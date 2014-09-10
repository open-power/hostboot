/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ipvpd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#include <i2c/eepromif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/vpd_if.H>
#include <config.h>

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

static const uint64_t IPVPD_TOC_SIZE = 0x100;

/**
 * @brief  Constructor
 */
IpVpdFacade::IpVpdFacade(uint64_t i_vpdSectionSize,
                         uint64_t i_vpdMaxSections,
                         const  recordInfo* i_vpdRecords,
                         uint64_t i_recSize,
                         const  keywordInfo* i_vpdKeywords,
                         uint64_t i_keySize,
                         PNOR::SectionId i_pnorSection,
                         mutex_t i_mutex,
                         VPD::VPD_MSG_TYPE i_vpdMsgType )
:iv_vpdSectionSize(i_vpdSectionSize)
,iv_vpdMaxSections(i_vpdMaxSections)
,iv_vpdRecords(i_vpdRecords)
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
            break;
        }

        err = translateKeyword( i_args.keyword,
                                keywordName );

        if( err )
        {
            break;
        }

        TRACSCOMP( g_trac_vpd,
                   INFO_MRK"IpVpdFacade::read: Record (%s) and Keyword (%s)",
                   recordName, keywordName );

        // Get the offset of the record requested
        err = findRecordOffset( recordName,
                                recordOffset,
                                i_target,
                                i_args );

        if( err )
        {
            break;
        }

        // use record offset to find/read the keyword
        err = retrieveKeyword( keywordName,
                               recordName,
                               recordOffset,
                               0,
                               i_target,
                               io_buffer,
                               io_buflen,
                               i_args );

        if( err )
        {
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

        TRACSCOMP( g_trac_vpd,
                   INFO_MRK"IpVpdFacade::Write: Record (%s) and Keyword (%s)",
                   recordName, keywordName );

        // Get the offset of the record requested
        err = findRecordOffset( recordName,
                                recordOffset,
                                i_target,
                                i_args );

        if( err )
        {
            break;
        }

        // use record offset to find/write the keyword
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
// IpVpdFacade::translateRecord
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::translateRecord ( ipVpdRecord i_record,
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
            TRACFCOMP( g_trac_vpd,
                       ERR_MRK"IpVpdFacade::translateRecord: No matching Record (0x%04x) found!",
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

            err->collectTrace( "VPD", 256 );
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
errlHndl_t IpVpdFacade::translateKeyword ( ipVpdKeyword i_keyword,
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
            TRACFCOMP( g_trac_vpd,
                       ERR_MRK"IpVpdFacade::translateKeyword: No matching Keyword found!" );

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

            err->collectTrace( "VPD", 256 );
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
                                           TARGETING::Target * i_target,
                                           input_args_t i_args )
{
    errlHndl_t err = NULL;

    if ( iv_configInfo.vpdReadPNOR )
    {
        return findRecordOffsetPnor(i_record, o_offset, i_target, i_args);
    }
    else if ( iv_configInfo.vpdReadHW )
    {
        return findRecordOffsetSeeprom(i_record, o_offset, i_target, i_args);
    }
    else
    {
        TRACFCOMP( g_trac_vpd,
          ERR_MRK"IpVpdFacade::findRecordOffset:vpdReadPNOR and vpdReadHW false!");

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_READ_CONFIG_NOT_SET
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FIND_RECORD_OFFSET
         * @userdata1        Target HUID
         * @userdata2        <UNUSED>
         * @devdesc          Both VPD read PNOR and VPD read HW
         *                   configs are set to false
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FIND_RECORD_OFFSET,
                                       VPD::VPD_READ_CONFIG_NOT_SET,
                                       TARGETING::get_huid(i_target),
                                       0x0,
                                       true /*Add HB SW Callout*/ );
        err->collectTrace( "VPD", 256 );
    }
    return NULL;
}



// ------------------------------------------------------------------
// IpVpdFacade::hasVpdPresent
// ------------------------------------------------------------------
bool IpVpdFacade::hasVpdPresent( TARGETING::Target * i_target,
                                 uint64_t i_record,
                                 uint64_t i_keyword )
{
    errlHndl_t err = NULL;
    uint16_t recordOffset = 0x0;
    input_args_t i_args;
    bool vpdPresent = false;
    const char * recordName = NULL;
    const char * keywordName = NULL;

    i_args.record = i_record;
    i_args.keyword = i_keyword;

    do
    {
        //get the Recod/Keyword names
        err = translateRecord( i_args.record,
                               recordName );

        if( err )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"Error occured during translateRecord\
                        - IpVpdFacade::hasVpdPresent");
            break;
        }

        err = translateKeyword( i_args.keyword,
                                keywordName );

        if( err )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"Error occured during \
                            translateKeyword - IpVpdFacade::hasVpdPresent" );
            break;
        }

        vpdPresent = recordPresent( recordName,
                                recordOffset,
                                i_target );

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
                                 TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;
    uint64_t tmpOffset = 0x0;
    char record[RECORD_BYTE_SIZE] = { '\0' };
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
        //      byte 4 - 5: Size (byte swapped)
        //      byte 6 - 7: UNUSED
        // --------------------------------------
        while( ( tmpOffset < IPVPD_TOC_SIZE ) &&
               !matchFound )
        {
                //Read Record Name
                err = fetchData( tmpOffset,
                                 RECORD_BYTE_SIZE,
                                 record,
                                 i_target );
                tmpOffset += RECORD_BYTE_SIZE;

                if( err )
                {
                    break;
                }

                if( !(memcmp(record, i_record, RECORD_BYTE_SIZE )) )
                {
                    matchFound = true;

                    // Read the matching record's offset
                    err = fetchData( tmpOffset,
                                     RECORD_ADDR_BYTE_SIZE,
                                     &o_offset,
                                     i_target );
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
                                i_target );

    if( !matchFound )
    {
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::findRecordOffset: No matching\
                   Record (%s) found in TOC!",
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
        err->collectTrace( "VPD", 256 );
    }

    // Return the offset found, after byte swapping it.
    o_offset = le16toh( offset );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findRecordOffset()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::findRecordOffsetSeeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findRecordOffsetSeeprom ( const char * i_record,
                                                  uint16_t & o_offset,
                                                  TARGETING::Target * i_target,
                                                  input_args_t i_args )
{
    errlHndl_t err = NULL;
    char l_buffer[256] = { 0 };
    uint16_t offset = 0x0;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::findRecordOffsetSeeprom()" );

    // Skip the ECC data + large resource ID in the VHDR
    offset = VHDR_ECC_DATA_SIZE + VHDR_RESOURCE_ID_SIZE;

    // Read PT keyword from VHDR to find the VTOC.
    size_t pt_len = sizeof(l_buffer);
    err = retrieveKeyword( "PT", "VHDR", offset, 0, i_target, l_buffer,
                           pt_len, i_args );
    if (err) {
        return err;
    }

    TocPtRecord *toc_rec = reinterpret_cast<TocPtRecord*>(l_buffer);
    if (pt_len < sizeof(TocPtRecord) ||
        (memcmp(toc_rec->record_name, "VTOC",
                sizeof(toc_rec->record_name)) != 0))
    {
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::findRecordOffset: VHDR is invalid!");

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_RECORD_INVALID_VHDR
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FIND_RECORD_OFFSET_SEEPROM
         * @userdata1        VHDR length
         * @userdata2        Target HUID
         * @devdesc          The VHDR was invalid
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FIND_RECORD_OFFSET_SEEPROM,
                                       VPD::VPD_RECORD_INVALID_VHDR,
                                       pt_len,
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

        err->collectTrace( "VPD" );
        return err;
    }

    offset = le16toh( toc_rec->record_offset ) + 1;  // skip 'large resource'

    // Read the PT keyword(s) (there may be more than 1) from the VTOC to
    // find the requested record.
    bool found = false;
    for (uint16_t index = 0; !found; ++index)
    {
        pt_len = sizeof(l_buffer);
        err = retrieveKeyword( "PT", "VTOC", offset, index, i_target, l_buffer,
                               pt_len, i_args );
        if ( err ) {
            break;
        }

        // Scan through the VTOC PT keyword records looking for a record
        // name match.
        for (size_t vtoc_pt_offset = 0; vtoc_pt_offset < pt_len;
            vtoc_pt_offset += sizeof(TocPtRecord))
        {
            toc_rec = reinterpret_cast<TocPtRecord*>(l_buffer + vtoc_pt_offset);
            TRACUCOMP( g_trac_vpd, "Scanning record %s", toc_rec->record_name);

            if (memcmp(toc_rec->record_name, i_record,
                       sizeof(toc_rec->record_name)) == 0)
            {
                // Byte swap field on output, skip 'large resource' byte
                o_offset = le16toh( toc_rec->record_offset ) + 1;
                found = true;
                break;
            }
        }
    }

    if ( !found && err == NULL ) {
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::findRecordOffsetSeeprom: "
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
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
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

        err->collectTrace( "VPD" );
    }

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findRecordOffsetSeeprom()" );

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
                ENTER_MRK"IpVpdFacade::retrieveKeyword()" );

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
                         i_target );
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
// IpVpdFacade::fetchData
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::fetchData ( uint64_t i_byteAddr,
                                    size_t i_numBytes,
                                    void * o_data,
                                    TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    if ( iv_configInfo.vpdReadPNOR )
    {
        return fetchDataFromPnor( i_byteAddr, i_numBytes, o_data, i_target );
    }
    else if ( iv_configInfo.vpdReadHW )
    {
        return fetchDataFromEeprom( i_byteAddr, i_numBytes, o_data, i_target );
    }
    else
    {
        TRACFCOMP( g_trac_vpd,
          ERR_MRK"IpVpdFacade::fetchData:vpdReadPNOR and vpdReadHW false!");

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_READ_CONFIG_NOT_SET
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_IPVPD_FETCH_DATA
         * @userdata1        Target HUID
         * @userdata2        <UNUSED>
         * @devdesc          Both VPD read PNOR and VPD read HW
         *                   configs are set to false
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FETCH_DATA,
                                       VPD::VPD_READ_CONFIG_NOT_SET,
                                       TARGETING::get_huid(i_target),
                                       0x0,
                                       true /*Add HB SW Callout*/ );
        err->collectTrace( "VPD", 256 );
    }
    return NULL;
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
                ENTER_MRK"IpVpdFacade::fetchDataFromPnor()" );

    do
    {
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
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::fetchDataFromPnor()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::fetchDataFromEeprom
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::fetchDataFromEeprom ( uint64_t i_byteAddr,
                                              size_t i_numBytes,
                                              void * o_data,
                                              TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::fetchDataFromEeprom()" );

    do
    {
        // Need to read directly from target's EEPROM.
        err = DeviceFW::deviceOp( DeviceFW::READ,
                                  i_target,
                                  o_data,
                                  i_numBytes,
                                  DEVICE_EEPROM_ADDRESS(
                                      EEPROM::VPD_PRIMARY,
                                      i_byteAddr ) );
        if( err )
        {
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
                ENTER_MRK"IpVpdFacade::findKeywordAddr()" );

    do
    {
        // Read size of Record
        err = fetchData( offset,
                         RECORD_ADDR_BYTE_SIZE,
                         &recordSize,
                         i_target );
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
                         i_target );
        offset += RECORD_BYTE_SIZE;

        if( err )
        {
            break;
        }

        if( memcmp( record, i_recordName, RECORD_BYTE_SIZE ) )
        {
            TRACFCOMP( g_trac_vpd,
                       ERR_MRK"IpVpdFacade::findKeywordAddr: Record(%s) for offset (0x%04x) did not match expected record(%s)!",
                       record,
                       i_offset,
                       i_recordName );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_RECORD_MISMATCH
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_IPVPD_FIND_KEYWORD_ADDR
             * @userdata1        Current offset into VPD
             * @userdata2        Start of Record offset
             * @devdesc          Record name does not match value expected for
             *                   offset read.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_IPVPD_FIND_KEYWORD_ADDR,
                                           VPD::VPD_RECORD_MISMATCH,
                                           offset,
                                           i_offset );

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
            err->collectTrace( "VPD", 256 );

            break;
        }

        // While size < size of record
        // Size of record is the input offset, plus the record size, plus
        // 2 bytes for the size value.
        while( ( offset < (recordSize + i_offset + RECORD_ADDR_BYTE_SIZE) ) )
        {
            TRACDCOMP( g_trac_vpd,
                       INFO_MRK"IpVpdFacade::findKeywordAddr: Looking for keyword, reading offset: 0x%04x",
                       offset );

            // read keyword name (2 bytes)
            err = fetchData( offset,
                             KEYWORD_BYTE_SIZE,
                             keyword,
                             i_target );
            offset += KEYWORD_BYTE_SIZE;

            if( err )
            {
                break;
            }

            TRACDCOMP( g_trac_vpd,
                       INFO_MRK"IpVpdFacade::findKeywordAddr: Read keyword name: %s",
                       keyword );

            // Check if we're reading a '#' keyword.  They have a 2 byte size
            uint32_t keywordLength = KEYWORD_SIZE_BYTE_SIZE;
            bool isPoundKwd = false;
            if( !(memcmp( keyword, "#", 1 )) )
            {
                TRACDCOMP( g_trac_vpd,
                           INFO_MRK"IpVpdFacade::findKeywordAddr: Reading # keyword, adding 1 byte to size to read!" );
                isPoundKwd = true;
                keywordLength++;
            }

            // Read keyword size
            err = fetchData( offset,
                             keywordLength,
                             &keywordSize,
                             i_target );
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

            TRACDCOMP( g_trac_vpd,
                       INFO_MRK"IpVpdFacade::findKeywordAddr: Read keyword size: 0x%04x",
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
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::findKeywordAddr: No matching %s keyword found within %s record!",
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
        err->collectTrace( "VPD", 256 );
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
        if ( iv_configInfo.vpdWriteHW )
        {
            // @todo RTC 106884 - Need to handle vpd write to HW
        }
        if ( iv_configInfo.vpdWritePNOR )
        {
            // Setup info needed to write from PNOR
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
        }
        else
        {
            // No PNOR, just eat the write attempt.
            TRACFCOMP(g_trac_vpd, "VPD record %s:%s - write ignored",
                      i_keywordName, i_recordName);
            break;
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
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::checkBufferSize: Buffer size (%d) is not larger than expected size (%d)",
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

        err->collectTrace( "VPD", 256 );

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
