/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/spidd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
 * @file spidd.C
 *
 * @brief Implementation of the Serial Peripheral Interface (SPI) device driver
 *
 */

// -----------------------------------------------------------------------------
//      Includes
// -----------------------------------------------------------------------------
#include "spidd.H"
#include <trace/interface.H>

#include <targeting/common/utilFilter.H>

#include <hbotcompid.H>
#include <initservice/taskargs.H>

// -----------------------------------------------------------------------------
//      Trace definitions
// -----------------------------------------------------------------------------
trace_desc_t* g_trac_spi = nullptr;
TRAC_INIT(&g_trac_spi, SPI_COMP_NAME, KILOBYTE);


#define TRACUCOMP(args...)    TRACFCOMP(args)
//#define TRACUCOMP

namespace SPI
{

/**
 * _start() task entry procedure using the macro found in taskargs.H
 */
TASK_ENTRY_MACRO( spiInit );

void spiInit(errlHndl_t & io_rtaskRetErrl)
{

}

// Register the generic SPI perform Op with routing code for Procs.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SPI,
                      TARGETING::TYPE_PROC,
                      spiPerformOp);

errlHndl_t spiPerformOp(DeviceFW::OperationType i_opType,
                        TARGETING::Target*      i_target,
                        void*                   io_buffer,
                        size_t&                 io_buflen,
                        int64_t                 i_accessType,
                        va_list                 i_args)
{
    TRACUCOMP(g_trac_spi, ENTER_MRK"spiPerformOp() opType(%s), "
              "i_target(0x%X), io_buffer(%p), io_buflen(%d),  "
              "i_accessType(%d)",
              i_opType == DeviceFW::READ ? "READ" : "WRITE",
              TARGETING::get_huid(i_target),
              io_buffer,
              io_buflen,
              i_accessType);

    errlHndl_t errl = nullptr;

    // Get the input args from the va_list
    // engine, read/write offset, skipecc
    spi_misc_args_t args;

    // SPI master engine to use for this operation
    args.engine = va_arg(i_args, uint64_t);
    // The offset to start the read or write from
    args.offset = va_arg(i_args, uint64_t);

    return errl;
}

}; // end namespace SPI
