/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_defines.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#ifndef __PM_RECOVERY_FFDC_DEFINES_
#define __PM_RECOVERY_FFDC_DEFINES_

#include <p9_hcd_memmap_base.H>
#include <endian.h>

#if( __BYTE_ORDER == __BIG_ENDIAN )
#define REV_2_BYTE(WORD) WORD
#else
#define REV_2_BYTE(WORD) \
    ( (((WORD) >> 8) & 0x00FF) | (((WORD) << 8) & 0xFF00) )
#endif

namespace p9_stop_recov_ffdc
{

/**
 * @brief   enumerates all the platforms involved with STOP Recovery.
 */
enum PmComplexPlatId
{
    PLAT_CME    =   0x01,
    PLAT_SGPE   =   0x02,
    PLAT_PGPE   =   0x03,
    PLAT_OCC    =   0x04,
    PLAT_PPM    =   0x05,
};

/**
 * @brief enumerates type of FFDC data
 */
enum FfdcDataType
{
    IMAGE_HEADER     =  0x01,
    DASH_BOARD_VAR   =  0x02,
    TRACES           =  0x03,
    INTERNAL_REG     =  0x04,
    SCOM_REG         =  0x05,
};

/**
 * @brief enumerates bit position used as validity mark of PPE FFDC sub-section.
 */

enum PpeFfdcValidStatus
{
    PPE_FFDC_INVALID        =   0x00,  //entire PPE FFDC is not valid
    PPE_DASHBOARD_VALID     =   0x01,  // PPE globals are valid
    PPE_IMAGE_HEADER_VALID  =   0x02,  // PPE image header is valid
    PPE_TRACE_VALID         =   0x04,  // PPE Traces are valid
    PPE_SPR_VALID           =   0x08,  // PPE SPRs are valid
    PPE_INT_REG_VALID       =   0x10,  // PPE Int Regs are valid
    PPE_STATE_VALID         =   0x20,  // PPE State Info is valid
    PPE_FFDC_ALL_VALID      =   0x3F,  // Entire PPE FFDC is valid
};

/**
 * @brief   models header of FFDC region of HOMER associated with a CME.
 */
struct __attribute__((packed)) PpeFfdcHeader
{
    uint32_t  iv_ppeMagicNumber;
    uint8_t   iv_ppeNumber;
    uint8_t   iv_headerSize;
    uint16_t  iv_sectionSize;
    uint8_t   iv_ffdcValid;
    uint8_t   iv_ppeHaltCondition;
    uint16_t  iv_dashBoardOffset;
    uint16_t  iv_sramHeaderOffset;
    uint16_t  iv_sprOffset;
    uint16_t  iv_intRegOffset;
    uint16_t  iv_offsetTraces;
    uint8_t   iv_reserve[4];
};

/**
 * @brief models Quad FFDC header.
 */
struct __attribute__((packed)) QuadFfdcHeader
{
    uint32_t iv_quadMagicWord;
    uint8_t  iv_quadInstance;
    uint8_t  iv_quadHeaderSize;
    uint16_t iv_sectionSize;
    uint16_t iv_offsetCppm0;
    uint16_t iv_offsetCppm1;
    uint16_t iv_offsetCppm2;
    uint16_t iv_offsetCppm3;
    uint16_t iv_offsetCme0;
    uint16_t iv_offsetCme1;
    uint16_t iv_offsetQppm;
    uint8_t  iv_reserve[2];
};

/**
 * @brief   a union modelling CME FFDC region's header area.
 */
union PpeFfdcHdrRegion
{
    uint8_t iv_ppeFfdcHdrArea[FFDC_PPE_HDR_SIZE];
    PpeFfdcHeader iv_ppeFfdcHdr;
};

/**
 * @brief   models CME's FFDC region.
 */
struct  __attribute__((packed)) PpeFfdcLayout
{
    PpeFfdcHdrRegion iv_ppeFfdcHdr;
    uint8_t iv_ppeGlobals[FFDC_PPE_SCORE_BOARD_SIZE];
    uint8_t iv_ppeImageHeader[FFDC_PPE_IMG_HDR_SIZE];
    uint8_t iv_ppeXirReg[FFDC_PPE_XIR_SIZE];
    uint8_t iv_ppeMajSpr[FFDC_PPE_MAJOR_SPR_SIZE];
    uint8_t iv_ppeMinSpr[FFDC_PPE_MINOR_SPR_SIZE];
    uint8_t iv_ppeGprs[FFDC_PPE_GPR_SIZE];
    uint8_t iv_ppeInternalReg[FFDC_PPE_INTERNAL_REG_SIZE];
    uint8_t iv_ppeTraces[FFDC_PPE_TRACES_SIZE];
};

/**
 * @brief   models Quad FFDC region of HOMER.
 */
struct __attribute__((packed)) HomerQuadFfdcRegion
{
    uint8_t iv_quadFfdcHeader[FFDC_QUAD_HDR_SIZE];
    uint8_t iv_quadCppmRegion[FFDC_CPPM_REGISTERS_SIZE];
    uint8_t iv_quadCmeBlock[MAX_CMES_PER_QUAD][FFDC_PPE_BLOCK_SIZE];
    uint8_t iv_quadQppmRegion[FFDC_QPPM_REGISTERS_SIZE];
};

/**
 * @brief   models OCC FFDC region of HOMER.
 */
struct __attribute__((packed)) HomerOccFfdcRegion
{
    uint8_t iv_occFfdcHeader[FFDC_OCC_REGION_HDR_SIZE];
    uint8_t iv_occTraceErrSize[FFDC_TRACE_ERR_SIZE];
    uint8_t iv_occTraceImpSize[FFDC_TRACE_IMP_SIZE];
    uint8_t iv_occTraceInfSize[FFDC_TRACE_INF_SIZE];
    uint8_t iv_occSsxSize[FFDC_TRACE_SSX_SIZE];
    uint8_t iv_occTraceGpe0Size[FFDC_TRACE_GPE0_SIZE];
    uint8_t iv_occTraceGpe1Size[FFDC_TRACE_GPE1_SIZE];
    uint8_t iv_occSharedSramSize[FFDC_SHARED_SRAM_SIZE];
};

/**
 * @brief   models full FFDC region of HOMER.
 */
struct  __attribute__((packed)) HomerFfdcRegion
{
    uint8_t iv_homerFfdcHeader[FFDC_HOMER_TOP_HEADER];
    HomerQuadFfdcRegion iv_quadFfdc[MAX_QUADS_PER_CHIP];
    PpeFfdcLayout       iv_sgpeFfdcRegion;
    PpeFfdcLayout       iv_pgpeFfdcRegion;
    HomerOccFfdcRegion  iv_occFfdcRegion;
};

}   //namespace p9_stop_recov_ffdc ends
#endif //__PM_RECOVERY_FFDC_DEFINES_
