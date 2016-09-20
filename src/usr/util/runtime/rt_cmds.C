/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_cmds.C $                              */
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
#include <runtime/interface.h>
#include <stdio.h>
#include <trace/interface.H>
#include <string.h>
#include "../utilbase.H"

/**
 * @brief  Execute an arbitrary command inside Hostboot Runtime
 * @param[in]   Number of arguments (standard C args)
 * @param[in]   Array of argument values (standard C args)
 * @param[out]  Response message (NULL terminated), memory allocated
 *              by hbrt, if o_outString is NULL then no response will
 *              be sent
 * @return 0 on success, else error code
 */
int hbrtCommand( int argc,
                 const char** argv,
                 char** o_outString )
{
    int rc = 0;
    UTIL_FT("Executing run_command : argc=%d, o_outString=%p",
                argc, o_outString);

    if( !argc )
    {
        UTIL_FT("run_command : Number of arguments = 0");
        return rc;
    }

    if( argv == NULL )
    {
        UTIL_FT("run_command : Argument array is empty");
        return rc;
    }

    for( int aa=0; aa<argc; aa++ )
    {
        UTIL_FT("run_command : %d=%s",aa,argv[aa]);
    }

    // If no output is specified, trace it instead
    bool l_traceOut = false;
    char* l_outPtr = NULL; //local value to use if needed
    char** l_output = o_outString;
    if( o_outString == NULL )
    {
        l_output = &l_outPtr;
        l_traceOut = true;
    }

    // Test path
    if( (argc == 2) && !strcmp( argv[0], "testRunCommand" ) )
    {
        *l_output = new char[strlen(argv[1])+1+5];//arg0+arg1+\0
        sprintf( *l_output, "TEST:%s", argv[1] );
    }

    if( l_traceOut && (*l_output != NULL) )
    {
        UTIL_FT("Output::%s",*l_output);
        delete *l_output;
    }

    return rc;
}


struct registerCmds
{
    registerCmds()
    {
        getRuntimeInterfaces()->run_command = &hbrtCommand;
    }
};

registerCmds g_registerCmds;

