/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/fake_spd.H $ */
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
/// @file fake_spd.H
/// @brief A tool to return fake (fixed) DIMM SPD for testing, development
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

// This shouldn't be callable by HB
#ifndef __HOSTBOOT_MODULE
#ifndef DOXYGEN

#ifndef _MSS_FAKE_SPD_H_
#define _MSS_FAKE_SPD_H_

#include <fapi2.H>
#include <cstdint>

///
/// @brief SPD_TYPE class for our "fake" SPD for testing purposes
///
enum class spd_type
{
    VBU_16GB_2RX4_2400_DDR4_RDIMM,
    MICRON_8GB_1Rx8_2400_DDR4_RDIMM,
    MICRON_32GB_2RX4_2400_DDR4_LRDIMM,
    SAMSUNG_64GB_2S2RX4_2400_DDR4_RDIMM_3DS,
    CUSTOM_16GB_2RX8,
    RDIMM_NVDIMM_HYBRID_16GB_1RX4_2400_DDR4,
};

///
/// @brief SPD helper function that immitates getSPD behavior
/// @tparam N size of the input array
/// @param[in] i_raw_spd array of SPD data
/// @param[out] o_blob the blob of data from the DIMM - raw
/// @param[out] o_size the size of the blob
///
template< size_t N >
void spd_helper( const uint8_t (&i_raw_spd)[N],
                 uint8_t* o_blob,
                 size_t& o_size )
{
    o_size = sizeof( i_raw_spd );

    if( o_blob != nullptr )
    {
        memcpy( o_blob, i_raw_spd, o_size );
    }
}

///
/// @brief Return a blob of SPD data from a DIMM
/// @param[in] i_target a DIMM target representing the DIMM in question
/// @param[in] i_type SPD type (vendor, sdram type, etc)
/// @param[out] o_blob the blob of data from the DIMM - raw
/// @param[out] o_size the size of the blob
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note passing nullptr for o_blob will return the size of the blob
///
fapi2::ReturnCode getSPD( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const spd_type i_type,
                          uint8_t* o_blob,
                          size_t& o_size );

#endif // _MSS_FAKE_SPD_H_
#endif // DOXYGEN
#endif // __HOSTBOOT_MODULE
