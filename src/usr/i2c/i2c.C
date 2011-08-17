//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/i2c/i2c.C $
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
 * @file i2c.C
 *
 * @brief Implementation of the i2c device driver
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
#include <i2c/i2creasoncodes.H>

#include "i2c.H"
// ----------------------------------------------
// Trace definitions
trace_desc_t* g_trac_i2c = NULL;
TRAC_INIT( & g_trac_i2c, "I2C", 4096 );

trace_desc_t* g_trac_i2cr = NULL;
TRAC_INIT( & g_trac_i2cr, "I2CR", 4096 );

namespace I2C
{

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::I2C,
                       TARGETING::TYPE_PROC,
                       i2cPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::I2C,
                       TARGETING::TYPE_MEMBUF,
                       i2cPerformOp );

// ------------------------------------------------------------------
// i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t i2cPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args )
{
    errlHndl_t err = NULL;

    // Get the input args our of the va_list
    //  Address, Port, Engine, Device Addr.
    input_args_t args;
    args.addr = va_arg( i_args, uint64_t );
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cPerformOp()" );

    do
    {
        // Check for Master Sentinel chip
        if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cPerformOp() - Cannot target Master Sentinel Chip "
                       "for an I2C Operation!" );

            /*@
             * @errortype
             * @reasoncode     I2C_MASTER_SENTINEL_TARGET
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_PERFORM_OP
             * @userdata1      Operation Type requested
             * @userdata2      <UNUSED>
             * @devdesc        Master Sentinel chip was used as a target for an
             *                 I2C operation.  This is NOT permitted.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PERFORM_OP,
                                           I2C_MASTER_SENTINEL_TARGET,
                                           i_opType,
                                           0x0 );

            break;
        }

        // TODO - Locking needs to be implemented for each engine on each
        // possible chip.  The details of this still need to be worked out.
        // This will be implemented with the bad machine path story (3629).

        if( i_opType == DeviceFW::READ )
        {
            err = i2cRead( i_target,
                           io_buffer,
                           io_buflen,
                           args );

            if( err )
            {
                break;
            }
        }
        else if( i_opType == DeviceFW::WRITE )
        {
            err = i2cWrite( i_target,
                            io_buffer,
                            io_buflen,
                            args );

            if( err )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cPerformOp() - Unknown Operation Type!" );

            /*@
             * @errortype
             * @reasoncode     I2C_INVALID_OP_TYPE
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       I2C_PERFORM_OP
             * @userdata1      i_opType
             * @userdata2      addr
             * @devdesc        Invalid Operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PERFORM_OP,
                                           I2C_INVALID_OP_TYPE,
                                           i_opType,
                                           args.addr );

            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end i2cPerformOp

// ------------------------------------------------------------------
// i2cRead
// ------------------------------------------------------------------
errlHndl_t i2cRead ( TARGETING::Target * i_target,
                     void * o_buffer,
                     size_t & i_buflen,
                     input_args_t i_args )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);
    uint64_t bytesRead = 0x0;

    uint64_t addr = i_args.addr;
    uint64_t engine = i_args.engine;
    uint64_t devAddr = i_args.devAddr;

    // TODO - hardcoded to 400KHz for now
    uint64_t interval = I2C_TIMEOUT_INTERVAL( I2C_CLOCK_DIVISOR_400KHZ );
    uint64_t timeoutCount = I2C_TIMEOUT_COUNT( interval );

    // Define the regs we'll be using
    cmdreg cmd;
    statusreg status;
    fiforeg fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cRead()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  START : engine %.2X : devAddr %.2X : addr %.4X : len %d",
               engine, devAddr, addr, i_buflen );

    do
    {
        // Do Command/Mode reg setups.
        size_t tmpSize = 0;
        err = i2cSetup( i_target,
                        tmpSize,    // First length is always 0 for reads (byte addr)
                        false,      // RnW, false to do initial setup of byte addr
                        false,
                        i_args );

        if( err )
        {
            break;
        }

        // Write the 2byte address to the FIFO
        err = i2cWriteByteAddr( i_target,
                                i_args );

        if( err )
        {
            break;
        }

        // Wait for cmd complete before continuing
        err = i2cWaitForCmdComp( i_target,
                                 engine );

        if( err )
        {
            break;
        }

        // Setup the Command register to start the read operation
        cmd.value = 0x0ull;
        cmd.with_start = 1;
        cmd.with_stop = 1;
        cmd.with_addr = 1;
        cmd.device_addr = devAddr;
        cmd.read_not_write = 1;     // Now doing a read
        cmd.length_b = i_buflen;

        err = deviceWrite( i_target,
                           &cmd.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].command ) );

        if( err )
        {
            break;
        }

        for( bytesRead = 0; bytesRead < i_buflen; bytesRead++ )
        {
            TRACDCOMP( g_trac_i2c,
                       INFO_MRK"Reading byte (%d) out of (%d)",
                       (bytesRead+1), i_buflen );

            // Read the status reg to see if there is data in the FIFO
            status.value = 0x0ull;
            err = i2cReadStatusReg( i_target,
                                    engine,
                                    status );

            if( err )
            {
                break;
            }

            while( 0 == status.fifo_entry_count )
            {
                nanosleep( 0, (interval * 1000) );

                status.value = 0x0ull;
                err = i2cReadStatusReg( i_target,
                                        engine,
                                        status );

                if( err )
                {
                    break;
                }

                if( 0 == timeoutCount-- )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cRead() - Timed out waiting for data in FIFO!" );

                    /*@
                     * @errortype
                     * @reasoncode     I2C_FIFO_TIMEOUT
                     * @severity       ERRL_SEV_UNRECOVERABLE
                     * @moduleid       I2C_READ
                     * @userdata1      Status Register Value
                     * @userdata2      Byte Address of write
                     * @devdesc        Timed out waiting for data in FIFO to read
                     */
                    err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                   I2C_READ,
                                                   I2C_FIFO_TIMEOUT,
                                                   status.value,
                                                   addr );

                    break;
                }
            }

            if( err )
            {
                break;
            }

            // Read the data from the fifo
            fifo.value = 0x0ull;
            err = deviceRead( i_target,
                              &fifo.value,
                              size,
                              DEVICE_SCOM_ADDRESS( masterAddrs[engine].fifo ) );

            if( err )
            {
                break;
            }

            *((uint8_t*)o_buffer + bytesRead) = fifo.byte_0;

            TRACSCOMP( g_trac_i2cr,
                       "I2C READ  DATA  : engine %.2X : devAddr %.2X : addr %.4X : "
                       // TODO - when trace parameter limit is lifted, add byte count back in
//                       "byte %d : %.2X",
                       "%.2X",
                       engine, devAddr, addr, /*bytesRead,*/ fifo.byte_0 );
        }

        if( err )
        {
            break;
        }

        // Poll for Command Complete
        err = i2cWaitForCmdComp( i_target,
                                 engine );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  END   : engine %.2X : devAddr %.2X : addr %.4X : len %d",
               engine, devAddr, addr, i_buflen );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cRead()" );

    return err;
} // end i2cRead

// ------------------------------------------------------------------
// i2cWrite
// ------------------------------------------------------------------
errlHndl_t i2cWrite ( TARGETING::Target * i_target,
                      void * i_buffer,
                      size_t & io_buflen,
                      input_args_t i_args )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);
    uint64_t bytesWritten = 0x0;

    uint64_t addr = i_args.addr;
    uint64_t engine = i_args.engine;
    uint64_t devAddr = i_args.devAddr;

    // Define regs we'll be using
    fiforeg fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWrite()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C WRITE START : engine %.2X : devAddr %.2X : addr %.4X : len %d",
               engine, devAddr, addr, io_buflen );

    do
    {
        // Do Command/Mode reg setups
        err = i2cSetup( i_target,
                        io_buflen,
                        false,
                        true,
                        i_args );

        if( err )
        {
            break;
        }

        // Write the 2 byte address to the FIFO
        err = i2cWriteByteAddr( i_target,
                                i_args );

        if( err )
        {
            break;
        }

        for( bytesWritten = 0x0; bytesWritten < io_buflen; bytesWritten++ )
        {
            // Wait for FIFO space to be available for the write
            err = i2cWaitForFifoSpace( i_target,
                                       i_args );

            if( err )
            {
                break;
            }

            // Write data to FIFO
            fifo.value = 0x0ull;
            fifo.byte_0 = *((uint8_t*)i_buffer + bytesWritten);

            err = deviceWrite( i_target,
                               &fifo.value,
                               size,
                               DEVICE_SCOM_ADDRESS( masterAddrs[engine].fifo ) );

            if( err )
            {
                break;
            }

            TRACSCOMP( g_trac_i2cr,
                       "I2C WRITE DATA  : engine %.2X : devAddr %.2X : addr %.4X : "
                       // TODO - Once trace paramenter limit is lifted add byte count in
                       "%.2X",
//                       "byte %d : %.2X",
                       engine, devAddr, addr, /*bytesWritten,*/ fifo.byte_0 );
        }

        if( err )
        {
            break;
        }

        // Check for Command complete, and make sure no errors
        err = i2cWaitForCmdComp( i_target,
                                 engine );

        if( err )
        {
            break;
        }

        // Make sure we send back how many bytes were written
        io_buflen = bytesWritten;
    } while( 0 );

    TRACSCOMP( g_trac_i2cr,
               "I2C WRITE END   : engine %.2X : devAddr %.2X : addr %.4X : len %d",
               engine, devAddr, addr, io_buflen );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cWrite()" );

    return err;
} // end i2cWrite

// ------------------------------------------------------------------
// i2cSetup
// ------------------------------------------------------------------
errlHndl_t i2cSetup ( TARGETING::Target * i_target,
                      size_t & i_buflen,
                      bool i_readNotWrite,
                      bool i_withStop,
                      input_args_t i_args )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    uint64_t port = i_args.port;
    uint64_t engine = i_args.engine;
    uint64_t devAddr = i_args.devAddr;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetup()" );

    // Define the registers that we'll use
    statusreg status;
    modereg mode;
    cmdreg cmd;

    do
    {
        // TODO - Validate some of the arg values passed in

        // Wait for Command complete before we start
        status.value = 0x0ull;
        err = i2cWaitForCmdComp( i_target,
                                 engine );

        if( err )
        {
            break;
        }

        // Write Mode Register:
        //      - bit rate divisor
        //      - port number
        mode.value = 0x0ull;

        // Hard code to 400KHz until we get attributes in place to get this from
        // the target.
        mode.bit_rate_div = I2C_CLOCK_DIVISOR_400KHZ;
        mode.port_num = port;

        err = deviceWrite( i_target,
                           &mode.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].mode ) );

        if( err )
        {
            break;
        }

        // Write Command Register:
        //      - with start
        //      - with stop
        //      - RnW
        //      - length
        cmd.value = 0x0ull;
        cmd.with_start = 1;
        cmd.with_stop = (i_withStop ? 1 : 0);
        cmd.with_addr = 1;
        cmd.device_addr = devAddr;
        cmd.read_not_write = (i_readNotWrite ? 1 : 0);

        // Need to accomodate the byte addr length when writing
        // to the FIFO, so add 2 bytes to the length.
        cmd.length_b = i_buflen + 2;

        err = deviceWrite( i_target,
                           &cmd.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].command ) );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetup()" );

    return err;
} // end i2cSetup

// ------------------------------------------------------------------
// i2cWaitForCmdComp
// ------------------------------------------------------------------
errlHndl_t i2cWaitForCmdComp ( TARGETING::Target * i_target,
                               uint64_t i_engine )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWaitForCmdComp()" );

    // Define the registers that we'll use
    statusreg status;

    // TODO - hardcoded to 400KHz for now.
    uint64_t interval = I2C_TIMEOUT_INTERVAL( I2C_CLOCK_DIVISOR_400KHZ );
    uint64_t timeoutCount = I2C_TIMEOUT_COUNT( interval );

    do
    {
        // Check the Command Complete bit
        do
        {
            nanosleep( 0, (interval * 1000) );
            status.value = 0x0ull;
            err = i2cReadStatusReg( i_target,
                                    i_engine,
                                    status );

            if( err )
            {
                break;
            }

            if( 0 == timeoutCount-- )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cWaitForCmdComp() - Timed out waiting for Command Complete!" );

                /*@
                 * @errortype
                 * @reasoncode     I2C_CMD_COMP_TIMEOUT
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       I2C_WAIT_FOR_CMD_COMP
                 * @userdata1      Status Register Value
                 * @userdata2      Master Engine
                 * @devdesc        Timed out waiting for command complete.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_WAIT_FOR_CMD_COMP,
                                               I2C_CMD_COMP_TIMEOUT,
                                               status.value,
                                               i_engine );

                break;
            }
        } while( 0 == status.command_complete ); /* Command Complete */

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cWaitForCmdComp()" );

    return err;
} // end i2cWaitForBus

// ------------------------------------------------------------------
// i2cReadStatusReg
// ------------------------------------------------------------------
errlHndl_t i2cReadStatusReg ( TARGETING::Target * i_target,
                              uint64_t i_engine,
                              statusreg & o_statusReg )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cReadStatusReg()" );

    do
    {
        // Read the status Reg
        err = deviceRead( i_target,
                          &o_statusReg.value,
                          size,
                          DEVICE_SCOM_ADDRESS( masterAddrs[i_engine].status ) );

        if( err )
        {
            break;
        }

        // Check for Errors
        // Per the specification it is a requirement to check for errors each time
        // that the status register is read.
        err = i2cCheckForErrors( i_target,
                                 o_statusReg );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cReadStatusReg()" );

    return err;
} // end i2cReadStatusReg

// ------------------------------------------------------------------
// i2cCheckForErrors
// ------------------------------------------------------------------
errlHndl_t i2cCheckForErrors ( TARGETING::Target * i_target,
                               statusreg i_statusVal )
{
    errlHndl_t err = NULL;
    i2cReasonCode reasonCode = I2C_INVALID_REASONCODE;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cCheckForErrors()" );

    do
    {
        if( 1 == i_statusVal.invalid_cmd )
        {
            reasonCode = I2C_INVALID_COMMAND;
        }
        else if( 1 == i_statusVal.lbus_parity_error )
        {
            reasonCode = I2C_LBUS_PARITY_ERROR;
        }
        else if( 1 == i_statusVal.backend_overrun_error )
        {
            reasonCode = I2C_BACKEND_OVERRUN_ERROR;
        }
        else if( 1 == i_statusVal.backend_access_error )
        {
            reasonCode = I2C_BACKEND_ACCESS_ERROR;
        }
        else if( 1 == i_statusVal.arbitration_lost_error )
        {
            reasonCode = I2C_ARBITRATION_LOST_ERROR;
        }
        else if( 1 == i_statusVal.nack_received )
        {
            reasonCode = I2C_NACK_RECEIVED;
        }
        else if( 1 == i_statusVal.data_request )
        {
            reasonCode = I2C_DATA_REQUEST;
        }
        else if( 1 == i_statusVal.stop_error )
        {
            reasonCode = I2C_STOP_ERROR;
        }
        else if( 1 == i_statusVal.any_i2c_interrupt )
        {
            // TODO - This will be expanded during bad machine path to specify
            // which interrupts have fired.
            reasonCode = I2C_INTERRUPT;
        }

        if( I2C_INVALID_REASONCODE != reasonCode )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCheckForErrors() - Error found after command complete!" );

            /*@
             * @errortype
             * @reasoncode     I2C_HW_ERROR_FOUND
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       I2C_CHECK_FOR_ERRORS
             * @userdata1      Reasoncode
             * @userdata2      <UNUSED>
             * @devdesc        Error was found in I2C status register.  Check userdata1
             *                 to determine what the error was.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_HW_ERROR_FOUND,
                                           reasonCode,
                                           0x0 );

            // TODO - RTC entry to be created to allow for adding a target to an errorlog.
            // Once that is implemented, the target will be used here to add to the log.

            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cCheckForErrors()" );

    return err;
} // end i2cCheckForErrors

// ------------------------------------------------------------------
// i2cWriteByteAddr
// ------------------------------------------------------------------
errlHndl_t i2cWriteByteAddr ( TARGETING::Target * i_target,
                              input_args_t i_args )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    uint64_t engine = i_args.engine;
    uint64_t addr = i_args.addr;

    // Define the reg(s) we'll be accessing
    fiforeg fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWriteByteAddr( %04x )",
               addr );

    do
    {
        // Make sure there is space in the FIFO
        err = i2cWaitForFifoSpace( i_target,
                                   i_args );

        if( err )
        {
            break;
        }

        // Write first byte of address to the FIFO
        fifo.value = 0x0ull;
        fifo.byte_0 = ((addr & 0xFF00) >> 8);

        err = deviceWrite( i_target,
                           &fifo.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].fifo ) );

        if( err )
        {
            break;
        }

        // Write 2nd byte of address to the FIFO
        fifo.value = 0x0ull;
        fifo.byte_0 = (addr & 0xFF);

        err = deviceWrite( i_target,
                           &fifo.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].fifo ) );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cWriteByteAddr( %04x )",
               addr );

    return err;
} // end i2cWriteByteAddr


// ------------------------------------------------------------------
// i2cWaitForFifoSpace
// ------------------------------------------------------------------
errlHndl_t i2cWaitForFifoSpace ( TARGETING::Target * i_target,
                                 input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint64_t engine = i_args.engine;
    uint64_t addr = i_args.addr;

    // TODO - hardcoded to 400KHz for now
    uint64_t interval = I2C_TIMEOUT_INTERVAL( I2C_CLOCK_DIVISOR_400KHZ );
    uint64_t timeoutCount = I2C_TIMEOUT_COUNT( interval );

    // Define regs we'll be using
    statusreg status;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWaitForFifoSpace()" );

    do
    {
        // Read Status reg to get available FIFO bytes
        status.value = 0x0ull;
        err = i2cReadStatusReg( i_target,
                                engine,
                                status );

        if( err )
        {
            break;
        }

        while( I2C_MAX_FIFO_CAPACITY <= status.fifo_entry_count )
        {
            // FIFO is full, wait before writing any data
            nanosleep( 0, (interval * 1000) );

            status.value = 0x0ull;
            err = i2cReadStatusReg( i_target,
                                    engine,
                                    status );

            if( err )
            {
                break;
            }

            if( 0 == timeoutCount-- )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cWrite() - Timed out waiting for space in FIFO!" );

                /*@
                 * @errortype
                 * @reasoncode     I2C_FIFO_TIMEOUT
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       I2C_WRITE
                 * @userdata1      Status Register Value
                 * @userdata2      Requested Byte Address
                 * @devdesc        Timed out waiting for space to write into FIFO.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_WRITE,
                                               I2C_FIFO_TIMEOUT,
                                               status.value,
                                               addr );

                break;
            }
        }

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cWaitForFifoSpace()" );

    return err;
} // end i2cWaitForFifoSpace

} // end namespace I2C
