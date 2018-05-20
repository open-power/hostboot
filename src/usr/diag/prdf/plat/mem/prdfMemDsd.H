/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDsd.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

/** @file prdfMemDsd.H */

#ifndef __prdfMemDsd_H
#define __prdfMemDsd_H

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdQueue.H>
#include <prdfP9McaExtraSig.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/** @brief DRAM Spare Deploy procedure. */
template<TARGETING::TYPE T>
class DsdEvent : public TdEntry
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_chip MCA or MBA.
     * @param i_rank Rank reporting chip mark.
     */
    DsdEvent<T>( ExtensibleChip * i_chip, const MemRank & i_rank,
                 const MemMark & i_mark, bool i_eccSpare = false ) :
        TdEntry(DSD_EVENT, i_chip, i_rank), iv_mark(i_mark),
        iv_eccSpare(i_eccSpare)
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
        PRDF_ASSERT( i_mark.isValid() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[DsdEvent::nextStep] "

        // TODO: RTC 189221 should assert if DRAM Sparing is NOT supported.

        uint32_t o_rc = SUCCESS;

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
                PRDF_ERR( PRDF_FUNC "analyzePhase() failed on 0x%08x,0x%2x",
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
     * @brief  Do analysis based on the current phase.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted, false
     *                otherwise.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

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
    uint32_t startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
    {
        uint32_t signature = 0;

        switch ( iv_phase )
        {
            case TD_PHASE_0:
                iv_phase  = TD_PHASE_1;
                signature = PRDFSIG_StartDsdPhase1;
                break;

            #ifndef __HOSTBOOT_RUNTIME // IPL only

            case TD_PHASE_1:
                iv_phase  = TD_PHASE_2;
                signature = PRDFSIG_StartDsdPhase2;
                break;

            #endif

            default: PRDF_ASSERT( false ); // invalid phase
        }

        PRDF_TRAC( "[DsdEvent] Starting DSD Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );

        io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

        return startCmd();
    }

  private: // instance variables

    const MemMark iv_mark;  ///< The chip mark from hardware.
    const bool iv_eccSpare; ///< True if the spare should be applied to the x4
                            ///< DRAM ECC spare.
};

} // end namespace PRDF

#endif // __prdfMemDsd_H

