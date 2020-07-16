/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_funcs.H $ */
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

/// @file p9c_mss_funcs.H
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI


#ifndef _MSS_FUNCS_H
#define _MSS_FUNCS_H
#include <dimmConsts.H>

/// @brief Struct to contain DRAM address bits
/// @note For DDR4, bank should be set to {BA0, BA1, BG0, BG1}
struct access_address
{
    uint32_t row_addr;
    uint32_t col_addr;
    uint8_t  mrank;
    uint8_t  srank;
    uint8_t  bank;
    uint8_t  port;
};

///
/// @brief Disables all CID's
/// @param[in] i_target - the MBA target on which to operate
/// @param[in,out] io_csn - the CSN containing CID's
/// @param[in,out] io_cke - the CKE containing CID's
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_disable_cid( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                   fapi2::variable_buffer& io_csn,
                                   fapi2::variable_buffer& io_cke);

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
        fapi2::variable_buffer& o_address_16);

///
/// @brief Adding information to the CCS - 0 instruction array by index
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Instruction Number
/// @param[in] Mem Address for CCS
/// @param[in] Targeted Bank for CCS
/// @param[in] Activate line for CCS
/// @param[in] RAS line for CCS
/// @param[in] CAS line for CCS
/// @param[in] WEN line for CCS
/// @param[in] CKE line for CCS
/// @param[in] ODT line for CCS
/// @param[in] Cal type
/// @param[in] Targeted Mem Port for CCS
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_inst_arry_0(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
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
                                      uint32_t i_port);


///
/// @brief Adding information to the CCS - 1 instruction array by index
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Instruction Number for CCS
/// @param[in] Number of Idles cycles
/// @param[in] Number of repeats
/// @param[in] Data
/// @param[in] Read Compare
/// @param[in] Rank to cal
/// @param[in] Cal enable
/// @param[in] CCS end
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_inst_arry_1( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                       uint32_t& io_instruction_number,
                                       const fapi2::variable_buffer i_num_idles,
                                       const fapi2::variable_buffer i_num_repeat,
                                       const fapi2::variable_buffer i_data,
                                       const fapi2::variable_buffer i_read_compare,
                                       const fapi2::variable_buffer i_rank_cal,
                                       const fapi2::variable_buffer i_ddr_cal_enable,
                                       const fapi2::variable_buffer i_ccs_end);



///
/// @brief load predefined pattern (enum) into specified array1 index
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in, out] Instruction Number for CCS
/// @param[in] Data Pattern
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_load_data_pattern( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint32_t io_instruction_number,
        mss_ccs_data_pattern data_pattern);



///
/// @brief load specified pattern (20 bits) into specified array1 index
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in, out] CCS Instruction Number
/// @param[in] Data Pattern
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_load_data_pattern( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint32_t io_instruction_number,
        const uint32_t data_pattern);



///
/// @brief Querying the status of the CCS
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] CCS Status
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_status_query( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        mss_ccs_status_query_result& i_status);



///
/// @brief Issuing a start or stop of the CCS
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Start or Stop Bit
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_start_stop( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const uint32_t i_start_stop);


///
/// @brief Adding info the the Mode Register of the CCS
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Stop CCS on error bit
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
fapi2::ReturnCode mss_ccs_mode( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                const fapi2::variable_buffer i_stop_on_err,
                                const fapi2::variable_buffer i_ue_disable,
                                const fapi2::variable_buffer i_data_sel,
                                const fapi2::variable_buffer i_pclk,
                                const fapi2::variable_buffer i_nclk,
                                const fapi2::variable_buffer i_cal_time_cnt,
                                const fapi2::variable_buffer i_resetn,
                                const fapi2::variable_buffer i_reset_recover,
                                const fapi2::variable_buffer i_copy_spare_cke);


///
/// @brief Extracting the type of ccs fail
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_fail_type( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);



///
/// @brief Execute the CCS intruction array
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Poll Nuber
/// @param[in] Wait timer
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_execute_ccs_inst_array( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint32_t i_num_poll,
        const uint32_t i_wait_timer);


///
/// @brief Setting the End location of the CCS array
/// @param[in] i_target - Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_instruction_number - CCS instruction number
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_set_end_bit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                       uint32_t i_instruction_number);
///
/// @brief Setting the End location of the CCS array
/// @param[in] i_target - Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] i_instruction_number - CCS instruction number
/// @param[in] i_cke - CKE to pass into the NOP
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_ccs_set_end_bit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                       uint32_t i_instruction_number,
                                       const fapi2::variable_buffer& i_cke);


///
/// @brief Checking the Parity Error Bits associated with the RCD
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Memory Port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_rcd_parity_check(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                       const uint32_t i_port);


///
/// @brief Reversing bit order of 32 bit uint
/// @param[in,out] uint32 number
/// @return reversed bits
///
uint32_t mss_reverse_32bits(uint32_t io_x);

///
/// @brief Reversing bit order of 8 bit uint
/// @param[in] uint8 number
/// @return reversed bits
///
uint8_t mss_reverse_8bits(const uint8_t i_number);



///
/// @brief execute init ZQ Cal on given target and port
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in] Mem port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_execute_zq_cal(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_port);



///
/// @brief swizzle the address bus and bank address bus for address mirror mode
/// @param[in] Target<fapi2::TARGET_TYPE_MBA> = centaur.mba
/// @param[in, out] Address
/// @param[in, out] Bank
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_address_mirror_swizzle(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::variable_buffer& io_address,
        fapi2::variable_buffer& io_bank);

///
/// @brief Loading ddr3 RCD into the drams.
/// @param[in] i_target centaur.mba target
/// @param[in] i_port_number Port number
/// @param[in] io_ccs_inst_cnt ccs instance
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_rcd_load(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, const uint32_t i_port_number,
                               uint32_t& io_ccs_inst_cnt);

///
/// @brief Loading ddr3 MRS into the drams.
/// @param[in] i_target  centaur.mba target
/// @param[in] i_port_number Port number
/// @param[in,out] io_ccs_inst_cnt ccs instance
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_mrs_load(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, const uint32_t i_port_number,
                               uint32_t& io_ccs_inst_cnt);

///
/// @brief Print MRS Shadow Regs to STDOUT (FAPI_INF)
/// @param[in] i_target  centaur.mba target
/// @param[in] port Centaur port
/// @param[in] rank_pair_group
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode print_shadow_reg(fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target, const uint32_t port,
                                   const uint8_t rank_pair_group);

///
/// @brief Assert ResetN signal
/// @param[in]  i_target  Reference to centaur.mba target
/// @param[in]  value   Value to set resetN
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_assert_resetn (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, const uint8_t value);

///
/// @brief Assert ResetN, drive mem clocks
/// @param[in]  i_target  Reference to centaur.mba target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_assert_resetn_drive_mem_clks(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

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
                                   uint32_t& io_ccs_inst_cnt);

/// @brief Add a NOP command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_nop_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const access_address i_addr,
                                 const uint32_t i_delay,
                                 uint32_t& io_instruction_number);

/// @brief Add an MRS command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for MRS
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_mrs_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const access_address i_addr,
                                 const uint32_t i_delay,
                                 uint32_t& io_instruction_number);

/// @brief Add an ACT command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_activate_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const access_address i_addr,
                                      const uint32_t i_delay,
                                      uint32_t& io_instruction_number);

/// @brief Add a WR command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for command
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode add_write_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const access_address i_addr,
                                   const uint32_t i_delay,
                                   uint32_t& io_instruction_number);

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
                                 uint32_t& io_instruction_number);

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
        uint32_t& io_instruction_number);

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
        uint32_t& io_instruction_number);

/// @brief Get the CSN representation of a given address
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for MRS
/// @param[in] i_stack_type value of ATTR_CEN_EFF_STACK_TYPE for given MBA
/// @param[out] o_csn_8 CSN encoding
/// @return FAPI2_RC_SUCCESS iff successful
fapi2::ReturnCode cs_decode(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                            const access_address i_addr,
                            const uint8_t i_stack_type,
                            fapi2::variable_buffer& o_csn_8);

///
/// @brief Check if a given DIMM is functional
/// @param[in] i_valid_dimm_bitmap from ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR
/// @param[in] i_port port index [0:1]
/// @param[in] i_dimm dimm index [0:1]
/// @return true if dimm is functional, false otherwise
///
bool is_dimm_functional(const uint8_t i_valid_dimm_bitmap,
                        const uint8_t i_port,
                        const uint8_t i_dimm);

///
/// @brief Throttle for N MBA value if it's above the throttle limit
/// @param[in] i_target MBA target
/// @param[in,out] io_n_mba_throttle
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode ipl_n_mba_throttle_override(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type& io_n_mba_throttle);
#endif /* _MSS_FUNCS_H */

