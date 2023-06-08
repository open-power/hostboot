/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_putsram_io_ppe.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///
/// @file ody_putsram_io_ppe.C
/// @brief Write data to IO PPE SRAM
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: HB, Cronus, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_putsram_io_ppe.H>
#include <ody_scom_omi_ioo.H>

//------------------------------------------------------------------------------
// scomt name spaces
//------------------------------------------------------------------------------
// Scomt definitions
SCOMT_OMI_USE_PHY_PPE_WRAP0_ARB_CSCR
SCOMT_OMI_USE_PHY_PPE_WRAP0_ARB_CSAR
SCOMT_OMI_USE_PHY_PPE_WRAP0_ARB_CSDR

using namespace scomt::omi;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode ody_putsram_io_ppe(
    const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP >& i_target,
    const uint64_t i_offset,
    const uint32_t i_bytes,
    const uint8_t* i_data)
{
    FAPI_DBG("Start");
    PHY_PPE_WRAP0_ARB_CSCR_t  WRAP0_ARB_CSCR;
    PHY_PPE_WRAP0_ARB_CSAR_t  WRAP0_ARB_CSAR;
    PHY_PPE_WRAP0_ARB_CSDR_t  WRAP0_ARB_CSDR;

    const uint8_t* l_dataPtr = i_data;
    uint64_t l_data64 = 0;

    FAPI_DBG("ody_putsram_io_ppe: i_offset [0x%.8X%.8X], i_bytes %u.",
             ((i_offset >> 32) & 0xFFFFFFFF), (i_offset & 0xFFFFFFFF), i_bytes);

    // Enable auto increment
    if (i_bytes > 8)
    {
        FAPI_DBG("ody_putsram_io_ppe: enable auto-increment.");
        WRAP0_ARB_CSCR.set_SRAM_ACCESS_MODE(1);
        FAPI_TRY(WRAP0_ARB_CSCR.putScom(i_target),
                 "Error putscom to WRAP0_ARB_CSCR (1).");
    }

    // Set the address pointer to the input offset
    WRAP0_ARB_CSAR = i_offset;
    FAPI_TRY(WRAP0_ARB_CSAR.putScom(i_target),
             "Error putscom to WRAP0_ARB_CSAR (SRAM address).");

    // Write data
    FAPI_DBG("Write data to SRAM...");

    while (l_dataPtr < (i_data + i_bytes))
    {
        l_data64 = 0;

        // Load 8 bytes into 64-bit word
        for (uint8_t ii = 0; ii < 8; ii++)
        {
            l_data64 |= ( static_cast<uint64_t>(*l_dataPtr++) << (56 - (8 * ii)) );

            // Exit if size has reached. Remaining data in double words are zeroes
            if (l_dataPtr >= i_data + i_bytes)
            {
                break;
            }
        }

        WRAP0_ARB_CSDR.set_CSDR_SRAM_DATA(l_data64);
        FAPI_TRY(WRAP0_ARB_CSDR.putScom(i_target),
                 "Error putscom to WRAP0_ARB_CSDR.");
    }

    // Disable auto-increment
    if (i_bytes > 8)
    {
        WRAP0_ARB_CSCR.set_SRAM_ACCESS_MODE(0);
        FAPI_TRY(WRAP0_ARB_CSCR.putScom(i_target),
                 "Error putscom to WRAP0_ARB_CSCR (0).");
    }

    FAPI_DBG("putsram completes.");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
