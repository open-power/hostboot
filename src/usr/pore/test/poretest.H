/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/test/poretest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __PORETEST_H
#define __PORETEST_H

/**
 *  @file poretest.H
 *
 *  @brief Test case for POREVE code
*/

#include <vector>
#include <cxxtest/TestSuite.H>
#include <targeting/common/commontargeting.H>
#include <fapiPoreVeArg.H>
#include <fapiTarget.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <vfs/vfs.H>
#include <errl/errlmanager.H>

#define CENTAUR_SBE_PNOR_MRR    0     // Memory Relocation Register for Centaur


using namespace TARGETING;
using namespace vsbe;
extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
                   std::vector<FapiPoreVeArg *> & io_sharedObjectArgs);

class PoreTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief PORE test #2
     *        Run a sample procedure on Proc
     */
    void testPore2(void)
    {
        // @todo - Add code to run sbe image from Proc when available

        return;
    }

};

#endif
