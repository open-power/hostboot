/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_mc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file p9c_mss_draminit_mc.C
/// @brief Procedure for handing over control to the MC
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///


//Run cen_draminit_mc.C to complete the initialization sequence. This performs the steps of
//***Set the IML Complete bit MBSSQ(2) (SCOM Addr: 0x02011417) to indicate that IML has completed
//***Start the refresh engines
//***Enabling periodic calibration and power management.

//----------------------------------------------------------------------
//  FAPI Includes
//----------------------------------------------------------------------
#include <fapi2.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <p9c_mss_funcs.H>
#include <p9c_mss_unmask_errors.H>
#include <p9c_mss_draminit_mc.H>
#include <p9c_mss_row_repair.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/cumulus_find.H>
#include <dimmConsts.H>
//----------------------------------------------------------------------
//  Address Includes
//----------------------------------------------------------------------
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>


extern "C" {
    ///
    /// @brief Draminit MC procedure. Enable MC functions and set IML complete within centaur
    /// @param[in]  i_target  Reference to centaur target
    /// @return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_draminit_mc(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
    {
        fapi2::buffer<uint64_t> l_mba01_ref0q_data_buffer_64;
        // Get associated MBA's on this centaur
        const auto l_mbaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MBA>();

        // Step One: Set IML COMPLETE
        FAPI_INF( "%s +++ Setting IML Complete +++", mss::c_str(i_target));
        FAPI_TRY(mss_set_iml_complete(i_target));

        // Loop through the 2 MBA's
        for (const auto& l_mba : l_mbaChiplets)
        {
            // Step Two: Disable CCS address lines
            FAPI_INF( "%s +++ Disabling CCS Address Lines +++", mss::c_str(i_target));
            FAPI_TRY(mss_ccs_mode_reset(l_mba), "---Error During CCS Mode Reset");

            // Step Two.1: Check RCD protect time on RDIMM and LRDIMM
            FAPI_INF( "%s +++ Check RCD protect time on RDIMM and LRDIMM +++", mss::c_str(i_target));
            FAPI_TRY(mss_check_RCD_protect_time(l_mba), "---Error During Check RCD protect time");

            //Step Two.2: Apply row repairs on each MBA's DIMM
            FAPI_INF( "%s +++ Applying sPPR row repairs +++", mss::c_str(i_target));
            FAPI_TRY(p9c_mss_deploy_row_repairs(l_mba), "---Error During Row Reapirs");

            //Step Two.3: Enable address inversion on each MBA for ALL CARDS
            FAPI_INF( "%s +++ Setting up adr inversion for port 1 +++", mss::c_str(i_target));
            FAPI_TRY(mss_enable_addr_inversion(l_mba), "---Error During ADR Inversion");

            // Step Three: Enable Refresh
            FAPI_INF( "%s +++ Enabling Refresh +++", mss::c_str(i_target));
            FAPI_TRY(fapi2::getScom(l_mba, CEN_MBA_MBAREF0Q, l_mba01_ref0q_data_buffer_64));

            //Bit 0 is enable
            l_mba01_ref0q_data_buffer_64.setBit<CEN_MBA_MBAREF0Q_CFG_REFRESH_ENABLE>();
            FAPI_TRY(fapi2::putScom(l_mba, CEN_MBA_MBAREF0Q, l_mba01_ref0q_data_buffer_64));

            // Step Four: Setup Periodic Cals
            FAPI_INF( "%s +++ Setting Up Periodic Cals +++", mss::c_str(i_target));
            FAPI_TRY(mss_enable_periodic_cal(l_mba), "---Error During Periodic Cal Setup and Enable");
        }

        // Step Six: Setup Control Bit ECC
        FAPI_INF( "%s +++ Setting Up Control Bit ECC +++", mss::c_str(i_target));
        FAPI_TRY(mss_enable_control_bit_ecc(i_target), "---Error During Control Bit ECC Setup");

        FAPI_TRY(mss_unmask_maint_errors(i_target));
        FAPI_DBG( "%s mss_draminit_mc complete", mss::c_str(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief Enable periodic calibration on centaur
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_periodic_cal (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        //Procedure to setup and enable periodic cals
        uint8_t l_attr_centaur_ec_rdclk_pr_update_hw236658_fixed = 0;

        //Find Parent chip for EC check
        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint32_t l_memcal_interval = 0; //  00 = Disable
        uint32_t l_zq_cal_interval = 0; //  00 = Disable

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MEMCAL_INTERVAL, i_target,  l_memcal_interval));
        //Determine what type of Centaur this is
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_ZQCAL_INTERVAL, i_target,  l_zq_cal_interval));

        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_CAL0Q, l_data_buffer_64));
        FAPI_INF("+++ Enabling Periodic Calibration +++");

        if (l_zq_cal_interval != 0)
        {
            //ZQ Cal Enabled
            l_data_buffer_64.setBit<0>();
            FAPI_INF("+++ Periodic Calibration: ZQ Cal Enabled +++");
        }
        else
        {
            //ZQ Cal Disabled
            l_data_buffer_64.clearBit<0>();
            FAPI_INF("+++ Periodic Calibration: ZQ Cal Disabled +++");
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_CAL0Q, l_data_buffer_64));

        if (l_memcal_interval != 0)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_RDCLK_PR_UPDATE_HW236658_FIXED, l_target_centaur,
                                   l_attr_centaur_ec_rdclk_pr_update_hw236658_fixed));

            if(!l_attr_centaur_ec_rdclk_pr_update_hw236658_fixed)
            {
                //Check EC, Disable Phase Select Update for DD2 HW
                //Phase Select Fix for DD1.1
                l_data_buffer_64.flush<0>();
                l_data_buffer_64.setBit<52>();

                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P0_0, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P0_1, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P0_2, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P0_3, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P0_4, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P1_0, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P1_1, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P1_2, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P1_3, l_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_DP18_RD_DIA_CONFIG5_P1_4, l_data_buffer_64));
            }

            //Disable Periodic Read Centering for ALL HW
            l_data_buffer_64.flush<0>();
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_PER_CAL_CONFIG_P0, l_data_buffer_64));
            l_data_buffer_64.clearBit<54>();
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_PER_CAL_CONFIG_P0, l_data_buffer_64));

            l_data_buffer_64.flush<0>();
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_PER_CAL_CONFIG_P1, l_data_buffer_64));
            l_data_buffer_64.clearBit<54>();
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_PER_CAL_CONFIG_P1, l_data_buffer_64));

            //Mem Cal Enabled
            l_data_buffer_64.flush<0>();
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_CAL1Q, l_data_buffer_64));
            l_data_buffer_64.setBit<0>();
            FAPI_INF("+++ Periodic Calibration: Mem Cal Enabled +++");
        }
        else
        {
            //Mem Cal Disabled
            l_data_buffer_64.flush<0>();
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_CAL1Q, l_data_buffer_64));
            l_data_buffer_64.clearBit<0>();
            FAPI_INF("+++ Periodic Calibration: Mem Cal Disabled +++");
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_CAL1Q, l_data_buffer_64));

    fapi_try_exit:
        return fapi2::current_err;

    }

    ///
    ///@brief Set IML complete bit
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_set_iml_complete (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
    {
        //Set IML Complete
        fapi2::buffer<uint64_t> l_data_buffer_64;
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBSSQ_ROX, l_data_buffer_64));
        l_data_buffer_64.setBit<2>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBSSQ_ROX, l_data_buffer_64));
        FAPI_INF("+++ IML Complete Enabled +++");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief Enable ECC checks
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_control_bit_ecc (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
    {
        //Enable Control Bit ECC
        fapi2::buffer<uint64_t> l_ecc0_data_buffer_64;
        fapi2::buffer<uint64_t> l_ecc1_data_buffer_64;
        uint8_t attr_centaur_ec_enable_rce_with_other_errors_hw246685 = 0;

        FAPI_TRY(fapi2::getScom(i_target, CEN_ECC01_MBSECCQ, l_ecc0_data_buffer_64));
        FAPI_TRY(fapi2::getScom(i_target, CEN_ECC23_MBSECCQ, l_ecc1_data_buffer_64));

        // Enable Memory ECC Check/Correct for MBA01
        // This assumes that all other settings of this register
        // are set in previous precedures or initfile.
        l_ecc0_data_buffer_64.clearBit<0>();
        l_ecc0_data_buffer_64.clearBit<1>();
        l_ecc0_data_buffer_64.setBit<3>();

        // Enable Memory ECC Check/Correct for MBA23
        // This assumes that all other settings of this register
        // are set in previous precedures or initfile.
        l_ecc1_data_buffer_64.clearBit<0>();
        l_ecc1_data_buffer_64.clearBit<1>();
        l_ecc1_data_buffer_64.setBit<3>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685, i_target,
                               attr_centaur_ec_enable_rce_with_other_errors_hw246685));

        if(attr_centaur_ec_enable_rce_with_other_errors_hw246685)
        {
            l_ecc0_data_buffer_64.setBit<16>();
            l_ecc1_data_buffer_64.setBit<16>();
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_ECC01_MBSECCQ, l_ecc0_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target, CEN_ECC23_MBSECCQ, l_ecc1_data_buffer_64));
        FAPI_INF("+++ mss_enable_control_bit_ecc complete +++");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief Enable power management and domain control
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_power_management (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        //Enable Power Management
        fapi2::buffer<uint64_t> l_pm_data_buffer_64;
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBARPC0Q, l_pm_data_buffer_64));

        // Enable power domain control
        // This assumes that all other settings of this register
        // are set in previous precedures or initfile.
        l_pm_data_buffer_64.setBit<2>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBARPC0Q, l_pm_data_buffer_64));

        FAPI_INF("+++ mss_enable_power_management complete +++");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief Switch address mux from CCS logic to mainline logic
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_ccs_mode_reset (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        //Selects address data from the mainline
        fapi2::buffer<uint64_t> l_ccs_mode_data_buffer_64;
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_ccs_mode_data_buffer_64));
        l_ccs_mode_data_buffer_64.clearBit<29>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_ccs_mode_data_buffer_64));

        FAPI_INF("+++ mss_ccs_mode_reset complete +++");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Checks parity error reporting and sets up RCD recovery
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode check_parity_and_enable_rcd_recovery(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_mba_farb0;
        //------------------------------------------------------
        // Exit if parity error reporting disabled
        //------------------------------------------------------
        // NOTE: This is just to be safe, so we don't create errors in case the initfile is out of sync.
        // Read FARB0
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

        // We're ok if bit ignoring RCD parity (bit 60) is not set...
        FAPI_ASSERT(!l_mba_farb0.getBit<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_IGNORE_RCD_PARITY_ERR>(),
                    fapi2::CEN_MSS_DRAMINIT_MC_PARITY_CHECKING_DISABLED()
                    .set_MBA(i_target)
                    .set_MBA_FARB0(l_mba_farb0),
                    "Exit mss_check_RCD_protect_time, since parity error reporting disabled on %s.", mss::c_str(i_target));

        //------------------------------------------------------
        // Enable RCD recovery
        //------------------------------------------------------
        l_mba_farb0.clearBit<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_DISABLE_RCD_RECOVERY>();

        // Write FARB0
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Sets up the firs for the RCD response time calibration
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode setup_firs_for_rcd_response_time_calibration(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_mbeccfir_mask_or;
        fapi2::buffer<uint64_t> l_mbacalfir_mask_or;

        constexpr uint32_t l_mbeccfir_mask_or_address[MAX_MBA_PER_CEN] =
        {
            // port0/1                            port2/3
            CEN_ECC01_MBECCFIR_MASK_WO_OR, CEN_ECC23_MBECCFIR_MASK_WO_OR
        };

        //------------------------------------------------------
        // Get MBA position: 0 = mba01, 1 = mba23
        //------------------------------------------------------
        uint8_t l_mbaPosition = 0;

        const auto& l_cen = mss::find_target<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_target);
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

        //------------------------------------------------------
        // Mask MBECCFIR bit 45: maint RCD parity error
        //------------------------------------------------------
        // Set bit 45 in the OR mask
        l_mbeccfir_mask_or.setBit<CEN_ECC01_MBECCFIR_MAINTENANCE_RCD_PARITY_ERROR>();
        // Write OR mask
        FAPI_TRY(fapi2::putScom(l_cen, l_mbeccfir_mask_or_address[l_mbaPosition], l_mbeccfir_mask_or));

        //------------------------------------------------------
        // Mask MBACALFIR bits 4,7: port0,1 RCD parity error
        //------------------------------------------------------
        // Set bit 4,7 in the OR mask
        l_mbacalfir_mask_or.setBit<CEN_MBA_MBACALFIRQ_RCD_PARITY_ERROR_0>();
        l_mbacalfir_mask_or.setBit<CEN_MBA_MBACALFIRQ_RCD_PARITY_ERROR_1>();
        // Write OR mask
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_OR, l_mbacalfir_mask_or));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Finds the maximum allowable RCD protect time
    /// @param[in] i_target MBA target
    /// @param[out] o_max_rcd_protect maximum allowable RCD protect time
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode find_max_rcd_protect_time(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t& o_max_rcd_protect)
    {
        fapi2::buffer<uint64_t> l_mba_dsm0;
        o_max_rcd_protect = 0;
        uint8_t l_cfg_wrdone_dly = 0;
        uint8_t l_cfg_rdtag_dly = 0;
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_DSM0Q, l_mba_dsm0));
        // Get 24:29 cfg_wrdone_dly
        l_mba_dsm0.extractToRight<CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_WRDATA_DLY, CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_WRDATA_DLY_LEN>
        (l_cfg_wrdone_dly);
        // Get 36:41 cfg_rdtag_dly
        l_mba_dsm0.extractToRight<CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_RDTAG_DLY, CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_RDTAG_DLY_LEN>
        (l_cfg_rdtag_dly);

        // Pick lower of the two: cfg_wrdone_dly and cfg_rdtag_dly, and use that for l_max_cfg_rcd_protection_time
        o_max_rcd_protect = std::min(l_cfg_wrdone_dly, l_cfg_rdtag_dly);
        FAPI_DBG("%s 0x%016lx %d %d %d", mss::c_str(i_target), l_mba_dsm0, l_cfg_wrdone_dly, l_cfg_rdtag_dly,
                 o_max_rcd_protect);

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Loads the RCD protection maint commands
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode load_rcd_protect_maint_cmd(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        // Constexpr's for beautification
        // Note: these are a conglomeration of a bunch of stop conditions, so no official values exist for them
        constexpr uint64_t STOP_CONDITION = 0;
        constexpr uint64_t STOP_CONDITION_LEN = 13;

        fapi2::buffer<uint64_t> l_data;
        // DISPLAY, bit 0:5 = 10000b
        constexpr uint8_t DISPLAY_CMD = 0x10;

        // Load display cmd type: MBMCT, 0:5 = 10000b
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMCTQ, l_data));
        l_data.insertFromRight<CEN_MBA_MBMCTQ_MAINT_CMD_TYPE, CEN_MBA_MBMCTQ_MAINT_CMD_TYPE_LEN>(DISPLAY_CMD);
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMCTQ, l_data));

        // Clear all stop conditions in MBASCTL
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBASCTLQ, l_data));
        l_data.clearBit<STOP_CONDITION, STOP_CONDITION_LEN>();
        l_data.clearBit<CEN_MBA_MBASCTLQ_MBSPA_BIT_0_MODE>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBASCTLQ, l_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

    static constexpr uint32_t l_mbeccfir_and_address[MAX_MBA_PER_CEN] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_WOX_AND,  CEN_ECC23_MBECCFIR_WOX_AND
    };

    ///
    /// @brief Clears the RCD parity FIR bit
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode clear_rcd_parity_fir(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_data;
        l_data.flush<1>();
        // Clears the RCD parity FIR (bit 45) in the AND mask
        l_data.clearBit<CEN_ECC01_MBECCFIR_MAINTENANCE_RCD_PARITY_ERROR>();

        const auto& l_cen = mss::find_target<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_target);
        uint8_t l_mbaPosition = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));
        // Write AND mask
        FAPI_TRY(fapi2::putScom(l_cen, l_mbeccfir_and_address[l_mbaPosition], l_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Clears the RCD parity FIR bit
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode clear_rcd_parity_mbacal_fir(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_data;
        l_data.flush<1>();
        // Clear RCD parity bits (bit 4,7) in the AND mask
        l_data.clearBit<CEN_MBA_MBACALFIRQ_RCD_PARITY_ERROR_0>();
        l_data.clearBit<CEN_MBA_MBACALFIRQ_RCD_PARITY_ERROR_1>();
        // Write AND mask
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIRQ_WOX_AND, l_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Sets up the RCD protect time
    /// @param[in] i_time the RCD protect time
    /// @param[in,out] io_data the data buffer to modify
    ///
    void set_rcd_protect_time(const uint8_t i_time, fapi2::buffer<uint64_t>& io_data)
    {
        // Set cfg_rcd_protection_time
        io_data.insertFromRight<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_RCD_PROTECTION_TIME,
                                CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_RCD_PROTECTION_TIME_LEN>( i_time );
    }

    ///
    /// @brief Sets up the RCD parity inject
    /// @param[in] i_port the port on which to do the inject
    /// @param[in,out] io_data the data buffer to modify
    ///
    void set_rcd_inject(const uint8_t i_port, fapi2::buffer<uint64_t>& io_data)
    {
        // Select single shot
        io_data.clearBit<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_INJECT_PARITY_ERR_CONSTANT>();

        if(i_port == 0)
        {
            // Select port0 CAS
            io_data.setBit<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_INJECT_PARITY_ERR_CAS0>();
        }
        else
        {
            // Select port1 CAS
            io_data.setBit<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_INJECT_PARITY_ERR_CAS1>();
        }
    }

    ///
    /// @brief Setup RCD parity inject and time
    /// @param[in] i_target MBA target
    /// @param[in] i_time the RCD protect time
    /// @param[in] i_port the port on which to operate
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode setup_rcd_protect_inject_time(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_time,
            const uint8_t i_port)
    {
        fapi2::buffer<uint64_t> l_data;
        // Read FARB0
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_data));

        // Sets up the RCD protect time
        set_rcd_protect_time(i_time, l_data);

        // Sets up the RCD inject
        set_rcd_inject(i_port, l_data);

        // Write FARB0
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Setup RCD parity inject and time
    /// @param[in] i_target MBA target
    /// @param[in] i_dimm the DIMM number on which to operate
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode start_single_address_maint(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_dimm)
    {
        fapi2::buffer<uint64_t> l_data;

        // Load start address in MBMACA for the given DIMM
        if(i_dimm == 1)
        {
            l_data.setBit<CEN_MBA_MBMACAQ_CMD_DIMM_SELECT>();
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMACAQ, l_data));

        // Start the command: MBMCCQ
        l_data.flush<0>();
        l_data.setBit<CEN_MBA_MBMCCQ_MAINT_CMD_START>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMCCQ, l_data));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Checks the maintenance engine's address FIR for errors
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode check_maint_fir(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_data;

        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBAFIRQ, l_data));

        if(l_data.getBit<CEN_MBA_MBAFIRQ_INVALID_MAINT_ADDRESS>())
        {
            fapi2::buffer<uint64_t> l_mbmaca;
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMACAQ, l_mbmaca));

            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_DRAMINIT_MC_DISPLAY_INVALID_ADDR().
                        set_MBA(i_target).
                        set_MBMACA(l_mbmaca).
                        set_MBAFIR(l_data),
                        "Display invalid address on %s.",
                        mss::c_str(i_target));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Checks the maintenance engine's address FIR for errors
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode check_maint_timeout(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_data;

        // Delay 1 mSec
        fapi2::delay(DELAY_1MS, DELAY_200000SIMCYCLES);

        // See if MBMSRQ[0] maint cmd in progress bit if off
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMSRQ, l_data));

        // If cmd still in progress
        if(l_data.getBit<CEN_MBA_MBMSRQ_MAINT_CMD_IP>())
        {
            fapi2::buffer<uint64_t> l_mbmct;
            fapi2::buffer<uint64_t> l_mbmaca;
            fapi2::buffer<uint64_t> l_mbasctl;
            fapi2::buffer<uint64_t> l_mbmcc;
            fapi2::buffer<uint64_t> l_mbafir;
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMCTQ, l_mbmct));
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMACAQ, l_mbmaca));
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBASCTLQ, l_mbasctl));
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMCCQ, l_mbmcc));
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBAFIRQ, l_mbafir));

            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_DRAMINIT_MC_DISPLAY_TIMEOUT().
                        set_MBA(i_target).
                        set_MBMCT(l_mbmct).
                        set_MBMACA(l_mbmaca).
                        set_MBASCTL(l_mbasctl).
                        set_MBMCC(l_mbmcc).
                        set_MBMSR(l_data).
                        set_MBAFIR(l_mbafir),
                        "Display timeout on %s.", mss::c_str(i_target));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Processes the RCD timeout results
    /// @param[in] i_target MBA target
    /// @param[in] i_port the port on which the code is operating
    /// @param[in] i_dimm the DIMM on which the code is operating
    /// @param[in] i_max_cfg_rcd_protection_time maximum allowable configuration time
    /// @param[in,out] io_cfg_rcd_protection_time current RCD protection time
    /// @param[in,out] io_highest_cfg_rcd_protection_time highest configuration time from all calibrated ports
    /// @param[out] o_loop_done true if the RCD error was found and the current loop is done
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode process_rcd_timeout_results(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port,
            const uint8_t i_dimm,
            const uint8_t i_max_cfg_rcd_protection_time,
            uint8_t& io_cfg_rcd_protection_time,
            uint8_t& io_highest_cfg_rcd_protection_time,
            bool& o_loop_done)
    {
        fapi2::buffer<uint64_t> l_mbeccfir;
        constexpr uint32_t l_mbeccfir_address[MAX_MBA_PER_CEN] =
        {
            // port0/1                            port2/3
            CEN_ECC01_MBECCFIR, CEN_ECC23_MBECCFIR
        };

        const auto& l_cen = mss::find_target<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_target);
        o_loop_done = false;
        uint8_t l_mbaPosition = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

        FAPI_TRY(fapi2::getScom(l_cen, l_mbeccfir_address[l_mbaPosition], l_mbeccfir));

        // If FIR bit set
        if (l_mbeccfir.getBit<CEN_ECC01_MBECCFIR_MAINTENANCE_RCD_PARITY_ERROR>())
        {
            // Save highest value seen on this MBA
            if (io_cfg_rcd_protection_time > io_highest_cfg_rcd_protection_time)
            {
                io_highest_cfg_rcd_protection_time = io_cfg_rcd_protection_time;
            }

            // Exit do-while loop and move on to another DIMM
            o_loop_done = true;
        }
        // Else FIR not set
        else
        {
            // Reached max_cfg_rcd_protection_time
            if (io_cfg_rcd_protection_time >= i_max_cfg_rcd_protection_time)
            {
                FAPI_ERR("Injected RCD parity error detected too late for RCD retry to be effective, max_cfg_rcd_protection_time=%d, port%d, dimm%d, %s",
                         i_max_cfg_rcd_protection_time, i_port, i_dimm, mss::c_str(i_target));

                fapi2::buffer<uint64_t> l_mbacalfir;
                fapi2::buffer<uint64_t> l_mba_farb0;
                fapi2::buffer<uint64_t> l_mba_dsm0;
                uint8_t l_dimm_index = 0;
                uint8_t l_cfg_wrdone_dly = 0;
                uint8_t l_cfg_rdtag_dly = 0;

                //Read mbacalfir for FFDC
                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIRQ, l_mbacalfir));
                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));
                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_dsm0));
                l_mba_dsm0.extractToRight<CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_WRDATA_DLY, CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_WRDATA_DLY_LEN>
                (l_cfg_wrdone_dly);
                l_mba_dsm0.extractToRight<CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_RDTAG_DLY, CEN_MBA_MBA_DSM0Q_DSM0Q_CFG_RDTAG_DLY_LEN>
                (l_cfg_rdtag_dly);

                // Get DIMM targets for this MBA
                const auto& l_target_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

                // Find DIMM target for this i_port and i_dimm
                for (l_dimm_index = 0; l_dimm_index < l_target_dimms.size(); l_dimm_index++)
                {
                    uint8_t l_target_port = 0;
                    uint8_t l_target_dimm = 0;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_target_dimms[l_dimm_index], l_target_port));
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_target_dimms[l_dimm_index], l_target_dimm));

                    if ((l_target_port == i_port) && (l_target_dimm == i_dimm))
                    {
                        break; // Break out of for loop since we found the DIMM target for this i_port and i_dimm
                    }
                }

                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_DRAMINIT_MC_INSUF_RCD_PROTECT_TIME().
                            set_DIMM(l_target_dimms[l_dimm_index]).
                            set_MBA(i_target).
                            set_PORT_SELECT(i_port).
                            set_DIMM_SELECT(i_dimm).
                            set_CFG_WRDONE_DLY(l_cfg_wrdone_dly).
                            set_CFG_RDTAG_DLY(l_cfg_rdtag_dly).
                            set_MAX_CFG_RCD_PROTECTION_TIME(i_max_cfg_rcd_protection_time).
                            set_MBA_FARB0(l_mba_farb0).
                            set_MBACALFIR(l_mbacalfir));

                // Including this in here for safety's sake
                o_loop_done = true;
            }

            // Else increment cfg_rcd_protection_time and try again
            else
            {
                io_cfg_rcd_protection_time++;
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Sets up the FIR mask for the RCD parity error in mainline
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode setup_firs_mask_rcd_parity_mainline(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_mbacalfir_mask_and;
        l_mbacalfir_mask_and.flush<1>();
        // Set bit 4,7 in the AND mask
        l_mbacalfir_mask_and.clearBit<CEN_MBA_MBACALFIRQ_RCD_PARITY_ERROR_0>();
        l_mbacalfir_mask_and.clearBit<CEN_MBA_MBACALFIRQ_RCD_PARITY_ERROR_1>();
        // Write AND mask
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_AND, l_mbacalfir_mask_and));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief validate RCD protect time
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_check_RCD_protect_time (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
        uint8_t l_dimm_type = 0;
        uint8_t l_cfg_rcd_protection_time = 0;
        uint8_t l_highest_cfg_rcd_protection_time = 0;
        uint8_t l_max_cfg_rcd_protection_time = 0;
        uint8_t l_valid_dimms  = 0;
        uint8_t l_valid_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;

        fapi2::buffer<uint64_t> l_mba_farb0;
        FAPI_INF("%s starting mss_check_RCD_protect_time", mss::c_str(i_target));

        //------------------------------------------------------
        // Get DIMM type
        //------------------------------------------------------
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target,  l_dimm_type));

        //------------------------------------------------------
        // Only run on RDIMM or LRDIMM
        //------------------------------------------------------
        if ((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
            || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM))
        {
            //------------------------------------------------------
            // Get Centaur target for the given MBA
            //------------------------------------------------------
            l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

            // Checks parity checking is setup correctly and enables RCD recovery
            FAPI_TRY(check_parity_and_enable_rcd_recovery(i_target));

            //------------------------------------------------------
            // Find out which DIMMs are functional
            //------------------------------------------------------
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, i_target,  l_valid_dimms));
            l_valid_dimm[0][0] = (l_valid_dimms & 0x80); // port0, dimm0
            l_valid_dimm[0][1] = (l_valid_dimms & 0x40); // port0, dimm1
            l_valid_dimm[1][0] = (l_valid_dimms & 0x08); // port1, dimm0
            l_valid_dimm[1][1] = (l_valid_dimms & 0x04); // port1, dimm1

            // Sets up the FIRs for RCD parity response calibration
            FAPI_TRY(setup_firs_for_rcd_response_time_calibration(i_target));

            //------------------------------------------------------
            // Find l_max_cfg_rcd_protection_time
            //------------------------------------------------------
            FAPI_TRY(find_max_rcd_protect_time(i_target, l_max_cfg_rcd_protection_time));

            //------------------------------------------------------
            // Maint cmd setup steps we can do once per MBA
            //------------------------------------------------------
            FAPI_TRY(load_rcd_protect_maint_cmd(i_target));

            //------------------------------------------------------
            // For each port in the given MBA:0,1
            //------------------------------------------------------
            for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++ )
            {
                //------------------------------------------------------
                // For each DIMM select on the given port:0,1
                //------------------------------------------------------
                for(l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++ )
                {
                    //------------------------------------------------------
                    // If DIMM valid
                    //------------------------------------------------------
                    if (l_valid_dimm[l_port][l_dimm])
                    {
                        //------------------------------------------------------
                        // Start with cfg_rcd_protection_time of 8
                        //------------------------------------------------------
                        l_cfg_rcd_protection_time = 8;

                        //------------------------------------------------------
                        // Clear MBECCFIR bit 45: maint RCD parity error
                        //------------------------------------------------------
                        FAPI_TRY(clear_rcd_parity_fir(i_target));

                        //------------------------------------------------------
                        // Loop until we find a passing cfg_rcd_protection_time
                        //------------------------------------------------------
                        bool l_loop_done = false;

                        do
                        {
                            //------------------------------------------------------
                            // Clear MBACALFIR bits 4,7: port0,1 RCD parity error
                            //------------------------------------------------------
                            // NOTE: Clearing these each time so they will be accurate for FFDC
                            FAPI_TRY(clear_rcd_parity_mbacal_fir(i_target));

                            //------------------------------------------------------
                            // Set l_cfg_rcd_protection_time
                            //------------------------------------------------------
                            //------------------------------------------------------
                            // Arm single shot RCD parity error for the given port
                            //------------------------------------------------------
                            FAPI_TRY(setup_rcd_protect_inject_time(i_target, l_cfg_rcd_protection_time, l_port));

                            //------------------------------------------------------
                            // Do single address display cmd
                            //------------------------------------------------------
                            FAPI_TRY(start_single_address_maint(i_target, l_dimm));

                            // Check for MBAFIR[1], invalid maint address.
                            FAPI_TRY(check_maint_fir(i_target));

                            // Checks for a maintenance timeout
                            FAPI_TRY(check_maint_timeout(i_target));

                            //------------------------------------------------------
                            // Check for MBECCFIR bit 45: maint RCD parity error
                            //------------------------------------------------------
                            FAPI_TRY(process_rcd_timeout_results(i_target, l_port, l_dimm, l_max_cfg_rcd_protection_time, l_cfg_rcd_protection_time,
                                                                 l_highest_cfg_rcd_protection_time, l_loop_done));
                        }
                        while (!l_loop_done);

                    }// End if valid DIMM
                }// End for each DIMM select
            }// End for each port

            //------------------------------------------------------
            // Clear MBECCFIR bit 45: maint RCD parity error
            //------------------------------------------------------
            FAPI_TRY(clear_rcd_parity_fir(i_target));

            //------------------------------------------------------
            // Clear MBACALFIR bits 4,7: port0,1 RCD parity error
            //------------------------------------------------------
            FAPI_TRY(clear_rcd_parity_mbacal_fir(i_target));

            //------------------------------------------------------
            // Unmask MBACALFIR bits 4,7: port0,1 RCD parity error
            //------------------------------------------------------
            FAPI_TRY(setup_firs_mask_rcd_parity_mainline(i_target));

            // Read FARB0
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

            //------------------------------------------------------
            // Load l_highest_cfg_rcd_protection_time
            //------------------------------------------------------
            // NOTE: We are loading highest_cfg_rcd_protection_time here just so we can stop after mss_draminit_mc and read out the values from the hw as a way to debug
            // NOTE: The final value we want to load is max_cfg_rcd_protection_time, which we will do in mss_thermal_init, before we enable RCD recovery.
            // NOTE: If no DIMM on this MBA passed, highest_cfg_rcd_protection_time will be 0
            set_rcd_protect_time( l_highest_cfg_rcd_protection_time, l_mba_farb0 );

            //------------------------------------------------------
            // Disable RCD recovery
            //------------------------------------------------------
            l_mba_farb0.setBit<CEN_MBA_MBA_FARB0Q_FARB0Q_CFG_DISABLE_RCD_RECOVERY>();

            // Write FARB0
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

        } // End if RDIMM or LRDIMM

        FAPI_INF("+++ %s mss_check_RCD_protect_time complete +++", mss::c_str(i_target));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief Disable spare CKE
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_spare_cke_disable (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        //Selects address data from the mainline
        fapi2::buffer<uint64_t> l_spare_cke_data_buffer_64;

        //Setup SPARE CKE enable bit
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBARPC0Q, l_spare_cke_data_buffer_64));
        l_spare_cke_data_buffer_64.clearBit<42>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBARPC0Q, l_spare_cke_data_buffer_64));

        FAPI_INF("+++ mss_spare_cke_disable complete +++");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    ///@brief Enable port 1 address inversion
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_addr_inversion (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        //Sets address inversion on port 1 of an MBA
        fapi2::buffer<uint64_t> l_mba_farb0_db_64;
        //Set bit 56 for adr inversion on port 1
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0_db_64));
        l_mba_farb0_db_64.setBit<56>();
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0_db_64));

        FAPI_INF("+++ mss_enable_addr_inversion complete +++");
    fapi_try_exit:
        return fapi2::current_err;
    }
} //end extern C

