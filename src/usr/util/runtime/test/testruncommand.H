/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/test/testruncommand.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <config.h>
#include <runtime/interface.h>
#include <string.h>
#include <stdio.h>
#include "utilbase.H"

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

        int rc = (getRuntimeInterfaces()->run_command)( argc, argv, &outstr );

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

        rc = (getRuntimeInterfaces()->run_command)( 0, NULL, NULL );
        if( rc )
        {
            TS_FAIL( "testRunCommandBad> Error from no args" );
        }
    }
};
