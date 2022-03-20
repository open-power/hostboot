/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/test/testruncommand.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <runtime/interface.h>
#include <string.h>
#include <stdio.h>
#include "utilbase.H"

//See rt_cmds.C
namespace Util
{
int hbrtCommand( int argc,
                 const char** argv,
                 char** o_outString );
}
//Use a macro for easy function name changes
#define RUN_COMMAND Util::hbrtCommand

class RunCommandTest : public CxxTest::TestSuite
{
  public:
    /**
     *  @brief Test basic command/response
     */
    void testRunCommand()
    {
        int argc = 2;

        char arg0[10]; memcpy( arg0, "testRunCommand", 15 );
        char arg1[10]; memcpy( arg1, "arg1", 5 );

        const char* argv[] = { arg0, arg1 };

        char* outstr = NULL;

        //if (&Util::hbrtCommand != getRuntimeInterfaces()->run_command)
        //{
        //    TS_FAIL("testRunCommand: run_command function pointer is not set to Util::hbrtCommand()");
        //    return;
        //}

        int rc = RUN_COMMAND( argc, argv, &outstr );

        TRACFCOMP( Util::g_util_trace, "testRunCommand> rc=%d :: %s",
                                        rc, outstr == NULL ? "null" : outstr );

        char expected[21];
        sprintf( expected, "TEST:arg1" );

        if( strcmp( outstr, expected ) )
        {
            TS_FAIL( "testRunCommand> Unexpected result : Exp=%s, Act=%s",
                     expected, outstr );
        }

        if( outstr )
        {
            delete[] outstr;
        }
    }

    /**
     *  @brief Test invalid parms
     */
    void testRunCommandBad(void)
    {
        int rc = 0;

        rc = RUN_COMMAND( 0, NULL, NULL );
        if( rc )
        {
            TS_FAIL( "testRunCommandBad> Error from no args" );
        }
    }


    /**
     *  @brief Test scom operations
     */
    void testRunCommandScom(void)
    {
        int rc = 0;
        char* outstr = NULL;

        char arg0[10]; memcpy( arg0, "getscom", 8 );
        char arg1[15]; memcpy( arg1, "0x00050000", 11 );//proc0
        char arg2[15]; memcpy( arg2, "0x02010803", 11 );//CXA FIR Mask
        char arg3[30]; memcpy( arg3, "0x1122334455667788", 19 );
        const char* argv[] = { arg0, arg1, arg2, arg3 };

        // do a read
        rc = RUN_COMMAND( 3, argv, &outstr );
        if( rc )
        {
            TS_FAIL( "testRunCommandScom1> rc=%d", rc );
        }
        TRACFCOMP( Util::g_util_trace, "testRunCommandScom1> rc=%d :: %s",
                                        rc, outstr == NULL ? "null" : outstr );
        if( outstr ) delete[] outstr;

        // do a write
        memcpy( arg0, "putscom", 8 );
        rc = RUN_COMMAND( 4, argv, &outstr );
        if( rc )
        {
            TS_FAIL( "testRunCommandScom2> rc=%d", rc );
        }
        TRACFCOMP( Util::g_util_trace, "testRunCommandScom2> rc=%d :: %s",
                                        rc, outstr == NULL ? "null" : outstr );
        if( outstr ) delete[] outstr;

        // read again to check data (in trace only)
        memcpy( arg0, "getscom", 8 );
        rc = RUN_COMMAND( 3, argv, &outstr );
        if( rc )
        {
            TS_FAIL( "testRunCommandScom3> rc=%d", rc );
        }
        TRACFCOMP( Util::g_util_trace, "testRunCommandScom3> rc=%d :: %s",
                                        rc, outstr == NULL ? "null" : outstr );
        if( outstr ) delete[] outstr;

    }


    /**
     *  @brief Test read HBRT version operation
     */
    void testRunCommandReadHbrtVersion(void)
    {
        int rc = 0;
        char* outstr = NULL;

        char arg0[20]; memcpy( arg0, "readHBRTversion", 16 );
        const char* argv[] = { arg0 };

        // do a read
        rc = RUN_COMMAND( 1, argv, &outstr );
        if( rc )
        {
            TS_FAIL( "testRunCommandReadHbrtVersion> rc=%d", rc );
        }
        if( outstr == NULL )
        {
            TS_FAIL( "testRunCommandReadHbrtVersion> outstr is NULL" );
        }
        TRACFCOMP( Util::g_util_trace,
                   "testRunCommandReadHbrtVersion> rc=%d :: %s",
                   rc, outstr == NULL ? "null" : outstr );
        if( outstr ) delete[] outstr;
    }
};
