/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/blockmsghdlr.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <kernel/blockmsghdlr.H>
#include <kernel/block.H>
#include <kernel/pagemgr.H>
#include <kernel/basesegment.H>
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
        // Call the function that attaches PTE and sets the
        // sPTE entry to present while updating permissions
        // on the sPTE entry of the physical addr.
        iv_block->attachSPTE(i_key);

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
            if (l_tmNode->msgCount == 1)
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
