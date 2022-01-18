/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddr5_ddimm_efd_engine.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file p10_ddr5_ddimm_efd_engine.H
/// @brief DDR5 DDIMM EFD eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDR5_DDIMM_EFD_ENGINE_H_
#define _P10_DDR5_DDIMM_EFD_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/utils/find.H>

#include <lib/eff_config/p10_ddimm_efd_engine.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <lib/dimm/exp_rank.H>


namespace mss
{
namespace efd
{
namespace ddr5
{

///
/// @brief Class for base EFD section of SPD - specifically DDR5
///
class ddimm_0_0 : public mss::efd::base
{
    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_port;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;
        uint8_t iv_dimm_rank;
        uint8_t iv_phy_rank;

    public:

        ///
        /// @brief Construct a new DDR5 DDIMM EFD rev 0.0 object
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_rank_info the current rank info class
        ///
        ddimm_0_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                  const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info) :
            base(i_dimm, i_rank_info) {}

        ///
        /// @brief Destroy the ddimm_efd_0_3 object
        ///
        virtual ~ddimm_0_0() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const
        {
            return mss::spd::rev::V0_0;
        }

        ///
        /// @brief Get the DRAM generation
        /// @return DRAM generation value
        ///
        virtual uint8_t get_dram_generation() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5;
        }

        /// @brief Process the fields for DDR5 DDIMM EFD
        ///
        /// @param[in] i_efd EFD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_efd) const
        {
            // This will need to be filled in. It's just a skeleton code now
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

}// ddr5

}// efd

}// mss

#endif
