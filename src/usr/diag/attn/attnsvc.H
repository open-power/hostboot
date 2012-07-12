/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnsvc.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
         * @brief ctor
         */
        Service();

        /**
         * @brief dtor
         */
        ~Service();

    private:

        /**
         * @brief intrTask infinite wait-for-interrupt loop
         *
         * repeatedly call intrTaskWait and processIntrQMsg
         *
         * @param[in] i_svc service object associated with task
         */
        static void intrTask(void * i_svc);

        /**
         * @brief prdTask infinite wait-for-attention loop
         *
         * repeatedly call prdTaskWait and processAttentions
         *
         * @param[in] i_svc service object associated with task
         */
        static void prdTask(void * i_svc);

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
         * perform the interrupt service message processing steps that must
         * be done before EOI can be sent by the interrupt service.  Namely
         * resolve and mask the interrupt causing attentions.
         *
         * @post interrupt service message ready to be acknowledged
         *
         * @param[in] i_msg interrupt svc intr message to be processed
         * @param[out] o_attentions attentions associated with interrupt msg
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] no error
         * @retval[!0] unexpected error
         */
        errlHndl_t processIntrQMsgPreAck(const msg_t & i_msg,
                AttentionList & o_attentions);

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
        bool prdTaskWait(AttentionList & o_attentions);

        /**
         * @brief processAttentions process interrupt task wakeup
         *
         * call prd to analyze attentions
         *
         * @post attentions analyzed by prd.  attentions cleard by prd unmasked
         *
         * @param[in] i_attentions attentions to be processed by prd
         */
        void processAttentions(const AttentionList & i_attentions);

        /**
         * @brief iv_attentions all active attentions in the node
         */
        AttentionList iv_attentions;

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
