/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/customize/p9_xip_customize.H $ */
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
#ifndef _P9_XIP_CUSTOMIZE_
#define _P9_XIP_CUSTOMIZE_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_xip_customize_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*     io_image,
    uint32_t& io_imageSize,
    void*     io_ringSectionBuf,
    uint32_t& io_ringSectionBufSize,
    uint8_t   i_sysPhase,
    uint8_t   i_modeBuild,
    void*     io_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     io_ringBuf2,
    uint32_t  i_ringBufSize2,
    uint32_t& io_bootCoreMask);

extern "C"
{
/// @brief p9_xip_customize used to customize the SBE/CME/SGPE images with
///        mailbox attributes, VPD rings and other stuff.
///
/// @param[in] i_proc_target             => P9 proc chip target
/// @param[in/out] io_image              => Pointer to an in-memory image
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
/// @param[in/out] io_ringSectionBuf     => Pointer to an in-memory ring section
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
/// @param[in/out] io_ringBuf1           => Caller supplied in-memory buffer
///                                         for uncompressed VPD rings in
/// @param[in] i_ringBufSize1            => Max size of VPD ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in/out] io_ringBuf2           => Caller supplied in-memory buffer
///                                         for uncompressed overlay rings
/// @param[in] i_ringBufSize2            => Max size of overlay ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in/out] io_bootCoreMask       => In: Mask of the desired boot cores
///                                         Out: Actual boot cores
///                                         (Only used in HB_SBE sysPhase)
///                                         (Bits(8:31) = EC00:EC23)
///
/// @return FAPI_RC_SUCCESS if the customization was successful
///
    fapi2::ReturnCode p9_xip_customize (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
        void*     io_image,
        uint32_t& io_imageSize,
        void*     io_ringSectionBuf,
        uint32_t& io_ringSectionBufSize,
        uint8_t   i_sysPhase,
        uint8_t   i_modeBuild,
        void*     io_ringBuf1,
        uint32_t  i_ringBufSize1,
        void*     io_ringBuf2,
        uint32_t  i_ringBufSize2,
        uint32_t& io_bootCoreMask);

}
#endif
