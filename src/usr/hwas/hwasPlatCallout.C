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

using namespace TARGETING;

namespace HWAS
{

//******************************************************************************
// platHandleProcedureCallout
//******************************************************************************
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

//******************************************************************************
// platHandleHWCallout
//******************************************************************************
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
    ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig = isBlockSpecDeconfigSetOnAnyNode();

    GARD_ErrorType gardDeconfig = GARD_Reconfig;
    // For eBMC systems, if we are in block speculative deconfig mode,
    // set the GARD_ErrorType to Sticky to treat deconfigs as
    // unrecoverable gards on the next reconfig loop,
    // otherwise set as normal GARD_Reconfig
    if (!INITSERVICE::spBaseServicesEnabled() && l_block_spec_deconfig)
    {
        HWAS_DBG("setting GARD_Sticky_deconfig for the Deconfig Gard");
        gardDeconfig = GARD_Sticky_deconfig;
    }
    else
    {
        HWAS_DBG("setting GARD_Reconfig for the Deconfig Gard");
    }

    HWAS_INF("HW callout; pTarget HUID 0x%8X, gardErrorType 0x%X, deconfigState 0x%X, ATTR_BLOCK_SPEC_DECONFIG=%d",
            TARGETING::get_huid(i_pTarget), i_gardErrorType, i_deconfigState, l_block_spec_deconfig);
#else
    HWAS_INF("HW callout; pTarget HUID 0x%8X, gardErrorType 0x%X, deconfigState 0x%X",
            TARGETING::get_huid(i_pTarget), i_gardErrorType, i_deconfigState);
#endif
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

        // check to see if this target is the master processor
        //  and if it's being deconfigured.
        //  NOTE: will be non-functional early in IPL before discovery complete.
        if ( (i_pTarget == l_masterProc) &&
             (NO_DECONFIG != i_deconfigState) )
        {
            const TARGETING::HwasState hwasState =
                    l_masterProc->getAttr<TARGETING::ATTR_HWAS_STATE>();
            // we either deconfigured the proc or we should have but
            // explicitly decided not too, either way we need to kill
            // the boot
            if (!hwasState.functional || l_skipDeconfig)
            {
                HWAS_ERR("master proc deconfigured - Shutdown due to plid 0x%X",
                        io_errl->eid());
                INITSERVICE::doShutdown(io_errl->eid(), true);
            }
        }
    } // PLD

    return errl;
}

//******************************************************************************
// platHandleAddBusCallout
//******************************************************************************
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

//******************************************************************************
// platHandleI2cDeviceCallout
//******************************************************************************
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

//******************************************************************************
// platHandleClockCallout
//******************************************************************************
errlHndl_t platHandleClockCallout(
        TARGETING::Target *i_pTarget,
        clockTypeEnum i_clockType,
        callOutPriority i_priority,
        errlHndl_t &io_errl,
        DeconfigEnum i_deconfigState,
        GARD_ErrorType i_gardErrorType)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    // processCallouts() function also changes, as today it (errlentry.C) calls
    // from the errlEntry object

    errlHndl_t pError = NULL;

    if ((io_errl->sev()) == (ERRORLOG::ERRL_SEV_INFORMATIONAL))
    {
        HWAS_INF("Error log is informational - skipping clock callouts");
    }
    else
    {
#ifdef CONFIG_PLDM

    // @TODO RTC 295271: Support PLDM clock callouts

#endif

#ifdef CONFIG_CLOCK_DECONFIGS_FATAL

        // If clock deconfigs are considered fatal, and deconfig requested, then
        // call doShutdown
        if(i_deconfigState == HWAS::DECONFIG)
        {
            HWAS_INF(
                "Clock deconfiguration considered fatal, requesting "
                "shutdown.  See PLID = 0x%X for details.",
                io_errl->eid());
            INITSERVICE::doShutdown(io_errl->eid(), true);
        }

#endif

    }

    return pError;
}

//******************************************************************************
// platHandleClockCallout
//******************************************************************************
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
