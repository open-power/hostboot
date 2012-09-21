/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/test/ibscomtest.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
     *        Write value and read back to verify
     */
    void test_IBscom(void)
    {

        //TODO Enable and improve test cases  RTC: 52900
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
            TS_FAIL( "test_IBscom> ERROR : Unable to find a Centaur chip" );
            return;
        }
        l_testTarget = *(centaur_list.begin());

        uint64_t addr = 0x03010E03;
        uint64_t orig_data = 0;
        uint64_t data = 0x12345678FEEDB0B0;
        size_t op_size = sizeof(uint64_t);

        //Save of initial register content
        l_err = deviceRead( l_testTarget,
                            &orig_data,
                            op_size,
                            DEVICE_SCOM_ADDRESS(addr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Orig Read: Error from device : addr=0x%X, RC=%X",
                      addr, l_err->reasonCode() );
            TS_FAIL( "test_IBscom1> ERROR : Unexpected error log from read1" );
            fails++;
            errlCommit(l_err,IBSCOM_COMP_ID);
        }

        l_err = deviceOp( DeviceFW::WRITE,
                          l_testTarget,
                          &data,
                          op_size,
                          DEVICE_IBSCOM_ADDRESS(addr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Write: Error from device : addr=0x%X, RC=%X",
                      addr, l_err->reasonCode() );
            TS_FAIL( "ScomTest::test_IBscom> ERROR : Error log from write1" );
            fails++;
            errlCommit(l_err,IBSCOM_COMP_ID);
        }

        total++;

        l_err = deviceOp( DeviceFW::READ,
                          l_testTarget,
                          &data,
                          op_size,
                          DEVICE_IBSCOM_ADDRESS(addr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Read: Error from device : addr=0x%X, RC=%X",
                      addr, l_err->reasonCode() );
            TS_FAIL( "test_IBscom> ERROR : Error log from read2" );
            fails++;
            errlCommit(l_err,IBSCOM_COMP_ID);
        }

        total++;

        //Restore original data.
          l_err = deviceWrite( l_testTarget,
                               &orig_data,
                               op_size,
                               DEVICE_SCOM_ADDRESS(addr) );

        if( l_err )
        {
            TRACFCOMP(g_trac_ibscom,
                      "IBscomTest::test_IBscom> Write Orig Data: Error from device : addr=0x%X, RC=%X",
                      addr, l_err->reasonCode() );
            TS_FAIL( "test_IBscom> ERROR : Error log from write2" );
            fails++;
            errlCommit(l_err,IBSCOM_COMP_ID);
        }


        TS_TRACE("test_IBscom runs successfully!");
        TRACFCOMP(g_trac_ibscom,
                  "IBscomTest::test_IBscom> %d/%d fails",
                  fails, total );

        return;
    }



};

#endif
