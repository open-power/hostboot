/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_f.H $        */
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

#ifndef __p10_scom_mcc_f_H_
#define __p10_scom_mcc_f_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCEBUSCL = 0x0c010c39ull;

static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 = 0;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 = 2;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA = 4;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB = 5;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7 = 6;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_7_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHA_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB = 16;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHB_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC = 24;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_LAT_THRESHC_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35 = 32;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED32_35_LEN = 4;
// mcc/reg00079.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEB = 0x0c010f7full;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN = 17;
// mcc/reg00079.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEA = 0x0c010f76ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
// mcc/reg00079.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MC_OMI_FIR_REG_ = 0x0c011b40ull;

static const uint32_t MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// mcc/reg00079.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLLOLDROP = 0x0c010e11ull;

static const uint32_t USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t USTL_USTLLOLDROP_A_DROP_REASON_LEN = 16;
static const uint32_t USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t USTL_USTLLOLDROP_B_DROP_REASON_LEN = 16;
// mcc/reg00079.H

}
}
#include "mcc/reg00079.H"
#endif
