/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/spd_factory.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file spd_factory.H
/// @brief SPD factory and functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FACTORY_H_
#define _MSS_SPD_FACTORY_H_

// std lib
#include <cstdint>
#include <map>
#include <memory>

// fapi2
#include <fapi2.H>
#include <fapi2_spd_access.H>

// mss lib
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace spd
{

///
/// @brief Decodes SPD Revision encoding level
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_value encoding revision num
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 1 (3~0).
/// @note Item JC-45-2220.01x
/// @note Page 14-15
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_encoding_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<uint8_t>& i_spd_data,
                                     uint8_t& o_value);
///
/// @brief Decodes SPD Revision additions level
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD blob
/// @param[out] o_value additions revision num
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 1 (bits 7~4).
/// @note Item JC-45-2220.01x
/// @note Page 14-15
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_additions_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<uint8_t>& i_spd_data,
                                      uint8_t& o_value);

///
/// @brief Decodes hybrid type (whether or not the DIMM is a hybrid) from SPD
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_value hybrid
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 3 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode hybrid(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                         const std::vector<uint8_t>& i_spd_data,
                         uint8_t& o_value);

///
/// @brief Decodes hybrid type (hybrid DIMM type) from SPD
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_value hybrid module type
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 3 (bits 6~4)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode hybrid_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const std::vector<uint8_t>& i_spd_data,
                              uint8_t& o_value);

///
/// @brief Decodes base module type (DIMM type) from SPD
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_value base module type
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 3 (bits 3~0)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode base_module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value);
///
/// @brief Decodes DRAM Device Type
/// @param[in] i_target dimm target
/// @param[out] o_value dram device type enumeration
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 2
/// @note Item JC-45-2220.01x
/// @note Page 16
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode dram_device_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value);

///
/// @brief Wrapper function for finding the raw card -- helper for testing
/// @param[in] i_target the dimm target
/// @param[in] i_dimm_type
/// @param[in] i_ref_raw_card_rev for FFDC
/// @param[in] i_mrw_supported_rc
/// @param[in] i_map raw card map
/// @param[out] o_rcw raw card setting
/// @return rcw_settings vector of rcw settings
/// @note This specialization is suited for creating a cache with custom
/// SPD data (e.g. testing custom SPD).
/// @note MRW attributes are read-only, this function provides a mechanism to test
/// different code paths.
///
fapi2::ReturnCode find_raw_card_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint64_t i_dimm_type,
                                        const uint8_t i_ref_raw_card_rev,
                                        const uint8_t i_mrw_supported_rc,
                                        const std::vector<std::pair<uint8_t, rcw_settings> >& i_map,
                                        rcw_settings& o_raw_card);

///
/// @brief Wrapper function for finding the raw card
/// @param[in] i_target the dimm target
/// @param[in] i_dimm_type
/// @param[in] i_ref_raw_card_rev for FFDC
/// @param[in] i_map raw card map
/// @param[out] o_rcw raw card setting
/// @return rcw_settings vector of rcw settings
/// @note This specialization is suited for creating a cache with custom
/// SPD data (e.g. testing custom SPD).
///
fapi2::ReturnCode find_raw_card( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_dimm_type,
                                 const uint8_t i_ref_raw_card_rev,
                                 const std::vector<std::pair<uint8_t, rcw_settings> >& i_map,
                                 rcw_settings& o_raw_card);

///
/// @brief Decodes reference raw card
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 130 (Bits 7~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @Note Page 4.1.2.12 - 49
///
fapi2::ReturnCode reference_raw_card(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<uint8_t>& i_spd_data,
                                     uint8_t& o_output);

///
/// @brief Retrieve current raw card settings
/// based on dimm type and raw card reference rev
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_raw_card raw card settings
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode raw_card_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   rcw_settings& o_raw_card);

///
/// @brief Object factory to select correct decoder
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_fact_obj shared pointer to the factory object
/// @return FAPI2_RC_SUCCESS if okay
/// @note Factory dependent on SPD revision & dimm type
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_spd_data,
                          std::shared_ptr<decoder>& o_fact_obj);


///
/// @brief Determines & sets effective config for number of master ranks per dimm
/// @param[in] i_target DIMM fapi2::Target
/// @param[in] i_pDecoder shared_ptr to SPD decoder
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This is done after the SPD cache is configured so that it can reflect the results of the
/// factory and we don't need to worry about SPD versions. This is expressly different than the dram and dimm setters
///
fapi2::ReturnCode master_ranks_per_dimm_setter(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<decoder>& i_pDecoder);

///
/// @brief Creates factory object & SPD data caches
/// @tparam T fapi2::TargetType, MCA, MCS, MCBIST, PROC_CHIP are possible TargetTypes
/// @param[in] i_target the fapi2 target to find DIMMs on
/// @param[out] o_factory_caches vector of factory objects
/// @param[in] i_pDecoder optional input decoder to insert custom decoder (nullptr default)
/// @return FAPI2_RC_SUCCESS if okay
///
template<fapi2::TargetType T>
fapi2::ReturnCode populate_decoder_caches(const fapi2::Target<T>& i_target,
        std::vector< std::shared_ptr<decoder> >& o_factory_caches,
        const std::shared_ptr<decoder>& i_pDecoder = nullptr)
{
    // Input decoder for this version of populating cache would get overriden
    // so I don't bother with it in this specialization
    std::shared_ptr<decoder> l_pDecoder;

    for( const auto& l_dimm : find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        size_t l_size = 0;
        FAPI_TRY( fapi2::getSPD(l_dimm, nullptr, l_size),
                  "%s. Failed to retrieve SPD blob size", mss::c_str(i_target) );

        {
            // "Container" for SPD data
            std::vector<uint8_t> l_spd(l_size);

            // Retrieve SPD data
            FAPI_TRY( fapi2::getSPD(l_dimm, l_spd.data(), l_size),
                      "%s. Failed to retrieve SPD data", mss::c_str(i_target) );

            // Retrieve factory object instance & populate spd data for that instance
            FAPI_TRY( factory(l_dimm, l_spd, l_pDecoder),
                      "%s. Failed SPD factory, could not instantiate decoder object", mss::c_str(i_target) );

            // Populate spd caches
            o_factory_caches.push_back( l_pDecoder );
        }

        // Populate some of the DIMM attributes early. This allows the following code to make
        // decisions based on DIMM information. Expressly done after the factory has decided on the SPD version
        FAPI_TRY( master_ranks_per_dimm_setter(l_dimm, l_pDecoder),
                  "%s. Failed master_ranks_per_dimm_setter()", mss::c_str(i_target) );

    }// end dimm

fapi_try_exit:
    return fapi2::current_err;
}

}// spd

///
/// @brief Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD
/// @param[in] i_pDecoder the SPD decoder
/// @param[out] o_value tCKmin value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_tckmin(const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
                             uint64_t& o_value);

///
/// @brief Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD
/// @param[in] i_pDecoder SPD decoder
/// @param[out] o_value tCKmax value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_tckmax(const std::shared_ptr<mss::spd::decoder>& i_pDecoder,
                             uint64_t& o_value);

}// mss

#endif //_MSS_SPD_FACTORY_H_
