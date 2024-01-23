/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ocmbupd/ocmbFwImage_const.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
#ifndef __OCMBFWIMAGE_CONST_H
#define __OCMBFWIMAGE_CONST_H

namespace ocmbupd
{

// ********************************WARNING**********************************
//
//   THIS FILE MUST BE KEPT IN SYNC WITH src/build/buildpnor/pkgOcmbFw.pl
//
// ********************************WARNING**********************************


/**
 * @brief Eyecatcher value is the ascii representation of the
 *        null terminated string, "OCMBHDR".
 */
constexpr uint64_t EYE_CATCHER_VALUE = 0x4F434D4248445200ULL;

constexpr uint32_t MAX_BIN_TRACE = 256;

/**
 * @brief Miscellaneous constants related to the OCMB firmware header
 */
enum OCMBFW_HEADER_CONSTS: uint32_t
{
    // Explorer-only format, contains only a base header and one
    // image.
    V1_BASE_HEADER_VERSION_MAJOR = 1,
    V1_BASE_HEADER_VERSION_MINOR = 0,

    HEADER_MAX_SIZE = 4096,

    // Multi-OCMB format, contains base and extended header along with
    // multiple images.
    V2_BASE_HEADER_VERSION_MAJOR = 2,
    V2_BASE_HEADER_VERSION_MINOR = 0,
};

/**
 * @brief Base header for the OCMB flash image content
 */
typedef struct ocmbFwHeader
{
    // See EYE_CATCHER_VALUE above
    uint64_t eyeCatcher;

    // The major and minor version of this header
    uint32_t majorVersion;
    uint32_t minorVersion;

    // The total size of this header (must be 8 byte aligned)
    uint32_t headerSize;

    // The number of "tagged data triplets" included
    // in this header. (see taggedTriplet_t)
    uint32_t numTriplets;

    // Variable sized, unordered tagged data triplets start here
}ocmbFwHeader_t;

/**
 * @brief Tag Id's for tagged triplets in the base header
 */
enum TRIPLET_TAG_IDS: uint32_t
{
    // Data contains 64 bytes of SHA512 hash data
    TAG_SHA512 = 1,

    // Data contains a null-terminated string of comma separated
    // key/value pairs with the following format:
    //   <key1>=<value1>,<key2>=<value2>,<key3>=<value3>
    //
    // Keys and values are defined by the manufacturer and must
    // not contain the characters "=" or ","
    TAG_KEY_VALUE_PAIRS = 2,
};

/**
 * @brief Tagged triplet data format for base header
 */
typedef struct taggedTriplet
{
    // Identifies the data format for this triplet
    uint32_t tagId;

    // Size of the data that follows (must be 8 byte aligned)
    uint32_t dataSize;

    // variable sized data starts here
}taggedTriplet_t;

/** OCMBFW extended PNOR partition structures **/

/* @brief The type of image a given image_info structure refers to.
 *        See the POZ SBE FIFO Interface specification for definitions of these constants. */
enum image_type_t : uint64_t
{
    IMAGE_TYPE_BOOTLOADER = 1,
    IMAGE_TYPE_RUNTIME = 2,
};

/* @brief The type of OCMB a given image_info structure is applicable
 * to.
 */
enum ocmb_type_t : uint64_t
{
    OCMB_TYPE_ODYSSEY = 1,
    OCMB_TYPE_EXPLORER = 2
};

enum compression_type_t : uint64_t
{
    COMPRESSION_TYPE_NONE = 0
};

/* @brief Storage for SHA3-512 hashes. */
using ocmbfw_hash_t = uint8_t[64];

/* @brief Storage for version string */
using vsn_string_t = uint8_t[256];

/* @brief A structure describing a single firmware image within the
 * OCMBFW PNOR partition.
 * If this structure changes, pkgOcmbFw_ext.py must be updated.
 */
struct ocmbfw_ext_image_info
{
    ocmb_type_t ocmb_type; // Odyssey or Explorer
    image_type_t image_type; // Type of image (bootloader, runtime)
    uint32_t dd_level_major;
    uint32_t dd_level_minor;
    compression_type_t compression_type;
    ocmbfw_hash_t image_hash; // Hash of image contents. How this is
                              // calculated is dependent on the OCMB
                              // and image types.
    ocmbfw_hash_t measured_hash; // Hash of the expected measurements that OCMB
                                 // will write into measurement registers for
                                 // secureboot validation.
    vsn_string_t version_string; // Human-readable version string.
    uint64_t image_offset; // byte offset from the V2 PNOR section header to image contents.
    uint64_t image_size; // Size of image contents in bytes
} PACKED;

enum ocmbfw_ext_partition_version_t : uint64_t
{
    OCMBFW_EXT_PARTITION_VERSION_1 = 1
};

/* @brief The OCMBFW extended section header.
 * If this structure changes, pkgOcmbFw_ext.py must be updated.
 */
struct ocmbfw_ext_pnor_section_header
{
    ocmbfw_ext_partition_version_t header_version; // subversion of V2 PNOR structure
    uint64_t num_images; // count of subsequent images[] array
    ocmbfw_ext_image_info images[1]; // any number of images
} PACKED;

/* @brief A wildcard for the find_ocmbfw_ext_image function */
const uint32_t DD_LEVEL_ANY = 0xFFFFFFFFu;

} //namespace ocmbupd

#endif
