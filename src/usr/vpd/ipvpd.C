/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ipvpd.C $                                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <endian.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>

#include "vpd.H"
#include "ipvpd.H"

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
                               i_target,
                               io_buffer,
                               io_buflen,
                               i_args );

        if( err )
        {
            break;
        }

    } while( 0 );

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
                                           0x0 );

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
    uint64_t tmpOffset = 0x0;
    char record[RECORD_BYTE_SIZE] = { '\0' };
    uint16_t offset = 0x0;
    bool matchFound = false;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::findRecordOffset()" );

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
            TRACDCOMP( g_trac_vpd,
                       INFO_MRK"IpVpdFacade::findRecordOffset: read offset: 0x%08x",
                       tmpOffset );

            // Read Record Name
            err = fetchData( tmpOffset,
                             RECORD_BYTE_SIZE,
                             record,
                             i_target );
            tmpOffset += RECORD_BYTE_SIZE;

            if( err )
            {
                break;
            }

            if( !(memcmp( record, i_record, RECORD_BYTE_SIZE )) )
            {
                matchFound = true;

                // Read the matching records offset
                err = fetchData( tmpOffset,
                                 RECORD_ADDR_BYTE_SIZE,
                                 &offset,
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
    } while( 0 );

    if( !matchFound )
    {
        TRACFCOMP( g_trac_vpd,
                   ERR_MRK"IpVpdFacade::findRecordOffset: No matching Record (%s) found in TOC!",
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
        // Add trace to the log so we know what record was being requested.
        err->collectTrace( "VPD" );
    }

    // Return the offset found, after byte swapping it.
    o_offset = le16toh( offset );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::findRecordOffset()" );

    return err;
}


// ------------------------------------------------------------------
// IpVpdFacade::retrieveKeyword
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::retrieveKeyword ( const char * i_keywordName,
                                          const char * i_recordName,
                                          uint16_t i_offset,
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
                               (size_t)keywordSize );
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

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"IpVpdFacade::fetchData()" );

    do
    {
        // Call a function in the common VPD code 
        VPD::pnorInformation info;
        info.segmentSize = iv_vpdSectionSize;
        info.maxSegments = iv_vpdMaxSections;
        info.pnorSection = iv_pnorSection;
        info.pnorSide = PNOR::CURRENT_SIDE;
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
                EXIT_MRK"IpVpdFacade::fetchData()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::findKeywordAddr
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::findKeywordAddr ( const char * i_keywordName,
                                          const char * i_recordName,
                                          uint16_t i_offset,
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
    bool matchFound = false;

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
            // Add trace so we see what record was being compared
            err->collectTrace( "VPD" );

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
                matchFound = true;
                break;
            }
            else
            {
                // set offset to next keyword (based on current keyword size)
                offset += keywordSize;
            }
        }

        if( err ||
            matchFound )
        {
            break;
        }
    } while( 0 );

    // If keyword not found in expected Record, flag error.
    if( !matchFound &&
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
         * @userdata1        Start of Record Offset
         * @userdata2[0:31]  Requested Record
         * @userdata2[32:63] Requested Keyword
         * @devdesc          Keyword was not found in Record starting at given
         *                   offset.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_IPVPD_FIND_KEYWORD_ADDR,
                                       VPD::VPD_KEYWORD_NOT_FOUND,
                                       i_offset,
                                       TWO_UINT32_TO_UINT64( i_args.record,
                                                             i_args.keyword ) );

        // Add trace so we know what Record/Keyword was missing
        err->collectTrace( "VPD" );
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
                               keywordSize );
        if( err )
        {
            break;
        }

        // Setup info needed to write from PNOR
        VPD::pnorInformation info;
        info.segmentSize = iv_vpdSectionSize;
        info.maxSegments = iv_vpdMaxSections;
        info.pnorSection = iv_pnorSection;
        info.pnorSide = PNOR::CURRENT_SIDE;
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

        // Quick double-check that our constants agree with the values in the
        //  VPD message structure
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


    } while(0);

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"IpVpdFacade::writeKeyword()" );

    return err;
}

// ------------------------------------------------------------------
// IpVpdFacade::checkBufferSize
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::checkBufferSize( size_t i_bufferSize,
                                         size_t i_expectedSize )
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
