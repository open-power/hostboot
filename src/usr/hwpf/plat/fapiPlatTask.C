/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatTask.C $                            */
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
 *  @file fapiPlatTask.C
 *
 *  @brief Performs the Hostboot fapi::plat startup task
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <initservice/taskargs.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <hwpf/plat/fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// Global Variables
//******************************************************************************
// Defined in fapiPlatAttrOverrideSync.C
extern TARGETING::AttributeTank::AttributeHeader g_attrOverrideHeader;
extern uint8_t g_attrOverride[AttrOverrideSync::MAX_DIRECT_OVERRIDE_ATTR_SIZE_BYTES];
extern uint8_t g_attrOverrideFapiTank;

//******************************************************************************
// This function monitors for FSP mailbox messages
//******************************************************************************
void * platMonitorForFspMessages(void * i_pContext)
{
    FAPI_IMP("Starting platMonitorForFspMessages");
    fapi::theAttrOverrideSync().monitorForFspMessages();
    return NULL; // Execution should never reach here
}

//******************************************************************************
// This function is run when the extended initservice loads the plat module
//
// It writes the global variables associated with direct attribute override to
// ensure they are paged and pinned in memory. These variables are used by a
// debug tool to override attributes
//
// It starts a task that monitors for FSP mailbox messages on the
// HB_HWPF_ATTR_MSGQ message queue
//******************************************************************************
void platTaskEntry(errlHndl_t &io_errl)
{
    FAPI_IMP("Starting platTaskEntry");

    // Write the global variables associated with direct attribute override
    g_attrOverrideHeader.iv_attrId = 0;
    g_attrOverride[0] = 0;
    g_attrOverrideFapiTank = 0;

    // Start task that monitors for FSP mailbox messages
    task_create(fapi::platMonitorForFspMessages, NULL);
}

} // End fapi namespace

// Macro that creates the _start function
TASK_ENTRY_MACRO(fapi::platTaskEntry);
