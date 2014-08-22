/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attnfakepresenter.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __TEST_ATTNFAKEPRESENTER_H
#define __TEST_ATTNFAKEPRESENTER_H

/**
 * @file attnfakepresenter.H
 *
 * @brief HBATTN fake interrupt presenter class definition.
 */

#include "sys/sync.h"
#include "sys/task.h"
#include "sys/msg.h"
#include "attntest.H"

namespace ATTN
{

/**
 * @brief FakePresenter
 *
 * HBATTN fake interrupt presenter class definition.
 */
class FakePresenter
{
    public:

        /**
         * @brief start
         *
         * Start the fake interrupt presenter.
         *
         * @param[in] i_q The message queue on which to place
         *                interrupt messages.
         *
         * @retval[true] Started succesfully.
         * @retval[false] Did not start succesfully.
         */
        bool start(msg_q_t i_q);

        /**
         * @brief stop
         *
         * Stop the fake interrupt presenter.
         *
         * @post All resources reclaimed.
         */
        void stop();

        /**
         * @brief interrupt
         *
         * Instruct the fake presenter to raise an interrupt.
         *
         * @param[in] i_source Interrupt source.
         * @param[in] i_type Interrupt type.
         * @param[in] i_data User pointer passed to callback.
         * @param[in] i_callback Function to call at EOI.
         */
        void interrupt(
                TARGETING::TargetHandle_t i_source,
                MessageType i_type,
                void * i_data,
                void (*i_callback)(
                    TARGETING::TargetHandle_t, MessageType, void *));

        /**
         * @brief ctor.
         */
        FakePresenter();

        /**
         * @brief dtor.
         */
        ~FakePresenter();

    private:

        /**
         * @brief wait
         *
         * Listen for fake interrupt requests.
         *
         * @param[in] i_q The message queue on which to place
         *                interrupt messages.
         *
         * @retval[true] Shutdown requested.
         * @retval[false] Shutdown not requested.
         */
        bool wait(msg_q_t i_q);

        /**
         * @brief main static wrapper for wait.
         *
         * @param[in] i_properties The presenter on which to call wait.
         */
        static void* main(void * i_properties);

        /**
         * @brief iv_mutex Shared data access serialization.
         */
        mutex_t iv_mutex;

        /**
         * @brief iv_tid
         */
        tid_t iv_tid;

        /**
         * @brief iv_recvQ The message Q on which to listen for interrupt
         *                 requests.
         */
        msg_q_t iv_recvQ;

        /**
         * @brief copy disabled.
         */
        FakePresenter(const FakePresenter &);

        /**
         * @brief assignment disabled.
         */
        FakePresenter & operator=(const FakePresenter &);
};
}
#endif
