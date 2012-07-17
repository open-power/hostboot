/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/testcore/kernel/misctest.H $
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
#ifndef __TESTCORE_KERNEL_MISC_H
#define __TESTCORE_KERNEL_MISC_H

#include <sys/misc.h>
#include <kernel/cpumgr.H>

/** @file misctest.H
 *
 *  Testcases for the system calls in sys/misc.h
 */

class MiscTest : public CxxTest::TestSuite
{
    public:

        /** Tests for cpu_spr_value() */
        void testCpuSprValue()
        {
            if (CpuManager::WAKEUP_MSR_VALUE != cpu_spr_value(CPU_SPR_MSR))
            {
                TS_FAIL("MSR value is not as expected.");
            }

            if (CpuManager::WAKEUP_LPCR_VALUE != cpu_spr_value(CPU_SPR_LPCR))
            {
                TS_FAIL("LPCR value is not as expected.");
            }
        }
};

#endif
