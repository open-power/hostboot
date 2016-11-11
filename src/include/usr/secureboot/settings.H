/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/settings.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#ifndef __SECUREBOOT_SETTINGS_H
#define __SECUREBOOT_SETTINGS_H

#include <stdint.h>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <cstdint>

namespace SECUREBOOT
{
    enum class SecureJumperState : uint8_t
    {
        SECURITY_DEASSERTED = 0b0,
        SECURITY_ASSERTED = 0b1,
    };

    /** @class Settings
     *
     *  @brief Caches and parses the hardware settings for Secureboot.
     */
    class Settings
    {
        public:
            Settings() : iv_enabled(false) { _init(); };
            ~Settings() {};

            /** @brief Determine if Secureboot is enabled. */
            bool getEnabled() const;

            /** @brief Get security switch register value. See wrapper
             *         in Secureboot's service.H for documentation
             */
            errlHndl_t getSecuritySwitch(uint64_t& o_regValue,
                TARGETING::Target* i_targ
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;

            /** @brief Returns the state of the secure jumper as reported by the
             *      given processor.  See wrapper in Secureboot's service.H
             *      for documenation.
             */
            errlHndl_t getJumperState(SecureJumperState& o_state,
                TARGETING::Target* i_targ
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;

        private:
            void _init();

            /** @brief  This helper method encapsulates the details of
             *          register reads.
             *  @par    Detailed Description:
             *          Reads a register at a given scom address and
             *          provides its result via the supplied register
             *          value reference. Returns an error if unsuccesful.
             *  @param  [in] i_targ The target processor to obtain the
             *          jumper state from. Must not be null.
             *  @param  [in] i_scomAddress A uint64_t corresponding to
             *          desired scomAddress to read.
             *  @param  [out] o_regValue A uint64_t reference to be
             *          populated with the contents of the requested
             *          register upon successful read.
             *
             *  @return errHndl_t Indicates whether the query was
             *          successful.
             *  @retval null if successful otherwise pointer to error log
             */
            errlHndl_t readSecurityRegister(TARGETING::Target* i_targ,
                                           const uint64_t i_scomAddress,
                                            uint64_t& o_regValue) const;

            /** Cached secure boot enabled value */
            bool iv_enabled;
    };
}

#endif
