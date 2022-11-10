/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/chipids.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
 * Contains constants for defined chip ids (aka. CFAM IDs, IDEC, etc)
 * for supported chips in POWER systems
 */

#ifndef _CHIPIDS_H
#define _CHIPIDS_H

#include <stdint.h>

// Standard chip ids
namespace POWER_CHIPID
{

/**
 * The format for all CFAM-based chips is:  MLmCC049
 *   M.m = Major.minor DD level, e.g. DD1.3
 *   L = Location
 *   CC = Unique chip id
 *
 * See https://eclipz.pok.ibm.com/sys/ras/docs/cfam_ids.txt
 */

/**
 * Extract the chipid from the full 32-bit CFAM ID
 * @param[in]  i_cfamId : 32-bit register data
 * @return 32-bit chipid value
 */
inline uint32_t extract_chipid32( uint32_t i_cfamId )
{
    return (i_cfamId & 0x0F0FF000);
};

/**
 * Extract the smaller chipid from the full 32-bit CFAM ID
 * @param[in]  i_cfamId : 32-bit register data
 * @return Left-justified 16-bit chipid value
 */
inline uint16_t extract_chipid16( uint32_t i_cfamId )
{
    return static_cast<uint16_t>((i_cfamId & 0x0F0FF000) >> 12);
};

/**
 * Extract the DD level from the full 32-bit CFAM ID
 * @param[in]  i_cfamId : 32-bit register data
 * @return Right-justified (1 byte) M.m DD level
 */
inline uint32_t extract_ddlevel( uint32_t i_cfamId )
{
    uint32_t l_major = 0xF0000000 & i_cfamId;
    uint32_t l_minor = 0x00F00000 & i_cfamId;
    return ((l_major >> 24) | (l_minor >> 20));
};


// Full 32-bit value with empty nibbles for DD level
constexpr uint32_t NIMBUS       = 0x020D1049;
constexpr uint32_t CUMULUS      = 0x020D4049;
constexpr uint32_t AXONE        = 0x020D9049;
constexpr uint32_t P10          = 0x020DA049;
constexpr uint32_t CENTAUR      = 0x06039049;
constexpr uint32_t EXPLORER     = 0x060D2000;
constexpr uint32_t GEMINI       = 0x060DC000;
constexpr uint32_t ODYSSEY      = 0x060C0049;

// Shorter 16-bit value (drops Major nibble and 049)
constexpr uint32_t NIMBUS_16       = 0x20D1;
constexpr uint32_t CUMULUS_16      = 0x20D4;
constexpr uint32_t AXONE_16        = 0x20D9;
constexpr uint32_t P10_16          = 0x20DA;
constexpr uint32_t CENTAUR_16      = 0x6039;
constexpr uint32_t EXPLORER_16     = 0x60D2;
constexpr uint32_t GEMINI_16       = 0x60DC;
constexpr uint32_t ODYSSEY_16      = 0x60C0;

}; //namespace


// OpenCAPI ids
namespace POWER_OCID
{

// Device IDs
constexpr uint16_t EXPLORER     = 0x0636;
constexpr uint16_t ODYSSEY      = 0x06C3;


// Vendor IDs
constexpr uint16_t VENDOR_IBM   = 0x1014;

}; //namespace


// DMB (Differential Memory Buffer) IDs
namespace DDIMM_DMB_ID
{

// DDR4 DDIMM - Bytes [198][199]
constexpr uint16_t EXPLORER    = 0x8029;
constexpr uint16_t GEMINI      = 0x80A4;

};

#endif /* _CHIPIDS_H */
