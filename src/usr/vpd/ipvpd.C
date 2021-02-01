/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ipvpd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <targeting/common/attributes.H>

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

// Return codes for the vpdeccCreateEcc and vpdeccCheckData methods
enum VPD_ECC_RC: size_t
{
    VPD_ECC_OK                 = 0,
    VPD_ECC_NOT_ENOUGH_BUFFER  = 1,
    VPD_ECC_WRONG_ECC_SIZE     = 2,
    VPD_ECC_WRONG_BUFFER_SIZE  = 9,
    VPD_ECC_UNCORRECTABLE_DATA = 90,
    VPD_ECC_CORRECTABLE_DATA   = 91,
};

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
    errlHndl_t err = nullptr;
    const char * recordName = nullptr;
    const char * keywordName = nullptr;
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
    if ( err != nullptr )
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
    errlHndl_t err = nullptr;
    const char * recordName = nullptr;
    const char * keywordName = nullptr;
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
        }
    } while( 0 );

    // If there is an error, add parameter info to log
    if ( err != nullptr )
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
    errlHndl_t l_err = nullptr;

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
                      nullptr,
                      l_sizePnor,
                      l_pnorArgs );
        if( l_err || (l_sizePnor == 0) )
        {
            // PNOR may not be loaded, ignore the error
            delete l_err;
            l_err = nullptr;
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
                      nullptr,
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
    errlHndl_t l_err = nullptr;

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
                      nullptr,
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
    errlHndl_t err = nullptr;

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
            TRACFCOMP(g_trac_vpd,"IpVpdFacade::loadPnor()> The amount of "
                                 "space required (0x%X) for the VPD cache "
                                 "exceeds the available space (0x%X)",
                                  pRecOffset + sRecLength,
                                  iv_vpdSectionSize );
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
        errlHndl_t invErr = nullptr;
        invErr = invalidatePnor( i_target );
        if( invErr )
        {
            TRACFCOMP(g_trac_vpd,"IpVpdFacade::loadPnor() "
                      "Error invalidating PNOR Target %.8X",
                      TARGETING::get_huid(i_target));
            delete invErr;
            invErr = nullptr;
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
    errlHndl_t err = nullptr;

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
    errlHndl_t err = nullptr;

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
                   "IpVpdFacade::translateRecord: record name: %s",
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
    errlHndl_t err = nullptr;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::translateKeyword(i_keyword=0x%.8X)",
                i_keyword );

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
// IpVpdFacade::recordStringtoEnum
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::recordStringtoEnum ( const char * i_record,
                                             VPD::vpdRecord & o_record )
{
    errlHndl_t err = nullptr;
    o_record = IPVPD::INVALID_RECORD;

    assert(i_record != nullptr, "IpVpdFacade::recordStringtoEnum i_record is nullptr");

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::recordStringtoEnum(i_record = %s)",
                i_record );

    do
    {

        uint64_t i = 0;
        for(; i < iv_recSize; i++)
        {
            if(compareRecordNames(iv_vpdRecords[i].recordName, i_record))
            {
                break;
            }
        }

        if(i >= iv_recSize)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::recordStringtoEnum: "
                       "No matching Record enum found for %s!",
                       i_record );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_RECORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_RECORD_STRING_TO_ENUM
             * @userdata1        Record string.
             * @userdata2        <UNUSED>
             * @devdesc          The record string did not have a
             *                   corresponding enumeration value.
             * @custdesc         VPD lookup error
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_RECORD_STRING_TO_ENUM,
                                           VPD::VPD_RECORD_NOT_FOUND,
                                           *(reinterpret_cast<const uint64_t *>(i_record)),
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( VPD_COMP_NAME, 256 );
            break;
        }

        o_record = iv_vpdRecords[i].record;
        TRACDCOMP( g_trac_vpd, "record: 0x%.8X",
                   iv_vpdRecords[i].record);
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::recordStringtoEnum()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::keywordStringtoEnum
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::keywordStringtoEnum ( const char * i_keyword,
                                              VPD::vpdKeyword & o_keyword )
{
    errlHndl_t err = nullptr;
    o_keyword = IPVPD::INVALID_KEYWORD;

    assert(i_keyword != nullptr, "IpVpdFacade::keywordStringtoEnum i_keyword is nullptr");

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::keywordStringtoEnum(i_keyword = %s)",
                i_keyword );

    do
    {

        uint64_t i = 0;
        for(; i < iv_recSize; i++)
        {
            if(compareKeywordNames(iv_vpdKeywords[i].keywordName, i_keyword))
            {
                break;
            }
        }

        if(i >= iv_recSize)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::keywordStringtoEnum: "
                       "No matching Keyword enum found for %s!",
                       i_keyword );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_KEYWORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_KEYWORD_STRING_TO_ENUM
             * @userdata1        Keyword string.
             * @userdata2        <UNUSED>
             * @devdesc          The keyword string did not have a
             *                   corresponding enumeration value.
             * @custdesc         VPD lookup error
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_KEYWORD_STRING_TO_ENUM,
                                           VPD::VPD_KEYWORD_NOT_FOUND,
                                           *(reinterpret_cast<const uint64_t *>(i_keyword)),
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( VPD_COMP_NAME, 256 );
            break;
        }

        o_keyword = iv_vpdKeywords[i].keyword;
        TRACDCOMP( g_trac_vpd, "keyword: 0x%.8X",
                   iv_vpdKeywords[i].keyword);
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::keywordStringtoEnum()" );

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
    errlHndl_t err = nullptr;

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
    errlHndl_t err = nullptr;
    uint16_t recordOffset = 0x0;
    input_args_t i_args;
    bool vpdPresent = false;
    const char * l_recordName = nullptr;
    const char * l_keywordName = nullptr;

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
    errlHndl_t err = nullptr;
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
    errlHndl_t err = nullptr;
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
    errlHndl_t err = nullptr;

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
    const  recordInfo* l_primaryVpdRecords = nullptr;
    uint64_t           l_primaryRecSize = 0;
    const  recordInfo* l_altVpdRecords = nullptr;
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
                err = nullptr;
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
    errlHndl_t err = nullptr;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::retrieveKeyword(%s, %s, . . .)",
                i_keywordName,
                i_recordName );

    do
    {
        // First go find the keyword in memory
        size_t keywordSize = 0x0;
        uint16_t byteAddr = 0x0;
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

        // If the buffer is nullptr, return the keyword size in io_buflen
        if( nullptr == io_buffer )
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
    errlHndl_t err = nullptr;
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

        // If the buffer is nullptr, return the keyword size in io_buflen
        if( nullptr == io_buffer )
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
    errlHndl_t err = nullptr;

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
    errlHndl_t err = nullptr;
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
    errlHndl_t err = nullptr;
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
                                          uint16_t i_recordOffset,
                                          uint16_t i_index,
                                          TARGETING::Target * i_target,
                                          size_t& o_keywordSize,
                                          uint16_t& o_keywordOffset,
                                          input_args_t i_args )
{
    errlHndl_t err = nullptr;
    uint16_t offset = i_recordOffset;
    uint16_t recordSize = 0x0;
    uint16_t keywordSize = 0x0;
    char record[RECORD_BYTE_SIZE] = { '\0' };
    char keyword[KEYWORD_BYTE_SIZE] = { '\0' };
    int matchesFound = 0;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::findKeywordAddr(%s, %s, %d, %d, %.8X )",
                i_keywordName,
                i_recordName,
                i_recordOffset,
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
            o_keywordOffset = offset - i_recordOffset; //make address relative

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
                       i_recordOffset,
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
                                                                i_recordOffset ),
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
        while( ( offset < (recordSize + i_recordOffset + RECORD_ADDR_BYTE_SIZE) ) )
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
                o_keywordOffset = offset - i_recordOffset; // make keyword address
                                                           // relative to the record
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
        nullptr == err )
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
                                       TWO_UINT32_TO_UINT64( i_recordOffset,
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
                                       uint16_t i_recordOffset,
                                       TARGETING::Target * i_target,
                                       void * i_buffer,
                                       size_t & i_buflen,
                                       input_args_t i_args )
{
    errlHndl_t err = nullptr;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::writeKeyword()" );

    do
    {
        // Note, there is no way to tell if a keyword is writable without
        //  hardcoding it so we will just assume that the callers know
        //  what they are doing

        // First go find the keyword in memory
        size_t keywordSize = 0x0;
        uint16_t keywordOffset = 0x0;
        err = findKeywordAddr( i_keywordName,
                               i_recordName,
                               i_recordOffset,
                               0,
                               i_target,
                               keywordSize,
                               keywordOffset,
                               i_args );
        if( err )
        {
            break;
        }

        // check size of usr i_buffer with keywordSize
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

            err = VPD::writePNOR( i_recordOffset+keywordOffset,
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

            msgdata.offset = i_recordOffset+keywordOffset;

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

#ifdef __HOSTBOOT_RUNTIME
            // In general, all writes to MVPD during HBRT are not allowed.
            // However, allow sbeApplyVpdOverrides() to write to only MVPD CACHE
            // if the writes to FSP and HW are disabled
            if(EEPROM::allowVPDOverrides())
            {
#endif

            // Write directly to target's EEPROM.
            err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                      i_target,
                                      i_buffer,
                                      keywordSize,
                                      DEVICE_EEPROM_ADDRESS(
                                          EEPROM::VPD_AUTO,
                                          i_recordOffset+keywordOffset,
                                          EEPROM::AUTOSELECT) );
            if( err )
            {
                break;
            }
            VPD::VpdWriteMsg_t msgdata;

            msgdata.offset = i_recordOffset+keywordOffset;

            err = VPD::sendMboxWriteMsg( keywordSize,
                                         i_buffer,
                                         i_target,
                                         iv_vpdMsgType,
                                         msgdata );
            if( err )
            {
                break;
            }

#ifdef __HOSTBOOT_RUNTIME
            } // end if(EEPROM::allowVPDOverrides()
            else
            {

                TRACFCOMP(g_trac_vpd, ERR_MRK"IpVpdFacade::writeKeyword> No MVPD write support in HBRT");
                VPD::RecordTargetPair_t l_recTarg
                  = VPD::makeRecordTargetPair(i_recordName,i_target);
                uint32_t l_kw = 0;
                memcpy( &l_kw, i_keywordName, KEYWORD_BYTE_SIZE );
                /*@
                 * @errortype
                 * @reasoncode       VPD::VPD_WRITE_MVPD_UNSUPPORTED_HBRT
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         VPD::VPD_IPVPD_WRITE_KEYWORD
                 * @userdata1[0:31]  Target HUID
                 * @userdata1[32:63] Requested VPD Destination
                 * @userdata2[0:31]  VPD Record (ASCII)
                 * @userdata2[32:63] VPD Keyword (ASCII)
                 * @devdesc          No MVPD write support in HBRT
                 * @custdesc         Firmware error writing VPD
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               VPD::VPD_IPVPD_WRITE_KEYWORD,
                                               VPD::VPD_WRITE_MVPD_UNSUPPORTED_HBRT,
                                               TWO_UINT32_TO_UINT64(
                                                    TARGETING::get_huid(i_target),
                                                    i_args.location ),
                                               TWO_UINT32_TO_UINT64(
                                                    l_recTarg.first,
                                                    l_kw),
                                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
                err->collectTrace( VPD_COMP_NAME, 256 );
                break;

            }
#endif

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
    errlHndl_t err = nullptr;

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
    return ( e2.record > e1.record );
}


// ------------------------------------------------------------------
// IpVpdFacade::compareKeywords
// ------------------------------------------------------------------
bool IpVpdFacade::compareKeywords ( const keywordInfo e1,
                                    const keywordInfo e2 )
{
    return ( e2.keyword > e1.keyword );
}

// ------------------------------------------------------------------
// IpVpdFacade::compareRecordNames
// ------------------------------------------------------------------
bool IpVpdFacade::compareRecordNames ( const char * recordName1,
                                       const char * recordName2 )
{
    assert(recordName1 != nullptr, "IpVpdFacade::compareRecordNames recordName1 is nullptr");
    assert(recordName2 != nullptr, "IpVpdFacade::compareRecordNames recordName2 is nullptr");
    return (strncmp(recordName2, recordName1, RECORD_BYTE_SIZE) == 0);
}


// ------------------------------------------------------------------
// IpVpdFacade::compareKeywordNames
// ------------------------------------------------------------------
bool IpVpdFacade::compareKeywordNames ( const char * keywordName1,
                                        const char * keywordName2)
{
    assert(keywordName1 != nullptr, "IpVpdFacade::compareKeywordNames keywordName1 is nullptr");
    assert(keywordName2 != nullptr, "IpVpdFacade::compareKeywordNames keywordName2 is nullptr");

    return (strncmp(keywordName2, keywordName1, KEYWORD_BYTE_SIZE) == 0);
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
    o_altVpdRecords = nullptr;
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
// IpVpdFacade::updateRecordData
// ------------------------------------------------------------------
void
IpVpdFacade::updateRecordData( errlHndl_t &io_vpdValidationError,
                               const TARGETING::TargetHandle_t i_target,
                               const char *i_recordName,
                               uint8_t    *i_recordData,
                               size_t      i_recordOffset,
                               size_t      i_recordLength )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::updateRecordData(): "
                "target 0x%.8X, record name %s, record length %d, record offset 0x%.4X",
                TARGETING::get_huid(i_target), i_recordName, i_recordLength, i_recordOffset );

    // Write the record data
    errlHndl_t l_writeError = DeviceFW::deviceOp( DeviceFW::WRITE,
                                                  i_target,
                                                  i_recordData,
                                                  i_recordLength,
                                                  DEVICE_EEPROM_ADDRESS(
                                                      EEPROM::VPD_AUTO,
                                                      i_recordOffset,
                                                      EEPROM::AUTOSELECT) );
    if (l_writeError)
    {
        // Failed to write the updated record
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::updateRecordData(): "
                   "deviceOp write failed to update record %s on target 0x%.8X. "
                   "Setting the deviceOp write error to informational and the "
                   "VPD validation error to unrecoverable.",
                   i_recordName, TARGETING::get_huid(i_target) );

        // Set the failed write error as informational and commit.
        l_writeError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit(l_writeError, VPD_COMP_ID);

        // Set the original VPD validation error to unrecoverable and return it.
        io_vpdValidationError->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
    }
    else
    {
        // Successfully updated the record to be in sync with the ECC data
        TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::updateRecordData(): "
                   "deviceOp write successfully updated record %s on target 0x%.8X. "
                   "Setting the VPD validation error to informational.",
                   i_recordName, TARGETING::get_huid(i_target) );

        // Set original error to informational, commit and return as a nullptr.
        io_vpdValidationError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit(io_vpdValidationError, VPD_COMP_ID);
    } // if (l_writeError)

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::updateRecordData()");
} // updateRecordData

// ------------------------------------------------------------------
// IpVpdFacade::getVtocRecordMetaData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::getVtocRecordMetaData ( TARGETING::Target*       i_target,
                                     const input_args_t      &i_args,
                                     pt_entry                &o_vtocRecordMetaData,
                                     const vhdr_record* const i_vhdrFullRecordData )
{
    errlHndl_t l_err(nullptr);

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::getVtocRecordMetaData():"
                "for target 0x%.8X", TARGETING::get_huid(i_target) );

    // Clear the outgoing data
    memset(&o_vtocRecordMetaData, 0, sizeof(o_vtocRecordMetaData));

    do
    {
        // If the VHDR record is provided, then extract the VTOC meta data from it
        if (unlikely(nullptr != i_vhdrFullRecordData))
        {
            assert( 0 != i_vhdrFullRecordData->pt_kw_vtoc_ecc_len, "IpVpdFacade::"
                    "getVtocRecordMetaData(): The VHDR record data has not been properly initialized" );

            // Copy the VTOC meta data for caller
            memcpy( &(o_vtocRecordMetaData.record_name),
                    &(i_vhdrFullRecordData->pt_kw_vtoc_name),
                    RECORD_BYTE_SIZE);
            o_vtocRecordMetaData.record_type   = i_vhdrFullRecordData->pt_kw_vtoc_type;
            o_vtocRecordMetaData.record_offset = i_vhdrFullRecordData->pt_kw_vtoc_off;
            o_vtocRecordMetaData.record_length = i_vhdrFullRecordData->pt_kw_vtoc_len;
            o_vtocRecordMetaData.ecc_offset    = i_vhdrFullRecordData->pt_kw_vtoc_ecc_off;
            o_vtocRecordMetaData.ecc_length    = i_vhdrFullRecordData->pt_kw_vtoc_ecc_len;
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
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                           "Error with getting PT (Pointer to Record) keyword "
                           "from VHDR record for target 0x%.8X",
                           TARGETING::get_huid(i_target) );
                break;
            }

            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                        "Success with getting PT (Pointer to Record) keyword "
                        "from VHDR record for target 0x%.8X",
                        TARGETING::get_huid(i_target) );

            // Access the VTOC meta data from the buffer
            pt_entry *l_tocRecord = reinterpret_cast<pt_entry*>(l_buffer);

            // Verify that the returned buffer is large enough to contain the VTOC meta data
            if (l_bufferSize < sizeof(pt_entry))
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                           "The VPD Header (VHDR) record returned the VTOC meta data "
                           "of size %d, but expected size of %d or greater on "
                           "target 0x%.8X!", l_bufferSize, sizeof(pt_entry),
                           TARGETING::get_huid(i_target) );
                TRACFBIN( g_trac_vpd, "Returned record meta data:", l_buffer, l_bufferSize );

                /*@
                 * @errortype
                 * @reasoncode       VPD::VPD_SIZE_MISMATCH
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         VPD::VPD_IPVPD_GET_VTOC_RECORD_META_DATA
                 * @userdata1[0:31]  Returned buffer size
                 * @userdata1[32:63] Expected buffer size
                 * @userdata2        Target HUID
                 * @devdesc          Buffer size returned is insufficient to
                 *                   contain the VTOC meta data.
                 * @custdesc         Firmware error reading VPD
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    VPD::VPD_IPVPD_GET_VTOC_RECORD_META_DATA,
                                    VPD::VPD_SIZE_MISMATCH,
                                    TWO_UINT32_TO_UINT64( l_bufferSize,
                                                          sizeof(pt_entry) ),
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

            // Verify that indeed the returned meta data is the VTOC meta data
            if (memcmp(l_tocRecord->record_name, VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                        RECORD_BYTE_SIZE) != 0)
            {
                uint32_t* l_recordName = reinterpret_cast<uint32_t*>(l_tocRecord->record_name);
                const uint32_t* l_vtocRecord =
                          reinterpret_cast<const uint32_t*>(VPD_TABLE_OF_CONTENTS_RECORD_NAME);
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                           "The VPD Header (VHDR) record returned record name 0x%.8X, "
                           "but expected 0x%.8X (VTOC) for target 0x%.8X!",
                           l_recordName[0], l_vtocRecord[0], TARGETING::get_huid(i_target) );

                TRACFBIN( g_trac_vpd, "Returned record meta data:", l_buffer, l_bufferSize );

                /*@
                 * @errortype
                 * @reasoncode       VPD::VPD_INCORRECT_RECORD_RETURNED
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         VPD::VPD_IPVPD_GET_VTOC_RECORD_META_DATA
                 * @userdata1[0:31]  Returned record name
                 * @userdata1[32:63] Expected record name
                 * @userdata2        Target HUID
                 * @devdesc          Incorrect record returned, expected the VTOC record
                 * @custdesc         Firmware error reading VPD
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    VPD::VPD_IPVPD_GET_VTOC_RECORD_META_DATA,
                                    VPD::VPD_INCORRECT_RECORD_RETURNED,
                                    TWO_UINT32_TO_UINT64( l_recordName[0],
                                                          l_vtocRecord[0] ),
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
            o_vtocRecordMetaData = *l_tocRecord;
        }
    } while (0);

    if (!l_err)
    {
        TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                    "Successfully retrieved VTOC meta data: record name(%s), "
                    "record type(0x%.4X), record offset(0x%.4X), record length(%d) "
                    "ecc offset(0x%.4X) and ecc length(%d) for target 0x%.8X",
                    o_vtocRecordMetaData.record_name, le16toh(o_vtocRecordMetaData.record_type),
                    le16toh(o_vtocRecordMetaData.record_offset), le16toh(o_vtocRecordMetaData.record_length),
                    le16toh(o_vtocRecordMetaData.ecc_offset), le16toh(o_vtocRecordMetaData.ecc_length),
                    TARGETING::get_huid(i_target) );
    }

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::getVtocRecordMetaData(): "
                "returning %s errors for target 0x%.8X",
                (l_err ? "with" : "with no"), TARGETING::get_huid(i_target));

    return l_err;
} // getVtocRecordMetaData

// ------------------------------------------------------------------
// IpVpdFacade::updateRecordEccData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::updateRecordEccData ( const TARGETING::TargetHandle_t  i_target,
                                   const IpVpdFacade::input_args_t &i_args,
                                   const pt_entry                  *i_ptEntry )
{
    errlHndl_t  l_err(nullptr);

    // If the VPD ECC algorithms are present then execute code.
    if (true == g_vpd_ecc_api_present)
    {
        // Get a copy of the target huid, once, for tracing purposes
        auto l_targetHuid = TARGETING::get_huid(i_target);

        // Target needs to be a PROC
        assert(TARGETING::TYPE_PROC == i_target->getAttr<TARGETING::ATTR_TYPE>(),
               "IpVpdFacade::updateRecordEccData(): Target 0x%.8X is not a PROC",
               l_targetHuid );

        const char* l_recordName(nullptr);
        pt_entry l_ptEntry = {0};

        do
        {
            if (i_ptEntry)
            {
                TRACFCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::updateRecordEccData(): target(0x%.8X) "
                           "i_ptEntry (record meta data from caller) = record(%s), record offset"
                           "(0x%.4X), record length(0x%.4X), ECC offset(0x%.4X), ECC length(0x%.4X)",
                           l_targetHuid, i_ptEntry->record_name,
                           le16toh(i_ptEntry->record_offset), le16toh(i_ptEntry->record_length),
                           le16toh(i_ptEntry->ecc_offset), le16toh(i_ptEntry->ecc_length) );

                // If caller passes in the meta data, then use that data instead of
                // re-retrieving it.
                l_recordName = i_ptEntry->record_name;
                l_ptEntry = *i_ptEntry;
            }
            else
            {
                TRACFCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::updateRecordEccData(): target(0x%.8X) "
                          "i_args = record(0x%.4X), keyword(0x%.4X), location(0x%.4X), "
                          "eepromSource(0x%.4X).  Retrieving record meta data for record 0x%.4X.",
                          l_targetHuid, i_args.record, i_args.keyword, i_args.location,
                          i_args.eepromSource, i_args.record);

                // Caller did not pass in the meta data, will retrieve it.
                l_err = translateRecord(i_args.record, l_recordName);
                if ( unlikely(nullptr != l_err) )
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::updateRecordEccData(): "
                               "translateRecord failed to translate record 0x%.4X on target 0x%.8X",
                               i_args.record, l_targetHuid );
                    break;
                }

                TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::updateRecordEccData(): "
                            "translateRecord succeeded in translating record 0x%.4X to %s "
                            "on target 0x%.8X", i_args.record, l_recordName, l_targetHuid );

                // Get the record meta data
                l_err = getRecordMetaData ( i_target, i_args, l_ptEntry, l_recordName );
                if ( unlikely(nullptr != l_err) )
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::updateRecordEccData(): "
                               "getRecordMetaData failed to get the meta data for record %s "
                               "on target 0x%.8X", l_recordName, l_targetHuid );
                    break;
                }
            } // if (i_ptEntry)  ... else ...

            // Convert the meta data to the correct format
            size_t l_recordOffset(le16toh(l_ptEntry.record_offset));
            size_t l_recordLength(le16toh(l_ptEntry.record_length));
            size_t l_eccOffset(le16toh(l_ptEntry.ecc_offset));
            size_t l_eccLength(le16toh(l_ptEntry.ecc_length));

            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::updateRecordEccData(): "
                        "getRecordMetaData returned record offset(0x%.4x), record length(0x%.4x) "
                        "ecc offset(0x%.4x), ecc length(0x%.4x) for record %s on target 0x%.8X",
                        l_recordOffset, l_recordLength, l_eccOffset,
                        l_eccLength,    l_recordName,   l_targetHuid );

            // Retrieve the record data.
            uint8_t l_recordData[l_recordLength] = {0};  // Create record data buffer
            l_err = fetchDataFromEeprom(l_recordOffset, l_recordLength, l_recordData,
                                        i_target,       i_args.eepromSource);

            if ( unlikely(nullptr != l_err) )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::updateRecordEccData(): "
                           "fetchDataFromEeprom failed to retrieve record data %s on "
                           "target 0x%.8X", l_recordName, l_targetHuid );
                break;
            }

            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::updateRecordEccData(): "
                        "fetchDataFromEeprom succeeded in retrieving record data %s on "
                        "target 0x%.8X", l_recordName, l_targetHuid );

            // Create the ECC data using the record's data
            uint8_t l_eccData[l_eccLength] = {0};  // Create record data buffer
            auto l_returnCode = vpdeccCreateEcc(l_recordData, l_recordLength,
                                                l_eccData,   &l_eccLength);

            // If the return code from the call to vpdeccCreateEcc is not VPD_ECC_OK, then an error occurred
            if ( unlikely(VPD_ECC_OK != l_returnCode) )
            {
                // Check the return code of the call to "vpdeccCreateEcc()" and create the
                // appropriate error log if necessary.
                l_err = checkCreateEccDataReturnCode(l_returnCode, i_target, i_args, l_recordName,
                                        l_recordOffset, l_recordLength, l_eccOffset, l_eccLength);
                if (l_err)
                {
                    break;
                }
            }

            // Write the ECC data to the ECC data's offset
            l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                        i_target,
                                        l_eccData,
                                        l_eccLength,
                                        DEVICE_EEPROM_ADDRESS(
                                          EEPROM::VPD_AUTO,
                                          l_eccOffset,
                                          EEPROM::AUTOSELECT) );

            if ( l_err )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::updateRecordEccData(): "
                    "Error with call to DeviceFW::deviceOp(WRITE) for target(0x%.8X) "
                    "failed to update the ECC data for record(%s) at ECC offset(0x%.4x) "
                    "with ECC length(0x%.4x)",
                    TARGETING::get_huid(i_target), l_recordName, l_eccOffset, l_eccLength );
                break;
            }

            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::updateRecordEccData(): "
                    "Success with call to DeviceFW::deviceOp(WRITE) for target(0x%.8X) "
                    "succeeded in updating the ECC data for record(%s) at ECC offset(0x%.4x) "
                    "with ECC length(0x%.4x)",
                    TARGETING::get_huid(i_target), l_recordName, l_eccOffset, l_eccLength );
        } while (0);

        TRACFCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::updateRecordEccData(): "
                                "returning %s errors for record %s on target 0x%.8X",
                                (l_err ? "with" : "with no"), l_recordName, l_targetHuid );
    } // if (true == g_vpd_ecc_api_present)

    return l_err;
} // updateRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::validateAllRecordEccData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::validateAllRecordEccData ( const TARGETING::TargetHandle_t  i_target )
{
    errlHndl_t l_validationError(nullptr);

    // If the VPD ECC algorithms are present then execute code.
    if (true == g_vpd_ecc_api_present)
    {
        // Get a copy of the target huid, once, for tracing purposes
        auto l_targetHuid = TARGETING::get_huid(i_target);

        TRACFCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::validateAllRecordEccData(): "
                                        "target 0x%.8X",  l_targetHuid );

        while (1)
        {
            l_validationError = _validateAllRecordEccData(i_target);

            // If the error returned because the VPD ECC validation failed, then
            // get next MVPD source.
            if ( l_validationError &&
                 (VPD::VPD_IPVPD_ECC_DATA_CHECK == l_validationError->moduleId()) )
            {
                #ifndef __HOSTBOOT_RUNTIME
                    errlHndl_t l_mvpdSourceError(nullptr);

                    // If validation of record ECC Data fails,
                    // then move onto the next MVPD source and try again.
                    l_mvpdSourceError = EEPROM::reloadMvpdEecacheFromNextSource(i_target, l_validationError);
                    if (l_mvpdSourceError)
                    {
                        // Validation of the record ECC data failed AND getting the next MVPD
                        // EECACHE source failed as well. Commit the MVPD source error, keep
                        // the validation error and deconfigure target based on the validation
                        // error.
                        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllRecordEccData(): "
                                   "reloadMvpdEecacheFromNextSource failed to get the next MVPD "
                                   "source for target 0x%.8X",  l_targetHuid );
                        errlCommit( l_mvpdSourceError, VPD_COMP_ID );
                    }
                #endif

                if (l_validationError)
                {
                    break;
                }
            }
            // Stop validating the record data if successful or the error
            // (if an error occurred) is not of type VPD::VPD_IPVPD_ECC_DATA_CHECK.
            else
            {
                break;
            }
        } // while (1)

        if ( unlikely(nullptr != l_validationError) )
        {
            // If validating a record returns an error and/or exhausted MVDP sources,
            // then deconfigure the target associated with this VPD so we can
            // potentially make more progress on the next boot.

            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllRecordEccData(): "
                   "failed to validate all the MVPD records' ECC data. "
                   "Calling out VPD part for target 0x%.8X", l_targetHuid );

            l_validationError->addPartCallout( i_target,
                                               HWAS::VPD_PART_TYPE,
                                               HWAS::SRCI_PRIORITY_HIGH );

            l_validationError->addHwCallout( i_target,
                                             HWAS::SRCI_PRIORITY_MED,
                                             HWAS::DELAYED_DECONFIG,
                                             HWAS::GARD_NULL );

            l_validationError->collectTrace( VPD_COMP_NAME, 256 );
        } // if ( unlikely(nullptr != l_validationError) )

        TRACFCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::validateAllRecordEccData(): "
                   "returning %s errors on target 0x%.8X",
                   (l_validationError ? "with" : "with no"), l_targetHuid );
    } // if (true == g_vpd_ecc_api_present)

    return l_validationError;
} // validateAllRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::_validateAllRecordEccData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::_validateAllRecordEccData ( const TARGETING::TargetHandle_t  i_target )
{
    // Target needs to be a PROC
    assert(TARGETING::TYPE_PROC == i_target->getAttr<TARGETING::ATTR_TYPE>(),
           "IpVpdFacade::_validateAllRecordEccData(): Target 0x%.8X is not a PROC",
           TARGETING::get_huid(i_target) );

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::_validateAllRecordEccData(): "
                                    "target 0x%.8X",  TARGETING::get_huid(i_target) );

    errlHndl_t l_err(nullptr);

    // Run validation on the cached copy of the VPD, as validating the
    // hardware is much slower by comparison.
    do
    {
        // Create the input args.  Only interested in the CACHE of the SEEPROM
        input_args_t l_args;
        l_args.record = 0;    // Not needed/used, defaulting to 0
        l_args.keyword = 0;   // Not needed/used, defaulting to 0
        l_args.location = VPD::SEEPROM;
        l_args.eepromSource = EEPROM::CACHE;

        // Define the VHDR record data buffer.  The constructor does not fill in the VTOC
        // meta data, that will be done via call to validateVhdrRecordEccData()
        vhdr_record l_vhdrRecordData(0);

        // Validate the VHDR record's ECC data, the first record in the MVPD data.
        // This method will also fill in the VTOC meta data within the VHDR record data
        l_err = validateVhdrRecordEccData(i_target, l_args, l_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::_validateAllRecordEccData(): "
                       "validateVhdrRecordEccData failed to validate the VHDR record");
            break;
        }

        // Validate the VTOC record's ECC data, the second record in the MVPD data.
        l_err = validateVtocRecordEccData(i_target, l_args, l_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::_validateAllRecordEccData(): "
                       "validateVtocRecordEccData failed to validate the VTOC record");
            break;
        }

        // Validate all the other record's ECC data.
        l_err = validateAllOtherRecordEccData(i_target, l_args, l_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::_validateAllRecordEccData(): "
                       "validateAllOtherRecordEccData failed to validate all records "
                       "excluding the VHDR and VTOC record");
            break;
        }
    } while ( 0 );

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::_validateAllRecordEccData(): "
               "returning %s errors on target 0x%.8X",
               (l_err ? "with" : "with no"), TARGETING::get_huid(i_target) );

    return l_err;
} // _validateAllRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::validateVhdrRecordEccData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::validateVhdrRecordEccData( const TARGETING::TargetHandle_t i_target,
                                        const input_args_t              &i_args,
                                        vhdr_record                     &o_vhdrRecordData )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::validateVhdrRecordEccData(): for "
                "record %s on target 0x%.8X; i_args = record(0x%.4X), keyword(0x%.4X), "
                "location(0x%.4X), eepromSource(0x%.4X)",
                VPD_HEADER_RECORD_NAME, TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource);

    errlHndl_t l_err(nullptr);

    do
    {
        // Get the VHDR record so it can be validated
        l_err = getFullVhdrRecordData(i_target, i_args, o_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                       "getFullVhdrRecordData failed to get the full data for record VHDR");
            break;
        }

        // The record data is right after the ECC data.
        size_t l_recordOffset(VHDR_ECC_DATA_SIZE);
        uint8_t* l_recordData(reinterpret_cast<uint8_t*>(&o_vhdrRecordData) + l_recordOffset);
        size_t l_recordLength(sizeof(o_vhdrRecordData) - VHDR_ECC_DATA_SIZE);

        // The ECC data is the first data in the VHDR record
        size_t l_eccOffset(0);
        uint8_t* l_eccData(reinterpret_cast<uint8_t*>(&o_vhdrRecordData));
        size_t l_eccLength(VHDR_ECC_DATA_SIZE);

        // Verify that retrieved ECC data is as expected.
        auto l_returnCode = vpdeccCheckData(l_recordData, l_recordLength,
                                              l_eccData,    l_eccLength);

        // If the return code from the call to vpdeccCheckData is not VPD_ECC_OK, then an error occurred
        if ( unlikely(VPD_ECC_OK != l_returnCode) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                       "vpdeccCheckData failed with error code %d for record %s "
                       "on target 0x%.8X", l_returnCode, VPD_HEADER_RECORD_NAME,
                       TARGETING::get_huid(i_target) );

            // Check the return code of the call to "vpdeccCheckData()" and create
            // the appropriate error log if necessary.
            l_err = checkEccDataValidationReturnCode(l_returnCode, i_target, i_args,
                    VPD_HEADER_RECORD_NAME, l_recordOffset, l_recordLength,
                    l_eccOffset, l_eccLength);

            if (l_err && (l_err->reasonCode() == VPD::VPD_ECC_DATA_CORRECTABLE_DATA) )
            {
                // Attempt to update and correct the record to be in sync with the ECC data
                TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                           "Attempt to update and correct the record %s to be in sync with "
                           "the ECC data on target 0x%.8X",
                           VPD_HEADER_RECORD_NAME, TARGETING::get_huid(i_target) );

                updateRecordData( l_err,        i_target,       VPD_HEADER_RECORD_NAME,
                                  l_recordData, l_recordOffset, l_recordLength  );
                if (l_err)
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                               "updateRecordData failed to update record %s on target 0x%.8X",
                               VPD_HEADER_RECORD_NAME, TARGETING::get_huid(i_target) );
                    break;
                }

                TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                           "updateRecordData successfully updated record %s on target 0x%.8X",
                           VPD_HEADER_RECORD_NAME, TARGETING::get_huid(i_target) );
            }
            else if (l_err)
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                           "vpdeccCheckData failed with error code %d for record %s "
                           "on target 0x%.8X", l_returnCode,
                           VPD_HEADER_RECORD_NAME, TARGETING::get_huid(i_target) );

                break;
            }
        } // if ( unlikely(VPD_ECC_OK != l_returnCode) )
    } while( 0 );

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::validateVhdrRecordEccData(): "
                "returning %s errors on record %s on target 0x%.8X",
                (l_err ? "with" : "with no"), VPD_HEADER_RECORD_NAME,
                TARGETING::get_huid(i_target) );

    return l_err;
} // validateVhdrRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::getFullVhdrRecordData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::getFullVhdrRecordData ( const TARGETING::TargetHandle_t i_target,
                                     const input_args_t             &i_args,
                                     vhdr_record                    &o_vhdrRecordData )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::getFullVhdrRecordData(): for "
                "record %s on target 0x%.8X; i_args = record(0x%.4X), keyword(0x%.4X), "
                "location(0x%.4X), eepromSource(0x%.4X)",
                VPD_HEADER_RECORD_NAME, TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource);

    errlHndl_t l_err(nullptr);

    // Retrieve the record data.
    size_t l_recordOffset(0), l_recordLength(sizeof(o_vhdrRecordData));
    l_err = fetchDataFromEeprom(l_recordOffset, l_recordLength, &o_vhdrRecordData,
                                i_target,       i_args.eepromSource);

    if ( unlikely(nullptr != l_err) )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getFullVhdrRecordData(): "
                   "fetchDataFromEeprom failed to retrieve record %s with record length "
                   "%d and record offset 0x%.4X on target 0x%.8X", VPD_HEADER_RECORD_NAME,
                   l_recordLength, l_recordOffset, TARGETING::get_huid(i_target));
    }
    else if (0 == o_vhdrRecordData.pt_kw_vtoc_ecc_len)
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getFullVhdrRecordData(): "
                   "fetchDataFromEeprom failed to properly retrieve the meta data for "
                   "record %s with record length %d and record offset 0x%.4X on target "
                   "0x%.8X. The VTOC ECC meta data for the record is missing.",
                   VPD_HEADER_RECORD_NAME,
                   l_recordLength, l_recordOffset, TARGETING::get_huid(i_target));

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_RECORD_INVALID_VHDR
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FETCH_DATA
         * @userdata1[00:31] Target to find record in
         * @userdata1[32:64] Input arg: Record ID
         * @userdata2[00:31] Input arg: Location
         * @userdata2[32:64] Input arg: EEEPROM SOURCE
         * @devdesc          The retrieved VPD Header Record (VHDR) is incomplete.
         * @custdesc         Firmware error with the VPD.
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         VPD::VPD_IPVPD_FETCH_DATA,
                                         VPD::VPD_RECORD_INVALID_VHDR,
                                         TWO_UINT32_TO_UINT64(
                                             TARGETING::get_huid(i_target),
                                             i_args.record ),
                                         TWO_UINT32_TO_UINT64(
                                             i_args.location,
                                             i_args.eepromSource ),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
    }

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::getFullVhdrRecordData(): "
                "returning %s errors for record %s on target 0x%.8X",
                (l_err ? "with" : "with no"), VPD_HEADER_RECORD_NAME,
                TARGETING::get_huid(i_target) );

    return l_err;
} // getFullVhdrRecordData

// ------------------------------------------------------------------
// IpVpdFacade::validateVtocRecordEccData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::validateVtocRecordEccData(
                const TARGETING::TargetHandle_t i_target,
                const input_args_t              &i_args,
                const vhdr_record               &i_vhdrRecordData )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::validateVtocRecordEccData(): for "
                "record %s on target 0x%.8X; i_args = record(0x%.4X), keyword(0x%.4X), "
                "location(0x%.4X), eepromSource(0x%.4X)",
                VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource);

    errlHndl_t l_err(nullptr);

    do
    {
        // Get the VTOC's meta data
        pt_entry l_ptEntry = {0};
        l_err = getVtocRecordMetaData(i_target, i_args, l_ptEntry, &i_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                       "getVtocRecordMetaData failed to get the record VTOC's meta data");
            break;
        }

        // Convert the meta data to the correct endianness
        size_t l_recordOffset(le16toh(l_ptEntry.record_offset));
        size_t l_recordLength(le16toh(l_ptEntry.record_length));
        size_t l_eccOffset(le16toh(l_ptEntry.ecc_offset));
        size_t l_eccLength(le16toh(l_ptEntry.ecc_length));

        TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                    "The record %s meta data: record length %d, record offset 0x%.4X, "
                    "ecc length %d and ecc offset 0x%.4X",
                    VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                    l_recordLength, l_recordOffset, l_eccLength, l_eccOffset);

        // Retrieve the record data.
        uint8_t l_recordData[l_recordLength] = {0};  // Create record data buffer
        l_err = fetchDataFromEeprom(l_recordOffset, l_recordLength, l_recordData,
                                    i_target,       i_args.eepromSource);

        if ( unlikely(nullptr != l_err) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                       "fetchDataFromEeprom failed to retrieve record %s with record length %d "
                       "and record offset 0x%.4X on target 0x%.8X",
                       VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                       l_recordLength, l_recordOffset, TARGETING::get_huid(i_target) );
            break;
        }

        // Retrieve the ECC data.
        uint8_t l_eccData[l_eccLength] = {0};  // Create ECC data buffer
        l_err = fetchDataFromEeprom(l_eccOffset, l_eccLength, l_eccData,
                                    i_target,    i_args.eepromSource);

        if ( unlikely(nullptr != l_err) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                       "fetchDataFromEeprom failed to retrieve ECC data for record %s "
                       "with ecc length %d and ecc offset 0x%.4X on target 0x%.8X",
                       VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                       l_eccLength, l_eccOffset, TARGETING::get_huid(i_target) );
            break;
        }

        // Verify that the retrieved ECC data is as expected.
        auto l_returnCode = vpdeccCheckData(l_recordData, l_recordLength,
                                            l_eccData,    l_eccLength);

        // If the return code from the call to vpdeccCheckData is not VPD_ECC_OK, then an error occurred
        if ( unlikely(VPD_ECC_OK != l_returnCode) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                       "vpdeccCheckData failed with error code %d for record %s "
                       "on target 0x%.8X", l_returnCode, VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                       TARGETING::get_huid(i_target) );

            // Get the 'force an ECC data update' flag
            auto l_forceEccUpdateFlag = TARGETING::UTIL::assertGetToplevelTarget()->
                 getAttr<TARGETING::ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR>();

            // Update the ECC data if forcing an update and the error is not a correctable error.
            // A correctable error is handled after this conditional.
            if ( l_forceEccUpdateFlag && (VPD::VPD_ECC_DATA_CORRECTABLE_DATA != l_returnCode) )
            {
                // Attempt to update the ECC data for record
                TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                           "Will attempt to update the ECC data based on the "
                           "ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR flag %d for record %s "
                           "on target 0x%.8X", l_forceEccUpdateFlag,
                           VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target) );

                errlHndl_t l_updateEccDataError = updateRecordEccData(i_target, i_args, &l_ptEntry);
                if (l_updateEccDataError)
                {
                    // Failed to update the ECC data for record
                    TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                               "updateRecordEccData failed to update the ECC data for "
                               "record %s on target 0x%.8X.  Setting error to informational.",
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target) );

                    // Set the error, from the failed update, as informational. The original
                    // validation fail, of the ECC data, will be handled below and severity
                    // set accordingly.
                    l_updateEccDataError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    errlCommit(l_updateEccDataError, VPD_COMP_ID);
                }
                else
                {
                    // Successfully updated the ECC data for record
                    TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                               "updateRecordEccData successfully updated the ECC data for "
                               "record %s on target 0x%.8X",
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target) );

                    // Setting the return code to 'OK', will allow the following code to
                    // have a successful resolution irrespective that the code is currently
                    // in an error path.
                    l_returnCode = VPD_ECC_OK;
                }
            } // if ( TARGETING::UTIL::assertGetToplevelTarget()->

            // Check the return code of the call to "vpdeccCheckData()" and create the
            // appropriate error log if necessary.
            l_err = checkEccDataValidationReturnCode(l_returnCode, i_target, i_args,
                    VPD_TABLE_OF_CONTENTS_RECORD_NAME, l_recordOffset, l_recordLength,
                    l_eccOffset, l_eccLength);

            if (l_err && (l_err->reasonCode() == VPD::VPD_ECC_DATA_CORRECTABLE_DATA) )
            {
                // Attempt to update and correct the record to be in sync with the ECC data
                TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                           "Attempt to update and correct the record %s to be in sync with "
                           "the ECC data on target 0x%.8X",
                           VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target) );

                updateRecordData( l_err,        i_target,       VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                                  l_recordData, l_recordOffset, l_recordLength  );
                if (l_err)
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                               "updateRecordData failed to update record %s on target 0x%.8X",
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target) );
                    break;
                }

                TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                           "updateRecordData successfully updated record %s on target 0x%.8X",
                           VPD_TABLE_OF_CONTENTS_RECORD_NAME, TARGETING::get_huid(i_target) );
            }
            else if (l_err)
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                           "Error code %d is an unrecoverable error, returning with error",
                           l_returnCode);
                break;
            }
        } // if ( unlikely(VPD_ECC_OK != l_returnCode) )
    } while( 0 );

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::validateVtocRecordEccData(): "
                "returning %s errors for record %s on target 0x%.8X",
                (l_err ? "with" : "with no"), VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                TARGETING::get_huid(i_target) );

    return l_err;
} // validateVtocRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::validateAllOtherRecordEccData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::validateAllOtherRecordEccData(
                const TARGETING::TargetHandle_t  i_target,
                const input_args_t              &i_args,
                const vhdr_record               &i_vhdrRecordData )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                "target(0x%.8X); i_args = record(0x%.4X), keyword(0x%.4X), "
                "location(0x%.4X), eepromSource(0x%.4X)", TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource);

    errlHndl_t l_err(nullptr);

    do
    {
        // Get the all the record meta data, minus the VHDR and VTOC records
        std::list<pt_entry> l_recordMetaDataList;
        l_err = getAllRecordMetaData(i_target, i_args, l_recordMetaDataList, i_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                        "getAllRecordMetaData failed");
            break;
        }

        // There will be multiple records to examine and validate their ECC data.
        // That will require allocating a buffer for each record and it's associated
        // ECC data to be retrieved and validated.  To expedite this, create one large
        // buffer, for each of the data buffers, that can hold any one of the respective
        // data member rather than constantly allocating and freeing up memory.

        // Find the largest buffer size, for each data member, to be used to create
        // the largest data buffer necessary.
        uint16_t l_maxRecordBufferLength(0);
        uint16_t l_maxEccBufferLength(0);
        for (const pt_entry &l_ptEntry: l_recordMetaDataList)
        {
            uint16_t l_recordLength(le16toh(l_ptEntry.record_length));
            uint16_t l_eccLength(le16toh(l_ptEntry.ecc_length));
            l_maxRecordBufferLength = std::max(l_maxRecordBufferLength, l_recordLength);
            l_maxEccBufferLength = std::max(l_maxEccBufferLength, l_eccLength);
        }

        // Pre-allocate the buffers, once, with the largest buffer size needed
        uint8_t l_recordData[l_maxRecordBufferLength] = {0};
        uint8_t l_eccData[l_maxEccBufferLength] = {0};

        // Iterate thru the records validating it's ECC data
        for (const pt_entry &l_ptEntry: l_recordMetaDataList)
        {
            // Convert the meta data to the correct format
            size_t l_recordOffset(le16toh(l_ptEntry.record_offset));
            size_t l_recordLength(le16toh(l_ptEntry.record_length));
            size_t l_eccOffset(le16toh(l_ptEntry.ecc_offset));
            size_t l_eccLength(le16toh(l_ptEntry.ecc_length));

            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                        "Validating record's %s meta data: record length %d, record offset "
                        "0x%.4X, ecc length %d and ecc offset 0x%.4X", l_ptEntry.record_name,
                        l_recordLength, l_recordOffset, l_eccLength, l_eccOffset);

            // Retrieve the record data.
            l_err = fetchDataFromEeprom(l_recordOffset, l_recordLength, l_recordData,
                                        i_target,       i_args.eepromSource);

            if ( unlikely(nullptr != l_err) )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                           "fetchDataFromEeprom failed to retrieve record %s with record length "
                           "%d and record offset 0x%.4X on target 0x%.8X", l_ptEntry.record_name,
                           l_recordLength, l_recordOffset, TARGETING::get_huid(i_target) );
                break;
            }

            // Retrieve the ECC data.
            l_err = fetchDataFromEeprom(l_eccOffset, l_eccLength, l_eccData,
                                        i_target,    i_args.eepromSource);

            if ( unlikely(nullptr != l_err) )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                           "fetchDataFromEeprom failed to retrieve ECC data for record %s "
                           "with ecc length %d and ecc offset 0x%.4X on target 0x%.8X",
                           l_ptEntry.record_name, l_eccLength,
                           l_eccOffset, TARGETING::get_huid(i_target) );
                break;
            }

            // Verify that the retrieved ECC data is as expected.
            auto l_returnCode = vpdeccCheckData(l_recordData, l_recordLength,
                                                  l_eccData,    l_eccLength);

            // If the return code from the call to vpdeccCheckData is not VPD_ECC_OK, then an error occurred
            if ( unlikely(VPD_ECC_OK != l_returnCode) )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                           "vpdeccCheckData failed with error code %d for record %s "
                           "on target 0x%.8X", l_returnCode, l_ptEntry.record_name,
                           TARGETING::get_huid(i_target) );

                // Get the 'force an ECC data update' flag
                auto l_forceEccUpdateFlag = TARGETING::UTIL::assertGetToplevelTarget()->
                     getAttr<TARGETING::ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR>();

                // Update the ECC data if forcing an update and the error is not a correctable error.
                // A correctable error is handled after this conditional.
                if ( l_forceEccUpdateFlag && (VPD::VPD_ECC_DATA_CORRECTABLE_DATA != l_returnCode) )
                {
                    // Attempt to update the ECC data for record
                    TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                               "Will attempt to update the ECC data based on the "
                               "ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR flag %d for record %s "
                               "on target 0x%.8X", l_forceEccUpdateFlag,
                               l_ptEntry.record_name, TARGETING::get_huid(i_target) );

                    errlHndl_t l_updateEccDataError = updateRecordEccData(i_target, i_args, &l_ptEntry);
                    if (l_updateEccDataError)
                    {
                        // Failed to update the ECC data for record
                        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                                   "updateRecordEccData failed to update the ECC data for "
                                   "record %s on target 0x%.8X. Setting error to informational.",
                                   l_ptEntry.record_name, TARGETING::get_huid(i_target) );

                        // Set the error, from the failed update, as informational. The original
                        // validation fail, of the ECC data, will be handled below and severity
                        // set accordingly.
                        l_updateEccDataError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        errlCommit(l_updateEccDataError, VPD_COMP_ID);
                    }
                    else
                    {
                        // Successfully updated the ECC data for record
                        TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                                   "updateRecordEccData successfully updated the ECC data for "
                                   "record %s on target 0x%.8X",
                                   l_ptEntry.record_name, TARGETING::get_huid(i_target) );

                        // Setting the return code to 'OK', will allow the following code to
                        // have a successful resolution irrespective that the code is currently
                        // in an error path.
                        l_returnCode = VPD_ECC_OK;
                    }
                } // if ( TARGETING::UTIL::assertGetToplevelTarget()->

                // Check the return code of the call to "vpdeccCheckData()" and create the
                // appropriate error log if necessary.
                l_err = checkEccDataValidationReturnCode(l_returnCode, i_target, i_args,
                        l_ptEntry.record_name, l_recordOffset, l_recordLength,
                        l_eccOffset, l_eccLength);

                if (l_err && (l_err->reasonCode() == VPD::VPD_ECC_DATA_CORRECTABLE_DATA) )
                {
                    // Attempt to update and correct the record to be in sync with the ECC data
                    TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                               "Attempt to update and correct the record %s to be in sync with "
                               "the ECC data on target 0x%.8X",
                               l_ptEntry.record_name, TARGETING::get_huid(i_target) );

                    updateRecordData( l_err,        i_target,       l_ptEntry.record_name,
                                      l_recordData, l_recordOffset, l_recordLength  );
                    if (l_err)
                    {
                        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                                   "updateRecordData failed to update record %s on target 0x%.8X",
                                   l_ptEntry.record_name, TARGETING::get_huid(i_target) );
                        break;
                    }

                    TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                               "updateRecordData successfully updated record %s on target 0x%.8X",
                               l_ptEntry.record_name, TARGETING::get_huid(i_target) );
                }
                else if (l_err)
                {
                    TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
                               "Error code %d is an unrecoverable error, returning with error",
                               l_returnCode);
                    break;
                }
            } // if ( unlikely(VPD_ECC_OK != l_returnCode) )
        } // for (const pt_entry &l_ptEntry: l_recordMetaDataList)
    } while (0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::validateAllOtherRecordEccData(): "
               "returning %s errors on target 0x%.8X",
               (l_err ? "with" : "with no"), TARGETING::get_huid(i_target) );

    return l_err;
} // validateAllOtherRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::getAllRecordMetaData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::getAllRecordMetaData (
                const TARGETING::TargetHandle_t  i_target,
                const input_args_t              &i_args,
                std::list<pt_entry>             &o_recordMetaDataList,
                const vhdr_record               &i_vhdrRecordData  )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::getAllRecordMetaData(): target(0x%.8X) "
                "i_args = record(0x%.4X), keyword(0x%.4X), location(0x%.4X), "
                "eepromSource(0x%.4X)", TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource);

    errlHndl_t l_err = nullptr;

    do
    {
        // Get the VTOC record meta data
        pt_entry l_vtocRecordMetaData = {0};  // The struct to contain the VTOC meta data
        l_err = getVtocRecordMetaData(i_target, i_args, l_vtocRecordMetaData, &i_vhdrRecordData);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getAllRecordMetaData(): "
                       "getVtocRecordMetaData failed to get the record VTOC's meta data");
            break;
        }

        l_err = _getRecordMetaData (i_target, l_vtocRecordMetaData, i_args, o_recordMetaDataList);
        if (l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getAllRecordMetaData(): "
                       "_getRecordMetaData failed to get all the record meta data");

            break;
        }
    } while (0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::getAllRecordMetaData(): "
                "returning %s errors on target 0x%.8X and record meta data list with %d entries",
                (l_err ? "with" : "with no"), TARGETING::get_huid(i_target),
                o_recordMetaDataList.size() );

    return l_err;
} // getAllRecordMetaData

// ------------------------------------------------------------------
// IpVpdFacade::getRecordMetaData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::getRecordMetaData (
                const TARGETING::TargetHandle_t  i_target,
                const input_args_t              &i_args,
                pt_entry                        &o_recordMetaData,
                const char* const                i_recordName )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::getRecordMetaData(): target(0x%.8X) "
                "i_args = record(0x%.4X), keyword(0x%.4X), location(0x%.4X), "
                "eepromSource(0x%.4X)", TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource);

    errlHndl_t l_err = nullptr;

    // Clear the outgoing meta data
    memset(&o_recordMetaData, 0, sizeof(o_recordMetaData));

    do
    {
        // Get the record name from the input args, if not provided
        const char* l_recordName(i_recordName);
        if (nullptr == l_recordName)
        {
            l_err = translateRecord(i_args.record, l_recordName);
            if ( unlikely(nullptr != l_err) )
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getRecordMetaData(): "
                           "translateRecord failed to translate record 0x%.8X", i_args.record);
                break;
            }
        }

        // Get the VTOC record meta data
        pt_entry l_vtocRecordMetaData = {0};  // The struct to contain the VTOC meta data
        l_err = getVtocRecordMetaData(i_target, i_args, l_vtocRecordMetaData);
        if ( unlikely(nullptr != l_err) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getRecordMetaData(): "
                       "getVtocRecordMetaData failed to get the record VTOC's meta data");
            break;
        }

        // Get the meta data for the record
        std::list<pt_entry> l_recordMetaDataList;
        l_err = _getRecordMetaData (i_target, l_vtocRecordMetaData, i_args,
                                    l_recordMetaDataList, l_recordName );
        if ( unlikely(nullptr != l_err) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::getRecordMetaData(): "
                       "_getRecordMetaData failed to get the record's %s meta data", l_recordName);
            break;
        }

        // If there is meta data in the list, then retrieve it
        if (l_recordMetaDataList.size())
        {
            o_recordMetaData = l_recordMetaDataList.front();

            TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::getRecordMetaData(): Record %s "
                        "found, returning the record's meta data: record offset 0x%.4X, "
                        "record length %d, ecc offset 0x%.4X and ecc length %d",
                        o_recordMetaData.record_name,
                        le16toh(o_recordMetaData.record_offset),
                        le16toh(o_recordMetaData.record_length),
                        le16toh(o_recordMetaData.ecc_offset),
                        le16toh(o_recordMetaData.ecc_length) );
        }
        // Else, if the list is empty, then the record was not found
        else
        {
            TRACFCOMP( g_trac_vpd, "IpVpdFacade::getRecordMetaData(): "
                       "Record 0x%.4X not found", i_args.record );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_RECORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_GET_RECORD_META_DATA
             * @userdata1[00:31] Target to find record in
             * @userdata1[32:64] Input arg: Record ID
             * @userdata2[00:31] Input arg: Location
             * @userdata2[32:64] Input arg: EEEPROM SOURCE
             * @devdesc          VPD record was not found.
             * @custdesc         Firmware error with the VPD.
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             VPD::VPD_IPVPD_GET_RECORD_META_DATA,
                                             VPD::VPD_RECORD_NOT_FOUND,
                                             TWO_UINT32_TO_UINT64(
                                                 TARGETING::get_huid(i_target),
                                                 i_args.record ),
                                             TWO_UINT32_TO_UINT64(
                                                 i_args.location,
                                                 i_args.eepromSource ),
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            break;
        }
    } while (0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::getRecordMetaData(): "
                "returning %s errors on target 0x%.8X",
                (l_err ? "with" : "with no"), TARGETING::get_huid(i_target) );

    return l_err;
} // getRecordMetaData

// ------------------------------------------------------------------
// IpVpdFacade::_getRecordMetaData
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::_getRecordMetaData (
                const TARGETING::TargetHandle_t  i_target,
                const pt_entry                  &i_vtocRecordMetaData,
                const input_args_t              &i_args,
                std::list<pt_entry>             &o_recordMetaDataList,
                const char* const                i_recordName )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"IpVpdFacade::_getRecordMetaData(): target(0x%.8X); "
                "i_args = record(0x%.4X), keyword(0x%.4X), location(0x%.4X), "
                "eepromSource(0x%.4X); %s %s", TARGETING::get_huid(i_target),
                i_args.record, i_args.keyword, i_args.location, i_args.eepromSource,
                (i_recordName ? "find record" : "gather all records" ),
                (i_recordName ? i_recordName : ""));

    errlHndl_t l_err(nullptr);

    // Clear the outgoing list
    o_recordMetaDataList.clear();

    do
    {
        // Skip the 'large resource'
        uint16_t l_offset = le16toh( i_vtocRecordMetaData.record_offset ) + 1;

        // Create a buffer to hold the VTOC's PT keyword data
        size_t l_ptKeywordBufferLength(MAX_KEYWORD_SIZE);
        char   l_ptKeywordBuffer[l_ptKeywordBufferLength] = { 0 };

        // Pointer to the meta data structure; used as a convenient way
        // to access the record's meta data.
        pt_entry *l_recordMetaData(nullptr);

        bool l_recordFound(false);

        // Read the PT keyword(s). The VTOC can have multiple PT keywords
        // but must have at least one.
        // Exit loop when an error occurs when reading one past the number of PT keywords.
        for (uint16_t l_index(0); /* exit criteria in code */ ; ++l_index)
        {
            l_err = retrieveKeyword( VPD_KEYWORD_POINTER_TO_RECORD,
                                     VPD_TABLE_OF_CONTENTS_RECORD_NAME,
                                     l_offset, l_index, i_target, l_ptKeywordBuffer,
                                     l_ptKeywordBufferLength, i_args );

            if ( l_err )
            {
                // If the index is greater than 0, and/or module ID and reason code are of "keyword not
                // found" then the number of PT keywords have been exhausted, for the VTOC record,
                // and this is an expected error, delete error log and exit method.
                if ( ( 0 != l_index ) && ( VPD::VPD_KEYWORD_NOT_FOUND == l_err->reasonCode() ) &&
                     ( VPD::VPD_IPVPD_FIND_KEYWORD_ADDR == l_err->moduleId() )                   )
                {
                    TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::_getRecordMetaData(): Exhausted "
                               "all PT keywords for record %s with a total of %d PT keywords "
                               "found. Deleting the produced error log because an error is "
                               "expected when retrieving all PT keywords",
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME, l_index);
                    delete l_err;
                    l_err = nullptr;
                }
                else
                // Else, index is 0 and/or there was an issue getting a PT keyword.
                {
                    TRACFCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::_getRecordMetaData(): "
                               "Failed to get all the PT keywords for record %s, at index %d",
                               VPD_TABLE_OF_CONTENTS_RECORD_NAME, l_index);
                }

                // Exit with or without error log
                break;
            }

            // Scan through the VTOC PT keyword buffer, collecting the meta data of each record.
            for (size_t l_vtocPtOffset = 0; l_vtocPtOffset < l_ptKeywordBufferLength;
                 l_vtocPtOffset += sizeof(pt_entry))
            {
                l_recordMetaData = reinterpret_cast<pt_entry*>(l_ptKeywordBuffer + l_vtocPtOffset);
                // Caller passed in a record name, then caller is only interested in a particular record
                if (i_recordName)
                {
                    if (0 == memcmp(l_recordMetaData->record_name, i_recordName, RECORD_BYTE_SIZE))
                    {
                        TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::_getRecordMetaData(): Record %s "
                                    "found, returning the record's meta data: record offset "
                                    "0x%.4X, record length %d, ecc offset 0x%.4X and ecc length %d",
                                    l_recordMetaData->record_name,
                                    le16toh(l_recordMetaData->record_offset),
                                    le16toh(l_recordMetaData->record_length),
                                    le16toh(l_recordMetaData->ecc_offset),
                                    le16toh(l_recordMetaData->ecc_length) );

                        o_recordMetaDataList.push_back(*l_recordMetaData);
                        l_recordFound = true;

                        // Record found, ergo, break out of for loop
                        break;
                    }
                } // if (i_recordName)
                // Called did not pass in a record name, therefore collect all records
                else
                {
                    TRACSSCOMP( g_trac_vpd, INFO_MRK"IpVpdFacade::_getRecordMetaData(): "
                                "Collecting the record's %s meta data: record offset 0x%.4X, "
                                "record length %d, ecc offset 0x%.4X and ecc length %d",
                                l_recordMetaData->record_name,
                                le16toh(l_recordMetaData->record_offset),
                                le16toh(l_recordMetaData->record_length),
                                le16toh(l_recordMetaData->ecc_offset),
                                le16toh(l_recordMetaData->ecc_length) );

                    o_recordMetaDataList.push_back(*l_recordMetaData);
                }
            } // for (size_t l_vtocPtOffset = 0; ...

            if (l_recordFound)
            {
                break;
            }
        }; // for (uint16_t l_index(0); /* exit criteria in code */ ; ++l_index)

    } while (0);

    if ( unlikely(nullptr != l_err) )
    {
        // Clear the outgoing list
        o_recordMetaDataList.clear();
    }

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"IpVpdFacade::_getRecordMetaData(): "
                "returning %s errors on target 0x%.8X and record meta data list with %d entries",
                (l_err ? "with" : "with no"), TARGETING::get_huid(i_target),
                o_recordMetaDataList.size() );

    return l_err;
} // _getRecordMetaData


// ------------------------------------------------------------------
// IpVpdFacade::checkCreateEccDataReturnCode
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::checkCreateEccDataReturnCode(
                const size_t                     i_createEccDataReturnCode,
                const TARGETING::TargetHandle_t  i_target,
                const IpVpdFacade::input_args_t &i_args,
                const char *                     i_recordName,
                const uint16_t                   i_recordOffset,
                const uint16_t                   i_recordLength,
                const uint16_t                   i_eccOffset,
                const uint16_t                   i_eccLength )
{
    errlHndl_t l_err(nullptr);

    // Get a copy of the target huid, once, for tracing/logging purposes
    auto l_targetHuid = TARGETING::get_huid(i_target);

    if ( VPD_ECC_NOT_ENOUGH_BUFFER == i_createEccDataReturnCode )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkCreateEccDataReturnCode(): "
                   "vpdecc_create_ecc failed with error VPD_ECC_NOT_ENOUGH_BUFFER, "
                   "error code %d, for record %s on target 0x%.8X; record offset(0x%.4X), "
                   "record length(0x%.4X), ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_createEccDataReturnCode, i_recordName, l_targetHuid, i_recordOffset,
                   i_recordLength, i_eccOffset, i_eccLength );

        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_ECC_DATA_UPDATE
         * @reasoncode       VPD::VPD_ECC_DATA_ECC_SIZE_ISSUE
         * @userdata1[00:31] HUID of target
         * @userdata1[32:47] Record to create ECC data for
         * @userdata1[48:63] Error code returned from call to vpdecc_create_ecc
         * @userdata2[00:15] Record data offset
         * @userdata2[16:31] Record data length
         * @userdata2[32:47] ECC data offset
         * @userdata2[48:63] ECC data length
         * @devdesc          Buffer to store ECC data is not large enough
         * @custdesc         Firmware error updating the VPD
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD::VPD_IPVPD_ECC_DATA_UPDATE,
                            VPD::VPD_ECC_DATA_ECC_SIZE_ISSUE,
                            TWO_UINT32_TO_UINT64(
                                l_targetHuid,
                                TWO_UINT16_TO_UINT32(
                                    i_args.record,
                                    i_createEccDataReturnCode ) ),
                            FOUR_UINT16_TO_UINT64(
                                i_recordOffset,
                                i_recordLength,
                                i_eccOffset,
                                i_eccLength ),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
    }
    else if ( i_createEccDataReturnCode != VPD_ECC_OK  )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkCreateEccDataReturnCode(): "
                   "vpdecc_create_ecc failed with an UNKNOWN error %d "
                   "for record %s on target 0x%.8X; record offset(0x%.4X), "
                   "record length(0x%.4X), ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_createEccDataReturnCode, i_recordName, l_targetHuid, i_recordOffset,
                   i_recordLength, i_eccOffset, i_eccLength );

        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_ECC_DATA_UPDATE
         * @reasoncode       VPD::VPD_ECC_DATA_UNKNOWN_FAILURE
         * @userdata1[00:31] HUID of target
         * @userdata1[32:47] Record to create ECC data for
         * @userdata1[48:63] Error code returned from call to vpdecc_create_ecc
         * @userdata2[00:15] Record data offset
         * @userdata2[16:31] Record data length
         * @userdata2[32:47] ECC data offset
         * @userdata2[48:63] ECC data length
         * @devdesc          API vpdecc_create_ecc returned unknown error
         * @custdesc         Firmware error updating the VPD
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD::VPD_IPVPD_ECC_DATA_UPDATE,
                            VPD::VPD_ECC_DATA_UNKNOWN_FAILURE,
                            TWO_UINT32_TO_UINT64(
                                l_targetHuid,
                                TWO_UINT16_TO_UINT32(
                                    i_args.record,
                                    i_createEccDataReturnCode ) ),
                            FOUR_UINT16_TO_UINT64(
                                i_recordOffset,
                                i_recordLength,
                                i_eccOffset,
                                i_eccLength ),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
    }
    else
    {
        TRACSSCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkCreateEccDataReturnCode(): "
                   "vpdecc_create_ecc successfully updated ECC data for record %s "
                   "on target 0x%.8X; record offset(0x%.4X), record length(0x%.4X), "
                   "ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_recordName, l_targetHuid, i_recordOffset, i_recordLength,
                   i_eccOffset, i_eccLength );
    }

    return l_err;
} // checkCreateEccDataReturnCode

// ------------------------------------------------------------------
// IpVpdFacade::checkEccDataValidationReturnCode
// ------------------------------------------------------------------
errlHndl_t
IpVpdFacade::checkEccDataValidationReturnCode(
                const size_t                     i_eccDataValidationReturnCode,
                const TARGETING::TargetHandle_t  i_target,
                const IpVpdFacade::input_args_t &i_args,
                const char *                     i_recordName,
                const uint16_t                   i_recordOffset,
                const uint16_t                   i_recordLength,
                const uint16_t                   i_eccOffset,
                const uint16_t                   i_eccLength )
{
    errlHndl_t l_err(nullptr);

    // Get a copy of the target huid, once, for tracing/logging purposes
    auto l_targetHuid = TARGETING::get_huid(i_target);

    if ( VPD_ECC_WRONG_ECC_SIZE    == i_eccDataValidationReturnCode  ||
         VPD_ECC_WRONG_BUFFER_SIZE == i_eccDataValidationReturnCode     )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkEccDataValidationReturnCode(): "
                   "vpdecc_check_data failed with error VPD_ECC_WRONG_ECC_SIZE "
                   "or VPD_ECC_WRONG_BUFFER_SIZE, error code %d, for record %s on "
                   "target 0x%.8X; record offset(0x%.4X), record length(0x%.4X), "
                   "ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_eccDataValidationReturnCode, i_recordName, l_targetHuid, i_recordOffset,
                   i_recordLength, i_eccOffset, i_eccLength );

        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_ECC_DATA_CHECK
         * @reasoncode       VPD::VPD_ECC_DATA_ECC_SIZE_ISSUE
         * @userdata1[00:31] HUID of target
         * @userdata1[32:47] Record to validate ECC data for
         * @userdata1[48:63] Error code returned from call to vpdecc_check_data
         * @userdata2[00:15] Record data offset
         * @userdata2[16:31] Record data length
         * @userdata2[32:47] ECC data offset
         * @userdata2[48:63] ECC data length
         * @devdesc          There is an issue with the ECC data size
         * @custdesc         Firmware error checking the VPD
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD::VPD_IPVPD_ECC_DATA_CHECK,
                            VPD::VPD_ECC_DATA_ECC_SIZE_ISSUE,
                            TWO_UINT32_TO_UINT64(
                                l_targetHuid,
                                TWO_UINT16_TO_UINT32(
                                    i_args.record,
                                    i_eccDataValidationReturnCode ) ),
                            FOUR_UINT16_TO_UINT64(
                                i_recordOffset,
                                i_recordLength,
                                i_eccOffset,
                                i_eccLength ),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
    }
    else if (VPD_ECC_UNCORRECTABLE_DATA == i_eccDataValidationReturnCode)
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkEccDataValidationReturnCode(): "
                   "vpdecc_check_data failed with error VPD_ECC_UNCORRECTABLE_DATA, "
                   "error code %d, for record %s on target 0x%.8X; record offset(0x%.4X), "
                   "record length(0x%.4X), ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_eccDataValidationReturnCode, i_recordName, l_targetHuid, i_recordOffset,
                   i_recordLength, i_eccOffset, i_eccLength );

        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_ECC_DATA_CHECK
         * @reasoncode       VPD::VPD_ECC_DATA_UNCORRECTABLE_DATA
         * @userdata1[00:31] HUID of target
         * @userdata1[32:47] Record to validate ECC data for
         * @userdata1[48:63] Error code returned from call to vpdecc_check_data
         * @userdata2[00:15] Record data offset
         * @userdata2[16:31] Record data length
         * @userdata2[32:47] ECC data offset
         * @userdata2[48:63] ECC data length
         * @devdesc          Encountered an uncorrectable error with the VPD check
         * @custdesc         Firmware error checking the VPD
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD::VPD_IPVPD_ECC_DATA_CHECK,
                            VPD::VPD_ECC_DATA_UNCORRECTABLE_DATA,
                            TWO_UINT32_TO_UINT64(
                                l_targetHuid,
                                TWO_UINT16_TO_UINT32(
                                    i_args.record,
                                    i_eccDataValidationReturnCode ) ),
                            FOUR_UINT16_TO_UINT64(
                                i_recordOffset,
                                i_recordLength,
                                i_eccOffset,
                                i_eccLength ),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
    }
    else if (VPD_ECC_CORRECTABLE_DATA == i_eccDataValidationReturnCode)
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkEccDataValidationReturnCode(): "
                   "vpdecc_check_data failed with error VPD_ECC_CORRECTABLE_DATA, "
                   "error code %d, for record %s on target 0x%.8X; record offset(0x%.4X), "
                   "record length(0x%.4X), ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_eccDataValidationReturnCode, i_recordName, l_targetHuid, i_recordOffset,
                   i_recordLength, i_eccOffset, i_eccLength );
        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
         * @moduleid         VPD::VPD_IPVPD_ECC_DATA_CHECK
         * @reasoncode       VPD::VPD_ECC_DATA_CORRECTABLE_DATA
         * @userdata1[00:31] HUID of target
         * @userdata1[32:47] Record to validate ECC data for
         * @userdata1[48:63] Error code returned from call to vpdecc_check_data
         * @userdata2[00:15] Record data offset
         * @userdata2[16:31] Record data length
         * @userdata2[32:47] ECC data offset
         * @userdata2[48:63] ECC data length
         * @devdesc          Encountered a correctable error with the VPD check
         * @custdesc         A correctable firmware error checking the VPD
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            VPD::VPD_IPVPD_ECC_DATA_CHECK,
                            VPD::VPD_ECC_DATA_CORRECTABLE_DATA,
                            TWO_UINT32_TO_UINT64(
                                l_targetHuid,
                                TWO_UINT16_TO_UINT32(
                                    i_args.record,
                                    i_eccDataValidationReturnCode ) ),
                            FOUR_UINT16_TO_UINT64(
                                i_recordOffset,
                                i_recordLength,
                                i_eccOffset,
                                i_eccLength ),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
    }
    else if ( i_eccDataValidationReturnCode != VPD_ECC_OK  )
    {
        TRACFCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkEccDataValidationReturnCode(): "
                   "vpdecc_check_data failed with UNKNOWN error %d "
                   "for record %s on target 0x%.8X; record offset(0x%.4X), "
                   "record length(0x%.4X), ecc offset(0x%.4X), ecc length(0x%.4X)",
                   i_eccDataValidationReturnCode, i_recordName, l_targetHuid, i_recordOffset,
                   i_recordLength, i_eccOffset, i_eccLength );

        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_ECC_DATA_CHECK
         * @reasoncode       VPD::VPD_ECC_DATA_UNKNOWN_FAILURE
         * @userdata1[00:31] HUID of target
         * @userdata1[32:47] Record to validate ECC data for
         * @userdata1[48:63] Error code returned from call to vpdecc_check_data
         * @userdata2[00:15] Record data offset
         * @userdata2[16:31] Record data length
         * @userdata2[32:47] ECC data offset
         * @userdata2[48:63] ECC data length
         * @devdesc          API vpdecc_check_data returned an unknown error
         * @custdesc         Firmware error checking the VPD
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD::VPD_IPVPD_ECC_DATA_CHECK,
                            VPD::VPD_ECC_DATA_UNKNOWN_FAILURE,
                            TWO_UINT32_TO_UINT64(
                                l_targetHuid,
                                TWO_UINT16_TO_UINT32(
                                    i_args.record,
                                    i_eccDataValidationReturnCode ) ),
                            FOUR_UINT16_TO_UINT64(
                                i_recordOffset,
                                i_recordLength,
                                i_eccOffset,
                                i_eccLength ),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
    }
    else
    {
        TRACSSCOMP( g_trac_vpd, ERR_MRK"IpVpdFacade::checkEccDataValidationReturnCode(): "
                    "vpdecc_check_data successfully validated ECC data for record %s "
                    "on target 0x%.8X; record offset(0x%.4X), record length(0x%.4X), "
                    "ecc offset(0x%.4X), ecc length(0x%.4X)",
                    i_recordName, l_targetHuid, i_recordOffset, i_recordLength,
                    i_eccOffset, i_eccLength );
    }

    return l_err;
} // checkEccDataValidationReturnCode

