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

//------------------------------------------------------------------------------------------------

// TODO RTC 267015 - investigate PM recovery parsing further

// Constants previously defined in p9_pm_recovery_ffdc_defines.H and elsewhere
struct __attribute__((packed)) FfdcSummSubSectHdr
{
    uint8_t  iv_subSectnId;
    uint8_t  iv_majorNum;
    uint8_t  iv_minorNum;
    uint8_t  iv_secValid;
};
constexpr uint8_t MAX_CMES_PER_CHIP = 12;
constexpr uint8_t FFDC_SUMMARY_SIZE_CME = 28;
constexpr uint8_t CME_MAJ_NUM = 1;
constexpr uint8_t CME_MIN_NUM = 0;
constexpr uint8_t SGPE_MAJ_NUM = 1;
constexpr uint8_t SGPE_MIN_NUM = 0;
constexpr uint8_t PGPE_MAJ_NUM = 1;
constexpr uint8_t PGPE_MIN_NUM = 0;
constexpr uint8_t SYS_CONFIG_MAJ_NUM = 1;
constexpr uint8_t SYS_CONFIG_MIN_NUM = 0;
constexpr uint8_t FFDC_SUMMARY_SIZE_CPPM_REG = 28;
constexpr uint8_t FFDC_SUMMARY_SIZE_QPPM_REG = 36;
constexpr uint8_t CPPM_MAJ_NUM = 1;
constexpr uint8_t CPPM_MIN_NUM = 0;
enum  VerList_t
{
    STATE_CONFIG_SECTN         =   0x00,
    SGPE_SECTN                 =   0x01,
    PGPE_SECTN                 =   0x02,
    CME_SECTN                  =   0x03,
    QPPM_SECTN                 =   0x04,
    CPPM_SECTN                 =   0x05,
    SGPE_GLOBAL_VAR_SECTN      =   0x06,
    PGPE_GLOBAL_VAR_SECTN      =   0x07,
    CME_GLOBAL_VAR_SECTN       =   0x08,
    MAX_FFDC_SUMMARY_SECTN_CNT =   0x09,
};

/**
 * @brief parser a user data section consisting of SCOM register values.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @param[in] i_regList list of registers
 * @param[in] i_majNum  major number
 * @param[in] i_minNum  minor number
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parseRegFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length,
                       std::vector < std::string >& i_regList,
                       uint32_t i_majNum, uint32_t i_minNum )

{
    char l_lineStr[BUF_LENGTH];
    char l_hdrStr[BUF_LENGTH];
    uint32_t l_rc            =  PARSE_SUCCESS;
    uint32_t secLength       =  0;
    std::vector < std::string > ::iterator itRegList;

    do
    {
        FfdcSummSubSectHdr* l_pSubSecHdr  =   (FfdcSummSubSectHdr*)i_buf;
        uint64_t* l_secBufPtr             =   (uint64_t*)( i_buf + sizeof( FfdcSummSubSectHdr ) );
        uint32_t  l_tempWord              =   0;
        uint64_t  l_tempDbWord            =   0;

        if( 0 == i_length )
        {
            i_parser.PrintHeading( "Bad Sub-Section" );
            l_rc    =   SECTION_INVALID;
            break;
        }

        snprintf( l_lineStr, BUF_LENGTH, "%02d", l_pSubSecHdr->iv_majorNum );
        i_parser.PrintString( "Major Ver", l_lineStr );
        memset( l_lineStr, 0x00, BUF_LENGTH );

        snprintf( l_lineStr, LINE_LENGTH, "%02d", l_pSubSecHdr->iv_minorNum );
        i_parser.PrintString( "Minor Ver", l_lineStr );
        memset( l_lineStr, 0x00, BUF_LENGTH );
        i_parser.PrintBlank();

        if( l_pSubSecHdr->iv_majorNum  !=  i_majNum )
        {
            i_parser.PrintBlank();
            i_parser.PrintHeading( "Maj Ver Mismatch" );
            l_rc    =   BIN_AND_PARSER_MAJ_VER_MISMATCH;
            break;
        }

        if( l_pSubSecHdr->iv_minorNum  !=  i_minNum )
        {
            i_parser.PrintHeading( "Min Ver Mismatch" );
            l_rc    =   BIN_AND_PARSER_MIN_VER_MISMATCH;
            break;
        }

        if( !l_pSubSecHdr->iv_secValid )
        {
            i_parser.PrintBlank();
            l_rc    =   SECTION_INVALID;
            i_parser.PrintHeading( "Section Invalid" );
            break;
        }

        secLength   =   (i_regList.size() * 8) + sizeof( FfdcSummSubSectHdr );
        secLength   =   (secLength > i_length) ? i_length : secLength;


        uint32_t l_currentLength    =   sizeof( FfdcSummSubSectHdr );

        for( itRegList = i_regList.begin(); itRegList != i_regList.end();
             itRegList++ )
        {
            if( l_currentLength > secLength )
            {

                break;
            }

            memset( l_lineStr, 0x00, BUF_LENGTH );
            memset( l_hdrStr, 0x00, BUF_LENGTH );
            snprintf( l_hdrStr, BUF_LENGTH, "%s", (*itRegList).c_str() );
            l_tempDbWord    =   htobe64(*l_secBufPtr);

            if( INVALID_DATA == l_tempDbWord )
            {
                memcpy( l_lineStr, "--", BUF_LENGTH );
            }
            else
            {
                l_tempWord    =   (l_tempDbWord >> 32);
                snprintf( l_lineStr, BUF_LENGTH, "0x%08x", l_tempWord );
                l_tempWord    =   (uint32_t)l_tempDbWord;
                snprintf( l_lineStr + UPPER_BYTE_POS, (BUF_LENGTH - UPPER_BYTE_POS), "%08x", l_tempWord );
            }

            i_parser.PrintString( l_hdrStr, l_lineStr );
            l_secBufPtr++;
            l_currentLength += 8;
        }

    }
    while(0);

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of PPE register values.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @param[in] i_majNum  major number
 * @param[in] i_minNum  minor number
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 * @note      assumes just PPE XIRs
 */
uint32_t parsePpeFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length,
                       uint32_t i_majNum, uint32_t i_minNum )
{
    char l_lineStr[BUF_LENGTH];
    char l_hdrStr[BUF_LENGTH];
    //NOTE: Ensure this register list always matches with list in
    //file p9_pm_recovery_ffdc_base.C
    std::vector < std::string > l_ppeRegList;
    std::vector < std::string > ::iterator itRegList;
    uint32_t l_rc            =  PARSE_SUCCESS;
    uint32_t l_currentLength =  0;
    uint32_t secLength       =  0;

    l_ppeRegList.push_back( "XSR" );
    l_ppeRegList.push_back( "IAR" );
    l_ppeRegList.push_back( "IR" );
    l_ppeRegList.push_back( "EDR" );
    l_ppeRegList.push_back( "SPRG0" );

    do
    {
        FfdcSummSubSectHdr* l_pSubSecHdr  =   (FfdcSummSubSectHdr*)i_buf;
        uint32_t* l_secBufPtr  =   (uint32_t*)( i_buf + sizeof( FfdcSummSubSectHdr ) );

        snprintf( l_lineStr, BUF_LENGTH, "%02d", l_pSubSecHdr->iv_majorNum );
        i_parser.PrintString( "Major Ver", l_lineStr );
        memset( l_lineStr, 0x00, BUF_LENGTH );

        snprintf( l_lineStr, BUF_LENGTH, "%02d", l_pSubSecHdr->iv_minorNum );
        i_parser.PrintString( "Minor Ver", l_lineStr );
        memset( l_lineStr, 0x00, BUF_LENGTH );
        i_parser.PrintBlank();

        if( l_pSubSecHdr->iv_majorNum  !=  i_majNum )
        {
            i_parser.PrintBlank();
            i_parser.PrintHeading( "Maj Ver Mismatch" );
            l_rc    =   BIN_AND_PARSER_MAJ_VER_MISMATCH;
            break;
        }

        if( l_pSubSecHdr->iv_minorNum  !=  i_minNum )
        {
            i_parser.PrintHeading( "Min Ver Mismatch" );
            l_rc    =   BIN_AND_PARSER_MIN_VER_MISMATCH;
            break;
        }

        if( ( !l_pSubSecHdr->iv_secValid ) || ( 0 == i_length ))
        {
            i_parser.PrintBlank();
            l_rc    =   SECTION_INVALID;
            i_parser.PrintHeading( "Section Invalid" );
            break;
        }

        secLength   =   ( l_ppeRegList.size() * 4) + sizeof( FfdcSummSubSectHdr );
        secLength   =   (secLength > i_length) ? i_length : secLength;

        l_currentLength    =   sizeof( FfdcSummSubSectHdr );

        for( itRegList = l_ppeRegList.begin(); itRegList != l_ppeRegList.end();
             itRegList++ )
        {
            if( l_currentLength > secLength )
            {
                break;
            }

            memset( l_lineStr, 0x00, BUF_LENGTH );
            memset( l_hdrStr, 0x00, BUF_LENGTH );
            snprintf( l_hdrStr, BUF_LENGTH, "%-15s ", (*itRegList).c_str() );
            snprintf( l_lineStr, BUF_LENGTH, "0x%08x", htobe32(*l_secBufPtr) );

            i_parser.PrintString( l_hdrStr, l_lineStr );
            l_secBufPtr++;
            l_currentLength += 4;
        }
    }
    while(0);

    return l_rc;

}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of CME's FFDC.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parseCmeFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length )
{
    char l_lineStr[LINE_LENGTH];
    uint32_t l_rc            =  PARSE_SUCCESS;
    uint32_t secLength       =  0;
    uint32_t l_maxCme        =  MAX_CMES_PER_CHIP;
    const char* lines       =  "---------------------------------------------";

    do
    {
        secLength   =   MAX_CMES_PER_CHIP * FFDC_SUMMARY_SIZE_CME;
        secLength   =   secLength > i_length ? i_length : secLength;
        l_maxCme    =   secLength / FFDC_SUMMARY_SIZE_CME;

        for( uint8_t cmeId = 0; cmeId < l_maxCme; cmeId++ )
        {
            memset( l_lineStr, 0x00, LINE_LENGTH );
            snprintf( l_lineStr, LINE_LENGTH, "XIR CME %02d", cmeId );
            i_parser.PrintHeading( l_lineStr );
            i_parser.PrintBlank();

            uint8_t* l_secBufPtr   =  i_buf +  ( cmeId * FFDC_SUMMARY_SIZE_CME );

            l_rc = parsePpeFfdc( i_parser, l_secBufPtr, FFDC_SUMMARY_SIZE_CME,
                                 CME_MAJ_NUM,
                                 CME_MIN_NUM );

            i_parser.PrintHeading( lines );

            if( l_rc )
            {
                if( SECTION_INVALID == l_rc )
                {
                    l_rc = PARSE_SUCCESS;
                    continue;
                }
                else
                {
                    break;
                }
            }

            i_parser.PrintBlank();
        }

    }
    while(0);

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of SGPE's XIRs.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parseSgpeFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length )
{
    uint32_t l_rc   =   PARSE_SUCCESS;

    do
    {
        i_parser.PrintHeading( "XIR SGPE" );
        i_parser.PrintBlank();
        l_rc = parsePpeFfdc( i_parser, i_buf, i_length,
                             SGPE_MAJ_NUM,
                             SGPE_MIN_NUM );

        if( l_rc )
        {
            break;
        }

        i_parser.PrintBlank();

    }
    while(0);

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of PGPE's XIRs.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parsePgpeFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length )
{
    uint32_t l_rc = PARSE_SUCCESS;

    do
    {
        i_parser.PrintHeading( "XIR PGPE " );
        i_parser.PrintBlank();
        l_rc = parsePpeFfdc( i_parser, i_buf, i_length,
                             PGPE_MAJ_NUM,
                             PGPE_MIN_NUM );

        if( l_rc )
        {
            break;
        }

        i_parser.PrintBlank();

    }
    while(0);

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of Proc chips's config and state.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parseSysState( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length )
{
    std::vector < std::string > l_occRegMap;
    uint32_t l_rc = PARSE_SUCCESS;

    do
    {
        //NOTE: Ensure this register list always matches with list in
        //file p9_pm_recovery_ffdc_occ.C
        l_occRegMap.push_back( "CME 0 FIR" );
        l_occRegMap.push_back( "CME 1 FIR" );
        l_occRegMap.push_back( "CME 2 FIR" );
        l_occRegMap.push_back( "CME 3 FIR" );
        l_occRegMap.push_back( "CME 4 FIR" );
        l_occRegMap.push_back( "CME 5 FIR" );
        l_occRegMap.push_back( "CME 6 FIR" );
        l_occRegMap.push_back( "CME 7 FIR" );
        l_occRegMap.push_back( "CME 8 FIR" );
        l_occRegMap.push_back( "CME 9 FIR" );
        l_occRegMap.push_back( "CME 10 FIR" );
        l_occRegMap.push_back( "CME 11 FIR" );
        l_occRegMap.push_back( "OCC FIR" );
        l_occRegMap.push_back( "PBA FIR" );
        l_occRegMap.push_back( "CCSR" );
        l_occRegMap.push_back( "QSSR" );
        l_occRegMap.push_back( "OCCFLG" );
        l_occRegMap.push_back( "OCCFLG2" );

        i_parser.PrintHeading( "Sys State " );
        i_parser.PrintBlank();

        l_rc = parseRegFfdc( i_parser, i_buf, i_length, l_occRegMap,
                             SYS_CONFIG_MAJ_NUM,
                             SYS_CONFIG_MIN_NUM );

        if( l_rc )
        {
            break;
        }

        i_parser.PrintBlank();

    }
    while(0);

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of CPPM registers.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parseCppmFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length )
{
    std::vector < std::string > l_cppmRegMap;
    uint32_t l_rc               =       PARSE_SUCCESS;
    uint32_t l_cppm             =       0;
    uint32_t l_cppmSectn        =       0;
    char l_lineStr[LINE_LENGTH];
    const char* lines = "---------------------------------------------";
    l_cppmSectn    =       (i_length / (FFDC_SUMMARY_SIZE_CPPM_REG));

    if( l_cppmSectn > MAX_CPPM )
    {
        l_cppmSectn = MAX_CPPM;
    }

    //NOTE: Ensure this register list always matches with list in
    //file p9_pm_recovery_ffdc_cppm.C
    l_cppmRegMap.push_back( "C_SSHSRC" );
    l_cppmRegMap.push_back( "VDMCR" );

    for( l_cppm = 0; l_cppm < l_cppmSectn; l_cppm++ )
    {
        memset( l_lineStr, 0x00, LINE_LENGTH );
        snprintf( l_lineStr, LINE_LENGTH, "CPPM %02d", l_cppm );
        i_parser.PrintHeading( l_lineStr );
        i_parser.PrintBlank();
        uint8_t* l_secBuf       =       i_buf + ( FFDC_SUMMARY_SIZE_CPPM_REG * l_cppm );

        l_rc = parseRegFfdc( i_parser, l_secBuf, FFDC_SUMMARY_SIZE_CPPM_REG, l_cppmRegMap,
                             CPPM_MAJ_NUM, CPPM_MIN_NUM );

        i_parser.PrintBlank();
        i_parser.PrintHeading( lines );

        if( l_rc )
        {
            if( SECTION_INVALID == l_rc )
            {
                l_rc = PARSE_SUCCESS;
                continue;
            }
            else
            {
                break;
            }
        }

    }

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section consisting of QPPM registers.
 * @param[in] i_parser  error log parser
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
uint32_t parseQppmFfdc( ErrlUsrParser& i_parser, uint8_t* i_buf, uint32_t i_length )
{
    std::vector < std::string > l_qppmRegMap;
    uint32_t l_rc = PARSE_SUCCESS;
    char l_lineStr[LINE_LENGTH];
    uint32_t l_qppmSectn       =       (i_length / (FFDC_SUMMARY_SIZE_QPPM_REG) );

    const char* lines = "---------------------------------------------";
    //NOTE: Ensure this register list always matches with list in
    //file p9_pm_recovery_ffdc_qppm.C

    l_qppmRegMap.push_back( "GPMMR" );
    l_qppmRegMap.push_back( "EQ_SSHSRC" );
    l_qppmRegMap.push_back( "QPPM_DPLL_FREQ" );

    if( l_qppmSectn > MAX_EQ )
    {
        l_qppmSectn = MAX_EQ;
    }

    for( uint32_t l_qppm = 0; l_qppm < l_qppmSectn; l_qppm++ )
    {
        memset( l_lineStr, 0x00, LINE_LENGTH );
        snprintf( l_lineStr, LINE_LENGTH, "QPPM %02d", l_qppm );
        i_parser.PrintHeading( l_lineStr );
        i_parser.PrintBlank();
        uint8_t* l_secBuf  =  i_buf + ( FFDC_SUMMARY_SIZE_QPPM_REG * l_qppm );

        l_rc = parseRegFfdc( i_parser, l_secBuf, FFDC_SUMMARY_SIZE_QPPM_REG, l_qppmRegMap,
                             CPPM_MAJ_NUM, CPPM_MIN_NUM );

        i_parser.PrintBlank();
        i_parser.PrintHeading( lines );

        if( l_rc )
        {
            if( SECTION_INVALID == l_rc )
            {
                l_rc = PARSE_SUCCESS;
                continue;
            }
            else
            {
                break;
            }
        }
    }

    return l_rc;
}

//------------------------------------------------------------------------------------------------

/**
 * @brief parser a user data section added by PRD in case of PM malfunction.
 * @param[in] i_buf     points to user data section
 * @param[in] i_length  length of the section
 * @param[in] i_parser  error log parser
 * @param[in] i_subsec  sub section id
 * @return    PARSE_SUCCESS if parsing succeeds, error code otherwise.
 */
bool parsePmFfdcData( void* i_buf, uint32_t i_length,
                      ErrlUsrParser& i_parser, errlver_t i_subsec )
{
    uint32_t l_rc = PARSE_SUCCESS;
    uint8_t* l_pBuf = (uint8_t*)i_buf;

    switch( i_subsec )
    {
        case STATE_CONFIG_SECTN:
            l_rc = parseSysState(  i_parser, l_pBuf, i_length );
            break;

        case SGPE_SECTN:
            l_rc = parseSgpeFfdc( i_parser, l_pBuf, i_length );
            break;

        case PGPE_SECTN:
            l_rc = parsePgpeFfdc( i_parser, l_pBuf, i_length );
            break;

        case CME_SECTN:
            l_rc = parseCmeFfdc( i_parser, l_pBuf, i_length );
            break;

        case QPPM_SECTN:
            l_rc = parseQppmFfdc( i_parser, l_pBuf, i_length );
            break;

        case CPPM_SECTN:
            l_rc = parseCppmFfdc( i_parser, l_pBuf, i_length );
            break;

        case SGPE_GLOBAL_VAR_SECTN:
            i_parser.PrintHeading( "SGPE Score Board" );
            i_parser.PrintBlank();
            i_parser.PrintHexDump( l_pBuf, i_length );
            i_parser.PrintBlank();
            break;

        case PGPE_GLOBAL_VAR_SECTN:
            i_parser.PrintHeading( "PGPE Score Board" );
            i_parser.PrintBlank();
            i_parser.PrintHexDump( l_pBuf, i_length );
            i_parser.PrintBlank();
            break;

        case CME_GLOBAL_VAR_SECTN:
            i_parser.PrintHeading( "CME Score Board" );
            i_parser.PrintBlank();
            i_parser.PrintHexDump( l_pBuf, i_length );
            i_parser.PrintBlank();
            break;

        default:
            i_parser.PrintHeading( "Unsupported Section" );
            break;
    }

    return (l_rc == PARSE_SUCCESS);
}

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

