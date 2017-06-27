/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_scan_compression.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#ifndef __P9_SCAN_COMPRESSION_H__
#define __P9_SCAN_COMPRESSION_H__

/// This header declares and documents the entry points defined in
/// p9_scan_compression.C.  Some constants are also required by the scan
/// decompression HOMER assembly procedures.

#ifndef __ASSEMBLER__

#include <stdint.h>
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
/// that we would have that many versions of ComprossedScanData, it is
/// strongly suggested to simply skip 0x34 as version number.
///
/// Bytes - Content
///
/// 0:1   - A 16-bit "magic number" that identifies and validates the
/// compression algorithm used to compress the data ("RS").
///
/// 2     - An 8-bit version number (3 for the time being).
///
/// 3     - An 8-bit type field distinguishing different scan data types
/// (0 for non-CMSK, 1 for CMSK).
///
/// 4:5   - The 16-bit size of the compressed scan data with
/// this header in \e bytes. This is not the exact length of actual scan data
/// in bits, but the number of bytes used by the RS4 encoding to store those
/// compressed scan bits.
///
/// 6:7   - The 16-bit ring ID uniquely identifying the ring.
///
/// 8:11  - scan scom register value
typedef struct
{
    uint16_t iv_magic;
    uint8_t  iv_version;
    uint8_t  iv_type;
    uint16_t iv_size;
    RingId_t iv_ringId;
    uint32_t iv_scanAddr;
} CompressedScanData;

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
compressed_scan_data_translate(CompressedScanData* o_data,
                               CompressedScanData* i_data);


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
/// assumed the \a i_string contains at least (\a i_length + 7) / 8 bytes.
///
/// \param[in] i_scanAddr The 32-bit scan address.
///
/// \param[in] i_ringId The ring ID that uniquely identifies the ring. (See
/// <ChipType> ring ID header files for more info.)
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
_rs4_compress(CompressedScanData* io_rs4,
              const uint32_t i_size,
              const uint8_t* i_data_str,
              const uint8_t* i_care_str,
              const uint32_t i_length,
              const uint32_t i_scanAddr,
              const RingId_t i_ringId);


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
/// assumed the \a i_string contains at least (\a i_length + 7) / 8 bytes.
///
/// \param[in] i_scanAddr The 32-bit scan address.
///
/// \param[in] i_ringId The ring ID that uniquely identifies the ring. (See
/// <ChipType> ring ID header files for more info.)
///
/// \returns See \ref scan_compression_codes
int
rs4_compress(CompressedScanData** o_rs4,
             const uint8_t* i_data_str,
             const uint8_t* i_care_str,
             const uint32_t i_length,
             const uint32_t i_scanAddr,
             const RingId_t i_ringId);


/// Decompress a scan string compressed using the RS4 compression algorithm
///
/// \param[in,out] io_data_str A caller-supplied data area to contain the
/// decompressed string. The \a i_stringSize must be large enough to contain
/// the decompressed string, which is the size of the original string in bits
/// rounded up to the nearest byte.
///
/// \param[in,out] io_care_str A caller-supplied data area to contain the
/// decompressed care mask. The \a i_stringSize must be large enough to contain
/// the decompressed care mask, which is the size of the original string in
/// bits rounded up to the nearest byte.
///
/// \param[in] i_size The size in \e bytes of \a o_data_str and \a o_care_str
/// buffers and which represents the max number of raw ring bits x 8 that may
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
_rs4_decompress(uint8_t* o_data_str,
                uint8_t* o_care_str,
                uint32_t i_size,
                uint32_t* o_length,
                const CompressedScanData* i_rs4);


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
/// contain at least (\a o_length + 7) / 8 \e bytes.
///
/// \param[in] i_rs4 A pointer to the CompressedScanData header and data to be
/// decompressed.
///
/// \returns See \ref scan_compression_codes
int
rs4_decompress(uint8_t** o_data_str,
               uint8_t** o_care_str,
               uint32_t* o_length,
               const CompressedScanData* i_rs4);


/// Determine if an RS4 compressed scan string is all 0
///
/// \param[in] i_data A pointer to the CompressedScanData header + data to be
///
/// \param[out] o_redundant Set to 1 if the RS4 string is the compressed form
/// of a scan string that is all 0; Otherwise set to 0.
///
/// \returns See \ref scan _compression_code
int
rs4_redundant(const CompressedScanData* i_data, int* o_redundant);


/// Check for CMSK ring in RS4
///
/// \param[in] i_rs4 A pointer to the RS4 CompressedScanData [header + data]
///
/// \returns 1 if CMSK ring found, 0 otherwise
int rs4_is_cmsk(const CompressedScanData* i_rs4);


/// Embed CMSK ring into an RS4 ring
///
/// \param[inout] io_rs4 A pointer to the CompressedScanData [header + data]
///
/// \param[in] i_rs4_cmsk A pointer to the cmsk CompressedScanData header + data to be embedded
///
/// \returns See \ref scan_compression_codes
int rs4_embed_cmsk(CompressedScanData** io_rs4,
                   CompressedScanData* i_rs4_cmsk);


/// Extract Stump & CMSK rings from an RS4 ring (assumes pre-allocated ring buffers)
///
/// \param[in] i_rs4  A pointer to the input hybrid CMSK RS4 ring and which must contain
/// boto CompressedScanData header + RS4 encoded data string.
///
/// \param[in] i_size  Size of buffers to hold the output Stump and CMSK RS4 rings.
///
/// \param[out] o_rs4_stump  A pointer to a pre-allocated buffer that must be big
/// enough to hold the Stump CompressedScanData [header + data].
///
/// \param[out] o_rs4_cmsk  A pointer to a pre-allocated buffer that must be big
/// enough to hold the Cmsk CompressedScanData [header + data].
///
/// \returns See \ref scan_compression_codes
int _rs4_extract_cmsk( const CompressedScanData* i_rs4,
                       size_t                    i_size,
                       CompressedScanData*       o_rs4_stump,
                       CompressedScanData*       o_rs4_cmsk );


/// Extract Stump & CMSK rings from an RS4 ring (local allocation of ring buffers)
///
/// \param[in] i_rs4  A pointer to the input hybrid CMSK RS4 ring and which must contain
/// boto CompressedScanData header + RS4 encoded data string.
///
/// \param[out] o_rs4_stump  A pointer to a locally allocated buffer that holds the
/// Stump CompressedScanData [header + data].  The calling code must free the buffer.
///
/// \param[out] o_rs4_cmsk  A pointer to a locally allocated buffer that holds the
/// Cmsk CompressedScanData [header + data].  The calling code must free the buffer.
///
/// \returns See \ref scan_compression_codes
int rs4_extract_cmsk( const CompressedScanData* i_rs4,
                      CompressedScanData**      o_rs4_stump,
                      CompressedScanData**      o_rs4_cmsk );

#endif  // __ASSEMBLER__

/// Function: print_raw_ring()
/// @brief: Prints out the raw decompressed RS4 ring content.
///
/// Desc.:It displays the raw decompressed ring content in the same
///       format that it appears as in EKB's ifCompiler generated raw ring
///       files, i.e. *.bin.srd (DATA) and *.bin.srd.bitsModified (CARE).
///
/// \param[in] data Its Data (*.bin.srd) or Care (*.bin.srd.bitsModified)
/// \param[in] bits Length of raw ring in bits
void print_raw_ring( uint8_t*  data, uint32_t  bits);


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
#define RS4_VERSION 3

/// Scan data types
#define RS4_SCAN_DATA_TYPE_CMSK     1
#define RS4_SCAN_DATA_TYPE_NON_CMSK 0

/// @}

/// \defgroup scan_compression_codes Scan Compression Return Codes
///
/// @{

/// Normal return code
#define SCAN_COMPRESSION_OK (uint8_t)0

/// The (de)compression algorithm could not allocate enough memory for the
/// (de)compression.
#define SCAN_COMPRESSION_NO_MEMORY (uint8_t)1

/// Magic number mismatch on scan decompression
#define SCAN_DECOMPRESSION_MAGIC_ERROR (uint8_t)2

/// Decompression size error
///
/// Decompression produced a string of a size different than indicated in the
/// header, indicating either a bug or data corruption.  Note that the entire
/// application should be considered corrupted if this error occurs since it
/// may not be discovered until after the decompression buffer is
/// overrun. This error may also be returned by rs4_redundant() in the event
/// of inconsistencies in the compressed string.
#define SCAN_DECOMPRESSION_SIZE_ERROR (uint8_t)3

/// A buffer would overflow
///
/// Either the caller-supplied memory buffer to _rs4_decompress() was too
/// small to contain the decompressed string, or a caller-supplied buffer to
/// _rs4_compress() was not large enough to hold the worst-case compressed
/// string.
#define SCAN_COMPRESSION_BUFFER_OVERFLOW (uint8_t)4

/// Inconsistent input data
///
/// 1 in data is masked by 0 in care mask
#define SCAN_COMPRESSION_INPUT_ERROR 5

/// Invalid transition in state machine
#define SCAN_COMPRESSION_STATE_ERROR 6

/// wrong compression version
#define SCAN_COMPRESSION_VERSION_ERROR 7

/// @}

#endif  //  __P9_SCAN_COMPRESSION_H__
