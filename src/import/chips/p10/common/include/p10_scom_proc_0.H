/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_0.H $       */
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

#ifndef __p10_scom_proc_0_H_
#define __p10_scom_proc_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> [INT_VC_EASC_FLUSH_CTRL]
static const uint64_t INT_VC_EASC_FLUSH_CTRL = 0x02010960ull;

static const uint32_t INT_VC_EASC_FLUSH_CTRL_POLL_VALID = 0;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_1 = 1;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_POLL_WANT_CACHE_DISABLE = 2;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7 = 3;
static const uint32_t INT_VC_EASC_FLUSH_CTRL_RESERVED_3_7_LEN = 5;
//<< [INT_VC_EASC_FLUSH_CTRL]
// proc/reg00000.H

//>> [MCD_BANK0_VGC]
static const uint64_t MCD_BANK0_VGC = 0x03010811ull;

static const uint32_t MCD_BANK0_VGC_P10_AVAIL_GROUPS = 0;
static const uint32_t MCD_BANK0_VGC_P10_AVAIL_GROUPS_LEN = 8;
static const uint32_t MCD_BANK0_VGC_RSVD_AVAIL_GROUPS = 8;
static const uint32_t MCD_BANK0_VGC_RSVD_AVAIL_GROUPS_LEN = 8;
static const uint32_t MCD_BANK0_VGC_FAILED_GROUPS = 16;
static const uint32_t MCD_BANK0_VGC_FAILED_GROUPS_LEN = 8;
static const uint32_t MCD_BANK0_VGC_FORCE_RTY_MCD_RATE = 24;
static const uint32_t MCD_BANK0_VGC_FORCE_RTY_MCD_RATE_LEN = 2;
static const uint32_t MCD_BANK0_VGC_4X4_MODE = 32;
static const uint32_t MCD_BANK0_VGC_HANG_POLL_ENABLE = 33;
static const uint32_t MCD_BANK0_VGC_RND_BACKOFF_ENABLE = 34;
static const uint32_t MCD_BANK0_VGC_DROP_PRIORITY_MODE = 35;
static const uint32_t MCD_BANK0_VGC_MASK_AGV_DISABLE_MODE = 36;
static const uint32_t MCD_BANK0_VGC_XLATE_TO_ADDR_ID_ENABLE = 37;
static const uint32_t MCD_BANK0_VGC_P8MODE_ENABLE = 38;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_FAC_ENABLE = 39;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_FAC_MASK = 40;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_FAC_MASK_LEN = 7;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE = 47;
static const uint32_t MCD_BANK0_VGC_EXT_ADDR_VEC_ENABLE_LEN = 2;
static const uint32_t MCD_BANK0_VGC_CS_HW400693_DISABLE = 49;
static const uint32_t MCD_BANK0_VGC_ENABLE_RCV_ADDR_DEBUG = 50;
static const uint32_t MCD_BANK0_VGC_CS_HW403560_DISABLE = 51;
static const uint32_t MCD_BANK0_VGC_CS_FWD_HW423589_ENABLE = 52;
static const uint32_t MCD_BANK0_VGC_CS_PAIR_HW423589_DISABLE = 53;
static const uint32_t MCD_BANK0_VGC_CS_RECOVER_HW423589_DISABLE = 54;
static const uint32_t MCD_BANK0_VGC_CS_WRITE_HW423589_DISABLE = 55;
static const uint32_t MCD_BANK0_VGC_1MB_GRANULE_MODE = 57;
static const uint32_t MCD_BANK0_VGC_FORCE_RTY_MCD_ENABLE = 58;
static const uint32_t MCD_BANK0_VGC_SPARE = 59;
static const uint32_t MCD_BANK0_VGC_SPARE_LEN = 5;
//<< [MCD_BANK0_VGC]
// proc/reg00000.H

//>> [NX_DMA_SU_STATUS]
static const uint64_t NX_DMA_SU_STATUS = 0x02011040ull;

static const uint32_t NX_DMA_SU_STATUS_HMI_ACTIVE = 54;
static const uint32_t NX_DMA_SU_STATUS_PBI_IDLE = 55;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH0_IDLE = 56;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH1_IDLE = 57;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH2_IDLE = 58;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH3_IDLE = 59;
static const uint32_t NX_DMA_SU_STATUS_DMA_CH4_IDLE = 60;
//<< [NX_DMA_SU_STATUS]
// proc/reg00000.H

//>> [TP_TPBR_PBA_PBAO_PBAERRRPT1]
static const uint64_t TP_TPBR_PBA_PBAO_PBAERRRPT1 = 0x01010ccdull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_RESERVED_0_5 = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_RESERVED_0_5_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCDE_SETUP_ERR = 6;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCDE_SETUP_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_SETUP_ERR = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_SETUP_ERR_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_OCI_DATAERR = 10;
static const uint32_t TP_TPBR_PBA_PBAO_PBAERRRPT1_CERR_BCUE_OCI_DATAERR_LEN = 2;
//<< [TP_TPBR_PBA_PBAO_PBAERRRPT1]
// proc/reg00001.H

//>> [TP_TPBR_PBA_PBAO_PBASLVCTL1]
static const uint64_t TP_TPBR_PBA_PBAO_PBASLVCTL1 = 0x00068005ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_ENABLE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_MATCH_VALUE = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_MATCH_VALUE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_4 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_CARE_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_CARE_MASK_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TTYPE = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TTYPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_11_14 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_11_14_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_TTYPE = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_PREFETCH_CTL = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_PREFETCH_CTL_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_INVALIDATE_CTL = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_W = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_A = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_B = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_C = 22;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_23 = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_DIS_WRITE_GATHER = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WR_GATHER_TIMEOUT = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WR_GATHER_TIMEOUT_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TSIZE = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TSIZE_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_EXTADDR = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_EXTADDR_LEN = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL1_RESERVED_50 = 50;
//<< [TP_TPBR_PBA_PBAO_PBASLVCTL1]
// proc/reg00001.H

//>> [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL = 0x0006402full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_POPULATE_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL_VALID_LEN = 4;
//<< [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACL]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU = 0x0006402eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN = 27;
//<< [TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCACU]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL]
static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL = 0x00066000ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL_LEN = 4;
//<< [TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OCBSES2]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2 = 0x0006c226ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2_SH_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES2_LL_WRITE_OVERFLOW = 1;
//<< [TP_TPCHIP_OCC_OCI_OCB_OCBSES2]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OIMR1]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_RW = 0x0006c024ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_CLEAR = 0x0006c025ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_OR = 0x0006c026ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_OCB_OCI_OIMR1_INTERRUPT_MASK_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR1_OCB_OCI_OIMR1_INTERRUPT_MASK_1_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_OIMR1]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OINKR1]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OINKR1 = 0x0006c030ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR1_OCB_OCI_OINKR1_INTERRUPT_INPUT_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR1_OCB_OCI_OINKR1_INTERRUPT_INPUT_1_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_OINKR1]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OIRR1A]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_RW = 0x0006c050ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_WO_CLEAR = 0x0006c051ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_WO_OR = 0x0006c052ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_OCB_OCI_OIRR1A_INTERRUPT_ROUTE_1_A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIRR1A_OCB_OCI_OIRR1A_INTERRUPT_ROUTE_1_A_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_OIRR1A]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_P2S_CR1]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1 = 0x0006c841ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_BRIDGE_ENABLE = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_DEVICE = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CPOL = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CPHA = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CLOCK_DIVIDER = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CLOCK_DIVIDER_LEN = 10;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CR1_RESERVED_2 = 14;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_CR1_RESERVED_2_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_CR1_NR_OF_FRAMES = 17;
//<< [TP_TPCHIP_OCC_OCI_OCB_P2S_CR1]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_P2S_STAT]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT = 0x0006c843ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_ONGOING = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_RESERVED_1_4 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_RESERVED_1_4_LEN = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_WRITE_WHILE_BRIDGE_BUSY_ERR = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_RESERVED_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_FSM_ERR = 7;
//<< [TP_TPCHIP_OCC_OCI_OCB_P2S_STAT]
// proc/reg00002.H

//>> [TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS = 0x00050001ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI = 0x00002801ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE = 0x00002804ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN = 16;
//<< [TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_CS]
// proc/reg00003.H

//>> [PB_COM_SCOM_EQ0_STATION_FIR_REG]
static const uint64_t PB_COM_SCOM_EQ0_STATION_FIR_REG_RW = 0x03011000ull;
static const uint64_t PB_COM_SCOM_EQ0_STATION_FIR_REG_WO_AND = 0x03011001ull;
static const uint64_t PB_COM_SCOM_EQ0_STATION_FIR_REG_WO_OR = 0x03011002ull;

static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_PROTOCOL_ERROR = 0;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_OVERFLOW_ERROR = 1;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_HW_PARITY_ERROR = 2;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FIR_SPARE_3 = 3;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_COHERENCY_ERROR = 4;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_CRESP_ADDR_ERROR = 5;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_CRESP_ERROR = 6;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_HANG_RECOVERY_LIMIT_ERROR = 7;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FIR_SPARE_8 = 8;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_HANG_RECOVERY_GTE_LEVEL1 = 9;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FORCE_MP_IPL = 10;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_PB_CMD_SNOOPER_ERROR = 11;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_DATA_OVERFLOW_ERROR = 12;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_DATA_PROTOCOL_ERROR = 13;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_DATA_ROUTE_ERROR = 14;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_FIR_COMPAB_TRIGGER = 15;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK0_PROTOCOL_ERROR = 16;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK0_OVERFLOW_ERROR = 17;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK0_HW_PARITY_ERROR = 18;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK1_PROTOCOL_ERROR = 19;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK1_OVERFLOW_ERROR = 20;
static const uint32_t PB_COM_SCOM_EQ0_STATION_FIR_REG_LINK1_HW_PARITY_ERROR = 21;
//<< [PB_COM_SCOM_EQ0_STATION_FIR_REG]
// proc/reg00000.H

//>> [TP_TPCHIP_TPC_CPLT_CTRL1]
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL1_RW = 0x01000001ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL1_WO_CLEAR = 0x01000021ull;
static const uint64_t TP_TPCHIP_TPC_CPLT_CTRL1_WO_OR = 0x01000011ull;

static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION0_FENCE_DC = 4;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC = 5;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC = 6;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION3_FENCE_DC = 7;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION4_FENCE_DC = 8;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION5_FENCE_DC = 9;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION6_FENCE_DC = 10;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION7_FENCE_DC = 11;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION8_FENCE_DC = 12;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION9_FENCE_DC = 13;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION10_FENCE_DC = 14;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION11_FENCE_DC = 15;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION12_FENCE_DC = 16;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION13_FENCE_DC = 17;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION14_FENCE_DC = 18;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_EXPORT_FREEZE = 20;
static const uint32_t TP_TPCHIP_TPC_CPLT_CTRL1_TC_STG_ACT_EN_DC = 22;
//<< [TP_TPCHIP_TPC_CPLT_CTRL1]
// proc/reg00003.H

//>> [TP_TPCHIP_OCC_OCI_OCB_OIEPR1]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_RW = 0x0006c02cull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_CLEAR = 0x0006c02dull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_OR = 0x0006c02eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_OCB_OCI_OIEPR1_INTERRUPT_EDGE_POL_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR1_OCB_OCI_OIEPR1_INTERRUPT_EDGE_POL_1_LEN = 32;
//<< [TP_TPCHIP_OCC_OCI_OCB_OIEPR1]
// proc/reg00002.H

//>> [TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1]
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1 = 0x0006c720ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_FRAME_SIZE_1 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_FRAME_SIZE_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_OUT_COUNT1_1 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_OUT_COUNT1_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_DELAY1_1 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_DELAY1_1_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_COUNT1_1 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1_IN_COUNT1_1_LEN = 6;
//<< [TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF1]
// proc/reg00002.H

//>> [TP_TPBR_PSI_WRAP_TX_DF_FSM_REG]
static const uint64_t TP_TPBR_PSI_WRAP_TX_DF_FSM_REG = 0x03011c06ull;

static const uint32_t TP_TPBR_PSI_WRAP_TX_DF_FSM_REG_TX_DF_FSM = 0;
static const uint32_t TP_TPBR_PSI_WRAP_TX_DF_FSM_REG_TX_DF_FSM_LEN = 4;
//<< [TP_TPBR_PSI_WRAP_TX_DF_FSM_REG]
// proc/reg00001.H

//>> [TP_TPBR_PSIHB_DEBUG_REG]
static const uint64_t TP_TPBR_PSIHB_DEBUG_REG = 0x03011d11ull;

static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_ERR_BITS = 0;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_ERR_BITS_LEN = 2;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_ONCE = 2;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2FSP_INJ_CONST = 3;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_ERR_BITS = 8;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_ERR_BITS_LEN = 2;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_ONCE = 10;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_PSIHB2PB_INJ_CONST = 11;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_TRACE_SEL = 16;
static const uint32_t TP_TPBR_PSIHB_DEBUG_REG_TRACE_SEL_LEN = 4;
//<< [TP_TPBR_PSIHB_DEBUG_REG]
// proc/reg00001.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "proc/reg00000.H"
#include "proc/reg00001.H"
#include "proc/reg00002.H"
#include "proc/reg00003.H"
#include "proc/reg00004.H"
#endif
#endif
