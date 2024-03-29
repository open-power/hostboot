/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatCallout.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
 *  @file hwasPlatCallout.C
 *
 *  @brief Platform Callout specific functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/hwasPlat.H>
#include <initservice/initserviceif.H>
#include <targeting/targplatutil.H>

using namespace TARGETING;

namespace HWAS
{

errlHndl_t platHandleProcedureCallout(
        errlHndl_t &io_errl,
        epubProcedureID i_procedure,
        callOutPriority i_priority)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    //  processCallouts() function also changes, as today it (errlentry.C) calls
    //  from the errlEntry object

    errlHndl_t errl = NULL;

    // hostboot does not handle or do any action for procedure callouts
    return errl;
}

errlHndl_t platHandleHWCallout(
        TARGETING::Target *i_pTarget,
        callOutPriority i_priority,
        DeconfigEnum    i_deconfigState,
        errlHndl_t     &io_errl,
        GARD_ErrorType  i_gardErrorType)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    //  processCallouts() function also changes, as today it (errlentry.C) calls
    //  from the errlEntry object

    errlHndl_t errl = nullptr;

#ifdef CONFIG_RECALL_DECONFIG_ON_RECONFIG
    GARD_ErrorType gardDeconfig = getEphmeralGardRecordType();
#endif

    HWAS_INF("HW callout; pTarget HUID 0x%8X, gardErrorType 0x%X, deconfigState 0x%X",
            TARGETING::get_huid(i_pTarget), i_gardErrorType, i_deconfigState);

    // grab the bootproc target to use below
    TARGETING::Target* l_masterProc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(l_masterProc);

    // On FSP boxes we need to avoid deconfiguring the boot
    // processor because it will break the FSP's ability to
    // analyze our TI.
    bool l_skipDeconfig = false;
#ifdef CONFIG_FSP_BUILD
    if( i_pTarget == l_masterProc )
    {
        l_skipDeconfig = true;
    }
#endif //#ifdef CONFIG_FSP_BUILD

    if (hwasPLDDetection())
    {
        HWAS_INF("hwasPLDDetection return true - skipping callouts");
    }
    else if ((io_errl->sev()) == (ERRORLOG::ERRL_SEV_INFORMATIONAL))
    {
        HWAS_INF("Error log is informational - skipping callouts");
    }
    else
    {
        switch (i_gardErrorType)
        {
            case (GARD_NULL):
            {   // means no GARD operations
                break;
            }
            default:
            {

#ifndef CONFIG_NO_GARD_SUPPORT
                errl = HWAS::theDeconfigGard()
                  .platCreateGardRecord(i_pTarget,
                                        io_errl->eid(),
                                        i_gardErrorType);

#elif CONFIG_RECALL_DECONFIG_ON_RECONFIG

                //If Gard is turned off, always populate a reconfig type
                //in case of a reconfig loop
                errl = HWAS::theDeconfigGard()
                  .platCreateGardRecord(i_pTarget,
                                        io_errl->eid(),
                                        gardDeconfig);
#endif
                break;
            }
        } // switch i_gardErrorType

        switch (i_deconfigState)
        {
            case (NO_DECONFIG):
            {
                break;
            }
            case (DECONFIG):
            {
                if( l_skipDeconfig )
                {
                    HWAS_ERR("Skipping boot proc deconfig - Shutdown due to plid 0x%X",
                             io_errl->eid());
                }
                else
                {
                    // call HWAS common function
                    errl = HWAS::theDeconfigGard()
                      .deconfigureTarget(*i_pTarget,
                                          io_errl->eid());
                }

#ifdef CONFIG_RECALL_DECONFIG_ON_RECONFIG
                //Always force a gard record on deconfig
                if(!errl)
                {
                    errl = HWAS::theDeconfigGard()
                      .platCreateGardRecord(i_pTarget,
                                            io_errl->eid(),
                                            gardDeconfig);
                }
#endif
                break;
            }
            case (DELAYED_DECONFIG):
            {
#ifdef CONFIG_RECALL_DECONFIG_ON_RECONFIG
                //Always force a gard record on deconfig
                errl = HWAS::theDeconfigGard()
                  .platCreateGardRecord(i_pTarget,
                                        io_errl->eid(),
                                        gardDeconfig);
#endif
                break;
            }
        } // switch i_deconfigState
    } // PLD

    return errl;
}

errlHndl_t platHandleAddBusCallout( HWAS::busCallout_t &io_busCallout,
                                    errlHndl_t &io_errl)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    //  processCallouts() function also changes, as today it (errlentry.C) calls
    //  from the errlEntry object

    errlHndl_t errl = NULL;

    // hostboot does not handle or do any action for bus callouts
    return errl;
}

errlHndl_t platHandleI2cDeviceCallout(
        TARGETING::Target *i_i2cMaster,
        uint8_t i_engine,
        uint8_t i_port,
        uint8_t i_address,
        callOutPriority i_priority,
        errlHndl_t &io_errl)
{
    errlHndl_t errl = nullptr;

    // hostboot handling is done in ERRORLOG::addI2cDeviceCallout function
    return errl;
}

errlHndl_t platHandleClockCallout(
        TARGETING::Target* const i_pTarget,
        const clockTypeEnum i_clockType,
        const callOutPriority i_priority,
        errlHndl_t &io_errl,
        const DeconfigEnum i_deconfigState,
        const GARD_ErrorType i_gardErrorType)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    // processCallouts() function also changes, as today it (errlentry.C) calls
    // from the errlEntry object

    if (io_errl->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
    { // Don't do anything when the error is just informational
#ifdef CONFIG_CLOCK_DECONFIGS_FATAL
        // If clock deconfigs are considered fatal, and deconfig requested, then
        // call doShutdown
        if(i_deconfigState == DECONFIG)
        {
            HWAS_INF(
                "Clock deconfiguration considered fatal, requesting "
                "shutdown.  See PLID = 0x%X for details.",
                io_errl->eid());
            INITSERVICE::doShutdown(io_errl->eid(), true);
        }
#endif

        // Since we don't have a real target for the clocks we won't trigger
        // a reconfig loop automatically when a clock is marked for deconfig.
        // To emulate that behavior we will manually set the flag that is
        // checked at the end of each istep.
        if( NO_DECONFIG != i_deconfigState )
        {
            HWAS_INF("Triggering reconfig loop for attempted clock deconfig");

            // Force a reconfig loop so the SP picks up our current
            //  HWAS_STATE and chooses a better boot core.
            setOrClearReconfigLoopReason(ReconfigSetOrClear::RECONFIG_SET,
                                         RECONFIGURE_LOOP_DECONFIGURE);
        }
        // Note: On eBMC systems this is the only way the IPL would be stopped.
        //  On FSP systems HWSV will stop the IPL and do a reconfig loop but
        //  there would be a race without this setting.  Hostboot would continue
        //  IPLing so we could run additional isteps and see extra errors due to
        //  the clock issue.
    }

    return nullptr;
}

errlHndl_t platHandlePartCallout(
        TARGETING::Target *i_pTarget,
        partTypeEnum i_partType,
        callOutPriority i_priority,
        errlHndl_t &io_errl,
        DeconfigEnum i_deconfigState,
        GARD_ErrorType i_gardErrorType)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    // processCallouts() function also changes, as today it (errlentry.C) calls
    // from the errlEntry object

    errlHndl_t errl = NULL;

    // Hostboot does not handle or do any action for part callouts
    return errl;
}


} // namespace HWAS
