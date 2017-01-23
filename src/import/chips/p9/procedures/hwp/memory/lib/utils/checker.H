/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/checker.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file checker.H
/// @brief Contains common functions that perform checks
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _CHECKER_H_
#define _CHECKER_H_

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>

namespace mss
{
namespace check
{
///
/// @brief checks for invalid DQ data captured by from read FIFO
/// used for LRDIMM training appliations
/// @param[in]  i_target the dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_data DQ data from DRAM
/// @param[in]  i_phase_timing phase timing we are iterating through
/// @param[in]  i_nibble nibble we are iterating through
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode invalid_dq_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool i_conditional,
        const fapi2::variable_buffer& i_data,
        const uint64_t i_phase_timing,
        const uint64_t i_nibble )
{
    constexpr uint64_t AADR_START = 0;
    constexpr uint64_t AADR_LEN = 64;

    constexpr uint64_t AAER_START = 64;
    constexpr uint64_t AAER_LEN = 8;

    uint64_t l_aaer = 0; // ecc
    uint64_t l_aadr = 0; // data

    // Can't printout the variable buffer directly. Extracting
    // data of interest for debugging purposes
    FAPI_TRY( i_data.extractToRight(l_aadr, AADR_START, AADR_LEN),
              "Failed to extract AADR data, start: %d, len: %d", AADR_START, AADR_LEN);

    FAPI_TRY( i_data.extractToRight(l_aaer, AAER_START, AAER_LEN),
              "Failed to extract AAER data, start: %d, len: %d", AAER_START, AAER_LEN);

    FAPI_ASSERT(i_conditional,
                fapi2::MSS_INVALID_DQ_DATA().
                set_PHASE_TIMING(i_phase_timing).
                set_NIBBLE(i_nibble).
                set_DIMM_TARGET(i_target).
                set_AADR(l_aadr).
                set_AAER(l_aaer),
                "%s. Invalid data received for phase: %d, nibble: %d, AADR: %d, AAER: %d.",
                mss::c_str(i_target), i_phase_timing,
                i_nibble, l_aadr, l_aaer );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Checks homogenous DDR4 dimm configuration (e.g. DDR4)
/// @param[in]  i_target the controller target
/// @return     fapi2::FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode dram_type(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    uint8_t l_dram_gen[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Retrieve DDR4 dimm attributes
    FAPI_TRY(eff_dram_gen(i_target, &(l_dram_gen[0][0])));

    // Make sure all DRAMs are DDR4 or throw an error
    for (const auto& l_mca : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        const auto l_port_num = mss::index(l_mca);

        for (const auto& l_dimm : l_mca.getChildren<fapi2::TARGET_TYPE_DIMM>())
        {
            const auto l_dimm_num = mss::index(l_dimm);

            FAPI_INF("%s DRAM device type is %llX",
                     mss::c_str(l_dimm),
                     l_dram_gen[l_port_num][l_dimm_num]);

            // Nimbus supports only DDR4
            FAPI_ASSERT(l_dram_gen[l_port_num][l_dimm_num] == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
                        fapi2::MSS_UNSUPPORTED_DEV_TYPE().
                        set_DEV_TYPE(l_dram_gen[l_port_num][l_dimm_num]),
                        "%s Incorrect DRAM device generation, DRAM generation is %llx",
                        mss::c_str(l_dimm),
                        l_dram_gen[l_port_num][l_dimm_num]);
        }// dimm
    }// mca

fapi_try_exit:
    return fapi2::current_err;

}// dram_type

///
/// @brief      Checks conditional and implements traces & exits if it fails
/// @param[in]  i_target the dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_key map key
/// @param[in]  i_data additional returned data
/// @param[in]  i_err_str error string to print out when conditional fails
/// @return     ReturnCode
///
inline fapi2::ReturnCode fail_for_invalid_map(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_conditional,
        const uint64_t i_key,
        const uint64_t i_data = 0,
        const char* i_err_str = "")
{
    // Invalid keys won't return useful or valid data so we allow optional data
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_INVALID_KEY().
                set_KEY(i_key).
                set_DATA(i_data).
                set_DIMM_TARGET(i_target),
                "%s. %s Could not find value from key %d. Returned data: %d.",
                c_str(i_target),
                i_err_str,
                i_key,
                i_data);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks to make sure ATTR_MSS_MRW_TEMP_REFRESH_MODE and ATTR_MSS_MRW_FINE_REFRESH_MODE are set correctly
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note from DDR4 DRAM Spec (79-4B) 4.9.4 page 48
///
fapi2::ReturnCode temp_refresh_mode();

namespace spd
{

///
/// @brief      Checks conditional passes and implements traces & exits if it fails
/// @tparam     T input data of any size
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_spd_byte_index current SPD byte
/// @param[in]  i_spd_data debug data
/// @param[in]  i_err_str error string to print out when conditional fails
/// @return     ReturnCode
///
template< typename T >
inline fapi2::ReturnCode fail_for_invalid_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_conditional,
        const size_t i_spd_byte_index,
        const T i_spd_data,
        const char* i_err_str)
{
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_BAD_SPD().
                set_VALUE(i_spd_data).
                set_BYTE(i_spd_byte_index).
                set_DIMM_TARGET(i_target),
                "%s %s Byte %d, Data returned: %d.",
                c_str(i_target),
                i_err_str,
                i_spd_byte_index,
                i_spd_data);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;

} // fail_for_invalid_value()

///
/// @brief      Checks conditional passes and implements traces if it fails. No FFDC collected.
/// @tparam     T input data of any size
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_conditional that we are testing against
/// @param[in]  i_spd_byte_index
/// @param[in]  i_spd_data debug data
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     void
///
template< typename T >
inline void warn_for_invalid_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const bool i_conditional,
                                   const size_t i_spd_byte_index,
                                   const T i_spd_data,
                                   const char* i_err_str)
{
    // Don't print warning conditional if true
    if(!i_conditional)
    {
        FAPI_IMP("%s. %s. Byte %d, Data returned: %d.",
                 c_str(i_target),
                 i_err_str,
                 i_spd_byte_index,
                 i_spd_data );
    }
}// warn_for_invalid_value

///
/// @brief      Checks if valid factory parameters are given
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_dimm_type DIMM type enumeration
/// @param[in]  i_encoding_rev SPD encoding level rev number
/// @param[in]  i_additions_rev SPD additions level rev number
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     fapi2::ReturnCode
///
inline fapi2::ReturnCode invalid_factory_sel(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_dimm_type,
        const uint8_t i_encoding_rev,
        const uint8_t i_additions_rev,
        const char* i_err_str)
{
    FAPI_ASSERT(false,
                fapi2::MSS_INVALID_DIMM_REV_COMBO().
                set_DIMM_TYPE(i_dimm_type).
                set_ENCODING_REV(i_encoding_rev).
                set_ADDITIONS_REV(i_additions_rev).
                set_DIMM_TARGET(i_target),
                "%s. %s. Invalid combination for dimm type: %d, rev: %d.%d",
                c_str(i_target),
                i_err_str,
                i_dimm_type,
                i_encoding_rev,
                i_additions_rev);
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}// invalid_factory_sel

///
/// @brief      Checks if valid factory parameters are given
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_dimm_type DIMM type enumeration
/// @param[in]  i_encoding_rev SPD encoding level rev number
/// @param[in]  i_additions_rev SPD additions level rev number
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     fapi2::ReturnCode
///
inline fapi2::ReturnCode invalid_cache(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const bool i_conditional,
                                       const uint8_t i_dimm_pos)
{
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_INVALID_CACHE().
                set_DIMM_POS(i_dimm_pos).
                set_DIMM_TARGET(i_target),
                "%s. Could not find SPD decoder cache for dimm pos: %d",
                c_str(i_target),
                i_dimm_pos);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}// invalid_factory_sel

}// spd
}// check
}// mss

#endif
