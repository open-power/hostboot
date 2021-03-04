/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemRrd.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file prdfMemRrd.H */

#ifndef __prdfMemRrd_H
#define __prdfMemRrd_H

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdQueue.H>
#include <prdfMemExtraSig.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/** @brief Row Repair Deploy procedure. */
template<TARGETING::TYPE T>
class RrdEvent : public TdEntry
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_chip OCMB.
     * @param i_rank Rank reporting chip mark.
     * @param i_mark Chip mark placed by hardware.
     */
    RrdEvent<T>( ExtensibleChip * i_chip, const MemRank & i_rank,
                 const MemMark & i_mark ) :
        TdEntry(RRD_EVENT, i_chip, i_rank), iv_mark(i_mark)
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
        PRDF_ASSERT( i_mark.isValid() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[RrdEvent::nextStep] "

        uint32_t o_rc = SUCCESS;

        // NOTE: Row repairs should already be supported if we get this far,
        //       so just continue without checking for the support here

        o_done = false;

        do
        {
            // First, do analysis.
            o_rc = analyzePhase( io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "analyzePhase() failed on 0x%08x,0x%2x",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            if ( o_done ) break; // Nothing more to do.

            // Then, start the next phase of the procedure.
            o_rc = startNextPhase( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startNextPhase() failed on 0x%08x,0x%2x",
                          iv_chip->getHuid(), getKey() );
                break;
            }

        } while (0);

        // Add the chip mark to the callout list if no callouts in the list.
        if ( 0 == io_sc.service_data->getMruListSize() )
        {
            MemoryMru mm { iv_chip->getTrgt(), iv_rank, iv_mark.getSymbol() };
            io_sc.service_data->SetCallout( mm );
        }

        return o_rc;

        #undef PRDF_FUNC
    }

    uint32_t getKey() const
    { return MemRank(iv_rank.getMaster()).getKey(); } // Master rank only

  private: // functions

    /**
     * @brief  Does isolation for ECC attentions during each phase.
     * @param  i_eccAttns Mask of all currently active maintenance attentions.
     *                    See enum MaintEccAttns for values.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t checkEcc( const uint32_t & i_eccAttns,
                       STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );
    /**
     * @brief  Called in the last phase of the procedure to determine if the
     *         row repair was successfully deployed.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t verifyRowRepair( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Do analysis based on the current phase.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[RrdEvent::analyzePhase] "

        uint32_t o_rc = SUCCESS;

        do
        {
            if ( TD_PHASE_0 == iv_phase )
            {
                // Before starting the first command, deploy the row repair
                o_rc = PlatServices::deployRowRepair<T>( iv_chip, iv_rank );
                break; // Nothing to analyze yet.
            }

            // Look for any ECC errors that occurred during the command.
            uint32_t eccAttns;
            o_rc = checkEccFirs<T>( iv_chip, eccAttns );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            // Analyze the ECC errors, if needed.
            o_rc = checkEcc( eccAttns, io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEcc() failed on 0x%08x",
                          iv_chip->getHuid() );
                break;
            }

            if ( o_done ) break; // abort the procedure.

            // Determine if the row repair was deployed successfully.
            o_rc = verifyRowRepair( io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "verifyRowRepair() failed on 0x%08x",
                          iv_chip->getHuid() );
                break;
            }

        } while (0);

        #ifdef __HOSTBOOT_RUNTIME
        if ( (SUCCESS == o_rc) && o_done )
        {
            // Clear the ECC FFDC for this master rank.
            MemDbUtils::resetEccFfdc<T>( iv_chip, iv_rank, MASTER_RANK );
        }
        #endif

        return o_rc;

        #undef PRDF_FUNC
    }

    /**
     * @brief  Starts the appropriate maintenance command for each phase of the
     *         procedure.
     * @pre    iv_phase must be set appropriately before calling this function.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startCmd();

    /**
     * @brief  Starts the next phase of the procedure.
     * @param  io_sc  The step code data struct.
     * @post   iv_phase will be updated appropriately per design.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startNextPhase( STEP_CODE_DATA_STRUCT & io_sc );

  private: // instance variables

    const MemMark iv_mark;  ///< The chip mark from hardware.
};

} // end namespace PRDF

#endif // __prdfMemRrd_H

