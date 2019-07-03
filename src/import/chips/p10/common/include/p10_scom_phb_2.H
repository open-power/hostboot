/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_2.H $        */
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

#ifndef __p10_scom_phb_2_H_
#define __p10_scom_phb_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


static const uint64_t REGS_CERR_RPT0_REG = 0x0301184aull;

static const uint32_t REGS_CERR_RPT0_REG_CERR_RPT0 = 0;
static const uint32_t REGS_CERR_RPT0_REG_CERR_RPT0_LEN = 64;
// phb/reg00002.H

static const uint64_t REGS_CERR_RPT1_REG = 0x0301184bull;

static const uint32_t REGS_CERR_RPT1_REG_CERR_RPT1 = 0;
static const uint32_t REGS_CERR_RPT1_REG_CERR_RPT1_LEN = 41;
// phb/reg00002.H

static const uint64_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL = 0x08010905ull;

static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// phb/reg00002.H

#ifndef __PPE_HCODE__
}
}
#include "phb/reg00002.H"
#endif
#endif
