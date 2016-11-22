/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/pm/pm_common_ext.H $                   */
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
#ifndef PM_COMMON_EXT_H
#define PM_COMMON_EXT_H

#include <errl/errlentry.H>

namespace HBPM
{
    /**
     * @brief Enumeration of the load PM complex mode
     *      LOAD == i_mode
     *       - Call pm_reset first
     *       - Load OCC lid, write OCC config data, build Pstate
     *         Parameter Blocks, and load Hcode reference image lid
     *      RELOAD == i_mode
     *       - Reload OCC lid, rewrite OCC config data, build Pstate
     *         Parameter Blocks, and rebuild Hcode
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

} //namespace HBPM ends

#endif
