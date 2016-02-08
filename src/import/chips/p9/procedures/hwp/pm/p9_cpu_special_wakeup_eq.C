/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup_eq.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
///  @brief         :    HWP to perform special wakeup of a core

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    2
// *HWP Consumed by :    OCC:FSP:HOST:CRO

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_cpu_special_wakeup.H>
#include <p9_cpu_special_wakeup_lib.H>

/// ----------------------------------------------------------------------------
///
/// @brief       Sets a normal core chiplet into special wakeup state.
///
fapi2::ReturnCode p9_cpu_special_wakeup_eq(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ>& i_target,
    const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_DBG("> p9_cpu_special_wakeup_eq");
    FAPI_TRY(_special_wakeup<fapi2::TARGET_TYPE_EQ> (
                 i_target,
                 i_operation,
                 i_entity ));

fapi_try_exit:
    FAPI_INF("< p9_cpu_special_wakeup_eq" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------

fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId)
{
    FAPI_INF("> spwkup_deassert EQ" );

    uint64_t l_address = i_processing_info.spwkup_address[0];
    FAPI_TRY(_spwkup_deassert(i_chipletTarget, l_address, i_msgId));

fapi_try_exit:
    FAPI_INF("< spwkup_deassert EQ" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------

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
