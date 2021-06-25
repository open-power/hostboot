/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_dyninit_bitvec_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

//------------------------------------------------------------------------------
/// @file  p10_dyninit_bitvec_utils.C
/// @brief Utilities for p10 dynamic init bit vector management
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer   : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_dyninit_bitvec_utils.H>

using namespace p10_dyninit_bitvec_utils;

//------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------

///
/// @brief Test that requested bit position is within range of bit vector's
///        current precise bit count
///
/// @param[in] i_bvec    Bit vector structure
/// @param[in] i_bit     Bit position to test
///
/// @returns bool True if i_bit is in range, else false
///
bool
p10_dyninit_bitvec_utils::test_bit_in_range(
    const p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit)
{
    return ((i_bit < i_bvec.iv_bit_count) &&
            (i_bit < (64 * i_bvec.iv_bits.size())));
}

///
/// @brief Assert that requested bit position is within range of bit vector's
///        current precise bit count
///
/// @param[in] i_bvec    Bit vector structure
/// @param[in] i_bit     Bit position to test
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
p10_dyninit_bitvec_utils::verify_bit_in_range(
    const p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit)
{
    FAPI_ASSERT(test_bit_in_range(i_bvec, i_bit),
                fapi2::P10_DYNINIT_BITVEC_RANGE_ERROR()
                .set_BIT_COUNT(i_bvec.iv_bit_count)
                .set_SIZE(i_bvec.iv_bits.size())
                .set_TYPE(i_bvec.iv_type)
                .set_SOURCE(i_bvec.iv_source)
                .set_BIT_POS(i_bit),
                "Bit %d out of range!",
                i_bit);
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Bit vector utility function -- check if specific bit position is set
///
/// @param[in]  i_bvec   Bit vector structure
/// @param[in]  i_bit    Bit position to test
/// @param[out] o_set    True if i_bit posiition is set in i_bvec, else false
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
p10_dyninit_bitvec_utils::is_bit_set(
    const p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit,
    bool& o_set)
{
    FAPI_TRY(verify_bit_in_range(i_bvec, i_bit));
    o_set = (i_bvec.iv_bits[i_bit / 64]) &
            ((0x8000000000000000ULL) >> (i_bit % 64));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bit vector utility function -- set specific bit position
///
/// @param[in]  i_bvec   Bit vector structure
/// @param[in]  i_bit    Bit position to set
/// @param[in]  i_desc   Bit description for trace
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
p10_dyninit_bitvec_utils::set_bit(
    p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit,
    const char* i_desc)
{
    FAPI_TRY(verify_bit_in_range(i_bvec, i_bit));
    i_bvec.iv_bits[i_bit / 64] |= ((0x8000000000000000ULL) >> (i_bit % 64));

    if (i_desc)
    {
        FAPI_DBG("Setting bit: %d (%s)",
                 i_bit, i_desc);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bit vector utility function -- clear specific bit position
///
/// @param[in]  i_bvec   Bit vector structure
/// @param[in]  i_bit    Bit position to clear
/// @param[in]  i_desc   Bit description for trace
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
p10_dyninit_bitvec_utils::clear_bit(
    p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit,
    const char* i_desc)
{
    FAPI_TRY(verify_bit_in_range(i_bvec, i_bit));
    i_bvec.iv_bits[i_bit / 64] &= ~((0x8000000000000000ULL) >> (i_bit % 64));

    if (i_desc)
    {
        FAPI_DBG("Clearing bit: %d (%s)",
                 i_bit, i_desc);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Dump bit vector contents for debug
///
/// @param[in]  i_bvec   Bit vector structure
///
/// @returns void
///
void
p10_dyninit_bitvec_utils::dump_bitvec(
    const p10_dyninit_bitvec& i_bvec)
{
    FAPI_DBG("Bit vector type: %s, source: %s, num bits: %d, vec size: %d",
             (i_bvec.iv_type == MODE) ? ("MODE") : ("FEATURE"),
             (i_bvec.iv_source == HW_IMAGE) ? ("HW_IMAGE") :
             ((i_bvec.iv_source == PLAT) ? ("PLAT") : ("MERGED")),
             i_bvec.iv_bit_count,
             i_bvec.iv_bits.size());

    if (i_bvec.iv_bit_count)
    {
        uint16_t l_start_index = 0;
        uint16_t l_end_index = 63;

        for (uint16_t i = 0; i < i_bvec.iv_bits.size(); i++)
        {
            FAPI_DBG("[ %5d : %-5d ] = 0x%016llX",
                     l_start_index,
                     l_end_index,
                     i_bvec.iv_bits[i]);
            l_start_index += 64;
            l_end_index += 64;
        }
    }

    return;
}

///
/// @brief Initialize bit vector from platform state
///
/// Queries platform attributes to initialize bit vector content sized
/// to match build time attribute properties
///
/// @param[in]  i_target     Processor scope target for attribute query
/// @param[in]  i_type       Type of bit vector to create.  Used to query
///                          appropriate platform attributes
/// @param[out] o_bvec       Bit vector filled to platform state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
p10_dyninit_bitvec_utils::init_bitvec_from_plat(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_dyninit_bitvec_type i_type,
    p10_dyninit_bitvec& o_bvec)
{
    FAPI_DBG("Start");

    if (i_type == MODE)
    {
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys_target;

        fapi2::ATTR_DYNAMIC_INIT_MODE_VEC_Type l_attr_vec;
        fapi2::ATTR_DYNAMIC_INIT_MODE_COUNT_Type l_attr_count;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_MODE_VEC,
                               l_sys_target,
                               l_attr_vec));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_MODE_COUNT,
                               l_sys_target,
                               l_attr_count));

        o_bvec.iv_bits.assign(l_attr_vec,
                              l_attr_vec +
                              (sizeof(l_attr_vec) /
                               sizeof(l_attr_vec[0])));
        o_bvec.iv_bit_count = l_attr_count;
    }
    else
    {
        fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC_Type l_attr_vec;
        fapi2::ATTR_DYNAMIC_INIT_FEATURE_COUNT_Type l_attr_count;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC,
                               i_target,
                               l_attr_vec));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_COUNT,
                               i_target,
                               l_attr_count));

        o_bvec.iv_bits.assign(l_attr_vec,
                              l_attr_vec +
                              (sizeof(l_attr_vec) /
                               sizeof(l_attr_vec[0])));
        o_bvec.iv_bit_count = l_attr_count;
    }

    o_bvec.iv_type = i_type;
    o_bvec.iv_source = PLAT;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Push bit vector state into platform attribute storage
///
/// @param[in]  i_target     Processor scope target for attribute query
/// @param[in]  i_bvec       Bit vector filled to platform state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
p10_dyninit_bitvec_utils::save_bitvec_to_plat(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p10_dyninit_bitvec& i_bvec)
{
    FAPI_DBG("Start");

    fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC_Type l_attr_vec;

    FAPI_ASSERT((i_bvec.iv_type == FEATURE) &&
                (i_bvec.iv_source == PLAT),
                fapi2::P10_DYNINIT_BITVEC_SAVE_ERROR()
                .set_TYPE(i_bvec.iv_type)
                .set_SOURCE(i_bvec.iv_source)
                .set_PROC_CHIP(i_target),
                "Requested bit vector type can't be saved to platform attribute!");

    // prep write to attribute
    for (uint16_t i = 0; i < i_bvec.iv_bits.size(); i++)
    {
        l_attr_vec[i] = i_bvec.iv_bits[i];
    }

    // write platform attribute
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC,
                           i_target,
                           l_attr_vec));

    // re-read, to honor CONST attribute overrides
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC,
                           i_target,
                           l_attr_vec));

    for (uint16_t i = 0; i < i_bvec.iv_bits.size(); i++)
    {
        i_bvec.iv_bits[i] = l_attr_vec[i];
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
