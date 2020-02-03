/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/pldmrp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include "pldmrp.H"
#include "file_io.h"
#include "base.h"
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <mctp/mctp_message_types.H>

trace_desc_t* g_trac_pldm = nullptr;
TRAC_INIT(&g_trac_pldm, PLDM_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW);

extern const char* VFS_ROOT_MSG_MCTP_OUT;

static void * handle_inbound_messages_task(void*)
{
    TRACFCOMP(g_trac_pldm, "Starting task to handle pldm inbound messages");
    Singleton<PldmRP>::instance().handle_inbound_messages();
    return nullptr;
}

void PldmRP::handle_inbound_messages(void)
{
    uint8_t l_rc = 0;

    while(1)
    {
        msg_t* msg = msg_wait(iv_inboundMsgQ);

        switch(msg->type)
        {
          case PLDM::MSG_CONTROL_DISCOVERY:
              //
              break;
          case PLDM::MSG_SMBIOS:
              //
              break;
          case PLDM::MSG_MONITOR_CONTROL:
              //
              break;
          case PLDM::MSG_BIOS_CONTROL:
              //
              break;
          case PLDM::MSG_OEM:
              //
              break;
          default:
               // TODO
              // Error because its an unknown type
              break;
        }

        if(l_rc != 0)
        {
            break;
        }
    }
}

errlHndl_t PldmRP::_init(void)
{
    TRACFCOMP(g_trac_pldm, "PldmRP::_init entry");
    errlHndl_t l_errl = nullptr;

    // Start cmd daemon first because we want it ready if poll daemon finds something right away
    task_create(handle_inbound_messages_task, NULL);

    iv_mctpOutboundMsgQ = msg_q_resolve(VFS_ROOT_MSG_MCTP_OUT);

    TRACFCOMP(g_trac_pldm, "PldmRP::_init exit");

    return l_errl;
}

void PldmRP::init(errlHndl_t& o_errl)
{
    // This will call the MctpRP construction which initializes MCTP
    // polling loops
    o_errl = Singleton<PldmRP>::instance()._init();;
}

PldmRP::PldmRP(void):
    iv_inboundMsgQ(msg_q_create())
{
}

// Set the function that will be called when mctp.so is loaded
TASK_ENTRY_MACRO( PldmRP::init );
