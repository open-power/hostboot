/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2c.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicates.H>
#include <devicefw/driverif.H>
#include <fsi/fsiif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include <attributetraits.H>
#include "i2c.H"
#include "errlud_i2c.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_i2c = NULL;
TRAC_INIT( & g_trac_i2c, I2C_COMP_NAME, KILOBYTE );

trace_desc_t* g_trac_i2cr = NULL;
TRAC_INIT( & g_trac_i2cr, "I2CR", KILOBYTE );


// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


// ----------------------------------------------
// Defines
// ----------------------------------------------
#define I2C_RESET_DELAY_NS (5 * NS_PER_MSEC)  // Sleep for 5 ms after reset
#define P8_MASTER_ENGINES 2         // Number of Engines used in P8
#define P8_MASTER_PORTS 3           // Number of Ports used in P8
#define CENTAUR_MASTER_ENGINES 1    // Number of Engines in a Centaur

// Derived from ATTR_I2C_BUS_SPEED_ARRAY[engine][port] attribute
const TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type g_var = {{NULL}};
#define I2C_BUS_ATTR_MAX_ENGINE  I2C_BUS_MAX_ENGINE(g_var)
#define I2C_BUS_ATTR_MAX_PORT    I2C_BUS_MAX_PORT(g_var)


// ----------------------------------------------

namespace I2C
{

// Register the generic I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::I2C,
                       TARGETING::TYPE_PROC,
                       i2cPerformOp );

// Register the generic I2C perform Op with the routing code for Memory Buffers.
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
    // Other args set below
    misc_args_t args;
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // These are additional parms in the case an offset is passed in
    // via va_list, as well

    args.offset_length = va_arg( i_args, uint64_t);

    if ( args.offset_length != 0 )
    {
        args.offset_buffer = reinterpret_cast<uint8_t*>
                                             (va_arg(i_args, uint64_t));
    }

    // Set both Host and FSI switches to 0 so that they get set later by
    // attribute in i2cCommonOp()
    args.switches.useHostI2C = 0;
    args.switches.useFsiI2C  = 0;


    // Call common function
    err = i2cCommonOp( i_opType,
                       i_target,
                       io_buffer,
                       io_buflen,
                       i_accessType,
                       args );


    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end i2cPerformOp


// Register the Host-based I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::HOSTI2C,
                       TARGETING::TYPE_PROC,
                       host_i2cPerformOp );

// Register the Host-based I2C perform Op with the routing code for Mem Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::HOSTI2C,
                       TARGETING::TYPE_MEMBUF,
                       host_i2cPerformOp );

// ------------------------------------------------------------------
// host_i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t host_i2cPerformOp( DeviceFW::OperationType i_opType,
                              TARGETING::Target * i_target,
                              void * io_buffer,
                              size_t & io_buflen,
                              int64_t i_accessType,
                              va_list i_args )
{
    errlHndl_t err = NULL;

    // Get the input args our of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // These are additional parms in the case an offset is passed in
    // via va_list, as well

    args.offset_length = va_arg( i_args, uint64_t);

    if ( args.offset_length != 0 )
    {
        args.offset_buffer = reinterpret_cast<uint8_t*>
                                             (va_arg(i_args, uint64_t));
    }

    // Set Host switch to 1 and FSI switch to 0
    args.switches.useHostI2C = 1;
    args.switches.useFsiI2C  = 0;


    // Call common function
    err = i2cCommonOp( i_opType,
                       i_target,
                       io_buffer,
                       io_buflen,
                       i_accessType,
                       args );


    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"host_i2cPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end host_i2cPerformOp


// Register the FSI-based I2C perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::FSI_I2C,
                       TARGETING::TYPE_PROC,
                       fsi_i2cPerformOp );

// Register the FSI-based I2C perform Op with the routing code for Mem Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::FSI_I2C,
                       TARGETING::TYPE_MEMBUF,
                       fsi_i2cPerformOp );

// ------------------------------------------------------------------
// fsi_i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t fsi_i2cPerformOp( DeviceFW::OperationType i_opType,
                             TARGETING::Target * i_target,
                             void * io_buffer,
                             size_t & io_buflen,
                             int64_t i_accessType,
                             va_list i_args )
{
    errlHndl_t err = NULL;

    // Get the input args our of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // These are additional parms in the case an offset is passed in
    // via va_list, as well

    args.offset_length = va_arg( i_args, uint64_t);

    if ( args.offset_length != 0 )
    {
        args.offset_buffer = reinterpret_cast<uint8_t*>
                                             (va_arg(i_args, uint64_t));
    }

    // Set FSI switch to 1 and Host switch to 0
    args.switches.useHostI2C = 0;
    args.switches.useFsiI2C  = 1;


    // Call common function
    err = i2cCommonOp( i_opType,
                       i_target,
                       io_buffer,
                       io_buflen,
                       i_accessType,
                       args );


    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"fsi_i2cPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end fsi_i2cPerformOp

// ------------------------------------------------------------------
// i2cSetSwitches
// ------------------------------------------------------------------
void i2cSetSwitches( TARGETING::Target * i_target,
                     misc_args_t & io_args )
{
    // Set Host vs FSI switches if both values are zero;
    // Otherwise, caller should have already set them
    if ( ( io_args.switches.useHostI2C == 0 ) &&
         ( io_args.switches.useFsiI2C == 0 ) )
    {
        if ( !( i_target->tryGetAttr<TARGETING::ATTR_I2C_SWITCHES>
                                    (io_args.switches) ) )
        {
            // Default to Host
            io_args.switches.useHostI2C = 1;
            io_args.switches.useFsiI2C  = 0;
        }
    }
    return;
}

// ------------------------------------------------------------------
// i2cCommonOp
// ------------------------------------------------------------------
errlHndl_t i2cCommonOp( DeviceFW::OperationType i_opType,
                        TARGETING::Target * i_target,
                        void * io_buffer,
                        size_t & io_buflen,
                        int64_t i_accessType,
                        misc_args_t & i_args )
{
    errlHndl_t err = NULL;
    errlHndl_t err_reset = NULL;
    bool mutex_success = false;

    mutex_t * engineLock = NULL;
    bool mutex_needs_unlock = false;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cCommonOp(): i_opType=%d, aType=%d, "
               "p/e/devAddr= %d/%d/0x%X, len=%d, offset=%d/%p",
               (uint64_t) i_opType, i_accessType, i_args.port, i_args.engine,
               i_args.devAddr, io_buflen, i_args.offset_length,
               i_args.offset_buffer);

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cCommonOp(): i_opType=%d, aType=%d, "
               "p/e/devAddr= %d/%d/0x%x, len=%d, offset=%d/%p",
               (uint64_t) i_opType, i_accessType, i_args.port, i_args.engine,
               i_args.devAddr, io_buflen, i_args.offset_length,
               i_args.offset_buffer);

    do
    {
        // Check for Master Sentinel chip
        if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCommonOp() - Cannot target Master Sentinel "
                       "Chip for an I2C Operation!" );

            /*@
             * @errortype
             * @reasoncode     I2C_MASTER_SENTINEL_TARGET
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_PERFORM_OP
             * @userdata1      Operation Type requested
             * @userdata2      <UNUSED>
             * @devdesc        Master Sentinel chip was used as a target for an
             *                 I2C operation.  This is not permitted.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PERFORM_OP,
                                           I2C_MASTER_SENTINEL_TARGET,
                                           i_opType,
                                           0x0,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        //Set Host vs Fsi switches if not done already
        i2cSetSwitches(i_target, i_args);

        // Get the mutex for the requested engine
        mutex_success = i2cGetEngineMutex( i_target,
                                       i_args,
                                       engineLock );

        if( !mutex_success )
        {
            TRACUCOMP( g_trac_i2c,
                       ERR_MRK"Error in i2cCommonOp::i2cGetEngineMutex()");
            break;
        }

        // Lock on this engine
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Obtaining lock for engine: %d",
                   i_args.engine );
        (void)mutex_lock( engineLock );
        mutex_needs_unlock = true;
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Locked on engine: %d",
                   i_args.engine );


        // Calculate variables related to I2C Bus Speed in 'args' struct
        err =  i2cSetBusVariables( i_target, I2C_BUS_SPEED_FROM_MRW, i_args);

        if( err )
        {
            // Skip performing the actual I2C Operation
            break;
        }


        /*******************************************************/
        /*  Perform the I2C Operation                          */
        /*******************************************************/

        /***********************************************/
        /* I2C Read with Offset                        */
        /***********************************************/
        if( i_opType        == DeviceFW::READ &&
            i_args.offset_length != 0 )
        {

            // First WRITE offset to device without a stop
            i_args.read_not_write  = false;
            i_args.with_stop       = false;
            i_args.skip_mode_setup = false;

            err = i2cWrite( i_target,
                            i_args.offset_buffer,
                            i_args.offset_length,
                            i_args );

            if( err == NULL )
            {
                // Now do the READ with a stop
                i_args.read_not_write = true;
                i_args.with_stop      = true;

                // Skip mode setup on this cmd -
                // already set with previous cmd
                i_args.skip_mode_setup = true;

                err = i2cRead( i_target,
                               io_buffer,
                               io_buflen,
                               i_args );
            }
        }

        /***********************************************/
        /* I2C Write with Offset                       */
        /***********************************************/
        else if( i_opType        == DeviceFW::WRITE &&
                 i_args.offset_length != 0 )
        {

            // Add the Offset Information to the start of the data and
            // then send as a single write operation

            size_t newBufLen = i_args.offset_length + io_buflen;
            uint8_t * newBuffer = static_cast<uint8_t*>(malloc(newBufLen));

            // Add the Offset to the buffer
            memcpy( newBuffer, i_args.offset_buffer, i_args.offset_length);

            // Now add the data the user wanted to write
            memcpy( &newBuffer[i_args.offset_length], io_buffer, io_buflen);

            // Write parms:
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;

            err = i2cWrite( i_target,
                            newBuffer,
                            newBufLen,
                            i_args );


            free( newBuffer );

        }

        /***********************************************/
        /* I2C Read (no offset)                        */
        /***********************************************/
        else if ( i_opType        == DeviceFW::READ &&
                  i_args.offset_length == 0 )
        {
            // Do a direct READ
            i_args.read_not_write  = true;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;

            err = i2cRead( i_target,
                           io_buffer,
                           io_buflen,
                           i_args);
        }


        /***********************************************/
        /* I2C Write (no offset)                       */
        /***********************************************/
        else if( i_opType        == DeviceFW::WRITE &&
                 i_args.offset_length == 0 )
        {
            // Do a direct WRITE with a stop
            i_args.read_not_write  = false;
            i_args.with_stop       = true;
            i_args.skip_mode_setup = false;

            err = i2cWrite( i_target,
                            io_buffer,
                            io_buflen,
                            i_args);
        }

        /********************************************************/
        /* Error - Unsupported I2C Op/Offset Type Combination   */
        /********************************************************/
        else
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cCommonOp() - "
                       "Unsupported Op/Offset-Type Combination=%d/%d",
                       i_opType, i_args.offset_length );
            uint64_t userdata2 = i_args.offset_length;
            userdata2 = (userdata2 << 16) | i_args.port;
            userdata2 = (userdata2 << 16) | i_args.engine;
            userdata2 = (userdata2 << 16) | i_args.devAddr;

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
             * @devdesc          Invalid operation type.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_PERFORM_OP,
                                           I2C_INVALID_OP_TYPE,
                                           i_opType,
                                           userdata2,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( I2C_COMP_NAME, 256);

            // No Operation performed, so can break and skip the section
            // that handles operation errors
            break;
        }

        // Handle Error from I2C Operation
        if( err )
        {

            // if it was a bus arbition lost error set the
            // the reset level so a force unlock reset can be performed
            i2c_reset_level l_reset_level = BASIC_RESET;

            if ( err->reasonCode() == I2C_ARBITRATION_LOST_ONLY_FOUND )
            {
                l_reset_level = FORCE_UNLOCK_RESET;
            }

            // Reset the I2C Master
            err_reset = i2cReset( i_target,
                                  i_args,
                                  l_reset_level);

            if( err_reset )
            {
                // 2 error logs, so commit the reset log here
                TRACFCOMP( g_trac_i2c, ERR_MRK"i2cCommonOp() - "
                           "Previous error (rc=0x%X, eid=0x%X) before "
                           "i2cReset() failed.  Committing reset error "
                           "(rc=0x%X, eid=0x%X) and returning original error",
                           err->reasonCode(), err->eid(),
                           err_reset->reasonCode(), err_reset->eid() );

                errlCommit( err_reset, I2C_COMP_ID );
            }

            // Sleep to allow devices to recover from reset
            nanosleep( 0, I2C_RESET_DELAY_NS );

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
                   i_args.engine );
    }

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        // @todo RTC 114298- update this for new parms/switches
        I2C::UdI2CParms( i_opType,
                         i_target,
                         io_buflen,
                         i_accessType,
                         i_args  )
                       .addToLog(err);
    }

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cCommonOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end i2cCommonOp



// ------------------------------------------------------------------
// i2cPresence
// ------------------------------------------------------------------
bool i2cPresence( TARGETING::Target * i_target,
                        uint64_t i_port,
                        uint64_t i_engine,
                        uint64_t i_devAddr )
{
    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cPresence(): tgt=0x%X: e/p/devAddr="
              "%d/%d/0x%X", TARGETING::get_huid(i_target), i_engine,
              i_port, i_devAddr );

    errlHndl_t err = NULL;
    bool l_mutex_success = false;
    bool l_present = false;
    size_t buflen = 1;
    uint64_t reset_error = 0;
    misc_args_t args;

    args.port = i_port;
    args.engine = i_engine;
    args.devAddr = i_devAddr;
    args.read_not_write = true;
    args.with_stop = true;
    args.skip_mode_setup = false;

    //Registers
    status_reg_t status;
    fifo_reg_t fifo;


    // Synchronization
    mutex_t * engineLock = NULL;
    bool mutex_needs_unlock = false;

    // Use Local Variables (timeoutCount gets decremented);
    uint64_t l_interval_ns;
    uint64_t l_timeoutCount;


    do
    {

        // Get the mutex for the requested engine
        l_mutex_success = i2cGetEngineMutex( i_target,
                                         args,
                                         engineLock );

        if( !l_mutex_success )
        {
            TRACUCOMP( g_trac_i2c,
                       ERR_MRK"Error in i2cPresence::i2cGetEngineMutex()");
            break;
        }

        // Lock on this engine
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Obtaining lock for engine: %d",
                   args.engine );

        (void)mutex_lock( engineLock );
        mutex_needs_unlock = true;

        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Locked on engine: %d",
                   args.engine );



        // Set I2C Mode (Host vs FSI) for the target
        args.switches.useHostI2C = 0;
        args.switches.useFsiI2C  = 0;
        i2cSetSwitches( i_target, args );

        err = i2cSetBusVariables(i_target,
                                 I2C_BUS_SPEED_400KHZ,
                                 args);

        if( err )
        {
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"error in i2cPresence::i2cSetBusVariables()");
            break;
        }

        err = i2cSetup( i_target,
                        buflen,
                        args );

        if( err )
        {
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"error in i2cPresence::i2cSetup()");
            break;
        }

        l_interval_ns = args.polling_interval_ns;
        l_timeoutCount = args.timeout_count;

        //Check the Command Complete bit
        do
        {
            nanosleep( 0, l_interval_ns );

            status.value = 0x0ull;
            err = i2cRegisterOp( DeviceFW::READ,
                                 i_target,
                                 &status.value,
                                 I2C_REG_STATUS,
                                 args );

            if( err )
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"i2cPresence::error in i2cRegisterOp()");
                break;
            }

            if( 0 == l_timeoutCount-- )
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"i2cPresence() - Timed out waiting for "
                                 "Command Complete!");
                break;
            }

        }while( 0 == status.command_complete &&
                0 == status.fifo_entry_count &&
                0 == status.nack_received &&
                0 == status.data_request ); /* Command has completed
                                                   or fifo has data    */

        if( err )
        {
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"Error when waiting for Command Complete");
            break;
        }


        if( status.nack_received == 0 )
        {
            //The chip was present.
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"chip found! i2cPresence returning true!");

            // No nack received so we check the FIFO register
            if( status.fifo_entry_count != 0 || status.data_request != 0 )
            {

                //Read data from FIFO register to complete operation.
                fifo.value = 0x0ull;
                err = i2cRegisterOp( DeviceFW::READ,
                                     i_target,
                                     &fifo.value,
                                     I2C_REG_FIFO,
                                     args );

                TRACUCOMP(g_trac_i2c,
                          "i2cPresence() - FIFO = 0x%016llx",
                          fifo.value);

                if( err )
                {
                    TRACUCOMP(g_trac_i2c,
                    ERR_MRK"Error in i2cPresence::i2cRegisterOp()"
                    " - FIFO register");
                    break;
                }

                // -check for command complete
                err = i2cWaitForCmdComp(i_target,
                                        args );
                if( err )
                {
                    TRACUCOMP(g_trac_i2c,
                           ERR_MRK"Error in i2cPresence::i2cWaitForCmdComp()");
                    break;
                }

            }

            l_present = true;
            break;
        }
        else
        {
            //The chip was not present.
            TRACUCOMP(g_trac_i2c,
                      ERR_MRK"The chip was not present!");

            // reset error register
            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &reset_error,
                                 I2C_REG_RESET_ERRORS,
                                 args );

            if( err )
            {
                TRACUCOMP(g_trac_i2c,
                          ERR_MRK"Error in i2cPresence::i2cRegisterOp()"
                          " - Error register");
            }
            break;
        }

    } while ( 0 );

    if( err )
    {
        TRACFCOMP( g_trac_i2c,
                   ERR_MRK"i2cPresence() Error!"
                   "tgt=0x%X",
                   TARGETING::get_huid(i_target));
        errlCommit(err,
                   I2C_COMP_ID);

    }

    // Check if we need to unlock the mutex
    if ( mutex_needs_unlock == true )
    {
        // Unlock
        (void) mutex_unlock( engineLock );
        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"Unlocked engine: %d",
                   args.engine );
    }

    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cPresence(): tgt=0x%X: e/p/devAddr="
              "%d/%d/0x%X: l_present=%d",
              TARGETING::get_huid(i_target), i_engine, i_port, i_devAddr,
              l_present );

    return l_present;

}


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

    // Use Local Variables (timeoutCount gets derecmented)
    uint64_t interval_ns  = i_args.polling_interval_ns;
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
                nanosleep( 0, interval_ns );

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

                    // For now limited in what we can call out:
                    // Could be an issue with Processor or its bus
                    // -- both on the same FRU
                    // @todo RTC 94872 - update this callout
                    err->addHwCallout( i_target,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL );

                    // Or HB code failed to do the procedure correctly
                    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_LOW);

                    err->collectTrace( I2C_COMP_NAME, 256);

                    break;
                }
            }

            if( err )
            {
                break;
            }

            // Read the data from the fifo
            fifo.value = 0x0ull;

            err = i2cRegisterOp( DeviceFW::READ,
                                 i_target,
                                 &fifo.value,
                                 I2C_REG_FIFO,
                                 i_args );

            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cRead() - FIFO = 0x%016llx",
                       fifo.value);

            if( err )
            {
                break;
            }

            *((uint8_t*)o_buffer + bytesRead) = fifo.byte_0;

            // Every time FIFO is read, reset timeout count
            timeoutCount = I2C_TIMEOUT_COUNT( interval_ns );

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

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &fifo.value,
                                 I2C_REG_FIFO,
                                 i_args );

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

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );

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

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &cmd.value,
                             I2C_REG_COMMAND,
                             i_args );

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
// i2cGetEngineMutex
// ------------------------------------------------------------------
bool i2cGetEngineMutex( TARGETING::Target * i_target,
                        misc_args_t & i_args,
                        mutex_t *& i_engineLock )
{
    bool success = true;

    do
    {
        switch( i_args.engine )
        {
            case 0:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_0>();
                break;
            case 1:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_1>();
                break;
            case 2:
                i_engineLock = i_target->
                           getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_2>();
                break;

            default:
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"Invalid engine for getting Mutex! "
                           "i_args.engine=%d", i_args.engine );
                success = false;
                assert(false, "i2c.C: Invalid engine for getting Mutex!"
                       "i_args.engine=%d", i_args.engine );

                break;
        };

    }while( 0 );

    return success;
}


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

    // Use Local Variables (timeoutCount gets decremented)
    uint64_t interval_ns  = i_args.polling_interval_ns;
    uint64_t timeoutCount = i_args.timeout_count;

    TRACUCOMP(g_trac_i2c, "i2cWaitForCmdComp(): timeoutCount=%d, "
              "interval_ns=%d", timeoutCount, interval_ns);

    do
    {
        // Check the Command Complete bit
        do
        {
            nanosleep( 0, interval_ns );

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


                // For now limited in what we can call out:
                // Could be an issue with Processor or its bus
                // -- both on the same FRU
                // @todo RTC 94872 - update this callout
                err->addHwCallout( i_target,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL );

                // Or HB code failed to do the procedure correctly
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                err->collectTrace( I2C_COMP_NAME, 256);

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

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cReadStatusReg()" );

    do
    {
        // Read the status Reg
        err = i2cRegisterOp( DeviceFW::READ,
                             i_target,
                             &o_statusReg.value,
                             I2C_REG_STATUS,
                             i_args );

        if( err )
        {
            break;
        }

        TRACUCOMP(g_trac_i2c,"i2cReadStatusReg(): "
                  INFO_MRK"status: 0x%016llx",
                  o_statusReg.value );


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
    bool nackFound  = false;
    bool busArbiLostFound = false;
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
            busArbiLostFound = true;
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Arbitration Lost! - status reg: %016llx",
                       i_statusVal.value );
        }

        if( 1 == i_statusVal.nack_received )
        {
            // Rather than using 'errorFound', use specific nackFound
            nackFound  = true;
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
                       ERR_MRK"i2cCheckForErrors() - Error(s) found" );

            // Combine the status registers
            uint64_t userdata1 = (0xFFFFFFFF00000000 & i_statusVal.value);
            userdata1 |= ( 0xFFFFFFFF00000000 & intRegVal)  >> 32;


            // Combine multiple input arguments
            uint64_t userdata2 = 0;
            userdata2 = static_cast<uint64_t>(i_args.engine) << 56;
            userdata2 |= static_cast<uint64_t>(i_args.port) << 48;
            userdata2 |= static_cast<uint64_t>(i_args.bit_rate_divisor) << 32;
            userdata2 |= TARGETING::get_huid(i_target);

            /*@
             * @errortype
             * @reasoncode       I2C_HW_ERROR_FOUND
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C_CHECK_FOR_ERRORS
             * @userdata1[0:31   Status Register Value
             * @userdata1[32:63] Interrupt Register Value (only valid in
             *                   Interrupt case)
             * @userdata2[0:7]   I2C Master Engine
             * @userdata2[8:15]  I2C Master Port
             * @userdata2[16:31] I2C Mode Register Bit Rate Divisor
             * @userdata2[32:63] I2C Master Target HUID
             * @devdesc          Error was found in I2C status register.
             *                   Check userdata to determine what the error was.
             * @custdesc       A problem occurred during the IPL of the system:
             *                 An error was found in the I2C status register.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_HW_ERROR_FOUND,
                                           userdata1,
                                           userdata2);

            // For now limited in what we can call out:
            // Could be an issue with Processor or its bus
            // -- both on the same FRU
            // @todo RTC 94872 - update this callout
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL );

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( I2C_COMP_NAME );

            break;
        }

        else if ( nackFound )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cCheckForErrors() - NACK found (only error)" );

            /*@
             * @errortype
             * @reasoncode     I2C_NACK_ONLY_FOUND
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       I2C_CHECK_FOR_ERRORS
             * @userdata1      Status Register Value
             * @userdata2      Interrupt Register Value
             * @devdesc        a NACK Error was found in the I2C status
             *                 register.
             * @custdesc       A problem occurred during the IPL of the system:
             *                 A NACK error was found in the I2C Status
             *                 register.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_NACK_ONLY_FOUND,
                                           i_statusVal.value,
                                           intRegVal );

            // For now limited in what we can call out:
            // Could be an issue with Processor or its bus
            // -- both on the same FRU
            // @todo RTC 94872 - update this callout
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL );

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( I2C_COMP_NAME );

            break;
        }
        else if( busArbiLostFound )
        {
            TRACFCOMP( g_trac_i2c,
            ERR_MRK"i2cCheckForErrors() - Bus Arbitration Lost (only error)");

            /*@
             * @errortype
             * @reasoncode     I2C_ARBITRATION_LOST_ONLY_FOUND
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       I2C_CHECK_FOR_ERRORS
             * @userdata1      Status Register Value
             * @userdata2      Interrupt Register Value
             * @devdesc        Bus Arbitration Lost Error was found in
             *                 the I2C status register.
             * @custdesc       A problem occurred during the IPL of the system:
             *                 A Bus Arbitration Lost error was found
             *                 in the I2C status register.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_CHECK_FOR_ERRORS,
                                           I2C_ARBITRATION_LOST_ONLY_FOUND,
                                           i_statusVal.value,
                                           intRegVal );

            // For now limited in what we can call out:
            // Could be an issue with Processor or its bus
            // -- both on the same FRU
            // @todo RTC 94872 - update this callout
            err->addHwCallout( i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL );

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            err->collectTrace( I2C_COMP_NAME );

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
    uint64_t interval_ns  = i_args.polling_interval_ns;
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
            nanosleep( 0, interval_ns );

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

                // For now limited in what we can call out:
                // Could be an issue with Processor or its bus
                // -- both on the same FRU
                // @todo RTC 94872 - update this callout
                err->addHwCallout( i_target,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL );

                // Or HB code failed to do the procedure correctly
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);

                err->collectTrace( I2C_COMP_NAME, 256);

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
// i2cSendStopSignal
// ------------------------------------------------------------------
errlHndl_t i2cSendStopSignal(TARGETING::Target * i_target,
                                misc_args_t & i_args)
{

    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSendStopSignal" );

    do
    {
        residual_length_reg_t clkdataline;
        clkdataline.value = 0x0;

        //manually send stop signal
        // set clock low: write 0 to immediate reset scl register

        TRACUCOMP(g_trac_i2c,"i2cSendStopSignal"
                  "clock line 0x%016llx",
                  clkdataline.value );

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_RESET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C reset SCL register Failed!!" );
            break;
        }

        //set data low: write 0 to immediate reset sda register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_RESET_SDA,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C reset SDA register Failed!!" );
            break;
        }

        // set clock high: write 0 to immediate set scl register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_SET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C set SCL register Failed!!" );
            break;
        }

        //set data high: write 0 to immediate set sda register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkdataline.value,
                             I2C_REG_SET_SDA,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C set SDA register Failed!!" );
            break;
        }
    }while(0);

    return err;
}//end i2cSendStopSignal


// ------------------------------------------------------------------
// i2cToggleClockLine
// ------------------------------------------------------------------
errlHndl_t i2cToggleClockLine(TARGETING::Target * i_target,
                                misc_args_t & i_args)
{

    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cToggleClockLine()" );

    do
    {
        residual_length_reg_t clkline;
        clkline.value = 0x0;

        //toggle clock line
        // set clock low: write 0 to immediate reset scl register

        TRACUCOMP(g_trac_i2c,"i2cToggleClockLine()"
                  "clock line 0x%016llx",
                  clkline.value );

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkline.value,
                             I2C_REG_RESET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C reset SCL register Failed!!" );
            break;
        }

        // set clock high: write 0 to immediate set scl register
        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &clkline.value,
                             I2C_REG_SET_SCL,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C set SCL register Failed!!" );
            break;
        }

    }while(0);

    return err;
}//end i2cToggleClockLine


// ------------------------------------------------------------------
// i2cForceResetAndUnlock
// ------------------------------------------------------------------
errlHndl_t i2cForceResetAndUnlock( TARGETING::Target * i_target,
                                    misc_args_t & i_args)
{

    errlHndl_t err = NULL;
    mode_reg_t mode;
    uint64_t l_speed = I2C_BUS_SPEED_FROM_MRW;

    // I2C Bus Speed Array
    TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cForceResetAndUnlock()" );

    do
    {

        // Get I2C Bus Speed Array attribute.  It will be used to determine
        // which engine/port combinations have devices on them
        if (  !( i_target->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                          (speed_array) ) )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cForceResetAndUnlock() - Cannot find "
                       "ATTR_I2C_BUS_SPEED_ARRAY needed for operation");
            /*@
             * @errortype
             * @reasoncode     I2C_ATTRIBUTE_NOT_FOUND
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_FORCE_RESET_AND_UNLOCK
             * @userdata1      Target for the attribute
             * @userdata2      <UNUSED>
             * @devdesc        ATTR_I2C_BUS_SPEED_ARRAY not found
             * @custdesc       I2C configuration data missing
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_FORCE_RESET_AND_UNLOCK,
                                           I2C_ATTRIBUTE_NOT_FOUND,
                                           TARGETING::get_huid(i_target),
                                           0x0,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        // Need to send slave stop to all ports with a device on the engine
        for( uint32_t port = 0; port < P8_MASTER_PORTS; port++ )
        {

            // Only send stop to a port if there are devices on it
            l_speed = speed_array[i_args.engine][port];
            if ( l_speed == 0 )
            {
                continue;
            }

            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cForceResetAndUnlock() - Performing op on "
                       "engine=%d, port=%d",
                       i_args.engine, port);

            // Clear mode register
            mode.value = 0x0ull;

            // set port in mode register
            mode.port_num = port;

            // enable diagnostic mode in mode register
            mode.diag_mode = 0x1;

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );

            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"I2C Enable Diagnostic mode Failed!!" );


                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }


            //toggle clock line
            err = i2cToggleClockLine( i_target,
                                      i_args );

            if( err )
            {
                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            //manually send stop signal
            err = i2cSendStopSignal( i_target,
                                     i_args );

            if( err )
            {
                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // disable diagnostic mode in mode register
            mode.diag_mode = 0x0;

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );


            if( err )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"I2C disable Diagnostic mode Failed!!" );
                // We still need to reset the other ports on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }


        } // end of port for loop

    }while(0);

    return err;
}// end i2cForceResetAndUnlock

// ------------------------------------------------------------------
// i2cReset
// ------------------------------------------------------------------
errlHndl_t i2cReset ( TARGETING::Target * i_target,
                      misc_args_t & i_args,
                      i2c_reset_level i_reset_level)
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cReset()" );

    // Writing to the Status Register does a full I2C reset.
    status_reg_t reset;

    do
    {
        reset.value = 0x0;

        err = i2cRegisterOp( DeviceFW::WRITE,
                             i_target,
                             &reset.value,
                             I2C_REG_RESET,
                             i_args );

        if( err )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"I2C Reset Failed!!" );
            break;
        }

        //if the reset is a force unlock then we need to enable
        //diagnostic mode and toggle the clock and data lines
        //to manually reset the bus
        if( i_reset_level == FORCE_UNLOCK_RESET )
        {
            err = i2cForceResetAndUnlock( i_target,
                                          i_args );

            if( err )
            {
                // We still want to send the slave stop command since the
                // initial reset completed above.
                // So just commit the log here and let the function continue.
                errlCommit( err, I2C_COMP_ID );
            }
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

    // Master Registers
    mode_reg_t mode;
    command_reg_t cmd;
    uint64_t l_speed = I2C_BUS_SPEED_FROM_MRW;

    // I2C Bus Speed Array
    TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;
    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSendSlaveStop()" );

    do
    {

        // Get I2C Bus Speed Array attribute.  It will be used to determine
        // which engine/port combinations have devices on them
        if (  !( i_target->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                          (speed_array) ) )
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"i2cSendSlaveStop() - Cannot find "
                       "ATTR_I2C_BUS_SPEED_ARRAY needed for operation");

            /*@
             * @errortype
             * @reasoncode     I2C_ATTRIBUTE_NOT_FOUND
             * @severity       ERRORLOG_SEV_UNRECOVERABLE
             * @moduleid       I2C_SEND_SLAVE_STOP
             * @userdata1      Target for the attribute
             * @userdata2      <UNUSED>
             * @devdesc        ATTR_I2C_BUS_SPEED_ARRAY not found
             * @custdesc       I2C configuration data missing
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2C_SEND_SLAVE_STOP,
                                           I2C_ATTRIBUTE_NOT_FOUND,
                                           TARGETING::get_huid(i_target),
                                           0x0,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( I2C_COMP_NAME, 256);

            break;
        }

        // Need to send slave stop to all ports with a device on the engine
        for( uint32_t port = 0; port < P8_MASTER_PORTS; port++ )
        {
            // Only send stop to a port if there are devices on it
            l_speed = speed_array[i_args.engine][port];
            if ( l_speed == 0 )
            {
                continue;
            }

            mode.value = 0x0ull;

            mode.port_num = port;
            mode.enhanced_mode = 1;

            // Need this to set bit_rate_divisor
            err = i2cSetBusVariables ( i_target,
                                       l_speed,
                                       i_args );
            if( err )
            {
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            mode.bit_rate_div = i_args.bit_rate_divisor;

            TRACUCOMP(g_trac_i2c,"i2cSendSlaveStop(): "
                      "mode: 0x%016llx",
                      mode.value );

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &mode.value,
                                 I2C_REG_MODE,
                                 i_args );

            if( err )
            {
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            cmd.value = 0x0ull;
            cmd.with_stop = 1;

            TRACUCOMP(g_trac_i2c,"i2cSendSlaveStop(): "
                      "cmd: 0x%016llx",
                      cmd.value );

            err = i2cRegisterOp( DeviceFW::WRITE,
                                 i_target,
                                 &cmd.value,
                                 I2C_REG_COMMAND,
                                 i_args );

            if( err )
            {
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // Now wait for cmd Complete
            err = i2cWaitForCmdComp( i_target,
                                     i_args );

            if( err )
            {
                // We still need to send the slave stop to the other ports
                // on this I2C engine
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

        } // end of port for-loop

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

    // Master Regs
    interrupt_reg_t intreg;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cGetInterrupts()" );

    do
    {
        intreg.value = 0x0;

        err = i2cRegisterOp( DeviceFW::READ,
                             i_target,
                             &intreg.value,
                             I2C_REG_INTERRUPT,
                             i_args );
        if( err )
        {
            break;
        }

        TRACUCOMP(g_trac_i2c,"i2cGetInterrupts(): "
                  "interrupt: 0x%016llx",
                  intreg.value );

        // Return the data read
        o_intRegValue = intreg.value;
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cGetInterrupts( int reg val: %016llx)",
               o_intRegValue );

    return err;
} // end i2cGetInterrupts

#define I2C_CALCULATE_BRD( i_clockSpeed ) ( i_clockSpeed / 37 )
// #define BRD_1024 = ( ( nest_freq / ( 16 * 1024 * KILOBYTE ) ) - 1 ) / 4;

// ------------------------------------------------------------------
//  i2cSetBusVariables
// ------------------------------------------------------------------
errlHndl_t i2cSetBusVariables ( TARGETING::Target * i_target,
                                uint64_t i_speed,
                                misc_args_t & io_args)
{
    errlHndl_t err = NULL;

    TRACUCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetBusVariables(): i_speed=%d",
               i_speed );

    do
    {
        if ( i_speed == I2C_BUS_SPEED_FROM_MRW )
        {
            // Read data from attributes set by MRW
            TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;

            if (
                ( !( i_target->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                          (speed_array) ) )   ||
                ( io_args.engine >= I2C_BUS_ATTR_MAX_ENGINE ) ||
                ( io_args.port   >= I2C_BUS_ATTR_MAX_PORT )
               )
            {
                // Default to 400KHz
                TRACFCOMP( g_trac_i2c, ERR_MRK"i2cSetBusVariables: "
                           "unable to get TARGETING::ATTR_I2C_BUS_SPEED_ARRAY "
                           "or invalid engine(%d)/port(%d) combo. "
                           "Defaulting to 400KHz.",
                           io_args.engine, io_args.port);
                io_args.bus_speed = I2C_BUS_SPEED_400KHZ;
            }
            else
            {
                io_args.bus_speed = speed_array[io_args.engine][io_args.port];

                assert(io_args.bus_speed,
                       "i2cSetBusVariables: bus_speed array[%d][%d] for "
                       "tgt 0x%X is 0",
                       io_args.engine, io_args.port,
                       TARGETING::get_huid(i_target));
            }
        }
        else
        {
            io_args.bus_speed = i_speed;
        }

        // Set other variables based off of io_args.bus_speed
        io_args.polling_interval_ns = i2cGetPollingInterval(io_args.bus_speed);
        io_args.timeout_count = I2C_TIMEOUT_COUNT(io_args.polling_interval_ns);

        // The Bit-Rate-Divisor set in the I2C Master mode register needs
        // to know the frequency of the "local bus" serving as a reflock
        // for the I2C Master
        uint64_t local_bus_MHZ = 0;

        if ( io_args.switches.useFsiI2C == 1 )
        {
            // @todo RTC 117560 - verify correct frequency
            local_bus_MHZ = g_I2C_NEST_FREQ_MHZ;
        }
        else
        {
            // For Host I2C use Nest Frequency
            local_bus_MHZ = g_I2C_NEST_FREQ_MHZ;
        }

        io_args.bit_rate_divisor = i2cGetBitRateDivisor(io_args.bus_speed,
                                                        local_bus_MHZ);

    } while( 0 );

    TRACUCOMP(g_trac_i2c,"i2cSetBusVariables(): tgt=0x%X, e/p/dA=%d/%d/0x%X: "
              "speed=%d: b_sp=%d, b_r_d=0x%x, p_i=%d, to_c = %d",
              TARGETING::get_huid(i_target),
              io_args.engine, io_args.port, io_args.devAddr,
              i_speed, io_args.bus_speed, io_args.bit_rate_divisor,
              io_args.polling_interval_ns, io_args.timeout_count);

    TRACUCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetBusVariables()" );

    return err;
}

/**
 * @brief This function will handle everything required to process
 *        each I2C master engine based on the input argements.
 *        List of operations in the i2cProcessOperation internal enum.
 */
enum i2cProcessOperation
{
    I2C_OP_RESET   = 1,
    I2C_OP_SETUP   = 2,
};
errlHndl_t i2cProcessActiveMasters ( i2cProcessType      i_processType,
                                     i2cProcessOperation i_processOperation,
                                     uint64_t            i_busSpeed,
                                     bool                i_functional )
{
    errlHndl_t err = NULL;
    bool error_found = false;
    bool mutex_success = false;
    mutex_t * engineLock = NULL;
    bool mutex_needs_unlock = false;

    misc_args_t io_args;

    // I2C Bus Speed Array
    TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speed_array;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cProcessActiveMasters(): Type=0x%X, "
               "Operation=%d Bus Speed=%d Functional=%d",
               i_processType, i_processOperation, i_busSpeed, i_functional );
    do
    {

        // Get list of Procs
        TARGETING::TargetHandleList procList;

        if ( i_processType & I2C_RANGE_PROC )
        {

            // Pass input parameter for function (true) or existing (false)
            TARGETING::getAllChips(procList,
                                   TARGETING::TYPE_PROC,
                                   i_functional);

            if( 0 == procList.size() )
            {
                TRACFCOMP(g_trac_i2c,INFO_MRK
                       "i2cProcessActiveMasters: No Processor chips found!");

            }

            TRACFCOMP( g_trac_i2c,
                     INFO_MRK"i2cProcessActiveMasters: I2C Master Procs: %d",
                     procList.size() );
        }

        // Get list of Membufs
        TARGETING::TargetHandleList membufList;

        if ( i_processType & I2C_RANGE_MEMBUF )
        {

            // Pass input parameter for function (true) or existing (false)
            TARGETING::getAllChips(membufList,
                                   TARGETING::TYPE_MEMBUF,
                                   i_functional);

            if( 0 == membufList.size() )
            {
                TRACFCOMP(g_trac_i2c,INFO_MRK
                          "i2cProcessActiveMasters: No Membuf chips found!");
            }

            TRACFCOMP( g_trac_i2c,
                   INFO_MRK"i2cProcessActiveMasters: I2C Master Membufs: %d",
                   membufList.size() );
        }

        // Combine lists into chipList
        TARGETING::TargetHandleList chipList;
        chipList.insert(chipList.end(), procList.begin(), procList.end());
        chipList.insert(chipList.end(), membufList.begin(), membufList.end());

        // Get the Master Proc Chip Target for comparisons later
        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target* masterProcChipTargetHandle = NULL;
        err = tS.queryMasterProcChipTargetHandle(masterProcChipTargetHandle);

        assert((err == NULL), "tS.queryMasterProcChipTargetHandle returned "
               "err for masterProcChipTargetHandle");

        // Process each chip/target
        for( size_t chip = 0; chip < chipList.size(); chip++ )
        {
            TARGETING::Target* tgt = chipList[chip];

            TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cProcessActiveMasters: Loop for tgt=0x%X",
                       TARGETING::get_huid(tgt) );

            // Look up I2C Mode for the target
            io_args.switches.useHostI2C = 0;
            io_args.switches.useFsiI2C  = 0;
            i2cSetSwitches( tgt, io_args );

            // Compare mode with input parameter
            if ( !( i_processType & I2C_RANGE_HOST )
                 && ( io_args.switches.useHostI2C == 1 ) )
            {
                TRACUCOMP( g_trac_i2c,
                        INFO_MRK"i2cProcessActiveMasters: skipping tgt=0x%X "
                        "due to i_processType=%d, useHostI2C=%d",
                        TARGETING::get_huid(tgt), i_processType,
                        io_args.switches.useHostI2C );
                continue;
            }

            if ( !( i_processType & I2C_RANGE_FSI )
                 && ( io_args.switches.useFsiI2C == 1 ) )
            {
                TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cProcessActiveMasters: skipping tgt=0x%X "
                       "due to i_processType=%d, useFsiI2C=%d",
                       TARGETING::get_huid(tgt), i_processType,
                       io_args.switches.useFsiI2C );
                continue;
            }


            // Get I2C Bus Speed Array attribute.  It will be used to
            // determine which engines have devices on them
            if ( !(tgt->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                                           (speed_array) ) )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"i2cSendSlaveStop() - Cannot find "
                           "ATTR_I2C_BUS_SPEED_ARRAY needed for operation");

                /*@
                 * @errortype
                 * @reasoncode     I2C_ATTRIBUTE_NOT_FOUND
                 * @severity       ERRORLOG_SEV_UNRECOVERABLE
                 * @moduleid       I2C_PROCESS_ACTIVE_MASTERS
                 * @userdata1      Target for the attribute
                 * @userdata2[0:31]  Operation
                 * @userdata2[32:64] Type
                 * @devdesc        ATTR_I2C_BUS_SPEED_ARRAY not found
                 * @custdesc       I2C configuration data missing
                 */
                err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        I2C_PROCESS_ACTIVE_MASTERS,
                                        I2C_ATTRIBUTE_NOT_FOUND,
                                        TARGETING::get_huid(tgt),
                                        TWO_UINT32_TO_UINT64(
                                            i_processOperation,
                                            i_processType),
                                        true /*Add HB SW Callout*/ );

                err->collectTrace( I2C_COMP_NAME, 256);

                // We still need to reset the other I2C engines
                errlCommit( err, I2C_COMP_ID );
                continue;
            }

            // if i_functional == false then all possible returned in chipList,
            // so need to check if each target is present
            // -- master target defaulted to present
            if ( ( i_functional == false ) &&
                 ( tgt != masterProcChipTargetHandle ) )
            {
                bool check = FSI::isSlavePresent(tgt);

                if ( check == false )
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                               "i2cProcessActiveMasters: skipping tgt=0x%X "
                               "due to FSI::isSlavePresent returned=%d",
                               TARGETING::get_huid(tgt), check );
                    continue;
                }
                else
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                             "i2cProcessActiveMasters: keeping tgt=0x%X due "
                             "to FSI::isSlavePresent returned=%d",
                             TARGETING::get_huid(tgt), check );
                }
            }

            for( size_t engine = 0;
                 engine < I2C_BUS_ATTR_MAX_ENGINE;
                 engine++ )
            {
                io_args.engine = engine;

                // Only reset engine 0 for FSI
                if ( (i_processOperation & I2C_OP_RESET ) &&
                     ( engine != 0 ) &&
                     (io_args.switches.useFsiI2C == 1) )
                {
                    continue;
                }

                // @todo RTC 126069 - only resetting engine 0 for now
                // -- only processors have an engine 1
                // (separate block from above to avoid merge issues)
                if ( ( i_processOperation & I2C_OP_RESET ) &&
                     ( engine != 0 ) )
                {
                    continue;
                }

                // Look for any device on this engine based on speed_array
                bool skip = true;
                for ( size_t j = 0; j < I2C_BUS_ATTR_MAX_PORT; j++ )
                {
                    if ( speed_array[engine][j] != 0 )
                    {
                        skip = false;
                        io_args.port = j; // use this port
                        break;
                    }
                }

                // PHYP wants all of the engines set regardless if hostboot
                // believes there is a device on the bus.
                if ( i_processOperation == I2C_OP_SETUP )
                {
                    skip = false;
                    io_args.port = 0;
                }

                if ( skip == true )
                {
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                              "i2cProcessActiveMasters: no devices found on "
                              "tgt=0x%X engine=%d",
                              TARGETING::get_huid(tgt), engine );
                    continue;
                }
                else
                {
                    TRACFCOMP( g_trac_i2c,INFO_MRK
                             "i2cProcessActiveMasters: Reset/Setup tgt=0x%X "
                             "engine=%d",
                             TARGETING::get_huid(tgt), engine );
                }

                error_found = false;
                mutex_needs_unlock = false;

                // Get the mutex for the requested engine
                mutex_success = i2cGetEngineMutex( tgt,
                                                   io_args,
                                                   engineLock );


                if( !mutex_success )
                {
                    TRACUCOMP( g_trac_i2c,
                               ERR_MRK"Error in i2cProcessActiveMasters: "
                               "i2cGetEngineMutex() failed to get mutex. "
                               "skipping reset on tgt=0x%X engine =%d",
                               TARGETING::get_huid(tgt), engine );
                    continue;
                }

                // Lock on this engine
                TRACUCOMP( g_trac_i2c,
                       INFO_MRK"i2cProcessActiveMasters: Obtaining lock for "
                       "engine: %d", engine );
                (void)mutex_lock( engineLock );
                mutex_needs_unlock = true;
                TRACUCOMP( g_trac_i2c,INFO_MRK
                           "i2cProcessActiveMasters: Locked on engine: %d",
                           engine );

                TRACUCOMP( g_trac_i2c,INFO_MRK
                           "i2cProcessActiveMasters: Setup/Reset "
                           "0x%X engine = %d",
                           TARGETING::get_huid(tgt), engine );

                // Setup Bus Speed
                err = i2cSetBusVariables ( tgt,
                                           i_busSpeed,
                                           io_args );
                if( err )
                {
                    error_found = true;

                    TRACFCOMP( g_trac_i2c,ERR_MRK
                               "i2cProcessActiveMasters: Error Setting Bus "
                               "Variables: tgt=0x%X engine=%d",
                               TARGETING::get_huid(tgt), engine );

                    // If we get error skip resetting this target, but still
                    // need to reset other I2C engines
                    errlCommit( err,
                                I2C_COMP_ID );

                    // Don't continue or break - need mutex unlock
                }

                // Now reset or setup the engine/bus
                if ( error_found == false )
                {
                    switch (i_processOperation)
                    {
                        case I2C_OP_RESET:
                        {
                            TRACFCOMP( g_trac_i2c,INFO_MRK
                                  "i2cProcessActiveMasters: reset engine: %d",
                                  engine );

                            err = i2cReset ( tgt, io_args,
                                     FORCE_UNLOCK_RESET);
                            if( err )
                            {
                                TRACFCOMP( g_trac_i2c,ERR_MRK
                                   "i2cProcessActiveMasters: Error reseting "
                                   "tgt=0x%X, engine=%d",
                                   TARGETING::get_huid(tgt), engine);

                                // If we get errors on the reset, we still need
                                // to reset the other I2C engines
                                errlCommit( err,
                                    I2C_COMP_ID );

                                // Don't continue or break - need mutex unlock
                            }
                            break;
                        }
                        case I2C_OP_SETUP:
                        {
                            mode_reg_t mode;
                            mode.value = 0x0;

                            TRACFCOMP( g_trac_i2c,INFO_MRK
                              "i2cProcessActiveMasters: setup engine: %d",
                              engine );

                            mode.bit_rate_div = io_args.bit_rate_divisor;

                            err = i2cRegisterOp( DeviceFW::WRITE,
                                                 tgt,
                                                 &mode.value,
                                                 I2C_REG_MODE,
                                                 io_args );
                            if( err )
                            {
                                TRACFCOMP( g_trac_i2c,
                                   ERR_MRK"i2cProcessActiveMasters:"
                                          " Error reading from"
                                          " Processor, engine: %d",
                                          engine );

                                // If we get errors on these reads,
                                // we still need to continue
                                // to program the I2C Bus Divisor for the rest
                                errlCommit( err,
                                        I2C_COMP_ID );
                            }
                            break;
                        }
                        default:
                            assert (0,"i2cProcessActiveMasters: "
                                      "invalid operation");
                     }
                }

                // Check if we need to unlock the mutex
                if ( mutex_needs_unlock == true )
                {
                    // Unlock
                    (void) mutex_unlock( engineLock );
                    TRACUCOMP( g_trac_i2c,INFO_MRK
                              "i2cProcessActiveMasters: Unlocked engine: %d",
                              engine );
                }

            } // end for-loop engine

        } // end for-loop chip

    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cProcessActiveMasters(): err rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}

/**
 * @brief This function is a wrapper to the common routine to reset
 *        I2C engines selected based on the input argements.
 *        Set bus speed from the MRW value.
 */
errlHndl_t i2cResetActiveMasters ( i2cProcessType i_resetType,
                                   bool i_functional )
{
    errlHndl_t err = NULL;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cResetActiveMasters(): i2cProcessType=0x%X, "
               "i_functional=%d",
               i_resetType, i_functional );

    err = i2cProcessActiveMasters (i_resetType,  // select engines
                                   I2C_OP_RESET, // reset engines
                                   I2C_BUS_SPEED_FROM_MRW,
                                   i_functional);

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cResetActiveMasters(): err rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}

/**
 * @brief This function is a wrapper to the common routine to setup
 *        I2C engines selected based on the input argements.
 *        Set bus speed 400KHZ for Phyp (and other payloads).
 */
errlHndl_t i2cSetupActiveMasters ( i2cProcessType i_setupType,
                                   bool i_functional )
{
    errlHndl_t err = NULL;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetupActiveMasters(): i2cProcessType=0x%X, "
               "i_functional=%d",
               i_setupType, i_functional );

    err = i2cProcessActiveMasters (i_setupType,   // select engines
                                   I2C_OP_SETUP,  // setup engines
                                   I2C_BUS_SPEED_400KHZ,
                                   i_functional);

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetupActiveMasters(): err rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}

// ------------------------------------------------------------------
//  i2cSetAccessMode
//   NOTE: currently just supporting I2C_SET_MODE_PROC_HOST
// ------------------------------------------------------------------
void i2cSetAccessMode( i2cSetAccessModeType i_setModeType )
{
    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetAccessMode(): %d", i_setModeType );

    TARGETING::I2cSwitches switches;

    bool mutex_success = false;
    mutex_t * engineLocks[I2C_BUS_ATTR_MAX_ENGINE];
    misc_args_t args;


    do
    {
        // Get list of targets
        TARGETING::TargetHandleList tgtList;

        // Support for I2C_SET_MODE_PROC_HOST
        TARGETING::getAllChips(tgtList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        if( 0 == tgtList.size() )
        {
            TRACFCOMP(g_trac_i2c,
                      INFO_MRK"i2cSetAccessMode: No Targets found!");
            break;
        }

        TRACUCOMP( g_trac_i2c,
                   INFO_MRK"i2cSetAccessMode: Targets: %d",
                   tgtList.size() );

        // Initalize mutex array
        for ( size_t index = 0; index < I2C_BUS_ATTR_MAX_ENGINE; index++ )
        {
            engineLocks[index] = NULL;
        }

        // Check and set each target
        for( size_t i = 0; i < tgtList.size(); i++ )
        {
            TARGETING::Target* tgt = tgtList[i];

            // Get the mutex for all engines
            for ( size_t engine = 0;
                  engine < I2C_BUS_ATTR_MAX_ENGINE;
                  engine++ )
            {
                args.engine = engine;
                engineLocks[engine] = NULL;

                mutex_success = i2cGetEngineMutex( tgt,
                                                   args,
                                                   engineLocks[engine] );

                if( !mutex_success )
                {
                    TRACFCOMP( g_trac_i2c,ERR_MRK"i2cSetAccessMode: Error from "
                               "i2cGetEngineMutex() getting engine %d lock for "
                               "tgt=0x%X", engine, TARGETING::get_huid(tgt));
                    break;
                }

                // Lock on this engine
                TRACUCOMP( g_trac_i2c,
                           INFO_MRK"Obtaining lock for engine: %d",
                           args.engine );

                (void)mutex_lock( engineLocks[engine] );

                TRACUCOMP( g_trac_i2c,
                           INFO_MRK"Locked on engine: %d",
                           args.engine );
            }

            if ( mutex_success )
            {
                // The target is locked so complete the operation
                switches = tgt->getAttr<TARGETING::ATTR_I2C_SWITCHES>();

                TRACUCOMP( g_trac_i2c,"i2cSetAccessMode: tgt=0x%X switches: "
                           "host=%d, fsi=%d",
                           TARGETING::get_huid(tgt), switches.useHostI2C,
                           switches.useFsiI2C);

                // Support for I2C_SET_MODE_PROC_HOST
                if ((switches.useHostI2C != 1) ||
                    (switches.useFsiI2C  != 0)   )
                {
                    switches.useHostI2C = 1;
                    switches.useFsiI2C  = 0;

                    tgt->setAttr<TARGETING::ATTR_I2C_SWITCHES>(switches);

                    TRACFCOMP( g_trac_i2c,"i2cSetAccessMode: tgt=0x%X "
                               "I2C_SWITCHES updated: host=%d, fsi=%d",
                               TARGETING::get_huid(tgt), switches.useHostI2C,
                               switches.useFsiI2C);
                }
            }

            // Unlock the engines
            for ( size_t engine = 0;
                  engine < I2C_BUS_ATTR_MAX_ENGINE;
                  engine++ )
            {
                args.engine = engine;
                if ( engineLocks[engine] != NULL )
                {
                    (void) mutex_unlock( engineLocks[engine] );
                    TRACUCOMP( g_trac_i2c,
                               INFO_MRK"Unlocked engine: %d",
                               args.engine );
                }
            }
        } // end of target for loop

    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetAccessMode");

    return;
}


// ------------------------------------------------------------------
//  i2cRegisterOp
// ------------------------------------------------------------------
errlHndl_t i2cRegisterOp ( DeviceFW::OperationType i_opType,
                       TARGETING::Target * i_target,
                       uint64_t * io_data_64,
                       i2c_reg_offset_t i_reg,
                       misc_args_t & i_args )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cRegisterOp()");

    uint64_t op_addr = 0x0;
    uint64_t op_size = 0x0; // in bytes

    do
    {
        // Calculate Register Address and data size based on access type
        if ( i_args.switches.useHostI2C == 1 )
        {
            op_addr = I2C_HOST_MASTER_BASE_ADDR + i_reg +
                        (i_args.engine * 0x20); // engine reg offset
            op_size=8;

            err = DeviceFW::deviceOp( i_opType,
                                      i_target,
                                      io_data_64,
                                      op_size,
                                      DEVICE_SCOM_ADDRESS(op_addr) );

        }

        else // i_args.switches.useFsiI2C == 1
        {
            // FSI addresses are at 1-byte offsets, so need to multiply the
            // i_reg offset by 4 since each I2C register is 4 bytes long.
            op_addr = I2C_FSI_MASTER_BASE_ADDR + ( i_reg * 4 );

            if ( i_reg == I2C_REG_FIFO )
            {
                // Only read/write 1 byte at a time for FIFO register
                op_size = 1;
            }
            else
            {
                op_size = 4;
            }

            // Read or Write, this command should have the data left-justfied
            err = DeviceFW::deviceOp( i_opType,
                                      i_target,
                                      io_data_64,
                                      op_size,
                                      DEVICE_FSI_ADDRESS(op_addr));

        }

        if ( err )
        {
            TRACFCOMP(g_trac_i2c,"i2cRegisterOp %s FAIL!: plid=0X%X, rc=0x%X "
                      "tgt=0x%X, reg=%d, addr=0x%.8X, "
                      "data=0x%.16X",
                      ( i_opType == DeviceFW::READ ) ? "read" : "write",
                      err->plid(),  err->reasonCode(),
                      TARGETING::get_huid(i_target),
                      i_reg, op_addr, (*io_data_64) );
        }

    } while( 0 );

    TRACUCOMP(g_trac_i2c,"i2cRegisterOp(%s): tgt=0x%X, h/f=%d/%d(%d) "
              "i_reg=%d, addr=0x%.8X, data=0x%.16X",
              ( i_opType == DeviceFW::READ ) ? "r" : "w",
              TARGETING::get_huid(i_target),
              i_args.switches.useHostI2C,
              i_args.switches.useFsiI2C, op_size,
              i_reg, op_addr, (*io_data_64) );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cRegisterOp()" );

    return err;
}

/**
 * @brief Return a set of information related to each I2C master on
 *   the given target chip
 */
void getMasterInfo( const TARGETING::Target* i_chip,
                    std::list<MasterInfo_t>& o_info )
{
    TRACDCOMP(g_trac_i2c,"getMasterInfo(%.8X)",TARGETING::get_huid(i_chip));
    for( uint32_t engine = 0;
         engine < I2C_BUS_ATTR_MAX_ENGINE;
         engine++ )
    {
        MasterInfo_t info;
        info.scomAddr = 0x000A0000 + engine*0x20;
        info.engine = engine;
        info.freq = i2cGetNestFreq()*1000*1000; //convert MHz->Hz
        // PIB_CLK = NEST_FREQ /4
        // Local Bus = PIB_CLK / 4
        info.freq = info.freq/16; //convert nest to local bus

        o_info.push_back(info);
    }
}

} // end namespace I2C
