/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/contrib/sha512.C $                              */
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
/* Copyright (c) 2000-2001, Aaron D. Gifford                              */
/* All rights reserved.                                                   */
/*                                                                        */
/* Redistribution and use in source and binary forms, with or without     */
/* modification, are permitted provided that the following conditions     */
/* are met:                                                               */
/* 1. Redistributions of source code must retain the above copyright      */
/*    notice, this list of conditions and the following disclaimer.       */
/* 2. Redistributions in binary form must reproduce the above copyright   */
/*    notice, this list of conditions and the following disclaimer in     */
/*    the documentation and/or other materials provided with the          */
/*    distribution.                                                       */
/* 3. Neither the name of the copyright holder nor the names of           */
/*    contributors may be used to endorse or promote products derived     */
/*    from this software without specific prior written permission.       */
/*                                                                        */
/* THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS''   */
/* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  */
/* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A            */
/* PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR    */
/* CONTRIBUTOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,         */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
/* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  */
/* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
/*                                                                        */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/********************************************************************
 * SHA-512  BIG-Endian Version
 *
 *******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <securerom/sha512.H>


/* Initial hash value HASH(32byte) for SHA-512 */
extern "C"
const uint64_t sha512_initial_hash_value[8] =
{
    0x6a09e667f3bcc908ULL,
    0xbb67ae8584caa73bULL,
    0x3c6ef372fe94f82bULL,
    0xa54ff53a5f1d36f1ULL,
    0x510e527fade682d1ULL,
    0x9b05688c2b3e6c1fULL,
    0x1f83d9abfb41bd6bULL,
    0x5be0cd19137e2179ULL
};

/* Hash constant words K for SHA-384 and SHA-512: */
extern "C"
const uint64_t K512[80] =
{
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
    0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
    0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
    0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
    0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
    0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
    0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
    0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
    0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
    0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
    0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
    0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
    0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
    0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
    0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
    0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
    0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
    0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
    0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
    0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
    0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};

#define SHA512_SHORT_BLOCK_LENGTH (SHA512_BLOCK_LENGTH - 16)

/*
 * Macro for incrementally adding the unsigned 64-bit integer n to the
 * unsigned 128-bit integer (represented using a two-element array of
 * 64-bit words):
 */
#define ADDINC128(w,n) \
{ \
    (w)[0] += (uint64_t)(n); \
    if ((w)[0] < (n)) \
    { \
        (w)[1]++; \
    } \
}

/* Shift-right (used in SHA-512): */
#define R(b,x) ((x) >> (b))

/* 64-bit Rotate-right (used in SHA-512): */
#define S64(b,x) (((x) >> (b)) | ((x) << (64 - (b))))

/* Two of six logical functions used in SHA-512: */
#define Ch(x,y,z) (((x) & (y)) ^ ((~(x)) & (z)))
#define Maj(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

/* Four of six logical functions used in SHA-512: */
#define Sigma0_512(x) (S64(28, (x)) ^ S64(34, (x)) ^ S64(39, (x)))
#define Sigma1_512(x) (S64(14, (x)) ^ S64(18, (x)) ^ S64(41, (x)))
#define sigma0_512(x) (S64( 1, (x)) ^ S64( 8, (x)) ^ R( 7,   (x)))
#define sigma1_512(x) (S64(19, (x)) ^ S64(61, (x)) ^ R( 6,   (x)))

static void SHA512_Last(SHA512_CTX*);
static void SHA512_Transform(SHA512_CTX*, const uint64_t *);

/*
 * Constant used by SHA256/384/512_End() functions for converting the
 * digest to a readable hexadecimal character string:
 */
static inline void bcopy(const void * SRC, void* DST, size_t length)
{
    unsigned char * source = (unsigned char *) SRC;
    unsigned char * destination = (unsigned char *) DST;
    for( ; length ; length--)
    {
        *destination++ = *source++;
    }
}
static inline void bzero(void * DST, size_t length){
    unsigned char * destination = (unsigned char *) DST;
    for( ; length ; length--)
    {
        *destination++=0x00;
    }
}

/*** SHA-512: *********************************************************/
asm(".globl .L.SHA512_Init");
void SHA512_Init(SHA512_CTX* context)
{
    if (context == (SHA512_CTX*)0)
    {
        return;
    }

    uint64_t* sha512_initial_hash_value_p;
#ifdef EMULATE_HW
    sha512_initial_hash_value_p = sha512_initial_hash_value;
#else
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                 "sub  %0,2,%0 \n\t" // because subi does not work
                 "addi %0,%0,(sha512_initial_hash_value-0x8000)@l" : "=r" (sha512_initial_hash_value_p) );
#endif

    bcopy(sha512_initial_hash_value_p, context->state, SHA512_DIGEST_LENGTH);
    bzero(context->buffer, SHA512_BLOCK_LENGTH);
    context->bitcount[0] = context->bitcount[1] =  0;
}


static void SHA512_Transform(SHA512_CTX* context, const uint64_t* data)
{
    uint64_t a, b, c, d, e, f, g, h, s0, s1;
    uint64_t T1, T2, *W512 = (uint64_t*)context->buffer;
    int j;

    uint64_t* K512_p;
#ifdef EMULATE_HW
    K512_p = K512;
#else
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                 "sub  %0,2,%0 \n\t" // because subi does not work
                 "addi %0,%0,(K512-0x8000)@l" : "=r" (K512_p) );
#endif

    /* Initialize registers with the prev. intermediate value */
    a = context->state[0];
    b = context->state[1];
    c = context->state[2];
    d = context->state[3];
    e = context->state[4];
    f = context->state[5];
    g = context->state[6];
    h = context->state[7];

    j = 0;
    do {
        /* Apply the SHA-512 compression function to update a..h with copy */
        T1 = h + Sigma1_512(e) + Ch(e, f, g) + K512_p[j] + (W512[j] = *data++);
        T2 = Sigma0_512(a) + Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;

        j++;
    } while (j < 16);

    do {
        /* Part of the message block expansion: */
        s0 = W512[(j+1)&0x0f];
        s0 = sigma0_512(s0);
        s1 = W512[(j+14)&0x0f];
        s1 =  sigma1_512(s1);

        /* Apply the SHA-512 compression function to update a..h */
        T1 = h + Sigma1_512(e) + Ch(e, f, g) + K512_p[j] +
             (W512[j&0x0f] += s1 + W512[(j+9)&0x0f] + s0);
        T2 = Sigma0_512(a) + Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;

        j++;
    } while (j < 80);

    /* Compute the current intermediate hash value */
    context->state[0] += a;
    context->state[1] += b;
    context->state[2] += c;
    context->state[3] += d;
    context->state[4] += e;
    context->state[5] += f;
    context->state[6] += g;
    context->state[7] += h;

    /* Clean up */
    a = b = c = d = e = f = g = h = T1 = T2 = 0;
}

asm(".globl .L.SHA512_Update");
void SHA512_Update(SHA512_CTX* context, const sha2_byte *data, size_t len)
{
    unsigned int freespace, usedspace;

    if (len == 0)
    {
        /* Calling with no data is valid - we do nothing */
        return;
    }

    usedspace = (context->bitcount[0] >> 3) % SHA512_BLOCK_LENGTH;
    if (usedspace > 0)
    {
        /* Calculate how much free space is available in the buffer */
        freespace = SHA512_BLOCK_LENGTH - usedspace;

        if (len >= freespace)
        {
            /* Fill the buffer completely and process it */
            bcopy(data, &context->buffer[usedspace], freespace);
            ADDINC128(context->bitcount, freespace << 3);
            len -= freespace;
            data += freespace;
            SHA512_Transform(context, (uint64_t*)context->buffer);
        }
        else
        {
            /* The buffer is not yet full */
            bcopy(data, &context->buffer[usedspace], len);
            ADDINC128(context->bitcount, len << 3);
            /* Clean up: */
            usedspace = freespace = 0;
            return;
        }
    }
    while (len >= SHA512_BLOCK_LENGTH)
    {
        /* Process as many complete blocks as we can */
        SHA512_Transform(context, (const uint64_t*)data);
        ADDINC128(context->bitcount, SHA512_BLOCK_LENGTH << 3);
        len -= SHA512_BLOCK_LENGTH;
        data += SHA512_BLOCK_LENGTH;
    }
    if (len > 0)
    {
        /* There's left-overs, so save 'em */
        bcopy(data, context->buffer, len);
        ADDINC128(context->bitcount, len << 3);
    }
    /* Clean up: */
    usedspace = freespace = 0;
}

static void SHA512_Last(SHA512_CTX* context)
{
    unsigned int usedspace;

    usedspace = (context->bitcount[0] >> 3) % SHA512_BLOCK_LENGTH;
    if (usedspace > 0)
    {
        /* Begin padding with a 1 bit: */
        context->buffer[usedspace++] = 0x80;

#if SHA512_FIX
        if (usedspace < SHA512_SHORT_BLOCK_LENGTH)
        {
            /* Set-up for the last transform: */
            bzero(&context->buffer[usedspace], SHA512_SHORT_BLOCK_LENGTH
                  - usedspace);
        }
        else if (usedspace > SHA512_SHORT_BLOCK_LENGTH)
        {
            if (usedspace < SHA512_BLOCK_LENGTH)
            {
                bzero(&context->buffer[usedspace], SHA512_BLOCK_LENGTH
                      - usedspace);
            }
            /* Do second-to-last transform: */
            SHA512_Transform(context, (uint64_t*)context->buffer);

            /* And set-up for the last transform: */
            bzero(context->buffer, SHA512_SHORT_BLOCK_LENGTH);
        }
#else
        if (usedspace < SHA512_SHORT_BLOCK_LENGTH)
        {
            /* Set-up for the last transform: */
            bzero(&context->buffer[usedspace], SHA512_SHORT_BLOCK_LENGTH
                  - usedspace);
        }
        else
        {
            if (usedspace < SHA512_BLOCK_LENGTH)
            {
                bzero(&context->buffer[usedspace], SHA512_BLOCK_LENGTH
                      - usedspace);
            }
            /* Do second-to-last transform: */
            SHA512_Transform(context, (uint64_t*)context->buffer);

            /* And set-up for the last transform: */
            bzero(context->buffer, SHA512_BLOCK_LENGTH - 2);
        }
#endif
    }
    else
    {
        /* Prepare for final transform: */
        bzero(context->buffer, SHA512_SHORT_BLOCK_LENGTH);

        /* Begin padding with a 1 bit: */
        *context->buffer = 0x80;
    }
    /* Store the length of input data (in bits): */
    uint64_t* p1 = reinterpret_cast<uint64_t*>(&context->buffer[SHA512_SHORT_BLOCK_LENGTH]);
    uint64_t* p2 = reinterpret_cast<uint64_t*>(&context->buffer[SHA512_SHORT_BLOCK_LENGTH+8]);
    *p1 = context->bitcount[1];
    *p2 = context->bitcount[0];

    /* Final transform: */
    SHA512_Transform(context, (uint64_t*)context->buffer);
}

asm(".globl .L.SHA512_Final");
void SHA512_Final(SHA512_CTX* context, sha2_hash_t *result) {
    /* Sanity check: */
    //assert(context != (SHA512_CTX*)0);

    /* If no digest buffer is passed, we don't bother doing this: */
    SHA512_Last(context);

    /* Save the hash data for output: */
    bcopy(context->state, result, SHA512_DIGEST_LENGTH);

    /* Zero out state data */
    bzero(context, sizeof(context));
}

asm(".globl .L.SHA512_Hash");
void SHA512_Hash(const sha2_byte* data, size_t len, sha2_hash_t *result) {
    SHA512_CTX context;

    SHA512_Init(&context);
    SHA512_Update(&context, data, len);
    SHA512_Final(&context, result);
}