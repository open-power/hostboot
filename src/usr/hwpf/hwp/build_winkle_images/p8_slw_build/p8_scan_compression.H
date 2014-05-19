/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_scan_compression.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __P8_SCAN_COMPRESSION_H__
#define __P8_SCAN_COMPRESSION_H__

// $Id: p8_scan_compression.H,v 1.5 2013/05/30 00:33:22 bcbrock Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_scan_compression.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Bishop Brock  Email: Bishop Brock; bcbrock@us.ibm.com
// *!
// *! General Description:
// *! 
// *!     See below.
//------------------------------------------------------------------------------
//
// Note: This file was originally named p8_scan_compression.c; See CVS archive
// for revision history of p8_scan_compression.c.

/// \file p8_scan_compression.H
/// \brief Structure definitions and protoypes related to scan chain
/// compression. 
///
/// This header declares and documents the entry points defined in
/// p8_scan_compression.C.  Some constants are also required by the scan
/// decompression PORE assembly procedures.

#include "fapi_sbe_common.H"

#ifndef __ASSEMBLER__

#include <stdint.h>

/// Compressed Scan Chain Data Structure Format
///
/// The compressed scan ring data structure must be 8-byte aligned in
/// memory. The container data structure consists of this 24-byte header
/// followed by an arbitrary number of 8 byte doublewords containing the
/// compressed scan data.  Images are always stored and processed in
/// big-endian byte order.  This container format is common across all
/// decompression algorithms.
///
/// Bytes - Content
/// 
/// 0:3 - A 32-bit "magic number" that identifies and validates the
/// compression algorithm and algorithm version used to compress the data.
///
/// 4:7 - The 32-bit size of the entire data structure in \e bytes.  This
/// consists of this 24-byte header plus the compressed scan data.  This value
/// is always a multiple of 8.
///
/// 8:11 - This 32-bit value is reserved to the compression
/// algorithm. Typically this field is used to record the 'size' of the
/// compressed string in units specific to each algorithm.
///
/// 12:15 - The length of the original scan chain in \e bits.
///
/// 16:19 - The 32 high-order bits of the value written to the Scan Select
/// register to set up the scan.  The Scan Select register only defines these
/// bits. 
///
/// 20 - The Scan Chain Data Structure version number
///
/// 21 - Flush-optimize : Is this byte is non-zero, the ring state to be
/// modified is the flush state of the ring.
///
/// 22 - The ring ID uniquely identifying the repair ring name.
///
/// 23 - The 7-bit pervasive chiplet Id + Multicast bit of the chiplet to
/// scan.  This value is loaded directly into P0.  The decompression
/// algorithms provide two entry points - one that uses this value as the
/// chiplet Id, and another that allows the caller to specify the chiplet Id
/// in the call.

typedef struct {

    /// Magic number - See \ref scan_compression_magic
    uint32_t iv_magic;

    /// Total size in bytes, including the container header
    uint32_t iv_size;

    /// Reserved to the algorithm
    uint32_t iv_algorithmReserved;

    /// Length of the original scan chain in bits
    uint32_t iv_length;

    /// The high-order 32 bits of the Scan Select Register
    ///
    /// Note that the Scan Select register only defines the high order 32
    /// bits, so we only need store the 32 high-order bits.  This field is
    /// 8-byte aligned so that the doubleword loaded by the PORE can be
    /// directly written to the scan select register.
    uint32_t iv_scanSelect;

    /// Data structure (header) version
    uint8_t iv_headerVersion;

    /// Flush-state optimization
    ///
    /// Normally, modifying the state of the ring requires XOR-ing the
    /// difference state (the compressed state) with the current ring state as
    /// it will appear in the Scan Data Register. If the current state of the
    /// ring is the scan-0 flush state, then by definition the Scan Data
    /// Register is always 0. Therefore we can simply write the difference to
    /// the Scan Data Register rather than using a read-XOR-write.
    uint8_t iv_flushOptimization;

    /// Ring ID uniquely identifying the repair name. (See the list of ring
		/// name vs ring IDs in p8_ring_identification.c).
    uint8_t iv_ringId;

    /// 7-bit pervasive chiplet Id + Multicast bit
    ///
    /// This field is right-justified in an 8-byte aligned doubleword so that
    /// the P0 register can be directly updated from the doubelword value in a
    /// data register.
    uint8_t iv_chipletId;

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
/// \param[in,out] io_data This is a pointer to a memory area which must be
/// large enough to hold the worst-case result of compressing \a i_string (see
/// below).  Note that the CompressedScanData is always created in big-endian
/// format, however the caller can use compresed_scan_data_translate() to
/// create a copy of the header in host format.
///
/// \param[in] i_dataSize The size of \a io_data in bytes.
///
/// \param[out] o_imageSize The effective size of the entire compressed scan
/// data structure (header + compressed data) created in \a io_data, in bytes.
/// This value will always be a multiple of 8.
///
/// \param[in] i_string The string to compress.  Scan data to compress is
/// left-justified in this input string.
///
/// \param[in] i_length The length of the input string in \e bits.  It is
/// assumed the \a i_string contains at least (\a i_length + 7) / 8 bytes.
///
/// \param[in] i_scanSelect The 64-bit value written to the Scan Select
/// register to set up for the scan. Only the 32 high-order bits are actually
/// stored.
///
/// \param[in] i_ringId The ring ID that uniquely identifies the ring name of
/// a repair ring. (See p8_ring_identification.c for more info.)
///
/// \param[in] i_chipletId The 7-bit value for the iv_chipletId field of the
/// CompressedScanData.
///
/// \param[in] i_flushOptimization This input parameter should be set to a
/// non-0 value if it is known that this ring difference will be applied to a
/// scan-0 flush state.  This will improve the performance of the
/// decompress-scan routine. If the initial state of the ring is unknown, set
/// this parameter to 0.
///
/// This API is required for integration with PHYP which does not support
/// malloc().  Applications in environments supporting malloc() can use
/// rs4_compress() instead.
///
/// The worst-case compression for RS4 requires 2 nibbles of control overhead
/// per 15 nibbles of data (17/15), plus a maximum of 2 nibbles of termination.
/// We always require this worst-case amount of memory including the header and
/// any rounding required to guarantee that the data size is a multiple of 8
/// bytes.  The final image size is also rounded up to a multiple of 8 bytes.
/// If the \a i_dataSize is less than this amount (based on \a i_length) the
/// call will fail.
///
/// \returns See \ref scan_compression_codes
int
_rs4_compress(CompressedScanData* io_data,
              uint32_t i_dataSize,
              uint32_t* o_imageSize,
              const uint8_t* i_string, 
              const uint32_t i_length,
              const uint64_t i_scanSelect,
              const uint8_t i_ringId,
              const uint8_t i_chipletId,
              const uint8_t i_flushOptimization);
             

/// Compress a scan string using the RS4 compression algorithm
///
/// \param[out] o_data This algorithm uses malloc() to allocate memory for the
/// compresed data, and returns a pointer to this memory in \a o_data. After
/// the call this memory is owned by the caller who is responsible for
/// free()-ing the data area once it is no longer required. Note that the
/// CompressedScanData is always created in big-endian format, however the
/// caller can use compresed_scan_data_translate() to create a copy of the
/// header in host format.
///
/// \param[out] o_size The effective size of the entire compressed scan data
/// structure (header + compressed data) pointed to by \a o_data, in bytes.
/// This value will always be a multiple of 8.
///
/// \param[in] i_string The string to compress.  Scan data to compress is
/// left-justified in this input string.
///
/// \param[in] i_length The length of the input string in \e bits.  It is
/// assumed the \a i_string contains at least (\a i_length + 7) / 8 bytes.
///
/// \param[in] i_scanSelect The 64-bit value written to the Scan Select
/// register to set up for the scan. Only the 32 high-order bits are actually
/// stored.
///
/// \param[in] i_ringId The ring ID that uniquely identifies the ring name of
/// a repair ring. (See p8_ring_identification.c for more info.)
///
/// \param[in] i_chipletId The 7-bit value for the iv_chipletId field of the
/// CompressedScanData.
///
/// \param[in] i_flushOptimization This input parameter should be set to a
/// non-0 value if it is known that this ring difference will be applied to a
/// scan-0 flush state.  This will improve the performance of the
/// decompress-scan routine. If the initial state of the ring is unknown, set
/// this parameter to 0.
///
/// \returns See \ref scan_compression_codes
int
rs4_compress(CompressedScanData** o_data,
             uint32_t* o_size,
             const uint8_t* i_string, 
             const uint32_t i_length,
             const uint64_t i_scanSelect,
             const uint8_t i_ringId,
             const uint8_t i_chipletId,
             const uint8_t i_flushOptimization);
             

/// Decompress a scan string compressed using the RS4 compression algorithm
///
/// \param[in,out] io_string A caller-supplied data area to contain the
/// decompressed string. The \a i_stringSize must be large enough to contain
/// the decompressed string, which is the size of the original string in bits
/// rounded up to the nearest byte.
///
/// \param[in] i_stringSize The size (in bytes) of \a i_string.
///
/// \param[out] o_length The length of the decompressed string in \e bits.
///
/// \param[in] i_data A pointer to the CompressedScanData header + data to be
/// decompressed.
///
/// This API is required for integration with PHYP which does not support
/// malloc().  Applications in environments supporting malloc() can use
/// rs4_decompress() instead.
///
/// \returns See \ref scan_compression_codes
int
_rs4_decompress(uint8_t* i_string,
                uint32_t i_stringSize,
                uint32_t* o_length,
                const CompressedScanData* i_data);
             

/// Decompress a scan string compressed using the RS4 compression algorithm
///
/// \param[out] o_string The API malloc()-s this data area to contain the
/// decompressed string. After this call the caller owns \a o_string and is
/// responsible for free()-ing this data area once it is no longer required.
///
/// \param[out] o_length The length of the decompressed string in \e bits.
/// The caller may assume that \a o_string contains at least (\a o_length + 7)
/// / 8 \e bytes.
///
/// \param[in] i_data A pointer to the CompressedScanData header + data to be
/// decompressed.
///
/// \returns See \ref scan_compression_codes
int
rs4_decompress(uint8_t** o_string,
               uint32_t* o_length,
               const CompressedScanData* i_data);


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
             

#endif  // __ASSEMBLER__


/// The current version of the CompressedScanData structure
///
/// This constant is required to be a #define to guarantee consistency between
/// the header format and cmopiled code.
#define COMPRESSED_SCAN_DATA_VERSION 1

/// The size of the CompressedScanData structure
CONST_UINT8_T(COMPRESSED_SCAN_DATA_SIZE, 24);


/// \defgroup scan_compression_magic Scan Compression Magic Numbers
///
/// @ {

/// RS4 Magic
CONST_UINT32_T(RS4_MAGIC, 0x52533401);      /* "RS4" + Version 0x01 */

/// @}


/// \defgroup scan_compression_codes Scan Compression Return Codes
///
/// @{

/// Normal return code
CONST_UINT8_T(SCAN_COMPRESSION_OK, 0);

/// The (de)compression algorithm could not allocate enough memory for the
/// (de)compression.
CONST_UINT8_T(SCAN_COMPRESSION_NO_MEMORY, 1);

/// Magic number mismatch on scan decompression
CONST_UINT8_T(SCAN_DECOMPRESSION_MAGIC_ERROR, 2);

/// Decompression size error
///
/// Decompression produced a string of a size different than indicated in the
/// header, indicating either a bug or data corruption.  Note that the entire
/// application should be considered corrupted if this error occurs since it
/// may not be discovered until after the decompression buffer is
/// overrun. This error may also be returned by rs4_redundant() in the event
/// of inconsistencies in the compressed string.
CONST_UINT8_T(SCAN_DECOMPRESSION_SIZE_ERROR, 3);

/// A buffer would overflow
///
/// Either the caller-supplied memory buffer to _rs4_decompress() was too
/// small to contain the decompressed string, or a caller-supplied buffer to
/// _rs4_compress() was not large enough to hold the worst-case compressed
/// string.
CONST_UINT8_T(SCAN_COMPRESSION_BUFFER_OVERFLOW, 4);

/// @}

#endif  //  __P8_SCAN_COMPRESSION_H__
