/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_update_ucd_flash.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <util/utillidmgr.H>
#include <util/utilmclmgr.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <initservice/isteps_trace.H>
#include <isteps/ucd/updateUcdFlash.H>
#include <secureboot/trustedbootif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <util/utilmem.H>
#include <util/misc.H>
#include <isteps/istep_reasoncodes.H>
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
    if (INITSERVICE::spBaseServicesEnabled() &&
        !Util::isSimicsRunning())
    {
        TARGETING::TargetHandleList powerSequencers;
        TARGETING::getAllAsics(powerSequencers,
                               TARGETING::TYPE_POWER_SEQUENCER,true);
        if(powerSequencers.empty())
        {
            // Continue if no functional power sequencers.  On MPIPL,
            // previously bad power sequencers will be ignored, and
            // Hostboot will not generate new errors.
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,INFO_MRK
                "call_update_ucd_flash: No functional UCD9090 or UCD90120A "
                "power sequencers found to update");

            // Done with update flow, no error
            break;
        }

        // Load the UCD flash binary via the MCL in load only mode
        MCL::MasterContainerLidMgr mclManager(true);
        MCL::CompInfo info;
        pError = mclManager.processSingleComponent(MCL::g_UcdCompId,info);
        if(pError)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                "call_update_ucd_flash: Failed in call to "
                "processSingleComponent() for UCD9090 "
                "component ID");

            // Failed update flow, commit at end of step
            break;
        }

        // Make sure TPM queue is flushed before doing any SPI operations, since
        // loading via MCL drives PCR extends into the TPM
        pError = TRUSTEDBOOT::flushTpmQueue();
        if(pError)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                "call_update_ucd_flash: Failed in call to "
                "TRUSTEDBOOT::flushTpmQueue()");

            // Failed update flow, commit at end of step
            break;
        }

        // Dump some LID info
        for(const auto& lid : info.lidIds)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"LID ID=0x%08X, "
                "size=%d, vAddr=%p",
                lid.id, lid.size, lid.vAddr);
            TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,"LID",lid.vAddr,64);
        }

        // Locate the UCD flash image (ignore signature LID and any other LIDs
        // in the container)
        const auto lidItr =
            std::find_if(
                info.lidIds.begin(),info.lidIds.end(),
                [](const MCL::LidInfo& i_lid)
                {
                    return (i_lid.id == static_cast<decltype(i_lid.id)>(
                                            Util::UCD_LIDID));
                });
        if(lidItr == info.lidIds.end())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                "call_update_ucd_flash: Failed to locate UCD flash image LID "
                "within UCD9090 component");

            /*@
             * @errortype
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @reasoncode ISTEP::RC_UCD_IMG_NOT_IN_CONTAINER
             * @moduleid   ISTEP::MOD_CALL_UPDATE_UCD_FLASH
             * @userdata1  UCD LID ID
             * @devdesc    The UCD content LID was not found within the UCD
             *     container
             * @custdesc   Unexpected IPL firmware data load error
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP::MOD_CALL_UPDATE_UCD_FLASH,
                ISTEP::RC_UCD_IMG_NOT_IN_CONTAINER,
                Util::UCD_LIDID,
                0,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            // Failed update flow, commit at end of step
            break;
        }

        // Use a UtilMem buffer to prevent sailing off end of the UCD flash
        // data.  Callee will seek back to beginning of content
        UtilMem image(lidItr->vAddr,lidItr->size);

        pError = updateAllUcdFlashImages(powerSequencers,image);
        if(pError)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                "call_update_ucd_flash: Failed in call to "
                "updateAllUcdFlashImages");
            break;
        }

        // Destructor automatically unloads the UCD flash binary

    } // End valid machine and not-simics check for UCD updates

    } while(0);

    if(pError)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "call_update_ucd_flash: step failed");
        pError->collectTrace(UCD_COMP_NAME);
        pError->collectTrace(ISTEP_COMP_NAME);
        errlCommit(pError, ISTEP_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, EXIT_MRK
              "call_update_ucd_flash" );
}

} // End UCD namespace

} // End TI namespace

} // End POWER_SEQUENCER namespace


