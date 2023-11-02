/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_ccs_des_insert_workaround.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file exp_ccs_des_insert_workaround.C
/// @brief Explorer workaround for CCS command des insert
///
// *HWP HWP Owner: David Jude Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/ccs/ccs_explorer.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/workarounds/ccs_des_insert_workaround.H>

namespace mss
{
namespace ccs
{
namespace workarounds
{

///
/// @brief Workaround for DES command insertion, Exp specialization requires delay of 0 at the end of array
/// @param[in] i_target the target to effect
/// @param[in] i_port the port target to effect
/// @param[in,out] io_inst_count the inst count for the ccs instructions
/// @param[in] i_current_cke the CKE for this instruction
/// @param[in] i_rank_config rank configs relative to memport pos
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode insert_des<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
    size_t& io_inst_count,
    const uint8_t i_current_cke,
    const mss::ccs::rank_configuration i_rank_config)
{
    if (io_inst_count == 0)
    {
        FAPI_INF("No des_command needed at array start for explorer %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    using TT = ccsTraits<mss::mc_type::EXPLORER>;
    constexpr uint64_t CCS_ARR0_ZERO = TT::CCS_ARR0_START;
    constexpr uint64_t CCS_ARR1_ZERO = TT::CCS_ARR1_START;

    // Set up des with idle - explorer default 0 at end of inst arr
    auto l_des =  mss::ccs::des_command<mss::mc_type::EXPLORER>();

    FAPI_ASSERT(io_inst_count <= TT::MAX_INST_DEPTH,
                fapi2::MSS_CONCURRENT_CCS_EXCEEDS_INSTRUCTION_LIMIT()
                .set_MC_TARGET(i_target)
                .set_REQUESTED_INSTRUCTIONS(io_inst_count)
                .set_MAX_INSTRUCTIONS(TT::MAX_INST_DEPTH),
                "%s over CCS concurrent instructions limit, requested %d instructions",
                mss::c_str(i_target), io_inst_count);

    // First, update the current instruction's chip selects for the current port
    FAPI_TRY(l_des.configure_rank(i_port, i_rank_config),
             "Error configuring rank in ccs::execute on port %s", mss::c_str(i_port));

    // Now, configure the idles and repeats within this instruction
    FAPI_TRY(l_des.configure_idles_and_repeats(i_port),
             "Error configuring idles and repeats in ccs::execute on port %s", mss::c_str(i_port));

    // Finally, configure the parity if needed
    FAPI_TRY(l_des.compute_parity(i_port, i_rank_config),
             "Error computing and configuring parity in ccs::execute on port %s", mss::c_str(i_port));

    l_des.set_cke_helper(i_current_cke);

    // Insert a DES as our last instruction. DES is idle state anyway and having this
    // here as an instruction forces the CCS engine to wait the delay specified in
    // the last instruction in this array (which it otherwise doesn't do.)
    l_des.arr1.template setBit<TT::ARR1_END>();
    FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + io_inst_count, l_des.arr0) );
    FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + io_inst_count, l_des.arr1) );

#ifndef __PPE__
    FAPI_INF("ccs inst %d fixup: 0x%016lX 0x%016lX (0x%lx, 0x%lx) %s",
             io_inst_count, l_des.arr0, l_des.arr1,
             CCS_ARR0_ZERO + io_inst_count, CCS_ARR1_ZERO + io_inst_count, mss::c_str(i_target));
#endif

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;

}
} // namespace workaround
} // namespace ccs
} // namespace mss
