/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_hcode_image_build.H $           */
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
#ifndef __HCODE_IMG_BUILD_H_
#define __HCODE_IMG_BUILD_H_

#include <stdint.h>

///
/// @file   p9_hcode_image_build.H
/// @brief  describes HWP interface that builds the STOP image.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          1
/// *HWP Consumed by:    Hostboot, Phyp
//

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <fapi2.H>

typedef  const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > CONST_FAPI2_PROC;

/**
 * @brief   phases of system associated for hcode image build.
 */
enum SysPhase_t
{
    PHASE_NA        =   0,
    PHASE_IPL       =   1,
    PHASE_REBUILD   =   2
};

/**
 * @brief   constants used for hcode image build.
 */
enum
{
    HW_IMG_RING_SIZE   =  1024 * 1024,
};

/**
 * @brief image types to be handled by the hcode image build HWP.
 * @note  structure below summarizes all the components that needs to be
 *        included during STOP image build. Setting a field to 1 means that
 *        it needs to be part of STOP image in HOMER. It can be used to
 *        build partial STOP image in HOMER.
 */
struct ImageType_t
{
    uint32_t sresetHndlrBuild: 1; // for sreset handler inclusion
    uint32_t threadLauncherBuild: 1; //for thread launcher inclusion
    uint32_t cmeHcodeBuild: 1;           // for cme hcode inclusion
    uint32_t cmeCommonRingBuild: 1;      // for core ring inclusion
    uint32_t cmeCoreSpecificRingBuild: 1; // for core specific scan ring inclusion
    uint32_t sgpeHcodeBuild: 1;          // for sgpe inclusion
    uint32_t sgpeCommonRingBuild: 1;     // for sgpe common scan ring inclusion
    uint32_t sgpeCacheSpecificRingBuild: 1; // for cache specific ring inclusion
    uint32_t pgpeImageBuild: 1;      // pgpe platform inclusion in image build
    uint32_t pgpePstateParmBlockBuild: 1; //pgpe P-State Parameter Block Build
    uint32_t reserve: 22;

    ImageType_t( )
    {
        memset( this , 0, sizeof (*this) );
        this->sresetHndlrBuild |= 0x01;
        this->threadLauncherBuild |= 0x01;
        this->cmeHcodeBuild |= 0x01;
        this->cmeCommonRingBuild |= 0x01;
        this->cmeCoreSpecificRingBuild |= 0x01;
        this->sgpeHcodeBuild |= 0x01;
        this->sgpeCommonRingBuild |= 0x01;
        this->sgpeCacheSpecificRingBuild |= 0x01;
        this->pgpeImageBuild |= 0x01;
        this->pgpePstateParmBlockBuild |= 0x01;
    }
};

/**
 * @brief   builds a STOP image using a refrence image as input.
 * @param   i_procTgt    fapi2 target for processor chip.
 * @param   i_pImageIn   points to memory mapped refrence image in PNOR.
 * @param   o_pImageOut  points to a buffer where STOP image is built.
 * @param   i_phase      phase of the system i.e. IPL or Hypervisor/rebuild mode.
 * @param   i_pBuf       buffer of size >= HW_IMG_RING_SIZE for handling ring.
 * @note    needs attribute ATTR_EC
 */
fapi2::ReturnCode p9_hcode_image_build( CONST_FAPI2_PROC& i_procTgt,
                                        void* const i_pImageIn,
                                        void* o_pImageOut,
                                        SysPhase_t i_phase,
                                        ImageType_t i_imgType,
                                        void*     i_pBuf );
#endif //__HCODE_IMG_BUILD_H_
