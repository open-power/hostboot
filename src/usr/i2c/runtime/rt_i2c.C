/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/runtime/rt_i2c.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>
#include <runtime/interface.h>
#include <runtime/rt_targeting.H>
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

    // Get the args out of the va_list
    //  Address, Port, Engine, Device Addr.
    // Other args set below
    misc_args_t args;
    args.port = va_arg( i_args, uint64_t );
    args.engine = va_arg( i_args, uint64_t );
    args.devAddr = va_arg( i_args, uint64_t );

    // i2c addresses are 7 bits so shift that right 1 bit
    args.devAddr >>= 1;

    // These are additional parms in the case an offset is passed in
    // via va_list, as well
    args.offset_length = va_arg( i_args, uint64_t);

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
            /*@
            * @errortype
            * @moduleid     I2C_PERFORM_OP
            * @reasoncode   I2C_RUNTIME_INVALID_OFFSET_LENGTH
            * @userdata1    Offset length
            * @userdata2    Op type
            * @devdesc      I2C offset length is invalid
            */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                          I2C_PERFORM_OP,
                                          I2C_RUNTIME_INVALID_OFFSET_LENGTH,
                                          args.offset_length,
                                          i_opType);

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);
        }
    }

    int rc = 0;
    bool l_host_if_enabled = true;
    RT_TARG::rtChipId_t proc_id = 0;

    // Convert target to proc id
    err = RT_TARG::getRtTarget( i_target,
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

    if(i_opType == DeviceFW::READ)
    {
        if(g_hostInterfaces->i2c_read != NULL)
        {
            rc = g_hostInterfaces->i2c_read
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
            TRACFCOMP(g_trac_i2c,ERR_MRK"Hypervisor I2C read interface not linked");
            l_host_if_enabled = false;
        }
    }
    else if (i_opType == DeviceFW::WRITE)
    {
        if(g_hostInterfaces->i2c_write != NULL)
        {
            rc = g_hostInterfaces->i2c_write
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
            TRACFCOMP(g_trac_i2c,ERR_MRK"Hypervisor I2C write interface not linked");
            l_host_if_enabled = false;
        }
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
    }

    if(rc)
    {
        // convert rc to error log
        /*@
         * @errortype
         * @moduleid     I2C_PERFORM_OP
         * @reasoncode   I2C_RUNTIME_ERR
         * @userdata1    Hypervisor return code
         * @userdata2    Op type
         * @devdesc      I2C access error
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                      I2C_PERFORM_OP,
                                      I2C_RUNTIME_ERR,
                                      rc,
                                      i_opType);

        err->addHwCallout(i_target,
                          HWAS::SRCI_PRIORITY_LOW,
                          HWAS::NO_DECONFIG,
                          HWAS::GARD_NULL);

        // Note: no trace buffer available at runtime
    }

    // If there is an error, add parameter info to log
    if ( err != NULL )
    {
        I2C::UdI2CParms( i_opType,
                         i_target,
                         io_buflen,
                         i_accessType,
                         args  )
                       .addToLog(err);
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

} // end namespace I2C
