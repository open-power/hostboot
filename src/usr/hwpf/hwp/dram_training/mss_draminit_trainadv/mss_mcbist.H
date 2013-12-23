/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_mcbist.H,v 1.41 2013/12/17 18:34:53 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             :  mss_mcbist.H
// *! TITLE                :
// *! DESCRIPTION          : MCBIST procedures
// *! CONTEXT              :
// *!
// *! OWNER  NAME          : Devashikamani, Aditya        Email: adityamd@in.ibm.com
// *! BACKUP               : Sethuraman, Saravanan        Email: saravanans@in.ibm.com
// *!***************************************************************************
// CHANGE HISTORY:
//-------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
//   1.41  |aditya  |12/17/13 |Updated mcb_error_map function parameters
//   1.40  |rwheeler|10/29/13 |added W_ONLY_INFINITE_RAND test
//   1.39  |aditya  |10/29/13 |Updated mcb_error_map function parameters
//   1.38  |aditya  |09/18/13 |Updated parameters for random seed attribute
//   1.37  |aditya  |08/02/13 |Updated parameters in mcb_error_map_print function
//   1.36  |aditya  |07/09/13 |Added l_random_addr_enable and l_fixed_addr_enable for struct Subtest_info
//   1.35  |aditya  |06/11/13 |Added l_random_data_enable and l_fixed_data_enable for struct Subtest_info
//   1.34  |aditya  |05/23/13 |Added TEST_RR and TEST_RF testtypes
//   1.33  |aditya  |05/22/13 |updated parameters for Subtest Printing
//   1.32  |aditya  |05/14/13 |updated parameters for cfg_mcb_dgen and random seed details
//   1.31  |aditya  |05/07/13 |Changed Parameter Passing in Functions
//   1.30  |aditya  |04/22/13 |updated testtypes
//   1.27  |aditya  |02/13/13 |updated testtypes
//   1.25  |aditya  |02/12/13 |updated testtypes
//   1.24  |aditya  |01/30/13 |Updated fw comments
//   1.23  |aditya  |01/16/13 |added a parameter to setup_mcbist function
//   1.22  |aditya  |01/11/13 |added a parameter to setup_mcbist function
//   1.21  |aditya  |01/07/13 | Updated FW Review Comments
//   1.20  |aditya  |01/03/13 | Updated FW Comments
//   1.18  |aditya  |12/18/12 | Updated Review Comments
//   1.17  |aditya  |12/14/12 |Updated FW review comments
//   1.16  |aditya  |12/6/12  | Updated Review Comments
//   1.15  |aditya  |11/15/12 | Updated for FW REVIEW COMMENTS
//   1.13  |aditya  |10/29/12 | Updated from ReturnCode to fapi::ReturnCode and Target to const fapi::Target &
//   1.12  |aditya  |10/18/12 | Changed Parameters for Function mcb_write_test_mem
//   1.11  |aditya  |10/17/12 | updated code to be compatible with ecmd 13 release
//   1.10  |aditya  |15-Oct-12| Moved scom address to cen_scom_addresses.H, added user option
//   1.9   |bellows |16-Jul-12| Added in Id tag
//   1.6   |gaushard|26/03/12 | Removed Extra Comments/Codes
//   1.5   |gaushard|26/03/12 | Updated Function Declaration
//   1.4   |sasethur|23/03/12 | Added enum for shmoo mode
//   1.3   |gaushard|22/03/12 | Added address generation function
//   1.2   |sasethur|24/02/12 | Updated Typo
//   1.1   |gaushard|14/02/12 | Shifted register address from .C file to .H file
//   1.0   |gaushard|12/01/12 | Initial version
//------------------------------------------------------------------------------
#ifndef MSS_MCBIST_H
#define MSS_MCBIST_H
/****************************************************************************************/
/* mss_mcbist.H                                                                           */
/****************************************************************************************/
#include <fapi.H>
#include <cen_scom_addresses.H>
#include <mss_access_delay_reg.H>

extern "C"
{
using namespace fapi;

//############### Global variables ################

enum mcbist_test_mem
{
    USER_MODE,
    CENSHMOO,
    SUREFAIL,
    MEMWRITE,
    MEMREAD,
    CBR_REFRESH,
    MCBIST_SHORT,
    SHORT_SEQ,
    DELTA_I,
    DELTA_I_LOOP,
    SHORT_RAND,
    LONG1,
    BUS_TAT,
    SIMPLE_FIX,
    SIMPLE_RAND,
    SIMPLE_RAND_2W,
    SIMPLE_RAND_FIXD,
    SIMPLE_RA_RD_WR,
    SIMPLE_RA_RD_R,
    SIMPLE_RA_FD_R,
    SIMPLE_RA_FD_R_INF,
    SIMPLE_SA_FD_R,
    SIMPLE_RA_FD_W,
    INFINITE,
    WR_ONLY,
    W_ONLY,
    R_ONLY,
    W_ONLY_RAND,
    R_ONLY_RAND,
    R_ONLY_MULTI,
    SHORT,
    SIMPLE_RAND_BARI,
    W_R_INFINITE,
    W_R_RAND_INFINITE,
    R_INFINITE1,
    R_INFINITE_RF,
    MARCH,
    SIMPLE_FIX_RF,
    SHMOO_STRESS,
    SIMPLE_RAND_RA,
    SIMPLE_FIX_RA,
    SIMPLE_FIX_RF_RA,
    TEST_RR,
    TEST_RF,
    W_ONLY_INFINITE_RAND
};

enum mcbist_data_gen
{
    ABLE_FIVE,
    USR_MODE,
    ONEHOT,
    DQ0_00011111_RESTALLONE,
    DQ0_11100000_RESTALLZERO,
    ALLZERO,
    ALLONE,
    BYTE_BURST_SIGNATURE,
    BYTE_BURST_SIGNATURE_V1,
    BYTE_BURST_SIGNATURE_V2,
    BYTE_BURST_SIGNATURE_V3,
    DATA_GEN_DELTA_I,
    MCBIST_2D_CUP_PAT0,
    MPR,
    MPR03,
    MPR25,
    MPR47,
    DELTA_I1,
    MCBIST_2D_CUP_PAT1,
    MHC_55,
    MHC_DQ_SIM,
    MCBIST_2D_CUP_PAT2,
    MCBIST_2D_CUP_PAT3,
    MCBIST_2D_CUP_PAT4,
    MCBIST_2D_CUP_PAT5,
    MCBIST_2D_CUP_PAT6,
    MCBIST_2D_CUP_PAT7,
    MCBIST_2D_CUP_PAT8,
    MCBIST_2D_CUP_PAT9,
    CWLPATTERN,
    GREY1,
    DC_ONECHANGE,
    DC_ONECHANGEDIAG,
    GREY2,
    FIRST_XFER,
    MCBIST_222_XFER,
    MCBIST_333_XFER,
    MCBIST_444_XFER,
    MCBIST_555_XFER,
    MCBIST_666_XFER,
    MCBIST_777_XFER,
    MCBIST_888_XFER,
    FIRST_XFER_X4MODE,
    MCBIST_LONG,
    PSEUDORANDOM,
    CASTLE
};

enum mcbist_oper_type
{
    W,
    R,
    RW,
    WR,
    RWR,
    RWW,
    OPER_RAND,
    GOTO
};

enum mcbist_data_mode
{
    FIX,
    DATA_RF,
    DATA_RR,
    RECCF,
    RECCB,
    DEA,
    DRL,
    DRR
    	      	
};

enum mcbist_addr_mode
{
    SF,
    SR,
    RF,
    RR
};

enum mcbist_add_select_mode
{
    FIX_ADDR,
    PORTA0_RANDOM,
    PORTA1_RANDOM,
    PORTA0_SEQ
};

enum mcbist_data_select_mode
{
    DEFAULT,
    BURST0,
    BURST1,
    BURST2
};

enum mcbist_byte_mask
{
    BYTE0,
    BYTE1,
    BYTE2,
    BYTE3,
    BYTE4,
    BYTE5,
    BYTE6,
    BYTE7,
    BYTE8,
    BYTE9,
    UNMASK_ALL,
    NONE
};

enum shmoo_mode
{
   FAST = 0,
   ONE_SLOW = 1,
   QUARTER_SLOW = 2,
   HALF_SLOW = 3,
   FULL_SLOW = 4,
   ONE_CHAR = 5,
   QUARTER_CHAR = 6,
   HALF_CHAR = 7,
   FULL_CHAR = 8
};

enum shmoo_addr_mode
{
   FEW_ADDR= 0,
   QUARTER_ADDR = 1,
   HALF_ADDR = 2,
   FULL_ADDR = 3
};

struct Subtest_info
{
uint8_t l_operation_type;
uint8_t l_data_mode;
uint8_t l_addr_mode;
uint8_t l_random_data_enable;
uint8_t l_fixed_data_enable;
uint8_t l_random_addr_enable;
uint8_t l_fixed_addr_enable;
};


fapi::ReturnCode poll_mcb(const fapi::Target & i_target_mba,uint8_t *o_mcb_status,struct Subtest_info l_sub_info[30],uint8_t i_flag);
fapi::ReturnCode mcb_error_map(const fapi::Target & i_target_mba,uint8_t  o_error_map[][8][10][2],uint8_t i_CDarray0[80],uint8_t i_CDarray1[80],uint8_t count_bad_dq[2]);
fapi::ReturnCode mcb_write_test_mem(const fapi::Target & i_target_mba,const uint64_t i_reg_addr,mcbist_oper_type i_operation_type,uint8_t i_cfg_test_123_cmd,mcbist_addr_mode i_addr_mode,mcbist_data_mode i_data_mode,uint8_t i_done,mcbist_data_select_mode i_data_select_mode, mcbist_add_select_mode i_addr_select_mode,uint8_t i_testnumber,uint8_t i_testnumber1,uint8_t i_total_no,struct Subtest_info l_sub_info[30]);
fapi::ReturnCode cfg_mcb_test_mem(const fapi::Target & i_target_mba,mcbist_test_mem i_test_type,struct Subtest_info l_sub_info[30]);
fapi::ReturnCode mcb_reset_trap(const fapi::Target & i_target_mba);
fapi::ReturnCode cfg_mcb_dgen(const fapi::Target & i_target_mba,mcbist_data_gen i_datamode,uint8_t i_mcbrotate);
fapi::ReturnCode cfg_byte_mask(const fapi::Target & i_target_mba);
fapi::ReturnCode start_mcb(const fapi::Target & i_target_mba);
fapi::ReturnCode setup_mcbist(const fapi::Target & i_target_mba,mcbist_byte_mask i_mcbbytemask,uint8_t i_mcbrotate,struct Subtest_info l_sub_info[30]);
//fapi::ReturnCode  mcb_error_map_print(const fapi::Target & i_target_mba,ecmdDataBufferBase & i_mcb_fail_320,uint8_t i_port);
//fapi::ReturnCode  mcb_error_map_print(const fapi::Target & i_target_mba,ecmdDataBufferBase & l_mcb_fail_160,uint8_t i_port,uint8_t l_array[200],uint8_t l_number);
fapi::ReturnCode  mcb_error_map_print(const fapi::Target & i_target_mba,ecmdDataBufferBase & l_mcb_fail_160,uint8_t i_port,uint8_t l_array[80],uint8_t l_number,ecmdDataBufferBase l_data_buf_port,ecmdDataBufferBase l_data_buf_spare);
fapi::ReturnCode mss_conversion_testtype(const fapi::Target & i_target_mba,uint8_t l_pattern,mcbist_test_mem &i_mcbtest );
fapi::ReturnCode mss_conversion_data(const fapi::Target & i_target_mba,uint8_t l_pattern,mcbist_data_gen  &i_mcbpatt);



}
#endif
