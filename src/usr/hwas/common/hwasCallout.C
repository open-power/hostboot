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

bool retrieveTarget(uint8_t * & io_uData,
                    TARGETING::Target * & o_pTarget, errlHndl_t i_errl)
{
    bool l_err = false;

    // data is either a token indicating it's the
    // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // or it's the EntityPath - getAttr<TARGETING::ATTR_PHYS_PATH>()
    if (*io_uData != TARGET_IS_SENTINEL)
    {
        // convert the EntityPath to a Target pointer
        TARGETING::EntityPath ep, *ep_ptr;
        uint32_t size;
        ep_ptr = (TARGETING::EntityPath *)io_uData;
        size = TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep_ptr->size();
        size *= sizeof(TARGETING::EntityPath::PathElement);
        size = sizeof(ep) - size;
        memcpy(&ep, io_uData, size);
        o_pTarget = TARGETING::targetService().toTarget(ep);
        io_uData += size;

        if (unlikely(o_pTarget == NULL))
        {   // only happen if we have a corrupt errlog or targeting.
            HWAS_ERR("HW callout; o_pTarget was NULL!!!");

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
            l_err = true;
        }
    }
    else
    {   // convert this to the real master processor
        TARGETING::targetService().masterProcChipTargetHandle(o_pTarget);
        io_uData += sizeof(HWAS::TARGET_IS_SENTINEL);
    }
    return l_err;
}

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
            TARGETING::Target *pTarget = NULL;
            uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
            bool l_err = retrieveTarget(l_uData, pTarget, i_errl);

            if (!l_err)
            {
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
        case (BUS_CALLOUT):
        {
            TARGETING::Target *pTarget1 = NULL;
            TARGETING::Target *pTarget2 = NULL;

            uint8_t * l_targetData = (uint8_t *)(pCalloutUD + 1);
            bool l_err1 = retrieveTarget(l_targetData, pTarget1, i_errl);
            bool l_err2 = retrieveTarget(l_targetData, pTarget2, i_errl);

            if (!l_err1 && !l_err2)
            {
                errlHndl_t errl = platHandleBusCallout(
                                        pTarget1, pTarget2,
                                        pCalloutUD->busType,
                                        pCalloutUD->priority,
                                        i_errl);
                if (errl)
                {
                    HWAS_ERR("HW callout: error from platHandlBusCallout");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            break;
        } // BUS_CALLOUT
        default:
        {
            HWAS_ERR("bad data in Callout UD %x", pCalloutUD->type);
            break;
        }
    } // switch

    HWAS_INF("processCallout exit");
} // processCallout

}; // end namespace
