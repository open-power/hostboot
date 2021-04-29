/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/settings_common.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __SECUREBOOT_SETTINGS_COMMON_H
#define __SECUREBOOT_SETTINGS_COMMON_H

/**
 * @file This file contains secureboot defines and constants that are common
 *       between HB and HBBL
 */

namespace SECUREBOOT
{
    enum ProcSecurity : uint64_t
    {
        SabBit   = 0x8000000000000000ull, // Secure access (mirrored)
        LLPBit   = 0x4000000000000000ull, // Late launch primary
        LLSBit   = 0x2000000000000000ull, // Late launch secondary
        LQABit   = 0x1000000000000000ull, // Local quiesce achieved
        SULBit   = 0x0800000000000000ull, // Security update lock
        L4ABit   = 0x0400000000000000ull, // Locality 4 access
        SDBBit   = 0x0200000000000000ull, // Secure chip debug mode
        CMFSIBit = 0x0100000000000000ull, // cMFSI access protection
        ABUSBit  = 0x0080000000000000ull, // Abus mailbox protection
        RNGBit   = 0x0040000000000000ull, // Random number generator lock
        // Spare = 0x0020000000000000ull,
        // Spare = 0x0010000000000000ull,
        TDPBit   = 0x0008000000000000ull, // TPM deconfig protection
        SOLBit   = 0x0004000000000000ull, // Secure OCMB lock
        // Spare = 0x0002000000000000ull,
        // Spare = 0x0001000000000000ull,
        KsPhypWrLock =  0x0000800000000000ull, // Keystore write lock (PHyp)
        KsPhypRdLock = 0x0000400000000000ull, // Keystore read lock (PHyp)
        KsHbWrLock = 0x0000200000000000ull, // Keystore SEEPROM write lock (Hostboot section)
        KsHbRdLock = 0x0000100000000000ull, // Keystore SEEPROM read lock (Hostboot section)
        KsOpalBank0WrLock = 0x0000080000000000ull, // Keystore write lock (Opal Bank 0)
        KsOpalBank0RdLock = 0x0000040000000000ull, // Keystore read lock (Opal Bank 0)
        KsOpalBank1WrLock = 0x0000020000000000ull, // Keystore write lock (Opal Bank 1)
        KsOpalBank1RdLock = 0x0000010000000000ull, // Keystore read lock (Opal Bank 1)
        KsOpalQueueWrLock = 0x0000008000000000ull, // Keystore write lock (Opal Queue)
        KsOpalQueueRdLock = 0x0000004000000000ull, // Keystore read lock (Opal Queue)
        MELBit   = 0x0000000800000000ull, // Memory encryption lock

        SwitchRegister = 0x00010005ull,
        SwitchRegisterClear = 0x00010006ull,
    };

} // namespace SECUREBOOT

#endif
