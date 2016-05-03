/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/pm_common.H $                               */
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
#ifndef PM_COMMON_H
#define PM_COMMON_H

#include <limits.h>
#include <errl/errlentry.H>
#include <diag/prdf/prdfWriteHomerFirData.H>

namespace HBPM
{
    /*
     * @brief Host config data consumed by OCC
     */
    struct occHostConfigDataArea_t
    {
        uint32_t version;

        //For computation of timebase frequency
        uint32_t nestFrequency;

        // For determining the interrupt type to Host
        //  0x00000000 = Use FSI2HOST Mailbox
        //  0x00000001 = Use OCC interrupt line through PSIHB complex
        uint32_t interruptType;

        // For informing OCC if it is the FIR master:
        //  0x00000000 = Default
        //  0x00000001 = FIR Master
        uint32_t firMaster;

        // FIR collection configuration data needed by FIR Master
        //  OCC in the event of a checkstop
        uint8_t firdataConfig[3072];
    };

    enum
    {
        OccHostDataVersion = 0x00000090,

        OCC_LIDID = 0x81e00430, // @TODO RTC: 148935 Where to define?
        OCC_IBSCOM_RANGE_IN_MB = MEGABYTE,

        // Interrupt Types
        USE_FSI2HOST_MAILBOX = 0x00000000,
        USE_PSIHB_COMPLEX    = 0x00000001,

        // FIR Master
        NOT_FIR_MASTER = 0x00000000,
        IS_FIR_MASTER  = 0x00000001,

        // Hcode Reference Image LIDs
        NIMBUS_HCODE_LIDID = 0x81e00602, // @TODO RTC: 148935 Where to define?
        CUMULUS_HCODE_LIDID = 0x81e00603, // @TODO RTC: 148935 Where to define?
    };

    /**
     * @brief Build new Pstate Parameter Block for PGPE and CME
     *
     * @param[in] i_target:       Target processor
     * @param[in] i_homer:        Virtual address of current proc's HOMER
     *
     * @return errlHndl_t  Error log Pstate Parameter Block build failed
     */
    errlHndl_t pstateParameterBuild( TARGETING::Target* i_target,
                                     void* i_homer);

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
     * @param[in] i_mode            Selects initial load vs concurrent reloads
     * @return errlHndl_t  Error log if loadHcode failed
     */
    errlHndl_t loadHcode( TARGETING::Target* i_target,
                          void* i_pImageOut,
                          uint32_t i_mode );

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
     * @return errlHndl_t  Error log if loadOCCImageToHomer failed
     */
    errlHndl_t loadOCCImageToHomer(TARGETING::Target* i_target,
                                   uint64_t i_occImgPaddr,
                                   uint64_t i_occImgVaddr);

    /**
     * @brief Start PM Complex.
     *
     * @param[in] i_target:    target of processor
     *
     * @return errlHndl_t  Error log of startPMComplex failed
     */
    errlHndl_t startPMComplex (TARGETING::Target* i_target);

    /**
     * @brief Reset PM Complex.
     *
     * @param[in] i_target:    target of processor
     *
     * @return errlHndl_t  Error log of resetPMComplex failed
     */
    errlHndl_t resetPMComplex(TARGETING::Target * i_target);

} //namespace HBPM ends

#endif
