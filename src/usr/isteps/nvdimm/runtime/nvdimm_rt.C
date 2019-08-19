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

/// BPM - Backup Power Module

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
#include "../errlud_nvdimm.H"
#include "../nvdimmErrorLog.H"
#include <isteps/nvdimm/nvdimm.H>  // implements some of these
#include "../nvdimm.H" // for g_trac_nvdimm

//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;
using namespace ERRORLOG;

namespace NVDIMM
{

static constexpr uint64_t DARN_ERROR_CODE = 0xFFFFFFFFFFFFFFFFull;
static constexpr uint32_t MAX_DARN_ERRORS = 10;

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
 * @param[in] i_arm_timeout - nvdimm local timeout status
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmCheckArmSuccess(Target *i_nvdimm, bool i_arm_timeout)
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
    else if (((l_data & ARM_ERROR) == ARM_ERROR) || ((l_data & RESET_N_ARMED) != RESET_N_ARMED) || i_arm_timeout)
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
        l_err->addHwCallout( i_nvdimm,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_Fatal);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmCheckArmSuccess() nvdimm[%X] ret[%X]",
                get_huid(i_nvdimm), l_data);

    return l_err;
}

bool nvdimmArm(TargetHandleList &i_nvdimmTargetList)
{
    bool o_arm_successful = true;
    bool l_continue = true;
    bool l_arm_timeout = false;
    uint8_t l_data;
    auto l_RegInfo = nvdimm_reg_t();
    uint64_t l_writeData;
    uint32_t l_writeAddress;
    size_t l_writeSize = sizeof(l_writeData);

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmArm() %d",
        i_nvdimmTargetList.size());

    errlHndl_t l_err = nullptr;
    errlHndl_t l_err_t = nullptr;

    // Mask MBACALFIR EventN to separate ARM handling
    for (TargetHandleList::iterator it = i_nvdimmTargetList.begin();
         it != i_nvdimmTargetList.end();)
    {
        TargetHandleList l_mcaList;
        getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
        assert(l_mcaList.size(), "nvdimmArm() failed to find parent MCA.");

        l_writeAddress = MBACALFIR_OR_MASK_REG;
        l_writeData = MBACALFIR_EVENTN_OR_BIT;
        l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                            DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }
        it++;
    }

    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        l_arm_timeout = false;

        // skip if the nvdimm is already armed
        ATTR_NVDIMM_ARMED_type l_armed_state = {};
        l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
        if (l_armed_state.armed)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] called when already armed", get_huid(l_nvdimm));
            continue;
        }

        // Set ES Policy, contains all of its status checks
        l_err = nvdimmSetESPolicy(l_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to set ES Policy", get_huid(l_nvdimm));
            o_arm_successful = false;

            nvdimmDisarm(i_nvdimmTargetList);
            l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
            if (l_err_t)
            {
                errlCommit( l_err_t, NVDIMM_COMP_ID );
            }

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Callout the nvdimm on high and gard
            l_err->addHwCallout( l_nvdimm,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_Fatal);

            errlCommit( l_err, NVDIMM_COMP_ID );
            break;
        }

        // Clear ARM status register
        l_err = nvdimmWriteReg(l_nvdimm, NVDIMM_MGT_CMD0, ARM_CLEAR);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArm() nvdimm[%X] - error clearing ARM status register",
                      get_huid(l_nvdimm));
            break;
        }

        l_err = NVDIMM::nvdimmChangeArmState(l_nvdimm, ARM_TRIGGER);
        // If we run into any error here we will just
        // commit the error log and move on. Let the
        // system continue to boot and let the user
        // salvage the data
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to trigger arm", get_huid(l_nvdimm));

            l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
            if (l_err_t)
            {
                errlCommit( l_err_t, NVDIMM_COMP_ID );
            }

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
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] arm command timed out", get_huid(l_nvdimm));
            l_arm_timeout = true;

            l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
            if (l_err_t)
            {
                errlCommit( l_err_t, NVDIMM_COMP_ID );
            }

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);

            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
        }

        // Check health status registers and exit if required
        l_err = nvdimmHealthStatusCheck( l_nvdimm, HEALTH_PRE_ARM, l_arm_timeout );

        // Check for health status failure
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed first health status check", get_huid(l_nvdimm));
            if (!l_continue)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );

                // Disarming all dimms due to error
                nvdimmDisarm(i_nvdimmTargetList);

                o_arm_successful = false;
                break;
            }
            else
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                continue;
            }
        }

        l_err = nvdimmCheckArmSuccess(l_nvdimm, l_arm_timeout);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to succesfully arm", get_huid(l_nvdimm));

            // Disarming all dimms due to error
            nvdimmDisarm(i_nvdimmTargetList);

            l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
            if (l_err_t)
            {
                errlCommit( l_err_t, NVDIMM_COMP_ID );
            }

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Dump Traces for error logs
            nvdimmTraceRegs( l_nvdimm, l_RegInfo );

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

            errlCommit(l_err, NVDIMM_COMP_ID);
            o_arm_successful = false;
            break;
        }

        // After arming the trigger, erase the image to prevent the possible
        // stale image getting the restored on the next boot in case of failed
        // save.
        l_err = nvdimmEraseNF(l_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to erase post arm", get_huid(l_nvdimm));

            // Disarming all dimms due to error
            nvdimmDisarm(i_nvdimmTargetList);

            l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
            if (l_err_t)
            {
                errlCommit( l_err_t, NVDIMM_COMP_ID );
            }

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
            break;
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

        // Enable Persistency and Warning Threshold notifications
        l_err = nvdimmWriteReg(l_nvdimm, SET_EVENT_NOTIFICATION_CMD, ENABLE_NOTIFICATIONS);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] setting persistency notification",
                      TARGETING::get_huid(l_nvdimm));
            break;
        }

        // Check notification status and errors
        l_err = nvdimmReadReg(l_nvdimm, SET_EVENT_NOTIFICATION_STATUS, l_data);
        if (l_err)
        {
            break;
        }
        else if (((l_data & SET_EVENT_NOTIFICATION_ERROR) == SET_EVENT_NOTIFICATION_ERROR)
                   || ((l_data & NOTIFICATIONS_ENABLED) != NOTIFICATIONS_ENABLED))
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to set event notification",
                      get_huid(l_nvdimm));

            // Set NVDIMM Status flag to partial working, as error detected but data might persist
            nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_VAL_SR);

           /*@
            *@errortype
            *@reasoncode       NVDIMM_SET_EVENT_NOTIFICATION_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_SET_EVENT_NOTIFICATION
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM threw an error or failed to set event
            *                  notifications during arming
            *@custdesc         NVDIMM failed to enable event notificaitons
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_SET_EVENT_NOTIFICATION,
                                             NVDIMM_SET_EVENT_NOTIFICATION_ERROR,
                                             TARGETING::get_huid(l_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );

            // Callout the dimm
            l_err->addHwCallout( l_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Read relevant regs for trace data
            nvdimmTraceRegs(l_nvdimm, l_RegInfo);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

            errlCommit( l_err, NVDIMM_COMP_ID );
            break;
        }

        // Re-check health status registers
        l_err = nvdimmHealthStatusCheck( l_nvdimm, HEALTH_POST_ARM, l_continue );

        // Check for health status failure
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed final health status check", get_huid(l_nvdimm));

            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
            break;
        }

    }

    // Check for uncommited i2c fail error logs
    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, "nvdimmArm() failed an i2c read/write");
        errlCommit( l_err, NVDIMM_COMP_ID );
        nvdimmDisarm(i_nvdimmTargetList);
        return false;
    }

    // Unmask MBACALFIR EventN and set to recoverable
    for (TargetHandleList::iterator it = i_nvdimmTargetList.begin();
         it != i_nvdimmTargetList.end();)
    {
        TargetHandleList l_mcaList;
        getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
        assert(l_mcaList.size(), "nvdimmArm() failed to find parent MCA.");

        // Set MBACALFIR_ACTION0 to recoverable
        l_writeAddress = MBACALFIR_ACTION0_REG;
        l_writeData = 0;
        l_err = deviceRead(l_mcaList[0], &l_writeData, l_writeSize,
                           DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }


        l_writeData &= MBACALFIR_EVENTN_AND_BIT;
        l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                               DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // Set MBACALFIR_ACTION1 to recoverable
        l_writeAddress = MBACALFIR_ACTION1_REG;
        l_writeData = 0;
        l_err = deviceRead(l_mcaList[0], &l_writeData, l_writeSize,
                           DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }

        l_writeData |= MBACALFIR_EVENTN_OR_BIT;
        l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                            DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // Unmask MBACALFIR[8]
        l_writeAddress = MBACALFIR_AND_MASK_REG;
        l_writeData = MBACALFIR_UNMASK_BIT;
        l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                            DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }

        it++;
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
        l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
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
    if ((l_statusFlag & NSTD_VAL_ERASED) == 0)
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
        l_armed_state = i_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
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

/*
 * @brief Check the health status of the individual NVDIMMs supplied in list
 *
 * @param[in] i_nvdimmTargetList - list of NVDIMMs to check the health of
 *
 * @return false if one or more NVDIMMs fail health check, else true
 */
bool nvDimmCheckHealthStatus(TargetHandleList &i_nvdimmTargetList)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmCheckHealthStatus(): "
              "Target list size(%d)", i_nvdimmTargetList.size());

    // The minimum lifetime value
    const uint8_t LIFETIME_MINIMUM_REQUIREMENT = 0x62;   // > 97%

    // The health check status flags for the different states of a health check
    const uint8_t HEALTH_CHECK_IN_PROGRESS_FLAG = 0x01;  // bit 0
    const uint8_t HEALTH_CHECK_SUCCEEDED_FLAG   = 0x02;  // bit 1
    const uint8_t HEALTH_CHECK_FAILED_FLAG      = 0x04;  // bit 2

    // Handle to catch any errors
    errlHndl_t l_err(nullptr);

    // The health check status from a health check call
    uint8_t l_healthCheck(0);

    // Status of the accumulation of all calls related to the health check.
    // If any one call is bad/fails, then this will be false, else it stays true
    bool l_didHealthCheckPass(true);

    // Iterate thru the NVDIMMs checking the health status of each one.
    // Going with the assumption that the caller waited the allotted time,
    // roughly 20 to 30 minutes, after the start of an IPL.
    // Success case:
    //   * Health check initiated at start of the IPL, caller waited the
    //     allotted time (20 to 30 mins) before doing a health check, health
    //     check returned success and the lifetime meets the minimum threshold
    //     for a new BPM.
    // Error cases are:
    //   * Health check is in progress, will assume BPM is hung
    //   * Health check failed
    //   * Health check succeeded but lifetime does not meet a certain threshold
    //   * If none of the above apply (success case and other error cases),
    //     then assume the health check was never initiated at the start of the
    //     IPL
    //   For each of these error cases do a predictive callout
    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        // Retrieve the Health Check status from the BPM
        TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckHealthStatus(): "
                  "Reading NVDIMM(0x%.8X) health check data, "
                  "register ES_CMD_STATUS0(0x%.2X)",
                   get_huid(l_nvdimm), ES_CMD_STATUS0);

        l_err = nvdimmReadReg(l_nvdimm, ES_CMD_STATUS0, l_healthCheck);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvDimmCheckHealthStatus(): "
                      "NVDIMM(0x%X) failed to read the health check "
                      "data, register ES_CMD_STATUS0(0x%.2X)",
                      get_huid(l_nvdimm), ES_CMD_STATUS0);

            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didHealthCheckPass = false;

            // Proceed to next NVDIMM, better luck next time
            continue;
        }

        // Trace out the returned data for inspection
        TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckHealthStatus(): "
                  "NVDIMM(0x%X) returned value(0x%.2X) from health check "
                  "data, register ES_CMD_STATUS0(0x%.2X)",
                  get_huid(l_nvdimm), l_healthCheck, ES_CMD_STATUS0)

        if (l_healthCheck & HEALTH_CHECK_IN_PROGRESS_FLAG)
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmCheckHealthStatus(): "
                       "Assuming caller waited the allotted time before "
                       "doing a health check on NVDIMM(0x%.8X), the BPM "
                       "is hung doing the health check.",
                       get_huid(l_nvdimm) );

            /*@
             * @errortype
             * @severity    ERRL_SEV_PREDICTIVE
             * @moduleid    NVDIMM_HEALTH_CHECK
             * @reasoncode  NVDIMM_HEALTH_CHECK_IN_PROGRESS_FAILURE
             * @userdata1   HUID of NVDIMM target
             * @userdata2   Health check status
             * @devdesc     Assuming caller waited the allotted time before
             *              doing a health check, then the BPM is hung doing
             *              the health check.
             * @custdesc    NVDIMM Health Check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_HEALTH_CHECK,
                                   NVDIMM_HEALTH_CHECK_IN_PROGRESS_FAILURE,
                                   get_huid(l_nvdimm),
                                   l_healthCheck,
                                   ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Add a BPM callout
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didHealthCheckPass = false;
        }
        else if (l_healthCheck & HEALTH_CHECK_FAILED_FLAG)
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmCheckHealthStatus(): "
                       "Assuming caller waited the allotted time before "
                       "doing a health check on NVDIMM(0x%.8X), the BPM "
                       "reported a failure.",
                       get_huid(l_nvdimm) );

            /*@
             * @errortype
             * @severity    ERRL_SEV_PREDICTIVE
             * @moduleid    NVDIMM_HEALTH_CHECK
             * @reasoncode  NVDIMM_HEALTH_CHECK_REPORTED_FAILURE
             * @userdata1   HUID of NVDIMM target
             * @userdata2   Health check status
             * @devdesc     NVDIMM Health Check failed
             * @devdesc     Assuming caller waited the allotted time before
             *              doing a health check, the BPM reported a failure
             *              while doing a health check.
             * @custdesc    NVDIMM Health Check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_HEALTH_CHECK,
                                   NVDIMM_HEALTH_CHECK_REPORTED_FAILURE,
                                   get_huid(l_nvdimm),
                                   l_healthCheck,
                                   ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Add a BPM callout
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didHealthCheckPass = false;
        }
        else if (l_healthCheck & HEALTH_CHECK_SUCCEEDED_FLAG)
        {
            TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckHealthStatus(): "
                      "Reading NVDIMM(0x%.8X) es lifetime data, "
                      "register ES_LIFETIME(0x%.2X)",
                       get_huid(l_nvdimm), ES_LIFETIME);

            // The lifetime percentage
            uint8_t l_lifetimePercentage(0);

            // Retrieve the Lifetime Percentage from the BPM
            l_err = nvdimmReadReg(l_nvdimm, ES_LIFETIME, l_lifetimePercentage);

            if (l_err)
            {
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmCheckHealthStatus(): "
                           "NVDIMM(0x%.8X) failed to read the "
                           "ES_LIFETIME(0x%.2X) data",
                           get_huid(l_nvdimm),
                           ES_LIFETIME );

                l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                l_err->collectTrace(NVDIMM_COMP_NAME);
                errlCommit(l_err, NVDIMM_COMP_ID);

                // Let the caller know something went amiss
                l_didHealthCheckPass = false;
            }
            else if (l_lifetimePercentage < LIFETIME_MINIMUM_REQUIREMENT)
            {
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmCheckHealthStatus(): "
                           "Health check on NVDIMM(0x%.8X) succeeded but the "
                           "BPM's lifetime(%d) does not meet the minimum "
                           "requirement(%d) needed to qualify as a new BPM.",
                            get_huid(l_nvdimm),
                            l_lifetimePercentage,
                            LIFETIME_MINIMUM_REQUIREMENT );

                /*@
                 * @errortype
                 * @severity         ERRL_SEV_PREDICTIVE
                 * @moduleid         NVDIMM_HEALTH_CHECK
                 * @reasoncode       NVDIMM_LIFETIME_MIN_REQ_NOT_MET
                 * @userdata1[00:31] HUID of NVDIMM target
                 * @userdata1[32:63] Health check status
                 * @userdata2[00:31] Retrieved lifetime percentage
                 * @userdata2[32:63] lifetime minimum requirement
                 * @devdesc          Health check succeeded but the BPM's
                 *                   lifetime does not meet the minimum
                 *                   requirement needed to qualify as a
                 *                   new BPM.
                 * @custdesc    NVDIMM Health Check failed
                 */
                l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                       NVDIMM_HEALTH_CHECK,
                                       NVDIMM_LIFETIME_MIN_REQ_NOT_MET,
                                       TWO_UINT32_TO_UINT64(
                                           get_huid(l_nvdimm),
                                           l_healthCheck),
                                       TWO_UINT32_TO_UINT64(
                                           l_lifetimePercentage,
                                           LIFETIME_MINIMUM_REQUIREMENT),
                                       ErrlEntry::NO_SW_CALLOUT );
                l_err->collectTrace(NVDIMM_COMP_NAME);

                // Add a BPM callout
                l_err->addPartCallout( l_nvdimm,
                                       HWAS::BPM_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH);
                // Collect the error
                errlCommit(l_err, NVDIMM_COMP_ID);

                // Let the caller know something went amiss
                l_didHealthCheckPass = false;
            } // end else if (l_lifetimePercentage ...
            else
            {
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimmCheckHealthStatus(): "
                           "Success: Health check on NVDIMM(0x%.8X) succeeded "
                           "and the BPM's lifetime(%d) meet's the minimum "
                           "requirement(%d) needed to qualify as a new BPM.",
                            get_huid(l_nvdimm),
                            l_lifetimePercentage,
                            LIFETIME_MINIMUM_REQUIREMENT );
            }
        }  // end else if (l_healthCheck & HEALTH_CHECK_SUCCEEDED_FLAG)
        else  // Assume the health check was never initiated at
              // the start of the IPL.
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmCheckHealthStatus(): "
                       "The health check on NVDIMM(0x%.8X) shows no status (in "
                       "progress, fail or succeed) so assuming it was never "
                       "initiated at the start of the IPL.",
                       get_huid(l_nvdimm) );

            /*@
             * @errortype
             * @severity    ERRL_SEV_PREDICTIVE
             * @moduleid    NVDIMM_HEALTH_CHECK
             * @reasoncode  NVDIMM_HEALTH_CHECK_NEVER_INITIATED
             * @userdata1   HUID of NVDIMM target
             * @userdata2   Health check status
             * @devdesc     The health check shows no status (in progress, fail
             *              or succeed) so assuming it was never initiated
             *              at the start of the IPL.
             * @custdesc    NVDIMM Health Check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_HEALTH_CHECK,
                                   NVDIMM_HEALTH_CHECK_NEVER_INITIATED,
                                   get_huid(l_nvdimm),
                                   l_healthCheck,
                                   ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Add a BPM callout
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didHealthCheckPass = false;
        }
    }  // end for (auto const l_nvdimm : i_nvdimmTargetList)

    // Should not have any uncommitted errors
    assert(l_err == NULL, "nvDimmCheckHealthStatus() - unexpected uncommitted"
                          "error found" );

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmCheckHealthStatus(): "
              "Returning %s", l_didHealthCheckPass == true ? "true" : "false" );

    return l_didHealthCheckPass;
}  // end nvDimmCheckHealthStatus

/**
 * @brief A wrapper around the call to nvDimmCheckHealthStatus
 *
 * @see nvDimmCheckHealthStatus for more details
 *
 * @return false if one or more NVDIMMs fail health check, else true
 */
bool nvDimmCheckHealthStatusOnSystem()
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmCheckHealthStatusOnSystem()");

    // Get the list of NVDIMM Targets from the system
    TargetHandleList l_nvDimmTargetList;
    nvdimm_getNvdimmList(l_nvDimmTargetList);

    // Return status of doing a check health status
    bool l_didHealthCheckPass = nvDimmCheckHealthStatus(l_nvDimmTargetList);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmCheckHealthStatusOnSystem(): "
              "Returning %s", l_didHealthCheckPass == true ? "true" : "false" );

    return l_didHealthCheckPass;
}  // end nvDimmCheckHealthStatusOnSystem

} // end NVDIMM namespace
