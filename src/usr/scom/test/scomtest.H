//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/scom/test/scomtest.H $
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
#ifndef __SCOMTEST_H
#define __SCOMTEST_H

/**
 *  @file scomtest.H
 *
 *  @brief Test case for SCOM code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <devicefw/userif.H>
#include <fsi/fsiif.H>



extern trace_desc_t* g_trac_scom;


class ScomTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief SCOM test via FSISCOM
     *     
     */
    void test_FSISCOMreadWrite(void)
    {
        TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite> Start" );

        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;

        TARGETING::Target* fsi_target = NULL;

        // Target Proc 1 - the FSI wrap-back connection in simics
        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,9);
        fsi_target = TARGETING::targetService().toTarget(epath);

        //only run if the target exists and has FSI enabled.
        if(fsi_target == NULL)
        {
            TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite> FSI Target not found, exiting test" );
            return;
        }
        else if((TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == fsi_target) ||
                (fsi_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom))
        {
            TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite> Target is the MASTER Sentinal or is set to use Xscom, exiting test" );
            return;
        }
        else if(0 == fsi_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useFsiScom)
        {
            TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite> useFsiScom set to zero, exiting test" );
            return;
        }

        // scratch data to use
        //@fixme: Need to either fabricate some fake registers to use or save off data before modifying SCOMs to avoid
        //   corrupting the HW.
        struct {
            uint64_t addr;
            uint64_t data;
        } test_data[] = {
            { 0x120F0000 ,0xFEEDB0B000001234}, 
            { 0x120F0166, 0xFEDCBA9876543210}, 
            { 0x00040005, 0x0000000000000000}, 
            { 0x02040004, 0xFFFFFFFFFFFFFFFF}, 

        };
        const uint64_t NUM_ADDRS = sizeof(test_data)/sizeof(test_data[0]);

        // allocate space for read data
        uint64_t read_data[NUM_ADDRS];
        size_t op_size = sizeof(uint32_t);

        // write all the test registers
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )   
        {
            op_size = sizeof(uint64_t);

            total++;
            l_err = deviceWrite( fsi_target,
                                &(test_data[x].data),
                                op_size,
                                DEVICE_SCOM_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite> Write: Error from device : addr=0x%X, RC=%X", test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "ScomTest::test_FSISCOMreadWrite> ERROR : Unexpected error log from write1" );
                fails++;
                errlCommit(l_err,SCOM_COMP_ID);
                delete l_err;
            }
        }

         // read all the test registers
        for( uint64_t x = 0; x < NUM_ADDRS; x++ )   
        {
            op_size = sizeof(uint64_t);

            total++;
            l_err = deviceRead( fsi_target,
                                 &(read_data[x]),
                                 op_size,
                                 DEVICE_SCOM_ADDRESS(test_data[x].addr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite> read: Error from device : addr=0x%X, RC=%X", test_data[x].addr, l_err->reasonCode() );
                TS_FAIL( "ScomTest::test_FSISCOMreadWrite> ERROR : Unexpected error log from write1" );
                fails++;
                errlCommit(l_err,SCOM_COMP_ID);
                delete l_err;
            }
            else if(read_data[x] != test_data[x].data)
            {
                TRACFCOMP(g_trac_scom, "ScomTest::test_FSISCOMreadWrite> read: Data miss-match : addr=0x%X, read_data=0x%llx, write_data=0x%llx", test_data[x].addr, read_data[x], test_data[x].data);
                TS_FAIL( "ScomTest::test_FSISCOMreadWrite> ERROR : Data miss-match between read and expected data" );
                fails++;
            }
        }

                TRACFCOMP( g_trac_scom, "ScomTest::test_FSISCOMreadWrite> %d/%d fails", fails, total );

    }


  //@todo - write tests to verify connection between XSCOM and FSISCOM

};

#endif
