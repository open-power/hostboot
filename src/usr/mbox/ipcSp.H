/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/ipcSp.H $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#if !defined(__IPCSP_H)
#define __IPCSP_H

#include <stdint.h>
#include <errl/errlentry.H>
#include <sys/msg.h>

namespace IPC
{

    /**
     * Handle IPC messages sent from other nodes
     */
    class IpcSp
    {
        public:

            /**
             * Initialize the service provider
             */
            static void init(errlHndl_t & o_errl);

        protected:

            /**
             * Constructor
             */
            IpcSp();

            /**
             * Destructor
             */
            ~IpcSp();

            /**
             * Start message handler
             *
             * @note This function is used to spawn a new task.
             *       The args and return value are not used.
             */
            static void* msg_handler(void * unused);

        private:

            /**
             * Intiailze the service provider
             */
            errlHndl_t _init();

            /**
             * The ipc service provider message handler.
             */
            void msgHandler();

            /**
             * The IPC message queue
             */
            msg_q_t iv_msgQ;

    };
}; // namespace IPC
#endif

