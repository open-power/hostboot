/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnsvc.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __ATTN_ATTNSVC_H
#define __ATTN_ATTNSVC_H

/**
 * @file attnsvc.H
 *
 * @brief HBATTN background service class definition.
 */

#include <sys/task.h>
#include <sys/sync.h>
#include "attnfwd.H"
#include "attnlist.H"

namespace ATTN
{

/**
 * @brief Service Host attention handler background service class definition.
 */
class Service
{
    public:

        /**
         * @brief stop Stop the background attention handler service.
         *
         * Noop if service already stopped.
         *
         * @post Service stopped.  All resources reclaimed.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error.
         */
        errlHndl_t stop();

        /**
         * @brief start start the background attention handler service
         *
         * noop if service already started
         *
         * @post service started.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] no error
         * @retval[!0] unexpected error
         */
        errlHndl_t start();

        /**
         * @brief running Provide a service running indicator.
         *
         * @retval[true] Service is running.
         * @retval[false] Service is not running.
         */
        bool running();

        /**
         * @brief ctor
         */
        Service();

        /**
         * @brief dtor
         */
        ~Service();

    private:

        /**
         * @brief ConfigureMode
         *
         * Up or down for parameter for configure methods.
         */
        enum ConfigureMode
        {
            UP, DOWN,
        };

        /**
         * @brief configureInterrupts enable or
         *   disable interrupts used by the service, on all
         *   functioning processors.
         *
         * @post Service (un)hooked to/from interrupt service
         *   for local error and host interrupts.
         * @post Local error and host priority set(cleared).
         * @post Local error and host interrupts (un)masked at GFIR macro.
         *
         * @param[in] i_mode Up or down
         * @param[in] i_q The msg q to be registered with the
         *             interrupt service.
         *
         * @retval[0] No error
         * @retval[!0] Unexpected error
         */
        errlHndl_t configureInterrupts(
                msg_q_t i_q,
                ConfigureMode i_mode);

        /**
         * @brief intrTask infinite wait-for-interrupt loop
         *
         * repeatedly call intrTaskWait and processIntrQMsg
         *
         * @param[in] i_svc service object associated with task
         */
        static void* intrTask(void * i_svc);

        /**
         * @brief prdTask infinite wait-for-attention loop
         *
         * repeatedly call prdTaskWait and processAttentions
         *
         * @param[in] i_svc service object associated with task
         */
        static void* prdTask(void * i_svc);

        /**
         * @brief startIntrTask start task helper function
         *
         * check to see if task already started
         *
         * @return bool Operation status.
         *
         * @retval[true] task started
         * @retval[false] task not started
         */
        bool startIntrTask();

        /**
         * @brief intrTaskWait wait for message on msg Q
         *
         * Messages are either shutdown messages or messages from
         * the interrupt service.  Handle shutdown messages directly or
         * defer interrupt service messages to processIntrQMsg
         *
         * @post new message available.
         *
         * @param[out] o_msg interrupt svc intr message
         *
         * @return bool Shutdown instruction.
         *
         * @retval[true] shutdown requested
         * @retval[false] shutdown not requested
         */
        bool intrTaskWait(msg_t * & o_msg);

        /**
         * @brief processIntrQMsg process interrupt service message
         *
         * resolve interrupt service message into attentions and
         * route to prd for analysis
         *
         * @post attentions routed to prd for analysis
         *
         * @param[in] i_msg interrupt svc intr message to be processed
         */
        void processIntrQMsg(msg_t & i_msg);

        /**
         * @brief processIntrQMsgPreAck pre EOI interrupt service message
         *        processing
         *
         * Perform the interrupt service message processing steps that must
         * be done before EOI can be sent by the interrupt service.
         *
         * @post interrupt service message ready to be acknowledged
         *
         * @param[in] i_msg interrupt svc intr message to be processed
         */
        void processIntrQMsgPreAck(const msg_t & i_msg);

        /**
         * @brief startPrdTask start task helper function
         *
         * check to see if task already started
         *
         * @return bool Operation status.
         *
         * @retval[true] task started
         * @retval[false] task not started
         */
        bool startPrdTask();

        /**
         * @brief prdTaskWait wait for wakeup
         *
         * Wakeups are either shutdown wakeups or wakeups from
         * the interrupt task.  Handle shutdown wakeups directly or
         * defer interrupt task wakeups to processAttentions
         *
         * @post new attentions available
         *
         * @return bool Shutdown instruction.
         *
         * @retval[true] shutdown requested
         * @retval[false] shutdown not requested
         */
        bool prdTaskWait();

        /**
         * @brief processAttentions process interrupt task wakeup
         *
         * call prd to analyze attentions
         *
         * @param[i_procs] procs to check for attentions behind
         *
         * @post attentions analyzed by prd.  attentions cleared by prd unmasked
         */
        void processAttentions(const TARGETING::TargetHandleList & i_procs);

        /**
         * @brief iv_interrupt PRD thread wakeup indicator
         */
        bool iv_interrupt;

        /**
         * @brief iv_intrTaskQ intr task message q
         */
        msg_q_t iv_intrTaskQ;

        /**
         * @brief iv_shutdownPrdTask prd task shutdown flag
         */
        bool iv_shutdownPrdTask;

        /**
         * @brief iv_prdTask prd task tid
         */
        tid_t iv_prdTask;

        /**
         * @brief iv_intrTask intr task tid
         */
        tid_t iv_intrTask;

        /**
         * @brief iv_mutex pendingAttentions protection
         */
        mutex_t iv_mutex;

        /**
         * @brief iv_cond pendingAttentions and shutdown flag condition
         */
        sync_cond_t iv_cond;

        /**
         * @brief copy disabled
         */
        Service(const Service &);

        /**
         * @brief assignment disabled
         */
        Service &operator=(const Service &);

        /**
         * @brief AttnSvcTest Provide access to unit test.
         */
        friend class ::AttnSvcTest;
        friend class ::AttnProcTest;
        friend class ::AttnMemTest;
};
}
#endif
