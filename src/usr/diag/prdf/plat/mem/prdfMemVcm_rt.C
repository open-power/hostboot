/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm_rt.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

/** @file prdfMemVcm_rt.C */

// Platform includes
#include <prdfMemDqBitmap.H>
#include <prdfMemVcm.H>
#include <prdfP9McaDataBundle.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMbaExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                               Helper functions
//
//##############################################################################

template<TARGETING::TYPE T>
VcmFalseAlarm * __getFalseAlarmCounter( ExtensibleChip * i_chip );

template<>
VcmFalseAlarm * __getFalseAlarmCounter<TYPE_MCA>( ExtensibleChip * i_chip )
{
    return getMcaDataBundle(i_chip)->getVcmFalseAlarmCounter();
}

template<>
VcmFalseAlarm * __getFalseAlarmCounter<TYPE_MBA>( ExtensibleChip * i_chip )
{
    return getMbaDataBundle(i_chip)->getVcmFalseAlarmCounter();
}

//##############################################################################
//
//                          Specializations for MCA
//
//##############################################################################

template<>
uint32_t VcmEvent<TYPE_MCA>::startCmd()
{
    #define PRDF_FUNC "[VcmEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // No stop conditions.
    mss::mcbist::stop_conditions stopCond;

    // Start the time based scrub procedure on this master rank.
    o_rc = startTdScrub<TYPE_MCA>( iv_chip, iv_rank, MASTER_RANK, stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MCA>::checkEcc( const uint32_t & i_eccAttns,
                                       STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<TYPE_MCA>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<TYPE_MCA>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<TYPE_MCA>( iv_chip, addr,
                                                  UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

        if ( mfgMode() && (i_eccAttns & MAINT_IUE) )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintIUE );

            o_rc = MemEcc::handleMemIue<TYPE_MCA>( iv_chip, iv_rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemIue(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // If service call is set, then IUE threshold was reached.
            if ( io_sc.service_data->queryServiceCall() )
            {
                PRDF_TRAC( PRDF_FUNC "IUE threshold detected: 0x%08x,0x%02x",
                           iv_chip->getHuid(), getKey() );

                // Leave the mark in place and abort this procedure.
                o_done = true; break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MCA>::cleanup( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[VcmEvent::cleanup] "

    uint32_t o_rc = SUCCESS;

    do
    {
        o_rc = MarkStore::chipMarkCleanup<TYPE_MCA>( iv_chip, iv_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "chipMarkCleanup(0x%08x,0x%02x) failed",
                      iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // The cleanup() function is called by both verified() and falseAlarm().
        // In either case, the error log should be predictive if there has been
        // a least one false alarm on any DRAM on this rank other than this
        // DRAM. This is required on Nimbus because of two symbol correction,
        // which does not exist on Centaur.
        VcmFalseAlarm * faCntr = __getFalseAlarmCounter<TYPE_MCA>(iv_chip);
        uint8_t dram = iv_mark.getSymbol().getDram();
        if ( faCntr->queryDrams(iv_rank, dram, io_sc) )
            io_sc.service_data->setServiceCall();

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
uint32_t VcmEvent<TYPE_MBA>::startCmd()
{
    #define PRDF_FUNC "[VcmEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    uint32_t stopCond = mss_MaintCmd::NO_STOP_CONDITIONS;

    // Due to a hardware bug in the Centaur, we must execute runtime maintenance
    // commands at a very slow rate. Because of this, we decided that we should
    // stop the command immediately on error if there is a UE so that we can
    // respond quicker and send a DMD message to the hypervisor as soon as
    // possible.

    stopCond |= mss_MaintCmd::STOP_ON_UE;
    stopCond |= mss_MaintCmd::STOP_IMMEDIATE;

    // Again, due to the hardware bug in the Centaur, we want to stop
    // immediately if there is an MCE found during phase 2 because that
    // indicates an error was detected on the bad DRAM and fixed by the chip
    // mark.

    if ( TD_PHASE_2 == iv_phase ) stopCond |= mss_MaintCmd::STOP_ON_MCE;

    if ( iv_canResumeScrub )
    {
        // Resume the command from the next address to the end of this master
        // rank.
        o_rc = resumeTdScrub<TYPE_MBA>( iv_chip, MASTER_RANK, stopCond );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "resumeTdScrub(0x%08x) failed",
                      iv_chip->getHuid() );
        }
    }
    else
    {
        // Start the time based scrub procedure on this master rank.
        o_rc = startTdScrub<TYPE_MBA>( iv_chip, iv_rank, MASTER_RANK, stopCond);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                      iv_chip->getHuid(), getKey() );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MBA>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    if ( iv_canResumeScrub )
    {
        signature = PRDFSIG_VcmResume;

        PRDF_TRAC( "[VcmEvent] Resuming VCM Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }
    else
    {
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
    }

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MBA>::checkEcc( const uint32_t & i_eccAttns,
                                       STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<TYPE_MBA>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<TYPE_MBA>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<TYPE_MBA>( iv_chip, addr,
                                                  UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

        if ( i_eccAttns & MAINT_RCE_ETE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintRETRY_CTE );

            // Add the rank to the callout list.
            MemoryMru mm { iv_chip->getTrgt(), iv_rank,
                           MemoryMruData::CALLOUT_RANK };
            io_sc.service_data->SetCallout( mm );

            // Make the error log predictive.
            io_sc.service_data->setServiceCall();
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MBA>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                           bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_0 == iv_phase ) break; // Nothing to analyze yet.

        // Look for any ECC errors that occurred during the command.
        uint32_t eccAttns;
        o_rc = checkEccFirs<TYPE_MBA>( iv_chip, eccAttns );
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

        // Determine if the command stopped on the last address.
        bool lastAddr = false;
        o_rc = didCmdStopOnLastAddr<TYPE_MBA>( iv_chip, MASTER_RANK, lastAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // It is important to initialize iv_canResumeScrub here, so that we will
        // know to resume the current phase in startNextPhase() instead of
        // starting phase.
        iv_canResumeScrub = !lastAddr;

        if ( TD_PHASE_2 == iv_phase )
        {
            if ( eccAttns & MAINT_MCE )
            {
                // The chip mark has been verified.
                o_rc = verified( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "verified() failed on 0x%08x",
                              iv_chip->getHuid() );
                    break;
                }

                // Procedure is complete.
                o_done = true;
            }
            else if ( !iv_canResumeScrub )
            {
                // The chip mark is not verified and the command has reached the
                // end of the rank. So this is a false alarm.
                o_rc = falseAlarm( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "falseAlarm() failed on 0x%08x",
                            iv_chip->getHuid() );
                    break;
                }

                // Procedure is complete.
                o_done = true;
            }
        }

    } while (0);

    if ( (SUCCESS == o_rc) && o_done )
    {
        // Clear the ECC FFDC for this master rank.
        MemDbUtils::resetEccFfdc<TYPE_MBA>( iv_chip, iv_rank, MASTER_RANK );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Generic template functions
//
//##############################################################################

template<TARGETING::TYPE T>
uint32_t VcmEvent<T>::falseAlarm( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[VcmEvent::falseAlarm] "

    uint32_t o_rc = SUCCESS;

    PRDF_TRAC( PRDF_FUNC "Chip mark false alarm: 0x%08x,0x%02x",
               iv_chip->getHuid(), getKey() );

    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                      PRDFSIG_VcmFalseAlarm );

    do
    {
        // If DRAM repairs are disabled, make the error log predictive.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break; // Nothing more to do.
        }

        // Increment the false alarm counter and check threshold.
        uint8_t dram = iv_mark.getSymbol().getDram();
        if ( __getFalseAlarmCounter<T>(iv_chip)->inc(iv_rank, dram, io_sc) )
        {
            // False alarm threshold has been reached.

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_VcmFalseAlarmTH );

            PRDF_TRAC( PRDF_FUNC "False alarm threshold: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            // Leave the chip mark in place and do any necessary cleanup.
            o_rc = cleanup( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "cleanup() failed" );
                break;
            }
        }
        else
        {
            // Remove the chip mark.
            o_rc = MarkStore::clearChipMark<T>( iv_chip, iv_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearChipMark(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class VcmEvent<TYPE_MCA>;
template class VcmEvent<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

