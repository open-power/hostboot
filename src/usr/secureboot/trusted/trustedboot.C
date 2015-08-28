/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.C $                    */
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
 * @file trustedboot.C
 *
 * @brief Trusted boot interfaces
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
#include <targeting/common/targetservice.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include "trustedboot.H"
#include "trustedTypes.H"
#include "trustedbootCmds.H"
#include "trustedbootUtils.H"
#include "base/tpmLogMgr.H"
#include "base/trustedboot_base.H"

namespace TRUSTEDBOOT
{

extern SystemTpms systemTpms;

void* host_update_master_tpm( void *io_pArgs )
{
    errlHndl_t err = NULL;
    bool unlock = false;

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"host_update_master_tpm()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"host_update_master_tpm()");

    do
    {

        // Get a node Target
        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target* nodeTarget = NULL;
        tS.getMasterNodeTarget( nodeTarget );

        if (nodeTarget == NULL)
            break;

        // Skip this target if target is non-functional
        if(!nodeTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().  \
           functional)
        {
            continue;
        }

        mutex_lock( &(systemTpms.tpm[TPM_MASTER_INDEX].tpmMutex) );
        unlock = true;

        if (!systemTpms.tpm[TPM_MASTER_INDEX].failed &&
            TPMDD::tpmPresence(nodeTarget, TPMDD::TPM_PRIMARY))
        {
            // Initialize the TPM, this will mark it as non-functional on fail
            tpmInitialize(systemTpms.tpm[TPM_MASTER_INDEX],
                          nodeTarget,
                          TPMDD::TPM_PRIMARY);

        }
        else
        {
            systemTpms.tpm[TPM_MASTER_INDEX].available = false;
        }

        // Allocate the TPM log if it hasn't been already
        if (!systemTpms.tpm[TPM_MASTER_INDEX].failed &&
            systemTpms.tpm[TPM_MASTER_INDEX].available &&
            NULL == systemTpms.tpm[TPM_MASTER_INDEX].logMgr)
        {
            systemTpms.tpm[TPM_MASTER_INDEX].logMgr = new TpmLogMgr;
            err = TpmLogMgr_initialize(
                        systemTpms.tpm[TPM_MASTER_INDEX].logMgr);
            if (NULL != err)
            {
                break;
            }
        }

        // Now we need to replay any existing entries in the log into the TPM
        tpmReplayLog(systemTpms.tpm[TPM_MASTER_INDEX]);

        if (systemTpms.tpm[TPM_MASTER_INDEX].failed ||
            !systemTpms.tpm[TPM_MASTER_INDEX].available)
        {

            /// @todo RTC:134913 Switch to backup chip if backup TPM avail

            // Master TPM not available
            TRACFCOMP( g_trac_trustedboot,
                       "Master TPM Existence Fail");

            /*@
             * @errortype
             * @reasoncode     RC_TPM_EXISTENCE_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_HOST_UPDATE_MASTER_TPM
             * @userdata1      node
             * @userdata2      0
             * @devdesc        No TPMs found in system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_HOST_UPDATE_MASTER_TPM,
                                           RC_TPM_EXISTENCE_FAIL,
                                           TARGETING::get_huid(nodeTarget),
                                           0,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            break;
        }


        // Lastly we will check on the backup TPM and see if it is enabled
        //  in the attributes at least
        TPMDD::tpm_info_t tpmInfo;
        tpmInfo.chip = TPMDD::TPM_BACKUP;
        err = TPMDD::tpmReadAttributes(nodeTarget, tpmInfo);
        if (NULL != err)
        {
            // We don't want to log this error we will just assume
            //   the backup doesn't exist
            delete err;
            err = NULL;
            TRACUCOMP( g_trac_trustedboot,
                       "host_update_master_tpm() tgt=0x%X "
                       "Marking backup TPM unavailable due to attribute fail",
                       TARGETING::get_huid(nodeTarget));
            systemTpms.tpm[TPM_BACKUP_INDEX].available = false;
            break;
        }
        else if (!tpmInfo.tpmEnabled)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "host_update_master_tpm() tgt=0x%X "
                       "Marking backup TPM unavailable",
                       TARGETING::get_huid(nodeTarget));
            systemTpms.tpm[TPM_BACKUP_INDEX].available = false;
        }

    } while ( 0 );

    if( unlock )
    {
        mutex_unlock(&(systemTpms.tpm[TPM_MASTER_INDEX].tpmMutex));
    }


    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"host_update_master_tpm() - %s",
               ((NULL == err) ? "No Error" : "With Error") );
    return err;
}


void tpmInitialize(TRUSTEDBOOT::TpmTarget & io_target,
                   TARGETING::Target* i_nodeTarget,
                   TPMDD::tpm_chip_types_t i_chip)
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize() tgt=0x%X chip=%d",
               TARGETING::get_huid(io_target.nodeTarget),
               io_target.chip);

    do
    {

        // TPM Initialization sequence

        io_target.nodeTarget = i_nodeTarget;
        io_target.chip = i_chip;
        io_target.initAttempted = true;
        io_target.available = true;
        io_target.failed = false;

        // TPM_STARTUP
        err = tpmCmdStartup(&io_target);
        if (NULL != err)
        {
            break;
        }

        // TPM_GETCAPABILITY to read FW Version
        err = tpmCmdGetCapFwVersion(&io_target);
        if (NULL != err)
        {
            break;
        }


    } while ( 0 );


    // If the TPM failed we will mark it not functional
    if (NULL != err)
    {
        tpmMarkFailed(&io_target);
        // Log this failure
        errlCommit(err, SECURE_COMP_ID);
    }

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmInitialize()");
}

void tpmReplayLog(TRUSTEDBOOT::TpmTarget & io_target)
{
    ///@todo RTC:125288 Implement replay
    // Function will walk existing entries in the TPM log and call
    //   tpmCmdPcrExtend as required
    // This function must commit any errors and call tpmMarkFailed if errors
    //   are found
}


} // end TRUSTEDBOOT
