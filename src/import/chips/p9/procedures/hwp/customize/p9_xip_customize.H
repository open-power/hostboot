/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/customize/p9_xip_customize.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef _P9_XIP_CUSTOMIZE_
#define _P9_XIP_CUSTOMIZE_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_xip_customize_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*     i_image,
    uint32_t& io_imageSize,
    void*     i_ringSectionBuf,
    uint32_t& io_ringSectionBufSize,
    uint8_t   i_sysPhase,
    uint8_t   i_modeBuild,
    void*     i_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     i_ringBuf2,
    uint32_t  i_ringBufSize2,
    uint32_t& io_bootCoreMask);

extern "C"
{
/// @brief p9_xip_customize used to customize the SBE/CME/SGPE images with
///        mailbox attributes, VPD rings and other stuff.
///
/// @param[in] i_proc_target             => P9 proc chip target
/// @param[in] i_image                   => Pointer to an in-memory image
///                                         HB_SBE:
///                                             In:  SBE image
///                                             Out: Seeprom image
///                                         RT_{CME,SGPE}:
///                                             In:  HW image
///                                             Out: HW image
/// @param[in/out] io_imageSize          => Size of image
///                                         HB_SBE:
///                                             In:  MAX_SEEPROM_IMAGE_SIZE
///                                             Out: Final size
///                                         RT_{CME,SGPE}:
///                                             In:  Size of HW image
///                                             Out: Unchanged
/// @param[in] i_ringSectionBuf          => Pointer to an in-memory ring section
///                                         buffer
///                                         HB_SBE:
///                                             Used as temporary image work buffer
///                                             In:  Undefined
///                                             Out: Undefined
///                                         RT_{CME,SGPE}:
///                                             In:  Undefined
///                                             Out: Updated .rings section
/// @param[in/out] io_ringSectionBufSize => In: Size of ring section buffer
///                                         HB_SBE:
///                                             In:  MAX_SEEPROM_IMAGE_SIZE
///                                             Out: Unchanged
///                                         RT_{CME,SGPE}:
///                                             In:  MAX_RT_IMAGE_SIZE
///                                             Out: Final size
/// @param[in] i_sysPhase                => ={HB_SBE, RT_CME, RT_SGPE}
/// @param[in] i_modeBuild               => ={IPL, REBUILD}
/// @param[in] i_ringBuf1                => Caller supplied in-memory buffer
///                                         for uncompressed VPD rings in
/// @param[in] i_ringBufSize1            => Max size of VPD ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in] i_ringBuf2                => Caller supplied in-memory buffer
///                                         for uncompressed overlay rings
/// @param[in] i_ringBufSize2            => Max size of overlay ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in/out] io_bootCoreMask       => In: Mask of the desired boot cores
///                                         Out: Actual boot cores
///                                         (Only used in HB_SBE sysPhase)
///
/// @return FAPI_RC_SUCCESS if the customization was successful
///
    fapi2::ReturnCode p9_xip_customize (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
        void*     i_image,
        uint32_t& io_imageSize,
        void*     i_ringSectionBuf,
        uint32_t& io_ringSectionBufSize,
        uint8_t   i_sysPhase,
        uint8_t   i_modeBuild,
        void*     i_ringBuf1,
        uint32_t  i_ringBufSize1,
        void*     i_ringBuf2,
        uint32_t  i_ringBufSize2,
        uint32_t& io_bootCoreMask);

}
#endif
