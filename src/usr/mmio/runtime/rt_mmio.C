/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/runtime/rt_mmio.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
// @file src/usr/mmio/runtime/rt_mmio.C
// @brief Runtime mmio operations -- particularly for scom operations

#include "../mmio.H"
#include <scom/runtime/rt_scomif.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <limits.h>
#include <usr/mmio/mmio_reasoncodes.H>

// Trace definition
trace_desc_t* g_trac_mmio = NULL;
TRAC_INIT(&g_trac_mmio, MMIO_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace MMIO
{
// Direct OCMB reads and writes to the device's memory mapped memory.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::MMIO,
                      TARGETING::TYPE_OCMB_CHIP,
                      ocmbMmioPerformOp);

/*******************************************************************************
 *
 * See comments in header file
 *
 */
errlHndl_t ocmbMmioPerformOp(DeviceFW::OperationType i_opType,
                             TARGETING::TargetHandle_t i_ocmbTarget,
                             void*   io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args)
{
    errlHndl_t l_err         = nullptr;
    uint64_t   l_offset      = va_arg(i_args, uint64_t);

    TRACUCOMP(g_trac_mmio, ENTER_MRK"runtime ocmbMmioPerformOp");
    TRACUCOMP(g_trac_mmio, INFO_MRK"op=%d, target=0x%.8X",
              i_opType, TARGETING::get_huid(i_ocmbTarget));
    TRACUCOMP(g_trac_mmio, INFO_MRK"buffer=%p, length=%d, accessType=%ld",
              io_buffer, io_buflen, i_accessType);
    TRACUCOMP(g_trac_mmio, INFO_MRK"offset=0x%lX", l_offset);

    // Verify offset is within scom mmio range
    if ( (l_offset >= (4 * GIGABYTE)) && (l_offset < (6 * GIGABYTE)) )
    {
        // add the base physical address to create a complete system-wide
        //  address
        uint64_t l_fullAddr = i_ocmbTarget->getAttr<TARGETING::ATTR_MMIO_PHYS_ADDR>();
        l_fullAddr += l_offset;

        // Set the ignore HRMOR bit so that PHYP gets the right address
        l_fullAddr |= IGNORE_HRMOR;

        // verify buffer length is supported
        if ((io_buflen != 4) && (io_buflen != 8))
        {
            // Only 4 and 8 byte scom sizes supported
            /*@
             * @errortype
             * @moduleid         MMIO::RT_OCMB_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INCORRECT_BUFFER_LENGTH
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset
             * @userdata2[0:31]  Operation Type
             * @userdata2[32:63] Buffer Length
             * @devdesc          Unsupported buffer length for SCOM offset.
             *                   Only lengths 4 and 8 supported.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::RT_OCMB_MMIO_PERFORM_OP,
                                    MMIO::RC_INCORRECT_BUFFER_LENGTH,
                                    TWO_UINT32_TO_UINT64(
                                      TARGETING::get_huid(i_ocmbTarget),
                                      l_offset),
                                    TWO_UINT32_TO_UINT64(i_opType, io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        }
        else
        {
            // hypervisor expects an 8-byte buffer
            uint8_t l_scombuf[8] = {0};
            if (i_opType == DeviceFW::WRITE)
            {
                if (io_buflen == 4)
                {
                    // data is right-justified
                    memcpy(l_scombuf+4, io_buffer, 4);
                }
                else // io_buflen == 8
                {
                    memcpy(l_scombuf, io_buffer, 8);
                }
            }

            // send message to hypervisor level to do the mmio operation
            l_err = SCOM::sendScomToHyp(i_opType, i_ocmbTarget,
                                        l_fullAddr, l_scombuf );
            if( io_buflen == 4 )
            {
                 // data is right-justified
                 memcpy( io_buffer, l_scombuf+4, 4 );
            }
            else // io_buflen == 8
            {
                 memcpy( io_buffer, l_scombuf, 8 );
            }
        }
    }
    else
    {
        // Only Scom range is supported for MMIO runtime context
        /*@
         * @errortype
         * @moduleid         MMIO::RT_OCMB_MMIO_PERFORM_OP
         * @reasoncode       MMIO::RC_INVALID_OFFSET
         * @userdata1[0:31]  Target huid
         * @userdata1[32:63] Data Offset
         * @userdata2[0:31]  Operation Type
         * @userdata2[32:63] Buffer Length
         * @devdesc          Invalid offset, requested
         *                   address was out of range for a MMIO operation.
         * @custdesc         Unexpected memory subsystem firmware error.
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                MMIO::RT_OCMB_MMIO_PERFORM_OP,
                                MMIO::RC_INVALID_OFFSET,
                                TWO_UINT32_TO_UINT64(
                                  TARGETING::get_huid(i_ocmbTarget),
                                  l_offset),
                                TWO_UINT32_TO_UINT64(i_opType, io_buflen),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

    return l_err;
}

};  // end namespace MMIO
