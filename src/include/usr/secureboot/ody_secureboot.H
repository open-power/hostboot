/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/ody_secureboot.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
#ifndef __ODY_SECUREBOOT
#define __ODY_SECUREBOOT

#include <stdint.h>
#include <errl/errlentry.H>

using namespace TARGETING;

/*
 * @file This file contains definitions of functions and structures for
 *       secureboot verification of Odyssey chips.
 */

/* @brief This union represents the structure of the SROM SB Control (SCOM 0x501B8)
          and Boot Loader SB Control (SCOM 0x501B9) registers. Note that bits 6 and 9
          differ between the two.
 */
union ody_secureboot_config_reg_t
{
    ody_secureboot_config_reg_t() {value = 0;}
    uint32_t value;
    struct fields_t
    {
        uint32_t securebootEnforcement : 1,       // 0
                 ECDSAVerificationEnable : 1,     // 1
                 dilithiumVerificationEnable : 1, // 2
                 ECIDVerificationEnable : 1,      // 3
                 hwKeyHashVerificationEnable : 1, // 4
                 secureModeEnable : 1,            // 5
                 reserved_1 : 1,                  // 6 (This bit differs between runtime and bootloader)
                 enableHashCalculation : 1,       // 7
                 bootComplete : 1,                // 8
                 productionImage : 1,             // 9 (bootloader only)
                 reserved_2 : 2,                  // 10-11
                 minimumSecureVersion : 8,        // 12-19
                 reserved_3 : 12;                 // 20-31
    } fields;
} ody_secureboot_config_reg;

/**
 * @brief Perform the secureboot verification for the given Odyssey OCMB.
 *
 * @param[in] i_ocmb the Odyssey OCMB chip to operate on
 *
 * @return Valid error log on failure; nullptr otherwise
 */
errlHndl_t odySecurebootVerification(Target* i_ocmb);

#endif
