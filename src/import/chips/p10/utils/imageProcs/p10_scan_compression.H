/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_scan_compression.H $ */
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
#ifndef __P10_SCAN_COMPRESSION_H__
#define __P10_SCAN_COMPRESSION_H__

/// This header declares and documents the entry points defined in
/// p10_scan_compression.C.  Some constants are also required by the scan
/// decompression HOMER assembly procedures.

#ifndef __ASSEMBLER__

#ifdef _WIN32
    #include "win32_stdint.h"
#else
    #ifdef __sun
        #include <sys/int_types.h>
    #else
        #include <stdint.h>
    #endif
#endif
#include <common_ringId.H>

/// Compressed Scan Chain Data Structure Format
///
/// The compressed scan ring data structure must be 8-byte aligned in
/// memory. The container data structure consists of a header
/// followed by an arbitrary number of 8 byte doublewords containing the
/// compressed scan data. Images are always stored and processed in
/// big-endian byte order. The header format is common across all
/// decompression algorithms.
///
/// ATTENTION:
/// The RS4v2 CompressedScanData had a 4 byte magic value with 0x34 ("4")
/// within its third byte, which is at the same byte position as iv_version
/// now. Users of CompressedScanData which use the magic value to detect
/// a ring data structure won't be able to distingish old and new
/// CompressedScanData for iv_version being 0x34. In the very unlikely case
/// that we would have that many versions of CompressedScanData, it is
/// strongly suggested to simply skip 0x34 as version number.
///
/// Bytes - Content
///
/// 0:1   - A 16-bit "magic number" that identifies and validates the
/// compression algorithm used to compress the data ("RS").
///
/// 2     - An 8-bit version number.
///
/// 3     - An 8-bit type field distinguishing different ring types.
/// See detailed explanation elsewhere in this file.
///
/// 4:5   - The 16-bit size of the compressed scan data with
/// this header in \e bytes. This is not the exact length of actual scan data
/// in bits, but the number of bytes used by the RS4 encoding to store those
/// compressed scan bits.
///
/// 6:7   - The 16-bit ring ID uniquely identifying the ring.
///
/// 8:9   - Dynamic init, or PLL, selector value [0:63].
///
/// 10:13 - scan scom register value
///
/// 14:15 - Undefined (to purposely pad to 4B boundary)
typedef struct
{
    uint16_t      iv_magic;
    uint8_t       iv_version;
    uint8_t       iv_type;
    uint16_t      iv_size;
    RingId_t      iv_ringId;
    uint32_t      iv_scanAddr;
    Rs4Selector_t iv_selector;  // Must be second last (temp assumption in Mvpd accessor)
    uint16_t      iv_undefined; // Must be last (temp assumption in Mvpd accessor)
} CompressedScanData;

#define RS4_MIN_RING_SIZE   20 // Min value of iv_size, e.g. flush size of short ring.

/// Endian-translate a CompressedScanData structure
///
/// \param o_data A pointer to a CompressedScanData structure to receive the
/// endian-translated form of \a i_data.
///
/// \param i_data A pointer to the original CompressedScanData structure.
///
/// This API performs an endian-converting copy of a CompressedScanData
/// structure. This copy is guaranteed to be done in such a way that \a i_data
/// and \a o_data may be the same pointer for in-place conversion.  Due to the
/// symmetry of reverse, translating a structure twice is always guaranteed to
/// return the origial structure to its original byte order.
void
compressed_scan_data_translate( CompressedScanData* o_data,
                                CompressedScanData* i_data );


/// Compress a scan string using the RS4 compression algorithm
///
/// \param[in,out] io_rs4 This is a pointer to a memory area which must be
/// large enough to hold the worst-case result of compressing \a i_data_str
/// and \a i_care_str (see below). Note that the CompressedScanData is
/// always created in big-endian format, however the caller can use
/// compresed_scan_data_translate() to create a copy of the header in
/// host format.
///
/// \param[in] i_size The size of the buffer pointed to by \a io_rs4.
///
/// \param[in] i_data_str The string to compress.  Scan data to compress is
/// left-justified in this input string.
///
/// \param[in] i_care_str The care mask that identifies which bits in the
/// i_data_str that need to be scanned (written). String is left-justified.
///
/// \param[in] i_length The length of the input string in \e bits.  It is
/// assumed the \a i_string contains at most (\a i_length + 7) / 8 bytes.
///
/// \param[in] i_scanAddr The 32-bit scan address.
///
/// \param[in] i_ringId The ring ID that uniquely identifies the ring. (See
/// <ChipType> ring ID header files for more info.)
///
/// \param[in] i_selector The dynamic, or PLL, 8-bit selector value identifying
/// the Dynamic init feature, or the PLL sub type, to be overlaid onto the
/// base ring found in either the .sbe.rings or .qme.rings section.
///
/// \param[in] i_type A vector specifying ring type: CMSK, override, selector
/// type (see details for iv_type elsewhere in this header file)
///
/// This API is required for integration with PHYP which does not support
/// local memory allocation, like malloc() and new().  Applications in
/// environments supporting local memory allocation can use rs4_compress()
/// instead.
///
/// We always require the worst-case amount of memory including the header and
/// any rounding required to guarantee that the data size is a multiple of 8
/// bytes.  The final image size is also rounded up to a multiple of 8 bytes.
/// If the \a io_size is less than this amount (based on \a i_length) the
/// call will fail.
///
/// \returns See \ref scan_compression_codes
int
_rs4_compress( CompressedScanData* io_rs4,
               const uint32_t      i_size,
               const uint8_t*      i_data_str,
               const uint8_t*      i_care_str,
               const uint32_t      i_length,
               const uint32_t      i_scanAddr,
               const RingId_t      i_ringId,
               const Rs4Selector_t i_selector,
               const uint8_t       i_type );


/// Compress a scan string using the RS4 compression algorithm
///
/// \param[out] o_rs4 This algorithm uses new() to allocate memory for the
/// compressed data, and returns a pointer to this memory in \a o_rs4. After
/// the call this memory is owned by the caller who is responsible for
/// free()-ing the data area once it is no longer required. Note that the
/// CompressedScanData is always created in big-endian format, however the
/// caller can use compresed_scan_data_translate() to create a copy of the
/// header in host format.
///
/// \param[in] i_data_str The string to compress.  Scan data to compress is
/// left-justified in this input string.
///
/// \param[in] i_care_str The care mask that identifies which bits in the
/// i_data_str that need to be scanned (written). String is left-justified.
///
/// \param[in] i_length The length of the input string in \e bits.  It is
/// assumed the \a i_string contains at most (\a i_length + 7) / 8 bytes.
///
/// \param[in] i_scanAddr The 32-bit scan address.
///
/// \param[in] i_ringId The ring ID that uniquely identifies the ring. (See
/// <ChipType> ring ID header files for more info.)
///
/// \param[in] i_selector The dynamic, or PLL, 8-bit selector value identifying
/// the Dynamic init feature, or the PLL sub type, to be overlaid onto the
/// base ring found in either the .sbe.rings or .qme.rings section.
///
/// \param[in] i_type A vector specifying ring type: CMSK, override, selector
/// type (see details for iv_type elsewhere in this header file)
///
/// \returns See \ref scan_compression_codes
int
rs4_compress( CompressedScanData** o_rs4,
              const uint8_t*       i_data_str,
              const uint8_t*       i_care_str,
              const uint32_t       i_length,
              const uint32_t       i_scanAddr,
              const RingId_t       i_ringId,
              const Rs4Selector_t  i_selector,
              const uint8_t        i_type );


/// Decompress a scan string compressed using the RS4 compression algorithm
///
/// \param[in,out] io_data_str A caller-supplied data area to contain the
/// decompressed string. The \a i_size must be large enough to contain
/// the decompressed string, which is the size of the original string in bits
/// rounded up to the nearest byte.
///
/// \param[in,out] io_care_str A caller-supplied data area to contain the
/// decompressed care mask. The \a i_size must be large enough to contain
/// the decompressed care mask, which is the size of the original string in
/// bits / 8 rounded up to the nearest byte.
///
/// \param[in] i_size The size in \e bytes of \a o_data_str and \a o_care_str
/// buffers and which represents the max number of raw ring bits / 8 that may
/// fit into the two raw ring buffers.
///
/// \param[out] o_length The length of the decompressed string in \e bits.
///
/// \param[in] i_rs4 A pointer to the CompressedScanData header + data to be
/// decompressed.
///
/// This API is required for integration with PHYP which does not support
/// local memory allocation, such as malloc() and new().  Applications in
/// environments supporting local memory allocation can use rs4_decompress()
/// instead.
///
/// \returns See \ref scan_compression_codes
int
_rs4_decompress( uint8_t* o_data_str,
                 uint8_t* o_care_str,
                 uint32_t i_size,
                 uint32_t* o_length,
                 const CompressedScanData* i_rs4 );


/// Decompress a scan string compressed using the RS4 compression algorithm
///
/// \param[out] o_data_str The API new() allocs this data area to contain the
/// decompressed string. After this call the caller owns \a o_data_str and is
/// responsible for free()-ing this data area once it is no longer required.
///
/// \param[out] o_care_str The API new() allocs this data area to contain the
/// decompressed care mask. After this call the caller owns \a o_care_str and
/// is responsible for free()-ing this data area once it is no longer required.
///
/// \param[out] o_length The length of the decompressed string and care mask
/// in \e bits. The caller may assume that \a o_data_str and o_care_str each
/// contain at most (\a o_length + 7) / 8 \e bytes.
///
/// \param[in] i_rs4 A pointer to the CompressedScanData header and data to be
/// decompressed.
///
/// \returns See \ref scan_compression_codes
int
rs4_decompress( uint8_t** o_data_str,
                uint8_t** o_care_str,
                uint32_t* o_length,
                const CompressedScanData* i_rs4 );



/// Get the raw bit length of an RS4 string by decompressing the string and
/// counting the bits along the way but ** without ** saving the raw
/// decompressed bit stream (ie, zero buffer space required).
///
/// \param[out] o_length  The length of the [raw] decompressed bit string
///
/// \param[in] i_rs4  A pointer to the RS4 ring to be decompressed
///
/// \returns See \ref scan_compression_codes
int
rs4_get_raw_bit_length( uint32_t& o_length,
                        const CompressedScanData* i_rs4 );


/// Determine if an RS4 compressed scan string is all 0
///
/// \param[in] i_data A pointer to the CompressedScanData header + data to be
///
/// \param[out] o_redundant Set to =true if the RS4 string is the compressed form
/// of a scan string that is all 0; Otherwise set to =false.
///
/// \returns See \ref scan_compression_codes
int
rs4_redundant( const CompressedScanData* i_data, MyBool_t& o_redundant );


/// Check for Override or Flush ring in RS4
///
/// \param[in] i_rs4 A pointer to the RS4 CompressedScanData [header + data]
///
/// \returns  true if Ovrd ring, false if Flush ring and UNDEFINED_BOOLEAN if any other type
MyBool_t
rs4_is_ovrd(const CompressedScanData* i_rs4);


// API for overlaying one RS4 ring onto another RS4 ring (without decompression)
//
// API arguments:
// o_rs4Final : The final overlaid output RS4 ring plus three raw4 rings
// i_workBufSize:  Size of buffer to hold final overlaid RS4 ring plus three raw4 rings
// i_rs4Tgt :   The ring to be overlaid. Note that buffer can be shared with rs4Final.
// i_rs4Ovly :  The overlay ring. Note that buffer can be shared with rs4Final.
// i_type :     The iv_type to program into final RS4 header
// i_selector : The iv_selector to program into final RS4 header
// i_ovlyMode : 0:Ovly is boss, 1:No bit conflicts (dynamic accummulation)
// i_dbgl :     0:No add'l debug output,  1:Add'l debug trace outputs
//
// Assumptions:
// - The two input rings must match wrt flush type, ringId, scanAddr, selector.
// - All buffers are caller managed.
// - If either of the input RS4 rings are empty, or do not contain a valid RS4
//   ring, this is an error.
int
rs4_overlay( CompressedScanData* o_rs4Final,
             const uint32_t i_workBufSize,
             const CompressedScanData* i_rs4Tgt,
             const CompressedScanData* i_rs4Ovly,
             const uint8_t i_ivType,
             const Rs4Selector_t i_selector,
             const uint8_t i_ovlyMode,
             const uint8_t i_dbgl = 0 );


#endif  // __ASSEMBLER__


/// \defgroup scan_compression_magic Scan Compression Magic Numbers
///
/// @ {

/// RS4 Magic
#define RS4_MAGIC 0x5253       /* "RS" */

/// @}

/// \defgroup scan_compression_version_type version and type accessors
///
/// @{

/// The current version of the CompressedScanData structure
///
/// This constant is required to be a #define to guarantee consistency between
/// the header format and compiled code.
/// #define RS4_VERSION 1  // Version from P8
/// #define RS4_VERSION 2  // Added ability to write zeros using a care mask
/// #define RS4_VERSION 3  // Reduced header size to 12 bytes
/// #define RS4_VERSION 4  // iv_type chg: Added SEL
#define RS4_VERSION 5  // iv_type chg: Remvd CMSK, movd/renmd OVRD->SCAN, expnded/renmd SEL->ORIG

/// @}


/// Scan and Origination ring types (used for encoding RS4 header's iv_type)
///
#ifdef WIN32
    /// Scan type: Flush or Override (Governs scan controller setup)
    #define RS4_IV_TYPE_SCAN_MASK       (uint8_t)0x03  //0b00000011
    #define RS4_IV_TYPE_SCAN_FLUSH      (uint8_t)0x01  //0b00000001
    #define RS4_IV_TYPE_SCAN_OVRD       (uint8_t)0x02  //0b00000010
    #define RS4_IV_TYPE_SCAN_CTX        (uint8_t)0x03  //0b00000011
    /// Origination of ring: Base, Mvpd, Overlays, Dynamic, Overrides (Used for customized debug)
    #define RS4_IV_TYPE_ORIG_MASK       (uint8_t)0x7c  //0b01111100
    #define RS4_IV_TYPE_ORIG_BASE       (uint8_t)0x04  //0b00000100 // Base (.{sbe,qme}.rings)
    #define RS4_IV_TYPE_ORIG_MVPD       (uint8_t)0x08  //0b00001000 // Mvpd (#R/G/S/P)
    #define RS4_IV_TYPE_ORIG_OVLY       (uint8_t)0x10  //0b00010000 // Overlays (.overlays)
    #define RS4_IV_TYPE_ORIG_DYN        (uint8_t)0x20  //0b00100000 // Dynamic (.dynamic)
    #define RS4_IV_TYPE_ORIG_OVRD       (uint8_t)0x40  //0b01000000 // Overrides (.overrides,.fa_ring_ovrd)

#else
    /// Scan type: Flush or Override (Governs scan controller setup)
    #define RS4_IV_TYPE_SCAN_MASK       (uint8_t)0b00000011
    #define RS4_IV_TYPE_SCAN_FLUSH      (uint8_t)0b00000001
    #define RS4_IV_TYPE_SCAN_OVRD       (uint8_t)0b00000010
    #define RS4_IV_TYPE_SCAN_CTX        (uint8_t)0b00000011
    /// Origination of ring: Base, Mvpd, Overlays, Dynamic, Overrides (Used for customized debug)
    #define RS4_IV_TYPE_ORIG_MASK       (uint8_t)0b01111100
    #define RS4_IV_TYPE_ORIG_BASE       (uint8_t)0b00000100 // Base (.{sbe,qme}.rings)
    #define RS4_IV_TYPE_ORIG_MVPD       (uint8_t)0b00001000 // Mvpd (#R/G/S/P)
    #define RS4_IV_TYPE_ORIG_OVLY       (uint8_t)0b00010000 // Overlays (.overlays)
    #define RS4_IV_TYPE_ORIG_DYN        (uint8_t)0b00100000 // Dynamic (.dynamic)
    #define RS4_IV_TYPE_ORIG_OVRD       (uint8_t)0b01000000 // Overrides (.overrides,.fa_ring_ovrd)
#endif
#define UNDEFINED_RS4_SELECTOR (Rs4Selector_t)0xffff
#define MAX_RS4_SELECTOR       (Rs4Selector_t)0xff // Practical upper limit of 255


/// Overlay modes
///
enum OVERLAY_MODE
{
    OVLY_MODE_RAW4TEST = (uint8_t)0, //Do Raw4 (de)Xpress steps only, copy Tgt to Final buf
    OVLY_MODE_BOSS     = (uint8_t)1, //rs4Ovly encodings overrule rs4Target
    OVLY_MODE_ACC      = (uint8_t)2, //rs4Ovly and rs4Target must agree (dynamic acc mode)
};

/// \defgroup scan_compression_codes Scan Compression Return Codes
///
/// @{

/// Normal return code
#define SCAN_COMPRESSION_OK  INFRASTRUCT_RC_SUCCESS

/// The (de)compression algorithm could not allocate enough memory for the
/// (de)compression.
#define SCAN_COMPRESSION_NO_MEMORY (uint8_t)1

/// Magic number mismatch on scan decompression
#define SCAN_COMPRESSION_MAGIC_ERROR (uint8_t)2

/// RS4 size error
#define SCAN_COMPRESSION_RS4_SIZE_ERROR (uint8_t)3

/// A buffer would overflow
#define SCAN_COMPRESSION_BUFFER_OVERFLOW (uint8_t)4

/// Bad input data - data=1 is masked by care=0
#define SCAN_COMPRESSION_CAREDATA_CONFLICT (uint8_t)5

/// Invalid transition in state machine
#define SCAN_COMPRESSION_STATE_ERROR (uint8_t)6

/// wrong compression version
#define SCAN_COMPRESSION_VERSION_ERROR (uint8_t)7

/// Invalid iv_type value
#define SCAN_COMPRESSION_IV_TYPE_ERROR (uint8_t)8

/// Generic Raw4 compression error
#define SCAN_COMPRESSION_RAW4_ERROR (uint8_t)9

/// Header mismatch between two RS4 rings
#define SCAN_COMPRESSION_HEADERS_DONT_MATCH (uint8_t)10

/// Invalid Overlay mode
#define SCAN_COMPRESSION_INVALID_OVERLAY_MODE (uint8_t)11

/// Overlay bit conflict
#define SCAN_COMPRESSION_OVERLAY_BIT_CONFLICT (uint8_t)12

/// Overlay bit conflict
#define SCAN_COMPRESSION_STOP_DECODE_ERROR (uint8_t)13
/// @}

#endif  //  __P10_SCAN_COMPRESSION_H__
