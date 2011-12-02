//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/i2c/eepromdd.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#include <targeting/targetservice.H>
#include <devicefw/driverif.H>
#include <i2c/eepromddreasoncodes.H>

#include "eepromdd.H"
// ----------------------------------------------
// Globals
// ----------------------------------------------
mutex_t g_eepromMutex;
bool g_initEepromMutex = true;

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_eeprom = NULL;
TRAC_INIT( & g_trac_eeprom, "EEPROM", 4096 );

trace_desc_t* g_trac_eepromr = NULL;
TRAC_INIT( & g_trac_eepromr, "EEPROMR", 4096 );

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

    i2cInfo.addr = va_arg( i_args, uint64_t );
    i2cInfo.chip = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPerformOp()" );

    do
    {
        if( g_initEepromMutex )
        {
            mutex_init( &g_eepromMutex );
            g_initEepromMutex = false;
        }

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
                       ERR_MRK"Invalid EEPROM Operation!" );

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
                   "EEPROM READ  START : Chip: %02d : Addr %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.addr, i_buflen );

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
            break;
        }

        mutex_unlock( &g_eepromMutex );
        unlock = false;

        TRACSCOMP( g_trac_eepromr,
                   "EEPROM READ  END   : Chip: %02d : Addr %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.addr, i_buflen, *((uint64_t*)o_buffer) );
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
    bool needFree = true;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromWrite()" );

    do
    {
        TRACSCOMP( g_trac_eepromr,
                   "EEPROM WRITE START : Chip: %02d : Addr %.2X : Len %d : %016llx",
                   i_i2cInfo.chip, i_i2cInfo.addr, io_buflen, *((uint64_t*)io_buffer) );

        err = eepromPrepareAddress( &byteAddr,
                                    byteAddrSize,
                                    i_i2cInfo );

        if( err )
        {
            break;
        }

        size_t newBufLen = byteAddrSize + io_buflen;
        newBuffer = static_cast<uint8_t*>(malloc( newBufLen ));
        needFree = true;

        // If we have an address to add to the buffer, do it now.
        // Add the byte address to the buffer
        memcpy( newBuffer, byteAddr, byteAddrSize );

        // Now add the data the user wanted to write
        memcpy( &newBuffer[byteAddrSize], io_buffer, io_buflen );

        // Lock for operation sequencing
        mutex_lock( &g_eepromMutex );

        // Do the actual data write
        err = deviceOp( DeviceFW::WRITE,
                        i_target,
                        newBuffer,
                        newBufLen,
                        DEVICE_I2C_ADDRESS( i_i2cInfo.port,
                                            i_i2cInfo.engine,
                                            i_i2cInfo.devAddr ) );

        mutex_unlock( &g_eepromMutex );

        if( err )
        {
            // Can't assume that anything was written if
            // there was an error.
            io_buflen = 0;
            break;
        }

        io_buflen = newBufLen - byteAddrSize;

        TRACSCOMP( g_trac_eepromr,
                   "EEPROM WRITE END   : Chip: %02d : Addr %.2X : Len %d",
                   i_i2cInfo.chip, i_i2cInfo.addr, io_buflen );
    } while( 0 );

    // Free memory
    if( needFree )
    {
        free( newBuffer );
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
        // TODO - eventually there will be different I2C devices and the way
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
                *((uint8_t*)o_buffer) = (i_i2cInfo.addr & 0xFF00ull) >> 8;
                *((uint8_t*)o_buffer+1) = (i_i2cInfo.addr & 0x00FFull);
                break;

            case ONE_BYTE_ADDR:
                o_bufSize = 1;
                memset( o_buffer, 0x0, o_bufSize );
                *((uint8_t*)o_buffer) = (i_i2cInfo.addr & 0xFFull);
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
                 * @userdata2        <UNUSED>
                 * @devdesc          The Device type was not recognized as one supported.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_PREPAREADDRESS,
                                               EEPROM_INVALID_DEVICE_TYPE,
                                               i_i2cInfo.deviceType,
                                               0x0 );

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
        if( 0 == o_i2cInfo.chip )
        {
            // Read Attributes from EEPROM_ADDR_INFO0
            TARGETING::EepromAddrInfo0 eepromData;
            if( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_ADDR_INFO0>( eepromData ) )
            {
                o_i2cInfo.port = eepromData.port;
                o_i2cInfo.devAddr = eepromData.devAddr;
                o_i2cInfo.engine = eepromData.engine;
                // TODO - eventually read out the slave device type
                o_i2cInfo.deviceType = TWO_BYTE_ADDR;
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - ERROR reading attributes for "
                           "chip %d!",
                           o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_ADDR_INFO0_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        EEPROM chip
                 * @userdata2        Attribute Enumeration
                 * @devdesc          ATTR_EEPROM_ADDR_INFO0 Attribute was not found
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_READATTRIBUTES,
                                               EEPROM_ADDR_INFO0_NOT_FOUND,
                                               o_i2cInfo.chip,
                                               TARGETING::ATTR_EEPROM_ADDR_INFO0 );

                break;
            }
        }
        else if( 1 == o_i2cInfo.chip )
        {
            // Read Attributes from EEPROM_ADDR_INFO1
            TARGETING::EepromAddrInfo1 eepromData;
            if( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_ADDR_INFO1>( eepromData ) )
            {
                o_i2cInfo.port = eepromData.port;
                o_i2cInfo.devAddr = eepromData.devAddr;
                o_i2cInfo.engine = eepromData.engine;
                // TODO - eventually read out the slave device type
                o_i2cInfo.deviceType = TWO_BYTE_ADDR;
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - ERROR reading attributes for "
                           "chip %d!",
                           o_i2cInfo.chip );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_ADDR_INFO1_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        EEPROM Chip
                 * @userdata2        Attribute Enum
                 * @devdesc          ATTR_EEPROM_ADDR_INFO0 Attribute was not found
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_READATTRIBUTES,
                                               EEPROM_ADDR_INFO1_NOT_FOUND,
                                               o_i2cInfo.chip,
                                               TARGETING::ATTR_EEPROM_ADDR_INFO1 );

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
             * @userdata2        <UNUSED>
             * @devdesc          Invalid EEPROM chip to access
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_READATTRIBUTES,
                                           EEPROM_INVALID_CHIP,
                                           o_i2cInfo.chip,
                                           0x0 );

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
            // I2C Master that talks to the DIMM EEPROM.  Read the path
            // from the attributes
            TARGETING::EepromAddrInfo0 eepromData;
            eepromData = i_target->getAttr<TARGETING::ATTR_EEPROM_ADDR_INFO0>();

            // check that the path exists
            bool exists = false;
            tS.exists( eepromData.i2cMasterPath,
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
                 * @userdata1        Attribute Enum
                 * @userdata2        <UNUSED>
                 * @devdesc          DIMM I2C Master Entity path doesn't exist.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_GETI2CMASTERTARGET,
                                               EEPROM_DIMM_I2C_MASTER_PATH_ERROR,
                                               TARGETING::ATTR_EEPROM_ADDR_INFO0,
                                               0x0 );

                break;
            }

            // Since it exists, convert to a target
            o_target = tS.toTarget( eepromData.i2cMasterPath );

            if( NULL == o_target )
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromGetI2CMasterTarget() - Parent Processor target "
                           "was NULL!" );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_TARGET_NULL
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_GETI2CMASTERTARGET
                 * @userdata1        <UNUSED>
                 * @userdata2        <UNUSED>
                 * @devdesc          Processor Target is NULL.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               EEPROM_GETI2CMASTERTARGET,
                                               EEPROM_TARGET_NULL,
                                               0x0,
                                               0x0 );

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
