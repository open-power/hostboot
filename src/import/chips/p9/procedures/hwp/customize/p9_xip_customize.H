/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/customize/p9_xip_customize.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
    void*     i_image,
    uint32_t& io_imageSize,
    uint8_t   i_sysPhase,
    void*     i_vpdUncompressedRings,
    uint32_t  i_vpdRingsSize,
    void*     i_overlaysUncompressedRings,
    uint32_t  i_overlayRingsSize);

extern "C"
{
/// @brief p9_xip_customize used to customize the SBE/SEEPROM image with
///        mailbox attributes and vpd rings
/// @param[in] i_proc_target            => P9 proc chip target
/// @param[in] i_image                  => Pointer to the in-memory SBE/SEEPROM image
/// @param[in/out] io_imageSize         => Size of the sbe/seeprom image
/// @param[in] i_sysPhase               => 0: SBE_IPL, 1: HB IPL
/// @param[in] i_vpdUncompressedRings   => Pointer to in-memory buffer that can
///                                        be used to keep uncompressed rings in
/// @param[in] i_vpdRingsSize           => Size of the vpd rings buffer
/// @param[in] i_overlaysUncompressedRings => Pointer to in-memory buffer for
///                                           uncompressed overlay rings
/// @param[in] i_overlayRingsSize       => Size of the overlay ring buffer
//
/// @note: the content of the image pointers will be changed upon return
///
/// @return FAPI_RC_SUCCESS if the customization was successful
///
    fapi2::ReturnCode p9_xip_customize (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
        void*     i_image,
        uint32_t& io_imageSize,
        uint8_t   i_sysPhase,
        void*     i_vpdUncompressedRings,
        uint32_t  i_vpdRingsSize,
        void*     i_overlaysUncompressedRings,
        uint32_t  i_overlayRingsSize);

}
#endif
