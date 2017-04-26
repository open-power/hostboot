/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/pm_common.H $                               */
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
#ifndef PM_COMMON_H
#define PM_COMMON_H

#include <limits.h>
#include <errl/errlentry.H>
#include <util/utillidmgr.H>
#include <diag/prdf/prdfWriteHomerFirData.H>
#include <isteps/pm/pm_common_ext.H>

namespace HBPM
{
    enum
    {
        OccHostDataVersion = 0x00000090,

        OCC_IBSCOM_RANGE_IN_MB = MEGABYTE,

        // Interrupt Types
        USE_FSI2HOST_MAILBOX = 0x00000000,
        USE_PSIHB_COMPLEX    = 0x00000001,

        // FIR Master
        NOT_FIR_MASTER = 0x00000000,
        IS_FIR_MASTER  = 0x00000001,

        // Mask off bit zero
        PHYSICAL_ADDR_MASK = 0x7FFFFFFFFFFFFFFF,
        VER_EYECATCH       = 0x56455253494F4E00, //'VERSION\0'
    };

    /**
     * @brief Sets up OCC Host data in Homer
     *
     * @param[in] i_proc:         target processor to load
     * @param[in] i_occHostDataVirtAddr Virtual
     *                       address of current
     *                       proc's Host data area.
     *
     * @return errlHndl_t  Error log Host data setup failed
     */
    errlHndl_t loadHostDataToHomer(TARGETING::Target* i_proc,
                                   void* i_occHostDataVirtAddr);

    /**
     * @brief Sets up Hcode in Homer
     *
     * @param[in] i_target:         Target processor
     * @param[in] i_pImageOut:      Pointer to HOMER image buffer
     * @param[in] i_mode            Selects initial load vs concurrent reload
     * @return errlHndl_t  Error log if loadHcode failed
     */
    errlHndl_t loadHcode( TARGETING::Target* i_target,
                          void* i_pImageOut,
                          loadPmMode i_mode );

    /**
     * @brief Execute procedures and steps required to setup for loading
     *        the OCC image in a specified processor
     *
     * @param[in] i_target:         Target processor
     * @param[in] i_occImgPaddr:    Physical address of current
     *                                 proc's OCC image in the homer
     * @param[in] i_occImgVaddr:  Virtual address of current
     *                                 proc's OCC image in the homer
     * @param[in] i_commonPhysAddr: Physical address of common
     *                              OCC region
     * @return errlHndl_t  Error log if loadOCCSetup failed
     */
    errlHndl_t loadOCCSetup(TARGETING::Target* i_target,
                            uint64_t i_occImgPaddr,
                            uint64_t i_occImgVaddr,
                            uint64_t i_commonPhysAddr);

    /**
     * @brief Execute procedures and steps required to load
     *        OCC image in a specified processor
     *
     * @param[in] i_target:         Target processor
     * @param[in] i_occImgPaddr:    Physical address of current
     *                                 proc's OCC image in the homer
     * @param[in] i_occImgVaddr:    Virtual address of current
     *                                 proc's OCC image in the homer
     * @param[in] i_mode            Selects initial load vs concurrent reload
     * @return errlHndl_t  Error log if loadOCCImageToHomer failed
     */
    errlHndl_t loadOCCImageToHomer(TARGETING::Target* i_target,
                                   uint64_t i_occImgPaddr,
                                   uint64_t i_occImgVaddr,
                                   loadPmMode i_mode);

    /**
     * @brief Load PM Complex.
     *
     * @param[in] i_target:         Target of processor
     * @param[in] i_homerPhysAddr:  Homer physical address
     * @param[in] i_commonPhysAddr: OCC common area physical address
     * @param[in] i_mode:           Load / Reload
     *      LOAD == i_mode
     *       - Call pm_reset first
     *       - Load OCC lid, write OCC config data, build Pstate
     *         Parameter Blocks, and load Hcode reference image lid
     *      RELOAD == i_mode
     *       - Reload OCC lid, rewrite OCC config data, build Pstate
     *         Parameter Blocks, and rebuild Hcode
     *
     * @return errlHndl_t  Error log if loadPMComplex failed
     */
    errlHndl_t loadPMComplex(TARGETING::Target * i_target,
                             uint64_t i_homerPhysAddr,
                             uint64_t i_commonPhysAddr,
                             loadPmMode i_mode);

    /**
     * @brief Start PM Complex.
     *
     * @param[in] i_target:    target of processor
     *
     * @return errlHndl_t  Error log if startPMComplex failed
     */
    errlHndl_t startPMComplex(TARGETING::Target* i_target);

    /**
     * @brief Reset PM Complex.
     *
     * @param[in] i_target:    target of processor
     *
     * @return errlHndl_t  Error log if resetPMComplex failed
     */
    errlHndl_t resetPMComplex(TARGETING::Target * i_target);

} //namespace HBPM ends

#endif
