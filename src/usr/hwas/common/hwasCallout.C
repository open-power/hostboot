/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwasCallout.C $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 *  @file hwasCallout.C
 *
 *  HardWare Availability Service Callout functions.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

#include <hwas/common/hwasCommon.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/attributes.H>

namespace HWAS
{

bool processCallout(const uint32_t i_errlPlid,
        uint8_t *i_pData,
        uint64_t i_Size)
{
    HWAS_INF("processCallout entry. plid 0x%x data %p size %lld",
            i_errlPlid, i_pData, i_Size);

    bool l_rc = false; // default is no shutdown required
    callout_ud_t *pCalloutUD = (callout_ud_t *)i_pData;
    errlHndl_t errl = NULL;
    switch (pCalloutUD->type)
    {
        case (HW_CALLOUT):
        {
            TARGETING::Target *pTarget;

            // data after the pCalloutUD structure is either a token
            //  indicating it's the MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
            //  or it's the EntityPath - getAttr<TARGETING::ATTR_PHYS_PATH>()
            if (*((uint8_t *)(pCalloutUD + 1)) != TARGET_IS_SENTINEL)
            {
                // convert the EntityPath to a Target pointer
                TARGETING::EntityPath ep;
                memcpy(&ep, (pCalloutUD + 1), sizeof(ep));
                pTarget = TARGETING::targetService().toTarget(ep);

                if (unlikely(pTarget == NULL))
                {   // only happen if we have a corrupt errlog or targeting.
                    HWAS_ERR("HW callout; pTarget was NULL!!!");
            
                    /*@
                     * @errortype
                     * @moduleid     HWAS::MOD_PROCESS_CALLOUT
                     * @reasoncode   HWAS::RC_INVALID_TARGET
                     * @devdesc      Invalid Target encountered in
                     *               processCallout
                     */
                    errl = hwasError(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        HWAS::MOD_PROCESS_CALLOUT,
                        HWAS::RC_INVALID_TARGET);
                    errlCommit(errl, HWAS_COMP_ID);
                    break;
                }
            }
            else
            {   //  convert this to the real master processor
                TARGETING::targetService().masterProcChipTargetHandle(pTarget);
            }

            const DeconfigEnum deconfigState = pCalloutUD->deconfigState;
            const GARD_ErrorType gardErrorType = pCalloutUD->gardErrorType;
            //const callOutPriority priority = pCalloutUD->priority;

            HWAS_INF("HW callout; pTarget %p gardErrorType %x deconfigState %x",
                    pTarget, gardErrorType, deconfigState);
            switch (gardErrorType)
            {
                case (GARD_NULL):
                {   // means no GARD operations
                    break;
                }
                default:
                {
                    // move these to platform specific functions?
                    // RTC: 45781
                    // hostboot:
                    // call HWAS common function
                    errl = HWAS::theDeconfigGard().createGardRecord(*pTarget,
                            i_errlPlid,
                            GARD_Fatal);
                    errlCommit(errl, HWAS_COMP_ID);
                    // fsp:
                    // RTC: 45781
                    // nothing? gard record is already in PNOR
                    break;
                }
            } // switch gardErrorType

            switch (deconfigState)
            {
                case (NO_DECONFIG):
                {
                    break;
                }
                case (DECONFIG):
                {
                    // check to see if this target is the master processor
                    TARGETING::Target *l_masterProc;
                    TARGETING::targetService().masterProcChipTargetHandle(
                                l_masterProc);
                    if (pTarget == l_masterProc)
                    {
                        // if so, we can't run anymore, so we will
                        // return TRUE so the caller calls doShutdown
                        HWAS_ERR("callout - DECONFIG on MasterProc");
                        l_rc = true;
                        break;
                    }

                    // else, call HWAS common function
                    errl = HWAS::theDeconfigGard().deconfigureTarget(*pTarget,
                                i_errlPlid);
                    errlCommit(errl, HWAS_COMP_ID);
                    break;
                }
                case (DELAYED_DECONFIG):
                {
                    // check to see if this target is the master processor
                    TARGETING::Target *l_masterProc;
                    TARGETING::targetService().masterProcChipTargetHandle(
                                l_masterProc);
                    if (pTarget == l_masterProc)
                    {
                        // if so, we can't run anymore, so we will
                        // return TRUE so the caller calls doShutdown
                        l_rc = true;
                        HWAS_ERR("callout - DELAYED_DECONFIG on MasterProc");
                        break;
                    }
                    // else
                    // do nothing -- the deconfig information was already
                    // put on a queue and will be processed separately,
                    // when the time is right.
                    break;
                }
            } // switch deconfigState
            break;
        }
        case (PROCEDURE_CALLOUT):
        {
            HWAS_INF("Procedure callout; proc 0x%x priority 0x%x",
                pCalloutUD->type, pCalloutUD->type);
            //const HWAS::epubProcedureID procedure = pCalloutUD->procedure;
            //const callOutPriority priority = pCalloutUD->priority;

            // move these to platform specific functions?
            // RTC: 45781
            // hostboot:
            // nothing

            // fsp:
            // RTC: 45781
            // ? not sure what fsp does for procedure callouts?
            break;
        }
        default:
        {
            HWAS_ERR("bad data in Callout UD %x", pCalloutUD->type);
            break;
        }
    } // switch

    HWAS_INF("processCallout exit l_rc %d", l_rc);
    return l_rc;
} // processCallout

}; // end namespace
