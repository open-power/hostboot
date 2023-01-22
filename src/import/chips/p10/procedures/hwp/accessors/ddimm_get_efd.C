/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/accessors/ddimm_get_efd.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
///
/// @file ddimm_get_efd.C
/// @brief Return the DRR's EFD based on VPDInfo
///
/// *HWP HW Maintainer: Roland Veloz <rveloz@us.ibm.com>
/// *HWP FW Maintainer: Christian Geddes <crgeddes@us.ibm.com>
/// *HWP Consumed by: Cronus, FSP, HB

/// This procedure was coded using the specs found in
/// document 1U2UDDIMM_SPD.docx, V 0.2.1, 1/17/19,
///
/// DMB - Differential Memory Buffer
/// DDIMM - Differential Dual In-Line Module
/// EFD - Extended Function Descriptor
/// MR  - Master Rank
/// SPD - Serial Presence Detect

#include <stdint.h>         // uint8_t, uint64_t
#include <endian.h>         // le64toh
#include <fapi2.H>          // anything prefixed with fapi2::
#include <ddimm_get_efd.H>

//remove the following comments for unit testing
//#undef FAPI_DBG
//#define FAPI_DBG(args...) FAPI_INF(args)

/// Common SPD memory addressing constants
/// These offsets are relative to the start of the SPD
/// 0 based addressing
// Offset to the memory type (DDR4, etc) of the DDIMM.
// size is 1 byte: address 2
const size_t SPD_MEM_TYPE_ADDR = 2;
// Offset to the module type (RDIMM, DDIMM, planar, etc)
// size is 1 byte: address 3
const size_t SPD_MODULE_TYPE_ADDR = 3;
// Mask of the base module type within the module type byte
const size_t SPD_BASE_MODULE_TYPE_MASK = 0x0F;
// Value of the base module type for a planar DIMM config
const size_t SPD_PLANAR_VALUE = 0x0C;

/// DDR4 SPD memory addressing constants
// Offset to the SPD's DMB manufacturer ID
// See SPD_DDR4_EXPECTED_DMB_MFG_ID below for the expected value for DDR4
// size is 2 bytes; address 198 - 199
const size_t SPD_DDR4_DMB_DMB_MFG_ID_ADDR = 198;
// Offset to the SPD's DMB manufacturer ID
// Offset to the SPD's DMB revision.
// See SPD_DDR4_EXPECTED_DMB_REVISION below for the expected value for DDR4
// size is 1 byte: address 200
const size_t SPD_DDR4_DMB_REVISION_ADDR = 200;
// Offset to the DDR4 EFD memory space/block offset.  The value, at this location,
// is where the EFD block data offset begins.
// size is 8 bytes: address 277 to 284
const size_t SPD_DDR4_EFD_MEMORY_SPACE_OFFSET_ADDR = 277;
// Offset to the DDR4 EFD's memory space size.  The value at this offset is used
// to calculate the actual EFD memory size (see calculateEfdMemorySpaceSize(..))
// size is 1 byte: address 285
// only bits 0 - 4 used (see following MASK const)
const size_t SPD_DDR4_EFD_MEMORY_SPACE_SIZE_ADDR = 285;
// Bit mask to the EFD memory space size
// Bits 0 - 4: Valid values are 0 - 5; 0=1K, 1=2KB, 2=4KB, 3=8KB, 4=16KB, 5=32KB
const uint8_t SPD_EFD_MEMORY_SPACE_SIZE_MASK = 0x0F;
const uint8_t SPD_EFD_MEMORY_SPACE_SIZE_MAX_VALUE = 0x05;
// This changes on planar SPD:
// Bits 0 - 6: EFD memory space in KB; 0=0KB, 1=1KB, 2=2KB, ... 127=127KB
// If bit 7 is set, it adds and additional 512 bytes to the size
const uint8_t SPD_PLANAR_EFD_MEMORY_SPACE_SIZE_MASK = 0x7F;
const uint8_t SPD_PLANAR_EFD_MEMORY_SPACE_SIZE_ADDER_MASK = 0x80;
const size_t SPD_PLANAR_EFD_MEMORY_SPACE_SIZE_ADDER = 512;
// Offset to the number of all EFDs that is contained in the DDR4 EFD memory space.
// The value at this offset is how many EFDs exists within the DDR4 EFD memory space.
// size is 2 bytes; address 286 to 287
const size_t SPD_DDR4_EFD_COUNT_ADDR = 286;
// Bit mask to the number of all EFDs
// Bits 0 - 5: Valid values are 0 - 63(0x003F)
const uint16_t SPD_EFD_COUNT_MASK = 0x003F;
// Offset to the DDR4 EFD meta data within the SPD.
// size is 128 bytes; address 288 to 415; 32 EFD meta data's sized 4 bytes each
const size_t SPD_DDR4_EFD_META_DATA_ADDR = 288;
// Offset to Host Interface Speed Supported within the DDR4 SPD.
const size_t SPD_DDR4_SUPPORTED_HOST_SPEEDS_ADDR = 205;

/// DDR5 SPD memory addressing constants
// Offset to the SPD's DMB manufacturer ID
// See SPD_DDR5_EXPECTED_DMB_MFG_ID below for the expected value for DDR5
// size is 2 bytes; address 282 - 283
const size_t SPD_DDR5_DMB_DMB_MFG_ID_ADDR = 282;
// Offset to the SPD's DMB revision.
// See SPD_DDR5_EXPECTED_DMB_REVISION below for the expected value for DDR5
// size is 1 byte: address 284
const size_t SPD_DDR5_DMB_REVISION_ADDR = 284;
// Offset to the DDR5 EFD memory space/block offset.  The value, at this location,
// is where the EFD block data offset begins.
// size is 8 bytes: address 381 to 388
const size_t SPD_DDR5_EFD_MEMORY_SPACE_OFFSET_ADDR = 381;
// Offset to the DDR5 EFD's memory space size.  The value at this offset is used
// to calculate the actual EFD memory size (see calculateEfdMemorySpaceSize(..))
// size is 1 byte: address 389
// only bits 0 - 4 used (see following MASK const)
const size_t SPD_DDR5_EFD_MEMORY_SPACE_SIZE_ADDR = 389;
// Offset to the number of all EFDs that is contained in the DDR5 EFD memory space.
// The value at this offset is how many EFDs exists within the DDR5 EFD memory space.
// size is 2 bytes; address 390 to 391
const size_t SPD_DDR5_EFD_COUNT_ADDR = 390;
// Offset to the DDR5 EFD meta data within the SPD.
// size is 24 bytes; address 392 to 415; 6 EFD meta data's sized 4 bytes each
const size_t SPD_DDR5_EFD_META_DATA_ADDR = 392;
// Offset to Host Interface Speed Supported within the DDR5 SPD.
const size_t SPD_DDR5_SUPPORTED_HOST_SPEEDS_ADDR = 363;

/// SPD - EFD meta data constants
// Size of the EFD meta data's within the SPD
// size is 4 bytes
const size_t SPD_EFD_META_DATA_BYTE_SIZE = 4;

/// SPD - EFD meta data addressing constants.
/// These offsets are relative to the start of a given EFD meta data section,
/// located in the EFD meta data block, as describe in const
/// SPD_DDR4_EFD_META_DATA_ADDR above
/// 0 based addressing
// Byte 1 offset to an individual EFD meta data
// Bits 0 - 4: EFD Extended Function Type
// size is 1 byte; address 1
const size_t SPD_EFD_META_DATA_EFD_BYTE_1_OFFSET = 1;
const size_t SPD_EFD_META_DATA_EFD_FUNCTION_TYPE_MASK = 0x0F;
// Byte 2 offset to an individual EFD meta data
// Bits 0 - 4: The end to the EFD block offset in the EFD memory space
//             SPD_EFD_META_DATA_EFD_BLOCK_OFFSET_MASK can mask these bits out
// size is 1 byte; address 2
const size_t SPD_EFD_META_DATA_EFD_BYTE_2_OFFSET = 2;
const size_t SPD_EFD_META_DATA_EFD_BLOCK_OFFSET_MASK = 0x1F;
// Byte 3 offset to an individual EFD meta data
// Bits 0 - 4: EFD block offset extension to an EFD in the EFD memory space
//             Currently not used
// Bits 7: Flag that indicates if an EFD, in the EFD memory space, is
//         implemented.
//         SPD_EFD_META_DATA_EFD_IS_IMPLEMENTED_MASK can mask this bit out
// size is 1 byte; address 3
const size_t SPD_EFD_META_DATA_EFD_BYTE_3_OFFSET = 3;
const size_t SPD_EFD_META_DATA_EFD_IS_IMPLEMENTED_MASK = 0x80;

/// EFD constants
// The EFD block size increments in multiple of 32 bytes
const size_t SPD_EFD_INCREMENTAL_BLOCK_BYTE_SIZE = 32;
// EFD total memory space size can be 1KB, 2KB, 4KB, 8KB, etc.,
// This value is used in an exponential function of the form y = ab^x
// Where 'EFD total memory space size' is y, EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE
// is a, value found at SPD_DDR4_EFD_MEMORY_SPACE_SIZE_ADDR is b, and x is 2
// also see SPD_DDR4_EFD_MEMORY_SPACE_SIZE_ADDR and calculateEfdMemorySpaceSize(..)
const size_t EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE = 1024;
// The 'assumed' maximum byte size.  The reason it is assumed, is because
// the maximum size could get updated.  Having this value allows for quick
// turn around on initial call.  On subsequent call, size is verified and
// asserted if the assumption is incorrect.
const size_t SPD_DDR4_EFD_ASSUMED_MAX_BYTE_SIZE = (4 *
        SPD_EFD_INCREMENTAL_BLOCK_BYTE_SIZE);
const size_t SPD_DDR5_EFD_ASSUMED_MAX_BYTE_SIZE = (16 *
        SPD_EFD_INCREMENTAL_BLOCK_BYTE_SIZE);

/// EFD - DDR4 memory addressing constants.
/// These offsets are relative to the start of the actual EFD block
/// as describe in const SPD_DDR4_EFD_MEMORY_SPACE_OFFSET_ADDR above
/// 0 based addressing
// Offset to the DDR4's frequency within an individual EFD
// size is 2 bytes: address 0 - 1
const size_t EFD_DDR4_FREQUENCY_ADDR = 0;
// Offset to the DDR4's master rank data within an individual EFD
// size is 1 byte: address 2
const size_t EFD_DDR4_MRANK_ADDR = 2;
// Offset to the DDR4's Channel supported data within an individual EFD
// size is 1 byte: address 15
// Only used on planar SPD
const size_t EFD_DDR4_CHANNEL_SUPPORT_ADDR = 3;
// Offset to the DDR4's Dimms supported data within an individual EFD
// size is 1 byte: address 7
// Only used on planar SPD
const size_t EFD_DDR4_DIMM_SUPPORTED_ADDR = 7;

/// SPD - DDR4 expected values
// SPD type for DDR4 as found in SPD byte 2
// size is 1 byte
const uint8_t SPD_DDR4_TYPE = 0x0C;
// SPD size for DDR4, 512 bytes as described in document 1U2UDDIMM_SPD.docx
const size_t SPD_DDR4_SIZE = 512;
// SPD - DDR4 expected value for the DMB manufacturer ID
// This value is extrapolated from the JEDEC document
// 0x29 is for for Microsemi
// size is 2 bytes
const uint16_t SPD_DDR4_DMB_MFG_ID_MICROCHIP = 0x2980;
const uint16_t SPD_DDR4_DMB_MFG_ID_IBM = 0xA480;
// SPD - DDR4 expected value for the DMB revision.
// Currently at initial revision - revision 0
// size is 1 byte
const uint8_t SPD_DDR4_EXPECTED_DMB_REVISION_0_MICROCHIP = 0x00;
const uint8_t SPD_DDR4_EXPECTED_DMB_REVISION_A0_MICROCHIP = 0xA0;
const uint8_t SPD_DDR4_EXPECTED_DMB_REVISION_A1_MICROCHIP = 0xA1;
const uint8_t SPD_DDR4_EXPECTED_DMB_REVISION_B0_MICROCHIP = 0xB0;
const uint8_t SPD_DDR4_EXPECTED_DMB_REVISION_IBM = 0x00;

/// EFD - DDR5 memory addressing constants.
/// These offsets are relative to the start of the actual EFD block
/// as describe in const SPD_DDR5_EFD_MEMORY_SPACE_OFFSET_ADDR above
/// 0 based addressing
// Offset to the DDR5's frequency within an individual EFD
// size is 1 byte: address 0
const size_t EFD_DDR5_FREQUENCY_ADDR = 0;
// Offset to the DDR5's master rank data within an individual EFD
// size is 1 byte: address 2
const size_t EFD_DDR5_MRANK_ADDR = 2;

/// SPD - DDR5 expected values
// SPD type for DDR5 as found in SPD byte 2
// size is 1 byte
const uint8_t SPD_DDR5_TYPE = 0x12;
// SPD size for DDR5, 512 bytes as described in document 1U2UDDIMM_SPD.docx
const size_t SPD_DDR5_SIZE = 512;
// SPD - DDR5 expected value for the DMB manufacturer ID
// size is 2 bytes
const uint16_t SPD_DDR5_DMB_MFG_ID_IBM = 0xA480;
// SPD - DDR5 expected value for the DMB revision.
// Currently at initial revision - revision 0
// size is 1 byte
const uint8_t SPD_DDR5_EXPECTED_DMB_REVISION_0_IBM = 0x00;

// Maximum number of FFDC elements we will save off
//  (should stay in sync with error xml)
const size_t MAX_EFD_FFDC = 32;

/// Local enumerations
// * Bytes 205 and 206 of DDR4 SPD and bytes 0 & 1 of EFD contain the frequency info.
// * Bytes 363 and 364 of DDR5 SPD and bytes 0 & 1 of EFD contain the frequency info.
enum DDR_FREQUENCY : uint16_t
{
    DDR4_FREQ_VAL_0 = 12800,
    DDR4_FREQ_VAL_1 = 14930,
    DDR4_FREQ_VAL_2 = 17060,
    DDR4_FREQ_VAL_3 = 19200,
    DDR4_FREQ_VAL_4 = 21330,
    DDR4_FREQ_VAL_5 = 23460,
    DDR4_FREQ_VAL_6 = 25600,

    DDR5_FREQ_VAL_0 = 25600,
    DDR5_FREQ_VAL_1 = 32000,
    DDR5_FREQ_VAL_2 = 38400,

    DDR_FREQ_BIT_MASK_0 = 0x0001,
    DDR_FREQ_BIT_MASK_1 = 0x0002,
    DDR_FREQ_BIT_MASK_2 = 0x0004,
    DDR_FREQ_BIT_MASK_3 = 0x0008,
    DDR_FREQ_BIT_MASK_4 = 0x0010,
    DDR_FREQ_BIT_MASK_5 = 0x0020,
    DDR_FREQ_BIT_MASK_6 = 0x0040,
};

// * Byte 2 of an EFD contains the master rank data.
enum DDR_MASTER_RANK : uint8_t
{
    DDR_MR_VAL_0 = 0,  // MR0
    DDR_MR_VAL_1 = 1,  // MR1
    DDR_MR_VAL_2 = 2,  // MR2
    DDR_MR_VAL_3 = 3,  // MR3

    DDR_MR_BIT_MASK_0 = 0x01,
    DDR_MR_BIT_MASK_1 = 0x02,
    DDR_MR_BIT_MASK_2 = 0x04,
    DDR_MR_BIT_MASK_3 = 0x08,

    // For planar systems, bit 0 is the number of DIMMs under the MC
    DDR_DROPS_BIT      = 0,

    // For planar systems, bits 1:3 is the total number of master ranks under the MC
    DDR_TOTAL_MR_START = 1,
    DDR_TOTAL_MR_LEN   = 3,
};

///
/// @brief Check that DDR4 MFG ID matches possible values
///
/// @param[in] i_mfg_id MFG ID
/// @return boolean valid/invalid
/// @note Can be expanded for future MFG IDs
///
bool check_ddr4_valid_mfg_id(const uint16_t i_mfg_id)
{
    return (SPD_DDR4_DMB_MFG_ID_MICROCHIP == i_mfg_id ||
            SPD_DDR4_DMB_MFG_ID_IBM == i_mfg_id);
}

///
/// @brief Check that DDR5 MFG ID matches possible values
///
/// @param[in] i_mfg_id MFG ID
/// @return boolean valid/invalid
/// @note Can be expanded for future MFG IDs
///
bool check_ddr5_valid_mfg_id(const uint16_t i_mfg_id)
{
    return (SPD_DDR5_DMB_MFG_ID_IBM == i_mfg_id);
}

///
/// @brief Gets the expected DMB revision of a particular DDR4 MFG ID
///
/// @param[in] i_mfg_id MFG ID
/// @param[in] i_dmb_revision DMB revision
/// @return expected DMB revision for ID
///
uint16_t check_ddr4_valid_dmb_revision(const uint16_t i_mfg_id, const uint8_t i_dmb_revision)
{
    if (i_mfg_id == SPD_DDR4_DMB_MFG_ID_IBM)
    {
        FAPI_DBG("ddr4_get_efd: SPD DMB revision = 0x%.2X, expected DMB revision = 0x%.2X",
                 i_dmb_revision, SPD_DDR4_EXPECTED_DMB_REVISION_IBM);

        return (i_dmb_revision == SPD_DDR4_EXPECTED_DMB_REVISION_IBM);
    }
    else // == SPD_DDR4_EXPECTED_DMB_REVISION_MICROCHIP
    {
        // We asserted earlier that we are either MCHP or IBM mfg ID
        FAPI_DBG("ddr4_get_efd: SPD DMB revision = 0x%.2X, expected DMB revision = 0x%.2X or 0x%.2X or 0x%.2X  or 0x%.2X",
                 i_dmb_revision,
                 SPD_DDR4_EXPECTED_DMB_REVISION_0_MICROCHIP,
                 SPD_DDR4_EXPECTED_DMB_REVISION_A0_MICROCHIP,
                 SPD_DDR4_EXPECTED_DMB_REVISION_A1_MICROCHIP,
                 SPD_DDR4_EXPECTED_DMB_REVISION_B0_MICROCHIP);

        return ((i_dmb_revision == SPD_DDR4_EXPECTED_DMB_REVISION_0_MICROCHIP) ||
                (i_dmb_revision == SPD_DDR4_EXPECTED_DMB_REVISION_A0_MICROCHIP) ||
                (i_dmb_revision == SPD_DDR4_EXPECTED_DMB_REVISION_A1_MICROCHIP) ||
                (i_dmb_revision == SPD_DDR4_EXPECTED_DMB_REVISION_B0_MICROCHIP));
    }
}

///
/// @brief Gets the expected DMB revision of a particular DDR5 MFG ID
///
/// @param[in] i_mfg_id MFG ID
/// @param[in] i_dmb_revision DMB revision
/// @return expected DMB revision for ID
///
uint16_t check_ddr5_valid_dmb_revision(const uint16_t i_mfg_id, const uint8_t i_dmb_revision)
{
    // We asserted earlier that we are IBM mfg ID
    FAPI_DBG("ddr5_get_efd: SPD DMB revision = 0x%.2X, expected DMB revision = 0x%.2X",
             i_dmb_revision,
             SPD_DDR5_EXPECTED_DMB_REVISION_0_IBM);

    return (i_dmb_revision == SPD_DDR5_EXPECTED_DMB_REVISION_0_IBM);
}

///
/// @brief Checks if the SPD is for a planar config
///
/// @param[in] i_module_type Module Type (byte 3) from SPD
/// @return true if planar config, false otherwise
///
bool is_planar_config(const uint8_t i_module_type)
{
    return ((i_module_type & SPD_BASE_MODULE_TYPE_MASK) == SPD_PLANAR_VALUE);
}

/// Local utilities
// @brief Maps the frequency numeric value to it's bit mask equivalent
//        Uses the enums in DDR_FREQUENCY above
//
// @param[in]  i_frequency, the frequency in numeric form
// @return the bit mask that represents given frequency if found, else 0
uint16_t ddr4FrequencyToBitMask(const uint64_t i_frequency)
{
    uint16_t l_bitMask{0};

    switch (i_frequency)
    {
        case DDR4_FREQ_VAL_0:
            l_bitMask = DDR_FREQ_BIT_MASK_0;
            break;

        case DDR4_FREQ_VAL_1:
            l_bitMask = DDR_FREQ_BIT_MASK_1;
            break;

        case DDR4_FREQ_VAL_2:
            l_bitMask = DDR_FREQ_BIT_MASK_2;
            break;

        case DDR4_FREQ_VAL_3:
            l_bitMask = DDR_FREQ_BIT_MASK_3;
            break;

        case DDR4_FREQ_VAL_4:
            l_bitMask = DDR_FREQ_BIT_MASK_4;
            break;

        case DDR4_FREQ_VAL_5:
            l_bitMask = DDR_FREQ_BIT_MASK_5;
            break;

        case DDR4_FREQ_VAL_6:
            l_bitMask = DDR_FREQ_BIT_MASK_6;
            break;

        default:
            l_bitMask = 0;
            break;
    }

    return l_bitMask;
}

// @brief Maps the frequency numeric value to it's bit mask equivalent
//        Uses the enums in DDR_FREQUENCY above
//
// @param[in]  i_frequency, the frequency in numeric form
// @return the bit mask that represents given frequency if found, else 0
uint16_t ddr5FrequencyToBitMask(const uint64_t i_frequency)
{
    uint16_t l_bitMask{0};

    switch (i_frequency)
    {
        case DDR5_FREQ_VAL_0:
            l_bitMask = DDR_FREQ_BIT_MASK_0;
            break;

        case DDR5_FREQ_VAL_1:
            l_bitMask = DDR_FREQ_BIT_MASK_1;
            break;

        case DDR5_FREQ_VAL_2:
            l_bitMask = DDR_FREQ_BIT_MASK_2;
            break;

        default:
            l_bitMask = 0;
            break;
    }

    return l_bitMask;
}

// @brief Maps the given master rank numeric value to it's bit mask equivalent
//        Uses the enums in DDR_FREQUENCY above
//
// @param[in]  i_masterRank, the master rank in numeric form
// @return the bit mask that represents given master rank if found, else 0
uint8_t ddrMasterRankToBitMask(const uint64_t i_masterRank)
{
    uint8_t l_bitMask{0};

    switch (i_masterRank)
    {
        case DDR_MR_VAL_0:
            l_bitMask = DDR_MR_BIT_MASK_0;
            break;

        case DDR_MR_VAL_1:
            l_bitMask = DDR_MR_BIT_MASK_1;
            break;

        case DDR_MR_VAL_2:
            l_bitMask = DDR_MR_BIT_MASK_2;
            break;

        case DDR_MR_VAL_3:
            l_bitMask = DDR_MR_BIT_MASK_3;
            break;

        default:
            l_bitMask = 0;
            break;
    }

    return l_bitMask;
};

// @brief Calculate the EFD memory space size using the exponential factor
//
// @param[in]  i_efdMemorySpaceByte, the memory space byte from the SPD
// @param[in]  i_isPlanarConfig, true if SPD is for a planar config
// @return the calculated memory space size or 0 if error
uint64_t calculateEfdMemorySpaceSize(const uint8_t i_efdMemorySpaceByte,
                                     const bool i_isPlanarConfig)
{
    uint64_t retVal = 0;

    if (i_isPlanarConfig)
    {
        retVal = EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE * (i_efdMemorySpaceByte & SPD_PLANAR_EFD_MEMORY_SPACE_SIZE_MASK);
        retVal += (i_efdMemorySpaceByte & SPD_PLANAR_EFD_MEMORY_SPACE_SIZE_ADDER_MASK) ?
                  SPD_PLANAR_EFD_MEMORY_SPACE_SIZE_ADDER : 0;
    }
    else
    {
        uint8_t l_exponentialFactor = i_efdMemorySpaceByte & SPD_EFD_MEMORY_SPACE_SIZE_MASK;
        // The exponential factor is the exponent in the power of 2 equation -
        // 2^i_exponentialFactor.  '2^i_exponentialFactor' is how many 1KB memory
        // blocks the EFD contains.  To get the full size of the EFD, multiply
        // 2^i_exponentialFactor by 1KB (EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE).

        if (l_exponentialFactor <= SPD_EFD_MEMORY_SPACE_SIZE_MAX_VALUE)
        {
            // 1 << i_exponentialFactor - a quick way to do a power of 2
            retVal = EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE * (1 << l_exponentialFactor);
        }
    }

    return retVal;
};

extern "C"
{

    // ddimm_get_efd
    fapi2::ReturnCode ddimm_get_efd(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&  i_ocmbFapi2Target,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpdInfo,
        uint8_t* const o_efdData,
        const uint8_t* const i_spdBuffer,
        const size_t   i_spdBufferSize)
    {
        FAPI_DBG("ddimm_get_efd: enter");

        // Initialize the error flag to success
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        // Initialize DRAM gen consts
        const uint8_t SPD_TYPE = i_spdBuffer[SPD_MEM_TYPE_ADDR];
        const uint8_t DRAM_GEN = SPD_TYPE;
        const size_t SPD_SIZE = (SPD_TYPE == SPD_DDR4_TYPE) ? SPD_DDR4_SIZE : SPD_DDR5_SIZE;

        // Sanity check that buffer is large enough to read DIMM Type
        // SPD size must be large enough to gather the DDIMM type info
        FAPI_ASSERT( (i_spdBufferSize > SPD_MEM_TYPE_ADDR),
                     fapi2::DDIMM_GET_EFD_VPD_BUFFER_INADEQUATE_TO_GET_DDR_TYPE().
                     set_VPD_BUFFER_SIZE(i_spdBufferSize).
                     set_REQUIRED_MIN_BUFFER_SIZE(static_cast<uint32_t>
                             (SPD_MEM_TYPE_ADDR)).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(io_vpdInfo.iv_vpd_type),
                     "ddimm_get_efd::The VPD buffer size (%d) is insufficient to "
                     "retrive the DDR type at location(%d).",
                     i_spdBufferSize,
                     SPD_MEM_TYPE_ADDR);

        // Check that we got a valid DDR4 or DDR5 SPD and that the SPD data size
        // is at a minumum of what is required for the DRAM generation
        FAPI_ASSERT( ( (SPD_TYPE == SPD_DDR4_TYPE) || (SPD_TYPE == SPD_DDR5_TYPE) ) &&
                     (i_spdBufferSize >= SPD_SIZE),
                     fapi2::DDIMM_GET_EFD_VPD_BUFFER_INADEQUATE_FOR_DDR().
                     set_VPD_BUFFER_SIZE(i_spdBufferSize).
                     set_DDR_TYPE(static_cast<uint32_t>(SPD_TYPE)).
                     set_REQUIRED_MIN_BUFFER_SIZE(SPD_SIZE).
                     set_REQUIRED_DDR4_TYPE(SPD_DDR4_TYPE).
                     set_REQUIRED_DDR5_TYPE(SPD_DDR5_TYPE).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(io_vpdInfo.iv_vpd_type),
                     "ddimm_get_efd::Either the VPD buffer size(%d) is less "
                     "than the required SPD size(%d) or the DDR memory "
                     "type(0x%.2X) does not match the DDR4 or DDR5 memory type(0x%.2X or 0x%.2X)",
                     i_spdBufferSize,
                     SPD_SIZE,
                     i_spdBuffer[SPD_MEM_TYPE_ADDR],
                     SPD_DDR4_TYPE,
                     SPD_DDR5_TYPE);

        // Call the explicit code for a DDR4 or DDR5
        FAPI_TRY_NO_TRACE(ddr4_ddr5_get_efd( i_ocmbFapi2Target,
                                             io_vpdInfo,
                                             o_efdData,
                                             i_spdBuffer,
                                             i_spdBufferSize,
                                             DRAM_GEN));

    fapi_try_exit:

        FAPI_DBG("ddimm_get_efd: exiting with %s",
                 ( (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS) ?
                   "no errors" : "errors" ));
        return fapi2::current_err;
    }

    /// @brief Return the DDR4/5's EFD based on VPDInfo
    ///        This procedure explicitly returns the EFD data, associated with a
    ///        DDR4 or DDR5, that matches given frequency and master rank criteria.
    ///
    /// @param[in]  i_ocmbFapi2Target, a valid fapi2 OCMB_CHIP target
    /// @param[in]  io_vpdInfo, @see ddimm_get_efd
    /// @param[out] o_efdData, @see ddimm_get_efd
    /// @param[in]  i_spdBuffer, pointer to the SPD data
    /// @param[in]  i_spdBufferSize, size of the SPD data
    /// @param[in]  i_dram_gen, DRAM generation encoding (SPD_DDR4_TYPE or SPD_DDR5_TYPE) of the SPD
    /// @note The size of blob may be less than io_vpdInfo.iv_size
    /// @note If data is returned for o_efdData, it will be in little endian
    /// @note Caller is responsible for allocating the buffers of o_efdData and
    ///       i_spdBuffer.  This procedure will NOT manage these buffers. This
    ///       procedure will only read/write to buffers, not allocate.
    /// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode ddr4_ddr5_get_efd(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&  i_ocmbFapi2Target,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpdInfo,
        uint8_t* const o_efdData,
        const uint8_t* const i_spdBuffer,
        const size_t   i_spdBufferSize,
        const uint8_t i_dram_gen)
    {
        // Initialize DRAM gen consts
        const size_t SPD_SIZE = (i_dram_gen == SPD_DDR4_TYPE) ? SPD_DDR4_SIZE : SPD_DDR5_SIZE;
        const size_t EFD_MEMORY_SPACE_OFFSET_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                SPD_DDR4_EFD_MEMORY_SPACE_OFFSET_ADDR : SPD_DDR5_EFD_MEMORY_SPACE_OFFSET_ADDR;
        const size_t EFD_MEMORY_SPACE_SIZE_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                SPD_DDR4_EFD_MEMORY_SPACE_SIZE_ADDR : SPD_DDR5_EFD_MEMORY_SPACE_SIZE_ADDR;
        const size_t EFD_COUNT_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                                      SPD_DDR4_EFD_COUNT_ADDR : SPD_DDR5_EFD_COUNT_ADDR;
        const size_t EFD_META_DATA_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                                          SPD_DDR4_EFD_META_DATA_ADDR : SPD_DDR5_EFD_META_DATA_ADDR;
        const size_t DMB_MFG_ID_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                                       SPD_DDR4_DMB_DMB_MFG_ID_ADDR : SPD_DDR5_DMB_DMB_MFG_ID_ADDR;
        const size_t DMB_REVISION_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                                         SPD_DDR4_DMB_REVISION_ADDR : SPD_DDR5_DMB_REVISION_ADDR;
        const size_t SUPPORTED_HOST_SPEEDS_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                SPD_DDR4_SUPPORTED_HOST_SPEEDS_ADDR : SPD_DDR5_SUPPORTED_HOST_SPEEDS_ADDR;
        const size_t EFD_FREQUENCY_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                                          EFD_DDR4_FREQUENCY_ADDR : EFD_DDR5_FREQUENCY_ADDR;
        const size_t EFD_MRANK_ADDR = (i_dram_gen == SPD_DDR4_TYPE) ?
                                      EFD_DDR4_MRANK_ADDR : EFD_DDR5_MRANK_ADDR;
        const size_t EFD_ASSUMED_MAX_BYTE_SIZE = (i_dram_gen == SPD_DDR4_TYPE) ?
                SPD_DDR4_EFD_ASSUMED_MAX_BYTE_SIZE : SPD_DDR5_EFD_ASSUMED_MAX_BYTE_SIZE;


        FAPI_DBG("ddr4_ddr5_get_efd: enter");

        // Initialize the error flag
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        // The variable round up.  These variables MUST come before any call
        // to FAPI_ASSERT, FAPI_TRY and 'goto fapi_try_exit'.
        uint64_t l_efdMemorySpaceOffset{0}; // The EFD memory location
        uint64_t l_efdMemorySpaceSize{0};  // The EFD size of the EFD mem space
        uint16_t l_efdCount{0};         // The number of EFDs
        size_t l_efdSize{0};            // The size of an EFD, not EFD meta data
        uint16_t l_dmbMfgId{0};         // The DMB manufacture ID
        uint8_t l_dmb_revision{0};
        uint16_t l_freqMask{0};         // The frequency mask as found in EFD
        uint8_t l_rankMask{0};          // The rank mask as found in EFD
        size_t ii{0};                   // A loop index
        // Pointer the beginning of the EFD meta data
        const uint8_t* l_efdMetaDataPtr(nullptr);
        // Pointer the beginning of the EFD block
        const uint8_t* l_efdDataPtr(nullptr);
        // Pointer to an individual EFD meta data
        const uint8_t* l_efdMetaDataNptr(nullptr);
        // Pointer to an individual EFD
        const uint8_t* l_efdDataNptr(nullptr);
        // Host Interface Supported Speeds field
        uint16_t l_supportedSpeeds(0);
        bool l_planar_config = is_planar_config(i_spdBuffer[SPD_MODULE_TYPE_ADDR]);

        // Fill in a data buffer for FFDC purposes that contains
        //  the first 8 bytes from the SPD (freq,rank,channel,dimms)
        uint64_t l_ffdc_EFD[MAX_EFD_FFDC];
        memset( l_ffdc_EFD, 0, sizeof(l_ffdc_EFD) );

        // On initial call, with nullptr for o_efdData, return the maximum size
        // for the EFD.  Will verify, on subsequent call, that the returned size
        // is in fact large enough to hold the EFD data.
        // Immediately setting the maximum size will expedite the code, not
        // forcing caller to go thru a lot of code, twice, to verify size.
        if ( nullptr == o_efdData ) // just return size
        {
            io_vpdInfo.iv_size = EFD_ASSUMED_MAX_BYTE_SIZE;
            FAPI_INF ("ddr4_ddr5_get_efd: Caller passed in an EFD data nullptr, so "
                      "returning size = %d so caller can allocate space for "
                      "EFD data",
                      io_vpdInfo.iv_size);

            goto fapi_try_exit;
        }


        //// First, set and validate all the variables necessary to retrieve
        //// data from the SPD, EFD meta data and the EFD memory space/block

        // From previous assert, buffer size is large enough to contain DDR4 and DDR5
        FAPI_DBG ( "ddr4_ddr5_get_efd: SPD DDR type 0x%02X size = %d, SPD buffer size = %d",
                   i_dram_gen, SPD_SIZE, i_spdBufferSize);

        // Sanity check that we're not a DDR5 planar SPD since this is not supported
        FAPI_ASSERT( !( (i_dram_gen == SPD_DDR5_TYPE) && l_planar_config ),
                     fapi2::DDIMM_GET_EFD_MEMORY_CONFIG_UNSUPPORTED().
                     set_DDR_TYPE(static_cast<uint32_t>(i_spdBuffer[SPD_MEM_TYPE_ADDR])).
                     set_PLANAR_CONFIG(l_planar_config).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target),
                     "ddr4_ddr5_get_efd: DDR type 0x%02X and planar memory config "
                     "combination is not supported.",
                     i_dram_gen );

        /// Get the EFD memory space offset (8 bytes)
        // The address where the EFD memory space is located at within the
        // SPD buffer
        l_efdMemorySpaceOffset = *reinterpret_cast<const uint64_t*>
                                 (&i_spdBuffer[EFD_MEMORY_SPACE_OFFSET_ADDR]);
        // Swap endianess to host format.
        l_efdMemorySpaceOffset = le64toh(l_efdMemorySpaceOffset);

        FAPI_DBG ("ddr4_ddr5_get_efd: EFD memory space location = %d",
                  l_efdMemorySpaceOffset);

        /// Sanity check the EFD memory space offset.
        // Make sure the EFD memory space is not within the SPD DDR4/DDR5 memory
        // space. The EFD memory space cannot share the same memory space as
        // the SPD base config or module specific config.
        FAPI_ASSERT( (l_efdMemorySpaceOffset >= SPD_SIZE),
                     fapi2::DDIMM_GET_EFD_EFD_MEMORY_SPACE_OFFSET_ERROR().
                     set_EFD_MEMORY_SPACE_OFFSET(l_efdMemorySpaceOffset).
                     set_BASE_MEMORY_SIZE(static_cast<uint32_t>(SPD_SIZE)).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(static_cast<uint32_t>(io_vpdInfo.iv_vpd_type)).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: EFD memory space offset = %d resides "
                     "within the SPD base+module memory size = %d. These two cannot "
                     "share the same meory space.",
                     l_efdMemorySpaceOffset,
                     SPD_SIZE );

        /// Get and convert the EFD's memory space size exponential factor
        // Convert to the actual size of the EFD's memory space.
        // The EFD memory space size's exponential factor is 8 bytes.
        l_efdMemorySpaceSize = calculateEfdMemorySpaceSize(
                                   i_spdBuffer[EFD_MEMORY_SPACE_SIZE_ADDR],
                                   is_planar_config(i_spdBuffer[SPD_MODULE_TYPE_ADDR]));

        FAPI_DBG ("ddr4_ddr5_get_efd: EFD memory space size factor = %d, "
                  "converted to EFD memory space size = %d ",
                  static_cast<uint32_t>
                  (i_spdBuffer[EFD_MEMORY_SPACE_SIZE_ADDR] &
                   SPD_EFD_MEMORY_SPACE_SIZE_MASK),
                  l_efdMemorySpaceSize);

        // If the memory space is 0, then calculating the EFD memory
        // space size failed.
        FAPI_ASSERT( l_efdMemorySpaceSize,
                     fapi2::DDIMM_GET_EFD_EFD_MEMORY_SIZE_MAPPING_ERROR().
                     set_EFD_MEMORY_SPACE_MAPPING_VALUE
                     (static_cast<uint32_t>
                      (i_spdBuffer[EFD_MEMORY_SPACE_SIZE_ADDR])).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(static_cast<uint32_t>(io_vpdInfo.iv_vpd_type)).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: Mapping unsuccessful for EFD space "
                     "size factor = 0x%0.2X",
                     i_spdBuffer[EFD_MEMORY_SPACE_SIZE_ADDR] );

        /// Sanity check the EFD memory space offset + EFD memory space size.
        // Make sure the size of the SPD buffer is large enough to contain
        // the EFD memory space located at the EFD memory space offset.
        // From previous assert, the EFD memory space offset is at the
        // the end of the DDR4 or DDR5 SPD data.
        FAPI_ASSERT( (i_spdBufferSize >=
                      (l_efdMemorySpaceOffset + l_efdMemorySpaceSize)),
                     fapi2::DDIMM_GET_EFD_EFD_MEMORY_SPACE_SIZE_ERROR().
                     set_EFD_MEMORY_SPACE_OFFSET(l_efdMemorySpaceOffset).
                     set_EFD_MEMORY_SPACE_SIZE(l_efdMemorySpaceSize).
                     set_VPD_BUFFER_SIZE(i_spdBufferSize).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(static_cast<uint32_t>(io_vpdInfo.iv_vpd_type)).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: SPD buffer size = %d is insufficient to "
                     "accommodate the EFD memory space size = %d at "
                     "offset = %d for DDR type 0x%02X; a minimum SPD buffer needed = %d",
                     i_spdBufferSize,
                     l_efdMemorySpaceSize,
                     l_efdMemorySpaceOffset,
                     i_dram_gen,
                     ( l_efdMemorySpaceOffset + l_efdMemorySpaceSize ) );

        /// Get the number of EFDs contained within the EFD memory space.
        // The number of EFDs value is 2 bytes.
        l_efdCount = *reinterpret_cast<const uint16_t*>
                     (&i_spdBuffer[EFD_COUNT_ADDR]);
        // Swap endianess to host format.
        l_efdCount = le16toh(l_efdCount);
        // Extract the number of EFDs
        l_efdCount &= SPD_EFD_COUNT_MASK;

        FAPI_DBG ("ddr4_ddr5_get_efd: The number of EFDs = %d", l_efdCount);

        /// Sanity check the number of EFDs extracted.
        // Make sure there is at least one EFD to work with
        FAPI_ASSERT( (l_efdCount),
                     fapi2::DDIMM_GET_EFD_NUMBER_OF_EFD_IS_ZERO().
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(static_cast<uint32_t>(io_vpdInfo.iv_vpd_type)).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: The number of EFDs is 0. Need at least one");

        // The size of the EFD can be extrapolated from the first EFD.
        // Use the ending block info (byte 2) from EFD[0] to determine size.
        // Mask out the EFD block multiplier value and multiply
        // that with the incremental block byte size
        // This value should be constant for all EFDs
        l_efdSize = (i_spdBuffer[EFD_META_DATA_ADDR +
                                 SPD_EFD_META_DATA_EFD_BYTE_2_OFFSET] &
                     SPD_EFD_META_DATA_EFD_BLOCK_OFFSET_MASK) *
                    SPD_EFD_INCREMENTAL_BLOCK_BYTE_SIZE;

        FAPI_DBG ("ddr4_ddr5_get_efd: The EFD data block size = %d", l_efdSize);

        // Verify that io_vpdInfo.iv_size is large enough to
        // hold the EFD data. If not, then assert.
        FAPI_ASSERT( (io_vpdInfo.iv_size >= l_efdSize),
                     fapi2::DDIMM_GET_EFD_INADEQUATE_EFD_BUFFER_SIZE().
                     set_EFD_BUFFER_SIZE(io_vpdInfo.iv_size).
                     set_EFD_BLOCK_SIZE(l_efdSize).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(static_cast<uint32_t>(io_vpdInfo.iv_vpd_type)).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: EFD block size = %d exceeds outgoing buffer "
                     "size = %d. Code const EFD_ASSUMED_MAX_BYTE_SIZE = %d "
                     "needs a size increase to match the EFD block size",
                     l_efdSize,
                     io_vpdInfo.iv_size,
                     static_cast<uint32_t>(EFD_ASSUMED_MAX_BYTE_SIZE));

        //// Secondly, get/confirm and set as much outgoing data as possible

        /// Set the outgoing to DDR4 or DDR5
        io_vpdInfo.iv_ddr_mode = i_dram_gen;

        FAPI_DBG ("ddr4_ddr5_get_efd: DDR mode = 0x%.2X",
                  io_vpdInfo.iv_ddr_mode);

        /// Confirm that the DMB manufacturer ID of the SPD data
        /// is what is expected
        // Get the DMB manufacturer ID - 2 bytes
        l_dmbMfgId = *reinterpret_cast<const uint16_t*>
                     (&i_spdBuffer[DMB_MFG_ID_ADDR]);
        // Swap endianess to host format.
        l_dmbMfgId = le16toh(l_dmbMfgId);

        FAPI_DBG ( "ddr4_ddr5_get_efd: SPD DMB manufacturer ID = 0x%.4X", l_dmbMfgId);

        // Confirm the DMB manufacturer ID value is what is expected
        FAPI_ASSERT( ( (i_dram_gen == SPD_DDR4_TYPE) && check_ddr4_valid_mfg_id(l_dmbMfgId) ) ||
                     ( (i_dram_gen == SPD_DDR5_TYPE) && check_ddr5_valid_mfg_id(l_dmbMfgId) ),
                     fapi2::DDIMM_GET_EFD_UNSUPPORTED_DMB_MFG_ID().
                     set_DMB_MFG_ID(static_cast<uint32_t>(l_dmbMfgId)).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(io_vpdInfo.iv_vpd_type).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: SPD DMB manufacturer ID 0x%.4X is not of "
                     "expected DMB manufacturer IDs MCHP DDR4: 0x%.4X, "
                     "IBM DDR4: 0x%.4X, IBM DDR5: 0x%.4X",
                     l_dmbMfgId,
                     SPD_DDR4_DMB_MFG_ID_MICROCHIP,
                     SPD_DDR4_DMB_MFG_ID_IBM,
                     SPD_DDR5_DMB_MFG_ID_IBM);

        // Set the outgoing DMB manufacturer ID
        io_vpdInfo.iv_dmb_mfg_id = l_dmbMfgId;

        FAPI_DBG ( "ddr4_ddr5_get_efd: SPD DMB manufacturer ID = 0x%.4X",
                   io_vpdInfo.iv_dmb_mfg_id);

        l_dmb_revision = *reinterpret_cast<const uint8_t*>(&i_spdBuffer[DMB_REVISION_ADDR]);

        // Confirm that the DMB revision is what is expected
        FAPI_ASSERT( ( (i_dram_gen == SPD_DDR4_TYPE) && check_ddr4_valid_dmb_revision(l_dmbMfgId, l_dmb_revision) ) ||
                     ( (i_dram_gen == SPD_DDR5_TYPE) && check_ddr5_valid_dmb_revision(l_dmbMfgId, l_dmb_revision) ),
                     fapi2::DDIMM_GET_EFD_UNSUPPORTED_DMB_REVISION().
                     set_DMB_REVISION(static_cast<uint32_t>
                                      (l_dmb_revision)).
                     set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                     set_VPD_TYPE(io_vpdInfo.iv_vpd_type).
                     set_DDR_TYPE(static_cast<uint32_t>
                                  (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                     "ddr4_ddr5_get_efd: SPD DMB revision 0x%.2X is not an expected revision: "
                     "IBM expected: DDR4 0x%.2X, DDR5 0x%.2X "
                     "MCHP expected: 0x%.2X or 0x%.2X or 0x%.2X or 0x%.2X",
                     l_dmb_revision,
                     SPD_DDR4_EXPECTED_DMB_REVISION_IBM,
                     SPD_DDR5_EXPECTED_DMB_REVISION_0_IBM,
                     SPD_DDR4_EXPECTED_DMB_REVISION_0_MICROCHIP,
                     SPD_DDR4_EXPECTED_DMB_REVISION_A0_MICROCHIP,
                     SPD_DDR4_EXPECTED_DMB_REVISION_A1_MICROCHIP,
                     SPD_DDR4_EXPECTED_DMB_REVISION_B0_MICROCHIP);

        // Set the outgoing DMB revision
        io_vpdInfo.iv_dmb_revision = l_dmb_revision;

        FAPI_DBG ( "ddr4_ddr5_get_efd: SPD DMB revision = 0x%.2X",
                   io_vpdInfo.iv_dmb_revision);


        //// Thirdly, confirm user input is valid and map user
        //// input to usable data

        /// Get the EFD frequency
        // Look up the bit mask for the given frequency
        // No need to swap endian, already in host format
        l_freqMask = (i_dram_gen == SPD_DDR4_TYPE) ?
                     ddr4FrequencyToBitMask(io_vpdInfo.iv_omi_freq_mhz) :
                     ddr5FrequencyToBitMask(io_vpdInfo.iv_omi_freq_mhz);

        FAPI_DBG ( "ddr4_ddr5_get_efd: Caller supplied frequency = %d",
                   io_vpdInfo.iv_omi_freq_mhz );

        // Confirm that mapping the frequency succeeded
        if (!l_freqMask)
        {
            const uint16_t FREQ0 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_0 : DDR5_FREQ_VAL_0;
            const uint16_t FREQ1 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_1 : DDR5_FREQ_VAL_1;
            const uint16_t FREQ2 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_2 : DDR5_FREQ_VAL_2;
            const uint16_t FREQ3 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_3 : 0;
            const uint16_t FREQ4 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_4 : 0;
            const uint16_t FREQ5 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_5 : 0;
            const uint16_t FREQ6 = (i_dram_gen == SPD_DDR4_TYPE) ? DDR4_FREQ_VAL_6 : 0;

            // If no value for freq, then mapping of frequency was unsuccessful
            // Note we don't want to produce FFDC if the ffdc_enabled flag is not set
            // i.e. if we're just probing the EFD for its supported frequencies
            FAPI_ASSERT( ( !io_vpdInfo.iv_is_config_ffdc_enabled ),
                         fapi2::DDIMM_GET_EFD_UNSUPPORTED_FREQUENCY().
                         set_UNSUPPORTED_FREQ(static_cast<uint32_t>
                                              (io_vpdInfo.iv_omi_freq_mhz)).
                         set_FREQ0(static_cast<uint32_t>(FREQ0)).
                         set_FREQ1(static_cast<uint32_t>(FREQ1)).
                         set_FREQ2(static_cast<uint32_t>(FREQ2)).
                         set_FREQ3(static_cast<uint32_t>(FREQ3)).
                         set_FREQ4(static_cast<uint32_t>(FREQ4)).
                         set_FREQ5(static_cast<uint32_t>(FREQ5)).
                         set_FREQ6(static_cast<uint32_t>(FREQ6)).
                         set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                         set_VPD_TYPE(io_vpdInfo.iv_vpd_type).
                         set_DDR_TYPE(static_cast<uint32_t>
                                      (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                         "ddr4_ddr5_get_efd: Frequency %d is not supported",
                         io_vpdInfo.iv_omi_freq_mhz );

            // If not asserting, still must exit .. can't continue with bad data
            FAPI_INF("ddr4_ddr5_get_efd: Frequency %d not supported. Valid "
                     "values are %d, %d, %d, %d, %d, %d or %d",
                     io_vpdInfo.iv_omi_freq_mhz, FREQ0, FREQ1,
                     FREQ2, FREQ3, FREQ4, FREQ5, FREQ6);

            FAPI_TRY_NO_TRACE(fapi2::FAPI2_RC_FALSE);
        }

        FAPI_DBG ("ddr4_ddr5_get_efd: Caller supplied frequency = %d, "
                  "converted to frequency bit value mask = 0x%.4X",
                  io_vpdInfo.iv_omi_freq_mhz, l_freqMask);

        /// Get the EFD MRANK
        // Look up the bit mask for the given MRANK
        l_rankMask = ddrMasterRankToBitMask( io_vpdInfo.iv_rank);

        // Confirm that mapping the master rank succeeded
        if ( !l_rankMask)
        {
            // If no value for MRANK, then mapping of MRANK was unsuccessful
            // Note we don't want to produce FFDC if the ffdc_enabled flag is not set
            // i.e. if we're just probing the EFD for its supported frequencies
            FAPI_ASSERT( ( !io_vpdInfo.iv_is_config_ffdc_enabled ),
                         fapi2::DDIMM_GET_EFD_UNSUPPORTED_RANK().
                         set_UNSUPPORTED_RANK(static_cast<uint32_t>
                                              (io_vpdInfo.iv_rank)).
                         set_RANK0(static_cast<uint32_t>(DDR_MR_VAL_0)).
                         set_RANK1(static_cast<uint32_t>(DDR_MR_VAL_1)).
                         set_RANK2(static_cast<uint32_t>(DDR_MR_VAL_2)).
                         set_RANK3(static_cast<uint32_t>(DDR_MR_VAL_3)).
                         set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                         set_VPD_TYPE(io_vpdInfo.iv_vpd_type).
                         set_DDR_TYPE(static_cast<uint32_t>
                                      (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                         "ddr4_ddr5_get_efd: Master rank %d is not supported. ",
                         io_vpdInfo.iv_rank );

            // If not asserting, still must exit .. can't continue with bad data
            FAPI_INF("ddr4_ddr5_get_efd: MRANK %d not supported. "
                     "Valid values are %d, %d, %d, or %d",
                     io_vpdInfo.iv_rank,
                     static_cast<uint32_t>(DDR_MR_VAL_0),
                     static_cast<uint32_t>(DDR_MR_VAL_1),
                     static_cast<uint32_t>(DDR_MR_VAL_2),
                     static_cast<uint32_t>(DDR_MR_VAL_3) );

            FAPI_TRY_NO_TRACE(fapi2::FAPI2_RC_FALSE);
        }

        FAPI_DBG ("ddr4_ddr5_get_efd: Caller supplied mrank = %d, "
                  "converted to mrank bit value mask = 0x%.2X",
                  io_vpdInfo.iv_rank, l_rankMask);


        //// Fourthly, find the EFD that matches the given frequency
        //// and mrank

        // Check the master list of supported frequencies before walking
        //  through the EFDs
        l_supportedSpeeds = *reinterpret_cast<const uint16_t*>
                            (i_spdBuffer + SUPPORTED_HOST_SPEEDS_ADDR);
        l_supportedSpeeds = le16toh(l_supportedSpeeds);

        if (!(l_freqMask & l_supportedSpeeds))
        {
            // Note we don't want to produce FFDC if the ffdc_enabled flag is not set
            // i.e. if we're just probing the EFD for its supported frequencies
            FAPI_ASSERT( !io_vpdInfo.iv_is_config_ffdc_enabled,
                         fapi2::DDIMM_UNSUPPORTED_FREQUENCY().
                         set_UNSUPPORTED_FREQ(static_cast<uint32_t>
                                              (io_vpdInfo.iv_omi_freq_mhz)).
                         set_SUPPORTED_FREQS(l_supportedSpeeds).
                         set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                         set_VPD_TYPE(io_vpdInfo.iv_vpd_type).
                         set_DDR_TYPE(static_cast<uint32_t>
                                      (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                         "Invalid frequency for this DIMM - request=%d, supported mask=%.4X",
                         io_vpdInfo.iv_omi_freq_mhz, l_supportedSpeeds );

            // If unable to collect FFDC and assert, at least trace out and exit with false
            FAPI_INF ("ddr4_ddr5_get_efd: Unsupported frequency %d (frequency bit mask = 0x%.4X, "
                      "supported mask = 0x%.4X)",
                      io_vpdInfo.iv_omi_freq_mhz, l_freqMask, l_supportedSpeeds);

            FAPI_TRY_NO_TRACE(fapi2::FAPI2_RC_FALSE);
        }

        // Point to the beginning of the EFD meta data, AKA EFD[0] meta data.
        l_efdMetaDataPtr = i_spdBuffer + EFD_META_DATA_ADDR;

        // Point to the beginning of the EFD data AKA EFD[0] data
        l_efdDataPtr = i_spdBuffer + l_efdMemorySpaceOffset;

        FAPI_DBG ("ddr4_ddr5_get_efd: Looking to match caller supplied frequency = "
                  "%d (mapped to 0x%.4X) and caller supplied mrank = "
                  "%d (mapped to 0x%.2X)",
                  io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                  io_vpdInfo.iv_rank, l_rankMask);

        // Iterate over the EFDs looking for a match
        ii = 0;

        for (; ii < l_efdCount; ++ii)
        {
            // First, point to the Nth EFD meta data, where N is 0-based.  The
            // meta data is where the data about the actual EFD's block
            // offset preside.
            l_efdMetaDataNptr = l_efdMetaDataPtr +
                                (ii * SPD_EFD_META_DATA_BYTE_SIZE);

            // Secondly, point to the Nth EFD data, where N is 0-based.
            // The Nth EFD data is a multiple of the EFD size from the
            // beginning of the EFD data
            l_efdDataNptr = l_efdDataPtr + (ii * l_efdSize);

            // Sanity check that the EFD size is within the EFD memory space
            FAPI_ASSERT( ( (l_efdMemorySpaceOffset + l_efdMemorySpaceSize) >=
                           (l_efdMemorySpaceOffset + (ii * l_efdSize) + l_efdSize) ),
                         fapi2::DDIMM_GET_EFD_EFD_BLOCK_SIZE_IS_OUT_OF_BOUNDS().
                         set_EFD_MEMORY_SPACE_OFFSET(l_efdMemorySpaceOffset).
                         set_EFD_MEMORY_SPACE_SIZE(l_efdMemorySpaceSize).
                         set_EFD_BLOCK(ii).
                         set_EFD_BLOCK_SIZE(l_efdSize).
                         set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                         set_VPD_TYPE(static_cast<uint32_t>
                                      (io_vpdInfo.iv_vpd_type)).
                         set_DDR_TYPE(static_cast<uint32_t>
                                      (i_spdBuffer[SPD_MEM_TYPE_ADDR])),
                         "EFD[%d] at location = %d plus EFD size = %d is "
                         "outside the bounds of the EFD memory space = %d",
                         ii,
                         l_efdMemorySpaceOffset + (ii * l_efdSize),
                         l_efdSize,
                         (l_efdMemorySpaceOffset + l_efdMemorySpaceSize) );

            // From previous assert, we know there is enough buffer to inspect
            // the EFD.

            // Copy data into FFDC buffer in case we find no matches
            if( ii < MAX_EFD_FFDC )
            {
                memcpy( &(l_ffdc_EFD[ii]),
                        l_efdDataNptr,
                        sizeof(l_ffdc_EFD[ii]) );
            }

            // Get the EFD's frequency bit mask
            uint16_t l_efdFreqMask = *reinterpret_cast<const uint16_t*>
                                     (&l_efdDataNptr[EFD_FREQUENCY_ADDR]);
            // Swap endianess to host format.
            l_efdFreqMask = le16toh(l_efdFreqMask);

            bool l_is_planar = is_planar_config(i_spdBuffer[SPD_MODULE_TYPE_ADDR]);
            uint32_t l_ocmb_pos = 0;
            uint8_t l_slot_supp_flag = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_ocmbFapi2Target, l_ocmb_pos) );

            // For planar EFD byte 15, processor slot supported is bit 0/1/2/3 = OCMB_CHIP position 7/6/5/4
            l_slot_supp_flag = 1 << l_ocmb_pos;

            // If the 'is implemented flag' is true for the EFD,
            // AND if the EFD frequency mask contains the frequency mask we are looking for
            // AND the EFD mrank bitmap includes the mrank we are looking for
            // AND if we're on a planar config:
            //     if the EFD slot supported flag is set for the OCMB_CHIP's position
            //     if the EFD DIMM count supported matches our DIMM config
            //     if the EFD total ranks on DIMM0+DIMM1 matches our DIMM config
            //     if the EFD DIMM type supported matches our DIMM config
            // then copy the EFD block for the caller.
            // TODO: Zen:MST-1690 Add in part/revision specific lookup if we need it
            const fapi2::buffer<uint8_t> l_efd_ddr4_mrank(l_efdDataNptr[EFD_MRANK_ADDR]);
            const uint8_t l_total_dimms_supported = (l_efd_ddr4_mrank.getBit<DDR_DROPS_BIT>()) ? 2 : 1;
            uint8_t l_total_ranks_supported = 0;
            l_efd_ddr4_mrank.extractToRight<DDR_TOTAL_MR_START, DDR_TOTAL_MR_LEN>(l_total_ranks_supported);

            if ( (l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_3_OFFSET] &
                  SPD_EFD_META_DATA_EFD_IS_IMPLEMENTED_MASK) &&
                 (l_efdFreqMask & l_freqMask)                               &&
                 (l_efdDataNptr[EFD_MRANK_ADDR] & l_rankMask) &&
                 ( !l_is_planar ||
                   ( (l_efdDataNptr[EFD_DDR4_CHANNEL_SUPPORT_ADDR] & l_slot_supp_flag) &&
                     (l_total_dimms_supported == io_vpdInfo.iv_dimm_count) &&
                     (l_total_ranks_supported == (io_vpdInfo.iv_total_ranks_dimm0 + io_vpdInfo.iv_total_ranks_dimm1)) &&
                     (l_efdDataNptr[EFD_DDR4_DIMM_SUPPORTED_ADDR] == io_vpdInfo.iv_dimm_type) ) ) )
            {
                // io_vpdInfo.iv_size and EFD block size compatibility
                // have been verified above

                // Copy the EFD data, that matched the given criteria,
                // to the out going buffer
                memcpy(o_efdData, l_efdDataNptr, l_efdSize);

                // Set the outgoing size to the actual size, it could
                // be different, but no more than what was given.
                io_vpdInfo.iv_size = l_efdSize;

                // Set the outgoing EFD function type
                io_vpdInfo.iv_efd_type =
                    l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_1_OFFSET] &
                    SPD_EFD_META_DATA_EFD_FUNCTION_TYPE_MASK;

                FAPI_INF ("ddr4_ddr5_get_efd: EFD[%d] block matched frequency %d "
                          "(frequency bit mask 0x%.4X) and mrank %d "
                          "(mrank bit mask 0x%.2X), efd size = %d",
                          ii,
                          io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                          io_vpdInfo.iv_rank, l_rankMask,
                          l_efdSize);

                if (l_is_planar)
                {
                    FAPI_INF ("ddr4_ddr5_get_efd: EFD[%d] block also matched planar fields "
                              "total ranks on DIMM0 %d, total ranks on DIMM1 %d, "
                              "Channel number %d, DIMM count %d, and type 0x%02X",
                              ii,
                              io_vpdInfo.iv_total_ranks_dimm0, io_vpdInfo.iv_total_ranks_dimm1,
                              l_ocmb_pos, io_vpdInfo.iv_dimm_count, io_vpdInfo.iv_dimm_type);
                }

                break; // exit stage left, we are done
            }  // end if ((l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_ ...

            // This EFD is not a match, send trace stating so
            FAPI_INF ("ddr4_ddr5_get_efd: Match failed for EFD[%d], freq bit mask "
                      "= 0x%.4X, rank bit mask = 0x%.2X, EFD memory location "
                      "= %d, EFD size = %d, is implemented flag = %s",
                      ii,
                      l_efdFreqMask,
                      l_efdDataNptr[EFD_MRANK_ADDR],
                      (l_efdMemorySpaceOffset + (ii * l_efdSize)),
                      l_efdSize,
                      ((l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_3_OFFSET] &
                        SPD_EFD_META_DATA_EFD_IS_IMPLEMENTED_MASK)
                       ? "true" : "false" ) );

            if (l_is_planar)
            {
                FAPI_INF ("ddr4_ddr5_get_efd: and planar fields "
                          "total ranks on DIMM0 %d, total ranks on DIMM1 %d, "
                          "Channel number %d, DIMM count %d, and type 0x%02X (supported type = 0x%02X)",
                          io_vpdInfo.iv_total_ranks_dimm0, io_vpdInfo.iv_total_ranks_dimm1,
                          l_ocmb_pos, io_vpdInfo.iv_dimm_count, io_vpdInfo.iv_dimm_type, l_efdDataNptr[EFD_DDR4_DIMM_SUPPORTED_ADDR]);
            }
        }  // end for (; ii < l_efdCount; ++ii)

        if (ii >= l_efdCount)
        {
            // Did not find an EFD to match frequency and mrank criteria
            // Collect FFDC and assert if iv_is_config_ffdc_enabled is true
            // Note we don't want to produce FFDC if the ffdc_enabled flag is not set
            // i.e. if we're just probing the EFD for its supported frequencies
            FAPI_ASSERT( ( !io_vpdInfo.iv_is_config_ffdc_enabled ),
                         fapi2::DDIMM_GET_EFD_EFD_NOT_FOUND().
                         set_FREQUENCY(io_vpdInfo.iv_omi_freq_mhz).
                         set_FREQUENCY_MAPPED_VALUE
                         (static_cast<uint32_t>(l_freqMask)).
                         set_MRANK(io_vpdInfo.iv_rank).
                         set_MRANK_MAPPED_VALUE
                         (static_cast<uint32_t>(l_rankMask)).
                         set_OCMB_CHIP_TARGET(i_ocmbFapi2Target).
                         set_VPD_TYPE(static_cast<uint32_t>
                                      (io_vpdInfo.iv_vpd_type)).
                         set_DDR_TYPE(static_cast<uint32_t>
                                      (i_spdBuffer[SPD_MEM_TYPE_ADDR])).
                         set_EFD_METADATA0(l_ffdc_EFD[0]).
                         set_EFD_METADATA1(l_ffdc_EFD[1]).
                         set_EFD_METADATA2(l_ffdc_EFD[2]).
                         set_EFD_METADATA3(l_ffdc_EFD[3]).
                         set_EFD_METADATA4(l_ffdc_EFD[4]).
                         set_EFD_METADATA5(l_ffdc_EFD[5]).
                         set_EFD_METADATA6(l_ffdc_EFD[6]).
                         set_EFD_METADATA7(l_ffdc_EFD[7]).
                         set_EFD_METADATA8(l_ffdc_EFD[8]).
                         set_EFD_METADATA9(l_ffdc_EFD[9]).
                         set_EFD_METADATA10(l_ffdc_EFD[10]).
                         set_EFD_METADATA11(l_ffdc_EFD[11]).
                         set_EFD_METADATA12(l_ffdc_EFD[12]).
                         set_EFD_METADATA13(l_ffdc_EFD[13]).
                         set_EFD_METADATA14(l_ffdc_EFD[14]).
                         set_EFD_METADATA15(l_ffdc_EFD[15]).
                         set_EFD_METADATA16(l_ffdc_EFD[16]).
                         set_EFD_METADATA17(l_ffdc_EFD[17]).
                         set_EFD_METADATA18(l_ffdc_EFD[18]).
                         set_EFD_METADATA19(l_ffdc_EFD[19]).
                         set_EFD_METADATA20(l_ffdc_EFD[20]).
                         set_EFD_METADATA21(l_ffdc_EFD[21]).
                         set_EFD_METADATA22(l_ffdc_EFD[22]).
                         set_EFD_METADATA23(l_ffdc_EFD[23]).
                         set_EFD_METADATA24(l_ffdc_EFD[24]).
                         set_EFD_METADATA25(l_ffdc_EFD[25]).
                         set_EFD_METADATA26(l_ffdc_EFD[26]).
                         set_EFD_METADATA27(l_ffdc_EFD[27]).
                         set_EFD_METADATA28(l_ffdc_EFD[28]).
                         set_EFD_METADATA29(l_ffdc_EFD[29]).
                         set_EFD_METADATA30(l_ffdc_EFD[30]).
                         set_EFD_METADATA31(l_ffdc_EFD[31]),
                         "ddr4_ddr5_get_efd: ALL EFDs have been exhausted.  NO "
                         "match for frequency %d (frequency bit mask 0x%.4X) "
                         "and mrank %d (mrank bit mask 0x%.2X), or "
                         "there was a match but the block is not implemented.",
                         io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                         io_vpdInfo.iv_rank, l_rankMask);

            // If unable to collect FFDC and assert, at least trace out error
            // and exit with false
            FAPI_INF ("ddr4_ddr5_get_efd: ALL EFDs have been exhausted.  NO match "
                      "for frequency = %d (frequency bit mask = 0x%.4X) and "
                      "mrank = %d (mrank bit mask = 0x%.2X), or "
                      "there was a match but the block is not implemented.",
                      io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                      io_vpdInfo.iv_rank, l_rankMask);

            FAPI_TRY_NO_TRACE(fapi2::FAPI2_RC_FALSE);
        }

    fapi_try_exit:

        FAPI_DBG("ddr4_ddr5_get_efd: exiting with %s",
                 ( (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS) ?
                   "no errors" : "errors" ));
        return fapi2::current_err;

    }  // end ddimm_get_efd

} //extern C
