/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file mrs_load_ddr4.H
/// @brief Code to support mrs_load_ddr4
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_LOAD_DDR4_H_
#define _MSS_MRS_LOAD_DDR4_H_

#include <vector>
#include <fapi2.H>
#include <lib/utils/c_str.H>
#include <lib/dimm/mrs_load.H>

namespace mss
{

namespace ddr4
{

// Forward declarations
class mrs00_data;
class mrs01_data;
class mrs02_data;
class mrs03_data;
class mrs04_data;
class mrs05_data;
class mrs06_data;

///
/// @defgroup setup-ccs
/// @addtogroyp setup-ccs
/// API which setup CCS instructions.
/// @{

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

/// }@

///
/// @defgroup setup-ccs-overloads
/// @addtogroyp setup-ccs-overloads
/// API which setup CCS instructions, but take an MRS data object as input
/// @{

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs00_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs01_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs01_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs02_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs02_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs03_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs04_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs04_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs05_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs05_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs06_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs06_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

/// }@

///
/// @defgroup ccs-decode
/// @addtogroyccs-decode
/// API which decode CCS instructions.
/// @{

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS00,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs00_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS01,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs01_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS02,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs02_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS03,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs03_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS04,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs04_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS05,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs05_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS06,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs06_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @defgroup mrs-structs
/// @addtogroup mrs-structs
// Each MRS has it's attributes encapsulated in it's little struct.
/// @{

///
/// @brief Data structure for MRS0 data
///
struct mrs00_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 0;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    // Kind of inverted; normally you'd implement this as a method of this class. But that
    // would mean pointers <sigh> as we'd have to make the IPL MRS machine's table leverage
    // dynaimc polymorphism and I avoid that where possible.
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs00_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs00_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs00_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_burst_length;
    uint8_t iv_read_burst_type;
    uint8_t iv_dll_reset;
    uint8_t iv_test_mode;
    uint8_t iv_write_recovery;
    uint8_t iv_cas_latency;
};

///
/// @brief Data structure for MRS1 data
///
struct mrs01_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 1;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs01_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs01_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs01_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_dll_enable;
    uint8_t iv_odic[MAX_RANK_PER_DIMM];
    uint8_t iv_additive_latency;
    uint8_t iv_wl_enable;
    uint8_t iv_tdqs;
    uint8_t iv_qoff;
    uint8_t iv_rtt_nom[MAX_RANK_PER_DIMM];
};

///
/// @brief Data structure for MRS2 data
///
struct mrs02_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 2;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs02_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs03_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs02_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_lpasr;
    uint8_t iv_cwl;
    uint8_t iv_write_crc;
    uint8_t iv_dram_rtt_wr[MAX_RANK_PER_DIMM];
};


///
/// @brief Data structure for MRS3 data
///
struct mrs03_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 3;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs03_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs03_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs03_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_mpr_mode;
    uint8_t iv_mpr_page;
    uint8_t iv_geardown;
    uint8_t iv_pda;
    uint8_t iv_crc_wr_latency;
    uint8_t iv_temp_readout;
    uint8_t iv_fine_refresh;
    uint8_t iv_read_format;
};

///
/// @brief Data structure for MRS4 data
///
struct mrs04_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 4;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs04_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs04_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs04_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_max_pd_mode;
    uint8_t iv_temp_refresh_range;
    uint8_t iv_temp_ref_mode;
    uint8_t iv_vref_mon;
    uint8_t iv_cs_cmd_latency;
    uint8_t iv_ref_abort;
    uint8_t iv_rd_pre_train_mode;
    uint8_t iv_rd_preamble;
    uint8_t iv_wr_preamble;
    uint8_t iv_ppr;
};

///
/// @brief Data structure for MRS5 data
///
struct mrs05_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 5;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs05_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs05_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs05_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_ca_parity_latency;
    uint8_t iv_crc_error_clear;
    uint8_t iv_ca_parity_error_status;
    uint8_t iv_odt_input_buffer;
    uint8_t iv_ca_parity;
    uint8_t iv_data_mask;
    uint8_t iv_write_dbi;
    uint8_t iv_read_dbi;
    uint8_t iv_rtt_park[MAX_RANK_PER_DIMM];
};

///
/// @brief Data structure for MRS6 data
///
struct mrs06_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_number = 6;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs06_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs06_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs06_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_vrefdq_train_value[MAX_RANK_PER_DIMM];
    uint8_t iv_vrefdq_train_range[MAX_RANK_PER_DIMM];
    uint8_t iv_vrefdq_train_enable[MAX_RANK_PER_DIMM];
    uint8_t iv_tccd_l;
};

/// @}

///
/// @brief Perform the mrs_load DDR4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

} // ns ddr4

// Map bits in the ARR0 register(s) to MRS address bits. Should be traits related to ARR0. BRS
enum address_bits
{
    A0 = 0,
    A1 = 1,
    A2 = 2,
    A3 = 3,
    A4 = 4,
    A5 = 5,
    A6 = 6,
    A7 = 7,
    A8 = 8,
    A9 = 9,
    A10 = 10,
    A11 = 11,
    A12 = 12,
    A13 = 13,
    A14 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_14,
    A15 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_15,
    A16 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_16,
    A17 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_17,

    // Only kind of address bits ... <shrug>
    BA0 = 17,
    BA1 = 18,
    BG0 = 19,
    BG1 = 15,
};

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction - implementation
/// @tparam T typename of the ccs::instruction_t
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note written this way so this is easier to test
///
template<fapi2::TargetType T>
void address_mirror_impl(ccs::instruction_t<T>& io_inst)
{
    // Nothing fancy here, just mirror the bits we're told to mirror in Table 14 — Address Mirroring and Inversion
    mss::template swap<A3, A4>(io_inst.arr0);
    mss::template swap<A5, A6>(io_inst.arr0);
    mss::template swap<A7, A8>(io_inst.arr0);
    mss::template swap<A11, A13>(io_inst.arr0);
    mss::template swap<BA0, BA1>(io_inst.arr0);
    mss::template swap<BG0, BG1>(io_inst.arr0);
}

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction
/// @tparam T typename of the ccs::instruction_t
/// @param[in] i_target target to use to get mirroring attribute
/// @param[in] i_rank the rank in question
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note assumes the input is from an even number rank
///
template<fapi2::TargetType T>
fapi2::ReturnCode address_mirror(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank, ccs::instruction_t<T>& io_inst)
{
    // We only mirror if the mirroring attribute is set.
    uint8_t l_mirror = 0;
    FAPI_TRY( eff_dimm_rcd_mirror_mode(i_target, l_mirror) );

    // We only mirror odd ranks.
    if ((l_mirror == fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON) && (i_rank & 0x1))
    {
        address_mirror_impl(io_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Invert (side to side) the ADR bits of a CCS instruction
/// @param[in] i_inst const reference to a CCS instruction.
/// @return[out] ccs instruction with the ADR bits inverted (side-to-side)
///
template<fapi2::TargetType T>
ccs::instruction_t<T> address_invert(const ccs::instruction_t<T>& i_inst)
{
    // Copy the input as the output doesn't all change.
    ccs::instruction_t<T> i_out(i_inst);

    // Nothing fancy here, just negate the bits we're told to negate in Table 14 — Address Mirroring and Inversion
    mss::template negate<A3>(i_out.arr0);
    mss::template negate<A4>(i_out.arr0);
    mss::template negate<A5>(i_out.arr0);
    mss::template negate<A6>(i_out.arr0);
    mss::template negate<A7>(i_out.arr0);
    mss::template negate<A8>(i_out.arr0);
    mss::template negate<A9>(i_out.arr0);

    mss::template negate<A11>(i_out.arr0);
    mss::template negate<A13>(i_out.arr0);
    mss::template negate<A17>(i_out.arr0);

    mss::template negate<BA0>(i_out.arr0);
    mss::template negate<BA1>(i_out.arr0);
    mss::template negate<BG0>(i_out.arr0);
    mss::template negate<BG1>(i_out.arr0);

    return i_out;
}

} // namespace
#endif
