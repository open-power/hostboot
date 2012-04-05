/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/mvpd/mvpd.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file mvpd.C
 *
 * @brief Implementation of the MVPD device driver
 *
 */

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
#include <spd/spdif.H>
#include <mvpd/mvpdreasoncodes.H>
#include <mvpd/mvpdenums.H>

#include "mvpd.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
bool g_loadModule = true;
mutex_t g_mvpdMutex = MUTEX_INITIALIZER;

uint64_t g_mvpdPnorAddr = 0x0;

// By setting to false, allows debug at a later time by allowing to
// substitute a binary file (procmvpd.dat) into PNOR.
const bool g_readPNOR = true;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_mvpd = NULL;
TRAC_INIT( & g_trac_mvpd, "MVPD", 4096 );

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)


// ----------------------------------------------
// Defines
// ----------------------------------------------


namespace MVPD
{

/**
* @brief This function compares 2 mvpd record values.  Used for binary
*       search to find a match.
*
* @param[in] e1 - Entry 1 to be compared.
*
* @param[in] e2 - Entry 2 to be compared.
*
* @return bool - Whether or not the e2 value is larger than the e1 value.
*/
bool compareKeywords ( const mvpdKeywordInfo e1,
                       const mvpdKeywordInfo e2 );

/**
* @brief This function compares 2 mvpd keyword values.  Used for binary
*       search to find a match.
*
* @param[in] e1 - Entry 1 to be compared.
*
* @param[in] e2 - Entry 2 to be compared.
*
* @return bool - Whether or not the e2 value is larger than the e1 value.
 */
bool compareRecords ( const mvpdRecordInfo e1,
                      const mvpdRecordInfo e2 );

/**
 * @brief This function compares sizes to be sure buffers are large enough
 *      to handle the data to be put in them.  If it is not, it will return
 *      an error.
 *
 * @param[in] i_bufferSize - The size of the buffer to check.
 *
 * @param[in] i_expectedSize - The minimum size the buffer should be.
 *
 * @return errlHndl_t - An error log will be returned if the buffer is not
 *      large enough.
 */
errlHndl_t checkBufferSize( size_t i_bufferSize,
                            size_t i_expectedSize );


// Register with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::MVPD,
                       TARGETING::TYPE_PROC,
                       mvpdRead );
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::MVPD,
                       TARGETING::TYPE_PROC,
                       mvpdWrite );


// ------------------------------------------------------------------
// mvpdRead
// ------------------------------------------------------------------
errlHndl_t mvpdRead ( DeviceFW::OperationType i_opType,
                      TARGETING::Target * i_target,
                      void * io_buffer,
                      size_t & io_buflen,
                      int64_t i_accessType,
                      va_list i_args )
{
    errlHndl_t err = NULL;
    const char * recordName = NULL;
    const char * keywordName = NULL;
    uint16_t recordOffset = 0x0;
    input_args_t args;
    args.record = ((mvpdRecord)va_arg( i_args, uint64_t ));
    args.keyword = ((mvpdKeyword)va_arg( i_args, uint64_t ));

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdRead()" );

    do
    {
        // Get the Record/keyword names
        err = mvpdTranslateRecord( args.record,
                                   recordName );

        if( err )
        {
            break;
        }

        err = mvpdTranslateKeyword( args.keyword,
                                    keywordName );

        if( err )
        {
            break;
        }

        TRACSCOMP( g_trac_mvpd,
                   INFO_MRK"Read record (%s) and Keyword (%s)",
                   recordName, keywordName );

        // Get the offset of the record requested
        err = mvpdFindRecordOffset( recordName,
                                    recordOffset,
                                    i_target,
                                    args );

        if( err )
        {
            break;
        }

        // use record offset to find/read the keyword
        err = mvpdRetrieveKeyword( keywordName,
                                   recordName,
                                   recordOffset,
                                   i_target,
                                   io_buffer,
                                   io_buflen,
                                   args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdRead()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdWrite
// ------------------------------------------------------------------
errlHndl_t mvpdWrite ( DeviceFW::OperationType i_opType,
                       TARGETING::Target * i_target,
                       void * io_buffer,
                       size_t & io_buflen,
                       int64_t i_accessType,
                       va_list i_args )
{
    errlHndl_t err = NULL;
    input_args_t args;
    args.record = ((mvpdRecord)va_arg( i_args, uint64_t ));
    args.keyword = ((mvpdKeyword)va_arg( i_args, uint64_t ));

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdWrite()" );

    do
    {
        // TODO - This will be implemented with story 39177
        TRACFCOMP( g_trac_mvpd,
                   ERR_MRK"MVPD Writes are not supported yet!" );

        /*@
         * @errortype
         * @reasoncode       MVPD_OPERATION_NOT_SUPPORTED
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         MVPD_WRITE
         * @userdata1        Requested Record
         * @userdata2        Requested Keyword
         * @devdesc          MVPD Writes are not supported currently.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MVPD_WRITE,
                                       MVPD_OPERATION_NOT_SUPPORTED,
                                       args.record,
                                       args.keyword );

        break;
    } while( 0 );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdWrite()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdTranslateRecord
// ------------------------------------------------------------------
errlHndl_t mvpdTranslateRecord ( mvpdRecord i_record,
                                 const char *& o_record )
{
    errlHndl_t err = NULL;
    uint32_t arraySize = 0x0;

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdTranslateRecord()" );

    do
    {
        arraySize = (sizeof(mvpdRecords)/sizeof(mvpdRecords[0]));
        mvpdRecordInfo tmpRecord;
        tmpRecord.record = i_record;
        const mvpdRecordInfo * entry = std::lower_bound( mvpdRecords,
                                                         &mvpdRecords[arraySize],
                                                         tmpRecord,
                                                         compareRecords );

        if( ( entry == &mvpdRecords[arraySize] )||
            ( i_record != entry->record ) )
        {
            TRACFCOMP( g_trac_mvpd,
                       ERR_MRK"No matching Record (0x%04x) found!",
                       i_record );

            /*@
             * @errortype
             * @reasoncode       MVPD_RECORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         MVPD_TRANSLATE_RECORD
             * @userdata1        Record enumeration.
             * @userdata2        <UNUSED>
             * @devdesc          The record enumeration did not have a
             *                   corresponding string value.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MVPD_TRANSLATE_RECORD,
                                           MVPD_RECORD_NOT_FOUND,
                                           i_record,
                                           0x0 );

            break;
        }

        o_record = entry->recordName;
        TRACDCOMP( g_trac_mvpd,
                   "record name: %s",
                   entry->recordName );
    } while( 0 );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdTranslateRecord()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdTranslateKeyword
// ------------------------------------------------------------------
errlHndl_t mvpdTranslateKeyword ( mvpdKeyword i_keyword,
                                  const char *& o_keyword )
{
    errlHndl_t err = NULL;
    uint32_t arraySize = 0x0;

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdTranslateKeyword()" );

    do
    {
        arraySize = (sizeof(mvpdKeywords)/sizeof(mvpdKeywords[0]));
        mvpdKeywordInfo tmpKeyword;
        tmpKeyword.keyword = i_keyword;
        const mvpdKeywordInfo * entry = std::lower_bound( mvpdKeywords,
                                                          &mvpdKeywords[arraySize],
                                                          tmpKeyword,
                                                          compareKeywords );

        if( ( entry == &mvpdKeywords[arraySize] ) ||
            ( i_keyword != entry->keyword ) )
        {
            TRACFCOMP( g_trac_mvpd,
                       ERR_MRK"No matching Keyword found!" );

            /*@
             * @errortype
             * @reasoncode       MVPD_KEYWORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         MVPD_TRANSLATE_KEYWORD
             * @userdata1        Keyword Enumeration
             * @userdata2        <UNUSED>
             * @devdesc          The keyword enumeration did not have a
             *                   corresponding string value.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MVPD_TRANSLATE_KEYWORD,
                                           MVPD_KEYWORD_NOT_FOUND,
                                           i_keyword,
                                           0x0 );

            break;
        }

        o_keyword = entry->keywordName;
        TRACDCOMP( g_trac_mvpd,
                   "keyword name: %s",
                   entry->keywordName );
    } while( 0 );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdTranslateKeyword()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdFindRecordOffset
// ------------------------------------------------------------------
errlHndl_t mvpdFindRecordOffset ( const char * i_record,
                                  uint16_t & o_offset,
                                  TARGETING::Target * i_target,
                                  input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint64_t tmpOffset = 0x0;
    char record[RECORD_BYTE_SIZE] = { '\0' };
    uint16_t offset = 0x0;
    bool matchFound = false;

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdFindRecordOffset()" );

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
        while( ( tmpOffset < 0x100 ) &&
               !matchFound )
        {
            TRACDCOMP( g_trac_mvpd,
                       INFO_MRK"read offset: 0x%08x",
                       tmpOffset );

            // Read Record Name
            err = mvpdFetchData( tmpOffset,
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
                err = mvpdFetchData( tmpOffset,
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
        TRACFCOMP( g_trac_mvpd,
                   ERR_MRK"No matching Record (%s) found in TOC!",
                   i_record );

        /*@
         * @errortype
         * @reasoncode       MVPD_RECORD_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         MVPD_FIND_RECORD_OFFSET
         * @userdata1        Requested Record
         * @userdata2        Requested Keyword
         * @devdesc          The requested record was not found in the MVPD TOC.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MVPD_FIND_RECORD_OFFSET,
                                       MVPD_RECORD_NOT_FOUND,
                                       i_args.record,
                                       i_args.keyword );
        // Add trace to the log so we know what record was being requested.
        err->collectTrace( "MVPD" );
    }

    // Return the offset found, after byte swapping it.
    o_offset = le16toh( offset );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdFindRecordOffset()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdRetrieveKeyword
// ------------------------------------------------------------------
errlHndl_t mvpdRetrieveKeyword ( const char * i_keywordName,
                                 const char * i_recordName,
                                 uint16_t i_offset,
                                 TARGETING::Target * i_target,
                                 void * io_buffer,
                                 size_t & io_buflen,
                                 input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint16_t offset = i_offset;
    uint16_t recordSize = 0x0;
    uint16_t keywordSize = 0x0;
    char record[RECORD_BYTE_SIZE] = { '\0' };
    char keyword[KEYWORD_BYTE_SIZE] = { '\0' };
    bool matchFound = false;

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdRetrieveKeyword()" );

    do
    {
        // Read size of Record
        err = mvpdFetchData( offset,
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
        err = mvpdFetchData( offset,
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
            TRACFCOMP( g_trac_mvpd,
                       ERR_MRK"Record(%s) for offset (0x%04x) did not match "
                       "expected record(%s)!",
                       record,
                       i_offset,
                       i_recordName );

            /*@
             * @errortype
             * @reasoncode       MVPD_RECORD_MISMATCH
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         MVPD_RETRIEVE_KEYWORD
             * @userdata1        Current offset into MVPD
             * @userdata2        Start of Record offset
             * @devdesc          Record name does not match value expected for
             *                   offset read.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MVPD_RETRIEVE_KEYWORD,
                                           MVPD_RECORD_MISMATCH,
                                           offset,
                                           i_offset );
            // Add trace so we see what record was being compared
            err->collectTrace( "MVPD" );

            break;
        }

        // While size < size of record
        // Size of record is the input offset, plus the record size, plus
        // 2 bytes for the size value.
        while( ( offset < (recordSize + i_offset + RECORD_ADDR_BYTE_SIZE) ) )
        {
            TRACDCOMP( g_trac_mvpd,
                       INFO_MRK"Looking for keyword, reading offset: 0x%04x",
                       offset );

            // read keyword name (2 bytes)
            err = mvpdFetchData( offset,
                                 KEYWORD_BYTE_SIZE,
                                 keyword,
                                 i_target );
            offset += KEYWORD_BYTE_SIZE;

            if( err )
            {
                break;
            }

            TRACDCOMP( g_trac_mvpd,
                       INFO_MRK"Read keyword name: %s",
                       keyword );

            // Check if we're reading a '#' keyword.  They have a 2 byte size
            uint32_t keywordLength = KEYWORD_SIZE_BYTE_SIZE;
            bool isPoundKwd = false;
            if( !(memcmp( keyword, "#", 1 )) )
            {
                TRACDCOMP( g_trac_mvpd,
                           INFO_MRK"Reading # keyword, adding 1 byte to size "
                           "to read!" );
                isPoundKwd = true;
                keywordLength++;
            }

            // Read keyword size
            err = mvpdFetchData( offset,
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

            TRACDCOMP( g_trac_mvpd,
                       INFO_MRK"Read keyword size: 0x%04x",
                       keywordSize );

            // if keyword equal i_keywordName
            if( !(memcmp( keyword, i_keywordName, KEYWORD_BYTE_SIZE ) ) )
            {
                matchFound = true;

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
                err = mvpdFetchData( offset,
                                     keywordSize,
                                     io_buffer,
                                     i_target );

                if( err )
                {
                    break;
                }
                io_buflen = keywordSize;

                // found our match, break out
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
        TRACFCOMP( g_trac_mvpd,
                   ERR_MRK"No matching %s keyword found within %s record!",
                   i_keywordName,
                   i_recordName );

        /*@
         * @errortype
         * @reasoncode       MVPD_KEYWORD_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         MVPD_RETRIEVE_KEYWORD
         * @userdata1        Start of Record Offset
         * @userdata2[0:31]  Requested Record
         * @userdata2[32:63] Requested Keyword
         * @devdesc          Keyword was not found in Record starting at given
         *                   offset.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MVPD_RETRIEVE_KEYWORD,
                                       MVPD_KEYWORD_NOT_FOUND,
                                       i_offset,
                                       TWO_UINT32_TO_UINT64( i_args.record,
                                                             i_args.keyword ) );

        // Add trace so we know what Record/Keyword was missing
        err->collectTrace( "MVPD" );
    }

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdRetrieveKeyword()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdFetchData
// ------------------------------------------------------------------
errlHndl_t mvpdFetchData ( uint64_t i_byteAddr,
                           size_t i_numBytes,
                           void * o_data,
                           TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdFetchData()" );

    do
    {
        if( g_readPNOR )
        {
            // Call a function in the SPD code which does an identical thing,
            // but with different address offsets.  Saves us having to
            // duplicate the code between the 2 modules.
            SPD::pnorInformation info;
            info.sectionSize = MVPD_SECTION_SIZE;
            info.maxSections = MVPD_MAX_SECTIONS;
            info.pnorSection = PNOR::MODULE_VPD;
            info.pnorSide = PNOR::SIDELESS;
            err = SPD::readPNOR( i_byteAddr,
                                 i_numBytes,
                                 o_data,
                                 i_target,
                                 info,
                                 g_mvpdPnorAddr,
                                 &g_mvpdMutex );

            if( err )
            {
                break;
            }
        }
        else
        {
            err = mvpdReadBinaryFile( i_byteAddr,
                                      i_numBytes,
                                      o_data );

            if( err )
            {
                break;
            }
        }
    } while( 0 );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdFetchData()" );

    return err;
}


// ------------------------------------------------------------------
// mvpdReadBinaryFile
// ------------------------------------------------------------------
errlHndl_t mvpdReadBinaryFile ( uint64_t i_offset,
                                size_t i_numBytes,
                                void * o_data )
{
    errlHndl_t err = NULL;
    const char * fileName = "procmvpd.dat";
    const char * startAddr = NULL;
    size_t fileSize;

    TRACSSCOMP( g_trac_mvpd,
                ENTER_MRK"mvpdReadBinaryFile()" );

    do
    {
        if( g_loadModule )
        {
            mutex_lock( &g_mvpdMutex );

            if( g_loadModule )
            {
                // Load the file
                TRACUCOMP( g_trac_mvpd,
                           "Load file" );
                err = VFS::module_load( fileName );

                if( err )
                {
                    TRACFCOMP( g_trac_mvpd,
                               ERR_MRK"Error opening binary MVPD file: %s",
                               fileName );
                    mutex_unlock( &g_mvpdMutex );

                    break;
                }

                g_loadModule = false;
            }
            mutex_unlock( &g_mvpdMutex );
        }

        // Get the starting address of the file/module
        TRACUCOMP( g_trac_mvpd,
                   "Get starting address/size" );
        err = VFS::module_address( fileName,
                                   startAddr,
                                   fileSize );

        if( err )
        {
            TRACFCOMP( g_trac_mvpd,
                       ERR_MRK"Error getting starting address of binary MVPD "
                       "file: %s",
                       fileName );

            break;
        }

        // Check that we can read the amount of data we need to from the
        // file we just loaded
        TRACUCOMP( g_trac_mvpd,
                   "Check Size vs file size" );
        if( (i_offset + i_numBytes) > fileSize )
        {
            TRACFCOMP( g_trac_mvpd,
                       ERR_MRK"Unable to read %d bytes from %s at offset 0x%08x "
                       "because file size is only %d bytes!",
                       i_numBytes,
                       fileName,
                       i_offset,
                       fileSize );

            /*@
             * @errortype
             * @reasoncode       MVPD_INSUFFICIENT_FILE_SIZE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         MVPD_READ_BINARY_FILE
             * @userdata1        File Size
             * @userdata2[0:31]  Starting offset into file
             * @userdata2[32:63] Number of bytes to read
             * @devdesc          File is not sufficiently large to read number of
             *                   bytes at offset given without overrunning file.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MVPD_READ_BINARY_FILE,
                                           MVPD_INSUFFICIENT_FILE_SIZE,
                                           fileSize,
                                           TWO_UINT32_TO_UINT64( i_offset,
                                                                 fileSize ) );

            break;
        }

        // Retrieve the data requested
        TRACUCOMP( g_trac_mvpd,
                   "Copy data out of file" );
        memcpy( o_data, (startAddr + i_offset), i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_mvpd,
                EXIT_MRK"mvpdReadBinaryFile()" );

    return err;
}


// ------------------------------------------------------------------
// checkBufferSize
// ------------------------------------------------------------------
errlHndl_t checkBufferSize( size_t i_bufferSize,
                            size_t i_expectedSize )
{
    errlHndl_t err = NULL;

    if( !(i_bufferSize >= i_expectedSize) )
    {
        TRACFCOMP( g_trac_mvpd,
                   ERR_MRK"Buffer size (%d) is not larger than expected size "
                   "(%d)",
                   i_bufferSize,
                   i_expectedSize );

        /*@
         * @errortype
         * @reasoncode       MVPD_INSUFFICIENT_BUFFER_SIZE
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         MVPD_CHECK_BUFFER_SIZE
         * @userdata1        Buffer Size
         * @userdata2        Expected Buffer Size
         * @devdesc          Buffer size was not greater than or equal to
         *                   expected buffer size.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MVPD_CHECK_BUFFER_SIZE,
                                       MVPD_INSUFFICIENT_BUFFER_SIZE,
                                       i_bufferSize,
                                       i_expectedSize );
    }

    return err;
}


// ------------------------------------------------------------------
// compareRecords
// ------------------------------------------------------------------
bool compareRecords ( const mvpdRecordInfo e1,
                      const mvpdRecordInfo e2 )
{
    if( e2.record > e1.record )
        return true;
    else
        return false;
}


// ------------------------------------------------------------------
// compareKeywords
// ------------------------------------------------------------------
bool compareKeywords ( const mvpdKeywordInfo e1,
                       const mvpdKeywordInfo e2 )
{
    if( e2.keyword > e1.keyword )
        return true;
    else
        return false;
}


} // end namespace MVPD
