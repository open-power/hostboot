/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_pcie_scominit.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
//-----------------------------------------------------------------------------------
///
/// @file p9_pcie_scominit.H
/// @brief Perform PCIE Phase1 init sequence (FAPI2)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB

#ifndef _P9_PCIE_SCOMINIT_H_
#define _P9_PCIE_SCOMINIT_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Helper Macros
//-----------------------------------------------------------------------------------
#define SET_REG_RMW_WITH_SINGLE_ATTR_8(in_attr_name, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(FAPI_ATTR_GET(in_attr_name, l_pec_chiplets, l_attr_8)); \
    FAPI_TRY(fapi2::getScom(l_pec_chiplets, in_reg_name, l_buf)); \
    FAPI_TRY(l_buf.insertFromRight(l_attr_8, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_RMW_WITH_SINGLE_ATTR_16(in_attr_name, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(FAPI_ATTR_GET(in_attr_name, l_pec_chiplets, l_attr_16)); \
    FAPI_TRY(fapi2::getScom(l_pec_chiplets, in_reg_name, l_buf)); \
    FAPI_TRY(l_buf.insertFromRight(l_attr_16, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_WR_WITH_SINGLE_ATTR_16(in_attr_name, in_reg_name, in_start_bit, in_bit_count)\
    l_buf = 0; \
    FAPI_TRY(FAPI_ATTR_GET(in_attr_name, l_pec_chiplets, l_attr_16)); \
    FAPI_TRY(l_buf.insertFromRight(l_attr_16, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_RMW(in_value, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(fapi2::getScom(l_pec_chiplets, in_reg_name, l_buf)); \
    FAPI_TRY(l_buf.insertFromRight(in_value, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

#define SET_REG_WR(in_value, in_reg_name, in_start_bit, in_bit_count)\
    FAPI_TRY(l_buf.insertFromRight(in_value, in_start_bit, in_bit_count)); \
    FAPI_DBG("pec%i: %#lx", l_pec_id, l_buf()); \
    FAPI_TRY(fapi2::putScom(l_pec_chiplets, in_reg_name, l_buf));

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pcie_scominit_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

const uint8_t NUM_PCS_CONFIG = 4;
const uint8_t NUM_PCIE_LANES = 16;
const uint8_t NUM_M_CONFIG = 4;
const uint8_t PEC0_IOP_CONFIG_START_BIT = 13;
const uint8_t PEC1_IOP_CONFIG_START_BIT = 14;
const uint8_t PEC2_IOP_CONFIG_START_BIT = 10;
const uint8_t PEC0_IOP_BIT_COUNT = 1;
const uint8_t PEC1_IOP_BIT_COUNT = 2;
const uint8_t PEC2_IOP_BIT_COUNT = 3;
const uint8_t PEC0_IOP_SWAP_START_BIT = 12;
const uint8_t PEC1_IOP_SWAP_START_BIT = 12;
const uint8_t PEC2_IOP_SWAP_START_BIT = 7;
const uint8_t PEC0_IOP_IOVALID_ENABLE_START_BIT = 4;
const uint8_t PEC1_IOP_IOVALID_ENABLE_START_BIT = 4;
const uint8_t PEC2_IOP_IOVALID_ENABLE_START_BIT = 4;
const uint8_t PEC_IOP_REFCLOCK_ENABLE_START_BIT = 32;
const uint8_t PEC_IOP_PMA_RESET_START_BIT = 29;
const uint8_t PEC_IOP_PIPE_RESET_START_BIT = 28;
const uint8_t PEC_IOP_HSS_PORT_READY_START_BIT = 58;

const uint64_t  PEC_IOP_PLLA_VCO_COURSE_CAL_REGISTER1 = 0x800005010D010C3F;
const uint64_t  PEC_IOP_PLLB_VCO_COURSE_CAL_REGISTER1 = 0x800005410D010C3F;
const uint64_t  PEC_IOP_RX_DFE_FUNC_REGISTER1 = 0x8000049F0D010C3F;
const uint64_t  PEC_IOP_RX_DFE_FUNC_REGISTER2 = 0x800004A00D010C3F;

const uint64_t  RX_VGA_CTRL3_REGISTER[NUM_PCIE_LANES] =
{
    0x8000008D0D010C3F,
    0x800000CD0D010C3F,
    0x8000018D0D010C3F,
    0x800001CD0D010C3F,
    0x8000028D0D010C3F,
    0x800002CD0D010C3F,
    0x8000038D0D010C3F,
    0x800003CD0D010C3F,
    0x8000088D0D010C3F,
    0x800008CD0D010C3F,
    0x8000098D0D010C3F,
    0x800009CD0D010C3F,
    0x80000A8D0D010C3F,
    0x80000ACD0D010C3F,
    0x80000B8D0D010C3F,
    0x80000BCD0D010C3F,
};

const uint64_t  RX_LOFF_CNTL_REGISTER[NUM_PCIE_LANES] =
{
    0x800000A60D010C3F,
    0x800000E60D010C3F,
    0x800001A60D010C3F,
    0x800001E60D010C3F,
    0x800002A60D010C3F,
    0x800002E60D010C3F,
    0x800003A60D010C3F,
    0x800003E60D010C3F,
    0x800008A60D010C3F,
    0x800008E60D010C3F,
    0x800009A60D010C3F,
    0x800009E60D010C3F,
    0x80000AA60D010C3F,
    0x80000AE60D010C3F,
    0x80000BA60D010C3F,
    0x80000BE60D010C3F,

};

const uint32_t PCS_CONFIG_MODE0 = 0xA006;
const uint32_t PCS_CONFIG_MODE1 = 0xA805;
const uint32_t PCS_CONFIG_MODE2 = 0xB071;
const uint32_t PCS_CONFIG_MODE3 = 0xB870;

const uint32_t MAX_NUM_POLLS = 100; //Maximum number of iterations (So, 400ns * 100 = 40us before timeout)
const uint64_t PMA_RESET_NANO_SEC_DELAY = 400; //400ns to wait for PMA RESET to go through
const uint64_t PMA_RESET_CYC_DELAY = 400; //400ns to wait for PMA RESET to go through

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Perform PCIE Phase1 init sequence
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if the setup completes successfully,
//
    fapi2::ReturnCode p9_pcie_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
} //extern"C"

#endif //_P9_PCIE_SCOMINIT_H_
