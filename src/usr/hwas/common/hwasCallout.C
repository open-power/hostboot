/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwasCallout.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
/* [+] Google Inc.                                                        */
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

#ifdef __HOSTBOOT_RUNTIME // defined in hwas.C
extern HWAS_TD_t g_trac_imp_hwas; // important - slow
extern HWAS_TD_t g_trac_dbg_hwas; // fast debug
#endif

using namespace HWAS::COMMON;

bool retrieveTarget(uint8_t * & io_uData,
                    TARGETING::Target * & o_pTarget, errlHndl_t i_errl)
{
    bool l_err = false;

    static_assert( sizeof(callout_ud_t) == 20,
                   "callout_ud_t is the wrong size" );

    // data is either a token indicating it's the
    // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // or it's the EntityPath - getAttr<TARGETING::ATTR_PHYS_PATH>()
    if (*io_uData != TARGET_IS_SENTINEL)
    {
        // convert the EntityPath to a Target pointer
        TARGETING::EntityPath ep, *ep_ptr;
        ep_ptr = (TARGETING::EntityPath *)io_uData;
        // size is total EntityPath size minus unused path elements
        uint32_t size = sizeof(*ep_ptr) -
                (TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep_ptr->size()) *
                    sizeof(TARGETING::EntityPath::PathElement);
        memcpy(&ep, io_uData, size);
        o_pTarget = TARGETING::targetService().toTarget(ep);
        io_uData += size;

        if (unlikely(o_pTarget == NULL))
        {   // only happen if we have a corrupt errlog or targeting.
            HWAS_ERR("HW callout; o_pTarget was NULL!!!");
#ifndef __HOSTBOOT_RUNTIME
            /*@
             * @errortype
             * @moduleid     HWAS::MOD_PROCESS_CALLOUT
             * @reasoncode   HWAS::RC_INVALID_TARGET
             * @devdesc      Invalid target encountered in
             *               processing of HW callout
             * @custdesc     Error occurred during system boot
             * @userdata1    callout errlog PLID
             */
            errlHndl_t errl = hwasError(
                        ERRL_SEV_INFORMATIONAL,
                        HWAS::MOD_PROCESS_CALLOUT,
                        HWAS::RC_INVALID_TARGET,
                        i_errl->plid());
            errlCommit(errl, HWAS_COMP_ID);
#endif
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

#ifndef __HOSTBOOT_RUNTIME
void processCallout(errlHndl_t &io_errl,
        uint8_t *i_pData,
        uint64_t i_Size,
        bool i_DeferredOnly)
{
    callout_ud_t *pCalloutUD = (callout_ud_t *)i_pData;
    HWAS_DBG("processCallout entry. data %p size %lld type 0x%x",
            i_pData, i_Size, pCalloutUD->type);

    if (i_DeferredOnly)
    {
        if ((pCalloutUD->type == HW_CALLOUT) &&
            (pCalloutUD->deconfigState == DELAYED_DECONFIG))
        {
            TARGETING::Target *pTarget = NULL;
            uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
            bool l_err = retrieveTarget(l_uData, pTarget, io_errl);

            if (!l_err)
            {
                HWAS::theDeconfigGard().registerDeferredDeconfigure(
                            *pTarget, io_errl->eid());
            }
        }
        // else, no deferred deconfigures - all good.
    }
    else
    switch (pCalloutUD->type)
    {
        case (HW_CALLOUT):
        {
            TARGETING::Target *pTarget = NULL;
            uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
            bool l_err = retrieveTarget(l_uData, pTarget, io_errl);

            if (!l_err)
            {
                errlHndl_t errl = platHandleHWCallout(
                                        pTarget,
                                        pCalloutUD->priority,
                                        pCalloutUD->deconfigState,
                                        io_errl,
                                        pCalloutUD->gardErrorType);
                if (errl)
                {
                    HWAS_ERR("processCallout: error from platHandlHWCallout");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            break;
        } // HW_CALLOUT
        case (PROCEDURE_CALLOUT):
        {
            HWAS_INF("Procedure callout; proc 0x%x priority 0x%x",
                pCalloutUD->procedure, pCalloutUD->priority);

            errlHndl_t errl = platHandleProcedureCallout(io_errl,
                            pCalloutUD->procedure, pCalloutUD->priority);
            if (errl)
            {
                HWAS_ERR("processCallout: error from platHandlProcedureCallout");
                errlCommit(errl, HWAS_COMP_ID);
            }
            break;
        } // PROCEDURE_CALLOUT
        case (BUS_CALLOUT):
        {
            HWAS::busCallout_t io_busCallout;

            uint8_t * l_targetData = (uint8_t *)(pCalloutUD + 1);
            bool l_err1 = retrieveTarget(l_targetData,
                                         io_busCallout.TargetPart1,
                                         io_errl);
            bool l_err2 = retrieveTarget(l_targetData,
                                         io_busCallout.TargetPart2,
                                         io_errl);

            io_busCallout.busType = pCalloutUD->busType;
            io_busCallout.priority = pCalloutUD->priority;
            io_busCallout.flag = pCalloutUD->flag;

            if (!l_err1 && !l_err2)
            {
                errlHndl_t errl = platHandleAddBusCallout(
                                     io_busCallout, io_errl );
                if (errl)
                {
                    HWAS_ERR("processCallout: error in platHandlAddBusCallout");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            break;
        } // BUS_CALLOUT
        case (CLOCK_CALLOUT):
        {
            TARGETING::Target *pTarget = NULL;
            uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
            bool l_err = retrieveTarget(l_uData, pTarget, io_errl);

            if (!l_err)
            {
                errlHndl_t errl = platHandleClockCallout(
                                        pTarget,
                                        pCalloutUD->clockType,
                                        pCalloutUD->priority,
                                        io_errl,
                                        pCalloutUD->clkDeconfigState,
                                        pCalloutUD->clkGardErrorType);
                if (errl)
                {
                    HWAS_ERR("processCallout: error from platHandleClockCallout");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            break;
        } // CLOCK_CALLOUT
        case (PART_CALLOUT):
        {
            TARGETING::Target *pTarget = NULL;
            uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
            bool l_err = retrieveTarget(l_uData, pTarget, io_errl);

            if (!l_err)
            {
                errlHndl_t errl = platHandlePartCallout(
                                        pTarget,
                                        pCalloutUD->partType,
                                        pCalloutUD->priority,
                                        io_errl,
                                        pCalloutUD->deconfigState,
                                        pCalloutUD->gardErrorType);
                if (errl)
                {
                    HWAS_ERR("processCallout: error platHandlePartCallout");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            break;
        } // PART_CALLOUT
        case (I2C_DEVICE_CALLOUT):
        {
            TARGETING::Target *i2cMaster = nullptr;

            uint8_t * l_targetData = reinterpret_cast<uint8_t *>(pCalloutUD + 1);
            bool wasErr = retrieveTarget(l_targetData, i2cMaster, io_errl);

            if (!wasErr)
            {
                errlHndl_t errl = nullptr;

                errl = platHandleI2cDeviceCallout(
                                        i2cMaster,
                                        pCalloutUD->engine,
                                        pCalloutUD->port,
                                        pCalloutUD->address,
                                        pCalloutUD->priority,
                                        io_errl);
                if (errl)
                {
                    HWAS_ERR("processCallout: error from platHandleI2cDeviceCallout");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            break;
        } // I2C_DEVICE_CALLOUT
        case (SENSOR_CALLOUT):
        {
            HWAS_ERR("Unsupported Callout UD, SENSOR_CALLOUT 0x%x", pCalloutUD->type);
            break;
        }
        default:
        {
            // Assert at compile time if there is a new unhandled callout type added to the enum
            static_assert(LAST_CALLOUT == I2C_DEVICE_CALLOUT, "New callout type needs to be handled in processCallout");
            // Emit an error trace and move on at runtime in case another component did some bad casting.
            HWAS_ERR("bad data in Callout UD 0x%x", pCalloutUD->type);
            break;
        }
    } // switch

    HWAS_DBG("processCallout exit");
} // processCallout

#endif

}; // end namespace
