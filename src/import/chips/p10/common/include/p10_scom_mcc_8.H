/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_8.H $        */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_mcc_8_H_
#define __p10_scom_mcc_8_H_


namespace scomt
{
namespace mcc
{


static const uint64_t ATCL_CL_CLSCOM_MCEPSQ = 0x0c010c26ull;

static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON = 0;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON = 16;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON = 24;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON = 32;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON = 40;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON = 48;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON_LEN = 8;
// mcc/reg00008.H

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY2B = 0x0c010f5dull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
// mcc/reg00008.H

static const uint64_t CRYPTO_ENCRYPT_CRYPTOCFG = 0x0c010f50ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE = 4;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT = 5;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 = 6;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11_LEN = 6;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ = 12;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ = 14;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ = 16;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ = 18;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ = 20;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ = 21;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ = 22;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ = 23;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ = 24;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ = 25;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE = 26;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE_LEN = 6;
// mcc/reg00008.H

static const uint64_t USTL_USTLBADRESP = 0x0c010e10ull;

static const uint32_t USTL_USTLBADRESP_A_BAD_RESP_VAL = 0;
static const uint32_t USTL_USTLBADRESP_A_BAD_RESP_IS_WRITE = 1;
static const uint32_t USTL_USTLBADRESP_A_BAD_RESP_IS_GOOD = 2;
static const uint32_t USTL_USTLBADRESP_A_BAD_RESP_TAG = 3;
static const uint32_t USTL_USTLBADRESP_A_BAD_RESP_TAG_LEN = 6;
static const uint32_t USTL_USTLBADRESP_B_BAD_RESP_VAL = 9;
static const uint32_t USTL_USTLBADRESP_B_BAD_RESP_IS_WRITE = 10;
static const uint32_t USTL_USTLBADRESP_B_BAD_RESP_IS_GOOD = 11;
static const uint32_t USTL_USTLBADRESP_B_BAD_RESP_TAG = 12;
static const uint32_t USTL_USTLBADRESP_B_BAD_RESP_TAG_LEN = 6;
// mcc/reg00008.H

static const uint64_t USTL_USTLERRPT = 0x0c010e16ull;

static const uint32_t USTL_USTLERRPT_WDF_CMT_PAR_ERR = 0;
static const uint32_t USTL_USTLERRPT_WDF_CMD_PAR_ERR = 1;
static const uint32_t USTL_USTLERRPT_WDF_BUFF_MGR_PAR_ERR = 2;
static const uint32_t USTL_USTLERRPT_WDF_NO_BUFF_ERR = 3;
static const uint32_t USTL_USTLERRPT_WDF_DSTL_WB_READ_TAG_PAR_ERR = 4;
static const uint32_t USTL_USTLERRPT_WRT_NO_BUFF_ERR = 5;
static const uint32_t USTL_USTLERRPT_WRT_BUFF_MGR_PAR_ERR = 6;
static const uint32_t USTL_USTLERRPT_WRT_MCS_SLICE0_WRITE_DISP_PAR_ERR = 7;
static const uint32_t USTL_USTLERRPT_WRT_MCS_SLICE1_WRITE_DISP_PAR_ERR = 8;
static const uint32_t USTL_USTLERRPT_WRT_MCS_SLICE2_WRITE_DISP_PAR_ERR = 9;
static const uint32_t USTL_USTLERRPT_WRT_MCS_SLICE3_WRITE_DISP_PAR_ERR = 10;
static const uint32_t USTL_USTLERRPT_WRT_MCS_WB_DONE_PAR_ERR = 11;
static const uint32_t USTL_USTLERRPT_WRT_DSTL_WB_READ_TAG_PAR_ERR = 12;
static const uint32_t USTL_USTLERRPT_RESERVED = 13;
static const uint32_t USTL_USTLERRPT_RESERVED_LEN = 3;
// mcc/reg00008.H

static const uint64_t USTL_USTLFIRACT0 = 0x0c010e06ull;

static const uint32_t USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
// mcc/reg00008.H

static const uint64_t USTL_USTLSTATUS = 0x0c010e0aull;

static const uint32_t USTL_USTLSTATUS_CHANA_LOL_MODE = 0;
static const uint32_t USTL_USTLSTATUS_CHANB_LOL_MODE = 1;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_RD = 2;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_RESP_CNFGMMIO_WR = 3;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_RD = 4;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_RESP_MEM_WR = 5;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_RD = 6;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_RESP_CNFGMMIO_WR = 7;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_RD = 8;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_RESP_MEM_WR = 9;
static const uint32_t USTL_USTLSTATUS_FAIL_RESP = 10;
static const uint32_t USTL_USTLSTATUS_FAIL_RESP_LEN = 4;
static const uint32_t USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS = 20;
static const uint32_t USTL_USTLSTATUS_CHANA_LANE_WIDTH_STATUS_LEN = 2;
static const uint32_t USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS = 22;
static const uint32_t USTL_USTLSTATUS_CHANB_LANE_WIDTH_STATUS_LEN = 2;
static const uint32_t USTL_USTLSTATUS_CHANA_WAT_FIRED = 24;
static const uint32_t USTL_USTLSTATUS_CHANB_WAT_FIRED = 25;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_RD_RETRY = 32;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_MEM_RD_DATA_ERROR = 33;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_MEM_WR_DATA_ERROR = 34;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_CNFG_RD_DATA_ERROR = 35;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_CNFG_WR_DATA_ERROR = 36;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_BAD_LEN_ADDR = 37;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 38;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_MEM_RDWR_RESP = 39;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_CNFG_RDWR_RESP = 40;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_UNDEFINED_CODE = 41;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_WR_RETRY = 42;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_RD_RETRY = 43;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_MEM_RD_DATA_ERROR = 44;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_MEM_WR_DATA_ERROR = 45;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_CNFG_RD_DATA_ERROR = 46;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_CNFG_WR_DATA_ERROR = 47;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_BAD_LEN_ADDR = 48;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_BAD_LEN_ADDR = 49;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_MEM_RDWR_RESP = 50;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_CNFG_RDWR_RESP = 51;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_UNDEFINED_CODE = 52;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_WR_RETRY = 53;
static const uint32_t USTL_USTLSTATUS_CHANA_FAIL_MEM_CNTL = 54;
static const uint32_t USTL_USTLSTATUS_CHANB_FAIL_MEM_CNTL = 55;
// mcc/reg00008.H

static const uint64_t WDF_WDFDBG = 0x0c010f44ull;

static const uint32_t WDF_WDFDBG_DBG_SPARE = 0;
static const uint32_t WDF_WDFDBG_DBG_SPARE_LEN = 32;
static const uint32_t WDF_WDFDBG_WAT_EVENT_ENABLE = 32;
static const uint32_t WDF_WDFDBG_WAT_SPARE1 = 33;
static const uint32_t WDF_WDFDBG_WAT_SPARE1_LEN = 3;
static const uint32_t WDF_WDFDBG_WAT0_EVENT_SELECT = 36;
static const uint32_t WDF_WDFDBG_WAT0_EVENT_SELECT_LEN = 4;
static const uint32_t WDF_WDFDBG_WAT1_EVENT_SELECT = 40;
static const uint32_t WDF_WDFDBG_WAT1_EVENT_SELECT_LEN = 4;
// mcc/reg00008.H

}
}
#ifndef __PPE_HCODE__
    #include "mcc/reg00008.H"
#endif
#endif
