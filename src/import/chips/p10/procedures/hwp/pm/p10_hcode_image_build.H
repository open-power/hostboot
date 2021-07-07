/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_hcode_image_build.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#ifndef __HCODE_IMG_BUILD_H_
#define __HCODE_IMG_BUILD_H_


///
/// @file   p10_hcode_image_build.H
/// @brief  describes HWP interface that builds the STOP image.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    HB:HBRT
//

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <fapi2.H>
#include <stdint.h>
#include <p10_infrastruct_help.H>

extern "C"
{

#define HW_IMG_RING_BUF1_SIZE 307200

    typedef  const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > CONST_FAPI2_PROC;

    namespace hcodeImageBuild
    {

    /**
     * @brief   phases of system associated for hcode image build.
     */
    enum SysPhase_t
    {
        PHASE_NA        =   0,
        PHASE_IPL       =   1,
        PHASE_REBUILD   =   2,
        PHASE_END       =   3,
    };

    /**
     * @brief   constants used for hcode image build.
     */
    enum
    {
        HW_IMG_RING_SIZE    =  MAX_SEEPROM_IMAGE_SIZE,
        WORK_BUF_SIZE       =  MAX_RING_BUF_SIZE
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
        union
        {
            struct
            {
                uint32_t selfRestoreBuild: 1;           // for self restore code inclusion
                uint32_t qmeHcodeBuild: 1;              // for qme hcode inclusion
                uint32_t qmeCommonRingBuild: 1;         // for core ring inclusion
                uint32_t qmeCoreSpecificRingBuild: 1;   // for core specific scan ring inclusion
                uint32_t xgpeImageBuild: 1;             // for xgpe inclusion
                uint32_t xgpeCommonRingBuild: 1;        // for xgpe common scan ring inclusion
                uint32_t xgpeCacheSpecificRingBuild: 1; // for cache specific ring inclusion
                uint32_t pgpeImageBuild: 1;             // pgpe platform inclusion in image build
                uint32_t pgpePstateParmBlockBuild: 1;   // pgpe P-State Parameter Block Build
                uint32_t coreSprBuild: 1;               // SPR restore region inclusion in HOMER Build
                uint32_t coreScomBuild: 1;              // Core SCOM restore region inclusion in HOMER Build
                uint32_t cacheScomBuild: 1;             // Cache SCOM restore region inclusion in HOMER Build
                uint32_t reserved: 20;
            };
            uint32_t value_32;
        };

        ImageType_t( )
        {
            memset( this , 0, sizeof (*this) );
            this->selfRestoreBuild              |=      0x01;
            this->qmeHcodeBuild                 |=      0x01;
            this->qmeCommonRingBuild            |=      0x01;
            this->qmeCoreSpecificRingBuild      |=      0x01;
            this->xgpeImageBuild                |=      0x01;
            this->xgpeCommonRingBuild           |=      0x01;
            this->xgpeCacheSpecificRingBuild    |=      0x01;
            this->pgpeImageBuild                |=      0x01;
            this->pgpePstateParmBlockBuild      |=      0x01;
            this->coreSprBuild                  |=      0x01;
            this->coreScomBuild                 |=      0x01;
            this->cacheScomBuild                |=      0x01;
        }

        bool isBuildValid()
        {
            bool buildValid = false;

            if ( ( this->selfRestoreBuild )         ||
                 ( this->qmeHcodeBuild )            ||
                 ( this->qmeCommonRingBuild )       ||
                 ( this->qmeCoreSpecificRingBuild ) ||
                 ( this->xgpeImageBuild )           ||
                 ( this->xgpeCommonRingBuild )      ||
                 ( this->xgpeCacheSpecificRingBuild ) ||
                 ( this->pgpeImageBuild )           ||
                 ( this->pgpePstateParmBlockBuild ) ||
                 ( this->coreSprBuild )             ||
                 ( this->coreScomBuild )            ||
                 ( this->cacheScomBuild ) )
            {
                buildValid = true;
            }

            return buildValid;
        }

        void configRebuildPhase()
        {
            this->coreSprBuild      &=  0x0;
            this->coreScomBuild     &=  0x0;
            this->cacheScomBuild    &=  0x0;
        }

        void configBuildPhase()
        {
            this->coreSprBuild      |=  0x1;
            this->coreScomBuild     |=  0x1;
            this->cacheScomBuild    |=  0x1;
        }

    };

    typedef fapi2::ReturnCode( *p10_hcode_image_build_FP_t )
    ( CONST_FAPI2_PROC& i_procTgt,
      void* const       i_pImageIn,
      void*             i_pHomerImage,
      void* const       i_pRingOverride,
      SysPhase_t        i_phase,
      ImageType_t       i_imgType,
      void*  const      i_pBuf1,
      const  uint32_t   i_sizeBuf1,
      void*  const      i_pBuf2,
      const  uint32_t   i_sizeBuf2,
      void*  const      i_pBuf3,
      const  uint32_t   i_sizeBuf3,
      void*  const      i_pBuf4,
      const  uint32_t   i_sizeBuf4 );

    /**
    * @brief   builds a STOP image using a refrence image as input.
    * @param   i_procTgt        fapi2 target for processor chip.
    * @param   i_pImageIn       points to memory mapped hw image in PNOR.
    * @param   i_pHomerImage    pointer to the beginning of the HOMER image buffer.
    * @param   i_pRingOverride  pointer to the location of override ring. NULL means override not available.
    * @param   i_phase          phase of the system i.e. IPL or Hypervisor/rebuild mode.
    * @param   i_imgType        image type to be built.
    * @param   i_pBuf1          pointer to a work buffer1.
    * @param   i_sizeBuf1       size of work buffer1. Minimum size expected HW_IMG_RING_SIZE.
    * @param   i_pBuf2          pointer to a work buffer2. Minimum size expected WORK_BUF_SIZE.
    * @param   i_sizeBuf2       size of work buffer2
    * @param   i_pBuf3          pointer to a work buffer3. Minimum size expected WORK_BUF_SIZE.
    * @param   i_sizeBuf3       size of work buffer3
    * @param   i_pBuf4          pointer to a work buffer4. Minimum size expected WORK_BUF_SIZE.
    * @param   i_sizeBuf4       size of work buffer4
    */
    fapi2::ReturnCode p10_hcode_image_build( CONST_FAPI2_PROC&  i_procTgt,
            void* const         i_pImageIn,
            void*               i_pHomerImage,
            void* const         i_pRingOverride,
            SysPhase_t          i_phase,
            ImageType_t         i_imgType,
            void*  const        i_pBuf1,
            const  uint32_t     i_sizeBuf1,
            void* const         i_pBuf2,
            const uint32_t      i_sizeBuf2,
            void* const         i_pBuf3,
            const uint32_t      i_sizeBuf3,
            void* const         i_pBuf4,
            const uint32_t      i_sizeBuf4 );

    } // namespace hcodeImageBuild
} // extern C

#endif //__HCODE_IMG_BUILD_H_
