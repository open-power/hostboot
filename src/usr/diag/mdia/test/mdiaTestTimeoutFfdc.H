/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiaTestTimeoutFfdc.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __TEST_MDIATESTTIMEOUTFFDC_H
#define __TEST_MDIATESTTIMEOUTFFDC_H

/**
 * @file mdiaTestTimeoutFfdc.H
 * @brief Timeout FFDC collection unit test
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include "../mdiasm.H"
#include "../mdiasmimpl.H"
#include <targeting/common/utilFilter.H>
#include "../mdiatrace.H"
#include "../mdiamonitor.H"
#include "../mdiafwd.H"
#include <sys/time.h>

using namespace MDIA;
using namespace TARGETING;

class MdiaTimeoutFfdcTest : public CxxTest::TestSuite
{
    private:

        TargetHandle_t getTarget()
        {
            TargetHandleList tmp;
            TARGETING::getAllChips(tmp, TYPE_OCMB_CHIP);
            TS_INFO("MdiaTimeoutFfdcTest getAllChips tmp.size=%d", tmp.size());
            return tmp[0];
        }

    public:

        void testTimeoutFfdc(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_INFO(ENTER_MRK "testOcmbTimeoutFfdc");

            // Just call addTimeoutFFDC with some appropriate target to ensure
            // it doesn't assert or crash.
            TargetHandle_t trgt = getTarget();
            errlHndl_t err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    PROCESS_COMMAND_TIMEOUT,
                    MAINT_COMMAND_SW_TIMED_OUT,
                    get_huid(trgt) );
            addTimeoutFFDC( trgt, err );

            TS_INFO(EXIT_MRK "testOcmbTimeoutFfdc");
        }

};
#endif
