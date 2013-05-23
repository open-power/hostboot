/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd.C $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
/**
 * @file eepromdd.C
 *
 * @brief Implementation of the EEPROM device driver,
 *      which will access various EEPROMs within the
 *      system via the I2C device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <i2c/eepromddreasoncodes.H>

#include <i2c/eepromif.H>
#include "eepromdd.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_eepromMutex = MUTEX_INITIALIZER;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_eeprom = NULL;
TRAC_INIT( & g_trac_eeprom, "EEPROM", KILOBYTE );

trace_desc_t* g_trac_eepromr = NULL;
TRAC_INIT( & g_trac_eepromr, "EEPROMR", KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define MAX_BYTE_ADDR 2
// ----------------------------------------------

namespace EEPROM
{

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_PROC,
                       eepromPerformOp );

// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_DIMM,
                       eepromPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_MEMBUF,
                       eepromPerformOp );

// ------------------------------------------------------------------
// eepromPerformOp
// ------------------------------------------------------------------
errlHndl_t eepromPerformOp( DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args )
{
    errlHndl_t err = NULL;
    TARGETING::Target * theTarget = NULL;
    eeprom_addr_t i2cInfo;
    i2cInfo.deviceType = LAST_DEVICE_TYPE;

    i2cInfo.chip = va_arg( i_args, uint64_t );
    i2cInfo.offset = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPerformOp()" );

    TRACUCOMP (g_trac_eeprom, ENTER_MRK"eepromPerformOp(): "
               "i_opType=%d, chip=%d, offset=%d, len=%d",
               (uint64_t) i_opType, i2cInfo.chip, i2cInfo.offset, io_buflen);


    do
    {
        // Read Attributes needed to complete the operation
        err = eepromReadAttributes( i_target,
                                    i2cInfo );

        if( err )
        {
            break;
        }

        // Check to see if we need to find a new target for
        // the I2C Master
        err = eepromGetI2CMasterTarget( i_target,
                                        i2cInfo,
                                        theTarget );

        if( err )
        {
            break;
        }

        // Do the read or write
        if( i_opType == DeviceFW::READ )
        {
            err = eepromRead( theTarget,
                              io_buffer,
                              io_buflen,
                              i2cInfo );

            if( err )
            {
                break;
            }
        }
        else if( i_opType == DeviceFW::WRITE )
        {
            err = eepromWrite( theTarget,
                               io_buffer,
                               io_buflen,
                               i2cInfo );

            if( err )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromPerformOp(): Invalid EEPROM Operation!");

            /*@
             * @errortype
             * @reasoncode     EEPROM_INVALID_OPERATION
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       EEPROM_PERFORM_OP
             * @userdata1      Operation Type
             * @userdata2      Chip to Access
             * @devdesc        Invalid Operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_PERFORM_OP,
                                           EEPROM_INVALID_OPERATION,
                                           i_opType,
                                           i2cInfo.chip );

            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end eepromPerformOp


// ------------------------------------------------------------------
// eepromRead
// ------------------------------------------------------------------
errlHndl_t eepromRead ( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t i_buflen,
                        eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    bool unlock = false;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromRead()" );

    do
    {
        TRACSCOMP( g_trac_eepromr,
                   "EEPROM READ  START : Chip: %02d : Offset %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.offset, i_buflen );

        err = eepromPrepareAddress( &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo );

        if( err )
        {
            break;
        }

        // Lock to sequence operations
        mutex_lock( &g_eepromMutex );
        unlock = true;

        // Only write the byte address if we have data to write
        if( 0 != byteAddrSize )
        {
            // Write the Byte Address of the Slave Device
            err = deviceOp( DeviceFW::WRITE,
                            i_target,
                            &byteAddr,
                            byteAddrSize,
                            DEVICE_I2C_ADDRESS( i_i2cInfo.port,
                                                i_i2cInfo.engine,
                                                i_i2cInfo.devAddr ) );

            if( err )
            {
                break;
            }
        }

        // Do the actual read via I2C
        err = deviceOp( DeviceFW::READ,
                        i_target,
                        o_buffer,
                        i_buflen,
                        DEVICE_I2C_ADDRESS( i_i2cInfo.port,
                                            i_i2cInfo.engine,
                                            i_i2cInfo.devAddr ) );

        if( err )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromRead(): I2C Read failed on %d/%d/0x%x",
                       i_i2cInfo.port, i_i2cInfo.engine, i_i2cInfo.devAddr );
            break;
        }

        mutex_unlock( &g_eepromMutex );
        unlock = false;

        TRACSCOMP( g_trac_eepromr,
                   "EEPROM READ  END   : Chip: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.offset, i_buflen,
                   *((uint64_t*)o_buffer) );

    } while( 0 );

    // Catch it if we break out early.
    if( unlock )
    {
        mutex_unlock( & g_eepromMutex );
    }

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromRead()" );

    return err;
} // end eepromRead


// ------------------------------------------------------------------
// eepromWrite
// ------------------------------------------------------------------
errlHndl_t eepromWrite ( TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t io_buflen,
                         eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;
    uint8_t byteAddr[MAX_BYTE_ADDR];
    size_t byteAddrSize = 0;
    uint8_t * newBuffer = NULL;
    bool needFree = false;
    bool unlock = false;
    eeprom_addr_t l_i2cInfo = i_i2cInfo;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromWrite()" );

    do
    {
        TRACSCOMP( g_trac_eepromr,
                   "EEPROM WRITE START : Chip: %02d : Offset %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.offset, io_buflen,
                   *((uint64_t*)io_buffer) );

        err = eepromPrepareAddress( &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo );

        if( err )
        {
            break;
        }


        // EEPROM devices have write page boundaries, so when necessary
        // need to split up command into multiple write operations

        // Setup a max-size buffer of byteAddrSize + writePageSize
        size_t newBufLen = byteAddrSize + i_i2cInfo.writePageSize;
        newBuffer = static_cast<uint8_t*>(malloc( newBufLen ));
        needFree = true;

        // Point a uint8_t ptr at io_buffer for array addressing below
        uint8_t * l_data_ptr = reinterpret_cast<uint8_t*>(io_buffer);

        // Lock for operation sequencing
        mutex_lock( &g_eepromMutex );
        unlock = true;

        // variables to store different amount of data length
        size_t loop_data_length = 0;
        size_t loop_buffer_length = 0;
        size_t total_bytes_written = 0;

        for ( uint64_t i = 0 ;
              (i * i_i2cInfo.writePageSize) < io_buflen ;
              i++)
        {

            if ( (io_buflen - (i * i_i2cInfo.writePageSize) )
                 >= i_i2cInfo.writePageSize)
            {
                // Data to write >= to writePageSize, so write
                //  the maximum amount: writePageSize
                loop_data_length = i_i2cInfo.writePageSize;
            }
            else
            {
                // Less than writePageSize to write
                loop_data_length = io_buflen % i_i2cInfo.writePageSize;
            }

            // Update the offset for each loop
            l_i2cInfo.offset += i * i_i2cInfo.writePageSize;

            err = eepromPrepareAddress( &byteAddr,
                                        byteAddrSize,
                                        l_i2cInfo );

            if (err)
            {
                break;
            }

            // Add the byte address to the buffer
            memcpy( newBuffer,
                    byteAddr,
                    byteAddrSize );

            // Now add the data the user wanted to write
            memcpy( &newBuffer[byteAddrSize],
                    &l_data_ptr[i * i_i2cInfo.writePageSize],
                    loop_data_length);

            // Calculate Total Length
            loop_buffer_length = loop_data_length + byteAddrSize;

            TRACUCOMP(g_trac_eeprom,"eepromWrite() Loop: %d/%d/0x%x "
                "loop=%d, l_b_l=%d, l_d_l=%d, offset=0x%x",
                i_i2cInfo.port, i_i2cInfo.engine,
                i_i2cInfo.devAddr, i, loop_buffer_length, loop_data_length,
                l_i2cInfo.offset);


            // Do the actual data write
            err = deviceOp( DeviceFW::WRITE,
                            i_target,
                            newBuffer,
                            loop_buffer_length,
                            DEVICE_I2C_ADDRESS( i_i2cInfo.port,
                                                i_i2cInfo.engine,
                                                i_i2cInfo.devAddr ) );

            if( err )
            {
                TRACFCOMP(g_trac_eeprom,
                    ERR_MRK"eepromWrite(): I2C Write failed on %d/%d/0x%x "
                    "loop=%d, l_b_l=%d, offset=0x%x",
                    i_i2cInfo.port, i_i2cInfo.engine,
                    i_i2cInfo.devAddr, i, loop_buffer_length, l_i2cInfo.offset);


                // Can't assume that anything was written if
                // there was an error, so no update to total_bytes_written
                // for this loop
                break;
            }

            // Update how much data was written
            total_bytes_written += loop_data_length;
        }

        // Release mutex lock
        mutex_unlock( &g_eepromMutex );
        unlock = false;

        // Set how much data was actually written
        io_buflen = total_bytes_written;

        if( err )
        {
            // Leave do-while loop
            break;
        }


        TRACSCOMP( g_trac_eepromr,
                   "EEPROM WRITE END   : Chip: %02d : Offset %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.offset, io_buflen );
    } while( 0 );

    // Free memory
    if( needFree )
    {
        free( newBuffer );
    }

    // Catch it if we break out early.
    if( unlock )
    {
        mutex_unlock( & g_eepromMutex );
    }

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromWrite()" );

    return err;
} // end eepromWrite


// ------------------------------------------------------------------
// eepromPrepareAddress
// ------------------------------------------------------------------
errlHndl_t eepromPrepareAddress ( void * o_buffer,
                                  size_t & o_bufSize,
                                  eeprom_addr_t i_i2cInfo )
{
    errlHndl_t err = NULL;

    o_bufSize = 0;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPrepareAddress()" );

    do
    {
        // --------------------------------------------------------------------
        // @todo RTC:72715 - support different I2C devices and the way
        // they handle addressing.  A new attribute will need to be added to
        // EEPROM_ADDR_INFOx to indicate the device type so the addressing
        // here can be handled properly.
        //
        // Until we get a different device, we'll just code for the 2 examples
        // that I know of now.
        // --------------------------------------------------------------------
        switch( i_i2cInfo.deviceType )
        {
            case TWO_BYTE_ADDR:
                o_bufSize = 2;
                memset( o_buffer, 0x0, o_bufSize );
                *((uint8_t*)o_buffer) = (i_i2cInfo.offset & 0xFF00ull) >> 8;
                *((uint8_t*)o_buffer+1) = (i_i2cInfo.offset & 0x00FFull);
                break;

            case ONE_BYTE_ADDR:
                o_bufSize = 1;
                memset( o_buffer, 0x0, o_bufSize );
                *((uint8_t*)o_buffer) = (i_i2cInfo.offset & 0xFFull);
                break;

            default:
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromPrepareAddress() - Invalid device type: %08x",
                           i_i2cInfo.deviceType );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_INVALID_DEVICE_TYPE
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_PREPAREADDRESS
                 * @userdata1        Device Type
                 * @userdata2        EEPROM chip
                 * @devdesc          The Device type was not recognized as one supported.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_PREPAREADDRESS,
                                               EEPROM_INVALID_DEVICE_TYPE,
                                               i_i2cInfo.deviceType,
                                               i_i2cInfo.chip );

                break;
        };

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPrepareAddress()" );

    return err;
} // end eepromPrepareAddress


// ------------------------------------------------------------------
// eepromReadAttributes
// ------------------------------------------------------------------
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & o_i2cInfo )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromReadAttributes()" );

    do
    {
        if( VPD_PRIMARY == o_i2cInfo.chip )
        {
            // Read Attributes from EEPROM_VPD_PRIMARY_INFO
            TARGETING::EepromVpdPrimaryInfo eepromData;
            if( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                                    ( eepromData ) )
            {
                o_i2cInfo.chipTypeEnum = VPD_PRIMARY;
                o_i2cInfo.port = eepromData.port;
                o_i2cInfo.devAddr = eepromData.devAddr;
                o_i2cInfo.engine = eepromData.engine;
                o_i2cInfo.i2cMasterPath = eepromData.i2cMasterPath;

                // @todo RTC:72715 - More attributes to be read
                o_i2cInfo.deviceType = TWO_BYTE_ADDR;
                o_i2cInfo.writePageSize = 128;

            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - ERROR reading "
                           "attributes for chip %d! (VPD_PRIMARY)",
                           o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_VPD_PRIMARY_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2[0:31]  EEPROM chip
                 * @userdata2[32:63] Attribute Enumeration
                 * @devdesc          ATTR_EEPROM_VPD_PRIMARY_INFO Attribute
                 *                   was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_VPD_PRIMARY_INFO_NOT_FOUND,
                                    TARGETING::get_huid(i_target),
                                    TWO_UINT32_TO_UINT64(
                                      o_i2cInfo.chip,
                                      TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO));

                break;
            }
        }
        else if( VPD_BACKUP == o_i2cInfo.chip )
        {
            // Read Attributes from EEPROM_VPD_BACKUP_INFO
            TARGETING::EepromVpdBackupInfo eepromData;
            if( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                                    ( eepromData ) )
            {
                o_i2cInfo.chipTypeEnum = VPD_BACKUP;
                o_i2cInfo.port = eepromData.port;
                o_i2cInfo.devAddr = eepromData.devAddr;
                o_i2cInfo.engine = eepromData.engine;
                o_i2cInfo.i2cMasterPath = eepromData.i2cMasterPath;

                // @todo RTC:72715 - More attributes to be read
                o_i2cInfo.deviceType = TWO_BYTE_ADDR;
                o_i2cInfo.writePageSize = 128;
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - ERROR reading "
                           "attributes for chip %d! (VPD_BACKUP)",
                           o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_VPD_BACKUP_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2[0:31]  EEPROM chip
                 * @userdata2[32:63] Attribute Enumeration
                 * @devdesc          ATTR_EEPROM_VPD_BACKUP_INFO Attribute
                 *                   was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_VPD_BACKUP_INFO_NOT_FOUND,
                                    TARGETING::get_huid(i_target),
                                    TWO_UINT32_TO_UINT64(
                                      o_i2cInfo.chip,
                                      TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO));

                break;
            }
        }
        else if( SBE_PRIMARY == o_i2cInfo.chip )
        {
            // Read Attributes from EEPROM_SBE_PRIMARY_INFO
            TARGETING::EepromSbePrimaryInfo eepromData;
            if( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO>
                                    ( eepromData ) )
            {
                o_i2cInfo.chipTypeEnum = SBE_PRIMARY;
                o_i2cInfo.port = eepromData.port;
                o_i2cInfo.devAddr = eepromData.devAddr;
                o_i2cInfo.engine = eepromData.engine;
                o_i2cInfo.i2cMasterPath = eepromData.i2cMasterPath;

                // @todo RTC:72715 - More attributes to be read
                o_i2cInfo.deviceType = TWO_BYTE_ADDR;
                o_i2cInfo.writePageSize = 128;
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - ERROR reading "
                           "attributes for chip %d! (SBE_PRIMARY)",
                           o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_SBE_PRIMARY_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2[0:31]  EEPROM chip
                 * @userdata2[32:63] Attribute Enumeration
                 * @devdesc          ATTR_EEPROM_SBE_PRIMARY_INFO Attribute
                 *                   was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_SBE_PRIMARY_INFO_NOT_FOUND,
                                    TARGETING::get_huid(i_target),
                                    TWO_UINT32_TO_UINT64(
                                      o_i2cInfo.chip,
                                      TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO));

                break;
            }
        }
        else if( SBE_BACKUP == o_i2cInfo.chip )
        {
            // Read Attributes from EEPROM_SBE_BACKUP_INFO
            TARGETING::EepromSbeBackupInfo eepromData;
            if( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO>
                                    ( eepromData ) )
            {
                o_i2cInfo.chipTypeEnum = SBE_BACKUP;
                o_i2cInfo.port = eepromData.port;
                o_i2cInfo.devAddr = eepromData.devAddr;
                o_i2cInfo.engine = eepromData.engine;
                o_i2cInfo.i2cMasterPath = eepromData.i2cMasterPath;

                // @todo RTC:72715 - More attributes to be read
                o_i2cInfo.deviceType = TWO_BYTE_ADDR;
                o_i2cInfo.writePageSize = 128;
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - ERROR reading "
                           "attributes for chip %d! (SBE_BACKUP)",
                           o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_SBE_BACKUP_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2[0:31]  EEPROM chip
                 * @userdata2[32:63] Attribute Enumeration
                 * @devdesc          ATTR_EEPROM_SBE_BACKUP_INFO Attribute
                 *                   was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_SBE_BACKUP_INFO_NOT_FOUND,
                                    TARGETING::get_huid(i_target),
                                    TWO_UINT32_TO_UINT64(
                                      o_i2cInfo.chip,
                                      TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO));

                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromReadAttributes() - Invalid chip (%d) to read "
                       "attributes from!",
                       o_i2cInfo.chip );

            /*@
             * @errortype
             * @reasoncode       EEPROM_INVALID_CHIP
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_READATTRIBUTES
             * @userdata1        EEPROM Chip
             * @userdata2        HUID of target
             * @devdesc          Invalid EEPROM chip to access
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_READATTRIBUTES,
                                           EEPROM_INVALID_CHIP,
                                           o_i2cInfo.chip,
                                           TARGETING::get_huid(i_target) );

            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromReadAttributes()" );

    return err;
} // end eepromReadAttributes


// ------------------------------------------------------------------
// eepromGetI2CMasterTarget
// ------------------------------------------------------------------
errlHndl_t eepromGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      eeprom_addr_t i_i2cInfo,
                                      TARGETING::Target * &o_target )
{
    errlHndl_t err = NULL;
    o_target = NULL;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromGetI2CMasterTarget()" );

    do
    {
        if( TARGETING::TYPE_DIMM == i_target->getAttr<TARGETING::ATTR_TYPE>() )
        {
            TARGETING::TargetService& tS = TARGETING::targetService();

            // For DIMMs we need to get the parent that contains the
            // I2C Master that talks to the DIMM EEPROM

            // The path was read from the attribute via eepromReadAttributes()
            // and passed to this function in i_i2cInfo


            // check that the path exists
            bool exists = false;
            tS.exists( i_i2cInfo.i2cMasterPath,
                       exists );

            if( !exists )
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromGetI2CMasterTarget() - i2cMasterPath attribute path "
                           "doesn't exist!" );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_DIMM_I2C_MASTER_PATH_ERROR
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_GETI2CMASTERTARGET
                 * @userdata1        Attribute Chip Type Enum
                 * @userdata2        HUID of target
                 * @devdesc          DIMM I2C Master Entity path doesn't exist.
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_GETI2CMASTERTARGET,
                                    EEPROM_DIMM_I2C_MASTER_PATH_ERROR,
                                    i_i2cInfo.chipTypeEnum,
                                    TARGETING::get_huid(i_target) );

                break;
            }

            // Since it exists, convert to a target
            o_target = tS.toTarget( i_i2cInfo.i2cMasterPath );

            if( NULL == o_target )
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromGetI2CMasterTarget() - I2C Master "
                                  "Path target was NULL!" );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_TARGET_NULL
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_GETI2CMASTERTARGET
                 * @userdata1        Attribute Chip Type Enum
                 * @userdata2        HUID of target
                 * @devdesc          I2C Master Path Target is NULL.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_GETI2CMASTERTARGET,
                                               EEPROM_TARGET_NULL,
                                               i_i2cInfo.chipTypeEnum,
                                               TARGETING::get_huid(i_target) );

                break;
            }
        }
        else
        {
            // Since current target is not a DIMM, use the target we have
            o_target = i_target;
        }
    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromGetI2CMasterTarget()" );

    return err;
} // end eepromGetI2CMasterTarget

} // end namespace EEPROM
