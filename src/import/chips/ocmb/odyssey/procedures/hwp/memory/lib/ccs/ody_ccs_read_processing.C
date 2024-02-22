/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_ccs_read_processing.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_ccs_read_processing.H
/// @brief  Process ccs read data for ddr5
///
// *HWP HWP Owner: Adithi Ganapathi <adithi.t.ganapathi@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB

#include <fapi2.H>
#include <lib/ccs/ody_ccs_read_processing.H>

#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/mcbist/ody_mcbist.H>

namespace mss
{
namespace ccs
{
///
/// @brief Grab the ccs trap data from the maint buffer
/// @param[in] i_target OCMB target on which to operate
/// @param[in] i_address the buffer position to read from
/// @param[out] o_aadr_data the AADR data read from the buffer
/// @param[out] o_aaer_data the AAER data read from the buffer
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode grab_ody_ccs_trap_data( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_address,
        fapi2::buffer<uint64_t>& o_aadr_data,
        fapi2::buffer<uint64_t>& o_aaer_data)
{
    // Maint buffer limit
    constexpr uint64_t BUFFER_OVERFLOW = 0x10;

    fapi2::buffer<uint64_t> l_aacr_data;
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    o_aadr_data = 0;
    o_aaer_data = 0;

    // The buffer will loop around if it's full
    const uint64_t l_addr = i_address % BUFFER_OVERFLOW;

    // Set up the array to read from,
    //Disable autoincrement
    l_aacr_data.clearBit<scomt::ody::ODC_WDF_REGS_AACR_AUTOINC>()
    // disable eccgen
    .clearBit<scomt::ody::ODC_WDF_REGS_AACR_ECCGEN>()
    // disable buffer
    .clearBit<scomt::ody::ODC_WDF_REGS_AACR_BUFFER>()
    // enable passthru
    .setBit<scomt::ody::ODC_WDF_REGS_AACR_PASSTHRU>();

    mss::mcbist::set_rmw_address<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_addr, l_aacr_data);

    // Write the address we want to read, then read out of the arrays
    FAPI_TRY(fapi2::putScom(l_ocmb_target, scomt::ody::ODC_WDF_REGS_AACR, l_aacr_data));
    FAPI_TRY(fapi2::getScom(l_ocmb_target, scomt::ody::ODC_WDF_REGS_AADR, o_aadr_data));
    FAPI_TRY(fapi2::getScom(l_ocmb_target, scomt::ody::ODC_WDF_REGS_AAER, o_aaer_data));

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Processes the first spare and ecc data into the beat pair
/// @param[in, out] io_beat_pair processed beat pair data
/// @param[in] i_aaer the aaer data
///
void process_aaer_first(mss::beat_pair& io_beat_pair, const fapi2::buffer<uint64_t>& i_aaer)
{
    constexpr uint64_t BYTE4_IDX = 4;
    constexpr uint64_t BYTE5_IDX = 5;
    constexpr uint64_t BEAT1 = 1;
    constexpr uint64_t BYTE0_POS = 0 * BITS_PER_BYTE;
    constexpr uint64_t BYTE1_POS = 1 * BITS_PER_BYTE;
    i_aaer.extractToRight<BYTE0_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE4_IDX][BEAT1]);
    i_aaer.extractToRight<BYTE1_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE5_IDX][BEAT1]);

}

///
/// @brief Processes the second spare and ecc data into the beat pair
/// @param[in, out] io_beat_pair processed beat pair data
/// @param[in] i_aaer the aaer data
///
void process_aaer_second(mss::beat_pair& io_beat_pair, const fapi2::buffer<uint64_t>& i_aaer)
{
    constexpr uint64_t BYTE4_IDX = 4;
    constexpr uint64_t BYTE5_IDX = 5;
    constexpr uint64_t BEAT0 = 0;
    constexpr uint64_t BYTE0_POS = 0 * BITS_PER_BYTE;
    constexpr uint64_t BYTE1_POS = 1 * BITS_PER_BYTE;
    i_aaer.extractToRight<BYTE0_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE4_IDX][BEAT0]);
    i_aaer.extractToRight<BYTE1_POS, BITS_PER_BYTE>(io_beat_pair.iv_data[BYTE5_IDX][BEAT0]);
}

///
/// @brief Reads and process the CCS data out of the buffers
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_data the data read from the buffer
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode prepare_ody_ccs_beat_data(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        mss::pair<uint64_t, uint16_t> (&o_data)[mss::ody::CCS_BEAT_DATA_SIZE])
{
    // Clear the o_data buffer before each read to ensure no data from a previous run is present
    memset(&o_data, 0, sizeof(o_data) / sizeof(o_data[0]));

    // Loops over all 8 beats of data that can be in burst
    constexpr uint64_t BEATS_PER_BURST = 16;
    constexpr uint64_t BEATS_PER_TRAP = 2;

    for (uint64_t i = 0; i < BEATS_PER_BURST; i += BEATS_PER_TRAP)
    {
        mss::beat_pair l_trap;
        mss::mcbist::raw_data_trap l_read;

        // Grab the beat pair data
        FAPI_TRY(grab_ody_ccs_trap_data(i_target, i    , l_read.iv_aadr_first, l_read.iv_aaer_first));
        FAPI_TRY(grab_ody_ccs_trap_data(i_target, i + 1, l_read.iv_aadr_second, l_read.iv_aaer_second));

#ifndef __PPE__
        FAPI_DBG(GENTARGTIDFORMAT " RAW_DATA maint1:%3u 0x%016lx 0x%016lx",
                 GENTARGTID(i_target), i, l_read.iv_aadr_first, l_read.iv_aaer_first);
        FAPI_DBG(GENTARGTIDFORMAT " RAW_DATA maint2:%3u 0x%016lx 0x%016lx",
                 GENTARGTID(i_target), i + 1, l_read.iv_aadr_second, l_read.iv_aaer_second);
#endif

        // Processes the beat pair data into the trap format
        mss::mcbist::process_data_compare_beat_pair(l_read, l_trap);
        process_aaer_first(l_trap, l_read.iv_aaer_first);
        process_aaer_second(l_trap, l_read.iv_aaer_second);

        // Assembles the human readable print data and adds it to the array
        o_data[i]   = mss::assemble_print_data(l_trap, 0);
        o_data[i + 1] = mss::assemble_print_data(l_trap, 1);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief To process and extract the OP code data from individual buffers
/// @param[in] i_dram_number to increment based on dram number
/// @param[in] i_dram_width number of dqs per device type
/// @param[in] i_data processed and assembled data from maint buffer
/// @param[out] o_op_code final op code data
/// @return FAPI2_RC_SUCCSS iff ok
//
fapi2::ReturnCode get_op_code(const uint8_t i_dram_number, const uint8_t i_dram_width,
                              const mss::pair<uint64_t, uint16_t> (&i_data)[mss::ody::CCS_BEAT_DATA_SIZE], uint8_t& o_op_code)
{
    /// As per ddr5 JEDEC spec, this function ignores BL 0-7
    /// and Extracts data out of BL 8-15 of DQ0 since rest of the DQs per device are redundant
    /// Sample DQ Output Map for x4 device -
    /// BL 0-7 8 9 10 11 12 13 14 15
    /// DQ0 0 OP0 OP1 OP2 OP3 OP4 OP5 OP6 OP7
    /// DQ1 1 !OP0 !OP1 !OP2 !OP3 !OP4 !OP5 !OP6 !OP7
    /// DQ2 0 OP0 OP1 OP2 OP3 OP4 OP5 OP6 OP7
    /// DQ3 1 !OP0 !OP1 !OP2 !OP3 !OP4 !OP5 !OP6 !OP7
    /// i_data is the vertical version of the above horizontal jedec spec table and processing the op code as follows

    /// DRAM   0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 x4 device
    /// DRAM   0 1 2 3 4 5 6 7     8 9 x8 device
    /// BYTE   0011223344556677    8899
    /// NIBBLE 0101010101010101    0101
    /// below is a sample of part of the processed ccs maint buffer (i.e. i_data)
    /// BL8 - {0xaaaaaaaaaa5aaaa5, 0x5aaa}-> bit0 of each nibble corresponds to OP0 stored in DQ0 of each dram
    /// BL9 - {0x55555555a555555a, 0xa555}-> bit0 of each nibble corresponds to OP1 stored in DQ0 of each dram
    /// BL10- {0x55555555a555555a, 0x555a}-> bit0 of each nibble corresponds to OP2 stored in DQ0 of each dram and so on till BL15

    /// converts to -top to bottom -
    /// (byte,nibble) (0,0) (0,1) (1,0) .....(9,1)
    ///              DRAM0 DRAM1 DRAM2 ..... DRAM19
    /// BL-8   0x      a     a     a  ..... a
    ///              1010   1010   1010 ..... 1010
    ///             DQ0123  DQ0123 DQ0123 .... DQ0123
    ///             OP0     OP0    OP0

    /// BL-9  0x      5         5       5
    ///             0101       0101     0101
    ///             DQ0123     DQ0123   DQ0123
    ///             OP1        OP1      OP1
    /// and so on until BL-15 which stores OP7 of each dram

    fapi2::buffer<uint8_t> l_mr_temp_value;
    int l_target_incr = 7;
    //to ignore the BL0-7 as per Jedec spec
    constexpr uint8_t OP_CODE_OFFSET = 8;

    for(uint8_t l_data_index = OP_CODE_OFFSET; l_data_index < mss::ody::CCS_BEAT_DATA_SIZE; ++l_data_index )
    {
        fapi2::buffer<uint8_t> l_data_dq0;
        fapi2::variable_buffer l_extra(mss::ody::MAX_DQ_BITS_PER_PORT);
        FAPI_TRY(l_extra.insert(i_data[l_data_index].first, 0, 64));
        FAPI_TRY(l_extra.insert(i_data[l_data_index].second, 64, 16));

#ifndef __PPE__
        FAPI_DBG("maint_processed_data:%d 0x%016lx 0x%016lx",
                 l_data_index, i_data[l_data_index].first, i_data[l_data_index].second);
#endif
        // extracts op code from DQ0 only of each dram based on dram width and inserts it in OP7:0 format
        FAPI_TRY(l_extra.extractToRight(l_data_dq0, i_dram_number * i_dram_width, 1));
        FAPI_TRY(l_mr_temp_value.insert(l_data_dq0, l_target_incr, 1, 7));
        l_target_incr -= 1;
    }

    FAPI_INF_NO_SBE("DRAM NUMBER: %d - OP code in HEX 0x%02lx ", i_dram_number, l_mr_temp_value);

    o_op_code = l_mr_temp_value;

fapi_try_exit:
    return fapi2::current_err;
}
}//mss
}//ccs
