/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/test/ibscomtest.H $                            */
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
#ifndef __IBSCOMTEST_H
#define __IBSCOMTEST_H

/**
 *  @file ibscomtest.H
 *
 *  @brief Test case for inband scom code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <ibscom/ibscomreasoncodes.H>
#include <devicefw/driverif.H>
#include <sys/time.h>

extern trace_desc_t* g_trac_ibscom;

using namespace TARGETING;


class IBscomTest: public CxxTest::TestSuite
{
  public:

    /**
     * @brief inband scom test #1
     *        Write values and read back to verify
     */
    void test_IBscom(void)
    {

        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;

        TARGETING::Target* l_testTarget = NULL;

        // Target: Find a Centaur on the Master processor
        TARGETING::Target* l_procTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_procTarget);
        assert(l_procTarget != NULL);

        TARGETING::PredicateCTM l_cent(TARGETING::CLASS_CHIP,
                                       TARGETING::TYPE_MEMBUF,
                                       TARGETING::MODEL_NA);
        TARGETING::PredicateHwas functionalPredicate;
        functionalPredicate.functional(true);

        TARGETING::PredicatePostfixExpr cent_query;
        cent_query.push(&l_cent).push(&functionalPredicate).And();

        TARGETING::TargetHandleList centaur_list;
        TARGETING::targetService().
          getAssociated(centaur_list,
                        l_procTarget,
                        TARGETING::TargetService::CHILD_BY_AFFINITY,
                        TARGETING::TargetService::ALL,
                        &cent_query);

        if( centaur_list.size() < 1 )
        {
            TS_FAIL( "test_IBscom> ERROR : Unable to find a Centaur chip" );
            return;
        }
        l_testTarget = *(centaur_list.begin());
        TRACFCOMP(g_trac_ibscom,"test_IBscom> Using target %.8X", TARGETING::get_huid(l_testTarget));

        ScomSwitches l_switches = l_testTarget->getAttr<ATTR_SCOM_SWITCHES>();
        if( !l_switches.useInbandScom )
        {
            TRACFCOMP(g_trac_ibscom,"Skipping test_IBscom because ibscom is not enabled");
            return;
        }

        TRACDCOMP(g_trac_ibscom,
                  "IBscomTest::test_IBscom> Read original data from Centaur");


        const uint64_t addrs[] = {0x02010803/*0:26*/, 0x03010403/*0:21*/};
        uint64_t orig_data[2] = {0};
        uint64_t new_data1[] = {0x123456E000000000, 0xFEEDB00000000000};
        uint64_t read_data[2] = {0};
        uint64_t read_data_fsi[2] = {0};
        size_t op_size = sizeof(uint64_t);
        const uint64_t junk = 0x1122334455667788;

        //Save off initial register content via FSI
        for(uint32_t i=0; i<2; i++)
        {
            op_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::READ,
                              l_testTarget,
                              &orig_data[i],
                              op_size,
                              DEVICE_FSISCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Orig Read: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "test_IBscom1> ERROR : Unexpected error log from saving original data." );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }
            total++;

            // OR in the original data so we don't clear mask bits
            new_data1[i] |= orig_data[i];
        }

        //Read the data with IBSCOM
        for(uint32_t i=0; i<2; i++)
        {
            TRACDCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Read data");

            //reset size
            op_size = sizeof(uint64_t);
            read_data[i] = junk;
            l_err = deviceOp( DeviceFW::READ,
                              l_testTarget,
                              &read_data[i],
                              op_size,
                              DEVICE_IBSCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Read: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "test_IBscom> ERROR : Error log from IBSCOM read" );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }

            if(orig_data[i] != read_data[i])
            {
                TS_FAIL( "test_IBscom> ERROR : Data miss-match on IBSCOM read check." );

                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom>ERROR: addr=0x%.8x: Write data=0x%.16X, IBSCOM read data=0x%.16X",
                          addrs[i], new_data1[i], read_data[i]);
                fails++;
            }

            total++;
        }

        //Write in some new data with IBSCOM
        for(uint32_t i=0; i<2; i++)
        {
            TRACDCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Write new pattern: 0x%.16X", new_data1[i]);

            op_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::WRITE,
                              l_testTarget,
                              &new_data1[i],
                              op_size,
                              DEVICE_IBSCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Write: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "ScomTest::test_IBscom> ERROR : Error log from IBSCOM Write" );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }
            nanosleep( 0, 1000000 ); //sleep for 1ms

            total++;
        }

        //Read the data back with FSISCOM
        for(uint32_t i=0; i<2; i++)
        {
            TRACDCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Read data back");

            //reset size
            op_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::READ,
                              l_testTarget,
                              &read_data_fsi[i],
                              op_size,
                              DEVICE_FSISCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom, "IBscomTest::test_IBscom> Read: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "test_IBscom> ERROR : Error log from FSI Read" );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }

            if(new_data1[i] != read_data_fsi[i])
            {
                TS_FAIL( "test_IBscom> ERROR : Data miss-match on FSI read-back check." );

                TRACFCOMP(g_trac_ibscom, "IBscomTest::test_IBscom>ERROR: addr=0x%.8x: Write data=0x%.16X, FSI read data=0x%.16X",
                          addrs[i], new_data1[i], read_data_fsi[i]);
                fails++;
            }
            total++;
        }

        //Write in some new data with FSISCOM
        uint64_t new_data2[] = {0xA5A5A50000000000/*0:26*/,
                                0x1122000000000000/*0:21*/};
        for(uint32_t i=0; i<2; i++)
        {
            TRACDCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Write new pattern: 0x%.16X", new_data2[i]);

            op_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::WRITE,
                              l_testTarget,
                              &new_data2[i],
                              op_size,
                              DEVICE_FSISCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Write: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "ScomTest::test_IBscom> ERROR : Error log from FSI Write" );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }

            total++;
        }


        //Read the data back with IBSCOM
        for(uint32_t i=0; i<2; i++)
        {
            TRACDCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Read data back");

            //reset size
            op_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::READ,
                              l_testTarget,
                              &read_data[i],
                              op_size,
                              DEVICE_IBSCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Read: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "test_IBscom> ERROR : Error log from IBSCOM read" );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }

            if(new_data2[i] != read_data[i])
            {
                TS_FAIL( "test_IBscom> ERROR : Data miss-match on IBSCOM read-back check." );

                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom>ERROR: addr=0x%.8x: Write data=0x%.16X, IBSCOM read data=0x%.16X",
                          addrs[i], new_data1[i], read_data[i]);
                fails++;
            }

            total++;
        }

        //Restore original data.
        for(uint32_t i=0; i<2; i++)
        {
            op_size = sizeof(uint64_t);
            l_err = deviceWrite( l_testTarget,
                                 &orig_data[i],
                                 op_size,
                                 DEVICE_SCOM_ADDRESS(addrs[i]) );

            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Write Orig Data: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "test_IBscom> ERROR : Error log from write2" );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }
        }

        TS_TRACE("test_IBscom runs successfully!");
        TRACFCOMP(g_trac_ibscom,
                  "IBscomTest::test_IBscom> %d/%d fails",
                  fails, total );

        return;
    }

    //TODO RTC: 72594: Add error path test cases when simics support
    //is available
    void test_IBscom_error(void)
    {
        TRACFCOMP(g_trac_ibscom,"Skipping test_IBscom_error because Simics is broken");
        return;

        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;

        TARGETING::Target* l_testTarget = NULL;

        // Target: Find a Centaur on the Master processor
        TARGETING::Target* l_procTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_procTarget);
        assert(l_procTarget != NULL);

        TARGETING::PredicateCTM l_cent(TARGETING::CLASS_CHIP,
                                       TARGETING::TYPE_MEMBUF,
                                       TARGETING::MODEL_NA);
        TARGETING::PredicatePostfixExpr cent_query;
        cent_query.push(&l_cent);


        TARGETING::TargetHandleList centaur_list;
        TARGETING::targetService().
          getAssociated(centaur_list,
                        l_procTarget,
                        TARGETING::TargetService::CHILD_BY_AFFINITY,
                        TARGETING::TargetService::ALL,
                        &cent_query);

        if( centaur_list.size() < 1 )
        {
            TS_FAIL( "test_IBscom_error> ERROR : Unable to find a Centaur chip" );
            return;
        }
        l_testTarget = *(centaur_list.begin());

        ScomSwitches l_switches = l_testTarget->getAttr<ATTR_SCOM_SWITCHES>();
        if( !l_switches.useInbandScom )
        {
            TRACFCOMP(g_trac_ibscom,"Skipping test_IBscom_error because ibscom is not enabled");
            return;
        }


        TRACDCOMP(g_trac_ibscom, "IBscomTest::test_IBscom_error> Read orignal data from Centaur");


        uint64_t new_data = 0x1234567ABABABA00;
        uint64_t read_data = 0;
        size_t op_size = sizeof(uint64_t);

        //Write a bad address
        uint64_t bad_addr = 0x02123456;
        TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom_error> Write bad address 0x%.16X", bad_addr);
        op_size = sizeof(uint64_t);
        l_err = deviceOp( DeviceFW::WRITE,
                          l_testTarget,
                          &new_data,
                          op_size,
                          DEVICE_IBSCOM_ADDRESS(bad_addr) );
        if( !l_err )
        {
            TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom_error> No error on bad address write" );
            TS_FAIL( "ScomTest::test_IBscom_error> No error on bad address write" );
            fails++;
        }
        else
        {
            delete l_err;
        }
        total++;
        nanosleep( 0, 1000000 ); //sleep for 1ms

        //Verify ibscom is still enabled, i.e. we didn't think it was a bus fail
        l_switches = l_testTarget->getAttr<ATTR_SCOM_SWITCHES>();
        total++;
        if( !l_switches.useInbandScom )
        {
            TS_FAIL( "ScomTest::test_IBscom_error> IBSCOM was wrongly disabled after bad address write" );
            fails++;
        }

        //Read a bad address
        bad_addr = 0x02876543;
        TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom_error> Write bad address 0x%.16X", bad_addr);
        op_size = sizeof(uint64_t);
        l_err = deviceOp( DeviceFW::READ,
                          l_testTarget,
                          &read_data,
                          op_size,
                          DEVICE_IBSCOM_ADDRESS(bad_addr) );
        if( !l_err )
        {
            TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom_error> No error on bad address read" );
            TS_FAIL( "ScomTest::test_IBscom_error> No error on bad address read" );
            fails++;
        }
        else
        {
            delete l_err;
        }
        total++;

        //Verify ibscom is still enabled, i.e. we didn't think it was a bus fail
        l_switches = l_testTarget->getAttr<ATTR_SCOM_SWITCHES>();
        total++;
        if( !l_switches.useInbandScom )
        {
            TS_FAIL( "ScomTest::test_IBscom_error> IBSCOM was wrongly disabled after bad address read" );
            fails++;
        }

        //Read a good address to prove things still work
        TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom_error> Read good address 0x%.16X", 0x02010803);
        op_size = sizeof(uint64_t);
        l_err = deviceOp( DeviceFW::READ,
                          l_testTarget,
                          &read_data,
                          op_size,
                          DEVICE_IBSCOM_ADDRESS(0x02010803) );
        if( l_err )
        {
            TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom_error> Error on read after fail" );
            TS_FAIL( "ScomTest::test_IBscom_error> Error on read after fail" );
            errlCommit(l_err,IBSCOM_COMP_ID);
            fails++;
        }
        total++;

        TS_TRACE("test_IBscom_error runs successfully!");
        TRACFCOMP(g_trac_ibscom,
                  "IBscomTest::test_IBscom_error> %d/%d fails",
                  fails, total );

        //TS_FAIL("FORCING ERROR TO STOP IPL");

        return;
    }
};

#endif
