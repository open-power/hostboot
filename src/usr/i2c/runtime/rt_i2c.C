/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/runtime/rt_i2c.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file rt_i2c.C
 *
 * @brief Runtime implementation of the i2c device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/hberrltypes.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>
#include <runtime/interface.h>
#include <targeting/runtime/rt_targeting.H>
#include <i2c/i2c.H>
#include <i2c/i2cif.H>
#include <sbeio/sbe_retry_handler.H>
#include "../errlud_i2c.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_i2c = NULL;
TRAC_INIT( & g_trac_i2c, I2C_COMP_NAME, KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


namespace I2C
{

const uint64_t SCAC_CONFIG_REG = 0x00000000020115CEULL;
const uint64_t SCAC_CONFIG_SET = 0x00000000020115CFULL;
const uint64_t SCAC_CONFIG_CLR = 0x00000000020115D0ULL;
const uint64_t SCAC_ENABLE_MSK = 0x8000000000000000ULL;

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

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cPerformOp()" );

    // Get the args out of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;

    // Read in the sub-operation
    const auto subop =
        static_cast<DeviceFW::I2C_SUBOP>(va_arg(i_args,uint64_t));

    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // These are additional parms in the case an offset is passed in
    // via va_list, as well
    args.offset_length = va_arg( i_args, uint64_t);

    TRACFCOMP(g_trac_i2c,
              "rt_i2c: i2cPerformOp for %.8X"
              TRACE_I2C_ADDR_FMT,
              TARGETING::get_huid(i_target),
              TRACE_I2C_ADDR_ARGS(args));

    uint32_t offset = 0;
    if ( args.offset_length != 0 )
    {
        args.offset_buffer = reinterpret_cast<uint8_t*>
                                             (va_arg(i_args, uint64_t));
        if ( args.offset_length == 1 )
        {
            offset = *(args.offset_buffer);
        }
        else if ( args.offset_length == 2 )
        {
            offset = *(reinterpret_cast<uint16_t*>(args.offset_buffer));
        }
        else if ( args.offset_length == 4 )
        {
            offset = *(reinterpret_cast<uint32_t*>(args.offset_buffer));
        }
        else
        {
            TRACFCOMP(g_trac_i2c, ERR_MRK"Invalid Offset length: 0x%.8X."
                "Previous parameters: i2c subop 0x%.8X, "
                "port 0x%.8X, engine 0x%.8X, deviceAddr 0x%.8X",
                args.offset_length, subop,
                args.port, args.engine, args.devAddr);
            /*@
            * @errortype
            * @moduleid     RT_I2C_PERFORM_OP
            * @reasoncode   I2C_RUNTIME_INVALID_OFFSET_LENGTH
            * @userdata1    Offset length
            * @userdata2[0:31]  Operation Type
            * @userdata2[32:64] Target
            * @devdesc      I2C offset length is invalid
            */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                          RT_I2C_PERFORM_OP,
                                          I2C_RUNTIME_INVALID_OFFSET_LENGTH,
                                          args.offset_length,
                                          TWO_UINT32_TO_UINT64(i_opType,
                                                TARGETING::get_huid(i_target)));

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);
            return err;
        }
    }

    int host_rc = 0;
    bool l_host_if_enabled = true;
    TARGETING::rtChipId_t proc_id = 0;

    // Check for Master Sentinel chip
    if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
    {
        TRACFCOMP( g_trac_i2c,
                   ERR_MRK"i2cPerformOp() - Cannot target Master Sentinel "
                   "Chip for an I2C Operation!" );

        /*@
         * @errortype
         * @reasoncode     I2C_MASTER_SENTINEL_TARGET
         * @severity       ERRORLOG_SEV_UNRECOVERABLE
         * @moduleid       RT_I2C_PERFORM_OP
         * @userdata1      Operation Type requested
         * @userdata2      <UNUSED>
         * @devdesc        Master Sentinel chip was used as a target for an
         *                 I2C operation.  This is not permitted.
         * @custdesc       Internal firmware error
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       RT_I2C_PERFORM_OP,
                                       I2C_MASTER_SENTINEL_TARGET,
                                       i_opType,
                                       0x0,
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        err->collectTrace( I2C_COMP_NAME, 256);

        return err;
    }

    // Convert target to proc id
    err = TARGETING::getRtTarget( i_target,
                                  proc_id);
    if(err)
    {
        return err;
    }

    // Combine proc/engine/port
    uint64_t proc_engine_port = 0;
    proc_engine_port |= proc_id << HBRT_I2C_MASTER_CHIP_SHIFT;
    proc_engine_port |= (uint64_t)(args.engine) << HBRT_I2C_MASTER_ENGINE_SHIFT;
    proc_engine_port |= (uint64_t)(args.port) << HBRT_I2C_MASTER_PORT_SHIFT;

    // PHYP/OPAL expect the 7-bit device address to be right-justified (we
    // left-justify it in Hostboot)
    args.devAddr >>= 1;

    // Potentially loop if someone else (SBE) is holding the atomic lock
    constexpr size_t MAX_I2C_LOCK_RETRIES = 10;
    for( size_t l_retries = 0; l_retries <= MAX_I2C_LOCK_RETRIES; l_retries++ )
    {
        // Send I2C op to host interface
        if(i_opType == DeviceFW::READ)
        {
            if(g_hostInterfaces->i2c_read != NULL)
            {
                host_rc = g_hostInterfaces->i2c_read
                  (
                   proc_engine_port,   // Master Chip/Engine/Port
                   args.devAddr,       // Dev Addr
                   args.offset_length, // Offset size
                   offset,             // Offset
                   io_buflen,          // Buffer length
                   io_buffer           // Buffer
                   );
            }
            else
            {
                TRACFCOMP(g_trac_i2c,
                          ERR_MRK"Hypervisor I2C read interface not linked");
                l_host_if_enabled = false;
            }
        }
        else if (i_opType == DeviceFW::WRITE)
        {
            if(g_hostInterfaces->i2c_write != NULL)
            {
                host_rc = g_hostInterfaces->i2c_write
                  (
                   proc_engine_port,   // Master Chip/Engine/Port
                   args.devAddr,       // Dev Addr
                   args.offset_length, // Offset size
                   offset,             // Offset
                   io_buflen,          // Buffer length
                   io_buffer           // Buffer
                   );
            }
            else
            {
                TRACFCOMP(g_trac_i2c,
                          ERR_MRK"Hypervisor I2C write interface not linked");
                l_host_if_enabled = false;
            }
        }
        else
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"i2cPerformOp() - "
                       "Unsupported Op/Offset-Type Combination=%d/%d",
                       i_opType, args.offset_length );
            uint64_t userdata2 = args.offset_length;
            userdata2 = (userdata2 << 16) | args.port;
            userdata2 = (userdata2 << 16) | args.engine;
            userdata2 = (userdata2 << 16) | args.devAddr;

            /*@
             * @errortype
             * @reasoncode       I2C_INVALID_OP_TYPE
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @moduleid         RT_I2C_PERFORM_OP
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
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            err->collectTrace( I2C_COMP_NAME, 256);

            // No Operation performed, so can break and skip the section
            // that handles operation errors
            break;
        }

        if(!l_host_if_enabled)
        {
            /*@
             * @errortype
             * @moduleid     I2C_PERFORM_OP
             * @reasoncode   I2C_RUNTIME_INTERFACE_ERR
             * @userdata1    0
             * @userdata2    Op type
             * @devdesc      I2C read/write interface not linked.
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                          I2C_PERFORM_OP,
                                          I2C_RUNTIME_INTERFACE_ERR,
                                          0,
                                          i_opType);

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);
            break;
        }

        // Jump out of the retry loop if there is no error
        if( 0 == host_rc )
        {
            break;
        }
        // Check if we need to handle a lock issue
        else if( HBRT_RC_I2C_LOCKED == host_rc )
        {
            TRACFCOMP(g_trac_i2c,
                      "I2C Engine is locked for %.8X (retry %d)"
                      TRACE_I2C_ADDR_FMT,
                      TARGETING::get_huid(i_target),
                      l_retries,
                      TRACE_I2C_ADDR_ARGS(args));

            // If we've already tried a few times, make one more attempt
            //  by resetting the SBE.  Note that the lock is taken
            //  back as part of reset logic.
            if( l_retries == MAX_I2C_LOCK_RETRIES-1 )
            {
                TRACFCOMP(g_trac_i2c,
                          ERR_MRK"Ran out of retries, giving up");

                // reset the SBE
                // Get the SBE Retry Handler
                SBEIO::SbeRetryHandler l_SBEobj = SBEIO::SbeRetryHandler(
                    i_target,
                    SBEIO::SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SBEIO::SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    SBEIO::EMPTY_PLID,
                    SBEIO::NOT_INITIAL_POWERON);

                //Attempt to recover the SBE
                l_SBEobj.main_sbe_handler();
                if (l_SBEobj.isSbeAtRuntime())
                {
                    TRACFCOMP(g_trac_i2c, "SBE Restarted successfully");
                }
                else
                {
                    TRACFCOMP(g_trac_i2c, "SBE restart failed");
                }
                // We don't actually care if the SBE recovered in
                //  this logic

                // One more try
                continue;
            }

            // Check if the SBE is dead
            //E0005 = Bit 0 indicates whether SBE is running or halted. 0 - running, 1 - halted.
            // Read the PPE External Interface DBGPRO reg
            uint64_t l_sbereg = 0;
            size_t l_scomsize = sizeof(l_sbereg);
            err = DeviceFW::deviceOp( DeviceFW::READ,
                                      i_target,
                                      &l_sbereg,
                                      l_scomsize,
                                      DEVICE_SCOM_ADDRESS(0x000E0005) );
            if ( err )
            {
                // the scom error is somewhat secondary to the i2c op
                //  we are trying to do, so just commit it as info
                //  and fall out to fail the i2c operation itself
                TRACFCOMP(g_trac_i2c,
                          ERR_MRK"Could not do scom to read SBE state");
                err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                break;
            }

            if( l_sbereg & 0x800000000000 )
            {
                TRACFCOMP(g_trac_i2c,
                          INFO_MRK"SBE is halted, taking the lock back");
                err = forceClearAtomicLock(i_target,
                             i2cEngineToEngineSelect(args.engine));
                if( err )
                {
                    TRACFCOMP(g_trac_i2c,
                              ERR_MRK"Error trying to force the atomic lock");
                    break;
                }
            }
        }
        // Unrecognized error
        else if(host_rc)
        {
            // convert rc to error log
            /*@
             * @errortype
             * @moduleid     I2C_PERFORM_OP
             * @reasoncode   I2C_RUNTIME_ERR
             * @userdata1    Hypervisor return code
             * @userdata2    Op type
             * @devdesc      I2C access error
             * @custdesc     Hardware access error
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                          I2C_PERFORM_OP,
                                          I2C_RUNTIME_ERR,
                                          host_rc,
                                          i_opType);

            err->addHwCallout(i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::NO_DECONFIG,
                              HWAS::GARD_NULL);
            break;
        }

    } //i2c retry loop

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        I2C::UdI2CParms( i_opType,
                         i_target,
                         io_buflen,
                         i_accessType,
                         args  )
                       .addToLog(err);
        err->collectTrace(I2C_COMP_NAME);
    }

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end i2cPerformOp

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
//  i2cDisableSensorCache
// ------------------------------------------------------------------
errlHndl_t i2cDisableSensorCache ( TARGETING::Target * i_target,
                                   bool & o_disabled )
{
    errlHndl_t err = NULL;

    o_disabled = false;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cDisableSensorCache()" );

    do
    {
        // There must be a 30ms window between the last time the cache
        //  was enabled and the next time it is disabled.  Since we
        //  have no way to easily track the last enablement, we will
        //  just take the hit inside every disable call.
        TRACDCOMP( g_trac_i2c, "Delaying 30ms before disable" );
        nanosleep(0,30 * NS_PER_MSEC);

        uint64_t scacData = 0x0;
        size_t dataSize = sizeof(scacData);

        // Read the scac config reg to get the enabled/disabled bit
        err = DeviceFW::deviceOp( DeviceFW::READ,
                                  i_target,
                                  &scacData,
                                  dataSize,
                                  DEVICE_SCOM_ADDRESS(SCAC_CONFIG_REG) );
        if ( err )
        {
            break;
        }

        // Disable SCAC if it's enabled
        if( scacData & SCAC_ENABLE_MSK )
        {
            o_disabled = true;  // Enable SCAC again after op completes
            scacData = SCAC_ENABLE_MSK;

            // Write the scac clear reg to disable the sensor cache
            err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                      i_target,
                                      &scacData,
                                      dataSize,
                                      DEVICE_SCOM_ADDRESS(SCAC_CONFIG_CLR) );
            if ( err )
            {
                break;
            }

            // Wait 30 msec for outstanding sensor cache
            // operations to complete
            nanosleep(0,30 * NS_PER_MSEC);
        }
    } while( 0 );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cDisableSensorCache()" );

    return err;
} // end i2cDisableSensorCache

// ------------------------------------------------------------------
//  i2cEnableSensorCache
// ------------------------------------------------------------------
errlHndl_t i2cEnableSensorCache ( TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_i2c,
               ENTER_MRK"i2cEnableSensorCache()" );

    // There must be a 2ms window where the cache is disabled to avoid
    //  some thrashing in the Centaur logic.
    TRACDCOMP( g_trac_i2c, "Delaying 2ms before enable" );
    nanosleep(0,2 * NS_PER_MSEC);

    uint64_t scacData = SCAC_ENABLE_MSK;
    size_t dataSize = sizeof(scacData);

    // Write the scac set reg to enable the sensor cache
    err = DeviceFW::deviceOp( DeviceFW::WRITE,
                              i_target,
                              &scacData,
                              dataSize,
                              DEVICE_SCOM_ADDRESS(SCAC_CONFIG_SET) );

    TRACDCOMP( g_trac_i2c,
               EXIT_MRK"i2cEnableSensorCache()" );

    return err;
} // end i2cEnableSensorCache

} // end namespace I2C
