/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/spd.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
/* [+] Evan Lojewski                                                      */
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
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <devicefw/userif.H>
#include <eeprom/eepromif.H>
#include <vfs/vfs.H>
#include <pnor/pnorif.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>
#include <algorithm>
#include "spd.H"
#include "ocmb_spd.H"
#include "spdDDR3.H"
#include "spdDDR4.H"
#include "spdDDR4_DDIMM.H"
#include "errlud_vpd.H"
#include "ocmb_spd.H"
#include <targeting/targplatutil.H>     // assertGetToplevelTarget

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_spd = nullptr;
TRAC_INIT( & g_trac_spd, "SPD", KILOBYTE );

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

// Define where to read/write SPD data
#ifdef CONFIG_DJVPD_READ_FROM_PNOR
    static bool g_spdReadPNOR = true;
#else
    static bool g_spdReadPNOR = false;
#endif
#ifdef CONFIG_DJVPD_READ_FROM_HW
    static bool g_spdReadHW = true;
#else
    static bool g_spdReadHW = false;
#endif
#ifdef CONFIG_DJVPD_WRITE_TO_PNOR
    static bool g_spdWritePNOR = true;
#else
    static bool g_spdWritePNOR = false;
#endif
#ifdef CONFIG_DJVPD_WRITE_TO_HW
    static bool g_spdWriteHW = true;
#else
    static bool g_spdWriteHW = false;
#endif

/**
* @brief Determine if the given DIMM type is a known DIMM type or not
*
* @param[in] i_dimmType - The DIMM to verify if valid
*
* @return boolean - return true if given parameter is a known DIMM type,
*                   false otherwise
*/
bool isValidDimmType ( uint8_t i_dimmType );

/**
  * @brief Determines if the given DIMM type is a known DIMM type or not by
  *        calling the correct isValidDimmType function for OCMB_SPD or SPD.
  *
  * @param[in] i_dimmType   - The DIMM to verify if valid
  *
  * @param[in] i_eepromType - The eeprom content type of the DIMM
  *
  * @return boolean - return true if given paramter is a known DIMM type,
  *                   false otherwise
  */
bool isValidDimmType(uint8_t i_dimmType,
                     TARGETING::EEPROM_CONTENT_TYPE i_eepromType);


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
 * @param[out] o_memType     - The memory type value to return.
 *
 * @param[in] i_target       - The target to read data from.
 *
 * @param[in] i_location     - The SPD source (PNOR/SEEPROM).
 *
 * @param[in] i_eepromSource - The EEPROM source (CACHE/HARDWARE).
 *                             Default to AUTOSELECT.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getMemType(uint8_t & o_memType,
                     TARGETING::Target * i_target,
                     VPD::vpdCmdTarget i_location,
                     EEPROM::EEPROM_SOURCE i_eepromSource = EEPROM::AUTOSELECT);

/**
 * @brief This function will read the DIMM memory type by calling the correct
 *        function given the eeprom content type.
 *
 * @param[out] o_memType     - The memory type value to return.
 *
 * @param[in] i_target       - The target to read data from.
 *
 * @param[in] i_eepromType   - The Eeprom content type of the target.
 *
 * @param[in] i_eepromSource - The EEPROM source (CACHE/HARDWARE).
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getMemType(uint8_t &                     o_memType,
                     TARGETING::Target *            i_target,
                     TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                     EEPROM::EEPROM_SOURCE          i_eepromSource);

/**
 * @brief This function will read the DIMM module type.
 *
 * @param[out] o_modType - The module type value to return.
 *
 * @param[in] i_target - The target to read data from.
 *
 * @param[in] i_memType - The memory type
 *
 * @param[in] i_location - The SPD source (PNOR/SEEPROM).
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getModType ( modSpecTypes_t & o_modType,
                        TARGETING::Target * i_target,
                        uint64_t i_memType,
                        VPD::vpdCmdTarget i_location );

/**
 * @brief This function will set the size of SPD for the given target based on
 *        the DIMM type.
 *
 * @param [in/out] io_target - DIMM target
 *
 * @param [in]     i_dimmType - The DIMMs type (DDR3, DDR4, etc)
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdSetSize ( TARGETING::Target &io_target,
                        uint8_t            i_dimmType);


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
// isValidDimmType
// ------------------------------------------------------------------
bool isValidDimmType ( const uint8_t i_dimmType )
{
    return ( ( SPD_DDR3_TYPE == i_dimmType ) ||
             ( SPD_DDR4_TYPE == i_dimmType ) );
}


bool isValidDimmType(uint8_t i_memType,
                     TARGETING::EEPROM_CONTENT_TYPE i_eepromType)
{
    bool isValid = false;

// TODO RTC:204341 Add support for reading/write EECACHE during runtime
#ifndef __HOSTBOOT_RUNTIME
    if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_ISDIMM)
    {
        isValid = isValidDimmType(i_memType);
    }
    else if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_DDIMM)
    {
        isValid = isValidOcmbDimmType(i_memType);
    }

#endif

    return isValid;
}


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
    errlHndl_t err{nullptr};
    VPD::vpdKeyword keyword = va_arg( i_args, uint64_t );
    VPD::vpdCmdTarget location = (VPD::vpdCmdTarget)va_arg( i_args, uint64_t );

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetKeywordValue(), io_buflen: %d, keyword: 0x%04x",
                io_buflen, keyword );

    do
    {
        // Read the Basic Memory Type
        uint8_t memType(MEM_TYPE_INVALID);
        err = getMemType( memType,
                          i_target,
                          location );

        if( err )
        {
            break;
        }

        TRACDCOMP( g_trac_spd,
                   INFO_MRK"Mem Type: %04x",
                   memType );

        // Check the Basic Memory Type
        if ( isValidDimmType(memType) )
        {
            // If the user wanted the Basic memory type, return this now.
            if( BASIC_MEMORY_TYPE == keyword )
            {
                io_buflen = MEM_TYPE_SZ;
                if (io_buffer != nullptr)
                {
                    memcpy( io_buffer, &memType, io_buflen );
                }
                break;
            }

            // Read the keyword value
            err = spdGetValue( keyword,
                               io_buffer,
                               io_buflen,
                               i_target,
                               memType,
                               location );

            if( err )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Invalid Basic Memory Type (0x%04x), "
                       "target huid = 0x%x",
                       memType,
                       TARGETING::get_huid(i_target));

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_GET_KEYWORD_VALUE
             * @userdata1        Basic Memory Type (Byte 2)
             * @userdata2        Keyword Requested
             * @devdesc          Invalid Basic Memory Type
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_GET_KEYWORD_VALUE,
                                           VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                           memType,
                                           keyword );

            // User could have installed a bad/unsupported dimm
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( "SPD", 256);

            break;
        }
    } while( 0 );

    // If there is an error, add parameter info to log
    if ( err != nullptr )
    {
        VPD::UdVpdParms( i_target,
                         io_buflen,
                         0,
                         keyword,
                         true ) // read
                       .addToLog(err);
    }

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdGetKeywordValue(): returning %s errors",
                (err ? "with" : "with no") );

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
    errlHndl_t err{nullptr};
    VPD::vpdKeyword keyword = va_arg( i_args, uint64_t );
    VPD::vpdCmdTarget location =
            (VPD::vpdCmdTarget)va_arg( i_args, uint64_t );

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteKeywordValue()" );

    do
    {
        // Get memory type
        uint8_t memType(MEM_TYPE_INVALID);
        err = getMemType( memType,
                          i_target,
                          location );

        if( err )
        {
            break;
        }

        // Check the Basic Memory Type
        if ( isValidDimmType(memType) )
        {
            err = spdWriteValue( keyword,
                                 io_buffer,
                                 io_buflen,
                                 i_target,
                                 memType,
                                 location );

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
             * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_WRITE_KEYWORD_VALUE
             * @userdata1        Basic Memory Type (Byte 2)
             * @userdata2        Keyword Requested
             * @devdesc          Invalid Basic Memory Type
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_WRITE_KEYWORD_VALUE,
                                           VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                           memType,
                                           keyword );

            // User could have installed a bad/unsupported dimm
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( "SPD", 256);

            break;
        }
    } while( 0 );

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        VPD::UdVpdParms( i_target,
                         io_buflen,
                         0,
                         keyword,
                         false ) // write
                       .addToLog(err);
    }


    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteKeywordValue(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdFetchData
// ------------------------------------------------------------------
errlHndl_t spdFetchData ( uint64_t              i_byteAddr,
                          size_t                i_numBytes,
                          void                * o_data,
                          TARGETING::Target   * i_target,
                          VPD::vpdCmdTarget     i_location,
                          EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdFetchData()" );

    do
    {
        if( unlikely( !g_usePNOR ) )
        {
            err = spdReadBinaryFile( i_byteAddr,
                                     i_numBytes,
                                     o_data );
            break;
        }

        // Determine the SPD source (PNOR/SEEPROM)
        VPD::vpdCmdTarget vpdSource = VPD::AUTOSELECT;
        bool configError = false;
        configError = VPD::resolveVpdSource( i_target,
                                             g_spdReadPNOR,
                                             g_spdReadHW,
                                             i_location,
                                             vpdSource );

        // Get the data
        if ( vpdSource == VPD::PNOR )
        {
#ifdef CONFIG_DJVPD_READ_FROM_PNOR
            // Setup info needed to read from PNOR
            VPD::pnorInformation info;
            info.segmentSize = DIMM_SPD_SECTION_SIZE;
            info.maxSegments = DIMM_SPD_MAX_SECTIONS;
            info.pnorSection = PNOR::DIMM_JEDEC_VPD;
            err = VPD::readPNOR( i_byteAddr,
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
#else
            assert( false, "spdFetchData> No PNOR support" );
#endif
        }
        else if ( vpdSource == VPD::SEEPROM )
        {
#ifdef CONFIG_DJVPD_READ_FROM_HW
            // Need to read directly from target's EEPROM.
            err = DeviceFW::deviceOp( DeviceFW::READ,
                                      i_target,
                                      o_data,
                                      i_numBytes,
                                      DEVICE_EEPROM_ADDRESS(
                                          EEPROM::VPD_AUTO,
                                          i_byteAddr,
                                          i_eepromSource));
            if( err )
            {
                TRACFCOMP(g_trac_spd,
                        "ERROR: failing out of deviceOp in spd.C");
                break;
            }
#else
            assert( false, "spdFetchData> No HW support" );
#endif
        }
        else
        {
            TRACFCOMP(g_trac_spd, "spdFetchData: vpd source incorrect!: %x", vpdSource);
            configError = true;
        }

        if( configError )
        {
            TRACFCOMP( g_trac_spd, ERR_MRK"spdFetchData: "
                       "Error resolving VPD source (PNOR/SEEPROM)");

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_READ_SOURCE_UNRESOLVED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_FETCH_DATA
             * @userdata1[0:31]  Target HUID
             * @userdata1[32:63] Requested VPD Source Location
             * @userdata2[0:31]  SPD read PNOR flag
             * @userdata2[32:63] SPD read HW flag
             * @devdesc          Unable to resolve the VPD
             *                   source (PNOR or SEEPROM)
             */
            err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        VPD::VPD_SPD_FETCH_DATA,
                        VPD::VPD_READ_SOURCE_UNRESOLVED,
                        TWO_UINT32_TO_UINT64( TARGETING::get_huid(i_target),
                                              i_location ),
                        TWO_UINT32_TO_UINT64( g_spdReadPNOR,
                                              g_spdReadHW ),
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            err->collectTrace( "VPD", 256 );
            break;
        }

    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdFetchData(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdWriteData
// ------------------------------------------------------------------
errlHndl_t spdWriteData ( uint64_t i_offset,
                          size_t i_numBytes,
                          void * i_data,
                          TARGETING::Target * i_target,
                          VPD::vpdCmdTarget i_location )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteData()" );

    do
    {
        if( g_spdWriteHW )
        {
            if( i_location != VPD::PNOR )
            {
                // Write directly to target's EEPROM.
                err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                          i_target,
                                          i_data,
                                          i_numBytes,
                                          DEVICE_EEPROM_ADDRESS(
                                              EEPROM::VPD_AUTO,
                                              i_offset,
                                              EEPROM::AUTOSELECT) );
                if( err )
                {
                    break;
                }
            }
        }
        if( g_spdWritePNOR )
        {
            if( i_location != VPD::SEEPROM )
            {
#ifdef CONFIG_DJVPD_WRITE_TO_PNOR
                // Setup info needed to write to PNOR
                VPD::pnorInformation info;
                info.segmentSize = DIMM_SPD_SECTION_SIZE;
                info.maxSegments = DIMM_SPD_MAX_SECTIONS;
                info.pnorSection = PNOR::DIMM_JEDEC_VPD;
                err = VPD::writePNOR( i_offset,
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
#else
                assert( false, "spdWriteData> No PNOR support" );
#endif
            }
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteData(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdGetValue
// ------------------------------------------------------------------
errlHndl_t spdGetValue(VPD::vpdKeyword       i_keyword,
                       void                * io_buffer,
                       size_t              & io_buflen,
                       TARGETING::Target   * i_target,
                       uint64_t              i_DDRRev,
                       VPD::vpdCmdTarget     i_location,
                       EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};
    uint8_t * tmpBuffer = static_cast<uint8_t *>(io_buffer);

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetValue()" );

    do
    {
        const KeywordData * entry{nullptr};
        err = getKeywordEntry( i_keyword,
                               i_DDRRev,
                               i_target,
                               entry );

        if( err )
        {
            break;
        }

        // Check to be sure entry is not NULL.
        if( nullptr == entry )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Entry Pointer is NULL!" );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_NULL_ENTRY
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_GET_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:31]  Buffer Size
             * @userdata2[32:63] Memory Type
             * @devdesc          The table entry associated with keyword was
             *                   NULL.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_GET_VALUE,
                                           VPD::VPD_NULL_ENTRY,
                                           i_keyword,
                                           TWO_UINT32_TO_UINT64( io_buflen,
                                                                 i_DDRRev ),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Check if this is a module specific keyword and check that the
        // correct values are in place to actually request it
        err = checkModSpecificKeyword( (*entry),
                                       i_DDRRev,
                                       i_target,
                                       i_location );

        if( err )
        {
            break;
        }

        // Support passing in NULL buffer to return VPD field size
        if ( nullptr == io_buffer )
        {
            io_buflen = (*entry).length;
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

        if( entry->isSpecialCase )
        {
            // Handle special cases where data isn't sequential
            // or is in reverse order from what would be read.
            err = spdSpecialCases( (*entry),
                                   io_buffer,
                                   i_target,
                                   i_DDRRev,
                                   i_location );

            if (err)
            {
                break;
            }
        }
        else
        {
            // Read length requested
            err = spdFetchData( (*entry).offset,
                                (*entry).length,
                                tmpBuffer,
                                i_target,
                                i_location );

            if( err )
            {
                break;
            }

            // if useBitmask set, mask and then shift data
            if( (*entry).bitMask )
            {
                // Any bit mask/shifting is only applied to the first byte
                tmpBuffer[0] = tmpBuffer[0] & (*entry).bitMask;
                tmpBuffer[0] = tmpBuffer[0] >> (*entry).shift;
            }
        }

        // Set length read to the size in the table
        io_buflen = (*entry).length;
    } while( 0 );

    if( err )
    {
        // Signal the caller that there was an error getting
        // data and that there is no valid data.
        io_buflen = 0;
    }

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdGetValue(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdWriteValue
// ------------------------------------------------------------------
errlHndl_t spdWriteValue ( VPD::vpdKeyword i_keyword,
                           void * io_buffer,
                           size_t & io_buflen,
                           TARGETING::Target * i_target,
                           uint64_t i_DDRRev,
                           VPD::vpdCmdTarget i_location )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteValue()" );

    do
    {
        const KeywordData * entry{nullptr};
        err = getKeywordEntry( i_keyword,
                               i_DDRRev,
                               i_target,
                               entry );

        if( err )
        {
            break;
        }

        if( nullptr == entry )
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Entry pointer is NULL!" );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_NULL_ENTRY
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_WRITE_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:31]  Buffer Length
             * @userdata2[32:63] Memory Type
             * @devdesc          The table entry associated with keyword was
             *                   NULL.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_WRITE_VALUE,
                                           VPD::VPD_NULL_ENTRY,
                                           i_keyword,
                                           TWO_UINT32_TO_UINT64( io_buflen,
                                                                 i_DDRRev ),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Check write flag
        if( !(entry->writable) )
        {
            // Error if not writable
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Trying to write keyword (0x%04x) that is non-"
                       "writable",
                       i_keyword );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_KEYWORD_NOT_WRITABLE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_WRITE_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:31]  Buffer Length
             * @userdata2[32:63] Memory Type
             * @devdesc          The SPD Keyword is not writable.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_WRITE_VALUE,
                                           VPD::VPD_KEYWORD_NOT_WRITABLE,
                                           i_keyword,
                                           TWO_UINT32_TO_UINT64( io_buflen,
                                                                 i_DDRRev ),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Check the Size to be equal to entry written
        err = spdCheckSize( io_buflen,
                            entry->length,
                            i_keyword );

        if( err )
        {
            break;
        }

        // We are not handling writes that are not on a byte
        //   boundary until we absolutely need to.  There are
        //   no writable keywords that are not on byte boundaries
        if( entry->bitMask )
        {
            // Error if not writable
            TRACFCOMP( g_trac_spd, ERR_MRK"spdWriteValue: "
                       "Trying to write keyword (0x%04x) that is not "
                       "a full byte size",
                       i_keyword );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_UNSUPPORTED_WRITE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_WRITE_VALUE
             * @userdata1        SPD Keyword
             * @userdata2[0:15]  Keyword Length (in bytes)
             * @userdata2[16:31] Keyword Bitmask
             * @userdata2[32:63] Memory Type
             * @devdesc          Writes to non-byte SPD keywords are
             *                   unsupported.
             * @custdesc         A problem occurred during the IPL of
             *                   the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_WRITE_VALUE,
                                           VPD::VPD_UNSUPPORTED_WRITE,
                                           i_keyword,
                                           TWO_UINT16_ONE_UINT32_TO_UINT64(
                                                      entry->length,
                                                      entry->bitMask,
                                                      i_DDRRev ),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Write value
        err = spdWriteData( entry->offset,
                            io_buflen,
                            io_buffer,
                            i_target,
                            i_location );

        if( err )
        {
            break;
        }

        // Don't send mbox msg for seeprom
        if ( i_location == VPD::SEEPROM )
        {
            break;
        }

        if( !g_spdWriteHW )
        {
            // Send mbox message with new data to Fsp
            VPD::VpdWriteMsg_t msgdata;
            msgdata.rec_num = i_target->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
            //XXXX=offset relative to whole section
            memcpy( msgdata.record, "XXXX", sizeof(msgdata.record) );
            msgdata.offset = entry->offset;
            err = VPD::sendMboxWriteMsg( io_buflen,
                                         io_buffer,
                                         i_target,
                                         VPD::VPD_WRITE_DIMM,
                                         msgdata );
            if( err )
            {
                break;
            }
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteValue(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}

// ------------------------------------------------------------------
// spdSetSize
// ------------------------------------------------------------------
errlHndl_t spdSetSize ( TARGETING::Target &io_target,
                        const uint8_t      i_dimmType)
{
    TRACSSCOMP( g_trac_spd, ENTER_MRK"spdSetSize(): setting DIMM SPD(0x%X) size for"
                " target(0x%X)", i_dimmType, TARGETING::get_huid(&io_target) );

    errlHndl_t l_err{nullptr};

    do
    {
        if ( SPD_DDR3_TYPE == i_dimmType )
        {
            io_target.setAttr<TARGETING::ATTR_DIMM_SPD_BYTE_SIZE>(SPD_DDR3_SIZE);
            TRACSSCOMP( g_trac_spd, "found DIMM w/ HUID 0x%.08X to be type "
                        "DDR3, set ATTR_DIMM_SPD_BYTE_SIZE to be %d",
                        TARGETING::get_huid(&io_target),
                        io_target.getAttr<TARGETING::ATTR_DIMM_SPD_BYTE_SIZE>() );

        }
        else if ( SPD_DDR4_TYPE == i_dimmType )
        {
            io_target.setAttr<TARGETING::ATTR_DIMM_SPD_BYTE_SIZE>(SPD_DDR4_SIZE);
            TRACSSCOMP( g_trac_spd, "found DIMM w/ HUID 0x%.08X to be type "
                        "DDR4, set ATTR_DIMM_SPD_BYTE_SIZE to be %d",
                        TARGETING::get_huid(&io_target),
                        io_target.getAttr<TARGETING::ATTR_DIMM_SPD_BYTE_SIZE>() );
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unsupported DDRx Revision (0x%X)",
                       i_dimmType );

            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_SET_DIMM_SIZE
             * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
             * @userdata1        HUID to DIMM target
             * @userdata2        The DDR Revision
             * @devdesc          Invalid DDR Revision
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             VPD::VPD_SPD_SET_DIMM_SIZE,
                                             VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                             TARGETING::get_huid(&io_target),
                                             i_dimmType,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace( "SPD", 256);
        }
    } while (0);

    TRACSSCOMP( g_trac_spd, EXIT_MRK"spdSetSize(): returning %s errors",
                (l_err ? "with" : "with no") );

    return l_err;
}

// ------------------------------------------------------------------
// spdPresent
// ------------------------------------------------------------------
bool spdPresent ( TARGETING::Target * i_target )
{
    TRACSSCOMP( g_trac_spd, ENTER_MRK"spdPresent()" );

    errlHndl_t err{nullptr};
    uint8_t    memType(MEM_TYPE_INVALID);
    bool       pres(false);

    do
    {

#ifndef __HOSTBOOT_RUNTIME

        if( g_spdReadHW )
        {
            if (EEPROM::eepromPresence( i_target ))
            {
                // Read the Basic Memory Type
                err = getMemType( memType,
                                  i_target,
                                  VPD::AUTOSELECT );

                if ( err )
                {
                    // err is returned as nullptr, no need to set
                    errlCommit(err, VPD_COMP_ID );

                    // exit loop and return false
                    break;
                }

                TRACDCOMP( g_trac_spd,
                           INFO_MRK"Mem Type: %04x",
                           memType );

                // Set the SPD size
                err = spdSetSize( *i_target, memType );
                if ( err )
                {
                    // err is returned as nullptr, no need to set
                    errlCommit(err, VPD_COMP_ID );

                    // exit loop and return false
                    break;
                }
                else
                {
                    pres = true;
                }
            }
            // exit loop and do not execute non runtime code below
            break;
        }

#endif
        // Read the Basic Memory Type
        err = getMemType( memType,
                          i_target,
                          VPD::AUTOSELECT );

        if ( err )
        {
            // err is returned as nullptr, no need to set
            errlCommit(err, VPD_COMP_ID );

            // exit loop and return false
            break;
        }

        TRACDCOMP( g_trac_spd,
                   INFO_MRK"Mem Type: %04x",
                   memType );

        if ( isValidDimmType(memType) )
        {
            // Set the SPD size
            err = spdSetSize( *i_target, memType );
            if ( err )
            {
                // err is returned as nullptr, no need to set
                errlCommit(err, VPD_COMP_ID );
            }
            else
            {
                pres = true;
            }
        }  // end if ( isValidDimmType(memType) )
    } while( 0 );

    TRACSSCOMP( g_trac_spd, EXIT_MRK"spdPresent(): returning %s",
                (pres ? "true" : "false") );

    return pres;
}



// ------------------------------------------------------------------
// ddr3SpecialCases
// ------------------------------------------------------------------
errlHndl_t ddr3SpecialCases(const KeywordData & i_kwdData,
                            void * io_buffer,
                            TARGETING::Target * i_target,
                            VPD::vpdCmdTarget i_location)
{
    errlHndl_t err{nullptr};
    uint8_t * tmpBuffer = static_cast<uint8_t *>(io_buffer);

    TRACSSCOMP( g_trac_spd, ENTER_MRK"ddr3SpecialCases()" );

    switch( i_kwdData.keyword )
    {
        // ==================================================
        // 2 byte - LSB then MSB
        case CAS_LATENCIES_SUPPORTED:
        case TRFC_MIN:
        case MODULE_MANUFACTURER_ID:
        case MODULE_REVISION_CODE:
        case DRAM_MANUFACTURER_ID:
        case MODULE_CRC:
        case RMM_MFR_ID_CODE:
        case MODSPEC_MM_MFR_ID_CODE:
            // Get MSB
            err = spdFetchData( i_kwdData.offset,
                                1, /* Read 1 byte at a time */
                                &tmpBuffer[0],
                                i_target,
                                i_location );

            if( err ) break;

            // Mask and shift if needed
            if( i_kwdData.bitMask )
            {
                tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
            }

            // Get LSB
            err = spdFetchData( (i_kwdData.offset - 1),
                                1, /* Read 1 byte at a time */
                                &tmpBuffer[1],
                                i_target,
                                i_location );
            break;

        // ==================================================
        // 2 byte - MSB with mask then LSB is 2 more than MSB
        case TRC_MIN:
            // Get MSB
            err = spdFetchData( i_kwdData.offset,
                                1, /* Read 1 byte at a time */
                                &tmpBuffer[0],
                                i_target,
                                i_location );

            if( err ) break;

            // Mask and shift if needed
            if( i_kwdData.bitMask )
            {
                tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
            }

            // Get LSB
            err = spdFetchData( (i_kwdData.offset + 2),
                                1, /* Read 1 byte at a time */
                                &tmpBuffer[1],
                                i_target,
                                i_location );
            break;

        // ==================================================
        default:
            TRACFCOMP( g_trac_spd, ERR_MRK"ddr3SpecialCases: "
                       "Unknown keyword (0x%04x) for DDR3 special cases!",
                       i_kwdData.keyword );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INVALID_SPD_KEYWORD
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_DDR3_SPECIAL_CASES
             * @userdata1        SPD Keyword
             * @userdata2        UNUSED
             * @devdesc          Keyword is not a special case keyword.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_DDR3_SPECIAL_CASES,
                                           VPD::VPD_INVALID_SPD_KEYWORD,
                                           i_kwdData.keyword,
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
    };

    TRACSSCOMP( g_trac_spd, EXIT_MRK"ddr3SpecialCases(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


errlHndl_t fetchDataFromEepromType(uint64_t i_byteAddr,
                                   size_t i_numBytes,
                                   void * o_data,
                                   TARGETING::Target * i_target,
                                   VPD::vpdCmdTarget i_location,
                                   TARGETING::EEPROM_CONTENT_TYPE i_eepromType)
{
    errlHndl_t errl = nullptr;

    if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_ISDIMM)
    {
        errl = spdFetchData(i_byteAddr,
                            i_numBytes,
                            o_data,
                            i_target,
                            i_location);
    }
    else if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_DDIMM)
    {
        errl = ocmbFetchData(i_target,
                             i_byteAddr,
                             i_numBytes,
                             o_data,
                             EEPROM::AUTOSELECT);
    }

    return errl;
}

// ------------------------------------------------------------------
// ddr4SpecialCases
// ------------------------------------------------------------------
errlHndl_t ddr4SpecialCases(const KeywordData & i_kwdData,
                            void * io_buffer,
                            TARGETING::Target * i_target,
                            VPD::vpdCmdTarget i_location)
{
    errlHndl_t err{nullptr};
    uint8_t * tmpBuffer = static_cast<uint8_t *>(io_buffer);

    TRACSSCOMP( g_trac_spd, ENTER_MRK"ddr4SpecialCases()" );

    auto eepromVpd =
        i_target->getAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>();

    TARGETING::EEPROM_CONTENT_TYPE eepromType =
       static_cast<TARGETING::EEPROM_CONTENT_TYPE>(eepromVpd.eepromContentType);

    switch( i_kwdData.keyword )
    {
        // ==================================================
        // 2 byte - LSB then MSB
        case TRFC1_MIN:
        case TRFC2_MIN:
        case TRFC4_MIN:
        case BASE_CONFIG_CRC:
        case MODULE_MANUFACTURER_ID:
        case DRAM_MANUFACTURER_ID:
        case MANUFACTURING_SECTION_CRC:
        case UMM_CRC:
        case RMM_MFR_ID_CODE:
        case RMM_CRC:
        case MODSPEC_MM_MFR_ID_CODE:
        case LRMM_CRC:

            // Get MSB
            err = fetchDataFromEepromType(i_kwdData.offset,
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[0],
                                          i_target,
                                          i_location,
                                          eepromType);

            if( err ) break;

            // Mask and shift if needed
            if( i_kwdData.bitMask )
            {
                tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
            }

            // Get LSB
            err = fetchDataFromEepromType((i_kwdData.offset - 1),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[1],
                                          i_target,
                                          i_location,
                                          eepromType);
            break;

        // ==================================================
        // 2 byte - MSB with mask then LSB is 2 more than MSB
        case TRC_MIN:
            // Get MSB
            err = fetchDataFromEepromType(i_kwdData.offset,
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[0],
                                          i_target,
                                          i_location,
                                          eepromType);

            if( err ) break;

            // Mask and shift if needed
            if( i_kwdData.bitMask )
            {
                tmpBuffer[0] = tmpBuffer[0] & i_kwdData.bitMask;
                tmpBuffer[0] = tmpBuffer[0] >> i_kwdData.shift;
            }

            // Get LSB
            err = fetchDataFromEepromType((i_kwdData.offset + 2),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[1],
                                          i_target,
                                          i_location,
                                          eepromType);
            break;

        // ==================================================
        // 4 byte - LSB first, no mask
        case CAS_LATENCIES_SUPPORTED_DDR4:
            // Get 4th byte
            err = fetchDataFromEepromType(i_kwdData.offset,
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[0],
                                          i_target,
                                          i_location,
                                          eepromType);

            if( err ) break;

            // Get 3rd Byte
            err = fetchDataFromEepromType((i_kwdData.offset - 1),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[1],
                                          i_target,
                                          i_location,
                                          eepromType);

            if( err ) break;

            // Get 2nd Byte
            err = fetchDataFromEepromType((i_kwdData.offset - 2),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[2],
                                          i_target,
                                          i_location,
                                          eepromType);

            if( err ) break;

            // Get 1st Byte
            err = fetchDataFromEepromType((i_kwdData.offset - 3),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[3],
                                          i_target,
                                          i_location,
                                          eepromType);
            break;

        // ==================================================
        default:
            TRACFCOMP( g_trac_spd, ERR_MRK"ddr4SpecialCases: "
                       "Unknown keyword (0x%04x) for DDR4 special cases!",
                       i_kwdData.keyword );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INVALID_SPD_KEYWORD
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_DDR4_SPECIAL_CASES
             * @userdata1        SPD Keyword
             * @userdata2        UNUSED
             * @devdesc          Keyword is not a special case keyword.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_DDR4_SPECIAL_CASES,
                                           VPD::VPD_INVALID_SPD_KEYWORD,
                                           i_kwdData.keyword,
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
    };

    TRACSSCOMP( g_trac_spd, EXIT_MRK"ddr4SpecialCases(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}

// ------------------------------------------------------------------
// spdSpecialCases
// ------------------------------------------------------------------
errlHndl_t spdSpecialCases ( const KeywordData & i_kwdData,
                             void * io_buffer,
                             TARGETING::Target * i_target,
                             uint64_t i_DDRRev,
                             VPD::vpdCmdTarget i_location )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdSpecialCases()" );

    do
    {
        // Handle each of the special cases here
        if( SPD_DDR3_TYPE == i_DDRRev )
        {
            err = ddr3SpecialCases(i_kwdData,io_buffer,i_target,i_location);
        }
        else if (SPD_DDR4_TYPE == i_DDRRev)
        {
            err = ddr4SpecialCases(i_kwdData,io_buffer,i_target,i_location);
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unsupported DDRx Revision (0x%04x)",
                       i_DDRRev );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_SPECIAL_CASES
             * @userdata1        SPD Keyword
             * @userdata2        DIMM DDR Revision
             * @devdesc          Invalid DDR Revision
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_SPECIAL_CASES,
                                           VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                           i_kwdData.keyword,
                                           i_DDRRev );

           // User could have installed a bad/unsupported dimm
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( "SPD", 256);

            break;
        }
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdSpecialCases(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdCheckSize
// ------------------------------------------------------------------
errlHndl_t spdCheckSize ( size_t i_bufferSz,
                          size_t i_expBufferSz,
                          VPD::vpdKeyword i_keyword )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdCheckSize(): buffer size(%d), "
                         "expected buffer size(%d), VPD keyword(0x%X)",
                         i_bufferSz, i_expBufferSz, i_keyword );

    // Check that the buffer is greater than or equal to the size
    // we need to get all the keyword data requested.
    if( i_bufferSz < i_expBufferSz )
    {
        TRACFCOMP( g_trac_spd,
                   ERR_MRK"Buffer Size (%d) for keyword (0x%04x) wasn't greater"
                   " than or equal to expected size (%d)",
                   i_bufferSz, i_keyword, i_expBufferSz );

        /*@
         * @errortype
         * @reasoncode       VPD::VPD_INSUFFICIENT_BUFFER_SIZE
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_SPD_CHECK_SIZE
         * @userdata1        Keyword
         * @userdata2[0:31]  Needed Buffer Size
         * @userdata2[32:63] Expected Buffer Size
         * @devdesc          Buffer Size provided was not big enough for
         *                   the keyword requested.
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_SPD_CHECK_SIZE,
                                       VPD::VPD_INSUFFICIENT_BUFFER_SIZE,
                                       i_keyword,
                                       TWO_UINT32_TO_UINT64( i_bufferSz,
                                                             i_expBufferSz ),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        err->collectTrace( "SPD", 256);

    }

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdCheckSize(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdReadBinaryFile
// ------------------------------------------------------------------
errlHndl_t spdReadBinaryFile ( uint64_t i_byteAddr,
                               size_t i_numBytes,
                               void * o_data )
{
    errlHndl_t err{nullptr};
#ifndef __HOSTBOOT_RUNTIME
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
            TRACFCOMP( g_trac_spd, ERR_MRK"spdReadBinaryFile: "
                       "Error getting starting address of binary SPD file: %s",
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
                       ERR_MRK"Unable to read %d bytes from %s at offset 0x%08x"
                       " because file size is only %d bytes!",
                       i_numBytes,
                       fileName,
                       i_byteAddr,
                       fileSize );
            uint64_t tmpData = (i_byteAddr + i_numBytes);
            tmpData = tmpData << 16;
            tmpData = tmpData & (fileSize & 0xFFFF);

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INSUFFICIENT_FILE_SIZE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_READ_BINARY_FILE
             * @userdata1        File Size
             * @userdata2[0:48]  Starting offset into file
             * @userdata2[49:63] Number of bytes to read
             * @devdesc          File is not sufficiently large to read number
             *                   of bytes at offset given without overrunning
             *                   file.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_READ_BINARY_FILE,
                                           VPD::VPD_INSUFFICIENT_FILE_SIZE,
                                           fileSize,
                                           tmpData,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Retrieve the data requested
        TRACUCOMP( g_trac_spd,
                   "Copy data out of file" );
        memcpy( o_data, (startAddr + i_byteAddr), i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdReadBinaryFile(): returning %s errors",
                (err ? "with" : "with no") );
#endif
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
                                     TARGETING::Target * i_target,
                                     VPD::vpdCmdTarget i_location )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"checkModSpecificKeyword()" );

    do
    {
        // Check that a Module Specific keyword is being accessed from a DIMM
        // of the correct Module Type.
        modSpecTypes_t modType = NA;
        err = getModType(modType, i_target, i_memType, i_location);

        if( err )
        {
            break;
        }

        if (!(modType & i_kwdData.modSpec))
        {
            TRACFCOMP( g_trac_spd, ERR_MRK"checkModSpecificKeyword: "
                       "Module specific keyword could not be matched with an "
                       "appropriate scenario!" );

            TRACFCOMP( g_trac_spd, ERR_MRK
                       "  Mem Type: 0x%04x, Mod Type: 0x%04x, Keyword: 0x%04x",
                       i_memType,
                       modType,
                       i_kwdData.keyword );

            uint32_t udUpper32 = TWO_UINT16_TO_UINT32(modType, i_memType);
            uint32_t udLower32 = TWO_UINT16_TO_UINT32(i_kwdData.keyword,
                    i_kwdData.modSpec);
            uint64_t userdata1 = TWO_UINT32_TO_UINT64(udUpper32, udLower32);

            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_CHECK_MODULE_SPECIFIC_KEYWORD
             * @reasoncode       VPD::VPD_MOD_SPECIFIC_UNSUPPORTED
             * @userdata1[00:15] Memory Module Type
             * @userdata1[16:31] Memory Type (byte 2)
             * @userdata1[32:47] SPD Keyword
             * @userdata1[48:63] Module Specific Flag
             * @userdata2        Target HUID
             * @devdesc          Unsupported Module Type.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    VPD::VPD_SPD_CHECK_MODULE_SPECIFIC_KEYWORD,
                                    VPD::VPD_MOD_SPECIFIC_UNSUPPORTED,
                                    userdata1,
                                    TARGETING::get_huid(i_target));

                // HB code asked for an unsupprted keyword for this Module
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                // Or user could have installed a bad/unsupported dimm
                err->addHwCallout( i_target,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::DECONFIG,
                                   HWAS::GARD_NULL );

            err->collectTrace( "SPD", 256);

            break;
        }

    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"checkModSpecificKeyword(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// getMemType
// ------------------------------------------------------------------
errlHndl_t getMemType(uint8_t             & o_memType,
                      TARGETING::Target   * i_target,
                      VPD::vpdCmdTarget     i_location,
                      EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};

    err = spdFetchData( MEM_TYPE_ADDR,
                        MEM_TYPE_SZ,
                        &o_memType,
                        i_target,
                        i_location,
                        i_eepromSource);

    TRACUCOMP( g_trac_spd,
               EXIT_MRK"SPD::getMemType() - MemType: 0x%02x, Error: %s",
               o_memType,
               ((NULL == err) ? "No" : "Yes") );

    return err;
}


errlHndl_t getMemType(uint8_t &                  o_memType,
                     TARGETING::Target *         i_target,
                     TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                     EEPROM::EEPROM_SOURCE       i_eepromSource)
{
    errlHndl_t err = nullptr;

// @TODO RTC 204341 Implement for runtime
#ifndef __HOSTBOOT_RUNTIME

    if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_ISDIMM)
    {
        err = getMemType(o_memType,
                         i_target,
                         VPD::AUTOSELECT,
                         i_eepromSource);
    }
    else if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_DDIMM)
    {
        err = getMemType(o_memType,
                         i_target,
                         i_eepromSource);
    }
    else
    {
        /*@
        * @errortype
        * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid         VPD::VPD_GET_MEMTYPE
        * @reasoncode       VPD::VPD_INVALID_EEPROM_CONTENT_TYPE
        * @userdata1        Eeprom Content Type Given
        * @userdata2        Target HUID
        * @devdesc          An unsupported eeprom content type was supplied.
        * @custdesc         A problem occurred during the IPL
        *                   of the system.
        */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      VPD::VPD_GET_MEMTYPE,
                                      VPD::VPD_INVALID_EEPROM_CONTENT_TYPE,
                                      i_eepromType,
                                      TARGETING::get_huid(i_target),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

#endif

    return err;

}

// ------------------------------------------------------------------
// getModType
// ------------------------------------------------------------------
errlHndl_t getModType ( modSpecTypes_t & o_modType,
                        TARGETING::Target * i_target,
                        uint64_t i_memType,
                        VPD::vpdCmdTarget i_location )
{
    errlHndl_t err{nullptr};
    o_modType = NA;

    auto eepromVpd =
        i_target->getAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>();

    TARGETING::EEPROM_CONTENT_TYPE eepromType =
       static_cast<TARGETING::EEPROM_CONTENT_TYPE>(eepromVpd.eepromContentType);

    uint8_t modTypeVal = 0;
    err = fetchDataFromEepromType(MOD_TYPE_ADDR,
                                  MOD_TYPE_SZ,
                                  &modTypeVal,
                                  i_target,
                                  i_location,
                                  eepromType);

    if (err)
    {
        TRACFCOMP( g_trac_spd,
                   ERR_MRK"SPD::getModType() - Error querying ModType" );
    }
    else
    {
        modTypeVal &= MOD_TYPE_MASK;

        if (SPD_DDR3_TYPE == i_memType)
        {
            if ((MOD_TYPE_DDR3_UDIMM == modTypeVal)      ||
                (MOD_TYPE_DDR3_SO_DIMM == modTypeVal)    ||
                (MOD_TYPE_DDR3_MICRO_DIMM == modTypeVal) ||
                (MOD_TYPE_DDR3_MINI_UDIMM == modTypeVal) ||
                (MOD_TYPE_DDR3_SO_UDIMM == modTypeVal))
            {
                o_modType = UMM;
            }
            else if ((MOD_TYPE_DDR3_RDIMM == modTypeVal)      ||
                     (MOD_TYPE_DDR3_MINI_RDIMM == modTypeVal) ||
                     (MOD_TYPE_DDR3_SO_RDIMM == modTypeVal))
            {
                o_modType = RMM;
            }
            else if ((MOD_TYPE_DDR3_MINI_CDIMM == modTypeVal) ||
                     (MOD_TYPE_DDR3_SO_CDIMM == modTypeVal))
            {
                o_modType = CMM;
            }
            else if (MOD_TYPE_DDR3_LRDIMM == modTypeVal)
            {
                o_modType = LRMM;
            }
        }
        else if (SPD_DDR4_TYPE == i_memType)
        {
            if ((MOD_TYPE_DDR4_UDIMM == modTypeVal)      ||
                (MOD_TYPE_DDR4_SO_DIMM == modTypeVal)    ||
                (MOD_TYPE_DDR4_MINI_UDIMM == modTypeVal) ||
                (MOD_TYPE_DDR4_SO_UDIMM == modTypeVal))
            {
                o_modType = UMM;
            }
            else if ((MOD_TYPE_DDR4_RDIMM == modTypeVal)      ||
                     (MOD_TYPE_DDR4_MINI_RDIMM == modTypeVal) ||
                     (MOD_TYPE_DDR4_SO_RDIMM == modTypeVal))
            {
                o_modType = RMM;
            }
            else if (MOD_TYPE_DDR4_LRDIMM == modTypeVal)
            {
                o_modType = LRMM;
            }
            else if( MOD_TYPE_DDIMM == modTypeVal)
            {
                o_modType = DDIMM;
            }
        }

        if (o_modType == NA)
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Module type 0x%02x unrecognized", modTypeVal );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_MOD_SPECIFIC_UNSUPPORTED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_GET_MOD_TYPE
             * @userdata1        Module Type (byte 3[3:0])
             * @userdata2        Memory Type (byte 2)
             * @devdesc          Unrecognized Module Type.
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                VPD::VPD_SPD_GET_MOD_TYPE,
                VPD::VPD_MOD_SPECIFIC_UNSUPPORTED,
                modTypeVal, i_memType,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);
        }
        else
        {
            TRACUCOMP( g_trac_spd,
                       "SPD::getModType() - Val: 0x%02x, ModType: 0x%02x",
                       modTypeVal, o_modType);
        }
    }

    return err;
}


// ------------------------------------------------------------------
// getKeywordEntry
// ------------------------------------------------------------------
errlHndl_t getKeywordEntry ( VPD::vpdKeyword i_keyword,
                             uint64_t i_memType,
                             TARGETING::Target * i_target,
                             const KeywordData *& o_entry )
{
    errlHndl_t err{nullptr};
    const KeywordData * kwdData;
    uint32_t arraySize = 0x0;

    TRACSSCOMP( g_trac_spd, ENTER_MRK"getKeywordEntry()" );

    do
    {
        if ( SPD_DDR3_TYPE == i_memType )
        {
            arraySize = (sizeof(ddr3Data)/sizeof(ddr3Data[0]));
            kwdData = ddr3Data;
        }
        else if ( SPD_DDR4_TYPE == i_memType )
        {
            modSpecTypes_t modType = NA;
            err = getModType(modType, i_target, i_memType, VPD::AUTOSELECT);
            if (modType == DDIMM)
            {
                arraySize = (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]));
                kwdData = ddr4DDIMMData;
            }
            else
            {
                arraySize = (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                kwdData = ddr4Data;
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd,
                       ERR_MRK"Unsupported DDRx Revision (0x%04x)",
                       i_memType );

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_GET_KEYWORD_ENTRY
             * @userdata1        SPD Keyword
             * @userdata2        The DDR Revision
             * @devdesc          Invalid DDR Revision
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_GET_KEYWORD_ENTRY,
                                           VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                           i_keyword,
                                           i_memType );

            // User could have installed a bad/unsupported dimm
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( "SPD", 256);

            break;
        }

        // Set the searching structure equal to the keyword we're looking for.
        KeywordData tmpKwdData;
        tmpKwdData.keyword = i_keyword;
        const KeywordData * entry = std::lower_bound( kwdData,
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
             * @reasoncode       VPD::VPD_KEYWORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_GET_KEYWORD_ENTRY
             * @userdata1        SPD Keyword
             * @userdata2        <UNUSED>
             * @devdesc          Invalid SPD Keyword
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_GET_KEYWORD_ENTRY,
                                           VPD::VPD_KEYWORD_NOT_FOUND,
                                           i_keyword,
                                           0x0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            err->collectTrace( "SPD", 256);

            break;
        }

        o_entry = entry;
    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"getKeywordEntry(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// setPartAndSerialNumberAttributes
// ------------------------------------------------------------------
void setPartAndSerialNumberAttributes( TARGETING::Target * i_target )
{
    errlHndl_t l_err = NULL;

    //Default to standard VPD Location for DDIMM SPD SN/PN
    VPD::vpdKeyword l_partKeyword = SPD::MODULE_PART_NUMBER;
    VPD::vpdKeyword l_serialKeyword = SPD::MODULE_SERIAL_NUMBER;

    if(TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_USE_11S_SPD>())
    {
        //Use IBM 11S Location for DDIMM SN/PN
        l_partKeyword = SPD::IBM_11S_PN;
        l_serialKeyword = SPD::IBM_11S_SN;
    }

    do
    {
         // Read the Basic Memory Type
        uint8_t l_memType(MEM_TYPE_INVALID);
        l_err = getMemType( l_memType,
                            i_target,
                            VPD::AUTOSELECT );
        if( l_err )
        {
            TRACDCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Error after getMemType");
            errlCommit(l_err, VPD_COMP_ID );
            l_err = NULL;
            break;
        }

        if (false == isValidDimmType(l_memType) )
        {
            TRACDCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Unknown memType");
            break;
        }

        // Get the keyword sizes
        const KeywordData* entry = NULL;
        l_err = getKeywordEntry( l_partKeyword,
                                 l_memType,
                                 i_target,
                                 entry );
        if( l_err )
        {
            break;
        }
        size_t l_partDataSize = entry->length;

        entry = NULL;
        l_err = getKeywordEntry( l_serialKeyword,
                                 l_memType,
                                 i_target,
                                 entry );
        if( l_err )
        {
            break;
        }
        size_t l_serialDataSize = entry->length;
        TRACDCOMP(g_trac_spd,"l_partDataSize=%d,l_serialDataSize=%d\n",
                l_partDataSize,l_serialDataSize);

        //read the keywords from SEEPROM since PNOR may not be loaded yet
        uint8_t l_partNumberData[l_partDataSize];
        l_err = spdGetValue( l_partKeyword,
                             l_partNumberData,
                             l_partDataSize,
                             i_target,
                             l_memType,
                             VPD::AUTOSELECT );

        if( l_err )
        {
            TRACDCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Error after spdGetValue-> PART_NUMBER");
            errlCommit(l_err, VPD_COMP_ID);
            l_err = NULL;
            break;
        }

        uint8_t l_serialNumberData[l_serialDataSize];
        l_err = spdGetValue( l_serialKeyword,
                             l_serialNumberData,
                             l_serialDataSize,
                             i_target,
                             l_memType,
                             VPD::AUTOSELECT );

        if( l_err )
        {
            TRACFCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Error after spdGetValue-> SERIAL_NUMBER");
            errlCommit(l_err, VPD_COMP_ID);
            l_err = NULL;
            break;
        }
        // Set the attributes
        TARGETING::ATTR_PART_NUMBER_type l_PN = {0};
        TARGETING::ATTR_SERIAL_NUMBER_type l_SN = {0};
        size_t expectedPNSize = sizeof(l_PN);
        size_t expectedSNSize = sizeof(l_SN);
        if(expectedPNSize < l_partDataSize)
        {
            TRACFCOMP(g_trac_spd, "Part data size too large for attribute. Expected: %d Actual: %d"
                    "Keyword: %X",
                    expectedPNSize, l_partDataSize, l_partKeyword);
        }
        else
        {
            memcpy(l_PN, l_partNumberData, l_partDataSize);
            i_target->trySetAttr<TARGETING::ATTR_PART_NUMBER>(l_PN);
        }
        if(expectedSNSize < l_serialDataSize)
        {
            TRACFCOMP(g_trac_spd, "Serial data size too large for attribute. Expected: %d Actual: %d",
                        expectedSNSize, l_serialDataSize);
        }
        else
        {
            memcpy(l_SN, l_serialNumberData, l_serialDataSize);
            i_target->trySetAttr<TARGETING::ATTR_SERIAL_NUMBER>(l_SN);
        }
    }while( 0 );

    TRACSSCOMP(g_trac_spd, EXIT_MRK"spd.C::setPartAndSerialNumberAttributes()");
}

/*
 * @brief Read keyword from SPD by determining which function to call based on
 *        eeprom content type.
 *
 * @param[in]     i_target         target to read data from
 * @param[in]     i_eepromType     Eeprom content type of the target.
 * @param[in]     i_keyword        keyword from spdenums.H to read
 * @param[in]     i_memType        The memory type of this target.
 * @param[in/out] io_buffer        data buffer SPD will be written to
 * @param[in/out] io_buflen        length of the given data buffer
 * @param[in]     i_eepromSource   The EEPROM source (CACHE/HARDWARE).
 *
 *
 * @return        errlHndl_t       nullptr on success. Otherwise, error log.
 */
errlHndl_t readFromEepromSource(TARGETING::Target*          i_target,
                                TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                          const VPD::vpdKeyword             i_keyword,
                          const uint8_t                     i_memType,
                                void*                       io_buffer,
                                size_t&                     io_buflen,
                                EEPROM::EEPROM_SOURCE       i_eepromSource)
{
    errlHndl_t err = nullptr;

    TRACSSCOMP(g_trac_spd, ENTER_MRK
               "readFromEepromSource: i_eepromSource %d , i_memType %d, i_eepromType %d",
               i_eepromSource, i_memType, i_eepromType);

// @TODO RTC 204341 Implement for runtime
#ifndef __HOSTBOOT_RUNTIME
    if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_ISDIMM)
    {
        err = spdGetValue(i_keyword,
                          io_buffer,
                          io_buflen,
                          i_target,
                          i_memType,
                          VPD::SEEPROM,
                          i_eepromSource);
    }
    else if (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_DDIMM)
    {
        err = ocmbGetSPD(i_target,
                         io_buffer,
                         io_buflen,
                         i_keyword,
                         i_memType,
                         i_eepromSource);
    }
    else
    {
        /*@
        * @errortype
        * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid         VPD::VPD_READ_FROM_EEPROM_SOURCE
        * @reasoncode       VPD::VPD_INVALID_EEPROM_CONTENT_TYPE
        * @userdata1        Eeprom Content Type Given
        * @userdata2        Target HUID
        * @devdesc          An unsupported eeprom content type was supplied.
        * @custdesc         A problem occurred during the IPL
        *                   of the system.
        */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      VPD::VPD_READ_FROM_EEPROM_SOURCE,
                                      VPD::VPD_INVALID_EEPROM_CONTENT_TYPE,
                                      i_eepromType,
                                      TARGETING::get_huid(i_target),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
#endif

    return err;
}


// ------------------------------------------------------------------
// cmpEecacheToEeprom
// ------------------------------------------------------------------
errlHndl_t cmpEecacheToEeprom(TARGETING::Target * i_target,
                              TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                              VPD::vpdKeyword i_keyword,
                              bool &o_match)
{
    errlHndl_t err = nullptr;

    TRACSSCOMP(g_trac_spd, ENTER_MRK"cmpEecacheToEeprom()");

    o_match = false;
    do
    {
        // Read the Basic Memory Type from the Eeprom Cache
        uint8_t memTypeCache(MEM_TYPE_INVALID);
        err = getMemType(memTypeCache,
                         i_target,
                         i_eepromType,
                         EEPROM::CACHE);
        if (err)
        {
            break;
        }

        if (!isValidDimmType(memTypeCache, i_eepromType))
        {
            TRACFCOMP(g_trac_spd, ERR_MRK
                     "cmpEecacheToEeprom() Invalid DIMM type found in cache copy of eeprom,"
                     " we will not be able to understand contents");
            break;
        }

        // Read the Basic Memory Type from HARDWARE
        uint8_t memTypeHardware(MEM_TYPE_INVALID);
        err = getMemType(memTypeHardware,
                         i_target,
                         i_eepromType,
                         EEPROM::HARDWARE);
        if (err)
        {
            break;
        }

        if (!isValidDimmType(memTypeHardware, i_eepromType))
        {
            // Leave o_match == false and exit.
            TRACFCOMP(g_trac_spd, ERR_MRK"cmpEecacheToEeprom() Invalid DIMM type found in hw copy of eeprom");
            break;
        }

        if (memTypeCache != memTypeHardware)
        {
            // CACHE and HARDWARE don't match.
            // Leave o_match == false and exit.
            break;
        }

         // Get the keyword size
        const KeywordData* entry = nullptr;
        err = getKeywordEntry(i_keyword,
                              memTypeHardware,
                              i_target,
                              entry);
        if (err)
        {
            break;
        }
        size_t dataSize = entry->length;


        // Read the keyword from HARDWARE
        size_t sizeHardware = dataSize;
        uint8_t dataHardware[sizeHardware];
        err = readFromEepromSource(i_target,
                                   i_eepromType,
                                   i_keyword,
                                   memTypeHardware,
                                   dataHardware,
                                   sizeHardware,
                                   EEPROM::HARDWARE);
        if (err)
        {
            break;
        }

        // Read the keyword from CACHE
        size_t sizeCache = dataSize;
        uint8_t dataCache[sizeCache];
        err = readFromEepromSource(i_target,
                                   i_eepromType,
                                   i_keyword,
                                   memTypeHardware,
                                   dataCache,
                                   sizeCache,
                                   EEPROM::CACHE);
        if (err)
        {
            // CACHE may not be loaded, ignore the error
            delete err;
            err = NULL;
            break;
        }

        TRACDBIN(g_trac_spd, "Hardware data : ", dataHardware, sizeHardware);
        TRACDBIN(g_trac_spd, "Cache data : ", dataCache, sizeCache);

        // Compare the HARDWARE/CACHE keyword size/data
        if (sizeHardware != sizeCache)
        {
            // CACHE and HARDWARE don't match.
            // Leave o_match == false and exit.
            break;
        }
        if (memcmp(dataHardware, dataCache, sizeHardware))
        {
            // CACHE and HARDWARE don't match.
            // Leave o_match == false and exit.
            break;
        }

        o_match = true;

    } while(0);

    TRACSSCOMP( g_trac_spd, EXIT_MRK"cmpEecacheToEeprom(): returning %s errors. o_match = 0x%X ",
                (err ? "with" : "with no"), o_match );

    return err;
 }

// ------------------------------------------------------------------
// cmpPnorToSeeprom
// ------------------------------------------------------------------
errlHndl_t cmpPnorToSeeprom ( TARGETING::Target * i_target,
                              VPD::vpdKeyword i_keyword,
                              bool &o_match )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd, ENTER_MRK"cmpPnorSeeprom()" );

    o_match = false;
    do
    {
        // Read the Basic Memory Type from the Seeprom
        uint8_t memTypeSeeprom(MEM_TYPE_INVALID);
        err = getMemType( memTypeSeeprom,
                          i_target,
                          VPD::SEEPROM );
        if( err )
        {
            break;
        }

        if( false == isValidDimmType(memTypeSeeprom) )
        {
            break;
        }

        // Read the Basic Memory Type from PNOR
        uint8_t memTypePnor(MEM_TYPE_INVALID);
        err = getMemType( memTypePnor,
                          i_target,
                          VPD::PNOR );
        if( err )
        {
            break;
        }

        if( false == isValidDimmType(memTypePnor) )
        {
            break;
        }

        if (memTypeSeeprom != memTypePnor)
        {
            break;
        }

         // Get the keyword size
        const KeywordData* entry = NULL;
        err = getKeywordEntry( i_keyword,
                               memTypePnor,
                               i_target,
                               entry );
        if( err )
        {
            break;
        }
        size_t dataSize = entry->length;


        // Read the keyword from PNOR
        size_t sizePnor = dataSize;
        uint8_t dataPnor[sizePnor];
        err = spdGetValue( i_keyword,
                           dataPnor,
                           sizePnor,
                           i_target,
                           memTypePnor,
                           VPD::PNOR );
        if( err )
        {
            // PNOR may not be loaded, ignore the error
            delete err;
            err = NULL;
            break;
        }

        // Read the keyword from SEEPROM
        size_t sizeSeeprom = dataSize;
        uint8_t dataSeeprom[sizeSeeprom];
        err = spdGetValue( i_keyword,
                           dataSeeprom,
                           sizeSeeprom,
                           i_target,
                           memTypePnor,
                           VPD::SEEPROM );
        if( err )
        {
            break;
        }

        // Compare the PNOR/SEEPROM size/data
        if( sizePnor != sizeSeeprom )
        {
            break;
        }
        if( memcmp( dataPnor, dataSeeprom, sizePnor ) )
        {
            break;
        }

        o_match = true;

    } while(0);

    TRACSSCOMP( g_trac_spd, EXIT_MRK"cmpPnorSeeprom(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
 }


// ------------------------------------------------------------------
// loadPnor
// ------------------------------------------------------------------
errlHndl_t loadPnor ( TARGETING::Target * i_target )
{
    errlHndl_t err{nullptr};
    size_t writeDataSize = 0;
    uint8_t spdEepromData[DIMM_SPD_SECTION_SIZE];
    TRACSSCOMP( g_trac_spd, ENTER_MRK"loadPnor()" );

    do
    {
        // Invalidate the SPD in PNOR
        err = invalidatePnor( i_target );
        if( err )
        {
            TRACFCOMP( g_trac_spd,
                ERR_MRK"loadPnorCache: Error invalidating the SPD in PNOR" );
            break;
        }

        // Determine the memory type so we know if we need to read 256,
        // 512, etc from the eeprom
        uint8_t memType(MEM_TYPE_INVALID);
        err = getMemType( memType,
                          i_target,
                          VPD::SEEPROM );

        if( err )
        {
            TRACFCOMP(g_trac_spd,
                    "spd.C::loadPnor - Error getting memtype(0x%x) "
                    "for target = 0x%x",
                    memType,
                    TARGETING::get_huid(i_target));
            break;
        }

        // Load PNOR cache from SEEPROM
        // Read entire EEPROM at one time

        // Get the size of the DIMM
        writeDataSize = i_target->getAttr<TARGETING::ATTR_DIMM_SPD_BYTE_SIZE>();

        // Fetch the EEPROM daa
        err = spdFetchData ( 0x0,
                             writeDataSize,
                             spdEepromData,
                             i_target,
                             VPD::SEEPROM );
        if( err )
        {
            TRACFCOMP( g_trac_spd,
                ERR_MRK"loadPnorCache: Error reading SEEPROM SPD data" );
            break;
        }
        // Write the entire SPD section to PNOR
        TRACDBIN(g_trac_spd, "ENTIRE EEPROM", spdEepromData, writeDataSize);
        err = spdWriteData( 0x0,
                            writeDataSize,
                            spdEepromData,
                            i_target,
                            VPD::PNOR );
        if( err )
        {
            TRACFCOMP( g_trac_spd,ERR_MRK"loadPnorCache: Error writing PNOR SPD data 2" );
            break;
        }


    } while(0);

    TRACSSCOMP( g_trac_spd, EXIT_MRK"loadPnorCache(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// invalidatePnor
// ------------------------------------------------------------------
errlHndl_t invalidatePnor ( TARGETING::Target * i_target )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd, ENTER_MRK"invalidatePnor()" );

    // Write SPD section to all Fs
    uint8_t writeData[DIMM_SPD_SECTION_SIZE];
    memset( writeData, 0xFF, DIMM_SPD_SECTION_SIZE );
    err = spdWriteData( 0x0,
                        DIMM_SPD_SECTION_SIZE,
                        writeData,
                        i_target,
                        VPD::PNOR );
    if( err )
    {
        TRACFCOMP( g_trac_spd, ERR_MRK"invalidatePnor: "
                   "Error invalidating the SPD in PNOR" );
    }

    TRACSSCOMP( g_trac_spd, EXIT_MRK"invalidatePnor(): returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// setConfigFlagsHW
// ------------------------------------------------------------------
void setConfigFlagsHW ( )
{
    // Only change configs if in PNOR caching mode
    // In PNOR only mode we would lose all VPD data
    if( g_spdReadPNOR &&
        g_spdReadHW )
    {
        g_spdReadPNOR  = false;
        g_spdReadHW    = true;
    }
    if( g_spdWritePNOR &&
        g_spdWriteHW )
    {
        g_spdWritePNOR = false;
        g_spdWriteHW   = true;
    }
}


}; // end namespace SPD
