/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_mc.C $ */
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
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>
//----------------------------------------------------------------------
//  Address Includes
//----------------------------------------------------------------------
#include <cen_gen_scom_addresses.H>


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
        FAPI_INF( "+++ Setting IML Complete +++");
        FAPI_TRY(mss_set_iml_complete(i_target));

        // Loop through the 2 MBA's
        for (const auto& l_mba : l_mbaChiplets)
        {
            // Step Two: Disable CCS address lines
            FAPI_INF( "+++ Disabling CCS Address Lines +++");
            FAPI_TRY(mss_ccs_mode_reset(l_mba), "---Error During CCS Mode Reset");

            // Step Two.1: Check RCD protect time on RDIMM and LRDIMM
            FAPI_INF( "+++ Check RCD protect time on RDIMM and LRDIMM +++");
            //forced this to only run if the test type is NOT DDR4 - as DDR4 ISRDIMMs are having IPL issues
            //FAPI_TRY(mss_check_RCD_protect_time(l_mba), "---Error During Check RCD protect time");

            //Step Two.2: Enable address inversion on each MBA for ALL CARDS
            FAPI_INF("+++ Setting up adr inversion for port 1 +++");
            FAPI_TRY(mss_enable_addr_inversion(l_mba), "---Error During ADR Inversion");

            // Step Three: Enable Refresh
            FAPI_INF( "+++ Enabling Refresh +++");
            FAPI_TRY(fapi2::getScom(l_mba, CEN_MBA_MBAREF0Q, l_mba01_ref0q_data_buffer_64));

            //Bit 0 is enable
            l_mba01_ref0q_data_buffer_64.setBit<0>();
            FAPI_TRY(fapi2::putScom(l_mba, CEN_MBA_MBAREF0Q, l_mba01_ref0q_data_buffer_64));

            // Step Four: Setup Periodic Cals
            FAPI_INF( "+++ Setting Up Periodic Cals +++");
            FAPI_TRY(mss_enable_periodic_cal(l_mba), "---Error During Periodic Cal Setup and Enable");
        }

        // Step Six: Setup Control Bit ECC
        FAPI_INF( "+++ Setting Up Control Bit ECC +++");
        FAPI_TRY(mss_enable_control_bit_ecc(i_target), "---Error During Control Bit ECC Setup");

        FAPI_TRY(mss_unmask_maint_errors(i_target));
        FAPI_DBG("mss_draminit_mc complete");

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
    ///@brief validate RCD protect time
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_check_RCD_protect_time (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
        uint8_t l_mbaPosition = 0;
        uint8_t l_dimm_type = 0;
        uint8_t l_cfg_wrdone_dly = 0;
        uint8_t l_cfg_rdtag_dly = 0;
        uint8_t l_cfg_rcd_protection_time = 0;
        uint8_t l_highest_cfg_rcd_protection_time = 0;
        uint8_t l_max_cfg_rcd_protection_time = 0;
        uint8_t l_cmdType = 0x10; // DISPLAY, bit 0:5 = 10000b
        uint8_t l_valid_dimms  = 0;
        uint8_t l_valid_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        uint8_t l_dimm_index = 0;
        uint8_t l_target_port = 0;
        uint8_t l_target_dimm = 0;

        uint32_t l_mbeccfir_mask_or_address[MAX_MBA_PER_CEN] =
        {
            // port0/1                            port2/3
            CEN_ECC01_MBECCFIR_MASK_WO_OR, CEN_ECC23_MBECCFIR_MASK_WO_OR
        };

        uint32_t l_mbeccfir_and_address[MAX_MBA_PER_CEN] =
        {
            // port0/1                            port2/3
            CEN_ECC01_MBECCFIR_WOX_AND,  CEN_ECC23_MBECCFIR_WOX_AND
        };

        uint32_t l_mbeccfir_address[MAX_MBA_PER_CEN] =
        {
            // port0/1                            port2/3
            CEN_ECC01_MBECCFIR, CEN_ECC23_MBECCFIR
        };

        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_target_dimm_array;

        fapi2::buffer<uint64_t> l_mbeccfir_mask_or;
        fapi2::buffer<uint64_t> l_mbeccfir_and;
        fapi2::buffer<uint64_t> l_mbeccfir;
        fapi2::buffer<uint64_t> l_mbacalfir_mask_or;
        fapi2::buffer<uint64_t> l_mbacalfir_mask_and;
        fapi2::buffer<uint64_t> l_mbacalfir_and;
        fapi2::buffer<uint64_t> l_mbacalfir;
        fapi2::buffer<uint64_t> l_mba_dsm0;
        fapi2::buffer<uint64_t> l_mba_farb0;
        fapi2::buffer<uint64_t> l_mbmct;
        fapi2::buffer<uint64_t> l_mbmaca;
        fapi2::buffer<uint64_t> l_mbasctl;
        fapi2::buffer<uint64_t> l_mbmcc;
        fapi2::buffer<uint64_t> l_mbafir;
        fapi2::buffer<uint64_t> l_mbmsr;

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
            // Exit if parity error reporting disabled
            //------------------------------------------------------
            // NOTE: This is just to be safe, so we don't create errors in case the initfile is out of sync.
            // Read FARB0
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

            if(l_mba_farb0.getBit<60>())
            {
                FAPI_ERR("Exit mss_check_RCD_protect_time, since parity error reporting disabled on %s.", mss::c_str(i_target));
                return fapi2::FAPI2_RC_FALSE;
            }

            //------------------------------------------------------
            // Enable RCD recovery
            //------------------------------------------------------
            l_mba_farb0.clearBit<54>();

            // Write FARB0
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));


            //------------------------------------------------------
            // Get Centaur target for the given MBA
            //------------------------------------------------------
            l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

            //------------------------------------------------------
            // Get MBA position: 0 = mba01, 1 = mba23
            //------------------------------------------------------
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

            //------------------------------------------------------
            // Find out which DIMMs are functional
            //------------------------------------------------------
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, i_target,  l_valid_dimms));
            l_valid_dimm[0][0] = (l_valid_dimms & 0x80); // port0, dimm0
            l_valid_dimm[0][1] = (l_valid_dimms & 0x40); // port0, dimm1
            l_valid_dimm[1][0] = (l_valid_dimms & 0x08); // port1, dimm0
            l_valid_dimm[1][1] = (l_valid_dimms & 0x04); // port1, dimm1


            //------------------------------------------------------
            // Mask MBECCFIR bit 45: maint RCD parity error
            //------------------------------------------------------
            l_mbeccfir_mask_or.flush<0>();
            // Set bit 45 in the OR mask
            l_mbeccfir_mask_or.setBit<45>();
            // Write OR mask
            FAPI_TRY(fapi2::putScom(l_targetCentaur, l_mbeccfir_mask_or_address[l_mbaPosition], l_mbeccfir_mask_or));


            //------------------------------------------------------
            // Mask MBACALFIR bits 4,7: port0,1 RCD parity error
            //------------------------------------------------------
            l_mbacalfir_mask_or.flush<0>();
            // Set bit 4,7 in the OR mask
            l_mbacalfir_mask_or.setBit<4>();
            l_mbacalfir_mask_or.setBit<7>();
            // Write OR mask
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_OR, l_mbacalfir_mask_or));


            //------------------------------------------------------
            // Find l_max_cfg_rcd_protection_time
            //------------------------------------------------------
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_DSM0Q, l_mba_dsm0));
            // Get 24:29 cfg_wrdone_dly
            FAPI_TRY(l_mba_dsm0.extract(l_cfg_wrdone_dly, 24, 6, 8 - 6));
            // Get 36:41 cfg_rdtag_dly
            FAPI_TRY(l_mba_dsm0.extract(l_cfg_rdtag_dly, 36, 6, 8 - 6));

            // Pick lower of the two: cfg_wrdone_dly and cfg_rdtag_dly, and use that for l_max_cfg_rcd_protection_time
            if (l_cfg_wrdone_dly <= l_cfg_rdtag_dly)
            {
                l_max_cfg_rcd_protection_time = l_cfg_wrdone_dly;
            }
            else
            {
                l_max_cfg_rcd_protection_time = l_cfg_rdtag_dly;
            }

            //------------------------------------------------------
            // Maint cmd setup steps we can do once per MBA
            //------------------------------------------------------

            // Load display cmd type: MBMCT, 0:5 = 10000b
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMCTQ, l_mbmct));
            FAPI_TRY(l_mbmct.insert(l_cmdType, 0, 5, 8 - 5 ));
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMCTQ, l_mbmct));

            // Clear all stop conditions in MBASCTL
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBASCTLQ, l_mbasctl));
            l_mbasctl.clearBit<0, 13>();
            l_mbasctl.clearBit<16>();
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBASCTLQ, l_mbasctl));


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
                        l_mbeccfir_and.flush<1>();
                        // Clear bit 45 in the AND mask
                        l_mbeccfir_and.clearBit<45>();
                        // Write AND mask
                        FAPI_TRY(fapi2::putScom(l_targetCentaur, l_mbeccfir_and_address[l_mbaPosition], l_mbeccfir_and));

                        //------------------------------------------------------
                        // Loop until we find a passing cfg_rcd_protection_time
                        //------------------------------------------------------
                        do
                        {
                            //------------------------------------------------------
                            // Clear MBACALFIR bits 4,7: port0,1 RCD parity error
                            //------------------------------------------------------
                            // NOTE: Clearing these each time so they will be accrate for FFDC
                            l_mbacalfir_and.flush<1>();
                            // Clear bit 4,7 in the AND mask
                            l_mbacalfir_and.clearBit<4>();
                            l_mbacalfir_and.clearBit<7>();
                            // Write AND mask
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIRQ_WOX_AND, l_mbacalfir_and));


                            //------------------------------------------------------
                            // Set l_cfg_rcd_protection_time
                            //------------------------------------------------------
                            // Read FARB0
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

                            // Set cfg_rcd_protection_time
                            FAPI_TRY(l_mba_farb0.insert( l_cfg_rcd_protection_time, 48, 6, 8 - 6 ));


                            //------------------------------------------------------
                            // Arm single shot RCD parity error for the given port
                            //------------------------------------------------------
                            // Select single shot
                            l_mba_farb0.clearBit<59>();

                            if(l_port == 0)
                            {
                                // Select port0 CAS
                                l_mba_farb0.setBit<40>();
                            }
                            else
                            {
                                // Select port1 CAS
                                l_mba_farb0.setBit<42>();
                            }

                            // Write FARB0
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));


                            //------------------------------------------------------
                            // Do single address display cmd
                            //------------------------------------------------------

                            // Load start address in MBMACA for the given DIMM
                            l_mbmaca.flush<0>();

                            if(l_dimm == 1)
                            {
                                l_mbmaca.setBit<1>();
                            }

                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMACAQ, l_mbmaca));

                            // Start the command: MBMCCQ
                            l_mbmcc.flush<0>();
                            l_mbmcc.setBit<0>();
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBMCCQ, l_mbmcc));

                            // Check for MBAFIR[1], invalid maint address.
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBAFIRQ, l_mbafir));

                            FAPI_ASSERT(!l_mbafir.getBit<1>(),
                                        fapi2::CEN_MSS_DRAMINIT_MC_DISPLAY_INVALID_ADDR().
                                        set_MBA(i_target).
                                        set_MBMACA(l_mbmaca).
                                        set_MBAFIR(l_mbafir),
                                        "Display invalid address on port%d, dimm%d, %s.",
                                        l_port, l_dimm, mss::c_str(i_target));

                            // Delay 1 mSec
                            fapi2::delay(DELAY_1MS, DELAY_200000SIMCYCLES);

                            // See if MBMSRQ[0] maint cmd in progress bit if off
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMSRQ, l_mbmsr));

                            // If cmd still in progress
                            FAPI_ASSERT(!l_mbmsr.getBit<1>(),
                                        fapi2::CEN_MSS_DRAMINIT_MC_DISPLAY_TIMEOUT().
                                        set_MBA(i_target).
                                        set_MBMCT(l_mbmct).
                                        set_MBMACA(l_mbmaca).
                                        set_MBASCTL(l_mbasctl).
                                        set_MBMCC(l_mbmcc).
                                        set_MBMSR(l_mbmsr).
                                        set_MBAFIR(l_mbafir),
                                        "Display timeout on %s.", mss::c_str(i_target));

                            // DEBUG Read MBACALFIR
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIRQ, l_mbacalfir));

                            //------------------------------------------------------
                            // Check for MBECCFIR bit 45: maint RCD parity error
                            //------------------------------------------------------

                            FAPI_TRY(fapi2::getScom(l_targetCentaur, l_mbeccfir_address[l_mbaPosition], l_mbeccfir));

                            // If FIR bit set
                            if (l_mbeccfir.getBit<45>())
                            {
                                // Save highest value seen on this MBA
                                if (l_cfg_rcd_protection_time > l_highest_cfg_rcd_protection_time)
                                {
                                    l_highest_cfg_rcd_protection_time = l_cfg_rcd_protection_time;
                                }

                                break; // Exit do-while loop and move on to another DIMM
                            }
                            // Else FIR not set
                            else
                            {
                                // Reached max_cfg_rcd_protection_time
                                if (l_cfg_rcd_protection_time == l_max_cfg_rcd_protection_time)
                                {
                                    FAPI_ERR("Injected RCD parity error detected too late for RCD retry to be effective, max_cfg_rcd_protection_time=%d, port%d, dimm%d, %s",
                                             l_max_cfg_rcd_protection_time, l_port, l_dimm, mss::c_str(i_target));

                                    //Read mbacalfir for FFDC
                                    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIRQ, l_mbacalfir));

                                    // Get DIMM targets for this MBA
                                    l_target_dimm_array = i_target.getChildren<fapi2::TARGET_TYPE_DIMM>();

                                    // Find DIMM target for this l_port and l_dimm
                                    for (l_dimm_index = 0; l_dimm_index < l_target_dimm_array.size(); l_dimm_index ++)
                                    {
                                        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_target_dimm_array[l_dimm_index], l_target_port));
                                        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_target_dimm_array[l_dimm_index], l_target_dimm));

                                        if ((l_target_port == l_port) && (l_target_dimm == l_dimm))
                                        {
                                            break; // Break out of for loop since we found the DIMM target for this l_port and l_dimm
                                        }
                                    }

                                    FAPI_ASSERT(false,
                                                fapi2::CEN_MSS_DRAMINIT_MC_INSUF_RCD_PROTECT_TIME().
                                                set_DIMM(l_target_dimm_array[l_dimm_index]).
                                                set_MBA(i_target).
                                                set_PORT_SELECT(l_port).
                                                set_DIMM_SELECT(l_dimm).
                                                set_CFG_WRDONE_DLY(l_cfg_wrdone_dly).
                                                set_CFG_RDTAG_DLY(l_cfg_rdtag_dly).
                                                set_MAX_CFG_RCD_PROTECTION_TIME(l_max_cfg_rcd_protection_time).
                                                set_MBA_FARB0(l_mba_farb0).
                                                set_MBACALFIR(l_mbacalfir));


                                    break; // Exit do-while loop and move on to another DIMM
                                }

                                // Else increment cfg_rcd_protection_time and try again
                                else
                                {
                                    l_cfg_rcd_protection_time++;
                                }
                            }
                        }
                        while (1);

                    }// End if valid DIMM
                }// End for each DIMM select
            }// End for each port

            //------------------------------------------------------
            // Clear MBECCFIR bit 45
            //------------------------------------------------------
            l_mbeccfir_and.flush<1>();
            // Clear bit 45 in the AND mask
            l_mbeccfir_and.clearBit<45>();
            // Write AND mask
            FAPI_TRY(fapi2::putScom(l_targetCentaur, l_mbeccfir_and_address[l_mbaPosition], l_mbeccfir_and));

            //------------------------------------------------------
            // Clear MBACALFIR bits 4,7: port0,1 RCD parity error
            //------------------------------------------------------
            l_mbacalfir_and.flush<1>();
            // Clear bit 4,7 in the AND mask
            l_mbacalfir_and.clearBit<4>();
            l_mbacalfir_and.clearBit<7>();
            // Write AND mask
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIRQ_WOX_AND, l_mbacalfir_and));

            //------------------------------------------------------
            // Unmask MBACALFIR bits 4,7: port0,1 RCD parity error
            //------------------------------------------------------
            l_mbacalfir_mask_and.flush<1>();
            // Set bit 4,7 in the AND mask
            l_mbacalfir_mask_and.clearBit<4>();
            l_mbacalfir_mask_and.clearBit<7>();
            // Write AND mask
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_AND, l_mbacalfir_mask_and));

            // Read FARB0
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

            //------------------------------------------------------
            // Load l_highest_cfg_rcd_protection_time
            //------------------------------------------------------
            // NOTE: We are loading highest_cfg_rcd_protection_time here just so we can stop after mss_draminit_mc and read out the values from the hw as a way to debug
            // NOTE: The final value we want to load is max_cfg_rcd_protection_time, which we will do in mss_thermal_init, before we enable RCD recovery.
            // NOTE: If no DIMM on this MBA passed, highest_cfg_rcd_protection_time will be 0
            FAPI_TRY(l_mba_farb0.insert( l_highest_cfg_rcd_protection_time, 48, 6, 8 - 6 ));

            //------------------------------------------------------
            // Disable RCD recovery
            //------------------------------------------------------
            l_mba_farb0.setBit<54>();

            // Write FARB0
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBA_FARB0Q, l_mba_farb0));

        } // End if RDIMM or LRDIMM

        FAPI_INF("+++ mss_check_RCD_protect_time complete +++");
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

