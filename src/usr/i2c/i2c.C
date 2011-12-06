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
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_i2c = NULL;
TRAC_INIT( & g_trac_i2c, "I2C", 4096 );

trace_desc_t* g_trac_i2cr = NULL;
TRAC_INIT( & g_trac_i2cr, "I2CR", 4096 );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define I2C_COMMAND_ATTEMPTS 2      // 1 Retry on failure
#define I2C_RETRY_DELAY 10000000    // Sleep for 10 ms before retrying
#define MAX_I2C_ENGINES 3           // Maximum of 3 engines per I2C Master
// ----------------------------------------------

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

        // Get the mutex for the requested engine
        mutex_t * engineLock = NULL;
        switch( args.engine )
        {
            case 0:
                engineLock = i_target->getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_0>();
                break;

            case 1:
                engineLock = i_target->getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_1>();
                break;

            case 2:
                engineLock = i_target->getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_2>();
                break;

            default:
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"Invalid engine for getting Mutex!" );
                // TODO - Create an error here
                break;
        };

        // Lock on this engine
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Obtaining lock for engine: %d",
                   args.engine );
        (void)mutex_lock( engineLock );
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Locked on engine: %d",
                   args.engine );

        for( int attempt = 0; attempt < I2C_COMMAND_ATTEMPTS; attempt++ )
        {
            if( err )
            {
                // Catch and commit the log here if we failed on first attempt.
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"Error Encountered, Attempt %d out of %d",
                           (attempt + 1),   // Add 1 since we started counting at 0
                           I2C_COMMAND_ATTEMPTS );

                errlCommit( err,
                            I2C_COMP_ID );

                // Reset the I2C Master
                err = i2cReset( i_target,
                                args );

                if( err )
                {
                    break;
                }

                // Sleep before trying again.
                nanosleep( 0, I2C_RETRY_DELAY );
            }

            if( i_opType == DeviceFW::READ )
            {
                err = i2cRead( i_target,
                               io_buffer,
                               io_buflen,
                               args );
            }
            else if( i_opType == DeviceFW::WRITE )
            {
                err = i2cWrite( i_target,
                                io_buffer,
                                io_buflen,
                                args );
            }
            else
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cPerformOp() - Unknown Operation Type!" );
                uint64_t userdata2 = args.port;
                userdata2 = (userdata2 << 16) | args.engine;
                userdata2 = (userdata2 << 16) | args.devAddr;

                /*@
                 * @errortype
                 * @reasoncode       I2C_INVALID_OP_TYPE
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         I2C_PERFORM_OP
                 * @userdata1        i_opType
                 * @userdata2[0:15]  <UNUSED>
                 * @userdata2[16:31] Master Port
                 * @userdata2[32:47] Master Engine
                 * @userdata2[48:63] Slave Device Address
                 * @devdesc          Invalid Operation type.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_PERFORM_OP,
                                               I2C_INVALID_OP_TYPE,
                                               i_opType,
                                               userdata2 );

                break;
            }

            // If no errors, break here
            if( NULL == err )
            {
                break;
            }
        }

        // Unlock
        (void) mutex_unlock( engineLock );
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Unlocked engine: %d",
                   args.engine );

        if( err )
        {
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

    uint64_t engine = i_args.engine;
    uint64_t devAddr = i_args.devAddr;
    uint64_t port = i_args.port;

    // TODO - hardcoded to 400KHz for now
    uint64_t interval = I2C_TIMEOUT_INTERVAL( I2C_CLOCK_DIVISOR_400KHZ );
    uint64_t timeoutCount = I2C_TIMEOUT_COUNT( interval );

    // Define the regs we'll be using
    statusreg status;
    fiforeg fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cRead()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  START : engine %.2X : port %.2X : devAddr %.2X : len %d",
               engine, port, devAddr, i_buflen );

    do
    {
        // Do Command/Mode reg setups.
        err = i2cSetup( i_target,
                        i_buflen,
                        true,
                        true,
                        i_args );

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
                                    i_args,
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
                                        i_args,
                                        status );

                if( err )
                {
                    break;
                }

                if( 0 == timeoutCount-- )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cRead() - Timed out waiting for data in FIFO!" );

                    uint64_t userdata2 = i_args.port;
                    userdata2 = (userdata2 << 16) | engine;
                    userdata2 = (userdata2 << 16) | devAddr;

                    /*@
                     * @errortype
                     * @reasoncode       I2C_FIFO_TIMEOUT
                     * @severity         ERRL_SEV_UNRECOVERABLE
                     * @moduleid         I2C_READ
                     * @userdata1        Status Register Value
                     * @userdata2[0:15]  <UNUSED>
                     * @userdata2[16:31] Master Port
                     * @userdata2[32:47] Master Engine
                     * @userdata2[48:63] Slave Device Address
                     * @devdesc          Timed out waiting for data in FIFO to read
                     */
                    err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                   I2C_READ,
                                                   I2C_FIFO_TIMEOUT,
                                                   status.value,
                                                   userdata2 );

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
                       "I2C READ  DATA  : engine %.2X : devAddr %.2X : byte %d : %.2X",
                       engine, devAddr, bytesRead, fifo.byte_0 );
        }

        if( err )
        {
            break;
        }

        // Poll for Command Complete
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  END   : engine %.2X : port %.2x : devAddr %.2X : len %d",
               engine, port, devAddr, i_buflen );

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

    uint64_t engine = i_args.engine;
    uint64_t devAddr = i_args.devAddr;
    uint64_t port = i_args.port;

    // Define regs we'll be using
    fiforeg fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWrite()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C WRITE START : engine %.2X : port %.2X : devAddr %.2X : len %d",
               engine, port, devAddr, io_buflen );

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
                       "I2C WRITE DATA  : engine %.2X : devAddr %.2X : byte %d : %.2X",
                       engine, devAddr, bytesWritten, fifo.byte_0 );
        }

        if( err )
        {
            break;
        }

        // Check for Command complete, and make sure no errors
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }

        // Make sure we send back how many bytes were written
        io_buflen = bytesWritten;
    } while( 0 );

    TRACSCOMP( g_trac_i2cr,
               "I2C WRITE END   : engine %.2X: port %.2X : devAddr %.2X : len %d",
               engine, port, devAddr, io_buflen );

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
                                 i_args );

        if( err )
        {
            break;
        }

        // Write Mode Register:
        //      - bit rate divisor
        //      - port number
        mode.value = 0x0ull;

        // TODO - Hard code to 400KHz until we get attributes in place to get this from
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
        cmd.length_b = i_buflen;

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
                               input_args_t i_args )
{
    errlHndl_t err = NULL;
    uint64_t engine = i_args.engine;

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
                                    i_args,
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
                                               engine );

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
                              input_args_t i_args,
                              statusreg & o_statusReg )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);
    uint64_t engine = i_args.engine;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cReadStatusReg()" );

    do
    {
        // Read the status Reg
        err = deviceRead( i_target,
                          &o_statusReg.value,
                          size,
                          DEVICE_SCOM_ADDRESS( masterAddrs[engine].status ) );

        if( err )
        {
            break;
        }

        // Check for Errors
        // Per the specification it is a requirement to check for errors each time
        // that the status register is read.
        err = i2cCheckForErrors( i_target,
                                 i_args,
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
                               input_args_t i_args,
                               statusreg i_statusVal )
{
    errlHndl_t err = NULL;
    bool errorFound = false;
    uint64_t intRegVal = 0x0;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cCheckForErrors()" );

    do
    {
        if( 1 == i_statusVal.invalid_cmd )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Invalid Command! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.lbus_parity_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Local Bus Parity Error! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.backend_overrun_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C BackEnd OverRun Error! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.backend_access_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C BackEnd Access Error! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.arbitration_lost_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Arbitration Lost! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.nack_received )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C NACK Received! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.data_request )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Data Request Error! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.stop_error )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C STOP Error! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.any_i2c_interrupt )
        {
            errorFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Interrupt Detected! - status reg: %016llx",
                       i_statusVal.value );

            // Get the Interrupt Register value to add to the log
            err = i2cGetInterrupts( i_target,
                                    i_args,
                                    intRegVal );

            if( err )
            {
                break;
            }
        }

        if( errorFound )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCheckForErrors() - Error(s) found after command complete!" );

            /*@
             * @errortype
             * @reasoncode     I2C_HW_ERROR_FOUND
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       I2C_CHECK_FOR_ERRORS
             * @userdata1      Status Register Value
             * @userdata2      Interrupt Register Value (only valid in Interrupt case)
             * @devdesc        Error was found in I2C status register.  Check userdata1
             *                 to determine what the error was.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_HW_ERROR_FOUND,
                                           i_statusVal.value,
                                           intRegVal );

            // TODO - RTC entry to be created to allow for adding a target to an errorlog.
            // Once that is implemented, the target will be used here to add to the log.

            // TODO - Add I2C traces to this log.

            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cCheckForErrors()" );

    return err;
} // end i2cCheckForErrors


// ------------------------------------------------------------------
// i2cWaitForFifoSpace
// ------------------------------------------------------------------
errlHndl_t i2cWaitForFifoSpace ( TARGETING::Target * i_target,
                                 input_args_t i_args )
{
    errlHndl_t err = NULL;

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
                                i_args,
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
                                    i_args,
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
                 * @userdata2      <UNUSED>
                 * @devdesc        Timed out waiting for space to write into FIFO.
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               I2C_WRITE,
                                               I2C_FIFO_TIMEOUT,
                                               status.value,
                                               0x0 );

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


// ------------------------------------------------------------------
// i2cReset
// ------------------------------------------------------------------
errlHndl_t i2cReset ( TARGETING::Target * i_target,
                      input_args_t i_args )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    // Get Args
    uint64_t engine = i_args.engine;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cReset()" );

    // Writing to the Status Register does a full I2C reset.
    statusreg reset;

    do
    {
        reset.value = 0x0;
        err = deviceWrite( i_target,
                           &reset.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].reset ) );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Reset Failed!!" );
            break;
        }

        // Part of doing the I2C Master reset is also sending a stop
        // command to the slave device.
        err = i2cSendSlaveStop( i_target,
                                i_args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cReset()" );

    return err;
} // end i2cReset


// ------------------------------------------------------------------
// i2cSendSlaveStop
// ------------------------------------------------------------------
errlHndl_t i2cSendSlaveStop ( TARGETING::Target * i_target,
                              input_args_t i_args )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);
    uint64_t engine = i_args.engine;
    uint64_t port = i_args.port;

    // Master Registers
    modereg mode;
    cmdreg cmd;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSendSlaveStop()" );

    do
    {
        mode.value = 0x0ull;
        // TODO - Hard code to 400KHz until we get attributes in place to get this from
        // the target.
        mode.bit_rate_div = I2C_CLOCK_DIVISOR_400KHZ;
        mode.port_num = port;
        mode.enhanced_mode = 1;

        err = deviceWrite( i_target,
                           &mode.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].mode ) );

        if( err )
        {
            break;
        }

        cmd.value = 0x0ull;
        cmd.with_stop = 1;

        err = deviceWrite( i_target,
                           &cmd.value,
                           size,
                           DEVICE_SCOM_ADDRESS( masterAddrs[engine].command ) );

        if( err )
        {
            break;
        }

        // Now wait for cmd Complete
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cSendSlaveStop()" );

    return err;
} // end i2cSendSlaveStop


// ------------------------------------------------------------------
// i2cGetInterrupts
// ------------------------------------------------------------------
errlHndl_t i2cGetInterrupts ( TARGETING::Target * i_target,
                              input_args_t i_args,
                              uint64_t & o_intRegValue )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);
    uint64_t engine = i_args.engine;

    // Master Regs
    interruptreg intreg;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cGetInterrupts()" );

    do
    {
        intreg.value = 0x0;
        err = deviceRead( i_target,
                          &intreg.value,
                          size,
                          DEVICE_SCOM_ADDRESS( masterAddrs[engine].interrupt ) );

        if( err )
        {
            break;
        }

        // Return the data read
        o_intRegValue = intreg.value;
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cGetInterrupts( int reg val: %016llx)",
               o_intRegValue );

    return err;
} // end i2cGetInterrupts

} // end namespace I2C
