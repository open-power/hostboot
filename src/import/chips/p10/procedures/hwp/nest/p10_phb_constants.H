/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_phb_constants.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p10_phb_constants.H
/// @brief Procedure to assert/deassert PERST from PHB. (FAPI2)
///
// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: Cronus/Lab

// EKB-Mirror-To: hostboot

#ifndef _P10_PHB_CONSTANTS_H_
#define _P10_PHB_CONSTANTS_H_

//---------------------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------------------


extern "C"
{


//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

//PHB HV Registers
    const uint32_t PHB_LEM_ERROR_MASK_REGISTER          = 0x0C18;
    const uint32_t PHB_TCE_TAG_ENABLE_REGISTER          = 0x0868;
    const uint32_t PHB_SYSTEM_CONFIGURATION_REGISTER        = 0x1A00;
    const uint32_t PHB_CORE_RESET_REGISTER              = 0x1A10;
    const uint32_t PHB_DLP_LANEEQ_CONTROL_REGISTER0         = 0x1AD0;
    const uint32_t PHB_DLP_LANEEQ_CONTROL_REGISTER1         = 0x1AD8;
    const uint32_t PHB_DLP_LANEEQ_CONTROL_REGISTER2         = 0x1AE0;
    const uint32_t PHB_DLP_LANEEQ_CONTROL_REGISTER3         = 0x1AE8;
    const uint32_t PHB_DLP_LANEEQ_CONTROL2_REGISTER0        = 0x1AF0;
    const uint32_t PHB_DLP_LANEEQ_CONTROL2_REGISTER1        = 0x1AF8;
    const uint32_t PHB_DLP_LANEEQ_CONTROL2_REGISTER2        = 0x1B00;
    const uint32_t PHB_DLP_LANEEQ_CONTROL2_REGISTER3        = 0x1B08;
    const uint32_t PHB_CFG_LINK_CTRL_STATUS_2_REGISTER      = 0x1078;
    const uint32_t PHB_CONTROL_REGISTER             = 0x0810;
    const uint32_t PHB_INTERUPT_NOTIFY_BASE_ADDR_REGISTER       = 0x0300;
    const uint32_t PHB_INTERUPT_NOTIFY_BASE_INDEX_REGISTER      = 0x0308;
    const uint32_t PHB_RTT_BASE_ADDR_REGISTER           = 0x0168;
    const uint32_t PHB_PELTV_BASE_ADDR_REGISTER         = 0x0188;
    const uint32_t PHB_M32_STARTING_ADDR_REGISTER           = 0x01A0;
    const uint32_t PHB_PEST_BASE_ADDR_REGISTER          = 0x01A8;
    const uint32_t PHB_CRW_BASE_ADDR_REGISTER           = 0x01B0;
    const uint32_t PHB_ASN_COMPARE_MASK_REGISTER            = 0x01C0;
    const uint32_t PHB_CAPI_COMPARE_MASK_REGISTER           = 0x01C8;
    const uint32_t PHB_PCIE_OUT_REQ_UPPER_ADDR_REGISTER     = 0x01F0;
    const uint32_t PHB_CONFIGURATION_REGISTER           = 0x0160;
    const uint32_t PHB_IODA_TABLE_ADDR_REGISTER         = 0x0220;
    const uint32_t PHB_IODA_TABLE_DATA_REGISTER         = 0x0228;
    const uint32_t PHB_DLP_ERROR_LOG_REGISTER1          = 0x1AA0;
    const uint32_t PHB_DLP_ERROR_LOG_REGISTER2          = 0x1AA8;
    const uint32_t PHB_DLP_ERROR_STATUS_REGISTER            = 0x1AB0;
    const uint32_t PHB_DLP_ERROR_COUNTERS_REGISTER          = 0x1AB8;
    const uint32_t PHB_CFG_PRIM_SEC_SUB_REGISTER            = 0x1018;
    const uint32_t PHB_CFG_IO_BASE_SEC_STATUS_REGISTER      = 0x101C;
    const uint32_t PHB_CFG_DEVICE_STATUS_CTRL_REGISTER      = 0x1050;
    const uint32_t PHB_CFG_DEVICE_STATUS_CTRL_REGISTER2     = 0x1070;
    const uint32_t PHB_CFG_AER_UE_STATUS_REGISTER           = 0x1104;
    const uint32_t PHB_CFG_AER_UE_MASK_REGISTER         = 0x1108;
    const uint32_t PHB_CFG_AER_CE_STATUS_REGISTER           = 0x1110;
    const uint32_t PHB_CFG_AER_CAP_CTRL_REGISTER            = 0x1118;
    const uint32_t PHB_CFG_AER_ROOT_ERR_STATUS_REGISTER     = 0x1118;
    const uint32_t PHB_PBL_ERROR_STATUS_REGISTER            = 0x1900;
    const uint32_t PHB_PBL_FIRST_ERROR_STATUS_REGISTER      = 0x1908;
    const uint32_t PHB_ERR_PBL_INF_ENABLE_REGISTER          = 0x1920;
    const uint32_t PHB_ERR_PBL_ECRC_ENABLE_REGISTER         = 0x1928;
    const uint32_t PHB_ERR_PBL_FAT_ENABLE_REGISTER          = 0x1930;
    const uint32_t PHB_PBL_ERROR_LOG_REGISTER0          = 0x1940;
    const uint32_t PHB_PBL_ERROR_LOG_REGISTER1          = 0x1948;
    const uint32_t PHB_PBL_ERROR_STATUS_MASK_REGISTER       = 0x1950;
    const uint32_t PHB_PBL_FIRST_ERROR_STATUS_MASK_REGISTER     = 0x1958;
    const uint32_t PHB_REGB_ERROR_STATUS_REGISTER           = 0x1C00;
    const uint32_t PHB_REGB_FIRST_ERROR_STATUS_REGISTER     = 0x1C08;
    const uint32_t PHB_ERR_REGB_INF_ENABLE_REGISTER         = 0x1C20;
    const uint32_t PHB_ERR_REGB_ECRC_ENABLE_REGISTER        = 0x1C28;
    const uint32_t PHB_ERR_REGB_FAT_ENABLE_REGISTER         = 0x1C30;
    const uint32_t PHB_REGB_ERROR_LOG_REGISTER0         = 0x1C40;
    const uint32_t PHB_REGB_ERROR_LOG_REGISTER1         = 0x1C48;
    const uint32_t PHB_REGB_ERROR_STATUS_MASK_REGISTER      = 0x1C50;
    const uint32_t PHB_REGB_FIRST_ERROR_STATUS_MASK_REGISTER    = 0x1C58;
    const uint32_t PHB_TXE_ERROR_STATUS_REGISTER            = 0x0D00;
    const uint32_t PHB_TXE_FIRST_ERROR_STATUS_REGISTER      = 0x0D08;
    const uint32_t PHB_TXE_ERR_LEM_REPORT_ENABLE_REGISTER       = 0x0D18;
    const uint32_t PHB_TXE_ERR_EEH_FREEZE_ENABLE_REGISTER       = 0x0D28;
    const uint32_t PHB_TXE_ERR_AIB_FENCE_ENABLE_REGISTER        = 0x0D30;
    const uint32_t PHB_TXE_ERROR_LOG_REGISTER0          = 0x0D40;
    const uint32_t PHB_TXE_ERROR_LOG_REGISTER1          = 0x0D48;
    const uint32_t PHB_TXE_ERROR_STATUS_MASK_REGISTER       = 0x0D50;
    const uint32_t PHB_TXE_FIRST_ERROR_STATUS_MASK_REGISTER     = 0x0D58;
    const uint32_t PHB_RXE_ARB_ERR_STATUS_REGISTER          = 0x0D80;
    const uint32_t PHB_RXE_ARB_FIRST_ERROR_STATUS_REGISTER      = 0x0D88;
    const uint32_t PHB_RXE_ARB_ERR_LEM_REPORT_ENABLE_REGISTER   = 0x0D98;
    const uint32_t PHB_RXE_ARB_ERR_EEH_FREEZE_ENABLE_REGISTER   = 0x0DA8;
    const uint32_t PHB_RXE_ARB_ERR_AIB_FENCE_ENABLE_REGISTER    = 0x0DB0;
    const uint32_t PHB_RXE_ARB_ERROR_LOG_REGISTER0          = 0x0DC0;
    const uint32_t PHB_RXE_ARB_ERROR_LOG_REGISTER1          = 0x0DC8;
    const uint32_t PHB_RXE_ARB_ERROR_STATUS_MASK_REGISTER       = 0x0DD0;
    const uint32_t PHB_RXE_ARB_FIRST_ERROR_STATUS_MASK_REGISTER = 0x0DD8;
    const uint32_t PHB_RXE_MRG_ERR_STATUS_REGISTER          = 0x0E00;
    const uint32_t PHB_RXE_MRG_FIRST_ERROR_STATUS_REGISTER      = 0x0E08;
    const uint32_t PHB_RXE_MRG_ERR_LEM_REPORT_ENABLE_REGISTER   = 0x0E18;
    const uint32_t PHB_RXE_MRG_ERR_EEH_FREEZE_ENABLE_REGISTER   = 0x0E28;
    const uint32_t PHB_RXE_MRG_ERR_AIB_FENCE_ENABLE_REGISTER    = 0x0E30;
    const uint32_t PHB_RXE_MRG_ERROR_LOG_REGISTER0          = 0x0E40;
    const uint32_t PHB_RXE_MRG_ERROR_LOG_REGISTER1          = 0x0E48;
    const uint32_t PHB_RXE_MRG_ERROR_STATUS_MASK_REGISTER       = 0x0E50;
    const uint32_t PHB_RXE_MRG_FIRST_ERROR_STATUS_MASK_REGISTER = 0x0E50;
    const uint32_t PHB_RXE_TCE_ERR_STATUS_REGISTER          = 0x0E80;
    const uint32_t PHB_RXE_TCE_FIRST_ERROR_STATUS_REGISTER      = 0x0E88;
    const uint32_t PHB_RXE_TCE_ERR_LEM_REPORT_ENABLE_REGISTER   = 0x0E98;
    const uint32_t PHB_RXE_TCE_ERR_EEH_FREEZE_ENABLE_REGISTER   = 0x0EA8;
    const uint32_t PHB_RXE_TCE_ERR_AIB_FENCE_ENABLE_REGISTER    = 0x0EB0;
    const uint32_t PHB_RXE_TCE_ERROR_LOG_REGISTER0          = 0x0EC0;
    const uint32_t PHB_RXE_TCE_ERROR_LOG_REGISTER1          = 0x0EC8;
    const uint32_t PHB_RXE_TCE_ERROR_STATUS_MASK_REGISTER       = 0x0ED0;
    const uint32_t PHB_RXE_TCE_FIRST_ERROR_STATUS_MASK_REGISTER = 0x0ED8;
    const uint32_t PHB_ERROR_STATUS_REGISTER            = 0x0C80;
    const uint32_t PHB_FIRST_ERROR_STATUS_REGISTER          = 0x0C88;
    const uint32_t PHB_ERR_LEM_REPORT_ENABLE_REGISTER       = 0x0C98;
    const uint32_t PHB_ERR_EEH_FREEZE_ENABLE_REGISTER       = 0x0CA8;
    const uint32_t PHB_ERR_AIB_FENCE_ENABLE_REGISTER        = 0x0CB0;
    const uint32_t PHB_ERROR_LOG_REGISTER0              = 0x0CC0;
    const uint32_t PHB_ERROR_LOG_REGISTER1              = 0x0CC8;
    const uint32_t PHB_ERROR_STATUS_MASK_REGISTER           = 0x0CD0;
    const uint32_t PHB_FIRST_ERROR_STATUS_MASK_REGISTER     = 0x0CD8;
    const uint32_t PHB_LEM_FIR_ACCUMALATOR_REGISTER         = 0x0C00;
    const uint32_t PHB_LEM_ACTION0_REGISTER             = 0x0C30;
    const uint32_t PHB_LEM_ACTION1_REGISTER             = 0x0C38;
    const uint32_t PHB_LEM_WOF_REGISTER             = 0x0C40;
    const uint32_t PHB_DLP_TRAINING_CTRL_REGISTER           = 0x1A40;
    const uint32_t PHB_PCIE_LINK_MANAGEMENT_REGISTER        = 0x1A30;
    const uint32_t PHB_PBL_NBW_COMPARE_MASK_REGISTER        = 0x1830;
    const uint32_t PHB_CFG_COMMAND_STATUS_REGISTER          = 0x1004;
    const uint32_t PHB_ERR_SYSTEM_INT_ENABLE_REGISTER       = 0x0CA0;
    const uint32_t PHB_TXE_ERR_SYSTEM_INT_ENABLE_REGISTER       = 0x0D20;
    const uint32_t PHB_RXE_ARB_ERR_SYSTEM_INT_ENABLE_REGISTER   = 0x0DA0;
    const uint32_t PHB_RXE_MRG_ERR_SYSTEM_INT_ENABLE_REGISTER   = 0x0E20;
    const uint32_t PHB_RXE_TCE_ERR_SYSTEM_INT_ENABLE_REGISTER   = 0x0EA0;
    const uint32_t PHB_SPECULATION_CONTROL_REGISTER         = 0x0218;
    const uint32_t PHB_TIMEOUT_CONTROL_REGISTER1            = 0x0878;
    const uint32_t PHB_TIMEOUT_CONTROL_REGISTER2            = 0x0880;
    const uint32_t PHB_PBL_TIMEOUT_CONTROL_REGISTER         = 0x1810;
    const uint32_t PHB_HOTPLUG_STATUS_REGISTER          = 0x1A20;
    const uint32_t PHB_PCIE_MISC_STRAP_REGISTER         = 0x1B30;
    const uint32_t PHB_PCIE_DLP_CONTROL_REGISTER        = 0x1A78;

//PHB HV Register field/bit definitions
    const uint32_t PHB_HV_1A00_PHYSICAL_LINK_WIDTH_START_BIT   = 40;
    const uint32_t PHB_HV_1A00_PHYSICAL_LINK_WIDTH_NUM_OF_BITS = 6;
    const uint32_t PHB_HV_1A10_CFG_CORE_RESET_BIT       = 0;
    const uint32_t PHB_HV_1A10_PDL_PTL_RESET_BIT        = 1;
    const uint32_t PHB_HV_1A10_PBL_RESET_BIT            = 2;
    const uint32_t PHB_HV_1A10_HP_PERST_BIT             = 3;
    const uint32_t PHB_HV_1A10_PIPE_RESETN_BIT          = 4;
    const uint32_t PHB_HV_1A30_TL_EC10_LINKACTIVE_BIT      = 8;
    const uint32_t PHB_HV_1A40_TL_EC10_DL_PGRESET      = 22;
    const uint32_t PHB_HV_1A40_TL_EC10_LINKACTIVE_BIT      = 23;
    const uint32_t PHB_HV_1A20_HP_PRESENCE_BIT         = 10;

} //extern"C"

#endif //_P10_PHB_CONSTANTS_H_
