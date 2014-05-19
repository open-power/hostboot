/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ecmddatabuffer/prdfCompressBuffer.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 * @file prdfCompressBuffer.H
 *
 * @brief Functions to provide the compression/decompression algorithms
 *
 */

#ifndef __PRDFCOMPRESSBUFFER_H
#define __PRDFCOMPRESSBUFFER_H

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#ifdef _AIX
#include <inttypes.h>
#else
#include <stdint.h>
#endif
#include <string.h>

#ifndef   MIN
#define   MIN(a, b) ( ((a) < (b)) ? (a) : (b) )
#endif

/*
 * Prdf Compression Algorithm:
 *        The purpose of these compression routines are to compress the register
 * dumps contained in our error logs.  In large systems, we could possibly have
 * more register data than we could possibly fit in an error log.  These
 * routines will allow us to fit more data into the error logs.  In addition,
 * the algorithms have been designed such that even if the end of the stream
 * is lost (cut short), we can uncompress all of the data up to that point.  We
 * had proposed using the Zlib compression algorithms, but they required the
 * CRC to match and we did not want that requirement.
 *
 *         This compression algorithm is based off the LZ77 compression algorithm.
 * The algorithm consists of a look-behind buffer of 1024 bytes, and a
 * look-ahead buffer of 63 bytes.  The algorithm attempts to find a match from
 * the start of the look-ahead buffer located inside the look-behind buffer.
 * If the longest match is bigger than 2 bytes (2 bytes is the break-even
 * point), it converts the match into a token (pos in look-behind, length) of
 * two bytes (12 bits to pos, 6 to length).  If no match is found, the first
 * character is popped from the look-ahead buffer.  As matches are found (or
 * not found) and popped from the look-ahead buffer, they are added to the
 * end of the look-behind buffer (if the buffer increases over 1024, the start
 * is shifted forward).
 *
 *         As the stream (look-ahead buffer) is converted into tokens, they are
 * bundled into groups of 8.  A special token is added to the beginning of the
 * bundle, recording the size of the following 8 tokens (2 or 1 bytes).  Once
 * the token bundle is complete (or end-of-stream), it is added to the output
 * buffer.
 *
 *        To use these routines, #define PRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS
 * or PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS, depending on usage.  These reduce
 * the code footprint, since only the needed functions are compiled in.
 *
 */

namespace PrdfCompressBuffer
{
    /* size_t compressedBufferMax(size_t)
     *                Determines the maximum size of the compressed buffer (worst
     * case) based on an input buffer size.
     */
    #ifdef PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS
    size_t compressedBufferMax(size_t i_bufSize)
        {
            return 1 + ((i_bufSize * 9) / 8);
        };
    #endif

    #if defined PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS   || \
        defined PRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS
    static size_t COMPRESSION_BREAKEVEN = 3;
    #endif

    /* class CompressedToken
     *                Internal class for converting (pos,size) tokens to two char.
     */
    class CompressedToken
    {
        private:
            uint8_t token[2];

        public:
            #ifdef PRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS
            // Default constructor.
            CompressedToken() {};
            #endif

            #ifdef PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS
            /* CompressedToken(size_t, size_t)
             *                Convert position and size to uint8 tokens.
             */
            CompressedToken(size_t i_pos, size_t i_size)
            {
                uint16_t l_token = (i_pos << 6)
                                 | (i_size - COMPRESSION_BREAKEVEN);
                token[1] = l_token & 0xFF;
                token[0] = (l_token >> 8) & 0xFF;
            };
            #endif

            #ifdef PRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS
            /* void uncompress(uint8_t *, uint8_t *&, size_t&)
             *                Convert uint8 tokens to pos,size values.  Changes
             * o_pos to be a pointer to the string inside the buffer and sets
             * o_size to be the size of the string.
             */
            void uncompress(uint8_t * i_buf, uint8_t * &o_pos, size_t &o_size)
            {
                uint16_t l_token = (token[0] << 8) | token[1];

                o_pos = &i_buf[(l_token & 0xFFC0) >> 6];
                o_size = (l_token & 0x3F) + COMPRESSION_BREAKEVEN;

                return;
            };
            /* void read(uint8_t *)
             *                 Read two bytes from the buffer to keep as tokens.
             * NOTE: Does not modify i_buf.
             */
            void read(uint8_t * i_buf)
            {
                token[0] = i_buf[0];
                token[1] = i_buf[1];
            };
            #endif

            #ifdef PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS
            /* void write(uint8_t *)
             *                Copy tokens into the beginning of the buffer.
             */
            void write(uint8_t * o_buf) { memcpy(o_buf, token, 2); };
            #endif

            size_t size() { return 2; };

            /* static size_t minSize()
             *               This function returns minimum size of token.
             *
             * NOTE: This function will be used for buffer size validation.
             *       Currently token size is fixed in nature. But in future
             *       we may go for variable length tokens. Therefore we dont
             *       want to make function "size" static.
             */
            static size_t minSize() { return 2; };
    };

    #ifdef PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS
    /* void compressBuffer(uint8_t *, size_t, uint8_t *, size_t &)
     *                Compresses i_buf and stores result into o_buf.
     *
     * i_buf         : pointer to input buffer.
     * i_size         : size of input buffer.
     * o_buf        : pointer to output buffer (supplied by caller).
     * o_size        : max size of output buffer.  After function, size of
     *                  compressed buffer.
     *
     * NOTE: The size of the output buffer should be 1 + ((i_size * 9) / 8)
     *             to guarentee no data is lost (worst case for compression).
     */
    void compressBuffer(uint8_t * i_buf, size_t i_size,
                        uint8_t * o_buf, size_t &o_size)
    {
        // Asserts.
        if ((i_buf == NULL) || (o_buf == NULL))
        {
            o_size = 0;
            return;
        }

        uint8_t * l_lookahead = i_buf; // Pointer to the look-behind buf.
        size_t l_laSize = 0;               // Size of look-behind.

        size_t l_tokPos = 0;               // Number of tokens in the bundle.
        uint8_t * l_tokC = o_buf++;    // Store compress bits and advance ptr.
        size_t l_outputSize = 1;       // start with l_tokC.

        while((i_size > 0) && (l_outputSize < o_size))
        {
            size_t l_curLen = 1;
            uint8_t * l_match = NULL;

            // Find the longest match. (2 is our break-even pt,
            // but 3 will provide better compression).
            for (size_t i = 3;
                 i < MIN(i_size, l_laSize) && (i < (64 + COMPRESSION_BREAKEVEN))
                 ; i++)
            {
                uint8_t * l_tmpMatch = NULL;

                l_tmpMatch = (uint8_t *) memmem(l_lookahead, l_laSize,
                                                i_buf, i);

                if (l_tmpMatch != NULL) // found match.
                {
                    l_match = l_tmpMatch;
                    l_curLen = i;
                }
                else
                    i = i_size + l_laSize; // abort for loop.
            }

            // Create token.
            if (l_match != NULL)
            {
                // found match, make sure there is room for the token.
                if (o_size - l_outputSize >= 2)
                {
                    CompressedToken l_token(l_match - l_lookahead, l_curLen);

                    l_token.write(o_buf);
                    o_buf += 2;
                    l_outputSize += 2;

                    (*l_tokC) = (*l_tokC << 1) | 0x1;
                    l_tokPos++;

                    i_buf += l_curLen;
                    l_laSize += l_curLen;
                    i_size -= l_curLen;
                }
                else
                {
                    l_outputSize = o_size;
                }
            }
            else
            {
                // no match, copy if room in the buffer.
                if (o_size - l_outputSize >= 1)
                {
                    o_buf[0] = i_buf[0];
                    o_buf++;
                    l_outputSize++;

                    (*l_tokC) = (*l_tokC << 1) | 0x0;
                    l_tokPos++;

                    i_buf++;
                    l_laSize++;
                    i_size--;
                }
                // else <= 0, so don't mess with l_outputSize.
            }

            // flush out lookahead. (keep at 1024 bytes)
            while(l_laSize >= 1024)
            {
                l_laSize--;
                l_lookahead++;
            }

            // check if bundle complete, create new bundle.
            if (l_tokPos == 8)
            {
                l_tokPos = 0;
                l_tokC = o_buf++;
                l_outputSize++;
            }

        } // end while.

        // Shift our bundle bits correctly. (the uncompressor doesn't know if
        // the bundle was complete, so always assumes so.
        if (l_tokPos != 0)
            (*l_tokC) = (*l_tokC) << (8 - l_tokPos);

        // We never _really_ go past our buffer, but sometimes our size says
        // we did, so fix that up...
        if (l_outputSize <= o_size)
            o_size = l_outputSize;

        return;
    };
    #endif

    #ifdef PRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS
    /* void uncompressBuffer(uint8_t *, size_t, uint8_t *, size_t &)
     *                Uncompresses i_buf and stores result into o_buf.
     *
     * i_buf         : pointer to input buffer.
     * i_size         : size of input buffer.
     * o_buf        : pointer to output buffer (supplied by caller).
     * o_size        : max size of output buffer.  After function, size of
     *                  uncompressed buffer.
     *
     * NOTE:  The size is never stored in an compressed or uncompressed buffer.
     *               The caller needs to keep track of those kind of things and add
     *               whatever kind of header they need.  If o_size isn't big enough
     *              you're not going to get the whole stream.  These functions will
     *              not overrun the buffer.
     */
    void uncompressBuffer(uint8_t * i_buf, size_t i_size,
                          uint8_t * o_buf, size_t & o_size)
    {
        // Asserts.
        if ((i_buf == NULL) || (o_buf == NULL))
        {
            o_size = 0;
            return;
        }

        // Initilize output buffer with 0
        memset( o_buf, 0, o_size);

        uint8_t * l_lookahead = o_buf;  // Look-behind buffer.
        size_t l_laSize = 0;                // look-behind size.

        uint8_t l_tokC = 0;                // Bundle bits.
        uint8_t l_tokPos = 8;                // Number of tokens from the bundle
                                        // thus far.  (start at 8 to get a new
                                        // bundle right away).

        size_t l_outputSize = 0;        // Size of output buffer.

        while ((i_size > 0) && (o_size > 0))  // while we're at the end of a buf.
        {
            // Check if we need to get a new bundle.
            if (l_tokPos == 8)
            {
                l_tokPos = 0;
                l_tokC = i_buf[0];
                i_buf++;
                i_size--;
                continue;
            }


            // Check if token was compressed or not.
            if ((l_tokC >> (7 - l_tokPos)) & 0x1)
            {
                // check if input buffer has tokens
                if ( i_size < CompressedToken::minSize() )
                {
                    // set exit condition
                    i_size = 0;
                    continue;
                }
                // compressed token...

                size_t l_matchSize;
                uint8_t * l_match;
                CompressedToken l_tok;

                // read token from stream.
                l_tok.read(i_buf);
                i_buf += l_tok.size();
                i_size -= l_tok.size();

                // get pointer to lookahead buffer, copy into output buffer.
                l_tok.uncompress(l_lookahead, l_match, l_matchSize);
                memcpy(o_buf, l_match, MIN(l_matchSize, o_size));

                // fix up all our sizes and pointers.
                l_laSize += l_matchSize;
                l_outputSize += MIN (l_matchSize, o_size);
                o_size -= MIN (l_matchSize, o_size);
                o_buf += l_matchSize;
            }
            else
            {
                // uncompressed token... just copy the byte.

                o_buf[0] = i_buf[0];
                o_size--;
                o_buf++;
                i_buf++;
                i_size--;

                l_laSize++;
                l_outputSize++;
            }
            l_tokPos++; // just did a token, so inc the bundle count.

            // Advance the look-behind buffer as needed.
            while (l_laSize >= 1024)
            {
                l_lookahead++;
                l_laSize--;
            }
        }

        // fix up o_size (since we've been decrementing it...)
        o_size = l_outputSize;
    };
    #endif

}; // end namespace.

#endif
