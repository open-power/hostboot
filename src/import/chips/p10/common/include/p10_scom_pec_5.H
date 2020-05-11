/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_5.H $        */
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

#ifndef __p10_scom_pec_5_H_
#define __p10_scom_pec_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [NET_CTRL1]
static const uint64_t NET_CTRL1_RW = 0x080f0044ull;
static const uint64_t NET_CTRL1_RW_WAND = 0x080f0045ull;
static const uint64_t NET_CTRL1_RW_WOR = 0x080f0046ull;

static const uint32_t NET_CTRL1_CACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t NET_CTRL1_CACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t NET_CTRL1_CACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t NET_CTRL1_CACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t NET_CTRL1_CORE0_CLK_DCC_BYPASS = 4;
static const uint32_t NET_CTRL1_CORE1_CLK_DCC_BYPASS = 5;
static const uint32_t NET_CTRL1_CORE2_CLK_DCC_BYPASS = 6;
static const uint32_t NET_CTRL1_CORE3_CLK_DCC_BYPASS = 7;
static const uint32_t NET_CTRL1_CACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t NET_CTRL1_CACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t NET_CTRL1_CACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t NET_CTRL1_CACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t NET_CTRL1_CORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t NET_CTRL1_CORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t NET_CTRL1_CORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t NET_CTRL1_CORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC = 23;
static const uint32_t NET_CTRL1_PCB_ACCESS = 24;
static const uint32_t NET_CTRL1_PCB_ACCESS_LEN = 8;
//<< [NET_CTRL1]
// pec/reg00005.H

//>> [PB_PBCQ_PEPBREGS_NESTTRC_REG]
static const uint64_t PB_PBCQ_PEPBREGS_NESTTRC_REG = 0x03011803ull;

static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A = 0;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_A_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B = 4;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_B_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C = 8;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_C_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D = 12;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_TRACE_MUX_SEL_D_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_NESTTRC_REG_PE_TRACE_ENABLE = 16;
//<< [PB_PBCQ_PEPBREGS_NESTTRC_REG]
// pec/reg00005.H

//>> [SCAN_LONG_ROTATE]
static const uint64_t SCAN_LONG_ROTATE = 0x08039000ull;
//<< [SCAN_LONG_ROTATE]
// pec/reg00005.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00005.H"
#endif
#endif
