/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnrandsource.H $                     */
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
#ifndef __TEST_ATTNRANDSOURCE_H
#define __TEST_ATTNRANDSOURCE_H

/**
 * @file attnrandsource.H
 *
 * @brief HBATTN Random attention source class definitions.
 */

#include "attntest.H"
#include "sys/task.h"

namespace ATTN
{

/**
 * @brief RandSource
 *
 * Random attention generator testcase.
 */
class RandSource
{
    public:

        /**
         * @brief start Start the testcase thread.
         *
         * @retval[true] Testcase thread started succesfully.
         * @retval[false] Testcase thread failed to start.
         */
        bool start();

        /**
         * @brief wait Wait for the testcase to run to completion.
         *
         * @post All resources reclaimed.
         *
         * @retval[true] Testcase succesfully ran to completion.
         * @retval[false] Testcase did not run succesfully to completion.
         */
        bool wait();

        /**
         * @brief ctor
         *
         * @param[in] i_iterations The number of attentions to inject.
         * @param[in] i_maxAttnsPerIteration The upper bound on the number
         *               of attentions to inject per iteration.
         * @param[in] i_injectSink The hardware on which to inject attentions.
         * @param[in] i_first The start of the range from which to
         *                         generate attentions.
         * @param[in] i_last The end of the range from which to
         *                         generate attentions.
         */
        RandSource(
                uint64_t i_iterations,
                uint64_t i_maxAttnsPerIteration,
                InjectSink & i_injectSink,
                TARGETING::TargetHandle_t * i_rangeStart,
                TARGETING::TargetHandle_t * i_rangeEnd);

        /**
         * @brief run Execute the testcase.
         */
        void run();

        /**
         * @brief dtor
         */
        ~RandSource();

    private:

        /**
         * @brief main Static wrapper for run.
         *
         * @param[in] i_source The source on which to call run.
         */
        static void* main(void * i_source);

        /**
         * @brief iv_mutex Shared data access serialization.
         */
        mutex_t iv_mutex;

        /**
         * @brief iv_tid Testcase thread number.
         */
        tid_t iv_tid;

        /**
         * @brief iv_iterations The number of attentions to inject.
         */
        uint64_t iv_iterations;

        /**
         * @brief iv_max The upper bound on the number of attentions
         *               to inject per iteration.
         */
        uint64_t iv_max;

        /**
         * @brief iv_injectSink The system on which attentions are injected.
         */
        InjectSink * iv_injectSink;

        /**
         * @brief iv_rangeStart The start of the range from which to
         *                      generate attentions.
         */
        TARGETING::TargetHandle_t * iv_first;

        /**
         * @brief iv_rangeEnd The end of the range from which to
         *                      generate attentions.
         */
        TARGETING::TargetHandle_t * iv_last;

        /**
         * @brief copy disabled
         */
        RandSource(const RandSource &);

        /**
         * @brief assignment disabled
         */
        RandSource &operator=(const RandSource &);
};
}
#endif
