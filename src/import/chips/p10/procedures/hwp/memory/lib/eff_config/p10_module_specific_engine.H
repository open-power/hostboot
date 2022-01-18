/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_module_specific_engine.H $ */
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
/// @file p10_module_specific_engine.H
/// @brief Module specific SPD data engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_MODULE_SPECIFIC_ENGINE_ENGINE_H_
#define _P10_MODULE_SPECIFIC_ENGINE_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace spd
{

///
/// @brief Class for base module specific section of SPD - generic to all DRAM generations
///
class module_specific_base
{
    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_port;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;

    public:

        ///
        /// @brief Construct a new module_specific_base object
        /// @param[in] i_dimm DIMM target
        ///
        module_specific_base(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :
            iv_dimm(i_dimm),
            iv_port(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm)),
            iv_ocmb(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm)) {}

        ///
        /// @brief Destroy the module_specific_base object
        ///
        virtual ~module_specific_base() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const = 0;

        ///
        /// @brief Get the DRAM generation
        /// @return DRAM generation value
        ///
        virtual uint8_t get_dram_generation() const = 0;

        ///
        /// @brief Get the DIMM type
        /// @return DIMM type value
        ///
        virtual uint8_t get_dimm_type() const = 0;

        /// @brief Process the fields for ddimm efd rev 0.4
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const = 0;
};

} // spd

}// mss

#endif
