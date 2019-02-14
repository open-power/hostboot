/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/ddimm_get_efd.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

/// SPD memory addressing constants
/// These offsets are relative to the start of the SPD
/// 0 based addressing
// Offset to the memory type (DDR4, etc) of the DDIMM.
// size is 1 byte: address 2
const size_t SPD_MEM_TYPE_ADDR = 2;
// Offset to the SPD's DMB manufacturer ID
// See SPD_DDR4_EXPECTED_DMB_MFG_ID below for the expected value for DDR4
// size is 2 bytes; address 198 - 199
const size_t SPD_DMB_DMB_MFG_ID_ADDR = 198;
// Offset to the SPD's DMB revision.
// See SPD_DDR4_EXPECTED_DMB_REVISION below for the expected value for DDR4
// size is 1 byte: address 200
const size_t SPD_DMB_REVISION_ADDR = 200;
// Offset to the EFD memory space/block offset.  The value, at this location,
// is where the EFD block data offset begins.
// size is 8 bytes: address 277 to 284
const size_t SPD_EFD_MEMORY_SPACE_OFFSET_ADDR = 277;
// Offset to the EFD's memory space size.  The value at this offset is used
// to calculate the actual EFD memory size (see calculateEfdMemorySpaceSize(..))
// size is 1 byte: address 285
// only bits 0 - 4 used (see following MASK const)
const size_t SPD_EFD_MEMORY_SPACE_SIZE_ADDR = 285;
// Bit mask to the EFD memory space size
// Bits 0 - 4: Valid values are 0 - 5; 0=1K, 1=2KB, 2=4KB, 3=8KB, 4=16KB, 5=32KB
const uint8_t SPD_EFD_MEMORY_SPACE_SIZE_MASK = 0x0F;
const uint8_t SPD_EFD_MEMORY_SPACE_SIZE_MAX_VALUE = 0x05;
// Offset to the number of all EFDs that is contained in the EFD memory space.
// The value at this offset is how many EFDs exists within the EFD memory space.
// size is 2 bytes; address 286 to 287
const size_t SPD_EFD_COUNT_ADDR = 286;
// Bit mask to the number of all EFDs
// Bits 0 - 5: Valid values are 0 - 63(0x003F)
const uint16_t SPD_EFD_COUNT_MASK = 0x003F;
// Offset to the EFD meta data within the SPD.
// size is 128 bytes; address 288 to 415; 32 EFD meta data's sized 4 bytes each
const size_t SPD_EFD_META_DATA_ADDR = 288;

/// SPD - EFD meta data constants
// Size of the EFD meta data's within the SPD
// size is 4 bytes
const size_t SPD_EFD_META_DATA_BYTE_SIZE = 4;

/// SPD - EFD meta data addressing constants.
/// These offsets are relative to the start of a given EFD meta data section,
/// located in the EFD meta data block, as describe in const
/// SPD_EFD_META_DATA_ADDR above
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
// Bits 7: Flag that indicates if an EFD, in the EFD memory space, is implemented
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
// is a, value found at SPD_EFD_MEMORY_SPACE_SIZE_ADDR is b, and x is 2
// also see SPD_EFD_MEMORY_SPACE_SIZE_ADDR and calculateEfdMemorySpaceSize(..)
const size_t EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE = 1024;

/// EFD - DDR4 memory addressing constants.
/// These offsets are relative to the start of the actual EFD block
/// as describe in const SPD_EFD_MEMORY_SPACE_OFFSET_ADDR above
/// 0 based addressing
// Offset to the DDR4's frequency within an individual EFD
// size is 2 bytes: address 0 - 1
const size_t EFD_DDR4_FREQUENCY_ADDR = 0;
// Offset to the DDR4's master rank data within an individual EFD
// size is 1 byte: address 2
const size_t EFD_DDR4_MASTER_RANK_ADDR = 2;

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
const uint16_t SPD_DDR4_EXPECTED_DMB_MFG_ID = 0x2980;
// SPD - DDR4 expected value for the DMB revision.
// Currently at initial revision - revision 0
// size is 1 byte
const uint8_t SPD_DDR4_EXPECTED_DMB_REVISION = 0x00;

/// Local enumerations
// * Bytes 205 and 206 of SPD and bytes 0 & 1 of EFD contain the frequency info.
enum DDR_FREQUENCY : uint16_t
{
    DDR4_FREQ_VAL_0 = 12800,
    DDR4_FREQ_VAL_1 = 14930,
    DDR4_FREQ_VAL_2 = 17060,
    DDR4_FREQ_VAL_3 = 19200,
    DDR4_FREQ_VAL_4 = 21330,
    DDR4_FREQ_VAL_5 = 23460,
    DDR4_FREQ_VAL_6 = 25600,

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
};

/// Local utilities
// @brief Maps the frequency numeric value to it's bit mask equivalent
//        Uses the enums in DDR_FREQUENCY above
//
// @param[in]  i_frequency, the frequency in numeric form
// @return the bit mask that represents given frequency if found, else 0
uint16_t ddrFrequencyToBitMask(const uint64_t i_frequency)
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
// @param[in]  i_exponentialFactor, the memory space 1KB exponential factor
// @return the calculated memory space size or 0 if error
uint64_t calculateEfdMemorySpaceSize(const uint8_t i_exponentialFactor)
{
    // The exponential factor is the exponent in the power of 2 equation -
    // 2^i_exponentialFactor.  '2^i_exponentialFactor' is how many 1KB memory
    // blocks the EFD contains.  To get the full size of the EFD, multiply
    // 2^i_exponentialFactor by 1KB (EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE).

    uint64_t retVal = 0;

    if (i_exponentialFactor <= SPD_EFD_MEMORY_SPACE_SIZE_MAX_VALUE)
    {
        // 1 << i_exponentialFactor - a quick way to do a power of 2
        retVal = EFD_EXPONENTIAL_BLOCK_MEMORY_SIZE * (1 << i_exponentialFactor);
    }

    return retVal;
};
extern "C"
{

/// ddr4_get_efd forward declaration
/// @brief Return the DDR4's EFD based on VPDInfo
///        This procedure explicitly returns the EFD data, associated with a
///        DDR4, that matches given frequency and master rank criteria.
///
/// @param[in]  i_ocmbFapi2Target, a valid fapi2 OCMB_CHIP target
/// @param[in]  io_vpdInfo, @see ddimm_get_efd
/// @param[out] o_efdData, @see ddimm_get_efd
/// @param[in]  i_spdBuffer, pointer to the DDR4 SPD data
/// @param[in]  i_spdBufferSize, size of the DDR4 SPD data
/// @note The size of blob may be less than io_vpdInfo.iv_size
/// @note If data is returned for o_efdData, it will be in little endian
/// @note Caller is responsible for allocating the buffers of o_efdData and
///       i_spdBuffer.  This procedure will NOT manage these buffers. This
///       procedure will only read/write to buffers, not allocate.
/// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode ddr4_get_efd(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&  i_ocmbFapi2Target,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpdInfo, // Can modify data
        uint8_t* const o_efdData,    // Don't change pointer but can modify data
        const uint8_t* const i_spdBuffer,  // Don't change pointer nor modify data
        size_t   i_spdBufferSize);   // Don't modify

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

        // Determine DDIMM type and do some sanity checks
        // SPD size must be large enough to gather the DDIMM type info
        FAPI_ASSERT( (i_spdBufferSize > SPD_MEM_TYPE_ADDR),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "SPD data size (%d) is insufficient to gather data from.",
                     i_spdBufferSize);

        // If working with a DDR4 then the SPD data size must
        // be at a minumum of what is required for a DDR4
        FAPI_ASSERT( ( (i_spdBuffer[SPD_MEM_TYPE_ADDR] == SPD_DDR4_TYPE) &&
                       (i_spdBufferSize >= SPD_DDR4_SIZE) ),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "Either memory type(0x%.2X) is not valid or size "
                     "of SPD data(%d) is insufficient for type",
                     i_spdBuffer[SPD_MEM_TYPE_ADDR],
                     i_spdBufferSize);

        FAPI_DBG ("ddimm_get_efd: working with a DDR4");

        // Call the explicit code for a DDR4
        FAPI_TRY(ddr4_get_efd( i_ocmbFapi2Target,
                               io_vpdInfo,
                               o_efdData,
                               i_spdBuffer,
                               i_spdBufferSize));
    fapi_try_exit:

        FAPI_DBG("ddimm_get_efd: exiting with %s",
                 ( (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS) ?
                   "no errors" : "errors" ));
        return fapi2::current_err;
    }

// ddr4_get_efd
    fapi2::ReturnCode ddr4_get_efd(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&  i_ocmbFapi2Target,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpdInfo,
        uint8_t* const o_efdData,
        const uint8_t* const i_spdBuffer,
        const size_t   i_spdBufferSize)
    {
        FAPI_DBG("ddr4_get_efd: enter");

        // Initialize the error flag
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        // The variable round up
        uint64_t l_efdMemorySpaceOffset{0}; // The EFD memory location
        uint64_t l_efdMemorySpaceSize{0};   // The EFD size of the EFD memory space
        uint16_t l_efdCount{0};             // The number EFDs
        size_t l_efdSize{0};                // The size of an EFD, not EFD meta data
        uint16_t l_dmbMfgId{0};             // The DMB manufacture ID
        uint16_t l_freqMask{0};             // The frequency mask as found in EFD
        uint8_t l_rankMask{0};              // The rank mask as found in EFD
        int ii{0};                          // A loop index
        const uint8_t* l_efdMetaDataPtr
        {
            nullptr
        };  // Pointer the beginning of the EFD meta data
        const uint8_t* l_efdDataPtr
        {
            nullptr
        };      // Pointer the beginning of the EFD block
        const uint8_t* l_efdMetaDataNptr
        {
            nullptr
        }; // Pointer to an individual EFD meta data
        const uint8_t* l_efdDataNptr
        {
            nullptr
        };     // Pointer to an individual EFD

        //// First, set all the variables necessary to retrieve data from
        //// the SPD, EFD meta data and the EFD memory space/block

        FAPI_DBG ( "ddr4_get_efd: SPD buffer size = %d, SPD DDR4 size = %d",
                   i_spdBufferSize, SPD_DDR4_SIZE);

        /// Sanity check the SPD buffer size.
        // Make sure the size of the SPD buffer is large enough to contain the
        // DDR4 SPD data. If not, can't reliably gather data from the buffer.
        FAPI_ASSERT( (i_spdBufferSize >= SPD_DDR4_SIZE),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: SPD buffer size = %d is insufficient to "
                     "gather data from, minimum required size is = %d",
                     i_spdBufferSize,
                     SPD_DDR4_SIZE );

        /// Get the EFD memory space offset (8 bytes)
        // The address where the EFD memory space is located at within the
        // SPD buffer
        l_efdMemorySpaceOffset = *reinterpret_cast<const uint64_t*>
                                 (&i_spdBuffer[SPD_EFD_MEMORY_SPACE_OFFSET_ADDR]);
        // Swap endianess to host format.
        l_efdMemorySpaceOffset = le64toh(l_efdMemorySpaceOffset);

        FAPI_DBG ("ddr4_get_efd: EFD memory space location = %d",
                  l_efdMemorySpaceOffset);

        /// Sanity check the EFD memory space offset.
        // Make sure the EFD memory space is not within the SPD DDR4 memory
        // space. The EFD memory space cannot share the same memory space as
        // the SPD DDR4.
        FAPI_ASSERT( (l_efdMemorySpaceOffset >= SPD_DDR4_SIZE),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: EFD memory space offset = %d resides "
                     "within the SPD DDR4 buffer size = %d. These two cannot "
                     "share the same meory space.",
                     l_efdMemorySpaceOffset,
                     SPD_DDR4_SIZE );

        /// Get and convert the EFD's memory space size exponential factor
        // Convert to the actual size of the EFD's memory space.
        // The EFD memory space size's exponential factor is 8 bytes.
        l_efdMemorySpaceSize = calculateEfdMemorySpaceSize(
                                   i_spdBuffer[SPD_EFD_MEMORY_SPACE_SIZE_ADDR] &
                                   SPD_EFD_MEMORY_SPACE_SIZE_MASK);

        FAPI_DBG ("ddr4_get_efd: EFD memory space size exponential factor = %d "
                  " converted to EFD memory space size = %d ",
                  static_cast<uint32_t>
                  (i_spdBuffer[SPD_EFD_MEMORY_SPACE_SIZE_ADDR] &
                   SPD_EFD_MEMORY_SPACE_SIZE_MASK),
                  l_efdMemorySpaceSize);

        // If the memory space is 0, then calculating the EFD memory
        // space size failed.
        FAPI_ASSERT( l_efdMemorySpaceSize,
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: Conversion unsuccessful for EFD space size "
                     "exponential factor = 0x%0.2X",
                     i_spdBuffer[SPD_EFD_MEMORY_SPACE_SIZE_ADDR] );

        /// Sanity check the EFD memory space offset + EFD memory space size.
        // Make sure the size of the SPD buffer is large enough to contain
        // the EFD memory space located at the EFD memory space offset.
        // From previous assert, the EFD memory space offset is at the
        // the end of the DDR4 SPD data.
        FAPI_ASSERT( (i_spdBufferSize >=
                      (l_efdMemorySpaceOffset + l_efdMemorySpaceSize)),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: SPD buffer size = %d is insufficient to "
                     "accommodate the EFD memory space size = %d at "
                     "offset = %d; a minimum SPD buffer needed =  %d",
                     i_spdBufferSize,
                     l_efdMemorySpaceSize,
                     l_efdMemorySpaceOffset,
                     ( l_efdMemorySpaceOffset + l_efdMemorySpaceSize ) );

        /// Get the number of EFDs contained within the EFD memory space.
        // The number of EFDs value is 2 bytes.
        l_efdCount = *reinterpret_cast<const uint16_t*>
                     (&i_spdBuffer[SPD_EFD_COUNT_ADDR]);
        // Swap endianess to host format.
        l_efdCount = le16toh(l_efdCount);
        // Extract the number of EFDs
        l_efdCount &= SPD_EFD_COUNT_MASK;

        FAPI_DBG ("ddr4_get_efd: number of EFDs = %d", l_efdCount);

        /// Sanity check the number of EFDs extracted.
        // Make sure there is at least one EFD to work with
        FAPI_ASSERT( (l_efdCount),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: The number of EFDs = %d. Need at least one",
                     l_efdCount);

        // The size of the EFD can be extrapolated from the first EFD.
        // Use the ending block info (byte 2) from EFD[0] to determine size.
        // Mask out the EFD block multiplier value and multiply
        // that with the incremental block byte size
        // This value should be constant for all EFDs
        l_efdSize = (i_spdBuffer[SPD_EFD_META_DATA_ADDR +
                                 SPD_EFD_META_DATA_EFD_BYTE_2_OFFSET] &
                     SPD_EFD_META_DATA_EFD_BLOCK_OFFSET_MASK) *
                    SPD_EFD_INCREMENTAL_BLOCK_BYTE_SIZE;

        FAPI_DBG ("ddr4_get_efd: the EFD block size = %d", l_efdSize);

        // null o_efdData pointer = request for o_efdData size
        if ( nullptr == o_efdData ) // just return size
        {
            io_vpdInfo.iv_size = l_efdSize;
            FAPI_INF ("ddr4_get_efd: Caller passed in an EFD data nullptr, so "
                      "returning size = %d so caller can allocate space for "
                      "EFD data",
                      io_vpdInfo.iv_size);

            goto fapi_try_exit;
        }

        //// Secondly, get/confirm and set as much outgoing data as possible

        /// Set the outgoing to DDR4
        io_vpdInfo.iv_ddr_mode = SPD_DDR4_TYPE;

        FAPI_DBG ("ddr4_get_efd: DDR mode = 0x%.2X",
                  io_vpdInfo.iv_ddr_mode);

        /// Confirm that the DMB manufacturer ID of the SPD data
        /// is what is expected
        // Get the DMB manufacturer ID - 2 bytes
        l_dmbMfgId = *reinterpret_cast<const uint16_t*>
                     (&i_spdBuffer[SPD_DMB_DMB_MFG_ID_ADDR]);
        // Swap endianess to host format.
        l_dmbMfgId = le16toh(l_dmbMfgId);

        FAPI_DBG ( "ddr4_get_efd: SPD DMB manufacturer ID = 0x%.4X "
                   "expected DMB manufacturer ID = 0x%.4X",
                   l_dmbMfgId,
                   SPD_DDR4_EXPECTED_DMB_MFG_ID );

        // Confirm the DMB manufacturer ID value is what we expect
        FAPI_ASSERT( (SPD_DDR4_EXPECTED_DMB_MFG_ID == l_dmbMfgId),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: SPD DMB manufacturer ID 0x%.4X is not the "
                     "expected DMB manufacturer ID 0x%.4X ",
                     l_dmbMfgId,
                     SPD_DDR4_EXPECTED_DMB_REVISION);

        // Set the outgoing DMB manufacturer ID
        io_vpdInfo.iv_dmb_mfg_id = SPD_DDR4_EXPECTED_DMB_MFG_ID;

        FAPI_DBG ( "ddr4_get_efd: SPD DMB manufacturer ID = 0x%.4X",
                   io_vpdInfo.iv_dmb_mfg_id);

        FAPI_DBG ( "ddr4_get_efd: SPD DMB revision = 0x%.2X "
                   "expected DMB revision = 0x%.2X",
                   i_spdBuffer[SPD_DMB_REVISION_ADDR],
                   SPD_DDR4_EXPECTED_DMB_REVISION );

        /// Confirm that the DMB revision of the SPD data is
        /// the revision we expect
        FAPI_ASSERT( (SPD_DDR4_EXPECTED_DMB_REVISION ==
                      i_spdBuffer[SPD_DMB_REVISION_ADDR] ),
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: SPD DMB revision 0x%.2X is not the expected "
                     "revision 0x%.2X",
                     i_spdBuffer[SPD_DMB_REVISION_ADDR],
                     SPD_DDR4_EXPECTED_DMB_REVISION );

        // Set the outgoing DMB revision
        io_vpdInfo.iv_dmb_revision = SPD_DDR4_EXPECTED_DMB_REVISION;

        FAPI_DBG ( "ddr4_get_efd: SPD DMB revision = 0x%.2X",
                   io_vpdInfo.iv_dmb_revision);


        //// Thirdly, confirm user input is valid and map user
        //// input to usable data

        /// Get the EFD frequency
        // Look up the bit mask for the given frequency
        // No need to swap endian, already in host format
        l_freqMask = ddrFrequencyToBitMask(io_vpdInfo.iv_omi_freq_mhz);

        FAPI_DBG ( "ddr4_get_efd: Caller supplied frquency = %d",
                   io_vpdInfo.iv_omi_freq_mhz );

        // If no value for frequency, then mapping of frequency was unsuccessful
        FAPI_ASSERT( l_freqMask,
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: Frequency %d not supported by Axone",
                     io_vpdInfo.iv_omi_freq_mhz );

        FAPI_DBG ("ddr4_get_efd: Caller supplied frquency = %d, "
                  "converted to frequency bit value mask = 0x%.4X",
                  io_vpdInfo.iv_omi_freq_mhz, l_freqMask);

        /// Get the EFD MR
        // Look up the bit mask for the given MR
        l_rankMask = ddrMasterRankToBitMask( io_vpdInfo.iv_rank_count);

        // If no value for MR, then mapping of MR was unsuccessful
        FAPI_ASSERT( l_rankMask,
                     fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                     "ddr4_get_efd: Master rank %d not supported by Axone",
                     io_vpdInfo.iv_rank_count );

        FAPI_DBG ("ddr4_get_efd: Caller supplied master rank = %d, "
                  "converted to master rank bit value mask = 0x%.2X",
                  io_vpdInfo.iv_rank_count, l_rankMask);

        //// Fourthly, find the EFD that matches the given frequency
        //// and master rank

        // Point to the beginning of the EFD meta data AKA EFD[0] meta data
        // The EFD[0] meta data contains the location and size of the
        // individual EFDs
        l_efdMetaDataPtr = i_spdBuffer + SPD_EFD_META_DATA_ADDR;

        // Point to the beginning of the EFD data AKA EFD[0] data
        l_efdDataPtr = i_spdBuffer + l_efdMemorySpaceOffset;

        FAPI_DBG ("ddr4_get_efd: Looking to match caller supplied frequency = "
                  "%d (mapped to 0x%.4X) and caller supplied master rank = "
                  "%d (mapped to 0x%.2X)",
                  io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                  io_vpdInfo.iv_rank_count, l_rankMask);

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

            // Sanity check that the EFD and size is within the EFD memory space
            FAPI_ASSERT( ( (l_efdMemorySpaceOffset + l_efdMemorySpaceSize) >=
                           (l_efdMemorySpaceOffset + (ii * l_efdSize) + l_efdSize) ),
                         fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                         "EFD[%d] at location = %d plus EFD size = %d is "
                         "outside the bounds of the EFD memory space = %d",
                         ii,
                         l_efdMemorySpaceOffset + (ii * l_efdSize),
                         l_efdSize,
                         (l_efdMemorySpaceOffset + l_efdMemorySpaceSize) );

            // From previous assert, we know there is enough buffer to inspect
            // the EFD.
            // Get the EFD's frequency bit mask
            uint16_t l_efdFreqMask = *reinterpret_cast<const uint16_t*>
                                     (&l_efdDataNptr[EFD_DDR4_FREQUENCY_ADDR]);
            // Swap endianess to host format.
            l_efdFreqMask = le16toh(l_efdFreqMask);

            // If the 'is implemented flag' is true for the EFD, AND if the EFD
            // frequency mask contains the frequency mask we are looking for AND
            // the EFD master rank matches the master rank we are looking for
            // then copy the EFD block for the caller.
            if ( (l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_3_OFFSET] &
                  SPD_EFD_META_DATA_EFD_IS_IMPLEMENTED_MASK) &&
                 (l_efdFreqMask & l_freqMask)                               &&
                 (l_efdDataNptr[EFD_DDR4_MASTER_RANK_ADDR] == l_rankMask) )
            {
                // Make sure the buffer to copy data to is large enough to
                // hold the EFD. If not, then assert.
                FAPI_ASSERT( (l_efdSize > io_vpdInfo.iv_size),
                             fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                             "EFD[%d] matches frequency and MR criteria but EFD "
                             "size %d exceeds outgoing buffer size %d",
                             ii,
                             l_efdSize,
                             io_vpdInfo.iv_size);

                if (io_vpdInfo.iv_size > l_efdSize)
                {
                    // If returning buffer larger than the EFD's size, then
                    // clear the buffer so no extraneous data is left in buffer
                    memset(o_efdData, 0, io_vpdInfo.iv_size);
                }

                // Copy the EFD data, that matched the given criteria,
                // to the out going buffer
                memcpy(o_efdData, l_efdDataNptr, l_efdSize);

                // Set the outgoing EFD function type
                io_vpdInfo.iv_efd_type =
                    l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_1_OFFSET] &
                    SPD_EFD_META_DATA_EFD_FUNCTION_TYPE_MASK;

                FAPI_INF ("ddr4_get_efd: EFD[%d] block matched frequency "
                          "criteria = 0x%.4X and master rank = 0x%.2X; "
                          "efd size = %d",
                          ii, l_freqMask, l_rankMask, l_efdSize);

                break; // exit stage left, we are done
            }  // end if ((l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_3_OFFSET]...

            // This EFD is not a match, send trace stating so
            FAPI_DBG ("ddr4_get_efd: Match failed for EFD[%d], freq bit mask "
                      "= 0x%.4X, rank bit mask = 0x%.2X, EFD memory location "
                      "= %d, EFD size = %d, is implemented flag = %d",
                      ii,
                      l_efdFreqMask,
                      l_efdDataNptr[EFD_DDR4_MASTER_RANK_ADDR],
                      (l_efdMemorySpaceOffset + (ii * l_efdSize)),
                      l_efdSize,
                      (l_efdMetaDataNptr[SPD_EFD_META_DATA_EFD_BYTE_3_OFFSET] &
                       SPD_EFD_META_DATA_EFD_IS_IMPLEMENTED_MASK));

        }  // end for (int i = 0; i < l_efdCount; ++i)

        if (ii >= l_efdCount)
        {
            // Did not find an EFD to match frequency and master rank criteria
            // Collect FFDC and assert if iv_is_config_ffdc_enabled is true
            FAPI_ASSERT( ( !io_vpdInfo.iv_is_config_ffdc_enabled ),
                         fapi2::TEST_ERROR_A().set_TARGET(i_ocmbFapi2Target),
                         "ALL EFDs have been exhausted.  NO match "
                         "for frequency %d (frequency bit mask 0x%.4X) and "
                         "master rank %d (master rank bit mask 0x%.2X)",
                         io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                         io_vpdInfo.iv_rank_count, l_rankMask);

            // If unable to collect FFDC and assert, at least trace out error
            // and exit with false
            FAPI_ERR ("ddr4_get_efd: ALL EFDs have been exhausted.  NO match "
                      "for frequency = %d (frequency bit mask = 0x%.4X) and "
                      "master rank = %d (master rank bit mask = 0x%.2X)",
                      io_vpdInfo.iv_omi_freq_mhz, l_freqMask,
                      io_vpdInfo.iv_rank_count, l_rankMask);

            fapi2::current_err == fapi2::FAPI2_RC_FALSE;
            goto fapi_try_exit;
        }

    fapi_try_exit:

        FAPI_DBG("ddimm_get_efd: exiting with %s",
                 ( (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS) ?
                   "no errors" : "errors" ));
        return fapi2::current_err;

    }  // end ddimm_get_efd

} //extern C
