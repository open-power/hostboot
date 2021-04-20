/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

/** @file prdfMemVcm.H */

#ifndef __prdfMemVcm_H
#define __prdfMemVcm_H

// Platform includes
#include <prdfErrlUtil.H>
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemMark.H>
#include <prdfMemRowRepair.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTdQueue.H>
#include <prdfMemExtraSig.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/** @brief Verify chip mark procedure. */
template<TARGETING::TYPE T>
class VcmEvent : public TdEntry
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_chip OCMB.
     * @param i_rank Rank reporting chip mark.
     * @param i_mark Chip mark placed by hardware.
     */
    VcmEvent<T>( ExtensibleChip * i_chip, const MemRank & i_rank,
                 const MemMark & i_mark ) :
        TdEntry(VCM_EVENT, i_chip, i_rank), iv_mark(i_mark),
        iv_rowRepairEnabled(PlatServices::isRowRepairEnabled<T>(i_chip,i_rank))
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
        PRDF_ASSERT( i_mark.isValid() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[VcmEvent::nextStep] "

        uint32_t o_rc = SUCCESS;

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
     * @brief  Starts the appropriate maintenance command for each phase of the
     *         VCM procedure.
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
    uint32_t startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t signature = 0;

        switch ( iv_phase )
        {
            case TD_PHASE_0:
                iv_phase  = TD_PHASE_1;
                signature = PRDFSIG_StartVcmPhase1;
                break;

            case TD_PHASE_1:
                iv_phase  = TD_PHASE_2;
                signature = PRDFSIG_StartVcmPhase2;
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        PRDF_TRAC( "[VcmEvent] Starting VCM Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );

        io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

        return startCmd();
    }

    /**
     * @brief  Do analysis based on the current phase.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted, false
     *                otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[VcmEvent::analyzePhase] "

        uint32_t o_rc = SUCCESS;

        do
        {
            if ( TD_PHASE_0 == iv_phase ) break; // Nothing to analyze yet.

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

            // Complete the phase.
            o_rc = handlePhaseComplete( eccAttns, io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEcc() failed on 0x%08x",
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
     * @brief  Does isolation for ECC attentions during each phase. Note that
     *         isolation is the same for both phases.
     * @param  i_eccAttns Mask of all currently active maintenance attentions.
     *                    See enum MaintEccAttns for values.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t checkEcc( const uint32_t & i_eccAttns,
                       STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Does appropriate actions at the end of a phase if it was not
     *         aborted due to an error. Note that the actions will differ per
     *         target type, runtime/IPL, or if there is an MCE on phase 2.
     * @param  i_eccAttns Mask of all currently active maintenance attentions.
     *                    See enum MaintEccAttns for values.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t handlePhaseComplete( const uint32_t & i_eccAttns,
                                  STEP_CODE_DATA_STRUCT & io_sc,
                                  bool & o_done );

    /**
     * @brief  The chip mark is verified. Do additional processing such as
     *         updating the VPD and initiating DRAM sparing, if supported.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t verified( STEP_CODE_DATA_STRUCT & io_sc )
    {
        #define PRDF_FUNC "[VcmEvent::verified] "

        uint32_t o_rc = SUCCESS;

        PRDF_TRAC( PRDF_FUNC "Chip mark verified: 0x%08x,0x%02x",
                   iv_chip->getHuid(), getKey() );

        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_VcmVerified );

        // Leave the chip mark in place and do any necessary cleanup.
        o_rc = cleanup( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "cleanup() failed" );
        }

        return o_rc;

        #undef PRDF_FUNC
    }

    /**
     * @brief  Cleanup required when a chip mark is left in place (i.e. chip
     *         mark verified or false alarm threshold). Will balance the chip
     *         and symbol marks, set VPD, and initiate DRAM sparing if
     *         supported.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t cleanup( STEP_CODE_DATA_STRUCT & io_sc )
    {
        #define PRDF_FUNC "[VcmEvent::cleanup] "

        uint32_t o_rc = SUCCESS;

        o_rc = MarkStore::chipMarkCleanup<T>( iv_chip, iv_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "chipMarkCleanup(0x%08x,0x%02x) failed",
                    iv_chip->getHuid(), iv_rank.getKey() );
        }

        return o_rc;

        #undef PRDF_FUNC
    }

    /**
     * @brief  Verification failed. Do additional processing such as removing
     *         the chip mark and false alarm threshold handling.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t falseAlarm( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Do extra analysis needed for Row Repair.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t rowRepair( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Do extra analysis needed for Row Repair once scrub has reached
     *         the end of the rank.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t rowRepairEndRank( STEP_CODE_DATA_STRUCT & io_sc );

  private: // instance variables

    const MemMark iv_mark; ///< The chip mark from hardware.
    const bool iv_rowRepairEnabled; ///< True if Row Repair is enabled.
    bool iv_resumeNextRow = false; ///< True if scrub is resuming on next row.
    uint8_t iv_mceCount = 0; ///< MCEs hit count, currently for Row Repair only.
    MemAddr iv_rowRepairFailAddr; ///< Address stored to apply Row Repair on.
};

//------------------------------------------------------------------------------

// Forward declarations for template specializations. Required for functions
// that are also defined in the primary template.

#ifdef __HOSTBOOT_RUNTIME
template<>
uint32_t VcmEvent<TARGETING::TYPE_OCMB_CHIP>::cleanup(
    STEP_CODE_DATA_STRUCT & io_sc);
#endif

} // end namespace PRDF

#endif // __prdfMemVcm_H

