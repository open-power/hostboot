/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/ipcSp.H $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

