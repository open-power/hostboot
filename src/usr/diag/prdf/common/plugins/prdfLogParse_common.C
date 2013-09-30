/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfLogParse_common.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
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

#include <srcisrc.H>

#include <errlplugins.H>
#include <errlusrparser.H>

#ifdef CONTEXT_x86_nfp

// FIXME: RTC: 51689 will address this issue.
// Need support for attributeenums.H in x86.nfp.
#include "../../../../export/ppc/fips/include/attributeenums.H"

#else

#include <attributeenums.H> // For TARGETING::TYPE enum

#endif

#include <prdfCenLogParse.H>

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
#include <prdfGardType.H>

// Default tables for undefined Chips
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
    {0x00ED0000, "PLL error"},
    {0,NULL} // this must exist and must be last
};

//------------------------------------------------------------------------------
// Forward references
//------------------------------------------------------------------------------

// SST Specific parser
bool parseCaptureData( void * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser, errlver_t ver );

bool parsePfaData( void * i_buffer, uint32_t i_buflen,
                   ErrlUsrParser & i_parser );

bool parseAVPData( void * i_buffer, uint32_t i_buflen,
                   ErrlUsrParser & i_parser );

bool parseHdatAVPData( void * i_buffer, uint32_t i_buflen,
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

    // FIXME: RTC: 51689 will address this issue.
    // This is a hack until we can get targeting support in x86.

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

    static const uint8_t MAX_EX_PER_PROC    = 16;
    static const uint8_t MAX_MCS_PER_PROC   =  8;
    static const uint8_t MAX_MBA_PER_MEMBUF =  2;

    switch ( o_targetType )
    {
        case TYPE_MEMBUF:
            snprintf( o_chipName, i_sz_chipName, "mb(n%dp%d)",
                      l_node, l_chip );
            break;
        case TYPE_PROC:
            snprintf( o_chipName, i_sz_chipName, "pu(n%dp%d)",
                      l_node, l_chip );
            break;
        case TYPE_EX:
            l_chip    = l_chip / MAX_EX_PER_PROC;
            l_chiplet = l_chiplet % MAX_EX_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "ex(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;
        case TYPE_MCS:
            l_chip    = l_chip / MAX_MCS_PER_PROC;
            l_chiplet = l_chiplet % MAX_MCS_PER_PROC;
            snprintf( o_chipName, i_sz_chipName, "mcs(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;
        case TYPE_MBA:
            l_chip    = l_chip / MAX_MBA_PER_MEMBUF;
            l_chiplet = l_chiplet % MAX_MBA_PER_MEMBUF;
            snprintf( o_chipName, i_sz_chipName, "mba(n%dp%dc%d)",
                      l_node, l_chip, l_chiplet );
            break;
        default:
            snprintf( o_chipName, i_sz_chipName, "????" );
    }
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

    uint8_t * l_uncompBuffer = new uint8_t[CaptureDataSize];
    size_t l_uncompBufSize = CaptureDataSize;
    CaptureDataClass * l_capData;
    memset( l_uncompBuffer, 0xFF,CaptureDataSize);

    if ( 2 <= i_ver ) // version 2 and above are compressed.
    {
        PrdfCompressBuffer::uncompressBuffer( ((uint8_t *) i_buffer),
                                              ((size_t) i_buflen),
                                              l_uncompBuffer,
                                              l_uncompBufSize );
        //fix up the buffer length now that uncompressed
        i_buflen = l_uncompBufSize;
        l_capData = (CaptureDataClass *) l_uncompBuffer;
    }
    else // version 1 is uncompressed.
    {
        l_capData = (CaptureDataClass *) i_buffer;
    }

    // Fix endianness on size field.
    l_capData->PfaCaptureDataSize = ntohl(l_capData->PfaCaptureDataSize);
    if( l_capData->PfaCaptureDataSize < i_buflen )
    {
        i_buflen = l_capData->PfaCaptureDataSize;
    }

    i_parser.PrintBlank();
    i_parser.PrintHeading("PRD Capture Data");
    i_parser.PrintBlank();

    char sigHeaderString[72], sigDataString[100];
    UtilMem lCapDataBS( l_capData->CaptureData,
                        l_capData->PfaCaptureDataSize * 8 ); // pw06

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
        char chipName[42], temp[42];
        getTargetInfo(l_chipId, l_targetType, &temp[0], 42 );
        snprintf( chipName, 42, "%s (0x%08x)", temp, l_chipId );
        // Print out the chip ID.
        i_parser.PrintString( chipName,
                              "*********************************************" );

        // Iterate through all of the chip's signatures
        for ( uint8_t j = 0; j < chipSigCount; j++ )
        {
            // Get register ID and data length from register header.
            uint16_t sigId;
            uint16_t sigDataSize;
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
            else if ( Util::hashString("MEM_UE_TABLE") == sigId )
            {
                 parseMemUeTable( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("MEM_CE_TABLE") == sigId )
            {
                 parseMemCeTable( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("DRAM_REPAIRS_DATA") == sigId )
            {
                 parseDramRepairsData( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("DRAM_REPAIRS_VPD") == sigId )
            {
                 parseDramRepairsVpd( sigData, sigDataSize, i_parser );
            }
            else if ( Util::hashString("BAD_DQ_BITMAP") == sigId )
            {
                 parseBadDqBitmap( sigData, sigDataSize, i_parser );
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

                snprintf( sigDataString, 100, "(0x%016llX) 0x%08x 0x%08x",
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

    if ( 2 <= i_ver ) // version 2 and above are compressed.
    {
        i_parser.PrintBlank();
        i_parser.PrintHeading("Uncompressed Capture Buffer");
        i_parser.PrintBlank();
        i_parser.PrintHexDump( l_uncompBuffer, l_uncompBufSize );
    }

    i_parser.PrintBlank();
    i_parser.PrintHeading("Compressed Capture Buffer");
    // NOTE: The compressed buffer is added by the ERRL component.

    delete [] l_uncompBuffer;

    rc = false;
    return rc;
}

//------------------------------------------------------------------------------

bool parsePfaData( void * i_buffer, uint32_t i_buflen,
                   ErrlUsrParser & i_parser )
{
    bool rc = true;

    i_parser.PrintBlank();

    if ( NULL != i_buffer )
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
        i_parser.PrintBool("  FLOODING",               pfa.FLOODING           );
        i_parser.PrintBool("  Thermal Event",          pfa.THERMAL_EVENT      );
        i_parser.PrintBool("  Unit CS",                pfa.UNIT_CHECKSTOP     );
        i_parser.PrintBool("  Using Sync'd Saved Sdc", pfa.USING_SAVED_SDC    );
        i_parser.PrintBool("  Last Core Termination",  pfa.LAST_CORE_TERMINATE);
        i_parser.PrintBool("  Deferred Deconfig",      pfa.DEFER_DECONFIG     );

        // Attention types
        i_parser.PrintNumber("Primary ATTN type",   "0x%02X", pfa.priAttnType);
        i_parser.PrintNumber("Secondary ATTN type", "0x%02X", pfa.secAttnType);

        // Thresholding
        snprintf( tmp, 50, "%d of %d", pfa.errorCount, pfa.threshold );
        i_parser.PrintString( "Error Count", tmp );

        // Dump info
        i_parser.PrintNumber("DUMP Content", "0x%08x", pfa.msDumpInfo.content);
        i_parser.PrintNumber("DUMP HUID",    "0x%08x", pfa.msDumpInfo.id);

        // Error log actions and severity
        i_parser.PrintNumber( "ERRL Actions", "0x%04x", pfa.errlActions );

        tmpStr = "Undefined";
        switch ( pfa.errlSeverity )
        {
            case ERRL_SEV_INFORMATIONAL: tmpStr = "INFORMATIONAL"; break;
            case ERRL_SEV_RECOVERED:     tmpStr = "RECOVERED";     break;
            case ERRL_SEV_PREDICTIVE:    tmpStr = "PREDICTIVE";    break;
            case ERRL_SEV_UNRECOVERABLE: tmpStr = "UNRECOVERABLE"; break;
        }
        snprintf( tmp, 50, "ERRL_SEV_%s (0x%x) ", tmpStr, pfa.errlSeverity );
        i_parser.PrintString( "ERRL Severity", tmp );

        // GARD info
        // Need to use PRDF namespace as we have included prdfGardType.H
        // in nested PRDF namespace
        tmpStr = PRDF::GardAction::ToString( pfa.prdGardErrType );
        snprintf( tmp, 50, "%s (0x%X) ", tmpStr, pfa.prdGardErrType );
        i_parser.PrintString( "PRD GARD Error Type", tmp );
        i_parser.PrintNumber( "HWAS GARD State", "0x%02X", pfa.hwasGardState );

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
                    case SRCI_PRIORITY_LOW:  tmpStr = "LOW";   break;
                    case SRCI_PRIORITY_MEDC: tmpStr = "MED_C"; break;
                    case SRCI_PRIORITY_MEDB: tmpStr = "MED_B"; break;
                    case SRCI_PRIORITY_MEDA: tmpStr = "MED_A"; break;
                    case SRCI_PRIORITY_MED:  tmpStr = "MED";   break;
                    case SRCI_PRIORITY_HIGH: tmpStr = "HIGH";  break;
                }
                snprintf( header, 25, " #%d %s", i+1, tmpStr );

                snprintf( data, 50, "0x%08x ", pfa.mruList[i].callout );

                switch ( pfa.mruList[i].type )
                {
                    case PRDcalloutData::TYPE_MEMMRU:
                        strcat( data, "(MemoryMru)" );
                        i_parser.PrintString( header, data );
                        parseMemMruData( i_parser, pfa.mruList[i].callout );
                        break;

                    case PRDcalloutData::TYPE_SYMFRU:
                        strcat( data, "(SymbolicFru)" );
                        i_parser.PrintString( header, data );
                        break;

                    case PRDcalloutData::TYPE_TARGET:
                        strcat( data, "(HUID)" );
                        i_parser.PrintString( header, data );
                        break;

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

            TARGETING::TYPE trgtType = TARGETING::TYPE_NA;
            for ( uint32_t i = 0; i < pfa.sigListCount; ++i )
            {
                char tmp1[256], tmp2[256];

                getTargetInfo( pfa.sigList[i].chipId, trgtType, &tmp1[0], 256 );

                uint32_t sig = pfa.sigList[i].signature;
                snprintf( tmp2, 256, "%s %s", tmp1,
                          (GetErrorSigTable()[trgtType][sig]).c_str() );

                i_parser.PrintString( "", tmp2 );
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

bool parseAVPData( void * i_buffer, uint32_t i_buflen,
                   ErrlUsrParser & i_parser )
{
    bool rc = true;

    if (i_buffer)
    {
        //To get endianness correct
        uint32_t l_avpTCNumber;
        UtilMem l_membuf1(i_buffer,i_buflen);
        l_membuf1 >> l_avpTCNumber;

        i_parser.PrintHeading("");
        i_parser.PrintHeading("PRD AVP Test Case Data");

        i_parser.PrintNumber("AVP Test Case Number", "0x%08x", l_avpTCNumber);
    }

    // Set return code to false, so that the hex data is dumped out, for now.
    rc = false;

    return rc;
}

//------------------------------------------------------------------------------

bool parseHdatAVPData( void * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser )
{
    bool rc = true;
    char l_buffer[29];

    if (i_buffer)
    {
        uint32_t l_avpTCInfo;
        uint8_t  l_avpTCInfoByte;

        i_parser.PrintHeading("");
        i_parser.PrintHeading("PRD HDAT AVP Test Case Data");

        memcpy(l_buffer, i_buffer, 29);
        memcpy(&l_avpTCInfo, l_buffer, 4);
        i_parser.PrintNumber("AVP Test Case Number", "0x%08x", l_avpTCInfo);
        memcpy(&l_avpTCInfo, &l_buffer[4], 4);
        i_parser.PrintNumber("AVP Test List Entry", "0x%08x", l_avpTCInfo);
        memcpy(&l_avpTCInfoByte, &l_buffer[8], 1);
        i_parser.PrintNumber("AVP Test Corner", "0x%02x", l_avpTCInfoByte);
        l_buffer[28] = '\0';
        i_parser.PrintString("AVP Description", &l_buffer[9]);
    }

    // Set return code to false, so that the hex data is dumped out, for now.
    rc = false;

    return rc;
}

//------------------------------------------------------------------------------

bool parseMemMru( void * i_buffer, uint32_t i_buflen, ErrlUsrParser & i_parser )
{
    bool o_rc = true;

    uint32_t memMru;
    size_t sz_memMru = sizeof( memMru );

    i_parser.PrintBlank();

    if ( i_buflen != sz_memMru )
    {
        i_parser.PrintString( "                   ERROR",
                              "Unable to parse MRU data" );
        i_parser.PrintBlank();
        i_parser.PrintHexDump( i_buffer, i_buflen );
    }
    else
    {
        UtilMem membuf( i_buffer, i_buflen );
        membuf >> memMru;

        char header[72];
        snprintf( header, 72, "MemoryMru (0x%08x)", memMru );
        i_parser.PrintHeading( header );

        o_rc = parseMemMruData( i_parser, memMru );
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

        case ErrlAVPData_1:
            rc = parseAVPData(i_buffer, i_buflen, i_parser);
            break;

        case ErrlAVPData_2:
            rc = parseHdatAVPData(i_buffer, i_buflen, i_parser);
            break;

        case ErrlMruData_1:
            rc = parseMemMru( i_buffer, i_buflen, i_parser );
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
    //ErrorCodeDescription* l_chipTable = NULL;

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
            case PRDF_THERMAL_FAIL:
                srcErrClass = "Thermal Error Condition";
                break;
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

        // Get the target type and chip name.
        TARGETING::TYPE l_targetType = TARGETING::TYPE_NA;
        char chipName[42];
        getTargetInfo( l_chipId, l_targetType, &chipName[0], 42 );

        std::string l_descString = GetErrorSigTable()[l_targetType][l_signature];
        const char * l_description = NULL;

        if (std::string() == l_descString)
        {
            for( uint32_t l_idx = 1;
                 g_defaultErrorCodes[l_idx].description != NULL; ++l_idx)
            {
                if (l_signature == g_defaultErrorCodes[l_idx].signature)
                {
                    l_description = g_defaultErrorCodes[l_idx].description;
                    break;
                }
            }
            if (l_description == NULL)
            {
                l_description = g_defaultErrorCodes[0].description;
            }
        }
        else
        {
            l_description = l_descString.c_str();
        }

        char l_tmp[MAX_DESC_LEN];  //@jl00 changed this from 100 to const 256.
        //Changed sprintf to snprintf to stop buffer overruns with long desc.
        snprintf(l_tmp, MAX_DESC_LEN , "%s %s", chipName, l_description);
        i_parser.PrintString("Signature Description", l_tmp);
    }

    return rc;
}

} //end namespace HOSTBOOT/FSP
} // end namespace PRDF

