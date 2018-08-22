/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/plat/mmio_access.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file i2c_access.H
///
/// @brief I2C access functions that needs to be specialized for
/// platform implementation.
///
/// NOTE : This is just an example implementation for compiling against

#ifndef _FAPI2_MMIO_ACCESS_H_
#define _FAPI2_MMIO_ACCESS_H_

#include <vector>
#include <iostream>
#include <iomanip>

#include <plat_mmio_access.H>
#include <fapi2_mmio_access.H>

namespace fapi2
{

/// @brief Reads data via mmio from the target
template< TargetType K, typename V >
inline ReturnCode getMMIO(const Target<K, V>& i_target,
                          const uint64_t i_mmioAddr,
                          const size_t i_transSize,
                          std::vector<uint8_t>& o_data)
{

    // Platform suggestion:
    // - Verify o_data.size() is a multiple of i_transSize

    o_data.assign( o_data.size(), 0 );

    for (size_t i = 0; i < o_data.size(); i++)
    {
        o_data[i] = i;
    }

    std::cout << std::hex << "   getMMIO "
              << "target: {" << i_target.getType() << ","
              << i_target.get() << "}; "
              << "i_mmioAddr: " << i_mmioAddr << "; "
              << "i_transSize: " << i_transSize << "; "
              << "l_byteSize: " << o_data.size() << "; "
              << "o_data: ";

    for ( uint8_t l_byte = 0; l_byte < o_data.size(); l_byte++ )
    {
        std::cout << std::setfill('0') << std::setw(2) << std::hex << +o_data[l_byte];
    }

    std::cout << "; " << std::dec << std::endl;

    return FAPI2_RC_SUCCESS;
}

/// @brief Writes data via mmio to the target.
template< TargetType K, typename V >
inline ReturnCode putMMIO(const Target<K, V>& i_target,
                          const uint64_t i_mmioAddr,
                          const size_t i_transSize,
                          const std::vector<uint8_t>& i_data)
{

    // Platform suggestion:
    // - Verify o_data.size() is a multiple of i_transSize

    std::cout << std::hex << "   putMMIO "
              << "target: {" << i_target.getType() << ","
              << i_target.get() << "}; "
              << "i_mmioAddr: " << i_mmioAddr << "; "
              << "i_transSize: " << i_transSize << "; "
              << "l_byteSize: " << i_data.size() << "; "
              << "i_data: ";

    for ( uint8_t l_byte = 0; l_byte < i_data.size(); l_byte++ )
    {
        std::cout << std::setfill('0') << std::setw(2) << std::hex << +i_data[l_byte];
    }

    std::cout << "; " << std::dec << std::endl;

    return FAPI2_RC_SUCCESS;
}

};


#endif // _FAPI2_MMIO_ACCESS_H_
