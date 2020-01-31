/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_sram_access_utils.C $ */
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
///
/// @file  p10_pm_sram_access_utils.C
/// @brief SRAM access utility functions for QME and OCC.
///
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Consumed by     : HS:CRO:SBE
///

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p10_pm_sram_access_utils.H>

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------
/// See doxygen in header file
void loadDataToBuffer(const bool i_useByteBuf,
                      const uint64_t i_data,
                      uint64_t* o_dataPtr)
{
    if (i_useByteBuf)
    {
        uint8_t* l_dataPtr8 = reinterpret_cast<uint8_t*>(o_dataPtr);

        for (uint8_t ii = 0; ii < 8; ii++)
        {
            *l_dataPtr8++ = (i_data >> (56 - (ii * 8))) & 0xFFull;
        }
    }
    else
    {
        *o_dataPtr = i_data;
    }

    return;
}

/// See doxygen in header file
void getDataFromBuffer(const bool i_useByteBuf,
                       uint64_t* i_dataPtr,
                       uint64_t& o_data)
{
    if (i_useByteBuf)
    {
        uint8_t* l_dataPtr8 = reinterpret_cast<uint8_t*>(i_dataPtr);
        o_data = 0;

        for (uint8_t ii = 0; ii < 8; ii++)
        {
            o_data |= (static_cast<uint64_t>(*l_dataPtr8++) << (56 - (8 * ii)) );
        }
    }
    else
    {
        o_data = *i_dataPtr;
    }

    return;
}
