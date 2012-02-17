//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mbox/test/mboxddtest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __MBOXDDTEST_H
#define __MBOXDDTEST_H

/**
 *  @file mboxddtest.H
 *
 *  @brief Test cases for MBOX Device Driver
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/hberrltypes.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include <mbox/mboxif.H>

extern trace_desc_t* g_trac_mbox;

using namespace TARGETING;

class MboxDDTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief MBOX DD test - Write (STUB)
     *        Perform basic write operation
     */
    void testWrite(void)
    {
        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWrite(STUB)> Begin");
        /*
         * This test function should be updated to perform TWO write
         * operations. Without the SIMICS data loopback update, this
         * should cause errors to occur due to no ack back from FSP.
         *
         * Currently, without proper SIMICS support, this test function
         * will be stubbed out to allow checkin of this file.
         */
        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWrite(STUB)> End");
    }

    /**
     * @brief MBOX DD test - Write/Read
     *        Perform basic write then read operation
     *        Requires SIMICS data loopback from SP-to-Host (PIB-to-LBUS)
     */
    void _testWriteRead(void)
    {
        uint64_t o_status = 0;
        errlHndl_t l_err = NULL;
        uint32_t in_mboxMsg [] = {0x12345678, 0x14785236, 0x96325874,
                                  0x98765432, 0x78910112, 0x66660000};
        size_t in_size = sizeof(in_mboxMsg);
        uint32_t out_mboxMsg[16] = {0};
        size_t out_size = sizeof(out_mboxMsg);

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWriteRead> Begin");

        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,0);

        l_err = DeviceFW::deviceWrite(
                TARGETING::targetService().toTarget(epath),
                static_cast<void*>(in_mboxMsg),in_size,
                DEVICE_MBOX_ADDRESS(&o_status));
        if (l_err)
        {
            TS_FAIL("Unable to write to mailbox device.\n");
        }

        l_err = DeviceFW::deviceRead(
                TARGETING::targetService().toTarget(epath),
                static_cast<void*>(out_mboxMsg),out_size,
                DEVICE_MBOX_ADDRESS(&o_status));
        if (l_err)
        {
            TS_FAIL("Unable to read mailbox device.\n");
        }
        if (o_status != 0x00000005)//Xdn & PIB Pending
        {
            TS_FAIL("PIB interrupt register shows unexpected interrupt.\n");
        }

        for (uint32_t i=0; i<sizeof(in_mboxMsg)/sizeof(uint32_t); ++i)
        {
            if (out_mboxMsg[i] != in_mboxMsg[i])
            {
                TS_FAIL("Loopback data area mismatch.\n");
                break;
            }
        }

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWriteRead> End");
    };

};     

#endif
