/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <prdfMemEccAnalysis.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTdQueue.H>
#include <prdfP9McaExtraSig.H>
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
     * @param i_chip MCA or MBA.
     * @param i_rank Rank reporting chip mark.
     * @param i_mark Chip mark placed by hardware.
     */
    VcmEvent<T>( ExtensibleChip * i_chip, const MemRank & i_rank,
                 const MemMark & i_mark ) :
        TdEntry(VCM_EVENT, i_chip, i_rank), iv_mark(i_mark)
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
        PRDF_ASSERT( i_mark.isValid() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        uint32_t o_rc = SUCCESS;

        o_done = false;

        // Add the chip mark to the callout list.
        MemoryMru mm { iv_chip->getTrgt(), iv_rank, iv_mark.getSymbol() };
        io_sc.service_data->SetCallout( mm );

        // Take action based on the current phase.
        switch ( iv_phase )
        {
            case TD_PHASE_0:
                o_rc = startPhase1( io_sc );
                break;

            case TD_PHASE_1:
                o_rc = analyzePhase1( io_sc, o_done );
                if ( SUCCESS == o_rc && !o_done ) o_rc = startPhase2( io_sc );
                break;

            case TD_PHASE_2:
                o_rc = analyzePhase2( io_sc, o_done );
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( "[VcmEvent::nextStep] failed: 0x%08x,0x%02x",
                      iv_chip->getHuid(), getKey() );
        }

        return o_rc;
    }

    uint32_t getKey() const
    { return MemRank(iv_rank.getMaster()).getKey(); } // Master rank only

  private: // functions

    /**
     * @brief  Starts phase 1 of the procedure.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startPhase1( STEP_CODE_DATA_STRUCT & io_sc )
    {
        PRDF_TRAC( "[VcmEvent] Starting VCM Phase 1: 0x%08x,0x%02x",
                   iv_chip->getHuid(), getKey() );

        iv_phase = TD_PHASE_1;
        io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                              PRDFSIG_StartVcmPhase1 );

        return PlatServices::startVcmPhase1<T>( iv_chip, iv_rank );
    }

    /**
     * @brief  Starts phase 2 of the procedure.
     * @param  io_sc  The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startPhase2( STEP_CODE_DATA_STRUCT & io_sc )
    {
        PRDF_TRAC( "[VcmEvent] Starting VCM Phase 2: 0x%08x,0x%02x",
                   iv_chip->getHuid(), getKey() );

        iv_phase = TD_PHASE_2;
        io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                              PRDFSIG_StartVcmPhase2 );

        return PlatServices::startVcmPhase2<T>( iv_chip, iv_rank );
    }

    /**
     * @brief  Analyzes the state of the hardware after phase 1 completes.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase1( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[VcmEvent::analyzePhase1] "

        uint32_t o_rc = SUCCESS;

        do
        {
            uint32_t eccAttns;
            o_rc = checkEccFirs<T>( iv_chip, eccAttns );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = checkEcc( eccAttns, io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEcc() failed" );
                break;
            }

        } while (0);

        return o_rc;

        #undef PRDF_FUNC
    }

    /**
     * @brief  Analyzes the state of the hardware after phase 1 completes.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase2( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
    {
        #define PRDF_FUNC "[VcmEvent::analyzePhase2] "

        uint32_t o_rc = SUCCESS;

        do
        {
            uint32_t eccAttns;
            o_rc = checkEccFirs<T>( iv_chip, eccAttns );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = checkEcc( eccAttns, io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkEcc() failed" );
                break;
            }

            if ( o_done ) break; // nothing more to do

            // Determine if the chip mark has been verified.
            o_rc = (eccAttns & MAINT_MCE) ? verified(io_sc) : falseAlarm(io_sc);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "verified()/falseAlarm() failed" );
                break;
            }

            // Procedure is complete.
            o_done = true;

        } while (0);

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

        do
        {
            // If DRAM repairs are disabled, make the error log predictive.
            if ( PlatServices::areDramRepairsDisabled() )
            {
                io_sc.service_data->setServiceCall();
                break; // Nothing more to do.
            }

            // If there is a symbol mark on the same DRAM as the newly verified
            // chip mark, remove the symbol mark.
            o_rc = MarkStore::balance<T>( iv_chip, iv_rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MarkStore::balance(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Set the entire chip in DRAM Repairs VPD.
            // TODO: RTC 169939

            // Add a DRAM sparing procedure to the queue, if supported.
            // TODO: RTC 157888

        } while (0);

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

  private: // instance variables

    const MemMark iv_mark; ///< The chip mark from hardware.

    #ifdef __HOSTBOOT_RUNTIME
    /** False alarm counter for all instances of this class. */
    static TdFalseAlarm cv_falseAlarm;
    #endif
};

} // end namespace PRDF

#endif // __prdfMemVcm_H

