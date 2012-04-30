/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/spd/spd.C $
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
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <pnor/pnorif.H>
#include <spd/spdreasoncodes.H>
#include <spd/spdenums.H>
#include <algorithm>
#include "spd.H"
#include "spdDDR3.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
bool g_loadModule = true;

// This mutex is used to lock for writing/updating the global variables.
mutex_t g_spdMutex = MUTEX_INITIALIZER;

uint64_t g_spdPnorAddr = 0x0;

// By setting to false, allows debug at a later time by allowing to
// substitute a binary file (dimmspd.dat) into PNOR.
const bool g_usePNOR = true;

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

/**
 * @brief This function will read the DIMM memory type.
 *
 * @param[out] o_memType - The memory type value to return.
 *
 * @param[in] i_target - The target to read data from.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getMemType ( uint8_t & o_memType,
                        TARGETING::Target * i_target );

/**
 * @brief This function will scan the table and return the entry
 *      corresponding to the keyword being requested.
 *
 * @param[in] i_keyword - The keyword being requested.
 *
 * @param[in] i_memType - The memory type of the target.
 *
 * @param[out] o_entry - The table entry corresponding to the keyword.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t getKeywordEntry ( uint64_t i_keyword,
                             uint64_t i_memType,
                             KeywordData *& o_entry );


// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::SPD,
                       TARGETING::TYPE_DIMM,
                       spdGetKeywordValue );
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::SPD,
                       TARGETING::TYPE_DIMM,
                       spdWriteKeywordValue );

// ------------------------------------------------------------------
// spdGetKeywordValue
// ------------------------------------------------------------------
errlHndl_t spdGetKeywordValue ( DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void * io_buffer,
                                size_t & io_buflen,
                                int64_t i_accessType,
                                va_list i_args )
{
    errlHndl_t err = NULL;
    uint64_t keyword = va_arg( i_args, uint64_t );

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetKeywordValue(), io_buflen: %d, keyword: 0x%04x",
                io_buflen, keyword );

    do
    {
        // Read the Basic Memory Type
        uint8_t memType = 0x0;
        err = getMemType( memType,
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
            if( BASIC_MEMORY_TYPE == keyword )
            {
                io_buflen = MEM_TYPE_ADDR_SZ;
                memcpy( io_buffer, &memType, io_buflen );
                break;
            }

            // Read the keyword value
            err = spdGetValue( keyword,
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
                                           keyword );

            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdGetKeywordValue()" );

    return err;
}


// ------------------------------------------------------------------
// spdWriteKeywordValue
// ------------------------------------------------------------------
errlHndl_t spdWriteKeywordValue ( DeviceFW::OperationType i_opType,
                                  TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & io_buflen,
                                  int64_t i_accessType,
                                  va_list i_args )
{
    errlHndl_t err = NULL;
    uint64_t keyword = va_arg( i_args, uint64_t );

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteKeywordValue()" );

    do
    {
        // Get memory type
        uint8_t memType = 0x0;
        err = getMemType( memType,
                          i_target );

        if( err )
        {
            break;
        }

        // Check DDR3
        if( SPD_DDR3 == memType )
        {
            err = spdWriteValue( keyword,
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
             * @moduleid         SPD_WRITE_KEYWORD_VALUE
             * @userdata1        Basic Memory Type (Byte 2)
             * @userdata2        Keyword Requested
             * @devdesc          Invalid Basic Memory Type
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_WRITE_KEYWORD_VALUE,
                                           SPD_INVALID_BASIC_MEMORY_TYPE,
                                           memType,
                                           keyword );

            break;
        }
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
        if( likely( g_usePNOR ) )
        {
            // Setup info needed to read from PNOR
            pnorInformation info;
            info.segmentSize = DIMM_SPD_SECTION_SIZE;
            info.maxSegments = DIMM_SPD_MAX_SECTIONS;
            info.pnorSection = PNOR::DIMM_JEDEC_VPD;
            info.pnorSide = PNOR::SIDELESS;
            err = readPNOR( i_byteAddr,
                            i_numBytes,
                            o_data,
                            i_target,
                            info,
                            g_spdPnorAddr,
                            &g_spdMutex );

            if( err )
            {
                break;
            }
        }
        else
        {
            err = spdReadBinaryFile( i_byteAddr,
                                     i_numBytes,
                                     o_data );

            if( err )
            {
                break;
            }
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdFetchData()" );

    return err;
}


// ------------------------------------------------------------------
// spdWriteData
// ------------------------------------------------------------------
errlHndl_t spdWriteData ( uint64_t i_offset,
                          size_t i_numBytes,
                          void * i_data,
                          TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteData()" );

    do
    {
        if( likely( g_usePNOR ) )
        {
            // Setup info needed to write from PNOR
            pnorInformation info;
            info.segmentSize = DIMM_SPD_SECTION_SIZE;
            info.maxSegments = DIMM_SPD_MAX_SECTIONS;
            info.pnorSection = PNOR::DIMM_JEDEC_VPD;
            info.pnorSide = PNOR::SIDELESS;
            err = writePNOR( i_offset,
                             i_numBytes,
                             i_data,
                             i_target,
                             info,
                             g_spdPnorAddr,
                             &g_spdMutex );

            if( err )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"There is no way to write SPD when not using PNOR!" );

            /*@
             * @errortype
             * @reasoncode       SPD_INVALID_WRITE_METHOD
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_WRITE_DATA
             * @userdata1        Write Offset
             * @userdata2        Number of Bytes to Write
             * @devdesc          g_usePNOR is false, but there isn't an
             *                   alternate way to write PNOR.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_WRITE_DATA,
                                           SPD_INVALID_WRITE_METHOD,
                                           i_offset,
                                           i_numBytes );

            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteData()" );

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

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetValue()" );

    do
    {
        KeywordData * entry = NULL;
        err = getKeywordEntry( i_keyword,
                               i_DDRRev,
                               entry );

        if( err )
        {
            break;
        }

        // Check to be sure entry is not NULL.
        if( NULL == entry )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Entry Pointer is NULL!" );

            /*@
             * @errortype
             * @reasoncode       SPD_NULL_ENTRY
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_GET_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:31]  Buffer Size
             * @userdata2[32:63] Memory Type
             * @devdesc          The table entry associated with keyword was
             *                   NULL.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_VALUE,
                                           SPD_NULL_ENTRY,
                                           i_keyword,
                                           TWO_UINT32_TO_UINT64( io_buflen,
                                                                 i_DDRRev ) );

            break;
        }

        // Check if this is a module specific keyword and check that the
        // correct values are in place to actually request it
        err = checkModSpecificKeyword( (*entry),
                                       i_DDRRev,
                                       i_target );

        if( err )
        {
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
// spdWriteValue
// ------------------------------------------------------------------
errlHndl_t spdWriteValue ( uint64_t i_keyword,
                           void * io_buffer,
                           size_t & io_buflen,
                           TARGETING::Target * i_target,
                           uint64_t i_DDRRev )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteValue()" );

    do
    {
        KeywordData * entry = NULL;
        err = getKeywordEntry( i_keyword,
                               i_DDRRev,
                               entry );

        if( err )
        {
            break;
        }

        if( NULL == entry )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Entry pointer is NULL!" );

            /*@
             * @errortype
             * @reasoncode       SPD_NULL_ENTRY
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_WRITE_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:31]  Buffer Length
             * @userdata2[32:63] Memory Type
             * @devdesc          The table entry associated with keyword was
             *                   NULL.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_WRITE_VALUE,
                                           SPD_NULL_ENTRY,
                                           i_keyword,
                                           TWO_UINT32_TO_UINT64( io_buflen,
                                                                 i_DDRRev ) );

            break;
        }

        // Check write flag
        if( entry->writable )
        {
            // Check the Size to be equal to entry written
            err = spdCheckSize( io_buflen,
                                entry->length,
                                i_keyword );

            if( err )
            {
                break;
            }

            // Write value
            err = spdWriteData( entry->offset,
                                io_buflen,
                                io_buffer,
                                i_target );

            if( err )
            {
                break;
            }

            // Send mbox message with new data to Fsp
            err = spdSendMboxWriteMsg();

            if( err )
            {
                break;
            }
        }
        else
        {
            // Error if not writable
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Trying to write keyword (0x%04x) that is non-"
                       "writable",
                       i_keyword );

            /*@
             * @errortype
             * @reasoncode       SPD_KEYWORD_NOT_WRITABLE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_WRITE_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:31]  Buffer Length
             * @userdata2[32:63] Memory Type
             * @devdesc          The SPD Keyword is not writable.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_WRITE_VALUE,
                                           SPD_KEYWORD_NOT_WRITABLE,
                                           i_keyword,
                                           TWO_UINT32_TO_UINT64( io_buflen,
                                                                 i_DDRRev ) );

            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteValue()" );

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
                // ==================================================
                // 2 byte - LSB then MSB
                case CAS_LATENCIES_SUPPORTED:
                case TRFC_MIN:
                case MODULE_MANUFACTURER_ID:
                case DRAM_MANUFACTURER_ID:
                case RMM_MFR_ID_CODE:
                case LRMM_MFR_ID_CODE:
                    // Check Size of buffer
                    err = spdCheckSize( io_buflen,
                                        i_kwdData.length,
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
                    err = spdFetchData( (i_kwdData.offset - 1),
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = i_kwdData.length;
                    break;

                // ==================================================
                // 2 byte - MSB then LSB is 2 less than MSB
                case TRC_MIN:
                    // Check Size of buffer
                    err = spdCheckSize( io_buflen,
                                        i_kwdData.length,
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
                    err = spdFetchData( (i_kwdData.offset - 2),
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = i_kwdData.length;
                    break;

                // ==================================================
                // 2 byte - MSB then LSB
                case TRAS_MIN:
                case TFAW_MIN:
                    // Check size of buffer
                    err = spdCheckSize( io_buflen,
                                        i_kwdData.length,
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
                    err = spdFetchData( (i_kwdData.offset + 1),
                                        1, /* Read 1 byte at a time */
                                        &tmpBuffer[1],
                                        i_target );

                    if( err ) break;

                    // Set number of bytes read
                    io_buflen = i_kwdData.length;
                    break;

                // ==================================================
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
                   ERR_MRK"Buffer Size (%d) for keyword (0x%04x) wasn't greater "
                   "than or equal to expected size (%d)",
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
                                       TWO_UINT32_TO_UINT64( i_bufferSz,
                                                             i_expBufferSz ) );
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
// spdSendMboxWriteMsg
// ------------------------------------------------------------------
errlHndl_t spdSendMboxWriteMsg ( void )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdSendMboxWriteMsg()" );

    do
    {
        // TODO - Since all writes to SPD will be greather than 16 bytes,
        // there is a need for the "extra_data" option from mbox.  This is not
        // available as of yet.
        //
        // This will be implemented with Story 41365, which cannot be done
        // until story 34032 has been completed.
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdSendMboxWriteMsg()" );

    return err;
}


// ------------------------------------------------------------------
// readPNOR
// ------------------------------------------------------------------
errlHndl_t readPNOR ( uint64_t i_byteAddr,
                      size_t i_numBytes,
                      void * o_data,
                      TARGETING::Target * i_target,
                      pnorInformation & i_pnorInfo,
                      uint64_t &io_cachedAddr,
                      mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * readAddr = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"readPNOR()" );

    do
    {
        // Check if we have the PNOR addr cached.
        if( 0x0 == io_cachedAddr )
        {
            err = getPnorAddr( i_pnorInfo,
                               io_cachedAddr,
                               i_mutex );

            if( err )
            {
                break;
            }
        }
        addr = io_cachedAddr;

        // Find vpd location of the target
        err = getVpdLocation( vpdLocation,
                              i_target );

        if( err )
        {
            break;
        }

        // Offset cached address by vpd location multiplier
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Now offset into that chunk of data by i_byteAddr
        addr += i_byteAddr;

        TRACUCOMP( g_trac_spd,
                   INFO_MRK"Address to read: 0x%08x",
                   addr );

        // Pull the data
        readAddr = reinterpret_cast<const char*>( addr );
        memcpy( o_data,
                readAddr,
                i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"readPNOR()" );

    return err;
}


// ------------------------------------------------------------------
// writePNOR
// ------------------------------------------------------------------
errlHndl_t writePNOR ( uint64_t i_byteAddr,
                       size_t i_numBytes,
                       void * i_data,
                       TARGETING::Target * i_target,
                       pnorInformation & i_pnorInfo,
                       uint64_t &io_cachedAddr,
                       mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * writeAddr = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"writePNOR()" );

    do
    {
        // Check if we have the PNOR addr cached.
        if( 0x0 == io_cachedAddr )
        {
            err = getPnorAddr( i_pnorInfo,
                               io_cachedAddr,
                               i_mutex );

            if( err )
            {
                break;
            }
        }
        addr = io_cachedAddr;

        // Find vpd location of the target
        err = getVpdLocation( vpdLocation,
                              i_target );

        if( err )
        {
            break;
        }

        // Offset cached address by vpd location multiplier
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Now offset into that chunk of data by i_byteAddr
        addr += i_byteAddr;

        TRACUCOMP( g_trac_spd,
                   INFO_MRK"Address to write: 0x%08x",
                   addr );

        // Write the data
        writeAddr = reinterpret_cast<const char*>( addr );
        memcpy( (void*)(writeAddr),
                i_data,
                i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"writePNOR()" );

    return err;
}


// ------------------------------------------------------------------
// getPnorAddr
// ------------------------------------------------------------------
errlHndl_t getPnorAddr ( pnorInformation & i_pnorInfo,
                         uint64_t &io_cachedAddr,
                         mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    PNOR::SectionInfo_t info;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"getPnorAddr()" );

    do
    {
        // Get SPD PNOR section info from PNOR RP
        err = PNOR::getSectionInfo( i_pnorInfo.pnorSection,
                                    i_pnorInfo.pnorSide,
                                    info );

        if( err )
        {
            break;
        }

        // Check the Size
        uint32_t expectedSize = i_pnorInfo.segmentSize * i_pnorInfo.maxSegments;
        if( expectedSize != info.size )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"PNOR section actual size (0x%08x) is not "
                       "equal to expected size (0x%08x)!",
                       info.size,
                       expectedSize );

            /*@
             * @errortype
             * @reasoncode       SPD_SIZE_MISMATCH
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_GET_PNOR_ADDR
             * @userdata1[0:31]  PNOR RP provided size
             * @userdata1[32:63] Expected Size
             * @userdata2[0:31]  PNOR Section enum
             * @userdata2[32:63] PNOR Side enum
             * @devdesc
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_PNOR_ADDR,
                                           SPD_SIZE_MISMATCH,
                                           TWO_UINT32_TO_UINT64( info.size,
                                                                 expectedSize ),
                                           TWO_UINT32_TO_UINT64( i_pnorInfo.pnorSection,
                                                                 i_pnorInfo.pnorSide) );
            break;
        }

        // Set the globals appropriately
        mutex_lock( i_mutex );
        io_cachedAddr = info.vaddr;
        mutex_unlock( i_mutex );
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"getPnorAddr() - addr: 0x%08x",
                io_cachedAddr );

    return err;
}


// ------------------------------------------------------------------
// getVpdLocation
// ------------------------------------------------------------------
errlHndl_t getVpdLocation ( int64_t & o_vpdLocation,
                            TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"getVpdLocation()" );

    o_vpdLocation = i_target->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
    TRACUCOMP( g_trac_spd,
               INFO_MRK"Using VPD location: %d",
               o_vpdLocation );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"getVpdLocation()" );

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


// ------------------------------------------------------------------
// checkModSpecificKeyword
// ------------------------------------------------------------------
errlHndl_t checkModSpecificKeyword ( KeywordData i_kwdData,
                                     uint64_t i_memType,
                                     TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"checkModSpecificKeyword()" );

    do
    {
        // If not a Module Specific keyword, skip this logic
        if( NA == i_kwdData.modSpec )
        {
            break;
        }

        // To check the module specific flags, also need the Module Type value
        // from byte 3.
        uint8_t modType = 0x0;
        err = spdFetchData( MEM_TYPE_ADDR,
                            MEM_TYPE_ADDR_SZ,
                            &modType,
                            i_target );

        if( err )
        {
            break;
        }

        // Check Unbuffered Memory Module (UMM)
        if( (SPD_DDR3 == i_memType) &&
            ( (0x2 == modType) ||
              (0x3 == modType) ||
              (0x4 == modType) ||
              (0x6 == modType) ||
              (0x8 == modType) ||
              (0xc == modType) ||
              (0xd == modType) ) )
        {
            if( 0 == (i_kwdData.modSpec & UMM) )
            {
                TRACFCOMP( g_trac_spd,
                           ERR_MRK"Keyword (0x%04x) is not valid with UMM modules!",
                           i_kwdData.keyword );

                /*@
                 * @errortype
                 * @reasoncode       SPD_MOD_SPECIFIC_MISMATCH_UMM
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         SPD_CHECK_MODULE_SPECIFIC_KEYWORD
                 * @userdata1[0:31]  Module Type (byte 3[3:0])
                 * @userdata1[32:63] Memory Type (byte 2)
                 * @userdata2[0:31]  SPD Keyword
                 * @userdata2[32:63] Module Specific flag
                 * @devdesc          Keyword requested was not UMM Module specific.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               SPD_CHECK_MODULE_SPECIFIC_KEYWORD,
                                               SPD_MOD_SPECIFIC_MISMATCH_UMM,
                                               TWO_UINT32_TO_UINT64( modType, i_memType ),
                                               TWO_UINT32_TO_UINT64( i_kwdData.keyword,
                                                                     i_kwdData.modSpec ) );

                break;
            }
        }
        // Check Registered Memory Module (RMM)
        else if( (SPD_DDR3 == i_memType) &&
                 ( (0x1 == modType) ||
                   (0x5 == modType) ||
                   (0x9 == modType) ) )
        {
            if( 0 == (i_kwdData.modSpec & RMM) )
            {
                TRACFCOMP( g_trac_spd,
                           ERR_MRK"Keyword (0x%04x) is not valid with RMM modules!",
                           i_kwdData.keyword );

                /*@
                 * @errortype
                 * @reasoncode       SPD_MOD_SPECIFIC_MISMATCH_RMM
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         SPD_CHECK_MODULE_SPECIFIC_KEYWORD
                 * @userdata1[0:31]  Module Type (byte 3[3:0])
                 * @userdata1[32:63] Memory Type (byte 2)
                 * @userdata2[0:31]  SPD Keyword
                 * @userdata2[32:63] Module Specific flag
                 * @devdesc          Keyword requested was not RMM Module specific.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               SPD_CHECK_MODULE_SPECIFIC_KEYWORD,
                                               SPD_MOD_SPECIFIC_MISMATCH_RMM,
                                               TWO_UINT32_TO_UINT64( modType, i_memType ),
                                               TWO_UINT32_TO_UINT64( i_kwdData.keyword,
                                                                     i_kwdData.modSpec ) );

                break;
            }
        }
        // Check Clocked Memory Module (CMM)
        else if( (SPD_DDR3 == i_memType) &&
                 ( (0x7 == modType) ||
                   (0xa == modType) ) )
        {
            if( 0 == (i_kwdData.modSpec & CMM) )
            {
                TRACFCOMP( g_trac_spd,
                           ERR_MRK"Keyword (0x%04x) is not valid with CMM modules!",
                           i_kwdData.keyword );

                /*@
                 * @errortype
                 * @reasoncode       SPD_MOD_SPECIFIC_MISMATCH_CMM
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         SPD_CHECK_MODULE_SPECIFIC_KEYWORD
                 * @userdata1[0:31]  Module Type (byte 3[3:0])
                 * @userdata1[32:63] Memory Type (byte 2)
                 * @userdata2[0:31]  SPD Keyword
                 * @userdata2[32:63] Module Specific flag
                 * @devdesc          Keyword requested was not CMM Module specific.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               SPD_CHECK_MODULE_SPECIFIC_KEYWORD,
                                               SPD_MOD_SPECIFIC_MISMATCH_CMM,
                                               TWO_UINT32_TO_UINT64( modType, i_memType ),
                                               TWO_UINT32_TO_UINT64( i_kwdData.keyword,
                                                                     i_kwdData.modSpec ) );

                break;
            }
        }
        // Check Load Reduction Memory Module (LRMM)
        else if( (SPD_DDR3 == i_memType) &&
                 ( (0xb == modType) ) )
        {
            if( 0 == (i_kwdData.modSpec & LRMM) )
            {
                TRACFCOMP( g_trac_spd,
                           ERR_MRK"Keyword (0x%04x) is not valid with LRMM modules!",
                           i_kwdData.keyword );

                /*@
                 * @errortype
                 * @reasoncode       SPD_MOD_SPECIFIC_MISMATCH_LRMM
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         SPD_CHECK_MODULE_SPECIFIC_KEYWORD
                 * @userdata1[0:31]  Module Type (byte 3[3:0])
                 * @userdata1[32:63] Memory Type (byte 2)
                 * @userdata2[0:31]  SPD Keyword
                 * @userdata2[32:63] Module Specific flag
                 * @devdesc          Keyword requested was not LRMM Module specific.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               SPD_CHECK_MODULE_SPECIFIC_KEYWORD,
                                               SPD_MOD_SPECIFIC_MISMATCH_LRMM,
                                               TWO_UINT32_TO_UINT64( modType, i_memType ),
                                               TWO_UINT32_TO_UINT64( i_kwdData.keyword,
                                                                     i_kwdData.modSpec ) );

                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Module specific keyword could not be matched with an "
                       "appropriate scenario!" );
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"  Mem Type: 0x%04x, Mod Type: 0x%04x, Keyword: 0x%04x",
                       i_memType,
                       modType,
                       i_kwdData.keyword );

            /*@
             * @errortype
             * @reasoncode       SPD_MOD_SPECIFIC_UNSUPPORTED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_CHECK_MODULE_SPECIFIC_KEYWORD
             * @userdata1[0:31]  Module Type (byte 3[3:0])
             * @userdata1[32:63] Memory Type (byte 2)
             * @userdata2[0:31]  SPD Keyword
             * @userdata2[32:63] Module Specific flag
             * @devdesc          Unsupported Module Specific setup.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_CHECK_MODULE_SPECIFIC_KEYWORD,
                                           SPD_MOD_SPECIFIC_UNSUPPORTED,
                                           TWO_UINT32_TO_UINT64( modType, i_memType ),
                                           TWO_UINT32_TO_UINT64( i_kwdData.keyword,
                                                                 i_kwdData.modSpec ) );

            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"checkModSpecificKeyword()" );

    return err;
}


// ------------------------------------------------------------------
// getMemType
// ------------------------------------------------------------------
errlHndl_t getMemType ( uint8_t & o_memType,
                        TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    err = spdFetchData( MEM_TYPE_ADDR,
                        MEM_TYPE_ADDR_SZ,
                        &o_memType,
                        i_target );

    TRACUCOMP( g_trac_spd,
               "SPD::getMemType() - MemType: 0x%02x, Error: %s",
               o_memType,
               ((NULL == err) ? "No" : "Yes") );

    return err;
}


// ------------------------------------------------------------------
// getKeywordEntry
// ------------------------------------------------------------------
errlHndl_t getKeywordEntry ( uint64_t i_keyword,
                             uint64_t i_memType,
                             KeywordData *& o_entry )
{
    errlHndl_t err = NULL;
    KeywordData * kwdData;
    uint32_t arraySize = 0x0;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"getKeywordEntry()" );

    do
    {
        if( SPD_DDR3 == i_memType )
        {
            // Put the table into an array
            arraySize = (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
            kwdData = ddr3Data;
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unsupported DDRx Revision (0x%04x)",
                       i_memType );

            /*@
             * @errortype
             * @reasoncode       SPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         SPD_GET_KEYWORD_ENTRY
             * @userdata1        SPD Keyword
             * @userdata2        The DDR Revision
             * @devdesc          Invalid DDR Revision
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_KEYWORD_ENTRY,
                                           SPD_INVALID_BASIC_MEMORY_TYPE,
                                           i_keyword,
                                           i_memType );

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
             * @moduleid         SPD_GET_KEYWORD_ENTRY
             * @userdata1        SPD Keyword
             * @userdata2        <UNUSED>
             * @devdesc          Invalid SPD Keyword
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SPD_GET_KEYWORD_ENTRY,
                                           SPD_KEYWORD_NOT_FOUND,
                                           i_keyword,
                                           0x0 );

            break;
        }

        o_entry = entry;
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"getKeywordEntry()" );

    return err;
}


} // end namespace SPD
