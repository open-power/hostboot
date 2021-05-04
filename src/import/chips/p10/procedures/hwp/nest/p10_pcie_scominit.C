/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_pcie_scominit.C
/// @brief Perform PCIE SCOM initialization (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

///
/// *HWP HW Maintainer: Ricardo Mata Jr. (ricmata@us.ibm.com)
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pcie_scominit.H>
#include <p10_pcie_scom.H>
#include <p10_scom_pec.H>
#include <p10_scom_phb.H>
#include <p10_fbc_utils.H>
#include <p10_iop_xram_utils.H>
#include <p10_phb_hv_access.H>
#include <p10_phb_hv_utils.H>
// Cronus only
#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
    #include <p10_pcie_utils.H>
#endif

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------
const uint8_t TC_PCI_IOVALID_DC_START = 8;
const uint8_t TC_PCI_SWAP_DC_START = 2;
const uint8_t NUM_STACK_CONFIG = 3;
const uint8_t NUM_OF_INSTANCES = 4;
const uint64_t PIPEDOUTCTL2_OFFSET = 22;
const uint64_t PIPEDOUTCTL0_OFFSET = 20;
const uint64_t NANO_SEC_DELAY = 1000000;
const uint64_t SIM_CYC_DELAY = 512;
const uint64_t MICRO_SEC_DELAY = 1000;

//Maximum number of iterations (So, 1ms * 100 = 100ms before timeout)
const uint32_t MAX_NUM_POLLS = 100;

// # of iterations while polling for DL_PGRESET to deassert
uint32_t l_poll_counter;

// July 2020 FW overrides
const uint16_t FW_VER_0_JUL_2020 = 0x1100;
const uint16_t FW_VER_1_JUL_2020 = 0x033A;

// December 2020 FW overrides
const uint16_t FW_VER_0_DEC_2020 = 0x2004;
const uint16_t FW_VER_1_DEC_2020 = 0x0262;

const uint8_t FAST_RX_CONT_CAL_ADAPT_BIT = 60;
const uint64_t  RAWLANEAONN_DIG_FAST_FLAGS_REG[NUM_OF_INSTANCES] =
{
    0x8000702B0801113F,
    0x8001702B0801113F,
    0x8000702B0801153F,
    0x8001702B0801153F,
};

const uint8_t SKIP_RX_DFE_CAL_CONT = 58;
const uint64_t RAWLANEAONN_DIG_RX_CONT_ALGO_CTL[NUM_OF_INSTANCES] =
{
    0x800070130801113F,
    0x800170130801113F,
    0x800070130801153F,
    0x800170130801153F,
};

// October 2020 FW overrides
const uint16_t FW_VER_0_OCT_2020 = 0x2002;
const uint16_t FW_VER_1_OCT_2020 = 0x00D2;

const uint8_t AFE_RTRIM_VAL = 0;
const uint8_t AFE_RTRIM_START = 62;
const uint8_t AFE_RTRIM_LEN = 2;
const uint8_t SCRATCH_15_START = 48;
const uint8_t SCRATCH_15_LEN = 16;
const uint64_t  RAWLANEN_DIG_FSM_FW_SCRATCH_15[NUM_OF_INSTANCES] =
{
    0x800060A30801113F,
    0x800160A30801113F,
    0x800060A30801153F,
    0x800160A30801153F,
};
const uint64_t  RAWLANEAONN_DIG_AFE_RTRIM[NUM_OF_INSTANCES] =
{
    0x8000712A0801113F,
    0x8001712A0801113F,
    0x8000712A0801153F,
    0x8001712A0801153F,
};

// FW version registers
const uint64_t  RAWCMN_DIG_AON_FW_VERSION_0[NUM_OF_INSTANCES] =
{
    0x800001780801113F,
    0x800101780801113F,
    0x800001780801153F,
    0x800101780801153F,
};

const uint64_t  RAWCMN_DIG_AON_FW_VERSION_1[NUM_OF_INSTANCES] =
{
    0x800001790801113F,
    0x800101790801113F,
    0x800001790801153F,
    0x800101790801153F,
};

// MPLLA Calibration Override Registers
const uint8_t MPLLA_FDIV_EN_OVRD_EN = 49;
const uint8_t MPLLA_FDIV_EN = 50;
const uint8_t MPLLA_FBCLK_OVRD_EN = 51;
const uint8_t MPLLA_FBCLK_DIV4_EN = 52;
const uint8_t MPLLA_FBCLK_EN = 53;
const uint8_t MPLLA_ANA_VREG_SPEEDUP_OVRD_EN = 56;
const uint8_t MPLLA_ANA_VREG_SPEEDUP = 57;
const uint8_t MPLLA_ANA_EN_OVRD_EN = 62;
const uint8_t MPLLA_ANA_EN = 63;

const uint64_t  SUP_DIG_ANA_MPLLA_OVRD_OUT0[NUM_OF_INSTANCES] =
{
    0x800000800801113F,
    0x800100800801113F,
    0x800000800801153F,
    0x800100800801153F,
};

///-----------------------------------------------------------------------------
/// Function definitions
///-----------------------------------------------------------------------------
fapi2::ReturnCode
p10_pcie_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");
    using namespace scomt;
    using namespace scomt::pec;
    using namespace scomt::phb;

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data;

    auto l_pec_targets = i_target.getChildren<fapi2::TARGET_TYPE_PEC>();
    auto l_phb_targets = i_target.getChildren<fapi2::TARGET_TYPE_PHB>();

    uint8_t l_attr_proc_pcie_phb_active[NUM_STACK_CONFIG] = {0};
    uint8_t l_attr_proc_pcie_lane_reversal[NUM_STACK_CONFIG] = {0};
    uint64_t l_xramBaseReg = 0;

    //Perform the PCIe Phase 1 Inits 1-8
    //Sets the lane config based on MRW attributes
    //Sets the swap bits based on MRW attributes
    //Sets valid PHBs, remove from reset
    //Performs any needed overrides (should flush correctly) ~ this is where initfile may be used
    //Set the IOP program complete bit
    //This is where the dSMP versus PCIE is selected in the PHY Link Layer

    //Set io for (auto l_pec_target : l_pec_targets)
    for (auto l_pec_target : l_pec_targets)
    {

        // Grab PEC level attributes to configure LANE_CFG, IOVALIDs, and SWAP fields.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PHB_ACTIVE, l_pec_target, l_attr_proc_pcie_phb_active),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_PHB_ACTIVE");
        FAPI_DBG("l_attr_proc_pcie_phb_active 0x%.0x", l_attr_proc_pcie_phb_active);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_LANE_REVERSAL, l_pec_target, l_attr_proc_pcie_lane_reversal),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_LANE_REVERSAL");
        FAPI_DBG("l_attr_proc_pcie_lane_reversal 0x%.0x", l_attr_proc_pcie_lane_reversal);

        // Loop through all PEC Stack configs and determine which IOVALIDs and SWAP should be active.
        l_data = 0;
        FAPI_TRY(PREP_CPLT_CONF1_WO_OR(l_pec_target));

        for (auto l_cur_stk = 0; l_cur_stk < NUM_STACK_CONFIG; l_cur_stk++)
        {
            // This sets the LANE_CFG and IOVALIDs.
            if (l_attr_proc_pcie_phb_active[l_cur_stk] == fapi2::ENUM_ATTR_PROC_PCIE_PHB_ACTIVE_ENABLE)
            {
                SET_CPLT_CONF1_LANE_CFG_DC(l_cur_stk, l_data);
                l_data.setBit(l_cur_stk + TC_PCI_IOVALID_DC_START);

                // This sets the LANE_SWAP.
                if (l_attr_proc_pcie_lane_reversal[l_cur_stk] == fapi2::ENUM_ATTR_PROC_PCIE_LANE_REVERSAL_ENABLE)
                {
                    l_data.setBit(l_cur_stk + TC_PCI_SWAP_DC_START);
                }
            }
        }

        FAPI_TRY(PUT_CPLT_CONF1_WO_OR(l_pec_target, l_data));

        //Initialize PCI CPLT_CNTL5
        l_data = 0;
        FAPI_TRY(PREP_CPLT_CTRL5_WO_OR(l_pec_target));
        SET_CPLT_CTRL5_TC_CCFG_PIPE_LANEX_EXT_PLL_MODE_DC(l_data);
        SET_CPLT_CTRL5_TC_CCFG_PHYX_CR_PARA_SEL_DC(l_data);
        SET_CPLT_CTRL5_TC_CCFG_PHY_EXT_CTRL_SEL_DC(l_data);
        FAPI_TRY(PUT_CPLT_CTRL5_WO_OR(l_pec_target, l_data));

        //Initialize PCI CPLT_CONF0
        l_data = 0;
        FAPI_TRY(PREP_CPLT_CONF0_WO_OR(l_pec_target));
        l_data.setBit<CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC, CPLT_CONF0_TC_PIPE_LANEX_LANEPLL_BYPASS_MODE_DC_LEN>();
        FAPI_TRY(PUT_CPLT_CONF0_WO_OR(l_pec_target, l_data));

        //Initialize PCIIOPP.TOP[0,1].PIPEDOUTCTL2 for HW525901
        for (uint8_t l_top = 0; l_top < NUM_OF_IO_TOPS; l_top++)
        {
            l_data = 0;
            l_xramBaseReg = getXramBaseReg(static_cast<xramIopTopNum_t>(l_top));

            FAPI_TRY(fapi2::getScom(l_pec_target, l_xramBaseReg + PIPEDOUTCTL2_OFFSET, l_data), "Error from getScom 0x%.16llX",
                     l_xramBaseReg + PIPEDOUTCTL2_OFFSET);
            l_data.setBit<TOP0_PIPEDOUTCTL2_RATIO_ALIGN_POLARITY>();
            l_data.clearBit<TOP0_PIPEDOUTCTL2_RATIO_ALIGN_DISABLE>();
            FAPI_TRY(fapi2::putScom(l_pec_target, l_xramBaseReg + PIPEDOUTCTL2_OFFSET, l_data), "Error from putScom 0x%.16llX",
                     l_xramBaseReg + PIPEDOUTCTL2_OFFSET);

        }

    }

    // Reset PHBs
    // P9, we had the phb power up in reset and thus there is the instruction to take it out of reset.
    // In P10, I move that register to a new grouping of latches and forgot to set the init value to '1'.
    for (auto l_phb_target : l_phb_targets)
    {

// Cronus only
#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
        // Skip if PHB target is not enabled
        bool l_phbEnabled = false;
        FAPI_TRY(isPHBEnabled(l_phb_target, l_phbEnabled),
                 "Error returned from isPHBEnabled()");

        if (!l_phbEnabled)
        {
            FAPI_DBG("PHB is disabled, skip Reset.");
            continue;
        }

#endif

        l_data = 0;
        FAPI_TRY(PREP_REGS_PHBRESET_REG(l_phb_target));
        SET_REGS_PHBRESET_REG_PE_ETU_RESET(l_data);
        FAPI_TRY(PUT_REGS_PHBRESET_REG(l_phb_target, l_data));
    }

    //Run initfile
    FAPI_EXEC_HWP(l_rc, p10_pcie_scom, i_target);

    if (l_rc)
    {
        FAPI_ERR("Error from p10.pcie.scom.initfile");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode p10_load_iop_override(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start CReg Overrides");
    using namespace scomt;
    using namespace scomt::pec;

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data;

    fapi2::ATTR_PROC_PCIE_FW_VERSION_0_Type l_fw_ver_0 = 0;
    fapi2::ATTR_PROC_PCIE_FW_VERSION_1_Type l_fw_ver_1 = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_FW_VERSION_0, i_target, l_fw_ver_0));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_FW_VERSION_1, i_target, l_fw_ver_1));

    FAPI_DBG("FW VERSION 0: %04X", l_fw_ver_0);
    FAPI_DBG("FW VERSION 1: %04X", l_fw_ver_1);

    // Loop through all configured PECs
    for (auto l_pec_target : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        for (uint8_t i = 0; i < NUM_OF_INSTANCES ; i++)
        {
            if ((l_fw_ver_0 == FW_VER_0_JUL_2020) && (l_fw_ver_1 == FW_VER_1_JUL_2020))
            {
                l_data = 0;
                FAPI_TRY(fapi2::getScom(l_pec_target, RAWLANEAONN_DIG_FAST_FLAGS_REG[i] , l_data),
                         "Error from getScom 0x%.16llX", RAWLANEAONN_DIG_FAST_FLAGS_REG[i]);
                l_data.setBit<FAST_RX_CONT_CAL_ADAPT_BIT>();
                FAPI_DBG("RAWLANEAONN_DIG_FAST_FLAGS_REG 0x%.0x", l_data);
                FAPI_TRY(fapi2::putScom(l_pec_target, RAWLANEAONN_DIG_FAST_FLAGS_REG[i] , l_data),
                         "Error from putScom 0x%.16llX", RAWLANEAONN_DIG_FAST_FLAGS_REG[i]);
            }
            else if ((l_fw_ver_0 == FW_VER_0_DEC_2020) && (l_fw_ver_1 == FW_VER_1_DEC_2020))
            {
                //This bit skips RX DFE slicer continuous calibration.
                l_data = 0;
                FAPI_TRY(fapi2::getScom(l_pec_target, RAWLANEAONN_DIG_RX_CONT_ALGO_CTL[i] , l_data),
                         "Error from getScom 0x%.16llX", RAWLANEAONN_DIG_RX_CONT_ALGO_CTL[i]);
                l_data.setBit<SKIP_RX_DFE_CAL_CONT>();
                FAPI_DBG("RAWLANEAONN_DIG_RX_CONT_ALGO_CTL 0x%.0x", l_data);
                FAPI_TRY(fapi2::putScom(l_pec_target, RAWLANEAONN_DIG_RX_CONT_ALGO_CTL[i] , l_data),
                         "Error from putScom 0x%.16llX", RAWLANEAONN_DIG_RX_CONT_ALGO_CTL[i]);
            }

            //Disable scratch_15 algo
            l_data = 0;
            l_data.setBit(SCRATCH_15_START, SCRATCH_15_LEN);
            FAPI_DBG("RAWLANEN_DIG_FSM_FW_SCRATCH_15 0x%.0x", l_data);
            FAPI_TRY(fapi2::putScom(l_pec_target, RAWLANEN_DIG_FSM_FW_SCRATCH_15[i] , l_data),
                     "Error from putScom 0x%.16llX", RAWLANEN_DIG_FSM_FW_SCRATCH_15[i]);

            // GEN1/GEN2 workaround - Yield issue.
            // Step 1
            l_data = 0;
            FAPI_TRY(fapi2::getScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
                     "Error from getScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);
            l_data.setBit<MPLLA_ANA_EN_OVRD_EN>();
            l_data.setBit<MPLLA_ANA_EN>();
            FAPI_DBG("Step1: SUP_DIG_ANA_MPLLA_OVRD_OUT0 0x%.0x", l_data);
            FAPI_TRY(fapi2::putScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
                     "Error from putScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);

            FAPI_TRY(fapi2::delay(MICRO_SEC_DELAY, SIM_CYC_DELAY), "fapiDelay error.");

            // Step 2 - This step was only needed to bring out the FB clock for observability. Not needed for the workaround.
            //l_data = 0;
            //FAPI_TRY(fapi2::getScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
            //         "Error from getScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);
            //l_data.setBit<MPLLA_FBCLK_OVRD_EN>();
            //l_data.clearBit<MPLLA_FBCLK_DIV4_EN>();
            //l_data.setBit<MPLLA_FBCLK_EN>();
            //FAPI_DBG("Step2: SUP_DIG_ANA_MPLLA_OVRD_OUT0 0x%.0x", l_data);
            //FAPI_TRY(fapi2::putScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
            //         "Error from putScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);
            //
            //FAPI_TRY(fapi2::delay(MICRO_SEC_DELAY, SIM_CYC_DELAY), "fapiDelay error.");

            // Step 3
            l_data = 0;
            FAPI_TRY(fapi2::getScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
                     "Error from getScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);
            l_data.setBit<MPLLA_ANA_VREG_SPEEDUP_OVRD_EN>();
            l_data.clearBit<MPLLA_ANA_VREG_SPEEDUP>();
            FAPI_DBG("Step3: SUP_DIG_ANA_MPLLA_OVRD_OUT0 0x%.0x", l_data);
            FAPI_TRY(fapi2::putScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
                     "Error from putScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);

            FAPI_TRY(fapi2::delay(MICRO_SEC_DELAY, SIM_CYC_DELAY), "fapiDelay error.");

            // Step 4
            l_data = 0;
            FAPI_TRY(fapi2::getScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
                     "Error from getScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);
            l_data.setBit<MPLLA_FDIV_EN_OVRD_EN>();
            l_data.setBit<MPLLA_FDIV_EN>();
            FAPI_DBG("Step4: SUP_DIG_ANA_MPLLA_OVRD_OUT0 0x%.0x", l_data);
            FAPI_TRY(fapi2::putScom(l_pec_target, SUP_DIG_ANA_MPLLA_OVRD_OUT0[i] , l_data),
                     "Error from putScom 0x%.16llX", SUP_DIG_ANA_MPLLA_OVRD_OUT0[i]);

            FAPI_TRY(fapi2::delay(MICRO_SEC_DELAY, SIM_CYC_DELAY), "fapiDelay error.");

        }
    }

fapi_try_exit:
    FAPI_DBG("End CReg Overrides");
    return fapi2::current_err;
}

/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode p10_load_rtrim_override(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start RTRIM Override");
    using namespace scomt;
    using namespace scomt::pec;
    using namespace scomt::phb;

    fapi2::buffer<uint64_t> l_data;

    fapi2::ATTR_PROC_PCIE_FW_VERSION_0_Type l_fw_ver_0 = 0;
    fapi2::ATTR_PROC_PCIE_FW_VERSION_1_Type l_fw_ver_1 = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_FW_VERSION_0, i_target, l_fw_ver_0));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_FW_VERSION_1, i_target, l_fw_ver_1));

    FAPI_DBG("FW VERSION 0: %04X", l_fw_ver_0);
    FAPI_DBG("FW VERSION 1: %04X", l_fw_ver_1);

    if ((l_fw_ver_0 == FW_VER_0_OCT_2020) && (l_fw_ver_1 == FW_VER_1_OCT_2020))
    {
        for (auto l_phb_target : i_target.getChildren<fapi2::TARGET_TYPE_PHB>())
        {

            // Cronus only
#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
            // Skip if PHB target is not enabled
            bool l_phbEnabled = false;
            FAPI_TRY(isPHBEnabled(l_phb_target, l_phbEnabled),
                     "Error returned from isPHBEnabled()");

            if (!l_phbEnabled)
            {
                FAPI_DBG("PHB is disabled, skip Reset.");
                continue;
            }

#endif
            l_data = 0;
            //Take ETU out of reset to acess PHB PCI - Core Reset Register
            FAPI_DBG("  ETU is in reset. Taking it out of reset");
            FAPI_TRY(PREP_REGS_PHBRESET_REG(l_phb_target),
                     "Error from PREP_REGS_PHBRESET_REG");
            CLEAR_REGS_PHBRESET_REG_PE_ETU_RESET(l_data);
            FAPI_TRY(PUT_REGS_PHBRESET_REG(l_phb_target, l_data),
                     "Error from PUT_REGS_PHBRESET_REG");

            l_data = 0;
            //This will deassert reset for the PCI CFG core only.
            FAPI_TRY(p10_phb_hv_access(l_phb_target, PHB_CORE_RESET_REGISTER, true, false, l_data),
                     "Error from p10_phb_hv_access: Deactivate PHB_CORE_RESET_REGISTER (Read)");
            l_data.clearBit<PHB_HV_1A10_CFG_CORE_RESET_BIT>();
            FAPI_DBG("  Value to be written to %016lX -  %016lX", PHB_CORE_RESET_REGISTER, l_data());
            FAPI_TRY(p10_phb_hv_access(l_phb_target, PHB_CORE_RESET_REGISTER, false, false, l_data),
                     "Error from p10_phb_hv_access: Deactivate PHB_CORE_RESET_REGISTER (Write)");


            l_data = 0;
            //This will deassert reset for the PDL + PTL + PBL + PIPE_RESET.
            FAPI_TRY(p10_phb_hv_access(l_phb_target, PHB_CORE_RESET_REGISTER, true, false, l_data),
                     "Error from p10_phb_hv_access: Deactivate PHB_CORE_RESET_REGISTER (Read)");
            l_data.clearBit<PHB_HV_1A10_PDL_PTL_RESET_BIT>();
            l_data.clearBit<PHB_HV_1A10_PBL_RESET_BIT>();
            l_data.setBit<PHB_HV_1A10_PIPE_RESETN_BIT>();
            FAPI_DBG("  Value to be written to %016lX -  %016lX", PHB_CORE_RESET_REGISTER, l_data());
            FAPI_TRY(p10_phb_hv_access(l_phb_target, PHB_CORE_RESET_REGISTER, false, false, l_data),
                     "Error from p10_phb_hv_access: Deactivate PHB_CORE_RESET_REGISTER (Write)");


            //Read PCIE - DLP Training Control Register to check for DL_PGRESET to be deasserted
            l_poll_counter = 0; //Reset poll counter

            while (l_poll_counter < MAX_NUM_POLLS)
            {
                l_poll_counter++;
                FAPI_TRY(fapi2::delay(NANO_SEC_DELAY, SIM_CYC_DELAY), "fapiDelay error.");

                l_data = 0;
                FAPI_TRY(p10_phb_hv_access(l_phb_target, PHB_DLP_TRAINING_CTRL_REGISTER, true, false, l_data),
                         "Error from p10_phb_hv_access: PHB_DLP_TRAINING_CTRL_REGISTER (Read)");

                FAPI_DBG("PHB%i: PHB_DLP_TRAINING_CTRL_REGISTER %#lx", l_phb_target, l_data());

                //Check DL_PGRESET is deasserted
                if (!(l_data.getBit(PHB_HV_1A40_TL_EC10_DL_PGRESET)))
                {
                    FAPI_DBG("  DL_PGRESET completed reset to complete %016lX -  %016lX", PHB_DLP_TRAINING_CTRL_REGISTER, l_data());
                    FAPI_DBG("  End polling for DL_PGRESET to become deasserted");
                    break;
                }
            }

            FAPI_DBG("  DL_PGRESET status (poll counter = %d).", l_poll_counter);

            FAPI_ASSERT(l_poll_counter < MAX_NUM_POLLS,
                        fapi2::P10_DL_PGRESET_STUCK()
                        .set_TARGET(l_phb_target)
                        .set_PHB_ADDR(PHB_DLP_TRAINING_CTRL_REGISTER)
                        .set_PHB_DATA(l_data),
                        "PHB%i: DL_PGRESET did not clear.", l_phb_target);

        }

        // Write CReg overrides through the CR Parallel Interface.
        // Note: This overrides is required to be done after ext_ld_done and lane_reset is de-asserted.
        // Loop through all configured PECs
        for (auto l_pec_target : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
        {
            for (uint8_t i = 0; i < NUM_OF_INSTANCES ; i++)
            {
                //Only to be applied with firmware version
                //  0x0178, 0x2002
                //  0x0179, 0x00D2
                //Change RTRIM setting to reflect short channels for better AFE performance.
                //Needs to be set after a toggle of lane_reset.
                l_data = 0;
                FAPI_TRY(fapi2::getScom(l_pec_target, RAWLANEAONN_DIG_AFE_RTRIM[i] , l_data),
                         "Error from getScom 0x%.16llX", RAWLANEAONN_DIG_AFE_RTRIM[i]);
                l_data.insertFromRight(AFE_RTRIM_VAL, AFE_RTRIM_START, AFE_RTRIM_LEN);
                FAPI_DBG("RAWLANEAONN_DIG_AFE_RTRIM 0x%.0x", l_data);
                FAPI_TRY(fapi2::putScom(l_pec_target, RAWLANEAONN_DIG_AFE_RTRIM[i] , l_data),
                         "Error from putScom 0x%.16llX", RAWLANEAONN_DIG_AFE_RTRIM[i]);
            }
        }


        for (auto l_phb_target : i_target.getChildren<fapi2::TARGET_TYPE_PHB>())
        {
            // Cronus only
#if !defined(__PPE__) && !defined(__HOSTBOOT_MODULE)
            // Skip if PHB target is not enabled
            bool l_phbEnabled = false;
            FAPI_TRY(isPHBEnabled(l_phb_target, l_phbEnabled),
                     "Error returned from isPHBEnabled()");

            if (!l_phbEnabled)
            {
                FAPI_DBG("PHB is disabled, skip Reset.");
                continue;
            }

#endif

            l_data = 0;
            //Put ETU into reset
            FAPI_DBG("  Put ETU back into reset.");
            FAPI_TRY(PREP_REGS_PHBRESET_REG(l_phb_target),
                     "Error from PREP_REGS_PHBRESET_REG");
            SET_REGS_PHBRESET_REG_PE_ETU_RESET(l_data);
            FAPI_TRY(PUT_REGS_PHBRESET_REG(l_phb_target, l_data),
                     "Error from PUT_REGS_PHBRESET_REG");
        }
    }

fapi_try_exit:
    FAPI_DBG("End RTRIM Override");
    return fapi2::current_err;
}


/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode p10_verify_iop_fw(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start Verify IOP FW");
    using namespace scomt;
    using namespace scomt::pec;

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data;

    fapi2::ATTR_PROC_PCIE_FW_VERSION_0_Type l_fw_ver_0_attr = 0;
    fapi2::ATTR_PROC_PCIE_FW_VERSION_1_Type l_fw_ver_1_attr = 0;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_IS_SIMICS_Type l_attr_is_simics;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_FW_VERSION_0, i_target, l_fw_ver_0_attr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_FW_VERSION_1, i_target, l_fw_ver_1_attr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_attr_is_simics));

    FAPI_DBG("FW VERSION 0: %04X", l_fw_ver_0_attr);
    FAPI_DBG("FW VERSION 1: %04X", l_fw_ver_1_attr);

    for (auto l_pec_target : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        for (uint8_t i = 0; i < NUM_OF_INSTANCES ; i++)
        {
            fapi2::buffer<uint64_t> l_fw_ver_0_hw = 0;
            fapi2::buffer<uint64_t> l_fw_ver_1_hw = 0;

            FAPI_TRY(fapi2::getScom(l_pec_target, RAWCMN_DIG_AON_FW_VERSION_0[i] , l_fw_ver_0_hw),
                     "Error from getScom 0x%.16llX", RAWCMN_DIG_AON_FW_VERSION_0[i]);
            FAPI_TRY(fapi2::getScom(l_pec_target, RAWCMN_DIG_AON_FW_VERSION_1[i] , l_fw_ver_1_hw),
                     "Error from getScom 0x%.16llX", RAWCMN_DIG_AON_FW_VERSION_1[i]);

            FAPI_ASSERT(l_attr_is_simics ||
                        ((l_fw_ver_0_attr == (l_fw_ver_0_hw() & 0xFFFF)) &&
                         (l_fw_ver_1_attr == (l_fw_ver_1_hw() & 0xFFFF))),
                        fapi2::P10_IOP_XRAM_FW_VER_ERROR()
                        .set_TARGET(l_pec_target)
                        .set_INST(i)
                        .set_FW_VER_0_ATTR(l_fw_ver_0_attr)
                        .set_FW_VER_0_HW(l_fw_ver_0_hw)
                        .set_FW_VER_1_ATTR(l_fw_ver_1_attr)
                        .set_FW_VER_1_HW(l_fw_ver_1_hw),
                        "p10_verify_iop_fw: Attribute and HW version values mismatch!");
        }
    }


fapi_try_exit:
    FAPI_DBG("End Verify IOP FW");
    return fapi2::current_err;
}
