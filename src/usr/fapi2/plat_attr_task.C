/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_attr_task.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
///
/// @file plat_attr_task.C
///
/// @brief Starts task which will handle attribute overrides
///

//******************************************************************************
// Includes
//******************************************************************************
#include <initservice/taskargs.H>
#include <fapi2/plat_attr_override_sync.H>
#include <fapi2/plat_trace.H>

namespace fapi2
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
    task_detach();
    FAPI_IMP("Starting platMonitorForFspMessages");
    fapi2::theAttrOverrideSync().monitorForFspMessages();
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
    task_create(fapi2::platMonitorForFspMessages, NULL);
}

} // End fapi2 namespace

// Macro that creates the _start function
TASK_ENTRY_MACRO(fapi2::platTaskEntry);

