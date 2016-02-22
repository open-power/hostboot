/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_pcie_scominit.H $             */
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
const uint8_t NUM_M_CONFIG = 4;
const uint8_t PEC0_IOP_CONFIG_START_BIT = 13;
const uint8_t PEC1_IOP_CONFIG_START_BIT = 14;
const uint8_t PEC2_IOP_CONFIG_START_BIT = 10;
const uint8_t PEC0_IOP_BIT_COUNT = 1;
const uint8_t PEC1_IOP_BIT_COUNT = 2;
const uint8_t PEC2_IOP_BIT_COUNT = 3;
const uint8_t PEC0_IOP_SWAP_START_BIT = 11;
const uint8_t PEC1_IOP_SWAP_START_BIT = 12;
const uint8_t PEC2_IOP_SWAP_START_BIT = 7;
const uint8_t PEC0_IOP_IOVALID_ENABLE_START_BIT = 4;
const uint8_t PEC1_IOP_IOVALID_ENABLE_START_BIT = 4;
const uint8_t PEC2_IOP_IOVALID_ENABLE_START_BIT = 4;
const uint8_t PEC_IOP_PMA_RESET_START_BIT = 29;
const uint8_t PEC_IOP_PIPE_RESET_START_BIT = 28;

const uint32_t PCS_CONFIG_MODE0 = 0xA0006;
const uint32_t PCS_CONFIG_MODE1 = 0xA805;
const uint32_t PCS_CONFIG_MODE2 = 0xB071;
const uint32_t PCS_CONFIG_MODE3 = 0xB870;

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
