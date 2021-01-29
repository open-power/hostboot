/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_checker.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
/// @file spd_checker.H
/// @brief SPD functions to check boundaries
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _SPD_CHECKER_H_
#define _SPD_CHECKER_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{

///
/// @brief Selectors for timing limits
/// @note BITS12 stands for a 12 bit range
/// @note BITS16 stands for a 16 bit range
///
enum bit_len
{
    BITS12 = 12,
    BITS16 = 16,
};

///
/// @class bitRangeTraits
/// @brief Traits class to select
/// @tparam T bit_len selector
///
template <bit_len T>
struct bitRangeTraits;

///
/// @class bitRangeTraits
/// @brief Traits class to select - BITS12 specialization
///
template<>
struct bitRangeTraits<BITS12>
{
    enum
    {
        LOWER_BOUND = 0x1,
        UPPER_BOUND = 0xfff,
    };
};

///
/// @class bitRangeTraits
/// @brief Traits class to select - BITS16 specialization
///
template<>
struct bitRangeTraits<BITS16>
{
    enum
    {
        LOWER_BOUND = 0x1,
        UPPER_BOUND = 0xffff,
    };
};

namespace spd
{
namespace check
{

///
/// @brief SPD timing boundary check
/// @tparam BL bit_len selector
/// @tparam TT defaulted to bitRangeTraits<TB>
/// @param[in] i_target fapi2 target
/// @param[in] i_timing the timing value
/// @param[in] i_rev the SPD revision that needs to be checked
/// @param[in] i_ffdc ffdc function code
/// @return FAPI2_RC_SUCCESS iff okay
///
template < bit_len BL, typename TT = bitRangeTraits<BL> >
fapi2::ReturnCode max_timing_range(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const int64_t i_timing,
                                   const rev i_rev,
                                   const generic_ffdc_codes i_ffdc)
{
    FAPI_ASSERT( (i_timing <= TT::UPPER_BOUND) &&
                 (i_timing >= TT::LOWER_BOUND),
                 fapi2::MSS_SPD_TIMING_FAIL()
                 .set_FAILED_REVISION(i_rev)
                 .set_FUNCTION_CODE(i_ffdc)
                 .set_OCMB_TARGET(i_target)
                 .set_TIMING(i_timing)
                 .set_UPPER_BOUND(TT::UPPER_BOUND)
                 .set_LOWER_BOUND(TT::LOWER_BOUND),
                 "Failed timing parameter check for %s. %d is outside of %d <= %d for SPD revision 0x%02x",
                 spd::c_str(i_target), i_timing, TT::LOWER_BOUND, TT::UPPER_BOUND, i_rev );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to test if a DRAM generation is valid
/// @param[in] i_dram_gen the DRAM gen from SPD
/// @return true if this DRAM gen is valid, else false
///
static inline bool is_dram_gen_valid(const uint8_t i_dram_gen)
{
    bool l_result = false;

    switch(i_dram_gen)
    {
        case DDR4:
            l_result = true;
            break;

        default:
            l_result = false;
            break;
    }

    return l_result;
}

///
/// @brief Checks for valid DRAM generation
/// @param[in] i_target the DIMM target
/// @param[in] i_dram_gen the DRAM gen from SPD
/// @param[in] i_func_code mss ffdc code
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode dram_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_dram_gen,
                                  const generic_ffdc_codes i_func_code)
{
    FAPI_ASSERT(is_dram_gen_valid(i_dram_gen),
                fapi2::MSS_INVALID_DRAM_GEN()
                .set_DRAM_GEN(i_dram_gen)
                .set_FUNCTION(i_func_code)
                .set_DIMM_TARGET(i_target),
                "Invalid DRAM gen recieved (%d) for %s",
                i_dram_gen, spd::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to test if a DIMM type is valid
/// @param[in] i_dimm_type the DIMM type from SPD
/// @return true if this DIMM type is valid, else false
///
static inline bool is_dimm_type_valid(const uint8_t i_dimm_type)
{
    bool l_result = false;

    switch(i_dimm_type)
    {
        case RDIMM:
        case LRDIMM:
        case DDIMM:
        case SORDIMM:
        case MINIRDIMM:
            l_result = true;
            break;

        default:
            l_result = false;
            break;
    }

    return l_result;
}

///
/// @brief Checks for valid DIMM type
/// @param[in] i_target the DIMM target
/// @param[in] i_dram_gen the DIMM type from SPD
/// @param[in] i_func_code mss ffdc code
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode dimm_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_dimm_type,
                                   const generic_ffdc_codes i_func_code)
{
    FAPI_ASSERT(is_dimm_type_valid(i_dimm_type),
                fapi2::MSS_INVALID_DIMM_TYPE()
                .set_DIMM_TYPE(i_dimm_type)
                .set_FUNCTION(i_func_code)
                .set_DIMM_TARGET(i_target),
                "Invalid DIMM type recieved (%d) for %s",
                i_dimm_type, DDIMM, spd::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to check for reserved values
/// @tparam TT FAPI2 target type
/// @param[in] i_target the fapi2 target
/// @param[in] i_reserved_bits vector of SORTED reserved bits to sort through
/// @param[in] i_ffdc ffdc function code
/// @param[in] i_input value to check
/// @return FAPI2_RC_SUCCESS iff okay
///
template < fapi2::TargetType TT >
inline fapi2::ReturnCode reserved_values(const fapi2::Target<TT>& i_target,
        const std::vector<uint8_t>& i_reserved_bits,
        const generic_ffdc_codes i_ffdc,
        const uint8_t i_input)
{
    // Lets make an additional check that we aren't being set to a reserved field
    FAPI_ASSERT( !std::binary_search(i_reserved_bits.begin(), i_reserved_bits.end(), i_input),
                 fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                 .set_FUNCTION_CODE(i_ffdc)
                 .set_FAILING_VALUE(i_input)
                 .set_OCMB_TARGET(i_target),
                 "Reserved bits seen on %s. Value seen:0x%02x",
                 spd::c_str(i_target), i_input );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}// check
}// spd
}// mss

#endif
