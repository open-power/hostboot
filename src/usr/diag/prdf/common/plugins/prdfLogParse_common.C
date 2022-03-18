/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfLogParse_common.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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

/** @file prdfLogParse.C
 *  @brief
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <prdfLogParse_common.H>

#include <prdf_service_codes.H>
#include <prdfPfa5Data.h>
#include <prdrErrlPluginsSupt.H>
#include <UtilHash.H>
#include <utilmem.H>

#include <prdfCalloutsData.H>   // For MruType enum
#include <prdfAttnTypes.H>      // For ATTENTION_VALUE_TYPE enum

#include <srcisrc.H>

#include <errlplugins.H>
#include <errlusrparser.H>
#include <attributeenums.H>     // For TARGETING::TYPE enum

#include <prdfMemLogParse.H>
#include <prdfProcLogParse.H>
#include <prdfParserEnums.H>
#include <prdfMemoryMruData.H>
#include <prdfBitString.H>

#include <hwas/common/hwasCallout.H>
#include <netinet/in.h>

// Portable formatting of uint64_t.  The ISO C99 standard requires
// __STDC_FORMAT_MACROS to be defined in order for PRIx64 etc. to be defined.
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

//------------------------------------------------------------------------------
// Data structures
//------------------------------------------------------------------------------

namespace PRDF
{

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

#define PRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS
#include <prdfCompressBuffer.H>

// Default tables for undefined Chips.
// These are special error codes and can be associated with any FIR.
// So we will consider only last 16 bits. Staring 16 bits will be
// discared and not used when comparing against signature generated
// by PRD code.
ErrorCodeDescription g_defaultErrorCodes[] =
{
    {0xFFFFFFFF, "Undefined error code" },  //this must be first
    {0x0000DD00, "Assert failed in PRD"},
    {0x0000DD01, "Invalid attention type passed to PRD"},
    {0x0000DD02, "No active error bits found"},
    {0x0000DD03, "Chip connection lookup failure"},
    {0x0000DD05, "Internal PRD code"},
    {0x0000DD09, "Fail to access attention data from registry"},
    {0x0000DD11, "SRC Access failure"},
    {0x0000DD12, "HWSV Access failure"},
    {0x0000DD20, "Config error - no domains in system"},
    {0x0000DD21, "No active attentions found"},
    {0x0000DD23, "Unknown chip raised attention"},
    {0x0000DD24, "PRD Model is not built"},
    {0x0000DD27, "PrdRbsCallback failure"},
    {0x0000DD28, "PrdStartScrub failure"},
    {0x0000DD29, "PrdResoreRbs failure"},
    {0x0000DD81, "Multiple bits on in Error Register"},
    {0x0000DD90, "Scan comm access from Error Register failed"},
    {0x0000DD91, "Scan comm access from Error Register failed due to"
                 " Power Fault"},
    {0x0000DDFF, "Special return code indicating Not to reset or"
                 " mask FIR bits"},
    {0,nullptr} // this must exist and must be last
};

//------------------------------------------------------------------------------
// Forward references
//------------------------------------------------------------------------------

// SST Specific parser
bool parseCaptureData( void * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser, errlver_t ver );

bool parsePfaData( void * i_buffer, uint32_t i_buflen,
                   ErrlUsrParser & i_parser );

//##############################################################################
//##
//##                          Utility Functions
//##
//##############################################################################

/** @fn getTargetInfo
 *  @brief Given a chip ID this function will return it's target type and chip
 *         name.
 *  @param i_chipId            the given chip's HUID
 *  @param o_targetType        the returned target type
 *  @param o_chipName          the returned entity path
 *  @param i_sizeOfChipName    size of the number of bytes in o_chipName
 */
void getTargetInfo( HUID i_chipId, TARGETING::TYPE & o_targetType,
                    char * o_chipName, uint32_t i_sz_chipName )
{
    using namespace TARGETING;

    // TODO: RTC 99942. Replace with HWSV API to get the target type

    o_targetType = static_cast<TYPE>((i_chipId >> 16) & 0xff);

    /*   HUID format (32 bits):
     *
     *   SSSSNNNNTTTTTTTTiiiiiiiiiiiiiiii
     *   S=System
     *   N=Node Number
     *   T=Target Type (matches TYPE attribute)
     *   i=Instance/Sequence number of target, relative to node
     */

    uint8_t  l_node    = (i_chipId >> 24) & 0xf;
    uint16_t l_chip    = i_chipId & 0xffff;
    uint16_t l_chiplet = l_chip;

    switch ( o_targetType )
    {
        case TYPE_SYS:
            snprintf( o_chipName, i_sz_chipName, "sys()" );
            break;

        case TYPE_PROC:
            snprintf( o_chipName, i_sz_chipName, "pu(n%dp%d)",
                      l_node, l_chip );
            break;

        case TYPE_NMMU:
            l_chip    = l_chip / MAX_NMMU_PER_PROC;
            l_chiplet = l_chiplet % MAX_NMMU_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "nmmu(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_PAUC:
            l_chip    = l_chip / MAX_PAUC_PER_PROC;
            l_chiplet = l_chiplet % MAX_PAUC_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "pauc(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_IOHS:
            l_chip    = l_chip / MAX_IOHS_PER_PROC;
            l_chiplet = l_chiplet % MAX_IOHS_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "iohs(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_SMPGROUP:
            l_chip    = l_chip / MAX_LINK_PER_PROC;
            l_chiplet = l_chiplet % MAX_LINK_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "iolink(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_PAU:
            l_chip    = l_chip / MAX_PAU_PER_PROC;
            l_chiplet = l_chiplet % MAX_PAU_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "pau(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_EQ:
            l_chip    = l_chip / MAX_EQ_PER_PROC;
            l_chiplet = l_chiplet % MAX_EQ_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "eq(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_CORE:
            l_chip    = l_chip / MAX_EC_PER_PROC;
            l_chiplet = l_chiplet % MAX_EC_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "ec(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_PEC:
            l_chip    = l_chip / MAX_PEC_PER_PROC;
            l_chiplet = l_chiplet % MAX_PEC_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "pec(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_PHB:
            l_chip    = l_chip / MAX_PHB_PER_PROC;
            l_chiplet = l_chiplet % MAX_PHB_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "phb(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_OCMB_CHIP:
            snprintf( o_chipName, i_sz_chipName, "ocmb(n%dp%d)",
                      l_node, l_chip );
            break;

        case TYPE_MEM_PORT:
            l_chip    = l_chip / MAX_PORT_PER_OCMB;
            l_chiplet = l_chiplet % MAX_PORT_PER_OCMB;
            snprintf( o_chipName, i_sz_chipName, "memport(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_MC:
            l_chip    = l_chip / MAX_MC_PER_PROC;
            l_chiplet = l_chiplet % MAX_MC_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "mc(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_MI:
            l_chip    = l_chip / MAX_MI_PER_PROC;
            l_chiplet = l_chiplet % MAX_MI_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "mi(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_MCC:
            l_chip    = l_chip / MAX_MCC_PER_PROC;
            l_chiplet = l_chiplet % MAX_MCC_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "mcc(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_OMIC:
            l_chip    = l_chip / MAX_OMIC_PER_PROC;
            l_chiplet = l_chiplet % MAX_OMIC_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "omic(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        case TYPE_OMI:
            l_chip    = l_chip / MAX_OMI_PER_PROC;
            l_chiplet = l_chiplet % MAX_OMI_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "omi(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;

        default:
            snprintf( o_chipName, i_sz_chipName, "????" );
    }
}

/** @fn getSigDesc
 *  @brief Given a chip ID and error signature this function will return
 *         signature description.
 *  @param i_chipId     the given chip's HUID
 *  @param i_sig        Error signature.
 *  @param i_len        Signature Description length.
 *  @param o_sigDesc    Signature Description.
 */
void getSigDesc( HUID i_chipId, const uint32_t i_sig, const uint32_t i_len,
                 char * o_sigDesc )
{
    using namespace TARGETING;

    // Get the target type and chip name.
    TARGETING::TYPE l_targetType = TARGETING::TYPE_NA;
    char chipName[42];
    getTargetInfo( i_chipId, l_targetType, &chipName[0], 42 );

    std::string l_descString = GetErrorSigTable()[l_targetType][i_sig];
    const char * l_description = nullptr;

    if (std::string() == l_descString)
    {
        for( uint32_t l_idx = 1;
             g_defaultErrorCodes[l_idx].description != nullptr; ++l_idx)
        {
            if ( (i_sig & 0x0000ffff ) ==
                        g_defaultErrorCodes[l_idx].signature)
            {
                l_description = g_defaultErrorCodes[l_idx].description;
                break;
            }
        }
        if (l_description == nullptr)
        {
            l_description = g_defaultErrorCodes[0].description;
        }
    }
    else
    {
        l_description = l_descString.c_str();
    }

    snprintf(o_sigDesc, i_len, "%s %s", chipName, l_description);

}
//------------------------------------------------------------------------------

void printUnknown( ErrlUsrParser & i_parser, errlver_t i_ver,
                   errlsubsec_t  i_sst )
{
    i_parser.PrintHeading("Unknown data type");
    i_parser.PrintNumber( "Data Version", "0x%08X", i_ver );
    i_parser.PrintNumber( "Data Type", "0x%08X", i_sst );
}

//------------------------------------------------------------------------------

bool parseCaptureData( void * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser, errlver_t i_ver )
{
    bool rc = true;

    uint32_t byteIndex = 0; // Capture Data buffer index in bytes

    size_t sz_uncompBuffer = sizeof(CaptureDataClass);
    uint8_t * uncompBuffer = new uint8_t[sz_uncompBuffer];
    CaptureDataClass * l_capData;
    memset( uncompBuffer, 0xFF, sz_uncompBuffer );

    if ( 2 <= i_ver ) // version 2 and above are compressed.
    {
        PrdfCompressBuffer::uncompressBuffer( ((uint8_t *) i_buffer),
                                              ((size_t) i_buflen),
                                              uncompBuffer,
                                              sz_uncompBuffer );
        //fix up the buffer length now that uncompressed
        i_buflen = sz_uncompBuffer;
        l_capData = (CaptureDataClass *) uncompBuffer;
    }
    else // version 1 is uncompressed.
    {
        l_capData = (CaptureDataClass *) i_buffer;
    }

    // Get the capture data size and adjust buffer length accordingly.
    size_t sz_capData = ntohl( l_capData->PfaCaptureDataSize );
    if ( sz_capData < i_buflen ) i_buflen = sz_capData;

    i_parser.PrintBlank();
    i_parser.PrintHeading("PRD Capture Data");
    i_parser.PrintBlank();

    char sigHeaderString[72], sigDataString[100];
    UtilMem lCapDataBS( l_capData->CaptureData, sz_capData * 8 );

    do
    {
        // NOTE: See prdfCaptureData.C for capture data format.

        // Get the next chip ID if it exists in the buffer
        uint32_t l_chipId;
        if ( i_buflen < (byteIndex + sizeof(l_chipId)) ) break;
        lCapDataBS >> l_chipId;
        byteIndex += sizeof(l_chipId);

        // Check for an invalid chip ID, reached end of input (0xFFFFFFFF).
        if (l_chipId == 0xFFFFFFFF ) break;

        // Get the number of signatures for this chip
        uint32_t chipSigCount;
        if ( i_buflen < (byteIndex + sizeof(chipSigCount)) ) break;
            lCapDataBS >> chipSigCount;

        byteIndex += sizeof(chipSigCount);

        // Get the Target type and chip name.
        TARGETING::TYPE l_targetType = TARGETING::TYPE_NA;
        char chipName[42+14], temp[42];
        getTargetInfo(l_chipId, l_targetType, &temp[0], 42 );
        snprintf( chipName, 42+14, "%s (0x%08x)", temp, l_chipId );
        // Print out the chip ID.
        i_parser.PrintString( chipName,
                              "*********************************************" );

        // Iterate through all of the chip's signatures
        for ( uint8_t j = 0; j < chipSigCount; j++ )
        {
            // Get register ID and data length from register header.
            uint16_t sigId = 0;
            uint16_t sigDataSize = 0;
            if (i_buflen < (byteIndex + sizeof(sigId) + sizeof(sigDataSize)))
                break;
            lCapDataBS >> sigId >> sigDataSize;
            byteIndex+= sizeof(sigId) + sizeof(sigDataSize);

            // Get the signature description and address from register ID table
            // if it exists.
            const char * sigDescription =
                        GetRegisterIdTable()[l_targetType][sigId].name.c_str();
            uint64_t sigAddress =
                        GetRegisterIdTable()[l_targetType][sigId].addr;
            snprintf( sigHeaderString, 72, " %s", sigDescription );

            // Get the register data
            uint8_t sigData[sigDataSize];
            size_t sz_uint8 = sizeof(uint8_t);
            for ( uint32_t k = 0; k < sigDataSize; k++ )
            {
                if ( i_buflen < (byteIndex + sz_uint8) ) break;
                lCapDataBS >> sigData[k];
                byteIndex += sz_uint8;
            }

            // Add cases here if special data parsing is needed.
            if ( 0 == sigDataSize )
            {
                i_parser.PrintString( sigHeaderString, "No Data Found" );
            }
            else if ( Util::hashString("ATTN_DATA") == sigId )
            {
                i_parser.PrintString( " ATTN_DEBUG", "" );
                i_parser.PrintHexDump( sigData, sigDataSize );
            }
            else if ( Util::hashString("MEM_UE_TABLE") == sigId )
            {
                parseMemUeTable( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("MEM_CE_TABLE") == sigId )
            {
                parseMemCeTable( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("IUE_COUNTS") == sigId )
            {
                parseIueCounts( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("DRAM_REPAIRS_DATA") == sigId )
            {
                parseDramRepairsData( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("DRAM_REPAIRS_VPD") == sigId )
            {
                parseDramRepairsVpd( sigData, sigDataSize, i_parser,
                                     l_targetType );
            }
            else if ( Util::hashString("BAD_DQ_BITMAP") == sigId )
            {
                parseBadDqBitmap( sigData, sigDataSize, i_parser,
                                  l_targetType );
            }
            else if ( Util::hashString("ROW_REPAIR_VPD") == sigId )
            {
                parseRowRepairVpd( sigData, sigDataSize, i_parser );
            }
            else if ( (Util::hashString(TD_CTLR_DATA::START) == sigId) ||
                      (Util::hashString(TD_CTLR_DATA::END)   == sigId) )
            {
                parseTdCtlrStateData( sigData, sigDataSize, i_parser, sigId );
            }
            else if ( Util::hashString("TOD_ERROR_DATA") == sigId)
            {
                parseTodFfdcData( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString(LD_CR_FFDC::L2TITLE) == sigId )
            {
                parseL2LdCrFfdc( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString(LD_CR_FFDC::L3TITLE) == sigId )
            {
                parseL3LdCrFfdc( sigData, sigDataSize, i_parser );
            }
            else if ( (0 != sigDataSize) && (sizeof(uint64_t) >= sigDataSize) )
            {
                // Print one reg/line if the data size <= 8 bytes
                const size_t sz_unit32 = sizeof(uint32_t);

                uint32_t tmpData1 = 0;
                size_t sz_tmpData1 = ( (sigDataSize > sz_unit32)
                                                ? sz_unit32 : sigDataSize );
                memcpy( &tmpData1, &sigData[0], sz_tmpData1 );

                uint32_t tmpData2 = 0;
                if ( sigDataSize > sz_unit32 )
                {
                    size_t sz_tmpData2 = sigDataSize - sz_unit32;
                    memcpy( &tmpData2, &sigData[sz_unit32], sz_tmpData2 );
                }

                snprintf(sigDataString, 100, "(0x%016" PRIx64 ") 0x%08x 0x%08x",
                         sigAddress, htonl(tmpData1), htonl(tmpData2) );

                i_parser.PrintString( sigHeaderString, sigDataString );
            }
            // Dump out the hex data
            else
            {
                i_parser.PrintString( sigHeaderString, "" );
                i_parser.PrintHexDump( sigData, sigDataSize );
            }
        }

    } while (true);

    i_parser.PrintBlank();

    // If rc is false and returned to the error log code it will add a hex dump
    // of the capture buffer to the end of the user data section. Uncomment this
    // line if the raw hex is needed for debug.
    //rc = false;

    if ( 2 <= i_ver ) // version 2 and above are compressed.
    {
        i_parser.PrintHeading("Uncompressed Capture Buffer");
        i_parser.PrintBlank();
        i_parser.PrintHexDump( uncompBuffer, sz_uncompBuffer );
        i_parser.PrintBlank();

        if ( false == rc )
        {
            i_parser.PrintHeading("Compressed Capture Buffer");
        }
    }
    else
    {
        i_parser.PrintHeading("Capture Buffer");

        rc = false; // force raw hex dump
    }

    delete [] uncompBuffer;

    return rc;
}

//------------------------------------------------------------------------------

const char * attnTypeToStr( uint32_t i_attnType )
{
    switch ( i_attnType )
    {
        case MACHINE_CHECK: return "SYSTEM_CS";
        case UNIT_CS:       return "UNIT_CS";
        case RECOVERABLE:   return "RECOVERABLE";
        case SPECIAL:       return "SPECIAL";
        case HOST_ATTN:     return "HOST_ATTN";
        default:            return "";
    }
}

//------------------------------------------------------------------------------

const char * errlSevTypeToStr( uint32_t i_errlSev )
{
    switch ( i_errlSev )
    {
        case ERRL_SEV_INFORMATIONAL: return "INFORMATIONAL";
        case ERRL_SEV_RECOVERED:     return "RECOVERED";
        case ERRL_SEV_PREDICTIVE:    return "PREDICTIVE";
        case ERRL_SEV_UNRECOVERABLE: return "UNRECOVERABLE";
        default:                     return "";
    }
}

//------------------------------------------------------------------------------

const char * gardTypeToStr( uint32_t i_gardType )
{
    switch ( i_gardType )
    {
        case HWAS::GARD_NULL:       return "NoGard";
        case HWAS::GARD_Predictive: return "Predictive";
        case HWAS::GARD_Fatal:      return "Fatal";
        default:                    return "";
    }
}

//------------------------------------------------------------------------------

bool parsePfaData( void * i_buffer, uint32_t i_buflen,
                   ErrlUsrParser & i_parser )
{
    bool rc = true;

    i_parser.PrintBlank();

    if ( nullptr != i_buffer )
    {
        // Get the PFA data struct.
        PfaData pfa;
        UtilMem l_membuf( i_buffer, i_buflen );
        l_membuf >> pfa;

        char tmp[50];
        const char * tmpStr = "";

        i_parser.PrintNumber("Service Action Counter", "0x%02X",
                             pfa.serviceActionCounter);

        // PRD Service Data Collector Flags
        i_parser.PrintString( "SDC Flags", "" );
        i_parser.PrintBool("  DUMP",                   pfa.DUMP               );
        i_parser.PrintBool("  UERE",                   pfa.UERE               );
        i_parser.PrintBool("  SUE",                    pfa.SUE                );
        i_parser.PrintBool("  AT_THRESHOLD",           pfa.AT_THRESHOLD       );
        i_parser.PrintBool("  DEGRADED",               pfa.DEGRADED           );
        i_parser.PrintBool("  SERVICE_CALL",           pfa.SERVICE_CALL       );
        i_parser.PrintBool("  TRACKIT",                pfa.TRACKIT            );
        i_parser.PrintBool("  TERMINATE",              pfa.TERMINATE          );
        i_parser.PrintBool("  LOGIT",                  pfa.LOGIT              );
        i_parser.PrintBool("  Memory channel failure", pfa.MEM_CHNL_FAIL      );
        i_parser.PrintBool("  Core unit checkstop",    pfa.PROC_CORE_CS       );
        i_parser.PrintBool("  Using Sync'd Saved Sdc", pfa.USING_SAVED_SDC    );
        i_parser.PrintBool("  Last Core Termination",  pfa.LAST_CORE_TERMINATE);
        i_parser.PrintBool("  Deferred Deconfig",      pfa.DEFER_DECONFIG     );
        i_parser.PrintBool("  Secondary Error",        pfa.SECONDARY_ERROR    );

        // Attention types
        snprintf( tmp, 50, "%s (0x%02X)", attnTypeToStr(pfa.priAttnType),
                pfa.priAttnType );
        i_parser.PrintString( "Primary ATTN Type", tmp );

        snprintf( tmp, 50, "%s (0x%02X)", attnTypeToStr(pfa.secAttnType),
                pfa.secAttnType );
        i_parser.PrintString( "Secondary ATTN Type", tmp );

        // Thresholding
        snprintf( tmp, 50, "%d of %d", pfa.errorCount, pfa.threshold );
        i_parser.PrintString( "Error Count", tmp );

        // Dump info
        i_parser.PrintNumber("DUMP Content", "0x%08x", pfa.msDumpInfo.content);
        i_parser.PrintNumber("DUMP HUID",    "0x%08x", pfa.msDumpInfo.id);

        // Error log actions and severity
        i_parser.PrintNumber( "ERRL Actions", "0x%04x", pfa.errlActions );
        snprintf( tmp, 50, "%s (0x%x) ",
                  errlSevTypeToStr(pfa.errlSeverity), pfa.errlSeverity );
        i_parser.PrintString( "ERRL Severity", tmp );

        // GARD info
        tmpStr = gardTypeToStr( pfa.globalGardPolicy );
        snprintf( tmp, 50, "%s (0x%X) ", tmpStr, pfa.globalGardPolicy );
        i_parser.PrintString( "PRD GARD Error Type", tmp );

        // MRU callouts
        if ( 0 < pfa.mruListCount )
        {
            i_parser.PrintNumber("PRD MRU List", "%d", pfa.mruListCount);

            for ( uint32_t i = 0; i < pfa.mruListCount; ++i )
            {
                char header[25];
                char data[50];

                tmpStr = "Unknown Priority";
                switch ( pfa.mruList[i].priority )
                {
                    case HWAS::SRCI_PRIORITY_NONE: tmpStr = "NONE";  break;
                    case HWAS::SRCI_PRIORITY_LOW:  tmpStr = "LOW";   break;
                    case HWAS::SRCI_PRIORITY_MEDC: tmpStr = "MED_C"; break;
                    case HWAS::SRCI_PRIORITY_MEDB: tmpStr = "MED_B"; break;
                    case HWAS::SRCI_PRIORITY_MEDA: tmpStr = "MED_A"; break;
                    case HWAS::SRCI_PRIORITY_MED:  tmpStr = "MED";   break;
                    case HWAS::SRCI_PRIORITY_HIGH: tmpStr = "HIGH";  break;
                }
                snprintf( header, 25, " #%d %s", i+1, tmpStr );

                snprintf( data, 50, "0x%08x ", pfa.mruList[i].callout );
                tmpStr = gardTypeToStr( pfa.mruList[i].gardState );

                switch ( pfa.mruList[i].type )
                {
                    case PRDcalloutData::TYPE_MEMMRU:
                        strcat( data, "(MemoryMru) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        parseMemMruData( i_parser, pfa.mruList[i].callout );
                        break;

                    case PRDcalloutData::TYPE_SYMFRU:
                        strcat( data, "(SymbolicFru) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;

                    case PRDcalloutData::TYPE_TARGET:
                        strcat( data, "(HUID) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;

                    case PRDcalloutData::TYPE_PROCCLK0:
                        strcat( data, "(PROCCLK0) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;

                    case PRDcalloutData::TYPE_PROCCLK1:
                        strcat( data, "(PROCCLK1) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;

                    case PRDcalloutData::TYPE_TODCLK:
                        strcat( data, "(TODCLK) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;

#ifndef __HOSTBOOT_MODULE
                    case PRDcalloutData::TYPE_PNOR:
                        strcat( data, "(PNOR) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;

                    case PRDcalloutData::TYPE_DPSS:
                        strcat( data, "(DPSS) " );
                        strcat( data, tmpStr );
                        i_parser.PrintString( header, data );
                        break;
#endif

                    default:
                        i_parser.PrintString( header, "(Unknown/Invalid)" );

                }
            }
        }

        // Multi-signatures
        if ( 0 < pfa.sigListCount )
        {
            i_parser.PrintNumber( "Multi-Signature List", "%d",
                                  pfa.sigListCount );

            for ( uint32_t i = 0; i < pfa.sigListCount; ++i )
            {
                char header[25];
                char sigDesc[256];

                snprintf( header, 25, "  0x%08x 0x%08x",
                          pfa.sigList[i].chipId, pfa.sigList[i].signature );

                getSigDesc( pfa.sigList[i].chipId, pfa.sigList[i].signature,
                            256, sigDesc );

                i_parser.PrintString( header, sigDesc );
            }
        }
    }

    if ( true != rc )
    {
        i_parser.PrintBlank();
        i_parser.PrintString( "                   ERROR",
                              "Unable to parse PFA data" );
    }

    // Set return code to false, so that the hex data is dumped out, for now.
    rc = false;

    return rc;
}

//------------------------------------------------------------------------------

bool parseExtMemMru( void * i_buffer, uint32_t i_buflen,
                     ErrlUsrParser & i_parser )
{
    bool o_rc = true; // Don't dump the hex buffer at the end.

    i_parser.PrintBlank();

    if ( i_buflen != sizeof(MemoryMruData::ExtendedData) )
    {
        i_parser.PrintString( "                   ERROR",
                              "Unable to parse MRU data" );
        o_rc = false; // Dump the hex buffer at the end.
    }
    else
    {
        // NOTE: The BitString and BitStringBuffer classes are not endian safe.
        // As such, this is needed to ensure this works with non-PPC machines.
        static const size_t sz_word  = sizeof(CPU_WORD);
        CPU_WORD* buf = (CPU_WORD*)i_buffer;
        for ( uint32_t i = 0; i < (i_buflen/sz_word); i++ )
        {
            buf[i] = ntohl(buf[i]);
        }

        BitString bs( (i_buflen*8), buf );
        uint32_t curPos = 0;

        MemoryMruData::ExtendedData extMemMru;

        // TODO RTC 179854
        extMemMru.mmMeld.u  = bs.getFieldJustify( curPos, 32 ); curPos+=32;
        extMemMru.isBufDimm = bs.getFieldJustify( curPos,  1 ); curPos+= 1;
        extMemMru.isX4Dram  = bs.getFieldJustify( curPos,  1 ); curPos+= 1;
        extMemMru.isValid   = bs.getFieldJustify( curPos,  1 ); curPos+= 1;
        curPos += 5; // 5 bits reserved

        for ( uint32_t i = 0; i < sizeof(extMemMru.dqMapping); i++ )
        {
            extMemMru.dqMapping[i] = bs.getFieldJustify( curPos+(i*8), 8 );
        }

        char heading[72];
        snprintf( heading, 72, "Extended MemoryMru (0x%08x)",
                  extMemMru.mmMeld.u );
        i_parser.PrintHeading( heading );
        i_parser.PrintBlank();

        parseMemMruData( i_parser, extMemMru );

        i_parser.PrintBlank();

        // Print the DQ mapping stored in the extended mem mru
        i_parser.PrintString("Mem VPD DQ Mapping:", "");
        for ( uint32_t n = 0; n < DQS_PER_DIMM; n+=20 )
        {
            char mapping[72];
            snprintf( mapping, 72, "%d %d %d %d %d %d %d %d %d %d "
                                   "%d %d %d %d %d %d %d %d %d %d",
                      extMemMru.dqMapping[n+0] , extMemMru.dqMapping[n+1],
                      extMemMru.dqMapping[n+2] , extMemMru.dqMapping[n+3],
                      extMemMru.dqMapping[n+4] , extMemMru.dqMapping[n+5],
                      extMemMru.dqMapping[n+6] , extMemMru.dqMapping[n+7],
                      extMemMru.dqMapping[n+8] , extMemMru.dqMapping[n+9],
                      extMemMru.dqMapping[n+10], extMemMru.dqMapping[n+11],
                      extMemMru.dqMapping[n+12], extMemMru.dqMapping[n+13],
                      extMemMru.dqMapping[n+14], extMemMru.dqMapping[n+15],
                      extMemMru.dqMapping[n+16], extMemMru.dqMapping[n+17],
                      extMemMru.dqMapping[n+18], extMemMru.dqMapping[n+19] );
            i_parser.PrintString(mapping, "");
        }

        o_rc = false; // Dump the hex buffer at the end. This is temporary. Just
                      // until we are confident the parser works.
    }

    return o_rc;
}

//##############################################################################
//##
//##                          Error Log Plugins
//##
//##############################################################################

bool logDataParse( ErrlUsrParser & i_parser, void * i_buffer,
                          uint32_t i_buflen, errlver_t i_ver,
                          errlsubsec_t i_sst )
{
    bool rc = false;
    switch ( i_sst )
    {
        case ErrlSectPFA5_1:  // Assume version 1 now
            rc = parsePfaData(i_buffer, i_buflen, i_parser);
            break;

        case ErrlCapData_1:  // Assume version 1 for now
            rc = parseCaptureData(i_buffer, i_buflen, i_parser, i_ver);
            break;

        case ErrlMruData:
            rc = parseExtMemMru( i_buffer, i_buflen, i_parser );
            break;

        case ErrlL2LineDeleteFfdc:
            rc = parseL2LineDeleteFfdc(i_buffer, i_buflen, i_parser, i_ver);
            break;

        case ErrlL3LineDeleteFfdc:
            rc = parseL3LineDeleteFfdc(i_buffer, i_buflen, i_parser, i_ver);
            break;

        default:
            printUnknown( i_parser, i_ver, i_sst );
            i_parser.PrintHexDump(i_buffer, i_buflen);
    }

    return rc;
}

//------------------------------------------------------------------------------

bool srcDataParse( ErrlUsrParser & i_parser, const SrciSrc & i_src )
{
    bool rc = true;
    const uint32_t MAX_DESC_LEN = 256;
    uint32_t l_wc = 0;
    const uint32_t *l_hexData = i_src.getHexData( l_wc );
    char l_tmpstr[72];
    const uint32_t l_chipId = l_hexData[l_wc-4];
    const uint32_t l_signature = l_hexData[l_wc-2];
    //ErrorCodeDescription* l_chipTable = nullptr;

    bool codeFailure = false;
    const char * srcErrType = "PRD Error of some sort.";
    const char * srcErrClass = "Unknown error reported by PRD.";

    if ( PRDF_CODE_FAIL <= i_src.reasonCode() )
    {
        codeFailure = true;
        srcErrType  = "PRD Internal Firmware Software Fault";
        srcErrClass = "Error condition within PRD code";
    }
    else
    {
        srcErrType = "PRD Detected Hardware Indication";
        switch ( i_src.reasonCode() )
        {
            case PRDF_DETECTED_FAIL_HARDWARE:
                srcErrClass = "Hardware Error Detected";
                break;
            case PRDF_DETECTED_FAIL_HARDWARE_PROBABLE:
                srcErrClass = "Hardware Error Detected, small probability of "
                              "software cause";
                break;
            case PRDF_DETECTED_FAIL_SOFTWARE_PROBABLE:
                srcErrClass = "Software likely caused a hardware error "
                              "condition, smaller possibility of a hardware "
                              "cause.";
                break;
            case PRDF_DETECTED_FAIL_SOFTWARE:
                srcErrClass = "Software caused hardware error condition "
                              "detected";
                break;
            case PRDF_EXTRA_FFDC:
                srcErrClass = "This errorlog contains extra FFDC associated "
                              "with a PLID-linked PRD analysis log";
                break;
            default:
                srcErrClass = "Unknown error classification";
                break;
        }
    }

    i_parser.PrintNumber("ModuleId","0x%02X",i_src.moduleId());
    i_parser.PrintNumber("Reason Code","0x%04X",i_src.reasonCode());
    i_parser.PrintNumber("Code Location","0x%04X",l_hexData[l_wc-3]);
    i_parser.PrintBlank();
    i_parser.PrintString("PRD SRC Type", srcErrType);
    i_parser.PrintString("PRD SRC Class", srcErrClass);
    i_parser.PrintBlank();

    if (!codeFailure)
    {

        snprintf(l_tmpstr, 72, "0x%08X 0x%08X",l_chipId,l_signature );
        i_parser.PrintString("PRD Signature",l_tmpstr);

        char l_sigDesc[MAX_DESC_LEN];
        // Get signature Description.
        getSigDesc( l_chipId, l_signature, MAX_DESC_LEN, l_sigDesc );

        i_parser.PrintString("Signature Description", l_sigDesc);
    }

    return rc;
}

} //end namespace HOSTBOOT/FSP
} // end namespace PRDF
