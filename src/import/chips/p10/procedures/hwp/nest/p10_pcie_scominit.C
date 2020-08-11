/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
const uint64_t NANO_SEC_DELAY = 20000;
const uint64_t SIM_CYC_DELAY = 512;

const uint8_t FAST_RX_CONT_CAL_ADAPT_BIT = 60;
const uint64_t  RAWLANEAONN_DIG_FAST_FLAGS_REG[NUM_OF_INSTANCES] =
{
    0x8000702B0801113F,
    0x8001702B0801113F,
    0x8000702B0801153F,
    0x8001702B0801153F,
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
            l_data.setBit<PIPEDOUTCTL2_RATIO_ALIGN_POLARITY>();
            l_data.clearBit<PIPEDOUTCTL2_RATIO_ALIGN_DISABLE>();
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

    // Loop through all configured PECs
    for (auto l_pec_target : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        //Disable FAST_RX_CONT_CAL_ADAPT per request from Synopsis
        //PleaseI disable CCA (continuous calibration and adaptation algorithm for slow VT drift) by:
        for (uint8_t i = 0; i < NUM_OF_INSTANCES ; i++)
        {
            l_data = 0;
            FAPI_TRY(fapi2::getScom(l_pec_target, RAWLANEAONN_DIG_FAST_FLAGS_REG[i] , l_data),
                     "Error from getScom 0x%.16llX", RAWLANEAONN_DIG_FAST_FLAGS_REG[i]);
            l_data.setBit<FAST_RX_CONT_CAL_ADAPT_BIT>();
            FAPI_DBG("RAWLANEAONN_DIG_FAST_FLAGS_REG 0x%.0x", l_data);
            FAPI_TRY(fapi2::putScom(l_pec_target, RAWLANEAONN_DIG_FAST_FLAGS_REG[i] , l_data),
                     "Error from putScom 0x%.16llX", RAWLANEAONN_DIG_FAST_FLAGS_REG[i]);
        }
    }

fapi_try_exit:
    FAPI_DBG("End CReg Overrides");
    return fapi2::current_err;
}
