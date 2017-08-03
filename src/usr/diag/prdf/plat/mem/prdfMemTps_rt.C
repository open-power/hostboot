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
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTps.H>
#include <prdfP9McaExtraSig.H>
#include <prdfP9McaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

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
    // Analyze Ecc Attentions
    // Analyze CEs

    o_done = true;
    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

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

