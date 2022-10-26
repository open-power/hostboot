/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/spd.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <targeting/common/utilFilter.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <devicefw/driverif.H>
#include <devicefw/userif.H>
#include <eeprom/eepromif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/spdenums.H>
#include <algorithm>
#include "spd.H"
#include "ocmb_spd.H"
#include "spdDDR3.H"
#include "spdDDR4.H"
#include "spdDDR4_DDIMM.H"
#include "spd_planar.H"
#include "errlud_vpd.H"
#include <targeting/targplatutil.H>     // assertGetToplevelTarget

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_spd = nullptr;
TRAC_INIT( & g_trac_spd, "SPD", KILOBYTE );

// ------------------------
// Macros for unit testing
// #define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
// #define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

using namespace TARGETING;

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
                     EEPROM_CONTENT_TYPE i_eepromType);


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
 * @param[in] i_eepromSource - The EEPROM source (CACHE/HARDWARE).
 *                             Default to AUTOSELECT.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getMemType(uint8_t & o_memType,
                     Target * i_target,
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
                     Target *            i_target,
                     EEPROM_CONTENT_TYPE i_eepromType,
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
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getModType ( modSpecTypes_t & o_modType,
                        Target * i_target,
                        uint64_t i_memType );


/**
 * @brief This function will read the DDIMM mod height.
 * @pre Assumes dimmType = DDR4 and modType = DDIMM
 *
 * @param[out] o_ddimmModHeight - The DIMM mod height reading
 *                               (use DDIMM_MOD_HEIGHT enums to translate to 4U, 2U or 1U)
 *
 * @param[in] i_target       - The target to read data from.
 *
 * @param[in] i_eepromSource - The EEPROM source (CACHE/HARDWARE).
 *                             Default to AUTOSELECT.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer
 *      to the error log.
 */
errlHndl_t getDdimmModHeight(uint8_t & o_ddimmModHeight,
                           Target * i_target,
                           EEPROM::EEPROM_SOURCE i_eepromSource = EEPROM::AUTOSELECT);


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
errlHndl_t spdSetSize ( Target &io_target,
                        uint8_t            i_dimmType);


// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::SPD,
                       TYPE_DIMM,
                       spdGetKeywordValue );
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::SPD,
                       TYPE_DIMM,
                       spdWriteKeywordValue );

// Register the perform Op with the routing code for OCMBs.
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::SPD,
                       TYPE_OCMB_CHIP,
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
                     EEPROM_CONTENT_TYPE i_eepromType)
{
    bool isValid = false;

// TODO RTC:204341 Add support for reading/write EECACHE during runtime
#ifndef __HOSTBOOT_RUNTIME
    if (i_eepromType == EEPROM_CONTENT_TYPE_ISDIMM)
    {
        isValid = isValidDimmType(i_memType);
    }
    else if ((i_eepromType == EEPROM_CONTENT_TYPE_DDIMM) ||
             (i_eepromType == EEPROM_CONTENT_TYPE_PLANAR_OCMB_SPD))
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
                                Target * i_target,
                                void * io_buffer,
                                size_t & io_buflen,
                                int64_t i_accessType,
                                va_list i_args )
{
    errlHndl_t err{nullptr};
    VPD::vpdKeyword keyword = va_arg( i_args, uint64_t );

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdGetKeywordValue(%08X), io_buflen: %d, keyword: 0x%04x",
                get_huid(i_target), io_buflen, keyword );

    do
    {
        // Read the Basic Memory Type
        uint8_t memType(MEM_TYPE_INVALID);
        err = getMemType( memType,
                          i_target );

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
                               memType );

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
                       get_huid(i_target));

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
                                  Target * i_target,
                                  void * io_buffer,
                                  size_t & io_buflen,
                                  int64_t i_accessType,
                                  va_list i_args )
{
    errlHndl_t err{nullptr};
    VPD::vpdKeyword keyword = va_arg( i_args, uint64_t );

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdWriteKeywordValue()" );

    do
    {
        // Get memory type
        uint8_t memType(MEM_TYPE_INVALID);
        err = getMemType( memType,
                          i_target );

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
                          Target   * i_target,
                          EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdFetchData()" );

    do
    {
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
                      ERR_MRK"spdFetchData: failing out of deviceOp in spd.C");
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
                          Target * i_target )
{
    errlHndl_t err{nullptr};


    do
    {
        TRACSSCOMP(g_trac_spd, "spdWriteData() HUID=0x%X",
                   get_huid(i_target));
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

    } while( 0 );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"spdWriteData() returning %s errors",
                (err ? "with" : "with no") );

    return err;
}


// ------------------------------------------------------------------
// spdGetValue
// ------------------------------------------------------------------
errlHndl_t spdGetValue(VPD::vpdKeyword       i_keyword,
                       void                * io_buffer,
                       size_t              & io_buflen,
                       Target              * i_target,
                       uint64_t              i_DDRRev,
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
                                       i_target );

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
                                   i_DDRRev );

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
                                i_eepromSource );

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
                           Target * i_target,
                           uint64_t i_DDRRev )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd, ENTER_MRK"spdWriteValue()");

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

        TRACSSCOMP( g_trac_spd, "spdWriteValue() spdWriteData g_spdWriteHW=0x%X i_keyword=0x%X io_buflen=0x%X HUID=0x%X",
            g_spdWriteHW, i_keyword, io_buflen, get_huid(i_target));
        // Write value
        err = spdWriteData( entry->offset,
                            io_buflen,
                            io_buffer,
                            i_target );

        if( err )
        {
            break;
        }

        // sendMboxWriteMsg will check if we need to send msg to SP or not
        TRACFCOMP(g_trac_spd, "spdWriteValue() sending sendMboxWriteMsg HUID=0x%X io_buflen=0x%X entry->offset=0x%X ",
                  get_huid(i_target), io_buflen, entry->offset);
        // Send mbox message with new data to FSP
        VPD::VpdWriteMsg_t msgdata;
        msgdata.offset = entry->offset;
        err = VPD::sendMboxWriteMsg( io_buflen,
                                     io_buffer,
                                     i_target,
                                     VPD::VPD_WRITE_CACHE,
                                     msgdata );
        if( err )
        {
            break;
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
errlHndl_t spdSetSize ( Target &io_target,
                        const uint8_t      i_dimmType)
{
    TRACSSCOMP( g_trac_spd, ENTER_MRK"spdSetSize(): setting DIMM SPD(0x%X) size for"
                " target(0x%X)", i_dimmType, get_huid(&io_target) );

    errlHndl_t l_err{nullptr};

    do
    {
        if ( SPD_DDR3_TYPE == i_dimmType )
        {
            io_target.setAttr<ATTR_DIMM_SPD_BYTE_SIZE>(SPD_DDR3_SIZE);
            TRACSSCOMP( g_trac_spd, "found DIMM w/ HUID 0x%08X to be type "
                        "DDR3, set ATTR_DIMM_SPD_BYTE_SIZE to be %d",
                        get_huid(&io_target),
                        io_target.getAttr<ATTR_DIMM_SPD_BYTE_SIZE>() );

        }
        else if ( SPD_DDR4_TYPE == i_dimmType )
        {
            io_target.setAttr<ATTR_DIMM_SPD_BYTE_SIZE>(SPD_DDR4_SIZE);
            TRACSSCOMP( g_trac_spd, "found DIMM w/ HUID 0x%08X to be type "
                        "DDR4, set ATTR_DIMM_SPD_BYTE_SIZE to be %d",
                        get_huid(&io_target),
                        io_target.getAttr<ATTR_DIMM_SPD_BYTE_SIZE>() );
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
                                             get_huid(&io_target),
                                             i_dimmType,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_err->collectTrace( "SPD", 256);
        }
    } while (0);

    TRACSSCOMP( g_trac_spd, EXIT_MRK"spdSetSize(): returning %s errors",
                (l_err ? "with" : "with no") );

    return l_err;
}

/**
 * @brief Checks for redundant memory type by reading SPD data, then
 *        sets the target to its appropriate redundancy setting.
 *        Specifically checking for DDR4 4U DDIMM
 * @param i_target DIMM target
 * @param i_memtype Memory type returned from getMemType()
 * @return nullptr if redundancy set correctly, else error
 */
errlHndl_t spdUpdateEepromRedundancy(Target * i_target, const uint8_t i_memType)
{
    errlHndl_t err{nullptr};
    ATTR_EEPROM_VPD_REDUNDANCY_type newEepromRedundancy =
                    EEPROM_VPD_REDUNDANCY_POSSIBLE;

    do {
        // Check for redundant DDR4 4U DDIMM
        if (i_memType == SPD_DDR4_TYPE)
        {
            modSpecTypes_t modType = NA;
            err = getModType(modType, i_target, i_memType);
            if ( err )
            {
                errlCommit(err, VPD_COMP_ID);
                break;
            }

            if (modType == DDIMM)
            {
                uint8_t ddimmModHeight = DDIMM_MOD_HEIGHT_INVALID;
                err = getDdimmModHeight(ddimmModHeight, i_target);
                if ( err )
                {
                    errlCommit(err, VPD_COMP_ID);
                    break;
                }

                if (ddimmModHeight == DDIMM_MOD_HEIGHT_4U)
                {
                    TRACFCOMP( g_trac_spd,
                        "spdUpdateEepromRedundancy> Found 0x%08X is an eeprom-redundant DDR4 4U DDIMM",
                        get_huid(i_target) );
                    newEepromRedundancy = EEPROM_VPD_REDUNDANCY_PRESENT;
                }
                else
                {
                    if ((ddimmModHeight == DDIMM_MOD_HEIGHT_2U) ||
                        (ddimmModHeight == DDIMM_MOD_HEIGHT_1U))
                    {
                        TRACFCOMP( g_trac_spd,
                            "spdUpdateEepromRedundancy> 0x%08X is a NON-REDUNDANT DDR4 %dU DDIMM",
                            get_huid(i_target), (ddimmModHeight == DDIMM_MOD_HEIGHT_2U)?2:1 );
                        newEepromRedundancy = EEPROM_VPD_REDUNDANCY_NOT_PRESENT;
                    }
                    else
                    {
                        TRACFCOMP( g_trac_spd,
                            "spdUpdateEepromRedundancy> 0x%08X is a non-redundant eeprom DDR4 DDIMM (mod height %x)",
                            get_huid(i_target), ddimmModHeight );
                    }
                }
            }
        }

        // Only update to redundancy present
        if (newEepromRedundancy != EEPROM_VPD_REDUNDANCY_POSSIBLE)
        {
            // we read SPD to determine redundancy
            i_target->setAttr<ATTR_EEPROM_VPD_REDUNDANCY>(newEepromRedundancy);

            // also update parent OCMB redundancy
            TargetHandleList l_ocmbs;
            getParentAffinityTargets(l_ocmbs,
                                     i_target,
                                     CLASS_CHIP,
                                     TYPE_OCMB_CHIP,
                                     false);
            if (l_ocmbs.size() == 1)
            {
                TRACFCOMP(g_trac_spd,
                    "spdUpdateEepromRedundancy> setting DDIMM (0x%08X) and its OCMB (0x%08X) to EEPROM_VPD_REDUNDANCY (%d)",
                    get_huid(i_target), get_huid(l_ocmbs[0]), newEepromRedundancy);
                l_ocmbs[0]->setAttr<ATTR_EEPROM_VPD_REDUNDANCY>(newEepromRedundancy);

                ATTR_EEPROM_VPD_ACCESSIBILITY_type dimm_eeprom_accessibility =
                    EEPROM_VPD_ACCESSIBILITY_NONE_DISABLED;
                if( i_target->tryGetAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(dimm_eeprom_accessibility) )
                {
                    TRACFCOMP(g_trac_spd,
                        "spdUpdateEepromRedundancy> setting OCMB(0x%08X) to DIMM accessibility setting (%x)",
                        get_huid(l_ocmbs[0]), dimm_eeprom_accessibility);
                    l_ocmbs[0]->setAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(dimm_eeprom_accessibility);
                }
            }
            else
            {
                // This is not expected but OCMB presence is later checked and that should
                // make the OCMBs match the DDIMMs (it might mean another error log though)
                TRACFCOMP(g_trac_spd,
                    "spdUpdateEepromRedundancy> Found %d ocmb parent(s) of DIMM target (0x%08X)",
                    l_ocmbs.size(), get_huid(i_target));
            }
        }
    } while (0);
    return err;
}

// ------------------------------------------------------------------
// spdPresent
// ------------------------------------------------------------------
bool spdPresent ( Target * i_target )
{
    TRACSSCOMP( g_trac_spd, ENTER_MRK"spdPresent(0x%08X)", get_huid(i_target) );

    errlHndl_t err{nullptr};
    uint8_t    memType(MEM_TYPE_INVALID);
    bool       pres(false);

    do
    {

#ifndef __HOSTBOOT_RUNTIME
        if (EEPROM::eepromPresence( i_target ))
        {
            err = getMemType( memType,
                              i_target );

            if ( err )
            {
                // exit loop and return false
                break;
            }

            TRACDCOMP( g_trac_spd,
                       INFO_MRK"Mem Type: 0x%04X",
                       memType );

            if ( !isValidDimmType(memType) )
            {
                TRACFCOMP( g_trac_spd, "spdPresent> Unexpected data 0x%04X found on 0x%08X, checking CRC",
                           memType, get_huid(i_target) );
                std::vector<crc_section_t> l_sections;
                errlHndl_t err2 = SPD::checkCRC( i_target, SPD::CHECK, EEPROM::VPD_AUTO, EEPROM::HARDWARE, l_sections);
                if( err2 )
                {
                    TRACFCOMP( g_trac_spd, "spdPresent> CRC error found, deleting error as it will be checked again later" );
                    // CRC later checked in platPresenceDetect() when it finds the functional OCMBs
                    // and then runs the CRC check on those so this error can be deleted
                    delete err2;
                    err2 = nullptr;

                    // we saw something so default it to DDR4
                    memType = SPD_DDR4_TYPE;
                }

                // Try the other EEPROM if possible
                // If not possible, continue to spdSetSize() which will decide if memType is usable or it will throw an error
                bool l_switched_to_backup = EEPROM::eepromSwitchToBackup(i_target);
                if (l_switched_to_backup)
                {
                    TRACFCOMP(g_trac_spd, "spdPresent> disabled primary access for 0x%08X", get_huid(i_target));

                    /*@
                     * @errortype
                     * @reasoncode       VPD::VPD_SPD_INVALID_PRIMARY_VPD
                     * @moduleid         VPD::VPD_SPD_PRESENCE_DETECT
                     * @userdata1        target huid
                     * @userdata2        invalid memory type
                     * @devdesc          Primary eeprom has invalid data, running on backup eeprom
                     * @custdesc         A problem occurred during the IPL
                     *                   of the system.
                     */
                    err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE_REDUNDANCY_LOST,
                                                   VPD::VPD_SPD_PRESENCE_DETECT,
                                                   VPD::VPD_SPD_INVALID_PRIMARY_VPD,
                                                   get_huid(i_target),
                                                   memType,
                                                   ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                    // VPD is wrong
                    err->addPartCallout( i_target,
                                         HWAS::VPD_PART_TYPE,
                                         HWAS::SRCI_PRIORITY_HIGH );

                    err->addHwCallout( i_target,
                                       HWAS::SRCI_PRIORITY_MED,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL );

                    bool mfgMode = areMfgThresholdsActive();
                    if (!mfgMode)
                    {
                        // field mode, don't make user visible log
                        TRACFCOMP(g_trac_spd, "spdPresent> field mode, so change to RECOVERED error");
                        err->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                    }
                    err->collectTrace( "SPD", 256);
                    errlCommit( err, VPD_COMP_ID );
                    continue;
                }
            }
            else
            {
                err = spdUpdateEepromRedundancy(i_target, memType);
                if (err)
                {
                    errlCommit(err, VPD_COMP_ID);
                    break;
                }
            }

            // Set the SPD size
            err = spdSetSize( *i_target, memType );
            if ( err )
            {
                errlCommit(err, VPD_COMP_ID );

                // exit loop and return false
                break;
            }
            else
            {
                pres = true;
            }
        }

#else // HOSTBOOT_RUNTIME CODE

        // Read the Basic Memory Type
        err = getMemType( memType,
                          i_target );

        if ( err )
        {
            errlCommit(err, VPD_COMP_ID );

            // exit loop and return false
            break;
        }

        TRACDCOMP( g_trac_spd,
                   INFO_MRK"Mem Type: 0x%04X",
                   memType );

        if ( isValidDimmType(memType) )
        {
            // Set the SPD size
            err = spdSetSize( *i_target, memType );
            if ( err )
            {
                errlCommit(err, VPD_COMP_ID );
            }
            else
            {
                pres = true;
            }
        }  // end if ( isValidDimmType(memType) )
#endif
        break;
    } while( !pres ); // only check in continue case (redundant eeprom)

    TRACSSCOMP( g_trac_spd, EXIT_MRK"spdPresent(0x%08X): returning %s",
        get_huid(i_target), (pres ? "true" : "false") );

    return pres;
}



// ------------------------------------------------------------------
// ddr3SpecialCases
// ------------------------------------------------------------------
errlHndl_t ddr3SpecialCases(const KeywordData & i_kwdData,
                            void * io_buffer,
                            Target * i_target)
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
                                i_target );

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
                                i_target );
            break;

        // ==================================================
        // 2 byte - MSB with mask then LSB is 2 more than MSB
        case TRC_MIN:
            // Get MSB
            err = spdFetchData( i_kwdData.offset,
                                1, /* Read 1 byte at a time */
                                &tmpBuffer[0],
                                i_target );

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
                                i_target );
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
                                   Target * i_target,
                                   EEPROM_CONTENT_TYPE i_eepromType)
{
    errlHndl_t errl = nullptr;

    if (i_eepromType == EEPROM_CONTENT_TYPE_ISDIMM)
    {
        errl = spdFetchData(i_byteAddr,
                            i_numBytes,
                            o_data,
                            i_target);
    }
    else if (i_eepromType == EEPROM_CONTENT_TYPE_DDIMM ||
             i_eepromType == EEPROM_CONTENT_TYPE_PLANAR_OCMB_SPD)
    {
        errl = ocmbFetchData(i_target,
                             i_byteAddr,
                             i_numBytes,
                             o_data,
                             EEPROM::AUTOSELECT);
    }
    else
    {
        /*@
         * @moduleid         VPD::VPD_FETCH_DATA_EEPROM_TYPE
         * @reasoncode       VPD::VPD_UNSUPPORTED_EEPROM_TYPE
         * @userdata1        Unsupported EEPROM type
         * @userdata2        HUID of target to read the EEPROM data for
         * @devdesc          The type EEPROM to read for the given target
         *                   is not supported.
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       VPD::VPD_FETCH_DATA_EEPROM_TYPE,
                                       VPD::VPD_UNSUPPORTED_EEPROM_TYPE,
                                       i_eepromType,
                                       get_huid(i_target),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

    return errl;
}

// ------------------------------------------------------------------
// ddr4SpecialCases
// ------------------------------------------------------------------
errlHndl_t ddr4SpecialCases(const KeywordData & i_kwdData,
                            void * io_buffer,
                            Target * i_target)
{
    errlHndl_t err{nullptr};
    uint8_t * tmpBuffer = static_cast<uint8_t *>(io_buffer);

    TRACSSCOMP( g_trac_spd, ENTER_MRK"ddr4SpecialCases()" );

    auto eepromVpd =
        i_target->getAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>();

    EEPROM_CONTENT_TYPE eepromType =
       static_cast<EEPROM_CONTENT_TYPE>(eepromVpd.eepromContentType);

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
                                          eepromType);

            if( err ) break;

            // Get 3rd Byte
            err = fetchDataFromEepromType((i_kwdData.offset - 1),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[1],
                                          i_target,
                                          eepromType);

            if( err ) break;

            // Get 2nd Byte
            err = fetchDataFromEepromType((i_kwdData.offset - 2),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[2],
                                          i_target,
                                          eepromType);

            if( err ) break;

            // Get 1st Byte
            err = fetchDataFromEepromType((i_kwdData.offset - 3),
                                          1, /* Read 1 byte at a time */
                                          &tmpBuffer[3],
                                          i_target,
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
                             Target * i_target,
                             uint64_t i_DDRRev )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"spdSpecialCases()" );

    do
    {
        // Handle each of the special cases here
        if( SPD_DDR3_TYPE == i_DDRRev )
        {
            err = ddr3SpecialCases(i_kwdData,io_buffer,i_target);
        }
        else if (SPD_DDR4_TYPE == i_DDRRev)
        {
            err = ddr4SpecialCases(i_kwdData,io_buffer,i_target);
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
                                     Target * i_target )
{
    errlHndl_t err{nullptr};

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"checkModSpecificKeyword()" );

    do
    {
        // Check that a Module Specific keyword is being accessed from a DIMM
        // of the correct Module Type.
        modSpecTypes_t modType = NA;
        err = getModType(modType, i_target, i_memType);

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
                       "Mem Type: 0x%04X, Mod Type: 0x%04X, Keyword: 0x%04X",
                       i_memType, modType, i_kwdData.keyword );

            uint32_t udUpper32 = TWO_UINT16_TO_UINT32(modType, i_memType);
            uint32_t udLower32 = TWO_UINT16_TO_UINT32(i_kwdData.keyword, i_kwdData.modSpec);
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
                                    get_huid(i_target));

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
                      Target   * i_target,
                      EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};

    err = spdFetchData( MEM_TYPE_ADDR,
                        MEM_TYPE_SZ,
                        &o_memType,
                        i_target,
                        i_eepromSource);

    TRACUCOMP( g_trac_spd,
               EXIT_MRK"SPD::getMemType() - MemType: 0x%02X, Error: %s",
               o_memType, ((NULL == err) ? "No" : "Yes") );

    return err;
}


errlHndl_t getMemType(uint8_t &                  o_memType,
                     Target *         i_target,
                     EEPROM_CONTENT_TYPE i_eepromType,
                     EEPROM::EEPROM_SOURCE       i_eepromSource)
{
    errlHndl_t err = nullptr;

// @TODO RTC 204341 Implement for runtime
#ifndef __HOSTBOOT_RUNTIME

    if ((i_eepromType == EEPROM_CONTENT_TYPE_DDIMM)  ||
        (i_eepromType == EEPROM_CONTENT_TYPE_ISDIMM) ||
        (i_eepromType == EEPROM_CONTENT_TYPE_PLANAR_OCMB_SPD))
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
                                      get_huid(i_target),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

#endif

    return err;

}

// ------------------------------------------------------------------
// getModType
// ------------------------------------------------------------------
errlHndl_t getModType ( modSpecTypes_t & o_modType,
                        Target * i_target,
                        uint64_t i_memType )
{
    errlHndl_t err{nullptr};
    o_modType = NA;

    auto eepromVpd =
        i_target->getAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>();

    EEPROM_CONTENT_TYPE eepromType =
       static_cast<EEPROM_CONTENT_TYPE>(eepromVpd.eepromContentType);

    uint8_t modTypeVal = 0;
    err = fetchDataFromEepromType(MOD_TYPE_ADDR,
                                  MOD_TYPE_SZ,
                                  &modTypeVal,
                                  i_target,
                                  eepromType);

    if (err)
    {
        TRACFCOMP( g_trac_spd, ERR_MRK "SPD::getModType() - Error querying ModType");
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
            else if (MOD_TYPE_PLANAR == modTypeVal)
            {
                o_modType = PLANAR;
            }
        }

        if (o_modType == NA)
        {
            TRACFCOMP( g_trac_spd, ERR_MRK"Module type 0x%02X unrecognized", modTypeVal );

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
                       "SPD::getModType() - Val: 0x%02X, ModType: 0x%02X",
                       modTypeVal, o_modType);
        }
    }

    return err;
}


errlHndl_t getDdimmModHeight(uint8_t & o_dimmModHeight,
                           Target * i_target,
                           EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};

    err = spdFetchData( DDIMM_MOD_HEIGHT_ADDR,
                        DDIMM_MOD_HEIGHT_SZ,
                        &o_dimmModHeight,
                        i_target,
                        i_eepromSource);

    TRACUCOMP( g_trac_spd,
               EXIT_MRK"SPD::getDimmSizeType() - DIMM mod height: 0x%02X, Error: %s",
               o_dimmModHeight, ((nullptr == err) ? "No" : "Yes") );

    return err;
}

// ------------------------------------------------------------------
// getKeywordEntry
// ------------------------------------------------------------------
errlHndl_t getKeywordEntry ( VPD::vpdKeyword i_keyword,
                             uint64_t i_memType,
                             Target * i_target,
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
            err = getModType(modType, i_target, i_memType);
            if (modType == DDIMM)
            {
                arraySize = (sizeof(ddr4DDIMMData)/sizeof(ddr4DDIMMData[0]));
                kwdData = ddr4DDIMMData;
            }
            else if (modType == PLANAR)
            {
                arraySize = (sizeof(planarEepromData)/sizeof(planarEepromData[0]));
                kwdData = planarEepromData;
            }
            else
            {
                arraySize = (sizeof(ddr4Data)/sizeof(ddr4Data[0]));
                kwdData = ddr4Data;
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd, ERR_MRK"Unsupported DDRx Revision (0x%04X)",
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
            TRACFCOMP( g_trac_spd, ERR_MRK"No matching keyword entry found for 0x%X!", i_keyword);

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_KEYWORD_NOT_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_SPD_GET_KEYWORD_ENTRY
             * @userdata1        SPD Keyword
             * @userdata2        target HUID reading the SPD for
             * @devdesc          Invalid SPD Keyword
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_SPD_GET_KEYWORD_ENTRY,
                                           VPD::VPD_KEYWORD_NOT_FOUND,
                                           i_keyword,
                                           get_huid(i_target),
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
void setPartAndSerialNumberAttributes( Target * i_target )
{
    errlHndl_t l_err = nullptr;

    //Default to standard VPD Location for DDIMM SPD SN/PN
    VPD::vpdKeyword l_partKeyword = SPD::MODULE_PART_NUMBER;
    VPD::vpdKeyword l_serialKeyword = SPD::MODULE_SERIAL_NUMBER;
    VPD::vpdKeyword l_ccinKeyword = 0;

    if(UTIL::assertGetToplevelTarget()->getAttr<ATTR_USE_11S_SPD>())
    {
        //Use IBM 11S Location for DDIMM SN/PN/CCIN
        l_partKeyword = SPD::IBM_11S_PN;
        l_serialKeyword = SPD::IBM_11S_SN;
        l_ccinKeyword = SPD::IBM_11S_CC;
    }

    do
    {
        // Read the Basic Memory Type
        uint8_t l_memType(MEM_TYPE_INVALID);
        l_err = getMemType( l_memType,
                            i_target );
        if( l_err )
        {
            TRACFCOMP(g_trac_spd, ERR_MRK
                      "spd.C::setPartAndSerialNumberAttributes(): Error after getMemType");
            break;
        }

        if (false == isValidDimmType(l_memType) )
        {
            TRACFCOMP(g_trac_spd, ERR_MRK
                      "spd.C::setPartAndSerialNumberAttributes(): Unknown memType = 0x%02X",
                      l_memType);
            break;
        }

        // Get the keyword sizes
        const KeywordData* entry = nullptr;
        l_err = getKeywordEntry( l_partKeyword,
                                 l_memType,
                                 i_target,
                                 entry );
        if( l_err )
        {
            break;
        }
        size_t l_partDataSize = entry->length;

        entry = nullptr;
        l_err = getKeywordEntry( l_serialKeyword,
                                 l_memType,
                                 i_target,
                                 entry );
        if( l_err )
        {
            break;
        }
        size_t l_serialDataSize = entry->length;

        size_t l_ccinDataSize = 0;
        if (l_ccinKeyword != 0)
        {
            entry = nullptr;
            l_err = getKeywordEntry( l_ccinKeyword,
                                     l_memType,
                                     i_target,
                                     entry );
            if( l_err )
            {
                break;
            }
            l_ccinDataSize = entry->length;
        }

        TRACDCOMP(g_trac_spd,
                  "l_partDataSize=%d,l_serialDataSize=%d\n",
                  l_partDataSize,l_serialDataSize);

        //read the keywords from the EEPROM
        uint8_t l_partNumberData[l_partDataSize] = {};
        l_err = spdGetValue( l_partKeyword,
                             l_partNumberData,
                             l_partDataSize,
                             i_target,
                             l_memType );
        if( l_err )
        {
            TRACFCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Error after spdGetValue-> PART_NUMBER");
            break;
        }

        uint8_t l_serialNumberData[l_serialDataSize] = {};
        l_err = spdGetValue( l_serialKeyword,
                             l_serialNumberData,
                             l_serialDataSize,
                             i_target,
                             l_memType );
        if( l_err )
        {
            TRACFCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Error after spdGetValue-> SERIAL_NUMBER");
            break;
        }

        uint8_t l_ccinData[l_ccinDataSize] = {};
        if (l_ccinKeyword != 0)
        {
            l_err = spdGetValue( l_ccinKeyword,
                                 l_ccinData,
                                 l_ccinDataSize,
                                 i_target,
                                 l_memType );
            if( l_err )
            {
                TRACFCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Error after spdGetValue-> CCIN");
                break;
            }
        }

        TRACFCOMP(g_trac_spd, "setPartAndSerialNumberAttributes: HUID=0x%08X", get_huid(i_target));

        // Set the attributes
        ATTR_PART_NUMBER_type l_PN = {0};
        size_t expectedPNSize = sizeof(l_PN);
        if(expectedPNSize < l_partDataSize)
        {
            TRACFCOMP(g_trac_spd, "PN data size too large for attribute. Expected: %d Actual: %d"
                    "Keyword: %X",
                    expectedPNSize, l_partDataSize, l_partKeyword);
            l_partDataSize = expectedPNSize; //truncate it
        }
        memcpy(l_PN, l_partNumberData, l_partDataSize);
        i_target->trySetAttr<ATTR_PART_NUMBER>(l_PN);
        TRACFBIN(g_trac_spd,
                 "                                : PART NUMBER =",
                 l_PN, l_partDataSize);

        // FRU Part Number is the same as Part Number for DIMMs
        ATTR_FRU_NUMBER_type l_FN = {0};
        size_t expectedFNSize = sizeof(l_FN);
        if(expectedFNSize < l_partDataSize)
        {
            TRACFCOMP(g_trac_spd, "FN data size too large for attribute. Expected: %d Actual: %d"
                    "Keyword: %X, attribute will be truncated",
                    expectedPNSize, l_partDataSize, l_partKeyword);
            l_partDataSize = expectedFNSize; //truncate it
        }
        memcpy(l_FN, l_partNumberData, l_partDataSize);
        i_target->trySetAttr<ATTR_FRU_NUMBER>(l_FN);
        TRACFBIN(g_trac_spd,
                 "                                : FRU NUMBER =",
                 l_FN, l_partDataSize);

        ATTR_SERIAL_NUMBER_type l_SN = {0};
        size_t expectedSNSize = sizeof(l_SN);
        if(expectedSNSize < l_serialDataSize)
        {
            TRACFCOMP(g_trac_spd, "Serial data size too large for attribute. Expected: %d Actual: %d, attribute will be truncated",
                        expectedSNSize, l_serialDataSize);
            l_serialDataSize = expectedSNSize; //truncate it
        }
        memcpy(l_SN, l_serialNumberData, l_serialDataSize);
        i_target->trySetAttr<ATTR_SERIAL_NUMBER>(l_SN);
        TRACFBIN(g_trac_spd,
                 "                                : SERIAL NUMBER =",
                 l_SN, l_serialDataSize);

        if (l_ccinKeyword != 0)
        {
            ATTR_FRU_CCIN_type l_CC = 0;
            size_t expectedCCSize = sizeof(l_CC);
            if(expectedCCSize < l_ccinDataSize)
            {
                TRACFCOMP(g_trac_spd,
                          "CCIN data size too large for attribute. Expected: %d Actual: %d, attribute will be truncated",
                          expectedCCSize, l_ccinDataSize);
                l_ccinDataSize = expectedCCSize; //truncate it
            }
            memcpy(&l_CC, l_ccinData, l_ccinDataSize);
            i_target->trySetAttr<ATTR_FRU_CCIN>(l_CC);
            TRACFCOMP(g_trac_spd,
                      "                                : CCIN = %lX",
                      l_CC);
        }

    }while( 0 );

    if( l_err )
    {
        TRACFCOMP(g_trac_spd, ERR_MRK"spd.C::setPartAndSerialNumberAttributes(): Committing error and moving on");
        errlCommit(l_err, VPD_COMP_ID);
        l_err = NULL;
    }

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
errlHndl_t readFromEepromSource(Target*          i_target,
                                EEPROM_CONTENT_TYPE i_eepromType,
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
    if (i_eepromType == EEPROM_CONTENT_TYPE_ISDIMM)
    {
        err = spdGetValue(i_keyword,
                          io_buffer,
                          io_buflen,
                          i_target,
                          i_memType,
                          i_eepromSource);
    }
    else if ((i_eepromType == EEPROM_CONTENT_TYPE_DDIMM) ||
             (i_eepromType == EEPROM_CONTENT_TYPE_PLANAR_OCMB_SPD))
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
                                      get_huid(i_target),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
#endif

    return err;
}


// ------------------------------------------------------------------
// cmpEecacheToEeprom
// ------------------------------------------------------------------
errlHndl_t cmpEecacheToEeprom(Target * i_target,
                              EEPROM_CONTENT_TYPE i_eepromType,
                              VPD::vpdKeyword i_keyword,
                              bool &o_match)
{
    errlHndl_t err = nullptr;

    TRACSSCOMP(g_trac_spd, ENTER_MRK"cmpEecacheToEeprom(%08X)", get_huid(i_target));

    // default to a mismatch to force a refresh from the eeprom
    o_match = false;

    // note if we failed with unexpected data
    bool unexpected_data = false;

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
                     "cmpEecacheToEeprom(): Invalid DIMM type (0x%X) found in cache copy of eeprom "
                     "(eeprom content type 0x%X), we will not be able to understand contents",
                     memTypeCache, i_eepromType);
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
            TRACFCOMP(g_trac_spd, ERR_MRK
                     "cmpEecacheToEeprom(): Invalid DIMM type (0x%X) found in hw copy of eeprom "
                     "(eeprom content type 0x%X)",
                     memTypeHardware, i_eepromType);
            unexpected_data = true;
            break;
        }

        if (memTypeCache != memTypeHardware)
        {
            // CACHE and HARDWARE don't match.
            // Leave o_match == false and exit.
            TRACFCOMP(g_trac_spd, ERR_MRK
                     "cmpEecacheToEeprom(): memTypeCache (0x%X) != memTypeHardware (0x%X)",
                     memTypeCache, memTypeHardware);
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
            err = nullptr;
            break;
        }

        TRACDBIN(g_trac_spd, "Hardware data : ", dataHardware, sizeHardware);
        TRACDBIN(g_trac_spd, "Cache data : ", dataCache, sizeCache);

        // Compare the HARDWARE/CACHE keyword size/data
        if (sizeHardware != sizeCache)
        {
            // CACHE and HARDWARE don't match.
            // Leave o_match == false and exit.
            TRACFCOMP( g_trac_spd,
                       "cmpEecacheToEeprom(): CACHE size (0x%X) and HARDWARE "
                       "size (0x%X) are differnt for 0x%08X",
                       sizeCache, sizeHardware, get_huid(i_target) );
            break;
        }
        if (memcmp(dataHardware, dataCache, sizeHardware))
        {
            // CACHE and HARDWARE don't match.
            // Leave o_match == false and exit.
            TRACFCOMP( g_trac_spd,
                       "cmpEecacheToEeprom(): CACHE and HARDWARE "
                       "data don't match for 0x%08X",
                       get_huid(i_target) );
            unexpected_data = true;
            break;
        }

        o_match = true;

    } while(0);

    //P10 DD1 Workaround
    // There is a bug on P10 DD1 that can cause SPD corruption
    // due to some floating i2c lines.  To help out the lab, we
    // want to avoid rereading the data from the physical spd eeprom
    // unless the part is completely new.  If we find a mismatch or
    // other unexpected data we will do a CRC check.  If we find a
    // miscompare we will assume corruption and return that the
    // data is in sync.  Downstream code will then push the cached
    // copy out to the hardware.
    if( !err && unexpected_data )
    {
        if ((i_eepromType == EEPROM_CONTENT_TYPE_DDIMM) ||
            (i_eepromType == EEPROM_CONTENT_TYPE_PLANAR_OCMB_SPD))
        {
            // do CRC check
            TRACFCOMP( g_trac_spd, "cmpEecacheToEeprom> Unexpected data found on 0x%08X, checking CRC",
               get_huid(i_target) );
            //TODO - check for p10 dd1 here
            std::vector<crc_section_t> l_sections;
            errlHndl_t errHW = SPD::checkCRC( i_target, SPD::CHECK, EEPROM::VPD_PRIMARY, EEPROM::HARDWARE, l_sections );
            if( errHW )
            {
                TRACFCOMP( g_trac_spd, "cmpEecacheToEeprom> CRC errors found in hardware" );
            }
            errlHndl_t errCACHE = SPD::checkCRC( i_target, SPD::CHECK, EEPROM::VPD_PRIMARY, EEPROM::CACHE, l_sections );
            if( errCACHE )
            {
                TRACFCOMP( g_trac_spd, "cmpEecacheToEeprom> CRC errors found in cache" );
            }
            // If the cache is bad, force a resync
            // Otherwise if the cache is okay and the HW is bad, assume a match so that
            //  the cache gets pushed out to the HW
            if( !errCACHE && !errHW )
            {
                TRACFCOMP( g_trac_spd, "cmpEecacheToEeprom> No CRC errors found, must be new HW" );
            }
            else
            {
                TRACFCOMP( g_trac_spd, "cmpEecacheToEeprom> Found some CRC errors, forcing cache refresh" );
                // errCACHE error
                // cache is either missing or bad, we want to refresh from the hardware

                // errHW error
                // this could mean a bitflip in the SN/PN itself, or it can mean
                //  we have a new part installed that had bad SPD to begin with
                // To be safe and avoid whacking SPD with old cache, we will just
                //  let this fail out and require repair

                o_match = false;

                // commit any logs we hit as informational, just in case
                if( errCACHE )
                {
                    errCACHE->collectTrace( "SPD", 256);
                    errCACHE->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    ERRORLOG::errlCommit(errCACHE, VPD_COMP_ID );
                }
                if( errHW )
                {
                    errHW->collectTrace( "SPD", 256);
                    errHW->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    ERRORLOG::errlCommit(errHW, VPD_COMP_ID );
                }
            }
        }
        else // other EEPROM_CONTENT_TYPEs
        {
            // don't do the CRC check, only valid for DDIMM and PLANAR_OCMB_SPD
            TRACFCOMP( g_trac_spd, "cmpEecacheToEeprom> Unexpected data found on 0x%08X, must be new HW",
                       get_huid(i_target));
        }

    }

    TRACSSCOMP( g_trac_spd, EXIT_MRK"cmpEecacheToEeprom(): returning %s errors. o_match = %s",
                (err ? "with" : "with no"), o_match ? "True" : "False");

    return err;
}

// In addition to the regular SPD driver, we also want to register against
//  the Generic VPD driver.  We need a wrapper to handle the extra "record"
//  argument though.
errlHndl_t spdGetKeywordValue_generic ( DeviceFW::OperationType i_opType,
                                        Target * i_target,
                                        void * io_buffer,
                                        size_t & io_buflen,
                                        int64_t i_accessType,
                                        va_list i_args )
{
    //first arg is a record that we ignore
    uint64_t l_record = va_arg( i_args, uint64_t );
    assert( l_record == SPD::NO_RECORD );

    //i_args is modified by va_arg so just pass it directly in
    return spdGetKeywordValue(i_opType,
                              i_target,
                              io_buffer,
                              io_buflen,
                              i_accessType,
                              i_args);
}
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::VPD,
                       TYPE_DIMM,
                       spdGetKeywordValue_generic );

errlHndl_t spdWriteKeywordValue_generic ( DeviceFW::OperationType i_opType,
                                          Target * i_target,
                                          void * io_buffer,
                                          size_t & io_buflen,
                                          int64_t i_accessType,
                                          va_list i_args )
{
    //first arg is a record that we ignore
    uint64_t l_record = va_arg( i_args, uint64_t );
    assert( l_record == SPD::NO_RECORD );

    //i_args is modified by va_arg so just pass it directly in
    return spdWriteKeywordValue(i_opType,
                                i_target,
                                io_buffer,
                                io_buflen,
                                i_accessType,
                                i_args);
}
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::VPD,
                       TYPE_DIMM,
                       spdWriteKeywordValue_generic );

DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::VPD,
                       TYPE_OCMB_CHIP,
                       spdWriteKeywordValue_generic );


}; // end namespace SPD
