/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_smp_wrap.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_smp_wrap.C
/// @brief Perform fabric/link reconfiguration for smp wrap mode (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_smp_wrap.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint8_t NUM_PROCS = 4;

struct wrap_mode_def
{
    fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type num_links[NUM_PROCS];
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type link_en[NUM_PROCS];
};

struct wrap_mode_def MODEA_DEF =
{
    .num_links = { 3, 3, 3, 3 },
    .link_en =
    {
        { 0, 1, 0, 0, 1, 0, 1, 0 }, // p0
        { 0, 1, 0, 0, 1, 0, 1, 0 }, // p1
        { 0, 1, 0, 0, 1, 0, 1, 0 }, // p2
        { 0, 1, 0, 0, 1, 0, 1, 0 }, // p3
    },
};

struct wrap_mode_def MODEB_DEF =
{
    .num_links = { 3, 3, 3, 3 },
    .link_en =
    {
        { 0, 0, 1, 0, 0, 1, 0, 1 }, // p0
        { 0, 0, 1, 0, 0, 1, 0, 1 }, // p1
        { 0, 0, 1, 0, 0, 1, 0, 1 }, // p2
        { 0, 0, 1, 0, 0, 1, 0, 1 }, // p3
    },
};

struct wrap_mode_def MODEC_DEF =
{
    .num_links = { 3, 3, 3, 3 },
    .link_en =
    {
        { 1, 0, 0, 0, 0, 1, 0, 1 }, // p0
        { 0, 0, 0, 1, 0, 1, 0, 1 }, // p1
        { 1, 0, 0, 0, 0, 1, 0, 1 }, // p2
        { 0, 0, 0, 1, 0, 1, 0, 1 }, // p3
    },
};

struct wrap_mode_def MODEV_DEF =
{
    .num_links = { 1, 1, 1, 1 },
    .link_en =
    {
        { 1, 0, 0, 0, 0, 0, 0, 0 }, // p0
        { 0, 0, 0, 1, 0, 0, 0, 0 }, // p1
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // p2
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // p3
    },
};

struct wrap_mode_def MODEW_DEF =
{
    .num_links = { 1, 1, 1, 1 },
    .link_en =
    {
        { 0, 1, 0, 0, 0, 0, 0, 0 }, // p0
        { 0, 0, 1, 0, 0, 0, 0, 0 }, // p1
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // p2
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // p3
    },
};

struct wrap_mode_def MODEX_DEF =
{
    .num_links = { 1, 1, 1, 1 },
    .link_en =
    {
        { 0, 0, 1, 0, 0, 0, 0, 0 }, // p0
        { 0, 1, 0, 0, 0, 0, 0, 0 }, // p1
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // p2
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // p3
    },
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_smp_wrap_mfg_mode(
    bool& o_is_smp_wrap_mode)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    fapi2::ATTR_MFG_FLAGS_Type l_mfg_flags;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, FAPI_SYSTEM, l_mfg_flags),
             "Error from FAPI_ATTR_GET (ATTR_MFG_FLAGS)");

    o_is_smp_wrap_mode = (l_mfg_flags[MFG_FLAGS_SMP_WRAP_CELL] == fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_SMP_WRAP_CONFIG) ?
                         (true) : (false);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_smp_wrap(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const enum p10_smp_wrap_mode i_wrap_mode)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_Type l_proc_id;
    bool l_smp_wrap_config;
    struct wrap_mode_def l_def;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, i_target, l_proc_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_ID)");

    FAPI_TRY(p10_smp_wrap_mfg_mode(l_smp_wrap_config),
             "Error from p10_smp_wrap_mfg_mode");

    FAPI_ASSERT(l_smp_wrap_config == true,
                fapi2::P10_SMP_WRAP_MFG_FLAGS_ERR(),
                "Manufacturing flags must be set for smp wrap mode!");

    FAPI_ASSERT(l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE,
                fapi2::P10_SMP_WRAP_UNSUPPORTED_BROADCAST_MODE()
                .set_BROADCAST_MODE(l_broadcast_mode),
                "Unsupported broadcast mode with smp wrap!");

    switch(i_wrap_mode)
    {
        case MODEA:
            FAPI_DBG("Reconfiguring active links (Mode A)");
            l_def = MODEA_DEF;
            break;

        case MODEB:
            FAPI_DBG("Reconfiguring active links (Mode B)");
            l_def = MODEB_DEF;
            break;

        case MODEC:
            FAPI_DBG("Reconfiguring active links (Mode C)");
            l_def = MODEC_DEF;
            break;

        case MODEV:
            FAPI_DBG("Reconfiguring active links (Mode V)");
            l_def = MODEV_DEF;
            break;

        case MODEW:
            FAPI_DBG("Reconfiguring active links (Mode W)");
            l_def = MODEW_DEF;
            break;

        case MODEX:
            FAPI_DBG("Reconfiguring active links (Mode X)");
            l_def = MODEX_DEF;
            break;

        default:
            FAPI_DBG("Unknown mode! Skipping link reconfig");
            goto fapi_try_exit;
            break;
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, i_target, l_def.num_links[l_proc_id]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_LINKS_CNFG)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_def.link_en[l_proc_id]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
