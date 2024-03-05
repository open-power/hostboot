/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_sbe_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_sbe_utils.H
/// @brief Odyssey SBE Utilities
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 1
// *HWP Consumed by: HB:Cronus

#ifndef _ODY_SBE_UTILS_
#define _ODY_SBE_UTILS_

#include <stdint.h>
#include <cstring>

/**
 * @brief  Defines the image types that could be updated
 *         See the 'POZ SBE FIFO Interface Specification'
 */
enum sppeImageType_t : uint16_t
{
    Invalid       = 0x0000,
    Bootloader    = 0x0001,
    Runtime       = 0x0002,
    BMC_Override  = 0x0003,
    Host_Override = 0x0004,
    Num_Types
};
inline sppeImageType_t& operator++ (sppeImageType_t& t)
{
    t = sppeImageType_t(static_cast<std::underlying_type<sppeImageType_t>::type>(t) + 1);
    return t;
};

/**
 * @brief  Useful structure to hold a single 64-byte hash value
 */
struct sppeImageHash_t
{
    uint8_t x[64];

    sppeImageHash_t( void );
    bool operator==(const sppeImageHash_t& i_rhs) const;
    sppeImageHash_t& operator=(const sppeImageHash_t& i_rhs);
};
inline bool sppeImageHash_t::operator==(const sppeImageHash_t& i_rhs) const
{
    return !memcmp( x, i_rhs.x, sizeof(sppeImageHash_t) );
};
inline sppeImageHash_t& sppeImageHash_t::operator=(const sppeImageHash_t& i_rhs)
{
    memcpy( x, i_rhs.x, sizeof(sppeImageHash_t) );
    return *this;
};
inline sppeImageHash_t::sppeImageHash_t( void )
{
    bzero( x, sizeof(sppeImageHash_t) );
};


/**
 * @brief  Defines the format of a Code Level Information Package
 *         See the 'POZ SBE FIFO Interface Specification'
 */
struct sppeCLIP_t
{
    uint16_t reserved1;
    sppeImageType_t type;
    uint32_t reserved2;
    sppeImageHash_t hash;

    sppeCLIP_t( void );
};
inline sppeCLIP_t::sppeCLIP_t( void )
{
    reserved1 = 0;
    reserved2 = 0;
    type = Invalid;
};

/**
 * @brief  Defines a set of information that defines an image that
 *         will be written into the Odyssey.
 */
struct sppeImage_t
{
    sppeImageType_t type;
    sppeImageHash_t hash;
    size_t pakSize;
    void* pak;  // Pointer to the pak data for the image
};

#endif
