//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/spd/spd.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file spd.C
 *
 * @brief Implementation of the SPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <spd/spdreasoncodes.H>
#include <spd/spdenums.H>
#include <algorithm>
#include "spd.H"
#include "spdDDR3.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
bool g_loadModule = true;
mutex_t g_spdMutex = MUTEX_INITIALIZER;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_spd = NULL;
TRAC_INIT( & g_trac_spd, "SPD", 4096 );

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)


// ----------------------------------------------
// Defines
// ----------------------------------------------


namespace SPD
{

/**
* @brief Compare two values and return whether e2 is greater than
*       the e1 value.  This is used during lower_bound to cut
*       search time down.
*
* @param[in] e1 - Structure to be searched, using the Keyword
*       value in that structure.
*
* @param[in] e2 - Structure to be searched, using the Keyword
*       value in that structure.
*
* @return boolean - Whether or not e2.keyword is larger than
*       e1.keyword.
*/
bool compareEntries ( const KeywordData e1,
                      const KeywordData e2 );

// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SPD,
                       TARGETING::TYPE_DIMM,
                       spdAccess );

// ------------------------------------------------------------------
// spdRead
// ------------------------------------------------------------------
errlHndl_t spdAccess( DeviceFW::OperationType i_opType,
                      TARGETING::Target * i_target,
                      void * io_buffer,
                      size_t & io_buflen,
                      int64_t i_accessType,
                      va_list i_args )
{
    errlHndl_t err = NULL;
    uint64_t keyword = va_arg( i_args, uint64_t );

    if( DeviceFW::READ == i_opType )
    {
        // Read the SPD keyword
        err = spdGetKeywordValue( keyword,
                                  io_buffer,
                                  io_buflen,
                                  i_target );
    }
    else
    {
        // Write the SPD keyword
        err = spdWriteKeywordValue( keyword,
                                    io_buffer,
                                    io_buflen,
                                    i_target );
    }

    return err;
} // end spdRead


// ------------------------------------------------------------------
// spdGetKeywordValue
// ------------------------------------------------------------------
errlHndl_t spdGetKeywordValue ( uint64_t i_keyword,
                                void * io_buffer,
                                size_t & io_buflen,
                                TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetKeywordValue(), io_buflen: %d, keyword: 0x%04x",
                io_buflen, i_keyword );

    do
    {
        // Read the Basic Memory Type
        uint8_t memType = 0x0;
        err = spdFetchData( MEM_TYPE_ADDR,
                            MEM_TYPE_ADDR_SZ,
                            &memType,
                            i_target );

        if( err )
        {
            break;
        }

        TRACDCOMP( g_trac_spd,
                   INFO_MRK"Mem Type: %04x",
                   memType );

        // Check the Basic Memory Type to be sure its valid before
        // continuing.
        if( SPD_DDR3 == memType )
        {
            // If the user wanted the Basic memory type, return this now.
            if( BASIC_MEMORY_TYPE == i_keyword )
            {
                io_buflen = MEM_TYPE_ADDR_SZ;
                memcpy( io_buffer, &memType, io_buflen );
                break;
            }

            // Read the keyword value
            err = spdGetValue( i_keyword,
                                   io_buffer,
                                   io_buflen,
                                   i_target,
                                   memType );

            if( err )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Invalid Basic Memory Type (0x%04x)",
                       memType );

            /*@
             * @errortype
             * @reasoncode       SPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_GET_KEYWORD_VALUE
             * @userdata1        Basic Memory Type (Byte 2)
             * @userdata2        Keyword Requested
             * @devdesc          Invalid Basic Memory Type
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_KEYWORD_VALUE,
                                           SPD_INVALID_BASIC_MEMORY_TYPE,
                                           memType,
                                           i_keyword );
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdGetKeywordValue()" );

    return err;
}


// ------------------------------------------------------------------
// spdWriteKeywordValue
// ------------------------------------------------------------------
errlHndl_t spdWriteKeywordValue ( uint64_t i_keyword,
                                  void * io_buffer,
                                  size_t & io_buflen,
                                  TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteKeywordValue()" );

    do
    {
        // TODO - This will be implemented with story 4659
        TRACFCOMP( g_trac_spd,
                   ERR_MRK"SPD writes are not supported yet!" );

        /*@
         * @errortype
         * @reasoncode       SPD_NOT_SUPPORTED
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         SPD_WRITE_KEYWORD_VALUE
         * @userdata1        i_keyword
         * @userdata2        <UNUSED>
         * @devdesc          SPD Writes are not supported yet.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       SPD_WRITE_KEYWORD_VALUE,
                                       SPD_NOT_SUPPORTED,
                                       i_keyword,
                                       0x0 );
        break;
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteKeywordValue()" );

    return err;
}


// ------------------------------------------------------------------
// spdFetchData
// ------------------------------------------------------------------
errlHndl_t spdFetchData ( uint64_t i_byteAddr,
                          size_t i_numBytes,
                          void * o_data,
                          TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdFetchData()" );

    do
    {
        // ---------------------------------------------------------------
        // TODO - For now, we will use a generic name of dimmspd.dat, and
        // access the file via vfs for all SPD content for ALL DIMMs.
        //
        // Unfortunately Fsp will not be able to write into our file
        // space in PNOR because the files/names will need to be signed.
        // This means that eventually there will be block of data in PNOR
        // where each DIMMs, and potential DIMM, information will be at
        // a given offset.
        // ---------------------------------------------------------------

        err = spdReadBinaryFile( i_byteAddr,
                                 i_numBytes,
                                 o_data );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdFetchData()" );

    return err;
}


// ------------------------------------------------------------------
// spdGetValue
// ------------------------------------------------------------------
errlHndl_t spdGetValue ( uint64_t i_keyword,
                         void * io_buffer,
                         size_t & io_buflen,
                         TARGETING::Target * i_target,
                         uint64_t i_DDRRev )
{
    errlHndl_t err = NULL;
    uint8_t * tmpBuffer = static_cast<uint8_t *>(io_buffer);
    KeywordData * kwdData;
    uint32_t arraySize = 0x0;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetValue()" );

    do
    {
        if( SPD_DDR3 == i_DDRRev )
        {
            // Put the table into an array
            arraySize = (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
            kwdData = ddr3Data;
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unsupported DDRx Revision (0x%04x)",
                       i_DDRRev );

            /*@
             * @errortype
             * @reasoncode       SPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_GET_VALUE
             * @userdata1        SPD Keyword
             * @userdata2        The DDR Revision
             * @devdesc          Invalid DDR Revision
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_VALUE,
                                           SPD_INVALID_BASIC_MEMORY_TYPE,
                                           i_keyword,
                                           i_DDRRev );

            break;
        }

        // Set the searching structure equal to the keyword we're looking for.
        KeywordData tmpKwdData;
        tmpKwdData.keyword = i_keyword;
        KeywordData * entry = std::lower_bound( kwdData,
                                              &kwdData[arraySize],
                                              tmpKwdData,
                                              compareEntries );

        if( ( entry == &kwdData[arraySize] ) ||
            ( i_keyword != entry->keyword ) )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"No matching keyword entry found!" );

            /*@
             * @errortype
             * @reasoncode       SPD_KEYWORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_GET_VALUE
             * @userdata1        SPD Keyword
             * @userdata2        <UNUSED>
             * @devdesc          Invalid SPD Keyword
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_VALUE,
                                           SPD_KEYWORD_NOT_FOUND,
                                           i_keyword,
                                           0x0 );

            break;
        }

        if( entry->isSpecialCase )
        {
            // Handle special cases where data isn't sequential
            // or is in reverse order from what would be read.
            err = spdSpecialCases( (*entry),
                                   io_buffer,
                                   io_buflen,
                                   i_target,
                                   i_DDRRev );

            break;
        }

        // Check io_buflen versus size in table
        err = spdCheckSize( io_buflen,
                            (*entry).length,
                            i_keyword );

        if( err )
        {
            break;
        }

        // Read length requested
        err = spdFetchData( (*entry).offset,
                            (*entry).length,
                            tmpBuffer,
                            i_target );

        if( err )
        {
            break;
        }

        // if useBitmask set, mask and then shift data
        if( (*entry).useBitMask )
        {
            // Any bit mask/shifting will always be on a <1 Byte value
            // thus, we touch only byte 0.
            tmpBuffer[0] = tmpBuffer[0] & (*entry).bitMask;
            tmpBuffer[0] = tmpBuffer[0] >> (*entry).shift;
        }

        // Set length read
        io_buflen = (*entry).length;
    } while( 0 );

    if( err )
    {
        // Signal the caller that there was an error getting
        // data and that there is no valid data.
        io_buflen = 0;
    }

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdGetValue()" );

    return err;
}


// ------------------------------------------------------------------
// spdSpecialCases
// ------------------------------------------------------------------
errlHndl_t spdSpecialCases ( KeywordData i_kwdData,
                             void * io_buffer,
                             size_t & io_buflen,
                             TARGETING::Target * i_target,
                             uint64_t i_DDRRev )
{
    errlHndl_t err = NULL;
    uint8_t * tmpBuffer = static_cast<uint8_t *>(io_buffer);

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdSpecialCases()" );

    do
    {
        // Handle each of the special cases here
        if( SPD_DDR3 == i_DDRRev )
        {
            switch( i_kwdData.keyword )
            {
                case CAS_LATENCIES_SUPPORTED:
                    // Length 2 bytes
                    // Byte 0x0e [7:0]
                    // Byte 0x0f [6:0] - MSB

                    // Check Size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Mask and shift if needed
                    if( i_kwdData.useBitMask )
                    {
                        tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                        tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
                    }

                    // Get LSB
                    err = spdFetchData( 0x0e,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                case TRC_MIN:
                    // Length 2 bytes
                    // Byte 0x15 [7:4] - MSB
                    // Byte 0x17 [7:0]

                    // Check Size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Mask and shift if needed
                    if( i_kwdData.useBitMask )
                    {
                        tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                        tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
                    }

                    // Get LSB
                    err = spdFetchData( 0x17,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                case TRAS_MIN:
                    // Length 2 bytes
                    // Byte 0x15 [3:0] - MSB
                    // Byte 0x16 [7:0]

                    // Check size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Mask and shift if needed
                    if( i_kwdData.useBitMask )
                    {
                        tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                        tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
                    }

                    // Get LSB
                    err = spdFetchData( 0x16,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                case TRFC_MIN:
                    // Length 2 bytes
                    // Byte 0x18 [7:0]
                    // Byte 0x19 [7:0] - MSB

                    // Check size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Get LSB
                    err = spdFetchData( 0x18,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                case TFAW_MIN:
                    // Length 2 bytes
                    // Byte 0x1c [3:0] - MSB
                    // byte 0x1d [7:0]

                    // Check size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Mask and shift if needed
                    if( i_kwdData.useBitMask )
                    {
                        tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                        tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
                    }

                    // Get LSB
                    err = spdFetchData( 0x1d,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                case MODULE_MANUFACTURER_ID:
                    // Length 2 bytes
                    // Byte 0x75 [7:0]
                    // Byte 0x76 [7:0] - MSB

                    // Check size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Get LSB
                    err = spdFetchData( 0x75,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                case DRAM_MANUFACTURER_ID:
                    // Length 2 bytes
                    // Byte 0x94 [7:0]
                    // Byte 0x95 [7:0] - MSB

                    // Check size of buffer
                    err = spdCheckSize( io_buflen,
                                        2,
                                        i_kwdData.keyword );

                    if( err ) break;

                    // Get MSB
                    err = spdFetchData( i_kwdData.offset,
                                        1, /*Read 1 byte at a time */
                                        &tmpBuffer[0],
                                        i_target );

                    if( err ) break;

                    // Get LSB
                    err = spdFetchData( 0x94,
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = 2;
                    break;

                default:
                    TRACFCOMP( g_trac_spd,
                               ERR_MRK"Unknown keyword (0x%04x) for DDR3 special cases!",
                               i_kwdData.keyword );

                    /*@
                     * @errortype
                     * @reasoncode       SPD_INVALID_SPD_KEYWORD
                     * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                     * @moduleid         SPD_SPECIAL_CASES
                     * @userdata1        SPD Keyword
                     * @userdata2        UNUSED
                     * @devdesc          Keyword is not a special case keyword.
                     */
                    err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                   SPD_SPECIAL_CASES,
                                                   SPD_INVALID_SPD_KEYWORD,
                                                   i_kwdData.keyword,
                                                   0x0 );
                    break;
            };
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unsupported DDRx Revision (0x%04x)",
                       i_DDRRev );

            /*@
             * @errortype
             * @reasoncode       SPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_SPECIAL_CASES
             * @userdata1        SPD Keyword
             * @userdata2        DIMM DDR Revision
             * @devdesc          Invalid DDR Revision
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_SPECIAL_CASES,
                                           SPD_INVALID_BASIC_MEMORY_TYPE,
                                           i_kwdData.keyword,
                                           i_DDRRev );

            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdSpecialCases()" );

    return err;
}


// ------------------------------------------------------------------
// spdCheckSize
// ------------------------------------------------------------------
errlHndl_t spdCheckSize ( size_t i_bufferSz,
                          size_t i_expBufferSz,
                          uint64_t i_keyword )
{
    errlHndl_t err = NULL;

    // Check that the buffer is greater than or equal to the size
    // we need to get all the keyword data requested.
    if( i_bufferSz < i_expBufferSz )
    {
        TRACFCOMP( g_trac_spd,
                   ERR_MRK"Buffer Size (%d) for keyword (0x%04x) wasn't greater than "
                   "or equal to expected size (%d)",
                   i_bufferSz, i_keyword, i_expBufferSz );

        /*@
         * @errortype
         * @reasoncode       SPD_INSUFFICIENT_BUFFER_SIZE
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         SPD_CHECK_SIZE
         * @userdata1        Keyword
         * @userdata2[0:31]  Needed Buffer Size
         * @userdata2[32:63] Expected Buffer Size
         * @devdesc          Buffer Size provided was not big enough for
         *                   the keyword requested.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       SPD_CHECK_SIZE,
                                       SPD_INSUFFICIENT_BUFFER_SIZE,
                                       i_keyword,
                                       TWO_UINT32_TO_UINT64( i_bufferSz, i_expBufferSz ) );
    }

    return err;
}


// ------------------------------------------------------------------
// spdReadBinaryFile
// ------------------------------------------------------------------
errlHndl_t spdReadBinaryFile ( uint64_t i_byteAddr,
                               size_t i_numBytes,
                               void * o_data )
{
    errlHndl_t err = NULL;
    const char * fileName = "dimmspd.dat";
    const char * startAddr = NULL;
    size_t fileSize;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdReadBinaryFile()" );

    do
    {
        if( g_loadModule )
        {
            mutex_lock( &g_spdMutex );

            if( g_loadModule )
            {
                // Load the file
                TRACUCOMP( g_trac_spd,
                           "Load file" );
                err = VFS::module_load( fileName );

                if( err )
                {
                    TRACFCOMP( g_trac_spd,
                               ERR_MRK"Error opening binary SPD file: %s",
                               fileName );
                    mutex_unlock( &g_spdMutex );

                    break;
                }

                g_loadModule = false;
            }
            mutex_unlock( &g_spdMutex );
        }

        // Get the starting address of the file/module
        TRACUCOMP( g_trac_spd,
                   "Get starting address/size" );
        err = VFS::module_address( fileName,
                                   startAddr,
                                   fileSize );

        if( err )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Error getting starting address of binary SPD file: %s",
                       fileName );

            break;
        }

        // Check that we can read the amount of data we need to from the
        // file we just loaded
        TRACUCOMP( g_trac_spd,
                   "Check Size vs file size" );
        if( (i_byteAddr + i_numBytes) > fileSize )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unable to read %d bytes from %s at offset 0x%08x "
                       "because file size is only %d bytes!",
                       i_numBytes,
                       fileName,
                       i_byteAddr,
                       fileSize );
            uint64_t tmpData = (i_byteAddr + i_numBytes);
            tmpData = tmpData << 16;
            tmpData = tmpData & (fileSize & 0xFFFF);

            /*@
             * @errortype
             * @reasoncode       SPD_INSUFFICIENT_FILE_SIZE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_READ_BINARY_FILE
             * @userdata1        File Size
             * @userdata2[0:48]  Starting offset into file
             * @userdata2[49:63] Number of bytes to read
             * @devdesc          File is not sufficiently large to read number of
             *                   bytes at offset given without overrunning file.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_READ_BINARY_FILE,
                                           SPD_INSUFFICIENT_FILE_SIZE,
                                           fileSize,
                                           tmpData );

            break;
        }

        // Retrieve the data requested
        TRACUCOMP( g_trac_spd,
                   "Copy data out of file" );
        memcpy( o_data, (startAddr + i_byteAddr), i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdReadBinaryFile()" );

    return err;
}


// ------------------------------------------------------------------
// compareEntries
// ------------------------------------------------------------------
bool compareEntries ( const KeywordData e1,
                      const KeywordData e2 )
{
    // e1 is the iterator value
    // e2 is the search value
    TRACUCOMP( g_trac_spd,
               INFO_MRK"e1: 0x%04x, e2: 0x%04x",
               e1.keyword,
               e2.keyword );
    if( e2.keyword > e1.keyword )
    {
        return true;
    }
    else
    {
        return false;
    }
}


} // end namespace SPD
