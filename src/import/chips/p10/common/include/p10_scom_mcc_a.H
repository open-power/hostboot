/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_a.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_mcc_a_H_
#define __p10_scom_mcc_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [ATCL_CL_CLSCOM_MCERRINJ]
static const uint64_t ATCL_CL_CLSCOM_MCERRINJ = 0x0c010c28ull;

static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ = 0;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER = 7;
//<< [ATCL_CL_CLSCOM_MCERRINJ]
// mcc/reg00010.H

//>> [DSTL_DSTLERRRPT]
static const uint64_t DSTL_DSTLERRRPT = 0x0c010d0cull;

static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 0;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 1;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT = 2;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT = 3;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 4;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT = 5;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT = 6;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT = 7;
static const uint32_t DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT = 8;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT = 9;
static const uint32_t DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT = 10;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT = 11;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT = 12;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT = 13;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT = 14;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT = 15;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT = 16;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT = 17;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT = 18;
static const uint32_t DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT = 19;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT = 20;
static const uint32_t DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT = 21;
static const uint32_t DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT = 22;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT = 23;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT = 24;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT = 25;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT = 26;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT = 27;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT = 28;
static const uint32_t DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT = 29;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT = 30;
static const uint32_t DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT = 31;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT = 32;
static const uint32_t DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT = 33;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT = 34;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT = 35;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 36;
static const uint32_t DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT = 37;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 38;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT = 39;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT = 40;
static const uint32_t DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT = 41;
static const uint32_t DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT = 42;
static const uint32_t DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT = 43;
static const uint32_t DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT = 44;
static const uint32_t DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT = 45;
static const uint32_t DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE = 62;
static const uint32_t DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE = 63;
//<< [DSTL_DSTLERRRPT]
// mcc/reg00010.H

//>> [DSTL_DSTLFIRACT1]
static const uint64_t DSTL_DSTLFIRACT1 = 0x0c010d07ull;

static const uint32_t DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 = 0;
static const uint32_t DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN = 39;
//<< [DSTL_DSTLFIRACT1]
// mcc/reg00010.H

//>> [DSTL_DSTLFIRWOF]
static const uint64_t DSTL_DSTLFIRWOF = 0x0c010d08ull;

static const uint32_t DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF = 0;
static const uint32_t DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN = 39;
//<< [DSTL_DSTLFIRWOF]
// mcc/reg00010.H

//>> [DSTL_DSTLPSAVE0]
static const uint64_t DSTL_DSTLPSAVE0 = 0x0c010d12ull;

static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE = 0;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH = 2;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE = 5;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT = 8;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE = 16;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH = 18;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE = 21;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT = 24;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL = 32;
static const uint32_t DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL = 36;
static const uint32_t DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN = 4;
static const uint32_t DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN = 40;
static const uint32_t DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE = 41;
static const uint32_t DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE0_RESERVED_43_47 = 43;
static const uint32_t DSTL_DSTLPSAVE0_RESERVED_43_47_LEN = 5;
//<< [DSTL_DSTLPSAVE0]
// mcc/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00010.H"
#endif
#endif
