/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_defines.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
 * @brief   enumerates all the sub-steps in a PM Reset Flow
 */
enum PmResetStep
{
    PM_RESET_UNKNOWN = 0x00,
    PM_RESET_INIT,
    PM_RESET_FFDC_SEC_INIT,
    PM_RESET_FFDC_CHK_PPE_HALT,
    PM_RESET_FFDC_GET_FIRS,
    PM_RESET_FIR_OCC,
    PM_RESET_OCC_CTRL,
    PM_RESET_SPL_WKUP_EX_ALL,
    PM_RESET_SET_AUTO_SPL_WKUP,
    PM_RESET_FIR_PBA,
    PM_RESET_FIR_PPM,
    PM_RESET_FIR_CME,
    PM_RESET_OCC_GPE,
    PM_RESET_PGPE,
    PM_RESET_SGPE,
    PM_RESET_EC_EQ,
    PM_RESET_PSAFE_UPDATE,
    PM_RESET_OCC_SRAM,
    PM_RESET_OCB,
    PM_RESET_PSS,
    PM_RESET_NOTIFY_PRD,
    PM_RESET_DONE = 0xFF  // Always the last
};

/**
 * @brief   enumerates all the platforms involved with STOP Recovery.
 */
enum PmComplexPlatId
{
    PLAT_INIT   =   0x00,
    PLAT_CME    =   0x01,
    PLAT_SGPE   =   0x02,
    PLAT_PGPE   =   0x03,
    PLAT_OCC    =   0x04,
    PLAT_CPPM   =   0x05,
    PLAT_QPPM   =   0x06,
    PLAT_MISC   =   0x07,
};

/**
 * @brief enumerates type of FFDC data
 */
enum FfdcDataType
{
    INIT             =  0x00, // initializes FFDC section headers
    IMAGE_HEADER     =  0x01, // collect PPE SRAM Image Header
    DASH_BOARD_VAR   =  0x02, // collect PPE GLobal Variables / Dash
    TRACES           =  0x04, // collect FW traces from SRAM
    INTERNAL_REG     =  0x08, // collect internal regsiters
    SCOM_REG         =  0x10, // collect SCOM registers
    PPE_STATE        =  0x20, // collect PPE SPRs, XIRs, and GPRs
    PPE_HALT_STATE   =  0x40, // collect the PPE Engine HALT State
    FIR_STATE        =  0x80,
    ALL              =  ( IMAGE_HEADER |
                          DASH_BOARD_VAR |
                          TRACES |
                          INTERNAL_REG |
                          SCOM_REG |
                          PPE_STATE |
                          PPE_HALT_STATE |
                          FIR_STATE)
};

/**
 * @brief enumerates bit positions used to mark sections in PM FFDC as valid
 */
enum PmFfdcSectionState
{
    PM_FFDC_INVALID        =   0x0000,  // none of the sections is valid
    PM_FFDC_FIR_VALID      =   0x0001,  // fir section valid
    PM_FFDC_QUAD0_VALID    =   0x0002,  // quad 0 section valid
    PM_FFDC_QUAD1_VALID    =   0x0004,  // quad 1 section valid
    PM_FFDC_QUAD2_VALID    =   0x0008,  // quad 2 section valid
    PM_FFDC_QUAD3_VALID    =   0x0010,  // quad 3 section valid
    PM_FFDC_QUAD4_VALID    =   0x0020,  // quad 4 section valid
    PM_FFDC_QUAD5_VALID    =   0x0040,  // quad 5 section valid
    PM_FFDC_SGPE_VALID     =   0x0080,  // sgpe section valid
    PM_FFDC_PGPE_VALID     =   0x0100,  // pgpe section valid
    PM_FFDC_OCC_VALID      =   0x0200,  // occ section valid
    PM_FFDC_VALID_ALL      =   ( PM_FFDC_FIR_VALID   |
                                 PM_FFDC_QUAD0_VALID |
                                 PM_FFDC_QUAD1_VALID |
                                 PM_FFDC_QUAD2_VALID |
                                 PM_FFDC_QUAD3_VALID |
                                 PM_FFDC_QUAD4_VALID |
                                 PM_FFDC_QUAD5_VALID |
                                 PM_FFDC_SGPE_VALID  |
                                 PM_FFDC_PGPE_VALID  |
                                 PM_FFDC_OCC_VALID )
};

/**
 * @brief enumerates bit position used as validity mark of PPE FFDC sub-section.
 */

enum PpeFfdcValidStatus
{
    PPE_FFDC_INVALID        = 0x0000,  //entire PPE FFDC is not valid
    PPE_DASHBOARD_VALID     = 0x0001,  // PPE globals are valid
    PPE_IMAGE_HEADER_VALID  = 0x0002,  // PPE image header is valid
    PPE_TRACE_VALID         = 0x0004,  // PPE Traces are valid
    PPE_STATE_VALID         = 0x0008,  // PPE XIRS, GPES and SPRs are valid
    PPE_INT_REG_VALID       = 0x0010,  // PPE Int Regs are valid
    PPE_HALT_STATE_VALID    = 0x0020,  // PPE Halt State Info is valid
    PPE_FFDC_ALL_VALID      = 0x003F,  // Entire PPE FFDC is valid
};

/**
 * @brief enumerates PPE's HALT conditions as inteprreted from XSR[0:3]
 */
enum PpeHaltCondition
{
    PPE_HALT_COND_NONE    = 0x00, // Not halted
    PPE_HALT_COND_BAD     = 0x08, // Halted, but cannot map source
    PPE_HALT_COND_XCR     = 0x09, // Halted via XCR
    PPE_HALT_COND_WDT     = 0x0A, // Halted via Watch Dog
    PPE_HALT_COND_NMI     = 0x0B, // Halted via unmaskable intr
    PPE_HALT_COND_DBG     = 0x0C, // Debug halt
    PPE_HALT_COND_DBCR    = 0x0D, // Halt via Debug Control Reg
    PPE_HALT_COND_EXT_HLT = 0x0E, // Ext halt_req input active
    PPE_HALT_COND_HW      = 0x0F, // Halted with a HW failure
    PPE_HALT_COND_UNKNOWN = 0xFF  // Could not read or interpret XSR
};

/**
 * @brief enumberates FFDC validity status.
 */
enum
{
    FFDC_SUMMARY_SUB_SEC_VALID      =   1,
    FFDC_SUMMARY_SUB_SEC_INVALID    =   0,
};

/**
 * @brief   Top level header of the PM Complex FFDC in HOMER
 */
struct __attribute__((packed)) PmFfdcHeader
{
    uint32_t  iv_magicNumber;     // Magic Word of Top Level PM FFDC
    uint8_t   iv_versionMajor;    // Major Version of the Layout Header
    uint8_t   iv_versionMinor;    // Minor Version of the Layout Header
    uint16_t  iv_headerSize;      // Size of this Header
    uint32_t  iv_sectionSize;     // Size of complete PM FFDC mapped by this
    uint8_t   iv_ffdcValid;       // Validity of the complete PM FFDC
    uint8_t   iv_phase;           // Last executed step in PM Reset
    uint16_t  iv_sectionsValid;   // See PmFfdcSectionState
    uint32_t  iv_procPosition;    // Logical position of Proc Chip in system
    uint16_t  iv_errorMarker;     // High level error marker
    uint16_t  iv_firOffset;       // Offset to FIR FFDC sub-section
    uint16_t  iv_quadOffset[MAX_QUADS_PER_CHIP];   // Offset to Quad subsections
    uint16_t  iv_sgpeOffset;      // Offset to the SGPE FFDC sub-section
    uint16_t  iv_pgpeOffset;      // Offset to the PGPE FFDC sub-section
    uint16_t  iv_occOffset;       // Offset to the OCC FFDC sub-section
    uint8_t   iv_reserved[6];     // Reserved
    uint32_t  iv_ccsr;            // CCSR on PM Reset entry
    uint32_t  iv_qcsr;            // QCSR on PM Reset entry
};

/**
 * @brief   models header of FFDC region of HOMER associated with a CME.
 */
struct __attribute__((packed)) PpeFfdcHeader
{
    uint32_t  iv_ppeMagicNumber;
    uint8_t   iv_versionMajor;
    uint8_t   iv_versionMinor;
    uint16_t  iv_headerSize;
    uint16_t  iv_sectionSize;
    uint16_t  iv_sectionsValid;
    uint8_t   iv_ppeNumber;
    uint8_t   iv_ppeHaltCondition;
    uint16_t  iv_dashBoardOffset;
    uint16_t  iv_sramHeaderOffset;
    uint16_t  iv_sprOffset;
    uint16_t  iv_intRegOffset;
    uint16_t  iv_offsetTraces;
};

/**
 * @brief models Quad FFDC header.
 */
struct __attribute__((packed)) QuadFfdcHeader
{
    uint32_t iv_quadMagicWord;
    uint8_t  iv_versionMajor;
    uint8_t  iv_versionMinor;
    uint16_t iv_quadHeaderSize;
    uint16_t iv_sectionSize;
    uint16_t iv_sectionsValid;
    uint8_t  iv_reserve1;
    uint8_t  iv_quadInstance;
    uint16_t iv_offsetCppm0;
    uint16_t iv_offsetCppm1;
    uint16_t iv_offsetCppm2;
    uint16_t iv_offsetCppm3;
    uint16_t iv_offsetCme0;
    uint16_t iv_offsetCme1;
    uint16_t iv_offsetQppm;
    uint8_t  iv_reserve2[4];
};


/**
 * @brief enumerates bit position used as validity mark of OCC FFDC sub-section.
 */
enum OccFfdcValidStatus
{
    OCC_FFDC_INVALID      =   0x0000,  // None of the FFDC section is valid
    OCC_FFDC_TRACE_ERR    =   0x0001,  // OCC ERR traces section valid
    OCC_FFDC_TRACE_IMP    =   0x0002,  // OCC IMP traces section valid
    OCC_FFDC_TRACE_INF    =   0x0004,  // OCC INF traces section valid
    OCC_FFDC_TRACE_SSX    =   0x0008,  // OCC SSX trace section valid
    OCC_FFDC_TRACE_GPE0   =   0x0010,  // OCC GPE0 Trace Section valid
    OCC_FFDC_TRACE_GPE1   =   0x0020,  // OCC GPE1 Trace Section Valid
    OCC_FFDC_SHARED_REGION =  0x0040,  // OCC Shared Region Section valid
    OCC_FFDC_REGISTERS    =   0x0080,  // OCC Register Section valid
    OCC_FFDC_VALID_ALL           =   ( OCC_FFDC_TRACE_ERR |
                                       OCC_FFDC_TRACE_IMP |
                                       OCC_FFDC_TRACE_INF |
                                       OCC_FFDC_TRACE_SSX |
                                       OCC_FFDC_TRACE_GPE0 |
                                       OCC_FFDC_TRACE_GPE1 |
                                       OCC_FFDC_SHARED_REGION |
                                       OCC_FFDC_REGISTERS)
};


/**
 * @brief models FIR FFDC header.
 * @note iv_validityVector bits 0:11  => CME0:11 FIR valid
 *                         bit  12    => OCC FIRs valid
 *                         bits 13:15 => Reserved
 */
const uint16_t PM_FFDC_FIR_VALID_POS_0 = 0x8000;
const uint8_t PM_FFDC_FIR_VALID_POS_MAX = 13;
const uint8_t PM_FFDC_FIR_VALID_POS_OCC = 12;

/**
 * @brief Models a SCOM register entry in FFDC
 */
struct __attribute__((packed)) FfdcScomEntry
{
    uint32_t iv_scomAddress;
    uint64_t iv_scomData;
};

struct __attribute__((packed)) FirFfdcHeader
{
    uint32_t iv_magicWord;
    uint8_t  iv_versionMajor;
    uint8_t  iv_versionMinor;
    uint16_t iv_headerSize;
    uint16_t iv_sectionSize;
    uint16_t iv_validityVector; // See note in doxygen above
    uint8_t  iv_reserved[4];
};

/**
 * @brief models C_Q_PPM FFDC header.
 */
struct __attribute__((packed)) PpmFfdcHeader
{
    uint32_t iv_ppmMagicWord;
    uint8_t  iv_versionMajor;
    uint8_t  iv_versionMinor;
    uint16_t iv_ppmHeaderSize;
    uint16_t iv_sectionSize;
    uint16_t iv_ffdcValid;
    uint8_t  iv_Instance;
    uint8_t  iv_reserved[3];
};

/**
 *  * @brief models OCC Region FFDC header.
 *   */
struct __attribute__((packed)) OccFfdcHeader
{
    uint32_t iv_magicWord;
    uint8_t  iv_versionMajor;
    uint8_t  iv_versionMinor;
    uint16_t iv_headerSize;
    uint16_t iv_sectionSize;
    uint16_t iv_sectionsValid;
    uint16_t iv_offsetErrTrace;
    uint16_t iv_offsetImpTrace;
    uint16_t iv_offsetInfTrace;
    uint16_t iv_offsetSsxTrace;
    uint16_t iv_offsetGpe0Trace;
    uint16_t iv_offsetGpe1Trace;
    uint16_t iv_offsetSharedSram;
    uint16_t iv_offsetOccRegs;
    uint8_t  iv_reserved[4];
};

/**
 * @brief   PM FFDC section header area
 */
union PmFfdcHdrRegion
{
    uint8_t      iv_pmFfdcHdrArea[FFDC_PM_HEADER_SIZE];
    PmFfdcHeader iv_pmFfdcHdr;
};

/**
 * @brief   a union modelling PPE FFDC region's header area.
 */
union PpeFfdcHdrRegion
{
    uint8_t iv_ppeFfdcHdrArea[FFDC_PPE_HDR_SIZE];
    PpeFfdcHeader iv_ppeFfdcHdr;
};

/**
 *  * @brief   a union modelling OCC FFDC region's header area.
 *   */
union OccFfdcHdrRegion
{
    uint8_t iv_ppeFfdcHdrArea[FFDC_OCC_REGION_HDR_SIZE];
    OccFfdcHeader iv_occFfdcHdr;
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
    uint8_t iv_ppeSpr[FFDC_PPE_SPR_SIZE];
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
    uint8_t iv_quadCppmRegion[MAX_CORES_PER_QUAD][FFDC_CPPM_REGION_SIZE];
    uint8_t iv_quadCmeBlock[MAX_CMES_PER_QUAD][FFDC_PPE_BLOCK_SIZE];
    uint8_t iv_quadQppmRegion[FFDC_QPPM_REGION_SIZE];
};

/**
 * @brief   models OCC FFDC region of HOMER.
 */
struct __attribute__((packed)) OccFfdcRegion
{
    uint8_t iv_occFfdcHeader[FFDC_OCC_REGION_HDR_SIZE];
    uint8_t iv_occTraceErr[FFDC_TRACE_ERR_SIZE];
    uint8_t iv_occTraceImp[FFDC_TRACE_IMP_SIZE];
    uint8_t iv_occTraceInf[FFDC_TRACE_INF_SIZE];
    uint8_t iv_occTraceSsx[FFDC_TRACE_SSX_SIZE];
    uint8_t iv_occTraceGpe0[FFDC_TRACE_GPE0_SIZE];
    uint8_t iv_occTraceGpe1[FFDC_TRACE_GPE1_SIZE];
    uint8_t iv_occSharedSram[FFDC_SHARED_SRAM_SIZE];
    uint8_t iv_occRegs[FFDC_OCC_REGS_SIZE];
};

/**
 * @brief   models Quad FFDC region of HOMER.
 */
struct __attribute__((packed)) FirFfdcRegion
{
    uint8_t iv_firFfdcHeader[FFDC_FIR_HDR_SIZE];
    uint8_t iv_firCmeBlock[MAX_CMES_PER_CHIP][FFDC_CME_FIR_REGISTERS_SIZE];
    uint8_t iv_OccPbaBlock[FFDC_FIR_REGISTER_SIZE];
};

/**
 * @brief   models the header for FFDC summary sub-section .
 */
struct __attribute__((packed)) FfdcSummSubSectHdr
{
    uint8_t  iv_subSectnId;
    uint8_t  iv_majorNum;
    uint8_t  iv_minorNum;
    uint8_t  iv_secValid;
};

/**
 * @brief   models the FFDC Summary sub-region containing system config and error info.
 */
struct __attribute__((packed)) SysState
{
    FfdcSummSubSectHdr iv_subSecHdr;
    uint8_t  iv_cmeFirs[MAX_CMES_PER_CHIP][FFDC_SUMMARY_SCOM_REG_SIZE];
    uint8_t  iv_occPbaFir[FFDC_SUMMARY_OCC_PBA_FIR_SIZE];
    uint8_t  iv_configReg[FFDC_SUMMARY_SIZE_SYS_CONFIG];
};

/**
 * @brief points to a block of FFDC sub-region.
 */
struct __attribute__((packed)) FfdcBlock
{
    uint8_t*  iv_dataPtr;
    uint32_t  iv_dataSize;
};

/**
 * models FFDC summary section in HOMER.
 */
struct  __attribute__((packed)) FfdcSummary
{
    uint32_t    iv_summaryMagicWord;
    SysState    iv_sysState;
    uint8_t     iv_sgpeSummary[FFDC_SUMMARY_SIZE_SGPE];
    uint8_t     iv_pgpeSummary[FFDC_SUMMARY_SIZE_PGPE];
    uint8_t     iv_cmeSummary[MAX_CMES_PER_CHIP][FFDC_SUMMARY_SIZE_CME];
    uint8_t     iv_qpmmRegSummary[MAX_QUADS_PER_CHIP][FFDC_SUMMARY_SIZE_QPPM_REG];
    uint8_t     iv_cpmmRegSummary[MAX_CORES_PER_CHIP][FFDC_SUMMARY_SIZE_CPPM_REG];
    FfdcBlock   iv_sgpeScoreBoard;
    FfdcBlock   iv_pgpeScoreBoard;
    FfdcBlock   iv_cmeScoreBoard[MAX_CMES_PER_CHIP];
};

/**
 * @brief   models full FFDC region of HOMER.
 */
struct  __attribute__((packed)) HomerFfdcRegion
{
    PmFfdcHdrRegion     iv_pmFfdcHdrRegion;
    FirFfdcRegion       iv_firFfdcRegion;
    HomerQuadFfdcRegion iv_quadFfdc[MAX_QUADS_PER_CHIP];
    PpeFfdcLayout       iv_sgpeFfdcRegion;
    PpeFfdcLayout       iv_pgpeFfdcRegion;
    OccFfdcRegion       iv_occFfdcRegion;
    FfdcSummary         iv_ffdcSummaryRegion;
};

}   //namespace p9_stop_recov_ffdc ends
#endif //__PM_RECOVERY_FFDC_DEFINES_
