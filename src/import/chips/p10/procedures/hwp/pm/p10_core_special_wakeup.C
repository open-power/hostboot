/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_core_special_wakeup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file   p10_core_special_wakeup.H
/// @brief  Asserts or de-asserts special wakeup request on a given core.
///
// *HWP HW Owner:       Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    HB, FSP
#include <p10_scom_eq_2.H>
#include <p10_scom_c_0.H>
#include <p10_scom_c_7.H>
#include <p10_scom_eq_c.H>
#include <p10_scom_eq_1.H>
#include <p10_core_special_wakeup.H>
#include <multicast_group_defs.H>
#include <p10_pm_hcd_flags.h>

/**
 * @brief Special wakeup operation message.
 */
char SplWkupMsg[p10specialWakeup::MAX_OPERATION][10] =
{
    "ASSERT",
    "DE-ASSERT"
};
/**
 * @brief   evaluates core and quad/qme states,if qme is in quiesce and
 *          core is eco enabled then we should skip assert/de-assert
 *          spwu.
 * @param   i_target            P10 unicast core target.
 * @param   o_coreSpwuSkipState True if core is eco and qme is in quiesce
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */
fapi2::ReturnCode verifyQMECoreState(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target,
    uint8_t& o_coreSpwuSkipState)
{
    fapi2::buffer <uint64_t> l_data;
    auto l_eq   =   i_target.getParent< fapi2::TARGET_TYPE_EQ >( );

    fapi2::ATTR_ECO_MODE_Type l_eco_mode;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE,
                           i_target,
                           l_eco_mode));

    FAPI_TRY( fapi2::getScom( l_eq, scomt::eq::QME_FLAGS_RW, l_data ) );

    if(l_data.getBit<p10hcd::QME_FLAGS_QUIESCE_MODE>()  &&
       l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_ENABLED)
    {
        o_coreSpwuSkipState = 1;
    }

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief   evaluates core and quad status before special wakeup of a core.
 * @param   i_target        P10 multicast core target.
 * @param   i_operation     Special wakeup opearation supported
 * @param   i_entity        entity requesting special wakeup
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 * @note    HBRT calls SplWkup HWP using unicast core target. Somehow call
 * fails if a multicase  interface is used.
 */
fapi2::ReturnCode checkForUcSplWkupPreReq(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target,
    const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    fapi2::buffer <uint64_t> l_data;
    fapi2::buffer <uint64_t> l_coreSshsrc;
    fapi2::buffer <uint64_t> l_scsr;
    auto l_eq   =   i_target.getParent< fapi2::TARGET_TYPE_EQ >( );
    FAPI_TRY( fapi2::getScom( l_eq, scomt::eq::QME_EISR_RW, l_data ) );

    if( l_data.getBit( scomt::eq::QME_EISR_SYSTEM_CHECKSTOP ) )
    {
        FAPI_ASSERT( false,
                     fapi2::SYSTEM_IN_CHECKSTOP_STATE().
                     set_QME_EISR_REG( l_data ),
                     "System In CheckStop State. Spl Wakeup Not Attempted On Core" );
    }

    //Need to assure ourselves that we have infrastructure in place to support
    //Special wakeup. Special wakeup at an early stage of IPL ( in failure path )
    //can't be supported. Check below enables calling platform to handle it
    //gracefully.

    FAPI_TRY( fapi2::getScom( l_eq, scomt::eq::QME_FLAGS_RW, l_data ) );
    FAPI_TRY( fapi2::getScom( i_target, scomt::c::QME_SCSR, l_scsr ) );

    if( l_data.getBit< p10specialWakeup::QME_FLAG_STOP_READY >() ||
        !l_scsr.getBit< scomt::c::QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE >() )
    {
        //Special Wakeup is Feasible
        FAPI_DBG( "PM Complex Ready For Special Wakeup On A Core" );
        fapi2::current_err  =  fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        FAPI_ASSERT( false,
                     fapi2::CORE_SPECIAL_WAKEUP_NOT_FEASIBLE().
                     set_QME_FLAG( l_data ),
                     "QME Not Booted. Spl Wakeup Request Cannot Be Serviced QME Flag 0x%016lx", l_data );
    }

fapi_try_exit:
    return fapi2::current_err;
}

//************************************************************************************************

/**
 * @brief a workaround for DD1 HW bug which affects cores in STOP0
 * @param[in] core target
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 * @note  a unicast version of handleHwWorkAround
 */

fapi2::ReturnCode handleUcHwWorkAround( const fapi2::Target < fapi2::TARGET_TYPE_CORE  >& i_target )
{
    fapi2::buffer<uint64_t> l_qmeIar;
    fapi2::buffer<uint64_t> l_scrData;
    fapi2::ReturnCode l_rc;
    uint32_t l_pmState = 0;

    auto l_parentEq  =  i_target.getParent< fapi2::TARGET_TYPE_EQ >();
    FAPI_TRY( getScom( l_parentEq, scomt::eq::QME_SCOM_XIDBGPRO, l_qmeIar ));

    if( l_qmeIar.getBit( scomt::eq::QME_SCOM_XIDBGPRO_XSR_HS ) )
    {
        FAPI_INF("QME Halted" );
        FAPI_TRY( getScom( i_target, scomt::c::QME_SCSR, l_scrData ) );

        l_scrData.extractToRight< 60, 4 >( l_pmState );

        if( ( l_scrData.getBit( scomt::c::QME_SCSR_PM_STATE_ACTIVE )) && ( ( l_pmState == 0 ) || ( l_pmState == 1 ) ) )
        {
            FAPI_INF( "Core in STOP 0" );
            l_scrData.setBit( scomt::c::QME_SCSR_ASSERT_PM_EXIT ); // Enable exit from core STOP state
            l_scrData.clearBit( scomt::c::QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE ); // Enable auto-special wakeup
            FAPI_TRY( putScom( i_target, scomt::c::QME_SCSR, l_scrData ) );

        }
    }
    else
    {
        FAPI_INF( "QME Not Halted Or Core Not In STOP 0" );
        fapi2::current_err  =  fapi2::RC_INTERNAL_NO_TIMEOUT_DUETO_STOP0_BUG;

    }

fapi_try_exit:
    return fapi2::current_err;
}

//************************************************************************************************

/**
 * @brief initiates special wakeup on a given core.
 * @param   i_target        P10 multicast core target.
 * @param   i_operation     Special wakeup opearation supported
 * @param   i_entity        entity requesting special wakeup
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */
fapi2::ReturnCode initiateUcSplWkup(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target,
    const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_coreSshsrc;
    fapi2::ATTR_CHIP_EC_FEATURE_SPL_WKUP_STOP0_HW529794_Type l_hw529794;
    fapi2::ReturnCode l_rc;
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >  l_procChip  =
        i_target.getParent< fapi2::TARGET_TYPE_PROC_CHIP >();
    uint32_t l_retryDelay   =   p10specialWakeup::SPECIAL_WAKE_UP_POLL_INTERVAL_NS;
    uint32_t l_pollCount    =   p10specialWakeup::SPECIAL_WAKEUP_TIMEOUT_NS / l_retryDelay;
    uint32_t l_address      =   0;
    l_address   =  p10specialWakeup::SpecialWakeupAddr[i_entity];

    FAPI_ATTR_GET( fapi2::ATTR_CHIP_EC_FEATURE_SPL_WKUP_STOP0_HW529794,
                   l_procChip,
                   l_hw529794 );

    l_data.flush<0>();

    if( p10specialWakeup::SPCWKUP_ENABLE  == i_operation )
    {
        l_data.setBit< p10specialWakeup::SPECIAL_WKUP_REQ_BIT > ();
    }

    //Initiating request for special wakeup
    FAPI_TRY( fapi2::putScom( i_target, l_address, l_data ));

    if( p10specialWakeup::SPCWKUP_DISABLE   ==  i_operation )
    {
        FAPI_DBG( "Special Wakeup - Deassert" );
        goto fapi_try_exit;
    }

    //Waiting for Special wakeup "DONE" to be asserted

    do
    {
        FAPI_TRY( fapi2::getScom( i_target, l_address, l_data ));
        //FIXME check for hcode error log
        fapi2::delay( l_retryDelay, 1000000 );
        l_pollCount--;

    }
    while( ( l_pollCount > 0 ) && ( !l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ));

    do
    {

        if( l_hw529794 && !l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() )
        {
            l_rc = handleUcHwWorkAround( i_target );

            if( l_rc == (fapi2::ReturnCode )fapi2::RC_INTERNAL_NO_TIMEOUT_DUETO_STOP0_BUG )
            {
                break;
            }

            l_pollCount    =   p10specialWakeup::SPECIAL_WAKEUP_TIMEOUT_NS / l_retryDelay;

            do
            {
                FAPI_TRY( fapi2::getScom( i_target, l_address, l_data ));
                //FIXME check for hcode error log
                fapi2::delay( l_retryDelay, 1000000 );
                l_pollCount--;

            }
            while( ( l_pollCount > 0 ) && ( !l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ));

            FAPI_ASSERT( ( true == l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ),
                         fapi2::SPCWKUP_CORE_HW529794_TIMEOUT().
                         set_POLLCOUNT( l_pollCount ).
                         set_SP_WKUP_REG_VALUE( l_data ).
                         set_ENTITY( i_entity ).
                         set_CORE_TARGET( i_target ).
                         set_CORE_SSHSRC( l_coreSshsrc ),
                         "Core Special Wakeup Request Timed Out" );

            FAPI_INF( "HW529794: Spl Wakeup Success !!!" );

            l_data.flush<0>().setBit( scomt::c::QME_SCSR_ASSERT_PM_EXIT );
            FAPI_TRY( fapi2::putScom( i_target, scomt::c::QME_SCSR_WO_CLEAR, l_data ));

            goto fapi_try_exit; // workaround worked and we got the DONE on core in STOP0
        }
    }
    while(0);

    FAPI_TRY( fapi2::getScom( i_target, scomt::c::QME_SSH_SRC, l_coreSshsrc ) );

    FAPI_ASSERT( ( true == l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ),
                 fapi2::SPCWKUP_CORE_TIMEOUT().
                 set_POLLCOUNT( l_pollCount ).
                 set_SP_WKUP_REG_VALUE( l_data ).
                 set_ENTITY( i_entity ).
                 set_CORE_TARGET( i_target ).
                 set_CORE_SSHSRC( l_coreSshsrc ),
                 "Core Special Wakeup Request Timed Out" );

    FAPI_INF( "Special Wakeup %s Done On Targeted Core",
              SplWkupMsg[(uint8_t)i_operation] );

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief evaluates core and quad status before special wakeup.
 * @param   i_target        P10 multicast core target.
 * @param   i_operation     Special wakeup opearation supported
 * @param   i_entity        entity requesting special wakeup
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */
fapi2::ReturnCode checkForSplWkupPreReq(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    fapi2::buffer <uint64_t> l_data;
    fapi2::buffer <uint64_t> l_coreSshsrc;
    fapi2::buffer <uint64_t> l_scsr;
    fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP > l_proc     =
        i_target.getParent < fapi2::TARGET_TYPE_PROC_CHIP > ();
    auto l_eq_mc_and = l_proc.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_AND >(fapi2::MCGROUP_GOOD_EQ);
    FAPI_TRY( fapi2::getScom( l_eq_mc_and, scomt::eq::QME_EISR_RW, l_data ) );

    if( l_data.getBit( scomt::eq::QME_EISR_SYSTEM_CHECKSTOP ) )
    {
        FAPI_ASSERT( false,
                     fapi2::SYSTEM_IN_CHECKSTOP_STATE().
                     set_QME_EISR_REG( l_data ),
                     "System In CheckStop State. Spl Wakeup Not Attempted" );
    }

    //Need to assure ourselves that we have infrastructure in place to support
    //Special wakeup. Special wakeup at an early stage of IPL ( in failure path )
    //can't be supported. Check below enables calling platform to handle it
    //gracefully.

    FAPI_TRY( fapi2::getScom( l_eq_mc_and, scomt::eq::QME_FLAGS_RW, l_data ) );
    FAPI_TRY( fapi2::getScom( i_target, scomt::c::QME_SCSR, l_scsr ) );

    if( l_data.getBit< p10specialWakeup::QME_FLAG_STOP_READY >() ||
        !l_scsr.getBit< scomt::c::QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE >() )
    {
        //Special Wakeup is Feasible
        FAPI_DBG( "PM Complex Ready For Special Wakeup" );
        fapi2::current_err  =  fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        FAPI_ASSERT( false,
                     fapi2::CORE_SPECIAL_WAKEUP_NOT_FEASIBLE().
                     set_QME_FLAG( l_data ),
                     "QME Not Booted. Spl Wakeup Request Cannot Be Serviced QME MC Flag 0x%016lx", l_data );
    }

fapi_try_exit:
    return fapi2::current_err;
}

//************************************************************************************************

/**
 * @brief a workaround for DD1 HW bug which affects cores in STOP0
 * @param[in] core target
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */

fapi2::ReturnCode handleHwWorkAround( const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > &
                                      i_target )
{
    fapi2::buffer<uint64_t> l_qmeIar;
    fapi2::buffer<uint64_t> l_scrData;
    fapi2::ReturnCode l_rc;
    uint32_t l_pmState = 0;
    auto l_coreList  =  i_target.getChildren< fapi2::TARGET_TYPE_CORE >( fapi2::TARGET_STATE_FUNCTIONAL );

    for( auto l_core : l_coreList )
    {
        auto l_parentEq  =  l_core.getParent< fapi2::TARGET_TYPE_EQ >();
        FAPI_TRY( getScom( l_parentEq, scomt::eq::QME_SCOM_XIDBGPRO, l_qmeIar ));

        if( l_qmeIar.getBit( scomt::eq::QME_SCOM_XIDBGPRO_XSR_HS ) )
        {
            FAPI_INF("QME Halted" );
            FAPI_TRY( getScom( l_core, scomt::c::QME_SCSR, l_scrData ) );

            l_scrData.extractToRight< 60, 4 >( l_pmState );

            if( ( l_scrData.getBit( scomt::c::QME_SCSR_PM_STATE_ACTIVE )) && ( ( l_pmState == 0 ) || ( l_pmState == 1 ) ) )
            {
                FAPI_INF( "Core in STOP 0" );
                l_scrData.setBit( scomt::c::QME_SCSR_ASSERT_PM_EXIT ); // Enable exit from core STOP state
                l_scrData.clearBit( scomt::c::QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE ); // Enable auto-special wakeup
                FAPI_TRY( putScom( l_core, scomt::c::QME_SCSR, l_scrData ) );

            }
        }
        else
        {
            FAPI_INF( "QME Not Halted Or Core Not In STOP 0" );
            fapi2::current_err  =  fapi2::RC_INTERNAL_NO_TIMEOUT_DUETO_STOP0_BUG;

        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

//************************************************************************************************

/**
 * @brief initiates special wakeup on a given core.
 * @param   i_target        P10 multicast core target.
 * @param   i_operation     Special wakeup opearation supported
 * @param   i_entity        entity requesting special wakeup
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */
fapi2::ReturnCode initiateSplWkup(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_coreSshsrc;
    fapi2::ATTR_CHIP_EC_FEATURE_SPL_WKUP_STOP0_HW529794_Type l_hw529794;
    fapi2::ReturnCode l_rc;
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP >  l_procChip  =
        i_target.getParent< fapi2::TARGET_TYPE_PROC_CHIP >();
    uint32_t l_retryDelay   =   p10specialWakeup::SPECIAL_WAKE_UP_POLL_INTERVAL_NS;
    uint32_t l_pollCount    =   p10specialWakeup::SPECIAL_WAKEUP_TIMEOUT_NS / l_retryDelay;
    uint32_t l_address      =   0;
    fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST,
          fapi2::MULTICAST_AND > l_ecMcAndTgt     =   i_target;
    l_address   =  p10specialWakeup::SpecialWakeupAddr[i_entity];

    FAPI_ATTR_GET( fapi2::ATTR_CHIP_EC_FEATURE_SPL_WKUP_STOP0_HW529794,
                   l_procChip,
                   l_hw529794 );

    l_data.flush<0>();

    if( p10specialWakeup::SPCWKUP_ENABLE  == i_operation )
    {
        l_data.setBit< p10specialWakeup::SPECIAL_WKUP_REQ_BIT > ();
    }

    //Initiating request for special wakeup
    FAPI_TRY( fapi2::putScom( i_target, l_address, l_data ));

    if( p10specialWakeup::SPCWKUP_DISABLE   ==  i_operation )
    {
        FAPI_DBG( "Special Wakeup - Deassert" );
        goto fapi_try_exit;
    }

    //Waiting for Special wakeup "DONE" to be asserted

    do
    {
        FAPI_TRY( fapi2::getScom( l_ecMcAndTgt, l_address, l_data ));
        //FIXME check for hcode error log
        fapi2::delay( l_retryDelay, 1000000 );
        l_pollCount--;

    }
    while( ( l_pollCount > 0 ) && ( !l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ));

    do
    {

        if( l_hw529794 && !l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() )
        {
            l_rc = handleHwWorkAround( i_target );

            if( l_rc == (fapi2::ReturnCode )fapi2::RC_INTERNAL_NO_TIMEOUT_DUETO_STOP0_BUG )
            {
                break;
            }

            l_pollCount    =   p10specialWakeup::SPECIAL_WAKEUP_TIMEOUT_NS / l_retryDelay;

            do
            {
                FAPI_TRY( fapi2::getScom( l_ecMcAndTgt, l_address, l_data ));
                //FIXME check for hcode error log
                fapi2::delay( l_retryDelay, 1000000 );
                l_pollCount--;

            }
            while( ( l_pollCount > 0 ) && ( !l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ));

            FAPI_ASSERT( ( true == l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ),
                         fapi2::SPCWKUP_CORE_HW529794_TIMEOUT().
                         set_POLLCOUNT( l_pollCount ).
                         set_SP_WKUP_REG_VALUE( l_data ).
                         set_ENTITY( i_entity ).
                         set_CORE_TARGET( i_target ).
                         set_CORE_SSHSRC( l_coreSshsrc ),
                         "Core Special Wakeup Request Timed Out" );

            FAPI_INF( "HW529794: Spl Wakeup Success !!!" );

            l_data.flush<0>().setBit( scomt::c::QME_SCSR_ASSERT_PM_EXIT );
            FAPI_TRY( fapi2::putScom( l_ecMcAndTgt, scomt::c::QME_SCSR_WO_CLEAR, l_data ));

            goto fapi_try_exit; // workaround worked and we got the DONE on core in STOP0
        }

    }
    while(0);

    FAPI_TRY( fapi2::getScom( l_ecMcAndTgt, scomt::c::QME_SSH_SRC, l_coreSshsrc ) );

    FAPI_ASSERT( ( true == l_data.getBit< p10specialWakeup::SPWKUP_REQ_DONE_BIT >() ),
                 fapi2::SPCWKUP_CORE_TIMEOUT().
                 set_POLLCOUNT( l_pollCount ).
                 set_SP_WKUP_REG_VALUE( l_data ).
                 set_ENTITY( i_entity ).
                 set_CORE_TARGET( i_target ).
                 set_CORE_SSHSRC( l_coreSshsrc ),
                 "Core Special Wakeup Request Timed Out" );

    FAPI_INF( "Special Wakeup %s Done On Targeted Core",
              SplWkupMsg[(uint8_t)i_operation] );

fapi_try_exit:
    return fapi2::current_err;
}

//************************************************************************************************

/**
 * @brief Sets an attribute to block recursion in falure path of Spl Wkup.
 * @param   i_coreList  list of p10 core targets.
 * @param   i_spWakeUpInProg    BLOCK, UNBLOCK
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */
void blockWakeupRecursion( const std::vector < fapi2::Target <fapi2::TARGET_TYPE_CORE >>& i_coreList,
                           p10specialWakeup::RecursionOp i_spWakeUpInProg )
{
    FAPI_INF(">> blockWakeupRecursion" );

    uint8_t attrVal     =   i_spWakeUpInProg;

    for( const auto& core : i_coreList )
    {
        FAPI_ATTR_SET( fapi2::ATTR_INSIDE_SPECIAL_WAKEUP,
                       core,
                       attrVal );
    }

    FAPI_INF("<< blockWakeupRecursion" );
}

//************************************************************************************************
//************************************************************************************************

/**
 * @brief   Detects if Spl Wkup is already in progress on that core.
 * @param   i_coreList  list of p10 core targets.
 * @return  FAPI2_RC_SUCCESS in case of SUCCESS else fapi2 return code.
 */
fapi2::ReturnCode   isSplWkupInProgress( const std::vector < fapi2::Target <fapi2::TARGET_TYPE_CORE >>& i_coreList )
{
    uint8_t attrVal = 0;

    for( const auto& core : i_coreList )
    {
        FAPI_ATTR_GET( fapi2::ATTR_INSIDE_SPECIAL_WAKEUP,
                       core,
                       attrVal );

        if( attrVal )
        {
            fapi2::current_err  =   fapi2::RC_INTERNAL_SPCWKUP_IN_PROGRESS;
            break;
        }
    }

    return fapi2::current_err;
}

//************************************************************************************************

fapi2::ReturnCode p10_uc_core_special_wakeup(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE >& i_target,
    const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity )

{
    FAPI_INF( ">> p10_uc_core_special_wakeup" );

    fapi2::ReturnCode l_tempRc  =   fapi2::FAPI2_RC_SUCCESS;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_fuseModeState     =   0;
    uint8_t l_corePos   =   0;
    uint8_t l_siblngPos =   0;
    uint8_t l_coreInStopOrECO_QMEHalt = 0;

    std::vector < fapi2::Target <fapi2::TARGET_TYPE_CORE >> l_modCoreList;
    fapi2::Target <fapi2::TARGET_TYPE_CORE> l_siblingCore;
    l_modCoreList.push_back( i_target );

    //Verify if cores are in ECO mode and QME is in quiesce, if yes, then
    //we shouldn't assert the spwu for that cores
    FAPI_TRY(verifyQMECoreState(i_target, l_coreInStopOrECO_QMEHalt));

    FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                   i_target,
                   l_corePos);

    if ( l_coreInStopOrECO_QMEHalt )
    {
        FAPI_INF("As QME halted and core is ECO enabled");
        FAPI_INF("Specialwakeup is skipped for this core %d ", l_corePos);
        return fapi2::RC_ECO_CORE_SPWU_SKIPPED;
    }

    FAPI_ATTR_GET( fapi2::ATTR_FUSED_CORE_MODE,
                   FAPI_SYSTEM,
                   l_fuseModeState);

    // It is a unicast target. In case of UC target, check for FUSED CORE mode.
    // Incase of FUSED CORE, regardless of target on which request is being made,
    // special wakeup operation must be performed on both odd and even cores.

    if( l_fuseModeState )
    {
        auto l_parentEq     =   i_target.getParent< fapi2::TARGET_TYPE_EQ >();
        auto l_eqCoreList   =   l_parentEq.getChildren< fapi2::TARGET_TYPE_CORE >( fapi2::TARGET_STATE_FUNCTIONAL );
        uint8_t l_tgtPos    =   0;

        FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                       l_modCoreList[0],
                       l_tgtPos );

        if( l_tgtPos & 0x01 )
        {
            l_siblngPos   =   l_tgtPos - 1;
        }
        else
        {
            l_siblngPos   =   l_tgtPos + 1;
        }

        for( const auto& core : l_eqCoreList )
        {
            FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                           core,
                           l_corePos );

            if( l_corePos == l_siblngPos )
            {
                //Attempting Special Wakeup On sibling core
                l_siblingCore = core;
                l_modCoreList.push_back( core );
                break;
            }

        }//for( auto core

    }//if( l_fuseModeState )

    l_tempRc    =   isSplWkupInProgress( l_modCoreList );

    if( l_tempRc == (uint32_t)fapi2::RC_INTERNAL_SPCWKUP_IN_PROGRESS )
    {
        FAPI_INF("Exiting Spl Wkup Recursion");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    blockWakeupRecursion( l_modCoreList, p10specialWakeup::BLOCK );

    FAPI_TRY( checkForUcSplWkupPreReq( i_target, i_operation, i_entity ),
              "Failed To Check Pre-Req For Special Wakeup Of A UniCast Core " );

    FAPI_TRY( initiateUcSplWkup( i_target, i_operation, i_entity ) ,
              "Attempt For Special Wakeup Of Core Failed" );

    //do special wakeup on other half of fused core
    if( l_fuseModeState )
    {
        //Attempting special wakeup on other half of fused core.
        FAPI_TRY( initiateUcSplWkup( l_siblingCore, i_operation, i_entity ) ,
                  "Attempt For Special Wakeup Of Sibling Core Failed" );
    }

fapi_try_exit:
    blockWakeupRecursion( l_modCoreList, p10specialWakeup::UNBLOCK );
    FAPI_INF( "<< p10_uc_core_special_wakeup" );
    return fapi2::current_err;
}


//************************************************************************************************

fapi2::ReturnCode p10_core_special_wakeup(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const p10specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p10specialWakeup::PROC_SPCWKUP_ENTITY i_entity )

{
    FAPI_INF( ">> p10_core_special_wakeup" );

    fapi2::ReturnCode l_tempRc  =   fapi2::FAPI2_RC_SUCCESS;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_fuseModeState     =   0;
    uint8_t l_corePos   =   0;
    uint8_t l_siblngPos =   0;
    std::vector < fapi2::Target <fapi2::TARGET_TYPE_CORE >> l_coreList  =
                i_target.getChildren< fapi2::TARGET_TYPE_CORE >( fapi2::TARGET_STATE_FUNCTIONAL );
    std::vector < fapi2::Target <fapi2::TARGET_TYPE_CORE >> l_modCoreList  =  l_coreList;
    fapi2::Target <fapi2::TARGET_TYPE_CORE> l_siblingCore;

    FAPI_ATTR_GET( fapi2::ATTR_FUSED_CORE_MODE,
                   FAPI_SYSTEM,
                   l_fuseModeState);

    if( 1 == l_modCoreList.size() )
    {
        // It is a unicast target. In case of UC target, check for FUSED CORE mode.
        // Incase of FUSED CORE, regardless of target on which request is being made,
        // special wakeup operation must be performed on both odd and even cores.

        if( l_fuseModeState )
        {
            auto l_parentEq     =   l_modCoreList[0].getParent< fapi2::TARGET_TYPE_EQ >();
            auto l_eqCoreList   =   l_parentEq.getChildren< fapi2::TARGET_TYPE_CORE >( fapi2::TARGET_STATE_FUNCTIONAL );
            uint8_t l_tgtPos    =   0;

            FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                           l_modCoreList[0],
                           l_tgtPos );

            if( l_tgtPos & 0x01 )
            {
                l_siblngPos   =   l_tgtPos - 1;
            }
            else
            {
                l_siblngPos   =   l_tgtPos + 1;
            }

            for( const auto& core : l_eqCoreList )
            {
                FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                               core,
                               l_corePos );

                if( l_corePos == l_siblngPos )
                {
                    //Attempting Special Wakeup On sibling core
                    l_siblingCore = core;
                    l_modCoreList.push_back( core );
                    break;
                }

            }//for( auto core

        }//if( l_fuseModeState )

    }//if( 1 == l_modCoreList.size() )

    l_tempRc    =   isSplWkupInProgress( l_modCoreList );

    if( l_tempRc == (uint32_t)fapi2::RC_INTERNAL_SPCWKUP_IN_PROGRESS )
    {
        FAPI_INF("Exiting Spl Wkup Recursion");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    blockWakeupRecursion( l_modCoreList, p10specialWakeup::BLOCK );

    FAPI_TRY( checkForSplWkupPreReq( i_target, i_operation, i_entity ),
              "Failed To Check Spl Wakeup Pre-Req" );

    FAPI_TRY( initiateSplWkup( i_target, i_operation, i_entity ) ,
              "Attempt For Special Wakeup Failed" );

    //Check if special wakeup  has been requested on only one half of fused core
    if( l_fuseModeState && ( 1 == l_coreList.size() ) )
    {
        //Attempting special wakeup on other half of fused core.
        FAPI_TRY( initiateSplWkup( l_siblingCore, i_operation, i_entity ) ,
                  "Attempt For Special Wakeup Failed" );
    }

fapi_try_exit:
    blockWakeupRecursion( l_modCoreList, p10specialWakeup::UNBLOCK );
    FAPI_INF( "<< p10_core_special_wakeup" );

    return fapi2::current_err;
}

//************************************************************************************************
