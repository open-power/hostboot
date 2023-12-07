/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_flashCheck.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
 * @file sbe_flashCheck.C
 * @brief This file contains the implementations of the
 *        SPPE SPI flash check messaging
 */

#include "sbe_fifodd.H"
#include <sbeio/sbeioif.H>

using namespace TARGETING;

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
            TRACFCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
            TRACDCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
            TRACFBIN(g_trac_sbeio, printf_string,##args)


namespace SBEIO
{

errlHndl_t sendSpiFlashCheckRequest(Target* i_ocmb, uint8_t i_scope, uint8_t i_side, uint8_t i_deviceId)
{
    errlHndl_t l_errl = nullptr;

    // SPPE will send back a scrub status entry per side requested per device, so
    // if we request to scrub the primary and backup sides on two devices, SPPE
    // will send back 4 scrub status entries. The side and deivce ID bits are OR'ed
    // together, so we can multiply the bit counts to find the total number of
    // scrub status entries we need to expect from SPPE.
    size_t l_numScrubStatusEntries = __builtin_popcount(i_side) * __builtin_popcount(i_deviceId);

    // The SSPE reponse contains the scrub status entries followed by the standard
    // FIFO response.
    std::vector<uint8_t>l_response;
    l_response.resize(l_numScrubStatusEntries * sizeof(SbeFifo::spiScrubStatusEntry) +
                      sizeof(SbeFifo::fifoStandardResponse));

    SbeFifo::fifoScrubMemDeviceRequest l_request;
    l_request.scope = i_scope;
    l_request.side = i_side;
    l_request.deviceId = i_deviceId;

    l_errl = SbeFifo::getTheInstance().performFifoChipOp(i_ocmb,
                                                         reinterpret_cast<uint32_t*>(&l_request),
                                                         reinterpret_cast<uint32_t*>(l_response.data()),
                                                         l_response.size());
    if(l_errl)
    {
        SBE_TRACF("sendSpiFlashCheckRequest: chip op failed for OCMB 0x%x", get_huid(i_ocmb));
        goto ERROR_EXIT;
    }

ERROR_EXIT:
    return l_errl;
}

} // namespace SBEIO
