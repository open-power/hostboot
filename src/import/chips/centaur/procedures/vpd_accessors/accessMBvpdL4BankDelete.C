/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/accessMBvpdL4BankDelete.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file accessMBvpdL4BankDelete.C
/// @brief get the L4 Bank Delete data from MBvpd record VSPD keyword MX
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <stdint.h>

//  fapi2 support
#include <fapi2.H>
#include <accessMBvpdL4BankDelete.H>
#include <fapi2_mbvpd_access.H>

extern "C"
{
///
/// @brief MBvpd accessor for the ATTR_L4_BANK_DELETE_VPD attribute
/// @param[in] i_mbTarget  - Reference to mb Target
/// @param[in,out] io_val  - retrived MX value or value to use to update MX vpd
/// @param[in] i_mode      - set or get mode
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode accessMBvpdL4BankDelete(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&  i_mbTarget,
        uint32_t&   io_val,
        const fapi2::MBvpdL4BankDeleteMode i_mode )
    {
        uint16_t l_l4BankDelete = 0;
        size_t l_bufSize = sizeof(l_l4BankDelete);

        FAPI_DBG("accessMBvpdL4BankDelete: entry ");

        // check for get/set mode
        if (fapi2::GET_L4_BANK_DELETE_MODE == i_mode) // retrieve value from vpd
        {
            // get vpd version from record VSPD keyword MX
            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_MX,
                                   i_mbTarget,
                                   reinterpret_cast<uint8_t*>(&l_l4BankDelete),
                                   l_bufSize), "accessMBvpdL4BankDelete: Read of MX keyword failed");

            // Check that sufficient size was returned.
            FAPI_ASSERT(l_bufSize >= sizeof(l_l4BankDelete),
                        fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                        set_KEYWORD(fapi2::MBVPD_KEYWORD_MX).
                        set_RETURNED_SIZE(l_bufSize).
                        set_CHIP_TARGET(i_mbTarget),
                        "accessMBvpdL4BankDelete:"
                        " less keyword data returned than expected %d < %zd",
                        l_bufSize, sizeof(l_l4BankDelete));

            // return value
            io_val = static_cast<uint32_t>(be16toh(l_l4BankDelete));

            FAPI_DBG("accessMBvpdL4BankDelete: get L4 Bank Delete = 0x%08x",
                     io_val);
        }
        else if (fapi2::SET_L4_BANK_DELETE_MODE == i_mode) // update vpd value
        {

            uint16_t l_val = static_cast<uint16_t>(io_val);
            l_l4BankDelete = htobe16(l_val);

            // update vpd record VSPD keyword MX
            FAPI_TRY(setMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_MX,
                                   i_mbTarget,
                                   reinterpret_cast<uint8_t*>(&l_l4BankDelete),
                                   l_bufSize), "accessMBvpdL4BankDelete: Set of MX keyword failed");

            FAPI_DBG("accessMBvpdL4BankDelete: set L4 Bank Delete = 0x%04x",
                     l_l4BankDelete);

        }
        else  // unlikely invalid mode
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MBVPD_INVALID_MODE_PARAMETER().
                        set_MODE(i_mode),
                        "accessMBvpdL4BankDelete:"
                        " invalid mode = 0x%02x", i_mode);
        }

        FAPI_DBG("accessMBvpdL4BankDelete: exit");

    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
