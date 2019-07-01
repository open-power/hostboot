/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9a_addr_ext.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9a_addr_ext.C
/// @brief Handle address extension mask for Axone
///

// *HWP HWP Owner: Ben Gass bgass@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9a_addr_ext.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------

fapi2::ReturnCode p9a_get_ext_mask(uint64_t& o_ext_mask)
{
    FAPI_DBG("Start");
    uint8_t l_addr_extension_group_id = 0;
    uint8_t l_addr_extension_chip_id = 0;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID,
                           FAPI_SYSTEM,
                           l_addr_extension_group_id),
             "Error from FAPI_ATTR_GET (ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID,
                           FAPI_SYSTEM,
                           l_addr_extension_chip_id),
             "Error from FAPI_ATTR_GET (ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID");

    o_ext_mask = ((l_addr_extension_group_id & 0xF) << 4) | (l_addr_extension_chip_id & 0xF);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}



/*
 * As documented (TYPO in BAR Bits)
 * They should be naturally ordered.
 * BAR Bits   6  8  9  7  10 11 12 13
 *      0x00  15 16 17 18 21 20 19 14
 *      0x04  15 16 17 18 21 20 14 19
 *      0x06  15 16 17 18 21 14 20 19
 *      0x07  15 16 17 18 14 21 20 19
 *      0x80  15 16 17 18 21 20 19 14
 *      0x84  15 16 17 18 21 20 14 19
 *      0x86  15 16 17 18 21 14 20 19
 *      0x87  15 16 17 18 14 21 20 19
 *      0xC0  15 17 18 21 20 19 14 16
 *      0xC4  15 17 18 21 20 14 19 16
 *      0xC6  15 17 18 21 14 20 19 16
 *      0xC7  15 17 18 14 21 20 19 16
 *      0xE0  15 18 21 20 19 14 17 16
 *      0xE4  15 18 21 20 14 19 17 16
 *      0xE6  15 18 21 14 20 19 17 16
 *      0xE7  15 18 14 21 20 19 17 16
 *      0xF0  15 21 20 19 14 18 17 16
 *      0xF4  15 21 20 14 19 18 17 16
 *      0xF6  15 21 14 20 19 18 17 16
 *      0xF7  15 14 21 20 19 18 17 16
 *
 *
 */
fapi2::ReturnCode extendBarAddress(const uint64_t& i_ext_mask, const fapi2::buffer<uint64_t>& i_bar_addr,
                                   fapi2::buffer<uint64_t>& o_bar)
{
    static const uint64_t BAR_START_BIT = 8;
    static const uint64_t BAR_MASK_STATIC_BITS = 0xFC03FFFE00000000ull; //31 bit bar, bits 6:13 reordered
    static const uint64_t REORDER_START_BIT = 6; // reordering of bar starts at bit 6
    static const int REORDER_END_BIT = 13; // reordering of bar stops at bit 13
    static const int NUM_EXT_MASKS = 20; // 20 different extension masks are supported
    static const uint64_t EXT_MASK_REORDER[][9] =   // Workbook table 7
    {
        // B     6   7   8   9  10  11  12  13
        { 0x00, 15, 16, 17, 18, 21, 20, 19, 14  },
        { 0x04, 15, 16, 17, 18, 21, 20, 14, 19  },
        { 0x06, 15, 16, 17, 18, 21, 14, 20, 19  },
        { 0x07, 15, 16, 17, 18, 14, 21, 20, 19  },
        { 0x80, 15, 16, 17, 18, 21, 20, 19, 14  },
        { 0x84, 15, 16, 17, 18, 21, 20, 14, 19  },
        { 0x86, 15, 16, 17, 18, 21, 14, 20, 19  },
        { 0x87, 15, 16, 17, 18, 14, 21, 20, 19  },
        { 0xC0, 15, 17, 18, 21, 20, 19, 14, 16  },
        { 0xC4, 15, 17, 18, 21, 20, 14, 19, 16  },
        { 0xC6, 15, 17, 18, 21, 14, 20, 19, 16  },
        { 0xC7, 15, 17, 18, 14, 21, 20, 19, 16  },
        { 0xE0, 15, 18, 21, 20, 19, 14, 17, 16  },
        { 0xE4, 15, 18, 21, 20, 14, 19, 17, 16  },
        { 0xE6, 15, 18, 21, 14, 20, 19, 17, 16  },
        { 0xE7, 15, 18, 14, 21, 20, 19, 17, 16  },
        { 0xF0, 15, 21, 20, 19, 14, 18, 17, 16  },
        { 0xF4, 15, 21, 20, 14, 19, 18, 17, 16  },
        { 0xF6, 15, 21, 14, 20, 19, 18, 17, 16  },
        { 0xF7, 15, 14, 21, 20, 19, 18, 17, 16  }
    };

    uint64_t l_bar = i_bar_addr;
    l_bar = i_bar_addr << BAR_START_BIT;
    l_bar = l_bar & BAR_MASK_STATIC_BITS;
    o_bar = l_bar;
    FAPI_DBG("i_bar_addr: %llx  o_bar: %llx", i_bar_addr, o_bar);

    for (auto l_i = 0; l_i < NUM_EXT_MASKS; l_i++)
    {
        if (EXT_MASK_REORDER[l_i][0] == i_ext_mask)
        {
            int l_ro_idx = 1;

            for (auto l_i2 = REORDER_START_BIT; l_i2 <= REORDER_END_BIT; l_i2++)
            {
                if (i_bar_addr.getBit(EXT_MASK_REORDER[l_i][l_ro_idx]))
                {
                    o_bar.setBit(l_i2);
                }

                l_ro_idx++;
            }

            goto fapi_try_exit;
        }
    }

    FAPI_DBG("o_bar: %llx", o_bar);
    FAPI_ASSERT(false,
                fapi2::PROC_OMI_SETUP_BARS_INVALID_ADDR_EXT_MASK()
                .set_EXT_MASK(i_ext_mask),
                "An invalid address extension mask was selected");
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
