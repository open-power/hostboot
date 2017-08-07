/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_rt.C $                  */
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

/** @file prdfMemTps_rt.C */

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTps.H>
#include <prdfP9McaExtraSig.H>
#include <prdfP9McaDataBundle.H>
#include <prdfTargetServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
TpsFalseAlarm * __getTpsFalseAlarmCounter( ExtensibleChip * i_chip );

template<>
TpsFalseAlarm * __getTpsFalseAlarmCounter<TYPE_MCA>( ExtensibleChip * i_chip )
{
    return getMcaDataBundle(i_chip)->getTpsFalseAlarmCounter();
}

//------------------------------------------------------------------------------

template<>
TpsFalseAlarm * __getTpsFalseAlarmCounter<TYPE_MBA>( ExtensibleChip * i_chip )
{
    // TODO RTC 157888
    //return getMbaDataBundle(i_chip)->getTpsFalseAlarmCounter();
    return nullptr;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::startTpsPhase1_rt( STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_TRAC( "[TpsEvent] Starting TPS Phase 1: 0x%08x,0x%02x",
               iv_chip->getHuid(), getKey() );

    iv_phase = TD_PHASE_1;
    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                          PRDFSIG_StartTpsPhase1 );
    bool countAllCes = false;
    if ( __getTpsFalseAlarmCounter<T>(iv_chip)->count(iv_rank, io_sc) >= 1 )
        countAllCes = true;

    return PlatServices::startTpsRuntime<T>( iv_chip, iv_rank, countAllCes);
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzeTpsPhase1_rt( STEP_CODE_DATA_STRUCT & io_sc,
                                           bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<T>::analyzeTpsPhase1_rt] "

    uint32_t o_rc = SUCCESS;

    // TODO RTC 171914
    do
    {
        // Analyze Ecc Attentions
        uint32_t eccAttns;
        o_rc = checkEccFirs<T>( iv_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                    iv_chip->getHuid() );
            break;
        }

        o_rc = analyzeEcc( eccAttns, io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeEcc() failed." );
            break;
        }
        if ( o_done ) break;

        // Analyze CEs

        o_done = true;
        PRDF_ERR( PRDF_FUNC "function not implemented yet" );

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t TpsEvent<TYPE_MCA>::analyzeEcc( const uint32_t & i_eccAttns,
                                         STEP_CODE_DATA_STRUCT & io_sc,
                                         bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::analyzeEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // If there was a UE.
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

            // Abort this procedure because additional repairs will likely
            // not help (also avoids complication of having UE and MPE at
            // the same time).
            o_done = true; break;
        }

        // If there was an IUE (MNFG only).
        if ( mfgMode() && (i_eccAttns & MAINT_IUE) )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintIUE );

            o_rc = MemEcc::handleMemIue<TYPE_MCA, McaDataBundle *>( iv_chip,
                                                                    iv_rank,
                                                                    io_sc );
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

                // Abort this procedure because port failure will be triggered
                // after analysis is complete.
                o_done = true; break;
            }
        }

        // If there was an MPE.
        if ( i_eccAttns & MAINT_MPE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintMPE );

            o_rc = MemEcc::handleMpe<TYPE_MCA, McaDataBundle *>( iv_chip,
                iv_rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                          iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }

            // Abort this procedure because the chip mark may have fixed the
            // symbol that triggered TPS
            o_done = true; break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

// TODO: RTC 171914 Actual implementation of this procedure will be done later.
template<>
uint32_t TpsEvent<TYPE_MCA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = false;

    switch ( iv_phase )
    {
        case TD_PHASE_0:
            // Start TPS phase 1
            o_rc = startTpsPhase1_rt( io_sc );
            break;
        case TD_PHASE_1:
            // Analyze TPS phase 1
            o_rc = analyzeTpsPhase1_rt( io_sc, o_done );
            break;
        default: PRDF_ASSERT( false ); // invalid phase

    }

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "TPS failed: 0x%08x,0x%02x", iv_chip->getHuid(),
                  getKey() );
    }

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

//------------------------------------------------------------------------------

} // end namespace PRDF

