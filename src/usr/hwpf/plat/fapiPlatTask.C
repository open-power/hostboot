/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/plat/fapiPlatTask.C $
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
 *  @file fapiPlatTask.C
 *
 *  @brief Performs the Hostboot fapi::plat startup task
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <initservice/taskargs.H>
#include <hwpf/fapi/fapiAttributeTank.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <hwpf/plat/fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// Global Variables
//******************************************************************************
// Defined in fapiPlatAttrOverrideSync.C
extern Attribute g_attrOverride;

//******************************************************************************
// This function monitors for FSP mailbox messages
//******************************************************************************
void * platMonitorForFspMessages(void * i_pContext)
{
    FAPI_IMP("Starting platMonitorForFspMessages");
    fapi::attrOverrideSync::monitorForFspMessages();
    return NULL; // Execution should never reach here
}

//******************************************************************************
// This function is run when the extended initservice loads the plat module
//
// It writes the g_attrOverride global to ensure it is paged and pinned in
// memory. This variable is used by a debug tool to override HWPF Attributes
//
// It starts a task that monitors for FSP mailbox messages on the
// HB_HWPF_ATTR_MSGQ message queue
//******************************************************************************
void platTaskEntry(errlHndl_t &io_errl)
{
    FAPI_IMP("Starting platTaskEntry");

    // Write the g_attrOverride global
    g_attrOverride.iv_val = 0;

    // Start task that monitors for FSP mailbox messages
    task_create(fapi::platMonitorForFspMessages, NULL);
}

} // End fapi namespace

// Macro that creates the _start function
TASK_ENTRY_MACRO(fapi::platTaskEntry);
