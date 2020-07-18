/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp_adu.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_build_smp_adu.C
/// @brief Interface for ADU operations required to support fabric
///        configuration actions (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_build_smp_adu.H>
#include <p10_putmemproc.H>
#include <fapi2_subroutine_executor.H>
#include <fapi2_mem_access.H>

#include <p10_scom_proc.H>
#include <p10_scom_iohs.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

// ADU lock
const uint32_t P10_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS = 1;
const bool     P10_BUILD_SMP_PHASE1_ADU_PICK_LOCK = false;
const uint32_t P10_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS = 5;
const bool     P10_BUILD_SMP_PHASE2_ADU_PICK_LOCK = true;

// FFDC logging on ADU switch fails
const uint8_t  P10_BUILD_SMP_FFDC_NUM_REGS = 15;
const uint32_t P10_BUILD_SMP_FFDC_REGS[P10_BUILD_SMP_FFDC_NUM_REGS] =
{
    scomt::proc::PB_COM_SCOM_ES3_STATION_MODE,           // 0  (FBC Mode)
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR,  // 1  (FBC HP Mode1)
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT,  // 2
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR,  // 3  (FBC HP Mode2)
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT,  // 4
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE3_CURR,  // 5  (FBC HP Mode3)
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT,  // 6
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE4_CURR,  // 7  (FBC HP Mode4)
    scomt::proc::PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT,  // 8
    scomt::iohs::AXON_CPLT_CONF1_RW,                     // 9  (IOHS IOvalids)
    scomt::proc::PB_PTLSCOM10_PTL_FIR_REG_RW,            // 10 (IOHS TL train states)
    scomt::proc::PB_PTLSCOM23_PTL_FIR_REG_RW,            // 11
    scomt::proc::PB_PTLSCOM45_PTL_FIR_REG_RW,            // 12
    scomt::proc::PB_PTLSCOM67_PTL_FIR_REG_RW,            // 13
    scomt::proc::TP_TPBR_AD_SND_MODE_REG                 // 14 (Switch AB/CD)
};

// DLR psave mode (HW529136)
const uint8_t ENUM_PSAVE_WIDTH_DISABLED = 0x00;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Check ADU status matches expected state/value
///        Note: Intended to be run while holding ADU lock
///
/// @param[in] i_smp        Structure encapsulating SMP topology
/// @param[inout] o_rc      FAPI error code to be appended with FFDC
/// @return void.
///
void p10_build_smp_append_ffdc(
    p10_build_smp_system& i_smp,
    fapi2::ReturnCode& o_rc)
{
    FAPI_DBG("Start");

    // collect FFDC
    fapi2::variable_buffer l_chip_data_valid(8 * P10_BUILD_SMP_MAX_SIZE);
    fapi2::variable_buffer l_group_ids(8 * P10_BUILD_SMP_MAX_SIZE);
    fapi2::variable_buffer l_chip_ids(8 * P10_BUILD_SMP_MAX_SIZE);
    fapi2::variable_buffer l_ffdc_addrs(64 * P10_BUILD_SMP_FFDC_NUM_REGS);
    fapi2::variable_buffer l_ffdc_reg_data(64 * P10_BUILD_SMP_MAX_SIZE * P10_BUILD_SMP_FFDC_NUM_REGS);
    uint8_t l_idx = 0;

    // init buffers
    l_chip_data_valid.flush<0>();
    l_group_ids.flush<1>();
    l_chip_ids.flush<1>();
    l_ffdc_reg_data.flush<1>();

    for (uint8_t jj = 0; jj < P10_BUILD_SMP_FFDC_NUM_REGS; jj++)
    {
        l_ffdc_addrs.set<uint64_t>(jj, P10_BUILD_SMP_FFDC_REGS[jj]);
    }

    // extract FFDC data
    for (auto n_iter = i_smp.groups.begin(); n_iter != i_smp.groups.end(); n_iter++)
    {
        for (auto p_iter = n_iter->second.chips.begin(); p_iter != n_iter->second.chips.end(); p_iter++)
        {
            // mark valid
            (void) l_chip_data_valid.set<uint8_t>(l_idx, 0x1);

            // log group/chip ID
            (void) l_group_ids.set<uint8_t>(l_idx, n_iter->first);
            (void) l_chip_ids.set<uint8_t>(l_idx, p_iter->first);

            // collect SCOM data
            for (uint8_t jj = 0; jj < P10_BUILD_SMP_FFDC_NUM_REGS; jj++)
            {
                fapi2::buffer<uint64_t> l_scom_data;
                fapi2::ReturnCode l_scom_rc;

                // discard bad SCOM return codes, mark data as all ones and keep collecting
                l_scom_rc = fapi2::getScom(*(p_iter->second.target),
                                           P10_BUILD_SMP_FFDC_REGS[jj],
                                           l_scom_data);

                if (l_scom_rc)
                {
                    l_scom_data.flush<1>();
                }

                (void) l_ffdc_reg_data.set<uint64_t>((P10_BUILD_SMP_FFDC_NUM_REGS * l_idx) + jj,
                                                     l_scom_data());
            }

            l_idx++;
        }
    }

    fapi2::ffdc_t CHIP_DATA_VALID;
    fapi2::ffdc_t GROUP_IDS;
    fapi2::ffdc_t CHIP_IDS;
    fapi2::ffdc_t FFDC_ADDRS;
    fapi2::ffdc_t FFDC_REG_DATA;

    CHIP_DATA_VALID.ptr() = static_cast<void*>(&l_chip_data_valid);
    CHIP_DATA_VALID.size() = sizeof(l_chip_data_valid);
    GROUP_IDS.ptr() = static_cast<void*>(&l_group_ids);
    GROUP_IDS.size() = sizeof(l_group_ids);
    CHIP_IDS.ptr() = static_cast<void*>(&l_chip_ids);
    CHIP_IDS.size() = sizeof(l_chip_ids);
    FFDC_ADDRS.ptr() = static_cast<void*>(&l_ffdc_addrs);
    FFDC_ADDRS.size() = sizeof(l_ffdc_addrs);
    FFDC_REG_DATA.ptr() = static_cast<void*>(&l_ffdc_reg_data);
    FFDC_REG_DATA.size() = sizeof(l_ffdc_reg_data);

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P10_BUILD_SMP_ADU_STATUS_MISMATCH_ERR);
}


///
/// @brief Set action which will occur on fabric pmisc switch command
///
/// @param[in] i_target     Processor chip target
/// @param[in] i_action     Enumerated type representing fabric operation
///
/// @return fapi2:ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_adu_set_switch_action(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_build_smp_adu_action i_action)
{
    FAPI_DBG("Start");

    uint64_t l_addr = 0x0ULL;
    uint32_t l_bytes = 1;
    uint32_t l_flags = fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC;
    uint8_t l_data_unused[1];
    fapi2::ReturnCode l_rc;

    if (i_action == SWITCH_AB)
    {
        l_flags |= fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_AB_MODE;
    }
    else if (i_action == SWITCH_CD)
    {
        l_flags |= fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE;
    }
    else
    {
        l_flags |= fapi2::SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE;
    }

    // issue operation
    FAPI_CALL_SUBROUTINE(fapi2::current_err,
                         p10_putmemproc,
                         i_target,
                         l_addr,
                         l_bytes,
                         l_data_unused,
                         l_flags);

    FAPI_TRY(fapi2::current_err,
             "Error from p10_putmemproc");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// See doxygen comments in header file
fapi2::ReturnCode p10_build_smp_sequence_adu(
    p10_build_smp_system& i_smp,
    const p10_build_smp_operation i_op,
    const p10_build_smp_adu_action i_action)
{
    FAPI_DBG("Start");

    // validate input action, set ADU operation parameters
    uint32_t l_flags = fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC;
    uint32_t l_bytes = 1;
    uint64_t l_addr = 0x0ULL;
    uint8_t l_data_unused[1];
    fapi2::ReturnCode l_rc;

    switch (i_action)
    {
        case SWITCH_AB:
        case SWITCH_CD:
            l_flags |= fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE;
            break;

        case QUIESCE:
            l_flags |= fapi2::SBE_MEM_ACCESS_FLAGS_PB_DIS_MODE;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P10_BUILD_SMP_BAD_ADU_ACTION_ERR()
                        .set_OP(i_op)
                        .set_ACTION(i_action),
                        "Invalid ADU action specified");
    }

    // loop through all chips, set switch operation
    FAPI_DBG("Setting switch controls");

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            // Condition for hotplug switch operation
            // all chips which were not quiesced prior to switch AB will need to observe the switch
            if (i_action != QUIESCE)
            {
                FAPI_TRY(p10_build_smp_adu_set_switch_action(
                             *(p_iter->second.target),
                             i_action),
                         "Error from p10_build_smp_adu_set_switch_action (set)");
            }
        }
    }

    // perform action on specified chips
    FAPI_DBG("Performing action = %d", i_action);

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            if (((i_action == QUIESCE) && (p_iter->second.issue_quiesce_next))
                || ((i_action == SWITCH_AB) && (p_iter->second.master_chip_sys_next))
                || (i_action == SWITCH_CD))
            {
                char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(*(p_iter->second.target), l_target_str, sizeof(l_target_str));

                // issue operation
                FAPI_INF("Issuing ADU op for %s", l_target_str);
                FAPI_CALL_SUBROUTINE(fapi2::current_err,
                                     p10_putmemproc,
                                     (*(p_iter->second.target)),
                                     l_addr,
                                     l_bytes,
                                     l_data_unused,
                                     l_flags);

                FAPI_TRY(fapi2::current_err,
                         "Error from p10_putmemproc");
            }
        }
    }

    // loop through all chips, reset switch controls
    FAPI_DBG("Operation complete, resetting switch controls");

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            // reset switch controls
            if (i_action != QUIESCE)
            {
                FAPI_TRY(p10_build_smp_adu_set_switch_action(
                             *(p_iter->second.target),
                             p10_build_smp_adu_action::RESET_SWITCH),
                         "Error from p10_build_smp_adu_set_switch_action (clear)");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
