/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup_core.C $ */
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

///
///  @file          :    p9_cpu_special_wakeup_core.C
///  @brief         :    HWP to perform special wakeup of a core

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    3
// *HWP Consumed by :    OCC:FSP:HOST:CRO

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_cpu_special_wakeup.H>
#include <p9_cpu_special_wakeup_lib.H>
#include <p9_ppe_defs.H>
#include <p9_ppe_utils.H>

fapi2::ReturnCode collectCoreTimeoutFailInfo( const fapi2::Target < fapi2::TARGET_TYPE_CORE>& i_target,
        ProcessingValues_t i_processing_info );

/// ----------------------------------------------------------------------------
///
/// @brief      Sets a normal core chiplet into special wakeup state.
/// @param[in]  i_target     core target
/// @param[in]  i_operation  Special Wakeup Operation i.e. assert or deassert
/// @param[in]  i_entity     entity to be considered for special wakeup.
/// @return     fapi2 return code.
///
fapi2::ReturnCode p9_cpu_special_wakeup_core(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE>& i_target,
    const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_INF(">> p9_cpu_special_wakeup_core");
    fapi2::ReturnCode l_rc;
    uint8_t l_spWakeUpInProg    =   0;

    ProcessingValues_t l_processing_info;
    auto l_eqTarget = i_target.getParent<fapi2::TARGET_TYPE_EQ>();

    FAPI_ATTR_GET( fapi2::ATTR_CORE_INSIDE_SPECIAL_WAKEUP,
                   i_target,
                   l_spWakeUpInProg );

    // A special wakeup is already in progress. In all likelyhood, a special
    // wakeup has timed out and we are in FFDC collection path. During this
    // FFDC collection, we SCOMed a register which itself needs a special
    // wakeup.

    if( l_spWakeUpInProg )
    {
        FAPI_INF("exiting core recurssion");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    p9specialWakeup::blockWakeupRecurssion( l_eqTarget, p9specialWakeup::BLOCK );

    l_rc = _special_wakeup<fapi2::TARGET_TYPE_CORE> (
               i_target,
               i_operation,
               i_entity,
               l_processing_info );

    if( l_rc == (uint32_t)fapi2::RC_INTERNAL_SPCWKUP_TIMEOUT )
    {
        collectCoreTimeoutFailInfo( i_target, l_processing_info );
    }

    p9specialWakeup::blockWakeupRecurssion( l_eqTarget, p9specialWakeup::UNBLOCK );

    FAPI_INF("<< p9_cpu_special_wakeup_core" );
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------

///
/// @brief      Collect FFDC for EQ Special Wakeup timeout
/// @param[in]  i_target     core target
/// @param[in]  i_operation  info pertaining to special wakeup
/// @return     fapi2 return code.
///
fapi2::ReturnCode collectCoreTimeoutFailInfo( const fapi2::Target < fapi2::TARGET_TYPE_CORE>& i_target,
        ProcessingValues_t i_processing_info )
{
    FAPI_INF(">> collectCoreTimeoutFailInfo" );
    fapi2::buffer<uint64_t> l_CPMMR;
    fapi2::buffer<uint64_t> l_GPMMR;
    fapi2::buffer<uint64_t> l_spWakeupRegVal;
    fapi2::buffer<uint64_t> l_histRegVal;

    fapi2::getScom( i_target, C_CPPM_CPMMR, l_CPMMR );
    fapi2::getScom( i_target, C_PPM_GPMMR_SCOM, l_GPMMR );
    fapi2::getScom( i_target, i_processing_info.spwkup_address[0], l_spWakeupRegVal );
    fapi2::getScom( i_target, i_processing_info.history_address[0], l_histRegVal );
    fapi2::Target < fapi2::TARGET_TYPE_EX> parentExTgt = i_target.getParent <fapi2::TARGET_TYPE_EX>();
    uint8_t l_exPos = 0;
    FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, parentExTgt, l_exPos );

    // Collect PPE FFDC for CME, SGPE and PGPE
    std::vector<uint64_t> l_ppeBaseAddresses;
    l_ppeBaseAddresses.push_back( getCmeBaseAddress( l_exPos ) );
    l_ppeBaseAddresses.push_back( SGPE_BASE_ADDRESS );
    l_ppeBaseAddresses.push_back( PGPE_BASE_ADDRESS );

    FAPI_ASSERT( false ,
                 fapi2::SPCWKUP_CORE_TIMEOUT().
                 set_POLLCOUNT( i_processing_info.poll_count ).
                 set_SP_WKUP_REG_VALUE( l_spWakeupRegVal ).
                 set_HISTORY_VALUE( l_histRegVal ).
                 set_ENTITY( i_processing_info.entity ).
                 set_CPMMR( l_CPMMR ).
                 set_GPMMR( l_GPMMR ).
                 set_EQ_TARGET( i_target.getParent <fapi2::TARGET_TYPE_EQ>() ).
                 set_EX_TARGET( parentExTgt ).
                 set_CORE_TARGET( i_target ).
                 set_PROC_CHIP_TARGET( i_processing_info.procTgt ).
                 set_PPE_BASE_ADDRESSES( l_ppeBaseAddresses ).
                 set_PPE_STATE_MODE( XIRS ),
                 "Timed Out In Setting Core Special Wakeup");
fapi_try_exit:
    FAPI_INF("<< collectCoreTimeoutFailInfo" );
    return fapi2::current_err;
}
// -----------------------------------------------------------------------------
/// @param[in]  i_chipletTarget     core target
/// @param[in]  i_processing_info   struct storing processing info
/// @param[in]  i_msgId             Id pertaining to debug message string.
/// @return     fapi2 return code.
fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId )
{
    FAPI_INF("> spwkup_deassert Core" );

    uint64_t l_address = i_processing_info.spwkup_address[0];
    FAPI_TRY(_spwkup_deassert(i_chipletTarget, l_address, i_msgId));

fapi_try_exit:
    FAPI_INF("< spwkup_deassert Core" );
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
///
/// @brief Set addresses for a core target type
/// @param[in]  i_target         core target
/// @param[in]  i_structure      struct storing processing info
/// @param[in]  i_entity         entity to be considered for special wakeup.
/// @return fapi2 return code.
///
template<>
fapi2::ReturnCode set_addresses(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity )
{
    FAPI_INF(">> set_addresses for Core");

    uint8_t l_core_num = 0;

    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, i_target, l_core_num),
             "fapiGetAttribute of ATTR_CHIP_UNIT_POS");

    FAPI_DBG("Core %d being procesed.", l_core_num);

    i_structure.spwkup_address[0]  = SPCWKUP_ADDR[i_entity][p9specialWakeup::SPW_CORE]
                                     + 0x01000000 * l_core_num;
    i_structure.history_address[0] = SPCWKUP_HIST_ADDR[i_entity][p9specialWakeup::SPW_CORE]
                                     + 0x01000000 * l_core_num;
    i_structure.netctrl_address[0] = SPCWKUP_NETCTRL0_ADDR[p9specialWakeup::SPW_CORE]
                                     + 0x01000000 * l_core_num;
    i_structure.gpmmr_address[0] = SPCWKUP_GPMMR_ADDR[p9specialWakeup::SPW_CORE]
                                   + 0x01000000 * l_core_num;
    i_structure.num_addresses = 1;

    FAPI_DBG("i_structure.spwkup_address[%d]  = 0x%08llX \n "
             "i_structure.history_address[%d] = 0x%08llX \n "
             "i_structure.netctrl_address[%d] = 0x%08llX \n "
             "i_structure.gpmmr_addresss[%d]  = 0x%08llX \n " ,
             0, i_structure.spwkup_address[0],
             0, i_structure.history_address[0],
             0, i_structure.netctrl_address[0],
             0, i_structure.gpmmr_address[0]);

fapi_try_exit:
    FAPI_INF("<< set_addresses for Core");
    return fapi2::current_err;
}
