/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfProcLogParse.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

/** @file  prdfProcLogParse.C
 *  @brief Error log parsing code specific to the processor subsystem.
 */

#include <prdfProcLogParse.H>

#include <errlusrparser.H>
#include <cstring>
#include <iipconst.h>
#include <prdfParserEnums.H>
#include <netinet/in.h>
#include <prdfPlatProcConst.H>

namespace PRDF
{

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

using namespace PARSER;
using namespace TOD;

//------------------------------------------------------------------------------

bool parseSlwFfdcData( uint8_t * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser )
{
    char hdr[HEADER_SIZE] = "";
    char data[DATA_SIZE]  = "";

    snprintf( hdr, HEADER_SIZE, " %s", SLW_FFDC_DATA::title );
    i_parser.PrintString( hdr, "" );

    const size_t sz_word = sizeof(uint32_t);

    uint32_t idx = 0;
    while ( idx + SLW_FFDC_DATA::ENTRY_SIZE < i_buflen )
    {
        uint32_t addr, val0, val1;

        memcpy( &addr, &i_buffer[idx            ], sz_word );
        memcpy( &val0, &i_buffer[idx+(1*sz_word)], sz_word );
        memcpy( &val1, &i_buffer[idx+(2*sz_word)], sz_word );

        addr = htonl(addr);
        val0 = htonl(val0);
        val1 = htonl(val1);

        snprintf(hdr,  HEADER_SIZE, "  Address: 0x%08x", addr );
        snprintf(data, DATA_SIZE,   "Value: 0x%08x 0x%08x", val0, val1 );

        i_parser.PrintString( hdr, data );

        idx += SLW_FFDC_DATA::ENTRY_SIZE;
    }

    return true;
}

//------------------------------------------------------------------------------

bool parseTodFfdcData(  uint8_t * i_buffer, uint32_t i_buflen,
                        ErrlUsrParser & i_parser )
{
    char data[DATA_SIZE]  = "";
    bool o_rc = true;
    i_parser.PrintString("TOD Error Data", "" );
    TodErrorSummary errorData;
    size_t szData = sizeof(TodErrorSummary);

    do
    {
        if( NULL == i_buffer )
        {
            o_rc = false;
            break;
        }

        if( i_buflen < szData )
        {
            o_rc = false;
            i_parser.PrintHexDump(i_buffer, i_buflen);
            break;
        }

        memcpy( &errorData, i_buffer, szData );

        i_parser.PrintBool( "Master Path Switch by HW",
                            errorData.hardwareSwitchFlip  );

        i_parser.PrintBool( "Host Detected TOD Error",
                            errorData.phypDetectedTodError );

        i_parser.PrintBool( "Host Switched Topology",
                            errorData.topologySwitchByPhyp );

        i_parser.PrintBool( "Topology Reset Requested",
                            errorData.topologyResetRequested );

        i_parser.PrintString( "Active Topology",
                              errorData.activeTopology ?
                              "Primary Config" : "Secondary Config" );

        i_parser.PrintNumber( "Functional TOD Osc", "0x%08x",
                              errorData.todOscCnt );

        snprintf(data,  DATA_SIZE, "0x%08x", errorData.activeMdmt );
        i_parser.PrintString( "Active MDMT", data );

        snprintf(data,  DATA_SIZE, "0x%08x", errorData.backUpMdmt );
        i_parser.PrintString( "Backup MDMT", data );

        char calloutSummary[LAST_TOD_ERROR][HEADER_SIZE] =
                                        { "No Error",
                                          "Master Path Error",
                                          "Internal Path Error",
                                          "Slave Path Network Error",
                                          "Unknown TOD Error" };

        errorData.activeTopologySummary =
                        errorData.activeTopologySummary % LAST_TOD_ERROR;
        errorData.backUpTopologySummary =
                        errorData.backUpTopologySummary % LAST_TOD_ERROR;

        i_parser.PrintString( "Active Topology Summary",
                              calloutSummary[errorData.activeTopologySummary] );

        i_parser.PrintString( "Active Topology M Path",
                              errorData.activeTopologyMastPath == 0 ?
                              "Path 0" : "Path 1" );

        i_parser.PrintString( "Backup Topology Summary",
                              calloutSummary[errorData.backUpTopologySummary] );

        i_parser.PrintString( "Backup Topology M Path",
                              errorData.backUpTopologyMastPath == 0 ?
                              "Path 0" : "Path 1" );
    }while(0);

    return o_rc;
}

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

