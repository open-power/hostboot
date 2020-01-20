/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp.C $    */
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

#include <p10_scom_proc.H>
#include <p10_scom_pauc_6.H>
#include <p10_scom_pauc_d.H>
#include <p10_scom_iohs_6.H>

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
        // each chip should match the flush state of the fabric logic
        if (!io_smp_chip.master_chip_sys_curr ||
            io_smp_chip.master_chip_group_curr)
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
        l_dl_trained  = GET_DLP_FIR_REG_LINK0_TRAINED(l_dl_fir_reg) &&
                        GET_DLP_FIR_REG_LINK1_TRAINED(l_dl_fir_reg);
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg) && GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg) && GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg));
        l_iovalid_set = (i_link_id % 2) ?
                        (GET_CPLT_CONF1_3_IOVALID_DC(l_cplt_conf1_reg) && GET_CPLT_CONF1_2_IOVALID_DC(l_cplt_conf1_reg)) :
                        (GET_CPLT_CONF1_1_IOVALID_DC(l_cplt_conf1_reg) && GET_CPLT_CONF1_0_IOVALID_DC(l_cplt_conf1_reg));
    }
    else if (i_link_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY)
    {
        l_dl_trained  = GET_DLP_FIR_REG_LINK0_TRAINED(l_dl_fir_reg);
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg));
        l_iovalid_set = (i_link_id % 2) ?
                        (GET_CPLT_CONF1_3_IOVALID_DC(l_cplt_conf1_reg)) :
                        (GET_CPLT_CONF1_1_IOVALID_DC(l_cplt_conf1_reg));
    }
    else if (i_link_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY)
    {
        l_dl_trained  = GET_DLP_FIR_REG_LINK1_TRAINED(l_dl_fir_reg);
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg));
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
/// @brief Update topology ID tables to represent all chips
///
/// @param[in] i_smp            Fully specified structure encapsulating SMP
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_topo_tables(
    p10_build_smp_system& i_smp)
{
    FAPI_DBG("Start");

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
            FAPI_TRY(topo::set_topology_id_tables(*(p_iter->second.target)),
                     "Error from topo::set_topology_id_tables");
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

    // check topology before continuing
    FAPI_TRY(p10_build_smp_check_topology(i_op, l_smp),
             "Error from p10_build_smp_check_topology");

    // update topology id tables prior to activating new config
    FAPI_TRY(p10_build_smp_topo_tables(l_smp),
             "Error from p10_build_smp_topo_tables");

    // set fabric hotplug configuration registers (switch AB)
    // activates new SMP configuration for given phase1/phase2
    FAPI_TRY(p10_build_smp_set_fbc_ab(l_smp, i_op),
             "Error from p10_build_smp_set_fbc_ab");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
