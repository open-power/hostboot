/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/settings.H $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
            bool getEnabled();

        private:
            void _init();

                /** Cached register value. */
            uint64_t iv_regValue;

                /** SCOM address for security settings. */
            static const uint64_t SECURITY_SWITCH_REGISTER;
                /** Bitfield mask for Secureboot enable flag. */
            static const uint64_t SECURITY_SWITCH_TRUSTED_BOOT;
    };
}

#endif
