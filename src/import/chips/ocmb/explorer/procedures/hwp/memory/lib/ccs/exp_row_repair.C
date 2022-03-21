/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/exp_row_repair.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file exp_row_repair.C
/// @brief API for row repair HWP
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/mc/exp_port_traits.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/ccs/exp_row_repair.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <lib/dimm/exp_rank.H>
#include <lib/dimm/exp_kind.H>
#include <lib/ccs/exp_bad_dq_bitmap_funcs.H>

#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/bit_count.H>

namespace mss
{

namespace exp
{

namespace ccs
{

///
/// @brief Reads the inversion register and proceses out if the chip's data is inverted
/// @param[in] i_data register data to read
/// @param[out] o_state the state of the inversion on the chip
///
void get_inversion(const fapi2::buffer<uint64_t>& i_data, mss::states& o_state)
{
    // Note: we're going to assume that we're not in mode 0b01.
    // That mode will break row repair as beats 0-3 will be different than beats 4-7
    // As row repair is needed for production, I think this is a safe assumption
    constexpr uint64_t INVERSION_DISABLED = 0;
    uint64_t l_inversion = 0;
    i_data.extractToRight<EXPLR_RDF_RECR_MBSECCQ_DATA_INVERSION, EXPLR_RDF_RECR_MBSECCQ_DATA_INVERSION_LEN>(l_inversion);
    o_state = l_inversion == INVERSION_DISABLED ? mss::states::OFF : mss::states::ON;
}

///
/// @brief Reads the inversion register and proceses out if the chip's data is inverted
/// @param[in] i_target the target on which to operate
/// @param[out] o_state the state of the inversion on the chip
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode process_inversion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, mss::states& o_state)
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_RDF_RECR, l_data));

    get_inversion(l_data, o_state);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the WR data in INST_ARR1 for a ccs write command
/// @param[in] i_data CCS write data
/// @param[in] i_inverse ON if the data needs to be inverted
/// @param[in,out] io_inst The vector of ccs instructions to add to
///
void set_write_data( const fapi2::buffer<uint64_t>& i_data,
                     const mss::states i_inversion,
                     mss::ccs::instruction_t<mss::mc_type::EXPLORER>& io_inst)
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;

    fapi2::buffer<uint64_t> l_data(i_data);

    // Check for data inversion
    if (i_inversion == mss::states::ON)
    {
        l_data.invert();
    }

    // Set the data
    io_inst.arr1.template
    insertFromRight<TT::ARR1_READ_OR_WRITE_DATA, TT::ARR1_READ_OR_WRITE_DATA_LEN>(l_data);
}

} // namespace ccs


namespace row_repair
{

///
/// @brief Creates the DRAM bitmap for row repair on all DRAMS
/// @return the DRAM bitmap for repairs on all DRAMs
///
fapi2::buffer<uint64_t> select_all_drams_for_repair()
{
    fapi2::buffer<uint64_t> l_dram_bitmap;
    l_dram_bitmap.setBit<DRAM_START_BIT, DRAM_LEN>();
    l_dram_bitmap.invert();
    return l_dram_bitmap;
}

///
/// @brief Creates the DRAM bitmap for row repair
/// @param[in] i_dram the DRAM on which to conduct row repairs
/// @param[out] o_dram_bitmap the DRAM bitmap on which to conduct row repairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode create_dram_bitmap(const uint64_t i_dram, fapi2::buffer<uint64_t>& o_dram_bitmap)
{
    o_dram_bitmap.flush<0>();
    FAPI_TRY(o_dram_bitmap.setBit(DRAM_START_BIT + i_dram));
    o_dram_bitmap.invert();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear a row repair entry from rank
/// @param[in] i_rank_info master rank
/// @param[in,out] io_row_repair_data data for this DIMM/rank
///
void clear_row_repair_entry( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                             uint8_t (&io_row_repair_data)[MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK])
{
    // Clear the entire entry for this DIMM/rank and write it back, to be consistent with PRD
    std::fill(std::begin(io_row_repair_data[i_rank_info.get_dimm_rank()]),
              std::end(io_row_repair_data[i_rank_info.get_dimm_rank()]), 0);
}

///
/// @brief Create CCS instruction with proper bits for guard key
/// @param[in] i_rank_info rank of address for instruction
/// @param[in] i_delay_in_cycles delay in cycles for instruction
/// @param[in] i_guard_key_addr guardkey sequence addr value
/// @param[in,out] io_inst ccs instruction to create guardkey for
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode add_sppr_guardkey( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                     const uint64_t i_delay_in_cycles,
                                     const uint64_t i_guard_key_addr,
                                     std::vector< mss::ccs::instruction_t<mss::mc_type::EXPLORER> >& io_inst )
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;

    constexpr uint64_t GUARDKEY_ADDR_LEN = 12;
    constexpr uint64_t ARR0_DDR_BANK_CLEAR = 0;
    constexpr uint64_t MRS00 = 0;
    bool l_is_a17 = false;
    bool l_has_rcd = false;

    // Parse out rank info
    const auto& l_port_rank = i_rank_info.get_port_rank();
    const auto& l_dimm = i_rank_info.get_dimm_target();

    // Create instructions
    mss::ccs::instruction_t<mss::mc_type::EXPLORER> l_inst_a_side;
    mss::ccs::instruction_t<mss::mc_type::EXPLORER> l_inst_b_side;

    // Initialize Instructions
    l_inst_a_side = mss::ccs::mrs_command<mss::mc_type::EXPLORER>(l_port_rank, MRS00);

    FAPI_TRY(mss::dimm::has_rcd<mss::mc_type::EXPLORER>(l_dimm, l_has_rcd),
             "Failed to check has_rcd on %s",
             mss::c_str(l_dimm) );

    // Manipulate data based on step of guard key sequence
    // Clearing bits per DDR4 SPPR spec despite MRS setup
    l_inst_a_side.arr0.template insertFromRight<TT::ARR0_DDR_ADDRESS_0_13,
                                GUARDKEY_ADDR_LEN>(i_guard_key_addr);
    l_inst_a_side.arr0.template clearBit<TT::ARR0_DDR_BANK_GROUP_1>();
    l_inst_a_side.arr0.template insertFromRight<TT::ARR0_DDR_BANK_0_1,
                                TT::ARR0_DDR_BANK_0_1_LEN>(ARR0_DDR_BANK_CLEAR);
    l_inst_a_side.arr0.template clearBit<TT::ARR0_DDR_BANK_GROUP_0>();

    // Perform Address Mirroring if necessary
    FAPI_TRY( mss::address_mirror<mss::mc_type::EXPLORER>(l_dimm, l_port_rank, l_inst_a_side),
              "Failed mirroring rank %d on %s",
              l_port_rank, mss::c_str(l_dimm) );

    // Far as I can tell with explorer, the address and inversion should be handled for us
    // So we need to see if the A17 bit is enabled. If it is we need to invert it for the CCS parity
    FAPI_TRY( is_a17_needed<mss::mc_type::EXPLORER>( l_dimm, l_is_a17),
              "Failed to detect A17 bit requirements on %s",
              mss::c_str(l_dimm) );
    l_inst_b_side = mss::address_invert(l_dimm, l_inst_a_side, l_is_a17);

    // Insert the delay into arr1 (control reg)
    // setting to 10 in order to space each side command by 20 which give plenty of time for tMOD
    l_inst_a_side.arr1.template insertFromRight<EXPLR_MCBIST_CCS_INST_ARR1_00_IDLES,
                                EXPLR_MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(i_delay_in_cycles);
    l_inst_b_side.arr1.template insertFromRight<EXPLR_MCBIST_CCS_INST_ARR1_00_IDLES,
                                EXPLR_MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(i_delay_in_cycles);

    // Trace printout
    FAPI_INF("Instruction Value: 0x%016llx:0x%016llx rank %d a-side on dimm %s",
             l_inst_a_side.arr0, l_inst_a_side.arr1, l_port_rank, mss::c_str(l_dimm));

    // Add a_side to the CCS program
    io_inst.push_back(l_inst_a_side);

    // If the dimm has RCD push b_side
    if (l_has_rcd)
    {
        // Trace printout
        FAPI_INF("Instruction Value: 0x%016llx:0x%016llx rank %d b-side on dimm %s",
                 l_inst_b_side.arr0, l_inst_b_side.arr1, l_port_rank, mss::c_str(l_dimm));

        // Add a_side to the CCS program
        io_inst.push_back(l_inst_b_side);
    }

    FAPI_INF("Guardkey created for %s", mss::c_str(l_dimm));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Build a table of PPR row repairs from attribute data for a given DIMM
/// @param[in] i_target DIMM target
/// @param[in] i_row_repair_data array of row repair attribute values for the DIMM
/// @param[out] o_repairs_per_dimm array of row repair data buffers
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode build_row_repair_table(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_row_repair_data[mss::exp::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK],
        std::vector<mss::row_repair::repair_entry<mss::mc_type::EXPLORER>>& o_repairs_per_dimm)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    constexpr uint8_t MAX_BANK_GROUP = 4;
    constexpr uint8_t MAX_BANKS = 8;

    uint8_t l_num_dram = 0;
    uint8_t l_num_subrank = 0;

    // Determine repair data bounds
    mss::dimm::kind<mss::mc_type::EXPLORER> l_kind(i_target, l_rc);
    FAPI_TRY(l_rc, "%s Failed to create dimm::kind instance", mss::c_str(i_target));
    // TODO: Move to helper function Zen#646
    l_num_dram = l_kind.iv_dram_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4 ?
                 mss::exp::generic_consts::EXP_NUM_DRAM_X4 : mss::exp::generic_consts::EXP_NUM_DRAM_X8;

    if (l_kind.iv_master_ranks != 0)
    {
        l_num_subrank = l_kind.iv_total_ranks / l_kind.iv_master_ranks;
    }

    o_repairs_per_dimm.clear();

    for (uint8_t l_dimm_rank = 0; l_dimm_rank < l_kind.iv_master_ranks; ++l_dimm_rank)
    {
        fapi2::buffer<uint32_t> l_row_repair_data;

        // Convert each entry from an array of bytes into a fapi2::buffer
        for (uint8_t l_byte = 0; l_byte < ROW_REPAIR_BYTES_PER_RANK; ++l_byte)
        {
            FAPI_TRY(l_row_repair_data.insertFromRight(i_row_repair_data[l_dimm_rank][l_byte],
                     l_byte * BITS_PER_BYTE,
                     BITS_PER_BYTE));
        }

        FAPI_INF("%s row repair entry for rank%u 0x%08x", mss::c_str(i_target), l_dimm_rank, l_row_repair_data);

        // Create repair entry
        mss::row_repair::repair_entry<mss::mc_type::EXPLORER> l_entry(l_row_repair_data, l_dimm_rank);

        if (l_entry.is_valid())
        {
            const uint64_t MAX_ROW = 1 << l_kind.iv_rows;
            const uint64_t MAX_SRANK = 1 << l_num_subrank;
            FAPI_INF("Found valid row repair request in VPD for DIMM %s, DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                     mss::spd::c_str(i_target), l_entry.iv_dram, l_entry.iv_dimm_rank, l_entry.iv_srank, l_entry.iv_bg, l_entry.iv_bank,
                     l_entry.iv_row);

            FAPI_INF("Maxes for dimm %s: DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                     mss::spd::c_str(i_target), l_num_dram, l_kind.iv_master_ranks, l_num_subrank, MAX_BANK_GROUP, MAX_BANKS,
                     l_kind.iv_rows);

            // Do some sanity checking here
            FAPI_ASSERT((l_entry.iv_dram < l_num_dram) &&
                        (l_entry.iv_srank < MAX_SRANK) &&
                        (l_entry.iv_bg < MAX_BANK_GROUP) &&
                        (l_entry.iv_bank < MAX_BANKS) &&
                        (l_entry.iv_row < MAX_ROW),
                        fapi2::EXP_ROW_REPAIR_ENTRY_OUT_OF_BOUNDS().
                        set_DIMM_TARGET(i_target).
                        set_DRAM(l_entry.iv_dram).
                        set_DRAM_MAX(l_num_dram).
                        set_MRANK(l_dimm_rank).
                        set_SRANK(l_entry.iv_srank).
                        set_SRANK_MAX(MAX_SRANK).
                        set_BANK_GROUP(l_entry.iv_bg).
                        set_BANK_GROUP_MAX(MAX_BANK_GROUP).
                        set_BANK(l_entry.iv_bank).
                        set_BANK_MAX(MAX_BANKS).
                        set_ROW(l_entry.iv_row).
                        set_ROW_MAX(MAX_ROW),
                        "%s SPD contained out of bounds row repair entry: DRAM: %d MAX: %d mrank %d srank %d MAX: %d"
                        "bg %d MAX: %d bank %d MAX: %d row 0x%05x MAX: 0x%05x",
                        mss::spd::c_str(i_target), l_entry.iv_dram, l_num_dram, l_dimm_rank, l_entry.iv_srank, MAX_SRANK,
                        l_entry.iv_bg, MAX_BANK_GROUP, l_entry.iv_bank, MAX_BANKS, l_entry.iv_row, MAX_ROW);
            // Insert row repair request into list
            o_repairs_per_dimm.push_back(l_entry);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create an error log and return with a good error code if a valid row repair is found
/// @param[in] i_target the DIMM target
/// @param[in] i_repair the repair data to validate
/// @return successful error code
///
fapi2::ReturnCode log_repairs_disabled_errors(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair)
{
    FAPI_ASSERT((!i_repair.is_valid()),
                fapi2::EXP_ROW_REPAIR_WITH_MNFG_REPAIRS_DISABLED().
                set_DIMM_TARGET(i_target).
                set_DRAM(i_repair.iv_dram).
                set_MRANK(i_repair.iv_dimm_rank).
                set_SRANK(i_repair.iv_srank).
                set_BANK_GROUP(i_repair.iv_bg).
                set_BANK(i_repair.iv_bank).
                set_ROW(i_repair.iv_row),
                "%s Row repair valid but DRAM repairs are disabled for DRAM %d, mrank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                mss::spd::c_str(i_target), i_repair.iv_dram, i_repair.iv_dimm_rank, i_repair.iv_srank, i_repair.iv_bg, i_repair.iv_bank,
                i_repair.iv_row);
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // We've found a valid row repair - log it as predictive, so we get callouts in MFG test but don't fail out
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_PREDICTIVE);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform a sPPR row repair operation
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_sppr( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                              const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                              const fapi2::buffer<uint64_t>& i_dram_bitmap,
                              mss::ccs::program<mss::mc_type::EXPLORER>& io_program)
{
    using TT = mrsTraits<mss::mc_type::EXPLORER>;
    constexpr size_t ENABLE_SPPR = 1;
    constexpr size_t NO_DELAY = 0;
    // Delay for PRE command
    constexpr uint64_t PRE_DELAY = 0;
    // Repeat value for ODT command
    constexpr uint64_t ODT_REPEAT = 4;

    // Variable Declarations
    uint64_t l_freq = 0;
    uint8_t l_odt_bits = 0;
    mss::states l_invert = mss::states::OFF;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_odt_attr[4] = {0};

    // Use rank to determine ranks and targets
    // Get port rank and target
    const auto l_port_target = i_rank_info.get_port_target();
    const auto l_port_rank = i_rank_info.get_port_rank();

    // Get dimm rank and target
    const auto l_dimm_target = i_rank_info.get_dimm_target();
    const auto l_dimm_rank = i_rank_info.get_dimm_rank();

    // Get the OCMB target
    const auto l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Declare timings
    const uint64_t tMOD = TT::mrs_tmod( l_port_target );
    uint8_t tRCD = 0;
    uint8_t tWR = 255;

    // Create local instruction
    mss::ccs::instruction_t<mss::mc_type::EXPLORER> l_inst;

    // Initialize MRS data:
    mss::ddr4::mrs04_data<mss::mc_type::EXPLORER> l_data4(l_dimm_target, l_rc);
    FAPI_TRY(l_rc, "Failed initializing MRS04 Data on %s", mss::c_str(l_dimm_target));

    // Get timing from API and attributes
    FAPI_TRY( mss::attr::get_dram_trcd(l_port_target, tRCD) );

    // Get freq from attributes:
    FAPI_TRY( mss::freq<mss::mc_type::EXPLORER>(l_ocmb_target, l_freq),
              "Failed to retrieve freq values on %s",
              mss::c_str(l_ocmb_target) );

    // Get ODT bits for ccs
    FAPI_TRY( mss::attr::get_si_odt_wr(l_dimm_target, l_odt_attr) );
    FAPI_TRY( mss::ccs::convert_odt_attr_to_ccs<mss::mc_type::EXPLORER>(l_odt_attr[l_dimm_rank], l_port_target, l_odt_bits),
              "Failed odt to ccs conversion on port rank %d on port %s",
              l_port_rank, mss::c_str(l_port_target));

    //-------------------------------
    // SPPR COMMAND:
    //-------------------------------

    // 0. Add des command for Self Time Refresh
    l_inst = mss::ccs::des_command<mss::mc_type::EXPLORER>();
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tMOD, l_inst, io_program.iv_instructions) );

    // 1. Precharge_all(): Create instruction for precharge and add it to the instruction array.
    l_inst = mss::ccs::init_pre_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_srank);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tRCD, l_inst, io_program.iv_instructions) );

    FAPI_MFG( "Running srank fix on dimm %s with srank %d", mss::c_str(l_dimm_target), i_repair.iv_srank );

    // 2. Enable sPPR and wait tMOD:
    l_data4.iv_soft_ppr = ENABLE_SPPR;
    FAPI_TRY(mss::mrs_engine( l_dimm_target, l_data4, l_port_rank, tMOD, io_program.iv_instructions),
             "Failed to setup mrs engine on dimm rank %d on dimm %s",
             l_dimm_rank, mss::c_str(l_dimm_target) );

    // 3. Guard Key Sequence:
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_ONE,
                                io_program.iv_instructions),
              "Failed to setup guard key seq one for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_TWO,
                                io_program.iv_instructions),
              "Failed to setup guard key seq two for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_THREE,
                                io_program.iv_instructions),
              "Failed to setup guard key seq three for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_FOUR,
                                io_program.iv_instructions),
              "Failed to setup guard key seq four for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );

    // 4. ACT to failed bank/address
    l_inst = mss::ccs::act_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_bank, i_repair.iv_bg,
             i_repair.iv_row, i_repair.iv_srank, tRCD);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tRCD, l_inst, io_program.iv_instructions) );

    // 5. WR Command with dq bits low:
    l_inst = mss::ccs::wr_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_bank, i_repair.iv_bg, i_repair.iv_srank,
             NO_DELAY);
    // Check for data inversion and invert data if on
    FAPI_TRY( mss::exp::ccs::process_inversion(l_port_target, l_invert) );
    mss::exp::ccs::set_write_data(i_dram_bitmap, l_invert, l_inst);
    // Set ODT Bits on WR command
    mss::ccs::set_odt_bits<mss::mc_type::EXPLORER>(l_odt_bits, l_inst);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, NO_DELAY, l_inst, io_program.iv_instructions) );

    // 6. Add odt command
    l_inst = mss::ccs::odt_command<mss::mc_type::EXPLORER>(l_odt_bits);
    mss::ccs::set_wr_repeats<mss::mc_type::EXPLORER>(ODT_REPEAT, l_inst);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tWR, l_inst, io_program.iv_instructions) );

    // 7. PRE to Bank (and wait at least 20ns to register)
    // Currently waiting tWR for debug
    l_inst = mss::ccs::pre_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_bank, i_repair.iv_bg, i_repair.iv_srank,
             PRE_DELAY);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tWR, l_inst, io_program.iv_instructions) );

    // 8. Set MR4 bit "A5=0" to exit sPPR
    l_data4.iv_soft_ppr = 0;
    FAPI_TRY( mss::mrs_engine(l_dimm_target, l_data4, l_port_rank, tMOD, io_program.iv_instructions),
              "Failed to setup mrs engine on rank %d on %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );

    // Add des command
    l_inst = mss::ccs::des_command<mss::mc_type::EXPLORER>();
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tMOD, l_inst, io_program.iv_instructions) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a hPPR row repair operation, part 1
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
/// @note hPPR has to be done in two steps because it requires a 1-second delay to execute the repair
///
fapi2::ReturnCode setup_hppr_pre_delay( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                        const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                                        const fapi2::buffer<uint64_t>& i_dram_bitmap,
                                        mss::ccs::program<mss::mc_type::EXPLORER>& io_program)
{
    using TT = mrsTraits<mss::mc_type::EXPLORER>;
    constexpr size_t ENABLE_HPPR = 1;
    constexpr size_t NO_DELAY = 0;
    // Repeat value for ODT command
    constexpr uint64_t ODT_REPEAT = 4;

    // Variable Declarations
    uint8_t l_odt_bits = 0;
    mss::states l_invert = mss::states::OFF;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_odt_attr[4] = {0};

    // Use rank to determine ranks and targets
    // Get port rank and target
    const auto l_port_target = i_rank_info.get_port_target();
    const auto l_port_rank = i_rank_info.get_port_rank();

    // Get dimm rank and target
    const auto l_dimm_target = i_rank_info.get_dimm_target();
    const auto l_dimm_rank = i_rank_info.get_dimm_rank();

    // Declare timings
    const uint64_t tMOD = TT::mrs_tmod( l_port_target );
    uint8_t tRCD = 0;
    uint8_t tWR = 255;

    // Create local instruction
    mss::ccs::instruction_t<mss::mc_type::EXPLORER> l_inst;

    // Initialize MRS data:
    mss::ddr4::mrs04_data<mss::mc_type::EXPLORER> l_data4(l_dimm_target, l_rc);
    FAPI_TRY(l_rc, "Failed initializing MRS04 Data on %s", mss::c_str(l_dimm_target));

    // Get timing from API and attributes
    FAPI_TRY( mss::attr::get_dram_trcd(l_port_target, tRCD) );

    // Get ODT bits for ccs
    FAPI_TRY( mss::attr::get_si_odt_wr(l_dimm_target, l_odt_attr) );
    FAPI_TRY( mss::ccs::convert_odt_attr_to_ccs<mss::mc_type::EXPLORER>(l_odt_attr[l_dimm_rank], l_port_target, l_odt_bits),
              "Failed odt to ccs conversion on port rank %d on port %s",
              l_port_rank, mss::c_str(l_port_target));

    //-------------------------------
    // hPPR COMMAND:
    //-------------------------------

    // 0. Add des command for Self Time Refresh
    l_inst = mss::ccs::des_command<mss::mc_type::EXPLORER>();
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tMOD, l_inst, io_program.iv_instructions) );

    // 1. Precharge_all(): Create instruction for precharge and add it to the instruction array.
    l_inst = mss::ccs::init_pre_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_srank);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tRCD, l_inst, io_program.iv_instructions) );

    FAPI_MFG( "Running srank fix on dimm %s with srank %d", mss::c_str(l_dimm_target), i_repair.iv_srank );

    // 2. Enable hPPR and wait tMOD:
    l_data4.iv_ppr = ENABLE_HPPR;
    FAPI_TRY(mss::mrs_engine( l_dimm_target, l_data4, l_port_rank, tMOD, io_program.iv_instructions),
             "Failed to setup mrs engine on dimm rank %d on dimm %s",
             l_dimm_rank, mss::c_str(l_dimm_target) );

    // 3. Guard Key Sequence:
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_ONE,
                                io_program.iv_instructions),
              "Failed to setup guard key seq one for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_TWO,
                                io_program.iv_instructions),
              "Failed to setup guard key seq two for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_THREE,
                                io_program.iv_instructions),
              "Failed to setup guard key seq three for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );
    FAPI_TRY( add_sppr_guardkey(i_rank_info, tMOD, GUARDKEY_SEQ_FOUR,
                                io_program.iv_instructions),
              "Failed to setup guard key seq four for dimm rank %d on dimm %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );

    // 4. ACT to failed bank/address
    l_inst = mss::ccs::act_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_bank, i_repair.iv_bg,
             i_repair.iv_row, i_repair.iv_srank, tRCD);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tRCD, l_inst, io_program.iv_instructions) );

    // 5. WR Command with dq bits low:
    l_inst = mss::ccs::wr_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_bank, i_repair.iv_bg, i_repair.iv_srank,
             NO_DELAY);
    // Check for data inversion and invert data if on
    FAPI_TRY( mss::exp::ccs::process_inversion(l_port_target, l_invert) );
    mss::exp::ccs::set_write_data(i_dram_bitmap, l_invert, l_inst);
    // Set ODT Bits on WR command
    mss::ccs::set_odt_bits<mss::mc_type::EXPLORER>(l_odt_bits, l_inst);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, NO_DELAY, l_inst, io_program.iv_instructions) );

    // 6. Add odt command
    l_inst = mss::ccs::odt_command<mss::mc_type::EXPLORER>(l_odt_bits);
    mss::ccs::set_wr_repeats<mss::mc_type::EXPLORER>(ODT_REPEAT, l_inst);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tWR, l_inst, io_program.iv_instructions) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a hPPR row repair operation, part 2
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
/// @note hPPR has to be done in two steps because it requires a 1-second delay to execute the repair
///
fapi2::ReturnCode setup_hppr_post_delay( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
        const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
        const fapi2::buffer<uint64_t>& i_dram_bitmap,
        mss::ccs::program<mss::mc_type::EXPLORER>& io_program)
{
    using TT = mrsTraits<mss::mc_type::EXPLORER>;

    // delay for PRE command
    constexpr uint64_t PRE_DELAY = 0;
    // delay at the end of the program (used twice to get 128K idles)
    constexpr uint64_t FINAL_DELAY = 0xFFFF;

    // Variable Declarations
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Use rank to determine ranks and targets
    // Get port rank and target
    const auto l_port_target = i_rank_info.get_port_target();
    const auto l_port_rank = i_rank_info.get_port_rank();

    // Get dimm rank and target
    const auto l_dimm_target = i_rank_info.get_dimm_target();
    const auto l_dimm_rank = i_rank_info.get_dimm_rank();

    // Declare timings
    const uint64_t tMOD = TT::mrs_tmod( l_port_target );
    uint8_t tWR = 255;

    // Create local instruction
    mss::ccs::instruction_t<mss::mc_type::EXPLORER> l_inst;

    // Initialize MRS data:
    mss::ddr4::mrs04_data<mss::mc_type::EXPLORER> l_data4(l_dimm_target, l_rc);
    FAPI_TRY(l_rc, "Failed initializing MRS04 Data on %s", mss::c_str(l_dimm_target));

    //-------------------------------
    // hPPR COMMAND:
    //-------------------------------

    // 7. PRE to Bank (and wait at least 20ns to register)
    // Currently waiting tWR for debug
    l_inst = mss::ccs::pre_load<mss::mc_type::EXPLORER>(i_rank_info, i_repair.iv_bank, i_repair.iv_bg, i_repair.iv_srank,
             PRE_DELAY);
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tWR, l_inst, io_program.iv_instructions) );

    // 8. Set MR4 bit "A13=0" to exit sPPR
    l_data4.iv_ppr = 0;
    FAPI_TRY( mss::mrs_engine(l_dimm_target, l_data4, l_port_rank, tMOD, io_program.iv_instructions),
              "Failed to setup mrs engine on rank %d on %s",
              l_dimm_rank, mss::c_str(l_dimm_target) );

    // Add 2 64k cycle idles to prevent the controller from sending any other commands before hPPR is done
    l_inst = mss::ccs::des_command<mss::mc_type::EXPLORER>();
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, FINAL_DELAY, l_inst,
              io_program.iv_instructions) );
    l_inst = mss::ccs::des_command<mss::mc_type::EXPLORER>();
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, FINAL_DELAY, l_inst,
              io_program.iv_instructions) );

    // Add des command
    l_inst = mss::ccs::des_command<mss::mc_type::EXPLORER>();
    FAPI_TRY( mss::ccs::process_inst<mss::mc_type::EXPLORER>(i_rank_info, tMOD, l_inst, io_program.iv_instructions) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a sPPR row repair operation during ipl
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode maint_row_repair( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                    const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                                    const fapi2::buffer<uint64_t>& i_dram_bitmap)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_modeq_reg;

    // Get port rank and target
    const auto l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::EXPLORER> l_program;

    // Setup SPPR CCS program
    FAPI_TRY( setup_sppr(i_rank_info, i_repair, i_dram_bitmap, l_program),
              "Failed sppr program setup for maint_row_repair on %s",
              mss::c_str(l_port_target) );

    FAPI_INF("%s Deploying maint row repair during ipl", mss::c_str(l_ocmb_target));

    // EXECUTE CCS ARRAY
    FAPI_TRY( mss::row_repair::config_ccs_regs<mss::mc_type::EXPLORER>(l_ocmb_target, l_port_target, l_modeq_reg) );
    FAPI_TRY( mss::ccs::execute<mss::mc_type::EXPLORER>(l_ocmb_target, l_program, l_port_target) );
    FAPI_TRY( mss::row_repair::revert_config_regs<mss::mc_type::EXPLORER>(l_ocmb_target, l_port_target, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a hPPR row repair operation during ipl
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode hppr_row_repair( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                   const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                                   const fapi2::buffer<uint64_t>& i_dram_bitmap)
{
    fapi2::buffer<uint64_t> l_modeq_reg;

    // Get port rank and target
    const auto l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::EXPLORER> l_program;

    // Turn off refresh
    FAPI_TRY(mss::change_refresh_enable<mss::mc_type::EXPLORER>(l_port_target, mss::states::LOW));

    // Setup HPPR CCS program, part 1
    FAPI_TRY( setup_hppr_pre_delay(i_rank_info, i_repair, i_dram_bitmap, l_program),
              "Failed hppr program setup, part 1 for hppr_row_repair on %s",
              mss::c_str(l_port_target) );

    FAPI_INF("%s Deploying hPPR row repair", mss::c_str(l_ocmb_target));

    // EXECUTE CCS ARRAY
    FAPI_TRY( mss::row_repair::config_ccs_regs<mss::mc_type::EXPLORER>(l_ocmb_target, l_port_target, l_modeq_reg) );
    FAPI_TRY( mss::ccs::execute<mss::mc_type::EXPLORER>(l_ocmb_target, l_program, l_port_target) );

    // Delay for tPGM (1 second for x4 and x8 DIMMs - setting to 2 seconds for further safety)
    FAPI_TRY(fapi2::delay(2 * mss::DELAY_1S, 200));

    // Setup HPPR CCS program, part 2
    l_program.iv_instructions.clear();
    FAPI_TRY( setup_hppr_post_delay(i_rank_info, i_repair, i_dram_bitmap, l_program),
              "Failed hppr program setup, part 1 for hppr_row_repair on %s",
              mss::c_str(l_port_target) );

    FAPI_INF("%s Deploying hPPR row repair, part 2 (post tPGM delay)", mss::c_str(l_ocmb_target));

    // EXECUTE CCS ARRAY
    FAPI_TRY( mss::ccs::execute<mss::mc_type::EXPLORER>(l_ocmb_target, l_program, l_port_target) );
    FAPI_TRY( mss::row_repair::revert_config_regs<mss::mc_type::EXPLORER>(l_ocmb_target, l_port_target, l_modeq_reg) );

    // Turn refresh back on
    FAPI_TRY(mss::change_refresh_enable<mss::mc_type::EXPLORER>(l_port_target, mss::states::HIGH));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper that adds power down disable for dynamic row repair
/// @param[in] i_target port target on which to operate
/// @param[in, out] io_program program holding CCS instructions to add to
///
void disable_power_down_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               mss::ccs::program<mss::mc_type::EXPLORER>& io_program)
{
    // The power down mode is set when CCS execution starts at runtime
    // We need to exit power down mode by holding the CKE high
    // The time for this is 5 clocks or tRFC + 10ns at max
    // This is 560ns -> 746 clocks. rounded up to 750 for saftey
    constexpr uint16_t POWER_DOWN_EXIT_DELAY = 750;

    io_program.iv_instructions.clear();

    io_program.iv_instructions.push_back(mss::ccs::des_command<mss::mc_type::EXPLORER>(POWER_DOWN_EXIT_DELAY));
}

///
/// @brief Perform a sPPR row repair operation at runtime
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dynamic_row_repair( const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                                      const mss::row_repair::repair_entry<mss::mc_type::EXPLORER>& i_repair,
                                      const fapi2::buffer<uint64_t>& i_dram_bitmap)
{
    using CCS = ccsTraits<mss::mc_type::EXPLORER>;
    using MCB = mss::mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_mcbist_status;
    fapi2::buffer<uint64_t> l_ccs_status;
    bool l_poll_result = false;

    // Get port rank and target
    const auto l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::EXPLORER> l_program;

    // Add des command for power down exit
    disable_power_down_helper(l_port_target, l_program);

    // Setup SPPR CCS program
    FAPI_TRY( setup_sppr(i_rank_info, i_repair, i_dram_bitmap, l_program),
              "Failed sppr program setup for dynamic_row_repair on %s",
              mss::c_str(l_port_target)  );

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( mss::ccs::start_stop<mss::mc_type::EXPLORER>(l_ocmb_target, mss::states::STOP),
              "Error stopping CCS engine before ccs::execution on %s",
              mss::c_str(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for CCS, meaning no other CCS is running
    l_poll_result = mss::poll(l_ocmb_target, CCS::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) 0x%llx, remaining: %d", stat_reg, poll_remaining);
        // We're done polling when we see ccs is not in progress.
        return stat_reg.getBit<CCS::CCS_IN_PROGRESS>() != 1;
    });

    // Check that ccs is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::EXP_ROW_REPAIR_CCS_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                "%s CCS engine is in use and is not available for repair",
                mss::c_str(l_ocmb_target));

    // Stop any ongoing MCBIST command
    FAPI_TRY( mss::memdiags::stop<mss::mc_type::EXPLORER>(l_ocmb_target),
              "MCBIST engine failed to stop current command in progress on %s",
              mss::c_str(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for MCBIST, meaning the MCBIST is free
    l_poll_result = mss::poll(l_ocmb_target, MCB::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("mcbist statq (stop) 0x%llx, remaining: %d", stat_reg, poll_remaining);
        // We're done polling when we see mcbist is not in progress.
        return stat_reg.getBit<MCB::MCBIST_IN_PROGRESS>() != 1;
    });

    // Check that mcbist is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::EXP_ROW_REPAIR_MCBIST_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                "%s MCBIST failed to exit previous command and is not available for repair",
                mss::c_str(l_ocmb_target));

    FAPI_INF("%s Deploying dynamic row repair", mss::c_str(l_ocmb_target));

    // Configure CCS regs for execution
    FAPI_TRY( mss::row_repair::config_ccs_regs<mss::mc_type::EXPLORER>(l_ocmb_target, l_port_target, l_modeq_reg ) );

    // Run CCS via MCBIST for Concurrent CCS
    FAPI_TRY( mss::ccs::execute_via_mcbist<mss::mc_type::EXPLORER>(l_ocmb_target, l_program, l_port_target) );

    // Revert CCS regs after execution
    // NOTE: May require MCBIST restoration for exp_background_scrub
    FAPI_TRY( mss::row_repair::revert_config_regs<mss::mc_type::EXPLORER>(l_ocmb_target, l_port_target, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deploy enough PPR row repairs to test all spare rows
/// @param[in] i_target_ocmb ocmb target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode activate_all_spare_rows(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb)
{
    FAPI_INF("%s Deploying row repairs to test all spare rows", mss::c_str(i_target_ocmb));

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_ocmb))
    {
        constexpr bool REPAIR_VALID = 1;
        constexpr uint8_t DRAM_POS = 0;
        constexpr uint8_t BANK_POS = 0;

        uint8_t l_num_ranks = 0;
        uint8_t l_num_mranks = 0;
        uint8_t l_num_sranks = 0;

        // Set all DRAM select bits so we get repairs on all DRAMs
        const auto l_dram_bitmap = select_all_drams_for_repair();

        // Gets the rank info for this DIMM
        std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_infos;
        FAPI_TRY(ranks_on_dimm(l_dimm, l_rank_infos),
                 "Failed to retrieve ranks on dimm on %s",
                 mss::c_str(l_dimm) );

        // Get dimm information
        FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(l_dimm, l_num_ranks) );
        FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(l_dimm, l_num_mranks) );

        // The number of sub ranks
        // Get dimm information ranks per DIMM is simply the number of total ranks divided by the number of master ranks
        if (l_num_mranks > 0)
        {
            // TODO: Add to helper function Zen#646
            l_num_sranks = l_num_ranks / l_num_mranks;
        }

        // Loops thru RANKs
        for (const auto& l_rank_info : l_rank_infos)
        {
            const auto l_dimm_rank = l_rank_info.get_dimm_rank();

            for (uint8_t l_srank = 0; l_srank < l_num_sranks; ++l_srank)
            {
                // Note: setting row = rank so we don't use row0 for every repair
                uint32_t l_row = l_dimm_rank;

                // Note: DIMM can only support one repair per BG, so we loop on BG and use BA=0
                for (uint8_t l_bg = 0; l_bg < mss::exp::MAX_BG_PER_DIMM; ++l_bg)
                {
                    mss::row_repair::repair_entry<mss::mc_type::EXPLORER> l_repair(REPAIR_VALID, l_dimm_rank, DRAM_POS, l_srank, l_bg,
                            BANK_POS,
                            l_row);

                    FAPI_INF("%s Deploying row repairs on rank %d, DRAM %d, subrank %d, bg %d, bank %d, row 0x%05x",
                             mss::spd::c_str(l_dimm), l_dimm_rank, DRAM_POS, l_srank, l_bg, BANK_POS, l_row);

                    FAPI_TRY( maint_row_repair(l_rank_info, l_repair, l_dram_bitmap),
                              "Failed maint_row_repair on %s rank %d",
                              mss::c_str(l_dimm), l_dimm_rank );
                }
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the number of bad bits on a DRAM for a given row repair
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_row_repair_dram_byte the byte of data that contains the row repair's DRAM information
/// @param[in] i_bad_bits the array of bad bits for this rank
/// @param[out] o_num_bad_bits_for_dram the number of bad bits on this DRAM
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_num_bad_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_row_repair_dram_byte,
                                   const uint8_t i_bad_bits[BAD_DQ_BYTE_COUNT],
                                   uint8_t& o_num_bad_bits_for_dram)
{
    constexpr size_t MASK_NIBBLE0 = 0xF0;
    constexpr size_t MASK_NIBBLE1 = 0x0F;

    o_num_bad_bits_for_dram = 0;

    uint8_t l_dram = 0;
    const fapi2::buffer<uint8_t> l_buffer(i_row_repair_dram_byte);

    // Note: we're using the 0-31 values here;
    // however, the ones we want are on the first byte, so we should be ok
    l_buffer.extractToRight<mss::ROW_REPAIR_DRAM_POS, ROW_REPAIR_DRAM_POS_LEN>(l_dram);
    uint8_t l_byte = 0;

    // Mask assuming a x8 DRAM, so the whole byte
    uint8_t l_mask = 0xff;

    uint8_t l_dram_width = 0;
    FAPI_TRY( mss::attr::get_dram_width(i_target, l_dram_width) );

    // The DRAM index in ATTR_ROW_REPAIR_DATA is relative to the logical perspective.
    // The bad_bits attribute is also logical perspective according to PRD
    // using the DRAM index
    // TODO: Move to helper function Zen#646
    l_byte = (l_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ?
             l_dram :
             l_dram / mss::NIBBLES_PER_BYTE;

    if (l_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4)
    {
        l_mask = mss::is_odd(l_dram) ? MASK_NIBBLE1 : MASK_NIBBLE0;
    }

    // Protect our array index
    FAPI_ASSERT(l_byte < mss::BAD_DQ_BYTE_COUNT,
                fapi2::EXP_DRAM_INDEX_OUT_OF_BOUNDS().
                set_DIMM_TARGET(i_target).
                set_DRAM_WIDTH(l_dram_width).
                set_INDEX(l_dram),
                "DRAM index %d supplied to get_num_bad_bits is out of bounds on %s",
                l_dram, mss::spd::c_str(i_target));

    {
        const uint8_t l_bad_bits_on_dram = i_bad_bits[l_byte] & l_mask;
        o_num_bad_bits_for_dram = mss::bit_count(l_bad_bits_on_dram);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the row repair attribute and clears out any unneeded repairs
/// @param[in] i_target the DIMM target on which to operate
/// @param[out] o_row_repair_data the row repair data to process for this DIMM
/// @return FAPI2_RC_SUCCESS iff successful
/// @note Clears out the repairs if there is more than one bad bit on the DRAM that would be repaired
///
fapi2::ReturnCode clear_row_repairs_on_bad_dram(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_row_repair_data)[mss::exp::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK])
{
    constexpr uint8_t WHOLE_DRAM_BAD = 2;
    constexpr uint8_t ROW_REPAIR_CLEAR_VALUE = 0;
    constexpr uint8_t ROW_REPAIR_DRAM_BYTE = 0;
    constexpr uint8_t ROW_REPAIR_VALID_BYTE = 3;
    constexpr uint8_t ROW_REPAIR_VALID_BIT = 7;
    uint8_t l_bad_dq_bitmap[mss::exp::MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT] = {};
    FAPI_TRY( mss::attr::get_bad_dq_bitmap(i_target, l_bad_dq_bitmap) );

    // Load row repair data for the dimm
    FAPI_TRY( mss::attr::get_row_repair_data(i_target, o_row_repair_data) );

    // Loops through all of the possible ranks on this DIMM and checks the repair data
    for(uint8_t l_rank = 0; l_rank < mss::exp::MAX_RANK_PER_DIMM; ++l_rank)
    {
        const fapi2::buffer<uint8_t> l_repair_valid_data(o_row_repair_data[l_rank][ROW_REPAIR_VALID_BYTE]);

        // If this repair is not valid, skip it
        if(!l_repair_valid_data.getBit<ROW_REPAIR_VALID_BIT>())
        {
            continue;
        }

        // Otherwise, ensure that the row repair is on a DRAM that won't have to be spared or marked off
        // Note: DRAMs will have to be spared or marked off at two bad bits
        uint8_t l_num_bad_bits = 0;

        // Gets the number of bad bits for the DRAM associated with this repair data
        FAPI_TRY(get_num_bad_bits(i_target,
                                  o_row_repair_data[l_rank][ROW_REPAIR_DRAM_BYTE],
                                  l_bad_dq_bitmap[l_rank],
                                  l_num_bad_bits),
                 "Failed to retrieve number of bad bits on rank %d on %s",
                 l_rank, mss::c_str(i_target));

        // If the whole DRAM would be called out as bad, then clear the row repair data associated
        // This way, we free up the row repair on this rank
        if(l_num_bad_bits >= WHOLE_DRAM_BAD)
        {
            std::fill(std::begin(o_row_repair_data[l_rank]), std::end(o_row_repair_data[l_rank]), ROW_REPAIR_CLEAR_VALUE);
        }
    }

    // Sets the row repair data
    // This way, any repairs that were freed can be cleaned up
    FAPI_TRY( mss::attr::set_row_repair_data(i_target, o_row_repair_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Map all repair data to dimm target
/// @param[in] i_target_ocmb ocmb target
/// @param[out] o_repair_map the map to fill with repair pairs
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode map_repairs_per_dimm( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb,
                                        REPAIR_MAP& o_repair_map )
{
    // Clear map for new repairs
    o_repair_map.clear();

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_ocmb))
    {
        uint8_t l_row_repair_data[mss::exp::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK] = {0};
        std::vector<mss::row_repair::repair_entry<mss::mc_type::EXPLORER>> l_repairs_per_dimm;

        // Load row repair data for the dimm
        FAPI_TRY( mss::attr::get_row_repair_data(l_dimm, l_row_repair_data) );

        // Clear out any repairs on bad DRAM
        // This way, we can use those row repairs again if needed
        FAPI_TRY( clear_row_repairs_on_bad_dram(l_dimm, l_row_repair_data),
                  "Failed to clear row repairs on %s",
                  mss::c_str(l_dimm) );

        // Build repair table
        FAPI_TRY( build_row_repair_table(l_dimm, l_row_repair_data, l_repairs_per_dimm),
                  "Failed to build row repair table on %s",
                  mss::c_str(l_dimm) );

        // Add dimm repairs to map
        o_repair_map.insert(std::make_pair(l_dimm, l_repairs_per_dimm));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deploy mapped row repairs
/// @param[in] i_repair_map the map with repair data pairs
/// @param[in] i_runtime true if at runtime requiring dynamic
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode deploy_mapped_repairs( const REPAIR_MAP& i_repair_map,
        const bool i_runtime )
{
    // Iterate through DRAM repairs structure
    for (const auto l_pair : i_repair_map)
    {
        const auto& l_dimm = l_pair.first;
        const auto& l_repairs = l_pair.second;

        // Loops thru repairs
        for (const auto& l_repair : l_repairs)
        {
            const auto& l_dimm_rank = l_repair.iv_dimm_rank;
            fapi2::buffer<uint64_t> l_dram_bitmap;
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            mss::rank::info<mss::mc_type::EXPLORER> l_rank_info(l_dimm, l_dimm_rank, l_rc);
            const auto& l_port_rank = l_rank_info.get_port_rank();

            // Check rank info completed
            FAPI_TRY(l_rc, "Failed creating rank info %s", mss::c_str(l_dimm));

            if (l_repair.is_valid())
            {
                // Deploy row repair and clear bad DQs
                FAPI_INF("%s Deploying row repair on DRAM %d, dimm rank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                         mss::spd::c_str(l_dimm), l_repair.iv_dram, l_dimm_rank, l_repair.iv_srank, l_repair.iv_bg, l_repair.iv_bank,
                         l_repair.iv_row);

                // Set DRAM select bit for dram
                FAPI_TRY(create_dram_bitmap(l_repair.iv_dram, l_dram_bitmap),
                         "Failed to create dram bitmap", mss::c_str(l_dimm) );

                // Check if at runtime for dynamic vs maint
                if (i_runtime)
                {
                    FAPI_TRY( dynamic_row_repair(l_rank_info, l_repair, l_dram_bitmap),
                              "Failed dynamic_row_repair on %s rank %d",
                              mss::c_str(l_dimm), l_dimm_rank );
                }
                else
                {
                    FAPI_TRY( maint_row_repair(l_rank_info, l_repair, l_dram_bitmap),
                              "Failed maint_row_repair on %s rank %d",
                              mss::c_str(l_dimm), l_dimm_rank );
                }

                // Clear bad DQ bits for this port, DIMM, rank that will be fixed by this row repair
                FAPI_INF("Updating bad bits on DIMM %s, DRAM %d, port rank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                         mss::c_str(l_dimm), l_repair.iv_dram, l_port_rank, l_repair.iv_srank, l_repair.iv_bg,
                         l_repair.iv_bank, l_repair.iv_row);
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace row_repair
} // namespace exp
} // namespace mss
