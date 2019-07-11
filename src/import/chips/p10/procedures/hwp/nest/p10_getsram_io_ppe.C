/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getsram_io_ppe.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_getsram_io_ppe.C
/// @brief Read data from IO PPE SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, SBE, Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_getsram_io_ppe.H>
#include <p10_scom_pauc.H>
#include <p10_getputsram_utils.H>

//------------------------------------------------------------------------------
// scomt name spaces
//------------------------------------------------------------------------------
using namespace scomt;
using namespace scomt::pauc;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode p10_getsram_io_ppe(
    const fapi2::Target < fapi2::TARGET_TYPE_PAUC >& i_target,
    const uint64_t i_offset,
    const uint32_t i_bytes,
    uint8_t* o_data)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_SRAM_ctrl_reg(0);
    uint8_t* l_dataPtr = o_data;
    fapi2::buffer<uint64_t> l_data(0);

    FAPI_DBG("p10_getsram_io_ppe: Offset %p, i_bytes %u.", i_offset, i_bytes);

    // Set PPE SRAM read offset
    FAPI_DBG("p10_getsram_io_ppe: Setup write offset in PPE_WRAP_ARB_CSAR reg.");
    FAPI_TRY(PREP_PHY_PPE_WRAP_ARB_CSAR(i_target),
             "p10_getsram_io_ppe: PREP_PHY_PPE_WRAP_ARB_CSAR returns an error.");
    FAPI_TRY(PUT_PHY_PPE_WRAP_ARB_CSAR(i_target, i_offset),
             "p10_getsram_io_ppe: PUT_PHY_PPE_WRAP_ARB_CSAR returns an error.");

    // Turn on Auto Increment if read more than 8 bytes
    if (i_bytes > 8)
    {
        FAPI_TRY(enableDisableIoPpeAutoInc(i_target, true),
                 "p10_getsram_io_ppe: enableDisableIoPpeAutoInc returns an error.");
    }

    // Read data
    FAPI_DBG("p10_getsram_io_ppe: Write data to PHY_PPE_WRAP_ARB_CSDR reg.");
    FAPI_TRY(PREP_PHY_PPE_WRAP_ARB_CSDR(i_target));

    while (l_dataPtr < (o_data + i_bytes))
    {
        // Read 8 bytes at a time
        FAPI_TRY(GET_PHY_PPE_WRAP_ARB_CSDR(i_target, l_data),
                 "p10_getsram_io_ppe: GET_PHY_PPE_WRAP_ARB_CSDR returns an error.");

        // Store data into output buffer
        for (uint8_t ii = 0; ii < 8; ii++)
        {
            *l_dataPtr++ = (l_data >> (56 - (ii * 8))) & 0xFFull;

            // Exit if size has reached
            if (l_dataPtr >= o_data + i_bytes)
            {
                break;
            }
        }
    }

    // Done, disable Auto Increment mode
    if (i_bytes > 8)
    {
        FAPI_TRY(enableDisableIoPpeAutoInc(i_target, false),
                 "p10_getsram_io_ppe: enableDisableIoPpeAutoInc returns an error.");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}
