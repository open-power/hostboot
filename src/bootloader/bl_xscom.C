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
#include <xscom/piberror_common.H>

#define XSCOM_RETRY_LIMIT 50000

/**
 * @brief Read the HMER status register
 *
 * @return The 64-bit value of the HMER register
 */
static uint64_t readHMER()
{
    register uint64_t l_hmerVal = 0;

    // 336 is the HMER reg
    asm volatile("mfspr %0, 336" : "=r" (l_hmerVal));

    return l_hmerVal;
}

/**
 * @brief Write a given value to the HMER register
 *
 * @param[in] i_val the 64-bit value to write to HMER
 */
static void writeHMER(const uint64_t i_val)
{
    register uint64_t l_targetGPR = i_val;

    // 336 is the HMER reg
    asm volatile("mtspr 336, %0"
                 :: "r" (l_targetGPR));
}

/**
 * @brief Reset the HMER reg's XSCOM status
 */
static void resetHMER()
{
    XSCOM::HMER l_hmer(-1);
    l_hmer.mXSComDone = 0;
    l_hmer.mXSComFail = 0;
    l_hmer.mXSComStatus = 0;
    writeHMER(l_hmer);
}

/**
 * @brief Continuously read the HMER status reg until either the XSCOM
 *        operation completes or there is a failure as indicated bu the
 *        XSCOM status bits
 *
 * @return The 64-bit value of the HMER register
 */
static uint64_t waitForHMERStatus()
{
    XSCOM::HMER l_hmer;

    do
    {
        // Read HMER until XSCOM is done or there is a failure
        l_hmer = readHMER();
    } while(!l_hmer.mXSComFail && !l_hmer.mXSComDone);

    return l_hmer;
}

Bootloader::hbblReasonCode XSCOM::xscomPerformOp(const DeviceFW::OperationType i_opType,
                                                       void* const io_buffer,
                                                       size_t& io_buflen,
                                                       const uint64_t i_addr)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;

    XSCOM::XSComP10Address l_xscomAddr(i_addr);

    uint64_t l_mmioAddr = g_blData->blToHbData.xscomBAR + l_xscomAddr;
    XSCOM::HMER l_hmer;

    uint32_t l_retryCounter = 0;

    do
    {
        resetHMER();

        if(l_retryCounter > XSCOM_RETRY_LIMIT)
        {
            bl_console::putString("XSCOM: Operation timed out; address: 0x");
            uint64_t l_addr = i_addr;
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_addr), sizeof(l_addr));
            bl_console::putString("\r\n");
            l_rc = Bootloader::RC_XSCOM_OP_TIMEOUT;
            break;
        }

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
            break;
        }

        l_hmer = waitForHMERStatus();

        ++l_retryCounter;
    } while(l_hmer.mXSComStatus == PIB::PIB_RESOURCE_OCCUPIED);

    if(l_hmer.mXSComFail)
    {
        l_rc = Bootloader::RC_XSCOM_OP_FAILED;
    }

    return l_rc;
}

