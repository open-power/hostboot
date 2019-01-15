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
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include <isteps/nvdimm/nvdimm.H>  // implements some of these
#include "../nvdimm.H" // for g_trac_nvdimm

//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace NVDIMM
{

/**
* @brief Notify PHYP of NVDIMM OCC protection status
*/
errlHndl_t notifyNvdimmProtectionChange(TARGETING::Target* i_target,
                                        const nvdimm_protection_t i_state)
{
    errlHndl_t l_err = nullptr;

    // default to send a not protected status
    uint64_t l_nvdimm_protection_state =
                                hostInterfaces::HBRT_FW_NVDIMM_NOT_PROTECTED;

    TRACFCOMP( g_trac_nvdimm, ENTER_MRK
        "notifyNvdimmProtectionChange: Target huid 0x%.8X, state %d",
        get_huid(i_target), i_state);
    do
    {
        TARGETING::TargetHandleList l_nvdimmTargetList =
            TARGETING::getProcNVDIMMs(i_target);

        // Only send command if the processor has an NVDIMM under it
        if (l_nvdimmTargetList.empty())
        {
            TRACFCOMP( g_trac_nvdimm,
                "notifyNvdimmProtectionChange: No NVDIMM found under processor 0x%.8X",
                get_huid(i_target));
            break;
        }

        TARGETING::ATTR_NVDIMM_ARMED_type l_nvdimm_armed_state =
                              i_target->getAttr<TARGETING::ATTR_NVDIMM_ARMED>();

        // Only notify protected state if NVDIMM controllers are
        // armed and no error was or is detected
        if (i_state == NVDIMM::PROTECTED)
        {
            // Exit without notifying phyp if in error state
            if (l_nvdimm_armed_state.error_detected)
            {
                // State can't go to protected after error is detected
                break;
            }
            // check if we need to rearm the NVDIMM(s)
            else if (!l_nvdimm_armed_state.armed)
            {
                bool nvdimms_armed =
                    NVDIMM::nvdimmArm(l_nvdimmTargetList);
                if (nvdimms_armed)
                {
                    // NVDIMMs are now armed and ready for backup
                    l_nvdimm_armed_state.armed = 1;
                    i_target->setAttr<TARGETING::ATTR_NVDIMM_ARMED>(l_nvdimm_armed_state);

                    l_nvdimm_protection_state = hostInterfaces::HBRT_FW_NVDIMM_PROTECTED;
                }
                else
                {
                    // If nvdimm arming failed,
                    // do NOT post that the dimms are now protected.

                    // Remember this error, only try arming once
                    if (!l_nvdimm_armed_state.error_detected)
                    {
                        l_nvdimm_armed_state.error_detected = 1;
                        i_target->setAttr<TARGETING::ATTR_NVDIMM_ARMED>(l_nvdimm_armed_state);
                    }

                    // Exit without notifying phyp of any protection change
                    break;
                }
            }
            else
            {
                // NVDIMM already armed and no error found
                l_nvdimm_protection_state = hostInterfaces::HBRT_FW_NVDIMM_PROTECTED;
            }
        }
        else if (i_state == NVDIMM::UNPROTECTED_BECAUSE_ERROR)
        {
            // Remember that this NV controller has an error so
            // we don't rearm this until next IPL
            if (!l_nvdimm_armed_state.error_detected)
            {
                l_nvdimm_armed_state.error_detected = 1;
                i_target->setAttr<TARGETING::ATTR_NVDIMM_ARMED>(l_nvdimm_armed_state);
            }
            // still notify phyp that NVDIMM is Not Protected
        }


        // Get the Proc Chip Id
        RT_TARG::rtChipId_t l_chipId = 0;

        l_err = RT_TARG::getRtTarget(i_target, l_chipId);
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

            // need to safely convert struct type into uint32_t
            union {
                TARGETING::ATTR_NVDIMM_ARMED_type tNvdimmArmed;
                uint32_t nvdimmArmed_int;
            } armed_state_union;
            armed_state_union.tNvdimmArmed = l_nvdimm_armed_state;

            /*@
             * @errortype
             * @severity          ERRL_SEV_PREDICTIVE
             * @moduleid          NOTIFY_NVDIMM_PROTECTION_CHG
             * @reasoncode        NVDIMM_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1         HUID of processor target
             * @userdata2[0:31]   Requested protection state
             * @userdata2[32:63]  Current armed state
             * @devdesc           Unable to inform PHYP of NVDIMM protection
             * @custdesc          Internal firmware error
             */
             l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                            NOTIFY_NVDIMM_PROTECTION_CHG,
                            NVDIMM_NULL_FIRMWARE_REQUEST_PTR,
                            get_huid(i_target),
                            TWO_UINT32_TO_UINT64(
                               l_nvdimm_protection_state,
                               armed_state_union.nvdimmArmed_int)
                            );

            l_err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);

             break;
        }

        TRACFCOMP( g_trac_nvdimm,
                  "notifyNvdimmProtectionChange: 0x%.8X processor NVDIMMS are "
                  "%s protected (current armed_state: 0x%02X)",
                  get_huid(i_target),
                  (l_nvdimm_protection_state == hostInterfaces::HBRT_FW_NVDIMM_PROTECTED)?"now":"NOT",
                  l_nvdimm_armed_state );

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
        l_req_fw_msg.nvdimm_protection_state.i_state =
                                                  l_nvdimm_protection_state;

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


bool nvdimmArm(TARGETING::TargetHandleList &i_nvdimmTargetList)
{
    bool o_arm_successful = true;

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmArm() %d",
        i_nvdimmTargetList.size());

    errlHndl_t l_err = nullptr;

    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        // skip if the nvdimm is in error state
        if (NVDIMM::nvdimmInErrorState(l_nvdimm))
        {
            // error state means arming not successful
            o_arm_successful = false;
            continue;
        }

        l_err = NVDIMM::nvdimmArmResetN(l_nvdimm);
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
            l_err->collectTrace(NVDIMM_COMP_NAME, 1024);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
            continue;
        }
    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmArm() returning %d",
              o_arm_successful);
    return o_arm_successful;
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
errlHndl_t nvdimmPollArmDone(TARGETING::Target* i_nvdimm,
                             uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollArmDone() nvdimm[%X]", TARGETING::get_huid(i_nvdimm) );

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, ARM, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollArmDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

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
errlHndl_t nvdimmCheckArmSuccess(TARGETING::Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmCheckArmSuccess() nvdimm[%X]",
                TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0;

    l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckArmSuccess() nvdimm[%X]"
                  "failed to read arm status reg!",TARGETING::get_huid(i_nvdimm));
    }
    else if ((l_data & ARM_SUCCESS) != ARM_SUCCESS)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckArmSuccess() nvdimm[%X]"
                                 "failed to arm!",TARGETING::get_huid(i_nvdimm));
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
                                       TWO_UINT32_TO_UINT64(ARM, TARGETING::get_huid(i_nvdimm)),
                                       0x0,
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
        //@TODO RTC 199645 - add HW callout on dimm target
        //failure to arm could mean internal NV controller error or
        //even error on the battery pack. NVDIMM will lose persistency
        //if failed to arm trigger
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmCheckArmSuccess() nvdimm[%X] ret[%X]",
                TARGETING::get_huid(i_nvdimm), l_data);

    return l_err;
}

/**
 * @brief This function arms the trigger to enable backup in the event
 *        of power loss (DDR Reset_n goes low) in conjunction with
 *        ATOMIC_SAVE_AND_ERASE. A separate erase command is not required
 *        as the image will get erased immediately before backup on the
 *        next catastrophic event.
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmArmResetN(TARGETING::Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmArmResetN() nvdimm[%X]",
                        TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    // Setting ATOMIC_SAVE_AND_ERASE in conjunction with ARM_RESETN. With this,
    // the content of the persistent data is not erased until immediately after
    // the next catastrophic event has occurred.
    l_err = nvdimmWriteReg(i_nvdimm, ARM_CMD, ARM_RESETN_AND_ATOMIC_SAVE_AND_ERASE);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArmResetN() nvdimm[%X] error arming nvdimm!!",
                  TARGETING::get_huid(i_nvdimm));
    }
    else
    {
        // Arm happens one module at a time. No need to set any offset on the counter
        uint32_t l_poll = 0;
        l_err = nvdimmPollArmDone(i_nvdimm, l_poll);
        if (!l_err)
        {
            l_err = nvdimmCheckArmSuccess(i_nvdimm);
        }
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmArmResetN() nvdimm[%X]",
                        TARGETING::get_huid(i_nvdimm));
    return l_err;
}

/**
 * @brief Check nvdimm error state
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return bool - true if nvdimm is in any error state, false otherwise
 */
bool nvdimmInErrorState(TARGETING::Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmInErrorState() HUID[%X]",TARGETING::get_huid(i_nvdimm));

    uint8_t l_statusFlag = i_nvdimm->getAttr<TARGETING::ATTR_NV_STATUS_FLAG>();
    bool l_ret = true;

    if ((l_statusFlag & NSTD_ERR) == 0)
        l_ret = false;

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmInErrorState() HUID[%X]",TARGETING::get_huid(i_nvdimm));
    return l_ret;
}

} // end NVDIMM namespace
