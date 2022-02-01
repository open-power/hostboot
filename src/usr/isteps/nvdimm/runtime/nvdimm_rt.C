/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/runtime/nvdimm_rt.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
 *  @brief NVDIMM functions only needed for runtime.  These functions include
 *         but are not limited to arming/disarming the NVDIMM along with methods
 *         to poll the arming and check the status of the arming.  Checking the
 *         error state of the NVDIMM, getting a random number with the darn
 *         instruction and checking the ES or NVM health status.
 */

/// BPM - Backup Power Module

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludstring.H>
#include <util/runtime/rt_fwreq_helper.H>
#include <targeting/common/attributes.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <targeting/runtime/rt_targeting.H>
#include <runtime/interface.h>
#include <arch/ppc.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include "../errlud_nvdimm.H"
#include "../nvdimmErrorLog.H"
#include <isteps/nvdimm/nvdimm.H>  // implements some of these
#include "../nvdimm.H" // for g_trac_nvdimm
#include <sys/time.h>

//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;
using namespace ERRORLOG;

namespace NVDIMM
{

static constexpr uint64_t DARN_ERROR_CODE = 0xFFFFFFFFFFFFFFFFull;
static constexpr uint32_t MAX_DARN_ERRORS = 10;

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
 * @brief Check the ES (enery source)/backup power module(BPM) health status of
 *        the individual NVDIMMs supplied in list
 *
 * @param[in] i_nvdimmTargetList - list of NVDIMMs to check the ES health of
 *
 * @return false if one or more NVDIMMs fail ES health check, else true
 */
bool nvDimmEsCheckHealthStatus(const TargetHandleList &i_nvdimmTargetList)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmEsCheckHealthStatus(): "
              "Target list size(%d)", i_nvdimmTargetList.size());

    // The minimum ES lifetime value
    const uint8_t ES_LIFETIME_MINIMUM_REQUIREMENT = 0x62;   // > 97%

    // The ES health check status flags for the different states of an
    // ES health check
    const uint8_t ES_HEALTH_CHECK_IN_PROGRESS_FLAG = 0x01;  // bit 0
    const uint8_t ES_HEALTH_CHECK_SUCCEEDED_FLAG   = 0x02;  // bit 1
    const uint8_t ES_HEALTH_CHECK_FAILED_FLAG      = 0x04;  // bit 2

    // Handle to catch any errors
    errlHndl_t l_err(nullptr);

    // The ES health check status from an ES health check call
    uint8_t l_esHealthCheck(0);

    // Status of the accumulation of all calls related to the ES health check.
    // If any one call is bad/fails, then this will be false, else it stays true
    bool l_didEsHealthCheckPass(true);

    // Iterate thru the NVDIMMs checking the ES health status of each one.
    // Going with the assumption that the caller waited the allotted time,
    // roughly 20 to 30 minutes, after the start of an IPL.
    // Success case:
    //   * ES health check initiated at start of the IPL, caller waited the
    //     allotted time (20 to 30 mins) before doing a health check, health
    //     check returned success and the lifetime meets the minimum threshold
    //     for a new BPM.
    // Error cases are:
    //   * ES health check is in progress, will assume BPM is hung
    //   * ES health check failed
    //   * ES health check succeeded but lifetime does not meet a
    //     certain threshold
    //   * If none of the above apply (success case and other error cases),
    //     then assume the ES health check was never initiated at the start
    //     of the IPL
    //   For each of these error cases do a predictive callout
    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        // Retrieve the Health Check status from the BPM
        TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmEsCheckHealthStatus(): "
                  "Reading NVDIMM(0x%.8X) ES health check data, "
                  "register ES_CMD_STATUS0(0x%.2X)",
                   get_huid(l_nvdimm), ES_CMD_STATUS0);

        l_err = nvdimmReadReg(l_nvdimm, ES_CMD_STATUS0, l_esHealthCheck);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                      "NVDIMM(0x%X) failed to read the ES health check "
                      "data, register ES_CMD_STATUS0(0x%.2X)",
                      get_huid(l_nvdimm), ES_CMD_STATUS0);

            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didEsHealthCheckPass = false;

            // Proceed to next NVDIMM, better luck next time
            continue;
        }

        // Trace out the returned data for inspection
        TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmEsCheckHealthStatus(): "
                  "NVDIMM(0x%X) returned value(0x%.2X) from the ES health "
                  "check data, register ES_CMD_STATUS0(0x%.2X)",
                  get_huid(l_nvdimm), l_esHealthCheck, ES_CMD_STATUS0);

        if (l_esHealthCheck & ES_HEALTH_CHECK_IN_PROGRESS_FLAG)
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                       "Assuming caller waited the allotted time before "
                       "doing an ES health check on NVDIMM(0x%.8X), the BPM "
                       "is hung doing the ES health check.",
                       get_huid(l_nvdimm) );

            /*@
             * @errortype
             * @severity    ERRL_SEV_PREDICTIVE
             * @moduleid    NVDIMM_ES_HEALTH_CHECK
             * @reasoncode  NVDIMM_ES_HEALTH_CHECK_IN_PROGRESS_FAILURE
             * @userdata1   HUID of NVDIMM target
             * @userdata2   ES health check status
             * @devdesc     Assuming caller waited the allotted time before
             *              doing an ES health check, then the BPM is hung doing
             *              the ES health check.
             * @custdesc    NVDIMM ES health check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_ES_HEALTH_CHECK,
                                   NVDIMM_ES_HEALTH_CHECK_IN_PROGRESS_FAILURE,
                                   get_huid(l_nvdimm),
                                   l_esHealthCheck,
                                   ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);
            nvdimmAddVendorLog(l_nvdimm, l_err);

            // Add a BPM callout
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddPage4Regs(l_nvdimm,l_err);
            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didEsHealthCheckPass = false;
        }
        else if (l_esHealthCheck & ES_HEALTH_CHECK_FAILED_FLAG)
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                       "Assuming caller waited the allotted time before "
                       "doing an ES health check on NVDIMM(0x%.8X), the BPM "
                       "reported a failure.",
                       get_huid(l_nvdimm) );

            /*@
             * @errortype
             * @severity    ERRL_SEV_PREDICTIVE
             * @moduleid    NVDIMM_ES_HEALTH_CHECK
             * @reasoncode  NVDIMM_ES_HEALTH_CHECK_REPORTED_FAILURE
             * @userdata1   HUID of NVDIMM target
             * @userdata2   ES health check status
             * @devdesc     Assuming caller waited the allotted time before
             *              doing an ES health check, the BPM reported a failure
             *              while doing an ES health check.
             * @custdesc    NVDIMM ES health check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_ES_HEALTH_CHECK,
                                   NVDIMM_ES_HEALTH_CHECK_REPORTED_FAILURE,
                                   get_huid(l_nvdimm),
                                   l_esHealthCheck,
                                   ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);
            nvdimmAddVendorLog(l_nvdimm, l_err);

            // Add a BPM callout
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddPage4Regs(l_nvdimm,l_err);
            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didEsHealthCheckPass = false;
        }
        else if (l_esHealthCheck & ES_HEALTH_CHECK_SUCCEEDED_FLAG)
        {
            TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmEsCheckHealthStatus(): "
                      "Reading NVDIMM(0x%.8X) ES lifetime data, "
                      "register ES_LIFETIME(0x%.2X)",
                       get_huid(l_nvdimm), ES_LIFETIME);

            // The lifetime percentage
            uint8_t l_lifetimePercentage(0);

            // Retrieve the Lifetime Percentage from the BPM
            l_err = nvdimmReadReg(l_nvdimm, ES_LIFETIME, l_lifetimePercentage);

            if (l_err)
            {
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                           "NVDIMM(0x%.8X) failed to read the "
                           "ES_LIFETIME(0x%.2X) data",
                           get_huid(l_nvdimm),
                           ES_LIFETIME );

                l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                l_err->collectTrace(NVDIMM_COMP_NAME);
                errlCommit(l_err, NVDIMM_COMP_ID);

                // Let the caller know something went amiss
                l_didEsHealthCheckPass = false;
            }
            else if (l_lifetimePercentage < ES_LIFETIME_MINIMUM_REQUIREMENT)
            {
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                           "ES health check on NVDIMM(0x%.8X) succeeded but "
                           "the BPM's lifetime(%d) does not meet the minimum "
                           "requirement(%d) needed to qualify as a new BPM.",
                            get_huid(l_nvdimm),
                            l_lifetimePercentage,
                            ES_LIFETIME_MINIMUM_REQUIREMENT );

                /*@
                 * @errortype
                 * @severity         ERRL_SEV_PREDICTIVE
                 * @moduleid         NVDIMM_ES_HEALTH_CHECK
                 * @reasoncode       NVDIMM_ES_LIFETIME_MIN_REQ_NOT_MET
                 * @userdata1[00:31] HUID of NVDIMM target
                 * @userdata1[32:63] ES health check status
                 * @userdata2[00:31] Retrieved lifetime percentage
                 * @userdata2[32:63] lifetime minimum requirement
                 * @devdesc          ES health check succeeded but the BPM's
                 *                   lifetime does not meet the minimum
                 *                   requirement needed to qualify as a
                 *                   new BPM.
                 * @custdesc         NVDIMM ES health check failed
                 */
                l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                       NVDIMM_ES_HEALTH_CHECK,
                                       NVDIMM_ES_LIFETIME_MIN_REQ_NOT_MET,
                                       TWO_UINT32_TO_UINT64(
                                           get_huid(l_nvdimm),
                                           l_esHealthCheck),
                                       TWO_UINT32_TO_UINT64(
                                           l_lifetimePercentage,
                                           ES_LIFETIME_MINIMUM_REQUIREMENT),
                                       ErrlEntry::NO_SW_CALLOUT );
                l_err->collectTrace(NVDIMM_COMP_NAME);
                nvdimmAddVendorLog(l_nvdimm, l_err);

                // Add a BPM callout
                l_err->addPartCallout( l_nvdimm,
                                       HWAS::BPM_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH);
                nvdimmAddPage4Regs(l_nvdimm,l_err);
                // Collect the error
                errlCommit(l_err, NVDIMM_COMP_ID);

                // Let the caller know something went amiss
                l_didEsHealthCheckPass = false;
            } // end else if (l_lifetimePercentage ...
            else
            {
                TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                           "Success: ES health check on NVDIMM(0x%.8X) "
                           "succeeded and the BPM's lifetime(%d) meet's the  "
                           "minimum requirement(%d) needed to qualify as "
                           "a new BPM.",
                            get_huid(l_nvdimm),
                            l_lifetimePercentage,
                            ES_LIFETIME_MINIMUM_REQUIREMENT );
            }
        }  // end else if (l_esHealthCheck & ES_HEALTH_CHECK_SUCCEEDED_FLAG)
        else  // Assume the ES health check was never initiated at
              // the start of the IPL.
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvDimmEsCheckHealthStatus(): "
                       "The ES health check on NVDIMM(0x%.8X) shows no status "
                       "(in progress, fail or succeed) so assuming it was "
                       "never initiated at the start of the IPL.",
                       get_huid(l_nvdimm) );

            /*@
             * @errortype
             * @severity    ERRL_SEV_PREDICTIVE
             * @moduleid    NVDIMM_ES_HEALTH_CHECK
             * @reasoncode  NVDIMM_ES_HEALTH_CHECK_NEVER_INITIATED
             * @userdata1   HUID of NVDIMM target
             * @userdata2   ES health check status
             * @devdesc     The ES health check shows no status (in progress,
             *              fail or succeed) so assuming it was never initiated
             *              at the start of the IPL.
             * @custdesc    NVDIMM ES health check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_ES_HEALTH_CHECK,
                                   NVDIMM_ES_HEALTH_CHECK_NEVER_INITIATED,
                                   get_huid(l_nvdimm),
                                   l_esHealthCheck,
                                   ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);
            nvdimmAddVendorLog(l_nvdimm, l_err);

            // Add a BPM callout
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddPage4Regs(l_nvdimm,l_err);
            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didEsHealthCheckPass = false;
        }
    }  // end for (auto const l_nvdimm : i_nvdimmTargetList)

    // Should not have any uncommitted errors
    assert(l_err == NULL, "nvDimmEsCheckHealthStatus() - unexpected "
                          "uncommitted error found" );

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmEsCheckHealthStatus(): "
             "Returning %s", l_didEsHealthCheckPass == true ? "true" : "false");

    return l_didEsHealthCheckPass;
}  // end nvDimmEsCheckHealthStatus

/**
 * @brief A wrapper around the call to nvDimmEsCheckHealthStatus
 *
 * @see nvDimmEsCheckHealthStatus for more details
 *
 * @return false if one or more NVDIMMs fail an ES health check, else true
 */
bool nvDimmEsCheckHealthStatusOnSystem()
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmEsCheckHealthStatusOnSystem()");

    // Get the list of NVDIMM Targets from the system
    TargetHandleList l_nvDimmTargetList;
    nvdimm_getNvdimmList(l_nvDimmTargetList);

    // Return status of doing a check health status
    bool l_didEsHealthCheckPass = nvDimmEsCheckHealthStatus(l_nvDimmTargetList);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmEsCheckHealthStatusOnSystem(): "
            "Returning %s", l_didEsHealthCheckPass == true ? "true" : "false" );

    return l_didEsHealthCheckPass;
}  // end nvDimmCheckHealthStatusOnSystem

/*
 * @brief Check the bad flash block percentage against a given maximum allowed.
 *
 * @details This returns a tristate - 1 pass, 2 different fails
 *          If true is returned, then the check passed and
 *                  o_badFlashBlockPercentage will contain what the retrieved
 *                  flash block percentage is.
 *          If false is returned and the o_badFlashBlockPercentage is zero, then
 *                  the check failed because of a register read fail
 *          If false is returned and the o_badFlashBlockPercentage is not zero,
 *                  then the check failed because the retrieved bad flash block
 *                  percentage exceeds the given maximum allowed
 *
 * @param[in]  i_nvDimm - The NVDIMM to check
 * @param[in]  i_maxPercentageAllowed - The maximum percentage of bad flash
 *                                      block allowed
 * @param[out] o_badFlashBlockPercentage - The retrieved bad flash block
 *                                         percentage from i_nvDimm, if no
 *                                         register read error.
 *
 * @return false if check failed or register read failed, else true
 */
bool nvDimmCheckBadFlashBlockPercentage(TargetHandle_t i_nvDimm,
                                        const uint8_t  i_maxPercentageAllowed,
                                        uint8_t  &o_badFlashBlockPercentage)
{
    // Cache the HUID of the NVDIMM
    uint32_t l_nvDimmHuid = get_huid( i_nvDimm );

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmCheckBadFlashBlockPercentage(): "
              "NVDIMM(0x%.4X), max bad flash blocks allowed(%d)",
              l_nvDimmHuid,
              i_maxPercentageAllowed);

    // The status of the check on the bad block percentage
    bool l_didBadFlashBlockPercentageCheckPass(true);

    // The retrieved flash block percentage from register, initialize to zero
    o_badFlashBlockPercentage = 0;

    // Handle to catch any errors
    errlHndl_t l_err(nullptr);

    // Retrieve the percentage of bad blocks and validate
    TRACDCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckBadFlashBlockPercentage(): "
              "Reading NVDIMM(0x%.8X) percentage of bad blocks from "
              "register FLASH_BAD_BLK_PCT(0x%.4X)",
               l_nvDimmHuid, FLASH_BAD_BLK_PCT);

    l_err = nvdimmReadReg(i_nvDimm,
                          FLASH_BAD_BLK_PCT,
                          o_badFlashBlockPercentage);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvDimmCheckBadFlashBlockPercentage(): "
                 "FAIL: NVDIMM(0x%.8X) failed to read the percentage of "
                 "bad blocks from register FLASH_BAD_BLK_PCT(0x%.4X), "
                 "marking as a fail",
                 l_nvDimmHuid, FLASH_BAD_BLK_PCT);

        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit(l_err, NVDIMM_COMP_ID);

        // Set up the fail state, so caller can determine that the fail was
        // due to a register read error
        l_didBadFlashBlockPercentageCheckPass = false;
        o_badFlashBlockPercentage = 0;
    }
    else
    {
        // Trace out the returned data for inspection
        TRACDCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckBadFlashBlockPercentage(): "
                  "NVDIMM(0x%.8X) returned value (%d) from the "
                  "percentage of bad blocks, register "
                  "FLASH_BAD_BLK_PCT(0x%.4X)",
                  l_nvDimmHuid,
                  o_badFlashBlockPercentage,
                  FLASH_BAD_BLK_PCT);

        // Check to see if the bad flash block percentage
        // exceeds maximum allowed.
        if (o_badFlashBlockPercentage > i_maxPercentageAllowed)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvDimmCheckBadFlashBlockPercentage(): "
                      "FAIL: For NVDIMM (0x%.8X), the percentage of bad "
                      "flash blocks (%d), read from register "
                      "FLASH_BAD_BLK_PCT(0x%.4X), exceeds the maximum "
                      "percentage of bad flash blocks allowed (%d), marking "
                      "this as a fail",
                      l_nvDimmHuid,
                      o_badFlashBlockPercentage,
                      FLASH_BAD_BLK_PCT,
                      i_maxPercentageAllowed);

            // Set up the fail state, so caller can determine that the fail was
            // due to percentage exceeding the max percentage allowed.
            // Note: Leave the value in o_badFlashBlockPercentage so caller
            // can inspect, if they wish
            l_didBadFlashBlockPercentageCheckPass = false;
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckBadFlashBlockPercentage(): "
                      "SUCCESS: For NVDIMM (0x%.8X), the percentage of bad "
                      "flash blocks (%d) is less than or meets the maximum "
                      "percentage of bad flash blocks allowed (%d), "
                      "marking this as a pass",
                      l_nvDimmHuid,
                      o_badFlashBlockPercentage,
                      i_maxPercentageAllowed);

            // Set up the pass state
            // Note: Leave the value in o_badFlashBlockPercentage so caller
            // can inspect, if they wish
            l_didBadFlashBlockPercentageCheckPass = true;
        }  // end if (l_badFlashBlockPercentage > i_maxPercentageAllowed)
    }  // end if (l_err) ... else

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmCheckBadFlashBlockPercentage(): "
             "Returning %s",
             l_didBadFlashBlockPercentageCheckPass == true ? "true" : "false" );

    return l_didBadFlashBlockPercentageCheckPass;
}

/*
 * @brief Check the flash error count against a given maximum allowed.
 *
 * @details This returns a tristate - 1 pass, 2 different fails
 *          If true is returned, then the check passed and
 *                  o_readFlashErrorCount will contain what the retrieved
 *                  flash error count is.
 *          If false is returned and the o_readFlashErrorCount is zero, then
 *                  the check failed because of a register read fail
 *          If false is returned and the o_readFlashErrorCount is not zero,
 *                  then the check failed because the retrieved flash error
 *                  count exceeds the given maximum allowed
 *
 * @param[in]  i_nvDimm - The NVDIMM to check
 * @param[in]  i_maxFlashErrorsAllowed - The maximum number of flash errors
 *                                       allowed
 * @param[out] o_readFlashErrorCount - The retrieved bad flash error
 *                                     count from i_nvDimm, if no
 *                                     register read error.
 *
 * @return false if check failed or register read failed, else true
 */
bool nvDimmCheckFlashErrorCount(TargetHandle_t  i_nvDimm,
                                const uint32_t  i_maxFlashErrorsAllowed,
                                uint32_t       &o_readFlashErrorCount)
{
    // Cache the HUID of the NVDIMM
    uint32_t l_nvDimmHuid = get_huid( i_nvDimm );

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmCheckFlashErrorCount(): "
              "NVDIMM(0x%.4X), max flash errors allowed(%d)",
              l_nvDimmHuid,
              i_maxFlashErrorsAllowed);

    // The status of the check on the flash error count
    bool l_didFlashErrorCountCheckPass(true);

    // The retrieved flash error count from register, initialize to zero
    o_readFlashErrorCount = 0;

    // Handle to catch any errors
    errlHndl_t l_err(nullptr);

    // The retrieved flash error count from a register
    uint8_t l_readFlashErrorCountByte(0);

    // Read the flash error count registers starting from MSB to LSB
    for (int16_t l_flashErrorRegister = FLASH_ERROR_COUNT2;
                 l_flashErrorRegister >= FLASH_ERROR_COUNT0;
                 --l_flashErrorRegister)
    {
        // Reset this for every iteration, may be redundant
        l_readFlashErrorCountByte = 0;

        TRACDCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckFlashErrorCount(): "
                  "Reading NVDIMM(0x%.8X) flash error count from "
                  "register FLASH_ERROR_COUNT(0x%.4X)",
                   l_nvDimmHuid, l_flashErrorRegister);

        l_err = nvdimmReadReg(i_nvDimm,
                              static_cast<i2cReg >(l_flashErrorRegister),
                              l_readFlashErrorCountByte);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvDimmCheckFlashErrorCount(): "
                      "FAIL: NVDIMM(0x%.8X) failed to read flash error "
                      "count from register FLASH_ERROR_COUNT(0x%.4X) "
                      "marking as a fail",
                      l_nvDimmHuid, l_flashErrorRegister);

            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Set up the fail state, so caller can determine that the fail was
            // due to a register read error
            l_didFlashErrorCountCheckPass = false;
            o_readFlashErrorCount = 0;

            break;
        }

        // If we get here, then the read was successful
        // Append the read flash error count byte to the LSB of the
        // aggregated flash error count bytes.
        o_readFlashErrorCount = (o_readFlashErrorCount << 8) |
                                 l_readFlashErrorCountByte;

        TRACDCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckFlashErrorCount(): "
                  "NVDIMM(0x%.8X) returned value (0x%.2X) from the "
                  "partial flash error count, register "
                  "FLASH_ERROR_COUNT(0x%.4X)",
                  l_nvDimmHuid,
                  l_readFlashErrorCountByte,
                  l_flashErrorRegister);

    }  // end for (int16_t l_flashErrorRegister = FLASH_ERROR_COUNT2; ...

    // If o_readFlashErrorCount is not zero, then register read was successful
    if (o_readFlashErrorCount)
    {
        TRACDCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckFlashErrorCount(): "
                  "NVDIMM(0x%.8X) flash error count = %d ",
                   l_nvDimmHuid, o_readFlashErrorCount);

        // Check the validity of the flash error count
        if (o_readFlashErrorCount > i_maxFlashErrorsAllowed)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvDimmCheckFlashErrorCount(): "
                   "FAIL: For NVDIMM (0x%.8X), the flash error count (%d), "
                   "read from registers FLASH_ERROR_COUNT0(0x%.4X), "
                   "FLASH_ERROR_COUNT1(0x%.4X) and FLASH_ERROR_COUNT2(0x%.4X), "
                   "exceeds the maximum number of flash "
                   "errors allowed (%d), marking this as a fail",
                   l_nvDimmHuid,
                   o_readFlashErrorCount,
                   FLASH_ERROR_COUNT0,
                   FLASH_ERROR_COUNT1,
                   FLASH_ERROR_COUNT2,
                   i_maxFlashErrorsAllowed);

            // Set up the fail state, so caller can determine that the fail was
            // due to error count exceeding the max errors allowed.
            // Note: Leave the value in o_readFlashErrorCount so caller
            // can inspect, if they wish
            l_didFlashErrorCountCheckPass = false;
        }
        else
        {
            TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmCheckFlashErrorCount(): "
                      "SUCCESS: For NVDIMM(0x%.8X), the flash error counts "
                      "(%d) is less than or meets the maximum number of "
                      "errors allowed (%d), marking this as a pass",
                      l_nvDimmHuid,
                      o_readFlashErrorCount,
                      i_maxFlashErrorsAllowed);

            // Set up the pass state
            // Note: Leave the value in o_readFlashErrorCount so caller
            // can inspect, if they wish
            l_didFlashErrorCountCheckPass = true;
        }
    } // end if (o_readFlashErrorCount)

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmCheckFlashErrorCount(): "
              "Returning %s",
              l_didFlashErrorCountCheckPass == true ? "true" : "false" );

    return l_didFlashErrorCountCheckPass;
}

/*
 * @brief Check the NVM (non-volatile memory)/flash health of the individual
 *        NVDIMMs supplied in list.
 *
 * @param[in] i_nvdimmTargetList - list of NVDIMMs to check the health of flash
 *
 * @return false if one or more NVDIMMs fail NVM health check, else true
 */
bool nvDimmNvmCheckHealthStatus(const TargetHandleList &i_nvDimmTargetList)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmNvmCheckHealthStatus(): "
              "Target list size(%d)", i_nvDimmTargetList.size());

    // The following maximums are the same values used by SMART's
    // manufacturing and recommended that we use.
    // The maximum percentage of bad flash blocks
    // Fail if over 19% of bad flash blocks is encountered
    const uint8_t MAXIMUM_PERCENTAGE_OF_BAD_FLASH_BLOCKS_ALLOWED = 19;
    // The maximum number of flash memory errors allowed
    // Fail if over 300 flash memory errors is encountered
    const uint32_t MAXIMUM_NUMBER_OF_FLASH_MEMORY_ERRORS_ALLOWED = 300;

    // Status of the accumulation of all calls related to the NVM health check.
    // If any one call is bad/fails, then this will be false, else it stays true
    bool l_didNvmHealthCheckPass(true);

    // Handle to catch any errors
    errlHndl_t l_err(nullptr);

    // The retrieved flash block percentage from register
    uint8_t  l_badFlashBlockPercentage(0);
    // The retrieved flash error count from register
    uint32_t l_flashErrorCount(0);

    // The status of the checks on the percentage of bad blocks and
    // flash error count
    // Default to true
    bool l_badFlashBlockPercentageCheckPassed(true);
    bool l_flashErrorCountCheckPassed(true);

    // Iterate thru the supplied NVDIMMs checking the health of the NVM
    for (auto const l_nvDimm : i_nvDimmTargetList)
    {
        // Cache the HUID of the NVDIMM
        uint32_t l_nvDimmHuid = get_huid( l_nvDimm );

        // Reset these for every NVDIMM that is checked
        l_badFlashBlockPercentage = 0;
        l_flashErrorCount = 0;
        l_badFlashBlockPercentageCheckPassed = true;
        l_flashErrorCountCheckPassed = true;

        // Check the validity of bad flash block percentage
        if (!nvDimmCheckBadFlashBlockPercentage(
                                l_nvDimm,
                                MAXIMUM_PERCENTAGE_OF_BAD_FLASH_BLOCKS_ALLOWED,
                                l_badFlashBlockPercentage))
        {
            // Set this to false to indicate that the overall check on the
            // NVDIMMs had at least one failure
            l_didNvmHealthCheckPass = false;

            // If no data in the variable l_badFlashBlockPercentage, then
            // this is a read register fail.  Move onto the next NVDIMM
            // this is a dud
            if (!l_badFlashBlockPercentage)
            {
                continue;
            }

            // Set the check to false, to facilitate error reporting
            l_badFlashBlockPercentageCheckPassed = false;
        }

        // Check the validity of the flash error count
        if (!nvDimmCheckFlashErrorCount(
                                l_nvDimm,
                                MAXIMUM_NUMBER_OF_FLASH_MEMORY_ERRORS_ALLOWED,
                                l_flashErrorCount))
        {
            // Set this to false to indicate that the overall check on the
            // NVDIMMs had at least one failure
            l_didNvmHealthCheckPass = false;

            // If no data in the variable l_flashErrorCount, then
            // this is a read register fail.  Move onto the next NVDIMM
            // this is a dud
            if (!l_flashErrorCount)
            {
                continue;
            }

            // Set the check to false, to facilitate error reporting
            l_flashErrorCountCheckPassed = false;
        }

        /// Now we assess the health of the flash based on data gathered above
        if ( !l_badFlashBlockPercentageCheckPassed ||
             !l_flashErrorCountCheckPassed )
        {
            // First set the NVDIMM HUID to the first 32 bits of user data 1
            uint64_t l_badFlashBlockPercentageUserData1 =
                                          TWO_UINT32_TO_UINT64(l_nvDimmHuid, 0);

            // If an issue with the bad flash block percentage, then append
            // data to user data 1
            if (!l_badFlashBlockPercentageCheckPassed &&
                 l_badFlashBlockPercentage)
            {
                // Setting the HUID here is redundant but easier than trying to
                // do some clever code that will set the HUID for user data 1
                // when this path is not taken, but the next check on the flash
                // error count is taken
                l_badFlashBlockPercentageUserData1 =
                              TWO_UINT32_TO_UINT64(l_nvDimmHuid,
                              TWO_UINT16_TO_UINT32(
                               l_badFlashBlockPercentage,
                               MAXIMUM_PERCENTAGE_OF_BAD_FLASH_BLOCKS_ALLOWED));
            }

            // If an issue with the flash error count, then set user
            // data 2 to contain the flash error count value
            uint64_t l_flashErrorCountUserData2(0);
            if (!l_flashErrorCountCheckPassed &&
                 l_flashErrorCount)
            {
                l_flashErrorCountUserData2 =
                                TWO_UINT32_TO_UINT64(l_flashErrorCount,
                                MAXIMUM_NUMBER_OF_FLASH_MEMORY_ERRORS_ALLOWED);
            }

            /*@
             * @errortype
             * @severity         ERRL_SEV_PREDICTIVE
             * @moduleid         NVDIMM_NVM_HEALTH_CHECK
             * @reasoncode       NVDIMM_NVM_HEALTH_CHECK_FAILED
             * @userdata1[0:31]  HUID of NVDIMM target
             * @userdata1[32:47] The retrieved bad flash block percentage,
             *                   if error with, else 0
             * @userdata1[48:63] The maximum percentage of bad flash blocks
             *                   allowed, if bad flash block percentage
             *                   exceeds this maximum, else 0
             * @userdata2[0:31]  The retrieved flash error count,
             *                   if error with, else 0
             * @userdata2[32:63] The maximum number of flash errors
             *                   allowed, if flash error exceeds this
             *                   maximum, else 0
             * @devdesc          Either the NVDIMM NVM bad flash block
             *                   percentage exceeded the maximum percentage
             *                   allowed or the NVDIMM NVM number of flash
             *                   error exceeds the maximum count allowed
             *                   or both.
             * @custdesc         NVDIMM NVM health check failed.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_NVM_HEALTH_CHECK,
                                   NVDIMM_NVM_HEALTH_CHECK_FAILED,
                                   l_badFlashBlockPercentageUserData1,
                                   l_flashErrorCountUserData2,
                                   ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);
            nvdimmAddVendorLog(l_nvDimm, l_err);

            // Add a DIMM callout
            l_err->addHwCallout( l_nvDimm,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );

            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);

            // Let the caller know something went amiss
            l_didNvmHealthCheckPass = false;
        }
        else
        {
            // This NVDIMM passed the NVM health check
            TRACFCOMP(g_trac_nvdimm, INFO_MRK"nvDimmNvmCheckHealthStatus(): "
                      "Success: NVDIMM (0x%.8X) passed the NVM health check.",
                      l_nvDimmHuid);
        } // end if ( !l_badFlashBlockPercentageCheckPassed  .. else
    }  // end for (auto const l_nvdimm : i_nvdimmTargetList)

    // Should not have any uncommitted errors
    assert(l_err == NULL, "nvDimmNvmCheckHealthStatus() - unexpected "
                          "uncommitted error found");

    TRACFCOMP(g_trac_nvdimm,EXIT_MRK"nvDimmNvmCheckHealthStatus(): Returning %s",
              l_didNvmHealthCheckPass == true ? "true" : "false" );

    return l_didNvmHealthCheckPass;
}  // end nvDimmNvmCheckHealthStatus

/**
 * @brief A wrapper around the call to nvDimmNvmCheckHealthStatus
 *
 * @see nvDimmNvmCheckHealthStatus for more details
 *
 * @return false if one or more NVDIMMs fail an NVM health check, else true
 */
bool nvDimmNvmCheckHealthStatusOnSystem()
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvDimmNvmCheckHealthStatusOnSystem()");

    // Get the list of NVDIMM Targets from the system
    TargetHandleList l_nvDimmTargetList;
    nvdimm_getNvdimmList(l_nvDimmTargetList);

    // Return status of doing a check health status
    bool l_didNvmHealthCheckPass = nvDimmNvmCheckHealthStatus(l_nvDimmTargetList);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvDimmNvmCheckHealthStatusOnSystem(): "
            "Returning %s", l_didNvmHealthCheckPass == true ? "true" : "false" );

    return l_didNvmHealthCheckPass;
}  // end nvDimmCheckHealthStatusOnSystem


/**
 * @brief Send NV_STATUS to host
 */
void nvdimmSendNvStatus()
{
    // Send NV_STATUS for all nvdimms
    TargetHandleList l_nvdimmTargetList;
    nvdimm_getNvdimmList(l_nvdimmTargetList);
    for (const auto & l_nvdimm : l_nvdimmTargetList)
    {
        errlHndl_t l_err = nullptr;
        l_err = notifyNvdimmProtectionChange(l_nvdimm,SEND_NV_STATUS);
        if (l_err)
        {
            errlCommit(l_err, NVDIMM_COMP_ID);
        }
    }
}

/**
 * @brief Collect the Lifetime Percentage from the BPM for every NDIMM
 *        and send it to PHYP
 */
void nvdimm_stats( void )
{
    errlHndl_t l_err = nullptr;

    // There are 2 unique interactions to accomplish this task.
    // 1) PHYP calls firmware_notify(HBRT_FW_MSG_TYPE_NVDIMM_STATS) which
    //    triggers this function call.
    // 2) Hostboot calls firmware_request(HBRT_FW_MSG_TYPE_NVDIMM_STATS)
    //    to send the data back to PHYP as there is no response buffer
    //    defined as part of firmware_notify.

    // Create the firmware_request request struct to send data back
    hostInterfaces::hbrt_fw_msg l_req_msg;
    memset(&l_req_msg, 0, sizeof(l_req_msg));  // clear it all
    l_req_msg.io_type = hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_STATS;

    // actual msg size (one type of hbrt_fw_msg)
    uint64_t l_req_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
      sizeof(l_req_msg.nvdimm_stats);

    // get the list possible nvdimm slots
    Target* l_sys = nullptr;
    targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "nvdimm_stats: no TopLevelTarget");
    ATTR_MSS_MRW_NVDIMM_PLUG_RULES_type l_slots =
      l_sys->getAttr<ATTR_MSS_MRW_NVDIMM_PLUG_RULES>();

    // special value to use when there is no data
    constexpr uint8_t NODATA = 0xEE;
    // set all status values to uninstalled and no data
    for( uint8_t i = 0; i < sizeof(l_req_msg.nvdimm_stats.bpmLifetime); i++ )
    {
        l_req_msg.nvdimm_stats.bpmLifetime[i] = NODATA;
    }
    for( uint8_t i = 0; i < sizeof(l_req_msg.nvdimm_stats.dimmInstalled); i++ )
    {
        l_req_msg.nvdimm_stats.dimmInstalled[i] = 0;
    }

    // Get the list of functional NVDIMM Targets from the system
    TargetHandleList l_nvdimmTargetList;
    nvdimm_getNvdimmList(l_nvdimmTargetList);

    for (const auto & l_nvdimm : l_nvdimmTargetList)
    {
        // The index into the data structures will match the relative
        //  position of this dimm among the complete list of possible
        //  nvdimm slots.
        ATTR_MSS_MRW_NVDIMM_SLOT_POSITION_type l_myslot =
          l_nvdimm->getAttr<ATTR_MSS_MRW_NVDIMM_SLOT_POSITION>();
        uint8_t l_mypos = 0xFF;
        constexpr size_t l_totalbits = (sizeof(l_slots)*8);
        // walk through each bit until we find the one for us
        for( size_t i = 0; i<l_totalbits; i++ )
        {
            ATTR_MSS_MRW_NVDIMM_PLUG_RULES_type curslotbit = 1;
            curslotbit = curslotbit << (l_totalbits-i-1);

            // if bit is set then this is a valid nvdimm slot
            if( curslotbit & l_slots )
            {
                if( l_mypos == 0xFF ) //first one
                {
                    l_mypos = 0;
                }
                else
                {
                    l_mypos++;
                }
            }

            // jump out when we find my slot
            if( i == l_myslot )
            {
                break;
            }
        }
        if( l_mypos > sizeof(hostInterfaces::nvdimm_stats_t::bpmLifetime) )
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimm_stats(): Invalid dimm slot (=%d) for %.8X : SLOT_POSITION=%d, PLUG_RULES=%.16llX",
                       l_mypos,
                       TARGETING::get_huid(l_nvdimm),
                       l_myslot,
                       l_slots );
            /*@
             * @errortype
             * @moduleid         NVDIMM_STATS
             * @reasoncode       NVDIMM_INVALID_DIMM_SLOT
             * @userdata1[0:31]  HUID of NVDIMM target
             * @userdata1[32:47] Computed relative position
             * @userdata1[48:63] Slot position of this dimm
             * @userdata2        Possible nvdimm slots
             * @devdesc          Could not compute a valid relative
             *                   position for this NVDIMM, needed
             *                   to fill in nvdimm_stats data.
             * @custdesc         Software error communicating NVDIMM statistics.
             */
            l_err = new ErrlEntry( ERRL_SEV_PREDICTIVE,
                                   NVDIMM_STATS,
                                   NVDIMM_INVALID_DIMM_SLOT,
                                   TWO_UINT32_TO_UINT64(
                                     TARGETING::get_huid(l_nvdimm),
                                     TWO_UINT16_TO_UINT32(l_mypos,l_myslot)
                                   ),
                                   l_slots,
                                   ErrlEntry::ADD_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Add a DIMM callout
            l_err->addHwCallout( l_nvdimm,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );

            // Collect the error
            errlCommit(l_err, NVDIMM_COMP_ID);
            continue; // move on to the next nvdimm
        }

        // Mark the nvdimm as installed
        l_req_msg.nvdimm_stats.dimmInstalled[l_mypos] = 1;

        // The lifetime percentage
        uint8_t l_lifetimePercentage(0);

        // Retrieve the Lifetime Percentage from the BPM
        l_err = nvdimmReadReg(l_nvdimm, ES_LIFETIME, l_lifetimePercentage);
        if (l_err)
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimm_stats(): NVDIMM(0x%.8X) failed to read the ES_LIFETIME(0x%.2X) data",
                       get_huid(l_nvdimm),
                       ES_LIFETIME );

            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);
            continue; //data already defaults to invalid
        }

        l_req_msg.nvdimm_stats.bpmLifetime[l_mypos] = l_lifetimePercentage;
    }

    // Create the firmware_request response struct to receive data
    hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
    uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
    memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

    // Make the firmware_request call
    l_err = firmware_request_helper(l_req_msg_size,
                                    &l_req_msg,
                                    &l_resp_fw_msg_size,
                                    &l_resp_fw_msg);
    if (l_err)
    {
        TRACFCOMP( g_trac_nvdimm, ERR_MRK"nvdimm_stats(): Error sending firmware_request" );
        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit(l_err, NVDIMM_COMP_ID);
    }
}

struct registerNvdimmRt
{
    registerNvdimmRt()
    {
        // Register function to call at end of RT init
        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callSendNvStatus = &nvdimmSendNvStatus;
    }
};

registerNvdimmRt g_registerNvdimmRt;

} // end NVDIMM namespace
