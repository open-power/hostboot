/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/test/fsiprestest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __FSIPRESTEST_H
#define __FSIPRESTEST_H

/**
 * @file fsiprestest.H
 * @brief Test cases for the FSI presence detect.
 */

#include <trace/interface.H>
#include <cxxtest/TestSuite.H>
#include <devicefw/userif.H>
#include <targeting/common/commontargeting.H>
#include <util/misc.H>

using namespace TARGETING;
using namespace DeviceFW;

extern trace_desc_t* g_trac_fsi;


class FSIPresTest : public CxxTest::TestSuite
{
    public:

        /** @brief Verify presence state matches the apparent FSI bus states.
         *
         * Performs a presence detect on every processor and memory, followed
         * by an FSI access to the device.  Ensures we get an error on every
         * non-present device and we do not get an error for any present
         * device.
         */
        void testPresence()
        {
            Target* l_masterChip = NULL;
            targetService().masterProcChipTargetHandle(l_masterChip);

            // Filter for just processor and mem-buffers.
            PredicateCTM l_proc(CLASS_NA,TYPE_PROC);
            PredicateCTM l_membuf(CLASS_NA,TYPE_MEMBUF);
            PredicatePostfixExpr l_expr;
            l_expr.push(&l_proc).push(&l_membuf).Or();

            TargetRangeFilter target(targetService().begin(),
                                     targetService().end(),
                                     &l_expr);

            // Iterate through all processors and mem-buffers.
            while(target)
            {
                TS_INFO("FSI-PRES: Testing target %x",
                          TARGETING::get_huid(*target));

                // Read presence detect.
                errlHndl_t l_errl = NULL;
                bool present = false;

                auto hwasState = target->getAttr<TARGETING::ATTR_HWAS_STATE>();
                present = hwasState.present;

                if ((*target == l_masterChip) && (!present))
                {
                    TS_FAIL("FSI-PRES: Claiming master chip is not present!");
                }
                else // Attempt FSI read.
                {

                    // Determine a valid FSI address to read.
                    uint64_t fsi_address = 0x1028; // CHIPID address
                    if (*target == l_masterChip)
                    {
                        fsi_address = 0x3474;  //MFSI MVER address
                    }

                    // Perform FSI read.
                    uint32_t fsi_data = 0;
                    size_t op_size = sizeof(fsi_data);
                    l_errl = deviceRead(*target, &fsi_data, op_size,
                                        DEVICE_FSI_ADDRESS(fsi_address));

                    // Verify we get an FSI error if device is not present or
                    // we do not get an FSI error if device is present.
                    if (present && l_errl)
                    {
                        TS_FAIL("FSI-PRES: "
                                "Error performing read to present device. %x",
                                 TARGETING::get_huid(*target));
                        TRACFCOMP(g_trac_fsi,
                                  "FSI-PRES: FSI-read failed with %d on %x",
                                  l_errl->reasonCode(),
                                  TARGETING::get_huid(*target));
                        // commit this log for debug
                        l_errl->collectTrace("UNIT_TEST",512);
                        errlCommit(l_errl,FSI_COMP_ID);
                    }
                    else if (!present && !l_errl)
                    {
                        if( Util::isMultiprocSupported() )
                        {
                            TS_FAIL("FSI-PRES: No error performing "
                                    "read to non-present device. %x",
                                    TARGETING::get_huid(*target));
                        }
                        TRACFCOMP(g_trac_fsi,
                                  "FSI-PRES: FSI-read did not fail. %x",
                                   TARGETING::get_huid(*target));
                    }
                    else
                    {
                        TS_TRACE("FSI-PRES: Read chip-id %x on %x",
                                 fsi_data, TARGETING::get_huid(*target));
                    }

                    // Delete any logs that got produced
                    if( l_errl )
                    {
                        delete l_errl;
                    }
                }

                ++target;
            }
        }
};

#endif
