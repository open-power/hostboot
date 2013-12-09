/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludcallout.C $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 *  @file errludcallout.C
 *
 *  @brief Implementation of ErrlUserDetailsCallout
 */
#include <sys/task.h>
#include <errl/errludcallout.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <targeting/common/trace.H>

namespace ERRORLOG
{

extern TARGETING::TARG_TD_t g_trac_errl;

//------------------------------------------------------------------------------
// Clock callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTargetData,
        uint32_t i_targetDataLength,
        const HWAS::clockTypeEnum i_clockType,
        const HWAS::callOutPriority i_priority,
        const HWAS::DeconfigEnum i_deconfigState,
        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACDCOMP(g_trac_errl, "ClockCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_CALLOUT;

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) + i_targetDataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::CLOCK_CALLOUT;
    pData->clockType = i_clockType;
    pData->priority = i_priority;
    pData->clkDeconfigState = i_deconfigState;
    pData->clkGardErrorType = i_gardErrorType;
    memcpy(pData + 1, i_pTargetData, i_targetDataLength);

    TRACDCOMP(g_trac_errl, "ClockCallout exit; pDataLength %d", pDataLength);

} // Clock callout

//------------------------------------------------------------------------------
// Bus callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTarget1Data,
        uint32_t i_target1DataLength,
        const void *i_pTarget2Data,
        uint32_t i_target2DataLength,
        const HWAS::busTypeEnum i_busType,
        const HWAS::callOutPriority i_priority)
{
    TRACDCOMP(g_trac_errl, "BusCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_CALLOUT;

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) +
                           i_target1DataLength + i_target2DataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::BUS_CALLOUT;
    pData->busType = i_busType;
    pData->priority = i_priority;
    char * l_ptr = (char *)(++pData);
    memcpy(l_ptr, i_pTarget1Data, i_target1DataLength);
    memcpy(l_ptr + i_target1DataLength, i_pTarget2Data, i_target2DataLength);

    TRACDCOMP(g_trac_errl, "BusCallout exit; pDataLength %d", pDataLength);

} // Bus callout

//------------------------------------------------------------------------------
// Hardware callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const void *i_pTargetData,
        uint32_t i_targetDataLength,
        const HWAS::callOutPriority i_priority,
        const HWAS::DeconfigEnum i_deconfigState,
        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACDCOMP(g_trac_errl, "HWCallout entry");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_CALLOUT;

    //iv_merge = false; // use the default of false

    uint32_t pDataLength = sizeof(HWAS::callout_ud_t) + i_targetDataLength;
    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(pDataLength));
    pData->type = HWAS::HW_CALLOUT;
    pData->priority = i_priority;
#ifndef __HOSTBOOT_RUNTIME
    pData->cpuid = task_getcpuid();
#else
    pData->cpuid = (uint32_t)(-1);
#endif
    pData->deconfigState = i_deconfigState;
    pData->gardErrorType = i_gardErrorType;
    memcpy(pData + 1, i_pTargetData, i_targetDataLength);

    TRACDCOMP(g_trac_errl, "HWCallout exit; pDataLength %d", pDataLength);

} // Hardware callout


//------------------------------------------------------------------------------
// Procedure callout
ErrlUserDetailsCallout::ErrlUserDetailsCallout(
        const HWAS::epubProcedureID i_procedure,
        const HWAS::callOutPriority i_priority)
{
    TRACDCOMP(g_trac_errl, "Procedure Callout");

    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_CALLOUT;

    //iv_merge = false; // use the default of false

    HWAS::callout_ud_t *pData;
    pData = reinterpret_cast<HWAS::callout_ud_t *>
                (reallocUsrBuf(sizeof(HWAS::callout_ud_t)));

    pData->type = HWAS::PROCEDURE_CALLOUT;
    pData->procedure = i_procedure;
    pData->priority = i_priority;

    TRACDCOMP(g_trac_errl, "Procedure Callout exit");

} // Procedure callout

}
