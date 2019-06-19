/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_6.H $       */
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

#ifndef __p10_scom_nmmu_6_H_
#define __p10_scom_nmmu_6_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW = 0x02010c00ull;
static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND = 0x02010c01ull;
static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR = 0x02010c02ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR = 1;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR = 3;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR = 5;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR = 6;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR = 7;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR = 8;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR = 9;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR = 10;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR = 11;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR = 12;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR = 13;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR = 14;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR = 15;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR = 17;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR = 18;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR = 19;
// nmmu/reg00006.H

}
}
#ifndef __PPE_HCODE__
    #include "nmmu/reg00006.H"
#endif
#endif
