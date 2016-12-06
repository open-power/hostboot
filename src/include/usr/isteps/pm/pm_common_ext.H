/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/pm/pm_common_ext.H $                   */
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
#ifndef PM_COMMON_EXT_H
#define PM_COMMON_EXT_H

#include <errl/errlentry.H>

namespace HBPM
{
    /**
     * @brief Enumeration of the load PM complex mode
     *      LOAD
     *       - Call pm_reset first
     *       - Load OCC lid, write OCC config data, build Pstate
     *         Parameter Blocks, and load Hcode reference image lid
     *      RELOAD
     *       - Reload OCC lid, rewrite OCC config data, build Pstate
     *         Parameter Blocks, and rebuild Hcode
     *      UNKNOWN
     *       - Unknown PM load type, do not load OCC/HCODE
     */
    enum loadPmMode
    {
        PM_LOAD         = 0x0,
        PM_RELOAD       = 0x1,
        PM_UNKNOWN      = 0xFF,
    };

    /**
     *  @brief Convert HOMER physical address space to a vitual address
     *  @param[in]  i_proc_target  Processsor target
     *  @param[in]  i_phys_addr    Physical address
     *  @return NULL on error, else virtual address
     */
    void *convertHomerPhysToVirt( TARGETING::Target* i_proc_target,
                                  uint64_t i_phys_addr);

    /**
     * @brief Load PM Complex for all proc targets.
     *
     * @param[in] i_mode        Load / Reload
     *
     * @return errlHndl_t  Error log of loadPMAll failed
     */
    errlHndl_t loadPMAll(loadPmMode i_mode);

    /**
     * @brief Start PM Complex for all proc targets.
     *
     * @return errlHndl_t  Error log if startPMAll failed
     */
    errlHndl_t startPMAll();

    /**
     * @brief Reset PM Complex for all proc targets.
     *
     * @return errlHndl_t  Error log if resetPMAll failed
     */
    errlHndl_t resetPMAll();

    /**
     * @brief Fetch the ring overrides (if they exist)
     *
     * @param[inout] io_overrideImg   NULL if image not in PNOR or is blank,
     *        else pointer to override data
     *
     * @return errlHndl_t  Error log if resetPMAll failed
     */
    errlHndl_t getRingOvd(void*& io_overrideImg);

#if __HOSTBOOT_RUNTIME
    /**
     *  @brief Modify the SCOM restore section of the HCODE image with the
     *          given register data
     *  @param  i_section        Runtime section to update
     *                           (passthru to pore_gen_scom)
     *  @param  i_operation      Type of operation to perform
     *                           (passthru to pore_gen_scom)
     *  @param  i_target         Target owning the scom address
     *  @param  i_rel_scom_addr  Fully qualified scom address
     *  @param  i_scom_data      Data for operation
     *  @return errlHndl_t
    */
    errlHndl_t hcode_update( uint32_t i_section,
                             uint32_t i_operation,
                             TARGETING::Target*  i_target,
                             uint64_t i_rel_scom_addr,
                             uint64_t i_scom_data );
#endif
} //namespace HBPM ends

#endif
