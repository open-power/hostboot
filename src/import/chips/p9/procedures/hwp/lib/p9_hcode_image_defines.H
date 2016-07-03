/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_hcode_image_defines.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
//--------------------------------------------------------------------------
// local structs and constants
// -------------------------------------------------------------------------
#ifndef __ASSEMBLER__

#ifndef __PPE_PLAT
namespace p9_hcodeImageBuild
{
#endif //__PPE_PLAT

#endif //__ASSEMBLER__

// Constants used in both C++ and Assembler/Linker code
CONST_UINT32_T(CPMR_HEADER_SIZE, 256);
CONST_UINT32_T(QPMR_HEADER_SIZE, 512);

//#pragma message (STR(CPMR_HEADER_SIZE))

// Define the Magic Numbers for the various images
HCD_MAGIC_NUMBER(CPMR_MAGIC_NUMBER, ULL(0x43504d525f312e30));  // CPMR_1.0
HCD_MAGIC_NUMBER(QPMR_MAGIC_NUMBER, ULL(0x51504d525f312e30));  // QPMR_1.0
HCD_MAGIC_NUMBER(CME_MAGIC_NUMBER , ULL(0x434d455f5f312e30));  // CME__1.0
HCD_MAGIC_NUMBER(PGPE_MAGIC_NUMBER , ULL(0x504750455F312E30)); // PGPE_1.0


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
HCD_HDR_UINT32( quadSpecRingOffset, 0);
HCD_HDR_UINT32( quadSpecRingLength, 0);
HCD_HDR_UINT32( quadSpecScomOffset, 0);
HCD_HDR_UINT32( quadSpecScomLength, 0);
HCD_HDR_UINT32( quadCmnRingOccOffset, 0);
HCD_HDR_UINT32( quadSpecRingOccOffset, 0);
HCD_HDR_UINT32( quadCmnScomOccOffset, 0);
HCD_HDR_PAD(512);
//HCD_HDR_PAD(QPMR_HEADER_SIZE);
#ifdef __ASSEMBLER__
.endm
#else
}  __attribute__((packed, aligned(512))) QpmrHeaderLayout_t;
//} __attribute__((packed, aligned(QPMR_HEADER_SIZE))) QpmrHeaderLayout_t;
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
HCD_HDR_UINT64( magic_number, CPMR_MAGIC_NUMBER);  // CPMR_1.0
HCD_HDR_UINT32( cpmrbuildDate, 0);
HCD_HDR_UINT32( cpmrVersion, 0);
HCD_HDR_UINT8_VEC (cpmrReserveFlags, 7, 0);
HCD_HDR_UINT8 ( fuseModeStatus, 0);
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
HCD_HDR_PAD(256);
//HCD_HDR_PAD(CPMR_HEADER_SIZE);
#ifdef __ASSEMBLER__
.endm
#else
} __attribute__((packed, aligned(256))) cpmrHeader_t;
//} __attribute__((packed, aligned(CPMR_HEADER_SIZE))) cpmrHeader_t;
#endif

// @todo Get around the above hardcoding.

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
HCD_HDR_UINT64(g_sgpe_magic_number, P9_XIP_MAGIC_SGPE);   //XIP SGPE
HCD_HDR_UINT32(g_sgpe_reset_address, 0);
HCD_HDR_UINT32(g_sgpe_reserve1, 0);
HCD_HDR_UINT32(g_sgpe_ivpr_address, 0);
HCD_HDR_UINT32(g_sgpe_reserve2, 0);
HCD_HDR_UINT32(g_sgpe_build_date, 0);
HCD_HDR_UINT32(g_sgpe_build_ver, 0);
HCD_HDR_UINT64(g_sgpe_reserve_flags, 0);
HCD_HDR_UINT32(g_sgpe_cmn_ring_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_cmn_ring_ovrd_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_spec_ring_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_spec_ring_ovrd_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_cmn_scom_offset, 0);
HCD_HDR_UINT32(g_sgpe_reserve3, 0);
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
HCD_HDR_UINT64(g_cme_magic_number, CME_MAGIC_NUMBER);  // CME__1.0
HCD_HDR_UINT32(g_cme_hcode_offset, 0);
HCD_HDR_UINT32(g_cme_hcode_length, 0);
HCD_HDR_UINT32(g_cme_common_ring_offset, 0);
HCD_HDR_UINT32(g_cme_cmn_ring_ovrd_offset, 0);
HCD_HDR_UINT32(g_cme_common_ring_length, 0);
HCD_HDR_UINT32(g_cme_pstate_region_offset, 0);
HCD_HDR_UINT32(g_cme_pstate_region_length, 0);
HCD_HDR_UINT32(g_cme_core_spec_ring_offset, 0);
HCD_HDR_UINT32(g_cme_core_spec_ring_ovrd_offset, 0);
HCD_HDR_UINT32(g_cme_max_spec_ring_length, 0);
HCD_HDR_UINT32(g_cme_scom_offset, 0);
HCD_HDR_UINT32(g_cme_scom_length, 0);
HCD_HDR_UINT32(g_cme_mode_flags, 0);
HCD_HDR_UINT32(g_cme_reserved1, 0);
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
 * Thus, this "structure" is NOT padded to a specific size and is limited to
 * 64B.  Also, structure member names are preceded with "g_" as these becoming
 * global variables in the CME Hcode.
 */
#ifdef __ASSEMBLER__
.macro  .pgpe_header
.section ".pgpe_header" , "aw"
.balign    8
#else
typedef struct
{
#endif
HCD_HDR_UINT64(g_pgpe_magic_number, PGPE_MAGIC_NUMBER);  // PGPE_1.0
HCD_HDR_UINT32(g_pgpe_build_date, 0);
HCD_HDR_UINT32(g_pgpe_build_ver, 0);
HCD_HDR_UINT32(g_pgpe_hcode_offset, 0);
HCD_HDR_UINT32(g_pgpe_hcode_length, 0);
HCD_HDR_PAD(IMG_HDR_ALIGN_SIZE);
//FIXME Need to get info on other fields
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
 * @brief   summarizes constants associated with hcode image build.
 */
enum
{
    ONE_KB                      = 1024,
    ONE_MB                      = 1024 * 1024,
    HALF_KB                     = 512,
    HARDWARE_IMG_SIZE           = ONE_MB,
    OCC_HOST_AREA_SIZE          = ONE_MB,
    HOMER_OCC_REGION_NUM        = 0,
    HOMER_QPMR_REGION_NUM       = 1,
    HOMER_CMPR_REGION_NUM       = 2,
    HOMER_PPMR_REGION_NUM       = 3,
    MAX_CORES_PER_CHIP          = 24,
    MAX_CME_PER_CHIP            = 12,
    CORE0_CHIPLET_ID            = 0x20,
    PAD_OPCODE                  = 0x00000200,   //ATTN Opcode
    PPE_RESERVE_AREA            = 0x200,
    FUSE_STATE                  = 0xAA,
    UNFUSE_STATE                = 0xBB,
    PK_DBG_PTR_AREA_SIZE        = 64,

    // QPMR
    QPMR_OFFSET                 = HOMER_QPMR_REGION_NUM * ONE_MB,
    SGPE_LVL_1_BOOT_LOAD_SIZE   = ONE_KB,
    SGPE_LVL_2_BOOT_LOAD_SIZE   = ONE_KB,
    SGPE_INT_VECT               = 384,
    SGPE_IMG_HEADER             = sizeof(sgpeHeader_t),
    SGPE_HCODE_SIZE             = 32 * ONE_KB, // FIXME RTC 155018 Revisit after Hcode optimization
    SGPE_EXE_SIZE               = (SGPE_HCODE_SIZE - ( SGPE_INT_VECT +
                                   SGPE_IMG_HEADER + PK_DBG_PTR_AREA_SIZE )),
    SGPE_COMMON_RING            = 13  * ONE_KB, // Common rings (10KB) + Override rings(3KB)
    CACHE_INST_SPECIFIC_SIZE    = 19  * ONE_KB,
    CACHE_SCOM_RESTORE_SIZE     = 6 * ONE_KB, //4488B rounded to 6KB
    SGPE_INSTRUMENTATION_SIZE   = 2 * ONE_KB,
    MAX_CACHE_CHIPLET           = 6,
    CACH0_CHIPLET_ID            = 0x10,

    SGPE_MAX_AREA_SIZE          = 64 * ONE_KB,

    // CPMR
    CPMR_OFFSET                 = HOMER_CMPR_REGION_NUM * ONE_MB,
    THREAD_LAUNCHER_SIZE        = 256,
    CORE_INT_AREA               = 8 * ONE_KB,
    SELF_REST_SIZE              = CORE_INT_AREA + THREAD_LAUNCHER_SIZE,
    CORE_RESTORE_SIZE           = 192 * ONE_KB,
    CORE_SCOM_START             = (256 * ONE_KB),
    CORE_SCOM_RES_SIZE          = 6 * ONE_KB,
    CME_INT_VECTOR_SIZE         = 384,
    CPMR_CME_HCODE_OFFSET       = (CORE_SCOM_START + CORE_SCOM_RES_SIZE),
    CME_HCODE_SIZE              = (25 * ONE_KB) + HALF_KB,
    CORE_COMMON_RING_SIZE       = 3  * ONE_KB, // common ring( 2KB) + common overrides (1KB)
    CORE_SPECIFIC_RING          = 2  * ONE_KB,
    SCOM_AREA_PER_CME           =  HALF_KB, // 256(ea ) * 2( CORES PER CME)
    QUAD_PSTATE_SIZE            = HALF_KB,
    INSTRUMENTATION_COUNTERS    = HALF_KB,
    CME_SRAM_HCODE_OFFSET       = 0x00,
    CORE_RESERVE_SIZE           =
        CORE_SCOM_START - ( CORE_RESTORE_SIZE + CME_HCODE_SIZE + CORE_COMMON_RING_SIZE + QUAD_PSTATE_SIZE  ),

    CME_REGION_START            =  (CORE_SCOM_START + CORE_SCOM_RES_SIZE),
    CME_INST_SPEC_RING_START    =  (300 * ONE_KB ) ,
    RESERVE_CME_RING_AREA       =  ( CME_INST_SPEC_RING_START  - ( CME_REGION_START +
                                     CME_HCODE_SIZE +
                                     CORE_COMMON_RING_SIZE +
                                     QUAD_PSTATE_SIZE)),
    CME_BLOCK_READ_LEN          =  32,
    CME_BLK_SIZE_SHIFT          =  0x05,
    CACHE_SCOM_START            =  128 * ONE_KB,

    // PPMR
    PGPE_LVL_1_BOOT_LOAD_SIZE   = ONE_KB,
    PGPE_LVL_2_BOOT_LOAD_SIZE   = ONE_KB,
    PGPE_INT_VECTOR             =  384,
    PGPE_HCODE_SIZE             =  32 * ONE_KB,
    PGPE_PARAM_BLOCK_SIZE       =  4 * ONE_KB,
    PSTATE_OUTPUT_TABLE         =  4 * ONE_KB,
    IGNORE_CHIPLET_INSTANCE     =  0xFF,
};

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
};

/**
 * @brief   models image section of SGPE in HOMER.
 */
typedef struct
{
    uint8_t qpmrHeader[sizeof(QpmrHeaderLayout_t)];
    uint8_t l1BootLoader[SGPE_LVL_1_BOOT_LOAD_SIZE];
    uint8_t l2BootLoader[SGPE_LVL_2_BOOT_LOAD_SIZE];
    uint8_t hcodeIntVect[SGPE_INT_VECT];
    uint8_t imgHeader[sizeof(sgpeHeader_t)];
    uint8_t debugPtrs[PK_DBG_PTR_AREA_SIZE];
    uint8_t hcode[SGPE_EXE_SIZE];
    uint8_t commonRings[SGPE_COMMON_RING];
    uint8_t cacheSpecificRing[CACHE_INST_SPECIFIC_SIZE];
} SgpeLayout_t;

typedef union CPMRSelfRestoreLayout
{
    uint8_t region[SELF_REST_SIZE];
    struct
    {
        cpmrHeader_t CPMRHeader;
        uint8_t      exe[SELF_REST_SIZE - sizeof(cpmrHeader_t)];
    } elements;
} CPMRSelfRestoreLayout_t;

/**
 * @brief   models image section associated with core self restore in HOMER.
 */
typedef struct
{
    CPMRSelfRestoreLayout_t CPMR_SR;
    uint8_t                 coreSelfRestore[CORE_RESTORE_SIZE];
    uint8_t                 reserve[CORE_SCOM_START - (SELF_REST_SIZE + CORE_RESTORE_SIZE)];
    uint8_t                 coreScom[CORE_SCOM_RES_SIZE];
} SelfRestoreLayout_t;

typedef union CmeHcodeLayout
{
    uint8_t hcode[CME_HCODE_SIZE];
    struct
    {
        uint8_t     cmeIntVector[CME_INT_VECTOR_SIZE];
        cmeHeader_t imgHeader;
        uint8_t     exe[CME_HCODE_SIZE - CME_INT_VECTOR_SIZE - sizeof(cmeHeader_t)];
    } elements;
} CmeHcodeLayout_t;


typedef struct
{
    SelfRestoreLayout_t  selfRestoreRegion;
    CmeHcodeLayout_t     cmeBin;
    uint8_t              commonRings[CORE_COMMON_RING_SIZE];
    uint8_t              quadPstateArea[QUAD_PSTATE_SIZE];
    uint8_t              resvRingArea[RESERVE_CME_RING_AREA];
    uint8_t              instSpecificRing[MAX_CORES_PER_CHIP * CORE_SPECIFIC_RING];
} CPMRLayout_t;

/**
 * @brief   models image section associated with PGPE in HOMER.
 */
typedef union PgpeHcodeLayout
{
    uint8_t hcode[PGPE_HCODE_SIZE];
    struct
    {
        uint8_t pgpeIntVector[PGPE_INT_VECTOR];
        PgpeHeader_t imgHeader;
        uint8_t exe[PGPE_HCODE_SIZE - PGPE_INT_VECTOR - sizeof(PgpeHeader_t)];
    } elements;
} PgpeHcodeLayout_t;

typedef struct
{
    uint8_t l1BootLoader[PGPE_LVL_1_BOOT_LOAD_SIZE];
    uint8_t l2BootLoader[PGPE_LVL_2_BOOT_LOAD_SIZE];
    PgpeHcodeLayout_t pgpeBin;
    uint8_t paramBlock[PGPE_PARAM_BLOCK_SIZE];
    uint8_t pstateOutputTable[PSTATE_OUTPUT_TABLE];
} PPMRLayout_t;

/**
 * @brief   models QPMR in HOMER.
 */
typedef struct
{
    SgpeLayout_t        sgpeRegion;
    uint8_t             qpmrReserve1[CACHE_SCOM_START - sizeof(SgpeLayout_t)];
    uint8_t             cacheScomRegion[CACHE_SCOM_RESTORE_SIZE];
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

#ifndef __PPE_PLAT
}// namespace p9_hcodeImageBuild ends
#endif //__PPE_PLAT

#endif //__ASSEMBLER__
#endif //__HW_IMG_DEFINE
