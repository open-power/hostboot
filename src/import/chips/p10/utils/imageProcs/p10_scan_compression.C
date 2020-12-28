/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_scan_compression.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

/// RS4 Compression Format (version 2)
/// ==================================
///
/// Scan strings are compressed using a simple run-length encoding called
/// RS4. The string to be decompressed and scanned is the difference between
/// the current state of the ring and the desired final state of the ring.
///
/// Both the data to be compressed and the final compressed data are treated
/// as strings of 4-bit nibbles. In the scan data structure the compressed
/// strings are padded with 0x0 nibbles to the next even multiple of 4.  The
/// compressed string consists of control nibbles and data nibbles.  The string
/// format includes a special control/data sequence that marks the end marks
/// the end of the string and the final bits of scan data.  The string is zero
/// padded to ensure 4-byte alignment.
///
/// Special control/data sequences have been been added for RS4v2 to store
/// pairs of care mask nibble and data nibble.  This enhancement is needed
/// to allow the scanning of significant zeros.  The RS4v1 format assumed
/// that all zeros have no meaning other than the positioning of 1 bits.
///
/// Runs of 0x0 nibbles as determined by the care mask (rotates) are encoded
/// using a simple variable-length integer encoding known as a "stop code".
/// This code treats each nibble in a variable-length integer encoding as an
/// octal digit (the low-order 3 bits) plus a stop bit (the high-order bit).
/// The examples below illustrate the encoding.
///
///     1xxx            - Rotate 0bxxx       nibbles (0 - 7)
///     0xxx 1yyy       - Rotate 0bxxxyyy    nibbles (8 - 63)
///     0xxx 0yyy 1zzz  - Rotate 0bxxxyyyzzz nibbles (64 - 511)
///     etc.
///
/// A 0-length rotate (code 0b1000) is needed to resynchronize the state
/// machine in the event of long scans (see below), or a string that begins
/// with a non-0x0 nibble.
///
/// Runs of non-0x0 nibbles (scans) are inserted verbatim into the compressed
/// string after a control nibble indicating the number of nibbles of
/// uncompressed data.  (Note that an isolated 0x0 in between non-0x0 nibbles
/// is permitted for efficiency reasons).  If a run is longer than 14 nibbles,
/// the compression algorithm must insert a 0-length rotate (0b1000) and a new
/// scan-length control before continuing with the non-0 data nibbles.
///
///     xxxx - Scan 0bxxxx nibbles which follow, 0bxxxx != 0 and 0bxxxx != 15
///
/// The special case of a 0b0000 code where a scan count is expected marks the
/// end of the string.  The end of string marker is always followed by a
/// nibble that contains the terminal bit count in the range 0-3.  If the
/// length of the original binary string was not an even multiple of 4, then a
/// final nibble contains the final scan data left justified.
///
///     0000 00nn [ttt0] - Terminate 0bnn bits, data 0bttt0 if 0bnn != 0
///
/// The special case of a 0b1111 code where a scan count is expected announces
/// a pair of care mask nibble and data nibble containing significant zeros.
/// Only a single pair can be stored this way, and longer sequences of such
/// pairs require resynchronization using zero rotates and special scan count
/// 0b1111 to be inserted.
///
/// Termination with care mask and data is accomplished by a special terminal
/// data count:
///
///     0000 10nn [ccc0] [ttt0] - Terminate
///                               0bnn bits care mask and 0bnn bits data,
///                               care mask 0bccc0 and data 0bttt0 if 0bnn != 0
///
/// BNF Grammar
/// ===========
///
/// Following is a BNF grammar for the strings accepted by the RS4
/// decompression and scan algorithm. At a high level, the state machine
/// recognizes a series of 1 or more sequences of a rotate (R) followed by a
/// scan (S) or end-of-string marker (E), followed by the terminal count (T)
/// and optional terminal data (D).
///
///     (R S)* (R E) T D?
///
/// \code
///
/// <rs4_string>             ::= <rotate> <terminate> |
///                              <rotate> <scan> <rs4_string>
///
/// <rotate>                 ::= <octal_stop> |
///                              <octal_go> <rotate>
///
/// <octal_go>               ::= '0x0' | ... | '0x7'
///
/// <octal_stop>             ::= '0x8' | ... | '0xf'
///
/// <scan>                   ::= <scan_count(N)> <data(N)> |
///                              <scan_count(15)> <care_data>
///
/// <scan_count(N)>          ::= * 0bnnnn, for N = 0bnnnn, N != 0  &  N != 15 *
///
/// <scan_count(15)>         ::= '0xf'
///
/// <data(N)>                ::= * N nibbles of uncompressed data, 0 < N < 15 *
///
/// <care_data>              ::= * 0bijkl 0bwxyz, for
///                                i >= w  &  j >= x  &  k >= y  &  l >= z  &
///                                ijkl > wxyz *
///
/// <terminate>              ::= '0x0' <terminal_count(0)> |
///                              '0x0' <terminal_count(T, T > 0)> <terminal_data(T)> |
///                              '0x0' <terminal_care_count(T, T > 0)> <terminal_care_data(T)>
///
/// <terminal_count(T)>      ::= * 0b00nn, for T = 0bnn *
///
/// <terminal_care_count(T)> ::= * 0b10nn, for T = 0bnn  &  T != 0 *
///
/// <terminal_data(1)>       ::= '0x0' | '0x8'
///
/// <terminal_data(2)>       ::= '0x0' | '0x4' | '0x8' | '0xc'
///
/// <terminal_data(3)>       ::= '0x0' | '0x2' | '0x4' | ... | '0xe'
///
/// <terminal_care_data(1)>  ::= * 0b1000 0b0000 *
///
/// <terminal_care_data(2)>  ::= * 0bij00 0bwx00, for
///                                i >= w  &  j >= x  &
///                                ij > wx *
///
/// <terminal_care_data(3)>  ::= * 0bijk0 0bwxy0, for
///                                i >= w  &  j >= x  &  k >= y  &
///                                ijk > wxy *
///
/// \endcode

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <endian.h>
#include "p10_scan_compression.H"
#include "p10_infrastruct_help.H"

// Diagnostic aids for debugging
#ifdef DEBUG_P10_SCAN_COMPRESSION

#include <stdio.h>

#define BUG(rc)                                     \
    ({                                              \
        fprintf(stderr,"%s:%d : Trapped rc = %d\n", \
                __FILE__, __LINE__, (rc));          \
        (rc);                                       \
    })

#define BUGX(rc, ...)                           \
    ({                                          \
        BUG(rc);                                \
        fprintf(stderr, ##__VA_ARGS__);         \
        (rc);                                   \
    })

#else

#define BUG(rc) (rc)
#define BUGX(rc, ...) (rc)

#endif  // DEBUG_P10_SCAN_COMPRESSION

// Note: PHYP requires that all subroutines, _even static subroutines_, have
// unique names to support concurrent update.  Most routines defined here have
// some variant of 'rs4' in their names; others should be inherently unique.

#if RS4_VERSION != 5
    #error This code assumes CompressedScanData structure version 4 layout
#endif

void
compressed_scan_data_translate(CompressedScanData* o_rs4,
                               CompressedScanData* i_rs4)
{
    o_rs4->iv_magic    = htobe16(i_rs4->iv_magic);
    o_rs4->iv_version  =         i_rs4->iv_version;
    o_rs4->iv_type     =         i_rs4->iv_type;
    o_rs4->iv_size     = htobe16(i_rs4->iv_size);
    o_rs4->iv_ringId   = htobe16(i_rs4->iv_ringId);
    o_rs4->iv_selector = htobe16(i_rs4->iv_selector);
    o_rs4->iv_scanAddr = htobe32(i_rs4->iv_scanAddr);
}


// Return a big-endian-indexed nibble from a byte string

static int
rs4_get_nibble(const uint8_t* i_string, const uint32_t i_i)
{
    uint8_t byte;
    int nibble;

    byte = i_string[i_i / 2];

    if (i_i % 2)
    {
        nibble = byte & 0xf;
    }
    else
    {
        nibble = byte >> 4;
    }

    return nibble;
}


// Set a big-endian-indexed nibble in a byte string

static int
rs4_set_nibble(uint8_t* io_string, const uint32_t i_i, const int i_nibble)
{
    uint8_t* byte;

    byte = &(io_string[i_i / 2]);

    if (i_i % 2)
    {
        *byte = (*byte & 0xf0) | i_nibble;
    }
    else
    {
        *byte = (*byte & 0x0f) | (i_nibble << 4);
    }

    return i_nibble;
}


// Encode an unsigned integer into a 4-bit octal stop code directly into a
// nibble stream at io_string<i_i>, returning the number of nibbles in the
// resulting code.

static int
rs4_stop_encode(const uint32_t i_count, uint8_t* io_string, const uint32_t i_i)
{
    uint32_t count;
    int digits, offset;

    // Determine the number of octal digits.  There is always at least 1.

    count = i_count >> 3;
    digits = 1;

    while (count)
    {
        count >>= 3;
        digits++;
    }

    // First insert the stop (low-order) digit

    offset = digits - 1;
    rs4_set_nibble(io_string, i_i + offset, (i_count & 0x7) | 0x8);

    // Now insert the high-order digits

    count = i_count >> 3;
    offset--;

    while (count)
    {
        rs4_set_nibble(io_string, i_i + offset, count & 0x7);
        offset--;
        count >>= 3;
    }

    return digits;
}


// Decode an unsigned integer from a 4-bit octal stop code appearing in a byte
// string at i_string<i_i>, returning the number of nibbles decoded.

static int
stop_decode(uint32_t* o_count, const uint8_t* i_string, const uint32_t i_i)
{
    int digits, nibble;
    uint32_t i, count;

    digits = 0;
    count = 0;
    i = i_i;

    do
    {
        nibble = rs4_get_nibble(i_string, i);

        if (digits == 0 && nibble == 0)
        {
            //A stop sequence cannot start with a zero. If it does, this
            //indicates either a damaged ring image or encoding bug.
            return -1;
        }

        count = (count * 8) + (nibble & 0x7);
        i++;
        digits++;
    }
    while ((nibble & 0x8) == 0);

    *o_count = count;
    return digits;
}


// RS4 compression algorithm notes:
//
// RS4 compression processes i_data_str/i_care_str as a strings of nibbles.
// Final special-case code handles the 0-3 remaining terminal bits.
//
// There is a special case for 0x0 nibbles embedded in a string of non-0x0
// nibbles. It is more efficient to encode a single 0x0 nibble as part of a
// longer string of non-0x0 nibbles.  However it is break-even (actually a
// slight statistical advantage) to break a scan sequence for two consecutive
// 0x0 nibbles.
//
// If a run of 14 scan nibbles is found the scan is terminated and we return
// to the rotate state.  Runs of more than 14 scans will always include a
// 0-length rotate between the scan sequences.
//
// The ability to store a 15th consecutive scan nibble was given up for an
// enhancement of the compression algorithm:
// The scan count 15 has a special meaning and is reserved for handling
// single nibbles that come with a care mask, that is, an extra nibble that
// determines the significance of scan bits, including both 1 and 0 bits.
//
// Returns a scan compression return code.

static int
__rs4_compress(uint8_t* o_rs4_str,
               uint32_t* o_nibbles,
               const uint8_t* i_data_str,
               const uint8_t* i_care_str,
               const uint32_t i_length)
{
    int state;                  /* 0 : Rotate, 1 : Scan one-data, 2 : Scan zero-data */
    uint32_t n;                 /* Number of whole nibbles in i_data */
    uint32_t r;                 /* Number of reminaing bits in i_data */
    uint32_t i;                 /* Nibble index in i_data_str/i_care_str */
    uint32_t j;                 /* Nibble index in o_rs4_str */
    uint32_t k;                 /* Location to place <scan_count(N)> */
    uint32_t count;             /* Counts *raw* rotate/scan nibbles */
    int care_nibble;
    int data_nibble;

    n = i_length / 4;
    r = i_length % 4;
    i = 0;
    j = 0;
    k = 0;                      /* Makes GCC happy */
    care_nibble = 0;
    data_nibble = 0;
    count = 0;
    state = 0;

    // Process the bulk of the string.  Note that state changes do not
    // increment 'i' - the nibble at i_data<i> is always scanned again.

    while (i < n)
    {
        care_nibble = rs4_get_nibble(i_care_str, i);
        data_nibble = rs4_get_nibble(i_data_str, i);

        if (~care_nibble & data_nibble)
        {
            MY_ERR("ERROR: __rs4_compress: Conflicting Care and Data bits in raw"
                   " ring at nibble[%u]=(0x%x,0x%x)\n",
                   i, care_nibble, data_nibble);
            return SCAN_COMPRESSION_CAREDATA_CONFLICT;
        }

        if (state == 0)
            //----------------//
            // Rotate section //
            //----------------//
        {
            if (care_nibble == 0)
            {
                count++;
                i++;
            }
            else
            {
                j += rs4_stop_encode(count, o_rs4_str, j);
                count = 0;
                k = j;
                j++;

                if ((care_nibble ^ data_nibble) == 0)
                {
                    // Only one-data in nibble.
                    state = 1;
                }
                else
                {
                    // There is zero-data in nibble.
                    state = 2;
                }
            }
        }
        else if (state == 1)
            //------------------//
            // One-data section //
            //------------------//
        {
            if (care_nibble == 0)
            {
                if (((i + 1) < n) && (rs4_get_nibble(i_care_str, i + 1) == 0))
                {
                    // Set the <scan_count(N)> in nibble k since no more data in
                    //   current AND next nibble (or next nibble might be last).
                    rs4_set_nibble(o_rs4_str, k, count);
                    count = 0;
                    state = 0;
                }
                else
                {
                    // Whether next nibble is last nibble or contains data, lets include the
                    //   current empty nibble in the scan_data(N) count because its
                    //   more efficient than inserting rotate go+stop nibbles.
                    rs4_set_nibble(o_rs4_str, j, 0);
                    count++;
                    i++;
                    j++;
                }
            }
            else if ((care_nibble ^ data_nibble) == 0)
            {
                // Only one-data in nibble. Continue pilling on one-data nibbles.
                rs4_set_nibble(o_rs4_str, j, data_nibble);
                count++;
                i++;
                j++;
            }
            else
            {
                // There is zero-data in nibble.
                // Set the <scan_count(N)> in nibble k to end current sequence of
                //   one-data nibbles.
                rs4_set_nibble(o_rs4_str, k, count);
                count = 0;
                state = 0;
            }

            if ((state == 1) && (count == 14))
            {
                // Set <scan_count(14)> in nibble k to end max allowed sequence of
                //   one-data nibbles.
                rs4_set_nibble(o_rs4_str, k, 14);
                count = 0;
                state = 0;
            }
        }
        else // state==2
            //-------------------//
            // Zero-data section //
            //-------------------//
        {
            rs4_set_nibble(o_rs4_str, k, 15);
            rs4_set_nibble(o_rs4_str, j, care_nibble);
            j++;
            rs4_set_nibble(o_rs4_str, j, data_nibble);
            i++;
            j++;
            count = 0;
            state = 0;
        }
    } // End of while (i<n)

    // Finish the current state and insert the terminate code (0x0).  Note that
    // if we finish on a scan we also must insert a zero rotate code (0x8).

    if (state == 0)
    {
        // Here we either finish a rotate or insert a zero rotate code.
        j += rs4_stop_encode(count, o_rs4_str, j);
    }
    else if (state == 1)
    {
        // Finish the scan, then insert zero rotate code.
        rs4_set_nibble(o_rs4_str, k, count);
        j += rs4_stop_encode(0, o_rs4_str, j);
    }
    else
    {
        return BUGX(SCAN_COMPRESSION_STATE_ERROR,
                    "Termination can not immediately follow masked data\n");
    }

    // Indicate termination start
    rs4_set_nibble(o_rs4_str, j, 0);
    j++;

    // Insert the remainder count nibble, and if r>0, the remainder data
    // nibble. Note that here we indicate the number of bits (0<=r<4).
    if (r == 0)
    {
        rs4_set_nibble(o_rs4_str, j, r);
        j++;
    }
    else
    {
        care_nibble = rs4_get_nibble(i_care_str, n) & ((0xf >> (4 - r)) << (4 - r)); // Make excess bits zero
        data_nibble = rs4_get_nibble(i_data_str, n) & ((0xf >> (4 - r)) << (4 - r)); // Make excess bits zero

        if (~care_nibble & data_nibble)
        {
            MY_ERR("ERROR: __rs4_compress: Conflicting [term] Care and Data bits in raw"
                   " ring at nibble[%u]=(0x%x,0x%x)\n",
                   i, care_nibble, data_nibble);
            return SCAN_COMPRESSION_CAREDATA_CONFLICT;
        }

        if ((care_nibble ^ data_nibble) == 0)
        {
            // Only one-data in rem nibble.
            rs4_set_nibble(o_rs4_str, j, r);
            j++;
            rs4_set_nibble(o_rs4_str, j, data_nibble);
            j++;
        }
        else
        {
            // Zero-data in rem nibble.
            rs4_set_nibble(o_rs4_str, j, r + 8);
            j++;
            rs4_set_nibble(o_rs4_str, j, care_nibble);
            j++;
            rs4_set_nibble(o_rs4_str, j, data_nibble);
            j++;
        }
    }

    *o_nibbles = j;

    return SCAN_COMPRESSION_OK;
}


// The worst-case compression for RS4 v2 occurs if all data nibbles
// contain significant zeros as specified by corresponding care nibbles,
// and if the raw ring length is a whole multiple of four.
//
// In general, each data and care nibble pair, which are one nibble
// in terms of input string length, are compressed into 4 nibbles:
//
// 1. a special data count nibble that indicates special case with care mask
// 2. a care mask nibble
// 3. a data nibble
// 4. a rotate nibble
//
// Then, if the raw ring length is a whole multiple of four (worst case),
// the last raw nibble also requires those RS4 four nibbles, and it is
// followed by 2 additional nibbles that terminate the compressed data.
// So a total of six nibbles to account for the last input nibble:
//
// 5. a '0x0' terminate nibble
// 6. a terminal count(0) nibble
//
// If on the other hand the last input nibble is partial, then that requires
// only four output nibbles because the terminate tag and data are combined
// in the encoding of <terminate>:
//
// 1. a '0x0' terminate nibbel
// 2. a terminal count nibble for masked data
// 3. a care mask nibble
// 4. a data nibble
//
// Besides there is always a rotate nibble at the begin of the compressed
// data:
//
// 0. rotate

static inline uint32_t
rs4_max_compressed_nibbles(const uint32_t i_length)
{
    uint32_t nibbles_raw, nibbles_rs4;

    nibbles_raw = (i_length + 3) / 4;    // bits rounded up to full nibbles
    nibbles_rs4 = 1                      // initial rotate nibble
                  + nibbles_raw * 4      // worst case whole nibble encoding
                  + 1                    // terminate nibble
                  + 1;                   // zero terminal count nibble

    return nibbles_rs4;
}

static inline uint32_t
rs4_max_compressed_bytes(uint32_t nibbles)
{
    uint32_t bytes;

    bytes  = ((nibbles + 1) / 2);        // nibbles rounded up to full bytes
    bytes += sizeof(CompressedScanData); // plus rs4 header
    bytes  = ((bytes + 3) / 4) * 4;      // rounded up to multiple of 4 bytes

    return bytes;
}


// We always require the worst-case amount of memory including the header and
// any rounding required to guarantee that the data size is a multiple of 4
// bytes. The final image size is also rounded up to a multiple of 4 bytes.
//
// Returns a scan compression return code.

int
_rs4_compress(CompressedScanData* io_rs4,
              const uint32_t i_size,
              const uint8_t* i_data_str,
              const uint8_t* i_care_str,
              const uint32_t i_length,
              const uint32_t i_scanAddr,
              const RingId_t i_ringId,
              const uint16_t i_selector,
              const uint8_t  i_type)
{
    int rc;
    uint32_t nibbles = rs4_max_compressed_nibbles(i_length);
    uint32_t bytes   = rs4_max_compressed_bytes(nibbles);
    uint8_t* rs4_str = (uint8_t*)io_rs4 + sizeof(CompressedScanData);

    if (bytes > i_size)
    {
        return BUG(SCAN_COMPRESSION_BUFFER_OVERFLOW);
    }

    memset(io_rs4, 0, i_size);

    rc = __rs4_compress(rs4_str, &nibbles, i_data_str, i_care_str, i_length);

    if (rc == SCAN_COMPRESSION_OK)
    {
        bytes = rs4_max_compressed_bytes(nibbles);

        io_rs4->iv_magic    = htobe16(RS4_MAGIC);
        io_rs4->iv_version  = RS4_VERSION;
        //io_rs4->iv_type is set below after sanity checking i_type
        io_rs4->iv_size     = htobe16(bytes);
        io_rs4->iv_ringId   = htobe16(i_ringId);
        io_rs4->iv_scanAddr = htobe32(i_scanAddr);
        io_rs4->iv_selector = htobe16(i_selector);
        io_rs4->iv_undefined = 0;

        // Check for valid iv_type

        // flush/override - any non-zero will do
        if ( i_type & RS4_IV_TYPE_SCAN_MASK )
        {
            // Valid flush/override settings.
        }
        else
        {
            return BUGX(SCAN_COMPRESSION_IV_TYPE_ERROR,
                        "_rs4_compress: Invalid iv_type(=0x%02x) value for flush/ovrd settings\n",
                        i_type);
        }

        // origination - any non-zero will do
        if ( i_type & RS4_IV_TYPE_ORIG_MASK )
        {
            // Valid ring origination settings.
        }
        else
        {
            return BUGX(SCAN_COMPRESSION_IV_TYPE_ERROR,
                        "_rs4_compress: Invalid iv_type(=0x%02x) value for ring origination"
                        " settings\n",
                        i_type);
        }

        io_rs4->iv_type     = i_type;
    }

    return rc;
}


// We always allocate the worst-case amount of memory including the header
// and any rounding required to guarantee that the allocated length is a
// multiple of 4 bytes.  The final size is also rounded up to a multiple of 4
// bytes.
//
// Returns a scan compression return code.

int
rs4_compress(CompressedScanData** o_rs4,
             const uint8_t* i_data_str,
             const uint8_t* i_care_str,
             const uint32_t i_length,
             const uint32_t i_scanAddr,
             const RingId_t i_ringId,
             const uint16_t i_selector,
             const uint8_t  i_type)
{
    uint32_t nibbles = rs4_max_compressed_nibbles(i_length);
    uint32_t bytes   = rs4_max_compressed_bytes(nibbles);

    *o_rs4  = (CompressedScanData*)(operator new(bytes));

    if (*o_rs4 == 0)
    {
        return BUG(SCAN_COMPRESSION_NO_MEMORY);
    }

    return _rs4_compress(*o_rs4, bytes,
                         i_data_str, i_care_str, i_length,
                         i_scanAddr, i_ringId, i_selector, i_type);
}


// Decompress an RS4-encoded string into a output string whose length must be
// exactly i_length bits.
//
// Returns a scan compression return code.

static int
__rs4_decompress(uint8_t* o_data_str,
                 uint8_t* o_care_str,
                 uint32_t i_size,
                 uint32_t* o_length,
                 const uint8_t* i_rs4_str)
{
    int state;                  /* 0 : Rotate, 1 : Scan */
    uint32_t i;                 /* Nibble index in i_rs4_str */
    uint32_t j;                 /* Nibble index in o_data_str/o_care_str */
    uint32_t k;                 /* Loop index */
    uint32_t bits;              /* Number of output bits decoded so far */
    uint32_t count;             /* Counts *raw* rotate nibbles */
    int      nibbles;           /* Rotate or scan RS4 nibbles to process */
    int r;                      /* Remainder bits */
    int masked;                 /* if a care mask is available */
    uint8_t  careNibble;
    uint8_t  dataNibble;

    i = 0;
    j = 0;
    bits = 0;
    state = 0;

    // Decompress the bulk of the string
    do
    {
        if (state == 0)
        {
            nibbles = stop_decode(&count, i_rs4_str, i);

            if (nibbles == -1)
            {
                MY_ERR("ERROR: __rs4_decompress: Error in the RS4 stop sequence\n");
                return SCAN_COMPRESSION_STOP_DECODE_ERROR;
            }

            i += nibbles;

            bits += 4 * count;

            if (bits > i_size * 8)
            {
                return BUG(SCAN_COMPRESSION_BUFFER_OVERFLOW);
            }

            // keep 'count' zero care and data nibbles
            // as initialised by memset in calling function
            j += count;

            state = 1;
        }
        else
        {
            nibbles = rs4_get_nibble(i_rs4_str, i);
            i++;

            if (nibbles == 0)
            {
                break;
            }

            masked = (nibbles == 15 ? 1 : 0);
            nibbles = (masked ? 1 : nibbles);
            bits += 4 * nibbles;

            if (bits > i_size * 8)
            {
                return BUG(SCAN_COMPRESSION_BUFFER_OVERFLOW);
            }


            if (masked)
            {
                careNibble = rs4_get_nibble(i_rs4_str, i);
                dataNibble = rs4_get_nibble(i_rs4_str, i + 1);

                if (~careNibble & dataNibble)
                {
                    MY_ERR("ERROR: __rs4_decompress: Conflicting care and data bits in RS4"
                           " ring at nibbles(%u,%u)=(0x%x,0x%x)\n",
                           i, i + 1, careNibble, dataNibble);
                    return SCAN_COMPRESSION_CAREDATA_CONFLICT;
                }

                rs4_set_nibble(o_care_str, j, careNibble);
                rs4_set_nibble(o_data_str, j, dataNibble);
                i += 2;
                j++;
            }
            else
            {
                for (k = 0; k < (uint8_t)nibbles; k++) //nibbles always <15 here
                {
                    dataNibble = rs4_get_nibble(i_rs4_str, i);
                    rs4_set_nibble(o_care_str, j, dataNibble); //care=data here
                    rs4_set_nibble(o_data_str, j, dataNibble);
                    i++;
                    j++;
                }
            }

            state = 0;
        }
    }
    while (1);

    // Now handle string termination

    nibbles = rs4_get_nibble(i_rs4_str, i);
    i++;

    masked = nibbles & 0x8;
    r = nibbles & 0x3;
    bits += r;

    if (bits > i_size * 8)
    {
        return BUG(SCAN_COMPRESSION_BUFFER_OVERFLOW);
    }

    if (r != 0)
    {
        if (masked)
        {
            careNibble = rs4_get_nibble(i_rs4_str, i);
            dataNibble = rs4_get_nibble(i_rs4_str, i + 1);

            if (~careNibble & dataNibble)
            {
                MY_ERR("ERROR: __rs4_decompress: Conflicting [term] care and data bits in RS4"
                       " ring at nibbles(%u,%u)=(0x%x,0x%x)\n",
                       i, i + 1, careNibble, dataNibble);
                return SCAN_COMPRESSION_CAREDATA_CONFLICT;
            }

            rs4_set_nibble(o_care_str, j, careNibble);
            rs4_set_nibble(o_data_str, j, dataNibble);
        }
        else
        {
            dataNibble = rs4_get_nibble(i_rs4_str, i);
            rs4_set_nibble(o_care_str, j, dataNibble); //care=data here
            rs4_set_nibble(o_data_str, j, dataNibble);
        }
    }

    *o_length = bits;
    return SCAN_COMPRESSION_OK;
}


int
_rs4_decompress(uint8_t* o_data_str,
                uint8_t* o_care_str,
                uint32_t i_size,
                uint32_t* o_length,
                const CompressedScanData* i_rs4)
{
    uint8_t* rs4_str = (uint8_t*)i_rs4 + sizeof(CompressedScanData);

    if (be16toh(i_rs4->iv_magic) != RS4_MAGIC)
    {
        return BUG(SCAN_COMPRESSION_MAGIC_ERROR);
    }

    if (i_rs4->iv_version != RS4_VERSION)
    {
        return BUG(SCAN_COMPRESSION_VERSION_ERROR);
    }

    memset(o_data_str, 0, i_size);
    memset(o_care_str, 0, i_size);

    return __rs4_decompress(o_data_str, o_care_str, i_size, o_length, rs4_str);
}


int
rs4_decompress(uint8_t** o_data_str,
               uint8_t** o_care_str,
               uint32_t* o_length,
               const CompressedScanData* i_rs4)
{
    uint32_t size = MAX_RING_BUF_SIZE_TOOL;
    int rc;

    *o_data_str = (uint8_t*)(operator new(size));

    if (*o_data_str == NULL)
    {
        return BUG(SCAN_COMPRESSION_NO_MEMORY);
    }

    *o_care_str = (uint8_t*)(operator new(size));

    if (*o_care_str == NULL)
    {
        operator delete(*o_data_str);
        *o_data_str = NULL;
        return BUG(SCAN_COMPRESSION_NO_MEMORY);
    }

    rc = _rs4_decompress(*o_data_str, *o_care_str, size, o_length, i_rs4);

    if (rc != SCAN_COMPRESSION_OK)
    {
        operator delete(*o_data_str);
        operator delete(*o_care_str);
        *o_data_str = NULL;
        *o_care_str = NULL;
    }

    return rc;
}


// Get the raw bit length of an RS4 string by decompressing the string and
// counting the bits along the way but ** without ** saving the raw
// decompressed bit stream (ie, zero buffer space required).

int
rs4_get_raw_bit_length( uint32_t& o_length,
                        const CompressedScanData* i_rs4 )
{
    int state;                  /* 0 : Rotate, 1 : Scan */
    uint32_t i;                 /* Nibble index in i_rs4Str */
    uint32_t k;                 /* Loop index */
    uint32_t bits;              /* Number of output bits decoded so far */
    uint32_t count;             /* Counts *raw* rotate nibbles */
    int      nibbles;           /* Rotate or scan RS4 nibbles to process */
    int r;                      /* Remainder bits */
    int masked;                 /* if a care mask is available */

    uint8_t* rs4Str = (uint8_t*)i_rs4 + sizeof(CompressedScanData);

    i = 0;
    bits = 0;
    state = 0;

    // Decompress the bulk of the string
    do
    {
        if (state == 0)
        {
            nibbles = stop_decode(&count, rs4Str, i);

            if (nibbles == -1)
            {
                MY_ERR("ERROR: rs4_get_raw_bit_length: Error in the RS4 stop sequence\n");
                return SCAN_COMPRESSION_STOP_DECODE_ERROR;
            }

            i += nibbles;

            bits += 4 * count;

            state = 1;
        }
        else
        {
            nibbles = rs4_get_nibble(rs4Str, i);
            i++;

            if (nibbles == 0)
            {
                break;
            }

            masked = (nibbles == 15 ? 1 : 0);
            nibbles = (masked ? 1 : nibbles);
            bits += 4 * nibbles;

            for (k = 0; k < (uint8_t)nibbles; k++) //nibbles always <15 here
            {
                i = (masked ? i + 1 : i);
                i++;
            }

            state = 0;
        }
    }
    while (1);

    // Now handle string termination

    nibbles = rs4_get_nibble(rs4Str, i);
    i++;

    masked = nibbles & 0x8;
    r = nibbles & 0x3;
    bits += r;

    if (r != 0)
    {
        i = (masked ? i + 1 : i);
    }

    // Sanity check that the RS4 nibble count, i, is <= RS4 string length from header x 2
    if (i > 2 * (be16toh(i_rs4->iv_size) - sizeof(CompressedScanData)))
    {
        MY_ERR("ERROR: rs4_get_raw_bit_length: The decoded number of  RS4 nibbles, i=%u, is"
               " inconsistent with the RS4 string length indicated in the header, iv_size=%u\n",
               i, be16toh(i_rs4->iv_size));
        return SCAN_COMPRESSION_RS4_SIZE_ERROR;
    }

    o_length = bits;

    return SCAN_COMPRESSION_OK;
}


// Check if the ring content will result in no latches being changed
int
rs4_redundant(const CompressedScanData* i_data, MyBool_t& o_redundant)
{
    uint8_t* data;
    uint32_t count;
    int      nibbles;

    o_redundant = false;

    if (htobe16(i_data->iv_magic) != RS4_MAGIC)
    {
        return BUG(SCAN_COMPRESSION_MAGIC_ERROR);
    }

    data = (uint8_t*)i_data + sizeof(CompressedScanData);

    // A compressed scan string is redundant if the initial rotate is
    // followed by the end-of-string marker, and any remaining mod-4 bits
    // are also 0.

    nibbles = stop_decode(&count, data, 0);

    if (nibbles == -1)
    {
        MY_ERR("ERROR: rs4_redundant: Error in the RS4 stop sequence\n");
        return SCAN_COMPRESSION_STOP_DECODE_ERROR;
    }

    if (rs4_get_nibble(data, nibbles) == 0)
    {
        if (rs4_get_nibble(data, nibbles + 1) == 0)
        {
            o_redundant = true;
        }
        else
        {
            if (rs4_get_nibble(data, nibbles + 2) == 0)
            {
                o_redundant = true;
            }
        }
    }

    return SCAN_COMPRESSION_OK;
}


// Check if RS4 container contains a ring intended to be scanned onto
// a scan chain that's been previously scanned (ie, Override scan mode)
// or a scan chain in flush state (ie, Flush scan mode)
MyBool_t
rs4_is_ovrd(const CompressedScanData* i_rs4)
{
    switch (i_rs4->iv_type & RS4_IV_TYPE_SCAN_MASK)
    {
        case RS4_IV_TYPE_SCAN_OVRD:
            return true;

        case RS4_IV_TYPE_SCAN_FLUSH:
            return false;

        default:
            return UNDEFINED_BOOLEAN;
    }

    return UNDEFINED_BOOLEAN;
}


// ************************************************************************* //
//         Overlay and Raw4 Scan Data (De)Compression Functions              //
// ************************************************************************* //

#define RAW4_MAGIC 0x52415734       /* "RAW4" */
//#define RAW4_VERSION 1
#define RAW4_VERSION 2  // 4-byte records, nibbles field dropped

typedef struct
{
    uint32_t magic;
    uint16_t version;
    uint16_t recs;    // Number of raw4 records.
    uint32_t size;    // Byte size of whole Raw4 container. No padding, No align.
    uint32_t bits;    // Raw ring bit count (of true *raw* ring).. No padding, No align
} Raw4ScanData_t;

typedef struct
{
    uint32_t nibbleIndex: 24; // Raw nibble index
    uint32_t careData: 8;     // Care+Data nibble pair
} Raw4Record_t;


//
// Compress a Raw4-encoded string into an RS4-encoded output string
//
static int
__rs4_compress_from_raw4( uint8_t* o_rs4Str,
                          const uint32_t i_bufSize,
                          uint32_t& o_nibbles,
                          const Raw4ScanData_t* i_raw4,
                          const uint8_t i_dbgl )
{
    int rc = SCAN_COMPRESSION_OK;

    int state;                  /* 0 : Rotate, 1 : Scan one-data, 2 : Scan zero-data */
    uint32_t i;                 /* Nibble index in raw bit stream */
    uint32_t j;                 /* Nibble index in o_rs4Str */
    uint32_t k;                 /* Location to place <scan_count(N)> */
    uint32_t count;             /* Counts rotate or scan *raw* nibbles */
    uint8_t careNibble;
    uint8_t dataNibble;

    if (i_dbgl)
    {
        MY_ERR("\nIn __rs4_compress_from_raw4:\n"
               "raw4 recs = %u\n"
               "raw4 size = %u\n"
               "raw4 bits = %u\n",
               i_raw4->recs, i_raw4->size, i_raw4->bits);

        for (uint32_t idx = 0; idx < i_raw4->recs; idx++)
        {
            MY_ERR("0x%06x", ((Raw4Record_t*)((uint8_t*)i_raw4 + sizeof(Raw4ScanData_t) + sizeof(
                                                  Raw4Record_t) * idx))->nibbleIndex);
            MY_ERR("%02x\n", ((Raw4Record_t*)((uint8_t*)i_raw4 + sizeof(Raw4ScanData_t) + sizeof(Raw4Record_t) * idx))->careData);
        }

        MY_ERR("\n");
    }

    i = 0;
    j = 0;
    k = 0;                      /* Makes GCC happy */
    careNibble = 0;
    dataNibble = 0;
    count = 0;
    state = 0;

    // Save away the number of records and nibbles in our Raw4 ring
    uint32_t raw4Recs   = i_raw4->recs;
    uint32_t rawBits    = i_raw4->bits;    // Number of true raw bits
    uint32_t rawNibbles = (i_raw4->bits + 3) / 4; // This includes the rem nibble, if any
    uint32_t iRec = 0;
    bool     bLastRecord = false;
    int      wholeNibblesInRec = 0;
    int      remBits = rawBits & 0x3;

    // Process the bulk of the string.

    // Note that state changes do not necessarily increment 'i' - the raw nibble
    // 'i', and the same record,  may be read again sometimes, depending on where
    // in the state machine.

    // Get the first raw4 record to be processed
    Raw4Record_t* raw4Record = (Raw4Record_t*)((uint8_t*)i_raw4 + sizeof(Raw4ScanData_t));

    while (i < rawBits / 4)
    {
        careNibble = (raw4Record->careData & 0xf0) >> 4;
        dataNibble = raw4Record->careData & 0x0f;

        if (~careNibble & dataNibble)
        {
            MY_ERR("ERROR: __rs4_compress_from_raw4: Conflicting care and data bits in Raw4"
                   " record, R[%u] = {%u, 0x%02x}\n",
                   iRec, raw4Record->nibbleIndex, raw4Record->careData);
            return SCAN_COMPRESSION_CAREDATA_CONFLICT;
        }

        if ((iRec + 1) < raw4Recs)
        {
            wholeNibblesInRec = (raw4Record + 1)->nibbleIndex - raw4Record->nibbleIndex;
        }
        else
        {
            wholeNibblesInRec = rawBits / 4 - raw4Record->nibbleIndex;
            bLastRecord = true;
        }

        // Raw4 encoding rule checks:
        // Rule1:
        // - Any rec: nibbles != 0 (ie, a record cannot represent a 0-length nibble sequence)
        // - Scan rec: nibbles == 1 (ie, scan records must be exactly 1 nibble long)
        // Rule2:
        // - Rot rec: records must be separated by >=1 scan records
        // Rule3:
        // - First rec: NI == 0
        if ( wholeNibblesInRec <= 0 ) //Rule1
        {
            MY_ERR("ERROR: __rs4_compress_from_raw4: Nibble sequence length = %i not"
                   " allowed. (We're in record, R[%u] = {%u, 0x%02x}, raw4Recs = %u,"
                   " rawNibbles = %u, rawBits = %u and bLastRecord = %i)\n",
                   wholeNibblesInRec, iRec, raw4Record->nibbleIndex, raw4Record->careData,
                   raw4Recs, rawNibbles, rawBits, bLastRecord);
            return SCAN_COMPRESSION_RAW4_ERROR;
        }
        else if ( careNibble != 0 && wholeNibblesInRec > 1 ) //Rule1
        {
            MY_ERR("ERROR: __rs4_compress_from_raw4: Nibble sequences longer than one are not"
                   " allowed for scan nibbles. (We're in record, R[%u] = {%u, 0x%02x}, raw4Recs"
                   " = %u and rawNibbles = %u)\n",
                   iRec, raw4Record->nibbleIndex, raw4Record->careData,
                   raw4Recs, rawNibbles);
            return SCAN_COMPRESSION_RAW4_ERROR;
        }
        else if ( !bLastRecord &&
                  careNibble == 0 &&
                  ((raw4Record + 1)->careData & 0xf0) >> 4 == 0 ) //Rule2
        {
            MY_ERR("ERROR: __rs4_compress_from_raw4: Adjacent rotate records is not allowed."
                   " Rotate records must be separated by at least one scan record. (We're in"
                   " record, R[%u] = {%u, 0x%02x}, raw4Recs = %u and rawNibbles = %u)\n",
                   iRec, raw4Record->nibbleIndex, raw4Record->careData,
                   raw4Recs, rawNibbles);
            return SCAN_COMPRESSION_RAW4_ERROR;
        }
        else if ( iRec == 0 && raw4Record->nibbleIndex != 0 ) //Rule3
        {
            MY_ERR("ERROR: __rs4_compress_from_raw4: First record's NI=%u must be zero. (We're in"
                   " record, R[%u] = {%u, 0x%02x}, raw4Recs = %u and rawNibbles = %u)\n",
                   raw4Record->nibbleIndex, iRec, raw4Record->nibbleIndex, raw4Record->careData,
                   raw4Recs, rawNibbles);
            return SCAN_COMPRESSION_RAW4_ERROR;
        }

        //
        // Now compress to RS4
        //
        if (state == 0)
        {

            if (careNibble == 0)
            {
                count += wholeNibblesInRec;
                // Update Raw4 counts
                i += wholeNibblesInRec;   // raw nibble count
                raw4Record++; // next record
                iRec++;       // record count
            }
            else
            {
                // Encode a zero stop code first before encoding the scan.
                // Note that we end up here when
                // 1) ending a rotate sequence,
                // 2) data in first raw nibble, or
                // 3) after ending an RS4 scan sequence and preceeding another scan.
                j += rs4_stop_encode(count, o_rs4Str, j);
                k = j;        // scan count index location
                j++;
                count = 0;

                if ((careNibble ^ dataNibble) == 0)
                {
                    // Only one-data in nibble.
                    state = 1;
                }
                else
                {
                    // There is zero-data in nibble.
                    state = 2;
                }
            }
        }
        else if (state == 1)
        {
            if (careNibble == 0)
            {
                // Allow for a single zero data nibble within an RS4 scan sequence. But if
                // subsequent nibble is also zero, then we're entering a rotate... unless
                // next nibble is the last. But first we need to determine if there's more
                // records...
                if (!bLastRecord) //...more records
                {
                    // Check if more than one zero nibble in current zero record nibble sequence
                    if ((raw4Record + 1)->nibbleIndex > raw4Record->nibbleIndex + 1)
                    {
                        // Set the <scan_count(N)> in nibble k since no more data in
                        //   current AND next nibble.
                        rs4_set_nibble(o_rs4Str, k, count);
                        count = 0;
                        state = 0;
                    }
                    else
                    {
                        // Next nibble is adjacent to current zero nibble and therefore contains
                        // a non-zero nibble. So lets inlude the current zero nibble in the scan
                        // in the existing scan data(N) count because its more efficient than
                        // inserting a single rotate nibble.
                        rs4_set_nibble(o_rs4Str, j, 0);
                        j++;
                        count++;

                        // Update Raw4 counts
                        i++;
                        raw4Record++;
                        iRec++;
                    }
                }
                else              //...last record
                {
                    // Check if more than one zero nibble in current zero record nibble sequence
                    if ( ((uint32_t)(raw4Record->nibbleIndex + 2) < rawNibbles)  ||
                         ((uint32_t)(raw4Record->nibbleIndex + 2) == rawNibbles && !remBits) )
                    {
                        // Set the <scan_count(N)> in nibble k since no more data in
                        //   current AND next nibble.
                        rs4_set_nibble(o_rs4Str, k, count);
                        count = 0;
                        state = 0;
                    }
                    else if ( ((uint32_t)(raw4Record->nibbleIndex + 1) == rawNibbles && !remBits) ||
                              ((uint32_t)(raw4Record->nibbleIndex + 2) == rawNibbles && remBits) )
                    {
                        // This is either the last raw nibble (with *no* rem bits nibble following)
                        // or it's the 2nd last raw nibble (*with* a rem bits nibble following).
                        // In either case, we will include the current zero nibble in the existing
                        // scan data(N) count because its more efficient than inserting a single
                        // rotate nibble.
                        rs4_set_nibble(o_rs4Str, j, 0);
                        j++;
                        count++;

                        // Update Raw4 counts
                        i++;
                        raw4Record++;
                        iRec++;
                    }
                    else
                    {
                        MY_ERR("ERROR: __rs4_compress_from_raw4: We should never come here in"
                               " the last nibble. (We're in record, R[%u] = {%u, 0x%02x},"
                               " raw4Recs = %u and rawNibbles = %u)\n",
                               iRec, raw4Record->nibbleIndex, raw4Record->careData,
                               raw4Recs, rawNibbles);
                        return SCAN_COMPRESSION_STATE_ERROR;
                    }
                }
            }
            else if ((careNibble ^ dataNibble) == 0)
            {
                // Only one-data in nibble. Continue pilling on one-data nibbles.
                rs4_set_nibble(o_rs4Str, j, dataNibble);
                j++;
                count++;

                // Update Raw4 counts
                i++;
                raw4Record++;
                iRec++;
            }
            else
            {
                // There is zero-data in nibble.
                // Set the <scan_count(N)> in nibble k to end current sequence of
                //   one-data nibbles.
                rs4_set_nibble(o_rs4Str, k, count);
                count = 0;
                state = 0;
            }

            if ((state == 1) && (count == 14))
            {
                // Set <scan_count(14)> in nibble k to end max allowed sequence of
                //   one-data nibbles.
                rs4_set_nibble(o_rs4Str, k, 14);
                count = 0;
                state = 0;
            }
        }
        else // state==2
            //-------------------//
            // Zero-data section //
            //-------------------//
        {
            rs4_set_nibble(o_rs4Str, k, 15);
            rs4_set_nibble(o_rs4Str, j, careNibble);
            j++;
            rs4_set_nibble(o_rs4Str, j, dataNibble);
            j++;
            count = 0;
            state = 0;

            // Update Raw4 counts
            i++;
            raw4Record++;
            iRec++;
        }
    } // End of while (i<rawBits/4)

    // Finish the current state and insert the terminate code (0x0).  Note that
    // if we finish on a scan we also must insert a zero rotate code (0x8).

    if (state == 0)
    {
        // Here we either finish a rotate or insert a zero rotate code.
        j += rs4_stop_encode(count, o_rs4Str, j);
    }
    else if (state == 1)
    {
        // Finish the scan, then insert zero rotate code.
        rs4_set_nibble(o_rs4Str, k, count);
        j += rs4_stop_encode(0, o_rs4Str, j);
    }
    else
    {
        return BUGX(SCAN_COMPRESSION_STATE_ERROR,
                    "Termination can not immediately follow state=2 (masked data state)\n");
    }

    // Indicate termination start
    rs4_set_nibble(o_rs4Str, j, 0);
    j++;

    // Insert the remainder count nibble, and if remBits>0, the remainder data
    // nibble. Note that here we indicate the number of bits (0<=remBits<4).
    if (remBits == 0)
    {
        rs4_set_nibble(o_rs4Str, j, remBits);
        j++;
    }
    else
    {
        // Copy the rem bits and make sure trailing bits are zero
        careNibble = ((raw4Record->careData & 0xf0) >> 4) &
                     ((0xf >> (4 - remBits)) << (4 - remBits));
        dataNibble = (raw4Record->careData & 0x0f)        &
                     ((0xf >> (4 - remBits)) << (4 - remBits));

        if (~careNibble & dataNibble)
        {
            MY_ERR("ERROR: __rs4_compress_from_raw4: Conflicting termination care and data bits"
                   " in Raw4 record, R[%u] = {%u, 0x%02x} and remBits = %i\n",
                   iRec, raw4Record->nibbleIndex, raw4Record->careData, remBits);
            return SCAN_COMPRESSION_CAREDATA_CONFLICT;
        }

        if ((careNibble ^ dataNibble) == 0)
        {
            // Only one-data in rem nibble.
            rs4_set_nibble(o_rs4Str, j, remBits);
            j++;
            rs4_set_nibble(o_rs4Str, j, dataNibble);
            j++;
        }
        else
        {
            // Zero-data in rem nibble.
            rs4_set_nibble(o_rs4Str, j, remBits + 8);
            j++;
            rs4_set_nibble(o_rs4Str, j, careNibble);
            j++;
            rs4_set_nibble(o_rs4Str, j, dataNibble);
            j++;
        }
    }

    o_nibbles = j;

    return rc;
}


static int
_rs4_compress_from_raw4( CompressedScanData* o_rs4,
                         const uint32_t i_bufSize,
                         const uint8_t  i_ivType,
                         const RingId_t i_ringId,
                         const uint32_t i_scanAddr,
                         const uint16_t i_selector,
                         const Raw4ScanData_t* i_raw4,
                         const uint8_t  i_dbgl )
{
    int rc = SCAN_COMPRESSION_OK;
    uint32_t rs4Nibbles = 0;

    rc = __rs4_compress_from_raw4( (uint8_t*)o_rs4 + sizeof(CompressedScanData),
                                   i_bufSize - sizeof(CompressedScanData),
                                   rs4Nibbles,
                                   i_raw4,
                                   i_dbgl );

    if (rc == SCAN_COMPRESSION_OK)
    {
        uint32_t rs4Size = rs4_max_compressed_bytes(rs4Nibbles);

        if (rs4Size > i_bufSize)
        {
            MY_ERR("ERROR: _rs4_compress_from_raw4: Buffer overflow\n");
            return SCAN_COMPRESSION_BUFFER_OVERFLOW;
        }

        o_rs4->iv_magic     = htobe16(RS4_MAGIC);
        o_rs4->iv_version   = RS4_VERSION;
        o_rs4->iv_type      = i_ivType;
        o_rs4->iv_size      = htobe16(rs4Size);
        o_rs4->iv_ringId    = htobe16(i_ringId);
        o_rs4->iv_scanAddr  = htobe32(i_scanAddr);
        o_rs4->iv_selector  = htobe16(i_selector);
        o_rs4->iv_undefined = 0;
    }

    return rc;
}


//
// Decompress an RS4-encoded string into a Raw4-encoded output string
//
static int
__rs4_decompress_to_raw4( uint8_t* o_raw4Str,
                          const uint32_t i_bufSize,
                          uint32_t& o_raw4Recs,
                          uint32_t& o_raw4Size,
                          uint32_t& o_rawBits,
                          const uint8_t* i_rs4Str,
                          const uint8_t  i_dbgl )
{
    int      state;             /* 0: Rotate, 1: Scan */
    bool     masked;            /* =true if a care mask is available */
    uint8_t  careNibble;
    uint8_t  dataNibble;
    uint32_t i;                 /* Nibble index in i_rs4Str */
    uint32_t count;             /* Counts *raw* rotate [zero] nibbles */
    int      nibbles;           /* Rotate or scan RS4 nibbles to process */

    uint8_t  szRaw4Record   = sizeof(Raw4Record_t);

    // Initialize decompression state machine vars
    state = 0; //Always start with processing rotate
    i = 0;     //The first RS4 nibble

    // Initialize Raw4 data string variables
    uint32_t raw4Recs = 0;           /* Record index/counter within Raw4 string so far */
    uint32_t raw4Size = 0;           /* Byte size of Raw4 string so far */
    uint32_t rawBits = 0;            /* Number of true *raw* bits decoded so far */
    uint32_t rawNibbleCount = 0;     /* True *raw* nibble count so far */

    // Pt to the first raw4 record to be populated
    Raw4Record_t* raw4Record = (Raw4Record_t*)o_raw4Str;

    // Decompress the bulk of the string
    do
    {
        if (state == 0)
        {
            // Get RS4 stop nipples and *raw* rotate [zero] nipple count
            nibbles = stop_decode(&count, i_rs4Str, i);

            if (nibbles == -1)
            {
                MY_ERR("ERROR: __rs4_decompress_to_raw4: Error in the RS4 stop sequence\n");
                return SCAN_COMPRESSION_STOP_DECODE_ERROR;
            }

            i += nibbles;

            // Only append record to raw4 string if there is at least one rotate nibble
            if (count)
            {
                // Update Raw4 stats
                rawBits += 4 * count;
                raw4Recs++;
                raw4Size += szRaw4Record;

                if (raw4Size > i_bufSize)
                {
                    MY_ERR("ERROR(1): __rs4_decompress_to_raw4: Buffer overflow\n");
                    return SCAN_COMPRESSION_BUFFER_OVERFLOW;
                }

                raw4Record->nibbleIndex = rawNibbleCount;

                raw4Record->careData = 0x00; // careData always zero for rotate sequences

                raw4Record++; // Pt to next record
                rawNibbleCount += count;
            }

            state = 1;
        }
        else
        {
            // Get scan_count
            nibbles = rs4_get_nibble(i_rs4Str, i);
            i++;

            // Check for terminate
            if (nibbles == 0)
            {
                break;
            }

            masked = (nibbles == 15 ? true : false);
            nibbles = (masked ? 1 : nibbles);

            // Update Raw4 stats
            rawBits += 4 * nibbles;
            raw4Recs += nibbles;
            raw4Size += szRaw4Record * nibbles;

            if (raw4Size > i_bufSize)
            {
                MY_ERR("ERROR(2): __rs4_decompress_to_raw4: Buffer overflow\n");
                return SCAN_COMPRESSION_BUFFER_OVERFLOW;
            }

            if (masked)
            {
                raw4Record->nibbleIndex = rawNibbleCount;

                careNibble = rs4_get_nibble(i_rs4Str, i);
                dataNibble = rs4_get_nibble(i_rs4Str, i + 1);

                if (~careNibble & dataNibble)
                {
                    MY_ERR("ERROR: __rs4_decompress_to_raw4: Conflicting care and data bits in RS4"
                           " ring at nibbles(%u,%u)=(0x%x,0x%x)\n",
                           i, i + 1, careNibble, dataNibble);
                    return SCAN_COMPRESSION_CAREDATA_CONFLICT;
                }

                raw4Record->careData = careNibble << 4; //Put Care into left nibbl
                raw4Record->careData |= dataNibble;     //Put Data into right nibbl

                i += 2;
                raw4Record++; // Pt to next record
                rawNibbleCount++;
            }
            else
            {
                for (uint8_t k = 0; k < (uint8_t)nibbles; k++) //nibbles always <15 here
                {
                    raw4Record->nibbleIndex = rawNibbleCount;

                    dataNibble = rs4_get_nibble(i_rs4Str, i);
                    raw4Record->careData = dataNibble << 4;//Put Care in left nibbl (care=data here)
                    raw4Record->careData |= dataNibble;    //Put Data in right nibbl

                    i++;
                    raw4Record++; // Pt to next record
                    rawNibbleCount++;
                }
            }

            state = 0;
        }
    }
    while (1);

    // Now handle string termination

    int remBits;   /* Remainder bit count (<=3) */

    nibbles = rs4_get_nibble(i_rs4Str, i);
    i++;

    masked = ((nibbles & 0x8) ? true : false);
    remBits = nibbles & 0x3;

    if (remBits)
    {
        if (masked)
        {
            careNibble = rs4_get_nibble(i_rs4Str, i);
            dataNibble = rs4_get_nibble(i_rs4Str, i + 1);
        }
        else
        {
            dataNibble = rs4_get_nibble(i_rs4Str, i);
            careNibble = dataNibble; //care=data here
        }

        // Do nothing if...
        //    care&data==0 and it follows a previous rotate sequence
        // otherwise, create an Raw4 record for the rem nibble if
        //    it has data in it or it immediately follows a previous data record
        if ( careNibble == 0 && dataNibble == 0 && (raw4Record - 1)->careData == 0 )
        {
            // Not much to do. Lump in rem [zero] rotate with ongoing rotate.
            // ...just add the remBits
            rawBits += remBits;
        }
        else
        {
            // Update Raw4 stats
            rawBits += remBits;
            raw4Recs++;
            raw4Size += szRaw4Record;

            if (raw4Size > i_bufSize)
            {
                MY_ERR("ERROR(3): __rs4_decompress_to_raw4: Buffer overflow\n");
                return SCAN_COMPRESSION_BUFFER_OVERFLOW;
            }

            raw4Record->nibbleIndex = rawNibbleCount;

            if (masked)
            {
                if (~careNibble & dataNibble)
                {
                    MY_ERR("ERROR: __rs4_decompress_to_raw4: Conflicting [rem] care and data bits"
                           " in RS4 ring at nibbles(%u,%u)=(0x%x,0x%x)\n",
                           i, i + 1, careNibble, dataNibble);
                    return SCAN_COMPRESSION_CAREDATA_CONFLICT;
                }

                raw4Record->careData = careNibble << 4; //Put Care into left nibbl
                raw4Record->careData |= dataNibble;     //Put Data into right nibbl
            }
            else
            {
                raw4Record->careData = dataNibble << 4;//Put Care in left nibbl (care=data here)
                raw4Record->careData |= dataNibble;    //Put Data in right nibbl
            }
        }
    }

    o_raw4Recs = raw4Recs;
    o_raw4Size = raw4Size;
    o_rawBits = rawBits;

    return SCAN_COMPRESSION_OK;
}


static int
_rs4_decompress_to_raw4( Raw4ScanData_t* o_raw4,
                         const uint32_t  i_bufSize,
                         const CompressedScanData* i_rs4,
                         const uint8_t   i_dbgl )
{
    int rc = SCAN_COMPRESSION_OK;

    uint32_t raw4Recs = 0;
    uint32_t raw4Size = 0;
    uint32_t rawBits = 0;

    rc = __rs4_decompress_to_raw4( (uint8_t*)o_raw4 + sizeof(Raw4ScanData_t),
                                   i_bufSize - sizeof(Raw4ScanData_t),
                                   raw4Recs,
                                   raw4Size,
                                   rawBits,
                                   (uint8_t*)i_rs4 + sizeof(CompressedScanData),
                                   i_dbgl );

    if (rc)
    {
        MY_ERR("ERROR: _rs4_decompress_to_raw4: __rs4_decompress_to_raw4 failed w/rc=0x%08x\n",
               rc);
        return rc;
    }

    o_raw4->magic   = RAW4_MAGIC; // "RAW4"
    o_raw4->version = RAW4_VERSION;
    o_raw4->recs    = raw4Recs;
    o_raw4->size    = raw4Size + sizeof(Raw4ScanData_t);
    o_raw4->bits    = rawBits;

    if (i_dbgl)
    {
        MY_ERR("\nIn _rs4_decompress_to_raw4:\n"
               "raw4 recs = %u\n"
               "raw4 size = %u\n"
               "raw4 bits = %u\n",
               o_raw4->recs, o_raw4->size, o_raw4->bits);

        for (uint32_t idx = 0; idx < o_raw4->recs; idx++)
        {
            MY_ERR("0x%06x", ((Raw4Record_t*)((uint8_t*)o_raw4 + sizeof(Raw4ScanData_t) + sizeof(
                                                  Raw4Record_t) * idx))->nibbleIndex);
            MY_ERR("%02x\n", ((Raw4Record_t*)((uint8_t*)o_raw4 + sizeof(Raw4ScanData_t) + sizeof(Raw4Record_t) * idx))->careData);
        }

        MY_ERR("\n");
    }

    return rc;
}


static int
_overlay_nibble_pair( uint8_t&      o_pairFinal,
                      const uint8_t i_pairTgt,  // 0bCCCCDDDD
                      const uint8_t i_pairOvly, // 0bCCCCDDDD
                      const uint8_t i_ovlyMode,
                      const bool    i_bOvrd,
                      const uint8_t i_dbgl )
{
    uint8_t careOvly = i_pairOvly >> 4;

    if (careOvly)
    {
        uint8_t dataOvly = i_pairOvly & 0xf;
        uint8_t careTgt = i_pairTgt >> 4;
        uint8_t dataTgt = i_pairTgt & 0xf;
        uint8_t careFinal = 0;
        uint8_t dataFinal = 0;

        for(uint8_t iBit = 0; iBit < 4; iBit++)
        {
            uint8_t mask = 0x08 >> iBit;

            if(i_ovlyMode == OVLY_MODE_BOSS)      // Ovly set bit trumps tgt set bit
            {
                if(careOvly & mask)
                {
                    if (dataOvly & mask)
                    {
                        dataFinal |= mask;
                        careFinal |= mask;
                    }
                    else
                    {
                        // Clear data bit (NOP, so just to show intent)
                        dataFinal &= ~mask;

                        if (i_bOvrd)
                        {
                            // Preserve set zero intent
                            careFinal |= mask;
                        }
                        else
                        {
                            // Clear care bit and treat as rotate (NOP, so just to show intent)
                            careFinal &= ~mask;
                        }
                    }
                }
                else
                {
                    // Since careOvly==0 there's no ovly to do on Tgt. So copy Tgt bits asis
                    dataFinal |= dataTgt & mask;
                    careFinal |= careTgt & mask;
                }
            }
            else if(i_ovlyMode == OVLY_MODE_ACC)  // Ovly and Tgt [data] bits must agree
            {
                if(careOvly & mask)
                {
                    // If both Tgt and Ovly want to change the latch, the data *MUST* agree
                    if (careTgt & mask && ((dataTgt & mask) != (dataOvly & mask)) )
                    {
                        // Bit conflict!
                        MY_ERR("ERROR: _overlay_nibble_pair: Overlay bit conflict\n");
                        return SCAN_COMPRESSION_OVERLAY_BIT_CONFLICT;
                    }

                    careFinal |= mask;

                    if (dataOvly & mask)
                    {
                        dataFinal |= mask;
                    }
                    else
                    {
                        // Clear data bit (NOP, so just to show intent)
                        dataFinal &= ~mask;
                    }
                }
                else
                {
                    // Since careOvly==0 there's no ovly to do on Tgt. So copy Tgt bits asis
                    dataFinal |= dataTgt & mask;
                    careFinal |= careTgt & mask;
                }
            }
            else
            {
                MY_ERR("ERROR: _overlay_nibble_pair: Invalid overlay mode(=%u)\n",
                       i_ovlyMode);
                return SCAN_COMPRESSION_INVALID_OVERLAY_MODE;
            }
        }

        o_pairFinal = careFinal << 4 | dataFinal;
    }
    else
    {
        // Nothing in Ovly to consider. Tgt remains unchanged. Do plain copy Tgt->Final
        o_pairFinal = i_pairTgt;
    }

    return SCAN_COMPRESSION_OK;
}


static int
_raw4_overlay( Raw4ScanData_t* o_raw4Final,
               const uint32_t  i_bufSize,
               const Raw4ScanData_t* i_raw4Tgt,
               const Raw4ScanData_t* i_raw4Ovly,
               const uint8_t   i_ovlyMode,
               const bool      i_bOvrd,
               const uint8_t   i_dbgl )
{
    int rc = SCAN_COMPRESSION_OK;

    uint8_t  careDataTgt;
    uint8_t  careDataOvly;
    uint8_t  careDataFinal;
    uint8_t  careDataFinalPrev;

    // Pt to the first raw4 records to be processed
    Raw4Record_t* recFinal = (Raw4Record_t*)(o_raw4Final + 1);
    Raw4Record_t* recTgt   = (Raw4Record_t*)(i_raw4Tgt + 1);
    Raw4Record_t* recOvly  = (Raw4Record_t*)(i_raw4Ovly + 1);
    bool bNewRecord;
    uint16_t recsCountFinal;

    // Do a couple of sanity checks
    if ( recTgt->nibbleIndex != 0 || recOvly->nibbleIndex != 0 )
    {
        MY_ERR("ERROR: _raw4_overlay: First record's NI must be zero in both rings but"
               " recTgt->nibbleIndex=%u and recOvly->nibbleIndex=%u\n",
               recTgt->nibbleIndex, recOvly->nibbleIndex);
        return SCAN_COMPRESSION_RAW4_ERROR;
    }

    if ( i_raw4Tgt->bits != i_raw4Ovly->bits )
    {
        MY_ERR("ERROR: _raw4_overlay: The number of raw bits must be the same in both rings but"
               " raw4Tgt->bits=%u and raw4Ovly->bits=%u\n",
               i_raw4Tgt->bits, i_raw4Ovly->bits);
        return SCAN_COMPRESSION_RAW4_ERROR;
    }

    // These input Raw4 header fields will remain the same in the overlaid output Raw4 ring
    o_raw4Final->magic   = RAW4_MAGIC; // "RAW4"
    o_raw4Final->version = RAW4_VERSION;
    o_raw4Final->bits    = i_raw4Tgt->bits;

    //
    // Overlay loop
    //
    bNewRecord = false;
    recsCountFinal = 0;
    careDataTgt = 0;
    careDataOvly = 0;
    careDataFinal     = 0;
    careDataFinalPrev = 0;
    recFinal->nibbleIndex = 0;
    recFinal->careData = careDataFinalPrev; //It will be changed immediately if overlay in
    //first nibble results in careData!=0.

    for (uint32_t iNib = 0; iNib < (i_raw4Tgt->bits + 3) / 4; iNib++)
    {
        if (iNib == recTgt->nibbleIndex)
        {
            careDataTgt = recTgt->careData;
            recTgt++;
            bNewRecord = true;
        }

        if (iNib == recOvly->nibbleIndex)
        {
            careDataOvly = recOvly->careData;
            recOvly++;
            bNewRecord = true;
        }

        if (bNewRecord)
        {
            // Only do overlay when new records are found. Otherwise, would just be repeating
            // previous identical overlay operation.
            rc = _overlay_nibble_pair( careDataFinal,
                                       careDataTgt,
                                       careDataOvly,
                                       i_ovlyMode,
                                       i_bOvrd,
                                       i_dbgl );

            if (rc)
            {
                if (rc == SCAN_COMPRESSION_OVERLAY_BIT_CONFLICT)
                {
                    MY_ERR("ERROR: _raw4_overlay: Bit conflict found during overlay"
                           " of careData{Tgt,Ovly}={0x%02x,0x%02x} in nibble=%u\n",
                           careDataTgt, careDataOvly, iNib);
                }

                return rc;
            }

            if (careDataFinal == 0 && careDataFinalPrev == 0 && recsCountFinal > 0)
            {
                // Nothing to do (unless we're in the very first nibble, ie, the recsCountFinal
                // check above). Otherwise, include overlaid rotate nibble into existing rotate
                // sequence.
            }
            else
            {
                recFinal->nibbleIndex = iNib;
                recFinal->careData = careDataFinal;
                recFinal++;
                recsCountFinal++;
                careDataFinalPrev = careDataFinal;
            }

            bNewRecord = false;
        }
    }

    o_raw4Final->recs = recsCountFinal;
    o_raw4Final->size = sizeof(Raw4ScanData_t) + recsCountFinal * sizeof(Raw4Record_t); //No padding

    return rc;
}


// API for overlaying one RS4 ring onto another RS4 ring using the Raw4 compresion format
//
// Assumptions:
// - the two rings must have identical ringId and scanAddr
// - the caller must supply a final iv_type and iv_selector
// - all buffers are caller managed
// - it is assumed the rs4Final buffer can hold four equally max sized RS4/Raw4 rings
//
int
rs4_overlay( CompressedScanData* o_rs4Final,    // Holds rs4Final + raw4Tgt + raw4Ovly + raw4Final
             const uint32_t      i_workBufSize, // Must fit above four rings
             const CompressedScanData* i_rs4Tgt,
             const CompressedScanData* i_rs4Ovly,
             const uint8_t       i_ivType,   // iv_type to be used in Final RS4 header
             const Rs4Selector_t i_selector, // iv_selector to be used in Final RS4 header
             const uint8_t       i_ovlyMode, // Overlay mode
             const uint8_t       i_dbgl )
{
    int rc = SCAN_COMPRESSION_OK;

    // Split up the input buffer, o_rs4Final, into four smaller equally sized buffers (starting
    // with o_rs4Final where it already is).
    // Then clear the three Raw4 buffers but wait to clear io_rs4Final until later to allow
    // using the same buffer for both rs4Tgt and rs4Final  or  rs4Ovly and rs4Final until then.
    Raw4ScanData_t* raw4Final = (Raw4ScanData_t*)((uint8_t*)o_rs4Final + i_workBufSize / 4 * 1);
    Raw4ScanData_t* raw4Tgt   = (Raw4ScanData_t*)((uint8_t*)o_rs4Final + i_workBufSize / 4 * 2);
    Raw4ScanData_t* raw4Ovly  = (Raw4ScanData_t*)((uint8_t*)o_rs4Final + i_workBufSize / 4 * 3);
    memset(raw4Final, 0, i_workBufSize / 4);
    memset(raw4Tgt,   0, i_workBufSize / 4);
    memset(raw4Ovly,  0, i_workBufSize / 4);


    if (o_rs4Final == NULL)
    {
        return BUGX(SCAN_COMPRESSION_NO_MEMORY,
                    "ERROR: rs4_overlay: No memory allocated for final overlaid RS4 ring\n");
    }

    if (i_workBufSize < 4 * RS4_RING_BUF_SIZE)
    {
        MY_ERR("ERROR: rs4_overlay: Input work buffer is too small\n");
        return SCAN_COMPRESSION_BUFFER_OVERFLOW;
    }

    // Basic RS4 header checks
    if ( be16toh(i_rs4Tgt->iv_magic) != RS4_MAGIC  ||
         be16toh(i_rs4Ovly->iv_magic) != RS4_MAGIC)
    {
        return BUGX(SCAN_COMPRESSION_MAGIC_ERROR,
                    "ERROR: rs4_overlay: Rings are not RS4 rings\n");
    }

    if ( i_rs4Tgt->iv_version != RS4_VERSION  ||
         i_rs4Ovly->iv_version != RS4_VERSION )
    {
        return BUGX(SCAN_COMPRESSION_VERSION_ERROR,
                    "ERROR: rs4_overlay: Rings' RS4 version do not match code level's version\n");
    }

    // Verify that rs4Tgt and rs4Ovly input rings' headers satisfy assumptions
    if ( i_rs4Tgt->iv_ringId != i_rs4Ovly->iv_ringId  ||
         i_rs4Tgt->iv_scanAddr != i_rs4Ovly->iv_scanAddr )
    {
        MY_ERR("ERROR: rs4_overlay: Mismatched RS4 headers as follows:\n"
               " ringIdTgt   =0x%03x\n"
               " ringIdOvly  =0x%03x\n"
               " scanAddrTgt =0x%08x\n"
               " scanAddrOvly=0x%08x\n",
               be16toh(i_rs4Tgt->iv_ringId), be16toh(i_rs4Ovly->iv_ringId),
               be32toh(i_rs4Tgt->iv_scanAddr), be32toh(i_rs4Ovly->iv_scanAddr));
        return SCAN_COMPRESSION_HEADERS_DONT_MATCH;
    }

    //
    // Do the overlay steps, ie decompress_to_raw4, overlay, recompress_to_rs4
    //
    rc = _rs4_decompress_to_raw4( raw4Tgt,
                                  i_workBufSize / 4,
                                  i_rs4Tgt,
                                  i_dbgl );

    if (rc)
    {
        MY_ERR("ERROR: rs4_overlay: _rs4_decompress_to_raw4 failed for Tgt ring w/rc=0x%08x\n",
               rc);
        return rc;
    }

    rc = _rs4_decompress_to_raw4( raw4Ovly,
                                  i_workBufSize / 4,
                                  i_rs4Ovly,
                                  i_dbgl );

    if (rc)
    {
        MY_ERR("ERROR: rs4_overlay: _rs4_decompress_to_raw4 failed for Ovly ring w/rc=0x%08x\n",
               rc);
        return rc;
    }

    // Copy ringId and scanAddr now that the RS4 input ring have been fully utilized and
    // may get overwritten in case they share buffer space with rs4Final.  Also, safe to
    // clear rs4Final.

    RingId_t ringIdTemp = be16toh(i_rs4Tgt->iv_ringId);
    uint32_t scanAddrTemp = be32toh(i_rs4Tgt->iv_scanAddr);

    memset(o_rs4Final,  0, i_workBufSize / 4);

    //
    // Do overlay or test Raw4 (de)compression algorithm
    //
    switch(i_ovlyMode)
    {

        case OVLY_MODE_BOSS:
        case OVLY_MODE_ACC:

            rc = _raw4_overlay( raw4Final,
                                i_workBufSize / 4,
                                raw4Tgt,
                                raw4Ovly,
                                i_ovlyMode,
                                (i_ivType & RS4_IV_TYPE_SCAN_OVRD) ? true : false,
                                i_dbgl );

            if (rc)
            {
                MY_ERR("ERROR: rs4_overlay: _raw4_overlay failed for ringId=0x%x w/rc=0x%08x\n",
                       ringIdTemp, rc);
                return rc;
            }

            rc = _rs4_compress_from_raw4( o_rs4Final,
                                          i_workBufSize / 4,
                                          i_ivType,
                                          ringIdTemp,
                                          scanAddrTemp,
                                          i_selector,
                                          raw4Final,
                                          i_dbgl );

            if (rc)
            {
                MY_ERR("ERROR: rs4_overlay: _rs4_compress_from_raw4 failed for ringId=0x%x"
                       " w/rc=0x%08x (1)\n",
                       ringIdTemp, rc);
                return rc;
            }

            break;

        case OVLY_MODE_RAW4TEST:

            rc = _rs4_compress_from_raw4( o_rs4Final,
                                          i_workBufSize / 4,
                                          i_ivType,
                                          ringIdTemp,
                                          scanAddrTemp,
                                          i_selector,
                                          raw4Tgt,
                                          i_dbgl );

            if (rc)
            {
                MY_ERR("ERROR: rs4_overlay: _rs4_compress_from_raw4 failed for ringId=0x%x"
                       " w/rc=0x%08x (2)\n",
                       ringIdTemp, rc);
                return rc;
            }

            break;

        default:

            MY_ERR("ERROR: rs4_overlay: Invalid overlay mode(=%u)\n", i_ovlyMode);

            return SCAN_COMPRESSION_INVALID_OVERLAY_MODE;
    }

    return rc;
}
