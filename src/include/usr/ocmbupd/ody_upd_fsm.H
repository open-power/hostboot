/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ocmbupd/ody_upd_fsm.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

/** @file ody_upd_fsm.H
 *
 *  @brief Defines the Odyssey code update FSM interface.
 */

#include <attributeenums.H>
#include <targeting/common/target.H>
#include <ocmbupd/ocmbupd.H>
#include <targeting/odyutil.H>

namespace ocmbupd
{

/** @brief A list of code update-related events that can occur for an OCMB. These
 *  are bit elements that can be OR'd together to form a bit set.
 */
enum ody_upd_event_t : uint32_t
{
    CHECK_FOR_READY_COMPLETED = 1 << 0,
    UPDATE_OMI_FIRMWARE_REACHED = 1 << 9,

    OCMB_BOOT_ERROR_NO_FFDC = 1 << 1,
    OCMB_BOOT_ERROR_WITH_FFDC = 1 << 2,
    OCMB_HWP_FAIL_HASH_FAIL = 1 << 3,
    OCMB_HWP_FAIL_OTHER = 1 << 4,

    ATTRS_INCOMPATIBLE = 1 << 5,

    CODE_UPDATE_CHIPOP_FAILURE = 1 << 6,
    IMAGE_SYNC_CHIPOP_FAILURE = 1 << 7,
    MEAS_REGS_MISMATCH = 1 << 8,

    IPL_COMPLETE = 1 << 10,

    NO_EVENT = 0,
    ANY_EVENT = 0xFFFFFFFF
};

/** @brief Process an event on the given OCMB. If an error log is
 *  related to the event, it is passed in as well, and this function
 *  takes ownership of it.
 *
 *  @param[in] i_ocmb             The OCMB for which the event is happening.
 *  @param[in] i_event            The event that is occurring.
 *  @param[in] i_errlog           Any error log associated with the event.
 *  @param[in] i_ocmbfw_pnor_partition  Owning handle to the OCMBFW PNOR partition.
 *  @param[out] o_restart_needed  Set by this function to tell the caller that the
 *                                OCMB needs to go through the check_for_ready
 *                                cycle again. The caller can determine whether the
 *                                IPL has advanced to a point where a full reboot
 *                                is required, or whether it can just perform a
 *                                CFAM reset without a reboot.
 *
 *  @note o_restart_needed is NEVER set to false by this function. It
 *  may be switched from false to true, but never vice versa.
 */
errlHndl_t ody_upd_process_event(TARGETING::Target* i_ocmb,
                                 const ody_upd_event_t i_event,
                                 errlHndl_t& i_errlog,
                                 const ocmbfw_owning_ptr_t& i_ocmbfw_pnor_partition,
                                 bool& o_restart_needed);

/** @brief Parameter type to ody_upd_all_process_event. */
enum perform_reconfig_t
{
    REQUEST_RECONFIG_IF_NEEDED,
    DO_NOT_REQUEST_RECONFIG
};

/** @brief Parameter type to ody_upd_all_process_event. */
enum functional_ocmbs_only_t
{
    EVENT_ON_FUNCTIONAL_OCMBS,
    EVENT_ON_ALL_OCMBS
};

/** @brief Process an event that concerns all Odyssey OCMBs in the system. This is
 *  a wrapper around ody_upd_process_event.
 *
 *  @param[in] i_event        The event that occurred.
 *  @param[in] i_which_ocmbs  Which OCMBs to operate on (only functional, or all).
 *  @param[in] i_perform_reconfig_if_needed  Whether this function should request a
 *                                           reconfig loop if one of the OCMBs needs
 *                                           to restart its check_for_ready loop.
 *  @param[out] o_restart_needed  Set to true if one of the OCMBs needs a restart.
 *                                Optional.
 *
 *  @return errlHndl_t       Error if any, otherwise nullptr.
 */
errlHndl_t ody_upd_all_process_event(const ody_upd_event_t i_event,
                                     functional_ocmbs_only_t i_which_ocmbs,
                                     perform_reconfig_t i_perform_reconfig_if_needed,
                                     bool* o_restart_needed = nullptr);

/** @brief Set the Odyssey code update state related to the firmware
 *  levels on the given target. Assumes that ATTR_SPPE_BOOT_SIDE is already
 *  set on the target.
 *
 * @param[in] i_ocmb  The OCMB target to set fsm state on.
 * @param[in] i_ocmbfw_pnor_partition  Handle to the OCMBFW PNOR partition.
 *
 * @return errlHndl_t  Error if any, otherwise nullptr.
 */
errlHndl_t set_ody_code_levels_state(TARGETING:: Target* i_ocmb,
                                     const ocmbfw_owning_ptr_t& i_ocmbfw_pnor_partition);

/** @brief Clears the code update state related to just the Odyssey
 *  code levels on the given OCMB (rather than related to all
 *  information, like the active side, golden boots attempted, etc.)
 *  This is a separate function because this function is populated
 *  every Odyssey boot, whereas the other information needs to be
 *  preserved across Odyssey boots.
 */
inline void clear_ody_code_levels_state(TARGETING::Target* const i_ocmb)
{
    using namespace TARGETING;
    if (UTIL::isOdysseyChip(i_ocmb))
    {
        i_ocmb->setAttr<ATTR_OCMB_FW_STATE>(OCMB_FW_STATE_UNKNOWN);

        ATTR_OCMB_CODE_LEVEL_SUMMARY_type vsn_string = { };
        strcpy(vsn_string, "unknown");
        i_ocmb->setAttr<ATTR_OCMB_CODE_LEVEL_SUMMARY>(vsn_string);
    }
}

/** @brief Reset the Odyssey FSM state for the given OCMB. This is
 *  done when we reach host_ipl_complete or when we detect that a part
 *  has been replaced.
 *
 *  @note This is inline in this header so that other libraries don't have to
 *        load libocmbupd to use it.
 */
inline void ody_upd_reset_state(TARGETING::Target* const i_ocmb)
{
    using namespace TARGETING;

    if (UTIL::isOdysseyChip(i_ocmb))
    {
        i_ocmb->setAttr<ATTR_OCMB_CODE_UPDATED>(0);
        i_ocmb->setAttr<ATTR_OCMB_GOLDEN_BOOT_ATTEMPTED>(0);
        i_ocmb->setAttr<ATTR_OCMB_BOOT_SIDE>(SPPE_BOOT_SIDE_SIDE0);

        clear_ody_code_levels_state(i_ocmb);
    }
}

}
