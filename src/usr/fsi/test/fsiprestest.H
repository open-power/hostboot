//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsi/test/fsiprestest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
                TS_TRACE("FSI-PRES: Testing target %x",
                          TARGETING::get_huid(*target)); 

                // Read presence detect.
                errlHndl_t l_errl = NULL;
                bool present = false;
                size_t l_size = 1;

                l_errl = deviceRead(*target, &present, l_size,
                                    DEVICE_PRESENT_ADDRESS());

                if (l_errl)
                {
                    TS_FAIL("FSI-PRES: Cannot perform presence detect. %x",
                             TARGETING::get_huid(*target));
                    TRACFCOMP(g_trac_fsi,
                              "Failed presence detect. %x",
                               TARGETING::get_huid(*target));
                }
                else if ((*target == l_masterChip) && (!present))
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
                        TS_FAIL("FSI-PRES: No error performing "
                                "read to non-present device. %x",
                                 TARGETING::get_huid(*target));
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
