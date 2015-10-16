/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include <devicefw/driverif.H>
#include <i2c/tpmddif.H>
#include <secureboot/trustedbootif.H>
#include <i2c/tpmddreasoncodes.H>
#include "trustedboot.H"
#include <secureboot/trustedboot_reasoncodes.H>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

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

        if (systemTpms.tpm[TPM_MASTER_INDEX].failed)
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
    uint8_t dataBuf[BUFSIZE];
    size_t dataSize = sizeof(dataBuf);
    size_t cmdSize = 0;

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
        io_target.failed = false;

        // Send the TPM startup command
        // Build our command block for a startup
        memset(dataBuf, 0, sizeof(dataBuf));

        TRUSTEDBOOT::TPM_BaseOut* resp =
            (TRUSTEDBOOT::TPM_BaseOut*)dataBuf;
#ifdef CONFIG_TPMDD_1_2
        TRUSTEDBOOT::TPM_2ByteIn* cmd =
            (TRUSTEDBOOT::TPM_2ByteIn*)dataBuf;

        cmd->base.tag = TRUSTEDBOOT::TPM_TAG_RQU_COMMAND;
        cmd->base.paramSize = sizeof (TRUSTEDBOOT::TPM_2ByteIn);
        cmd->base.ordinal = TRUSTEDBOOT::TPM_ORD_Startup;
        cmd->param = TRUSTEDBOOT::TPM_ST_CLEAR;
        cmdSize = cmd->base.paramSize;
#elif defined(CONFIG_TPMDD_2_0)
        TRUSTEDBOOT::TPM2_2ByteIn* cmd =
            (TRUSTEDBOOT::TPM2_2ByteIn*)dataBuf;

        cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
        cmd->base.commandSize = sizeof (TRUSTEDBOOT::TPM2_2ByteIn);
        cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_Startup;
        cmd->param = TRUSTEDBOOT::TPM_SU_CLEAR;
        cmdSize = cmd->base.commandSize;
#endif

        err = deviceRead(io_target.nodeTarget,
                         &dataBuf,
                         dataSize,
                         DEVICE_TPM_ADDRESS( io_target.chip,
                                             TPMDD::TPM_OP_TRANSMIT,
                                             cmdSize) );

        if (NULL != err)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP I2C Fail %X : ",
                       err->reasonCode() );
            break;

        }
        else if (TRUSTEDBOOT::TPM_SUCCESS != resp->returnCode)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM STARTUP OP Fail %X : ",
                       resp->returnCode);

            /*@
             * @errortype
             * @reasoncode     RC_TPM_START_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_INITIALIZE
             * @userdata1      node
             * @userdata2      returnCode
             * @devdesc        Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_INITIALIZE,
                                           RC_TPM_START_FAIL,
                                           TARGETING::get_huid(
                                              io_target.nodeTarget),
                                           resp->returnCode,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            break;
        }


    } while ( 0 );


    // If the TPM failed we will mark it not functional
    if (NULL != err)
    {
        io_target.failed = true;
        // Log this failure
        errlCommit(err, SECURE_COMP_ID);
    }

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmInitialize() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

}

} // end TRUSTEDBOOT
