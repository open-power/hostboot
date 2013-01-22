/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludcallout.C $                                */
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
    pData->cpuid = task_getcpuid();
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
