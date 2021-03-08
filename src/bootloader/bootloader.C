/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bootloader.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

/**
 * @file bootloader.C
 *
 * @brief Bootloader main() function and various helper functions
 */

#define __BOOT_LOADER_C

#include <stdint.h>
#include <bootloader/bootloader.H>
#include <bootloader/bootloader_trace.H>
#include <bootloader/hbblreasoncodes.H>
#include <bootloader/bl_pnorAccess.H>
#include <bootloader/bootloaderif.H>
#include <bootloader/bl_console.H>
#include <bootloader/bl_xscom.H>

#include <lpc_const.H>
#include <pnor_utils.H>
#include <arch/pvrformat.H>
#include <arch/ppc.H>

#include <ecc.H>

#include <stdlib.h>
#include <util/align.H>
#include <string.h>
#include <limits.h>
#include <math.h>

#include <securerom/ROM.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/settings_common.H>
#include <p10_sbe_hb_structures.H>

#include <pnor/pnorif.H>
#include <kernel/memstate.H>

#include <p10_sbe_spi_cmd.H>
#include <bl_tpm_spidd.H>

using namespace MEMMAP;

extern char bootloader_end_address;

// XSCOM/LPC BAR constants
const uint64_t XSCOM_BAR_MASK = 0xFF000003FFFFFFFFULL;
const uint64_t LPC_BAR_MASK = 0xFF000000FFFFFFFFULL;

namespace Bootloader{

    /**
     * @brief Set Secureboot Config Data structure so it is accessible via
     *        Hostboot code
     *
     * @param[in] i_hbbSrc  Void pointer to effective address of HBB image
     *                      inlcuding the header. Must not be NULL
     *
     * @return N/A
     */
    void setSecureData(const void * i_pHbbSrc)
    {
        // Create BlToHbData

        // Read SBE HB shared data.
        const BootloaderConfigData_t* l_blConfigData =
            reinterpret_cast<BootloaderConfigData_t *>(SBE_HB_COMM_ADDR);

        // Set Secure Settings
        // Ensure SBE to Bootloader structure has the SAB member
        //   and other Secure Settings
        g_blData->blToHbData.secureAccessBit =
            l_blConfigData->secureSettings.secureAccessBit;
        g_blData->blToHbData.securityOverride =
            l_blConfigData->secureSettings.securityOverride;
        g_blData->blToHbData.allowAttrOverrides =
            l_blConfigData->secureSettings.allowAttrOverrides;
        g_blData->blToHbData.secBackdoorBit =
            l_blConfigData->secureSettings.secBackdoorBit;

        // Find secure ROM addr
        // Get starting address of ROM size and code which is the next 8 byte
        // aligned address after the bootloader end.
        // [hbbl][pad:8:if-applicable][securerom-size:8][securerom]
        const void * l_pBootloaderEnd = &bootloader_end_address;
        uint64_t l_bootloaderSize = 0;
        memcpy (&l_bootloaderSize, l_pBootloaderEnd, sizeof(l_bootloaderSize));
        const uint8_t* l_pRomStart = reinterpret_cast<uint8_t *>(
                                        getHRMOR() + ALIGN_8(l_bootloaderSize));

        // Set Rom Size
        memcpy (&g_blData->blToHbData.secureRomSize,
                l_pRomStart,
                sizeof(g_blData->blToHbData.secureRomSize));
        l_pRomStart += sizeof(g_blData->blToHbData.secureRomSize);

        // Get Secure ROM info
        const auto l_pSecRomInfo = reinterpret_cast<const SecureRomInfo*>(
                                                                   l_pRomStart);

        // Translate SBE to BL version into BL to HB version
        switch(l_blConfigData->version)
        {
            // Add cases as additional versions are created
            case SB_SETTING:
                g_blData->blToHbData.version = BLTOHB_SB_SETTING;
                break;

            // @TODO RTC 269616 - Remove INIT and make SB_SETTING default
            case INIT:
            default:
                g_blData->blToHbData.version = BLTOHB_INIT;
                break;
        }

        // Copy values for MMIO BARs
        g_blData->blToHbData.xscomBAR =
            ((l_blConfigData->xscomBAR & XSCOM_BAR_MASK) == 0) ?
                l_blConfigData->xscomBAR :
                MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR;

        /* lpcBAR already copied in main() */

        // Only set rest of BlToHbData if SecureROM is valid
        if ( secureRomInfoValid(l_pSecRomInfo) )
        {
            // Store valid check local to bootloader, as another validation
            // is required in code outside the bootloader.
            g_blData->secureRomValid = true;

            g_blData->blToHbData.eyeCatch = BLTOHB_EYECATCHER;
            g_blData->blToHbData.branchtableOffset =
                                               l_pSecRomInfo->branchtableOffset;
            g_blData->blToHbData.secureRom = l_pRomStart;

            // Set data size of HW key hash
            g_blData->blToHbData.hwKeysHashSize = SHA512_DIGEST_LENGTH;

            // @TODO RTC 269616 - Remove if{} section and keep else{} section
            if (g_blData->blToHbData.version < BLTOHB_SB_SETTING)
            {
                // Use default imprint hash for versions withoout .sb_setting SBE section
                g_blData->blToHbData.hwKeysHashPtr = default_hw_key_hash;

                // Set Minimum FW Secure Version
                // Use default of 0 for early version of SBE code
                g_blData->blToHbData.min_secure_version = 0;

                // Set Measurement Seeprom Version
                // Use default of 0 for early version of SBE code
                g_blData->blToHbData.measurement_seeprom_version = 0;
            }
            else
            {
                // Get HW Keys' Hash Ptr
                g_blData->blToHbData.hwKeysHashPtr = &l_blConfigData->sbSettings.hwKeyHash[0];

                // Get Minimum Secure Version
                g_blData->blToHbData.min_secure_version = l_blConfigData->sbSettings.msv;

                // Get Measurement Seeprom Version
                g_blData->blToHbData.measurement_seeprom_version =
                    l_blConfigData->mSeepromVersion;
            }

            // Set HBB header and size
            g_blData->blToHbData.hbbHeader = i_pHbbSrc;
            g_blData->blToHbData.hbbHeaderSize = PAGE_SIZE;

            // Set Bootloader preceived size of structure
            g_blData->blToHbData.sizeOfStructure = sizeof(BlToHbData);
        }
    }

    void setKeyAddrMapData(const void * i_pHbbSrc)
    {
        // Read SBE HB shared data.
        const auto l_blConfigData = reinterpret_cast<BootloaderConfigData_t *>(
                                                              SBE_HB_COMM_ADDR);
        // Set copy keyaddr stash data
        memcpy(&g_blData->blToHbData.keyAddrStashData,
               &l_blConfigData->pair,
               (l_blConfigData->numKeyAddrPair * sizeof(keyAddrPair_t)));

        g_blData->blToHbData.numKeyAddrPair = l_blConfigData->numKeyAddrPair;
    }

    void copyBlToHbtoHbLocation()
    {
        // Place BlToHb into proper location for HB to find
        memcpy(reinterpret_cast<void *>(BLTOHB_COMM_DATA_ADDR_LATEST |
                                        IGNORE_HRMOR_MASK),
                &g_blData->blToHbData,
                sizeof(BlToHbData));
    }

    /**
     *  @brief Verify container's component ID against a reference
     *     component ID. Up to 8 ASCII characters, not including NULL, will be
     *     compared (thus, it is critical that all components are unique with
     *     respect to the first 8 bytes).
     *
     *  @param[in] i_pHeader Void pointer to start of the container's secure
     *      header.  Must not be nullptr.
     *  @param[in] i_pComponentId Reference component ID to compare to.  Must
     *      not be nullptr.
     */
    void verifyComponentId(
        const void* const i_pHeader,
        const char* const i_pComponentId)
    {

        const auto* const pHwPrefix =
            reinterpret_cast<const ROM_prefix_header_raw* const>(
                  reinterpret_cast<const uint8_t* const>(i_pHeader)
                + offsetof(ROM_container_raw,prefix));
        const auto swKeyCount = pHwPrefix->sw_key_count;
        const auto ecidCount = pHwPrefix->ecid_count;

        const char* const pCompIdInContainer =
              reinterpret_cast<const char* const>(i_pHeader)
            + offsetof(ROM_container_raw,prefix)
            + offsetof(ROM_prefix_header_raw,ecid)
            + ecidCount*ECID_SIZE
            + offsetof(ROM_prefix_data_raw,sw_pkey_p)
            + swKeyCount*sizeof(ecc_key_t)
            + offsetof(ROM_sw_header_raw,component_id);

        if(strncmp(pCompIdInContainer,
                   i_pComponentId,
                   sizeof(ROM_sw_header_raw::component_id)) != 0)
        {
            char pTruncatedComponentId[
                  sizeof(ROM_sw_header_raw::component_id)
                + sizeof(uint8_t)]={0};
            strncpy(pTruncatedComponentId,
                    i_pComponentId,
                    sizeof(ROM_sw_header_raw::component_id));

            BOOTLOADER_TRACE(BTLDR_TRC_COMP_ID_VERIFY_FAILED);

            // Read SBE HB shared data
            const auto pBlConfigData = reinterpret_cast<
                BootloaderConfigData_t *>(SBE_HB_COMM_ADDR);

            /*@
             * @errortype
             * @moduleid         Bootloader::MOD_BOOTLOADER_VERIFY_COMP_ID
             * @reasoncode       SECUREBOOT::RC_ROM_VERIFY
             * @userdata1[0:15]  TI_WITH_SRC
             * @userdata1[16:31] TI_BOOTLOADER
             * @userdata1[32:63] Failing address = 0
             * @userdata2[0:31]  First 4 bytes of observed component ID
             * @userdata2[32:63] Last 4 bytes of observed component ID
             * @errorInfo[0:15]  SBE boot side
             * @errorInfo[16:31] Unused
             * @devdesc          Container component ID verification failed.
             * @custdesc         Platform security violation detected
             */
            bl_terminate(
                MOD_BOOTLOADER_VERIFY_COMP_ID,
                SECUREBOOT::RC_ROM_VERIFY,
                *reinterpret_cast<const uint32_t*>(
                   pCompIdInContainer),
                *reinterpret_cast<const uint32_t*>(
                   pCompIdInContainer+sizeof(uint32_t)),
                true,
                0,
                TWO_UINT16_TO_UINT32(
                    pBlConfigData->sbeBootSide,0));
        }
        else
        {
            BOOTLOADER_TRACE(BTLDR_TRC_COMP_ID_VERIFY_SUCCESS);
        }
    }

    /**
     * @brief Verify Container against system hash keys
     *
     * @param[in] i_pContainer  Void pointer to effective address
     *                          of container
     * NOTE : no-op if Config Secureboot not enabled.
     *
     * @return N/A
     */
    void verifyContainer(const void * i_pContainer)
    {
        BOOTLOADER_TRACE(BTLDR_TRC_MAIN_VERIFY_START);

        uint64_t l_rc = 0;

        // Check if Secure Access Bit is set
        if (!g_blData->blToHbData.secureAccessBit)
        {
            BOOTLOADER_TRACE(BTLDR_TRC_MAIN_VERIFY_SAB_UNSET);
        }
        // Terminate if a valid securerom is not present
        else if ( !g_blData->secureRomValid )
        {
            BOOTLOADER_TRACE(BTLDR_TRC_MAIN_VERIFY_INVALID_SECROM);
            /*@
             * @errortype
             * @moduleid     Bootloader::MOD_BOOTLOADER_VERIFY
             * @reasoncode   SECUREBOOT::RC_SECROM_INVALID
             * @userdata1[0:15]   TI_WITH_SRC
             * @userdata1[16:31]  TI_BOOTLOADER
             * @userdata1[32:63]  Failing address = 0
             * @devdesc      Valid securerom not present
             * @custdesc     Security failure occurred while running processor
             *               boot code.
             */
            bl_terminate(Bootloader::MOD_BOOTLOADER_VERIFY,
                         SECUREBOOT::RC_SECROM_INVALID);
        }
        else
        {
            bl_console::putString("Validating boot firmware\r\n");
            // Set startAddr to ROM_verify() function at an offset of Secure ROM
            uint64_t l_rom_verify_startAddr =
                reinterpret_cast<const uint64_t>(g_blData->blToHbData.secureRom)
                + g_blData->blToHbData.branchtableOffset
                + ROM_VERIFY_FUNCTION_OFFSET;

            // Declare local input struct
            ROM_hw_params l_hw_parms;

            // Clear/zero-out the struct since we want 0 ('zero') values for
            // struct elements my_ecid, entry_point and log
            uint8_t *p_hw_parms = reinterpret_cast<uint8_t *>(&l_hw_parms);
            for(uint8_t i = 0; i < sizeof(ROM_hw_params); p_hw_parms[i++] = 0){}

            // Use current hw hash key
            memcpy (&l_hw_parms.hw_key_hash, g_blData->blToHbData.hwKeysHashPtr,
                    sizeof(SHA512_t));

            // Use current minimum FW secure version
            l_hw_parms.log = g_blData->blToHbData.min_secure_version;

            const auto l_container = reinterpret_cast<const ROM_container_raw*>
                                                                 (i_pContainer);

            l_rc = call_rom_verify(reinterpret_cast<void*>
                                   (l_rom_verify_startAddr),
                                   l_container,
                                   &l_hw_parms);
            if (l_rc != 0)
            {
                // Get first 4 bytes of Container that failed verification
                uint32_t l_beginContainer = 0;
                memcpy(&l_beginContainer, i_pContainer,
                       sizeof(l_beginContainer));

                // Get first 4 bytes of system's hw keys' hash
                uint32_t l_beginHwKeysHash = 0;
                memcpy(&l_beginHwKeysHash, g_blData->blToHbData.hwKeysHashPtr,
                       sizeof(l_beginHwKeysHash));

                // Read SBE HB shared data.
                const auto l_blConfigData = reinterpret_cast<
                                    BootloaderConfigData_t *>(SBE_HB_COMM_ADDR);

                // Verification of Container failed.
                BOOTLOADER_TRACE(BTLDR_TRC_MAIN_VERIFY_FAIL);
                /*@
                 * @errortype
                 * @moduleid     Bootloader::MOD_BOOTLOADER_VERIFY
                 * @reasoncode   SECUREBOOT::RC_ROM_VERIFY
                 * @userdata1[0:15]   TI_WITH_SRC
                 * @userdata1[16:31]  TI_BOOTLOADER
                 * @userdata1[32:63]  Failing address = 0
                 * @userdata2[0:31]   First 4 bytes System's HW keys' Hash
                 * @userdata2[32:63]  First 4 bytes of Container Header
                 * @errorInfo[0:15]   SBE Boot Side
                 * @errorInfo[16:31]  ROM_hw_params log
                 * @devdesc      ROM verification failed
                 * @custdesc     Platform security violation detected
                 */
                bl_terminate(MOD_BOOTLOADER_VERIFY,
                             SECUREBOOT::RC_ROM_VERIFY,
                             l_beginHwKeysHash,
                             l_beginContainer,
                             true,
                             0,
                             TWO_UINT16_TO_UINT32(l_blConfigData->sbeBootSide,
                                                  l_hw_parms.log));

            }

            BOOTLOADER_TRACE(BTLDR_TRC_MAIN_VERIFY_SUCCESS);
            verifyComponentId(i_pContainer,
                            PNOR::SectionIdToString(PNOR::HB_BASE_CODE));
        }
    }

#ifndef CONFIG_VPO_COMPILE
    /**
     * @brief Sets the TDP (TPM Deconfig Protect) bit in the secure register
     */
    void setTpmTdpBit()
    {
        uint64_t l_data = SECUREBOOT::ProcSecurity::TDPBit;
        size_t l_buflen = sizeof(l_data);

        // Set the TPM TDP bit in the secure reg
        Bootloader::hbblReasonCode l_rc = XSCOM::xscomPerformOp(DeviceFW::WRITE,
                                                                &l_data,
                                                                l_buflen,
                                                                SECUREBOOT::ProcSecurity::SwitchRegister);
        if(l_rc)
        {
            bl_console::putString("Could not write to secure register. XSCOM RC: ");
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_rc), sizeof(l_rc));
            bl_console::putString("\r\n");
        }
    }

    /**
     * @brief Reads the secure register and returns the value of the TDP (TPM Deconfigure Protect) bit
     *
     * @return The value of the TDP bit
     */
    bool getTpmTdpBit()
    {
        bool l_bitSet = false;

        uint64_t l_buffer = 0;
        size_t l_buflen = sizeof(l_buffer);
        Bootloader::hbblReasonCode l_rc = XSCOM::xscomPerformOp(DeviceFW::READ,
                                                                &l_buffer,
                                                                l_buflen,
                                                                SECUREBOOT::ProcSecurity::SwitchRegister);
        if(l_rc)
        {
            bl_console::putString("Could not read secure register. XSCOM RC: ");
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_rc), sizeof(l_rc));
            bl_console::putString("\r\n");
        }
        else
        {
            l_bitSet = l_buffer & SECUREBOOT::ProcSecurity::TDPBit;
        }

        return l_bitSet;
    }

    /**
     * @brief Initialize the TPM and extend the given hash to TPM PCR0
     *
     * @param[in] i_hash the hash to be extended to TPM PCR0. Needs to be at least
     *            32 bytes long.
     * @return 0 on success or error code on failure
     */
    static Bootloader::hbblReasonCode extendHashToTPM(const uint8_t* const i_hash)
    {
        Bootloader::hbblReasonCode l_rc = RC_NO_ERROR;
        do {

        // If the TDP bit is set, then SBE had detected a problem with the TPM and we shouldn't
        // be attempting any TPM ops.
        if(getTpmTdpBit())
        {
            bl_console::putString("TPM TDP Bit set; will not perform TPM ops\r\n");
            break;
        }

        // First, initialize the TPM SPI engine so we can communicate with TPM
        l_rc = tpm_init_spi_engine();
        if(l_rc)
        {
            bl_console::putString("Could not init TPM SPI engine clock! RC: ");
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_rc), sizeof(l_rc));
            bl_console::putString("\r\n");
            break;
        }

        // Set the TPM locality to 0
        uint8_t l_locality = TPMDD::TPM_ACCESS_REQUEST_LOCALITY_USE;
        size_t l_size = sizeof(l_locality);
        l_rc = tpm_write(TPMDD::TPM_REG_75x_TPM_ACCESS, &l_locality, l_size);
        if(l_rc)
        {
            bl_console::putString("Could not set TPM locality\r\n");
            break;
        }

        // Start the TPM
        l_rc = tpmCmdStartup();
        if(l_rc)
        {
            bl_console::putString("TPM init FAILED; RC: 0x");
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_rc), sizeof(l_rc));
            bl_console::putString("\r\n");
            break;
        }

        // Extend the input hash to TPM PCR0
        l_rc = tpmExtendHash(i_hash);
        if(l_rc)
        {
            bl_console::putString("Could not extend hash! RC: ");
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_rc), sizeof(l_rc));
            bl_console::putString("\r\n");
            break;
        }

        } while(0);

        if(l_rc)
        {
            bl_console::putString("Setting the TPM TDP bit\r\n");
            // Set the TPM TDP bit if any TPM op fails
            setTpmTdpBit();
            g_blData->blToHbData.tdpFlagSet = 1;
        }

        return l_rc;
    }
#endif

    /** Bootloader main function to work with and start HBB.
     *
     * @return 0.
     *
     * @note Should branch to HBB and never return.
     */
    extern "C"
    int main()
    {
        // Initialization
        g_blData->bl_trace_index = 0;
        g_blData->bl_trace_index_saved = BOOTLOADER_TRACE_SIZE;
        BOOTLOADER_TRACE(BTLDR_TRC_MAIN_START);

        //Set core scratch 3 to say bootloader is active
        //"bootload" = 0x626F6F746C6F6164 in ascii
        uint64_t hostboot_string = 0x626F6F746C6F6164;
        writeScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE, hostboot_string);

        //Set core scratch 1 to the eventual HRMOR of Hostboot
        // and the space SBE calculated for hostboot.  The HRMOR spoofing is
        // required in order for FSP code to be able to find the TI area without
        // having to know exactly where we are in the boot flow.
        // See _updates_and_setup in bl_start.S for where we put
        // our TI area below our actual HRMOR.  The size driven by SBE will
        // allow a dump to grab all of our working data along with
        // our actual image.
        KernelMemState::MemState_t l_memstate;
        l_memstate.location = KernelMemState::MEM_CONTAINED_L3;
        l_memstate.hrmor = (HBB_RUNNING_ADDR);

        // Copy SBE BL shared data into BL HB shared data
        const auto l_blConfigData = reinterpret_cast<BootloaderConfigData_t *>(
                                                              SBE_HB_COMM_ADDR);
        g_blData->blToHbData.lpcBAR
            = ((l_blConfigData->lpcBAR & LPC_BAR_MASK) == 0)
            ? l_blConfigData->lpcBAR
            : MMIO_GROUP0_CHIP0_LPC_BASE_ADDR;

#ifndef CONFIG_VPO_COMPILE
        g_blData->blToHbData.cacheSizeMb = l_blConfigData->cacheSizeMB;
#else  //The cache size is fixed to 4MB in VPO
        g_blData->blToHbData.cacheSizeMb = 4;
#endif

        writeScratchReg(MMIO_SCRATCH_MEMORY_STATE, l_memstate.fullData);

        bl_console::init();

        // start of istep 6.1
        bl_console::putString("\ristep6.1\r\n");

#ifndef CONFIG_VPO_COMPILE // We don't want to make any LPC PNOR accesses in VPO
                           // HBB will be manually pre-loaded into the memory
        //We dont know what the start of pnor is because we dont know the size
        uint64_t l_pnorStart = 0;

        uint32_t l_errCode = PNOR::NO_ERROR;
        g_blData->secureRomValid = false;

        // Get location of HB base code in PNOR from TOC
        // @TODO RTC:138268 Support multiple sides of PNOR in bootloader
        bl_console::putString("Loading boot firmware\r\n");
        bl_pnorAccess::getHBBSection(g_blData->blToHbData.lpcBAR,
                                     g_blData->bl_hbbSection,
                                     l_errCode,
                                     l_pnorStart);

        if(PNOR::NO_ERROR == l_errCode)
        {
            // get hbbFlashOffset
            uint64_t l_hbbFlashOffset = g_blData->bl_hbbSection.flashAddr;
            // get hbbLength without size of ECC data
            uint32_t l_hbbLength = g_blData->bl_hbbSection.size;
            // get hbbEcc
            bool l_hbbEcc =
                ( g_blData->bl_hbbSection.integrity == FFS_INTEG_ECC_PROTECT);

            uint32_t workingLength= (l_hbbEcc) ?
                (l_hbbLength * LENGTH_W_ECC)/LENGTH_WO_ECC : l_hbbLength;

            // handleMMIO below always moves WORDSIZE chunks at a time, even
            // if there is just one byte left, so subtract WORDSIZE from the
            // limit to compensate
            if(workingLength > (MEGABYTE-WORDSIZE))
            {
                BOOTLOADER_TRACE(BTLDR_TRC_BAD_WORK_LEN);
                /*@
                 * @errortype
                 * @moduleid         Bootloader::MOD_BOOTLOADER_MAIN
                 * @reasoncode       Bootloader::RC_BAD_WORK_LEN
                 * @userdata1[0:15]  TI_WITH_SRC
                 * @userdata1[16:31] TI_BOOTLOADER
                 * @userdata1[32:63] Failing address = 0
                 * @userdata2[0:31]  Length of data from TOC (bytes)
                 * @userdata2[32:63] Working length (bytes)
                 * @errorInfo[0:31]  Max space available (bytes)
                 * @devdesc  Not enough memory to load boot firmware
                 * @custdesc Failed to load boot firmware
                 */
                bl_terminate(
                    MOD_BOOTLOADER_MAIN,
                    RC_BAD_WORK_LEN,
                    l_hbbLength,
                    workingLength,
                    true,
                    0,
                    (MEGABYTE-WORDSIZE));
            }

            // Copy HB base code from PNOR to working location
            handleMMIO((l_pnorStart + l_hbbFlashOffset),
                       ((l_hbbEcc) ? HBB_ECC_WORKING_ADDR : HBB_WORKING_ADDR),
                       workingLength,
                       WORDSIZE,
                       READ);
            BOOTLOADER_TRACE(BTLDR_TRC_MAIN_WORKING_HANDLEMMIO_RTN);

            PNOR::ECC::eccStatus rc = PNOR::ECC::CLEAN;
            if(l_hbbEcc)
            {
                // Remove ECC from HB base code at working location and
                // store result in new working location
                rc = PNOR::ECC::removeECC(
                    reinterpret_cast<uint8_t*>(HBB_ECC_WORKING_ADDR |
                                               IGNORE_HRMOR_MASK),
                    reinterpret_cast<uint8_t*>(HBB_WORKING_ADDR |
                                               IGNORE_HRMOR_MASK),
                    l_hbbLength);
                if (rc != PNOR::ECC::CLEAN)
                {
                    BOOTLOADER_TRACE(BTLDR_TRC_MAIN_REMOVEECC_RTN);
                }
                else if (rc != PNOR::ECC::CORRECTED)
                {
                    BOOTLOADER_TRACE(BTLDR_TRC_MAIN_REMOVEECC_CORRECTED);
                }
            }

            if (rc != PNOR::ECC::UNCORRECTABLE)
            {
#else //VPO_COMPILE
                // Since we're not reading HBB from PNOR, and can't get the real
                // size of HBB, hardcode the size to the maximum it can be
                uint32_t l_hbbLength = 904 * KILOBYTE;
#endif
                uint64_t *l_src_addr =
                   reinterpret_cast<uint64_t*>(HBB_WORKING_ADDR |
                                               IGNORE_HRMOR_MASK);

                uint64_t *l_dest_addr =
                   reinterpret_cast<uint64_t*>(HBB_RUNNING_ADDR |
                                               IGNORE_HRMOR_MASK);

                // Get Secure Data from SBE HBBL communication area
                setSecureData(l_src_addr);

                // Get Key-Addr Mapping from SBE HBBL communication area
                setKeyAddrMapData(l_src_addr);

                copyBlToHbtoHbLocation();

#ifndef CONFIG_VPO_COMPILE // No secureboot in VPO - no need to verify
                // ROM verification of HBB image
                verifyContainer(l_src_addr);

#ifdef CONFIG_TPMDD
                // Grab the HBB content signature hash out of the secureboot
                // header and extended into TPM

                // Current offset of the hash of protected payload into the
                // secure header
                const uint16_t CONTENT_HASH_OFFSET = 1085;
                uint8_t* l_hash = reinterpret_cast<uint8_t*>(l_src_addr) +
                                  CONTENT_HASH_OFFSET;

                // Extend the obtained hash into TPM
                Bootloader::hbblReasonCode l_rc = extendHashToTPM(l_hash);
                if(l_rc)
                {
                    bl_console::putString("Could not extend HBB hash to TPM. RC: ");
                    bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_rc), sizeof(l_rc));
                    bl_console::putString("\r\n");
                    bl_console::putString("Continuing the boot.\r\n");
                    l_rc = Bootloader::RC_NO_ERROR;
                }
#endif // CONFIG_TPMDD

                // Increment past secure header
                if (isEnforcedSecureSection(PNOR::HB_BASE_CODE))
                {
                    l_src_addr += PAGE_SIZE/sizeof(uint64_t);
                    l_hbbLength -= PAGE_SIZE;
                }

#endif // CONFIG_VPO_COMPILE

                // Copy HBB image into address where it executes
                for(uint32_t i = 0;
                    i < l_hbbLength / sizeof(uint64_t);
                    i++)
                {
                    l_dest_addr[i] = l_src_addr[i];
                }
                BOOTLOADER_TRACE(BTLDR_TRC_MAIN_COPY_HBB_DONE);

                //Set core scratch 3 to say hbb image is starting
                //"starthbb" = 0x7374617274686262 in ascii
                hostboot_string = 0x7374617274686262;
                writeScratchReg(MMIO_SCRATCH_HOSTBOOT_ACTIVE,
                                hostboot_string);

                // Start executing HBB
                bl_console::putString("Invoking boot firmware\r\n");
                enterHBB(HBB_HRMOR, HBB_RUNNING_OFFSET);
#ifndef CONFIG_VPO_COMPILE
            }
            else
            {
                BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_MAIN_REMOVEECC_FAIL);
                /*@
                 * @errortype
                 * @moduleid     Bootloader::MOD_BOOTLOADER_MAIN
                 * @reasoncode   Bootloader::RC_REMOVE_ECC_FAIL
                 * @userdata1[0:15]   TI_WITH_SRC
                 * @userdata1[16:31]  TI_BOOTLOADER
                 * @userdata1[32:63]  Failing address = 0
                 * @userdata2[0:31]   Word7 = 0
                 * @userdata2[32:63]  Word8 = 0
                 * @devdesc      Uncorrectable ECC error found in HBB
                 * @custdesc     A problem occurred while running processor
                 *               boot code.
                 */
                bl_terminate(MOD_BOOTLOADER_MAIN,
                             RC_REMOVE_ECC_FAIL);
            }
        }
        else
        {
            // Note getHBBSection should have TI'd so won't get here
            BOOTLOADER_TRACE_W_BRK(BTLDR_TRC_MAIN_GETHBBSECTION_FAIL);
        }
#endif

        return 0;
    }

    /** Handle MMIO to copy code/data from location to another.
     *
     * @param[in] i_srcAddr - The source location.
     * @param[in] i_destAddr - The destination location.
     * @param[in] i_size - The size of the code/data.
     * @param[in] i_ld_st_size - The size of each load/store operation.
     * @param[in] i_mmioOp - The opcode for read/write operation
     *
     * @return void.
     */
    void handleMMIO(uint64_t i_srcAddr,
                    uint64_t i_destAddr,
                    uint32_t i_size,
                    MMIOLoadStoreSizes i_ld_st_size,
                    MMIOReadWrite i_mmioOp)
    {
        BOOTLOADER_TRACE(BTLDR_TRC_HANDLEMMIO_START + i_ld_st_size);

        // Set base addresses, Ignore HRMOR setting
        uint64_t l_srcAddr_base = i_srcAddr | IGNORE_HRMOR_MASK;
        uint64_t l_destAddr_base = i_destAddr | IGNORE_HRMOR_MASK;

        uint64_t l_targetGPR = 0;

        for(uint32_t i = 0;
            i < i_size;
            i += i_ld_st_size)
        {
            // Set addresses
            uint64_t l_srcAddr = l_srcAddr_base + i;
            uint64_t l_destAddr = l_destAddr_base + i;

            if(i_ld_st_size == BYTESIZE)
            {
                if (i_mmioOp == READ)
                {
                    // Cache-inhibited load byte from hypervisor state.
                    // lbzcix    BOP1,Ref_G0,BOP2
                    asm volatile("lbzcix %0, 0, %1"
                                : "=r" (l_targetGPR)    // output, %0
                                : "r" (l_srcAddr)       // input,  %1
                                : );                    // no impacts

                    uint8_t* l_destPtr = reinterpret_cast<uint8_t*>(l_destAddr);
                    *l_destPtr = l_targetGPR;
                }
                else
                {
                    uint8_t l_data = *(reinterpret_cast<uint8_t*>(l_srcAddr));

                    // Cache-inhibited store byte from hypervisor state
                    // stbcix    BOP1,Ref_G0,BOP2
                    asm volatile("stbcix %0, 0, %1"
                                :
                                : "r" (l_data), "r" (l_destAddr)
                                : "memory"); // indicates mem read/write op
                }
            }
            else if(i_ld_st_size == WORDSIZE)
            {
                if(i_mmioOp == READ)
                {
                    // Cache-inhibited load word from hypervisor state.
                    // lwzcix    BOP1,Ref_G0,BOP2
                    asm volatile("lwzcix %0, 0, %1"
                                 : "=r" (l_targetGPR)    // output, %0
                                 : "r" (l_srcAddr)       // input,  %1
                                 : );                    // no impacts

                    uint32_t* l_destPtr = reinterpret_cast<uint32_t*>(l_destAddr);
                    *l_destPtr = l_targetGPR;
                }
                else
                {
                    uint32_t l_data = *(reinterpret_cast<uint32_t*>(l_srcAddr));

                    // Cache-inhibited store word from hypervisor state
                    // stwcix    BOP1,Ref_G0,BOP2
                    asm volatile("stwcix %0, 0, %1"
                                 :
                                 : "r" (l_data), "r" (l_destAddr)
                                 : "memory"); // indicates mem read/write op
                }
            }
            else
            {
                if(i_mmioOp == READ)
                {
                    // Cache-inhibited load double word from hypervisor state.
                    // ldcix       BOP1,Ref_G0,BOP2
                    asm volatile("ldcix %0, 0, %1"
                                 : "=r" (l_targetGPR)    // output, %0
                                 : "r" (l_srcAddr)       // input,  %1
                                 : );                    // no impacts

                    uint64_t* l_destPtr = reinterpret_cast<uint64_t*>(l_destAddr);
                    *l_destPtr = l_targetGPR;
                }
                else
                {
                    uint64_t l_data = *(reinterpret_cast<uint64_t*>(l_srcAddr));

                    // Cache-inhibited store double word from hypervisor state
                    // stdcix    BOP1,Ref_G0,BOP2
                    asm volatile("stdcix %0, 0, %1"
                                 :
                                 : "r" (l_data), "r" (l_destAddr)
                                 : "memory"); // indicates mem read/write op
                }
            }
        }
    }
} // end namespace Bootloader
