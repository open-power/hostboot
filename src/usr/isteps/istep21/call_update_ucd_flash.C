/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_update_ucd_flash.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#include <errl/errlentry.H>
#include <trace/interface.H>
#include <initservice/initserviceif.H>
#include <util/utilmclmgr.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <config.h>
#include <initservice/isteps_trace.H>
#include <isteps/ucd/updateUcdFlash.H>
#include <secureboot/trustedbootif.H>
#include "call_update_ucd_flash.H"

namespace POWER_SEQUENCER
{

namespace TI
{

namespace UCD
{

void call_update_ucd_flash(void)
{
    errlHndl_t pError = nullptr;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK
              "call_update_ucd_flash");

    do {

    // Update UCD flash images, if needed
    if (INITSERVICE::spBaseServicesEnabled())
    {
        // @TODO RTC 201991
        // break early if no UCD devices

        // Load the UCD flash binary via the MCL in load only mode
        MCL::MasterContainerLidMgr mclManager(true);
        MCL::CompInfo info;
        pError = mclManager.processSingleComponent(MCL::g_UcdCompId,info);
        if(pError)
        {
            break;
        }

        // Make sure TPM queue is flushed before doing any I2C operations
        TRUSTEDBOOT::flushTpmQueue();

        // @TODO RTC 201990 add flash update algorithm and make trace TRACDBIN
        // call into:
        //
        // errlHndl_t updateUcdFlash(
        //     TARGETING::Target* i_pUcd,
        //     const void*        i_pFlashImage);
        for(const auto& lid : info.lidIds)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"LID ID=0x%08X, "
                "size=%d, vAddr=%p",
                lid.id, lid.size, lid.vAddr);
            TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,"LID",lid.vAddr,64);
        }

        // Destructor automatically unloads the UCD flash binary
    }

    } while(0);

    if(pError)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "call_update_ucd_flash failed");
        errlCommit(pError, ISTEP_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, EXIT_MRK
              "call_update_ucd_flash" );
}

} // End UCD namespace

} // End TI namespace

} // End POWER_SEQUENCER namespace


