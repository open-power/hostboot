/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/ipc_reasoncodes.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#ifndef __IPC_REASONCODES_H
#define __IPC_REASONCODES_H

#include <hbotcompid.H>

#define IPC_TRACE_NAME "IPC"

namespace IPC
{
    enum IPCModuleId
    {
        MOD_IPCSP_MSGHDLR       = 0x01,    //IpcSp::msgHandler
    };

    enum IPCReasonCode
    {
        RC_INVALID_MSG_TYPE       = IPC_COMP_ID | 0x01,
        RC_BAD_PHYS_ADDR          = IPC_COMP_ID | 0x02,
        RC_BLOCK_MAP_FAIL         = IPC_COMP_ID | 0x03,
        RC_BLOCK_UNMAP_FAIL       = IPC_COMP_ID | 0x04,
        RC_INCORRECT_NODE_ROUTING = IPC_COMP_ID | 0x05,
    };

};
#endif

