/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_utils.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#ifndef __SBE_UTILS_H
#define __SBE_UTILS_H

#include <targeting/common/commontargeting.H>

/**
 * @file sbe_utils.H
 * @brief Common sbeio utilities for both PSU and FIFO
 */

namespace SBEIO
{
    static constexpr size_t SBE_MAX_LENGTH_IMAGE_HASH = 16;

    /**
    * @brief constexpr for the SBE Capabilities
    *
    *   Complies with document Host_SBE_Interface_Specification_v0.9e.pdf
    */
    // POZ SBE FIFO Interface Specification v1.1 shows a max of 16 capabilities
    static constexpr uint8_t POZ_SBE_MAX_CAPABILITIES = 16;
    // SBE FIFO Interface Specification for P10 Systems v2.1 shows a max of
    //  26 for Get Capabilities 2
    static constexpr uint8_t SBE_MAX_CAPABILITIES_2 = 26;

    static constexpr uint8_t SBE_RELEASE_TAG_MAX_CHARS = 20;

    // access values into capabilities array
    static constexpr uint8_t  SBE_CAPABILITY_HALT_OFFSET = 22;
    static constexpr uint32_t SBE_CMD_HALT_SUPPORTED = 0xAB000001;

    // The maximum amount of pages hostboot will allow FFDC package buffers from SBE to be.
    // This is chosen arbitrarily as a defense against cases where the End-of-Transmission (EOT) is not
    // recieved from SBE.
    static constexpr uint8_t SBE_FFDC_MAX_PAGES = 6;

    // For 4U max is 181 bytes - setting max to 256 words
    // See fips1010 sbeiInternal.H
    // SBE is a 32-bit engine so use uint32_t (Hostboot words are uint64_t)
    static constexpr uint32_t SBE_PMIC_HLTH_CHECK_BUFFER_LEN_BYTES = 256 * sizeof(uint32_t);

    enum SBE_TARGET_TYPES {
        SBE_TARGET_TYPE_PROC_CHIP    = 0x0000,
        SBE_TARGET_TYPE_PERV         = 0x0001,
        SBE_TARGET_TYPE_EQ           = 0x0002,
        SBE_TARGET_TYPE_CORE         = 0x0003,
        SBE_TARGET_TYPE_OCMB_CHIP    = 0x0004,
        SBE_TARGET_TYPE_TOTAL          ,
        SBE_TARGET_TYPE_UNKNOWN  = 0xFF
    };

    /// @brief translates HB target types tob SBE target type groups
    /// @param[in] i_hbTarget includes the HB target type
    /// @return SBEIO::SBE_TARGET_TYPES returns SBE_TARGET_TYPE_UNKNOWN in error
    SBE_TARGET_TYPES translateToSBETargetType(TARGETING::Target * i_hbTarget);

    /// @brief returns a ChipletID for a give target
    /// @param[in] i_hbTarget includes the HB target type
    /// @return: ChipletID for i_hbTarget target
    uint8_t getChipletIDForSBE(TARGETING::Target * i_hbTarget);

    /**
     * @brief Some SBE chip ops will perform actions on a target. In this
     *        case we need to find the processor associated with that
     *        target so we know what SBE to send our chip op to.
     *        This function will lookup the correct processor to use
     *        to perform such a chip op.
     *
     * @param[in] i_target  Target which we want to the processor accociated with
     *
     * @return Target ptr pointing to the processor associated with i_target,
     *         if no associated processor is found this will be nullptr
     */
    TARGETING::Target* getChipForPsuOp(TARGETING::Target *i_target);

    /**
     * @brief Common function to check for interface usage errors. Checks if the boot proc, sentinel, nullptr, or
     *        non-odyssey chip was passed into a chipop function.
     *
     * @param[in] i_target The target to test
     *
     * @param[in] i_commandClass The command class for the SBE FIFO message being attempted. Provides context for the
     *                           error.
     *
     * @param[in] i_command      The command for the SBE FIFO message being attempted. Provides context for the error.
     *
     * @param[in] i_addr  Optional. The address that was attempted to be accessed if one was used. Can be useful for
     *                    context when doing SCOM chipops.
     *
     * @return errlHndl_t an error or nullptr.
     */
    errlHndl_t sbeioInterfaceChecks(TARGETING::Target * i_target,
                                    uint8_t             i_commandClass,
                                    uint8_t             i_command,
                                    uint64_t            i_addr = 0);

    /**
     * @brief Specific function to check for Odyssey chip.
     *
     * @param[in] i_target The target to test
     *
     * @param[in] i_commandClass The command class for the SBE FIFO message being attempted. Provides context for the
     *                           error.
     *
     * @param[in] i_command      The command for the SBE FIFO message being attempted. Provides context for the error.
     *
     * @return errlHndl_t an error or nullptr.
     */
    errlHndl_t sbeioOdysseyCheck(TARGETING::Target * i_target,
                                 uint8_t             i_commandClass,
                                 uint8_t             i_command);
}

#endif  // __SBE_UTILS_H
