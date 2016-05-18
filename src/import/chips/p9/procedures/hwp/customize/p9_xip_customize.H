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
