/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_ipl.C $                 */
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

/** @file prdfMemTps_ipl.C */

// Platform includes
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemIplCeStats.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTps.H>
#include <prdfP9McaDataBundle.H>
#include <prdfP9McaExtraSig.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = false;

    do
    {
        //only done in MNFG IPL CE Handling mode
        PRDF_ASSERT( isMfgCeCheckingEnabled() );

        //phase 0
        if ( TD_PHASE_0 == iv_phase )
        {
            o_rc = startNextPhase( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startNextPhase() failed on 0x%08x,0x%02x",
                          iv_chip->getHuid(), getKey() );
                break;
            }
        }
        //phase 1/2
        else
        {
            // PHASE_1: Collect soft/intermittent CE for later analysis use.
            // PHASE_2: Callout all hard CEs.
            McaDataBundle * db = getMcaDataBundle( iv_chip );
            o_rc = ( TD_PHASE_1 == iv_phase )
                                ? db->getIplCeStats()->collectStats(  iv_rank)
                                : db->getIplCeStats()->calloutHardCes(iv_rank);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "collectStats/calloutHardCes(0x%02x) "
                          "failed on 0x%08x", iv_rank.getKey(),
                          iv_chip->getHuid() );
                break;
            }

            //get the ecc attentions
            uint32_t eccAttns;
            o_rc = checkEccFirs<TYPE_MCA>( iv_chip, eccAttns );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Call to 'checkEccFirs' failed on chip: "
                          "0x%08x", iv_chip->getHuid() );
                break;
            }

            //if there was a UE or IUE
            if ( (eccAttns & MAINT_UE) || (eccAttns & MAINT_IUE) )
            {
                PRDF_TRAC( PRDF_FUNC "UE Detected. Aborting this procedure." );
                //UE
                if ( eccAttns & MAINT_UE )
                {
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_MaintUE );
                }
                //IUE
                else
                {
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_MaintIUE );
                }

                // At this point we don't actually have an address for the UE.
                // The best we can do is get the address in which the command
                // stopped.
                MemAddr addr;
                o_rc = getMemMaintAddr<TYPE_MCA>( iv_chip, addr );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                              iv_chip->getHuid() );
                    break;
                }

                // Do memory UE handling.
                o_rc = MemEcc::handleMemUe<TYPE_MCA>(iv_chip, addr,
                                                     UE_TABLE::SCRUB_UE, io_sc);
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleMemUe<T>(0x%08x) failed",
                              iv_chip->getHuid() );
                    break;
                }

                //Abort this procedure
                o_done = true;
            }
            //else if there was an MPE
            else if ( eccAttns & MAINT_MPE )
            {
                // Do memory MPE handling.
                o_rc = MemEcc::handleMpe<TYPE_MCA>( iv_chip, iv_rank,
                                                    UE_TABLE::SCRUB_MPE, io_sc);
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleMpe(0x%08x,0x%02x) failed",
                              iv_chip->getHuid(), getKey() );
                    break;
                }

                //Abort this procedure
                o_done = true;
            }
            else
            {
                //Add the rank to the callout list
                MemoryMru memmru(iv_chip->getTrgt(), iv_rank,
                        MemoryMruData::CALLOUT_RANK);
                io_sc.service_data->SetCallout( memmru );

                //phase 1
                if ( TD_PHASE_1 == iv_phase )
                {
                    o_rc = startNextPhase( io_sc );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "startNextPhase() failed on 0x%08x,"
                                  "0x%02x", iv_chip->getHuid(), getKey() );
                        break;
                    }
                }
                //phase 2
                else
                {
                    //Abort this procedure
                    o_done = true;
                }
            }
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// TODO: RTC 157888 Actual implementation of this procedure will be done later.
template<>
uint32_t TpsEvent<TYPE_MBA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MBA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = true;

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Generic template functions
//
//##############################################################################

template <TARGETING::TYPE T>
uint32_t TpsEvent<T>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    switch ( iv_phase )
    {
        case TD_PHASE_0:
            iv_phase  = TD_PHASE_1;
            signature = PRDFSIG_StartTpsPhase1;
            break;

        case TD_PHASE_1:
            iv_phase  = TD_PHASE_2;
            signature = PRDFSIG_StartTpsPhase2;
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    PRDF_TRAC( "[TpsEvent] Starting TPS Phase %d: 0x%08x,0x%02x",
               iv_phase, iv_chip->getHuid(), getKey() );

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

//##############################################################################
//
//                          Specializations for MCA
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_MCA>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // We don't need to set any stop-on-error conditions or thresholds for
    // soft/inter/hard CEs during Memory Diagnostics. The design is to let the
    // command continue to the end of the rank and we do diagnostics on the
    // CE counts found in the per-symbol counters. Therefore, all we need to do
    // is tell the hardware which CE types to count.

    mss::mcbist::stop_conditions stopCond;

    switch ( iv_phase )
    {
        case TD_PHASE_1:
            // Set the per symbol counters to count only soft/inter CEs.
            stopCond.set_nce_soft_symbol_count_enable( mss::ON);
            stopCond.set_nce_inter_symbol_count_enable(mss::ON);
            break;

        case TD_PHASE_2:
            // Set the per symbol counters to count only hard CEs.
            stopCond.set_nce_hard_symbol_count_enable(mss::ON);
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    // Start the time based scrub procedure on this slave rank.
    o_rc = startTdScrub<TYPE_MCA>( iv_chip, iv_rank, SLAVE_RANK, stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_MBA>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    uint32_t stopCond = mss_MaintCmd::NO_STOP_CONDITIONS;

    // We don't need to set any stop-on-error conditions or thresholds for
    // soft/inter/hard CEs during Memory Diagnostics. The design is to let the
    // command continue to the end of the rank and we do diagnostics on the
    // CE counts found in the per-symbol counters. Therefore, all we need to do
    // is tell the hardware which CE types to count.

    do
    {
        ExtensibleChip * membChip = getConnectedParent( iv_chip, TYPE_MEMBUF );
        const char * reg_str = (0 == iv_chip->getPos()) ? "MBA0_MBSTR"
                                                        : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( reg_str );
        o_rc = mbstr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s: 0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        switch ( iv_phase )
        {
            case TD_PHASE_1:
                // Set the per symbol counters to count only soft/inter CEs.
                mbstr->SetBitFieldJustified( 55, 3, 0x6 );
                break;

            case TD_PHASE_2:
                // Set the per symbol counters to count only hard CEs.
                mbstr->SetBitFieldJustified( 55, 3, 0x1 );
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s: 0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        // Start the time based scrub procedure on this slave rank.
        o_rc = startTdScrub<TYPE_MBA>( iv_chip, iv_rank, SLAVE_RANK, stopCond );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                      iv_chip->getHuid(), getKey() );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

