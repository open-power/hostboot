/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9n2_perv_scom_addresses.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file p9_perv_scom_addresses.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 3
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

/*---------------------------------------------------------------
 *
 *---------------------------------------------------------------
 *
 *---------------------------------------------------------------
 */

#ifndef __P9N2_PERV_SCOM_ADDRESSES_H
#define __P9N2_PERV_SCOM_ADDRESSES_H

#include <stdint.h>

static const uint64_t P9N2_PERV_ADDR_TRAP_REG                                      = 0x00010003ull;

static const uint64_t P9N2_PERV_TP_ADDR_TRAP_REG                                   = 0x01010003ull;


static const uint64_t P9N2_PERV_ASSIST_INTERRUPT_REG                               = 0x000F0011ull;

static const uint64_t P9N2_PERV_TP_ASSIST_INTERRUPT_REG                            = 0x010F0011ull;

static const uint64_t P9N2_PERV_N0_ASSIST_INTERRUPT_REG                            = 0x020F0011ull;

static const uint64_t P9N2_PERV_N1_ASSIST_INTERRUPT_REG                            = 0x030F0011ull;

static const uint64_t P9N2_PERV_N2_ASSIST_INTERRUPT_REG                            = 0x040F0011ull;

static const uint64_t P9N2_PERV_N3_ASSIST_INTERRUPT_REG                            = 0x050F0011ull;

static const uint64_t P9N2_PERV_XB_ASSIST_INTERRUPT_REG                            = 0x060F0011ull;

static const uint64_t P9N2_PERV_MC01_ASSIST_INTERRUPT_REG                          = 0x070F0011ull;

static const uint64_t P9N2_PERV_MC23_ASSIST_INTERRUPT_REG                          = 0x080F0011ull;

static const uint64_t P9N2_PERV_OB0_ASSIST_INTERRUPT_REG                           = 0x090F0011ull;

static const uint64_t P9N2_PERV_OB3_ASSIST_INTERRUPT_REG                           = 0x0C0F0011ull;

static const uint64_t P9N2_PERV_PCI0_ASSIST_INTERRUPT_REG                          = 0x0D0F0011ull;

static const uint64_t P9N2_PERV_PCI1_ASSIST_INTERRUPT_REG                          = 0x0E0F0011ull;

static const uint64_t P9N2_PERV_PCI2_ASSIST_INTERRUPT_REG                          = 0x0F0F0011ull;

static const uint64_t P9N2_PERV_EP00_ASSIST_INTERRUPT_REG                          = 0x100F0011ull;

static const uint64_t P9N2_PERV_EP01_ASSIST_INTERRUPT_REG                          = 0x110F0011ull;

static const uint64_t P9N2_PERV_EP02_ASSIST_INTERRUPT_REG                          = 0x120F0011ull;

static const uint64_t P9N2_PERV_EP03_ASSIST_INTERRUPT_REG                          = 0x130F0011ull;

static const uint64_t P9N2_PERV_EP04_ASSIST_INTERRUPT_REG                          = 0x140F0011ull;

static const uint64_t P9N2_PERV_EP05_ASSIST_INTERRUPT_REG                          = 0x150F0011ull;

static const uint64_t P9N2_PERV_EC00_ASSIST_INTERRUPT_REG                          = 0x200F0011ull;

static const uint64_t P9N2_PERV_EC01_ASSIST_INTERRUPT_REG                          = 0x210F0011ull;

static const uint64_t P9N2_PERV_EC02_ASSIST_INTERRUPT_REG                          = 0x220F0011ull;

static const uint64_t P9N2_PERV_EC03_ASSIST_INTERRUPT_REG                          = 0x230F0011ull;

static const uint64_t P9N2_PERV_EC04_ASSIST_INTERRUPT_REG                          = 0x240F0011ull;

static const uint64_t P9N2_PERV_EC05_ASSIST_INTERRUPT_REG                          = 0x250F0011ull;

static const uint64_t P9N2_PERV_EC06_ASSIST_INTERRUPT_REG                          = 0x260F0011ull;

static const uint64_t P9N2_PERV_EC07_ASSIST_INTERRUPT_REG                          = 0x270F0011ull;

static const uint64_t P9N2_PERV_EC08_ASSIST_INTERRUPT_REG                          = 0x280F0011ull;

static const uint64_t P9N2_PERV_EC09_ASSIST_INTERRUPT_REG                          = 0x290F0011ull;

static const uint64_t P9N2_PERV_EC10_ASSIST_INTERRUPT_REG                          = 0x2A0F0011ull;

static const uint64_t P9N2_PERV_EC11_ASSIST_INTERRUPT_REG                          = 0x2B0F0011ull;

static const uint64_t P9N2_PERV_EC12_ASSIST_INTERRUPT_REG                          = 0x2C0F0011ull;

static const uint64_t P9N2_PERV_EC13_ASSIST_INTERRUPT_REG                          = 0x2D0F0011ull;

static const uint64_t P9N2_PERV_EC14_ASSIST_INTERRUPT_REG                          = 0x2E0F0011ull;

static const uint64_t P9N2_PERV_EC15_ASSIST_INTERRUPT_REG                          = 0x2F0F0011ull;

static const uint64_t P9N2_PERV_EC16_ASSIST_INTERRUPT_REG                          = 0x300F0011ull;

static const uint64_t P9N2_PERV_EC17_ASSIST_INTERRUPT_REG                          = 0x310F0011ull;

static const uint64_t P9N2_PERV_EC18_ASSIST_INTERRUPT_REG                          = 0x320F0011ull;

static const uint64_t P9N2_PERV_EC19_ASSIST_INTERRUPT_REG                          = 0x330F0011ull;

static const uint64_t P9N2_PERV_EC20_ASSIST_INTERRUPT_REG                          = 0x340F0011ull;

static const uint64_t P9N2_PERV_EC21_ASSIST_INTERRUPT_REG                          = 0x350F0011ull;

static const uint64_t P9N2_PERV_EC22_ASSIST_INTERRUPT_REG                          = 0x360F0011ull;

static const uint64_t P9N2_PERV_EC23_ASSIST_INTERRUPT_REG                          = 0x370F0011ull;


static const uint64_t P9N2_PERV_ATOMIC_LOCK_MASK_LATCH_REG                         = 0x00010007ull;

static const uint64_t P9N2_PERV_TP_ATOMIC_LOCK_MASK_LATCH_REG                      = 0x01010007ull;


static const uint64_t P9N2_PERV_ATOMIC_LOCK_REG                                    = 0x000F03FFull;

static const uint64_t P9N2_PERV_TP_ATOMIC_LOCK_REG                                 = 0x010F03FFull;

static const uint64_t P9N2_PERV_N0_ATOMIC_LOCK_REG                                 = 0x020F03FFull;

static const uint64_t P9N2_PERV_N1_ATOMIC_LOCK_REG                                 = 0x030F03FFull;

static const uint64_t P9N2_PERV_N2_ATOMIC_LOCK_REG                                 = 0x040F03FFull;

static const uint64_t P9N2_PERV_N3_ATOMIC_LOCK_REG                                 = 0x050F03FFull;

static const uint64_t P9N2_PERV_XB_ATOMIC_LOCK_REG                                 = 0x060F03FFull;

static const uint64_t P9N2_PERV_MC01_ATOMIC_LOCK_REG                               = 0x070F03FFull;

static const uint64_t P9N2_PERV_MC23_ATOMIC_LOCK_REG                               = 0x080F03FFull;

static const uint64_t P9N2_PERV_OB0_ATOMIC_LOCK_REG                                = 0x090F03FFull;

static const uint64_t P9N2_PERV_OB3_ATOMIC_LOCK_REG                                = 0x0C0F03FFull;

static const uint64_t P9N2_PERV_PCI0_ATOMIC_LOCK_REG                               = 0x0D0F03FFull;

static const uint64_t P9N2_PERV_PCI1_ATOMIC_LOCK_REG                               = 0x0E0F03FFull;

static const uint64_t P9N2_PERV_PCI2_ATOMIC_LOCK_REG                               = 0x0F0F03FFull;

static const uint64_t P9N2_PERV_EP00_ATOMIC_LOCK_REG                               = 0x100F03FFull;

static const uint64_t P9N2_PERV_EP01_ATOMIC_LOCK_REG                               = 0x110F03FFull;

static const uint64_t P9N2_PERV_EP02_ATOMIC_LOCK_REG                               = 0x120F03FFull;

static const uint64_t P9N2_PERV_EP03_ATOMIC_LOCK_REG                               = 0x130F03FFull;

static const uint64_t P9N2_PERV_EP04_ATOMIC_LOCK_REG                               = 0x140F03FFull;

static const uint64_t P9N2_PERV_EP05_ATOMIC_LOCK_REG                               = 0x150F03FFull;

static const uint64_t P9N2_PERV_EC00_ATOMIC_LOCK_REG                               = 0x200F03FFull;

static const uint64_t P9N2_PERV_EC01_ATOMIC_LOCK_REG                               = 0x210F03FFull;

static const uint64_t P9N2_PERV_EC02_ATOMIC_LOCK_REG                               = 0x220F03FFull;

static const uint64_t P9N2_PERV_EC03_ATOMIC_LOCK_REG                               = 0x230F03FFull;

static const uint64_t P9N2_PERV_EC04_ATOMIC_LOCK_REG                               = 0x240F03FFull;

static const uint64_t P9N2_PERV_EC05_ATOMIC_LOCK_REG                               = 0x250F03FFull;

static const uint64_t P9N2_PERV_EC06_ATOMIC_LOCK_REG                               = 0x260F03FFull;

static const uint64_t P9N2_PERV_EC07_ATOMIC_LOCK_REG                               = 0x270F03FFull;

static const uint64_t P9N2_PERV_EC08_ATOMIC_LOCK_REG                               = 0x280F03FFull;

static const uint64_t P9N2_PERV_EC09_ATOMIC_LOCK_REG                               = 0x290F03FFull;

static const uint64_t P9N2_PERV_EC10_ATOMIC_LOCK_REG                               = 0x2A0F03FFull;

static const uint64_t P9N2_PERV_EC11_ATOMIC_LOCK_REG                               = 0x2B0F03FFull;

static const uint64_t P9N2_PERV_EC12_ATOMIC_LOCK_REG                               = 0x2C0F03FFull;

static const uint64_t P9N2_PERV_EC13_ATOMIC_LOCK_REG                               = 0x2D0F03FFull;

static const uint64_t P9N2_PERV_EC14_ATOMIC_LOCK_REG                               = 0x2E0F03FFull;

static const uint64_t P9N2_PERV_EC15_ATOMIC_LOCK_REG                               = 0x2F0F03FFull;

static const uint64_t P9N2_PERV_EC16_ATOMIC_LOCK_REG                               = 0x300F03FFull;

static const uint64_t P9N2_PERV_EC17_ATOMIC_LOCK_REG                               = 0x310F03FFull;

static const uint64_t P9N2_PERV_EC18_ATOMIC_LOCK_REG                               = 0x320F03FFull;

static const uint64_t P9N2_PERV_EC19_ATOMIC_LOCK_REG                               = 0x330F03FFull;

static const uint64_t P9N2_PERV_EC20_ATOMIC_LOCK_REG                               = 0x340F03FFull;

static const uint64_t P9N2_PERV_EC21_ATOMIC_LOCK_REG                               = 0x350F03FFull;

static const uint64_t P9N2_PERV_EC22_ATOMIC_LOCK_REG                               = 0x360F03FFull;

static const uint64_t P9N2_PERV_EC23_ATOMIC_LOCK_REG                               = 0x370F03FFull;


static const uint64_t P9N2_PERV_ATTN_INTERRUPT_REG                                 = 0x000F001Aull;

static const uint64_t P9N2_PERV_TP_ATTN_INTERRUPT_REG                              = 0x010F001Aull;

static const uint64_t P9N2_PERV_N0_ATTN_INTERRUPT_REG                              = 0x020F001Aull;

static const uint64_t P9N2_PERV_N1_ATTN_INTERRUPT_REG                              = 0x030F001Aull;

static const uint64_t P9N2_PERV_N2_ATTN_INTERRUPT_REG                              = 0x040F001Aull;

static const uint64_t P9N2_PERV_N3_ATTN_INTERRUPT_REG                              = 0x050F001Aull;

static const uint64_t P9N2_PERV_XB_ATTN_INTERRUPT_REG                              = 0x060F001Aull;

static const uint64_t P9N2_PERV_MC01_ATTN_INTERRUPT_REG                            = 0x070F001Aull;

static const uint64_t P9N2_PERV_MC23_ATTN_INTERRUPT_REG                            = 0x080F001Aull;

static const uint64_t P9N2_PERV_OB0_ATTN_INTERRUPT_REG                             = 0x090F001Aull;

static const uint64_t P9N2_PERV_OB3_ATTN_INTERRUPT_REG                             = 0x0C0F001Aull;

static const uint64_t P9N2_PERV_PCI0_ATTN_INTERRUPT_REG                            = 0x0D0F001Aull;

static const uint64_t P9N2_PERV_PCI1_ATTN_INTERRUPT_REG                            = 0x0E0F001Aull;

static const uint64_t P9N2_PERV_PCI2_ATTN_INTERRUPT_REG                            = 0x0F0F001Aull;

static const uint64_t P9N2_PERV_EP00_ATTN_INTERRUPT_REG                            = 0x100F001Aull;

static const uint64_t P9N2_PERV_EP01_ATTN_INTERRUPT_REG                            = 0x110F001Aull;

static const uint64_t P9N2_PERV_EP02_ATTN_INTERRUPT_REG                            = 0x120F001Aull;

static const uint64_t P9N2_PERV_EP03_ATTN_INTERRUPT_REG                            = 0x130F001Aull;

static const uint64_t P9N2_PERV_EP04_ATTN_INTERRUPT_REG                            = 0x140F001Aull;

static const uint64_t P9N2_PERV_EP05_ATTN_INTERRUPT_REG                            = 0x150F001Aull;

static const uint64_t P9N2_PERV_EC00_ATTN_INTERRUPT_REG                            = 0x200F001Aull;

static const uint64_t P9N2_PERV_EC01_ATTN_INTERRUPT_REG                            = 0x210F001Aull;

static const uint64_t P9N2_PERV_EC02_ATTN_INTERRUPT_REG                            = 0x220F001Aull;

static const uint64_t P9N2_PERV_EC03_ATTN_INTERRUPT_REG                            = 0x230F001Aull;

static const uint64_t P9N2_PERV_EC04_ATTN_INTERRUPT_REG                            = 0x240F001Aull;

static const uint64_t P9N2_PERV_EC05_ATTN_INTERRUPT_REG                            = 0x250F001Aull;

static const uint64_t P9N2_PERV_EC06_ATTN_INTERRUPT_REG                            = 0x260F001Aull;

static const uint64_t P9N2_PERV_EC07_ATTN_INTERRUPT_REG                            = 0x270F001Aull;

static const uint64_t P9N2_PERV_EC08_ATTN_INTERRUPT_REG                            = 0x280F001Aull;

static const uint64_t P9N2_PERV_EC09_ATTN_INTERRUPT_REG                            = 0x290F001Aull;

static const uint64_t P9N2_PERV_EC10_ATTN_INTERRUPT_REG                            = 0x2A0F001Aull;

static const uint64_t P9N2_PERV_EC11_ATTN_INTERRUPT_REG                            = 0x2B0F001Aull;

static const uint64_t P9N2_PERV_EC12_ATTN_INTERRUPT_REG                            = 0x2C0F001Aull;

static const uint64_t P9N2_PERV_EC13_ATTN_INTERRUPT_REG                            = 0x2D0F001Aull;

static const uint64_t P9N2_PERV_EC14_ATTN_INTERRUPT_REG                            = 0x2E0F001Aull;

static const uint64_t P9N2_PERV_EC15_ATTN_INTERRUPT_REG                            = 0x2F0F001Aull;

static const uint64_t P9N2_PERV_EC16_ATTN_INTERRUPT_REG                            = 0x300F001Aull;

static const uint64_t P9N2_PERV_EC17_ATTN_INTERRUPT_REG                            = 0x310F001Aull;

static const uint64_t P9N2_PERV_EC18_ATTN_INTERRUPT_REG                            = 0x320F001Aull;

static const uint64_t P9N2_PERV_EC19_ATTN_INTERRUPT_REG                            = 0x330F001Aull;

static const uint64_t P9N2_PERV_EC20_ATTN_INTERRUPT_REG                            = 0x340F001Aull;

static const uint64_t P9N2_PERV_EC21_ATTN_INTERRUPT_REG                            = 0x350F001Aull;

static const uint64_t P9N2_PERV_EC22_ATTN_INTERRUPT_REG                            = 0x360F001Aull;

static const uint64_t P9N2_PERV_EC23_ATTN_INTERRUPT_REG                            = 0x370F001Aull;


static const uint64_t P9N2_PERV_BIST                                               = 0x0003000Bull;

static const uint64_t P9N2_PERV_TP_BIST                                            = 0x0103000Bull;

static const uint64_t P9N2_PERV_N0_BIST                                            = 0x0203000Bull;

static const uint64_t P9N2_PERV_N1_BIST                                            = 0x0303000Bull;

static const uint64_t P9N2_PERV_N2_BIST                                            = 0x0403000Bull;

static const uint64_t P9N2_PERV_N3_BIST                                            = 0x0503000Bull;

static const uint64_t P9N2_PERV_XB_BIST                                            = 0x0603000Bull;

static const uint64_t P9N2_PERV_MC01_BIST                                          = 0x0703000Bull;

static const uint64_t P9N2_PERV_MC23_BIST                                          = 0x0803000Bull;

static const uint64_t P9N2_PERV_OB0_BIST                                           = 0x0903000Bull;

static const uint64_t P9N2_PERV_OB3_BIST                                           = 0x0C03000Bull;

static const uint64_t P9N2_PERV_PCI0_BIST                                          = 0x0D03000Bull;

static const uint64_t P9N2_PERV_PCI1_BIST                                          = 0x0E03000Bull;

static const uint64_t P9N2_PERV_PCI2_BIST                                          = 0x0F03000Bull;

static const uint64_t P9N2_PERV_EP00_BIST                                          = 0x1003000Bull;

static const uint64_t P9N2_PERV_EP01_BIST                                          = 0x1103000Bull;

static const uint64_t P9N2_PERV_EP02_BIST                                          = 0x1203000Bull;

static const uint64_t P9N2_PERV_EP03_BIST                                          = 0x1303000Bull;

static const uint64_t P9N2_PERV_EP04_BIST                                          = 0x1403000Bull;

static const uint64_t P9N2_PERV_EP05_BIST                                          = 0x1503000Bull;

static const uint64_t P9N2_PERV_EC00_BIST                                          = 0x2003000Bull;

static const uint64_t P9N2_PERV_EC01_BIST                                          = 0x2103000Bull;

static const uint64_t P9N2_PERV_EC02_BIST                                          = 0x2203000Bull;

static const uint64_t P9N2_PERV_EC03_BIST                                          = 0x2303000Bull;

static const uint64_t P9N2_PERV_EC04_BIST                                          = 0x2403000Bull;

static const uint64_t P9N2_PERV_EC05_BIST                                          = 0x2503000Bull;

static const uint64_t P9N2_PERV_EC06_BIST                                          = 0x2603000Bull;

static const uint64_t P9N2_PERV_EC07_BIST                                          = 0x2703000Bull;

static const uint64_t P9N2_PERV_EC08_BIST                                          = 0x2803000Bull;

static const uint64_t P9N2_PERV_EC09_BIST                                          = 0x2903000Bull;

static const uint64_t P9N2_PERV_EC10_BIST                                          = 0x2A03000Bull;

static const uint64_t P9N2_PERV_EC11_BIST                                          = 0x2B03000Bull;

static const uint64_t P9N2_PERV_EC12_BIST                                          = 0x2C03000Bull;

static const uint64_t P9N2_PERV_EC13_BIST                                          = 0x2D03000Bull;

static const uint64_t P9N2_PERV_EC14_BIST                                          = 0x2E03000Bull;

static const uint64_t P9N2_PERV_EC15_BIST                                          = 0x2F03000Bull;

static const uint64_t P9N2_PERV_EC16_BIST                                          = 0x3003000Bull;

static const uint64_t P9N2_PERV_EC17_BIST                                          = 0x3103000Bull;

static const uint64_t P9N2_PERV_EC18_BIST                                          = 0x3203000Bull;

static const uint64_t P9N2_PERV_EC19_BIST                                          = 0x3303000Bull;

static const uint64_t P9N2_PERV_EC20_BIST                                          = 0x3403000Bull;

static const uint64_t P9N2_PERV_EC21_BIST                                          = 0x3503000Bull;

static const uint64_t P9N2_PERV_EC22_BIST                                          = 0x3603000Bull;

static const uint64_t P9N2_PERV_EC23_BIST                                          = 0x3703000Bull;


static const uint64_t P9N2_PERV_BIT_SEL_REG_2                                      = 0x000F0008ull;

static const uint64_t P9N2_PERV_PIB_BIT_SEL_REG_2                                  = 0x000F0008ull;


static const uint32_t P9N2_PERV_CBS_CS_FSI                                         = 0x00002801ull;

static const uint32_t P9N2_PERV_CBS_CS_FSI_BYTE                                    = 0x00002804ull;

static const uint64_t P9N2_PERV_CBS_CS_SCOM                                        = 0x00050001ull;

static const uint64_t P9N2_PERV_PIB_CBS_CS                                         = 0x00050001ull;


static const uint32_t P9N2_PERV_CBS_EL_FSI                                         = 0x00002803ull;

static const uint32_t P9N2_PERV_CBS_EL_FSI_BYTE                                    = 0x0000280Cull;

static const uint64_t P9N2_PERV_CBS_EL_SCOM                                        = 0x00050003ull;

static const uint64_t P9N2_PERV_PIB_CBS_EL                                         = 0x00050003ull;


static const uint32_t P9N2_PERV_CBS_EL_HIST_FSI                                    = 0x00002806ull;

static const uint32_t P9N2_PERV_CBS_EL_HIST_FSI_BYTE                               = 0x00002818ull;

static const uint64_t P9N2_PERV_CBS_EL_HIST_SCOM                                   = 0x00050006ull;

static const uint64_t P9N2_PERV_PIB_CBS_EL_HIST                                    = 0x00050006ull;


static const uint32_t P9N2_PERV_CBS_ENVSTAT_FSI                                    = 0x00002804ull;

static const uint32_t P9N2_PERV_CBS_ENVSTAT_FSI_BYTE                               = 0x00002810ull;

static const uint64_t P9N2_PERV_CBS_ENVSTAT_SCOM                                   = 0x00050004ull;

static const uint64_t P9N2_PERV_PIB_CBS_ENVSTAT                                    = 0x00050004ull;


static const uint32_t P9N2_PERV_CBS_STAT_FSI                                       = 0x0000280Bull;

static const uint32_t P9N2_PERV_CBS_STAT_FSI_BYTE                                  = 0x0000282Cull;

static const uint64_t P9N2_PERV_CBS_STAT_SCOM                                      = 0x0005000Bull;

static const uint64_t P9N2_PERV_PIB_CBS_STAT                                       = 0x0005000Bull;


static const uint32_t P9N2_PERV_CBS_TR_FSI                                         = 0x00002802ull;

static const uint32_t P9N2_PERV_CBS_TR_FSI_BYTE                                    = 0x00002808ull;

static const uint64_t P9N2_PERV_CBS_TR_SCOM                                        = 0x00050002ull;

static const uint64_t P9N2_PERV_PIB_CBS_TR                                         = 0x00050002ull;


static const uint32_t P9N2_PERV_CBS_TR_HIST_FSI                                    = 0x00002805ull;

static const uint32_t P9N2_PERV_CBS_TR_HIST_FSI_BYTE                               = 0x00002814ull;

static const uint64_t P9N2_PERV_CBS_TR_HIST_SCOM                                   = 0x00050005ull;

static const uint64_t P9N2_PERV_PIB_CBS_TR_HIST                                    = 0x00050005ull;


static const uint64_t P9N2_PERV_CC_ATOMIC_LOCK_REG                                 = 0x000303FFull;

static const uint64_t P9N2_PERV_TP_CC_ATOMIC_LOCK_REG                              = 0x010303FFull;

static const uint64_t P9N2_PERV_N0_CC_ATOMIC_LOCK_REG                              = 0x020303FFull;

static const uint64_t P9N2_PERV_N1_CC_ATOMIC_LOCK_REG                              = 0x030303FFull;

static const uint64_t P9N2_PERV_N2_CC_ATOMIC_LOCK_REG                              = 0x040303FFull;

static const uint64_t P9N2_PERV_N3_CC_ATOMIC_LOCK_REG                              = 0x050303FFull;

static const uint64_t P9N2_PERV_XB_CC_ATOMIC_LOCK_REG                              = 0x060303FFull;

static const uint64_t P9N2_PERV_MC01_CC_ATOMIC_LOCK_REG                            = 0x070303FFull;

static const uint64_t P9N2_PERV_MC23_CC_ATOMIC_LOCK_REG                            = 0x080303FFull;

static const uint64_t P9N2_PERV_OB0_CC_ATOMIC_LOCK_REG                             = 0x090303FFull;

static const uint64_t P9N2_PERV_OB3_CC_ATOMIC_LOCK_REG                             = 0x0C0303FFull;

static const uint64_t P9N2_PERV_PCI0_CC_ATOMIC_LOCK_REG                            = 0x0D0303FFull;

static const uint64_t P9N2_PERV_PCI1_CC_ATOMIC_LOCK_REG                            = 0x0E0303FFull;

static const uint64_t P9N2_PERV_PCI2_CC_ATOMIC_LOCK_REG                            = 0x0F0303FFull;

static const uint64_t P9N2_PERV_EP00_CC_ATOMIC_LOCK_REG                            = 0x100303FFull;

static const uint64_t P9N2_PERV_EP01_CC_ATOMIC_LOCK_REG                            = 0x110303FFull;

static const uint64_t P9N2_PERV_EP02_CC_ATOMIC_LOCK_REG                            = 0x120303FFull;

static const uint64_t P9N2_PERV_EP03_CC_ATOMIC_LOCK_REG                            = 0x130303FFull;

static const uint64_t P9N2_PERV_EP04_CC_ATOMIC_LOCK_REG                            = 0x140303FFull;

static const uint64_t P9N2_PERV_EP05_CC_ATOMIC_LOCK_REG                            = 0x150303FFull;

static const uint64_t P9N2_PERV_EC00_CC_ATOMIC_LOCK_REG                            = 0x200303FFull;

static const uint64_t P9N2_PERV_EC01_CC_ATOMIC_LOCK_REG                            = 0x210303FFull;

static const uint64_t P9N2_PERV_EC02_CC_ATOMIC_LOCK_REG                            = 0x220303FFull;

static const uint64_t P9N2_PERV_EC03_CC_ATOMIC_LOCK_REG                            = 0x230303FFull;

static const uint64_t P9N2_PERV_EC04_CC_ATOMIC_LOCK_REG                            = 0x240303FFull;

static const uint64_t P9N2_PERV_EC05_CC_ATOMIC_LOCK_REG                            = 0x250303FFull;

static const uint64_t P9N2_PERV_EC06_CC_ATOMIC_LOCK_REG                            = 0x260303FFull;

static const uint64_t P9N2_PERV_EC07_CC_ATOMIC_LOCK_REG                            = 0x270303FFull;

static const uint64_t P9N2_PERV_EC08_CC_ATOMIC_LOCK_REG                            = 0x280303FFull;

static const uint64_t P9N2_PERV_EC09_CC_ATOMIC_LOCK_REG                            = 0x290303FFull;

static const uint64_t P9N2_PERV_EC10_CC_ATOMIC_LOCK_REG                            = 0x2A0303FFull;

static const uint64_t P9N2_PERV_EC11_CC_ATOMIC_LOCK_REG                            = 0x2B0303FFull;

static const uint64_t P9N2_PERV_EC12_CC_ATOMIC_LOCK_REG                            = 0x2C0303FFull;

static const uint64_t P9N2_PERV_EC13_CC_ATOMIC_LOCK_REG                            = 0x2D0303FFull;

static const uint64_t P9N2_PERV_EC14_CC_ATOMIC_LOCK_REG                            = 0x2E0303FFull;

static const uint64_t P9N2_PERV_EC15_CC_ATOMIC_LOCK_REG                            = 0x2F0303FFull;

static const uint64_t P9N2_PERV_EC16_CC_ATOMIC_LOCK_REG                            = 0x300303FFull;

static const uint64_t P9N2_PERV_EC17_CC_ATOMIC_LOCK_REG                            = 0x310303FFull;

static const uint64_t P9N2_PERV_EC18_CC_ATOMIC_LOCK_REG                            = 0x320303FFull;

static const uint64_t P9N2_PERV_EC19_CC_ATOMIC_LOCK_REG                            = 0x330303FFull;

static const uint64_t P9N2_PERV_EC20_CC_ATOMIC_LOCK_REG                            = 0x340303FFull;

static const uint64_t P9N2_PERV_EC21_CC_ATOMIC_LOCK_REG                            = 0x350303FFull;

static const uint64_t P9N2_PERV_EC22_CC_ATOMIC_LOCK_REG                            = 0x360303FFull;

static const uint64_t P9N2_PERV_EC23_CC_ATOMIC_LOCK_REG                            = 0x370303FFull;


static const uint64_t P9N2_PERV_CC_PROTECT_MODE_REG                                = 0x000303FEull;

static const uint64_t P9N2_PERV_TP_CC_PROTECT_MODE_REG                             = 0x010303FEull;

static const uint64_t P9N2_PERV_N0_CC_PROTECT_MODE_REG                             = 0x020303FEull;

static const uint64_t P9N2_PERV_N1_CC_PROTECT_MODE_REG                             = 0x030303FEull;

static const uint64_t P9N2_PERV_N2_CC_PROTECT_MODE_REG                             = 0x040303FEull;

static const uint64_t P9N2_PERV_N3_CC_PROTECT_MODE_REG                             = 0x050303FEull;

static const uint64_t P9N2_PERV_XB_CC_PROTECT_MODE_REG                             = 0x060303FEull;

static const uint64_t P9N2_PERV_MC01_CC_PROTECT_MODE_REG                           = 0x070303FEull;

static const uint64_t P9N2_PERV_MC23_CC_PROTECT_MODE_REG                           = 0x080303FEull;

static const uint64_t P9N2_PERV_OB0_CC_PROTECT_MODE_REG                            = 0x090303FEull;

static const uint64_t P9N2_PERV_OB3_CC_PROTECT_MODE_REG                            = 0x0C0303FEull;

static const uint64_t P9N2_PERV_PCI0_CC_PROTECT_MODE_REG                           = 0x0D0303FEull;

static const uint64_t P9N2_PERV_PCI1_CC_PROTECT_MODE_REG                           = 0x0E0303FEull;

static const uint64_t P9N2_PERV_PCI2_CC_PROTECT_MODE_REG                           = 0x0F0303FEull;

static const uint64_t P9N2_PERV_EP00_CC_PROTECT_MODE_REG                           = 0x100303FEull;

static const uint64_t P9N2_PERV_EP01_CC_PROTECT_MODE_REG                           = 0x110303FEull;

static const uint64_t P9N2_PERV_EP02_CC_PROTECT_MODE_REG                           = 0x120303FEull;

static const uint64_t P9N2_PERV_EP03_CC_PROTECT_MODE_REG                           = 0x130303FEull;

static const uint64_t P9N2_PERV_EP04_CC_PROTECT_MODE_REG                           = 0x140303FEull;

static const uint64_t P9N2_PERV_EP05_CC_PROTECT_MODE_REG                           = 0x150303FEull;

static const uint64_t P9N2_PERV_EC00_CC_PROTECT_MODE_REG                           = 0x200303FEull;

static const uint64_t P9N2_PERV_EC01_CC_PROTECT_MODE_REG                           = 0x210303FEull;

static const uint64_t P9N2_PERV_EC02_CC_PROTECT_MODE_REG                           = 0x220303FEull;

static const uint64_t P9N2_PERV_EC03_CC_PROTECT_MODE_REG                           = 0x230303FEull;

static const uint64_t P9N2_PERV_EC04_CC_PROTECT_MODE_REG                           = 0x240303FEull;

static const uint64_t P9N2_PERV_EC05_CC_PROTECT_MODE_REG                           = 0x250303FEull;

static const uint64_t P9N2_PERV_EC06_CC_PROTECT_MODE_REG                           = 0x260303FEull;

static const uint64_t P9N2_PERV_EC07_CC_PROTECT_MODE_REG                           = 0x270303FEull;

static const uint64_t P9N2_PERV_EC08_CC_PROTECT_MODE_REG                           = 0x280303FEull;

static const uint64_t P9N2_PERV_EC09_CC_PROTECT_MODE_REG                           = 0x290303FEull;

static const uint64_t P9N2_PERV_EC10_CC_PROTECT_MODE_REG                           = 0x2A0303FEull;

static const uint64_t P9N2_PERV_EC11_CC_PROTECT_MODE_REG                           = 0x2B0303FEull;

static const uint64_t P9N2_PERV_EC12_CC_PROTECT_MODE_REG                           = 0x2C0303FEull;

static const uint64_t P9N2_PERV_EC13_CC_PROTECT_MODE_REG                           = 0x2D0303FEull;

static const uint64_t P9N2_PERV_EC14_CC_PROTECT_MODE_REG                           = 0x2E0303FEull;

static const uint64_t P9N2_PERV_EC15_CC_PROTECT_MODE_REG                           = 0x2F0303FEull;

static const uint64_t P9N2_PERV_EC16_CC_PROTECT_MODE_REG                           = 0x300303FEull;

static const uint64_t P9N2_PERV_EC17_CC_PROTECT_MODE_REG                           = 0x310303FEull;

static const uint64_t P9N2_PERV_EC18_CC_PROTECT_MODE_REG                           = 0x320303FEull;

static const uint64_t P9N2_PERV_EC19_CC_PROTECT_MODE_REG                           = 0x330303FEull;

static const uint64_t P9N2_PERV_EC20_CC_PROTECT_MODE_REG                           = 0x340303FEull;

static const uint64_t P9N2_PERV_EC21_CC_PROTECT_MODE_REG                           = 0x350303FEull;

static const uint64_t P9N2_PERV_EC22_CC_PROTECT_MODE_REG                           = 0x360303FEull;

static const uint64_t P9N2_PERV_EC23_CC_PROTECT_MODE_REG                           = 0x370303FEull;


static const uint32_t P9N2_PERV_FSI2PIB_CHIPID_FSI                                 = 0x0000100Aull;

static const uint32_t P9N2_PERV_FSI2PIB_CHIPID_FSI_BYTE                            = 0x00001028ull;


static const uint32_t P9N2_PERV_FSISHIFT_CHIP_ID_FSI                               = 0x00000C09ull;

static const uint32_t P9N2_PERV_FSISHIFT_CHIP_ID_FSI_BYTE                          = 0x00000C24ull;


static const uint64_t P9N2_PERV_CLK_REGION                                         = 0x00030006ull;

static const uint64_t P9N2_PERV_TP_CLK_REGION                                      = 0x01030006ull;

static const uint64_t P9N2_PERV_N0_CLK_REGION                                      = 0x02030006ull;

static const uint64_t P9N2_PERV_N1_CLK_REGION                                      = 0x03030006ull;

static const uint64_t P9N2_PERV_N2_CLK_REGION                                      = 0x04030006ull;

static const uint64_t P9N2_PERV_N3_CLK_REGION                                      = 0x05030006ull;

static const uint64_t P9N2_PERV_XB_CLK_REGION                                      = 0x06030006ull;

static const uint64_t P9N2_PERV_MC01_CLK_REGION                                    = 0x07030006ull;

static const uint64_t P9N2_PERV_MC23_CLK_REGION                                    = 0x08030006ull;

static const uint64_t P9N2_PERV_OB0_CLK_REGION                                     = 0x09030006ull;

static const uint64_t P9N2_PERV_OB3_CLK_REGION                                     = 0x0C030006ull;

static const uint64_t P9N2_PERV_PCI0_CLK_REGION                                    = 0x0D030006ull;

static const uint64_t P9N2_PERV_PCI1_CLK_REGION                                    = 0x0E030006ull;

static const uint64_t P9N2_PERV_PCI2_CLK_REGION                                    = 0x0F030006ull;

static const uint64_t P9N2_PERV_EP00_CLK_REGION                                    = 0x10030006ull;

static const uint64_t P9N2_PERV_EP01_CLK_REGION                                    = 0x11030006ull;

static const uint64_t P9N2_PERV_EP02_CLK_REGION                                    = 0x12030006ull;

static const uint64_t P9N2_PERV_EP03_CLK_REGION                                    = 0x13030006ull;

static const uint64_t P9N2_PERV_EP04_CLK_REGION                                    = 0x14030006ull;

static const uint64_t P9N2_PERV_EP05_CLK_REGION                                    = 0x15030006ull;

static const uint64_t P9N2_PERV_EC00_CLK_REGION                                    = 0x20030006ull;

static const uint64_t P9N2_PERV_EC01_CLK_REGION                                    = 0x21030006ull;

static const uint64_t P9N2_PERV_EC02_CLK_REGION                                    = 0x22030006ull;

static const uint64_t P9N2_PERV_EC03_CLK_REGION                                    = 0x23030006ull;

static const uint64_t P9N2_PERV_EC04_CLK_REGION                                    = 0x24030006ull;

static const uint64_t P9N2_PERV_EC05_CLK_REGION                                    = 0x25030006ull;

static const uint64_t P9N2_PERV_EC06_CLK_REGION                                    = 0x26030006ull;

static const uint64_t P9N2_PERV_EC07_CLK_REGION                                    = 0x27030006ull;

static const uint64_t P9N2_PERV_EC08_CLK_REGION                                    = 0x28030006ull;

static const uint64_t P9N2_PERV_EC09_CLK_REGION                                    = 0x29030006ull;

static const uint64_t P9N2_PERV_EC10_CLK_REGION                                    = 0x2A030006ull;

static const uint64_t P9N2_PERV_EC11_CLK_REGION                                    = 0x2B030006ull;

static const uint64_t P9N2_PERV_EC12_CLK_REGION                                    = 0x2C030006ull;

static const uint64_t P9N2_PERV_EC13_CLK_REGION                                    = 0x2D030006ull;

static const uint64_t P9N2_PERV_EC14_CLK_REGION                                    = 0x2E030006ull;

static const uint64_t P9N2_PERV_EC15_CLK_REGION                                    = 0x2F030006ull;

static const uint64_t P9N2_PERV_EC16_CLK_REGION                                    = 0x30030006ull;

static const uint64_t P9N2_PERV_EC17_CLK_REGION                                    = 0x31030006ull;

static const uint64_t P9N2_PERV_EC18_CLK_REGION                                    = 0x32030006ull;

static const uint64_t P9N2_PERV_EC19_CLK_REGION                                    = 0x33030006ull;

static const uint64_t P9N2_PERV_EC20_CLK_REGION                                    = 0x34030006ull;

static const uint64_t P9N2_PERV_EC21_CLK_REGION                                    = 0x35030006ull;

static const uint64_t P9N2_PERV_EC22_CLK_REGION                                    = 0x36030006ull;

static const uint64_t P9N2_PERV_EC23_CLK_REGION                                    = 0x37030006ull;


static const uint64_t P9N2_PERV_CLOCK_STAT_ARY                                     = 0x0003000Aull;

static const uint64_t P9N2_PERV_TP_CLOCK_STAT_ARY                                  = 0x0103000Aull;

static const uint64_t P9N2_PERV_N0_CLOCK_STAT_ARY                                  = 0x0203000Aull;

static const uint64_t P9N2_PERV_N1_CLOCK_STAT_ARY                                  = 0x0303000Aull;

static const uint64_t P9N2_PERV_N2_CLOCK_STAT_ARY                                  = 0x0403000Aull;

static const uint64_t P9N2_PERV_N3_CLOCK_STAT_ARY                                  = 0x0503000Aull;

static const uint64_t P9N2_PERV_XB_CLOCK_STAT_ARY                                  = 0x0603000Aull;

static const uint64_t P9N2_PERV_MC01_CLOCK_STAT_ARY                                = 0x0703000Aull;

static const uint64_t P9N2_PERV_MC23_CLOCK_STAT_ARY                                = 0x0803000Aull;

static const uint64_t P9N2_PERV_OB0_CLOCK_STAT_ARY                                 = 0x0903000Aull;

static const uint64_t P9N2_PERV_OB3_CLOCK_STAT_ARY                                 = 0x0C03000Aull;

static const uint64_t P9N2_PERV_PCI0_CLOCK_STAT_ARY                                = 0x0D03000Aull;

static const uint64_t P9N2_PERV_PCI1_CLOCK_STAT_ARY                                = 0x0E03000Aull;

static const uint64_t P9N2_PERV_PCI2_CLOCK_STAT_ARY                                = 0x0F03000Aull;

static const uint64_t P9N2_PERV_EP00_CLOCK_STAT_ARY                                = 0x1003000Aull;

static const uint64_t P9N2_PERV_EP01_CLOCK_STAT_ARY                                = 0x1103000Aull;

static const uint64_t P9N2_PERV_EP02_CLOCK_STAT_ARY                                = 0x1203000Aull;

static const uint64_t P9N2_PERV_EP03_CLOCK_STAT_ARY                                = 0x1303000Aull;

static const uint64_t P9N2_PERV_EP04_CLOCK_STAT_ARY                                = 0x1403000Aull;

static const uint64_t P9N2_PERV_EP05_CLOCK_STAT_ARY                                = 0x1503000Aull;

static const uint64_t P9N2_PERV_EC00_CLOCK_STAT_ARY                                = 0x2003000Aull;

static const uint64_t P9N2_PERV_EC01_CLOCK_STAT_ARY                                = 0x2103000Aull;

static const uint64_t P9N2_PERV_EC02_CLOCK_STAT_ARY                                = 0x2203000Aull;

static const uint64_t P9N2_PERV_EC03_CLOCK_STAT_ARY                                = 0x2303000Aull;

static const uint64_t P9N2_PERV_EC04_CLOCK_STAT_ARY                                = 0x2403000Aull;

static const uint64_t P9N2_PERV_EC05_CLOCK_STAT_ARY                                = 0x2503000Aull;

static const uint64_t P9N2_PERV_EC06_CLOCK_STAT_ARY                                = 0x2603000Aull;

static const uint64_t P9N2_PERV_EC07_CLOCK_STAT_ARY                                = 0x2703000Aull;

static const uint64_t P9N2_PERV_EC08_CLOCK_STAT_ARY                                = 0x2803000Aull;

static const uint64_t P9N2_PERV_EC09_CLOCK_STAT_ARY                                = 0x2903000Aull;

static const uint64_t P9N2_PERV_EC10_CLOCK_STAT_ARY                                = 0x2A03000Aull;

static const uint64_t P9N2_PERV_EC11_CLOCK_STAT_ARY                                = 0x2B03000Aull;

static const uint64_t P9N2_PERV_EC12_CLOCK_STAT_ARY                                = 0x2C03000Aull;

static const uint64_t P9N2_PERV_EC13_CLOCK_STAT_ARY                                = 0x2D03000Aull;

static const uint64_t P9N2_PERV_EC14_CLOCK_STAT_ARY                                = 0x2E03000Aull;

static const uint64_t P9N2_PERV_EC15_CLOCK_STAT_ARY                                = 0x2F03000Aull;

static const uint64_t P9N2_PERV_EC16_CLOCK_STAT_ARY                                = 0x3003000Aull;

static const uint64_t P9N2_PERV_EC17_CLOCK_STAT_ARY                                = 0x3103000Aull;

static const uint64_t P9N2_PERV_EC18_CLOCK_STAT_ARY                                = 0x3203000Aull;

static const uint64_t P9N2_PERV_EC19_CLOCK_STAT_ARY                                = 0x3303000Aull;

static const uint64_t P9N2_PERV_EC20_CLOCK_STAT_ARY                                = 0x3403000Aull;

static const uint64_t P9N2_PERV_EC21_CLOCK_STAT_ARY                                = 0x3503000Aull;

static const uint64_t P9N2_PERV_EC22_CLOCK_STAT_ARY                                = 0x3603000Aull;

static const uint64_t P9N2_PERV_EC23_CLOCK_STAT_ARY                                = 0x3703000Aull;


static const uint64_t P9N2_PERV_CLOCK_STAT_NSL                                     = 0x00030009ull;

static const uint64_t P9N2_PERV_TP_CLOCK_STAT_NSL                                  = 0x01030009ull;

static const uint64_t P9N2_PERV_N0_CLOCK_STAT_NSL                                  = 0x02030009ull;

static const uint64_t P9N2_PERV_N1_CLOCK_STAT_NSL                                  = 0x03030009ull;

static const uint64_t P9N2_PERV_N2_CLOCK_STAT_NSL                                  = 0x04030009ull;

static const uint64_t P9N2_PERV_N3_CLOCK_STAT_NSL                                  = 0x05030009ull;

static const uint64_t P9N2_PERV_XB_CLOCK_STAT_NSL                                  = 0x06030009ull;

static const uint64_t P9N2_PERV_MC01_CLOCK_STAT_NSL                                = 0x07030009ull;

static const uint64_t P9N2_PERV_MC23_CLOCK_STAT_NSL                                = 0x08030009ull;

static const uint64_t P9N2_PERV_OB0_CLOCK_STAT_NSL                                 = 0x09030009ull;

static const uint64_t P9N2_PERV_OB3_CLOCK_STAT_NSL                                 = 0x0C030009ull;

static const uint64_t P9N2_PERV_PCI0_CLOCK_STAT_NSL                                = 0x0D030009ull;

static const uint64_t P9N2_PERV_PCI1_CLOCK_STAT_NSL                                = 0x0E030009ull;

static const uint64_t P9N2_PERV_PCI2_CLOCK_STAT_NSL                                = 0x0F030009ull;

static const uint64_t P9N2_PERV_EP00_CLOCK_STAT_NSL                                = 0x10030009ull;

static const uint64_t P9N2_PERV_EP01_CLOCK_STAT_NSL                                = 0x11030009ull;

static const uint64_t P9N2_PERV_EP02_CLOCK_STAT_NSL                                = 0x12030009ull;

static const uint64_t P9N2_PERV_EP03_CLOCK_STAT_NSL                                = 0x13030009ull;

static const uint64_t P9N2_PERV_EP04_CLOCK_STAT_NSL                                = 0x14030009ull;

static const uint64_t P9N2_PERV_EP05_CLOCK_STAT_NSL                                = 0x15030009ull;

static const uint64_t P9N2_PERV_EC00_CLOCK_STAT_NSL                                = 0x20030009ull;

static const uint64_t P9N2_PERV_EC01_CLOCK_STAT_NSL                                = 0x21030009ull;

static const uint64_t P9N2_PERV_EC02_CLOCK_STAT_NSL                                = 0x22030009ull;

static const uint64_t P9N2_PERV_EC03_CLOCK_STAT_NSL                                = 0x23030009ull;

static const uint64_t P9N2_PERV_EC04_CLOCK_STAT_NSL                                = 0x24030009ull;

static const uint64_t P9N2_PERV_EC05_CLOCK_STAT_NSL                                = 0x25030009ull;

static const uint64_t P9N2_PERV_EC06_CLOCK_STAT_NSL                                = 0x26030009ull;

static const uint64_t P9N2_PERV_EC07_CLOCK_STAT_NSL                                = 0x27030009ull;

static const uint64_t P9N2_PERV_EC08_CLOCK_STAT_NSL                                = 0x28030009ull;

static const uint64_t P9N2_PERV_EC09_CLOCK_STAT_NSL                                = 0x29030009ull;

static const uint64_t P9N2_PERV_EC10_CLOCK_STAT_NSL                                = 0x2A030009ull;

static const uint64_t P9N2_PERV_EC11_CLOCK_STAT_NSL                                = 0x2B030009ull;

static const uint64_t P9N2_PERV_EC12_CLOCK_STAT_NSL                                = 0x2C030009ull;

static const uint64_t P9N2_PERV_EC13_CLOCK_STAT_NSL                                = 0x2D030009ull;

static const uint64_t P9N2_PERV_EC14_CLOCK_STAT_NSL                                = 0x2E030009ull;

static const uint64_t P9N2_PERV_EC15_CLOCK_STAT_NSL                                = 0x2F030009ull;

static const uint64_t P9N2_PERV_EC16_CLOCK_STAT_NSL                                = 0x30030009ull;

static const uint64_t P9N2_PERV_EC17_CLOCK_STAT_NSL                                = 0x31030009ull;

static const uint64_t P9N2_PERV_EC18_CLOCK_STAT_NSL                                = 0x32030009ull;

static const uint64_t P9N2_PERV_EC19_CLOCK_STAT_NSL                                = 0x33030009ull;

static const uint64_t P9N2_PERV_EC20_CLOCK_STAT_NSL                                = 0x34030009ull;

static const uint64_t P9N2_PERV_EC21_CLOCK_STAT_NSL                                = 0x35030009ull;

static const uint64_t P9N2_PERV_EC22_CLOCK_STAT_NSL                                = 0x36030009ull;

static const uint64_t P9N2_PERV_EC23_CLOCK_STAT_NSL                                = 0x37030009ull;


static const uint64_t P9N2_PERV_CLOCK_STAT_SL                                      = 0x00030008ull;

static const uint64_t P9N2_PERV_TP_CLOCK_STAT_SL                                   = 0x01030008ull;

static const uint64_t P9N2_PERV_N0_CLOCK_STAT_SL                                   = 0x02030008ull;

static const uint64_t P9N2_PERV_N1_CLOCK_STAT_SL                                   = 0x03030008ull;

static const uint64_t P9N2_PERV_N2_CLOCK_STAT_SL                                   = 0x04030008ull;

static const uint64_t P9N2_PERV_N3_CLOCK_STAT_SL                                   = 0x05030008ull;

static const uint64_t P9N2_PERV_XB_CLOCK_STAT_SL                                   = 0x06030008ull;

static const uint64_t P9N2_PERV_MC01_CLOCK_STAT_SL                                 = 0x07030008ull;

static const uint64_t P9N2_PERV_MC23_CLOCK_STAT_SL                                 = 0x08030008ull;

static const uint64_t P9N2_PERV_OB0_CLOCK_STAT_SL                                  = 0x09030008ull;

static const uint64_t P9N2_PERV_OB3_CLOCK_STAT_SL                                  = 0x0C030008ull;

static const uint64_t P9N2_PERV_PCI0_CLOCK_STAT_SL                                 = 0x0D030008ull;

static const uint64_t P9N2_PERV_PCI1_CLOCK_STAT_SL                                 = 0x0E030008ull;

static const uint64_t P9N2_PERV_PCI2_CLOCK_STAT_SL                                 = 0x0F030008ull;

static const uint64_t P9N2_PERV_EP00_CLOCK_STAT_SL                                 = 0x10030008ull;

static const uint64_t P9N2_PERV_EP01_CLOCK_STAT_SL                                 = 0x11030008ull;

static const uint64_t P9N2_PERV_EP02_CLOCK_STAT_SL                                 = 0x12030008ull;

static const uint64_t P9N2_PERV_EP03_CLOCK_STAT_SL                                 = 0x13030008ull;

static const uint64_t P9N2_PERV_EP04_CLOCK_STAT_SL                                 = 0x14030008ull;

static const uint64_t P9N2_PERV_EP05_CLOCK_STAT_SL                                 = 0x15030008ull;

static const uint64_t P9N2_PERV_EC00_CLOCK_STAT_SL                                 = 0x20030008ull;

static const uint64_t P9N2_PERV_EC01_CLOCK_STAT_SL                                 = 0x21030008ull;

static const uint64_t P9N2_PERV_EC02_CLOCK_STAT_SL                                 = 0x22030008ull;

static const uint64_t P9N2_PERV_EC03_CLOCK_STAT_SL                                 = 0x23030008ull;

static const uint64_t P9N2_PERV_EC04_CLOCK_STAT_SL                                 = 0x24030008ull;

static const uint64_t P9N2_PERV_EC05_CLOCK_STAT_SL                                 = 0x25030008ull;

static const uint64_t P9N2_PERV_EC06_CLOCK_STAT_SL                                 = 0x26030008ull;

static const uint64_t P9N2_PERV_EC07_CLOCK_STAT_SL                                 = 0x27030008ull;

static const uint64_t P9N2_PERV_EC08_CLOCK_STAT_SL                                 = 0x28030008ull;

static const uint64_t P9N2_PERV_EC09_CLOCK_STAT_SL                                 = 0x29030008ull;

static const uint64_t P9N2_PERV_EC10_CLOCK_STAT_SL                                 = 0x2A030008ull;

static const uint64_t P9N2_PERV_EC11_CLOCK_STAT_SL                                 = 0x2B030008ull;

static const uint64_t P9N2_PERV_EC12_CLOCK_STAT_SL                                 = 0x2C030008ull;

static const uint64_t P9N2_PERV_EC13_CLOCK_STAT_SL                                 = 0x2D030008ull;

static const uint64_t P9N2_PERV_EC14_CLOCK_STAT_SL                                 = 0x2E030008ull;

static const uint64_t P9N2_PERV_EC15_CLOCK_STAT_SL                                 = 0x2F030008ull;

static const uint64_t P9N2_PERV_EC16_CLOCK_STAT_SL                                 = 0x30030008ull;

static const uint64_t P9N2_PERV_EC17_CLOCK_STAT_SL                                 = 0x31030008ull;

static const uint64_t P9N2_PERV_EC18_CLOCK_STAT_SL                                 = 0x32030008ull;

static const uint64_t P9N2_PERV_EC19_CLOCK_STAT_SL                                 = 0x33030008ull;

static const uint64_t P9N2_PERV_EC20_CLOCK_STAT_SL                                 = 0x34030008ull;

static const uint64_t P9N2_PERV_EC21_CLOCK_STAT_SL                                 = 0x35030008ull;

static const uint64_t P9N2_PERV_EC22_CLOCK_STAT_SL                                 = 0x36030008ull;

static const uint64_t P9N2_PERV_EC23_CLOCK_STAT_SL                                 = 0x37030008ull;


static const uint64_t P9N2_PERV_CMD_WRDAT                                          = 0x00030000ull;

static const uint64_t P9N2_PERV_PIB_CMD_WRDAT                                      = 0x00030000ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_CMD_WRDAT                               = 0x00020000ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_CMD_WRDAT                               = 0x00020010ull;

static const uint64_t P9N2_PERV_PIB2OPB0_CMD_WRDAT                                 = 0x00020000ull;

static const uint64_t P9N2_PERV_PIB2OPB1_CMD_WRDAT                                 = 0x00020010ull;


static const uint32_t P9N2_PERV_FSI2PIB_COMMAND_REGISTER_FSI                       = 0x00001002ull;

static const uint32_t P9N2_PERV_FSI2PIB_COMMAND_REGISTER_FSI_BYTE                  = 0x00001008ull;

static const uint32_t P9N2_PERV_FSISHIFT_COMMAND_REGISTER_FSI                      = 0x00000C01ull;

static const uint32_t P9N2_PERV_FSISHIFT_COMMAND_REGISTER_FSI_BYTE                 = 0x00000C04ull;


static const uint64_t P9N2_PERV_0_FSII2C_COMMAND_REGISTER_A                        = 0x00001801ull;

static const uint32_t P9N2_PERV_FSII2C_COMMAND_REGISTER_A                          = 0x00001801ull;


static const uint32_t P9N2_PERV_FSI2PIB_COMPLEMENT_MASK_FSI                        = 0x0000100Cull;

static const uint32_t P9N2_PERV_FSI2PIB_COMPLEMENT_MASK_FSI_BYTE                   = 0x00001030ull;

static const uint32_t P9N2_PERV_FSISHIFT_COMPLEMENT_MASK_FSI                       = 0x00000C0Cull;

static const uint32_t P9N2_PERV_FSISHIFT_COMPLEMENT_MASK_FSI_BYTE                  = 0x00000C30ull;


static const uint64_t P9N2_PERV_CONTROL_REG                                        = 0x00050012ull;

static const uint64_t P9N2_PERV_TP_CONTROL_REG                                     = 0x01050012ull;

static const uint64_t P9N2_PERV_N0_CONTROL_REG                                     = 0x02050012ull;

static const uint64_t P9N2_PERV_N1_CONTROL_REG                                     = 0x03050012ull;

static const uint64_t P9N2_PERV_N2_CONTROL_REG                                     = 0x04050012ull;

static const uint64_t P9N2_PERV_N3_CONTROL_REG                                     = 0x05050012ull;

static const uint64_t P9N2_PERV_XB_CONTROL_REG                                     = 0x06050012ull;

static const uint64_t P9N2_PERV_MC01_CONTROL_REG                                   = 0x07050012ull;

static const uint64_t P9N2_PERV_MC23_CONTROL_REG                                   = 0x08050012ull;

static const uint64_t P9N2_PERV_OB0_CONTROL_REG                                    = 0x09050012ull;

static const uint64_t P9N2_PERV_OB3_CONTROL_REG                                    = 0x0C050012ull;

static const uint64_t P9N2_PERV_PCI0_CONTROL_REG                                   = 0x0D050012ull;

static const uint64_t P9N2_PERV_PCI1_CONTROL_REG                                   = 0x0E050012ull;

static const uint64_t P9N2_PERV_PCI2_CONTROL_REG                                   = 0x0F050012ull;

static const uint64_t P9N2_PERV_EP00_CONTROL_REG                                   = 0x10050012ull;

static const uint64_t P9N2_PERV_EP01_CONTROL_REG                                   = 0x11050012ull;

static const uint64_t P9N2_PERV_EP02_CONTROL_REG                                   = 0x12050012ull;

static const uint64_t P9N2_PERV_EP03_CONTROL_REG                                   = 0x13050012ull;

static const uint64_t P9N2_PERV_EP04_CONTROL_REG                                   = 0x14050012ull;

static const uint64_t P9N2_PERV_EP05_CONTROL_REG                                   = 0x15050012ull;

static const uint64_t P9N2_PERV_EC00_CONTROL_REG                                   = 0x20050012ull;

static const uint64_t P9N2_PERV_EC01_CONTROL_REG                                   = 0x21050012ull;

static const uint64_t P9N2_PERV_EC02_CONTROL_REG                                   = 0x22050012ull;

static const uint64_t P9N2_PERV_EC03_CONTROL_REG                                   = 0x23050012ull;

static const uint64_t P9N2_PERV_EC04_CONTROL_REG                                   = 0x24050012ull;

static const uint64_t P9N2_PERV_EC05_CONTROL_REG                                   = 0x25050012ull;

static const uint64_t P9N2_PERV_EC06_CONTROL_REG                                   = 0x26050012ull;

static const uint64_t P9N2_PERV_EC07_CONTROL_REG                                   = 0x27050012ull;

static const uint64_t P9N2_PERV_EC08_CONTROL_REG                                   = 0x28050012ull;

static const uint64_t P9N2_PERV_EC09_CONTROL_REG                                   = 0x29050012ull;

static const uint64_t P9N2_PERV_EC10_CONTROL_REG                                   = 0x2A050012ull;

static const uint64_t P9N2_PERV_EC11_CONTROL_REG                                   = 0x2B050012ull;

static const uint64_t P9N2_PERV_EC12_CONTROL_REG                                   = 0x2C050012ull;

static const uint64_t P9N2_PERV_EC13_CONTROL_REG                                   = 0x2D050012ull;

static const uint64_t P9N2_PERV_EC14_CONTROL_REG                                   = 0x2E050012ull;

static const uint64_t P9N2_PERV_EC15_CONTROL_REG                                   = 0x2F050012ull;

static const uint64_t P9N2_PERV_EC16_CONTROL_REG                                   = 0x30050012ull;

static const uint64_t P9N2_PERV_EC17_CONTROL_REG                                   = 0x31050012ull;

static const uint64_t P9N2_PERV_EC18_CONTROL_REG                                   = 0x32050012ull;

static const uint64_t P9N2_PERV_EC19_CONTROL_REG                                   = 0x33050012ull;

static const uint64_t P9N2_PERV_EC20_CONTROL_REG                                   = 0x34050012ull;

static const uint64_t P9N2_PERV_EC21_CONTROL_REG                                   = 0x35050012ull;

static const uint64_t P9N2_PERV_EC22_CONTROL_REG                                   = 0x36050012ull;

static const uint64_t P9N2_PERV_EC23_CONTROL_REG                                   = 0x37050012ull;


static const uint64_t P9N2_PERV_CPLT_CONF0                                         = 0x00000008ull;

static const uint64_t P9N2_PERV_TP_CPLT_CONF0                                      = 0x01000008ull;

static const uint64_t P9N2_PERV_CPLT_CONF0_OR                                      = 0x00000018ull;

static const uint64_t P9N2_PERV_TP_CPLT_CONF0_OR                                   = 0x01000018ull;

static const uint64_t P9N2_PERV_CPLT_CONF0_CLEAR                                   = 0x00000028ull;

static const uint64_t P9N2_PERV_TP_CPLT_CONF0_CLEAR                                = 0x01000028ull;

static const uint64_t P9N2_PERV_N0_CPLT_CONF0                                      = 0x02000008ull;

static const uint64_t P9N2_PERV_N0_CPLT_CONF0_OR                                   = 0x02000018ull;

static const uint64_t P9N2_PERV_N0_CPLT_CONF0_CLEAR                                = 0x02000028ull;

static const uint64_t P9N2_PERV_N1_CPLT_CONF0                                      = 0x03000008ull;

static const uint64_t P9N2_PERV_N1_CPLT_CONF0_OR                                   = 0x03000018ull;

static const uint64_t P9N2_PERV_N1_CPLT_CONF0_CLEAR                                = 0x03000028ull;

static const uint64_t P9N2_PERV_N2_CPLT_CONF0                                      = 0x04000008ull;

static const uint64_t P9N2_PERV_N2_CPLT_CONF0_OR                                   = 0x04000018ull;

static const uint64_t P9N2_PERV_N2_CPLT_CONF0_CLEAR                                = 0x04000028ull;

static const uint64_t P9N2_PERV_N3_CPLT_CONF0                                      = 0x05000008ull;

static const uint64_t P9N2_PERV_N3_CPLT_CONF0_OR                                   = 0x05000018ull;

static const uint64_t P9N2_PERV_N3_CPLT_CONF0_CLEAR                                = 0x05000028ull;

static const uint64_t P9N2_PERV_XB_CPLT_CONF0                                      = 0x06000008ull;

static const uint64_t P9N2_PERV_XB_CPLT_CONF0_OR                                   = 0x06000018ull;

static const uint64_t P9N2_PERV_XB_CPLT_CONF0_CLEAR                                = 0x06000028ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CONF0                                    = 0x07000008ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CONF0_OR                                 = 0x07000018ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CONF0_CLEAR                              = 0x07000028ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CONF0                                    = 0x08000008ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CONF0_OR                                 = 0x08000018ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CONF0_CLEAR                              = 0x08000028ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CONF0                                     = 0x09000008ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CONF0_OR                                  = 0x09000018ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CONF0_CLEAR                               = 0x09000028ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CONF0                                     = 0x0C000008ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CONF0_OR                                  = 0x0C000018ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CONF0_CLEAR                               = 0x0C000028ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CONF0                                    = 0x0D000008ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CONF0_OR                                 = 0x0D000018ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CONF0_CLEAR                              = 0x0D000028ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CONF0                                    = 0x0E000008ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CONF0_OR                                 = 0x0E000018ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CONF0_CLEAR                              = 0x0E000028ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CONF0                                    = 0x0F000008ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CONF0_OR                                 = 0x0F000018ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CONF0_CLEAR                              = 0x0F000028ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CONF0                                    = 0x10000008ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CONF0_OR                                 = 0x10000018ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CONF0_CLEAR                              = 0x10000028ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CONF0                                    = 0x11000008ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CONF0_OR                                 = 0x11000018ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CONF0_CLEAR                              = 0x11000028ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CONF0                                    = 0x12000008ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CONF0_OR                                 = 0x12000018ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CONF0_CLEAR                              = 0x12000028ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CONF0                                    = 0x13000008ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CONF0_OR                                 = 0x13000018ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CONF0_CLEAR                              = 0x13000028ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CONF0                                    = 0x14000008ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CONF0_OR                                 = 0x14000018ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CONF0_CLEAR                              = 0x14000028ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CONF0                                    = 0x15000008ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CONF0_OR                                 = 0x15000018ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CONF0_CLEAR                              = 0x15000028ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CONF0                                    = 0x20000008ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CONF0_OR                                 = 0x20000018ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CONF0_CLEAR                              = 0x20000028ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CONF0                                    = 0x21000008ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CONF0_OR                                 = 0x21000018ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CONF0_CLEAR                              = 0x21000028ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CONF0                                    = 0x22000008ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CONF0_OR                                 = 0x22000018ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CONF0_CLEAR                              = 0x22000028ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CONF0                                    = 0x23000008ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CONF0_OR                                 = 0x23000018ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CONF0_CLEAR                              = 0x23000028ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CONF0                                    = 0x24000008ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CONF0_OR                                 = 0x24000018ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CONF0_CLEAR                              = 0x24000028ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CONF0                                    = 0x25000008ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CONF0_OR                                 = 0x25000018ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CONF0_CLEAR                              = 0x25000028ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CONF0                                    = 0x26000008ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CONF0_OR                                 = 0x26000018ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CONF0_CLEAR                              = 0x26000028ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CONF0                                    = 0x27000008ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CONF0_OR                                 = 0x27000018ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CONF0_CLEAR                              = 0x27000028ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CONF0                                    = 0x28000008ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CONF0_OR                                 = 0x28000018ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CONF0_CLEAR                              = 0x28000028ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CONF0                                    = 0x29000008ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CONF0_OR                                 = 0x29000018ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CONF0_CLEAR                              = 0x29000028ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CONF0                                    = 0x2A000008ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CONF0_OR                                 = 0x2A000018ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CONF0_CLEAR                              = 0x2A000028ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CONF0                                    = 0x2B000008ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CONF0_OR                                 = 0x2B000018ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CONF0_CLEAR                              = 0x2B000028ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CONF0                                    = 0x2C000008ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CONF0_OR                                 = 0x2C000018ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CONF0_CLEAR                              = 0x2C000028ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CONF0                                    = 0x2D000008ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CONF0_OR                                 = 0x2D000018ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CONF0_CLEAR                              = 0x2D000028ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CONF0                                    = 0x2E000008ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CONF0_OR                                 = 0x2E000018ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CONF0_CLEAR                              = 0x2E000028ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CONF0                                    = 0x2F000008ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CONF0_OR                                 = 0x2F000018ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CONF0_CLEAR                              = 0x2F000028ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CONF0                                    = 0x30000008ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CONF0_OR                                 = 0x30000018ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CONF0_CLEAR                              = 0x30000028ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CONF0                                    = 0x31000008ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CONF0_OR                                 = 0x31000018ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CONF0_CLEAR                              = 0x31000028ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CONF0                                    = 0x32000008ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CONF0_OR                                 = 0x32000018ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CONF0_CLEAR                              = 0x32000028ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CONF0                                    = 0x33000008ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CONF0_OR                                 = 0x33000018ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CONF0_CLEAR                              = 0x33000028ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CONF0                                    = 0x34000008ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CONF0_OR                                 = 0x34000018ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CONF0_CLEAR                              = 0x34000028ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CONF0                                    = 0x35000008ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CONF0_OR                                 = 0x35000018ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CONF0_CLEAR                              = 0x35000028ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CONF0                                    = 0x36000008ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CONF0_OR                                 = 0x36000018ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CONF0_CLEAR                              = 0x36000028ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CONF0                                    = 0x37000008ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CONF0_OR                                 = 0x37000018ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CONF0_CLEAR                              = 0x37000028ull;


static const uint64_t P9N2_PERV_CPLT_CONF1                                         = 0x00000009ull;

static const uint64_t P9N2_PERV_TP_CPLT_CONF1                                      = 0x01000009ull;

static const uint64_t P9N2_PERV_CPLT_CONF1_OR                                      = 0x00000019ull;

static const uint64_t P9N2_PERV_TP_CPLT_CONF1_OR                                   = 0x01000019ull;

static const uint64_t P9N2_PERV_CPLT_CONF1_CLEAR                                   = 0x00000029ull;

static const uint64_t P9N2_PERV_TP_CPLT_CONF1_CLEAR                                = 0x01000029ull;

static const uint64_t P9N2_PERV_N0_CPLT_CONF1                                      = 0x02000009ull;

static const uint64_t P9N2_PERV_N0_CPLT_CONF1_OR                                   = 0x02000019ull;

static const uint64_t P9N2_PERV_N0_CPLT_CONF1_CLEAR                                = 0x02000029ull;

static const uint64_t P9N2_PERV_N1_CPLT_CONF1                                      = 0x03000009ull;

static const uint64_t P9N2_PERV_N1_CPLT_CONF1_OR                                   = 0x03000019ull;

static const uint64_t P9N2_PERV_N1_CPLT_CONF1_CLEAR                                = 0x03000029ull;

static const uint64_t P9N2_PERV_N2_CPLT_CONF1                                      = 0x04000009ull;

static const uint64_t P9N2_PERV_N2_CPLT_CONF1_OR                                   = 0x04000019ull;

static const uint64_t P9N2_PERV_N2_CPLT_CONF1_CLEAR                                = 0x04000029ull;

static const uint64_t P9N2_PERV_N3_CPLT_CONF1                                      = 0x05000009ull;

static const uint64_t P9N2_PERV_N3_CPLT_CONF1_OR                                   = 0x05000019ull;

static const uint64_t P9N2_PERV_N3_CPLT_CONF1_CLEAR                                = 0x05000029ull;

static const uint64_t P9N2_PERV_XB_CPLT_CONF1                                      = 0x06000009ull;

static const uint64_t P9N2_PERV_XB_CPLT_CONF1_OR                                   = 0x06000019ull;

static const uint64_t P9N2_PERV_XB_CPLT_CONF1_CLEAR                                = 0x06000029ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CONF1                                    = 0x07000009ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CONF1_OR                                 = 0x07000019ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CONF1_CLEAR                              = 0x07000029ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CONF1                                    = 0x08000009ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CONF1_OR                                 = 0x08000019ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CONF1_CLEAR                              = 0x08000029ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CONF1                                     = 0x09000009ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CONF1_OR                                  = 0x09000019ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CONF1_CLEAR                               = 0x09000029ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CONF1                                     = 0x0C000009ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CONF1_OR                                  = 0x0C000019ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CONF1_CLEAR                               = 0x0C000029ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CONF1                                    = 0x0D000009ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CONF1_OR                                 = 0x0D000019ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CONF1_CLEAR                              = 0x0D000029ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CONF1                                    = 0x0E000009ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CONF1_OR                                 = 0x0E000019ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CONF1_CLEAR                              = 0x0E000029ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CONF1                                    = 0x0F000009ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CONF1_OR                                 = 0x0F000019ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CONF1_CLEAR                              = 0x0F000029ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CONF1                                    = 0x10000009ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CONF1_OR                                 = 0x10000019ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CONF1_CLEAR                              = 0x10000029ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CONF1                                    = 0x11000009ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CONF1_OR                                 = 0x11000019ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CONF1_CLEAR                              = 0x11000029ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CONF1                                    = 0x12000009ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CONF1_OR                                 = 0x12000019ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CONF1_CLEAR                              = 0x12000029ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CONF1                                    = 0x13000009ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CONF1_OR                                 = 0x13000019ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CONF1_CLEAR                              = 0x13000029ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CONF1                                    = 0x14000009ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CONF1_OR                                 = 0x14000019ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CONF1_CLEAR                              = 0x14000029ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CONF1                                    = 0x15000009ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CONF1_OR                                 = 0x15000019ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CONF1_CLEAR                              = 0x15000029ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CONF1                                    = 0x20000009ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CONF1_OR                                 = 0x20000019ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CONF1_CLEAR                              = 0x20000029ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CONF1                                    = 0x21000009ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CONF1_OR                                 = 0x21000019ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CONF1_CLEAR                              = 0x21000029ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CONF1                                    = 0x22000009ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CONF1_OR                                 = 0x22000019ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CONF1_CLEAR                              = 0x22000029ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CONF1                                    = 0x23000009ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CONF1_OR                                 = 0x23000019ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CONF1_CLEAR                              = 0x23000029ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CONF1                                    = 0x24000009ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CONF1_OR                                 = 0x24000019ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CONF1_CLEAR                              = 0x24000029ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CONF1                                    = 0x25000009ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CONF1_OR                                 = 0x25000019ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CONF1_CLEAR                              = 0x25000029ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CONF1                                    = 0x26000009ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CONF1_OR                                 = 0x26000019ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CONF1_CLEAR                              = 0x26000029ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CONF1                                    = 0x27000009ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CONF1_OR                                 = 0x27000019ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CONF1_CLEAR                              = 0x27000029ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CONF1                                    = 0x28000009ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CONF1_OR                                 = 0x28000019ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CONF1_CLEAR                              = 0x28000029ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CONF1                                    = 0x29000009ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CONF1_OR                                 = 0x29000019ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CONF1_CLEAR                              = 0x29000029ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CONF1                                    = 0x2A000009ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CONF1_OR                                 = 0x2A000019ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CONF1_CLEAR                              = 0x2A000029ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CONF1                                    = 0x2B000009ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CONF1_OR                                 = 0x2B000019ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CONF1_CLEAR                              = 0x2B000029ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CONF1                                    = 0x2C000009ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CONF1_OR                                 = 0x2C000019ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CONF1_CLEAR                              = 0x2C000029ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CONF1                                    = 0x2D000009ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CONF1_OR                                 = 0x2D000019ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CONF1_CLEAR                              = 0x2D000029ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CONF1                                    = 0x2E000009ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CONF1_OR                                 = 0x2E000019ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CONF1_CLEAR                              = 0x2E000029ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CONF1                                    = 0x2F000009ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CONF1_OR                                 = 0x2F000019ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CONF1_CLEAR                              = 0x2F000029ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CONF1                                    = 0x30000009ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CONF1_OR                                 = 0x30000019ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CONF1_CLEAR                              = 0x30000029ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CONF1                                    = 0x31000009ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CONF1_OR                                 = 0x31000019ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CONF1_CLEAR                              = 0x31000029ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CONF1                                    = 0x32000009ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CONF1_OR                                 = 0x32000019ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CONF1_CLEAR                              = 0x32000029ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CONF1                                    = 0x33000009ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CONF1_OR                                 = 0x33000019ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CONF1_CLEAR                              = 0x33000029ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CONF1                                    = 0x34000009ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CONF1_OR                                 = 0x34000019ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CONF1_CLEAR                              = 0x34000029ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CONF1                                    = 0x35000009ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CONF1_OR                                 = 0x35000019ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CONF1_CLEAR                              = 0x35000029ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CONF1                                    = 0x36000009ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CONF1_OR                                 = 0x36000019ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CONF1_CLEAR                              = 0x36000029ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CONF1                                    = 0x37000009ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CONF1_OR                                 = 0x37000019ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CONF1_CLEAR                              = 0x37000029ull;


static const uint64_t P9N2_PERV_CPLT_CTRL0                                         = 0x00000000ull;

static const uint64_t P9N2_PERV_TP_CPLT_CTRL0                                      = 0x01000000ull;

static const uint64_t P9N2_PERV_CPLT_CTRL0_OR                                      = 0x00000010ull;

static const uint64_t P9N2_PERV_TP_CPLT_CTRL0_OR                                   = 0x01000010ull;

static const uint64_t P9N2_PERV_CPLT_CTRL0_CLEAR                                   = 0x00000020ull;

static const uint64_t P9N2_PERV_TP_CPLT_CTRL0_CLEAR                                = 0x01000020ull;

static const uint64_t P9N2_PERV_N0_CPLT_CTRL0                                      = 0x02000000ull;

static const uint64_t P9N2_PERV_N0_CPLT_CTRL0_OR                                   = 0x02000010ull;

static const uint64_t P9N2_PERV_N0_CPLT_CTRL0_CLEAR                                = 0x02000020ull;

static const uint64_t P9N2_PERV_N1_CPLT_CTRL0                                      = 0x03000000ull;

static const uint64_t P9N2_PERV_N1_CPLT_CTRL0_OR                                   = 0x03000010ull;

static const uint64_t P9N2_PERV_N1_CPLT_CTRL0_CLEAR                                = 0x03000020ull;

static const uint64_t P9N2_PERV_N2_CPLT_CTRL0                                      = 0x04000000ull;

static const uint64_t P9N2_PERV_N2_CPLT_CTRL0_OR                                   = 0x04000010ull;

static const uint64_t P9N2_PERV_N2_CPLT_CTRL0_CLEAR                                = 0x04000020ull;

static const uint64_t P9N2_PERV_N3_CPLT_CTRL0                                      = 0x05000000ull;

static const uint64_t P9N2_PERV_N3_CPLT_CTRL0_OR                                   = 0x05000010ull;

static const uint64_t P9N2_PERV_N3_CPLT_CTRL0_CLEAR                                = 0x05000020ull;

static const uint64_t P9N2_PERV_XB_CPLT_CTRL0                                      = 0x06000000ull;

static const uint64_t P9N2_PERV_XB_CPLT_CTRL0_OR                                   = 0x06000010ull;

static const uint64_t P9N2_PERV_XB_CPLT_CTRL0_CLEAR                                = 0x06000020ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CTRL0                                    = 0x07000000ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CTRL0_OR                                 = 0x07000010ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CTRL0_CLEAR                              = 0x07000020ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CTRL0                                    = 0x08000000ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CTRL0_OR                                 = 0x08000010ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CTRL0_CLEAR                              = 0x08000020ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CTRL0                                     = 0x09000000ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CTRL0_OR                                  = 0x09000010ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CTRL0_CLEAR                               = 0x09000020ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CTRL0                                     = 0x0C000000ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CTRL0_OR                                  = 0x0C000010ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CTRL0_CLEAR                               = 0x0C000020ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CTRL0                                    = 0x0D000000ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CTRL0_OR                                 = 0x0D000010ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CTRL0_CLEAR                              = 0x0D000020ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CTRL0                                    = 0x0E000000ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CTRL0_OR                                 = 0x0E000010ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CTRL0_CLEAR                              = 0x0E000020ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CTRL0                                    = 0x0F000000ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CTRL0_OR                                 = 0x0F000010ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CTRL0_CLEAR                              = 0x0F000020ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CTRL0                                    = 0x10000000ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CTRL0_OR                                 = 0x10000010ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CTRL0_CLEAR                              = 0x10000020ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CTRL0                                    = 0x11000000ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CTRL0_OR                                 = 0x11000010ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CTRL0_CLEAR                              = 0x11000020ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CTRL0                                    = 0x12000000ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CTRL0_OR                                 = 0x12000010ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CTRL0_CLEAR                              = 0x12000020ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CTRL0                                    = 0x13000000ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CTRL0_OR                                 = 0x13000010ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CTRL0_CLEAR                              = 0x13000020ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CTRL0                                    = 0x14000000ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CTRL0_OR                                 = 0x14000010ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CTRL0_CLEAR                              = 0x14000020ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CTRL0                                    = 0x15000000ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CTRL0_OR                                 = 0x15000010ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CTRL0_CLEAR                              = 0x15000020ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CTRL0                                    = 0x20000000ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CTRL0_OR                                 = 0x20000010ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CTRL0_CLEAR                              = 0x20000020ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CTRL0                                    = 0x21000000ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CTRL0_OR                                 = 0x21000010ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CTRL0_CLEAR                              = 0x21000020ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CTRL0                                    = 0x22000000ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CTRL0_OR                                 = 0x22000010ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CTRL0_CLEAR                              = 0x22000020ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CTRL0                                    = 0x23000000ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CTRL0_OR                                 = 0x23000010ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CTRL0_CLEAR                              = 0x23000020ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CTRL0                                    = 0x24000000ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CTRL0_OR                                 = 0x24000010ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CTRL0_CLEAR                              = 0x24000020ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CTRL0                                    = 0x25000000ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CTRL0_OR                                 = 0x25000010ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CTRL0_CLEAR                              = 0x25000020ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CTRL0                                    = 0x26000000ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CTRL0_OR                                 = 0x26000010ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CTRL0_CLEAR                              = 0x26000020ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CTRL0                                    = 0x27000000ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CTRL0_OR                                 = 0x27000010ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CTRL0_CLEAR                              = 0x27000020ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CTRL0                                    = 0x28000000ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CTRL0_OR                                 = 0x28000010ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CTRL0_CLEAR                              = 0x28000020ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CTRL0                                    = 0x29000000ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CTRL0_OR                                 = 0x29000010ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CTRL0_CLEAR                              = 0x29000020ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CTRL0                                    = 0x2A000000ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CTRL0_OR                                 = 0x2A000010ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CTRL0_CLEAR                              = 0x2A000020ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CTRL0                                    = 0x2B000000ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CTRL0_OR                                 = 0x2B000010ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CTRL0_CLEAR                              = 0x2B000020ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CTRL0                                    = 0x2C000000ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CTRL0_OR                                 = 0x2C000010ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CTRL0_CLEAR                              = 0x2C000020ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CTRL0                                    = 0x2D000000ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CTRL0_OR                                 = 0x2D000010ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CTRL0_CLEAR                              = 0x2D000020ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CTRL0                                    = 0x2E000000ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CTRL0_OR                                 = 0x2E000010ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CTRL0_CLEAR                              = 0x2E000020ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CTRL0                                    = 0x2F000000ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CTRL0_OR                                 = 0x2F000010ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CTRL0_CLEAR                              = 0x2F000020ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CTRL0                                    = 0x30000000ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CTRL0_OR                                 = 0x30000010ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CTRL0_CLEAR                              = 0x30000020ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CTRL0                                    = 0x31000000ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CTRL0_OR                                 = 0x31000010ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CTRL0_CLEAR                              = 0x31000020ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CTRL0                                    = 0x32000000ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CTRL0_OR                                 = 0x32000010ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CTRL0_CLEAR                              = 0x32000020ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CTRL0                                    = 0x33000000ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CTRL0_OR                                 = 0x33000010ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CTRL0_CLEAR                              = 0x33000020ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CTRL0                                    = 0x34000000ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CTRL0_OR                                 = 0x34000010ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CTRL0_CLEAR                              = 0x34000020ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CTRL0                                    = 0x35000000ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CTRL0_OR                                 = 0x35000010ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CTRL0_CLEAR                              = 0x35000020ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CTRL0                                    = 0x36000000ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CTRL0_OR                                 = 0x36000010ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CTRL0_CLEAR                              = 0x36000020ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CTRL0                                    = 0x37000000ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CTRL0_OR                                 = 0x37000010ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CTRL0_CLEAR                              = 0x37000020ull;


static const uint64_t P9N2_PERV_CPLT_CTRL1                                         = 0x00000001ull;

static const uint64_t P9N2_PERV_TP_CPLT_CTRL1                                      = 0x01000001ull;

static const uint64_t P9N2_PERV_CPLT_CTRL1_OR                                      = 0x00000011ull;

static const uint64_t P9N2_PERV_TP_CPLT_CTRL1_OR                                   = 0x01000011ull;

static const uint64_t P9N2_PERV_CPLT_CTRL1_CLEAR                                   = 0x00000021ull;

static const uint64_t P9N2_PERV_TP_CPLT_CTRL1_CLEAR                                = 0x01000021ull;

static const uint64_t P9N2_PERV_N0_CPLT_CTRL1                                      = 0x02000001ull;

static const uint64_t P9N2_PERV_N0_CPLT_CTRL1_OR                                   = 0x02000011ull;

static const uint64_t P9N2_PERV_N0_CPLT_CTRL1_CLEAR                                = 0x02000021ull;

static const uint64_t P9N2_PERV_N1_CPLT_CTRL1                                      = 0x03000001ull;

static const uint64_t P9N2_PERV_N1_CPLT_CTRL1_OR                                   = 0x03000011ull;

static const uint64_t P9N2_PERV_N1_CPLT_CTRL1_CLEAR                                = 0x03000021ull;

static const uint64_t P9N2_PERV_N2_CPLT_CTRL1                                      = 0x04000001ull;

static const uint64_t P9N2_PERV_N2_CPLT_CTRL1_OR                                   = 0x04000011ull;

static const uint64_t P9N2_PERV_N2_CPLT_CTRL1_CLEAR                                = 0x04000021ull;

static const uint64_t P9N2_PERV_N3_CPLT_CTRL1                                      = 0x05000001ull;

static const uint64_t P9N2_PERV_N3_CPLT_CTRL1_OR                                   = 0x05000011ull;

static const uint64_t P9N2_PERV_N3_CPLT_CTRL1_CLEAR                                = 0x05000021ull;

static const uint64_t P9N2_PERV_XB_CPLT_CTRL1                                      = 0x06000001ull;

static const uint64_t P9N2_PERV_XB_CPLT_CTRL1_OR                                   = 0x06000011ull;

static const uint64_t P9N2_PERV_XB_CPLT_CTRL1_CLEAR                                = 0x06000021ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CTRL1                                    = 0x07000001ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CTRL1_OR                                 = 0x07000011ull;

static const uint64_t P9N2_PERV_MC01_CPLT_CTRL1_CLEAR                              = 0x07000021ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CTRL1                                    = 0x08000001ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CTRL1_OR                                 = 0x08000011ull;

static const uint64_t P9N2_PERV_MC23_CPLT_CTRL1_CLEAR                              = 0x08000021ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CTRL1                                     = 0x09000001ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CTRL1_OR                                  = 0x09000011ull;

static const uint64_t P9N2_PERV_OB0_CPLT_CTRL1_CLEAR                               = 0x09000021ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CTRL1                                     = 0x0C000001ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CTRL1_OR                                  = 0x0C000011ull;

static const uint64_t P9N2_PERV_OB3_CPLT_CTRL1_CLEAR                               = 0x0C000021ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CTRL1                                    = 0x0D000001ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CTRL1_OR                                 = 0x0D000011ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_CTRL1_CLEAR                              = 0x0D000021ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CTRL1                                    = 0x0E000001ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CTRL1_OR                                 = 0x0E000011ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_CTRL1_CLEAR                              = 0x0E000021ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CTRL1                                    = 0x0F000001ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CTRL1_OR                                 = 0x0F000011ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_CTRL1_CLEAR                              = 0x0F000021ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CTRL1                                    = 0x10000001ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CTRL1_OR                                 = 0x10000011ull;

static const uint64_t P9N2_PERV_EP00_CPLT_CTRL1_CLEAR                              = 0x10000021ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CTRL1                                    = 0x11000001ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CTRL1_OR                                 = 0x11000011ull;

static const uint64_t P9N2_PERV_EP01_CPLT_CTRL1_CLEAR                              = 0x11000021ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CTRL1                                    = 0x12000001ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CTRL1_OR                                 = 0x12000011ull;

static const uint64_t P9N2_PERV_EP02_CPLT_CTRL1_CLEAR                              = 0x12000021ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CTRL1                                    = 0x13000001ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CTRL1_OR                                 = 0x13000011ull;

static const uint64_t P9N2_PERV_EP03_CPLT_CTRL1_CLEAR                              = 0x13000021ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CTRL1                                    = 0x14000001ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CTRL1_OR                                 = 0x14000011ull;

static const uint64_t P9N2_PERV_EP04_CPLT_CTRL1_CLEAR                              = 0x14000021ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CTRL1                                    = 0x15000001ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CTRL1_OR                                 = 0x15000011ull;

static const uint64_t P9N2_PERV_EP05_CPLT_CTRL1_CLEAR                              = 0x15000021ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CTRL1                                    = 0x20000001ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CTRL1_OR                                 = 0x20000011ull;

static const uint64_t P9N2_PERV_EC00_CPLT_CTRL1_CLEAR                              = 0x20000021ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CTRL1                                    = 0x21000001ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CTRL1_OR                                 = 0x21000011ull;

static const uint64_t P9N2_PERV_EC01_CPLT_CTRL1_CLEAR                              = 0x21000021ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CTRL1                                    = 0x22000001ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CTRL1_OR                                 = 0x22000011ull;

static const uint64_t P9N2_PERV_EC02_CPLT_CTRL1_CLEAR                              = 0x22000021ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CTRL1                                    = 0x23000001ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CTRL1_OR                                 = 0x23000011ull;

static const uint64_t P9N2_PERV_EC03_CPLT_CTRL1_CLEAR                              = 0x23000021ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CTRL1                                    = 0x24000001ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CTRL1_OR                                 = 0x24000011ull;

static const uint64_t P9N2_PERV_EC04_CPLT_CTRL1_CLEAR                              = 0x24000021ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CTRL1                                    = 0x25000001ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CTRL1_OR                                 = 0x25000011ull;

static const uint64_t P9N2_PERV_EC05_CPLT_CTRL1_CLEAR                              = 0x25000021ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CTRL1                                    = 0x26000001ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CTRL1_OR                                 = 0x26000011ull;

static const uint64_t P9N2_PERV_EC06_CPLT_CTRL1_CLEAR                              = 0x26000021ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CTRL1                                    = 0x27000001ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CTRL1_OR                                 = 0x27000011ull;

static const uint64_t P9N2_PERV_EC07_CPLT_CTRL1_CLEAR                              = 0x27000021ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CTRL1                                    = 0x28000001ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CTRL1_OR                                 = 0x28000011ull;

static const uint64_t P9N2_PERV_EC08_CPLT_CTRL1_CLEAR                              = 0x28000021ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CTRL1                                    = 0x29000001ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CTRL1_OR                                 = 0x29000011ull;

static const uint64_t P9N2_PERV_EC09_CPLT_CTRL1_CLEAR                              = 0x29000021ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CTRL1                                    = 0x2A000001ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CTRL1_OR                                 = 0x2A000011ull;

static const uint64_t P9N2_PERV_EC10_CPLT_CTRL1_CLEAR                              = 0x2A000021ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CTRL1                                    = 0x2B000001ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CTRL1_OR                                 = 0x2B000011ull;

static const uint64_t P9N2_PERV_EC11_CPLT_CTRL1_CLEAR                              = 0x2B000021ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CTRL1                                    = 0x2C000001ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CTRL1_OR                                 = 0x2C000011ull;

static const uint64_t P9N2_PERV_EC12_CPLT_CTRL1_CLEAR                              = 0x2C000021ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CTRL1                                    = 0x2D000001ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CTRL1_OR                                 = 0x2D000011ull;

static const uint64_t P9N2_PERV_EC13_CPLT_CTRL1_CLEAR                              = 0x2D000021ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CTRL1                                    = 0x2E000001ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CTRL1_OR                                 = 0x2E000011ull;

static const uint64_t P9N2_PERV_EC14_CPLT_CTRL1_CLEAR                              = 0x2E000021ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CTRL1                                    = 0x2F000001ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CTRL1_OR                                 = 0x2F000011ull;

static const uint64_t P9N2_PERV_EC15_CPLT_CTRL1_CLEAR                              = 0x2F000021ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CTRL1                                    = 0x30000001ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CTRL1_OR                                 = 0x30000011ull;

static const uint64_t P9N2_PERV_EC16_CPLT_CTRL1_CLEAR                              = 0x30000021ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CTRL1                                    = 0x31000001ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CTRL1_OR                                 = 0x31000011ull;

static const uint64_t P9N2_PERV_EC17_CPLT_CTRL1_CLEAR                              = 0x31000021ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CTRL1                                    = 0x32000001ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CTRL1_OR                                 = 0x32000011ull;

static const uint64_t P9N2_PERV_EC18_CPLT_CTRL1_CLEAR                              = 0x32000021ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CTRL1                                    = 0x33000001ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CTRL1_OR                                 = 0x33000011ull;

static const uint64_t P9N2_PERV_EC19_CPLT_CTRL1_CLEAR                              = 0x33000021ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CTRL1                                    = 0x34000001ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CTRL1_OR                                 = 0x34000011ull;

static const uint64_t P9N2_PERV_EC20_CPLT_CTRL1_CLEAR                              = 0x34000021ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CTRL1                                    = 0x35000001ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CTRL1_OR                                 = 0x35000011ull;

static const uint64_t P9N2_PERV_EC21_CPLT_CTRL1_CLEAR                              = 0x35000021ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CTRL1                                    = 0x36000001ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CTRL1_OR                                 = 0x36000011ull;

static const uint64_t P9N2_PERV_EC22_CPLT_CTRL1_CLEAR                              = 0x36000021ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CTRL1                                    = 0x37000001ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CTRL1_OR                                 = 0x37000011ull;

static const uint64_t P9N2_PERV_EC23_CPLT_CTRL1_CLEAR                              = 0x37000021ull;


static const uint64_t P9N2_PERV_CPLT_MASK0                                         = 0x00000101ull;

static const uint64_t P9N2_PERV_TP_CPLT_MASK0                                      = 0x01000101ull;

static const uint64_t P9N2_PERV_N0_CPLT_MASK0                                      = 0x02000101ull;

static const uint64_t P9N2_PERV_N1_CPLT_MASK0                                      = 0x03000101ull;

static const uint64_t P9N2_PERV_N2_CPLT_MASK0                                      = 0x04000101ull;

static const uint64_t P9N2_PERV_N3_CPLT_MASK0                                      = 0x05000101ull;

static const uint64_t P9N2_PERV_XB_CPLT_MASK0                                      = 0x06000101ull;

static const uint64_t P9N2_PERV_MC01_CPLT_MASK0                                    = 0x07000101ull;

static const uint64_t P9N2_PERV_MC23_CPLT_MASK0                                    = 0x08000101ull;

static const uint64_t P9N2_PERV_OB0_CPLT_MASK0                                     = 0x09000101ull;

static const uint64_t P9N2_PERV_OB3_CPLT_MASK0                                     = 0x0C000101ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_MASK0                                    = 0x0D000101ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_MASK0                                    = 0x0E000101ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_MASK0                                    = 0x0F000101ull;

static const uint64_t P9N2_PERV_EP00_CPLT_MASK0                                    = 0x10000101ull;

static const uint64_t P9N2_PERV_EP01_CPLT_MASK0                                    = 0x11000101ull;

static const uint64_t P9N2_PERV_EP02_CPLT_MASK0                                    = 0x12000101ull;

static const uint64_t P9N2_PERV_EP03_CPLT_MASK0                                    = 0x13000101ull;

static const uint64_t P9N2_PERV_EP04_CPLT_MASK0                                    = 0x14000101ull;

static const uint64_t P9N2_PERV_EP05_CPLT_MASK0                                    = 0x15000101ull;

static const uint64_t P9N2_PERV_EC00_CPLT_MASK0                                    = 0x20000101ull;

static const uint64_t P9N2_PERV_EC01_CPLT_MASK0                                    = 0x21000101ull;

static const uint64_t P9N2_PERV_EC02_CPLT_MASK0                                    = 0x22000101ull;

static const uint64_t P9N2_PERV_EC03_CPLT_MASK0                                    = 0x23000101ull;

static const uint64_t P9N2_PERV_EC04_CPLT_MASK0                                    = 0x24000101ull;

static const uint64_t P9N2_PERV_EC05_CPLT_MASK0                                    = 0x25000101ull;

static const uint64_t P9N2_PERV_EC06_CPLT_MASK0                                    = 0x26000101ull;

static const uint64_t P9N2_PERV_EC07_CPLT_MASK0                                    = 0x27000101ull;

static const uint64_t P9N2_PERV_EC08_CPLT_MASK0                                    = 0x28000101ull;

static const uint64_t P9N2_PERV_EC09_CPLT_MASK0                                    = 0x29000101ull;

static const uint64_t P9N2_PERV_EC10_CPLT_MASK0                                    = 0x2A000101ull;

static const uint64_t P9N2_PERV_EC11_CPLT_MASK0                                    = 0x2B000101ull;

static const uint64_t P9N2_PERV_EC12_CPLT_MASK0                                    = 0x2C000101ull;

static const uint64_t P9N2_PERV_EC13_CPLT_MASK0                                    = 0x2D000101ull;

static const uint64_t P9N2_PERV_EC14_CPLT_MASK0                                    = 0x2E000101ull;

static const uint64_t P9N2_PERV_EC15_CPLT_MASK0                                    = 0x2F000101ull;

static const uint64_t P9N2_PERV_EC16_CPLT_MASK0                                    = 0x30000101ull;

static const uint64_t P9N2_PERV_EC17_CPLT_MASK0                                    = 0x31000101ull;

static const uint64_t P9N2_PERV_EC18_CPLT_MASK0                                    = 0x32000101ull;

static const uint64_t P9N2_PERV_EC19_CPLT_MASK0                                    = 0x33000101ull;

static const uint64_t P9N2_PERV_EC20_CPLT_MASK0                                    = 0x34000101ull;

static const uint64_t P9N2_PERV_EC21_CPLT_MASK0                                    = 0x35000101ull;

static const uint64_t P9N2_PERV_EC22_CPLT_MASK0                                    = 0x36000101ull;

static const uint64_t P9N2_PERV_EC23_CPLT_MASK0                                    = 0x37000101ull;


static const uint64_t P9N2_PERV_CPLT_STAT0                                         = 0x00000100ull;

static const uint64_t P9N2_PERV_TP_CPLT_STAT0                                      = 0x01000100ull;

static const uint64_t P9N2_PERV_N0_CPLT_STAT0                                      = 0x02000100ull;

static const uint64_t P9N2_PERV_N1_CPLT_STAT0                                      = 0x03000100ull;

static const uint64_t P9N2_PERV_N2_CPLT_STAT0                                      = 0x04000100ull;

static const uint64_t P9N2_PERV_N3_CPLT_STAT0                                      = 0x05000100ull;

static const uint64_t P9N2_PERV_XB_CPLT_STAT0                                      = 0x06000100ull;

static const uint64_t P9N2_PERV_MC01_CPLT_STAT0                                    = 0x07000100ull;

static const uint64_t P9N2_PERV_MC23_CPLT_STAT0                                    = 0x08000100ull;

static const uint64_t P9N2_PERV_OB0_CPLT_STAT0                                     = 0x09000100ull;

static const uint64_t P9N2_PERV_OB3_CPLT_STAT0                                     = 0x0C000100ull;

static const uint64_t P9N2_PERV_PCI0_CPLT_STAT0                                    = 0x0D000100ull;

static const uint64_t P9N2_PERV_PCI1_CPLT_STAT0                                    = 0x0E000100ull;

static const uint64_t P9N2_PERV_PCI2_CPLT_STAT0                                    = 0x0F000100ull;

static const uint64_t P9N2_PERV_EP00_CPLT_STAT0                                    = 0x10000100ull;

static const uint64_t P9N2_PERV_EP01_CPLT_STAT0                                    = 0x11000100ull;

static const uint64_t P9N2_PERV_EP02_CPLT_STAT0                                    = 0x12000100ull;

static const uint64_t P9N2_PERV_EP03_CPLT_STAT0                                    = 0x13000100ull;

static const uint64_t P9N2_PERV_EP04_CPLT_STAT0                                    = 0x14000100ull;

static const uint64_t P9N2_PERV_EP05_CPLT_STAT0                                    = 0x15000100ull;

static const uint64_t P9N2_PERV_EC00_CPLT_STAT0                                    = 0x20000100ull;

static const uint64_t P9N2_PERV_EC01_CPLT_STAT0                                    = 0x21000100ull;

static const uint64_t P9N2_PERV_EC02_CPLT_STAT0                                    = 0x22000100ull;

static const uint64_t P9N2_PERV_EC03_CPLT_STAT0                                    = 0x23000100ull;

static const uint64_t P9N2_PERV_EC04_CPLT_STAT0                                    = 0x24000100ull;

static const uint64_t P9N2_PERV_EC05_CPLT_STAT0                                    = 0x25000100ull;

static const uint64_t P9N2_PERV_EC06_CPLT_STAT0                                    = 0x26000100ull;

static const uint64_t P9N2_PERV_EC07_CPLT_STAT0                                    = 0x27000100ull;

static const uint64_t P9N2_PERV_EC08_CPLT_STAT0                                    = 0x28000100ull;

static const uint64_t P9N2_PERV_EC09_CPLT_STAT0                                    = 0x29000100ull;

static const uint64_t P9N2_PERV_EC10_CPLT_STAT0                                    = 0x2A000100ull;

static const uint64_t P9N2_PERV_EC11_CPLT_STAT0                                    = 0x2B000100ull;

static const uint64_t P9N2_PERV_EC12_CPLT_STAT0                                    = 0x2C000100ull;

static const uint64_t P9N2_PERV_EC13_CPLT_STAT0                                    = 0x2D000100ull;

static const uint64_t P9N2_PERV_EC14_CPLT_STAT0                                    = 0x2E000100ull;

static const uint64_t P9N2_PERV_EC15_CPLT_STAT0                                    = 0x2F000100ull;

static const uint64_t P9N2_PERV_EC16_CPLT_STAT0                                    = 0x30000100ull;

static const uint64_t P9N2_PERV_EC17_CPLT_STAT0                                    = 0x31000100ull;

static const uint64_t P9N2_PERV_EC18_CPLT_STAT0                                    = 0x32000100ull;

static const uint64_t P9N2_PERV_EC19_CPLT_STAT0                                    = 0x33000100ull;

static const uint64_t P9N2_PERV_EC20_CPLT_STAT0                                    = 0x34000100ull;

static const uint64_t P9N2_PERV_EC21_CPLT_STAT0                                    = 0x35000100ull;

static const uint64_t P9N2_PERV_EC22_CPLT_STAT0                                    = 0x36000100ull;

static const uint64_t P9N2_PERV_EC23_CPLT_STAT0                                    = 0x37000100ull;


static const uint64_t P9N2_PERV_EC00_CPPM_CACCR                                    = 0x200F0168ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CACCR_CLEAR                              = 0x200F0169ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CACCR_OR                                 = 0x200F016Aull;

static const uint64_t P9N2_PERV_EC01_CPPM_CACCR                                    = 0x210F0168ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CACCR_CLEAR                              = 0x210F0169ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CACCR_OR                                 = 0x210F016Aull;

static const uint64_t P9N2_PERV_EC02_CPPM_CACCR                                    = 0x220F0168ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CACCR_CLEAR                              = 0x220F0169ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CACCR_OR                                 = 0x220F016Aull;

static const uint64_t P9N2_PERV_EC03_CPPM_CACCR                                    = 0x230F0168ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CACCR_CLEAR                              = 0x230F0169ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CACCR_OR                                 = 0x230F016Aull;

static const uint64_t P9N2_PERV_EC04_CPPM_CACCR                                    = 0x240F0168ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CACCR_CLEAR                              = 0x240F0169ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CACCR_OR                                 = 0x240F016Aull;

static const uint64_t P9N2_PERV_EC05_CPPM_CACCR                                    = 0x250F0168ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CACCR_CLEAR                              = 0x250F0169ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CACCR_OR                                 = 0x250F016Aull;

static const uint64_t P9N2_PERV_EC06_CPPM_CACCR                                    = 0x260F0168ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CACCR_CLEAR                              = 0x260F0169ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CACCR_OR                                 = 0x260F016Aull;

static const uint64_t P9N2_PERV_EC07_CPPM_CACCR                                    = 0x270F0168ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CACCR_CLEAR                              = 0x270F0169ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CACCR_OR                                 = 0x270F016Aull;

static const uint64_t P9N2_PERV_EC08_CPPM_CACCR                                    = 0x280F0168ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CACCR_CLEAR                              = 0x280F0169ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CACCR_OR                                 = 0x280F016Aull;

static const uint64_t P9N2_PERV_EC09_CPPM_CACCR                                    = 0x290F0168ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CACCR_CLEAR                              = 0x290F0169ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CACCR_OR                                 = 0x290F016Aull;

static const uint64_t P9N2_PERV_EC10_CPPM_CACCR                                    = 0x2A0F0168ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CACCR_CLEAR                              = 0x2A0F0169ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CACCR_OR                                 = 0x2A0F016Aull;

static const uint64_t P9N2_PERV_EC11_CPPM_CACCR                                    = 0x2B0F0168ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CACCR_CLEAR                              = 0x2B0F0169ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CACCR_OR                                 = 0x2B0F016Aull;

static const uint64_t P9N2_PERV_EC12_CPPM_CACCR                                    = 0x2C0F0168ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CACCR_CLEAR                              = 0x2C0F0169ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CACCR_OR                                 = 0x2C0F016Aull;

static const uint64_t P9N2_PERV_EC13_CPPM_CACCR                                    = 0x2D0F0168ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CACCR_CLEAR                              = 0x2D0F0169ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CACCR_OR                                 = 0x2D0F016Aull;

static const uint64_t P9N2_PERV_EC14_CPPM_CACCR                                    = 0x2E0F0168ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CACCR_CLEAR                              = 0x2E0F0169ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CACCR_OR                                 = 0x2E0F016Aull;

static const uint64_t P9N2_PERV_EC15_CPPM_CACCR                                    = 0x2F0F0168ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CACCR_CLEAR                              = 0x2F0F0169ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CACCR_OR                                 = 0x2F0F016Aull;

static const uint64_t P9N2_PERV_EC16_CPPM_CACCR                                    = 0x300F0168ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CACCR_CLEAR                              = 0x300F0169ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CACCR_OR                                 = 0x300F016Aull;

static const uint64_t P9N2_PERV_EC17_CPPM_CACCR                                    = 0x310F0168ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CACCR_CLEAR                              = 0x310F0169ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CACCR_OR                                 = 0x310F016Aull;

static const uint64_t P9N2_PERV_EC18_CPPM_CACCR                                    = 0x320F0168ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CACCR_CLEAR                              = 0x320F0169ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CACCR_OR                                 = 0x320F016Aull;

static const uint64_t P9N2_PERV_EC19_CPPM_CACCR                                    = 0x330F0168ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CACCR_CLEAR                              = 0x330F0169ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CACCR_OR                                 = 0x330F016Aull;

static const uint64_t P9N2_PERV_EC20_CPPM_CACCR                                    = 0x340F0168ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CACCR_CLEAR                              = 0x340F0169ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CACCR_OR                                 = 0x340F016Aull;

static const uint64_t P9N2_PERV_EC21_CPPM_CACCR                                    = 0x350F0168ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CACCR_CLEAR                              = 0x350F0169ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CACCR_OR                                 = 0x350F016Aull;

static const uint64_t P9N2_PERV_EC22_CPPM_CACCR                                    = 0x360F0168ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CACCR_CLEAR                              = 0x360F0169ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CACCR_OR                                 = 0x360F016Aull;

static const uint64_t P9N2_PERV_EC23_CPPM_CACCR                                    = 0x370F0168ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CACCR_CLEAR                              = 0x370F0169ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CACCR_OR                                 = 0x370F016Aull;


static const uint64_t P9N2_PERV_EC00_CPPM_CACSR                                    = 0x200F016Bull;

static const uint64_t P9N2_PERV_EC01_CPPM_CACSR                                    = 0x210F016Bull;

static const uint64_t P9N2_PERV_EC02_CPPM_CACSR                                    = 0x220F016Bull;

static const uint64_t P9N2_PERV_EC03_CPPM_CACSR                                    = 0x230F016Bull;

static const uint64_t P9N2_PERV_EC04_CPPM_CACSR                                    = 0x240F016Bull;

static const uint64_t P9N2_PERV_EC05_CPPM_CACSR                                    = 0x250F016Bull;

static const uint64_t P9N2_PERV_EC06_CPPM_CACSR                                    = 0x260F016Bull;

static const uint64_t P9N2_PERV_EC07_CPPM_CACSR                                    = 0x270F016Bull;

static const uint64_t P9N2_PERV_EC08_CPPM_CACSR                                    = 0x280F016Bull;

static const uint64_t P9N2_PERV_EC09_CPPM_CACSR                                    = 0x290F016Bull;

static const uint64_t P9N2_PERV_EC10_CPPM_CACSR                                    = 0x2A0F016Bull;

static const uint64_t P9N2_PERV_EC11_CPPM_CACSR                                    = 0x2B0F016Bull;

static const uint64_t P9N2_PERV_EC12_CPPM_CACSR                                    = 0x2C0F016Bull;

static const uint64_t P9N2_PERV_EC13_CPPM_CACSR                                    = 0x2D0F016Bull;

static const uint64_t P9N2_PERV_EC14_CPPM_CACSR                                    = 0x2E0F016Bull;

static const uint64_t P9N2_PERV_EC15_CPPM_CACSR                                    = 0x2F0F016Bull;

static const uint64_t P9N2_PERV_EC16_CPPM_CACSR                                    = 0x300F016Bull;

static const uint64_t P9N2_PERV_EC17_CPPM_CACSR                                    = 0x310F016Bull;

static const uint64_t P9N2_PERV_EC18_CPPM_CACSR                                    = 0x320F016Bull;

static const uint64_t P9N2_PERV_EC19_CPPM_CACSR                                    = 0x330F016Bull;

static const uint64_t P9N2_PERV_EC20_CPPM_CACSR                                    = 0x340F016Bull;

static const uint64_t P9N2_PERV_EC21_CPPM_CACSR                                    = 0x350F016Bull;

static const uint64_t P9N2_PERV_EC22_CPPM_CACSR                                    = 0x360F016Bull;

static const uint64_t P9N2_PERV_EC23_CPPM_CACSR                                    = 0x370F016Bull;


static const uint64_t P9N2_PERV_EC00_CPPM_CIIR                                     = 0x200F01ADull;

static const uint64_t P9N2_PERV_EC01_CPPM_CIIR                                     = 0x210F01ADull;

static const uint64_t P9N2_PERV_EC02_CPPM_CIIR                                     = 0x220F01ADull;

static const uint64_t P9N2_PERV_EC03_CPPM_CIIR                                     = 0x230F01ADull;

static const uint64_t P9N2_PERV_EC04_CPPM_CIIR                                     = 0x240F01ADull;

static const uint64_t P9N2_PERV_EC05_CPPM_CIIR                                     = 0x250F01ADull;

static const uint64_t P9N2_PERV_EC06_CPPM_CIIR                                     = 0x260F01ADull;

static const uint64_t P9N2_PERV_EC07_CPPM_CIIR                                     = 0x270F01ADull;

static const uint64_t P9N2_PERV_EC08_CPPM_CIIR                                     = 0x280F01ADull;

static const uint64_t P9N2_PERV_EC09_CPPM_CIIR                                     = 0x290F01ADull;

static const uint64_t P9N2_PERV_EC10_CPPM_CIIR                                     = 0x2A0F01ADull;

static const uint64_t P9N2_PERV_EC11_CPPM_CIIR                                     = 0x2B0F01ADull;

static const uint64_t P9N2_PERV_EC12_CPPM_CIIR                                     = 0x2C0F01ADull;

static const uint64_t P9N2_PERV_EC13_CPPM_CIIR                                     = 0x2D0F01ADull;

static const uint64_t P9N2_PERV_EC14_CPPM_CIIR                                     = 0x2E0F01ADull;

static const uint64_t P9N2_PERV_EC15_CPPM_CIIR                                     = 0x2F0F01ADull;

static const uint64_t P9N2_PERV_EC16_CPPM_CIIR                                     = 0x300F01ADull;

static const uint64_t P9N2_PERV_EC17_CPPM_CIIR                                     = 0x310F01ADull;

static const uint64_t P9N2_PERV_EC18_CPPM_CIIR                                     = 0x320F01ADull;

static const uint64_t P9N2_PERV_EC19_CPPM_CIIR                                     = 0x330F01ADull;

static const uint64_t P9N2_PERV_EC20_CPPM_CIIR                                     = 0x340F01ADull;

static const uint64_t P9N2_PERV_EC21_CPPM_CIIR                                     = 0x350F01ADull;

static const uint64_t P9N2_PERV_EC22_CPPM_CIIR                                     = 0x360F01ADull;

static const uint64_t P9N2_PERV_EC23_CPPM_CIIR                                     = 0x370F01ADull;


static const uint64_t P9N2_PERV_EC00_CPPM_CISR                                     = 0x200F01AEull;

static const uint64_t P9N2_PERV_EC01_CPPM_CISR                                     = 0x210F01AEull;

static const uint64_t P9N2_PERV_EC02_CPPM_CISR                                     = 0x220F01AEull;

static const uint64_t P9N2_PERV_EC03_CPPM_CISR                                     = 0x230F01AEull;

static const uint64_t P9N2_PERV_EC04_CPPM_CISR                                     = 0x240F01AEull;

static const uint64_t P9N2_PERV_EC05_CPPM_CISR                                     = 0x250F01AEull;

static const uint64_t P9N2_PERV_EC06_CPPM_CISR                                     = 0x260F01AEull;

static const uint64_t P9N2_PERV_EC07_CPPM_CISR                                     = 0x270F01AEull;

static const uint64_t P9N2_PERV_EC08_CPPM_CISR                                     = 0x280F01AEull;

static const uint64_t P9N2_PERV_EC09_CPPM_CISR                                     = 0x290F01AEull;

static const uint64_t P9N2_PERV_EC10_CPPM_CISR                                     = 0x2A0F01AEull;

static const uint64_t P9N2_PERV_EC11_CPPM_CISR                                     = 0x2B0F01AEull;

static const uint64_t P9N2_PERV_EC12_CPPM_CISR                                     = 0x2C0F01AEull;

static const uint64_t P9N2_PERV_EC13_CPPM_CISR                                     = 0x2D0F01AEull;

static const uint64_t P9N2_PERV_EC14_CPPM_CISR                                     = 0x2E0F01AEull;

static const uint64_t P9N2_PERV_EC15_CPPM_CISR                                     = 0x2F0F01AEull;

static const uint64_t P9N2_PERV_EC16_CPPM_CISR                                     = 0x300F01AEull;

static const uint64_t P9N2_PERV_EC17_CPPM_CISR                                     = 0x310F01AEull;

static const uint64_t P9N2_PERV_EC18_CPPM_CISR                                     = 0x320F01AEull;

static const uint64_t P9N2_PERV_EC19_CPPM_CISR                                     = 0x330F01AEull;

static const uint64_t P9N2_PERV_EC20_CPPM_CISR                                     = 0x340F01AEull;

static const uint64_t P9N2_PERV_EC21_CPPM_CISR                                     = 0x350F01AEull;

static const uint64_t P9N2_PERV_EC22_CPPM_CISR                                     = 0x360F01AEull;

static const uint64_t P9N2_PERV_EC23_CPPM_CISR                                     = 0x370F01AEull;


static const uint64_t P9N2_PERV_EC00_CPPM_CIVRMLCR                                 = 0x200F01B7ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CIVRMLCR                                 = 0x210F01B7ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CIVRMLCR                                 = 0x220F01B7ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CIVRMLCR                                 = 0x230F01B7ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CIVRMLCR                                 = 0x240F01B7ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CIVRMLCR                                 = 0x250F01B7ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CIVRMLCR                                 = 0x260F01B7ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CIVRMLCR                                 = 0x270F01B7ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CIVRMLCR                                 = 0x280F01B7ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CIVRMLCR                                 = 0x290F01B7ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CIVRMLCR                                 = 0x2A0F01B7ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CIVRMLCR                                 = 0x2B0F01B7ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CIVRMLCR                                 = 0x2C0F01B7ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CIVRMLCR                                 = 0x2D0F01B7ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CIVRMLCR                                 = 0x2E0F01B7ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CIVRMLCR                                 = 0x2F0F01B7ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CIVRMLCR                                 = 0x300F01B7ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CIVRMLCR                                 = 0x310F01B7ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CIVRMLCR                                 = 0x320F01B7ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CIVRMLCR                                 = 0x330F01B7ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CIVRMLCR                                 = 0x340F01B7ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CIVRMLCR                                 = 0x350F01B7ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CIVRMLCR                                 = 0x360F01B7ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CIVRMLCR                                 = 0x370F01B7ull;


static const uint64_t P9N2_PERV_EC00_CPPM_CMEDATA                                  = 0x200F01A8ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDATA_CLEAR                            = 0x200F01A9ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDATA_OR                               = 0x200F01AAull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDATA                                  = 0x210F01A8ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDATA_CLEAR                            = 0x210F01A9ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDATA_OR                               = 0x210F01AAull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDATA                                  = 0x220F01A8ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDATA_CLEAR                            = 0x220F01A9ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDATA_OR                               = 0x220F01AAull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDATA                                  = 0x230F01A8ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDATA_CLEAR                            = 0x230F01A9ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDATA_OR                               = 0x230F01AAull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDATA                                  = 0x240F01A8ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDATA_CLEAR                            = 0x240F01A9ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDATA_OR                               = 0x240F01AAull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDATA                                  = 0x250F01A8ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDATA_CLEAR                            = 0x250F01A9ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDATA_OR                               = 0x250F01AAull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDATA                                  = 0x260F01A8ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDATA_CLEAR                            = 0x260F01A9ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDATA_OR                               = 0x260F01AAull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDATA                                  = 0x270F01A8ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDATA_CLEAR                            = 0x270F01A9ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDATA_OR                               = 0x270F01AAull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDATA                                  = 0x280F01A8ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDATA_CLEAR                            = 0x280F01A9ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDATA_OR                               = 0x280F01AAull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDATA                                  = 0x290F01A8ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDATA_CLEAR                            = 0x290F01A9ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDATA_OR                               = 0x290F01AAull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDATA                                  = 0x2A0F01A8ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDATA_CLEAR                            = 0x2A0F01A9ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDATA_OR                               = 0x2A0F01AAull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDATA                                  = 0x2B0F01A8ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDATA_CLEAR                            = 0x2B0F01A9ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDATA_OR                               = 0x2B0F01AAull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDATA                                  = 0x2C0F01A8ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDATA_CLEAR                            = 0x2C0F01A9ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDATA_OR                               = 0x2C0F01AAull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDATA                                  = 0x2D0F01A8ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDATA_CLEAR                            = 0x2D0F01A9ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDATA_OR                               = 0x2D0F01AAull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDATA                                  = 0x2E0F01A8ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDATA_CLEAR                            = 0x2E0F01A9ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDATA_OR                               = 0x2E0F01AAull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDATA                                  = 0x2F0F01A8ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDATA_CLEAR                            = 0x2F0F01A9ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDATA_OR                               = 0x2F0F01AAull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDATA                                  = 0x300F01A8ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDATA_CLEAR                            = 0x300F01A9ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDATA_OR                               = 0x300F01AAull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDATA                                  = 0x310F01A8ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDATA_CLEAR                            = 0x310F01A9ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDATA_OR                               = 0x310F01AAull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDATA                                  = 0x320F01A8ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDATA_CLEAR                            = 0x320F01A9ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDATA_OR                               = 0x320F01AAull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDATA                                  = 0x330F01A8ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDATA_CLEAR                            = 0x330F01A9ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDATA_OR                               = 0x330F01AAull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDATA                                  = 0x340F01A8ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDATA_CLEAR                            = 0x340F01A9ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDATA_OR                               = 0x340F01AAull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDATA                                  = 0x350F01A8ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDATA_CLEAR                            = 0x350F01A9ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDATA_OR                               = 0x350F01AAull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDATA                                  = 0x360F01A8ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDATA_CLEAR                            = 0x360F01A9ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDATA_OR                               = 0x360F01AAull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDATA                                  = 0x370F01A8ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDATA_CLEAR                            = 0x370F01A9ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDATA_OR                               = 0x370F01AAull;


static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB0                                   = 0x200F0190ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB0_CLEAR                             = 0x200F0191ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB0_OR                                = 0x200F0192ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB0                                   = 0x210F0190ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB0_CLEAR                             = 0x210F0191ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB0_OR                                = 0x210F0192ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB0                                   = 0x220F0190ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB0_CLEAR                             = 0x220F0191ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB0_OR                                = 0x220F0192ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB0                                   = 0x230F0190ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB0_CLEAR                             = 0x230F0191ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB0_OR                                = 0x230F0192ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB0                                   = 0x240F0190ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB0_CLEAR                             = 0x240F0191ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB0_OR                                = 0x240F0192ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB0                                   = 0x250F0190ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB0_CLEAR                             = 0x250F0191ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB0_OR                                = 0x250F0192ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB0                                   = 0x260F0190ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB0_CLEAR                             = 0x260F0191ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB0_OR                                = 0x260F0192ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB0                                   = 0x270F0190ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB0_CLEAR                             = 0x270F0191ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB0_OR                                = 0x270F0192ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB0                                   = 0x280F0190ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB0_CLEAR                             = 0x280F0191ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB0_OR                                = 0x280F0192ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB0                                   = 0x290F0190ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB0_CLEAR                             = 0x290F0191ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB0_OR                                = 0x290F0192ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB0                                   = 0x2A0F0190ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB0_CLEAR                             = 0x2A0F0191ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB0_OR                                = 0x2A0F0192ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB0                                   = 0x2B0F0190ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB0_CLEAR                             = 0x2B0F0191ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB0_OR                                = 0x2B0F0192ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB0                                   = 0x2C0F0190ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB0_CLEAR                             = 0x2C0F0191ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB0_OR                                = 0x2C0F0192ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB0                                   = 0x2D0F0190ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB0_CLEAR                             = 0x2D0F0191ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB0_OR                                = 0x2D0F0192ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB0                                   = 0x2E0F0190ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB0_CLEAR                             = 0x2E0F0191ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB0_OR                                = 0x2E0F0192ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB0                                   = 0x2F0F0190ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB0_CLEAR                             = 0x2F0F0191ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB0_OR                                = 0x2F0F0192ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB0                                   = 0x300F0190ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB0_CLEAR                             = 0x300F0191ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB0_OR                                = 0x300F0192ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB0                                   = 0x310F0190ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB0_CLEAR                             = 0x310F0191ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB0_OR                                = 0x310F0192ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB0                                   = 0x320F0190ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB0_CLEAR                             = 0x320F0191ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB0_OR                                = 0x320F0192ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB0                                   = 0x330F0190ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB0_CLEAR                             = 0x330F0191ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB0_OR                                = 0x330F0192ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB0                                   = 0x340F0190ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB0_CLEAR                             = 0x340F0191ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB0_OR                                = 0x340F0192ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB0                                   = 0x350F0190ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB0_CLEAR                             = 0x350F0191ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB0_OR                                = 0x350F0192ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB0                                   = 0x360F0190ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB0_CLEAR                             = 0x360F0191ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB0_OR                                = 0x360F0192ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB0                                   = 0x370F0190ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB0_CLEAR                             = 0x370F0191ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB0_OR                                = 0x370F0192ull;


static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB1                                   = 0x200F0194ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB1_CLEAR                             = 0x200F0195ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB1_OR                                = 0x200F0196ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB1                                   = 0x210F0194ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB1_CLEAR                             = 0x210F0195ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB1_OR                                = 0x210F0196ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB1                                   = 0x220F0194ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB1_CLEAR                             = 0x220F0195ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB1_OR                                = 0x220F0196ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB1                                   = 0x230F0194ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB1_CLEAR                             = 0x230F0195ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB1_OR                                = 0x230F0196ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB1                                   = 0x240F0194ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB1_CLEAR                             = 0x240F0195ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB1_OR                                = 0x240F0196ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB1                                   = 0x250F0194ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB1_CLEAR                             = 0x250F0195ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB1_OR                                = 0x250F0196ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB1                                   = 0x260F0194ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB1_CLEAR                             = 0x260F0195ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB1_OR                                = 0x260F0196ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB1                                   = 0x270F0194ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB1_CLEAR                             = 0x270F0195ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB1_OR                                = 0x270F0196ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB1                                   = 0x280F0194ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB1_CLEAR                             = 0x280F0195ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB1_OR                                = 0x280F0196ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB1                                   = 0x290F0194ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB1_CLEAR                             = 0x290F0195ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB1_OR                                = 0x290F0196ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB1                                   = 0x2A0F0194ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB1_CLEAR                             = 0x2A0F0195ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB1_OR                                = 0x2A0F0196ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB1                                   = 0x2B0F0194ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB1_CLEAR                             = 0x2B0F0195ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB1_OR                                = 0x2B0F0196ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB1                                   = 0x2C0F0194ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB1_CLEAR                             = 0x2C0F0195ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB1_OR                                = 0x2C0F0196ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB1                                   = 0x2D0F0194ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB1_CLEAR                             = 0x2D0F0195ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB1_OR                                = 0x2D0F0196ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB1                                   = 0x2E0F0194ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB1_CLEAR                             = 0x2E0F0195ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB1_OR                                = 0x2E0F0196ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB1                                   = 0x2F0F0194ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB1_CLEAR                             = 0x2F0F0195ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB1_OR                                = 0x2F0F0196ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB1                                   = 0x300F0194ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB1_CLEAR                             = 0x300F0195ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB1_OR                                = 0x300F0196ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB1                                   = 0x310F0194ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB1_CLEAR                             = 0x310F0195ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB1_OR                                = 0x310F0196ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB1                                   = 0x320F0194ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB1_CLEAR                             = 0x320F0195ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB1_OR                                = 0x320F0196ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB1                                   = 0x330F0194ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB1_CLEAR                             = 0x330F0195ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB1_OR                                = 0x330F0196ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB1                                   = 0x340F0194ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB1_CLEAR                             = 0x340F0195ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB1_OR                                = 0x340F0196ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB1                                   = 0x350F0194ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB1_CLEAR                             = 0x350F0195ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB1_OR                                = 0x350F0196ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB1                                   = 0x360F0194ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB1_CLEAR                             = 0x360F0195ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB1_OR                                = 0x360F0196ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB1                                   = 0x370F0194ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB1_CLEAR                             = 0x370F0195ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB1_OR                                = 0x370F0196ull;


static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB2                                   = 0x200F0198ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB2_CLEAR                             = 0x200F0199ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB2_OR                                = 0x200F019Aull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB2                                   = 0x210F0198ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB2_CLEAR                             = 0x210F0199ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB2_OR                                = 0x210F019Aull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB2                                   = 0x220F0198ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB2_CLEAR                             = 0x220F0199ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB2_OR                                = 0x220F019Aull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB2                                   = 0x230F0198ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB2_CLEAR                             = 0x230F0199ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB2_OR                                = 0x230F019Aull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB2                                   = 0x240F0198ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB2_CLEAR                             = 0x240F0199ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB2_OR                                = 0x240F019Aull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB2                                   = 0x250F0198ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB2_CLEAR                             = 0x250F0199ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB2_OR                                = 0x250F019Aull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB2                                   = 0x260F0198ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB2_CLEAR                             = 0x260F0199ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB2_OR                                = 0x260F019Aull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB2                                   = 0x270F0198ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB2_CLEAR                             = 0x270F0199ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB2_OR                                = 0x270F019Aull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB2                                   = 0x280F0198ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB2_CLEAR                             = 0x280F0199ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB2_OR                                = 0x280F019Aull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB2                                   = 0x290F0198ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB2_CLEAR                             = 0x290F0199ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB2_OR                                = 0x290F019Aull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB2                                   = 0x2A0F0198ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB2_CLEAR                             = 0x2A0F0199ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB2_OR                                = 0x2A0F019Aull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB2                                   = 0x2B0F0198ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB2_CLEAR                             = 0x2B0F0199ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB2_OR                                = 0x2B0F019Aull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB2                                   = 0x2C0F0198ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB2_CLEAR                             = 0x2C0F0199ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB2_OR                                = 0x2C0F019Aull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB2                                   = 0x2D0F0198ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB2_CLEAR                             = 0x2D0F0199ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB2_OR                                = 0x2D0F019Aull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB2                                   = 0x2E0F0198ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB2_CLEAR                             = 0x2E0F0199ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB2_OR                                = 0x2E0F019Aull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB2                                   = 0x2F0F0198ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB2_CLEAR                             = 0x2F0F0199ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB2_OR                                = 0x2F0F019Aull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB2                                   = 0x300F0198ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB2_CLEAR                             = 0x300F0199ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB2_OR                                = 0x300F019Aull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB2                                   = 0x310F0198ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB2_CLEAR                             = 0x310F0199ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB2_OR                                = 0x310F019Aull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB2                                   = 0x320F0198ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB2_CLEAR                             = 0x320F0199ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB2_OR                                = 0x320F019Aull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB2                                   = 0x330F0198ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB2_CLEAR                             = 0x330F0199ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB2_OR                                = 0x330F019Aull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB2                                   = 0x340F0198ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB2_CLEAR                             = 0x340F0199ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB2_OR                                = 0x340F019Aull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB2                                   = 0x350F0198ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB2_CLEAR                             = 0x350F0199ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB2_OR                                = 0x350F019Aull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB2                                   = 0x360F0198ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB2_CLEAR                             = 0x360F0199ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB2_OR                                = 0x360F019Aull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB2                                   = 0x370F0198ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB2_CLEAR                             = 0x370F0199ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB2_OR                                = 0x370F019Aull;


static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB3                                   = 0x200F019Cull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB3_CLEAR                             = 0x200F019Dull;

static const uint64_t P9N2_PERV_EC00_CPPM_CMEDB3_OR                                = 0x200F019Eull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB3                                   = 0x210F019Cull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB3_CLEAR                             = 0x210F019Dull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEDB3_OR                                = 0x210F019Eull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB3                                   = 0x220F019Cull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB3_CLEAR                             = 0x220F019Dull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEDB3_OR                                = 0x220F019Eull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB3                                   = 0x230F019Cull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB3_CLEAR                             = 0x230F019Dull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEDB3_OR                                = 0x230F019Eull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB3                                   = 0x240F019Cull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB3_CLEAR                             = 0x240F019Dull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEDB3_OR                                = 0x240F019Eull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB3                                   = 0x250F019Cull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB3_CLEAR                             = 0x250F019Dull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEDB3_OR                                = 0x250F019Eull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB3                                   = 0x260F019Cull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB3_CLEAR                             = 0x260F019Dull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEDB3_OR                                = 0x260F019Eull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB3                                   = 0x270F019Cull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB3_CLEAR                             = 0x270F019Dull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEDB3_OR                                = 0x270F019Eull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB3                                   = 0x280F019Cull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB3_CLEAR                             = 0x280F019Dull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEDB3_OR                                = 0x280F019Eull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB3                                   = 0x290F019Cull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB3_CLEAR                             = 0x290F019Dull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEDB3_OR                                = 0x290F019Eull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB3                                   = 0x2A0F019Cull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB3_CLEAR                             = 0x2A0F019Dull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEDB3_OR                                = 0x2A0F019Eull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB3                                   = 0x2B0F019Cull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB3_CLEAR                             = 0x2B0F019Dull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEDB3_OR                                = 0x2B0F019Eull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB3                                   = 0x2C0F019Cull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB3_CLEAR                             = 0x2C0F019Dull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEDB3_OR                                = 0x2C0F019Eull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB3                                   = 0x2D0F019Cull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB3_CLEAR                             = 0x2D0F019Dull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEDB3_OR                                = 0x2D0F019Eull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB3                                   = 0x2E0F019Cull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB3_CLEAR                             = 0x2E0F019Dull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEDB3_OR                                = 0x2E0F019Eull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB3                                   = 0x2F0F019Cull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB3_CLEAR                             = 0x2F0F019Dull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEDB3_OR                                = 0x2F0F019Eull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB3                                   = 0x300F019Cull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB3_CLEAR                             = 0x300F019Dull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEDB3_OR                                = 0x300F019Eull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB3                                   = 0x310F019Cull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB3_CLEAR                             = 0x310F019Dull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEDB3_OR                                = 0x310F019Eull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB3                                   = 0x320F019Cull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB3_CLEAR                             = 0x320F019Dull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEDB3_OR                                = 0x320F019Eull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB3                                   = 0x330F019Cull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB3_CLEAR                             = 0x330F019Dull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEDB3_OR                                = 0x330F019Eull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB3                                   = 0x340F019Cull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB3_CLEAR                             = 0x340F019Dull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEDB3_OR                                = 0x340F019Eull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB3                                   = 0x350F019Cull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB3_CLEAR                             = 0x350F019Dull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEDB3_OR                                = 0x350F019Eull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB3                                   = 0x360F019Cull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB3_CLEAR                             = 0x360F019Dull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEDB3_OR                                = 0x360F019Eull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB3                                   = 0x370F019Cull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB3_CLEAR                             = 0x370F019Dull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEDB3_OR                                = 0x370F019Eull;


static const uint64_t P9N2_PERV_EC00_CPPM_CMEMSG                                   = 0x200F01ABull;

static const uint64_t P9N2_PERV_EC01_CPPM_CMEMSG                                   = 0x210F01ABull;

static const uint64_t P9N2_PERV_EC02_CPPM_CMEMSG                                   = 0x220F01ABull;

static const uint64_t P9N2_PERV_EC03_CPPM_CMEMSG                                   = 0x230F01ABull;

static const uint64_t P9N2_PERV_EC04_CPPM_CMEMSG                                   = 0x240F01ABull;

static const uint64_t P9N2_PERV_EC05_CPPM_CMEMSG                                   = 0x250F01ABull;

static const uint64_t P9N2_PERV_EC06_CPPM_CMEMSG                                   = 0x260F01ABull;

static const uint64_t P9N2_PERV_EC07_CPPM_CMEMSG                                   = 0x270F01ABull;

static const uint64_t P9N2_PERV_EC08_CPPM_CMEMSG                                   = 0x280F01ABull;

static const uint64_t P9N2_PERV_EC09_CPPM_CMEMSG                                   = 0x290F01ABull;

static const uint64_t P9N2_PERV_EC10_CPPM_CMEMSG                                   = 0x2A0F01ABull;

static const uint64_t P9N2_PERV_EC11_CPPM_CMEMSG                                   = 0x2B0F01ABull;

static const uint64_t P9N2_PERV_EC12_CPPM_CMEMSG                                   = 0x2C0F01ABull;

static const uint64_t P9N2_PERV_EC13_CPPM_CMEMSG                                   = 0x2D0F01ABull;

static const uint64_t P9N2_PERV_EC14_CPPM_CMEMSG                                   = 0x2E0F01ABull;

static const uint64_t P9N2_PERV_EC15_CPPM_CMEMSG                                   = 0x2F0F01ABull;

static const uint64_t P9N2_PERV_EC16_CPPM_CMEMSG                                   = 0x300F01ABull;

static const uint64_t P9N2_PERV_EC17_CPPM_CMEMSG                                   = 0x310F01ABull;

static const uint64_t P9N2_PERV_EC18_CPPM_CMEMSG                                   = 0x320F01ABull;

static const uint64_t P9N2_PERV_EC19_CPPM_CMEMSG                                   = 0x330F01ABull;

static const uint64_t P9N2_PERV_EC20_CPPM_CMEMSG                                   = 0x340F01ABull;

static const uint64_t P9N2_PERV_EC21_CPPM_CMEMSG                                   = 0x350F01ABull;

static const uint64_t P9N2_PERV_EC22_CPPM_CMEMSG                                   = 0x360F01ABull;

static const uint64_t P9N2_PERV_EC23_CPPM_CMEMSG                                   = 0x370F01ABull;


static const uint64_t P9N2_PERV_EC00_CPPM_CPMMR_SCOM                               = 0x200F0106ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CPMMR_SCOM1                              = 0x200F0107ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CPMMR_SCOM2                              = 0x200F0108ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CPMMR_SCOM                               = 0x210F0106ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CPMMR_SCOM1                              = 0x210F0107ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CPMMR_SCOM2                              = 0x210F0108ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CPMMR_SCOM                               = 0x220F0106ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CPMMR_SCOM1                              = 0x220F0107ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CPMMR_SCOM2                              = 0x220F0108ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CPMMR_SCOM                               = 0x230F0106ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CPMMR_SCOM1                              = 0x230F0107ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CPMMR_SCOM2                              = 0x230F0108ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CPMMR_SCOM                               = 0x240F0106ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CPMMR_SCOM1                              = 0x240F0107ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CPMMR_SCOM2                              = 0x240F0108ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CPMMR_SCOM                               = 0x250F0106ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CPMMR_SCOM1                              = 0x250F0107ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CPMMR_SCOM2                              = 0x250F0108ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CPMMR_SCOM                               = 0x260F0106ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CPMMR_SCOM1                              = 0x260F0107ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CPMMR_SCOM2                              = 0x260F0108ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CPMMR_SCOM                               = 0x270F0106ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CPMMR_SCOM1                              = 0x270F0107ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CPMMR_SCOM2                              = 0x270F0108ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CPMMR_SCOM                               = 0x280F0106ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CPMMR_SCOM1                              = 0x280F0107ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CPMMR_SCOM2                              = 0x280F0108ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CPMMR_SCOM                               = 0x290F0106ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CPMMR_SCOM1                              = 0x290F0107ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CPMMR_SCOM2                              = 0x290F0108ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CPMMR_SCOM                               = 0x2A0F0106ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CPMMR_SCOM1                              = 0x2A0F0107ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CPMMR_SCOM2                              = 0x2A0F0108ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CPMMR_SCOM                               = 0x2B0F0106ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CPMMR_SCOM1                              = 0x2B0F0107ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CPMMR_SCOM2                              = 0x2B0F0108ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CPMMR_SCOM                               = 0x2C0F0106ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CPMMR_SCOM1                              = 0x2C0F0107ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CPMMR_SCOM2                              = 0x2C0F0108ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CPMMR_SCOM                               = 0x2D0F0106ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CPMMR_SCOM1                              = 0x2D0F0107ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CPMMR_SCOM2                              = 0x2D0F0108ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CPMMR_SCOM                               = 0x2E0F0106ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CPMMR_SCOM1                              = 0x2E0F0107ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CPMMR_SCOM2                              = 0x2E0F0108ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CPMMR_SCOM                               = 0x2F0F0106ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CPMMR_SCOM1                              = 0x2F0F0107ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CPMMR_SCOM2                              = 0x2F0F0108ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CPMMR_SCOM                               = 0x300F0106ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CPMMR_SCOM1                              = 0x300F0107ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CPMMR_SCOM2                              = 0x300F0108ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CPMMR_SCOM                               = 0x310F0106ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CPMMR_SCOM1                              = 0x310F0107ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CPMMR_SCOM2                              = 0x310F0108ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CPMMR_SCOM                               = 0x320F0106ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CPMMR_SCOM1                              = 0x320F0107ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CPMMR_SCOM2                              = 0x320F0108ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CPMMR_SCOM                               = 0x330F0106ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CPMMR_SCOM1                              = 0x330F0107ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CPMMR_SCOM2                              = 0x330F0108ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CPMMR_SCOM                               = 0x340F0106ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CPMMR_SCOM1                              = 0x340F0107ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CPMMR_SCOM2                              = 0x340F0108ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CPMMR_SCOM                               = 0x350F0106ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CPMMR_SCOM1                              = 0x350F0107ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CPMMR_SCOM2                              = 0x350F0108ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CPMMR_SCOM                               = 0x360F0106ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CPMMR_SCOM1                              = 0x360F0107ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CPMMR_SCOM2                              = 0x360F0108ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CPMMR_SCOM                               = 0x370F0106ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CPMMR_SCOM1                              = 0x370F0107ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CPMMR_SCOM2                              = 0x370F0108ull;


static const uint64_t P9N2_PERV_EC00_CPPM_CSAR                                     = 0x200F0138ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CSAR_CLEAR                               = 0x200F0139ull;

static const uint64_t P9N2_PERV_EC00_CPPM_CSAR_OR                                  = 0x200F013Aull;

static const uint64_t P9N2_PERV_EC01_CPPM_CSAR                                     = 0x210F0138ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CSAR_CLEAR                               = 0x210F0139ull;

static const uint64_t P9N2_PERV_EC01_CPPM_CSAR_OR                                  = 0x210F013Aull;

static const uint64_t P9N2_PERV_EC02_CPPM_CSAR                                     = 0x220F0138ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CSAR_CLEAR                               = 0x220F0139ull;

static const uint64_t P9N2_PERV_EC02_CPPM_CSAR_OR                                  = 0x220F013Aull;

static const uint64_t P9N2_PERV_EC03_CPPM_CSAR                                     = 0x230F0138ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CSAR_CLEAR                               = 0x230F0139ull;

static const uint64_t P9N2_PERV_EC03_CPPM_CSAR_OR                                  = 0x230F013Aull;

static const uint64_t P9N2_PERV_EC04_CPPM_CSAR                                     = 0x240F0138ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CSAR_CLEAR                               = 0x240F0139ull;

static const uint64_t P9N2_PERV_EC04_CPPM_CSAR_OR                                  = 0x240F013Aull;

static const uint64_t P9N2_PERV_EC05_CPPM_CSAR                                     = 0x250F0138ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CSAR_CLEAR                               = 0x250F0139ull;

static const uint64_t P9N2_PERV_EC05_CPPM_CSAR_OR                                  = 0x250F013Aull;

static const uint64_t P9N2_PERV_EC06_CPPM_CSAR                                     = 0x260F0138ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CSAR_CLEAR                               = 0x260F0139ull;

static const uint64_t P9N2_PERV_EC06_CPPM_CSAR_OR                                  = 0x260F013Aull;

static const uint64_t P9N2_PERV_EC07_CPPM_CSAR                                     = 0x270F0138ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CSAR_CLEAR                               = 0x270F0139ull;

static const uint64_t P9N2_PERV_EC07_CPPM_CSAR_OR                                  = 0x270F013Aull;

static const uint64_t P9N2_PERV_EC08_CPPM_CSAR                                     = 0x280F0138ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CSAR_CLEAR                               = 0x280F0139ull;

static const uint64_t P9N2_PERV_EC08_CPPM_CSAR_OR                                  = 0x280F013Aull;

static const uint64_t P9N2_PERV_EC09_CPPM_CSAR                                     = 0x290F0138ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CSAR_CLEAR                               = 0x290F0139ull;

static const uint64_t P9N2_PERV_EC09_CPPM_CSAR_OR                                  = 0x290F013Aull;

static const uint64_t P9N2_PERV_EC10_CPPM_CSAR                                     = 0x2A0F0138ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CSAR_CLEAR                               = 0x2A0F0139ull;

static const uint64_t P9N2_PERV_EC10_CPPM_CSAR_OR                                  = 0x2A0F013Aull;

static const uint64_t P9N2_PERV_EC11_CPPM_CSAR                                     = 0x2B0F0138ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CSAR_CLEAR                               = 0x2B0F0139ull;

static const uint64_t P9N2_PERV_EC11_CPPM_CSAR_OR                                  = 0x2B0F013Aull;

static const uint64_t P9N2_PERV_EC12_CPPM_CSAR                                     = 0x2C0F0138ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CSAR_CLEAR                               = 0x2C0F0139ull;

static const uint64_t P9N2_PERV_EC12_CPPM_CSAR_OR                                  = 0x2C0F013Aull;

static const uint64_t P9N2_PERV_EC13_CPPM_CSAR                                     = 0x2D0F0138ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CSAR_CLEAR                               = 0x2D0F0139ull;

static const uint64_t P9N2_PERV_EC13_CPPM_CSAR_OR                                  = 0x2D0F013Aull;

static const uint64_t P9N2_PERV_EC14_CPPM_CSAR                                     = 0x2E0F0138ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CSAR_CLEAR                               = 0x2E0F0139ull;

static const uint64_t P9N2_PERV_EC14_CPPM_CSAR_OR                                  = 0x2E0F013Aull;

static const uint64_t P9N2_PERV_EC15_CPPM_CSAR                                     = 0x2F0F0138ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CSAR_CLEAR                               = 0x2F0F0139ull;

static const uint64_t P9N2_PERV_EC15_CPPM_CSAR_OR                                  = 0x2F0F013Aull;

static const uint64_t P9N2_PERV_EC16_CPPM_CSAR                                     = 0x300F0138ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CSAR_CLEAR                               = 0x300F0139ull;

static const uint64_t P9N2_PERV_EC16_CPPM_CSAR_OR                                  = 0x300F013Aull;

static const uint64_t P9N2_PERV_EC17_CPPM_CSAR                                     = 0x310F0138ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CSAR_CLEAR                               = 0x310F0139ull;

static const uint64_t P9N2_PERV_EC17_CPPM_CSAR_OR                                  = 0x310F013Aull;

static const uint64_t P9N2_PERV_EC18_CPPM_CSAR                                     = 0x320F0138ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CSAR_CLEAR                               = 0x320F0139ull;

static const uint64_t P9N2_PERV_EC18_CPPM_CSAR_OR                                  = 0x320F013Aull;

static const uint64_t P9N2_PERV_EC19_CPPM_CSAR                                     = 0x330F0138ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CSAR_CLEAR                               = 0x330F0139ull;

static const uint64_t P9N2_PERV_EC19_CPPM_CSAR_OR                                  = 0x330F013Aull;

static const uint64_t P9N2_PERV_EC20_CPPM_CSAR                                     = 0x340F0138ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CSAR_CLEAR                               = 0x340F0139ull;

static const uint64_t P9N2_PERV_EC20_CPPM_CSAR_OR                                  = 0x340F013Aull;

static const uint64_t P9N2_PERV_EC21_CPPM_CSAR                                     = 0x350F0138ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CSAR_CLEAR                               = 0x350F0139ull;

static const uint64_t P9N2_PERV_EC21_CPPM_CSAR_OR                                  = 0x350F013Aull;

static const uint64_t P9N2_PERV_EC22_CPPM_CSAR                                     = 0x360F0138ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CSAR_CLEAR                               = 0x360F0139ull;

static const uint64_t P9N2_PERV_EC22_CPPM_CSAR_OR                                  = 0x360F013Aull;

static const uint64_t P9N2_PERV_EC23_CPPM_CSAR                                     = 0x370F0138ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CSAR_CLEAR                               = 0x370F0139ull;

static const uint64_t P9N2_PERV_EC23_CPPM_CSAR_OR                                  = 0x370F013Aull;


static const uint64_t P9N2_PERV_EC00_CPPM_ERR                                      = 0x200F0121ull;

static const uint64_t P9N2_PERV_EC01_CPPM_ERR                                      = 0x210F0121ull;

static const uint64_t P9N2_PERV_EC02_CPPM_ERR                                      = 0x220F0121ull;

static const uint64_t P9N2_PERV_EC03_CPPM_ERR                                      = 0x230F0121ull;

static const uint64_t P9N2_PERV_EC04_CPPM_ERR                                      = 0x240F0121ull;

static const uint64_t P9N2_PERV_EC05_CPPM_ERR                                      = 0x250F0121ull;

static const uint64_t P9N2_PERV_EC06_CPPM_ERR                                      = 0x260F0121ull;

static const uint64_t P9N2_PERV_EC07_CPPM_ERR                                      = 0x270F0121ull;

static const uint64_t P9N2_PERV_EC08_CPPM_ERR                                      = 0x280F0121ull;

static const uint64_t P9N2_PERV_EC09_CPPM_ERR                                      = 0x290F0121ull;

static const uint64_t P9N2_PERV_EC10_CPPM_ERR                                      = 0x2A0F0121ull;

static const uint64_t P9N2_PERV_EC11_CPPM_ERR                                      = 0x2B0F0121ull;

static const uint64_t P9N2_PERV_EC12_CPPM_ERR                                      = 0x2C0F0121ull;

static const uint64_t P9N2_PERV_EC13_CPPM_ERR                                      = 0x2D0F0121ull;

static const uint64_t P9N2_PERV_EC14_CPPM_ERR                                      = 0x2E0F0121ull;

static const uint64_t P9N2_PERV_EC15_CPPM_ERR                                      = 0x2F0F0121ull;

static const uint64_t P9N2_PERV_EC16_CPPM_ERR                                      = 0x300F0121ull;

static const uint64_t P9N2_PERV_EC17_CPPM_ERR                                      = 0x310F0121ull;

static const uint64_t P9N2_PERV_EC18_CPPM_ERR                                      = 0x320F0121ull;

static const uint64_t P9N2_PERV_EC19_CPPM_ERR                                      = 0x330F0121ull;

static const uint64_t P9N2_PERV_EC20_CPPM_ERR                                      = 0x340F0121ull;

static const uint64_t P9N2_PERV_EC21_CPPM_ERR                                      = 0x350F0121ull;

static const uint64_t P9N2_PERV_EC22_CPPM_ERR                                      = 0x360F0121ull;

static const uint64_t P9N2_PERV_EC23_CPPM_ERR                                      = 0x370F0121ull;


static const uint64_t P9N2_PERV_EC00_CPPM_ERRMSK                                   = 0x200F0122ull;

static const uint64_t P9N2_PERV_EC01_CPPM_ERRMSK                                   = 0x210F0122ull;

static const uint64_t P9N2_PERV_EC02_CPPM_ERRMSK                                   = 0x220F0122ull;

static const uint64_t P9N2_PERV_EC03_CPPM_ERRMSK                                   = 0x230F0122ull;

static const uint64_t P9N2_PERV_EC04_CPPM_ERRMSK                                   = 0x240F0122ull;

static const uint64_t P9N2_PERV_EC05_CPPM_ERRMSK                                   = 0x250F0122ull;

static const uint64_t P9N2_PERV_EC06_CPPM_ERRMSK                                   = 0x260F0122ull;

static const uint64_t P9N2_PERV_EC07_CPPM_ERRMSK                                   = 0x270F0122ull;

static const uint64_t P9N2_PERV_EC08_CPPM_ERRMSK                                   = 0x280F0122ull;

static const uint64_t P9N2_PERV_EC09_CPPM_ERRMSK                                   = 0x290F0122ull;

static const uint64_t P9N2_PERV_EC10_CPPM_ERRMSK                                   = 0x2A0F0122ull;

static const uint64_t P9N2_PERV_EC11_CPPM_ERRMSK                                   = 0x2B0F0122ull;

static const uint64_t P9N2_PERV_EC12_CPPM_ERRMSK                                   = 0x2C0F0122ull;

static const uint64_t P9N2_PERV_EC13_CPPM_ERRMSK                                   = 0x2D0F0122ull;

static const uint64_t P9N2_PERV_EC14_CPPM_ERRMSK                                   = 0x2E0F0122ull;

static const uint64_t P9N2_PERV_EC15_CPPM_ERRMSK                                   = 0x2F0F0122ull;

static const uint64_t P9N2_PERV_EC16_CPPM_ERRMSK                                   = 0x300F0122ull;

static const uint64_t P9N2_PERV_EC17_CPPM_ERRMSK                                   = 0x310F0122ull;

static const uint64_t P9N2_PERV_EC18_CPPM_ERRMSK                                   = 0x320F0122ull;

static const uint64_t P9N2_PERV_EC19_CPPM_ERRMSK                                   = 0x330F0122ull;

static const uint64_t P9N2_PERV_EC20_CPPM_ERRMSK                                   = 0x340F0122ull;

static const uint64_t P9N2_PERV_EC21_CPPM_ERRMSK                                   = 0x350F0122ull;

static const uint64_t P9N2_PERV_EC22_CPPM_ERRMSK                                   = 0x360F0122ull;

static const uint64_t P9N2_PERV_EC23_CPPM_ERRMSK                                   = 0x370F0122ull;


static const uint64_t P9N2_PERV_EC00_CPPM_IPPMCMD                                  = 0x200F01C0ull;

static const uint64_t P9N2_PERV_EC01_CPPM_IPPMCMD                                  = 0x210F01C0ull;

static const uint64_t P9N2_PERV_EC02_CPPM_IPPMCMD                                  = 0x220F01C0ull;

static const uint64_t P9N2_PERV_EC03_CPPM_IPPMCMD                                  = 0x230F01C0ull;

static const uint64_t P9N2_PERV_EC04_CPPM_IPPMCMD                                  = 0x240F01C0ull;

static const uint64_t P9N2_PERV_EC05_CPPM_IPPMCMD                                  = 0x250F01C0ull;

static const uint64_t P9N2_PERV_EC06_CPPM_IPPMCMD                                  = 0x260F01C0ull;

static const uint64_t P9N2_PERV_EC07_CPPM_IPPMCMD                                  = 0x270F01C0ull;

static const uint64_t P9N2_PERV_EC08_CPPM_IPPMCMD                                  = 0x280F01C0ull;

static const uint64_t P9N2_PERV_EC09_CPPM_IPPMCMD                                  = 0x290F01C0ull;

static const uint64_t P9N2_PERV_EC10_CPPM_IPPMCMD                                  = 0x2A0F01C0ull;

static const uint64_t P9N2_PERV_EC11_CPPM_IPPMCMD                                  = 0x2B0F01C0ull;

static const uint64_t P9N2_PERV_EC12_CPPM_IPPMCMD                                  = 0x2C0F01C0ull;

static const uint64_t P9N2_PERV_EC13_CPPM_IPPMCMD                                  = 0x2D0F01C0ull;

static const uint64_t P9N2_PERV_EC14_CPPM_IPPMCMD                                  = 0x2E0F01C0ull;

static const uint64_t P9N2_PERV_EC15_CPPM_IPPMCMD                                  = 0x2F0F01C0ull;

static const uint64_t P9N2_PERV_EC16_CPPM_IPPMCMD                                  = 0x300F01C0ull;

static const uint64_t P9N2_PERV_EC17_CPPM_IPPMCMD                                  = 0x310F01C0ull;

static const uint64_t P9N2_PERV_EC18_CPPM_IPPMCMD                                  = 0x320F01C0ull;

static const uint64_t P9N2_PERV_EC19_CPPM_IPPMCMD                                  = 0x330F01C0ull;

static const uint64_t P9N2_PERV_EC20_CPPM_IPPMCMD                                  = 0x340F01C0ull;

static const uint64_t P9N2_PERV_EC21_CPPM_IPPMCMD                                  = 0x350F01C0ull;

static const uint64_t P9N2_PERV_EC22_CPPM_IPPMCMD                                  = 0x360F01C0ull;

static const uint64_t P9N2_PERV_EC23_CPPM_IPPMCMD                                  = 0x370F01C0ull;


static const uint64_t P9N2_PERV_EC00_CPPM_IPPMRDATA                                = 0x200F01C3ull;

static const uint64_t P9N2_PERV_EC01_CPPM_IPPMRDATA                                = 0x210F01C3ull;

static const uint64_t P9N2_PERV_EC02_CPPM_IPPMRDATA                                = 0x220F01C3ull;

static const uint64_t P9N2_PERV_EC03_CPPM_IPPMRDATA                                = 0x230F01C3ull;

static const uint64_t P9N2_PERV_EC04_CPPM_IPPMRDATA                                = 0x240F01C3ull;

static const uint64_t P9N2_PERV_EC05_CPPM_IPPMRDATA                                = 0x250F01C3ull;

static const uint64_t P9N2_PERV_EC06_CPPM_IPPMRDATA                                = 0x260F01C3ull;

static const uint64_t P9N2_PERV_EC07_CPPM_IPPMRDATA                                = 0x270F01C3ull;

static const uint64_t P9N2_PERV_EC08_CPPM_IPPMRDATA                                = 0x280F01C3ull;

static const uint64_t P9N2_PERV_EC09_CPPM_IPPMRDATA                                = 0x290F01C3ull;

static const uint64_t P9N2_PERV_EC10_CPPM_IPPMRDATA                                = 0x2A0F01C3ull;

static const uint64_t P9N2_PERV_EC11_CPPM_IPPMRDATA                                = 0x2B0F01C3ull;

static const uint64_t P9N2_PERV_EC12_CPPM_IPPMRDATA                                = 0x2C0F01C3ull;

static const uint64_t P9N2_PERV_EC13_CPPM_IPPMRDATA                                = 0x2D0F01C3ull;

static const uint64_t P9N2_PERV_EC14_CPPM_IPPMRDATA                                = 0x2E0F01C3ull;

static const uint64_t P9N2_PERV_EC15_CPPM_IPPMRDATA                                = 0x2F0F01C3ull;

static const uint64_t P9N2_PERV_EC16_CPPM_IPPMRDATA                                = 0x300F01C3ull;

static const uint64_t P9N2_PERV_EC17_CPPM_IPPMRDATA                                = 0x310F01C3ull;

static const uint64_t P9N2_PERV_EC18_CPPM_IPPMRDATA                                = 0x320F01C3ull;

static const uint64_t P9N2_PERV_EC19_CPPM_IPPMRDATA                                = 0x330F01C3ull;

static const uint64_t P9N2_PERV_EC20_CPPM_IPPMRDATA                                = 0x340F01C3ull;

static const uint64_t P9N2_PERV_EC21_CPPM_IPPMRDATA                                = 0x350F01C3ull;

static const uint64_t P9N2_PERV_EC22_CPPM_IPPMRDATA                                = 0x360F01C3ull;

static const uint64_t P9N2_PERV_EC23_CPPM_IPPMRDATA                                = 0x370F01C3ull;


static const uint64_t P9N2_PERV_EC00_CPPM_IPPMSTAT                                 = 0x200F01C1ull;

static const uint64_t P9N2_PERV_EC01_CPPM_IPPMSTAT                                 = 0x210F01C1ull;

static const uint64_t P9N2_PERV_EC02_CPPM_IPPMSTAT                                 = 0x220F01C1ull;

static const uint64_t P9N2_PERV_EC03_CPPM_IPPMSTAT                                 = 0x230F01C1ull;

static const uint64_t P9N2_PERV_EC04_CPPM_IPPMSTAT                                 = 0x240F01C1ull;

static const uint64_t P9N2_PERV_EC05_CPPM_IPPMSTAT                                 = 0x250F01C1ull;

static const uint64_t P9N2_PERV_EC06_CPPM_IPPMSTAT                                 = 0x260F01C1ull;

static const uint64_t P9N2_PERV_EC07_CPPM_IPPMSTAT                                 = 0x270F01C1ull;

static const uint64_t P9N2_PERV_EC08_CPPM_IPPMSTAT                                 = 0x280F01C1ull;

static const uint64_t P9N2_PERV_EC09_CPPM_IPPMSTAT                                 = 0x290F01C1ull;

static const uint64_t P9N2_PERV_EC10_CPPM_IPPMSTAT                                 = 0x2A0F01C1ull;

static const uint64_t P9N2_PERV_EC11_CPPM_IPPMSTAT                                 = 0x2B0F01C1ull;

static const uint64_t P9N2_PERV_EC12_CPPM_IPPMSTAT                                 = 0x2C0F01C1ull;

static const uint64_t P9N2_PERV_EC13_CPPM_IPPMSTAT                                 = 0x2D0F01C1ull;

static const uint64_t P9N2_PERV_EC14_CPPM_IPPMSTAT                                 = 0x2E0F01C1ull;

static const uint64_t P9N2_PERV_EC15_CPPM_IPPMSTAT                                 = 0x2F0F01C1ull;

static const uint64_t P9N2_PERV_EC16_CPPM_IPPMSTAT                                 = 0x300F01C1ull;

static const uint64_t P9N2_PERV_EC17_CPPM_IPPMSTAT                                 = 0x310F01C1ull;

static const uint64_t P9N2_PERV_EC18_CPPM_IPPMSTAT                                 = 0x320F01C1ull;

static const uint64_t P9N2_PERV_EC19_CPPM_IPPMSTAT                                 = 0x330F01C1ull;

static const uint64_t P9N2_PERV_EC20_CPPM_IPPMSTAT                                 = 0x340F01C1ull;

static const uint64_t P9N2_PERV_EC21_CPPM_IPPMSTAT                                 = 0x350F01C1ull;

static const uint64_t P9N2_PERV_EC22_CPPM_IPPMSTAT                                 = 0x360F01C1ull;

static const uint64_t P9N2_PERV_EC23_CPPM_IPPMSTAT                                 = 0x370F01C1ull;


static const uint64_t P9N2_PERV_EC00_CPPM_IPPMWDATA                                = 0x200F01C2ull;

static const uint64_t P9N2_PERV_EC01_CPPM_IPPMWDATA                                = 0x210F01C2ull;

static const uint64_t P9N2_PERV_EC02_CPPM_IPPMWDATA                                = 0x220F01C2ull;

static const uint64_t P9N2_PERV_EC03_CPPM_IPPMWDATA                                = 0x230F01C2ull;

static const uint64_t P9N2_PERV_EC04_CPPM_IPPMWDATA                                = 0x240F01C2ull;

static const uint64_t P9N2_PERV_EC05_CPPM_IPPMWDATA                                = 0x250F01C2ull;

static const uint64_t P9N2_PERV_EC06_CPPM_IPPMWDATA                                = 0x260F01C2ull;

static const uint64_t P9N2_PERV_EC07_CPPM_IPPMWDATA                                = 0x270F01C2ull;

static const uint64_t P9N2_PERV_EC08_CPPM_IPPMWDATA                                = 0x280F01C2ull;

static const uint64_t P9N2_PERV_EC09_CPPM_IPPMWDATA                                = 0x290F01C2ull;

static const uint64_t P9N2_PERV_EC10_CPPM_IPPMWDATA                                = 0x2A0F01C2ull;

static const uint64_t P9N2_PERV_EC11_CPPM_IPPMWDATA                                = 0x2B0F01C2ull;

static const uint64_t P9N2_PERV_EC12_CPPM_IPPMWDATA                                = 0x2C0F01C2ull;

static const uint64_t P9N2_PERV_EC13_CPPM_IPPMWDATA                                = 0x2D0F01C2ull;

static const uint64_t P9N2_PERV_EC14_CPPM_IPPMWDATA                                = 0x2E0F01C2ull;

static const uint64_t P9N2_PERV_EC15_CPPM_IPPMWDATA                                = 0x2F0F01C2ull;

static const uint64_t P9N2_PERV_EC16_CPPM_IPPMWDATA                                = 0x300F01C2ull;

static const uint64_t P9N2_PERV_EC17_CPPM_IPPMWDATA                                = 0x310F01C2ull;

static const uint64_t P9N2_PERV_EC18_CPPM_IPPMWDATA                                = 0x320F01C2ull;

static const uint64_t P9N2_PERV_EC19_CPPM_IPPMWDATA                                = 0x330F01C2ull;

static const uint64_t P9N2_PERV_EC20_CPPM_IPPMWDATA                                = 0x340F01C2ull;

static const uint64_t P9N2_PERV_EC21_CPPM_IPPMWDATA                                = 0x350F01C2ull;

static const uint64_t P9N2_PERV_EC22_CPPM_IPPMWDATA                                = 0x360F01C2ull;

static const uint64_t P9N2_PERV_EC23_CPPM_IPPMWDATA                                = 0x370F01C2ull;


static const uint64_t P9N2_PERV_EC00_CPPM_NC0INDIR_SCOM                            = 0x200F0130ull;

static const uint64_t P9N2_PERV_EC00_CPPM_NC0INDIR_SCOM1                           = 0x200F0131ull;

static const uint64_t P9N2_PERV_EC00_CPPM_NC0INDIR_SCOM2                           = 0x200F0132ull;

static const uint64_t P9N2_PERV_EC01_CPPM_NC0INDIR_SCOM                            = 0x210F0130ull;

static const uint64_t P9N2_PERV_EC01_CPPM_NC0INDIR_SCOM1                           = 0x210F0131ull;

static const uint64_t P9N2_PERV_EC01_CPPM_NC0INDIR_SCOM2                           = 0x210F0132ull;

static const uint64_t P9N2_PERV_EC02_CPPM_NC0INDIR_SCOM                            = 0x220F0130ull;

static const uint64_t P9N2_PERV_EC02_CPPM_NC0INDIR_SCOM1                           = 0x220F0131ull;

static const uint64_t P9N2_PERV_EC02_CPPM_NC0INDIR_SCOM2                           = 0x220F0132ull;

static const uint64_t P9N2_PERV_EC03_CPPM_NC0INDIR_SCOM                            = 0x230F0130ull;

static const uint64_t P9N2_PERV_EC03_CPPM_NC0INDIR_SCOM1                           = 0x230F0131ull;

static const uint64_t P9N2_PERV_EC03_CPPM_NC0INDIR_SCOM2                           = 0x230F0132ull;

static const uint64_t P9N2_PERV_EC04_CPPM_NC0INDIR_SCOM                            = 0x240F0130ull;

static const uint64_t P9N2_PERV_EC04_CPPM_NC0INDIR_SCOM1                           = 0x240F0131ull;

static const uint64_t P9N2_PERV_EC04_CPPM_NC0INDIR_SCOM2                           = 0x240F0132ull;

static const uint64_t P9N2_PERV_EC05_CPPM_NC0INDIR_SCOM                            = 0x250F0130ull;

static const uint64_t P9N2_PERV_EC05_CPPM_NC0INDIR_SCOM1                           = 0x250F0131ull;

static const uint64_t P9N2_PERV_EC05_CPPM_NC0INDIR_SCOM2                           = 0x250F0132ull;

static const uint64_t P9N2_PERV_EC06_CPPM_NC0INDIR_SCOM                            = 0x260F0130ull;

static const uint64_t P9N2_PERV_EC06_CPPM_NC0INDIR_SCOM1                           = 0x260F0131ull;

static const uint64_t P9N2_PERV_EC06_CPPM_NC0INDIR_SCOM2                           = 0x260F0132ull;

static const uint64_t P9N2_PERV_EC07_CPPM_NC0INDIR_SCOM                            = 0x270F0130ull;

static const uint64_t P9N2_PERV_EC07_CPPM_NC0INDIR_SCOM1                           = 0x270F0131ull;

static const uint64_t P9N2_PERV_EC07_CPPM_NC0INDIR_SCOM2                           = 0x270F0132ull;

static const uint64_t P9N2_PERV_EC08_CPPM_NC0INDIR_SCOM                            = 0x280F0130ull;

static const uint64_t P9N2_PERV_EC08_CPPM_NC0INDIR_SCOM1                           = 0x280F0131ull;

static const uint64_t P9N2_PERV_EC08_CPPM_NC0INDIR_SCOM2                           = 0x280F0132ull;

static const uint64_t P9N2_PERV_EC09_CPPM_NC0INDIR_SCOM                            = 0x290F0130ull;

static const uint64_t P9N2_PERV_EC09_CPPM_NC0INDIR_SCOM1                           = 0x290F0131ull;

static const uint64_t P9N2_PERV_EC09_CPPM_NC0INDIR_SCOM2                           = 0x290F0132ull;

static const uint64_t P9N2_PERV_EC10_CPPM_NC0INDIR_SCOM                            = 0x2A0F0130ull;

static const uint64_t P9N2_PERV_EC10_CPPM_NC0INDIR_SCOM1                           = 0x2A0F0131ull;

static const uint64_t P9N2_PERV_EC10_CPPM_NC0INDIR_SCOM2                           = 0x2A0F0132ull;

static const uint64_t P9N2_PERV_EC11_CPPM_NC0INDIR_SCOM                            = 0x2B0F0130ull;

static const uint64_t P9N2_PERV_EC11_CPPM_NC0INDIR_SCOM1                           = 0x2B0F0131ull;

static const uint64_t P9N2_PERV_EC11_CPPM_NC0INDIR_SCOM2                           = 0x2B0F0132ull;

static const uint64_t P9N2_PERV_EC12_CPPM_NC0INDIR_SCOM                            = 0x2C0F0130ull;

static const uint64_t P9N2_PERV_EC12_CPPM_NC0INDIR_SCOM1                           = 0x2C0F0131ull;

static const uint64_t P9N2_PERV_EC12_CPPM_NC0INDIR_SCOM2                           = 0x2C0F0132ull;

static const uint64_t P9N2_PERV_EC13_CPPM_NC0INDIR_SCOM                            = 0x2D0F0130ull;

static const uint64_t P9N2_PERV_EC13_CPPM_NC0INDIR_SCOM1                           = 0x2D0F0131ull;

static const uint64_t P9N2_PERV_EC13_CPPM_NC0INDIR_SCOM2                           = 0x2D0F0132ull;

static const uint64_t P9N2_PERV_EC14_CPPM_NC0INDIR_SCOM                            = 0x2E0F0130ull;

static const uint64_t P9N2_PERV_EC14_CPPM_NC0INDIR_SCOM1                           = 0x2E0F0131ull;

static const uint64_t P9N2_PERV_EC14_CPPM_NC0INDIR_SCOM2                           = 0x2E0F0132ull;

static const uint64_t P9N2_PERV_EC15_CPPM_NC0INDIR_SCOM                            = 0x2F0F0130ull;

static const uint64_t P9N2_PERV_EC15_CPPM_NC0INDIR_SCOM1                           = 0x2F0F0131ull;

static const uint64_t P9N2_PERV_EC15_CPPM_NC0INDIR_SCOM2                           = 0x2F0F0132ull;

static const uint64_t P9N2_PERV_EC16_CPPM_NC0INDIR_SCOM                            = 0x300F0130ull;

static const uint64_t P9N2_PERV_EC16_CPPM_NC0INDIR_SCOM1                           = 0x300F0131ull;

static const uint64_t P9N2_PERV_EC16_CPPM_NC0INDIR_SCOM2                           = 0x300F0132ull;

static const uint64_t P9N2_PERV_EC17_CPPM_NC0INDIR_SCOM                            = 0x310F0130ull;

static const uint64_t P9N2_PERV_EC17_CPPM_NC0INDIR_SCOM1                           = 0x310F0131ull;

static const uint64_t P9N2_PERV_EC17_CPPM_NC0INDIR_SCOM2                           = 0x310F0132ull;

static const uint64_t P9N2_PERV_EC18_CPPM_NC0INDIR_SCOM                            = 0x320F0130ull;

static const uint64_t P9N2_PERV_EC18_CPPM_NC0INDIR_SCOM1                           = 0x320F0131ull;

static const uint64_t P9N2_PERV_EC18_CPPM_NC0INDIR_SCOM2                           = 0x320F0132ull;

static const uint64_t P9N2_PERV_EC19_CPPM_NC0INDIR_SCOM                            = 0x330F0130ull;

static const uint64_t P9N2_PERV_EC19_CPPM_NC0INDIR_SCOM1                           = 0x330F0131ull;

static const uint64_t P9N2_PERV_EC19_CPPM_NC0INDIR_SCOM2                           = 0x330F0132ull;

static const uint64_t P9N2_PERV_EC20_CPPM_NC0INDIR_SCOM                            = 0x340F0130ull;

static const uint64_t P9N2_PERV_EC20_CPPM_NC0INDIR_SCOM1                           = 0x340F0131ull;

static const uint64_t P9N2_PERV_EC20_CPPM_NC0INDIR_SCOM2                           = 0x340F0132ull;

static const uint64_t P9N2_PERV_EC21_CPPM_NC0INDIR_SCOM                            = 0x350F0130ull;

static const uint64_t P9N2_PERV_EC21_CPPM_NC0INDIR_SCOM1                           = 0x350F0131ull;

static const uint64_t P9N2_PERV_EC21_CPPM_NC0INDIR_SCOM2                           = 0x350F0132ull;

static const uint64_t P9N2_PERV_EC22_CPPM_NC0INDIR_SCOM                            = 0x360F0130ull;

static const uint64_t P9N2_PERV_EC22_CPPM_NC0INDIR_SCOM1                           = 0x360F0131ull;

static const uint64_t P9N2_PERV_EC22_CPPM_NC0INDIR_SCOM2                           = 0x360F0132ull;

static const uint64_t P9N2_PERV_EC23_CPPM_NC0INDIR_SCOM                            = 0x370F0130ull;

static const uint64_t P9N2_PERV_EC23_CPPM_NC0INDIR_SCOM1                           = 0x370F0131ull;

static const uint64_t P9N2_PERV_EC23_CPPM_NC0INDIR_SCOM2                           = 0x370F0132ull;


static const uint64_t P9N2_PERV_EC00_CPPM_NC1INDIR_SCOM                            = 0x200F0133ull;

static const uint64_t P9N2_PERV_EC00_CPPM_NC1INDIR_SCOM1                           = 0x200F0134ull;

static const uint64_t P9N2_PERV_EC00_CPPM_NC1INDIR_SCOM2                           = 0x200F0135ull;

static const uint64_t P9N2_PERV_EC01_CPPM_NC1INDIR_SCOM                            = 0x210F0133ull;

static const uint64_t P9N2_PERV_EC01_CPPM_NC1INDIR_SCOM1                           = 0x210F0134ull;

static const uint64_t P9N2_PERV_EC01_CPPM_NC1INDIR_SCOM2                           = 0x210F0135ull;

static const uint64_t P9N2_PERV_EC02_CPPM_NC1INDIR_SCOM                            = 0x220F0133ull;

static const uint64_t P9N2_PERV_EC02_CPPM_NC1INDIR_SCOM1                           = 0x220F0134ull;

static const uint64_t P9N2_PERV_EC02_CPPM_NC1INDIR_SCOM2                           = 0x220F0135ull;

static const uint64_t P9N2_PERV_EC03_CPPM_NC1INDIR_SCOM                            = 0x230F0133ull;

static const uint64_t P9N2_PERV_EC03_CPPM_NC1INDIR_SCOM1                           = 0x230F0134ull;

static const uint64_t P9N2_PERV_EC03_CPPM_NC1INDIR_SCOM2                           = 0x230F0135ull;

static const uint64_t P9N2_PERV_EC04_CPPM_NC1INDIR_SCOM                            = 0x240F0133ull;

static const uint64_t P9N2_PERV_EC04_CPPM_NC1INDIR_SCOM1                           = 0x240F0134ull;

static const uint64_t P9N2_PERV_EC04_CPPM_NC1INDIR_SCOM2                           = 0x240F0135ull;

static const uint64_t P9N2_PERV_EC05_CPPM_NC1INDIR_SCOM                            = 0x250F0133ull;

static const uint64_t P9N2_PERV_EC05_CPPM_NC1INDIR_SCOM1                           = 0x250F0134ull;

static const uint64_t P9N2_PERV_EC05_CPPM_NC1INDIR_SCOM2                           = 0x250F0135ull;

static const uint64_t P9N2_PERV_EC06_CPPM_NC1INDIR_SCOM                            = 0x260F0133ull;

static const uint64_t P9N2_PERV_EC06_CPPM_NC1INDIR_SCOM1                           = 0x260F0134ull;

static const uint64_t P9N2_PERV_EC06_CPPM_NC1INDIR_SCOM2                           = 0x260F0135ull;

static const uint64_t P9N2_PERV_EC07_CPPM_NC1INDIR_SCOM                            = 0x270F0133ull;

static const uint64_t P9N2_PERV_EC07_CPPM_NC1INDIR_SCOM1                           = 0x270F0134ull;

static const uint64_t P9N2_PERV_EC07_CPPM_NC1INDIR_SCOM2                           = 0x270F0135ull;

static const uint64_t P9N2_PERV_EC08_CPPM_NC1INDIR_SCOM                            = 0x280F0133ull;

static const uint64_t P9N2_PERV_EC08_CPPM_NC1INDIR_SCOM1                           = 0x280F0134ull;

static const uint64_t P9N2_PERV_EC08_CPPM_NC1INDIR_SCOM2                           = 0x280F0135ull;

static const uint64_t P9N2_PERV_EC09_CPPM_NC1INDIR_SCOM                            = 0x290F0133ull;

static const uint64_t P9N2_PERV_EC09_CPPM_NC1INDIR_SCOM1                           = 0x290F0134ull;

static const uint64_t P9N2_PERV_EC09_CPPM_NC1INDIR_SCOM2                           = 0x290F0135ull;

static const uint64_t P9N2_PERV_EC10_CPPM_NC1INDIR_SCOM                            = 0x2A0F0133ull;

static const uint64_t P9N2_PERV_EC10_CPPM_NC1INDIR_SCOM1                           = 0x2A0F0134ull;

static const uint64_t P9N2_PERV_EC10_CPPM_NC1INDIR_SCOM2                           = 0x2A0F0135ull;

static const uint64_t P9N2_PERV_EC11_CPPM_NC1INDIR_SCOM                            = 0x2B0F0133ull;

static const uint64_t P9N2_PERV_EC11_CPPM_NC1INDIR_SCOM1                           = 0x2B0F0134ull;

static const uint64_t P9N2_PERV_EC11_CPPM_NC1INDIR_SCOM2                           = 0x2B0F0135ull;

static const uint64_t P9N2_PERV_EC12_CPPM_NC1INDIR_SCOM                            = 0x2C0F0133ull;

static const uint64_t P9N2_PERV_EC12_CPPM_NC1INDIR_SCOM1                           = 0x2C0F0134ull;

static const uint64_t P9N2_PERV_EC12_CPPM_NC1INDIR_SCOM2                           = 0x2C0F0135ull;

static const uint64_t P9N2_PERV_EC13_CPPM_NC1INDIR_SCOM                            = 0x2D0F0133ull;

static const uint64_t P9N2_PERV_EC13_CPPM_NC1INDIR_SCOM1                           = 0x2D0F0134ull;

static const uint64_t P9N2_PERV_EC13_CPPM_NC1INDIR_SCOM2                           = 0x2D0F0135ull;

static const uint64_t P9N2_PERV_EC14_CPPM_NC1INDIR_SCOM                            = 0x2E0F0133ull;

static const uint64_t P9N2_PERV_EC14_CPPM_NC1INDIR_SCOM1                           = 0x2E0F0134ull;

static const uint64_t P9N2_PERV_EC14_CPPM_NC1INDIR_SCOM2                           = 0x2E0F0135ull;

static const uint64_t P9N2_PERV_EC15_CPPM_NC1INDIR_SCOM                            = 0x2F0F0133ull;

static const uint64_t P9N2_PERV_EC15_CPPM_NC1INDIR_SCOM1                           = 0x2F0F0134ull;

static const uint64_t P9N2_PERV_EC15_CPPM_NC1INDIR_SCOM2                           = 0x2F0F0135ull;

static const uint64_t P9N2_PERV_EC16_CPPM_NC1INDIR_SCOM                            = 0x300F0133ull;

static const uint64_t P9N2_PERV_EC16_CPPM_NC1INDIR_SCOM1                           = 0x300F0134ull;

static const uint64_t P9N2_PERV_EC16_CPPM_NC1INDIR_SCOM2                           = 0x300F0135ull;

static const uint64_t P9N2_PERV_EC17_CPPM_NC1INDIR_SCOM                            = 0x310F0133ull;

static const uint64_t P9N2_PERV_EC17_CPPM_NC1INDIR_SCOM1                           = 0x310F0134ull;

static const uint64_t P9N2_PERV_EC17_CPPM_NC1INDIR_SCOM2                           = 0x310F0135ull;

static const uint64_t P9N2_PERV_EC18_CPPM_NC1INDIR_SCOM                            = 0x320F0133ull;

static const uint64_t P9N2_PERV_EC18_CPPM_NC1INDIR_SCOM1                           = 0x320F0134ull;

static const uint64_t P9N2_PERV_EC18_CPPM_NC1INDIR_SCOM2                           = 0x320F0135ull;

static const uint64_t P9N2_PERV_EC19_CPPM_NC1INDIR_SCOM                            = 0x330F0133ull;

static const uint64_t P9N2_PERV_EC19_CPPM_NC1INDIR_SCOM1                           = 0x330F0134ull;

static const uint64_t P9N2_PERV_EC19_CPPM_NC1INDIR_SCOM2                           = 0x330F0135ull;

static const uint64_t P9N2_PERV_EC20_CPPM_NC1INDIR_SCOM                            = 0x340F0133ull;

static const uint64_t P9N2_PERV_EC20_CPPM_NC1INDIR_SCOM1                           = 0x340F0134ull;

static const uint64_t P9N2_PERV_EC20_CPPM_NC1INDIR_SCOM2                           = 0x340F0135ull;

static const uint64_t P9N2_PERV_EC21_CPPM_NC1INDIR_SCOM                            = 0x350F0133ull;

static const uint64_t P9N2_PERV_EC21_CPPM_NC1INDIR_SCOM1                           = 0x350F0134ull;

static const uint64_t P9N2_PERV_EC21_CPPM_NC1INDIR_SCOM2                           = 0x350F0135ull;

static const uint64_t P9N2_PERV_EC22_CPPM_NC1INDIR_SCOM                            = 0x360F0133ull;

static const uint64_t P9N2_PERV_EC22_CPPM_NC1INDIR_SCOM1                           = 0x360F0134ull;

static const uint64_t P9N2_PERV_EC22_CPPM_NC1INDIR_SCOM2                           = 0x360F0135ull;

static const uint64_t P9N2_PERV_EC23_CPPM_NC1INDIR_SCOM                            = 0x370F0133ull;

static const uint64_t P9N2_PERV_EC23_CPPM_NC1INDIR_SCOM1                           = 0x370F0134ull;

static const uint64_t P9N2_PERV_EC23_CPPM_NC1INDIR_SCOM2                           = 0x370F0135ull;


static const uint64_t P9N2_PERV_EC00_CPPM_PECES                                    = 0x200F01AFull;

static const uint64_t P9N2_PERV_EC01_CPPM_PECES                                    = 0x210F01AFull;

static const uint64_t P9N2_PERV_EC02_CPPM_PECES                                    = 0x220F01AFull;

static const uint64_t P9N2_PERV_EC03_CPPM_PECES                                    = 0x230F01AFull;

static const uint64_t P9N2_PERV_EC04_CPPM_PECES                                    = 0x240F01AFull;

static const uint64_t P9N2_PERV_EC05_CPPM_PECES                                    = 0x250F01AFull;

static const uint64_t P9N2_PERV_EC06_CPPM_PECES                                    = 0x260F01AFull;

static const uint64_t P9N2_PERV_EC07_CPPM_PECES                                    = 0x270F01AFull;

static const uint64_t P9N2_PERV_EC08_CPPM_PECES                                    = 0x280F01AFull;

static const uint64_t P9N2_PERV_EC09_CPPM_PECES                                    = 0x290F01AFull;

static const uint64_t P9N2_PERV_EC10_CPPM_PECES                                    = 0x2A0F01AFull;

static const uint64_t P9N2_PERV_EC11_CPPM_PECES                                    = 0x2B0F01AFull;

static const uint64_t P9N2_PERV_EC12_CPPM_PECES                                    = 0x2C0F01AFull;

static const uint64_t P9N2_PERV_EC13_CPPM_PECES                                    = 0x2D0F01AFull;

static const uint64_t P9N2_PERV_EC14_CPPM_PECES                                    = 0x2E0F01AFull;

static const uint64_t P9N2_PERV_EC15_CPPM_PECES                                    = 0x2F0F01AFull;

static const uint64_t P9N2_PERV_EC16_CPPM_PECES                                    = 0x300F01AFull;

static const uint64_t P9N2_PERV_EC17_CPPM_PECES                                    = 0x310F01AFull;

static const uint64_t P9N2_PERV_EC18_CPPM_PECES                                    = 0x320F01AFull;

static const uint64_t P9N2_PERV_EC19_CPPM_PECES                                    = 0x330F01AFull;

static const uint64_t P9N2_PERV_EC20_CPPM_PECES                                    = 0x340F01AFull;

static const uint64_t P9N2_PERV_EC21_CPPM_PECES                                    = 0x350F01AFull;

static const uint64_t P9N2_PERV_EC22_CPPM_PECES                                    = 0x360F01AFull;

static const uint64_t P9N2_PERV_EC23_CPPM_PECES                                    = 0x370F01AFull;


static const uint64_t P9N2_PERV_EC00_CPPM_PERRSUM                                  = 0x200F0120ull;

static const uint64_t P9N2_PERV_EC01_CPPM_PERRSUM                                  = 0x210F0120ull;

static const uint64_t P9N2_PERV_EC02_CPPM_PERRSUM                                  = 0x220F0120ull;

static const uint64_t P9N2_PERV_EC03_CPPM_PERRSUM                                  = 0x230F0120ull;

static const uint64_t P9N2_PERV_EC04_CPPM_PERRSUM                                  = 0x240F0120ull;

static const uint64_t P9N2_PERV_EC05_CPPM_PERRSUM                                  = 0x250F0120ull;

static const uint64_t P9N2_PERV_EC06_CPPM_PERRSUM                                  = 0x260F0120ull;

static const uint64_t P9N2_PERV_EC07_CPPM_PERRSUM                                  = 0x270F0120ull;

static const uint64_t P9N2_PERV_EC08_CPPM_PERRSUM                                  = 0x280F0120ull;

static const uint64_t P9N2_PERV_EC09_CPPM_PERRSUM                                  = 0x290F0120ull;

static const uint64_t P9N2_PERV_EC10_CPPM_PERRSUM                                  = 0x2A0F0120ull;

static const uint64_t P9N2_PERV_EC11_CPPM_PERRSUM                                  = 0x2B0F0120ull;

static const uint64_t P9N2_PERV_EC12_CPPM_PERRSUM                                  = 0x2C0F0120ull;

static const uint64_t P9N2_PERV_EC13_CPPM_PERRSUM                                  = 0x2D0F0120ull;

static const uint64_t P9N2_PERV_EC14_CPPM_PERRSUM                                  = 0x2E0F0120ull;

static const uint64_t P9N2_PERV_EC15_CPPM_PERRSUM                                  = 0x2F0F0120ull;

static const uint64_t P9N2_PERV_EC16_CPPM_PERRSUM                                  = 0x300F0120ull;

static const uint64_t P9N2_PERV_EC17_CPPM_PERRSUM                                  = 0x310F0120ull;

static const uint64_t P9N2_PERV_EC18_CPPM_PERRSUM                                  = 0x320F0120ull;

static const uint64_t P9N2_PERV_EC19_CPPM_PERRSUM                                  = 0x330F0120ull;

static const uint64_t P9N2_PERV_EC20_CPPM_PERRSUM                                  = 0x340F0120ull;

static const uint64_t P9N2_PERV_EC21_CPPM_PERRSUM                                  = 0x350F0120ull;

static const uint64_t P9N2_PERV_EC22_CPPM_PERRSUM                                  = 0x360F0120ull;

static const uint64_t P9N2_PERV_EC23_CPPM_PERRSUM                                  = 0x370F0120ull;


static const uint64_t P9N2_PERV_CRSIC                                              = 0x00030005ull;

static const uint64_t P9N2_PERV_PIB_CRSIC                                          = 0x00030005ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_CRSIC                                   = 0x00020005ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_CRSIC                                   = 0x00020015ull;

static const uint64_t P9N2_PERV_PIB2OPB0_CRSIC                                     = 0x00020005ull;

static const uint64_t P9N2_PERV_PIB2OPB1_CRSIC                                     = 0x00020015ull;


static const uint64_t P9N2_PERV_CRSIM                                              = 0x00030006ull;

static const uint64_t P9N2_PERV_PIB_CRSIM                                          = 0x00030006ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_CRSIM                                   = 0x00020006ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_CRSIM                                   = 0x00020016ull;

static const uint64_t P9N2_PERV_PIB2OPB0_CRSIM                                     = 0x00020006ull;

static const uint64_t P9N2_PERV_PIB2OPB1_CRSIM                                     = 0x00020016ull;


static const uint64_t P9N2_PERV_CRSIS                                              = 0x00030007ull;

static const uint64_t P9N2_PERV_PIB_CRSIS                                          = 0x00030007ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_CRSIS                                   = 0x00020007ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_CRSIS                                   = 0x00020017ull;

static const uint64_t P9N2_PERV_PIB2OPB0_CRSIS                                     = 0x00020007ull;

static const uint64_t P9N2_PERV_PIB2OPB1_CRSIS                                     = 0x00020017ull;


static const uint64_t P9N2_PERV_CTRL_ATOMIC_LOCK_REG                               = 0x000003FFull;

static const uint64_t P9N2_PERV_TP_CTRL_ATOMIC_LOCK_REG                            = 0x010003FFull;

static const uint64_t P9N2_PERV_N0_CTRL_ATOMIC_LOCK_REG                            = 0x020003FFull;

static const uint64_t P9N2_PERV_N1_CTRL_ATOMIC_LOCK_REG                            = 0x030003FFull;

static const uint64_t P9N2_PERV_N2_CTRL_ATOMIC_LOCK_REG                            = 0x040003FFull;

static const uint64_t P9N2_PERV_N3_CTRL_ATOMIC_LOCK_REG                            = 0x050003FFull;

static const uint64_t P9N2_PERV_XB_CTRL_ATOMIC_LOCK_REG                            = 0x060003FFull;

static const uint64_t P9N2_PERV_MC01_CTRL_ATOMIC_LOCK_REG                          = 0x070003FFull;

static const uint64_t P9N2_PERV_MC23_CTRL_ATOMIC_LOCK_REG                          = 0x080003FFull;

static const uint64_t P9N2_PERV_OB0_CTRL_ATOMIC_LOCK_REG                           = 0x090003FFull;

static const uint64_t P9N2_PERV_OB3_CTRL_ATOMIC_LOCK_REG                           = 0x0C0003FFull;

static const uint64_t P9N2_PERV_PCI0_CTRL_ATOMIC_LOCK_REG                          = 0x0D0003FFull;

static const uint64_t P9N2_PERV_PCI1_CTRL_ATOMIC_LOCK_REG                          = 0x0E0003FFull;

static const uint64_t P9N2_PERV_PCI2_CTRL_ATOMIC_LOCK_REG                          = 0x0F0003FFull;

static const uint64_t P9N2_PERV_EP00_CTRL_ATOMIC_LOCK_REG                          = 0x100003FFull;

static const uint64_t P9N2_PERV_EP01_CTRL_ATOMIC_LOCK_REG                          = 0x110003FFull;

static const uint64_t P9N2_PERV_EP02_CTRL_ATOMIC_LOCK_REG                          = 0x120003FFull;

static const uint64_t P9N2_PERV_EP03_CTRL_ATOMIC_LOCK_REG                          = 0x130003FFull;

static const uint64_t P9N2_PERV_EP04_CTRL_ATOMIC_LOCK_REG                          = 0x140003FFull;

static const uint64_t P9N2_PERV_EP05_CTRL_ATOMIC_LOCK_REG                          = 0x150003FFull;

static const uint64_t P9N2_PERV_EC00_CTRL_ATOMIC_LOCK_REG                          = 0x200003FFull;

static const uint64_t P9N2_PERV_EC01_CTRL_ATOMIC_LOCK_REG                          = 0x210003FFull;

static const uint64_t P9N2_PERV_EC02_CTRL_ATOMIC_LOCK_REG                          = 0x220003FFull;

static const uint64_t P9N2_PERV_EC03_CTRL_ATOMIC_LOCK_REG                          = 0x230003FFull;

static const uint64_t P9N2_PERV_EC04_CTRL_ATOMIC_LOCK_REG                          = 0x240003FFull;

static const uint64_t P9N2_PERV_EC05_CTRL_ATOMIC_LOCK_REG                          = 0x250003FFull;

static const uint64_t P9N2_PERV_EC06_CTRL_ATOMIC_LOCK_REG                          = 0x260003FFull;

static const uint64_t P9N2_PERV_EC07_CTRL_ATOMIC_LOCK_REG                          = 0x270003FFull;

static const uint64_t P9N2_PERV_EC08_CTRL_ATOMIC_LOCK_REG                          = 0x280003FFull;

static const uint64_t P9N2_PERV_EC09_CTRL_ATOMIC_LOCK_REG                          = 0x290003FFull;

static const uint64_t P9N2_PERV_EC10_CTRL_ATOMIC_LOCK_REG                          = 0x2A0003FFull;

static const uint64_t P9N2_PERV_EC11_CTRL_ATOMIC_LOCK_REG                          = 0x2B0003FFull;

static const uint64_t P9N2_PERV_EC12_CTRL_ATOMIC_LOCK_REG                          = 0x2C0003FFull;

static const uint64_t P9N2_PERV_EC13_CTRL_ATOMIC_LOCK_REG                          = 0x2D0003FFull;

static const uint64_t P9N2_PERV_EC14_CTRL_ATOMIC_LOCK_REG                          = 0x2E0003FFull;

static const uint64_t P9N2_PERV_EC15_CTRL_ATOMIC_LOCK_REG                          = 0x2F0003FFull;

static const uint64_t P9N2_PERV_EC16_CTRL_ATOMIC_LOCK_REG                          = 0x300003FFull;

static const uint64_t P9N2_PERV_EC17_CTRL_ATOMIC_LOCK_REG                          = 0x310003FFull;

static const uint64_t P9N2_PERV_EC18_CTRL_ATOMIC_LOCK_REG                          = 0x320003FFull;

static const uint64_t P9N2_PERV_EC19_CTRL_ATOMIC_LOCK_REG                          = 0x330003FFull;

static const uint64_t P9N2_PERV_EC20_CTRL_ATOMIC_LOCK_REG                          = 0x340003FFull;

static const uint64_t P9N2_PERV_EC21_CTRL_ATOMIC_LOCK_REG                          = 0x350003FFull;

static const uint64_t P9N2_PERV_EC22_CTRL_ATOMIC_LOCK_REG                          = 0x360003FFull;

static const uint64_t P9N2_PERV_EC23_CTRL_ATOMIC_LOCK_REG                          = 0x370003FFull;


static const uint64_t P9N2_PERV_CTRL_PROTECT_MODE_REG                              = 0x000003FEull;

static const uint64_t P9N2_PERV_TP_CTRL_PROTECT_MODE_REG                           = 0x010003FEull;

static const uint64_t P9N2_PERV_N0_CTRL_PROTECT_MODE_REG                           = 0x020003FEull;

static const uint64_t P9N2_PERV_N1_CTRL_PROTECT_MODE_REG                           = 0x030003FEull;

static const uint64_t P9N2_PERV_N2_CTRL_PROTECT_MODE_REG                           = 0x040003FEull;

static const uint64_t P9N2_PERV_N3_CTRL_PROTECT_MODE_REG                           = 0x050003FEull;

static const uint64_t P9N2_PERV_XB_CTRL_PROTECT_MODE_REG                           = 0x060003FEull;

static const uint64_t P9N2_PERV_MC01_CTRL_PROTECT_MODE_REG                         = 0x070003FEull;

static const uint64_t P9N2_PERV_MC23_CTRL_PROTECT_MODE_REG                         = 0x080003FEull;

static const uint64_t P9N2_PERV_OB0_CTRL_PROTECT_MODE_REG                          = 0x090003FEull;

static const uint64_t P9N2_PERV_OB3_CTRL_PROTECT_MODE_REG                          = 0x0C0003FEull;

static const uint64_t P9N2_PERV_PCI0_CTRL_PROTECT_MODE_REG                         = 0x0D0003FEull;

static const uint64_t P9N2_PERV_PCI1_CTRL_PROTECT_MODE_REG                         = 0x0E0003FEull;

static const uint64_t P9N2_PERV_PCI2_CTRL_PROTECT_MODE_REG                         = 0x0F0003FEull;

static const uint64_t P9N2_PERV_EP00_CTRL_PROTECT_MODE_REG                         = 0x100003FEull;

static const uint64_t P9N2_PERV_EP01_CTRL_PROTECT_MODE_REG                         = 0x110003FEull;

static const uint64_t P9N2_PERV_EP02_CTRL_PROTECT_MODE_REG                         = 0x120003FEull;

static const uint64_t P9N2_PERV_EP03_CTRL_PROTECT_MODE_REG                         = 0x130003FEull;

static const uint64_t P9N2_PERV_EP04_CTRL_PROTECT_MODE_REG                         = 0x140003FEull;

static const uint64_t P9N2_PERV_EP05_CTRL_PROTECT_MODE_REG                         = 0x150003FEull;

static const uint64_t P9N2_PERV_EC00_CTRL_PROTECT_MODE_REG                         = 0x200003FEull;

static const uint64_t P9N2_PERV_EC01_CTRL_PROTECT_MODE_REG                         = 0x210003FEull;

static const uint64_t P9N2_PERV_EC02_CTRL_PROTECT_MODE_REG                         = 0x220003FEull;

static const uint64_t P9N2_PERV_EC03_CTRL_PROTECT_MODE_REG                         = 0x230003FEull;

static const uint64_t P9N2_PERV_EC04_CTRL_PROTECT_MODE_REG                         = 0x240003FEull;

static const uint64_t P9N2_PERV_EC05_CTRL_PROTECT_MODE_REG                         = 0x250003FEull;

static const uint64_t P9N2_PERV_EC06_CTRL_PROTECT_MODE_REG                         = 0x260003FEull;

static const uint64_t P9N2_PERV_EC07_CTRL_PROTECT_MODE_REG                         = 0x270003FEull;

static const uint64_t P9N2_PERV_EC08_CTRL_PROTECT_MODE_REG                         = 0x280003FEull;

static const uint64_t P9N2_PERV_EC09_CTRL_PROTECT_MODE_REG                         = 0x290003FEull;

static const uint64_t P9N2_PERV_EC10_CTRL_PROTECT_MODE_REG                         = 0x2A0003FEull;

static const uint64_t P9N2_PERV_EC11_CTRL_PROTECT_MODE_REG                         = 0x2B0003FEull;

static const uint64_t P9N2_PERV_EC12_CTRL_PROTECT_MODE_REG                         = 0x2C0003FEull;

static const uint64_t P9N2_PERV_EC13_CTRL_PROTECT_MODE_REG                         = 0x2D0003FEull;

static const uint64_t P9N2_PERV_EC14_CTRL_PROTECT_MODE_REG                         = 0x2E0003FEull;

static const uint64_t P9N2_PERV_EC15_CTRL_PROTECT_MODE_REG                         = 0x2F0003FEull;

static const uint64_t P9N2_PERV_EC16_CTRL_PROTECT_MODE_REG                         = 0x300003FEull;

static const uint64_t P9N2_PERV_EC17_CTRL_PROTECT_MODE_REG                         = 0x310003FEull;

static const uint64_t P9N2_PERV_EC18_CTRL_PROTECT_MODE_REG                         = 0x320003FEull;

static const uint64_t P9N2_PERV_EC19_CTRL_PROTECT_MODE_REG                         = 0x330003FEull;

static const uint64_t P9N2_PERV_EC20_CTRL_PROTECT_MODE_REG                         = 0x340003FEull;

static const uint64_t P9N2_PERV_EC21_CTRL_PROTECT_MODE_REG                         = 0x350003FEull;

static const uint64_t P9N2_PERV_EC22_CTRL_PROTECT_MODE_REG                         = 0x360003FEull;

static const uint64_t P9N2_PERV_EC23_CTRL_PROTECT_MODE_REG                         = 0x370003FEull;


static const uint32_t P9N2_PERV_FSI2PIB_DATA_REGISTER_0_FSI                        = 0x00001000ull;


static const uint32_t P9N2_PERV_FSI2PIB_DATA_REGISTER_1_FSI                        = 0x00001001ull;

static const uint32_t P9N2_PERV_FSI2PIB_DATA_REGISTER_1_FSI_BYTE                   = 0x00001004ull;


static const uint64_t P9N2_PERV_DBG_CBS_CC                                         = 0x00030013ull;

static const uint64_t P9N2_PERV_TP_DBG_CBS_CC                                      = 0x01030013ull;

static const uint64_t P9N2_PERV_N0_DBG_CBS_CC                                      = 0x02030013ull;

static const uint64_t P9N2_PERV_N1_DBG_CBS_CC                                      = 0x03030013ull;

static const uint64_t P9N2_PERV_N2_DBG_CBS_CC                                      = 0x04030013ull;

static const uint64_t P9N2_PERV_N3_DBG_CBS_CC                                      = 0x05030013ull;

static const uint64_t P9N2_PERV_XB_DBG_CBS_CC                                      = 0x06030013ull;

static const uint64_t P9N2_PERV_MC01_DBG_CBS_CC                                    = 0x07030013ull;

static const uint64_t P9N2_PERV_MC23_DBG_CBS_CC                                    = 0x08030013ull;

static const uint64_t P9N2_PERV_OB0_DBG_CBS_CC                                     = 0x09030013ull;

static const uint64_t P9N2_PERV_OB3_DBG_CBS_CC                                     = 0x0C030013ull;

static const uint64_t P9N2_PERV_PCI0_DBG_CBS_CC                                    = 0x0D030013ull;

static const uint64_t P9N2_PERV_PCI1_DBG_CBS_CC                                    = 0x0E030013ull;

static const uint64_t P9N2_PERV_PCI2_DBG_CBS_CC                                    = 0x0F030013ull;

static const uint64_t P9N2_PERV_EP00_DBG_CBS_CC                                    = 0x10030013ull;

static const uint64_t P9N2_PERV_EP01_DBG_CBS_CC                                    = 0x11030013ull;

static const uint64_t P9N2_PERV_EP02_DBG_CBS_CC                                    = 0x12030013ull;

static const uint64_t P9N2_PERV_EP03_DBG_CBS_CC                                    = 0x13030013ull;

static const uint64_t P9N2_PERV_EP04_DBG_CBS_CC                                    = 0x14030013ull;

static const uint64_t P9N2_PERV_EP05_DBG_CBS_CC                                    = 0x15030013ull;

static const uint64_t P9N2_PERV_EC00_DBG_CBS_CC                                    = 0x20030013ull;

static const uint64_t P9N2_PERV_EC01_DBG_CBS_CC                                    = 0x21030013ull;

static const uint64_t P9N2_PERV_EC02_DBG_CBS_CC                                    = 0x22030013ull;

static const uint64_t P9N2_PERV_EC03_DBG_CBS_CC                                    = 0x23030013ull;

static const uint64_t P9N2_PERV_EC04_DBG_CBS_CC                                    = 0x24030013ull;

static const uint64_t P9N2_PERV_EC05_DBG_CBS_CC                                    = 0x25030013ull;

static const uint64_t P9N2_PERV_EC06_DBG_CBS_CC                                    = 0x26030013ull;

static const uint64_t P9N2_PERV_EC07_DBG_CBS_CC                                    = 0x27030013ull;

static const uint64_t P9N2_PERV_EC08_DBG_CBS_CC                                    = 0x28030013ull;

static const uint64_t P9N2_PERV_EC09_DBG_CBS_CC                                    = 0x29030013ull;

static const uint64_t P9N2_PERV_EC10_DBG_CBS_CC                                    = 0x2A030013ull;

static const uint64_t P9N2_PERV_EC11_DBG_CBS_CC                                    = 0x2B030013ull;

static const uint64_t P9N2_PERV_EC12_DBG_CBS_CC                                    = 0x2C030013ull;

static const uint64_t P9N2_PERV_EC13_DBG_CBS_CC                                    = 0x2D030013ull;

static const uint64_t P9N2_PERV_EC14_DBG_CBS_CC                                    = 0x2E030013ull;

static const uint64_t P9N2_PERV_EC15_DBG_CBS_CC                                    = 0x2F030013ull;

static const uint64_t P9N2_PERV_EC16_DBG_CBS_CC                                    = 0x30030013ull;

static const uint64_t P9N2_PERV_EC17_DBG_CBS_CC                                    = 0x31030013ull;

static const uint64_t P9N2_PERV_EC18_DBG_CBS_CC                                    = 0x32030013ull;

static const uint64_t P9N2_PERV_EC19_DBG_CBS_CC                                    = 0x33030013ull;

static const uint64_t P9N2_PERV_EC20_DBG_CBS_CC                                    = 0x34030013ull;

static const uint64_t P9N2_PERV_EC21_DBG_CBS_CC                                    = 0x35030013ull;

static const uint64_t P9N2_PERV_EC22_DBG_CBS_CC                                    = 0x36030013ull;

static const uint64_t P9N2_PERV_EC23_DBG_CBS_CC                                    = 0x37030013ull;


static const uint64_t P9N2_PERV_DBG_INST1_COND_REG_1                               = 0x000107C1ull;

static const uint64_t P9N2_PERV_TP_DBG_INST1_COND_REG_1                            = 0x010107C1ull;


static const uint64_t P9N2_PERV_DBG_INST1_COND_REG_2                               = 0x000107C2ull;

static const uint64_t P9N2_PERV_TP_DBG_INST1_COND_REG_2                            = 0x010107C2ull;


static const uint64_t P9N2_PERV_DBG_INST1_COND_REG_3                               = 0x000107C3ull;

static const uint64_t P9N2_PERV_TP_DBG_INST1_COND_REG_3                            = 0x010107C3ull;


static const uint64_t P9N2_PERV_DBG_INST2_COND_REG_1                               = 0x000107C4ull;

static const uint64_t P9N2_PERV_TP_DBG_INST2_COND_REG_1                            = 0x010107C4ull;


static const uint64_t P9N2_PERV_DBG_INST2_COND_REG_2                               = 0x000107C5ull;

static const uint64_t P9N2_PERV_TP_DBG_INST2_COND_REG_2                            = 0x010107C5ull;


static const uint64_t P9N2_PERV_DBG_INST2_COND_REG_3                               = 0x000107C6ull;

static const uint64_t P9N2_PERV_TP_DBG_INST2_COND_REG_3                            = 0x010107C6ull;


static const uint64_t P9N2_PERV_DBG_MODE_REG                                       = 0x000107C0ull;

static const uint64_t P9N2_PERV_TP_DBG_MODE_REG                                    = 0x010107C0ull;


static const uint64_t P9N2_PERV_DBG_TRACE_MODE_REG_2                               = 0x000107CFull;

static const uint64_t P9N2_PERV_TP_DBG_TRACE_MODE_REG_2                            = 0x010107CFull;


static const uint64_t P9N2_PERV_DBG_TRACE_REG_0                                    = 0x000107CDull;

static const uint64_t P9N2_PERV_TP_DBG_TRACE_REG_0                                 = 0x010107CDull;


static const uint64_t P9N2_PERV_DBG_TRACE_REG_1                                    = 0x000107CEull;

static const uint64_t P9N2_PERV_TP_DBG_TRACE_REG_1                                 = 0x010107CEull;


static const uint64_t P9N2_PERV_DEBUG_TRACE_CONTROL                                = 0x000107D0ull;

static const uint64_t P9N2_PERV_TP_DEBUG_TRACE_CONTROL                             = 0x010107D0ull;


static const uint64_t P9N2_PERV_DEVICE_ID_REG                                      = 0x000F000Full;

static const uint64_t P9N2_PERV_PIB_DEVICE_ID_REG                                  = 0x000F000Full;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_ERROR_PTR_REGISTER_FSI                = 0x00000C21ull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_ERROR_PTR_REGISTER_FSI_BYTE           = 0x00000C84ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_MODE_REGISTER_FSI                     = 0x00000C19ull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_MODE_REGISTER_FSI_BYTE                = 0x00000C64ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_FSI             = 0x00000C1Bull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_OP_BLOCKSIZE_REGISTER_FSI_BYTE        = 0x00000C6Cull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI          = 0x00000C1Full;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER0_REGISTER_FSI_BYTE     = 0x00000C7Cull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI          = 0x00000C20ull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_RCV_BUFFER1_REGISTER_FSI_BYTE     = 0x00000C80ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_SND_BUFFER0_REGISTER_FSI          = 0x00000C1Dull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_SND_BUFFER0_REGISTER_FSI_BYTE     = 0x00000C74ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_SND_BUFFER1_REGISTER_FSI          = 0x00000C1Eull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_PIB_SND_BUFFER1_REGISTER_FSI_BYTE     = 0x00000C78ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_REM_SIZE_REGISTER_FSI                 = 0x00000C1Cull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_REM_SIZE_REGISTER_FSI_BYTE            = 0x00000C70ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_SCOM_CMD_REGISTER_FSI                 = 0x00000C22ull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_SCOM_CMD_REGISTER_FSI_BYTE            = 0x00000C88ull;


static const uint32_t P9N2_PERV_FSISHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI           = 0x00000C1Aull;

static const uint32_t P9N2_PERV_FSISHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE      = 0x00000C68ull;


static const uint32_t P9N2_PERV_DOORBELL_STATUS_CONTROL_1A_FSI                     = 0x00002824ull;

static const uint32_t P9N2_PERV_DOORBELL_STATUS_CONTROL_1A_FSI_BYTE                = 0x00002890ull;

static const uint64_t P9N2_PERV_DOORBELL_STATUS_CONTROL_1A_SCOM                    = 0x00050020ull;

static const uint64_t P9N2_PERV_PIB_DOORBELL_STATUS_CONTROL_1A                     = 0x00050020ull;


static const uint32_t P9N2_PERV_DOORBELL_STATUS_CONTROL_2A_FSI                     = 0x0000282Cull;

static const uint32_t P9N2_PERV_DOORBELL_STATUS_CONTROL_2A_FSI_BYTE                = 0x000028B0ull;

static const uint64_t P9N2_PERV_DOORBELL_STATUS_CONTROL_2A_SCOM                    = 0x00050028ull;

static const uint64_t P9N2_PERV_PIB_DOORBELL_STATUS_CONTROL_2A                     = 0x00050028ull;


static const uint64_t P9N2_PERV_DTS_RESULT0                                        = 0x00050000ull;

static const uint64_t P9N2_PERV_TP_DTS_RESULT0                                     = 0x01050000ull;

static const uint64_t P9N2_PERV_N0_DTS_RESULT0                                     = 0x02050000ull;

static const uint64_t P9N2_PERV_N1_DTS_RESULT0                                     = 0x03050000ull;

static const uint64_t P9N2_PERV_N2_DTS_RESULT0                                     = 0x04050000ull;

static const uint64_t P9N2_PERV_N3_DTS_RESULT0                                     = 0x05050000ull;

static const uint64_t P9N2_PERV_XB_DTS_RESULT0                                     = 0x06050000ull;

static const uint64_t P9N2_PERV_MC01_DTS_RESULT0                                   = 0x07050000ull;

static const uint64_t P9N2_PERV_MC23_DTS_RESULT0                                   = 0x08050000ull;

static const uint64_t P9N2_PERV_OB0_DTS_RESULT0                                    = 0x09050000ull;

static const uint64_t P9N2_PERV_OB3_DTS_RESULT0                                    = 0x0C050000ull;

static const uint64_t P9N2_PERV_PCI0_DTS_RESULT0                                   = 0x0D050000ull;

static const uint64_t P9N2_PERV_PCI1_DTS_RESULT0                                   = 0x0E050000ull;

static const uint64_t P9N2_PERV_PCI2_DTS_RESULT0                                   = 0x0F050000ull;

static const uint64_t P9N2_PERV_EP00_DTS_RESULT0                                   = 0x10050000ull;

static const uint64_t P9N2_PERV_EP01_DTS_RESULT0                                   = 0x11050000ull;

static const uint64_t P9N2_PERV_EP02_DTS_RESULT0                                   = 0x12050000ull;

static const uint64_t P9N2_PERV_EP03_DTS_RESULT0                                   = 0x13050000ull;

static const uint64_t P9N2_PERV_EP04_DTS_RESULT0                                   = 0x14050000ull;

static const uint64_t P9N2_PERV_EP05_DTS_RESULT0                                   = 0x15050000ull;

static const uint64_t P9N2_PERV_EC00_DTS_RESULT0                                   = 0x20050000ull;

static const uint64_t P9N2_PERV_EC01_DTS_RESULT0                                   = 0x21050000ull;

static const uint64_t P9N2_PERV_EC02_DTS_RESULT0                                   = 0x22050000ull;

static const uint64_t P9N2_PERV_EC03_DTS_RESULT0                                   = 0x23050000ull;

static const uint64_t P9N2_PERV_EC04_DTS_RESULT0                                   = 0x24050000ull;

static const uint64_t P9N2_PERV_EC05_DTS_RESULT0                                   = 0x25050000ull;

static const uint64_t P9N2_PERV_EC06_DTS_RESULT0                                   = 0x26050000ull;

static const uint64_t P9N2_PERV_EC07_DTS_RESULT0                                   = 0x27050000ull;

static const uint64_t P9N2_PERV_EC08_DTS_RESULT0                                   = 0x28050000ull;

static const uint64_t P9N2_PERV_EC09_DTS_RESULT0                                   = 0x29050000ull;

static const uint64_t P9N2_PERV_EC10_DTS_RESULT0                                   = 0x2A050000ull;

static const uint64_t P9N2_PERV_EC11_DTS_RESULT0                                   = 0x2B050000ull;

static const uint64_t P9N2_PERV_EC12_DTS_RESULT0                                   = 0x2C050000ull;

static const uint64_t P9N2_PERV_EC13_DTS_RESULT0                                   = 0x2D050000ull;

static const uint64_t P9N2_PERV_EC14_DTS_RESULT0                                   = 0x2E050000ull;

static const uint64_t P9N2_PERV_EC15_DTS_RESULT0                                   = 0x2F050000ull;

static const uint64_t P9N2_PERV_EC16_DTS_RESULT0                                   = 0x30050000ull;

static const uint64_t P9N2_PERV_EC17_DTS_RESULT0                                   = 0x31050000ull;

static const uint64_t P9N2_PERV_EC18_DTS_RESULT0                                   = 0x32050000ull;

static const uint64_t P9N2_PERV_EC19_DTS_RESULT0                                   = 0x33050000ull;

static const uint64_t P9N2_PERV_EC20_DTS_RESULT0                                   = 0x34050000ull;

static const uint64_t P9N2_PERV_EC21_DTS_RESULT0                                   = 0x35050000ull;

static const uint64_t P9N2_PERV_EC22_DTS_RESULT0                                   = 0x36050000ull;

static const uint64_t P9N2_PERV_EC23_DTS_RESULT0                                   = 0x37050000ull;


static const uint64_t P9N2_PERV_DTS_TRC_RESULT                                     = 0x00050003ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_DTS_TRC_RESULT                                  = 0x01050003ull;

static const uint64_t P9N2_PERV_N0_DTS_TRC_RESULT                                  = 0x02050003ull;

static const uint64_t P9N2_PERV_N1_DTS_TRC_RESULT                                  = 0x03050003ull;

static const uint64_t P9N2_PERV_N2_DTS_TRC_RESULT                                  = 0x04050003ull;

static const uint64_t P9N2_PERV_N3_DTS_TRC_RESULT                                  = 0x05050003ull;

static const uint64_t P9N2_PERV_XB_DTS_TRC_RESULT                                  = 0x06050003ull;

static const uint64_t P9N2_PERV_MC01_DTS_TRC_RESULT                                = 0x07050003ull;

static const uint64_t P9N2_PERV_MC23_DTS_TRC_RESULT                                = 0x08050003ull;

static const uint64_t P9N2_PERV_OB0_DTS_TRC_RESULT                                 = 0x09050003ull;

static const uint64_t P9N2_PERV_OB3_DTS_TRC_RESULT                                 = 0x0C050003ull;

static const uint64_t P9N2_PERV_PCI0_DTS_TRC_RESULT                                = 0x0D050003ull;

static const uint64_t P9N2_PERV_PCI1_DTS_TRC_RESULT                                = 0x0E050003ull;

static const uint64_t P9N2_PERV_PCI2_DTS_TRC_RESULT                                = 0x0F050003ull;

static const uint64_t P9N2_PERV_EP00_DTS_TRC_RESULT                                = 0x10050003ull;

static const uint64_t P9N2_PERV_EP01_DTS_TRC_RESULT                                = 0x11050003ull;

static const uint64_t P9N2_PERV_EP02_DTS_TRC_RESULT                                = 0x12050003ull;

static const uint64_t P9N2_PERV_EP03_DTS_TRC_RESULT                                = 0x13050003ull;

static const uint64_t P9N2_PERV_EP04_DTS_TRC_RESULT                                = 0x14050003ull;

static const uint64_t P9N2_PERV_EP05_DTS_TRC_RESULT                                = 0x15050003ull;

static const uint64_t P9N2_PERV_EC00_DTS_TRC_RESULT                                = 0x20050003ull;

static const uint64_t P9N2_PERV_EC01_DTS_TRC_RESULT                                = 0x21050003ull;

static const uint64_t P9N2_PERV_EC02_DTS_TRC_RESULT                                = 0x22050003ull;

static const uint64_t P9N2_PERV_EC03_DTS_TRC_RESULT                                = 0x23050003ull;

static const uint64_t P9N2_PERV_EC04_DTS_TRC_RESULT                                = 0x24050003ull;

static const uint64_t P9N2_PERV_EC05_DTS_TRC_RESULT                                = 0x25050003ull;

static const uint64_t P9N2_PERV_EC06_DTS_TRC_RESULT                                = 0x26050003ull;

static const uint64_t P9N2_PERV_EC07_DTS_TRC_RESULT                                = 0x27050003ull;

static const uint64_t P9N2_PERV_EC08_DTS_TRC_RESULT                                = 0x28050003ull;

static const uint64_t P9N2_PERV_EC09_DTS_TRC_RESULT                                = 0x29050003ull;

static const uint64_t P9N2_PERV_EC10_DTS_TRC_RESULT                                = 0x2A050003ull;

static const uint64_t P9N2_PERV_EC11_DTS_TRC_RESULT                                = 0x2B050003ull;

static const uint64_t P9N2_PERV_EC12_DTS_TRC_RESULT                                = 0x2C050003ull;

static const uint64_t P9N2_PERV_EC13_DTS_TRC_RESULT                                = 0x2D050003ull;

static const uint64_t P9N2_PERV_EC14_DTS_TRC_RESULT                                = 0x2E050003ull;

static const uint64_t P9N2_PERV_EC15_DTS_TRC_RESULT                                = 0x2F050003ull;

static const uint64_t P9N2_PERV_EC16_DTS_TRC_RESULT                                = 0x30050003ull;

static const uint64_t P9N2_PERV_EC17_DTS_TRC_RESULT                                = 0x31050003ull;

static const uint64_t P9N2_PERV_EC18_DTS_TRC_RESULT                                = 0x32050003ull;

static const uint64_t P9N2_PERV_EC19_DTS_TRC_RESULT                                = 0x33050003ull;

static const uint64_t P9N2_PERV_EC20_DTS_TRC_RESULT                                = 0x34050003ull;

static const uint64_t P9N2_PERV_EC21_DTS_TRC_RESULT                                = 0x35050003ull;

static const uint64_t P9N2_PERV_EC22_DTS_TRC_RESULT                                = 0x36050003ull;

static const uint64_t P9N2_PERV_EC23_DTS_TRC_RESULT                                = 0x37050003ull;


static const uint64_t P9N2_PERV_EDRAM_STATUS                                       = 0x000F0029ull;

static const uint64_t P9N2_PERV_TP_EDRAM_STATUS                                    = 0x010F0029ull;

static const uint64_t P9N2_PERV_N0_EDRAM_STATUS                                    = 0x020F0029ull;

static const uint64_t P9N2_PERV_N1_EDRAM_STATUS                                    = 0x030F0029ull;

static const uint64_t P9N2_PERV_N2_EDRAM_STATUS                                    = 0x040F0029ull;

static const uint64_t P9N2_PERV_N3_EDRAM_STATUS                                    = 0x050F0029ull;

static const uint64_t P9N2_PERV_XB_EDRAM_STATUS                                    = 0x060F0029ull;

static const uint64_t P9N2_PERV_MC01_EDRAM_STATUS                                  = 0x070F0029ull;

static const uint64_t P9N2_PERV_MC23_EDRAM_STATUS                                  = 0x080F0029ull;

static const uint64_t P9N2_PERV_OB0_EDRAM_STATUS                                   = 0x090F0029ull;

static const uint64_t P9N2_PERV_OB3_EDRAM_STATUS                                   = 0x0C0F0029ull;

static const uint64_t P9N2_PERV_PCI0_EDRAM_STATUS                                  = 0x0D0F0029ull;

static const uint64_t P9N2_PERV_PCI1_EDRAM_STATUS                                  = 0x0E0F0029ull;

static const uint64_t P9N2_PERV_PCI2_EDRAM_STATUS                                  = 0x0F0F0029ull;

static const uint64_t P9N2_PERV_EP00_EDRAM_STATUS                                  = 0x100F0029ull;

static const uint64_t P9N2_PERV_EP01_EDRAM_STATUS                                  = 0x110F0029ull;

static const uint64_t P9N2_PERV_EP02_EDRAM_STATUS                                  = 0x120F0029ull;

static const uint64_t P9N2_PERV_EP03_EDRAM_STATUS                                  = 0x130F0029ull;

static const uint64_t P9N2_PERV_EP04_EDRAM_STATUS                                  = 0x140F0029ull;

static const uint64_t P9N2_PERV_EP05_EDRAM_STATUS                                  = 0x150F0029ull;

static const uint64_t P9N2_PERV_EC00_EDRAM_STATUS                                  = 0x200F0029ull;

static const uint64_t P9N2_PERV_EC01_EDRAM_STATUS                                  = 0x210F0029ull;

static const uint64_t P9N2_PERV_EC02_EDRAM_STATUS                                  = 0x220F0029ull;

static const uint64_t P9N2_PERV_EC03_EDRAM_STATUS                                  = 0x230F0029ull;

static const uint64_t P9N2_PERV_EC04_EDRAM_STATUS                                  = 0x240F0029ull;

static const uint64_t P9N2_PERV_EC05_EDRAM_STATUS                                  = 0x250F0029ull;

static const uint64_t P9N2_PERV_EC06_EDRAM_STATUS                                  = 0x260F0029ull;

static const uint64_t P9N2_PERV_EC07_EDRAM_STATUS                                  = 0x270F0029ull;

static const uint64_t P9N2_PERV_EC08_EDRAM_STATUS                                  = 0x280F0029ull;

static const uint64_t P9N2_PERV_EC09_EDRAM_STATUS                                  = 0x290F0029ull;

static const uint64_t P9N2_PERV_EC10_EDRAM_STATUS                                  = 0x2A0F0029ull;

static const uint64_t P9N2_PERV_EC11_EDRAM_STATUS                                  = 0x2B0F0029ull;

static const uint64_t P9N2_PERV_EC12_EDRAM_STATUS                                  = 0x2C0F0029ull;

static const uint64_t P9N2_PERV_EC13_EDRAM_STATUS                                  = 0x2D0F0029ull;

static const uint64_t P9N2_PERV_EC14_EDRAM_STATUS                                  = 0x2E0F0029ull;

static const uint64_t P9N2_PERV_EC15_EDRAM_STATUS                                  = 0x2F0F0029ull;

static const uint64_t P9N2_PERV_EC16_EDRAM_STATUS                                  = 0x300F0029ull;

static const uint64_t P9N2_PERV_EC17_EDRAM_STATUS                                  = 0x310F0029ull;

static const uint64_t P9N2_PERV_EC18_EDRAM_STATUS                                  = 0x320F0029ull;

static const uint64_t P9N2_PERV_EC19_EDRAM_STATUS                                  = 0x330F0029ull;

static const uint64_t P9N2_PERV_EC20_EDRAM_STATUS                                  = 0x340F0029ull;

static const uint64_t P9N2_PERV_EC21_EDRAM_STATUS                                  = 0x350F0029ull;

static const uint64_t P9N2_PERV_EC22_EDRAM_STATUS                                  = 0x360F0029ull;

static const uint64_t P9N2_PERV_EC23_EDRAM_STATUS                                  = 0x370F0029ull;


static const uint64_t P9N2_PERV_ERROR_REG                                          = 0x000F001Full;

static const uint64_t P9N2_PERV_PIB_ERROR_REG                                      = 0x000F001Full;

static const uint64_t P9N2_PERV_TP_ERROR_REG                                       = 0x010F001Full;

static const uint64_t P9N2_PERV_N0_ERROR_REG                                       = 0x020F001Full;

static const uint64_t P9N2_PERV_N1_ERROR_REG                                       = 0x030F001Full;

static const uint64_t P9N2_PERV_N2_ERROR_REG                                       = 0x040F001Full;

static const uint64_t P9N2_PERV_N3_ERROR_REG                                       = 0x050F001Full;

static const uint64_t P9N2_PERV_XB_ERROR_REG                                       = 0x060F001Full;

static const uint64_t P9N2_PERV_MC01_ERROR_REG                                     = 0x070F001Full;

static const uint64_t P9N2_PERV_MC23_ERROR_REG                                     = 0x080F001Full;

static const uint64_t P9N2_PERV_OB0_ERROR_REG                                      = 0x090F001Full;

static const uint64_t P9N2_PERV_OB3_ERROR_REG                                      = 0x0C0F001Full;

static const uint64_t P9N2_PERV_PCI0_ERROR_REG                                     = 0x0D0F001Full;

static const uint64_t P9N2_PERV_PCI1_ERROR_REG                                     = 0x0E0F001Full;

static const uint64_t P9N2_PERV_PCI2_ERROR_REG                                     = 0x0F0F001Full;

static const uint64_t P9N2_PERV_EP00_ERROR_REG                                     = 0x100F001Full;

static const uint64_t P9N2_PERV_EP01_ERROR_REG                                     = 0x110F001Full;

static const uint64_t P9N2_PERV_EP02_ERROR_REG                                     = 0x120F001Full;

static const uint64_t P9N2_PERV_EP03_ERROR_REG                                     = 0x130F001Full;

static const uint64_t P9N2_PERV_EP04_ERROR_REG                                     = 0x140F001Full;

static const uint64_t P9N2_PERV_EP05_ERROR_REG                                     = 0x150F001Full;

static const uint64_t P9N2_PERV_EC00_ERROR_REG                                     = 0x200F001Full;

static const uint64_t P9N2_PERV_EC01_ERROR_REG                                     = 0x210F001Full;

static const uint64_t P9N2_PERV_EC02_ERROR_REG                                     = 0x220F001Full;

static const uint64_t P9N2_PERV_EC03_ERROR_REG                                     = 0x230F001Full;

static const uint64_t P9N2_PERV_EC04_ERROR_REG                                     = 0x240F001Full;

static const uint64_t P9N2_PERV_EC05_ERROR_REG                                     = 0x250F001Full;

static const uint64_t P9N2_PERV_EC06_ERROR_REG                                     = 0x260F001Full;

static const uint64_t P9N2_PERV_EC07_ERROR_REG                                     = 0x270F001Full;

static const uint64_t P9N2_PERV_EC08_ERROR_REG                                     = 0x280F001Full;

static const uint64_t P9N2_PERV_EC09_ERROR_REG                                     = 0x290F001Full;

static const uint64_t P9N2_PERV_EC10_ERROR_REG                                     = 0x2A0F001Full;

static const uint64_t P9N2_PERV_EC11_ERROR_REG                                     = 0x2B0F001Full;

static const uint64_t P9N2_PERV_EC12_ERROR_REG                                     = 0x2C0F001Full;

static const uint64_t P9N2_PERV_EC13_ERROR_REG                                     = 0x2D0F001Full;

static const uint64_t P9N2_PERV_EC14_ERROR_REG                                     = 0x2E0F001Full;

static const uint64_t P9N2_PERV_EC15_ERROR_REG                                     = 0x2F0F001Full;

static const uint64_t P9N2_PERV_EC16_ERROR_REG                                     = 0x300F001Full;

static const uint64_t P9N2_PERV_EC17_ERROR_REG                                     = 0x310F001Full;

static const uint64_t P9N2_PERV_EC18_ERROR_REG                                     = 0x320F001Full;

static const uint64_t P9N2_PERV_EC19_ERROR_REG                                     = 0x330F001Full;

static const uint64_t P9N2_PERV_EC20_ERROR_REG                                     = 0x340F001Full;

static const uint64_t P9N2_PERV_EC21_ERROR_REG                                     = 0x350F001Full;

static const uint64_t P9N2_PERV_EC22_ERROR_REG                                     = 0x360F001Full;

static const uint64_t P9N2_PERV_EC23_ERROR_REG                                     = 0x370F001Full;


static const uint64_t P9N2_PERV_ERROR_STATUS                                       = 0x0003000Full;

static const uint64_t P9N2_PERV_TP_ERROR_STATUS                                    = 0x0103000Full;

static const uint64_t P9N2_PERV_N0_ERROR_STATUS                                    = 0x0203000Full;

static const uint64_t P9N2_PERV_N1_ERROR_STATUS                                    = 0x0303000Full;

static const uint64_t P9N2_PERV_N2_ERROR_STATUS                                    = 0x0403000Full;

static const uint64_t P9N2_PERV_N3_ERROR_STATUS                                    = 0x0503000Full;

static const uint64_t P9N2_PERV_XB_ERROR_STATUS                                    = 0x0603000Full;

static const uint64_t P9N2_PERV_MC01_ERROR_STATUS                                  = 0x0703000Full;

static const uint64_t P9N2_PERV_MC23_ERROR_STATUS                                  = 0x0803000Full;

static const uint64_t P9N2_PERV_OB0_ERROR_STATUS                                   = 0x0903000Full;

static const uint64_t P9N2_PERV_OB3_ERROR_STATUS                                   = 0x0C03000Full;

static const uint64_t P9N2_PERV_PCI0_ERROR_STATUS                                  = 0x0D03000Full;

static const uint64_t P9N2_PERV_PCI1_ERROR_STATUS                                  = 0x0E03000Full;

static const uint64_t P9N2_PERV_PCI2_ERROR_STATUS                                  = 0x0F03000Full;

static const uint64_t P9N2_PERV_EP00_ERROR_STATUS                                  = 0x1003000Full;

static const uint64_t P9N2_PERV_EP01_ERROR_STATUS                                  = 0x1103000Full;

static const uint64_t P9N2_PERV_EP02_ERROR_STATUS                                  = 0x1203000Full;

static const uint64_t P9N2_PERV_EP03_ERROR_STATUS                                  = 0x1303000Full;

static const uint64_t P9N2_PERV_EP04_ERROR_STATUS                                  = 0x1403000Full;

static const uint64_t P9N2_PERV_EP05_ERROR_STATUS                                  = 0x1503000Full;

static const uint64_t P9N2_PERV_EC00_ERROR_STATUS                                  = 0x2003000Full;

static const uint64_t P9N2_PERV_EC01_ERROR_STATUS                                  = 0x2103000Full;

static const uint64_t P9N2_PERV_EC02_ERROR_STATUS                                  = 0x2203000Full;

static const uint64_t P9N2_PERV_EC03_ERROR_STATUS                                  = 0x2303000Full;

static const uint64_t P9N2_PERV_EC04_ERROR_STATUS                                  = 0x2403000Full;

static const uint64_t P9N2_PERV_EC05_ERROR_STATUS                                  = 0x2503000Full;

static const uint64_t P9N2_PERV_EC06_ERROR_STATUS                                  = 0x2603000Full;

static const uint64_t P9N2_PERV_EC07_ERROR_STATUS                                  = 0x2703000Full;

static const uint64_t P9N2_PERV_EC08_ERROR_STATUS                                  = 0x2803000Full;

static const uint64_t P9N2_PERV_EC09_ERROR_STATUS                                  = 0x2903000Full;

static const uint64_t P9N2_PERV_EC10_ERROR_STATUS                                  = 0x2A03000Full;

static const uint64_t P9N2_PERV_EC11_ERROR_STATUS                                  = 0x2B03000Full;

static const uint64_t P9N2_PERV_EC12_ERROR_STATUS                                  = 0x2C03000Full;

static const uint64_t P9N2_PERV_EC13_ERROR_STATUS                                  = 0x2D03000Full;

static const uint64_t P9N2_PERV_EC14_ERROR_STATUS                                  = 0x2E03000Full;

static const uint64_t P9N2_PERV_EC15_ERROR_STATUS                                  = 0x2F03000Full;

static const uint64_t P9N2_PERV_EC16_ERROR_STATUS                                  = 0x3003000Full;

static const uint64_t P9N2_PERV_EC17_ERROR_STATUS                                  = 0x3103000Full;

static const uint64_t P9N2_PERV_EC18_ERROR_STATUS                                  = 0x3203000Full;

static const uint64_t P9N2_PERV_EC19_ERROR_STATUS                                  = 0x3303000Full;

static const uint64_t P9N2_PERV_EC20_ERROR_STATUS                                  = 0x3403000Full;

static const uint64_t P9N2_PERV_EC21_ERROR_STATUS                                  = 0x3503000Full;

static const uint64_t P9N2_PERV_EC22_ERROR_STATUS                                  = 0x3603000Full;

static const uint64_t P9N2_PERV_EC23_ERROR_STATUS                                  = 0x3703000Full;


static const uint64_t P9N2_PERV_ERROR_STATUS_REG                                   = 0x000F0034ull;

static const uint64_t P9N2_PERV_PIB_ERROR_STATUS_REG                               = 0x000F0034ull;


static const uint64_t P9N2_PERV_ERR_STATUS_REG                                     = 0x00050013ull;

static const uint64_t P9N2_PERV_TP_ERR_STATUS_REG                                  = 0x01050013ull;

static const uint64_t P9N2_PERV_N0_ERR_STATUS_REG                                  = 0x02050013ull;

static const uint64_t P9N2_PERV_N1_ERR_STATUS_REG                                  = 0x03050013ull;

static const uint64_t P9N2_PERV_N2_ERR_STATUS_REG                                  = 0x04050013ull;

static const uint64_t P9N2_PERV_N3_ERR_STATUS_REG                                  = 0x05050013ull;

static const uint64_t P9N2_PERV_XB_ERR_STATUS_REG                                  = 0x06050013ull;

static const uint64_t P9N2_PERV_MC01_ERR_STATUS_REG                                = 0x07050013ull;

static const uint64_t P9N2_PERV_MC23_ERR_STATUS_REG                                = 0x08050013ull;

static const uint64_t P9N2_PERV_OB0_ERR_STATUS_REG                                 = 0x09050013ull;

static const uint64_t P9N2_PERV_OB3_ERR_STATUS_REG                                 = 0x0C050013ull;

static const uint64_t P9N2_PERV_PCI0_ERR_STATUS_REG                                = 0x0D050013ull;

static const uint64_t P9N2_PERV_PCI1_ERR_STATUS_REG                                = 0x0E050013ull;

static const uint64_t P9N2_PERV_PCI2_ERR_STATUS_REG                                = 0x0F050013ull;

static const uint64_t P9N2_PERV_EP00_ERR_STATUS_REG                                = 0x10050013ull;

static const uint64_t P9N2_PERV_EP01_ERR_STATUS_REG                                = 0x11050013ull;

static const uint64_t P9N2_PERV_EP02_ERR_STATUS_REG                                = 0x12050013ull;

static const uint64_t P9N2_PERV_EP03_ERR_STATUS_REG                                = 0x13050013ull;

static const uint64_t P9N2_PERV_EP04_ERR_STATUS_REG                                = 0x14050013ull;

static const uint64_t P9N2_PERV_EP05_ERR_STATUS_REG                                = 0x15050013ull;

static const uint64_t P9N2_PERV_EC00_ERR_STATUS_REG                                = 0x20050013ull;

static const uint64_t P9N2_PERV_EC01_ERR_STATUS_REG                                = 0x21050013ull;

static const uint64_t P9N2_PERV_EC02_ERR_STATUS_REG                                = 0x22050013ull;

static const uint64_t P9N2_PERV_EC03_ERR_STATUS_REG                                = 0x23050013ull;

static const uint64_t P9N2_PERV_EC04_ERR_STATUS_REG                                = 0x24050013ull;

static const uint64_t P9N2_PERV_EC05_ERR_STATUS_REG                                = 0x25050013ull;

static const uint64_t P9N2_PERV_EC06_ERR_STATUS_REG                                = 0x26050013ull;

static const uint64_t P9N2_PERV_EC07_ERR_STATUS_REG                                = 0x27050013ull;

static const uint64_t P9N2_PERV_EC08_ERR_STATUS_REG                                = 0x28050013ull;

static const uint64_t P9N2_PERV_EC09_ERR_STATUS_REG                                = 0x29050013ull;

static const uint64_t P9N2_PERV_EC10_ERR_STATUS_REG                                = 0x2A050013ull;

static const uint64_t P9N2_PERV_EC11_ERR_STATUS_REG                                = 0x2B050013ull;

static const uint64_t P9N2_PERV_EC12_ERR_STATUS_REG                                = 0x2C050013ull;

static const uint64_t P9N2_PERV_EC13_ERR_STATUS_REG                                = 0x2D050013ull;

static const uint64_t P9N2_PERV_EC14_ERR_STATUS_REG                                = 0x2E050013ull;

static const uint64_t P9N2_PERV_EC15_ERR_STATUS_REG                                = 0x2F050013ull;

static const uint64_t P9N2_PERV_EC16_ERR_STATUS_REG                                = 0x30050013ull;

static const uint64_t P9N2_PERV_EC17_ERR_STATUS_REG                                = 0x31050013ull;

static const uint64_t P9N2_PERV_EC18_ERR_STATUS_REG                                = 0x32050013ull;

static const uint64_t P9N2_PERV_EC19_ERR_STATUS_REG                                = 0x33050013ull;

static const uint64_t P9N2_PERV_EC20_ERR_STATUS_REG                                = 0x34050013ull;

static const uint64_t P9N2_PERV_EC21_ERR_STATUS_REG                                = 0x35050013ull;

static const uint64_t P9N2_PERV_EC22_ERR_STATUS_REG                                = 0x36050013ull;

static const uint64_t P9N2_PERV_EC23_ERR_STATUS_REG                                = 0x37050013ull;


static const uint32_t P9N2_PERV_FSISHIFT_EXTENDED_STATUS_FSI                       = 0x00000C08ull;

static const uint32_t P9N2_PERV_FSISHIFT_EXTENDED_STATUS_FSI_BYTE                  = 0x00000C20ull;


static const uint64_t P9N2_PERV_0_FSII2C_EXTENDED_STATUS_A                         = 0x00001808ull;

static const uint32_t P9N2_PERV_FSII2C_EXTENDED_STATUS_A                           = 0x00001808ull;


static const uint64_t P9N2_PERV_0_FSII2C_FIFO1_REGISTER_READ_A                     = 0x00001800ull;

static const uint32_t P9N2_PERV_FSII2C_FIFO1_REGISTER_READ_A                       = 0x00001800ull;


static const uint64_t P9N2_PERV_FIRST_ERR_REG                                      = 0x000F001Eull;

static const uint64_t P9N2_PERV_PIB_FIRST_ERR_REG                                  = 0x000F001Eull;


static const uint64_t P9N2_PERV_FIRST_REPLY_REG                                    = 0x000F0018ull;

static const uint64_t P9N2_PERV_PIB_FIRST_REPLY_REG                                = 0x000F0018ull;


static const uint64_t P9N2_PERV_FIR_MASK                                           = 0x00040002ull;

static const uint64_t P9N2_PERV_TP_FIR_MASK                                        = 0x01040002ull;

static const uint64_t P9N2_PERV_N0_FIR_MASK                                        = 0x02040002ull;

static const uint64_t P9N2_PERV_N1_FIR_MASK                                        = 0x03040002ull;

static const uint64_t P9N2_PERV_N2_FIR_MASK                                        = 0x04040002ull;

static const uint64_t P9N2_PERV_N3_FIR_MASK                                        = 0x05040002ull;

static const uint64_t P9N2_PERV_XB_FIR_MASK                                        = 0x06040002ull;

static const uint64_t P9N2_PERV_MC01_FIR_MASK                                      = 0x07040002ull;

static const uint64_t P9N2_PERV_MC23_FIR_MASK                                      = 0x08040002ull;

static const uint64_t P9N2_PERV_OB0_FIR_MASK                                       = 0x09040002ull;

static const uint64_t P9N2_PERV_OB3_FIR_MASK                                       = 0x0C040002ull;

static const uint64_t P9N2_PERV_PCI0_FIR_MASK                                      = 0x0D040002ull;

static const uint64_t P9N2_PERV_PCI1_FIR_MASK                                      = 0x0E040002ull;

static const uint64_t P9N2_PERV_PCI2_FIR_MASK                                      = 0x0F040002ull;

static const uint64_t P9N2_PERV_EP00_FIR_MASK                                      = 0x10040002ull;

static const uint64_t P9N2_PERV_EP01_FIR_MASK                                      = 0x11040002ull;

static const uint64_t P9N2_PERV_EP02_FIR_MASK                                      = 0x12040002ull;

static const uint64_t P9N2_PERV_EP03_FIR_MASK                                      = 0x13040002ull;

static const uint64_t P9N2_PERV_EP04_FIR_MASK                                      = 0x14040002ull;

static const uint64_t P9N2_PERV_EP05_FIR_MASK                                      = 0x15040002ull;

static const uint64_t P9N2_PERV_EC00_FIR_MASK                                      = 0x20040002ull;

static const uint64_t P9N2_PERV_EC01_FIR_MASK                                      = 0x21040002ull;

static const uint64_t P9N2_PERV_EC02_FIR_MASK                                      = 0x22040002ull;

static const uint64_t P9N2_PERV_EC03_FIR_MASK                                      = 0x23040002ull;

static const uint64_t P9N2_PERV_EC04_FIR_MASK                                      = 0x24040002ull;

static const uint64_t P9N2_PERV_EC05_FIR_MASK                                      = 0x25040002ull;

static const uint64_t P9N2_PERV_EC06_FIR_MASK                                      = 0x26040002ull;

static const uint64_t P9N2_PERV_EC07_FIR_MASK                                      = 0x27040002ull;

static const uint64_t P9N2_PERV_EC08_FIR_MASK                                      = 0x28040002ull;

static const uint64_t P9N2_PERV_EC09_FIR_MASK                                      = 0x29040002ull;

static const uint64_t P9N2_PERV_EC10_FIR_MASK                                      = 0x2A040002ull;

static const uint64_t P9N2_PERV_EC11_FIR_MASK                                      = 0x2B040002ull;

static const uint64_t P9N2_PERV_EC12_FIR_MASK                                      = 0x2C040002ull;

static const uint64_t P9N2_PERV_EC13_FIR_MASK                                      = 0x2D040002ull;

static const uint64_t P9N2_PERV_EC14_FIR_MASK                                      = 0x2E040002ull;

static const uint64_t P9N2_PERV_EC15_FIR_MASK                                      = 0x2F040002ull;

static const uint64_t P9N2_PERV_EC16_FIR_MASK                                      = 0x30040002ull;

static const uint64_t P9N2_PERV_EC17_FIR_MASK                                      = 0x31040002ull;

static const uint64_t P9N2_PERV_EC18_FIR_MASK                                      = 0x32040002ull;

static const uint64_t P9N2_PERV_EC19_FIR_MASK                                      = 0x33040002ull;

static const uint64_t P9N2_PERV_EC20_FIR_MASK                                      = 0x34040002ull;

static const uint64_t P9N2_PERV_EC21_FIR_MASK                                      = 0x35040002ull;

static const uint64_t P9N2_PERV_EC22_FIR_MASK                                      = 0x36040002ull;

static const uint64_t P9N2_PERV_EC23_FIR_MASK                                      = 0x37040002ull;


static const uint64_t P9N2_PERV_FMU_FORCE_OP_REG                                   = 0x00020003ull;

static const uint64_t P9N2_PERV_TP_FMU_FORCE_OP_REG                                = 0x01020003ull;


static const uint64_t P9N2_PERV_FMU_KVREF_DATAREG                                  = 0x00020004ull;

static const uint64_t P9N2_PERV_TP_FMU_KVREF_DATAREG                               = 0x01020004ull;


static const uint64_t P9N2_PERV_FMU_MODE_REG                                       = 0x00020000ull;

static const uint64_t P9N2_PERV_TP_FMU_MODE_REG                                    = 0x01020000ull;


static const uint64_t P9N2_PERV_FMU_OSC_CNTR1_REG                                  = 0x00020001ull;

static const uint64_t P9N2_PERV_TP_FMU_OSC_CNTR1_REG                               = 0x01020001ull;


static const uint64_t P9N2_PERV_FMU_OSC_CNTR2_REG                                  = 0x00020002ull;

static const uint64_t P9N2_PERV_TP_FMU_OSC_CNTR2_REG                               = 0x01020002ull;


static const uint64_t P9N2_PERV_FMU_PULSE_GEN_REG                                  = 0x00020001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_FMU_PULSE_GEN_REG                               = 0x01020001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PERV_FMU_VMEAS_MAX_RESULT                               = 0x00020008ull;

static const uint64_t P9N2_PERV_TP_FMU_VMEAS_MAX_RESULT                            = 0x01020008ull;


static const uint64_t P9N2_PERV_FMU_VMEAS_MIN_RESULT                               = 0x00020009ull;

static const uint64_t P9N2_PERV_TP_FMU_VMEAS_MIN_RESULT                            = 0x01020009ull;


static const uint32_t P9N2_PERV_FSISHIFT_FRONT_END_LENGTH_REGISTER_FSI             = 0x00000C02ull;

static const uint32_t P9N2_PERV_FSISHIFT_FRONT_END_LENGTH_REGISTER_FSI_BYTE        = 0x00000C08ull;


static const uint32_t P9N2_PERV_FSB_FSB_DNFIFO_DATA_OUT_FSI                        = 0x00002410ull;

static const uint32_t P9N2_PERV_FSB_FSB_DNFIFO_DATA_OUT_FSI_BYTE                   = 0x00002440ull;


static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_ACK_EOT_FSI                       = 0x00002415ull;

static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_ACK_EOT_FSI_BYTE                  = 0x00002454ull;


static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_MTC_FSI                           = 0x00002416ull;

static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_MTC_FSI_BYTE                      = 0x00002458ull;


static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_RESET_FSI                         = 0x00002414ull;

static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_RESET_FSI_BYTE                    = 0x00002450ull;


static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_STATUS_FSI                        = 0x00002411ull;

static const uint32_t P9N2_PERV_FSB_FSB_DOWNFIFO_STATUS_FSI_BYTE                   = 0x00002444ull;


static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_DATA_IN_FSI                         = 0x00002400ull;


static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_REQ_RESET_FSI                       = 0x00002403ull;

static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_REQ_RESET_FSI_BYTE                  = 0x0000240Cull;


static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_SIG_EOT_FSI                         = 0x00002402ull;

static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_SIG_EOT_FSI_BYTE                    = 0x00002408ull;


static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_STATUS_FSI                          = 0x00002401ull;

static const uint32_t P9N2_PERV_FSB_FSB_UPFIFO_STATUS_FSI_BYTE                     = 0x00002404ull;


static const uint32_t P9N2_PERV_FSISCRPD1_FSI                                      = 0x00001401ull;

static const uint32_t P9N2_PERV_FSISCRPD1_FSI_BYTE                                 = 0x00001404ull;


static const uint32_t P9N2_PERV_FSISCRPD2_FSI                                      = 0x00001402ull;

static const uint32_t P9N2_PERV_FSISCRPD2_FSI_BYTE                                 = 0x00001408ull;


static const uint32_t P9N2_PERV_FSISCRPD3_FSI                                      = 0x00001403ull;

static const uint32_t P9N2_PERV_FSISCRPD3_FSI_BYTE                                 = 0x0000140Cull;


static const uint32_t P9N2_PERV_FSI_A_LLMOD_FSI0                                   = 0x00000900ull;


static const uint32_t P9N2_PERV_FSI_A_LLSTAT_FSI0                                  = 0x00000904ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAEB_FSI0                              = 0x00003070ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAEB                          = 0x00000C1Cull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP0_FSI0                            = 0x00003050ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP0                        = 0x00000C14ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP1_FSI0                            = 0x00003054ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP1                        = 0x00000C15ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP2_FSI0                            = 0x00003058ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP2                        = 0x00000C16ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP3_FSI0                            = 0x0000305Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP3                        = 0x00000C17ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP4_FSI0                            = 0x00003060ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP4                        = 0x00000C18ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP5_FSI0                            = 0x00003064ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP5                        = 0x00000C19ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP6_FSI0                            = 0x00003068ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP6                        = 0x00000C1Aull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MAESP7_FSI0                            = 0x0000306Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MAESP7                        = 0x00000C1Bull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MATRB0_FSI0                            = 0x000031D8ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MATRB0                        = 0x00000C76ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MCENP0_FSI0                            = 0x00003020ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MCENP0                        = 0x00000C08ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MCRSP0_FSI0                            = 0x00003008ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MCRSP0                        = 0x00000C02ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MCRSP1_FSI0                            = 0x0000300Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MCRSP1                        = 0x00000C03ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MCSIEP0_FSI0                           = 0x00003070ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MCSIEP0                       = 0x00000C1Cull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MDLYR_FSI0                             = 0x00003004ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MDLYR                         = 0x00000C01ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MDTRB0_FSI0                            = 0x000031DCull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MDTRB0                        = 0x00000C77ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MECTRL_FSI0                            = 0x000032E0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MECTRL                        = 0x00000CB8ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MENP0_FSI0                             = 0x00003010ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MENP0                         = 0x00000C04ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MENP1_FSI0                             = 0x00003014ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MENP1                         = 0x00000C05ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MESRB0_FSI0                            = 0x000031D0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MESRB0                        = 0x00000C74ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MLEVP0_FSI0                            = 0x00003018ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MLEVP0                        = 0x00000C06ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MLEVP1_FSI0                            = 0x0000301Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MLEVP1                        = 0x00000C07ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MMODE_FSI0                             = 0x00003000ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MMODE                         = 0x00000C00ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MREFP0_FSI0                            = 0x00003020ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MREFP0                        = 0x00000C08ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MREFP1_FSI0                            = 0x00003024ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MREFP1                        = 0x00000C09ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESB0_FSI0                            = 0x000031D0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESB0                        = 0x00000C74ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP0_FSI0                            = 0x000030D0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP0                        = 0x00000C34ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP1_FSI0                            = 0x000030D4ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP1                        = 0x00000C35ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP2_FSI0                            = 0x000030D8ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP2                        = 0x00000C36ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP3_FSI0                            = 0x000030DCull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP3                        = 0x00000C37ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP4_FSI0                            = 0x000030E0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP4                        = 0x00000C38ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP5_FSI0                            = 0x000030E4ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP5                        = 0x00000C39ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP6_FSI0                            = 0x000030E8ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP6                        = 0x00000C3Aull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MRESP7_FSI0                            = 0x000030ECull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MRESP7                        = 0x00000C3Bull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSCSB0_FSI0                            = 0x000031D4ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSCSB0                        = 0x00000C75ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSENP0_FSI0                            = 0x00003018ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSENP0                        = 0x00000C06ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP0_FSI0                            = 0x00003030ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP0                        = 0x00000C0Cull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP1_FSI0                            = 0x00003034ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP1                        = 0x00000C0Dull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP2_FSI0                            = 0x00003038ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP2                        = 0x00000C0Eull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP3_FSI0                            = 0x0000303Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP3                        = 0x00000C0Full;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP4_FSI0                            = 0x00003040ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP4                        = 0x00000C10ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP5_FSI0                            = 0x00003044ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP5                        = 0x00000C11ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP6_FSI0                            = 0x00003048ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP6                        = 0x00000C12ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSIEP7_FSI0                            = 0x0000304Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSIEP7                        = 0x00000C13ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSSIEP0_FSI0                           = 0x00003050ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSSIEP0                       = 0x00000C14ull;


static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP0_FSI0                            = 0x000030D0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP0                        = 0x00000C34ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP1_FSI0                            = 0x000030D4ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP1                        = 0x00000C35ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP2_FSI0                            = 0x000030D8ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP2                        = 0x00000C36ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP3_FSI0                            = 0x000030DCull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP3                        = 0x00000C37ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP4_FSI0                            = 0x000030E0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP4                        = 0x00000C38ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP5_FSI0                            = 0x000030E4ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP5                        = 0x00000C39ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP6_FSI0                            = 0x000030E8ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP6                        = 0x00000C3Aull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MSTAP7_FSI0                            = 0x000030ECull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MSTAP7                        = 0x00000C3Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_0_MVER_FSI0                              = 0x00003074ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_A_MST_0_MVER                          = 0x00000C1Dull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAEB_FSI0                              = 0x00003470ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAEB_SCOMFSI0                          = 0x00000D1Cull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP0_FSI0                            = 0x00003450ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP0_SCOMFSI0                        = 0x00000D14ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP1_FSI0                            = 0x00003454ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP1_SCOMFSI0                        = 0x00000D15ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP2_FSI0                            = 0x00003458ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP2_SCOMFSI0                        = 0x00000D16ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP3_FSI0                            = 0x0000345Cull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP3_SCOMFSI0                        = 0x00000D17ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP4_FSI0                            = 0x00003460ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP4_SCOMFSI0                        = 0x00000D18ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP5_FSI0                            = 0x00003464ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP5_SCOMFSI0                        = 0x00000D19ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP6_FSI0                            = 0x00003468ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP6_SCOMFSI0                        = 0x00000D1Aull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP7_FSI0                            = 0x0000346Cull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MAESP7_SCOMFSI0                        = 0x00000D1Bull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MATRB0_FSI0                            = 0x000035D8ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MATRB0_SCOMFSI0                        = 0x00000D76ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MCENP0_FSI0                            = 0x00003420ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MCENP0_SCOMFSI0                        = 0x00000D08ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MCRSP0_FSI0                            = 0x00003408ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MCRSP0_SCOMFSI0                        = 0x00000D02ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MCRSP1_FSI0                            = 0x0000340Cull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MCRSP1_SCOMFSI0                        = 0x00000D03ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MCSIEP0_FSI0                           = 0x00003470ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MCSIEP0_SCOMFSI0                       = 0x00000D1Cull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MDLYR_FSI0                             = 0x00003404ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MDLYR_SCOMFSI0                         = 0x00000D01ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MDTRB0_FSI0                            = 0x000035DCull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MDTRB0_SCOMFSI0                        = 0x00000D77ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MECTRL_FSI0                            = 0x000036E0ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MECTRL_SCOMFSI0                        = 0x00000DB8ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MENP0_FSI0                             = 0x00003410ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MENP0_SCOMFSI0                         = 0x00000D04ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MENP1_FSI0                             = 0x00003414ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MENP1_SCOMFSI0                         = 0x00000D05ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MESRB0_FSI0                            = 0x000035D0ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MESRB0_SCOMFSI0                        = 0x00000D74ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MLEVP0_FSI0                            = 0x00003418ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MLEVP0_SCOMFSI0                        = 0x00000D06ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MLEVP1_FSI0                            = 0x0000341Cull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MLEVP1_SCOMFSI0                        = 0x00000D07ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MMODE_FSI0                             = 0x00003400ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MMODE_SCOMFSI0                         = 0x00000D00ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MREFP0_FSI0                            = 0x00003420ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MREFP0_SCOMFSI0                        = 0x00000D08ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MREFP1_FSI0                            = 0x00003424ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MREFP1_SCOMFSI0                        = 0x00000D09ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESB0_FSI0                            = 0x000035D0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESB0_SCOMFSI0                        = 0x00000D74ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP0_FSI0                            = 0x000034D0ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP0_SCOMFSI0                        = 0x00000D34ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP1_FSI0                            = 0x000034D4ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP1_SCOMFSI0                        = 0x00000D35ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP2_FSI0                            = 0x000034D8ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP2_SCOMFSI0                        = 0x00000D36ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP3_FSI0                            = 0x000034DCull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP3_SCOMFSI0                        = 0x00000D37ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP4_FSI0                            = 0x000034E0ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP4_SCOMFSI0                        = 0x00000D38ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP5_FSI0                            = 0x000034E4ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP5_SCOMFSI0                        = 0x00000D39ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP6_FSI0                            = 0x000034E8ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP6_SCOMFSI0                        = 0x00000D3Aull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP7_FSI0                            = 0x000034ECull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MRESP7_SCOMFSI0                        = 0x00000D3Bull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSCSB0_FSI0                            = 0x000035D4ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSCSB0_SCOMFSI0                        = 0x00000D75ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSENP0_FSI0                            = 0x00003418ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSENP0_SCOMFSI0                        = 0x00000D06ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP0_FSI0                            = 0x00003430ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP0_SCOMFSI0                        = 0x00000D0Cull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP1_FSI0                            = 0x00003434ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP1_SCOMFSI0                        = 0x00000D0Dull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP2_FSI0                            = 0x00003438ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP2_SCOMFSI0                        = 0x00000D0Eull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP3_FSI0                            = 0x0000343Cull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP3_SCOMFSI0                        = 0x00000D0Full;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP4_FSI0                            = 0x00003440ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP4_SCOMFSI0                        = 0x00000D10ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP5_FSI0                            = 0x00003444ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP5_SCOMFSI0                        = 0x00000D11ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP6_FSI0                            = 0x00003448ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP6_SCOMFSI0                        = 0x00000D12ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP7_FSI0                            = 0x0000344Cull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSIEP7_SCOMFSI0                        = 0x00000D13ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSSIEP0_FSI0                           = 0x00003450ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSSIEP0_SCOMFSI0                       = 0x00000D14ull;


static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP0_FSI0                            = 0x000034D0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP0_SCOMFSI0                        = 0x00000D34ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP1_FSI0                            = 0x000034D4ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP1_SCOMFSI0                        = 0x00000D35ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP2_FSI0                            = 0x000034D8ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP2_SCOMFSI0                        = 0x00000D36ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP3_FSI0                            = 0x000034DCull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP3_SCOMFSI0                        = 0x00000D37ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP4_FSI0                            = 0x000034E0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP4_SCOMFSI0                        = 0x00000D38ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP5_FSI0                            = 0x000034E4ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP5_SCOMFSI0                        = 0x00000D39ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP6_FSI0                            = 0x000034E8ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP6_SCOMFSI0                        = 0x00000D3Aull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP7_FSI0                            = 0x000034ECull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI_A_MST_1_MSTAP7_SCOMFSI0                        = 0x00000D3Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_MST_1_MVER_FSI0                              = 0x00003474ull;

static const uint32_t P9N2_PERV_FSI_A_MST_1_MVER_SCOMFSI0                          = 0x00000D1Dull;


static const uint32_t P9N2_PERV_FSI_A_SCI1M_FSI0                                   = 0x00000820ull;


static const uint32_t P9N2_PERV_FSI_A_SCI2CM_FSI0                                  = 0x0000082Cull;


static const uint32_t P9N2_PERV_FSI_A_SCISC_FSI0                                   = 0x00000808ull;


static const uint32_t P9N2_PERV_FSI_A_SCISM_FSI0                                   = 0x00000814ull;


static const uint32_t P9N2_PERV_FSI_A_SCMBL_FSI0                                   = 0x00000840ull;


static const uint32_t P9N2_PERV_FSI_A_SCMBR_FSI0                                   = 0x0000084Cull;


static const uint32_t P9N2_PERV_FSI_A_SCMDT_FSI0                                   = 0x0000082Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SCRSIC0_FSI0                                 = 0x00000850ull;


static const uint32_t P9N2_PERV_FSI_A_SCRSIC4_FSI0                                 = 0x00000854ull;


static const uint32_t P9N2_PERV_FSI_A_SCRSIM0_FSI0                                 = 0x00000858ull;


static const uint32_t P9N2_PERV_FSI_A_SCRSIM4_FSI0                                 = 0x0000085Cull;


static const uint32_t P9N2_PERV_FSI_A_SCRSIS0_FSI0                                 = 0x00000860ull;


static const uint32_t P9N2_PERV_FSI_A_SCRSIS4_FSI0                                 = 0x00000864ull;


static const uint32_t P9N2_PERV_FSI_A_SDATA_FSI0                                   = 0x00000830ull;


static const uint32_t P9N2_PERV_FSI_A_SDMA_FSI0                                    = 0x00000804ull;


static const uint32_t P9N2_PERV_FSI_A_SI1M_FSI0                                    = 0x00000818ull;


static const uint32_t P9N2_PERV_FSI_A_SI1S_FSI0                                    = 0x0000081Cull;


static const uint32_t P9N2_PERV_FSI_A_SI2M_FSI0                                    = 0x00000824ull;


static const uint32_t P9N2_PERV_FSI_A_SI2S_FSI0                                    = 0x00000828ull;


static const uint32_t P9N2_PERV_FSI_A_SIC_FSI0                                     = 0x00000820ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SISC_FSI0                                    = 0x00000808ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SISM_FSI0                                    = 0x0000080Cull;


static const uint32_t P9N2_PERV_FSI_A_SISS_FSI0                                    = 0x00000810ull;


static const uint32_t P9N2_PERV_FSI_A_SLASTD_SRES_FSI0                             = 0x00000834ull;


static const uint32_t P9N2_PERV_FSI_A_SLBUS_FSI0                                   = 0x00000830ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SMBL_FSI0                                    = 0x00000838ull;


static const uint32_t P9N2_PERV_FSI_A_SMBR_FSI0                                    = 0x00000844ull;


static const uint32_t P9N2_PERV_FSI_A_SMODE_FSI0                                   = 0x00000800ull;


static const uint32_t P9N2_PERV_FSI_A_SNML_FSI0                                    = 0x00000840ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SNMR_FSI0                                    = 0x0000084Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SOML_FSI0                                    = 0x0000083Cull;


static const uint32_t P9N2_PERV_FSI_A_SOMR_FSI0                                    = 0x00000848ull;


static const uint32_t P9N2_PERV_FSI_A_SRSIC0_FSI0                                  = 0x00000868ull;


static const uint32_t P9N2_PERV_FSI_A_SRSIC4_FSI0                                  = 0x0000086Cull;


static const uint32_t P9N2_PERV_FSI_A_SRSIM0_FSI0                                  = 0x00000870ull;


static const uint32_t P9N2_PERV_FSI_A_SRSIM4_FSI0                                  = 0x00000874ull;


static const uint32_t P9N2_PERV_FSI_A_SRSIS0_FSI0                                  = 0x00000878ull;


static const uint32_t P9N2_PERV_FSI_A_SRSIS4_FSI0                                  = 0x0000087Cull;


static const uint32_t P9N2_PERV_FSI_A_SSI1M_FSI0                                   = 0x0000081Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SSI2M_FSI0                                   = 0x00000828ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SSISM_FSI0                                   = 0x00000810ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SSMBL_FSI0                                   = 0x0000083Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SSMBR_FSI0                                   = 0x00000848ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_A_SSTAT_FSI0                                   = 0x00000814ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_LLMOD_FSI1                                   = 0x00000900ull;


static const uint32_t P9N2_PERV_FSI_B_LLSTAT_FSI1                                  = 0x00000904ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAEB_FSI1                              = 0x00003070ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAEB                          = 0x00000C1Cull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP0_FSI1                            = 0x00003050ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP0                        = 0x00000C14ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP1_FSI1                            = 0x00003054ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP1                        = 0x00000C15ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP2_FSI1                            = 0x00003058ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP2                        = 0x00000C16ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP3_FSI1                            = 0x0000305Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP3                        = 0x00000C17ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP4_FSI1                            = 0x00003060ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP4                        = 0x00000C18ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP5_FSI1                            = 0x00003064ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP5                        = 0x00000C19ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP6_FSI1                            = 0x00003068ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP6                        = 0x00000C1Aull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MAESP7_FSI1                            = 0x0000306Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MAESP7                        = 0x00000C1Bull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MATRB0_FSI1                            = 0x000031D8ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MATRB0                        = 0x00000C76ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MCENP0_FSI1                            = 0x00003020ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MCENP0                        = 0x00000C08ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MCRSP0_FSI1                            = 0x00003008ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MCRSP0                        = 0x00000C02ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MCRSP1_FSI1                            = 0x0000300Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MCRSP1                        = 0x00000C03ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MCSIEP0_FSI1                           = 0x00003070ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MCSIEP0                       = 0x00000C1Cull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MDLYR_FSI1                             = 0x00003004ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MDLYR                         = 0x00000C01ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MDTRB0_FSI1                            = 0x000031DCull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MDTRB0                        = 0x00000C77ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MECTRL_FSI1                            = 0x000032E0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MECTRL                        = 0x00000CB8ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MENP0_FSI1                             = 0x00003010ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MENP0                         = 0x00000C04ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MENP1_FSI1                             = 0x00003014ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MENP1                         = 0x00000C05ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MESRB0_FSI1                            = 0x000031D0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MESRB0                        = 0x00000C74ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MLEVP0_FSI1                            = 0x00003018ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MLEVP0                        = 0x00000C06ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MLEVP1_FSI1                            = 0x0000301Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MLEVP1                        = 0x00000C07ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MMODE_FSI1                             = 0x00003000ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MMODE                         = 0x00000C00ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MREFP0_FSI1                            = 0x00003020ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MREFP0                        = 0x00000C08ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MREFP1_FSI1                            = 0x00003024ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MREFP1                        = 0x00000C09ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESB0_FSI1                            = 0x000031D0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESB0                        = 0x00000C74ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP0_FSI1                            = 0x000030D0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP0                        = 0x00000C34ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP1_FSI1                            = 0x000030D4ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP1                        = 0x00000C35ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP2_FSI1                            = 0x000030D8ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP2                        = 0x00000C36ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP3_FSI1                            = 0x000030DCull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP3                        = 0x00000C37ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP4_FSI1                            = 0x000030E0ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP4                        = 0x00000C38ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP5_FSI1                            = 0x000030E4ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP5                        = 0x00000C39ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP6_FSI1                            = 0x000030E8ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP6                        = 0x00000C3Aull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MRESP7_FSI1                            = 0x000030ECull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MRESP7                        = 0x00000C3Bull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSCSB0_FSI1                            = 0x000031D4ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSCSB0                        = 0x00000C75ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSENP0_FSI1                            = 0x00003018ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSENP0                        = 0x00000C06ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP0_FSI1                            = 0x00003030ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP0                        = 0x00000C0Cull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP1_FSI1                            = 0x00003034ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP1                        = 0x00000C0Dull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP2_FSI1                            = 0x00003038ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP2                        = 0x00000C0Eull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP3_FSI1                            = 0x0000303Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP3                        = 0x00000C0Full;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP4_FSI1                            = 0x00003040ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP4                        = 0x00000C10ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP5_FSI1                            = 0x00003044ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP5                        = 0x00000C11ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP6_FSI1                            = 0x00003048ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP6                        = 0x00000C12ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSIEP7_FSI1                            = 0x0000304Cull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSIEP7                        = 0x00000C13ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSSIEP0_FSI1                           = 0x00003050ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSSIEP0                       = 0x00000C14ull;


static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP0_FSI1                            = 0x000030D0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP0                        = 0x00000C34ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP1_FSI1                            = 0x000030D4ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP1                        = 0x00000C35ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP2_FSI1                            = 0x000030D8ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP2                        = 0x00000C36ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP3_FSI1                            = 0x000030DCull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP3                        = 0x00000C37ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP4_FSI1                            = 0x000030E0ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP4                        = 0x00000C38ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP5_FSI1                            = 0x000030E4ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP5                        = 0x00000C39ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP6_FSI1                            = 0x000030E8ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP6                        = 0x00000C3Aull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MSTAP7_FSI1                            = 0x000030ECull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MSTAP7                        = 0x00000C3Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_MST_0_MVER_FSI1                              = 0x00003074ull;

static const uint32_t P9N2_PERV_FSISHIFT_FSI_B_MST_0_MVER                          = 0x00000C1Dull;


static const uint32_t P9N2_PERV_FSI_B_SCI1M_FSI1                                   = 0x00000820ull;


static const uint32_t P9N2_PERV_FSI_B_SCI2CM_FSI1                                  = 0x0000082Cull;


static const uint32_t P9N2_PERV_FSI_B_SCISC_FSI1                                   = 0x00000808ull;


static const uint32_t P9N2_PERV_FSI_B_SCISM_FSI1                                   = 0x00000814ull;


static const uint32_t P9N2_PERV_FSI_B_SCMBL_FSI1                                   = 0x00000840ull;


static const uint32_t P9N2_PERV_FSI_B_SCMBR_FSI1                                   = 0x0000084Cull;


static const uint32_t P9N2_PERV_FSI_B_SCMDT_FSI1                                   = 0x0000082Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SCRSIC0_FSI1                                 = 0x00000850ull;


static const uint32_t P9N2_PERV_FSI_B_SCRSIC4_FSI1                                 = 0x00000854ull;


static const uint32_t P9N2_PERV_FSI_B_SCRSIM0_FSI1                                 = 0x00000858ull;


static const uint32_t P9N2_PERV_FSI_B_SCRSIM4_FSI1                                 = 0x0000085Cull;


static const uint32_t P9N2_PERV_FSI_B_SCRSIS0_FSI1                                 = 0x00000860ull;


static const uint32_t P9N2_PERV_FSI_B_SCRSIS4_FSI1                                 = 0x00000864ull;


static const uint32_t P9N2_PERV_FSI_B_SDATA_FSI1                                   = 0x00000830ull;


static const uint32_t P9N2_PERV_FSI_B_SDMA_FSI1                                    = 0x00000804ull;


static const uint32_t P9N2_PERV_FSI_B_SI1M_FSI1                                    = 0x00000818ull;


static const uint32_t P9N2_PERV_FSI_B_SI1S_FSI1                                    = 0x0000081Cull;


static const uint32_t P9N2_PERV_FSI_B_SI2M_FSI1                                    = 0x00000824ull;


static const uint32_t P9N2_PERV_FSI_B_SI2S_FSI1                                    = 0x00000828ull;


static const uint32_t P9N2_PERV_FSI_B_SIC_FSI1                                     = 0x00000820ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SISC_FSI1                                    = 0x00000808ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SISM_FSI1                                    = 0x0000080Cull;


static const uint32_t P9N2_PERV_FSI_B_SISS_FSI1                                    = 0x00000810ull;


static const uint32_t P9N2_PERV_FSI_B_SLASTD_SRES_FSI1                             = 0x00000834ull;


static const uint32_t P9N2_PERV_FSI_B_SLBUS_FSI1                                   = 0x00000830ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SMBL_FSI1                                    = 0x00000838ull;


static const uint32_t P9N2_PERV_FSI_B_SMBR_FSI1                                    = 0x00000844ull;


static const uint32_t P9N2_PERV_FSI_B_SMODE_FSI1                                   = 0x00000800ull;


static const uint32_t P9N2_PERV_FSI_B_SNML_FSI1                                    = 0x00000840ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SNMR_FSI1                                    = 0x0000084Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SOML_FSI1                                    = 0x0000083Cull;


static const uint32_t P9N2_PERV_FSI_B_SOMR_FSI1                                    = 0x00000848ull;


static const uint32_t P9N2_PERV_FSI_B_SRSIC0_FSI1                                  = 0x00000868ull;


static const uint32_t P9N2_PERV_FSI_B_SRSIC4_FSI1                                  = 0x0000086Cull;


static const uint32_t P9N2_PERV_FSI_B_SRSIM0_FSI1                                  = 0x00000870ull;


static const uint32_t P9N2_PERV_FSI_B_SRSIM4_FSI1                                  = 0x00000874ull;


static const uint32_t P9N2_PERV_FSI_B_SRSIS0_FSI1                                  = 0x00000878ull;


static const uint32_t P9N2_PERV_FSI_B_SRSIS4_FSI1                                  = 0x0000087Cull;


static const uint32_t P9N2_PERV_FSI_B_SSI1M_FSI1                                   = 0x0000081Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SSI2M_FSI1                                   = 0x00000828ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SSISM_FSI1                                   = 0x00000810ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SSMBL_FSI1                                   = 0x0000083Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SSMBR_FSI1                                   = 0x00000848ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_FSI_B_SSTAT_FSI1                                   = 0x00000814ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint32_t P9N2_PERV_GPWRP_FSI                                          = 0x0000281Full;

static const uint32_t P9N2_PERV_GPWRP_FSI_BYTE                                     = 0x0000287Cull;

static const uint64_t P9N2_PERV_GPWRP_SCOM                                         = 0x0005001Full;

static const uint64_t P9N2_PERV_PIB_GPWRP                                          = 0x0005001Full;


static const uint64_t P9N2_PERV_GXSTOP0_MASK_REG                                   = 0x00040014ull;

static const uint64_t P9N2_PERV_TP_GXSTOP0_MASK_REG                                = 0x01040014ull;

static const uint64_t P9N2_PERV_N0_GXSTOP0_MASK_REG                                = 0x02040014ull;

static const uint64_t P9N2_PERV_N1_GXSTOP0_MASK_REG                                = 0x03040014ull;

static const uint64_t P9N2_PERV_N2_GXSTOP0_MASK_REG                                = 0x04040014ull;

static const uint64_t P9N2_PERV_N3_GXSTOP0_MASK_REG                                = 0x05040014ull;

static const uint64_t P9N2_PERV_XB_GXSTOP0_MASK_REG                                = 0x06040014ull;

static const uint64_t P9N2_PERV_MC01_GXSTOP0_MASK_REG                              = 0x07040014ull;

static const uint64_t P9N2_PERV_MC23_GXSTOP0_MASK_REG                              = 0x08040014ull;

static const uint64_t P9N2_PERV_OB0_GXSTOP0_MASK_REG                               = 0x09040014ull;

static const uint64_t P9N2_PERV_OB3_GXSTOP0_MASK_REG                               = 0x0C040014ull;

static const uint64_t P9N2_PERV_PCI0_GXSTOP0_MASK_REG                              = 0x0D040014ull;

static const uint64_t P9N2_PERV_PCI1_GXSTOP0_MASK_REG                              = 0x0E040014ull;

static const uint64_t P9N2_PERV_PCI2_GXSTOP0_MASK_REG                              = 0x0F040014ull;

static const uint64_t P9N2_PERV_EP00_GXSTOP0_MASK_REG                              = 0x10040014ull;

static const uint64_t P9N2_PERV_EP01_GXSTOP0_MASK_REG                              = 0x11040014ull;

static const uint64_t P9N2_PERV_EP02_GXSTOP0_MASK_REG                              = 0x12040014ull;

static const uint64_t P9N2_PERV_EP03_GXSTOP0_MASK_REG                              = 0x13040014ull;

static const uint64_t P9N2_PERV_EP04_GXSTOP0_MASK_REG                              = 0x14040014ull;

static const uint64_t P9N2_PERV_EP05_GXSTOP0_MASK_REG                              = 0x15040014ull;

static const uint64_t P9N2_PERV_EC00_GXSTOP0_MASK_REG                              = 0x20040014ull;

static const uint64_t P9N2_PERV_EC01_GXSTOP0_MASK_REG                              = 0x21040014ull;

static const uint64_t P9N2_PERV_EC02_GXSTOP0_MASK_REG                              = 0x22040014ull;

static const uint64_t P9N2_PERV_EC03_GXSTOP0_MASK_REG                              = 0x23040014ull;

static const uint64_t P9N2_PERV_EC04_GXSTOP0_MASK_REG                              = 0x24040014ull;

static const uint64_t P9N2_PERV_EC05_GXSTOP0_MASK_REG                              = 0x25040014ull;

static const uint64_t P9N2_PERV_EC06_GXSTOP0_MASK_REG                              = 0x26040014ull;

static const uint64_t P9N2_PERV_EC07_GXSTOP0_MASK_REG                              = 0x27040014ull;

static const uint64_t P9N2_PERV_EC08_GXSTOP0_MASK_REG                              = 0x28040014ull;

static const uint64_t P9N2_PERV_EC09_GXSTOP0_MASK_REG                              = 0x29040014ull;

static const uint64_t P9N2_PERV_EC10_GXSTOP0_MASK_REG                              = 0x2A040014ull;

static const uint64_t P9N2_PERV_EC11_GXSTOP0_MASK_REG                              = 0x2B040014ull;

static const uint64_t P9N2_PERV_EC12_GXSTOP0_MASK_REG                              = 0x2C040014ull;

static const uint64_t P9N2_PERV_EC13_GXSTOP0_MASK_REG                              = 0x2D040014ull;

static const uint64_t P9N2_PERV_EC14_GXSTOP0_MASK_REG                              = 0x2E040014ull;

static const uint64_t P9N2_PERV_EC15_GXSTOP0_MASK_REG                              = 0x2F040014ull;

static const uint64_t P9N2_PERV_EC16_GXSTOP0_MASK_REG                              = 0x30040014ull;

static const uint64_t P9N2_PERV_EC17_GXSTOP0_MASK_REG                              = 0x31040014ull;

static const uint64_t P9N2_PERV_EC18_GXSTOP0_MASK_REG                              = 0x32040014ull;

static const uint64_t P9N2_PERV_EC19_GXSTOP0_MASK_REG                              = 0x33040014ull;

static const uint64_t P9N2_PERV_EC20_GXSTOP0_MASK_REG                              = 0x34040014ull;

static const uint64_t P9N2_PERV_EC21_GXSTOP0_MASK_REG                              = 0x35040014ull;

static const uint64_t P9N2_PERV_EC22_GXSTOP0_MASK_REG                              = 0x36040014ull;

static const uint64_t P9N2_PERV_EC23_GXSTOP0_MASK_REG                              = 0x37040014ull;


static const uint64_t P9N2_PERV_GXSTOP1_MASK_REG                                   = 0x00040015ull;

static const uint64_t P9N2_PERV_TP_GXSTOP1_MASK_REG                                = 0x01040015ull;

static const uint64_t P9N2_PERV_N0_GXSTOP1_MASK_REG                                = 0x02040015ull;

static const uint64_t P9N2_PERV_N1_GXSTOP1_MASK_REG                                = 0x03040015ull;

static const uint64_t P9N2_PERV_N2_GXSTOP1_MASK_REG                                = 0x04040015ull;

static const uint64_t P9N2_PERV_N3_GXSTOP1_MASK_REG                                = 0x05040015ull;

static const uint64_t P9N2_PERV_XB_GXSTOP1_MASK_REG                                = 0x06040015ull;

static const uint64_t P9N2_PERV_MC01_GXSTOP1_MASK_REG                              = 0x07040015ull;

static const uint64_t P9N2_PERV_MC23_GXSTOP1_MASK_REG                              = 0x08040015ull;

static const uint64_t P9N2_PERV_OB0_GXSTOP1_MASK_REG                               = 0x09040015ull;

static const uint64_t P9N2_PERV_OB3_GXSTOP1_MASK_REG                               = 0x0C040015ull;

static const uint64_t P9N2_PERV_PCI0_GXSTOP1_MASK_REG                              = 0x0D040015ull;

static const uint64_t P9N2_PERV_PCI1_GXSTOP1_MASK_REG                              = 0x0E040015ull;

static const uint64_t P9N2_PERV_PCI2_GXSTOP1_MASK_REG                              = 0x0F040015ull;

static const uint64_t P9N2_PERV_EP00_GXSTOP1_MASK_REG                              = 0x10040015ull;

static const uint64_t P9N2_PERV_EP01_GXSTOP1_MASK_REG                              = 0x11040015ull;

static const uint64_t P9N2_PERV_EP02_GXSTOP1_MASK_REG                              = 0x12040015ull;

static const uint64_t P9N2_PERV_EP03_GXSTOP1_MASK_REG                              = 0x13040015ull;

static const uint64_t P9N2_PERV_EP04_GXSTOP1_MASK_REG                              = 0x14040015ull;

static const uint64_t P9N2_PERV_EP05_GXSTOP1_MASK_REG                              = 0x15040015ull;

static const uint64_t P9N2_PERV_EC00_GXSTOP1_MASK_REG                              = 0x20040015ull;

static const uint64_t P9N2_PERV_EC01_GXSTOP1_MASK_REG                              = 0x21040015ull;

static const uint64_t P9N2_PERV_EC02_GXSTOP1_MASK_REG                              = 0x22040015ull;

static const uint64_t P9N2_PERV_EC03_GXSTOP1_MASK_REG                              = 0x23040015ull;

static const uint64_t P9N2_PERV_EC04_GXSTOP1_MASK_REG                              = 0x24040015ull;

static const uint64_t P9N2_PERV_EC05_GXSTOP1_MASK_REG                              = 0x25040015ull;

static const uint64_t P9N2_PERV_EC06_GXSTOP1_MASK_REG                              = 0x26040015ull;

static const uint64_t P9N2_PERV_EC07_GXSTOP1_MASK_REG                              = 0x27040015ull;

static const uint64_t P9N2_PERV_EC08_GXSTOP1_MASK_REG                              = 0x28040015ull;

static const uint64_t P9N2_PERV_EC09_GXSTOP1_MASK_REG                              = 0x29040015ull;

static const uint64_t P9N2_PERV_EC10_GXSTOP1_MASK_REG                              = 0x2A040015ull;

static const uint64_t P9N2_PERV_EC11_GXSTOP1_MASK_REG                              = 0x2B040015ull;

static const uint64_t P9N2_PERV_EC12_GXSTOP1_MASK_REG                              = 0x2C040015ull;

static const uint64_t P9N2_PERV_EC13_GXSTOP1_MASK_REG                              = 0x2D040015ull;

static const uint64_t P9N2_PERV_EC14_GXSTOP1_MASK_REG                              = 0x2E040015ull;

static const uint64_t P9N2_PERV_EC15_GXSTOP1_MASK_REG                              = 0x2F040015ull;

static const uint64_t P9N2_PERV_EC16_GXSTOP1_MASK_REG                              = 0x30040015ull;

static const uint64_t P9N2_PERV_EC17_GXSTOP1_MASK_REG                              = 0x31040015ull;

static const uint64_t P9N2_PERV_EC18_GXSTOP1_MASK_REG                              = 0x32040015ull;

static const uint64_t P9N2_PERV_EC19_GXSTOP1_MASK_REG                              = 0x33040015ull;

static const uint64_t P9N2_PERV_EC20_GXSTOP1_MASK_REG                              = 0x34040015ull;

static const uint64_t P9N2_PERV_EC21_GXSTOP1_MASK_REG                              = 0x35040015ull;

static const uint64_t P9N2_PERV_EC22_GXSTOP1_MASK_REG                              = 0x36040015ull;

static const uint64_t P9N2_PERV_EC23_GXSTOP1_MASK_REG                              = 0x37040015ull;


static const uint64_t P9N2_PERV_GXSTOP2_MASK_REG                                   = 0x00040016ull;

static const uint64_t P9N2_PERV_TP_GXSTOP2_MASK_REG                                = 0x01040016ull;

static const uint64_t P9N2_PERV_N0_GXSTOP2_MASK_REG                                = 0x02040016ull;

static const uint64_t P9N2_PERV_N1_GXSTOP2_MASK_REG                                = 0x03040016ull;

static const uint64_t P9N2_PERV_N2_GXSTOP2_MASK_REG                                = 0x04040016ull;

static const uint64_t P9N2_PERV_N3_GXSTOP2_MASK_REG                                = 0x05040016ull;

static const uint64_t P9N2_PERV_XB_GXSTOP2_MASK_REG                                = 0x06040016ull;

static const uint64_t P9N2_PERV_MC01_GXSTOP2_MASK_REG                              = 0x07040016ull;

static const uint64_t P9N2_PERV_MC23_GXSTOP2_MASK_REG                              = 0x08040016ull;

static const uint64_t P9N2_PERV_OB0_GXSTOP2_MASK_REG                               = 0x09040016ull;

static const uint64_t P9N2_PERV_OB3_GXSTOP2_MASK_REG                               = 0x0C040016ull;

static const uint64_t P9N2_PERV_PCI0_GXSTOP2_MASK_REG                              = 0x0D040016ull;

static const uint64_t P9N2_PERV_PCI1_GXSTOP2_MASK_REG                              = 0x0E040016ull;

static const uint64_t P9N2_PERV_PCI2_GXSTOP2_MASK_REG                              = 0x0F040016ull;

static const uint64_t P9N2_PERV_EP00_GXSTOP2_MASK_REG                              = 0x10040016ull;

static const uint64_t P9N2_PERV_EP01_GXSTOP2_MASK_REG                              = 0x11040016ull;

static const uint64_t P9N2_PERV_EP02_GXSTOP2_MASK_REG                              = 0x12040016ull;

static const uint64_t P9N2_PERV_EP03_GXSTOP2_MASK_REG                              = 0x13040016ull;

static const uint64_t P9N2_PERV_EP04_GXSTOP2_MASK_REG                              = 0x14040016ull;

static const uint64_t P9N2_PERV_EP05_GXSTOP2_MASK_REG                              = 0x15040016ull;

static const uint64_t P9N2_PERV_EC00_GXSTOP2_MASK_REG                              = 0x20040016ull;

static const uint64_t P9N2_PERV_EC01_GXSTOP2_MASK_REG                              = 0x21040016ull;

static const uint64_t P9N2_PERV_EC02_GXSTOP2_MASK_REG                              = 0x22040016ull;

static const uint64_t P9N2_PERV_EC03_GXSTOP2_MASK_REG                              = 0x23040016ull;

static const uint64_t P9N2_PERV_EC04_GXSTOP2_MASK_REG                              = 0x24040016ull;

static const uint64_t P9N2_PERV_EC05_GXSTOP2_MASK_REG                              = 0x25040016ull;

static const uint64_t P9N2_PERV_EC06_GXSTOP2_MASK_REG                              = 0x26040016ull;

static const uint64_t P9N2_PERV_EC07_GXSTOP2_MASK_REG                              = 0x27040016ull;

static const uint64_t P9N2_PERV_EC08_GXSTOP2_MASK_REG                              = 0x28040016ull;

static const uint64_t P9N2_PERV_EC09_GXSTOP2_MASK_REG                              = 0x29040016ull;

static const uint64_t P9N2_PERV_EC10_GXSTOP2_MASK_REG                              = 0x2A040016ull;

static const uint64_t P9N2_PERV_EC11_GXSTOP2_MASK_REG                              = 0x2B040016ull;

static const uint64_t P9N2_PERV_EC12_GXSTOP2_MASK_REG                              = 0x2C040016ull;

static const uint64_t P9N2_PERV_EC13_GXSTOP2_MASK_REG                              = 0x2D040016ull;

static const uint64_t P9N2_PERV_EC14_GXSTOP2_MASK_REG                              = 0x2E040016ull;

static const uint64_t P9N2_PERV_EC15_GXSTOP2_MASK_REG                              = 0x2F040016ull;

static const uint64_t P9N2_PERV_EC16_GXSTOP2_MASK_REG                              = 0x30040016ull;

static const uint64_t P9N2_PERV_EC17_GXSTOP2_MASK_REG                              = 0x31040016ull;

static const uint64_t P9N2_PERV_EC18_GXSTOP2_MASK_REG                              = 0x32040016ull;

static const uint64_t P9N2_PERV_EC19_GXSTOP2_MASK_REG                              = 0x33040016ull;

static const uint64_t P9N2_PERV_EC20_GXSTOP2_MASK_REG                              = 0x34040016ull;

static const uint64_t P9N2_PERV_EC21_GXSTOP2_MASK_REG                              = 0x35040016ull;

static const uint64_t P9N2_PERV_EC22_GXSTOP2_MASK_REG                              = 0x36040016ull;

static const uint64_t P9N2_PERV_EC23_GXSTOP2_MASK_REG                              = 0x37040016ull;


static const uint64_t P9N2_PERV_GXSTOP_TRIG_REG                                    = 0x00040013ull;

static const uint64_t P9N2_PERV_TP_GXSTOP_TRIG_REG                                 = 0x01040013ull;

static const uint64_t P9N2_PERV_N0_GXSTOP_TRIG_REG                                 = 0x02040013ull;

static const uint64_t P9N2_PERV_N1_GXSTOP_TRIG_REG                                 = 0x03040013ull;

static const uint64_t P9N2_PERV_N2_GXSTOP_TRIG_REG                                 = 0x04040013ull;

static const uint64_t P9N2_PERV_N3_GXSTOP_TRIG_REG                                 = 0x05040013ull;

static const uint64_t P9N2_PERV_XB_GXSTOP_TRIG_REG                                 = 0x06040013ull;

static const uint64_t P9N2_PERV_MC01_GXSTOP_TRIG_REG                               = 0x07040013ull;

static const uint64_t P9N2_PERV_MC23_GXSTOP_TRIG_REG                               = 0x08040013ull;

static const uint64_t P9N2_PERV_OB0_GXSTOP_TRIG_REG                                = 0x09040013ull;

static const uint64_t P9N2_PERV_OB3_GXSTOP_TRIG_REG                                = 0x0C040013ull;

static const uint64_t P9N2_PERV_PCI0_GXSTOP_TRIG_REG                               = 0x0D040013ull;

static const uint64_t P9N2_PERV_PCI1_GXSTOP_TRIG_REG                               = 0x0E040013ull;

static const uint64_t P9N2_PERV_PCI2_GXSTOP_TRIG_REG                               = 0x0F040013ull;

static const uint64_t P9N2_PERV_EP00_GXSTOP_TRIG_REG                               = 0x10040013ull;

static const uint64_t P9N2_PERV_EP01_GXSTOP_TRIG_REG                               = 0x11040013ull;

static const uint64_t P9N2_PERV_EP02_GXSTOP_TRIG_REG                               = 0x12040013ull;

static const uint64_t P9N2_PERV_EP03_GXSTOP_TRIG_REG                               = 0x13040013ull;

static const uint64_t P9N2_PERV_EP04_GXSTOP_TRIG_REG                               = 0x14040013ull;

static const uint64_t P9N2_PERV_EP05_GXSTOP_TRIG_REG                               = 0x15040013ull;

static const uint64_t P9N2_PERV_EC00_GXSTOP_TRIG_REG                               = 0x20040013ull;

static const uint64_t P9N2_PERV_EC01_GXSTOP_TRIG_REG                               = 0x21040013ull;

static const uint64_t P9N2_PERV_EC02_GXSTOP_TRIG_REG                               = 0x22040013ull;

static const uint64_t P9N2_PERV_EC03_GXSTOP_TRIG_REG                               = 0x23040013ull;

static const uint64_t P9N2_PERV_EC04_GXSTOP_TRIG_REG                               = 0x24040013ull;

static const uint64_t P9N2_PERV_EC05_GXSTOP_TRIG_REG                               = 0x25040013ull;

static const uint64_t P9N2_PERV_EC06_GXSTOP_TRIG_REG                               = 0x26040013ull;

static const uint64_t P9N2_PERV_EC07_GXSTOP_TRIG_REG                               = 0x27040013ull;

static const uint64_t P9N2_PERV_EC08_GXSTOP_TRIG_REG                               = 0x28040013ull;

static const uint64_t P9N2_PERV_EC09_GXSTOP_TRIG_REG                               = 0x29040013ull;

static const uint64_t P9N2_PERV_EC10_GXSTOP_TRIG_REG                               = 0x2A040013ull;

static const uint64_t P9N2_PERV_EC11_GXSTOP_TRIG_REG                               = 0x2B040013ull;

static const uint64_t P9N2_PERV_EC12_GXSTOP_TRIG_REG                               = 0x2C040013ull;

static const uint64_t P9N2_PERV_EC13_GXSTOP_TRIG_REG                               = 0x2D040013ull;

static const uint64_t P9N2_PERV_EC14_GXSTOP_TRIG_REG                               = 0x2E040013ull;

static const uint64_t P9N2_PERV_EC15_GXSTOP_TRIG_REG                               = 0x2F040013ull;

static const uint64_t P9N2_PERV_EC16_GXSTOP_TRIG_REG                               = 0x30040013ull;

static const uint64_t P9N2_PERV_EC17_GXSTOP_TRIG_REG                               = 0x31040013ull;

static const uint64_t P9N2_PERV_EC18_GXSTOP_TRIG_REG                               = 0x32040013ull;

static const uint64_t P9N2_PERV_EC19_GXSTOP_TRIG_REG                               = 0x33040013ull;

static const uint64_t P9N2_PERV_EC20_GXSTOP_TRIG_REG                               = 0x34040013ull;

static const uint64_t P9N2_PERV_EC21_GXSTOP_TRIG_REG                               = 0x35040013ull;

static const uint64_t P9N2_PERV_EC22_GXSTOP_TRIG_REG                               = 0x36040013ull;

static const uint64_t P9N2_PERV_EC23_GXSTOP_TRIG_REG                               = 0x37040013ull;


static const uint64_t P9N2_PERV_HANG_PULSE_0_REG                                   = 0x000F0020ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_0_REG                                = 0x010F0020ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_0_REG                                = 0x020F0020ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_0_REG                                = 0x030F0020ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_0_REG                                = 0x040F0020ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_0_REG                                = 0x050F0020ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_0_REG                                = 0x060F0020ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_0_REG                              = 0x070F0020ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_0_REG                              = 0x080F0020ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_0_REG                               = 0x090F0020ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_0_REG                               = 0x0C0F0020ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_0_REG                              = 0x0D0F0020ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_0_REG                              = 0x0E0F0020ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_0_REG                              = 0x0F0F0020ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_0_REG                              = 0x100F0020ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_0_REG                              = 0x110F0020ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_0_REG                              = 0x120F0020ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_0_REG                              = 0x130F0020ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_0_REG                              = 0x140F0020ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_0_REG                              = 0x150F0020ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_0_REG                              = 0x200F0020ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_0_REG                              = 0x210F0020ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_0_REG                              = 0x220F0020ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_0_REG                              = 0x230F0020ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_0_REG                              = 0x240F0020ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_0_REG                              = 0x250F0020ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_0_REG                              = 0x260F0020ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_0_REG                              = 0x270F0020ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_0_REG                              = 0x280F0020ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_0_REG                              = 0x290F0020ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_0_REG                              = 0x2A0F0020ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_0_REG                              = 0x2B0F0020ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_0_REG                              = 0x2C0F0020ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_0_REG                              = 0x2D0F0020ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_0_REG                              = 0x2E0F0020ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_0_REG                              = 0x2F0F0020ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_0_REG                              = 0x300F0020ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_0_REG                              = 0x310F0020ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_0_REG                              = 0x320F0020ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_0_REG                              = 0x330F0020ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_0_REG                              = 0x340F0020ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_0_REG                              = 0x350F0020ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_0_REG                              = 0x360F0020ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_0_REG                              = 0x370F0020ull;


static const uint64_t P9N2_PERV_HANG_PULSE_1_REG                                   = 0x000F0021ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_1_REG                                = 0x010F0021ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_1_REG                                = 0x020F0021ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_1_REG                                = 0x030F0021ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_1_REG                                = 0x040F0021ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_1_REG                                = 0x050F0021ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_1_REG                                = 0x060F0021ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_1_REG                              = 0x070F0021ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_1_REG                              = 0x080F0021ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_1_REG                               = 0x090F0021ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_1_REG                               = 0x0C0F0021ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_1_REG                              = 0x0D0F0021ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_1_REG                              = 0x0E0F0021ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_1_REG                              = 0x0F0F0021ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_1_REG                              = 0x100F0021ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_1_REG                              = 0x110F0021ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_1_REG                              = 0x120F0021ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_1_REG                              = 0x130F0021ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_1_REG                              = 0x140F0021ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_1_REG                              = 0x150F0021ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_1_REG                              = 0x200F0021ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_1_REG                              = 0x210F0021ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_1_REG                              = 0x220F0021ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_1_REG                              = 0x230F0021ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_1_REG                              = 0x240F0021ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_1_REG                              = 0x250F0021ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_1_REG                              = 0x260F0021ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_1_REG                              = 0x270F0021ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_1_REG                              = 0x280F0021ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_1_REG                              = 0x290F0021ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_1_REG                              = 0x2A0F0021ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_1_REG                              = 0x2B0F0021ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_1_REG                              = 0x2C0F0021ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_1_REG                              = 0x2D0F0021ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_1_REG                              = 0x2E0F0021ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_1_REG                              = 0x2F0F0021ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_1_REG                              = 0x300F0021ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_1_REG                              = 0x310F0021ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_1_REG                              = 0x320F0021ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_1_REG                              = 0x330F0021ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_1_REG                              = 0x340F0021ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_1_REG                              = 0x350F0021ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_1_REG                              = 0x360F0021ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_1_REG                              = 0x370F0021ull;


static const uint64_t P9N2_PERV_HANG_PULSE_2_REG                                   = 0x000F0022ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_2_REG                                = 0x010F0022ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_2_REG                                = 0x020F0022ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_2_REG                                = 0x030F0022ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_2_REG                                = 0x040F0022ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_2_REG                                = 0x050F0022ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_2_REG                                = 0x060F0022ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_2_REG                              = 0x070F0022ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_2_REG                              = 0x080F0022ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_2_REG                               = 0x090F0022ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_2_REG                               = 0x0C0F0022ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_2_REG                              = 0x0D0F0022ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_2_REG                              = 0x0E0F0022ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_2_REG                              = 0x0F0F0022ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_2_REG                              = 0x100F0022ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_2_REG                              = 0x110F0022ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_2_REG                              = 0x120F0022ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_2_REG                              = 0x130F0022ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_2_REG                              = 0x140F0022ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_2_REG                              = 0x150F0022ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_2_REG                              = 0x200F0022ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_2_REG                              = 0x210F0022ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_2_REG                              = 0x220F0022ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_2_REG                              = 0x230F0022ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_2_REG                              = 0x240F0022ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_2_REG                              = 0x250F0022ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_2_REG                              = 0x260F0022ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_2_REG                              = 0x270F0022ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_2_REG                              = 0x280F0022ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_2_REG                              = 0x290F0022ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_2_REG                              = 0x2A0F0022ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_2_REG                              = 0x2B0F0022ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_2_REG                              = 0x2C0F0022ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_2_REG                              = 0x2D0F0022ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_2_REG                              = 0x2E0F0022ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_2_REG                              = 0x2F0F0022ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_2_REG                              = 0x300F0022ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_2_REG                              = 0x310F0022ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_2_REG                              = 0x320F0022ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_2_REG                              = 0x330F0022ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_2_REG                              = 0x340F0022ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_2_REG                              = 0x350F0022ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_2_REG                              = 0x360F0022ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_2_REG                              = 0x370F0022ull;


static const uint64_t P9N2_PERV_HANG_PULSE_3_REG                                   = 0x000F0023ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_3_REG                                = 0x010F0023ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_3_REG                                = 0x020F0023ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_3_REG                                = 0x030F0023ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_3_REG                                = 0x040F0023ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_3_REG                                = 0x050F0023ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_3_REG                                = 0x060F0023ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_3_REG                              = 0x070F0023ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_3_REG                              = 0x080F0023ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_3_REG                               = 0x090F0023ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_3_REG                               = 0x0C0F0023ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_3_REG                              = 0x0D0F0023ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_3_REG                              = 0x0E0F0023ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_3_REG                              = 0x0F0F0023ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_3_REG                              = 0x100F0023ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_3_REG                              = 0x110F0023ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_3_REG                              = 0x120F0023ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_3_REG                              = 0x130F0023ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_3_REG                              = 0x140F0023ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_3_REG                              = 0x150F0023ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_3_REG                              = 0x200F0023ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_3_REG                              = 0x210F0023ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_3_REG                              = 0x220F0023ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_3_REG                              = 0x230F0023ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_3_REG                              = 0x240F0023ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_3_REG                              = 0x250F0023ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_3_REG                              = 0x260F0023ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_3_REG                              = 0x270F0023ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_3_REG                              = 0x280F0023ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_3_REG                              = 0x290F0023ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_3_REG                              = 0x2A0F0023ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_3_REG                              = 0x2B0F0023ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_3_REG                              = 0x2C0F0023ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_3_REG                              = 0x2D0F0023ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_3_REG                              = 0x2E0F0023ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_3_REG                              = 0x2F0F0023ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_3_REG                              = 0x300F0023ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_3_REG                              = 0x310F0023ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_3_REG                              = 0x320F0023ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_3_REG                              = 0x330F0023ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_3_REG                              = 0x340F0023ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_3_REG                              = 0x350F0023ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_3_REG                              = 0x360F0023ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_3_REG                              = 0x370F0023ull;


static const uint64_t P9N2_PERV_HANG_PULSE_4_REG                                   = 0x000F0024ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_4_REG                                = 0x010F0024ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_4_REG                                = 0x020F0024ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_4_REG                                = 0x030F0024ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_4_REG                                = 0x040F0024ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_4_REG                                = 0x050F0024ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_4_REG                                = 0x060F0024ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_4_REG                              = 0x070F0024ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_4_REG                              = 0x080F0024ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_4_REG                               = 0x090F0024ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_4_REG                               = 0x0C0F0024ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_4_REG                              = 0x0D0F0024ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_4_REG                              = 0x0E0F0024ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_4_REG                              = 0x0F0F0024ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_4_REG                              = 0x100F0024ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_4_REG                              = 0x110F0024ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_4_REG                              = 0x120F0024ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_4_REG                              = 0x130F0024ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_4_REG                              = 0x140F0024ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_4_REG                              = 0x150F0024ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_4_REG                              = 0x200F0024ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_4_REG                              = 0x210F0024ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_4_REG                              = 0x220F0024ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_4_REG                              = 0x230F0024ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_4_REG                              = 0x240F0024ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_4_REG                              = 0x250F0024ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_4_REG                              = 0x260F0024ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_4_REG                              = 0x270F0024ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_4_REG                              = 0x280F0024ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_4_REG                              = 0x290F0024ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_4_REG                              = 0x2A0F0024ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_4_REG                              = 0x2B0F0024ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_4_REG                              = 0x2C0F0024ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_4_REG                              = 0x2D0F0024ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_4_REG                              = 0x2E0F0024ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_4_REG                              = 0x2F0F0024ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_4_REG                              = 0x300F0024ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_4_REG                              = 0x310F0024ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_4_REG                              = 0x320F0024ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_4_REG                              = 0x330F0024ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_4_REG                              = 0x340F0024ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_4_REG                              = 0x350F0024ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_4_REG                              = 0x360F0024ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_4_REG                              = 0x370F0024ull;


static const uint64_t P9N2_PERV_HANG_PULSE_5_REG                                   = 0x000F0025ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_5_REG                                = 0x010F0025ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_5_REG                                = 0x020F0025ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_5_REG                                = 0x030F0025ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_5_REG                                = 0x040F0025ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_5_REG                                = 0x050F0025ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_5_REG                                = 0x060F0025ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_5_REG                              = 0x070F0025ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_5_REG                              = 0x080F0025ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_5_REG                               = 0x090F0025ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_5_REG                               = 0x0C0F0025ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_5_REG                              = 0x0D0F0025ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_5_REG                              = 0x0E0F0025ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_5_REG                              = 0x0F0F0025ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_5_REG                              = 0x100F0025ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_5_REG                              = 0x110F0025ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_5_REG                              = 0x120F0025ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_5_REG                              = 0x130F0025ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_5_REG                              = 0x140F0025ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_5_REG                              = 0x150F0025ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_5_REG                              = 0x200F0025ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_5_REG                              = 0x210F0025ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_5_REG                              = 0x220F0025ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_5_REG                              = 0x230F0025ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_5_REG                              = 0x240F0025ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_5_REG                              = 0x250F0025ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_5_REG                              = 0x260F0025ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_5_REG                              = 0x270F0025ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_5_REG                              = 0x280F0025ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_5_REG                              = 0x290F0025ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_5_REG                              = 0x2A0F0025ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_5_REG                              = 0x2B0F0025ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_5_REG                              = 0x2C0F0025ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_5_REG                              = 0x2D0F0025ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_5_REG                              = 0x2E0F0025ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_5_REG                              = 0x2F0F0025ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_5_REG                              = 0x300F0025ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_5_REG                              = 0x310F0025ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_5_REG                              = 0x320F0025ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_5_REG                              = 0x330F0025ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_5_REG                              = 0x340F0025ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_5_REG                              = 0x350F0025ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_5_REG                              = 0x360F0025ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_5_REG                              = 0x370F0025ull;


static const uint64_t P9N2_PERV_HANG_PULSE_6_REG                                   = 0x000F0026ull;

static const uint64_t P9N2_PERV_TP_HANG_PULSE_6_REG                                = 0x010F0026ull;

static const uint64_t P9N2_PERV_N0_HANG_PULSE_6_REG                                = 0x020F0026ull;

static const uint64_t P9N2_PERV_N1_HANG_PULSE_6_REG                                = 0x030F0026ull;

static const uint64_t P9N2_PERV_N2_HANG_PULSE_6_REG                                = 0x040F0026ull;

static const uint64_t P9N2_PERV_N3_HANG_PULSE_6_REG                                = 0x050F0026ull;

static const uint64_t P9N2_PERV_XB_HANG_PULSE_6_REG                                = 0x060F0026ull;

static const uint64_t P9N2_PERV_MC01_HANG_PULSE_6_REG                              = 0x070F0026ull;

static const uint64_t P9N2_PERV_MC23_HANG_PULSE_6_REG                              = 0x080F0026ull;

static const uint64_t P9N2_PERV_OB0_HANG_PULSE_6_REG                               = 0x090F0026ull;

static const uint64_t P9N2_PERV_OB3_HANG_PULSE_6_REG                               = 0x0C0F0026ull;

static const uint64_t P9N2_PERV_PCI0_HANG_PULSE_6_REG                              = 0x0D0F0026ull;

static const uint64_t P9N2_PERV_PCI1_HANG_PULSE_6_REG                              = 0x0E0F0026ull;

static const uint64_t P9N2_PERV_PCI2_HANG_PULSE_6_REG                              = 0x0F0F0026ull;

static const uint64_t P9N2_PERV_EP00_HANG_PULSE_6_REG                              = 0x100F0026ull;

static const uint64_t P9N2_PERV_EP01_HANG_PULSE_6_REG                              = 0x110F0026ull;

static const uint64_t P9N2_PERV_EP02_HANG_PULSE_6_REG                              = 0x120F0026ull;

static const uint64_t P9N2_PERV_EP03_HANG_PULSE_6_REG                              = 0x130F0026ull;

static const uint64_t P9N2_PERV_EP04_HANG_PULSE_6_REG                              = 0x140F0026ull;

static const uint64_t P9N2_PERV_EP05_HANG_PULSE_6_REG                              = 0x150F0026ull;

static const uint64_t P9N2_PERV_EC00_HANG_PULSE_6_REG                              = 0x200F0026ull;

static const uint64_t P9N2_PERV_EC01_HANG_PULSE_6_REG                              = 0x210F0026ull;

static const uint64_t P9N2_PERV_EC02_HANG_PULSE_6_REG                              = 0x220F0026ull;

static const uint64_t P9N2_PERV_EC03_HANG_PULSE_6_REG                              = 0x230F0026ull;

static const uint64_t P9N2_PERV_EC04_HANG_PULSE_6_REG                              = 0x240F0026ull;

static const uint64_t P9N2_PERV_EC05_HANG_PULSE_6_REG                              = 0x250F0026ull;

static const uint64_t P9N2_PERV_EC06_HANG_PULSE_6_REG                              = 0x260F0026ull;

static const uint64_t P9N2_PERV_EC07_HANG_PULSE_6_REG                              = 0x270F0026ull;

static const uint64_t P9N2_PERV_EC08_HANG_PULSE_6_REG                              = 0x280F0026ull;

static const uint64_t P9N2_PERV_EC09_HANG_PULSE_6_REG                              = 0x290F0026ull;

static const uint64_t P9N2_PERV_EC10_HANG_PULSE_6_REG                              = 0x2A0F0026ull;

static const uint64_t P9N2_PERV_EC11_HANG_PULSE_6_REG                              = 0x2B0F0026ull;

static const uint64_t P9N2_PERV_EC12_HANG_PULSE_6_REG                              = 0x2C0F0026ull;

static const uint64_t P9N2_PERV_EC13_HANG_PULSE_6_REG                              = 0x2D0F0026ull;

static const uint64_t P9N2_PERV_EC14_HANG_PULSE_6_REG                              = 0x2E0F0026ull;

static const uint64_t P9N2_PERV_EC15_HANG_PULSE_6_REG                              = 0x2F0F0026ull;

static const uint64_t P9N2_PERV_EC16_HANG_PULSE_6_REG                              = 0x300F0026ull;

static const uint64_t P9N2_PERV_EC17_HANG_PULSE_6_REG                              = 0x310F0026ull;

static const uint64_t P9N2_PERV_EC18_HANG_PULSE_6_REG                              = 0x320F0026ull;

static const uint64_t P9N2_PERV_EC19_HANG_PULSE_6_REG                              = 0x330F0026ull;

static const uint64_t P9N2_PERV_EC20_HANG_PULSE_6_REG                              = 0x340F0026ull;

static const uint64_t P9N2_PERV_EC21_HANG_PULSE_6_REG                              = 0x350F0026ull;

static const uint64_t P9N2_PERV_EC22_HANG_PULSE_6_REG                              = 0x360F0026ull;

static const uint64_t P9N2_PERV_EC23_HANG_PULSE_6_REG                              = 0x370F0026ull;


static const uint64_t P9N2_PERV_HEARTBEAT_REG                                      = 0x000F0018ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_HEARTBEAT_REG                                   = 0x010F0018ull;

static const uint64_t P9N2_PERV_N0_HEARTBEAT_REG                                   = 0x020F0018ull;

static const uint64_t P9N2_PERV_N1_HEARTBEAT_REG                                   = 0x030F0018ull;

static const uint64_t P9N2_PERV_N2_HEARTBEAT_REG                                   = 0x040F0018ull;

static const uint64_t P9N2_PERV_N3_HEARTBEAT_REG                                   = 0x050F0018ull;

static const uint64_t P9N2_PERV_XB_HEARTBEAT_REG                                   = 0x060F0018ull;

static const uint64_t P9N2_PERV_MC01_HEARTBEAT_REG                                 = 0x070F0018ull;

static const uint64_t P9N2_PERV_MC23_HEARTBEAT_REG                                 = 0x080F0018ull;

static const uint64_t P9N2_PERV_OB0_HEARTBEAT_REG                                  = 0x090F0018ull;

static const uint64_t P9N2_PERV_OB3_HEARTBEAT_REG                                  = 0x0C0F0018ull;

static const uint64_t P9N2_PERV_PCI0_HEARTBEAT_REG                                 = 0x0D0F0018ull;

static const uint64_t P9N2_PERV_PCI1_HEARTBEAT_REG                                 = 0x0E0F0018ull;

static const uint64_t P9N2_PERV_PCI2_HEARTBEAT_REG                                 = 0x0F0F0018ull;

static const uint64_t P9N2_PERV_EP00_HEARTBEAT_REG                                 = 0x100F0018ull;

static const uint64_t P9N2_PERV_EP01_HEARTBEAT_REG                                 = 0x110F0018ull;

static const uint64_t P9N2_PERV_EP02_HEARTBEAT_REG                                 = 0x120F0018ull;

static const uint64_t P9N2_PERV_EP03_HEARTBEAT_REG                                 = 0x130F0018ull;

static const uint64_t P9N2_PERV_EP04_HEARTBEAT_REG                                 = 0x140F0018ull;

static const uint64_t P9N2_PERV_EP05_HEARTBEAT_REG                                 = 0x150F0018ull;

static const uint64_t P9N2_PERV_EC00_HEARTBEAT_REG                                 = 0x200F0018ull;

static const uint64_t P9N2_PERV_EC01_HEARTBEAT_REG                                 = 0x210F0018ull;

static const uint64_t P9N2_PERV_EC02_HEARTBEAT_REG                                 = 0x220F0018ull;

static const uint64_t P9N2_PERV_EC03_HEARTBEAT_REG                                 = 0x230F0018ull;

static const uint64_t P9N2_PERV_EC04_HEARTBEAT_REG                                 = 0x240F0018ull;

static const uint64_t P9N2_PERV_EC05_HEARTBEAT_REG                                 = 0x250F0018ull;

static const uint64_t P9N2_PERV_EC06_HEARTBEAT_REG                                 = 0x260F0018ull;

static const uint64_t P9N2_PERV_EC07_HEARTBEAT_REG                                 = 0x270F0018ull;

static const uint64_t P9N2_PERV_EC08_HEARTBEAT_REG                                 = 0x280F0018ull;

static const uint64_t P9N2_PERV_EC09_HEARTBEAT_REG                                 = 0x290F0018ull;

static const uint64_t P9N2_PERV_EC10_HEARTBEAT_REG                                 = 0x2A0F0018ull;

static const uint64_t P9N2_PERV_EC11_HEARTBEAT_REG                                 = 0x2B0F0018ull;

static const uint64_t P9N2_PERV_EC12_HEARTBEAT_REG                                 = 0x2C0F0018ull;

static const uint64_t P9N2_PERV_EC13_HEARTBEAT_REG                                 = 0x2D0F0018ull;

static const uint64_t P9N2_PERV_EC14_HEARTBEAT_REG                                 = 0x2E0F0018ull;

static const uint64_t P9N2_PERV_EC15_HEARTBEAT_REG                                 = 0x2F0F0018ull;

static const uint64_t P9N2_PERV_EC16_HEARTBEAT_REG                                 = 0x300F0018ull;

static const uint64_t P9N2_PERV_EC17_HEARTBEAT_REG                                 = 0x310F0018ull;

static const uint64_t P9N2_PERV_EC18_HEARTBEAT_REG                                 = 0x320F0018ull;

static const uint64_t P9N2_PERV_EC19_HEARTBEAT_REG                                 = 0x330F0018ull;

static const uint64_t P9N2_PERV_EC20_HEARTBEAT_REG                                 = 0x340F0018ull;

static const uint64_t P9N2_PERV_EC21_HEARTBEAT_REG                                 = 0x350F0018ull;

static const uint64_t P9N2_PERV_EC22_HEARTBEAT_REG                                 = 0x360F0018ull;

static const uint64_t P9N2_PERV_EC23_HEARTBEAT_REG                                 = 0x370F0018ull;


static const uint64_t P9N2_PERV_HOSTATTN                                           = 0x00040009ull;

static const uint64_t P9N2_PERV_TP_HOSTATTN                                        = 0x01040009ull;

static const uint64_t P9N2_PERV_N0_HOSTATTN                                        = 0x02040009ull;

static const uint64_t P9N2_PERV_N1_HOSTATTN                                        = 0x03040009ull;

static const uint64_t P9N2_PERV_N2_HOSTATTN                                        = 0x04040009ull;

static const uint64_t P9N2_PERV_N3_HOSTATTN                                        = 0x05040009ull;

static const uint64_t P9N2_PERV_XB_HOSTATTN                                        = 0x06040009ull;

static const uint64_t P9N2_PERV_MC01_HOSTATTN                                      = 0x07040009ull;

static const uint64_t P9N2_PERV_MC23_HOSTATTN                                      = 0x08040009ull;

static const uint64_t P9N2_PERV_OB0_HOSTATTN                                       = 0x09040009ull;

static const uint64_t P9N2_PERV_OB3_HOSTATTN                                       = 0x0C040009ull;

static const uint64_t P9N2_PERV_PCI0_HOSTATTN                                      = 0x0D040009ull;

static const uint64_t P9N2_PERV_PCI1_HOSTATTN                                      = 0x0E040009ull;

static const uint64_t P9N2_PERV_PCI2_HOSTATTN                                      = 0x0F040009ull;

static const uint64_t P9N2_PERV_EP00_HOSTATTN                                      = 0x10040009ull;

static const uint64_t P9N2_PERV_EP01_HOSTATTN                                      = 0x11040009ull;

static const uint64_t P9N2_PERV_EP02_HOSTATTN                                      = 0x12040009ull;

static const uint64_t P9N2_PERV_EP03_HOSTATTN                                      = 0x13040009ull;

static const uint64_t P9N2_PERV_EP04_HOSTATTN                                      = 0x14040009ull;

static const uint64_t P9N2_PERV_EP05_HOSTATTN                                      = 0x15040009ull;

static const uint64_t P9N2_PERV_EC00_HOSTATTN                                      = 0x20040009ull;

static const uint64_t P9N2_PERV_EC01_HOSTATTN                                      = 0x21040009ull;

static const uint64_t P9N2_PERV_EC02_HOSTATTN                                      = 0x22040009ull;

static const uint64_t P9N2_PERV_EC03_HOSTATTN                                      = 0x23040009ull;

static const uint64_t P9N2_PERV_EC04_HOSTATTN                                      = 0x24040009ull;

static const uint64_t P9N2_PERV_EC05_HOSTATTN                                      = 0x25040009ull;

static const uint64_t P9N2_PERV_EC06_HOSTATTN                                      = 0x26040009ull;

static const uint64_t P9N2_PERV_EC07_HOSTATTN                                      = 0x27040009ull;

static const uint64_t P9N2_PERV_EC08_HOSTATTN                                      = 0x28040009ull;

static const uint64_t P9N2_PERV_EC09_HOSTATTN                                      = 0x29040009ull;

static const uint64_t P9N2_PERV_EC10_HOSTATTN                                      = 0x2A040009ull;

static const uint64_t P9N2_PERV_EC11_HOSTATTN                                      = 0x2B040009ull;

static const uint64_t P9N2_PERV_EC12_HOSTATTN                                      = 0x2C040009ull;

static const uint64_t P9N2_PERV_EC13_HOSTATTN                                      = 0x2D040009ull;

static const uint64_t P9N2_PERV_EC14_HOSTATTN                                      = 0x2E040009ull;

static const uint64_t P9N2_PERV_EC15_HOSTATTN                                      = 0x2F040009ull;

static const uint64_t P9N2_PERV_EC16_HOSTATTN                                      = 0x30040009ull;

static const uint64_t P9N2_PERV_EC17_HOSTATTN                                      = 0x31040009ull;

static const uint64_t P9N2_PERV_EC18_HOSTATTN                                      = 0x32040009ull;

static const uint64_t P9N2_PERV_EC19_HOSTATTN                                      = 0x33040009ull;

static const uint64_t P9N2_PERV_EC20_HOSTATTN                                      = 0x34040009ull;

static const uint64_t P9N2_PERV_EC21_HOSTATTN                                      = 0x35040009ull;

static const uint64_t P9N2_PERV_EC22_HOSTATTN                                      = 0x36040009ull;

static const uint64_t P9N2_PERV_EC23_HOSTATTN                                      = 0x37040009ull;


static const uint64_t P9N2_PERV_HOSTATTN_MASK                                      = 0x0004001Aull;

static const uint64_t P9N2_PERV_TP_HOSTATTN_MASK                                   = 0x0104001Aull;

static const uint64_t P9N2_PERV_N0_HOSTATTN_MASK                                   = 0x0204001Aull;

static const uint64_t P9N2_PERV_N1_HOSTATTN_MASK                                   = 0x0304001Aull;

static const uint64_t P9N2_PERV_N2_HOSTATTN_MASK                                   = 0x0404001Aull;

static const uint64_t P9N2_PERV_N3_HOSTATTN_MASK                                   = 0x0504001Aull;

static const uint64_t P9N2_PERV_XB_HOSTATTN_MASK                                   = 0x0604001Aull;

static const uint64_t P9N2_PERV_MC01_HOSTATTN_MASK                                 = 0x0704001Aull;

static const uint64_t P9N2_PERV_MC23_HOSTATTN_MASK                                 = 0x0804001Aull;

static const uint64_t P9N2_PERV_OB0_HOSTATTN_MASK                                  = 0x0904001Aull;

static const uint64_t P9N2_PERV_OB3_HOSTATTN_MASK                                  = 0x0C04001Aull;

static const uint64_t P9N2_PERV_PCI0_HOSTATTN_MASK                                 = 0x0D04001Aull;

static const uint64_t P9N2_PERV_PCI1_HOSTATTN_MASK                                 = 0x0E04001Aull;

static const uint64_t P9N2_PERV_PCI2_HOSTATTN_MASK                                 = 0x0F04001Aull;

static const uint64_t P9N2_PERV_EP00_HOSTATTN_MASK                                 = 0x1004001Aull;

static const uint64_t P9N2_PERV_EP01_HOSTATTN_MASK                                 = 0x1104001Aull;

static const uint64_t P9N2_PERV_EP02_HOSTATTN_MASK                                 = 0x1204001Aull;

static const uint64_t P9N2_PERV_EP03_HOSTATTN_MASK                                 = 0x1304001Aull;

static const uint64_t P9N2_PERV_EP04_HOSTATTN_MASK                                 = 0x1404001Aull;

static const uint64_t P9N2_PERV_EP05_HOSTATTN_MASK                                 = 0x1504001Aull;

static const uint64_t P9N2_PERV_EC00_HOSTATTN_MASK                                 = 0x2004001Aull;

static const uint64_t P9N2_PERV_EC01_HOSTATTN_MASK                                 = 0x2104001Aull;

static const uint64_t P9N2_PERV_EC02_HOSTATTN_MASK                                 = 0x2204001Aull;

static const uint64_t P9N2_PERV_EC03_HOSTATTN_MASK                                 = 0x2304001Aull;

static const uint64_t P9N2_PERV_EC04_HOSTATTN_MASK                                 = 0x2404001Aull;

static const uint64_t P9N2_PERV_EC05_HOSTATTN_MASK                                 = 0x2504001Aull;

static const uint64_t P9N2_PERV_EC06_HOSTATTN_MASK                                 = 0x2604001Aull;

static const uint64_t P9N2_PERV_EC07_HOSTATTN_MASK                                 = 0x2704001Aull;

static const uint64_t P9N2_PERV_EC08_HOSTATTN_MASK                                 = 0x2804001Aull;

static const uint64_t P9N2_PERV_EC09_HOSTATTN_MASK                                 = 0x2904001Aull;

static const uint64_t P9N2_PERV_EC10_HOSTATTN_MASK                                 = 0x2A04001Aull;

static const uint64_t P9N2_PERV_EC11_HOSTATTN_MASK                                 = 0x2B04001Aull;

static const uint64_t P9N2_PERV_EC12_HOSTATTN_MASK                                 = 0x2C04001Aull;

static const uint64_t P9N2_PERV_EC13_HOSTATTN_MASK                                 = 0x2D04001Aull;

static const uint64_t P9N2_PERV_EC14_HOSTATTN_MASK                                 = 0x2E04001Aull;

static const uint64_t P9N2_PERV_EC15_HOSTATTN_MASK                                 = 0x2F04001Aull;

static const uint64_t P9N2_PERV_EC16_HOSTATTN_MASK                                 = 0x3004001Aull;

static const uint64_t P9N2_PERV_EC17_HOSTATTN_MASK                                 = 0x3104001Aull;

static const uint64_t P9N2_PERV_EC18_HOSTATTN_MASK                                 = 0x3204001Aull;

static const uint64_t P9N2_PERV_EC19_HOSTATTN_MASK                                 = 0x3304001Aull;

static const uint64_t P9N2_PERV_EC20_HOSTATTN_MASK                                 = 0x3404001Aull;

static const uint64_t P9N2_PERV_EC21_HOSTATTN_MASK                                 = 0x3504001Aull;

static const uint64_t P9N2_PERV_EC22_HOSTATTN_MASK                                 = 0x3604001Aull;

static const uint64_t P9N2_PERV_EC23_HOSTATTN_MASK                                 = 0x3704001Aull;


static const uint64_t P9N2_PERV_HOST_MASK_REG                                      = 0x000F0033ull;

static const uint64_t P9N2_PERV_PIB_HOST_MASK_REG                                  = 0x000F0033ull;


static const uint64_t P9N2_PERV_0_FSII2C_I2C_BUSY_REGISTER_A                       = 0x0000180Aull;

static const uint32_t P9N2_PERV_FSII2C_I2C_BUSY_REGISTER_A                         = 0x0000180Aull;


static const uint64_t P9N2_PERV_IGNORE_PAR_REG                                     = 0x000F001Cull;

static const uint64_t P9N2_PERV_PIB_IGNORE_PAR_REG                                 = 0x000F001Cull;


static const uint64_t P9N2_PERV_0_FSII2C_IMM_RESET_ERR_A                           = 0x00001808ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSII2C_IMM_RESET_ERR_A                             = 0x00001808ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PERV_0_FSII2C_IMM_RESET_I2C_A                           = 0x00001807ull;

static const uint32_t P9N2_PERV_FSII2C_IMM_RESET_I2C_A                             = 0x00001807ull;


static const uint64_t P9N2_PERV_0_FSII2C_IMM_RESET_S_SCL_A                         = 0x0000180Bull;

static const uint32_t P9N2_PERV_FSII2C_IMM_RESET_S_SCL_A                           = 0x0000180Bull;


static const uint64_t P9N2_PERV_0_FSII2C_IMM_RESET_S_SDA_A                         = 0x0000180Dull;

static const uint32_t P9N2_PERV_FSII2C_IMM_RESET_S_SDA_A                           = 0x0000180Dull;


static const uint64_t P9N2_PERV_0_FSII2C_IMM_SET_S_SCL_A                           = 0x00001809ull;

static const uint32_t P9N2_PERV_FSII2C_IMM_SET_S_SCL_A                             = 0x00001809ull;


static const uint64_t P9N2_PERV_0_FSII2C_IMM_SET_S_SDA_A                           = 0x0000180Cull;

static const uint32_t P9N2_PERV_FSII2C_IMM_SET_S_SDA_A                             = 0x0000180Cull;


static const uint64_t P9N2_PERV_INJECT_REG                                         = 0x00050011ull;

static const uint64_t P9N2_PERV_TP_INJECT_REG                                      = 0x01050011ull;

static const uint64_t P9N2_PERV_N0_INJECT_REG                                      = 0x02050011ull;

static const uint64_t P9N2_PERV_N1_INJECT_REG                                      = 0x03050011ull;

static const uint64_t P9N2_PERV_N2_INJECT_REG                                      = 0x04050011ull;

static const uint64_t P9N2_PERV_N3_INJECT_REG                                      = 0x05050011ull;

static const uint64_t P9N2_PERV_XB_INJECT_REG                                      = 0x06050011ull;

static const uint64_t P9N2_PERV_MC01_INJECT_REG                                    = 0x07050011ull;

static const uint64_t P9N2_PERV_MC23_INJECT_REG                                    = 0x08050011ull;

static const uint64_t P9N2_PERV_OB0_INJECT_REG                                     = 0x09050011ull;

static const uint64_t P9N2_PERV_OB3_INJECT_REG                                     = 0x0C050011ull;

static const uint64_t P9N2_PERV_PCI0_INJECT_REG                                    = 0x0D050011ull;

static const uint64_t P9N2_PERV_PCI1_INJECT_REG                                    = 0x0E050011ull;

static const uint64_t P9N2_PERV_PCI2_INJECT_REG                                    = 0x0F050011ull;

static const uint64_t P9N2_PERV_EP00_INJECT_REG                                    = 0x10050011ull;

static const uint64_t P9N2_PERV_EP01_INJECT_REG                                    = 0x11050011ull;

static const uint64_t P9N2_PERV_EP02_INJECT_REG                                    = 0x12050011ull;

static const uint64_t P9N2_PERV_EP03_INJECT_REG                                    = 0x13050011ull;

static const uint64_t P9N2_PERV_EP04_INJECT_REG                                    = 0x14050011ull;

static const uint64_t P9N2_PERV_EP05_INJECT_REG                                    = 0x15050011ull;

static const uint64_t P9N2_PERV_EC00_INJECT_REG                                    = 0x20050011ull;

static const uint64_t P9N2_PERV_EC01_INJECT_REG                                    = 0x21050011ull;

static const uint64_t P9N2_PERV_EC02_INJECT_REG                                    = 0x22050011ull;

static const uint64_t P9N2_PERV_EC03_INJECT_REG                                    = 0x23050011ull;

static const uint64_t P9N2_PERV_EC04_INJECT_REG                                    = 0x24050011ull;

static const uint64_t P9N2_PERV_EC05_INJECT_REG                                    = 0x25050011ull;

static const uint64_t P9N2_PERV_EC06_INJECT_REG                                    = 0x26050011ull;

static const uint64_t P9N2_PERV_EC07_INJECT_REG                                    = 0x27050011ull;

static const uint64_t P9N2_PERV_EC08_INJECT_REG                                    = 0x28050011ull;

static const uint64_t P9N2_PERV_EC09_INJECT_REG                                    = 0x29050011ull;

static const uint64_t P9N2_PERV_EC10_INJECT_REG                                    = 0x2A050011ull;

static const uint64_t P9N2_PERV_EC11_INJECT_REG                                    = 0x2B050011ull;

static const uint64_t P9N2_PERV_EC12_INJECT_REG                                    = 0x2C050011ull;

static const uint64_t P9N2_PERV_EC13_INJECT_REG                                    = 0x2D050011ull;

static const uint64_t P9N2_PERV_EC14_INJECT_REG                                    = 0x2E050011ull;

static const uint64_t P9N2_PERV_EC15_INJECT_REG                                    = 0x2F050011ull;

static const uint64_t P9N2_PERV_EC16_INJECT_REG                                    = 0x30050011ull;

static const uint64_t P9N2_PERV_EC17_INJECT_REG                                    = 0x31050011ull;

static const uint64_t P9N2_PERV_EC18_INJECT_REG                                    = 0x32050011ull;

static const uint64_t P9N2_PERV_EC19_INJECT_REG                                    = 0x33050011ull;

static const uint64_t P9N2_PERV_EC20_INJECT_REG                                    = 0x34050011ull;

static const uint64_t P9N2_PERV_EC21_INJECT_REG                                    = 0x35050011ull;

static const uint64_t P9N2_PERV_EC22_INJECT_REG                                    = 0x36050011ull;

static const uint64_t P9N2_PERV_EC23_INJECT_REG                                    = 0x37050011ull;


static const uint32_t P9N2_PERV_FSI2PIB_INTERRUPT_FSI                              = 0x0000100Bull;

static const uint32_t P9N2_PERV_FSI2PIB_INTERRUPT_FSI_BYTE                         = 0x0000102Cull;


static const uint64_t P9N2_PERV_INTERRUPT1_REG                                     = 0x000F0020ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_INTERRUPT1_REG_OR                                  = 0x000F0021ull;

static const uint64_t P9N2_PERV_INTERRUPT1_REG_AND                                 = 0x000F0022ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT1_REG                                 = 0x000F0020ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT1_REG_OR                              = 0x000F0021ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT1_REG_AND                             = 0x000F0022ull;


static const uint64_t P9N2_PERV_INTERRUPT2_REG                                     = 0x000F0023ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_INTERRUPT2_REG_OR                                  = 0x000F0024ull;

static const uint64_t P9N2_PERV_INTERRUPT2_REG_AND                                 = 0x000F0025ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT2_REG                                 = 0x000F0023ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT2_REG_OR                              = 0x000F0024ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT2_REG_AND                             = 0x000F0025ull;


static const uint64_t P9N2_PERV_INTERRUPT3_REG                                     = 0x000F0026ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_INTERRUPT3_REG_OR                                  = 0x000F0027ull;

static const uint64_t P9N2_PERV_INTERRUPT3_REG_AND                                 = 0x000F0028ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT3_REG                                 = 0x000F0026ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT3_REG_OR                              = 0x000F0027ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT3_REG_AND                             = 0x000F0028ull;


static const uint64_t P9N2_PERV_INTERRUPT4_REG                                     = 0x000F0029ull;

static const uint64_t P9N2_PERV_INTERRUPT4_REG_OR                                  = 0x000F002Aull;

static const uint64_t P9N2_PERV_INTERRUPT4_REG_AND                                 = 0x000F002Bull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT4_REG                                 = 0x000F0029ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT4_REG_OR                              = 0x000F002Aull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT4_REG_AND                             = 0x000F002Bull;


static const uint64_t P9N2_PERV_0_FSII2C_INTERRUPTS_A                              = 0x00001806ull;

static const uint32_t P9N2_PERV_FSII2C_INTERRUPTS_A                                = 0x00001806ull;


static const uint64_t P9N2_PERV_0_FSII2C_INTERRUPT_COND_A                          = 0x00001805ull;

static const uint32_t P9N2_PERV_FSII2C_INTERRUPT_COND_A                            = 0x00001805ull;


static const uint64_t P9N2_PERV_INTERRUPT_CONF_REG                                 = 0x000F002Full;

static const uint64_t P9N2_PERV_INTERRUPT_CONF_REG_WOR                             = 0x000F0030ull;

static const uint64_t P9N2_PERV_INTERRUPT_CONF_REG_WAND                            = 0x000F0031ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_CONF_REG                             = 0x000F002Full;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_CONF_REG_WOR                         = 0x000F0030ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_CONF_REG_WAND                        = 0x000F0031ull;


static const uint64_t P9N2_PERV_INTERRUPT_HOLD_REG                                 = 0x000F0032ull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_HOLD_REG                             = 0x000F0032ull;


static const uint64_t P9N2_PERV_0_FSII2C_INTERRUPT_MASK_REGISTER_A_WO              = 0x00001804ull;

static const uint64_t P9N2_PERV_0_FSII2C_INTERRUPT_MASK_REGISTER_A_OR              = 0x00001805ull;

static const uint64_t P9N2_PERV_0_FSII2C_INTERRUPT_MASK_REGISTER_A_AND             = 0x00001806ull;

static const uint32_t P9N2_PERV_FSII2C_INTERRUPT_MASK_REGISTER_A_WO                = 0x00001804ull;

static const uint32_t P9N2_PERV_FSII2C_INTERRUPT_MASK_REGISTER_A_OR                = 0x00001805ull;

static const uint32_t P9N2_PERV_FSII2C_INTERRUPT_MASK_REGISTER_A_AND               = 0x00001806ull;


static const uint64_t P9N2_PERV_0_FSII2C_INTERRUPT_MASK_REGISTER_READ_A            = 0x00001804ull;

static const uint32_t P9N2_PERV_FSII2C_INTERRUPT_MASK_REGISTER_READ_A              = 0x00001804ull;


static const uint64_t P9N2_PERV_INTERRUPT_TYPE_MASK_REG                            = 0x000F002Cull;

static const uint64_t P9N2_PERV_INTERRUPT_TYPE_MASK_REG_WOR                        = 0x000F002Dull;

static const uint64_t P9N2_PERV_INTERRUPT_TYPE_MASK_REG_WAND                       = 0x000F002Eull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_TYPE_MASK_REG                        = 0x000F002Cull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_TYPE_MASK_REG_WOR                    = 0x000F002Dull;

static const uint64_t P9N2_PERV_PIB_INTERRUPT_TYPE_MASK_REG_WAND                   = 0x000F002Eull;


static const uint64_t P9N2_PERV_INTERRUPT_TYPE_REG                                 = 0x000F001Aull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_INTERRUPT_TYPE_REG                             = 0x000F001Aull;


static const uint64_t P9N2_PERV_IODA_TCD_IODA                                      = 0x00002800ull;


static const uint64_t P9N2_PERV_IODA_TDR_IODA                                      = 0x00002C00ull;


static const uint64_t P9N2_PERV_IODA_TDR_MEM_IODA                                  = 0x00003000ull;


static const uint64_t P9N2_PERV_FSB_IODA_TVT_IODA                                  = 0x00002400ull;


static const uint64_t P9N2_PERV_IODA_XLT_EA_IODA                                   = 0x00004000ull;


static const uint64_t P9N2_PERV_KVREF_AND_VMEAS_MODE_STATUS_REG                    = 0x00020007ull;

static const uint64_t P9N2_PERV_TP_KVREF_AND_VMEAS_MODE_STATUS_REG                 = 0x01020007ull;


static const uint64_t P9N2_PERV_KVREF_TUNE_DATA                                    = 0x00020005ull;

static const uint64_t P9N2_PERV_TP_KVREF_TUNE_DATA                                 = 0x01020005ull;


static const uint64_t P9N2_PERV_LOCAL_FIR                                          = 0x0004000Aull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR                                       = 0x0104000Aull;

static const uint64_t P9N2_PERV_LOCAL_FIR_AND                                      = 0x0004000Bull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_AND                                   = 0x0104000Bull;

static const uint64_t P9N2_PERV_LOCAL_FIR_OR                                       = 0x0004000Cull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_OR                                    = 0x0104000Cull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR                                       = 0x0204000Aull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_AND                                   = 0x0204000Bull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_OR                                    = 0x0204000Cull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR                                       = 0x0304000Aull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_AND                                   = 0x0304000Bull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_OR                                    = 0x0304000Cull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR                                       = 0x0404000Aull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_AND                                   = 0x0404000Bull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_OR                                    = 0x0404000Cull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR                                       = 0x0504000Aull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_AND                                   = 0x0504000Bull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_OR                                    = 0x0504000Cull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR                                       = 0x0604000Aull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_AND                                   = 0x0604000Bull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_OR                                    = 0x0604000Cull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR                                     = 0x0704000Aull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_AND                                 = 0x0704000Bull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_OR                                  = 0x0704000Cull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR                                     = 0x0804000Aull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_AND                                 = 0x0804000Bull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_OR                                  = 0x0804000Cull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR                                      = 0x0904000Aull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_AND                                  = 0x0904000Bull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_OR                                   = 0x0904000Cull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR                                      = 0x0C04000Aull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_AND                                  = 0x0C04000Bull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_OR                                   = 0x0C04000Cull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR                                     = 0x0D04000Aull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_AND                                 = 0x0D04000Bull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_OR                                  = 0x0D04000Cull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR                                     = 0x0E04000Aull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_AND                                 = 0x0E04000Bull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_OR                                  = 0x0E04000Cull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR                                     = 0x0F04000Aull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_AND                                 = 0x0F04000Bull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_OR                                  = 0x0F04000Cull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR                                     = 0x1004000Aull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_AND                                 = 0x1004000Bull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_OR                                  = 0x1004000Cull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR                                     = 0x1104000Aull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_AND                                 = 0x1104000Bull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_OR                                  = 0x1104000Cull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR                                     = 0x1204000Aull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_AND                                 = 0x1204000Bull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_OR                                  = 0x1204000Cull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR                                     = 0x1304000Aull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_AND                                 = 0x1304000Bull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_OR                                  = 0x1304000Cull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR                                     = 0x1404000Aull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_AND                                 = 0x1404000Bull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_OR                                  = 0x1404000Cull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR                                     = 0x1504000Aull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_AND                                 = 0x1504000Bull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_OR                                  = 0x1504000Cull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR                                     = 0x2004000Aull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_AND                                 = 0x2004000Bull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_OR                                  = 0x2004000Cull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR                                     = 0x2104000Aull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_AND                                 = 0x2104000Bull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_OR                                  = 0x2104000Cull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR                                     = 0x2204000Aull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_AND                                 = 0x2204000Bull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_OR                                  = 0x2204000Cull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR                                     = 0x2304000Aull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_AND                                 = 0x2304000Bull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_OR                                  = 0x2304000Cull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR                                     = 0x2404000Aull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_AND                                 = 0x2404000Bull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_OR                                  = 0x2404000Cull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR                                     = 0x2504000Aull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_AND                                 = 0x2504000Bull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_OR                                  = 0x2504000Cull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR                                     = 0x2604000Aull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_AND                                 = 0x2604000Bull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_OR                                  = 0x2604000Cull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR                                     = 0x2704000Aull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_AND                                 = 0x2704000Bull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_OR                                  = 0x2704000Cull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR                                     = 0x2804000Aull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_AND                                 = 0x2804000Bull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_OR                                  = 0x2804000Cull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR                                     = 0x2904000Aull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_AND                                 = 0x2904000Bull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_OR                                  = 0x2904000Cull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR                                     = 0x2A04000Aull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_AND                                 = 0x2A04000Bull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_OR                                  = 0x2A04000Cull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR                                     = 0x2B04000Aull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_AND                                 = 0x2B04000Bull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_OR                                  = 0x2B04000Cull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR                                     = 0x2C04000Aull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_AND                                 = 0x2C04000Bull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_OR                                  = 0x2C04000Cull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR                                     = 0x2D04000Aull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_AND                                 = 0x2D04000Bull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_OR                                  = 0x2D04000Cull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR                                     = 0x2E04000Aull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_AND                                 = 0x2E04000Bull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_OR                                  = 0x2E04000Cull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR                                     = 0x2F04000Aull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_AND                                 = 0x2F04000Bull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_OR                                  = 0x2F04000Cull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR                                     = 0x3004000Aull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_AND                                 = 0x3004000Bull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_OR                                  = 0x3004000Cull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR                                     = 0x3104000Aull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_AND                                 = 0x3104000Bull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_OR                                  = 0x3104000Cull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR                                     = 0x3204000Aull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_AND                                 = 0x3204000Bull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_OR                                  = 0x3204000Cull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR                                     = 0x3304000Aull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_AND                                 = 0x3304000Bull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_OR                                  = 0x3304000Cull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR                                     = 0x3404000Aull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_AND                                 = 0x3404000Bull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_OR                                  = 0x3404000Cull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR                                     = 0x3504000Aull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_AND                                 = 0x3504000Bull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_OR                                  = 0x3504000Cull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR                                     = 0x3604000Aull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_AND                                 = 0x3604000Bull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_OR                                  = 0x3604000Cull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR                                     = 0x3704000Aull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_AND                                 = 0x3704000Bull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_OR                                  = 0x3704000Cull;


static const uint64_t P9N2_PERV_LOCAL_FIR_ACTION0                                  = 0x00040010ull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_ACTION0                               = 0x01040010ull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_ACTION0                               = 0x02040010ull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_ACTION0                               = 0x03040010ull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_ACTION0                               = 0x04040010ull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_ACTION0                               = 0x05040010ull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_ACTION0                               = 0x06040010ull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_ACTION0                             = 0x07040010ull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_ACTION0                             = 0x08040010ull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_ACTION0                              = 0x09040010ull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_ACTION0                              = 0x0C040010ull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_ACTION0                             = 0x0D040010ull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_ACTION0                             = 0x0E040010ull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_ACTION0                             = 0x0F040010ull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_ACTION0                             = 0x10040010ull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_ACTION0                             = 0x11040010ull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_ACTION0                             = 0x12040010ull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_ACTION0                             = 0x13040010ull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_ACTION0                             = 0x14040010ull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_ACTION0                             = 0x15040010ull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_ACTION0                             = 0x20040010ull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_ACTION0                             = 0x21040010ull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_ACTION0                             = 0x22040010ull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_ACTION0                             = 0x23040010ull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_ACTION0                             = 0x24040010ull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_ACTION0                             = 0x25040010ull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_ACTION0                             = 0x26040010ull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_ACTION0                             = 0x27040010ull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_ACTION0                             = 0x28040010ull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_ACTION0                             = 0x29040010ull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_ACTION0                             = 0x2A040010ull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_ACTION0                             = 0x2B040010ull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_ACTION0                             = 0x2C040010ull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_ACTION0                             = 0x2D040010ull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_ACTION0                             = 0x2E040010ull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_ACTION0                             = 0x2F040010ull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_ACTION0                             = 0x30040010ull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_ACTION0                             = 0x31040010ull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_ACTION0                             = 0x32040010ull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_ACTION0                             = 0x33040010ull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_ACTION0                             = 0x34040010ull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_ACTION0                             = 0x35040010ull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_ACTION0                             = 0x36040010ull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_ACTION0                             = 0x37040010ull;


static const uint64_t P9N2_PERV_LOCAL_FIR_ACTION1                                  = 0x00040011ull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_ACTION1                               = 0x01040011ull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_ACTION1                               = 0x02040011ull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_ACTION1                               = 0x03040011ull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_ACTION1                               = 0x04040011ull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_ACTION1                               = 0x05040011ull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_ACTION1                               = 0x06040011ull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_ACTION1                             = 0x07040011ull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_ACTION1                             = 0x08040011ull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_ACTION1                              = 0x09040011ull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_ACTION1                              = 0x0C040011ull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_ACTION1                             = 0x0D040011ull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_ACTION1                             = 0x0E040011ull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_ACTION1                             = 0x0F040011ull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_ACTION1                             = 0x10040011ull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_ACTION1                             = 0x11040011ull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_ACTION1                             = 0x12040011ull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_ACTION1                             = 0x13040011ull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_ACTION1                             = 0x14040011ull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_ACTION1                             = 0x15040011ull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_ACTION1                             = 0x20040011ull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_ACTION1                             = 0x21040011ull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_ACTION1                             = 0x22040011ull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_ACTION1                             = 0x23040011ull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_ACTION1                             = 0x24040011ull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_ACTION1                             = 0x25040011ull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_ACTION1                             = 0x26040011ull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_ACTION1                             = 0x27040011ull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_ACTION1                             = 0x28040011ull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_ACTION1                             = 0x29040011ull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_ACTION1                             = 0x2A040011ull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_ACTION1                             = 0x2B040011ull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_ACTION1                             = 0x2C040011ull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_ACTION1                             = 0x2D040011ull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_ACTION1                             = 0x2E040011ull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_ACTION1                             = 0x2F040011ull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_ACTION1                             = 0x30040011ull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_ACTION1                             = 0x31040011ull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_ACTION1                             = 0x32040011ull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_ACTION1                             = 0x33040011ull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_ACTION1                             = 0x34040011ull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_ACTION1                             = 0x35040011ull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_ACTION1                             = 0x36040011ull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_ACTION1                             = 0x37040011ull;


static const uint64_t P9N2_PERV_LOCAL_FIR_MASK                                     = 0x0004000Dull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_MASK                                  = 0x0104000Dull;

static const uint64_t P9N2_PERV_LOCAL_FIR_MASK_AND                                 = 0x0004000Eull;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_MASK_AND                              = 0x0104000Eull;

static const uint64_t P9N2_PERV_LOCAL_FIR_MASK_OR                                  = 0x0004000Full;

static const uint64_t P9N2_PERV_TP_LOCAL_FIR_MASK_OR                               = 0x0104000Full;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_MASK                                  = 0x0204000Dull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_MASK_AND                              = 0x0204000Eull;

static const uint64_t P9N2_PERV_N0_LOCAL_FIR_MASK_OR                               = 0x0204000Full;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_MASK                                  = 0x0304000Dull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_MASK_AND                              = 0x0304000Eull;

static const uint64_t P9N2_PERV_N1_LOCAL_FIR_MASK_OR                               = 0x0304000Full;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_MASK                                  = 0x0404000Dull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_MASK_AND                              = 0x0404000Eull;

static const uint64_t P9N2_PERV_N2_LOCAL_FIR_MASK_OR                               = 0x0404000Full;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_MASK                                  = 0x0504000Dull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_MASK_AND                              = 0x0504000Eull;

static const uint64_t P9N2_PERV_N3_LOCAL_FIR_MASK_OR                               = 0x0504000Full;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_MASK                                  = 0x0604000Dull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_MASK_AND                              = 0x0604000Eull;

static const uint64_t P9N2_PERV_XB_LOCAL_FIR_MASK_OR                               = 0x0604000Full;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_MASK                                = 0x0704000Dull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_MASK_AND                            = 0x0704000Eull;

static const uint64_t P9N2_PERV_MC01_LOCAL_FIR_MASK_OR                             = 0x0704000Full;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_MASK                                = 0x0804000Dull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_MASK_AND                            = 0x0804000Eull;

static const uint64_t P9N2_PERV_MC23_LOCAL_FIR_MASK_OR                             = 0x0804000Full;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_MASK                                 = 0x0904000Dull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_MASK_AND                             = 0x0904000Eull;

static const uint64_t P9N2_PERV_OB0_LOCAL_FIR_MASK_OR                              = 0x0904000Full;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_MASK                                 = 0x0C04000Dull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_MASK_AND                             = 0x0C04000Eull;

static const uint64_t P9N2_PERV_OB3_LOCAL_FIR_MASK_OR                              = 0x0C04000Full;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_MASK                                = 0x0D04000Dull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_MASK_AND                            = 0x0D04000Eull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_FIR_MASK_OR                             = 0x0D04000Full;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_MASK                                = 0x0E04000Dull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_MASK_AND                            = 0x0E04000Eull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_FIR_MASK_OR                             = 0x0E04000Full;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_MASK                                = 0x0F04000Dull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_MASK_AND                            = 0x0F04000Eull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_FIR_MASK_OR                             = 0x0F04000Full;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_MASK                                = 0x1004000Dull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_MASK_AND                            = 0x1004000Eull;

static const uint64_t P9N2_PERV_EP00_LOCAL_FIR_MASK_OR                             = 0x1004000Full;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_MASK                                = 0x1104000Dull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_MASK_AND                            = 0x1104000Eull;

static const uint64_t P9N2_PERV_EP01_LOCAL_FIR_MASK_OR                             = 0x1104000Full;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_MASK                                = 0x1204000Dull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_MASK_AND                            = 0x1204000Eull;

static const uint64_t P9N2_PERV_EP02_LOCAL_FIR_MASK_OR                             = 0x1204000Full;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_MASK                                = 0x1304000Dull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_MASK_AND                            = 0x1304000Eull;

static const uint64_t P9N2_PERV_EP03_LOCAL_FIR_MASK_OR                             = 0x1304000Full;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_MASK                                = 0x1404000Dull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_MASK_AND                            = 0x1404000Eull;

static const uint64_t P9N2_PERV_EP04_LOCAL_FIR_MASK_OR                             = 0x1404000Full;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_MASK                                = 0x1504000Dull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_MASK_AND                            = 0x1504000Eull;

static const uint64_t P9N2_PERV_EP05_LOCAL_FIR_MASK_OR                             = 0x1504000Full;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_MASK                                = 0x2004000Dull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_MASK_AND                            = 0x2004000Eull;

static const uint64_t P9N2_PERV_EC00_LOCAL_FIR_MASK_OR                             = 0x2004000Full;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_MASK                                = 0x2104000Dull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_MASK_AND                            = 0x2104000Eull;

static const uint64_t P9N2_PERV_EC01_LOCAL_FIR_MASK_OR                             = 0x2104000Full;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_MASK                                = 0x2204000Dull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_MASK_AND                            = 0x2204000Eull;

static const uint64_t P9N2_PERV_EC02_LOCAL_FIR_MASK_OR                             = 0x2204000Full;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_MASK                                = 0x2304000Dull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_MASK_AND                            = 0x2304000Eull;

static const uint64_t P9N2_PERV_EC03_LOCAL_FIR_MASK_OR                             = 0x2304000Full;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_MASK                                = 0x2404000Dull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_MASK_AND                            = 0x2404000Eull;

static const uint64_t P9N2_PERV_EC04_LOCAL_FIR_MASK_OR                             = 0x2404000Full;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_MASK                                = 0x2504000Dull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_MASK_AND                            = 0x2504000Eull;

static const uint64_t P9N2_PERV_EC05_LOCAL_FIR_MASK_OR                             = 0x2504000Full;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_MASK                                = 0x2604000Dull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_MASK_AND                            = 0x2604000Eull;

static const uint64_t P9N2_PERV_EC06_LOCAL_FIR_MASK_OR                             = 0x2604000Full;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_MASK                                = 0x2704000Dull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_MASK_AND                            = 0x2704000Eull;

static const uint64_t P9N2_PERV_EC07_LOCAL_FIR_MASK_OR                             = 0x2704000Full;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_MASK                                = 0x2804000Dull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_MASK_AND                            = 0x2804000Eull;

static const uint64_t P9N2_PERV_EC08_LOCAL_FIR_MASK_OR                             = 0x2804000Full;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_MASK                                = 0x2904000Dull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_MASK_AND                            = 0x2904000Eull;

static const uint64_t P9N2_PERV_EC09_LOCAL_FIR_MASK_OR                             = 0x2904000Full;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_MASK                                = 0x2A04000Dull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_MASK_AND                            = 0x2A04000Eull;

static const uint64_t P9N2_PERV_EC10_LOCAL_FIR_MASK_OR                             = 0x2A04000Full;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_MASK                                = 0x2B04000Dull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_MASK_AND                            = 0x2B04000Eull;

static const uint64_t P9N2_PERV_EC11_LOCAL_FIR_MASK_OR                             = 0x2B04000Full;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_MASK                                = 0x2C04000Dull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_MASK_AND                            = 0x2C04000Eull;

static const uint64_t P9N2_PERV_EC12_LOCAL_FIR_MASK_OR                             = 0x2C04000Full;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_MASK                                = 0x2D04000Dull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_MASK_AND                            = 0x2D04000Eull;

static const uint64_t P9N2_PERV_EC13_LOCAL_FIR_MASK_OR                             = 0x2D04000Full;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_MASK                                = 0x2E04000Dull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_MASK_AND                            = 0x2E04000Eull;

static const uint64_t P9N2_PERV_EC14_LOCAL_FIR_MASK_OR                             = 0x2E04000Full;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_MASK                                = 0x2F04000Dull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_MASK_AND                            = 0x2F04000Eull;

static const uint64_t P9N2_PERV_EC15_LOCAL_FIR_MASK_OR                             = 0x2F04000Full;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_MASK                                = 0x3004000Dull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_MASK_AND                            = 0x3004000Eull;

static const uint64_t P9N2_PERV_EC16_LOCAL_FIR_MASK_OR                             = 0x3004000Full;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_MASK                                = 0x3104000Dull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_MASK_AND                            = 0x3104000Eull;

static const uint64_t P9N2_PERV_EC17_LOCAL_FIR_MASK_OR                             = 0x3104000Full;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_MASK                                = 0x3204000Dull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_MASK_AND                            = 0x3204000Eull;

static const uint64_t P9N2_PERV_EC18_LOCAL_FIR_MASK_OR                             = 0x3204000Full;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_MASK                                = 0x3304000Dull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_MASK_AND                            = 0x3304000Eull;

static const uint64_t P9N2_PERV_EC19_LOCAL_FIR_MASK_OR                             = 0x3304000Full;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_MASK                                = 0x3404000Dull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_MASK_AND                            = 0x3404000Eull;

static const uint64_t P9N2_PERV_EC20_LOCAL_FIR_MASK_OR                             = 0x3404000Full;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_MASK                                = 0x3504000Dull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_MASK_AND                            = 0x3504000Eull;

static const uint64_t P9N2_PERV_EC21_LOCAL_FIR_MASK_OR                             = 0x3504000Full;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_MASK                                = 0x3604000Dull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_MASK_AND                            = 0x3604000Eull;

static const uint64_t P9N2_PERV_EC22_LOCAL_FIR_MASK_OR                             = 0x3604000Full;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_MASK                                = 0x3704000Dull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_MASK_AND                            = 0x3704000Eull;

static const uint64_t P9N2_PERV_EC23_LOCAL_FIR_MASK_OR                             = 0x3704000Full;


static const uint64_t P9N2_PERV_LOCAL_XSTOP_ERR                                    = 0x00040018ull;

static const uint64_t P9N2_PERV_TP_LOCAL_XSTOP_ERR                                 = 0x01040018ull;

static const uint64_t P9N2_PERV_N0_LOCAL_XSTOP_ERR                                 = 0x02040018ull;

static const uint64_t P9N2_PERV_N1_LOCAL_XSTOP_ERR                                 = 0x03040018ull;

static const uint64_t P9N2_PERV_N2_LOCAL_XSTOP_ERR                                 = 0x04040018ull;

static const uint64_t P9N2_PERV_N3_LOCAL_XSTOP_ERR                                 = 0x05040018ull;

static const uint64_t P9N2_PERV_XB_LOCAL_XSTOP_ERR                                 = 0x06040018ull;

static const uint64_t P9N2_PERV_MC01_LOCAL_XSTOP_ERR                               = 0x07040018ull;

static const uint64_t P9N2_PERV_MC23_LOCAL_XSTOP_ERR                               = 0x08040018ull;

static const uint64_t P9N2_PERV_OB0_LOCAL_XSTOP_ERR                                = 0x09040018ull;

static const uint64_t P9N2_PERV_OB3_LOCAL_XSTOP_ERR                                = 0x0C040018ull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_XSTOP_ERR                               = 0x0D040018ull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_XSTOP_ERR                               = 0x0E040018ull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_XSTOP_ERR                               = 0x0F040018ull;

static const uint64_t P9N2_PERV_EP00_LOCAL_XSTOP_ERR                               = 0x10040018ull;

static const uint64_t P9N2_PERV_EP01_LOCAL_XSTOP_ERR                               = 0x11040018ull;

static const uint64_t P9N2_PERV_EP02_LOCAL_XSTOP_ERR                               = 0x12040018ull;

static const uint64_t P9N2_PERV_EP03_LOCAL_XSTOP_ERR                               = 0x13040018ull;

static const uint64_t P9N2_PERV_EP04_LOCAL_XSTOP_ERR                               = 0x14040018ull;

static const uint64_t P9N2_PERV_EP05_LOCAL_XSTOP_ERR                               = 0x15040018ull;

static const uint64_t P9N2_PERV_EC00_LOCAL_XSTOP_ERR                               = 0x20040018ull;

static const uint64_t P9N2_PERV_EC01_LOCAL_XSTOP_ERR                               = 0x21040018ull;

static const uint64_t P9N2_PERV_EC02_LOCAL_XSTOP_ERR                               = 0x22040018ull;

static const uint64_t P9N2_PERV_EC03_LOCAL_XSTOP_ERR                               = 0x23040018ull;

static const uint64_t P9N2_PERV_EC04_LOCAL_XSTOP_ERR                               = 0x24040018ull;

static const uint64_t P9N2_PERV_EC05_LOCAL_XSTOP_ERR                               = 0x25040018ull;

static const uint64_t P9N2_PERV_EC06_LOCAL_XSTOP_ERR                               = 0x26040018ull;

static const uint64_t P9N2_PERV_EC07_LOCAL_XSTOP_ERR                               = 0x27040018ull;

static const uint64_t P9N2_PERV_EC08_LOCAL_XSTOP_ERR                               = 0x28040018ull;

static const uint64_t P9N2_PERV_EC09_LOCAL_XSTOP_ERR                               = 0x29040018ull;

static const uint64_t P9N2_PERV_EC10_LOCAL_XSTOP_ERR                               = 0x2A040018ull;

static const uint64_t P9N2_PERV_EC11_LOCAL_XSTOP_ERR                               = 0x2B040018ull;

static const uint64_t P9N2_PERV_EC12_LOCAL_XSTOP_ERR                               = 0x2C040018ull;

static const uint64_t P9N2_PERV_EC13_LOCAL_XSTOP_ERR                               = 0x2D040018ull;

static const uint64_t P9N2_PERV_EC14_LOCAL_XSTOP_ERR                               = 0x2E040018ull;

static const uint64_t P9N2_PERV_EC15_LOCAL_XSTOP_ERR                               = 0x2F040018ull;

static const uint64_t P9N2_PERV_EC16_LOCAL_XSTOP_ERR                               = 0x30040018ull;

static const uint64_t P9N2_PERV_EC17_LOCAL_XSTOP_ERR                               = 0x31040018ull;

static const uint64_t P9N2_PERV_EC18_LOCAL_XSTOP_ERR                               = 0x32040018ull;

static const uint64_t P9N2_PERV_EC19_LOCAL_XSTOP_ERR                               = 0x33040018ull;

static const uint64_t P9N2_PERV_EC20_LOCAL_XSTOP_ERR                               = 0x34040018ull;

static const uint64_t P9N2_PERV_EC21_LOCAL_XSTOP_ERR                               = 0x35040018ull;

static const uint64_t P9N2_PERV_EC22_LOCAL_XSTOP_ERR                               = 0x36040018ull;

static const uint64_t P9N2_PERV_EC23_LOCAL_XSTOP_ERR                               = 0x37040018ull;


static const uint64_t P9N2_PERV_LOCAL_XSTOP_MASK                                   = 0x00040019ull;

static const uint64_t P9N2_PERV_TP_LOCAL_XSTOP_MASK                                = 0x01040019ull;

static const uint64_t P9N2_PERV_N0_LOCAL_XSTOP_MASK                                = 0x02040019ull;

static const uint64_t P9N2_PERV_N1_LOCAL_XSTOP_MASK                                = 0x03040019ull;

static const uint64_t P9N2_PERV_N2_LOCAL_XSTOP_MASK                                = 0x04040019ull;

static const uint64_t P9N2_PERV_N3_LOCAL_XSTOP_MASK                                = 0x05040019ull;

static const uint64_t P9N2_PERV_XB_LOCAL_XSTOP_MASK                                = 0x06040019ull;

static const uint64_t P9N2_PERV_MC01_LOCAL_XSTOP_MASK                              = 0x07040019ull;

static const uint64_t P9N2_PERV_MC23_LOCAL_XSTOP_MASK                              = 0x08040019ull;

static const uint64_t P9N2_PERV_OB0_LOCAL_XSTOP_MASK                               = 0x09040019ull;

static const uint64_t P9N2_PERV_OB3_LOCAL_XSTOP_MASK                               = 0x0C040019ull;

static const uint64_t P9N2_PERV_PCI0_LOCAL_XSTOP_MASK                              = 0x0D040019ull;

static const uint64_t P9N2_PERV_PCI1_LOCAL_XSTOP_MASK                              = 0x0E040019ull;

static const uint64_t P9N2_PERV_PCI2_LOCAL_XSTOP_MASK                              = 0x0F040019ull;

static const uint64_t P9N2_PERV_EP00_LOCAL_XSTOP_MASK                              = 0x10040019ull;

static const uint64_t P9N2_PERV_EP01_LOCAL_XSTOP_MASK                              = 0x11040019ull;

static const uint64_t P9N2_PERV_EP02_LOCAL_XSTOP_MASK                              = 0x12040019ull;

static const uint64_t P9N2_PERV_EP03_LOCAL_XSTOP_MASK                              = 0x13040019ull;

static const uint64_t P9N2_PERV_EP04_LOCAL_XSTOP_MASK                              = 0x14040019ull;

static const uint64_t P9N2_PERV_EP05_LOCAL_XSTOP_MASK                              = 0x15040019ull;

static const uint64_t P9N2_PERV_EC00_LOCAL_XSTOP_MASK                              = 0x20040019ull;

static const uint64_t P9N2_PERV_EC01_LOCAL_XSTOP_MASK                              = 0x21040019ull;

static const uint64_t P9N2_PERV_EC02_LOCAL_XSTOP_MASK                              = 0x22040019ull;

static const uint64_t P9N2_PERV_EC03_LOCAL_XSTOP_MASK                              = 0x23040019ull;

static const uint64_t P9N2_PERV_EC04_LOCAL_XSTOP_MASK                              = 0x24040019ull;

static const uint64_t P9N2_PERV_EC05_LOCAL_XSTOP_MASK                              = 0x25040019ull;

static const uint64_t P9N2_PERV_EC06_LOCAL_XSTOP_MASK                              = 0x26040019ull;

static const uint64_t P9N2_PERV_EC07_LOCAL_XSTOP_MASK                              = 0x27040019ull;

static const uint64_t P9N2_PERV_EC08_LOCAL_XSTOP_MASK                              = 0x28040019ull;

static const uint64_t P9N2_PERV_EC09_LOCAL_XSTOP_MASK                              = 0x29040019ull;

static const uint64_t P9N2_PERV_EC10_LOCAL_XSTOP_MASK                              = 0x2A040019ull;

static const uint64_t P9N2_PERV_EC11_LOCAL_XSTOP_MASK                              = 0x2B040019ull;

static const uint64_t P9N2_PERV_EC12_LOCAL_XSTOP_MASK                              = 0x2C040019ull;

static const uint64_t P9N2_PERV_EC13_LOCAL_XSTOP_MASK                              = 0x2D040019ull;

static const uint64_t P9N2_PERV_EC14_LOCAL_XSTOP_MASK                              = 0x2E040019ull;

static const uint64_t P9N2_PERV_EC15_LOCAL_XSTOP_MASK                              = 0x2F040019ull;

static const uint64_t P9N2_PERV_EC16_LOCAL_XSTOP_MASK                              = 0x30040019ull;

static const uint64_t P9N2_PERV_EC17_LOCAL_XSTOP_MASK                              = 0x31040019ull;

static const uint64_t P9N2_PERV_EC18_LOCAL_XSTOP_MASK                              = 0x32040019ull;

static const uint64_t P9N2_PERV_EC19_LOCAL_XSTOP_MASK                              = 0x33040019ull;

static const uint64_t P9N2_PERV_EC20_LOCAL_XSTOP_MASK                              = 0x34040019ull;

static const uint64_t P9N2_PERV_EC21_LOCAL_XSTOP_MASK                              = 0x35040019ull;

static const uint64_t P9N2_PERV_EC22_LOCAL_XSTOP_MASK                              = 0x36040019ull;

static const uint64_t P9N2_PERV_EC23_LOCAL_XSTOP_MASK                              = 0x37040019ull;


static const uint64_t P9N2_PERV_LSTAT                                              = 0x00030002ull;

static const uint64_t P9N2_PERV_PIB_LSTAT                                          = 0x00030002ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_LSTAT                                   = 0x00020002ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_LSTAT                                   = 0x00020012ull;

static const uint64_t P9N2_PERV_PIB2OPB0_LSTAT                                     = 0x00020002ull;

static const uint64_t P9N2_PERV_PIB2OPB1_LSTAT                                     = 0x00020012ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_0_FSI                                = 0x00002840ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_0_FSI_BYTE                           = 0x00002900ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_0_SCOM                               = 0x00050040ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_0                                = 0x00050040ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_1_FSI                                = 0x00002841ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_1_FSI_BYTE                           = 0x00002904ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_1_SCOM                               = 0x00050041ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_1                                = 0x00050041ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_10_FSI                               = 0x0000284Aull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_10_FSI_BYTE                          = 0x00002928ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_10_SCOM                              = 0x0005004Aull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_10                               = 0x0005004Aull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_11_FSI                               = 0x0000284Bull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_11_FSI_BYTE                          = 0x0000292Cull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_11_SCOM                              = 0x0005004Bull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_11                               = 0x0005004Bull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_12_FSI                               = 0x0000284Cull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_12_FSI_BYTE                          = 0x00002930ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_12_SCOM                              = 0x0005004Cull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_12                               = 0x0005004Cull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_13_FSI                               = 0x0000284Dull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_13_FSI_BYTE                          = 0x00002934ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_13_SCOM                              = 0x0005004Dull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_13                               = 0x0005004Dull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_14_FSI                               = 0x0000284Eull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_14_FSI_BYTE                          = 0x00002938ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_14_SCOM                              = 0x0005004Eull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_14                               = 0x0005004Eull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_15_FSI                               = 0x0000284Full;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_15_FSI_BYTE                          = 0x0000293Cull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_15_SCOM                              = 0x0005004Full;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_15                               = 0x0005004Full;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_2_FSI                                = 0x00002842ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_2_FSI_BYTE                           = 0x00002908ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_2_SCOM                               = 0x00050042ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_2                                = 0x00050042ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_3_FSI                                = 0x00002843ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_3_FSI_BYTE                           = 0x0000290Cull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_3_SCOM                               = 0x00050043ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_3                                = 0x00050043ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_4_FSI                                = 0x00002844ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_4_FSI_BYTE                           = 0x00002910ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_4_SCOM                               = 0x00050044ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_4                                = 0x00050044ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_5_FSI                                = 0x00002845ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_5_FSI_BYTE                           = 0x00002914ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_5_SCOM                               = 0x00050045ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_5                                = 0x00050045ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_6_FSI                                = 0x00002846ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_6_FSI_BYTE                           = 0x00002918ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_6_SCOM                               = 0x00050046ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_6                                = 0x00050046ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_7_FSI                                = 0x00002847ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_7_FSI_BYTE                           = 0x0000291Cull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_7_SCOM                               = 0x00050047ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_7                                = 0x00050047ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_8_FSI                                = 0x00002848ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_8_FSI_BYTE                           = 0x00002920ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_8_SCOM                               = 0x00050048ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_8                                = 0x00050048ull;


static const uint32_t P9N2_PERV_M1A_DATA_AREA_9_FSI                                = 0x00002849ull;

static const uint32_t P9N2_PERV_M1A_DATA_AREA_9_FSI_BYTE                           = 0x00002924ull;

static const uint64_t P9N2_PERV_M1A_DATA_AREA_9_SCOM                               = 0x00050049ull;

static const uint64_t P9N2_PERV_PIB_M1A_DATA_AREA_9                                = 0x00050049ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_0_FSI                                = 0x00002880ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_0_FSI_BYTE                           = 0x00002A00ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_0_SCOM                               = 0x00050080ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_0                                = 0x00050080ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_1_FSI                                = 0x00002881ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_1_FSI_BYTE                           = 0x00002A04ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_1_SCOM                               = 0x00050081ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_1                                = 0x00050081ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_10_FSI                               = 0x0000288Aull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_10_FSI_BYTE                          = 0x00002A28ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_10_SCOM                              = 0x0005008Aull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_10                               = 0x0005008Aull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_11_FSI                               = 0x0000288Bull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_11_FSI_BYTE                          = 0x00002A2Cull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_11_SCOM                              = 0x0005008Bull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_11                               = 0x0005008Bull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_12_FSI                               = 0x0000288Cull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_12_FSI_BYTE                          = 0x00002A30ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_12_SCOM                              = 0x0005008Cull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_12                               = 0x0005008Cull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_13_FSI                               = 0x0000288Dull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_13_FSI_BYTE                          = 0x00002A34ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_13_SCOM                              = 0x0005008Dull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_13                               = 0x0005008Dull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_14_FSI                               = 0x0000288Eull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_14_FSI_BYTE                          = 0x00002A38ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_14_SCOM                              = 0x0005008Eull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_14                               = 0x0005008Eull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_15_FSI                               = 0x0000288Full;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_15_FSI_BYTE                          = 0x00002A3Cull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_15_SCOM                              = 0x0005008Full;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_15                               = 0x0005008Full;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_2_FSI                                = 0x00002882ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_2_FSI_BYTE                           = 0x00002A08ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_2_SCOM                               = 0x00050082ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_2                                = 0x00050082ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_3_FSI                                = 0x00002883ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_3_FSI_BYTE                           = 0x00002A0Cull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_3_SCOM                               = 0x00050083ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_3                                = 0x00050083ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_4_FSI                                = 0x00002884ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_4_FSI_BYTE                           = 0x00002A10ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_4_SCOM                               = 0x00050084ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_4                                = 0x00050084ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_5_FSI                                = 0x00002885ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_5_FSI_BYTE                           = 0x00002A14ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_5_SCOM                               = 0x00050085ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_5                                = 0x00050085ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_6_FSI                                = 0x00002886ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_6_FSI_BYTE                           = 0x00002A18ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_6_SCOM                               = 0x00050086ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_6                                = 0x00050086ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_7_FSI                                = 0x00002887ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_7_FSI_BYTE                           = 0x00002A1Cull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_7_SCOM                               = 0x00050087ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_7                                = 0x00050087ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_8_FSI                                = 0x00002888ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_8_FSI_BYTE                           = 0x00002A20ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_8_SCOM                               = 0x00050088ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_8                                = 0x00050088ull;


static const uint32_t P9N2_PERV_M1B_DATA_AREA_9_FSI                                = 0x00002889ull;

static const uint32_t P9N2_PERV_M1B_DATA_AREA_9_FSI_BYTE                           = 0x00002A24ull;

static const uint64_t P9N2_PERV_M1B_DATA_AREA_9_SCOM                               = 0x00050089ull;

static const uint64_t P9N2_PERV_PIB_M1B_DATA_AREA_9                                = 0x00050089ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_0_FSI                                = 0x000028C0ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_0_FSI_BYTE                           = 0x00002B00ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_0_SCOM                               = 0x000500C0ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_0                                = 0x000500C0ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_1_FSI                                = 0x000028C1ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_1_FSI_BYTE                           = 0x00002B04ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_1_SCOM                               = 0x000500C1ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_1                                = 0x000500C1ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_10_FSI                               = 0x000028CAull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_10_FSI_BYTE                          = 0x00002B28ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_10_SCOM                              = 0x000500CAull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_10                               = 0x000500CAull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_11_FSI                               = 0x000028CBull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_11_FSI_BYTE                          = 0x00002B2Cull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_11_SCOM                              = 0x000500CBull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_11                               = 0x000500CBull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_12_FSI                               = 0x000028CCull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_12_FSI_BYTE                          = 0x00002B30ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_12_SCOM                              = 0x000500CCull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_12                               = 0x000500CCull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_13_FSI                               = 0x000028CDull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_13_FSI_BYTE                          = 0x00002B34ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_13_SCOM                              = 0x000500CDull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_13                               = 0x000500CDull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_14_FSI                               = 0x000028CEull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_14_FSI_BYTE                          = 0x00002B38ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_14_SCOM                              = 0x000500CEull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_14                               = 0x000500CEull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_15_FSI                               = 0x000028CFull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_15_FSI_BYTE                          = 0x00002B3Cull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_15_SCOM                              = 0x000500CFull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_15                               = 0x000500CFull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_2_FSI                                = 0x000028C2ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_2_FSI_BYTE                           = 0x00002B08ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_2_SCOM                               = 0x000500C2ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_2                                = 0x000500C2ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_3_FSI                                = 0x000028C3ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_3_FSI_BYTE                           = 0x00002B0Cull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_3_SCOM                               = 0x000500C3ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_3                                = 0x000500C3ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_4_FSI                                = 0x000028C4ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_4_FSI_BYTE                           = 0x00002B10ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_4_SCOM                               = 0x000500C4ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_4                                = 0x000500C4ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_5_FSI                                = 0x000028C5ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_5_FSI_BYTE                           = 0x00002B14ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_5_SCOM                               = 0x000500C5ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_5                                = 0x000500C5ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_6_FSI                                = 0x000028C6ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_6_FSI_BYTE                           = 0x00002B18ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_6_SCOM                               = 0x000500C6ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_6                                = 0x000500C6ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_7_FSI                                = 0x000028C7ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_7_FSI_BYTE                           = 0x00002B1Cull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_7_SCOM                               = 0x000500C7ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_7                                = 0x000500C7ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_8_FSI                                = 0x000028C8ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_8_FSI_BYTE                           = 0x00002B20ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_8_SCOM                               = 0x000500C8ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_8                                = 0x000500C8ull;


static const uint32_t P9N2_PERV_M2A_DATA_AREA_9_FSI                                = 0x000028C9ull;

static const uint32_t P9N2_PERV_M2A_DATA_AREA_9_FSI_BYTE                           = 0x00002B24ull;

static const uint64_t P9N2_PERV_M2A_DATA_AREA_9_SCOM                               = 0x000500C9ull;

static const uint64_t P9N2_PERV_PIB_M2A_DATA_AREA_9                                = 0x000500C9ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_0_FSI                                = 0x00002900ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_0_FSI_BYTE                           = 0x00002C00ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_0_SCOM                               = 0x00050100ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_0                                = 0x00050100ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_1_FSI                                = 0x00002901ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_1_FSI_BYTE                           = 0x00002C04ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_1_SCOM                               = 0x00050101ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_1                                = 0x00050101ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_10_FSI                               = 0x0000290Aull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_10_FSI_BYTE                          = 0x00002C28ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_10_SCOM                              = 0x0005010Aull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_10                               = 0x0005010Aull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_11_FSI                               = 0x0000290Bull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_11_FSI_BYTE                          = 0x00002C2Cull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_11_SCOM                              = 0x0005010Bull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_11                               = 0x0005010Bull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_12_FSI                               = 0x0000290Cull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_12_FSI_BYTE                          = 0x00002C30ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_12_SCOM                              = 0x0005010Cull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_12                               = 0x0005010Cull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_13_FSI                               = 0x0000290Dull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_13_FSI_BYTE                          = 0x00002C34ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_13_SCOM                              = 0x0005010Dull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_13                               = 0x0005010Dull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_14_FSI                               = 0x0000290Eull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_14_FSI_BYTE                          = 0x00002C38ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_14_SCOM                              = 0x0005010Eull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_14                               = 0x0005010Eull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_15_FSI                               = 0x0000290Full;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_15_FSI_BYTE                          = 0x00002C3Cull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_15_SCOM                              = 0x0005010Full;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_15                               = 0x0005010Full;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_2_FSI                                = 0x00002902ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_2_FSI_BYTE                           = 0x00002C08ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_2_SCOM                               = 0x00050102ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_2                                = 0x00050102ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_3_FSI                                = 0x00002903ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_3_FSI_BYTE                           = 0x00002C0Cull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_3_SCOM                               = 0x00050103ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_3                                = 0x00050103ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_4_FSI                                = 0x00002904ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_4_FSI_BYTE                           = 0x00002C10ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_4_SCOM                               = 0x00050104ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_4                                = 0x00050104ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_5_FSI                                = 0x00002905ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_5_FSI_BYTE                           = 0x00002C14ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_5_SCOM                               = 0x00050105ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_5                                = 0x00050105ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_6_FSI                                = 0x00002906ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_6_FSI_BYTE                           = 0x00002C18ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_6_SCOM                               = 0x00050106ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_6                                = 0x00050106ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_7_FSI                                = 0x00002907ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_7_FSI_BYTE                           = 0x00002C1Cull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_7_SCOM                               = 0x00050107ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_7                                = 0x00050107ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_8_FSI                                = 0x00002908ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_8_FSI_BYTE                           = 0x00002C20ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_8_SCOM                               = 0x00050108ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_8                                = 0x00050108ull;


static const uint32_t P9N2_PERV_M2B_DATA_AREA_9_FSI                                = 0x00002909ull;

static const uint32_t P9N2_PERV_M2B_DATA_AREA_9_FSI_BYTE                           = 0x00002C24ull;

static const uint64_t P9N2_PERV_M2B_DATA_AREA_9_SCOM                               = 0x00050109ull;

static const uint64_t P9N2_PERV_PIB_M2B_DATA_AREA_9                                = 0x00050109ull;


static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_0_A_FSI                   = 0x00002821ull;

static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_0_A_FSI_BYTE              = 0x00002884ull;

static const uint64_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_0_A_SCOM                  = 0x00050021ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_HEADER_COMMAND_0_A                   = 0x00050021ull;


static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_0_B_FSI                   = 0x00002825ull;

static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_0_B_FSI_BYTE              = 0x00002894ull;

static const uint64_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_0_B_SCOM                  = 0x00050025ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_HEADER_COMMAND_0_B                   = 0x00050025ull;


static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_1_A_FSI                   = 0x00002822ull;

static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_1_A_FSI_BYTE              = 0x00002888ull;

static const uint64_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_1_A_SCOM                  = 0x00050022ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_HEADER_COMMAND_1_A                   = 0x00050022ull;


static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_1_B_FSI                   = 0x00002826ull;

static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_1_B_FSI_BYTE              = 0x00002898ull;

static const uint64_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_1_B_SCOM                  = 0x00050026ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_HEADER_COMMAND_1_B                   = 0x00050026ull;


static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_2_A_FSI                   = 0x00002823ull;

static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_2_A_FSI_BYTE              = 0x0000288Cull;

static const uint64_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_2_A_SCOM                  = 0x00050023ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_HEADER_COMMAND_2_A                   = 0x00050023ull;


static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_2_B_FSI                   = 0x00002827ull;

static const uint32_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_2_B_FSI_BYTE              = 0x0000289Cull;

static const uint64_t P9N2_PERV_MAILBOX_1_HEADER_COMMAND_2_B_SCOM                  = 0x00050027ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_HEADER_COMMAND_2_B                   = 0x00050027ull;


static const uint32_t P9N2_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_FSI    = 0x00002833ull;

static const uint32_t P9N2_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_FSI_BYTE = 0x000028CCull;

static const uint64_t P9N2_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_SCOM   = 0x00050033ull;

static const uint64_t P9N2_PERV_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_SCOM1  = 0x00050034ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_WOR = 0x00050033ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_1_CLEAR = 0x00050034ull;


static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_0_A_FSI                   = 0x00002829ull;

static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_0_A_FSI_BYTE              = 0x000028A4ull;

static const uint64_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_0_A_SCOM                  = 0x00050029ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_2_HEADER_COMMAND_0_A                   = 0x00050029ull;


static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_0_B_FSI                   = 0x0000282Dull;

static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_0_B_FSI_BYTE              = 0x000028B4ull;

static const uint64_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_0_B_SCOM                  = 0x0005002Dull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_2_HEADER_COMMAND_0_B                   = 0x0005002Dull;


static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_1_A_FSI                   = 0x0000282Aull;

static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_1_A_FSI_BYTE              = 0x000028A8ull;

static const uint64_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_1_A_SCOM                  = 0x0005002Aull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_2_HEADER_COMMAND_1_A                   = 0x0005002Aull;


static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_1_B_FSI                   = 0x0000282Eull;

static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE              = 0x000028B8ull;

static const uint64_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_1_B_SCOM                  = 0x0005002Eull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_2_HEADER_COMMAND_1_B                   = 0x0005002Eull;


static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_2_A_FSI                   = 0x0000282Bull;

static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_2_A_FSI_BYTE              = 0x000028ACull;

static const uint64_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_2_A_SCOM                  = 0x0005002Bull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_2_HEADER_COMMAND_2_A                   = 0x0005002Bull;


static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_2_B_FSI                   = 0x0000282Full;

static const uint32_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_2_B_FSI_BYTE              = 0x000028BCull;

static const uint64_t P9N2_PERV_MAILBOX_2_HEADER_COMMAND_2_B_SCOM                  = 0x0005002Full;

static const uint64_t P9N2_PERV_PIB_MAILBOX_2_HEADER_COMMAND_2_B                   = 0x0005002Full;


static const uint32_t P9N2_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_FSI          = 0x00002831ull;

static const uint32_t P9N2_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_FSI_BYTE     = 0x000028C4ull;

static const uint64_t P9N2_PERV_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS_SCOM         = 0x00050031ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_SLAVE_A_DOORBELL_ERROR_STATUS          = 0x00050031ull;


static const uint32_t P9N2_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI             = 0x00002832ull;

static const uint32_t P9N2_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE        = 0x000028C8ull;

static const uint64_t P9N2_PERV_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_SCOM            = 0x00050032ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT             = 0x00050032ull;


static const uint32_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_FSI          = 0x00002830ull;

static const uint32_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_FSI_BYTE     = 0x000028C0ull;

static const uint64_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_SCOM         = 0x00050030ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS          = 0x00050030ull;


static const uint32_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_FSI             = 0x00002835ull;

static const uint32_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_FSI_BYTE        = 0x000028D4ull;

static const uint64_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_SCOM            = 0x00050035ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT             = 0x00050035ull;


static const uint32_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_FSI      = 0x00002836ull;

static const uint64_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_FSI0     = 0x00002837ull;

static const uint32_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_FSI_BYTE = 0x000028D8ull;

static const uint64_t P9N2_PERV_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_SCOM     = 0x00050036ull;

static const uint64_t P9N2_PERV_PIB_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1      = 0x00050036ull;


static const uint64_t P9N2_PERV_MCAST_COMP_MASK_REG                                = 0x000F0017ull;

static const uint64_t P9N2_PERV_PIB_MCAST_COMP_MASK_REG                            = 0x000F0017ull;


static const uint64_t P9N2_PERV_MCAST_COMP_REG                                     = 0x000F0015ull;

static const uint64_t P9N2_PERV_PIB_MCAST_COMP_REG                                 = 0x000F0015ull;


static const uint64_t P9N2_PERV_MCAST_COMP_VAL_REG                                 = 0x000F0016ull;

static const uint64_t P9N2_PERV_PIB_MCAST_COMP_VAL_REG                             = 0x000F0016ull;


static const uint64_t P9N2_PERV_MCAST_GRP_0_SLAVES_REG                             = 0x000F0000ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_0_SLAVES_REG                         = 0x000F0000ull;


static const uint64_t P9N2_PERV_MCAST_GRP_1_SLAVES_REG                             = 0x000F0001ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_1_SLAVES_REG                         = 0x000F0001ull;


static const uint64_t P9N2_PERV_MCAST_GRP_2_SLAVES_REG                             = 0x000F0002ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_2_SLAVES_REG                         = 0x000F0002ull;


static const uint64_t P9N2_PERV_MCAST_GRP_3_SLAVES_REG                             = 0x000F0003ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_3_SLAVES_REG                         = 0x000F0003ull;


static const uint64_t P9N2_PERV_MCAST_GRP_4_SLAVES_REG                             = 0x000F0004ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_4_SLAVES_REG                         = 0x000F0004ull;


static const uint64_t P9N2_PERV_MCAST_GRP_5_SLAVES_REG                             = 0x000F0005ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_5_SLAVES_REG                         = 0x000F0005ull;


static const uint64_t P9N2_PERV_MCAST_GRP_6_SLAVES_REG                             = 0x000F0006ull;

static const uint64_t P9N2_PERV_PIB_MCAST_GRP_6_SLAVES_REG                         = 0x000F0006ull;


static const uint64_t P9N2_PERV_MODE_REG                                           = 0x00040008ull;

static const uint64_t P9N2_PERV_TP_MODE_REG                                        = 0x01040008ull;

static const uint64_t P9N2_PERV_N0_MODE_REG                                        = 0x02040008ull;

static const uint64_t P9N2_PERV_N1_MODE_REG                                        = 0x03040008ull;

static const uint64_t P9N2_PERV_N2_MODE_REG                                        = 0x04040008ull;

static const uint64_t P9N2_PERV_N3_MODE_REG                                        = 0x05040008ull;

static const uint64_t P9N2_PERV_XB_MODE_REG                                        = 0x06040008ull;

static const uint64_t P9N2_PERV_MC01_MODE_REG                                      = 0x07040008ull;

static const uint64_t P9N2_PERV_MC23_MODE_REG                                      = 0x08040008ull;

static const uint64_t P9N2_PERV_OB0_MODE_REG                                       = 0x09040008ull;

static const uint64_t P9N2_PERV_OB3_MODE_REG                                       = 0x0C040008ull;

static const uint64_t P9N2_PERV_PCI0_MODE_REG                                      = 0x0D040008ull;

static const uint64_t P9N2_PERV_PCI1_MODE_REG                                      = 0x0E040008ull;

static const uint64_t P9N2_PERV_PCI2_MODE_REG                                      = 0x0F040008ull;

static const uint64_t P9N2_PERV_EP00_MODE_REG                                      = 0x10040008ull;

static const uint64_t P9N2_PERV_EP01_MODE_REG                                      = 0x11040008ull;

static const uint64_t P9N2_PERV_EP02_MODE_REG                                      = 0x12040008ull;

static const uint64_t P9N2_PERV_EP03_MODE_REG                                      = 0x13040008ull;

static const uint64_t P9N2_PERV_EP04_MODE_REG                                      = 0x14040008ull;

static const uint64_t P9N2_PERV_EP05_MODE_REG                                      = 0x15040008ull;

static const uint64_t P9N2_PERV_EC00_MODE_REG                                      = 0x20040008ull;

static const uint64_t P9N2_PERV_EC01_MODE_REG                                      = 0x21040008ull;

static const uint64_t P9N2_PERV_EC02_MODE_REG                                      = 0x22040008ull;

static const uint64_t P9N2_PERV_EC03_MODE_REG                                      = 0x23040008ull;

static const uint64_t P9N2_PERV_EC04_MODE_REG                                      = 0x24040008ull;

static const uint64_t P9N2_PERV_EC05_MODE_REG                                      = 0x25040008ull;

static const uint64_t P9N2_PERV_EC06_MODE_REG                                      = 0x26040008ull;

static const uint64_t P9N2_PERV_EC07_MODE_REG                                      = 0x27040008ull;

static const uint64_t P9N2_PERV_EC08_MODE_REG                                      = 0x28040008ull;

static const uint64_t P9N2_PERV_EC09_MODE_REG                                      = 0x29040008ull;

static const uint64_t P9N2_PERV_EC10_MODE_REG                                      = 0x2A040008ull;

static const uint64_t P9N2_PERV_EC11_MODE_REG                                      = 0x2B040008ull;

static const uint64_t P9N2_PERV_EC12_MODE_REG                                      = 0x2C040008ull;

static const uint64_t P9N2_PERV_EC13_MODE_REG                                      = 0x2D040008ull;

static const uint64_t P9N2_PERV_EC14_MODE_REG                                      = 0x2E040008ull;

static const uint64_t P9N2_PERV_EC15_MODE_REG                                      = 0x2F040008ull;

static const uint64_t P9N2_PERV_EC16_MODE_REG                                      = 0x30040008ull;

static const uint64_t P9N2_PERV_EC17_MODE_REG                                      = 0x31040008ull;

static const uint64_t P9N2_PERV_EC18_MODE_REG                                      = 0x32040008ull;

static const uint64_t P9N2_PERV_EC19_MODE_REG                                      = 0x33040008ull;

static const uint64_t P9N2_PERV_EC20_MODE_REG                                      = 0x34040008ull;

static const uint64_t P9N2_PERV_EC21_MODE_REG                                      = 0x35040008ull;

static const uint64_t P9N2_PERV_EC22_MODE_REG                                      = 0x36040008ull;

static const uint64_t P9N2_PERV_EC23_MODE_REG                                      = 0x37040008ull;


static const uint64_t P9N2_PERV_0_FSII2C_MODE_REGISTER_A                           = 0x00001802ull;

static const uint32_t P9N2_PERV_FSII2C_MODE_REGISTER_A                             = 0x00001802ull;


static const uint64_t P9N2_PERV_MULTICAST_GROUP_1                                  = 0x000F0001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_MULTICAST_GROUP_1                               = 0x010F0001ull;

static const uint64_t P9N2_PERV_N0_MULTICAST_GROUP_1                               = 0x020F0001ull;

static const uint64_t P9N2_PERV_N1_MULTICAST_GROUP_1                               = 0x030F0001ull;

static const uint64_t P9N2_PERV_N2_MULTICAST_GROUP_1                               = 0x040F0001ull;

static const uint64_t P9N2_PERV_N3_MULTICAST_GROUP_1                               = 0x050F0001ull;

static const uint64_t P9N2_PERV_XB_MULTICAST_GROUP_1                               = 0x060F0001ull;

static const uint64_t P9N2_PERV_MC01_MULTICAST_GROUP_1                             = 0x070F0001ull;

static const uint64_t P9N2_PERV_MC23_MULTICAST_GROUP_1                             = 0x080F0001ull;

static const uint64_t P9N2_PERV_OB0_MULTICAST_GROUP_1                              = 0x090F0001ull;

static const uint64_t P9N2_PERV_OB3_MULTICAST_GROUP_1                              = 0x0C0F0001ull;

static const uint64_t P9N2_PERV_PCI0_MULTICAST_GROUP_1                             = 0x0D0F0001ull;

static const uint64_t P9N2_PERV_PCI1_MULTICAST_GROUP_1                             = 0x0E0F0001ull;

static const uint64_t P9N2_PERV_PCI2_MULTICAST_GROUP_1                             = 0x0F0F0001ull;

static const uint64_t P9N2_PERV_EP00_MULTICAST_GROUP_1                             = 0x100F0001ull;

static const uint64_t P9N2_PERV_EP01_MULTICAST_GROUP_1                             = 0x110F0001ull;

static const uint64_t P9N2_PERV_EP02_MULTICAST_GROUP_1                             = 0x120F0001ull;

static const uint64_t P9N2_PERV_EP03_MULTICAST_GROUP_1                             = 0x130F0001ull;

static const uint64_t P9N2_PERV_EP04_MULTICAST_GROUP_1                             = 0x140F0001ull;

static const uint64_t P9N2_PERV_EP05_MULTICAST_GROUP_1                             = 0x150F0001ull;

static const uint64_t P9N2_PERV_EC00_MULTICAST_GROUP_1                             = 0x200F0001ull;

static const uint64_t P9N2_PERV_EC01_MULTICAST_GROUP_1                             = 0x210F0001ull;

static const uint64_t P9N2_PERV_EC02_MULTICAST_GROUP_1                             = 0x220F0001ull;

static const uint64_t P9N2_PERV_EC03_MULTICAST_GROUP_1                             = 0x230F0001ull;

static const uint64_t P9N2_PERV_EC04_MULTICAST_GROUP_1                             = 0x240F0001ull;

static const uint64_t P9N2_PERV_EC05_MULTICAST_GROUP_1                             = 0x250F0001ull;

static const uint64_t P9N2_PERV_EC06_MULTICAST_GROUP_1                             = 0x260F0001ull;

static const uint64_t P9N2_PERV_EC07_MULTICAST_GROUP_1                             = 0x270F0001ull;

static const uint64_t P9N2_PERV_EC08_MULTICAST_GROUP_1                             = 0x280F0001ull;

static const uint64_t P9N2_PERV_EC09_MULTICAST_GROUP_1                             = 0x290F0001ull;

static const uint64_t P9N2_PERV_EC10_MULTICAST_GROUP_1                             = 0x2A0F0001ull;

static const uint64_t P9N2_PERV_EC11_MULTICAST_GROUP_1                             = 0x2B0F0001ull;

static const uint64_t P9N2_PERV_EC12_MULTICAST_GROUP_1                             = 0x2C0F0001ull;

static const uint64_t P9N2_PERV_EC13_MULTICAST_GROUP_1                             = 0x2D0F0001ull;

static const uint64_t P9N2_PERV_EC14_MULTICAST_GROUP_1                             = 0x2E0F0001ull;

static const uint64_t P9N2_PERV_EC15_MULTICAST_GROUP_1                             = 0x2F0F0001ull;

static const uint64_t P9N2_PERV_EC16_MULTICAST_GROUP_1                             = 0x300F0001ull;

static const uint64_t P9N2_PERV_EC17_MULTICAST_GROUP_1                             = 0x310F0001ull;

static const uint64_t P9N2_PERV_EC18_MULTICAST_GROUP_1                             = 0x320F0001ull;

static const uint64_t P9N2_PERV_EC19_MULTICAST_GROUP_1                             = 0x330F0001ull;

static const uint64_t P9N2_PERV_EC20_MULTICAST_GROUP_1                             = 0x340F0001ull;

static const uint64_t P9N2_PERV_EC21_MULTICAST_GROUP_1                             = 0x350F0001ull;

static const uint64_t P9N2_PERV_EC22_MULTICAST_GROUP_1                             = 0x360F0001ull;

static const uint64_t P9N2_PERV_EC23_MULTICAST_GROUP_1                             = 0x370F0001ull;


static const uint64_t P9N2_PERV_MULTICAST_GROUP_2                                  = 0x000F0002ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_MULTICAST_GROUP_2                               = 0x010F0002ull;

static const uint64_t P9N2_PERV_N0_MULTICAST_GROUP_2                               = 0x020F0002ull;

static const uint64_t P9N2_PERV_N1_MULTICAST_GROUP_2                               = 0x030F0002ull;

static const uint64_t P9N2_PERV_N2_MULTICAST_GROUP_2                               = 0x040F0002ull;

static const uint64_t P9N2_PERV_N3_MULTICAST_GROUP_2                               = 0x050F0002ull;

static const uint64_t P9N2_PERV_XB_MULTICAST_GROUP_2                               = 0x060F0002ull;

static const uint64_t P9N2_PERV_MC01_MULTICAST_GROUP_2                             = 0x070F0002ull;

static const uint64_t P9N2_PERV_MC23_MULTICAST_GROUP_2                             = 0x080F0002ull;

static const uint64_t P9N2_PERV_OB0_MULTICAST_GROUP_2                              = 0x090F0002ull;

static const uint64_t P9N2_PERV_OB3_MULTICAST_GROUP_2                              = 0x0C0F0002ull;

static const uint64_t P9N2_PERV_PCI0_MULTICAST_GROUP_2                             = 0x0D0F0002ull;

static const uint64_t P9N2_PERV_PCI1_MULTICAST_GROUP_2                             = 0x0E0F0002ull;

static const uint64_t P9N2_PERV_PCI2_MULTICAST_GROUP_2                             = 0x0F0F0002ull;

static const uint64_t P9N2_PERV_EP00_MULTICAST_GROUP_2                             = 0x100F0002ull;

static const uint64_t P9N2_PERV_EP01_MULTICAST_GROUP_2                             = 0x110F0002ull;

static const uint64_t P9N2_PERV_EP02_MULTICAST_GROUP_2                             = 0x120F0002ull;

static const uint64_t P9N2_PERV_EP03_MULTICAST_GROUP_2                             = 0x130F0002ull;

static const uint64_t P9N2_PERV_EP04_MULTICAST_GROUP_2                             = 0x140F0002ull;

static const uint64_t P9N2_PERV_EP05_MULTICAST_GROUP_2                             = 0x150F0002ull;

static const uint64_t P9N2_PERV_EC00_MULTICAST_GROUP_2                             = 0x200F0002ull;

static const uint64_t P9N2_PERV_EC01_MULTICAST_GROUP_2                             = 0x210F0002ull;

static const uint64_t P9N2_PERV_EC02_MULTICAST_GROUP_2                             = 0x220F0002ull;

static const uint64_t P9N2_PERV_EC03_MULTICAST_GROUP_2                             = 0x230F0002ull;

static const uint64_t P9N2_PERV_EC04_MULTICAST_GROUP_2                             = 0x240F0002ull;

static const uint64_t P9N2_PERV_EC05_MULTICAST_GROUP_2                             = 0x250F0002ull;

static const uint64_t P9N2_PERV_EC06_MULTICAST_GROUP_2                             = 0x260F0002ull;

static const uint64_t P9N2_PERV_EC07_MULTICAST_GROUP_2                             = 0x270F0002ull;

static const uint64_t P9N2_PERV_EC08_MULTICAST_GROUP_2                             = 0x280F0002ull;

static const uint64_t P9N2_PERV_EC09_MULTICAST_GROUP_2                             = 0x290F0002ull;

static const uint64_t P9N2_PERV_EC10_MULTICAST_GROUP_2                             = 0x2A0F0002ull;

static const uint64_t P9N2_PERV_EC11_MULTICAST_GROUP_2                             = 0x2B0F0002ull;

static const uint64_t P9N2_PERV_EC12_MULTICAST_GROUP_2                             = 0x2C0F0002ull;

static const uint64_t P9N2_PERV_EC13_MULTICAST_GROUP_2                             = 0x2D0F0002ull;

static const uint64_t P9N2_PERV_EC14_MULTICAST_GROUP_2                             = 0x2E0F0002ull;

static const uint64_t P9N2_PERV_EC15_MULTICAST_GROUP_2                             = 0x2F0F0002ull;

static const uint64_t P9N2_PERV_EC16_MULTICAST_GROUP_2                             = 0x300F0002ull;

static const uint64_t P9N2_PERV_EC17_MULTICAST_GROUP_2                             = 0x310F0002ull;

static const uint64_t P9N2_PERV_EC18_MULTICAST_GROUP_2                             = 0x320F0002ull;

static const uint64_t P9N2_PERV_EC19_MULTICAST_GROUP_2                             = 0x330F0002ull;

static const uint64_t P9N2_PERV_EC20_MULTICAST_GROUP_2                             = 0x340F0002ull;

static const uint64_t P9N2_PERV_EC21_MULTICAST_GROUP_2                             = 0x350F0002ull;

static const uint64_t P9N2_PERV_EC22_MULTICAST_GROUP_2                             = 0x360F0002ull;

static const uint64_t P9N2_PERV_EC23_MULTICAST_GROUP_2                             = 0x370F0002ull;


static const uint64_t P9N2_PERV_MULTICAST_GROUP_3                                  = 0x000F0003ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_MULTICAST_GROUP_3                               = 0x010F0003ull;

static const uint64_t P9N2_PERV_N0_MULTICAST_GROUP_3                               = 0x020F0003ull;

static const uint64_t P9N2_PERV_N1_MULTICAST_GROUP_3                               = 0x030F0003ull;

static const uint64_t P9N2_PERV_N2_MULTICAST_GROUP_3                               = 0x040F0003ull;

static const uint64_t P9N2_PERV_N3_MULTICAST_GROUP_3                               = 0x050F0003ull;

static const uint64_t P9N2_PERV_XB_MULTICAST_GROUP_3                               = 0x060F0003ull;

static const uint64_t P9N2_PERV_MC01_MULTICAST_GROUP_3                             = 0x070F0003ull;

static const uint64_t P9N2_PERV_MC23_MULTICAST_GROUP_3                             = 0x080F0003ull;

static const uint64_t P9N2_PERV_OB0_MULTICAST_GROUP_3                              = 0x090F0003ull;

static const uint64_t P9N2_PERV_OB3_MULTICAST_GROUP_3                              = 0x0C0F0003ull;

static const uint64_t P9N2_PERV_PCI0_MULTICAST_GROUP_3                             = 0x0D0F0003ull;

static const uint64_t P9N2_PERV_PCI1_MULTICAST_GROUP_3                             = 0x0E0F0003ull;

static const uint64_t P9N2_PERV_PCI2_MULTICAST_GROUP_3                             = 0x0F0F0003ull;

static const uint64_t P9N2_PERV_EP00_MULTICAST_GROUP_3                             = 0x100F0003ull;

static const uint64_t P9N2_PERV_EP01_MULTICAST_GROUP_3                             = 0x110F0003ull;

static const uint64_t P9N2_PERV_EP02_MULTICAST_GROUP_3                             = 0x120F0003ull;

static const uint64_t P9N2_PERV_EP03_MULTICAST_GROUP_3                             = 0x130F0003ull;

static const uint64_t P9N2_PERV_EP04_MULTICAST_GROUP_3                             = 0x140F0003ull;

static const uint64_t P9N2_PERV_EP05_MULTICAST_GROUP_3                             = 0x150F0003ull;

static const uint64_t P9N2_PERV_EC00_MULTICAST_GROUP_3                             = 0x200F0003ull;

static const uint64_t P9N2_PERV_EC01_MULTICAST_GROUP_3                             = 0x210F0003ull;

static const uint64_t P9N2_PERV_EC02_MULTICAST_GROUP_3                             = 0x220F0003ull;

static const uint64_t P9N2_PERV_EC03_MULTICAST_GROUP_3                             = 0x230F0003ull;

static const uint64_t P9N2_PERV_EC04_MULTICAST_GROUP_3                             = 0x240F0003ull;

static const uint64_t P9N2_PERV_EC05_MULTICAST_GROUP_3                             = 0x250F0003ull;

static const uint64_t P9N2_PERV_EC06_MULTICAST_GROUP_3                             = 0x260F0003ull;

static const uint64_t P9N2_PERV_EC07_MULTICAST_GROUP_3                             = 0x270F0003ull;

static const uint64_t P9N2_PERV_EC08_MULTICAST_GROUP_3                             = 0x280F0003ull;

static const uint64_t P9N2_PERV_EC09_MULTICAST_GROUP_3                             = 0x290F0003ull;

static const uint64_t P9N2_PERV_EC10_MULTICAST_GROUP_3                             = 0x2A0F0003ull;

static const uint64_t P9N2_PERV_EC11_MULTICAST_GROUP_3                             = 0x2B0F0003ull;

static const uint64_t P9N2_PERV_EC12_MULTICAST_GROUP_3                             = 0x2C0F0003ull;

static const uint64_t P9N2_PERV_EC13_MULTICAST_GROUP_3                             = 0x2D0F0003ull;

static const uint64_t P9N2_PERV_EC14_MULTICAST_GROUP_3                             = 0x2E0F0003ull;

static const uint64_t P9N2_PERV_EC15_MULTICAST_GROUP_3                             = 0x2F0F0003ull;

static const uint64_t P9N2_PERV_EC16_MULTICAST_GROUP_3                             = 0x300F0003ull;

static const uint64_t P9N2_PERV_EC17_MULTICAST_GROUP_3                             = 0x310F0003ull;

static const uint64_t P9N2_PERV_EC18_MULTICAST_GROUP_3                             = 0x320F0003ull;

static const uint64_t P9N2_PERV_EC19_MULTICAST_GROUP_3                             = 0x330F0003ull;

static const uint64_t P9N2_PERV_EC20_MULTICAST_GROUP_3                             = 0x340F0003ull;

static const uint64_t P9N2_PERV_EC21_MULTICAST_GROUP_3                             = 0x350F0003ull;

static const uint64_t P9N2_PERV_EC22_MULTICAST_GROUP_3                             = 0x360F0003ull;

static const uint64_t P9N2_PERV_EC23_MULTICAST_GROUP_3                             = 0x370F0003ull;


static const uint64_t P9N2_PERV_MULTICAST_GROUP_4                                  = 0x000F0004ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_MULTICAST_GROUP_4                               = 0x010F0004ull;

static const uint64_t P9N2_PERV_N0_MULTICAST_GROUP_4                               = 0x020F0004ull;

static const uint64_t P9N2_PERV_N1_MULTICAST_GROUP_4                               = 0x030F0004ull;

static const uint64_t P9N2_PERV_N2_MULTICAST_GROUP_4                               = 0x040F0004ull;

static const uint64_t P9N2_PERV_N3_MULTICAST_GROUP_4                               = 0x050F0004ull;

static const uint64_t P9N2_PERV_XB_MULTICAST_GROUP_4                               = 0x060F0004ull;

static const uint64_t P9N2_PERV_MC01_MULTICAST_GROUP_4                             = 0x070F0004ull;

static const uint64_t P9N2_PERV_MC23_MULTICAST_GROUP_4                             = 0x080F0004ull;

static const uint64_t P9N2_PERV_OB0_MULTICAST_GROUP_4                              = 0x090F0004ull;

static const uint64_t P9N2_PERV_OB3_MULTICAST_GROUP_4                              = 0x0C0F0004ull;

static const uint64_t P9N2_PERV_PCI0_MULTICAST_GROUP_4                             = 0x0D0F0004ull;

static const uint64_t P9N2_PERV_PCI1_MULTICAST_GROUP_4                             = 0x0E0F0004ull;

static const uint64_t P9N2_PERV_PCI2_MULTICAST_GROUP_4                             = 0x0F0F0004ull;

static const uint64_t P9N2_PERV_EP00_MULTICAST_GROUP_4                             = 0x100F0004ull;

static const uint64_t P9N2_PERV_EP01_MULTICAST_GROUP_4                             = 0x110F0004ull;

static const uint64_t P9N2_PERV_EP02_MULTICAST_GROUP_4                             = 0x120F0004ull;

static const uint64_t P9N2_PERV_EP03_MULTICAST_GROUP_4                             = 0x130F0004ull;

static const uint64_t P9N2_PERV_EP04_MULTICAST_GROUP_4                             = 0x140F0004ull;

static const uint64_t P9N2_PERV_EP05_MULTICAST_GROUP_4                             = 0x150F0004ull;

static const uint64_t P9N2_PERV_EC00_MULTICAST_GROUP_4                             = 0x200F0004ull;

static const uint64_t P9N2_PERV_EC01_MULTICAST_GROUP_4                             = 0x210F0004ull;

static const uint64_t P9N2_PERV_EC02_MULTICAST_GROUP_4                             = 0x220F0004ull;

static const uint64_t P9N2_PERV_EC03_MULTICAST_GROUP_4                             = 0x230F0004ull;

static const uint64_t P9N2_PERV_EC04_MULTICAST_GROUP_4                             = 0x240F0004ull;

static const uint64_t P9N2_PERV_EC05_MULTICAST_GROUP_4                             = 0x250F0004ull;

static const uint64_t P9N2_PERV_EC06_MULTICAST_GROUP_4                             = 0x260F0004ull;

static const uint64_t P9N2_PERV_EC07_MULTICAST_GROUP_4                             = 0x270F0004ull;

static const uint64_t P9N2_PERV_EC08_MULTICAST_GROUP_4                             = 0x280F0004ull;

static const uint64_t P9N2_PERV_EC09_MULTICAST_GROUP_4                             = 0x290F0004ull;

static const uint64_t P9N2_PERV_EC10_MULTICAST_GROUP_4                             = 0x2A0F0004ull;

static const uint64_t P9N2_PERV_EC11_MULTICAST_GROUP_4                             = 0x2B0F0004ull;

static const uint64_t P9N2_PERV_EC12_MULTICAST_GROUP_4                             = 0x2C0F0004ull;

static const uint64_t P9N2_PERV_EC13_MULTICAST_GROUP_4                             = 0x2D0F0004ull;

static const uint64_t P9N2_PERV_EC14_MULTICAST_GROUP_4                             = 0x2E0F0004ull;

static const uint64_t P9N2_PERV_EC15_MULTICAST_GROUP_4                             = 0x2F0F0004ull;

static const uint64_t P9N2_PERV_EC16_MULTICAST_GROUP_4                             = 0x300F0004ull;

static const uint64_t P9N2_PERV_EC17_MULTICAST_GROUP_4                             = 0x310F0004ull;

static const uint64_t P9N2_PERV_EC18_MULTICAST_GROUP_4                             = 0x320F0004ull;

static const uint64_t P9N2_PERV_EC19_MULTICAST_GROUP_4                             = 0x330F0004ull;

static const uint64_t P9N2_PERV_EC20_MULTICAST_GROUP_4                             = 0x340F0004ull;

static const uint64_t P9N2_PERV_EC21_MULTICAST_GROUP_4                             = 0x350F0004ull;

static const uint64_t P9N2_PERV_EC22_MULTICAST_GROUP_4                             = 0x360F0004ull;

static const uint64_t P9N2_PERV_EC23_MULTICAST_GROUP_4                             = 0x370F0004ull;


static const uint64_t P9N2_PERV_NET_CTRL0                                          = 0x000F0040ull;

static const uint64_t P9N2_PERV_TP_NET_CTRL0                                       = 0x010F0040ull;

static const uint64_t P9N2_PERV_NET_CTRL0_WAND                                     = 0x000F0041ull;

static const uint64_t P9N2_PERV_TP_NET_CTRL0_WAND                                  = 0x010F0041ull;

static const uint64_t P9N2_PERV_NET_CTRL0_WOR                                      = 0x000F0042ull;

static const uint64_t P9N2_PERV_TP_NET_CTRL0_WOR                                   = 0x010F0042ull;

static const uint64_t P9N2_PERV_N0_NET_CTRL0                                       = 0x020F0040ull;

static const uint64_t P9N2_PERV_N0_NET_CTRL0_WAND                                  = 0x020F0041ull;

static const uint64_t P9N2_PERV_N0_NET_CTRL0_WOR                                   = 0x020F0042ull;

static const uint64_t P9N2_PERV_N1_NET_CTRL0                                       = 0x030F0040ull;

static const uint64_t P9N2_PERV_N1_NET_CTRL0_WAND                                  = 0x030F0041ull;

static const uint64_t P9N2_PERV_N1_NET_CTRL0_WOR                                   = 0x030F0042ull;

static const uint64_t P9N2_PERV_N2_NET_CTRL0                                       = 0x040F0040ull;

static const uint64_t P9N2_PERV_N2_NET_CTRL0_WAND                                  = 0x040F0041ull;

static const uint64_t P9N2_PERV_N2_NET_CTRL0_WOR                                   = 0x040F0042ull;

static const uint64_t P9N2_PERV_N3_NET_CTRL0                                       = 0x050F0040ull;

static const uint64_t P9N2_PERV_N3_NET_CTRL0_WAND                                  = 0x050F0041ull;

static const uint64_t P9N2_PERV_N3_NET_CTRL0_WOR                                   = 0x050F0042ull;

static const uint64_t P9N2_PERV_XB_NET_CTRL0                                       = 0x060F0040ull;

static const uint64_t P9N2_PERV_XB_NET_CTRL0_WAND                                  = 0x060F0041ull;

static const uint64_t P9N2_PERV_XB_NET_CTRL0_WOR                                   = 0x060F0042ull;

static const uint64_t P9N2_PERV_MC01_NET_CTRL0                                     = 0x070F0040ull;

static const uint64_t P9N2_PERV_MC01_NET_CTRL0_WAND                                = 0x070F0041ull;

static const uint64_t P9N2_PERV_MC01_NET_CTRL0_WOR                                 = 0x070F0042ull;

static const uint64_t P9N2_PERV_MC23_NET_CTRL0                                     = 0x080F0040ull;

static const uint64_t P9N2_PERV_MC23_NET_CTRL0_WAND                                = 0x080F0041ull;

static const uint64_t P9N2_PERV_MC23_NET_CTRL0_WOR                                 = 0x080F0042ull;

static const uint64_t P9N2_PERV_OB0_NET_CTRL0                                      = 0x090F0040ull;

static const uint64_t P9N2_PERV_OB0_NET_CTRL0_WAND                                 = 0x090F0041ull;

static const uint64_t P9N2_PERV_OB0_NET_CTRL0_WOR                                  = 0x090F0042ull;

static const uint64_t P9N2_PERV_OB3_NET_CTRL0                                      = 0x0C0F0040ull;

static const uint64_t P9N2_PERV_OB3_NET_CTRL0_WAND                                 = 0x0C0F0041ull;

static const uint64_t P9N2_PERV_OB3_NET_CTRL0_WOR                                  = 0x0C0F0042ull;

static const uint64_t P9N2_PERV_PCI0_NET_CTRL0                                     = 0x0D0F0040ull;

static const uint64_t P9N2_PERV_PCI0_NET_CTRL0_WAND                                = 0x0D0F0041ull;

static const uint64_t P9N2_PERV_PCI0_NET_CTRL0_WOR                                 = 0x0D0F0042ull;

static const uint64_t P9N2_PERV_PCI1_NET_CTRL0                                     = 0x0E0F0040ull;

static const uint64_t P9N2_PERV_PCI1_NET_CTRL0_WAND                                = 0x0E0F0041ull;

static const uint64_t P9N2_PERV_PCI1_NET_CTRL0_WOR                                 = 0x0E0F0042ull;

static const uint64_t P9N2_PERV_PCI2_NET_CTRL0                                     = 0x0F0F0040ull;

static const uint64_t P9N2_PERV_PCI2_NET_CTRL0_WAND                                = 0x0F0F0041ull;

static const uint64_t P9N2_PERV_PCI2_NET_CTRL0_WOR                                 = 0x0F0F0042ull;

static const uint64_t P9N2_PERV_EP00_NET_CTRL0                                     = 0x100F0040ull;

static const uint64_t P9N2_PERV_EP00_NET_CTRL0_WAND                                = 0x100F0041ull;

static const uint64_t P9N2_PERV_EP00_NET_CTRL0_WOR                                 = 0x100F0042ull;

static const uint64_t P9N2_PERV_EP01_NET_CTRL0                                     = 0x110F0040ull;

static const uint64_t P9N2_PERV_EP01_NET_CTRL0_WAND                                = 0x110F0041ull;

static const uint64_t P9N2_PERV_EP01_NET_CTRL0_WOR                                 = 0x110F0042ull;

static const uint64_t P9N2_PERV_EP02_NET_CTRL0                                     = 0x120F0040ull;

static const uint64_t P9N2_PERV_EP02_NET_CTRL0_WAND                                = 0x120F0041ull;

static const uint64_t P9N2_PERV_EP02_NET_CTRL0_WOR                                 = 0x120F0042ull;

static const uint64_t P9N2_PERV_EP03_NET_CTRL0                                     = 0x130F0040ull;

static const uint64_t P9N2_PERV_EP03_NET_CTRL0_WAND                                = 0x130F0041ull;

static const uint64_t P9N2_PERV_EP03_NET_CTRL0_WOR                                 = 0x130F0042ull;

static const uint64_t P9N2_PERV_EP04_NET_CTRL0                                     = 0x140F0040ull;

static const uint64_t P9N2_PERV_EP04_NET_CTRL0_WAND                                = 0x140F0041ull;

static const uint64_t P9N2_PERV_EP04_NET_CTRL0_WOR                                 = 0x140F0042ull;

static const uint64_t P9N2_PERV_EP05_NET_CTRL0                                     = 0x150F0040ull;

static const uint64_t P9N2_PERV_EP05_NET_CTRL0_WAND                                = 0x150F0041ull;

static const uint64_t P9N2_PERV_EP05_NET_CTRL0_WOR                                 = 0x150F0042ull;

static const uint64_t P9N2_PERV_EC00_NET_CTRL0                                     = 0x200F0040ull;

static const uint64_t P9N2_PERV_EC00_NET_CTRL0_WAND                                = 0x200F0041ull;

static const uint64_t P9N2_PERV_EC00_NET_CTRL0_WOR                                 = 0x200F0042ull;

static const uint64_t P9N2_PERV_EC01_NET_CTRL0                                     = 0x210F0040ull;

static const uint64_t P9N2_PERV_EC01_NET_CTRL0_WAND                                = 0x210F0041ull;

static const uint64_t P9N2_PERV_EC01_NET_CTRL0_WOR                                 = 0x210F0042ull;

static const uint64_t P9N2_PERV_EC02_NET_CTRL0                                     = 0x220F0040ull;

static const uint64_t P9N2_PERV_EC02_NET_CTRL0_WAND                                = 0x220F0041ull;

static const uint64_t P9N2_PERV_EC02_NET_CTRL0_WOR                                 = 0x220F0042ull;

static const uint64_t P9N2_PERV_EC03_NET_CTRL0                                     = 0x230F0040ull;

static const uint64_t P9N2_PERV_EC03_NET_CTRL0_WAND                                = 0x230F0041ull;

static const uint64_t P9N2_PERV_EC03_NET_CTRL0_WOR                                 = 0x230F0042ull;

static const uint64_t P9N2_PERV_EC04_NET_CTRL0                                     = 0x240F0040ull;

static const uint64_t P9N2_PERV_EC04_NET_CTRL0_WAND                                = 0x240F0041ull;

static const uint64_t P9N2_PERV_EC04_NET_CTRL0_WOR                                 = 0x240F0042ull;

static const uint64_t P9N2_PERV_EC05_NET_CTRL0                                     = 0x250F0040ull;

static const uint64_t P9N2_PERV_EC05_NET_CTRL0_WAND                                = 0x250F0041ull;

static const uint64_t P9N2_PERV_EC05_NET_CTRL0_WOR                                 = 0x250F0042ull;

static const uint64_t P9N2_PERV_EC06_NET_CTRL0                                     = 0x260F0040ull;

static const uint64_t P9N2_PERV_EC06_NET_CTRL0_WAND                                = 0x260F0041ull;

static const uint64_t P9N2_PERV_EC06_NET_CTRL0_WOR                                 = 0x260F0042ull;

static const uint64_t P9N2_PERV_EC07_NET_CTRL0                                     = 0x270F0040ull;

static const uint64_t P9N2_PERV_EC07_NET_CTRL0_WAND                                = 0x270F0041ull;

static const uint64_t P9N2_PERV_EC07_NET_CTRL0_WOR                                 = 0x270F0042ull;

static const uint64_t P9N2_PERV_EC08_NET_CTRL0                                     = 0x280F0040ull;

static const uint64_t P9N2_PERV_EC08_NET_CTRL0_WAND                                = 0x280F0041ull;

static const uint64_t P9N2_PERV_EC08_NET_CTRL0_WOR                                 = 0x280F0042ull;

static const uint64_t P9N2_PERV_EC09_NET_CTRL0                                     = 0x290F0040ull;

static const uint64_t P9N2_PERV_EC09_NET_CTRL0_WAND                                = 0x290F0041ull;

static const uint64_t P9N2_PERV_EC09_NET_CTRL0_WOR                                 = 0x290F0042ull;

static const uint64_t P9N2_PERV_EC10_NET_CTRL0                                     = 0x2A0F0040ull;

static const uint64_t P9N2_PERV_EC10_NET_CTRL0_WAND                                = 0x2A0F0041ull;

static const uint64_t P9N2_PERV_EC10_NET_CTRL0_WOR                                 = 0x2A0F0042ull;

static const uint64_t P9N2_PERV_EC11_NET_CTRL0                                     = 0x2B0F0040ull;

static const uint64_t P9N2_PERV_EC11_NET_CTRL0_WAND                                = 0x2B0F0041ull;

static const uint64_t P9N2_PERV_EC11_NET_CTRL0_WOR                                 = 0x2B0F0042ull;

static const uint64_t P9N2_PERV_EC12_NET_CTRL0                                     = 0x2C0F0040ull;

static const uint64_t P9N2_PERV_EC12_NET_CTRL0_WAND                                = 0x2C0F0041ull;

static const uint64_t P9N2_PERV_EC12_NET_CTRL0_WOR                                 = 0x2C0F0042ull;

static const uint64_t P9N2_PERV_EC13_NET_CTRL0                                     = 0x2D0F0040ull;

static const uint64_t P9N2_PERV_EC13_NET_CTRL0_WAND                                = 0x2D0F0041ull;

static const uint64_t P9N2_PERV_EC13_NET_CTRL0_WOR                                 = 0x2D0F0042ull;

static const uint64_t P9N2_PERV_EC14_NET_CTRL0                                     = 0x2E0F0040ull;

static const uint64_t P9N2_PERV_EC14_NET_CTRL0_WAND                                = 0x2E0F0041ull;

static const uint64_t P9N2_PERV_EC14_NET_CTRL0_WOR                                 = 0x2E0F0042ull;

static const uint64_t P9N2_PERV_EC15_NET_CTRL0                                     = 0x2F0F0040ull;

static const uint64_t P9N2_PERV_EC15_NET_CTRL0_WAND                                = 0x2F0F0041ull;

static const uint64_t P9N2_PERV_EC15_NET_CTRL0_WOR                                 = 0x2F0F0042ull;

static const uint64_t P9N2_PERV_EC16_NET_CTRL0                                     = 0x300F0040ull;

static const uint64_t P9N2_PERV_EC16_NET_CTRL0_WAND                                = 0x300F0041ull;

static const uint64_t P9N2_PERV_EC16_NET_CTRL0_WOR                                 = 0x300F0042ull;

static const uint64_t P9N2_PERV_EC17_NET_CTRL0                                     = 0x310F0040ull;

static const uint64_t P9N2_PERV_EC17_NET_CTRL0_WAND                                = 0x310F0041ull;

static const uint64_t P9N2_PERV_EC17_NET_CTRL0_WOR                                 = 0x310F0042ull;

static const uint64_t P9N2_PERV_EC18_NET_CTRL0                                     = 0x320F0040ull;

static const uint64_t P9N2_PERV_EC18_NET_CTRL0_WAND                                = 0x320F0041ull;

static const uint64_t P9N2_PERV_EC18_NET_CTRL0_WOR                                 = 0x320F0042ull;

static const uint64_t P9N2_PERV_EC19_NET_CTRL0                                     = 0x330F0040ull;

static const uint64_t P9N2_PERV_EC19_NET_CTRL0_WAND                                = 0x330F0041ull;

static const uint64_t P9N2_PERV_EC19_NET_CTRL0_WOR                                 = 0x330F0042ull;

static const uint64_t P9N2_PERV_EC20_NET_CTRL0                                     = 0x340F0040ull;

static const uint64_t P9N2_PERV_EC20_NET_CTRL0_WAND                                = 0x340F0041ull;

static const uint64_t P9N2_PERV_EC20_NET_CTRL0_WOR                                 = 0x340F0042ull;

static const uint64_t P9N2_PERV_EC21_NET_CTRL0                                     = 0x350F0040ull;

static const uint64_t P9N2_PERV_EC21_NET_CTRL0_WAND                                = 0x350F0041ull;

static const uint64_t P9N2_PERV_EC21_NET_CTRL0_WOR                                 = 0x350F0042ull;

static const uint64_t P9N2_PERV_EC22_NET_CTRL0                                     = 0x360F0040ull;

static const uint64_t P9N2_PERV_EC22_NET_CTRL0_WAND                                = 0x360F0041ull;

static const uint64_t P9N2_PERV_EC22_NET_CTRL0_WOR                                 = 0x360F0042ull;

static const uint64_t P9N2_PERV_EC23_NET_CTRL0                                     = 0x370F0040ull;

static const uint64_t P9N2_PERV_EC23_NET_CTRL0_WAND                                = 0x370F0041ull;

static const uint64_t P9N2_PERV_EC23_NET_CTRL0_WOR                                 = 0x370F0042ull;


static const uint64_t P9N2_PERV_NET_CTRL1                                          = 0x000F0044ull;

static const uint64_t P9N2_PERV_TP_NET_CTRL1                                       = 0x010F0044ull;

static const uint64_t P9N2_PERV_NET_CTRL1_WAND                                     = 0x000F0045ull;

static const uint64_t P9N2_PERV_TP_NET_CTRL1_WAND                                  = 0x010F0045ull;

static const uint64_t P9N2_PERV_NET_CTRL1_WOR                                      = 0x000F0046ull;

static const uint64_t P9N2_PERV_TP_NET_CTRL1_WOR                                   = 0x010F0046ull;

static const uint64_t P9N2_PERV_N0_NET_CTRL1                                       = 0x020F0044ull;

static const uint64_t P9N2_PERV_N0_NET_CTRL1_WAND                                  = 0x020F0045ull;

static const uint64_t P9N2_PERV_N0_NET_CTRL1_WOR                                   = 0x020F0046ull;

static const uint64_t P9N2_PERV_N1_NET_CTRL1                                       = 0x030F0044ull;

static const uint64_t P9N2_PERV_N1_NET_CTRL1_WAND                                  = 0x030F0045ull;

static const uint64_t P9N2_PERV_N1_NET_CTRL1_WOR                                   = 0x030F0046ull;

static const uint64_t P9N2_PERV_N2_NET_CTRL1                                       = 0x040F0044ull;

static const uint64_t P9N2_PERV_N2_NET_CTRL1_WAND                                  = 0x040F0045ull;

static const uint64_t P9N2_PERV_N2_NET_CTRL1_WOR                                   = 0x040F0046ull;

static const uint64_t P9N2_PERV_N3_NET_CTRL1                                       = 0x050F0044ull;

static const uint64_t P9N2_PERV_N3_NET_CTRL1_WAND                                  = 0x050F0045ull;

static const uint64_t P9N2_PERV_N3_NET_CTRL1_WOR                                   = 0x050F0046ull;

static const uint64_t P9N2_PERV_XB_NET_CTRL1                                       = 0x060F0044ull;

static const uint64_t P9N2_PERV_XB_NET_CTRL1_WAND                                  = 0x060F0045ull;

static const uint64_t P9N2_PERV_XB_NET_CTRL1_WOR                                   = 0x060F0046ull;

static const uint64_t P9N2_PERV_MC01_NET_CTRL1                                     = 0x070F0044ull;

static const uint64_t P9N2_PERV_MC01_NET_CTRL1_WAND                                = 0x070F0045ull;

static const uint64_t P9N2_PERV_MC01_NET_CTRL1_WOR                                 = 0x070F0046ull;

static const uint64_t P9N2_PERV_MC23_NET_CTRL1                                     = 0x080F0044ull;

static const uint64_t P9N2_PERV_MC23_NET_CTRL1_WAND                                = 0x080F0045ull;

static const uint64_t P9N2_PERV_MC23_NET_CTRL1_WOR                                 = 0x080F0046ull;

static const uint64_t P9N2_PERV_OB0_NET_CTRL1                                      = 0x090F0044ull;

static const uint64_t P9N2_PERV_OB0_NET_CTRL1_WAND                                 = 0x090F0045ull;

static const uint64_t P9N2_PERV_OB0_NET_CTRL1_WOR                                  = 0x090F0046ull;

static const uint64_t P9N2_PERV_OB3_NET_CTRL1                                      = 0x0C0F0044ull;

static const uint64_t P9N2_PERV_OB3_NET_CTRL1_WAND                                 = 0x0C0F0045ull;

static const uint64_t P9N2_PERV_OB3_NET_CTRL1_WOR                                  = 0x0C0F0046ull;

static const uint64_t P9N2_PERV_PCI0_NET_CTRL1                                     = 0x0D0F0044ull;

static const uint64_t P9N2_PERV_PCI0_NET_CTRL1_WAND                                = 0x0D0F0045ull;

static const uint64_t P9N2_PERV_PCI0_NET_CTRL1_WOR                                 = 0x0D0F0046ull;

static const uint64_t P9N2_PERV_PCI1_NET_CTRL1                                     = 0x0E0F0044ull;

static const uint64_t P9N2_PERV_PCI1_NET_CTRL1_WAND                                = 0x0E0F0045ull;

static const uint64_t P9N2_PERV_PCI1_NET_CTRL1_WOR                                 = 0x0E0F0046ull;

static const uint64_t P9N2_PERV_PCI2_NET_CTRL1                                     = 0x0F0F0044ull;

static const uint64_t P9N2_PERV_PCI2_NET_CTRL1_WAND                                = 0x0F0F0045ull;

static const uint64_t P9N2_PERV_PCI2_NET_CTRL1_WOR                                 = 0x0F0F0046ull;

static const uint64_t P9N2_PERV_EP00_NET_CTRL1                                     = 0x100F0044ull;

static const uint64_t P9N2_PERV_EP00_NET_CTRL1_WAND                                = 0x100F0045ull;

static const uint64_t P9N2_PERV_EP00_NET_CTRL1_WOR                                 = 0x100F0046ull;

static const uint64_t P9N2_PERV_EP01_NET_CTRL1                                     = 0x110F0044ull;

static const uint64_t P9N2_PERV_EP01_NET_CTRL1_WAND                                = 0x110F0045ull;

static const uint64_t P9N2_PERV_EP01_NET_CTRL1_WOR                                 = 0x110F0046ull;

static const uint64_t P9N2_PERV_EP02_NET_CTRL1                                     = 0x120F0044ull;

static const uint64_t P9N2_PERV_EP02_NET_CTRL1_WAND                                = 0x120F0045ull;

static const uint64_t P9N2_PERV_EP02_NET_CTRL1_WOR                                 = 0x120F0046ull;

static const uint64_t P9N2_PERV_EP03_NET_CTRL1                                     = 0x130F0044ull;

static const uint64_t P9N2_PERV_EP03_NET_CTRL1_WAND                                = 0x130F0045ull;

static const uint64_t P9N2_PERV_EP03_NET_CTRL1_WOR                                 = 0x130F0046ull;

static const uint64_t P9N2_PERV_EP04_NET_CTRL1                                     = 0x140F0044ull;

static const uint64_t P9N2_PERV_EP04_NET_CTRL1_WAND                                = 0x140F0045ull;

static const uint64_t P9N2_PERV_EP04_NET_CTRL1_WOR                                 = 0x140F0046ull;

static const uint64_t P9N2_PERV_EP05_NET_CTRL1                                     = 0x150F0044ull;

static const uint64_t P9N2_PERV_EP05_NET_CTRL1_WAND                                = 0x150F0045ull;

static const uint64_t P9N2_PERV_EP05_NET_CTRL1_WOR                                 = 0x150F0046ull;

static const uint64_t P9N2_PERV_EC00_NET_CTRL1                                     = 0x200F0044ull;

static const uint64_t P9N2_PERV_EC00_NET_CTRL1_WAND                                = 0x200F0045ull;

static const uint64_t P9N2_PERV_EC00_NET_CTRL1_WOR                                 = 0x200F0046ull;

static const uint64_t P9N2_PERV_EC01_NET_CTRL1                                     = 0x210F0044ull;

static const uint64_t P9N2_PERV_EC01_NET_CTRL1_WAND                                = 0x210F0045ull;

static const uint64_t P9N2_PERV_EC01_NET_CTRL1_WOR                                 = 0x210F0046ull;

static const uint64_t P9N2_PERV_EC02_NET_CTRL1                                     = 0x220F0044ull;

static const uint64_t P9N2_PERV_EC02_NET_CTRL1_WAND                                = 0x220F0045ull;

static const uint64_t P9N2_PERV_EC02_NET_CTRL1_WOR                                 = 0x220F0046ull;

static const uint64_t P9N2_PERV_EC03_NET_CTRL1                                     = 0x230F0044ull;

static const uint64_t P9N2_PERV_EC03_NET_CTRL1_WAND                                = 0x230F0045ull;

static const uint64_t P9N2_PERV_EC03_NET_CTRL1_WOR                                 = 0x230F0046ull;

static const uint64_t P9N2_PERV_EC04_NET_CTRL1                                     = 0x240F0044ull;

static const uint64_t P9N2_PERV_EC04_NET_CTRL1_WAND                                = 0x240F0045ull;

static const uint64_t P9N2_PERV_EC04_NET_CTRL1_WOR                                 = 0x240F0046ull;

static const uint64_t P9N2_PERV_EC05_NET_CTRL1                                     = 0x250F0044ull;

static const uint64_t P9N2_PERV_EC05_NET_CTRL1_WAND                                = 0x250F0045ull;

static const uint64_t P9N2_PERV_EC05_NET_CTRL1_WOR                                 = 0x250F0046ull;

static const uint64_t P9N2_PERV_EC06_NET_CTRL1                                     = 0x260F0044ull;

static const uint64_t P9N2_PERV_EC06_NET_CTRL1_WAND                                = 0x260F0045ull;

static const uint64_t P9N2_PERV_EC06_NET_CTRL1_WOR                                 = 0x260F0046ull;

static const uint64_t P9N2_PERV_EC07_NET_CTRL1                                     = 0x270F0044ull;

static const uint64_t P9N2_PERV_EC07_NET_CTRL1_WAND                                = 0x270F0045ull;

static const uint64_t P9N2_PERV_EC07_NET_CTRL1_WOR                                 = 0x270F0046ull;

static const uint64_t P9N2_PERV_EC08_NET_CTRL1                                     = 0x280F0044ull;

static const uint64_t P9N2_PERV_EC08_NET_CTRL1_WAND                                = 0x280F0045ull;

static const uint64_t P9N2_PERV_EC08_NET_CTRL1_WOR                                 = 0x280F0046ull;

static const uint64_t P9N2_PERV_EC09_NET_CTRL1                                     = 0x290F0044ull;

static const uint64_t P9N2_PERV_EC09_NET_CTRL1_WAND                                = 0x290F0045ull;

static const uint64_t P9N2_PERV_EC09_NET_CTRL1_WOR                                 = 0x290F0046ull;

static const uint64_t P9N2_PERV_EC10_NET_CTRL1                                     = 0x2A0F0044ull;

static const uint64_t P9N2_PERV_EC10_NET_CTRL1_WAND                                = 0x2A0F0045ull;

static const uint64_t P9N2_PERV_EC10_NET_CTRL1_WOR                                 = 0x2A0F0046ull;

static const uint64_t P9N2_PERV_EC11_NET_CTRL1                                     = 0x2B0F0044ull;

static const uint64_t P9N2_PERV_EC11_NET_CTRL1_WAND                                = 0x2B0F0045ull;

static const uint64_t P9N2_PERV_EC11_NET_CTRL1_WOR                                 = 0x2B0F0046ull;

static const uint64_t P9N2_PERV_EC12_NET_CTRL1                                     = 0x2C0F0044ull;

static const uint64_t P9N2_PERV_EC12_NET_CTRL1_WAND                                = 0x2C0F0045ull;

static const uint64_t P9N2_PERV_EC12_NET_CTRL1_WOR                                 = 0x2C0F0046ull;

static const uint64_t P9N2_PERV_EC13_NET_CTRL1                                     = 0x2D0F0044ull;

static const uint64_t P9N2_PERV_EC13_NET_CTRL1_WAND                                = 0x2D0F0045ull;

static const uint64_t P9N2_PERV_EC13_NET_CTRL1_WOR                                 = 0x2D0F0046ull;

static const uint64_t P9N2_PERV_EC14_NET_CTRL1                                     = 0x2E0F0044ull;

static const uint64_t P9N2_PERV_EC14_NET_CTRL1_WAND                                = 0x2E0F0045ull;

static const uint64_t P9N2_PERV_EC14_NET_CTRL1_WOR                                 = 0x2E0F0046ull;

static const uint64_t P9N2_PERV_EC15_NET_CTRL1                                     = 0x2F0F0044ull;

static const uint64_t P9N2_PERV_EC15_NET_CTRL1_WAND                                = 0x2F0F0045ull;

static const uint64_t P9N2_PERV_EC15_NET_CTRL1_WOR                                 = 0x2F0F0046ull;

static const uint64_t P9N2_PERV_EC16_NET_CTRL1                                     = 0x300F0044ull;

static const uint64_t P9N2_PERV_EC16_NET_CTRL1_WAND                                = 0x300F0045ull;

static const uint64_t P9N2_PERV_EC16_NET_CTRL1_WOR                                 = 0x300F0046ull;

static const uint64_t P9N2_PERV_EC17_NET_CTRL1                                     = 0x310F0044ull;

static const uint64_t P9N2_PERV_EC17_NET_CTRL1_WAND                                = 0x310F0045ull;

static const uint64_t P9N2_PERV_EC17_NET_CTRL1_WOR                                 = 0x310F0046ull;

static const uint64_t P9N2_PERV_EC18_NET_CTRL1                                     = 0x320F0044ull;

static const uint64_t P9N2_PERV_EC18_NET_CTRL1_WAND                                = 0x320F0045ull;

static const uint64_t P9N2_PERV_EC18_NET_CTRL1_WOR                                 = 0x320F0046ull;

static const uint64_t P9N2_PERV_EC19_NET_CTRL1                                     = 0x330F0044ull;

static const uint64_t P9N2_PERV_EC19_NET_CTRL1_WAND                                = 0x330F0045ull;

static const uint64_t P9N2_PERV_EC19_NET_CTRL1_WOR                                 = 0x330F0046ull;

static const uint64_t P9N2_PERV_EC20_NET_CTRL1                                     = 0x340F0044ull;

static const uint64_t P9N2_PERV_EC20_NET_CTRL1_WAND                                = 0x340F0045ull;

static const uint64_t P9N2_PERV_EC20_NET_CTRL1_WOR                                 = 0x340F0046ull;

static const uint64_t P9N2_PERV_EC21_NET_CTRL1                                     = 0x350F0044ull;

static const uint64_t P9N2_PERV_EC21_NET_CTRL1_WAND                                = 0x350F0045ull;

static const uint64_t P9N2_PERV_EC21_NET_CTRL1_WOR                                 = 0x350F0046ull;

static const uint64_t P9N2_PERV_EC22_NET_CTRL1                                     = 0x360F0044ull;

static const uint64_t P9N2_PERV_EC22_NET_CTRL1_WAND                                = 0x360F0045ull;

static const uint64_t P9N2_PERV_EC22_NET_CTRL1_WOR                                 = 0x360F0046ull;

static const uint64_t P9N2_PERV_EC23_NET_CTRL1                                     = 0x370F0044ull;

static const uint64_t P9N2_PERV_EC23_NET_CTRL1_WAND                                = 0x370F0045ull;

static const uint64_t P9N2_PERV_EC23_NET_CTRL1_WOR                                 = 0x370F0046ull;


static const uint64_t P9N2_PERV_OCC_SCOM_OCCERRRPT                                 = 0x0001080Aull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCERRRPT                              = 0x0101080Aull;


static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIR                                   = 0x00010800ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIR                                = 0x01010800ull;

static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIR_AND                               = 0x00010801ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIR_AND                            = 0x01010801ull;

static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIR_OR                                = 0x00010802ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIR_OR                             = 0x01010802ull;


static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIRACT0                               = 0x00010806ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIRACT0                            = 0x01010806ull;


static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIRACT1                               = 0x00010807ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIRACT1                            = 0x01010807ull;


static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIRMASK                               = 0x00010803ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIRMASK                            = 0x01010803ull;

static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIRMASK_AND                           = 0x00010804ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIRMASK_AND                        = 0x01010804ull;

static const uint64_t P9N2_PERV_OCC_SCOM_OCCLFIRMASK_OR                            = 0x00010805ull;

static const uint64_t P9N2_PERV_TP_OCC_SCOM_OCCLFIRMASK_OR                         = 0x01010805ull;


static const uint64_t P9N2_PERV_OPCG_ALIGN                                         = 0x00030001ull;

static const uint64_t P9N2_PERV_TP_OPCG_ALIGN                                      = 0x01030001ull;

static const uint64_t P9N2_PERV_N0_OPCG_ALIGN                                      = 0x02030001ull;

static const uint64_t P9N2_PERV_N1_OPCG_ALIGN                                      = 0x03030001ull;

static const uint64_t P9N2_PERV_N2_OPCG_ALIGN                                      = 0x04030001ull;

static const uint64_t P9N2_PERV_N3_OPCG_ALIGN                                      = 0x05030001ull;

static const uint64_t P9N2_PERV_XB_OPCG_ALIGN                                      = 0x06030001ull;

static const uint64_t P9N2_PERV_MC01_OPCG_ALIGN                                    = 0x07030001ull;

static const uint64_t P9N2_PERV_MC23_OPCG_ALIGN                                    = 0x08030001ull;

static const uint64_t P9N2_PERV_OB0_OPCG_ALIGN                                     = 0x09030001ull;

static const uint64_t P9N2_PERV_OB3_OPCG_ALIGN                                     = 0x0C030001ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_ALIGN                                    = 0x0D030001ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_ALIGN                                    = 0x0E030001ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_ALIGN                                    = 0x0F030001ull;

static const uint64_t P9N2_PERV_EP00_OPCG_ALIGN                                    = 0x10030001ull;

static const uint64_t P9N2_PERV_EP01_OPCG_ALIGN                                    = 0x11030001ull;

static const uint64_t P9N2_PERV_EP02_OPCG_ALIGN                                    = 0x12030001ull;

static const uint64_t P9N2_PERV_EP03_OPCG_ALIGN                                    = 0x13030001ull;

static const uint64_t P9N2_PERV_EP04_OPCG_ALIGN                                    = 0x14030001ull;

static const uint64_t P9N2_PERV_EP05_OPCG_ALIGN                                    = 0x15030001ull;

static const uint64_t P9N2_PERV_EC00_OPCG_ALIGN                                    = 0x20030001ull;

static const uint64_t P9N2_PERV_EC01_OPCG_ALIGN                                    = 0x21030001ull;

static const uint64_t P9N2_PERV_EC02_OPCG_ALIGN                                    = 0x22030001ull;

static const uint64_t P9N2_PERV_EC03_OPCG_ALIGN                                    = 0x23030001ull;

static const uint64_t P9N2_PERV_EC04_OPCG_ALIGN                                    = 0x24030001ull;

static const uint64_t P9N2_PERV_EC05_OPCG_ALIGN                                    = 0x25030001ull;

static const uint64_t P9N2_PERV_EC06_OPCG_ALIGN                                    = 0x26030001ull;

static const uint64_t P9N2_PERV_EC07_OPCG_ALIGN                                    = 0x27030001ull;

static const uint64_t P9N2_PERV_EC08_OPCG_ALIGN                                    = 0x28030001ull;

static const uint64_t P9N2_PERV_EC09_OPCG_ALIGN                                    = 0x29030001ull;

static const uint64_t P9N2_PERV_EC10_OPCG_ALIGN                                    = 0x2A030001ull;

static const uint64_t P9N2_PERV_EC11_OPCG_ALIGN                                    = 0x2B030001ull;

static const uint64_t P9N2_PERV_EC12_OPCG_ALIGN                                    = 0x2C030001ull;

static const uint64_t P9N2_PERV_EC13_OPCG_ALIGN                                    = 0x2D030001ull;

static const uint64_t P9N2_PERV_EC14_OPCG_ALIGN                                    = 0x2E030001ull;

static const uint64_t P9N2_PERV_EC15_OPCG_ALIGN                                    = 0x2F030001ull;

static const uint64_t P9N2_PERV_EC16_OPCG_ALIGN                                    = 0x30030001ull;

static const uint64_t P9N2_PERV_EC17_OPCG_ALIGN                                    = 0x31030001ull;

static const uint64_t P9N2_PERV_EC18_OPCG_ALIGN                                    = 0x32030001ull;

static const uint64_t P9N2_PERV_EC19_OPCG_ALIGN                                    = 0x33030001ull;

static const uint64_t P9N2_PERV_EC20_OPCG_ALIGN                                    = 0x34030001ull;

static const uint64_t P9N2_PERV_EC21_OPCG_ALIGN                                    = 0x35030001ull;

static const uint64_t P9N2_PERV_EC22_OPCG_ALIGN                                    = 0x36030001ull;

static const uint64_t P9N2_PERV_EC23_OPCG_ALIGN                                    = 0x37030001ull;


static const uint64_t P9N2_PERV_OPCG_CAPT1                                         = 0x00030010ull;

static const uint64_t P9N2_PERV_TP_OPCG_CAPT1                                      = 0x01030010ull;

static const uint64_t P9N2_PERV_N0_OPCG_CAPT1                                      = 0x02030010ull;

static const uint64_t P9N2_PERV_N1_OPCG_CAPT1                                      = 0x03030010ull;

static const uint64_t P9N2_PERV_N2_OPCG_CAPT1                                      = 0x04030010ull;

static const uint64_t P9N2_PERV_N3_OPCG_CAPT1                                      = 0x05030010ull;

static const uint64_t P9N2_PERV_XB_OPCG_CAPT1                                      = 0x06030010ull;

static const uint64_t P9N2_PERV_MC01_OPCG_CAPT1                                    = 0x07030010ull;

static const uint64_t P9N2_PERV_MC23_OPCG_CAPT1                                    = 0x08030010ull;

static const uint64_t P9N2_PERV_OB0_OPCG_CAPT1                                     = 0x09030010ull;

static const uint64_t P9N2_PERV_OB3_OPCG_CAPT1                                     = 0x0C030010ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_CAPT1                                    = 0x0D030010ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_CAPT1                                    = 0x0E030010ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_CAPT1                                    = 0x0F030010ull;

static const uint64_t P9N2_PERV_EP00_OPCG_CAPT1                                    = 0x10030010ull;

static const uint64_t P9N2_PERV_EP01_OPCG_CAPT1                                    = 0x11030010ull;

static const uint64_t P9N2_PERV_EP02_OPCG_CAPT1                                    = 0x12030010ull;

static const uint64_t P9N2_PERV_EP03_OPCG_CAPT1                                    = 0x13030010ull;

static const uint64_t P9N2_PERV_EP04_OPCG_CAPT1                                    = 0x14030010ull;

static const uint64_t P9N2_PERV_EP05_OPCG_CAPT1                                    = 0x15030010ull;

static const uint64_t P9N2_PERV_EC00_OPCG_CAPT1                                    = 0x20030010ull;

static const uint64_t P9N2_PERV_EC01_OPCG_CAPT1                                    = 0x21030010ull;

static const uint64_t P9N2_PERV_EC02_OPCG_CAPT1                                    = 0x22030010ull;

static const uint64_t P9N2_PERV_EC03_OPCG_CAPT1                                    = 0x23030010ull;

static const uint64_t P9N2_PERV_EC04_OPCG_CAPT1                                    = 0x24030010ull;

static const uint64_t P9N2_PERV_EC05_OPCG_CAPT1                                    = 0x25030010ull;

static const uint64_t P9N2_PERV_EC06_OPCG_CAPT1                                    = 0x26030010ull;

static const uint64_t P9N2_PERV_EC07_OPCG_CAPT1                                    = 0x27030010ull;

static const uint64_t P9N2_PERV_EC08_OPCG_CAPT1                                    = 0x28030010ull;

static const uint64_t P9N2_PERV_EC09_OPCG_CAPT1                                    = 0x29030010ull;

static const uint64_t P9N2_PERV_EC10_OPCG_CAPT1                                    = 0x2A030010ull;

static const uint64_t P9N2_PERV_EC11_OPCG_CAPT1                                    = 0x2B030010ull;

static const uint64_t P9N2_PERV_EC12_OPCG_CAPT1                                    = 0x2C030010ull;

static const uint64_t P9N2_PERV_EC13_OPCG_CAPT1                                    = 0x2D030010ull;

static const uint64_t P9N2_PERV_EC14_OPCG_CAPT1                                    = 0x2E030010ull;

static const uint64_t P9N2_PERV_EC15_OPCG_CAPT1                                    = 0x2F030010ull;

static const uint64_t P9N2_PERV_EC16_OPCG_CAPT1                                    = 0x30030010ull;

static const uint64_t P9N2_PERV_EC17_OPCG_CAPT1                                    = 0x31030010ull;

static const uint64_t P9N2_PERV_EC18_OPCG_CAPT1                                    = 0x32030010ull;

static const uint64_t P9N2_PERV_EC19_OPCG_CAPT1                                    = 0x33030010ull;

static const uint64_t P9N2_PERV_EC20_OPCG_CAPT1                                    = 0x34030010ull;

static const uint64_t P9N2_PERV_EC21_OPCG_CAPT1                                    = 0x35030010ull;

static const uint64_t P9N2_PERV_EC22_OPCG_CAPT1                                    = 0x36030010ull;

static const uint64_t P9N2_PERV_EC23_OPCG_CAPT1                                    = 0x37030010ull;


static const uint64_t P9N2_PERV_OPCG_CAPT2                                         = 0x00030011ull;

static const uint64_t P9N2_PERV_TP_OPCG_CAPT2                                      = 0x01030011ull;

static const uint64_t P9N2_PERV_N0_OPCG_CAPT2                                      = 0x02030011ull;

static const uint64_t P9N2_PERV_N1_OPCG_CAPT2                                      = 0x03030011ull;

static const uint64_t P9N2_PERV_N2_OPCG_CAPT2                                      = 0x04030011ull;

static const uint64_t P9N2_PERV_N3_OPCG_CAPT2                                      = 0x05030011ull;

static const uint64_t P9N2_PERV_XB_OPCG_CAPT2                                      = 0x06030011ull;

static const uint64_t P9N2_PERV_MC01_OPCG_CAPT2                                    = 0x07030011ull;

static const uint64_t P9N2_PERV_MC23_OPCG_CAPT2                                    = 0x08030011ull;

static const uint64_t P9N2_PERV_OB0_OPCG_CAPT2                                     = 0x09030011ull;

static const uint64_t P9N2_PERV_OB3_OPCG_CAPT2                                     = 0x0C030011ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_CAPT2                                    = 0x0D030011ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_CAPT2                                    = 0x0E030011ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_CAPT2                                    = 0x0F030011ull;

static const uint64_t P9N2_PERV_EP00_OPCG_CAPT2                                    = 0x10030011ull;

static const uint64_t P9N2_PERV_EP01_OPCG_CAPT2                                    = 0x11030011ull;

static const uint64_t P9N2_PERV_EP02_OPCG_CAPT2                                    = 0x12030011ull;

static const uint64_t P9N2_PERV_EP03_OPCG_CAPT2                                    = 0x13030011ull;

static const uint64_t P9N2_PERV_EP04_OPCG_CAPT2                                    = 0x14030011ull;

static const uint64_t P9N2_PERV_EP05_OPCG_CAPT2                                    = 0x15030011ull;

static const uint64_t P9N2_PERV_EC00_OPCG_CAPT2                                    = 0x20030011ull;

static const uint64_t P9N2_PERV_EC01_OPCG_CAPT2                                    = 0x21030011ull;

static const uint64_t P9N2_PERV_EC02_OPCG_CAPT2                                    = 0x22030011ull;

static const uint64_t P9N2_PERV_EC03_OPCG_CAPT2                                    = 0x23030011ull;

static const uint64_t P9N2_PERV_EC04_OPCG_CAPT2                                    = 0x24030011ull;

static const uint64_t P9N2_PERV_EC05_OPCG_CAPT2                                    = 0x25030011ull;

static const uint64_t P9N2_PERV_EC06_OPCG_CAPT2                                    = 0x26030011ull;

static const uint64_t P9N2_PERV_EC07_OPCG_CAPT2                                    = 0x27030011ull;

static const uint64_t P9N2_PERV_EC08_OPCG_CAPT2                                    = 0x28030011ull;

static const uint64_t P9N2_PERV_EC09_OPCG_CAPT2                                    = 0x29030011ull;

static const uint64_t P9N2_PERV_EC10_OPCG_CAPT2                                    = 0x2A030011ull;

static const uint64_t P9N2_PERV_EC11_OPCG_CAPT2                                    = 0x2B030011ull;

static const uint64_t P9N2_PERV_EC12_OPCG_CAPT2                                    = 0x2C030011ull;

static const uint64_t P9N2_PERV_EC13_OPCG_CAPT2                                    = 0x2D030011ull;

static const uint64_t P9N2_PERV_EC14_OPCG_CAPT2                                    = 0x2E030011ull;

static const uint64_t P9N2_PERV_EC15_OPCG_CAPT2                                    = 0x2F030011ull;

static const uint64_t P9N2_PERV_EC16_OPCG_CAPT2                                    = 0x30030011ull;

static const uint64_t P9N2_PERV_EC17_OPCG_CAPT2                                    = 0x31030011ull;

static const uint64_t P9N2_PERV_EC18_OPCG_CAPT2                                    = 0x32030011ull;

static const uint64_t P9N2_PERV_EC19_OPCG_CAPT2                                    = 0x33030011ull;

static const uint64_t P9N2_PERV_EC20_OPCG_CAPT2                                    = 0x34030011ull;

static const uint64_t P9N2_PERV_EC21_OPCG_CAPT2                                    = 0x35030011ull;

static const uint64_t P9N2_PERV_EC22_OPCG_CAPT2                                    = 0x36030011ull;

static const uint64_t P9N2_PERV_EC23_OPCG_CAPT2                                    = 0x37030011ull;


static const uint64_t P9N2_PERV_OPCG_CAPT3                                         = 0x00030012ull;

static const uint64_t P9N2_PERV_TP_OPCG_CAPT3                                      = 0x01030012ull;

static const uint64_t P9N2_PERV_N0_OPCG_CAPT3                                      = 0x02030012ull;

static const uint64_t P9N2_PERV_N1_OPCG_CAPT3                                      = 0x03030012ull;

static const uint64_t P9N2_PERV_N2_OPCG_CAPT3                                      = 0x04030012ull;

static const uint64_t P9N2_PERV_N3_OPCG_CAPT3                                      = 0x05030012ull;

static const uint64_t P9N2_PERV_XB_OPCG_CAPT3                                      = 0x06030012ull;

static const uint64_t P9N2_PERV_MC01_OPCG_CAPT3                                    = 0x07030012ull;

static const uint64_t P9N2_PERV_MC23_OPCG_CAPT3                                    = 0x08030012ull;

static const uint64_t P9N2_PERV_OB0_OPCG_CAPT3                                     = 0x09030012ull;

static const uint64_t P9N2_PERV_OB3_OPCG_CAPT3                                     = 0x0C030012ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_CAPT3                                    = 0x0D030012ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_CAPT3                                    = 0x0E030012ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_CAPT3                                    = 0x0F030012ull;

static const uint64_t P9N2_PERV_EP00_OPCG_CAPT3                                    = 0x10030012ull;

static const uint64_t P9N2_PERV_EP01_OPCG_CAPT3                                    = 0x11030012ull;

static const uint64_t P9N2_PERV_EP02_OPCG_CAPT3                                    = 0x12030012ull;

static const uint64_t P9N2_PERV_EP03_OPCG_CAPT3                                    = 0x13030012ull;

static const uint64_t P9N2_PERV_EP04_OPCG_CAPT3                                    = 0x14030012ull;

static const uint64_t P9N2_PERV_EP05_OPCG_CAPT3                                    = 0x15030012ull;

static const uint64_t P9N2_PERV_EC00_OPCG_CAPT3                                    = 0x20030012ull;

static const uint64_t P9N2_PERV_EC01_OPCG_CAPT3                                    = 0x21030012ull;

static const uint64_t P9N2_PERV_EC02_OPCG_CAPT3                                    = 0x22030012ull;

static const uint64_t P9N2_PERV_EC03_OPCG_CAPT3                                    = 0x23030012ull;

static const uint64_t P9N2_PERV_EC04_OPCG_CAPT3                                    = 0x24030012ull;

static const uint64_t P9N2_PERV_EC05_OPCG_CAPT3                                    = 0x25030012ull;

static const uint64_t P9N2_PERV_EC06_OPCG_CAPT3                                    = 0x26030012ull;

static const uint64_t P9N2_PERV_EC07_OPCG_CAPT3                                    = 0x27030012ull;

static const uint64_t P9N2_PERV_EC08_OPCG_CAPT3                                    = 0x28030012ull;

static const uint64_t P9N2_PERV_EC09_OPCG_CAPT3                                    = 0x29030012ull;

static const uint64_t P9N2_PERV_EC10_OPCG_CAPT3                                    = 0x2A030012ull;

static const uint64_t P9N2_PERV_EC11_OPCG_CAPT3                                    = 0x2B030012ull;

static const uint64_t P9N2_PERV_EC12_OPCG_CAPT3                                    = 0x2C030012ull;

static const uint64_t P9N2_PERV_EC13_OPCG_CAPT3                                    = 0x2D030012ull;

static const uint64_t P9N2_PERV_EC14_OPCG_CAPT3                                    = 0x2E030012ull;

static const uint64_t P9N2_PERV_EC15_OPCG_CAPT3                                    = 0x2F030012ull;

static const uint64_t P9N2_PERV_EC16_OPCG_CAPT3                                    = 0x30030012ull;

static const uint64_t P9N2_PERV_EC17_OPCG_CAPT3                                    = 0x31030012ull;

static const uint64_t P9N2_PERV_EC18_OPCG_CAPT3                                    = 0x32030012ull;

static const uint64_t P9N2_PERV_EC19_OPCG_CAPT3                                    = 0x33030012ull;

static const uint64_t P9N2_PERV_EC20_OPCG_CAPT3                                    = 0x34030012ull;

static const uint64_t P9N2_PERV_EC21_OPCG_CAPT3                                    = 0x35030012ull;

static const uint64_t P9N2_PERV_EC22_OPCG_CAPT3                                    = 0x36030012ull;

static const uint64_t P9N2_PERV_EC23_OPCG_CAPT3                                    = 0x37030012ull;


static const uint64_t P9N2_PERV_OPCG_REG0                                          = 0x00030002ull;

static const uint64_t P9N2_PERV_TP_OPCG_REG0                                       = 0x01030002ull;

static const uint64_t P9N2_PERV_N0_OPCG_REG0                                       = 0x02030002ull;

static const uint64_t P9N2_PERV_N1_OPCG_REG0                                       = 0x03030002ull;

static const uint64_t P9N2_PERV_N2_OPCG_REG0                                       = 0x04030002ull;

static const uint64_t P9N2_PERV_N3_OPCG_REG0                                       = 0x05030002ull;

static const uint64_t P9N2_PERV_XB_OPCG_REG0                                       = 0x06030002ull;

static const uint64_t P9N2_PERV_MC01_OPCG_REG0                                     = 0x07030002ull;

static const uint64_t P9N2_PERV_MC23_OPCG_REG0                                     = 0x08030002ull;

static const uint64_t P9N2_PERV_OB0_OPCG_REG0                                      = 0x09030002ull;

static const uint64_t P9N2_PERV_OB3_OPCG_REG0                                      = 0x0C030002ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_REG0                                     = 0x0D030002ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_REG0                                     = 0x0E030002ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_REG0                                     = 0x0F030002ull;

static const uint64_t P9N2_PERV_EP00_OPCG_REG0                                     = 0x10030002ull;

static const uint64_t P9N2_PERV_EP01_OPCG_REG0                                     = 0x11030002ull;

static const uint64_t P9N2_PERV_EP02_OPCG_REG0                                     = 0x12030002ull;

static const uint64_t P9N2_PERV_EP03_OPCG_REG0                                     = 0x13030002ull;

static const uint64_t P9N2_PERV_EP04_OPCG_REG0                                     = 0x14030002ull;

static const uint64_t P9N2_PERV_EP05_OPCG_REG0                                     = 0x15030002ull;

static const uint64_t P9N2_PERV_EC00_OPCG_REG0                                     = 0x20030002ull;

static const uint64_t P9N2_PERV_EC01_OPCG_REG0                                     = 0x21030002ull;

static const uint64_t P9N2_PERV_EC02_OPCG_REG0                                     = 0x22030002ull;

static const uint64_t P9N2_PERV_EC03_OPCG_REG0                                     = 0x23030002ull;

static const uint64_t P9N2_PERV_EC04_OPCG_REG0                                     = 0x24030002ull;

static const uint64_t P9N2_PERV_EC05_OPCG_REG0                                     = 0x25030002ull;

static const uint64_t P9N2_PERV_EC06_OPCG_REG0                                     = 0x26030002ull;

static const uint64_t P9N2_PERV_EC07_OPCG_REG0                                     = 0x27030002ull;

static const uint64_t P9N2_PERV_EC08_OPCG_REG0                                     = 0x28030002ull;

static const uint64_t P9N2_PERV_EC09_OPCG_REG0                                     = 0x29030002ull;

static const uint64_t P9N2_PERV_EC10_OPCG_REG0                                     = 0x2A030002ull;

static const uint64_t P9N2_PERV_EC11_OPCG_REG0                                     = 0x2B030002ull;

static const uint64_t P9N2_PERV_EC12_OPCG_REG0                                     = 0x2C030002ull;

static const uint64_t P9N2_PERV_EC13_OPCG_REG0                                     = 0x2D030002ull;

static const uint64_t P9N2_PERV_EC14_OPCG_REG0                                     = 0x2E030002ull;

static const uint64_t P9N2_PERV_EC15_OPCG_REG0                                     = 0x2F030002ull;

static const uint64_t P9N2_PERV_EC16_OPCG_REG0                                     = 0x30030002ull;

static const uint64_t P9N2_PERV_EC17_OPCG_REG0                                     = 0x31030002ull;

static const uint64_t P9N2_PERV_EC18_OPCG_REG0                                     = 0x32030002ull;

static const uint64_t P9N2_PERV_EC19_OPCG_REG0                                     = 0x33030002ull;

static const uint64_t P9N2_PERV_EC20_OPCG_REG0                                     = 0x34030002ull;

static const uint64_t P9N2_PERV_EC21_OPCG_REG0                                     = 0x35030002ull;

static const uint64_t P9N2_PERV_EC22_OPCG_REG0                                     = 0x36030002ull;

static const uint64_t P9N2_PERV_EC23_OPCG_REG0                                     = 0x37030002ull;


static const uint64_t P9N2_PERV_OPCG_REG1                                          = 0x00030003ull;

static const uint64_t P9N2_PERV_TP_OPCG_REG1                                       = 0x01030003ull;

static const uint64_t P9N2_PERV_N0_OPCG_REG1                                       = 0x02030003ull;

static const uint64_t P9N2_PERV_N1_OPCG_REG1                                       = 0x03030003ull;

static const uint64_t P9N2_PERV_N2_OPCG_REG1                                       = 0x04030003ull;

static const uint64_t P9N2_PERV_N3_OPCG_REG1                                       = 0x05030003ull;

static const uint64_t P9N2_PERV_XB_OPCG_REG1                                       = 0x06030003ull;

static const uint64_t P9N2_PERV_MC01_OPCG_REG1                                     = 0x07030003ull;

static const uint64_t P9N2_PERV_MC23_OPCG_REG1                                     = 0x08030003ull;

static const uint64_t P9N2_PERV_OB0_OPCG_REG1                                      = 0x09030003ull;

static const uint64_t P9N2_PERV_OB3_OPCG_REG1                                      = 0x0C030003ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_REG1                                     = 0x0D030003ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_REG1                                     = 0x0E030003ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_REG1                                     = 0x0F030003ull;

static const uint64_t P9N2_PERV_EP00_OPCG_REG1                                     = 0x10030003ull;

static const uint64_t P9N2_PERV_EP01_OPCG_REG1                                     = 0x11030003ull;

static const uint64_t P9N2_PERV_EP02_OPCG_REG1                                     = 0x12030003ull;

static const uint64_t P9N2_PERV_EP03_OPCG_REG1                                     = 0x13030003ull;

static const uint64_t P9N2_PERV_EP04_OPCG_REG1                                     = 0x14030003ull;

static const uint64_t P9N2_PERV_EP05_OPCG_REG1                                     = 0x15030003ull;

static const uint64_t P9N2_PERV_EC00_OPCG_REG1                                     = 0x20030003ull;

static const uint64_t P9N2_PERV_EC01_OPCG_REG1                                     = 0x21030003ull;

static const uint64_t P9N2_PERV_EC02_OPCG_REG1                                     = 0x22030003ull;

static const uint64_t P9N2_PERV_EC03_OPCG_REG1                                     = 0x23030003ull;

static const uint64_t P9N2_PERV_EC04_OPCG_REG1                                     = 0x24030003ull;

static const uint64_t P9N2_PERV_EC05_OPCG_REG1                                     = 0x25030003ull;

static const uint64_t P9N2_PERV_EC06_OPCG_REG1                                     = 0x26030003ull;

static const uint64_t P9N2_PERV_EC07_OPCG_REG1                                     = 0x27030003ull;

static const uint64_t P9N2_PERV_EC08_OPCG_REG1                                     = 0x28030003ull;

static const uint64_t P9N2_PERV_EC09_OPCG_REG1                                     = 0x29030003ull;

static const uint64_t P9N2_PERV_EC10_OPCG_REG1                                     = 0x2A030003ull;

static const uint64_t P9N2_PERV_EC11_OPCG_REG1                                     = 0x2B030003ull;

static const uint64_t P9N2_PERV_EC12_OPCG_REG1                                     = 0x2C030003ull;

static const uint64_t P9N2_PERV_EC13_OPCG_REG1                                     = 0x2D030003ull;

static const uint64_t P9N2_PERV_EC14_OPCG_REG1                                     = 0x2E030003ull;

static const uint64_t P9N2_PERV_EC15_OPCG_REG1                                     = 0x2F030003ull;

static const uint64_t P9N2_PERV_EC16_OPCG_REG1                                     = 0x30030003ull;

static const uint64_t P9N2_PERV_EC17_OPCG_REG1                                     = 0x31030003ull;

static const uint64_t P9N2_PERV_EC18_OPCG_REG1                                     = 0x32030003ull;

static const uint64_t P9N2_PERV_EC19_OPCG_REG1                                     = 0x33030003ull;

static const uint64_t P9N2_PERV_EC20_OPCG_REG1                                     = 0x34030003ull;

static const uint64_t P9N2_PERV_EC21_OPCG_REG1                                     = 0x35030003ull;

static const uint64_t P9N2_PERV_EC22_OPCG_REG1                                     = 0x36030003ull;

static const uint64_t P9N2_PERV_EC23_OPCG_REG1                                     = 0x37030003ull;


static const uint64_t P9N2_PERV_OPCG_REG2                                          = 0x00030004ull;

static const uint64_t P9N2_PERV_TP_OPCG_REG2                                       = 0x01030004ull;

static const uint64_t P9N2_PERV_N0_OPCG_REG2                                       = 0x02030004ull;

static const uint64_t P9N2_PERV_N1_OPCG_REG2                                       = 0x03030004ull;

static const uint64_t P9N2_PERV_N2_OPCG_REG2                                       = 0x04030004ull;

static const uint64_t P9N2_PERV_N3_OPCG_REG2                                       = 0x05030004ull;

static const uint64_t P9N2_PERV_XB_OPCG_REG2                                       = 0x06030004ull;

static const uint64_t P9N2_PERV_MC01_OPCG_REG2                                     = 0x07030004ull;

static const uint64_t P9N2_PERV_MC23_OPCG_REG2                                     = 0x08030004ull;

static const uint64_t P9N2_PERV_OB0_OPCG_REG2                                      = 0x09030004ull;

static const uint64_t P9N2_PERV_OB3_OPCG_REG2                                      = 0x0C030004ull;

static const uint64_t P9N2_PERV_PCI0_OPCG_REG2                                     = 0x0D030004ull;

static const uint64_t P9N2_PERV_PCI1_OPCG_REG2                                     = 0x0E030004ull;

static const uint64_t P9N2_PERV_PCI2_OPCG_REG2                                     = 0x0F030004ull;

static const uint64_t P9N2_PERV_EP00_OPCG_REG2                                     = 0x10030004ull;

static const uint64_t P9N2_PERV_EP01_OPCG_REG2                                     = 0x11030004ull;

static const uint64_t P9N2_PERV_EP02_OPCG_REG2                                     = 0x12030004ull;

static const uint64_t P9N2_PERV_EP03_OPCG_REG2                                     = 0x13030004ull;

static const uint64_t P9N2_PERV_EP04_OPCG_REG2                                     = 0x14030004ull;

static const uint64_t P9N2_PERV_EP05_OPCG_REG2                                     = 0x15030004ull;

static const uint64_t P9N2_PERV_EC00_OPCG_REG2                                     = 0x20030004ull;

static const uint64_t P9N2_PERV_EC01_OPCG_REG2                                     = 0x21030004ull;

static const uint64_t P9N2_PERV_EC02_OPCG_REG2                                     = 0x22030004ull;

static const uint64_t P9N2_PERV_EC03_OPCG_REG2                                     = 0x23030004ull;

static const uint64_t P9N2_PERV_EC04_OPCG_REG2                                     = 0x24030004ull;

static const uint64_t P9N2_PERV_EC05_OPCG_REG2                                     = 0x25030004ull;

static const uint64_t P9N2_PERV_EC06_OPCG_REG2                                     = 0x26030004ull;

static const uint64_t P9N2_PERV_EC07_OPCG_REG2                                     = 0x27030004ull;

static const uint64_t P9N2_PERV_EC08_OPCG_REG2                                     = 0x28030004ull;

static const uint64_t P9N2_PERV_EC09_OPCG_REG2                                     = 0x29030004ull;

static const uint64_t P9N2_PERV_EC10_OPCG_REG2                                     = 0x2A030004ull;

static const uint64_t P9N2_PERV_EC11_OPCG_REG2                                     = 0x2B030004ull;

static const uint64_t P9N2_PERV_EC12_OPCG_REG2                                     = 0x2C030004ull;

static const uint64_t P9N2_PERV_EC13_OPCG_REG2                                     = 0x2D030004ull;

static const uint64_t P9N2_PERV_EC14_OPCG_REG2                                     = 0x2E030004ull;

static const uint64_t P9N2_PERV_EC15_OPCG_REG2                                     = 0x2F030004ull;

static const uint64_t P9N2_PERV_EC16_OPCG_REG2                                     = 0x30030004ull;

static const uint64_t P9N2_PERV_EC17_OPCG_REG2                                     = 0x31030004ull;

static const uint64_t P9N2_PERV_EC18_OPCG_REG2                                     = 0x32030004ull;

static const uint64_t P9N2_PERV_EC19_OPCG_REG2                                     = 0x33030004ull;

static const uint64_t P9N2_PERV_EC20_OPCG_REG2                                     = 0x34030004ull;

static const uint64_t P9N2_PERV_EC21_OPCG_REG2                                     = 0x35030004ull;

static const uint64_t P9N2_PERV_EC22_OPCG_REG2                                     = 0x36030004ull;

static const uint64_t P9N2_PERV_EC23_OPCG_REG2                                     = 0x37030004ull;


static const uint64_t P9N2_PERV_OSCERR_HOLD                                        = 0x00020019ull;

static const uint64_t P9N2_PERV_TP_OSCERR_HOLD                                     = 0x01020019ull;


static const uint64_t P9N2_PERV_OSCERR_MASK                                        = 0x0002001Aull;

static const uint64_t P9N2_PERV_TP_OSCERR_MASK                                     = 0x0102001Aull;


static const uint64_t P9N2_PERV_OSCERR_MCODE                                       = 0x0002001Bull;

static const uint64_t P9N2_PERV_TP_OSCERR_MCODE                                    = 0x0102001Bull;


static const uint64_t P9N2_PERV_PCB_OPCG_GO                                        = 0x00030020ull;

static const uint64_t P9N2_PERV_TP_PCB_OPCG_GO                                     = 0x01030020ull;

static const uint64_t P9N2_PERV_N0_PCB_OPCG_GO                                     = 0x02030020ull;

static const uint64_t P9N2_PERV_N1_PCB_OPCG_GO                                     = 0x03030020ull;

static const uint64_t P9N2_PERV_N2_PCB_OPCG_GO                                     = 0x04030020ull;

static const uint64_t P9N2_PERV_N3_PCB_OPCG_GO                                     = 0x05030020ull;

static const uint64_t P9N2_PERV_XB_PCB_OPCG_GO                                     = 0x06030020ull;

static const uint64_t P9N2_PERV_MC01_PCB_OPCG_GO                                   = 0x07030020ull;

static const uint64_t P9N2_PERV_MC23_PCB_OPCG_GO                                   = 0x08030020ull;

static const uint64_t P9N2_PERV_OB0_PCB_OPCG_GO                                    = 0x09030020ull;

static const uint64_t P9N2_PERV_OB3_PCB_OPCG_GO                                    = 0x0C030020ull;

static const uint64_t P9N2_PERV_PCI0_PCB_OPCG_GO                                   = 0x0D030020ull;

static const uint64_t P9N2_PERV_PCI1_PCB_OPCG_GO                                   = 0x0E030020ull;

static const uint64_t P9N2_PERV_PCI2_PCB_OPCG_GO                                   = 0x0F030020ull;

static const uint64_t P9N2_PERV_EP00_PCB_OPCG_GO                                   = 0x10030020ull;

static const uint64_t P9N2_PERV_EP01_PCB_OPCG_GO                                   = 0x11030020ull;

static const uint64_t P9N2_PERV_EP02_PCB_OPCG_GO                                   = 0x12030020ull;

static const uint64_t P9N2_PERV_EP03_PCB_OPCG_GO                                   = 0x13030020ull;

static const uint64_t P9N2_PERV_EP04_PCB_OPCG_GO                                   = 0x14030020ull;

static const uint64_t P9N2_PERV_EP05_PCB_OPCG_GO                                   = 0x15030020ull;

static const uint64_t P9N2_PERV_EC00_PCB_OPCG_GO                                   = 0x20030020ull;

static const uint64_t P9N2_PERV_EC01_PCB_OPCG_GO                                   = 0x21030020ull;

static const uint64_t P9N2_PERV_EC02_PCB_OPCG_GO                                   = 0x22030020ull;

static const uint64_t P9N2_PERV_EC03_PCB_OPCG_GO                                   = 0x23030020ull;

static const uint64_t P9N2_PERV_EC04_PCB_OPCG_GO                                   = 0x24030020ull;

static const uint64_t P9N2_PERV_EC05_PCB_OPCG_GO                                   = 0x25030020ull;

static const uint64_t P9N2_PERV_EC06_PCB_OPCG_GO                                   = 0x26030020ull;

static const uint64_t P9N2_PERV_EC07_PCB_OPCG_GO                                   = 0x27030020ull;

static const uint64_t P9N2_PERV_EC08_PCB_OPCG_GO                                   = 0x28030020ull;

static const uint64_t P9N2_PERV_EC09_PCB_OPCG_GO                                   = 0x29030020ull;

static const uint64_t P9N2_PERV_EC10_PCB_OPCG_GO                                   = 0x2A030020ull;

static const uint64_t P9N2_PERV_EC11_PCB_OPCG_GO                                   = 0x2B030020ull;

static const uint64_t P9N2_PERV_EC12_PCB_OPCG_GO                                   = 0x2C030020ull;

static const uint64_t P9N2_PERV_EC13_PCB_OPCG_GO                                   = 0x2D030020ull;

static const uint64_t P9N2_PERV_EC14_PCB_OPCG_GO                                   = 0x2E030020ull;

static const uint64_t P9N2_PERV_EC15_PCB_OPCG_GO                                   = 0x2F030020ull;

static const uint64_t P9N2_PERV_EC16_PCB_OPCG_GO                                   = 0x30030020ull;

static const uint64_t P9N2_PERV_EC17_PCB_OPCG_GO                                   = 0x31030020ull;

static const uint64_t P9N2_PERV_EC18_PCB_OPCG_GO                                   = 0x32030020ull;

static const uint64_t P9N2_PERV_EC19_PCB_OPCG_GO                                   = 0x33030020ull;

static const uint64_t P9N2_PERV_EC20_PCB_OPCG_GO                                   = 0x34030020ull;

static const uint64_t P9N2_PERV_EC21_PCB_OPCG_GO                                   = 0x35030020ull;

static const uint64_t P9N2_PERV_EC22_PCB_OPCG_GO                                   = 0x36030020ull;

static const uint64_t P9N2_PERV_EC23_PCB_OPCG_GO                                   = 0x37030020ull;


static const uint64_t P9N2_PERV_PCB_OPCG_STOP                                      = 0x00030030ull;

static const uint64_t P9N2_PERV_TP_PCB_OPCG_STOP                                   = 0x01030030ull;

static const uint64_t P9N2_PERV_N0_PCB_OPCG_STOP                                   = 0x02030030ull;

static const uint64_t P9N2_PERV_N1_PCB_OPCG_STOP                                   = 0x03030030ull;

static const uint64_t P9N2_PERV_N2_PCB_OPCG_STOP                                   = 0x04030030ull;

static const uint64_t P9N2_PERV_N3_PCB_OPCG_STOP                                   = 0x05030030ull;

static const uint64_t P9N2_PERV_XB_PCB_OPCG_STOP                                   = 0x06030030ull;

static const uint64_t P9N2_PERV_MC01_PCB_OPCG_STOP                                 = 0x07030030ull;

static const uint64_t P9N2_PERV_MC23_PCB_OPCG_STOP                                 = 0x08030030ull;

static const uint64_t P9N2_PERV_OB0_PCB_OPCG_STOP                                  = 0x09030030ull;

static const uint64_t P9N2_PERV_OB3_PCB_OPCG_STOP                                  = 0x0C030030ull;

static const uint64_t P9N2_PERV_PCI0_PCB_OPCG_STOP                                 = 0x0D030030ull;

static const uint64_t P9N2_PERV_PCI1_PCB_OPCG_STOP                                 = 0x0E030030ull;

static const uint64_t P9N2_PERV_PCI2_PCB_OPCG_STOP                                 = 0x0F030030ull;

static const uint64_t P9N2_PERV_EP00_PCB_OPCG_STOP                                 = 0x10030030ull;

static const uint64_t P9N2_PERV_EP01_PCB_OPCG_STOP                                 = 0x11030030ull;

static const uint64_t P9N2_PERV_EP02_PCB_OPCG_STOP                                 = 0x12030030ull;

static const uint64_t P9N2_PERV_EP03_PCB_OPCG_STOP                                 = 0x13030030ull;

static const uint64_t P9N2_PERV_EP04_PCB_OPCG_STOP                                 = 0x14030030ull;

static const uint64_t P9N2_PERV_EP05_PCB_OPCG_STOP                                 = 0x15030030ull;

static const uint64_t P9N2_PERV_EC00_PCB_OPCG_STOP                                 = 0x20030030ull;

static const uint64_t P9N2_PERV_EC01_PCB_OPCG_STOP                                 = 0x21030030ull;

static const uint64_t P9N2_PERV_EC02_PCB_OPCG_STOP                                 = 0x22030030ull;

static const uint64_t P9N2_PERV_EC03_PCB_OPCG_STOP                                 = 0x23030030ull;

static const uint64_t P9N2_PERV_EC04_PCB_OPCG_STOP                                 = 0x24030030ull;

static const uint64_t P9N2_PERV_EC05_PCB_OPCG_STOP                                 = 0x25030030ull;

static const uint64_t P9N2_PERV_EC06_PCB_OPCG_STOP                                 = 0x26030030ull;

static const uint64_t P9N2_PERV_EC07_PCB_OPCG_STOP                                 = 0x27030030ull;

static const uint64_t P9N2_PERV_EC08_PCB_OPCG_STOP                                 = 0x28030030ull;

static const uint64_t P9N2_PERV_EC09_PCB_OPCG_STOP                                 = 0x29030030ull;

static const uint64_t P9N2_PERV_EC10_PCB_OPCG_STOP                                 = 0x2A030030ull;

static const uint64_t P9N2_PERV_EC11_PCB_OPCG_STOP                                 = 0x2B030030ull;

static const uint64_t P9N2_PERV_EC12_PCB_OPCG_STOP                                 = 0x2C030030ull;

static const uint64_t P9N2_PERV_EC13_PCB_OPCG_STOP                                 = 0x2D030030ull;

static const uint64_t P9N2_PERV_EC14_PCB_OPCG_STOP                                 = 0x2E030030ull;

static const uint64_t P9N2_PERV_EC15_PCB_OPCG_STOP                                 = 0x2F030030ull;

static const uint64_t P9N2_PERV_EC16_PCB_OPCG_STOP                                 = 0x30030030ull;

static const uint64_t P9N2_PERV_EC17_PCB_OPCG_STOP                                 = 0x31030030ull;

static const uint64_t P9N2_PERV_EC18_PCB_OPCG_STOP                                 = 0x32030030ull;

static const uint64_t P9N2_PERV_EC19_PCB_OPCG_STOP                                 = 0x33030030ull;

static const uint64_t P9N2_PERV_EC20_PCB_OPCG_STOP                                 = 0x34030030ull;

static const uint64_t P9N2_PERV_EC21_PCB_OPCG_STOP                                 = 0x35030030ull;

static const uint64_t P9N2_PERV_EC22_PCB_OPCG_STOP                                 = 0x36030030ull;

static const uint64_t P9N2_PERV_EC23_PCB_OPCG_STOP                                 = 0x37030030ull;


static const uint32_t P9N2_PERV_PEEK4A0_FSI                                        = 0x000004A0ull;


static const uint32_t P9N2_PERV_PEEK4A4_FSI                                        = 0x000004A4ull;


static const uint32_t P9N2_PERV_PEEK4A8_FSI                                        = 0x000004A8ull;


static const uint32_t P9N2_PERV_PEEK4AC_FSI                                        = 0x000004ACull;


static const uint32_t P9N2_PERV_PEEK4B0_FSI                                        = 0x000004B0ull;


static const uint32_t P9N2_PERV_PEEK4B4_FSI                                        = 0x000004B4ull;


static const uint32_t P9N2_PERV_PEEK4B8_FSI                                        = 0x000004B8ull;


static const uint32_t P9N2_PERV_PERV_CTRL0_FSI                                     = 0x0000281Aull;

static const uint32_t P9N2_PERV_PERV_CTRL0_FSI_BYTE                                = 0x00002868ull;

static const uint64_t P9N2_PERV_PERV_CTRL0_SCOM                                    = 0x0005001Aull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL0                                     = 0x0005001Aull;


static const uint32_t P9N2_PERV_PERV_CTRL0_CLEAR_FSI                               = 0x0000293Aull;

static const uint32_t P9N2_PERV_PERV_CTRL0_CLEAR_FSI_BYTE                          = 0x00002CE8ull;

static const uint64_t P9N2_PERV_PERV_CTRL0_CLEAR_SCOM                              = 0x0005013Aull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL0_CLEAR                               = 0x0005013Aull;


static const uint32_t P9N2_PERV_PERV_CTRL0_COPY_FSI                                = 0x0000291Aull;

static const uint32_t P9N2_PERV_PERV_CTRL0_COPY_FSI_BYTE                           = 0x00002C68ull;

static const uint64_t P9N2_PERV_PERV_CTRL0_COPY_SCOM                               = 0x0005011Aull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL0_COPY                                = 0x0005011Aull;


static const uint32_t P9N2_PERV_PERV_CTRL0_SET_FSI                                 = 0x0000292Aull;

static const uint32_t P9N2_PERV_PERV_CTRL0_SET_FSI_BYTE                            = 0x00002CA8ull;

static const uint64_t P9N2_PERV_PERV_CTRL0_SET_SCOM                                = 0x0005012Aull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL0_SET                                 = 0x0005012Aull;


static const uint32_t P9N2_PERV_PERV_CTRL1_FSI                                     = 0x0000281Bull;

static const uint32_t P9N2_PERV_PERV_CTRL1_FSI_BYTE                                = 0x0000286Cull;

static const uint64_t P9N2_PERV_PERV_CTRL1_SCOM                                    = 0x0005001Bull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL1                                     = 0x0005001Bull;


static const uint32_t P9N2_PERV_PERV_CTRL1_CLEAR_FSI                               = 0x0000293Bull;

static const uint32_t P9N2_PERV_PERV_CTRL1_CLEAR_FSI_BYTE                          = 0x00002CECull;

static const uint64_t P9N2_PERV_PERV_CTRL1_CLEAR_SCOM                              = 0x0005013Bull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL1_CLEAR                               = 0x0005013Bull;


static const uint32_t P9N2_PERV_PERV_CTRL1_COPY_FSI                                = 0x0000291Bull;

static const uint32_t P9N2_PERV_PERV_CTRL1_COPY_FSI_BYTE                           = 0x00002C6Cull;

static const uint64_t P9N2_PERV_PERV_CTRL1_COPY_SCOM                               = 0x0005011Bull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL1_COPY                                = 0x0005011Bull;


static const uint32_t P9N2_PERV_PERV_CTRL1_SET_FSI                                 = 0x0000292Bull;

static const uint32_t P9N2_PERV_PERV_CTRL1_SET_FSI_BYTE                            = 0x00002CACull;

static const uint64_t P9N2_PERV_PERV_CTRL1_SET_SCOM                                = 0x0005012Bull;

static const uint64_t P9N2_PERV_PIB_PERV_CTRL1_SET                                 = 0x0005012Bull;


static const uint64_t P9N2_PERV_PLL_LOCK_REG                                       = 0x000F0019ull;

static const uint64_t P9N2_PERV_TP_PLL_LOCK_REG                                    = 0x010F0019ull;

static const uint64_t P9N2_PERV_N0_PLL_LOCK_REG                                    = 0x020F0019ull;

static const uint64_t P9N2_PERV_N1_PLL_LOCK_REG                                    = 0x030F0019ull;

static const uint64_t P9N2_PERV_N2_PLL_LOCK_REG                                    = 0x040F0019ull;

static const uint64_t P9N2_PERV_N3_PLL_LOCK_REG                                    = 0x050F0019ull;

static const uint64_t P9N2_PERV_XB_PLL_LOCK_REG                                    = 0x060F0019ull;

static const uint64_t P9N2_PERV_MC01_PLL_LOCK_REG                                  = 0x070F0019ull;

static const uint64_t P9N2_PERV_MC23_PLL_LOCK_REG                                  = 0x080F0019ull;

static const uint64_t P9N2_PERV_OB0_PLL_LOCK_REG                                   = 0x090F0019ull;

static const uint64_t P9N2_PERV_OB3_PLL_LOCK_REG                                   = 0x0C0F0019ull;

static const uint64_t P9N2_PERV_PCI0_PLL_LOCK_REG                                  = 0x0D0F0019ull;

static const uint64_t P9N2_PERV_PCI1_PLL_LOCK_REG                                  = 0x0E0F0019ull;

static const uint64_t P9N2_PERV_PCI2_PLL_LOCK_REG                                  = 0x0F0F0019ull;

static const uint64_t P9N2_PERV_EP00_PLL_LOCK_REG                                  = 0x100F0019ull;

static const uint64_t P9N2_PERV_EP01_PLL_LOCK_REG                                  = 0x110F0019ull;

static const uint64_t P9N2_PERV_EP02_PLL_LOCK_REG                                  = 0x120F0019ull;

static const uint64_t P9N2_PERV_EP03_PLL_LOCK_REG                                  = 0x130F0019ull;

static const uint64_t P9N2_PERV_EP04_PLL_LOCK_REG                                  = 0x140F0019ull;

static const uint64_t P9N2_PERV_EP05_PLL_LOCK_REG                                  = 0x150F0019ull;

static const uint64_t P9N2_PERV_EC00_PLL_LOCK_REG                                  = 0x200F0019ull;

static const uint64_t P9N2_PERV_EC01_PLL_LOCK_REG                                  = 0x210F0019ull;

static const uint64_t P9N2_PERV_EC02_PLL_LOCK_REG                                  = 0x220F0019ull;

static const uint64_t P9N2_PERV_EC03_PLL_LOCK_REG                                  = 0x230F0019ull;

static const uint64_t P9N2_PERV_EC04_PLL_LOCK_REG                                  = 0x240F0019ull;

static const uint64_t P9N2_PERV_EC05_PLL_LOCK_REG                                  = 0x250F0019ull;

static const uint64_t P9N2_PERV_EC06_PLL_LOCK_REG                                  = 0x260F0019ull;

static const uint64_t P9N2_PERV_EC07_PLL_LOCK_REG                                  = 0x270F0019ull;

static const uint64_t P9N2_PERV_EC08_PLL_LOCK_REG                                  = 0x280F0019ull;

static const uint64_t P9N2_PERV_EC09_PLL_LOCK_REG                                  = 0x290F0019ull;

static const uint64_t P9N2_PERV_EC10_PLL_LOCK_REG                                  = 0x2A0F0019ull;

static const uint64_t P9N2_PERV_EC11_PLL_LOCK_REG                                  = 0x2B0F0019ull;

static const uint64_t P9N2_PERV_EC12_PLL_LOCK_REG                                  = 0x2C0F0019ull;

static const uint64_t P9N2_PERV_EC13_PLL_LOCK_REG                                  = 0x2D0F0019ull;

static const uint64_t P9N2_PERV_EC14_PLL_LOCK_REG                                  = 0x2E0F0019ull;

static const uint64_t P9N2_PERV_EC15_PLL_LOCK_REG                                  = 0x2F0F0019ull;

static const uint64_t P9N2_PERV_EC16_PLL_LOCK_REG                                  = 0x300F0019ull;

static const uint64_t P9N2_PERV_EC17_PLL_LOCK_REG                                  = 0x310F0019ull;

static const uint64_t P9N2_PERV_EC18_PLL_LOCK_REG                                  = 0x320F0019ull;

static const uint64_t P9N2_PERV_EC19_PLL_LOCK_REG                                  = 0x330F0019ull;

static const uint64_t P9N2_PERV_EC20_PLL_LOCK_REG                                  = 0x340F0019ull;

static const uint64_t P9N2_PERV_EC21_PLL_LOCK_REG                                  = 0x350F0019ull;

static const uint64_t P9N2_PERV_EC22_PLL_LOCK_REG                                  = 0x360F0019ull;

static const uint64_t P9N2_PERV_EC23_PLL_LOCK_REG                                  = 0x370F0019ull;


static const uint64_t P9N2_PERV_EP00_PPM_CGCR                                      = 0x100F0164ull;

static const uint64_t P9N2_PERV_EP01_PPM_CGCR                                      = 0x110F0164ull;

static const uint64_t P9N2_PERV_EP02_PPM_CGCR                                      = 0x120F0164ull;

static const uint64_t P9N2_PERV_EP03_PPM_CGCR                                      = 0x130F0164ull;

static const uint64_t P9N2_PERV_EP04_PPM_CGCR                                      = 0x140F0164ull;

static const uint64_t P9N2_PERV_EP05_PPM_CGCR                                      = 0x150F0164ull;

static const uint64_t P9N2_PERV_EC00_PPM_CGCR                                      = 0x200F0164ull;

static const uint64_t P9N2_PERV_EC01_PPM_CGCR                                      = 0x210F0164ull;

static const uint64_t P9N2_PERV_EC02_PPM_CGCR                                      = 0x220F0164ull;

static const uint64_t P9N2_PERV_EC03_PPM_CGCR                                      = 0x230F0164ull;

static const uint64_t P9N2_PERV_EC04_PPM_CGCR                                      = 0x240F0164ull;

static const uint64_t P9N2_PERV_EC05_PPM_CGCR                                      = 0x250F0164ull;

static const uint64_t P9N2_PERV_EC06_PPM_CGCR                                      = 0x260F0164ull;

static const uint64_t P9N2_PERV_EC07_PPM_CGCR                                      = 0x270F0164ull;

static const uint64_t P9N2_PERV_EC08_PPM_CGCR                                      = 0x280F0164ull;

static const uint64_t P9N2_PERV_EC09_PPM_CGCR                                      = 0x290F0164ull;

static const uint64_t P9N2_PERV_EC10_PPM_CGCR                                      = 0x2A0F0164ull;

static const uint64_t P9N2_PERV_EC11_PPM_CGCR                                      = 0x2B0F0164ull;

static const uint64_t P9N2_PERV_EC12_PPM_CGCR                                      = 0x2C0F0164ull;

static const uint64_t P9N2_PERV_EC13_PPM_CGCR                                      = 0x2D0F0164ull;

static const uint64_t P9N2_PERV_EC14_PPM_CGCR                                      = 0x2E0F0164ull;

static const uint64_t P9N2_PERV_EC15_PPM_CGCR                                      = 0x2F0F0164ull;

static const uint64_t P9N2_PERV_EC16_PPM_CGCR                                      = 0x300F0164ull;

static const uint64_t P9N2_PERV_EC17_PPM_CGCR                                      = 0x310F0164ull;

static const uint64_t P9N2_PERV_EC18_PPM_CGCR                                      = 0x320F0164ull;

static const uint64_t P9N2_PERV_EC19_PPM_CGCR                                      = 0x330F0164ull;

static const uint64_t P9N2_PERV_EC20_PPM_CGCR                                      = 0x340F0164ull;

static const uint64_t P9N2_PERV_EC21_PPM_CGCR                                      = 0x350F0164ull;

static const uint64_t P9N2_PERV_EC22_PPM_CGCR                                      = 0x360F0164ull;

static const uint64_t P9N2_PERV_EC23_PPM_CGCR                                      = 0x370F0164ull;


static const uint64_t P9N2_PERV_EP00_PPM_GPMMR_SCOM                                = 0x100F0100ull;

static const uint64_t P9N2_PERV_EP00_PPM_GPMMR_SCOM1                               = 0x100F0101ull;

static const uint64_t P9N2_PERV_EP00_PPM_GPMMR_SCOM2                               = 0x100F0102ull;

static const uint64_t P9N2_PERV_EP01_PPM_GPMMR_SCOM                                = 0x110F0100ull;

static const uint64_t P9N2_PERV_EP01_PPM_GPMMR_SCOM1                               = 0x110F0101ull;

static const uint64_t P9N2_PERV_EP01_PPM_GPMMR_SCOM2                               = 0x110F0102ull;

static const uint64_t P9N2_PERV_EP02_PPM_GPMMR_SCOM                                = 0x120F0100ull;

static const uint64_t P9N2_PERV_EP02_PPM_GPMMR_SCOM1                               = 0x120F0101ull;

static const uint64_t P9N2_PERV_EP02_PPM_GPMMR_SCOM2                               = 0x120F0102ull;

static const uint64_t P9N2_PERV_EP03_PPM_GPMMR_SCOM                                = 0x130F0100ull;

static const uint64_t P9N2_PERV_EP03_PPM_GPMMR_SCOM1                               = 0x130F0101ull;

static const uint64_t P9N2_PERV_EP03_PPM_GPMMR_SCOM2                               = 0x130F0102ull;

static const uint64_t P9N2_PERV_EP04_PPM_GPMMR_SCOM                                = 0x140F0100ull;

static const uint64_t P9N2_PERV_EP04_PPM_GPMMR_SCOM1                               = 0x140F0101ull;

static const uint64_t P9N2_PERV_EP04_PPM_GPMMR_SCOM2                               = 0x140F0102ull;

static const uint64_t P9N2_PERV_EP05_PPM_GPMMR_SCOM                                = 0x150F0100ull;

static const uint64_t P9N2_PERV_EP05_PPM_GPMMR_SCOM1                               = 0x150F0101ull;

static const uint64_t P9N2_PERV_EP05_PPM_GPMMR_SCOM2                               = 0x150F0102ull;

static const uint64_t P9N2_PERV_EC00_PPM_GPMMR_SCOM                                = 0x200F0100ull;

static const uint64_t P9N2_PERV_EC00_PPM_GPMMR_SCOM1                               = 0x200F0101ull;

static const uint64_t P9N2_PERV_EC00_PPM_GPMMR_SCOM2                               = 0x200F0102ull;

static const uint64_t P9N2_PERV_EC01_PPM_GPMMR_SCOM                                = 0x210F0100ull;

static const uint64_t P9N2_PERV_EC01_PPM_GPMMR_SCOM1                               = 0x210F0101ull;

static const uint64_t P9N2_PERV_EC01_PPM_GPMMR_SCOM2                               = 0x210F0102ull;

static const uint64_t P9N2_PERV_EC02_PPM_GPMMR_SCOM                                = 0x220F0100ull;

static const uint64_t P9N2_PERV_EC02_PPM_GPMMR_SCOM1                               = 0x220F0101ull;

static const uint64_t P9N2_PERV_EC02_PPM_GPMMR_SCOM2                               = 0x220F0102ull;

static const uint64_t P9N2_PERV_EC03_PPM_GPMMR_SCOM                                = 0x230F0100ull;

static const uint64_t P9N2_PERV_EC03_PPM_GPMMR_SCOM1                               = 0x230F0101ull;

static const uint64_t P9N2_PERV_EC03_PPM_GPMMR_SCOM2                               = 0x230F0102ull;

static const uint64_t P9N2_PERV_EC04_PPM_GPMMR_SCOM                                = 0x240F0100ull;

static const uint64_t P9N2_PERV_EC04_PPM_GPMMR_SCOM1                               = 0x240F0101ull;

static const uint64_t P9N2_PERV_EC04_PPM_GPMMR_SCOM2                               = 0x240F0102ull;

static const uint64_t P9N2_PERV_EC05_PPM_GPMMR_SCOM                                = 0x250F0100ull;

static const uint64_t P9N2_PERV_EC05_PPM_GPMMR_SCOM1                               = 0x250F0101ull;

static const uint64_t P9N2_PERV_EC05_PPM_GPMMR_SCOM2                               = 0x250F0102ull;

static const uint64_t P9N2_PERV_EC06_PPM_GPMMR_SCOM                                = 0x260F0100ull;

static const uint64_t P9N2_PERV_EC06_PPM_GPMMR_SCOM1                               = 0x260F0101ull;

static const uint64_t P9N2_PERV_EC06_PPM_GPMMR_SCOM2                               = 0x260F0102ull;

static const uint64_t P9N2_PERV_EC07_PPM_GPMMR_SCOM                                = 0x270F0100ull;

static const uint64_t P9N2_PERV_EC07_PPM_GPMMR_SCOM1                               = 0x270F0101ull;

static const uint64_t P9N2_PERV_EC07_PPM_GPMMR_SCOM2                               = 0x270F0102ull;

static const uint64_t P9N2_PERV_EC08_PPM_GPMMR_SCOM                                = 0x280F0100ull;

static const uint64_t P9N2_PERV_EC08_PPM_GPMMR_SCOM1                               = 0x280F0101ull;

static const uint64_t P9N2_PERV_EC08_PPM_GPMMR_SCOM2                               = 0x280F0102ull;

static const uint64_t P9N2_PERV_EC09_PPM_GPMMR_SCOM                                = 0x290F0100ull;

static const uint64_t P9N2_PERV_EC09_PPM_GPMMR_SCOM1                               = 0x290F0101ull;

static const uint64_t P9N2_PERV_EC09_PPM_GPMMR_SCOM2                               = 0x290F0102ull;

static const uint64_t P9N2_PERV_EC10_PPM_GPMMR_SCOM                                = 0x2A0F0100ull;

static const uint64_t P9N2_PERV_EC10_PPM_GPMMR_SCOM1                               = 0x2A0F0101ull;

static const uint64_t P9N2_PERV_EC10_PPM_GPMMR_SCOM2                               = 0x2A0F0102ull;

static const uint64_t P9N2_PERV_EC11_PPM_GPMMR_SCOM                                = 0x2B0F0100ull;

static const uint64_t P9N2_PERV_EC11_PPM_GPMMR_SCOM1                               = 0x2B0F0101ull;

static const uint64_t P9N2_PERV_EC11_PPM_GPMMR_SCOM2                               = 0x2B0F0102ull;

static const uint64_t P9N2_PERV_EC12_PPM_GPMMR_SCOM                                = 0x2C0F0100ull;

static const uint64_t P9N2_PERV_EC12_PPM_GPMMR_SCOM1                               = 0x2C0F0101ull;

static const uint64_t P9N2_PERV_EC12_PPM_GPMMR_SCOM2                               = 0x2C0F0102ull;

static const uint64_t P9N2_PERV_EC13_PPM_GPMMR_SCOM                                = 0x2D0F0100ull;

static const uint64_t P9N2_PERV_EC13_PPM_GPMMR_SCOM1                               = 0x2D0F0101ull;

static const uint64_t P9N2_PERV_EC13_PPM_GPMMR_SCOM2                               = 0x2D0F0102ull;

static const uint64_t P9N2_PERV_EC14_PPM_GPMMR_SCOM                                = 0x2E0F0100ull;

static const uint64_t P9N2_PERV_EC14_PPM_GPMMR_SCOM1                               = 0x2E0F0101ull;

static const uint64_t P9N2_PERV_EC14_PPM_GPMMR_SCOM2                               = 0x2E0F0102ull;

static const uint64_t P9N2_PERV_EC15_PPM_GPMMR_SCOM                                = 0x2F0F0100ull;

static const uint64_t P9N2_PERV_EC15_PPM_GPMMR_SCOM1                               = 0x2F0F0101ull;

static const uint64_t P9N2_PERV_EC15_PPM_GPMMR_SCOM2                               = 0x2F0F0102ull;

static const uint64_t P9N2_PERV_EC16_PPM_GPMMR_SCOM                                = 0x300F0100ull;

static const uint64_t P9N2_PERV_EC16_PPM_GPMMR_SCOM1                               = 0x300F0101ull;

static const uint64_t P9N2_PERV_EC16_PPM_GPMMR_SCOM2                               = 0x300F0102ull;

static const uint64_t P9N2_PERV_EC17_PPM_GPMMR_SCOM                                = 0x310F0100ull;

static const uint64_t P9N2_PERV_EC17_PPM_GPMMR_SCOM1                               = 0x310F0101ull;

static const uint64_t P9N2_PERV_EC17_PPM_GPMMR_SCOM2                               = 0x310F0102ull;

static const uint64_t P9N2_PERV_EC18_PPM_GPMMR_SCOM                                = 0x320F0100ull;

static const uint64_t P9N2_PERV_EC18_PPM_GPMMR_SCOM1                               = 0x320F0101ull;

static const uint64_t P9N2_PERV_EC18_PPM_GPMMR_SCOM2                               = 0x320F0102ull;

static const uint64_t P9N2_PERV_EC19_PPM_GPMMR_SCOM                                = 0x330F0100ull;

static const uint64_t P9N2_PERV_EC19_PPM_GPMMR_SCOM1                               = 0x330F0101ull;

static const uint64_t P9N2_PERV_EC19_PPM_GPMMR_SCOM2                               = 0x330F0102ull;

static const uint64_t P9N2_PERV_EC20_PPM_GPMMR_SCOM                                = 0x340F0100ull;

static const uint64_t P9N2_PERV_EC20_PPM_GPMMR_SCOM1                               = 0x340F0101ull;

static const uint64_t P9N2_PERV_EC20_PPM_GPMMR_SCOM2                               = 0x340F0102ull;

static const uint64_t P9N2_PERV_EC21_PPM_GPMMR_SCOM                                = 0x350F0100ull;

static const uint64_t P9N2_PERV_EC21_PPM_GPMMR_SCOM1                               = 0x350F0101ull;

static const uint64_t P9N2_PERV_EC21_PPM_GPMMR_SCOM2                               = 0x350F0102ull;

static const uint64_t P9N2_PERV_EC22_PPM_GPMMR_SCOM                                = 0x360F0100ull;

static const uint64_t P9N2_PERV_EC22_PPM_GPMMR_SCOM1                               = 0x360F0101ull;

static const uint64_t P9N2_PERV_EC22_PPM_GPMMR_SCOM2                               = 0x360F0102ull;

static const uint64_t P9N2_PERV_EC23_PPM_GPMMR_SCOM                                = 0x370F0100ull;

static const uint64_t P9N2_PERV_EC23_PPM_GPMMR_SCOM1                               = 0x370F0101ull;

static const uint64_t P9N2_PERV_EC23_PPM_GPMMR_SCOM2                               = 0x370F0102ull;


static const uint64_t P9N2_PERV_EP00_PPM_IVRMAVR                                   = 0x100F01B5ull;

static const uint64_t P9N2_PERV_EP01_PPM_IVRMAVR                                   = 0x110F01B5ull;

static const uint64_t P9N2_PERV_EP02_PPM_IVRMAVR                                   = 0x120F01B5ull;

static const uint64_t P9N2_PERV_EP03_PPM_IVRMAVR                                   = 0x130F01B5ull;

static const uint64_t P9N2_PERV_EP04_PPM_IVRMAVR                                   = 0x140F01B5ull;

static const uint64_t P9N2_PERV_EP05_PPM_IVRMAVR                                   = 0x150F01B5ull;

static const uint64_t P9N2_PERV_EC00_PPM_IVRMAVR                                   = 0x200F01B5ull;

static const uint64_t P9N2_PERV_EC01_PPM_IVRMAVR                                   = 0x210F01B5ull;

static const uint64_t P9N2_PERV_EC02_PPM_IVRMAVR                                   = 0x220F01B5ull;

static const uint64_t P9N2_PERV_EC03_PPM_IVRMAVR                                   = 0x230F01B5ull;

static const uint64_t P9N2_PERV_EC04_PPM_IVRMAVR                                   = 0x240F01B5ull;

static const uint64_t P9N2_PERV_EC05_PPM_IVRMAVR                                   = 0x250F01B5ull;

static const uint64_t P9N2_PERV_EC06_PPM_IVRMAVR                                   = 0x260F01B5ull;

static const uint64_t P9N2_PERV_EC07_PPM_IVRMAVR                                   = 0x270F01B5ull;

static const uint64_t P9N2_PERV_EC08_PPM_IVRMAVR                                   = 0x280F01B5ull;

static const uint64_t P9N2_PERV_EC09_PPM_IVRMAVR                                   = 0x290F01B5ull;

static const uint64_t P9N2_PERV_EC10_PPM_IVRMAVR                                   = 0x2A0F01B5ull;

static const uint64_t P9N2_PERV_EC11_PPM_IVRMAVR                                   = 0x2B0F01B5ull;

static const uint64_t P9N2_PERV_EC12_PPM_IVRMAVR                                   = 0x2C0F01B5ull;

static const uint64_t P9N2_PERV_EC13_PPM_IVRMAVR                                   = 0x2D0F01B5ull;

static const uint64_t P9N2_PERV_EC14_PPM_IVRMAVR                                   = 0x2E0F01B5ull;

static const uint64_t P9N2_PERV_EC15_PPM_IVRMAVR                                   = 0x2F0F01B5ull;

static const uint64_t P9N2_PERV_EC16_PPM_IVRMAVR                                   = 0x300F01B5ull;

static const uint64_t P9N2_PERV_EC17_PPM_IVRMAVR                                   = 0x310F01B5ull;

static const uint64_t P9N2_PERV_EC18_PPM_IVRMAVR                                   = 0x320F01B5ull;

static const uint64_t P9N2_PERV_EC19_PPM_IVRMAVR                                   = 0x330F01B5ull;

static const uint64_t P9N2_PERV_EC20_PPM_IVRMAVR                                   = 0x340F01B5ull;

static const uint64_t P9N2_PERV_EC21_PPM_IVRMAVR                                   = 0x350F01B5ull;

static const uint64_t P9N2_PERV_EC22_PPM_IVRMAVR                                   = 0x360F01B5ull;

static const uint64_t P9N2_PERV_EC23_PPM_IVRMAVR                                   = 0x370F01B5ull;


static const uint64_t P9N2_PERV_EP00_PPM_IVRMCR                                    = 0x100F01B0ull;

static const uint64_t P9N2_PERV_EP00_PPM_IVRMCR_CLEAR                              = 0x100F01B1ull;

static const uint64_t P9N2_PERV_EP00_PPM_IVRMCR_OR                                 = 0x100F01B2ull;

static const uint64_t P9N2_PERV_EP01_PPM_IVRMCR                                    = 0x110F01B0ull;

static const uint64_t P9N2_PERV_EP01_PPM_IVRMCR_CLEAR                              = 0x110F01B1ull;

static const uint64_t P9N2_PERV_EP01_PPM_IVRMCR_OR                                 = 0x110F01B2ull;

static const uint64_t P9N2_PERV_EP02_PPM_IVRMCR                                    = 0x120F01B0ull;

static const uint64_t P9N2_PERV_EP02_PPM_IVRMCR_CLEAR                              = 0x120F01B1ull;

static const uint64_t P9N2_PERV_EP02_PPM_IVRMCR_OR                                 = 0x120F01B2ull;

static const uint64_t P9N2_PERV_EP03_PPM_IVRMCR                                    = 0x130F01B0ull;

static const uint64_t P9N2_PERV_EP03_PPM_IVRMCR_CLEAR                              = 0x130F01B1ull;

static const uint64_t P9N2_PERV_EP03_PPM_IVRMCR_OR                                 = 0x130F01B2ull;

static const uint64_t P9N2_PERV_EP04_PPM_IVRMCR                                    = 0x140F01B0ull;

static const uint64_t P9N2_PERV_EP04_PPM_IVRMCR_CLEAR                              = 0x140F01B1ull;

static const uint64_t P9N2_PERV_EP04_PPM_IVRMCR_OR                                 = 0x140F01B2ull;

static const uint64_t P9N2_PERV_EP05_PPM_IVRMCR                                    = 0x150F01B0ull;

static const uint64_t P9N2_PERV_EP05_PPM_IVRMCR_CLEAR                              = 0x150F01B1ull;

static const uint64_t P9N2_PERV_EP05_PPM_IVRMCR_OR                                 = 0x150F01B2ull;

static const uint64_t P9N2_PERV_EC00_PPM_IVRMCR                                    = 0x200F01B0ull;

static const uint64_t P9N2_PERV_EC00_PPM_IVRMCR_CLEAR                              = 0x200F01B1ull;

static const uint64_t P9N2_PERV_EC00_PPM_IVRMCR_OR                                 = 0x200F01B2ull;

static const uint64_t P9N2_PERV_EC01_PPM_IVRMCR                                    = 0x210F01B0ull;

static const uint64_t P9N2_PERV_EC01_PPM_IVRMCR_CLEAR                              = 0x210F01B1ull;

static const uint64_t P9N2_PERV_EC01_PPM_IVRMCR_OR                                 = 0x210F01B2ull;

static const uint64_t P9N2_PERV_EC02_PPM_IVRMCR                                    = 0x220F01B0ull;

static const uint64_t P9N2_PERV_EC02_PPM_IVRMCR_CLEAR                              = 0x220F01B1ull;

static const uint64_t P9N2_PERV_EC02_PPM_IVRMCR_OR                                 = 0x220F01B2ull;

static const uint64_t P9N2_PERV_EC03_PPM_IVRMCR                                    = 0x230F01B0ull;

static const uint64_t P9N2_PERV_EC03_PPM_IVRMCR_CLEAR                              = 0x230F01B1ull;

static const uint64_t P9N2_PERV_EC03_PPM_IVRMCR_OR                                 = 0x230F01B2ull;

static const uint64_t P9N2_PERV_EC04_PPM_IVRMCR                                    = 0x240F01B0ull;

static const uint64_t P9N2_PERV_EC04_PPM_IVRMCR_CLEAR                              = 0x240F01B1ull;

static const uint64_t P9N2_PERV_EC04_PPM_IVRMCR_OR                                 = 0x240F01B2ull;

static const uint64_t P9N2_PERV_EC05_PPM_IVRMCR                                    = 0x250F01B0ull;

static const uint64_t P9N2_PERV_EC05_PPM_IVRMCR_CLEAR                              = 0x250F01B1ull;

static const uint64_t P9N2_PERV_EC05_PPM_IVRMCR_OR                                 = 0x250F01B2ull;

static const uint64_t P9N2_PERV_EC06_PPM_IVRMCR                                    = 0x260F01B0ull;

static const uint64_t P9N2_PERV_EC06_PPM_IVRMCR_CLEAR                              = 0x260F01B1ull;

static const uint64_t P9N2_PERV_EC06_PPM_IVRMCR_OR                                 = 0x260F01B2ull;

static const uint64_t P9N2_PERV_EC07_PPM_IVRMCR                                    = 0x270F01B0ull;

static const uint64_t P9N2_PERV_EC07_PPM_IVRMCR_CLEAR                              = 0x270F01B1ull;

static const uint64_t P9N2_PERV_EC07_PPM_IVRMCR_OR                                 = 0x270F01B2ull;

static const uint64_t P9N2_PERV_EC08_PPM_IVRMCR                                    = 0x280F01B0ull;

static const uint64_t P9N2_PERV_EC08_PPM_IVRMCR_CLEAR                              = 0x280F01B1ull;

static const uint64_t P9N2_PERV_EC08_PPM_IVRMCR_OR                                 = 0x280F01B2ull;

static const uint64_t P9N2_PERV_EC09_PPM_IVRMCR                                    = 0x290F01B0ull;

static const uint64_t P9N2_PERV_EC09_PPM_IVRMCR_CLEAR                              = 0x290F01B1ull;

static const uint64_t P9N2_PERV_EC09_PPM_IVRMCR_OR                                 = 0x290F01B2ull;

static const uint64_t P9N2_PERV_EC10_PPM_IVRMCR                                    = 0x2A0F01B0ull;

static const uint64_t P9N2_PERV_EC10_PPM_IVRMCR_CLEAR                              = 0x2A0F01B1ull;

static const uint64_t P9N2_PERV_EC10_PPM_IVRMCR_OR                                 = 0x2A0F01B2ull;

static const uint64_t P9N2_PERV_EC11_PPM_IVRMCR                                    = 0x2B0F01B0ull;

static const uint64_t P9N2_PERV_EC11_PPM_IVRMCR_CLEAR                              = 0x2B0F01B1ull;

static const uint64_t P9N2_PERV_EC11_PPM_IVRMCR_OR                                 = 0x2B0F01B2ull;

static const uint64_t P9N2_PERV_EC12_PPM_IVRMCR                                    = 0x2C0F01B0ull;

static const uint64_t P9N2_PERV_EC12_PPM_IVRMCR_CLEAR                              = 0x2C0F01B1ull;

static const uint64_t P9N2_PERV_EC12_PPM_IVRMCR_OR                                 = 0x2C0F01B2ull;

static const uint64_t P9N2_PERV_EC13_PPM_IVRMCR                                    = 0x2D0F01B0ull;

static const uint64_t P9N2_PERV_EC13_PPM_IVRMCR_CLEAR                              = 0x2D0F01B1ull;

static const uint64_t P9N2_PERV_EC13_PPM_IVRMCR_OR                                 = 0x2D0F01B2ull;

static const uint64_t P9N2_PERV_EC14_PPM_IVRMCR                                    = 0x2E0F01B0ull;

static const uint64_t P9N2_PERV_EC14_PPM_IVRMCR_CLEAR                              = 0x2E0F01B1ull;

static const uint64_t P9N2_PERV_EC14_PPM_IVRMCR_OR                                 = 0x2E0F01B2ull;

static const uint64_t P9N2_PERV_EC15_PPM_IVRMCR                                    = 0x2F0F01B0ull;

static const uint64_t P9N2_PERV_EC15_PPM_IVRMCR_CLEAR                              = 0x2F0F01B1ull;

static const uint64_t P9N2_PERV_EC15_PPM_IVRMCR_OR                                 = 0x2F0F01B2ull;

static const uint64_t P9N2_PERV_EC16_PPM_IVRMCR                                    = 0x300F01B0ull;

static const uint64_t P9N2_PERV_EC16_PPM_IVRMCR_CLEAR                              = 0x300F01B1ull;

static const uint64_t P9N2_PERV_EC16_PPM_IVRMCR_OR                                 = 0x300F01B2ull;

static const uint64_t P9N2_PERV_EC17_PPM_IVRMCR                                    = 0x310F01B0ull;

static const uint64_t P9N2_PERV_EC17_PPM_IVRMCR_CLEAR                              = 0x310F01B1ull;

static const uint64_t P9N2_PERV_EC17_PPM_IVRMCR_OR                                 = 0x310F01B2ull;

static const uint64_t P9N2_PERV_EC18_PPM_IVRMCR                                    = 0x320F01B0ull;

static const uint64_t P9N2_PERV_EC18_PPM_IVRMCR_CLEAR                              = 0x320F01B1ull;

static const uint64_t P9N2_PERV_EC18_PPM_IVRMCR_OR                                 = 0x320F01B2ull;

static const uint64_t P9N2_PERV_EC19_PPM_IVRMCR                                    = 0x330F01B0ull;

static const uint64_t P9N2_PERV_EC19_PPM_IVRMCR_CLEAR                              = 0x330F01B1ull;

static const uint64_t P9N2_PERV_EC19_PPM_IVRMCR_OR                                 = 0x330F01B2ull;

static const uint64_t P9N2_PERV_EC20_PPM_IVRMCR                                    = 0x340F01B0ull;

static const uint64_t P9N2_PERV_EC20_PPM_IVRMCR_CLEAR                              = 0x340F01B1ull;

static const uint64_t P9N2_PERV_EC20_PPM_IVRMCR_OR                                 = 0x340F01B2ull;

static const uint64_t P9N2_PERV_EC21_PPM_IVRMCR                                    = 0x350F01B0ull;

static const uint64_t P9N2_PERV_EC21_PPM_IVRMCR_CLEAR                              = 0x350F01B1ull;

static const uint64_t P9N2_PERV_EC21_PPM_IVRMCR_OR                                 = 0x350F01B2ull;

static const uint64_t P9N2_PERV_EC22_PPM_IVRMCR                                    = 0x360F01B0ull;

static const uint64_t P9N2_PERV_EC22_PPM_IVRMCR_CLEAR                              = 0x360F01B1ull;

static const uint64_t P9N2_PERV_EC22_PPM_IVRMCR_OR                                 = 0x360F01B2ull;

static const uint64_t P9N2_PERV_EC23_PPM_IVRMCR                                    = 0x370F01B0ull;

static const uint64_t P9N2_PERV_EC23_PPM_IVRMCR_CLEAR                              = 0x370F01B1ull;

static const uint64_t P9N2_PERV_EC23_PPM_IVRMCR_OR                                 = 0x370F01B2ull;


static const uint64_t P9N2_PERV_EP00_PPM_IVRMDVR                                   = 0x100F01B4ull;

static const uint64_t P9N2_PERV_EP01_PPM_IVRMDVR                                   = 0x110F01B4ull;

static const uint64_t P9N2_PERV_EP02_PPM_IVRMDVR                                   = 0x120F01B4ull;

static const uint64_t P9N2_PERV_EP03_PPM_IVRMDVR                                   = 0x130F01B4ull;

static const uint64_t P9N2_PERV_EP04_PPM_IVRMDVR                                   = 0x140F01B4ull;

static const uint64_t P9N2_PERV_EP05_PPM_IVRMDVR                                   = 0x150F01B4ull;

static const uint64_t P9N2_PERV_EC00_PPM_IVRMDVR                                   = 0x200F01B4ull;

static const uint64_t P9N2_PERV_EC01_PPM_IVRMDVR                                   = 0x210F01B4ull;

static const uint64_t P9N2_PERV_EC02_PPM_IVRMDVR                                   = 0x220F01B4ull;

static const uint64_t P9N2_PERV_EC03_PPM_IVRMDVR                                   = 0x230F01B4ull;

static const uint64_t P9N2_PERV_EC04_PPM_IVRMDVR                                   = 0x240F01B4ull;

static const uint64_t P9N2_PERV_EC05_PPM_IVRMDVR                                   = 0x250F01B4ull;

static const uint64_t P9N2_PERV_EC06_PPM_IVRMDVR                                   = 0x260F01B4ull;

static const uint64_t P9N2_PERV_EC07_PPM_IVRMDVR                                   = 0x270F01B4ull;

static const uint64_t P9N2_PERV_EC08_PPM_IVRMDVR                                   = 0x280F01B4ull;

static const uint64_t P9N2_PERV_EC09_PPM_IVRMDVR                                   = 0x290F01B4ull;

static const uint64_t P9N2_PERV_EC10_PPM_IVRMDVR                                   = 0x2A0F01B4ull;

static const uint64_t P9N2_PERV_EC11_PPM_IVRMDVR                                   = 0x2B0F01B4ull;

static const uint64_t P9N2_PERV_EC12_PPM_IVRMDVR                                   = 0x2C0F01B4ull;

static const uint64_t P9N2_PERV_EC13_PPM_IVRMDVR                                   = 0x2D0F01B4ull;

static const uint64_t P9N2_PERV_EC14_PPM_IVRMDVR                                   = 0x2E0F01B4ull;

static const uint64_t P9N2_PERV_EC15_PPM_IVRMDVR                                   = 0x2F0F01B4ull;

static const uint64_t P9N2_PERV_EC16_PPM_IVRMDVR                                   = 0x300F01B4ull;

static const uint64_t P9N2_PERV_EC17_PPM_IVRMDVR                                   = 0x310F01B4ull;

static const uint64_t P9N2_PERV_EC18_PPM_IVRMDVR                                   = 0x320F01B4ull;

static const uint64_t P9N2_PERV_EC19_PPM_IVRMDVR                                   = 0x330F01B4ull;

static const uint64_t P9N2_PERV_EC20_PPM_IVRMDVR                                   = 0x340F01B4ull;

static const uint64_t P9N2_PERV_EC21_PPM_IVRMDVR                                   = 0x350F01B4ull;

static const uint64_t P9N2_PERV_EC22_PPM_IVRMDVR                                   = 0x360F01B4ull;

static const uint64_t P9N2_PERV_EC23_PPM_IVRMDVR                                   = 0x370F01B4ull;


static const uint64_t P9N2_PERV_EP00_PPM_IVRMST                                    = 0x100F01B3ull;

static const uint64_t P9N2_PERV_EP01_PPM_IVRMST                                    = 0x110F01B3ull;

static const uint64_t P9N2_PERV_EP02_PPM_IVRMST                                    = 0x120F01B3ull;

static const uint64_t P9N2_PERV_EP03_PPM_IVRMST                                    = 0x130F01B3ull;

static const uint64_t P9N2_PERV_EP04_PPM_IVRMST                                    = 0x140F01B3ull;

static const uint64_t P9N2_PERV_EP05_PPM_IVRMST                                    = 0x150F01B3ull;

static const uint64_t P9N2_PERV_EC00_PPM_IVRMST                                    = 0x200F01B3ull;

static const uint64_t P9N2_PERV_EC01_PPM_IVRMST                                    = 0x210F01B3ull;

static const uint64_t P9N2_PERV_EC02_PPM_IVRMST                                    = 0x220F01B3ull;

static const uint64_t P9N2_PERV_EC03_PPM_IVRMST                                    = 0x230F01B3ull;

static const uint64_t P9N2_PERV_EC04_PPM_IVRMST                                    = 0x240F01B3ull;

static const uint64_t P9N2_PERV_EC05_PPM_IVRMST                                    = 0x250F01B3ull;

static const uint64_t P9N2_PERV_EC06_PPM_IVRMST                                    = 0x260F01B3ull;

static const uint64_t P9N2_PERV_EC07_PPM_IVRMST                                    = 0x270F01B3ull;

static const uint64_t P9N2_PERV_EC08_PPM_IVRMST                                    = 0x280F01B3ull;

static const uint64_t P9N2_PERV_EC09_PPM_IVRMST                                    = 0x290F01B3ull;

static const uint64_t P9N2_PERV_EC10_PPM_IVRMST                                    = 0x2A0F01B3ull;

static const uint64_t P9N2_PERV_EC11_PPM_IVRMST                                    = 0x2B0F01B3ull;

static const uint64_t P9N2_PERV_EC12_PPM_IVRMST                                    = 0x2C0F01B3ull;

static const uint64_t P9N2_PERV_EC13_PPM_IVRMST                                    = 0x2D0F01B3ull;

static const uint64_t P9N2_PERV_EC14_PPM_IVRMST                                    = 0x2E0F01B3ull;

static const uint64_t P9N2_PERV_EC15_PPM_IVRMST                                    = 0x2F0F01B3ull;

static const uint64_t P9N2_PERV_EC16_PPM_IVRMST                                    = 0x300F01B3ull;

static const uint64_t P9N2_PERV_EC17_PPM_IVRMST                                    = 0x310F01B3ull;

static const uint64_t P9N2_PERV_EC18_PPM_IVRMST                                    = 0x320F01B3ull;

static const uint64_t P9N2_PERV_EC19_PPM_IVRMST                                    = 0x330F01B3ull;

static const uint64_t P9N2_PERV_EC20_PPM_IVRMST                                    = 0x340F01B3ull;

static const uint64_t P9N2_PERV_EC21_PPM_IVRMST                                    = 0x350F01B3ull;

static const uint64_t P9N2_PERV_EC22_PPM_IVRMST                                    = 0x360F01B3ull;

static const uint64_t P9N2_PERV_EC23_PPM_IVRMST                                    = 0x370F01B3ull;


static const uint64_t P9N2_PERV_EP00_PPM_PFCS_SCOM                                 = 0x100F0118ull;

static const uint64_t P9N2_PERV_EP00_PPM_PFCS_SCOM1                                = 0x100F0119ull;

static const uint64_t P9N2_PERV_EP00_PPM_PFCS_SCOM2                                = 0x100F011Aull;

static const uint64_t P9N2_PERV_EP01_PPM_PFCS_SCOM                                 = 0x110F0118ull;

static const uint64_t P9N2_PERV_EP01_PPM_PFCS_SCOM1                                = 0x110F0119ull;

static const uint64_t P9N2_PERV_EP01_PPM_PFCS_SCOM2                                = 0x110F011Aull;

static const uint64_t P9N2_PERV_EP02_PPM_PFCS_SCOM                                 = 0x120F0118ull;

static const uint64_t P9N2_PERV_EP02_PPM_PFCS_SCOM1                                = 0x120F0119ull;

static const uint64_t P9N2_PERV_EP02_PPM_PFCS_SCOM2                                = 0x120F011Aull;

static const uint64_t P9N2_PERV_EP03_PPM_PFCS_SCOM                                 = 0x130F0118ull;

static const uint64_t P9N2_PERV_EP03_PPM_PFCS_SCOM1                                = 0x130F0119ull;

static const uint64_t P9N2_PERV_EP03_PPM_PFCS_SCOM2                                = 0x130F011Aull;

static const uint64_t P9N2_PERV_EP04_PPM_PFCS_SCOM                                 = 0x140F0118ull;

static const uint64_t P9N2_PERV_EP04_PPM_PFCS_SCOM1                                = 0x140F0119ull;

static const uint64_t P9N2_PERV_EP04_PPM_PFCS_SCOM2                                = 0x140F011Aull;

static const uint64_t P9N2_PERV_EP05_PPM_PFCS_SCOM                                 = 0x150F0118ull;

static const uint64_t P9N2_PERV_EP05_PPM_PFCS_SCOM1                                = 0x150F0119ull;

static const uint64_t P9N2_PERV_EP05_PPM_PFCS_SCOM2                                = 0x150F011Aull;

static const uint64_t P9N2_PERV_EC00_PPM_PFCS_SCOM                                 = 0x200F0118ull;

static const uint64_t P9N2_PERV_EC00_PPM_PFCS_SCOM1                                = 0x200F0119ull;

static const uint64_t P9N2_PERV_EC00_PPM_PFCS_SCOM2                                = 0x200F011Aull;

static const uint64_t P9N2_PERV_EC01_PPM_PFCS_SCOM                                 = 0x210F0118ull;

static const uint64_t P9N2_PERV_EC01_PPM_PFCS_SCOM1                                = 0x210F0119ull;

static const uint64_t P9N2_PERV_EC01_PPM_PFCS_SCOM2                                = 0x210F011Aull;

static const uint64_t P9N2_PERV_EC02_PPM_PFCS_SCOM                                 = 0x220F0118ull;

static const uint64_t P9N2_PERV_EC02_PPM_PFCS_SCOM1                                = 0x220F0119ull;

static const uint64_t P9N2_PERV_EC02_PPM_PFCS_SCOM2                                = 0x220F011Aull;

static const uint64_t P9N2_PERV_EC03_PPM_PFCS_SCOM                                 = 0x230F0118ull;

static const uint64_t P9N2_PERV_EC03_PPM_PFCS_SCOM1                                = 0x230F0119ull;

static const uint64_t P9N2_PERV_EC03_PPM_PFCS_SCOM2                                = 0x230F011Aull;

static const uint64_t P9N2_PERV_EC04_PPM_PFCS_SCOM                                 = 0x240F0118ull;

static const uint64_t P9N2_PERV_EC04_PPM_PFCS_SCOM1                                = 0x240F0119ull;

static const uint64_t P9N2_PERV_EC04_PPM_PFCS_SCOM2                                = 0x240F011Aull;

static const uint64_t P9N2_PERV_EC05_PPM_PFCS_SCOM                                 = 0x250F0118ull;

static const uint64_t P9N2_PERV_EC05_PPM_PFCS_SCOM1                                = 0x250F0119ull;

static const uint64_t P9N2_PERV_EC05_PPM_PFCS_SCOM2                                = 0x250F011Aull;

static const uint64_t P9N2_PERV_EC06_PPM_PFCS_SCOM                                 = 0x260F0118ull;

static const uint64_t P9N2_PERV_EC06_PPM_PFCS_SCOM1                                = 0x260F0119ull;

static const uint64_t P9N2_PERV_EC06_PPM_PFCS_SCOM2                                = 0x260F011Aull;

static const uint64_t P9N2_PERV_EC07_PPM_PFCS_SCOM                                 = 0x270F0118ull;

static const uint64_t P9N2_PERV_EC07_PPM_PFCS_SCOM1                                = 0x270F0119ull;

static const uint64_t P9N2_PERV_EC07_PPM_PFCS_SCOM2                                = 0x270F011Aull;

static const uint64_t P9N2_PERV_EC08_PPM_PFCS_SCOM                                 = 0x280F0118ull;

static const uint64_t P9N2_PERV_EC08_PPM_PFCS_SCOM1                                = 0x280F0119ull;

static const uint64_t P9N2_PERV_EC08_PPM_PFCS_SCOM2                                = 0x280F011Aull;

static const uint64_t P9N2_PERV_EC09_PPM_PFCS_SCOM                                 = 0x290F0118ull;

static const uint64_t P9N2_PERV_EC09_PPM_PFCS_SCOM1                                = 0x290F0119ull;

static const uint64_t P9N2_PERV_EC09_PPM_PFCS_SCOM2                                = 0x290F011Aull;

static const uint64_t P9N2_PERV_EC10_PPM_PFCS_SCOM                                 = 0x2A0F0118ull;

static const uint64_t P9N2_PERV_EC10_PPM_PFCS_SCOM1                                = 0x2A0F0119ull;

static const uint64_t P9N2_PERV_EC10_PPM_PFCS_SCOM2                                = 0x2A0F011Aull;

static const uint64_t P9N2_PERV_EC11_PPM_PFCS_SCOM                                 = 0x2B0F0118ull;

static const uint64_t P9N2_PERV_EC11_PPM_PFCS_SCOM1                                = 0x2B0F0119ull;

static const uint64_t P9N2_PERV_EC11_PPM_PFCS_SCOM2                                = 0x2B0F011Aull;

static const uint64_t P9N2_PERV_EC12_PPM_PFCS_SCOM                                 = 0x2C0F0118ull;

static const uint64_t P9N2_PERV_EC12_PPM_PFCS_SCOM1                                = 0x2C0F0119ull;

static const uint64_t P9N2_PERV_EC12_PPM_PFCS_SCOM2                                = 0x2C0F011Aull;

static const uint64_t P9N2_PERV_EC13_PPM_PFCS_SCOM                                 = 0x2D0F0118ull;

static const uint64_t P9N2_PERV_EC13_PPM_PFCS_SCOM1                                = 0x2D0F0119ull;

static const uint64_t P9N2_PERV_EC13_PPM_PFCS_SCOM2                                = 0x2D0F011Aull;

static const uint64_t P9N2_PERV_EC14_PPM_PFCS_SCOM                                 = 0x2E0F0118ull;

static const uint64_t P9N2_PERV_EC14_PPM_PFCS_SCOM1                                = 0x2E0F0119ull;

static const uint64_t P9N2_PERV_EC14_PPM_PFCS_SCOM2                                = 0x2E0F011Aull;

static const uint64_t P9N2_PERV_EC15_PPM_PFCS_SCOM                                 = 0x2F0F0118ull;

static const uint64_t P9N2_PERV_EC15_PPM_PFCS_SCOM1                                = 0x2F0F0119ull;

static const uint64_t P9N2_PERV_EC15_PPM_PFCS_SCOM2                                = 0x2F0F011Aull;

static const uint64_t P9N2_PERV_EC16_PPM_PFCS_SCOM                                 = 0x300F0118ull;

static const uint64_t P9N2_PERV_EC16_PPM_PFCS_SCOM1                                = 0x300F0119ull;

static const uint64_t P9N2_PERV_EC16_PPM_PFCS_SCOM2                                = 0x300F011Aull;

static const uint64_t P9N2_PERV_EC17_PPM_PFCS_SCOM                                 = 0x310F0118ull;

static const uint64_t P9N2_PERV_EC17_PPM_PFCS_SCOM1                                = 0x310F0119ull;

static const uint64_t P9N2_PERV_EC17_PPM_PFCS_SCOM2                                = 0x310F011Aull;

static const uint64_t P9N2_PERV_EC18_PPM_PFCS_SCOM                                 = 0x320F0118ull;

static const uint64_t P9N2_PERV_EC18_PPM_PFCS_SCOM1                                = 0x320F0119ull;

static const uint64_t P9N2_PERV_EC18_PPM_PFCS_SCOM2                                = 0x320F011Aull;

static const uint64_t P9N2_PERV_EC19_PPM_PFCS_SCOM                                 = 0x330F0118ull;

static const uint64_t P9N2_PERV_EC19_PPM_PFCS_SCOM1                                = 0x330F0119ull;

static const uint64_t P9N2_PERV_EC19_PPM_PFCS_SCOM2                                = 0x330F011Aull;

static const uint64_t P9N2_PERV_EC20_PPM_PFCS_SCOM                                 = 0x340F0118ull;

static const uint64_t P9N2_PERV_EC20_PPM_PFCS_SCOM1                                = 0x340F0119ull;

static const uint64_t P9N2_PERV_EC20_PPM_PFCS_SCOM2                                = 0x340F011Aull;

static const uint64_t P9N2_PERV_EC21_PPM_PFCS_SCOM                                 = 0x350F0118ull;

static const uint64_t P9N2_PERV_EC21_PPM_PFCS_SCOM1                                = 0x350F0119ull;

static const uint64_t P9N2_PERV_EC21_PPM_PFCS_SCOM2                                = 0x350F011Aull;

static const uint64_t P9N2_PERV_EC22_PPM_PFCS_SCOM                                 = 0x360F0118ull;

static const uint64_t P9N2_PERV_EC22_PPM_PFCS_SCOM1                                = 0x360F0119ull;

static const uint64_t P9N2_PERV_EC22_PPM_PFCS_SCOM2                                = 0x360F011Aull;

static const uint64_t P9N2_PERV_EC23_PPM_PFCS_SCOM                                 = 0x370F0118ull;

static const uint64_t P9N2_PERV_EC23_PPM_PFCS_SCOM1                                = 0x370F0119ull;

static const uint64_t P9N2_PERV_EC23_PPM_PFCS_SCOM2                                = 0x370F011Aull;


static const uint64_t P9N2_PERV_EP00_PPM_PFDLY                                     = 0x100F011Bull;

static const uint64_t P9N2_PERV_EP01_PPM_PFDLY                                     = 0x110F011Bull;

static const uint64_t P9N2_PERV_EP02_PPM_PFDLY                                     = 0x120F011Bull;

static const uint64_t P9N2_PERV_EP03_PPM_PFDLY                                     = 0x130F011Bull;

static const uint64_t P9N2_PERV_EP04_PPM_PFDLY                                     = 0x140F011Bull;

static const uint64_t P9N2_PERV_EP05_PPM_PFDLY                                     = 0x150F011Bull;

static const uint64_t P9N2_PERV_EC00_PPM_PFDLY                                     = 0x200F011Bull;

static const uint64_t P9N2_PERV_EC01_PPM_PFDLY                                     = 0x210F011Bull;

static const uint64_t P9N2_PERV_EC02_PPM_PFDLY                                     = 0x220F011Bull;

static const uint64_t P9N2_PERV_EC03_PPM_PFDLY                                     = 0x230F011Bull;

static const uint64_t P9N2_PERV_EC04_PPM_PFDLY                                     = 0x240F011Bull;

static const uint64_t P9N2_PERV_EC05_PPM_PFDLY                                     = 0x250F011Bull;

static const uint64_t P9N2_PERV_EC06_PPM_PFDLY                                     = 0x260F011Bull;

static const uint64_t P9N2_PERV_EC07_PPM_PFDLY                                     = 0x270F011Bull;

static const uint64_t P9N2_PERV_EC08_PPM_PFDLY                                     = 0x280F011Bull;

static const uint64_t P9N2_PERV_EC09_PPM_PFDLY                                     = 0x290F011Bull;

static const uint64_t P9N2_PERV_EC10_PPM_PFDLY                                     = 0x2A0F011Bull;

static const uint64_t P9N2_PERV_EC11_PPM_PFDLY                                     = 0x2B0F011Bull;

static const uint64_t P9N2_PERV_EC12_PPM_PFDLY                                     = 0x2C0F011Bull;

static const uint64_t P9N2_PERV_EC13_PPM_PFDLY                                     = 0x2D0F011Bull;

static const uint64_t P9N2_PERV_EC14_PPM_PFDLY                                     = 0x2E0F011Bull;

static const uint64_t P9N2_PERV_EC15_PPM_PFDLY                                     = 0x2F0F011Bull;

static const uint64_t P9N2_PERV_EC16_PPM_PFDLY                                     = 0x300F011Bull;

static const uint64_t P9N2_PERV_EC17_PPM_PFDLY                                     = 0x310F011Bull;

static const uint64_t P9N2_PERV_EC18_PPM_PFDLY                                     = 0x320F011Bull;

static const uint64_t P9N2_PERV_EC19_PPM_PFDLY                                     = 0x330F011Bull;

static const uint64_t P9N2_PERV_EC20_PPM_PFDLY                                     = 0x340F011Bull;

static const uint64_t P9N2_PERV_EC21_PPM_PFDLY                                     = 0x350F011Bull;

static const uint64_t P9N2_PERV_EC22_PPM_PFDLY                                     = 0x360F011Bull;

static const uint64_t P9N2_PERV_EC23_PPM_PFDLY                                     = 0x370F011Bull;


static const uint64_t P9N2_PERV_EP00_PPM_PFOFF                                     = 0x100F011Dull;

static const uint64_t P9N2_PERV_EP01_PPM_PFOFF                                     = 0x110F011Dull;

static const uint64_t P9N2_PERV_EP02_PPM_PFOFF                                     = 0x120F011Dull;

static const uint64_t P9N2_PERV_EP03_PPM_PFOFF                                     = 0x130F011Dull;

static const uint64_t P9N2_PERV_EP04_PPM_PFOFF                                     = 0x140F011Dull;

static const uint64_t P9N2_PERV_EP05_PPM_PFOFF                                     = 0x150F011Dull;

static const uint64_t P9N2_PERV_EC00_PPM_PFOFF                                     = 0x200F011Dull;

static const uint64_t P9N2_PERV_EC01_PPM_PFOFF                                     = 0x210F011Dull;

static const uint64_t P9N2_PERV_EC02_PPM_PFOFF                                     = 0x220F011Dull;

static const uint64_t P9N2_PERV_EC03_PPM_PFOFF                                     = 0x230F011Dull;

static const uint64_t P9N2_PERV_EC04_PPM_PFOFF                                     = 0x240F011Dull;

static const uint64_t P9N2_PERV_EC05_PPM_PFOFF                                     = 0x250F011Dull;

static const uint64_t P9N2_PERV_EC06_PPM_PFOFF                                     = 0x260F011Dull;

static const uint64_t P9N2_PERV_EC07_PPM_PFOFF                                     = 0x270F011Dull;

static const uint64_t P9N2_PERV_EC08_PPM_PFOFF                                     = 0x280F011Dull;

static const uint64_t P9N2_PERV_EC09_PPM_PFOFF                                     = 0x290F011Dull;

static const uint64_t P9N2_PERV_EC10_PPM_PFOFF                                     = 0x2A0F011Dull;

static const uint64_t P9N2_PERV_EC11_PPM_PFOFF                                     = 0x2B0F011Dull;

static const uint64_t P9N2_PERV_EC12_PPM_PFOFF                                     = 0x2C0F011Dull;

static const uint64_t P9N2_PERV_EC13_PPM_PFOFF                                     = 0x2D0F011Dull;

static const uint64_t P9N2_PERV_EC14_PPM_PFOFF                                     = 0x2E0F011Dull;

static const uint64_t P9N2_PERV_EC15_PPM_PFOFF                                     = 0x2F0F011Dull;

static const uint64_t P9N2_PERV_EC16_PPM_PFOFF                                     = 0x300F011Dull;

static const uint64_t P9N2_PERV_EC17_PPM_PFOFF                                     = 0x310F011Dull;

static const uint64_t P9N2_PERV_EC18_PPM_PFOFF                                     = 0x320F011Dull;

static const uint64_t P9N2_PERV_EC19_PPM_PFOFF                                     = 0x330F011Dull;

static const uint64_t P9N2_PERV_EC20_PPM_PFOFF                                     = 0x340F011Dull;

static const uint64_t P9N2_PERV_EC21_PPM_PFOFF                                     = 0x350F011Dull;

static const uint64_t P9N2_PERV_EC22_PPM_PFOFF                                     = 0x360F011Dull;

static const uint64_t P9N2_PERV_EC23_PPM_PFOFF                                     = 0x370F011Dull;


static const uint64_t P9N2_PERV_EP00_PPM_PFSNS                                     = 0x100F011Cull;

static const uint64_t P9N2_PERV_EP01_PPM_PFSNS                                     = 0x110F011Cull;

static const uint64_t P9N2_PERV_EP02_PPM_PFSNS                                     = 0x120F011Cull;

static const uint64_t P9N2_PERV_EP03_PPM_PFSNS                                     = 0x130F011Cull;

static const uint64_t P9N2_PERV_EP04_PPM_PFSNS                                     = 0x140F011Cull;

static const uint64_t P9N2_PERV_EP05_PPM_PFSNS                                     = 0x150F011Cull;

static const uint64_t P9N2_PERV_EC00_PPM_PFSNS                                     = 0x200F011Cull;

static const uint64_t P9N2_PERV_EC01_PPM_PFSNS                                     = 0x210F011Cull;

static const uint64_t P9N2_PERV_EC02_PPM_PFSNS                                     = 0x220F011Cull;

static const uint64_t P9N2_PERV_EC03_PPM_PFSNS                                     = 0x230F011Cull;

static const uint64_t P9N2_PERV_EC04_PPM_PFSNS                                     = 0x240F011Cull;

static const uint64_t P9N2_PERV_EC05_PPM_PFSNS                                     = 0x250F011Cull;

static const uint64_t P9N2_PERV_EC06_PPM_PFSNS                                     = 0x260F011Cull;

static const uint64_t P9N2_PERV_EC07_PPM_PFSNS                                     = 0x270F011Cull;

static const uint64_t P9N2_PERV_EC08_PPM_PFSNS                                     = 0x280F011Cull;

static const uint64_t P9N2_PERV_EC09_PPM_PFSNS                                     = 0x290F011Cull;

static const uint64_t P9N2_PERV_EC10_PPM_PFSNS                                     = 0x2A0F011Cull;

static const uint64_t P9N2_PERV_EC11_PPM_PFSNS                                     = 0x2B0F011Cull;

static const uint64_t P9N2_PERV_EC12_PPM_PFSNS                                     = 0x2C0F011Cull;

static const uint64_t P9N2_PERV_EC13_PPM_PFSNS                                     = 0x2D0F011Cull;

static const uint64_t P9N2_PERV_EC14_PPM_PFSNS                                     = 0x2E0F011Cull;

static const uint64_t P9N2_PERV_EC15_PPM_PFSNS                                     = 0x2F0F011Cull;

static const uint64_t P9N2_PERV_EC16_PPM_PFSNS                                     = 0x300F011Cull;

static const uint64_t P9N2_PERV_EC17_PPM_PFSNS                                     = 0x310F011Cull;

static const uint64_t P9N2_PERV_EC18_PPM_PFSNS                                     = 0x320F011Cull;

static const uint64_t P9N2_PERV_EC19_PPM_PFSNS                                     = 0x330F011Cull;

static const uint64_t P9N2_PERV_EC20_PPM_PFSNS                                     = 0x340F011Cull;

static const uint64_t P9N2_PERV_EC21_PPM_PFSNS                                     = 0x350F011Cull;

static const uint64_t P9N2_PERV_EC22_PPM_PFSNS                                     = 0x360F011Cull;

static const uint64_t P9N2_PERV_EC23_PPM_PFSNS                                     = 0x370F011Cull;


static const uint64_t P9N2_PERV_EP00_PPM_PIG                                       = 0x100F0180ull;

static const uint64_t P9N2_PERV_EP01_PPM_PIG                                       = 0x110F0180ull;

static const uint64_t P9N2_PERV_EP02_PPM_PIG                                       = 0x120F0180ull;

static const uint64_t P9N2_PERV_EP03_PPM_PIG                                       = 0x130F0180ull;

static const uint64_t P9N2_PERV_EP04_PPM_PIG                                       = 0x140F0180ull;

static const uint64_t P9N2_PERV_EP05_PPM_PIG                                       = 0x150F0180ull;

static const uint64_t P9N2_PERV_EC00_PPM_PIG                                       = 0x200F0180ull;

static const uint64_t P9N2_PERV_EC01_PPM_PIG                                       = 0x210F0180ull;

static const uint64_t P9N2_PERV_EC02_PPM_PIG                                       = 0x220F0180ull;

static const uint64_t P9N2_PERV_EC03_PPM_PIG                                       = 0x230F0180ull;

static const uint64_t P9N2_PERV_EC04_PPM_PIG                                       = 0x240F0180ull;

static const uint64_t P9N2_PERV_EC05_PPM_PIG                                       = 0x250F0180ull;

static const uint64_t P9N2_PERV_EC06_PPM_PIG                                       = 0x260F0180ull;

static const uint64_t P9N2_PERV_EC07_PPM_PIG                                       = 0x270F0180ull;

static const uint64_t P9N2_PERV_EC08_PPM_PIG                                       = 0x280F0180ull;

static const uint64_t P9N2_PERV_EC09_PPM_PIG                                       = 0x290F0180ull;

static const uint64_t P9N2_PERV_EC10_PPM_PIG                                       = 0x2A0F0180ull;

static const uint64_t P9N2_PERV_EC11_PPM_PIG                                       = 0x2B0F0180ull;

static const uint64_t P9N2_PERV_EC12_PPM_PIG                                       = 0x2C0F0180ull;

static const uint64_t P9N2_PERV_EC13_PPM_PIG                                       = 0x2D0F0180ull;

static const uint64_t P9N2_PERV_EC14_PPM_PIG                                       = 0x2E0F0180ull;

static const uint64_t P9N2_PERV_EC15_PPM_PIG                                       = 0x2F0F0180ull;

static const uint64_t P9N2_PERV_EC16_PPM_PIG                                       = 0x300F0180ull;

static const uint64_t P9N2_PERV_EC17_PPM_PIG                                       = 0x310F0180ull;

static const uint64_t P9N2_PERV_EC18_PPM_PIG                                       = 0x320F0180ull;

static const uint64_t P9N2_PERV_EC19_PPM_PIG                                       = 0x330F0180ull;

static const uint64_t P9N2_PERV_EC20_PPM_PIG                                       = 0x340F0180ull;

static const uint64_t P9N2_PERV_EC21_PPM_PIG                                       = 0x350F0180ull;

static const uint64_t P9N2_PERV_EC22_PPM_PIG                                       = 0x360F0180ull;

static const uint64_t P9N2_PERV_EC23_PPM_PIG                                       = 0x370F0180ull;


static const uint64_t P9N2_PERV_EP00_PPM_SCRATCH0                                  = 0x100F011Eull;

static const uint64_t P9N2_PERV_EP01_PPM_SCRATCH0                                  = 0x110F011Eull;

static const uint64_t P9N2_PERV_EP02_PPM_SCRATCH0                                  = 0x120F011Eull;

static const uint64_t P9N2_PERV_EP03_PPM_SCRATCH0                                  = 0x130F011Eull;

static const uint64_t P9N2_PERV_EP04_PPM_SCRATCH0                                  = 0x140F011Eull;

static const uint64_t P9N2_PERV_EP05_PPM_SCRATCH0                                  = 0x150F011Eull;

static const uint64_t P9N2_PERV_EC00_PPM_SCRATCH0                                  = 0x200F011Eull;

static const uint64_t P9N2_PERV_EC01_PPM_SCRATCH0                                  = 0x210F011Eull;

static const uint64_t P9N2_PERV_EC02_PPM_SCRATCH0                                  = 0x220F011Eull;

static const uint64_t P9N2_PERV_EC03_PPM_SCRATCH0                                  = 0x230F011Eull;

static const uint64_t P9N2_PERV_EC04_PPM_SCRATCH0                                  = 0x240F011Eull;

static const uint64_t P9N2_PERV_EC05_PPM_SCRATCH0                                  = 0x250F011Eull;

static const uint64_t P9N2_PERV_EC06_PPM_SCRATCH0                                  = 0x260F011Eull;

static const uint64_t P9N2_PERV_EC07_PPM_SCRATCH0                                  = 0x270F011Eull;

static const uint64_t P9N2_PERV_EC08_PPM_SCRATCH0                                  = 0x280F011Eull;

static const uint64_t P9N2_PERV_EC09_PPM_SCRATCH0                                  = 0x290F011Eull;

static const uint64_t P9N2_PERV_EC10_PPM_SCRATCH0                                  = 0x2A0F011Eull;

static const uint64_t P9N2_PERV_EC11_PPM_SCRATCH0                                  = 0x2B0F011Eull;

static const uint64_t P9N2_PERV_EC12_PPM_SCRATCH0                                  = 0x2C0F011Eull;

static const uint64_t P9N2_PERV_EC13_PPM_SCRATCH0                                  = 0x2D0F011Eull;

static const uint64_t P9N2_PERV_EC14_PPM_SCRATCH0                                  = 0x2E0F011Eull;

static const uint64_t P9N2_PERV_EC15_PPM_SCRATCH0                                  = 0x2F0F011Eull;

static const uint64_t P9N2_PERV_EC16_PPM_SCRATCH0                                  = 0x300F011Eull;

static const uint64_t P9N2_PERV_EC17_PPM_SCRATCH0                                  = 0x310F011Eull;

static const uint64_t P9N2_PERV_EC18_PPM_SCRATCH0                                  = 0x320F011Eull;

static const uint64_t P9N2_PERV_EC19_PPM_SCRATCH0                                  = 0x330F011Eull;

static const uint64_t P9N2_PERV_EC20_PPM_SCRATCH0                                  = 0x340F011Eull;

static const uint64_t P9N2_PERV_EC21_PPM_SCRATCH0                                  = 0x350F011Eull;

static const uint64_t P9N2_PERV_EC22_PPM_SCRATCH0                                  = 0x360F011Eull;

static const uint64_t P9N2_PERV_EC23_PPM_SCRATCH0                                  = 0x370F011Eull;


static const uint64_t P9N2_PERV_EP00_PPM_SCRATCH1                                  = 0x100F011Full;

static const uint64_t P9N2_PERV_EP01_PPM_SCRATCH1                                  = 0x110F011Full;

static const uint64_t P9N2_PERV_EP02_PPM_SCRATCH1                                  = 0x120F011Full;

static const uint64_t P9N2_PERV_EP03_PPM_SCRATCH1                                  = 0x130F011Full;

static const uint64_t P9N2_PERV_EP04_PPM_SCRATCH1                                  = 0x140F011Full;

static const uint64_t P9N2_PERV_EP05_PPM_SCRATCH1                                  = 0x150F011Full;

static const uint64_t P9N2_PERV_EC00_PPM_SCRATCH1                                  = 0x200F011Full;

static const uint64_t P9N2_PERV_EC01_PPM_SCRATCH1                                  = 0x210F011Full;

static const uint64_t P9N2_PERV_EC02_PPM_SCRATCH1                                  = 0x220F011Full;

static const uint64_t P9N2_PERV_EC03_PPM_SCRATCH1                                  = 0x230F011Full;

static const uint64_t P9N2_PERV_EC04_PPM_SCRATCH1                                  = 0x240F011Full;

static const uint64_t P9N2_PERV_EC05_PPM_SCRATCH1                                  = 0x250F011Full;

static const uint64_t P9N2_PERV_EC06_PPM_SCRATCH1                                  = 0x260F011Full;

static const uint64_t P9N2_PERV_EC07_PPM_SCRATCH1                                  = 0x270F011Full;

static const uint64_t P9N2_PERV_EC08_PPM_SCRATCH1                                  = 0x280F011Full;

static const uint64_t P9N2_PERV_EC09_PPM_SCRATCH1                                  = 0x290F011Full;

static const uint64_t P9N2_PERV_EC10_PPM_SCRATCH1                                  = 0x2A0F011Full;

static const uint64_t P9N2_PERV_EC11_PPM_SCRATCH1                                  = 0x2B0F011Full;

static const uint64_t P9N2_PERV_EC12_PPM_SCRATCH1                                  = 0x2C0F011Full;

static const uint64_t P9N2_PERV_EC13_PPM_SCRATCH1                                  = 0x2D0F011Full;

static const uint64_t P9N2_PERV_EC14_PPM_SCRATCH1                                  = 0x2E0F011Full;

static const uint64_t P9N2_PERV_EC15_PPM_SCRATCH1                                  = 0x2F0F011Full;

static const uint64_t P9N2_PERV_EC16_PPM_SCRATCH1                                  = 0x300F011Full;

static const uint64_t P9N2_PERV_EC17_PPM_SCRATCH1                                  = 0x310F011Full;

static const uint64_t P9N2_PERV_EC18_PPM_SCRATCH1                                  = 0x320F011Full;

static const uint64_t P9N2_PERV_EC19_PPM_SCRATCH1                                  = 0x330F011Full;

static const uint64_t P9N2_PERV_EC20_PPM_SCRATCH1                                  = 0x340F011Full;

static const uint64_t P9N2_PERV_EC21_PPM_SCRATCH1                                  = 0x350F011Full;

static const uint64_t P9N2_PERV_EC22_PPM_SCRATCH1                                  = 0x360F011Full;

static const uint64_t P9N2_PERV_EC23_PPM_SCRATCH1                                  = 0x370F011Full;


static const uint64_t P9N2_PERV_EP00_PPM_SPWKUP_FSP                                = 0x100F010Bull;

static const uint64_t P9N2_PERV_EP01_PPM_SPWKUP_FSP                                = 0x110F010Bull;

static const uint64_t P9N2_PERV_EP02_PPM_SPWKUP_FSP                                = 0x120F010Bull;

static const uint64_t P9N2_PERV_EP03_PPM_SPWKUP_FSP                                = 0x130F010Bull;

static const uint64_t P9N2_PERV_EP04_PPM_SPWKUP_FSP                                = 0x140F010Bull;

static const uint64_t P9N2_PERV_EP05_PPM_SPWKUP_FSP                                = 0x150F010Bull;

static const uint64_t P9N2_PERV_EC00_PPM_SPWKUP_FSP                                = 0x200F010Bull;

static const uint64_t P9N2_PERV_EC01_PPM_SPWKUP_FSP                                = 0x210F010Bull;

static const uint64_t P9N2_PERV_EC02_PPM_SPWKUP_FSP                                = 0x220F010Bull;

static const uint64_t P9N2_PERV_EC03_PPM_SPWKUP_FSP                                = 0x230F010Bull;

static const uint64_t P9N2_PERV_EC04_PPM_SPWKUP_FSP                                = 0x240F010Bull;

static const uint64_t P9N2_PERV_EC05_PPM_SPWKUP_FSP                                = 0x250F010Bull;

static const uint64_t P9N2_PERV_EC06_PPM_SPWKUP_FSP                                = 0x260F010Bull;

static const uint64_t P9N2_PERV_EC07_PPM_SPWKUP_FSP                                = 0x270F010Bull;

static const uint64_t P9N2_PERV_EC08_PPM_SPWKUP_FSP                                = 0x280F010Bull;

static const uint64_t P9N2_PERV_EC09_PPM_SPWKUP_FSP                                = 0x290F010Bull;

static const uint64_t P9N2_PERV_EC10_PPM_SPWKUP_FSP                                = 0x2A0F010Bull;

static const uint64_t P9N2_PERV_EC11_PPM_SPWKUP_FSP                                = 0x2B0F010Bull;

static const uint64_t P9N2_PERV_EC12_PPM_SPWKUP_FSP                                = 0x2C0F010Bull;

static const uint64_t P9N2_PERV_EC13_PPM_SPWKUP_FSP                                = 0x2D0F010Bull;

static const uint64_t P9N2_PERV_EC14_PPM_SPWKUP_FSP                                = 0x2E0F010Bull;

static const uint64_t P9N2_PERV_EC15_PPM_SPWKUP_FSP                                = 0x2F0F010Bull;

static const uint64_t P9N2_PERV_EC16_PPM_SPWKUP_FSP                                = 0x300F010Bull;

static const uint64_t P9N2_PERV_EC17_PPM_SPWKUP_FSP                                = 0x310F010Bull;

static const uint64_t P9N2_PERV_EC18_PPM_SPWKUP_FSP                                = 0x320F010Bull;

static const uint64_t P9N2_PERV_EC19_PPM_SPWKUP_FSP                                = 0x330F010Bull;

static const uint64_t P9N2_PERV_EC20_PPM_SPWKUP_FSP                                = 0x340F010Bull;

static const uint64_t P9N2_PERV_EC21_PPM_SPWKUP_FSP                                = 0x350F010Bull;

static const uint64_t P9N2_PERV_EC22_PPM_SPWKUP_FSP                                = 0x360F010Bull;

static const uint64_t P9N2_PERV_EC23_PPM_SPWKUP_FSP                                = 0x370F010Bull;


static const uint64_t P9N2_PERV_EP00_PPM_SPWKUP_HYP                                = 0x100F010Dull;

static const uint64_t P9N2_PERV_EP01_PPM_SPWKUP_HYP                                = 0x110F010Dull;

static const uint64_t P9N2_PERV_EP02_PPM_SPWKUP_HYP                                = 0x120F010Dull;

static const uint64_t P9N2_PERV_EP03_PPM_SPWKUP_HYP                                = 0x130F010Dull;

static const uint64_t P9N2_PERV_EP04_PPM_SPWKUP_HYP                                = 0x140F010Dull;

static const uint64_t P9N2_PERV_EP05_PPM_SPWKUP_HYP                                = 0x150F010Dull;

static const uint64_t P9N2_PERV_EC00_PPM_SPWKUP_HYP                                = 0x200F010Dull;

static const uint64_t P9N2_PERV_EC01_PPM_SPWKUP_HYP                                = 0x210F010Dull;

static const uint64_t P9N2_PERV_EC02_PPM_SPWKUP_HYP                                = 0x220F010Dull;

static const uint64_t P9N2_PERV_EC03_PPM_SPWKUP_HYP                                = 0x230F010Dull;

static const uint64_t P9N2_PERV_EC04_PPM_SPWKUP_HYP                                = 0x240F010Dull;

static const uint64_t P9N2_PERV_EC05_PPM_SPWKUP_HYP                                = 0x250F010Dull;

static const uint64_t P9N2_PERV_EC06_PPM_SPWKUP_HYP                                = 0x260F010Dull;

static const uint64_t P9N2_PERV_EC07_PPM_SPWKUP_HYP                                = 0x270F010Dull;

static const uint64_t P9N2_PERV_EC08_PPM_SPWKUP_HYP                                = 0x280F010Dull;

static const uint64_t P9N2_PERV_EC09_PPM_SPWKUP_HYP                                = 0x290F010Dull;

static const uint64_t P9N2_PERV_EC10_PPM_SPWKUP_HYP                                = 0x2A0F010Dull;

static const uint64_t P9N2_PERV_EC11_PPM_SPWKUP_HYP                                = 0x2B0F010Dull;

static const uint64_t P9N2_PERV_EC12_PPM_SPWKUP_HYP                                = 0x2C0F010Dull;

static const uint64_t P9N2_PERV_EC13_PPM_SPWKUP_HYP                                = 0x2D0F010Dull;

static const uint64_t P9N2_PERV_EC14_PPM_SPWKUP_HYP                                = 0x2E0F010Dull;

static const uint64_t P9N2_PERV_EC15_PPM_SPWKUP_HYP                                = 0x2F0F010Dull;

static const uint64_t P9N2_PERV_EC16_PPM_SPWKUP_HYP                                = 0x300F010Dull;

static const uint64_t P9N2_PERV_EC17_PPM_SPWKUP_HYP                                = 0x310F010Dull;

static const uint64_t P9N2_PERV_EC18_PPM_SPWKUP_HYP                                = 0x320F010Dull;

static const uint64_t P9N2_PERV_EC19_PPM_SPWKUP_HYP                                = 0x330F010Dull;

static const uint64_t P9N2_PERV_EC20_PPM_SPWKUP_HYP                                = 0x340F010Dull;

static const uint64_t P9N2_PERV_EC21_PPM_SPWKUP_HYP                                = 0x350F010Dull;

static const uint64_t P9N2_PERV_EC22_PPM_SPWKUP_HYP                                = 0x360F010Dull;

static const uint64_t P9N2_PERV_EC23_PPM_SPWKUP_HYP                                = 0x370F010Dull;


static const uint64_t P9N2_PERV_EP00_PPM_SPWKUP_OCC                                = 0x100F010Cull;

static const uint64_t P9N2_PERV_EP01_PPM_SPWKUP_OCC                                = 0x110F010Cull;

static const uint64_t P9N2_PERV_EP02_PPM_SPWKUP_OCC                                = 0x120F010Cull;

static const uint64_t P9N2_PERV_EP03_PPM_SPWKUP_OCC                                = 0x130F010Cull;

static const uint64_t P9N2_PERV_EP04_PPM_SPWKUP_OCC                                = 0x140F010Cull;

static const uint64_t P9N2_PERV_EP05_PPM_SPWKUP_OCC                                = 0x150F010Cull;

static const uint64_t P9N2_PERV_EC00_PPM_SPWKUP_OCC                                = 0x200F010Cull;

static const uint64_t P9N2_PERV_EC01_PPM_SPWKUP_OCC                                = 0x210F010Cull;

static const uint64_t P9N2_PERV_EC02_PPM_SPWKUP_OCC                                = 0x220F010Cull;

static const uint64_t P9N2_PERV_EC03_PPM_SPWKUP_OCC                                = 0x230F010Cull;

static const uint64_t P9N2_PERV_EC04_PPM_SPWKUP_OCC                                = 0x240F010Cull;

static const uint64_t P9N2_PERV_EC05_PPM_SPWKUP_OCC                                = 0x250F010Cull;

static const uint64_t P9N2_PERV_EC06_PPM_SPWKUP_OCC                                = 0x260F010Cull;

static const uint64_t P9N2_PERV_EC07_PPM_SPWKUP_OCC                                = 0x270F010Cull;

static const uint64_t P9N2_PERV_EC08_PPM_SPWKUP_OCC                                = 0x280F010Cull;

static const uint64_t P9N2_PERV_EC09_PPM_SPWKUP_OCC                                = 0x290F010Cull;

static const uint64_t P9N2_PERV_EC10_PPM_SPWKUP_OCC                                = 0x2A0F010Cull;

static const uint64_t P9N2_PERV_EC11_PPM_SPWKUP_OCC                                = 0x2B0F010Cull;

static const uint64_t P9N2_PERV_EC12_PPM_SPWKUP_OCC                                = 0x2C0F010Cull;

static const uint64_t P9N2_PERV_EC13_PPM_SPWKUP_OCC                                = 0x2D0F010Cull;

static const uint64_t P9N2_PERV_EC14_PPM_SPWKUP_OCC                                = 0x2E0F010Cull;

static const uint64_t P9N2_PERV_EC15_PPM_SPWKUP_OCC                                = 0x2F0F010Cull;

static const uint64_t P9N2_PERV_EC16_PPM_SPWKUP_OCC                                = 0x300F010Cull;

static const uint64_t P9N2_PERV_EC17_PPM_SPWKUP_OCC                                = 0x310F010Cull;

static const uint64_t P9N2_PERV_EC18_PPM_SPWKUP_OCC                                = 0x320F010Cull;

static const uint64_t P9N2_PERV_EC19_PPM_SPWKUP_OCC                                = 0x330F010Cull;

static const uint64_t P9N2_PERV_EC20_PPM_SPWKUP_OCC                                = 0x340F010Cull;

static const uint64_t P9N2_PERV_EC21_PPM_SPWKUP_OCC                                = 0x350F010Cull;

static const uint64_t P9N2_PERV_EC22_PPM_SPWKUP_OCC                                = 0x360F010Cull;

static const uint64_t P9N2_PERV_EC23_PPM_SPWKUP_OCC                                = 0x370F010Cull;


static const uint64_t P9N2_PERV_EP00_PPM_SPWKUP_OTR                                = 0x100F010Aull;

static const uint64_t P9N2_PERV_EP01_PPM_SPWKUP_OTR                                = 0x110F010Aull;

static const uint64_t P9N2_PERV_EP02_PPM_SPWKUP_OTR                                = 0x120F010Aull;

static const uint64_t P9N2_PERV_EP03_PPM_SPWKUP_OTR                                = 0x130F010Aull;

static const uint64_t P9N2_PERV_EP04_PPM_SPWKUP_OTR                                = 0x140F010Aull;

static const uint64_t P9N2_PERV_EP05_PPM_SPWKUP_OTR                                = 0x150F010Aull;

static const uint64_t P9N2_PERV_EC00_PPM_SPWKUP_OTR                                = 0x200F010Aull;

static const uint64_t P9N2_PERV_EC01_PPM_SPWKUP_OTR                                = 0x210F010Aull;

static const uint64_t P9N2_PERV_EC02_PPM_SPWKUP_OTR                                = 0x220F010Aull;

static const uint64_t P9N2_PERV_EC03_PPM_SPWKUP_OTR                                = 0x230F010Aull;

static const uint64_t P9N2_PERV_EC04_PPM_SPWKUP_OTR                                = 0x240F010Aull;

static const uint64_t P9N2_PERV_EC05_PPM_SPWKUP_OTR                                = 0x250F010Aull;

static const uint64_t P9N2_PERV_EC06_PPM_SPWKUP_OTR                                = 0x260F010Aull;

static const uint64_t P9N2_PERV_EC07_PPM_SPWKUP_OTR                                = 0x270F010Aull;

static const uint64_t P9N2_PERV_EC08_PPM_SPWKUP_OTR                                = 0x280F010Aull;

static const uint64_t P9N2_PERV_EC09_PPM_SPWKUP_OTR                                = 0x290F010Aull;

static const uint64_t P9N2_PERV_EC10_PPM_SPWKUP_OTR                                = 0x2A0F010Aull;

static const uint64_t P9N2_PERV_EC11_PPM_SPWKUP_OTR                                = 0x2B0F010Aull;

static const uint64_t P9N2_PERV_EC12_PPM_SPWKUP_OTR                                = 0x2C0F010Aull;

static const uint64_t P9N2_PERV_EC13_PPM_SPWKUP_OTR                                = 0x2D0F010Aull;

static const uint64_t P9N2_PERV_EC14_PPM_SPWKUP_OTR                                = 0x2E0F010Aull;

static const uint64_t P9N2_PERV_EC15_PPM_SPWKUP_OTR                                = 0x2F0F010Aull;

static const uint64_t P9N2_PERV_EC16_PPM_SPWKUP_OTR                                = 0x300F010Aull;

static const uint64_t P9N2_PERV_EC17_PPM_SPWKUP_OTR                                = 0x310F010Aull;

static const uint64_t P9N2_PERV_EC18_PPM_SPWKUP_OTR                                = 0x320F010Aull;

static const uint64_t P9N2_PERV_EC19_PPM_SPWKUP_OTR                                = 0x330F010Aull;

static const uint64_t P9N2_PERV_EC20_PPM_SPWKUP_OTR                                = 0x340F010Aull;

static const uint64_t P9N2_PERV_EC21_PPM_SPWKUP_OTR                                = 0x350F010Aull;

static const uint64_t P9N2_PERV_EC22_PPM_SPWKUP_OTR                                = 0x360F010Aull;

static const uint64_t P9N2_PERV_EC23_PPM_SPWKUP_OTR                                = 0x370F010Aull;


static const uint64_t P9N2_PERV_EP00_PPM_SSHFSP                                    = 0x100F0111ull;

static const uint64_t P9N2_PERV_EP01_PPM_SSHFSP                                    = 0x110F0111ull;

static const uint64_t P9N2_PERV_EP02_PPM_SSHFSP                                    = 0x120F0111ull;

static const uint64_t P9N2_PERV_EP03_PPM_SSHFSP                                    = 0x130F0111ull;

static const uint64_t P9N2_PERV_EP04_PPM_SSHFSP                                    = 0x140F0111ull;

static const uint64_t P9N2_PERV_EP05_PPM_SSHFSP                                    = 0x150F0111ull;

static const uint64_t P9N2_PERV_EC00_PPM_SSHFSP                                    = 0x200F0111ull;

static const uint64_t P9N2_PERV_EC01_PPM_SSHFSP                                    = 0x210F0111ull;

static const uint64_t P9N2_PERV_EC02_PPM_SSHFSP                                    = 0x220F0111ull;

static const uint64_t P9N2_PERV_EC03_PPM_SSHFSP                                    = 0x230F0111ull;

static const uint64_t P9N2_PERV_EC04_PPM_SSHFSP                                    = 0x240F0111ull;

static const uint64_t P9N2_PERV_EC05_PPM_SSHFSP                                    = 0x250F0111ull;

static const uint64_t P9N2_PERV_EC06_PPM_SSHFSP                                    = 0x260F0111ull;

static const uint64_t P9N2_PERV_EC07_PPM_SSHFSP                                    = 0x270F0111ull;

static const uint64_t P9N2_PERV_EC08_PPM_SSHFSP                                    = 0x280F0111ull;

static const uint64_t P9N2_PERV_EC09_PPM_SSHFSP                                    = 0x290F0111ull;

static const uint64_t P9N2_PERV_EC10_PPM_SSHFSP                                    = 0x2A0F0111ull;

static const uint64_t P9N2_PERV_EC11_PPM_SSHFSP                                    = 0x2B0F0111ull;

static const uint64_t P9N2_PERV_EC12_PPM_SSHFSP                                    = 0x2C0F0111ull;

static const uint64_t P9N2_PERV_EC13_PPM_SSHFSP                                    = 0x2D0F0111ull;

static const uint64_t P9N2_PERV_EC14_PPM_SSHFSP                                    = 0x2E0F0111ull;

static const uint64_t P9N2_PERV_EC15_PPM_SSHFSP                                    = 0x2F0F0111ull;

static const uint64_t P9N2_PERV_EC16_PPM_SSHFSP                                    = 0x300F0111ull;

static const uint64_t P9N2_PERV_EC17_PPM_SSHFSP                                    = 0x310F0111ull;

static const uint64_t P9N2_PERV_EC18_PPM_SSHFSP                                    = 0x320F0111ull;

static const uint64_t P9N2_PERV_EC19_PPM_SSHFSP                                    = 0x330F0111ull;

static const uint64_t P9N2_PERV_EC20_PPM_SSHFSP                                    = 0x340F0111ull;

static const uint64_t P9N2_PERV_EC21_PPM_SSHFSP                                    = 0x350F0111ull;

static const uint64_t P9N2_PERV_EC22_PPM_SSHFSP                                    = 0x360F0111ull;

static const uint64_t P9N2_PERV_EC23_PPM_SSHFSP                                    = 0x370F0111ull;


static const uint64_t P9N2_PERV_EP00_PPM_SSHHYP                                    = 0x100F0114ull;

static const uint64_t P9N2_PERV_EP01_PPM_SSHHYP                                    = 0x110F0114ull;

static const uint64_t P9N2_PERV_EP02_PPM_SSHHYP                                    = 0x120F0114ull;

static const uint64_t P9N2_PERV_EP03_PPM_SSHHYP                                    = 0x130F0114ull;

static const uint64_t P9N2_PERV_EP04_PPM_SSHHYP                                    = 0x140F0114ull;

static const uint64_t P9N2_PERV_EP05_PPM_SSHHYP                                    = 0x150F0114ull;

static const uint64_t P9N2_PERV_EC00_PPM_SSHHYP                                    = 0x200F0114ull;

static const uint64_t P9N2_PERV_EC01_PPM_SSHHYP                                    = 0x210F0114ull;

static const uint64_t P9N2_PERV_EC02_PPM_SSHHYP                                    = 0x220F0114ull;

static const uint64_t P9N2_PERV_EC03_PPM_SSHHYP                                    = 0x230F0114ull;

static const uint64_t P9N2_PERV_EC04_PPM_SSHHYP                                    = 0x240F0114ull;

static const uint64_t P9N2_PERV_EC05_PPM_SSHHYP                                    = 0x250F0114ull;

static const uint64_t P9N2_PERV_EC06_PPM_SSHHYP                                    = 0x260F0114ull;

static const uint64_t P9N2_PERV_EC07_PPM_SSHHYP                                    = 0x270F0114ull;

static const uint64_t P9N2_PERV_EC08_PPM_SSHHYP                                    = 0x280F0114ull;

static const uint64_t P9N2_PERV_EC09_PPM_SSHHYP                                    = 0x290F0114ull;

static const uint64_t P9N2_PERV_EC10_PPM_SSHHYP                                    = 0x2A0F0114ull;

static const uint64_t P9N2_PERV_EC11_PPM_SSHHYP                                    = 0x2B0F0114ull;

static const uint64_t P9N2_PERV_EC12_PPM_SSHHYP                                    = 0x2C0F0114ull;

static const uint64_t P9N2_PERV_EC13_PPM_SSHHYP                                    = 0x2D0F0114ull;

static const uint64_t P9N2_PERV_EC14_PPM_SSHHYP                                    = 0x2E0F0114ull;

static const uint64_t P9N2_PERV_EC15_PPM_SSHHYP                                    = 0x2F0F0114ull;

static const uint64_t P9N2_PERV_EC16_PPM_SSHHYP                                    = 0x300F0114ull;

static const uint64_t P9N2_PERV_EC17_PPM_SSHHYP                                    = 0x310F0114ull;

static const uint64_t P9N2_PERV_EC18_PPM_SSHHYP                                    = 0x320F0114ull;

static const uint64_t P9N2_PERV_EC19_PPM_SSHHYP                                    = 0x330F0114ull;

static const uint64_t P9N2_PERV_EC20_PPM_SSHHYP                                    = 0x340F0114ull;

static const uint64_t P9N2_PERV_EC21_PPM_SSHHYP                                    = 0x350F0114ull;

static const uint64_t P9N2_PERV_EC22_PPM_SSHHYP                                    = 0x360F0114ull;

static const uint64_t P9N2_PERV_EC23_PPM_SSHHYP                                    = 0x370F0114ull;


static const uint64_t P9N2_PERV_EP00_PPM_SSHOCC                                    = 0x100F0112ull;

static const uint64_t P9N2_PERV_EP01_PPM_SSHOCC                                    = 0x110F0112ull;

static const uint64_t P9N2_PERV_EP02_PPM_SSHOCC                                    = 0x120F0112ull;

static const uint64_t P9N2_PERV_EP03_PPM_SSHOCC                                    = 0x130F0112ull;

static const uint64_t P9N2_PERV_EP04_PPM_SSHOCC                                    = 0x140F0112ull;

static const uint64_t P9N2_PERV_EP05_PPM_SSHOCC                                    = 0x150F0112ull;

static const uint64_t P9N2_PERV_EC00_PPM_SSHOCC                                    = 0x200F0112ull;

static const uint64_t P9N2_PERV_EC01_PPM_SSHOCC                                    = 0x210F0112ull;

static const uint64_t P9N2_PERV_EC02_PPM_SSHOCC                                    = 0x220F0112ull;

static const uint64_t P9N2_PERV_EC03_PPM_SSHOCC                                    = 0x230F0112ull;

static const uint64_t P9N2_PERV_EC04_PPM_SSHOCC                                    = 0x240F0112ull;

static const uint64_t P9N2_PERV_EC05_PPM_SSHOCC                                    = 0x250F0112ull;

static const uint64_t P9N2_PERV_EC06_PPM_SSHOCC                                    = 0x260F0112ull;

static const uint64_t P9N2_PERV_EC07_PPM_SSHOCC                                    = 0x270F0112ull;

static const uint64_t P9N2_PERV_EC08_PPM_SSHOCC                                    = 0x280F0112ull;

static const uint64_t P9N2_PERV_EC09_PPM_SSHOCC                                    = 0x290F0112ull;

static const uint64_t P9N2_PERV_EC10_PPM_SSHOCC                                    = 0x2A0F0112ull;

static const uint64_t P9N2_PERV_EC11_PPM_SSHOCC                                    = 0x2B0F0112ull;

static const uint64_t P9N2_PERV_EC12_PPM_SSHOCC                                    = 0x2C0F0112ull;

static const uint64_t P9N2_PERV_EC13_PPM_SSHOCC                                    = 0x2D0F0112ull;

static const uint64_t P9N2_PERV_EC14_PPM_SSHOCC                                    = 0x2E0F0112ull;

static const uint64_t P9N2_PERV_EC15_PPM_SSHOCC                                    = 0x2F0F0112ull;

static const uint64_t P9N2_PERV_EC16_PPM_SSHOCC                                    = 0x300F0112ull;

static const uint64_t P9N2_PERV_EC17_PPM_SSHOCC                                    = 0x310F0112ull;

static const uint64_t P9N2_PERV_EC18_PPM_SSHOCC                                    = 0x320F0112ull;

static const uint64_t P9N2_PERV_EC19_PPM_SSHOCC                                    = 0x330F0112ull;

static const uint64_t P9N2_PERV_EC20_PPM_SSHOCC                                    = 0x340F0112ull;

static const uint64_t P9N2_PERV_EC21_PPM_SSHOCC                                    = 0x350F0112ull;

static const uint64_t P9N2_PERV_EC22_PPM_SSHOCC                                    = 0x360F0112ull;

static const uint64_t P9N2_PERV_EC23_PPM_SSHOCC                                    = 0x370F0112ull;


static const uint64_t P9N2_PERV_EP00_PPM_SSHOTR                                    = 0x100F0113ull;

static const uint64_t P9N2_PERV_EP01_PPM_SSHOTR                                    = 0x110F0113ull;

static const uint64_t P9N2_PERV_EP02_PPM_SSHOTR                                    = 0x120F0113ull;

static const uint64_t P9N2_PERV_EP03_PPM_SSHOTR                                    = 0x130F0113ull;

static const uint64_t P9N2_PERV_EP04_PPM_SSHOTR                                    = 0x140F0113ull;

static const uint64_t P9N2_PERV_EP05_PPM_SSHOTR                                    = 0x150F0113ull;

static const uint64_t P9N2_PERV_EC00_PPM_SSHOTR                                    = 0x200F0113ull;

static const uint64_t P9N2_PERV_EC01_PPM_SSHOTR                                    = 0x210F0113ull;

static const uint64_t P9N2_PERV_EC02_PPM_SSHOTR                                    = 0x220F0113ull;

static const uint64_t P9N2_PERV_EC03_PPM_SSHOTR                                    = 0x230F0113ull;

static const uint64_t P9N2_PERV_EC04_PPM_SSHOTR                                    = 0x240F0113ull;

static const uint64_t P9N2_PERV_EC05_PPM_SSHOTR                                    = 0x250F0113ull;

static const uint64_t P9N2_PERV_EC06_PPM_SSHOTR                                    = 0x260F0113ull;

static const uint64_t P9N2_PERV_EC07_PPM_SSHOTR                                    = 0x270F0113ull;

static const uint64_t P9N2_PERV_EC08_PPM_SSHOTR                                    = 0x280F0113ull;

static const uint64_t P9N2_PERV_EC09_PPM_SSHOTR                                    = 0x290F0113ull;

static const uint64_t P9N2_PERV_EC10_PPM_SSHOTR                                    = 0x2A0F0113ull;

static const uint64_t P9N2_PERV_EC11_PPM_SSHOTR                                    = 0x2B0F0113ull;

static const uint64_t P9N2_PERV_EC12_PPM_SSHOTR                                    = 0x2C0F0113ull;

static const uint64_t P9N2_PERV_EC13_PPM_SSHOTR                                    = 0x2D0F0113ull;

static const uint64_t P9N2_PERV_EC14_PPM_SSHOTR                                    = 0x2E0F0113ull;

static const uint64_t P9N2_PERV_EC15_PPM_SSHOTR                                    = 0x2F0F0113ull;

static const uint64_t P9N2_PERV_EC16_PPM_SSHOTR                                    = 0x300F0113ull;

static const uint64_t P9N2_PERV_EC17_PPM_SSHOTR                                    = 0x310F0113ull;

static const uint64_t P9N2_PERV_EC18_PPM_SSHOTR                                    = 0x320F0113ull;

static const uint64_t P9N2_PERV_EC19_PPM_SSHOTR                                    = 0x330F0113ull;

static const uint64_t P9N2_PERV_EC20_PPM_SSHOTR                                    = 0x340F0113ull;

static const uint64_t P9N2_PERV_EC21_PPM_SSHOTR                                    = 0x350F0113ull;

static const uint64_t P9N2_PERV_EC22_PPM_SSHOTR                                    = 0x360F0113ull;

static const uint64_t P9N2_PERV_EC23_PPM_SSHOTR                                    = 0x370F0113ull;


static const uint64_t P9N2_PERV_EP00_PPM_SSHSRC                                    = 0x100F0110ull;

static const uint64_t P9N2_PERV_EP01_PPM_SSHSRC                                    = 0x110F0110ull;

static const uint64_t P9N2_PERV_EP02_PPM_SSHSRC                                    = 0x120F0110ull;

static const uint64_t P9N2_PERV_EP03_PPM_SSHSRC                                    = 0x130F0110ull;

static const uint64_t P9N2_PERV_EP04_PPM_SSHSRC                                    = 0x140F0110ull;

static const uint64_t P9N2_PERV_EP05_PPM_SSHSRC                                    = 0x150F0110ull;

static const uint64_t P9N2_PERV_EC00_PPM_SSHSRC                                    = 0x200F0110ull;

static const uint64_t P9N2_PERV_EC01_PPM_SSHSRC                                    = 0x210F0110ull;

static const uint64_t P9N2_PERV_EC02_PPM_SSHSRC                                    = 0x220F0110ull;

static const uint64_t P9N2_PERV_EC03_PPM_SSHSRC                                    = 0x230F0110ull;

static const uint64_t P9N2_PERV_EC04_PPM_SSHSRC                                    = 0x240F0110ull;

static const uint64_t P9N2_PERV_EC05_PPM_SSHSRC                                    = 0x250F0110ull;

static const uint64_t P9N2_PERV_EC06_PPM_SSHSRC                                    = 0x260F0110ull;

static const uint64_t P9N2_PERV_EC07_PPM_SSHSRC                                    = 0x270F0110ull;

static const uint64_t P9N2_PERV_EC08_PPM_SSHSRC                                    = 0x280F0110ull;

static const uint64_t P9N2_PERV_EC09_PPM_SSHSRC                                    = 0x290F0110ull;

static const uint64_t P9N2_PERV_EC10_PPM_SSHSRC                                    = 0x2A0F0110ull;

static const uint64_t P9N2_PERV_EC11_PPM_SSHSRC                                    = 0x2B0F0110ull;

static const uint64_t P9N2_PERV_EC12_PPM_SSHSRC                                    = 0x2C0F0110ull;

static const uint64_t P9N2_PERV_EC13_PPM_SSHSRC                                    = 0x2D0F0110ull;

static const uint64_t P9N2_PERV_EC14_PPM_SSHSRC                                    = 0x2E0F0110ull;

static const uint64_t P9N2_PERV_EC15_PPM_SSHSRC                                    = 0x2F0F0110ull;

static const uint64_t P9N2_PERV_EC16_PPM_SSHSRC                                    = 0x300F0110ull;

static const uint64_t P9N2_PERV_EC17_PPM_SSHSRC                                    = 0x310F0110ull;

static const uint64_t P9N2_PERV_EC18_PPM_SSHSRC                                    = 0x320F0110ull;

static const uint64_t P9N2_PERV_EC19_PPM_SSHSRC                                    = 0x330F0110ull;

static const uint64_t P9N2_PERV_EC20_PPM_SSHSRC                                    = 0x340F0110ull;

static const uint64_t P9N2_PERV_EC21_PPM_SSHSRC                                    = 0x350F0110ull;

static const uint64_t P9N2_PERV_EC22_PPM_SSHSRC                                    = 0x360F0110ull;

static const uint64_t P9N2_PERV_EC23_PPM_SSHSRC                                    = 0x370F0110ull;


static const uint64_t P9N2_PERV_EP00_PPM_VDMCR                                     = 0x100F01B8ull;

static const uint64_t P9N2_PERV_EP00_PPM_VDMCR_CLEAR                               = 0x100F01B9ull;

static const uint64_t P9N2_PERV_EP00_PPM_VDMCR_OR                                  = 0x100F01BAull;

static const uint64_t P9N2_PERV_EP01_PPM_VDMCR                                     = 0x110F01B8ull;

static const uint64_t P9N2_PERV_EP01_PPM_VDMCR_CLEAR                               = 0x110F01B9ull;

static const uint64_t P9N2_PERV_EP01_PPM_VDMCR_OR                                  = 0x110F01BAull;

static const uint64_t P9N2_PERV_EP02_PPM_VDMCR                                     = 0x120F01B8ull;

static const uint64_t P9N2_PERV_EP02_PPM_VDMCR_CLEAR                               = 0x120F01B9ull;

static const uint64_t P9N2_PERV_EP02_PPM_VDMCR_OR                                  = 0x120F01BAull;

static const uint64_t P9N2_PERV_EP03_PPM_VDMCR                                     = 0x130F01B8ull;

static const uint64_t P9N2_PERV_EP03_PPM_VDMCR_CLEAR                               = 0x130F01B9ull;

static const uint64_t P9N2_PERV_EP03_PPM_VDMCR_OR                                  = 0x130F01BAull;

static const uint64_t P9N2_PERV_EP04_PPM_VDMCR                                     = 0x140F01B8ull;

static const uint64_t P9N2_PERV_EP04_PPM_VDMCR_CLEAR                               = 0x140F01B9ull;

static const uint64_t P9N2_PERV_EP04_PPM_VDMCR_OR                                  = 0x140F01BAull;

static const uint64_t P9N2_PERV_EP05_PPM_VDMCR                                     = 0x150F01B8ull;

static const uint64_t P9N2_PERV_EP05_PPM_VDMCR_CLEAR                               = 0x150F01B9ull;

static const uint64_t P9N2_PERV_EP05_PPM_VDMCR_OR                                  = 0x150F01BAull;

static const uint64_t P9N2_PERV_EC00_PPM_VDMCR                                     = 0x200F01B8ull;

static const uint64_t P9N2_PERV_EC00_PPM_VDMCR_CLEAR                               = 0x200F01B9ull;

static const uint64_t P9N2_PERV_EC00_PPM_VDMCR_OR                                  = 0x200F01BAull;

static const uint64_t P9N2_PERV_EC01_PPM_VDMCR                                     = 0x210F01B8ull;

static const uint64_t P9N2_PERV_EC01_PPM_VDMCR_CLEAR                               = 0x210F01B9ull;

static const uint64_t P9N2_PERV_EC01_PPM_VDMCR_OR                                  = 0x210F01BAull;

static const uint64_t P9N2_PERV_EC02_PPM_VDMCR                                     = 0x220F01B8ull;

static const uint64_t P9N2_PERV_EC02_PPM_VDMCR_CLEAR                               = 0x220F01B9ull;

static const uint64_t P9N2_PERV_EC02_PPM_VDMCR_OR                                  = 0x220F01BAull;

static const uint64_t P9N2_PERV_EC03_PPM_VDMCR                                     = 0x230F01B8ull;

static const uint64_t P9N2_PERV_EC03_PPM_VDMCR_CLEAR                               = 0x230F01B9ull;

static const uint64_t P9N2_PERV_EC03_PPM_VDMCR_OR                                  = 0x230F01BAull;

static const uint64_t P9N2_PERV_EC04_PPM_VDMCR                                     = 0x240F01B8ull;

static const uint64_t P9N2_PERV_EC04_PPM_VDMCR_CLEAR                               = 0x240F01B9ull;

static const uint64_t P9N2_PERV_EC04_PPM_VDMCR_OR                                  = 0x240F01BAull;

static const uint64_t P9N2_PERV_EC05_PPM_VDMCR                                     = 0x250F01B8ull;

static const uint64_t P9N2_PERV_EC05_PPM_VDMCR_CLEAR                               = 0x250F01B9ull;

static const uint64_t P9N2_PERV_EC05_PPM_VDMCR_OR                                  = 0x250F01BAull;

static const uint64_t P9N2_PERV_EC06_PPM_VDMCR                                     = 0x260F01B8ull;

static const uint64_t P9N2_PERV_EC06_PPM_VDMCR_CLEAR                               = 0x260F01B9ull;

static const uint64_t P9N2_PERV_EC06_PPM_VDMCR_OR                                  = 0x260F01BAull;

static const uint64_t P9N2_PERV_EC07_PPM_VDMCR                                     = 0x270F01B8ull;

static const uint64_t P9N2_PERV_EC07_PPM_VDMCR_CLEAR                               = 0x270F01B9ull;

static const uint64_t P9N2_PERV_EC07_PPM_VDMCR_OR                                  = 0x270F01BAull;

static const uint64_t P9N2_PERV_EC08_PPM_VDMCR                                     = 0x280F01B8ull;

static const uint64_t P9N2_PERV_EC08_PPM_VDMCR_CLEAR                               = 0x280F01B9ull;

static const uint64_t P9N2_PERV_EC08_PPM_VDMCR_OR                                  = 0x280F01BAull;

static const uint64_t P9N2_PERV_EC09_PPM_VDMCR                                     = 0x290F01B8ull;

static const uint64_t P9N2_PERV_EC09_PPM_VDMCR_CLEAR                               = 0x290F01B9ull;

static const uint64_t P9N2_PERV_EC09_PPM_VDMCR_OR                                  = 0x290F01BAull;

static const uint64_t P9N2_PERV_EC10_PPM_VDMCR                                     = 0x2A0F01B8ull;

static const uint64_t P9N2_PERV_EC10_PPM_VDMCR_CLEAR                               = 0x2A0F01B9ull;

static const uint64_t P9N2_PERV_EC10_PPM_VDMCR_OR                                  = 0x2A0F01BAull;

static const uint64_t P9N2_PERV_EC11_PPM_VDMCR                                     = 0x2B0F01B8ull;

static const uint64_t P9N2_PERV_EC11_PPM_VDMCR_CLEAR                               = 0x2B0F01B9ull;

static const uint64_t P9N2_PERV_EC11_PPM_VDMCR_OR                                  = 0x2B0F01BAull;

static const uint64_t P9N2_PERV_EC12_PPM_VDMCR                                     = 0x2C0F01B8ull;

static const uint64_t P9N2_PERV_EC12_PPM_VDMCR_CLEAR                               = 0x2C0F01B9ull;

static const uint64_t P9N2_PERV_EC12_PPM_VDMCR_OR                                  = 0x2C0F01BAull;

static const uint64_t P9N2_PERV_EC13_PPM_VDMCR                                     = 0x2D0F01B8ull;

static const uint64_t P9N2_PERV_EC13_PPM_VDMCR_CLEAR                               = 0x2D0F01B9ull;

static const uint64_t P9N2_PERV_EC13_PPM_VDMCR_OR                                  = 0x2D0F01BAull;

static const uint64_t P9N2_PERV_EC14_PPM_VDMCR                                     = 0x2E0F01B8ull;

static const uint64_t P9N2_PERV_EC14_PPM_VDMCR_CLEAR                               = 0x2E0F01B9ull;

static const uint64_t P9N2_PERV_EC14_PPM_VDMCR_OR                                  = 0x2E0F01BAull;

static const uint64_t P9N2_PERV_EC15_PPM_VDMCR                                     = 0x2F0F01B8ull;

static const uint64_t P9N2_PERV_EC15_PPM_VDMCR_CLEAR                               = 0x2F0F01B9ull;

static const uint64_t P9N2_PERV_EC15_PPM_VDMCR_OR                                  = 0x2F0F01BAull;

static const uint64_t P9N2_PERV_EC16_PPM_VDMCR                                     = 0x300F01B8ull;

static const uint64_t P9N2_PERV_EC16_PPM_VDMCR_CLEAR                               = 0x300F01B9ull;

static const uint64_t P9N2_PERV_EC16_PPM_VDMCR_OR                                  = 0x300F01BAull;

static const uint64_t P9N2_PERV_EC17_PPM_VDMCR                                     = 0x310F01B8ull;

static const uint64_t P9N2_PERV_EC17_PPM_VDMCR_CLEAR                               = 0x310F01B9ull;

static const uint64_t P9N2_PERV_EC17_PPM_VDMCR_OR                                  = 0x310F01BAull;

static const uint64_t P9N2_PERV_EC18_PPM_VDMCR                                     = 0x320F01B8ull;

static const uint64_t P9N2_PERV_EC18_PPM_VDMCR_CLEAR                               = 0x320F01B9ull;

static const uint64_t P9N2_PERV_EC18_PPM_VDMCR_OR                                  = 0x320F01BAull;

static const uint64_t P9N2_PERV_EC19_PPM_VDMCR                                     = 0x330F01B8ull;

static const uint64_t P9N2_PERV_EC19_PPM_VDMCR_CLEAR                               = 0x330F01B9ull;

static const uint64_t P9N2_PERV_EC19_PPM_VDMCR_OR                                  = 0x330F01BAull;

static const uint64_t P9N2_PERV_EC20_PPM_VDMCR                                     = 0x340F01B8ull;

static const uint64_t P9N2_PERV_EC20_PPM_VDMCR_CLEAR                               = 0x340F01B9ull;

static const uint64_t P9N2_PERV_EC20_PPM_VDMCR_OR                                  = 0x340F01BAull;

static const uint64_t P9N2_PERV_EC21_PPM_VDMCR                                     = 0x350F01B8ull;

static const uint64_t P9N2_PERV_EC21_PPM_VDMCR_CLEAR                               = 0x350F01B9ull;

static const uint64_t P9N2_PERV_EC21_PPM_VDMCR_OR                                  = 0x350F01BAull;

static const uint64_t P9N2_PERV_EC22_PPM_VDMCR                                     = 0x360F01B8ull;

static const uint64_t P9N2_PERV_EC22_PPM_VDMCR_CLEAR                               = 0x360F01B9ull;

static const uint64_t P9N2_PERV_EC22_PPM_VDMCR_OR                                  = 0x360F01BAull;

static const uint64_t P9N2_PERV_EC23_PPM_VDMCR                                     = 0x370F01B8ull;

static const uint64_t P9N2_PERV_EC23_PPM_VDMCR_CLEAR                               = 0x370F01B9ull;

static const uint64_t P9N2_PERV_EC23_PPM_VDMCR_OR                                  = 0x370F01BAull;


static const uint64_t P9N2_PERV_PRE_COUNTER_REG                                    = 0x000F0028ull;

static const uint64_t P9N2_PERV_TP_PRE_COUNTER_REG                                 = 0x010F0028ull;

static const uint64_t P9N2_PERV_N0_PRE_COUNTER_REG                                 = 0x020F0028ull;

static const uint64_t P9N2_PERV_N1_PRE_COUNTER_REG                                 = 0x030F0028ull;

static const uint64_t P9N2_PERV_N2_PRE_COUNTER_REG                                 = 0x040F0028ull;

static const uint64_t P9N2_PERV_N3_PRE_COUNTER_REG                                 = 0x050F0028ull;

static const uint64_t P9N2_PERV_XB_PRE_COUNTER_REG                                 = 0x060F0028ull;

static const uint64_t P9N2_PERV_MC01_PRE_COUNTER_REG                               = 0x070F0028ull;

static const uint64_t P9N2_PERV_MC23_PRE_COUNTER_REG                               = 0x080F0028ull;

static const uint64_t P9N2_PERV_OB0_PRE_COUNTER_REG                                = 0x090F0028ull;

static const uint64_t P9N2_PERV_OB3_PRE_COUNTER_REG                                = 0x0C0F0028ull;

static const uint64_t P9N2_PERV_PCI0_PRE_COUNTER_REG                               = 0x0D0F0028ull;

static const uint64_t P9N2_PERV_PCI1_PRE_COUNTER_REG                               = 0x0E0F0028ull;

static const uint64_t P9N2_PERV_PCI2_PRE_COUNTER_REG                               = 0x0F0F0028ull;

static const uint64_t P9N2_PERV_EP00_PRE_COUNTER_REG                               = 0x100F0028ull;

static const uint64_t P9N2_PERV_EP01_PRE_COUNTER_REG                               = 0x110F0028ull;

static const uint64_t P9N2_PERV_EP02_PRE_COUNTER_REG                               = 0x120F0028ull;

static const uint64_t P9N2_PERV_EP03_PRE_COUNTER_REG                               = 0x130F0028ull;

static const uint64_t P9N2_PERV_EP04_PRE_COUNTER_REG                               = 0x140F0028ull;

static const uint64_t P9N2_PERV_EP05_PRE_COUNTER_REG                               = 0x150F0028ull;

static const uint64_t P9N2_PERV_EC00_PRE_COUNTER_REG                               = 0x200F0028ull;

static const uint64_t P9N2_PERV_EC01_PRE_COUNTER_REG                               = 0x210F0028ull;

static const uint64_t P9N2_PERV_EC02_PRE_COUNTER_REG                               = 0x220F0028ull;

static const uint64_t P9N2_PERV_EC03_PRE_COUNTER_REG                               = 0x230F0028ull;

static const uint64_t P9N2_PERV_EC04_PRE_COUNTER_REG                               = 0x240F0028ull;

static const uint64_t P9N2_PERV_EC05_PRE_COUNTER_REG                               = 0x250F0028ull;

static const uint64_t P9N2_PERV_EC06_PRE_COUNTER_REG                               = 0x260F0028ull;

static const uint64_t P9N2_PERV_EC07_PRE_COUNTER_REG                               = 0x270F0028ull;

static const uint64_t P9N2_PERV_EC08_PRE_COUNTER_REG                               = 0x280F0028ull;

static const uint64_t P9N2_PERV_EC09_PRE_COUNTER_REG                               = 0x290F0028ull;

static const uint64_t P9N2_PERV_EC10_PRE_COUNTER_REG                               = 0x2A0F0028ull;

static const uint64_t P9N2_PERV_EC11_PRE_COUNTER_REG                               = 0x2B0F0028ull;

static const uint64_t P9N2_PERV_EC12_PRE_COUNTER_REG                               = 0x2C0F0028ull;

static const uint64_t P9N2_PERV_EC13_PRE_COUNTER_REG                               = 0x2D0F0028ull;

static const uint64_t P9N2_PERV_EC14_PRE_COUNTER_REG                               = 0x2E0F0028ull;

static const uint64_t P9N2_PERV_EC15_PRE_COUNTER_REG                               = 0x2F0F0028ull;

static const uint64_t P9N2_PERV_EC16_PRE_COUNTER_REG                               = 0x300F0028ull;

static const uint64_t P9N2_PERV_EC17_PRE_COUNTER_REG                               = 0x310F0028ull;

static const uint64_t P9N2_PERV_EC18_PRE_COUNTER_REG                               = 0x320F0028ull;

static const uint64_t P9N2_PERV_EC19_PRE_COUNTER_REG                               = 0x330F0028ull;

static const uint64_t P9N2_PERV_EC20_PRE_COUNTER_REG                               = 0x340F0028ull;

static const uint64_t P9N2_PERV_EC21_PRE_COUNTER_REG                               = 0x350F0028ull;

static const uint64_t P9N2_PERV_EC22_PRE_COUNTER_REG                               = 0x360F0028ull;

static const uint64_t P9N2_PERV_EC23_PRE_COUNTER_REG                               = 0x370F0028ull;


static const uint64_t P9N2_PERV_PRIMARY_ADDRESS_REG                                = 0x000F0000ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_PRIMARY_ADDRESS_REG                             = 0x010F0000ull;

static const uint64_t P9N2_PERV_N0_PRIMARY_ADDRESS_REG                             = 0x020F0000ull;

static const uint64_t P9N2_PERV_N1_PRIMARY_ADDRESS_REG                             = 0x030F0000ull;

static const uint64_t P9N2_PERV_N2_PRIMARY_ADDRESS_REG                             = 0x040F0000ull;

static const uint64_t P9N2_PERV_N3_PRIMARY_ADDRESS_REG                             = 0x050F0000ull;

static const uint64_t P9N2_PERV_XB_PRIMARY_ADDRESS_REG                             = 0x060F0000ull;

static const uint64_t P9N2_PERV_MC01_PRIMARY_ADDRESS_REG                           = 0x070F0000ull;

static const uint64_t P9N2_PERV_MC23_PRIMARY_ADDRESS_REG                           = 0x080F0000ull;

static const uint64_t P9N2_PERV_OB0_PRIMARY_ADDRESS_REG                            = 0x090F0000ull;

static const uint64_t P9N2_PERV_OB3_PRIMARY_ADDRESS_REG                            = 0x0C0F0000ull;

static const uint64_t P9N2_PERV_PCI0_PRIMARY_ADDRESS_REG                           = 0x0D0F0000ull;

static const uint64_t P9N2_PERV_PCI1_PRIMARY_ADDRESS_REG                           = 0x0E0F0000ull;

static const uint64_t P9N2_PERV_PCI2_PRIMARY_ADDRESS_REG                           = 0x0F0F0000ull;

static const uint64_t P9N2_PERV_EP00_PRIMARY_ADDRESS_REG                           = 0x100F0000ull;

static const uint64_t P9N2_PERV_EP01_PRIMARY_ADDRESS_REG                           = 0x110F0000ull;

static const uint64_t P9N2_PERV_EP02_PRIMARY_ADDRESS_REG                           = 0x120F0000ull;

static const uint64_t P9N2_PERV_EP03_PRIMARY_ADDRESS_REG                           = 0x130F0000ull;

static const uint64_t P9N2_PERV_EP04_PRIMARY_ADDRESS_REG                           = 0x140F0000ull;

static const uint64_t P9N2_PERV_EP05_PRIMARY_ADDRESS_REG                           = 0x150F0000ull;

static const uint64_t P9N2_PERV_EC00_PRIMARY_ADDRESS_REG                           = 0x200F0000ull;

static const uint64_t P9N2_PERV_EC01_PRIMARY_ADDRESS_REG                           = 0x210F0000ull;

static const uint64_t P9N2_PERV_EC02_PRIMARY_ADDRESS_REG                           = 0x220F0000ull;

static const uint64_t P9N2_PERV_EC03_PRIMARY_ADDRESS_REG                           = 0x230F0000ull;

static const uint64_t P9N2_PERV_EC04_PRIMARY_ADDRESS_REG                           = 0x240F0000ull;

static const uint64_t P9N2_PERV_EC05_PRIMARY_ADDRESS_REG                           = 0x250F0000ull;

static const uint64_t P9N2_PERV_EC06_PRIMARY_ADDRESS_REG                           = 0x260F0000ull;

static const uint64_t P9N2_PERV_EC07_PRIMARY_ADDRESS_REG                           = 0x270F0000ull;

static const uint64_t P9N2_PERV_EC08_PRIMARY_ADDRESS_REG                           = 0x280F0000ull;

static const uint64_t P9N2_PERV_EC09_PRIMARY_ADDRESS_REG                           = 0x290F0000ull;

static const uint64_t P9N2_PERV_EC10_PRIMARY_ADDRESS_REG                           = 0x2A0F0000ull;

static const uint64_t P9N2_PERV_EC11_PRIMARY_ADDRESS_REG                           = 0x2B0F0000ull;

static const uint64_t P9N2_PERV_EC12_PRIMARY_ADDRESS_REG                           = 0x2C0F0000ull;

static const uint64_t P9N2_PERV_EC13_PRIMARY_ADDRESS_REG                           = 0x2D0F0000ull;

static const uint64_t P9N2_PERV_EC14_PRIMARY_ADDRESS_REG                           = 0x2E0F0000ull;

static const uint64_t P9N2_PERV_EC15_PRIMARY_ADDRESS_REG                           = 0x2F0F0000ull;

static const uint64_t P9N2_PERV_EC16_PRIMARY_ADDRESS_REG                           = 0x300F0000ull;

static const uint64_t P9N2_PERV_EC17_PRIMARY_ADDRESS_REG                           = 0x310F0000ull;

static const uint64_t P9N2_PERV_EC18_PRIMARY_ADDRESS_REG                           = 0x320F0000ull;

static const uint64_t P9N2_PERV_EC19_PRIMARY_ADDRESS_REG                           = 0x330F0000ull;

static const uint64_t P9N2_PERV_EC20_PRIMARY_ADDRESS_REG                           = 0x340F0000ull;

static const uint64_t P9N2_PERV_EC21_PRIMARY_ADDRESS_REG                           = 0x350F0000ull;

static const uint64_t P9N2_PERV_EC22_PRIMARY_ADDRESS_REG                           = 0x360F0000ull;

static const uint64_t P9N2_PERV_EC23_PRIMARY_ADDRESS_REG                           = 0x370F0000ull;


static const uint64_t P9N2_PERV_PROTECT_MODE_REG                                   = 0x000F03FEull;

static const uint64_t P9N2_PERV_TP_PROTECT_MODE_REG                                = 0x010F03FEull;

static const uint64_t P9N2_PERV_N0_PROTECT_MODE_REG                                = 0x020F03FEull;

static const uint64_t P9N2_PERV_N1_PROTECT_MODE_REG                                = 0x030F03FEull;

static const uint64_t P9N2_PERV_N2_PROTECT_MODE_REG                                = 0x040F03FEull;

static const uint64_t P9N2_PERV_N3_PROTECT_MODE_REG                                = 0x050F03FEull;

static const uint64_t P9N2_PERV_XB_PROTECT_MODE_REG                                = 0x060F03FEull;

static const uint64_t P9N2_PERV_MC01_PROTECT_MODE_REG                              = 0x070F03FEull;

static const uint64_t P9N2_PERV_MC23_PROTECT_MODE_REG                              = 0x080F03FEull;

static const uint64_t P9N2_PERV_OB0_PROTECT_MODE_REG                               = 0x090F03FEull;

static const uint64_t P9N2_PERV_OB3_PROTECT_MODE_REG                               = 0x0C0F03FEull;

static const uint64_t P9N2_PERV_PCI0_PROTECT_MODE_REG                              = 0x0D0F03FEull;

static const uint64_t P9N2_PERV_PCI1_PROTECT_MODE_REG                              = 0x0E0F03FEull;

static const uint64_t P9N2_PERV_PCI2_PROTECT_MODE_REG                              = 0x0F0F03FEull;

static const uint64_t P9N2_PERV_EP00_PROTECT_MODE_REG                              = 0x100F03FEull;

static const uint64_t P9N2_PERV_EP01_PROTECT_MODE_REG                              = 0x110F03FEull;

static const uint64_t P9N2_PERV_EP02_PROTECT_MODE_REG                              = 0x120F03FEull;

static const uint64_t P9N2_PERV_EP03_PROTECT_MODE_REG                              = 0x130F03FEull;

static const uint64_t P9N2_PERV_EP04_PROTECT_MODE_REG                              = 0x140F03FEull;

static const uint64_t P9N2_PERV_EP05_PROTECT_MODE_REG                              = 0x150F03FEull;

static const uint64_t P9N2_PERV_EC00_PROTECT_MODE_REG                              = 0x200F03FEull;

static const uint64_t P9N2_PERV_EC01_PROTECT_MODE_REG                              = 0x210F03FEull;

static const uint64_t P9N2_PERV_EC02_PROTECT_MODE_REG                              = 0x220F03FEull;

static const uint64_t P9N2_PERV_EC03_PROTECT_MODE_REG                              = 0x230F03FEull;

static const uint64_t P9N2_PERV_EC04_PROTECT_MODE_REG                              = 0x240F03FEull;

static const uint64_t P9N2_PERV_EC05_PROTECT_MODE_REG                              = 0x250F03FEull;

static const uint64_t P9N2_PERV_EC06_PROTECT_MODE_REG                              = 0x260F03FEull;

static const uint64_t P9N2_PERV_EC07_PROTECT_MODE_REG                              = 0x270F03FEull;

static const uint64_t P9N2_PERV_EC08_PROTECT_MODE_REG                              = 0x280F03FEull;

static const uint64_t P9N2_PERV_EC09_PROTECT_MODE_REG                              = 0x290F03FEull;

static const uint64_t P9N2_PERV_EC10_PROTECT_MODE_REG                              = 0x2A0F03FEull;

static const uint64_t P9N2_PERV_EC11_PROTECT_MODE_REG                              = 0x2B0F03FEull;

static const uint64_t P9N2_PERV_EC12_PROTECT_MODE_REG                              = 0x2C0F03FEull;

static const uint64_t P9N2_PERV_EC13_PROTECT_MODE_REG                              = 0x2D0F03FEull;

static const uint64_t P9N2_PERV_EC14_PROTECT_MODE_REG                              = 0x2E0F03FEull;

static const uint64_t P9N2_PERV_EC15_PROTECT_MODE_REG                              = 0x2F0F03FEull;

static const uint64_t P9N2_PERV_EC16_PROTECT_MODE_REG                              = 0x300F03FEull;

static const uint64_t P9N2_PERV_EC17_PROTECT_MODE_REG                              = 0x310F03FEull;

static const uint64_t P9N2_PERV_EC18_PROTECT_MODE_REG                              = 0x320F03FEull;

static const uint64_t P9N2_PERV_EC19_PROTECT_MODE_REG                              = 0x330F03FEull;

static const uint64_t P9N2_PERV_EC20_PROTECT_MODE_REG                              = 0x340F03FEull;

static const uint64_t P9N2_PERV_EC21_PROTECT_MODE_REG                              = 0x350F03FEull;

static const uint64_t P9N2_PERV_EC22_PROTECT_MODE_REG                              = 0x360F03FEull;

static const uint64_t P9N2_PERV_EC23_PROTECT_MODE_REG                              = 0x370F03FEull;


static const uint64_t P9N2_PERV_PSCOM_ERROR_MASK                                   = 0x00010002ull;

static const uint64_t P9N2_PERV_TP_PSCOM_ERROR_MASK                                = 0x01010002ull;


static const uint64_t P9N2_PERV_PSCOM_MODE_REG                                     = 0x00010000ull;

static const uint64_t P9N2_PERV_TP_PSCOM_MODE_REG                                  = 0x01010000ull;


static const uint64_t P9N2_PERV_PSCOM_STATUS_ERROR_REG                             = 0x00010001ull;

static const uint64_t P9N2_PERV_TP_PSCOM_STATUS_ERROR_REG                          = 0x01010001ull;


static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_CTRL                                = 0x100F0152ull;

static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_CTRL_CLEAR                          = 0x100F0153ull;

static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_CTRL_OR                             = 0x100F0154ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_CTRL                                = 0x110F0152ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_CTRL_CLEAR                          = 0x110F0153ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_CTRL_OR                             = 0x110F0154ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_CTRL                                = 0x120F0152ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_CTRL_CLEAR                          = 0x120F0153ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_CTRL_OR                             = 0x120F0154ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_CTRL                                = 0x130F0152ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_CTRL_CLEAR                          = 0x130F0153ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_CTRL_OR                             = 0x130F0154ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_CTRL                                = 0x140F0152ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_CTRL_CLEAR                          = 0x140F0153ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_CTRL_OR                             = 0x140F0154ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_CTRL                                = 0x150F0152ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_CTRL_CLEAR                          = 0x150F0153ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_CTRL_OR                             = 0x150F0154ull;


static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_FREQ                                = 0x100F0151ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_FREQ                                = 0x110F0151ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_FREQ                                = 0x120F0151ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_FREQ                                = 0x130F0151ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_FREQ                                = 0x140F0151ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_FREQ                                = 0x150F0151ull;


static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_ICHAR                               = 0x100F0157ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_ICHAR                               = 0x110F0157ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_ICHAR                               = 0x120F0157ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_ICHAR                               = 0x130F0157ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_ICHAR                               = 0x140F0157ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_ICHAR                               = 0x150F0157ull;


static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_OCHAR                               = 0x100F0156ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_OCHAR                               = 0x110F0156ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_OCHAR                               = 0x120F0156ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_OCHAR                               = 0x130F0156ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_OCHAR                               = 0x140F0156ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_OCHAR                               = 0x150F0156ull;


static const uint64_t P9N2_PERV_EP00_QPPM_DPLL_STAT                                = 0x100F0155ull;

static const uint64_t P9N2_PERV_EP01_QPPM_DPLL_STAT                                = 0x110F0155ull;

static const uint64_t P9N2_PERV_EP02_QPPM_DPLL_STAT                                = 0x120F0155ull;

static const uint64_t P9N2_PERV_EP03_QPPM_DPLL_STAT                                = 0x130F0155ull;

static const uint64_t P9N2_PERV_EP04_QPPM_DPLL_STAT                                = 0x140F0155ull;

static const uint64_t P9N2_PERV_EP05_QPPM_DPLL_STAT                                = 0x150F0155ull;


static const uint64_t P9N2_PERV_EP00_QPPM_ERR                                      = 0x100F0121ull;

static const uint64_t P9N2_PERV_EP01_QPPM_ERR                                      = 0x110F0121ull;

static const uint64_t P9N2_PERV_EP02_QPPM_ERR                                      = 0x120F0121ull;

static const uint64_t P9N2_PERV_EP03_QPPM_ERR                                      = 0x130F0121ull;

static const uint64_t P9N2_PERV_EP04_QPPM_ERR                                      = 0x140F0121ull;

static const uint64_t P9N2_PERV_EP05_QPPM_ERR                                      = 0x150F0121ull;


static const uint64_t P9N2_PERV_EP00_QPPM_ERRMSK                                   = 0x100F0122ull;

static const uint64_t P9N2_PERV_EP01_QPPM_ERRMSK                                   = 0x110F0122ull;

static const uint64_t P9N2_PERV_EP02_QPPM_ERRMSK                                   = 0x120F0122ull;

static const uint64_t P9N2_PERV_EP03_QPPM_ERRMSK                                   = 0x130F0122ull;

static const uint64_t P9N2_PERV_EP04_QPPM_ERRMSK                                   = 0x140F0122ull;

static const uint64_t P9N2_PERV_EP05_QPPM_ERRMSK                                   = 0x150F0122ull;


static const uint64_t P9N2_PERV_EP00_QPPM_ERRSUM                                   = 0x100F0120ull;

static const uint64_t P9N2_PERV_EP01_QPPM_ERRSUM                                   = 0x110F0120ull;

static const uint64_t P9N2_PERV_EP02_QPPM_ERRSUM                                   = 0x120F0120ull;

static const uint64_t P9N2_PERV_EP03_QPPM_ERRSUM                                   = 0x130F0120ull;

static const uint64_t P9N2_PERV_EP04_QPPM_ERRSUM                                   = 0x140F0120ull;

static const uint64_t P9N2_PERV_EP05_QPPM_ERRSUM                                   = 0x150F0120ull;


static const uint64_t P9N2_PERV_EP00_QPPM_EXCGCR                                   = 0x100F0165ull;

static const uint64_t P9N2_PERV_EP00_QPPM_EXCGCR_CLEAR                             = 0x100F0166ull;

static const uint64_t P9N2_PERV_EP00_QPPM_EXCGCR_OR                                = 0x100F0167ull;

static const uint64_t P9N2_PERV_EP01_QPPM_EXCGCR                                   = 0x110F0165ull;

static const uint64_t P9N2_PERV_EP01_QPPM_EXCGCR_CLEAR                             = 0x110F0166ull;

static const uint64_t P9N2_PERV_EP01_QPPM_EXCGCR_OR                                = 0x110F0167ull;

static const uint64_t P9N2_PERV_EP02_QPPM_EXCGCR                                   = 0x120F0165ull;

static const uint64_t P9N2_PERV_EP02_QPPM_EXCGCR_CLEAR                             = 0x120F0166ull;

static const uint64_t P9N2_PERV_EP02_QPPM_EXCGCR_OR                                = 0x120F0167ull;

static const uint64_t P9N2_PERV_EP03_QPPM_EXCGCR                                   = 0x130F0165ull;

static const uint64_t P9N2_PERV_EP03_QPPM_EXCGCR_CLEAR                             = 0x130F0166ull;

static const uint64_t P9N2_PERV_EP03_QPPM_EXCGCR_OR                                = 0x130F0167ull;

static const uint64_t P9N2_PERV_EP04_QPPM_EXCGCR                                   = 0x140F0165ull;

static const uint64_t P9N2_PERV_EP04_QPPM_EXCGCR_CLEAR                             = 0x140F0166ull;

static const uint64_t P9N2_PERV_EP04_QPPM_EXCGCR_OR                                = 0x140F0167ull;

static const uint64_t P9N2_PERV_EP05_QPPM_EXCGCR                                   = 0x150F0165ull;

static const uint64_t P9N2_PERV_EP05_QPPM_EXCGCR_CLEAR                             = 0x150F0166ull;

static const uint64_t P9N2_PERV_EP05_QPPM_EXCGCR_OR                                = 0x150F0167ull;


static const uint64_t P9N2_PERV_EP00_QPPM_OCCHB                                    = 0x100F015Full;

static const uint64_t P9N2_PERV_EP01_QPPM_OCCHB                                    = 0x110F015Full;

static const uint64_t P9N2_PERV_EP02_QPPM_OCCHB                                    = 0x120F015Full;

static const uint64_t P9N2_PERV_EP03_QPPM_OCCHB                                    = 0x130F015Full;

static const uint64_t P9N2_PERV_EP04_QPPM_OCCHB                                    = 0x140F015Full;

static const uint64_t P9N2_PERV_EP05_QPPM_OCCHB                                    = 0x150F015Full;


static const uint64_t P9N2_PERV_EP00_QPPM_QACCR                                    = 0x100F0160ull;

static const uint64_t P9N2_PERV_EP00_QPPM_QACCR_CLEAR                              = 0x100F0161ull;

static const uint64_t P9N2_PERV_EP00_QPPM_QACCR_OR                                 = 0x100F0162ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QACCR                                    = 0x110F0160ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QACCR_CLEAR                              = 0x110F0161ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QACCR_OR                                 = 0x110F0162ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QACCR                                    = 0x120F0160ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QACCR_CLEAR                              = 0x120F0161ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QACCR_OR                                 = 0x120F0162ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QACCR                                    = 0x130F0160ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QACCR_CLEAR                              = 0x130F0161ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QACCR_OR                                 = 0x130F0162ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QACCR                                    = 0x140F0160ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QACCR_CLEAR                              = 0x140F0161ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QACCR_OR                                 = 0x140F0162ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QACCR                                    = 0x150F0160ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QACCR_CLEAR                              = 0x150F0161ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QACCR_OR                                 = 0x150F0162ull;


static const uint64_t P9N2_PERV_EP00_QPPM_QACSR                                    = 0x100F0163ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QACSR                                    = 0x110F0163ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QACSR                                    = 0x120F0163ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QACSR                                    = 0x130F0163ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QACSR                                    = 0x140F0163ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QACSR                                    = 0x150F0163ull;


static const uint64_t P9N2_PERV_EP00_QPPM_QCCR_SCOM                                = 0x100F01BDull;

static const uint64_t P9N2_PERV_EP00_QPPM_QCCR_SCOM1                               = 0x100F01BEull;

static const uint64_t P9N2_PERV_EP00_QPPM_QCCR_SCOM2                               = 0x100F01BFull;

static const uint64_t P9N2_PERV_EP01_QPPM_QCCR_SCOM                                = 0x110F01BDull;

static const uint64_t P9N2_PERV_EP01_QPPM_QCCR_SCOM1                               = 0x110F01BEull;

static const uint64_t P9N2_PERV_EP01_QPPM_QCCR_SCOM2                               = 0x110F01BFull;

static const uint64_t P9N2_PERV_EP02_QPPM_QCCR_SCOM                                = 0x120F01BDull;

static const uint64_t P9N2_PERV_EP02_QPPM_QCCR_SCOM1                               = 0x120F01BEull;

static const uint64_t P9N2_PERV_EP02_QPPM_QCCR_SCOM2                               = 0x120F01BFull;

static const uint64_t P9N2_PERV_EP03_QPPM_QCCR_SCOM                                = 0x130F01BDull;

static const uint64_t P9N2_PERV_EP03_QPPM_QCCR_SCOM1                               = 0x130F01BEull;

static const uint64_t P9N2_PERV_EP03_QPPM_QCCR_SCOM2                               = 0x130F01BFull;

static const uint64_t P9N2_PERV_EP04_QPPM_QCCR_SCOM                                = 0x140F01BDull;

static const uint64_t P9N2_PERV_EP04_QPPM_QCCR_SCOM1                               = 0x140F01BEull;

static const uint64_t P9N2_PERV_EP04_QPPM_QCCR_SCOM2                               = 0x140F01BFull;

static const uint64_t P9N2_PERV_EP05_QPPM_QCCR_SCOM                                = 0x150F01BDull;

static const uint64_t P9N2_PERV_EP05_QPPM_QCCR_SCOM1                               = 0x150F01BEull;

static const uint64_t P9N2_PERV_EP05_QPPM_QCCR_SCOM2                               = 0x150F01BFull;


static const uint64_t P9N2_PERV_EP00_QPPM_QPMMR                                    = 0x100F0103ull;

static const uint64_t P9N2_PERV_EP00_QPPM_QPMMR_CLEAR                              = 0x100F0104ull;

static const uint64_t P9N2_PERV_EP00_QPPM_QPMMR_OR                                 = 0x100F0105ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QPMMR                                    = 0x110F0103ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QPMMR_CLEAR                              = 0x110F0104ull;

static const uint64_t P9N2_PERV_EP01_QPPM_QPMMR_OR                                 = 0x110F0105ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QPMMR                                    = 0x120F0103ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QPMMR_CLEAR                              = 0x120F0104ull;

static const uint64_t P9N2_PERV_EP02_QPPM_QPMMR_OR                                 = 0x120F0105ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QPMMR                                    = 0x130F0103ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QPMMR_CLEAR                              = 0x130F0104ull;

static const uint64_t P9N2_PERV_EP03_QPPM_QPMMR_OR                                 = 0x130F0105ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QPMMR                                    = 0x140F0103ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QPMMR_CLEAR                              = 0x140F0104ull;

static const uint64_t P9N2_PERV_EP04_QPPM_QPMMR_OR                                 = 0x140F0105ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QPMMR                                    = 0x150F0103ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QPMMR_CLEAR                              = 0x150F0104ull;

static const uint64_t P9N2_PERV_EP05_QPPM_QPMMR_OR                                 = 0x150F0105ull;


static const uint64_t P9N2_PERV_EP00_QPPM_VDMCFGR                                  = 0x100F01B6ull;

static const uint64_t P9N2_PERV_EP01_QPPM_VDMCFGR                                  = 0x110F01B6ull;

static const uint64_t P9N2_PERV_EP02_QPPM_VDMCFGR                                  = 0x120F01B6ull;

static const uint64_t P9N2_PERV_EP03_QPPM_VDMCFGR                                  = 0x130F01B6ull;

static const uint64_t P9N2_PERV_EP04_QPPM_VDMCFGR                                  = 0x140F01B6ull;

static const uint64_t P9N2_PERV_EP05_QPPM_VDMCFGR                                  = 0x150F01B6ull;


static const uint64_t P9N2_PERV_EP00_QPPM_VOLT_CHAR                                = 0x100F01BBull;

static const uint64_t P9N2_PERV_EP01_QPPM_VOLT_CHAR                                = 0x110F01BBull;

static const uint64_t P9N2_PERV_EP02_QPPM_VOLT_CHAR                                = 0x120F01BBull;

static const uint64_t P9N2_PERV_EP03_QPPM_VOLT_CHAR                                = 0x130F01BBull;

static const uint64_t P9N2_PERV_EP04_QPPM_VOLT_CHAR                                = 0x140F01BBull;

static const uint64_t P9N2_PERV_EP05_QPPM_VOLT_CHAR                                = 0x150F01BBull;


static const uint32_t P9N2_PERV_FSISHIFT_READ_BUFFER_FSI                           = 0x00000C03ull;

static const uint32_t P9N2_PERV_FSISHIFT_READ_BUFFER_FSI_BYTE                      = 0x00000C0Cull;


static const uint64_t P9N2_PERV_RECOV_INTERRUPT_REG                                = 0x000F001Bull;

static const uint64_t P9N2_PERV_TP_RECOV_INTERRUPT_REG                             = 0x010F001Bull;

static const uint64_t P9N2_PERV_N0_RECOV_INTERRUPT_REG                             = 0x020F001Bull;

static const uint64_t P9N2_PERV_N1_RECOV_INTERRUPT_REG                             = 0x030F001Bull;

static const uint64_t P9N2_PERV_N2_RECOV_INTERRUPT_REG                             = 0x040F001Bull;

static const uint64_t P9N2_PERV_N3_RECOV_INTERRUPT_REG                             = 0x050F001Bull;

static const uint64_t P9N2_PERV_XB_RECOV_INTERRUPT_REG                             = 0x060F001Bull;

static const uint64_t P9N2_PERV_MC01_RECOV_INTERRUPT_REG                           = 0x070F001Bull;

static const uint64_t P9N2_PERV_MC23_RECOV_INTERRUPT_REG                           = 0x080F001Bull;

static const uint64_t P9N2_PERV_OB0_RECOV_INTERRUPT_REG                            = 0x090F001Bull;

static const uint64_t P9N2_PERV_OB3_RECOV_INTERRUPT_REG                            = 0x0C0F001Bull;

static const uint64_t P9N2_PERV_PCI0_RECOV_INTERRUPT_REG                           = 0x0D0F001Bull;

static const uint64_t P9N2_PERV_PCI1_RECOV_INTERRUPT_REG                           = 0x0E0F001Bull;

static const uint64_t P9N2_PERV_PCI2_RECOV_INTERRUPT_REG                           = 0x0F0F001Bull;

static const uint64_t P9N2_PERV_EP00_RECOV_INTERRUPT_REG                           = 0x100F001Bull;

static const uint64_t P9N2_PERV_EP01_RECOV_INTERRUPT_REG                           = 0x110F001Bull;

static const uint64_t P9N2_PERV_EP02_RECOV_INTERRUPT_REG                           = 0x120F001Bull;

static const uint64_t P9N2_PERV_EP03_RECOV_INTERRUPT_REG                           = 0x130F001Bull;

static const uint64_t P9N2_PERV_EP04_RECOV_INTERRUPT_REG                           = 0x140F001Bull;

static const uint64_t P9N2_PERV_EP05_RECOV_INTERRUPT_REG                           = 0x150F001Bull;

static const uint64_t P9N2_PERV_EC00_RECOV_INTERRUPT_REG                           = 0x200F001Bull;

static const uint64_t P9N2_PERV_EC01_RECOV_INTERRUPT_REG                           = 0x210F001Bull;

static const uint64_t P9N2_PERV_EC02_RECOV_INTERRUPT_REG                           = 0x220F001Bull;

static const uint64_t P9N2_PERV_EC03_RECOV_INTERRUPT_REG                           = 0x230F001Bull;

static const uint64_t P9N2_PERV_EC04_RECOV_INTERRUPT_REG                           = 0x240F001Bull;

static const uint64_t P9N2_PERV_EC05_RECOV_INTERRUPT_REG                           = 0x250F001Bull;

static const uint64_t P9N2_PERV_EC06_RECOV_INTERRUPT_REG                           = 0x260F001Bull;

static const uint64_t P9N2_PERV_EC07_RECOV_INTERRUPT_REG                           = 0x270F001Bull;

static const uint64_t P9N2_PERV_EC08_RECOV_INTERRUPT_REG                           = 0x280F001Bull;

static const uint64_t P9N2_PERV_EC09_RECOV_INTERRUPT_REG                           = 0x290F001Bull;

static const uint64_t P9N2_PERV_EC10_RECOV_INTERRUPT_REG                           = 0x2A0F001Bull;

static const uint64_t P9N2_PERV_EC11_RECOV_INTERRUPT_REG                           = 0x2B0F001Bull;

static const uint64_t P9N2_PERV_EC12_RECOV_INTERRUPT_REG                           = 0x2C0F001Bull;

static const uint64_t P9N2_PERV_EC13_RECOV_INTERRUPT_REG                           = 0x2D0F001Bull;

static const uint64_t P9N2_PERV_EC14_RECOV_INTERRUPT_REG                           = 0x2E0F001Bull;

static const uint64_t P9N2_PERV_EC15_RECOV_INTERRUPT_REG                           = 0x2F0F001Bull;

static const uint64_t P9N2_PERV_EC16_RECOV_INTERRUPT_REG                           = 0x300F001Bull;

static const uint64_t P9N2_PERV_EC17_RECOV_INTERRUPT_REG                           = 0x310F001Bull;

static const uint64_t P9N2_PERV_EC18_RECOV_INTERRUPT_REG                           = 0x320F001Bull;

static const uint64_t P9N2_PERV_EC19_RECOV_INTERRUPT_REG                           = 0x330F001Bull;

static const uint64_t P9N2_PERV_EC20_RECOV_INTERRUPT_REG                           = 0x340F001Bull;

static const uint64_t P9N2_PERV_EC21_RECOV_INTERRUPT_REG                           = 0x350F001Bull;

static const uint64_t P9N2_PERV_EC22_RECOV_INTERRUPT_REG                           = 0x360F001Bull;

static const uint64_t P9N2_PERV_EC23_RECOV_INTERRUPT_REG                           = 0x370F001Bull;


static const uint64_t P9N2_PERV_REC_ACK_REG                                        = 0x000F0010ull;

static const uint64_t P9N2_PERV_PIB_REC_ACK_REG                                    = 0x000F0010ull;


static const uint64_t P9N2_PERV_REC_ERR_REG0                                       = 0x000F0011ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_REC_ERR_REG0                                   = 0x000F0011ull;


static const uint64_t P9N2_PERV_REC_ERR_REG1                                       = 0x000F0012ull;

static const uint64_t P9N2_PERV_PIB_REC_ERR_REG1                                   = 0x000F0012ull;


static const uint64_t P9N2_PERV_REC_ERR_REG2                                       = 0x000F0013ull;

static const uint64_t P9N2_PERV_PIB_REC_ERR_REG2                                   = 0x000F0013ull;


static const uint64_t P9N2_PERV_REC_ERR_REG3                                       = 0x000F0014ull;

static const uint64_t P9N2_PERV_PIB_REC_ERR_REG3                                   = 0x000F0014ull;


static const uint64_t P9N2_PERV_RESET                                              = 0x00030004ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_RESET                                          = 0x00030004ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_RESET                                   = 0x00020004ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_RESET                                   = 0x00020014ull;

static const uint32_t P9N2_PERV_FSI2PIB_RESET_FSI                                  = 0x00001006ull;

static const uint32_t P9N2_PERV_FSI2PIB_RESET_FSI_BYTE                             = 0x00001018ull;

static const uint32_t P9N2_PERV_FSISHIFT_RESET_FSI                                 = 0x00000C06ull;

static const uint32_t P9N2_PERV_FSISHIFT_RESET_FSI_BYTE                            = 0x00000C18ull;

static const uint64_t P9N2_PERV_PIB2OPB0_RESET                                     = 0x00020004ull;

static const uint64_t P9N2_PERV_PIB2OPB1_RESET                                     = 0x00020014ull;


static const uint32_t P9N2_PERV_FSISHIFT_RESET_ERRORS_FSI                          = 0x00000C07ull;

static const uint32_t P9N2_PERV_FSISHIFT_RESET_ERRORS_FSI_BYTE                     = 0x00000C1Cull;


static const uint64_t P9N2_PERV_RESET_REG                                          = 0x000F001Dull;

static const uint64_t P9N2_PERV_PIB_RESET_REG                                      = 0x000F001Dull;


static const uint64_t P9N2_PERV_0_FSII2C_RESIDUAL_FRONT_END_BACK_END_LENGTH_A      = 0x00001809ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSII2C_RESIDUAL_FRONT_END_BACK_END_LENGTH_A        = 0x00001809ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PERV_RFIR                                               = 0x00040001ull;

static const uint64_t P9N2_PERV_TP_RFIR                                            = 0x01040001ull;

static const uint64_t P9N2_PERV_N0_RFIR                                            = 0x02040001ull;

static const uint64_t P9N2_PERV_N1_RFIR                                            = 0x03040001ull;

static const uint64_t P9N2_PERV_N2_RFIR                                            = 0x04040001ull;

static const uint64_t P9N2_PERV_N3_RFIR                                            = 0x05040001ull;

static const uint64_t P9N2_PERV_XB_RFIR                                            = 0x06040001ull;

static const uint64_t P9N2_PERV_MC01_RFIR                                          = 0x07040001ull;

static const uint64_t P9N2_PERV_MC23_RFIR                                          = 0x08040001ull;

static const uint64_t P9N2_PERV_OB0_RFIR                                           = 0x09040001ull;

static const uint64_t P9N2_PERV_OB3_RFIR                                           = 0x0C040001ull;

static const uint64_t P9N2_PERV_PCI0_RFIR                                          = 0x0D040001ull;

static const uint64_t P9N2_PERV_PCI1_RFIR                                          = 0x0E040001ull;

static const uint64_t P9N2_PERV_PCI2_RFIR                                          = 0x0F040001ull;

static const uint64_t P9N2_PERV_EP00_RFIR                                          = 0x10040001ull;

static const uint64_t P9N2_PERV_EP01_RFIR                                          = 0x11040001ull;

static const uint64_t P9N2_PERV_EP02_RFIR                                          = 0x12040001ull;

static const uint64_t P9N2_PERV_EP03_RFIR                                          = 0x13040001ull;

static const uint64_t P9N2_PERV_EP04_RFIR                                          = 0x14040001ull;

static const uint64_t P9N2_PERV_EP05_RFIR                                          = 0x15040001ull;

static const uint64_t P9N2_PERV_EC00_RFIR                                          = 0x20040001ull;

static const uint64_t P9N2_PERV_EC01_RFIR                                          = 0x21040001ull;

static const uint64_t P9N2_PERV_EC02_RFIR                                          = 0x22040001ull;

static const uint64_t P9N2_PERV_EC03_RFIR                                          = 0x23040001ull;

static const uint64_t P9N2_PERV_EC04_RFIR                                          = 0x24040001ull;

static const uint64_t P9N2_PERV_EC05_RFIR                                          = 0x25040001ull;

static const uint64_t P9N2_PERV_EC06_RFIR                                          = 0x26040001ull;

static const uint64_t P9N2_PERV_EC07_RFIR                                          = 0x27040001ull;

static const uint64_t P9N2_PERV_EC08_RFIR                                          = 0x28040001ull;

static const uint64_t P9N2_PERV_EC09_RFIR                                          = 0x29040001ull;

static const uint64_t P9N2_PERV_EC10_RFIR                                          = 0x2A040001ull;

static const uint64_t P9N2_PERV_EC11_RFIR                                          = 0x2B040001ull;

static const uint64_t P9N2_PERV_EC12_RFIR                                          = 0x2C040001ull;

static const uint64_t P9N2_PERV_EC13_RFIR                                          = 0x2D040001ull;

static const uint64_t P9N2_PERV_EC14_RFIR                                          = 0x2E040001ull;

static const uint64_t P9N2_PERV_EC15_RFIR                                          = 0x2F040001ull;

static const uint64_t P9N2_PERV_EC16_RFIR                                          = 0x30040001ull;

static const uint64_t P9N2_PERV_EC17_RFIR                                          = 0x31040001ull;

static const uint64_t P9N2_PERV_EC18_RFIR                                          = 0x32040001ull;

static const uint64_t P9N2_PERV_EC19_RFIR                                          = 0x33040001ull;

static const uint64_t P9N2_PERV_EC20_RFIR                                          = 0x34040001ull;

static const uint64_t P9N2_PERV_EC21_RFIR                                          = 0x35040001ull;

static const uint64_t P9N2_PERV_EC22_RFIR                                          = 0x36040001ull;

static const uint64_t P9N2_PERV_EC23_RFIR                                          = 0x37040001ull;


static const uint64_t P9N2_PERV_RING_FENCE_MASK_LATCH_REG                          = 0x00010008ull;

static const uint64_t P9N2_PERV_TP_RING_FENCE_MASK_LATCH_REG                       = 0x01010008ull;


static const uint32_t P9N2_PERV_ROOT_CTRL0_FSI                                     = 0x00002810ull;

static const uint32_t P9N2_PERV_ROOT_CTRL0_FSI_BYTE                                = 0x00002840ull;

static const uint64_t P9N2_PERV_ROOT_CTRL0_SCOM                                    = 0x00050010ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL0                                     = 0x00050010ull;


static const uint32_t P9N2_PERV_ROOT_CTRL0_CLEAR_FSI                               = 0x00002930ull;

static const uint32_t P9N2_PERV_ROOT_CTRL0_CLEAR_FSI_BYTE                          = 0x00002CC0ull;

static const uint64_t P9N2_PERV_ROOT_CTRL0_CLEAR_SCOM                              = 0x00050130ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL0_CLEAR                               = 0x00050130ull;


static const uint32_t P9N2_PERV_ROOT_CTRL0_COPY_FSI                                = 0x00002910ull;

static const uint32_t P9N2_PERV_ROOT_CTRL0_COPY_FSI_BYTE                           = 0x00002C40ull;

static const uint64_t P9N2_PERV_ROOT_CTRL0_COPY_SCOM                               = 0x00050110ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL0_COPY                                = 0x00050110ull;


static const uint32_t P9N2_PERV_ROOT_CTRL0_SET_FSI                                 = 0x00002920ull;

static const uint32_t P9N2_PERV_ROOT_CTRL0_SET_FSI_BYTE                            = 0x00002C80ull;

static const uint64_t P9N2_PERV_ROOT_CTRL0_SET_SCOM                                = 0x00050120ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL0_SET                                 = 0x00050120ull;


static const uint32_t P9N2_PERV_ROOT_CTRL1_FSI                                     = 0x00002811ull;

static const uint32_t P9N2_PERV_ROOT_CTRL1_FSI_BYTE                                = 0x00002844ull;

static const uint64_t P9N2_PERV_ROOT_CTRL1_SCOM                                    = 0x00050011ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_ROOT_CTRL1                                     = 0x00050011ull;


static const uint32_t P9N2_PERV_ROOT_CTRL1_CLEAR_FSI                               = 0x00002931ull;

static const uint32_t P9N2_PERV_ROOT_CTRL1_CLEAR_FSI_BYTE                          = 0x00002CC4ull;

static const uint64_t P9N2_PERV_ROOT_CTRL1_CLEAR_SCOM                              = 0x00050131ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL1_CLEAR                               = 0x00050131ull;


static const uint32_t P9N2_PERV_ROOT_CTRL1_COPY_FSI                                = 0x00002911ull;

static const uint32_t P9N2_PERV_ROOT_CTRL1_COPY_FSI_BYTE                           = 0x00002C44ull;

static const uint64_t P9N2_PERV_ROOT_CTRL1_COPY_SCOM                               = 0x00050111ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL1_COPY                                = 0x00050111ull;


static const uint32_t P9N2_PERV_ROOT_CTRL1_SET_FSI                                 = 0x00002921ull;

static const uint32_t P9N2_PERV_ROOT_CTRL1_SET_FSI_BYTE                            = 0x00002C84ull;

static const uint64_t P9N2_PERV_ROOT_CTRL1_SET_SCOM                                = 0x00050121ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL1_SET                                 = 0x00050121ull;


static const uint32_t P9N2_PERV_ROOT_CTRL2_FSI                                     = 0x00002812ull;

static const uint32_t P9N2_PERV_ROOT_CTRL2_FSI_BYTE                                = 0x00002848ull;

static const uint64_t P9N2_PERV_ROOT_CTRL2_SCOM                                    = 0x00050012ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_ROOT_CTRL2                                     = 0x00050012ull;


static const uint32_t P9N2_PERV_ROOT_CTRL2_CLEAR_FSI                               = 0x00002932ull;

static const uint32_t P9N2_PERV_ROOT_CTRL2_CLEAR_FSI_BYTE                          = 0x00002CC8ull;

static const uint64_t P9N2_PERV_ROOT_CTRL2_CLEAR_SCOM                              = 0x00050132ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL2_CLEAR                               = 0x00050132ull;


static const uint32_t P9N2_PERV_ROOT_CTRL2_COPY_FSI                                = 0x00002912ull;

static const uint32_t P9N2_PERV_ROOT_CTRL2_COPY_FSI_BYTE                           = 0x00002C48ull;

static const uint64_t P9N2_PERV_ROOT_CTRL2_COPY_SCOM                               = 0x00050112ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL2_COPY                                = 0x00050112ull;


static const uint32_t P9N2_PERV_ROOT_CTRL2_SET_FSI                                 = 0x00002922ull;

static const uint32_t P9N2_PERV_ROOT_CTRL2_SET_FSI_BYTE                            = 0x00002C88ull;

static const uint64_t P9N2_PERV_ROOT_CTRL2_SET_SCOM                                = 0x00050122ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL2_SET                                 = 0x00050122ull;


static const uint32_t P9N2_PERV_ROOT_CTRL3_FSI                                     = 0x00002813ull;

static const uint32_t P9N2_PERV_ROOT_CTRL3_FSI_BYTE                                = 0x0000284Cull;

static const uint64_t P9N2_PERV_ROOT_CTRL3_SCOM                                    = 0x00050013ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL3                                     = 0x00050013ull;


static const uint32_t P9N2_PERV_ROOT_CTRL3_CLEAR_FSI                               = 0x00002933ull;

static const uint32_t P9N2_PERV_ROOT_CTRL3_CLEAR_FSI_BYTE                          = 0x00002CCCull;

static const uint64_t P9N2_PERV_ROOT_CTRL3_CLEAR_SCOM                              = 0x00050133ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL3_CLEAR                               = 0x00050133ull;


static const uint32_t P9N2_PERV_ROOT_CTRL3_COPY_FSI                                = 0x00002913ull;

static const uint32_t P9N2_PERV_ROOT_CTRL3_COPY_FSI_BYTE                           = 0x00002C4Cull;

static const uint64_t P9N2_PERV_ROOT_CTRL3_COPY_SCOM                               = 0x00050113ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL3_COPY                                = 0x00050113ull;


static const uint32_t P9N2_PERV_ROOT_CTRL3_SET_FSI                                 = 0x00002923ull;

static const uint32_t P9N2_PERV_ROOT_CTRL3_SET_FSI_BYTE                            = 0x00002C8Cull;

static const uint64_t P9N2_PERV_ROOT_CTRL3_SET_SCOM                                = 0x00050123ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL3_SET                                 = 0x00050123ull;


static const uint32_t P9N2_PERV_ROOT_CTRL4_FSI                                     = 0x00002814ull;

static const uint32_t P9N2_PERV_ROOT_CTRL4_FSI_BYTE                                = 0x00002850ull;

static const uint64_t P9N2_PERV_ROOT_CTRL4_SCOM                                    = 0x00050014ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL4                                     = 0x00050014ull;


static const uint32_t P9N2_PERV_ROOT_CTRL4_CLEAR_FSI                               = 0x00002934ull;

static const uint32_t P9N2_PERV_ROOT_CTRL4_CLEAR_FSI_BYTE                          = 0x00002CD0ull;

static const uint64_t P9N2_PERV_ROOT_CTRL4_CLEAR_SCOM                              = 0x00050134ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL4_CLEAR                               = 0x00050134ull;


static const uint32_t P9N2_PERV_ROOT_CTRL4_COPY_FSI                                = 0x00002914ull;

static const uint32_t P9N2_PERV_ROOT_CTRL4_COPY_FSI_BYTE                           = 0x00002C50ull;

static const uint64_t P9N2_PERV_ROOT_CTRL4_COPY_SCOM                               = 0x00050114ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL4_COPY                                = 0x00050114ull;


static const uint32_t P9N2_PERV_ROOT_CTRL4_SET_FSI                                 = 0x00002924ull;

static const uint32_t P9N2_PERV_ROOT_CTRL4_SET_FSI_BYTE                            = 0x00002C90ull;

static const uint64_t P9N2_PERV_ROOT_CTRL4_SET_SCOM                                = 0x00050124ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL4_SET                                 = 0x00050124ull;


static const uint32_t P9N2_PERV_ROOT_CTRL5_FSI                                     = 0x00002815ull;

static const uint32_t P9N2_PERV_ROOT_CTRL5_FSI_BYTE                                = 0x00002854ull;

static const uint64_t P9N2_PERV_ROOT_CTRL5_SCOM                                    = 0x00050015ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL5                                     = 0x00050015ull;


static const uint32_t P9N2_PERV_ROOT_CTRL5_CLEAR_FSI                               = 0x00002935ull;

static const uint32_t P9N2_PERV_ROOT_CTRL5_CLEAR_FSI_BYTE                          = 0x00002CD4ull;

static const uint64_t P9N2_PERV_ROOT_CTRL5_CLEAR_SCOM                              = 0x00050135ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL5_CLEAR                               = 0x00050135ull;


static const uint32_t P9N2_PERV_ROOT_CTRL5_COPY_FSI                                = 0x00002915ull;

static const uint32_t P9N2_PERV_ROOT_CTRL5_COPY_FSI_BYTE                           = 0x00002C54ull;

static const uint64_t P9N2_PERV_ROOT_CTRL5_COPY_SCOM                               = 0x00050115ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL5_COPY                                = 0x00050115ull;


static const uint32_t P9N2_PERV_ROOT_CTRL5_SET_FSI                                 = 0x00002925ull;

static const uint32_t P9N2_PERV_ROOT_CTRL5_SET_FSI_BYTE                            = 0x00002C94ull;

static const uint64_t P9N2_PERV_ROOT_CTRL5_SET_SCOM                                = 0x00050125ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL5_SET                                 = 0x00050125ull;


static const uint32_t P9N2_PERV_ROOT_CTRL6_FSI                                     = 0x00002816ull;

static const uint32_t P9N2_PERV_ROOT_CTRL6_FSI_BYTE                                = 0x00002858ull;

static const uint64_t P9N2_PERV_ROOT_CTRL6_SCOM                                    = 0x00050016ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL6                                     = 0x00050016ull;


static const uint32_t P9N2_PERV_ROOT_CTRL6_CLEAR_FSI                               = 0x00002936ull;

static const uint32_t P9N2_PERV_ROOT_CTRL6_CLEAR_FSI_BYTE                          = 0x00002CD8ull;

static const uint64_t P9N2_PERV_ROOT_CTRL6_CLEAR_SCOM                              = 0x00050136ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL6_CLEAR                               = 0x00050136ull;


static const uint32_t P9N2_PERV_ROOT_CTRL6_COPY_FSI                                = 0x00002916ull;

static const uint32_t P9N2_PERV_ROOT_CTRL6_COPY_FSI_BYTE                           = 0x00002C58ull;

static const uint64_t P9N2_PERV_ROOT_CTRL6_COPY_SCOM                               = 0x00050116ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL6_COPY                                = 0x00050116ull;


static const uint32_t P9N2_PERV_ROOT_CTRL6_SET_FSI                                 = 0x00002926ull;

static const uint32_t P9N2_PERV_ROOT_CTRL6_SET_FSI_BYTE                            = 0x00002C98ull;

static const uint64_t P9N2_PERV_ROOT_CTRL6_SET_SCOM                                = 0x00050126ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL6_SET                                 = 0x00050126ull;


static const uint32_t P9N2_PERV_ROOT_CTRL7_FSI                                     = 0x00002817ull;

static const uint32_t P9N2_PERV_ROOT_CTRL7_FSI_BYTE                                = 0x0000285Cull;

static const uint64_t P9N2_PERV_ROOT_CTRL7_SCOM                                    = 0x00050017ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL7                                     = 0x00050017ull;


static const uint32_t P9N2_PERV_ROOT_CTRL7_CLEAR_FSI                               = 0x00002937ull;

static const uint32_t P9N2_PERV_ROOT_CTRL7_CLEAR_FSI_BYTE                          = 0x00002CDCull;

static const uint64_t P9N2_PERV_ROOT_CTRL7_CLEAR_SCOM                              = 0x00050137ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL7_CLEAR                               = 0x00050137ull;


static const uint32_t P9N2_PERV_ROOT_CTRL7_COPY_FSI                                = 0x00002917ull;

static const uint32_t P9N2_PERV_ROOT_CTRL7_COPY_FSI_BYTE                           = 0x00002C5Cull;

static const uint64_t P9N2_PERV_ROOT_CTRL7_COPY_SCOM                               = 0x00050117ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL7_COPY                                = 0x00050117ull;


static const uint32_t P9N2_PERV_ROOT_CTRL7_SET_FSI                                 = 0x00002927ull;

static const uint32_t P9N2_PERV_ROOT_CTRL7_SET_FSI_BYTE                            = 0x00002C9Cull;

static const uint64_t P9N2_PERV_ROOT_CTRL7_SET_SCOM                                = 0x00050127ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL7_SET                                 = 0x00050127ull;


static const uint32_t P9N2_PERV_ROOT_CTRL8_FSI                                     = 0x00002818ull;

static const uint32_t P9N2_PERV_ROOT_CTRL8_FSI_BYTE                                = 0x00002860ull;

static const uint64_t P9N2_PERV_ROOT_CTRL8_SCOM                                    = 0x00050018ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL8                                     = 0x00050018ull;


static const uint32_t P9N2_PERV_ROOT_CTRL8_CLEAR_FSI                               = 0x00002938ull;

static const uint32_t P9N2_PERV_ROOT_CTRL8_CLEAR_FSI_BYTE                          = 0x00002CE0ull;

static const uint64_t P9N2_PERV_ROOT_CTRL8_CLEAR_SCOM                              = 0x00050138ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL8_CLEAR                               = 0x00050138ull;


static const uint32_t P9N2_PERV_ROOT_CTRL8_COPY_FSI                                = 0x00002918ull;

static const uint32_t P9N2_PERV_ROOT_CTRL8_COPY_FSI_BYTE                           = 0x00002C60ull;

static const uint64_t P9N2_PERV_ROOT_CTRL8_COPY_SCOM                               = 0x00050118ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL8_COPY                                = 0x00050118ull;


static const uint32_t P9N2_PERV_ROOT_CTRL8_SET_FSI                                 = 0x00002928ull;

static const uint32_t P9N2_PERV_ROOT_CTRL8_SET_FSI_BYTE                            = 0x00002CA0ull;

static const uint64_t P9N2_PERV_ROOT_CTRL8_SET_SCOM                                = 0x00050128ull;

static const uint64_t P9N2_PERV_PIB_ROOT_CTRL8_SET                                 = 0x00050128ull;


static const uint64_t P9N2_PERV_RSIC                                               = 0x00030008ull;

static const uint64_t P9N2_PERV_PIB_RSIC                                           = 0x00030008ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_RSIC                                    = 0x00020008ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_RSIC                                    = 0x00020018ull;

static const uint64_t P9N2_PERV_PIB2OPB0_RSIC                                      = 0x00020008ull;

static const uint64_t P9N2_PERV_PIB2OPB1_RSIC                                      = 0x00020018ull;


static const uint64_t P9N2_PERV_RSIM                                               = 0x00030009ull;

static const uint64_t P9N2_PERV_PIB_RSIM                                           = 0x00030009ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_RSIM                                    = 0x00020009ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_RSIM                                    = 0x00020019ull;

static const uint64_t P9N2_PERV_PIB2OPB0_RSIM                                      = 0x00020009ull;

static const uint64_t P9N2_PERV_PIB2OPB1_RSIM                                      = 0x00020019ull;


static const uint64_t P9N2_PERV_RSIS                                               = 0x0003000Aull;

static const uint64_t P9N2_PERV_PIB_RSIS                                           = 0x0003000Aull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_RSIS                                    = 0x0002000Aull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_RSIS                                    = 0x0002001Aull;

static const uint64_t P9N2_PERV_PIB2OPB0_RSIS                                      = 0x0002000Aull;

static const uint64_t P9N2_PERV_PIB2OPB1_RSIS                                      = 0x0002001Aull;


static const uint64_t P9N2_PERV_SBE_LCL_DBG_PPE                                    = 0x00000120ull;


static const uint64_t P9N2_PERV_SBE_LCL_EIMR_PPE                                   = 0x00000020ull;

static const uint64_t P9N2_PERV_SBE_LCL_EIMR_PPE1                                  = 0x00000030ull;

static const uint64_t P9N2_PERV_SBE_LCL_EIMR_PPE2                                  = 0x00000038ull;


static const uint64_t P9N2_PERV_SBE_LCL_EINR_PPE                                   = 0x000000A0ull;


static const uint64_t P9N2_PERV_SBE_LCL_EIPR_PPE                                   = 0x00000040ull;

static const uint64_t P9N2_PERV_SBE_LCL_EIPR_PPE1                                  = 0x00000050ull;

static const uint64_t P9N2_PERV_SBE_LCL_EIPR_PPE2                                  = 0x00000058ull;


static const uint64_t P9N2_PERV_SBE_LCL_EISR_PPE                                   = 0x00000000ull;

static const uint64_t P9N2_PERV_SBE_LCL_EISR_PPE1                                  = 0x00000010ull;

static const uint64_t P9N2_PERV_SBE_LCL_EISR_PPE2                                  = 0x00000018ull;


static const uint64_t P9N2_PERV_SBE_LCL_EISTR_PPE                                  = 0x00000080ull;


static const uint64_t P9N2_PERV_SBE_LCL_EITR_PPE                                   = 0x00000060ull;

static const uint64_t P9N2_PERV_SBE_LCL_EITR_PPE1                                  = 0x00000070ull;

static const uint64_t P9N2_PERV_SBE_LCL_EITR_PPE2                                  = 0x00000078ull;


static const uint64_t P9N2_PERV_SBE_LCL_IVPR_PPE                                   = 0x00000160ull;


static const uint64_t P9N2_PERV_SBE_LCL_TBR_PPE                                    = 0x00000140ull;


static const uint64_t P9N2_PERV_SBE_LCL_TSEL_PPE                                   = 0x00000100ull;


static const uint32_t P9N2_PERV_SB_CS_FSI                                          = 0x00002808ull;

static const uint32_t P9N2_PERV_SB_CS_FSI_BYTE                                     = 0x00002820ull;

static const uint64_t P9N2_PERV_SB_CS_SCOM                                         = 0x00050008ull;

static const uint64_t P9N2_PERV_PIB_SB_CS                                          = 0x00050008ull;


static const uint32_t P9N2_PERV_SB_MSG_FSI                                         = 0x00002809ull;

static const uint32_t P9N2_PERV_SB_MSG_FSI_BYTE                                    = 0x00002824ull;

static const uint64_t P9N2_PERV_SB_MSG_SCOM                                        = 0x00050009ull;

static const uint64_t P9N2_PERV_PIB_SB_MSG                                         = 0x00050009ull;


static const uint64_t P9N2_PERV_SCAN32                                             = 0x00038000ull;

static const uint64_t P9N2_PERV_TP_SCAN32                                          = 0x01038000ull;

static const uint64_t P9N2_PERV_N0_SCAN32                                          = 0x02038000ull;

static const uint64_t P9N2_PERV_N1_SCAN32                                          = 0x03038000ull;

static const uint64_t P9N2_PERV_N2_SCAN32                                          = 0x04038000ull;

static const uint64_t P9N2_PERV_N3_SCAN32                                          = 0x05038000ull;

static const uint64_t P9N2_PERV_XB_SCAN32                                          = 0x06038000ull;

static const uint64_t P9N2_PERV_MC01_SCAN32                                        = 0x07038000ull;

static const uint64_t P9N2_PERV_MC23_SCAN32                                        = 0x08038000ull;

static const uint64_t P9N2_PERV_OB0_SCAN32                                         = 0x09038000ull;

static const uint64_t P9N2_PERV_OB3_SCAN32                                         = 0x0C038000ull;

static const uint64_t P9N2_PERV_PCI0_SCAN32                                        = 0x0D038000ull;

static const uint64_t P9N2_PERV_PCI1_SCAN32                                        = 0x0E038000ull;

static const uint64_t P9N2_PERV_PCI2_SCAN32                                        = 0x0F038000ull;

static const uint64_t P9N2_PERV_EP00_SCAN32                                        = 0x10038000ull;

static const uint64_t P9N2_PERV_EP01_SCAN32                                        = 0x11038000ull;

static const uint64_t P9N2_PERV_EP02_SCAN32                                        = 0x12038000ull;

static const uint64_t P9N2_PERV_EP03_SCAN32                                        = 0x13038000ull;

static const uint64_t P9N2_PERV_EP04_SCAN32                                        = 0x14038000ull;

static const uint64_t P9N2_PERV_EP05_SCAN32                                        = 0x15038000ull;

static const uint64_t P9N2_PERV_EC00_SCAN32                                        = 0x20038000ull;

static const uint64_t P9N2_PERV_EC01_SCAN32                                        = 0x21038000ull;

static const uint64_t P9N2_PERV_EC02_SCAN32                                        = 0x22038000ull;

static const uint64_t P9N2_PERV_EC03_SCAN32                                        = 0x23038000ull;

static const uint64_t P9N2_PERV_EC04_SCAN32                                        = 0x24038000ull;

static const uint64_t P9N2_PERV_EC05_SCAN32                                        = 0x25038000ull;

static const uint64_t P9N2_PERV_EC06_SCAN32                                        = 0x26038000ull;

static const uint64_t P9N2_PERV_EC07_SCAN32                                        = 0x27038000ull;

static const uint64_t P9N2_PERV_EC08_SCAN32                                        = 0x28038000ull;

static const uint64_t P9N2_PERV_EC09_SCAN32                                        = 0x29038000ull;

static const uint64_t P9N2_PERV_EC10_SCAN32                                        = 0x2A038000ull;

static const uint64_t P9N2_PERV_EC11_SCAN32                                        = 0x2B038000ull;

static const uint64_t P9N2_PERV_EC12_SCAN32                                        = 0x2C038000ull;

static const uint64_t P9N2_PERV_EC13_SCAN32                                        = 0x2D038000ull;

static const uint64_t P9N2_PERV_EC14_SCAN32                                        = 0x2E038000ull;

static const uint64_t P9N2_PERV_EC15_SCAN32                                        = 0x2F038000ull;

static const uint64_t P9N2_PERV_EC16_SCAN32                                        = 0x30038000ull;

static const uint64_t P9N2_PERV_EC17_SCAN32                                        = 0x31038000ull;

static const uint64_t P9N2_PERV_EC18_SCAN32                                        = 0x32038000ull;

static const uint64_t P9N2_PERV_EC19_SCAN32                                        = 0x33038000ull;

static const uint64_t P9N2_PERV_EC20_SCAN32                                        = 0x34038000ull;

static const uint64_t P9N2_PERV_EC21_SCAN32                                        = 0x35038000ull;

static const uint64_t P9N2_PERV_EC22_SCAN32                                        = 0x36038000ull;

static const uint64_t P9N2_PERV_EC23_SCAN32                                        = 0x37038000ull;


static const uint64_t P9N2_PERV_SCAN64                                             = 0x0003E000ull;

static const uint64_t P9N2_PERV_TP_SCAN64                                          = 0x0103E000ull;

static const uint64_t P9N2_PERV_N0_SCAN64                                          = 0x0203E000ull;

static const uint64_t P9N2_PERV_N1_SCAN64                                          = 0x0303E000ull;

static const uint64_t P9N2_PERV_N2_SCAN64                                          = 0x0403E000ull;

static const uint64_t P9N2_PERV_N3_SCAN64                                          = 0x0503E000ull;

static const uint64_t P9N2_PERV_XB_SCAN64                                          = 0x0603E000ull;

static const uint64_t P9N2_PERV_MC01_SCAN64                                        = 0x0703E000ull;

static const uint64_t P9N2_PERV_MC23_SCAN64                                        = 0x0803E000ull;

static const uint64_t P9N2_PERV_OB0_SCAN64                                         = 0x0903E000ull;

static const uint64_t P9N2_PERV_OB3_SCAN64                                         = 0x0C03E000ull;

static const uint64_t P9N2_PERV_PCI0_SCAN64                                        = 0x0D03E000ull;

static const uint64_t P9N2_PERV_PCI1_SCAN64                                        = 0x0E03E000ull;

static const uint64_t P9N2_PERV_PCI2_SCAN64                                        = 0x0F03E000ull;

static const uint64_t P9N2_PERV_EP00_SCAN64                                        = 0x1003E000ull;

static const uint64_t P9N2_PERV_EP01_SCAN64                                        = 0x1103E000ull;

static const uint64_t P9N2_PERV_EP02_SCAN64                                        = 0x1203E000ull;

static const uint64_t P9N2_PERV_EP03_SCAN64                                        = 0x1303E000ull;

static const uint64_t P9N2_PERV_EP04_SCAN64                                        = 0x1403E000ull;

static const uint64_t P9N2_PERV_EP05_SCAN64                                        = 0x1503E000ull;

static const uint64_t P9N2_PERV_EC00_SCAN64                                        = 0x2003E000ull;

static const uint64_t P9N2_PERV_EC01_SCAN64                                        = 0x2103E000ull;

static const uint64_t P9N2_PERV_EC02_SCAN64                                        = 0x2203E000ull;

static const uint64_t P9N2_PERV_EC03_SCAN64                                        = 0x2303E000ull;

static const uint64_t P9N2_PERV_EC04_SCAN64                                        = 0x2403E000ull;

static const uint64_t P9N2_PERV_EC05_SCAN64                                        = 0x2503E000ull;

static const uint64_t P9N2_PERV_EC06_SCAN64                                        = 0x2603E000ull;

static const uint64_t P9N2_PERV_EC07_SCAN64                                        = 0x2703E000ull;

static const uint64_t P9N2_PERV_EC08_SCAN64                                        = 0x2803E000ull;

static const uint64_t P9N2_PERV_EC09_SCAN64                                        = 0x2903E000ull;

static const uint64_t P9N2_PERV_EC10_SCAN64                                        = 0x2A03E000ull;

static const uint64_t P9N2_PERV_EC11_SCAN64                                        = 0x2B03E000ull;

static const uint64_t P9N2_PERV_EC12_SCAN64                                        = 0x2C03E000ull;

static const uint64_t P9N2_PERV_EC13_SCAN64                                        = 0x2D03E000ull;

static const uint64_t P9N2_PERV_EC14_SCAN64                                        = 0x2E03E000ull;

static const uint64_t P9N2_PERV_EC15_SCAN64                                        = 0x2F03E000ull;

static const uint64_t P9N2_PERV_EC16_SCAN64                                        = 0x3003E000ull;

static const uint64_t P9N2_PERV_EC17_SCAN64                                        = 0x3103E000ull;

static const uint64_t P9N2_PERV_EC18_SCAN64                                        = 0x3203E000ull;

static const uint64_t P9N2_PERV_EC19_SCAN64                                        = 0x3303E000ull;

static const uint64_t P9N2_PERV_EC20_SCAN64                                        = 0x3403E000ull;

static const uint64_t P9N2_PERV_EC21_SCAN64                                        = 0x3503E000ull;

static const uint64_t P9N2_PERV_EC22_SCAN64                                        = 0x3603E000ull;

static const uint64_t P9N2_PERV_EC23_SCAN64                                        = 0x3703E000ull;


static const uint64_t P9N2_PERV_SCAN_CAPTUREDR                                     = 0x0003C000ull;

static const uint64_t P9N2_PERV_TP_SCAN_CAPTUREDR                                  = 0x0103C000ull;

static const uint64_t P9N2_PERV_N0_SCAN_CAPTUREDR                                  = 0x0203C000ull;

static const uint64_t P9N2_PERV_N1_SCAN_CAPTUREDR                                  = 0x0303C000ull;

static const uint64_t P9N2_PERV_N2_SCAN_CAPTUREDR                                  = 0x0403C000ull;

static const uint64_t P9N2_PERV_N3_SCAN_CAPTUREDR                                  = 0x0503C000ull;

static const uint64_t P9N2_PERV_XB_SCAN_CAPTUREDR                                  = 0x0603C000ull;

static const uint64_t P9N2_PERV_MC01_SCAN_CAPTUREDR                                = 0x0703C000ull;

static const uint64_t P9N2_PERV_MC23_SCAN_CAPTUREDR                                = 0x0803C000ull;

static const uint64_t P9N2_PERV_OB0_SCAN_CAPTUREDR                                 = 0x0903C000ull;

static const uint64_t P9N2_PERV_OB3_SCAN_CAPTUREDR                                 = 0x0C03C000ull;

static const uint64_t P9N2_PERV_PCI0_SCAN_CAPTUREDR                                = 0x0D03C000ull;

static const uint64_t P9N2_PERV_PCI1_SCAN_CAPTUREDR                                = 0x0E03C000ull;

static const uint64_t P9N2_PERV_PCI2_SCAN_CAPTUREDR                                = 0x0F03C000ull;

static const uint64_t P9N2_PERV_EP00_SCAN_CAPTUREDR                                = 0x1003C000ull;

static const uint64_t P9N2_PERV_EP01_SCAN_CAPTUREDR                                = 0x1103C000ull;

static const uint64_t P9N2_PERV_EP02_SCAN_CAPTUREDR                                = 0x1203C000ull;

static const uint64_t P9N2_PERV_EP03_SCAN_CAPTUREDR                                = 0x1303C000ull;

static const uint64_t P9N2_PERV_EP04_SCAN_CAPTUREDR                                = 0x1403C000ull;

static const uint64_t P9N2_PERV_EP05_SCAN_CAPTUREDR                                = 0x1503C000ull;

static const uint64_t P9N2_PERV_EC00_SCAN_CAPTUREDR                                = 0x2003C000ull;

static const uint64_t P9N2_PERV_EC01_SCAN_CAPTUREDR                                = 0x2103C000ull;

static const uint64_t P9N2_PERV_EC02_SCAN_CAPTUREDR                                = 0x2203C000ull;

static const uint64_t P9N2_PERV_EC03_SCAN_CAPTUREDR                                = 0x2303C000ull;

static const uint64_t P9N2_PERV_EC04_SCAN_CAPTUREDR                                = 0x2403C000ull;

static const uint64_t P9N2_PERV_EC05_SCAN_CAPTUREDR                                = 0x2503C000ull;

static const uint64_t P9N2_PERV_EC06_SCAN_CAPTUREDR                                = 0x2603C000ull;

static const uint64_t P9N2_PERV_EC07_SCAN_CAPTUREDR                                = 0x2703C000ull;

static const uint64_t P9N2_PERV_EC08_SCAN_CAPTUREDR                                = 0x2803C000ull;

static const uint64_t P9N2_PERV_EC09_SCAN_CAPTUREDR                                = 0x2903C000ull;

static const uint64_t P9N2_PERV_EC10_SCAN_CAPTUREDR                                = 0x2A03C000ull;

static const uint64_t P9N2_PERV_EC11_SCAN_CAPTUREDR                                = 0x2B03C000ull;

static const uint64_t P9N2_PERV_EC12_SCAN_CAPTUREDR                                = 0x2C03C000ull;

static const uint64_t P9N2_PERV_EC13_SCAN_CAPTUREDR                                = 0x2D03C000ull;

static const uint64_t P9N2_PERV_EC14_SCAN_CAPTUREDR                                = 0x2E03C000ull;

static const uint64_t P9N2_PERV_EC15_SCAN_CAPTUREDR                                = 0x2F03C000ull;

static const uint64_t P9N2_PERV_EC16_SCAN_CAPTUREDR                                = 0x3003C000ull;

static const uint64_t P9N2_PERV_EC17_SCAN_CAPTUREDR                                = 0x3103C000ull;

static const uint64_t P9N2_PERV_EC18_SCAN_CAPTUREDR                                = 0x3203C000ull;

static const uint64_t P9N2_PERV_EC19_SCAN_CAPTUREDR                                = 0x3303C000ull;

static const uint64_t P9N2_PERV_EC20_SCAN_CAPTUREDR                                = 0x3403C000ull;

static const uint64_t P9N2_PERV_EC21_SCAN_CAPTUREDR                                = 0x3503C000ull;

static const uint64_t P9N2_PERV_EC22_SCAN_CAPTUREDR                                = 0x3603C000ull;

static const uint64_t P9N2_PERV_EC23_SCAN_CAPTUREDR                                = 0x3703C000ull;


static const uint64_t P9N2_PERV_12_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x0C03D000ull;

static const uint64_t P9N2_PERV_13_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x0D03D000ull;

static const uint64_t P9N2_PERV_14_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x0E03D000ull;

static const uint64_t P9N2_PERV_15_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x0F03D000ull;

static const uint64_t P9N2_PERV_16_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x1003D000ull;

static const uint64_t P9N2_PERV_17_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x1103D000ull;

static const uint64_t P9N2_PERV_18_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x1203D000ull;

static const uint64_t P9N2_PERV_19_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x1303D000ull;

static const uint64_t P9N2_PERV_1_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0103D000ull;

static const uint64_t P9N2_PERV_20_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x1403D000ull;

static const uint64_t P9N2_PERV_21_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x1503D000ull;

static const uint64_t P9N2_PERV_2_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0203D000ull;

static const uint64_t P9N2_PERV_32_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2003D000ull;

static const uint64_t P9N2_PERV_33_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2103D000ull;

static const uint64_t P9N2_PERV_34_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2203D000ull;

static const uint64_t P9N2_PERV_35_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2303D000ull;

static const uint64_t P9N2_PERV_36_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2403D000ull;

static const uint64_t P9N2_PERV_37_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2503D000ull;

static const uint64_t P9N2_PERV_38_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2603D000ull;

static const uint64_t P9N2_PERV_39_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2703D000ull;

static const uint64_t P9N2_PERV_3_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0303D000ull;

static const uint64_t P9N2_PERV_40_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2803D000ull;

static const uint64_t P9N2_PERV_41_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2903D000ull;

static const uint64_t P9N2_PERV_42_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2A03D000ull;

static const uint64_t P9N2_PERV_43_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2B03D000ull;

static const uint64_t P9N2_PERV_44_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2C03D000ull;

static const uint64_t P9N2_PERV_45_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2D03D000ull;

static const uint64_t P9N2_PERV_46_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2E03D000ull;

static const uint64_t P9N2_PERV_47_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x2F03D000ull;

static const uint64_t P9N2_PERV_48_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3003D000ull;

static const uint64_t P9N2_PERV_49_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3103D000ull;

static const uint64_t P9N2_PERV_4_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0403D000ull;

static const uint64_t P9N2_PERV_50_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3203D000ull;

static const uint64_t P9N2_PERV_51_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3303D000ull;

static const uint64_t P9N2_PERV_52_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3403D000ull;

static const uint64_t P9N2_PERV_53_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3503D000ull;

static const uint64_t P9N2_PERV_54_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3603D000ull;

static const uint64_t P9N2_PERV_55_FSI2PIB_SCAN_CAPTUREDR_LONG                     = 0x3703D000ull;

static const uint64_t P9N2_PERV_5_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0503D000ull;

static const uint64_t P9N2_PERV_6_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0603D000ull;

static const uint64_t P9N2_PERV_7_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0703D000ull;

static const uint64_t P9N2_PERV_8_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0803D000ull;

static const uint64_t P9N2_PERV_9_FSI2PIB_SCAN_CAPTUREDR_LONG                      = 0x0903D000ull;


static const uint64_t P9N2_PERV_12_FSI2PIB_SCAN_LONG_ROTATE                        = 0x0C039000ull;

static const uint64_t P9N2_PERV_13_FSI2PIB_SCAN_LONG_ROTATE                        = 0x0D039000ull;

static const uint64_t P9N2_PERV_14_FSI2PIB_SCAN_LONG_ROTATE                        = 0x0E039000ull;

static const uint64_t P9N2_PERV_15_FSI2PIB_SCAN_LONG_ROTATE                        = 0x0F039000ull;

static const uint64_t P9N2_PERV_16_FSI2PIB_SCAN_LONG_ROTATE                        = 0x10039000ull;

static const uint64_t P9N2_PERV_17_FSI2PIB_SCAN_LONG_ROTATE                        = 0x11039000ull;

static const uint64_t P9N2_PERV_18_FSI2PIB_SCAN_LONG_ROTATE                        = 0x12039000ull;

static const uint64_t P9N2_PERV_19_FSI2PIB_SCAN_LONG_ROTATE                        = 0x13039000ull;

static const uint64_t P9N2_PERV_1_FSI2PIB_SCAN_LONG_ROTATE                         = 0x01039000ull;

static const uint64_t P9N2_PERV_20_FSI2PIB_SCAN_LONG_ROTATE                        = 0x14039000ull;

static const uint64_t P9N2_PERV_21_FSI2PIB_SCAN_LONG_ROTATE                        = 0x15039000ull;

static const uint64_t P9N2_PERV_2_FSI2PIB_SCAN_LONG_ROTATE                         = 0x02039000ull;

static const uint64_t P9N2_PERV_32_FSI2PIB_SCAN_LONG_ROTATE                        = 0x20039000ull;

static const uint64_t P9N2_PERV_33_FSI2PIB_SCAN_LONG_ROTATE                        = 0x21039000ull;

static const uint64_t P9N2_PERV_34_FSI2PIB_SCAN_LONG_ROTATE                        = 0x22039000ull;

static const uint64_t P9N2_PERV_35_FSI2PIB_SCAN_LONG_ROTATE                        = 0x23039000ull;

static const uint64_t P9N2_PERV_36_FSI2PIB_SCAN_LONG_ROTATE                        = 0x24039000ull;

static const uint64_t P9N2_PERV_37_FSI2PIB_SCAN_LONG_ROTATE                        = 0x25039000ull;

static const uint64_t P9N2_PERV_38_FSI2PIB_SCAN_LONG_ROTATE                        = 0x26039000ull;

static const uint64_t P9N2_PERV_39_FSI2PIB_SCAN_LONG_ROTATE                        = 0x27039000ull;

static const uint64_t P9N2_PERV_3_FSI2PIB_SCAN_LONG_ROTATE                         = 0x03039000ull;

static const uint64_t P9N2_PERV_40_FSI2PIB_SCAN_LONG_ROTATE                        = 0x28039000ull;

static const uint64_t P9N2_PERV_41_FSI2PIB_SCAN_LONG_ROTATE                        = 0x29039000ull;

static const uint64_t P9N2_PERV_42_FSI2PIB_SCAN_LONG_ROTATE                        = 0x2A039000ull;

static const uint64_t P9N2_PERV_43_FSI2PIB_SCAN_LONG_ROTATE                        = 0x2B039000ull;

static const uint64_t P9N2_PERV_44_FSI2PIB_SCAN_LONG_ROTATE                        = 0x2C039000ull;

static const uint64_t P9N2_PERV_45_FSI2PIB_SCAN_LONG_ROTATE                        = 0x2D039000ull;

static const uint64_t P9N2_PERV_46_FSI2PIB_SCAN_LONG_ROTATE                        = 0x2E039000ull;

static const uint64_t P9N2_PERV_47_FSI2PIB_SCAN_LONG_ROTATE                        = 0x2F039000ull;

static const uint64_t P9N2_PERV_48_FSI2PIB_SCAN_LONG_ROTATE                        = 0x30039000ull;

static const uint64_t P9N2_PERV_49_FSI2PIB_SCAN_LONG_ROTATE                        = 0x31039000ull;

static const uint64_t P9N2_PERV_4_FSI2PIB_SCAN_LONG_ROTATE                         = 0x04039000ull;

static const uint64_t P9N2_PERV_50_FSI2PIB_SCAN_LONG_ROTATE                        = 0x32039000ull;

static const uint64_t P9N2_PERV_51_FSI2PIB_SCAN_LONG_ROTATE                        = 0x33039000ull;

static const uint64_t P9N2_PERV_52_FSI2PIB_SCAN_LONG_ROTATE                        = 0x34039000ull;

static const uint64_t P9N2_PERV_53_FSI2PIB_SCAN_LONG_ROTATE                        = 0x35039000ull;

static const uint64_t P9N2_PERV_54_FSI2PIB_SCAN_LONG_ROTATE                        = 0x36039000ull;

static const uint64_t P9N2_PERV_55_FSI2PIB_SCAN_LONG_ROTATE                        = 0x37039000ull;

static const uint64_t P9N2_PERV_5_FSI2PIB_SCAN_LONG_ROTATE                         = 0x05039000ull;

static const uint64_t P9N2_PERV_6_FSI2PIB_SCAN_LONG_ROTATE                         = 0x06039000ull;

static const uint64_t P9N2_PERV_7_FSI2PIB_SCAN_LONG_ROTATE                         = 0x07039000ull;

static const uint64_t P9N2_PERV_8_FSI2PIB_SCAN_LONG_ROTATE                         = 0x08039000ull;

static const uint64_t P9N2_PERV_9_FSI2PIB_SCAN_LONG_ROTATE                         = 0x09039000ull;


static const uint64_t P9N2_PERV_SCAN_REGION_TYPE                                   = 0x00030005ull;

static const uint64_t P9N2_PERV_TP_SCAN_REGION_TYPE                                = 0x01030005ull;

static const uint64_t P9N2_PERV_N0_SCAN_REGION_TYPE                                = 0x02030005ull;

static const uint64_t P9N2_PERV_N1_SCAN_REGION_TYPE                                = 0x03030005ull;

static const uint64_t P9N2_PERV_N2_SCAN_REGION_TYPE                                = 0x04030005ull;

static const uint64_t P9N2_PERV_N3_SCAN_REGION_TYPE                                = 0x05030005ull;

static const uint64_t P9N2_PERV_XB_SCAN_REGION_TYPE                                = 0x06030005ull;

static const uint64_t P9N2_PERV_MC01_SCAN_REGION_TYPE                              = 0x07030005ull;

static const uint64_t P9N2_PERV_MC23_SCAN_REGION_TYPE                              = 0x08030005ull;

static const uint64_t P9N2_PERV_OB0_SCAN_REGION_TYPE                               = 0x09030005ull;

static const uint64_t P9N2_PERV_OB3_SCAN_REGION_TYPE                               = 0x0C030005ull;

static const uint64_t P9N2_PERV_PCI0_SCAN_REGION_TYPE                              = 0x0D030005ull;

static const uint64_t P9N2_PERV_PCI1_SCAN_REGION_TYPE                              = 0x0E030005ull;

static const uint64_t P9N2_PERV_PCI2_SCAN_REGION_TYPE                              = 0x0F030005ull;

static const uint64_t P9N2_PERV_EP00_SCAN_REGION_TYPE                              = 0x10030005ull;

static const uint64_t P9N2_PERV_EP01_SCAN_REGION_TYPE                              = 0x11030005ull;

static const uint64_t P9N2_PERV_EP02_SCAN_REGION_TYPE                              = 0x12030005ull;

static const uint64_t P9N2_PERV_EP03_SCAN_REGION_TYPE                              = 0x13030005ull;

static const uint64_t P9N2_PERV_EP04_SCAN_REGION_TYPE                              = 0x14030005ull;

static const uint64_t P9N2_PERV_EP05_SCAN_REGION_TYPE                              = 0x15030005ull;

static const uint64_t P9N2_PERV_EC00_SCAN_REGION_TYPE                              = 0x20030005ull;

static const uint64_t P9N2_PERV_EC01_SCAN_REGION_TYPE                              = 0x21030005ull;

static const uint64_t P9N2_PERV_EC02_SCAN_REGION_TYPE                              = 0x22030005ull;

static const uint64_t P9N2_PERV_EC03_SCAN_REGION_TYPE                              = 0x23030005ull;

static const uint64_t P9N2_PERV_EC04_SCAN_REGION_TYPE                              = 0x24030005ull;

static const uint64_t P9N2_PERV_EC05_SCAN_REGION_TYPE                              = 0x25030005ull;

static const uint64_t P9N2_PERV_EC06_SCAN_REGION_TYPE                              = 0x26030005ull;

static const uint64_t P9N2_PERV_EC07_SCAN_REGION_TYPE                              = 0x27030005ull;

static const uint64_t P9N2_PERV_EC08_SCAN_REGION_TYPE                              = 0x28030005ull;

static const uint64_t P9N2_PERV_EC09_SCAN_REGION_TYPE                              = 0x29030005ull;

static const uint64_t P9N2_PERV_EC10_SCAN_REGION_TYPE                              = 0x2A030005ull;

static const uint64_t P9N2_PERV_EC11_SCAN_REGION_TYPE                              = 0x2B030005ull;

static const uint64_t P9N2_PERV_EC12_SCAN_REGION_TYPE                              = 0x2C030005ull;

static const uint64_t P9N2_PERV_EC13_SCAN_REGION_TYPE                              = 0x2D030005ull;

static const uint64_t P9N2_PERV_EC14_SCAN_REGION_TYPE                              = 0x2E030005ull;

static const uint64_t P9N2_PERV_EC15_SCAN_REGION_TYPE                              = 0x2F030005ull;

static const uint64_t P9N2_PERV_EC16_SCAN_REGION_TYPE                              = 0x30030005ull;

static const uint64_t P9N2_PERV_EC17_SCAN_REGION_TYPE                              = 0x31030005ull;

static const uint64_t P9N2_PERV_EC18_SCAN_REGION_TYPE                              = 0x32030005ull;

static const uint64_t P9N2_PERV_EC19_SCAN_REGION_TYPE                              = 0x33030005ull;

static const uint64_t P9N2_PERV_EC20_SCAN_REGION_TYPE                              = 0x34030005ull;

static const uint64_t P9N2_PERV_EC21_SCAN_REGION_TYPE                              = 0x35030005ull;

static const uint64_t P9N2_PERV_EC22_SCAN_REGION_TYPE                              = 0x36030005ull;

static const uint64_t P9N2_PERV_EC23_SCAN_REGION_TYPE                              = 0x37030005ull;


static const uint64_t P9N2_PERV_SCAN_UPDATEDR                                      = 0x0003A000ull;

static const uint64_t P9N2_PERV_TP_SCAN_UPDATEDR                                   = 0x0103A000ull;

static const uint64_t P9N2_PERV_N0_SCAN_UPDATEDR                                   = 0x0203A000ull;

static const uint64_t P9N2_PERV_N1_SCAN_UPDATEDR                                   = 0x0303A000ull;

static const uint64_t P9N2_PERV_N2_SCAN_UPDATEDR                                   = 0x0403A000ull;

static const uint64_t P9N2_PERV_N3_SCAN_UPDATEDR                                   = 0x0503A000ull;

static const uint64_t P9N2_PERV_XB_SCAN_UPDATEDR                                   = 0x0603A000ull;

static const uint64_t P9N2_PERV_MC01_SCAN_UPDATEDR                                 = 0x0703A000ull;

static const uint64_t P9N2_PERV_MC23_SCAN_UPDATEDR                                 = 0x0803A000ull;

static const uint64_t P9N2_PERV_OB0_SCAN_UPDATEDR                                  = 0x0903A000ull;

static const uint64_t P9N2_PERV_OB3_SCAN_UPDATEDR                                  = 0x0C03A000ull;

static const uint64_t P9N2_PERV_PCI0_SCAN_UPDATEDR                                 = 0x0D03A000ull;

static const uint64_t P9N2_PERV_PCI1_SCAN_UPDATEDR                                 = 0x0E03A000ull;

static const uint64_t P9N2_PERV_PCI2_SCAN_UPDATEDR                                 = 0x0F03A000ull;

static const uint64_t P9N2_PERV_EP00_SCAN_UPDATEDR                                 = 0x1003A000ull;

static const uint64_t P9N2_PERV_EP01_SCAN_UPDATEDR                                 = 0x1103A000ull;

static const uint64_t P9N2_PERV_EP02_SCAN_UPDATEDR                                 = 0x1203A000ull;

static const uint64_t P9N2_PERV_EP03_SCAN_UPDATEDR                                 = 0x1303A000ull;

static const uint64_t P9N2_PERV_EP04_SCAN_UPDATEDR                                 = 0x1403A000ull;

static const uint64_t P9N2_PERV_EP05_SCAN_UPDATEDR                                 = 0x1503A000ull;

static const uint64_t P9N2_PERV_EC00_SCAN_UPDATEDR                                 = 0x2003A000ull;

static const uint64_t P9N2_PERV_EC01_SCAN_UPDATEDR                                 = 0x2103A000ull;

static const uint64_t P9N2_PERV_EC02_SCAN_UPDATEDR                                 = 0x2203A000ull;

static const uint64_t P9N2_PERV_EC03_SCAN_UPDATEDR                                 = 0x2303A000ull;

static const uint64_t P9N2_PERV_EC04_SCAN_UPDATEDR                                 = 0x2403A000ull;

static const uint64_t P9N2_PERV_EC05_SCAN_UPDATEDR                                 = 0x2503A000ull;

static const uint64_t P9N2_PERV_EC06_SCAN_UPDATEDR                                 = 0x2603A000ull;

static const uint64_t P9N2_PERV_EC07_SCAN_UPDATEDR                                 = 0x2703A000ull;

static const uint64_t P9N2_PERV_EC08_SCAN_UPDATEDR                                 = 0x2803A000ull;

static const uint64_t P9N2_PERV_EC09_SCAN_UPDATEDR                                 = 0x2903A000ull;

static const uint64_t P9N2_PERV_EC10_SCAN_UPDATEDR                                 = 0x2A03A000ull;

static const uint64_t P9N2_PERV_EC11_SCAN_UPDATEDR                                 = 0x2B03A000ull;

static const uint64_t P9N2_PERV_EC12_SCAN_UPDATEDR                                 = 0x2C03A000ull;

static const uint64_t P9N2_PERV_EC13_SCAN_UPDATEDR                                 = 0x2D03A000ull;

static const uint64_t P9N2_PERV_EC14_SCAN_UPDATEDR                                 = 0x2E03A000ull;

static const uint64_t P9N2_PERV_EC15_SCAN_UPDATEDR                                 = 0x2F03A000ull;

static const uint64_t P9N2_PERV_EC16_SCAN_UPDATEDR                                 = 0x3003A000ull;

static const uint64_t P9N2_PERV_EC17_SCAN_UPDATEDR                                 = 0x3103A000ull;

static const uint64_t P9N2_PERV_EC18_SCAN_UPDATEDR                                 = 0x3203A000ull;

static const uint64_t P9N2_PERV_EC19_SCAN_UPDATEDR                                 = 0x3303A000ull;

static const uint64_t P9N2_PERV_EC20_SCAN_UPDATEDR                                 = 0x3403A000ull;

static const uint64_t P9N2_PERV_EC21_SCAN_UPDATEDR                                 = 0x3503A000ull;

static const uint64_t P9N2_PERV_EC22_SCAN_UPDATEDR                                 = 0x3603A000ull;

static const uint64_t P9N2_PERV_EC23_SCAN_UPDATEDR                                 = 0x3703A000ull;


static const uint64_t P9N2_PERV_SCAN_UPDATEDR_LONG                                 = 0x0003B000ull;

static const uint64_t P9N2_PERV_TP_SCAN_UPDATEDR_LONG                              = 0x0103B000ull;

static const uint64_t P9N2_PERV_N0_SCAN_UPDATEDR_LONG                              = 0x0203B000ull;

static const uint64_t P9N2_PERV_N1_SCAN_UPDATEDR_LONG                              = 0x0303B000ull;

static const uint64_t P9N2_PERV_N2_SCAN_UPDATEDR_LONG                              = 0x0403B000ull;

static const uint64_t P9N2_PERV_N3_SCAN_UPDATEDR_LONG                              = 0x0503B000ull;

static const uint64_t P9N2_PERV_XB_SCAN_UPDATEDR_LONG                              = 0x0603B000ull;

static const uint64_t P9N2_PERV_MC01_SCAN_UPDATEDR_LONG                            = 0x0703B000ull;

static const uint64_t P9N2_PERV_MC23_SCAN_UPDATEDR_LONG                            = 0x0803B000ull;

static const uint64_t P9N2_PERV_OB0_SCAN_UPDATEDR_LONG                             = 0x0903B000ull;

static const uint64_t P9N2_PERV_OB3_SCAN_UPDATEDR_LONG                             = 0x0C03B000ull;

static const uint64_t P9N2_PERV_PCI0_SCAN_UPDATEDR_LONG                            = 0x0D03B000ull;

static const uint64_t P9N2_PERV_PCI1_SCAN_UPDATEDR_LONG                            = 0x0E03B000ull;

static const uint64_t P9N2_PERV_PCI2_SCAN_UPDATEDR_LONG                            = 0x0F03B000ull;

static const uint64_t P9N2_PERV_EP00_SCAN_UPDATEDR_LONG                            = 0x1003B000ull;

static const uint64_t P9N2_PERV_EP01_SCAN_UPDATEDR_LONG                            = 0x1103B000ull;

static const uint64_t P9N2_PERV_EP02_SCAN_UPDATEDR_LONG                            = 0x1203B000ull;

static const uint64_t P9N2_PERV_EP03_SCAN_UPDATEDR_LONG                            = 0x1303B000ull;

static const uint64_t P9N2_PERV_EP04_SCAN_UPDATEDR_LONG                            = 0x1403B000ull;

static const uint64_t P9N2_PERV_EP05_SCAN_UPDATEDR_LONG                            = 0x1503B000ull;

static const uint64_t P9N2_PERV_EC00_SCAN_UPDATEDR_LONG                            = 0x2003B000ull;

static const uint64_t P9N2_PERV_EC01_SCAN_UPDATEDR_LONG                            = 0x2103B000ull;

static const uint64_t P9N2_PERV_EC02_SCAN_UPDATEDR_LONG                            = 0x2203B000ull;

static const uint64_t P9N2_PERV_EC03_SCAN_UPDATEDR_LONG                            = 0x2303B000ull;

static const uint64_t P9N2_PERV_EC04_SCAN_UPDATEDR_LONG                            = 0x2403B000ull;

static const uint64_t P9N2_PERV_EC05_SCAN_UPDATEDR_LONG                            = 0x2503B000ull;

static const uint64_t P9N2_PERV_EC06_SCAN_UPDATEDR_LONG                            = 0x2603B000ull;

static const uint64_t P9N2_PERV_EC07_SCAN_UPDATEDR_LONG                            = 0x2703B000ull;

static const uint64_t P9N2_PERV_EC08_SCAN_UPDATEDR_LONG                            = 0x2803B000ull;

static const uint64_t P9N2_PERV_EC09_SCAN_UPDATEDR_LONG                            = 0x2903B000ull;

static const uint64_t P9N2_PERV_EC10_SCAN_UPDATEDR_LONG                            = 0x2A03B000ull;

static const uint64_t P9N2_PERV_EC11_SCAN_UPDATEDR_LONG                            = 0x2B03B000ull;

static const uint64_t P9N2_PERV_EC12_SCAN_UPDATEDR_LONG                            = 0x2C03B000ull;

static const uint64_t P9N2_PERV_EC13_SCAN_UPDATEDR_LONG                            = 0x2D03B000ull;

static const uint64_t P9N2_PERV_EC14_SCAN_UPDATEDR_LONG                            = 0x2E03B000ull;

static const uint64_t P9N2_PERV_EC15_SCAN_UPDATEDR_LONG                            = 0x2F03B000ull;

static const uint64_t P9N2_PERV_EC16_SCAN_UPDATEDR_LONG                            = 0x3003B000ull;

static const uint64_t P9N2_PERV_EC17_SCAN_UPDATEDR_LONG                            = 0x3103B000ull;

static const uint64_t P9N2_PERV_EC18_SCAN_UPDATEDR_LONG                            = 0x3203B000ull;

static const uint64_t P9N2_PERV_EC19_SCAN_UPDATEDR_LONG                            = 0x3303B000ull;

static const uint64_t P9N2_PERV_EC20_SCAN_UPDATEDR_LONG                            = 0x3403B000ull;

static const uint64_t P9N2_PERV_EC21_SCAN_UPDATEDR_LONG                            = 0x3503B000ull;

static const uint64_t P9N2_PERV_EC22_SCAN_UPDATEDR_LONG                            = 0x3603B000ull;

static const uint64_t P9N2_PERV_EC23_SCAN_UPDATEDR_LONG                            = 0x3703B000ull;


static const uint32_t P9N2_PERV_SCPSIZE_FSI                                        = 0x00001400ull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_1_FSI                             = 0x00002838ull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_1_FSI_BYTE                        = 0x000028E0ull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_1_SCOM                            = 0x00050038ull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_1                             = 0x00050038ull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_2_FSI                             = 0x00002839ull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_2_FSI_BYTE                        = 0x000028E4ull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_2_SCOM                            = 0x00050039ull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_2                             = 0x00050039ull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_3_FSI                             = 0x0000283Aull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_3_FSI_BYTE                        = 0x000028E8ull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_3_SCOM                            = 0x0005003Aull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_3                             = 0x0005003Aull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_4_FSI                             = 0x0000283Bull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_4_FSI_BYTE                        = 0x000028ECull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_4_SCOM                            = 0x0005003Bull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_4                             = 0x0005003Bull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_5_FSI                             = 0x0000283Cull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_5_FSI_BYTE                        = 0x000028F0ull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_5_SCOM                            = 0x0005003Cull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_5                             = 0x0005003Cull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_6_FSI                             = 0x0000283Dull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_6_FSI_BYTE                        = 0x000028F4ull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_6_SCOM                            = 0x0005003Dull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_6                             = 0x0005003Dull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_7_FSI                             = 0x0000283Eull;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_7_FSI_BYTE                        = 0x000028F8ull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_7_SCOM                            = 0x0005003Eull;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_7                             = 0x0005003Eull;


static const uint32_t P9N2_PERV_SCRATCH_REGISTER_8_FSI                             = 0x0000283Full;

static const uint32_t P9N2_PERV_SCRATCH_REGISTER_8_FSI_BYTE                        = 0x000028FCull;

static const uint64_t P9N2_PERV_SCRATCH_REGISTER_8_SCOM                            = 0x0005003Full;

static const uint64_t P9N2_PERV_PIB_SCRATCH_REGISTER_8                             = 0x0005003Full;


static const uint32_t P9N2_PERV_FSI2PIB_SET_PIB_RESET_FSI                          = 0x00001007ull;

static const uint32_t P9N2_PERV_FSI2PIB_SET_PIB_RESET_FSI_BYTE                     = 0x0000101Cull;


static const uint32_t P9N2_PERV_FSISHIFT_SHIFT_CONTROL_REGISTER_2_FSI              = 0x00000C10ull;

static const uint32_t P9N2_PERV_FSISHIFT_SHIFT_CONTROL_REGISTER_2_FSI_BYTE         = 0x00000C40ull;


static const uint64_t P9N2_PERV_SKITTER_CLKSRC_REG                                 = 0x00050016ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_SKITTER_CLKSRC_REG                              = 0x01050016ull;

static const uint64_t P9N2_PERV_N0_SKITTER_CLKSRC_REG                              = 0x02050016ull;

static const uint64_t P9N2_PERV_N1_SKITTER_CLKSRC_REG                              = 0x03050016ull;

static const uint64_t P9N2_PERV_N2_SKITTER_CLKSRC_REG                              = 0x04050016ull;

static const uint64_t P9N2_PERV_N3_SKITTER_CLKSRC_REG                              = 0x05050016ull;

static const uint64_t P9N2_PERV_XB_SKITTER_CLKSRC_REG                              = 0x06050016ull;

static const uint64_t P9N2_PERV_MC01_SKITTER_CLKSRC_REG                            = 0x07050016ull;

static const uint64_t P9N2_PERV_MC23_SKITTER_CLKSRC_REG                            = 0x08050016ull;

static const uint64_t P9N2_PERV_OB0_SKITTER_CLKSRC_REG                             = 0x09050016ull;

static const uint64_t P9N2_PERV_OB3_SKITTER_CLKSRC_REG                             = 0x0C050016ull;

static const uint64_t P9N2_PERV_PCI0_SKITTER_CLKSRC_REG                            = 0x0D050016ull;

static const uint64_t P9N2_PERV_PCI1_SKITTER_CLKSRC_REG                            = 0x0E050016ull;

static const uint64_t P9N2_PERV_PCI2_SKITTER_CLKSRC_REG                            = 0x0F050016ull;

static const uint64_t P9N2_PERV_EP00_SKITTER_CLKSRC_REG                            = 0x10050016ull;

static const uint64_t P9N2_PERV_EP01_SKITTER_CLKSRC_REG                            = 0x11050016ull;

static const uint64_t P9N2_PERV_EP02_SKITTER_CLKSRC_REG                            = 0x12050016ull;

static const uint64_t P9N2_PERV_EP03_SKITTER_CLKSRC_REG                            = 0x13050016ull;

static const uint64_t P9N2_PERV_EP04_SKITTER_CLKSRC_REG                            = 0x14050016ull;

static const uint64_t P9N2_PERV_EP05_SKITTER_CLKSRC_REG                            = 0x15050016ull;

static const uint64_t P9N2_PERV_EC00_SKITTER_CLKSRC_REG                            = 0x20050016ull;

static const uint64_t P9N2_PERV_EC01_SKITTER_CLKSRC_REG                            = 0x21050016ull;

static const uint64_t P9N2_PERV_EC02_SKITTER_CLKSRC_REG                            = 0x22050016ull;

static const uint64_t P9N2_PERV_EC03_SKITTER_CLKSRC_REG                            = 0x23050016ull;

static const uint64_t P9N2_PERV_EC04_SKITTER_CLKSRC_REG                            = 0x24050016ull;

static const uint64_t P9N2_PERV_EC05_SKITTER_CLKSRC_REG                            = 0x25050016ull;

static const uint64_t P9N2_PERV_EC06_SKITTER_CLKSRC_REG                            = 0x26050016ull;

static const uint64_t P9N2_PERV_EC07_SKITTER_CLKSRC_REG                            = 0x27050016ull;

static const uint64_t P9N2_PERV_EC08_SKITTER_CLKSRC_REG                            = 0x28050016ull;

static const uint64_t P9N2_PERV_EC09_SKITTER_CLKSRC_REG                            = 0x29050016ull;

static const uint64_t P9N2_PERV_EC10_SKITTER_CLKSRC_REG                            = 0x2A050016ull;

static const uint64_t P9N2_PERV_EC11_SKITTER_CLKSRC_REG                            = 0x2B050016ull;

static const uint64_t P9N2_PERV_EC12_SKITTER_CLKSRC_REG                            = 0x2C050016ull;

static const uint64_t P9N2_PERV_EC13_SKITTER_CLKSRC_REG                            = 0x2D050016ull;

static const uint64_t P9N2_PERV_EC14_SKITTER_CLKSRC_REG                            = 0x2E050016ull;

static const uint64_t P9N2_PERV_EC15_SKITTER_CLKSRC_REG                            = 0x2F050016ull;

static const uint64_t P9N2_PERV_EC16_SKITTER_CLKSRC_REG                            = 0x30050016ull;

static const uint64_t P9N2_PERV_EC17_SKITTER_CLKSRC_REG                            = 0x31050016ull;

static const uint64_t P9N2_PERV_EC18_SKITTER_CLKSRC_REG                            = 0x32050016ull;

static const uint64_t P9N2_PERV_EC19_SKITTER_CLKSRC_REG                            = 0x33050016ull;

static const uint64_t P9N2_PERV_EC20_SKITTER_CLKSRC_REG                            = 0x34050016ull;

static const uint64_t P9N2_PERV_EC21_SKITTER_CLKSRC_REG                            = 0x35050016ull;

static const uint64_t P9N2_PERV_EC22_SKITTER_CLKSRC_REG                            = 0x36050016ull;

static const uint64_t P9N2_PERV_EC23_SKITTER_CLKSRC_REG                            = 0x37050016ull;


static const uint64_t P9N2_PERV_SKITTER_DATA0                                      = 0x00050019ull;

static const uint64_t P9N2_PERV_TP_SKITTER_DATA0                                   = 0x01050019ull;

static const uint64_t P9N2_PERV_N0_SKITTER_DATA0                                   = 0x02050019ull;

static const uint64_t P9N2_PERV_N1_SKITTER_DATA0                                   = 0x03050019ull;

static const uint64_t P9N2_PERV_N2_SKITTER_DATA0                                   = 0x04050019ull;

static const uint64_t P9N2_PERV_N3_SKITTER_DATA0                                   = 0x05050019ull;

static const uint64_t P9N2_PERV_XB_SKITTER_DATA0                                   = 0x06050019ull;

static const uint64_t P9N2_PERV_MC01_SKITTER_DATA0                                 = 0x07050019ull;

static const uint64_t P9N2_PERV_MC23_SKITTER_DATA0                                 = 0x08050019ull;

static const uint64_t P9N2_PERV_OB0_SKITTER_DATA0                                  = 0x09050019ull;

static const uint64_t P9N2_PERV_OB3_SKITTER_DATA0                                  = 0x0C050019ull;

static const uint64_t P9N2_PERV_PCI0_SKITTER_DATA0                                 = 0x0D050019ull;

static const uint64_t P9N2_PERV_PCI1_SKITTER_DATA0                                 = 0x0E050019ull;

static const uint64_t P9N2_PERV_PCI2_SKITTER_DATA0                                 = 0x0F050019ull;

static const uint64_t P9N2_PERV_EP00_SKITTER_DATA0                                 = 0x10050019ull;

static const uint64_t P9N2_PERV_EP01_SKITTER_DATA0                                 = 0x11050019ull;

static const uint64_t P9N2_PERV_EP02_SKITTER_DATA0                                 = 0x12050019ull;

static const uint64_t P9N2_PERV_EP03_SKITTER_DATA0                                 = 0x13050019ull;

static const uint64_t P9N2_PERV_EP04_SKITTER_DATA0                                 = 0x14050019ull;

static const uint64_t P9N2_PERV_EP05_SKITTER_DATA0                                 = 0x15050019ull;

static const uint64_t P9N2_PERV_EC00_SKITTER_DATA0                                 = 0x20050019ull;

static const uint64_t P9N2_PERV_EC01_SKITTER_DATA0                                 = 0x21050019ull;

static const uint64_t P9N2_PERV_EC02_SKITTER_DATA0                                 = 0x22050019ull;

static const uint64_t P9N2_PERV_EC03_SKITTER_DATA0                                 = 0x23050019ull;

static const uint64_t P9N2_PERV_EC04_SKITTER_DATA0                                 = 0x24050019ull;

static const uint64_t P9N2_PERV_EC05_SKITTER_DATA0                                 = 0x25050019ull;

static const uint64_t P9N2_PERV_EC06_SKITTER_DATA0                                 = 0x26050019ull;

static const uint64_t P9N2_PERV_EC07_SKITTER_DATA0                                 = 0x27050019ull;

static const uint64_t P9N2_PERV_EC08_SKITTER_DATA0                                 = 0x28050019ull;

static const uint64_t P9N2_PERV_EC09_SKITTER_DATA0                                 = 0x29050019ull;

static const uint64_t P9N2_PERV_EC10_SKITTER_DATA0                                 = 0x2A050019ull;

static const uint64_t P9N2_PERV_EC11_SKITTER_DATA0                                 = 0x2B050019ull;

static const uint64_t P9N2_PERV_EC12_SKITTER_DATA0                                 = 0x2C050019ull;

static const uint64_t P9N2_PERV_EC13_SKITTER_DATA0                                 = 0x2D050019ull;

static const uint64_t P9N2_PERV_EC14_SKITTER_DATA0                                 = 0x2E050019ull;

static const uint64_t P9N2_PERV_EC15_SKITTER_DATA0                                 = 0x2F050019ull;

static const uint64_t P9N2_PERV_EC16_SKITTER_DATA0                                 = 0x30050019ull;

static const uint64_t P9N2_PERV_EC17_SKITTER_DATA0                                 = 0x31050019ull;

static const uint64_t P9N2_PERV_EC18_SKITTER_DATA0                                 = 0x32050019ull;

static const uint64_t P9N2_PERV_EC19_SKITTER_DATA0                                 = 0x33050019ull;

static const uint64_t P9N2_PERV_EC20_SKITTER_DATA0                                 = 0x34050019ull;

static const uint64_t P9N2_PERV_EC21_SKITTER_DATA0                                 = 0x35050019ull;

static const uint64_t P9N2_PERV_EC22_SKITTER_DATA0                                 = 0x36050019ull;

static const uint64_t P9N2_PERV_EC23_SKITTER_DATA0                                 = 0x37050019ull;


static const uint64_t P9N2_PERV_SKITTER_DATA1                                      = 0x0005001Aull;

static const uint64_t P9N2_PERV_TP_SKITTER_DATA1                                   = 0x0105001Aull;

static const uint64_t P9N2_PERV_N0_SKITTER_DATA1                                   = 0x0205001Aull;

static const uint64_t P9N2_PERV_N1_SKITTER_DATA1                                   = 0x0305001Aull;

static const uint64_t P9N2_PERV_N2_SKITTER_DATA1                                   = 0x0405001Aull;

static const uint64_t P9N2_PERV_N3_SKITTER_DATA1                                   = 0x0505001Aull;

static const uint64_t P9N2_PERV_XB_SKITTER_DATA1                                   = 0x0605001Aull;

static const uint64_t P9N2_PERV_MC01_SKITTER_DATA1                                 = 0x0705001Aull;

static const uint64_t P9N2_PERV_MC23_SKITTER_DATA1                                 = 0x0805001Aull;

static const uint64_t P9N2_PERV_OB0_SKITTER_DATA1                                  = 0x0905001Aull;

static const uint64_t P9N2_PERV_OB3_SKITTER_DATA1                                  = 0x0C05001Aull;

static const uint64_t P9N2_PERV_PCI0_SKITTER_DATA1                                 = 0x0D05001Aull;

static const uint64_t P9N2_PERV_PCI1_SKITTER_DATA1                                 = 0x0E05001Aull;

static const uint64_t P9N2_PERV_PCI2_SKITTER_DATA1                                 = 0x0F05001Aull;

static const uint64_t P9N2_PERV_EP00_SKITTER_DATA1                                 = 0x1005001Aull;

static const uint64_t P9N2_PERV_EP01_SKITTER_DATA1                                 = 0x1105001Aull;

static const uint64_t P9N2_PERV_EP02_SKITTER_DATA1                                 = 0x1205001Aull;

static const uint64_t P9N2_PERV_EP03_SKITTER_DATA1                                 = 0x1305001Aull;

static const uint64_t P9N2_PERV_EP04_SKITTER_DATA1                                 = 0x1405001Aull;

static const uint64_t P9N2_PERV_EP05_SKITTER_DATA1                                 = 0x1505001Aull;

static const uint64_t P9N2_PERV_EC00_SKITTER_DATA1                                 = 0x2005001Aull;

static const uint64_t P9N2_PERV_EC01_SKITTER_DATA1                                 = 0x2105001Aull;

static const uint64_t P9N2_PERV_EC02_SKITTER_DATA1                                 = 0x2205001Aull;

static const uint64_t P9N2_PERV_EC03_SKITTER_DATA1                                 = 0x2305001Aull;

static const uint64_t P9N2_PERV_EC04_SKITTER_DATA1                                 = 0x2405001Aull;

static const uint64_t P9N2_PERV_EC05_SKITTER_DATA1                                 = 0x2505001Aull;

static const uint64_t P9N2_PERV_EC06_SKITTER_DATA1                                 = 0x2605001Aull;

static const uint64_t P9N2_PERV_EC07_SKITTER_DATA1                                 = 0x2705001Aull;

static const uint64_t P9N2_PERV_EC08_SKITTER_DATA1                                 = 0x2805001Aull;

static const uint64_t P9N2_PERV_EC09_SKITTER_DATA1                                 = 0x2905001Aull;

static const uint64_t P9N2_PERV_EC10_SKITTER_DATA1                                 = 0x2A05001Aull;

static const uint64_t P9N2_PERV_EC11_SKITTER_DATA1                                 = 0x2B05001Aull;

static const uint64_t P9N2_PERV_EC12_SKITTER_DATA1                                 = 0x2C05001Aull;

static const uint64_t P9N2_PERV_EC13_SKITTER_DATA1                                 = 0x2D05001Aull;

static const uint64_t P9N2_PERV_EC14_SKITTER_DATA1                                 = 0x2E05001Aull;

static const uint64_t P9N2_PERV_EC15_SKITTER_DATA1                                 = 0x2F05001Aull;

static const uint64_t P9N2_PERV_EC16_SKITTER_DATA1                                 = 0x3005001Aull;

static const uint64_t P9N2_PERV_EC17_SKITTER_DATA1                                 = 0x3105001Aull;

static const uint64_t P9N2_PERV_EC18_SKITTER_DATA1                                 = 0x3205001Aull;

static const uint64_t P9N2_PERV_EC19_SKITTER_DATA1                                 = 0x3305001Aull;

static const uint64_t P9N2_PERV_EC20_SKITTER_DATA1                                 = 0x3405001Aull;

static const uint64_t P9N2_PERV_EC21_SKITTER_DATA1                                 = 0x3505001Aull;

static const uint64_t P9N2_PERV_EC22_SKITTER_DATA1                                 = 0x3605001Aull;

static const uint64_t P9N2_PERV_EC23_SKITTER_DATA1                                 = 0x3705001Aull;


static const uint64_t P9N2_PERV_SKITTER_DATA2                                      = 0x0005001Bull;

static const uint64_t P9N2_PERV_TP_SKITTER_DATA2                                   = 0x0105001Bull;

static const uint64_t P9N2_PERV_N0_SKITTER_DATA2                                   = 0x0205001Bull;

static const uint64_t P9N2_PERV_N1_SKITTER_DATA2                                   = 0x0305001Bull;

static const uint64_t P9N2_PERV_N2_SKITTER_DATA2                                   = 0x0405001Bull;

static const uint64_t P9N2_PERV_N3_SKITTER_DATA2                                   = 0x0505001Bull;

static const uint64_t P9N2_PERV_XB_SKITTER_DATA2                                   = 0x0605001Bull;

static const uint64_t P9N2_PERV_MC01_SKITTER_DATA2                                 = 0x0705001Bull;

static const uint64_t P9N2_PERV_MC23_SKITTER_DATA2                                 = 0x0805001Bull;

static const uint64_t P9N2_PERV_OB0_SKITTER_DATA2                                  = 0x0905001Bull;

static const uint64_t P9N2_PERV_OB3_SKITTER_DATA2                                  = 0x0C05001Bull;

static const uint64_t P9N2_PERV_PCI0_SKITTER_DATA2                                 = 0x0D05001Bull;

static const uint64_t P9N2_PERV_PCI1_SKITTER_DATA2                                 = 0x0E05001Bull;

static const uint64_t P9N2_PERV_PCI2_SKITTER_DATA2                                 = 0x0F05001Bull;

static const uint64_t P9N2_PERV_EP00_SKITTER_DATA2                                 = 0x1005001Bull;

static const uint64_t P9N2_PERV_EP01_SKITTER_DATA2                                 = 0x1105001Bull;

static const uint64_t P9N2_PERV_EP02_SKITTER_DATA2                                 = 0x1205001Bull;

static const uint64_t P9N2_PERV_EP03_SKITTER_DATA2                                 = 0x1305001Bull;

static const uint64_t P9N2_PERV_EP04_SKITTER_DATA2                                 = 0x1405001Bull;

static const uint64_t P9N2_PERV_EP05_SKITTER_DATA2                                 = 0x1505001Bull;

static const uint64_t P9N2_PERV_EC00_SKITTER_DATA2                                 = 0x2005001Bull;

static const uint64_t P9N2_PERV_EC01_SKITTER_DATA2                                 = 0x2105001Bull;

static const uint64_t P9N2_PERV_EC02_SKITTER_DATA2                                 = 0x2205001Bull;

static const uint64_t P9N2_PERV_EC03_SKITTER_DATA2                                 = 0x2305001Bull;

static const uint64_t P9N2_PERV_EC04_SKITTER_DATA2                                 = 0x2405001Bull;

static const uint64_t P9N2_PERV_EC05_SKITTER_DATA2                                 = 0x2505001Bull;

static const uint64_t P9N2_PERV_EC06_SKITTER_DATA2                                 = 0x2605001Bull;

static const uint64_t P9N2_PERV_EC07_SKITTER_DATA2                                 = 0x2705001Bull;

static const uint64_t P9N2_PERV_EC08_SKITTER_DATA2                                 = 0x2805001Bull;

static const uint64_t P9N2_PERV_EC09_SKITTER_DATA2                                 = 0x2905001Bull;

static const uint64_t P9N2_PERV_EC10_SKITTER_DATA2                                 = 0x2A05001Bull;

static const uint64_t P9N2_PERV_EC11_SKITTER_DATA2                                 = 0x2B05001Bull;

static const uint64_t P9N2_PERV_EC12_SKITTER_DATA2                                 = 0x2C05001Bull;

static const uint64_t P9N2_PERV_EC13_SKITTER_DATA2                                 = 0x2D05001Bull;

static const uint64_t P9N2_PERV_EC14_SKITTER_DATA2                                 = 0x2E05001Bull;

static const uint64_t P9N2_PERV_EC15_SKITTER_DATA2                                 = 0x2F05001Bull;

static const uint64_t P9N2_PERV_EC16_SKITTER_DATA2                                 = 0x3005001Bull;

static const uint64_t P9N2_PERV_EC17_SKITTER_DATA2                                 = 0x3105001Bull;

static const uint64_t P9N2_PERV_EC18_SKITTER_DATA2                                 = 0x3205001Bull;

static const uint64_t P9N2_PERV_EC19_SKITTER_DATA2                                 = 0x3305001Bull;

static const uint64_t P9N2_PERV_EC20_SKITTER_DATA2                                 = 0x3405001Bull;

static const uint64_t P9N2_PERV_EC21_SKITTER_DATA2                                 = 0x3505001Bull;

static const uint64_t P9N2_PERV_EC22_SKITTER_DATA2                                 = 0x3605001Bull;

static const uint64_t P9N2_PERV_EC23_SKITTER_DATA2                                 = 0x3705001Bull;


static const uint64_t P9N2_PERV_SKITTER_FORCE_REG                                  = 0x00050014ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_SKITTER_FORCE_REG                               = 0x01050014ull;

static const uint64_t P9N2_PERV_N0_SKITTER_FORCE_REG                               = 0x02050014ull;

static const uint64_t P9N2_PERV_N1_SKITTER_FORCE_REG                               = 0x03050014ull;

static const uint64_t P9N2_PERV_N2_SKITTER_FORCE_REG                               = 0x04050014ull;

static const uint64_t P9N2_PERV_N3_SKITTER_FORCE_REG                               = 0x05050014ull;

static const uint64_t P9N2_PERV_XB_SKITTER_FORCE_REG                               = 0x06050014ull;

static const uint64_t P9N2_PERV_MC01_SKITTER_FORCE_REG                             = 0x07050014ull;

static const uint64_t P9N2_PERV_MC23_SKITTER_FORCE_REG                             = 0x08050014ull;

static const uint64_t P9N2_PERV_OB0_SKITTER_FORCE_REG                              = 0x09050014ull;

static const uint64_t P9N2_PERV_OB3_SKITTER_FORCE_REG                              = 0x0C050014ull;

static const uint64_t P9N2_PERV_PCI0_SKITTER_FORCE_REG                             = 0x0D050014ull;

static const uint64_t P9N2_PERV_PCI1_SKITTER_FORCE_REG                             = 0x0E050014ull;

static const uint64_t P9N2_PERV_PCI2_SKITTER_FORCE_REG                             = 0x0F050014ull;

static const uint64_t P9N2_PERV_EP00_SKITTER_FORCE_REG                             = 0x10050014ull;

static const uint64_t P9N2_PERV_EP01_SKITTER_FORCE_REG                             = 0x11050014ull;

static const uint64_t P9N2_PERV_EP02_SKITTER_FORCE_REG                             = 0x12050014ull;

static const uint64_t P9N2_PERV_EP03_SKITTER_FORCE_REG                             = 0x13050014ull;

static const uint64_t P9N2_PERV_EP04_SKITTER_FORCE_REG                             = 0x14050014ull;

static const uint64_t P9N2_PERV_EP05_SKITTER_FORCE_REG                             = 0x15050014ull;

static const uint64_t P9N2_PERV_EC00_SKITTER_FORCE_REG                             = 0x20050014ull;

static const uint64_t P9N2_PERV_EC01_SKITTER_FORCE_REG                             = 0x21050014ull;

static const uint64_t P9N2_PERV_EC02_SKITTER_FORCE_REG                             = 0x22050014ull;

static const uint64_t P9N2_PERV_EC03_SKITTER_FORCE_REG                             = 0x23050014ull;

static const uint64_t P9N2_PERV_EC04_SKITTER_FORCE_REG                             = 0x24050014ull;

static const uint64_t P9N2_PERV_EC05_SKITTER_FORCE_REG                             = 0x25050014ull;

static const uint64_t P9N2_PERV_EC06_SKITTER_FORCE_REG                             = 0x26050014ull;

static const uint64_t P9N2_PERV_EC07_SKITTER_FORCE_REG                             = 0x27050014ull;

static const uint64_t P9N2_PERV_EC08_SKITTER_FORCE_REG                             = 0x28050014ull;

static const uint64_t P9N2_PERV_EC09_SKITTER_FORCE_REG                             = 0x29050014ull;

static const uint64_t P9N2_PERV_EC10_SKITTER_FORCE_REG                             = 0x2A050014ull;

static const uint64_t P9N2_PERV_EC11_SKITTER_FORCE_REG                             = 0x2B050014ull;

static const uint64_t P9N2_PERV_EC12_SKITTER_FORCE_REG                             = 0x2C050014ull;

static const uint64_t P9N2_PERV_EC13_SKITTER_FORCE_REG                             = 0x2D050014ull;

static const uint64_t P9N2_PERV_EC14_SKITTER_FORCE_REG                             = 0x2E050014ull;

static const uint64_t P9N2_PERV_EC15_SKITTER_FORCE_REG                             = 0x2F050014ull;

static const uint64_t P9N2_PERV_EC16_SKITTER_FORCE_REG                             = 0x30050014ull;

static const uint64_t P9N2_PERV_EC17_SKITTER_FORCE_REG                             = 0x31050014ull;

static const uint64_t P9N2_PERV_EC18_SKITTER_FORCE_REG                             = 0x32050014ull;

static const uint64_t P9N2_PERV_EC19_SKITTER_FORCE_REG                             = 0x33050014ull;

static const uint64_t P9N2_PERV_EC20_SKITTER_FORCE_REG                             = 0x34050014ull;

static const uint64_t P9N2_PERV_EC21_SKITTER_FORCE_REG                             = 0x35050014ull;

static const uint64_t P9N2_PERV_EC22_SKITTER_FORCE_REG                             = 0x36050014ull;

static const uint64_t P9N2_PERV_EC23_SKITTER_FORCE_REG                             = 0x37050014ull;


static const uint64_t P9N2_PERV_SKITTER_MODE_REG                                   = 0x00050010ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_SKITTER_MODE_REG                                = 0x01050010ull;

static const uint64_t P9N2_PERV_N0_SKITTER_MODE_REG                                = 0x02050010ull;

static const uint64_t P9N2_PERV_N1_SKITTER_MODE_REG                                = 0x03050010ull;

static const uint64_t P9N2_PERV_N2_SKITTER_MODE_REG                                = 0x04050010ull;

static const uint64_t P9N2_PERV_N3_SKITTER_MODE_REG                                = 0x05050010ull;

static const uint64_t P9N2_PERV_XB_SKITTER_MODE_REG                                = 0x06050010ull;

static const uint64_t P9N2_PERV_MC01_SKITTER_MODE_REG                              = 0x07050010ull;

static const uint64_t P9N2_PERV_MC23_SKITTER_MODE_REG                              = 0x08050010ull;

static const uint64_t P9N2_PERV_OB0_SKITTER_MODE_REG                               = 0x09050010ull;

static const uint64_t P9N2_PERV_OB3_SKITTER_MODE_REG                               = 0x0C050010ull;

static const uint64_t P9N2_PERV_PCI0_SKITTER_MODE_REG                              = 0x0D050010ull;

static const uint64_t P9N2_PERV_PCI1_SKITTER_MODE_REG                              = 0x0E050010ull;

static const uint64_t P9N2_PERV_PCI2_SKITTER_MODE_REG                              = 0x0F050010ull;

static const uint64_t P9N2_PERV_EP00_SKITTER_MODE_REG                              = 0x10050010ull;

static const uint64_t P9N2_PERV_EP01_SKITTER_MODE_REG                              = 0x11050010ull;

static const uint64_t P9N2_PERV_EP02_SKITTER_MODE_REG                              = 0x12050010ull;

static const uint64_t P9N2_PERV_EP03_SKITTER_MODE_REG                              = 0x13050010ull;

static const uint64_t P9N2_PERV_EP04_SKITTER_MODE_REG                              = 0x14050010ull;

static const uint64_t P9N2_PERV_EP05_SKITTER_MODE_REG                              = 0x15050010ull;

static const uint64_t P9N2_PERV_EC00_SKITTER_MODE_REG                              = 0x20050010ull;

static const uint64_t P9N2_PERV_EC01_SKITTER_MODE_REG                              = 0x21050010ull;

static const uint64_t P9N2_PERV_EC02_SKITTER_MODE_REG                              = 0x22050010ull;

static const uint64_t P9N2_PERV_EC03_SKITTER_MODE_REG                              = 0x23050010ull;

static const uint64_t P9N2_PERV_EC04_SKITTER_MODE_REG                              = 0x24050010ull;

static const uint64_t P9N2_PERV_EC05_SKITTER_MODE_REG                              = 0x25050010ull;

static const uint64_t P9N2_PERV_EC06_SKITTER_MODE_REG                              = 0x26050010ull;

static const uint64_t P9N2_PERV_EC07_SKITTER_MODE_REG                              = 0x27050010ull;

static const uint64_t P9N2_PERV_EC08_SKITTER_MODE_REG                              = 0x28050010ull;

static const uint64_t P9N2_PERV_EC09_SKITTER_MODE_REG                              = 0x29050010ull;

static const uint64_t P9N2_PERV_EC10_SKITTER_MODE_REG                              = 0x2A050010ull;

static const uint64_t P9N2_PERV_EC11_SKITTER_MODE_REG                              = 0x2B050010ull;

static const uint64_t P9N2_PERV_EC12_SKITTER_MODE_REG                              = 0x2C050010ull;

static const uint64_t P9N2_PERV_EC13_SKITTER_MODE_REG                              = 0x2D050010ull;

static const uint64_t P9N2_PERV_EC14_SKITTER_MODE_REG                              = 0x2E050010ull;

static const uint64_t P9N2_PERV_EC15_SKITTER_MODE_REG                              = 0x2F050010ull;

static const uint64_t P9N2_PERV_EC16_SKITTER_MODE_REG                              = 0x30050010ull;

static const uint64_t P9N2_PERV_EC17_SKITTER_MODE_REG                              = 0x31050010ull;

static const uint64_t P9N2_PERV_EC18_SKITTER_MODE_REG                              = 0x32050010ull;

static const uint64_t P9N2_PERV_EC19_SKITTER_MODE_REG                              = 0x33050010ull;

static const uint64_t P9N2_PERV_EC20_SKITTER_MODE_REG                              = 0x34050010ull;

static const uint64_t P9N2_PERV_EC21_SKITTER_MODE_REG                              = 0x35050010ull;

static const uint64_t P9N2_PERV_EC22_SKITTER_MODE_REG                              = 0x36050010ull;

static const uint64_t P9N2_PERV_EC23_SKITTER_MODE_REG                              = 0x37050010ull;


static const uint64_t P9N2_PERV_SLAVE_CONFIG_REG                                   = 0x000F001Eull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_SLAVE_CONFIG_REG                                = 0x010F001Eull;

static const uint64_t P9N2_PERV_N0_SLAVE_CONFIG_REG                                = 0x020F001Eull;

static const uint64_t P9N2_PERV_N1_SLAVE_CONFIG_REG                                = 0x030F001Eull;

static const uint64_t P9N2_PERV_N2_SLAVE_CONFIG_REG                                = 0x040F001Eull;

static const uint64_t P9N2_PERV_N3_SLAVE_CONFIG_REG                                = 0x050F001Eull;

static const uint64_t P9N2_PERV_XB_SLAVE_CONFIG_REG                                = 0x060F001Eull;

static const uint64_t P9N2_PERV_MC01_SLAVE_CONFIG_REG                              = 0x070F001Eull;

static const uint64_t P9N2_PERV_MC23_SLAVE_CONFIG_REG                              = 0x080F001Eull;

static const uint64_t P9N2_PERV_OB0_SLAVE_CONFIG_REG                               = 0x090F001Eull;

static const uint64_t P9N2_PERV_OB3_SLAVE_CONFIG_REG                               = 0x0C0F001Eull;

static const uint64_t P9N2_PERV_PCI0_SLAVE_CONFIG_REG                              = 0x0D0F001Eull;

static const uint64_t P9N2_PERV_PCI1_SLAVE_CONFIG_REG                              = 0x0E0F001Eull;

static const uint64_t P9N2_PERV_PCI2_SLAVE_CONFIG_REG                              = 0x0F0F001Eull;

static const uint64_t P9N2_PERV_EP00_SLAVE_CONFIG_REG                              = 0x100F001Eull;

static const uint64_t P9N2_PERV_EP01_SLAVE_CONFIG_REG                              = 0x110F001Eull;

static const uint64_t P9N2_PERV_EP02_SLAVE_CONFIG_REG                              = 0x120F001Eull;

static const uint64_t P9N2_PERV_EP03_SLAVE_CONFIG_REG                              = 0x130F001Eull;

static const uint64_t P9N2_PERV_EP04_SLAVE_CONFIG_REG                              = 0x140F001Eull;

static const uint64_t P9N2_PERV_EP05_SLAVE_CONFIG_REG                              = 0x150F001Eull;

static const uint64_t P9N2_PERV_EC00_SLAVE_CONFIG_REG                              = 0x200F001Eull;

static const uint64_t P9N2_PERV_EC01_SLAVE_CONFIG_REG                              = 0x210F001Eull;

static const uint64_t P9N2_PERV_EC02_SLAVE_CONFIG_REG                              = 0x220F001Eull;

static const uint64_t P9N2_PERV_EC03_SLAVE_CONFIG_REG                              = 0x230F001Eull;

static const uint64_t P9N2_PERV_EC04_SLAVE_CONFIG_REG                              = 0x240F001Eull;

static const uint64_t P9N2_PERV_EC05_SLAVE_CONFIG_REG                              = 0x250F001Eull;

static const uint64_t P9N2_PERV_EC06_SLAVE_CONFIG_REG                              = 0x260F001Eull;

static const uint64_t P9N2_PERV_EC07_SLAVE_CONFIG_REG                              = 0x270F001Eull;

static const uint64_t P9N2_PERV_EC08_SLAVE_CONFIG_REG                              = 0x280F001Eull;

static const uint64_t P9N2_PERV_EC09_SLAVE_CONFIG_REG                              = 0x290F001Eull;

static const uint64_t P9N2_PERV_EC10_SLAVE_CONFIG_REG                              = 0x2A0F001Eull;

static const uint64_t P9N2_PERV_EC11_SLAVE_CONFIG_REG                              = 0x2B0F001Eull;

static const uint64_t P9N2_PERV_EC12_SLAVE_CONFIG_REG                              = 0x2C0F001Eull;

static const uint64_t P9N2_PERV_EC13_SLAVE_CONFIG_REG                              = 0x2D0F001Eull;

static const uint64_t P9N2_PERV_EC14_SLAVE_CONFIG_REG                              = 0x2E0F001Eull;

static const uint64_t P9N2_PERV_EC15_SLAVE_CONFIG_REG                              = 0x2F0F001Eull;

static const uint64_t P9N2_PERV_EC16_SLAVE_CONFIG_REG                              = 0x300F001Eull;

static const uint64_t P9N2_PERV_EC17_SLAVE_CONFIG_REG                              = 0x310F001Eull;

static const uint64_t P9N2_PERV_EC18_SLAVE_CONFIG_REG                              = 0x320F001Eull;

static const uint64_t P9N2_PERV_EC19_SLAVE_CONFIG_REG                              = 0x330F001Eull;

static const uint64_t P9N2_PERV_EC20_SLAVE_CONFIG_REG                              = 0x340F001Eull;

static const uint64_t P9N2_PERV_EC21_SLAVE_CONFIG_REG                              = 0x350F001Eull;

static const uint64_t P9N2_PERV_EC22_SLAVE_CONFIG_REG                              = 0x360F001Eull;

static const uint64_t P9N2_PERV_EC23_SLAVE_CONFIG_REG                              = 0x370F001Eull;


static const uint32_t P9N2_PERV_SNS1LTH_FSI                                        = 0x0000281Dull;

static const uint32_t P9N2_PERV_SNS1LTH_FSI_BYTE                                   = 0x00002874ull;

static const uint64_t P9N2_PERV_SNS1LTH_SCOM                                       = 0x0005001Dull;

static const uint64_t P9N2_PERV_PIB_SNS1LTH                                        = 0x0005001Dull;


static const uint32_t P9N2_PERV_SNS2LTH_FSI                                        = 0x0000281Eull;

static const uint32_t P9N2_PERV_SNS2LTH_FSI_BYTE                                   = 0x00002878ull;

static const uint64_t P9N2_PERV_SNS2LTH_SCOM                                       = 0x0005001Eull;

static const uint64_t P9N2_PERV_PIB_SNS2LTH                                        = 0x0005001Eull;


static const uint64_t P9N2_PERV_SPATTN_SCOM                                        = 0x00040004ull;

static const uint64_t P9N2_PERV_TP_SPATTN_SCOM                                     = 0x01040004ull;

static const uint64_t P9N2_PERV_SPATTN_SCOM1                                       = 0x00040005ull;

static const uint64_t P9N2_PERV_TP_SPATTN_SCOM1                                    = 0x01040005ull;

static const uint64_t P9N2_PERV_SPATTN_SCOM2                                       = 0x00040006ull;

static const uint64_t P9N2_PERV_TP_SPATTN_SCOM2                                    = 0x01040006ull;

static const uint64_t P9N2_PERV_N0_SPATTN_SCOM                                     = 0x02040004ull;

static const uint64_t P9N2_PERV_N0_SPATTN_SCOM1                                    = 0x02040005ull;

static const uint64_t P9N2_PERV_N0_SPATTN_SCOM2                                    = 0x02040006ull;

static const uint64_t P9N2_PERV_N1_SPATTN_SCOM                                     = 0x03040004ull;

static const uint64_t P9N2_PERV_N1_SPATTN_SCOM1                                    = 0x03040005ull;

static const uint64_t P9N2_PERV_N1_SPATTN_SCOM2                                    = 0x03040006ull;

static const uint64_t P9N2_PERV_N2_SPATTN_SCOM                                     = 0x04040004ull;

static const uint64_t P9N2_PERV_N2_SPATTN_SCOM1                                    = 0x04040005ull;

static const uint64_t P9N2_PERV_N2_SPATTN_SCOM2                                    = 0x04040006ull;

static const uint64_t P9N2_PERV_N3_SPATTN_SCOM                                     = 0x05040004ull;

static const uint64_t P9N2_PERV_N3_SPATTN_SCOM1                                    = 0x05040005ull;

static const uint64_t P9N2_PERV_N3_SPATTN_SCOM2                                    = 0x05040006ull;

static const uint64_t P9N2_PERV_XB_SPATTN_SCOM                                     = 0x06040004ull;

static const uint64_t P9N2_PERV_XB_SPATTN_SCOM1                                    = 0x06040005ull;

static const uint64_t P9N2_PERV_XB_SPATTN_SCOM2                                    = 0x06040006ull;

static const uint64_t P9N2_PERV_MC01_SPATTN_SCOM                                   = 0x07040004ull;

static const uint64_t P9N2_PERV_MC01_SPATTN_SCOM1                                  = 0x07040005ull;

static const uint64_t P9N2_PERV_MC01_SPATTN_SCOM2                                  = 0x07040006ull;

static const uint64_t P9N2_PERV_MC23_SPATTN_SCOM                                   = 0x08040004ull;

static const uint64_t P9N2_PERV_MC23_SPATTN_SCOM1                                  = 0x08040005ull;

static const uint64_t P9N2_PERV_MC23_SPATTN_SCOM2                                  = 0x08040006ull;

static const uint64_t P9N2_PERV_OB0_SPATTN_SCOM                                    = 0x09040004ull;

static const uint64_t P9N2_PERV_OB0_SPATTN_SCOM1                                   = 0x09040005ull;

static const uint64_t P9N2_PERV_OB0_SPATTN_SCOM2                                   = 0x09040006ull;

static const uint64_t P9N2_PERV_OB3_SPATTN_SCOM                                    = 0x0C040004ull;

static const uint64_t P9N2_PERV_OB3_SPATTN_SCOM1                                   = 0x0C040005ull;

static const uint64_t P9N2_PERV_OB3_SPATTN_SCOM2                                   = 0x0C040006ull;

static const uint64_t P9N2_PERV_PCI0_SPATTN_SCOM                                   = 0x0D040004ull;

static const uint64_t P9N2_PERV_PCI0_SPATTN_SCOM1                                  = 0x0D040005ull;

static const uint64_t P9N2_PERV_PCI0_SPATTN_SCOM2                                  = 0x0D040006ull;

static const uint64_t P9N2_PERV_PCI1_SPATTN_SCOM                                   = 0x0E040004ull;

static const uint64_t P9N2_PERV_PCI1_SPATTN_SCOM1                                  = 0x0E040005ull;

static const uint64_t P9N2_PERV_PCI1_SPATTN_SCOM2                                  = 0x0E040006ull;

static const uint64_t P9N2_PERV_PCI2_SPATTN_SCOM                                   = 0x0F040004ull;

static const uint64_t P9N2_PERV_PCI2_SPATTN_SCOM1                                  = 0x0F040005ull;

static const uint64_t P9N2_PERV_PCI2_SPATTN_SCOM2                                  = 0x0F040006ull;

static const uint64_t P9N2_PERV_EP00_SPATTN_SCOM                                   = 0x10040004ull;

static const uint64_t P9N2_PERV_EP00_SPATTN_SCOM1                                  = 0x10040005ull;

static const uint64_t P9N2_PERV_EP00_SPATTN_SCOM2                                  = 0x10040006ull;

static const uint64_t P9N2_PERV_EP01_SPATTN_SCOM                                   = 0x11040004ull;

static const uint64_t P9N2_PERV_EP01_SPATTN_SCOM1                                  = 0x11040005ull;

static const uint64_t P9N2_PERV_EP01_SPATTN_SCOM2                                  = 0x11040006ull;

static const uint64_t P9N2_PERV_EP02_SPATTN_SCOM                                   = 0x12040004ull;

static const uint64_t P9N2_PERV_EP02_SPATTN_SCOM1                                  = 0x12040005ull;

static const uint64_t P9N2_PERV_EP02_SPATTN_SCOM2                                  = 0x12040006ull;

static const uint64_t P9N2_PERV_EP03_SPATTN_SCOM                                   = 0x13040004ull;

static const uint64_t P9N2_PERV_EP03_SPATTN_SCOM1                                  = 0x13040005ull;

static const uint64_t P9N2_PERV_EP03_SPATTN_SCOM2                                  = 0x13040006ull;

static const uint64_t P9N2_PERV_EP04_SPATTN_SCOM                                   = 0x14040004ull;

static const uint64_t P9N2_PERV_EP04_SPATTN_SCOM1                                  = 0x14040005ull;

static const uint64_t P9N2_PERV_EP04_SPATTN_SCOM2                                  = 0x14040006ull;

static const uint64_t P9N2_PERV_EP05_SPATTN_SCOM                                   = 0x15040004ull;

static const uint64_t P9N2_PERV_EP05_SPATTN_SCOM1                                  = 0x15040005ull;

static const uint64_t P9N2_PERV_EP05_SPATTN_SCOM2                                  = 0x15040006ull;

static const uint64_t P9N2_PERV_EC00_SPATTN_SCOM                                   = 0x20040004ull;

static const uint64_t P9N2_PERV_EC00_SPATTN_SCOM1                                  = 0x20040005ull;

static const uint64_t P9N2_PERV_EC00_SPATTN_SCOM2                                  = 0x20040006ull;

static const uint64_t P9N2_PERV_EC01_SPATTN_SCOM                                   = 0x21040004ull;

static const uint64_t P9N2_PERV_EC01_SPATTN_SCOM1                                  = 0x21040005ull;

static const uint64_t P9N2_PERV_EC01_SPATTN_SCOM2                                  = 0x21040006ull;

static const uint64_t P9N2_PERV_EC02_SPATTN_SCOM                                   = 0x22040004ull;

static const uint64_t P9N2_PERV_EC02_SPATTN_SCOM1                                  = 0x22040005ull;

static const uint64_t P9N2_PERV_EC02_SPATTN_SCOM2                                  = 0x22040006ull;

static const uint64_t P9N2_PERV_EC03_SPATTN_SCOM                                   = 0x23040004ull;

static const uint64_t P9N2_PERV_EC03_SPATTN_SCOM1                                  = 0x23040005ull;

static const uint64_t P9N2_PERV_EC03_SPATTN_SCOM2                                  = 0x23040006ull;

static const uint64_t P9N2_PERV_EC04_SPATTN_SCOM                                   = 0x24040004ull;

static const uint64_t P9N2_PERV_EC04_SPATTN_SCOM1                                  = 0x24040005ull;

static const uint64_t P9N2_PERV_EC04_SPATTN_SCOM2                                  = 0x24040006ull;

static const uint64_t P9N2_PERV_EC05_SPATTN_SCOM                                   = 0x25040004ull;

static const uint64_t P9N2_PERV_EC05_SPATTN_SCOM1                                  = 0x25040005ull;

static const uint64_t P9N2_PERV_EC05_SPATTN_SCOM2                                  = 0x25040006ull;

static const uint64_t P9N2_PERV_EC06_SPATTN_SCOM                                   = 0x26040004ull;

static const uint64_t P9N2_PERV_EC06_SPATTN_SCOM1                                  = 0x26040005ull;

static const uint64_t P9N2_PERV_EC06_SPATTN_SCOM2                                  = 0x26040006ull;

static const uint64_t P9N2_PERV_EC07_SPATTN_SCOM                                   = 0x27040004ull;

static const uint64_t P9N2_PERV_EC07_SPATTN_SCOM1                                  = 0x27040005ull;

static const uint64_t P9N2_PERV_EC07_SPATTN_SCOM2                                  = 0x27040006ull;

static const uint64_t P9N2_PERV_EC08_SPATTN_SCOM                                   = 0x28040004ull;

static const uint64_t P9N2_PERV_EC08_SPATTN_SCOM1                                  = 0x28040005ull;

static const uint64_t P9N2_PERV_EC08_SPATTN_SCOM2                                  = 0x28040006ull;

static const uint64_t P9N2_PERV_EC09_SPATTN_SCOM                                   = 0x29040004ull;

static const uint64_t P9N2_PERV_EC09_SPATTN_SCOM1                                  = 0x29040005ull;

static const uint64_t P9N2_PERV_EC09_SPATTN_SCOM2                                  = 0x29040006ull;

static const uint64_t P9N2_PERV_EC10_SPATTN_SCOM                                   = 0x2A040004ull;

static const uint64_t P9N2_PERV_EC10_SPATTN_SCOM1                                  = 0x2A040005ull;

static const uint64_t P9N2_PERV_EC10_SPATTN_SCOM2                                  = 0x2A040006ull;

static const uint64_t P9N2_PERV_EC11_SPATTN_SCOM                                   = 0x2B040004ull;

static const uint64_t P9N2_PERV_EC11_SPATTN_SCOM1                                  = 0x2B040005ull;

static const uint64_t P9N2_PERV_EC11_SPATTN_SCOM2                                  = 0x2B040006ull;

static const uint64_t P9N2_PERV_EC12_SPATTN_SCOM                                   = 0x2C040004ull;

static const uint64_t P9N2_PERV_EC12_SPATTN_SCOM1                                  = 0x2C040005ull;

static const uint64_t P9N2_PERV_EC12_SPATTN_SCOM2                                  = 0x2C040006ull;

static const uint64_t P9N2_PERV_EC13_SPATTN_SCOM                                   = 0x2D040004ull;

static const uint64_t P9N2_PERV_EC13_SPATTN_SCOM1                                  = 0x2D040005ull;

static const uint64_t P9N2_PERV_EC13_SPATTN_SCOM2                                  = 0x2D040006ull;

static const uint64_t P9N2_PERV_EC14_SPATTN_SCOM                                   = 0x2E040004ull;

static const uint64_t P9N2_PERV_EC14_SPATTN_SCOM1                                  = 0x2E040005ull;

static const uint64_t P9N2_PERV_EC14_SPATTN_SCOM2                                  = 0x2E040006ull;

static const uint64_t P9N2_PERV_EC15_SPATTN_SCOM                                   = 0x2F040004ull;

static const uint64_t P9N2_PERV_EC15_SPATTN_SCOM1                                  = 0x2F040005ull;

static const uint64_t P9N2_PERV_EC15_SPATTN_SCOM2                                  = 0x2F040006ull;

static const uint64_t P9N2_PERV_EC16_SPATTN_SCOM                                   = 0x30040004ull;

static const uint64_t P9N2_PERV_EC16_SPATTN_SCOM1                                  = 0x30040005ull;

static const uint64_t P9N2_PERV_EC16_SPATTN_SCOM2                                  = 0x30040006ull;

static const uint64_t P9N2_PERV_EC17_SPATTN_SCOM                                   = 0x31040004ull;

static const uint64_t P9N2_PERV_EC17_SPATTN_SCOM1                                  = 0x31040005ull;

static const uint64_t P9N2_PERV_EC17_SPATTN_SCOM2                                  = 0x31040006ull;

static const uint64_t P9N2_PERV_EC18_SPATTN_SCOM                                   = 0x32040004ull;

static const uint64_t P9N2_PERV_EC18_SPATTN_SCOM1                                  = 0x32040005ull;

static const uint64_t P9N2_PERV_EC18_SPATTN_SCOM2                                  = 0x32040006ull;

static const uint64_t P9N2_PERV_EC19_SPATTN_SCOM                                   = 0x33040004ull;

static const uint64_t P9N2_PERV_EC19_SPATTN_SCOM1                                  = 0x33040005ull;

static const uint64_t P9N2_PERV_EC19_SPATTN_SCOM2                                  = 0x33040006ull;

static const uint64_t P9N2_PERV_EC20_SPATTN_SCOM                                   = 0x34040004ull;

static const uint64_t P9N2_PERV_EC20_SPATTN_SCOM1                                  = 0x34040005ull;

static const uint64_t P9N2_PERV_EC20_SPATTN_SCOM2                                  = 0x34040006ull;

static const uint64_t P9N2_PERV_EC21_SPATTN_SCOM                                   = 0x35040004ull;

static const uint64_t P9N2_PERV_EC21_SPATTN_SCOM1                                  = 0x35040005ull;

static const uint64_t P9N2_PERV_EC21_SPATTN_SCOM2                                  = 0x35040006ull;

static const uint64_t P9N2_PERV_EC22_SPATTN_SCOM                                   = 0x36040004ull;

static const uint64_t P9N2_PERV_EC22_SPATTN_SCOM1                                  = 0x36040005ull;

static const uint64_t P9N2_PERV_EC22_SPATTN_SCOM2                                  = 0x36040006ull;

static const uint64_t P9N2_PERV_EC23_SPATTN_SCOM                                   = 0x37040004ull;

static const uint64_t P9N2_PERV_EC23_SPATTN_SCOM1                                  = 0x37040005ull;

static const uint64_t P9N2_PERV_EC23_SPATTN_SCOM2                                  = 0x37040006ull;


static const uint64_t P9N2_PERV_SPA_MASK                                           = 0x00040007ull;

static const uint64_t P9N2_PERV_TP_SPA_MASK                                        = 0x01040007ull;

static const uint64_t P9N2_PERV_N0_SPA_MASK                                        = 0x02040007ull;

static const uint64_t P9N2_PERV_N1_SPA_MASK                                        = 0x03040007ull;

static const uint64_t P9N2_PERV_N2_SPA_MASK                                        = 0x04040007ull;

static const uint64_t P9N2_PERV_N3_SPA_MASK                                        = 0x05040007ull;

static const uint64_t P9N2_PERV_XB_SPA_MASK                                        = 0x06040007ull;

static const uint64_t P9N2_PERV_MC01_SPA_MASK                                      = 0x07040007ull;

static const uint64_t P9N2_PERV_MC23_SPA_MASK                                      = 0x08040007ull;

static const uint64_t P9N2_PERV_OB0_SPA_MASK                                       = 0x09040007ull;

static const uint64_t P9N2_PERV_OB3_SPA_MASK                                       = 0x0C040007ull;

static const uint64_t P9N2_PERV_PCI0_SPA_MASK                                      = 0x0D040007ull;

static const uint64_t P9N2_PERV_PCI1_SPA_MASK                                      = 0x0E040007ull;

static const uint64_t P9N2_PERV_PCI2_SPA_MASK                                      = 0x0F040007ull;

static const uint64_t P9N2_PERV_EP00_SPA_MASK                                      = 0x10040007ull;

static const uint64_t P9N2_PERV_EP01_SPA_MASK                                      = 0x11040007ull;

static const uint64_t P9N2_PERV_EP02_SPA_MASK                                      = 0x12040007ull;

static const uint64_t P9N2_PERV_EP03_SPA_MASK                                      = 0x13040007ull;

static const uint64_t P9N2_PERV_EP04_SPA_MASK                                      = 0x14040007ull;

static const uint64_t P9N2_PERV_EP05_SPA_MASK                                      = 0x15040007ull;

static const uint64_t P9N2_PERV_EC00_SPA_MASK                                      = 0x20040007ull;

static const uint64_t P9N2_PERV_EC01_SPA_MASK                                      = 0x21040007ull;

static const uint64_t P9N2_PERV_EC02_SPA_MASK                                      = 0x22040007ull;

static const uint64_t P9N2_PERV_EC03_SPA_MASK                                      = 0x23040007ull;

static const uint64_t P9N2_PERV_EC04_SPA_MASK                                      = 0x24040007ull;

static const uint64_t P9N2_PERV_EC05_SPA_MASK                                      = 0x25040007ull;

static const uint64_t P9N2_PERV_EC06_SPA_MASK                                      = 0x26040007ull;

static const uint64_t P9N2_PERV_EC07_SPA_MASK                                      = 0x27040007ull;

static const uint64_t P9N2_PERV_EC08_SPA_MASK                                      = 0x28040007ull;

static const uint64_t P9N2_PERV_EC09_SPA_MASK                                      = 0x29040007ull;

static const uint64_t P9N2_PERV_EC10_SPA_MASK                                      = 0x2A040007ull;

static const uint64_t P9N2_PERV_EC11_SPA_MASK                                      = 0x2B040007ull;

static const uint64_t P9N2_PERV_EC12_SPA_MASK                                      = 0x2C040007ull;

static const uint64_t P9N2_PERV_EC13_SPA_MASK                                      = 0x2D040007ull;

static const uint64_t P9N2_PERV_EC14_SPA_MASK                                      = 0x2E040007ull;

static const uint64_t P9N2_PERV_EC15_SPA_MASK                                      = 0x2F040007ull;

static const uint64_t P9N2_PERV_EC16_SPA_MASK                                      = 0x30040007ull;

static const uint64_t P9N2_PERV_EC17_SPA_MASK                                      = 0x31040007ull;

static const uint64_t P9N2_PERV_EC18_SPA_MASK                                      = 0x32040007ull;

static const uint64_t P9N2_PERV_EC19_SPA_MASK                                      = 0x33040007ull;

static const uint64_t P9N2_PERV_EC20_SPA_MASK                                      = 0x34040007ull;

static const uint64_t P9N2_PERV_EC21_SPA_MASK                                      = 0x35040007ull;

static const uint64_t P9N2_PERV_EC22_SPA_MASK                                      = 0x36040007ull;

static const uint64_t P9N2_PERV_EC23_SPA_MASK                                      = 0x37040007ull;


static const uint32_t P9N2_PERV_FSI2PIB_STATUS_FSI                                 = 0x00001007ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSI2PIB_STATUS_FSI_BYTE                            = 0x0000101Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_STATUS_FSI                                = 0x00000C07ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSISHIFT_STATUS_FSI_BYTE                           = 0x00000C1Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PERV_0_FSII2C_STATUS_REGISTER_ENGINE_A                  = 0x00001807ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint32_t P9N2_PERV_FSII2C_STATUS_REGISTER_ENGINE_A                    = 0x00001807ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PERV_STAT_RDDAT_ERRES                                   = 0x00030001ull;

static const uint64_t P9N2_PERV_PIB_STAT_RDDAT_ERRES                               = 0x00030001ull;

static const uint64_t P9N2_PERV_0_PIB2OPB0_STAT_RDDAT_ERRES                        = 0x00020001ull;

static const uint64_t P9N2_PERV_0_PIB2OPB1_STAT_RDDAT_ERRES                        = 0x00020011ull;

static const uint64_t P9N2_PERV_PIB2OPB0_STAT_RDDAT_ERRES                          = 0x00020001ull;

static const uint64_t P9N2_PERV_PIB2OPB1_STAT_RDDAT_ERRES                          = 0x00020011ull;


static const uint64_t P9N2_PERV_SUM_MASK_REG                                       = 0x00040017ull;

static const uint64_t P9N2_PERV_TP_SUM_MASK_REG                                    = 0x01040017ull;

static const uint64_t P9N2_PERV_N0_SUM_MASK_REG                                    = 0x02040017ull;

static const uint64_t P9N2_PERV_N1_SUM_MASK_REG                                    = 0x03040017ull;

static const uint64_t P9N2_PERV_N2_SUM_MASK_REG                                    = 0x04040017ull;

static const uint64_t P9N2_PERV_N3_SUM_MASK_REG                                    = 0x05040017ull;

static const uint64_t P9N2_PERV_XB_SUM_MASK_REG                                    = 0x06040017ull;

static const uint64_t P9N2_PERV_MC01_SUM_MASK_REG                                  = 0x07040017ull;

static const uint64_t P9N2_PERV_MC23_SUM_MASK_REG                                  = 0x08040017ull;

static const uint64_t P9N2_PERV_OB0_SUM_MASK_REG                                   = 0x09040017ull;

static const uint64_t P9N2_PERV_OB3_SUM_MASK_REG                                   = 0x0C040017ull;

static const uint64_t P9N2_PERV_PCI0_SUM_MASK_REG                                  = 0x0D040017ull;

static const uint64_t P9N2_PERV_PCI1_SUM_MASK_REG                                  = 0x0E040017ull;

static const uint64_t P9N2_PERV_PCI2_SUM_MASK_REG                                  = 0x0F040017ull;

static const uint64_t P9N2_PERV_EP00_SUM_MASK_REG                                  = 0x10040017ull;

static const uint64_t P9N2_PERV_EP01_SUM_MASK_REG                                  = 0x11040017ull;

static const uint64_t P9N2_PERV_EP02_SUM_MASK_REG                                  = 0x12040017ull;

static const uint64_t P9N2_PERV_EP03_SUM_MASK_REG                                  = 0x13040017ull;

static const uint64_t P9N2_PERV_EP04_SUM_MASK_REG                                  = 0x14040017ull;

static const uint64_t P9N2_PERV_EP05_SUM_MASK_REG                                  = 0x15040017ull;

static const uint64_t P9N2_PERV_EC00_SUM_MASK_REG                                  = 0x20040017ull;

static const uint64_t P9N2_PERV_EC01_SUM_MASK_REG                                  = 0x21040017ull;

static const uint64_t P9N2_PERV_EC02_SUM_MASK_REG                                  = 0x22040017ull;

static const uint64_t P9N2_PERV_EC03_SUM_MASK_REG                                  = 0x23040017ull;

static const uint64_t P9N2_PERV_EC04_SUM_MASK_REG                                  = 0x24040017ull;

static const uint64_t P9N2_PERV_EC05_SUM_MASK_REG                                  = 0x25040017ull;

static const uint64_t P9N2_PERV_EC06_SUM_MASK_REG                                  = 0x26040017ull;

static const uint64_t P9N2_PERV_EC07_SUM_MASK_REG                                  = 0x27040017ull;

static const uint64_t P9N2_PERV_EC08_SUM_MASK_REG                                  = 0x28040017ull;

static const uint64_t P9N2_PERV_EC09_SUM_MASK_REG                                  = 0x29040017ull;

static const uint64_t P9N2_PERV_EC10_SUM_MASK_REG                                  = 0x2A040017ull;

static const uint64_t P9N2_PERV_EC11_SUM_MASK_REG                                  = 0x2B040017ull;

static const uint64_t P9N2_PERV_EC12_SUM_MASK_REG                                  = 0x2C040017ull;

static const uint64_t P9N2_PERV_EC13_SUM_MASK_REG                                  = 0x2D040017ull;

static const uint64_t P9N2_PERV_EC14_SUM_MASK_REG                                  = 0x2E040017ull;

static const uint64_t P9N2_PERV_EC15_SUM_MASK_REG                                  = 0x2F040017ull;

static const uint64_t P9N2_PERV_EC16_SUM_MASK_REG                                  = 0x30040017ull;

static const uint64_t P9N2_PERV_EC17_SUM_MASK_REG                                  = 0x31040017ull;

static const uint64_t P9N2_PERV_EC18_SUM_MASK_REG                                  = 0x32040017ull;

static const uint64_t P9N2_PERV_EC19_SUM_MASK_REG                                  = 0x33040017ull;

static const uint64_t P9N2_PERV_EC20_SUM_MASK_REG                                  = 0x34040017ull;

static const uint64_t P9N2_PERV_EC21_SUM_MASK_REG                                  = 0x35040017ull;

static const uint64_t P9N2_PERV_EC22_SUM_MASK_REG                                  = 0x36040017ull;

static const uint64_t P9N2_PERV_EC23_SUM_MASK_REG                                  = 0x37040017ull;


static const uint64_t P9N2_PERV_SYNC_CONFIG                                        = 0x00030000ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_SYNC_CONFIG                                     = 0x01030000ull;

static const uint64_t P9N2_PERV_N0_SYNC_CONFIG                                     = 0x02030000ull;

static const uint64_t P9N2_PERV_N1_SYNC_CONFIG                                     = 0x03030000ull;

static const uint64_t P9N2_PERV_N2_SYNC_CONFIG                                     = 0x04030000ull;

static const uint64_t P9N2_PERV_N3_SYNC_CONFIG                                     = 0x05030000ull;

static const uint64_t P9N2_PERV_XB_SYNC_CONFIG                                     = 0x06030000ull;

static const uint64_t P9N2_PERV_MC01_SYNC_CONFIG                                   = 0x07030000ull;

static const uint64_t P9N2_PERV_MC23_SYNC_CONFIG                                   = 0x08030000ull;

static const uint64_t P9N2_PERV_OB0_SYNC_CONFIG                                    = 0x09030000ull;

static const uint64_t P9N2_PERV_OB3_SYNC_CONFIG                                    = 0x0C030000ull;

static const uint64_t P9N2_PERV_PCI0_SYNC_CONFIG                                   = 0x0D030000ull;

static const uint64_t P9N2_PERV_PCI1_SYNC_CONFIG                                   = 0x0E030000ull;

static const uint64_t P9N2_PERV_PCI2_SYNC_CONFIG                                   = 0x0F030000ull;

static const uint64_t P9N2_PERV_EP00_SYNC_CONFIG                                   = 0x10030000ull;

static const uint64_t P9N2_PERV_EP01_SYNC_CONFIG                                   = 0x11030000ull;

static const uint64_t P9N2_PERV_EP02_SYNC_CONFIG                                   = 0x12030000ull;

static const uint64_t P9N2_PERV_EP03_SYNC_CONFIG                                   = 0x13030000ull;

static const uint64_t P9N2_PERV_EP04_SYNC_CONFIG                                   = 0x14030000ull;

static const uint64_t P9N2_PERV_EP05_SYNC_CONFIG                                   = 0x15030000ull;

static const uint64_t P9N2_PERV_EC00_SYNC_CONFIG                                   = 0x20030000ull;

static const uint64_t P9N2_PERV_EC01_SYNC_CONFIG                                   = 0x21030000ull;

static const uint64_t P9N2_PERV_EC02_SYNC_CONFIG                                   = 0x22030000ull;

static const uint64_t P9N2_PERV_EC03_SYNC_CONFIG                                   = 0x23030000ull;

static const uint64_t P9N2_PERV_EC04_SYNC_CONFIG                                   = 0x24030000ull;

static const uint64_t P9N2_PERV_EC05_SYNC_CONFIG                                   = 0x25030000ull;

static const uint64_t P9N2_PERV_EC06_SYNC_CONFIG                                   = 0x26030000ull;

static const uint64_t P9N2_PERV_EC07_SYNC_CONFIG                                   = 0x27030000ull;

static const uint64_t P9N2_PERV_EC08_SYNC_CONFIG                                   = 0x28030000ull;

static const uint64_t P9N2_PERV_EC09_SYNC_CONFIG                                   = 0x29030000ull;

static const uint64_t P9N2_PERV_EC10_SYNC_CONFIG                                   = 0x2A030000ull;

static const uint64_t P9N2_PERV_EC11_SYNC_CONFIG                                   = 0x2B030000ull;

static const uint64_t P9N2_PERV_EC12_SYNC_CONFIG                                   = 0x2C030000ull;

static const uint64_t P9N2_PERV_EC13_SYNC_CONFIG                                   = 0x2D030000ull;

static const uint64_t P9N2_PERV_EC14_SYNC_CONFIG                                   = 0x2E030000ull;

static const uint64_t P9N2_PERV_EC15_SYNC_CONFIG                                   = 0x2F030000ull;

static const uint64_t P9N2_PERV_EC16_SYNC_CONFIG                                   = 0x30030000ull;

static const uint64_t P9N2_PERV_EC17_SYNC_CONFIG                                   = 0x31030000ull;

static const uint64_t P9N2_PERV_EC18_SYNC_CONFIG                                   = 0x32030000ull;

static const uint64_t P9N2_PERV_EC19_SYNC_CONFIG                                   = 0x33030000ull;

static const uint64_t P9N2_PERV_EC20_SYNC_CONFIG                                   = 0x34030000ull;

static const uint64_t P9N2_PERV_EC21_SYNC_CONFIG                                   = 0x35030000ull;

static const uint64_t P9N2_PERV_EC22_SYNC_CONFIG                                   = 0x36030000ull;

static const uint64_t P9N2_PERV_EC23_SYNC_CONFIG                                   = 0x37030000ull;


static const uint64_t P9N2_PERV_THERM_MODE_REG                                     = 0x0005000Full;

static const uint64_t P9N2_PERV_TP_THERM_MODE_REG                                  = 0x0105000Full;

static const uint64_t P9N2_PERV_N0_THERM_MODE_REG                                  = 0x0205000Full;

static const uint64_t P9N2_PERV_N1_THERM_MODE_REG                                  = 0x0305000Full;

static const uint64_t P9N2_PERV_N2_THERM_MODE_REG                                  = 0x0405000Full;

static const uint64_t P9N2_PERV_N3_THERM_MODE_REG                                  = 0x0505000Full;

static const uint64_t P9N2_PERV_XB_THERM_MODE_REG                                  = 0x0605000Full;

static const uint64_t P9N2_PERV_MC01_THERM_MODE_REG                                = 0x0705000Full;

static const uint64_t P9N2_PERV_MC23_THERM_MODE_REG                                = 0x0805000Full;

static const uint64_t P9N2_PERV_OB0_THERM_MODE_REG                                 = 0x0905000Full;

static const uint64_t P9N2_PERV_OB3_THERM_MODE_REG                                 = 0x0C05000Full;

static const uint64_t P9N2_PERV_PCI0_THERM_MODE_REG                                = 0x0D05000Full;

static const uint64_t P9N2_PERV_PCI1_THERM_MODE_REG                                = 0x0E05000Full;

static const uint64_t P9N2_PERV_PCI2_THERM_MODE_REG                                = 0x0F05000Full;

static const uint64_t P9N2_PERV_EP00_THERM_MODE_REG                                = 0x1005000Full;

static const uint64_t P9N2_PERV_EP01_THERM_MODE_REG                                = 0x1105000Full;

static const uint64_t P9N2_PERV_EP02_THERM_MODE_REG                                = 0x1205000Full;

static const uint64_t P9N2_PERV_EP03_THERM_MODE_REG                                = 0x1305000Full;

static const uint64_t P9N2_PERV_EP04_THERM_MODE_REG                                = 0x1405000Full;

static const uint64_t P9N2_PERV_EP05_THERM_MODE_REG                                = 0x1505000Full;

static const uint64_t P9N2_PERV_EC00_THERM_MODE_REG                                = 0x2005000Full;

static const uint64_t P9N2_PERV_EC01_THERM_MODE_REG                                = 0x2105000Full;

static const uint64_t P9N2_PERV_EC02_THERM_MODE_REG                                = 0x2205000Full;

static const uint64_t P9N2_PERV_EC03_THERM_MODE_REG                                = 0x2305000Full;

static const uint64_t P9N2_PERV_EC04_THERM_MODE_REG                                = 0x2405000Full;

static const uint64_t P9N2_PERV_EC05_THERM_MODE_REG                                = 0x2505000Full;

static const uint64_t P9N2_PERV_EC06_THERM_MODE_REG                                = 0x2605000Full;

static const uint64_t P9N2_PERV_EC07_THERM_MODE_REG                                = 0x2705000Full;

static const uint64_t P9N2_PERV_EC08_THERM_MODE_REG                                = 0x2805000Full;

static const uint64_t P9N2_PERV_EC09_THERM_MODE_REG                                = 0x2905000Full;

static const uint64_t P9N2_PERV_EC10_THERM_MODE_REG                                = 0x2A05000Full;

static const uint64_t P9N2_PERV_EC11_THERM_MODE_REG                                = 0x2B05000Full;

static const uint64_t P9N2_PERV_EC12_THERM_MODE_REG                                = 0x2C05000Full;

static const uint64_t P9N2_PERV_EC13_THERM_MODE_REG                                = 0x2D05000Full;

static const uint64_t P9N2_PERV_EC14_THERM_MODE_REG                                = 0x2E05000Full;

static const uint64_t P9N2_PERV_EC15_THERM_MODE_REG                                = 0x2F05000Full;

static const uint64_t P9N2_PERV_EC16_THERM_MODE_REG                                = 0x3005000Full;

static const uint64_t P9N2_PERV_EC17_THERM_MODE_REG                                = 0x3105000Full;

static const uint64_t P9N2_PERV_EC18_THERM_MODE_REG                                = 0x3205000Full;

static const uint64_t P9N2_PERV_EC19_THERM_MODE_REG                                = 0x3305000Full;

static const uint64_t P9N2_PERV_EC20_THERM_MODE_REG                                = 0x3405000Full;

static const uint64_t P9N2_PERV_EC21_THERM_MODE_REG                                = 0x3505000Full;

static const uint64_t P9N2_PERV_EC22_THERM_MODE_REG                                = 0x3605000Full;

static const uint64_t P9N2_PERV_EC23_THERM_MODE_REG                                = 0x3705000Full;


static const uint64_t P9N2_PERV_TIMEOUT_REG                                        = 0x000F0019ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_TIMEOUT_REG                                    = 0x000F0019ull;

static const uint64_t P9N2_PERV_TP_TIMEOUT_REG                                     = 0x010F0010ull;

static const uint64_t P9N2_PERV_N0_TIMEOUT_REG                                     = 0x020F0010ull;

static const uint64_t P9N2_PERV_N1_TIMEOUT_REG                                     = 0x030F0010ull;

static const uint64_t P9N2_PERV_N2_TIMEOUT_REG                                     = 0x040F0010ull;

static const uint64_t P9N2_PERV_N3_TIMEOUT_REG                                     = 0x050F0010ull;

static const uint64_t P9N2_PERV_XB_TIMEOUT_REG                                     = 0x060F0010ull;

static const uint64_t P9N2_PERV_MC01_TIMEOUT_REG                                   = 0x070F0010ull;

static const uint64_t P9N2_PERV_MC23_TIMEOUT_REG                                   = 0x080F0010ull;

static const uint64_t P9N2_PERV_OB0_TIMEOUT_REG                                    = 0x090F0010ull;

static const uint64_t P9N2_PERV_OB3_TIMEOUT_REG                                    = 0x0C0F0010ull;

static const uint64_t P9N2_PERV_PCI0_TIMEOUT_REG                                   = 0x0D0F0010ull;

static const uint64_t P9N2_PERV_PCI1_TIMEOUT_REG                                   = 0x0E0F0010ull;

static const uint64_t P9N2_PERV_PCI2_TIMEOUT_REG                                   = 0x0F0F0010ull;

static const uint64_t P9N2_PERV_EP00_TIMEOUT_REG                                   = 0x100F0010ull;

static const uint64_t P9N2_PERV_EP01_TIMEOUT_REG                                   = 0x110F0010ull;

static const uint64_t P9N2_PERV_EP02_TIMEOUT_REG                                   = 0x120F0010ull;

static const uint64_t P9N2_PERV_EP03_TIMEOUT_REG                                   = 0x130F0010ull;

static const uint64_t P9N2_PERV_EP04_TIMEOUT_REG                                   = 0x140F0010ull;

static const uint64_t P9N2_PERV_EP05_TIMEOUT_REG                                   = 0x150F0010ull;

static const uint64_t P9N2_PERV_EC00_TIMEOUT_REG                                   = 0x200F0010ull;

static const uint64_t P9N2_PERV_EC01_TIMEOUT_REG                                   = 0x210F0010ull;

static const uint64_t P9N2_PERV_EC02_TIMEOUT_REG                                   = 0x220F0010ull;

static const uint64_t P9N2_PERV_EC03_TIMEOUT_REG                                   = 0x230F0010ull;

static const uint64_t P9N2_PERV_EC04_TIMEOUT_REG                                   = 0x240F0010ull;

static const uint64_t P9N2_PERV_EC05_TIMEOUT_REG                                   = 0x250F0010ull;

static const uint64_t P9N2_PERV_EC06_TIMEOUT_REG                                   = 0x260F0010ull;

static const uint64_t P9N2_PERV_EC07_TIMEOUT_REG                                   = 0x270F0010ull;

static const uint64_t P9N2_PERV_EC08_TIMEOUT_REG                                   = 0x280F0010ull;

static const uint64_t P9N2_PERV_EC09_TIMEOUT_REG                                   = 0x290F0010ull;

static const uint64_t P9N2_PERV_EC10_TIMEOUT_REG                                   = 0x2A0F0010ull;

static const uint64_t P9N2_PERV_EC11_TIMEOUT_REG                                   = 0x2B0F0010ull;

static const uint64_t P9N2_PERV_EC12_TIMEOUT_REG                                   = 0x2C0F0010ull;

static const uint64_t P9N2_PERV_EC13_TIMEOUT_REG                                   = 0x2D0F0010ull;

static const uint64_t P9N2_PERV_EC14_TIMEOUT_REG                                   = 0x2E0F0010ull;

static const uint64_t P9N2_PERV_EC15_TIMEOUT_REG                                   = 0x2F0F0010ull;

static const uint64_t P9N2_PERV_EC16_TIMEOUT_REG                                   = 0x300F0010ull;

static const uint64_t P9N2_PERV_EC17_TIMEOUT_REG                                   = 0x310F0010ull;

static const uint64_t P9N2_PERV_EC18_TIMEOUT_REG                                   = 0x320F0010ull;

static const uint64_t P9N2_PERV_EC19_TIMEOUT_REG                                   = 0x330F0010ull;

static const uint64_t P9N2_PERV_EC20_TIMEOUT_REG                                   = 0x340F0010ull;

static const uint64_t P9N2_PERV_EC21_TIMEOUT_REG                                   = 0x350F0010ull;

static const uint64_t P9N2_PERV_EC22_TIMEOUT_REG                                   = 0x360F0010ull;

static const uint64_t P9N2_PERV_EC23_TIMEOUT_REG                                   = 0x370F0010ull;


static const uint64_t P9N2_PERV_TIMESTAMP_COUNTER_READ                             = 0x0005001Cull;

static const uint64_t P9N2_PERV_TP_TIMESTAMP_COUNTER_READ                          = 0x0105001Cull;

static const uint64_t P9N2_PERV_N0_TIMESTAMP_COUNTER_READ                          = 0x0205001Cull;

static const uint64_t P9N2_PERV_N1_TIMESTAMP_COUNTER_READ                          = 0x0305001Cull;

static const uint64_t P9N2_PERV_N2_TIMESTAMP_COUNTER_READ                          = 0x0405001Cull;

static const uint64_t P9N2_PERV_N3_TIMESTAMP_COUNTER_READ                          = 0x0505001Cull;

static const uint64_t P9N2_PERV_XB_TIMESTAMP_COUNTER_READ                          = 0x0605001Cull;

static const uint64_t P9N2_PERV_MC01_TIMESTAMP_COUNTER_READ                        = 0x0705001Cull;

static const uint64_t P9N2_PERV_MC23_TIMESTAMP_COUNTER_READ                        = 0x0805001Cull;

static const uint64_t P9N2_PERV_OB0_TIMESTAMP_COUNTER_READ                         = 0x0905001Cull;

static const uint64_t P9N2_PERV_OB3_TIMESTAMP_COUNTER_READ                         = 0x0C05001Cull;

static const uint64_t P9N2_PERV_PCI0_TIMESTAMP_COUNTER_READ                        = 0x0D05001Cull;

static const uint64_t P9N2_PERV_PCI1_TIMESTAMP_COUNTER_READ                        = 0x0E05001Cull;

static const uint64_t P9N2_PERV_PCI2_TIMESTAMP_COUNTER_READ                        = 0x0F05001Cull;

static const uint64_t P9N2_PERV_EP00_TIMESTAMP_COUNTER_READ                        = 0x1005001Cull;

static const uint64_t P9N2_PERV_EP01_TIMESTAMP_COUNTER_READ                        = 0x1105001Cull;

static const uint64_t P9N2_PERV_EP02_TIMESTAMP_COUNTER_READ                        = 0x1205001Cull;

static const uint64_t P9N2_PERV_EP03_TIMESTAMP_COUNTER_READ                        = 0x1305001Cull;

static const uint64_t P9N2_PERV_EP04_TIMESTAMP_COUNTER_READ                        = 0x1405001Cull;

static const uint64_t P9N2_PERV_EP05_TIMESTAMP_COUNTER_READ                        = 0x1505001Cull;

static const uint64_t P9N2_PERV_EC00_TIMESTAMP_COUNTER_READ                        = 0x2005001Cull;

static const uint64_t P9N2_PERV_EC01_TIMESTAMP_COUNTER_READ                        = 0x2105001Cull;

static const uint64_t P9N2_PERV_EC02_TIMESTAMP_COUNTER_READ                        = 0x2205001Cull;

static const uint64_t P9N2_PERV_EC03_TIMESTAMP_COUNTER_READ                        = 0x2305001Cull;

static const uint64_t P9N2_PERV_EC04_TIMESTAMP_COUNTER_READ                        = 0x2405001Cull;

static const uint64_t P9N2_PERV_EC05_TIMESTAMP_COUNTER_READ                        = 0x2505001Cull;

static const uint64_t P9N2_PERV_EC06_TIMESTAMP_COUNTER_READ                        = 0x2605001Cull;

static const uint64_t P9N2_PERV_EC07_TIMESTAMP_COUNTER_READ                        = 0x2705001Cull;

static const uint64_t P9N2_PERV_EC08_TIMESTAMP_COUNTER_READ                        = 0x2805001Cull;

static const uint64_t P9N2_PERV_EC09_TIMESTAMP_COUNTER_READ                        = 0x2905001Cull;

static const uint64_t P9N2_PERV_EC10_TIMESTAMP_COUNTER_READ                        = 0x2A05001Cull;

static const uint64_t P9N2_PERV_EC11_TIMESTAMP_COUNTER_READ                        = 0x2B05001Cull;

static const uint64_t P9N2_PERV_EC12_TIMESTAMP_COUNTER_READ                        = 0x2C05001Cull;

static const uint64_t P9N2_PERV_EC13_TIMESTAMP_COUNTER_READ                        = 0x2D05001Cull;

static const uint64_t P9N2_PERV_EC14_TIMESTAMP_COUNTER_READ                        = 0x2E05001Cull;

static const uint64_t P9N2_PERV_EC15_TIMESTAMP_COUNTER_READ                        = 0x2F05001Cull;

static const uint64_t P9N2_PERV_EC16_TIMESTAMP_COUNTER_READ                        = 0x3005001Cull;

static const uint64_t P9N2_PERV_EC17_TIMESTAMP_COUNTER_READ                        = 0x3105001Cull;

static const uint64_t P9N2_PERV_EC18_TIMESTAMP_COUNTER_READ                        = 0x3205001Cull;

static const uint64_t P9N2_PERV_EC19_TIMESTAMP_COUNTER_READ                        = 0x3305001Cull;

static const uint64_t P9N2_PERV_EC20_TIMESTAMP_COUNTER_READ                        = 0x3405001Cull;

static const uint64_t P9N2_PERV_EC21_TIMESTAMP_COUNTER_READ                        = 0x3505001Cull;

static const uint64_t P9N2_PERV_EC22_TIMESTAMP_COUNTER_READ                        = 0x3605001Cull;

static const uint64_t P9N2_PERV_EC23_TIMESTAMP_COUNTER_READ                        = 0x3705001Cull;


static const uint64_t P9N2_PERV_TOD_CHIP_CTRL_REG                                  = 0x00040010ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_TOD_CHIP_CTRL_REG                              = 0x00040010ull;


static const uint64_t P9N2_PERV_TOD_ERROR_INJECT_REG                               = 0x00040031ull;

static const uint64_t P9N2_PERV_PIB_TOD_ERROR_INJECT_REG                           = 0x00040031ull;


static const uint64_t P9N2_PERV_TOD_ERROR_MASK_REG                                 = 0x00040032ull;

static const uint64_t P9N2_PERV_PIB_TOD_ERROR_MASK_REG                             = 0x00040032ull;


static const uint64_t P9N2_PERV_TOD_ERROR_REG                                      = 0x00040030ull;

static const uint64_t P9N2_PERV_PIB_TOD_ERROR_REG                                  = 0x00040030ull;


static const uint64_t P9N2_PERV_TOD_ERROR_ROUTING_REG                              = 0x00040033ull;

static const uint64_t P9N2_PERV_PIB_TOD_ERROR_ROUTING_REG                          = 0x00040033ull;


static const uint64_t P9N2_PERV_TOD_FSM_REG                                        = 0x00040024ull;

static const uint64_t P9N2_PERV_PIB_TOD_FSM_REG                                    = 0x00040024ull;


static const uint64_t P9N2_PERV_TOD_I_PATH_CTRL_REG                                = 0x00040006ull;

static const uint64_t P9N2_PERV_PIB_TOD_I_PATH_CTRL_REG                            = 0x00040006ull;


static const uint64_t P9N2_PERV_TOD_LOAD_TOD_MOD_REG                               = 0x00040018ull;

static const uint64_t P9N2_PERV_PIB_TOD_LOAD_TOD_MOD_REG                           = 0x00040018ull;


static const uint64_t P9N2_PERV_TOD_LOAD_TOD_REG                                   = 0x00040021ull;

static const uint64_t P9N2_PERV_PIB_TOD_LOAD_TOD_REG                               = 0x00040021ull;


static const uint64_t P9N2_PERV_TOD_LOW_ORDER_STEP_REG                             = 0x00040023ull;

static const uint64_t P9N2_PERV_PIB_TOD_LOW_ORDER_STEP_REG                         = 0x00040023ull;


static const uint64_t P9N2_PERV_TOD_MISC_RESET_REG                                 = 0x0004000Bull;

static const uint64_t P9N2_PERV_PIB_TOD_MISC_RESET_REG                             = 0x0004000Bull;


static const uint64_t P9N2_PERV_TOD_MOVE_TOD_TO_TB_REG                             = 0x00040017ull;

static const uint64_t P9N2_PERV_PIB_TOD_MOVE_TOD_TO_TB_REG                         = 0x00040017ull;


static const uint64_t P9N2_PERV_TOD_M_PATH_0_STEP_STEER_REG                        = 0x0004000Eull;

static const uint64_t P9N2_PERV_PIB_TOD_M_PATH_0_STEP_STEER_REG                    = 0x0004000Eull;


static const uint64_t P9N2_PERV_TOD_M_PATH_1_STEP_STEER_REG                        = 0x0004000Full;

static const uint64_t P9N2_PERV_PIB_TOD_M_PATH_1_STEP_STEER_REG                    = 0x0004000Full;


static const uint64_t P9N2_PERV_TOD_M_PATH_CTRL_REG                                = 0x00040000ull;

static const uint64_t P9N2_PERV_PIB_TOD_M_PATH_CTRL_REG                            = 0x00040000ull;


static const uint64_t P9N2_PERV_TOD_M_PATH_STATUS_REG                              = 0x00040009ull;

static const uint64_t P9N2_PERV_PIB_TOD_M_PATH_STATUS_REG                          = 0x00040009ull;


static const uint64_t P9N2_PERV_TOD_PRI_PORT_0_CTRL_REG                            = 0x00040001ull;

static const uint64_t P9N2_PERV_PIB_TOD_PRI_PORT_0_CTRL_REG                        = 0x00040001ull;


static const uint64_t P9N2_PERV_TOD_PRI_PORT_1_CTRL_REG                            = 0x00040002ull;

static const uint64_t P9N2_PERV_PIB_TOD_PRI_PORT_1_CTRL_REG                        = 0x00040002ull;


static const uint64_t P9N2_PERV_TOD_PROBE_SELECT_REG                               = 0x0004000Cull;

static const uint64_t P9N2_PERV_PIB_TOD_PROBE_SELECT_REG                           = 0x0004000Cull;


static const uint64_t P9N2_PERV_TOD_PSS_MSS_CTRL_REG                               = 0x00040007ull;

static const uint64_t P9N2_PERV_PIB_TOD_PSS_MSS_CTRL_REG                           = 0x00040007ull;


static const uint64_t P9N2_PERV_TOD_PSS_MSS_STATUS_REG                             = 0x00040008ull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_TOD_PSS_MSS_STATUS_REG                         = 0x00040008ull;


static const uint64_t P9N2_PERV_TOD_RX_TTYPE_CTRL_REG                              = 0x00040029ull;

static const uint64_t P9N2_PERV_PIB_TOD_RX_TTYPE_CTRL_REG                          = 0x00040029ull;


static const uint64_t P9N2_PERV_TOD_SEC_PORT_0_CTRL_REG                            = 0x00040003ull;

static const uint64_t P9N2_PERV_PIB_TOD_SEC_PORT_0_CTRL_REG                        = 0x00040003ull;


static const uint64_t P9N2_PERV_TOD_SEC_PORT_1_CTRL_REG                            = 0x00040004ull;

static const uint64_t P9N2_PERV_PIB_TOD_SEC_PORT_1_CTRL_REG                        = 0x00040004ull;


static const uint64_t P9N2_PERV_TOD_START_TOD_REG                                  = 0x00040022ull;

static const uint64_t P9N2_PERV_PIB_TOD_START_TOD_REG                              = 0x00040022ull;


static const uint64_t P9N2_PERV_TOD_S_PATH_CTRL_REG                                = 0x00040005ull;

static const uint64_t P9N2_PERV_PIB_TOD_S_PATH_CTRL_REG                            = 0x00040005ull;


static const uint64_t P9N2_PERV_TOD_S_PATH_STATUS_REG                              = 0x0004000Aull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_PIB_TOD_S_PATH_STATUS_REG                          = 0x0004000Aull;


static const uint64_t P9N2_PERV_TOD_TIMER_REG                                      = 0x0004000Dull;

static const uint64_t P9N2_PERV_PIB_TOD_TIMER_REG                                  = 0x0004000Dull;


static const uint64_t P9N2_PERV_TOD_TRACE_DATA_1_REG                               = 0x0004001Dull;

static const uint64_t P9N2_PERV_PIB_TOD_TRACE_DATA_1_REG                           = 0x0004001Dull;


static const uint64_t P9N2_PERV_TOD_TRACE_DATA_2_REG                               = 0x0004001Eull;

static const uint64_t P9N2_PERV_PIB_TOD_TRACE_DATA_2_REG                           = 0x0004001Eull;


static const uint64_t P9N2_PERV_TOD_TRACE_DATA_3_REG                               = 0x0004001Full;

static const uint64_t P9N2_PERV_PIB_TOD_TRACE_DATA_3_REG                           = 0x0004001Full;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_0_REG                                 = 0x00040011ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_0_REG                             = 0x00040011ull;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_1_REG                                 = 0x00040012ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_1_REG                             = 0x00040012ull;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_2_REG                                 = 0x00040013ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_2_REG                             = 0x00040013ull;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_3_REG                                 = 0x00040014ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_3_REG                             = 0x00040014ull;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_4_REG                                 = 0x00040015ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_4_REG                             = 0x00040015ull;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_5_REG                                 = 0x00040016ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_5_REG                             = 0x00040016ull;


static const uint64_t P9N2_PERV_TOD_TX_TTYPE_CTRL_REG                              = 0x00040027ull;

static const uint64_t P9N2_PERV_PIB_TOD_TX_TTYPE_CTRL_REG                          = 0x00040027ull;


static const uint64_t P9N2_PERV_TOD_VALUE_REG                                      = 0x00040020ull;

static const uint64_t P9N2_PERV_PIB_TOD_VALUE_REG                                  = 0x00040020ull;


static const uint64_t P9N2_PERV_TRACE_HI_DATA_REG                                  = 0x00010440ull;

static const uint64_t P9N2_PERV_TP_TRACE_HI_DATA_REG                               = 0x01010400ull;
//DUPS: 01010400,

static const uint64_t P9N2_PERV_TRACE_LO_DATA_REG                                  = 0x00010441ull;

static const uint64_t P9N2_PERV_TP_TRACE_LO_DATA_REG                               = 0x01010401ull;
//DUPS: 01010401,

static const uint64_t P9N2_PERV_TRACE_TRCTRL_CONFIG                                = 0x00010442ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRCTRL_CONFIG                             = 0x01010402ull;
//DUPS: 01010402,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_0                              = 0x00010443ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_0                           = 0x01010403ull;
//DUPS: 01010403,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_1                              = 0x00010444ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_1                           = 0x01010404ull;
//DUPS: 01010404,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_2                              = 0x00010445ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_2                           = 0x01010405ull;
//DUPS: 01010405,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_3                              = 0x00010446ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_3                           = 0x01010406ull;
//DUPS: 01010406,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_4                              = 0x00010447ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_4                           = 0x01010407ull;
//DUPS: 01010407,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_5                              = 0x00010448ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_5                           = 0x01010408ull;
//DUPS: 01010408,

static const uint64_t P9N2_PERV_TRACE_TRDATA_CONFIG_9                              = 0x00010449ull;

static const uint64_t P9N2_PERV_TP_TRACE_TRDATA_CONFIG_9                           = 0x01010409ull;
//DUPS: 01010409,

static const uint32_t P9N2_PERV_FSI2PIB_TRUE_MASK_FSI                              = 0x0000100Dull;

static const uint32_t P9N2_PERV_FSI2PIB_TRUE_MASK_FSI_BYTE                         = 0x00001034ull;

static const uint32_t P9N2_PERV_FSISHIFT_TRUE_MASK_FSI                             = 0x00000C0Dull;

static const uint32_t P9N2_PERV_FSISHIFT_TRUE_MASK_FSI_BYTE                        = 0x00000C34ull;


static const uint64_t P9N2_PERV_VITAL_SCAN_OUT                                     = 0x000F0017ull;

static const uint64_t P9N2_PERV_TP_VITAL_SCAN_OUT                                  = 0x010F0017ull;

static const uint64_t P9N2_PERV_N0_VITAL_SCAN_OUT                                  = 0x020F0017ull;

static const uint64_t P9N2_PERV_N1_VITAL_SCAN_OUT                                  = 0x030F0017ull;

static const uint64_t P9N2_PERV_N2_VITAL_SCAN_OUT                                  = 0x040F0017ull;

static const uint64_t P9N2_PERV_N3_VITAL_SCAN_OUT                                  = 0x050F0017ull;

static const uint64_t P9N2_PERV_XB_VITAL_SCAN_OUT                                  = 0x060F0017ull;

static const uint64_t P9N2_PERV_MC01_VITAL_SCAN_OUT                                = 0x070F0017ull;

static const uint64_t P9N2_PERV_MC23_VITAL_SCAN_OUT                                = 0x080F0017ull;

static const uint64_t P9N2_PERV_OB0_VITAL_SCAN_OUT                                 = 0x090F0017ull;

static const uint64_t P9N2_PERV_OB3_VITAL_SCAN_OUT                                 = 0x0C0F0017ull;

static const uint64_t P9N2_PERV_PCI0_VITAL_SCAN_OUT                                = 0x0D0F0017ull;

static const uint64_t P9N2_PERV_PCI1_VITAL_SCAN_OUT                                = 0x0E0F0017ull;

static const uint64_t P9N2_PERV_PCI2_VITAL_SCAN_OUT                                = 0x0F0F0017ull;

static const uint64_t P9N2_PERV_EP00_VITAL_SCAN_OUT                                = 0x100F0017ull;

static const uint64_t P9N2_PERV_EP01_VITAL_SCAN_OUT                                = 0x110F0017ull;

static const uint64_t P9N2_PERV_EP02_VITAL_SCAN_OUT                                = 0x120F0017ull;

static const uint64_t P9N2_PERV_EP03_VITAL_SCAN_OUT                                = 0x130F0017ull;

static const uint64_t P9N2_PERV_EP04_VITAL_SCAN_OUT                                = 0x140F0017ull;

static const uint64_t P9N2_PERV_EP05_VITAL_SCAN_OUT                                = 0x150F0017ull;

static const uint64_t P9N2_PERV_EC00_VITAL_SCAN_OUT                                = 0x200F0017ull;

static const uint64_t P9N2_PERV_EC01_VITAL_SCAN_OUT                                = 0x210F0017ull;

static const uint64_t P9N2_PERV_EC02_VITAL_SCAN_OUT                                = 0x220F0017ull;

static const uint64_t P9N2_PERV_EC03_VITAL_SCAN_OUT                                = 0x230F0017ull;

static const uint64_t P9N2_PERV_EC04_VITAL_SCAN_OUT                                = 0x240F0017ull;

static const uint64_t P9N2_PERV_EC05_VITAL_SCAN_OUT                                = 0x250F0017ull;

static const uint64_t P9N2_PERV_EC06_VITAL_SCAN_OUT                                = 0x260F0017ull;

static const uint64_t P9N2_PERV_EC07_VITAL_SCAN_OUT                                = 0x270F0017ull;

static const uint64_t P9N2_PERV_EC08_VITAL_SCAN_OUT                                = 0x280F0017ull;

static const uint64_t P9N2_PERV_EC09_VITAL_SCAN_OUT                                = 0x290F0017ull;

static const uint64_t P9N2_PERV_EC10_VITAL_SCAN_OUT                                = 0x2A0F0017ull;

static const uint64_t P9N2_PERV_EC11_VITAL_SCAN_OUT                                = 0x2B0F0017ull;

static const uint64_t P9N2_PERV_EC12_VITAL_SCAN_OUT                                = 0x2C0F0017ull;

static const uint64_t P9N2_PERV_EC13_VITAL_SCAN_OUT                                = 0x2D0F0017ull;

static const uint64_t P9N2_PERV_EC14_VITAL_SCAN_OUT                                = 0x2E0F0017ull;

static const uint64_t P9N2_PERV_EC15_VITAL_SCAN_OUT                                = 0x2F0F0017ull;

static const uint64_t P9N2_PERV_EC16_VITAL_SCAN_OUT                                = 0x300F0017ull;

static const uint64_t P9N2_PERV_EC17_VITAL_SCAN_OUT                                = 0x310F0017ull;

static const uint64_t P9N2_PERV_EC18_VITAL_SCAN_OUT                                = 0x320F0017ull;

static const uint64_t P9N2_PERV_EC19_VITAL_SCAN_OUT                                = 0x330F0017ull;

static const uint64_t P9N2_PERV_EC20_VITAL_SCAN_OUT                                = 0x340F0017ull;

static const uint64_t P9N2_PERV_EC21_VITAL_SCAN_OUT                                = 0x350F0017ull;

static const uint64_t P9N2_PERV_EC22_VITAL_SCAN_OUT                                = 0x360F0017ull;

static const uint64_t P9N2_PERV_EC23_VITAL_SCAN_OUT                                = 0x370F0017ull;


static const uint64_t P9N2_PERV_VMEAS_RESULT_REG                                   = 0x00020006ull;

static const uint64_t P9N2_PERV_TP_VMEAS_RESULT_REG                                = 0x01020006ull;


static const uint64_t P9N2_PERV_0_FSII2C_WATER_MARK_REGISTER_A                     = 0x00001803ull;

static const uint32_t P9N2_PERV_FSII2C_WATER_MARK_REGISTER_A                       = 0x00001803ull;


static const uint64_t P9N2_PERV_WRITE_PROTECT_ENABLE_REG                           = 0x00010005ull;

static const uint64_t P9N2_PERV_TP_WRITE_PROTECT_ENABLE_REG                        = 0x01010005ull;


static const uint64_t P9N2_PERV_WRITE_PROTECT_RINGS_REG                            = 0x00010006ull;

static const uint64_t P9N2_PERV_TP_WRITE_PROTECT_RINGS_REG                         = 0x01010006ull;


static const uint64_t P9N2_PERV_XFIR                                               = 0x00040000ull;

static const uint64_t P9N2_PERV_TP_XFIR                                            = 0x01040000ull;

static const uint64_t P9N2_PERV_N0_XFIR                                            = 0x02040000ull;

static const uint64_t P9N2_PERV_N1_XFIR                                            = 0x03040000ull;

static const uint64_t P9N2_PERV_N2_XFIR                                            = 0x04040000ull;

static const uint64_t P9N2_PERV_N3_XFIR                                            = 0x05040000ull;

static const uint64_t P9N2_PERV_XB_XFIR                                            = 0x06040000ull;

static const uint64_t P9N2_PERV_MC01_XFIR                                          = 0x07040000ull;

static const uint64_t P9N2_PERV_MC23_XFIR                                          = 0x08040000ull;

static const uint64_t P9N2_PERV_OB0_XFIR                                           = 0x09040000ull;

static const uint64_t P9N2_PERV_OB3_XFIR                                           = 0x0C040000ull;

static const uint64_t P9N2_PERV_PCI0_XFIR                                          = 0x0D040000ull;

static const uint64_t P9N2_PERV_PCI1_XFIR                                          = 0x0E040000ull;

static const uint64_t P9N2_PERV_PCI2_XFIR                                          = 0x0F040000ull;

static const uint64_t P9N2_PERV_EP00_XFIR                                          = 0x10040000ull;

static const uint64_t P9N2_PERV_EP01_XFIR                                          = 0x11040000ull;

static const uint64_t P9N2_PERV_EP02_XFIR                                          = 0x12040000ull;

static const uint64_t P9N2_PERV_EP03_XFIR                                          = 0x13040000ull;

static const uint64_t P9N2_PERV_EP04_XFIR                                          = 0x14040000ull;

static const uint64_t P9N2_PERV_EP05_XFIR                                          = 0x15040000ull;

static const uint64_t P9N2_PERV_EC00_XFIR                                          = 0x20040000ull;

static const uint64_t P9N2_PERV_EC01_XFIR                                          = 0x21040000ull;

static const uint64_t P9N2_PERV_EC02_XFIR                                          = 0x22040000ull;

static const uint64_t P9N2_PERV_EC03_XFIR                                          = 0x23040000ull;

static const uint64_t P9N2_PERV_EC04_XFIR                                          = 0x24040000ull;

static const uint64_t P9N2_PERV_EC05_XFIR                                          = 0x25040000ull;

static const uint64_t P9N2_PERV_EC06_XFIR                                          = 0x26040000ull;

static const uint64_t P9N2_PERV_EC07_XFIR                                          = 0x27040000ull;

static const uint64_t P9N2_PERV_EC08_XFIR                                          = 0x28040000ull;

static const uint64_t P9N2_PERV_EC09_XFIR                                          = 0x29040000ull;

static const uint64_t P9N2_PERV_EC10_XFIR                                          = 0x2A040000ull;

static const uint64_t P9N2_PERV_EC11_XFIR                                          = 0x2B040000ull;

static const uint64_t P9N2_PERV_EC12_XFIR                                          = 0x2C040000ull;

static const uint64_t P9N2_PERV_EC13_XFIR                                          = 0x2D040000ull;

static const uint64_t P9N2_PERV_EC14_XFIR                                          = 0x2E040000ull;

static const uint64_t P9N2_PERV_EC15_XFIR                                          = 0x2F040000ull;

static const uint64_t P9N2_PERV_EC16_XFIR                                          = 0x30040000ull;

static const uint64_t P9N2_PERV_EC17_XFIR                                          = 0x31040000ull;

static const uint64_t P9N2_PERV_EC18_XFIR                                          = 0x32040000ull;

static const uint64_t P9N2_PERV_EC19_XFIR                                          = 0x33040000ull;

static const uint64_t P9N2_PERV_EC20_XFIR                                          = 0x34040000ull;

static const uint64_t P9N2_PERV_EC21_XFIR                                          = 0x35040000ull;

static const uint64_t P9N2_PERV_EC22_XFIR                                          = 0x36040000ull;

static const uint64_t P9N2_PERV_EC23_XFIR                                          = 0x37040000ull;


static const uint64_t P9N2_PERV_XSTOP1                                             = 0x0003000Cull;

static const uint64_t P9N2_PERV_TP_XSTOP1                                          = 0x0103000Cull;

static const uint64_t P9N2_PERV_N0_XSTOP1                                          = 0x0203000Cull;

static const uint64_t P9N2_PERV_N1_XSTOP1                                          = 0x0303000Cull;

static const uint64_t P9N2_PERV_N2_XSTOP1                                          = 0x0403000Cull;

static const uint64_t P9N2_PERV_N3_XSTOP1                                          = 0x0503000Cull;

static const uint64_t P9N2_PERV_XB_XSTOP1                                          = 0x0603000Cull;

static const uint64_t P9N2_PERV_MC01_XSTOP1                                        = 0x0703000Cull;

static const uint64_t P9N2_PERV_MC23_XSTOP1                                        = 0x0803000Cull;

static const uint64_t P9N2_PERV_OB0_XSTOP1                                         = 0x0903000Cull;

static const uint64_t P9N2_PERV_OB3_XSTOP1                                         = 0x0C03000Cull;

static const uint64_t P9N2_PERV_PCI0_XSTOP1                                        = 0x0D03000Cull;

static const uint64_t P9N2_PERV_PCI1_XSTOP1                                        = 0x0E03000Cull;

static const uint64_t P9N2_PERV_PCI2_XSTOP1                                        = 0x0F03000Cull;

static const uint64_t P9N2_PERV_EP00_XSTOP1                                        = 0x1003000Cull;

static const uint64_t P9N2_PERV_EP01_XSTOP1                                        = 0x1103000Cull;

static const uint64_t P9N2_PERV_EP02_XSTOP1                                        = 0x1203000Cull;

static const uint64_t P9N2_PERV_EP03_XSTOP1                                        = 0x1303000Cull;

static const uint64_t P9N2_PERV_EP04_XSTOP1                                        = 0x1403000Cull;

static const uint64_t P9N2_PERV_EP05_XSTOP1                                        = 0x1503000Cull;

static const uint64_t P9N2_PERV_EC00_XSTOP1                                        = 0x2003000Cull;

static const uint64_t P9N2_PERV_EC01_XSTOP1                                        = 0x2103000Cull;

static const uint64_t P9N2_PERV_EC02_XSTOP1                                        = 0x2203000Cull;

static const uint64_t P9N2_PERV_EC03_XSTOP1                                        = 0x2303000Cull;

static const uint64_t P9N2_PERV_EC04_XSTOP1                                        = 0x2403000Cull;

static const uint64_t P9N2_PERV_EC05_XSTOP1                                        = 0x2503000Cull;

static const uint64_t P9N2_PERV_EC06_XSTOP1                                        = 0x2603000Cull;

static const uint64_t P9N2_PERV_EC07_XSTOP1                                        = 0x2703000Cull;

static const uint64_t P9N2_PERV_EC08_XSTOP1                                        = 0x2803000Cull;

static const uint64_t P9N2_PERV_EC09_XSTOP1                                        = 0x2903000Cull;

static const uint64_t P9N2_PERV_EC10_XSTOP1                                        = 0x2A03000Cull;

static const uint64_t P9N2_PERV_EC11_XSTOP1                                        = 0x2B03000Cull;

static const uint64_t P9N2_PERV_EC12_XSTOP1                                        = 0x2C03000Cull;

static const uint64_t P9N2_PERV_EC13_XSTOP1                                        = 0x2D03000Cull;

static const uint64_t P9N2_PERV_EC14_XSTOP1                                        = 0x2E03000Cull;

static const uint64_t P9N2_PERV_EC15_XSTOP1                                        = 0x2F03000Cull;

static const uint64_t P9N2_PERV_EC16_XSTOP1                                        = 0x3003000Cull;

static const uint64_t P9N2_PERV_EC17_XSTOP1                                        = 0x3103000Cull;

static const uint64_t P9N2_PERV_EC18_XSTOP1                                        = 0x3203000Cull;

static const uint64_t P9N2_PERV_EC19_XSTOP1                                        = 0x3303000Cull;

static const uint64_t P9N2_PERV_EC20_XSTOP1                                        = 0x3403000Cull;

static const uint64_t P9N2_PERV_EC21_XSTOP1                                        = 0x3503000Cull;

static const uint64_t P9N2_PERV_EC22_XSTOP1                                        = 0x3603000Cull;

static const uint64_t P9N2_PERV_EC23_XSTOP1                                        = 0x3703000Cull;


static const uint64_t P9N2_PERV_XSTOP2                                             = 0x0003000Dull;

static const uint64_t P9N2_PERV_TP_XSTOP2                                          = 0x0103000Dull;

static const uint64_t P9N2_PERV_N0_XSTOP2                                          = 0x0203000Dull;

static const uint64_t P9N2_PERV_N1_XSTOP2                                          = 0x0303000Dull;

static const uint64_t P9N2_PERV_N2_XSTOP2                                          = 0x0403000Dull;

static const uint64_t P9N2_PERV_N3_XSTOP2                                          = 0x0503000Dull;

static const uint64_t P9N2_PERV_XB_XSTOP2                                          = 0x0603000Dull;

static const uint64_t P9N2_PERV_MC01_XSTOP2                                        = 0x0703000Dull;

static const uint64_t P9N2_PERV_MC23_XSTOP2                                        = 0x0803000Dull;

static const uint64_t P9N2_PERV_OB0_XSTOP2                                         = 0x0903000Dull;

static const uint64_t P9N2_PERV_OB3_XSTOP2                                         = 0x0C03000Dull;

static const uint64_t P9N2_PERV_PCI0_XSTOP2                                        = 0x0D03000Dull;

static const uint64_t P9N2_PERV_PCI1_XSTOP2                                        = 0x0E03000Dull;

static const uint64_t P9N2_PERV_PCI2_XSTOP2                                        = 0x0F03000Dull;

static const uint64_t P9N2_PERV_EP00_XSTOP2                                        = 0x1003000Dull;

static const uint64_t P9N2_PERV_EP01_XSTOP2                                        = 0x1103000Dull;

static const uint64_t P9N2_PERV_EP02_XSTOP2                                        = 0x1203000Dull;

static const uint64_t P9N2_PERV_EP03_XSTOP2                                        = 0x1303000Dull;

static const uint64_t P9N2_PERV_EP04_XSTOP2                                        = 0x1403000Dull;

static const uint64_t P9N2_PERV_EP05_XSTOP2                                        = 0x1503000Dull;

static const uint64_t P9N2_PERV_EC00_XSTOP2                                        = 0x2003000Dull;

static const uint64_t P9N2_PERV_EC01_XSTOP2                                        = 0x2103000Dull;

static const uint64_t P9N2_PERV_EC02_XSTOP2                                        = 0x2203000Dull;

static const uint64_t P9N2_PERV_EC03_XSTOP2                                        = 0x2303000Dull;

static const uint64_t P9N2_PERV_EC04_XSTOP2                                        = 0x2403000Dull;

static const uint64_t P9N2_PERV_EC05_XSTOP2                                        = 0x2503000Dull;

static const uint64_t P9N2_PERV_EC06_XSTOP2                                        = 0x2603000Dull;

static const uint64_t P9N2_PERV_EC07_XSTOP2                                        = 0x2703000Dull;

static const uint64_t P9N2_PERV_EC08_XSTOP2                                        = 0x2803000Dull;

static const uint64_t P9N2_PERV_EC09_XSTOP2                                        = 0x2903000Dull;

static const uint64_t P9N2_PERV_EC10_XSTOP2                                        = 0x2A03000Dull;

static const uint64_t P9N2_PERV_EC11_XSTOP2                                        = 0x2B03000Dull;

static const uint64_t P9N2_PERV_EC12_XSTOP2                                        = 0x2C03000Dull;

static const uint64_t P9N2_PERV_EC13_XSTOP2                                        = 0x2D03000Dull;

static const uint64_t P9N2_PERV_EC14_XSTOP2                                        = 0x2E03000Dull;

static const uint64_t P9N2_PERV_EC15_XSTOP2                                        = 0x2F03000Dull;

static const uint64_t P9N2_PERV_EC16_XSTOP2                                        = 0x3003000Dull;

static const uint64_t P9N2_PERV_EC17_XSTOP2                                        = 0x3103000Dull;

static const uint64_t P9N2_PERV_EC18_XSTOP2                                        = 0x3203000Dull;

static const uint64_t P9N2_PERV_EC19_XSTOP2                                        = 0x3303000Dull;

static const uint64_t P9N2_PERV_EC20_XSTOP2                                        = 0x3403000Dull;

static const uint64_t P9N2_PERV_EC21_XSTOP2                                        = 0x3503000Dull;

static const uint64_t P9N2_PERV_EC22_XSTOP2                                        = 0x3603000Dull;

static const uint64_t P9N2_PERV_EC23_XSTOP2                                        = 0x3703000Dull;


static const uint64_t P9N2_PERV_XSTOP3                                             = 0x0003000Eull;

static const uint64_t P9N2_PERV_TP_XSTOP3                                          = 0x0103000Eull;

static const uint64_t P9N2_PERV_N0_XSTOP3                                          = 0x0203000Eull;

static const uint64_t P9N2_PERV_N1_XSTOP3                                          = 0x0303000Eull;

static const uint64_t P9N2_PERV_N2_XSTOP3                                          = 0x0403000Eull;

static const uint64_t P9N2_PERV_N3_XSTOP3                                          = 0x0503000Eull;

static const uint64_t P9N2_PERV_XB_XSTOP3                                          = 0x0603000Eull;

static const uint64_t P9N2_PERV_MC01_XSTOP3                                        = 0x0703000Eull;

static const uint64_t P9N2_PERV_MC23_XSTOP3                                        = 0x0803000Eull;

static const uint64_t P9N2_PERV_OB0_XSTOP3                                         = 0x0903000Eull;

static const uint64_t P9N2_PERV_OB3_XSTOP3                                         = 0x0C03000Eull;

static const uint64_t P9N2_PERV_PCI0_XSTOP3                                        = 0x0D03000Eull;

static const uint64_t P9N2_PERV_PCI1_XSTOP3                                        = 0x0E03000Eull;

static const uint64_t P9N2_PERV_PCI2_XSTOP3                                        = 0x0F03000Eull;

static const uint64_t P9N2_PERV_EP00_XSTOP3                                        = 0x1003000Eull;

static const uint64_t P9N2_PERV_EP01_XSTOP3                                        = 0x1103000Eull;

static const uint64_t P9N2_PERV_EP02_XSTOP3                                        = 0x1203000Eull;

static const uint64_t P9N2_PERV_EP03_XSTOP3                                        = 0x1303000Eull;

static const uint64_t P9N2_PERV_EP04_XSTOP3                                        = 0x1403000Eull;

static const uint64_t P9N2_PERV_EP05_XSTOP3                                        = 0x1503000Eull;

static const uint64_t P9N2_PERV_EC00_XSTOP3                                        = 0x2003000Eull;

static const uint64_t P9N2_PERV_EC01_XSTOP3                                        = 0x2103000Eull;

static const uint64_t P9N2_PERV_EC02_XSTOP3                                        = 0x2203000Eull;

static const uint64_t P9N2_PERV_EC03_XSTOP3                                        = 0x2303000Eull;

static const uint64_t P9N2_PERV_EC04_XSTOP3                                        = 0x2403000Eull;

static const uint64_t P9N2_PERV_EC05_XSTOP3                                        = 0x2503000Eull;

static const uint64_t P9N2_PERV_EC06_XSTOP3                                        = 0x2603000Eull;

static const uint64_t P9N2_PERV_EC07_XSTOP3                                        = 0x2703000Eull;

static const uint64_t P9N2_PERV_EC08_XSTOP3                                        = 0x2803000Eull;

static const uint64_t P9N2_PERV_EC09_XSTOP3                                        = 0x2903000Eull;

static const uint64_t P9N2_PERV_EC10_XSTOP3                                        = 0x2A03000Eull;

static const uint64_t P9N2_PERV_EC11_XSTOP3                                        = 0x2B03000Eull;

static const uint64_t P9N2_PERV_EC12_XSTOP3                                        = 0x2C03000Eull;

static const uint64_t P9N2_PERV_EC13_XSTOP3                                        = 0x2D03000Eull;

static const uint64_t P9N2_PERV_EC14_XSTOP3                                        = 0x2E03000Eull;

static const uint64_t P9N2_PERV_EC15_XSTOP3                                        = 0x2F03000Eull;

static const uint64_t P9N2_PERV_EC16_XSTOP3                                        = 0x3003000Eull;

static const uint64_t P9N2_PERV_EC17_XSTOP3                                        = 0x3103000Eull;

static const uint64_t P9N2_PERV_EC18_XSTOP3                                        = 0x3203000Eull;

static const uint64_t P9N2_PERV_EC19_XSTOP3                                        = 0x3303000Eull;

static const uint64_t P9N2_PERV_EC20_XSTOP3                                        = 0x3403000Eull;

static const uint64_t P9N2_PERV_EC21_XSTOP3                                        = 0x3503000Eull;

static const uint64_t P9N2_PERV_EC22_XSTOP3                                        = 0x3603000Eull;

static const uint64_t P9N2_PERV_EC23_XSTOP3                                        = 0x3703000Eull;


static const uint64_t P9N2_PERV_XSTOP_INTERRUPT_REG                                = 0x000F001Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG
static const uint64_t P9N2_PERV_TP_XSTOP_INTERRUPT_REG                             = 0x010F001Cull;

static const uint64_t P9N2_PERV_N0_XSTOP_INTERRUPT_REG                             = 0x020F001Cull;

static const uint64_t P9N2_PERV_N1_XSTOP_INTERRUPT_REG                             = 0x030F001Cull;

static const uint64_t P9N2_PERV_N2_XSTOP_INTERRUPT_REG                             = 0x040F001Cull;

static const uint64_t P9N2_PERV_N3_XSTOP_INTERRUPT_REG                             = 0x050F001Cull;

static const uint64_t P9N2_PERV_XB_XSTOP_INTERRUPT_REG                             = 0x060F001Cull;

static const uint64_t P9N2_PERV_MC01_XSTOP_INTERRUPT_REG                           = 0x070F001Cull;

static const uint64_t P9N2_PERV_MC23_XSTOP_INTERRUPT_REG                           = 0x080F001Cull;

static const uint64_t P9N2_PERV_OB0_XSTOP_INTERRUPT_REG                            = 0x090F001Cull;

static const uint64_t P9N2_PERV_OB3_XSTOP_INTERRUPT_REG                            = 0x0C0F001Cull;

static const uint64_t P9N2_PERV_PCI0_XSTOP_INTERRUPT_REG                           = 0x0D0F001Cull;

static const uint64_t P9N2_PERV_PCI1_XSTOP_INTERRUPT_REG                           = 0x0E0F001Cull;

static const uint64_t P9N2_PERV_PCI2_XSTOP_INTERRUPT_REG                           = 0x0F0F001Cull;

static const uint64_t P9N2_PERV_EP00_XSTOP_INTERRUPT_REG                           = 0x100F001Cull;

static const uint64_t P9N2_PERV_EP01_XSTOP_INTERRUPT_REG                           = 0x110F001Cull;

static const uint64_t P9N2_PERV_EP02_XSTOP_INTERRUPT_REG                           = 0x120F001Cull;

static const uint64_t P9N2_PERV_EP03_XSTOP_INTERRUPT_REG                           = 0x130F001Cull;

static const uint64_t P9N2_PERV_EP04_XSTOP_INTERRUPT_REG                           = 0x140F001Cull;

static const uint64_t P9N2_PERV_EP05_XSTOP_INTERRUPT_REG                           = 0x150F001Cull;

static const uint64_t P9N2_PERV_EC00_XSTOP_INTERRUPT_REG                           = 0x200F001Cull;

static const uint64_t P9N2_PERV_EC01_XSTOP_INTERRUPT_REG                           = 0x210F001Cull;

static const uint64_t P9N2_PERV_EC02_XSTOP_INTERRUPT_REG                           = 0x220F001Cull;

static const uint64_t P9N2_PERV_EC03_XSTOP_INTERRUPT_REG                           = 0x230F001Cull;

static const uint64_t P9N2_PERV_EC04_XSTOP_INTERRUPT_REG                           = 0x240F001Cull;

static const uint64_t P9N2_PERV_EC05_XSTOP_INTERRUPT_REG                           = 0x250F001Cull;

static const uint64_t P9N2_PERV_EC06_XSTOP_INTERRUPT_REG                           = 0x260F001Cull;

static const uint64_t P9N2_PERV_EC07_XSTOP_INTERRUPT_REG                           = 0x270F001Cull;

static const uint64_t P9N2_PERV_EC08_XSTOP_INTERRUPT_REG                           = 0x280F001Cull;

static const uint64_t P9N2_PERV_EC09_XSTOP_INTERRUPT_REG                           = 0x290F001Cull;

static const uint64_t P9N2_PERV_EC10_XSTOP_INTERRUPT_REG                           = 0x2A0F001Cull;

static const uint64_t P9N2_PERV_EC11_XSTOP_INTERRUPT_REG                           = 0x2B0F001Cull;

static const uint64_t P9N2_PERV_EC12_XSTOP_INTERRUPT_REG                           = 0x2C0F001Cull;

static const uint64_t P9N2_PERV_EC13_XSTOP_INTERRUPT_REG                           = 0x2D0F001Cull;

static const uint64_t P9N2_PERV_EC14_XSTOP_INTERRUPT_REG                           = 0x2E0F001Cull;

static const uint64_t P9N2_PERV_EC15_XSTOP_INTERRUPT_REG                           = 0x2F0F001Cull;

static const uint64_t P9N2_PERV_EC16_XSTOP_INTERRUPT_REG                           = 0x300F001Cull;

static const uint64_t P9N2_PERV_EC17_XSTOP_INTERRUPT_REG                           = 0x310F001Cull;

static const uint64_t P9N2_PERV_EC18_XSTOP_INTERRUPT_REG                           = 0x320F001Cull;

static const uint64_t P9N2_PERV_EC19_XSTOP_INTERRUPT_REG                           = 0x330F001Cull;

static const uint64_t P9N2_PERV_EC20_XSTOP_INTERRUPT_REG                           = 0x340F001Cull;

static const uint64_t P9N2_PERV_EC21_XSTOP_INTERRUPT_REG                           = 0x350F001Cull;

static const uint64_t P9N2_PERV_EC22_XSTOP_INTERRUPT_REG                           = 0x360F001Cull;

static const uint64_t P9N2_PERV_EC23_XSTOP_INTERRUPT_REG                           = 0x370F001Cull;


static const uint64_t P9N2_PERV_XTRA_TRACE_MODE                                    = 0x000107D1ull;

static const uint64_t P9N2_PERV_TP_XTRA_TRACE_MODE                                 = 0x010107D1ull;

#endif

