/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c.C $                                           */
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
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicates.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>

#include "i2c.H"
// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_i2c = NULL;
TRAC_INIT( & g_trac_i2c, "I2C", KILOBYTE );

trace_desc_t* g_trac_i2cr = NULL;
TRAC_INIT( & g_trac_i2cr, "I2CR", KILOBYTE );


// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define I2C_COMMAND_ATTEMPTS 2      // 1 Retry on failure
#define I2C_RETRY_DELAY 10000000    // Sleep for 10 ms before retrying
#define MAX_I2C_ENGINES 3           // Maximum of 3 engines per I2C Master
#define P8_MASTER_ENGINES 2         // Number of Engines used in P8
#define CENTAUR_MASTER_ENGINES 1    // Number of Engines in a Centaur
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

    mutex_t * engineLock = NULL;
    bool mutex_needs_unlock = false;

    // Get the input args our of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );


    // These are additional parms in the case an offset is passed in
    // via va_list, as well
    uint64_t  l_offset_length = 0;
    uint8_t * l_offset_buffer = NULL;

    l_offset_length = va_arg( i_args, uint64_t);

    if ( l_offset_length != 0)
    {
        l_offset_buffer = reinterpret_cast<uint8_t*>(va_arg(i_args, uint64_t));
    }

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cPerformOp(): i_opType=%d, aType=%d, "
               "p/e/devAddr= %d/%d/0x%X, len=%d, offset=%d/%p",
               (uint64_t) i_opType, i_accessType, args.port, args.engine,
               args.devAddr, io_buflen, l_offset_length, l_offset_buffer);

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cPerformOp(): i_opType=%d, aType=%d, "
               "p/e/devAddr= %d/%d/0x%x, len=%d, offset=%d/%p",
               (uint64_t) i_opType, i_accessType, args.port, args.engine,
               args.devAddr, io_buflen, l_offset_length, l_offset_buffer);


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
                           ERR_MRK"Invalid engine for getting Mutex! "
                           "args.engine=%d", args.engine  );
                // @todo RTC:69113 - Create an error here
                break;
        };

        // Lock on this engine
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Obtaining lock for engine: %d",
                   args.engine );
        (void)mutex_lock( engineLock );
        mutex_needs_unlock = true;
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Locked on engine: %d",
                   args.engine );


        // Calculate variables related to I2C Bus Speed in 'args' struct
        err =  i2cSetBusVariables( i_target, READ_I2C_BUS_ATTRIBUTES, args);

        if( err )
        {
            break;
        }


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


            if( i_opType        == DeviceFW::READ &&
                l_offset_length != 0 )
            {

                // First WRITE offset to device without a stop
                args.read_not_write  = false;
                args.with_stop       = false;
                args.skip_mode_setup = false;

                err = i2cWrite( i_target,
                                l_offset_buffer,
                                l_offset_length,
                                args );

                if( err == NULL )
                {
                    // Now do the READ with a stop
                    args.read_not_write = true;
                    args.with_stop      = true;

                    // Skip mode setup on this cmd -
                    // already set with previous cmd
                    args.skip_mode_setup = true;

                    err = i2cRead( i_target,
                                   io_buffer,
                                   io_buflen,
                                   args );
                }
            }

            else if( i_opType        == DeviceFW::WRITE &&
                     l_offset_length != 0 )
            {

                // Add the Offset Information to the start of the data and
                // then send as a single write operation

                size_t newBufLen = l_offset_length + io_buflen;
                uint8_t * newBuffer = static_cast<uint8_t*>(malloc(newBufLen));

                // Add the Offset to the buffer
                memcpy( newBuffer, l_offset_buffer, l_offset_length);

                // Now add the data the user wanted to write
                memcpy( &newBuffer[l_offset_length], io_buffer, io_buflen);

                // Write parms:
                args.read_not_write  = false;
                args.with_stop       = true;
                args.skip_mode_setup = false;

                err = i2cWrite( i_target,
                                newBuffer,
                                newBufLen,
                                args );


                free( newBuffer );

            }

            else if ( i_opType        == DeviceFW::READ &&
                      l_offset_length == 0 )
            {
                // Do a direct READ
                args.read_not_write  = true;
                args.with_stop       = true;
                args.skip_mode_setup = false;

                err = i2cRead( i_target,
                               io_buffer,
                               io_buflen,
                               args);
            }


            else if( i_opType        == DeviceFW::WRITE &&
                     l_offset_length == 0 )
            {
                // Do a direct WRITE with a stop
                args.read_not_write  = false;
                args.with_stop       = true;
                args.skip_mode_setup = false;

                err = i2cWrite( i_target,
                                io_buffer,
                                io_buflen,
                                args);
            }
            else
            {
                TRACFCOMP( g_trac_i2c, ERR_MRK"i2cPerformOp() - "
                           "Unsupported Op/Offset-Type Combination=%d/%d",
                           i_opType, l_offset_length );
                uint64_t userdata2 = l_offset_length;
                userdata2 = (userdata2 << 16) | args.port;
                userdata2 = (userdata2 << 16) | args.engine;
                userdata2 = (userdata2 << 16) | args.devAddr;

                /*@
                 * @errortype
                 * @reasoncode       I2C_INVALID_OP_TYPE
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         I2C_PERFORM_OP
                 * @userdata1        i_opType
                 * @userdata2[0:15]  Offset Length
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
            if( err == NULL )
            {
                break;
            }
        }

        if( err )
        {
            break;
        }
    } while( 0 );

    // Check if we need to unlock the mutex
    if ( mutex_needs_unlock == true )
    {
        // Unlock
        (void) mutex_unlock( engineLock );
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Unlocked engine: %d",
                   args.engine );
    }

    // If there is an error, add target to log
    if ( (err != NULL) && (i_target != NULL) )
    {
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(err);
    }

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
                     misc_args_t & i_args)
{
    errlHndl_t err = NULL;
    uint64_t bytesRead = 0x0;
    size_t size = sizeof(uint64_t);


    // Use Local Variables (timeoutCount gets derecmented)
    uint64_t interval     = i_args.timeout_interval;
    uint64_t timeoutCount = i_args.timeout_count;

    // Define the regs we'll be using
    status_reg_t status;
    fifo_reg_t fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cRead()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C READ  START : engine %.2X : port %.2X : devAddr %.2X : len %d",
               i_args.engine, i_args.port, i_args.devAddr, i_buflen );

    do
    {
        // Do Command/Mode reg setups.
        i_args.read_not_write = true;

        err = i2cSetup( i_target,
                        i_buflen,
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

            // Wait for 1 of 2 indictators to read from FIFO:
            // 1) fifo_entry_count !=0
            // 2) Data Request bit is on
            while( (0 == status.fifo_entry_count) &&
                   (0 == status.data_request)        )
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


                TRACUCOMP( g_trac_i2c, "i2cRead() Wait Loop: status=0x%016llx "
                   ".fifo_entry_count=%d, .data_request=%d",
                   status.value, status.fifo_entry_count, status.data_request);


                if( 0 == timeoutCount-- )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cRead() - Timed out waiting for data in FIFO!" );

                    uint64_t userdata2 = i_args.port;
                    userdata2 = (userdata2 << 16) | i_args.engine;
                    userdata2 = (userdata2 << 16) | i_args.devAddr;

                    /*@
                     * @errortype
                     * @reasoncode       I2C_FIFO_TIMEOUT
                     * @severity         ERRL_SEV_UNRECOVERABLE
                     * @moduleid         I2C_READ
                     * @userdata1        Status Register Value
                     * @userdata2[0:31]  Master Port
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
                              DEVICE_SCOM_ADDRESS(
                                  masterAddrs[i_args.engine].fifo ) );

            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cRead() - FIFO[0x%lx] = 0x%016llx",
                       masterAddrs[i_args.engine].fifo, fifo.value);

            if( err )
            {
                break;
            }

            *((uint8_t*)o_buffer + bytesRead) = fifo.byte_0;

            // Everytime FIFO is read, reset timeout count
            timeoutCount = I2C_TIMEOUT_COUNT( interval );

            TRACUCOMP( g_trac_i2cr,
                       "I2C READ  DATA  : engine %.2X : port %.2x : "
                       "devAddr %.2X : byte %d : %.2X (0x%lx)",
                       i_args.engine, i_args.port, i_args.devAddr, bytesRead,
                       fifo.byte_0, fifo.value );
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
               i_args.engine, i_args.port, i_args.devAddr, i_buflen );

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
                      misc_args_t & i_args)
{
    errlHndl_t err = NULL;
    uint64_t bytesWritten = 0x0;
    size_t size = sizeof(uint64_t);

    // Define regs we'll be using
    fifo_reg_t fifo;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWrite()" );

    TRACSCOMP( g_trac_i2cr,
               "I2C WRITE START : engine %.2X : port %.2X : devAddr %.2X : len %d",
               i_args.engine, i_args.port, i_args.devAddr, io_buflen );

    do
    {
        // Do Command/Mode reg setups
        i_args.read_not_write = false;

        err = i2cSetup( i_target,
                        io_buflen,
                        i_args);

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
                               DEVICE_SCOM_ADDRESS(
                                   masterAddrs[i_args.engine].fifo ) );

            if( err )
            {
                break;
            }

            TRACUCOMP( g_trac_i2cr,
                       "I2C WRITE DATA  : engine %.2X : port %.2X : "
                       "devAddr %.2X : byte %d : %.2X (0x%lx)",
                       i_args.engine, i_args.port, i_args.devAddr,
                       bytesWritten, fifo.byte_0, fifo.value );
        }

        if( err )
        {
            break;
        }

        // Check for Command complete
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
               i_args.engine, i_args.port, i_args.devAddr, io_buflen );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cWrite()" );

    return err;
} // end i2cWrite

// ------------------------------------------------------------------
// i2cSetup
// ------------------------------------------------------------------
errlHndl_t i2cSetup ( TARGETING::Target * i_target,
                      size_t & i_buflen,
                      misc_args_t & i_args)
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetup(): buf_len=%d, r_nw=%d, w_stop=%d, sms=%d",
               i_buflen, i_args.read_not_write, i_args.with_stop,
               i_args.skip_mode_setup);

    // Define the registers that we'll use
    mode_reg_t mode;
    command_reg_t cmd;

    do
    {
        // Wait for Command complete before we start
        err = i2cWaitForCmdComp( i_target,
                                 i_args );

        if( err )
        {
            break;
        }


        // Skip mode setup on 2nd of 2 cmd strung together - like when sending
        //  device offset first before read or write

        if ( i_args.skip_mode_setup == false)
        {
            // Write Mode Register:
            //      - bit rate divisor (set in i2cSetClockVariables() )
            //      - port number

            mode.value = 0x0ull;
            mode.bit_rate_div = i_args.bit_rate_divisor;
            mode.port_num = i_args.port;


            TRACUCOMP( g_trac_i2c,"i2cSetup(): set mode = 0x%lx", mode.value);

            err = deviceWrite( i_target,
                               &mode.value,
                               size,
                               DEVICE_SCOM_ADDRESS(
                                   masterAddrs[i_args.engine].mode));

            if( err )
            {
                break;
            }
        }


        // Write Command Register:
        //      - with start
        //      - with stop
        //      - RnW
        //      - length
        cmd.value = 0x0ull;
        cmd.with_start = 1;
        cmd.with_stop = (i_args.with_stop ? 1 : 0);
        cmd.with_addr = 1;

        // cmd.device_addr is 7 bits
        // devAddr though is a uint64_t
        //  -- value stored in LSB byte of uint64_t
        //  -- LS-bit is unused, creating the 7 bit cmd.device_addr
        //  So will be masking for LSB, and then shifting to push off LS-bit
        cmd.device_addr = (0x000000FF & i_args.devAddr) >> 1;

        cmd.read_not_write = (i_args.read_not_write ? 1 : 0);
        cmd.length_b = i_buflen;

        TRACUCOMP( g_trac_i2c,"i2cSetup(): set cmd = 0x%lx", cmd.value);

        err = deviceWrite( i_target,
                           &cmd.value,
                           size,
                           DEVICE_SCOM_ADDRESS(
                               masterAddrs[i_args.engine].command ) );

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
                               misc_args_t & i_args)
{
    errlHndl_t err = NULL;
    uint64_t engine = i_args.engine;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cWaitForCmdComp()" );

    // Define the registers that we'll use
    status_reg_t status;

    // Use Local Variables (timeoutCount gets derecmented)
    uint64_t interval     = i_args.timeout_interval;
    uint64_t timeoutCount = i_args.timeout_count;

    TRACUCOMP(g_trac_i2c, "i2cWaitForCmdComp(): timeoutCount=%d, interval=%d",
              timeoutCount, interval);

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
                              misc_args_t & i_args,
                              status_reg_t & o_statusReg )
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
                          DEVICE_SCOM_ADDRESS(
                              masterAddrs[i_args.engine].status ) );

        if( err )
        {
            break;
        }

        TRACUCOMP(g_trac_i2c,"i2cReadStatusReg(): "
                  INFO_MRK"status[0x%lx]: 0x%016llx",
                  masterAddrs[i_args.engine].status, o_statusReg.value );


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
                               misc_args_t & i_args,
                               status_reg_t i_statusVal )
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
            // - i2cGetInterrupts() adds intRegVal to trace, so it ill be added
            //   to error log below
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

            // @todo RTC:69113 - Add target and I2C traces to the errorlog.

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
                                 misc_args_t & i_args )
{
    errlHndl_t err = NULL;

    // Use Local Variables (timeoutCount gets derecmented)
    uint64_t interval     = i_args.timeout_interval;
    uint64_t timeoutCount = i_args.timeout_count;

    // Define regs we'll be using
    status_reg_t status;

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

        TRACUCOMP( g_trac_i2c, "i2cWaitForFifoSpace(): status=0x%016llx "
                   "I2C_MAX_FIFO_CAPACITY=%d, status.fifo_entry_count=%d",
                   status.value, I2C_MAX_FIFO_CAPACITY,
                   status.fifo_entry_count);


        // 2 Conditions to wait on:
        // 1) FIFO is full
        // 2) Data Request bit is not set
        while( (I2C_MAX_FIFO_CAPACITY <= status.fifo_entry_count) &&
               (0 == status.data_request)                             )
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
                      misc_args_t & i_args)
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    // Get Args

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cReset()" );

    // Writing to the Status Register does a full I2C reset.
    status_reg_t reset;

    do
    {
        reset.value = 0x0;

        TRACUCOMP(g_trac_i2c,"i2cReset() "
                  "reset[0x%lx]: 0x%016llx",
                  masterAddrs[i_args.engine].reset, reset.value );

        err = deviceWrite( i_target,
                           &reset.value,
                           size,
                           DEVICE_SCOM_ADDRESS(
                               masterAddrs[i_args.engine].reset ) );

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
                              misc_args_t & i_args)
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    // Master Registers
    mode_reg_t mode;
    command_reg_t cmd;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSendSlaveStop()" );

    do
    {
        mode.value = 0x0ull;

        mode.bit_rate_div = i_args.bit_rate_divisor;
        mode.port_num = i_args.port;
        mode.enhanced_mode = 1;

        TRACUCOMP(g_trac_i2c,"i2cSendSlaveStop(): "
                  "mode[0x%lx]: 0x%016llx",
                  masterAddrs[engine].mode, mode.value );

        err = deviceWrite( i_target,
                           &mode.value,
                           size,
                           DEVICE_SCOM_ADDRESS(
                               masterAddrs[i_args.engine].mode ) );

        if( err )
        {
            break;
        }

        cmd.value = 0x0ull;
        cmd.with_stop = 1;

        TRACUCOMP(g_trac_i2c,"i2cSendSlaveStop(): "
                  "cmd[0x%lx]: 0x%016llx",
                  masterAddrs[engine].command, cmd.value );

        err = deviceWrite( i_target,
                           &cmd.value,
                           size,
                           DEVICE_SCOM_ADDRESS(
                               masterAddrs[i_args.engine].command ) );

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
                              misc_args_t & i_args,
                              uint64_t & o_intRegValue )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    // Master Regs
    interrupt_reg_t intreg;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cGetInterrupts()" );

    do
    {
        intreg.value = 0x0;
        err = deviceRead( i_target,
                          &intreg.value,
                          size,
                          DEVICE_SCOM_ADDRESS(
                              masterAddrs[i_args.engine].interrupt ) );

        if( err )
        {
            break;
        }

        TRACUCOMP(g_trac_i2c,"i2cGetInterrupts(): "
                  "interrupt[0x%lx]: 0x%016llx",
                  masterAddrs[engine].interrupt, intreg.value );

        // Return the data read
        o_intRegValue = intreg.value;
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cGetInterrupts( int reg val: %016llx)",
               o_intRegValue );

    return err;
} // end i2cGetInterrupts


// ------------------------------------------------------------------
// i2cSetupMasters
// ------------------------------------------------------------------
errlHndl_t i2cSetupMasters ( void )
{
    errlHndl_t err = NULL;
    size_t size = sizeof(uint64_t);

    misc_args_t io_args;

    mode_reg_t mode;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetupMasters()" );

    do
    {
        // Get top level system target
        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        // Get list of the Centaur Chips
        TARGETING::TargetHandleList centList;
        TARGETING::PredicateCTM predCent( TARGETING::CLASS_CHIP,
                                          TARGETING::TYPE_MEMBUF );
        tS.getAssociated( centList,
                          sysTarget,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL,
                          &predCent );

        if( 0 == centList.size() )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cSetupMasters: No Centaur chips found!" );

            /*@
             * @errortype
             * @reasoncode       I2C_NO_CENTAUR_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_SETUP_MASTERS
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @frucallout       <NONE>
             * @devdesc          No Centaur chips found to programm I2C bus
             * divisor
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_SETUP_MASTERS,
                                           I2C_NO_CENTAUR_FOUND,
                                           0x0, 0x0 );
            break;
        }

        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"I2C Master Centaurs: %d",
                   centList.size() );

        // Setup each Membuf Master
        for( uint32_t centaur = 0; centaur < centList.size(); centaur++ )
        {
            if( !centList[centaur]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional )
            {
                // Non functional
                TRACDCOMP( g_trac_i2c,
                           INFO_MRK"Centaur %d is non-functional",
                           centaur );
                continue;
            }

            for( uint32_t engine = 0; engine < CENTAUR_MASTER_ENGINES; engine++ )
            {
                // Write Mode Register:
                mode.value = 0x0ull;

                // Hardcode to 400KHz for PHYP
                err = i2cSetBusVariables ( centList[centaur],
                                           SET_I2C_BUS_400KHZ,
                                           io_args );

                if( err )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cSetupMasters: Error Setting Bus "
                               "Speed Variables-Centaur, engine: %d",
                               engine );

                    // If we get error skip setting this target, but still need
                    // to continue to program the I2C Bus Divisor for the rest
                    errlCommit( err,
                                I2C_COMP_ID );
                    continue;
                }

                mode.bit_rate_div = io_args.bit_rate_divisor;

                err = deviceWrite( centList[centaur],
                                   &mode.value,
                                   size,
                                   DEVICE_SCOM_ADDRESS(
                                       masterAddrs[engine].mode));

                if( err )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cSetupMasters: Error reading from "
                               "Centaur, engine: %d",
                               engine );

                    // If we get errors on these reads, we still need to continue
                    // to program the I2C Bus Divisor for the rest
                    errlCommit( err,
                                I2C_COMP_ID );
                }
            }

            if( err )
            {
                break;
            }
        }

        if( err )
        {
            break;
        }

        // Get list of Procs
        TARGETING::TargetHandleList procList;
        TARGETING::PredicateCTM predProc( TARGETING::CLASS_CHIP,
                                          TARGETING::TYPE_PROC );
        tS.getAssociated( procList,
                          sysTarget,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL,
                          &predProc );

        if( 0 == procList.size() )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cSetupMasters: No Processor chips found!" );

            /*@
             * @errortype
             * @reasoncode       I2C_NO_PROC_FOUND
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_SETUP_MASTERS
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @frucallout       <NONE>
             * @devdesc          No Centaur chips found to programm I2C bus
             * divisor
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_SETUP_MASTERS,
                                           I2C_NO_PROC_FOUND,
                                           0x0, 0x0 );
            break;
        }

        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"I2C Master Procs: %d",
                   procList.size() );

        // Do reads to each Proc
        for( uint32_t proc = 0; proc < procList.size(); proc++ )
        {
            if( !procList[proc]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional )
            {
                // Non functional
                TRACDCOMP( g_trac_i2c,
                           INFO_MRK"proc %d, is non-functional",
                           proc );
                continue;
            }

            for( uint32_t engine = 0; engine < P8_MASTER_ENGINES; engine++ )
            {
                // Write Mode Register:
                mode.value = 0x0ull;

                // Hardcode to 400KHz for PHYP
                err = i2cSetBusVariables ( procList[proc],
                                           SET_I2C_BUS_400KHZ,
                                           io_args );

                if( err )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cSetupMasters: Error Setting Bus "
                               "Speed Variables-Processor, engine: %d",
                               engine );

                    // If we get error skip setting this target, but still need
                    // to continue to program the I2C Bus Divisor for the rest
                    errlCommit( err,
                                I2C_COMP_ID );

                    continue;
                }

                mode.bit_rate_div = io_args.bit_rate_divisor;

                err = deviceWrite( procList[proc],
                                   &mode.value,
                                   size,
                                   DEVICE_SCOM_ADDRESS(
                                       masterAddrs[engine].mode));

                if( err )
                {
                    TRACFCOMP( g_trac_i2c,
                               ERR_MRK"i2cSetupMasters: Error reading from "
                               "Processor, engine: %d",
                               engine );

                    // If we get errors on these reads, we still need to continue
                    // to program the I2C Bus Divisor for the rest
                    errlCommit( err,
                                I2C_COMP_ID );
                }
            }

            if( err )
            {
                break;
            }
        }

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetupMasters()" );

    return err;
}



// ------------------------------------------------------------------
//  i2cSetClockVariables
// ------------------------------------------------------------------
errlHndl_t i2cSetBusVariables ( TARGETING::Target * i_target,
                                i2c_bus_setting_mode_t i_mode,
                                misc_args_t & io_args)
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetBusVariables()" );

    do
    {

        // @todo RTC:80614 - Read I2C bus speed attributes from I2C Master
        // For now, hardcode to 400KHz
        i_mode = SET_I2C_BUS_400KHZ;

        if (i_mode == SET_I2C_BUS_400KHZ)
        {

            io_args.bus_speed = 400;
            io_args.bit_rate_divisor = I2C_CLOCK_DIVISOR_400KHZ;
            io_args.timeout_interval = I2C_TIMEOUT_INTERVAL(
                                           I2C_CLOCK_DIVISOR_400KHZ);
            io_args.timeout_count = I2C_TIMEOUT_COUNT(
                                        io_args.timeout_interval);


        }

        /* @todo RTC:80614 - sync up reading attributes with MRW
        else if (i_mode == READ_I2C_BUS_ATTRIBUTES)
        {

        }
        */

        else
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cSetBusVariables: "
                       "Invalid Bus Speed Mode Input!" );

            /*@
             * @errortype
             * @reasoncode       I2C_INVALID_BUS_SPEED_MODE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_SET_BUS_VARIABLES
             * @userdata1        I2C Bus Setting Mode Enum
             * @userdata2        <UNUSED>
             * @frucallout       <NONE>
             * @devdesc          Invalid I2C bus speed mode input
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_SET_BUS_VARIABLES,
                                           I2C_INVALID_BUS_SPEED_MODE,
                                           i_mode,
                                           0x0 );
            break;

        }


    } while( 0 );


    TRACUCOMP(g_trac_i2c,"i2cSetBusVariables(): e/p/dA=%d/%d/0x%x: "
              "mode=%d: b_sp=%d, b_r_d=0x%x, to_i=%d, to_c = %d",
              io_args.engine, io_args.port, io_args.devAddr,
              i_mode, io_args.bus_speed, io_args.bit_rate_divisor,
              io_args.timeout_interval, io_args.timeout_count);

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetBusVariables()" );

    return err;
}


} // end namespace I2C
