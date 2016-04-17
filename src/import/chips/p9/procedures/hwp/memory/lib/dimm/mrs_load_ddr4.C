/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/mrs_load_ddr4.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file mrs_load_ddr4.C
/// @brief Run and manage the DDR4 mrs loading
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Bill Hoffa <wghoffa@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/mrs_load_ddr4.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

//
// Each MRS has it's attributes encapsulated in it's little setter function.
//

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs00(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    // Map from Write Recovery attribute value to bits in the MRS.
    // Bit 4 is A13, bits 5:7 are A11:A9
    static const uint8_t wr_map[27] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b0000, 0, 0b0001, 0, 0b0001, 0, 0b0011,
        0, 0b0100, 0, 0b0101, 0, 0b0111, 0, 0b0110, 0, 0b1000
    };

    // Map from the CAS Latency attribute to the bits in the MRS
    static const uint8_t cl_map[34] =
    {
        // 0  1  2  3  4  5  6  7  8
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        // 9        10       11       12       13       14       15       16
        0b00000, 0b00001, 0b00010, 0b00011, 0b00100, 0b00101, 0b00110, 0b00111,
        // 17,      18       19       20       21       22       23       24
        0b01101, 0b01000, 0b01110, 0b01001, 0b01111, 0b01010, 0b01100, 0b01011,
        // 25       26       27       28       29       30       31       32       33
        0b10000, 0b10001, 0b10010, 0b10011, 0b10100, 0b10101, 0b10110, 0b10111, 0b11000
    };

    uint8_t l_burst_length = 0;
    uint8_t l_read_burst_type = 0;
    uint8_t l_dll_reset = 0;
    uint8_t l_test_mode = 0;
    uint8_t l_write_recovery = 0;
    uint8_t l_cas_latency = 0;

    fapi2::buffer<uint8_t> l_cl;
    fapi2::buffer<uint8_t> l_wr;

    FAPI_TRY( mss::eff_dram_bl(i_target, l_burst_length) );
    FAPI_TRY( mss::eff_dram_rbt(i_target, l_read_burst_type) );
    FAPI_TRY( mss::eff_dram_cl(i_target, l_cas_latency) );
    FAPI_TRY( mss::eff_dram_dll_reset(i_target, l_dll_reset) );
    FAPI_TRY( mss::eff_dram_tm(i_target, l_test_mode) );
    FAPI_TRY( mss::eff_dram_twr(i_target, l_write_recovery) );

    FAPI_DBG("MR0 Attributes: BL: 0x%x, RBT: 0x%x, CL: 0x%x(0x%x), TM: 0x%x, DLL_RESET: 0x%x, WR: 0x%x(0x%x)",
             l_burst_length, l_read_burst_type, l_cas_latency, cl_map[l_cas_latency],
             l_test_mode, l_dll_reset, l_write_recovery, wr_map[l_write_recovery]);

    io_inst.arr0.insertFromRight<A0, 2>(l_burst_length);
    io_inst.arr0.writeBit<A3>(l_read_burst_type);
    io_inst.arr0.writeBit<A7>(l_test_mode);
    io_inst.arr0.writeBit<A8>(l_dll_reset);

    // CAS Latency takes a little effort - the bits aren't contiguous
    l_cl = cl_map[l_cas_latency];
    io_inst.arr0.writeBit<A12>(l_cl.getBit<3>());
    io_inst.arr0.writeBit<A6>(l_cl.getBit<4>());
    io_inst.arr0.writeBit<A5>(l_cl.getBit<5>());
    io_inst.arr0.writeBit<A4>(l_cl.getBit<6>());
    io_inst.arr0.writeBit<A2>(l_cl.getBit<7>());

    // Write Recovery/Read to Precharge is not contiguous either.
    l_wr = wr_map[l_write_recovery];
    io_inst.arr0.writeBit<A13>(l_wr.getBit<4>());
    io_inst.arr0.writeBit<A11>(l_wr.getBit<5>());
    io_inst.arr0.writeBit<A10>(l_wr.getBit<6>());
    io_inst.arr0.writeBit<A9>(l_wr.getBit<7>());

    FAPI_DBG("MR0: 0x%016llx", uint64_t(io_inst.arr0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS0,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs00_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    static const uint8_t wr_map[9] = { 10, 12, 14, 16, 18, 20, 24, 22, 26 };

    uint8_t l_burst_length = 0;
    uint8_t l_read_burst_type = 0;
    uint8_t l_dll_reset = 0;
    uint8_t l_test_mode = 0;

    fapi2::buffer<uint8_t> l_wr_index;
    fapi2::buffer<uint8_t> l_cas_latency;

    i_inst.arr0.extractToRight<A0, 2>(l_burst_length);
    l_read_burst_type = i_inst.arr0.getBit<A3>();
    l_test_mode = i_inst.arr0.getBit<A7>();
    l_dll_reset = i_inst.arr0.getBit<A8>();

    // CAS Latency takes a little effort - the bits aren't contiguous
    l_cas_latency.writeBit<3>(i_inst.arr0.getBit<A12>());
    l_cas_latency.writeBit<4>(i_inst.arr0.getBit<A6>());
    l_cas_latency.writeBit<5>(i_inst.arr0.getBit<A5>());
    l_cas_latency.writeBit<6>(i_inst.arr0.getBit<A4>());
    l_cas_latency.writeBit<7>(i_inst.arr0.getBit<A2>());

    // Write Recovery/Read to Precharge is not contiguous either.
    l_wr_index.writeBit<4>(i_inst.arr0.getBit<A13>());
    l_wr_index.writeBit<5>(i_inst.arr0.getBit<A11>());
    l_wr_index.writeBit<6>(i_inst.arr0.getBit<A10>());
    l_wr_index.writeBit<7>(i_inst.arr0.getBit<A9>());

    FAPI_DBG("MR0 Decode BL: 0x%x, RBT: 0x%x, CL: 0x%x, TM: 0x%x, DLL_RESET: 0x%x, WR: (0x%x)0x%x",
             l_burst_length, l_read_burst_type, uint8_t(l_cas_latency), l_test_mode, l_dll_reset,
             wr_map[uint8_t(l_wr_index)], uint8_t(l_wr_index));

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs01(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    // Little table to map Output Driver Imepdance Control. 34Ohm is index 0,
    // 48Ohm is index 1 and we expect eff_config to make sure there's nothing
    // else used here.
    // Left bit is A2, right bit is A1
    static const uint8_t odic_map[2] = { 0b00, 0b01 };

    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    //                                      0  RQZ/1  RQZ/2  RQZ/3  RQZ/4  RQZ/5  RQZ/6  RQZ/7
    static const uint8_t rtt_nom_map[8] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    uint8_t l_dll_enable = 0;
    uint8_t l_odic = 0;
    uint8_t l_wl_enable = 0;
    uint8_t l_tdqs = 0;
    uint8_t l_qoff = 0;
    uint8_t l_rtt_nom[MAX_RANK_PER_DIMM] = {0};

    size_t l_rtt_nom_index = 0;

    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_odic_buffer;
    fapi2::buffer<uint8_t> l_rtt_nom_buffer;

    FAPI_TRY( mss::eff_dram_dll_enable(i_target, l_dll_enable) );
    FAPI_TRY( mss::eff_dram_ron(i_target, l_odic) );
    FAPI_TRY( mss::eff_dram_al(i_target, l_additive_latency) );
    FAPI_TRY( mss::eff_dram_wr_lvl_enable(i_target, l_wl_enable) );
    FAPI_TRY( mss::eff_dram_rtt_nom(i_target, &(l_rtt_nom[0])) );
    FAPI_TRY( mss::eff_dram_tdqs(i_target, l_tdqs) );
    FAPI_TRY( mss::eff_dram_output_buffer(i_target, l_qoff) );

    // Map from impedance to bits in MRS1
    l_odic_buffer = (l_odic == fapi2::ENUM_ATTR_EFF_DRAM_RON_OHM34) ? odic_map[0] : odic_map[1];

    // We have to be careful about 0
    l_rtt_nom_index = (l_rtt_nom[mss::index(i_rank)] == 0) ?
                      0 : fapi2::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM240 / l_rtt_nom[mss::index(i_rank)];

    // Map from RTT_NOM array to the value in the map
    l_rtt_nom_buffer = rtt_nom_map[l_rtt_nom_index];

    FAPI_INF("MR1 rank %d attributes: DLL_ENABLE: 0x%x, ODIC: 0x%x(0x%x), AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM: 0x%x(0x%x), TDQS: 0x%x, QOFF: 0x%x", i_rank,
             l_dll_enable, l_odic, uint8_t(l_odic_buffer), uint8_t(l_additive_latency), l_wl_enable,
             l_rtt_nom[mss::index(i_rank)], uint8_t(l_rtt_nom_buffer), l_tdqs, l_qoff);

    io_inst.arr0.writeBit<A0>(l_dll_enable);
    mss::swizzle<A1, 2, 7>(l_odic_buffer, io_inst.arr0);
    mss::swizzle<A3, 2, 7>(l_additive_latency, io_inst.arr0);
    io_inst.arr0.writeBit<A7>(l_wl_enable);
    mss::swizzle<A8, 3, 7>(l_rtt_nom_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A11>(l_tdqs);
    io_inst.arr0.writeBit<A12>(l_qoff);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS1,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs01_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_odic;
    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_rtt_nom;

    uint8_t l_dll_enable = i_inst.arr0.getBit<A0>();
    uint8_t l_wrl_enable = i_inst.arr0.getBit<A7>();
    uint8_t l_tdqs = i_inst.arr0.getBit<A11>();
    uint8_t l_qoff = i_inst.arr0.getBit<A12>();

    mss::swizzle<6, 2, A2>(i_inst.arr0, l_odic);
    mss::swizzle<6, 2, A4>(i_inst.arr0, l_additive_latency);
    mss::swizzle<5, 3, A10>(i_inst.arr0, l_rtt_nom);

    FAPI_INF("MR1 rank %d decode: DLL_ENABLE: 0x%x, ODIC: 0x%x, AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM: 0x%x, TDQS: 0x%x, QOFF: 0x%x", i_rank,
             l_dll_enable, uint8_t(l_odic), uint8_t(l_additive_latency), l_wrl_enable, uint8_t(l_rtt_nom),
             l_tdqs, l_qoff);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Given a uint32_t, which contains address bits with an encoded MRS1,
/// decode and trace the contents
/// @param[in] i_value ADR 17:0
/// @return void
///
fapi2::ReturnCode ddr4_mrs01_decode(const uint32_t i_value)
{
    fapi2::buffer<uint32_t> l_data(i_value);
    // Flip l_data so bit 0 is bit 0, bit 17 is bit 17 ...
    reverse(l_data);

    fapi2::buffer<uint8_t> l_odic;
    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_rtt_nom;

    uint8_t l_dll_enable = l_data.getBit<A0>();
    uint8_t l_wrl_enable = l_data.getBit<A7>();
    uint8_t l_tdqs = l_data.getBit<A11>();
    uint8_t l_qoff = l_data.getBit<A12>();

    mss::swizzle<6, 2, A2>(l_data, l_odic);
    mss::swizzle<6, 2, A4>(l_data, l_additive_latency);
    mss::swizzle<5, 3, A10>(l_data, l_rtt_nom);

    FAPI_INF("MR1 buffer decode: DLL_ENABLE: 0x%x, ODIC: 0x%x, AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM: 0x%x, TDQS: 0x%x, QOFF: 0x%x",
             l_dll_enable, uint8_t(l_odic), uint8_t(l_additive_latency), l_wrl_enable, uint8_t(l_rtt_nom),
             l_tdqs, l_qoff);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs02(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    // Index this by subtracting 9 from the CWL attribute value.
    static const uint64_t LOWEST_CWL = 9;
    //                                     9     10     11     12        14         16       18        20
    static const uint8_t cwl_map[12] = { 0b000, 0b001, 0b010, 0b011, 0, 0b100, 0, 0b101, 0, 0b110, 0, 0b111 };

    fapi2::buffer<uint8_t> l_lpasr;
    uint8_t l_cwl = 0;
    uint8_t l_dram_rtt_wr[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_write_crc = 0;

    fapi2::buffer<uint8_t> l_cwl_buffer;
    fapi2::buffer<uint8_t> l_rtt_wr_buffer;

    FAPI_TRY( mss::eff_dram_lpasr(i_target, l_lpasr) );
    FAPI_TRY( mss::eff_dram_cwl(i_target, l_cwl) );
    FAPI_TRY( mss::eff_dram_rtt_wr(i_target, &(l_dram_rtt_wr[0])) );
    FAPI_TRY( mss::eff_write_crc(i_target, l_write_crc) );

    l_cwl_buffer = cwl_map[l_cwl - LOWEST_CWL];

    // Arg. Change this. BRS
    switch (l_dram_rtt_wr[i_rank])
    {
        case fapi2::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE:
            l_rtt_wr_buffer = 0b000;
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_RTT_WR_HIGHZ:
            l_rtt_wr_buffer = 0b011;
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM240:
            l_rtt_wr_buffer = 0b010;
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120:
            l_rtt_wr_buffer = 0b001;
            break;

        case fapi2::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60:
            l_rtt_wr_buffer = 0b100;
            break;

        default:
            FAPI_ERR("unknown RTT_WR 0x%x (%s rank %d), dynamic odt off",
                     l_dram_rtt_wr[i_rank], mss::c_str(i_target), i_rank);
            l_rtt_wr_buffer = 0b000;
            break;
    };

    FAPI_INF("MR2 rank %d attributes: LPASR: 0x%x, CWL: 0x%x(0x%x), RTT_WR: 0x%x(0x%x), WRITE_CRC: 0x%x", i_rank,
             uint8_t(l_lpasr), l_cwl, uint8_t(l_cwl_buffer),
             l_dram_rtt_wr[i_rank], uint8_t(l_rtt_wr_buffer), l_write_crc);

    mss::swizzle<A3, 3, 7>(l_cwl_buffer, io_inst.arr0);

    mss::swizzle<A6, 2, 7>(l_lpasr, io_inst.arr0);

    mss::swizzle<A9, 3, 7>(l_rtt_wr_buffer, io_inst.arr0);

    io_inst.arr0.writeBit<A12>(l_write_crc);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS2,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs02_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_lpasr;
    fapi2::buffer<uint8_t> l_cwl;
    fapi2::buffer<uint8_t> l_rtt_wr;

    uint8_t l_write_crc = i_inst.arr0.getBit<A12>();
    mss::swizzle<5, 3, A5>(i_inst.arr0, l_cwl);
    mss::swizzle<6, 2, A7>(i_inst.arr0, l_lpasr);
    mss::swizzle<5, 3, A11>(i_inst.arr0, l_rtt_wr);

    FAPI_INF("MR2 rank %d deocode: LPASR: 0x%x, CWL: 0x%x, RTT_WR: 0x%x, WRITE_CRC: 0x%x", i_rank,
             uint8_t(l_lpasr), uint8_t(l_cwl), uint8_t(l_rtt_wr), l_write_crc);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs03(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    //                                                         4  5  6  R
    static const uint8_t crc_wr_latency_map[8] = { 0, 0, 0, 0, 0, 1, 2, 3 };

    uint8_t l_mpr_page = 0;
    uint8_t l_geardown = 0;
    uint8_t l_pda = 0;
    uint8_t l_crc_wr_latency = 0;
    uint8_t l_temp_readout = 0;
    uint8_t l_fine_refresh;

    fapi2::buffer<uint8_t> l_mpr_mode;
    fapi2::buffer<uint8_t> l_crc_wr_latency_buffer;
    fapi2::buffer<uint8_t> l_read_format;

    FAPI_TRY( mss::eff_mpr_mode(i_target, l_mpr_mode) );
    FAPI_TRY( mss::eff_mpr_page(i_target, l_mpr_page) );
    FAPI_TRY( mss::eff_geardown_mode(i_target, l_geardown) );
    FAPI_TRY( mss::eff_per_dram_access(i_target, l_pda) );
    FAPI_TRY( mss::eff_temp_readout(i_target, l_temp_readout) );
    FAPI_TRY( mss::mrw_fine_refresh_mode(l_fine_refresh) );
    FAPI_TRY( mss::eff_crc_wr_latency(i_target, l_crc_wr_latency) );
    FAPI_TRY( mss::eff_mpr_rd_format(i_target, l_read_format) );

    l_crc_wr_latency_buffer = crc_wr_latency_map[l_crc_wr_latency];

    FAPI_INF("MR3 rank %d attributes: MPR_MODE: 0x%x, MPR_PAGE: 0x%x, GD: 0x%x, PDA: 0x%x, "
             "TEMP: 0x%x FR: 0x%x, CRC_WL: 0x%x(0x%x), RF: 0x%x", i_rank,
             uint8_t(l_mpr_mode), l_mpr_page, l_geardown, l_pda, l_temp_readout,
             uint8_t(l_fine_refresh), l_crc_wr_latency, uint8_t(l_crc_wr_latency_buffer),
             uint8_t(l_read_format));

    mss::swizzle<A0, 2, 7>(l_mpr_mode, io_inst.arr0);
    io_inst.arr0.writeBit<A2>(l_mpr_page);
    io_inst.arr0.writeBit<A3>(l_geardown);
    io_inst.arr0.writeBit<A4>(l_pda);
    io_inst.arr0.writeBit<A5>(l_temp_readout);

    mss::swizzle<A6 , 3, 7>(fapi2::buffer<uint8_t>(l_fine_refresh), io_inst.arr0);
    mss::swizzle<A9 , 2, 7>(l_crc_wr_latency_buffer, io_inst.arr0);
    mss::swizzle<A11, 2, 7>(l_read_format, io_inst.arr0);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS3,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs03_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_mpr_mode;

    fapi2::buffer<uint8_t> l_fine_refresh;
    fapi2::buffer<uint8_t> l_crc_wr_latency_buffer;
    fapi2::buffer<uint8_t> l_read_format;

    uint8_t l_mpr_page = i_inst.arr0.getBit<A2>();
    uint8_t l_geardown = i_inst.arr0.getBit<A3>();
    uint8_t l_pda = i_inst.arr0.getBit<A4>();
    uint8_t l_temp_readout = i_inst.arr0.getBit<A5>();

    mss::swizzle<6, 2, A1>(i_inst.arr0, l_mpr_mode);
    mss::swizzle<5, 3, A7>(i_inst.arr0, l_fine_refresh);
    mss::swizzle<6, 2, A10>(i_inst.arr0, l_crc_wr_latency_buffer);
    mss::swizzle<6, 2, A12>(i_inst.arr0, l_read_format);

    FAPI_INF("MR3 rank %d decode: MPR_MODE: 0x%x, MPR_PAGE: 0x%x, GD: 0x%x, PDA: 0x%x, "
             "TEMP: 0x%x FR: 0x%x, CRC_WL: 0x%x, RF: 0x%x", i_rank,
             uint8_t(l_mpr_mode), l_mpr_page, l_geardown, l_pda, uint8_t(l_temp_readout),
             uint8_t(l_fine_refresh), uint8_t(l_crc_wr_latency_buffer), uint8_t(l_read_format));

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs04(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    //                                              0             3      4      5      6         8
    static const uint8_t cs_cmd_latency_map[9] = { 0b000, 0, 0, 0b001, 0b010, 0b011, 0b100, 0, 0b101 };

    uint8_t l_max_pd_mode = 0;
    uint8_t l_temp_refresh_range = 0;
    uint8_t l_temp_ref_mode = 0;
    uint8_t l_vref_mon = 0;
    uint8_t l_cs_cmd_latency = 0;
    uint8_t l_ref_abort = 0;
    uint8_t l_rd_pre_train_mode = 0;
    uint8_t l_rd_preamble = 0;
    uint8_t l_wr_preamble = 0;
    uint8_t l_ppr = 0;

    fapi2::buffer<uint8_t> l_cs_cmd_latency_buffer;

    FAPI_TRY( mss::eff_max_powerdown_mode(i_target, l_max_pd_mode) );
    FAPI_TRY( mss::mrw_temp_refresh_range(l_temp_refresh_range) );
    FAPI_TRY( mss::eff_temp_refresh_mode(i_target, l_temp_ref_mode) );
    FAPI_TRY( mss::eff_internal_vref_monitor(i_target, l_vref_mon) );
    FAPI_TRY( mss::eff_cs_cmd_latency(i_target, l_cs_cmd_latency) );
    FAPI_TRY( mss::eff_self_ref_abort(i_target, l_ref_abort) );
    FAPI_TRY( mss::eff_rd_preamble_train(i_target, l_rd_pre_train_mode) );
    FAPI_TRY( mss::eff_rd_preamble(i_target, l_rd_preamble) );
    FAPI_TRY( mss::eff_wr_preamble(i_target, l_wr_preamble) );
    FAPI_TRY( mss::eff_dram_ppr(i_target, l_ppr) );

    l_cs_cmd_latency_buffer = cs_cmd_latency_map[l_cs_cmd_latency];

    FAPI_INF("MR4 rank %d attributes: MAX_PD: 0x%x, TEMP_REFRESH_RANGE: 0x%x, TEMP_REF_MODE: 0x%x "
             "VREF_MON: 0x%x, CSL: 0x%x(0x%x), REF_ABORT: 0x%x, RD_PTM: 0x%x, RD_PRE: 0x%x, "
             "WR_PRE: 0x%x, PPR: 0x%x", i_rank,
             l_max_pd_mode, l_temp_refresh_range, l_temp_ref_mode, l_vref_mon,
             l_cs_cmd_latency, uint8_t(l_cs_cmd_latency_buffer), l_ref_abort,
             l_rd_pre_train_mode, l_rd_preamble, l_wr_preamble, l_ppr);

    io_inst.arr0.writeBit<A1>(l_max_pd_mode);
    io_inst.arr0.writeBit<A2>(l_temp_refresh_range);
    io_inst.arr0.writeBit<A3>(l_temp_ref_mode);
    io_inst.arr0.writeBit<A4>(l_vref_mon);

    mss::swizzle<A6, 3, 7>(l_cs_cmd_latency_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A9>(l_ref_abort);
    io_inst.arr0.writeBit<A10>(l_rd_pre_train_mode);
    io_inst.arr0.writeBit<A11>(l_rd_preamble);
    io_inst.arr0.writeBit<A12>(l_wr_preamble);
    io_inst.arr0.writeBit<A13>(l_ppr);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS4,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs04_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    uint8_t l_max_pd_mode = i_inst.arr0.getBit<A1>();
    uint8_t l_temp_refresh_range = i_inst.arr0.getBit<A2>();
    uint8_t l_temp_ref_mode = i_inst.arr0.getBit<A3>();
    uint8_t l_vref_mon = i_inst.arr0.getBit<A4>();

    fapi2::buffer<uint8_t> l_cs_cmd_latency_buffer;
    mss::swizzle<5, 3, A8>(i_inst.arr0, l_cs_cmd_latency_buffer);

    uint8_t l_ref_abort = i_inst.arr0.getBit<A9>();
    uint8_t l_rd_pre_train_mode = i_inst.arr0.getBit<A10>();
    uint8_t l_rd_preamble = i_inst.arr0.getBit<A11>();
    uint8_t l_wr_preamble = i_inst.arr0.getBit<A12>();
    uint8_t l_ppr = i_inst.arr0.getBit<A13>();

    FAPI_INF("MR4 rank %d decode: MAX_PD: 0x%x, TEMP_REFRESH_RANGE: 0x%x, TEMP_REF_MODE: 0x%x "
             "VREF_MON: 0x%x, CSL: 0x%x, REF_ABORT: 0x%x, RD_PTM: 0x%x, RD_PRE: 0x%x, "
             "WR_PRE: 0x%x, PPR: 0x%x", i_rank,
             l_max_pd_mode, l_temp_refresh_range, l_temp_ref_mode, l_vref_mon,
             uint8_t(l_cs_cmd_latency_buffer), l_ref_abort,
             l_rd_pre_train_mode, l_rd_preamble, l_wr_preamble, l_ppr);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs05(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    //                                                 0                4      5      6         8
    static const uint8_t ca_parity_latency_map[9] = { 0b000, 0, 0, 0, 0b001, 0b010, 0b011, 0, 0b100 };

    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    //                                       0  RQZ/1  RQZ/2  RQZ/3  RQZ/4  RQZ/5  RQZ/6  RQZ/7
    static const uint8_t rtt_park_map[8] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    uint8_t l_ca_parity_latency = 0;
    uint8_t l_crc_error_clear = 0;
    uint8_t l_ca_parity_error_status = 0;
    uint8_t l_odt_input_buffer = 0;
    uint8_t l_rtt_park[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_ca_parity = 0;
    uint8_t l_data_mask = 0;
    uint8_t l_write_dbi = 0;
    uint8_t l_read_dbi = 0;

    uint8_t l_rtt_park_index = 0;

    fapi2::buffer<uint8_t> l_ca_parity_latency_buffer;
    fapi2::buffer<uint8_t> l_rtt_park_buffer;

    FAPI_TRY( mss::eff_ca_parity_latency(i_target, l_ca_parity_latency) );
    FAPI_TRY( mss::eff_crc_error_clear(i_target, l_crc_error_clear) );
    FAPI_TRY( mss::eff_ca_parity_error_status(i_target, l_ca_parity_error_status) );
    FAPI_TRY( mss::eff_odt_input_buff(i_target, l_odt_input_buffer) );

    FAPI_TRY( mss::eff_rtt_park(i_target, &(l_rtt_park[0])) );

    FAPI_TRY( mss::eff_ca_parity(i_target, l_ca_parity) );
    FAPI_TRY( mss::eff_data_mask(i_target, l_data_mask) );
    FAPI_TRY( mss::eff_write_dbi(i_target, l_write_dbi) );
    FAPI_TRY( mss::eff_read_dbi(i_target, l_read_dbi) );

    l_ca_parity_latency_buffer = ca_parity_latency_map[l_ca_parity_latency];

    // We have to be careful about 0
    l_rtt_park_index = (l_rtt_park[mss::index(i_rank)] == 0) ?
                       0 : fapi2::ENUM_ATTR_EFF_RTT_PARK_240OHM / l_rtt_park[mss::index(i_rank)];

    // Map from RTT_NOM array to the value in the map
    l_rtt_park_buffer = rtt_park_map[l_rtt_park_index];

    FAPI_INF("MR5 rank %d attributes: CAPL: 0x%x(0x%x), CRC_EC: 0x%x, CA_PES: 0x%x, ODT_IB: 0x%x "
             "RTT_PARK: 0x%x(0x%x), CAP: 0x%x, DM: 0x%x, WDBI: 0x%x, RDBI: 0x%x", i_rank,
             l_ca_parity_latency, uint8_t(l_ca_parity_latency_buffer), l_crc_error_clear,
             l_ca_parity_error_status, l_odt_input_buffer,
             l_rtt_park[mss::index(i_rank)], uint8_t(l_rtt_park_buffer), l_ca_parity,
             l_data_mask, l_write_dbi, l_read_dbi);

    mss::swizzle<A0, 3, 7>(l_ca_parity_latency_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A3>(l_crc_error_clear);
    io_inst.arr0.writeBit<A4>(l_ca_parity_error_status);
    io_inst.arr0.writeBit<A5>(l_odt_input_buffer);
    mss::swizzle<A6, 3, 7>(l_rtt_park_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A9>(l_ca_parity);
    io_inst.arr0.writeBit<A10>(l_data_mask);
    io_inst.arr0.writeBit<A11>(l_write_dbi);
    io_inst.arr0.writeBit<A12>(l_read_dbi);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS5,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs05_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_ca_parity_latency_buffer;
    fapi2::buffer<uint8_t> l_rtt_park_buffer;

    mss::swizzle<5, 3, A2>(i_inst.arr0, l_ca_parity_latency_buffer);
    mss::swizzle<5, 3, A8>(i_inst.arr0, l_rtt_park_buffer);

    uint8_t l_crc_error_clear = i_inst.arr0.getBit<A3>();
    uint8_t l_ca_parity_error_status = i_inst.arr0.getBit<A4>();
    uint8_t l_odt_input_buffer = i_inst.arr0.getBit<A5>();

    uint8_t l_ca_parity = i_inst.arr0.getBit<A9>();
    uint8_t l_data_mask = i_inst.arr0.getBit<A10>();
    uint8_t l_write_dbi = i_inst.arr0.getBit<A11>();
    uint8_t l_read_dbi = i_inst.arr0.getBit<A12>();

    FAPI_INF("MR5 rank %d decode: CAPL: 0x%x, CRC_EC: 0x%x, CA_PES: 0x%x, ODT_IB: 0x%x "
             "RTT_PARK: 0x%x, CAP: 0x%x, DM: 0x%x, WDBI: 0x%x, RDBI: 0x%x", i_rank,
             uint8_t(l_ca_parity_latency_buffer), l_crc_error_clear, l_ca_parity_error_status,
             l_odt_input_buffer, uint8_t(l_rtt_park_buffer), l_ca_parity, l_data_mask,
             l_write_dbi, l_read_dbi);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
static fapi2::ReturnCode ddr4_mrs06(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                                    const uint64_t i_rank)
{
    //                                          4      5     6      7       8
    static const uint8_t tccd_l_map[9] = { 0, 0, 0, 0, 0b000, 0b001, 0b010, 0b011, 0b100 };

    uint8_t l_vrefdq_train_value[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_vrefdq_train_range[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_vrefdq_train_enable[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_tccd_l = 0;

    fapi2::buffer<uint8_t> l_tccd_l_buffer;
    fapi2::buffer<uint8_t> l_vrefdq_train_value_buffer;

    FAPI_TRY( mss::eff_vref_dq_train_value(i_target, l_vrefdq_train_value) );
    FAPI_TRY( mss::eff_vref_dq_train_range(i_target, l_vrefdq_train_range) );
    FAPI_TRY( mss::eff_vref_dq_train_enable(i_target, l_vrefdq_train_enable) );
    FAPI_TRY( mss::eff_dram_tccd_l(i_target, l_tccd_l) );

    l_tccd_l_buffer = tccd_l_map[l_tccd_l];
    l_vrefdq_train_value_buffer = l_vrefdq_train_value[mss::index(i_rank)];

    FAPI_INF("MR6 rank %d attributes: TRAIN_V: 0x%x(0x%x), TRAIN_R: 0x%x, TRAIN_E: 0x%x, TCCD_L: 0x%x(0x%x)", i_rank,
             l_vrefdq_train_value[mss::index(i_rank)], uint8_t(l_vrefdq_train_value_buffer),
             l_vrefdq_train_range[mss::index(i_rank)],
             l_vrefdq_train_enable[mss::index(i_rank)], l_tccd_l, uint8_t(l_tccd_l_buffer));

    mss::swizzle<A0, 6, 7>(l_vrefdq_train_value_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A6>(l_vrefdq_train_range[mss::index(i_rank)]);
    io_inst.arr0.writeBit<A7>(l_vrefdq_train_enable[mss::index(i_rank)]);
    mss::swizzle<A10, 3, 7>(l_tccd_l_buffer, io_inst.arr0);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS6,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
static fapi2::ReturnCode ddr4_mrs06_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
        const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_tccd_l_buffer;
    fapi2::buffer<uint8_t> l_vrefdq_train_value_buffer;

    mss::swizzle<2, 6, A5>(i_inst.arr0, l_vrefdq_train_value_buffer);
    uint8_t l_vrefdq_train_range = i_inst.arr0.getBit<A6>();
    uint8_t l_vrefdq_train_enable = i_inst.arr0.getBit<A7>();
    mss::swizzle<5, 3, A12>(i_inst.arr0, l_tccd_l_buffer);

    FAPI_INF("MR6 rank %d decode: TRAIN_V: 0x%x, TRAIN_R: 0x%x, TRAIN_E: 0x%x, TCCD_L: 0x%x", i_rank,
             uint8_t(l_vrefdq_train_value_buffer), l_vrefdq_train_range,
             l_vrefdq_train_enable, uint8_t(l_tccd_l_buffer));

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Perform the mrs_load_ddr4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] i_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load_ddr4( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& i_inst)
{
    FAPI_INF("mrs_load_ddr4 %s", mss::c_str(i_target));

    // Per DDR4MRS02 table 104 - timing requirements
    static const uint64_t tMRD = 8;

    static std::vector< mrs_data<TARGET_TYPE_MCBIST> > l_mrs_data =
    {
        {  0, ddr4_mrs00, ddr4_mrs00_decode, tMRD  }, {  1, ddr4_mrs01, ddr4_mrs01_decode, tMRD  },
        {  2, ddr4_mrs02, ddr4_mrs02_decode, tMRD  }, {  3, ddr4_mrs03, ddr4_mrs03_decode, tMRD  },
        {  4, ddr4_mrs04, ddr4_mrs04_decode, tMRD  }, {  5, ddr4_mrs05, ddr4_mrs05_decode, tMRD  },
        {  6, ddr4_mrs06, ddr4_mrs06_decode, tMRD  },
    };

    std::vector< uint64_t > l_ranks;
    FAPI_TRY( mss::ranks(i_target, l_ranks) );

    for (auto d : l_mrs_data)
    {
        for (auto r : l_ranks)
        {
            // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
            ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst_a_side = ccs::mrs_command<TARGET_TYPE_MCBIST>(i_target, r, d.iv_mrs);
            ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst_b_side;

            // Thou shalt send 2 MRS, one for the a-side and the other inverted for the b-side.
            // If we're on an odd-rank then we need to mirror
            // So configure the A-side, mirror if necessary and invert for the B-side
            FAPI_TRY( d.iv_func(i_target, l_inst_a_side, r) );

            FAPI_TRY( mss::address_mirror(i_target, r, l_inst_a_side) );
            l_inst_b_side = mss::address_invert(l_inst_a_side);

            // Not sure if we can get tricky here and only delay after the b-side MR. The question is whether the delay
            // is needed/assumed by the register or is purely a DRAM mandated delay. We know we can't go wrong having
            // both delays but if we can ever confirm that we only need one we can fix this. BRS
            l_inst_a_side.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(d.iv_delay);
            l_inst_b_side.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(d.iv_delay);

            // Dump out the 'decoded' MRS and trace the CCS instructions.
            if (d.iv_dumper != NULL)
            {
                FAPI_TRY( d.iv_dumper(l_inst_a_side, r) );
            }

            FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d a-side", uint8_t(d.iv_mrs), d.iv_delay,
                     l_inst_a_side.arr0, l_inst_a_side.arr1, mss::c_str(i_target), r);
            FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d b-side", uint8_t(d.iv_mrs), d.iv_delay,
                     l_inst_b_side.arr0, l_inst_b_side.arr1, mss::c_str(i_target), r);

            // Add both to the CCS program
            i_inst.push_back(l_inst_a_side);
            i_inst.push_back(l_inst_b_side);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
