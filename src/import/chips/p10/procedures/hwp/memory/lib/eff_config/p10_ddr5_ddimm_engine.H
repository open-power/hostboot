/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddr5_ddimm_engine.H $ */
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
/// @file p10_ddr5_ddimm_engine.H
/// @brief DDR5 DDIMM Module section eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDR5_DDIMM_ENGINE_H_
#define _P10_DDR5_DDIMM_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/utils/find.H>

#include <lib/eff_config/p10_module_specific_engine.H>
#include <lib/eff_config/p10_base_engine.H>

namespace mss
{
namespace spd
{
namespace ddr5
{

///
/// @brief Class for DDIMM SPD Rev 0.3
///
class ddimm_0_0 : public mss::spd::module_specific_base
{

    public:

        ///
        /// @brief Construct a new ddimm rev 0.0 object
        /// @param[in] i_dimm DIMM target
        ///
        ddimm_0_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :
            module_specific_base(i_dimm) {}

        ///
        /// @brief Destroy the ddimm_0_0 object
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

        ///
        /// @brief Get the DIMM type
        /// @return DIMM type value
        ///
        virtual uint8_t get_dimm_type() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM;
        }

        ///
        /// @brief Process the fields for ddimm rev 0.3
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            // Blank for now - this commit is to merge in the skeleton for use
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // TODO: Zen:MST-1426: Add DDIMM module decodes in here, including ody_serial_number
};

} // ddr5

} // spd

}// mss

#endif
