/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_chiplet_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p10_chiplet_scominit.C
/// @brief SCOM inits to all chiplets (sans quad/fabric)
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_chiplet_scominit.H>
#include <p10_nx_scom.H>
#include <p10_vas_scom.H>
#include <p10_int_scom.H>
#include <p10_mi_omi_scom.H>
#include <p10_mcc_omi_scom.H>

#include <p10_fbc_utils.H>
#include <p10_putmemproc.H>
#include <fapi2_subroutine_executor.H>
#include <fapi2_mem_access.H>

#include <p10_scom_proc_8.H>
#include <p10_scom_proc_e.H>
#include <p10_scom_nmmu_e.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Activate fabric async configuration via switch_cd
///        Note that the performance optimized settings are preconfigured
///        into the fabric Mode D registers via dynamic inits
///
/// @param[in] i_target         Reference to processor chip target
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_chiplet_scominit_fbc_cd(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    uint32_t l_flags = fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC;
    uint64_t l_addr_unused = 0x0ULL;
    uint32_t l_bytes_unused = 1;
    uint8_t l_data_unused[1];
    fapi2::ReturnCode l_rc;

    fapi2::buffer<uint64_t> l_station_mode(0x0);
    fapi2::buffer<uint64_t> l_station_cfg3(0x0);

    // configure fbc to abide by switch_cd signal
    GET_PB_COM_SCOM_EQ0_STATION_MODE(i_target, l_station_mode);
    SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_EQ0(l_station_mode);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_MODE, l_station_mode),
             "Error from p10_fbc_utils_set_racetrack_regs (PB_COM_SCOM_EQ0_STATION_MODE)");

    // select to apply mode D on switch_cd signal
    GET_PB_COM_SCOM_EQ0_STATION_CFG3(i_target, l_station_cfg3);
    SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT0_SELCD(l_station_cfg3);
    SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_UNIT1_SELCD(l_station_cfg3);
    SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK0_SELCD(l_station_cfg3);
    SET_PB_COM_SCOM_EQ0_STATION_CFG3_PB_CFG_PBIASY_LINK1_SELCD(l_station_cfg3);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_CFG3, l_station_cfg3),
             "Error from p10_fbc_utils_set_racetrack_regs (PB_COM_SCOM_EQ0_STATION_CFG3)");

    // issue switch_cd to apply new configuration
    FAPI_CALL_SUBROUTINE(l_rc,
                         p10_putmemproc,
                         i_target,
                         l_addr_unused,
                         l_bytes_unused,
                         l_data_unused,
                         l_flags | fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE);
    FAPI_TRY(l_rc, "Error from p10_putmemproc when setting switch_cd config bit pre-switch");

    FAPI_CALL_SUBROUTINE(l_rc,
                         p10_putmemproc,
                         i_target,
                         l_addr_unused,
                         l_bytes_unused,
                         l_data_unused,
                         l_flags | fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE);
    FAPI_TRY(l_rc, "Error from p10_putmemproc when issuing switch_cd command");

    FAPI_CALL_SUBROUTINE(l_rc,
                         p10_putmemproc,
                         i_target,
                         l_addr_unused,
                         l_bytes_unused,
                         l_data_unused,
                         l_flags | fapi2::SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE);
    FAPI_TRY(l_rc, "Error from p10_putmemproc when clearing switch_cd config bit post-switch");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup nmmu epsilon values
///        Note that the nmmu scom initfile is called in p10_sbe_scominit,
///        but epsilon values were not yet determined at that point, therefore
///        epsilons for nmmu are applied here outside of its scom initfile
///
/// @param[in] i_target         Reference to processor chip target
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_chiplet_scominit_nmmu_epsilons(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::nmmu;

    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_nmmu_targets = i_target.getChildren<fapi2::TARGET_TYPE_NMMU>();
    fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1_Type l_eps_write_cycles_t1;
    fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2_Type l_eps_write_cycles_t2;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, FAPI_SYSTEM, l_eps_write_cycles_t1),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_WRITE_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, FAPI_SYSTEM, l_eps_write_cycles_t2),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_WRITE_CYCLES_T2)");

    for (auto& l_nmmu : l_nmmu_targets)
    {
        fapi2::buffer<uint64_t> l_scom_data;

        FAPI_TRY(GET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE(l_nmmu, l_scom_data),
                 "Error from getScom (FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE)");

        SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL(l_eps_write_cycles_t1, l_scom_data);
        SET_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL(l_eps_write_cycles_t2, l_scom_data);

        FAPI_TRY(PUT_FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE(l_nmmu, l_scom_data),
                 "Error from getScom (FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::ReturnCode l_rc;

    fapi2::toString(i_target, l_tgt_str, sizeof(l_tgt_str));

    // activate fabric async configuration (switch_cd)
    FAPI_DBG("Issuing switch_cd to activate fabric async config on %s...", l_tgt_str);
    FAPI_TRY(p10_chiplet_scominit_fbc_cd(i_target),
             "Error from p10_build_smp_set_fbc_cd");

    // setup nmmu epsilon values
    FAPI_DBG("Applying nmmu epsilon values on target %s...", l_tgt_str);
    FAPI_TRY(p10_chiplet_scominit_nmmu_epsilons(i_target),
             "Error from p10_chiplet_scominit_nmmu_epsilons");

    // apply nx scom initfile
    FAPI_DBG("Invoking p10.nx.scom.initfile on target %s...", l_tgt_str);
    FAPI_EXEC_HWP(l_rc, p10_nx_scom, i_target, FAPI_SYSTEM);
    FAPI_TRY(l_rc, "Error from p10_nx_scom");

    // apply vas scom initfile
    FAPI_DBG("Invoking p10.vas.scom.initfile on target %s...", l_tgt_str);
    FAPI_EXEC_HWP(l_rc, p10_vas_scom, i_target, FAPI_SYSTEM);
    FAPI_TRY(l_rc, "Error from p10_vas_scom");

    // apply int scom initfile
    FAPI_DBG("Invoking p10.int.scom.initfile on target %s...", l_tgt_str);
    FAPI_EXEC_HWP(l_rc, p10_int_scom, i_target, FAPI_SYSTEM);
    FAPI_TRY(l_rc, "Error from p10_int_scom");

    // apply omi scom initfiles
    for (const auto& l_mi_target : i_target.getChildren<fapi2::TARGET_TYPE_MI>())
    {
        for (const auto& l_mcc_target : l_mi_target.getChildren<fapi2::TARGET_TYPE_MCC>())
        {
            fapi2::toString(l_mcc_target, l_tgt_str, sizeof(l_tgt_str));

            FAPI_DBG("Invoking p10.mcc.omi.scom.initfile on target %s...", l_tgt_str);
            FAPI_EXEC_HWP(l_rc, p10_mcc_omi_scom, l_mcc_target, FAPI_SYSTEM, i_target);
            FAPI_TRY(l_rc, "Error from p10.mcc.omi.scom.initfile");

            for (auto l_omi_target : l_mcc_target.getChildren<fapi2::TARGET_TYPE_OMI>())
            {
                fapi2::toString(l_omi_target, l_tgt_str, sizeof(l_tgt_str));

                FAPI_DBG("Invoking p10.mi.omi.scom.initfile on target %s...", l_tgt_str);
                FAPI_EXEC_HWP(l_rc, p10_mi_omi_scom, l_mi_target, l_omi_target, l_mcc_target);
                FAPI_TRY(l_rc, "Error from p10.mi.omi.scom.initfile");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
