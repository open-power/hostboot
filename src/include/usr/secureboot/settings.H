/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/settings.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

namespace SECUREBOOT
{
    /** @class Settings
     *
     *  @brief Caches and parses the hardware settings for Secureboot.
     */
    class Settings
    {
        public:
            Settings() : iv_regValue(0) { _init(); };
            ~Settings() {};

            /** @brief Determine if Secureboot is enabled. */
            bool getEnabled() const;

            /** @brief Get security switch register value */
            uint64_t getSecuritySwitch() const;

            /** @brief Returns the state of the secure jumper as reported by the
             *      master processor.
             *
             *  @par Detailed Description:
             *      Returns the state of the secure jumper as reported by the
             *      master processor.  This should NOT be used to determine
             *      whether security is enabled, because several conditions are
             *      aggregated together to determine that.  To query whether
             *      security is actually enabled or not, call the enabled() API.
             *      This is a limited-use API intended to be called by trusted
             *      boot code to determine whether a system shipped with a
             *      secure jumper applied or removed, in order to decide
             *      whether to enforce the "TPM Required" policy or not.
             *
             *  @return Boolean indicating acting master processor's secure
             *      jumper state
             *  @retval true Jumper is configured to request HW security.  This
             *      does not necessarily imply security is enabled, because an
             *      open SBE can override the HW policy.  Use the getEnabled()
             *      API to determine whether security is actually enabled.
             *  @retval false Jumper is configured to disble HW security.
             */
            bool getJumperState() const;

        private:
            void _init();

            /** Cached register value. */
            uint64_t iv_regValue;
    };
}

#endif
