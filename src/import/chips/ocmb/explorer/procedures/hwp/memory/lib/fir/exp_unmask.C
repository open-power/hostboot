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

#include <lib/shared/exp_defaults.H>
#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/fir/exp_fir.H>
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

    FAPI_TRY(l_rc1, "unable to create fir::reg for %d", EXPLR_MCBIST_MCBISTFIRQ);
    FAPI_TRY(l_rc2, "unable to create fir::reg for %d", EXPLR_SRQ_SRQFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for %d", EXPLR_RDF_FIR);

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
             .checkstop<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE>()
             .checkstop<EXPLR_RDF_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>()
             .recoverable_error<EXPLR_RDF_FIR_ECC_RBUF_CE_DW0>()
             .recoverable_error<EXPLR_RDF_FIR_ECC_RBUF_CE_DW1>()
             .checkstop<EXPLR_RDF_FIR_ECC_RBUF_UE_DW0>()
             .checkstop<EXPLR_RDF_FIR_ECC_RBUF_UE_DW1>()
             .write());

    // Write SRQ FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_srq_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_REFRESH_OVERRUN>()
             .write());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after draminit_training
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
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

    FAPI_TRY(l_rc1, "unable to create fir::reg for %d", EXPLR_MCBIST_MCBISTFIRQ);
    FAPI_TRY(l_rc2, "unable to create fir::reg for %d", EXPLR_SRQ_SRQFIRQ);

    // Write MCBISTFIR register per Explorer unmask spec; omit bit 10 cmd_complete until draminit_mc
    FAPI_TRY(l_exp_mcbist_reg.recoverable_error<EXPLR_MCBIST_MCBISTFIRQ_COMMAND_ADDRESS_TIMEOUT>()
             .checkstop<EXPLR_MCBIST_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
             .checkstop<EXPLR_MCBIST_MCBISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>()
             .recoverable_error<EXPLR_MCBIST_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .checkstop<EXPLR_MCBIST_MCBISTFIRQ_SCOM_FATAL_REG_PE>()
             .write());

    // Write SRQ FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_srq_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_NCF_MCB_LOGIC_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_MCB_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WRQ_RRQ_HANG_ERR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_SM_1HOT_ERR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_CMD_PARITY_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR2>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR3>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WDF_ERROR7>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_UE>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_LOGIC_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_NCF_CORR_ERROR>()
             .write());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
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
