/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_unmask.C $ */
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
/// @file exp_unmask.C
/// @brief Subroutines for unmasking and setting up MSS FIR
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/shared/exp_defaults.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/fir/exp_fir_traits.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>

namespace mss
{

namespace unmask
{

///
/// @brief Unmask and setup actions performed after draminit_mc
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode after_draminit_mc<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success for MCBISTFIR and SRQFIR and RDFFIR
    mss::fir::reg<EXPLR_MCBIST_MCBISTFIRQ> l_exp_mcbist_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_SRQ_SRQFIRQ> l_exp_srq_reg(i_target, l_rc2);
    mss::fir::reg<EXPLR_RDF_FIR> l_exp_rdf_reg(i_target, l_rc3);

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_MCBIST_MCBISTFIRQ 0x%08X", EXPLR_MCBIST_MCBISTFIRQ);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_SRQ_SRQFIRQ 0x%08X", EXPLR_SRQ_SRQFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for EXPLR_RDF_FIR 0x%08X", EXPLR_RDF_FIR);

    // Write MCBISTFIR register per Explorer unmask spec
    FAPI_TRY(l_exp_mcbist_reg.attention<EXPLR_MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>()
             .write());

    // Write RDF FIR register per Explorer unmask spec
    // TK Need to set EXPLR_RDF_FIR_MAINTENANCE_RCD to recoverable for planar/ISDIMM
    FAPI_TRY(l_exp_rdf_reg.recoverable_error<EXPLR_RDF_FIR_MAINTENANCE_AUE>()
             .recoverable_error<EXPLR_RDF_FIR_MAINTENANCE_IAUE>()
             .recoverable_error<EXPLR_RDF_FIR_RDDATA_VALID_ERROR>()
             .recoverable_error<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_STATUS>()
             .recoverable_error<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_RECOVERABLE>()
             .local_checkstop<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE>()
             .local_checkstop<EXPLR_RDF_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>()
             .recoverable_error<EXPLR_RDF_FIR_ECC_RBUF_CE_DW0>()
             .recoverable_error<EXPLR_RDF_FIR_ECC_RBUF_CE_DW1>()
             .local_checkstop<EXPLR_RDF_FIR_ECC_RBUF_UE_DW0>()
             .local_checkstop<EXPLR_RDF_FIR_ECC_RBUF_UE_DW1>()
             .write());

    // Write SRQ FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_srq_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_REFRESH_OVERRUN>()
             .write());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after draminit_training
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode after_draminit_training<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success for MCBISTFIR and SRQFIR
    mss::fir::reg<EXPLR_MCBIST_MCBISTFIRQ> l_exp_mcbist_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_SRQ_SRQFIRQ> l_exp_srq_reg(i_target, l_rc2);

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_MCBIST_MCBISTFIRQ 0x%08X", EXPLR_MCBIST_MCBISTFIRQ);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_SRQ_SRQFIRQ 0x%08X", EXPLR_SRQ_SRQFIRQ);

    // Write MCBISTFIR register per Explorer unmask spec; omit bit 10 cmd_complete until draminit_mc
    FAPI_TRY(l_exp_mcbist_reg.recoverable_error<EXPLR_MCBIST_MCBISTFIRQ_COMMAND_ADDRESS_TIMEOUT>()
             .local_checkstop<EXPLR_MCBIST_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
             .local_checkstop<EXPLR_MCBIST_MCBISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>()
             .recoverable_error<EXPLR_MCBIST_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .local_checkstop<EXPLR_MCBIST_MCBISTFIRQ_SCOM_FATAL_REG_PE>()
             .write());

    // Write SRQ FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_srq_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_NCF_MCB_LOGIC_ERROR>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_NCF_MCB_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WRQ_RRQ_HANG_ERR>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_SM_1HOT_ERR>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_CMD_PARITY_ERROR>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR2>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR3>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WDF_ERROR7>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_NCF_UE>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_NCF_LOGIC_ERROR>()
             .local_checkstop<EXPLR_SRQ_SRQFIRQ_NCF_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_NCF_CORR_ERROR>()
             .write());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Unmask Explorer Global FIR and SPECIAL ATTN mask registers afer exp_omi_init
/// @param[in] i_target Explorer to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
template<>
fapi2::ReturnCode after_mc_omi_init<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc4 = fapi2::FAPI2_RC_SUCCESS;

    fapi2::buffer<uint64_t> l_global_fir_mask_reg;
    fapi2::buffer<uint64_t> l_global_spa_attn_reg;

    mss::fir::reg<EXPLR_MMIO_MFIR> l_exp_mmio_mfir_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_TLXT_TLXFIRQ> l_exp_tlxt_fir_reg(i_target, l_rc2);
    mss::fir::reg<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR> l_exp_local_fir_reg(i_target, l_rc3);
    mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG> l_exp_dlx_omi_fir_reg(i_target, l_rc4);

    FAPI_TRY(l_rc1, "for target %s unable to create fir::reg for EXPLR_MMIO_MFIR 0x%0x",
             mss::c_str(i_target), EXPLR_MMIO_MFIR);
    FAPI_TRY(l_rc2, "for target %s unable to create fir::reg for EXPLR_TLXT_TLXFIRQ 0x%0x",
             mss::c_str(i_target), EXPLR_TLXT_TLXFIRQ);
    FAPI_TRY(l_rc3, "for target %s unable to create fir::reg for EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR 0x%0x",
             mss::c_str(i_target), EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR);
    FAPI_TRY(l_rc4, "for target %s unable to create fir::reg for EXPLR_DLX_MC_OMI_FIR_REG 0x%0x",
             mss::c_str(i_target), EXPLR_DLX_MC_OMI_FIR_REG);

    // Pull global fir mask state and unmask bits per spec
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_FIR_MASK, l_global_fir_mask_reg));
    l_global_fir_mask_reg.clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN3>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN4>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN7>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN8>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN9>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN11>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN12>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TP_MB_UNIT_TOP_FIR_MASK, l_global_fir_mask_reg));

    // Pull global special attn state and unmask bits per spec
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_SPA_MASK, l_global_spa_attn_reg));
    l_global_spa_attn_reg.clearBit<EXPLR_TP_MB_UNIT_TOP_SPATTN_IN5>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TP_MB_UNIT_TOP_SPA_MASK, l_global_spa_attn_reg));

    // Setup MMIO MFIR unmasks per spec
    FAPI_TRY(l_exp_mmio_mfir_reg.recoverable_error<EXPLR_MMIO_MFIR_SCOM_ERR>()
             .local_checkstop<EXPLR_MMIO_MFIR_FSM_PERR>()
             .local_checkstop<EXPLR_MMIO_MFIR_FIFO_OVERFLOW>()
             .local_checkstop<EXPLR_MMIO_MFIR_CTL_REG_PERR>()
             .recoverable_error<EXPLR_MMIO_MFIR_INFO_REG_PERR>()
             .write());

    // Setup TLXT FIR unmasks per spec
    FAPI_TRY(l_exp_tlxt_fir_reg.local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXT_PARITY_ERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXT_RECOVERABLE_ERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXT_CONFIG_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXT_INFORMATIONAL_PERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXT_HARD_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_OC_MALFORMED>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXR_OC_PROTOCOL_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_ADDR_XLAT>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_METADATA_UNC_DPERR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_OC_UNSUPPORTED>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_OC_FATAL>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_CONTROL_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_INTERNAL_ERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXR_INFORMATIONAL>()
             .write());

    // Setup LOCAL FIR unmasks per spec
    FAPI_TRY(l_exp_local_fir_reg.recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN0>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN1>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN2>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN8>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN63>()
             .write());

    // Setup MC OMI FIR unmasks per spec
    FAPI_TRY(l_exp_dlx_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_FLIT_CE>()
             .write());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after mss_scominit
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// TODO: Need to implement this function
template<>
fapi2::ReturnCode after_scominit<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Unmask and setup actions performed after mss_ddr_phy_reset
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// TODO: Need to implement this function
template<>
fapi2::ReturnCode after_phy_reset<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Unmask and setup actions performed after exp_omi_setup
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode after_mc_omi_setup<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success
    mss::fir::reg<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR> l_exp_local_fir_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_TLXT_TLXFIRQ> l_exp_tlx_fir_reg(i_target, l_rc2);
    mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG> l_exp_mc_omi_fir_reg(i_target, l_rc3);

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR 0x%08X", EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_TLXT_TLXFIRQ 0x%08X", EXPLR_TLXT_TLXFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for EXPLR_DLX_MC_OMI_FIR_REG 0x%08X", EXPLR_DLX_MC_OMI_FIR_REG);

    // Write LOCAL_FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_local_fir_reg.recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_106>()
             .local_checkstop<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_111>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_112>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PROC_SS__TOP_FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PROC_SS__TOP_NON_FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_7__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_6__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_5__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_4__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_3__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_2__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_1__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_0__FATAL>()
             .write());

    // Write TLX FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_tlx_fir_reg.recoverable_error<EXPLR_TLXT_TLXFIRQ_INFO_REG_PARITY_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_CTRL_REG_PARITY_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLX_VC0_MAX_CRD_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLX_VC1_MAX_CRD_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLX_DCP0_MAX_CRD_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_TLX_DCP3_MAX_CRD_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_CREDIT_MGMT_ERROR>()
             .local_checkstop<EXPLR_TLXT_TLXFIRQ_CREDIT_MGMT_PERROR>()
             .write());

    // Write MC_OMI FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_mc_omi_fir_reg.local_checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
             .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_DATA_UE>()
             .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>()
             .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_TIMEOUT>()
             .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
             .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>()
             .write());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// TODO: Need to implement this function
template<>
fapi2::ReturnCode after_memdiags<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Unmask and setup actions for scrub related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// TODO: Need to implement this function
template<>
fapi2::ReturnCode after_background_scrub<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

} // end unmask ns
} // end mss ns
