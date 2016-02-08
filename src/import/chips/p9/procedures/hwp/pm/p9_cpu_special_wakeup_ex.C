/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup_ex.C $ */
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
///  @file          :    p9_cpu_special_wakeup_ex.C
///  @brief         :    HWP to perform special wakeup of an EX "chiplet"

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
/// @brief       Sets an EX "chiplet" into special wakeup state.
///
fapi2::ReturnCode p9_cpu_special_wakeup_ex(
    const fapi2::Target < fapi2::TARGET_TYPE_EX>& i_target,
    const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
    const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_DBG("> p9_cpu_special_wakeup_ex");
    FAPI_TRY(_special_wakeup<fapi2::TARGET_TYPE_EX> (
                 i_target,
                 i_operation,
                 i_entity ));

fapi_try_exit:
    FAPI_INF("< p9_cpu_special_wakeup_ex" );
    return fapi2::current_err;

}

/// ----------------------------------------------------------------------------

fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId)
{
    FAPI_INF("> spwkup_deassert core EX" );

    uint64_t l_address;

    for (uint32_t i = 0; i < i_processing_info.num_addresses; ++i)
    {
        l_address = i_processing_info.spwkup_address[i];
        FAPI_TRY(_spwkup_deassert(i_chipletTarget, l_address, i_msgId));
    }

fapi_try_exit:
    FAPI_INF("< spwkup_deassert EX" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------

template<>
fapi2::ReturnCode set_addresses(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity )
{
    FAPI_INF("> set_addresses for EX");

    FAPI_DBG("i_processing: setaddr start"
             "entity = %d  "
             "b_xstop_flag = %d "
             "b_ignore_xstop_flag = %d "
             "b_wakeup_on_entry_flag = %d "
             "b_ex_flag = %d \n",
             i_structure.entity,
             i_structure.b_xstop_flag,
             i_structure.b_ignore_xstop_flag,
             i_structure.b_wakeup_on_entry_flag,
             i_structure.b_ex_flag);

    uint8_t l_ex_num = 0;
    uint8_t l_core_num = 0;
    uint32_t i = 0;

    // Determine the good cores in the EX
    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_ASSERT(l_core_functional_vector.size() > 0,
                fapi2::SPCWKUP_NOEXCORES(),
                "No good cores to special wake-up in targeted EX");

    for (auto it : l_core_functional_vector)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, it, l_core_num),
                 "fapiGetAttribute of ATTR_CHIP_UNIT_POS");

        FAPI_DBG("EX %d being procesed. Setting up for Core %d with index %d",
                 l_ex_num, l_core_num, i);

        i_structure.spwkup_address[i]  = SPCWKUP_ADDR[i_entity][p9specialWakeup::SPW_CORE]
                                         + 0x01000000 * l_core_num;
        i_structure.history_address[i] = SPCWKUP_HIST_ADDR[i_entity][p9specialWakeup::SPW_CORE]
                                         + 0x01000000 * l_core_num;
        i_structure.netctrl_address[i] = SPCWKUP_NETCTRL0_ADDR[p9specialWakeup::SPW_CORE]
                                         + 0x01000000 * l_core_num;
        i_structure.gpmmr_address[i] = SPCWKUP_GPMMR_ADDR[p9specialWakeup::SPW_CORE]
                                       + 0x01000000 * l_core_num;

        FAPI_DBG("i_structure.spwkup_address[%d]  = 0x%08llX \n "
                 "i_structure.history_address[%d] = 0x%08llX \n "
                 "i_structure.netctrl_address[%d] = 0x%08llX \n "
                 "i_structure.gpmmr_addresss[%d]  = 0x%08llX \n " ,
                 i, i_structure.spwkup_address[i],
                 i, i_structure.history_address[i],
                 i, i_structure.netctrl_address[i],
                 i, i_structure.gpmmr_address[i]);
        ++i;
    }

    i_structure.num_addresses = i;


fapi_try_exit:
    FAPI_INF("< set_addresses for EX");
    return fapi2::current_err;
}
