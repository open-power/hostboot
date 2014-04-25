/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsiscom/test/fsiscomtest.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include <fsiscom/fsiscom_reasoncodes.H>

extern trace_desc_t* g_trac_fsiscom;

class FsiScomTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Test error path and recovery
     */
    void test_Error(void)
    {
        TRACFCOMP( g_trac_fsiscom, "FsiScomTest::test_Error> Start" );

        uint64_t fails = 0;
        uint64_t total = 0;
        errlHndl_t l_err = NULL;
        uint64_t regdata = 0;
        size_t op_size = sizeof(uint64_t);

        // Centaur target
        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_MEMBUF,4);
        TARGETING::Target* fsi_target =
          TARGETING::targetService().toTarget(epath);
        if( fsi_target == NULL )
        {
            TRACFCOMP( g_trac_fsiscom, "FsiScomTest::test_Error> Target is NULL" );
            TS_FAIL( "FsiScomTest::test_Error> Target is NULL" );
        }

        // Bad address read
        total++;
        l_err = DeviceFW::deviceOp(
                          DeviceFW::READ,
                          fsi_target,
                          &regdata,
                          op_size,
                          DEVICE_FSISCOM_ADDRESS(0x11111111) );
        if( l_err && (l_err->reasonCode() == FSISCOM::RC_READ_ERROR) )
        {
            delete l_err;
        }
        else
        {
            TRACFCOMP(g_trac_fsiscom, "FsiScomTest::test_Error> No/wrong error for bad address read, RC=%X", ERRL_GETRC_SAFE(l_err) );
            TS_FAIL( "FsiScomTest::test_Error> No/wrong error for bad address read" );
            fails++;
            if( l_err ) { errlCommit(l_err,FSISCOM_COMP_ID); }
        }

        // Bad address write
        total++;
        l_err = DeviceFW::deviceOp(
                          DeviceFW::WRITE,
                          fsi_target,
                          &regdata,
                          op_size,
                          DEVICE_FSISCOM_ADDRESS(0x00222222) );
        if( l_err && (l_err->reasonCode() == FSISCOM::RC_WRITE_ERROR) )
        {
            delete l_err;
        }
        else
        {
            TRACFCOMP(g_trac_fsiscom, "FsiScomTest::test_Error> No/wrong error for bad address write, RC=%X", ERRL_GETRC_SAFE(l_err) );
            TS_FAIL( "FsiScomTest::test_Error> No/wrong error for bad address write" );
            fails++;
            if( l_err ) { errlCommit(l_err,FSISCOM_COMP_ID); }
        }

        // Do a good scom to prove things are working again
        total++;
        l_err = DeviceFW::deviceOp(
                          DeviceFW::READ,
                          fsi_target,
                          &regdata,
                          op_size,
                          DEVICE_FSISCOM_ADDRESS(0x02011403) );
        if( l_err )
        {
            TRACFCOMP(g_trac_fsiscom, "FsiScomTest::test_Error> Error reading 0x02011403, RC=%X", ERRL_GETRC_SAFE(l_err) );
            TS_FAIL( "FsiScomTest::test_Error> Error reading 0x02011403" );
            fails++;
            errlCommit(l_err,FSISCOM_COMP_ID);
        }

        TRACFCOMP( g_trac_fsiscom, "FsiScomTest::test_Error> %d/%d fails", fails, total );
    };
};
