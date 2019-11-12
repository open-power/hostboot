/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/ccs_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
/// @file ccs_workarounds.H
/// @brief Contains CCS workarounds
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _CCS_WORKAROUNDS_H
#define _CCS_WORKAROUNDS_H

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <lib/shared/mss_const.H>

#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/nimbus_find.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>


namespace mss
{

namespace ccs
{

namespace workarounds
{

///
/// @brief Issues the PDA exit command
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in,out] io_program - the CCS program
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
/// @note The PHY traps both the a-side and b-side MRS's into the same shadow register
/// After the a-side MRS exits PDA, the b-side MRS will not be taken out of PDA mode
/// To workaround this problem, a-side MRS is issued, then the shadow register is modified to have PDA mode enabled
/// Then the b-side MRS is issued
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank,
                        ccs::program& io_program );

///
/// @brief Re-enables PDA mode on a given rank in the shadow registers
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode enable_pda_shadow_reg( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank );

///
/// @brief Holds the given cke low in a CCS instruction
/// @param[in,out] io_cke - the cke bit that needs to remain low
/// @param[in,out] io_inst - the CCS instruction
///
inline void hold_cke_low_helper( fapi2::buffer<uint8_t>& io_cke,
                                 ccs::instruction_t& io_inst )
{
    fapi2::buffer<uint8_t> l_cur_cke;
    io_inst.arr0.extractToRight<MCBIST_CCS_INST_ARR0_00_DDR_CKE, MCBIST_CCS_INST_ARR0_00_DDR_CKE_LEN>(l_cur_cke);
    io_cke &= l_cur_cke;
    io_inst.arr0.insertFromRight<MCBIST_CCS_INST_ARR0_00_DDR_CKE, MCBIST_CCS_INST_ARR0_00_DDR_CKE_LEN>(io_cke);
}

///
/// @brief Holds the lower order rank cke low in higher order rank instruction
/// @param[in,out] io_program - CCS program with instructions on multi-rank DIMM
///
inline void hold_cke_low( ccs::program& io_program )
{
    fapi2::buffer<uint8_t> l_cke(CKE_HIGH);

    for ( auto& l_inst : io_program.iv_instructions )
    {
        hold_cke_low_helper( l_cke, l_inst );
    }
}

///
/// @brief Holds the given cke high in a CCS instruction
/// @param[in,out] io_cke - the cke bit that needs to remain high
/// @param[in,out] io_inst - the CCS instruction
///
inline void hold_cke_high_helper( fapi2::buffer<uint8_t>& io_cke,
                                  ccs::instruction_t& io_inst )
{
    fapi2::buffer<uint8_t> l_cur_cke;
    io_inst.arr0.extractToRight<MCBIST_CCS_INST_ARR0_00_DDR_CKE, MCBIST_CCS_INST_ARR0_00_DDR_CKE_LEN>(l_cur_cke);
    io_cke |= l_cur_cke;
    io_inst.arr0.insertFromRight<MCBIST_CCS_INST_ARR0_00_DDR_CKE, MCBIST_CCS_INST_ARR0_00_DDR_CKE_LEN>(io_cke);
}

///
/// @brief Holds the lower order rank cke high in higher order rank instruction
/// @param[in,out] io_inst - CCS program with instructions on multi-rank DIMM
///
inline void hold_cke_high( std::vector<ccs::instruction_t>& io_inst )
{
    fapi2::buffer<uint8_t> l_cke(CKE_LOW);

    for ( auto& l_inst : io_inst )
    {
        hold_cke_high_helper( l_cke, l_inst );
    }
}

///
/// @brief Holds the lower order rank cke high in higher order rank instruction
/// @param[in,out] io_program - CCS program with instructions on multi-rank DIMM
///
inline void hold_cke_high( ccs::program& io_program )
{
    fapi2::buffer<uint8_t> l_cke(CKE_LOW);

    for ( auto& l_inst : io_program.iv_instructions )
    {
        hold_cke_high_helper( l_cke, l_inst );
    }
}

///
/// @brief Preload the CCS program for epow
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @return FAPI2_RC_SUCCSS iff ok
/// @note This is written specifically to support EPOW on NVDIMM
///
fapi2::ReturnCode preload_ccs_for_epow( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                        ccs::program& i_program);

namespace nvdimm
{

///
/// @brief add_refreshes() helper
/// @param[in] i_target The MCA target where the program will be executed on
/// @param[in,out] i_program the MCBIST ccs program to append the refreshes
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode add_refreshes_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       mss::ccs::program& io_program);

///
/// @brief Adds refreshes at the beginning and end of the program
/// @param[in] i_target The MCA target where the program will be executed on
/// @param[in,out] io_program the MCBIST ccs program to add the refreshes
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode add_refreshes(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                mss::ccs::program& io_program);

///
/// @brief Execute a set of CCS instructions
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_port The port target that the array is for
/// @return FAPI2_RC_SUCCSS iff ok
/// @note This is a copy of execute() with minor tweaks to the namespace and single port only
///
fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                           mss::ccs::program& i_program,
                           const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_port);

///
/// @brief Execute the contents of the CCS array with ccs_addr_mux_sel control
/// @param[in] i_target The MCBIST containing the array
/// @param[in] i_program the MCBIST ccs program - to get the polling parameters
/// @param[in] i_port The port target that the array is for
/// @return FAPI2_RC_SUCCESS iff success
/// @note This is the exact same copy of execute_inst_array() in ccs.H with changes
///       to ccs_addr_mux_sel before and after the execute. This is required to ensure
///       CCS can properly drive the bus during the nvdimm post-restore sequence.
///
fapi2::ReturnCode execute_inst_array(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                     mss::ccs::program& i_program,
                                     fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_port);
}

namespace wr_lvl
{

///
/// @brief Updates an MRS to have the desired Qoff value
/// @param[in,out] io_mrs - the MRS to update
/// @param[in] i_state - the state for the qoff in the MRS
///
void update_mrs(mss::ddr4::mrs01_data& io_mrs, const mss::states i_state);

///
/// @brief Adds in an MRS on a per-rank basis based upon qoff
/// @param[in] i_target - the target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in] i_state - the state of qoff
/// @param[in,out] io_inst the instruction to fixup
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_mrs(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                          const uint64_t i_rank,
                          const mss::states& i_state,
                          std::vector<ccs::instruction_t>& io_inst);

///
/// @brief Gets a vector of ranks that are not going to be calibrated in the given rank pair
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[out] o_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode get_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        std::vector<uint64_t>& o_ranks);

///
/// @brief Adds the non-primary ranks from a rank pair to a ranks vector
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_non_primary_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        std::vector<uint64_t>& io_ranks);

///
/// @brief Adds all ranks from a rank pair to a ranks vector
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_ranks_from_pair(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rp,
                                      std::vector<uint64_t>& io_ranks);

///
/// @brief Adds a rank to the ranks vector if it is valid
/// @param[in] i_rank - the rank to add to the vector
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
///
void add_rank_to_vector(const uint64_t i_rank, std::vector<uint64_t>& io_ranks);

///
/// @brief Enables or disables the DQ outputs on all non-calibrating ranks
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in] i_state - the state of qoff
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode configure_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const mss::states& i_state);

} // ns wr_lvl

} // ns workarounds

} // ns ccs

} // ns mss

#endif
