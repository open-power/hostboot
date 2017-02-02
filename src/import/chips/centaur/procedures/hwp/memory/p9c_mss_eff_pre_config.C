/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_pre_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9c_mss_eff_pre_config.C
/// @brief This procedure puts in required attributes for mss_eff_config_thermal which are based on "worst case" config in case these attributes were not able to be setup by mss_eff_config
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C" {
    ///
    /// @brief This procedure puts in required attributes for mss_eff_config_thermal which are based on "worst case" config in case these attributes were not able to be setup by mss_eff_config
    /// @param[in] i_target_mba
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_eff_pre_config(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        constexpr uint32_t MSS_EFF_VALID = 255;

        // Grab DIMM/SPD data.
        uint8_t l_cur_dimm_spd_valid_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_spd_custom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};

        uint8_t l_cur_mba_port = 0;
        uint8_t l_cur_mba_dimm = 0;
        uint32_t l_eff_cen_rcv_imp_dq_dqs_schmoo[MAX_PORTS_PER_MBA] = {0};
        uint32_t l_eff_cen_drv_imp_dq_dqs_schmoo[MAX_PORTS_PER_MBA] = {0};
        uint8_t l_eff_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_eff_num_master_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_eff_dimm_ranks_configed[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_eff_dram_gen = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3;
        uint8_t l_eff_dimm_type = fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM;
        uint8_t l_eff_custom_dimm = fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES;
        uint8_t l_eff_dram_width = fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4;
        uint8_t l_eff_dram_tdqs = fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE;
        uint8_t l_eff_num_drops_per_port = fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_SINGLE;
        const auto l_target_dimm_array = i_target_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

        for (const auto& l_dimm : l_target_dimm_array)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm, l_cur_mba_port));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm, l_cur_mba_dimm));
            l_cur_dimm_spd_valid_u8array[l_cur_mba_port][l_cur_mba_dimm] = MSS_EFF_VALID;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, l_dimm,
                                   l_spd_custom[l_cur_mba_port][l_cur_mba_dimm]));
        }

        if (l_cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
        {
            if (l_spd_custom[0][0] == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES)
            {
                l_eff_custom_dimm = fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES;
            }
            else
            {
                l_eff_custom_dimm = fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_NO;
            }
        }
        else
        {
            FAPI_INF("WARNING: Plug rule violation at %s!", mss::c_str(i_target_mba));
            FAPI_INF("WARNING: Do NOT trust ATTR_EFF_CUSTOM_DIMM for %s!", mss::c_str(i_target_mba));
        }

        for (uint8_t l_cur_port = 0; l_cur_port < MAX_PORTS_PER_MBA; l_cur_port += 1)
        {
            l_eff_cen_rcv_imp_dq_dqs_schmoo[l_cur_port] = 0;
            l_eff_cen_drv_imp_dq_dqs_schmoo[l_cur_port] = 0;

            for (uint8_t l_cur_dimm = 0; l_cur_dimm < MAX_DIMM_PER_PORT; l_cur_dimm += 1)
            {
                l_eff_num_ranks_per_dimm[l_cur_port][l_cur_dimm] = 8;
                l_eff_num_master_ranks_per_dimm[l_cur_port][l_cur_dimm] = 8;
                l_eff_dimm_ranks_configed[l_cur_port][l_cur_dimm] = MSS_EFF_VALID;
            }
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_eff_cen_rcv_imp_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_eff_cen_drv_imp_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba, l_eff_dram_gen));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target_mba, l_eff_dimm_type));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_eff_custom_dimm));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_eff_dram_width));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TDQS, i_target_mba, l_eff_dram_tdqs));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, l_eff_num_ranks_per_dimm));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, l_eff_num_master_ranks_per_dimm));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED, i_target_mba, l_eff_dimm_ranks_configed));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target_mba, l_eff_num_drops_per_port));
    fapi_try_exit:
        return fapi2::current_err;
    }



} // extern "C"
