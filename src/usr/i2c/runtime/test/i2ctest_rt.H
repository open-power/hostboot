/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/runtime/test/i2ctest_rt.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __I2CTEST_RT_H
#define __I2CTEST_RT_H

/**
 *  @file i2ctest_rt.H
 *
 *  @brief Test cases for I2C code inside HBRT
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include <i2c/i2c.H>

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


class I2CTestRuntime: public CxxTest::TestSuite
{
    public:

        /**
         * @brief Test the I2C lock functionality
         */
        void test_i2c_lock( void )
        {
            // Simics doesn't support the Atomic Lock function
            //  so all we can do is test that our function to
            //  clear it out runs without an error
            
        }

};

#endif
