/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup_eq.C $ */
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
///  @file          :    p9_cpu_special_wakeup_eq.C
///  @brief         :    HWP to perform special wakeup of an eq

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


fapi2::ReturnCode collectEqTimeoutFailInfo( const fapi2::Target < fapi2::TARGET_TYPE_EQ>& i_target,
        ProcessingValues_t i_processing_info );
/// ----------------------------------------------------------------------------
///
/// @brief      Sets a normal eq chiplet into special wakeup state.
/// @param[in]  i_target     eq target
/// @param[in]  i_operation  Special Wakeup Operation i.e. assert or deassert
/// @param[in]  i_entity     entity to be considered for special wakeup.
/// @return     fapi2 return code.
///
fapi2::ReturnCode p9_cpu_special_wakeup_eq(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ>& i_target,
    const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_INF(">> p9_cpu_special_wakeup_eq");

    uint8_t l_spWakeUpInProg = 0;
    ProcessingValues_t l_processing_info;
    fapi2::ReturnCode l_rc;

    FAPI_ATTR_GET( fapi2::ATTR_EQ_INSIDE_SPECIAL_WAKEUP,
                   i_target,
                   l_spWakeUpInProg );

    //A special wakeup is already in progress. In all likelyhood, a special
    // wakeup has timed out and we are in FFDC collection path. During this
    // FFDC collection, we SCOMed a register which itself needs a special
    // wakeup.

    if( l_spWakeUpInProg )
    {
        FAPI_INF("exiting eq recurssion");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    p9specialWakeup::blockWakeupRecurssion( i_target, p9specialWakeup::BLOCK );

    l_rc = _special_wakeup( i_target,
                            i_operation,
                            i_entity,
                            l_processing_info );

    // Collect Register data
    if( l_rc == (uint32_t) fapi2::RC_INTERNAL_SPCWKUP_TIMEOUT )
    {
        collectEqTimeoutFailInfo( i_target, l_processing_info );
    }

    p9specialWakeup::blockWakeupRecurssion( i_target, p9specialWakeup::UNBLOCK );

    FAPI_INF("<< p9_cpu_special_wakeup_eq" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------

///
/// @brief      Collect FFDC for EQ Special Wakeup timeout
/// @param[in]  i_target     eq target
/// @param[in]  i_operation  info pertaining to special wakeup
/// @return     fapi2 return code.
///
fapi2::ReturnCode collectEqTimeoutFailInfo( const fapi2::Target < fapi2::TARGET_TYPE_EQ>& i_target,
        ProcessingValues_t i_processing_info )
{
    FAPI_INF(">> collectEqTimeoutFailInfo" );

    fapi2::buffer<uint64_t> l_GPMMR;
    fapi2::buffer<uint64_t> l_spWakeupRegVal;
    fapi2::buffer<uint64_t> l_histRegVal;
    fapi2::buffer<uint64_t> l_netCtrlVal;
    std::vector<uint64_t> l_ppeBaseAddressList;
    l_ppeBaseAddressList.push_back( SGPE_BASE_ADDRESS );

    uint8_t l_exPos = 0;
    auto l_ex_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EX>();

    for ( auto it : l_ex_vector )
    {
        FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, it, l_exPos );
        l_ppeBaseAddressList.push_back( getCmeBaseAddress( l_exPos  ) );
    }


    fapi2::getScom( i_target, i_processing_info.history_address[0], l_histRegVal);
    fapi2::getScom( i_target, EQ_PPM_GPMMR_SCOM, l_GPMMR );
    fapi2::getScom( i_target, i_processing_info.spwkup_address[0], l_spWakeupRegVal );
    fapi2::getScom( i_target, i_processing_info.netctrl_address[0], l_netCtrlVal );

    FAPI_ASSERT( false ,
                 fapi2::SPCWKUP_EQ_TIMEOUT().
                 set_POLLCOUNT( i_processing_info.poll_count ).
                 set_QUAD_NETCTRL( l_netCtrlVal ).
                 set_SP_WKUP_REG_VALUE( l_spWakeupRegVal ).
                 set_QUAD_HISTORY_VALUE( l_histRegVal ).
                 set_ENTITY( i_processing_info.entity ).
                 set_GPMMR( l_GPMMR ).
                 set_EQ_TARGET( i_target ).
                 set_EX0_TARGET( l_ex_vector[0] ).  //ignoring case of no functional ex
                 set_EX1_TARGET((( l_ex_vector.size() > 1 ) ? l_ex_vector[1] : l_ex_vector[0] )).
                 set_NUM_FUNC_EX( l_ex_vector.size() ).
                 set_PROC_CHIP_TARGET( i_processing_info.procTgt ).
                 set_PPE_BASE_ADDRESS_LIST( l_ppeBaseAddressList ).
                 set_PPE_STATE_MODE( XIRS ),
                 "Timed Out In Setting The EQ Special Wakeup" );

fapi_try_exit:
    FAPI_INF("<< collectEqTimeoutFailInfo" );
    return fapi2::current_err;
}
/// ----------------------------------------------------------------------------
/// @brief      deasserts special wakeup state on a given chiplet
/// @param[in]  i_chipletTarget     eq target
/// @param[in]  i_processing_info   struct storing processing info
/// @param[in]  i_msgId             Id pertaining to debug message string.
/// @return     fapi2 return code.
fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId )
{
    FAPI_INF("> spwkup_deassert EQ" );

    uint64_t l_address = i_processing_info.spwkup_address[0];
    FAPI_TRY(_spwkup_deassert(i_chipletTarget, l_address, i_msgId));

fapi_try_exit:
    FAPI_INF("< spwkup_deassert EQ" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------

///
/// @brief Set address for an eq target type
/// @param[in]  i_target         eq target
/// @param[in]  i_structure      struct storing processing info
/// @param[in]  i_entity         entity to be considered for special wakeup.
/// @return fapi2 return code.
///
template<>
fapi2::ReturnCode set_addresses(const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity )
{
    FAPI_INF("> set_addresses for EQ");

    uint8_t l_eq_num = 0;

    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, i_target, l_eq_num),
             "fapiGetAttribute of ATTR_CHIP_UNIT_POS");

    FAPI_DBG("EQ %d being procesed.", l_eq_num);

    i_structure.spwkup_address[0]  = SPCWKUP_ADDR[i_entity][p9specialWakeup::SPW_EQ]
                                     + 0x01000000 * l_eq_num;
    i_structure.history_address[0] = SPCWKUP_HIST_ADDR[i_entity][p9specialWakeup::SPW_EQ]
                                     + 0x01000000 * l_eq_num;
    i_structure.netctrl_address[0] = SPCWKUP_NETCTRL0_ADDR[p9specialWakeup::SPW_EQ]
                                     + 0x01000000 * l_eq_num;
    i_structure.gpmmr_address[0] = SPCWKUP_GPMMR_ADDR[p9specialWakeup::SPW_EQ]
                                   + 0x01000000 * l_eq_num;
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
    FAPI_INF("< set_addresses for EQ");
    return fapi2::current_err;
}
