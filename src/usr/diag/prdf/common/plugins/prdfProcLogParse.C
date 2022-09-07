/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfProcLogParse.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#include <endian.h>
#include <prdfPlatProcConst.H>
#include <map>
#include <vector>
#include <string>

#include <prdfBufferStream.H>

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
    // NOTE: This data has been deprecated and moved to it's own user data
    //       section. However, the parser must remain for legacy logs.

    bool o_rc = true;

    i_parser.PrintString( " L2_LD_FFDC", "" );

    do
    {
        if ( nullptr == i_buffer ) { o_rc = false; break; }

        if ( i_buflen < sizeof(LD_CR_FFDC::L2LdCrFfdc) )
            { o_rc = false; break; }

        // NOTE: Do not memcpy this data to the L3 LD struct. It does not work
        //       properly with PPC data and an x86 parser. Instead, assume the
        //       data is always in PPC format and extract the data manually.

        // Bytes 0 and 1 are reserved
        // Byte 2 is for column repair which is not used in P10.
        uint8_t ldMaxAllowed =  (i_buffer[3] & 0xf0) >> 4;
        uint8_t ldCount      =   i_buffer[3] & 0x0f;
        uint16_t addr        = ((i_buffer[4] & 0x03) << 8) | i_buffer[5];
        uint8_t col          =   i_buffer[6];
        bool nextCycle       = ((i_buffer[7] & 0x80) != 0);
        uint8_t bank         =  (i_buffer[7] & 0x40) >> 6;
        uint8_t dw           =  (i_buffer[7] & 0x38) >> 3;
        uint8_t member       =   i_buffer[7] & 0x07;

        i_parser.PrintNumber("   L2 LD Counts",      "%d", ldCount);
        i_parser.PrintNumber("   L2 LD Max Allowed", "%d", ldMaxAllowed);

        i_parser.PrintNumber("   L2 Error Member",       "0x%02x", member);
        i_parser.PrintNumber("   L2 Error DW",           "0x%02x", dw);
        i_parser.PrintNumber("   L2 Error Bank",         "0x%02x", bank);
        i_parser.PrintBool(  "   L2 Error Back of 2to1 Next Cycle", nextCycle);
        i_parser.PrintNumber("   L2 Error Syndrome Col", "0x%02x", col);
        i_parser.PrintNumber("   L2 Error Address",      "0x%04x", addr);

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
    // NOTE: This data has been deprecated and moved to it's own user data
    //       section. However, the parser must remain for legacy logs.

    bool o_rc = true;

    i_parser.PrintString( " L3_LD_FFDC", "" );

    do
    {
        if ( nullptr == i_buffer ) { o_rc = false; break; }

        if ( i_buflen < sizeof(LD_CR_FFDC::L3LdCrFfdc) )
            { o_rc = false; break; }

        // NOTE: Do not memcpy this data to the L3 LD struct. It does not work
        //       properly with PPC data and an x86 parser. Instead, assume the
        //       data is always in PPC format and extract the data manually.

        // Bytes 0 and 1 are reserved
        // Byte 2 is for column repair which is not used in P10.
        uint8_t ldMaxAllowed =  (i_buffer[3] & 0xf0) >> 4;
        uint8_t ldCount      =   i_buffer[3] & 0x0f;
        uint16_t addr        = ((i_buffer[4] & 0x07) << 9) |
                               ( i_buffer[5]         << 1) |
                               ((i_buffer[6] & 0x80) >> 7);
        uint8_t col          = ((i_buffer[6] & 0x7f) << 1) |
                               ((i_buffer[7] & 0x80) >> 7);
        uint8_t bank         =  (i_buffer[7] & 0x40) >> 6;
        uint8_t dw           =  (i_buffer[7] & 0x38) >> 3;
        uint8_t member       =   i_buffer[7] & 0x07;

        // NOTE: This is where the data is broken, which prompted
        //       the new user data section.

        // Member is a 3-bit field and should be 4.
        char tmp_member[DATA_SIZE]  = "";
        snprintf(tmp_member,  DATA_SIZE, "0x%02x (or possibly 0x%02x)",
                 member, member + 8);

        // Bank is a 1-bit field and should be 2.
        char tmp_bank[DATA_SIZE]  = "";
        snprintf(tmp_bank,  DATA_SIZE, "0x%02x (or possibly 0x%02x)",
                 bank, bank + 2);

        // CL half does not exist in data.
        const char* tmp_cl_half = "unknown";

        i_parser.PrintNumber("   L3 LD Counts",      "%d", ldCount );
        i_parser.PrintNumber("   L3 LD Max Allowed", "%d", ldMaxAllowed );

        i_parser.PrintString("   L3 Error Member",                 tmp_member);
        i_parser.PrintNumber("   L3 Error DW",           "0x%02x", dw);
        i_parser.PrintString("   L3 Error Bank",                   tmp_bank);
        i_parser.PrintString("   L3 Error CL Half",                tmp_cl_half);
        i_parser.PrintNumber("   L3 Error Syndrome Col", "0x%02x", col);
        i_parser.PrintNumber("   L3 Error Address",      "0x%04x", addr);

    } while (0);

    if ( !o_rc && i_buffer )
    {
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }

    return o_rc;
}

//------------------------------------------------------------------------------

bool parseL2LineDeleteFfdc(void* i_buffer, uint32_t i_buflen,
                           ErrlUsrParser& i_parser, errlver_t)
{
    i_parser.PrintBlank();
    i_parser.PrintHeading("L2 Line Delete Data");
    i_parser.PrintBlank();

    BufferReadStream ffdc{i_buffer, i_buflen};

    if (ffdc.good())
    {
        uint8_t nodePos = 0, procPos = 0, corePos = 0;
        uint16_t ldCount = 0, ldMax = 0;
        uint8_t ce_ue = 0, member = 0, dw = 0, bank = 0;
        uint8_t nextcycle = 0, syndrome_col= 0;
        uint16_t addr = 0;

        ffdc >> nodePos         // 1 byte
             >> procPos         // 1 byte
             >> corePos         // 1 byte
             >> ldCount         // 2 bytes
             >> ldMax           // 2 bytes
             >> ce_ue           // 1 byte
             >> member          // 1 byte
             >> dw              // 1 byte
             >> bank            // 1 byte
             >> nextcycle       // 1 byte
             >> syndrome_col    // 1 byte
             >> addr;           // 2 bytes
                        // total: 15 bytes

        char target[DATA_SIZE];
        snprintf(target, DATA_SIZE, "node %d proc %d core %d",
                 nodePos, procPos, corePos);

        i_parser.PrintString("Target", target);

        i_parser.PrintNumber("Line Delete Count", "%d", ldCount);
        i_parser.PrintNumber("Max Line Deletes",  "%d", ldMax);

        i_parser.PrintString("Error Data", "" );

        i_parser.PrintString("  Type",
            (0 == ce_ue) ? "CE" : ((1 == ce_ue) ? "UE" : "CE/UE"));

        i_parser.PrintNumber("  Member",       "0x%02x", member);
        i_parser.PrintNumber("  DW",           "0x%02x", dw);
        i_parser.PrintNumber("  Bank",         "0x%02x", bank);
        i_parser.PrintBool(  "  Back of 2to1 Next Cycle", (0 != nextcycle));
        i_parser.PrintNumber("  Syndrome Col", "0x%02x", syndrome_col);
        i_parser.PrintNumber("  Address",      "0x%04x", addr);
    }

//    return ffdc.good(); // false will trigger a hex dump
    return false; // TODO: eventually will remove, but keeping for debug.
}

//------------------------------------------------------------------------------

bool parseL3LineDeleteFfdc(void* i_buffer, uint32_t i_buflen,
                           ErrlUsrParser& i_parser, errlver_t)
{
    i_parser.PrintBlank();
    i_parser.PrintHeading("L3 Line Delete Data");
    i_parser.PrintBlank();

    BufferReadStream ffdc{i_buffer, i_buflen};

    if (ffdc.good())
    {
        uint8_t nodePos = 0, procPos = 0, corePos = 0;
        uint16_t ldCount = 0, ldMax = 0;
        uint8_t ce_ue = 0, member = 0, dw = 0, bank = 0;
        uint8_t cl_half = 0, syndrome_col= 0;
        uint16_t addr = 0;

        ffdc >> nodePos         // 1 byte
             >> procPos         // 1 byte
             >> corePos         // 1 byte
             >> ldCount         // 2 bytes
             >> ldMax           // 2 bytes
             >> ce_ue           // 1 byte
             >> member          // 1 byte
             >> dw              // 1 byte
             >> bank            // 1 byte
             >> cl_half         // 1 byte
             >> syndrome_col    // 1 byte
             >> addr;           // 2 bytes
                        // total: 15 bytes

        char target[DATA_SIZE];
        snprintf(target, DATA_SIZE, "node %d proc %d core %d",
                 nodePos, procPos, corePos);

        i_parser.PrintString("Target", target);

        i_parser.PrintNumber("Line Delete Count", "%d", ldCount);
        i_parser.PrintNumber("Max Line Deletes",  "%d", ldMax);

        i_parser.PrintString("Error Data", "" );

        i_parser.PrintString("  Type",
            (0 == ce_ue) ? "CE" : ((1 == ce_ue) ? "UE" : "CE/UE"));

        i_parser.PrintNumber("  Member",       "0x%02x", member);
        i_parser.PrintNumber("  DW",           "0x%02x", dw);
        i_parser.PrintNumber("  Bank",         "0x%02x", bank);
        i_parser.PrintNumber("  CL Half",      "0x%02x", cl_half);
        i_parser.PrintNumber("  Syndrome Col", "0x%02x", syndrome_col);
        i_parser.PrintNumber("  Address",      "0x%04x", addr);
    }

//    return ffdc.good(); // false will trigger a hex dump
    return false; // TODO: eventually will remove, but keeping for debug.
}

bool parseScratchSig(void* i_buffer, uint32_t i_buflen, ErrlUsrParser& i_parser,
                     errlver_t)
{
    bool rc = true;

    uint32_t chipId = 0;
    uint32_t sigId  = 0;

    BufferReadStream ffdc{i_buffer, i_buflen};

    ffdc >> chipId
         >> sigId;

    char sig[72];
    snprintf( sig, 72, "0x%08x 0x%08x", chipId, sigId );
    i_parser.PrintString("HB Scratch Reg Signature:", sig);

    return rc;
}

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

