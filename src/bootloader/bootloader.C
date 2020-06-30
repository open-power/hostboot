/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bootloader.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#define __BOOT_LOADER_C

#include <stdint.h>
#include <bootloader/bootloader.H>
#include <bootloader/bootloader_trace.H>
#include <bootloader/hbblreasoncodes.H>
#include <bootloader/bl_pnorAccess.H>
#include <bootloader/bootloaderif.H>

#include <lpc_const.H>
#include <pnor_utils.H>
#include <arch/memorymap.H>

#include <ecc.H>

#include <stdlib.h>
#include <util/align.H>
#include <string.h>
#include <limits.h>

#include <securerom/ROM.H>
#include <config.h>
#include <secureboot/secure_reasoncodes.H>
#include <p9_sbe_hb_structures.H>

#include <pnor/pnorif.H>

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
        // Read SBE HB shared data.
        const auto l_blConfigData = reinterpret_cast<BootloaderConfigData_t *>(
                                                              SBE_HB_COMM_ADDR);
        // Set Secure Settings
        // Ensure SBE to Bootloader structure has the SAB member
        //   and other Secure Settings
        if (l_blConfigData->version >= SAB_ADDED)
        {
            g_blData->blToHbData.secureAccessBit =
                l_blConfigData->secureSettings.secureAccessBit;
            g_blData->blToHbData.securityOverride =
                l_blConfigData->secureSettings.securityOverride;
            g_blData->blToHbData.allowAttrOverrides =
                l_blConfigData->secureSettings.allowAttrOverrides;
        }

        if(l_blConfigData->version >= SBE_BACKDOOR_BIT_ADDED)
        {
            g_blData->blToHbData.secBackdoorBit =
                                 l_blConfigData->secureSettings.secBackdoorBit;
        }

        // Find secure ROM addr
        // Get starting address of ROM size and code which is the next 8 byte
        // aligned address after the bootloader end.
        // [hbbl][pad:8:if-applicable][securerom-size:8][securerom]
        const void * l_pBootloaderEnd = &bootloader_end_address;
        uint64_t l_bootloaderSize = 0;
        memcpy (&l_bootloaderSize, l_pBootloaderEnd, sizeof(l_bootloaderSize));
        const uint8_t* l_pRomStart = reinterpret_cast<uint8_t *>(
                                        getHRMOR() + ALIGN_8(l_bootloaderSize));

        // Create BlToHbData
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
            case ADDR_STASH_SUPPORT_ADDED:
                g_blData->blToHbData.version = BLTOHB_KEYADDR;
                break;
            case SBE_BACKDOOR_BIT_ADDED:
                g_blData->blToHbData.version = BLTOHB_BACKDOOR;
                break;
            default:
                g_blData->blToHbData.version = BLTOHB_SIZE;
                break;
        }

        // Copy values for MMIO BARs
        g_blData->blToHbData.xscomBAR
            = ((l_blConfigData->version >= MMIO_BARS_ADDED) &&
               ((l_blConfigData->xscomBAR & XSCOM_BAR_MASK) == 0))
            ? l_blConfigData->xscomBAR
            : MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR;
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

            // Set HW key hash pointer (20K - 64 bytes) and size
            g_blData->blToHbData.hwKeysHash = reinterpret_cast<const void *>
                                                            (HW_KEYS_HASH_ADDR);
            g_blData->blToHbData.hwKeysHashSize = SHA512_DIGEST_LENGTH;

            if (g_blData->blToHbData.version >= BLTOHB_SECURE_VERSION)
            {
                // Set Secure Version from the 1 byte before HW key hash pointer
                memcpy(&g_blData->blToHbData.secure_version,
                       reinterpret_cast<const void *>(SECURE_VERSION_ADDR),
                       sizeof(g_blData->blToHbData.secure_version));
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
        // Ensure SBE to Bootloader structure has key addr stash info
        if (l_blConfigData->version >= ADDR_STASH_SUPPORT_ADDED)
        {
            memcpy(&g_blData->blToHbData.keyAddrStashData,
                   &l_blConfigData->pair,
                   sizeof(keyAddrPair_t));
        }
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
     *      header.  Must not be nullptr or function will assert.
     *  @param[in] i_pComponentId Reference component ID to compare to.  Must
     *      not be nullptr or function will assert.
     */
    void verifyComponentId(
        const void* const i_pHeader,
        const char* const i_pComponentId)
    {
        assert(i_pHeader != nullptr);
        assert(i_pComponentId != nullptr);

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
#ifdef CONFIG_SECUREBOOT
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
            memcpy (&l_hw_parms.hw_key_hash, g_blData->blToHbData.hwKeysHash,
                    sizeof(SHA512_t));

            // Use current secure version
            l_hw_parms.log = g_blData->blToHbData.secure_version;

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
                memcpy(&l_beginHwKeysHash, g_blData->blToHbData.hwKeysHash,
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
#endif
    }

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

        // @TODO RTC:138268 Support multiple sides of PNOR in bootloader

        // Copy SBE BL shared data into BL HB shared data
        const auto l_blConfigData = reinterpret_cast<BootloaderConfigData_t *>(
                                                              SBE_HB_COMM_ADDR);
        g_blData->blToHbData.lpcBAR
            = ((l_blConfigData->version >= MMIO_BARS_ADDED) &&
               ((l_blConfigData->lpcBAR & LPC_BAR_MASK) == 0))
            ? l_blConfigData->lpcBAR
            : MMIO_GROUP0_CHIP0_LPC_BASE_ADDR;

        //pnorEnd is the end of flash, which is base of lpc, plus
        //the offset of the FW space, plus the TOP memory address in FW space
        uint64_t l_pnorEnd = g_blData->blToHbData.lpcBAR + LPC::LPCHC_FW_SPACE
                           + PNOR::LPC_TOP_OF_FLASH_OFFSET;

        //We dont know what the start of pnor is because we dont know the size
        uint64_t l_pnorStart = 0;

        uint32_t l_errCode = PNOR::NO_ERROR;
        g_blData->secureRomValid = false;

        // Get location of HB base code in PNOR from TOC
        // @TODO RTC:138268 Support multiple sides of PNOR in bootloader
        bl_pnorAccess::getHBBSection(l_pnorEnd,
                                     g_blData->bl_hbbSection,
                                     l_errCode,
                                     l_pnorStart);
        BOOTLOADER_TRACE(BTLDR_TRC_MAIN_GETHBBSECTION_RTN );

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
            handleMMIO(l_pnorStart + l_hbbFlashOffset,
                       (l_hbbEcc) ? HBB_ECC_WORKING_ADDR : HBB_WORKING_ADDR,
                       workingLength,
                       WORDSIZE);
            BOOTLOADER_TRACE(BTLDR_TRC_MAIN_WORKING_HANDLEMMIO_RTN);

            PNOR::ECC::eccStatus rc = PNOR::ECC::CLEAN;
            if(l_hbbEcc)
            {
                // Remove ECC from HB base code at in working location and
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

                // ROM verification of HBB image
                verifyContainer(l_src_addr);

                // Increment past secure header
                if (isEnforcedSecureSection(PNOR::HB_BASE_CODE))
                {
                    l_src_addr += PAGE_SIZE/sizeof(uint64_t);
                    l_hbbLength -= PAGE_SIZE;
                }

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
                enterHBB(HBB_HRMOR, HBB_RUNNING_OFFSET);
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

        return 0;
    }


    /** Handle MMIO to copy code/data from location to another.
     *
     * @param[in] i_srcAddr - The source location.
     * @param[in] i_destAddr - The destination location.
     * @param[in] i_size - The size of the code/data.
     * @param[in] i_ld_st_size - The size of each load/store operation.
     *
     * @return void.
     */
    void handleMMIO(uint64_t i_srcAddr,
                    uint64_t i_destAddr,
                    uint32_t i_size,
                    MMIOLoadStoreSizes i_ld_st_size)
    {
        BOOTLOADER_TRACE(BTLDR_TRC_HANDLEMMIO_START + i_ld_st_size);

        // Set base addresses, Ignore HRMOR setting
        uint64_t l_srcAddr_base = i_srcAddr | IGNORE_HRMOR_MASK;
        uint64_t l_destAddr_base = i_destAddr | IGNORE_HRMOR_MASK;

        uint32_t l_targetGPR = 0;

        for(uint32_t i = 0;
            i < i_size;
            i += i_ld_st_size)
        {
            // Set addresses
            uint64_t l_srcAddr = l_srcAddr_base + i;
            uint64_t l_destAddr = l_destAddr_base + i;

            if(i_ld_st_size == BYTESIZE)
            {
                // Cache-inhibited load byte from hypervisor state.
                // lbzcix      BOP1,Ref_G0,BOP2
                asm volatile("lbzcix %0, 0, %1"
                             : "=r" (l_targetGPR)    // output, %0
                             : "r" (l_srcAddr)       // input,  %1
                             : );                    // no impacts

                // Store byte.
                // stbx      BOP1,Ref_G0,BOP2
                asm volatile("stbx %0,0,%1"
                             :: "r" (l_targetGPR) , "r" (l_destAddr));
            }
            else if(i_ld_st_size == WORDSIZE)
            {
                // Cache-inhibited load word from hypervisor state.
                // lwzcix      BOP1,Ref_G0,BOP2
                asm volatile("lwzcix %0, 0, %1"
                             : "=r" (l_targetGPR)    // output, %0
                             : "r" (l_srcAddr)       // input,  %1
                             : );                    // no impacts

                // store word.
                // stwx      BOP1,Ref_G0,BOP2
                asm volatile("stwx %0,0,%1"
                             :: "r" (l_targetGPR) , "r" (l_destAddr));
            }
            else
            {
                // Cache-inhibited load double word from hypervisor state.
                // ldcix       BOP1,Ref_G0,BOP2
                asm volatile("ldcix %0, 0, %1"
                             : "=r" (l_targetGPR)    // output, %0
                             : "r" (l_srcAddr)       // input,  %1
                             : );                    // no impacts

                // Store double word.
                // stdx      BOP1,Ref_G0,BOP2
                asm volatile("stdx %0,0,%1"
                             :: "r" (l_targetGPR) , "r" (l_destAddr));
            }
        }
    }
} // end namespace Bootloader
