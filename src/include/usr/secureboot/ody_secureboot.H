/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/ody_secureboot.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
          and Boot Loader SB Control (SCOM 0x501B9) registers. Note that bit 6
          differs between the two, but we don't use that bit in secureboot verification
          of these registers in Hostboot.
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
                 reserved_2 : 3,                  // 9-11
                 minimumSecureVersion : 8,        // 12-19
                 reserved_3 : 12;                 // 20-31
    } fields;
} ody_secureboot_config_reg;

/* @brief This union represents the structure of ATTR_OCMB_BOOT_FLAGS, defined in
          src/import/chips/ocmb/odyssey/procedures/xml/attribute_info/ody_perv_attributes.xml
          This structure needs to be kept in-sync with the attribute.
 */
union ocmb_boot_flags_t
{
    ocmb_boot_flags_t() {value = 0;}
    uint32_t value;
    struct fields_t
    {
        uint32_t bootIndication : 2,                 // 0-1
                 reserved_1 : 1,                     // 2
                 isSimulation : 1,                   // 3
                 securityEnable : 1,                 // 4
                 noFFDCSend : 1,                     // 5
                 disableSecurity : 1,                // 6
                 allowAttrOverrides : 1,             // 7
                 reserved_2 : 3,                     // 8-10
                 disableScomFiltering : 1,           // 11
                 disableInvalidScomAddrCheck : 1,    // 12
                 mfgMode : 1,                        // 13
                 reserved_3 : 2,                     // 14-15
                 enableECDSASignature : 1,           // 16
                 enableDilithiumSignature : 1,       // 17
                 enableECIDVerification : 1,         // 18
                 enableHWKeyHashVerification : 1,    // 19
                 enableFileHashCalculation : 1,      // 20
                 enforceBlSecurityVersion : 1,       // 21
                 secureBootValidityVerification : 1, // 22
                 disableIOBist : 1,                  // 23
                 disableAbist : 1,                   // 24
                 disableLbist : 1,                   // 25
                 enableBurnInMode : 1,               // 26
                 gracefulTerminate : 1,              // 27
                 forceProdMode : 1,                  // 28
                 reserved_4 : 3;                     // 29-31
    } fields;
} ocmb_boot_flags;

/**
 * @brief Perform the secureboot verification for the given Odyssey OCMB.
 *
 * @param[in] i_ocmb the Odyssey OCMB chip to operate on
 *
 * @return Valid error log on failure; nullptr otherwise
 */
errlHndl_t odySecurebootVerification(Target* i_ocmb);

#endif
