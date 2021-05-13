/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfProcLogParse.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#include <map>
#include <vector>
#include <string>

namespace PRDF
{

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

using namespace PARSER;
using namespace TOD;

/**
 * @brief Misc SCOM addresses
 */
enum
{
    P9N2_PU_OCB_OCI_OCCFLG_SCOM     =   0x0006C08A,
    P9N2_PU_OCB_OCI_OCCFLG2_SCOM    =   0x0006C18A,

};

/**
 * @brief error codes returned by parser.
 */
enum  ErrorCode
{
    PARSE_SUCCESS                       =   0,
    BAD_CORRUPT_BIN                     =   1,
    BIN_AND_PARSER_MAJ_VER_MISMATCH     =   2,
    BIN_AND_PARSER_MIN_VER_MISMATCH     =   3,
    SECTION_INVALID                     =   4,
    BAD_SCOM_ADDRESS                    =   5,
    BAD_PPE_ADDRESS                     =   6,
};

/**
 * @brief local constants.
 */
enum  BufLengths
{
    BUF_LENGTH      =   120,
    LINE_LENGTH     =    80,
    UPPER_BYTE_POS  =    10,
};

/**
 * @brief register types supported by parser.
 */
enum RegType
{
    PPE_XIR     =   0x01,
    SCOM_REG    =   0x02,
};

/**
 * @brief codes for various PPE's SPRs
 */
enum PpeSprs
{
    CTR     =   9,
    DACR    =   316,
    DBCR    =   308,
    DEC     =   22,
    EDR     =   61,
    IVPR    =   63,
    ISR     =   62,
    LR      =   8,
    PIR     =   286,
    PVR     =   287,
    SPRG0   =   272,
    SRR0    =   26,
    SRR1    =   27,
    TCR     =   340,
    TSR     =   336,
    XER     =   1,
    //XIRs
    XSR     =   4200,
    IAR     =   2,
    IR      =   3,
    MSR     =   42,
    CR      =   420,
};

/**
 * Misc constants local to file.
 */
enum
{
    MAX_EQ          =       6,
    MAX_CPPM        =       24,
    INVALID_DATA    =       0x212d2d21212d2d21ull,
    MAX_XIR_NAME    =       5,
};

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
        if( nullptr == i_buffer )
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

//------------------------------------------------------------------------------

bool parseL2LdCrFfdc( uint8_t * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    bool o_rc = true;

    const char * lines = "---------------------------------------------";
    i_parser.PrintString( LD_CR_FFDC::L2TITLE, lines );

    do
    {
        if ( nullptr == i_buffer ) { o_rc = false; break; }

        if ( i_buflen < sizeof(LD_CR_FFDC::L2LdCrFfdc) )
            { o_rc = false; break; }

        LD_CR_FFDC::L2LdCrFfdc ldcrffdc;
        memcpy( &ldcrffdc, i_buffer, sizeof(LD_CR_FFDC::L2LdCrFfdc));

        i_parser.PrintNumber( "   L2 LD Counts", "%d", ldcrffdc.L2LDcnt );
        i_parser.PrintNumber( "   L2 LD Max Allowed", "%d",
                                              ldcrffdc.L2LDMaxAllowed );
        i_parser.PrintNumber( "   L2 CR Max Allowed", "%d",
                                              ldcrffdc.L2CRMaxAllowed );
        i_parser.PrintNumber( "   L2 CR Present", "%d",
                                              ldcrffdc.L2CRPresent );

        i_parser.PrintNumber( "   L2 Error Member", "%d",
                                               ldcrffdc.L2errMember );
        i_parser.PrintNumber( "   L2 Error DW", "%d", ldcrffdc.L2errDW );
        i_parser.PrintNumber( "   L2 Error Bank", "%d",
                                               ldcrffdc.L2errBank );
        i_parser.PrintBool(   "   L2 Error Back of 2to1 Next Cycle",
                                               0 != ldcrffdc.L2errBack2to1 );
        i_parser.PrintNumber( "   L2 Error Syndrome Col", "%d",
                                               ldcrffdc.L2errSynCol );
        i_parser.PrintNumber( "   L2 Error Address", "%d",
                                               ldcrffdc.L2errAddress );

    } while (0);

    if ( !o_rc && i_buffer )
    {
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }

    return o_rc;
}

//------------------------------------------------------------------------------

bool parseL3LdCrFfdc( uint8_t * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    bool o_rc = true;

    const char * lines = "---------------------------------------------";
    i_parser.PrintString( LD_CR_FFDC::L3TITLE, lines );

    do
    {
        if ( nullptr == i_buffer ) { o_rc = false; break; }

        if ( i_buflen < sizeof(LD_CR_FFDC::L3LdCrFfdc) )
            { o_rc = false; break; }

        LD_CR_FFDC::L3LdCrFfdc ldcrffdc;
        memcpy( &ldcrffdc, i_buffer, sizeof(LD_CR_FFDC::L3LdCrFfdc));

        i_parser.PrintNumber( "   L3 LD Counts", "%d", ldcrffdc.L3LDcnt );
        i_parser.PrintNumber( "   L3 LD Max Allowed", "%d",
                                                ldcrffdc.L3LDMaxAllowed );
        i_parser.PrintNumber( "   L3 CR Max Allowed", "%d",
                                                ldcrffdc.L3CRMaxAllowed );
        i_parser.PrintNumber( "   L3 CR Present", "%d",
                                                ldcrffdc.L3CRPresent );

        i_parser.PrintNumber( "   L3 Error Member", "%d",
                                                ldcrffdc.L3errMember );
        i_parser.PrintNumber( "   L3 Error DW", "%d", ldcrffdc.L3errDW );
        i_parser.PrintNumber( "   L3 Error Bank", "%d", ldcrffdc.L3errBank );
        i_parser.PrintNumber( "   L3 Error Syndrome Col", "%d",
                                                ldcrffdc.L3errSynCol );
        i_parser.PrintNumber( "   L3 Error Address", "%d",
                                                ldcrffdc.L3errAddress );
    } while (0);

    if ( !o_rc && i_buffer )
    {
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }

    return o_rc;
}

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

