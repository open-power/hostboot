/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/occ/occ_common.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#ifndef OCC_COMMON_H
#define OCC_COMMON_H

#include <limits.h>
#include <errl/errlentry.H>

namespace HBOCC
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
        OccHostDataVersion = 3,
        OCC_LIDID = 0x81e00430,
        OCC_IBSCOM_RANGE_IN_MB = MEGABYTE,

        // Interrupt Types
        USE_FSI2HOST_MAILBOX = 0x00000000,
        USE_PSIHB_COMPLEX    = 0x00000001,

        // FIR Master
        NOT_FIR_MASTER = 0x00000000,
        IS_FIR_MASTER  = 0x00000001
    };

    enum occAction_t
    {
        OCC_START,
        OCC_STOP,
    };
    /**
     * @brief Sets up OCC Host data
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
     * @brief Execute procedures and steps required to load
     *        OCC data in a specified processor
     *
     * @param[in] i_target:         target processor to load
     * @param[in] i_homerPhysAddr:  Physical address of current
     *                                 proc's homer
     * @param[in] i_homerVirtAddr:  Virtual address of current
     *                                 proc's homer
     * @param[in] i_commonPhysAddr: Physical address of common
     *                              occ region
     * @return errlHndl_t  Error log of loadOCC failed
     */
    errlHndl_t loadOCC(TARGETING::Target* i_target,
                       uint64_t i_homerPhysAddr,
                       uint64_t i_homerVirtAddr,
                       uint64_t i_commonPhysAddr);

    /**
     * @brief Start OCC for specified DCM pair of processors.
     *        If 2nd input is NULL, OCC will be setup on just
     *        one target.
     *
     * @param[in] i_target0:    target of first processor in DCM pair
     * @param[in] i_target1:    target of second processor in DCM pair
     * @param[out] o_failedTarget failed target in case of an error
     *
     * @return errlHndl_t  Error log of startOCC failed
     */
    errlHndl_t startOCC (TARGETING::Target* i_target0,
                         TARGETING::Target* i_target1,
                         TARGETING::Target *& o_failedTarget);
    /**
     * @brief Stop OCC for specified DCM pair of processors.
     *        If 2nd input is NULL, OCC will be setup on just
     *        one target.
     *
     * @param[in] i_target0:    target of first processor in DCM pair
     * @param[in] i_target1:    target of second processor in DCM pair
     *
     * @return errlHndl_t  Error log of stopOCC failed
     */
    errlHndl_t stopOCC(TARGETING::Target * i_target0,
                       TARGETING::Target * i_target1);

    /**
     * @brief Stops OCCs on all Processors in the node
     *        Function will attempt to stop all OCCs and commit
     *        logs inline.  An error will only be returned for
     *        very unexpected software fails.
     *
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t stopAllOCCs();

} //namespace HBOCC ends

#endif
