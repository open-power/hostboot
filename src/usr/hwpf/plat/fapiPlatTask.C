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
#include <sys/task.h>
#include <initservice/taskargs.H>
#include <hwpf/fapi/fapiAttributeOverride.H>
#include <fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// Global Variables
//******************************************************************************
// Defined in fapiPlatAttrOverrideDirect.C
extern AttributeOverride g_attrOverride;

//******************************************************************************
// platTaskEntry
// This function writes the g_attrOverride global variable first written by the
// Simics/VBU console and then read by fapiPlatAttrOverrideDirect.C to ensure
// it is paged and pinned in memory
//******************************************************************************
void platTaskEntry(errlHndl_t &io_errl)
{
    FAPI_IMP("Starting platTaskEntry");
    g_attrOverride.iv_overrideVal = 0;
    task_end();
}

// Macro that creates the _start function
TASK_ENTRY_MACRO(fapi::platTaskEntry);

} // End fapi namespace
