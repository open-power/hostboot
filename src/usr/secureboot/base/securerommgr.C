/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/securerommgr.C $                      */
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
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include <sys/mmio.h>
#include <kernel/pagemgr.H>
#include <limits.h>
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include "../common/securetrace.H"
#include <kernel/bltohbdatamgr.H>
#include <errl/errludstring.H>
#include <string.h>

#include "securerommgr.H"
#include <secureboot/settings.H>
#include <config.h>
#include <console/consoleif.H>
#include <secureboot/containerheader.H>
#include "../common/errlud_secure.H"

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// Definition in ROM.H
const std::array<sbFuncType_t, SB_FUNC_TYPES::MAX_TYPES> SecRomFuncTypes =
{
    SB_FUNC_TYPES::SHA512,
    SB_FUNC_TYPES::ECDSA521
};

namespace SECUREBOOT
{

/**
 * @brief Initialize Secure Rom by loading it into memory and
 *        retrieving Hash Keys
 */
errlHndl_t initializeSecureRomManager(void)
{
    return Singleton<SecureRomManager>::instance().initialize();
}

/**
 * @brief Verify Signed Container
 */
errlHndl_t verifyContainer(void * i_container,  const RomVerifyIds& i_ids,
                           const SHA512_t* i_hwKeyHash,
                           const uint8_t i_secureVersion)
{
    errlHndl_t l_errl = nullptr;

    l_errl = Singleton<SecureRomManager>::instance().
                                       verifyContainer(i_container,
                                                       i_ids,
                                                       i_hwKeyHash,
                                                       i_secureVersion);

    return l_errl;
}

errlHndl_t verifyComponentId(
    const ContainerHeader& i_containerHeader,
    const char* const      i_pComponentId)
{
    assert(i_pComponentId != nullptr,"BUG! Component ID string was nullptr");

    errlHndl_t pError = nullptr;

    if(strncmp(i_containerHeader.componentId(),
               i_pComponentId,
               sizeof(ROM_sw_header_raw::component_id)) != 0)
    {
        char pTruncatedComponentId[sizeof(ROM_sw_header_raw::component_id)+
                                  sizeof(uint8_t)]={0};
        strncpy(pTruncatedComponentId,
                i_pComponentId,
                sizeof(ROM_sw_header_raw::component_id));

        TRACFCOMP(g_trac_secure,ERR_MRK"SECUREROM::verifyComponentId: "
            "Secure Boot verification failure; container's component ID of "
            "[%s] does not match expected component ID of [%s] (truncated "
            "from [%s])",
            i_containerHeader.componentId(),
            pTruncatedComponentId,
            i_pComponentId);

        /*@
         * @errortype
         * @severity     ERRL_SEV_UNRECOVERABLE
         * @moduleid     SECUREBOOT::MOD_SECURE_VERIFY_COMPONENT
         * @reasoncode   SECUREBOOT::RC_ROM_VERIFY
         * @devdesc      Container's component ID does not match expected
         *               component ID
         * @custdesc     Secure Boot firmware validation failed
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            SECUREBOOT::MOD_SECURE_VERIFY_COMPONENT,
            SECUREBOOT::RC_ROM_VERIFY,
            0,
            0,
            true /*Add HB Software Callout*/ );

        ERRORLOG::ErrlUserDetailsStringSet stringSet;
        stringSet.add("Actual component ID",i_containerHeader.componentId());
        stringSet.add("Expected ID (truncated)",pTruncatedComponentId);
        stringSet.add("Expected ID (full)",i_pComponentId);
        stringSet.addToLog(pError);
        pError->collectTrace(PNOR_COMP_NAME,ERROR_TRACE_SIZE);
        pError->collectTrace(SECURE_COMP_NAME,ERROR_TRACE_SIZE);
    }

    return pError;
}

/**
 * @brief Hash Signed Blob
 *
 */
void hashBlob(const void * i_blob, size_t i_size, SHA512_t o_buf)
{
    return Singleton<SecureRomManager>::instance().
                                               hashBlob(i_blob, i_size, o_buf);
}

/**
 * @brief Hash concatenation of 2 Blobs
 *
 */
void hashConcatBlobs(const blobPair_t &i_blobs, SHA512_t o_buf)
{
        return Singleton<SecureRomManager>::instance().
                                                hashConcatBlobs(i_blobs, o_buf);
}

/*
 * @brief  Externally available hardware keys' hash retrieval function
 */
void getHwKeyHash(SHA512_t o_hash)
{
    return Singleton<SecureRomManager>::instance().getHwKeyHash(o_hash);
}

/*
 * @brief  Externally available Minimum FW Secure Version retrieval function
 */
uint8_t getMinimumSecureVersion(void)
{
    return Singleton<SecureRomManager>::instance().getMinimumSecureVersion();
}


sbFuncVer_t getSecRomFuncVersion(const sbFuncType_t i_funcType)
{
    return Singleton<SecureRomManager>::instance().
                                               getSecRomFuncVersion(i_funcType);
}

uint64_t getSecRomFuncOffset(const sbFuncType_t i_funcType)
{
    return Singleton<SecureRomManager>::instance().
                                                getSecRomFuncOffset(i_funcType);
}

}; //end SECUREBOOT namespace

/********************
 Public Methods
 ********************/

// allow external methods to access g_trac_secure
using namespace SECUREBOOT;

/**
 * @brief Initialize Secure Rom by loading it into memory and
 *        getting Hash Keys
 */
errlHndl_t SecureRomManager::initialize()
{
    TRACFCOMP(g_trac_secure,ENTER_MRK"SecureRomManager::initialize()");

    errlHndl_t l_errl = nullptr;
    uint32_t l_rc = 0;

    do{
        // Check if bootloader to hostboot data is valid.
        iv_secureromValid = g_BlToHbDataManager.isValid();
        // Enforce that the securerom is valid
        if (!iv_secureromValid)
        {
            TRACFCOMP(g_trac_secure,ERR_MRK"SecureRomManager::initialize(): SecureROM invalid");
#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(SECURE_COMP_NAME, ERR_MRK"SecureROM invalid");
#endif
            printk("ERR> SecureRomManager SecureROM invalid\n");
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_SECURE_ROM_INIT
             * @reasoncode   SECUREBOOT::RC_SECROM_INVALID
             * @devdesc      Valid securerom not present
             * @custdesc     Security failure occurred during the IPL of
             *               the system.
             */
            l_errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              SECUREBOOT::MOD_SECURE_ROM_INIT,
                                              SECUREBOOT::RC_SECROM_INVALID);
            l_errl->collectTrace(SECURE_COMP_NAME,ERROR_TRACE_SIZE);
            break;
        }

        TRACFCOMP(g_trac_secure,"SecureRomManager::initialize(): SecureROM valid, enabling functionality");
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(SECURE_COMP_NAME, "SecureROM valid - enabling functionality");
#endif

        // Check to see if ROM has already been initialized
        if (iv_securerom != nullptr)
        {
            // The Secure ROM has already been initialized
            TRACUCOMP(g_trac_secure,"SecureRomManager::initialize(): Already "
                      "Loaded: iv_securerom=%p", iv_securerom);

            // Can skip the rest of this function
            break;
        }

        // ROM code starts at the end of the reserved page
        iv_securerom = g_BlToHbDataManager.getSecureRom();

        // invalidate icache to make sure that bootrom code in memory is used
        size_t l_icache_invalid_size = (g_BlToHbDataManager.getPreservedSize() /
                                        sizeof(uint64_t));

        mm_icache_invalidate(const_cast<void*>(iv_securerom),
                             l_icache_invalid_size);

        // Make this address space executable
        uint64_t l_access_type = EXECUTABLE;
        l_rc = mm_set_permission( const_cast<void*>(iv_securerom),
                                  g_BlToHbDataManager.getPreservedSize(),
                                  l_access_type);

        if (l_rc != 0)
        {
            TRACFCOMP(g_trac_secure,EXIT_MRK"SecureRomManager::initialize():"
            " Fail from mm_set_permission(EXECUTABLE): l_rc=0x%x, ptr=%p, "
            "size=0x%x, access=0x%x", l_rc, iv_securerom,
            g_BlToHbDataManager.getPreservedSize(), EXECUTABLE);

            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_SECURE_ROM_INIT
             * @reasoncode   SECUREBOOT::RC_SET_PERMISSION_FAIL_EXE
             * @userdata1    l_rc
             * @userdata2    iv_securerom
             * @devdesc      mm_set_permission(EXECUTABLE) failed for Secure ROM
             * @custdesc     A problem occurred during the IPL of the system.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   SECUREBOOT::MOD_SECURE_ROM_INIT,
                                   SECUREBOOT::RC_SET_PERMISSION_FAIL_EXE,
                                   TO_UINT64(l_rc),
                                   reinterpret_cast<uint64_t>(iv_securerom),
                                   true /*Add HB Software Callout*/ );

            l_errl->collectTrace(SECURE_COMP_NAME,ERROR_TRACE_SIZE);
            break;

        }

        /***************************************************************/
        /*  Retrieve HW Hash Keys From The System                      */
        /***************************************************************/
        SecureRomManager::getHwKeyHash();


        TRACDCOMP(g_trac_secure,INFO_MRK"SecureRomManager::initialize(): SUCCESSFUL:"
                  " iv_securerom=%p", iv_securerom);

#ifdef HOSTBOOT_DEBUG
        TRACFCOMP(g_trac_secure,">> iv_SecRomFuncTypeOffset Map");
        for (auto const &funcType : iv_SecRomFuncTypeOffset)
        {
            TRACFCOMP(g_trac_secure,">>>> Func Type = 0x%X",
                      funcType.first);
            for (auto const &version : funcType.second)
            {
                TRACFCOMP(g_trac_secure,">>>>>> Version = 0x%X, Offset = 0x%X",
                          version.first, version.second);
            }
        }
        TRACFCOMP(g_trac_secure,"<<<< iv_SecRomFuncTypeOffset map");
#endif

    }while(0);

    TRACDCOMP(g_trac_secure,EXIT_MRK"SecureRomManager::initialize() - %s",
              ((nullptr == l_errl) ? "No Error" : "With Error") );

    return l_errl;
}

/**
 * @brief Verify Container against system hash keys
 */
errlHndl_t SecureRomManager::verifyContainer(void * i_container,
                                             const RomVerifyIds& i_ids,
                                             const SHA512_t* i_hwKeyHash,
                                             const uint8_t i_secureVersion)
{
    TRACDCOMP(g_trac_secure,ENTER_MRK"SecureRomManager::verifyContainer(): "
              "i_container=%p", i_container);


    errlHndl_t  l_errl = nullptr;
    uint64_t    l_rc   = 0;

    do{

        // Check to see if ROM has already been initialized
        // This should have been done early in IPL so assert if this
        // is not the case as system is in a bad state
        assert(iv_securerom != nullptr);


        // Declare local input struct
        ROM_hw_params l_hw_parms;

        // Clear/zero-out the struct since we want 0 ('zero') values for
        // struct elements my_ecid, entry_point and log
        memset(&l_hw_parms, 0, sizeof(ROM_hw_params));

        // Now set hw_key_hash, which is of type SHA512_t, to iv_key_hash
        if (i_hwKeyHash == nullptr)
        {
            // Use current hw hash key
            memcpy (&l_hw_parms.hw_key_hash, iv_key_hash, sizeof(SHA512_t));
        }
        else
        {
            // Use custom hw hash key
            memcpy (&l_hw_parms.hw_key_hash, i_hwKeyHash, sizeof(SHA512_t));
        }

        // Set FW Secure Version
        if (i_secureVersion == INVALID_SECURE_VERSION)
        {
            // Use internal system Minimum Secure Version
            l_hw_parms.log = getMinimumSecureVersion();
        }
        else
        {
            // Use custom hw hash key
            l_hw_parms.log = i_secureVersion;
        }

        /*******************************************************************/
        /* Call ROM_verify() function via an assembly call                 */
        /*******************************************************************/

        // Set startAddr to ROM_verify() function at an offset of Secure ROM
        uint64_t l_rom_verify_startAddr =
                                reinterpret_cast<uint64_t>(iv_securerom) +
                                getSecRomFuncOffset(SB_FUNC_TYPES::ECDSA521);

        TRACUCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                  " Calling ROM_verify() via call_rom_verify: l_rc=0x%x, "
                  "l_hw_parms.log=0x%x (&l_hw_parms=%p) addr=%p (iv_d_p=%p)",
                  l_rc, l_hw_parms.log, &l_hw_parms, l_rom_verify_startAddr,
                 iv_securerom);

        ROM_container_raw* l_container = reinterpret_cast<ROM_container_raw*>(
                                                                   i_container);
        l_rc = call_rom_verify(reinterpret_cast<void*>
                               (l_rom_verify_startAddr),
                               l_container,
                               &l_hw_parms);

        TRACUCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                  "Back from ROM_verify() via call_rom_verify: l_rc=0x%x, "
                  "l_hw_parms.log=0x%x (&l_hw_parms=%p) addr=%p (iv_d_p=%p)",
                   l_rc, l_hw_parms.log, &l_hw_parms, l_rom_verify_startAddr,
                   iv_securerom);



        if (l_rc != 0)
        {
            TRACFCOMP(g_trac_secure,ERR_MRK"SecureRomManager::verifyContainer():"
            " ROM_verify() FAIL: l_rc=0x%x, l_hw_parms.log=0x%x "
            "addr=%p (iv_d_p=%p)", l_rc, l_hw_parms.log,
            l_rom_verify_startAddr, iv_securerom);

            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     SECUREBOOT::MOD_SECURE_ROM_VERIFY
             * @reasoncode   SECUREBOOT::RC_ROM_VERIFY
             * @userdata1    l_rc
             * @userdata2    l_hw_parms.log
             * @devdesc      ROM_verify() Call Failed
             * @custdesc     Failure to verify authenticity of software.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         SECUREBOOT::MOD_SECURE_ROM_VERIFY,
                                         SECUREBOOT::RC_ROM_VERIFY,
                                         l_rc,
                                         l_hw_parms.log,
                                         true /*Add HB Software Callout*/ );
            l_errl->collectTrace(PNOR_COMP_NAME);
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(UTIL_COMP_NAME);
            l_errl->collectTrace(RUNTIME_COMP_NAME);

            ContainerHeader l_conHdr;
            auto l_hdrParseErr = l_conHdr.setHeader(i_container);
            if (l_hdrParseErr)
            {
                TRACFCOMP(g_trac_secure, ERR_MRK"SecureRomManager::verifyContainer(): setheader failed");
                // Link parse error log to existing errorlog plid and commit error
                l_hdrParseErr->plid(l_errl->plid());
                ERRORLOG::errlCommit(l_hdrParseErr, RUNTIME_COMP_ID);

                // Add UD data without data needed from Container Header
                UdVerifyInfo("UNKNOWN", 0, i_ids, {}, {}, 0, 0, 0).addToLog(l_errl);
            }
            else
            {
                // Measure protected section. Note it starts one page after the
                // vaddr passed in for verification
                auto l_pProtectedSec =
                    reinterpret_cast<const uint8_t*>(i_container) + PAGESIZE;
                SHA512_t l_measuredHash = {0};
                SECUREBOOT::hashBlob(l_pProtectedSec,
                                     l_conHdr.payloadTextSize(),
                                     l_measuredHash);
                // Add UD data to errorlog
                UdVerifyInfo(l_conHdr.componentId(),
                             l_conHdr.payloadTextSize(),
                             i_ids,
                             l_measuredHash,
                             *l_conHdr.payloadTextHash(),
                             getMinimumSecureVersion(),
                             i_secureVersion,
                             l_conHdr.secureVersion()
                             ).addToLog(l_errl);

            }

            break;

        }

    }while(0);


    TRACDCOMP(g_trac_secure,EXIT_MRK"SecureRomManager::verifyContainer() - %s",
             ((nullptr == l_errl) ? "No Error" : "With Error") );

    return l_errl;
}


/**
 * @brief Hash Blob
 */
void SecureRomManager::hashBlob(const void * i_blob, size_t i_size, SHA512_t o_buf) const
{

    TRACDCOMP(g_trac_secure,INFO_MRK"SecureRomManager::hashBlob()");

    // Check to see if ROM has already been initialized
    // This should have been done early in IPL so assert if this
    // is not the case as system is in a bad state
    assert(iv_securerom != nullptr);

    // Set startAddr to ROM_SHA512() function at an offset of Secure ROM
    uint64_t l_rom_SHA512_startAddr =
                                reinterpret_cast<uint64_t>(iv_securerom) +
                                getSecRomFuncOffset(SB_FUNC_TYPES::SHA512);

    call_rom_SHA512(reinterpret_cast<void*>(l_rom_SHA512_startAddr),
                    reinterpret_cast<const sha2_byte*>(i_blob),
                    i_size,
                    reinterpret_cast<SHA512_t*>(o_buf));

    TRACUCOMP(g_trac_secure,"SecureRomManager::hashBlob(): "
              "call_rom_SHA512: blob=%p size=0x%X addr=%p (iv_d_p=%p)",
               i_blob, i_size, l_rom_SHA512_startAddr,
               iv_securerom);

    TRACDCOMP(g_trac_secure,EXIT_MRK"SecureRomManager::hashBlob()");
}

/**
 * @brief Hash concatenation of N Blobs
 */
void SecureRomManager::hashConcatBlobs(const blobPair_t &i_blobs,
                                      SHA512_t o_buf) const
{
    std::vector<uint8_t> concatBuf;
    for (const auto &it : i_blobs)
    {
        assert(it.first != nullptr, "BUG! In SecureRomManager::hashConcatBlobs(), "
            "User passed in nullptr blob pointer");
        const uint8_t* const blob =  static_cast<const uint8_t*>(it.first);
        const auto blobSize = it.second;
        concatBuf.insert(concatBuf.end(), blob, blob + blobSize);
    }

    // Call hash blob on new concatenated buffer
    hashBlob(concatBuf.data(),concatBuf.size(),o_buf);
}

/********************
 Internal Methods
 ********************/

/**
 * @brief Retrieves HW Keys from the system
 */
void SecureRomManager::getHwKeyHash()
{
    iv_key_hash  = reinterpret_cast<const SHA512_t*>(
                                           g_BlToHbDataManager.getHwKeysHash());
}

/**
 * @brief Retrieves Minimum FW Secure Version
 */
uint8_t SecureRomManager::getMinimumSecureVersion()
{
    return g_BlToHbDataManager.getMinimumSecureVersion();
}


/**
 * @brief  Retrieve the internal hardware keys' hash from secure ROM object.
 */
void SecureRomManager::getHwKeyHash(SHA512_t o_hash)
{
    memcpy(o_hash, iv_key_hash, sizeof(SHA512_t));
}

const SecureRomManager::SecRomFuncTypeOffsetMap_t
            SecureRomManager::iv_SecRomFuncTypeOffset =
{
    // SHA512 Hash Function
    { SB_FUNC_TYPES::SHA512,
        {
            { SB_FUNC_VERS::SHA512_INIT,
              g_BlToHbDataManager.getBranchtableOffset() +
                SHA512_HASH_FUNCTION_OFFSET
            }
        }
    } ,
    // ECDSA521 Verify Function
    { SB_FUNC_TYPES::ECDSA521,
        {
            { SB_FUNC_VERS::ECDSA521_INIT,
              g_BlToHbDataManager.getBranchtableOffset() +
                ROM_VERIFY_FUNCTION_OFFSET
            }
        }
    }
};

sbFuncVer_t SecureRomManager::getSecRomFuncVersion(const sbFuncType_t
                                                         i_funcType) const
{
    sbFuncVer_t l_funcVer = SB_FUNC_TYPES::SB_FUNC_TYPES_INVALID;

    switch (i_funcType)
    {
        case SB_FUNC_TYPES::SHA512:
            l_funcVer = iv_curSHA512Ver;
            break;
        case SB_FUNC_TYPES::ECDSA521:
            l_funcVer = iv_curECDSA521Ver;
            break;
        default:
            assert(false, "getCurFuncVer:: Function type 0x%X not supported", i_funcType);
            break;
    }

    return l_funcVer;
}

uint64_t SecureRomManager::getSecRomFuncOffset(const sbFuncType_t i_funcType)
                                                                           const
{
    sbFuncVer_t l_funcVer = getSecRomFuncVersion(i_funcType);

    return iv_SecRomFuncTypeOffset.at(i_funcType).at(l_funcVer);
}
