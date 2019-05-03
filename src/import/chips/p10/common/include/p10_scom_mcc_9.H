/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_9.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#include "proc_scomt.H"

#ifndef __p10_scom_mcc_9_H_
#define __p10_scom_mcc_9_H_


namespace scomt
{
namespace mcc
{


static const uint64_t ATCL_CL_CLSCOM_MCAMOC = 0x0c010c25ull;

static const uint32_t ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN = 0;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP0 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_FORCE_PF_DROP1 = 2;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_EN_RD_FROM_AMOC = 3;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES = 4;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_LEN = 25;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT = 29;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_WRTO = 32;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47 = 33;
static const uint32_t ATCL_CL_CLSCOM_MCAMOC_RESERVED33_47_LEN = 15;
// mcc/reg00009.H

static const uint64_t ATCL_CL_CLSCOM_MCWAT = 0x0c010c2aull;

static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL = 0;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CMD_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_RETRY_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_RESERVED8_9 = 9;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG = 10;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_ENABLE_EARLY_HANG_PULSE = 11;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL = 12;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_RRQ_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL = 16;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_WRQ_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL = 20;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_MERGE_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL = 24;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_DEALLOC_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL = 28;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_WAT_CRESP_STALL_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSTATE_DEBUG_SEL = 32;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSTATE_DEBUG_SEL_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_DEBUG_SEL = 40;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_DISP_DEBUG_SEL_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_DEBUG_SEL = 48;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CHARB_DEBUG_SEL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSX_DEBUG_SEL = 52;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSX_DEBUG_SEL_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL = 59;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_WAT_BLOCK_WRBUF_AVAIL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCWAT_CLSTATE_INT_DEBUG_SEL = 63;
// mcc/reg00009.H

static const uint64_t DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 35;
// mcc/reg00009.H

static const uint64_t DSTL_DSTLSTATUS = 0x0c010d10ull;

static const uint32_t DSTL_DSTLSTATUS_A_FAIL_WOF = 0;
static const uint32_t DSTL_DSTLSTATUS_A_FAIL_WOF_LEN = 10;
static const uint32_t DSTL_DSTLSTATUS_B_FAIL_WOF = 10;
static const uint32_t DSTL_DSTLSTATUS_B_FAIL_WOF_LEN = 10;
// mcc/reg00009.H

static const uint64_t WDF_WDFCFG = 0x0c010f40ull;

static const uint32_t WDF_WDFCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t WDF_WDFCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t WDF_WDFCFG_CFG_WDF_SERIAL_SEQ_MODE = 2;
static const uint32_t WDF_WDFCFG_RESET_KEEPER = 3;
static const uint32_t WDF_WDFCFG_MERGE_CAPACITY_LIMIT = 4;
static const uint32_t WDF_WDFCFG_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t WDF_WDFCFG_WDFCFG_8_11_SPARE = 8;
static const uint32_t WDF_WDFCFG_WDFCFG_8_11_SPARE_LEN = 4;
static const uint32_t WDF_WDFCFG_WDFCFG_16_17_SPARE = 16;
static const uint32_t WDF_WDFCFG_WDFCFG_16_17_SPARE_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW0_ERR_INJ = 18;
static const uint32_t WDF_WDFCFG_DSTL_DW0_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW1_ERR_INJ = 20;
static const uint32_t WDF_WDFCFG_DSTL_DW1_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW2_ERR_INJ = 22;
static const uint32_t WDF_WDFCFG_DSTL_DW2_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_DW3_ERR_INJ = 24;
static const uint32_t WDF_WDFCFG_DSTL_DW3_ERR_INJ_LEN = 2;
static const uint32_t WDF_WDFCFG_DSTL_ONE_SHOT_INJ = 26;
static const uint32_t WDF_WDFCFG_DSTL_PERSISTANT_INJ = 27;
static const uint32_t WDF_WDFCFG_WDFCFG_28_31_SPARE = 28;
static const uint32_t WDF_WDFCFG_WDFCFG_28_31_SPARE_LEN = 4;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT = 32;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_SELECT_LEN = 4;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE = 36;
static const uint32_t WDF_WDFCFG_ECC_WDF_HCA_TIMEBASE_LEN = 28;
// mcc/reg00009.H

static const uint64_t WRITE_WRTCFG = 0x0c010f48ull;

static const uint32_t WRITE_WRTCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t WRITE_WRTCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t WRITE_WRTCFG_RESET_KEEPER = 2;
static const uint32_t WRITE_WRTCFG_MPIPL = 3;
static const uint32_t WRITE_WRTCFG_ASYNC_INJ = 4;
static const uint32_t WRITE_WRTCFG_ASYNC_INJ_LEN = 4;
static const uint32_t WRITE_WRTCFG_SPARE_8 = 8;
static const uint32_t WRITE_WRTCFG_NEW_WRITE_64B_MODE = 9;
static const uint32_t WRITE_WRTCFG_CFG_OVERRUN_FORCE_SUE_ENABLE = 10;
static const uint32_t WRITE_WRTCFG_RESERVED_11 = 11;
static const uint32_t WRITE_WRTCFG_DSTL_DW0_ERR_INJ = 12;
static const uint32_t WRITE_WRTCFG_DSTL_DW0_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_DW1_ERR_INJ = 14;
static const uint32_t WRITE_WRTCFG_DSTL_DW1_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_DW2_ERR_INJ = 16;
static const uint32_t WRITE_WRTCFG_DSTL_DW2_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_DW3_ERR_INJ = 18;
static const uint32_t WRITE_WRTCFG_DSTL_DW3_ERR_INJ_LEN = 2;
static const uint32_t WRITE_WRTCFG_DSTL_ONE_SHOT_INJ = 20;
static const uint32_t WRITE_WRTCFG_DSTL_PERSISTANT_INJ = 21;
static const uint32_t WRITE_WRTCFG_RESERVED_22_31 = 22;
static const uint32_t WRITE_WRTCFG_RESERVED_22_31_LEN = 10;
// mcc/reg00009.H

static const uint64_t WRITE_WRT_WDF_ECC = 0x0c010f49ull;

static const uint32_t WRITE_WRT_WDF_ECC_0_ERR_TYPE = 0;
static const uint32_t WRITE_WRT_WDF_ECC_0_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_0_SYNDROME = 8;
static const uint32_t WRITE_WRT_WDF_ECC_0_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_WDF_ECC_1_ERR_TYPE = 16;
static const uint32_t WRITE_WRT_WDF_ECC_1_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_1_SYNDROME = 24;
static const uint32_t WRITE_WRT_WDF_ECC_1_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_WDF_ECC_2_ERR_TYPE = 32;
static const uint32_t WRITE_WRT_WDF_ECC_2_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_2_SYNDROME = 40;
static const uint32_t WRITE_WRT_WDF_ECC_2_SYNDROME_LEN = 8;
static const uint32_t WRITE_WRT_WDF_ECC_3_ERR_TYPE = 48;
static const uint32_t WRITE_WRT_WDF_ECC_3_ERR_TYPE_LEN = 3;
static const uint32_t WRITE_WRT_WDF_ECC_3_SYNDROME = 56;
static const uint32_t WRITE_WRT_WDF_ECC_3_SYNDROME_LEN = 8;
// mcc/reg00009.H

}
}
#include "mcc/reg00009.H"
#endif
