/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/runtime/nvdimm_rt.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/**
 *  @file nvdimm_rt.C
 *
 *  @brief NVDIMM functions only needed for runtime
 */
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <util/runtime/rt_fwreq_helper.H>
#include <targeting/common/attributes.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <usr/runtime/rt_targeting.H>
#include <runtime/interface.h>
#include <arch/ppc.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include <isteps/nvdimm/nvdimm.H>  // implements some of these
#include "../nvdimm.H" // for g_trac_nvdimm

//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;

namespace NVDIMM
{

const uint8_t NV_STATUS_UNPROTECTED_SET   = 0x01;
const uint8_t NV_STATUS_UNPROTECTED_CLEAR = 0xFE;
const uint8_t NV_STATUS_POSSIBLY_UNPROTECTED_SET   = 0x40;
const uint8_t NV_STATUS_POSSIBLY_UNPROTECTED_CLEAR = 0xBF;

const uint8_t NV_STATUS_OR_MASK = 0xFB;
const uint8_t NV_STATUS_AND_MASK = 0x04;

/**
* @brief Notify PHYP of NVDIMM OCC protection status
*/
errlHndl_t notifyNvdimmProtectionChange(Target* i_target,
                                        const nvdimm_protection_t i_state)
{
    TRACFCOMP( g_trac_nvdimm, ENTER_MRK
        "notifyNvdimmProtectionChange: Target huid 0x%.8X, state %d",
        get_huid(i_target), i_state);

    errlHndl_t l_err = nullptr;

    do
    {
        // Get the type of target passed in
        // It could be proc_type for OCC state
        // Or dimm_type for ARM/ERROR state
        ATTR_TYPE_type l_type = i_target->getAttr<ATTR_TYPE>();
        assert((l_type == TYPE_PROC)||(l_type == TYPE_DIMM),
               "notifyNvdimmProtectionChange invalid target type");

        // Load the nvdimm list
        TargetHandleList l_nvdimmTargetList;
        Target* l_proc = nullptr;
        if (l_type == TYPE_PROC)
        {
            // Get the nvdimms under this proc target
            l_nvdimmTargetList = getProcNVDIMMs(i_target);

            // Only send command if the processor has an NVDIMM under it
            if (l_nvdimmTargetList.empty())
            {
                TRACFCOMP( g_trac_nvdimm, "notifyNvdimmProtectionChange: "
                    "No NVDIMM found under processor 0x%.8X",
                    get_huid(i_target));
                break;
            }

            // The proc target is the passed-in target
            l_proc = i_target;
        }
        else
        {
            // Only a list of one but keep consistent with proc type
            l_nvdimmTargetList.push_back(i_target);

            // Find the proc target from nvdimm target passed in
            TargetHandleList l_procList;
            getParentAffinityTargets(l_procList,
                                     i_target,
                                     CLASS_CHIP,
                                     TYPE_PROC,
                                     UTIL_FILTER_ALL);
            assert(l_procList.size() == 1, "notifyNvdimmProtectionChange:"
                                        "getParentAffinityTargets size != 1");
            l_proc = l_procList[0];
        }


        // Update the nvdimm status attributes
        for (auto const l_nvdimm : l_nvdimmTargetList)
        {
            // Get the armed status attr and update it
            ATTR_NVDIMM_ARMED_type l_armed_state = {};
            // TODO: RTC 211510 Move ATTR_NVDIMM_ARMED from proc_type to dimm type
            //l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
            uint8_t l_tmp = l_nvdimm->getAttr<ATTR_SCRATCH_UINT8_1>();
            memcpy(&l_armed_state, &l_tmp, sizeof(l_tmp));

            switch (i_state)
            {
                case NVDIMM_ARMED:
                    l_armed_state.armed = 1;
                    break;
                case NVDIMM_DISARMED:
                    l_armed_state.armed = 0;
                    break;
                case OCC_ACTIVE:
                    l_armed_state.occ_active = 1;
                    break;
                case OCC_INACTIVE:
                    l_armed_state.occ_active = 0;
                    break;
                case NVDIMM_FATAL_HW_ERROR:
                    l_armed_state.fatal_error_detected = 1;
                    break;
                case NVDIMM_RISKY_HW_ERROR:
                    l_armed_state.risky_error_detected = 1;
                    break;
            }

            // TODO: RTC 211510 Move ATTR_NVDIMM_ARMED from proc_type to dimm type
            //l_nvdimm->setAttr<ATTR_NVDIMM_ARMED>(l_armed_state);
            memcpy(&l_tmp, &l_armed_state, sizeof(l_tmp));
            l_nvdimm->setAttr<ATTR_SCRATCH_UINT8_1>(l_tmp);


            // Get the nv status flag attr and update it
            ATTR_NV_STATUS_FLAG_type l_nv_status =
                        l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();

            // Clear bit 0 if protected nv state
            if (l_armed_state.armed &&
                l_armed_state.occ_active &&
                !l_armed_state.fatal_error_detected)
            {
                l_nv_status &= NV_STATUS_UNPROTECTED_CLEAR;
            }

            // Set bit 0 if unprotected nv state
            else
            {
                l_nv_status |= NV_STATUS_UNPROTECTED_SET;
            }

            // Set bit 6 if risky error
            if (l_armed_state.risky_error_detected)
            {
                l_nv_status |= NV_STATUS_POSSIBLY_UNPROTECTED_SET;
            }

            l_nvdimm->setAttr<ATTR_NV_STATUS_FLAG>(l_nv_status);

        } // for nvdimm list


        // Generate combined nvdimm status for the proc
        // Bit 2 of NV_STATUS_FLAG is 'Device contents are persisted'
        //   and must be ANDed for all nvdimms
        //   the rest of the bits are ORed for all nvdimms
        ATTR_NV_STATUS_FLAG_type l_combined_or     = 0x00;
        ATTR_NV_STATUS_FLAG_type l_combined_and    = 0xFF;
        ATTR_NV_STATUS_FLAG_type l_combined_status = 0x00;
        l_nvdimmTargetList = getProcNVDIMMs(l_proc);
        for (auto const l_nvdimm : l_nvdimmTargetList)
        {
            l_combined_or  |= l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();
            l_combined_and &= l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();
        }

        // Bit 2 of NV_STATUS_FLAG is 'Device contents are persisted'
        l_combined_status =
                (l_combined_or  & NV_STATUS_OR_MASK) |
                (l_combined_and & NV_STATUS_AND_MASK);


        // Send combined status to phyp
        // Get the Proc Chip Id
        RT_TARG::rtChipId_t l_chipId = 0;

        l_err = RT_TARG::getRtTarget(l_proc, l_chipId);
        if(l_err)
        {
            TRACFCOMP( g_trac_nvdimm,
                ERR_MRK"notifyNvdimmProtectionChange: getRtTarget ERROR" );
            break;
        }

        // send the notification msg
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"notifyNvdimmProtectionChange: "
                     "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity          ERRL_SEV_PREDICTIVE
             * @moduleid          NOTIFY_NVDIMM_PROTECTION_CHG
             * @reasoncode        NVDIMM_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1         HUID of processor target
             * @userdata2[0:31]   NV_STATUS to PHYP
             * @userdata2[32:63]  In state change
             * @devdesc           Unable to inform PHYP of NVDIMM protection
             * @custdesc          Internal firmware error
             */
             l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                            NOTIFY_NVDIMM_PROTECTION_CHG,
                            NVDIMM_NULL_FIRMWARE_REQUEST_PTR,
                            get_huid(l_proc),
                            TWO_UINT32_TO_UINT64(
                               l_combined_status,
                               i_state)
                            );

            l_err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);

             break;
        }

        TRACFCOMP( g_trac_nvdimm,
                  "notifyNvdimmProtectionChange: 0x%.8X "
                  "NV_STATUS to PHYP: 0x%02X",
                  get_huid(l_proc),
                  l_combined_status );

        // Create the firmware_request request struct to send data
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        memset(&l_req_fw_msg, 0, sizeof(l_req_fw_msg));  // clear it all

        // actual msg size (one type of hbrt_fw_msg)
        uint64_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                              sizeof(l_req_fw_msg.nvdimm_protection_state);

        // Populate the firmware_request request struct with given data
        l_req_fw_msg.io_type =
                        hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_PROTECTION;
        l_req_fw_msg.nvdimm_protection_state.i_procId = l_chipId;
        l_req_fw_msg.nvdimm_protection_state.i_state = l_combined_status;

        // Create the firmware_request response struct to receive data
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        &l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        &l_resp_fw_msg);

    } while (0);

    TRACFCOMP( g_trac_nvdimm,
        EXIT_MRK "notifyNvdimmProtectionChange(%.8X, %d) - ERRL %.8X:%.4X",
        get_huid(i_target), i_state,
        ERRL_GETEID_SAFE(l_err), ERRL_GETRC_SAFE(l_err) );

    return l_err;
}

/**
 * @brief This function polls the command status register for arm completion
 *        (does not indicate success or fail)
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollArmDone(Target* i_nvdimm,
                             uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollArmDone() nvdimm[%X]", get_huid(i_nvdimm) );

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, ARM, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollArmDone() nvdimm[%X]",
              get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function checks the arm status register to make sure
 *        the trigger has been armed to ddr_reset_n
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmCheckArmSuccess(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmCheckArmSuccess() nvdimm[%X]",
                get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0;

    l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckArmSuccess() nvdimm[%X]"
                  "failed to read arm status reg!",get_huid(i_nvdimm));
    }
    else if ((l_data & ARM_SUCCESS) != ARM_SUCCESS)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckArmSuccess() nvdimm[%X]"
                                 "failed to arm!",get_huid(i_nvdimm));
        /*@
         *@errortype
         *@reasoncode       NVDIMM_ARM_FAILED
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_SET_ARM
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@userdata2        <UNUSED>
         *@devdesc          Encountered error arming the catastrophic save
         *                   trigger on NVDIMM. Make sure an energy source
         *                   is connected to the NVDIMM and the ES policy
         *                   is set properly
         *@custdesc         NVDIMM encountered error arming save trigger
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       NVDIMM_SET_ARM,
                                       NVDIMM_ARM_FAILED,
                                       TWO_UINT32_TO_UINT64(ARM, get_huid(i_nvdimm)),
                                       0x0,
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME, 256 );

        // Failure to arm could mean internal NV controller error or
        // even error on the battery pack. NVDIMM will lose persistency
        // if failed to arm trigger
        l_err->addPartCallout( i_nvdimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH);
        l_err->addPartCallout( i_nvdimm,
                               HWAS::BPM_PART_TYPE,
                               HWAS::SRCI_PRIORITY_MED);
        l_err->addPartCallout( i_nvdimm,
                               HWAS::BPM_CABLE_PART_TYPE,
                               HWAS::SRCI_PRIORITY_MED);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmCheckArmSuccess() nvdimm[%X] ret[%X]",
                get_huid(i_nvdimm), l_data);

    return l_err;
}

bool nvdimmArm(TargetHandleList &i_nvdimmTargetList)
{
    bool o_arm_successful = true;

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmArm() %d",
        i_nvdimmTargetList.size());

    errlHndl_t l_err = nullptr;

    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        // skip if the nvdimm is already armed
        ATTR_NVDIMM_ARMED_type l_armed_state = {};
        // TODO: RTC 211510 Move ATTR_NVDIMM_ARMED from proc_type to dimm type
        //l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
        uint8_t l_tmp = l_nvdimm->getAttr<ATTR_SCRATCH_UINT8_1>();
        memcpy(&l_armed_state, &l_tmp, sizeof(l_tmp));
        if (l_armed_state.armed)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] called when already armed", get_huid(l_nvdimm));
            continue;
        }

        // skip if the nvdimm is in error state
        if (NVDIMM::nvdimmInErrorState(l_nvdimm))
        {
            // error state means arming not successful
            o_arm_successful = false;
            continue;
        }

        l_err = nvdimmSetESPolicy(l_nvdimm);
        if (l_err)
        {
            o_arm_successful = false;
            nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOBKUP);

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;
        }

        l_err = NVDIMM::nvdimmChangeArmState(l_nvdimm, ARM_TRIGGER);
        // If we run into any error here we will just
        // commit the error log and move on. Let the
        // system continue to boot and let the user
        // salvage the data
        if (l_err)
        {
            NVDIMM::nvdimmSetStatusFlag(l_nvdimm, NVDIMM::NSTD_ERR_NOBKUP);
            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
            continue;
        }

        // Arm happens one module at a time. No need to set any offset on the counter
        uint32_t l_poll = 0;
        l_err = nvdimmPollArmDone(l_nvdimm, l_poll);
        if (l_err)
        {
            NVDIMM::nvdimmSetStatusFlag(l_nvdimm, NVDIMM::NSTD_ERR_NOBKUP);
            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
            continue;
        }

        l_err = nvdimmCheckArmSuccess(l_nvdimm);
        if (l_err)
        {
            NVDIMM::nvdimmSetStatusFlag(l_nvdimm, NVDIMM::NSTD_ERR_NOBKUP);
            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
            continue;
        }

        // After arming the trigger, erase the image to prevent the possible
        // stale image getting the restored on the next boot in case of failed
        // save.
        l_err = nvdimmEraseNF(l_nvdimm);
        if (l_err)
        {
            NVDIMM::nvdimmSetStatusFlag(l_nvdimm, NVDIMM::NSTD_ERR_NOBKUP);
            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;

            // If the erase failed let's disarm the trigger
            l_err = nvdimmChangeArmState(l_nvdimm, DISARM_TRIGGER);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArm() nvdimm[%X], error disarming the nvdimm!",
                          get_huid(l_nvdimm));
                l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                l_err->collectTrace(NVDIMM_COMP_NAME);
                errlCommit(l_err, NVDIMM_COMP_ID);
            }

            continue;
        }

        // Arm successful, update armed status
        l_err = NVDIMM::notifyNvdimmProtectionChange(l_nvdimm,
                                                     NVDIMM::NVDIMM_ARMED);
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);
        }
    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmArm() returning %d",
              o_arm_successful);
    return o_arm_successful;
}

bool nvdimmDisarm(TargetHandleList &i_nvdimmTargetList)
{
    bool o_disarm_successful = true;

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmDisarm() %d",
        i_nvdimmTargetList.size());

    errlHndl_t l_err = nullptr;

    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        // skip if the nvdimm is already disarmed
        ATTR_NVDIMM_ARMED_type l_armed_state = {};
        // TODO: RTC 211510 Move ATTR_NVDIMM_ARMED from proc_type to dimm type
        //l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
        uint8_t l_tmp = l_nvdimm->getAttr<ATTR_SCRATCH_UINT8_1>();
        memcpy(&l_armed_state, &l_tmp, sizeof(l_tmp));
        if (!l_armed_state.armed)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmDisarm() nvdimm[%X] called when already disarmed", get_huid(l_nvdimm));
            continue;
        }

        l_err = NVDIMM::nvdimmChangeArmState(l_nvdimm, DISARM_TRIGGER);
        // If we run into any error here we will just
        // commit the error log and move on. Let the
        // system continue to boot and let the user
        // salvage the data
        if (l_err)
        {
            NVDIMM::nvdimmSetStatusFlag(l_nvdimm, NVDIMM::NSTD_ERR_NOBKUP);
            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_disarm_successful = false;
            continue;
        }

        // Disarm successful, update armed status
        l_err = NVDIMM::notifyNvdimmProtectionChange(l_nvdimm,
                                                     NVDIMM::NVDIMM_DISARMED);
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);
        }
    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmDisarm() returning %d",
              o_disarm_successful);
    return o_disarm_successful;
}

/**
 * @brief Check nvdimm error state
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return bool - true if nvdimm is in any error state, false otherwise
 */
bool nvdimmInErrorState(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmInErrorState() HUID[%X]",get_huid(i_nvdimm));

    uint8_t l_statusFlag = i_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();
    bool l_ret = true;

    // Just checking bit 1 for now, need to investigate these
    // Should be checking NVDIMM_ARMED instead
    //if ((l_statusFlag & NSTD_ERR) == 0)
    if ((l_statusFlag & NSTD_ERR_NOPRSV) == 0)
    {
        l_ret = false;
    }

    // Also check the encryption error status
    Target* l_sys = nullptr;
    targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "nvdimmInErrorState: no TopLevelTarget");
    if (l_sys->getAttr<ATTR_NVDIMM_ENCRYPTION_ENABLE>())
    {
        ATTR_NVDIMM_ARMED_type l_armed_state = {};
        // TODO: RTC 211510 Move ATTR_NVDIMM_ARMED from proc_type to dimm type
        //l_armed_state = i_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
        uint8_t l_tmp = i_nvdimm->getAttr<ATTR_SCRATCH_UINT8_1>();
        memcpy(&l_armed_state, &l_tmp, sizeof(l_tmp));
        if (l_armed_state.encryption_error_detected)
        {
            l_ret = true;
        }
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmInErrorState() HUID[%X]",get_huid(i_nvdimm));
    return l_ret;
}


// This could be made a generic utility
errlHndl_t nvdimm_getDarnNumber(size_t i_genSize, uint8_t* o_genData)
{
    assert(i_genSize % sizeof(uint64_t) == 0,"nvdimm_getDarnNumber() bad i_genSize");

    errlHndl_t l_err = nullptr;
    uint64_t* l_darnData = reinterpret_cast<uint64_t*>(o_genData);

    for (uint32_t l_loop = 0; l_loop < (i_genSize / sizeof(uint64_t)); l_loop++)
    {
        // Darn could return an error code
        uint32_t l_darnErrors = 0;

        while (l_darnErrors < MAX_DARN_ERRORS)
        {
            // Get a 64-bit random number with the darn instruction
            l_darnData[l_loop] = getDarn();

            if ( l_darnData[l_loop] != DARN_ERROR_CODE )
            {
                break;
            }
            else
            {
                l_darnErrors++;
            }
        }

        if (l_darnErrors == MAX_DARN_ERRORS)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_getDarnNumber() reached MAX_DARN_ERRORS");
            /*@
            *@errortype
            *@reasoncode       NVDIMM_ENCRYPTION_MAX_DARN_ERRORS
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_GET_DARN_NUMBER
            *@userdata1        MAX_DARN_ERRORS
            *@devdesc          Error using darn instruction
            *@custdesc         NVDIMM encryption error
            */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        NVDIMM_GET_DARN_NUMBER,
                        NVDIMM_ENCRYPTION_MAX_DARN_ERRORS,
                        MAX_DARN_ERRORS,
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);
            break;
        }
    }

    return l_err;
}


errlHndl_t nvdimm_getRandom(uint8_t* o_genData)
{
    errlHndl_t l_err = nullptr;
    uint8_t l_xtraData[ENC_KEY_SIZE] = {0};

    do
    {
        // Get a random number with the darn instruction
        l_err = nvdimm_getDarnNumber(ENC_KEY_SIZE, o_genData);
        if (l_err)
        {
            break;
        }

        // Validate and update the random number
        // Retry if more randomness required
        do
        {
            //Get replacement data
            l_err = nvdimm_getDarnNumber(ENC_KEY_SIZE, l_xtraData);
            if (l_err)
            {
                break;
            }

        }while (nvdimm_keyifyRandomNumber(o_genData, l_xtraData));

    }while (0);

    return l_err;
}


} // end NVDIMM namespace
