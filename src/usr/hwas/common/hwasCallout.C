/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwas/common/hwasCallout.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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

class RegisterHWASFunctions
{
    public:
    RegisterHWASFunctions()
    {
        // HWAS is awake - register our processCallout function
        HWAS_DBG("module load: calling errlog::setHwasProcessCalloutFn");
        ERRORLOG::ErrlManager::setHwasProcessCalloutFn((processCalloutFn)(&processCallout));
    }
};
// this causes the function to get run at module load.
RegisterHWASFunctions registerHWASFunctions;

void processCallout(const uint32_t i_errlPlid,
        uint8_t *i_pData,
        uint64_t i_Size)
{
    HWAS_INF("processCallout entry. plid 0x%x data %p %lld",
            i_errlPlid, i_pData, i_Size);

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
            if (*((uint8_t *)(pCalloutUD + 1)) == TARGET_IS_SENTINEL)
            {
                pTarget = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
                // TODO RTC: 45780
                HWAS_INF("TARGET_SENTINEL - can't handle; exiting");
                break; // HWAS can't handle this right now... 
            }
            else
            {
                // convert the EntityPath to a Target pointer
                TARGETING::EntityPath ep;
                memcpy(&ep, (pCalloutUD + 1), sizeof(ep));
                pTarget = TARGETING::targetService().toTarget(ep);
            }

            if (pTarget == NULL)
            {   // should only happen if we have a corrupt errlog or targeting.
                HWAS_ERR("HW callout; pTarget was NULL!!!");

                /*@
                 * @errortype
                 * @moduleid     MOD_PROCESS_CALLOUT
                 * @reasoncode   HWAS::RC_INVALID_TARGET
                 * @devdesc      Invalid Target encountered into processCallout
                 */
                errl = hwasError(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HWAS::MOD_PROCESS_CALLOUT,
                    HWAS::RC_INVALID_TARGET);
                errlCommit(errl, HWAS_COMP_ID);
                break;
            }

            HWAS_INF("HW callout; pTarget %p", pTarget);
            const DeconfigEnum deconfigState = pCalloutUD->deconfigState;
            const GARD_ErrorType gardErrorType = pCalloutUD->gardErrorType;
            //const callOutPriority priority = pCalloutUD->priority;
            switch (gardErrorType)
            {
                case (GARD_NULL):
                {   // means no GARD operations
                    break;
                }
                default:
                {
                    // call HWAS common function
                    errl = HWAS::theDeconfigGard().createGardRecord(*pTarget,
                            i_errlPlid,
                            GARD_Fatal);
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
                    // call HWAS common function
                    errl = HWAS::theDeconfigGard().deconfigureTarget(*pTarget,
                                i_errlPlid);
                    break;
                }
                case (DELAYED_DECONFIG):
                {
                    // call HWAS common function
                    // TODO RTC: 45781
                    //errl = HWAS::theDeconfigGard().registerDelayedDeconfigure(*pTarget,
                                //i_errlPlid);
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

            // TODO RTC: 35108
            // call HWAS common function
            //errl = HWAS::processCallout(procedure, priority, i_errlPlid);
            break;
        }
        default:
        {
            HWAS_ERR("bad data in Callout UD %x", pCalloutUD->type);
            break;
        }
    } // switch

    HWAS_INF("processCallout exit errl %p", errl);
} // processCallout

}; // end namespace
