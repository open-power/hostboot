/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/lib/p9_stop_util.H $                  */
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
#ifndef __P9_STOP_UTIL_
#define __P9_STOP_UTIL_

#ifdef __HOS_AIX__
    #define __BYTE_ORDER __BIG_ENDIAN
#else
    #include <endian.h>
#endif

#ifndef __PPE_PLAT
    #include "p9_stop_api.H"
#endif

#ifdef FAPI_2
    #include <fapi2.H>
#endif

///
/// @file   p9_stop_util.H
/// @brief  describes some utilty functions for STOP API.
///
// *HWP HW Owner    :  Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :  Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team        :  PM
// *HWP Level       :  2
// *HWP Consumed by :  HB:HYP
#ifndef __PPE_PLAT
namespace stopImageSection
{
#endif  //__PPE_PLAT
/**
 * @brief  helper function to swizzle given input data
 * @note   swizles bytes to handle endianess issue.
 */
#if( __BYTE_ORDER == __BIG_ENDIAN )

// NOP if it is a big endian system
#define SWIZZLE_2_BYTE(WORD) WORD
#define SWIZZLE_4_BYTE(WORD) WORD
#define SWIZZLE_8_BYTE(WORD) WORD

#else
#define SWIZZLE_2_BYTE(WORD) \
    ( (((WORD) >> 8) & 0x00FF) | (((WORD) << 8) & 0xFF00) )

#define SWIZZLE_4_BYTE(WORD) \
    ( (((WORD) >> 24) & 0x000000FF) | (((WORD) >>  8) & 0x0000FF00) | \
      (((WORD) <<  8) & 0x00FF0000) | (((WORD) << 24) & 0xFF000000) )

#define SWIZZLE_8_BYTE(WORD) \
    ( (((WORD) >> 56) & 0x00000000000000FF) |  \
      (((WORD) >> 40) & 0x000000000000FF00)| \
      (((WORD) >> 24) & 0x0000000000FF0000) |  \
      (((WORD) >>  8) & 0x00000000FF000000) |  \
      (((WORD) <<  8) & 0x000000FF00000000) |  \
      (((WORD) << 24) & 0x0000FF0000000000) | \
      (((WORD) << 40) & 0x00FF000000000000) |  \
      (((WORD) << 56) & 0xFF00000000000000) )
#endif

/**
 * @brief   describes details of CPMR header in HOMER.
 */
typedef struct
{
    uint64_t attnOpcodes;
    uint64_t homerMagicNumber;
    uint32_t buildDate;
    uint32_t version;
    uint8_t  reserve1[7];
    uint8_t  fuseModeStatus;
    uint32_t cmeImgOffset;
    uint32_t cmeImgLength;
    uint32_t cmeCommonRingOffset;
    uint32_t cmeCommonRingLength;
    uint32_t cmePstateOffset;
    uint32_t cmePstateLength;
    uint32_t coreSpecRingOffset;
    uint32_t coreSpecRingLen;
    uint32_t coreScomOffset;
    uint32_t coreScomLength;
    uint32_t reserve2[184];
} HomerImgDesc_t;

/**
 * @brief enumerates bit(s) positions of interest for PIR.
 */
enum
{
    FUSE_BIT0 = 0x08,
    FUSE_BIT1 = 0x04,
    FUSE_BIT2 = 0x02,
    FUSE_BIT3 = 0x01,
    QUAD_BITS = 0x70
};

#ifndef __PPE_PLAT
/**
 * @brief   returns core id and thread id by parsing a given PIR.
 * @param   i_pStopImage    points to STOP image associated with a proc chip.
 * @param   i_pir           PIR associated with a core's thread.
 * @param   o_coreId        core id obtained from PIR.
 * @param   o_threadId      thread id obtained from PIR.
 * @return  SUCCESS if function suceeds, error code otherwise.
 */
StopReturnCode_t getCoreAndThread( void* const i_pStopImage,
                                   const uint64_t i_pir,
                                   uint32_t& o_coreId, uint32_t& o_threadId );

} // namespace stopImageSection ends

#endif //__PPE_PLAT
#endif


