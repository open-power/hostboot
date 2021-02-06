/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp.C $    */
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
///
/// @file p10_build_smp.C
/// @brief Perform fabric configuration (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_build_smp.H>
#include <p10_build_smp_fbc_ab.H>
#include <p10_fbc_utils.H>
#include <p10_smp_wrap.H>

#include <p10_scom_proc.H>
#include <p10_scom_pauc_5.H>
#include <p10_scom_pauc_6.H>
#include <p10_scom_pauc_9.H>
#include <p10_scom_pauc_d.H>
#include <p10_scom_iohs_2.H>
#include <p10_scom_iohs_6.H>
#include <p10_scom_iohs_9.H>
#include <p10_scom_eq.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
const uint8_t ENUM_PSAVE_WIDTH_DISABLED     = 0b000;
const uint8_t ENUM_PSAVE_WIDTH_QUARTER      = 0b001;
const uint8_t ENUM_PSAVE_WIDTH_HALF         = 0b010;
const uint8_t ENUM_PSAVE_WIDTH_FULL_QUARTER = 0b101;
const uint8_t ENUM_PSAVE_WIDTH_FULL_HALF    = 0b110;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Process single chip target into SMP chip data structure
///
/// @param[in] i_target                     Reference to processor chip target
/// @param[in] i_group_id                   Fabric group ID for this chip target
/// @param[in] i_chip_id                    Fabric chip ID for this chip target
/// @param[in] i_master_chip_sys_next       True if this chip should be designated
///                                         fabric system master post-reconfiguration
/// @param[in] i_first_chip_found_in_group  True if this chip is the first discovered
///                                         in its group (when processing HWP inputs)
/// @param[in] i_op                         Enumerated type representing SMP build phase
/// @param[in/out] io_smp_chip              Structure encapsulating single chip in SMP topology
///
/// @return fapi2::ReturnCode               FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_process_chip(
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_group_id,
    const uint8_t i_chip_id,
    const bool i_master_chip_sys_next,
    const bool i_first_chip_found_in_group,
    const p10_build_smp_operation i_op,
    p10_build_smp_chip& io_smp_chip)
{
    using namespace scomt::proc;

    FAPI_DBG("Start");

    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
    bool l_err = false;

    fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_Type l_sys_master_chip_attr;
    fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_Type l_group_master_chip_attr;
    fapi2::buffer<uint64_t> l_hp_mode1_curr;

    // display target information for this chip
    fapi2::toString(i_target, l_target_str, sizeof(l_target_str));
    FAPI_INF("Target: %s", l_target_str);

    // set target handle pointer
    io_smp_chip.target = &i_target;

    // set group/chip IDs
    io_smp_chip.group_id = i_group_id;
    io_smp_chip.chip_id = i_chip_id;

    // set group/system master CURR data structure fields from HW
    FAPI_TRY(GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(i_target, l_hp_mode1_curr),
             "Error from getScom (PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR)");

    io_smp_chip.master_chip_group_curr =
        GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(l_hp_mode1_curr);
    io_smp_chip.master_chip_sys_curr =
        GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(l_hp_mode1_curr);

    FAPI_DBG("   Master chip GRP CURR = %d", io_smp_chip.master_chip_group_curr);
    FAPI_DBG("   Master chip SYS CURR = %d", io_smp_chip.master_chip_sys_curr);

    // set system master NEXT designation from HWP platform input
    io_smp_chip.master_chip_sys_next = i_master_chip_sys_next;
    FAPI_DBG("   Master chip SYS NEXT = %d", io_smp_chip.master_chip_sys_next);

    // set group master NEXT designation based on phase
    if (i_op == SMP_ACTIVATE_PHASE1)
    {
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        bool l_smp_wrap_config;
        FAPI_TRY(p10_smp_wrap_mfg_mode(l_smp_wrap_config),
                 "Error from p10_smp_wrap_mfg_mode");

        // each chip should match the flush state of the fabric logic
        if ((!io_smp_chip.master_chip_sys_curr || io_smp_chip.master_chip_group_curr)
            && (!l_smp_wrap_config))
        {
            FAPI_DBG("Error: chip does not match flush state of fabric: sys_curr: %d, grp_curr: %d",
                     io_smp_chip.master_chip_sys_curr ? 1 : 0, io_smp_chip.master_chip_group_curr ? 1 : 0);
            l_err = true;
        }
        else
        {
            // designate first chip found in each group as group master after reconfiguration
            io_smp_chip.master_chip_group_next = i_first_chip_found_in_group;
        }
    }
    else
    {
        // maintain current group master status after reconfiguration
        io_smp_chip.master_chip_group_next = io_smp_chip.master_chip_group_curr;
    }

    // set issue quiesce NEXT flag
    if (io_smp_chip.master_chip_sys_next)
    {
        // this chip will not be quiesced, to enable switch AB
        io_smp_chip.issue_quiesce_next = false;

        // in both activation scenarios, we expect that
        // the newly designated master is currently configured
        // as a master within the scope of its current enclosing fabric
        if (!io_smp_chip.master_chip_sys_curr)
        {
            FAPI_DBG("Error: newly designated master is not currently a master");
            l_err = true;
        }
    }
    else
    {
        if (io_smp_chip.master_chip_sys_curr)
        {
            // this chip will not be the new master, but is one now
            // use it to quiesce all chips in its fabric
            io_smp_chip.issue_quiesce_next = true;
        }
        else
        {
            io_smp_chip.issue_quiesce_next = false;
        }
    }

    FAPI_DBG("   Issue quiesce NEXT = %d", io_smp_chip.issue_quiesce_next);

    // default remaining NEXT state data structure fields
    io_smp_chip.quiesced_next = false;
    FAPI_DBG("   Quiesced NEXT = %d", io_smp_chip.quiesced_next);

    // assert if local error is set
    FAPI_ASSERT(l_err == false,
                fapi2::P10_BUILD_SMP_MASTER_DESIGNATION_ERR()
                .set_TARGET(i_target)
                .set_OP(i_op)
                .set_GROUP_ID(io_smp_chip.group_id)
                .set_CHIP_ID(io_smp_chip.chip_id)
                .set_MASTER_CHIP_SYS_CURR(io_smp_chip.master_chip_sys_curr)
                .set_MASTER_CHIP_GROUP_CURR(io_smp_chip.master_chip_group_curr)
                .set_MASTER_CHIP_SYS_NEXT(io_smp_chip.master_chip_sys_next)
                .set_MASTER_CHIP_GROUP_NEXT(io_smp_chip.master_chip_group_next),
                "Fabric group/system master designation error");

    // write attributes for initfile consumption
    l_sys_master_chip_attr = (io_smp_chip.master_chip_sys_next) ?
                             (fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE) :
                             (fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP, i_target, l_sys_master_chip_attr),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP)");

    l_group_master_chip_attr = (io_smp_chip.master_chip_group_next) ?
                               (fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE) :
                               (fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP, i_target, l_group_master_chip_attr),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_GROUP_MASTER_CHIP)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Insert chip structure into proper position within SMP strucure based
///        on its fabric group/chip IDs
///
/// @param[in] i_target                 Reference to processor chip target
/// @param[in] i_master_chip_sys_next   Flag designating this chip should be designated fabric
///                                     system master post-reconfiguration. Note: This chip must
///                                     currently be designated a master in its enclosing fabric
///                                         - PHASE1/HB: any chip
///                                         - PHASE2/FSP: any current drawer master
/// @param[in] i_op                     Enumerated type representing SMP build phase (HB or FSP)
/// @param[in/out] io_smp               Fully specified structure encapsulating SMP
/// @param[out] o_group_id              Group which chip belongs to
///
/// @return fapi2::ReturnCode           FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_insert_chip(
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_master_chip_sys_next,
    const p10_build_smp_operation i_op,
    p10_build_smp_system& io_smp,
    uint8_t& o_group_id)
{
    FAPI_DBG("Start");

    p10_build_smp_chip l_smp_chip;
    bool l_first_chip_found_in_group = false;
    std::map<uint8_t, p10_build_smp_group>::iterator g_iter;
    std::map<uint8_t, p10_build_smp_chip>::iterator p_iter;
    uint8_t l_group_id;
    uint8_t l_chip_id;

    // get fabric group/chip ID
    FAPI_TRY(p10_fbc_utils_get_topology_id(i_target, l_group_id, l_chip_id),
             "Error from p10_fbc_utils_get_topology_id");

    // search to see if group structure already exists for the group this chip resides in
    g_iter = io_smp.groups.find(l_group_id);

    // if no matching groups found, create one
    if (g_iter == io_smp.groups.end())
    {
        FAPI_DBG("No matching group found, inserting new group structure");

        // insert new group into SMP structure
        p10_build_smp_group l_smp_group;
        l_smp_group.group_id = l_group_id;
        auto l_ret = io_smp.groups.insert(std::pair<uint8_t, p10_build_smp_group>(l_group_id, l_smp_group));
        g_iter = l_ret.first;

        FAPI_ASSERT(l_ret.second,
                    fapi2::P10_BUILD_SMP_GROUP_ADD_INTERNAL_ERR()
                    .set_TARGET(i_target)
                    .set_GROUP_ID(l_group_id),
                    "Error encountered adding group to SMP");

        // mark as first chip found in its group
        l_first_chip_found_in_group = true;
    }

    // ensure that no chip has already been inserted into this group
    // with the same chip ID as this chip
    p_iter = io_smp.groups[l_group_id].chips.find(l_chip_id);

    // matching chip ID & group ID already found, flag an error
    FAPI_ASSERT(p_iter == io_smp.groups[l_group_id].chips.end(),
                fapi2::P10_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR()
                .set_TARGET1(i_target)
                .set_TARGET2(*(p_iter->second.target))
                .set_GROUP_ID(l_group_id)
                .set_CHIP_ID(l_chip_id),
                "Multiple chips found with the same fabric group ID / chip ID attribute values");

    // process/fill chip data structure
    FAPI_TRY(p10_build_smp_process_chip(
                 i_target,
                 l_group_id,
                 l_chip_id,
                 i_master_chip_sys_next,
                 l_first_chip_found_in_group,
                 i_op,
                 l_smp_chip),
             "Error from p10_build_smp_process_chip");

    // insert chip into SMP structure
    FAPI_INF("Inserting g%d:p%d", l_group_id, l_chip_id);
    io_smp.groups[l_group_id].chips[l_chip_id] = l_smp_chip;

    // return group ID
    o_group_id = l_group_id;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Insert HWP inputs and build SMP data structure
///
/// @param[in] i_chips                  Vector of processor chip targets to be included in SMP
/// @param[in] i_master_chip_sys_next   Target designating chip which should be designated fabric
///                                     system master post-reconfiguration. Note: This chip must
///                                     currently be designated a master in its enclosing fabric
///                                          - PHASE1/HB: any chip
///                                          - PHASE2/FSP: any current drawer master
/// @param[in] i_op                     Enumerated type representing SMP build phase (HB or FSP)
/// @param[in] io_smp                   Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode           FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_insert_chips(
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_chips,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_master_chip_sys_next,
    const p10_build_smp_operation i_op,
    p10_build_smp_system& io_smp)
{
    FAPI_DBG("Start");

    // loop over input processor chips
    bool l_master_chip_sys_next_found = false;
    uint8_t l_master_chip_next_group_id = 0;

    for (auto l_iter = i_chips.begin(); l_iter != i_chips.end(); l_iter++)
    {
        bool l_master_chip_sys_next = ((*l_iter) == i_master_chip_sys_next);
        uint8_t l_group_id;

        if (l_master_chip_sys_next)
        {
            // ensure that we haven't already designated one
            FAPI_ASSERT(!l_master_chip_sys_next_found,
                        fapi2::P10_BUILD_SMP_MULTIPLE_MASTER_DESIGNATION_ERR()
                        .set_MASTER_CHIP_SYS_NEXT_TARGET(i_master_chip_sys_next)
                        .set_OP(i_op),
                        "Muliple chips found in input vector which match target designated as master");
            l_master_chip_sys_next_found = true;
        }

        FAPI_TRY(p10_build_smp_insert_chip(
                     *l_iter,
                     l_master_chip_sys_next,
                     i_op,
                     io_smp,
                     l_group_id),
                 "Error from p10_build_smp_insert_chip");

        if (l_master_chip_sys_next)
        {
            l_master_chip_next_group_id = l_group_id;
        }
    }

    // ensure that new system master was designated
    FAPI_ASSERT(l_master_chip_sys_next_found,
                fapi2::P10_BUILD_SMP_NO_MASTER_DESIGNATION_ERR()
                .set_MASTER_CHIP_SYS_NEXT_TARGET(i_master_chip_sys_next)
                .set_OP(i_op),
                "No chips found in input vector which match target designated as master");

    // check that SMP size does not exceed maximum number of chips supported
    FAPI_ASSERT(i_chips.size() <= P10_BUILD_SMP_MAX_SIZE,
                fapi2::P10_BUILD_SMP_MAX_SIZE_ERR()
                .set_SIZE(i_chips.size())
                .set_MAX_SIZE(P10_BUILD_SMP_MAX_SIZE)
                .set_OP(i_op),
                "Number of chips found in input vector exceeds supported SMP size");

    // based on master designation and operation phase, determine whether
    // each chip will be quiesced as a result of hotplug switch activity
    for (auto g_iter = io_smp.groups.begin(); g_iter != io_smp.groups.end(); g_iter++)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            if (((i_op == SMP_ACTIVATE_PHASE1) && (p_iter->second.issue_quiesce_next)) ||
                ((i_op == SMP_ACTIVATE_PHASE2) && (g_iter->first != l_master_chip_next_group_id)))
            {
                p_iter->second.quiesced_next = true;
            }
            else
            {
                p_iter->second.quiesced_next = false;
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Check validity of link DL/TL logic
///
/// @param[in] i_iohs_target    Reference to IOHS target
/// @param[in] i_link_id        Chiplet number for given IOHS target
/// @param[in] i_link_en        Attribute value that defines active half-links for given IOHS
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_validate_link(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type i_link_id,
    const uint8_t i_link_en)
{
    using namespace scomt::proc;
    using namespace scomt::pauc;
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_fir_reg;
    fapi2::buffer<uint64_t> l_tl_fir_reg;
    fapi2::buffer<uint64_t> l_cplt_conf1_reg;
    bool l_dl_trained = false;
    bool l_tl_trained = false;
    bool l_iovalid_set = false;

    auto l_pauc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    // read DL training state
    FAPI_TRY(GET_DLP_FIR_REG_RW(i_iohs_target, l_dl_fir_reg),
             "Error from getScom (DLP_FIR_REG_RW)");
    // read TL training state
    FAPI_TRY(GET_PB_PTL_FIR_REG_RW(l_pauc_target, l_tl_fir_reg),
             "Error from getScom (PB_PTL_FIR_REG_RW)");

    // read iovalid state
    FAPI_TRY(GET_CPLT_CONF1_RW(l_pauc_target, l_cplt_conf1_reg),
             "Error from getScom (CPLT_CONF1_RW)");

    if (i_link_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE)
    {
        FAPI_TRY(PREP_DLP_FIR_REG_RW(i_iohs_target));
        l_dl_trained  = GET_DLP_FIR_REG_0_TRAINED(l_dl_fir_reg) &&
                        GET_DLP_FIR_REG_1_TRAINED(l_dl_fir_reg);

        FAPI_TRY(PREP_PB_PTL_FIR_REG_RW(l_pauc_target));
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg) && GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg) && GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg));

        FAPI_TRY(PREP_CPLT_CONF1_RW(l_pauc_target));
        l_iovalid_set = (i_link_id % 2) ?
                        (GET_CPLT_CONF1_3_IOVALID_DC(l_cplt_conf1_reg) && GET_CPLT_CONF1_2_IOVALID_DC(l_cplt_conf1_reg)) :
                        (GET_CPLT_CONF1_1_IOVALID_DC(l_cplt_conf1_reg) && GET_CPLT_CONF1_0_IOVALID_DC(l_cplt_conf1_reg));
    }
    else if (i_link_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY)
    {
        FAPI_TRY(PREP_DLP_FIR_REG_RW(i_iohs_target));
        l_dl_trained  = GET_DLP_FIR_REG_0_TRAINED(l_dl_fir_reg);

        FAPI_TRY(PREP_PB_PTL_FIR_REG_RW(l_pauc_target));
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg));

        FAPI_TRY(PREP_CPLT_CONF1_RW(l_pauc_target));
        l_iovalid_set = (i_link_id % 2) ?
                        (GET_CPLT_CONF1_3_IOVALID_DC(l_cplt_conf1_reg)) :
                        (GET_CPLT_CONF1_1_IOVALID_DC(l_cplt_conf1_reg));
    }
    else if (i_link_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY)
    {
        FAPI_TRY(PREP_DLP_FIR_REG_RW(i_iohs_target));
        l_dl_trained  = GET_DLP_FIR_REG_1_TRAINED(l_dl_fir_reg);

        FAPI_TRY(PREP_PB_PTL_FIR_REG_RW(l_pauc_target));
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg));

        FAPI_TRY(PREP_CPLT_CONF1_RW(l_pauc_target));
        l_iovalid_set = (i_link_id % 2) ?
                        (GET_CPLT_CONF1_2_IOVALID_DC(l_cplt_conf1_reg)) :
                        (GET_CPLT_CONF1_0_IOVALID_DC(l_cplt_conf1_reg));
    }

    // assert if not in expected state
    FAPI_ASSERT(l_dl_trained && l_tl_trained && l_iovalid_set,
                fapi2::P10_BUILD_SMP_INVALID_LINK_STATE()
                .set_TARGET(i_iohs_target)
                .set_LINK_EN(i_link_en)
                .set_DL_FIR_REG(l_dl_fir_reg)
                .set_TL_FIR_REG(l_tl_fir_reg)
                .set_CPLT_CONF1_REG(l_cplt_conf1_reg),
                "Link DL/TL/iovalid are not in expected state");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Verify that fabric topology is logically valid
///        - In a given group, all chips are connected to every other
///          chip in the group by an X bus (if pump mode = chip_is_node)
///        - Each chip is connected to its partner chip (with same chip id)
///          in every other group by an A bus or X bus (if pump mode = chip_is_group)
///
/// @param[in] i_op             Enumerated type representing SMP build phase (HB or FSP)
/// @param[in] i_smp            Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_check_topology(
    const p10_build_smp_operation i_op,
    p10_build_smp_system& i_smp)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::buffer<uint8_t> l_group_ids_in_system;
    fapi2::buffer<uint8_t> l_chip_ids_in_groups;

    // determine broadcast mode
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE");

    // build set of all valid group IDs in system
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        FAPI_INF("Adding g%d", g_iter->first);
        l_group_ids_in_system.setBit(g_iter->first);

        // build set of all valid chip IDs in group
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            FAPI_INF("Adding g%d:p%d", g_iter->first, p_iter->first);
            l_chip_ids_in_groups.setBit(p_iter->first);
        }
    }

    // iterate over all groups
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        // iterate over all chips in current group
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            FAPI_DBG("Checking connectivity for g%d:p%d", g_iter->first, p_iter->first);

            fapi2::buffer<uint8_t> l_connected_group_ids;
            fapi2::buffer<uint8_t> l_connected_chip_ids;
            bool intergroup_set_match = false;
            bool intragroup_set_match = false;

            fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_en;
            fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_en;
            fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_x_rem_chip_id;
            fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_a_rem_group_id;

            // add IDs associated with current chip, to make direct set comparison easy
            l_connected_group_ids.setBit(p_iter->second.group_id);
            l_connected_chip_ids.setBit(p_iter->second.chip_id);

            // process X/A links, mark reachable group/chip IDs
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, *(p_iter->second.target), l_x_en),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, *(p_iter->second.target), l_a_en),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, *(p_iter->second.target), l_x_rem_chip_id),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, *(p_iter->second.target), l_a_rem_group_id),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");

            for(auto l_iohs : (*(p_iter->second.target)).getChildren<fapi2::TARGET_TYPE_IOHS>())
            {
                fapi2::ATTR_CHIP_UNIT_POS_Type l_link_id;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs, l_link_id),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                if (l_x_en[l_link_id])
                {
                    FAPI_INF("Processing X link g%d:p%d:c%d", g_iter->first, p_iter->first, l_link_id);

                    FAPI_TRY(p10_build_smp_validate_link(l_iohs, l_link_id, l_x_en[l_link_id]),
                             "Error from p10_build_smp_validate_link (g%d:p%d:c%d)", g_iter->first, p_iter->first, l_link_id);

                    if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                    {
                        l_connected_group_ids.setBit(l_x_rem_chip_id[l_link_id]);
                    }
                    else
                    {
                        l_connected_chip_ids.setBit(l_x_rem_chip_id[l_link_id]);
                    }
                }

                if (l_a_en[l_link_id])
                {
                    FAPI_INF("Processing A link g%d:p%d:c%d", g_iter->first, p_iter->first, l_link_id);

                    FAPI_TRY(p10_build_smp_validate_link(l_iohs, l_link_id, l_a_en[l_link_id]),
                             "Error from p10_build_smp_validate_link (g%d:p%dc:%d)", g_iter->first, p_iter->first, l_link_id);

                    l_connected_group_ids.setBit(l_a_rem_group_id[l_link_id]);
                }
            }

            // compare ID sets, emit error if they don't match
            intergroup_set_match = (l_group_ids_in_system == l_connected_group_ids);
            intragroup_set_match = (l_chip_ids_in_groups == l_connected_chip_ids);

            if (!intergroup_set_match || !intragroup_set_match)
            {
                // display target information
                char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(*(p_iter->second.target), l_target_str, sizeof(l_target_str));

                if (!intragroup_set_match)
                {
                    FAPI_ERR("Target %s is not fully connected (X) to all other chips in its group", l_target_str);
                }

                if (!intergroup_set_match)
                {
                    FAPI_ERR("Target %s is not fully connected (X/A) to all other groups in the system", l_target_str);
                }

                FAPI_ASSERT(false,
                            fapi2::P10_BUILD_SMP_INVALID_TOPOLOGY()
                            .set_TARGET(*(p_iter->second.target))
                            .set_OP(i_op)
                            .set_GROUP_ID(p_iter->second.group_id)
                            .set_CHIP_ID(p_iter->second.chip_id)
                            .set_INTERGROUP_CONNECTIONS_OK(intergroup_set_match)
                            .set_CONNECTED_GROUP_IDS(l_connected_group_ids)
                            .set_GROUP_IDS_IN_SYSTEM(l_group_ids_in_system)
                            .set_INTRAGROUP_CONNECTIONS_OK(intragroup_set_match)
                            .set_CONNECTED_CHIP_IDS(l_connected_chip_ids)
                            .set_CHIP_IDS_IN_GROUPS(l_chip_ids_in_groups)
                            .set_FBC_BROADCAST_MODE(l_broadcast_mode),
                            "Invalid fabric topology detected");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Update link attributes for manufacturing smp wrap config
///        - Selects a valid link configuration for the first initial boot
///        - Skips any updates when cycling through the various mfg wrap modes
///
/// @param[in] i_smp            Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_mfg_config(
    p10_build_smp_system& i_smp)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    bool l_smp_wrap_config;
    FAPI_TRY(p10_smp_wrap_mfg_mode(l_smp_wrap_config),
             "Error from p10_smp_wrap_mfg_mode");

    if(l_smp_wrap_config)
    {
        fapi2::ATTR_IS_SIMULATION_Type l_sim_env;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_sim_env),
                 "Error from FAPI_ATTR_GET (ATTR_IS_SIMULATION)");

        for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
        {
            for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
            {
                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(p_iter->second.target);

                fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_num_links;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, l_target, l_num_links),
                         "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINKS_CNFG)");

                if(l_num_links > 3) // only three links can be active at a time in mfg mode
                {
                    FAPI_TRY(p10_smp_wrap(l_target, l_sim_env ? MODEV : MODEA),
                             "Error from p10_smp_wrap");
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Update topology ID tables to represent all chips
///
/// @param[in] i_smp            Fully specified structure encapsulating SMP
/// @param[in] i_op             Enumerated type representing SMP build phase (HB or FSP)
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_topo_tables(
    p10_build_smp_system& i_smp,
    const p10_build_smp_operation i_op)
{
    FAPI_DBG("Start");
    using namespace scomt::eq;

    // update topology ID table entry in attribute for each chip
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            FAPI_TRY(topo::init_topology_id_table(*(p_iter->second.target)),
                     "Error from topo::init_topology_id_table");
        }
    }

    // apply resulting attribute value to all unit registers on all chips
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            // ADU, NX, VAS, INT, NMMU
            // update on both build SMP calls
            FAPI_TRY(topo::set_topology_id_tables(*(p_iter->second.target)),
                     "Error from topo::set_topology_id_tables");

            // PCIE: HB drawer scoped values updated in p10_pcie_config (after first build SMP call)
            //       CEC scoped values can be updated here in second build SMP call
            if (i_op == SMP_ACTIVATE_PHASE2)
            {
                FAPI_TRY(topo::set_topology_id_tables_pec(*(p_iter->second.target)),
                         "Error from topo::set_topology_id_tables_pec");
            }

#ifdef __HOSTBOOT_MODULE
            // L2/L3/NCU: update only for Hostboot execution
            {
                // build set of cores to update depending on build SMP call
                std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>> l_cores_to_update;

                for (const auto& c : (*(p_iter->second.target)).getChildren<fapi2::TARGET_TYPE_CORE>())
                {
                    fapi2::ATTR_CHIP_UNIT_POS_Type l_attr_chip_unit_pos;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, c, l_attr_chip_unit_pos));

                    if ((i_op == SMP_ACTIVATE_PHASE1) &&
                        (p_iter->second.master_chip_group_next))
                    {
                        // limit update to set of active cores/backing caches on primary chip, which
                        // should all be accessible... active/backing attributes do not currently get pushed
                        // up from SBE -> HB so we need to determine empirically from HW
                        // (code here looks at EQ clock region state)
                        fapi2::Target<fapi2::TARGET_TYPE_EQ> l_eq = c.getParent<fapi2::TARGET_TYPE_EQ>();
                        fapi2::buffer<uint64_t> l_eq_clock_status;
                        FAPI_TRY(fapi2::getScom(l_eq, CLOCK_STAT_SL, l_eq_clock_status));

                        // unit5 = l30
                        // unit6 = l31
                        // unit7 = l32
                        // unit8 = l33
                        // value of 0b0 indicates clocks are running
                        if (!l_eq_clock_status.getBit(CLOCK_STAT_SL_UNIT5_SL + (l_attr_chip_unit_pos % 4)))
                        {
                            l_cores_to_update.push_back(c);
                        }
                    }
                    else if (i_op == SMP_ACTIVATE_PHASE2)
                    {
                        // update all cores
                        l_cores_to_update.push_back(c);
                    }
                }

                // perform live update via SCOM
                for (const auto& c : l_cores_to_update)
                {
                    FAPI_TRY(topo::set_topology_id_tables_cache(c),
                             "Error from topo::set_topology_id_tables_cache");
                }
            }
#endif
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Update link topology ID tables to represent all connections
///
/// @param[in] i_smp            Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_link_topo_tables(
    p10_build_smp_system& i_smp)
{
    FAPI_DBG("Start");

    // build set of all valid group/chip IDs in system
    fapi2::buffer<uint32_t> l_topo_ids_in_system;

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(p_iter->second.target);
            uint8_t l_topo_index = 0;

            // index into topology table is by the 5-bit topology id of processor
            FAPI_TRY(topo::get_topology_idx(l_target, EFF_TOPOLOGY_ID, l_topo_index),
                     "Error from topo::get_topology_idx (remote target)");

            FAPI_INF("Adding topology index %d", l_topo_index);
            l_topo_ids_in_system.setBit(l_topo_index);
        }
    }

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_loc_target = *(p_iter->second.target);
            fapi2::ATTR_PROC_FABRIC_LINK_TOPOLOGY_ID_TABLE_Type l_topo_id_table;
            fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_cnfg;
            fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_cnfg;
            fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_x_addr_dis;
            fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_a_addr_dis;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_TOPOLOGY_ID_TABLE, l_loc_target, l_topo_id_table),
                     "Error form FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_TOPOLOGY_ID_TABLE)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, l_loc_target, l_x_cnfg),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, l_loc_target, l_a_cnfg),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, l_loc_target, l_x_addr_dis),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ADDR_DIS)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, l_loc_target, l_a_addr_dis),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ADDR_DIS)");

            for(auto l_loc_iohs_target : l_loc_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
            {
                fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_iohs_target;
                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_target;
                uint8_t l_topo_index = 0;

                fapi2::ATTR_CHIP_UNIT_POS_Type l_loc_link_id;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_loc_iohs_target, l_loc_link_id),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_DBG("Working on link %d\n", l_loc_link_id);

                bool l_link_en = (l_x_cnfg[l_loc_link_id] != fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE) ?
                                 (l_x_cnfg[l_loc_link_id] != fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE) :
                                 (l_a_cnfg[l_loc_link_id] != fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
                bool l_addr_en = (l_x_cnfg[l_loc_link_id] != fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE) ?
                                 (l_x_addr_dis[l_loc_link_id] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_OFF) :
                                 (l_a_addr_dis[l_loc_link_id] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_OFF);

                if(l_link_en && l_addr_en)
                {
                    l_loc_iohs_target.getOtherEnd(l_rem_iohs_target);
                    l_rem_target = l_rem_iohs_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

                    // index into topology table is by the 5-bit topology id of remote chip
                    FAPI_TRY(topo::get_topology_idx(l_rem_target, EFF_TOPOLOGY_ID, l_topo_index),
                             "Error from topo::get_topology_idx (remote target)");

                    if(l_x_cnfg[l_loc_link_id] != fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                    {
                        // program the link id used to get from this chip to remote chip for xlinks
                        FAPI_DBG("Set LINK_TOPOLOGY_ID_TABLE[%d]=%d\n", l_topo_index, l_loc_link_id);
                        l_topo_id_table[l_topo_index] = l_loc_link_id;
                    }
                    else
                    {
                        // program all indexes for valid remote groups for alinks
                        for(uint8_t l_index = 0; l_index < P10_FBC_UTILS_MAX_TOPO_ENTRIES; l_index++)
                        {
                            if(l_topo_ids_in_system.getBit(l_index) && ((l_index & 0x1C) == (l_topo_index & 0x1C)))
                            {
                                FAPI_DBG("Set LINK_TOPOLOGY_ID_TABLE[%d]=%d\n", l_index, l_loc_link_id);
                                l_topo_id_table[l_index] = l_loc_link_id;
                            }
                        }
                    }
                }
                else
                {
                    // link is not enabled for fabric command operations, we don't know the remote chip id
                    // so invalidate any entries in the topology table that references this link
                    for(uint8_t l_topo_index = 0; l_topo_index < (sizeof(l_topo_id_table) / sizeof(l_topo_id_table[0])); l_topo_index++)
                    {
                        if(l_topo_id_table[l_topo_index] == l_loc_link_id)
                        {
                            l_topo_id_table[l_topo_index] = fapi2::ENUM_ATTR_PROC_FABRIC_LINK_TOPOLOGY_ID_TABLE_INVALID;
                        }
                    }
                }
            }

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_LINK_TOPOLOGY_ID_TABLE, l_loc_target, l_topo_id_table),
                     "Error form FAPI_ATTR_SET (ATTR_PROC_FABRIC_LINK_TOPOLOGY_ID_TABLE)");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Disable dynamic lane reduction (dlr) on all links
///
/// @param[in] i_smp            Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_dlr_disable(
    p10_build_smp_system& i_smp)
{
    FAPI_DBG("Start");

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(p_iter->second.target);

            fapi2::ATTR_CHIP_EC_FEATURE_HW529136_Type l_hw529136;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW529136, l_target, l_hw529136),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW529136)");

            if(l_hw529136)
            {
                for (auto l_pauc : l_target.getChildren<fapi2::TARGET_TYPE_PAUC>())
                {
                    using namespace scomt::pauc;

                    fapi2::buffer<uint64_t> l_psave_mode_cfg;

                    fapi2::ATTR_CHIP_UNIT_POS_Type l_pauc_id;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pauc, l_pauc_id),
                             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                    FAPI_TRY(GET_PB_PSAVE01_MODE_CFG(l_pauc, l_psave_mode_cfg),
                             "Error from getScom (PB_PSAVE01_MODE_CFG)");
                    SET_PB_PSAVE01_MODE_CFG_WIDTH(ENUM_PSAVE_WIDTH_DISABLED, l_psave_mode_cfg);
                    FAPI_TRY(PUT_PB_PSAVE01_MODE_CFG(l_pauc, l_psave_mode_cfg),
                             "Error from putScom (PB_PSAVE01_MODE_CFG)");

                    FAPI_TRY(GET_PB_PSAVE23_MODE_CFG(l_pauc, l_psave_mode_cfg),
                             "Error from getScom (PB_PSAVE23_MODE_CFG)");
                    SET_PB_PSAVE23_MODE_CFG_WIDTH(ENUM_PSAVE_WIDTH_DISABLED, l_psave_mode_cfg);
                    FAPI_TRY(PUT_PB_PSAVE23_MODE_CFG(l_pauc, l_psave_mode_cfg),
                             "Error from putScom (PB_PSAVE23_MODE_CFG)");
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Enable dynamic lane reduction (dlr) on selected links
///
/// @param[in] i_smp            Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_dlr_enable(
    p10_build_smp_system& i_smp)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_FABRIC_DLR_PSAVE_MODE_Type l_dlr_mode;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_DLR_PSAVE_MODE, FAPI_SYSTEM, l_dlr_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_DLR_PSAVE_MODE)");

    if(l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_DISABLED)
    {
        FAPI_DBG("Selected dlr psave mode is DISABLED, skipping dlr enablement");
        goto fapi_try_exit;
    }

    FAPI_DBG("Selected dlr psave mode: 0x%x\n", l_dlr_mode);

    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); g_iter++)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); p_iter++)
        {
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = *(p_iter->second.target);

            for (auto l_loc_iohs : l_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
            {
                char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_loc_iohs, l_targetStr, sizeof(l_targetStr));

                fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fbc_link_active;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_loc_iohs, l_fbc_link_active),
                         "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

                if(l_fbc_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE)
                {
                    using namespace scomt::pauc;

                    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_loc_pauc;
                    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_rem_pauc;
                    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_iohs;
                    fapi2::ATTR_CHIP_UNIT_POS_Type l_loc_iohs_id;
                    fapi2::ATTR_CHIP_UNIT_POS_Type l_rem_iohs_id;
                    fapi2::ATTR_CHIP_EC_FEATURE_HW522788_Type l_hw522788;
                    fapi2::buffer<uint64_t> l_psave_mode_cfg;
                    uint64_t l_psave_width = 0;
                    fapi2::ReturnCode l_rc;

                    // Verify that the link width and psave mode selected are valid
                    // combinations to enable; full-width links can support any psave
                    // mode, but half-width links can only support half psave modes

                    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_loc_iohs, l_link_train),
                             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

                    bool l_half_link = ((l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)
                                        || (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY));

                    bool l_psave_qtr = ((l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_QUARTER)
                                        || (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_FULL_QUARTER));

                    if(l_half_link && l_psave_qtr)
                    {
                        FAPI_DBG("%s Skipping dlr enable: quarter-width psave on half links is unsupported", l_targetStr);
                        continue;
                    }

                    // Only one end of the link connection should have psave enabled, the
                    // remote end should have psave_width = disabled; determine the
                    // psave state on the remote end before programming the psave mode
                    // on the local end of the link

                    l_rc = l_loc_iohs.getOtherEnd(l_rem_iohs);

                    FAPI_ASSERT(!l_rc,
                                fapi2::P10_BUILD_SMP_DLR_REM_ENDP_TARGET_ERR()
                                .set_LOC_ENDP_TARGET(l_loc_iohs),
                                "Unable to detect remote end of the link");

                    l_rem_pauc = l_rem_iohs.getParent<fapi2::TARGET_TYPE_PAUC>();

                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_rem_iohs, l_rem_iohs_id),
                             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                    if((l_rem_iohs_id % 2) == 0)
                    {
                        FAPI_TRY(GET_PB_PSAVE01_MODE_CFG(l_rem_pauc, l_psave_mode_cfg),
                                 "Error from getScom (PB_PSAVE01_MODE_CFG)");
                        GET_PB_PSAVE01_MODE_CFG_WIDTH(l_psave_mode_cfg, l_psave_width);
                    }
                    else
                    {
                        FAPI_TRY(GET_PB_PSAVE23_MODE_CFG(l_rem_pauc, l_psave_mode_cfg),
                                 "Error from getScom (PB_PSAVE23_MODE_CFG)");
                        GET_PB_PSAVE23_MODE_CFG_WIDTH(l_psave_mode_cfg, l_psave_width);
                    }

                    if(l_psave_width != ENUM_PSAVE_WIDTH_DISABLED)
                    {
                        FAPI_DBG("%s Skipping dlr enable: psave on remote link endpoint already enabled", l_targetStr);
                        continue;
                    }

                    // Remote link endpoint has psave_width = disabled, continue to
                    // program the psave mode for the local link endpoint

                    FAPI_DBG("%s Setting dlr enable: l_fbc_link_active = %d, l_link_train = %d",
                             l_targetStr, l_fbc_link_active, l_link_train);

                    switch(l_dlr_mode)
                    {
                        case fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_QUARTER:
                            l_psave_width = ENUM_PSAVE_WIDTH_QUARTER;
                            break;

                        case fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_HALF:
                            l_psave_width = ENUM_PSAVE_WIDTH_HALF;
                            break;

                        case fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_FULL_QUARTER:
                            l_psave_width = ENUM_PSAVE_WIDTH_FULL_QUARTER;
                            break;

                        case fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_FULL_HALF:
                            l_psave_width = ENUM_PSAVE_WIDTH_FULL_HALF;
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::P10_BUILD_SMP_DLR_INVALID_MODE()
                                        .set_DLR_MODE(l_dlr_mode),
                                        "Invalid dlr mode selected for configuration");
                            break;
                    }

                    l_loc_pauc = l_loc_iohs.getParent<fapi2::TARGET_TYPE_PAUC>();

                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_loc_iohs, l_loc_iohs_id),
                             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                    if((l_loc_iohs_id % 2) == 0)
                    {
                        FAPI_TRY(GET_PB_PSAVE01_MODE_CFG(l_loc_pauc, l_psave_mode_cfg),
                                 "Error from getScom (PB_PSAVE01_MODE_CFG)");
                        SET_PB_PSAVE01_MODE_CFG_WIDTH(l_psave_width, l_psave_mode_cfg);
                        FAPI_TRY(PUT_PB_PSAVE01_MODE_CFG(l_loc_pauc, l_psave_mode_cfg),
                                 "Error from putScom (PB_PSAVE01_MODE_CFG)");
                    }
                    else
                    {
                        FAPI_TRY(GET_PB_PSAVE23_MODE_CFG(l_loc_pauc, l_psave_mode_cfg),
                                 "Error from getScom (PB_PSAVE23_MODE_CFG)");
                        SET_PB_PSAVE23_MODE_CFG_WIDTH(l_psave_width, l_psave_mode_cfg);
                        FAPI_TRY(PUT_PB_PSAVE23_MODE_CFG(l_loc_pauc, l_psave_mode_cfg),
                                 "Error from putScom (PB_PSAVE23_MODE_CFG)");
                    }

                    // HW522788 Checkstop on link retrain or high error rates if dlr is enabled for DD1
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW522788, l_target, l_hw522788),
                             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW522788)");

                    if(l_hw522788)
                    {
                        using namespace scomt::iohs;

                        fapi2::buffer<uint64_t> l_dlp_fir_data;
                        fapi2::buffer<uint64_t> l_clear_data;

                        bool l_evn_en = ((l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
                                         || (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY));
                        bool l_odd_en = ((l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
                                         || (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY));

                        FAPI_TRY(PREP_DLP_FIR_REG_RW(l_loc_iohs));
                        l_clear_data.flush<1>();

                        if(l_evn_en)
                        {
                            CLEAR_DLP_FIR_REG_0_RETRAIN_THRESHOLD(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_INVALID_BLOCK(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_DESKEW_ERROR(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_DESKEW_OVERFLOW(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_SW_RETRAIN(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_NUM_REPLAY(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_SPARE_DONE(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_TRAINING_FAILED(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(l_clear_data);
                            CLEAR_DLP_FIR_REG_0_INTERNAL_ERROR(l_clear_data);
                        }

                        if(l_odd_en)
                        {
                            CLEAR_DLP_FIR_REG_1_RETRAIN_THRESHOLD(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_INVALID_BLOCK(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_DESKEW_ERROR(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_DESKEW_OVERFLOW(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_SW_RETRAIN(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_NUM_REPLAY(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_SPARE_DONE(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_TRAINING_FAILED(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(l_clear_data);
                            CLEAR_DLP_FIR_REG_1_INTERNAL_ERROR(l_clear_data);
                        }

                        FAPI_TRY(GET_DLP_FIR_MASK_REG_RW(l_loc_iohs, l_dlp_fir_data),
                                 "Error from getScom (DLP_FIR_MASK_REG_RW)");
                        FAPI_TRY(PUT_DLP_FIR_MASK_REG_RW(l_loc_iohs, l_dlp_fir_data & l_clear_data),
                                 "Error from putScom (DLP_FIR_MASK_REG_RW)");
                        FAPI_TRY(GET_DLP_FIR_ACTION0_REG(l_loc_iohs, l_dlp_fir_data),
                                 "Error from getScom (DLP_FIR_ACTION0_REG)");
                        FAPI_TRY(PUT_DLP_FIR_ACTION0_REG(l_loc_iohs, l_dlp_fir_data & l_clear_data),
                                 "Error from putScom (DLP_FIR_ACTION0_REG)");
                        FAPI_TRY(GET_DLP_FIR_ACTION1_REG(l_loc_iohs, l_dlp_fir_data),
                                 "Error from getScom (DLP_FIR_ACTION1_REG)");
                        FAPI_TRY(PUT_DLP_FIR_ACTION1_REG(l_loc_iohs, l_dlp_fir_data & l_clear_data),
                                 "Error from putScom (DLP_FIR_ACTION1_REG)");

                        FAPI_TRY(GET_DLP_FIR_MASK_REG_RW(l_rem_iohs, l_dlp_fir_data),
                                 "Error from getScom (DLP_FIR_MASK_REG_RW)");
                        FAPI_TRY(PUT_DLP_FIR_MASK_REG_RW(l_rem_iohs, l_dlp_fir_data & l_clear_data),
                                 "Error from putScom (DLP_FIR_MASK_REG_RW)");
                        FAPI_TRY(GET_DLP_FIR_ACTION0_REG(l_rem_iohs, l_dlp_fir_data),
                                 "Error from getScom (DLP_FIR_ACTION0_REG)");
                        FAPI_TRY(PUT_DLP_FIR_ACTION0_REG(l_rem_iohs, l_dlp_fir_data & l_clear_data),
                                 "Error from putScom (DLP_FIR_ACTION0_REG)");
                        FAPI_TRY(GET_DLP_FIR_ACTION1_REG(l_rem_iohs, l_dlp_fir_data),
                                 "Error from getScom (DLP_FIR_ACTION1_REG)");
                        FAPI_TRY(PUT_DLP_FIR_ACTION1_REG(l_rem_iohs, l_dlp_fir_data & l_clear_data),
                                 "Error from putScom (DLP_FIR_ACTION1_REG)");
                    }
                }
                else
                {
                    FAPI_DBG("%s Skipping dlr enable: l_fbc_link_active = %d",
                             l_targetStr, l_fbc_link_active);
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_build_smp(
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_chips,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_master_chip_sys_next,
    const p10_build_smp_operation i_op)
{
    FAPI_DBG("Start");

    p10_build_smp_system l_smp;

    // process HWP input vector of chips
    FAPI_TRY(p10_build_smp_insert_chips(i_chips, i_master_chip_sys_next, i_op, l_smp),
             "Error from p10_build_smp_insert_chips");

    // update link attrs for manufacturing smp wrap config
    FAPI_TRY(p10_build_smp_mfg_config(l_smp),
             "Error from p10_build_smp_mfg_config");

    // check topology before continuing
    FAPI_TRY(p10_build_smp_check_topology(i_op, l_smp),
             "Error from p10_build_smp_check_topology");

    // update topology id tables prior to activating new config
    FAPI_TRY(p10_build_smp_topo_tables(l_smp, i_op),
             "Error from p10_build_smp_topo_tables");

    // update link topology id tables prior to activating new config
    FAPI_TRY(p10_build_smp_link_topo_tables(l_smp),
             "Error from p10_build_smp_topo_tables");

    // disable dlr prior to activating new config
    FAPI_TRY(p10_build_smp_dlr_disable(l_smp),
             "Error from p10_build_smp_dlr_disable");

    // set fabric hotplug configuration registers (switch AB)
    // activates new SMP configuration for given phase1/phase2
    FAPI_TRY(p10_build_smp_set_fbc_ab(l_smp, i_op),
             "Error from p10_build_smp_set_fbc_ab");

    // enable dlr after activating new config
    FAPI_TRY(p10_build_smp_dlr_enable(l_smp),
             "Error from p10_build_smp_dlr_enable");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
