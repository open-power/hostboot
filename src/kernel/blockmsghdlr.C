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
