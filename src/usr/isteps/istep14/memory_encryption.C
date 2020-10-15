/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/memory_encryption.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

// Error logs
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

// Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>

// Misc
#include <devicefw/userif.H>
#include <initservice/isteps_trace.H>
#include <secureboot/service.H>

using namespace TARGETING;
using namespace ERRORLOG;

/** @brief Generate a 64-bit random number.
 *
 * @param[out] o_random  A 64-bit random number.
 * @return errlHndl_t    Error on failure, nullptr otherwise
 */
static errlHndl_t hardware_random64(uint64_t& o_random)
{
    // @TODO RTC 208820: Actually generate a random number
    o_random = 0;
    return nullptr;
}

/* @brief Determine whether memory encryption should be enabled.
 *
 * @param[in] i_procs    Processor targets to consider
 * @param[out] o_enable  True if memory encryption should be enabled on
 *                       all given processors, false otherwise.
 * @return errlHndl_t    Error if any, otherwise nullptr.
 */
static errlHndl_t should_enable_memory_encryption(TargetHandleList const i_procs,
                                                  bool& o_enable)
{
    errlHndl_t errl = nullptr;

    o_enable = true;

    // If any processor disables encryption, then we won't enable it on any
    // processor.
    for (const auto proc : i_procs)
    {
        bool encryption_export_controlled = false;

        // Check for export controls on memory encryption
        {
            // Read the Export Control Status register to check whether we're
            // allowed to use cryptography.
            const uint64_t EXPORT_REGL_STATUS_SCOM_REG = 0x10009;
            uint64_t export_ctl = 0;
            size_t export_ctl_size = sizeof(export_ctl);
            errl = deviceRead(proc,
                              &export_ctl,
                              export_ctl_size,
                              DEVICE_SCOM_ADDRESS(EXPORT_REGL_STATUS_SCOM_REG));

            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Memory encryption: Failed to read export status SCOM register");
                break;
            }

            const uint64_t EXPORT_STATUS_TP_MC_ALLOW_CRYPTO_DC = 1ull << (63 - 11);

            encryption_export_controlled = (export_ctl & EXPORT_STATUS_TP_MC_ALLOW_CRYPTO_DC) == 0;
        }

        if (encryption_export_controlled)
        {
            // Do not enable encryption if export controls are in place on any
            // processor.
            o_enable = false;
        }
        else
        {
            // If no export controls are in place, then check whether this
            // processor's attribute disables encryption.
            o_enable = o_enable && (proc->getAttr<ATTR_PROC_MEMORY_ENCRYPTION_ENABLED>()
                                    != PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED);
        }
    }

    return errl;
}

errlHndl_t lock_memory_crypto_settings()
{
    errlHndl_t errl = nullptr;

    TargetHandleList procs;
    getAllChips(procs, TYPE_PROC);
    for (const auto proc : procs)
    {
        errl = SECUREBOOT::setSecuritySwitchBits({ SECUREBOOT::ProcSecurity::MELBit,
                                                   SECUREBOOT::ProcSecurity::SKLBitW,
                                                   SECUREBOOT::ProcSecurity::SKLBitR },
                                                 proc);

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"lock_memory_crypto_settings: "
                      "Cannot set security switch bits on PROC 0x%08x",
                      get_huid(proc));

            break;
        }
    }

    return errl;
}

errlHndl_t setup_memory_crypto_keys()
{
    /// Key setup SCOM addresses
    // We don't list the CHAN1 and CHAN2 SCOMs separately here because they are
    // modeled as different targets.
    static const uint64_t MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY1A = 0x000000000C010F52ull;
    static const uint64_t MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY1B = 0x000000000C010F53ull;
    static const uint64_t MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY2A = 0x000000000C010F54ull;
    static const uint64_t MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY2B = 0x000000000C010F55ull;
    static const uint64_t MCP_CHANX_CRYPTO_ENCRYPT_CRYPTONONCEA = 0x000000000C010F56ull;
    static const uint64_t MCP_CHANX_CRYPTO_ENCRYPT_CRYPTONONCEB = 0x000000000C010F57ull;
    static const uint64_t MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY1A = 0x000000000C010F5Aull;
    static const uint64_t MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY1B = 0x000000000C010F5Bull;
    static const uint64_t MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY2A = 0x000000000C010F5Cull;
    static const uint64_t MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY2B = 0x000000000C010F5Dull;
    static const uint64_t MCP_CHANX_CRYPTO_DECRYPT_CRYPTONONCEA = 0x000000000C010F5Eull;
    static const uint64_t MCP_CHANX_CRYPTO_DECRYPT_CRYPTONONCEB = 0x000000000C010F5Full;

    // List of pairs of encrypt and decrypt registers, which need to contain the
    // same value.
    struct crypto_scom_pair_t
    {
        uint64_t encrypt_key_reg = 0,
                 decrypt_key_reg = 0,
                 mask = 0xFFFFFFFFFFFFFFFFull;
    };

    // Nonce register B is only 24 bits.
    static const uint64_t NONCE_B_MASK = 0xFFFFFF0000000000ull;

    // AES-XTS requires both keys, whereas CTR mode only requires one, but we
    // set up both in either case to support both.
    static const crypto_scom_pair_t key_scoms[] =
    {
        { MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY1A, MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY1A },
        { MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY1B, MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY1B },
        { MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY2A, MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY2A },
        { MCP_CHANX_CRYPTO_ENCRYPT_CRYPTOKEY2B, MCP_CHANX_CRYPTO_DECRYPT_CRYPTOKEY2B },
        { MCP_CHANX_CRYPTO_ENCRYPT_CRYPTONONCEA, MCP_CHANX_CRYPTO_DECRYPT_CRYPTONONCEA },
        { MCP_CHANX_CRYPTO_ENCRYPT_CRYPTONONCEB, MCP_CHANX_CRYPTO_DECRYPT_CRYPTONONCEB, NONCE_B_MASK }
    };

    errlHndl_t errl = nullptr;

    /// Set up the encryption and decryption keys on every MCC target.

    do
    {

    Target* const node = UTIL::getCurrentNodeTarget();
    TargetHandleList encrypt_mccs;

    {
        TargetHandleList procs;
        getChildAffinityTargetsByState(procs,
                                       node,
                                       CLASS_NA,
                                       TYPE_PROC,
                                       UTIL_FILTER_FUNCTIONAL);

        // Collect a list of MCCs from each PROC on this node that wants encryption.

        bool enable_encryption { };
        errl = should_enable_memory_encryption(procs, enable_encryption);

        if (errl)
        {
            break;
        }

        if (enable_encryption)
        {
            getChildAffinityTargetsByState(encrypt_mccs,
                                           node,
                                           CLASS_NA,
                                           TYPE_MCC,
                                           UTIL_FILTER_FUNCTIONAL);
        }
    }

    // Iterate each MCC in this node and generate a random key for each key SCOM
    // register.

    if (encrypt_mccs.empty())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Memory encryption: Encryption disabled on node 0x%08x, not initializing keys",
                  get_huid(node));
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Memory encryption: Initializing keys for a total of %lu MCCs on node 0x%08x",
                  encrypt_mccs.size(),
                  get_huid(node));
    }

    for (const auto mcc : encrypt_mccs)
    {
        for (const auto scom_pair : key_scoms)
        {
            uint64_t key = 0;
            errl = hardware_random64(key);

            if (errl)
            {
                break;
            }

            // Mask key and write to encryption and decryption registers
            key &= scom_pair.mask;

            uint64_t buffer = key;
            uint64_t buffersize = sizeof(buffer);
            errl = deviceWrite(mcc, &buffer, buffersize, DEVICE_SCOM_ADDRESS(scom_pair.encrypt_key_reg));

            if (errl)
            {
                break;
            }

            buffer = key;
            buffersize = sizeof(buffer);
            errl = deviceWrite(mcc, &buffer, buffersize, DEVICE_SCOM_ADDRESS(scom_pair.decrypt_key_reg));

            if (errl)
            {
                break;
            }
        }

        if (errl)
        {
            break;
        }
    }

    } while (false);

    return errl;
}
