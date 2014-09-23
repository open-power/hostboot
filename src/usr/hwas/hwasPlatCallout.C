/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatCallout.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#include <ipmi/ipmisensor.H>

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
        errlHndl_t &io_errl,
        GARD_ErrorType  i_gardErrorType)
{
    // WARNING:
    // this hostboot code should not change io_errl, unless the caller of the
    //  processCallouts() function also changes, as today it (errlentry.C) calls
    //  from the errlEntry object

    errlHndl_t errl = NULL;

    HWAS_INF("HW callout; pTarget %p gardErrorType %x deconfigState %x",
            i_pTarget, i_gardErrorType, i_deconfigState);

    if (hwasPLDDetection())
    {
        HWAS_INF("hwasPLDDetection return true - skipping callouts");
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
                errl = HWAS::theDeconfigGard().platCreateGardRecord(i_pTarget,
                        io_errl->eid(),
                        i_gardErrorType);
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
                // call HWAS common function
                errl = HWAS::theDeconfigGard().deconfigureTarget(*i_pTarget,
                            io_errl->eid());
                break;
            }
            case (DELAYED_DECONFIG):
            {
                // do nothing -- the deconfig information was already
                // put on a queue and will be processed separately,
                // when the time is right.
                break;
            }
        } // switch i_deconfigState

        // check to see if this target is the master processor
        //  and if it's been deconfigured.
        TARGETING::Target *l_masterProc;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterProc);
        if (i_pTarget == l_masterProc)
        {
            const TARGETING::HwasState hwasState =
                    l_masterProc->getAttr<TARGETING::ATTR_HWAS_STATE>();
            if (!hwasState.functional)
            {
                HWAS_ERR("master proc deconfigured - Shutdown due to plid 0x%X",
                        io_errl->plid());
                INITSERVICE::doShutdown(io_errl->plid(), true);
            }
        }
    } // PLD

    return errl;
}

//******************************************************************************
// platHandleBusCallout
//******************************************************************************
errlHndl_t platHandleBusCallout(
        TARGETING::Target *i_pTarget1,
        TARGETING::Target *i_pTarget2,
        busTypeEnum i_busType,
        callOutPriority i_priority,
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

#ifdef CONFIG_BMC_IPMI

    // If BMC is present and IPMI is configured system has a simple clock
    // topology, so need to update the BMC fault sensor for the clock if there
    // is a deconfig since Hostboot is the only party able to handle clock
    // fails.
    // For now, all clock sensors reside on the node target
    if(i_deconfigState == HWAS::DECONFIG)
    {
        TARGETING::TargetHandleList parentList;

        (void)getParentAffinityTargets (
            parentList,
            i_pTarget, TARGETING::CLASS_ENC, TARGETING::TYPE_NODE,
            false);

        assert(parentList.size() == 1, "Bug! Query returned multiple or no "
            "(actual = %d) parents",
            parentList.size());

        TARGETING::TargetHandle_t pTarget = parentList[0];

        // Get associated target
        TARGETING::ATTR_TYPE_type associatedType = TARGETING::TYPE_NA;
        switch(i_clockType)
        {
            case TODCLK_TYPE:
                associatedType = TARGETING::TYPE_OSC;
                break;
            case MEMCLK_TYPE:
            case OSCREFCLK_TYPE:
                associatedType = TARGETING::TYPE_OSCREFCLK;
                break;
            case OSCPCICLK_TYPE:
                associatedType = TARGETING::TYPE_OSCPCICLK;
                break;
            default:
                assert(0,"Bug! Caller supplied illegal clock type.  "
                    "i_clockType = 0x%X",
                    i_clockType);
        }

        SENSOR::FaultSensor faultSensor(pTarget,associatedType);

        pError = faultSensor.setStatus(
            SENSOR::FaultSensor::FAULT_STATE_ASSERTED);
        if(pError)
        {
            HWAS_ERR("Failed setting fault sensor status for clock type 0x%X "
                "and HUID 0x%X",
                i_clockType, TARGETING::get_huid(pTarget));
            pError->collectTrace(HWAS_COMP_NAME, 512);
            errlCommit(pError, HWAS_COMP_ID);
        }
    }

#endif

#ifdef CONFIG_CLOCK_DECONFIGS_FATAL

    // If clock deconfigs are considered fatal, and deconfig requested, then
    // call doShutdown
    if(i_deconfigState == HWAS::DECONFIG)
    {
        HWAS_INF(
            "Clock deconfiguration considered fatal, requesting "
            "shutdown.  See PLID = 0x%X for details.",
            io_errl->plid());
        INITSERVICE::doShutdown(io_errl->plid(), true);
    }

#endif

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
