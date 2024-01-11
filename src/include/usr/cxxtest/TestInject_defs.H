/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/cxxtest/TestInject_defs.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
/**
 *  @file TestInject_defs.H
 *
 *  @brief Definitions for CXX Test Injects
 */
#ifndef __TESTINJECT_DEFS_H
#define __TESTINJECT_DEFS_H

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
#include <stdint.h>
#include <sys/sync.h>

namespace CxxTest
{
    /**
     * @brief  Define the injects for Testcases
     */
    enum CxxTestInjects : uint8_t
    {
        INJECT_CLEAR,
        INJECT_NONE,
        MMIO_INJECT_IN_PROGRESS,
        MMIO_INJECT_OP_ERROR,
        MMIO_INJECT_CHECKSTOP,
        SBEIO_INJECT_IN_PROGRESS,
        SBEIO_INJECT_FIFO_HANG,
        SBEIO_INJECT_FIFO_BREAKAGE,
        SBEIO_INJECT_HRESET_ody_sbe_hreset,
        SBEIO_INJECT_HRESET_ody_sppe_check_for_ready,
        SBEIO_INJECT_HRESET_sendAttrUpdateRequest,
        SBEIO_INJECT_HRESET_ThermalSensorPolling,
        SBEIO_INJECT_HRESET_TWO_FAILS,
        SBEIO_INJECT_HRESET_SKIP_DUMP,
        MAX_CXX_TEST_INJECTS = 63,
    };

    class CxxTestInject
    {
        mutex_t iv_mutex;

      protected:
        CxxTestInjects iv_injects[MAX_CXX_TEST_INJECTS];

      public:
        CxxTestInject() : iv_injects{}
        {
            mutex_init(&iv_mutex);
        }
        /**
         * @brief  Activate an inject
         * @param[in]  i_test  enum for the testcase to activate
         */
        void set(CxxTestInjects i_test)
        {
            const auto lock    = scoped_mutex_lock(iv_mutex);
            iv_injects[i_test] = i_test;
        }
        /**
         * @brief  De-activate an inject
         * @param[in]  i_test  enum for the testcase to de-activate
         */
        void clear(CxxTestInjects i_test)
        {
            const auto lock    = scoped_mutex_lock(iv_mutex);
            iv_injects[i_test] = INJECT_CLEAR;
        }
        /**
         * @brief  Query if an inject for a testcase is active
         * @param[in]  i_test  enum for a testcase to query
         */
        bool isSet(CxxTestInjects i_test)
        {
            const auto lock = scoped_mutex_lock(iv_mutex);
            return (iv_injects[i_test] == i_test);
        }
    };
};

#endif
#endif
