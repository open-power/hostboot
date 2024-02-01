/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_setup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_setup.C
/// @brief Setup OMI DL
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------
#include <ody_omi_setup.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>
#include <ody_scom_ody.H>
#include <ody_fir_lib.H>

SCOMT_OMI_USE_D_REG_DL0_ERROR_MASK
SCOMT_OMI_USE_D_REG_CMN_CONFIG
SCOMT_OMI_USE_D_REG_DL0_CONFIG0
SCOMT_OMI_USE_D_REG_DL0_CONFIG1
SCOMT_OMI_USE_D_REG_DL0_CYA_BITS
SCOMT_ODY_USE_ODC_TLXT_REGS_TLXCFG0
SCOMT_ODY_USE_ODC_TLXT_REGS_TLXCFG1
SCOMT_ODY_USE_ODC_TLXT_REGS_TLXCFG2
SCOMT_ODY_USE_ODC_TLXT_REGS_TLXCFG3
SCOMT_ODY_USE_ODC_SRQ_MBA_ROQ0Q
SCOMT_ODY_USE_ODC_MMIO_MXMETA

///
/// @brief Setup OMI DL
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_setup(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Starting ody_omi_setup");

    using namespace scomt::omi;
    using namespace scomt::ody;

    io_ppe_firs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_firs(FIR_SCOM_LFIR_RW_WCLEAR_REG, FIR_DL0_ERROR_MASK,
            FIR_DL0_ERROR_ACTION, FIR_MC_OMI_RW_WCLEAR_REG,
            FIR_DL0_SKIT_CTL, FIR_TLX_RW_WCLEAR);

    D_REG_DL0_ERROR_MASK_t l_dl0_error_mask;
    D_REG_CMN_CONFIG_t l_cmn_config;
    D_REG_DL0_CONFIG0_t l_dl0_config0;
    D_REG_DL0_CONFIG1_t l_dl0_config1;
    D_REG_DL0_CYA_BITS_t l_dl0_cya;
    ODC_TLXT_REGS_TLXCFG0_t l_tlxcfg0;
    ODC_TLXT_REGS_TLXCFG1_t l_tlxcfg1;
    ODC_TLXT_REGS_TLXCFG2_t l_tlxcfg2;
    ODC_TLXT_REGS_TLXCFG3_t l_tlxcfg3;
    ODC_SRQ_MBA_ROQ0Q_t l_srq_mba_roq0q;
    ODC_MMIO_MXMETA_t l_mmio_mxmeta;

    bool l_mfg_mode = false;

    fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE_Type l_half_dimm_mode;

    FAPI_TRY(ody_io::get_functional_margin_mfg_mode(l_mfg_mode));

    //Clear mask to all training done FIR
    FAPI_TRY(l_dl0_error_mask.getScom(i_target));
    l_dl0_error_mask.set_39(0);
    FAPI_TRY(l_dl0_error_mask.putScom(i_target));

    FAPI_TRY(l_cmn_config.getScom(i_target));
    l_cmn_config.set_SPARE(0);
    l_cmn_config.set_RX_EDGE_ENA(1);
    l_cmn_config.set_RX_EDGE_MARGIN(1);
    l_cmn_config.set_DISABLE_XSTOPIN(0);
    l_cmn_config.set_RECAL_TIMER(7);
    l_cmn_config.set_DBG_EN(0);
    l_cmn_config.set_DBG_SEL(0);
    l_cmn_config.set_CNTR0_EN(0);
    l_cmn_config.set_CNTR1_EN(0);
    l_cmn_config.set_CNTR2_EN(0);
    l_cmn_config.set_CNTR3_EN(0);
    FAPI_TRY(l_cmn_config.putScom(i_target));

    FAPI_TRY(l_dl0_config0.getScom(i_target));
    l_dl0_config0.set_CFG_TL_CREDITS(0x2);
    l_dl0_config0.set_TL_EVENT_ACTIONS(0);
    l_dl0_config0.set_TL_ERROR_ACTIONS(0);
    l_dl0_config0.set_DEBUG_SELECT(0);
    l_dl0_config0.set_DEBUG_ENABLE(0);
    l_dl0_config0.set_TX_LN_REV_ENA(1);
    l_dl0_config0.set_PWRMGT_ENABLE(0);
    l_dl0_config0.set_TRAIN_MODE(0);
    l_dl0_config0.set_VERSION(9);
    FAPI_TRY(l_dl0_config0.putScom(i_target));

    FAPI_TRY(l_dl0_config1.getScom(i_target));
    l_dl0_config1.set_PREIPL_PRBS_TIME(1);

    if (l_mfg_mode)
    {
        l_dl0_config1.set_EDPL_TIME(10);     // 10: 512s
        l_dl0_config1.set_EDPL_THRESHOLD(3); // 3: 8 Errors
    }
    else
    {
        l_dl0_config1.set_EDPL_TIME(6);      // 6: 128mS
        l_dl0_config1.set_EDPL_THRESHOLD(7); // 7: 128 Errors
    }

    l_dl0_config1.set_EDPL_ENA(1);
    FAPI_TRY(l_dl0_config1.putScom(i_target));

    FAPI_TRY(l_dl0_cya.getScom(i_target));
    l_dl0_cya.set_DIS_SYNCTO(1); // Needed as the host may be running manual training (step by step)
    l_dl0_cya.set_FRBUF_FULL(1);
    FAPI_TRY(l_dl0_cya.putScom(i_target));

    FAPI_TRY(l_tlxcfg0.getScom(i_target));
    l_tlxcfg0.set_EARLY_WDONE_DISABLE(0);
    l_tlxcfg0.set_DCP1_RETURN_PAUSE(0);
    l_tlxcfg0.set_VC0_RETURN_PAUSE(0);
    l_tlxcfg0.set_VC1_RETURN_PAUSE(0);
    l_tlxcfg0.set_DCP1_INIT(128);
    FAPI_TRY(l_tlxcfg0.putScom(i_target));

    FAPI_TRY(l_tlxcfg1.getScom(i_target));
    l_tlxcfg1.set_FIR_TLXR_SHUTDOWN_CONTROLS(0x614);
    l_tlxcfg1.set_TLXR_MS_MMIO_ADDRBIT(0xe);
    l_tlxcfg1.set_CDD_THRESHOLD(4);
    l_tlxcfg1.set_CD4_THRESHOLD(4);
    l_tlxcfg1.set_CFG_CDD_DIS(0);
    l_tlxcfg1.set_CFG_CD4_DIS(1);
    l_tlxcfg1.set_CFG_CD6_DIS(1);
    l_tlxcfg1.set_LOW_LAT_RD_DIS(0);
    l_tlxcfg1.set_CLK_GATE_DIS(0);
    l_tlxcfg1.set_CFEI_ENAB(0);
    l_tlxcfg1.set_CFEI_PERSIST(0);
    l_tlxcfg1.set_CFEI_BIT0(0);
    l_tlxcfg1.set_CFEI_BIT1(0);
    l_tlxcfg1.set_LOW_LAT_DEGRADE_DIS(1);
    FAPI_TRY(l_tlxcfg1.putScom(i_target));

    FAPI_TRY(l_tlxcfg2.getScom(i_target));
    l_tlxcfg2.set_XSTOP_RD_GATE_DIS(0);
    l_tlxcfg2.set_READ_CANCEL_DIS(1);
    l_tlxcfg2.set_READ_PROMOTE_DIS(1);
    l_tlxcfg2.set_READ_DROPPABLE_DIS(1);
    l_tlxcfg2.set_LP_STARVATION_DIS(0);
    l_tlxcfg2.set_MP_STARVATION_DIS(0);
    l_tlxcfg2.set_ENTRY0_HP_DLY(255);
    l_tlxcfg2.set_CFG_TLXT_128B_RESP_EN(0);
    l_tlxcfg2.set_SYS_XSTOP_IN_DIS(0);
    l_tlxcfg2.set_CFG_TLXT_ENHANCED_LL_MODE_DIS(1);
    l_tlxcfg2.set_CFG_TLXT_CD6_THRESHOLD(4);
    l_tlxcfg2.set_CFG_XMETA_LANE_WIDTH_COMP_DIS(0);

    FAPI_TRY(l_tlxcfg2.putScom(i_target));

    FAPI_TRY(l_tlxcfg3.getScom(i_target));
    l_tlxcfg3.set_CFG_TL_CREDIT_HP_TIMEOUT(0x00ff);
    l_tlxcfg3.set_CFG_VC0_CREDIT_HP_THRESHOLD(1);
    l_tlxcfg3.set_CFG_VC1_CREDIT_HP_THRESHOLD(4);
    l_tlxcfg3.set_CFG_DCP1_CREDIT_HP_THRESHOLD(6);
    l_tlxcfg3.set_CFG_TL_CREDIT_FORCE_HP(0);
    FAPI_TRY(l_tlxcfg3.putScom(i_target));

    FAPI_TRY(l_srq_mba_roq0q.getScom(i_target));
    l_srq_mba_roq0q.set_CFG_TLXR_SPEC_CMD_ENB(1);
    FAPI_TRY(l_srq_mba_roq0q.putScom(i_target));

    FAPI_TRY(l_ppe_firs.mc_omi_fir_set(i_target));
    FAPI_TRY(l_ppe_firs.tlx_fir_set(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE, i_target, l_half_dimm_mode));
    FAPI_TRY(l_mmio_mxmeta.getScom(i_target));

    if (l_half_dimm_mode == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM)
    {
        l_mmio_mxmeta.set_MXMETA_XMETA_MODE(1);
    }
    else
    {
        l_mmio_mxmeta.set_MXMETA_XMETA_MODE(0);
    }

    FAPI_TRY(l_mmio_mxmeta.putScom(i_target));

fapi_try_exit:
    FAPI_DBG("End ody_omi_setup");
    return fapi2::current_err;
}
