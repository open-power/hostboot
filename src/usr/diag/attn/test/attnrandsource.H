/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnrandsource.H $
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
         * @param[in] i_system The fake hardware on which to inject attentions.
         * @param[in] i_first The start of the range from which to
         *                         generate attentions.
         * @param[in] i_last The end of the range from which to
         *                         generate attentions.
         */
        RandSource(
                uint64_t i_iterations,
                uint64_t i_maxAttnsPerIteration,
                FakeSystem & i_system,
                TARGETING::TargetHandle_t * i_rangeStart,
                TARGETING::TargetHandle_t * i_rangeEnd);

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
         * @brief run Execute the testcase.
         */
        void run();

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
         * @brief iv_system The system on which attentions are injected.
         */
        FakeSystem * iv_system;

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
