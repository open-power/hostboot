/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/expupd/ocmbFwImage_const.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

namespace expupd
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
    HEADER_VERSION_MAJOR = 1,
    HEADER_VERSION_MINOR = 0,
    HEADER_MAX_SIZE = 4096,
};

/**
 * @brief Header for the OCMB flash image content
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
 * @brief Tag Id's for tagged triplets
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
 * @brief Tagged triplet data format
 */
typedef struct taggedTriplet
{
    // Identifies the data format for this triplet
    uint32_t tagId;

    // Size of the data that follows (must be 8 byte aligned)
    uint32_t dataSize;

    // variable sized data starts here
}taggedTriplet_t;

} //namespace expupd

#endif
