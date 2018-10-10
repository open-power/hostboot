/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file lib/phy/mss_lrdimm_training.C
/// @brief LRDIMM training implementation
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/shared/mss_const.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/dimm/ddr4/data_buffer_ddr4_nimbus.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/phy/mss_training.H>
#include <lib/mc/port.H>
#include <lib/rosetta_map/rosetta_map.H>
#include <lib/dimm/ddr4/pba.H>
#include <lib/eff_config/timing.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/phy/mss_lrdimm_training.H>


#ifdef LRDIMM_CAPABLE
    #include <lib/phy/mss_lrdimm_training_helper.H>
#endif

namespace mss
{
namespace ccs
{
///
/// @brief Loads a WRITE command to the program of ccs instructions
/// @param[in] i_target Dimm Target
/// @param[in] i_rank Rank
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in] i_column_addr Row Address to Write
/// @return the write auto-precharge instruction
///
ccs::instruction_t wra_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                             const uint64_t i_rank,
                             const fapi2::buffer<uint64_t>& i_bank_addr,
                             const fapi2::buffer<uint64_t>& i_bank_group_addr,
                             const fapi2::buffer<uint64_t>& i_column_addr )
{
    ccs::instruction_t l_inst (i_rank); // sets CSn bits based on rank
    constexpr uint8_t MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_10 = 10;
    constexpr uint8_t MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_12 = 12;

    l_inst = ccs::wr_command(i_rank, i_bank_addr, i_bank_group_addr, i_column_addr);

    // Set A10 hi for auto precharge
    l_inst.arr0.template setBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_10>();
    // Set A12 hi for b8 fly
    l_inst.arr0.template setBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_12>();

    return l_inst;
}

///
/// @brief Loads a READ command to the program of ccs instructions
/// @param[in] i_target Dimm Target
/// @param[in] i_rank Rank
/// @param[in] i_bank_addr Bank Address
/// @param[in] i_bank_group_addr Bank Group Address
/// @param[in] i_column_addr Row Address to Read
/// @return the Device Deselect CCS instruction
ccs::instruction_t rda_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                             const uint64_t i_rank,
                             const fapi2::buffer<uint64_t>& i_bank_addr,
                             const fapi2::buffer<uint64_t>& i_bank_group_addr,
                             const fapi2::buffer<uint64_t>& i_column_addr )
{
    ccs::instruction_t l_inst = ccs::rda_command(i_rank, i_bank_addr, i_bank_group_addr,
                                i_column_addr);// sets CSn bits based on rank
    constexpr uint8_t MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_12 = 12;

    // Set A12 LOW for BC4, HI for BL8
    l_inst.arr0.template setBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_12>();

    return l_inst;
}

///
/// @brief Loads odt command to the program of ccs instructions
/// @param[in] i_odt_values odt value
/// @param[in] i_repeat the number of cycles to hold the ODT
/// @return the Device Deselect CCS instruction
///
ccs::instruction_t odt_load(const uint8_t i_odt_values, const uint64_t i_repeat)
{
    auto l_odt = mss::ccs::odt_command(i_odt_values, i_repeat);

    // Set RAS HI
    l_odt.arr0.template setBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_16>();
    // Set CAS_n HI
    l_odt.arr0.template setBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_15>();
    // Set WE_n HI
    l_odt.arr0.template setBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_14>();

    return l_odt;
}

///
/// @brief Configures registers for ccs execution
/// @param[in] fapi2_mcbist_target The MCBIST target
/// @param[in] fapi2_mca_target The MCA target
/// @param[in, out] modeq_reg A buffer that holds data to write into ccs mode register
/// @param[in, out] ecccntl_reg A buffer that holds data to write into recr register
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode config_ccs_regs(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& fapi2_mcbist_target,
                                  const fapi2::Target<fapi2::TARGET_TYPE_MCA>& fapi2_mca_target,
                                  fapi2::buffer<uint64_t>& modeq_reg,
                                  fapi2::buffer<uint64_t>& ecccntl_reg)
{
// configure modeq register
    fapi2::buffer<uint64_t> l_temp = 0;
    FAPI_TRY(mss::getScom(fapi2_mcbist_target, MCBIST_CCS_MODEQ, modeq_reg));
    l_temp = modeq_reg;
    l_temp.template clearBit<MCBIST_CCS_MODEQ_NTTM_MODE>();     // 1 = nontraditional transparent mode
    l_temp.template clearBit<MCBIST_CCS_MODEQ_CFG_DGEN_FIXED_MODE>();

    l_temp.template clearBit<MCBIST_CCS_MODEQ_STOP_ON_ERR>();      // 1 = stop on ccs error
    l_temp.template setBit<MCBIST_CCS_MODEQ_UE_DISABLE>();      // 1 = hardware ignores UEs
    l_temp.template setBit<MCBIST_CCS_MODEQ_COPY_CKE_TO_SPARE_CKE>();       // 1 = cope CKE to spare CKE
    l_temp.template setBit<MCBIST_CCS_MODEQ_CFG_PARITY_AFTER_CMD>();       // 1 = OE driven on parity cycle
    l_temp.template setBit<MCBIST_CCS_MODEQ_IDLE_PAT_ACTN>();       // ACTn Idle
    l_temp.template setBit<MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_16>();       // RASn Idle
    l_temp.template setBit<MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_15>();       // CASn Idle
    l_temp.template setBit<MCBIST_CCS_MODEQ_IDLE_PAT_ADDRESS_14>();       // WEn Idle
    l_temp.template clearBit<MCBIST_CCS_MODEQ_DDR_PARITY_ENABLE>();     // 0 = hardware sets parity
    FAPI_TRY(mss::putScom(fapi2_mcbist_target, MCBIST_CCS_MODEQ, l_temp));

    FAPI_TRY(mss::getScom(fapi2_mca_target, MCA_RECR, ecccntl_reg));
    l_temp = ecccntl_reg;
    l_temp.template insertFromRight<6, 3>(0b001);       // setup read delay pointer
    FAPI_TRY(mss::putScom(fapi2_mca_target, MCA_RECR, l_temp));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restores registers to original values before ccs execution
/// @param[in] i_mcbist_target The MCBIST target
/// @param[in] i_mca_target The MCA target
/// @param[in] i_modeq_reg Buffer that holds data to write into ccs mode register
/// @param[in] i_ecccntl_reg Buffer that holds data to write into recr register
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode revert_config_regs(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_mcbist_target,
                                     const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_mca_target,
                                     const fapi2::buffer<uint64_t>& i_modeq_reg,
                                     const fapi2::buffer<uint64_t>& i_ecccntl_reg)
{
    // Configure ccs mode register:
    FAPI_TRY(mss::putScom(i_mcbist_target, MCBIST_CCS_MODEQ, i_modeq_reg));

    // Configure recr register
    FAPI_TRY(mss::putScom(i_mca_target, MCA_RECR, i_ecccntl_reg));

fapi_try_exit:
    return fapi2::current_err;
}

}// ns ccs
namespace training
{

namespace lrdimm
{

///
/// @brief Swizzles a DQ from the MC perspective to the DIMM perspective
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_mc_dq the DQ on the MC perspective to swizzle to the buffer's perspective
/// @param[out] o_buffer_dq the DQ number from the buffer's perspective
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mc_to_dimm_dq(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_mc_dq,
                                uint64_t& o_buffer_dq)
{
    uint64_t l_c4_dq = 0;
    uint8_t* l_dimm_dq_ptr = nullptr;
    uint8_t l_dimm_to_c4[MAX_DQ_BITS] = {};

    // First get the c4 DQ
    FAPI_TRY(rosetta_map::mc_to_c4<rosetta_type::DQ>( i_target, i_mc_dq, l_c4_dq ));

    // Now get the DIMM DQ
    FAPI_TRY(vpd_dq_map(i_target, &l_dimm_to_c4[0]));
    l_dimm_dq_ptr = std::find(l_dimm_to_c4, l_dimm_to_c4 + MAX_DQ_BITS, l_c4_dq);

    // Check that we got a good value
    FAPI_ASSERT(l_dimm_dq_ptr != l_dimm_to_c4 + MAX_DQ_BITS,
                fapi2::MSS_LOOKUP_FAILED()
                .set_KEY(l_c4_dq)
                .set_DATA(i_mc_dq)
                .set_TARGET(i_target));

    // Now return that value
    o_buffer_dq = *l_dimm_dq_ptr;

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Swizzles a DQ from the DRAM perspective to the buffer's perspective
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_mc_dq the DQ on the MC perspective to swizzle to the buffer's perspective
/// @param[out] o_buffer_dq the DQ number from the buffer's perspective
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mc_to_buffer(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_mc_dq,
                               uint64_t& o_buffer_dq)
{
    FAPI_TRY(mc_to_dimm_dq(i_target, i_mc_dq, o_buffer_dq));

    // Each buffer is a byte and we want the bit from the buffer's perspective
    o_buffer_dq = o_buffer_dq % BITS_PER_BYTE;

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Checks if a buffer's nibbles are swizzled
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_buffer the buffer on which to see if the nibbles are swizzled
/// @param[out] o_are_swizzled true if the buffer's nibbles are swizzled
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode are_buffers_nibbles_swizzled(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_buffer,
        bool& o_are_swizzled)
{
    const auto l_mc_dq = i_buffer * BITS_PER_BYTE;
    uint64_t l_buffer_dq = 0;
    FAPI_TRY(mc_to_buffer(i_target, l_mc_dq, l_buffer_dq));

    // Now, checks if the nibble is swizzled
    // We're swizzled if the 0'th DQ from the MC perspective is on buffer's nibble 1
    o_are_swizzled = (1 == (l_buffer_dq / BITS_PER_NIBBLE));
    FAPI_DBG("%s buffer:%u %s swizzled mc_dq:%u buffer_dq:%u",
             mss::c_str(i_target), i_buffer, o_are_swizzled ? "are" : "not", l_mc_dq, l_buffer_dq);

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Issues initial pattern write to all ranks in the rank pair
/// @param[in] i_target the MCA target on which to operate
/// @parma[in] i_rp the rank pair on which to operate
/// @parma[in] i_pattern the pattern to program into the MPR
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mpr_pattern_wr_all_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint32_t i_pattern)
{
    std::vector<uint64_t> l_ranks;

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in mrep::run %s",
              mss::c_str(i_target) );

    // Loops over all ranks within this rank pair
    for (const auto l_rank : l_ranks)
    {
        FAPI_TRY(mpr_pattern_wr_rank(i_target, l_rank, i_pattern));
    };

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Issues initial pattern write a specific rank
/// @param[in] i_target the MCA target on which to operate
/// @parma[in] i_rank the rank to setup for initial pattern write
/// @parma[in] i_pattern the pattern to program into the MPR
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mpr_pattern_wr_rank(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rank,
                                      const uint32_t i_pattern)
{
    // Skip over invalid ranks (NO_RANK)
    if(i_rank == NO_RANK)
    {
        FAPI_DBG("%s NO_RANK was passed in %u. Skipping", mss::c_str(i_target), i_rank)
        return fapi2::FAPI2_RC_SUCCESS;
    }

    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Gets the DIMM target
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target, i_rank, l_dimm),
             "%s failed to get DIMM target for rank %u", mss::c_str(i_target), i_rank);

    // Ok, MPR write
    // We need to
    // 1) MRS into MPR mode
    // 2) Disable address inversion, so we set our values correctly
    //    We need to disable address inversion so both A-side and B-side get the same pattern written into the MPR registers
    // 3) Write the patterns in according to the bank address
    // 4) Restore the default address inversion
    // 5) MRS out of MPR mode

    // 1) MRS into MPR mode
    FAPI_TRY( mss::ddr4::mpr_load(l_dimm,
                                  fapi2::ENUM_ATTR_EFF_MPR_MODE_ENABLE,
                                  i_rank,
                                  l_program.iv_instructions) );

    // 2) Disable address inversion
    // We need to disable address inversion so both A-side and B-side get the same pattern written into the MPR registers
    FAPI_TRY(disable_address_inversion(l_dimm, l_program.iv_instructions));

    // 3) Write the patterns in according to the bank address
    FAPI_INF("%s are we failing here rank%u", mss::c_str(i_target), i_rank);
    FAPI_TRY(add_mpr_pattern_writes(l_dimm,
                                    i_rank,
                                    i_pattern,
                                    l_program.iv_instructions));

    // 4) Restore the default address inversion
    FAPI_TRY(restore_address_inversion(l_dimm, l_program.iv_instructions));

    // 5) MRS out of MPR mode
    FAPI_TRY( mss::ddr4::mpr_load(l_dimm,
                                  fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE,
                                  i_rank,
                                  l_program.iv_instructions) );

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

//
/// @brief Does a CCS NTTM mode read
/// @param[in] i_target - the MCA target on which to operate
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode execute_nttm_mode_read(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{

    using TT = ccsTraits<mss::mc_type::NIMBUS>;

    // A hardware bug requires us to increase our delay significanlty for NTTM mode reads
    constexpr uint64_t SAFE_NTTM_READ_DELAY = 0x40;
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Note: CKE are enabled by default in the NTTM mode read command, so we should be good to go
    // set the NTTM read mode
    auto l_nttm_read = mss::ccs::nttm_read_command();
    l_nttm_read.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(SAFE_NTTM_READ_DELAY);
    l_program.iv_instructions.push_back(l_nttm_read);

    // turn on NTTM mode
    FAPI_TRY( mss::ccs::configure_nttm(l_mcbist, mss::states::ON),
              "%s failed to turn on NTTM mode", mss::c_str(i_target) );

    // Issue CCS
    FAPI_TRY(ccs::execute( l_mcbist,
                           l_program,
                           i_target) );
    // turn off NTTM mode
    FAPI_TRY( mss::ccs::configure_nttm(l_mcbist, mss::states::OFF),
              "%s failed to turn off NTTM mode", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

#ifdef LRDIMM_CAPABLE
///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrep::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        const uint8_t i_abort_on_error ) const
{
    FAPI_INF("%s setting up the read pointer enable rp%u", mss::c_str(i_target), i_rp);
    FAPI_TRY( mss::setup_read_pointer_delay(i_target));

    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::ON),
              "%s failed to write force dq capture", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrep::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::OFF),
              "%s failed to write exit dq capture", mss::c_str(i_target) );

    // Clears the FIR's that can get set by training
    // They're not real, so we want to clear them and move on
    FAPI_TRY(mss::training::lrdimm::workarounds::clear_firs(i_target), "%s failed to clear FIRs", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the results to buffer generate PBA commands
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_mrep_result a vector of the MREP result
/// @param[out] o_container the PBA commands structure
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note a little helper to allow us to unit test that we generate the PBA commands ok
///
fapi2::ReturnCode mrep::write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_mrep_result,
        mss::ddr4::pba::commands& o_container) const
{
    uint8_t l_buffer = 0;
    // Clears out the PBA container to ensure we don't issue undesired commands
    o_container.clear();

    // Get's the MCA
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Looops through and generates the PBA commands
    for(const auto& l_recorder : i_mrep_result)
    {
        bool l_are_nibbles_swapped = false;
        FAPI_TRY(are_buffers_nibbles_swizzled(l_mca, l_buffer, l_are_nibbles_swapped));

        {
            const auto l_result_nibble0 = l_are_nibbles_swapped ?
                                          l_recorder.second.iv_delay :
                                          l_recorder.first.iv_delay;
            const auto l_result_nibble1 = l_are_nibbles_swapped ?
                                          l_recorder.first.iv_delay :
                                          l_recorder.second.iv_delay;

            FAPI_DBG("%s MREP rank%u buffer:%u final values (0x%02x,0x%02x) %s swapped BC2x:0x%02x BC3x:0x%02x",
                     mss::c_str(l_mca), i_rank, l_buffer, l_recorder.first.iv_delay, l_recorder.second.iv_delay,
                     l_are_nibbles_swapped ? "are" : "not", l_result_nibble0, l_result_nibble1);

            // Function space is derived from the rank
            // 2 is for Nibble 0, 3 is for Nibble 1
            // Data corresponds to the final setting we have
            // Delay is for PBA, bumping it way out so we don't have issues
            constexpr uint64_t PBA_DELAY = 255;
            constexpr uint64_t BCW_NIBBLE0 = 0x02;
            constexpr uint64_t BCW_NIBBLE1 = 0x03;

            const mss::cw_info MREP_FINAL_SET_BCW_N0( i_rank,
                    BCW_NIBBLE0,
                    l_result_nibble0,
                    PBA_DELAY,
                    mss::CW8_DATA_LEN,
                    mss::cw_info::BCW);
            const mss::cw_info MREP_FINAL_SET_BCW_N1( i_rank,
                    BCW_NIBBLE1,
                    l_result_nibble1,
                    PBA_DELAY,
                    mss::CW8_DATA_LEN,
                    mss::cw_info::BCW);

            // Each buffer contains two nibbles
            // Each nibble corresponds to one BCW
            // Add in the buffer control words
            FAPI_TRY(o_container.add_command(i_target, l_buffer, MREP_FINAL_SET_BCW_N0));
            FAPI_TRY(o_container.add_command(i_target, l_buffer, MREP_FINAL_SET_BCW_N1));
        }

        ++l_buffer;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write the result to buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_mrep_result a vector of the MREP results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrep::write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_mrep_result) const
{
    mss::ddr4::pba::commands l_container;

    // Sets up the PBA commands
    FAPI_TRY(write_result_to_buffers_helper( i_target,
             i_rank,
             i_mrep_result,
             l_container),
             "%s rank%u failed generating PBA commands",
             mss::c_str(i_target), i_rank);

    // Issue the PBA to set the final MREP results
    FAPI_TRY(mss::ddr4::pba::execute_commands(l_container));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets MREP Delay value
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank to operate on - drives the function space select
/// @param[in] delay value /64 Tck - MREP delay value
/// @return FAPI2_RC_SUCCESS if okay
/// @note Sets DA setting for buffer control word (F[3:0]BC2x, F[3:0]BC3x)
///
fapi2::ReturnCode mrep::set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_rank,
                                  const uint8_t i_delay ) const
{
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    std::vector<cw_info> l_bcws =
    {
        {i_rank, NIBBLE0_BCW_NUMBER, i_delay, mss::tmrd_l2(), mss::CW8_DATA_LEN, cw_info::BCW},
        {i_rank, NIBBLE1_BCW_NUMBER, i_delay, mss::tmrd_l2(), mss::CW8_DATA_LEN, cw_info::BCW},
    };

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the nibble flags for the invalid data callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @param[out] o_invalid_count number of invalid data occurances seen
/// @return invalid data nibble flags
/// @note Invalid data is defined as not having all zeros or all ones
///
uint32_t mrep::flag_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_rank,
                                  const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders,
                                  uint64_t& o_invalid_count) const
{
    o_invalid_count = 0;
    uint8_t l_buffer = 0;

    // Per nibble invalid data flags - bitmap
    uint32_t l_per_nibble_flags = 0;

    for(const auto& l_recorder : i_recorders)
    {

        // This is a coding issue here, just break out of the loop
        // We should never have more data than recorders
        // No need to log it, just recover and continue
        if(l_buffer >= MAX_LRDIMM_BUFFERS)
        {
            FAPI_ERR("%s rank%u saw buffer%u when number of buffers is %u. Continuing gracefully",
                     mss::c_str(i_target), i_rank, l_buffer, MAX_LRDIMM_BUFFERS);
            break;
        }

        // Updates the bitmap
        o_invalid_count += l_recorder.first.iv_invalid_data_count + l_recorder.second.iv_invalid_data_count;
        append_nibble_flags(l_recorder.first.iv_invalid_data_count != mrep_dwl_recorder::CLEAN,
                            l_recorder.second.iv_invalid_data_count != mrep_dwl_recorder::CLEAN,
                            l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if invalid data is seen during this calibration step
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
/// @note Invalid data is defined as not having all zeros or all ones
///
fapi2::ReturnCode mrep::callout_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    // We also count the number of occurances of invalid data across the port/rank
    // This count gives more insight into the fails
    // Low counts mean one off data glitches
    // High counts indicate that one or more nibbles are having issues
    uint64_t l_invalid_data_count = 0;
    const auto l_per_nibble_flags = flag_invalid_data( i_target, i_rank, i_recorders, l_invalid_data_count);

    FAPI_TRY(callout::invalid_data( i_target,
                                    i_rank,
                                    l_per_nibble_flags,
                                    l_invalid_data_count,
                                    mss::cal_steps::MREP,
                                    "MREP"));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the nibble flags for the no transition callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return no transition nibble flags
///
uint32_t mrep::flag_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_rank,
                                   const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    uint8_t l_buffer = 0;

    // Per nibble invalid data flags - bitmap
    uint32_t l_per_nibble_flags = 0;

    for(const auto& l_recorder : i_recorders)
    {

        // This is a coding issue here, just break out of the loop
        // We should never have more data than recorders
        // No need to log it, just recover and continue
        if(l_buffer >= MAX_LRDIMM_BUFFERS)
        {
            FAPI_ERR("%s rank%u saw buffer%u when number of buffers is %u. Continuing gracefully",
                     mss::c_str(i_target), i_rank, l_buffer, MAX_LRDIMM_BUFFERS);
            break;
        }

        const bool l_nibble0_no_transition = !l_recorder.first.iv_seen0 || !l_recorder.first.iv_seen1;
        const bool l_nibble1_no_transition = !l_recorder.second.iv_seen0 || !l_recorder.second.iv_seen1;

        // Updates the bitmap
        append_nibble_flags(l_nibble0_no_transition, l_nibble1_no_transition, l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if a rank does not see a 0->1 transition
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode mrep::callout_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    // Per nibble weird data and no transition flags - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    uint32_t l_per_nibble_flags = flag_no_transition( i_target, i_rank, i_recorders);

    // Error checking here
    FAPI_ASSERT(l_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_NO_TRANSITION()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(mss::cal_steps::MREP)
                .set_NIBBLE_FLAGS(l_per_nibble_flags),
                "%s rank%u has seen invalid data on nibbles 0x%x in MREP",
                mss::c_str(i_target), i_rank, l_per_nibble_flags);


    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrep::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                             const uint64_t i_rp,
                             const uint8_t i_abort_on_error ) const
{
    constexpr uint8_t MPR_LOCATION0 = 0;
    std::vector<uint64_t> l_ranks;
    uint8_t l_rank_index = 0;
    FAPI_INF("%s RP%d starting calibrate MREP", mss::c_str(i_target), i_rp);

    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in mrep::run %s",
              mss::c_str(i_target) );

    // Disable all rank of 2 dimm's before training
    for (const auto& l_dimm : l_dimms)
    {
        FAPI_TRY(set_rank_presence(l_dimm, RANK_PRESENCE_MASK));
    }

    // Loops over all ranks within this rank pair
    // MREP is a buffer to DRAM calibration step, so we need to calibrate all ranks seperately
    for (const auto& l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            FAPI_DBG("%s RP%u l_rank_index:%u is being skipped as it's not configured (%u)",
                     mss::c_str(i_target), i_rp, l_rank_index, l_rank);
            ++l_rank_index;
            continue;
        }

        FAPI_DBG("%s RP%u rank index number %u has rank %u", mss::c_str(i_target), i_rp, l_rank_index, l_rank);
        const auto& l_dimm = l_dimms[mss::rank::get_dimm_from_rank(l_rank)];

        // Added in for cronus debug - not needed for hostboot
#ifndef __HOSTBOOT_MODULE
        // Prints the header
        FAPI_DBG("%s CARD  AAAAAAAAAA RCD BBBBBBBB", mss::c_str(i_target));
        FAPI_DBG("%s CARD  0000000000 RCD 11111111", mss::c_str(i_target));
        FAPI_DBG("%s CARD  0516273849 RCD 04152637", mss::c_str(i_target));
#endif

        // Vector represents the number of LRDIMM buffers
        // The pair represents the two nibbles that we need to calibrate within the buffer
        std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>> l_results_recorder(MAX_LRDIMM_BUFFERS);
        //Loop through all of our delays multiple times to reduce noise issues
        std::vector<mrep_dwl_result> l_loop_results(MREP_DWL_LOOP_TIMES);

        const auto l_dimm_rank = mss::index(l_rank);

        // 1) Gets the ranks on which to put DRAM into MPR mode
        FAPI_TRY( mpr_load(l_dimm, fapi2::ENUM_ATTR_EFF_MPR_MODE_ENABLE, l_rank), "%s failed mpr_load rank%u",
                  mss::c_str(l_dimm), l_rank);

#ifdef LRDIMM_CAPABLE
        // 2) set the rank presence
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence(l_rank)),
                 "%s failed set rank%u",
                 mss::c_str(l_dimm), l_rank);

        // 3) put buffer, dram into read preamble training mode
        FAPI_TRY(set_dram_rd_preamble_mode(l_dimm, mss::states::ON, l_rank), "%s failed set_dram_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
        FAPI_TRY(set_buffer_rd_preamble_mode(l_dimm, mss::states::ON), "%s failed set_buffer_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
#endif

        // 4) Put the buffer in MREP mode -> host issues BCW's
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::MREP), "%s failed set_buffer_training", mss::c_str(l_dimm));

        // Loop through all of our delays
        for(auto& l_loop_result : l_loop_results)
        {
            for(uint8_t l_delay = 0; l_delay < MREP_DWL_MAX_DELAY; ++l_delay)
            {
                // 5) Set the MREP l_delay -> host issues BCW's
                FAPI_TRY(set_delay(l_dimm, l_dimm_rank, l_delay), "%s failed set_delay rank%u delay%u", mss::c_str(l_dimm),
                         l_rank, l_delay);

                // 6) Do an MPR read -> host issues RD command to the DRAM
                FAPI_TRY( mpr_read(l_dimm, MPR_LOCATION0, l_rank), "%s failed mpr_read rank%u delay%u", mss::c_str(l_dimm),
                          l_rank, l_delay);

                // 6.1) Do an NTTM mode read -> forces the logic to read out the data
                FAPI_TRY(execute_nttm_mode_read(i_target));

                FAPI_TRY(get_result(l_dimm, mss::cal_steps::MREP, l_delay, l_loop_result, l_results_recorder));
            } //l_delay loop
        }

        // 7) Analyze the results -> host/FW read from CCS results and go
        FAPI_TRY( analyze_result(l_dimm, mss::cal_steps::MREP, l_loop_results, l_results_recorder),
                  "%s failed analyze_mrep_result rank%u",
                  mss::c_str(l_dimm), l_rank);

        // 8) Error check -> if we had stuck 1 or stuck 0 (never saw a 0 to 1 or a 1 to 0 transition) exit out with an error
        FAPI_TRY(error_check(l_dimm, l_rank, l_results_recorder), "%s failed error_check rank:%u", mss::c_str(l_dimm), l_rank);

        // 9) Apply MREP offset to ranks based upon tCK RD preamble mode
        FAPI_TRY(apply_final_offset(l_dimm, l_results_recorder), "%s failed apply_final_offset rank%u", mss::c_str(l_dimm),
                 l_rank);

        // 10) take the buffer out of MREP mode -> host issues BCW's
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::NORMAL), "%s failed set_buffer_training", mss::c_str(l_dimm));

#ifdef LRDIMM_CAPABLE
        // 11) take buffer, dram out of read preamble training mode
        FAPI_TRY(set_dram_rd_preamble_mode(l_dimm, mss::states::OFF, l_rank), "%s failed set_dram_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
        FAPI_TRY(set_buffer_rd_preamble_mode(l_dimm, mss::states::OFF), "%s failed set_buffer_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
#endif

        // 12) take DRAM out of MPR -> host issues MRS
        FAPI_TRY( mpr_load(l_dimm, fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE, l_rank), "%s failed mpr_load %u", mss::c_str(l_dimm),
                  l_rank);

        // 13) Write final values into the buffers -> host issues BCW's in PBA mode (values are calculated in step 7)
        FAPI_TRY( write_result_to_buffers(l_dimm, l_dimm_rank, l_results_recorder), "%s failed write_result_to_buffers rank%u",
                  mss::c_str(l_dimm), l_rank);

        l_rank_index++;
    }//l_rank loop

#ifdef LRDIMM_CAPABLE

    // 14) set for two or four rank dimms
    for (const auto& l_dimm : l_dimms)
    {
        uint8_t l_rank_num = 0;
        FAPI_TRY( eff_num_master_ranks_per_dimm(l_dimm, l_rank_num) );
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence_value(l_rank_num)));
    }

#endif

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrep::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Gets the number of VREF's to run on
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_rp the rank pair on which to operate
/// @param[out] o_num_vref the number of VREF's to run against
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::BUFFER_RD_VREF>::get_num_vrefs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target,
        const uint64_t i_rp,
        uint64_t& o_num_vref) const
{
    o_num_vref = MAX_LRDIMM_BUFFERS;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Gets the lowest possible VREF
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_min_vref the number of VREF's to run against
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::BUFFER_RD_VREF>::get_min_vref( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint8_t& o_min_vref) const
{
    using TT = VREFTraits<vref_types::BUFFER_RD_VREF>;
    o_min_vref = TT::MIN_BOUND;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Gets the highest possible VREF
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_max_vref the number of VREF's to run against
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::BUFFER_RD_VREF>::get_max_vref( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint8_t& o_max_vref) const
{
    using TT = VREFTraits<vref_types::BUFFER_RD_VREF>;
    o_max_vref = TT::MAX_BOUND;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Adds a command to the command structure
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_rp the rank pair on which to operate
/// @param[in] i_index the index of the VREF to go to
/// @param[in] i_vref the VREF to go to
/// @param[in,out] io_commands the commands structure to update
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::BUFFER_RD_VREF>::add_command( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_index,
        const uint64_t i_vref,
        mss::ddr4::pba::commands& io_commands) const
{
    std::vector<uint64_t> l_ranks;
    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in add_command<BUFFER_RD_VREF> %s",
              mss::c_str(i_target) );

    for(const auto l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            continue;
        }

        // VREF delay
        constexpr uint64_t PBA_DELAY = 2000;
        const mss::cw_info BCW(FUNC_SPACE_5, DRAM_VREF_CW, uint64_t(i_vref), PBA_DELAY, CW8_DATA_LEN, cw_info::BCW);

        // Gets our DIMM from this rank
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
        FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target, l_rank, l_dimm),
                 "%s failed to get DIMM from rank%u", mss::c_str(i_target), l_rank);

        FAPI_TRY(io_commands.add_command( l_dimm, i_index, BCW ));

        // Yes, always break out of this loop - we just need to get the DIMM for this loop, so here we are
        break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Issues all of the commands from the command structure
/// @param[in] i_commands the commands structure to update
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::BUFFER_RD_VREF>::issue_commands( const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target,
        mss::ddr4::pba::commands& i_commands) const
{
    FAPI_TRY(mss::ddr4::pba::execute_commands(i_commands));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the lowest possible VREF
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_min_vref the number of VREF's to run against
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::DRAM_WR_VREF>::get_min_vref( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint8_t& o_min_vref) const
{
    using TT = VREFTraits<vref_types::DRAM_WR_VREF>;
    o_min_vref = TT::MIN_BOUND;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Gets the highest possible VREF
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_max_vref the number of VREF's to run against
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::DRAM_WR_VREF>::get_max_vref( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint8_t& o_max_vref) const
{
    using TT = VREFTraits<vref_types::DRAM_WR_VREF>;
    o_max_vref = TT::MAX_BOUND;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Gets the number of VREF's to run on
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_rp the rank pair on which to operate
/// @param[out] o_num_vref the number of VREF's to run against
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::DRAM_WR_VREF>::get_num_vrefs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target,
        const uint64_t i_rp,
        uint64_t& o_num_vref) const
{
    uint8_t l_rank_number = 0;
    std::vector<uint64_t> l_ranks;

    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
             "Failed get_ranks_in_pair in <vref_types::DRAM_WR_VREF>::get_num_vrefs %s",
             mss::c_str(i_target));

    for (const auto& l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            continue;
        }

        l_rank_number++;
    }

    o_num_vref = l_rank_number;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds a command to the command structure
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_rp the rank pair on which to operate
/// @param[in] i_index the index of the VREF to go to
/// @param[in] i_vref the VREF to go to
/// @param[in,out] io_program the program structure to update
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::DRAM_WR_VREF>::add_command( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_index,
        const uint64_t i_vref,
        mss::ccs::program& io_program) const
{
    std::vector<uint64_t> l_ranks;
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    uint64_t l_index = 0;
    constexpr uint8_t VREF_DEFALT_RANGE = 0;

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in add_command<DRAM_WR_VREF> %s",
              mss::c_str(i_target) );

    //base i_index find right rank
    for(const auto l_rank : l_ranks)
    {
        if(l_rank == NO_RANK)
        {
            continue;
        }

        if(l_index == i_index)
        {
            FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target, l_rank, l_dimm),
                      "%s Failed get_dimm_target_from_rank in add_command<DRAM_WR_VREF>",
                      mss::c_str(i_target));

            FAPI_DBG("DRAM_WR_VREF:write vref l_rank = 0x%02x l_index = 0x%02x i_vref = 0x%02x",
                     l_rank, l_index, i_vref);

            FAPI_TRY(mss::ddr4::setup_latch_wr_vref_commands_by_rank(l_dimm,
                     l_rank,
                     VREF_DEFALT_RANGE,
                     i_vref,
                     io_program.iv_instructions),
                     "%s Failed setup_latch_wr_vref_commands_by_rank in add_command<DRAM_WR_VREF>",
                     mss::c_str(i_target));
            break;
        }

        l_index++;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Issues all of the commands from the command structure
/// @param[in] i_commands the commands structure to update
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note We want to always specialize this function
///
template<>
fapi2::ReturnCode vref<vref_types::DRAM_WR_VREF>::issue_commands( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        mss::ccs::program& i_program) const
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    FAPI_TRY( mss::ccs::execute(l_mcbist, i_program, i_target), "Failed ccs execute %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the results to buffer generate PBA commands
/// @param[in] i_target the DIMM target
/// @param[in] i_result a vector of the vref result
/// @param[out] o_container the PBA commands structure
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note a little helper to allow us to unit test that we generate the PBA commands ok
///
fapi2::ReturnCode buffer_wr_vref::write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_target,
        const std::vector<recorder>& i_result,
        mss::ddr4::pba::commands& o_container) const
{
    // Get's the MCA
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    uint8_t l_buffer = 0;
    constexpr uint64_t HOST_VREF_RAG_POS = 6;
    constexpr uint64_t HOST_VREF_RAG_LEN = 1;
    uint8_t l_default_vref = 0;
    fapi2::buffer<uint8_t> l_is_m386a8k40cm2_ctd7y = 0;

    FAPI_TRY( mss::is_m386a8k40cm2_ctd7y(l_mca, l_is_m386a8k40cm2_ctd7y), "Error in p9_mss_draminit_training %s",
              mss::c_str(i_target) );

    FAPI_TRY(eff_dimm_ddr4_f5bc5x(i_target, l_default_vref));

    // Clears out the PBA container to ensure we don't issue undesired commands
    o_container.clear();

    // Looops through and generates the PBA commands
    for(const auto& l_recorder : i_result)
    {
        fapi2::buffer<uint8_t> l_bcw_value;
        fapi2::buffer<uint8_t> l_vref_value;
        bool l_range = false;

        FAPI_DBG("%s buffer wr vref buffer:%u final values l_recorder.iv_final_delay = 0x%02x",
                 mss::c_str(l_mca), l_buffer, l_recorder.iv_final_vref);

        //workaround for better margin
        if((l_is_m386a8k40cm2_ctd7y) && (mss::count_dimm(l_mca) == MAX_DIMM_PER_PORT))
        {
            constexpr uint8_t OFFSET = 2;

            //means no find 0->1 transition, use original value
            if(l_recorder.iv_final_vref == NOVLOW)
            {
                l_range = 0;
                l_vref_value = l_default_vref - OFFSET;
            }
            else
            {
                FAPI_TRY(convert_vref_value(l_recorder.iv_final_vref + OFFSET, l_range, l_vref_value));
            }
        }
        else
        {
            //means no find 0->1 transition, use original value
            if(l_recorder.iv_final_vref == NOVLOW)
            {
                ++l_buffer;
                continue;

            }

            FAPI_TRY(convert_vref_value(l_recorder.iv_final_vref, l_range, l_vref_value));
        }

        // Gets the BCW value for the buffer training control word
        FAPI_TRY(eff_dimm_ddr4_f6bc4x(i_target, l_bcw_value));

        // Modifies the BCW value accordingly
        l_bcw_value.insertFromRight<HOST_VREF_RAG_POS, HOST_VREF_RAG_LEN>(l_range);

        // Delay is for PBA, bumping it way out so we don't have issues
        constexpr uint64_t SAFE_DELAY = 20000;
        constexpr uint64_t PBA_DELAY = 255;

        const mss::cw_info FINAL_SET_BCW_RANGE( FUNC_SPACE_6,
                                                BUFF_TRAIN_CONFIG_CW,
                                                l_bcw_value,
                                                PBA_DELAY,
                                                mss::CW8_DATA_LEN,
                                                mss::cw_info::BCW);
        const mss::cw_info FINAL_SET_BCW_VREF( FUNC_SPACE_5,
                                               HOST_VREF_CW,
                                               l_vref_value,
                                               SAFE_DELAY,
                                               mss::CW8_DATA_LEN,
                                               mss::cw_info::BCW);

        // Each buffer contains two nibbles
        // Each nibble corresponds to one BCW
        // Add in the buffer control words
        FAPI_TRY(o_container.add_command(i_target, l_buffer, FINAL_SET_BCW_RANGE));
        FAPI_TRY(o_container.add_command(i_target, l_buffer, FINAL_SET_BCW_VREF));

        ++l_buffer;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write the result to buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_result a vector of the results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode buffer_wr_vref::write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::vector<recorder>& i_result) const
{
    mss::ddr4::pba::commands l_container;

    // Sets up the PBA commands
    FAPI_TRY(write_result_to_buffers_helper( i_target,
             i_result,
             l_container),
             "%s failed generating PBA commands",
             mss::c_str(i_target));

    // Issue the PBA to set the final results
    if(!l_container.empty())
    {
        FAPI_TRY(mss::ddr4::pba::execute_commands(l_container));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief analyze with each nibble
/// @param[in] i_target the MCA target
/// @param[in] i_result the result need to analyze
/// @param[in] i_buffer the buffer number
/// @param[in] i_vref the vref we set
/// @param[in, out] io_recorder we need to get and record
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode buffer_wr_vref::analyze_result_for_each_buffer( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_result,
        const uint8_t i_buffer,
        const uint8_t i_vref,
        recorder& io_recorder ) const
{
    if(i_result == 0)
    {
        io_recorder.iv_seen0 = true;
    }
    else if(i_result == 0xff)
    {
        if(io_recorder.iv_seen0)
        {
            io_recorder.iv_seen1 = true;
        }
    }

    // Record the 0->1 transition only if:
    // 1) we've seen a 0
    // 2) we've seen a 1
    // 3) we have not recorded a value prior (don't want to overwrite our good values) (not 0)
    if( (io_recorder.iv_seen0 == true) &&
        (io_recorder.iv_seen1 == true) &&
        (io_recorder.iv_final_vref == NOVLOW) )
    {
        io_recorder.iv_final_vref = i_vref;
        FAPI_DBG( "buffer_wr_vref %s buffer:%u found a 0->1 transition at vref 0x%02x",
                  mss::c_str(i_target), i_buffer, i_vref );
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief analyze the result of buffer host interface vref training
/// @param[in] i_target the MCA target
/// @param[in] i_vref the vref number we current set
/// @param[in, out] io_recorders a vector of the host interface vref training results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode buffer_wr_vref::analyze_result( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_vref,
        std::vector<recorder>& io_recorders) const
{
    data_response l_data;
    uint8_t l_buffer = 0;
    constexpr uint64_t BEATS_PER_BUFFER = 8;

    FAPI_TRY( l_data.read(i_target),
              "%s failed to read buffer_wr_vref data response vref:0x%02x",
              mss::c_str(i_target),
              i_vref );

    for(uint8_t i = 0; i < BEATS_PER_BUFFER; i++)
    {
        FAPI_DBG( "%s vref:0x%02x burst%u: 0x%02x%02x%02x%02x%02x%02x%02x%02x%02x ",
                  mss::c_str(i_target), i_vref, i,
                  l_data.iv_buffer_beat[0][i], l_data.iv_buffer_beat[1][i], l_data.iv_buffer_beat[2][i], l_data.iv_buffer_beat[3][i],
                  l_data.iv_buffer_beat[4][i], l_data.iv_buffer_beat[5][i], l_data.iv_buffer_beat[6][i], l_data.iv_buffer_beat[7][i],
                  l_data.iv_buffer_beat[8][i]);
    }

    // Note: we want to update the value of the results recorder, so no const
    for(auto& l_recorder : io_recorders)
    {
        // All beats should be the same, until proven otherwise, just use beat 0
        constexpr uint64_t DEFAULT_BEAT = 0;
        uint8_t l_buffer_result = l_data.iv_buffer_beat[l_buffer][DEFAULT_BEAT];

        // need all beat be 0xff
        for(uint8_t l_beat = 1; l_beat < BEATS_PER_BUFFER; l_beat++)
        {
            l_buffer_result = l_buffer_result & l_data.iv_buffer_beat[l_buffer][l_beat];
        }

        FAPI_DBG( "%s vref:0x%02x result buffer:%u data:0x%02x ",
                  mss::c_str(i_target), i_vref,
                  l_buffer, l_buffer_result);

        FAPI_TRY(analyze_result_for_each_buffer( i_target,
                 l_buffer_result,
                 l_buffer,
                 i_vref,
                 l_recorder) );

        l_buffer++;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief convert vref loop value to range number(1 or 2) and vref register value
/// @param[in] i_vref the loop value
/// @param[out] o_range range number
/// @param[out] o_register_value vref register value
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode buffer_wr_vref::convert_vref_value(const uint8_t& i_vref,
        bool& o_range,
        uint8_t& o_register_value)const
{
    constexpr uint64_t SIXTY_PERCENT = 0x18;

    if(i_vref < SIXTY_PERCENT)
    {
        o_range = 1;    //range 2
        o_register_value = i_vref;
    }
    else
    {
        o_range = 0;    //range 1
        o_register_value = i_vref - SIXTY_PERCENT;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Sets buffer host interface vref value
/// @param[in] i_target the DIMM target
/// @param[in] i_vref value
/// @return FAPI2_RC_SUCCESS if okay
/// @note Sets DA setting for buffer control word (F5BC5x,F6BC4x)
///
fapi2::ReturnCode buffer_wr_vref::set_vref(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_vref ) const
{
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    std::vector<cw_info> l_bcws;

    constexpr uint64_t HOST_VREF_RAG_POS = 6;
    constexpr uint64_t HOST_VREF_RAG_LEN = 1;
    constexpr uint64_t BCW_SAFE_DELAY = 2000;
    fapi2::buffer<uint8_t> l_bcw_value;
    fapi2::buffer<uint8_t> l_vref_value;
    bool l_range = false;

    uint8_t l_sim = 0;


    FAPI_TRY(convert_vref_value(i_vref, l_range, l_vref_value));
    // Gets the BCW value for the buffer training control word
    FAPI_TRY(eff_dimm_ddr4_f6bc4x(i_target, l_bcw_value));

    // Modifies the BCW value accordingly
    l_bcw_value.insertFromRight<HOST_VREF_RAG_POS, HOST_VREF_RAG_LEN>(l_range);
    l_bcws.push_back(cw_info(FUNC_SPACE_6, BUFF_TRAIN_CONFIG_CW, l_bcw_value,  mss::tmrc(), mss::CW8_DATA_LEN,
                             cw_info::BCW));
    l_bcws.push_back(cw_info(FUNC_SPACE_5, HOST_VREF_CW, l_vref_value, BCW_SAFE_DELAY, mss::CW8_DATA_LEN,
                             cw_info::BCW));

    FAPI_DBG("%s f6bc4x = 0x%02x, f5bc5x = 0x%02x for vref 0x%02x\n",  mss::c_str(i_target),
             l_bcw_value,  l_vref_value,  i_vref);

    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets buffer host interface vref value
/// @param[in] i_target the DIMM target
/// @return FAPI2_RC_SUCCESS if okay
/// @note Sets DA setting for buffer control word (F5BC5x,F6BC4x)
///
fapi2::ReturnCode buffer_wr_vref::restore_org_vref(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target) const
{
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    std::vector<cw_info> l_bcws;

    fapi2::buffer<uint8_t> l_f6bc4x;
    fapi2::buffer<uint8_t> l_f5bc5x;
    constexpr uint64_t BCW_SAFE_DELAY = 2000;

    uint8_t l_sim = 0;

    // Gets the BCW value for the buffer training control word
    FAPI_TRY(eff_dimm_ddr4_f6bc4x(i_target, l_f6bc4x));
    FAPI_TRY(eff_dimm_ddr4_f5bc5x(i_target, l_f5bc5x));

    // Modifies the BCW value accordingly
    l_bcws.push_back(cw_info(FUNC_SPACE_6, BUFF_TRAIN_CONFIG_CW, l_f6bc4x, mss::tmrc(), mss::CW8_DATA_LEN,
                             cw_info::BCW));
    l_bcws.push_back(cw_info(FUNC_SPACE_5, HOST_VREF_CW, l_f5bc5x, BCW_SAFE_DELAY, mss::CW8_DATA_LEN,
                             cw_info::BCW));

    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode buffer_wr_vref::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rp,
                                       const uint8_t i_abort_on_error ) const
{
    std::vector<uint64_t> l_ranks;

    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in add_command<BUFFER_WR_VREF> %s",
              mss::c_str(i_target) );

    for(const auto l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            continue;
        }

        // we only want to run one rank per DIMM
        if((l_rank != 0) && (l_rank != 4))
        {
            continue;
        }

        const auto& l_dimm = l_dimms[mss::rank::get_dimm_from_rank(l_rank)];
        // Vector represents the number of LRDIMM buffers
        std::vector<recorder> l_results_recorder(MAX_LRDIMM_BUFFERS);

        //Write 0 to address 0 and read back, shmoo vref value, found 0->1 transition
        //Use middle point of 0->1 transition and 100% as the best vref value
        constexpr uint64_t WRITE_DATA = 0x0;
        constexpr uint64_t VREF_PARAMETER = 0x0;

        for(int8_t l_vref = MAX_VREF; l_vref >= 0; l_vref--)
        {
            // 1) Set the l_vref -> host issues BCW's
            FAPI_TRY(set_vref(l_dimm, l_vref));
            // 500ns delay for vref update
            fapi2::delay(500, 0);

            // 2) Write 0 to address 0 and read back
            FAPI_TRY(conduct_write_read(l_dimm, l_vref, l_rank, WRITE_DATA));

            // 3)  Analyze the results -> find 0->1 trainsition
            FAPI_TRY(analyze_result(i_target, l_vref, l_results_recorder));
        }

        // 4) workaround , must do even numbers of read
        FAPI_TRY(conduct_write_read(l_dimm, VREF_PARAMETER, l_rank, WRITE_DATA));

        // 5) restore original vref
        FAPI_TRY(restore_org_vref(l_dimm));
        // 500ns delay for vref update
        fapi2::delay(500, 0);

        // 6)  calculate middle point of the 0->1 transition and the 100%
        FAPI_TRY(calculate_best_vref(l_dimm, l_results_recorder));

        // 7) Write final values into the buffers -> host issues BCW's in PBA mode (values are calculated in step 4)
        FAPI_TRY(write_result_to_buffers( l_dimm, l_results_recorder));
        // 500ns delay for vref update
        fapi2::delay(500, 0);


    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write data to address 0 and read back
/// @param[in] i_target the DIMM target
/// @param[in] i_verf the vref number we current set
/// @param[in] i_rank the rank number
/// @param[in] i_write_data the data to write
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode buffer_wr_vref::conduct_write_read( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t& i_vref,
        const uint64_t& i_rank,
        const uint64_t& i_write_data) const
{
    using TT = ccsTraits<mss::mc_type::NIMBUS>;
    uint8_t tRCD = 15;
    uint8_t tWR = 15;           //set to highest min value initially.
    uint8_t PL = 0;
    uint8_t CWL = 0;
    uint8_t CL = 0;
    uint8_t AL = 0;

    uint64_t l_delay = 0;
    uint8_t WL = 0;
    uint8_t RL = 0;
    fapi2::buffer<uint64_t> modeq_reg;
    fapi2::buffer<uint64_t> ecccntl_reg;
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> > l_ports;
    // Gets WR/RD ODT values
    uint8_t l_rd_odt[MAX_RANK_PER_DIMM] = {};
    uint8_t l_wr_odt[MAX_RANK_PER_DIMM] = {};
    // Used for ODT values
    const auto l_dimm_rank = mss::index(i_rank);

    constexpr uint8_t ODT_CYCLE_LEN = 10;


    // Create Program
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Get timings from attributes:
    FAPI_TRY(mss::eff_odt_rd(i_target, &l_rd_odt[0]));
    FAPI_TRY(mss::eff_odt_wr(i_target, &l_wr_odt[0]));
    FAPI_TRY(mss::eff_dram_trcd(i_target, tRCD));
    FAPI_TRY(mss::eff_dram_twr(i_target, tWR));
    FAPI_TRY(mss::eff_ca_parity_latency(i_target, PL));
    FAPI_TRY(mss::eff_dram_cwl(i_target, CWL));
    FAPI_TRY(mss::eff_dram_cl(i_target, CL));
    FAPI_TRY(mss::eff_dram_al(i_target, AL));
    WL = PL + CWL + AL;
    RL = PL + CL + AL;

    FAPI_DBG("TIMING PARAMETERS:\nPL = %d; CWL = %d; AL = %d; WL = %d; tRCD = %d; tWR = %d; ",
             PL, CWL, AL, WL, tRCD, tWR);

    //write
    {

        // activate instruciton
        {
            auto l_activate = ccs::act_command(i_rank);

            l_delay = tRCD;
            l_activate.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);

            // Adds the instructions to the CCS program
            l_program.iv_instructions.push_back(l_activate);
        }

        // load wr command
        {
            auto l_wr = mss::ccs::wra_load(i_target, i_rank, 0, 0, 0);

            l_delay = 0;
            l_wr.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);

            //set write data for ccs write command
            l_wr.arr1.template insertFromRight<TT::ARR1_READ_OR_WRITE_DATA, TT::ARR1_READ_OR_WRITE_DATA_LEN>(i_write_data);

            // Adds the instructions to the CCS program
            l_program.iv_instructions.push_back(l_wr);
        }

        // add odt command
        {
            // ODT value buffer
            uint8_t l_ccs_value = 0;
            FAPI_TRY(mss::ccs::convert_odt_attr_to_ccs(l_wr_odt[l_dimm_rank], l_mca, l_ccs_value));

            // Inserts ODT values
            auto l_odt = mss::ccs::odt_load(l_ccs_value, WL + ODT_CYCLE_LEN);

            l_delay = tWR + tRCD;
            l_odt.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);

            //set write data for ccs write command
            l_odt.arr1.template insertFromRight<TT::ARR1_READ_OR_WRITE_DATA, TT::ARR1_READ_OR_WRITE_DATA_LEN>(i_write_data);

            // Adds the instructions to the CCS program
            l_program.iv_instructions.push_back(l_odt);
        }
    }

    //read
    {
        // activate instruciton
        {
            auto l_activate = ccs::act_command(i_rank);

            l_delay = tRCD;
            l_activate.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);

            // Adds the instructions to the CCS program
            l_program.iv_instructions.push_back(l_activate);
        }

        // load read command
        {
            auto l_rd = mss::ccs::rda_load(i_target, i_rank, 0, 0, 0);

            l_delay = 1;
            l_rd.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);

            // Adds the instructions to the CCS program
            l_program.iv_instructions.push_back(l_rd);
        }

        // add odt command
        {
            // ODT value buffer
            uint8_t l_ccs_value = 0;
            FAPI_TRY(mss::ccs::convert_odt_attr_to_ccs(l_rd_odt[l_dimm_rank], l_mca, l_ccs_value));

            // Inserts ODT values
            auto l_odt = mss::ccs::odt_load(l_ccs_value, RL + ODT_CYCLE_LEN);

            l_delay = tRCD;
            l_odt.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);

            // Adds the instructions to the CCS program
            l_program.iv_instructions.push_back(l_odt);
        }
    }
    //set ports for ccs execution
    l_ports.push_back(l_mca);

    //---------------------------------------
    // configure and execute ccs array
    //---------------------------------------
    {
        FAPI_TRY(mss::ccs::config_ccs_regs(l_mcbist, l_mca, modeq_reg, ecccntl_reg));
        FAPI_TRY(mss::ccs::execute(l_mcbist, l_program, l_ports));
        FAPI_TRY(mss::ccs::revert_config_regs(l_mcbist, l_mca, modeq_reg, ecccntl_reg));
    }

fapi_try_exit:
    return fapi2::current_err;
}
#endif

///
/// @brief Deconfigures calibration steps depending upon LRDIMM type
/// @param[in] i_dimm_type - DIMM type
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps - the bit mask of calibration steps
/// @return a vector of the calibration steps to run
///
void deconfigure_steps(const uint8_t i_dimm_type,
                       const bool i_sim,
                       fapi2::buffer<uint32_t>& io_cal_steps)
{
    // If the DIMM type is an LRDIMM, configure for LRDIMM
    if(i_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
    {
        FAPI_INF("LRDIMM: deconfigure WR VREF 2D and RD VREF 2D");
        // We clear WRITE_CTR_2D_VREF as the HW calibration algorithm will not work with LRDIMM
        io_cal_steps.clearBit<WRITE_CTR_2D_VREF>();
        return;
    }

    FAPI_INF("Not LRDIMM: deconfigure all LRDIMM specific steps");
    // Otherwise, clear all LRDIMM calibration steps
    io_cal_steps.clearBit<DB_ZQCAL>()
    .clearBit<MREP>()
    .clearBit<MRD_COARSE>()
    .clearBit<BUFFER_RD_VREF>()
    .clearBit<MRD_FINE>()
    .clearBit<DWL>()
    .clearBit<MWD_COARSE>()
    .clearBit<DRAM_WR_VREF>()
    .clearBit<MWD_FINE>()
    .clearBit<HWL>()
    .clearBit<BUFFER_WR_VREF>();
}

} // ns lrdimm

} // ns training

} // ns mss
