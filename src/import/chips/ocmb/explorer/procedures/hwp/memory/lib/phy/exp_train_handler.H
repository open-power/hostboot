/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_handler.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file exp_train_handler.H
/// @brief Procedure handle any training fails from the explorer
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __EXP_TRAIN_HANDLER_H__
#define __EXP_TRAIN_HANDLER_H__

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>

namespace mss
{
namespace exp
{

///
/// @brief Reads the training response structure
/// @param[in] i_target the target associated with the response data
/// @param[in] i_data the response data to read
/// @param[out] o_resp the processed training response class
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode read_training_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<uint8_t>& i_data,
        user_response_msdg& o_resp);

///
/// @brief Explorer's bad bit interface class
/// @note L1 functionality Place holder to avoid merge conflicts. This will be updated in another commit
///
class bad_bit_interface
{
    public:

        ///
        /// @brief Default constructor
        ///
        bad_bit_interface() = default;

        ///
        /// @brief Default destructor
        ///
        ~bad_bit_interface() = default;

        ///
        /// @param[in] i_target the DIMM to record training results on
        /// @param[out] o_bad_bits the processed bad bits
        /// @return FAPI2_RC_SUCCESS if ok
        ///
        fapi2::ReturnCode record_bad_bits_interface( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t (&o_bad_dq)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]) const
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

} // ns exp
} // ns mss

#endif
