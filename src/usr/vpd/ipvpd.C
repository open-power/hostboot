/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ipvpd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
/* [+] Google Inc.                                                        */
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
// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <endian.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <devicefw/userif.H>
#include <eeprom/eepromif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/vpd_if.H>
#include <vpd/ipvpdenums.H>
#include <util/utilrsvdmem.H>
#include <util/runtime/util_rt.H>

#include "vpd.H"
#include "ipvpd.H"
#include "errlud_vpd.H"

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_vpd;


// ----------------------------------------------
// Globals
// ----------------------------------------------

static const uint64_t IPVPD_TOC_SIZE = 0x100;  //256
static const uint64_t IPVPD_TOC_ENTRY_SIZE = 8;
static const uint64_t IPVPD_TOC_INVALID_DATA = 0xFFFFFFFFFFFFFFFF;

/**
 * @brief  Constructor
 */
IpVpdFacade::IpVpdFacade(const  recordInfo* i_vpdRecords,
                         uint64_t i_recSize,
                         const  keywordInfo* i_vpdKeywords,
                         uint64_t i_keySize,
                         PNOR::SectionId i_pnorSection,
                         mutex_t i_mutex,
                         VPD::VPD_MSG_TYPE i_vpdMsgType )
:iv_vpdRecords(i_vpdRecords)
,iv_recSize(i_recSize)
,iv_vpdKeywords(i_vpdKeywords)
,iv_keySize(i_keySize)
,iv_pnorSection(i_pnorSection)
,iv_mutex(i_mutex)
,iv_cachePnorAddr(0x0)
,iv_vpdMsgType(i_vpdMsgType)
{
    iv_configInfo.vpdReadPNOR   = false;
    iv_configInfo.vpdReadHW     = false;
    iv_configInfo.vpdWritePNOR  = false;
    iv_configInfo.vpdWriteHW    = false;
    iv_vpdSectionSize           = 0;
    iv_vpdMaxSections           = 0;

    TRACUCOMP(g_trac_vpd, "IpVpdFacade::IpVpdFacade> " );
}


// ------------------------------------------------------------------
// IpVpdFacade::read
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::read ( TARGETING::Target * i_target,
                               void* io_buffer,
                               size_t & io_buflen,
                               input_args_t i_args )
{
    errlHndl_t err = NULL;
    const char * recordName = NULL;
    const char * keywordName = NULL;
    uint16_t recordOffset = 0x0;

    TRACUCOMP(g_trac_vpd, "IpVpdFacade::read> " );

    do
    {
        // Get the Record/keyword names
        err = translateRecord(i_args.record,
                              recordName);
        if( err )
        {
            TRACFCOMP( g_trac_vpd,
                       ERR_MRK"IpVpdFacade::read: translateRecord failed" );
            break;
        }

        err = translateKeyword( i_args.keyword,
                                keywordName );

        if( err )
        {
            TRACFCOMP( g_trac_vpd,
                       ERR_MRK"IpVpdFacade::read: translateKeyword failed" );
            break;
        }

        TRACSSCOMP( g_trac_vpd,
                   INFO_MRK"IpVpdFacade::read: Record (%s) and Keyword (%s)",
                   recordName, keywordName );

        // Get the offset of the record requested
        err = findRecordOffset( recordName,
                                recordOffset,
                                iv_configInfo.vpdReadPNOR,
                                iv_configInfo.vpdReadHW,
                                i_target,
                                i_args );
        if( err )
        {
            break;
        }

        TRACSSCOMP( g_trac_vpd,
                   INFO_MRK"IpVpdFacade::read: Record offset for %s is 0x%.4x",
                   recordName, recordOffset );

        if(IPVPD::FULL_RECORD == i_args.keyword)
        {
            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::read: read full record - target 0x%.8X length 0x%X",
              TARGETING::get_huid(i_target), io_buflen);
            // full record
            err = retrieveRecord(  recordName,
                                   recordOffset,
                                   i_target,
                                   io_buffer,
                                   io_buflen,
                                   i_args );
        }
        else //specific keyword
        {
            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::read: retrieveKeyword  target 0x%.8X length 0x%X",
              TARGETING::get_huid(i_target), io_buflen);

            // use record offset to find/read the keyword
            err = retrieveKeyword( keywordName,
                                   recordName,
                                   recordOffset,
                                   0,
                                   i_target,
                                   io_buffer,
                                   io_buflen,
                                   i_args );
        }

        if( err )
        {
            TRACSSCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::read: target 0x%.8X length 0x%X failed",
              TARGETING::get_huid(i_target), io_buflen);
            break;
        }

    } while( 0 );

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        VPD::UdVpdParms( i_target,
                         io_buflen,
                         i_args.record,
                         i_args.keyword,
                         true ) // read
                       .addToLog(err);
    }

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::read()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::write
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::write ( TARGETING::Target * i_target,
                                void* io_buffer,
                                size_t & io_buflen,
                                input_args_t i_args )
{
    errlHndl_t err = NULL;
    const char * recordName = NULL;
    const char * keywordName = NULL;
    uint16_t recordOffset = 0x0;

    TRACUCOMP(g_trac_vpd, "IpVpdFacade::write> " );

    do
    {

        // Get the Record/keyword names
        err = translateRecord(i_args.record,
                              recordName);
        if( err )
        {
            break;
        }

        err = translateKeyword( i_args.keyword,
                                keywordName );
        if( err )
        {
            break;
        }

        TRACSSCOMP( g_trac_vpd,
                   INFO_MRK"IpVpdFacade::Write: Record (%s) and Keyword (%s)",
                   recordName, keywordName );

        // If writes to PNOR and SEEPROM are both enabled and
        //   the write location is not specified, then call
        //   write() recursively for each location
        if ( iv_configInfo.vpdWritePNOR &&
             iv_configInfo.vpdWriteHW &&
             ((i_args.location & VPD::LOCATION_MASK) == VPD::AUTOSELECT) )
        {
            input_args_t l_args = i_args;

            l_args.location = VPD::SEEPROM;
            err = write( i_target,
                         io_buffer,
                         io_buflen,
                         l_args );
            if( err )
            {
                break;
            }

            // PNOR needs to be loaded before we can write it
            TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                    i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
            if( vpdSwitches.pnorCacheValid )
            {
                l_args.location = VPD::PNOR;
                err = write( i_target,
                             io_buffer,
                             io_buflen,
                             l_args );
                if( err )
                {
                    break;
                }
            }
        }
        else
        {
            // Get the offset of the record requested
            err = findRecordOffset( recordName,
                                    recordOffset,
                                    iv_configInfo.vpdWritePNOR,
                                    iv_configInfo.vpdWriteHW,
                                    i_target,
                                    i_args );
            if( err )
            {
                break;
            }

            // Use record offset to find/write the keyword
            err = writeKeyword( keywordName,
                                recordName,
                                recordOffset,
                                i_target,
                                io_buffer,
                                io_buflen,
                                i_args );
            if( err )
            {
                break;
            }

            //@TODO-RTC:250100-Enable Enterprise VPD ECC
            // Need add the VPD ECC update code here
        }
    } while( 0 );

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        VPD::UdVpdParms( i_target,
                         io_buflen,
                         i_args.record,
                         i_args.keyword,
                         false ) // write
                       .addToLog(err);
    }

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::Write()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::cmpEecacheToEeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::cmpEecacheToEeprom(TARGETING::Target * i_target,
                                           VPD::vpdRecord      i_record,
                                           VPD::vpdKeyword     i_keyword,
                                           bool              & o_match)
{
    errlHndl_t l_err = nullptr;

    TRACSSCOMP(g_trac_vpd, ENTER_MRK"cmpEecacheToEeprom() ");

    o_match = false;

    input_args_t l_cacheArgs;
    l_cacheArgs.record = i_record;
    l_cacheArgs.keyword = i_keyword;
    l_cacheArgs.location = VPD::SEEPROM;
    l_cacheArgs.eepromSource = EEPROM::CACHE;

    input_args_t l_hardwareArgs;
    l_hardwareArgs.record = i_record;
    l_hardwareArgs.keyword = i_keyword;
    l_hardwareArgs.location = VPD::SEEPROM;
    l_hardwareArgs.eepromSource = EEPROM::HARDWARE;

    do
    {
        // Get the CACHE size
        size_t l_sizeCache = 0;

        l_err = read(i_target,
                     nullptr,
                     l_sizeCache,
                     l_cacheArgs);

        if( l_err || (l_sizeCache == 0) )
        {
            TRACFCOMP(g_trac_vpd,
                      "cmpEecacheToEeprom() an error occurred reading the keyword size in cache");
            break;
        }

        // Get the CACHE data
        uint8_t l_dataCache[l_sizeCache];
        l_err = read( i_target,
                      l_dataCache,
                      l_sizeCache,
                      l_cacheArgs );

        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      "cmpEecacheToEeprom() an error occurred reading the keyword in cache");
            break;
        }

        // Get the HARDWARE size
        size_t l_sizeHardware = 0;
        l_err = read( i_target,
                      nullptr,
                      l_sizeHardware,
                      l_hardwareArgs );

        if( l_err || (l_sizeHardware == 0) )
        {
            TRACFCOMP(g_trac_vpd,
                      "cmpEecacheToEeprom() an error occurred reading the keyword size in hardware");
            break;
        }

        // Get the HARDWARE data
        uint8_t l_dataHardware[l_sizeHardware];
        l_err = read( i_target,
                      l_dataHardware,
                      l_sizeHardware,
                      l_hardwareArgs );

        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      "cmpEecacheToEeprom() an error occurred reading the keyword in hardware");
            break;
        }

        // Compare the CACHE/HARDWARE keyword size/data
        if( l_sizeCache != l_sizeHardware )
        {
            // Leave o_match == false since there isn't a match.
            break;
        }

        if( memcmp( l_dataCache,
                    l_dataHardware,
                    l_sizeCache ) != 0 )
        {
            TRACFCOMP( g_trac_vpd, "cmpEecacheToEeprom found mismatch for HUID %.8X 0x%X:0x%X", TARGETING::get_huid(i_target), i_record, i_keyword );
            TRACFBIN( g_trac_vpd, "HARDWARE", l_dataHardware, l_sizeHardware );
            TRACFBIN( g_trac_vpd, "CACHE", l_dataCache, l_sizeCache );
            break;
        }

        o_match = true;

    } while(0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"cmpEecacheToEeprom()" );

    return l_err;
}

// ------------------------------------------------------------------
// IpVpdFacade::cmpPnorToSeeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::cmpPnorToSeeprom ( TARGETING::Target * i_target,
                                           VPD::vpdRecord i_record,
                                           VPD::vpdKeyword i_keyword,
                                           bool &o_match )
{
    errlHndl_t l_err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"cmpPnorToSeeprom() " );

    o_match = false;

    input_args_t l_pnorArgs;
    l_pnorArgs.record = i_record;
    l_pnorArgs.keyword = i_keyword;
    l_pnorArgs.location = VPD::PNOR;

    input_args_t l_seepromArgs;
    l_seepromArgs.record = i_record;
    l_seepromArgs.keyword = i_keyword;
    l_seepromArgs.location = VPD::SEEPROM;

    do
    {
        // Get the PNOR size
        size_t l_sizePnor = 0;
        l_err = read( i_target,
                      NULL,
                      l_sizePnor,
                      l_pnorArgs );
        if( l_err || (l_sizePnor == 0) )
        {
            // PNOR may not be loaded, ignore the error
            delete l_err;
            l_err = NULL;
            break;
        }

        // Get the PNOR data
        uint8_t l_dataPnor[l_sizePnor];
        l_err = read( i_target,
                      l_dataPnor,
                      l_sizePnor,
                      l_pnorArgs );
        if( l_err )
        {
            break;
        }

        // Get the SEEPROM size
        size_t l_sizeSeeprom = 0;
        l_err = read( i_target,
                      NULL,
                      l_sizeSeeprom,
                      l_seepromArgs );
        if( l_err || (l_sizeSeeprom == 0) )
        {
            break;
        }

        // Get the SEEPROM data
        uint8_t l_dataSeeprom[l_sizeSeeprom];
        l_err = read( i_target,
                      l_dataSeeprom,
                      l_sizeSeeprom,
                      l_seepromArgs );
        if( l_err )
        {
            break;
        }

        // Compare the PNOR/SEEPROM size/data
        if( l_sizePnor != l_sizeSeeprom )
        {
            break;
        }
        if( memcmp( l_dataPnor,
                    l_dataSeeprom,
                    l_sizePnor ) != 0 )
        {
            TRACFCOMP( g_trac_vpd, "cmpPnorToSeeprom found mismatch for HUID %.8X 0x%X:0x%X", TARGETING::get_huid(i_target), i_record, i_keyword );
            TRACFBIN( g_trac_vpd, "EEPROM", l_dataSeeprom, l_sizeSeeprom );
            TRACFBIN( g_trac_vpd, "PNOR", l_dataPnor, l_sizePnor );
            break;
        }

        o_match = true;

    } while(0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"cmpPnorToSeeprom()" );

    return l_err;
}

// ------------------------------------------------------------------
// IpVpdFacade::cmpSeepromToZero
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::cmpSeepromToZero ( TARGETING::Target * i_target,
                                           VPD::vpdRecord i_record,
                                           VPD::vpdKeyword i_keyword,
                                           bool &o_match )
{
    errlHndl_t l_err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"cmpSeepromToZero() " );

    o_match = false;

    input_args_t l_seepromArgs;
    l_seepromArgs.record = i_record;
    l_seepromArgs.keyword = i_keyword;
    l_seepromArgs.location = VPD::SEEPROM;

    do
    {
        // Get the SEEPROM size
        size_t l_sizeSeeprom = 0;
        l_err = read( i_target,
                      NULL,
                      l_sizeSeeprom,
                      l_seepromArgs );
        if( l_err || (l_sizeSeeprom == 0) )
        {
            break;
        }

        // Get the SEEPROM data
        uint8_t l_dataSeeprom[l_sizeSeeprom];
        l_err = read( i_target,
                      l_dataSeeprom,
                      l_sizeSeeprom,
                      l_seepromArgs );
        if( l_err )
        {
            break;
        }

        // Compare the SEEPROM data to zero
        uint8_t l_zero[l_sizeSeeprom];
        memset(l_zero,0,l_sizeSeeprom);

        if( memcmp( l_zero,
                    l_dataSeeprom,
                    l_sizeSeeprom ) != 0 )
        {
            break;
        }

        o_match = true;

    } while(0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"cmpSeepromToZero()" );

    return l_err;
}

/*             IPVPD PNOR FORMAT
   |-----------------------------------------------------------|----|
   |TOC0|TOC1|...........................................|TOC31|    |
   |-----------------------------------------------------------|TARG0
   |REC1DATA|.........................................|RECNDATA|64K |
   |-----------------------------------------------------------|----|
   |TOC0|TOC1|...........................................|TOC31|    |
   |-----------------------------------------------------------|TARG1
   |REC1DATA|.........................................|RECNDATA|64K |
   |-----------------------------------------------------------|----|
   |TOC0|TOC1|...........................................|TOC31|    |
   |-----------------------------------------------------------|TARG2
   |REC1DATA|.........................................|RECNDATA|64K |
   |-----------------------------------------------------------|----|
   ---- Till TARGN
*/

#ifndef __HOSTBOOT_RUNTIME
// ------------------------------------------------------------------
// IpVpdFacade::loadPnor
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::loadPnor ( TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::loadPnor()" );

    // Load PNOR TOC with invalid data
    err = invalidatePnor( i_target );
    if( err )
    {
        TRACFCOMP(g_trac_vpd,
                  "IpVpdFacade::loadPnor() Error invalidating PNOR Target %.8X",
                  TARGETING::get_huid(i_target));
        return err;
    }

    // Temp data for entire VPD entry
    uint8_t* tmpVpdPtr = new uint8_t[iv_vpdSectionSize];

    // Load the temp data with invalid TOC
    uint64_t tocdata = IPVPD_TOC_INVALID_DATA;
    for( uint32_t tocoffset = 0;
         tocoffset < IPVPD_TOC_SIZE;
         tocoffset += IPVPD_TOC_ENTRY_SIZE )
    {
        memcpy( (tmpVpdPtr + tocoffset),
                &tocdata,
                IPVPD_TOC_ENTRY_SIZE );
    }

    // Load PNOR cache from SEEPROM
    // Variables starting with p=PNOR, s=SEEPROM

    // Table of contents
    tocData pTocEntry;
    uint16_t pTocOffset = 0;

    // Records
    uint16_t sRecOffset = 0;
    uint16_t sRecLength = 0;
    uint16_t pRecOffset = IPVPD_TOC_SIZE;  // Records begin after TOC
    input_args_t sRecArgs;
    sRecArgs.location =
              static_cast<VPD::vpdCmdTarget>(VPD::SEEPROM | VPD::USEVPD);

    std::list<pt_entry> recList;
    recList.clear();
    err = getRecordListSeeprom( recList,
                                i_target,
                                sRecArgs );
    if( err )
    {
        TRACFCOMP(g_trac_vpd,"IpVPdFacade::loadPnor() getRecordListSeeprom failed");
        return err;
    }

    for ( std::list<pt_entry>::iterator it = recList.begin();
          it != recList.end(); it++ )
    {
        // Copy the record name to the toc structure asciiRec
        memcpy( pTocEntry.asciiRec,
                (*it).record_name,
                RECORD_BYTE_SIZE );

        // Swap the bytes to match SEEPROM VPD format
        pTocEntry.offset[0] = ((uint8_t*)(&pRecOffset))[1];
        pTocEntry.offset[1] = ((uint8_t*)(&pRecOffset))[0];

        // Just a signature after every TOC entry
        pTocEntry.unusedByte[0] = 0x5A;
        pTocEntry.unusedByte[1] = 0x5A;

        // Write TOC to temp data
        memcpy( (tmpVpdPtr + pTocOffset),
                &pTocEntry,
                IPVPD_TOC_ENTRY_SIZE );

        // Byte swap fields, skip 'large resource' byte
        sRecOffset = le16toh( (*it).record_offset ) + 1;
        sRecLength = le16toh( (*it).record_length );

        // Make sure we don't exceed our allocated space in PNOR
        if( (pRecOffset + sRecLength) > iv_vpdSectionSize )
        {
            TRACFCOMP(g_trac_vpd,"IpVpdFacade::loadPnor()> The amount of space required (0x%X) for the VPD cache exceeds the available space (0x%X)", pRecOffset + sRecLength, iv_vpdSectionSize );
            /*@
             * @errortype
             * @reasoncode       VPD::VPD_CACHE_SIZE_EXCEEDED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_LOAD_PNOR
             * @userdata1        HUID of target chip
             * @userdata2[00:31] Available size
             * @userdata2[32:63] Requested size
             * @devdesc          The amount of space required for the VPD
             *                   cache exceeds the available space
             * @custdesc         Fatal firmware boot error
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_LOAD_PNOR,
                                           VPD::VPD_CACHE_SIZE_EXCEEDED,
                                           TARGETING::get_huid(i_target),
                                           TWO_UINT32_TO_UINT64(
                                              iv_vpdSectionSize,
                                              pRecOffset + sRecLength ),
                                           true /*Add HB SW Callout*/ );
            err->collectTrace( VPD_COMP_NAME, 256 );
            break;
        }

        // Read record data from SEEPROM, put it into temp data
        uint8_t* pRecPtr = tmpVpdPtr + pRecOffset;
        err = fetchData( sRecOffset,
                         sRecLength,
                         pRecPtr,
                         i_target,
                         sRecArgs.location,
                         (*it).record_name );
        if( err )
        {
            TRACFCOMP(g_trac_vpd,"IpVpdFacade::loadPnor() Error reading record %s",(*it).record_name);
            break;
        }

        // Increment the PNOR TOC and record offsets
        pTocOffset += IPVPD_TOC_ENTRY_SIZE;
        pRecOffset += sRecLength;
    }

    if( !err )
    {
        // Setup info needed to write PNOR
        VPD::pnorInformation pInfo;
        pInfo.segmentSize = iv_vpdSectionSize;
        pInfo.maxSegments = iv_vpdMaxSections;
        pInfo.pnorSection = iv_pnorSection;

        // Write the entire PNOR entry
        err = VPD::writePNOR( 0x0,                  // start offset
                              pRecOffset,           // size
                              tmpVpdPtr,            // data
                              i_target,
                              pInfo,
                              iv_cachePnorAddr,
                              &iv_mutex );
        if( err )
        {
            TRACFCOMP(g_trac_vpd,"IpVpdFacade::loadPnor() Error writing PNOR VPD data");
        }
    }
    else
    {
        // Error reading record data, invalidate the TOC
        // Use different errl so we don't overwrite the original
        errlHndl_t invErr = NULL;
        invErr = invalidatePnor( i_target );
        if( invErr )
        {
            TRACFCOMP(g_trac_vpd,"IpVpdFacade::loadPnor() "
                      "Error invalidating PNOR Target %.8X",
                      TARGETING::get_huid(i_target));
            delete invErr;
            invErr = NULL;
        }
    }

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::loadPnor()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::invalidatePnor
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::invalidatePnor ( TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::invalidatePnor()" );

    // Setup info needed to write PNOR
    VPD::pnorInformation pInfo;
    pInfo.segmentSize = iv_vpdSectionSize;
    pInfo.maxSegments = iv_vpdMaxSections;
    pInfo.pnorSection = iv_pnorSection;

    // Temp data for entire TOC
    uint8_t* tmpTocPtr = new uint8_t[IPVPD_TOC_SIZE];

    // Load the temp data with invalid TOC
    uint64_t tocdata = IPVPD_TOC_INVALID_DATA;
    for( uint32_t tocoffset = 0;
         tocoffset < IPVPD_TOC_SIZE;
         tocoffset += IPVPD_TOC_ENTRY_SIZE )
    {
        memcpy( (tmpTocPtr + tocoffset),
                &tocdata,
                IPVPD_TOC_ENTRY_SIZE );
    }

    // Write the entire PNOR TOC
    err = VPD::writePNOR( 0x0,              // start offset
                          IPVPD_TOC_SIZE,   // size
                          tmpTocPtr,        // data
                          i_target,
                          pInfo,
                          iv_cachePnorAddr,
                          &iv_mutex );
    if( err )
    {
        TRACFCOMP(g_trac_vpd,
                  "IpVpdFacade::invalidatePnor() Error writing PNOR TOC");
        return err;
    }

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::invalidatePnor()" );

    return err;
}
#endif

// ------------------------------------------------------------------
// IpVpdFacade::translateRecord
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::translateRecord ( VPD::vpdRecord i_record,
                                          const char *& o_record )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::translateRecord(i_record=0x%.8X)",
                i_record );

    do
    {
        recordInfo tmpRecord;
        tmpRecord.record = i_record;
        const recordInfo * entry = std::lower_bound(iv_vpdRecords,
                                                    &iv_vpdRecords[iv_recSize],
                                                    tmpRecord,
                                                    compareRecords );

        if( ( entry == &iv_vpdRecords[iv_recSize] )||
            ( i_record != entry->record ) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::translateRecord: "
                       "No matching Record (0x%04x) found!",
                       i_record );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_RECORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_TRANSLATE_RECORD
             * @userdata1        Record enumeration.
             * @userdata2        <UNUSED>
             * @devdesc          The record enumeration did not have a
             *                   corresponding string value.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_TRANSLATE_RECORD,
                                           VPD::VPD_RECORD_NOT_FOUND,
                                           i_record,
                                           0x0,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( VPD_COMP_NAME, 256 );
            break;
        }

        o_record = entry->recordName;
        TRACDCOMP( g_trac_vpd,
                   "record name: %s",
                   entry->recordName );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::translateRecord()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::translateKeyword
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::translateKeyword ( VPD::vpdKeyword i_keyword,
                                           const char *& o_keyword )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::translateKeyword()" );

    do
    {
        keywordInfo tmpKeyword;
        tmpKeyword.keyword = i_keyword;
        const keywordInfo * entry =
          std::lower_bound( iv_vpdKeywords,
                            &iv_vpdKeywords[iv_keySize],
                            tmpKeyword,
                            compareKeywords );

        if( ( entry == &iv_vpdKeywords[iv_keySize] ) ||
            ( i_keyword != entry->keyword ) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::translateKeyword: "
                       "No matching Keyword found!" );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_KEYWORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_TRANSLATE_KEYWORD
             * @userdata1        Keyword Enumeration
             * @userdata2        <UNUSED>
             * @devdesc          The keyword enumeration did not have a
             *                   corresponding string value.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_TRANSLATE_KEYWORD,
                                           VPD::VPD_KEYWORD_NOT_FOUND,
                                           i_keyword,
                                           0x0 );

            // Could be FSP or HB code's fault
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_MED);
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_MED);

            err->collectTrace( VPD_COMP_NAME, 256 );
            break;
        }

        o_keyword = entry->keywordName;
        TRACDCOMP( g_trac_vpd,
                   "IpVpdFacade::translateKeyword: keyword name: %s",
                   entry->keywordName );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::translateKeyword()" );

    return err;
}


// ------------------------------------------------------------------
// IpVpdFacade::findRecordOffset
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findRecordOffset ( const char * i_record,
                                           uint16_t & o_offset,
                                           bool i_rwPnorEnabled,
                                           bool i_rwHwEnabled,
                                           TARGETING::Target * i_target,
                                           input_args_t i_args )
{
    errlHndl_t err = NULL;

    // Look for a record override in our image unless explicitly told not to
    if( (i_args.location & VPD::OVERRIDE_MASK) != VPD::USEVPD )
    {
        uint8_t* l_overridePtr = nullptr;
        VPD::RecordTargetPair_t l_recTarg =
          VPD::makeRecordTargetPair(i_record,i_target);

        // Check if we already figured out where to get this record from
        mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
        VPD::OverrideMap_t::iterator l_overItr = iv_overridePtr.find(l_recTarg);
        if( l_overItr != iv_overridePtr.end() )
        {
            l_overridePtr = l_overItr->second;
            mutex_unlock(&iv_mutex);
        }
        else
        {
            mutex_unlock(&iv_mutex);
            // Now go see if we should be using the override and if so
            //  where we find the right copy
            err = checkForRecordOverride(i_record,i_target,l_overridePtr);
            if( err )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"findRecordOffset> failure calling checkForRecordOverride for %s on %.8X",
                           i_record, get_huid(i_target) );
                return err;
            }

            // Don't trace that record exists in PNOR if it does not
            if (l_overridePtr != nullptr)
            {
                TRACFCOMP( g_trac_vpd, INFO_MRK" Record %s for target 0x%.8X exists at %p in PNOR",
                       i_record, get_huid(i_target), l_overridePtr );
            }
        }

        // If we have an override, the record is already pointed at directly
        if( l_overridePtr != nullptr )
        {
            o_offset = 0;
            return nullptr;
        }
    }

    // Determine the VPD source (PNOR/SEEPROM)
    VPD::vpdCmdTarget vpdSource = VPD::AUTOSELECT;
    bool configError = false;
    configError = VPD::resolveVpdSource( i_target,
                                         i_rwPnorEnabled,
                                         i_rwHwEnabled,
                                         i_args.location,
                                         vpdSource );
    // Get the record offset
    if ( vpdSource == VPD::PNOR )
    {
        err = findRecordOffsetPnor(i_record, o_offset, i_target, i_args);
    }
    else if ( vpdSource == VPD::SEEPROM )
    {
        uint16_t o_length;
        err = findRecordOffsetSeeprom(i_record,
                                      o_offset,
                                      o_length,
                                      i_target,
                                      i_args);
    }
    else
    {
        configError = true;
    }

    if( configError )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::findRecordOffset: "
                   "Error resolving VPD source (PNOR/SEEPROM)");

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_READ_SOURCE_UNRESOLVED
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FIND_RECORD_OFFSET
         * @userdata1[0:31]  Target HUID
         * @userdata1[32:63] Requested VPD Source Location
         * @userdata2[0:31]  VPD write PNOR flag
         * @userdata2[32:63] VPD write HW flag
         * @devdesc          Unable to resolve the VPD
         *                   source (PNOR or SEEPROM)
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FIND_RECORD_OFFSET,
                                       VPD::VPD_READ_SOURCE_UNRESOLVED,
                                       TWO_UINT32_TO_UINT64(
                                            TARGETING::get_huid(i_target),
                                            i_args.location ),
                                       TWO_UINT32_TO_UINT64(
                                            i_rwPnorEnabled,
                                            i_rwHwEnabled ),
                                       true /*Add HB SW Callout*/ );
        VPD::UdConfigParms( i_target,
                            i_args.record,
                            i_args.keyword,
                            i_args.location,
                            iv_configInfo.vpdReadPNOR,
                            iv_configInfo.vpdReadHW,
                            iv_configInfo.vpdWritePNOR,
                            iv_configInfo.vpdWriteHW
                          ).addToLog(err);
        err->collectTrace( VPD_COMP_NAME, 256 );
    }

    return err;
}



// ------------------------------------------------------------------
// IpVpdFacade::hasVpdPresent
// ------------------------------------------------------------------
bool IpVpdFacade::hasVpdPresent( TARGETING::Target * i_target,
                                 VPD::vpdRecord i_record,
                                 VPD::vpdRecord i_keyword )
{
    errlHndl_t err = NULL;
    uint16_t recordOffset = 0x0;
    input_args_t i_args;
    bool vpdPresent = false;
    const char * l_recordName = NULL;
    const char * l_keywordName = NULL;

    i_args.record = i_record;
    i_args.keyword = i_keyword;

    do
    {
        //get the Record/Keyword names
        err = translateRecord( i_args.record,
                               l_recordName );

        if( err )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"Error occurred during translateRecord\
                        - IpVpdFacade::hasVpdPresent");
            break;
        }

        err = translateKeyword( i_args.keyword,
                                l_keywordName );

        if( err )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"Error occurred during \
                            translateKeyword - IpVpdFacade::hasVpdPresent" );
            break;
        }

        vpdPresent = recordPresent( l_recordName,
                                    recordOffset,
                                    i_target,
                                    VPD::USEVPD );

    }while( 0 );

    if( err )
    {
        errlCommit( err, VPD_COMP_ID );
        return false;
    }


    return vpdPresent;
}

// ------------------------------------------------------------------
// IpVpdFacade::recordPresent
// ------------------------------------------------------------------
bool IpVpdFacade::recordPresent( const char * i_record,
                                 uint16_t & o_offset,
                                 TARGETING::Target * i_target,
                                 VPD::vpdCmdTarget i_location )
{
    errlHndl_t err = NULL;
    uint64_t tmpOffset = 0x0;
    char l_record[RECORD_BYTE_SIZE] = { '\0' };
    bool matchFound = false;

    do
    {
        // --------------------------------------
        // Start reading at beginning of file
        // First 256 bytes are the TOC
        // --------------------------------------
        // TOC Format is as follows:
        //      8 bytes per entry - 32 entries possible
        //   Entry:
        //      byte 0 - 3: ASCII Record Name
        //      byte 4 - 5: OFFSET (byte swapped)
        //      byte 6 - 7: UNUSED
        // --------------------------------------
        while( ( tmpOffset < IPVPD_TOC_SIZE ) &&
               !matchFound )
        {
            //Read Record Name
            err = fetchData( tmpOffset,
                             RECORD_BYTE_SIZE,
                             l_record,
                             i_target,
                             i_location,
                             i_record );
            tmpOffset += RECORD_BYTE_SIZE;

            if( err )
            {
                break;
            }

            if( !(memcmp(l_record, i_record, RECORD_BYTE_SIZE )) )
            {
                matchFound = true;

                // Read the matching record's offset
                err = fetchData( tmpOffset,
                                 RECORD_ADDR_BYTE_SIZE,
                                 &o_offset,
                                 i_target,
                                 i_location,
                                 i_record );
                if( err )
                {
                    break;
                }
            }
            tmpOffset += (RECORD_ADDR_BYTE_SIZE + RECORD_TOC_UNUSED);
        }

        if( err )
        {
            break;
        }
    }while( 0 );

    if( err )
    {
        errlCommit( err, VPD_COMP_ID );
        return false;
    }
    return matchFound;
}

// ------------------------------------------------------------------
// IpVpdFacade::findRecordOffsetPnor
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findRecordOffsetPnor ( const char * i_record,
                                               uint16_t & o_offset,
                                               TARGETING::Target * i_target,
                                               input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint16_t offset = 0x0;
    bool matchFound = false;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::findRecordOffset()" );

    matchFound = recordPresent( i_record,
                                offset,
                                i_target,
                                i_args.location );

    if( !matchFound )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::findRecordOffsetPnor: "
                   "No matching Record (%s) found in TOC!",
                   i_record );

        /*@
            * @errortype
            * @reasoncode       VPD::VPD_RECORD_NOT_FOUND
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         VPD::VPD_IPVPD_FIND_RECORD_OFFSET
            * @userdata1        Requested Record
            * @userdata2        Requested Keyword
            * @devdesc          The requested record was not found in the VPD TOC.
            */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        VPD::VPD_IPVPD_FIND_RECORD_OFFSET,
                                        VPD::VPD_RECORD_NOT_FOUND,
                                        i_args.record,
                                        i_args.keyword );

        // Could be the VPD of the target wasn't set up properly
        // -- DECONFIG so that we can possibly keep booting
        err->addHwCallout( i_target,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::DECONFIG,
                            HWAS::GARD_NULL );
        // Or FSP code didn't set up the VPD properly
        err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                    HWAS::SRCI_PRIORITY_MED);

        // Or HB code didn't look for the record properly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_LOW);

        // Add trace to the log so we know what record was being requested.
        err->collectTrace( VPD_COMP_NAME, 256 );


    }

    // Return the offset found, after byte swapping it.
    o_offset = le16toh( offset );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findRecordOffsetPnor()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::findRecordOffsetSeeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findRecordOffsetSeeprom ( const char * i_record,
                                                  uint16_t & o_recordOffset,
                                                  uint16_t & o_recordlength,
                                                  TARGETING::Target * i_target,
                                                  input_args_t i_args )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::findRecordOffsetSeeprom()" );

    errlHndl_t l_err(nullptr);

    // Create these "dummy" variables.  Don't need but necessary for API
    uint16_t l_eccOffset(0), l_eccLength(0);

    // Get the record meta data, which has the record offset/length caller
    // is interested in.
    l_err = findRecordMetaDataSeeprom( i_record, o_recordOffset, o_recordlength,
                                       l_eccOffset, l_eccLength,
                                       i_target, i_args);

    // The caller is only interested in the data past the 'Large Resource' byte,
    // therefore, move the offset 1 byte over.
    o_recordOffset += 1;

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findRecordOffsetSeeprom(): returning %s errors",
                (l_err ? "with" : "with no") );

    return l_err;
} // findRecordOffsetSeeprom


// ------------------------------------------------------------------
// IpVpdFacade::findRecordMetaDataSeeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findRecordMetaDataSeeprom ( const char * i_record,
                                                    uint16_t & o_recordOffset,
                                                    uint16_t & o_recordLength,
                                                    uint16_t & o_eccOffset,
                                                    uint16_t & o_eccLength,
                                                    TARGETING::Target * i_target,
                                                    const input_args_t &i_args )
{
    errlHndl_t err = nullptr;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::findRecordMetaDataSeeprom()" );

    // Get the VTOC record meta data
    pt_entry vtoc_rec;  // The struct to contain the VTOC meta data
    err = getVtocRecordMetaData(i_target, i_args, vtoc_rec);
    if (err)
    {
        return err;
    }

    // skip 'large resource'
    uint16_t offset = le16toh( vtoc_rec.record_offset ) + 1;

    // Create some useful variables
    char l_buffer[256] = { 0 };
    size_t pt_len = sizeof(l_buffer);
    pt_entry *toc_rec(nullptr);

    // Read the PT keyword(s) (there may be more than 1) from the VTOC to
    // find the requested record.
    bool found = false;
    for (uint16_t index = 0; !found; ++index)
    {
        pt_len = sizeof(l_buffer);
        err = retrieveKeyword( VPD_KEYWORD_POINTER_TO_RECORD,
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                               offset, index, i_target, l_buffer,
                               pt_len, i_args );
        if ( err ) {
            // There may be only one PT record
            if (index != 0)
            {
                delete err;
                err = nullptr;
            }
            break;
        }

        // Scan through the VTOC PT keyword records looking for a record
        // name match.
        for (size_t vtoc_pt_offset = 0; vtoc_pt_offset < pt_len;
            vtoc_pt_offset += sizeof(pt_entry))
        {
            toc_rec = reinterpret_cast<pt_entry*>(l_buffer + vtoc_pt_offset);
            TRACUCOMP( g_trac_vpd, "Scanning record %s", toc_rec->record_name);

            if (memcmp(toc_rec->record_name, i_record,
                       sizeof(toc_rec->record_name)) == 0)
            {
                o_recordOffset = le16toh( toc_rec->record_offset );
                o_recordLength = le16toh( toc_rec->record_length );
                o_eccOffset = le16toh( toc_rec->ecc_offset );
                o_eccLength = le16toh( toc_rec->ecc_length );
                found = true;
                break;
            }
        }
    }

    if ( !found && err == nullptr ) {
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::findRecordMetaDataSeeprom: "
                   "No matching Record (%s) found in VTOC!", i_record );

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_RECORD_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FIND_RECORD_OFFSET_SEEPROM
         * @userdata1[0:31]  Requested Record
         * @userdata1[32:63] Requested Keyword
         * @userdata2        Target HUID
         * @devdesc          The requested record was not found in the VPD VTOC.
         */
        err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD::VPD_IPVPD_FIND_RECORD_OFFSET_SEEPROM,
                            VPD::VPD_RECORD_NOT_FOUND,
                            TWO_UINT32_TO_UINT64(i_args.record,
                                                 i_args.keyword),
                            TARGETING::get_huid(i_target) );

        // Could be the VPD of the target wasn't set up properly
        // -- DECONFIG so that we can possibly keep booting
        err->addHwCallout( i_target,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::DECONFIG,
                           HWAS::GARD_NULL );

        // Or HB code didn't look for the record properly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_LOW);

        err->collectTrace( VPD_COMP_NAME );
    }

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findRecordMetaDataSeeprom(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
} // findRecordMetaDataSeeprom


// ------------------------------------------------------------------
// IpVpdFacade::getRecordListSeeprom
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::getRecordListSeeprom ( std::list<pt_entry> & o_recList,
                                    TARGETING::Target * i_target,
                                    input_args_t i_args )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::getRecordListSeeprom()" );

    // Get the VTOC record meta data
    pt_entry vtoc_rec;  // The struct to contain the VTOC meta data
    err = getVtocRecordMetaData(i_target, i_args, vtoc_rec);
    if (err)
    {
        return err;
    }

    // Get the list of records that should be copied to pnor.
    // The list of records for this vpd sub class will be the primary list.
    // If the eeprom is being shared, then their might be an alternate list
    // to also include.
    const  recordInfo* l_primaryVpdRecords = NULL;
    uint64_t           l_primaryRecSize = 0;
    const  recordInfo* l_altVpdRecords = NULL;
    uint64_t           l_altRecSize = 0;
    getRecordLists(l_primaryVpdRecords,
                   l_primaryRecSize,
                   l_altVpdRecords,
                   l_altRecSize);

    // skip 'large resource'
    uint16_t offset = le16toh( vtoc_rec.record_offset ) + 1;

    // Create some useful variables
    char l_buffer[256] = { 0 };
    size_t pt_len = sizeof(l_buffer);
    pt_entry *toc_rec(nullptr);

    // Read the PT keyword(s) from the VTOC
    for (uint16_t index = 0; index < 3; ++index)
    {
        pt_len = sizeof(l_buffer);
        err = retrieveKeyword( VPD_KEYWORD_POINTER_TO_RECORD,
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                               offset,
                               index,
                               i_target,
                               l_buffer,
                               pt_len,
                               i_args );
        if ( err )
        {
            // There may be only one PT keyword
            if ( index != 0 )
            {
                delete err;
                err = NULL;
            }
            break;
        }

        // Scan through the VTOC PT keyword records
        // Copy the records to the list
        for ( size_t vtoc_pt_offset = 0;
              vtoc_pt_offset < pt_len;
              vtoc_pt_offset += sizeof(pt_entry) )
        {
            bool l_found = false;
            toc_rec =
                reinterpret_cast<pt_entry*>(l_buffer + vtoc_pt_offset);

            // Save record if on the list for this target
            for ( uint32_t rec = 0; rec < l_primaryRecSize; rec++ )
            {
                if ( memcmp( toc_rec->record_name,
                            l_primaryVpdRecords[rec].recordName,
                            RECORD_BYTE_SIZE ) == 0 )
                {
                    o_recList.push_back(*toc_rec);
                    l_found = true;
                    break;
                }
            }
            // if not found, check the alternate list
            if (!l_found)
            {
                for ( uint32_t rec = 0; rec < l_altRecSize; rec++ )
                {
                    if ( memcmp( toc_rec->record_name,
                            l_altVpdRecords[rec].recordName,
                            RECORD_BYTE_SIZE ) == 0 )
                    {
                        o_recList.push_back(*toc_rec);
                        break;
                    }
                }
            }
        }
    }

    TRACSSCOMP( g_trac_vpd,EXIT_MRK"IpVpdFacade::getRecordListSeeprom()" );

    return err;
}


// ------------------------------------------------------------------
// IpVpdFacade::retrieveKeyword
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::retrieveKeyword ( const char * i_keywordName,
                                          const char * i_recordName,
                                          uint16_t i_offset,
                                          uint16_t i_index,
                                          TARGETING::Target * i_target,
                                          void * io_buffer,
                                          size_t & io_buflen,
                                          input_args_t i_args )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::retrieveKeyword(%s, %s, . . .)",
                i_keywordName,
                i_recordName );

    do
    {
        // First go find the keyword in memory
        size_t keywordSize = 0x0;
        uint64_t byteAddr = 0x0;
        err = findKeywordAddr( i_keywordName,
                               i_recordName,
                               i_offset,
                               i_index,
                               i_target,
                               keywordSize,
                               byteAddr,
                               i_args );
        if( err )
        {
            break;
        }

        // If the buffer is NULL, return the keyword size in io_buflen
        if( NULL == io_buffer )
        {
            io_buflen = keywordSize;
            break;
        }

        // check size of usr buffer with io_buflen
        err = checkBufferSize( io_buflen,
                               (size_t)keywordSize,
                               i_target );
        if( err )
        {
            break;
        }

        // Read keyword data into io_buffer
        err = fetchData( i_offset+byteAddr,
                         keywordSize,
                         io_buffer,
                         i_target,
                         i_args,
                         i_recordName );
        if( err )
        {
            break;
        }

        // Everything worked
        io_buflen = keywordSize;

    } while(0);

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::retrieveKeyword()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::retrieveRecord
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::retrieveRecord( const char * i_recordName,
                                          uint16_t i_offset,
                                          TARGETING::Target * i_target,
                                          void * io_buffer,
                                          size_t & io_buflen,
                                          input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint16_t l_size = 0x0;

    TRACUCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::retrieveRecord()" );

    do
    {
        // Get the record size.. it is the first two bytes of the record
        err = fetchData( i_offset,
                         sizeof(l_size),
                         &l_size,
                         i_target,
                         i_args.location,
                         i_recordName );

        if( err )
        {
            break;
        }

        //byteswap
        l_size = le16toh(l_size);
        l_size += 2; // include the 2 byte size field in total record

        // If the buffer is NULL, return the keyword size in io_buflen
        if( NULL == io_buffer )
        {
            io_buflen = l_size;
            break;
        }

        // check size of usr buffer with io_buflen
        err = checkBufferSize( io_buflen,
                               (size_t)l_size,
                               i_target );
        if( err )
        {
            break;
        }

        // Read keyword data into io_buffer
        err = fetchData( i_offset,
                         l_size,
                         io_buffer,
                         i_target,
                         i_args,
                         i_recordName );
        if( err )
        {
            break;
        }

        // Everything worked
        io_buflen = l_size;

    } while(0);

    TRACUCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::retrieveRecord()" );

    return err;
}


// ------------------------------------------------------------------
// IpVpdFacade::fetchData
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::fetchData ( uint64_t            i_byteAddr,
                                    size_t              i_numBytes,
                                    void *              o_data,
                                    TARGETING::Target * i_target,
                                    VPD::vpdCmdTarget   i_location,
                                    const char*         i_record )
{
    errlHndl_t err = nullptr;

    // Create an input_args struct which will default EEPROM_SOURCE
    // to EEPROM::AUTOSELECT.
    input_args_t inputArgs;

    // Set the VPD location to the given location (PNOR/SEEPROM).
    inputArgs.location = i_location;

    err = fetchData(i_byteAddr,
                    i_numBytes,
                    o_data,
                    i_target,
                    inputArgs,
                    i_record);

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::fetchData
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::fetchData ( uint64_t i_byteAddr,
                                    size_t i_numBytes,
                                    void * o_data,
                                    TARGETING::Target * i_target,
                                    input_args_t i_args,
                                    const char* i_record )
{
    errlHndl_t err = NULL;

    // Determine the VPD source (PNOR/SEEPROM)
    VPD::vpdCmdTarget vpdSource = VPD::AUTOSELECT;
    bool configError = false;
    configError = VPD::resolveVpdSource( i_target,
                                         iv_configInfo.vpdReadPNOR,
                                         iv_configInfo.vpdReadHW,
                                         i_args.location,
                                         vpdSource );

    // Look for a record override in our image unless explicitly told not to
    bool l_foundOverride = false;
    if( (i_args.location & VPD::OVERRIDE_MASK) != VPD::USEVPD )
    {
        uint8_t* l_overridePtr = nullptr;
        VPD::RecordTargetPair_t l_recTarg =
          VPD::makeRecordTargetPair(i_record,i_target);

        // At this point we can assume that the pointer is set into our
        //  map if we need it
        mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
        VPD::OverrideMap_t::iterator l_overItr = iv_overridePtr.find(l_recTarg);
        if( l_overItr != iv_overridePtr.end() )
        {
            l_overridePtr = l_overItr->second;

            // Just do a simple memcpy
            if( l_overridePtr != nullptr )
            {
                memcpy( o_data, l_overridePtr+i_byteAddr, i_numBytes );
                l_foundOverride = true;
            }
        }
        // Automatically populate a bunch of infrastructure records that
        //   we would never override (makes the error checks pass cleaner)
        else if( (0 == memcmp( i_record, VPD_HEADER_RECORD_NAME, 4 ))
                 || (0 == memcmp( i_record, VPD_TABLE_OF_CONTENTS_RECORD_NAME, 4 )) )
        {
            iv_overridePtr[l_recTarg] = nullptr;
        }
        else
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::fetchData: "
                       "iv_overridePtr is not set as expected for %s on %.8X",
                       i_record, TARGETING::get_huid(i_target) );
            for( auto l_over : iv_overridePtr )
            {
                TRACFCOMP( g_trac_vpd, "%.8X : %.8X = %p",
                           TARGETING::get_huid((l_over.first).second),
                           (l_over.first).first,
                           l_over.second );
            }
            assert( false,
                    "iv_overridePtr is not set inside IpVpdFacade::fetchData" );
        }
        mutex_unlock(&iv_mutex);
    }

    // Get the data
    if ( (vpdSource == VPD::PNOR) && !l_foundOverride )
    {
        err = fetchDataFromPnor( i_byteAddr, i_numBytes, o_data, i_target );
    }
    else if ( (vpdSource == VPD::SEEPROM) && !l_foundOverride )
    {
        err = fetchDataFromEeprom(i_byteAddr,
                                  i_numBytes,
                                  o_data,
                                  i_target,
                                  i_args.eepromSource);
    }
    else
    {
        configError = true;
    }

    if( configError && !l_foundOverride  )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::fetchData: "
                   "Error resolving VPD source (PNOR/SEEPROM)");

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_READ_SOURCE_UNRESOLVED
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FETCH_DATA
         * @userdata1[0:31]  Target HUID
         * @userdata1[32:63] Requested VPD Source Location
         * @userdata2[0:31]  VPD read PNOR flag
         * @userdata2[32:63] VPD read HW flag
         * @devdesc          Unable to resolve the VPD
         *                   source (PNOR or SEEPROM)
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FETCH_DATA,
                                       VPD::VPD_READ_SOURCE_UNRESOLVED,
                                       TWO_UINT32_TO_UINT64(
                                            TARGETING::get_huid(i_target),
                                            i_args.location ),
                                       TWO_UINT32_TO_UINT64(
                                            iv_configInfo.vpdReadPNOR,
                                            iv_configInfo.vpdReadHW ),
                                       true /*Add HB SW Callout*/ );
        err->collectTrace( VPD_COMP_NAME, 256 );
    }

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::fetchDataFromPnor
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::fetchDataFromPnor ( uint64_t i_byteAddr,
                                            size_t i_numBytes,
                                            void * o_data,
                                            TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;
    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::fetchDataFromPnor(%ld, %d, . . .)",
                i_byteAddr,
                i_numBytes );
    do
    {
#ifndef __HOSTBOOT_RUNTIME
        // Call a function in the common VPD code
        VPD::pnorInformation info;
        info.segmentSize = iv_vpdSectionSize;
        info.maxSegments = iv_vpdMaxSections;
        info.pnorSection = iv_pnorSection;
        err = VPD::readPNOR( i_byteAddr,
                             i_numBytes,
                             o_data,
                             i_target,
                             info,
                             iv_cachePnorAddr,
                             &iv_mutex );

        if( err )
        {
            break;
        }
#else
        assert( false, "IpVpdFacade::fetchDataFromPnor> No PNOR support in HBRT" );
#endif

    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::fetchDataFromPnor()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::fetchDataFromEeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::fetchDataFromEeprom(uint64_t i_byteAddr,
                                           size_t i_numBytes,
                                           void * o_data,
                                           TARGETING::Target * i_target,
                                           EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err = NULL;
    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::fetchDataFromEeprom(%ld, %d, 0x%.8X . . .)",
                i_byteAddr,
                i_numBytes,
                TARGETING::get_huid(i_target) );

    do
    {
        // Need to read directly from target's EEPROM.
        TRACSSCOMP( g_trac_vpd, "IpVpdFacade::fetchDataFromEeprom -> deviceOp(DEVICE_EEPROM_ADDRESS(VPD_AUTO, %d, %d)",
          i_byteAddr, i_eepromSource );
        err = DeviceFW::deviceOp( DeviceFW::READ,
                                  i_target,
                                  o_data,
                                  i_numBytes,
                                  DEVICE_EEPROM_ADDRESS(
                                      EEPROM::VPD_AUTO,
                                      i_byteAddr,
                                      i_eepromSource ) );
        if( err )
        {
            TRACSSCOMP( g_trac_vpd,
                ERR_MRK"IpVpdFacade::fetchDataFromEeprom(%ld, %d, 0x%.8X . . .) failed, err rc=0x%X, plid=0x%X",
                i_byteAddr,
                i_numBytes,
                TARGETING::get_huid(i_target),
                ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err) );
            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::fetchDataFromEeprom()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::findKeywordAddr
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findKeywordAddr ( const char * i_keywordName,
                                          const char * i_recordName,
                                          uint16_t i_offset,
                                          uint16_t i_index,
                                          TARGETING::Target * i_target,
                                          size_t& o_keywordSize,
                                          uint64_t& o_byteAddr,
                                          input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint16_t offset = i_offset;
    uint16_t recordSize = 0x0;
    uint16_t keywordSize = 0x0;
    char record[RECORD_BYTE_SIZE] = { '\0' };
    char keyword[KEYWORD_BYTE_SIZE] = { '\0' };
    int matchesFound = 0;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::findKeywordAddr(%s, %s, %d, %d, %.8X )",
                i_keywordName,
                i_recordName,
                i_offset,
                i_index,
                TARGETING::get_huid(i_target) );

    do
    {
        // Read size of Record
        err = fetchData( offset,
                         RECORD_ADDR_BYTE_SIZE,
                         &recordSize,
                         i_target,
                         i_args.location,
                         i_recordName );
        offset += RECORD_ADDR_BYTE_SIZE;
        if( err )
        {
            break;
        }

        // Byte Swap
        recordSize = le16toh( recordSize );

        // Skip 3 bytes - RT
        // Read 4 bytes ( Record name ) - compare with expected
        offset += RT_SKIP_BYTES;
        err = fetchData( offset,
                         RECORD_BYTE_SIZE,
                         record,
                         i_target,
                         i_args.location,
                         i_recordName );

        // If we were looking for the Record Type (RT) keyword, we are done.
        if (memcmp( i_keywordName, "RT", KEYWORD_BYTE_SIZE ) == 0) {
            // send back the relevant data
            o_keywordSize = RECORD_BYTE_SIZE;
            o_byteAddr = offset - i_offset; //make address relative

            // found our match, break out
            matchesFound++;
            if ( matchesFound == i_index + 1 ) {
                break;
            }
        }

        offset += RECORD_BYTE_SIZE;

        if( err )
        {
            break;
        }

        if( memcmp( record, i_recordName, RECORD_BYTE_SIZE ) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::findKeywordAddr: "
                       "Record(%s) for offset (0x%04x->0x%04x) did not match "
                       "expected record(%s)!",
                       record,
                       i_offset,
                       offset,
                       i_recordName );

            // convert data for SRC display
            uint32_t exp_rec;
            memcpy( &exp_rec, i_recordName, RECORD_BYTE_SIZE );
            uint32_t act_rec;
            memcpy( &act_rec, record, RECORD_BYTE_SIZE );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_RECORD_MISMATCH
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_FIND_KEYWORD_ADDR
             * @userdata1[00:31] Current offset into VPD
             * @userdata1[32:63] Start of Record offset
             * @userdata2[00:31] Expected record name
             * @userdata2[32:63] Found record name
             * @devdesc          Record name does not match value expected for
             *                   offset read.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_FIND_KEYWORD_ADDR,
                                           VPD::VPD_RECORD_MISMATCH,
                                           TWO_UINT32_TO_UINT64(offset,
                                                                i_offset ),
                                           TWO_UINT32_TO_UINT64(exp_rec,
                                                                act_rec) );

            // Could be the VPD of the target wasn't set up properly
            // -- DECONFIG so that we can possibly keep booting
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL );

            // Or FSP code didn't set up the VPD properly
            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_MED);

            // Or HB code didn't look for the record properly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            // Add trace so we see what record was being compared
            err->collectTrace( VPD_COMP_NAME, 256 );

            break;
        }

        // While size < size of record
        // Size of record is the input offset, plus the record size, plus
        // 2 bytes for the size value.
        while( ( offset < (recordSize + i_offset + RECORD_ADDR_BYTE_SIZE) ) )
        {
            TRACDCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::findKeywordAddr: "
                       "Looking for keyword, reading offset: 0x%04x",
                       offset );

            // read keyword name (2 bytes)
            err = fetchData( offset,
                             KEYWORD_BYTE_SIZE,
                             keyword,
                             i_target,
                             i_args.location,
                             i_recordName );
            offset += KEYWORD_BYTE_SIZE;

            if( err )
            {
                break;
            }

            TRACDCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::findKeywordAddr: "
                       "Read keyword name: %s",
                       keyword );

            // Check if we're reading a '#' keyword.  They have a 2 byte size
            uint32_t keywordLength = KEYWORD_SIZE_BYTE_SIZE;
            bool isPoundKwd = false;
            if( !(memcmp( keyword, "#", 1 )) )
            {
                TRACDCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::findKeywordAddr: "
                           "Reading # keyword, adding 1 byte to size to read!");
                isPoundKwd = true;
                keywordLength++;
            }

            // Read keyword size
            err = fetchData( offset,
                             keywordLength,
                             &keywordSize,
                             i_target,
                             i_args.location,
                             i_recordName );
            offset += keywordLength;

            if( err )
            {
                break;
            }

            if( isPoundKwd )
            {
                // Swap it since 2 byte sizes are byte swapped.
                keywordSize = le16toh( keywordSize );
            }
            else
            {
                keywordSize = keywordSize >> 8;
            }

            TRACDCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::findKeywordAddr: "
                       "Read keyword size: 0x%04x",
                       keywordSize );

            // if keyword equal i_keywordName
            if( !(memcmp( keyword, i_keywordName, KEYWORD_BYTE_SIZE ) ) )
            {
                // send back the relevant data
                o_keywordSize = keywordSize;
                o_byteAddr = offset - i_offset; //make address relative

                // found our match, break out
                matchesFound++;
                if ( matchesFound == i_index + 1 ) {
                    break;
                }
                // set offset to next keyword (based on current keyword size)
                offset += keywordSize;
            }
            else
            {
                // set offset to next keyword (based on current keyword size)
                offset += keywordSize;
            }
        }

        if( err ||
            matchesFound == i_index + 1 )
        {
            break;
        }
    } while( 0 );

    // If keyword not found in expected Record, flag error.
    if( matchesFound != i_index + 1 &&
        NULL == err )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::findKeywordAddr: "
                   "No matching %s keyword found within %s record!",
                   i_keywordName,
                   i_recordName );

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_KEYWORD_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FIND_KEYWORD_ADDR
         * @userdata1[0:31]  Start of Record Offset
         * @userdata1[32:63] Keyword Index
         * @userdata2[0:31]  Requested Record
         * @userdata2[32:63] Requested Keyword
         * @devdesc          Keyword was not found in Record starting at given
         *                   offset.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FIND_KEYWORD_ADDR,
                                       VPD::VPD_KEYWORD_NOT_FOUND,
                                       TWO_UINT32_TO_UINT64( i_offset,
                                                             i_index ),
                                       TWO_UINT32_TO_UINT64( i_args.record,
                                                             i_args.keyword ) );

        // Could be the VPD of the target wasn't set up properly
        // -- DECONFIG so that we can possibly keep booting
        err->addHwCallout( i_target,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::DECONFIG,
                           HWAS::GARD_NULL );

        // Or FSP code didn't set up the VPD properly
        err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                 HWAS::SRCI_PRIORITY_MED);

        // Or HB code didn't look for the record properly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_LOW);

        // Add trace so we know what Record/Keyword was missing
        err->collectTrace( VPD_COMP_NAME, 256 );
    }

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findKeywordAddr()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::writeKeyword
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::writeKeyword ( const char * i_keywordName,
                                       const char * i_recordName,
                                       uint16_t i_offset,
                                       TARGETING::Target * i_target,
                                       void * i_buffer,
                                       size_t & i_buflen,
                                       input_args_t i_args )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::writeKeyword()" );

    do
    {
        // Note, there is no way to tell if a keyword is writable without
        //  hardcoding it so we will just assume that the callers know
        //  what they are doing

        // First go find the keyword in memory
        size_t keywordSize = 0x0;
        uint64_t byteAddr = 0x0;
        err = findKeywordAddr( i_keywordName,
                               i_recordName,
                               i_offset,
                               0,
                               i_target,
                               keywordSize,
                               byteAddr,
                               i_args );
        if( err )
        {
            break;
        }

        // check size of usr buffer with io_buflen
        err = checkBufferSize( i_buflen,
                               keywordSize,
                               i_target );
        if( err )
        {
            break;
        }

        // Determine the VPD destination (PNOR/SEEPROM)
        VPD::vpdCmdTarget vpdDest = VPD::AUTOSELECT;
        bool configError = false;
        configError = VPD::resolveVpdSource( i_target,
                                             iv_configInfo.vpdWritePNOR,
                                             iv_configInfo.vpdWriteHW,
                                             i_args.location,
                                             vpdDest );

        // Look for a record override in our image unless explicitly told not to
        if( (i_args.location & VPD::OVERRIDE_MASK) != VPD::USEVPD )
        {
            uint8_t* l_overridePtr = nullptr;
            VPD::RecordTargetPair_t l_recTarg
              = VPD::makeRecordTargetPair(i_recordName,i_target);

            // At this point we can assume that the pointer is set into our
            //  map if we need it
            mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
            VPD::OverrideMap_t::iterator l_overItr = iv_overridePtr.find(l_recTarg);
            if( l_overItr != iv_overridePtr.end() )
            {
                l_overridePtr = l_overItr->second;

                // If we are using an override, we can't write to it
                if( l_overridePtr != nullptr )
                {
                    uint32_t l_kw = 0;
                    memcpy( &l_kw, i_keywordName, KEYWORD_BYTE_SIZE );
                    /*@
                     * @errortype
                     * @reasoncode       VPD::VPD_CANNOT_WRITE_OVERRIDDEN_VPD
                     * @moduleid         VPD::VPD_IPVPD_WRITE_KEYWORD
                     * @userdata1[0:31]  Target HUID
                     * @userdata1[32:63] <unused>
                     * @userdata2[0:31]  VPD Record (ASCII)
                     * @userdata2[32:63] VPD Keyword (ASCII)
                     * @devdesc          Attempting to write to a VPD record
                     *                   that has been overridden by firmware
                     * @custdesc         Firmware error writing VPD
                     */
                    err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              VPD::VPD_IPVPD_WRITE_KEYWORD,
                              VPD::VPD_WRITE_DEST_UNRESOLVED,
                              TWO_UINT32_TO_UINT64(
                                        TARGETING::get_huid(i_target),
                                        0 ),
                              TWO_UINT32_TO_UINT64(
                                        l_recTarg.first,
                                        l_kw),
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
                    err->collectTrace( VPD_COMP_NAME, 256 );

                    mutex_unlock(&iv_mutex);

                    break;
                }
            }
            mutex_unlock(&iv_mutex);
        }

        // Write the data
        if ( vpdDest == VPD::PNOR )
        {
#ifndef __HOSTBOOT_RUNTIME
            // Setup info needed to write to PNOR
            VPD::pnorInformation info;
            info.segmentSize = iv_vpdSectionSize;
            info.maxSegments = iv_vpdMaxSections;
            info.pnorSection = iv_pnorSection;

            err = VPD::writePNOR( i_offset+byteAddr,
                                  keywordSize,
                                  i_buffer,
                                  i_target,
                                  info,
                                  iv_cachePnorAddr,
                                  &iv_mutex );
            if( err )
            {
                break;
            }

            VPD::VpdWriteMsg_t msgdata;

            // Quick double-check that our constants agree with the values
            //  in the VPD message structure
            assert( sizeof(msgdata.record) == RECORD_BYTE_SIZE );
            assert( sizeof(msgdata.keyword) == KEYWORD_BYTE_SIZE );

            // Finally, send it down to the FSP
            msgdata.rec_num = i_target->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
            memcpy( msgdata.record, i_recordName, RECORD_BYTE_SIZE );
            memcpy( msgdata.keyword, i_keywordName, KEYWORD_BYTE_SIZE );
            err = VPD::sendMboxWriteMsg( keywordSize,
                                         i_buffer,
                                         i_target,
                                         iv_vpdMsgType,
                                         msgdata );
            if( err )
            {
                break;
            }
#else
            assert( false, "IpVpdFacade::writeKeyword> No PNOR support in HBRT" );
#endif
        }
        else if ( vpdDest == VPD::SEEPROM )
        {
            // Write directly to target's EEPROM.
            err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                      i_target,
                                      i_buffer,
                                      keywordSize,
                                      DEVICE_EEPROM_ADDRESS(
                                          EEPROM::VPD_AUTO,
                                          i_offset+byteAddr,
                                          EEPROM::AUTOSELECT) );
            if( err )
            {
                break;
            }
        }
        else
        {
            configError = true;
        }

        if( configError )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::writeKeyword: "
                       "Error resolving VPD source (PNOR/SEEPROM)");

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_WRITE_DEST_UNRESOLVED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_WRITE_KEYWORD
             * @userdata1[0:31]  Target HUID
             * @userdata1[32:63] Requested VPD Destination
             * @userdata2[0:31]  VPD write PNOR flag
             * @userdata2[32:63] VPD write HW flag
             * @devdesc          Unable to resolve the VPD
             *                   destination (PNOR or SEEPROM)
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_WRITE_KEYWORD,
                                           VPD::VPD_WRITE_DEST_UNRESOLVED,
                                           TWO_UINT32_TO_UINT64(
                                                TARGETING::get_huid(i_target),
                                                i_args.location ),
                                           TWO_UINT32_TO_UINT64(
                                                iv_configInfo.vpdWritePNOR,
                                                iv_configInfo.vpdWriteHW ),
                                           true /*Add HB SW Callout*/ );
            err->collectTrace( VPD_COMP_NAME, 256 );
        }
    } while(0);

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::writeKeyword()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::checkBufferSize
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::checkBufferSize( size_t i_bufferSize,
                                         size_t i_expectedSize,
                                         TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    if( !(i_bufferSize >= i_expectedSize) )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkBufferSize: "
                   "Buffer size (%d) is not larger than expected size (%d)",
                   i_bufferSize,
                   i_expectedSize );

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_INSUFFICIENT_BUFFER_SIZE
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_CHECK_BUFFER_SIZE
         * @userdata1        Buffer Size
         * @userdata2        Expected Buffer Size
         * @devdesc          Buffer size was not greater than or equal to
         *                   expected buffer size.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_CHECK_BUFFER_SIZE,
                                       VPD::VPD_INSUFFICIENT_BUFFER_SIZE,
                                       i_bufferSize,
                                       i_expectedSize );

        // Could be the VPD of the target wasn't set up properly
        // -- DECONFIG so that we can possibly keep booting
        err->addHwCallout( i_target,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::DECONFIG,
                           HWAS::GARD_NULL );

        // Or FSP code didn't set up the VPD properly
        err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                 HWAS::SRCI_PRIORITY_MED);

        // Or HB code didn't look for the record properly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_LOW);

        err->collectTrace( VPD_COMP_NAME, 256 );

    }

    return err;
}


// ------------------------------------------------------------------
// IpVpdFacade::compareRecords
// ------------------------------------------------------------------
bool IpVpdFacade::compareRecords ( const recordInfo e1,
                                   const recordInfo e2 )
{
    if( e2.record > e1.record )
        return true;
    else
        return false;
}


// ------------------------------------------------------------------
// IpVpdFacade::compareKeywords
// ------------------------------------------------------------------
bool IpVpdFacade::compareKeywords ( const keywordInfo e1,
                                    const keywordInfo e2 )
{
    if( e2.keyword > e1.keyword )
        return true;
    else
        return false;
}


// ------------------------------------------------------------------
// IpVpdFacade::setConfigFlagsHW
// ------------------------------------------------------------------
void IpVpdFacade::setConfigFlagsHW ( )
{
    // Only change configs if in PNOR caching mode
    if( iv_configInfo.vpdReadPNOR &&
        iv_configInfo.vpdReadHW )
    {
        iv_configInfo.vpdReadPNOR = false;
        iv_configInfo.vpdReadHW = true;
    }
    if( iv_configInfo.vpdWritePNOR &&
        iv_configInfo.vpdWriteHW )
    {
        iv_configInfo.vpdWritePNOR = false;
        iv_configInfo.vpdWriteHW = true;
    }
}

// Return the lists of records that should be copied to pnor.
// The default lists to use are this object's record list and size.
// No Alternate.
void IpVpdFacade::getRecordLists(
                const  recordInfo* & o_primaryVpdRecords,
                uint64_t           & o_primaryRecSize,
                const  recordInfo* & o_altVpdRecords,
                uint64_t           & o_altRecSize)
{
    o_primaryVpdRecords = iv_vpdRecords;
    o_primaryRecSize = iv_recSize;
    o_altVpdRecords = NULL;
    o_altRecSize = 0;
}

/**
 * @brief Callback function to check for a record override
 */
errlHndl_t IpVpdFacade::checkForRecordOverride( const char* i_record,
                                                TARGETING::Target* i_target,
                                                uint8_t*& o_ptr )
{
    // by default there is not an override
    o_ptr = nullptr;
    TRACDCOMP( g_trac_vpd, "No override for %s on %.8X", i_record, TARGETING::get_huid(i_target) );
    VPD::RecordTargetPair_t l_recTarg =
      VPD::makeRecordTargetPair(i_record,i_target);
    mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
    iv_overridePtr[l_recTarg] = nullptr;
    mutex_unlock(&iv_mutex);
    return nullptr;
}

#ifdef CONFIG_SECUREBOOT
/**
 * @brief Load/unload the appropriate secure section for
 *        an overriden PNOR section
 */
errlHndl_t IpVpdFacade::loadUnloadSecureSection( input_args_t i_args,
                                                 TARGETING::Target* i_target,
                                                 bool i_load,
                                                 bool& o_loaded )
{
    // nothing to do by default
    o_loaded = false;
    return nullptr;
}
#endif


// ------------------------------------------------------------------
// IpVpdFacade::getVtocRecordMetaData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::getVtocRecordMetaData ( TARGETING::Target*       i_target,
                                     const input_args_t      &i_args,
                                     pt_entry                &o_ptEntry,
                                     const vhdr_record* const i_vhdrFullRecordData )
{
    errlHndl_t l_err(nullptr);

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::getVtocRecordMetaData() "
                "for target 0x%.8X", TARGETING::get_huid(i_target) );

    // Clear the outgoing data
    memset(&o_ptEntry, 0, sizeof(o_ptEntry));

    do
    {
        // If the VHDR record is provided, then extract the VTOC meta data from it
        if (unlikely(nullptr != i_vhdrFullRecordData))
        {
            // Copy the VTOC meta data for caller
            memcpy( &(o_ptEntry.record_name),
                    &(i_vhdrFullRecordData->pt_kw_vtoc_name),
                    RECORD_BYTE_SIZE);
            o_ptEntry.record_type   = i_vhdrFullRecordData->pt_kw_vtoc_type;
            o_ptEntry.record_offset = i_vhdrFullRecordData->pt_kw_vtoc_off;
            o_ptEntry.record_length = i_vhdrFullRecordData->pt_kw_vtoc_len;
            o_ptEntry.ecc_offset    = i_vhdrFullRecordData->pt_kw_vtoc_ecc_off;
            o_ptEntry.ecc_length    = i_vhdrFullRecordData->pt_kw_vtoc_ecc_len;
        }
        // Need to get the PT keyword from the VHDR record to get the VTOC meta data
        else
        {
            // Considering that the struct vhdr_record contains the VTOC meta data
            // as a data member, then a buffer size equal to the size of the
            // struct vhdr_record should be sufficient to gather the VTOC meta data.
            size_t   l_bufferSize(sizeof(vhdr_record));
            char     l_buffer[l_bufferSize] = { 0 };

            // Skip the ECC data + large resource ID in the VHDR record
            uint16_t l_offset(VHDR_ECC_DATA_SIZE + RESOURCE_ID_SIZE);

            // Read PT (Pointer to Record) keyword from VHDR to find the VTOC.
            l_err = retrieveKeyword( VPD_KEYWORD_POINTER_TO_RECORD, VPD_HEADER_RECORD_NAME,
                                     l_offset, 0, i_target, l_buffer, l_bufferSize, i_args );
            if (l_err)
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData: "
                           "Error with getting PT (Pointer to Record) keyword "
                           "from VHDR record for target 0x%.8X",
                           TARGETING::get_huid(i_target) );
                break;
            }

            TRACSSCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData: "
                        "Success with getting PT (Pointer to Record) keyword "
                        "from VHDR record for target 0x%.8X",
                        TARGETING::get_huid(i_target) );

            pt_entry *l_tocRecord = reinterpret_cast<pt_entry*>(l_buffer);
            if (l_bufferSize < sizeof(pt_entry)       ||
                (memcmp(l_tocRecord->record_name, VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                        RECORD_BYTE_SIZE) != 0))
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData: "
                           "The VPD Header (VHDR) record is invalid for "
                           "target 0x%.8X!", TARGETING::get_huid(i_target) );

                /*@
                 * @errortype
                 * @reasoncode       VPD::VPD_RECORD_INVALID_VHDR
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         VPD::VPD_IPVPD_GET_VTOC_RECORD_META_DATA
                 * @userdata1        VHDR length
                 * @userdata2        Target HUID
                 * @devdesc          The VHDR was invalid
                 * @custdesc         Firmware error reading VPD
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    VPD::VPD_IPVPD_GET_VTOC_RECORD_META_DATA,
                                    VPD::VPD_RECORD_INVALID_VHDR,
                                    l_bufferSize,
                                    TARGETING::get_huid(i_target) );

                // Could be the VPD of the target wasn't set up properly
                // -- DECONFIG so that we can possibly keep booting
                l_err->addHwCallout( i_target,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::DECONFIG,
                                   HWAS::GARD_NULL );

                // Or HB code didn't look for the record properly
                l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                l_err->collectTrace( VPD_COMP_NAME );
                break;
            }

            // Copy the VTOC meta data for caller
            memcpy(&(o_ptEntry.record_name), l_tocRecord->record_name,  RECORD_BYTE_SIZE);
            o_ptEntry.record_type   = l_tocRecord->record_type;
            o_ptEntry.record_offset = l_tocRecord->record_offset;
            o_ptEntry.record_length = l_tocRecord->record_length;
            o_ptEntry.ecc_offset    = l_tocRecord->ecc_offset;
            o_ptEntry.ecc_length    = l_tocRecord->ecc_length;
        }
    } while (0);


    if (!l_err)
    {
        TRACSSCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData: "
                    "Successfully retrieved VTOC meta data: record name(%s), "
                    "record type(0x%.4X), record offset(0x%.4X), record length(%d) "
                    "ecc offset(0x%.4X) and ecc length(%d) for target 0x%.8X",
                    o_ptEntry.record_name, le16toh(o_ptEntry.record_type),
                    le16toh(o_ptEntry.record_offset), le16toh(o_ptEntry.record_length),
                    le16toh(o_ptEntry.ecc_offset), le16toh(o_ptEntry.ecc_length),
                    TARGETING::get_huid(i_target) );
    }

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                "returning %s errors for target 0x%.8X",
                (l_err ? "with" : "with no"), TARGETING::get_huid(i_target));

    return l_err;
}


