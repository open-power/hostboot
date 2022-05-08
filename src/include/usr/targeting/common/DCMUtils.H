/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/DCMUtils.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

#ifndef DUAL_CHIP_MODULE_H
#define DUAL_CHIP_MODULE_H

/**
 * @file DCMUtils.H
 *
 * @brief DCM (Dual Chip Module) utilities
 *
 */

#ifdef __HOSTBOOT_MODULE

#include <map>
#include <hwas/common/deconfigGard.H>

namespace TARGETING
{

class DCMUtils
{
    public:
        /**
         *  @brief Default Constructor
         *
         *  Constructor only initializes internal variables, does not do any
         *  actual work.
         */
        DCMUtils();

        /**
         * @brief Will determine if the system is a Dual Chip Module system or not.
         *        The system is considered a Dual Chip Module if any PROC is paired
         *        with another other PROC via the location code of the PROCs.
         *
         * @note Will populate the class with paired data if not done so.
         *
         * @return: true if any PROC has a pair, false otherwise
         */
        bool isSystemDCM();

        /**
         * @brief Get the associated IO SCM chip of i_procTarget if the system
         *        is a dual chip module with IO SCM chips.
         *        If i_procTarget itself is an IO SCM chip then nothing is returned.
         *
         * @note Will populate the class with paired data if not done so.
         *
         * @param[in] i_procTarget The PROC's target to find paired IO SCM chip for
         * @return: The IO SCM chip associated with the PROC target if found, else nullptr
         */
        TargetHandle_t getAssociatedIoScmChip(TargetHandle_t i_procTarget);

        /**
         * @brief Dump dual chip pairs found on system and a subset of their
         *        state. For testing and debugging purposes.
         *
         * @note Will populate the class with paired data if not done so.
         *
         *  Data dumps will look similar to:
         *    Is system dual chip: 1 (0: no; 1: yes)
         *      Location Code LocCodeXX is paired: 1 (0: no; 1: yes)
         *        PROC target HUID 0x00050000
         *           present cores: 10
         *           is functional: 1
         *           is spec deconfig: 0
         *           deconfig by EID: 0
         *        IO SCM chip HUID 0x00050001
         *           present cores: 0
         *           is functional: 1
         *           is spec deconfig: 0
         *           deconfig by EID: 0
         *       ....
         */
        void dumpDcmPairs();

    private:
        /**
         * @brief This method will inspect each PROC and pair each PROC based on the
         *        PROC's location code. If any PROC is paired then the system is
         *        considered a dual chip module system. This will populate the class
         *        with the found paired PROCs.
         */
        void determineSystemIsDCM();

        /**
         *  @brief A struct to hold DCM PROC pairs
         */
        struct dcmProcsPairs_t
        {
            // True if both iv_procTarget and iv_ioScmChip are not NULL, false otherwise.
            bool  iv_isPaired = false;
            TargetHandle_t iv_procTarget = nullptr;  // The PROC target of the pair
            TargetHandle_t iv_ioScmChip = nullptr;   // The IO SCM chip of the pair
            ATTR_HUID_type iv_procTargetHuid = 0; // HUID of the PROC target
            ATTR_HUID_type iv_ioScmChipHuid = 0;  // HUID of the IO SCM chip
            uint32_t iv_procTargetCores = 0;      // Number of cores the PROC targets contains
                                        // The number of cores the IO SCM chip contains is always 0

            /**
             * @brief Add target to DCM pair struct. Type of target, PROC or IO SCM chip,
             *        is determined by the number of cores the target has:
             *          0 cores = IO SCM chip
             *          non 0 cores = PROC
             *
             * @param[in] i_target Pointer to a PROC target or an IO SCM chip
             * @param[in] i_nCores The number of present cores i_target contains
             * @param[in] i_procHuid The HUID of i_target
             */
            void addTarget(Target* i_target, const size_t i_nCores, const uint32_t i_procHuid)
            {
                // If the number of cores is not 0 then the target is a PROC target,
                // If the number of cores *is* 0 then the target is an IO Chip
                if (i_nCores)
                {
                    iv_procTarget = i_target;
                    iv_procTargetHuid = i_procHuid;
                    iv_procTargetCores = i_nCores;
                }
                else
                {
                    iv_ioScmChip = i_target;
                    iv_ioScmChipHuid = i_procHuid;
                }

                if (iv_procTarget && iv_ioScmChip)
                {  iv_isPaired = true; }
            }
        } ;

        /**
         * @brief Methods to dump the PROC and IO SCM chip
         *
         * @param[in] i_dcmProcPair a struct containing useful info about the targets
         */
        void dumpProcTarget(const dcmProcsPairs_t &i_dcmProcPair) const;
        void dumpIoScmChip(const dcmProcsPairs_t &i_dcmProcPair) const;

        // True if system has been searched for pairs, false otherwise
        bool iv_isInitialized;
        // True if any PROCs are paired, false otherwise
        bool iv_isSystemDCM;

        // A mapping of the PROC/IO SCM pair data to their common location code
        std::map<ATTR_STATIC_ABS_LOCATION_CODE_typeStdArr, dcmProcsPairs_t> iv_mapDcmPairs;

}; // class DCMUtils

} // namespace TARGETING

#endif // __HOSTBOOT_MODULE

#endif //  DUAL_CHIP_MODULE_H
