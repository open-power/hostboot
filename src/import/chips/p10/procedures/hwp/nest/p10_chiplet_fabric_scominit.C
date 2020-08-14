/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_chiplet_fabric_scominit.C $ */
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
/// @file p10_chiplet_fabric_scominit.C
/// @brief Apply fabric scom inits to prepare for xlink enablement
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_chiplet_fabric_scominit.H>
#include <p10_smp_link_firs.H>
#include <p10_fbc_utils.H>
#include <p10_fbc_no_hp_scom.H>
#include <p10_fbc_ptl_scom.H>
#include <p10_fbc_dlp_scom.H>

#include <p10_scom_proc.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_chiplet_fabric_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_config_intranode,
    const bool i_config_internode)
{
    FAPI_DBG("Start");
    FAPI_DBG("  i_config_intranode: %d", i_config_intranode);
    FAPI_DBG("  i_config_internode: %d", i_config_internode);

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_iohs_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::ReturnCode l_rc;

    if (i_config_intranode)
    {
        // apply FBC non-hotplug scom initfile
        fapi2::toString(i_target, l_tgt_str, sizeof(l_tgt_str));
        FAPI_DBG("Invoking p10.fbc.no_hp.scom.initfile on target %s...", l_tgt_str);
        FAPI_EXEC_HWP(l_rc, p10_fbc_no_hp_scom, i_target, FAPI_SYSTEM);
        FAPI_TRY(l_rc, "Error from p10_fbc_no_hp_scom");

        // init all FIRs as inactive before applying configuration
        for(auto l_iohs : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_PRESENT))
        {
            FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_t::BOTH, action_t::INACTIVE),
                     "Error from p10_smp_link_firs when masking firs for all links");
        }
    }

    for (auto l_iohs : l_iohs_targets)
    {
        fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fabric_link_active;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs, l_fabric_link_active),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

        if(l_fabric_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE)
        {
            fapi2::ATTR_IOHS_DRAWER_INTERCONNECT_Type l_drawer_interconnect;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_DRAWER_INTERCONNECT, l_iohs, l_drawer_interconnect),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_DRAWER_INTERCONNECT)");

            if((i_config_intranode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_FALSE)) ||
               (i_config_internode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE)))
            {
                auto l_pauc = l_iohs.getParent<fapi2::TARGET_TYPE_PAUC>();
                fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
                sublink_t sublink_opt;

                // apply FBC TL scom initfile
                fapi2::toString(l_pauc, l_tgt_str, sizeof(l_tgt_str));
                FAPI_DBG("Invoking p10.fbc.ptl.scom.initfile on target %s...", l_tgt_str);
                FAPI_EXEC_HWP(l_rc, p10_fbc_ptl_scom, l_pauc, i_target, FAPI_SYSTEM);
                FAPI_TRY(l_rc, "Error from p10_fbc_ptl_scom");

                // apply FBC DL scom initfile
                fapi2::toString(l_iohs, l_tgt_str, sizeof(l_tgt_str));
                FAPI_DBG("Invoking p10.fbc.dlp.scom.initfile on target %s...", l_tgt_str);
                FAPI_EXEC_HWP(l_rc, p10_fbc_dlp_scom, l_iohs, i_target, FAPI_SYSTEM);
                FAPI_TRY(l_rc, "Error from p10_fbc_dlp_scom");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs, l_link_train),
                         "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

                switch(l_link_train)
                {
                    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
                        sublink_opt = sublink_t::BOTH;
                        break;

                    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
                        sublink_opt = sublink_t::EVEN;
                        break;

                    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
                        sublink_opt = sublink_t::ODD;
                        break;

                    default:
                        sublink_opt = sublink_t::NONE;
                        break;
                }

                // setup and unmask TL/DL FIRs
                FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_opt, action_t::RUNTIME),
                         "Error from p10_smp_link_firs when configuring for runtime operations");
            }
        }
        else
        {
            // mask TL/DL FIRs for links that are not configured for smp operations
            if (i_config_intranode)
            {
                FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_t::BOTH, action_t::INACTIVE),
                         "Error from p10_smp_link_firs when configuring both sublinks for inactive operations");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
