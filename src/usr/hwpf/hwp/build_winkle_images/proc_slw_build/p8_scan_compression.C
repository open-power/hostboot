 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/p8_scan_compression.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: p8_scan_compression.C,v 1.4 2012/08/17 16:19:44 cmolsen Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_scan_compression.C,v $
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

/// \file p8_scan_compression.C
/// \brief APIs related to scan chain compression.
///
/// RS4 Compression Format
/// ======================
///
/// Scan strings are compressed using a simple run-length encoding called
/// RS4. The string to be decompressed and scanned is the difference between
/// the current state of the ring and the desired final state of the ring.  A
/// run-time optimization supports the case that the current state of the ring
/// is the flush state.
///
/// Both the data to be compressed and the final compressed data are treated
/// as strings of 4-bit nibbles. When packaged in the scan data structure
/// however the compressed string must begin on an 8-byte boundary and is
/// always read 8 bytes at a time.  In the scan data structure the compressed
/// strings are also padded with 0x0 nibbles to the next even multiple of 8
/// bytes. The compressed string consists of control nibbles and data nibbles.
/// The string format includes a special control/data sequence that marks the
/// end of the string and the final bits of scan data.
///
/// Runs of 0x0 nibbles (rotates) are encoded using a simple variable-length
/// integer encoding known as a "stop code".  This code treats each nibble in
/// a variable-length integer encoding as an octal digit (the low-order 3
/// bits) plus a stop bit (the high-order bit).  The examples below
/// illustrate the encoding.
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
/// uncompressed data.  If a run is longer than 15 nibbles, the compression
/// algorithm must insert a 0-length rotate and a new scan-length control
/// before continuing with the non-0 data nibbles.
///
///     xxxx - Scan 0bxxxx nibbles which follow, 0bxxxx != 0
///
/// The special case of a 0b0000 code where a scan count is expected marks the
/// end of the string.  The end of string marker is always followed by a
/// nibble that contains the terminal bit count in the range 0-3.  If the
/// length of the original binary string was not an even multiple of 4, then a
/// final nibble contains the final scan data left justified.
///
///     0000 00nn [ttt0] - Terminate 0bnn bits, data 0bttt0 if 0bnn != 0
///
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
/// <rs4_string>        ::= <rotate> <terminate> |
///                         <rotate> <scan> <rs4_string>
///
/// <rotate>            ::= <octal_stop> |
///                         <octal_go> <rotate>
///
/// <octal_go>          ::= '0x0' | ... | '0x7'
///
/// <octal_stop>        ::= '0x8' | ... | '0xf'
///
/// <scan>              ::= <scan_count(N)> <data(N)>
///
/// <scan_count(N)>     ::= * 0bnnnn, for N = 0bnnnn, N != 0 *
///
/// <data(N)>           ::= * N nibbles of uncompressed data *
///
/// <terminate>         ::= '0x0' <terminal_count(0)> |
///                         '0x0' <terminal_count(T, T > 0)> <terminal_data(T)>
///
/// <terminal_count(T)> ::= * 0b00nn, for T = 0bnn *
///
/// <terminal_data(1)>  ::= '0x0' | '0x8'
///
/// <terminal_data(2)>  ::= '0x0' | '0x4' | '0x8' | '0xc'
///
/// <terminal_data(3)>  ::= '0x0' | '0x2' | '0x4' | ... | '0xe'
///
/// \endcode


#include <stdlib.h>
#include "p8_scan_compression.H"

// Diagnostic aids for debugging
#ifdef DEBUG_P8_SCAN_COMPRESSION

#ifdef __FAPI

#include "fapi.H"
#define fprintf(stream, ...) FAPI_ERR(__VA_ARGS__)
#define BUG_NEWLINE ""

#else // __FAPI

#include <stdio.h>
#define BUG_NEWLINE "\n"

#endif // __FAPI

#define BUG(rc)                                                 \
    ({                                                          \
        fprintf(stderr,"%s:%d : Trapped rc = %d" BUG_NEWLINE,   \
                __FILE__, __LINE__, (rc));                      \
        (rc);                                                   \
    })

#define BUGX(rc, ...)                           \
    ({                                          \
        BUG(rc);                                \
        fprintf(stderr, ##__VA_ARGS__);         \
        (rc);                                   \
    })

#else // DEBUG_P8_SCAN_COMPRESSION

#define BUG(rc) (rc)
#define BUGX(rc, ...) (rc)

#endif  // DEBUG_P8_SCAN_COMPRESSION

// Note: For maximum flexibility we provide private versions of
// endian-conversion routines rather than counting on a system-specific header
// to provide these.

// Byte-reverse a 32-bit integer if on a little-endian machine

static uint32_t
revle32(const uint32_t i_x)
{
    uint32_t rx;

#ifndef _BIG_ENDIAN
    uint8_t *pix = (uint8_t*)(&i_x);
    uint8_t *prx = (uint8_t*)(&rx);

    prx[0] = pix[3];
    prx[1] = pix[2];
    prx[2] = pix[1];
    prx[3] = pix[0];
#else
    rx = i_x;
#endif
    return rx;
}


#if COMPRESSED_SCAN_DATA_VERSION != 1
#error This code assumes CompressedScanData structure version 1 layout
#endif

void
compressed_scan_data_translate(CompressedScanData* o_data,
                               CompressedScanData* i_data)
{
    o_data->iv_magic             = revle32(i_data->iv_magic);
    o_data->iv_size              = revle32(i_data->iv_size);
    o_data->iv_algorithmReserved = revle32(i_data->iv_algorithmReserved);
    o_data->iv_length            = revle32(i_data->iv_length);
    o_data->iv_scanSelect        = revle32(i_data->iv_scanSelect);
    o_data->iv_headerVersion     = i_data->iv_headerVersion;
    o_data->iv_flushOptimization = i_data->iv_flushOptimization;
    o_data->iv_ringId            = i_data->iv_ringId;
    o_data->iv_chipletId         = i_data->iv_chipletId;
}


// Return a big-endian-indexed nibble from a byte string

static int
get_nibble(const uint8_t* i_string, const uint32_t i_i)
{
    uint8_t byte;
    int nibble;

    byte = i_string[i_i / 2];
    if (i_i % 2) {
        nibble = byte & 0xf;
    } else {
        nibble = byte >> 4;
    }
    return nibble;
}


// Set a big-endian-indexed nibble in a byte string

static int
set_nibble(uint8_t* io_string, const uint32_t i_i, const int i_nibble)
{
    uint8_t* byte;

    byte = &(io_string[i_i / 2]);
    if (i_i % 2) {
        *byte = (*byte & 0xf0) | i_nibble;
    } else {
        *byte = (*byte & 0x0f) | (i_nibble << 4);
    }
    return i_nibble;
}


// Encode an unsigned integer into a 4-bit octal stop code directly into a
// nibble stream at io_string<i_i>, returning the number of nibbles in the
// resulting code.

static int
stop_encode(const uint32_t i_count, uint8_t* io_string, const uint32_t i_i)
{
    uint32_t count;
    int digits, offset;

    // Determine the number of octal digits.  There is always at least 1.

    count = i_count >> 3;
    digits = 1;
    while (count) {
        count >>= 3;
        digits++;
    }

    // First insert the stop (low-order) digit

    offset = digits - 1;
    set_nibble(io_string, i_i + offset, (i_count & 0x7) | 0x8);

    // Now insert the high-order digits

    count = i_count >> 3;
    offset--;
    while (count) {
        set_nibble(io_string, i_i + offset, count & 0x7);
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

    do {
        nibble = get_nibble(i_string, i);
        count = (count * 8) + (nibble & 0x7);
        i++;
        digits++;
    } while ((nibble & 0x8) == 0);

    *o_count = count;
    return digits;
}


// RS4 compression algorithm notes:
//
// RS4 compression processes i_string as a string of nibbles.  Final
// special-case code handles the 0-3 remaining terminal bits.
//
// There is a special case for 0x0 nibbles embedded in a string of non-0x0
// nibbles. It is more efficient to encode a single 0x0 nibble as part of a
// longer string of non 0x0 nibbles.  However it is break-even (actually a
// slight statistical advantage) to break a scan seqeunce for 2 0x0 nibbles.
//
// If a run of 15 scan nibbles is found the scan is terminated and we return
// to the rotate state.  Runs of more than 15 scans will always include a
// 0-length rotate between the scan sequences.
//
// Returns the number of nibbles in the compressed string.

static uint32_t
_rs4_compress(CompressedScanData* o_data,
              const uint8_t* i_string,
              const uint32_t i_length)
{
    int state;                  /* 0 : Rotate, 1 : Scan */
    uint32_t n;                 /* Number of whole nibbles in i_data */
    uint32_t r;                 /* Number of reminaing bits in i_data */
    uint32_t i;                 /* Nibble index in i_string */
    uint32_t j;                 /* Nibble index in data */
    uint32_t k;                 /* Location to place scan count */
    uint32_t count;             /* Counts rotate/scan nibbles */
    uint8_t* data;              /* The compressed scan data area */

    n = i_length / 4;
    r = i_length % 4;
    i = 0;
    j = 0;
    k = 0;                      /* Makes GCC happy */
    data = (uint8_t*)o_data + sizeof(CompressedScanData);
    count = 0;
    state = 0;

    // Process the bulk of the string.  Note that state changes do not
    // increment 'i' - the nibble at i_data<i> is always scanned again.

    while (i < n) {
        if (state == 0) {
            if (get_nibble(i_string, i) == 0) {
                count++;
                i++;
            } else {
                j += stop_encode(count, data, j);
                count = 0;
                k = j;
                j++;
                state = 1;
            }
        } else {
            if (get_nibble(i_string, i) == 0) {
                if (((i + 1) < n) && (get_nibble(i_string, i + 1) == 0)) {
                    set_nibble(data, k, count);
                    count = 0;
                    state = 0;
                } else {
                    set_nibble(data, j, 0);
                    count++;
                    i++;
                    j++;
                }
            } else {
                set_nibble(data, j, get_nibble(i_string, i));
                count++;
                i++;
                j++;
            }
            if ((state == 1) && (count == 15)) {
                set_nibble(data, k, 15);
                state = 0;
                count = 0;
            }
        }
    }

    // Finish the current state and insert the terminate code (scan 0).  If we
    // finish on a scan we must insert a null rotate first.

    if (state == 0) {
        j += stop_encode(count, data, j);
    } else {
        set_nibble(data, k, count);
        j += stop_encode(0, data, j);
    }
    set_nibble(data, j, 0);
    j++;

    // Insert the remainder count nibble, and if non-0, the remainder data
    // nibble.

    set_nibble(data, j, r);
    j++;
    if (r != 0) {
        set_nibble(data, j, get_nibble(i_string, n));
        j++;
    }

    // Return the number of nibbles in the compressed string.

    return j;
}


// The worst-case compression for RS4 requires 2 nibbles of control overhead
// per 15 nibbles of data (17/15), plus a maximum of 2 nibbles of termination.
// We always allocate this worst-case amount of memory including the header
// and any rounding required to guarantee that the allocated length is a
// multiple of 8 bytes.  The final size is also rounded up to a multiple of 8
// bytes.

int
rs4_compress(CompressedScanData** o_data,
             uint32_t* o_size,
             const uint8_t* i_string,
             const uint32_t i_length,
             const uint64_t i_scanSelect,
						 const uint8_t i_ringId,
             const uint8_t i_chipletId,
             const uint8_t i_flushOptimization)
{
    int rc;
    uint32_t nibbles, bytes;

    nibbles = (((((i_length + 3) / 4) + 14) / 15) * 17) + 2;
    bytes = ((nibbles + 1) / 2) + sizeof(CompressedScanData);
    bytes = ((bytes + 7) / 8) * 8;

    *o_data = (CompressedScanData*)calloc(bytes, 1);

    if (*o_data == 0) {
        rc = BUG(SCAN_COMPRESSION_NO_MEMORY);
    } else {
        nibbles = _rs4_compress(*o_data, i_string, i_length);
        bytes = ((nibbles + 1) / 2) + sizeof(CompressedScanData);
        bytes = ((bytes + 7) / 8) * 8;

        (*o_data)->iv_magic             = revle32(RS4_MAGIC);
        (*o_data)->iv_size              = revle32(bytes);
        (*o_data)->iv_algorithmReserved = revle32(nibbles);
        (*o_data)->iv_length            = revle32(i_length);
        (*o_data)->iv_scanSelect        = revle32((uint32_t)(i_scanSelect >> 32));
        (*o_data)->iv_headerVersion     = COMPRESSED_SCAN_DATA_VERSION;
        (*o_data)->iv_flushOptimization = i_flushOptimization;
        (*o_data)->iv_ringId            = i_ringId;
        (*o_data)->iv_chipletId         = i_chipletId;

        *o_size = bytes;

        rc = SCAN_COMPRESSION_OK;
    }

    return rc;
}


// Decompress an RS4-encoded string into a output string whose length must be
// exactly i_length bits.
//
// Returns a scan compression return code.

static int
_rs4_decompress(uint8_t* o_string,
                const uint8_t* i_string,
                const uint32_t i_length)
{
    int rc;
    int state;                  /* 0 : Rotate, 1 : Scan */
    uint32_t i;                 /* Nibble index in i_string */
    uint32_t j;                 /* Nibble index in o_string */
    uint32_t k;                 /* Loop index */
    uint32_t bits;              /* Number of output bits decoded so far */
    uint32_t count;             /* Count of rotate nibbles */
    uint32_t nibbles;           /* Rotate encoding or scan nibbles to process */
    int r;                      /* Remainder bits */

    rc = 0;
    i = 0;
    j = 0;
    bits = 0;
    state = 0;

    // Decompress the bulk of the string

    do {
        if (state == 0) {
            nibbles = stop_decode(&count, i_string, i);
            if ((bits + (4 * count)) > i_length) {
                rc = BUG(SCAN_DECOMPRESSION_SIZE_ERROR);
                break;
            }
            i += nibbles;
            bits += (4 * count);
            for (k = 0; k < count; k++) {
                set_nibble(o_string, j, 0);
                j++;
            }
            state = 1;
        } else {
            nibbles = get_nibble(i_string, i);
            i++;
            if (nibbles == 0) {
                break;
            }
            if ((bits + (4 * nibbles)) > i_length) {
                rc = BUG(SCAN_DECOMPRESSION_SIZE_ERROR);
                break;
            }
            bits += (4 * nibbles);
            for (k = 0; k < nibbles; k++) {
                set_nibble(o_string, j, get_nibble(i_string, i));
                i++;
                j++;
            }
            state = 0;
        }
    } while (1);

    // Now handle string termination

    if (!rc) {
        r = get_nibble(i_string, i);
        i++;
        if (r != 0) {
            if ((bits + r) > i_length) {
                rc = BUG(SCAN_DECOMPRESSION_SIZE_ERROR);
            } else {
                bits += r;
                set_nibble(o_string, j, get_nibble(i_string, i));
            }
        }
    }

    // Final check to insure the string was valid

    if (!rc) {
        if (bits != i_length) {
            rc = BUGX(SCAN_DECOMPRESSION_SIZE_ERROR,
                      "bits = %zu, i_length = %zu\n",
                      bits, i_length);
        }
    }

    return rc;
}


int
rs4_decompress(uint8_t** o_string,
               uint32_t* o_length,
               const CompressedScanData* i_data)
{
    int rc;
    uint32_t bytes;

    do {
        if (revle32(i_data->iv_magic) != RS4_MAGIC) {
            rc = BUG(SCAN_DECOMPRESSION_MAGIC_ERROR);
            break;
        }

        *o_length = revle32(i_data->iv_length);
        bytes = ((*o_length + 7) / 8) * 8;
        *o_string = (uint8_t*)calloc(bytes, 1);
        if (*o_string == 0) {
            rc = BUG(SCAN_COMPRESSION_NO_MEMORY);
            break;
        }

        rc = _rs4_decompress(*o_string,
                             (uint8_t*)i_data + sizeof(CompressedScanData),
                             *o_length);
    } while (0);

    return rc;
}


