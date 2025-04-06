/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/contrib/keccak.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024,2025                        */
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
// This file was modified from the ekb version of this file used by
// the processor SBE code for sha3/v3 verification
#include <stdint.h>
#include <securerom/keccak.H>
#include <securerom/sha3.H>

#ifdef __PPE__
    #include <ppe42_string.h>
#else
    #include <string.h>
#endif

static const uint64_t keccak_rcs[KECCAK_ROUNDS] =
{
    0x0000000000000001ULL,
    0x0000000000008082ULL,
    0x800000000000808aULL,
    0x8000000080008000ULL,
    0x000000000000808bULL,
    0x0000000080000001ULL,
    0x8000000080008081ULL,
    0x8000000000008009ULL,
    0x000000000000008aULL,
    0x0000000000000088ULL,
    0x0000000080008009ULL,
    0x000000008000000aULL,
    0x000000008000808bULL,
    0x800000000000008bULL,
    0x8000000000008089ULL,
    0x8000000000008003ULL,
    0x8000000000008002ULL,
    0x8000000000000080ULL,
    0x000000000000800aULL,
    0x800000008000000aULL,
    0x8000000080008081ULL,
    0x8000000000008080ULL,
    0x0000000080000001ULL,
    0x8000000080008008ULL
};

#define ROTL64(i, n) ((i << n) ^ (i >> (64-n)))

static void keccak_permute(Keccak_state* state)
{
    uint64_t* A = state->A;
    int i = 0;

    /**
     *  For i_r from 12+2l-n_r to 12+2l-1, A=Rnd(A,i_r)
     *  l=6, n_r=24 => 0 to 23 => 24 rounds
     *  Rnd(A, i_r) = ι(χ(π(ρ(θ(A)))), i_r)
     */
    for (i = 0; i < KECCAK_ROUNDS; ++i)
    {
        /* θ(A) */
        uint64_t CZ[5];
        uint64_t DZ[5];
        uint64_t tmp0, tmp1;
        CZ[0] = A[0] ^ A[5] ^ A[10] ^ A[15] ^ A[20];
        CZ[1] = A[1] ^ A[6] ^ A[11] ^ A[16] ^ A[21];
        CZ[2] = A[2] ^ A[7] ^ A[12] ^ A[17] ^ A[22];
        CZ[3] = A[3] ^ A[8] ^ A[13] ^ A[18] ^ A[23];
        CZ[4] = A[4] ^ A[9] ^ A[14] ^ A[19] ^ A[24];

        DZ[0] = CZ[4] ^ ROTL64(CZ[1], 1);
        DZ[1] = CZ[0] ^ ROTL64(CZ[2], 1);
        DZ[2] = CZ[1] ^ ROTL64(CZ[3], 1);
        DZ[3] = CZ[2] ^ ROTL64(CZ[4], 1);
        DZ[4] = CZ[3] ^ ROTL64(CZ[0], 1);

        /**
         * for (int j = 0; j < KECCAK_P_64L; ++j)
         *  A[j] ^= DZ[j % 5];
        */
        A[0] ^= DZ[0];
        A[1] ^= DZ[1];
        A[2] ^= DZ[2];
        A[3] ^= DZ[3];
        A[4] ^= DZ[4];
        A[5] ^= DZ[0];
        A[6] ^= DZ[1];
        A[7] ^= DZ[2];
        A[8] ^= DZ[3];
        A[9] ^= DZ[4];
        A[10] ^= DZ[0];
        A[11] ^= DZ[1];
        A[12] ^= DZ[2];
        A[13] ^= DZ[3];
        A[14] ^= DZ[4];
        A[15] ^= DZ[0];
        A[16] ^= DZ[1];
        A[17] ^= DZ[2];
        A[18] ^= DZ[3];
        A[19] ^= DZ[4];
        A[20] ^= DZ[0];
        A[21] ^= DZ[1];
        A[22] ^= DZ[2];
        A[23] ^= DZ[3];
        A[24] ^= DZ[4];

        /* pi(ρ(θ(A))) */
        /** A[0] = A[0] */
        /**
         * int x = 1, y = 0;
         * for (int t = 0; t <= 23; ++t) {
         *   A'[y*5+x] = ROTL64(A[y*5+x], ((t+1)*(t+2)/2) % 64);
         *   (x, y)= (y, (2x+3y) mod 5)
         * }
         *
         * for (int t = 0; t < KECCAK_P_64L; ++t) {
         *   A[t] = A['idx'((x + 3y) mod 5', x]
         *
        */
        tmp0 = ROTL64(A[1], 1);
        tmp1 = ROTL64(A[10], 3);
        A[10] = tmp0;
        tmp0 = ROTL64(A[7], 6);
        A[7] = tmp1;
        tmp1 = ROTL64(A[11], 10);
        A[11] = tmp0;
        tmp0 = ROTL64(A[17], 15);
        A[17] = tmp1;
        tmp1 = ROTL64(A[18], 21);
        A[18] = tmp0;
        tmp0 = ROTL64(A[3], 28);
        A[3] = tmp1;
        tmp1 = ROTL64(A[5], 36);
        A[5] = tmp0;
        tmp0 = ROTL64(A[16], 45);
        A[16] = tmp1;
        tmp1 = ROTL64(A[8], 55);
        A[8] = tmp0;
        tmp0 = ROTL64(A[21], 2);
        A[21] = tmp1;
        tmp1 = ROTL64(A[24], 14);
        A[24] = tmp0;
        tmp0 = ROTL64(A[4], 27);
        A[4] = tmp1;
        tmp1 = ROTL64(A[15], 41);
        A[15] = tmp0;
        tmp0 = ROTL64(A[23], 56);
        A[23] = tmp1;
        tmp1 = ROTL64(A[19], 8);
        A[19] = tmp0;
        tmp0 = ROTL64(A[13], 25);
        A[13] = tmp1;
        tmp1 = ROTL64(A[12], 43);
        A[12] = tmp0;
        tmp0 = ROTL64(A[2], 62);
        A[2] = tmp1;
        tmp1 = ROTL64(A[20], 18);
        A[20] = tmp0;
        tmp0 = ROTL64(A[14], 39);
        A[14] = tmp1;
        tmp1 = ROTL64(A[22], 61);
        A[22] = tmp0;
        tmp0 = ROTL64(A[9], 20);
        A[9] = tmp1;
        tmp1 = ROTL64(A[6], 44);
        A[6] = tmp0;
        A[1] = tmp1;



        /* χ(π(ρ(θ(A))))
         * for (int t = 0; t < KECCAK_P_64L; ++t) {
         *   A[t] = A[t] ^ ~A['idx'((x + 1) mod 5', x] & A['idx'((x + 2) mod 5', x]
         */
        CZ[0] = A[4] ^ (~A[0] & A[1]);
        CZ[1] = A[0] ^ (~A[1] & A[2]);
        CZ[2] = A[1] ^ (~A[2] & A[3]);
        CZ[3] = A[2] ^ (~A[3] & A[4]);
        CZ[4] = A[3] ^ (~A[4] & A[0]);
        A[4] = CZ[0];
        A[0] = CZ[1];
        A[1] = CZ[2];
        A[2] = CZ[3];
        A[3] = CZ[4];

        CZ[0] = A[9] ^ (~A[5] & A[6]);
        CZ[1] = A[5] ^ (~A[6] & A[7]);
        CZ[2] = A[6] ^ (~A[7] & A[8]);
        CZ[3] = A[7] ^ (~A[8] & A[9]);
        CZ[4] = A[8] ^ (~A[9] & A[5]);
        A[9] = CZ[0];
        A[5] = CZ[1];
        A[6] = CZ[2];
        A[7] = CZ[3];
        A[8] = CZ[4];

        CZ[0] = A[14] ^ (~A[10] & A[11]);
        CZ[1] = A[10] ^ (~A[11] & A[12]);
        CZ[2] = A[11] ^ (~A[12] & A[13]);
        CZ[3] = A[12] ^ (~A[13] & A[14]);
        CZ[4] = A[13] ^ (~A[14] & A[10]);
        A[14] = CZ[0];
        A[10] = CZ[1];
        A[11] = CZ[2];
        A[12] = CZ[3];
        A[13] = CZ[4];

        CZ[0] = A[19] ^ (~A[15] & A[16]);
        CZ[1] = A[15] ^ (~A[16] & A[17]);
        CZ[2] = A[16] ^ (~A[17] & A[18]);
        CZ[3] = A[17] ^ (~A[18] & A[19]);
        CZ[4] = A[18] ^ (~A[19] & A[15]);
        A[19] = CZ[0];
        A[15] = CZ[1];
        A[16] = CZ[2];
        A[17] = CZ[3];
        A[18] = CZ[4];

        CZ[0] = A[24] ^ (~A[20] & A[21]);
        CZ[1] = A[20] ^ (~A[21] & A[22]);
        CZ[2] = A[21] ^ (~A[22] & A[23]);
        CZ[3] = A[22] ^ (~A[23] & A[24]);
        CZ[4] = A[23] ^ (~A[24] & A[20]);
        A[24] = CZ[0];
        A[20] = CZ[1];
        A[21] = CZ[2];
        A[22] = CZ[3];
        A[23] = CZ[4];

        /* ι(χ(π(ρ(θ(A)))): Add round constant */
        A[0] ^= keccak_rcs[i];
    }

}

#define KECCAK_MIN(a, b) (a < b ? (a) : (b))

static void keccak_sponge_init(Keccak_state* state)
{
    memset(state->A, 0, KECCAK_P_64L * 8);
    state->idx = 0;
}

static void keccak_sponge_absorb_update(Keccak_state* state, const uint8_t* N, size_t Nlen, size_t rBytes)
{
    uint64_t* A = state->A;
    size_t i = state->idx;

    /** Number of bytes in the first block */
    size_t fb_bytes = (i > 0 ? KECCAK_MIN(Nlen, rBytes - i) : 0);
    /** Number of full blocks */
    size_t fl_blocks = (Nlen - fb_bytes) / rBytes;
    /** Number of bytes in the last block */
    size_t lb_bytes = (Nlen - fb_bytes - fl_blocks * rBytes);

    /** First partial block */
    for (; i < state->idx + fb_bytes; ++i)
    {
        A[i / 8] ^= ((uint64_t) * N++) << 8 * (i % 8);
    }

    if (i == rBytes)
    {
        keccak_permute(state);
        i = 0;
    }

    /** Full blocks */
    for (size_t j = 0; j < fl_blocks; ++j)
    {
        for (; i < rBytes / 8; ++i, N += 8)
        {
            A[i] ^=
                ((uint64_t) N[0]) ^
                (((uint64_t) N[1]) << 8) ^
                (((uint64_t) N[2]) << 16) ^
                (((uint64_t) N[3]) << 24) ^
                (((uint64_t) N[4]) << 32) ^
                (((uint64_t) N[5]) << 40) ^
                (((uint64_t) N[6]) << 48) ^
                (((uint64_t) N[7]) << 56);
        }

        keccak_permute(state);
        i = 0;
    }

    /** Last partial block */
    for (; i < lb_bytes; ++i)
    {
        A[i / 8] ^= ((uint64_t) * N++) << 8 * (i % 8);
    }

    state->idx = i;
}

/**
 * Final absorb part of Keccak Sponge, includes padding.
 * Does the first permute for squeezing
*/
static void keccak_sponge_absorb_final(Keccak_state* state, size_t rBytes, int domsep)
{
    uint64_t* A = state->A;
    size_t i = state->idx;

    A[i / 8] ^= ((uint64_t) domsep) << (8 * (i % 8));
    A[rBytes / 8 - 1] ^= UINT64_C(0x8000000000000000);

    state->idx = 0;
}

static void keccak_sponge_squeeze_blocks_update(Keccak_state* state, uint8_t* out, size_t blocks, size_t rBytes)
{
    uint64_t* A = state->A;

    for (size_t j = 0; j < blocks; ++j)
    {
        keccak_permute(state);

        for (size_t i = 0; i < rBytes; ++i)
        {
            *out++ = A[i / 8] >> 8 * (i % 8);
        }
    }
}

static void keccak_sponge_squeeze_update(Keccak_state* state, size_t Ni, uint8_t* out, size_t rBytes)
{
    uint64_t* A = state->A;
    size_t i = state->idx;

    /** Number of bytes in the first block */
    size_t fb_bytes = (i > 0 ? KECCAK_MIN(Ni, rBytes - i) : 0);
    /** Number of full blocks */
    size_t fl_blocks = (Ni - fb_bytes) / rBytes;
    /** Number of bytes in the last block */
    size_t lb_bytes = (Ni - fb_bytes - fl_blocks * rBytes);

    /** First partial block */
    for (; i < state->idx + fb_bytes; ++i)
    {
        *out++ = A[i / 8] >> 8 * (i % 8);
    }

    /** Full blocks */
    for (size_t j = 0; j < fl_blocks; ++j)
    {
        keccak_permute(state);

        for (i = 0; i < rBytes / 8; ++i, out += 8)
        {
            out[0] = A[i];
            out[1] = A[i] >> 8;
            out[2] = A[i] >> 16;
            out[3] = A[i] >> 24;
            out[4] = A[i] >> 32;
            out[5] = A[i] >> 40;
            out[6] = A[i] >> 48;
            out[7] = A[i] >> 56;
        }

        i = 0;
    }

    if (i == 0 && lb_bytes)
    {
        keccak_permute(state);
    }

    /** Last partial block */
    for (; i < lb_bytes; ++i)
    {
        *out++ = A[i / 8] >> 8 * (i % 8);
    }

    state->idx = i;
}

static void keccak_sponge_wipe(Keccak_state* state)
{
    volatile uint64_t* tmp = (volatile uint64_t*)state->A;

    for (int i = 0; i < KECCAK_P_64L; ++i)
    {
        tmp[i] = 0;
    }
}

/** Incremental API for SHAKE128 / SHAKE256 */

void shake128_absorb(Keccak_state* state, const uint8_t* in, size_t inlen)
{
    keccak_sponge_absorb_update(state, in, inlen, SHAKE128_RATE);
}

void shake256_absorb(Keccak_state* state, const uint8_t* in, size_t inlen)
{
    keccak_sponge_absorb_update(state, in, inlen, SHAKE256_RATE);
}

void shake128_init(Keccak_state* state)
{
    keccak_sponge_init(state);
}

void shake128_finalize(Keccak_state* state)
{
    keccak_sponge_absorb_final(state, SHAKE128_RATE, SHAKE_DOMAIN_SEP);
}

void shake128_squeeze(uint8_t* out, size_t outlen, Keccak_state* state)
{
    keccak_sponge_squeeze_update(state, outlen, out, SHAKE256_RATE);
}

void shake128_absorb_once(Keccak_state* state, const uint8_t* in, size_t inlen)
{
    keccak_sponge_init(state);
    keccak_sponge_absorb_update(state, in, inlen, SHAKE128_RATE);
    keccak_sponge_absorb_final(state, SHAKE128_RATE, SHAKE_DOMAIN_SEP);
}

void shake128_squeezeblocks(uint8_t* out, size_t nblocks, Keccak_state* state)
{
    keccak_sponge_squeeze_blocks_update(state, out, nblocks, SHAKE128_RATE);
}

void shake128_wipe(Keccak_state* state)
{
    keccak_sponge_wipe(state);
}

void shake256_init(Keccak_state* state)
{
    keccak_sponge_init(state);
}

void shake256_finalize(Keccak_state* state)
{
    keccak_sponge_absorb_final(state, SHAKE256_RATE, SHAKE_DOMAIN_SEP);
}

void shake256_squeeze(uint8_t* out, size_t outlen, Keccak_state* state)
{
    keccak_sponge_squeeze_update(state, outlen, out, SHAKE256_RATE);
}

void shake256_absorb_once(Keccak_state* state, const uint8_t* in, size_t inlen)
{
    keccak_sponge_init(state);
    keccak_sponge_absorb_update(state, in, inlen, SHAKE256_RATE);
    keccak_sponge_absorb_final(state, SHAKE256_RATE, SHAKE_DOMAIN_SEP);
}

void shake256_squeezeblocks(uint8_t* out, size_t nblocks, Keccak_state* state)
{
    keccak_sponge_squeeze_blocks_update(state, out, nblocks, SHAKE256_RATE);
}

void shake256_wipe(Keccak_state* state)
{
    keccak_sponge_wipe(state);
}

/** Non-incremental API for SHAKE128 / SHAKE256 */

void shake128(uint8_t* out, size_t outlen, const uint8_t* in, size_t inlen)
{
    Keccak_state state;

    size_t blocks = outlen / SHAKE128_RATE;
    size_t rem = blocks * SHAKE128_RATE;

    shake128_absorb_once(&state, in, inlen);
    shake128_squeezeblocks(out, blocks, &state);
    shake128_squeeze(out + rem, outlen - rem, &state);
    shake128_wipe(&state);
}

void shake256(uint8_t* out, size_t outlen, const uint8_t* in, size_t inlen)
{
    Keccak_state state;

    size_t blocks = outlen / SHAKE256_RATE;
    size_t rem = blocks * SHAKE256_RATE;

    shake256_absorb_once(&state, in, inlen);
    shake256_squeezeblocks(out, blocks, &state);
    shake256_squeeze(out + rem, outlen - rem, &state);
    shake256_wipe(&state);
}

// At this time Hostboot code is not support the sha3_256() function so
// it will be compiled out, but kept here for reference
#if 0
/** Non-incremental API for SHA3-256 / SHA3-512 */
void sha3_256(uint8_t h[32], const uint8_t* in, size_t inlen)
{
    Keccak_state state;
    keccak_sponge_init(&state);
    keccak_sponge_absorb_update(&state, in, inlen, SHA3_256_RATE);
    keccak_sponge_absorb_final(&state, SHA3_256_RATE, SHA3_DOMAIN_SEP);
    keccak_sponge_squeeze_update(&state, 32, h, SHA3_256_RATE);
    keccak_sponge_wipe(&state);
}
#endif

// @TODO JIRA PFHB-921 reinstate the asm() call so that the securerom
// branch table can properly find this function
//asm(".globl .L.sha3_512");
void sha3_512(uint8_t h[64], const uint8_t* in, size_t inlen)
{
    Keccak_state state;
    keccak_sponge_init(&state);
    keccak_sponge_absorb_update(&state, in, inlen, SHA3_512_RATE);
    keccak_sponge_absorb_final(&state, SHA3_512_RATE, SHA3_DOMAIN_SEP);
    keccak_sponge_squeeze_update(&state, 64, h, SHA3_512_RATE);
    keccak_sponge_wipe(&state);
}

/** Incremental API for SHA3-512 */
// At this time Hostboot code is only supporting the sha3() function so
// these incremental API functions will be compiled out, but kept here for
// reference
#if 0
void sha3_512_init(Keccak_state* state)
{
    keccak_sponge_init(state);
}

void sha3_512_update(Keccak_state* state, const void* data, size_t len)
{
    keccak_sponge_absorb_update(state, (const uint8_t*) data, len, SHA3_512_RATE);
}

void sha3_512_final(uint8_t md[64], Keccak_state* state)
{
    keccak_sponge_absorb_final(state, SHA3_512_RATE, SHA3_DOMAIN_SEP);
    keccak_sponge_squeeze_update(state, 64, md, SHA3_512_RATE);
    keccak_sponge_wipe(state);
}
#endif

/** Functions are defined in src/include/securerom/contrib/sha3.H **/

// At this time Hostboot code is only supporting the sha3() function so
// these other functions will be compiled out, but kept here for reference
#if 0

int sha3_init(sha3_ctx_t* c)
{
    sha3_512_init(c);
    return 1;
}

int sha3_update(sha3_ctx_t* c, const void* data, size_t len)
{
    sha3_512_update(c, data, len);
    return 1;
}

asm(".globl .L.sha3_final");
int sha3_final(sha3_t* md, sha3_ctx_t* c)
{
    sha3_512_final((uint8_t*)md, c);
    return 1;
}
#endif

// This is the main sha3() function that hostboot uses, which essentially
// just calls one other function in this file: sha3_512()
// @TODO JIRA PFHB-921 reinstate the asm() call so that the securerom
// branch table can properly find this function
//asm(".globl .L.sha3");
void* sha3(const void* in, size_t inlen, void* md, int mdlen)
{
    sha3_t digest;
    sha3_512(digest, (const uint8_t*)in, inlen);
    memcpy(md, digest, ((mdlen > SHA3_DIGEST_LENGTH) ? SHA3_DIGEST_LENGTH : mdlen));
    return md;
}

