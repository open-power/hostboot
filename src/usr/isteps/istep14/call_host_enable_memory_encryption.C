/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_host_enable_memory_encryption.C $ */
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

/* @file memory_encryption.C
 *
 * @brief Implements Hostboot support for memory encryption. Support includes
 * things like cryptographic key generation and installation, encryption
 * activation, and keystore and SCOM register locking.
 */

// Error logs
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludstring.H>
#include <errl/errludtarget.H>
#include <errl/errlreasoncodes.H>

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
#include <memory>

// HWP
#include <p10_ncu_enable_darn.H>
#include <p10_init_mem_encryption.H>
#include <fapi2/plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace ISTEP;
using namespace HWAS;

/* @brief Add FFDC for a random number generation failure to an error log.
 *
 * @param[in] i_errlog  The error log to add FFDC to
 * @param[in] i_core    The core on which the DARN instruction failed
 * @param[in] i_nx      The NX the core is connected to
 */
static void addRngFFDC(const errlHndl_t i_errlog,
                       const Target* const i_core,
                       const Target* const i_nx)
{
    errlHndl_t errl = nullptr;

    // Add some FFDC about which core and NX we are using
    char msg[128] = { }; // 128 is just a generous estimate for the snprintfs below

    snprintf(msg, sizeof(msg), "Core 0x%08x is using NX 0x%08x on processor 0x%08x",
             get_huid(i_core), get_huid(i_nx), get_huid(getParentChip(i_nx)));

    ErrlUserDetailsString(msg).addToLog(i_errlog);

    // Read the L2 FIR register and get the DARN_DATA_TIMEOUT bit
    const uint64_t L2_FIR_REGISTER_SCOM_REG = 0x20028000ull;
    const uint64_t DARN_DATA_TIMEOUT_BITMASK = 1ull << (63 - 28);

    uint64_t data;
    uint64_t data_size = sizeof(data);
    errl = deviceRead(const_cast<Target*>(i_core),
                      &data,
                      data_size,
                      DEVICE_SCOM_ADDRESS(L2_FIR_REGISTER_SCOM_REG));

    if (errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "addNxFFDC: Can't read L2_FIR_REGISTER from core 0x%08x",
                  get_huid(i_core));
        errl->collectTrace(ISTEP_COMP_NAME);
        errl->plid(i_errlog->plid());
        errlCommit(errl, ISTEP_COMP_ID); // commit error and move on

        snprintf(msg, sizeof(msg), "Can't read L2_FIR register from core 0x%08x",
                 get_huid(i_core));
    }
    else
    {
        snprintf(msg, sizeof(msg), "L2_FIR[DARN_DATA_TIMEOUT] = %d",
                 (data & DARN_DATA_TIMEOUT_BITMASK) ? 1 : 0);
    }

    ErrlUserDetailsString(msg).addToLog(i_errlog);
}

/** @brief Generate a 64-bit random number with the DARN instruction.
 *
 * See the Power ISA v3.0b page 78 for documentation on the DARN ("Deliver A
 * Random Number") instruction.
 *
 * @param[in] i_core     The core we're executing on (which will run the DARN
 *                       instructions).
 * @param[in] i_proc     The NX unit connected to i_core.
 * @param[out] o_random  A 64-bit random number.
 * @return errlHndl_t    Error if any, nullptr otherwise.
 */
static errlHndl_t hardware_random64(const Target* const i_core,
                                    const Target* const i_nx,
                                    uint64_t& o_random)
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
         * @moduleid         MOD_ENABLE_MEMORY_ENCRYPTION
         * @reasoncode       RC_RNG_FAILED
         * @devdesc          RNG for memory encryption keygen failed
         * @custdesc         Hardware failure prevents memory encryption
         */
        errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            MOD_ENABLE_MEMORY_ENCRYPTION,
            RC_RNG_FAILED);

        // Deconfigure the NX, don't deconfigure the core
        errl->addHwCallout(i_nx, SRCI_PRIORITY_HIGH, DECONFIG, GARD_Fatal);
        errl->addHwCallout(i_core, SRCI_PRIORITY_MED, NO_DECONFIG, GARD_NULL);
        errl->addProcedureCallout(EPUB_PRC_HB_CODE, SRCI_PRIORITY_LOW);
        addRngFFDC(errl, i_core, i_nx);
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
                          ERR_MRK"Memory encryption: Failed to read export status SCOM register");
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

/* @brief Lock the memory encryption settings.
 *
 * This function locks the crypto settings so that cryptographic keys cannot be
 * read or written by the host from SCOM registers or the keystore SEEPROM, and
 * encryption/decryption settings cannot be disabled or modified. The lock
 * persists until the units are power-cycled.
 *
 * This function should be called after encryption has been set up and enabled.
 *
 * @return errlHndl_t  Error on failure, nullptr otherwise.
 */
static errlHndl_t lock_memory_crypto_settings()
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
 * @param[in] i_node         The current node
 * @param[out] o_activecore  The core on which DARN can be executed (always
 *                           the master core)
 * @param[out] o_activenx    The NX unit connected to o_activecore
 * @return errlHndl_t Error if any, otherwise nullptr
 */
static errlHndl_t initialize_master_core_ncu(Target* const i_node,
                                             const Target*& o_activecore,
                                             const Target*& o_activenx)
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

    o_activecore = mastercore;
    o_activenx = nxs[0];

    return errl;
}

static errlHndl_t enable_memory_encryption()
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

    /// Enable encryption and set up the encryption and decryption keys on every
    /// eligible MCC target.

    TargetHandleList encrypt_mccs;
    bool enable_encryption { };

    do
    {

    Target* const node = UTIL::getCurrentNodeTarget();

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
    const Target* activenx = nullptr, * activecore = nullptr;
    errl = initialize_master_core_ncu(node, activecore, activenx);

    if (errl)
    {
        break;
    }

    task_affinity_pin();
    task_affinity_migrate_to_master();

    // Unpin this task's affinity when this scope ends
    std::unique_ptr<void, void(*)(void*)>
        unpin_affinity(reinterpret_cast<void*>(1), // just needs to be nonzero
                       [](void*){ task_affinity_unpin(); });

    // Iterate each MCC in this node and generate a random key for each key SCOM
    // register.

    for (const auto mcc : encrypt_mccs)
    {
        for (const auto scom_pair : key_scoms)
        {
            uint64_t key = 0;
            errl = hardware_random64(activecore, activenx, key);

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

    { // Create an informational error log to report whether we enabled memory encryption
        /*@
         * @errortype         ERRL_SEV_INFORMATIONAL
         * @moduleid          MOD_ENABLE_MEMORY_ENCRYPTION
         * @reasoncode        RC_MEMORY_ENCRYPTION_ENABLED
         * @userdata1         Was memory encryption successfully enabled? (1 = yes, 0 = no)
         * @devdesc           Memory encryption was enabled for the listed MCCs
         * @custdesc          Memory encryption information
         */
        auto cryptinfo = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                       MOD_ENABLE_MEMORY_ENCRYPTION,
                                       RC_MEMORY_ENCRYPTION_ENABLED);

        if (enable_encryption && !errl)
        {
            cryptinfo->addUserData1(1); // Encryption was successfully enabled

            for (const auto mcc : encrypt_mccs)
            {
                char buf[128] = { }; // 128 is just a generous guess for the snprintf below
                snprintf(buf, sizeof(buf), "Encryption enabled on MCC 0x%08x", get_huid(mcc));
                ErrlUserDetailsString(buf).addToLog(cryptinfo);
            }
        }

        errlCommit(cryptinfo, ISTEP_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Memory encryption: setup_memory_crypto_keys %s",
              errl ? "failed" : "succeeded");

    return errl;
}

namespace ISTEP_14
{

void* call_host_enable_memory_encryption(void*)
{
    /// Enable encryption, and then lock the encryption settings.

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"call_host_enable_memory_encryption");

    ISTEP_ERROR::IStepError stepError;

    struct
    {
        errlHndl_t(*function)();
        istepReasonCode rc;
    } funcs[]
      { { enable_memory_encryption,    RC_MEMCRYPT_KEY_SETUP_FAILED },
        { lock_memory_crypto_settings, RC_MEMCRYPT_LOCK_FAILED } };

    for (const auto func : funcs)
    {
        errlHndl_t crypto_error = func.function();

        if (crypto_error)
        {
            // These are the errors that the expression below can produce:

            /* @errortype      ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_ENABLE_MEMORY_ENCRYPTION
             * @reasoncode     RC_MEMCRYPT_KEY_SETUP_FAILED
             * @devdesc        Memory encryption key setup failed
             * @custdesc       Platform security problem detected
             */

            /* @errortype      ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_ENABLE_MEMORY_ENCRYPTION
             * @reasoncode     RC_MEMCRYPT_LOCK_FAILED
             * @devdesc        Memory encryption lock failed
             * @custdesc       Platform security problem detected
             */
            auto errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                MOD_ENABLE_MEMORY_ENCRYPTION,
                func.rc);

            errl->plid(crypto_error->plid());
            errl->collectTrace(ISTEP_COMP_NAME);
            stepError.addErrorDetails(errl);

            errlCommit(crypto_error, HWPF_COMP_ID);
            errlCommit(errl, HWPF_COMP_ID);
        }

        // Continue even if we error out
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              EXIT_MRK"call_host_enable_memory_encryption");

    return stepError.getErrorHandle();
}

} // namespace ISTEP14
