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
// Constants used in both C++ and Assembler/Linker code
CONST_UINT32_T(CPMR_HEADER_SIZE, 256);
CONST_UINT32_T(QPMR_HEADER_SIZE, 512);
CONST_UINT32_T(PPMR_HEADER_SIZE, 512);
CONST_UINT32_T(PGPE_IVPR_ADDR,   0xfff20000);

//#pragma message (STR(CPMR_HEADER_SIZE))

// Define the Magic Numbers for the various images
HCD_MAGIC_NUMBER(CPMR_MAGIC_NUMBER, ULL(0x43504d525f312e30));  // CPMR_1.0
HCD_MAGIC_NUMBER(CME_MAGIC_NUMBER , ULL(0x434d455f5f312e30));  // CME__1.0
HCD_MAGIC_NUMBER(QPMR_MAGIC_NUMBER, ULL(0x51504d525f312e30));  // QPMR_1.0
HCD_MAGIC_NUMBER(SGPE_MAGIC_NUMBER, ULL(0x534750455f312e30 )); // SGPE_1.0
HCD_MAGIC_NUMBER(PPMR_MAGIC_NUMBER, ULL(0x50504d525f312e30));  // PPMR_1.0
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
HCD_HDR_UINT32( quadCommonOvrdOffset, 0 );
HCD_HDR_UINT32( quadCommonOvrdLength, 0 );
HCD_HDR_UINT32( quadSpecRingOffset, 0);
HCD_HDR_UINT32( quadSpecRingLength, 0);
HCD_HDR_UINT32( quadScomOffset, 0);
HCD_HDR_UINT32( quadScomLength, 0);
HCD_HDR_UINT32( quad24x7Offset, 0);
HCD_HDR_UINT32( quad24x7Length, 0);
HCD_HDR_UINT32( stopFfdcOffset, 0);
HCD_HDR_UINT32( stopFfdcLength, 0);
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
HCD_HDR_UINT32(g_sgpe_reserve2, 0);
HCD_HDR_UINT32(g_sgpe_build_date, 0);
HCD_HDR_UINT32(g_sgpe_build_ver, 0);
HCD_HDR_UINT32(g_sgpe_reserve_flags, 0);
HCD_HDR_UINT16(g_sgpe_location_id, 0);
HCD_HDR_UINT16(g_sgpe_reserve3, 0);
HCD_HDR_UINT32(g_sgpe_cmn_ring_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_cmn_ring_ovrd_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_spec_ring_occ_offset, 0);
HCD_HDR_UINT32(g_sgpe_scom_offset, 0);
HCD_HDR_UINT32(g_sgpe_scom_mem_offset, 0);
HCD_HDR_UINT32(g_sgpe_scom_mem_length, 0);
HCD_HDR_UINT32(g_sgpe_24x7_offset, 0);
HCD_HDR_UINT32(g_sgpe_24x7_length, 0);
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
HCD_HDR_UINT32(g_cme_reserved2, 0); //Retain next field at 8B boundary
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
HCD_HDR_UINT32(g_pgpe_sys_reset_addr,           0 );        // Fully qualified OCC address where pk_init resides
HCD_HDR_UINT32(g_pgpe_shared_sram_addr,         0 );        // SRAM address where shared SRAM begins
HCD_HDR_UINT32(g_pgpe_ivpr_addr,   PGPE_IVPR_ADDR );        // Beginning of PGPE region in OCC SRAM
HCD_HDR_UINT32(g_pgpe_shared_sram_len,          0 );        // Length of shared SRAM area
HCD_HDR_UINT32(g_pgpe_build_date,               0 );        // Build date for PGPE Image
HCD_HDR_UINT32(g_pgpe_build_ver,                0 );        // Build Version
HCD_HDR_UINT16(g_pgpe_flags,                    0 );        // PGPE Flags
HCD_HDR_UINT16(g_pgpe_reserve1,                 0 );        // Reserve field
HCD_HDR_UINT32(g_pgpe_reserve2,                 0 );        // Reserve field
HCD_HDR_UINT32(g_pgpe_gppb_sram_addr,           0 );        // Offset to Global P State Parameter Block
HCD_HDR_UINT32(g_pgpe_hcode_length,             0 );        // Length of PGPE Hcode
HCD_HDR_UINT32(g_pgpe_gppb_mem_offset,
               0 );        // Offset to start of Global PS Param Block wrt start of HOMER.
HCD_HDR_UINT32(g_pgpe_gppb_length,              0 );        // Length of Global P State Parameter Block
HCD_HDR_UINT32(g_pgpe_gen_pstables_mem_offset,  0 );        // Offset to PState Table wrt start of HOMER
HCD_HDR_UINT32(g_pgpe_gen_pstables_length,      0 );        // Length of P State table
HCD_HDR_UINT32(g_pgpe_occ_pstables_sram_addr,   0 );        // Offset to start of OCC P-State table
HCD_HDR_UINT32(g_pgpe_occ_pstables_len,         0 );        // Length of OCC P-State table
HCD_HDR_UINT32(g_pgpe_beacon_addr,              0 );        // SRAM addr where PGPE beacon is located
HCD_HDR_UINT32(g_quad_status_addr,              0 );
HCD_HDR_UINT32(g_wof_table_addr,                0 );
HCD_HDR_UINT32(g_wof_table_length,              0 );
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
    HALF_KB                     = 512,
    ONE_KB                      = 1024,
    ONE_MB                      = 1024 * 1024,
    HARDWARE_IMG_SIZE           = ONE_MB,
    OCC_HOST_AREA_SIZE          = ONE_MB,
    HOMER_OCC_REGION_NUM        = 0,
    HOMER_QPMR_REGION_NUM       = 1,
    HOMER_CMPR_REGION_NUM       = 2,
    HOMER_PPMR_REGION_NUM       = 3,
    MAX_CORES_PER_CHIP          = 24,
    THREADS_PER_CORE            = 4,
    MAX_CME_PER_CHIP            = 12,
    MAX_CACHE_CHIPLETS          = 6,
    CACH0_CHIPLET_ID            = 0x10,
    MAX_CORES_PER_EX            = 2,
    CORE0_CHIPLET_ID            = 0x20,
    PAD_OPCODE                  = 0x00000200,   //ATTN Opcode
    BLR_INST                    = 0x4e800020,   //blr instruction
    THREAD_RESTORE_AREA_SIZE    = 2048,
    PPE_RESERVE_AREA            = 0x200,
    FUSED_MODE                  = 0xBB,
    NONFUSED_MODE               = 0xAA,
    PK_DBG_PTR_AREA_SIZE        = 64,
    SCOM_ENTRY_SIZE             = 16,           // 4B pad, 4B address, 8B data
    SCOM_RESTORE_PER_CHIPLET    = 64, // size in words (16B * 16)/4

    //---- QPMR  ----
    QPMR_OFFSET                 = HOMER_QPMR_REGION_NUM * ONE_MB,

    //** Boot Loaders
    SGPE_LVL_1_BOOT_LOAD_SIZE   = ONE_KB,
    SGPE_LVL_2_BOOT_LOAD_SIZE   = ONE_KB,

    //** Hcode
    SGPE_INT_VECT               = 384,
    SGPE_IMG_HEADER             = sizeof(sgpeHeader_t),
    SGPE_DBG_PTR_AREA_SIZE      = 64,
    SGPE_HCODE_SIZE             = (45 * ONE_KB) + HALF_KB,  // @todo RTC 158543 Reallocate space

    SGPE_IMAGE_SIZE             = 80 * ONE_KB,

    SGPE_ALLOCATED_SIZE         = SGPE_HCODE_SIZE,   // @todo RTC 158543 Reallocate space (collapse??)

    //** Scan
    SGPE_COMMON_RING_SIZE       = 13 * ONE_KB,  // 400B * 9 rings * 3 types (base, RL, CC)
    SGPE_OVERRIDE_RING_SIZE     = 3 * ONE_KB,   // 300B * 9 rings

    CACHE_INST_SPECIFIC_SIZE    = (3 * ONE_KB) + HALF_KB, // per cache, 1KB/ring x 5 rings/cache
    SGPE_INSTRUMENTATION_SIZE   = 2 * ONE_KB,
    MAX_CACHE_CHIPLET           = 6,
    MAX_QUAD_SPEC_RING_SIZE     = 19  * ONE_KB,

    //** SCOM
    NUM_CACHE_SCOM_REGS         = 47 + 1,       // 16 L2 repr, 16 L3 repr, 15 non-repr, 1 NULL
    CACHE_SCOM_RESTORE_SIZE     = 6 * ONE_KB, //4488B rounded to 6KB

    CACHE_SCOM_START            = 128 * ONE_KB, // HOMER offset from QPMR

    //** OCC SRAM Allocation
    SGPE_MAX_AREA_SIZE          = 80 * ONE_KB,  // Allocation within the OCC SRAM
    SGPE_RESERVE_SIZE           = SGPE_MAX_AREA_SIZE -
                                  ( SGPE_HCODE_SIZE +
                                    SGPE_COMMON_RING_SIZE +
                                    CACHE_SCOM_RESTORE_SIZE +
                                    SGPE_OVERRIDE_RING_SIZE +
                                    CACHE_SCOM_RESTORE_SIZE),

    //---- CPMR ----
    CPMR_OFFSET                 = HOMER_CMPR_REGION_NUM * ONE_MB,

    //** Self Restore
    THREAD_LAUNCHER_SIZE        = 256,
    CORE_INT_AREA               = 8 * ONE_KB,
    SELF_REST_SIZE              = CORE_INT_AREA + THREAD_LAUNCHER_SIZE,
    CORE_RESTORE_SIZE           = ((2 * ONE_KB) * THREADS_PER_CORE) * MAX_CORES_PER_CHIP,

    //** SCOM
    CORE_SCOM_START             = (256 * ONE_KB),
    CORE_SCOM_RESTORE_SIZE      = SCOM_ENTRY_SIZE * 16, // (15 registers + 1 NULL) per core
    CME_SCOM_AREA               = CORE_SCOM_RESTORE_SIZE * 2, // 2 cores
    SCOM_AREA_PER_CME           =  HALF_KB, // 256(ea ) * 2( CORES PER CME) (???)

    //** Hcode
    CORE_SCOM_PER_CME           = 512,
    CORE_SCOM_RES_SIZE          = MAX_CME_PER_CHIP * SCOM_AREA_PER_CME,
    CME_INT_VECTOR_SIZE         = 384,
    CME_IMG_HEADER_SIZE         = 64,
    CPMR_CME_HCODE_OFFSET       = (CORE_SCOM_START + CORE_SCOM_RES_SIZE),
    CME_REGION_SIZE             =  (64 * ONE_KB), // CME hcode and data's footprint in HOMER
    CME_SRAM_SIZE               =  (32 * ONE_KB ),

    //** Scan
    CORE_COMMON_RING_SIZE       = 2  * ONE_KB, // common ring( 2KB) + common overrides (1KB)
    MAX_SIZE_CME_INST_RING      = 1 * ONE_KB,
    CORE_OVERRIDE_RING          = 1 * ONE_KB,   // common for all cores
    QUAD_PSTATE_SIZE            = HALF_KB,      // common for all cores
    CME_INSTRUMENTATION_SIZE    = HALF_KB,      // per CME
    INSTRUMENTATION_COUNTERS    = HALF_KB,      // (???)
    CME_SRAM_HCODE_OFFSET       = 0x00, //(???)
    CME_REGION_START            =  (CORE_SCOM_START + CORE_SCOM_RES_SIZE),
    CME_BLOCK_READ_LEN          = 32,
    CME_BLK_SIZE_SHIFT          = 0x05,

    //CME Image Flags
    CME_STOP_3_TO_2_BIT_POS         =   0x80000000,
    CME_STOP_4_TO_2_BIT_POS         =   0x40000000,
    CME_STOP_5_TO_4_BIT_POS         =   0x20000000,
    CME_STOP_8_TO_5_BIT_POS         =   0x10000000,
    CME_STOP_11_TO_8_BIT_POS        =   0x08000000,
    CME_SKIP_CORE_POWEROFF_BIT_POS  =   0x00000001,

    //SGPE Image Flags
    SGPE_STOP_4_TO_2_BIT_POS        =   0x80000000,
    SGPE_STOP_5_TO_4_BIT_POS        =   0x40000000,
    SGPE_STOP_8_TO_5_BIT_POS        =   0x20000000,
    SGPE_STOP_11_TO_8_BIT_POS       =   0x10000000,
    SGPE_PROC_FAB_ADDR_BAR_MODE_POS =   0x00008000,

    // PPMR
    //** Boot Loaders
    PPMR_OFFSET                 =  HOMER_PPMR_REGION_NUM * ONE_MB,
    PPMR_HEADER_LEN             =  512,
    PGPE_LVL_1_BOOT_LOAD_SIZE   =  ONE_KB,
    PGPE_LVL_2_BOOT_LOAD_SIZE   =  ONE_KB,
    PGPE_MAX_AREA_SIZE          =  48 * ONE_KB, // @todo RTC 158543 Reallocate space

    PGPE_HOMER_SRAM_ALLOC       =  128 * ONE_KB,
    PGPE_HOMER_SRAM_RESERVE     =  PGPE_HOMER_SRAM_ALLOC -
                                   (PPMR_HEADER_LEN  +
                                    PGPE_LVL_1_BOOT_LOAD_SIZE +
                                    PGPE_LVL_2_BOOT_LOAD_SIZE +
                                    PGPE_MAX_AREA_SIZE),

    PGPE_INT_VECTOR             =  384,
    PGPE_HCODE_SIZE             =  32 * ONE_KB,
    PGPE_PARAM_BLOCK_SIZE       =  8 * ONE_KB,

    // @todo: get these from the p9_homer_map.h file
    HOMER_OOC_PARAM_BLOCK_ADDR      =  0x00320000,   // PPMR + 128KB
    HOMER_PSTATE_OUTPUT_TABLE_ADDR  =  0x00324000,   // PPMR + 144KB
    HOMER_WOF_TABLE_ADDR            =  0x003C0000,   // PPMR + 768KB (the last 256KB)

    OCC_PARAM_BLOCK_ALLOC       =  16 * ONE_KB,
    OCC_PARAM_BLOCK_SIZE        =  8 * ONE_KB,

    PSTATE_OUTPUT_TABLE_ALLOC   =  16 * ONE_KB,
    PSTATE_OUTPUT_TABLE_SIZE    =  8 * ONE_KB,

    WOF_TABLES_BLOCK_ALLOC       =  256 * ONE_KB,

    OCI_SRAM_ADDR_BASE          =  0xFFF20000,   // @todo: what is this for?
    OCI_PBA_ADDR_BASE           =  0x80300000,
    IGNORE_CHIPLET_INSTANCE     =  0xFF,

    //RING LAYOUT
    RING_ALIGN_BOUNDARY         =  0x08,

    //MISC
    DARN_BAR_EN_POS             = 0x8000000000000000ll,
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
    BUILD_SEC_SIZE_OVERFLOW     =   28,
    BUILD_FAIL_INVALID_SECTN    =   29,
    BUILD_FAIL_RING_EXTRACTN    =   30,
    CME_SRAM_IMG_SIZE_ERR       =   31,
    SGPE_SRAM_IMG_SIZE_ERR      =   32,
    PGPE_SRAM_IMG_SIZE_ERR      =   33,
    BUILD_FAIL_PGPE_PPMR        =   34,
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
    uint8_t  instanceRingPayLoad[ MAX_SIZE_CME_INST_RING - sizeof(CoreSpecRingList_t)];
} CoreSpecRingCme_t;

typedef union
{
    CoreSpecRingCme_t instRingIndex;
    uint8_t instScanRings[ MAX_SIZE_CME_INST_RING ];
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
    uint16_t    eqModeRing;
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
    uint16_t    eqAnaBndyRingl3dccBucket26;
    uint16_t    eqAnaModeRing;
    uint16_t    ex_l2_fure_1;
    uint16_t    ex_l3_fure_1;
} QuadCmnRingsList_t;

typedef struct
{
    QuadCmnRingsList_t   quadCmnRingList;
    uint8_t             cmnRingPayLoad[SGPE_COMMON_RING_SIZE - sizeof(QuadCmnRingsList_t)];
} QuadCmnRingsSgpe_t;

typedef union
{
    QuadCmnRingsSgpe_t cmnRingIndex;
    uint8_t cmnScanRings[SGPE_COMMON_RING_SIZE];
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
    QuadSpecRingsList_t quadSpecRings[MAX_CACHE_CHIPLET];
    uint8_t quadSpecRingPayLoad[ MAX_QUAD_SPEC_RING_SIZE - (MAX_CACHE_CHIPLET * sizeof(QuadSpecRingsList_t))];
} QuadSpecRing_t;

typedef union
{
    QuadSpecRing_t instRingIndex;
    uint8_t instScanRings[ MAX_QUAD_SPEC_RING_SIZE ];
} InstRingLayoutSgpe_t;

/**
 * @brief   models image section of SGPE in HOMER.
 */
typedef struct
{
    uint8_t qpmrHeader[sizeof(QpmrHeaderLayout_t)];
    uint8_t l1BootLoader[SGPE_LVL_1_BOOT_LOAD_SIZE];
    uint8_t l2BootLoader[SGPE_LVL_2_BOOT_LOAD_SIZE];
    uint8_t sgpeSramImage[SGPE_IMAGE_SIZE];
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
    uint8_t  ppmrHeader[PPMR_HEADER_LEN];
    uint8_t  l1BootLoader[PGPE_LVL_1_BOOT_LOAD_SIZE];
    uint8_t  l2BootLoader[PGPE_LVL_2_BOOT_LOAD_SIZE];
    uint8_t  pgpeSramImage[PGPE_MAX_AREA_SIZE];     // Includes the Global Pstate Parameter Block
    uint8_t  ppmr_reserved0[PGPE_HOMER_SRAM_RESERVE];
    uint8_t  occParmBlock[sizeof(OCCPstateParmBlock)];  // PPMR + 128KB
    uint8_t  occParmBlockReserve[OCC_PARAM_BLOCK_ALLOC - sizeof(OCCPstateParmBlock)];
    uint8_t  pstateTable[sizeof(GeneratedPstateInfo)];  // PPMR + 144KB
    uint8_t  pstateTableReserve[PSTATE_OUTPUT_TABLE_ALLOC - sizeof(GeneratedPstateInfo)];
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

#ifdef __cplusplus
#ifndef __PPE_PLAT
}// namespace p9_hcodeImageBuild ends
#endif //__PPE_PLAT
#endif //__cplusplus

#endif //__ASSEMBLER__
#endif //__HW_IMG_DEFINE
