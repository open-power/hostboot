/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_getecid_utils.C $ */
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

/// @file exp_getecid_utils.C
/// @brief Gets ECID from explorer fuse registers
///
/// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <fapi2.H>
#include <lib/i2c/exp_i2c.H>
#include <lib/shared/exp_consts.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fixes.H>
#include <explorer_scom_addresses_fld_fixes.H>
#include <mss_explorer_attribute_setters.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>


namespace mss
{
namespace exp
{
namespace ecid
{

///
/// @brief Determines enterprise state from explorer FUSE
/// @param[in] i_target the controller
/// @param[out] o_enterprise_mode state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_enterprise_from_fuse(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    bool& o_enterprise_mode)
{
    fapi2::buffer<uint64_t> l_reg_resp_buffer;
    FAPI_TRY(fapi2::getScom( i_target, static_cast<uint64_t>(EXPLR_EFUSE_IMAGE_OUT_0), l_reg_resp_buffer ),
             "exp_getecid: could not read explorer fuse register 0x%08x", EXPLR_EFUSE_IMAGE_OUT_0);

    // Since the bit is a disable bit, take the opposite to get enable=true, disable=false
    o_enterprise_mode = !(l_reg_resp_buffer.getBit<EXPLR_EFUSE_IMAGE_OUT_0_ENTERPRISE_MODE_DIS>());

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads ECID into output array from fuse
/// @param[in] i_target the controller
/// @param[out] o_array ECID contents
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode read_from_fuse(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint16_t (&o_ecid_array)[mss::exp::ecid_consts::FUSE_ARRAY_SIZE])
{

    // FUSE registers mapping to the above bit-structure
    static constexpr uint64_t l_ecid_regs[mss::exp::ecid_consts::FUSE_ARRAY_SIZE] =
    {
        EXPLR_EFUSE_PE_DATA_0,
        EXPLR_EFUSE_PE_DATA_1,
        EXPLR_EFUSE_PE_DATA_2,
        EXPLR_EFUSE_PE_DATA_3,
        EXPLR_EFUSE_PE_DATA_4,
        EXPLR_EFUSE_PE_DATA_5,
        EXPLR_EFUSE_PE_DATA_6, // PE_DATA_7 does not exist
        EXPLR_EFUSE_PE_DATA_8,
        EXPLR_EFUSE_PE_DATA_9,
        EXPLR_EFUSE_PE_DATA_10,
        EXPLR_EFUSE_PE_DATA_11,
        EXPLR_EFUSE_PE_DATA_12,
        EXPLR_EFUSE_PE_DATA_13,
        EXPLR_EFUSE_PE_DATA_14
    };

    fapi2::buffer<uint64_t> l_efuse_contents;
    static constexpr uint32_t START_BIT = 48; // Last 16 bits

    for (uint16_t l_pe_reg = 0; l_pe_reg < mss::exp::ecid_consts::FUSE_ARRAY_SIZE; ++l_pe_reg)
    {
        l_efuse_contents.flush<0>();

        // Assuming this will fall back to I2C.
        FAPI_TRY(fapi2::getScom( i_target, l_ecid_regs[l_pe_reg], l_efuse_contents ),
                 "exp_getecid: could not read explorer fuse register 0x%08x", l_ecid_regs[l_pe_reg]);

        // Each EFUSE register in question looks like this according to the spec:
        //
        // BIT          FUNCTION
        // 31:16        Unused
        // 15:0         EFUSE_IMAGE_OUT [HIGH:LOW]
        //
        // So, we are expecting the data in question to be in the right-most 16 bits.
        l_efuse_contents.extract<START_BIT, mss::exp::ecid_consts::DATA_IN_SIZE>(o_ecid_array[l_pe_reg]);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Stores ECID in ATTR_ECID
/// @param[in] i_target the controller
/// @param[in] i_ecid 16-bit array of ECID contents
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode set_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint16_t i_ecid[mss::exp::ecid_consts::FUSE_ARRAY_SIZE])
{

    //
    // TK - ATTR_ECID is only two 64-bit integers, but our OCMB ECID is larger.
    // Per Dan Crowell, there are plans in the future to make ATTR_ECID larger
    // This will need to be updated once that is changed. Currently, this is
    // only storing the first 128 bits of the ECID.
    //
    // TK - Once the above is implemented, we no longer need ATTR_OCMB_ECID (see exp_getecid.C)
    //

    // ATTR_ECID is an array of 2 64-bit integers
    uint64_t l_attr_ecid[mss::exp::ecid_consts::ATTR_ECID_SIZE] = {0};

    fapi2::buffer<uint64_t> l_constructed_ecid;

    // Build 64 bit ECID from right to left (from lowest to highest)
    // Places l_ecid[0] in 48:64, l_ecid[1] in 32:48, etc.
    mss::right_aligned_insert(l_constructed_ecid, i_ecid[3], i_ecid[2], i_ecid[1], i_ecid[0]);
    l_attr_ecid[0] = l_constructed_ecid;
    l_constructed_ecid.flush<0>();

    // Places l_ecid[4] in 48:64, l_ecid[5] in 32:48, etc.
    mss::right_aligned_insert(l_constructed_ecid, i_ecid[7], i_ecid[6], i_ecid[5], i_ecid[4]);
    l_attr_ecid[1] = l_constructed_ecid;

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target, l_attr_ecid),
             "exp_getecid: Could not set ATTR_ECID on %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}
} // ecid
} // exp
} // mss
