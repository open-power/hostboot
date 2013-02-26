/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/test/ibscomtest.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
            TS_FAIL( "test_IBscom> ERROR : Unable to find a Centaur chip" );
            return;
        }
        l_testTarget = *(centaur_list.begin());

        TRACDCOMP(g_trac_ibscom,
                  "IBscomTest::test_IBscom> Read orignal data from Centaur");


        const uint64_t addrs[] = {0x0201164F, 0x0301069A};
        uint64_t orig_data[2] = {0};
        uint64_t new_data[] = {0x1234567ABABABA00, 0xFEEDB0B0FEDCBA00};
        uint64_t read_data[2] = {0};
        uint64_t read_data_fsi[2] = {0};
        size_t op_size = sizeof(uint64_t);

        //Save of initial register content
        for(uint32_t i=0; i<2; i++)
        {
            op_size = sizeof(uint64_t);
            l_err = deviceRead( l_testTarget,
                                &orig_data[i],
                                op_size,
                                DEVICE_SCOM_ADDRESS(addrs[i]) );
            if( l_err )
            {
                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Orig Read: Error from device : addr=0x%X, RC=%X",
                          addrs[i], l_err->reasonCode() );
                TS_FAIL( "test_IBscom1> ERROR : Unexpected error log from saving original data." );
                fails++;
                errlCommit(l_err,IBSCOM_COMP_ID);
            }
            total++;

        }

        //Write in some new data
        for(uint32_t i=0; i<2; i++)
        {
            TRACDCOMP(g_trac_ibscom,"IBscomTest::test_IBscom> Write new pattern: 0x%.16X", new_data[i]);

            op_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::WRITE,
                              l_testTarget,
                              &new_data[i],
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

            if(new_data[i] != read_data[i])
            {
                TS_FAIL( "test_IBscom> ERROR : Data miss-match on IBSCOM read-back check." );

                TRACFCOMP(g_trac_ibscom,"IBscomTest::test_IBscom>ERROR: addr=0x%.8x: Write data=0x%.16X, IBSCOM read data=0x%.16X",
                          addrs[i], new_data[i], read_data[i]);
                fails++;
            }

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

            if(new_data[i] != read_data_fsi[i])
            {
                TS_FAIL( "test_IBscom> ERROR : Data miss-match on FSI read-back check." );

                TRACFCOMP(g_trac_ibscom, "IBscomTest::test_IBscom>ERROR: addr=0x%.8x: Write data=0x%.16X, FSI read data=0x%.16X",
                          addrs[i], new_data[i], read_data_fsi[i]);
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

    //TODO RTC: 68733: Add error path test cases when simics support
    //is available

};

#endif
