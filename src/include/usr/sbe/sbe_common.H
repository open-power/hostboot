/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbe_common.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
 *  @file sbe_common.H
 *
 *  SBE common header
 *
 */

#ifndef __SBE_SBE_COMMON_H
#define __SBE_SBE_COMMON_H

#include <stdint.h>  // size_t, uint8_t, etc
#include <builtins.h> // PACKED

namespace SBE
{
    /******************************************/
    /*  Constants                             */
    /******************************************/
    // Each SBE Image stored in PNOR has a 64-byte version associated with it
    // (like a SHA hash of the image)
    const size_t  SBE_IMAGE_VERSION_SIZE = 64; // 64 bytes

    // Using only first 20 bytes of 64-byte sbe_image_version
    const size_t  SBE_MVPD_SHORT_IMAGE_VERSION_SIZE = 20;

    // Number of versions supported
    const uint8_t SBE_SEEPROM_STRUCT_MAX_VERSIONS    = 0x02;

    // Size of supported versions - must be 8-byte aligned
    const size_t  SBE_SEEPROM_STRUCT_SIZES[SBE_SEEPROM_STRUCT_MAX_VERSIONS] =
                      {
                         0,   // ver0: uninitialized - no size
                         80,  // ver1: size of struct is 80 bytes
                      };

    // This enum provides the struct versions for sbeSeepromVersionInfo_t
    // Each numeric version is named after the key feature it introduces.
    enum sbeSeepromStructVersionInfo_t {
        STRUCT_VERSION_FIRST  = 0x1,
        STRUCT_VERSION_LATEST = 0x1,
        STRUCT_VERSION_SIMICS = 0x5A5A5A5A,
    };

    #define STRUCT_VERSION_CHECK(version) (((version) >= STRUCT_VERSION_FIRST) \
                                        && ((version) <= STRUCT_VERSION_LATEST))

    // Constant written to SBE SEEPROM version struct to invalidate the
    // struct and the image - 'INVALID\0'
    const uint64_t SBE_SEEPROM_STRUCT_INVALID = 0x494E56414C494400;

    // Used for locations of SBE_Version and SBE Image on a SEEPROM
    const uint64_t SBE_KILOBYTE                 = 1024;    // Size of a Kilobyte
    const uint64_t SBE_SEEPROM_VERSION_READ_SIZE = 0x100; // 128 Bytes * 2  (256 decimal)
    const uint64_t SBE_IMAGE_SEEPROM_ADDRESS    = 0x00;          // 0
    const uint64_t SBE_VERSION_SPACE_WITH_ECC   = (SBE_SEEPROM_VERSION_READ_SIZE * 9) / 8; // 256B + ECC
    const uint64_t SBE_SEEPROM_SIZE             = 512*SBE_KILOBYTE;   // 512KB Physical size
    const uint64_t PHYS_CHIPS_PER_LOGICAL_SEEPROM = 1; // EKB p10_infrastruct_help.H PCPLS
    const uint64_t SBE_SEEPROM_ECC_PAD          = SBE_SEEPROM_SIZE % 9;
    const uint64_t SBE_SEEPROM_SIZE_WO_ECC      = ((SBE_SEEPROM_SIZE - SBE_SEEPROM_ECC_PAD) / 9) * 8;
    // SBE Version (with ECC) kept at end of the 512KB memory
    // Adjust end of usable memory with ECC to be a multiple of 9 bytes
    const uint64_t SBE_VERSION_SEEPROM_ADDRESS  = PHYS_CHIPS_PER_LOGICAL_SEEPROM * SBE_SEEPROM_SIZE
                                                - SBE_SEEPROM_ECC_PAD
                                                - SBE_VERSION_SPACE_WITH_ECC;

    const uint64_t END_OF_SEEPROM_MINUS_READ_SIZE = PHYS_CHIPS_PER_LOGICAL_SEEPROM*SBE_SEEPROM_SIZE_WO_ECC
                                               - SBE_SEEPROM_VERSION_READ_SIZE;

    // Used to read SBE Boot Side from processor
    // (PERV_SB_CS_SCOM 0x00050008 or PERV_SB_CS_FSI 0x2808)
    // bit location identifies if boot side=0 or boot side=1
    const uint64_t SBE_BOOT_SELECT_MASK = 0x0000400000000000;   // SBE SEEPROM bit 17
    const uint32_t SBE_BOOT_SELECT_MASK_FSI = SBE_BOOT_SELECT_MASK>>32;
    const uint64_t SBE_MBOOT_SELECT_MASK = 0x0000200000000000;  // Measurement SEEPROM bit 18
    const uint32_t SBE_MBOOT_SELECT_MASK_FSI = SBE_MBOOT_SELECT_MASK>>32;

    // Hard coded value, pass in 2KB max
    const uint32_t RING_OVD_SIZE = 0x800;


    // PNOR SBE Partition constants
    const uint32_t MAX_SBE_ENTRIES = 9;
    const uint32_t SBETOC_EYECATCH = 0x53424500;  //'SBE\0'
    const uint64_t NONSECURE_VER_EYECATCH = 0x56455253494F4E00; //'VERSION\0'
    const uint32_t SUPPORTED_TOC_VER = 0x00000001;

    // Cacheline Size
    const uint64_t CACHELINE_SIZE = 128;

    // MVPD SB Keyword contants
    const size_t  MVPD_SB_RECORD_SIZE = 129;

    // PERMANENT FLAG - bit 0: 0x0 -> indicates 0 is permanent.
    const uint8_t PERMANENT_FLAG_MASK             = 0x80;
    const uint8_t SEEPROM_0_PERMANENT_VALUE       = 0x00;
    const uint8_t SEEPROM_1_PERMANENT_VALUE       = 0x80;

    // RE-IPL SEEPROM DESIGNATION - bit 1: 0x0 -> indicates boot from SEEPROM 0
    // NOTE: Used *ONLY* for re-IPL Requests
    const uint8_t REIPL_SEEPROM_MASK              = 0x40;
    const uint8_t REIPL_SEEPROM_0_VALUE           = 0x00;
    const uint8_t REIPL_SEEPROM_1_VALUE           = 0x40;

    // SEEPROM 0 FORCE UPDATE FLAG - bit 2: 0x0 -> indicates do not force update
    const uint8_t SEEPROM_0_FORCE_UPDATE_MASK     = 0x20;
    const uint8_t SEEPROM_0_DO_NOT_FORCE_UPDATE   = 0x00;
    const uint8_t SEEPROM_0_FORCE_UPDATE          = 0x20;

    // SEEPROM 1 FORCE UPDATE FLAG - bit 3: 0x0 -> indicates do not force update
    const uint8_t SEEPROM_1_FORCE_UPDATE_MASK     = 0x10;
    const uint8_t SEEPROM_1_DO_NOT_FORCE_UPDATE   = 0x00;
    const uint8_t SEEPROM_1_FORCE_UPDATE          = 0x10;

    // RE-IPL MSEEPROM DESIGNATION - bit 4: 0x0 -> indicates boot from MSEEPROM 0
    const uint8_t REIPL_MSEEPROM_MASK              = 0x08;
    const uint8_t REIPL_MSEEPROM_0_VALUE           = 0x00;
    const uint8_t REIPL_MSEEPROM_1_VALUE           = 0x08;


    /******************************************/
    /*  Structs                               */
    /******************************************/

    // Copied from src/include/usr/util/utilxipimage.H
    struct imageBuild_t
    {
        uint32_t buildDate;    // Generated by `date +%Y%m%d`, eg, 20110630
        uint32_t buildTime;    // Generated by `date +%H%M`, eg, 0756
        char     buildTag[20]; // Generated when releasing image to fw
    } PACKED;

    /**
     * @brief Struct containing version information stored on SBE SEEPROMs
     *
     * NOTE: For ECC purposes, this must be 8-byte aligned,
     *       so pad data if necessary
     *       struct_version 1: size = 4+4+64+4+1+3 = 80 (aligned)
     */
    struct sbeSeepromVersionInfo_t
    {
        // The first 64-bits will be read out to check for struct_version
        uint32_t  struct_version;
        uint32_t  data_crc;
        uint8_t   image_version[SBE_IMAGE_VERSION_SIZE];
        uint8_t   unused1[4];     // unused space; added for alignment
        uint8_t   origin;        // set if SBE came from golden side
        uint8_t   unused2[3];     // unused space; added for alignment
    } PACKED;

    // This line forces a compile fail if struct is NOT 8-byte-aligned
    static_assert(0 == (sizeof(sbeSeepromVersionInfo_t) % 8),
                  "sbeSeepromVersionInfo_t is not 8-byte-aligned");

    typedef uint8_t sbe_image_version_t[SBE_IMAGE_VERSION_SIZE];

    /**
     * @brief Struct of individual SBE entry in SBE
     *        Table of Contents in PNOR partitions
     */
    struct sbeTocEntry_t
    {
        uint32_t ec;          // Chip EC, right aligned
        uint32_t offset;      // Offset within partition, in bytes
        uint32_t size;        // Size of image, in bytes
    } PACKED;

    /**
     * @brief Layout of Table of Contents at beginning of SBE Partitions in PNOR
     */
    struct sbeToc_t
    {
        uint32_t eyeCatch;                      // Expected to contain 'SBE\0'
        uint32_t tocVersion;                    // Version of SBE TOC
        sbeTocEntry_t entries[MAX_SBE_ENTRIES]; // Image entries
    } PACKED;

    /**
     * @brief Layout of Hostboot Bootloader (HBBL) end of load data
     */
    struct hbblEndData_t
    {
        uint64_t eyecatcher;                 // Expected to contain 'HBBLend\0'
        uint64_t address;                    // bootloader.ld end_load_address
    } PACKED;

    /**
     * @brief Layout of SB keyword in MVPD
     */
    struct mvpdSbKeyword_t
    {
        uint8_t flags;                 // 1 byte for various flags

        uint32_t seeprom_0_data_crc;
        uint8_t seeprom_0_short_version[SBE_MVPD_SHORT_IMAGE_VERSION_SIZE];

        uint32_t seeprom_1_data_crc;
        uint8_t seeprom_1_short_version[SBE_MVPD_SHORT_IMAGE_VERSION_SIZE];

        SBE::imageBuild_t seeprom_0_build;

        SBE::imageBuild_t seeprom_1_build;

        uint8_t mvpdSbPad[MVPD_SB_RECORD_SIZE - sizeof(flags)
                          - sizeof(seeprom_0_data_crc)
                          - sizeof(seeprom_1_data_crc)
                          - (SBE_MVPD_SHORT_IMAGE_VERSION_SIZE * 2)
                          - (sizeof(SBE::imageBuild_t) * 2)];
    } PACKED;

    // This line forces a compile fail if struct is too large
    static_assert(sizeof(mvpdSbKeyword_t) <= MVPD_SB_RECORD_SIZE,
                  "mvpdSbKeyword_t is too large");
} //end namespace SBE
#endif
