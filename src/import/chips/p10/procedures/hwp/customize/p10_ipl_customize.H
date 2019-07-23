/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_ipl_customize.H $ */
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
#ifndef _P10_IPL_CUSTOMIZE_H_
#define _P10_IPL_CUSTOMIZE_H_

#ifndef WIN32
#include <fapi2.H>

#define NUM_OF_CORES     (uint8_t)32
#define NUM_OF_QMES      (uint8_t)8
#define CORES_PER_QME    (NUM_OF_CORES/NUM_OF_QMES)
#define MVPD_DD_KWD_VER1 (uint8_t)0x01

enum SYSPHASE
{
    SYSPHASE_HB_SBE = 0,
    SYSPHASE_RT_QME = 1,
    NOOF_SYSPHASES  = 2,
};

enum MvpdRingStatus
{
    RING_NOT_FOUND,
    RING_FOUND,
    RING_REDUNDANT,
    RING_SCAN
};

enum ChipletIdentifier
{
    EQ_CHIPLET,
    EC_CHIPLET,
};

const uint32_t EC_POSITION = 0x80000000;

typedef struct
{
    //Read as:000X 000X 000X 000X 000X 000X 000X 000X (binary;X=[0,1]) EQ:[0:07]
    uint32_t EQ;

    //Read as:XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX (binary;X=[0,1]) EC:[0:31]
    uint32_t EC;

    // Following members used to capture current state of instance vpd ring to
    // be appended when image run out-of-space.
    // Refers to chiplet as in EQ/EC
    uint8_t  chipletUnderProcess;

    // Refer to EQ:[0:7]; EC:[0:31]
    uint8_t  chipletNumUnderProcess;
} VpdInsInsertProg_t;

const uint8_t MAX_FILTER_PLL_BUCKETS = 4;


typedef fapi2::ReturnCode (*p10_ipl_customize_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*     i_hwImage,
    void*     io_image,
    uint32_t& io_imageSize,
    void*     io_ringSectionBuf,
    uint32_t& io_ringSectionBufSize,
    uint8_t   i_sysPhase,
    void*     i_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     i_ringBuf2,
    uint32_t  i_ringBufSize2,
    void*     i_ringBuf3,
    uint32_t  i_ringBufSize3,
    uint32_t& io_bootCoreMask);

extern "C"
{
/// @brief p10_ipl_customize used to customize the SBE/CME/SGPE images with
///        mailbox attributes, VPD rings and other stuff.
///
/// @param[in] i_proc_target             => Processor chip target
/// @param[in] i_hwImage                 => HW image
/// @param[in/out] io_image              => Pointer to SBE image
///                                         HB_SBE:
///                                             In:  SBE [ringless] DD specific image
///                                             Out: Customized SBE image
///                                         RT_QME:
///                                             In:  Undefined
///                                             Out: Undefined
/// @param[in/out] io_imageSize          => Size of SBE image
///                                         HB_SBE:
///                                             In:  >=MAX_SBE_SEEPROM_SIZE
///                                             Out: Final size
///                                         RT_QME:
///                                             In:  Undefined
///                                             Out: Undefined
/// @param[in/out] io_ringSectionBuf     => Pointer to an in-memory ring section
///                                         buffer
///                                         HB_SBE:
///                                             Used as temporary image work buffer
///                                             In:  Caller supplied buffer
///                                             Out: Undefined
///                                         RT_QME:
///                                             In:  Caller supplied buffer
///                                             Out: Customized QME .rings section
/// @param[in/out] io_ringSectionBufSize => In: Size of ring section buffer
///                                         HB_SBE:
///                                             In:  >=MAX_SBE_SEEPROM_SIZE
///                                             Out: Final size
///                                         RT_QME:
///                                             In:  >=MAX_SBE_SEEPROM_SIZE
///                                             Out: Final size
/// @param[in] i_sysPhase                => ={HB_SBE, RT_QME}
/// @param[in] i_ringBuf1                => Caller supplied in-memory buffer
///                                         for VPD rings
/// @param[in] i_ringBufSize1            => Max size of ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in] i_ringBuf2                => Caller supplied in-memory buffer
///                                         for dynamic and overlays rings
/// @param[in] i_ringBufSize2            => Max size of ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in] i_ringBuf3                => Caller supplied in-memory buffer
///                                         to hold scratchpad rings
/// @param[in] i_ringBufSize3            => Max size of ring buffer
///                                         (Should equal MAX_RING_BUF_SIZE)
/// @param[in/out] io_bootCoreMask       => In: Mask of the desired boot cores
///                                         Out: Actual boot cores filled
///                                         (Only used in HB_SBE sysPhase)
///                                         (Bits(0:31) = EC00:EC31)
///
/// @return FAPI_RC_SUCCESS if the customization was successful
///
    fapi2::ReturnCode p10_ipl_customize (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
        void*     i_hwImage,
        void*     io_image,
        uint32_t& io_imageSize,
        void*     io_ringSectionBuf,
        uint32_t& io_ringSectionBufSize,
        uint8_t   i_sysPhase,
        void*     i_ringBuf1,
        uint32_t  i_ringBufSize1,
        void*     i_ringBuf2,
        uint32_t  i_ringBufSize2,
        void*     i_ringBuf3,
        uint32_t  i_ringBufSize3,
        uint32_t& io_bootCoreMask);
}
#else
extern "C" {
    int p10_ipl_customize (
        int& i_proc_target,
        void*     i_hwImage,
        void*     io_image,
        uint32_t& io_imageSize,
        void*     io_ringSectionBuf,
        uint32_t& io_ringSectionBufSize,
        uint8_t   i_sysPhase,
        void*     i_ringBuf1,
        uint32_t  i_ringBufSize1,
        void*     i_ringBuf2,
        uint32_t  i_ringBufSize2,
        void*     i_ringBuf3,
        uint32_t  i_ringBufSize3,
        uint32_t& io_bootCoreMask);
}
#endif

#endif // _P10_IPL_CUSTOMIZE_H_
