/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_xscom.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

/** @file bl_xscom.C
 *  @brief Implementation of the XSCOM interfaces for HBBL
 */
#include <bl_xscom.H>
#include <bootloader_data.H>
#include <bootloader.H>
#include <bl_console.H>
#include <stdint.h>

Bootloader::hbblReasonCode XSCOM::xscomPerformOp(const DeviceFW::OperationType i_opType,
                                                  void* const io_buffer,
                                                  size_t& io_buflen,
                                                  const uint64_t i_addr)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;

    XSCOM::XSComP10Address l_xscomAddr(i_addr);

    uint64_t l_mmioAddr = g_blData->blToHbData.xscomBAR + l_xscomAddr;

    if(i_opType == DeviceFW::READ)
    {
        // The in/output buffer needs to have HRMOR attached to it, since it gets
        // passed around as an offset and not an absolute address.
        Bootloader::handleMMIO(l_mmioAddr,
                   reinterpret_cast<uintptr_t>(io_buffer) + getHRMOR(),
                   io_buflen,
                   Bootloader::DBLWORDSIZE,
                   Bootloader::READ);
    }
    else if (i_opType == DeviceFW::WRITE)
    {
        // The in/output buffer needs to have HRMOR attached to it, since it gets
        // passed around as an offset and not an absolute address.
        Bootloader::handleMMIO(reinterpret_cast<uintptr_t>(io_buffer) + getHRMOR(),
                   l_mmioAddr,
                   io_buflen,
                   Bootloader::DBLWORDSIZE,
                   Bootloader::WRITE);
    }
    else
    {
        l_rc = Bootloader::RC_XSCOM_BAD_PARAM;
    }

    // TODO RTC: 243863 Check HMER and perform retry

    return l_rc;
}
