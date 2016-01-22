/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedboot_base.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 * @file trustedboot_base.C
 *
 * @brief Trusted boot base interfaces
 * This file is compiled in regardless of CONFIG_TPMDD
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include "trustedboot_base.H"
#include "../trustedboot.H"
#include "../trustedbootCmds.H"
#include "../trustedbootUtils.H"
#include "tpmLogMgr.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
#ifdef CONFIG_TPMDD
trace_desc_t* g_trac_trustedboot = NULL;
TRAC_INIT( & g_trac_trustedboot, "TRBOOT", KILOBYTE );
#endif

namespace TRUSTEDBOOT
{

#ifdef CONFIG_TPMDD
/// Global object to store TPM status
SystemTpms systemTpms;

SystemTpms::SystemTpms()
{
}

TpmTarget::TpmTarget()
{
    memset(this, 0, sizeof(TpmTarget));
    available = true; // Default to available until we know better
    mutex_init(&tpmMutex);

}
#endif


errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                     uint8_t* i_digest,
                     size_t  i_digestSize,
                     const char* i_logMsg)
{
    errlHndl_t err = NULL;
#ifdef CONFIG_TPMDD
    TPM_Alg_Id algId = TPM_ALG_SHA256;

    size_t fullDigestSize = getDigestSize(algId);
    char logMsg[MAX_TPM_LOG_MSG];

    TRACDCOMP( g_trac_trustedboot, ENTER_MRK"pcrExtend()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"pcrExtend() pcr=%d msg='%s'", i_pcr, i_logMsg);
    TRACFBIN(g_trac_trustedboot, "pcrExtend() digest:", i_digest, i_digestSize);

    // Ensure proper digest size
    uint8_t digestData[fullDigestSize];
    memset(digestData, 0, sizeof(digestData));

    // copy over the incoming digest to append or truncate to what we need
    memcpy(digestData, i_digest,
           (i_digestSize < fullDigestSize ? i_digestSize : fullDigestSize));

    // Truncate logMsg if required
    memset(logMsg, 0, sizeof(logMsg));
    memcpy(logMsg, i_logMsg,
           (strlen(i_logMsg) < MAX_TPM_LOG_MSG ? strlen(i_logMsg) :
            MAX_TPM_LOG_MSG));


    for (size_t idx = 0; idx < MAX_SYSTEM_TPMS; idx++)
    {
        // Add the event to this TPM, if an error occurs the TPM will
        //  be marked as failed and the error log committed
        pcrExtendSingleTpm(systemTpms.tpm[idx],
                           i_pcr,
                           algId,
                           digestData,
                           fullDigestSize,
                           logMsg);
    }

    // Lastly make sure we are in a state where we have a functional TPM
    err = tpmVerifyFunctionalTpmExists();


    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"pcrExtend() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

#endif
    return err;
}

#ifdef CONFIG_TPMDD
void pcrExtendSingleTpm(TpmTarget & io_target,
                        TPM_Pcr i_pcr,
                        TPM_Alg_Id i_algId,
                        uint8_t* i_digest,
                        size_t  i_digestSize,
                        const char* i_logMsg)
{
    errlHndl_t err = NULL;
    TCG_PCR_EVENT2 eventLog;
    bool unlock = false;

    do
    {
        mutex_lock( &io_target.tpmMutex );
        unlock = true;

        // Allocate the TPM log if it hasn't been already
        if (!io_target.failed &&
            io_target.available &&
            NULL == io_target.logMgr)
        {
            io_target.logMgr = new TpmLogMgr;
            err = TpmLogMgr_initialize(io_target.logMgr);
            if (NULL != err)
            {
                break;
            }
        }

        // Log the event, we will do this in two scenarios
        //  - !initAttempted - prior to IPL of the TPM we log for replay
        //  - initAttempted && !failed - TPM is functional so we log
        if ((io_target.available &&
             !io_target.initAttempted) ||
            (io_target.available &&
             io_target.initAttempted &&
             !io_target.failed))
        {
            // Fill in TCG_PCR_EVENT2 and add to log
            eventLog = TpmLogMgr_genLogEventPcrExtend(i_pcr, i_algId, i_digest,
                                                      i_digestSize, i_logMsg);
            err = TpmLogMgr_addEvent(io_target.logMgr,&eventLog);
            if (NULL != err)
            {
                break;
            }
        }

        // If the TPM init has occurred and it is currently
        //  functional we will do our extension
        if (io_target.available &&
            io_target.initAttempted &&
            !io_target.failed)
        {

            err = tpmCmdPcrExtend(&io_target,
                                  i_pcr,
                                  i_algId,
                                  i_digest,
                                  i_digestSize);
            if (NULL != err)
            {
                break;
            }
        }
    } while ( 0 );

    if (NULL != err)
    {
        // We failed to extend to this TPM we can no longer use it
        tpmMarkFailed(&io_target);

        // Log this failure
        errlCommit(err, SECURE_COMP_ID);
        err = NULL;
    }

    if (unlock)
    {
        mutex_unlock(&io_target.tpmMutex);
    }
    return;
}

void tpmMarkFailed(TpmTarget * io_target)
{

    TRACFCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmMarkFailed() Marking TPM as failed : "
               "tgt=0x%X chip=%d",
               TARGETING::get_huid(io_target->nodeTarget),
               io_target->chip);

    io_target->failed = true;
    /// @todo RTC:125287 Add fail marker to TPM log and disable TPM access

}

errlHndl_t tpmVerifyFunctionalTpmExists()
{
    errlHndl_t err = NULL;
    bool foundFunctional = false;

    for (size_t idx = 0; idx < MAX_SYSTEM_TPMS; idx ++)
    {
        if (!systemTpms.tpm[idx].failed ||
            !systemTpms.tpm[idx].initAttempted)
        {
            foundFunctional = true;
            break;
        }
    }

    if (!foundFunctional)
    {
        TRACFCOMP( g_trac_trustedboot,
                   "NO FUNCTIONAL TPM FOUND");

        /*@
         * @errortype
         * @reasoncode     RC_TPM_NOFUNCTIONALTPM_FAIL
         * @severity       ERRL_SEV_UNRECOVERABLE
         * @moduleid       MOD_TPM_VERIFYFUNCTIONAL
         * @userdata1      0
         * @userdata2      0
         * @devdesc        No functional TPMs exist in the system
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_TPM_VERIFYFUNCTIONAL,
                                       RC_TPM_NOFUNCTIONALTPM_FAIL,
                                       0, 0,
                                       true /*Add HB SW Callout*/ );

        err->collectTrace( SECURE_COMP_NAME );
    }

    return err;
}

errlHndl_t tpmCreateErrorLog(const uint8_t i_modId,
                             const uint16_t i_reasonCode,
                             const uint64_t i_user1,
                             const uint64_t i_user2)
{
    errlHndl_t err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    i_modId,
                                    i_reasonCode,
                                    i_user1,
                                    i_user2,
                                    true /*Add HB SW Callout*/ );
    err->collectTrace( SECURE_COMP_NAME );
    return err;
}

#endif

} // end TRUSTEDBOOT
