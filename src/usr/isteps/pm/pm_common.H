/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/pm_common.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <isteps/pm/pm_common_ext.H>
#include <istepHelperFuncs.H>
#include <sys/mm.h>

// Definitions for convertHomerPhysToVirt()
#ifndef __HOSTBOOT_RUNTIME
#define HBPM_UNMAP     mm_block_unmap
#define HBPM_MAP       mm_block_map
#define HBPM_PHYS_ADDR (reinterpret_cast<void*>(i_phys_addr))
#define UNSEC_HOMER_PHYS_ADDR (reinterpret_cast<void*>(l_unsecureHomerAddr))
#else
#define HBPM_UNMAP     g_hostInterfaces->unmap_phys_mem
#define HBPM_MAP       g_hostInterfaces->map_phys_mem
#define HBPM_PHYS_ADDR i_phys_addr
#define UNSEC_HOMER_PHYS_ADDR l_unsecureHomerAddr
#endif

namespace HBPM
{
    enum
    {
        OccHostDataVersion = 0x000000A0,

        OCC_IBSCOM_RANGE_IN_MB = MEGABYTE,

        // Interrupt Types
        USE_FSI2HOST_MAILBOX = 0x00000000,
        USE_PSIHB_COMPLEX    = 0x00000001,

        // FIR Master
        NOT_FIR_MASTER = 0x00000000,
        IS_FIR_MASTER  = 0x00000001,

        // SMF Mode
        SMF_MODE_DISABLED = 0x00000000,
        SMF_MODE_ENABLED  = 0x00000001,

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

    //
    // @brief - Handles the core_checkstop_handler HWP
    //
    // @param[in] i_core_target      - Core Target ID
    // @param[in] i_override_restore - settings for the HWP. Are we overriding
    //                                 the xstop settings (true) or restoring
    //                                 the original settings (false)
    //
    // @return errlHndl_t

    errlHndl_t core_checkstop_helper_hwp(
                                const TARGETING::Target* i_core_target,
                                bool i_override_restore);
    //
    // @brief - Turns off unit xstops in the homer image
    //
    // @return errlHndl_t

    errlHndl_t core_checkstop_helper_homer();

} //namespace HBPM ends

#endif
