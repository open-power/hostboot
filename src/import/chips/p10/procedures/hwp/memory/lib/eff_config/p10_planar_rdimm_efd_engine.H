/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_planar_rdimm_efd_engine.H $ */
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
/// @file p10_planar_rdimm_efd_engine.H
/// @brief Planar RDIMM EFD eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_PLANAR_RDIMM_EFD_ENGINE_H_
#define _P10_PLANAR_RDIMM_EFD_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>

#include <mss_explorer_attribute_setters.H>
#include <lib/eff_config/p10_ddimm_efd_engine.H>

namespace mss
{
namespace efd
{

///
/// @brief Class for Planar RDIMM EFD Rev 0.4
///
class planar_rdimm_efd_0_4 : public ddimm_efd_0_4
{
        using RDIMM_F = mss::spd::fields<mss::spd::DDR4, mss::spd::RDIMM_MODULE>;

    public:
        ///
        /// @brief Construct a new planar rdimm efd rev 0.4 object
        ///
        /// @param[in] i_dimm DIMM target
        /// @param[in] i_rank_info the current rank info class
        ///
        planar_rdimm_efd_0_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                             const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info)
            : ddimm_efd_0_4(i_dimm, i_rank_info)
        {
        }

        virtual ~planar_rdimm_efd_0_4() = default;

        ///
        /// @brief Traits for rcd dic 1
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_dic_1(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits for rcd dic 0
        ///
        /// @param[in] i_field field
        /// @return true/false valid value
        /// @note 0.4 revision version
        ///
        virtual bool check_rcd_dic_0(const uint8_t i_field) const
        {
            return true;
        }

        // Virtual function overloads go here

        ///
        /// @brief Set the rcd dic field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note for planar, this info comes from the RDIMM module bytes 137-138 (swizzled)
        ///
        virtual fapi2::ReturnCode set_rcd_dic_planar(const std::vector<uint8_t>& i_spd) const
        {
            constexpr uint8_t FIELD_LEN = 2;
            constexpr uint8_t CKE_DRIVER_START = 8;
            constexpr uint8_t ODT_DRIVER_START = 10;
            constexpr uint8_t CA_DRIVER_START = 14;
            constexpr uint8_t CS_DRIVER_START = 12;
            constexpr uint8_t Y0_Y2_DRIVER_START = 4;
            constexpr uint8_t Y1_Y3_DRIVER_START = 6;

            // Get the data
            fapi2::buffer<uint16_t> l_rcd_dic = 0;
            uint8_t l_cke = 0;
            uint8_t l_odt = 0;
            uint8_t l_ca = 0;
            uint8_t l_cs = 0;
            uint8_t l_y0_y2 = 0;
            uint8_t l_y1_y3 = 0;

            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, RDIMM_F::CKE_DRIVER, i_spd, SET_RCD_DIC, l_cke));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, RDIMM_F::ODT_DRIVER, i_spd, SET_RCD_DIC, l_odt));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, RDIMM_F::CA_DRIVER, i_spd, SET_RCD_DIC, l_ca));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, RDIMM_F::CS_DRIVER, i_spd, SET_RCD_DIC, l_cs));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, RDIMM_F::YO_Y2_DRIVER, i_spd, SET_RCD_DIC, l_y0_y2));
            FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, RDIMM_F::Y1_Y3_DRIVER, i_spd, SET_RCD_DIC, l_y1_y3));

            l_rcd_dic.insertFromRight<CKE_DRIVER_START, FIELD_LEN>(l_cke);
            l_rcd_dic.insertFromRight<ODT_DRIVER_START, FIELD_LEN>(l_odt);
            l_rcd_dic.insertFromRight<CA_DRIVER_START, FIELD_LEN>(l_ca);
            l_rcd_dic.insertFromRight<CS_DRIVER_START, FIELD_LEN>(l_cs);
            l_rcd_dic.insertFromRight<Y0_Y2_DRIVER_START, FIELD_LEN>(l_y0_y2);
            l_rcd_dic.insertFromRight<Y1_Y3_DRIVER_START, FIELD_LEN>(l_y1_y3);

            // Set the attribute
            FAPI_TRY(mss::attr::set_exp_rcd_dic(iv_dimm, l_rcd_dic));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Process any overrides from the base SPD (planar support)
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process_overrides(const std::vector<uint8_t>& i_spd) const
        {
            FAPI_TRY(set_rcd_dic_planar(i_spd));
            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};

//
// Can be updated with the earliest supported planar_rdimm efd revision
//
using planar_rdimm_efd_latest = planar_rdimm_efd_0_4;

}// efd

}// mss

#endif
