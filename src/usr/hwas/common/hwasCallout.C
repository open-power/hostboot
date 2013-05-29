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

#include <hwas/common/hwasError.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/attributes.H>

namespace HWAS
{

using namespace HWAS::COMMON;

void processCallout(errlHndl_t i_errl,
        uint8_t *i_pData,
        uint64_t i_Size)
{
    HWAS_INF("processCallout entry. data %p size %lld",
            i_pData, i_Size);

    callout_ud_t *pCalloutUD = (callout_ud_t *)i_pData;

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
                     *               processing of HW callout
                     * @userdata1    callout errlog PLID
                     */
                    errlHndl_t errl = hwasError(
                        ERRL_SEV_INFORMATIONAL,
                        HWAS::MOD_PROCESS_CALLOUT,
                        HWAS::RC_INVALID_TARGET,
                        i_errl->plid());
                    errlCommit(errl, HWAS_COMP_ID);
                    break;
                }
            }
            else
            {   //  convert this to the real master processor
                TARGETING::targetService().masterProcChipTargetHandle(pTarget);
            }

            errlHndl_t errl = platHandleHWCallout(
                            pTarget,
                            pCalloutUD->priority,
                            pCalloutUD->deconfigState,
                            i_errl,
                            pCalloutUD->gardErrorType);
            if (errl)
            {
                HWAS_ERR("HW callout: error from platHandlHWCallout");
                errlCommit(errl, HWAS_COMP_ID);
            }
            break;
        } // HW_CALLOUT
        case (PROCEDURE_CALLOUT):
        {
            HWAS_INF("Procedure callout; proc 0x%x priority 0x%x",
                pCalloutUD->procedure, pCalloutUD->priority);

            errlHndl_t errl = platHandleProcedureCallout(i_errl,
                            pCalloutUD->procedure, pCalloutUD->priority);
            if (errl)
            {
                HWAS_ERR("HW callout: error from platHandlProcedureCallout");
                errlCommit(errl, HWAS_COMP_ID);
            }
            break;
        }
        default:
        {
            HWAS_ERR("bad data in Callout UD %x", pCalloutUD->type);
            break;
        }
    } // switch

    HWAS_INF("processCallout exit");
} // processCallout

}; // end namespace
