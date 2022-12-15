/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_unmask.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_unmask.H
/// @brief Odyssey FIR unmask functions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ODY_UNMASK_H_
#define _MSS_ODY_UNMASK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic_attribute_accessors_manual.H>

namespace mss
{
namespace unmask
{

///
/// @brief Finds if a specific port is present
/// @param[in] i_ports the vector of ports present on this OCMB chip
/// @param[in] i_port_pos the port to look for in terms of the relative pos
/// @return true if the port is present, otherwise false
///
bool is_port_present(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports, const uint8_t i_port_pos);

///
/// @brief Sets up a specific FIR if a port is present and has an RCD
/// @tparam B the bit to update in the FIR register
/// @tparam R the FIR register to update
/// @param[in] i_ports the vector of ports present on this OCMB chip
/// @param[in] i_port_pos the port to look for in terms of the relative pos
/// @param[in] i_action the action type to set up for the FIR
/// @param[in,out] io_fir the FIR register class to update
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template <uint64_t B, uint64_t R>
fapi2::ReturnCode set_fir_bit_if_port_has_rcd(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports,
        const uint8_t i_port_pos,
        const mss::fir::action i_action,
        mss::fir::reg2<R>& io_fir)
{
    for(const auto& l_port : i_ports)
    {
        // Unmask and set actions on the requested port
        if(mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port) == i_port_pos)
        {
            bool l_has_rcd = false;
            FAPI_TRY(mss::has_rcd(l_port, l_has_rcd));

            // ...but only if it has an RCD
            if(l_has_rcd)
            {
                switch (i_action)
                {
                    case mss::fir::action::ATTN:
                        io_fir. template attention<B>();
                        break;

                    case mss::fir::action::LXSTOP:
                        io_fir. template local_checkstop<B>();
                        break;

                    case mss::fir::action::RECOV:
                        io_fir. template recoverable_error<B>();
                        break;

                    case mss::fir::action::XSTOP:
                    default:
                        io_fir. template checkstop<B>();
                        break;
                }
            }
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to disable the RCD recovery
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Code is based upon the RAS document from 13DEC2022
///
fapi2::ReturnCode after_scominit_disable_rcd_recovery_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target );

} // end unmask ns
} // end mss ns

#endif
