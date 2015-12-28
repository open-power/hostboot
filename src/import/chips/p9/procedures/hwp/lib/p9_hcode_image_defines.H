/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/lib/p9_hcode_image_defines.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __HW_IMG_DEFINE
#define __HW_IMG_DEFINE

///
/// @file   p9_hcode_image_defines.H
/// @brief  defines constants associated with hcode image build.
///
// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    Hostboot: Phyp
//--------------------------------------------------------------------------
// local structs and constants
// -------------------------------------------------------------------------
#ifndef __ASSEMBLER__

#ifndef __PPE_PLAT
namespace p9_hcodeImageBuild
{
#endif //__PPE_PLAT

/**
 * @brief   summarizes constants associated with hcode image build.
 */
enum
{
    ONE_KB                      = 1024,
    ONE_MB                      = 1024 * 1024,
    HARDWARE_IMG_SIZE           = ONE_MB,
    OCC_HOST_AREA_SIZE          = ONE_MB,
    MAX_CORES_PER_CHIP          = 24,
    PAD_OPCODE                  = 0x00000200,   //ATTN Opcode
    PPE_RESERVE_AREA            = 0x200,
    QPMR_HEADER_SIZE            = 0x00000200,
    SGPE_LVL_1_BOOT_LOAD_SIZE   = ONE_KB,
    SGPE_LVL_2_BOOT_LOAD_SIZE   = ONE_KB,
    SGPE_INT_VECT               = 384,
    SGPE_IMG_HEADER             = 64,
    SGPE_DBG_PTR_AREA_SIZE      = 64,
    CME_HCODE_REL_OFFSET        = (SGPE_INT_VECT +
                                   SGPE_IMG_HEADER +
                                   SGPE_DBG_PTR_AREA_SIZE),
    SGPE_HCODE_SIZE             = 30 * ONE_KB,
    SGPE_COMMON_RING            = 2  * ONE_KB,
    CACHE_SCOM_RESTORE_SIZE     = 6  * ONE_KB,
    CACHE_INST_SPECIFIC_SIZE    = 4  * ONE_KB,
    MAX_CACHE_CHIPLET           = 6,
    SGPE_MAX_AREA_SIZE          = 64 * ONE_KB,
    CPMR_HEADER_SIZE            = 256,
    THREAD_LAUNCHER_SIZE        = 256,
    CORE_INT_AREA               = 8 * ONE_KB,
    SELF_REST_SIZE              = CORE_INT_AREA + THREAD_LAUNCHER_SIZE,
    CORE_RESTORE_SIZE           = 192 * ONE_KB,
    CORE_SCOM_RES_SIZE          = 6 * ONE_KB,
    CME_INT_VECTOR              = 384,
    CME_IMG_HEADER              = 64,
    CME_DBG_PTR_AREA_SIZE       = 64,
    CME_HCODE_SIZE              = 20 * ONE_KB,
    CORE_COMMON_RING_SIZE       = 6  * ONE_KB,
    QUAD_PSTATE_SIZE            = 2  * ONE_KB,
    CORE_SPECIFIC_RING          = 2  * ONE_KB,
    CORE_SCOM_START             = 256 * ONE_KB,
    CORE_RESERVE_SIZE           =
        CORE_SCOM_START - ( CORE_RESTORE_SIZE + CORE_INT_AREA +
                            CME_HCODE_SIZE + CORE_COMMON_RING_SIZE +
                            QUAD_PSTATE_SIZE + CME_IMG_HEADER ),

    CME_REGION_START            =  CORE_SCOM_START + CORE_SCOM_RES_SIZE,
    CME_INST_SPEC_RING_START    =  (300 * ONE_KB ) ,    // offset from CPMR
    RESERVE_CME_RING_AREA       =  ( CME_INST_SPEC_RING_START  - ( CME_REGION_START +
                                     PPE_RESERVE_AREA +
                                     CME_HCODE_SIZE +
                                     CORE_COMMON_RING_SIZE +
                                     QUAD_PSTATE_SIZE)),

    PGPE_LVL_1_BOOT_LOAD_SIZE   =  ONE_KB,
    PGPE_LVL_2_BOOT_LOAD_SIZE   =  ONE_KB,
    PGPE_IMG_HEADER             =  64,   // need to get confirmation on this
    PGPE_HCODE_INT_VECT         =  384,
    PGPE_HCODE_SIZE             =  16 * ONE_KB,
    PGPE_PARAM_BLOCK_SIZE       =  8 * ONE_KB,
    PSTATE_OUTPUT_TABLE         =  8 * ONE_KB,
    FUSE_STATE                  =  0xAA,
    UNFUSE_STATE                =  0xBB,
    CME_BLOCK_READ_LEN          =  32,
    CACHE_SCOM_START            =  128 * ONE_KB,
    CPMR_MAGIC_WORD             =  0x484F4D4552312E30ll,
    CME_BLK_SIZE_SHIFT          =  0x05,
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
    BUILD_FAIL_P9_CPMR_HDR      =   13,
    BUILD_FAIL_P9_SRESET_HNDLR  =   14,
    BUILD_FAIL_P9_THRD_LAUNCHER =   15,
    BUILD_FAIL_P9_SPR_RESTORE   =   16,
    BUILD_FAIL_P9_SCOM_RESTORE  =   17,
    BUILD_FAIL_CME_IMG_HDR      =   18,
    BUILD_FAIL_CME_HCODE        =   19,
    BUILD_FAIL_CME_CMN_RINGS    =   20,
    BUILD_FAIL_CME_QUAD_PSTATE  =   21,
    BUILD_FAIL_CME_SPEC_RINGS   =   22,
    BUILD_FAIL_CME_INT_VECT     =   23,
};

/**
 * @brief   models image section of SGPE in HOMER.
 */
typedef struct
{
    uint8_t qpmrHeader[QPMR_HEADER_SIZE];
    uint8_t l1BootLoader[SGPE_LVL_1_BOOT_LOAD_SIZE];
    uint8_t l2BootLoader[SGPE_LVL_2_BOOT_LOAD_SIZE];
    uint8_t hcodeIntVect[SGPE_INT_VECT];
    uint8_t imgHeader[SGPE_IMG_HEADER];
    uint8_t debugPtrArea[SGPE_DBG_PTR_AREA_SIZE];
    uint8_t hcode[SGPE_HCODE_SIZE];
    uint8_t commonRings[SGPE_COMMON_RING];
    uint8_t cacheSpecificRing[MAX_CACHE_CHIPLET][CACHE_INST_SPECIFIC_SIZE];
} SgpeLayout_t;

/**
 * @brief   models image section associated with core self restore in HOMER.
 */
typedef struct
{
    uint8_t  selfRestoreArea[SELF_REST_SIZE];
    uint8_t  coreSelfRestore[CORE_RESTORE_SIZE];
    uint8_t  reserve[CORE_SCOM_START - (SELF_REST_SIZE + CORE_RESTORE_SIZE)];
    uint8_t  coreScom[CORE_SCOM_RES_SIZE];
} SelfRestoreLayout_t;

typedef struct
{
    uint8_t  cmeIntVector[CME_INT_VECTOR];
    uint8_t  imgHeader[CME_IMG_HEADER];
    uint8_t  debugPtrArea[CME_DBG_PTR_AREA_SIZE];
    uint8_t  hcode[CME_HCODE_SIZE];
    uint8_t  commonRings[CORE_COMMON_RING_SIZE];
    uint8_t  quadPstateArea[QUAD_PSTATE_SIZE];
    uint8_t  resvRingArea[RESERVE_CME_RING_AREA];
    uint8_t  instSpecificRing[MAX_CORES_PER_CHIP][CORE_SPECIFIC_RING]; // 300KB offset from CPMR
} CmeRegionLayout_t;

/**
 * @brief   models image section associated with core self restore in HOMER.
 */
typedef struct
{
    uint8_t l1BootLoader[PGPE_LVL_1_BOOT_LOAD_SIZE];
    uint8_t l2BootLoader[PGPE_LVL_2_BOOT_LOAD_SIZE];
    uint8_t pgpeIntVector[PGPE_HCODE_INT_VECT];
    uint8_t imgHeader[PGPE_IMG_HEADER];
    uint8_t hcode[PGPE_HCODE_SIZE];
    uint8_t paramBlock[PGPE_PARAM_BLOCK_SIZE];
    uint8_t pstateOutputTable[PSTATE_OUTPUT_TABLE];
} PgpeLayout_t;

/**
 * @brief   models CME image header in HOMER.
 */
typedef struct
{
    uint64_t magicNumber;
    uint32_t buildDate;
    uint32_t buildVer;
    uint32_t hcodeOffset;
    uint32_t hcodeLength;
    uint32_t commonRingOffset;
    uint32_t commonRingLength;
    uint32_t pStateOffset;
    uint32_t pStateLength;
    uint32_t coreSpecificRingOffset;;
    uint32_t coreSpecificRingLength;
    uint32_t cmeMode;
    uint8_t  reserve[12];
} CmeImageHeader_t;

/**
 * @brief   models SGPE image header in HOMER.
 */
struct SgpeImageHeader_t
{
    uint64_t magicNumber;
    uint32_t sysResetAddr;
    uint32_t reserve1;
    uint32_t ivprAddress;
    uint32_t reserve2;
    uint32_t buildDate;
    uint32_t buildVer;
    uint64_t reserveFlag;
    uint32_t quadCmnRingOccOffset;
    uint32_t quadSpecRingOccOffset;
    uint32_t quadCommonScomOccOffset;
    uint8_t  reserve3[12];
};


/**
 * @brief   models layout of HOMER.
 */
struct Homerlayout_t
{
    uint8_t occHostArea[OCC_HOST_AREA_SIZE];
    SgpeLayout_t sgpeRegion;
    uint8_t sgpeReserve1[CACHE_SCOM_START - sizeof(SgpeLayout_t)];
    uint8_t cacheScomRegion[CACHE_SCOM_RESTORE_SIZE];
    uint8_t sgpeReserve2[ONE_MB - (CACHE_SCOM_START + CACHE_SCOM_RESTORE_SIZE )];
    SelfRestoreLayout_t selfRestoreRegion;
    CmeRegionLayout_t cmeRegion;
    uint8_t cmeReserve[ONE_MB - (sizeof( CmeRegionLayout_t ) + sizeof( SelfRestoreLayout_t ))];
    PgpeLayout_t pgpeRegion;
    uint8_t pgpeReserve[ONE_MB - sizeof( PgpeLayout_t )];
};

#ifndef __PPE_PLAT
}// namespace p9_hcodeImageBuild ends
#endif //__PPE_PLAT

#endif //__ASSEMBLER__

/**
 * @brief models QPMR header in HOMER
 */

#ifdef __ASSEMBLER__
#define DEF_MEM_QPMR_UINT64( member )\
    member: \
    .quad 0
#else
#define DEF_MEM_QPMR_UINT64( member ) uint64_t member;
#endif

#ifdef __ASSEMBLER__
#define DEF_MEM_QPMR_UINT32( member )\
    member: \
    .long 0
#else
#define DEF_MEM_QPMR_UINT32( member ) uint32_t member;
#endif


#ifdef __ASSEMBLER__
.section ".qpmr" , "aw"
.balign 8
#else

#ifndef __PPE_PLAT
namespace p9_hcodeImageBuild
{
#endif //__PPE_PLAT

struct QpmrHeaderLayout_t
{
#endif
DEF_MEM_QPMR_UINT64( magicNumber )
DEF_MEM_QPMR_UINT32( bootCopierOffset )  // level 1 boot loader
DEF_MEM_QPMR_UINT32( reserve1 )
DEF_MEM_QPMR_UINT32( bootLoaderOffset ) // level 2 boot loader
DEF_MEM_QPMR_UINT32( bootLoaderLength )
DEF_MEM_QPMR_UINT32( buildDate )
DEF_MEM_QPMR_UINT32( buildVersion )
DEF_MEM_QPMR_UINT64( reservedFlags )
DEF_MEM_QPMR_UINT32( sgpeImgOffset )
DEF_MEM_QPMR_UINT32( sgpeImgLength )
DEF_MEM_QPMR_UINT32( quadCmnRingOffset )
DEF_MEM_QPMR_UINT32( quadCmnRingLength )
DEF_MEM_QPMR_UINT32( quadSpecRingOffset )
DEF_MEM_QPMR_UINT32( quadSpecRingLength )
DEF_MEM_QPMR_UINT32( quadSpecScomOffset )
DEF_MEM_QPMR_UINT32( quadSpecScomLength )
DEF_MEM_QPMR_UINT32( quadCmnRingOccOffset )
DEF_MEM_QPMR_UINT32( quadSpecRingOccOffset )
DEF_MEM_QPMR_UINT32( quadCmnScomOccOffset )
#ifndef __ASSEMBLER__
};

#ifndef __PPE_PLAT
} // p9_hcodeImageBuild ends
#endif //__PPE_PLAT

#endif


#endif
