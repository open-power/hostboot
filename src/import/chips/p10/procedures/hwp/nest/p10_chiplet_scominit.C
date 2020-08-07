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
#include <p10_nmmu_scom.H>
#include <p10_mi_omi_pretrain_scom.H>
#include <p10_mcc_omi_pretrain_scom.H>

#include <p10_fbc_utils.H>
#include <p10_putmemproc.H>
#include <fapi2_subroutine_executor.H>
#include <fapi2_mem_access.H>

#include <p10_scom_proc_7.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Activate fabric async configuration via switch_cd
///        Note that the performance optimized settings are preconfigured
///        into the fabric Mode D registers via dynamic inits
///
///        The switch_cd should only be issued from the master chip
///
/// @param[in] i_target         Reference to processor chip target
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_chiplet_scominit_switch_cd(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    uint32_t l_flags = fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC;
    uint64_t l_addr_unused = 0x0ULL;
    uint32_t l_bytes_unused = 1;
    uint8_t l_data_unused[1];
    fapi2::ReturnCode l_rc;

    fapi2::buffer<uint64_t> l_hp_mode1(0x0);

    FAPI_TRY(GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(i_target, l_hp_mode1),
             "Error from getScom (PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR)");

    if(GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(l_hp_mode1))
    {
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
    FAPI_TRY(p10_chiplet_scominit_switch_cd(i_target),
             "Error from p10_chiplet_scominit_switch_cd");

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

    // apply nmmu scom initfile
    for(auto& l_nmmu_target : i_target.getChildren<fapi2::TARGET_TYPE_NMMU>())
    {
        FAPI_DBG("Invoking p10.nmmu.scom.initfile on target %s...", l_tgt_str);
        FAPI_EXEC_HWP(l_rc, p10_nmmu_scom, l_nmmu_target, i_target, FAPI_SYSTEM);
        FAPI_TRY(l_rc, "Error from p10_nmmu_scom");
    }

    // apply omi scom initfiles
    for (const auto& l_mi_target : i_target.getChildren<fapi2::TARGET_TYPE_MI>())
    {
        for (const auto& l_mcc_target : l_mi_target.getChildren<fapi2::TARGET_TYPE_MCC>())
        {
            fapi2::toString(l_mcc_target, l_tgt_str, sizeof(l_tgt_str));

            FAPI_DBG("Invoking p10.mcc.omi.pretrain.scom.initfile on target %s...", l_tgt_str);
            FAPI_EXEC_HWP(l_rc, p10_mcc_omi_pretrain_scom, l_mcc_target, FAPI_SYSTEM);
            FAPI_TRY(l_rc, "Error from p10.mcc.omi.pretrain.scom.initfile");

            for (auto l_omi_target : l_mcc_target.getChildren<fapi2::TARGET_TYPE_OMI>())
            {
                fapi2::toString(l_omi_target, l_tgt_str, sizeof(l_tgt_str));

                FAPI_DBG("Invoking p10.mi.omi.pretrain.scom.initfile on target %s...", l_tgt_str);
                FAPI_EXEC_HWP(l_rc, p10_mi_omi_pretrain_scom, l_mi_target, l_omi_target, l_mcc_target, FAPI_SYSTEM);
                FAPI_TRY(l_rc, "Error from p10.mi.omi.pretrain.scom.initfile");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
