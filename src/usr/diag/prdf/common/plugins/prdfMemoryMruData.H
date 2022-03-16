/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfMemoryMruData.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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

/** @file  prdfMemoryMruData.H
 *  @brief This is specifically designed to be included in both functional and
 *         error log parsing code (i.e. must be able to compile in PPC and
 *         x86.nfp contexts).
 */

#ifndef __prdfMemoryMruData_H
#define __prdfMemoryMruData_H

#include <stdint.h>
#include <endian.h>
#include <string.h>

#include <prdfParserEnums.H>

namespace PRDF
{

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

namespace MemoryMruData
{
/** Typically a MemoryMru callout is associated with a symbol (single DIMM
 *  callout), however, there are times were we cannot isolate down that far and
 *  instead need to callout a rank (pair of DIMMs) and the associated MBA.
 *  This enums will be used to indicate if any special callouts are needed.
 */
enum Callout
{
    // NOTE: These values will be stored in the symbol field of the uint32_t
    //       version of the MemoryMru so the values must fit within the
    //       7-bits field and not collide with a valid symbol value.
    NO_SPECIAL_CALLOUT    = 0x6f,
    FIRST_SPECIAL_CALLOUT = 0x70,

    CALLOUT_RANK = FIRST_SPECIAL_CALLOUT,
    CALLOUT_ALL_MEM,

    LAST_SPECIAL_CALLOUT = CALLOUT_ALL_MEM, // Absolute last value is 0x7f
};

union MemMruMeld
{
    uint32_t u; ///< The 32-bit version of the MemoryMru

    struct
    {
        // NOTE: The combined total of all bits in this struct must add up to
        //       32 bits.
        // NOTE: There are some unused bits that can be used for future needs
        //       such as version number or wiring type.
        // NOTE: The arrangement of bits should not change. This struct will be
        //       used for parsing the MemoryMru in the error log parser, which
        //       wil be used in multiple releases. You should be able to add a
        //       field using the unused bits depending on the usage of the
        //       field, however, if the structure changes, you must add a
        //       version field so that the error log parser know which format to
        //       used.

#if !( __BYTE_ORDER == __LITTLE_ENDIAN )

        uint32_t valid      : 1; ///< Used to indicate nothing failed while
                                 ///< building the object (1=valid, 0=not valid)
        uint32_t procPos    : 3; ///< Proc position within node (0-7)
        uint32_t chnlPos    : 3; ///< MCC position within proc (0-7)
        uint32_t omiPos     : 1; ///< OMI position within the MCC (0-1)

        uint32_t pins       : 2; ///< Even and/or Odd symbol pins
        uint32_t nodePos    : 3; ///< Node position (0-7)
        uint32_t mrank      : 3; ///< Master rank (0-7)

        uint32_t dramSpared : 1; ///< True if symbol is on spared DRAM
        uint32_t symbol     : 7; ///< Symbol or SpecialCallout

        uint32_t eccSpared  : 1; ///< True if symbol is on ECC DRAM
        uint32_t srank      : 3; ///< Slave rank (0-7)
        uint32_t isOcmb     : 1; ///< True if OCMB is used
        uint32_t unused     : 2; ///< 2 Bits currently unused
#else
        // Need to reverse this to make the uint32_t look right in the
        // simulator.
        uint32_t unused     : 2;
        uint32_t isOcmb     : 1;
        uint32_t srank      : 3;
        uint32_t eccSpared  : 1;
        uint32_t symbol     : 7;
        uint32_t dramSpared : 1;
        uint32_t mrank      : 3;
        uint32_t nodePos    : 3;
        uint32_t pins       : 2;
        uint32_t omiPos     : 1;
        uint32_t chnlPos    : 3;
        uint32_t procPos    : 3;
        uint32_t valid      : 1;
#endif

    } s; ///< A struct defining the 32-bit version of the MemoryMru
};

/** Contains a MemoryMru and extended data for extra FFDC. */
struct ExtendedData
{
    MemMruMeld mmMeld;             ///< See MemMruMeld union
    uint32_t   isBufDimm      : 1; ///< 1=Centaur DIMM, 0=IS DIMM
    uint32_t   isX4Dram       : 1; ///< 1=x4 DRAM DIMM, 0=x8 DRAM DIMM
    uint32_t   isValid        : 1; ///< 1=struct contains valid data,
                                   ///< 0=otherwise. Needed just in case there
                                   ///< was a failure to gather extended data.
    uint32_t   reserved       :21; ///< Future use / nice boundary
    uint8_t    dqMapping[DQS_PER_DIMM]; ///< DQ to DIMM DQ mapping

    /** Default contructor */
    ExtendedData() :
        isBufDimm(0), isX4Dram(0),
        isValid(0), reserved(0)
    {
        mmMeld.u = 0;
        memset( &dqMapping[0], 0x00, sizeof(dqMapping) );
    }

    /** Contructor from flattened MemoryMru */
    explicit ExtendedData( uint32_t i_memMru ) :
        isBufDimm(0), isX4Dram(0),
        isValid(0), reserved(0)
    {
        mmMeld.u = i_memMru;
        memset( &dqMapping[0], 0x00, sizeof(dqMapping) );
    }
};

} // end namespace MemoryMruData
#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif

} // end namespace PRDF

#endif // __prdfMemoryMruData_H

