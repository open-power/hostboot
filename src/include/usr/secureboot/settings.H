/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/settings.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <vector>

namespace SECUREBOOT
{
    enum class SecureJumperState : uint8_t
    {
        SECURITY_DEASSERTED = 0b0,
        SECURITY_ASSERTED = 0b1,
    };

    // these constants represent the scom addresses and masks we need
    // to obtain secure boot settings from the system
    enum class ProcSecurity : uint64_t
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
        // Spare = 0x0004000000000000ull,
        // Spare = 0x0002000000000000ull,
        // Spare = 0x0001000000000000ull,
        SKLBitW  = 0x0000008000000000ull, // Keystore SEEPROM write lock (Hostboot section)
        SKLBitR  = 0x0000004000000000ull, // Keystore SEEPROM read lock (Hostboot section)
        MELBit   = 0x0000000800000000ull, // Memory encryption lock

        SwitchRegister = 0x00010005ull,
        SwitchRegisterClear = 0x00010006ull,
    };

    enum class ProcCbsControl : uint64_t
    {
        SabBit         = 0x0800000000000000ull, // Secure access
        JumperStateBit = 0x0400000000000000ull, // Secure jumper

        StatusRegister    = 0x00050001ull, // used for SCOM operation
        StatusRegisterFsi = 0x00002804ull, // used for FSI operation
    };

    inline bool operator|(const ProcCbsControl i_cbs, const uint64_t i_value)
    {
        return (static_cast<uint64_t>(i_cbs) | i_value);
    }

    inline bool operator&(const ProcCbsControl i_cbs, const uint64_t i_value)
    {
        return (static_cast<uint64_t>(i_cbs) & i_value);
    }

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
                TARGETING::Target* i_pProc
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;

            /** @brief Get Processor CBS Control regeister value. See wrapper
             *         in Secureboot's service.H for documentation
             */
            errlHndl_t getProcCbsControlRegister(uint64_t& o_regValue,
                TARGETING::Target* i_pProc
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;

            /**
             *  @brief Clear bits in the processor security swith register.  See
             *      full documentation in service.H.
             */
            errlHndl_t clearSecuritySwitchBits(
                const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
                      TARGETING::Target*                     i_pTarget =
                      TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;
            /**
             *  @brief Set bits in the processor security swith register.  See
             *      full documentation in service.H.
             */
            errlHndl_t setSecuritySwitchBits(
                const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
                      TARGETING::Target*                     i_pTarget =
                      TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;

            /** @brief Returns the state of the secure jumper as reported by the
             *      given processor.  See wrapper in Secureboot's service.H
             *      for documenation.
             */
            errlHndl_t getJumperState(SecureJumperState& o_state,
                TARGETING::Target* i_pProc
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) const;

        private:
            void _init();

            /** @brief  This helper method encapsulates the details of
             *          register reads.
             *  @par    Detailed Description:
             *          Reads a register at a given scom address and
             *          provides its result via the supplied register
             *          value reference. Returns an error if unsuccesful.
             *  @param  [in] i_pProc The target processor to obtain the
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
            errlHndl_t readSecurityRegister(TARGETING::Target* i_pProc,
                                           const uint64_t i_scomAddress,
                                            uint64_t& o_regValue) const;

            /**
             *  @brief  Write a generic security related register
             *
             *  @par Detailed Description:
             *      Writes a given security register given a proc target, SCOM
             *      address, and value.
             *
             *  @param[in] i_pTarget Processor target to write.  Must be either
             *      the master processor target sentinel or valid processor
             *      target. Must not be NULL.
             *  @param[in] i_scomAddress SCOM address to write
             *  @param[in] i_data Data to write to given SCOM address
             *
             *  @return errHndl_t Error log handle indicating success or failure
             *  @retval nullptr  Wrote data to SCOM address successfully
             *  @retval !nullptr Error log providing failure details
             */
            errlHndl_t writeSecurityRegister(
                       TARGETING::Target* i_pTarget,
                       uint64_t           i_scomAddress,
                       uint64_t           i_data) const;

            /** Cached secure boot enabled value */
            bool iv_enabled;
    };
}

#endif
