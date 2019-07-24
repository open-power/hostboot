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
        l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
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


} // end NVDIMM namespace
