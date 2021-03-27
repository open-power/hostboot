/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/ipc_msg_types.H $                        */
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
#if !defined(__IPC_MSG_TYPES_H)
#define __IPC_MSG_TYPES_H

#include <mbox/mbox_queues.H>

namespace IPC
{
    /**
     * IPC message types
     */
    enum ipc_msg_type_t
    {
        IPC_POPULATE_ATTRIBUTES = MBOX::FIRST_SECURE_MSG + 1,
        IPC_TEST_CONNECTION = MBOX::FIRST_SECURE_MSG + 2,
        IPC_START_PAYLOAD,
        IPC_QUERY_CHIPINFO,
        IPC_SET_SBE_CHIPINFO,
        IPC_CLOSE_TCES,
        IPC_POPULATE_TPM_INFO_BY_NODE,
        IPC_FREQ_ATTR_DATA, // frequency attribute data from master to other drawers
        IPC_PCR_EXTEND,     // Extend TPM measurement to primary TPM on
                            // node
    };

}; // namespace IPC
#endif
