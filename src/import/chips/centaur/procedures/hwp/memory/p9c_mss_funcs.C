/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file p9c_mss_funcs.C
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <p9c_mss_funcs.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/bit_count.H>

///
/// @brief Disables all CID's
/// @param[in] i_target - the MBA target on which to operate
/// @param[in,out] io_csn - the CSN containing CID's
/// @param[in,out] io_cke - the CKE containing CID's
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_disable_cid( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                   fapi2::variable_buffer& io_csn,
                                   fapi2::variable_buffer& io_cke)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_dram_stack));

    if (l_dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
    {
        // CID 0/1 on DIMM0
        FAPI_TRY(io_csn.clearBit(2, 2));

        // CID 0/1 on DIMM1
        FAPI_TRY(io_csn.clearBit(6, 2));

        // Currently, CID2 is not needed.  If it is needed, we'll need to uncomment the below code
        // We'll also need to fake out CCS to think that it has 16Gb memory so we can use CKE3/7 independently of other signals
#if CID2_IS_NEEDED
        // CID2 hangs out in CKE1
        FAPI_TRY(io_cke.clearBit(1));

        // If we need to keep track of the CKE for both ports (8 CKE bits), hit CKE1 on port 1 as well
        if(io_cke.getBitLength() == 8)
        {
            FAPI_TRY(io_cke.clearBit(5));
        }

#endif
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_set_end_bit
/// @brief Setting the End location of the CCS array
/// @param[in] i_target, Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_instruction_number, CCS instruction number
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_set_end_bit(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    uint32_t i_instruction_number
)
{
    fapi2::variable_buffer l_cke_4(4);
    FAPI_TRY(l_cke_4.setBit(0, 4), "Error setting up buffers");
    FAPI_TRY(mss_ccs_set_end_bit( i_target,
                                  i_instruction_number,
                                  l_cke_4 ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setting the End location of the CCS array
/// @param[in] i_target - Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_instruction_number - CCS instruction number
/// @param[in] i_cke - CKE to pass into the NOP
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_set_end_bit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                       uint32_t i_instruction_number,
                                       const fapi2::variable_buffer& i_cke)
{
    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_ddr_cal_type_4(4);
    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);

    uint32_t l_port_number = 0xFFFFFFFF;

    i_instruction_number = i_instruction_number + 1;

    FAPI_DBG( "Setting End Bit on instruction (NOP): %d.", i_instruction_number);

    // Single NOP with CKE raised high and the end bit set high
    FAPI_TRY(l_csn_8.setBit(0, 8), "Error setting up buffers");
    FAPI_TRY(l_address_16.clearBit(0, 16));
    FAPI_TRY(l_num_idles_16.clearBit(0, 16));
    FAPI_TRY(l_odt_4.clearBit(0, 4), "Error setting up buffers");
    FAPI_TRY(l_csn_8.setBit(0, 8), "Error setting up buffers");
    FAPI_TRY(l_wen_1.clearBit(0), "Error setting up buffers");
    FAPI_TRY(l_casn_1.clearBit(0), "Error setting up buffers");
    FAPI_TRY(l_rasn_1.clearBit(0), "Error setting up buffers");
    FAPI_TRY(l_ccs_end_1.setBit(0), "Error setting up buffers");


    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  i_instruction_number,
                                  l_address_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  i_cke,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  l_port_number));

    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  i_instruction_number,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1));


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_address_mirror_swizzle
/// @brief swizzle the address bus and bank address bus for address mirror mode
/// @param[in] i_target, Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in, out] io_address, Address
/// @param[in, out] io_bank, Bank
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_address_mirror_swizzle(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    fapi2::variable_buffer& io_address,
    fapi2::variable_buffer& io_bank
)
{
    FAPI_DBG("Enter mss_address_mirror_swizzle\n");
    fapi2::variable_buffer l_address_post_swizzle_16(16);
    fapi2::variable_buffer l_bank_post_swizzle_3(3);
    uint16_t l_mirror_mode_ba = 0;
    uint16_t l_mirror_mode_ad  = 0;

    FAPI_INF( "ADDRESS MIRRORING ON %s", mss::c_str(i_target));

    FAPI_TRY(io_address.extract(l_mirror_mode_ad, 0, 16));
    FAPI_DBG( "PRE - MIRROR MODE ADDRESS: 0x%04X", l_mirror_mode_ad);
    FAPI_TRY(io_bank.extract(l_mirror_mode_ba, 0, 3), "mss_address_mirror_swizzle: Error setting up buffers");
    FAPI_DBG( "PRE - MIRROR MODE BANK ADDRESS: 0x%04X", l_mirror_mode_ba);

    //Initialize address and bank address as the same pre mirror mode swizzle
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 0, 16, 0));
    FAPI_TRY(l_bank_post_swizzle_3.insert(io_bank, 0, 3, 0), "mss_address_mirror_swizzle: Error setting up buffers");

    //Swap A3 and A4
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 4, 1, 3));
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 3, 1, 4));

    //Swap A5 and A6
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 6, 1, 5));
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 5, 1, 6));

    //Swap A7 and A8
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 8, 1, 7));
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 7, 1, 8));

    //Swap A11 and A13
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 13, 1, 11));
    FAPI_TRY(l_address_post_swizzle_16.insert(io_address, 11, 1, 13));

    //Swap BA0 and BA1
    FAPI_TRY(l_bank_post_swizzle_3.insert(io_bank, 1, 1, 0), "mss_address_mirror_swizzle: Error setting up buffers");
    FAPI_TRY(l_bank_post_swizzle_3.insert(io_bank, 0, 1, 1), "mss_address_mirror_swizzle: Error setting up buffers");

    //Swap BG0 and BG1 (BA2 and ADDR 15)
    FAPI_TRY(l_bank_post_swizzle_3.insert(io_address, 2, 1, 15), "mss_address_mirror_swizzle: Error setting up buffers");
    FAPI_TRY(l_address_post_swizzle_16.insert(io_bank, 15, 1, 2));

    FAPI_TRY(l_address_post_swizzle_16.extract(l_mirror_mode_ad, 0, 16));
    FAPI_DBG( "POST - MIRROR MODE ADDRESS: 0x%04X", l_mirror_mode_ad);
    FAPI_TRY(l_bank_post_swizzle_3.extract(l_mirror_mode_ba, 0, 3), "mss_address_mirror_swizzle: Error setting up buffers");
    FAPI_DBG( "POST - MIRROR MODE BANK ADDRESS: 0x%04X", l_mirror_mode_ba);

    //copy address and bank address back to the IO variables
    FAPI_TRY(io_address.insert(l_address_post_swizzle_16, 0, 16, 0));
    FAPI_TRY(io_bank.insert(l_bank_post_swizzle_3, 0, 3, 0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup address CCS field for a nominal MRS for MR1
/// @param[in] i_target mba target being calibrated
/// @param[in] i_port port being calibrated
/// @param[in] i_rank rank pair being calibrated
/// @param[out] o_address_16 CCS address field
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_nominal_mrs1_address(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint8_t i_port,
        const uint32_t i_rank,
        fapi2::variable_buffer& o_address_16)
{
    const uint8_t l_dimm = (i_rank) / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_rank - MAX_RANKS_PER_DIMM * l_dimm;
    uint8_t l_dll_enable = 0;
    uint8_t l_out_drv_imp_cntl[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_dram_rtt_nom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t l_dram_al = 0;
    uint8_t l_wr_lvl = 0;
    uint8_t l_tdqs_enable = 0;
    uint8_t l_q_off = 0;
    uint8_t l_lrdimm_rank_mult_mode = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE, i_target, l_dll_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RON, i_target, l_out_drv_imp_cntl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM, i_target, l_dram_rtt_nom));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target, l_dram_al));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE, i_target, l_wr_lvl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TDQS, i_target, l_tdqs_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER, i_target, l_q_off));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_LRDIMM_RANK_MULT_MODE, i_target, l_lrdimm_rank_mult_mode));

    if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_ENABLE)
    {
        l_dll_enable = 0x00;
    }
    else if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_DISABLE)
    {
        l_dll_enable = 0xFF;
    }

    if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_DISABLE)
    {
        l_dram_al = 0x00;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1)
    {
        l_dram_al = 0x80;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2)
    {
        l_dram_al = 0x40;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_3)
    {
        l_dram_al = 0xC0;
    }

    if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
    {
        l_wr_lvl = 0x00;
    }
    else if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
    {
        l_wr_lvl = 0xFF;
    }

    if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE)
    {
        l_tdqs_enable = 0x00;
    }
    else if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_ENABLE)
    {
        l_tdqs_enable = 0xFF;
    }

    if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
    {
        l_q_off = 0xFF;
    }
    else if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
    {
        l_q_off = 0x00;
    }

    if ( l_lrdimm_rank_mult_mode != 0 )
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0x00;
    }
    else if (l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_DISABLE)
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0x00;
    }
    else if (l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM20)
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0x20;
    }
    else if (l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM30)
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0xA0;
    }
    else if (l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM40)
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0xC0;
    }
    else if (l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM60)
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0x80;
    }
    else if (l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120)
    {
        l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank] = 0x40;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_DRAMINIT_RTT_NOM_IMP_INPUT_ERROR().
                    set_TARGET_MBA_ERROR(i_target).
                    set_IMP(l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank]).
                    set_PORT(i_port).
                    set_DIMM(l_dimm).
                    set_RANK(l_dimm_rank),
                    "mss_mrs_load: %s Error determining ATTR_VPD_DRAM_RTT_NOM value: %d from attribute",
                    mss::c_str(i_target), l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank]);
    }

    if (l_out_drv_imp_cntl[i_port][l_dimm] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM40)
    {
        l_out_drv_imp_cntl[i_port][l_dimm] = 0x00;
    }
    else if (l_out_drv_imp_cntl[i_port][l_dimm] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM34)
    {
        l_out_drv_imp_cntl[i_port][l_dimm] = 0x80;
    }

    FAPI_TRY(o_address_16.insert((uint8_t) l_dll_enable, 0, 1, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) l_out_drv_imp_cntl[i_port][l_dimm], 1, 1, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank], 2, 1, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) l_dram_al, 3, 2, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) l_out_drv_imp_cntl[i_port][l_dimm], 5, 1, 1));
    FAPI_TRY(o_address_16.insert((uint8_t) l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank], 6, 1, 1));
    FAPI_TRY(o_address_16.insert((uint8_t) l_wr_lvl, 7, 1, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) 0x00, 8, 1));
    FAPI_TRY(o_address_16.insert((uint8_t) l_dram_rtt_nom[i_port][l_dimm][l_dimm_rank], 9, 1, 2));
    FAPI_TRY(o_address_16.insert((uint8_t) 0x00, 10, 1));
    FAPI_TRY(o_address_16.insert((uint8_t) l_tdqs_enable, 11, 1, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) l_q_off, 12, 1, 0));
    FAPI_TRY(o_address_16.insert((uint8_t) 0x00, 13, 3));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_inst_arry_0
/// @brief Adding information to the CCS - 0 instruction array by index
/// @param[in] i_target, Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] io_instruction_number, Instruction Number
/// @param[in] i_address, Mem Address for CCS
/// @param[in] i_bank, Targeted Bank for CCS
/// @param[in] i_activate, Activate line for CCS
/// @param[in] i_rasn, RAS line for CCS
/// @param[in] i_casn, CAS line for CCS
/// @param[in] i_wen, WEN line for CCS
/// @param[in] i_cke, CKE line for CCS
/// @param[in] i_csn, CSN line for CCS
/// @param[in] i_odt, ODT line for CCS
/// @param[in] i_ddr_cal_type, Cal type
/// @param[in] i_port. Targeted Mem Port for CCS
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_inst_arry_0(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    uint32_t& io_instruction_number,
    const fapi2::variable_buffer i_address,
    const fapi2::variable_buffer i_bank,
    const fapi2::variable_buffer i_activate,
    const fapi2::variable_buffer i_rasn,
    const fapi2::variable_buffer i_casn,
    const fapi2::variable_buffer i_wen,
    const fapi2::variable_buffer i_cke,
    const fapi2::variable_buffer i_csn,
    const fapi2::variable_buffer i_odt,
    const fapi2::variable_buffer i_ddr_cal_type,
    uint32_t i_port
)
{
    uint32_t l_reg_address = 0;
    fapi2::variable_buffer l_data_buffer(64);
    uint64_t l_data_64;
    uint8_t l_dimm_type = 0;
    uint32_t l_num_retry = 0;
    uint32_t l_timer = 0;
    uint8_t l_cs_start = 0;
    uint8_t l_csn_dimm0 = 0;
    uint8_t l_parity_bit = 0;
    uint8_t l_parity_bit_even = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));

    if ((io_instruction_number >= 30) && (i_port != 0xFFFFFFFF))
    {
        l_num_retry = 20;
        l_timer = DELAY_100US;
        FAPI_DBG("CCS: Set end bit.\n");
        FAPI_TRY(mss_ccs_set_end_bit( i_target, 29, i_cke ));
        FAPI_TRY(mss_execute_ccs_inst_array( i_target, l_num_retry, l_timer));
        io_instruction_number = 0;
    }

    if (i_port == 0xFFFFFFFF)
    {
        i_port = 0;
    }

    FAPI_DBG("i_port: %x  io_instruction_number: %x\n", i_port, io_instruction_number);
    l_reg_address = io_instruction_number + CEN_MBA_CCS_INST_ARR0_0;

    l_data_buffer.flush<0>();

    // If we have 8 CKE bits, then we want to control the CKE's individually on each port
    // Just copy the CKE information directly
    // Why 8 CKE bits? We have a total of 8 CKE bits in each CCS register
    if(i_cke.getBitLength() == 8)
    {
        FAPI_TRY(l_data_buffer.insert(i_cke, 24, 8, 0), "insert failed");
    }
    // Otherwise, copy the CKE from one port to the other
    else
    {
        FAPI_TRY(l_data_buffer.insert(i_cke, 24, 4, 0), "insert failed");
        FAPI_TRY(l_data_buffer.insert(i_cke, 28, 4, 0), "insert failed");
    }

    if (i_port == 0)
    {
        FAPI_TRY(l_data_buffer.insert(i_csn, 32, 8, 0), "insert failed");
        FAPI_TRY(l_data_buffer.insertFromRight((uint8_t)0xFF, 40, 8), "insertFromRight Failed");
        FAPI_TRY(l_data_buffer.insert(i_odt, 48, 4, 0), "insert failed");
        FAPI_TRY(l_data_buffer.insertFromRight((uint8_t)0x00, 52, 4), "insertFromRight Failed");
    }
    else if (i_port == 1)
    {
        FAPI_TRY(l_data_buffer.insert((uint8_t)0xFF, 32, 8), "insert failed");
        FAPI_TRY(l_data_buffer.insert(i_csn, 40, 8, 0), "insert failed");
        FAPI_TRY(l_data_buffer.insertFromRight((uint8_t)0x00, 48, 4), "insert failed");
        FAPI_TRY(l_data_buffer.insert(i_odt, 52, 4, 0), "insert failed");
    }
    else if (i_port == 3)
    {
        FAPI_TRY(l_data_buffer.insert(i_csn, 32, 8, 0), "insert failed");
        FAPI_TRY(l_data_buffer.insert(i_csn, 40, 8, 0), "insert failed") ;
        FAPI_TRY(l_data_buffer.insert(i_odt, 48, 4, 0), "insert failed") ;
        FAPI_TRY(l_data_buffer.insert(i_odt, 52, 4, 0), "insert failed") ;
    }

    //Placing bits into the data buffer
    FAPI_TRY(l_data_buffer.insert( i_address, 0, 16, 0), "insert failed");
    FAPI_TRY(l_data_buffer.insert( i_bank, 17, 3, 0), "insert failed");
    FAPI_TRY(l_data_buffer.insert( i_activate, 20, 1, 0), "insert failed");
    FAPI_TRY(l_data_buffer.insert( i_rasn, 21, 1, 0), "insert failed");
    FAPI_TRY(l_data_buffer.insert( i_casn, 22, 1, 0), "insert failed");
    FAPI_TRY(l_data_buffer.insert( i_wen, 23, 1, 0), "insert failed");
    FAPI_TRY(l_data_buffer.insert( i_ddr_cal_type, 56, 4, 0), "insert failed");

    if((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
        || l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM) )
    {
        FAPI_TRY(i_csn.extractToRight(l_csn_dimm0, 0, 2));

        if (i_port == 0)
        {
            // If any DIMM0 CS bits are cleared, we're selecting DIMM0
            if (l_csn_dimm0 != 3)
            {
                l_cs_start  = 32;
            }
            // If not, we're selecting DIMM1
            else
            {
                l_cs_start  = 36;
            }
        }
        else
        {
            // If any DIMM0 CS bits are cleared, we're selecting DIMM0
            if (l_csn_dimm0 != 3)
            {
                l_cs_start  = 40;
            }
            // If not, we're selecting DIMM1
            else
            {
                l_cs_start  = 44;
            }
        }

        // CKE, CS, and ODT fields don't get counted for parity
        // CID is the exception, if we're talking to a TSV part
        l_parity_bit = l_data_buffer.getNumBitsSet(0, 16) + l_data_buffer.getNumBitsSet(17,
                       7) + l_data_buffer.getNumBitsSet(l_cs_start + 2, 2);

        l_parity_bit_even = l_parity_bit % 2;

        FAPI_TRY(l_data_buffer.insertFromRight(l_parity_bit_even, 60, 1));
    }

    FAPI_TRY(l_data_buffer.extract(l_data_64));
    FAPI_TRY(fapi2::putScom(i_target, l_reg_address, l_data_64));
    FAPI_DBG("ccs_inst_arry_0 is done");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_inst_arry_1
/// @brief Adding information to the CCS - 1 instruction array by index
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] io_instruction_number Instruction Number for CCS
/// @param[in] i_num_idles Number of Idles cycles
/// @param[in] i_num_repeat Number of repeats
/// @param[in] i_data Data
/// @param[in] i_read_compare Read Compare
/// @param[in] i_rank_cal Rank to cal
/// @param[in] i_ddr_cal_enable Cal enable
/// @param[in] i_ccs_end CCS end
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_inst_arry_1(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    uint32_t& io_instruction_number,
    const fapi2::variable_buffer i_num_idles,
    const fapi2::variable_buffer i_num_repeat,
    const fapi2::variable_buffer i_data,
    const fapi2::variable_buffer i_read_compare,
    const fapi2::variable_buffer i_rank_cal,
    const fapi2::variable_buffer i_ddr_cal_enable,
    const fapi2::variable_buffer i_ccs_end
)
{
    uint32_t l_reg_address = 0;
    fapi2::variable_buffer l_goto_inst(5);
    fapi2::variable_buffer l_data_buffer(64);
    uint64_t l_data_64 = 0;
    uint32_t l_num_retry = 0;
    uint32_t l_timer = 0;

    if ((io_instruction_number >= 30) && (i_ccs_end.isBitClear(0)))
    {
        l_num_retry = 20;
        l_timer = DELAY_100US;
        FAPI_TRY(mss_ccs_set_end_bit( i_target, 29));
        FAPI_TRY(mss_execute_ccs_inst_array( i_target, l_num_retry, l_timer));
        io_instruction_number = 0;
    }

    l_reg_address = io_instruction_number + CEN_MBA_CCS_INST_ARR1_0;


    FAPI_TRY(l_goto_inst.insertFromRight(io_instruction_number + 1, 0, 5));

    //Setting up a CCS Instruction Array Type 1
    FAPI_TRY(l_data_buffer.insert( i_num_idles, 0, 16, 0));
    FAPI_TRY(l_data_buffer.insert( i_num_repeat, 16, 16, 0));
    FAPI_TRY(l_data_buffer.insert( i_data, 32, 20, 0));
    FAPI_TRY(l_data_buffer.insert( i_read_compare, 52, 1, 0));
    FAPI_TRY(l_data_buffer.insert( i_rank_cal, 53, 4, 0));
    FAPI_TRY(l_data_buffer.insert( i_ddr_cal_enable, 57, 1, 0));
    FAPI_TRY(l_data_buffer.insert( i_ccs_end, 58, 1, 0));
    FAPI_TRY(l_data_buffer.insert( l_goto_inst, 59, 5, 0));
    FAPI_TRY(l_data_buffer.extract(l_data_64));
    FAPI_TRY(fapi2::putScom(i_target, l_reg_address, l_data_64));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_load_data_pattern
/// @brief load predefined pattern (enum) into specified array1 index
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_instruction_number Instruction Number for CCS
/// @param[in] i_mss_ccs_data_pattern Data Pattern
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_load_data_pattern(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    uint32_t i_instruction_number,
    mss_ccs_data_pattern i_data_pattern)
{
    //Example Use:
    //

    if (i_data_pattern == MSS_CCS_DATA_PATTERN_00)
    {
        FAPI_TRY(mss_ccs_load_data_pattern(i_target, i_instruction_number, 0x00000000));
    }
    else if (i_data_pattern == MSS_CCS_DATA_PATTERN_0F)
    {
        FAPI_TRY(mss_ccs_load_data_pattern(i_target, i_instruction_number, 0x00055555));
    }
    else if (i_data_pattern == MSS_CCS_DATA_PATTERN_F0)
    {
        FAPI_TRY(mss_ccs_load_data_pattern(i_target, i_instruction_number, 0x000aaaaa));
    }
    else if (i_data_pattern == MSS_CCS_DATA_PATTERN_FF)
    {
        FAPI_TRY(mss_ccs_load_data_pattern(i_target, i_instruction_number, 0x000fffff));
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @function mss_ccs_load_data_pattern
/// @brief load predefined pattern (enum) into specified array1 index
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_instruction_number Instruction Number for CCS
/// @param[in] data_pattern Data Pattern
///
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_load_data_pattern(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_instruction_number,
    const uint32_t i_data_pattern)
{
    uint32_t l_reg_address = 0;
    fapi2::buffer<uint64_t> l_data_buffer;

    FAPI_ASSERT(i_instruction_number < CCS_MAX_INSTRUCTION_NUM,
                fapi2::CEN_MSS_CCS_INDEX_OUT_OF_BOUNDS().
                set_INDEX_VALUE(i_instruction_number),
                "mss_ccs_load_data_pattern: CCS Instruction Array index out of bounds");

    l_reg_address = i_instruction_number + CEN_MBA_CCS_INST_ARR1_0;
    //read current array1 reg
    FAPI_TRY(fapi2::getScom(i_target, l_reg_address, l_data_buffer));
    //modify data bits for specified pattern
    FAPI_TRY(l_data_buffer.insertFromRight(i_data_pattern, 32, 20));
    //write array1 back out
    FAPI_TRY(fapi2::putScom(i_target, l_reg_address, l_data_buffer));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_mode
/// @brief Adding info the the Mode Register of the CCS
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_stop_on_err Stop CCS on error bit
/// @param[in] Disable UE
/// @param[in] Select Data
/// @param[in] Pclk
/// @param[in] Nclk
/// @param[in] Cal timeout
/// @param[in] ResetN
/// @param[in] Reset Recover
/// @param[in] Copy spare CKE
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const fapi2::variable_buffer i_stop_on_err,
    const fapi2::variable_buffer i_ue_disable,
    const fapi2::variable_buffer i_data_sel,
    const fapi2::variable_buffer i_pclk,
    const fapi2::variable_buffer i_nclk,
    const fapi2::variable_buffer i_cal_time_cnt,
    const fapi2::variable_buffer i_resetn,
    const fapi2::variable_buffer i_reset_recover,
    const fapi2::variable_buffer i_copy_spare_cke
)
{
    fapi2::variable_buffer l_data_buffer(64);
    uint64_t l_data_64 = 0;
    uint8_t l_dimm_type = 0;
    fapi2::buffer<uint64_t> l_scom_buff;
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_scom_buff));
    FAPI_TRY(l_data_buffer.insert(uint64_t(l_scom_buff)));
    //Setting up CCS mode
    FAPI_TRY(l_data_buffer.insert( i_stop_on_err, 0, 1, 0));
    FAPI_TRY(l_data_buffer.insert( i_ue_disable, 1, 1, 0));
    FAPI_TRY(l_data_buffer.insert( i_data_sel, 2, 2, 0));
    FAPI_TRY(l_data_buffer.insert( i_nclk, 4, 2, 0));
    FAPI_TRY(l_data_buffer.insert( i_pclk, 6, 2, 0));
    FAPI_TRY(l_data_buffer.insert( i_cal_time_cnt, 8, 16, 0));
    FAPI_TRY(l_data_buffer.insert( i_resetn, 24, 1, 0));
    FAPI_TRY(l_data_buffer.insert( i_reset_recover, 24, 1, 0));
    FAPI_TRY(l_data_buffer.insert( i_copy_spare_cke, 26, 1, 0));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));

    //if in DDR4 mode, count the parity bit and set it
    if((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
        || l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM) )
    {
        FAPI_TRY(l_data_buffer.insertFromRight( (uint8_t)0xff, 61, 1));
    }

    FAPI_TRY(l_data_buffer.extract(l_data_64));
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_64));
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @function mss_ccs_start_stop
/// @brief Issuing a start or stop of the CCS
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_start_stop Start or Stop Bit
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_start_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const bool i_start_stop
)
{
    fapi2::buffer<uint64_t> l_data_buffer;
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_CNTLQ, l_data_buffer));

    if (i_start_stop == MSS_CCS_START)
    {
        l_data_buffer.setBit<0>();
        FAPI_DBG(" Executing contents of CCS." );
    }
    else if (i_start_stop == MSS_CCS_STOP)
    {
        l_data_buffer.setBit<1>();
        FAPI_DBG(" Halting execution of the CCS." );
    }

    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_CNTLQ, l_data_buffer));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_status_query
/// @brief Querying the status of the CCS
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_status CCS Status
///
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_status_query( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        mss_ccs_status_query_result& i_status)
{
    fapi2::buffer<uint64_t> l_data_buffer;
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_STATQ, l_data_buffer));

    if (l_data_buffer.getBit<2>())
    {
        i_status = MSS_STAT_QUERY_FAIL;
    }
    else if (l_data_buffer.getBit<0>())
    {
        i_status = MSS_STAT_QUERY_IN_PROGRESS;
    }
    else if (l_data_buffer.getBit<1>())
    {
        i_status = MSS_STAT_QUERY_PASS;
    }
    else
    {
        FAPI_INF("CCS Status Undetermined.");
        fapi2::current_err = fapi2::FAPI2_RC_FALSE;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_ccs_fail_type
/// @brief Extracting the type of ccs fail
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_fail_type(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target
)
{
    fapi2::buffer<uint64_t> l_data_buffer;
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_STATQ, l_data_buffer));

    //DECONFIG and FFDC INFO
    FAPI_ASSERT(!l_data_buffer.getBit<3>(),
                fapi2::CEN_MSS_CCS_READ_MISCOMPARE().
                set_TARGET_MBA_ERROR(i_target).
                set_REG_CONTENTS(l_data_buffer),
                "CCS returned a FAIL condtion of \"Read Miscompare\" ");
    //DECONFIG and FFDC INFO
    FAPI_ASSERT(!l_data_buffer.getBit<4>(),
                fapi2::CEN_MSS_CCS_UE_SUE().
                set_TARGET_MBA_ERROR(i_target).
                set_REG_CONTENTS(l_data_buffer),
                "CCS returned a FAIL condition of \"UE or SUE Error\" ");
    //DECONFIG and FFDC INFO
    FAPI_ASSERT(!l_data_buffer.getBit<5>(),
                fapi2::CEN_MSS_CCS_CAL_TIMEOUT().
                set_TARGET_MBA_ERROR(i_target).
                set_REG_CONTENTS(l_data_buffer),
                "CCS returned a FAIL condition of \"Calibration Operation Time Out\" ");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_execute_ccs_inst_array
/// @brief Execute the CCS intruction array
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_num_poll Poll Nuber
/// @param[in] i_wait_timer Wait timer
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_execute_ccs_inst_array(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_num_poll,
    const uint32_t i_wait_timer
)
{
    enum mss_ccs_status_query_result l_status = MSS_STAT_QUERY_IN_PROGRESS;
    uint32_t l_count = 0;

    FAPI_TRY(mss_ccs_start_stop( i_target, MSS_CCS_START));

    while ((l_count < i_num_poll) && (l_status == MSS_STAT_QUERY_IN_PROGRESS))
    {
        FAPI_TRY(mss_ccs_status_query( i_target, l_status));
        l_count++;
        fapi2::delay(i_wait_timer, i_wait_timer);
    }

    FAPI_DBG("CCS Executed Polling %d times.", l_count);

    if (l_status == MSS_STAT_QUERY_FAIL)
    {
        FAPI_ERR("CCS FAILED");
        FAPI_TRY(mss_ccs_fail_type(i_target));
        FAPI_ERR("CCS has returned a fail.");
    }
    else if (l_status == MSS_STAT_QUERY_IN_PROGRESS)
    {
        FAPI_ERR("CCS Operation Hung");
        FAPI_ERR("CCS has returned a IN_PROGRESS status and considered Hung.");
        FAPI_TRY(mss_ccs_fail_type(i_target));
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_CCS_HUNG().
                    set_TARGET_MBA_ERROR(i_target),
                    "Returning a CCS HUNG RC Value.");
    }
    else if (l_status == MSS_STAT_QUERY_PASS)
    {
        FAPI_DBG("CCS Executed Successfully.");
    }
    else
    {
        FAPI_INF("CCS Status Undetermined.");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reverse 32 bit int
/// @param[in] i_x input 32b int
/// @return reversed 32b int
///
uint32_t mss_reverse_32bits(uint32_t i_x)
{
    //reversing bit order of a 32 bit uint
    i_x = (((i_x & 0xaaaaaaaa) >> 1) | ((i_x & 0x55555555) << 1));
    i_x = (((i_x & 0xcccccccc) >> 2) | ((i_x & 0x33333333) << 2));
    i_x = (((i_x & 0xf0f0f0f0) >> 4) | ((i_x & 0x0f0f0f0f) << 4));
    i_x = (((i_x & 0xff00ff00) >> 8) | ((i_x & 0x00ff00ff) << 8));
    return((i_x >> 16) | (i_x << 16));
}

/// @brief reverse 8 bit int
/// @param[in] i_x input 8b int
/// @return reversed 8b int
uint8_t mss_reverse_8bits(const uint8_t i_number)
{

    //reversing bit order of a 8 bit uint
    uint8_t l_temp = 0;

    for (uint8_t l_loop = 0; l_loop < 8; l_loop++)
    {
        uint8_t l_bit = (i_number & (1 << l_loop)) >> l_loop;
        l_temp |= l_bit << (7 - l_loop);
    }

    return l_temp;
}

///
/// @function mss_rcd_parity_check
/// @brief Checking the Parity Error Bits associated with the RCD
/// @param[in] i_target Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_port Memory Port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_rcd_parity_check(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_port
)
{
    //checks all ports for a parity error
    fapi2::buffer<uint64_t> l_data_buffer;
    uint8_t l_port_0_error = 0;
    uint8_t l_port_1_error = 0;
    uint8_t l_rcd_parity_fail = 0;
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIRQ_WOX_OR, l_data_buffer));


    FAPI_TRY(l_data_buffer.extract(l_port_0_error, 4, 1));
    FAPI_TRY(l_data_buffer.extract(l_port_1_error, 7, 1));
    FAPI_TRY(l_data_buffer.extract(l_rcd_parity_fail, 5, 1));

    FAPI_INF("Checking for RCD Parity Error.");

    //DECONFIG and FFDC INFO
    FAPI_ASSERT(!l_rcd_parity_fail,
                fapi2::CEN_MSS_RCD_PARITY_ERROR_LIMIT().
                set_TARGET_MBA_ERROR(i_target),
                "Ports 0 and 1 has exceeded a maximum number of RCD Parity Errors.");

    if (i_port == 0)
    {
        //DECONFIG and FFDC INFO
        FAPI_ASSERT(!l_port_0_error,
                    fapi2::CEN_MSS_RCD_PARITY_ERROR_PORT0().
                    set_TARGET_MBA_ERROR(i_target),
                    "Port 0 has recorded an RCD Parity Error.");
    }
    else if (i_port == 1)
    {
        //DECONFIG and FFDC INFO
        FAPI_ASSERT(!l_port_1_error,
                    fapi2::CEN_MSS_RCD_PARITY_ERROR_PORT1().
                    set_TARGET_MBA_ERROR(i_target),
                    "Port 1 has recorded an RCD Parity Error.");
    }
    else
    {
        FAPI_INF("No RCD Parity Errors on Port %d.", i_port);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @function mss_execute_zq_cal
/// @brief execute init ZQ Cal on given target and port
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Mem port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_execute_zq_cal(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint8_t i_port
)
{
    constexpr uint32_t NUM_POLL = 100;
    uint32_t l_instruction_number = 0;

    //adds a NOP before ZQ cal
    fapi2::variable_buffer l_address_buffer_16(16);
    fapi2::variable_buffer l_bank_buffer_3(3);
    fapi2::variable_buffer l_activate_buffer_1(1);
    fapi2::variable_buffer l_rasn_buffer_1(1);
    fapi2::variable_buffer l_casn_buffer_1(1);
    fapi2::variable_buffer l_wen_buffer_1(1);
    fapi2::variable_buffer l_cke_buffer_4(4);
    fapi2::variable_buffer l_csn_buffer_8(8);
    fapi2::variable_buffer l_odt_buffer_4(4);
    fapi2::variable_buffer l_num_idles_buffer_16(16);
    fapi2::variable_buffer l_test_buffer_4(4);
    fapi2::variable_buffer l_num_repeat_buffer_16(16);
    fapi2::variable_buffer l_data_buffer_20(20);
    fapi2::variable_buffer l_read_compare_buffer_1(1);
    fapi2::variable_buffer l_rank_cal_buffer_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_buffer_1(1);
    fapi2::variable_buffer l_ccs_end_buffer_1(1);
    fapi2::variable_buffer l_stop_on_err_buffer_1(1);
    fapi2::variable_buffer l_resetn_buffer_1(1);
    fapi2::variable_buffer l_data_buffer_64(64);
    uint64_t l_data_64 = 0;
    uint8_t l_current_rank = 0;
    uint8_t l_start_rank = 0;
    uint8_t l_num_master_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //num_ranks_array[port][dimm]
    uint8_t l_stack_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_dimm_type = 0;
    uint8_t l_rank_end = 0;
    fapi2::buffer<uint64_t> l_scom_buff;
    l_bank_buffer_3.flush<0>();
    l_activate_buffer_1.flush<1>();
    l_rasn_buffer_1.flush<1>(); //For NOP rasn = 1; casn = 1; wen = 1;
    l_casn_buffer_1.flush<1>();
    l_wen_buffer_1.flush<1>();
    l_cke_buffer_4.flush<1>();
    l_csn_buffer_8.flush<1>();
    l_odt_buffer_4.flush<0>();
    l_test_buffer_4.flush<0>(); // 01XX:External ZQ calibration
    FAPI_TRY(l_test_buffer_4.setBit(1));
    l_num_idles_buffer_16 = 0x0400; //1024 for ZQCal
    l_num_repeat_buffer_16.flush<0>();
    l_data_buffer_20.flush<0>();
    l_read_compare_buffer_1.flush<0>();
    l_rank_cal_buffer_4.flush<0>();
    l_ddr_cal_enable_buffer_1.flush<0>();
    l_ccs_end_buffer_1.flush<0>();

    l_stop_on_err_buffer_1.flush<0>();
    FAPI_TRY(l_resetn_buffer_1.setBit(0));
    l_data_buffer_64.flush<0>();


    FAPI_TRY(mss_ccs_inst_arry_0(i_target, l_instruction_number, l_address_buffer_16, l_bank_buffer_3, l_activate_buffer_1,
                                 l_rasn_buffer_1, l_casn_buffer_1, l_wen_buffer_1, l_cke_buffer_4, l_csn_buffer_8, l_odt_buffer_4, l_test_buffer_4,
                                 i_port));
    //Error handling for mss_ccs_inst built into mss_funcs
    FAPI_TRY(mss_ccs_inst_arry_1(i_target, l_instruction_number, l_num_idles_buffer_16, l_num_repeat_buffer_16,
                                 l_data_buffer_20,
                                 l_read_compare_buffer_1, l_rank_cal_buffer_4, l_ddr_cal_enable_buffer_1, l_ccs_end_buffer_1));
    //Error handling for mss_ccs_inst built into mss_funcs

    FAPI_TRY(mss_ccs_inst_arry_0(i_target, l_instruction_number, l_address_buffer_16, l_bank_buffer_3, l_activate_buffer_1,
                                 l_rasn_buffer_1, l_casn_buffer_1, l_wen_buffer_1, l_cke_buffer_4, l_csn_buffer_8, l_odt_buffer_4, l_test_buffer_4,
                                 i_port));
    //Error handling for mss_ccs_inst built into mss_funcs
    FAPI_TRY(mss_ccs_inst_arry_1(i_target, l_instruction_number, l_num_idles_buffer_16, l_num_repeat_buffer_16,
                                 l_data_buffer_20,
                                 l_read_compare_buffer_1, l_rank_cal_buffer_4, l_ddr_cal_enable_buffer_1, l_ccs_end_buffer_1));
    //Error handling for mss_ccs_inst built into mss_funcs

    FAPI_TRY(mss_ccs_inst_arry_0(i_target, l_instruction_number, l_address_buffer_16, l_bank_buffer_3, l_activate_buffer_1,
                                 l_rasn_buffer_1, l_casn_buffer_1, l_wen_buffer_1, l_cke_buffer_4, l_csn_buffer_8, l_odt_buffer_4, l_test_buffer_4,
                                 i_port));
    //Error handling for mss_ccs_inst built into mss_funcs
    FAPI_TRY(mss_ccs_inst_arry_1(i_target, l_instruction_number, l_num_idles_buffer_16, l_num_repeat_buffer_16,
                                 l_data_buffer_20,
                                 l_read_compare_buffer_1, l_rank_cal_buffer_4, l_ddr_cal_enable_buffer_1, l_ccs_end_buffer_1));
    //Error handling for mss_ccs_inst built into mss_funcs

    l_instruction_number = 1;

    //now sets up for ZQ CAL
    l_address_buffer_16 = 0x0020; //Set A10 bit for ZQCal Long
    l_bank_buffer_3.flush<0>();
    l_activate_buffer_1.flush<1>();
    l_rasn_buffer_1.flush<1>(); //For ZQCal rasn = 1; casn = 1; wen = 0;
    l_casn_buffer_1.flush<1>();
    l_wen_buffer_1.flush<0>();
    l_cke_buffer_4.flush<1>();
    l_odt_buffer_4.flush<0>();
    l_test_buffer_4.flush<0>(); // 01XX:External ZQ calibration
    FAPI_TRY(l_test_buffer_4.setBit(1));
    l_num_idles_buffer_16 = 0x0400; //1024 for ZQCal
    l_num_repeat_buffer_16.flush<0>();
    l_data_buffer_20.flush<0>();
    l_read_compare_buffer_1.flush<0>();
    l_rank_cal_buffer_4.flush<0>();
    l_ddr_cal_enable_buffer_1.flush<0>();
    l_ccs_end_buffer_1.flush<0>();
    l_stop_on_err_buffer_1.flush<0>();
    FAPI_TRY(l_resetn_buffer_1.setBit(0));
    l_data_buffer_64.flush<0>();


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, l_num_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_stack_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, l_num_master_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));

    //Set up CCS Mode Reg for ZQ cal long and Init cal
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_scom_buff));
    FAPI_TRY(l_data_buffer_64.insert(uint64_t(l_scom_buff)));

    FAPI_TRY(l_data_buffer_64.insert(l_stop_on_err_buffer_1, 0, 1, 0));
    FAPI_TRY(l_data_buffer_64.insert(l_resetn_buffer_1, 24, 1, 0));

    //if in DDR4 mode, count the parity bit and set it
    if(l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM || l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM )
    {
        FAPI_TRY(l_data_buffer_64.insertFromRight(0xff, 61, 1));
    }

    FAPI_TRY(l_data_buffer_64.extract(l_data_64));
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_64));


    for(uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
    {
        l_start_rank = (4 * l_dimm);

        if(l_stack_type[i_port][l_dimm] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            l_rank_end = l_num_master_ranks_array[i_port][l_dimm];

        }
        else
        {
            l_rank_end = l_num_ranks_array[i_port][l_dimm];
        }

        for(l_current_rank = l_start_rank; l_current_rank < l_start_rank + l_rank_end; l_current_rank++)
        {
            FAPI_INF( "+++++++++++++++ Sending zqcal to port: %d rank: %d +++++++++++++++", i_port, l_current_rank);
            l_csn_buffer_8.flush<1>();
            FAPI_TRY(l_csn_buffer_8.clearBit(l_current_rank));

            FAPI_TRY(mss_disable_cid(i_target, l_csn_buffer_8, l_cke_buffer_4));

            //Issue execute.
            FAPI_INF( "+++++++++++++++ Execute CCS array on port: %d +++++++++++++++", i_port);
            FAPI_TRY(mss_ccs_inst_arry_0(i_target, l_instruction_number, l_address_buffer_16, l_bank_buffer_3, l_activate_buffer_1,
                                         l_rasn_buffer_1, l_casn_buffer_1, l_wen_buffer_1, l_cke_buffer_4, l_csn_buffer_8, l_odt_buffer_4, l_test_buffer_4,
                                         i_port));
            //Error handling for mss_ccs_inst built into mss_funcs
            FAPI_TRY(mss_ccs_inst_arry_1(i_target, l_instruction_number, l_num_idles_buffer_16, l_num_repeat_buffer_16,
                                         l_data_buffer_20,
                                         l_read_compare_buffer_1, l_rank_cal_buffer_4, l_ddr_cal_enable_buffer_1, l_ccs_end_buffer_1));
            //Error handling for mss_ccs_inst built into mss_funcs
            FAPI_TRY(mss_ccs_set_end_bit(i_target, l_instruction_number));
            FAPI_TRY(mss_execute_ccs_inst_array(i_target, NUM_POLL, 60));
            l_instruction_number = 1;
            //Error handling for mss_ccs_inst built into mss_funcs
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Loading ddr3 MRS into the drams.
/// @param[in]  i_target  centaur.mba target
/// @param[in] i_port_number Port number
/// @param[in,out] io_ccs_inst_cnt ccs instance
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_mrs_load(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_port_number,
    uint32_t& io_ccs_inst_cnt)
{

    uint32_t l_dimm_number = 0;
    uint32_t l_rank_number = 0;
    uint32_t l_mrs_number = 0;

    fapi2::buffer<uint64_t> l_data_buffer_64(64);
    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_cke_4(4);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_ddr_cal_type_4(4);

    fapi2::variable_buffer l_csn_setup_8(8);

    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_idles_setup_16(16);

    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);

    fapi2::variable_buffer l_mrs0(16);
    fapi2::variable_buffer l_mrs1(16);
    fapi2::variable_buffer l_mrs2(16);
    fapi2::variable_buffer l_mrs3(16);
    uint16_t l_MRS0 = 0;
    uint16_t l_MRS1 = 0;
    uint16_t l_MRS2 = 0;
    uint16_t l_MRS3 = 0;

    uint16_t l_num_ranks = 0;
    uint8_t l_lrdimm_rank_mult_mode = 0;
    uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
    uint8_t l_dimm_type = 0;
    uint8_t l_is_sim = 0;
    uint8_t l_dram_2n_mode = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    uint8_t l_dram_bl = 0;
    uint8_t l_read_bt = 0; //Read Burst Type
    uint8_t l_dram_cl = 0;
    uint8_t l_test_mode = 0; //TEST MODE
    uint8_t l_dll_reset = 0; //DLL Reset
    uint8_t l_dram_wr = 0;
    uint8_t l_dll_precharge = 0; //DLL Control For Precharge
    uint8_t l_dll_enable = 0; //DLL Enable
    uint8_t l_mpr_loc = 0; // MPR Location
    uint8_t l_mpr_op = 0; // MPR Operation Mode
    uint8_t l_dram_rtt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t l_sr_temp = 0; // Self-Refresh Temp Range
    uint8_t l_auto_sr = 0; // Auto Self-Refresh
    uint8_t l_cwl = 0; // CAS Write Latency
    uint8_t l_pt_arr_sr = 0; //Partial Array Self Refresh
    uint8_t l_q_off = 0; //Qoff - Output buffer Enable
    uint8_t l_tdqs_enable = 0; //TDQS Enable
    uint8_t l_wr_lvl = 0; //write leveling enable
    uint8_t l_dram_al = 0;
    uint8_t l_dram_rtt_nom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t l_out_drv_imp_cntl[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};


    FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR %s PORT %d +++++++++++++++++++++", mss::c_str(i_target),
              i_port_number);
    FAPI_TRY(l_rasn_1.clearBit(0));
    FAPI_TRY(l_casn_1.clearBit(0));
    FAPI_TRY(l_wen_1.clearBit(0));
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));
    FAPI_TRY(l_csn_setup_8.setBit(0, 8));
    FAPI_TRY(l_num_idles_setup_16.insertFromRight((uint32_t) 400, 0, 16));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, l_num_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED, i_target, l_dram_2n_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_BL, i_target, l_dram_bl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_RBT, i_target, l_read_bt));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, i_target, l_dram_cl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TM, i_target, l_test_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_RESET, i_target, l_dll_reset));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR, i_target, l_dram_wr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD, i_target, l_dll_precharge));

    if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BL8)
    {
        l_dram_bl = 0x00;
    }
    else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_OTF)
    {
        l_dram_bl = 0x80;
    }
    else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BC4)
    {
        l_dram_bl = 0x40;
    }

    if (l_dram_wr == 16)
    {
        l_dram_wr = 0x00;
    }
    else if (l_dram_wr == 5)
    {
        l_dram_wr = 0x80;
    }
    else if (l_dram_wr == 6)
    {
        l_dram_wr = 0x40;
    }
    else if (l_dram_wr == 7)
    {
        l_dram_wr = 0xC0;
    }
    else if (l_dram_wr == 8)
    {
        l_dram_wr = 0x20;
    }
    else if (l_dram_wr == 10)
    {
        l_dram_wr = 0xA0;
    }
    else if (l_dram_wr == 12)
    {
        l_dram_wr = 0x60;
    }
    else if (l_dram_wr == 14)
    {
        l_dram_wr = 0xE0;
    }


    if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_SEQUENTIAL)
    {
        l_read_bt = 0x00;
    }
    else if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_INTERLEAVE)
    {
        l_read_bt = 0xFF;
    }

    if ((l_dram_cl > 4) && (l_dram_cl < 12))
    {
        l_dram_cl = (l_dram_cl - 4) << 1;
    }
    else if ((l_dram_cl > 11) && (l_dram_cl < 17))
    {
        l_dram_cl = ((l_dram_cl - 12) << 1) + 1;
    }

    l_dram_cl = mss_reverse_8bits(l_dram_cl);

    if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_NORMAL)
    {
        l_test_mode = 0x00;
    }
    else if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_TEST)
    {
        l_test_mode = 0xFF;
    }

    if (l_dll_reset == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_RESET_YES)
    {
        l_dll_reset = 0xFF;
    }
    else if (l_dll_reset == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_RESET_NO)
    {
        l_dll_reset = 0x00;
    }

    if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_SLOWEXIT)
    {
        l_dll_precharge = 0x00;
    }
    else if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_FASTEXIT)
    {
        l_dll_precharge = 0xFF;
    }

    //MRS1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE, i_target, l_dll_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RON, i_target, l_out_drv_imp_cntl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM, i_target, l_dram_rtt_nom));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target, l_dram_al));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE, i_target, l_wr_lvl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TDQS, i_target, l_tdqs_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER, i_target, l_q_off));

    if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_ENABLE)
    {
        l_dll_enable = 0x00;
    }
    else if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_DISABLE)
    {
        l_dll_enable = 0xFF;
    }

    if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_DISABLE)
    {
        l_dram_al = 0x00;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1)
    {
        l_dram_al = 0x80;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2)
    {
        l_dram_al = 0x40;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_3)
    {
        l_dram_al = 0xC0;
    }

    if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
    {
        l_wr_lvl = 0x00;
    }
    else if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
    {
        l_wr_lvl = 0xFF;
    }

    if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE)
    {
        l_tdqs_enable = 0x00;
    }
    else if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_ENABLE)
    {
        l_tdqs_enable = 0xFF;
    }

    if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
    {
        l_q_off = 0xFF;
    }
    else if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
    {
        l_q_off = 0x00;
    }

    //MRS2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_PASR, i_target, l_pt_arr_sr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, i_target, l_cwl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ASR, i_target, l_auto_sr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_SRT, i_target, l_sr_temp));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_WR, i_target, l_dram_rtt_wr));

    if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_FULL)
    {
        l_pt_arr_sr = 0x00;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_FIRST_HALF)
    {
        l_pt_arr_sr = 0x80;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_FIRST_QUARTER)
    {
        l_pt_arr_sr = 0x40;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_FIRST_EIGHTH)
    {
        l_pt_arr_sr = 0xC0;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_LAST_THREE_FOURTH)
    {
        l_pt_arr_sr = 0x20;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_LAST_HALF)
    {
        l_pt_arr_sr = 0xA0;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_LAST_QUARTER)
    {
        l_pt_arr_sr = 0x60;
    }
    else if (l_pt_arr_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_PASR_LAST_EIGHTH)
    {
        l_pt_arr_sr = 0xE0;
    }

    l_cwl = mss_reverse_8bits(l_cwl - 5);

    if (l_auto_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_ASR_SRT)
    {
        l_auto_sr = 0x00;
    }
    else if (l_auto_sr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_ASR_ASR)
    {
        l_auto_sr = 0xFF;
    }

    if (l_sr_temp == fapi2::ENUM_ATTR_CEN_EFF_DRAM_SRT_NORMAL)
    {
        l_sr_temp = 0x00;
    }
    else if (l_sr_temp == fapi2::ENUM_ATTR_CEN_EFF_DRAM_SRT_EXTEND)
    {
        l_sr_temp = 0xFF;
    }

    //MRS3
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_LOC, i_target, l_mpr_loc));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_MODE, i_target, l_mpr_op));

    l_mpr_loc = mss_reverse_8bits(l_mpr_loc);

    if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_ENABLE)
    {
        l_mpr_op = 0xFF;
    }
    else if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_DISABLE)
    {
        l_mpr_op = 0x00;
    }

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_address_16.clearBit(0, 16));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16));
    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  io_ccs_inst_cnt,
                                  l_address_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  l_cke_4,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  i_port_number));


    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  io_ccs_inst_cnt,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1));


    io_ccs_inst_cnt ++;

    // Dimm 0-1
    for ( l_dimm_number = 0; l_dimm_number < MAX_DIMM_PER_PORT; l_dimm_number++)
    {
        l_num_ranks = l_num_ranks_array[i_port_number][l_dimm_number];

        if (l_num_ranks == 0)
        {
            FAPI_INF( " %s PORT%d DIMM%d not configured. Num_ranks: %d ", mss::c_str(i_target), i_port_number, l_dimm_number,
                      l_num_ranks);
        }
        else
        {

            if (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_LRDIMM_RANK_MULT_MODE, i_target, l_lrdimm_rank_mult_mode));


                if ( (l_lrdimm_rank_mult_mode == 4) && (l_num_ranks == 8) )
                {
                    l_num_ranks = 2;
                }
            }

            // Rank 0-3
            for ( l_rank_number = 0; l_rank_number < l_num_ranks; l_rank_number++)
            {
                FAPI_INF( "MRS SETTINGS FOR %s PORT%d DIMM%d RANK%d", mss::c_str(i_target), i_port_number, l_dimm_number,
                          l_rank_number);

                l_csn_8.setBit(0, 8);
                l_address_16.clearBit(0, 16);

                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_bl, 0, 2, 0));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_cl, 2, 1, 0));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_read_bt, 3, 1, 0));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_cl, 4, 3, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_test_mode, 7, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dll_reset, 8, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_wr, 9, 3));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dll_precharge, 12, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) 0x00, 13, 3));

                FAPI_TRY(l_mrs0.extract(l_MRS0, 0, 16));

                if ( l_lrdimm_rank_mult_mode != 0 )
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_DISABLE)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM20)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x20;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM30)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0xA0;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM40)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0xC0;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM60)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x80;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x40;
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_DRAMINIT_RTT_NOM_IMP_INPUT_ERROR().
                                set_TARGET_MBA_ERROR(i_target).
                                set_IMP(l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number]).
                                set_PORT(i_port_number).
                                set_DIMM(l_dimm_number).
                                set_RANK(l_rank_number),
                                "mss_mrs_load: %s Error determining ATTR_VPD_DRAM_RTT_NOM value: %d from attribute",
                                mss::c_str(i_target), l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number]);
                }

                if (l_out_drv_imp_cntl[i_port_number][l_dimm_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM40)
                {
                    l_out_drv_imp_cntl[i_port_number][l_dimm_number] = 0x00;
                }
                else if (l_out_drv_imp_cntl[i_port_number][l_dimm_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM34)
                {
                    l_out_drv_imp_cntl[i_port_number][l_dimm_number] = 0x80;
                }

                FAPI_TRY(l_mrs1.insert((uint8_t) l_dll_enable, 0, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_out_drv_imp_cntl[i_port_number][l_dimm_number], 1, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number], 2, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dram_al, 3, 2, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_out_drv_imp_cntl[i_port_number][l_dimm_number], 5, 1, 1));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number], 6, 1, 1));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_wr_lvl, 7, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) 0x00, 8, 1));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number], 9, 1, 2));
                FAPI_TRY(l_mrs1.insert((uint8_t) 0x00, 10, 1));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_tdqs_enable, 11, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_q_off, 12, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) 0x00, 13, 3));

                FAPI_TRY(l_mrs1.extract(l_MRS1, 0, 16));

                if ( (l_lrdimm_rank_mult_mode != 0) && (l_rank_number > 1) )
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = l_dram_rtt_wr[i_port_number][l_dimm_number][0];
                }
                else if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_DISABLE)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }
                else if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM60)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0x80;
                }
                else if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM120)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0x40;
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_DRAMINIT_RTT_WR_IMP_INPUT_ERROR().
                                set_TARGET_MBA_ERROR(i_target).
                                set_IMP(l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number]).
                                set_PORT(i_port_number).
                                set_DIMM(l_dimm_number).
                                set_RANK(l_rank_number),
                                "mss_mrs_load: %s Error determining ATTR_VPD_DRAM_RTT_WR value: %d from attribute",
                                mss::c_str(i_target), l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number]);
                }

                FAPI_TRY(l_mrs2.insert((uint8_t) l_pt_arr_sr, 0, 3));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_cwl, 3, 3));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_auto_sr, 6, 1));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_sr_temp, 7, 1));
                FAPI_TRY(l_mrs2.insert((uint8_t) 0x00, 8, 1));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number], 9, 2));
                FAPI_TRY(l_mrs2.insert((uint8_t) 0x00, 11, 5));

                FAPI_TRY(l_mrs2.extract(l_MRS2, 0, 16));

                FAPI_TRY(l_mrs3.insert((uint8_t) l_mpr_loc, 0, 2));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_mpr_op, 2, 1));
                FAPI_TRY(l_mrs3.insert((uint16_t) 0x0000, 3, 13));

                FAPI_TRY(l_mrs3.extract(l_MRS3, 0, 16));
                FAPI_INF( "MRS 0: 0x%04X", l_MRS0);
                FAPI_INF( "l_MRS 1: 0x%04X", l_MRS1);
                FAPI_INF( "l_MRS 2: 0x%04X", l_MRS2);
                FAPI_INF( "l_MRS 3: 0x%04X", l_MRS3);

                // Only corresponding CS to rank
                FAPI_TRY(l_csn_8.setBit(0, 8));
                FAPI_TRY(l_csn_8.clearBit(l_rank_number + 4 * l_dimm_number));

                // Propogate through the 4 MRS cmds
                for ( l_mrs_number = 0; l_mrs_number < 4; l_mrs_number++)
                {

                    // Copying the current MRS into address buffer matching the MRS_array order
                    // Setting the bank address
                    if (l_mrs_number == 0)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs2, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 1)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs3, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 2)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs1, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 3)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs0, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5));
                    }

                    if (( l_address_mirror_map[i_port_number][l_dimm_number] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                    {
                        FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3));

                    }


                    if (l_dram_2n_mode  == fapi2::ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_TRUE)
                    {

                        // Send out to the CCS array a "setup" cycle
                        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                      io_ccs_inst_cnt,
                                                      l_address_16,
                                                      l_bank_3,
                                                      l_activate_1,
                                                      l_rasn_1,
                                                      l_casn_1,
                                                      l_wen_1,
                                                      l_cke_4,
                                                      l_csn_setup_8,
                                                      l_odt_4,
                                                      l_ddr_cal_type_4,
                                                      i_port_number));


                        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                      io_ccs_inst_cnt,
                                                      l_num_idles_setup_16,
                                                      l_num_repeat_16,
                                                      l_data_20,
                                                      l_read_compare_1,
                                                      l_rank_cal_4,
                                                      l_ddr_cal_enable_1,
                                                      l_ccs_end_1));


                        io_ccs_inst_cnt ++;

                    }

                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                  io_ccs_inst_cnt,
                                                  l_address_16,
                                                  l_bank_3,
                                                  l_activate_1,
                                                  l_rasn_1,
                                                  l_casn_1,
                                                  l_wen_1,
                                                  l_cke_4,
                                                  l_csn_8,
                                                  l_odt_4,
                                                  l_ddr_cal_type_4,
                                                  i_port_number));


                    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                  io_ccs_inst_cnt,
                                                  l_num_idles_16,
                                                  l_num_repeat_16,
                                                  l_data_20,
                                                  l_read_compare_1,
                                                  l_rank_cal_4,
                                                  l_ddr_cal_enable_1,
                                                  l_ccs_end_1));


                    io_ccs_inst_cnt ++;
                } // end mrs loop
            } // end rank loop
        } // end if has ranks
    } // end dimm loop

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Loading ddr3 RCD into the drams.
/// @param[in]  i_target centaur.mba target
/// @param[in] i_port_number Port number
/// @param[in,out] io_ccs_inst_cnt ccs instance
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_rcd_load(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                               const uint32_t i_port_number,
                               uint32_t& io_ccs_inst_cnt)
{
    uint32_t l_dimm_number = 0;
    uint32_t l_rcd_number = 0;
    fapi2::buffer<uint8_t> l_rcd_cntl_wrd_4;
    fapi2::buffer<uint64_t> l_rcd_cntl_wrd_64;
    uint16_t l_num_ranks = 0;

    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_cke_4(4);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_ddr_cal_type_4(4);

    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);

    uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
    uint64_t l_rcd_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
    uint8_t l_dimm_type = 0;
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_rasn_1.setBit(0));
    FAPI_TRY(l_casn_1.setBit(0));
    FAPI_TRY(l_wen_1.setBit(0));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, l_num_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RCD_CNTL_WORD_0_15, i_target, l_rcd_array));

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    FAPI_TRY(l_address_16.clearBit(0, 16));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16));
    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  io_ccs_inst_cnt,
                                  l_address_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  l_cke_4,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  i_port_number));

    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  io_ccs_inst_cnt,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1));

    io_ccs_inst_cnt++;

    FAPI_INF( "+++++++++++++++++++++ LOADING RCD CONTROL WORDS FOR %s PORT %d +++++++++++++++++++++",
              mss::c_str(i_target), i_port_number);

    for ( l_dimm_number = 0; l_dimm_number < MAX_DIMM_PER_PORT; l_dimm_number++)
    {
        l_num_ranks = l_num_ranks_array[i_port_number][l_dimm_number];

        if (l_num_ranks == 0)
        {
            FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d", i_port_number, l_dimm_number, l_num_ranks);
        }
        else
        {
            FAPI_INF( "RCD SETTINGS FOR %s PORT%d DIMM%d ", mss::c_str(i_target), i_port_number, l_dimm_number);
            FAPI_INF( "RCD Control Word: 0x%016llX", l_rcd_array[i_port_number][l_dimm_number]);

            // ALL active CS lines at a time.
            FAPI_TRY(l_csn_8.setBit(0, 8));

            if (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM)
            {
                // for dimm0 use CS0,1 (active low); for dimm1 use CS4,5 (active low)
                FAPI_TRY(l_csn_8.clearBit((4 * l_dimm_number), 2 ));
            }
            else if ((l_num_ranks == 1) || (l_num_ranks == 2))
            {
                FAPI_TRY(l_csn_8.clearBit(0 + 4 * l_dimm_number));
                FAPI_TRY(l_csn_8.clearBit(1 + 4 * l_dimm_number));
            }
            else if (l_num_ranks == 4)
            {
                FAPI_TRY(l_csn_8.clearBit(0 + 4 * l_dimm_number));
                FAPI_TRY(l_csn_8.clearBit(1 + 4 * l_dimm_number));
                FAPI_TRY(l_csn_8.clearBit(2 + 4 * l_dimm_number));
                FAPI_TRY(l_csn_8.clearBit(3 + 4 * l_dimm_number));
            }

            // Propogate through the 16, 4-bit control words
            for ( l_rcd_number = 0; l_rcd_number <= 15; l_rcd_number++)
            {
                FAPI_TRY(l_bank_3.clearBit(0, 3));
                FAPI_TRY(l_address_16.clearBit(0, 16));

                FAPI_TRY(l_rcd_cntl_wrd_64.insert(l_rcd_array[i_port_number][l_dimm_number], 0, 64, 0));
                FAPI_TRY(l_rcd_cntl_wrd_64.extract(l_rcd_cntl_wrd_4, 4 * l_rcd_number, 4));

                //control word number code bits A0, A1, A2, BA2
                FAPI_TRY(l_address_16.insert(l_rcd_number, 2, 1, 29));
                FAPI_TRY(l_address_16.insert(l_rcd_number, 1, 1, 30));
                FAPI_TRY(l_address_16.insert(l_rcd_number, 0, 1, 31));
                FAPI_TRY(l_bank_3.insert(l_rcd_number, 2, 1, 28));

                //control word values RCD0 = A3, RCD1 = A4, RCD2 = BA0, RCD3 = BA1
                FAPI_TRY(l_address_16.insert(uint8_t(l_rcd_cntl_wrd_4), 3, 1, 3));
                FAPI_TRY(l_address_16.insert(uint8_t(l_rcd_cntl_wrd_4), 4, 1, 2));
                FAPI_TRY(l_bank_3.insert(uint8_t(l_rcd_cntl_wrd_4), 0, 1, 1));
                FAPI_TRY(l_bank_3.insert(uint8_t(l_rcd_cntl_wrd_4), 1, 1, 0));

                // Send out to the CCS array
                if ( l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM && (l_rcd_number == 2 || l_rcd_number == 10) )
                {
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 4000, 0 , 16)); // wait tStab for clock timing rcd words
                }
                else
                {
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 12, 0, 16));
                }


                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              l_address_16,
                                              l_bank_3,
                                              l_activate_1,
                                              l_rasn_1,
                                              l_casn_1,
                                              l_wen_1,
                                              l_cke_4,
                                              l_csn_8,
                                              l_odt_4,
                                              l_ddr_cal_type_4,
                                              i_port_number));


                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              l_num_idles_16,
                                              l_num_repeat_16,
                                              l_data_20,
                                              l_read_compare_1,
                                              l_rank_cal_4,
                                              l_ddr_cal_enable_1,
                                              l_ccs_end_1));


                io_ccs_inst_cnt ++;

            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Print MRS Shadow Regs to STDOUT (FAPI_INF)
/// @param[in] i_target  centaur.mba target
/// @param[in] i_port Centaur port
/// @param[in] i_rank_pair_group Centaur RP
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode print_shadow_reg(fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target, const uint32_t i_port,
                                   const uint8_t i_rank_pair_group)
{
    uint64_t l_reg_addr[MAX_PORTS_PER_MBA][4][2][NUM_RANK_GROUPS]; //1st is port 2nd is mode reg 3rd is primary vs secondary 4th is rp
    fapi2::buffer<uint64_t> l_data_buffer_64;
    uint16_t l_mrs = 0;
    uint8_t l_dram_gen = 0;
    FAPI_INF("i_target: %s  port %x  rank_pair_group %x", mss::c_str(i_target), i_port, i_rank_pair_group);
    //creates the list of all of the mode registers
    //1st is port 2nd is mode reg 3rd is primary vs secondary 4th is rp
    l_reg_addr[0][0][0][0] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP0_P0;
    l_reg_addr[0][1][0][0] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP0_P0;
    l_reg_addr[0][2][0][0] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP0_P0;
    l_reg_addr[0][3][0][0] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP0_P0;
    l_reg_addr[0][0][0][1] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP1_P0;
    l_reg_addr[0][1][0][1] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP1_P0;
    l_reg_addr[0][2][0][1] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP1_P0;
    l_reg_addr[0][3][0][1] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP1_P0;
    l_reg_addr[0][0][0][2] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP2_P0;
    l_reg_addr[0][1][0][2] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP2_P0;
    l_reg_addr[0][2][0][2] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP2_P0;
    l_reg_addr[0][3][0][2] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP2_P0;
    l_reg_addr[0][0][0][3] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP3_P0;
    l_reg_addr[0][1][0][3] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP3_P0;
    l_reg_addr[0][2][0][3] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP3_P0;
    l_reg_addr[0][3][0][3] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP3_P0;

    l_reg_addr[0][0][1][0] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP0_P0;
    l_reg_addr[0][1][1][0] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP0_P0;
    l_reg_addr[0][2][1][0] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP0_P0;
    l_reg_addr[0][3][1][0] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP0_P0;
    l_reg_addr[0][0][1][1] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP1_P0;
    l_reg_addr[0][1][1][1] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP1_P0;
    l_reg_addr[0][2][1][1] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP1_P0;
    l_reg_addr[0][3][1][1] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP1_P0;
    l_reg_addr[0][0][1][2] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP2_P0;
    l_reg_addr[0][1][1][2] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP2_P0;
    l_reg_addr[0][2][1][2] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP2_P0;
    l_reg_addr[0][3][1][2] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP2_P0;
    l_reg_addr[0][0][1][3] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP3_P0;
    l_reg_addr[0][1][1][3] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP3_P0;
    l_reg_addr[0][2][1][3] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP3_P0;
    l_reg_addr[0][3][1][3] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP3_P0;

    l_reg_addr[1][0][0][0] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP0_P1;
    l_reg_addr[1][1][0][0] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP0_P1;
    l_reg_addr[1][2][0][0] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP0_P1;
    l_reg_addr[1][3][0][0] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP0_P1;
    l_reg_addr[1][0][0][1] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP1_P1;
    l_reg_addr[1][1][0][1] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP1_P1;
    l_reg_addr[1][2][0][1] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP1_P1;
    l_reg_addr[1][3][0][1] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP1_P1;
    l_reg_addr[1][0][0][2] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP2_P1;
    l_reg_addr[1][1][0][2] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP2_P1;
    l_reg_addr[1][2][0][2] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP2_P1;
    l_reg_addr[1][3][0][2] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP2_P1;
    l_reg_addr[1][0][0][3] = CEN_MBA_DDRPHY_PC_MR0_PRI_RP3_P1;
    l_reg_addr[1][1][0][3] = CEN_MBA_DDRPHY_PC_MR1_PRI_RP3_P1;
    l_reg_addr[1][2][0][3] = CEN_MBA_DDRPHY_PC_MR2_PRI_RP3_P1;
    l_reg_addr[1][3][0][3] = CEN_MBA_DDRPHY_PC_MR3_PRI_RP3_P1;


    l_reg_addr[1][0][1][0] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP0_P1;
    l_reg_addr[1][1][1][0] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP0_P1;
    l_reg_addr[1][2][1][0] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP0_P1;
    l_reg_addr[1][3][1][0] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP0_P1;
    l_reg_addr[1][0][1][1] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP1_P1;
    l_reg_addr[1][1][1][1] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP1_P1;
    l_reg_addr[1][2][1][1] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP1_P1;
    l_reg_addr[1][3][1][1] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP1_P1;
    l_reg_addr[1][0][1][2] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP2_P1;
    l_reg_addr[1][1][1][2] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP2_P1;
    l_reg_addr[1][2][1][2] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP2_P1;
    l_reg_addr[1][3][1][2] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP2_P1;
    l_reg_addr[1][0][1][3] = CEN_MBA_DDRPHY_PC_MR0_SEC_RP3_P1;
    l_reg_addr[1][1][1][3] = CEN_MBA_DDRPHY_PC_MR1_SEC_RP3_P1;
    l_reg_addr[1][2][1][3] = CEN_MBA_DDRPHY_PC_MR2_SEC_RP3_P1;
    l_reg_addr[1][3][1][3] = CEN_MBA_DDRPHY_PC_MR3_SEC_RP3_P1;

    FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][0][0][i_rank_pair_group], l_data_buffer_64));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target,  l_dram_gen));
    l_data_buffer_64.reverse();
    FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
    FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 0 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
              l_mrs );

    FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][1][0][i_rank_pair_group], l_data_buffer_64));
    l_data_buffer_64.reverse();
    FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
    FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 1 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
              l_mrs );

    FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][2][0][i_rank_pair_group], l_data_buffer_64));
    l_data_buffer_64.reverse();
    FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
    FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 2 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
              l_mrs );

    FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][3][0][i_rank_pair_group], l_data_buffer_64));
    l_data_buffer_64.reverse();
    FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
    FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 3 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
              l_mrs );

    if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][0][1][i_rank_pair_group], l_data_buffer_64));
        l_data_buffer_64.reverse();
        FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
        FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 4 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
                  l_mrs );

        FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][1][1][i_rank_pair_group], l_data_buffer_64));
        l_data_buffer_64.reverse();
        FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
        FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 5 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
                  l_mrs );

        FAPI_TRY(fapi2::getScom(i_target, l_reg_addr[i_port][2][1][i_rank_pair_group], l_data_buffer_64));
        l_data_buffer_64.reverse();
        FAPI_TRY(l_data_buffer_64.extract(l_mrs, 0, 16));
        FAPI_INF( "%s PORT %d SHADOW REGISTER MRS 6 RP %d VALUE: 0x%04X", mss::c_str(i_target), i_port, i_rank_pair_group,
                  l_mrs );
    }

fapi_try_exit:
    return fapi2::current_err;
}



///
/// @brief Assert ResetN, drive mem clocks
/// @param[in]  i_target  Reference to centaur.mba target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_assert_resetn_drive_mem_clks(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    // mcbist_ddr_resetn = 1 -- to deassert DDR RESET#
    //mcbist_ddr_dphy_nclk = 01, mcbist_ddr_dphy_pclk = 10 -- to drive the memory clks
    fapi2::variable_buffer l_stop_on_err_1(1);
    fapi2::variable_buffer l_ue_disable_1(1);
    fapi2::variable_buffer l_data_sel_2(2);
    fapi2::variable_buffer l_pclk_2(2);
    fapi2::variable_buffer l_nclk_2(2);
    fapi2::variable_buffer l_cal_time_cnt_16(16);
    fapi2::variable_buffer l_resetn_1(1);
    fapi2::variable_buffer l_reset_recover_1(1);
    fapi2::variable_buffer l_copy_spare_cke_1(1);
    FAPI_TRY(l_pclk_2.insertFromRight((uint32_t) 2, 0, 2));
    FAPI_TRY(l_nclk_2.insertFromRight((uint32_t) 1, 0, 2));
    FAPI_TRY(l_resetn_1.setBit(0));
    FAPI_TRY(l_copy_spare_cke_1.setBit(0)); // mdb : clk enable on for spare

    FAPI_INF( "+++++++++++++++++++++ ASSERTING RESETN, DRIVING MEM CLKS +++++++++++++++++++++");

    // Setting CCS Mode
    FAPI_TRY(mss_ccs_mode(i_target,
                          l_stop_on_err_1,
                          l_ue_disable_1,
                          l_data_sel_2,
                          l_pclk_2,
                          l_nclk_2,
                          l_cal_time_cnt_16,
                          l_resetn_1,
                          l_reset_recover_1,
                          l_copy_spare_cke_1));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Assert ResetN signal
/// @param[in]  i_target  Reference to centaur.mba target
/// @param[in]  i_value   Value to set resetN (value of 1 deasserts reset)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_assert_resetn (
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint8_t i_value)
{
    fapi2::buffer<uint64_t> l_data_buffer;
    FAPI_INF( "+++++++++++++++++++++ ASSERTING RESETN to the value of %d +++++++++++++++++++++", i_value);
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer));
    //Setting up CCS mode
    FAPI_TRY(l_data_buffer.insert( i_value, 24, 1, 7)); // use bit 7
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set non calibrating ranks to wr lvl mode on and qoff disabled during wr lvling
/// @param[in] i_target mba target being calibrated
/// @param[in] i_port port being calibrated
/// @param[in] i_rank rank pair group being calibrated
/// @param[in] i_state 1 turn on (configure) or 0 turn off (cleanup)
/// @param[in,out] io_ccs_inst_cnt CCS instruction Number
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_wr_lvl_mrs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                   const uint8_t i_port,
                                   const uint32_t i_rank,
                                   const uint8_t i_state,
                                   uint32_t& io_ccs_inst_cnt)
{
    fapi2::variable_buffer l_data_buffer_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_cke_4(4);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_ddr_cal_type_4(4);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
    const uint8_t l_dimm = (i_rank) / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_rank - MAX_RANKS_PER_DIMM * l_dimm;
    access_address l_addr = {0, 0, 0, 0, 0};
    uint32_t l_delay = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    l_delay = 400;
    FAPI_TRY(add_nop_to_ccs(i_target, l_addr, l_delay, io_ccs_inst_cnt));

    // Load nominal MRS values for the MR1, which contains RTT_NOM
    FAPI_INF("Sending MRS to rank %d on %s", i_rank, mss::c_str(i_target));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 12, 0, 16));
    FAPI_TRY(l_activate_1.setBit(0));
    FAPI_TRY(l_rasn_1.clearBit(0));
    FAPI_TRY(l_casn_1.clearBit(0));
    FAPI_TRY(l_wen_1.clearBit(0));
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.clearBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));

    FAPI_TRY(mss_nominal_mrs1_address(i_target, i_port, i_rank, l_data_buffer_16));

    // Insert on or off to wr lvl enable and qoff
    FAPI_TRY(l_data_buffer_16.insert(i_state, 7, 1, 0));
    FAPI_TRY(l_data_buffer_16.insert(i_state, 12, 1, 0));

    // Only corresponding CS to rank
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_csn_8.clearBit(i_rank));

    FAPI_TRY(mss_disable_cid(i_target, l_csn_8, l_cke_4));

    FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
    FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
    FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));

    // Do the mirror swizzle if needed
    if (( l_address_mirror_map[i_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_INF("Doing address_mirroring_swizzle for %d %d %d %02x", i_port, l_dimm, l_dimm_rank,
                 l_address_mirror_map[i_port][l_dimm] );
        FAPI_TRY(mss_address_mirror_swizzle(i_target, l_data_buffer_16, l_bank_3), "mss_address_mirror_swizzle failed on %s",
                 mss::c_str(i_target));

    }
    else
    {
        FAPI_INF("No swizzle for address_mirroring_swizzle necessary for %d %d %d 0x%02x", i_port, l_dimm, l_dimm_rank,
                 l_address_mirror_map[i_port][l_dimm] );
    }

    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  io_ccs_inst_cnt,
                                  l_data_buffer_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  l_cke_4,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  i_port), "ccs_inst_arry_0 failed on %s", mss::c_str(i_target));

    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  io_ccs_inst_cnt,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1), "ccs_inst_arry_0 failed on %s", mss::c_str(i_target));
    io_ccs_inst_cnt++;

    // Set a NOP as the last command
    l_addr.port = i_port;
    l_delay = 12;
    FAPI_TRY(add_nop_to_ccs(i_target, l_addr, l_delay, io_ccs_inst_cnt));

    // Setup end bit for CCS
    FAPI_TRY(mss_ccs_set_end_bit(i_target, io_ccs_inst_cnt - 1), "mss_ccs_set_end_bit failed on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add a NOP command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_nop_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const access_address i_addr,
                                 const uint32_t i_delay,
                                 uint32_t& io_instruction_number)
{
    uint8_t l_is_sim = 0;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);
    uint32_t l_port = i_addr.port;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));

    // CCS Array 0 Setup

    // Command structure setup
    addr_16.flush<0>();
    bank_3.flush<0>();
    cke_4.flush<1>();
    csn_8.flush<1>();
    FAPI_TRY(rasn_1.setBit(0));
    FAPI_TRY(casn_1.setBit(0));
    FAPI_TRY(wen_1.setBit(0));

    FAPI_TRY(read_compare_1.clearBit(0));

    // Final setup
    odt_4.flush<0>();
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add an MRS command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for MRS
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert MRS command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_mrs_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const access_address i_addr,
                                 const uint32_t i_delay,
                                 uint32_t& io_instruction_number)
{
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    uint8_t l_stack_type_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    const uint8_t l_dimm = i_addr.mrank / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_addr.mrank - MAX_RANKS_PER_DIMM * l_dimm;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;
    uint32_t l_port = i_addr.port;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target_mba, l_address_mirror_map));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  l_stack_type_u8array));

    // CCS Array 0 Setup

    // Buffer conversions from inputs
    FAPI_TRY(addr_16.insertFromRight(i_addr.row_addr, 0, 16));
    FAPI_TRY(addr_16.extract(l_data_16));
    l_data_16.reverse();
    FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
    FAPI_TRY(bank_3.insertFromRight(i_addr.bank, 0, 3));
    FAPI_TRY(bank_3.extract(l_data_8, 0, 3));
    l_data_8.reverse();
    FAPI_TRY(bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));
    FAPI_INF("%s add_MRS_to_ccs ADDR : 0x%04X  MR : 0x%X", mss::c_str(i_target_mba), i_addr.row_addr, i_addr.bank);

    FAPI_TRY(cs_decode(i_target_mba, i_addr, l_stack_type_u8array[0][0], csn_8));

    // Command structure setup
    cke_4.flush<1>();
    FAPI_TRY(rasn_1.clearBit(0));
    FAPI_TRY(casn_1.clearBit(0));
    FAPI_TRY(wen_1.clearBit(0));

    FAPI_TRY(read_compare_1.clearBit(0));

    // Final setup
    odt_4.flush<0>();
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    if ((l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, addr_16, bank_3));
    }

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add an ACT command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_activate_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const access_address i_addr,
                                      const uint32_t i_delay,
                                      uint32_t& io_instruction_number)
{
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    uint8_t l_stack_type_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    const uint8_t l_dimm = i_addr.mrank / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_addr.mrank - MAX_RANKS_PER_DIMM * l_dimm;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);

    uint8_t l_dram_type;
    uint32_t l_port = i_addr.port;
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target_mba, l_address_mirror_map));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba, l_dram_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  l_stack_type_u8array));

    // CCS Array 0 Setup

    // Buffer conversions from inputs
    FAPI_TRY(bank_3.insertFromRight(i_addr.bank, 0, 3));
    FAPI_TRY(bank_3.extract(l_data_8, 0, 3));
    l_data_8.reverse();
    FAPI_TRY(bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));
    csn_8.flush<1>();
    cke_4.flush<1>();

    FAPI_TRY(cs_decode(i_target_mba, i_addr, l_stack_type_u8array[0][0], csn_8));

    // Command structure setup
    // executes DDR4 commands if neccessary, otherwise executes DDR3 commands
    if(l_dram_type == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
    {
        FAPI_TRY(ddr4_activate_1.clearBit(0));

        FAPI_TRY(wen_1.insert(i_addr.row_addr, 0 , 1 , 17));
        FAPI_TRY(casn_1.insert(i_addr.row_addr, 0 , 1 , 16));
        FAPI_TRY(rasn_1.insert(i_addr.row_addr, 0 , 1 , 15));

        FAPI_TRY(addr_16.insertFromRight(i_addr.row_addr, 0, 16));
        FAPI_TRY(addr_16.extract(l_data_16));
        l_data_16.reverse();
        FAPI_TRY(addr_16.insert((uint16_t)l_data_16));

        FAPI_TRY(addr_16.insert(i_addr.row_addr, 14 , 1 , 14));
        FAPI_TRY(addr_16.insert(i_addr.bank, 15 , 1 , 4));
    }
    else
    {
        FAPI_TRY(rasn_1.clearBit(0));
        FAPI_TRY(casn_1.setBit(0));
        FAPI_TRY(ddr4_activate_1.setBit(0));
        FAPI_TRY(addr_16.insertFromRight(i_addr.row_addr, 0, 16));
        FAPI_TRY(addr_16.extract(l_data_16));
        l_data_16.reverse();
        FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
    }

    // Final setup
    odt_4.flush<0>();
    cal_type_4.flush<0>();

    if ((l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, addr_16, bank_3));
    }

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add a WR command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_write_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const access_address i_addr,
                                   const uint32_t i_delay,
                                   uint32_t& io_instruction_number)
{
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    uint8_t l_stack_type_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    const uint8_t l_dimm = i_addr.mrank / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_addr.mrank - MAX_RANKS_PER_DIMM * l_dimm;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);

    uint8_t l_dram_type;
    uint8_t l_odt[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint32_t l_port = i_addr.port;
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target_mba, l_address_mirror_map));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba, l_dram_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, i_target_mba,  l_odt));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  l_stack_type_u8array));

    // Buffer conversions from inputs
    FAPI_TRY(bank_3.insertFromRight(i_addr.bank, 0, 3));
    FAPI_TRY(bank_3.extract(l_data_8, 0, 3));
    l_data_8.reverse();
    FAPI_TRY(bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));

    FAPI_TRY(cs_decode(i_target_mba, i_addr, l_stack_type_u8array[0][0], csn_8));

    // Command structure setup
    cke_4.flush<1>();
    FAPI_TRY(rasn_1.setBit(0));
    FAPI_TRY(casn_1.clearBit(0));
    FAPI_TRY(wen_1.clearBit(0));

    // Final setup
    FAPI_TRY(odt_4.insert(l_odt[l_port][l_dimm][l_dimm_rank], 0, 4));
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    if(l_dram_type == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
    {
        FAPI_TRY(addr_16.insertFromRight(i_addr.col_addr, 0, 16));
        FAPI_TRY(addr_16.extract(l_data_16));
        l_data_16.reverse();
        FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
        FAPI_TRY(addr_16.setBit(12)); // burst length 8

        FAPI_TRY(addr_16.insert(i_addr.bank, 15 , 1 , 4));

    }
    else
    {
        FAPI_TRY(addr_16.insertFromRight(i_addr.col_addr, 0, 16));
        FAPI_TRY(addr_16.extract(l_data_16));
        l_data_16.reverse();
        FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
        FAPI_TRY(addr_16.setBit(12)); // burst length 8
    }

    if ((l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, addr_16, bank_3));
    }

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add an ODT command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_repeat number of repeats to specify in this instruction
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_odt_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const access_address i_addr,
                                 const uint32_t i_repeat,
                                 const uint32_t i_delay,
                                 uint32_t& io_instruction_number)
{
    const uint8_t l_dimm = i_addr.mrank / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_addr.mrank % MAX_RANKS_PER_DIMM;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);

    uint8_t l_dram_type;
    uint8_t l_odt[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    const uint32_t odt_cyc = 5;
    uint32_t l_port = i_addr.port;
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba, l_dram_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, i_target_mba,  l_odt));

    // Buffer conversions from inputs
    addr_16.flush<0>();
    bank_3.flush<0>();
    csn_8.flush<1>();
    FAPI_TRY(csn_8.clearBit(6));
    FAPI_TRY(csn_8.clearBit(7));  //  need to have a unused cs_n for the valid data to write out on the bus.

    // Command structure setup
    cke_4.flush<1>();
    FAPI_TRY(rasn_1.setBit(0));
    FAPI_TRY(casn_1.setBit(0));
    FAPI_TRY(wen_1.setBit(0));

    // Final setup
    FAPI_TRY(odt_4.insert(l_odt[l_port][l_dimm][l_dimm_rank], 0, 4));
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    if(l_dram_type == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
    {
        FAPI_TRY(addr_16.setBit(12)); // burst length 8
    }

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    FAPI_TRY(repeat_16.insertFromRight((i_repeat + odt_cyc), 0, 16));
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add a precharge all command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in] i_odt_wr value of ATTR_CEN_VPD_ODT_WR
/// @param[in] i_stack_type value of ATTR_CEN_EFF_STACK_TYPE
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_precharge_all_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        const access_address i_addr,
        const uint32_t i_delay,
        const uint8_t (&i_odt_wr)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM],
        const uint8_t (&i_stack_type)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT],
        uint32_t& io_instruction_number)
{
    const uint8_t l_dimm = i_addr.mrank / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_addr.mrank % MAX_RANKS_PER_DIMM;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);

    uint32_t l_port = i_addr.port;
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;

    // Buffer conversions from inputs
    FAPI_TRY(addr_16.insertFromRight(i_addr.col_addr, 0, 16));
    FAPI_TRY(addr_16.extract(l_data_16));
    l_data_16.reverse();
    FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
    FAPI_TRY(bank_3.insertFromRight(i_addr.bank, 0, 3));
    FAPI_TRY(bank_3.extract(l_data_8, 0, 3));
    l_data_8.reverse();
    FAPI_TRY(bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));

    FAPI_TRY(cs_decode(i_target_mba, i_addr, i_stack_type[0][0], csn_8));

    // Command structure setup
    cke_4.flush<1>();
    FAPI_TRY(rasn_1.clearBit(0));
    FAPI_TRY(casn_1.setBit(0));
    FAPI_TRY(wen_1.clearBit(0));
    FAPI_TRY(addr_16.setBit(10));

    // Final setup
    FAPI_TRY(odt_4.insert(i_odt_wr[l_port][l_dimm][l_dimm_rank], 0, 4));
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add a DES command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_repeat number of repeats to specify in this instruction
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_des_with_repeat_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        const access_address i_addr,
        const uint32_t i_repeat,
        const uint32_t i_delay,
        uint32_t& io_instruction_number)
{
    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;
    uint32_t l_port = i_addr.port;

    // CCS Array 0 Setup

    // Buffer conversions from inputs
    FAPI_TRY(addr_16.insertFromRight(i_addr.row_addr, 0, 16));
    FAPI_TRY(addr_16.extract(l_data_16));
    l_data_16.reverse();
    FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
    FAPI_TRY(bank_3.insertFromRight(i_addr.bank, 0, 3));
    FAPI_TRY(bank_3.extract(l_data_8, 0, 3));
    l_data_8.reverse();
    FAPI_TRY(bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));
    csn_8.flush<1>();

    // Command structure setup
    cke_4.flush<1>();
    FAPI_TRY(rasn_1.setBit(0));
    FAPI_TRY(casn_1.setBit(0));
    FAPI_TRY(wen_1.setBit(0));

    FAPI_TRY(read_compare_1.clearBit(0));

    // Final setup
    odt_4.flush<0>();
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    idles_16.flush<0>();
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    FAPI_TRY(repeat_16.insertFromRight(i_repeat, 0, 16));
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Get the CSN representation of a given address
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for MRS
/// @param[in] i_stack_type value of ATTR_CEN_EFF_STACK_TYPE for given MBA
/// @param[out] o_csn_8 CSN encoding
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode cs_decode(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                            const access_address i_addr,
                            const uint8_t i_stack_type,
                            fapi2::variable_buffer& o_csn_8)
{
    fapi2::variable_buffer mrank(8);
    fapi2::variable_buffer cid(8);
    fapi2::buffer<uint64_t> data_buffer;

    o_csn_8.flush<1>();

    if(i_stack_type == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
    {
        FAPI_TRY(mrank.insert(i_addr.mrank, 4, 4, 4));
        FAPI_TRY(cid.insert(i_addr.srank, 4, 4, 4));

        uint8_t mrank_u8 = 0;
        mrank.extract(mrank_u8, 0, 8);
        uint8_t cid_u8 = 0;
        cid.extract(cid_u8, 0, 8);

        FAPI_ASSERT((mrank_u8 == 0 || mrank_u8 == 1  || mrank_u8 == 4 || mrank_u8 == 5),
                    fapi2::CEN_MSS_CCS_MRANK_OUT_OF_BOUNDS()
                    .set_INDEX_VALUE(mrank_u8),
                    "mrank value: 0x%02X not supported\n", mrank_u8);

        FAPI_ASSERT(cid_u8 < 8,
                    fapi2::CEN_MSS_CCS_SRANK_OUT_OF_BOUNDS()
                    .set_INDEX_VALUE(cid_u8),
                    "srank/cid value: 0x%X not Supported", cid_u8);

        FAPI_TRY(o_csn_8.clearBit(mrank_u8));

        if (mrank_u8 >= MAX_RANKS_PER_DIMM)
        {
            FAPI_TRY(o_csn_8.insert(cid_u8, 6, 1, 7));
            FAPI_TRY(o_csn_8.insert(cid_u8, 7, 1, 6));
        }
        else
        {
            FAPI_TRY(o_csn_8.insert(cid_u8, 2, 1, 7));
            FAPI_TRY(o_csn_8.insert(cid_u8, 3, 1, 6));
        }

        FAPI_DBG("%s Row: %x, Col: %x, Mrank: %d, Srank: %d, Bank: %d, Port: %d\n",
                 mss::c_str(i_target_mba), i_addr.row_addr, i_addr.col_addr, mrank_u8, cid_u8, i_addr.bank, i_addr.port);
    }
    else
    {
        FAPI_TRY(o_csn_8.clearBit(i_addr.mrank));
        FAPI_DBG("%s Row: %x, Col: %x, Rank: %d, Bank: %d, Port: %d\n",
                 mss::c_str(i_target_mba), i_addr.row_addr, i_addr.col_addr, i_addr.mrank, i_addr.bank, i_addr.port);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to check if we are a 128GB_16Gb_RDIMM
/// @param[in] i_target MBA target
/// @param[out] o_is_128GB_16Gb_RDIMM
/// @return true iff we are a 128GB_16Gb_RDIMM, false otherwise
///
static fapi2::ReturnCode check_128GB_16Gb_RDIMM (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        bool& o_is_128GB_16Gb_RDIMM)
{
    fapi2::ATTR_CEN_EFF_DIMM_TYPE_Type l_dimm_type = {};
    fapi2::ATTR_CEN_EFF_DIMM_SIZE_Type l_dimm_size = {};
    fapi2::ATTR_CEN_EFF_DRAM_DENSITY_Type l_dram_density = {};

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_SIZE, i_target, l_dimm_size));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DENSITY, i_target, l_dram_density));

    // Should have at least one DIMM so checking DIMM[0][0] is safe
    o_is_128GB_16Gb_RDIMM = (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM &&
                             l_dram_density == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DENSITY_16Gb &&
                             l_dimm_size[0][0] == fapi2::ENUM_ATTR_CEN_EFF_DIMM_SIZE_128GB);

fapi_try_exit:
    return fapi2::current_err;
};

///
/// @brief Helper function to calculate N_MBA throttle value
/// @param[in] i_target MBA target
/// @param[out] o_n_mba_throttle N_MBA throttle
/// @return FAPI2_RC_SUCCESS iff okay
///
static fapi2::ReturnCode calc_ipl_n_mba_throttle(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type& o_n_mba_throttle)
{
    // 68.75 desired utilization
    constexpr double DESIRED_UTILIZATION = 0.6875;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_dram_m_clocks = {};

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_dram_m_clocks));

    o_n_mba_throttle = static_cast<uint32_t>( (DESIRED_UTILIZATION * l_dram_m_clocks) /  DRAM_BUS_UTILS );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Throttle for N MBA value if it's above the throttle limit
/// @param[in] i_target MBA target
/// @param[in,out] io_n_mba_throttle
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode ipl_n_mba_throttle_override(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type& io_n_mba_throttle)
{
    bool l_is_128GB_16Gb_RDIMM = false;

    FAPI_TRY(check_128GB_16Gb_RDIMM(i_target, l_is_128GB_16Gb_RDIMM),
             "Failed 128GB_16Gb_RDIMM check (attr acessor reads) for %s",
             mss::c_str(i_target));

    if(!l_is_128GB_16Gb_RDIMM)
    {
        FAPI_DBG("Skipping ipl_n_mba_throttle_override(), applied only to 128GB 16Gb RDIMMs for %s",
                 mss::c_str(i_target));

        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Being here means we are a 128GB 16Gb RDIMM
    {
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type l_desired_n_mba_throttle = {};

        //  Calculate n_mba throttle using the desired dram data bus utilization
        FAPI_TRY(calc_ipl_n_mba_throttle(i_target, l_desired_n_mba_throttle),
                 "Failed calc_ipl_n_mba_throttle() for %s", mss::c_str(i_target));

        // Only limit the n_mba_throttle value if the previously calculated value
        //  is equal to or higher than our caculated n_mba_throttle using our
        // desired utilization of 68.75%.
        if (io_n_mba_throttle > l_desired_n_mba_throttle)
        {
            io_n_mba_throttle = l_desired_n_mba_throttle;
        }// end if
    }

fapi_try_exit:
    return fapi2::current_err;
}
