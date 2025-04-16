/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/securerommgr.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2025                        */
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
#include <console/consoleif.H>
#include <secureboot/containerheader.H>
#include "../common/errlud_secure.H"

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// For SrcUserData
using namespace errl_util;

// Definition in ROM.H
const std::array<sbFuncType_t, SB_FUNC_TYPES::MAX_TYPES> SecRomFuncTypes =
{
    SB_FUNC_TYPES::SHA512,
    SB_FUNC_TYPES::ECDSA521,
    SB_FUNC_TYPES::SHA3,
    SB_FUNC_TYPES::MLDSA,
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
errlHndl_t verifyContainer(      void * i_container,
                           const RomVerifyIds& i_ids,
                           const SHA512_t* i_hwKeyHash,
                           const uint8_t i_secureVersion,
                           const ATTR_SB_SIGNING_MODE_type i_signMode)
{
    errlHndl_t l_errl = nullptr;

    l_errl = Singleton<SecureRomManager>::instance().
                                       verifyContainer(i_container,
                                                       i_ids,
                                                       i_hwKeyHash,
                                                       i_secureVersion,
                                                       i_signMode);
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
               sizeof(ROM_fw_header_raw::component_id)) != 0)
    {
        char pTruncatedComponentId[sizeof(ROM_fw_header_raw::component_id)+
                                  sizeof(uint8_t)]={0};
        strncpy(pTruncatedComponentId,
                i_pComponentId,
                sizeof(ROM_fw_header_raw::component_id));

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
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

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
void hashBlob(const void * i_blob,
                    size_t i_size,
                    SHA512_t o_buf,
              const ATTR_SB_SIGNING_MODE_type i_signMode)
{
    return Singleton<SecureRomManager>::instance().
                                               hashBlob(i_blob,
                                                        i_size,
                                                        o_buf,
                                                        i_signMode);

}

/**
 * @brief Hash concatenation of 2 Blobs
 *
 */
void hashConcatBlobs(const blobPair_t &i_blobs,
                           SHA512_t o_buf,
                     const ATTR_SB_SIGNING_MODE_type i_signMode)

{
        return Singleton<SecureRomManager>::instance().
                                                hashConcatBlobs(i_blobs,
                                                                o_buf,
                                                                i_signMode);

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
            CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, ERR_MRK"SecureROM invalid");
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
        CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, "SecureROM valid - enabling functionality");
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
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_errl->collectTrace(SECURE_COMP_NAME,ERROR_TRACE_SIZE);
            break;

        }

        // Useful for looking at SecureROM's start through its jumptabale
        TRACFBIN(g_trac_secure,"SecureRomManager::initialize(): iv_securerom",
                 const_cast<void*>(iv_securerom), 128);

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
errlHndl_t SecureRomManager::verifyContainer(      void * i_container,
                                             const RomVerifyIds& i_ids,
                                             const SHA512_t* i_hwKeyHash,
                                             const uint8_t i_secureVersion,
                                             const ATTR_SB_SIGNING_MODE_type i_signMode)
{
    TRACUCOMP(g_trac_secure,ENTER_MRK"SecureRomManager::verifyContainer(): "
              "i_container=%p, i_sv=0x%02X, i_signMode=0x%02X",
              i_container, i_secureVersion, i_signMode);

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

        // Set hw_key_hash
        if (i_hwKeyHash == nullptr)
        {
            // Use current (aka system) hw key hash
            memcpy (&l_hw_parms.hw_key_hash, iv_key_hash, sizeof(SHA512_t));
        }
        else
        {
            // Use custom hw key hash passed in by the caller
            memcpy (&l_hw_parms.hw_key_hash, i_hwKeyHash, sizeof(SHA512_t));
        }

        // Set FW Secure Version
        if (i_secureVersion == INVALID_SECURE_VERSION)
        {
            // Use system Minimum FW Secure Version
            l_hw_parms.log = getMinimumSecureVersion();
        }
        else
        {
            // Use custom Secure Version passed in by the caller
            l_hw_parms.log = i_secureVersion;
        }

        // Determine which signing mode - V1 or V3 - is going to be used below
        // based on what caller passed in
        uint8_t l_signModeToUse = 0; // default to SB_SIGNING_SYSTEM_CONTAINER
        uint8_t l_system_signing_mode = g_BlToHbDataManager.getSecurebootSigningMode();
        if (i_signMode == TARGETING::SB_SIGNING_SYSTEM_CONTAINER)
        {
            // Use system's Signing Mode
            l_signModeToUse = l_system_signing_mode;
            TRACUCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                      "Using System SB Signing Mode 0x%.2X",
                      l_signModeToUse);
        }
        else
        {
            // Use input value
            l_signModeToUse = i_signMode;
            TRACFCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                      "Using i_signMode SB Signing Mode 0x%.2X. "
                      "Ignoring system mode 0x%.2X",
                      l_signModeToUse, l_system_signing_mode);
        }

        // Now check that the header of the container passed in matches the
        // signing mode determined above
        ContainerHeader l_conHdr;
        l_errl = l_conHdr.setHeader(i_container);
        if (l_errl)
        {
            TRACFCOMP(g_trac_secure, ERR_MRK"SecureRomManager::verifyContainer(): setheader failed");

            // Add UD data without data needed from Container Header
            UdVerifyInfo("UNKNOWN", 0, i_ids, {}, {}, 0, 0, 0).addToLog(l_errl);
            break;
        }

        // Catch any mis-matched security versions here BEFORE running it through
        // the proper verification rountine below
        if ( ((l_signModeToUse == TARGETING::SB_SIGNING_V3_CONTAINER)
               && (l_conHdr.isV3() == false))
             ||
             ((l_signModeToUse == TARGETING::SB_SIGNING_V1_CONTAINER)
               && (l_conHdr.isV3() == true)))
        {
            /*@
             * @errortype
             * @severity          ERRL_SEV_UNRECOVERABLE
             * @moduleid          SECUREBOOT::MOD_SECURE_ROM_VERIFY
             * @reasoncode        SECUREBOOT::RC_BAD_MIX_OF_V1_AND_V3
             * @userdata1[00:31]  Sign Mode To Use
             * @userdata1[32:63]  Input Sign Mode
             * @userdata2         Is container header V3
             * @devdesc           Mismatch between V1 and V3 headers/signing mode
             * @custdesc          Failure to verify authenticity of software.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             SECUREBOOT::MOD_SECURE_ROM_VERIFY,
                                             SECUREBOOT::RC_BAD_MIX_OF_V1_AND_V3,
                                             SrcUserData(bits{00,31}, l_signModeToUse,
                                                         bits{31,63}, i_signMode),
                                             l_conHdr.isV3(),
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_errl->collectTrace(PNOR_COMP_NAME);
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(UTIL_COMP_NAME);
            l_errl->collectTrace(RUNTIME_COMP_NAME);

            break;
        }


        /*******************************************************************/
        /* Call ROM_verify() function via an assembly call                 */
        /*******************************************************************/

        uint64_t l_rom_verify_startAddr = 0; // Common for V1 and V3

        if (l_signModeToUse == TARGETING::SB_SIGNING_V3_CONTAINER)
        {

            // V3 verification path
// @TODO JIRA PFHB-921 Use SecureROM access when it is available
#if 0
            // Set startAddr to ROM_v3_verify() function at an offset of Secure ROM
            l_rom_verify_startAddr =
                                reinterpret_cast<uint64_t>(iv_securerom) +
                                getSecRomFuncOffset(SB_FUNC_TYPES::MLDSA);

            TRACUCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                     "Calling ROM_v3_verify() via call_rom_v3_verify: l_rc=0x%x, "
                     "l_hw_parms.log=0x%x (&l_hw_parms=%p) addr=%p (iv_d_p=%p)",
                     l_rc, l_hw_parms.log, &l_hw_parms, l_rom_verify_startAddr,
                     iv_securerom);

            ROM_v3_container_raw* l_v3_container =
                                   reinterpret_cast<ROM_v3_container_raw*>(
                                                                 i_container);

            l_rc = call_rom_v3_verify(reinterpret_cast<void*>
                                       (l_rom_verify_startAddr),
                                     l_v3_container,
                                     &l_hw_parms);

            TRACUCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                     "Back from ROM_v3_verify() via call_rom_v3_verify: l_rc=0x%x, "
                     "l_hw_parms.log=0x%x (&l_hw_parms=%p) addr=%p (iv_d_p=%p)",
                     l_rc, l_hw_parms.log, &l_hw_parms, l_rom_verify_startAddr,
                     iv_securerom);

#endif

            ROM_v3_container_raw* l_v3_container =
                                   reinterpret_cast<ROM_v3_container_raw*>(
                                                                 i_container);

            l_rc = ROM_v3_verify (l_v3_container,
                                  &l_hw_parms);

            TRACFCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                     "Back from ROM_v3_verify() via direct ROM_v3_verify: l_rc=0x%x, "
                     "l_hw_parms.log=0x%x (&l_hw_parms=%p) addr=%p (iv_d_p=%p)",
                     l_rc, l_hw_parms.log, &l_hw_parms, l_rom_verify_startAddr,
                     iv_securerom);


        }
        else
        {
            // Normal V1 verification path

            // Set startAddr to ROM_verify() function at an offset of Secure ROM
            uint64_t l_rom_verify_startAddr =
                                    reinterpret_cast<uint64_t>(iv_securerom) +
                                    getSecRomFuncOffset(SB_FUNC_TYPES::ECDSA521);

            TRACUCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                     "Calling ROM_verify() via call_rom_verify: l_rc=0x%x, "
                     "l_hw_parms.log=0x%x (&l_hw_parms=%p) addr=%p (iv_d_p=%p)",
                     l_rc, l_hw_parms.log, &l_hw_parms, l_rom_verify_startAddr,
                     iv_securerom);

            ROM_container_raw* l_container =
                                   reinterpret_cast<ROM_container_raw*>(
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
        }


#ifdef CONFIG_FSP_BUILD
        // Temporary workaround until hb_hll verification is resolved
        // If there is a V3 verification fail in a FSP-environment, this workaround will
        // termpoarily set the l_rc to 0 to bypass the fail under the following condition:
        // - the driver on the system is a lab/imprint/dev (aka non-production) driver
        //   - the presence of the security backdoor will be used to verify this is
        //     lab/imprint/dev driver
        if((l_rc != 0) // verification fail
            && (l_signModeToUse == TARGETING::SB_SIGNING_V3_CONTAINER) // running in V3 signing mode
            && (SECUREBOOT::getSbeSecurityBackdoor())  // it's a lab/imprint/dev driver
            && (INITSERVICE::spBaseServicesEnabled())) // confirming this is running on a FSP-based system
        {
            TRACFCOMP(g_trac_secure,"SecureRomManager::verifyContainer(): "
                     "ROM_verify() failed in V3 signing mode (%d), with an imprint (%d) "
                     "driver on a FSP (%d) system: l_rc=0x%x. Temporarily ignoring this "
                     "error by setting l_rc to 0",
                     l_rc, l_signModeToUse, SECUREBOOT::getSbeSecurityBackdoor,
                     INITSERVICE::spBaseServicesEnabled());
            l_rc = 0;
        }



// End of workaround
#endif

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
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
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
                // Measure protected section. This section starts after the
                // container's header, which is what i_container points to.
                // There are different headers sizes based on the container's
                // version.
                size_t l_contHdrSize = (l_signModeToUse
                                        == TARGETING::SB_SIGNING_V3_CONTAINER)
                                           ? V3_SECURE_HEADER_SIZE
                                           : PAGESIZE;

                auto l_pProtectedSec =
                    reinterpret_cast<const uint8_t*>(i_container)
                                                     + l_contHdrSize;
                SHA512_t l_measuredHash = {0};
                SECUREBOOT::hashBlob(l_pProtectedSec,
                                     l_conHdr.payloadTextSize(),
                                     l_measuredHash,
                                     l_signModeToUse);

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
void SecureRomManager::hashBlob(const void * i_blob,
                                      size_t i_size,
                                      SHA512_t o_buf,
                                const ATTR_SB_SIGNING_MODE_type i_signMode) const
{

    TRACDCOMP(g_trac_secure,INFO_MRK"SecureRomManager::hashBlob()");

    // Check to see if ROM has already been initialized
    // This should have been done early in IPL so assert if this
    // is not the case as system is in a bad state
    assert(iv_securerom != nullptr);

    assert((i_signMode == SB_SIGNING_V1_CONTAINER)
           || (i_signMode == SB_SIGNING_V3_CONTAINER)
           || (i_signMode == SB_SIGNING_SYSTEM_CONTAINER),
           "SecureRomManager::hashBlob: invalid i_signMode=%d!",
           i_signMode);

    auto l_signModeToUse = 0;
    if (i_signMode == SB_SIGNING_SYSTEM_CONTAINER)
    {
        // get system signing mode
        l_signModeToUse = SECUREBOOT::hashSignMode();
    }
    else
    {
        // Must be V1 or V3 based on assert and if-check above
        l_signModeToUse = i_signMode;
    }

    if (l_signModeToUse == SB_SIGNING_V1_CONTAINER)
    {
        // V1
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
    }
    else
    {
        // V3

        // @TODO JIRA PFHB-921 Until securerom's call_rom_SHA3() function is
        // working, call the linked sha3() function directly below

        // Set startAddr to ROM_SHA3() function at an offset of Secure ROM
        //uint64_t l_rom_SHA3_startAddr =
        //                        reinterpret_cast<uint64_t>(iv_securerom) +
        //                        getSecRomFuncOffset(SB_FUNC_TYPES::SHA3);

        //call_rom_SHA3(reinterpret_cast<void*>(l_rom_SHA3_startAddr),
        //                i_blob,
        //                i_size,
        //                reinterpret_cast<sha3_t*>(o_buf));
        sha3(i_blob, i_size, reinterpret_cast<void*>(o_buf));

        TRACUCOMP(g_trac_secure,"SecureRomManager::hashBlob(): "
                  "call_rom_SHA3: blob=%p size=0x%X addr=%p (iv_d_p=%p)",
                   i_blob, i_size, l_rom_SHA3_startAddr,
                   iv_securerom);
    }
}

/**
 * @brief Hash concatenation of N Blobs
 */
void SecureRomManager::hashConcatBlobs(const blobPair_t &i_blobs,
                                             SHA512_t o_buf,
                                       const ATTR_SB_SIGNING_MODE_type i_signMode) const
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
    hashBlob(concatBuf.data(),concatBuf.size(),o_buf, i_signMode);
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
                                           g_BlToHbDataManager.getHwKeysHashPtr());
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

/**
 * @brief  Fill out these sections so they can be put into HDAT
 */
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
    } ,
    // SHA53 Hash Function
    { SB_FUNC_TYPES::SHA3,
        {
            { SB_FUNC_VERS::SHA3_INIT,
              g_BlToHbDataManager.getBranchtableOffset() +
                SHA3_HASH_FUNCTION_OFFSET
            }
        }
    } ,
    // MLDSA Verify Function
    { SB_FUNC_TYPES::MLDSA,
        {
            { SB_FUNC_VERS::MLDSA_INIT,
              g_BlToHbDataManager.getBranchtableOffset() +
                ROM_V3_VERIFY_FUNCTION_OFFSET
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
        case SB_FUNC_TYPES::SHA3:
            l_funcVer = iv_curSHA3Ver;
            break;
        case SB_FUNC_TYPES::MLDSA:
            l_funcVer = iv_curMLDSAVer;
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
