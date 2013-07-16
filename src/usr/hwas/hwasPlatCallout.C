/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatCallout.C $                              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
                errl = HWAS::theDeconfigGard().createGardRecord(*i_pTarget,
                        io_errl->plid(),
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
                            io_errl->plid());
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
                INITSERVICE::doShutdown(io_errl->plid());
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

} // namespace HWAS
