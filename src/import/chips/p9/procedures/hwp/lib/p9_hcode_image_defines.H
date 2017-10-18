/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_hcode_image_defines.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file   p9_hcode_image_defines.H
/// @brief  defines constants associated with hcode image build.
///
// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    Hostboot: Phyp

#ifndef __HW_IMG_DEFINE
#define __HW_IMG_DEFINE

#include <p9_hcd_header_defs.H>
#include <p9_hcd_memmap_base.H>
#include <p9_hcd_memmap_homer.H>
#include <p9_hcd_memmap_occ_sram.H>
#include <p9_hcd_memmap_cme_sram.H>

#include <p9_pstates_cmeqm.h>
#include <p9_pstates_common.h>
#include <p9_pstates_occ.h>
#include <p9_pstates_pgpe.h>
#include <p9_pstates_table.h>

//--------------------------------------------------------------------------
// local structs and constants
// -------------------------------------------------------------------------
#ifndef __ASSEMBLER__
#ifdef __cplusplus
#ifndef __PPE_PLAT
namespace p9_hcodeImageBuild
{
#endif //__PPE_PLAT
#endif //__cplusplus
#endif //__ASSEMBLER__

//FIXME to make future addition simple, need a better solution
/**
 * @brief returns maximum quad common rings that enter HOMER.
 */

#define MAX_HOMER_QUAD_CMN_RINGS       (uint32_t)(EQ::g_chipletData.iv_num_common_rings - 4)
#define MAX_HOMER_CORE_CMN_RINGS       (uint32_t)(EC::g_chipletData.iv_num_common_rings - 2)

/**
 * @brief models QPMR header in HOMER
 */

#ifdef __ASSEMBLER__
.macro .qpmr_header
.section ".qpmr" , "aw"
.balign 8
#else
typedef struct
{
#endif  // __ASSEMBLER__

HCD_HDR_UINT64( magic_number, QPMR_MAGIC_NUMBER);  // QPMR_1.0
HCD_HDR_UINT32( bootCopierOffset, 0);  // level 1 boot loader
HCD_HDR_UINT32( reserve1, 0);
HCD_HDR_UINT32( bootLoaderOffset, 0);  // level 2 boot loader
HCD_HDR_UINT32( bootLoaderLength, 0);
HCD_HDR_UINT32( buildDate, 0);
HCD_HDR_UINT32( buildVersion, 0);
HCD_HDR_UINT64( reservedFlags, 0);
HCD_HDR_UINT32( sgpeImgOffset, 0);
HCD_HDR_UINT32( sgpeImgLength, 0);
HCD_HDR_UINT32( quadCommonRingOffset, 0);
HCD_HDR_UINT32( quadCommonRingLength, 0);
HCD_HDR_UINT32( quadCommonOvrdOffset, 0 );
HCD_HDR_UINT32( quadCommonOvrdLength, 0 );
HCD_HDR_UINT32( quadSpecRingOffset, 0);
HCD_HDR_UINT32( quadSpecRingLength, 0);
HCD_HDR_UINT32( quadScomOffset, 0);
HCD_HDR_UINT32( quadScomLength, 0);
HCD_HDR_UINT32( quadAuxOffset, 0);
HCD_HDR_UINT32( quadAuxLength, 0);
HCD_HDR_UINT32( stopFfdcOffset, 0);
HCD_HDR_UINT32( stopFfdcLength, 0);
HCD_HDR_UINT32( sgpeBootProgCode, 0 );
HCD_HDR_UINT32( sgpeSramImageSize, 0 );
HCD_HDR_PAD(512);
#ifdef __ASSEMBLER__
.endm
#else
}  __attribute__((packed, aligned(512))) QpmrHeaderLayout_t;
#endif
// @todo Get around the above hardcoding.


/**
 * CPMR Header
 *
 *  This header is only consumed by Hcode Image Build and
 *  lab tools, not by PPE code.  It is generated with assembler
 *  primitives during CME build and placed in HOMER by
 *  Hcode Image Build.
 */

#ifdef __ASSEMBLER__
.macro  .cpmr_header
.section ".cpmr" , "aw"
.balign    8
#else
typedef struct
{
#endif
HCD_HDR_ATTN  ( attnOpcodes, 2);
HCD_HDR_UINT64( magic_number, CPMR_MAGIC_NUMBER);
HCD_HDR_UINT32( cpmrbuildDate, 0);
HCD_HDR_UINT32( cpmrVersion, 0);
HCD_HDR_UINT8_VEC (cpmrReserveFlags, 7, 0);
HCD_HDR_UINT8 ( fusedModeStatus, 0);
HCD_HDR_UINT32( cmeImgOffset, 0);
HCD_HDR_UINT32( cmeImgLength, 0);
HCD_HDR_UINT32( cmeCommonRingOffset, 0);
HCD_HDR_UINT32( cmeCommonRingLength, 0);
HCD_HDR_UINT32( cmePstateOffset, 0);
HCD_HDR_UINT32( cmePstateLength, 0);
HCD_HDR_UINT32( coreSpecRingOffset, 0);
HCD_HDR_UINT32( coreSpecRingLength, 0);
HCD_HDR_UINT32( coreScomOffset, 0);
HCD_HDR_UINT32( coreScomLength, 0);
HCD_HDR_PAD(CPMR_HEADER_SIZE);
#ifdef __ASSEMBLER__
.endm
#else
} __attribute__((packed, aligned(256))) cpmrHeader_t;
#endif


// @todo Get around the above hardcoding.

/**
 * PPMR Header
 *
 *  This header is only consumed by Hcode Image Build and
 *  lab tools, not by PPE code.  It is generated with assembler
 *  primitives during PGPE build and placed in HOMER by
 *  Hcode Image Build.
 */

#ifdef __ASSEMBLER__
.macro  .ppmr_header
.section ".ppmr_header" , "aw"
.balign    8
#else
typedef struct
{
#endif
//Offset are wrt to start of PPMR unless specified otherwise
//length in bytes unless specified otherwise.
HCD_HDR_UINT64(g_ppmr_magic_number, PPMR_MAGIC_NUMBER);  // PPMR_1.0
HCD_HDR_UINT32(g_ppmr_bc_offset,    0 );  // PGPE Level1 Boot loader
HCD_HDR_UINT32(g_ppmr_reserve1,     0 );
HCD_HDR_UINT32(g_ppmr_bl_offset,    0 );  // PGPE Level2 Boot loader
HCD_HDR_UINT32(g_ppmr_bl_length,    0 );  // PGPE Level2 Boot loader
HCD_HDR_UINT32(g_ppmr_build_date,   0 );  // Build date for PGPE Image
HCD_HDR_UINT32(g_ppmr_build_ver,    0 );  // Build Version
HCD_HDR_UINT64(g_ppmr_reserve_flag, 0 );  // Reserve Flag
HCD_HDR_UINT32(g_ppmr_hcode_offset, 0 );  // Offset to start of PGPE Hcode
HCD_HDR_UINT32(g_ppmr_hcode_length, 0 );  // PGPE Hcode length in Bytes
HCD_HDR_UINT32(g_ppmr_gppb_offset,  0 );  // Offset to Global P State Parameter Block
HCD_HDR_UINT32(g_ppmr_gppb_length,  0 );  // Length of Global P State Parameter Block
HCD_HDR_UINT32(g_ppmr_lppb_offset,  0 );  // Offset to Local P State Parameter Block
HCD_HDR_UINT32(g_ppmr_lppb_length,  0 );  // Length of Local P State Parameter Block
HCD_HDR_UINT32(g_ppmr_oppb_offset,  0 );  // Offset to OCC P State Parameter Block
HCD_HDR_UINT32(g_ppmr_oppb_length,  0 );  // Length of OCC P State Parameter Block
HCD_HDR_UINT32(g_ppmr_pstables_offset, 0); // Offset to PState Table
HCD_HDR_UINT32(g_ppmr_pstables_length, 0); // Length of P State table
HCD_HDR_UINT32(g_ppmr_pgpe_sram_img_size, 0); // PGPE Actual SRAM Image Size
HCD_HDR_UINT32(g_ppmr_pgpe_boot_prog_code, 0 );// for debug of PGPE booting
HCD_HDR_UINT32(g_ppmr_wof_table_offset, 0 );    // Offset to start of WOF Table
HCD_HDR_UINT32(g_ppmr_wof_table_length, 0 );   // Length of WOF table
HCD_HDR_UINT32(g_ppmr_aux_task_offset,    0 );  // PGPE Aux Task Offset
HCD_HDR_UINT32(g_ppmr_aux_task_length,    0 );  // PGPE Aux Task Length
HCD_HDR_PAD(0x200);
#ifdef __ASSEMBLER__
.endm
#else
} __attribute__((packed, aligned(0x200))) PpmrHeader_t;
#endif

/**
 * SGPE Header
 *
 * The SGPE header is loaded in the OCC SRAM.  Structure member names are
 * preceded with "g_" as these becoming global variables in the SGPE Hcode.
 *
 * The Linker script maps this header to an SRAM address range after interrupt
 * vector area. Some fields will be populated during Hcode image build activity.
 * Build date, version, Hcode offset and position are populated during SGPE
 * Image build process.
 */

#define IMG_HDR_ALIGN_SIZE 32
#ifdef __ASSEMBLER__
.macro .sgpe_header
.section ".sgpe_image_header" , "aw"
.balign    8
#else
typedef struct
{
#endif
HCD_HDR_UINT64(g_sgpe_magic_number, SGPE_MAGIC_NUMBER);   //SGPE 1.0
HCD_HDR_UINT32(g_sgpe_reset_address, 0);
HCD_HDR_UINT32(g_sgpe_reserve1, 0);
HCD_HDR_UINT32(g_sgpe_ivpr_address, 0);
HCD_HDR_UINT32(g_sgpe_timebase_hz, 0);
HCD_HDR_UINT32(g_sgpe_build_date, 0);
HCD_HDR_UINT32(g_sgpe_build_ver, 0);
HCD_HDR_UINT32(g_sgpe_reserve_flags, 0);
HCD_HDR_UINT16(g_sgpe_location_id, 0);
HCD_HDR_UINT16(g_sgpe_addr_extension, 0);
HCD_HDR_UINT32(g_sgpe_cmn_ring_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_cmn_ring_ovrd_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_spec_ring_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_scom_offset, 0);
HCD_HDR_UINT32(g_sgpe_scom_mem_offset, 0);
HCD_HDR_UINT32(g_sgpe_scom_mem_length, 0);
HCD_HDR_UINT32(g_sgpe_aux_offset, 0);
HCD_HDR_UINT32(g_sgpe_aux_length, 0);
HCD_HDR_UINT32(g_sgpe_aux_control, 0);
HCD_HDR_UINT32(g_sgpe_reserve4, 0);
HCD_HDR_UINT64(g_sgpe_chtm_mem_cfg, 0);
HCD_HDR_PAD(IMG_HDR_ALIGN_SIZE);
#ifdef __ASSEMBLER__
.endm
#else
//FIXME RTC 155018
//Eventually SGPE Img header has been defined to be of size 96B. Next 36B would be for
//debug pointer.Aligning SGPE image header to 64B boundary.
} __attribute__((packed, aligned(IMG_HDR_ALIGN_SIZE))) sgpeHeader_t;
#endif


/**
 * CME Header
 *
 * The CME header is loaded in the CME SRAM so it is "tight" (little extra space)
 * Thus, this "structure" is NOT padded to a specific size and is limited to
 * 64B.  Also, structure member names are preceded with "g_" as these becoming
 * global variables in the CME Hcode.
 */
#ifdef __ASSEMBLER__
.macro  .cme_header
.section ".cme_image_header" , "aw"
.balign    8
#else
typedef struct
{
#endif
HCD_HDR_UINT64(g_cme_magic_number, CME_MAGIC_NUMBER);
HCD_HDR_UINT32(g_cme_hcode_offset, 0);
HCD_HDR_UINT32(g_cme_hcode_length, 0);
HCD_HDR_UINT32(g_cme_common_ring_offset, 0);
HCD_HDR_UINT32(g_cme_cmn_ring_ovrd_offset, 0);
HCD_HDR_UINT32(g_cme_common_ring_length, 0);
HCD_HDR_UINT32(g_cme_pstate_region_offset, 0);
HCD_HDR_UINT32(g_cme_pstate_region_length, 0);
HCD_HDR_UINT32(g_cme_core_spec_ring_offset, 0);
HCD_HDR_UINT32(g_cme_max_spec_ring_length, 0);
HCD_HDR_UINT32(g_cme_scom_offset, 0);
HCD_HDR_UINT32(g_cme_scom_length, 0);
HCD_HDR_UINT32(g_cme_mode_flags, 0);
HCD_HDR_UINT16(g_cme_location_id, 0);
HCD_HDR_UINT16(g_cme_qm_mode_flags, 0);
HCD_HDR_UINT32(g_cme_timebase_hz, 0); //Retain next field at 8B boundary
HCD_HDR_UINT64(g_cme_cpmr_PhyAddr, 0);
HCD_HDR_PAD(IMG_HDR_ALIGN_SIZE);
#ifdef __ASSEMBLER__
.endm
#else
//FIXME RTC 155018
//Eventually CME Img header might be of size 96B. Next 36B would be for
//debug pointer.Aligning CME image header to 64B boundary.
} __attribute__((packed, aligned(IMG_HDR_ALIGN_SIZE))) cmeHeader_t;
#endif

#ifndef __ASSEMBLER__

typedef struct CMEImageFlags
{
    uint32_t fused_mode     : 1;
    uint32_t reserved0      : 31;
} CMEImageFlags_t;

#endif //__ASSEMBLER__

/**
 * PGPE Header
 *
 * The PGPE header is loaded in the OCC SRAM so it is "tight" (little extra space)
 * Also, structure member names are preceded with "g_" as these becoming
 * global variables in the PGPE Hcode.
 */
#ifdef __ASSEMBLER__
.macro  .pgpe_header
.section ".pgpe_image_header" , "aw"
.balign    8
#else
typedef struct
{
#endif
HCD_HDR_UINT64(g_pgpe_magic_number, PGPE_MAGIC_NUMBER);     // PGPE_1.0
HCD_HDR_UINT32(g_pgpe_sys_reset_addr,             0 );      // Fully qualified OCC address where pk_init resides
HCD_HDR_UINT32(g_pgpe_shared_sram_addr,           0 );      // SRAM address where shared SRAM begins
HCD_HDR_UINT32(g_pgpe_ivpr_addr,                  0 );      // Beginning of PGPE region in OCC SRAM
HCD_HDR_UINT32(g_pgpe_shared_sram_len,            0 );      // Length of shared SRAM area
HCD_HDR_UINT32(g_pgpe_build_date,                 0 );      // Build date for PGPE Image
HCD_HDR_UINT32(g_pgpe_build_ver,                  0 );      // Build Version
HCD_HDR_UINT16(g_pgpe_flags,                      0 );      // PGPE Flags
HCD_HDR_UINT16(g_pgpe_reserve1,                   0 );      // Reserve field
HCD_HDR_UINT32(g_pgpe_timebase_hz,                0 );      // Timebase (in Hz) - dependent on nest frequency
HCD_HDR_UINT32(g_pgpe_gppb_sram_addr,             0 );      // Offset to Global P State Parameter Block
HCD_HDR_UINT32(g_pgpe_hcode_length,               0 );      // Length of PGPE Hcode
HCD_HDR_UINT32(g_pgpe_gppb_mem_offset,
               0 );        // Offset to start of Global PS Param Block wrt start of HOMER.
HCD_HDR_UINT32(g_pgpe_gppb_length,              0 );        // Length of Global P State Parameter Block
HCD_HDR_UINT32(g_pgpe_gen_pstables_mem_offset,  0 );        // Offset to PState Table wrt start of HOMER
HCD_HDR_UINT32(g_pgpe_gen_pstables_length,      0 );        // Length of P State table
HCD_HDR_UINT32(g_pgpe_occ_pstables_sram_addr,   0 );        // Offset to start of OCC P-State table
HCD_HDR_UINT32(g_pgpe_occ_pstables_len,         0 );        // Length of OCC P-State table
HCD_HDR_UINT32(g_pgpe_beacon_addr,              0 );        // SRAM addr where PGPE beacon is located
HCD_HDR_UINT32(g_quad_status_addr,              0 );
HCD_HDR_UINT32(g_pgpe_wof_state_address,        0 );        // SRAM address where PGPE WOF State is located
HCD_HDR_UINT32(g_pgpe_req_active_quad_address,  0 );        // SRAM address where requested quad status is located
HCD_HDR_UINT32(g_wof_table_addr,                0 );        // SRAM address where WOF Table is Located
HCD_HDR_UINT32(g_wof_table_length,              0 );        // WOF Table length in bytes
HCD_HDR_UINT32(g_pgpe_core_throttle_assert_cnt, 0 );        // Core throttle assert count
HCD_HDR_UINT32(g_pgpe_core_throttle_deassert_cnt, 0 );      // Core throttle de-aasert count
HCD_HDR_UINT32(g_pgpe_aux_controls,             0 );        // Auxiliary Controls
#ifdef __ASSEMBLER__
.endm
#else
//FIXME RTC 155018
//Eventually PGPE Img header has been defined to be of size 96B. Next 36B would be for
//debug pointer.Aligning PGPE image header to 64B boundary.
} __attribute__((packed, aligned(IMG_HDR_ALIGN_SIZE))) PgpeHeader_t;
#endif

#ifndef __ASSEMBLER__

/**
 * @brief   enumerates all return codes associated with hcode image build.
 */
enum ImgBldRetCode_t
{
    IMG_BUILD_SUCCESS           =   0,
    BUILD_FAIL_SGPE_IMAGE       =   1,
    BUILD_FAIL_SELF_REST_IMAGE  =   2,
    BUILD_FAIL_CME_IMAGE        =   3,
    BUILD_FAIL_PGPE_IMAGE       =   4,
    BUILD_FAIL_SGPE_QPMR        =   5,
    BUILD_FAIL_SGPE_BL1         =   6,
    BUILD_FAIL_SGPE_BL2         =   7,
    BUILD_FAIL_SGPE_INT_VECT    =   8,
    BUILD_FAIL_SGPE_HDR         =   9,
    BUILD_FAIL_SGPE_HCODE       =   10,
    BUILD_FAIL_SGPE_CMN_RINGS   =   11,
    BUILD_FAIL_SGPE_SPEC_RINGS  =   12,
    BUILD_FAIL_CPMR_HDR         =   13,
    BUILD_FAIL_SRESET_HNDLR     =   14,
    BUILD_FAIL_THRD_LAUNCHER    =   15,
    BUILD_FAIL_SPR_RESTORE      =   16,
    BUILD_FAIL_SCOM_RESTORE     =   17,
    BUILD_FAIL_CME_IMG_HDR      =   18,
    BUILD_FAIL_CME_HCODE        =   19,
    BUILD_FAIL_CMN_RINGS        =   20,
    BUILD_FAIL_CME_QUAD_PSTATE  =   21,
    BUILD_FAIL_SPEC_RINGS       =   22,
    BUILD_FAIL_INT_VECT         =   23,
    BUILD_FAIL_PGPE_BL1         =   24,
    BUILD_FAIL_PGPE_BL2         =   25,
    BUILD_FAIL_PGPE_HCODE       =   26,
    BUILD_FAIL_OVERRIDE         =   27,
    BUILD_SEC_SIZE_OVERFLOW     =   28,
    BUILD_FAIL_INVALID_SECTN    =   29,
    BUILD_FAIL_RING_EXTRACTN    =   30,
    CME_SRAM_IMG_SIZE_ERR       =   31,
    SGPE_SRAM_IMG_SIZE_ERR      =   32,
    PGPE_SRAM_IMG_SIZE_ERR      =   33,
    BUILD_FAIL_PGPE_PPMR        =   34,
    BUILD_FAIL_RING_SEL_EQ_INEX =   35,
    BUILD_FAIL_XIP_CUST_ERR     =   36,
    BUILD_ERR_INTERNAL          =   0xffff,
};

/**
 * @brief   models layout of core common rings in HOMER.
 * @note    Ring list below is primarily for debug.
 */
typedef struct
{
    uint16_t    ecFuncRing;
    uint16_t    ecGptrRing;
    uint16_t    ecTimeRing;
    uint16_t    ecModeRing;
    uint16_t    ecabstRing;
    uint8_t     reserved[6];
} CoreCmnRingsList_t;

typedef struct
{
    CoreCmnRingsList_t cmnRings;
    uint8_t     cmnScanRingPayload[CORE_COMMON_RING_SIZE - sizeof(CoreCmnRingsList_t)];
} CoreCmnRingsCme_t;

typedef union
{
    CoreCmnRingsCme_t cmnRingIndex;
    uint8_t cmnScanRings[CORE_COMMON_RING_SIZE];
} CoreCmnRingLayout_t;

/**
 * @brief   models layout of core instance specific ring in HOMER.
 * @note    Ring list below is primarily for debug.
 */
typedef struct
{
    uint16_t ecRepr0;
    uint16_t ecRepr1;
    uint8_t  ecReserve[4];
} CoreSpecRingList_t;
typedef struct
{
    CoreSpecRingList_t coreSpecRings;
    uint8_t  instanceRingPayLoad[ CORE_SPECIFIC_RING_SIZE_PER_CORE - sizeof(CoreSpecRingList_t)];
} CoreSpecRingCme_t;

typedef union
{
    CoreSpecRingCme_t instRingIndex;
    uint8_t instScanRings[ CORE_SPECIFIC_RING_SIZE_PER_CORE ];
} CoreSpecRingLayout_t;

/**
 * @brief   models layout of quad common rings in HOMER.
 * @note    this layout resides in QPMR region and is consumed by SGPE.
 *          Ring list below is primarily for debug.
 */

typedef struct
{
    uint16_t    eqFureRing;
    uint16_t    eqGptrRing;
    uint16_t    eqTimeRing;
    uint16_t    eqInexRing;
    uint16_t    exL3FureRing;
    uint16_t    exL3GptrRing;
    uint16_t    exL3TimeRing;
    uint16_t    exL2ModeRing;
    uint16_t    exL2FureRing;
    uint16_t    exL2GptrRing;
    uint16_t    exL2TimeRing;
    uint16_t    exL3RefrFureRing;
    uint16_t    exL3RefrGptrRing;
    uint16_t    eqAnaFuncRing;
    uint16_t    eqAnaGptrRing;
    uint16_t    eqDpllFuncRing;
    uint16_t    eqDpllGptrRing;
    uint16_t    eqDpllModeRing;
    uint16_t    eqAnaBndyRingBucket0;
    uint16_t    eqAnaBndyRingBucket1;
    uint16_t    eqAnaBndyRingBucket2;
    uint16_t    eqAnaBndyRingBucket3;
    uint16_t    eqAnaBndyRingBucket4;
    uint16_t    eqAnaBndyRingBucket5;
    uint16_t    eqAnaBndyRingBucket6;
    uint16_t    eqAnaBndyRingBucket7;
    uint16_t    eqAnaBndyRingBucket8;
    uint16_t    eqAnaBndyRingBucket9;
    uint16_t    eqAnaBndyRingBucket10;
    uint16_t    eqAnaBndyRingBucket11;
    uint16_t    eqAnaBndyRingBucket12;
    uint16_t    eqAnaBndyRingBucket13;
    uint16_t    eqAnaBndyRingBucket14;
    uint16_t    eqAnaBndyRingBucket15;
    uint16_t    eqAnaBndyRingBucket16;
    uint16_t    eqAnaBndyRingBucket17;
    uint16_t    eqAnaBndyRingBucket18;
    uint16_t    eqAnaBndyRingBucket19;
    uint16_t    eqAnaBndyRingBucket20;
    uint16_t    eqAnaBndyRingBucket21;
    uint16_t    eqAnaBndyRingBucket22;
    uint16_t    eqAnaBndyRingBucket23;
    uint16_t    eqAnaBndyRingBucket24;
    uint16_t    eqAnaBndyRingBucket25;
    uint16_t    eqAnaBndyRingl3dccBucket;
    uint16_t    eqAnaModeRing;
    uint16_t    eqAnaBndyRingBucket26;
    uint16_t    eqAnaBndyRingBucket27;
    uint16_t    eqAnaBndyRingBucket28;
    uint16_t    eqAnaBndyRingBucket29;
    uint16_t    eqAnaBndyRingBucket30;
    uint16_t    eqAnaBndyRingBucket31;
    uint16_t    eqAnaBndyRingBucket32;
    uint16_t    eqAnaBndyRingBucket33;
    uint16_t    eqAnaBndyRingBucket34;
    uint16_t    eqAnaBndyRingBucket35;
    uint16_t    eqAnaBndyRingBucket36;
    uint16_t    eqAnaBndyRingBucket37;
    uint16_t    eqAnaBndyRingBucket38;
    uint16_t    eqAnaBndyRingBucket39;
    uint16_t    eqAnaBndyRingBucket40;
    uint16_t    eqAnaBndyRingBucket41;
} QuadCmnRingsList_t;

typedef struct
{
    QuadCmnRingsList_t   quadCmnRingList;
    uint8_t             cmnRingPayLoad[QUAD_COMMON_RING_SIZE - sizeof(QuadCmnRingsList_t)];
} QuadCmnRingsSgpe_t;

typedef union
{
    QuadCmnRingsSgpe_t cmnRingIndex;
    uint8_t cmnScanRings[QUAD_COMMON_RING_SIZE];
} CmnRingLayoutSgpe_t;

/**
 * @brief   models layout of quad/ex instance specific ring in HOMER.
 * @note    this layout resides in QPMR region and is consumed by SGPE.
 *          Ring list below is primarily for debug.
 */
typedef struct
{
    uint16_t eqRepr0Index;
    uint16_t ex0L3ReprIndex;
    uint16_t ex1L3ReprIndex;
    uint16_t ex0L2ReprIndex;
    uint16_t ex1L2ReprIndex;
    uint16_t ex0L3RefrReprIndex;
    uint16_t ex1L3RefrReprIndex;
    uint16_t ex0L3RefrTimeIndex;
    uint16_t ex1L3RefrTimeIndex;
    uint8_t  eqReserve[6];
} QuadSpecRingsList_t;

typedef struct
{
    QuadSpecRingsList_t quadSpecRings[MAX_QUADS_PER_CHIP];
    uint8_t quadSpecRingPayLoad[ QUAD_SPECIFIC_RING_SIZE_TOTAL - (MAX_QUADS_PER_CHIP * sizeof(QuadSpecRingsList_t))];
} QuadSpecRing_t;

typedef union
{
    QuadSpecRing_t instRingIndex;
    uint8_t instScanRings[ QUAD_SPECIFIC_RING_SIZE_TOTAL ];
} InstRingLayoutSgpe_t;

/**
 * @brief   models image section of SGPE in HOMER.
 */
typedef struct
{
    uint8_t qpmrHeader[sizeof(QpmrHeaderLayout_t)];
    uint8_t l1BootLoader[SGPE_BOOT_COPIER_SIZE];
    uint8_t l2BootLoader[SGPE_BOOT_LOADER_SIZE];
    uint8_t sgpeSramImage[SGPE_IMAGE_SIZE];
} SgpeLayout_t;

typedef union CPMRSelfRestoreLayout
{
    uint8_t region[SELF_RESTORE_CODE_SIZE];
    struct
    {
        cpmrHeader_t CPMRHeader;
        uint8_t      exe[SELF_RESTORE_CODE_SIZE - sizeof(cpmrHeader_t)];
    } elements;
} CPMRSelfRestoreLayout_t;

/**
 * @brief   models image section associated with core self restore in HOMER.
 */
typedef struct
{
    CPMRSelfRestoreLayout_t CPMR_SR;
    uint8_t                 coreSelfRestore[SELF_RESTORE_CORE_REGS_SIZE];
    uint8_t                 reserve[CORE_SCOM_RESTORE_CPMR_OFFSET - SELF_RESTORE_SIZE_TOTAL];
    uint8_t                 coreScom[CORE_SCOM_RESTORE_SIZE_TOTAL];
} SelfRestoreLayout_t;

typedef struct
{
    SelfRestoreLayout_t     selfRestoreRegion;
    uint8_t                 cmeSramRegion[CME_REGION_SIZE];
} CPMRLayout_t;

/**
 * @brief   models image section associated with PGPE in HOMER.
 */
typedef struct
{
    uint8_t  ppmrHeader[PPMR_HEADER_SIZE];
    uint8_t  l1BootLoader[PGPE_BOOT_COPIER_SIZE];
    uint8_t  l2BootLoader[PGPE_BOOT_LOADER_SIZE];
    uint8_t  pgpeSramImage[PGPE_IMAGE_SIZE];     // Includes the Global Pstate Parameter Block
    uint8_t  aux_task[PGPE_AUX_TASK_SIZE];
    uint8_t  ppmr_reserved0[PGPE_IMAGE_RESERVE_SIZE];
    uint8_t  occParmBlock[sizeof(OCCPstateParmBlock)];  // PPMR + 128KB
    uint8_t  occParmBlockReserve[OCC_PSTATE_PARAM_BLOCK_REGION_SIZE - sizeof(OCCPstateParmBlock)];
    uint8_t  pstateTable[sizeof(GeneratedPstateInfo)];  // PPMR + 144KB
    uint8_t  pstateTableReserve[PGPE_PSTATE_OUTPUT_TABLES_REGION_SIZE - sizeof(GeneratedPstateInfo)];
    uint8_t  ppmr_reserved1[WOF_TABLE_RESERVE];
    uint8_t  wofTableSize[OCC_WOF_TABLES_SIZE]; //WOF Tables located ar PPMR base + 768KB
} PPMRLayout_t;

/**
 * @brief   models QPMR in HOMER.
 */
typedef struct
{
    SgpeLayout_t        sgpeRegion;
    uint8_t             qpmrReserve1[QUAD_SCOM_RESTORE_QPMR_OFFSET - sizeof(SgpeLayout_t)];
    uint8_t             cacheScomRegion[QUAD_SCOM_RESTORE_SIZE_TOTAL];
} QPMRLayout_t;

/**
 * @brief   models layout of HOMER.
 */
typedef struct
{
    uint8_t occHostArea[OCC_HOST_AREA_SIZE];
    QPMRLayout_t qpmrRegion;
    uint8_t      qpmrReserve[ONE_MB - sizeof( QPMRLayout_t )];
    CPMRLayout_t cpmrRegion;
    uint8_t      cppmReserve[ONE_MB - sizeof( CPMRLayout_t )];
    PPMRLayout_t ppmrRegion;
    uint8_t      pgpeReserve[ONE_MB - sizeof( PPMRLayout_t )];
} Homerlayout_t;

#ifdef __cplusplus
#ifndef __PPE_PLAT
}// namespace p9_hcodeImageBuild ends
#endif //__PPE_PLAT
#endif //__cplusplus

#endif //__ASSEMBLER__
#endif //__HW_IMG_DEFINE
