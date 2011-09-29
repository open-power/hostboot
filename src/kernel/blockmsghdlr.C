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
#include <kernel/pagemgr.H>

MessageHandler::HandleResult BlockReadMsgHdlr::handleResponse(
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

MessageHandler::HandleResult BlockWriteMsgHdlr::handleResponse(
        msg_sys_types_t i_type, void* i_key, task_t* i_task, int i_rc)
{
    //Default to indicate nothing specific has been done for this response.
    MessageHandler::HandleResult l_result = UNHANDLED_RC;
    if (i_rc != 0)
    {
        //Request default behavior of resume/kill task based on rc.
        return l_result;
    }
    //Find the virtual address to page address mapping to know which page
    //address to release since only the virtual address is available on the msg
    PageAddrNode* l_paNode = iv_va2paList.find(i_key);
    if (l_paNode)
    {
        l_result = SUCCESS;
        //Complete page removal and remove list entry
        PageManager::freePage(reinterpret_cast<void*>(l_paNode->pageAddr));
        iv_va2paList.erase(l_paNode);
        delete l_paNode;
    }
    //Not handling a reponse from kernel
    if (i_task != NULL)
    {
        //Find the task's msg count to know how many messages were sent
        //to remove pages and whether to continue deferring the task or not
        TaskMsgNode* l_tmNode = iv_msgGrpList.find(i_task);
        if (l_tmNode)
        {
            //Last message for the given task
            if (l_tmNode->msgCount == 1 &&
                (l_tmNode->next == NULL && l_tmNode->prev == NULL))
            {
                l_result = SUCCESS;
                iv_msgGrpList.erase(l_tmNode);
                delete l_tmNode;
            }
            else
            {
                l_result = CONTINUE_DEFER;
                l_tmNode->msgCount--;
            }
        }
    }

    return l_result;
}

void BlockWriteMsgHdlr::incMsgCount(task_t* i_task)
{
    TaskMsgNode* l_tmNode = iv_msgGrpList.find(i_task);
    if (l_tmNode == NULL)
    {
        //Add task to list and set message count to 1
        l_tmNode = new TaskMsgNode();
        l_tmNode->key = i_task;
        l_tmNode->msgCount = 0;
        iv_msgGrpList.insert(l_tmNode);
    }
    l_tmNode->msgCount++;
}

void BlockWriteMsgHdlr::addVirtAddr(void* i_vaddr,uint64_t i_pgAddr)
{
    PageAddrNode* l_paNode = new PageAddrNode();
    l_paNode->key = i_vaddr;
    l_paNode->pageAddr = i_pgAddr;
    iv_va2paList.insert(l_paNode);
}
