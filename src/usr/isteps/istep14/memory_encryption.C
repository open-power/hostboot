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
#include <targeting/namedtarget.H>

// Misc
#include <devicefw/userif.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/isteps_trace.H>
#include <secureboot/service.H>
#include <arch/ppc.H>

// HWP
#include <p10_ncu_enable_darn.H>
#include <p10_init_mem_encryption.H>
#include <fapi2/plat_hwp_invoker.H>

using namespace TARGETING;
using namespace ERRORLOG;

/** @brief Generate a 64-bit random number with the DARN instruction.
 *
 * See the Power ISA v3.0b page 78 for documentation on the DARN ("Deliver A
 * Random Number") instruction.
 *
 * @param[out] o_random  A 64-bit random number.
 * @return errlHndl_t    Error if any, nullptr otherwise.
 */

static errlHndl_t hardware_random64(uint64_t& o_random)
{
    // The spec says that we should retry several times when DARN fails. This
    // number defines how many times we loop before failing. 10 is the spec's
    // suggested value.
    static const int NUM_RETRIES = 10;

    int fails = 0;

    while (fails < NUM_RETRIES)
    {
        o_random = darn();

        if (o_random == DARN_FAILURE)
        {
            ++fails;
        }
        else
        {
            break;
        }
    }

    errlHndl_t errl = nullptr;

    // Fail if we broke out of the above loop after failing too many times
    if (fails >= NUM_RETRIES)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"hardware_random64: DARN failed too many times");

        /* @errortype        ERRL_SEV_UNRECOVERABLE
         * @moduleid         ISTEP::MOD_PROC_EXIT_CACHE_CONTAINED
         * @reasoncode       ISTEP::RC_RNG_FAILED
         * @devdesc          RNG for memory encryption keygen failed
         * @custdesc         Hardware failure prevents memory encryption
         */
        errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            ISTEP::MOD_PROC_EXIT_CACHE_CONTAINED,
            ISTEP::RC_RNG_FAILED);
    }

    return errl;
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

/* @brief Initialize the NCU on the master core so that the DARN instruction is
 *        usable from that core.
 *
 * @param[in] i_node  The current node
 * @return errlHndl_t Error if any, otherwise nullptr
 */
static errlHndl_t initialize_master_core_ncu(Target* const i_node)
{
    errlHndl_t errl = nullptr;

    const Target* const mastercore = getMasterCore();
    assert(mastercore, "Cannot get master core");
    const Target* nx_proc = getParentChip(mastercore);
    assert(nx_proc, "Cannot get parent chip of master core");

    TargetHandleList nxs;
    getChildChiplets(nxs, nx_proc, TYPE_NX, true);

    // We prefer to use the NX from the same processor as the master core, but
    // if that NX is not functional, then we just grab any functional NX and get
    // its parent processor.
    // The minimum hardware check in host_gard will ensure that we have at least
    // one functional NX.
    if (nxs.empty())
    {
        getChildChiplets(nxs, i_node, TYPE_NX, true);
        assert(!nxs.empty(), "Cannot find any functional NX chiplets");
        nx_proc = getParentChip(nxs[0]);
        assert(nx_proc, "NX has no parent chip");
    }

    FAPI_INVOKE_HWP(errl, p10_ncu_enable_darn, { mastercore }, { nx_proc });

    if (errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"Memory encryption: initialize_master_core_ncu failed "
                  "for core 0x%08x and processor 0x%08x",
                  get_huid(mastercore),
                  get_huid(nx_proc));
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

    bool task_pinned = false;
    errlHndl_t errl = nullptr;

    /// Enable encryption and set up the encryption and decryption keys on every
    /// eligible MCC target.

    do
    {

    Target* const node = UTIL::getCurrentNodeTarget();
    TargetHandleList encrypt_mccs;
    bool enable_encryption { };

    {
        TargetHandleList procs;
        getChildAffinityTargetsByState(procs,
                                       node,
                                       CLASS_NA,
                                       TYPE_PROC,
                                       UTIL_FILTER_FUNCTIONAL);

        errl = should_enable_memory_encryption(procs, enable_encryption);

        if (errl)
        {
            break;
        }

        if (enable_encryption)
        {
            // Set up the encryption SCOMs
            Target* failproc = nullptr;
            errl = hwp_for_each(p10_init_mem_encryption, procs, &failproc);

            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Memory encryption: p10_init_mem_encryption failed on processor 0x%08x",
                          get_huid(failproc));
                break;
            }

            // Collect a list of MCCs from each PROC on this node if encryption
            // is enabled.
            getChildAffinityTargetsByState(encrypt_mccs,
                                           node,
                                           CLASS_NA,
                                           TYPE_MCC,
                                           UTIL_FILTER_FUNCTIONAL);
        }
    }

    if (!enable_encryption)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Memory encryption: Encryption disabled on node 0x%08x, not initializing keys",
                  get_huid(node));
        break;
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Memory encryption: Initializing keys for a total of %lu MCCs on node 0x%08x",
                  encrypt_mccs.size(),
                  get_huid(node));
    }

    // Set up the master core for DARN and migrate this task there so that the
    // hardware_random64 calls below work.
    errl = initialize_master_core_ncu(node);

    if (errl)
    {
        break;
    }

    task_pinned = true;
    task_affinity_pin();
    task_affinity_migrate_to_master();

    // Iterate each MCC in this node and generate a random key for each key SCOM
    // register.

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

    if (task_pinned)
    { // Affinity pinning and unpinning have to be balanced.
        task_affinity_unpin();
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Memory encryption: setup_memory_crypto_keys %s",
              errl ? "failed" : "succeeded");

    return errl;
}
