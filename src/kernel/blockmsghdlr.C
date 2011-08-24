//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/blockmsghdlr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <kernel/blockmsghdlr.H>
#include <kernel/block.H>
//#include <kernel/console.H>

MessageHandler::HandleResult BlockMsgHdlr::handleResponse(
        msg_sys_types_t i_type, void* i_key, task_t* i_task, int i_rc)
{
    if (i_rc != 0)
    {
        // Indicate nothing specific has been done for this response.  Request
        // default behavior of resume/kill task based on rc.
        return UNHANDLED_RC;
    }
    else
    {
        //Set the present bit for the address associated with this block
        iv_block->setIsPresent(i_key);
        //Add the address into the page table associated with this block
        iv_block->addPTE(i_key);
        return SUCCESS;
    }
}
