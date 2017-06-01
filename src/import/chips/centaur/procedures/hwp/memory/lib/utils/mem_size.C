/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/lib/utils/mem_size.C $ */
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

#include <fapi2.H>

#include <lib/shared/dimmConsts.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief Check if a given DIMM is functional
/// @param[in] i_valid_dimm_bitmap from ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR
/// @param[in] i_port port index [0:1]
/// @param[in] i_dimm dimm index [0:1]
/// @return true if dimm is functional, false otherwise
///
bool is_dimm_functional(const uint8_t i_valid_dimm_bitmap,
                        const uint8_t i_port,
                        const uint8_t i_dimm)
{
    // TODO - RTC:174931 See if we can clean up is_dimm_functional when indexing API is implemented
    constexpr uint8_t PORT0_DIMM0_BIT_POS = 0;
    constexpr uint8_t PORT0_DIMM1_BIT_POS = 1;
    constexpr uint8_t PORT1_DIMM0_BIT_POS = 4;
    constexpr uint8_t PORT1_DIMM1_BIT_POS = 5;

    // Map that represents a valid dimm position for ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR
    // Taken from attribute description
    static constexpr uint8_t const VALID_DIMM_POS[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] =
    {
        { PORT0_DIMM0_BIT_POS, PORT0_DIMM1_BIT_POS },
        { PORT1_DIMM0_BIT_POS, PORT1_DIMM1_BIT_POS },
    };

    if (i_port >= MAX_PORTS_PER_MBA)
    {
        FAPI_ERR("Port index out of bounds: %d", i_port);
        fapi2::Assert(false);
    }

    if (i_dimm >= MAX_DIMM_PER_PORT)
    {
        FAPI_ERR("DIMM index out of bounds: %d", i_dimm);
        fapi2::Assert(false);
    }

    // We are just checking bits are set from bitmap
    // that states whether a certain dimm is functional
    return fapi2::buffer<uint8_t>(i_valid_dimm_bitmap).getBit(VALID_DIMM_POS[i_port][i_dimm]);
}

///
/// @brief Return the total memory size behind a DMI
/// @param[in] i_target the DMI target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_target, uint64_t& o_size )
{
    o_size = 0;

    for (const auto& mba : mss::find_targets<fapi2::TARGET_TYPE_MBA>(i_target))
    {
        uint8_t l_sizes[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {};
        uint8_t l_func_dimms_bitmap = 0;

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, mba,  l_func_dimms_bitmap),
                  "Failed to access attribute ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR for %s", mss::c_str(mba) );

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_SIZE, mba, l_sizes),
                  "Failed to access attribute ATTR_CEN_EFF_DIMM_SIZE for %s", mss::c_str(mba) );

        for( size_t p = 0; p < MAX_PORTS_PER_MBA; ++p)
        {
            for( size_t d = 0; d < MAX_DIMM_PER_PORT; ++d)
            {
                if( is_dimm_functional(l_func_dimms_bitmap, p, d) )
                {
                    o_size += l_sizes[p][d];
                }
            }// dimm
        }// port
    }// mba

fapi_try_exit:
    return fapi2::current_err;
}

}// mss
