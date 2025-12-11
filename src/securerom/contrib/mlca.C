/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/contrib/mlca.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024,2026                        */
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
// SPDX-License-Identifier: Apache-2.0
// This file was modified from the ekb version of this file used by
// the processor SBE code for mldsa_verify/v3 verification

/*
 * README
 *
 * This version of the file has all parts not used by hostboot
 * compiled out using #if 0 blocks, except for parts already
 * compiled out using compiler flags (eg NO_MLDSA_SIGN).
 *
 * Some changes needed to be made in order for this to work in
 * the secureROM.
 * 1. In several spots where const arrays are accessed, we
 *    have some inline assembly to find the proper location.
 * 2. Several switch statements are replaced with equivalent
 *    if statements due to compiler optimizations that break
 *    them in the secureROM
 */

/*----------------------------------------------------------------------
 *
 * Dilithium variants supported (K/L):
 *   round2
 *     Dil III   Dil-5/4
 *     Dil IV    Dil-6/5
 *     Dil V     Dil-8/7
 *   round3 (2021-02 update)
 *     Dil II    Dil-4/4
 *     Dil III   Dil-6/5
 *     Dil V     Dil-8/7
 *
 * Kyber variants supported:
 *   round2 and round3
 *   Kyb III   Kyber768
 *   Kyb V     Kyber1024
 *
 * define
 *    USE_STATIC_MLCA  -- make public functions static; suitable for
 *                     -- single-file distribution
 *
 * you may conditionalize parts by preventing features to skip:
 *    NO_CRYSTALS_SIG  -- remove digital signature sign/verify (Dilithium)
 *    NO_CRYSTALS_KEX  -- remove key transport (Kyber)
 *    NO_CRYSTALS_R2   -- exclude round3 versions, if appropriate
 *    NO_CRYSTALS_R3   -- exclude round2 versions, if appropriate
 *
 */

#if !defined(MLCA__IMPL_H__)
#define MLCA__IMPL_H__

#include <securerom/mlca.H>
#include <securerom/keccak.H>
#include <securerom/contrib/crystals-oids.h>
#include <securerom/contrib/pqalgs.h>

//MAB#include <securerom/contrib/v3_mlca/include/mlca2_int.h>
//MAB#include <securerom/contrib/v3_mlca/include/mlca2.h>

#if defined (__HOSTBOOT_MODULE)
#include <stdlib.h> // for mlca_malloc and mlca_free
#endif

#include <stddef.h>
#ifdef __PPE__
    #include <ppe42_string.h>
#else
    #include <string.h>
#endif

#define __INLINE__ inline
#define MEMCPY     memcpy
#define MEMCMP     memcmp
#define MEMMOVE    memmove
#define MEMSET     memset

#if !defined(COMMON_BASE_H__)
#define COMMON_BASE_H__ 1

/* note: a minimized version used within IBM prod environments
 * allow repeated inclusion of common-....h derivatives
 */

#if !defined(ARRAY_ELEMS)
    #define ARRAY_ELEMS(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

/* compile-time evaluated 'assertion'
 * assume leaves no runtime code around
 */
#if !defined(BUILD_ASSERT)
    #define BUILD_ASSERT(condition) ((void)sizeof(char[1 - 2 * !(condition)]))
#endif

#if !defined(MARK_UNUSED)
    #define MARK_UNUSED(prm) (void)(prm) /* used for 'unused' warnings */
#endif

#if (__GNUC__ >= 3) /* note: pre-gcc3 support is basically irrelevant */
    #define ATTR_PURE__  __attribute__((pure))
    #define ATTR_CONST__ __attribute__((const))

#else
    #define ATTR_PURE__  /**/
    #define ATTR_CONST__ /**/
#endif               /* gcc >= 3 */

/* NOP marker for possibly-sensitive stack structs */
#define CRS_SENSITIVE /**/

/*--------------------------------------
 * endianness-conversion 'macros'
 * assuming ntohl() etc. are real functions, not static-inline macros
 */

/*------------------------------------*/
static __INLINE__ uint32_t MSBF3_READ(const void* p)
{
    const unsigned char* pb = (const unsigned char*)p;

    return ((((uint32_t)(pb)[2])) | (((uint32_t)((pb)[1])) << 8) |
            (((uint32_t)((pb)[0])) << 16));
}

/*------------------------------------*/
static __INLINE__ uint32_t MSBF4_READ(const void* p)
{
    const unsigned char* pb = (const unsigned char*)p;

    return ((((uint32_t)(pb)[3])) | (((uint32_t)((pb)[2])) << 8) |
            (((uint32_t)((pb)[1])) << 16) | (((uint32_t)((pb)[0])) << 24));
}

/*------------------------------------*/
static __INLINE__ uint32_t LSBF4_READ(const void* p)
{
    const unsigned char* pb = (const unsigned char*)p;

    return ((((uint32_t)(pb)[0])) | (((uint32_t)((pb)[1])) << 8) |
            (((uint32_t)((pb)[2])) << 16) | (((uint32_t)((pb)[3])) << 24));
}

/*--------------------------------------
 * assume this gets inlined, possibly through bswap() or equivalent
 * recent gcc/clang and some xlc's tend to do so
 */
static __INLINE__ void MSBF4_WRITE(void* p, uint64_t v)
{
    unsigned char* pb = (unsigned char*)p;

    pb[3] = (unsigned char)v;
    pb[2] = (unsigned char)(v >> 8);
    pb[1] = (unsigned char)(v >> 16);
    pb[0] = (unsigned char)(v >> 24);
}

/*--------------------------------------
 * assume this gets inlined, possibly through bswap() or equivalent
 * recent gcc/clang and some xlc's tend to do so
 */
// Commented out and replaced with regular memset call
// Because this crashes in secureROM context
#if 0
static __INLINE__ void* MEMSET0_STRICT(void* mem, size_t size)
{
    typedef void* (*memset_t)(void*, int, size_t);
    static volatile memset_t memset_func = MEMSET;
    memset_func(mem, 0, size);
    return mem;
}
#endif

#endif /* !defined(COMMON_BASE_H__) */

#if defined(NO_CRYSTALS_SIG)
    #if defined(NO_CRYSTALS_CIP) && defined(NO_CRYSTALS_KEX)
        #error "error: both signature and key-transport/encryption has been prohibited"
    #endif
#endif

/* conditionally keep top fns module-local */
#if defined(USE_STATIC_MLCA)
    #define CRS_STATIC static
#else
    #define CRS_STATIC /**/
#endif

#if !defined(NO_MLCA_RANDOM)
//MAB #include <mlca2_random.h>
//MAB#include <securerom/contrib/v3_mlca/include/mlca2_random.h>
CRS_STATIC size_t randombytes(unsigned char* r, size_t rbytes, void* rng)
{
    return 123;
}
#endif

#if 1 /*-----  delimiter: Crystals core  -----------------------------*/
typedef enum
{
    CRS__SPC_PRV2PUB = 1 /* such as PKCS8-to-SPKI or public-to-private */
} CRS__SpecOID_t;

#if 0
CRS_STATIC unsigned int is_special_oid(const unsigned char* oid, size_t oidb)
{
    if (!oid || !oidb)
    {
        return 0;
    }

    if (oidb != CR_OID_SPECIAL_PRV2PUB_BYTES)
    {
        return 0;
    }

    if (!MEMCMP(oid, CR_OID_SPECIAL_PRV2PUB, CR_OID_SPECIAL_PRV2PUB_BYTES))
    {
        return CRS__SPC_PRV2PUB;
    }

    return 0;
}
#endif

#if 1 /*-----  delimiter: reduce  ------------------------------------*/
#define DIL_D                         14
#define DIL_Q                         8380417
#define DIL_MONT                      4193792U    /* 2^32 % DIL_Q */
#define DIL_QINV                      4236238847U /* -1/DIL_Q mod 2^32 */
#define DIL_GAMMA1                    ((DIL_Q - 1) / 16)
#define DIL_GAMMA2                    (DIL_GAMMA1 / 2)
#define DIL_ALPHA                     (2 * DIL_GAMMA2)

#define DIL_MLDSA_TRBYTES             64
#define DIL_MLDSA_RNDBYTES            32

/*
 * round3 equivalent, first with ref.impl-compatible signed units
 * unless otherwise noted, DIL_... constants are identical for r2 and r3
 */
#define DIL_SD                        13
#define DIL_SMONT                     -4186625 /* 2^32 % DIL_Q, signed units */
#define DIL_SQINV                     58728449 /* 1/DIL_Q mod 2^32, signed units */
/**/
#define KYB_Q                         3329
#define KYB_MONT                      2285 /* 2^16 ^ KYB_Q */
#define KYB_R3_MONT                   -1044
#define KYB_QINV                      62209 /* -1/KYB_Q mod 2^16 */
#define KYB_R3_QINV                   -3327
#define KYB_ETA                       2
#define KYB_ETA1                      2
#define KYB_POLYBYTES                 ((size_t)384)
#define KYB_SYMBYTES                  ((size_t)32)
#define KYB_SHRDBYTES                 ((size_t)32) /* shared secret size */
#define KYB_INDCPA_MSGBYTES           KYB_SYMBYTES

#define DIL_SEEDBYTES                 ((unsigned int)256 / 8)
#define DIL_CRHBYTES                  ((unsigned int)384 / 8)
#define DIL_R3_CRHBYTES               ((unsigned int)512 / 8)
/* max(r2, r3 CRH) */
#define DIL_MAX_CRHBYTES              DIL_R3_CRHBYTES

#define DIL_R2_POLYT0_PACKEDBYTES     ((unsigned int)448)
#define DIL_R2_POLYT1_PACKEDBYTES     ((unsigned int)288)
#define DIL_R3_POLYT0_PACKEDBYTES     ((unsigned int)416)
#define DIL_R3_POLYT1_PACKEDBYTES     ((unsigned int)320)
/**/
#define DIL_POLYW1_PACKEDBYTES        ((unsigned int)128)
/* r3 is param-dependent */
/**/
#define DIL_POLYZ_PACKEDBYTES         ((unsigned int)640)
/* r3 is param-dependent, see dil_r3k2polyz_bytes() */

/* K/L-dependent values for (5,4), (6,5), (8,7) */
/**/
#define DIL_PUB_BYTES(k)              (DIL_SEEDBYTES + (k)*DIL_R2_POLYT1_PACKEDBYTES)
#define DIL_PUB5x4_BYTES              DIL_PUB_BYTES(5)
#define DIL_PUB6x5_BYTES              DIL_PUB_BYTES(6)
#define DIL_PUB8x7_BYTES              DIL_PUB_BYTES(8)
/* round3 and round3.0 are identical: */
#define DIL_R3_PUB4x4_BYTES           ((size_t)1312)
#define DIL_R3_PUB6x5_BYTES           ((size_t)1952)
#define DIL_R3_PUB8x7_BYTES           ((size_t)2592)

#define DIL_MLDSA_44_PUB_BYTES        ((size_t)1312)
#define DIL_MLDSA_65_PUB_BYTES        ((size_t)1952)
#define DIL_MLDSA_87_PUB_BYTES        ((size_t)2592)

#define DIL_BETA5x4                   275
#define DIL_BETA6x5                   175
#define DIL_BETA8x7                   120

#define DIL_R3_BETA4x4                78
#define DIL_R3_BETA6x5                196
#define DIL_R3_BETA8x7                120

#define DIL_OMEGA5x4                  96
#define DIL_OMEGA6x5                  120
#define DIL_OMEGA8x7                  140

#define DIL_R3_OMEGA4x4               80
#define DIL_R3_OMEGA6x5               55
#define DIL_R3_OMEGA8x7               75

#define DIL_SIGBYTES5x4               2701
#define DIL_SIGBYTES6x5               3366
#define DIL_SIGBYTES8x7               4668

#define DIL_R3_SIGBYTES4x4            2420
#define DIL_R3_SIGBYTES6x5            3293
#define DIL_R3_SIGBYTES8x7            4595

#define DIL_MLDSA_SIGBYTES4x4         2420
#define DIL_MLDSA_SIGBYTES6x5         3309
#define DIL_MLDSA_SIGBYTES8x7         4627

/*
 * raw bytecounts, excl. any ASN.1/BER framing or post-appended in-band type
 * hardwired since formula contains conditionals; do not expect
 * compiler constant expansion
 */
#define DIL_PRV5x4_BYTES              ((size_t)3504)
#define DIL_PRV6x5_BYTES              ((size_t)3856)
#define DIL_PRV8x7_BYTES              ((size_t)5136)
/* see also dil_prv_wirebytes()
 */
/* was round3 v0:
#define  DIL_R3_PRV4x4_BYTES  ((size_t) 2544)   // r3.0
#define  DIL_R3_PRV6x5_BYTES  ((size_t) 4016)   // r3.0
#define  DIL_R3_PRV8x7_BYTES  ((size_t) 4880)   // r3.0
*/
#define DIL_R3_PRV4x4_BYTES           ((size_t)2528)
#define DIL_R3_PRV6x5_BYTES           ((size_t)4000)
#define DIL_R3_PRV8x7_BYTES           ((size_t)4864)

#define DIL_MLDSA_PRV4x4_BYTES        ((size_t)2560)
#define DIL_MLDSA_PRV6x5_BYTES        ((size_t)4032)
#define DIL_MLDSA_PRV8x7_BYTES        ((size_t)4896)

/* ETA <= 3 decides */
#define DIL_POLYETA5x4_PACKEDBYTES    ((size_t)128)
#define DIL_POLYETA6x5_PACKEDBYTES    ((size_t)96)
#define DIL_POLYETA8x7_PACKEDBYTES    ((size_t)96)
/**/
#define DIL_R3_POLYETA4x4_PACKEDBYTES ((size_t)96)
#define DIL_R3_POLYETA6x5_PACKEDBYTES ((size_t)128)
#define DIL_R3_POLYETA8x7_PACKEDBYTES ((size_t)96)

#define DIL_MLDSA_44_CTILDEBYTES      ((size_t)32)
#define DIL_MLDSA_65_CTILDEBYTES      ((size_t)48)
#define DIL_MLDSA_87_CTILDEBYTES      ((size_t)64)
#define DIL_MLDSA_MAX_CTILDEBYTES     DIL_MLDSA_87_CTILDEBYTES

#define DIL_VECT_MAX                  ((unsigned int)8) /* MAX(K, L) for any config */
#define KYB_VECT_MAX                  ((unsigned int)4) /* MAX(K) for any config */

/* raw/packed public key, private key, ciphertext */
/* Cat II Kyber512 is not supported */
/**/
/* #define KYB_PUB2_BYTES ((size_t) 800) */
#define KYB_PUB3_BYTES                ((size_t)1184)
#define KYB_PUB4_BYTES                ((size_t)1568)
/*
 * the _public_ key field within the _private_ key has a trailer,
 * after a verbatim copy of the public key
 */
#define KYB_PRV2PUB_ADDL_BYTES        ((size_t)256 / 8 + 256 / 8)
/**/
/* full encoding with prv bits plus included public part plus trailer */
/* #define KYB_PRV2_BYTES ((size_t) 1632) */
#define KYB_PRV3_BYTES                ((size_t)2400)
#define KYB_PRV4_BYTES                ((size_t)3168)
/**/
/* net-net encoding, only starting prv bits [one K-vector set] */
/* #define KYB_PRV2_NET_BYTES ((size_t) 768) */
#define KYB_PRV3_NET_BYTES            ((size_t)1152)
#define KYB_PRV4_NET_BYTES            ((size_t)1536)
/**/
/* #define KYB_CIPHTXT2_BYTES ((size_t) 736) */
#define KYB_CIPHTXT3_BYTES            ((size_t)1088)
#define KYB_CIPHTXT4_BYTES            ((size_t)1568)

/* trailing bytes _after_ raw key material, storing type as BE unsigned value:
 */
#define CRS_WTYPE_BYTES               ((size_t)4)

//--------------------------------------
typedef enum
{
    CRS_ALG_FL_SIG = 1,   // things related to signatures
    CRS_ALG_FL_KEX = 2,   // ...related to key exchange...
    CRS_ALG_FL_CIP = 4    // ...related to encryption...
} CRS_AlgFlag_t;

#if 1 /*-----  delimiter: SHA-3 PRF  -------------------------------------*/
/* SHA-3 PRF only: */
#define DIL_STREAM128_BLOCKBYTES SHAKE128_RATE
#define DIL_STREAM256_BLOCKBYTES SHAKE256_RATE
typedef Keccak_state stream128_state;
typedef Keccak_state stream256_state;
/**/
#define stream128_init(STATE, SEED, NONCE)                                     \
    shake128_stream_init(STATE, SEED, NONCE)
#define stream128_wipe(STATE) shake128_wipe(STATE)

#endif /*-----  /delimiter: SHA-3 PRF  ------------------------------------*/

/* /header constants from params.h */

/*************************************************
 * Description: For finite field element a with 0 <= a <= Q*2^32,
 *              compute r \equiv a*2^{-32} (mod Q) such that 0 <= r < 2*Q.
 * Arguments:   - uint64_t: finite field element a
 * Returns r.
 **************************************************/
ATTR_CONST__
/**/
CRS_STATIC uint32_t dil_montg_reduce(uint64_t a)
{
    uint64_t t;

    t = a * DIL_QINV;
    t &= ((uint64_t)1 << 32) - 1;
    t *= DIL_Q;
    t += a;

    t >>= 32;

    return t;
}

/*--------------------------------------
 * signed (r3 ref.) counterpart of montgomery_reduce()
 */
ATTR_CONST__
/**/
CRS_STATIC int32_t montgomery_s_reduce(int64_t a)
{
    int32_t t;

    t = (int64_t)a * DIL_SQINV;

    t = (a - (int64_t)t * DIL_Q) >> 32;

    return t;
}

/*************************************************
 * Description: For finite field element a, compute r \equiv a (mod Q)
 *              such that 0 <= r < 2*Q.
 * Arguments:   - uint32_t: finite field element a
 * Returns r.
 **************************************************/
ATTR_CONST__
/**/
CRS_STATIC uint32_t reduce32(uint32_t a)
{
    uint32_t t;

    t = a & 0x7FFFFF;
    a >>= 23;
    t += (a << 13) - a;

    return t;
}

/*************************************************
 * signed (r3 ref.impl.) counterpart of reduce32()
 *
 * Description: For finite field element a with a <= 2^{31} - 2^{22} - 1,
 *              compute r \equiv a (mod Q) such that -6283009 <= r <= 6283007.
 * Arguments:   - int32_t: finite field element a
 * Returns r.
 **************************************************/
ATTR_CONST__
/**/
CRS_STATIC int32_t s_reduce32(int32_t a)
{
    int32_t t;

    t = (a + (1 << 22)) >> 23;
    t = a - t * DIL_Q;

    return t;
}

/*************************************************
 * Description: Subtract Q if input coefficient is bigger than Q.
 * Arguments:   - uint32_t: finite field element a
 * Returns r.
 **************************************************/
CRS_STATIC uint32_t csubq(uint32_t a)
{
    a -= DIL_Q;

    a += ((int32_t)a >> 31) & DIL_Q;

    return a;
}

/*************************************************
 * Description: Add Q if input coefficient is negative.
 * Arguments:   - int32_t: finite field element a
 */
CRS_STATIC int32_t s_caddq(int32_t a)
{
    a += (a >> 31) & DIL_Q;

    return a;
}

/*************************************************
 * Description: For finite field element a, compute standard
 *              representative r = a mod Q.
 * Arguments:   - uint32_t: finite field element a
 * Returns r.
 **************************************************/
CRS_STATIC uint32_t freeze(uint32_t a)
{
    a = reduce32(a);
    a = csubq(a);

    return a;
}

/*************************************************
 * signed (r3 ref.impl.) counterpart of freeze()
 *
 * Description: For finite field element a, compute standard
 *              representative r = a mod^+ Q.
 * Arguments:   - int32_t: finite field element a
 * Returns r.
 **************************************************/
CRS_STATIC int32_t s_freeze(int32_t a)
{
    a = s_reduce32(a);
    a = s_caddq(a);

    return a;
}

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*-- Kyber ------*/

/* global vaiable used as barrier for constant-time functions */
volatile int16_t  int16_t_blocker = 0;
volatile uint16_t unt16_t_blocker = 0;
volatile uint8_t  uint8_t_blocker = 0;

//---------------------------------------
static void       kyb_cmov_int16(int16_t* r, int16_t v, uint16_t b)
{
    v ^= int16_t_blocker;
    b ^= unt16_t_blocker;
    b = -b;
    *r ^= (b & ((*r) ^ v));
}

/*************************************************
 * Description: Montgomery reduction; given a 32-bit integer a, computes
 *              16-bit integer congruent to a * R^-1 mod q,
 *              where R=2^16
 *
 * Arguments:   - int32_t a: input integer to be reduced;
 *                           has to be in {-q2^15,...,q2^15-1}
 *
 * Returns:     integer in {-q+1,...,q-1} congruent to a * R^-1 modulo q.
 **************************************************/
CRS_STATIC int16_t kyb__montg_reduce(int32_t a)
{
    int32_t t;
    int16_t u;

    u = a * KYB_QINV;
    t = (int32_t)u * KYB_Q;
    t = a - t;

    t >>= 16;

    return t;
}

CRS_STATIC int16_t r3_kyb__montg_reduce(int32_t a)
{
    int32_t t;
    int16_t u;

    u = a * KYB_R3_QINV;
    t = (int32_t)u * KYB_Q;
    t = a - t;

    t >>= 16;

    return t;
}

/*************************************************
 * Description: Barrett reduction; given a 16-bit integer a, computes
 *              16-bit integer congruent to a mod q in {0,...,q}
 * Arguments:   - int16_t a: input integer to be reduced
 * Returns:     integer in {0,...,q} congruent to a modulo q.
 **************************************************/
CRS_STATIC int16_t kyb__barrett_reduce(int16_t a)
{
    // int16_t v = ((1U << 26) + KYB_Q / 2) / KYB_Q;
    const int16_t v = 20159;
    int16_t       t;

    t = (int32_t)v * a >> 26;
    t *= KYB_Q;

    return a - t;
}

CRS_STATIC int16_t r3_kyb__barrett_reduce(int16_t a)
{
    // int16_t v = ((1U << 26) + KYB_Q / 2) / KYB_Q;
    const int16_t v = 20159;
    int16_t       t;

    t = ((int32_t)v * a + (1 << 25)) >> 26;
    t *= KYB_Q;

    return a - t;
}

/*************************************************
 * Description: Conditionallly subtract q
 * Arguments:   - int16_t x: input integer
 * Returns:     a - q if a >= q, else a
 **************************************************/
CRS_STATIC int16_t kyb__csubq(int16_t a)
{
    a -= KYB_Q;

    a += (a >> 15) & KYB_Q;

    return a;
}
#endif /*-----  /Kyber  -----------------------------*/
#endif /*-----  /delimiter: reduce  -----------------------------------*/

#if 1 /*-----  delimiter: NTT  ---------------------------------------*/
/* Kyber and Dilithium primes, so NTT-internal reductions, differ */

#define DIL_N ((unsigned int)256)
#define KYB_N ((unsigned int)256)

/*
 * Added extern "C" to all const arrays in order for us to be
 * able to find them properly in secureROM context
*/

/* Roots of unity in order needed by forward ntt */
extern "C"
const uint32_t dil_zetas[DIL_N] =
{
    0,       25847,   5771523, 7861508, 237124,  7602457, 7504169, 466468,
    1826347, 2353451, 8021166, 6288512, 3119733, 5495562, 3111497, 2680103,
    2725464, 1024112, 7300517, 3585928, 7830929, 7260833, 2619752, 6271868,
    6262231, 4520680, 6980856, 5102745, 1757237, 8360995, 4010497, 280005,
    2706023, 95776,   3077325, 3530437, 6718724, 4788269, 5842901, 3915439,
    4519302, 5336701, 3574422, 5512770, 3539968, 8079950, 2348700, 7841118,
    6681150, 6736599, 3505694, 4558682, 3507263, 6239768, 6779997, 3699596,
    811944,  531354,  954230,  3881043, 3900724, 5823537, 2071892, 5582638,
    4450022, 6851714, 4702672, 5339162, 6927966, 3475950, 2176455, 6795196,
    7122806, 1939314, 4296819, 7380215, 5190273, 5223087, 4747489, 126922,
    3412210, 7396998, 2147896, 2715295, 5412772, 4686924, 7969390, 5903370,
    7709315, 7151892, 8357436, 7072248, 7998430, 1349076, 1852771, 6949987,
    5037034, 264944,  508951,  3097992, 44288,   7280319, 904516,  3958618,
    4656075, 8371839, 1653064, 5130689, 2389356, 8169440, 759969,  7063561,
    189548,  4827145, 3159746, 6529015, 5971092, 8202977, 1315589, 1341330,
    1285669, 6795489, 7567685, 6940675, 5361315, 4499357, 4751448, 3839961,
    2091667, 3407706, 2316500, 3817976, 5037939, 2244091, 5933984, 4817955,
    266997,  2434439, 7144689, 3513181, 4860065, 4621053, 7183191, 5187039,
    900702,  1859098, 909542,  819034,  495491,  6767243, 8337157, 7857917,
    7725090, 5257975, 2031748, 3207046, 4823422, 7855319, 7611795, 4784579,
    342297,  286988,  5942594, 4108315, 3437287, 5038140, 1735879, 203044,
    2842341, 2691481, 5790267, 1265009, 4055324, 1247620, 2486353, 1595974,
    4613401, 1250494, 2635921, 4832145, 5386378, 1869119, 1903435, 7329447,
    7047359, 1237275, 5062207, 6950192, 7929317, 1312455, 3306115, 6417775,
    7100756, 1917081, 5834105, 7005614, 1500165, 777191,  2235880, 3406031,
    7838005, 5548557, 6709241, 6533464, 5796124, 4656147, 594136,  4603424,
    6366809, 2432395, 2454455, 8215696, 1957272, 3369112, 185531,  7173032,
    5196991, 162844,  1616392, 3014001, 810149,  1652634, 4686184, 6581310,
    5341501, 3523897, 3866901, 269760,  2213111, 7404533, 1717735, 472078,
    7953734, 1723600, 6577327, 1910376, 6712985, 7276084, 8119771, 4546524,
    5441381, 6144432, 7959518, 6094090, 183443,  7403526, 1612842, 4834730,
    7826001, 3919660, 8332111, 7018208, 3937738, 1400424, 7534263, 1976782
};

#if 0
const int16_t r3_kyb_zetas[128] =
{
    -1044, -758,  -359,  -1517, 1493,  1422,  287,   202,  -171,  622,   1577,
    182,   962,   -1202, -1474, 1468,  573,   -1325, 264,  383,   -829,  1458,
    -1602, -130,  -681,  1017,  732,   608,   -1542, 411,  -205,  -1571, 1223,
    652,   -552,  1015,  -1293, 1491,  -282,  -1544, 516,  -8,    -320,  -666,
    -1618, -1162, 126,   1469,  -853,  -90,   -271,  830,  107,   -1421, -247,
    -951,  -398,  961,   -1508, -725,  448,   -1065, 677,  -1275, -1103, 430,
    555,   843,   -1251, 871,   1550,  105,   422,   587,  177,   -235,  -291,
    -460,  1574,  1653,  -246,  778,   1159,  -147,  -777, 1483,  -602,  1119,
    -1590, 644,   -872,  349,   418,   329,   -156,  -75,  817,   1097,  603,
    610,   1322,  -1285, -1465, 384,   -1215, -136,  1218, -1335, -874,  220,
    -1187, -1659, -1185, -1530, -1278, 794,   -1510, -854, -870,  478,   -108,
    -308,  996,   991,   958,   -1460, 1522,  1628
};
#endif

/* Roots of unity in order needed by inverse ntt */
extern "C"
const uint32_t dil_zetas_inv[DIL_N] =
{
    6403635, 846154,  6979993, 4442679, 1362209, 48306,   4460757, 554416,
    3545687, 6767575, 976891,  8196974, 2286327, 420899,  2235985, 2939036,
    3833893, 260646,  1104333, 1667432, 6470041, 1803090, 6656817, 426683,
    7908339, 6662682, 975884,  6167306, 8110657, 4513516, 4856520, 3038916,
    1799107, 3694233, 6727783, 7570268, 5366416, 6764025, 8217573, 3183426,
    1207385, 8194886, 5011305, 6423145, 164721,  5925962, 5948022, 2013608,
    3776993, 7786281, 3724270, 2584293, 1846953, 1671176, 2831860, 542412,
    4974386, 6144537, 7603226, 6880252, 1374803, 2546312, 6463336, 1279661,
    1962642, 5074302, 7067962, 451100,  1430225, 3318210, 7143142, 1333058,
    1050970, 6476982, 6511298, 2994039, 3548272, 5744496, 7129923, 3767016,
    6784443, 5894064, 7132797, 4325093, 7115408, 2590150, 5688936, 5538076,
    8177373, 6644538, 3342277, 4943130, 4272102, 2437823, 8093429, 8038120,
    3595838, 768622,  525098,  3556995, 5173371, 6348669, 3122442, 655327,
    522500,  43260,   1613174, 7884926, 7561383, 7470875, 6521319, 7479715,
    3193378, 1197226, 3759364, 3520352, 4867236, 1235728, 5945978, 8113420,
    3562462, 2446433, 6136326, 3342478, 4562441, 6063917, 4972711, 6288750,
    4540456, 3628969, 3881060, 3019102, 1439742, 812732,  1584928, 7094748,
    7039087, 7064828, 177440,  2409325, 1851402, 5220671, 3553272, 8190869,
    1316856, 7620448, 210977,  5991061, 3249728, 6727353, 8578,    3724342,
    4421799, 7475901, 1100098, 8336129, 5282425, 7871466, 8115473, 3343383,
    1430430, 6527646, 7031341, 381987,  1308169, 22981,   1228525, 671102,
    2477047, 411027,  3693493, 2967645, 5665122, 6232521, 983419,  4968207,
    8253495, 3632928, 3157330, 3190144, 1000202, 4083598, 6441103, 1257611,
    1585221, 6203962, 4904467, 1452451, 3041255, 3677745, 1528703, 3930395,
    2797779, 6308525, 2556880, 4479693, 4499374, 7426187, 7849063, 7568473,
    4680821, 1600420, 2140649, 4873154, 3821735, 4874723, 1643818, 1699267,
    539299,  6031717, 300467,  4840449, 2867647, 4805995, 3043716, 3861115,
    4464978, 2537516, 3592148, 1661693, 4849980, 5303092, 8284641, 5674394,
    8100412, 4369920, 19422,   6623180, 3277672, 1399561, 3859737, 2118186,
    2108549, 5760665, 1119584, 549488,  4794489, 1079900, 7356305, 5654953,
    5700314, 5268920, 2884855, 5260684, 2091905, 359251,  6026966, 6554070,
    7913949, 876248,  777960,  8143293, 518909,  2608894, 8354570
};

extern "C"
const uint8_t mldsa_ds_pure[2] = {0x0, 0x0};

/*************************************************
 * Description: Forward NTT, in-place. No modular reduction is performed after
 *              additions or subtractions. If input coefficients are below 2*Q,
 *              then output coefficients are below 18*Q.
 *              Output vector is in bitreversed order.
 * Arguments:   - uint32_t p[N]: input/output coefficient array
 **************************************************/
CRS_STATIC void          ntt256(uint32_t p[DIL_N])
{
    unsigned int len, start, j, k;
    uint32_t     zeta, t;

    k = 1;

    const uint32_t* dil_zetas_p;

    // In secureROM context dil_zetas won't correctly point to the data
    // So we must do this in order to use it
    #if defined EMULATE_HW || defined __HOSTBOOT_MODULE
    dil_zetas_p = dil_zetas;
    #else
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                    "sub  %0,2,%0 \n\t" // because subi does not work
                    "addi %0,%0,(dil_zetas-0x8000)@l" : "=r" (dil_zetas_p) );
    #endif

    for (len = 128; len > 0; len >>= 1)
    {
        for (start = 0; start < DIL_N; start = j + len)
        {
            zeta = dil_zetas_p[k++];

            for (j = start; j < start + len; ++j)
            {
                t          = dil_montg_reduce((uint64_t)zeta * p[j + len]);
                p[j + len] = p[j] + 2 * DIL_Q - t;
                p[j]       = p[j] + t;
            }
        }
    }
}

/*************************************************
 * Description: Inverse NTT and multiplication by Montgomery factor 2^32.
 *              In-place. No modular reductions after additions or
 *              subtractions. Input coefficient need to be smaller than 2*Q.
 *              Output coefficient are smaller than 2*Q.
 * Arguments:   - uint32_t p[N]: input/output coefficient array
 **************************************************/
CRS_STATIC void invntt_tomont256(uint32_t p[DIL_N])
{
    unsigned int   start, len, j, k;
    uint32_t       t, zeta;
    const uint32_t f =
        (((uint64_t)DIL_MONT * DIL_MONT % DIL_Q) * (DIL_Q - 1) % DIL_Q) *
        ((DIL_Q - 1) >> 8) % DIL_Q;

    k = 0;

    const uint32_t* dil_zetas_inv_p;

    // In secureROM context dil_zetas_inv won't correctly point to the data
    // So we must do this in order to use it
    #if defined EMULATE_HW || defined __HOSTBOOT_MODULE
    dil_zetas_inv_p = dil_zetas_inv;
    #else
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                    "sub  %0,2,%0 \n\t" // because subi does not work
                    "addi %0,%0,(dil_zetas_inv-0x8000)@l" : "=r" (dil_zetas_inv_p) );
    #endif

    for (len = 1; len < DIL_N; len <<= 1)
    {
        for (start = 0; start < DIL_N; start = j + len)
        {
            zeta = dil_zetas_inv_p[k++];

            for (j = start; j < start + len; ++j)
            {
                t = p[j];

                p[j]       = t + p[j + len];
                p[j + len] = t + 256 * DIL_Q - p[j + len];
                p[j + len] = dil_montg_reduce((uint64_t)zeta * p[j + len]);
            }
        }
    }

    for (j = 0; j < DIL_N; ++j)
    {
        p[j] = dil_montg_reduce((uint64_t)f * p[j]);
    }
}

/*-----  round3 NTT  -------------------------------------------------------*/
extern "C"
const int32_t s_zetas[DIL_N] =
{
    0,        25847,    -2608894, -518909,  237124,   -777960,  -876248,
    466468,   1826347,  2353451,  -359251,  -2091905, 3119733,  -2884855,
    3111497,  2680103,  2725464,  1024112,  -1079900, 3585928,  -549488,
    -1119584, 2619752,  -2108549, -2118186, -3859737, -1399561, -3277672,
    1757237,  -19422,   4010497,  280005,   2706023,  95776,    3077325,
    3530437,  -1661693, -3592148, -2537516, 3915439,  -3861115, -3043716,
    3574422,  -2867647, 3539968,  -300467,  2348700,  -539299,  -1699267,
    -1643818, 3505694,  -3821735, 3507263,  -2140649, -1600420, 3699596,
    811944,   531354,   954230,   3881043,  3900724,  -2556880, 2071892,
    -2797779, -3930395, -1528703, -3677745, -3041255, -1452451, 3475950,
    2176455,  -1585221, -1257611, 1939314,  -4083598, -1000202, -3190144,
    -3157330, -3632928, 126922,   3412210,  -983419,  2147896,  2715295,
    -2967645, -3693493, -411027,  -2477047, -671102,  -1228525, -22981,
    -1308169, -381987,  1349076,  1852771,  -1430430, -3343383, 264944,
    508951,   3097992,  44288,    -1100098, 904516,   3958618,  -3724342,
    -8578,    1653064,  -3249728, 2389356,  -210977,  759969,   -1316856,
    189548,   -3553272, 3159746,  -1851402, -2409325, -177440,  1315589,
    1341330,  1285669,  -1584928, -812732,  -1439742, -3019102, -3881060,
    -3628969, 3839961,  2091667,  3407706,  2316500,  3817976,  -3342478,
    2244091,  -2446433, -3562462, 266997,   2434439,  -1235728, 3513181,
    -3520352, -3759364, -1197226, -3193378, 900702,   1859098,  909542,
    819034,   495491,   -1613174, -43260,   -522500,  -655327,  -3122442,
    2031748,  3207046,  -3556995, -525098,  -768622,  -3595838, 342297,
    286988,   -2437823, 4108315,  3437287,  -3342277, 1735879,  203044,
    2842341,  2691481,  -2590150, 1265009,  4055324,  1247620,  2486353,
    1595974,  -3767016, 1250494,  2635921,  -3548272, -2994039, 1869119,
    1903435,  -1050970, -1333058, 1237275,  -3318210, -1430225, -451100,
    1312455,  3306115,  -1962642, -1279661, 1917081,  -2546312, -1374803,
    1500165,  777191,   2235880,  3406031,  -542412,  -2831860, -1671176,
    -1846953, -2584293, -3724270, 594136,   -3776993, -2013608, 2432395,
    2454455,  -164721,  1957272,  3369112,  185531,   -1207385, -3183426,
    162844,   1616392,  3014001,  810149,   1652634,  -3694233, -1799107,
    -3038916, 3523897,  3866901,  269760,   2213111,  -975884,  1717735,
    472078,   -426683,  1723600,  -1803090, 1910376,  -1667432, -1104333,
    -260646,  -3833893, -2939036, -2235985, -420899,  -2286327, 183443,
    -976891,  1612842,  -3545687, -554416,  3919660,  -48306,   -1362209,
    3937738,  1400424,  -846154,  1976782
};

/*************************************************
 * signed (r3 ref.) counterpart of ntt256()
 *
 * Description: Forward NTT, in-place. No modular reduction is performed after
 *              additions or subtractions. Output vector is in bitreversed
 *order. Arguments:   - uint32_t p[N]: input/output coefficient array
 **************************************************/
CRS_STATIC void sntt256(int32_t a[DIL_N])
{
    unsigned int len, start, j, k = 0;
    int32_t      zeta, t;

    const int32_t* s_zetas_p;

    // In secureROM context s_zetas won't correctly point to the data
    // So we must do this in order to use it
    #if defined EMULATE_HW || defined __HOSTBOOT_MODULE
    s_zetas_p = s_zetas;
    #else
    // In securerom we must do this in order for const arrays to work
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                    "sub  %0,2,%0 \n\t" // because subi does not work
                    "addi %0,%0,(s_zetas-0x8000)@l" : "=r" (s_zetas_p) );
    #endif

    for (len = 128; len > 0; len >>= 1)
    {
        for (start = 0; start < DIL_N; start = j + len)
        {
            zeta = s_zetas_p[++k];

            for (j = start; j < start + len; ++j)
            {
                t = montgomery_s_reduce((int64_t)zeta * a[j + len]);

                a[j + len] = a[j] - t;

                a[j] = a[j] + t;
            }
        }
    }
}

/*************************************************
 * signed (r3 ref.) counterpart of invntt_tomont256()
 *
 * Description: Inverse NTT and multiplication by Montgomery factor 2^32.
 *              In-place. No modular reductions after additions or
 *              subtractions; input coefficients need to be smaller than
 *              Q in absolute value. Output coefficient are smaller than Q in
 *              absolute value.
 * Arguments:   - uint32_t p[N]: input/output coefficient array
 **************************************************/
CRS_STATIC void invntt_s_tomont256(int32_t a[DIL_N])
{
    int32_t      f = 41978; /* mont^2/256 */
    unsigned int start, len, j, k;
    int32_t      t, zeta;

    k = 256;

    const int32_t* s_zetas_p;

    // In secureROM context s_zetas won't correctly point to the data
    // So we must do this in order to use it
    #if defined EMULATE_HW || defined __HOSTBOOT_MODULE
    s_zetas_p = s_zetas;
    #else
    // In securerom we must do this in order for const arrays to work
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                    "sub  %0,2,%0 \n\t" // because subi does not work
                    "addi %0,%0,(s_zetas-0x8000)@l" : "=r" (s_zetas_p) );
    #endif

    for (len = 1; len < DIL_N; len <<= 1)
    {
        for (start = 0; start < DIL_N; start = j + len)
        {
            zeta = -s_zetas_p[--k];

            for (j = start; j < start + len; ++j)
            {
                t = a[j];

                a[j] = t + a[j + len];

                a[j + len] = t - a[j + len];

                a[j + len] = montgomery_s_reduce((int64_t)zeta * a[j + len]);
            }
        }
    }

    for (j = 0; j < DIL_N; ++j)
    {
        a[j] = montgomery_s_reduce((int64_t)f * a[j]);
    }
}

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*  Kyber  */

CRS_STATIC const uint16_t kyb_zetas[128] =
{
    2285, 2571, 2970, 1812, 1493, 1422, 287,  202,  3158, 622,  1577, 182,
    962,  2127, 1855, 1468, 573,  2004, 264,  383,  2500, 1458, 1727, 3199,
    2648, 1017, 732,  608,  1787, 411,  3124, 1758, 1223, 652,  2777, 1015,
    2036, 1491, 3047, 1785, 516,  3321, 3009, 2663, 1711, 2167, 126,  1469,
    2476, 3239, 3058, 830,  107,  1908, 3082, 2378, 2931, 961,  1821, 2604,
    448,  2264, 677,  2054, 2226, 430,  555,  843,  2078, 871,  1550, 105,
    422,  587,  177,  3094, 3038, 2869, 1574, 1653, 3083, 778,  1159, 3182,
    2552, 1483, 2727, 1119, 1739, 644,  2457, 349,  418,  329,  3173, 3254,
    817,  1097, 603,  610,  1322, 2044, 1864, 384,  2114, 3193, 1218, 1994,
    2455, 220,  2142, 1670, 2144, 1799, 2051, 794,  1819, 2475, 2459, 478,
    3221, 3021, 996,  991,  958,  1869, 1522, 1628
};

CRS_STATIC const uint16_t kyb_zetas_inv[128] =
{
    1701, 1807, 1460, 2371, 2338, 2333, 308,  108,  2851, 870,  854,  1510,
    2535, 1278, 1530, 1185, 1659, 1187, 3109, 874,  1335, 2111, 136,  1215,
    2945, 1465, 1285, 2007, 2719, 2726, 2232, 2512, 75,   156,  3000, 2911,
    2980, 872,  2685, 1590, 2210, 602,  1846, 777,  147,  2170, 2551, 246,
    1676, 1755, 460,  291,  235,  3152, 2742, 2907, 3224, 1779, 2458, 1251,
    2486, 2774, 2899, 1103, 1275, 2652, 1065, 2881, 725,  1508, 2368, 398,
    951,  247,  1421, 3222, 2499, 271,  90,   853,  1860, 3203, 1162, 1618,
    666,  320,  8,    2813, 1544, 282,  1838, 1293, 2314, 552,  2677, 2106,
    1571, 205,  2918, 1542, 2721, 2597, 2312, 681,  130,  1602, 1871, 829,
    2946, 3065, 1325, 2756, 1861, 1474, 1202, 2367, 3147, 1752, 2707, 171,
    3127, 3042, 1907, 1836, 1517, 359,  758,  1441
};

/*************************************************
 * Description: Multiplication followed by Montgomery reduction
 *
 * Arguments:   - int16_t a: first factor
 *              - int16_t b: second factor
 *
 * Returns 16-bit integer congruent to a*b*R^{-1} mod q
 **************************************************/
CRS_STATIC int16_t kyb__fqmul(int16_t a, int16_t b)
{
    return kyb__montg_reduce((int32_t)a * b);
}

CRS_STATIC int16_t r3_kyb__fqmul(int16_t a, int16_t b)
{
    return r3_kyb__montg_reduce((int32_t)a * b);
}

/*************************************************
 * Name:        ntt
 *
 * Description: Inplace number-theoretic transform (NTT) in Rq
 *              input is in standard order, output is in bitreversed order
 *
 * Arguments:   - int16_t r[256]: pointer to input/output vector of elements
 *                                of Zq
 **************************************************/
CRS_STATIC void kyb__ntt256(int16_t r[256])
{
    unsigned int len, start, j, k;
    int16_t      t, zeta;

    k = 1;

    for (len = 128; len >= 2; len >>= 1)
    {
        for (start = 0; start < 256; start = j + len)
        {
            zeta = kyb_zetas[k++];

            for (j = start; j < start + len; ++j)
            {
                t = kyb__fqmul(zeta, r[j + len]);

                r[j + len] = r[j] - t;
                r[j]       = r[j] + t;
            }
        }
    }
}

CRS_STATIC void r3_kyb__ntt256(int16_t r[256])
{
    unsigned int len, start, j, k;
    int16_t      t, zeta;

    k = 1;

    for (len = 128; len >= 2; len >>= 1)
    {
        for (start = 0; start < 256; start = j + len)
        {
            zeta = r3_kyb_zetas[k++];

            for (j = start; j < start + len; j++)
            {
                t = r3_kyb__fqmul(zeta, r[j + len]);

                r[j + len] = r[j] - t;
                r[j]       = r[j] + t;
            }
        }
    }
}

/*************************************************
 * Name:        invntt_tomont
 *
 * Description: Inplace inverse number-theoretic transform in Rq and
 *              multiplication by Montgomery factor 2^16.
 *              Input is in bitreversed order, output is in standard order
 *
 * Arguments:   - int16_t r[256]: pointer to input/output vector of elements
 *                                of Zq
 **************************************************/
CRS_STATIC void kyb__invntt256(int16_t r[256])
{
    unsigned int start, len, j, k;
    int16_t      t, zeta;

    k = 0;

    for (len = 2; len <= 128; len <<= 1)
    {
        for (start = 0; start < 256; start = j + len)
        {
            zeta = kyb_zetas_inv[k++];

            for (j = start; j < start + len; ++j)
            {
                t = r[j];

                r[j] = kyb__barrett_reduce(t + r[j + len]);

                r[j + len] = t - r[j + len];

                r[j + len] = kyb__fqmul(zeta, r[j + len]);
            }
        }
    }

    for (j = 0; j < 256; ++j)
    {
        r[j] = kyb__fqmul(r[j], kyb_zetas_inv[127]);
    }
}

CRS_STATIC void r3_kyb__invntt256(int16_t r[256])
{
    unsigned int  start, len, j, k;
    int16_t       t, zeta;
    const int16_t f = 1441;   // mont^2/128

    k = 127;

    for (len = 2; len <= 128; len <<= 1)
    {
        for (start = 0; start < 256; start = j + len)
        {
            zeta = r3_kyb_zetas[k--];

            for (j = start; j < start + len; j++)
            {
                t          = r[j];
                r[j]       = r3_kyb__barrett_reduce(t + r[j + len]);
                r[j + len] = r[j + len] - t;
                r[j + len] = r3_kyb__fqmul(zeta, r[j + len]);
            }
        }
    }

    for (j = 0; j < 256; j++)
    {
        r[j] = r3_kyb__fqmul(r[j], f);
    }
}

/*************************************************
 * Description: Multiplication of polynomials in Zq[X]/(X^2-zeta)
 *              used for multiplication of elements in Rq in NTT domain
 *
 * Arguments:   - int16_t r[2]:       pointer to the output polynomial
 *              - const int16_t a[2]: pointer to the first factor
 *              - const int16_t b[2]: pointer to the second factor
 *              - int16_t zeta:       integer defining the reduction polynomial
 **************************************************/
CRS_STATIC void kyb__basemul(int16_t r[2], const int16_t a[2],
                             const int16_t b[2], int16_t zeta)
{
    r[0] = kyb__fqmul(a[1], b[1]);
    r[0] = kyb__fqmul(r[0], zeta);
    r[0] += kyb__fqmul(a[0], b[0]);

    r[1] = kyb__fqmul(a[0], b[1]);
    r[1] += kyb__fqmul(a[1], b[0]);
}

CRS_STATIC void r3_kyb__basemul(int16_t r[2], const int16_t a[2],
                                const int16_t b[2], int16_t zeta)
{
    r[0] = r3_kyb__fqmul(a[1], b[1]);
    r[0] = r3_kyb__fqmul(r[0], zeta);
    r[0] += r3_kyb__fqmul(a[0], b[0]);

    r[1] = r3_kyb__fqmul(a[0], b[1]);
    r[1] += r3_kyb__fqmul(a[1], b[0]);
}
#endif /*-----  /Kyber  -----------------------------*/
#endif /*-----  /delimiter: NTT  --------------------------------------*/

#if 1 /*-----  delimiter: rounding  ----------------------------------*/
/*************************************************
 * Description: For finite field element a, compute a0, a1 such that
 *              a mod Q = a1*2^D + a0 with -2^{D-1} < a0 <= 2^{D-1}.
 *              Assumes a to be standard representative.
 *
 * Arguments:   - uint32_t a: input element
 *              - uint32_t *a0: pointer to output element Q + a0
 *
 * Returns a1.
 **************************************************/
CRS_STATIC uint32_t power2round(uint32_t a, uint32_t* a0)
{
    int32_t t;

    /* Centralized remainder mod 2^D */
    t = a & ((1U << DIL_D) - 1);
    t -= (1U << (DIL_D - 1)) + 1;
    t += (t >> 31) & (1U << DIL_D);
    t -= (1U << (DIL_D - 1)) - 1;

    *a0 = DIL_Q + t;
    a   = (a - t) >> DIL_D;

    return a;
}

/*--------------------------------------
 * signed (r3 ref.) counterpart of power2round()
 */
CRS_STATIC int32_t spower2round(int32_t* a0, int32_t a)
{
    int32_t a1;

    a1  = (a + (1 << (DIL_SD - 1)) - 1) >> DIL_SD;
    *a0 = a - (a1 << DIL_SD);

    return a1;
}

/*************************************************
 * Description: For finite field element a, compute high and low bits a0, a1
 *such that a mod Q = a1*ALPHA + a0 with -ALPHA/2 < a0 <= ALPHA/2 except if a1 =
 *(Q-1)/ALPHA where we set a1 = 0 and -ALPHA/2 <= a0 = a mod Q - Q < 0. Assumes
 *a to be standard representative. Arguments:   - uint32_t a: input element
 *              - uint32_t *a0: pointer to output element Q + a0
 * Returns a1.
 **************************************************/
CRS_STATIC uint32_t decompose(uint32_t a, uint32_t* a0)
{
#if DIL_ALPHA != (DIL_Q - 1) / 16
#error "decompose assumes ALPHA == (Q-1)/16"
#endif
    int32_t t, u;

    /* Centralized remainder mod ALPHA */
    t = a & 0x7FFFF;
    t += (a >> 19) << 9;
    t -= DIL_ALPHA / 2 + 1;
    t += (t >> 31) & DIL_ALPHA;
    t -= DIL_ALPHA / 2 - 1;
    a -= t;

    /* Divide by ALPHA (possible to avoid) */
    u = a - 1;
    u >>= 31;
    a = (a >> 19) + 1;
    a -= u & 1;

    /* Border case */
    *a0 = DIL_Q + t - (a >> 4);
    a &= 0xF;

    return a;
}

/*--------------------------------------
 * expanded form of GAMMA1, replacing ref.impl. #define
 * returns 0 for unknown param sets (which SNH)
 *
 * assume inlining/const-propagation on any reasonable platform
 */
ATTR_CONST__
/**/
CRS_STATIC int32_t dil_r3k2gamma1(unsigned int k)
{
    switch (k)
    {
        case 4:
            return (1 << 17);

        case 6:
        case 8:
            return (1 << 19);

        default:
            return 0;
    }
}

/*--------------------------------------
 * expanded form of GAMMA2, replacing ref.impl. #define
 * returns 0 for unknown param sets (which SNH)
 *
 * assume inlining/const-propagation on any reasonable platform
 */
ATTR_CONST__
/**/
CRS_STATIC int32_t dil_r3k2gamma2(unsigned int k)
{
    switch (k)
    {
        case 4:
            return 95232; /* (DIL_Q -1) /88 */

        case 6:
        case 8:
            return 261888; /* (DIL_Q -1) /32 */

        default:
            return 0;
    }
}

/*--------------------------------------
 * expanded form of POLYZ_PACKEDBYTES, replacing ref.impl. #define
 * returns 0 for unknown param sets (which SNH)
 *
 * assume inlining/const-propagation on any reasonable platform
 */
ATTR_CONST__
/**/
CRS_STATIC size_t dil_r3k2polyz_bytes(unsigned int k)
{
    switch (k)
    {
        case 4:
            return 576;

        case 6:
        case 8:
            return 640;

        default:
            return 0;
    }
}

/*--------------------------------------
 * expanded form of POLYW1_PACKEDBYTES, replacing ref.impl. #define
 * returns 0 for unknown param sets (which SNH)
 *
 * assume inlining/const-propagation on any reasonable platform
 */
ATTR_CONST__
/**/
CRS_STATIC size_t dil_r3k2polyw1_bytes(unsigned int k)
{
    switch (k)
    {
        case 4:
            return 192;

        case 6:
        case 8:
            return 128;

        default:
            return 0;
    }
}
/*
 * verification needs max(K * w1-bytes) as an upper limit, this is it:
 */
#define DIL__KxPOLYW1_MAX_BYTES ((size_t)1024)

#if 0
/*--------------------------------------
 * expanded form of POLYETA_PACKEDBYTES, replacing ref.impl. #define
 * returns 0 for unknown param sets (which SNH)
 *
 * assume inlining/const-propagation on any reasonable platform
 */
ATTR_CONST__
/**/
CRS_STATIC size_t dil_r3k2polyeta_bytes(unsigned int k)
{
    switch (k)
    {
        case 4:
        case 8:
            return 96; /* ETA=2 cases */

        case 6:
            return 128; /* ETA=4 */

        default:
            return 0;
    }
}
#endif

/*--------------------------------------
 * expanded form of POLYETA_PACKEDBYTES, replacing ref.impl. #define
 * returns 0 for unknown param sets (which SNH)
 *
 * assume inlining/const-propagation on any reasonable platform
 */
ATTR_CONST__
/**/
CRS_STATIC size_t dil_mldsa_ctilbytes(unsigned int k)
{
    if (k == 4)
    {
        return DIL_MLDSA_44_CTILDEBYTES;
    }
    if (k == 6)
    {
        return DIL_MLDSA_65_CTILDEBYTES;
    }
    if (k == 8)
    {
        return DIL_MLDSA_87_CTILDEBYTES;
    }
    return 0;
}

/*--------------------------------------
 * signed (r3 ref.) counterpart of decompose()
 */
CRS_STATIC int32_t s_decompose(int32_t* a0, int32_t a, unsigned int dil_k)
{
    int32_t a1;

    a1 = (a + 127) >> 7;

    /* original condition: GAMMA2 == (DIL_Q-1) /32
     *   -> Dil3 (6x5), Dil5 (8x7)
     */
    if (dil_k != 4)
    {
        a1 = (a1 * 1025 + (1 << 21)) >> 22;
        a1 &= 15;

        /* original condition: GAMMA2 == (DIL_Q-1) /88
         *   -> Dil2 (4x4)
         */
    }
    else
    {
        a1 = (a1 * 11275 + (1 << 23)) >> 24;
        a1 ^= ((43 - a1) >> 31) & a1;
    }

    *a0 = a - a1 * 2 * dil_r3k2gamma2(dil_k); /* was: * GAMMA2; */

    *a0 -= (((DIL_Q - 1) / 2 - *a0) >> 31) & DIL_Q;

    return a1;
}

/*************************************************
 * Description: Compute hint bit indicating whether the low bits of the
 *              input element overflow into the high bits. Inputs assumed to be
 *              standard representatives.
 *
 * Arguments:   - uint32_t a0: low bits of input element
 *              - uint32_t a1: high bits of input element
 *
 * Returns 1 if high bits of a and b differ and 0 otherwise.
 **************************************************/
CRS_STATIC unsigned int make_hint(uint32_t a0, uint32_t a1)
{
    if ((a0 <= DIL_GAMMA2) || (a0 > DIL_Q - DIL_GAMMA2) ||
        ((a0 == DIL_Q - DIL_GAMMA2) && !a1))
    {
        return 0;
    }

    return 1;
}

/*--------------------------------------
 * signed (r3 ref.) counterpart of sdecompose()
 */
ATTR_CONST__
/**/
CRS_STATIC unsigned int make_s_hint(int32_t a0, int32_t a1, unsigned int dil_k)
{
    int32_t gamma2 = dil_r3k2gamma2(dil_k);

    /*
     * expect const. propagation to eliminate
     * even this variable
     */
    if ((a0 > gamma2) || (a0 < -gamma2) || ((a0 == -gamma2) && (a1 != 0)))
    {
        return 1;
    }

    /* round3.0 -> round3 changed expression */

    return 0;
}

/*************************************************
 * Description: Correct high bits according to hint.
 *
 * Arguments:   - uint32_t a: input element
 *              - unsigned int hint: hint bit
 *
 * Returns corrected high bits.
 **************************************************/
CRS_STATIC uint32_t use_hint(uint32_t a, unsigned int hint)
{
    uint32_t a0, a1;

    a1 = decompose(a, &a0);

    if (!hint)
    {
        return a1;
    }
    else if (a0 > DIL_Q)
    {
        return (a1 + 1) & 0xF;
    }
    else
    {
        return (a1 - 1) & 0xF;
    }
}

/*--------------------------------------
 * signed (r3 ref.) counterpart of use_hint()
 */
CRS_STATIC int32_t use_s_hint(int32_t a, unsigned int hint, unsigned int dil_k)
{
    int32_t a0, a1;

    a1 = s_decompose(&a0, a, dil_k);

    if (hint == 0)
    {
        return a1;
    }

    /* original condition: GAMMA2 == (DIL_Q-1) /32
     *   -> Dil3 (6x5), Dil5 (8x7)
     */
    if (dil_k != 4)
    {
        if (a0 > 0)
        {
            return (a1 + 1) & 15;
        }
        else
        {
            return (a1 - 1) & 15;
        }

        /* original condition: GAMMA2 == (DIL_Q-1) /88
         *   -> Dil2 (4x4)
         */
    }
    else
    {
        if (a0 > 0)
        {
            return (a1 == 43) ? 0 : a1 + 1;
        }
        else
        {
            return (a1 == 0) ? 43 : a1 - 1;
        }
    }
}

#endif /*-----  /delimiter: rounding  ---------------------------------*/

#if 1 /*-----  delimiter: poly -> symmetric.h  -----------------------*/
CRS_STATIC void shake128_stream_init(Keccak_state* state,
                                     const uint8_t seed[DIL_SEEDBYTES],
                                     uint16_t      nonce)
{
    uint8_t t[2];

    t[0] = nonce;
    t[1] = nonce >> 8;

    shake128_init(state);
    shake128_absorb(state, seed, DIL_SEEDBYTES);
    shake128_absorb(state, t, 2);
    shake128_finalize(state);
}

#if 0
/*------------------------------------*/
CRS_STATIC void shake256_stream_init(Keccak_state* state,
                                     const uint8_t seed[DIL_CRHBYTES],
                                     uint16_t      nonce)
{
    uint8_t t[2];

    t[0] = nonce;
    t[1] = nonce >> 8;

    shake256_init(state);
    shake256_absorb(state, seed, DIL_CRHBYTES);
    shake256_absorb(state, t, 2);
    shake256_finalize(state);
}
#endif

/*------------------------------------
 * round3 dilithium, different field size
 */
CRS_STATIC void shake256_stream_init_dilr3(Keccak_state* state,
        const uint8_t seed[DIL_R3_CRHBYTES],
        uint16_t      nonce)
{
    uint8_t t[2];

    t[0] = nonce;
    t[1] = nonce >> 8;

    shake256_init(state);
    shake256_absorb(state, seed, DIL_R3_CRHBYTES);
    shake256_absorb(state, t, 2);
    shake256_finalize(state);
}

/*----------------------------------*/
#define stream128_squeezeblocks(OUT, OUTBLOCKS, STATE)                         \
    shake128_squeezeblocks(OUT, OUTBLOCKS, STATE)

#define stream256_init(STATE, SEED, NONCE)                                     \
    shake256_stream_init(STATE, SEED, NONCE)

/* r3, different seed size */
#define stream256_init_dilr3(STATE, SEED, NONCE)                               \
    shake256_stream_init_dilr3(STATE, SEED, NONCE)

#define stream256_squeezeblocks(OUT, OUTBLOCKS, STATE)                         \
    shake256_squeezeblocks(OUT, OUTBLOCKS, STATE)

#define stream256_wipe(STATE) shake256_wipe(STATE)

//--------------------------------------
static __INLINE__ size_t dil_crh(unsigned char* res, size_t rbytes,
                                 const unsigned char* seed, size_t sbytes)
{
    shake256(res, rbytes, seed, sbytes);

    return rbytes;
}
#endif /*-----  /delimiter: poly -> symmetric.h  ----------------------*/

#if 1 /*-----  delimiter: poly  --------------------------------------*/
#if !defined(NO_CRYSTALS_SIG)
typedef struct
{
    uint32_t coeffs[DIL_N]; /* round2 */
} poly;

typedef struct
{
    int32_t coeffs[DIL_N]; /* round3 */
} spoly;
#endif

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX)
typedef struct
{
    int16_t coeffs[KYB_N];
} kpoly;
#endif

#if !defined(NO_CRYSTALS_SIG) /*-------------------------------------------*/
/*************************************************
 * Description: Inplace reduction of all coefficients of polynomial to
 *              representative in [0,2*Q[.
 *
 * Arguments:   - poly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void poly_reduce(poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] = reduce32(a->coeffs[i]);
    }
}

/*************************************************
 * Description: For all coefficients of in/out polynomial subtract Q if
 *              coefficient is bigger than Q.
 * Arguments:   - poly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void poly_csubq(poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] = csubq(a->coeffs[i]);
    }
}

/*************************************************
 * Description: Inplace reduction of all coefficients of polynomial to
 *              standard representatives.
 * Arguments:   - poly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void poly_freeze(poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] = freeze(a->coeffs[i]);
    }
}

/*************************************************
 * Description: Add polynomials. No modular reduction is performed.
 * Arguments:   - poly *c: pointer to output polynomial
 *              - const poly *a: pointer to first summand
 *              - const poly *b: pointer to second summand
 **************************************************/
CRS_STATIC void poly_add(poly* c, const poly* a, const poly* b)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = a->coeffs[i] + b->coeffs[i];
    }
}

/*************************************************
 * Description: Subtract polynomials. Assumes coefficients of second input
 *              polynomial to be less than 2*Q. No modular reduction is
 *              performed.
 * Arguments:   - poly *c: pointer to output polynomial
 *              - const poly *a: pointer to first input polynomial
 *              - const poly *b: pointer to second input polynomial to be
 *                               subtraced from first input polynomial
 **************************************************/
CRS_STATIC void poly_sub(poly* c, const poly* a, const poly* b)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = a->coeffs[i] + 2 * DIL_Q - b->coeffs[i];
    }
}

/*************************************************
 * Description: Multiply polynomial by 2^D without modular reduction. Assumes
 *              input coefficients to be less than 2^{32-D}.
 * Arguments:   - poly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void poly_shiftl(poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] <<= DIL_D;
    }
}

/*************************************************
 * Description: Inplace forward NTT. Output coefficients can be up to
 *              16*Q larger than input coefficients.
 *
 * Arguments:   - poly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void poly_ntt256(poly* a)
{
    ntt256(a->coeffs);
}

/*************************************************
 * Name:        poly_invntt_tomont
 *
 * Description: Inplace inverse NTT and multiplication by 2^{32}.
 *              Input coefficients need to be less than 2*Q.
 *              Output coefficients are less than 2*Q.
 *
 * Arguments:   - poly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void poly_invntt_tomont(poly* a)
{
    invntt_tomont256(a->coeffs);
}

/*************************************************
 * Description: Pointwise multiplication of polynomials in NTT domain
 *              representation and multiplication of resulting polynomial
 *              by 2^{-32}. Output coefficients are less than 2*Q if input
 *              coefficient are less than 22*Q.
 *
 * Arguments:   - poly *c: pointer to output polynomial
 *              - const poly *a: pointer to first input polynomial
 *              - const poly *b: pointer to second input polynomial
 **************************************************/
CRS_STATIC void poly_pointwise_montgomery(poly* c, const poly* a, const poly* b)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = dil_montg_reduce((uint64_t)a->coeffs[i] * b->coeffs[i]);
    }
}

/*************************************************
 * Description: For all coefficients c of the input polynomial,
 *              compute c0, c1 such that c mod Q = c1*2^D + c0
 *              with -2^{D-1} < c0 <= 2^{D-1}. Assumes coefficients to be
 *              standard representatives.
 *
 * Arguments:   - poly *a1: pointer to output polynomial with coefficients c1
 *              - poly *a0: pointer to output polynomial with coefficients Q +
 *c0
 *              - const poly *v: pointer to input polynomial
 **************************************************/
CRS_STATIC void poly_power2round(poly* a1, poly* a0, const poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a1->coeffs[i] = power2round(a->coeffs[i], &a0->coeffs[i]);
    }
}

/*************************************************
 * Description: For all coefficients c of the input polynomial,
 *              compute high and low bits c0, c1 such c mod Q = c1*ALPHA + c0
 *              with -ALPHA/2 < c0 <= ALPHA/2 except c1 = (Q-1)/ALPHA where we
 *              set c1 = 0 and -ALPHA/2 <= c0 = c mod Q - Q < 0.
 *              Assumes coefficients to be standard representatives.
 *
 * Arguments:   - poly *a1: pointer to output polynomial with coefficients c1
 *              - poly *a0: pointer to output polynomial with coefficients Q +
 *c0
 *              - const poly *c: pointer to input polynomial
 **************************************************/
CRS_STATIC void poly_decompose(poly* a1, poly* a0, const poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a1->coeffs[i] = decompose(a->coeffs[i], &a0->coeffs[i]);
    }
}

/*************************************************
 * Name:        poly_make_hint
 *
 * Description: Compute hint polynomial. The coefficients of which indicate
 *              whether the low bits of the corresponding coefficient of
 *              the input polynomial overflow into the high bits.
 *
 * Arguments:   - poly *h: pointer to output hint polynomial
 *              - const poly *a0: pointer to low part of input polynomial
 *              - const poly *a1: pointer to high part of input polynomial
 *
 * Returns number of 1 bits.
 **************************************************/
CRS_STATIC unsigned int poly_make_hint(poly* h, const poly* a0, const poly* a1)
{
    unsigned int i, s = 0;

    for (i = 0; i < DIL_N; ++i)
    {
        h->coeffs[i] = make_hint(a0->coeffs[i], a1->coeffs[i]);
        s += h->coeffs[i];
    }

    return s;
}

/*************************************************
 * Name:        poly_use_hint
 *
 * Description: Use hint polynomial to correct the high bits of a polynomial.
 *
 * Arguments:   - poly *b: pointer to output polynomial with corrected high bits
 *              - const poly *a: pointer to input polynomial
 *              - const poly *h: pointer to input hint polynomial
 **************************************************/
CRS_STATIC void poly_use_hint(poly* b, const poly* a, const poly* h)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        b->coeffs[i] = use_hint(a->coeffs[i], h->coeffs[i]);
    }
}

/*************************************************
 * Name:        poly_chknorm
 *
 * Description: Check infinity norm of polynomial against given bound.
 *              Assumes input coefficients to be standard representatives.
 *
 * Arguments:   - const poly *a: pointer to polynomial
 *              - uint32_t B: norm bound
 *
 * Returns 0 if norm is strictly smaller than B and 1 otherwise.
 **************************************************/
ATTR_PURE__
static
/**/
int
poly_chknorm(const poly* a, uint32_t B)
{
    unsigned int i;
    uint32_t     t;

    /* It is ok to leak which coefficient violates the bound since
     the probability for each coefficient is independent of secret
     data but we must not leak sign of the centralized representative. */

    for (i = 0; i < DIL_N; ++i)
    {
        /* Absolute value of centralized representative */

        t = (DIL_Q - 1) / 2 - a->coeffs[i];
        t ^= (int32_t)t >> 31;
        t = (DIL_Q - 1) / 2 - t;

        if (t >= B)
        {
            return 1;
        }
    }

    return 0;
}

/*************************************************
 * Name:        rej_uniform
 *
 * Description: Sample uniformly random coefficients in [0, Q-1] by
 *              performing rejection sampling using array of random bytes.
 *
 * Arguments:   - uint32_t *a: pointer to output array (allocated)
 *              - unsigned int len: number of coefficients to be sampled
 *              - const uint8_t *buf: array of random bytes
 *              - unsigned int buflen: length of array of random bytes
 *
 * Returns number of sampled coefficients. Can be smaller than len if not enough
 * random bytes were given.
 **************************************************/
CRS_STATIC unsigned int rej_uniform(uint32_t* a, unsigned int len,
                                    const uint8_t* buf, unsigned int buflen)
{
    unsigned int ctr = 0, pos = 0;
    uint32_t     t;

    while ((ctr < len) && (pos + 3 <= buflen))
    {
        t = buf[pos++];

        t |= (uint32_t)buf[pos++] << 8;
        t |= (uint32_t)buf[pos++] << 16;

        t &= 0x7FFFFF;

        if (t < DIL_Q)
        {
            a[ctr++] = t;
        }
    }

    return ctr;
}

/*************************************************
 * Name:        poly_uniform
 *
 * Description: Sample polynomial with uniformly random coefficients
 *              in [0,Q-1] by performing rejection sampling using the
 *              output stream of SHAKE256(seed|nonce) or AES256CTR(seed,nonce).
 *
 * Arguments:   - poly *a: pointer to output polynomial
 *              - const uint8_t seed[]: byte array with seed of length SEEDBYTES
 *              - uint16_t nonce: 2-byte nonce
 **************************************************/
#define POLY_UNIFORM_NBLOCKS                                                   \
    ((768 + DIL_STREAM128_BLOCKBYTES - 1) / DIL_STREAM128_BLOCKBYTES)

CRS_STATIC void poly_uniform(poly* a, const uint8_t seed[DIL_SEEDBYTES],
                             uint16_t nonce)
{
    unsigned int    i, ctr, off;
    unsigned int    buflen = POLY_UNIFORM_NBLOCKS * DIL_STREAM128_BLOCKBYTES;
    uint8_t         buf[POLY_UNIFORM_NBLOCKS * DIL_STREAM128_BLOCKBYTES + 2];
    stream128_state state;

    stream128_init(&state, seed, nonce);
    stream128_squeezeblocks(buf, POLY_UNIFORM_NBLOCKS, &state);

    ctr = rej_uniform(a->coeffs, DIL_N, buf, buflen);

    while (ctr < DIL_N)
    {
        off = buflen % 3;

        for (i = 0; i < off; ++i)
        {
            buf[i] = buf[buflen - off + i];
        }

        buflen = DIL_STREAM128_BLOCKBYTES + off;

        stream128_squeezeblocks(buf + off, 1, &state);

        ctr += rej_uniform(a->coeffs + ctr, DIL_N - ctr, buf, buflen);
    }

    stream128_wipe(&state);
}

#if 0
/*************************************************
 * Name:        rej_eta
 *
 * Description: Sample uniformly random coefficients in [-ETA, ETA] by
 *              performing rejection sampling using array of random bytes.
 *
 * Arguments:   - uint32_t *a: pointer to output array (allocated)
 *              - unsigned int len: number of coefficients to be sampled
 *              - const uint8_t *buf: array of random bytes
 *              - unsigned int buflen: length of array of random bytes
 *
 * Returns number of sampled coefficients. Can be smaller than len if not enough
 * random bytes were given.
 **************************************************/
CRS_STATIC unsigned int rej_eta(uint32_t* a, unsigned int len,
                                const uint8_t* buf, unsigned int buflen,
                                unsigned int eta)
{
    unsigned int ctr = 0, pos = 0;
    uint32_t     t0, t1;

    while ((ctr < len) && (pos < buflen))
    {
        if (eta <= 3)
        {
            t0 = buf[pos] & 0x07;
            t1 = buf[pos++] >> 5;
        }
        else
        {
            t0 = buf[pos] & 0x0F;
            t1 = buf[pos++] >> 4;
        }

        if (t0 <= 2 * eta)
        {
            a[ctr++] = DIL_Q + eta - t0;
        }

        if ((t1 <= 2 * eta) && (ctr < len))
        {
            a[ctr++] = DIL_Q + eta - t1;
        }
    }

    return ctr;
}

/*************************************************
 * Description: Sample polynomial with uniformly random coefficients
 *              in [-ETA,ETA] by performing rejection sampling using the
 *              output stream from SHAKE256(seed|nonce) or
 *AES256CTR(seed,nonce).
 *
 * Arguments:   - poly *a: pointer to output polynomial
 *              - const uint8_t seed[]: byte array with seed of length SEEDBYTES
 *              - uint16_t nonce: 2-byte nonce
 **************************************************/
#define POLY_UNIFORM_ETA_NBLOCKS                                               \
    ((192 + DIL_STREAM128_BLOCKBYTES - 1) / DIL_STREAM128_BLOCKBYTES)

CRS_STATIC void poly_uniform_eta(poly* a, const uint8_t seed[DIL_SEEDBYTES],
                                 unsigned int eta, uint16_t nonce)
{
    unsigned int buflen = POLY_UNIFORM_ETA_NBLOCKS * DIL_STREAM128_BLOCKBYTES;
    uint8_t      buf[POLY_UNIFORM_ETA_NBLOCKS * DIL_STREAM128_BLOCKBYTES];
    stream128_state state;
    unsigned int    ctr;

    stream128_init(&state, seed, nonce);
    stream128_squeezeblocks(buf, POLY_UNIFORM_ETA_NBLOCKS, &state);

    ctr = rej_eta(a->coeffs, DIL_N, buf, buflen, eta);

    while (ctr < DIL_N)
    {
        stream128_squeezeblocks(buf, 1, &state);

        ctr += rej_eta(a->coeffs + ctr, DIL_N - ctr, buf,
                       DIL_STREAM128_BLOCKBYTES, eta);
    }

    stream128_wipe(&state);
}

/*************************************************
 * Name:        rej_gamma1m1
 *
 * Description: Sample uniformly random coefficients
 *              in [-(GAMMA1 - 1), GAMMA1 - 1] by performing rejection sampling
 *              using array of random bytes.
 *
 * Arguments:   - uint32_t *a: pointer to output array (allocated)
 *              - unsigned int len: number of coefficients to be sampled
 *              - const uint8_t *buf: array of random bytes
 *              - unsigned int buflen: length of array of random bytes
 *
 * Returns number of sampled coefficients. Can be smaller than len if not enough
 * random bytes were given.
 **************************************************/
CRS_STATIC unsigned int rej_gamma1m1(uint32_t* a, unsigned int len,
                                     const uint8_t* buf, unsigned int buflen)
{
#if DIL_GAMMA1 > (1 << 19)
#error "rej_gamma1m1() assumes GAMMA1 - 1 fits in 19 bits"
#endif
    unsigned int ctr, pos;
    uint32_t     t0, t1;

    ctr = pos = 0;

    while (ctr < len && pos + 5 <= buflen)
    {
        t0 = buf[pos];
        t0 |= (uint32_t)buf[pos + 1] << 8;
        t0 |= (uint32_t)buf[pos + 2] << 16;
        t0 &= 0xFFFFF;

        t1 = buf[pos + 2] >> 4;
        t1 |= (uint32_t)buf[pos + 3] << 4;
        t1 |= (uint32_t)buf[pos + 4] << 12;

        pos += 5;

        if (t0 <= 2 * DIL_GAMMA1 - 2)
        {
            a[ctr++] = DIL_Q + DIL_GAMMA1 - 1 - t0;
        }

        if (t1 <= 2 * DIL_GAMMA1 - 2 && ctr < len)
        {
            a[ctr++] = DIL_Q + DIL_GAMMA1 - 1 - t1;
        }
    }

    return ctr;
}

/*************************************************
 * Name:        poly_uniform_gamma1m1
 *
 * Description: Sample polynomial with uniformly random coefficients
 *              in [-(GAMMA1 - 1), GAMMA1 - 1] by performing rejection
 *              sampling on output stream of SHAKE256(seed|nonce)
 *              or AES256CTR(seed,nonce).
 *
 * Arguments:   - poly *a: pointer to output polynomial
 *              - const uint8_t seed[]: byte array with seed of length CRHBYTES
 *              - uint16_t nonce: 16-bit nonce
 **************************************************/
#define POLY_UNIFORM_GAMMA1M1_NBLOCKS                                          \
    ((640 + DIL_STREAM256_BLOCKBYTES - 1) / DIL_STREAM256_BLOCKBYTES)

CRS_STATIC void poly_uniform_gamma1m1(poly* a, const uint8_t seed[DIL_CRHBYTES],
                                      uint16_t nonce)
{
    unsigned int i, ctr, off;
    unsigned int buflen =
        POLY_UNIFORM_GAMMA1M1_NBLOCKS * DIL_STREAM256_BLOCKBYTES;
    uint8_t buf[POLY_UNIFORM_GAMMA1M1_NBLOCKS * DIL_STREAM256_BLOCKBYTES + 4];
    stream256_state state;

    stream256_init(&state, seed, nonce);
    stream256_squeezeblocks(buf, POLY_UNIFORM_GAMMA1M1_NBLOCKS, &state);

    ctr = rej_gamma1m1(a->coeffs, DIL_N, buf, buflen);

    while (ctr < DIL_N)
    {
        off = buflen % 5;

        for (i = 0; i < off; ++i)
        {
            buf[i] = buf[buflen - off + i];
        }

        buflen = DIL_STREAM256_BLOCKBYTES + off;

        stream256_squeezeblocks(buf + off, 1, &state);

        ctr += rej_gamma1m1(a->coeffs + ctr, DIL_N - ctr, buf, buflen);
    }

    stream256_wipe(&state);
}
#endif

/*************************************************
 * Description: Bit-pack polynomial with coefficients in [-ETA,ETA].
 *              Input coefficients are assumed to lie in [Q-ETA,Q+ETA].
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLETA_SIZE_PACKED bytes
 *              - const poly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void polyeta_pack(uint8_t* r, const poly* a, unsigned int eta)
{
    unsigned int i;
    uint8_t      t[8];

    if (2 * eta <= 7)
    {
        for (i = 0; i < DIL_N / 8; ++i)
        {
            t[0] = DIL_Q + eta - a->coeffs[8 * i + 0];
            t[1] = DIL_Q + eta - a->coeffs[8 * i + 1];
            t[2] = DIL_Q + eta - a->coeffs[8 * i + 2];
            t[3] = DIL_Q + eta - a->coeffs[8 * i + 3];
            t[4] = DIL_Q + eta - a->coeffs[8 * i + 4];
            t[5] = DIL_Q + eta - a->coeffs[8 * i + 5];
            t[6] = DIL_Q + eta - a->coeffs[8 * i + 6];
            t[7] = DIL_Q + eta - a->coeffs[8 * i + 7];

            r[3 * i + 0] = (t[0] >> 0) | (t[1] << 3) | (t[2] << 6);
            r[3 * i + 1] =
                (t[2] >> 2) | (t[3] << 1) | (t[4] << 4) | (t[5] << 7);
            r[3 * i + 2] = (t[5] >> 1) | (t[6] << 2) | (t[7] << 5);
        }
    }
    else
    {
        for (i = 0; i < DIL_N / 2; ++i)
        {
            t[0] = DIL_Q + eta - a->coeffs[2 * i + 0];
            t[1] = DIL_Q + eta - a->coeffs[2 * i + 1];
            r[i] = t[0] | (t[1] << 4);
        }
    }
}

/*************************************************
 * Name:        polyeta_unpack
 *
 * Description: Unpack polynomial with coefficients in [-ETA,ETA].
 *              Output coefficients lie in [Q-ETA,Q+ETA].
 *
 * Arguments:   - poly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void polyeta_unpack(poly* r, const uint8_t* a, unsigned int eta)
{
    unsigned int i;

    if (eta <= 3)
    {
        for (i = 0; i < DIL_N / 8; ++i)
        {
            r->coeffs[8 * i + 0] = a[3 * i + 0] & 0x07;
            r->coeffs[8 * i + 1] = (a[3 * i + 0] >> 3) & 0x07;
            r->coeffs[8 * i + 2] =
                ((a[3 * i + 0] >> 6) | (a[3 * i + 1] << 2)) & 0x07;
            r->coeffs[8 * i + 3] = (a[3 * i + 1] >> 1) & 0x07;
            r->coeffs[8 * i + 4] = (a[3 * i + 1] >> 4) & 0x07;
            r->coeffs[8 * i + 5] =
                ((a[3 * i + 1] >> 7) | (a[3 * i + 2] << 1)) & 0x07;
            r->coeffs[8 * i + 6] = (a[3 * i + 2] >> 2) & 0x07;
            r->coeffs[8 * i + 7] = (a[3 * i + 2] >> 5) & 0x07;

            r->coeffs[8 * i + 0] = DIL_Q + eta - r->coeffs[8 * i + 0];
            r->coeffs[8 * i + 1] = DIL_Q + eta - r->coeffs[8 * i + 1];
            r->coeffs[8 * i + 2] = DIL_Q + eta - r->coeffs[8 * i + 2];
            r->coeffs[8 * i + 3] = DIL_Q + eta - r->coeffs[8 * i + 3];
            r->coeffs[8 * i + 4] = DIL_Q + eta - r->coeffs[8 * i + 4];
            r->coeffs[8 * i + 5] = DIL_Q + eta - r->coeffs[8 * i + 5];
            r->coeffs[8 * i + 6] = DIL_Q + eta - r->coeffs[8 * i + 6];
            r->coeffs[8 * i + 7] = DIL_Q + eta - r->coeffs[8 * i + 7];
        }
    }
    else
    {
        for (i = 0; i < DIL_N / 2; ++i)
        {
            r->coeffs[2 * i + 0] = a[i] & 0x0F;
            r->coeffs[2 * i + 1] = a[i] >> 4;

            r->coeffs[2 * i + 0] = DIL_Q + eta - r->coeffs[2 * i + 0];
            r->coeffs[2 * i + 1] = DIL_Q + eta - r->coeffs[2 * i + 1];
        }
    }
}

/*************************************************
 * Name:        polyt1_pack
 *
 * Description: Bit-pack polynomial t1 with coefficients fitting in 9 bits.
 *              Input coefficients are assumed to be standard representatives.
 *
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLT1_SIZE_PACKED bytes
 *              - const poly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void polyt1_pack(uint8_t* r, const poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 8; ++i)
    {
        r[9 * i + 0] = (a->coeffs[8 * i + 0] >> 0);
        r[9 * i + 1] =
            (a->coeffs[8 * i + 0] >> 8) | (a->coeffs[8 * i + 1] << 1);
        r[9 * i + 2] =
            (a->coeffs[8 * i + 1] >> 7) | (a->coeffs[8 * i + 2] << 2);
        r[9 * i + 3] =
            (a->coeffs[8 * i + 2] >> 6) | (a->coeffs[8 * i + 3] << 3);
        r[9 * i + 4] =
            (a->coeffs[8 * i + 3] >> 5) | (a->coeffs[8 * i + 4] << 4);
        r[9 * i + 5] =
            (a->coeffs[8 * i + 4] >> 4) | (a->coeffs[8 * i + 5] << 5);
        r[9 * i + 6] =
            (a->coeffs[8 * i + 5] >> 3) | (a->coeffs[8 * i + 6] << 6);
        r[9 * i + 7] =
            (a->coeffs[8 * i + 6] >> 2) | (a->coeffs[8 * i + 7] << 7);
        r[9 * i + 8] = (a->coeffs[8 * i + 7] >> 1);
    }
}

/*************************************************
 * Name:        polyt1_unpack
 *
 * Description: Unpack polynomial t1 with 9-bit coefficients.
 *              Output coefficients are standard representatives.
 *
 * Arguments:   - poly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void polyt1_unpack(poly* r, const uint8_t* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 8; ++i)
    {
        r->coeffs[8 * i + 0] =
            ((a[9 * i + 0] >> 0) | ((uint32_t)a[9 * i + 1] << 8)) & 0x1FF;
        r->coeffs[8 * i + 1] =
            ((a[9 * i + 1] >> 1) | ((uint32_t)a[9 * i + 2] << 7)) & 0x1FF;
        r->coeffs[8 * i + 2] =
            ((a[9 * i + 2] >> 2) | ((uint32_t)a[9 * i + 3] << 6)) & 0x1FF;
        r->coeffs[8 * i + 3] =
            ((a[9 * i + 3] >> 3) | ((uint32_t)a[9 * i + 4] << 5)) & 0x1FF;
        r->coeffs[8 * i + 4] =
            ((a[9 * i + 4] >> 4) | ((uint32_t)a[9 * i + 5] << 4)) & 0x1FF;
        r->coeffs[8 * i + 5] =
            ((a[9 * i + 5] >> 5) | ((uint32_t)a[9 * i + 6] << 3)) & 0x1FF;
        r->coeffs[8 * i + 6] =
            ((a[9 * i + 6] >> 6) | ((uint32_t)a[9 * i + 7] << 2)) & 0x1FF;
        r->coeffs[8 * i + 7] =
            ((a[9 * i + 7] >> 7) | ((uint32_t)a[9 * i + 8] << 1)) & 0x1FF;
    }
}

/*************************************************
 * Name:        polyt0_pack
 *
 * Description: Bit-pack polynomial t0 with coefficients in ]-2^{D-1}, 2^{D-1}].
 *              Input coefficients are assumed to lie in ]Q-2^{D-1}, Q+2^{D-1}].
 *
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLT0_SIZE_PACKED bytes
 *              - const poly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void polyt0_pack(uint8_t* r, const poly* a)
{
#if DIL_D != 14
#error "polyt0_pack() assumes D == 14"
#endif
    unsigned int i;
    uint32_t     t[4];

    for (i = 0; i < DIL_N / 4; ++i)
    {
        t[0] = DIL_Q + (1U << (DIL_D - 1)) - a->coeffs[4 * i + 0];
        t[1] = DIL_Q + (1U << (DIL_D - 1)) - a->coeffs[4 * i + 1];
        t[2] = DIL_Q + (1U << (DIL_D - 1)) - a->coeffs[4 * i + 2];
        t[3] = DIL_Q + (1U << (DIL_D - 1)) - a->coeffs[4 * i + 3];

        r[7 * i + 0] = t[0];
        r[7 * i + 1] = t[0] >> 8;
        r[7 * i + 1] |= t[1] << 6;
        r[7 * i + 2] = t[1] >> 2;
        r[7 * i + 3] = t[1] >> 10;
        r[7 * i + 3] |= t[2] << 4;
        r[7 * i + 4] = t[2] >> 4;
        r[7 * i + 5] = t[2] >> 12;
        r[7 * i + 5] |= t[3] << 2;
        r[7 * i + 6] = t[3] >> 6;
    }
}

/*************************************************
 * Name:        polyt0_unpack
 *
 * Description: Unpack polynomial t0 with coefficients in ]-2^{D-1}, 2^{D-1}].
 *              Output coefficients lie in ]Q-2^{D-1},Q+2^{D-1}].
 *
 * Arguments:   - poly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void polyt0_unpack(poly* r, const uint8_t* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 4; ++i)
    {
        r->coeffs[4 * i + 0] = a[7 * i + 0];
        r->coeffs[4 * i + 0] |= (uint32_t)a[7 * i + 1] << 8;
        r->coeffs[4 * i + 0] &= 0x3FFF;

        r->coeffs[4 * i + 1] = a[7 * i + 1] >> 6;
        r->coeffs[4 * i + 1] |= (uint32_t)a[7 * i + 2] << 2;
        r->coeffs[4 * i + 1] |= (uint32_t)a[7 * i + 3] << 10;
        r->coeffs[4 * i + 1] &= 0x3FFF;

        r->coeffs[4 * i + 2] = a[7 * i + 3] >> 4;
        r->coeffs[4 * i + 2] |= (uint32_t)a[7 * i + 4] << 4;
        r->coeffs[4 * i + 2] |= (uint32_t)a[7 * i + 5] << 12;
        r->coeffs[4 * i + 2] &= 0x3FFF;

        r->coeffs[4 * i + 3] = a[7 * i + 5] >> 2;
        r->coeffs[4 * i + 3] |= (uint32_t)a[7 * i + 6] << 6;

        r->coeffs[4 * i + 0] =
            DIL_Q + (1U << (DIL_D - 1)) - r->coeffs[4 * i + 0];
        r->coeffs[4 * i + 1] =
            DIL_Q + (1U << (DIL_D - 1)) - r->coeffs[4 * i + 1];
        r->coeffs[4 * i + 2] =
            DIL_Q + (1U << (DIL_D - 1)) - r->coeffs[4 * i + 2];
        r->coeffs[4 * i + 3] =
            DIL_Q + (1U << (DIL_D - 1)) - r->coeffs[4 * i + 3];
    }
}

#if 0
/*************************************************
 * Name:        polyz_pack
 *
 * Description: Bit-pack polynomial z with coefficients
 *              in [-(GAMMA1 - 1), GAMMA1 - 1].
 *              Input coefficients are assumed to be standard representatives.
 *
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLZ_SIZE_PACKED bytes
 *              - const poly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void polyz_pack(uint8_t* r, const poly* a)
{
#if DIL_GAMMA1 > (1 << 19)
#error "polyz_pack() assumes GAMMA1 - 1 fits in 19 bits"
#endif
    unsigned int i;
    uint32_t     t[2];

    for (i = 0; i < DIL_N / 2; ++i)
    {
        /* Map to {0,...,2*GAMMA1 - 2} */
        t[0] = DIL_GAMMA1 - 1 - a->coeffs[2 * i + 0];
        t[0] += ((int32_t)t[0] >> 31) & DIL_Q;

        t[1] = DIL_GAMMA1 - 1 - a->coeffs[2 * i + 1];
        t[1] += ((int32_t)t[1] >> 31) & DIL_Q;

        r[5 * i + 0] = t[0];
        r[5 * i + 1] = t[0] >> 8;
        r[5 * i + 2] = t[0] >> 16;
        r[5 * i + 2] |= t[1] << 4;
        r[5 * i + 3] = t[1] >> 4;
        r[5 * i + 4] = t[1] >> 12;
    }
}

/*************************************************
 * Name:        polyz_unpack
 *
 * Description: Unpack polynomial z with coefficients
 *              in [-(GAMMA1 - 1), GAMMA1 - 1].
 *              Output coefficients are standard representatives.
 *
 * Arguments:   - poly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void polyz_unpack(poly* r, const unsigned char* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 2; ++i)
    {
        r->coeffs[2 * i + 0] = a[5 * i + 0];
        r->coeffs[2 * i + 0] |= (uint32_t)a[5 * i + 1] << 8;
        r->coeffs[2 * i + 0] |= (uint32_t)a[5 * i + 2] << 16;
        r->coeffs[2 * i + 0] &= 0xFFFFF;

        r->coeffs[2 * i + 1] = a[5 * i + 2] >> 4;
        r->coeffs[2 * i + 1] |= (uint32_t)a[5 * i + 3] << 4;
        r->coeffs[2 * i + 1] |= (uint32_t)a[5 * i + 4] << 12;

        r->coeffs[2 * i + 0] = DIL_GAMMA1 - 1 - r->coeffs[2 * i + 0];
        r->coeffs[2 * i + 0] += ((int32_t)r->coeffs[2 * i + 0] >> 31) & DIL_Q;
        r->coeffs[2 * i + 1] = DIL_GAMMA1 - 1 - r->coeffs[2 * i + 1];
        r->coeffs[2 * i + 1] += ((int32_t)r->coeffs[2 * i + 1] >> 31) & DIL_Q;
    }
}

/*************************************************
 * Name:        polyw1_pack
 *
 * Description: Bit-pack polynomial w1 with coefficients in [0, 15].
 *              Input coefficients are assumed to be standard representatives.
 *
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLW1_SIZE_PACKED bytes
 *              - const poly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void polyw1_pack(uint8_t* r, const poly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 2; ++i)
    {
        r[i] = a->coeffs[2 * i + 0] | (a->coeffs[2 * i + 1] << 4);
    }
}
#endif

#if 1 /* delimiter: round3 */
/*************************************************
 * Description: Inplace reduction of all coefficients of polynomial to
 *              representative in [-6283009,6283007].
 * Arguments:   - spoly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void spoly_reduce(spoly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] = s_reduce32(a->coeffs[i]);
    }
}

/*************************************************
 * Description: For all coefficients of in/out polynomial add Q if
 *              coefficient is negative.
 * Arguments:   - spoly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void spoly_caddq(spoly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] = s_caddq(a->coeffs[i]);
    }
}

/*************************************************
 * Description: Inplace reduction of all coefficients of polynomial to
 *              standard representatives.
 *
 * Arguments:   - spoly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void spoly_freeze(spoly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] = s_freeze(a->coeffs[i]);
    }
}

/*************************************************
 * Description: Add polynomials. No modular reduction is performed.
 * Arguments:   - spoly *c: pointer to output polynomial
 *              - const spoly *a: pointer to first summand
 *              - const spoly *b: pointer to second summand
 **************************************************/
CRS_STATIC void spoly_add(spoly* c, const spoly* a, const spoly* b)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = a->coeffs[i] + b->coeffs[i];
    }
}

/*************************************************
 * Description: Subtract polynomials. No modular reduction is
 *              performed.
 * Arguments:   - spoly *c: pointer to output polynomial
 *              - const spoly *a: pointer to first input polynomial
 *              - const spoly *b: pointer to second input polynomial to be
 *                               subtraced from first input polynomial
 **************************************************/
CRS_STATIC void spoly_sub(spoly* c, const spoly* a, const spoly* b)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = a->coeffs[i] - b->coeffs[i];
    }
}

/*************************************************
 * Description: Multiply polynomial by 2^D without modular reduction. Assumes
 *              input coefficients to be less than 2^{31-D} in absolute value.
 * Arguments:   - spoly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void spoly_shiftl(spoly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a->coeffs[i] <<= DIL_SD;
    }
}

/*************************************************
 * Description: Inplace forward NTT. Coefficients can grow by
 *              8*Q in absolute value.
 * Arguments:   - spoly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void spoly_ntt256(spoly* a)
{
    sntt256(a->coeffs);
}

/*************************************************
 * Description: Inplace inverse NTT and multiplication by 2^{32}.
 *              Input coefficients need to be less than Q in absolute
 *              value and output coefficients are again bounded by Q.
 *
 * Arguments:   - spoly *a: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void spoly_invntt_tomont(spoly* a)
{
    invntt_s_tomont256(a->coeffs);
}

/*************************************************
 * Description: Pointwise multiplication of polynomials in NTT domain
 *              representation and multiplication of resulting polynomial
 *              by 2^{-32}.
 * Arguments:   - spoly *c: pointer to output polynomial
 *              - const spoly *a: pointer to first input polynomial
 *              - const spoly *b: pointer to second input polynomial
 **************************************************/
CRS_STATIC void spoly_pointwise_montgomery(spoly* c, const spoly* a,
        const spoly* b)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] =
            montgomery_s_reduce((int64_t)a->coeffs[i] * b->coeffs[i]);
    }
}

/*************************************************
 * Description: For all coefficients c of the input polynomial,
 *              compute c0, c1 such that c mod Q = c1*2^D + c0
 *              with -2^{D-1} < c0 <= 2^{D-1}. Assumes coefficients to be
 *              standard representatives.
 *
 * Arguments:   - spoly *a1: pointer to output polynomial with coefficients c1
 *              - spoly *a0: pointer to output polynomial with coefficients c0
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spoly_power2round(spoly* a1, spoly* a0, const spoly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a1->coeffs[i] = spower2round(&a0->coeffs[i], a->coeffs[i]);
    }
}

/*************************************************
 * Description: For all coefficients c of the input polynomial,
 *              compute high and low bits c0, c1 such c mod Q = c1*ALPHA + c0
 *              with -ALPHA/2 < c0 <= ALPHA/2 except c1 = (Q-1)/ALPHA where we
 *              set c1 = 0 and -ALPHA/2 <= c0 = c mod Q - Q < 0.
 *              Assumes coefficients to be standard representatives.
 * Arguments:   - spoly *a1: pointer to output polynomial with coefficients c1
 *              - spoly *a0: pointer to output polynomial with coefficients c0
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spoly_decompose(spoly* a1, spoly* a0, const spoly* a,
                                unsigned int dil_k)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        a1->coeffs[i] = s_decompose(&a0->coeffs[i], a->coeffs[i], dil_k);
    }
}

/*************************************************
 * Description: Compute hint polynomial. The coefficients of which indicate
 *              whether the low bits of the corresponding coefficient of
 *              the input polynomial overflow into the high bits.
 * Arguments:   - spoly *h: pointer to output hint polynomial
 *              - const spoly *a0: pointer to low part of input polynomial
 *              - const spoly *a1: pointer to high part of input polynomial
 * Returns number of 1 bits.
 **************************************************/
CRS_STATIC unsigned int spoly_make_hint(spoly* h, const spoly* a0,
                                        const spoly* a1, unsigned int dil_k)
{
    unsigned int i, s = 0;

    for (i = 0; i < DIL_N; ++i)
    {
        h->coeffs[i] = make_s_hint(a0->coeffs[i], a1->coeffs[i], dil_k);

        s += h->coeffs[i];
    }

    return s;
}

/*************************************************
 * Description: Use hint polynomial to correct the high bits of a polynomial.
 * Arguments:   - spoly *b: pointer to output polynomial with corrected high
 *bits
 *              - const spoly *a: pointer to input polynomial
 *              - const spoly *h: pointer to input hint polynomial
 **************************************************/
CRS_STATIC void spoly_use_hint(spoly* b, const spoly* a, const spoly* h,
                               unsigned int dil_k)
{
    unsigned int i;

    for (i = 0; i < DIL_N; ++i)
    {
        b->coeffs[i] = use_s_hint(a->coeffs[i], h->coeffs[i], dil_k);
    }
}

/*************************************************
 * Description: Check infinity norm of polynomial against given bound.
 *              Assumes input coefficients were reduced by reduce32().
 * Arguments:   - const spoly *a: pointer to polynomial
 *              - int32_t B: norm bound
 * Returns 0 if norm is strictly smaller than B <= (Q-1)/8 and 1 otherwise.
 **************************************************/
CRS_STATIC int spoly_chknorm(const spoly* a, int32_t B)
{
    unsigned int i;
    int32_t      t;

    if (B > (DIL_Q - 1) / 8)
    {
        return 1;
    }

    /* It is ok to leak which coefficient violates the bound since
     the probability for each coefficient is independent of secret
     data but we must not leak the sign of the centralized representative. */

    for (i = 0; i < DIL_N; ++i)
    {
        /* Absolute value */
        t = a->coeffs[i] >> 31;

        t = a->coeffs[i] - (t & 2 * a->coeffs[i]);

        if (t >= B)
        {
            return 1;
        }
    }

    return 0;
}

/*************************************************
 * Description: Sample uniformly random coefficients in [0, Q-1] by
 *              performing rejection sampling on array of random bytes.
 * Arguments:   - int32_t *a: pointer to output array (allocated)
 *              - unsigned int len: number of coefficients to be sampled
 *              - const uint8_t *buf: array of random bytes
 *              - unsigned int buflen: length of array of random bytes
 * Returns number of sampled coefficients. Can be smaller than len if not enough
 * random bytes were given.
 **************************************************/
CRS_STATIC unsigned int rej_s_uniform(int32_t* a, unsigned int len,
                                      const uint8_t* buf, unsigned int buflen)
{
    unsigned int ctr, pos;
    uint32_t     t;

    ctr = pos = 0;

    while ((ctr < len) && (pos + 3 <= buflen))
    {
        t = buf[pos++];

        t |= (uint32_t)buf[pos++] << 8;

        t |= (uint32_t)buf[pos++] << 16;
        /* LSBF3_READ() */

        t &= 0x7FFFFF;

        if (t < DIL_Q)
        {
            a[ctr++] = t;
        }
    }

    return ctr;
}

/*************************************************
 * Description: Sample polynomial with uniformly random coefficients
 *              in [0,Q-1] by performing rejection sampling on the
 *              output stream of SHAKE256(seed|nonce)
 *
 * Arguments:   - spoly *a: pointer to output polynomial
 *              - const uint8_t seed[]: byte array with seed of length SEEDBYTES
 *              - uint16_t nonce: 2-byte nonce
 **************************************************/
/* uses POLY_UNIFORM_NBLOCKS shared with round2 */

CRS_STATIC void spoly_uniform(spoly* a, const uint8_t seed[DIL_SEEDBYTES],
                              uint16_t nonce)
{
    unsigned int    buflen = POLY_UNIFORM_NBLOCKS * DIL_STREAM128_BLOCKBYTES;
    uint8_t         buf[POLY_UNIFORM_NBLOCKS * DIL_STREAM128_BLOCKBYTES + 2];
    unsigned int    i, ctr, off;
    stream128_state state;

    stream128_init(&state, seed, nonce);
    stream128_squeezeblocks(buf, POLY_UNIFORM_NBLOCKS, &state);

    ctr = rej_s_uniform(a->coeffs, DIL_N, buf, buflen);

    while (ctr < DIL_N)
    {
        off = buflen % 3;

        for (i = 0; i < off; ++i)
        {
            buf[i] = buf[buflen - off + i];
        }

        stream128_squeezeblocks(buf + off, 1, &state);

        buflen = DIL_STREAM128_BLOCKBYTES + off;

        ctr += rej_s_uniform(a->coeffs + ctr, DIL_N - ctr, buf, buflen);
    }

    stream128_wipe(&state);
}

/*************************************************
 * Description: Sample uniformly random coefficients in [-ETA, ETA] by
 *              performing rejection sampling on array of random bytes.
 * Arguments:   - int32_t *a: pointer to output array (allocated)
 *              - unsigned int len: number of coefficients to be sampled
 *              - const uint8_t *buf: array of random bytes
 *              - unsigned int buflen: length of array of random bytes
 * Returns number of sampled coefficients. Can be smaller than len if not enough
 * random bytes were given.
 **************************************************/
CRS_STATIC unsigned int rej_s_eta(int32_t* a, unsigned int len,
                                  const uint8_t* buf, unsigned int buflen,
                                  unsigned int eta)
{
    unsigned int ctr, pos;
    uint32_t     t0, t1;

    ctr = pos = 0;

    while ((ctr < len) && (pos < buflen))
    {
        t0 = buf[pos] & 0x0F;

        t1 = buf[pos++] >> 4;

        /* original preproc: ETA == 2 (4x4 or 8x7) */
        if (eta == 2)
        {
            if (t0 < 15)
            {
                t0 = t0 - (205 * t0 >> 10) * 5;

                a[ctr++] = 2 - t0;
            }

            if (t1 < 15 && ctr < len)
            {
                t1 = t1 - (205 * t1 >> 10) * 5;

                a[ctr++] = 2 - t1;
            }

            /* original preproc: ETA == 4 (6x5) */
        }
        else
        {
            if (t0 < 9)
            {
                a[ctr++] = 4 - t0;
            }

            if ((t1 < 9) && (ctr < len))
            {
                a[ctr++] = 4 - t1;
            }
        }
    }

    return ctr;
}

/*************************************************
 * Description: Sample polynomial with uniformly random coefficients
 *              in [-ETA,ETA] by performing rejection sampling on the
 *              output stream from SHAKE256(seed|nonce) or
 *AES256CTR(seed,nonce).
 *
 * Arguments:   - spoly *a: pointer to output polynomial
 *              - const uint8_t seed[]: byte array with seed of length SEEDBYTES
 *              - uint16_t nonce: 2-byte nonce
 **************************************************/

/* original constants: STREAM256_BLOCKBYTES == SHAKE256_RATE == 136 */
#if 0
    // #if ETA == 2    /* 4x4, 8x7 */
    // #define POLY_UNIFORM_ETA_NBLOCKS
    //         ((136 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)   /* -> 1 */
    //
    // #elif ETA == 4  /* 6x5 */
    // #define POLY_UNIFORM_ETA_NBLOCKS
    //         ((227 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)   /* -> 2 */
    //
    // ...in other words, for our param.sets, #blocks == eta/2
    // #endif
#endif
/*
 * ->
 */
#define POLY_UNIFORM_ETA_MAX_BLKS ((unsigned int)2)

/*---------------------------------------------------
 */
CRS_STATIC void spoly_uniform_eta(spoly* a, const uint8_t seed[DIL_R3_CRHBYTES],
                                  uint16_t nonce, unsigned int eta)
{
    uint8_t         buf[POLY_UNIFORM_ETA_MAX_BLKS * DIL_STREAM256_BLOCKBYTES];
    unsigned int    blks = eta / 2;
    /* see notes at POLY_UNIFORM_ETA_MAX_BLKS
     * map eta(2)->1 block, eta(4)->2 blocks
     */
    unsigned int    buflen = blks * DIL_STREAM256_BLOCKBYTES;
    stream256_state state;
    unsigned int    ctr;

    if (!eta || (blks > POLY_UNIFORM_ETA_MAX_BLKS))
    {
        /* blks(eta) */
        return; /* should-not-happen */
    }

    shake256_stream_init_dilr3(&state, seed, nonce);
    stream256_squeezeblocks(buf, blks, &state);

    ctr = rej_s_eta(a->coeffs, DIL_N, buf, buflen, eta);

    while (ctr < DIL_N)
    {
        stream256_squeezeblocks(buf, 1, &state);

        ctr += rej_s_eta(a->coeffs + ctr, DIL_N - ctr, buf,
                         DIL_STREAM256_BLOCKBYTES, eta);
    }

    stream256_wipe(&state);
}

#if 0
/* round3.0 original fn.body */
uint8_t buf[ POLY_UNIFORM_ETA_MAX_BLKS *
             DIL_STREAM128_BLOCKBYTES ];
unsigned int blks   = eta / 2;
/* see notes at POLY_UNIFORM_ETA_MAX_BLKS
* map eta(2)->1 block, eta(4)->2 blocks
*/
unsigned int buflen = blks * DIL_STREAM128_BLOCKBYTES;
stream128_state state;
unsigned int ctr;

if (!eta || (blks > POLY_UNIFORM_ETA_MAX_BLKS))
{
    /* blks(eta) */
    return;         /* should-not-happen */
}

stream128_init(&state, seed, nonce);
stream128_squeezeblocks(buf, blks, &state);

ctr = rej_s_eta(a->coeffs, DIL_N, buf, buflen, eta);

while (ctr < DIL_N)
{
    stream128_squeezeblocks(buf, 1, &state);

    ctr += rej_s_eta(a->coeffs + ctr, DIL_N - ctr, buf,
                     DIL_STREAM128_BLOCKBYTES, eta);
}



/*************************************************
 * Description: Bit-pack polynomial with coefficients
 *              in [-(GAMMA1 - 1), GAMMA1].
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLYZ_PACKEDBYTES bytes
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spolyz_pack(uint8_t* r, const spoly* a, unsigned int dil_k)
{
    unsigned int i, gamma1 = dil_r3k2gamma1(dil_k);
    uint32_t     t[4];

    if (gamma1 == (1 << 17))
    {
        for (i = 0; i < DIL_N / 4; ++i)
        {
            t[0] = gamma1 - a->coeffs[4 * i + 0];
            t[1] = gamma1 - a->coeffs[4 * i + 1];
            t[2] = gamma1 - a->coeffs[4 * i + 2];
            t[3] = gamma1 - a->coeffs[4 * i + 3];

            r[9 * i + 0] = t[0];
            r[9 * i + 1] = t[0] >> 8;
            r[9 * i + 2] = t[0] >> 16;
            r[9 * i + 2] |= t[1] << 2;
            r[9 * i + 3] = t[1] >> 6;
            r[9 * i + 4] = t[1] >> 14;
            r[9 * i + 4] |= t[2] << 4;
            r[9 * i + 5] = t[2] >> 4;
            r[9 * i + 6] = t[2] >> 12;
            r[9 * i + 6] |= t[3] << 6;
            r[9 * i + 7] = t[3] >> 2;
            r[9 * i + 8] = t[3] >> 10;
        }
    }
    else
    {
        /* (gamma1 == (1 << 19)) */
        for (i = 0; i < DIL_N / 2; ++i)
        {
            t[0] = gamma1 - a->coeffs[2 * i + 0];
            t[1] = gamma1 - a->coeffs[2 * i + 1];

            r[5 * i + 0] = t[0];
            r[5 * i + 1] = t[0] >> 8;
            r[5 * i + 2] = t[0] >> 16;
            r[5 * i + 2] |= t[1] << 4;
            r[5 * i + 3] = t[1] >> 4;
            r[5 * i + 4] = t[1] >> 12;
        }
    }
}
#endif

/*************************************************
 * Description: Unpack polynomial z with coefficients
 *              in [-(GAMMA1 - 1), GAMMA1].
 * Arguments:   - spoly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void spolyz_unpack(spoly* r, const uint8_t* a, unsigned int dil_k)
{
    unsigned int i, gamma1 = dil_r3k2gamma1(dil_k);

    if (gamma1 == (1 << 17))
    {
        /* was: GAMMA1 == (1 << 17) */
        for (i = 0; i < DIL_N / 4; ++i)
        {
            r->coeffs[4 * i + 0] = a[9 * i + 0];
            r->coeffs[4 * i + 0] |= (uint32_t)a[9 * i + 1] << 8;
            r->coeffs[4 * i + 0] |= (uint32_t)a[9 * i + 2] << 16;
            r->coeffs[4 * i + 0] &= 0x3FFFF;

            r->coeffs[4 * i + 1] = a[9 * i + 2] >> 2;
            r->coeffs[4 * i + 1] |= (uint32_t)a[9 * i + 3] << 6;
            r->coeffs[4 * i + 1] |= (uint32_t)a[9 * i + 4] << 14;
            r->coeffs[4 * i + 1] &= 0x3FFFF;

            r->coeffs[4 * i + 2] = a[9 * i + 4] >> 4;
            r->coeffs[4 * i + 2] |= (uint32_t)a[9 * i + 5] << 4;
            r->coeffs[4 * i + 2] |= (uint32_t)a[9 * i + 6] << 12;
            r->coeffs[4 * i + 2] &= 0x3FFFF;

            r->coeffs[4 * i + 3] = a[9 * i + 6] >> 6;
            r->coeffs[4 * i + 3] |= (uint32_t)a[9 * i + 7] << 2;
            r->coeffs[4 * i + 3] |= (uint32_t)a[9 * i + 8] << 10;
            r->coeffs[4 * i + 3] &= 0x3FFFF;

            r->coeffs[4 * i + 0] = gamma1 - r->coeffs[4 * i + 0];
            r->coeffs[4 * i + 1] = gamma1 - r->coeffs[4 * i + 1];
            r->coeffs[4 * i + 2] = gamma1 - r->coeffs[4 * i + 2];
            r->coeffs[4 * i + 3] = gamma1 - r->coeffs[4 * i + 3];
        }
    }
    else
    {
        /* (gamma1 == (1 << 19)) */
        for (i = 0; i < DIL_N / 2; ++i)
        {
            r->coeffs[2 * i + 0] = a[5 * i + 0];
            r->coeffs[2 * i + 0] |= (uint32_t)a[5 * i + 1] << 8;
            r->coeffs[2 * i + 0] |= (uint32_t)a[5 * i + 2] << 16;
            r->coeffs[2 * i + 0] &= 0xFFFFF;

            r->coeffs[2 * i + 1] = a[5 * i + 2] >> 4;
            r->coeffs[2 * i + 1] |= (uint32_t)a[5 * i + 3] << 4;
            r->coeffs[2 * i + 1] |= (uint32_t)a[5 * i + 4] << 12;
            r->coeffs[2 * i + 0] &= 0xFFFFF;

            r->coeffs[2 * i + 0] = gamma1 - r->coeffs[2 * i + 0];
            r->coeffs[2 * i + 1] = gamma1 - r->coeffs[2 * i + 1];
        }
    }
}

/*************************************************
 * Description: Sample polynomial with uniformly random coefficients
 *              in [-(GAMMA1 - 1), GAMMA1] by unpacking output stream
 *              of SHAKE256(seed|nonce)
 * Arguments:   - spoly *a: pointer to output polynomial
 *              - const uint8_t seed[]: byte array with seed of length CRHBYTES
 *              - uint16_t nonce: 16-bit nonce
 **************************************************/

/* original constants: STREAM256_BLOCKBYTES == SHAKE256_RATE == 136
 * the values are coincidentally identical
 */
#if 0
    // #if GAMMA1 == (1 << 17)                   /* 4x4 */
    // #define POLY_UNIFORM_GAMMA1_NBLOCKS
    //     ((576 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)  /* -> 5 */
    //
    // #elif GAMMA1 == (1 << 19)                 /* 6x5, 8x7 */
    // #define POLY_UNIFORM_GAMMA1_NBLOCKS
    //     ((640 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)  /* -> 5 */
    // #endif
#endif
/**/
#define SPOLY_UNIFORM_GAMMA1_NBLOCKS ((unsigned int)5)

CRS_STATIC void spoly_uniform_gamma1(spoly*        a,
                                     const uint8_t seed[DIL_R3_CRHBYTES],
                                     uint16_t nonce, unsigned int dil_k)
{
    uint8_t buf[SPOLY_UNIFORM_GAMMA1_NBLOCKS * DIL_STREAM256_BLOCKBYTES];
    stream256_state state;

    stream256_init_dilr3(&state, seed, nonce);
    stream256_squeezeblocks(buf, SPOLY_UNIFORM_GAMMA1_NBLOCKS, &state);

    spolyz_unpack(a, buf, dil_k);

    memset(buf, 0, SPOLY_UNIFORM_GAMMA1_NBLOCKS * DIL_STREAM256_BLOCKBYTES);
    stream256_wipe(&state);
}

/*--------------------------------------
 * returns 0 for unknown param.sets, which should not happen
 */
ATTR_CONST__
/**/
CRS_STATIC unsigned int dilr3_k2tau(unsigned int dil_k)
{
    if (dil_k == 4)
    {
        return 39;
    }
    if (dil_k == 6)
    {
        return 49;
    }
    if (dil_k == 8)
    {
        return 60;
    }
    return 0;
}

#if 0
/*--------------------------------------
 * returns 0 for unknown param.sets, which should not happen
 */
ATTR_CONST__
/**/
CRS_STATIC unsigned int dilr3_k2eta(unsigned int dil_k)
{
    switch (dil_k)
    {
        case 4:
        case 8:
            return 2;

        case 6:
            return 4;

        default:
            return 0; /* SNH */
    }
}

/*************************************************
 * Description: Implementation of H. Samples polynomial with TAU nonzero
 *              coefficients in {-1,1} using the output stream of
 *              SHAKE256(seed).
 * Arguments:   - spoly *c: pointer to output polynomial
 *              - const uint8_t mu[]: byte array containing seed of length
 *SEEDBYTES
 **************************************************/
CRS_STATIC void spoly_challenge(spoly* c, const uint8_t seed[DIL_SEEDBYTES],
                                unsigned int dil_k)
{
    uint8_t      buf[SHAKE256_RATE];
    unsigned int i, b, pos;
    Keccak_state state;
    uint64_t     signs;

    shake256_init(&state);
    shake256_absorb(&state, seed, DIL_SEEDBYTES);
    shake256_finalize(&state);
    shake256_squeezeblocks(buf, 1, &state);

    signs = 0;

    for (i = 0; i < 8; ++i)
    {
        signs |= (uint64_t)buf[i] << 8 * i;
    }

    pos = 8;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = 0;
    }

    for (i = DIL_N - dilr3_k2tau(dil_k); i < DIL_N; ++i)
    {
        do
        {
            if (pos >= SHAKE256_RATE)
            {
                shake256_squeezeblocks(buf, 1, &state);
                pos = 0;
            }

            b = buf[pos++];
        }
        while (b > i);

        c->coeffs[i] = c->coeffs[b];
        c->coeffs[b] = 1 - 2 * (signs & 1);

        signs >>= 1;
    }

    stream256_wipe(&state);
}
#endif

/*************************************************
 * Description: Implementation of H. Samples polynomial with TAU nonzero
 *              coefficients in {-1,1} using the output stream of
 *              SHAKE256(seed).
 * Arguments:   - spoly *c: pointer to output polynomial
 *              - const uint8_t seed[]: byte array containing seed of length
 *ctildebytes
 **************************************************/
CRS_STATIC void ml_spoly_challenge(spoly* c, const uint8_t* seed,
                                   unsigned int dil_k)
{
    uint8_t      buf[SHAKE256_RATE];
    unsigned int i, b, pos;
    Keccak_state state;
    uint64_t     signs;
    size_t       ctilbytes = dil_mldsa_ctilbytes(dil_k);

    shake256_init(&state);
    shake256_absorb(&state, seed, ctilbytes);
    shake256_finalize(&state);
    shake256_squeezeblocks(buf, 1, &state);

    signs = 0;

    for (i = 0; i < 8; ++i)
    {
        signs |= (uint64_t)buf[i] << 8 * i;
    }

    pos = 8;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = 0;
    }

    for (i = DIL_N - dilr3_k2tau(dil_k); i < DIL_N; ++i)
    {
        do
        {
            if (pos >= SHAKE256_RATE)
            {
                shake256_squeezeblocks(buf, 1, &state);
                pos = 0;
            }

            b = buf[pos++];
        }
        while (b > i);

        c->coeffs[i] = c->coeffs[b];
        c->coeffs[b] = 1 - 2 * (signs & 1);

        signs >>= 1;
    }

    stream256_wipe(&state);
}

/*************************************************
 * Description: Bit-pack polynomial with coefficients in [-ETA,ETA].
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLYETA_PACKEDBYTES bytes
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spolyeta_pack(uint8_t* r, const spoly* a, unsigned int eta)
{
    unsigned int i;
    uint8_t      t[8];

    if (eta == 2)
    {
        for (i = 0; i < DIL_N / 8; ++i)
        {
            t[0] = eta - a->coeffs[8 * i + 0];
            t[1] = eta - a->coeffs[8 * i + 1];
            t[2] = eta - a->coeffs[8 * i + 2];
            t[3] = eta - a->coeffs[8 * i + 3];
            t[4] = eta - a->coeffs[8 * i + 4];
            t[5] = eta - a->coeffs[8 * i + 5];
            t[6] = eta - a->coeffs[8 * i + 6];
            t[7] = eta - a->coeffs[8 * i + 7];

            r[3 * i + 0] = (t[0] >> 0) | (t[1] << 3) | (t[2] << 6);
            r[3 * i + 1] =
                (t[2] >> 2) | (t[3] << 1) | (t[4] << 4) | (t[5] << 7);
            r[3 * i + 2] = (t[5] >> 1) | (t[6] << 2) | (t[7] << 5);
        }
    }
    else
    {
        /* eta == 4 */
        for (i = 0; i < DIL_N / 2; ++i)
        {
            t[0] = eta - a->coeffs[2 * i + 0];
            t[1] = eta - a->coeffs[2 * i + 1];
            r[i] = t[0] | (t[1] << 4);
        }
    }
}

/*************************************************
 * Description: Unpack polynomial with coefficients in [-ETA,ETA].
 *
 * Arguments:   - spoly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void spolyeta_unpack(spoly* r, const uint8_t* a, unsigned int eta)
{
    unsigned int i;

    if (eta == 2)
    {
        for (i = 0; i < DIL_N / 8; ++i)
        {
            r->coeffs[8 * i + 0] = (a[3 * i + 0] >> 0) & 7;
            r->coeffs[8 * i + 1] = (a[3 * i + 0] >> 3) & 7;
            r->coeffs[8 * i + 2] =
                ((a[3 * i + 0] >> 6) | (a[3 * i + 1] << 2)) & 7;

            r->coeffs[8 * i + 3] = (a[3 * i + 1] >> 1) & 7;
            r->coeffs[8 * i + 4] = (a[3 * i + 1] >> 4) & 7;
            r->coeffs[8 * i + 5] =
                ((a[3 * i + 1] >> 7) | (a[3 * i + 2] << 1)) & 7;

            r->coeffs[8 * i + 6] = (a[3 * i + 2] >> 2) & 7;
            r->coeffs[8 * i + 7] = (a[3 * i + 2] >> 5) & 7;

            r->coeffs[8 * i + 0] = eta - r->coeffs[8 * i + 0];
            r->coeffs[8 * i + 1] = eta - r->coeffs[8 * i + 1];
            r->coeffs[8 * i + 2] = eta - r->coeffs[8 * i + 2];
            r->coeffs[8 * i + 3] = eta - r->coeffs[8 * i + 3];
            r->coeffs[8 * i + 4] = eta - r->coeffs[8 * i + 4];
            r->coeffs[8 * i + 5] = eta - r->coeffs[8 * i + 5];
            r->coeffs[8 * i + 6] = eta - r->coeffs[8 * i + 6];
            r->coeffs[8 * i + 7] = eta - r->coeffs[8 * i + 7];
        }
    }
    else
    {
        /* eta == 4 */
        for (i = 0; i < DIL_N / 2; ++i)
        {
            r->coeffs[2 * i + 0] = a[i] & 0x0F;
            r->coeffs[2 * i + 1] = a[i] >> 4;
            r->coeffs[2 * i + 0] = eta - r->coeffs[2 * i + 0];
            r->coeffs[2 * i + 1] = eta - r->coeffs[2 * i + 1];
        }
    }
}

/*************************************************
 * Description: Bit-pack polynomial t1 with coefficients fitting in 10 bits.
 *              Input coefficients are assumed to be standard representatives.
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLYT1_PACKEDBYTES bytes
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spolyt1_pack(uint8_t* r, const spoly* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 4; ++i)
    {
        r[5 * i + 0] = (a->coeffs[4 * i + 0] >> 0);
        r[5 * i + 1] =
            (a->coeffs[4 * i + 0] >> 8) | (a->coeffs[4 * i + 1] << 2);
        r[5 * i + 2] =
            (a->coeffs[4 * i + 1] >> 6) | (a->coeffs[4 * i + 2] << 4);
        r[5 * i + 3] =
            (a->coeffs[4 * i + 2] >> 4) | (a->coeffs[4 * i + 3] << 6);
        r[5 * i + 4] = (a->coeffs[4 * i + 3] >> 2);
    }
}

/*************************************************
 * Description: Unpack polynomial t1 with 10-bit coefficients.
 *              Output coefficients are standard representatives.
 * Arguments:   - spoly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void spolyt1_unpack(spoly* r, const uint8_t* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 4; ++i)
    {
        r->coeffs[4 * i + 0] =
            ((a[5 * i + 0] >> 0) | ((uint32_t)a[5 * i + 1] << 8)) & 0x3FF;

        r->coeffs[4 * i + 1] =
            ((a[5 * i + 1] >> 2) | ((uint32_t)a[5 * i + 2] << 6)) & 0x3FF;

        r->coeffs[4 * i + 2] =
            ((a[5 * i + 2] >> 4) | ((uint32_t)a[5 * i + 3] << 4)) & 0x3FF;

        r->coeffs[4 * i + 3] =
            ((a[5 * i + 3] >> 6) | ((uint32_t)a[5 * i + 4] << 2)) & 0x3FF;
    }
}

/*************************************************
 * Description: Bit-pack polynomial t0 with coefficients in ]-2^{D-1}, 2^{D-1}].
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLYT0_PACKEDBYTES bytes
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spolyt0_pack(uint8_t* r, const spoly* a)
{
    unsigned int i;
    uint32_t     t[8];

    for (i = 0; i < DIL_N / 8; ++i)
    {
        t[0] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 0];
        t[1] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 1];
        t[2] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 2];
        t[3] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 3];
        t[4] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 4];
        t[5] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 5];
        t[6] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 6];
        t[7] = (1 << (DIL_SD - 1)) - a->coeffs[8 * i + 7];

        r[13 * i + 0] = t[0];
        r[13 * i + 1] = t[0] >> 8;
        r[13 * i + 1] |= t[1] << 5;
        r[13 * i + 2] = t[1] >> 3;
        r[13 * i + 3] = t[1] >> 11;
        r[13 * i + 3] |= t[2] << 2;
        r[13 * i + 4] = t[2] >> 6;
        r[13 * i + 4] |= t[3] << 7;
        r[13 * i + 5] = t[3] >> 1;
        r[13 * i + 6] = t[3] >> 9;
        r[13 * i + 6] |= t[4] << 4;
        r[13 * i + 7] = t[4] >> 4;
        r[13 * i + 8] = t[4] >> 12;
        r[13 * i + 8] |= t[5] << 1;
        r[13 * i + 9] = t[5] >> 7;
        r[13 * i + 9] |= t[6] << 6;
        r[13 * i + 10] = t[6] >> 2;
        r[13 * i + 11] = t[6] >> 10;
        r[13 * i + 11] |= t[7] << 3;
        r[13 * i + 12] = t[7] >> 5;
    }
}

/*************************************************
 * Name:        polyt0_unpack
 *
 * Description: Unpack polynomial t0 with coefficients in ]-2^{D-1}, 2^{D-1}].
 *
 * Arguments:   - spoly *r: pointer to output polynomial
 *              - const uint8_t *a: byte array with bit-packed polynomial
 **************************************************/
CRS_STATIC void spolyt0_unpack(spoly* r, const uint8_t* a)
{
    unsigned int i;

    for (i = 0; i < DIL_N / 8; ++i)
    {
        r->coeffs[8 * i + 0] = a[13 * i + 0];
        r->coeffs[8 * i + 0] |= (uint32_t)a[13 * i + 1] << 8;
        r->coeffs[8 * i + 0] &= 0x1FFF;

        r->coeffs[8 * i + 1] = a[13 * i + 1] >> 5;
        r->coeffs[8 * i + 1] |= (uint32_t)a[13 * i + 2] << 3;
        r->coeffs[8 * i + 1] |= (uint32_t)a[13 * i + 3] << 11;
        r->coeffs[8 * i + 1] &= 0x1FFF;

        r->coeffs[8 * i + 2] = a[13 * i + 3] >> 2;
        r->coeffs[8 * i + 2] |= (uint32_t)a[13 * i + 4] << 6;
        r->coeffs[8 * i + 2] &= 0x1FFF;

        r->coeffs[8 * i + 3] = a[13 * i + 4] >> 7;
        r->coeffs[8 * i + 3] |= (uint32_t)a[13 * i + 5] << 1;
        r->coeffs[8 * i + 3] |= (uint32_t)a[13 * i + 6] << 9;
        r->coeffs[8 * i + 3] &= 0x1FFF;

        r->coeffs[8 * i + 4] = a[13 * i + 6] >> 4;
        r->coeffs[8 * i + 4] |= (uint32_t)a[13 * i + 7] << 4;
        r->coeffs[8 * i + 4] |= (uint32_t)a[13 * i + 8] << 12;
        r->coeffs[8 * i + 4] &= 0x1FFF;

        r->coeffs[8 * i + 5] = a[13 * i + 8] >> 1;
        r->coeffs[8 * i + 5] |= (uint32_t)a[13 * i + 9] << 7;
        r->coeffs[8 * i + 5] &= 0x1FFF;

        r->coeffs[8 * i + 6] = a[13 * i + 9] >> 6;
        r->coeffs[8 * i + 6] |= (uint32_t)a[13 * i + 10] << 2;
        r->coeffs[8 * i + 6] |= (uint32_t)a[13 * i + 11] << 10;
        r->coeffs[8 * i + 6] &= 0x1FFF;

        r->coeffs[8 * i + 7] = a[13 * i + 11] >> 3;
        r->coeffs[8 * i + 7] |= (uint32_t)a[13 * i + 12] << 5;
        r->coeffs[8 * i + 7] &= 0x1FFF;

        r->coeffs[8 * i + 0] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 0];
        r->coeffs[8 * i + 1] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 1];
        r->coeffs[8 * i + 2] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 2];
        r->coeffs[8 * i + 3] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 3];
        r->coeffs[8 * i + 4] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 4];
        r->coeffs[8 * i + 5] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 5];
        r->coeffs[8 * i + 6] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 6];
        r->coeffs[8 * i + 7] = (1 << (DIL_SD - 1)) - r->coeffs[8 * i + 7];
    }
}

#if 0
/*--------------------------------------
 * expect the few calls to be inlined/const-propagated
 */
CRS_STATIC size_t spolyw1_packedbytes(unsigned int dil_k)
{
    switch (dil_k)
    {
        case 4:
            return 192;

        case 6:
        case 8:
            return 128;

#if 0
// original:
// #if GAMMA2 == (Q-1)/88              /* -> 4x4 */
// #define POLYW1_PACKEDBYTES  192
// #elif GAMMA2 == (Q-1)/32            /* -> 6x5, 8x7 */
// #define POLYW1_PACKEDBYTES  128
// #endif
#endif

        default:
            return 0;
    }
}
#endif

/*************************************************
 * Description: Bit-pack polynomial w1 with coefficients in [0,15] or [0,43].
 *              Input coefficients are assumed to be standard representatives.
 * Arguments:   - uint8_t *r: pointer to output byte array with at least
 *                            POLYW1_PACKEDBYTES bytes
 *              - const spoly *a: pointer to input polynomial
 **************************************************/
CRS_STATIC void spolyw1_pack(uint8_t* r, const spoly* a, unsigned int dil_k)
{
    unsigned int i, gamma2 = dil_r3k2gamma2(dil_k);

    if (gamma2 == (DIL_Q - 1) / 88)
    {
        for (i = 0; i < DIL_N / 4; ++i)
        {
            r[3 * i + 0] = a->coeffs[4 * i + 0];
            r[3 * i + 0] |= a->coeffs[4 * i + 1] << 6;
            r[3 * i + 1] = a->coeffs[4 * i + 1] >> 2;
            r[3 * i + 1] |= a->coeffs[4 * i + 2] << 4;
            r[3 * i + 2] = a->coeffs[4 * i + 2] >> 4;
            r[3 * i + 2] |= a->coeffs[4 * i + 3] << 2;
        }
    }
    else
    {
        /* gamma2 == (DIL_Q-1) /32 */
        for (i = 0; i < DIL_N / 2; ++i)
        {
            r[i] = a->coeffs[2 * i + 0] | (a->coeffs[2 * i + 1] << 4);
        }
    }
}
#endif /* /delimiter: round3 */
#endif /* !NO_CRYSTALS_SIG */

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*- Kyber ------*/
CRS_STATIC void kpoly_csubq(kpoly* r);

/*************************************************
 * Description: Compression and subsequent serialization of a polynomial
 * Arguments:   - uint8_t *r: pointer to output byte array
 *                            (of length KYBER_POLYCOMPRESSEDBYTES)
 *              - poly *a:    pointer to input polynomial
 **************************************************/
CRS_STATIC void kpoly_compress(uint8_t* r, size_t compressed_bytes, kpoly* a)
{
    unsigned int i, j;
    uint8_t      t[8];
    uint16_t     u;
    uint32_t     d0;

    kpoly_csubq(a);

    if (compressed_bytes == 128)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                // t[j] = ((((uint16_t)a->coeffs[8*i+j] << 4) +
                //          KYB_Q/2)/ KYB_Q) & 15;
                u = (uint16_t)a->coeffs[8 * i + j];
                // ((u << 4) + KYB_Q/2) / KYB_Q ~=~ (((u << 4) + KYB_Q/2 + 1) *
                // (2^28 / KYB_Q)) >> 28
                d0 = u << 4;
                d0 += 1665;
                d0 *= 80635;
                d0 >>= 28;
                t[j] = d0 & 0xf;
            }

            r[0] = t[0] | (t[1] << 4);
            r[1] = t[2] | (t[3] << 4);
            r[2] = t[4] | (t[5] << 4);
            r[3] = t[6] | (t[7] << 4);

            r += 4;
        }
    }
    else if (compressed_bytes == 160)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                // t[j] = ((((uint32_t)a->coeffs[8*i+j] << 5) +
                //         KYB_Q/2) /KYB_Q) & 31;
                u = (uint16_t)a->coeffs[8 * i + j];
                // ((u << 5) + KYB_Q/2) / KYB_Q ~=~ (((u << 5) + KYB_Q/2) *
                // (2^27 / KYB_Q)) >> 27
                d0 = u << 5;
                d0 += 1664;
                d0 *= 40318;
                d0 >>= 27;
                t[j] = d0 & 0x1f;
            }

            r[0] = (t[0] >> 0) | (t[1] << 5);
            r[1] = (t[1] >> 3) | (t[2] << 2) | (t[3] << 7);
            r[2] = (t[3] >> 1) | (t[4] << 4);
            r[3] = (t[4] >> 4) | (t[5] << 1) | (t[6] << 6);
            r[4] = (t[6] >> 2) | (t[7] << 3);

            r += 5;
        }

#if 0
        /* deactivated, kyber512 */
    }
    else if (compressed_bytes == 96)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            for (j = 0; j < 8; j++)
                t[j] = ((((uint16_t)a->coeffs[8 * i + j] << 3)
                         + KYB_Q / 2) / KYB_Q) & 7;

            r[0] = (t[0] >> 0) | (t[1] << 3) | (t[2] << 6);
            r[1] = (t[2] >> 2) | (t[3] << 1) | (t[4] << 4) |
                   (t[5] << 7);
            r[2] = (t[5] >> 1) | (t[6] << 2) | (t[7] << 5);

            r += 3;
        }

#endif
    }
}

CRS_STATIC void r3_kpoly_compress(uint8_t* r, size_t compressed_bytes, kpoly* a)
{
    unsigned int i, j;
    int16_t      u;
    uint32_t     d0;
    uint8_t      t[8];

    if (compressed_bytes == 128)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                // map to positive standard representatives
                u = a->coeffs[8 * i + j];
                u += (u >> 15) & KYB_Q;
                // t[j] = ((((uint16_t)u << 4) + KYB_Q/2)/KYB_Q) & 15;
                // ((u << 4) + KYB_Q/2) / KYB_Q ~=~ (((u << 4) + KYB_Q/2 + 1) *
                // (2^28 / KYB_Q)) >> 28
                d0 = u << 4;
                d0 += 1665;
                d0 *= 80635;
                d0 >>= 28;
                t[j] = d0 & 0xf;
            }

            r[0] = t[0] | (t[1] << 4);
            r[1] = t[2] | (t[3] << 4);
            r[2] = t[4] | (t[5] << 4);
            r[3] = t[6] | (t[7] << 4);
            r += 4;
        }
    }
    else if (compressed_bytes == 160)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                // map to positive standard representatives
                u = a->coeffs[8 * i + j];
                u += (u >> 15) & KYB_Q;
                // t[j] = ((((uint32_t)u << 5) + KYB_Q/2)/KYB_Q) & 31;
                // ((u << 5) + KYB_Q/2) / KYB_Q ~=~ (((u << 5) + KYB_Q/2) *
                // (2^27 / KYB_Q)) >> 27
                d0 = u << 5;
                d0 += 1664;
                d0 *= 40318;
                d0 >>= 27;
                t[j] = d0 & 0x1f;
            }

            r[0] = (t[0] >> 0) | (t[1] << 5);
            r[1] = (t[1] >> 3) | (t[2] << 2) | (t[3] << 7);
            r[2] = (t[3] >> 1) | (t[4] << 4);
            r[3] = (t[4] >> 4) | (t[5] << 1) | (t[6] << 6);
            r[4] = (t[6] >> 2) | (t[7] << 3);
            r += 5;
        }

#if 0
        /* deactivated, kyber512 */
    }
    else if (compressed_bytes == 96)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            for (j = 0; j < 8; j++)
                t[j] = ((((uint16_t)a->coeffs[8 * i + j] << 3)
                         + KYB_Q / 2) / KYB_Q) & 7;

            r[0] = (t[0] >> 0) | (t[1] << 3) | (t[2] << 6);
            r[1] = (t[2] >> 2) | (t[3] << 1) | (t[4] << 4) |
                   (t[5] << 7);
            r[2] = (t[5] >> 1) | (t[6] << 2) | (t[7] << 5);

            r += 3;
        }

#endif
    }
}

/*************************************************
 * Description: De-serialization and subsequent decompression of a polynomial;
 *              approximate inverse of poly_compress
 * Arguments:   - kpoly *r:         pointer to output polynomial
 *              - const uint8_t *a: pointer to input byte array
 *                                  (of length KYBER_POLYCOMPRESSEDBYTES bytes)
 **************************************************/
CRS_STATIC void kpoly_decompress(kpoly* r, const uint8_t* a, size_t abytes)
{
    unsigned int i, j;
    uint8_t      t[8];

    if (abytes == 128)
    {
        for (i = 0; i < KYB_N / 2; i++)
        {
            r->coeffs[2 * i + 0] = (((uint16_t)(a[0] & 15) * KYB_Q) + 8) >> 4;

            r->coeffs[2 * i + 1] = (((uint16_t)(a[0] >> 4) * KYB_Q) + 8) >> 4;

            a += 1;
        }
    }
    else if (abytes == 160)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            t[0] = (a[0] >> 0);
            t[1] = (a[0] >> 5) | (a[1] << 3);
            t[2] = (a[1] >> 2);
            t[3] = (a[1] >> 7) | (a[2] << 1);
            t[4] = (a[2] >> 4) | (a[3] << 4);
            t[5] = (a[3] >> 1);
            t[6] = (a[3] >> 6) | (a[4] << 2);
            t[7] = (a[4] >> 3);
            a += 5;

            for (j = 0; j < 8; j++)
            {
                r->coeffs[8 * i + j] =
                    ((uint32_t)(t[j] & 31) * KYB_Q + 16) >> 5;
            }
        }

#if 0
        /* deactivated: kyber512 */
    }
    else if (abytes == 96)
    {
        for (i = 0; i < KYB_N / 8; i++)
        {
            t[0] = (a[0] >> 0);
            t[1] = (a[0] >> 3);
            t[2] = (a[0] >> 6) | (a[1] << 2);
            t[3] = (a[1] >> 1);
            t[4] = (a[1] >> 4);
            t[5] = (a[1] >> 7) | (a[2] << 1);
            t[6] = (a[2] >> 2);
            t[7] = (a[2] >> 5);
            a += 3;

            for (j = 0; j < 8; j++)
            {
                r->coeffs[8 * i + j] =
                    ((uint16_t)(t[j] & 7) * KYB_Q + 4) >> 3;
            }
        }

#endif
    }
}

CRS_STATIC void r3_kpoly_decompress(kpoly* r, const uint8_t* a, size_t abytes)
{
    kpoly_decompress(r, a, abytes);
}

/*************************************************
 * Description: Serialization of a polynomial
 *
 * Arguments:   - uint8_t *r: pointer to output byte array
 *                            (needs space for KYB_POLYBYTES bytes)
 *              - kpoly *a:   pointer to input polynomial
 **************************************************/
CRS_STATIC void kpoly_tobytes(uint8_t r[KYB_POLYBYTES], kpoly* a)
{
    uint16_t     t0, t1;
    unsigned int i;

    kpoly_csubq(a);

    for (i = 0; i < KYB_N / 2; i++)
    {
        t0 = a->coeffs[2 * i];
        t1 = a->coeffs[2 * i + 1];

        r[3 * i + 0] = (t0 >> 0);
        r[3 * i + 1] = (t0 >> 8) | (t1 << 4);
        r[3 * i + 2] = (t1 >> 4);
    }
}

CRS_STATIC void r3_kpoly_tobytes(uint8_t r[KYB_POLYBYTES], kpoly* a)
{
    unsigned int i;
    uint16_t     t0, t1;

    for (i = 0; i < KYB_N / 2; i++)
    {
        // map to positive standard representatives
        t0 = a->coeffs[2 * i];
        t0 += ((int16_t)t0 >> 15) & KYB_Q;
        t1 = a->coeffs[2 * i + 1];
        t1 += ((int16_t)t1 >> 15) & KYB_Q;
        r[3 * i + 0] = (t0 >> 0);
        r[3 * i + 1] = (t0 >> 8) | (t1 << 4);
        r[3 * i + 2] = (t1 >> 4);
    }
}

/*************************************************
 * Description: De-serialization of a polynomial;
 *              inverse of poly_tobytes
 * Arguments:   - kpoly *r:         pointer to output polynomial
 *              - const uint8_t *a: pointer to input byte array
 *                                  (of KYB_POLYBYTES bytes)
 **************************************************/
CRS_STATIC void kpoly_frombytes(kpoly* r, const uint8_t a[KYB_POLYBYTES])
{
    unsigned int i;

    for (i = 0; i < KYB_N / 2; i++)
    {
        r->coeffs[2 * i] =
            ((a[3 * i + 0] >> 0) | ((uint16_t)a[3 * i + 1] << 8)) & 0xfff;

        r->coeffs[2 * i + 1] =
            ((a[3 * i + 1] >> 4) | ((uint16_t)a[3 * i + 2] << 4)) & 0xfff;
    }
}

CRS_STATIC void r3_kpoly_frombytes(kpoly* r, const uint8_t a[KYB_POLYBYTES])
{
    kpoly_frombytes(r, a);
}

/*************************************************
 * Name:        poly_frommsg
 *
 * Description: Convert 32-byte message to polynomial
 *
 * Arguments:   - kpoly *r:           pointer to output polynomial
 *              - const uint8_t *msg: pointer to input message
 **************************************************/
CRS_STATIC void kpoly_frommsg(kpoly* r, const uint8_t msg[KYB_INDCPA_MSGBYTES])
{
    unsigned int i, j;

    for (i = 0; i < KYB_N / 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            r->coeffs[8 * i + j] = 0;
            kyb_cmov_int16(r->coeffs + 8 * i + j, ((KYB_Q + 1) / 2),
                           (msg[i] >> j) & 1);
        }
    }
}

/*************************************************
 * Description: Convert polynomial to 32-byte message
 *
 * Arguments:   - uint8_t *msg: pointer to output message
 *              - kpoly *a:     pointer to input polynomial
 **************************************************/
CRS_STATIC void kpoly_tomsg(uint8_t msg[KYB_INDCPA_MSGBYTES], kpoly* a)
{
    unsigned int i, j;
    uint32_t     t;

    kpoly_csubq(a);

    for (i = 0; i < KYB_N / 8; i++)
    {
        msg[i] = 0;

        for (j = 0; j < 8; j++)
        {
            t = a->coeffs[8 * i + j];
            // t += ((int16_t) t >> 15) & KYB_Q;
            // t = (((t << 1) + KYB_Q / 2) / KYB_Q) & 1;
            t <<= 1;
            t += 1665;
            t *= 80635;
            t >>= 28;
            t &= 1;

            msg[i] |= t << j;
        }
    }
}

CRS_STATIC void r3_kpoly_tomsg(uint8_t msg[KYB_INDCPA_MSGBYTES], kpoly* a)
{
    unsigned int i, j;
    uint32_t     t;

    for (i = 0; i < KYB_N / 8; i++)
    {
        msg[i] = 0;

        for (j = 0; j < 8; j++)
        {
            t = a->coeffs[8 * i + j];
            // t += ((int16_t)t >> 15) & KYB_Q;
            // t = (((t << 1) + KYB_Q / 2) / KYB_Q) & 1;
            t <<= 1;
            t += 1665;
            t *= 80635;
            t >>= 28;
            t &= 1;

            msg[i] |= t << j;
        }
    }
}

/*************************************************
 * Description: Given an array of uniformly random bytes, compute
 *              polynomial with coefficients distributed according to
 *              a centered binomial distribution with parameter KYBER_ETA
 *
 * Arguments:   - poly *r:            pointer to output polynomial
 *              - const uint8_t *buf: pointer to input byte array
 **************************************************/
CRS_STATIC void kyb_cbd(kpoly* r, const uint8_t buf[KYB_ETA * KYB_N / 4])
{
    unsigned int i, j;
    uint32_t     t, d;
    int16_t      a, b;

    for (i = 0; i < KYB_N / 8; i++)
    {
        t = LSBF4_READ(buf + 4 * i);

        d = t & 0x55555555;
        d += (t >> 1) & 0x55555555;

        for (j = 0; j < 8; j++)
        {
            a = (d >> (4 * j + 0)) & 0x3;
            b = (d >> (4 * j + 2)) & 0x3;

            r->coeffs[8 * i + j] = a - b;
        }
    }
}

CRS_STATIC void kyb_cbd_eta1(kpoly* r, const uint8_t buf[KYB_ETA * KYB_N / 4])
{
    kyb_cbd(r, buf);
}

/**************************************/
CRS_STATIC void kyber_shake256_prf(uint8_t* out, size_t outlen,
                                   const uint8_t key[KYB_SYMBYTES],
                                   uint8_t       nonce)
{
    uint8_t extkey[KYB_SYMBYTES + 1] CRS_SENSITIVE;

    MEMCPY(extkey, key, KYB_SYMBYTES);

    extkey[KYB_SYMBYTES] = nonce;

    shake256(out, outlen, extkey, sizeof(extkey));

    MEMSET0_STRICT(extkey, sizeof(extkey));
}

/*************************************************
 * Description: Sample a polynomial deterministically from a seed and a nonce,
 *              with output polynomial close to centered binomial distribution
 *              with parameter KYBER_ETA
 *
 * Arguments:   - kpoly *r:            pointer to output polynomial
 *              - const uint8_t *seed: pointer to input seed
 *                                     (of length KYB_SYMBYTES bytes)
 *              - uint8_t nonce:       one-byte input nonce
 **************************************************/
CRS_STATIC void kpoly_getnoise(kpoly* r, const uint8_t seed[KYB_SYMBYTES],
                               uint8_t nonce)
{
    uint8_t buf[KYB_ETA * KYB_N / 4] CRS_SENSITIVE;

    kyber_shake256_prf(buf, sizeof(buf), seed, nonce);

    kyb_cbd(r, buf);

    MEMSET0_STRICT(buf, sizeof(buf));
}

CRS_STATIC void r3_kpoly_getnoise_eta1(kpoly*        r,
                                       const uint8_t seed[KYB_SYMBYTES],
                                       uint8_t       nonce)
{
    uint8_t buf[KYB_ETA * KYB_N / 4] CRS_SENSITIVE;

    kyber_shake256_prf(buf, sizeof(buf), seed, nonce);

    kyb_cbd_eta1(r, buf);

    MEMSET0_STRICT(buf, sizeof(buf));
}

// for Kyber768 and Kyber1024, eta1 == eta2
CRS_STATIC void r3_kpoly_getnoise_eta2(kpoly*        r,
                                       const uint8_t seed[KYB_SYMBYTES],
                                       uint8_t       nonce)
{
    r3_kpoly_getnoise_eta1(r, seed, nonce);
}

/*------------------------------------*/
CRS_STATIC void kpoly_reduce(kpoly* r);
CRS_STATIC void r3_kpoly_reduce(kpoly* r);

/*************************************************
 * Description: Computes negacyclic number-theoretic transform (NTT) of
 *              a polynomial in place;
 *              inputs assumed to be in normal order, output in bitreversed
 *order
 *
 * Arguments:   - uint16_t *r: pointer to in/output polynomial
 **************************************************/
CRS_STATIC void kpoly_ntt(kpoly* r)
{
    kyb__ntt256(r->coeffs);

    kpoly_reduce(r);
}

CRS_STATIC void r3_kpoly_ntt(kpoly* r)
{
    r3_kyb__ntt256(r->coeffs);

    r3_kpoly_reduce(r);
}

/*************************************************
 * Description: Computes inverse of negacyclic number-theoretic transform (NTT)
 *              of a polynomial in place;
 *              inputs assumed to be in bitreversed order, output in normal
 *order
 *
 * Arguments:   - uint16_t *a: pointer to in/output polynomial
 **************************************************/
CRS_STATIC void kpoly_invntt_tomont(kpoly* r)
{
    kyb__invntt256(r->coeffs);
}

CRS_STATIC void r3_kpoly_invntt_tomont(kpoly* r)
{
    r3_kyb__invntt256(r->coeffs);
}

/*************************************************
 * Description: Multiplication of two polynomials in NTT domain
 * Arguments:   - kpoly *r:       pointer to output polynomial
 *              - const kpoly *a: pointer to first input polynomial
 *              - const kpoly *b: pointer to second input polynomial
 **************************************************/
CRS_STATIC void kpoly_basemul_montgomery(kpoly* r, const kpoly* a,
        const kpoly* b)
{
    unsigned int i;

    for (i = 0; i < KYB_N / 4; i++)
    {
        kyb__basemul(&r->coeffs[4 * i], &a->coeffs[4 * i], &b->coeffs[4 * i],
                     kyb_zetas[64 + i]);

        kyb__basemul(&r->coeffs[4 * i + 2], &a->coeffs[4 * i + 2],
                     &b->coeffs[4 * i + 2], -kyb_zetas[64 + i]);
    }
}

CRS_STATIC void r3_kpoly_basemul_montgomery(kpoly* r, const kpoly* a,
        const kpoly* b)
{
    unsigned int i;

    for (i = 0; i < KYB_N / 4; i++)
    {
        r3_kyb__basemul(&r->coeffs[4 * i], &a->coeffs[4 * i], &b->coeffs[4 * i],
                        r3_kyb_zetas[64 + i]);

        r3_kyb__basemul(&r->coeffs[4 * i + 2], &a->coeffs[4 * i + 2],
                        &b->coeffs[4 * i + 2], -r3_kyb_zetas[64 + i]);
    }
}

/*************************************************
 * Description: Inplace conversion of all coefficients of a polynomial
 *              from normal domain to Montgomery domain
 * Arguments:   - kpoly *r: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void kpoly_tomont(kpoly* r)
{
    int16_t      f = (UINT64_C(1) << 32) % KYB_Q;
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = kyb__montg_reduce((int32_t)r->coeffs[i] * f);
    }
}

CRS_STATIC void r3_kpoly_tomont(kpoly* r)
{
    int16_t      f = (UINT64_C(1) << 32) % KYB_Q;
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = r3_kyb__montg_reduce((int32_t)r->coeffs[i] * f);
    }
}

/*************************************************
 * Description: Applies Barrett reduction to all coefficients of a polynomial
 *              for details of the Barrett reduction see comments in reduce.c
 * Arguments:   - kpoly *r: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void kpoly_reduce(kpoly* r)
{
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = kyb__barrett_reduce(r->coeffs[i]);
    }
}

CRS_STATIC void r3_kpoly_reduce(kpoly* r)
{
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = r3_kyb__barrett_reduce(r->coeffs[i]);
    }
}

/*************************************************
 * Description: Applies conditional subtraction of q to each coefficient
 *              of a polynomial. For details of conditional subtraction
 *              of q see comments in reduce.c
 *
 * Arguments:   - kpoly *r: pointer to input/output polynomial
 **************************************************/
CRS_STATIC void kpoly_csubq(kpoly* r)
{
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = kyb__csubq(r->coeffs[i]);
    }
}

/*************************************************
 * Description: Add two K polynomials
 *
 * Arguments: - kpoly *r:       pointer to output polynomial
 *            - const kpoly *a: pointer to first input polynomial
 *            - const kpoly *b: pointer to second input polynomial
 **************************************************/
CRS_STATIC void kpoly_add(kpoly* r, const kpoly* a, const kpoly* b)
{
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = a->coeffs[i] + b->coeffs[i];
    }
}

/*************************************************
 * Description: Subtract two polynomials
 * Arguments: - poly *r:       pointer to output polynomial
 *            - const poly *a: pointer to first input polynomial
 *            - const poly *b: pointer to second input polynomial
 **************************************************/
CRS_STATIC void kpoly_sub(kpoly* r, const kpoly* a, const kpoly* b)
{
    unsigned int i;

    for (i = 0; i < KYB_N; i++)
    {
        r->coeffs[i] = a->coeffs[i] - b->coeffs[i];
    }
}
#endif /*-----  /delimiter: Kyber  ------------------------------------*/
#endif /*-----  /delimiter: poly  -------------------------------------*/

#if 1 /*-----  delimiter: polyvec, some of packing.c  ----------------*/
/* the largest polyvecl, polyveck possible
 * safe to cast to any valid, smaller size
 */
#if !defined(NO_CRYSTALS_SIG)
typedef struct
{
    poly vec[DIL_VECT_MAX];
} polyvec_max;

/* round3, ref.impl-compatible signed math
 */
typedef struct
{
    spoly vec[DIL_VECT_MAX];
} spolyvec_max;
/**/
typedef struct
{
    spoly vec[DIL_VECT_MAX - 1];
} spolyvec_maxm1;

#if 0
//--------------------------------------
// 0 if K is not a valid predefined category
CRS_STATIC unsigned int dil_eta(unsigned int k, unsigned int round)
{
    switch ((round << 16) | k)
    {
        //  case 0x20004: return 6;
        case 0x20005:
            return 5;

        case 0x20006:
            return 3; /* Category IV */

        case 0x20008:
            return 2; /* Category V? */

        case 0x30004:
            return 2;

        case 0x30006:
            return 4;

        case 0x30008:
            return 2;

        default:
            return 0;
    }
}

//--------------------------------------
// raw bytecount, excluding ASN framing
CRS_STATIC size_t dil_prv_wirebytes(unsigned int k, unsigned int l,
                                    unsigned int round)
{
    if (!l)
    {
        l = k - 1;
    }

    if (round == 2)
    {
        return DIL_SEEDBYTES * 2 + DIL_CRHBYTES +
               (k + l) * ((dil_eta(k, round) <= 3) ? 96 : 128) +
               k * DIL_R2_POLYT0_PACKEDBYTES;
    }

    /* see also: DIL_R3_CRHBYTES */

    if (round == 3)
    {
        return DIL_SEEDBYTES * 3 +
               (k + l) * ((dil_eta(k, round) < 4) ? 96 : 128) +
               k * DIL_R3_POLYT0_PACKEDBYTES;
    }

    if (round == 4)
    {
        switch ((round << 16) | (k << 4) | l)
        {
            case 0x40044:
                return DIL_MLDSA_PRV4x4_BYTES;

            case 0x40065:
                return DIL_MLDSA_PRV6x5_BYTES;

            case 0x40087:
                return DIL_MLDSA_PRV8x7_BYTES;

            default:
                return 0;
        }
    }

    return 0;
}

//--------------------------------------
// raw bytecount, excluding ASN framing
CRS_STATIC size_t dil_pub_wirebytes(unsigned int k, unsigned int l,
                                    unsigned int round)
{
    if (!l)
    {
        l = k - 1;
    }

    switch ((round << 16) | (k << 4) | l)
    {
        //  case 0x20043: return DIL_PUB4x3_BYTES;
        case 0x20054:
            return DIL_PUB5x4_BYTES;

        case 0x20065:
            return DIL_PUB6x5_BYTES;

        case 0x20087:
            return DIL_PUB8x7_BYTES;

        case 0x30044:
            return DIL_R3_PUB4x4_BYTES;

        case 0x30065:
            return DIL_R3_PUB6x5_BYTES;

        case 0x30087:
            return DIL_R3_PUB8x7_BYTES;

        case 0x40044:
            return DIL_MLDSA_44_PUB_BYTES;

        case 0x40065:
            return DIL_MLDSA_65_PUB_BYTES;

        case 0x40087:
            return DIL_MLDSA_87_PUB_BYTES;

        default:
            return 0;
    }
}
#endif
#endif /* !NO_CRYSTALS_SIG */

#if 0
//--------------------------------------
// raw bytecount, excluding ASN framing
CRS_STATIC size_t kyb_pub_wirebytes(unsigned int k)
{
    BUILD_ASSERT(((size_t)KYB_PUB_MAX_BYTES) >= KYB_PUB4_BYTES);

    switch (k)
    {
        //  case 2: return KYB_PUB2_BYTES;
        case 3:
            return KYB_PUB3_BYTES;

        case 4:
            return KYB_PUB4_BYTES;

        default:
            return 0;
    }
}

//--------------------------------------
// raw bytecount, excluding ASN framing
//
// returns complete prv+pub object (default KEM encoding) with non-0 'full'
// net bytecount of leading secret bytes (prv only) with 0 'full'
//
CRS_STATIC size_t kyb_prv_wirebytes(unsigned int k, unsigned int full)
{
    BUILD_ASSERT(((size_t)KYB_PRV_MAX_BYTES) >= KYB_PRV4_BYTES);

    switch (k)
    {
        //  case 2: return (full ? KYB_PRV2_BYTES : KYB_PRV2_NET_BYTES);
        case 3:
            return (full ? KYB_PRV3_BYTES : KYB_PRV3_NET_BYTES);

        case 4:
            return (full ? KYB_PRV4_BYTES : KYB_PRV4_NET_BYTES);

        default:
            return 0;
    }
}

//--------------------------------------
// raw bytecount for ciphertext, excluding any framing
//
CRS_STATIC size_t kyb_ctext_wirebytes(unsigned int k)
{
    BUILD_ASSERT(((size_t)KYB_CIPHERTXT_MAX_BYTES) >= KYB_CIPHTXT4_BYTES);

    switch (k)
    {
        //  case 2: return KYB_CIPHTXT2_BYTES;
        case 3:
            return KYB_CIPHTXT3_BYTES;

        case 4:
            return KYB_CIPHTXT4_BYTES;

        default:
            return 0;
    }
}
#endif

#if !defined(NO_CRYSTALS_SIG)
//--------------------------------------
CRS_STATIC unsigned int dil_omega(unsigned int k, unsigned int round)
{
    unsigned int value = (round << 4) | k;
    if (value == 0x25)
    {
        return DIL_OMEGA5x4;
    }
    if (value == 0x26)
    {
        return DIL_OMEGA6x5;
    }
    if (value == 0x28)
    {
        return DIL_OMEGA8x7;
    }
    if (value == 0x34)
    {
        return DIL_R3_OMEGA4x4;
    }
    if (value == 0x36)
    {
        return DIL_R3_OMEGA6x5;
    }
    if (value == 0x38)
    {
        return DIL_R3_OMEGA8x7;
    }
    return 0;
}

//--------------------------------------
//
CRS_STATIC unsigned int dil_k2beta(unsigned int k, unsigned int round)
{
    unsigned int value = (round << 4) | k;
    if (value == 0x25)
    {
        return DIL_BETA5x4;
    }
    if (value == 0x26)
    {
        return DIL_BETA6x5;
    }
    if (value == 0x28)
    {
        return DIL_BETA8x7;
    }
    if (value == 0x34)
    {
        return DIL_R3_BETA4x4;
    }
    if (value == 0x36)
    {
        return DIL_R3_BETA6x5;
    }
    if (value == 0x38)
    {
        return DIL_R3_BETA8x7;
    }
    return 0;
}

//--------------------------------------
// raw bytecount, excluding ASN framing
// returns 0  if parameter choice is not supported
//
// ref.impl:
// CRYPTO_BYTES == (L*POLYZ_PACKEDBYTES + OMEGA + K + N/8 + 8)  [r2]
//
// see also: dil_sigbytes2type(), which is practically the inverse
//
CRS_STATIC size_t dil_signature_bytes(unsigned int k, unsigned int l,
                                      unsigned int round)
{
    switch ((round << 16) | (k << 4) | l)
    {
        case 0x20054:
            return DIL_SIGBYTES5x4; /* round 2 */

        case 0x20065:
            return DIL_SIGBYTES6x5;

        case 0x20087:
            return DIL_SIGBYTES8x7;

        case 0x30044:
            return DIL_R3_SIGBYTES4x4; /* round 3 */

        case 0x30065:
            return DIL_R3_SIGBYTES6x5;

        case 0x30087:
            return DIL_R3_SIGBYTES8x7;

        case 0x40044:
            return DIL_MLDSA_SIGBYTES4x4; /* mldsa */

        case 0x40065:
            return DIL_MLDSA_SIGBYTES6x5;

        case 0x40087:
            return DIL_MLDSA_SIGBYTES8x7;

        default:
            return 0;
    }
}

#if 0
/*--------------------------------------
 * raw/ASN-less signature field sizes are unique
 *
 * see also: dil_signature_bytes()
 */
CRS_STATIC unsigned int dil_sigbytes2type(size_t sigbytes)
{
    switch (sigbytes)
    {
        case 2701:
            return MLCA_ID_DIL3_R2; /* round 2 */

        case 3366:
            return MLCA_ID_DIL4_R2;

        case 4668:
            return MLCA_ID_DIL5_R2;

        case 2420:
            return MLCA_ID_DIL2_R3; /* round 3 */

        case 3293:
            return MLCA_ID_DIL3_R3;

        case 4595:
            return MLCA_ID_DIL5_R3;

        // case 2420: return MLCA_ID_DIL_MLDSA_44; // ambiguous
        // case 3309: return MLCA_ID_DIL_MLDSA_65;
        // case 4627: return MLCA_ID_DIL_MLDSA_87;

        default:
            return 0;
    }
}

/*--------------------------------------
 * crude distinguisher for round2/3 Dil. raw-PRV-key bytes (which are unique)
 * to select sign alg
 */
CRS_STATIC unsigned int dil__prvbytes2type(size_t prvbytes)
{
    switch (prvbytes)
    {
        case DIL_PRV5x4_BYTES:
            return MLCA_ID_DIL3_R2;

        case DIL_PRV6x5_BYTES:
            return MLCA_ID_DIL4_R2;

        case DIL_PRV8x7_BYTES:
            return MLCA_ID_DIL5_R2;

        case DIL_R3_PRV4x4_BYTES:
            return MLCA_ID_DIL2_R3;

        case DIL_R3_PRV6x5_BYTES:
            return MLCA_ID_DIL3_R3;

        case DIL_R3_PRV8x7_BYTES:
            return MLCA_ID_DIL5_R3;

        case DIL_MLDSA_PRV4x4_BYTES:
            return MLCA_ID_DIL_MLDSA_44;

        case DIL_MLDSA_PRV6x5_BYTES:
            return MLCA_ID_DIL_MLDSA_65;

        case DIL_MLDSA_PRV8x7_BYTES:
            return MLCA_ID_DIL_MLDSA_87;

        default:
            return 0;
    }
}

/*--------------------------------------
 * crude distinguisher for round2/3 Dil. raw-PRV-key bytes (which are unique)
 * to select sign alg
 */
CRS_STATIC unsigned int dil__pubbytes2type(size_t pubbytes)
{
    switch (pubbytes)
    {
        case DIL_PUB5x4_BYTES:
            return MLCA_ID_DIL3_R2;

        case DIL_PUB6x5_BYTES:
            return MLCA_ID_DIL4_R2;

        case DIL_PUB8x7_BYTES:
            return MLCA_ID_DIL5_R2;

        case DIL_R3_PUB4x4_BYTES:
            return MLCA_ID_DIL2_R3;

        case DIL_R3_PUB6x5_BYTES:
            return MLCA_ID_DIL3_R3;

        case DIL_R3_PUB8x7_BYTES:
            return MLCA_ID_DIL5_R3;

        default:
            return 0;
    }
}
#endif

CRS_STATIC unsigned int dil__pubbytes2type_mldsa(size_t pubbytes)
{
    switch (pubbytes)
    {
        case DIL_MLDSA_44_PUB_BYTES:
            return MLCA_ID_DIL_MLDSA_44;

        case DIL_MLDSA_65_PUB_BYTES:
            return MLCA_ID_DIL_MLDSA_65;

        case DIL_MLDSA_87_PUB_BYTES:
            return MLCA_ID_DIL_MLDSA_87;

        default:
            return 0;
    }
}

#if 0
/*--------------------------------------
 * OID stubs for Dilithium
 *
 * highly regular:
 *     1.3.6.1.4.1.2.267 .X .Y.Z  ->  060b 2b0601040102820b <X> <Y> <Z>
 *
 * all valid X/Y/Z are single-byte, so sizeof(OID) == sizeof(...stub) +3
 */
CRS_STATIC const unsigned char crs_oidstub[] =
{
    0x06, 0x0b,                                       // OID{
    0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b,   //     ...}
};

CRS_STATIC const unsigned char crs_oidstub_csor[] =
{
    0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04
};
/**/
#define CRS_OIDTAIL_BYTES      ((size_t)3)
#define CRS_OIDTAIL_CSOR_BYTES ((size_t)2)

/*--------------------------------------
 * returns  >0  if Crystals variant is a recognized one, see MLCA_ID_t
 *           0  not a recognized OID, incl. NULL/insufficient input
 *
 * OIDs are highly regular, so we just verify these stubs
 * see also crs_oid2wire(), the inverse
 */
CRS_STATIC unsigned int crs_oid2type(const unsigned char* oid, size_t obytes)
{
    unsigned int rc = 0;

    if (oid && (obytes == sizeof(crs_oidstub) + CRS_OIDTAIL_BYTES) &&
        !MEMCMP(oid, crs_oidstub, obytes - CRS_OIDTAIL_BYTES))
    {
        switch (MSBF4_READ(oid + obytes - 4) & 0xffffff)
        {
            /* (.1) Dilithium round2 */
            case 0x010504:
                rc = MLCA_ID_DIL3_R2;
                break;

            case 0x010605:
                rc = MLCA_ID_DIL4_R2;
                break;

            case 0x010807:
                rc = MLCA_ID_DIL5_R2;
                break;

            /* (.6) Dilithium round2, 'raw' key objects */
            case 0x060504:
                rc = MLCA_ID_DIL3_R2_RAW;
                break;

            case 0x060605:
                rc = MLCA_ID_DIL4_R2_RAW;
                break;

            case 0x060807:
                rc = MLCA_ID_DIL5_R2_RAW;
                break;

            /* (.7) Dilithium round3, compressed signatures */
            case 0x070404:
                rc = MLCA_ID_DIL2_R3;
                break;

            case 0x070605:
                rc = MLCA_ID_DIL3_R3;
                break;

            case 0x070807:
                rc = MLCA_ID_DIL5_R3;
                break;

            /* Kyber OIDs are .N.N */

            /* (.5) Kyber round2 */
            case 0x050303:
                rc = MLCA_ID_KYB3_R2;
                break;

            case 0x050404:
                rc = MLCA_ID_KYB4_R2;
                break;

            /* (.8) Kyber round3 */
            case 0x080303:
                rc = MLCA_ID_KYB3_R3;
                break;

            case 0x080404:
                rc = MLCA_ID_KYB4_R3;
                break;

            default:
                break;
        }
    }
    else if (oid &&
             (obytes == sizeof(crs_oidstub_csor) + CRS_OIDTAIL_CSOR_BYTES) &&
             !MEMCMP(oid, crs_oidstub_csor, obytes - CRS_OIDTAIL_CSOR_BYTES))
    {
        switch (MSBF4_READ(oid + obytes - 4) & 0xffff)
        {
            /* ML-DSA */
            case 0x0311:
                rc = MLCA_ID_DIL_MLDSA_44;
                break;

            case 0x0312:
                rc = MLCA_ID_DIL_MLDSA_65;
                break;

            case 0x0313:
                rc = MLCA_ID_DIL_MLDSA_87;
                break;

            /* ML-KEM */
            case 0x0402:
                rc = MLCA_ID_KYB_MLKEM_768;
                break;

            case 0x0403:
                rc = MLCA_ID_KYB_MLKEM_1024;
                break;

            default:
                break;
        }
    }

    return rc;
}

/*--------------------------------------
 * returns written bytecount
 *         0  if type is unknown
 *        ~0  if output buffer is insufficient
 */
CRS_STATIC size_t crs_oid2wire(unsigned char* wire, size_t wbytes,
                               unsigned int type)
{
    uint32_t tail = 0;
    size_t   wr;

    switch (type)
    {
        /* Dilithium, round 2 */
        case MLCA_ID_DIL3_R2:
            tail = 0x010504;
            break;

        case MLCA_ID_DIL4_R2:
            tail = 0x010605;
            break;

        case MLCA_ID_DIL5_R2:
            tail = 0x010807;
            break;

        case MLCA_ID_DIL3_R2_RAW:
            tail = 0x060504;
            break;

        case MLCA_ID_DIL4_R2_RAW:
            tail = 0x060605;
            break;

        case MLCA_ID_DIL5_R2_RAW:
            tail = 0x060807;
            break;

        /* Dilithium, round 3 */
        case MLCA_ID_DIL2_R3:
            tail = 0x070404;
            break;

        case MLCA_ID_DIL3_R3:
            tail = 0x070605;
            break;

        case MLCA_ID_DIL5_R3:
            tail = 0x070807;
            break;

        /* Kyber */
        case MLCA_ID_KYB3_R2:
            tail = 0x050303;
            break;

        case MLCA_ID_KYB4_R2:
            tail = 0x050404;
            break;

        /* Kyber, round 3 */
        case MLCA_ID_KYB3_R3:
            tail = 0x080303;
            break;

        case MLCA_ID_KYB4_R3:
            tail = 0x080404;
            break;

        default:
            break;
    }

    if (!tail)
    {
        return 0;
    }

    wr = sizeof(crs_oidstub) + CRS_OIDTAIL_BYTES;

    if (wire && (wr > wbytes))
    {
        return ~((size_t)0);    // insufficient output
    }

    if (wire)
    {
        MEMCPY(wire, crs_oidstub, sizeof(crs_oidstub));

        wire[wr - 3] = (unsigned char)(tail >> 16);
        wire[wr - 2] = (unsigned char)(tail >> 8);
        wire[wr - 1] = (unsigned char)tail;
    }

    return wr;
}
#endif
#endif /* !NO_CRYSTALS_SIG */

#if 0
/*--------------------------------------
 * map known IDs to [strength and] functionality
 * see CRS_AlgFlags_t
 *
 * 0 if type is unknown
 */
CRS_STATIC unsigned int crs_type2category(unsigned int type)
{
    switch (type)
    {
        case MLCA_ID_DIL3_R2:
        case MLCA_ID_DIL4_R2:
        case MLCA_ID_DIL5_R2:
        case MLCA_ID_DIL3_R2_RAW:
        case MLCA_ID_DIL4_R2_RAW:
        case MLCA_ID_DIL5_R2_RAW:
        case MLCA_ID_DIL2_R3:
        case MLCA_ID_DIL3_R3:
        case MLCA_ID_DIL5_R3:
        case MLCA_ID_DIL_MLDSA_44:
        case MLCA_ID_DIL_MLDSA_65:
        case MLCA_ID_DIL_MLDSA_87:
            return CRS_ALG_FL_SIG;

        case MLCA_ID_KYB3_R2:
        case MLCA_ID_KYB4_R2:
        case MLCA_ID_KYB3_R3:
        case MLCA_ID_KYB4_R3:
        case MLCA_ID_KYB_MLKEM_768:
        case MLCA_ID_KYB_MLKEM_1024:
            return CRS_ALG_FL_KEX | CRS_ALG_FL_CIP;

        default:
            return 0;
    }
}
#endif

#if 0 /*-----  delimiter: ASN.1/BER  ---------------------------------*/

/* priv.keys which consists of BIT STRING arrays: */
#define CRS__ASN_MAX_ELEMS  ((unsigned int)7)

/* size constant meaning 'invalid/unexpected format' when returned;
 * none of the reserved values are valid size for any struct we deal with
 */
#define CRS__SZ_FMT_INVALID ((size_t)1)
#define CRS__SZ_ETOOSMALL   ((size_t)2)
#define CRS__SZ_MAXERROR    CRS__SZ_ETOOSMALL

/* all encoding is DER
 * we rely on DER as input, since only minimal framing is supported
 *
 * Dilithium public keys:
 *   [3]   0 1794: SEQUENCE {                               -- 30 82 xx yy
 *   [1]   4   15:   SEQUENCE {                             -- 30 nn
 *   [1]   6   11:     OBJECT IDENTIFIER '...2 267 1 6 5'   -- 06 ...
 *   [4]  19    0:     NULL                                 -- 05 00
 *               :     }
 *   [3]  21 1773:   BIT STRING, encapsulates {             -- 03 82 xx yy 00
 *   [3]  26 1768:     SEQUENCE {                           -- 30 82 xx yy
 *   [2]  30   33:       BIT STRING                         -- 03 21 00 ...
 *               :         59 3D BC 08 17 DB 66 9F 67 0D 61 1F DD 27 A5 46
 *               :         88 D7 A3 B9 0D C7 82 CA F8 8A 8E 2F 1A 2A 5E 0B
 *   [3]  65 1729:       BIT STRING                         -- 30 82 xx yy 00
 *               :         53 C7 B4 9C 2B 7B BB 92 F7 A4 EC 36 88 0B F1 EE
 *               :         C7 7E C1 15 BB D8 F3 F8 30 DE CA 04 BD C4 A7 D8 ...
 *
 * exploiting the following specialized information:
 *   [1]  OID sizes are fixed; tags are single-byte
 *   [2]  nonce/bit string sizes are fixed; tags are single byte
 *   [3]  public keys' T1 vector sizes, their BIT STRING etc.
 *        encapsulation and any integrating tag uses/needs 2-byte
 *        Length sizes (82 xx yy)
 *   [4]  NULL parameters are supplied and ignored [legacy compatibility]
 */
#define CRS__ASN_NULL_BYTES 2
#define DIL_SPKI_ADDL_BYTES                                                    \
    4 /*SEQ*/ + 2 /*SEQ*/ + CRS__ASN_NULL_BYTES + 5 /*BIT*/ + 4 /*SEQ*/ +      \
    3 /*BIT*/ + 5 /*BIT*/
//
// excludes OID; OIDs include their Tag+Len fields, not separately
// framed, therefore missing from above

/* Dilithium private keys (full):
 *
 *      0 5648: SEQUENCE {
 *      4    1:   INTEGER 0
 *      7   15:   SEQUENCE {
 *      9   11:     OBJECT IDENTIFIER '1 3 6 1 4 1 2 267 1 6 5'
 *     22    0:     NULL
 *            :     }
 *     24 5624:   OCTET STRING, encapsulates {
 *     28 5620:     SEQUENCE {
 *     32    1:       INTEGER 0
 *     35   33:       BIT STRING
 *            :         95 52 ED 10 1F 58 01 EC 50 89 05 76 D5 EB BF 5A
 *            :         05 D2 9F 30 74 91 D2 3F BF 15 5D 7D 8B 8E A2 F5
 *     70   33:       BIT STRING
 *            :         7C DC 6F B1 43 0D 26 84 DC 12 E9 B3 3D 22 F8 79
 *            :         06 63 FA 5A 4C 32 14 72 C3 99 60 FD A9 58 BA F1
 *    105   49:       BIT STRING
 *            :         43 CE 70 B5 43 F4 26 50 6C EC D7 5E BF 17 C9 32
 *            :         72 F5 49 52 43 0C A7 A6 18 15 05 EB BB A3 DF 23
 *            :         4C 21 3B 89 BE B5 28 F2 33 69 28 86 F5 35 75 20
 *    156  481:       BIT STRING
 *            :         2D 00 45 8A 90 55 E3 BC B2 5B 8A 98 18 99 91 75
 *            :         08 98 23 B4 C2 12 85 61 61 B7 C5 AD 4C 37 58 A3
 *            :         61 A2 D6 D9 33 8D C8 A8 B1 14 4B 15 63 51 11 B9
 *   ...
 *    641  577:       BIT STRING
 *            :         5E A0 8C 49 56 B4 13 06 AC 9E 0D 80 F3 36 54 74
 *            :         8C 62 DC 24 4B E2 54 35 AB 15 86 09 DC 01 73 87
 *            :         8E 66 18 CB CA 86 3A 0E 09 43 0A 63 4D D4 92 01
 *   ...
 *   1222 2689:       BIT STRING
 *            :         A4 CA 2F 0D C5 9A D0 F9 54 10 1D B7 AD BE C8 8F
 *            :         B2 10 9D 8C 8E DA 9E 0D 44 FC 32 AA B9 59 98 A5
 *            :         2E 95 53 B5 5A DE 7A 69 2B 1C 0B 62 F0 80 6E A0
 *   ...
 *   3915 1733:       [0] {
 *   3919 1729:         BIT STRING
 *            :           39 42 F5 ED E4 2E 68 32 0D 92 68 CE AA 48 7F 73
 *            :           51 99 5B 89 0E 24 DD CB 75 60 5B 85 B6 90 1A 2D
 *            :           37 86 09 4C 10 F4 E5 99 84 87 BC 2D 7B 81 A2 CB
 *   ...
 *            :         }
 *            :       }
 *            :     }
 *            :   }
 */

/* Kyber public keys:
 *   [3]   0 1794: SEQUENCE {                               -- 30 82 xx yy
 *   [1]   4   15:   SEQUENCE {                             -- 30 nn
 *   [1]   6   11:     OBJECT IDENTIFIER '...2 267 5 4 4'   -- 06 ...
 *   [4]  19    0:     NULL                                 -- 05 00
 *               :     }
 *   [3]  21 1773:   BIT STRING, encapsulates {             -- 03 82 xx yy 00
 *   [3]  26 1768:     SEQUENCE {                           -- 30 82 xx yy
 *   [3]  65 1729:       BIT STRING                         -- 30 82 xx yy 00
 *               :         53 C7 B4 9C 2B 7B BB 92 F7 A4 EC 36 88 0B F1 EE
 *               :         C7 7E C1 15 BB D8 F3 F8 30 DE CA 04 BD C4 A7 D8 ...
 */
#define KYB_SPKI_ADDL_BYTES                                                    \
    4 /*SEQ*/ + 2 /*SEQ*/ + CRS__ASN_NULL_BYTES + 5 /*BIT*/ + 4 /*SEQ*/ +      \
    5 /*BIT*/
//
// excludes OID; OIDs include their Tag+Len fields, not separately
// framed, therefore missing from above

// Kyber round2 private key
// not a typo: priv.fields intentionally not broken down ('sub-fields')
// public field is redundant, it is included in prv.key (assuming KEM
// use, and not reducing replicated sub-fields)
/*
 *    0 4781: SEQUENCE {
 *    4    1:   INTEGER 0
 *    7   15:   SEQUENCE {
 *    9   11:     OBJECT IDENTIFIER '1 3 6 1 4 1 2 267 5 4 4'
 *   22    0:     NULL
 *          :     }
 *   24 4757:   OCTET STRING, encapsulates {
 *   28 4753:     SEQUENCE {
 *   32    1:       INTEGER 0
 *   35 3169:       BIT STRING
 *          :         A9 21 0C A4 E4 5A 6F 82 01 7D EC 30 24 64 59 ED
 *          :         3A 36 7C 66 8A 2A D8 2A 11 D9 A0 A3 30 23 F6 F4
 *          :         C1 00 95 00 06 67 20 C9 69 52 D5 C3 A3 58 D8 61
 * ...
 * 3208 1573:       [0] {
 * 3212 1569:         BIT STRING
 *          :           F7 18 C6 E0 81 A7 C5 A8 77 0C 34 BB 76 CC A0 A3
 *          :           BA 5D 56 E7 25 E5 16 85 38 84 60 E7 8C 2B F1 13
 *          :           9F E2 27 97 ED 15 69 11 A3 93 08 97 C7 B4 60 1B
 * ...
 *          :         }
 *          :       }
 *          :     }
 *          :   }
 */

/* Tag+Len+fixed Value byte for SEEDBYTES-sized BIT STRINGs */
#define DIL__ASN1_BITSTR_SEED   0x032100
#define DIL__ASN1_BITSTR_SEED_B ((size_t)3) /* sizeof(..._BITSTR_SEED) */

#define CRS__ASN1_SEQUENCE      0x30
#define CRS__ASN1_BITSTRING     0x03
#define CRS__ASN1_OCTETSTRING   0x04
#define CRS__ASN1_NULL          0x05
#define CRS__ASN1_INT           0x02

//----------------------------------------------------------------------------
// writes BIT STRING frame to end of (wire, wbytes)
// returns written bytecount
//
// opportunistic; assume result fits; restricted to 82 xx yy or single-byte Len
//
CRS_STATIC size_t crs_asn_bitstr(unsigned char* wire, size_t wbytes,
                                 size_t bstring_net_bytes)
{
    if (bstring_net_bytes < 0x80)
    {
        // 03 ...len... 00
        if (wire && (wbytes >= 3))
        {
            wire[wbytes - 3] = CRS__ASN1_BITSTRING;
            wire[wbytes - 2] = (unsigned char)bstring_net_bytes + 1;
            wire[wbytes - 1] = 0;
        }

        return 3;
    }
    else
    {
        // assume  03 82 xx yy 00
        if (wire && (wbytes >= 5))
        {
            wire[wbytes - 5] = CRS__ASN1_BITSTRING;
            wire[wbytes - 4] = 0x82;

            wire[wbytes - 3] = (unsigned char)((bstring_net_bytes + 1) >> 8);
            wire[wbytes - 2] = (unsigned char)bstring_net_bytes + 1;

            wire[wbytes - 1] = 0;
        }

        return 5;
    }
}

//--------------------------------------
CRS_STATIC size_t crs_asn_something(unsigned char* wire, size_t wbytes,
                                    size_t seq_net_bytes, unsigned char tag)
{
    if (seq_net_bytes < 0x80)
    {
        // [tag] ...len... 00
        if (wire && (wbytes >= 2))
        {
            wire[wbytes - 2] = tag;
            wire[wbytes - 1] = (unsigned char)seq_net_bytes;
        }

        return 2;
    }
    else
    {
        // assume  [tag] 82 xx yy
        if (wire && (wbytes >= 4))
        {
            wire[wbytes - 4] = tag;
            wire[wbytes - 3] = 0x82;
            wire[wbytes - 2] = (unsigned char)(seq_net_bytes >> 8);
            wire[wbytes - 1] = (unsigned char)seq_net_bytes;
        }

        return 4;
    }
}

/*------------------------------------*/
CRS_STATIC size_t crs_asn_sequence(unsigned char* wire, size_t wbytes,
                                   size_t seq_net_bytes)
{
    return crs_asn_something(wire, wbytes, seq_net_bytes, CRS__ASN1_SEQUENCE);
}

/*------------------------------------*/
CRS_STATIC size_t crs_asn_octetstr(unsigned char* wire, size_t wbytes,
                                   size_t seq_net_bytes)
{
    return crs_asn_something(wire, wbytes, seq_net_bytes,
                             CRS__ASN1_OCTETSTRING);
}

/*--------------------------------------
 * used only for single-byte INT fields
 */
CRS_STATIC size_t crs_asn_int(unsigned char* wire, size_t wbytes,
                              unsigned char i)
{
    if (wire && (wbytes >= 3))
    {
        wire[wbytes - 3] = CRS__ASN1_INT;
        wire[wbytes - 2] = 1;
        wire[wbytes - 1] = i;
    }

    return 3;
}

//--------------------------------------
CRS_STATIC size_t crs_asn_null(unsigned char* wire, size_t wbytes)
{
    if (wire && (wbytes >= CRS__ASN_NULL_BYTES))
    {
        wire[wbytes - 2] = CRS__ASN1_NULL;
        wire[wbytes - 1] = 0x00;
    }

    return CRS__ASN_NULL_BYTES;
}

/*--------------------------------------
 * add  [0] { ... }  or  [1] { ... }  etc. explicit-tag frame
 * 'tag' is 0-based
 *
 * currently, always with "82 xx yy" length structure
 */
CRS_STATIC size_t crs_asn_expl(unsigned char* wire, size_t wbytes,
                               size_t netbytes, unsigned char i_class)
{
    if (wire && (wbytes >= 4))
    {
        wire[wbytes - 4] = 0xa0 + i_class;
        wire[wbytes - 3] = 0x82;
        wire[wbytes - 2] = (unsigned char)(netbytes >> 8);
        wire[wbytes - 1] = (unsigned char)netbytes;
    }

    return 4;
}

/*--------------------------------------
 * macro supplying "SEQ { OID... NULL }" frame at end of (wire, wbytes)
 *
 * returns offset of SEQ byte within (wire, wbytes)
 *         ~0  if type is unknown
 *
 * note: NULL is not optional for our current Crystals definitions
 */
CRS_STATIC size_t crs_asn_oid_extd(unsigned char* wire, size_t wbytes,
                                   unsigned int type)
{
    size_t oidb;

    if (!wbytes)
    {
        return 0;
    }

    oidb = crs_oid2wire(NULL, ~0, type);

    if (!oidb)
    {
        return ~((size_t)0);
    }

    wbytes -= crs_asn_null(wire, wbytes);

    wbytes -= crs_oid2wire(wire ? &wire[wbytes - oidb] : NULL, oidb, type);

    wbytes -= crs_asn_sequence(wire, wbytes, oidb + CRS__ASN_NULL_BYTES);

    /* SEQ { OID { ... } NULL } */

    return wbytes;
}

#if 0
/* retrieve trailing type
 */
CRS_STATIC uint32_t
{
    uint32_t type = 0;

    wtype = MSBF4_READ(pub + pbytes - CRS_WTYPE_BYTES);

    return type;
}
#endif

#if !defined(NO_CRYSTALS_SIG) /*-----  Dilithium  ----------------------*/

/* recurring check: 'does a BIT STRING of 'net_bytes' start here?'
 * returns offset of net bit string if it does (>0)
 *         0      if bytes at offset are not a BIT STRING frame
 *
 *
 * see crs_asn_bitstr() for write counterparts and combinations used
 */
CRS_STATIC size_t is_bitstr_at(const unsigned char* asn, size_t abytes,
                               size_t offs, size_t net_bytes)
{
    size_t tlbytes = 0; /* incl. 0-partial-bit indicating 00 */

    /* prelim. check, valid BIT STR tag+len >= 3 bytes,
     * plus deal with overflows
     *
     * proper check incl. net bytes follows identification
     */
    if (!asn || (abytes < 3) || (offs >= abytes) || (offs + 3 >= abytes) ||
        !net_bytes)
    {
        return 0;
    }

    /* first, verify tag+len+00 */
    /* full check for net_bytes fitting follows */

    if (net_bytes < 0x80)
    {
        /* 03 ...len... 00 [...data...] */
        // sufficient offset already verified above

        if (MSBF3_READ(asn + offs) !=
            ((((uint32_t)CRS__ASN1_BITSTRING) << 16) | ((net_bytes + 1) << 8)))
        {
            return 0;
        }

        tlbytes = 3;
    }
    else if (net_bytes <= 0xffff)
    {
        /* assume  03 82 xx yy 00 */
        uint64_t rd;

        if (offs + 5 >= abytes)
        {
            return 0;
        }

        rd = ((uint64_t)(MSBF4_READ(asn + offs)) << 8) + asn[offs + 4];

        if (rd != UINT64_C(0x0382000000) + (((uint32_t)net_bytes + 1) << 8))
        {
            return 0;
        }

        tlbytes = 5;
    }
    else
    {
        return 0;
    }

    if (offs + tlbytes + net_bytes > abytes)
    {
        return 0;
    }

    return offs + tlbytes;
}

/* don't do this at home: size+offset of regions within raw keys
 * some, marked are functions of K/L
 *
 * DO NOT CHANGE ORDER unless updating PKCS8/PRV conversion code too
 */
CRS_STATIC const struct
{
    unsigned int type;

    size_t       nonceb;
    size_t       keyb;
    size_t       prfb;
    size_t       s1b; /* vector(L) */
    size_t       s2b; /* vector(K) */
    size_t       t0b; /* low bits(vector(K)) */

    size_t       prvb; /* sum of bytecounts above */

    size_t       t1b; /* high bits(vector(K)); public part, excluding
                       * starting DIL_SEEDBYTES which is redundant
                       */

    size_t       pkcs8b; /* full PKCS8 bytecount; partial/1 is -t1b */
} dil__sections[] =
{
    /* clang-format off */
    /*                               L    K    K           K     */
    { MLCA_ID_DIL3_R2, 32, 32, 48, 512, 640, 2240, DIL_PRV5x4_BYTES, 1440, 5012 },
    { MLCA_ID_DIL4_R2, 32, 32, 48, 480, 576, 2688, DIL_PRV6x5_BYTES, 1728, 5652 },
    { MLCA_ID_DIL5_R2, 32, 32, 48, 672, 768, 3584, DIL_PRV8x7_BYTES, 2304, 7508 },

    /*                               s1   s2   t0          t1    */
    { MLCA_ID_DIL2_R3, 32, 32, 32, 384, 384, 1664, DIL_R3_PRV4x4_BYTES, 1280, 3876 },
    { MLCA_ID_DIL3_R3, 32, 32, 32, 640, 768, 2496, DIL_R3_PRV6x5_BYTES, 1920, 5988 },
    { MLCA_ID_DIL5_R3, 32, 32, 32, 672, 768, 3328, DIL_R3_PRV8x7_BYTES, 2560, 7492 },
    /* clang-format on */

    /* sizes w/o typos: scaling is nonlinear */

    /* keep entries in fixed, append-only order */
};

/*------------------------------------*/
CRS_STATIC unsigned int dil_type2round(unsigned int type);

/*--------------------------------------
 * returns >0  if written to start of (wire, wbytes)
 *         0   if input is not recognized Dilithium+prv.key type
 */
CRS_STATIC size_t dil_prv2wire(unsigned char* wire, size_t wbytes,
                               const unsigned char* prv, size_t prvbytes,
                               unsigned int flags, const unsigned char* pub,
                               size_t pubbytes, const unsigned char* algid,
                               size_t ibytes)
{
    size_t       wr = 0, offs = 0, offs0, prvoffs = prvbytes, curr;
    unsigned int type = 0, idx, round = 2;

    switch (prv ? prvbytes : 0)
    {
        case DIL_PRV5x4_BYTES:
            type = MLCA_ID_DIL3_R2;
            break;

        case DIL_PRV6x5_BYTES:
            type = MLCA_ID_DIL4_R2;
            break;

        case DIL_PRV8x7_BYTES:
            type = MLCA_ID_DIL5_R2;
            break;

        case DIL_R3_PRV4x4_BYTES:
            type = MLCA_ID_DIL2_R3;
            break;

        case DIL_R3_PRV6x5_BYTES:
            type = MLCA_ID_DIL3_R3;
            break;

        case DIL_R3_PRV8x7_BYTES:
            type = MLCA_ID_DIL5_R3;
            break;

        case DIL_PRV5x4_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL3_R2;
            break;

        case DIL_PRV6x5_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL4_R2;
            break;

        case DIL_PRV8x7_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL5_R2;
            break;

        default:
            break;
    }

    round = dil_type2round(type);

    if (!type || !round)
    {
        return 0;
    }

    (void)algid;
    (void)ibytes;

    for (idx = 0; idx < ARRAY_ELEMS(dil__sections); ++idx)
    {
        if (dil__sections[idx].type == type)
        {
            break;
        }
    }

    if (idx >= ARRAY_ELEMS(dil__sections))
    {
        return 0;    /* type does not match */
    }

    offs0 = wbytes;
    offs  = wbytes;

    /* partial key if (pub, pubbytes) is not t1[] */

    /* start of raw pub.key is DIL_SEEDBYTES, skip */

    if (pub)
    {
        if (dil__sections[idx].t1b + DIL_SEEDBYTES == pubbytes)
        {
            pubbytes = dil__sections[idx].t1b;
            offs -= pubbytes;

            if (wire)
                MEMMOVE(wire + offs, pub + DIL_SEEDBYTES,
                        dil__sections[idx].t1b);
        }
        else
        {
            return (size_t)MLCA_EPUBKEYSIZE;
        }
    }
    else
    {
        pubbytes = 0;
    }

    if (wire)
    {
        wr = dil__sections[idx].pkcs8b - pubbytes;

        if (wr > wbytes - pubbytes)
        {
            return (size_t)MLCA_ETOOSMALL;
        }
    }

    offs -= crs_asn_bitstr(wire, offs, pubbytes);
    offs -= crs_asn_expl(wire, offs, offs0 - offs, 0);

    /* [0] { BIT STRING { ... } } */

    if (prvoffs != dil__sections[idx].prvb)
    {
        return 0;
    }

    /* fields in reverse order, written back-to-front */

    curr = dil__sections[idx].t0b;
    prvoffs -= curr;
    offs -= curr;

    if ((offs < wbytes) && wire)
    {
        MEMMOVE(wire + offs, prv + prvoffs, curr);
    }

    offs -= crs_asn_bitstr(wire, offs, curr);

    curr = dil__sections[idx].s2b;
    prvoffs -= curr;
    offs -= curr;

    if ((offs < wbytes) && wire)
    {
        MEMMOVE(wire + offs, prv + prvoffs, curr);
    }

    offs -= crs_asn_bitstr(wire, offs, curr);

    curr = dil__sections[idx].s1b;
    prvoffs -= curr;
    offs -= curr;

    if ((offs < wbytes) && wire)
    {
        MEMMOVE(wire + offs, prv + prvoffs, curr);
    }

    offs -= crs_asn_bitstr(wire, offs, curr);

    curr = dil__sections[idx].prfb;
    prvoffs -= curr;
    offs -= curr;

    if ((offs < wbytes) && wire)
    {
        MEMMOVE(wire + offs, prv + prvoffs, curr);
    }

    offs -= crs_asn_bitstr(wire, offs, curr);

    curr = dil__sections[idx].keyb;
    prvoffs -= curr;
    offs -= curr;

    if ((offs < wbytes) && wire)
    {
        MEMMOVE(wire + offs, prv + prvoffs, curr);
    }

    offs -= crs_asn_bitstr(wire, offs, curr);

    curr = dil__sections[idx].nonceb;
    prvoffs -= curr;
    offs -= curr;

    if ((offs < wbytes) && wire)
    {
        MEMMOVE(wire + offs, prv + prvoffs, curr);
    }

    offs -= crs_asn_bitstr(wire, offs, curr);

    offs -= crs_asn_int(wire, offs, 0); /* INT { ...version 0... } */
    offs -= crs_asn_sequence(wire, offs, wbytes - offs);
    offs -= crs_asn_octetstr(wire, offs, offs0 - offs);

    offs = crs_asn_oid_extd(wire, offs, type);
    offs -= crs_asn_int(wire, offs, 0); /* INT { ...version 0... } */
    offs -= crs_asn_sequence(wire, offs, wbytes - offs);

    wr = wbytes - offs;

    if (offs && wire && wr && (offs < wbytes))
    {
        /* check on wr>0 is redundant */
        MEMMOVE(wire, wire + offs, wr);
        MEMSET0_STRICT(wire + wr, wbytes - wr);
    }

    MARK_UNUSED(flags);

    return wr;
}

/*--------------------------------------
 */
CRS_STATIC size_t dil_pub2wire(unsigned char* wire, size_t wbytes,
                               const unsigned char* pub, size_t pbytes,
                               const unsigned char* algid, size_t ibytes)
{
    unsigned int type = 0, round = 0;
    size_t       wr = 0, offs = 0, oidb;

    switch (pub ? pbytes : 0)
    {
        case DIL_PUB5x4_BYTES:
            type = MLCA_ID_DIL3_R2;
            break;

        case DIL_PUB6x5_BYTES:
            type = MLCA_ID_DIL4_R2;
            break;

        case DIL_PUB8x7_BYTES:
            type = MLCA_ID_DIL5_R2;
            break;

        case DIL_R3_PUB4x4_BYTES:
            type = MLCA_ID_DIL2_R3;
            break;

        case DIL_R3_PUB6x5_BYTES:
            type = MLCA_ID_DIL3_R3;
            break;

        case DIL_R3_PUB8x7_BYTES:
            type = MLCA_ID_DIL5_R3;
            break;

        case DIL_PUB5x4_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL3_R2;
            break;

        case DIL_PUB6x5_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL4_R2;
            break;

        case DIL_PUB8x7_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL5_R2;
            break;

        case DIL_R3_PUB4x4_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL2_R3;
            break;

        case DIL_R3_PUB6x5_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL3_R3;
            break;

        case DIL_R3_PUB8x7_BYTES + CRS_WTYPE_BYTES:
            type = MLCA_ID_DIL5_R3;
            break;

        default:
            break;
    }

    round = dil_type2round(type);

    if (!type || !round)
    {
        return 0;
    }

    (void)algid;
    (void)ibytes;

    wr = DIL_SPKI_ADDL_BYTES + sizeof(crs_oidstub) + CRS_OIDTAIL_BYTES + pbytes;

    if (!wire)
    {
        return wr;
    }

    if (wr > wbytes)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    /* concatenate fields back to front */

    if (DIL_SEEDBYTES > pbytes)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    pbytes -= DIL_SEEDBYTES;

    if (pbytes > wr)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs = wr - pbytes;

    // seed is (pub, DIL_SEEDBYTES)
    // raw T1 is rest

    MEMMOVE(&(wire[offs]), &(pub[DIL_SEEDBYTES]), pbytes);

    if (crs_asn_bitstr(NULL, offs, pbytes) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_bitstr(wire, offs, pbytes);
    // BIT STRING { t1 }

    if (DIL_SEEDBYTES > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= DIL_SEEDBYTES;

    MEMMOVE(&(wire[offs]), pub, DIL_SEEDBYTES);

    if (crs_asn_bitstr(NULL, offs, DIL_SEEDBYTES) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_bitstr(wire, offs, DIL_SEEDBYTES);
    // BIT STRING { seed }

    if (crs_asn_sequence(NULL, offs, wr - offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_sequence(wire, offs, wr - offs);
    // SEQ { BIT { seed } BIT { t1 } }

    if (crs_asn_bitstr(NULL, offs, wr - offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_bitstr(wire, offs, wr - offs);
    // BIT { SEQ { BIT { seed } BIT { t1 } } }

    if (crs_asn_null(NULL, offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_null(wire, offs);

    if ((oidb = crs_oid2wire(NULL, ~0, type)) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    oidb = crs_oid2wire(&(wire[offs - oidb]), oidb, type);

    if (oidb == 0 || oidb == ~((size_t)0))
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= oidb;

    if (crs_asn_sequence(NULL, offs, oidb + CRS__ASN_NULL_BYTES) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_sequence(wire, offs, oidb + CRS__ASN_NULL_BYTES);
    // SEQ { OID { ... } NULL }

    if (crs_asn_sequence(NULL, offs, wr - offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_sequence(wire, offs, wr - offs);

    return wr;
}
#endif /* /Dilithium */

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*-- Kyber ------*/
/* Kyber r2 objects are redundant, they contain full private key
 * (as used by ref.impl, assuming direct concatenation) and separate
 * public-key field, a subset of the former.
 *
 * This redundancy is a historical artifact; we do not intent to alter it.
 */

/*--------------------------------------
 * returns >0  if written to start of (wire, wbytes)
 *         0   if input is not recognized Kyber+prv.key type
 */
CRS_STATIC size_t kyb_prv2wire(unsigned char* wire, size_t wbytes,
                               const unsigned char* prv, size_t pbytes,
                               const unsigned char* algid, size_t ibytes)
{
    size_t       wr = 0, offs = 0, offs0 = 0, pubb = 0;
    unsigned int type = 0;

    type = crs_oid2type(algid, ibytes);

    if (type == 0)
    {
        return 0;
    }

    switch (prv ? pbytes : 0)
    {
        case KYB_PRV4_BYTES:
            pubb = kyb_pub_wirebytes(4);
            break;

        case KYB_PRV3_BYTES:
            pubb = kyb_pub_wirebytes(3);
            break;

        case KYB_PRV4_BYTES + CRS_WTYPE_BYTES:
            pubb = kyb_pub_wirebytes(4);
            break;

        case KYB_PRV3_BYTES + CRS_WTYPE_BYTES:
            pubb = kyb_pub_wirebytes(3);
            break;

        default:
            break;
    }

    if (!type || !pubb)
    {
        return 0;
    }

    pubb += KYB_PRV2PUB_ADDL_BYTES;
    /* priv.key only: pub field contains extra trailer */

    offs0 = wbytes;
    offs  = wbytes - pubb;

    pbytes -= pubb; /* < (pbytes pure raw.key) || (pubb) > */

    if (wire && (wr < wbytes))
    {
        MEMMOVE(&(wire[offs]), prv + pbytes, pubb);
    }

    offs -= crs_asn_bitstr(wire, offs, pubb);

    /* BIT STRING { t1 } */

    offs -= crs_asn_expl(wire, offs, offs0 - offs, 0);

    /* [0] { BIT STRING { t1 } } */

    offs -= pbytes + pubb;

    if (wire)
    {
        MEMMOVE(&(wire[offs]), prv, pbytes + pubb);
    }

    offs -= crs_asn_bitstr(wire, offs, pbytes + pubb);

    /* BIT STRING { ..prv.. } [0] { BIT STRING { t1 } } */

    offs -= crs_asn_int(wire, offs, 0); /* INT { ...version 0... } */

    offs -= crs_asn_sequence(wire, offs, offs0 - offs);

    offs -= crs_asn_octetstr(wire, offs, offs0 - offs);

    offs = crs_asn_oid_extd(wire, offs, type);

    offs -= crs_asn_int(wire, offs, 0); /* INT { ...version 0... } */

    offs -= crs_asn_sequence(wire, offs, offs0 - offs);

    wr = offs0 - offs;

    if (offs && wire && wr)
    {
        /* check on wr>0 is redundant */
        MEMMOVE(wire, wire + offs, wr);
        MEMSET0_STRICT(wire + wr, wbytes - wr);
    }

    return wr;
}

#if 0
    // Kyber r2 3-3: matching hard templates:
    //     3633 bytes total
    //          0 3629: SEQUENCE {
    //          4    1:   INTEGER 0
    //          7   15:   SEQUENCE {
    //          9   11:     OBJECT IDENTIFIER '1 3 6 1 4 1 2 267 5 3 3'
    //         22    0:     NULL
    //                :     }
    //         24 3605:   OCTET STRING, encapsulates {
    //         28 3601:     SEQUENCE {
    //         32    1:       INTEGER 0
    //         35 2401:       BIT STRING
    //                :         ........ 2B DC 3E 13 82 35 73 91 C6 0B A5 2A 54
    //                :         0B 1E 85 B2 24 51 49 CE 38 D9 31 DD A2 63 EA D9
    //         ...
    //         30820e2d020100300f060b2b0601040102820b050303050004820e1530820e11
    //         0201000382096100......
    //                 -> 2400 net bytes at offset 40 (prv/1)
    //         ...
    //         2440 1189:       [0] {
    //         2444 1185:         BIT STRING
    //         ...
    //         a08204a5038204a1  [8 net bytes] at offset 2440


    // Kyber r2 4-4: matching hard templates:
    //     4785 bytes total
    //          0 4781: SEQUENCE {
    //          4    1:   INTEGER 0
    //          7   15:   SEQUENCE {
    //          9   11:     OBJECT IDENTIFIER '1 3 6 1 4 1 2 267 5 4 4'
    //         22    0:     NULL
    //                :     }
    //         24 4757:   OCTET STRING, encapsulates {
    //         28 4753:     SEQUENCE {
    //         32    1:       INTEGER 0
    //         35 3169:       BIT STRING
    //                :         ........ 97 73 95 0C C9 06 AF 7C BB F6 27 9D 9A
    //                :         DC 1B 76 42 53 3A 16 CA 16 29 62 5C D2 7C E8 FB
    //         ...
    //         308212ad020100300f060b2b0601040102820b05040405000482129530821291
    //         02010003820c6100......
    //                 -> 3168 net bytes at offset 40 (prv/1)
    //   ...
    //         3208 1573:       [0] {
    //         3212 1569:         BIT STRING
    //   ...
    //         a082062503820621  [8 net bytes] at offset 3208

#endif

/* dil_spkis_der[] is a more structured way of achieving the same */

CRS_STATIC const unsigned char kyb__3pkcs8_pfx[] =
{
    0x30, 0x82, 0x0e, 0x6d, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x05,
    0x03, 0x03, 0x05, 0x00, 0x04, 0x82, 0x0e, 0x55, 0x30, 0x82,
    0x0e, 0x51, 0x02, 0x01, 0x00, 0x03, 0x82, 0x09, 0x61, 0x00,
};

CRS_STATIC const unsigned char kyb__4pkcs8_pfx[] =
{
    0x30, 0x82, 0x12, 0xed, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x05,
    0x04, 0x04, 0x05, 0x00, 0x04, 0x82, 0x12, 0xd5, 0x30, 0x82,
    0x12, 0xd1, 0x02, 0x01, 0x00, 0x03, 0x82, 0x0c, 0x61, 0x00,
};

CRS_STATIC const unsigned char r3_kyb__3pkcs8_pfx[] =
{
    0x30, 0x82, 0x0e, 0x6d, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x08,
    0x03, 0x03, 0x05, 0x00, 0x04, 0x82, 0x0e, 0x55, 0x30, 0x82,
    0x0e, 0x51, 0x02, 0x01, 0x00, 0x03, 0x82, 0x09, 0x61, 0x00,
};

CRS_STATIC const unsigned char r3_kyb__4pkcs8_pfx[] =
{
    0x30, 0x82, 0x12, 0xed, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x08,
    0x04, 0x04, 0x05, 0x00, 0x04, 0x82, 0x12, 0xd5, 0x30, 0x82,
    0x12, 0xd1, 0x02, 0x01, 0x00, 0x03, 0x82, 0x0c, 0x61, 0x00,
};

/*--------------------------------------
 * retrieve internal prv.key from PKCS8-encoded wire bytes
 *
 * skeleton, identifying OID through minimal template
 * returns >0  if successful: nr. of bytes written to start of (prv, pbytes)
 *          0  if framing is not recognized as a Kyber form
 *             mapping to errors; never valid sizes:
 *          1  if appears to be Kyber-like, but encoding is invalid
 *          2  if output is insufficient
 *
 * sets non-NULL 'type' to recognized MLCA_ID_t constant, if known
 *
 */
CRS_STATIC size_t kyb_wire2prv(unsigned char* prv, size_t pbytes,
                               unsigned int* type, const unsigned char* wire,
                               size_t wbytes, const unsigned char* algid,
                               size_t ibytes)
{
    unsigned int wtype = 0, spec = 0; /* wtype >0 if read successfully */
    size_t       wr = 0, pubb = 0;
    int          round;

    spec = is_special_oid(algid, ibytes);

    do
    {
        if (spec && (spec != CRS__SPC_PRV2PUB))
        {
            wr = (size_t)MLCA_ENSUPPORT;
            break;
        }

        if (!wire || !wbytes)
        {
            break;
        }

        wr = CRS__SZ_FMT_INVALID; /* may break on any error */

        /*
         * please do not comment on hardwired offsets/content
         */
        if (wbytes == (size_t)4849)
        {
            /* r2, 4-4 */
            if (MEMCMP(wire, kyb__4pkcs8_pfx, sizeof(kyb__4pkcs8_pfx)))
            {
                round = 2;
            }
            else if (MEMCMP(wire, r3_kyb__4pkcs8_pfx,
                            sizeof(r3_kyb__4pkcs8_pfx)))
            {
                round = 3;
            }
            else
            {
                break;
            }

            /* [0] { BIT STRING { ... } } */
            if (MEMCMP(wire + 3208, "\xa0\x82\x06\x65\x03\x82\x06\x61", 8))
            {
                break;
            }

            wr = KYB_PRV4_BYTES;

            if (prv && (pbytes < wr))
            {
                wr = CRS__SZ_ETOOSMALL;
            }
            else
            {
                if (prv)
                {
                    if (round == 2)
                    {
                        MEMMOVE(prv, wire + sizeof(kyb__4pkcs8_pfx), wr);
                    }
                    else
                    {
                        MEMMOVE(prv, wire + sizeof(r3_kyb__4pkcs8_pfx), wr);
                    }
                }

                wtype = MLCA_ID_KYB4_R2;
                pubb  = KYB_PUB4_BYTES;
            }
        }
        else if (wbytes == (size_t)3697)
        {
            /* r2, 3-3 */
            if (MEMCMP(wire, kyb__3pkcs8_pfx, sizeof(kyb__3pkcs8_pfx)))
            {
                round = 2;
            }
            else if (MEMCMP(wire, r3_kyb__3pkcs8_pfx,
                            sizeof(r3_kyb__3pkcs8_pfx)))
            {
                round = 3;
            }
            else
            {
                break;
            }

            /* [0] { BIT STRING { ... } } */
            if (MEMCMP(wire + 2440, "\xa0\x82\x04\xe5\x03\x82\x04\xe1", 8))
            {
                break;
            }

            wr = KYB_PRV3_BYTES;

            if (prv && (pbytes < wr))
            {
                wr = CRS__SZ_ETOOSMALL;
            }
            else
            {
                if (prv)
                {
                    if (round == 2)
                    {
                        MEMMOVE(prv, wire + sizeof(kyb__3pkcs8_pfx), wr);
                    }
                    else
                    {
                        MEMMOVE(prv, wire + sizeof(r3_kyb__3pkcs8_pfx), wr);
                    }
                }

                wtype = MLCA_ID_KYB3_R2;
                pubb  = KYB_PUB3_BYTES;
            }
        }
        else
        {
            wr = 0; /* unknown base type */
        }
    }
    while (0);

    if (prv && (wr <= pbytes) && pubb && (spec == CRS__SPC_PRV2PUB))
    {
        MEMMOVE(prv, prv + wr - KYB_PRV2PUB_ADDL_BYTES - pubb, pubb);
        wr = pubb;
    }

    /* opportunistic: write trailing type as BE32
     *
     * checking validity(wr) is redundant
     * please do not comment on it
     */
    if (wtype && prv && (wr > CRS__SZ_MAXERROR) &&
        (wr + CRS_WTYPE_BYTES <= pbytes))
    {
        MSBF4_WRITE(prv + wr, wtype);
    }

    if (type)
    {
        *type = wtype;
    }

    return wr;
}

/*--------------------------------------
 * assuming DER encoding
 */
CRS_STATIC const unsigned char kyb__3spki_pfx[] =
{
    0x30, 0x82, 0x04, 0xbf, 0x30, 0x0f, 0x06, 0x0b, 0x2b, 0x06, 0x01, 0x04,
    0x01, 0x02, 0x82, 0x0b, 0x05, 0x03, 0x03, 0x05, 0x00, 0x03, 0x82, 0x04,
    0xaa, 0x00, 0x30, 0x82, 0x04, 0xa5, 0x03, 0x82, 0x04, 0xa1, 0x00,
};
/* + KYB_PUB3_BYTES */

/*--------------------------------------
 * assuming DER encoding
 */
CRS_STATIC const unsigned char kyb__4spki_pfx[] =
{
    0x30, 0x82, 0x06, 0x3f, 0x30, 0x0f, 0x06, 0x0b, 0x2b, 0x06, 0x01, 0x04,
    0x01, 0x02, 0x82, 0x0b, 0x05, 0x04, 0x04, 0x05, 0x00, 0x03, 0x82, 0x06,
    0x2a, 0x00, 0x30, 0x82, 0x06, 0x25, 0x03, 0x82, 0x06, 0x21, 0x00,
};
/* + KYB_PUB4_BYTES */

/*--------------------------------------
 * skeleton, identifying OID through minimal template
 * returns >0  if successful: nr. of bytes written to start of (pub, pbytes)
 *          0  if framing is not recognized
 *          1  if framing appears to be Dilithium, but details invalid
 *             (not a valid size otherwise)
 *
 * sets non-NULL 'type' to recognized MLCA_ID_t constant, if known
 *
 */
CRS_STATIC size_t kyb_wire2pub(unsigned char* pub, size_t pbytes,
                               unsigned int* type, const unsigned char* wire,
                               size_t wbytes, const unsigned char* algid,
                               size_t ibytes)
{
    unsigned int rdtype = 0;
    size_t       wr     = 0;

    if (type)
    {
        *type = 0;
    }

    if (!wire || !wbytes)
    {
        return 0;
    }

    if (sizeof(kyb__3spki_pfx) + KYB_PUB3_BYTES == wbytes)
    {
        if (MEMCMP(kyb__3spki_pfx, wire, sizeof(kyb__3spki_pfx)))
        {
            return 0;
        }

        rdtype = MLCA_ID_KYB3_R2;
        wr     = KYB_PUB3_BYTES;
    }
    else if (sizeof(kyb__4spki_pfx) + KYB_PUB4_BYTES == wbytes)
    {
        if (MEMCMP(kyb__4spki_pfx, wire, sizeof(kyb__4spki_pfx)))
        {
            return 0;
        }

        rdtype = MLCA_ID_KYB4_R2;
        wr     = KYB_PUB4_BYTES;
    }
    else
    {
        return 0;
    }

    if (!pub)
    {
        return wr;
    }

    if (pbytes < wr)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    MEMMOVE(pub, wire + wbytes - wr, wr);

    if (type)
    {
        *type = rdtype;
    }

    (void)algid;
    (void)ibytes;

    return wr;
}

//--------------------------------------
CRS_STATIC size_t kyb_pub2wire(unsigned char* wire, size_t wbytes,
                               const unsigned char* pub, size_t pbytes,
                               const unsigned char* algid, size_t ibytes)
{
    size_t       wr = 0, offs = 0;
    unsigned int type = 0;

    type = crs_oid2type(algid, ibytes);

    if (type == 0)
    {
        return 0;
    }

    if (!type)
    {
        return 0;
    }

    wr = KYB_SPKI_ADDL_BYTES + sizeof(crs_oidstub) + CRS_OIDTAIL_BYTES + pbytes;

    if (!wire)
    {
        return wr;
    }

    if (wr > wbytes)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    /* wrap field as-is */
    if (pbytes > wr)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs = wr - pbytes;
    MEMMOVE(&(wire[offs]), pub, pbytes);

    if (crs_asn_bitstr(NULL, offs, pbytes) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_bitstr(wire, offs, pbytes);
    // BIT STRING { ...raw public key... }

    if (crs_asn_sequence(NULL, offs, wr - offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_sequence(wire, offs, wr - offs);
    // SEQ { BIT { ...raw pub.key... } }

    if (crs_asn_bitstr(NULL, offs, wr - offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_bitstr(wire, offs, wr - offs);
    // BIT { SEQ { BIT { ...raw pub.key... } } }

    if (crs_asn_oid_extd(NULL, offs, type) == ~((size_t)0))
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs = crs_asn_oid_extd(wire, offs, type);

    if (crs_asn_sequence(NULL, offs, wr - offs) > offs)
    {
        return (size_t)MLCA_ETOOSMALL;
    }

    offs -= crs_asn_sequence(wire, offs, wr - offs);

    return wr;
}
#endif /* /Kyber */

//--------------------------------------
typedef enum
{
    DIL_SPKI_SEEDFRAME = 1,   // seed[32] in its own BIT STRING frame
    DIL_SPKI_T1FRAME   = 2,   // T1[var-len] in its own BIT STRING frame
    DIL_SPKI_FULLFRAME = 4    // seed || T1 in a single BIT STRING
} DIL_SPKIflags_t;

/* offset collection of Dilithium fields
 * see dil__sections[] for bytecount counterparts
 */
struct CRS_DilStruct
{
    size_t nonce;
    size_t key;
    size_t prf;
    size_t s1b; /* vector(L) */
    size_t s2b; /* vector(K) */
    size_t t0b; /* low bits(vector(K)) */
    size_t t1b; /* high bits(vector(K)); public part */
    /* OPTIONAL */
};
/**/
#define CRS__DILSTRUCT_INIT0                                                   \
    {                                                                          \
        0, 0, 0, 0, 0, 0, 0,                                                   \
    }

/*--------------------------------------
 * DER SPKI frames
 * identify enough
 *   1) check size
 *   2) check for OID in known position
 *   3) pick up type, nonce[32] and T1[size-dependent] offsets if valid
 */
CRS_STATIC const struct
{
    /* field names with "...b" abbreviate "...bytes" */
    size_t       totalb;
    const char*  descr;

    unsigned int type;

    size_t       oidoffs; /* full 06(...) frame incl. Tag+Len */
    size_t       oidb;

    size_t       seedoffs; /* raw value, w/o any ASN frame excl. 00 start
                              byte of BIT STRING; see also flags */
    size_t       seedb;

    size_t       t1offs; /* raw T1 value, w/o any ASN frame, see also flags */
    size_t       t1b;

    unsigned int flags; /* see DIL_SPKIflags_t */
} dil_spkis_der[] =
{
    /* round2, standard DER SPKIs */
    /* clang-format off */
    {
        1510, "Dil, round2 std. SPKI, Cat. III [Dil-5-4]",
        MLCA_ID_DIL3_R2,
        6, 13, /*OID*/ 33, 32, /*DIL_SEEDBYTES*/ 70, 1440,
        DIL_SPKI_SEEDFRAME | DIL_SPKI_T1FRAME,
    },

    {
        1798, "Dil, round2 std. SPKI, Cat. IV [Dil-6-5]",
        MLCA_ID_DIL4_R2,
        6, 13, /*OID*/ 33, 32, /*DIL_SEEDBYTES*/ 70, 1728,
        DIL_SPKI_SEEDFRAME | DIL_SPKI_T1FRAME,
    },

    {
        2374, "Dil, round2 std. SPKI, Cat. V [Dil-8-7]",
        MLCA_ID_DIL5_R2,
        6, 13, /*OID*/ 33, 32, /*DIL_SEEDBYTES*/ 70, 2304,
        DIL_SPKI_SEEDFRAME | DIL_SPKI_T1FRAME,
    },

    /* round3, standard DER SPKIs */

    {
        1350, "Dil, round3 std. SPKI, Cat. II [Dil-4-4]",
        MLCA_ID_DIL2_R3,
        6, 13, /*OID*/ 33, 32, /*DIL_SEEDBYTES*/ 70, 1280,
        DIL_SPKI_SEEDFRAME | DIL_SPKI_T1FRAME,
    },

    {
        1990, "Dil, round3 std. SPKI, Cat. III [Dil-6-5]",
        MLCA_ID_DIL3_R3,
        6, 13, /*OID*/ 33, 32, /*DIL_SEEDBYTES*/ 70, 1920,
        DIL_SPKI_SEEDFRAME | DIL_SPKI_T1FRAME,
    },

    {
        2630, "Dil, round3 std. SPKI, Cat. V [Dil-8-7]",
        MLCA_ID_DIL5_R3,
        6, 13, /*OID*/ 33, 32, /*DIL_SEEDBYTES*/ 70, 2560,
        DIL_SPKI_SEEDFRAME | DIL_SPKI_T1FRAME,
    },
    /* clang-format on */
};

/*--------------------------------------
 * skeleton, identifying OID through minimal template
 * returns >0  if successful: nr. of bytes written to start of (pub, pbytes)
 *          0  if framing is not recognized
 *          1  if framing appears to be Dilithium, but details invalid
 *             (not a valid size otherwise)
 *
 * polymorphic, accepts round2 and r3 SPKIs
 *
 * sets non-NULL 'type' to recognized MLCA_ID_t constant, if known
 *
 */
CRS_STATIC size_t dil_wire2pub(unsigned char* pub, size_t pbytes,
                               unsigned int* type, const unsigned char* wire,
                               size_t wbytes, const unsigned char* algid,
                               size_t ibytes)
{
    size_t       seedoffs = 0, seedb = 0, t1offs = 0, t1b = 0;
    // any valid offset is >0
    unsigned int idx = 0, i;
    size_t       wr  = 0;

    if (type)
    {
        *type = 0;
    }

    if (!wire || !wbytes)
    {
        return 0;
    }

    for (i = 0; i < ARRAY_ELEMS(dil_spkis_der); ++i)
    {
        unsigned int otype;

        if (dil_spkis_der[i].totalb != wbytes)
        {
            continue;
        }

        //-----  retrieve <seed || T1> into (pub, pbytes)  -----------

        // OID retrieval+verification is unconditional

        otype = crs_oid2type(wire + dil_spkis_der[i].oidoffs,
                             dil_spkis_der[i].oidb);

        //
        if (!otype || (otype != dil_spkis_der[i].type))
        {
            continue;
        }

        /* is this a seed-sized BIT STRING Tag+Len? */
        if (DIL_SPKI_SEEDFRAME & dil_spkis_der[i].flags)
        {
            uint32_t v = MSBF3_READ(&(wire[dil_spkis_der[i].seedoffs - 3]));
#if 0
            (wire[ dil_spkis_der[i].seedoffs - 3 ] << 16) +
            (wire[ dil_spkis_der[i].seedoffs - 2 ] <<  8) +
            wire[ dil_spkis_der[i].seedoffs - 1 ] ;
            // i.e., MSBF3_READ()
#endif

            if (v != DIL__ASN1_BITSTR_SEED)
            {
                continue;
            }

            seedoffs = dil_spkis_der[i].seedoffs;
            seedb    = dil_spkis_der[i].seedb;
        }

        /* is this "03 82 xx yy 00" (xxyy == sizeof(T1)+1)? */

        if (DIL_SPKI_T1FRAME & dil_spkis_der[i].flags)
        {
            uint32_t v = MSBF4_READ(wire + dil_spkis_der[i].t1offs - 5);

            if (((((uint16_t)CRS__ASN1_BITSTRING) << 8) + 0x82) != (v >> 16))
            {
                continue;
            }

            /* BIT STRING { 00 ...T1... }, so +1 byte */

            if ((uint16_t)v != dil_spkis_der[i].t1b + 1)
            {
                continue;
            }

            /* verify 00 (no unused BIT STRING bits) */

            if (wire[dil_spkis_der[i].t1offs - 1] != 0)
            {
                continue;
            }

            /* BIT STRING { .... } covers rest of data */

            t1offs = dil_spkis_der[i].t1offs;
            t1b    = dil_spkis_der[i].t1b;
        }

        if (seedoffs && t1offs)
        {
            idx = i;
            break;
        }
    }

    /* fields are in the same order
     * writing seed, then T1 with MEMMOVE works in-place
     */
    if (seedoffs && seedb && t1offs && t1b)
    {
        wr = seedb + t1b;

        if (type)
        {
            *type = dil_spkis_der[idx].type;
        }

        if (pub && (pbytes >= wr))
        {
            MEMMOVE(pub, wire + seedoffs, seedb);
            MEMMOVE(pub + seedb, wire + t1offs, t1b);
        }
    }

    (void)algid;
    (void)ibytes;

    return wr;
}

/*--------------------------------------
 */
CRS_STATIC const unsigned char dil__pkcs8_87r2_pfx[] =
{
    /* r2 8-7 */
    0x30, 0x82, 0x1d, 0x50, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x01,
    0x08, 0x07, 0x05, 0x00, 0x04, 0x82, 0x1d, 0x38, 0x30, 0x82,
    0x1d, 0x34, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};
/*
 *    0 7504: SEQUENCE {
 *    4    1:   INTEGER 0
 *    7   15:   SEQUENCE {
 *    9   11:     OBJECT IDENTIFIER '1 3 6 1 4 1 2 267 1 8 7'
 *   22    0:     NULL
 *          :     }
 *   24 7480:   OCTET STRING, encapsulates {
 *   28 7476:     SEQUENCE {
 *   32    1:       INTEGER 0
 *   35   33:       BIT STRING
 *          :         E8 17 BB ...
 */

/*--------------------------------------
 */
CRS_STATIC const unsigned char dil__pkcs8_87r3_pfx[] =
{
    /* r3 8-7 */
    0x30, 0x82, 0x1d, 0x40, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07,
    0x08, 0x07, 0x05, 0x00, 0x04, 0x82, 0x1d, 0x28, 0x30, 0x82,
    0x1d, 0x24, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};
/**/
#if 0
    /* round 3.0: */
    0x30, 0x82, 0x1d, 0x50, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07,
    0x08, 0x07, 0x05, 0x00, 0x04, 0x82, 0x1d, 0x38, 0x30, 0x82,
    0x1d, 0x34, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
#endif
/*
 *    0 7504: SEQUENCE {
 *    4    1:   INTEGER 0
 *    7   15:   SEQUENCE {
 *    9   11:     OBJECT IDENTIFIER '1 3 6 1 4 1 2 267 7 8 7'
 *   22    0:     NULL
 *          :     }
 *   24 7480:   OCTET STRING, encapsulates {
 *   28 7476:     SEQUENCE {
 *   32    1:       INTEGER 0
 *   35   33:       BIT STRING
 *          :         1A 1F D4...
 */

/* round2 Dil-8-7, partial/1 key, lacks public T1
 */
CRS_STATIC const unsigned char dil__pkcs8_87r2p1_pfx[] =
{
    0x30, 0x82, 0x14, 0x4e, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x01,
    0x08, 0x07, 0x05, 0x00, 0x04, 0x82, 0x14, 0x36, 0x30, 0x82,
    0x14, 0x32, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};

CRS_STATIC const unsigned char dil__pkcs8_65r2_pfx[] =
{
    /* r2 6-5 */
    0x30, 0x82, 0x16, 0x10, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x01,
    0x06, 0x05, 0x05, 0x00, 0x04, 0x82, 0x15, 0xf8, 0x30, 0x82,
    0x15, 0xf4, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};

/* Dil-6-5, round2 partial/1 key, lacks public T1
 */
CRS_STATIC const unsigned char dil__pkcs8_65r2p1_pfx[] =
{
    0x30, 0x82, 0x0f, 0x4e, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x01,
    0x06, 0x05, 0x05, 0x00, 0x04, 0x82, 0x0f, 0x36, 0x30, 0x82,
    0x0f, 0x32, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};

CRS_STATIC const unsigned char dil__pkcs8_65r3_pfx[] =
{
    /* r3 6-5 */
    0x30, 0x82, 0x17, 0x60, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07,
    0x06, 0x05, 0x05, 0x00, 0x04, 0x82, 0x17, 0x48, 0x30, 0x82,
    0x17, 0x44, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};
/**/
#if 0
    /* round 3.0 */
    0x30, 0x82, 0x17, 0x70, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07,
    0x06, 0x05, 0x05, 0x00, 0x04, 0x82, 0x17, 0x58, 0x30, 0x82,
    0x17, 0x54, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
#endif

CRS_STATIC const unsigned char dil__pkcs8_54r2_pfx[] =
{
    /* r2 5-4 */
    0x30, 0x82, 0x13, 0x90, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x01,
    0x05, 0x04, 0x05, 0x00, 0x04, 0x82, 0x13, 0x78, 0x30, 0x82,
    0x13, 0x74, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};

/* Dil-5-4, partial/1 key, lacks public T1
 */
CRS_STATIC const unsigned char dil__pkcs8_54r2p1_pfx[] =
{
    0x30, 0x82, 0x0d, 0xee, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x01,
    0x05, 0x04, 0x05, 0x00, 0x04, 0x82, 0x0d, 0xd6, 0x30, 0x82,
    0x0d, 0xd2, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};

CRS_STATIC const unsigned char dil__pkcs8_44r3_pfx[] =
{
    /* r3 4-4 */
    0x30, 0x82, 0x0f, 0x20, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07,
    0x04, 0x04, 0x05, 0x00, 0x04, 0x82, 0x0f, 0x08, 0x30, 0x82,
    0x0f, 0x04, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
};
/**/
#if 0
    /* round3.0: */
    0x30, 0x82, 0x0f, 0x30, 0x02, 0x01, 0x00, 0x30, 0x0f, 0x06,
    0x0b, 0x2b, 0x06, 0x01, 0x04, 0x01, 0x02, 0x82, 0x0b, 0x07,
    0x04, 0x04, 0x05, 0x00, 0x04, 0x82, 0x0f, 0x18, 0x30, 0x82,
    0x0f, 0x14, 0x02, 0x01, 0x00, 0x03, 0x21, 0x00,
#endif

/*------------------------------------*/
CRS_STATIC unsigned int is_nonempty_dilstruct(const struct CRS_DilStruct* ps)
{
    if (!ps || !ps->nonce || !ps->key)
    {
        return 0;
    }

    if (ps->prf && ps->s1b && ps->s2b && ps->t0b && ps->t1b)
    {
        return 2;
    }

    if (ps->prf && ps->s1b && ps->s2b && ps->t0b)
    {
        return 1;    /* partial key */
    }

    return 0;
}

/*--------------------------------------
 * retrieve internal prv.key from PKCS8-encoded wire bytes
 *
 * skeleton, identifying OID through minimal template
 * returns >0  if successful: nr. of bytes written to start of (prv, pbytes)
 *          0  if framing is not recognized as a Dilithium form
 *
 * sets non-NULL 'type' to recognized MLCA_ID_t constant, if known
 *
 * transforms PKCS8 into [raw] _public_ key (not an SPKI) written to
 * (prv, pbytes) if called with with CR_OID_SPECIAL_PRV2PUB 'algid'
 *
 * see dil__sections[]
 */
CRS_STATIC size_t dil_wire2prv(unsigned char* prv, size_t pbytes,
                               unsigned int* type, const unsigned char* wire,
                               size_t wbytes, const unsigned char* algid,
                               size_t ibytes)
{
    struct CRS_DilStruct s = CRS__DILSTRUCT_INIT0;
    unsigned int t = 0, round = 0, spec; /* t: 1-based in dil__sections */
    size_t       wr = 0;

    spec = is_special_oid(algid, ibytes);

    do
    {
        if (!wire || !wbytes)
        {
            break;
        }

        wr = CRS__SZ_FMT_INVALID; /* may break on any error */

        if (type)
        {
            *type = 0;
        }

        /* template match below depends on fixed dil__sections[] order */

        /*
         * please do not comment on hardwired offsets/content
         *
         * templates set the expected offset, which is
         * then cross-checked against bytecount
         */
        /* fixed-offset fields: */
        s.nonce = 35;
        s.key   = 70;
        s.prf   = 105;

        s.s1b = 156; /* r2 only; r3: 140 */

        /* r2 and r3 8-7 full-PKCS8 sizes happen to coincide,
         * so 2x check is actually one
         */
        // changes with r3'p

        if (wbytes == dil__sections[6 - 1].pkcs8b)
        {
            if (MEMCMP(wire, dil__pkcs8_87r3_pfx, sizeof(dil__pkcs8_87r3_pfx)))
            {
                break;
            }

            round = 3;
            t     = 6;
            s.s1b = 140;
            s.s2b = 817;
            s.t0b = 1590;
            s.t1b = 4927;
        }
        else if (wbytes == dil__sections[3 - 1].pkcs8b)
        {
            /* r2, 8-7, full */
            if (MEMCMP(wire, dil__pkcs8_87r2_pfx, sizeof(dil__pkcs8_87r2_pfx)))
            {
                break;
            }

            round = 2;
            s.t0b = 1606; /* sizes common to r2 and r3 8-7 */
            s.s2b = 833;

            /**/
            if (round == 2)
            {
                t     = 3;
                s.t1b = 5199;
            }
            else
            {
                t     = 6;
                s.t1b = 4927;
            }
        }
        else if (wbytes == (size_t)5202)
        {
            /* r2, 8-7, partial/1 */
            if (MEMCMP(wire, dil__pkcs8_87r2p1_pfx,
                       sizeof(dil__pkcs8_87r2p1_pfx)))
            {
                break;
            }

            t     = 3;
            s.s2b = 833;
            s.t0b = 1606;
        }
        else if (wbytes == dil__sections[2 - 1].pkcs8b)
        {
            /* r2, 6-5, full */
            if (MEMCMP(wire, dil__pkcs8_65r2_pfx, sizeof(dil__pkcs8_65r2_pfx)))
            {
                break;
            }

            t     = 2;
            s.s2b = 641;
            s.t0b = 1222;
            s.t1b = 3919;
        }
        else if (wbytes == (size_t)3922)
        {
            /* r2, 6-5, partial/1 */
            if (MEMCMP(wire, dil__pkcs8_65r2p1_pfx,
                       sizeof(dil__pkcs8_65r2p1_pfx)))
            {
                break;
            }

            t     = 2;
            s.s2b = 641;
            s.t0b = 1222;
        }
        else if (wbytes == dil__sections[5 - 1].pkcs8b)
        {
            /* r3, 6-5, full */
            s.s1b = 140;

            if (MEMCMP(wire, dil__pkcs8_65r3_pfx, sizeof(dil__pkcs8_65r3_pfx)))
            {
                break;
            }

            round = 3;
            t     = 5;
            s.s2b = 785;
            s.t0b = 1558;
            s.t1b = 4063;
        }
        else if (wbytes == dil__sections[1 - 1].pkcs8b)
        {
            /* r2, 5-4, full */
            if (MEMCMP(wire, dil__pkcs8_54r2_pfx, sizeof(dil__pkcs8_54r2_pfx)))
            {
                break;
            }

            t     = 1;
            s.s2b = 673;
            s.t0b = 1318;
            s.t1b = 3567;
        }
        else if (wbytes == (size_t)3570)
        {
            /* r2, 5-4, partial/1 */
            if (MEMCMP(wire, dil__pkcs8_54r2p1_pfx,
                       sizeof(dil__pkcs8_54r2p1_pfx)))
            {
                break;
            }

            t     = 1;
            s.s2b = 673;
            s.t0b = 1318;
        }
        else if (wbytes == dil__sections[4 - 1].pkcs8b)
        {
            /* r3, 4-4, full */
            if (MEMCMP(wire, dil__pkcs8_44r3_pfx, sizeof(dil__pkcs8_44r3_pfx)))
            {
                break;
            }

            round = 3;
            t     = 4;
            s.s1b = 140;
            s.s2b = 529;
            s.t0b = 918;
            s.t1b = 2591;
        }

        /* no match, falling through with default wr 'no match' */
    }
    while (0);

    if (!t || (t > ARRAY_ELEMS(dil__sections)))
    {
        return 0;
    }

    --t; /* -> zero-based index */

    wr = dil__sections[t].prvb;

    s.nonce = is_bitstr_at(wire, wbytes, s.nonce, dil__sections[t].nonceb);
    s.key   = is_bitstr_at(wire, wbytes, s.key, dil__sections[t].keyb);
    s.prf   = is_bitstr_at(wire, wbytes, s.prf, dil__sections[t].prfb);
    s.s1b   = is_bitstr_at(wire, wbytes, s.s1b, dil__sections[t].s1b);
    s.s2b   = is_bitstr_at(wire, wbytes, s.s2b, dil__sections[t].s2b);
    s.t0b   = is_bitstr_at(wire, wbytes, s.t0b, dil__sections[t].t0b);

    if (!s.t1b)
    {
        return 0;
    }

    if (s.t1b)
    {
        s.t1b = is_bitstr_at(wire, wbytes, s.t1b, dil__sections[t].t1b);
    }

    do
    {
        if (!is_nonempty_dilstruct(&s))
        {
            wr = 0; /* valid-looking frame with invalid internals */
            break;
        }

        /*-----  special case: PKCS8-to-raw public key  ---------------------*/

        if (spec == CRS__SPC_PRV2PUB)
        {
            /* PUB == <nonce || T1> */
            if (!s.t1b)
            {
                wr = (size_t)MLCA_EMISSING;
                break;
            }

            wr = dil__sections[t].nonceb + dil__sections[t].t1b;
            /* raw .PUB at [s.t1b, wr] */
        }
        else if (spec)
        {
            wr = (size_t)MLCA_ENSUPPORT;
            break;
        }

        /*-----  /special case  ---------------------------------------------*/

        if (wr && prv && (pbytes < wr))
        {
            wr = (size_t)MLCA_ETOOSMALL; /* 'does not fit' */
            break;
        }

        if (type)
        {
            *type = dil__sections[t].type;
        }

        if (wr && prv && is_nonempty_dilstruct(&s))
        {
            size_t i = 0;
            /* raw concatenated fields */

            MEMMOVE(prv, wire + s.nonce, dil__sections[t].nonceb);
            i += dil__sections[t].nonceb;

            if (spec != CRS__SPC_PRV2PUB)
            {
                MEMMOVE(prv + i, wire + s.key, dil__sections[t].keyb);
                i += dil__sections[t].keyb;

                MEMMOVE(prv + i, wire + s.prf, dil__sections[t].prfb);
                i += dil__sections[t].prfb;

                MEMMOVE(prv + i, wire + s.s1b, dil__sections[t].s1b);
                i += dil__sections[t].s1b;

                MEMMOVE(prv + i, wire + s.s2b, dil__sections[t].s2b);
                i += dil__sections[t].s2b;

                MEMMOVE(prv + i, wire + s.t0b, dil__sections[t].t0b);
                i += dil__sections[t].t0b;

                /* skipping .t1b is not an oversight: that is
                 * an optional, public-key field which is just
                 * padded to the private-key PKCS8 by default
                 */
            }
            else
            {
                MEMMOVE(prv + i, wire + s.t1b, dil__sections[t].t1b);
                i += dil__sections[t].t1b;
                /* PKCS8-to-public */
            }

            /* opportunistic: write trailing type as BE32
             *
             * checking validity(wr) is redundant
             * please do not comment on it
             */
            if (prv && (wr + CRS_WTYPE_BYTES <= pbytes))
            {
                MSBF4_WRITE(prv + wr, dil__sections[t].type);
            }
        }
    }
    while (0);

    return wr;
}
#endif /*-----  /delimiter: ASN.1/BER  --------------------------------*/

/*--------------------------------------
 * does not check 'type' validity; call only after verification
 *
 * currently, type is either  <round> 0 <K>  or <round> <K> <L>
 *
 * expect this 'function' to be cheap, no need to cache etc.
 */
CRS_STATIC unsigned int dil_type2k(unsigned int type)
{
    if (type & 0xf0)
    {
        return ((type >> 4) & 0x0f); /* <K> <L> */
    }
    else
    {
        return (type & 0x0f); /* 0 <K> */
    }
}

/*--------------------------------------
 * does not check 'type' validity; call only after verification
 *
 * currently, type is either  <round> 0 <K>  or <round> <K> <L>
 * K == L-1  for all variants of the first type
 *
 * expect this 'function' to be cheap, no need to cache etc.
 */
CRS_STATIC unsigned int dil_type2l(unsigned int type)
{
    if (type & 0xf0)
    {
        return type & 0x0f; /* <K> <L> */
    }
    else
    {
        return ((type >> 4) & 0x0f) - 1; /* 0 <K> -> L == K-1 */
    }
}

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*- Kyber ------*/
/*--------------------------------------
 * does not check 'type' validity; call only after verification
 *
 * expect this 'function' to be cheap, no need to cache etc.
 */
CRS_STATIC unsigned int kyb_type2k(unsigned int type)
{
    switch (type)
    {
        case MLCA_ID_KYB3_R2:
        case MLCA_ID_KYB3_R3:
        case MLCA_ID_KYB_MLKEM_768:
            return 3; /* Kyber-768 */

        case MLCA_ID_KYB4_R2:
        case MLCA_ID_KYB4_R3:
        case MLCA_ID_KYB_MLKEM_1024:
            return 4; /* Kyber-1024 */

        default:
            return 0;
    }
}
#endif /* Kyber */

/*--------------------------------------
 * does not check 'type' validity; call only after verification
 */
#if 0
CRS_STATIC unsigned int dil_type2eta(unsigned int type)
{
    switch (type)
    {
        case MLCA_ID_DIL3_R2:
        case MLCA_ID_DIL3_R2_RAW:
            return 5;

        case MLCA_ID_DIL4_R2:
        case MLCA_ID_DIL4_R2_RAW:
            return 3;

        case MLCA_ID_DIL5_R2:
        case MLCA_ID_DIL2_R3:
        case MLCA_ID_DIL5_R3:
        case MLCA_ID_DIL5_R2_RAW:
        case MLCA_ID_DIL_MLDSA_44:
        case MLCA_ID_DIL_MLDSA_87:
            return 2;

        case MLCA_ID_DIL3_R3:
        case MLCA_ID_DIL_MLDSA_65:
            return 4;

        default:
            return 0;
    }
}
#endif

/*--------------------------------------
 * does not check 'type' validity; call only after verification
 */
CRS_STATIC unsigned int dil_type2round(unsigned int type)
{
    switch (type)
    {
        case MLCA_ID_DIL3_R2:
        case MLCA_ID_DIL4_R2:
        case MLCA_ID_DIL5_R2:
        case MLCA_ID_DIL3_R2_RAW:
        case MLCA_ID_DIL4_R2_RAW:
        case MLCA_ID_DIL5_R2_RAW:
            return 2;

        case MLCA_ID_DIL2_R3:
        case MLCA_ID_DIL3_R3:
        case MLCA_ID_DIL5_R3:
            return 3;

        case MLCA_ID_DIL_MLDSA_44:
        case MLCA_ID_DIL_MLDSA_65:
        case MLCA_ID_DIL_MLDSA_87:
            return 4;

        default:
            return 0;
    }
}

#if 0
CRS_STATIC unsigned int kyb_type2round(unsigned int type)
{
    switch (type)
    {
        case MLCA_ID_KYB3_R2:
        case MLCA_ID_KYB4_R2:
            return 2;

        case MLCA_ID_KYB3_R3:
        case MLCA_ID_KYB4_R3:
            return 3;

        case MLCA_ID_KYB_MLKEM_768:
        case MLCA_ID_KYB_MLKEM_1024:
            return 4;

        default:
            return 0;
    }
}
#endif

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*- Kyber ------*/
/*--------------------------------------
 * a few un/packing fns for Kyber are collected to one spot
 * resolve forward references
 */
typedef struct
{
    kpoly vec[KYB_VECT_MAX];
} kpolyvec_max;
/**/
CRS_STATIC void kpolyvec_compress(unsigned char* r, size_t rbytes,
                                  kpolyvec_max* a, unsigned int kyb_k);
CRS_STATIC void r3_kpolyvec_compress(unsigned char* r, size_t rbytes,
                                     kpolyvec_max* a, unsigned int kyb_k);
/**/
CRS_STATIC void kpolyvec_decompress(kpolyvec_max* r, unsigned int kyb_k,
                                    const unsigned char* a, size_t abytes);
CRS_STATIC void r3_kpolyvec_decompress(kpolyvec_max* r, unsigned int kyb_k,
                                       const unsigned char* a, size_t abytes);
#endif /* Kyber */

//--------------------------------------
// include "polyvec-include.h" /* size-specialized fn set */
#include <securerom/contrib/polyvec-include.h>

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*- Kyber ------*/

/*************************************************
 * Description: Compress and serialize vector of polynomials
 * Arguments:   - uint8_t *r: pointer to output byte array
 *                            (needs space for KYBER_POLYVECCOMPRESSEDBYTES)
 *              - polyvec *a: pointer to input vector of polynomials
 **************************************************/
CRS_STATIC void kpolyvec_compress(unsigned char* r, size_t rbytes,
                                  kpolyvec_max* a, unsigned int kyb_k)
{
    unsigned int i, j, k;
    uint64_t     d0;

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_csubq((kpolyvec3*)a);
            break;

        case 4:
            kpolyvec4_csubq((kpolyvec4*)a);
            break;
    }

    if (rbytes == (kyb_k * 352))
    {
        uint16_t t[8];

        for (i = 0; i < kyb_k; i++)
        {
            for (j = 0; j < KYB_N / 8; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    t[k] = a->vec[i].coeffs[8 * j + k];
                    // t[k] = ((((uint32_t)a->vec[i].coeffs[8*j+k] << 11) +
                    // KYB_Q/2)
                    //                 /KYB_Q) & 0x7ff;
                    //  ((u << 11) + KYB_Q/2) / KYB_Q ~=~ (((u << 11) + KYB_Q/2)
                    //  * (2^31 / KYB_Q)) >> 31
                    d0 = t[k];
                    d0 <<= 11;
                    d0 += 1664;
                    d0 *= 645084;
                    d0 >>= 31;

                    t[k] = d0 & 0x7ff;
                }

                r[0]  = (t[0] >> 0);
                r[1]  = (t[0] >> 8) | (t[1] << 3);
                r[2]  = (t[1] >> 5) | (t[2] << 6);
                r[3]  = (t[2] >> 2);
                r[4]  = (t[2] >> 10) | (t[3] << 1);
                r[5]  = (t[3] >> 7) | (t[4] << 4);
                r[6]  = (t[4] >> 4) | (t[5] << 7);
                r[7]  = (t[5] >> 1);
                r[8]  = (t[5] >> 9) | (t[6] << 2);
                r[9]  = (t[6] >> 6) | (t[7] << 5);
                r[10] = (t[7] >> 3);

                r += 11;
            }
        }
    }
    else if (rbytes == (kyb_k * 320))
    {
        uint16_t t[4];

        for (i = 0; i < kyb_k; i++)
        {
            for (j = 0; j < KYB_N / 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    t[k] = a->vec[i].coeffs[4 * j + k];
                    // t[k] = ((((uint32_t)a->vec[i].coeffs[4*j+k] << 10) +
                    // KYB_Q/2)
                    //                 / KYB_Q) & 0x3ff;
                    //  ((u << 10) + KYB_Q/2) / KYB_Q ~=~ (((u << 10) + KYB_Q/2
                    //  + 1) * (2^32 / KYB_Q)) >> 32
                    d0 = t[k];
                    d0 <<= 10;
                    d0 += 1665;
                    d0 *= 1290167;
                    d0 >>= 32;

                    t[k] = d0 & 0x3ff;
                }

                r[0] = (t[0] >> 0);
                r[1] = (t[0] >> 8) | (t[1] << 2);
                r[2] = (t[1] >> 6) | (t[2] << 4);
                r[3] = (t[2] >> 4) | (t[3] << 6);
                r[4] = (t[3] >> 2);
                r += 5;
            }
        }
    }
}

CRS_STATIC void r3_kpolyvec_compress(unsigned char* r, size_t rbytes,
                                     kpolyvec_max* a, unsigned int kyb_k)
{
    unsigned int i, j, k;
    uint64_t     d0;

    if (rbytes == (kyb_k * 352))
    {
        uint16_t t[8];

        for (i = 0; i < kyb_k; i++)
        {
            for (j = 0; j < KYB_N / 8; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    t[k] = a->vec[i].coeffs[8 * j + k];
                    t[k] += ((int16_t)t[k] >> 15) & KYB_Q;
                    // t[k]  = ((((uint32_t)t[k] << 11) + KYB_Q/2)/KYB_Q) &
                    // 0x7ff;
                    //  ((u << 11) + KYB_Q/2) / KYB_Q ~=~ (((u << 11) + KYB_Q/2
                    //  + 1) * (2^31 / KYB_Q)) >> 31
                    d0 = (uint32_t)t[k] << 11;
                    d0 += 1664;
                    d0 *= 645084;
                    d0 >>= 31;

                    t[k] = d0 & 0x7ff;
                }

                r[0]  = (t[0] >> 0);
                r[1]  = (t[0] >> 8) | (t[1] << 3);
                r[2]  = (t[1] >> 5) | (t[2] << 6);
                r[3]  = (t[2] >> 2);
                r[4]  = (t[2] >> 10) | (t[3] << 1);
                r[5]  = (t[3] >> 7) | (t[4] << 4);
                r[6]  = (t[4] >> 4) | (t[5] << 7);
                r[7]  = (t[5] >> 1);
                r[8]  = (t[5] >> 9) | (t[6] << 2);
                r[9]  = (t[6] >> 6) | (t[7] << 5);
                r[10] = (t[7] >> 3);
                r += 11;
            }
        }
    }
    else if (rbytes == (kyb_k * 320))
    {
        uint16_t t[4];

        for (i = 0; i < kyb_k; i++)
        {
            for (j = 0; j < KYB_N / 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    t[k] = a->vec[i].coeffs[4 * j + k];
                    t[k] += ((int16_t)t[k] >> 15) & KYB_Q;
                    // t[k] = ((((uint32_t)t[k] << 10) + KYB_Q / 2) / KYB_Q) &
                    // 0x3ff;
                    //  ((u << 10) + KYB_Q/2) / KYB_Q ~=~ (((u << 10) + KYB_Q/2
                    //  + 1) * (2^32 / KYB_Q)) >> 32
                    d0 = (uint32_t)t[k] << 10;
                    d0 += 1665;
                    d0 *= 1290167;
                    d0 >>= 32;

                    t[k] = d0 & 0x3ff;
                }

                r[0] = (t[0] >> 0);
                r[1] = (t[0] >> 8) | (t[1] << 2);
                r[2] = (t[1] >> 6) | (t[2] << 4);
                r[3] = (t[2] >> 4) | (t[3] << 6);
                r[4] = (t[3] >> 2);
                r += 5;
            }
        }
    }
}

/*************************************************
 * Description: De-serialize and decompress vector of polynomials;
 *              approximate inverse of polyvec_compress
 *
 * Arguments:   - polyvec *r:       pointer to output vector of polynomials
 *              - const uint8_t *a: pointer to input byte array
 *                                  (of length KYBER_POLYVECCOMPRESSEDBYTES)
 **************************************************/
CRS_STATIC void kpolyvec_decompress(kpolyvec_max* r, unsigned int kyb_k,
                                    const unsigned char* a, size_t abytes)
{
    unsigned int i, j, k;

    if (abytes == (kyb_k * 352))
    {
        uint16_t t[8];

        for (i = 0; i < kyb_k; i++)
        {
            for (j = 0; j < KYB_N / 8; j++)
            {
                t[0] = (a[0] >> 0) | ((uint16_t)a[1] << 8);
                t[1] = (a[1] >> 3) | ((uint16_t)a[2] << 5);
                t[2] = (a[2] >> 6) | ((uint16_t)a[3] << 2) |
                       ((uint16_t)a[4] << 10);
                t[3] = (a[4] >> 1) | ((uint16_t)a[5] << 7);
                t[4] = (a[5] >> 4) | ((uint16_t)a[6] << 4);
                t[5] =
                    (a[6] >> 7) | ((uint16_t)a[7] << 1) | ((uint16_t)a[8] << 9);
                t[6] = (a[8] >> 2) | ((uint16_t)a[9] << 6);
                t[7] = (a[9] >> 5) | ((uint16_t)a[10] << 3);
                a += 11;

                for (k = 0; k < 8; k++)
                    r->vec[i].coeffs[8 * j + k] =
                        ((uint32_t)(t[k] & 0x7FF) * KYB_Q + 1024) >> 11;
            }
        }
    }
    else if (abytes == (kyb_k * 320))
    {
        uint16_t t[4];

        for (i = 0; i < kyb_k; i++)
        {
            for (j = 0; j < KYB_N / 4; j++)
            {
                t[0] = (a[0] >> 0) | ((uint16_t)a[1] << 8);
                t[1] = (a[1] >> 2) | ((uint16_t)a[2] << 6);
                t[2] = (a[2] >> 4) | ((uint16_t)a[3] << 4);
                t[3] = (a[3] >> 6) | ((uint16_t)a[4] << 2);
                a += 5;

                for (k = 0; k < 4; k++)
                    r->vec[i].coeffs[4 * j + k] =
                        ((uint32_t)(t[k] & 0x3FF) * KYB_Q + 512) >> 10;
            }
        }
    }
}

CRS_STATIC void r3_kpolyvec_decompress(kpolyvec_max* r, unsigned int kyb_k,
                                       const unsigned char* a, size_t abytes)
{
    kpolyvec_decompress(r, kyb_k, a, abytes);
}
#endif /*-----  /delimiter: Kyber  ------------------------------------*/

#if !defined(NO_CRYSTALS_SIG) /*-----  delimiter: Dilithium  --------------*/
#if 0
/*************************************************
 * Bit-pack signature sig = (z, h, c).
 * Arguments:   - uint8_t sig[]: output byte array
 *              - const polyvecl *z: pointer to vector z
 *              - const polyveck *h: pointer to hint vector h
 *              - const poly *c: pointer to challenge polynomial
 *
 * accesses only necessary number of elements of z[] and h[]
 **************************************************/
CRS_STATIC size_t dil_r2sig2wire(unsigned char* sig, size_t sbytes,
                                 const polyvec_max* z, const polyvec_max* h,
                                 const poly* c, unsigned int dil_k)
{
    unsigned int i, j, k = 0, omega = dil_omega(dil_k, 2);
    size_t       sb = dil_signature_bytes(dil_k, dil_k - 1, 2);
    uint64_t     signs, mask;

    if (!sb || !omega)
    {
        return 0;
    }

    if (sbytes < sb)
    {
        return 0;
    }

    MEMSET(sig, 0, sb);

    for (i = 0; i < (dil_k - 1); ++i) /* ... < L */
    {
        polyz_pack(sig + i * DIL_POLYZ_PACKEDBYTES, &(z->vec[i]));
    }

    sig += (dil_k - 1) * DIL_POLYZ_PACKEDBYTES; /* L * ... */

    /* Encode h */
    for (i = 0; i < dil_k; ++i)
    {
        for (j = 0; j < DIL_N; ++j)
        {
            if (h->vec[i].coeffs[j] != 0)
            {
                sig[k++] = j;
            }
        }

        sig[omega + i] = k;
    }

#if 0

    while (k < omega)
    {
        sig[k++] = 0;    /* was cleared at start */
    }

#endif

    sig += omega + dil_k;

    /* Encode c */
    signs = 0;
    mask  = 1;

    for (i = 0; i < DIL_N / 8; ++i)
    {
        sig[i] = 0;

        for (j = 0; j < 8; ++j)
        {
            if (c->coeffs[8 * i + j] != 0)
            {
                sig[i] |= (1U << j);

                if (c->coeffs[8 * i + j] == (DIL_Q - 1))
                {
                    signs |= mask;
                }

                mask <<= 1;
            }
        }
    }

    sig += DIL_N / 8;

    for (i = 0; i < 8; ++i)
    {
        sig[i] = signs >> 8 * i;
    }

    return sb;
}

/*************************************************
 * Bit-pack signature sig = (z, h, c).
 * Arguments:   - uint8_t sig[]: output byte array
 *              - chash[ DIL_SEEDBYTES ]: challenge hash
 *              - const polyvecl *z: pointer to vector z
 *              - const polyveck *h: pointer to hint vector h
 * accesses only necessary number of elements of z[] and h[]
 *
 * sig[] and chash[] MAY be the same buffer; other overlap is undefined
 **************************************************/
CRS_STATIC size_t dil_r3sig2wire(unsigned char* sig, size_t sbytes,
                                 const unsigned char* chash,
                                 const spolyvec_max* z, const spolyvec_max* h,
                                 unsigned int dil_k, unsigned int dil_l)
{
    unsigned int i, j, k = 0, omega = dil_omega(dil_k, 3);
    size_t       sb = dil_signature_bytes(dil_k, dil_l, 3),
                 pzb      = dil_r3k2polyz_bytes(dil_k);

    if (!sb || !omega || !pzb)
    {
        return 0;
    }

    if (sbytes < sb)
    {
        return 0;
    }

    if ((const unsigned char*)sig != chash)
    {
        MEMMOVE(sig, chash, DIL_SEEDBYTES);
    }

    /* tolerate in-place write (NOP)
     * only memset(0) below
     */
    sig += DIL_SEEDBYTES;

    MEMSET(sig, 0, sb - DIL_SEEDBYTES);

    for (i = 0; i < dil_l; ++i) /* ... < L */
    {
        spolyz_pack(sig + i * pzb, &(z->vec[i]), dil_k);
    }

    sig += dil_l * pzb;

    /* Encode h */
    for (i = 0; i < dil_k; ++i)
    {
        for (j = 0; j < DIL_N; ++j)
        {
            if (h->vec[i].coeffs[j] != 0)
            {
                sig[k] = j;
                ++k;
            }
        }

        sig[omega + i] = k;
    }

    return sb;
}

/*************************************************
 * Bit-pack signature sig = (z, h, c).
 * Arguments:   - uint8_t sig[]: output byte array
 *              - chash[ CTILBYTES ]: challenge hash
 *              - const polyvecl *z: pointer to vector z
 *              - const polyveck *h: pointer to hint vector h
 * accesses only necessary number of elements of z[] and h[]
 *
 * sig[] and chash[] MAY be the same buffer; other overlap is undefined
 **************************************************/
CRS_STATIC size_t dil_mldsasig2wire(unsigned char* sig, size_t sbytes,
                                    const unsigned char* chash,
                                    const spolyvec_max*  z,
                                    const spolyvec_max* h, unsigned int dil_k,
                                    unsigned int dil_l)
{
    unsigned int i, j, k = 0, omega = dil_omega(dil_k, 3);
    size_t       sb  = dil_signature_bytes(dil_k, dil_l, 4),
                 pzb       = dil_r3k2polyz_bytes(dil_k);
    size_t ctilbytes = dil_mldsa_ctilbytes(dil_k);

    if (!sb || !omega || !pzb)
    {
        return 0;
    }

    if (sbytes < sb)
    {
        return 0;
    }

    if ((const unsigned char*)sig != chash)
    {
        MEMMOVE(sig, chash, ctilbytes);
    }

    /* tolerate in-place write (NOP)
     * only memset(0) below
     */
    sig += ctilbytes;

    MEMSET(sig, 0, sb - ctilbytes);

    for (i = 0; i < dil_l; ++i) /* ... < L */
    {
        spolyz_pack(sig + i * pzb, &(z->vec[i]), dil_k);
    }

    sig += dil_l * pzb;

    /* Encode h */
    for (i = 0; i < dil_k; ++i)
    {
        for (j = 0; j < DIL_N; ++j)
        {
            if (h->vec[i].coeffs[j] != 0)
            {
                sig[k] = j;
                ++k;
            }
        }

        sig[omega + i] = k;
    }

    return sb;
}

/*------------------------------------
 * Unpack signature sig = (z, h, c); round 2
 * Arguments:   - polyvecl *z: pointer to output vector z
 *              - polyveck *h: pointer to output hint vector h
 *              - poly *c: pointer to output challenge polynomial
 *              - const uint8_t sig[]: byte array containing
 *                bit-packed signature
 *
 * Returns >0 in case of malformed signature; otherwise 0.
 *
 * accesses only necessary number of elements of z[] and h[],
 * any of the polyvec<...> vectors MAY be used with proper dil_k
 **************************************************/
CRS_STATIC int r2_wire2sig(polyvec_max* z, polyvec_max* h, poly* c,
                           unsigned int dil_k, const unsigned char* sig,
                           size_t sbytes)
{
    size_t       sb = dil_signature_bytes(dil_k, dil_k - 1, 2);
    unsigned int i, j, k, omega = dil_omega(dil_k, 2);
    uint64_t     signs;

    if (sb != sbytes)
    {
        return 1;
    }

    for (i = 0; i < dil_k - 1; ++i) /* L */
    {
        polyz_unpack(&(z->vec[i]), sig + i * DIL_POLYZ_PACKEDBYTES);
    }

    sig += (dil_k - 1) * DIL_POLYZ_PACKEDBYTES; /* L * ... */

    /* Decode h */
    k = 0;

    for (i = 0; i < dil_k; ++i)
    {
        for (j = 0; j < DIL_N; ++j)
        {
            h->vec[i].coeffs[j] = 0;
        }

        if ((sig[omega + i] < k) || (sig[omega + i] > omega))
        {
            return 1;
        }

        for (j = k; j < sig[omega + i]; ++j)
        {
            /* Coefficients are ordered for strong unforgeability */

            if ((j > k) && (sig[j] <= sig[j - 1]))
            {
                return 1;
            }

            h->vec[i].coeffs[sig[j]] = 1;
        }

        k = sig[omega + i];
    }

    /* Extra indices are zero for strong unforgeability */
    for (j = k; j < omega; ++j)
    {
        if (sig[j])
        {
            return 1;
        }
    }

    sig += omega + dil_k;

    /* Decode c */
    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = 0;
    }

    signs = 0;

    for (i = 0; i < 8; ++i)
    {
        signs |= ((uint64_t)sig[DIL_N / 8 + i]) << 8 * i;
    }

    /* Extra sign bits are zero for strong unforgeability */

    if (signs >> 60)
    {
        return 1;
    }

    for (i = 0; i < DIL_N / 8; ++i)
    {
        for (j = 0; j < 8; ++j)
        {
            if ((sig[i] >> j) & 0x01)
            {
                c->coeffs[8 * i + j] = 1;
                c->coeffs[8 * i + j] ^= -(signs & 1) & (1 ^ (DIL_Q - 1));

                signs >>= 1;
            }
        }
    }

    return 0;
}

/*------------------------------------
 * Unpack signature sig = (z, h, c); round3
 * Arguments:   - chash: challenge hash  [DIL_SEEDBYTES]
 *              - polyvecl *z: pointer to output vector z
 *              - polyveck *h: pointer to output hint vector h
 *              - const uint8_t sig[]: byte array containing
 *                bit-packed signature
 *
 * Returns >0 in case of malformed signature; otherwise 0.
 *
 * accesses only necessary number of elements of z[] and h[],
 * 'sig' and 'chash' may be the same buffer; other overlap is undefined
 **************************************************/
CRS_STATIC int r3_wire2sig(unsigned char* chash, /* DIL_SEEDBYTES */
                           spolyvec_max* z, spolyvec_max* h, unsigned int dil_k,
                           unsigned int dil_l, const unsigned char* sig,
                           size_t sbytes)
{
    size_t sb  = dil_signature_bytes(dil_k, dil_l, 3),
           pzb = dil_r3k2polyz_bytes(dil_k);
    unsigned int i, j, k, omega = dil_omega(dil_k, 3);

    if (!sig || (sb != sbytes))
    {
        return 1;
    }

    if (!z || !h || !chash)
    {
        return 2;    /* should-not-happen */
    }

    if ((const unsigned char*)chash != sig)
    {
        MEMMOVE(chash, sig, DIL_SEEDBYTES);
    }

    sig += DIL_SEEDBYTES;

    for (i = 0; i < dil_l; ++i) /* L */
    {
        spolyz_unpack(&(z->vec[i]), sig + i * pzb, dil_k);
    }

    sig += dil_l * pzb; /* L * ... */

    /* Decode h */
    k = 0;

    for (i = 0; i < dil_k; ++i)
    {
        for (j = 0; j < DIL_N; ++j)
        {
            h->vec[i].coeffs[j] = 0;
        }

        if ((sig[omega + i] < k) || (sig[omega + i] > omega))
        {
            return 3;
        }

        for (j = k; j < sig[omega + i]; ++j)
        {
            /* Coefficients are ordered for strong unforgeability */

            if ((j > k) && (sig[j] <= sig[j - 1]))
            {
                return 4;
            }

            h->vec[i].coeffs[sig[j]] = 1;
        }

        k = sig[omega + i];
    }

    /* Extra indices are zero for strong unforgeability */
    for (j = k; j < omega; ++j)
    {
        if (sig[j])
        {
            return 5;
        }
    }

    sig += omega + dil_k;

    return 0;
}
#endif

/*------------------------------------
 * Unpack signature sig = (z, h, c); round3
 * Arguments:   - chash: challenge hash  [CTILBYTES]
 *              - polyvecl *z: pointer to output vector z
 *              - polyveck *h: pointer to output hint vector h
 *              - const uint8_t sig[]: byte array containing
 *                bit-packed signature
 *
 * Returns >0 in case of malformed signature; otherwise 0.
 *
 * accesses only necessary number of elements of z[] and h[],
 * 'sig' and 'chash' may be the same buffer; other overlap is undefined
 **************************************************/
CRS_STATIC int mldsa_wire2sig(unsigned char* chash, /* CTILBYTES */
                              spolyvec_max* z, spolyvec_max* h,
                              unsigned int dil_k, unsigned int dil_l,
                              const unsigned char* sig, size_t sbytes)
{
    size_t sb  = dil_signature_bytes(dil_k, dil_l, 4),
           pzb = dil_r3k2polyz_bytes(dil_k);
    unsigned int i, j, k, omega = dil_omega(dil_k, 3);
    size_t       ctilbytes = dil_mldsa_ctilbytes(dil_k);

    if (!sig || (sb != sbytes))
    {
        return 1;
    }

    if (!z || !h || !chash)
    {
        return 2;    /* should-not-happen */
    }

    if ((const unsigned char*)chash != sig)
    {
        MEMMOVE(chash, sig, ctilbytes);
    }

    sig += ctilbytes;

    for (i = 0; i < dil_l; ++i) /* L */
    {
        spolyz_unpack(&(z->vec[i]), sig + i * pzb, dil_k);
    }

    sig += dil_l * pzb; /* L * ... */

    /* Decode h */
    k = 0;

    for (i = 0; i < dil_k; ++i)
    {
        for (j = 0; j < DIL_N; ++j)
        {
            h->vec[i].coeffs[j] = 0;
        }

        if ((sig[omega + i] < k) || (sig[omega + i] > omega))
        {
            return 3;
        }

        for (j = k; j < sig[omega + i]; ++j)
        {
            /* Coefficients are ordered for strong unforgeability */

            if ((j > k) && (sig[j] <= sig[j - 1]))
            {
                return 4;
            }

            h->vec[i].coeffs[sig[j]] = 1;
        }

        k = sig[omega + i];
    }

    /* Extra indices are zero for strong unforgeability */
    for (j = k; j < omega; ++j)
    {
        if (sig[j])
        {
            return 5;
        }
    }

    sig += omega + dil_k;

    return 0;
}

#endif /* !NO_CRYSTALS_SIG, /Dilithium  --------------*/
#endif /*-----  /delimiter: polyvec, some of packing.c  ---------------*/

#if !defined(NO_CRYSTALS_SIG) /*-----  delimiter: Dilithium  --------------*/

typedef struct
{
    unsigned char seed[2 * DIL_SEEDBYTES + 3 * DIL_MAX_CRHBYTES];
    polyvec_max   s1, s2;

    polyvec_max   t0, t1;

    polyvec_max   w0, w1;

    polyvec_max   h, y, z;

    poly          c, chat;

    Keccak_state  state;
} DilState;

#if 0
/*-------------------------------------------------
 * Description: Implementation of H. Samples polynomial with 60 nonzero
 *              coefficients in {-1,1} using the output stream of
 *              SHAKE256(mu|w1).
 *
 * Arguments:   - poly *c: pointer to output polynomial
 *              - const uint8_t mu[]: byte array containing mu
 *              - const polyveck *w1: pointer to vector w1
 **************************************************/
CRS_STATIC void dil_challenge(poly* c, const uint8_t mu[DIL_CRHBYTES],
                              const polyvec_max* w1, unsigned int k)
{
    unsigned char buf[DIL_CRHBYTES + DIL_VECT_MAX * DIL_POLYW1_PACKEDBYTES];
    unsigned int  i, b, pos;
    uint64_t      signs = 0;
    Keccak_state  state;

    // MEMMOVE(buf, mu, DIL_CRHBYTES);
    memmove(buf, mu, DIL_CRHBYTES);

    for (i = 0; i < k; ++i)
    {
        polyw1_pack(buf + DIL_CRHBYTES + i * DIL_POLYW1_PACKEDBYTES,
                    &(w1->vec[i]));
    }

    shake256_init(&state);
    shake256_absorb(&state, buf, DIL_CRHBYTES + k * DIL_POLYW1_PACKEDBYTES);
    shake256_finalize(&state);
    shake256_squeezeblocks(buf, 1, &state);

    signs = 0;

    for (i = 0; i < 8; ++i)
    {
        signs |= (uint64_t)buf[i] << 8 * i;
    }

    pos = 8;

    for (i = 0; i < DIL_N; ++i)
    {
        c->coeffs[i] = 0;
    }

    for (i = 196; i < 256; ++i)
    {
        do
        {
            if (pos >= SHAKE256_RATE)
            {
                shake256_squeezeblocks(buf, 1, &state);
                pos = 0;
            }

            b = buf[pos++];
        }
        while (b > i);

        c->coeffs[i] = c->coeffs[b];
        c->coeffs[b] = 1;
        c->coeffs[b] ^= -((uint32_t)signs & 1) & (1 ^ (DIL_Q - 1));
        signs >>= 1;
    }

    shake256_wipe(&state);
}
#endif

#if !defined(NO_DILITHIUM_SIGN) /*-----  delimiter: Dilithium sign  --------------*/
/*************************************************
 * Description: Computes signature (round 2)
 * Arguments:   - uint8_t *sig:   pointer to output signature (of length
 *CRYPTO_BYTES)
 *              - size_t siglen:  max.available/written signature (in/output)
 *              - uint8_t *m:     pointer to message to be signed
 *              - size_t mlen:    length of message
 *              - uint8_t *sk:    pointer to bit-packed secret key
 * Returns 0 (failure) or >0 (written bytecount)
 **************************************************/
CRS_STATIC size_t r2_sign(const void* pKey, unsigned char* sig, size_t siglen,
                          const uint8_t* m, size_t mlen, const uint8_t* sk,
                          size_t skbytes, unsigned int type)
{
    unsigned int i, n = 0, K = 0, beta;
    uint8_t      seedbuf[2 * DIL_SEEDBYTES + 3 * DIL_CRHBYTES];
    uint8_t*     rho, *tr, *key, *mu, *rhoprime;
    uint16_t     nonce = 0;

    struct sign_mat
    {
        poly         c, chat;
        polyvec_max  mat[DIL_VECT_MAX]; /* using only K * L */
        polyvec_max  s1, y, z;          /* L */
        polyvec_max  t0, s2, w1, w0, h; /* K */
        Keccak_state state;
    };
    struct sign_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    (void)type;

    // layout: [key || mu] MUST be consecutive

    rho      = seedbuf;
    tr       = rho + DIL_SEEDBYTES;
    key      = tr + DIL_CRHBYTES;
    mu       = key + DIL_SEEDBYTES;
    rhoprime = mu + DIL_CRHBYTES;

    if (!type)
    {
        type = dil__prvbytes2type(skbytes);
    }

    K = dil_type2k(type);

    /**/
    if ((dil_type2round(type) != 2) || !K)
    {
        return 0;
    }

    beta = dil_k2beta(K, 2);

    // unpack_sk(rho, key, tr, &s1, &s2, &t0, sk);

    switch (K)
    {
        /* s1 is L-sized; s2+t0 are K-sized */
        case 5:
            unpack_prv5(rho, key, tr, (polyvec4*)&pMat->s1, (polyvec5*)&pMat->s2,
                        (polyvec5*)&pMat->t0, sk);
            break;

        case 6:
            unpack_prv6(rho, key, tr, (polyvec5*)&pMat->s1, (polyvec6*)&pMat->s2,
                        (polyvec6*)&pMat->t0, sk);
            break;

        case 8:
            unpack_prv8(rho, key, tr, (polyvec7*)&pMat->s1, (polyvec8*)&pMat->s2,
                        (polyvec8*)&pMat->t0, sk);
            break;
    }

    /* mu[ DIL_CRHBYTES ] := CRH(tr, msg) */
    shake256_init(&pMat->state);
    shake256_absorb(&pMat->state, tr, DIL_CRHBYTES);
    shake256_absorb(&pMat->state, m, mlen);
    shake256_finalize(&pMat->state);
    shake256_squeeze(mu, DIL_CRHBYTES, &pMat->state);

    dil_crh(rhoprime, DIL_CRHBYTES, key, DIL_SEEDBYTES + DIL_CRHBYTES);

    /* Expand matrix and transform vectors */
    switch (K)
    {
        case 5:
            expand_matrix_5x4(pMat->mat, rho);
            polyvec4_ntt((polyvec4*)&pMat->s1);  /* L */
            polyvec5_ntt((polyvec5*)&pMat->s2);  /* K */
            polyvec5_ntt((polyvec5*)&pMat->t0);
            break;

        case 6:
            expand_matrix_6x5(pMat->mat, rho);
            polyvec5_ntt((polyvec5*)&pMat->s1);  /* L */
            polyvec6_ntt((polyvec6*)&pMat->s2);  /* K */
            polyvec6_ntt((polyvec6*)&pMat->t0);
            break;

        case 8:
            expand_matrix_8x7(pMat->mat, rho);
            polyvec7_ntt((polyvec7*)&pMat->s1);  /* L */
            polyvec8_ntt((polyvec8*)&pMat->s2);  /* K */
            polyvec8_ntt((polyvec8*)&pMat->t0);
            break;
    }

REJECT:

    /* Sample intermediate vector y */
    for (i = 0; i < K - 1; ++i) /* L */
    {
        poly_uniform_gamma1m1(&(pMat->y.vec[i]), rhoprime, nonce++);
    }

    /* Matrix-vector multiplication */
    pMat->z = pMat->y;

    switch (K)
    {
        // K->L, +1 difference is not a typo
        case 5:
            polyvec4_ntt((polyvec4*)&pMat->z);
            break;

        case 6:
            polyvec5_ntt((polyvec5*)&pMat->z);
            break;

        case 8:
            polyvec7_ntt((polyvec7*)&pMat->z);
            break;
    }

    for (i = 0; i < K; ++i)
    {
        switch (K)
        {
            // K->L, +1 difference is not a typo
            case 5:
                polyvec4_pointwise_acc_montgomery(&(pMat->w1.vec[i]),
                                                  (const polyvec4*) & (pMat->mat[i]),
                                                  (const polyvec4*)&pMat->z);
                break;

            case 6:
                polyvec5_pointwise_acc_montgomery(&(pMat->w1.vec[i]),
                                                  (const polyvec5*) & (pMat->mat[i]),
                                                  (const polyvec5*)&pMat->z);
                break;

            case 8:
                polyvec7_pointwise_acc_montgomery(&(pMat->w1.vec[i]),
                                                  (const polyvec7*) & (pMat->mat[i]),
                                                  (const polyvec7*)&pMat->z);
                break;
        }

        poly_reduce(&(pMat->w1.vec[i]));
        poly_invntt_tomont(&(pMat->w1.vec[i]));
    }

    /* Decompose w and call the random oracle */

    switch (K)
    {
        case 5:
            polyvec5_csubq((polyvec5*)&pMat->w1);
            polyvec5_decompose((polyvec5*)&pMat->w1, (polyvec5*)&pMat->w0,
                               (polyvec5*)&pMat->w1);
            break;

        case 6:
            polyvec6_csubq((polyvec6*)&pMat->w1);
            polyvec6_decompose((polyvec6*)&pMat->w1, (polyvec6*)&pMat->w0,
                               (polyvec6*)&pMat->w1);
            break;

        case 8:
            polyvec8_csubq((polyvec8*)&pMat->w1);
            polyvec8_decompose((polyvec8*)&pMat->w1, (polyvec8*)&pMat->w0,
                               (polyvec8*)&pMat->w1);
            break;
    }

    dil_challenge(&pMat->c, mu, &pMat->w1, K);

    pMat->chat = pMat->c;
    poly_ntt256(&pMat->chat);

    /* Compute z, reject if it reveals secret */

    for (i = 0; i < K - 1; ++i)
    {
        /* L */
        poly_pointwise_montgomery(&(pMat->z.vec[i]), &pMat->chat,
                                  &(pMat->s1.vec[i]));
        poly_invntt_tomont(&(pMat->z.vec[i]));
    }

    {
        unsigned fail = 0;

        switch (K)
        {
            // -> L, so choices are off-by-one
            case 5:
                polyvec4_add((polyvec4*)&pMat->z, (const polyvec4*)&pMat->z,
                             (const polyvec4*)&pMat->y);
                polyvec4_freeze((polyvec4*)&pMat->z);
                fail = !!polyvec4_chknorm((const polyvec4*)&pMat->z,
                                          DIL_GAMMA1 - beta);
                break;

            case 6:
                polyvec5_add((polyvec5*)&pMat->z, (const polyvec5*)&pMat->z,
                             (const polyvec5*)&pMat->y);
                polyvec5_freeze((polyvec5*)&pMat->z);
                fail = !!polyvec5_chknorm((const polyvec5*)&pMat->z,
                                          DIL_GAMMA1 - beta);
                break;

            case 8:
                polyvec7_add((polyvec7*)&pMat->z, (const polyvec7*)&pMat->z,
                             (const polyvec7*)&pMat->y);
                polyvec7_freeze((polyvec7*)&pMat->z);
                fail = !!polyvec7_chknorm((const polyvec7*)&pMat->z,
                                          DIL_GAMMA1 - beta);
                break;
        }

        if (fail)
        {
            goto REJECT;
        }
    }

    /* Check that subtracting cs2 does not change high bits of w
     * and low bits do not reveal secret information */

    for (i = 0; i < K; ++i)
    {
        poly_pointwise_montgomery(&(pMat->h.vec[i]), &pMat->chat,
                                  &(pMat->s2.vec[i]));
        poly_invntt_tomont(&(pMat->h.vec[i]));
    }

    {
        unsigned int fail = 0;

        switch (K)
        {
            case 5:
                polyvec5_sub((polyvec5*)&pMat->w0, (const polyvec5*)&pMat->w0,
                             (const polyvec5*)&pMat->h);
                polyvec5_freeze((polyvec5*)&pMat->w0);
                fail = !!polyvec5_chknorm((const polyvec5*)&pMat->w0,
                                          DIL_GAMMA2 - beta);
                break;

            case 6:
                polyvec6_sub((polyvec6*)&pMat->w0, (const polyvec6*)&pMat->w0,
                             (const polyvec6*)&pMat->h);
                polyvec6_freeze((polyvec6*)&pMat->w0);
                fail = !!polyvec6_chknorm((const polyvec6*)&pMat->w0,
                                          DIL_GAMMA2 - beta);
                break;

            case 8:
                polyvec8_sub((polyvec8*)&pMat->w0, (const polyvec8*)&pMat->w0,
                             (const polyvec8*)&pMat->h);
                polyvec8_freeze((polyvec8*)&pMat->w0);
                fail = !!polyvec8_chknorm((const polyvec8*)&pMat->w0,
                                          DIL_GAMMA2 - beta);
                break;

            default:
                break;
        }

        if (fail)
        {
            goto REJECT;
        }
    }

    /* Compute hints for w1 */

    for (i = 0; i < K; ++i)
    {
        poly_pointwise_montgomery(&(pMat->h.vec[i]), &pMat->chat,
                                  &(pMat->t0.vec[i]));
        poly_invntt_tomont(&(pMat->h.vec[i]));
    }

    {
        unsigned int fail = 0;

        switch (K)
        {
            case 5:
                polyvec5_csubq((polyvec5*)&pMat->h);
                fail = !!polyvec5_chknorm((const polyvec5*)&pMat->h, DIL_GAMMA2);
                break;

            case 6:
                polyvec6_csubq((polyvec6*)&pMat->h);
                fail = !!polyvec6_chknorm((const polyvec6*)&pMat->h, DIL_GAMMA2);
                break;

            case 8:
                polyvec8_csubq((polyvec8*)&pMat->h);
                fail = !!polyvec8_chknorm((const polyvec8*)&pMat->h, DIL_GAMMA2);
                break;

            default:
                break;
        }

        if (fail)
        {
            goto REJECT;
        }
    }

    switch (K)
    {
        case 5:
            polyvec5_add((polyvec5*)&pMat->w0, (const polyvec5*)&pMat->w0,
                         (const polyvec5*)&pMat->h);
            polyvec5_csubq((polyvec5*)&pMat->w0);
            n = polyvec5_make_hint((polyvec5*)&pMat->h,
                                   (const polyvec5*)&pMat->w0,
                                   (const polyvec5*)&pMat->w1);
            break;

        case 6:
            polyvec6_add((polyvec6*)&pMat->w0, (const polyvec6*)&pMat->w0,
                         (const polyvec6*)&pMat->h);
            polyvec6_csubq((polyvec6*)&pMat->w0);
            n = polyvec6_make_hint((polyvec6*)&pMat->h,
                                   (const polyvec6*)&pMat->w0,
                                   (const polyvec6*)&pMat->w1);
            break;

        case 8:
            polyvec8_add((polyvec8*)&pMat->w0, (const polyvec8*)&pMat->w0,
                         (const polyvec8*)&pMat->h);
            polyvec8_csubq((polyvec8*)&pMat->w0);
            n = polyvec8_make_hint((polyvec8*)&pMat->h,
                                   (const polyvec8*)&pMat->w0,
                                   (const polyvec8*)&pMat->w1);
            break;

        default:
            break;
    }

    if (n > dil_omega(K, 2))
    {
        goto REJECT;
    }

    siglen = dil_r2sig2wire(sig, siglen, &pMat->z, &pMat->h, &pMat->c, K);

    MEMSET0_STRICT(pMat, sizeof(struct sign_mat));

    return siglen;
}

/*************************************************
 * Description: Computes signature (round 3)
 * Arguments:   - uint8_t *sig:   pointer to output signature (of length
 *CRYPTO_BYTES)
 *              - size_t siglen:  max.available/written signature (in/output)
 *              - uint8_t *m:     pointer to message to be signed
 *              - size_t mlen:    length of message
 *              - uint8_t *sk:    pointer to bit-packed secret key
 * Returns 0 (failure) or >0 (written bytecount)
 **************************************************/
CRS_STATIC size_t r3_sign(const void* pKey, unsigned char* sig, size_t siglen,
                          const uint8_t* m, size_t mlen, const uint8_t* sk,
                          size_t skbytes, unsigned int type)
{
    uint8_t      seedbuf[3 * DIL_SEEDBYTES + 2 * DIL_R3_CRHBYTES];
    uint8_t*     rho, *tr, *key, *mu, *rhoprime;
    unsigned int n = 0, K = 0, L = 0, beta, rej = 0, omega;
    int32_t      gamma1, gamma2;
    uint16_t     nonce = 0;
    size_t       wr, w1pb;

    struct sign_mat
    {
        spoly        cp;
        spolyvec_max mat[DIL_VECT_MAX]; /* using only K * L */
        spolyvec_max s1, y, z;          /* L */
        spolyvec_max t0, s2, w1, w0, h; /* K */
        Keccak_state state;
    };
    struct sign_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    // layout: [key || mu] MUST be consecutive
    rho      = seedbuf;
    tr       = rho + DIL_SEEDBYTES;
    key      = tr + DIL_SEEDBYTES;
    mu       = key + DIL_SEEDBYTES;
    rhoprime = mu + DIL_R3_CRHBYTES;

    if (!type)
    {
        type = dil__prvbytes2type(skbytes);
    }

    K      = dil_type2k(type);
    L      = dil_type2l(type);
    gamma1 = dil_r3k2gamma1(K);
    gamma2 = dil_r3k2gamma2(K);
    beta   = dil_k2beta(K, 3);
    omega  = dil_omega(K, 3);
    w1pb   = K * dil_r3k2polyw1_bytes(K);

    if (((dil_type2round(type) != 3) || !K || !L) ||
        (!gamma1 || !gamma2 || !beta || !omega || !w1pb ||
         ((int32_t)beta > gamma1) || ((int32_t)beta > gamma2)))
    {
        return 0;
    }

    // note: ref.impl. reorders r2/3 params:
    //     r2: unpack_sk(rho, key, tr, &s1, &s2, &t0, sk);
    //     r3: unpack_sk(rho, tr, key, &t0, &s1, &s2, sk);
    //                        ^^^^^^^
    // we keep uniform order for sanity

    switch (K)
    {
        /* s1 is L-sized; s2+t0 are K-sized */
        case 4:
            sunpack_prv4(rho, key, tr, (spolyvec4*)&pMat->s1,
                         (spolyvec4*)&pMat->s2, (spolyvec4*)&pMat->t0, sk);
            break;

        case 6:
            sunpack_prv6(rho, key, tr, (spolyvec5*)&pMat->s1,
                         (spolyvec6*)&pMat->s2, (spolyvec6*)&pMat->t0, sk);
            break;

        case 8:
            sunpack_prv8(rho, key, tr, (spolyvec7*)&pMat->s1,
                         (spolyvec8*)&pMat->s2, (spolyvec8*)&pMat->t0, sk);
            break;
    }

    /* mu[ DIL_R3_CRHBYTES ] := H(tr, msg) */
    shake256_init(&pMat->state);
    shake256_absorb(&pMat->state, tr, DIL_SEEDBYTES);
    shake256_absorb(&pMat->state, m, mlen);
    shake256_finalize(&pMat->state);
    shake256_squeeze(mu, DIL_R3_CRHBYTES, &pMat->state);

    shake256(rhoprime, DIL_R3_CRHBYTES, key, DIL_SEEDBYTES + DIL_R3_CRHBYTES);

    /* Expand matrix and transform vectors */
    switch (K)
    {
        case 4:
            expand_smatrix_4x4(pMat->mat, rho);
            spolyvec4_ntt((spolyvec4*)&pMat->s1);  /* L */
            spolyvec4_ntt((spolyvec4*)&pMat->s2);  /* K */
            spolyvec4_ntt((spolyvec4*)&pMat->t0);
            break;

        case 6:
            expand_smatrix_6x5(pMat->mat, rho);
            spolyvec5_ntt((spolyvec5*)&pMat->s1);  /* L */
            spolyvec6_ntt((spolyvec6*)&pMat->s2);  /* K */
            spolyvec6_ntt((spolyvec6*)&pMat->t0);
            break;

        case 8:
            expand_smatrix_8x7(pMat->mat, rho);
            spolyvec7_ntt((spolyvec7*)&pMat->s1);  /* L */
            spolyvec8_ntt((spolyvec8*)&pMat->s2);  /* K */
            spolyvec8_ntt((spolyvec8*)&pMat->t0);
            break;
    }

REJECT:

    /* Sample intermediate vector y */
    switch (K)
    {
        case 4:
            spolyvec4_uniform_gamma1((spolyvec4*)&pMat->y, rhoprime, nonce++, K);
            pMat->z = pMat->y;
            spolyvec4_ntt((spolyvec4*)&pMat->z);
            /**/
            /* matrix-vector multiply */
            spolyvec4x4_matrix_pointwise_montgomery(
                (spolyvec4*)&pMat->w1, pMat->mat, (const spolyvec4*)&pMat->z);
            spolyvec4_reduce((spolyvec4*)&pMat->w1);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->w1);
            /* decompose W */
            spolyvec4_caddq((spolyvec4*)&pMat->w1);
            spolyvec4_decompose((spolyvec4*)&pMat->w1, (spolyvec4*)&pMat->w0,
                                (const spolyvec4*)&pMat->w1);
            spolyvec4_pack_w1(sig, (const spolyvec4*)&pMat->w1);
            break;

        case 6:
            spolyvec5_uniform_gamma1((spolyvec5*)&pMat->y, rhoprime, nonce++, K);
            pMat->z = pMat->y;
            spolyvec5_ntt((spolyvec5*)&pMat->z);
            /**/
            /* matrix-vector multiply */
            spolyvec6x5_matrix_pointwise_montgomery(
                (spolyvec6*)&pMat->w1, pMat->mat, (const spolyvec5*)&pMat->z);
            spolyvec6_reduce((spolyvec6*)&pMat->w1);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->w1);
            /* decompose W */
            spolyvec6_caddq((spolyvec6*)&pMat->w1);
            spolyvec6_decompose((spolyvec6*)&pMat->w1, (spolyvec6*)&pMat->w0,
                                (const spolyvec6*)&pMat->w1);
            spolyvec6_pack_w1(sig, (const spolyvec6*)&pMat->w1);
            break;

        case 8:
            spolyvec7_uniform_gamma1((spolyvec7*)&pMat->y, rhoprime, nonce++, K);
            pMat->z = pMat->y;
            spolyvec7_ntt((spolyvec7*)&pMat->z);
            /**/
            /* matrix-vector multiply */
            spolyvec8x7_matrix_pointwise_montgomery(
                (spolyvec8*)&pMat->w1, pMat->mat, (const spolyvec7*)&pMat->z);
            spolyvec8_reduce((spolyvec8*)&pMat->w1);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->w1);
            /* decompose W */
            spolyvec8_caddq((spolyvec8*)&pMat->w1);
            spolyvec8_decompose((spolyvec8*)&pMat->w1, (spolyvec8*)&pMat->w0,
                                (const spolyvec8*)&pMat->w1);
            spolyvec8_pack_w1(sig, (const spolyvec8*)&pMat->w1);
            break;
    }

    /* written sig[ K * POLYW1-PACKED-BYTES ] */

    wr = w1pb;

    /* sig[ DIL_SEEDBYTES ] := CRH(mu[], sig[wr]) */
    shake256_init(&pMat->state);
    shake256_absorb(&pMat->state, mu, DIL_R3_CRHBYTES);
    shake256_absorb(&pMat->state, sig, wr);
    shake256_finalize(&pMat->state);
    shake256_squeeze(sig, DIL_SEEDBYTES, &pMat->state);

    spoly_challenge(&pMat->cp, sig, K);
    spoly_ntt256(&pMat->cp);

    switch (K)
    {
        case 4:
            spolyvec4_pointwise_poly_montgomery((spolyvec4*)&pMat->z, &pMat->cp,
                                                (const spolyvec4*)&pMat->s1);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->z);
            spolyvec4_add((spolyvec4*)&pMat->z, (const spolyvec4*)&pMat->z,
                          (const spolyvec4*)&pMat->y);
            spolyvec4_reduce((spolyvec4*)&pMat->z);
            rej = spolyvec4_chknorm((const spolyvec4*)&pMat->z, gamma1 - beta);
            break;

        case 6:
            spolyvec5_pointwise_poly_montgomery((spolyvec5*)&pMat->z, &pMat->cp,
                                                (const spolyvec5*)&pMat->s1);
            spolyvec5_invntt_tomont((spolyvec5*)&pMat->z);
            spolyvec5_add((spolyvec5*)&pMat->z, (const spolyvec5*)&pMat->z,
                          (const spolyvec5*)&pMat->y);
            spolyvec5_reduce((spolyvec5*)&pMat->z);
            rej = spolyvec5_chknorm((const spolyvec5*)&pMat->z, gamma1 - beta);
            break;

        case 8:
            spolyvec7_pointwise_poly_montgomery((spolyvec7*)&pMat->z, &pMat->cp,
                                                (const spolyvec7*)&pMat->s1);
            spolyvec7_invntt_tomont((spolyvec7*)&pMat->z);
            spolyvec7_add((spolyvec7*)&pMat->z, (const spolyvec7*)&pMat->z,
                          (const spolyvec7*)&pMat->y);
            spolyvec7_reduce((spolyvec7*)&pMat->z);
            rej = spolyvec7_chknorm((const spolyvec7*)&pMat->z, gamma1 - beta);
            break;
    }

    if (rej)
    {
        goto REJECT;
    }

    /* Check that subtracting cs2 does not change
     * high bits of w and low bits do not reveal
     * secret information */
    switch (K)
    {
        case 4:
            spolyvec4_pointwise_poly_montgomery((spolyvec4*)&pMat->h, &pMat->cp,
                                                (const spolyvec4*)&pMat->s2);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->h);
            spolyvec4_sub((spolyvec4*)&pMat->w0, (const spolyvec4*)&pMat->w0,
                          (const spolyvec4*)&pMat->h);
            spolyvec4_reduce((spolyvec4*)&pMat->w0);
            rej = spolyvec4_chknorm((const spolyvec4*)&pMat->w0, gamma2 - beta);
            break;

        case 6:
            spolyvec6_pointwise_poly_montgomery((spolyvec6*)&pMat->h, &pMat->cp,
                                                (const spolyvec6*)&pMat->s2);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->h);
            spolyvec6_sub((spolyvec6*)&pMat->w0, (const spolyvec6*)&pMat->w0,
                          (const spolyvec6*)&pMat->h);
            spolyvec6_reduce((spolyvec6*)&pMat->w0);
            rej = spolyvec6_chknorm((const spolyvec6*)&pMat->w0, gamma2 - beta);
            break;

        case 8:
            spolyvec8_pointwise_poly_montgomery((spolyvec8*)&pMat->h, &pMat->cp,
                                                (const spolyvec8*)&pMat->s2);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->h);
            spolyvec8_sub((spolyvec8*)&pMat->w0, (const spolyvec8*)&pMat->w0,
                          (const spolyvec8*)&pMat->h);
            spolyvec8_reduce((spolyvec8*)&pMat->w0);
            rej = spolyvec8_chknorm((const spolyvec8*)&pMat->w0, gamma2 - beta);
            break;
    }

    if (rej)
    {
        goto REJECT;
    }

    /* compute hints for W1 */
    switch (K)
    {
        case 4:
            spolyvec4_pointwise_poly_montgomery((spolyvec4*)&pMat->h, &pMat->cp,
                                                (const spolyvec4*)&pMat->t0);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->h);
            spolyvec4_reduce((spolyvec4*)&pMat->h);
            rej = spolyvec4_chknorm((const spolyvec4*)&pMat->h, gamma2);
            break;

        case 6:
            spolyvec6_pointwise_poly_montgomery((spolyvec6*)&pMat->h, &pMat->cp,
                                                (const spolyvec6*)&pMat->t0);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->h);
            spolyvec6_reduce((spolyvec6*)&pMat->h);
            rej = spolyvec6_chknorm((const spolyvec6*)&pMat->h, gamma2);
            break;

        case 8:
            spolyvec8_pointwise_poly_montgomery((spolyvec8*)&pMat->h, &pMat->cp,
                                                (const spolyvec8*)&pMat->t0);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->h);
            spolyvec8_reduce((spolyvec8*)&pMat->h);
            rej = spolyvec8_chknorm((const spolyvec8*)&pMat->h, gamma2);
            break;
    }

    if (rej)
    {
        goto REJECT;
    }

    switch (K)
    {
        case 4:
            spolyvec4_add((spolyvec4*)&pMat->w0, (const spolyvec4*)&pMat->w0,
                          (const spolyvec4*)&pMat->h);
            n = spolyvec4_make_hint((spolyvec4*)&pMat->h,
                                    (const spolyvec4*)&pMat->w0,
                                    (const spolyvec4*)&pMat->w1, K);
            break;

        case 6:
            spolyvec6_add((spolyvec6*)&pMat->w0, (const spolyvec6*)&pMat->w0,
                          (const spolyvec6*)&pMat->h);
            n = spolyvec6_make_hint((spolyvec6*)&pMat->h,
                                    (const spolyvec6*)&pMat->w0,
                                    (const spolyvec6*)&pMat->w1, K);
            break;

        case 8:
            spolyvec8_add((spolyvec8*)&pMat->w0, (const spolyvec8*)&pMat->w0,
                          (const spolyvec8*)&pMat->h);
            n = spolyvec8_make_hint((spolyvec8*)&pMat->h,
                                    (const spolyvec8*)&pMat->w0,
                                    (const spolyvec8*)&pMat->w1, K);
            break;
    }

    rej = (n > omega);

    if (rej)
    {
        goto REJECT;
    }

    siglen = dil_r3sig2wire(sig, siglen, sig, &pMat->z, &pMat->h, K, L);
    /* sig... -> sig... is not a typo,
     * documented to work in-place
     */

    MEMSET0_STRICT(pMat, sizeof(struct sign_mat));
    /* ...any special-cased log etc. would come here... */

    return siglen;
}

#endif  /*-----  delimiter: Dilithium sign  --------------*/

#if !defined(NO_MLDSA_SIGN) /*-----  delimiter: ML_DSA sign  --------------*/
/*************************************************
 * Description: Computes signature (mldsa)
 * Arguments:   - uint8_t *sig:   pointer to output signature (of length
 *CRYPTO_BYTES)
 *              - size_t siglen:  max.available/written signature (in/output)
 *              - uint8_t *m:     pointer to message to be signed
 *              - size_t mlen:    length of message
 *              - uint8_t *sk:    pointer to bit-packed secret key
 * Returns 0 (failure) or >0 (written bytecount)
 **************************************************/
CRS_STATIC size_t mldsa_sign_internal(const void* pKey, unsigned char* sig,
                                      size_t siglen, const uint8_t* m,
                                      size_t mlen, const uint8_t* sk,
                                      size_t skbytes, unsigned int type,
                                      const uint8_t* domsep, size_t domsepLen,
                                      const uint8_t* coins)
{
    uint8_t seedbuf[2 * DIL_SEEDBYTES + DIL_MLDSA_TRBYTES + DIL_MLDSA_RNDBYTES +
                    2 * DIL_R3_CRHBYTES];
    uint8_t*     rho, *tr, *key, *mu, *rhoprime, *rnd;
    unsigned int n = 0, K = 0, L = 0, beta, rej = 0, omega;
    int32_t      gamma1, gamma2;
    uint16_t     nonce = 0;
    size_t       wr;

    struct sign_mat
    {
        spoly        cp;
        spolyvec_max mat[DIL_VECT_MAX]; /* using only K * L */
        spolyvec_max s1, y, z;          /* L */
        spolyvec_max t0, s2, w1, w0, h; /* K */
        Keccak_state state;
    };
    struct sign_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    // layout: [key || mu] MUST be consecutive
    rho      = seedbuf;
    tr       = rho + DIL_SEEDBYTES;
    key      = tr + DIL_MLDSA_TRBYTES;
    rnd      = key + DIL_SEEDBYTES;
    mu       = rnd + DIL_MLDSA_RNDBYTES;
    rhoprime = mu + DIL_R3_CRHBYTES;

    if (!type)
    {
        type = dil__prvbytes2type(skbytes);
    }

    K      = dil_type2k(type);
    L      = dil_type2l(type);
    gamma1 = dil_r3k2gamma1(K);
    gamma2 = dil_r3k2gamma2(K);
    beta   = dil_k2beta(K, 3);
    omega  = dil_omega(K, 3);

    if (((dil_type2round(type) != 4) || !K || !L) ||
        (!gamma1 || !gamma2 || !beta || !omega || ((int32_t)beta > gamma1) ||
         ((int32_t)beta > gamma2)))
    {
        return 0;
    }

    switch (K)
    {
        /* s1 is L-sized; s2+t0 are K-sized */
        case 4:
            ml_sunpack_prv4(rho, key, tr, (spolyvec4*)&pMat->s1,
                            (spolyvec4*)&pMat->s2, (spolyvec4*)&pMat->t0, sk);
            break;

        case 6:
            ml_sunpack_prv6(rho, key, tr, (spolyvec5*)&pMat->s1,
                            (spolyvec6*)&pMat->s2, (spolyvec6*)&pMat->t0, sk);
            break;

        case 8:
            ml_sunpack_prv8(rho, key, tr, (spolyvec7*)&pMat->s1,
                            (spolyvec8*)&pMat->s2, (spolyvec8*)&pMat->t0, sk);
            break;
    }

    /* mu[ DIL_R3_CRHBYTES ] := H(tr, msg) */
    shake256_init(&pMat->state);
    shake256_absorb(&pMat->state, tr, DIL_MLDSA_TRBYTES);

    if (domsepLen && domsep != NULL)
    {
        shake256_absorb(&pMat->state, domsep, domsepLen);
    }

    shake256_absorb(&pMat->state, m, mlen);
    shake256_finalize(&pMat->state);
    shake256_squeeze(mu, DIL_R3_CRHBYTES, &pMat->state);

    MEMCPY(rnd, coins, DIL_MLDSA_RNDBYTES);

    shake256(rhoprime, DIL_R3_CRHBYTES, key,
             DIL_SEEDBYTES + DIL_MLDSA_RNDBYTES + DIL_R3_CRHBYTES);

    /* Expand matrix and transform vectors */
    switch (K)
    {
        case 4:
            expand_smatrix_4x4(pMat->mat, rho);
            spolyvec4_ntt((spolyvec4*)&pMat->s1);  /* L */
            spolyvec4_ntt((spolyvec4*)&pMat->s2);  /* K */
            spolyvec4_ntt((spolyvec4*)&pMat->t0);
            break;

        case 6:
            expand_smatrix_6x5(pMat->mat, rho);
            spolyvec5_ntt((spolyvec5*)&pMat->s1);  /* L */
            spolyvec6_ntt((spolyvec6*)&pMat->s2);  /* K */
            spolyvec6_ntt((spolyvec6*)&pMat->t0);
            break;

        case 8:
            expand_smatrix_8x7(pMat->mat, rho);
            spolyvec7_ntt((spolyvec7*)&pMat->s1);  /* L */
            spolyvec8_ntt((spolyvec8*)&pMat->s2);  /* K */
            spolyvec8_ntt((spolyvec8*)&pMat->t0);
            break;
    }

REJECT:

    /* Sample intermediate vector y */
    switch (K)
    {
        case 4:
            spolyvec4_uniform_gamma1((spolyvec4*)&pMat->y, rhoprime, nonce++, K);
            pMat->z = pMat->y;
            spolyvec4_ntt((spolyvec4*)&pMat->z);
            /**/
            /* matrix-vector multiply */
            spolyvec4x4_matrix_pointwise_montgomery(
                (spolyvec4*)&pMat->w1, pMat->mat, (const spolyvec4*)&pMat->z);
            spolyvec4_reduce((spolyvec4*)&pMat->w1);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->w1);
            /* decompose W */
            spolyvec4_caddq((spolyvec4*)&pMat->w1);
            spolyvec4_decompose((spolyvec4*)&pMat->w1, (spolyvec4*)&pMat->w0,
                                (const spolyvec4*)&pMat->w1);
            spolyvec4_pack_w1(sig, (const spolyvec4*)&pMat->w1);
            break;

        case 6:
            spolyvec5_uniform_gamma1((spolyvec5*)&pMat->y, rhoprime, nonce++, K);
            pMat->z = pMat->y;
            spolyvec5_ntt((spolyvec5*)&pMat->z);
            /**/
            /* matrix-vector multiply */
            spolyvec6x5_matrix_pointwise_montgomery(
                (spolyvec6*)&pMat->w1, pMat->mat, (const spolyvec5*)&pMat->z);
            spolyvec6_reduce((spolyvec6*)&pMat->w1);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->w1);
            /* decompose W */
            spolyvec6_caddq((spolyvec6*)&pMat->w1);
            spolyvec6_decompose((spolyvec6*)&pMat->w1, (spolyvec6*)&pMat->w0,
                                (const spolyvec6*)&pMat->w1);
            spolyvec6_pack_w1(sig, (const spolyvec6*)&pMat->w1);
            break;

        case 8:
            spolyvec7_uniform_gamma1((spolyvec7*)&pMat->y, rhoprime, nonce++, K);
            pMat->z = pMat->y;
            spolyvec7_ntt((spolyvec7*)&pMat->z);
            /**/
            /* matrix-vector multiply */
            spolyvec8x7_matrix_pointwise_montgomery(
                (spolyvec8*)&pMat->w1, pMat->mat, (const spolyvec7*)&pMat->z);
            spolyvec8_reduce((spolyvec8*)&pMat->w1);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->w1);
            /* decompose W */
            spolyvec8_caddq((spolyvec8*)&pMat->w1);
            spolyvec8_decompose((spolyvec8*)&pMat->w1, (spolyvec8*)&pMat->w0,
                                (const spolyvec8*)&pMat->w1);
            spolyvec8_pack_w1(sig, (const spolyvec8*)&pMat->w1);
            break;
    }

    /* written sig[ K * POLYW1-PACKED-BYTES ] */

    wr = K * dil_r3k2polyw1_bytes(K);

    /* sig[ DIL_SEEDBYTES ] := CRH(mu[], sig[wr]) */
    shake256_init(&pMat->state);
    shake256_absorb(&pMat->state, mu, DIL_R3_CRHBYTES);
    shake256_absorb(&pMat->state, sig, wr);
    shake256_finalize(&pMat->state);
    shake256_squeeze(sig, K * 8, &pMat->state);   // CTILDEBYTES = K*8

    ml_spoly_challenge(&pMat->cp, sig, K);
    spoly_ntt256(&pMat->cp);

    switch (K)
    {
        case 4:
            spolyvec4_pointwise_poly_montgomery((spolyvec4*)&pMat->z, &pMat->cp,
                                                (const spolyvec4*)&pMat->s1);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->z);
            spolyvec4_add((spolyvec4*)&pMat->z, (const spolyvec4*)&pMat->z,
                          (const spolyvec4*)&pMat->y);
            spolyvec4_reduce((spolyvec4*)&pMat->z);
            rej = spolyvec4_chknorm((const spolyvec4*)&pMat->z, gamma1 - beta);
            break;

        case 6:
            spolyvec5_pointwise_poly_montgomery((spolyvec5*)&pMat->z, &pMat->cp,
                                                (const spolyvec5*)&pMat->s1);
            spolyvec5_invntt_tomont((spolyvec5*)&pMat->z);
            spolyvec5_add((spolyvec5*)&pMat->z, (const spolyvec5*)&pMat->z,
                          (const spolyvec5*)&pMat->y);
            spolyvec5_reduce((spolyvec5*)&pMat->z);
            rej = spolyvec5_chknorm((const spolyvec5*)&pMat->z, gamma1 - beta);
            break;

        case 8:
            spolyvec7_pointwise_poly_montgomery((spolyvec7*)&pMat->z, &pMat->cp,
                                                (const spolyvec7*)&pMat->s1);
            spolyvec7_invntt_tomont((spolyvec7*)&pMat->z);
            spolyvec7_add((spolyvec7*)&pMat->z, (const spolyvec7*)&pMat->z,
                          (const spolyvec7*)&pMat->y);
            spolyvec7_reduce((spolyvec7*)&pMat->z);
            rej = spolyvec7_chknorm((const spolyvec7*)&pMat->z, gamma1 - beta);
            break;
    }

    if (rej)
    {
        goto REJECT;
    }

    /* Check that subtracting cs2 does not change
     * high bits of w and low bits do not reveal
     * secret information */
    switch (K)
    {
        case 4:
            spolyvec4_pointwise_poly_montgomery((spolyvec4*)&pMat->h, &pMat->cp,
                                                (const spolyvec4*)&pMat->s2);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->h);
            spolyvec4_sub((spolyvec4*)&pMat->w0, (const spolyvec4*)&pMat->w0,
                          (const spolyvec4*)&pMat->h);
            spolyvec4_reduce((spolyvec4*)&pMat->w0);
            rej = spolyvec4_chknorm((const spolyvec4*)&pMat->w0, gamma2 - beta);
            break;

        case 6:
            spolyvec6_pointwise_poly_montgomery((spolyvec6*)&pMat->h, &pMat->cp,
                                                (const spolyvec6*)&pMat->s2);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->h);
            spolyvec6_sub((spolyvec6*)&pMat->w0, (const spolyvec6*)&pMat->w0,
                          (const spolyvec6*)&pMat->h);
            spolyvec6_reduce((spolyvec6*)&pMat->w0);
            rej = spolyvec6_chknorm((const spolyvec6*)&pMat->w0, gamma2 - beta);
            break;

        case 8:
            spolyvec8_pointwise_poly_montgomery((spolyvec8*)&pMat->h, &pMat->cp,
                                                (const spolyvec8*)&pMat->s2);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->h);
            spolyvec8_sub((spolyvec8*)&pMat->w0, (const spolyvec8*)&pMat->w0,
                          (const spolyvec8*)&pMat->h);
            spolyvec8_reduce((spolyvec8*)&pMat->w0);
            rej = spolyvec8_chknorm((const spolyvec8*)&pMat->w0, gamma2 - beta);
            break;
    }

    if (rej)
    {
        goto REJECT;
    }

    /* compute hints for W1 */
    switch (K)
    {
        case 4:
            spolyvec4_pointwise_poly_montgomery((spolyvec4*)&pMat->h, &pMat->cp,
                                                (const spolyvec4*)&pMat->t0);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->h);
            spolyvec4_reduce((spolyvec4*)&pMat->h);
            rej = spolyvec4_chknorm((const spolyvec4*)&pMat->h, gamma2);
            break;

        case 6:
            spolyvec6_pointwise_poly_montgomery((spolyvec6*)&pMat->h, &pMat->cp,
                                                (const spolyvec6*)&pMat->t0);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->h);
            spolyvec6_reduce((spolyvec6*)&pMat->h);
            rej = spolyvec6_chknorm((const spolyvec6*)&pMat->h, gamma2);
            break;

        case 8:
            spolyvec8_pointwise_poly_montgomery((spolyvec8*)&pMat->h, &pMat->cp,
                                                (const spolyvec8*)&pMat->t0);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->h);
            spolyvec8_reduce((spolyvec8*)&pMat->h);
            rej = spolyvec8_chknorm((const spolyvec8*)&pMat->h, gamma2);
            break;
    }

    if (rej)
    {
        goto REJECT;
    }

    switch (K)
    {
        case 4:
            spolyvec4_add((spolyvec4*)&pMat->w0, (const spolyvec4*)&pMat->w0,
                          (const spolyvec4*)&pMat->h);
            n = spolyvec4_make_hint((spolyvec4*)&pMat->h,
                                    (const spolyvec4*)&pMat->w0,
                                    (const spolyvec4*)&pMat->w1, K);
            break;

        case 6:
            spolyvec6_add((spolyvec6*)&pMat->w0, (const spolyvec6*)&pMat->w0,
                          (const spolyvec6*)&pMat->h);
            n = spolyvec6_make_hint((spolyvec6*)&pMat->h,
                                    (const spolyvec6*)&pMat->w0,
                                    (const spolyvec6*)&pMat->w1, K);
            break;

        case 8:
            spolyvec8_add((spolyvec8*)&pMat->w0, (const spolyvec8*)&pMat->w0,
                          (const spolyvec8*)&pMat->h);
            n = spolyvec8_make_hint((spolyvec8*)&pMat->h,
                                    (const spolyvec8*)&pMat->w0,
                                    (const spolyvec8*)&pMat->w1, K);
            break;
    }

    rej = (n > omega);

    if (rej)
    {
        goto REJECT;
    }

    siglen = dil_mldsasig2wire(sig, siglen, sig, &pMat->z, &pMat->h, K, L);
    /* sig... -> sig... is not a typo,
     * documented to work in-place
     */

    MEMSET0_STRICT(pMat, sizeof(struct sign_mat));
    /* ...any special-cased log etc. would come here... */

    return siglen;
}

CRS_STATIC size_t mldsa_sign(const void* pKey, unsigned char* sig,
                             size_t siglen, const uint8_t* m, size_t mlen,
                             const uint8_t* sk, size_t skbytes,
                             unsigned int type, void* rng)
{
    int     rc = 0;
    uint8_t coins[DIL_MLDSA_RNDBYTES];

    if (rng != NULL)   // FIPS 204 hedged/randomized
    {
        randombytes(coins, DIL_MLDSA_RNDBYTES, rng);
    }
    else   // FIPS 204 deterministic
    {
        MEMSET0_STRICT(coins, DIL_MLDSA_RNDBYTES);
    }

    rc = mldsa_sign_internal(pKey, sig, siglen, m, mlen, sk, skbytes, type,
                             mldsa_ds_pure, 2, coins);

    MEMSET0_STRICT(coins, DIL_MLDSA_RNDBYTES);

    return rc;
}

#endif /*-----  delimiter: ML_DSA sign  --------------*/

#if !defined(NO_DILITHIUM_VERIFY) /*-----  delimiter: NO_DILITHIUM_VERIFY  --------------*/
/*************************************************
 * Description: Verifies signature.
 * Arguments:   - uint8_t *m: pointer to input signature
 *              - size_t siglen: length of signature
 *              - const uint8_t *m: pointer to message
 *              - size_t mlen: length of message
 *              - const uint8_t *pk: pointer to bit-packed public key
 * Returns >0 if signature could be verified correctly and 0 otherwise
 **************************************************/
CRS_STATIC int r2_verify(const void* pKey, const uint8_t* sig, size_t siglen,
                         const uint8_t* m, size_t mlen, const uint8_t* pk,
                         size_t pkbytes)
{
    int          rc = 1;
    unsigned int i, K = 0, beta, type;
    uint8_t      rho[DIL_SEEDBYTES];
    uint8_t      mu[DIL_CRHBYTES];
    size_t       sigb;

    struct ver_mat
    {
        poly         c, cp;
        polyvec_max  mat[DIL_VECT_MAX], z; /* L; LxK (mat) */
        polyvec_max  t1, h, w1;            /* K */
        Keccak_state state;
    };
    struct ver_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    type = dil__pubbytes2type(pkbytes);
    K    = dil_type2k(type);

    /**/
    if (!type || !K || (dil_type2round(type) != 2))
    {
        return MLCA_EKEYTYPE;
    }

    sigb = dil_signature_bytes(K, K - 1, 2); /* K == L+1 for all of r2 */
    beta = dil_k2beta(K, 2);

    if (!sigb || (siglen != sigb))
    {
        return 0;
    }

    switch (K)
    {
        case 5:
            unpack_pk5(rho, (polyvec5*)&pMat->t1, pk);
            break;

        case 6:
            unpack_pk6(rho, (polyvec6*)&pMat->t1, pk);
            break;

        case 8:
            unpack_pk8(rho, (polyvec8*)&pMat->t1, pk);
            break;

        default:
            rc = MLCA_EINTERN;
    }

    if (rc == 1 && r2_wire2sig(&pMat->z, &pMat->h, &pMat->c, K, sig, siglen))
    {
        rc = 0;
    }

    if (rc == 1)
    {
        unsigned int fail = 0;

        switch (K)
        {
            /* check Lx vector, so -1 is not off-by-one */
            case 5:
                fail = !!polyvec4_chknorm((const polyvec4*)&pMat->z,
                                          DIL_GAMMA1 - beta);
                break;

            case 6:
                fail = !!polyvec5_chknorm((const polyvec5*)&pMat->z,
                                          DIL_GAMMA1 - beta);
                break;

            case 8:
                fail = !!polyvec7_chknorm((const polyvec7*)&pMat->z,
                                          DIL_GAMMA1 - beta);
                break;

            default:
                break;
        }

        if (fail)
        {
            rc = 0;
        }

        /* Compute CRH(CRH(rho, t1), msg) */
        if (rc == 1)
        {
            dil_crh(mu, DIL_CRHBYTES, pk, pkbytes);
            //
            shake256_init(&pMat->state);
            shake256_absorb(&pMat->state, mu, DIL_CRHBYTES);
            shake256_absorb(&pMat->state, m, mlen);
            shake256_finalize(&pMat->state);
            shake256_squeeze(mu, DIL_CRHBYTES, &pMat->state);

            /* Matrix-vector multiplication; compute Az - c2^dt1 */

            switch (K)
            {
                /* NTT on L-sized vector, K-1 */
                case 5:
                    expand_matrix_5x4(pMat->mat, rho);
                    polyvec4_ntt((polyvec4*)&pMat->z);  /* L */
                    break;

                case 6:
                    expand_matrix_6x5(pMat->mat, rho);
                    polyvec5_ntt((polyvec5*)&pMat->z);  /* L */
                    break;

                case 8:
                    expand_matrix_8x7(pMat->mat, rho);
                    polyvec7_ntt((polyvec7*)&pMat->z);  /* L */
                    break;
            }

            for (i = 0; i < K; ++i)
            {
                switch (K)
                {
                    case 5:
                        polyvec4_pointwise_acc_montgomery(
                            &(pMat->w1.vec[i]), (const polyvec4*) & (pMat->mat[i]),
                            (const polyvec4*)&pMat->z);
                        break;

                    case 6:
                        polyvec5_pointwise_acc_montgomery(
                            &(pMat->w1.vec[i]), (const polyvec5*) & (pMat->mat[i]),
                            (const polyvec5*)&pMat->z);
                        break;

                    case 8:
                        polyvec7_pointwise_acc_montgomery(
                            &(pMat->w1.vec[i]), (const polyvec7*) & (pMat->mat[i]),
                            (const polyvec7*)&pMat->z);
                        break;
                }
            }

            pMat->cp = pMat->c;
            poly_ntt256(&pMat->cp);

            switch (K)
            {
                case 5:
                    polyvec5_shiftl((polyvec5*)&pMat->t1);
                    polyvec5_ntt((polyvec5*)&pMat->t1);
                    break;

                case 6:
                    polyvec6_shiftl((polyvec6*)&pMat->t1);
                    polyvec6_ntt((polyvec6*)&pMat->t1);
                    break;

                case 8:
                    polyvec8_shiftl((polyvec8*)&pMat->t1);
                    polyvec8_ntt((polyvec8*)&pMat->t1);
                    break;
            }

            for (i = 0; i < K; ++i)
            {
                poly_pointwise_montgomery(&(pMat->t1.vec[i]), &pMat->cp,
                                          &(pMat->t1.vec[i]));
            }

            /* csubq: Reconstruct w1 */
            switch (K)
            {
                case 5:
                    polyvec5_sub((polyvec5*)&pMat->w1, (const polyvec5*)&pMat->w1,
                                 (const polyvec5*)&pMat->t1);
                    polyvec5_reduce((polyvec5*)&pMat->w1);
                    polyvec5_invntt_tomont((polyvec5*)&pMat->w1);
                    polyvec5_csubq((polyvec5*)&pMat->w1);
                    polyvec5_use_hint((polyvec5*)&pMat->w1,
                                      (const polyvec5*)&pMat->w1,
                                      (const polyvec5*)&pMat->h);
                    break;

                case 6:
                    polyvec6_sub((polyvec6*)&pMat->w1, (const polyvec6*)&pMat->w1,
                                 (const polyvec6*)&pMat->t1);
                    polyvec6_reduce((polyvec6*)&pMat->w1);
                    polyvec6_invntt_tomont((polyvec6*)&pMat->w1);
                    polyvec6_csubq((polyvec6*)&pMat->w1);
                    polyvec6_use_hint((polyvec6*)&pMat->w1,
                                      (const polyvec6*)&pMat->w1,
                                      (const polyvec6*)&pMat->h);
                    break;

                case 8:
                    polyvec8_sub((polyvec8*)&pMat->w1, (const polyvec8*)&pMat->w1,
                                 (const polyvec8*)&pMat->t1);
                    polyvec8_reduce((polyvec8*)&pMat->w1);
                    polyvec8_invntt_tomont((polyvec8*)&pMat->w1);
                    polyvec8_csubq((polyvec8*)&pMat->w1);
                    polyvec8_use_hint((polyvec8*)&pMat->w1,
                                      (const polyvec8*)&pMat->w1,
                                      (const polyvec8*)&pMat->h);
                    break;
            }

            /* Call random oracle and verify challenge */

            dil_challenge(&pMat->cp, mu, &pMat->w1, K);

            for (i = 0; i < DIL_N; ++i)
            {
                if (pMat->c.coeffs[i] != pMat->cp.coeffs[i])
                {
                    rc = 0;
                }
            }
        }
    }

    MEMSET0_STRICT(pMat, sizeof(struct ver_mat));

    return rc;
}

/*************************************************
 * Description: Verifies signature.
 * Arguments:   - uint8_t *m: pointer to input signature
 *              - size_t siglen: length of signature
 *              - const uint8_t *m: pointer to message
 *              - size_t mlen: length of message
 *              - const uint8_t *pk: pointer to bit-packed public key
 * Returns >0 if signature could be verified correctly and 0 otherwise
 **************************************************/
CRS_STATIC int r3_verify(const void* pKey, const uint8_t* sig, size_t siglen,
                         const uint8_t* m, size_t mlen, const uint8_t* pk,
                         size_t pkbytes)
{
    int           rc = 1;
    unsigned int  K  = 0, L, beta, type;
    unsigned char rho[DIL_SEEDBYTES], mu[DIL_R3_CRHBYTES], chash[DIL_SEEDBYTES],
             w1pack[DIL__KxPOLYW1_MAX_BYTES];
    int32_t gamma1, gamma2;
    size_t  sigb, w1pb, i;

    struct ver_mat
    {
        spoly        cp;
        spolyvec_max mat[DIL_VECT_MAX], z; /* L; LxK (mat) */
        spolyvec_max t1, h, w1;            /* K */
        Keccak_state state;
    };

    struct ver_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    type   = dil__pubbytes2type(pkbytes);
    K      = dil_type2k(type);
    L      = dil_type2l(type);
    gamma1 = dil_r3k2gamma1(K);
    gamma2 = dil_r3k2gamma2(K);
    w1pb   = K * dil_r3k2polyw1_bytes(K);

    /**/
    if (!type || !K || !L || !gamma1 || !gamma2 || !w1pb ||
        (w1pb > sizeof(w1pack)) || (dil_type2round(type) != 3))
    {
        return MLCA_EKEYTYPE;
    }

    sigb = dil_signature_bytes(K, L, 3);
    beta = dil_k2beta(K, 3);

    /**/
    if (!sig || !sigb || (siglen != sigb))
    {
        return 0;
    }

    switch (K)
    {
        case 4:
            sunpack_pk4(rho, (spolyvec4*)&pMat->t1, pk);
            break;

        case 6:
            sunpack_pk6(rho, (spolyvec6*)&pMat->t1, pk);
            break;

        case 8:
            sunpack_pk8(rho, (spolyvec8*)&pMat->t1, pk);
            break;

        default:
            rc = MLCA_EINTERN;
    }

    if (rc == 1 && r3_wire2sig(chash, &pMat->z, &pMat->h, K, L, sig, siglen))
    {
        rc = 0;
    }

    if (rc == 1)
    {
        unsigned int fail = 0;

        switch (K)
        {
            case 4:
                fail =
                    !!spolyvec4_chknorm((const spolyvec4*)&pMat->z, gamma1 - beta);
                break;

            case 6:
                fail =
                    !!spolyvec5_chknorm((const spolyvec5*)&pMat->z, gamma1 - beta);
                break;

            case 8:
                fail =
                    !!spolyvec7_chknorm((const spolyvec7*)&pMat->z, gamma1 - beta);
                break;

            default:
                break;
        }

        if (fail)
        {
            rc = 0;
        }

        /* mu[ DIL_SEEDBYTES ] := CRH(H(rho, t1), msg) */
        if (rc == 1)
        {
            /* round3.0 was:
              dil_crh(mu, DIL_CRHBYTES, pk, pkbytes);
             */
            shake256(mu, DIL_SEEDBYTES, pk, pkbytes);
            /**/
            shake256_init(&pMat->state);
            shake256_absorb(&pMat->state, mu, DIL_SEEDBYTES);
            shake256_absorb(&pMat->state, m, mlen);
            shake256_finalize(&pMat->state);
            shake256_squeeze(mu, DIL_R3_CRHBYTES, &pMat->state);

            spoly_challenge(&pMat->cp, chash, K);

            /* Matrix-vector multiplication; compute Az - c2^dt1 */

            switch (K)
            {
                /* NTT on L-sized vector */
                case 4:
                    expand_smatrix_4x4(pMat->mat, rho);
                    spolyvec4_ntt((spolyvec4*)&pMat->z);  /* L */
                    spolyvec4x4_matrix_pointwise_montgomery(
                        (spolyvec4*)&pMat->w1, pMat->mat,
                        (const spolyvec4*)&pMat->z);
                    break;

                case 6:
                    expand_smatrix_6x5(pMat->mat, rho);
                    spolyvec5_ntt((spolyvec5*)&pMat->z);  /* L */
                    spolyvec6x5_matrix_pointwise_montgomery(
                        (spolyvec6*)&pMat->w1, pMat->mat,
                        (const spolyvec5*)&pMat->z);
                    break;

                case 8:
                    expand_smatrix_8x7(pMat->mat, rho);
                    spolyvec7_ntt((spolyvec7*)&pMat->z);  /* L */
                    spolyvec8x7_matrix_pointwise_montgomery(
                        (spolyvec8*)&pMat->w1, pMat->mat,
                        (const spolyvec7*)&pMat->z);
                    break;
            }

            spoly_ntt256(&pMat->cp);

            switch (K)
            {
                case 4:
                    spolyvec4_shiftl((spolyvec4*)&pMat->t1);
                    spolyvec4_ntt((spolyvec4*)&pMat->t1);
                    spolyvec4_pointwise_poly_montgomery(
                        (spolyvec4*)&pMat->t1, &pMat->cp,
                        (const spolyvec4*)&pMat->t1);
                    spolyvec4_sub((spolyvec4*)&pMat->w1,
                                  (const spolyvec4*)&pMat->w1,
                                  (const spolyvec4*)&pMat->t1);
                    spolyvec4_reduce((spolyvec4*)&pMat->w1);
                    spolyvec4_invntt_tomont((spolyvec4*)&pMat->w1);
                    /* reconstruct W1 */
                    spolyvec4_caddq((spolyvec4*)&pMat->w1);
                    spolyvec4_use_hint((spolyvec4*)&pMat->w1,
                                       (const spolyvec4*)&pMat->w1,
                                       (const spolyvec4*)&pMat->h, K);
                    spolyvec4_pack_w1(w1pack, (const spolyvec4*)&pMat->w1);
                    break;

                case 6:
                    spolyvec6_shiftl((spolyvec6*)&pMat->t1);
                    spolyvec6_ntt((spolyvec6*)&pMat->t1);
                    spolyvec6_pointwise_poly_montgomery(
                        (spolyvec6*)&pMat->t1, &pMat->cp,
                        (const spolyvec6*)&pMat->t1);
                    spolyvec6_sub((spolyvec6*)&pMat->w1,
                                  (const spolyvec6*)&pMat->w1,
                                  (const spolyvec6*)&pMat->t1);
                    spolyvec6_reduce((spolyvec6*)&pMat->w1);
                    spolyvec6_invntt_tomont((spolyvec6*)&pMat->w1);
                    /* reconstruct W1 */
                    spolyvec6_caddq((spolyvec6*)&pMat->w1);
                    spolyvec6_use_hint((spolyvec6*)&pMat->w1,
                                       (const spolyvec6*)&pMat->w1,
                                       (const spolyvec6*)&pMat->h, K);
                    spolyvec6_pack_w1(w1pack, (const spolyvec6*)&pMat->w1);
                    break;

                case 8:
                    spolyvec8_shiftl((spolyvec8*)&pMat->t1);
                    spolyvec8_ntt((spolyvec8*)&pMat->t1);
                    spolyvec8_pointwise_poly_montgomery(
                        (spolyvec8*)&pMat->t1, &pMat->cp,
                        (const spolyvec8*)&pMat->t1);
                    spolyvec8_sub((spolyvec8*)&pMat->w1,
                                  (const spolyvec8*)&pMat->w1,
                                  (const spolyvec8*)&pMat->t1);
                    spolyvec8_reduce((spolyvec8*)&pMat->w1);
                    spolyvec8_invntt_tomont((spolyvec8*)&pMat->w1);
                    /* reconstruct W1 */
                    spolyvec8_caddq((spolyvec8*)&pMat->w1);
                    spolyvec8_use_hint((spolyvec8*)&pMat->w1,
                                       (const spolyvec8*)&pMat->w1,
                                       (const spolyvec8*)&pMat->h, K);
                    spolyvec8_pack_w1(w1pack, (const spolyvec8*)&pMat->w1);
                    break;
            }

            /* rho[ DIL_SEEDBYTES ] := CRH(mu[ DIL_CRHBYTES ], w1pack[w1pb])
             * reusing already-idle rho[] which happens to share size
             */
            shake256_init(&pMat->state);
            shake256_absorb(&pMat->state, mu, DIL_R3_CRHBYTES);
            shake256_absorb(&pMat->state, w1pack, w1pb);
            shake256_finalize(&pMat->state);
            shake256_squeeze(rho, DIL_SEEDBYTES, &pMat->state);

            sigb = 0;

            for (i = 0; i < DIL_SEEDBYTES; ++i)
            {
                sigb += !!(chash[i] == rho[i]);
            }

            rc = (sigb == DIL_SEEDBYTES);
        }
    }

    MEMSET0_STRICT(pMat, sizeof(struct ver_mat));

    return rc;
}
#endif  /*-----  delimiter: NO_DILITHIUM_VERIFY  --------------*/

#if !defined(NO_MLDSA_VERIFY)  /*-----  delimiter: NO_MLDSA_VERIFY  --------------*/
/*************************************************
 * Description: Verifies signature.
 * Arguments:   - uint8_t *m: pointer to input signature
 *              - size_t siglen: length of signature
 *              - const uint8_t *m: pointer to message
 *              - size_t mlen: length of message
 *              - const uint8_t *pk: pointer to bit-packed public key
 * Returns >0 if signature could be verified correctly and 0 otherwise
 **************************************************/
CRS_STATIC int mldsa_verify_internal(const uint8_t* sig, size_t siglen,
                                     const uint8_t* m, size_t mlen,
                                     const uint8_t* pk, size_t pkbytes,
                                     const uint8_t* domsep, size_t domsepLen)
{
    int           rc = 1;
    unsigned int  K  = 0, L, beta, type;

    unsigned char rho[DIL_MLDSA_MAX_CTILDEBYTES], mu[DIL_R3_CRHBYTES],
             chash[DIL_MLDSA_MAX_CTILDEBYTES],
             w1pack[DIL__KxPOLYW1_MAX_BYTES];   // note: rho size is
    // max(DIL_MLDSA_MAX_CTILDEBYTES,
    // DIL_SEEDBYTES)

    int32_t gamma1, gamma2;
    size_t  sigb, w1pb, i, ctilbytes;

    struct ver_mat
    {
        spoly        cp;
        spolyvec_max mat[DIL_VECT_MAX], z; /* L; LxK (mat) */
        spolyvec_max t1, h, w1;            /* K */
        Keccak_state state;
    };

#if defined(USE_DYNAMIC_ALLOC)
    struct ver_mat* pMat = (struct ver_mat*)mlca_alloc (sizeof(struct ver_mat));
#else
    struct ver_mat mat, *pMat = &mat;
#endif

    type      = dil__pubbytes2type_mldsa(pkbytes);
    K         = dil_type2k(type);
    L         = dil_type2l(type);
    ctilbytes = dil_mldsa_ctilbytes(K);
    gamma1    = dil_r3k2gamma1(K);
    gamma2    = dil_r3k2gamma2(K);
    w1pb      = K * dil_r3k2polyw1_bytes(K);

    /**/
    if (!type || !K || !L || !gamma1 || !gamma2 || !w1pb ||
        (w1pb > sizeof(w1pack)) || (dil_type2round(type) != 4))
    {
        return MLCA_EKEYTYPE;
    }

    sigb = dil_signature_bytes(K, L, 4);
    beta = dil_k2beta(K, 3);

    /**/
    if (!sig || !sigb || (siglen != sigb))
    {
        return 0;
    }

    switch (K)
    {
        case 4:
            sunpack_pk4(rho, (spolyvec4*)&pMat->t1, pk);
            break;

        case 6:
            sunpack_pk6(rho, (spolyvec6*)&pMat->t1, pk);
            break;

        case 8:
            sunpack_pk8(rho, (spolyvec8*)&pMat->t1, pk);
            break;

        default:
            rc = MLCA_EINTERN;
    }

    if (rc == 1 && mldsa_wire2sig(chash, &pMat->z, &pMat->h, K, L, sig, siglen))
    {
        rc = 0;
    }

    if (rc == 1)
    {
        unsigned int fail = 0;

        switch (K)
        {
            case 4:
                fail =
                    !!spolyvec4_chknorm((const spolyvec4*)&pMat->z, gamma1 - beta);
                break;

            case 6:
                fail =
                    !!spolyvec5_chknorm((const spolyvec5*)&pMat->z, gamma1 - beta);
                break;

            case 8:
                fail =
                    !!spolyvec7_chknorm((const spolyvec7*)&pMat->z, gamma1 - beta);
                break;

            default:
                break;
        }

        if (fail)
        {
            rc = 0;
        }

        /* mu[ DIL_SEEDBYTES ] := CRH(H(rho, t1), msg) */
        if (rc == 1)
        {
            /* round3.0 was:
              dil_crh(mu, DIL_CRHBYTES, pk, pkbytes);
             */
            shake256(mu, DIL_R3_CRHBYTES, pk, pkbytes);
            /**/
            shake256_init(&pMat->state);
            shake256_absorb(&pMat->state, mu, DIL_R3_CRHBYTES);

            if (domsepLen)
            {
                shake256_absorb(&pMat->state, domsep, domsepLen);
            }

            shake256_absorb(&pMat->state, m, mlen);
            shake256_finalize(&pMat->state);
            shake256_squeeze(mu, DIL_R3_CRHBYTES, &pMat->state);

            ml_spoly_challenge(&pMat->cp, chash, K);

            /* Matrix-vector multiplication; compute Az - c2^dt1 */

            switch (K)
            {
                /* NTT on L-sized vector */
                case 4:
                    expand_smatrix_4x4(pMat->mat, rho);
                    spolyvec4_ntt((spolyvec4*)&pMat->z);  /* L */
                    spolyvec4x4_matrix_pointwise_montgomery(
                        (spolyvec4*)&pMat->w1, pMat->mat,
                        (const spolyvec4*)&pMat->z);
                    break;

                case 6:
                    expand_smatrix_6x5(pMat->mat, rho);
                    spolyvec5_ntt((spolyvec5*)&pMat->z);  /* L */
                    spolyvec6x5_matrix_pointwise_montgomery(
                        (spolyvec6*)&pMat->w1, pMat->mat,
                        (const spolyvec5*)&pMat->z);
                    break;

                case 8:
                    expand_smatrix_8x7(pMat->mat, rho);
                    spolyvec7_ntt((spolyvec7*)&pMat->z);  /* L */
                    spolyvec8x7_matrix_pointwise_montgomery(
                        (spolyvec8*)&pMat->w1, pMat->mat,
                        (const spolyvec7*)&pMat->z);
                    break;
            }

            spoly_ntt256(&pMat->cp);

            switch (K)
            {
                case 4:
                    spolyvec4_shiftl((spolyvec4*)&pMat->t1);
                    spolyvec4_ntt((spolyvec4*)&pMat->t1);
                    spolyvec4_pointwise_poly_montgomery(
                        (spolyvec4*)&pMat->t1, &pMat->cp,
                        (const spolyvec4*)&pMat->t1);
                    spolyvec4_sub((spolyvec4*)&pMat->w1,
                                  (const spolyvec4*)&pMat->w1,
                                  (const spolyvec4*)&pMat->t1);
                    spolyvec4_reduce((spolyvec4*)&pMat->w1);
                    spolyvec4_invntt_tomont((spolyvec4*)&pMat->w1);
                    /* reconstruct W1 */
                    spolyvec4_caddq((spolyvec4*)&pMat->w1);
                    spolyvec4_use_hint((spolyvec4*)&pMat->w1,
                                       (const spolyvec4*)&pMat->w1,
                                       (const spolyvec4*)&pMat->h, K);
                    spolyvec4_pack_w1(w1pack, (const spolyvec4*)&pMat->w1);
                    break;

                case 6:
                    spolyvec6_shiftl((spolyvec6*)&pMat->t1);
                    spolyvec6_ntt((spolyvec6*)&pMat->t1);
                    spolyvec6_pointwise_poly_montgomery(
                        (spolyvec6*)&pMat->t1, &pMat->cp,
                        (const spolyvec6*)&pMat->t1);
                    spolyvec6_sub((spolyvec6*)&pMat->w1,
                                  (const spolyvec6*)&pMat->w1,
                                  (const spolyvec6*)&pMat->t1);
                    spolyvec6_reduce((spolyvec6*)&pMat->w1);
                    spolyvec6_invntt_tomont((spolyvec6*)&pMat->w1);
                    /* reconstruct W1 */
                    spolyvec6_caddq((spolyvec6*)&pMat->w1);
                    spolyvec6_use_hint((spolyvec6*)&pMat->w1,
                                       (const spolyvec6*)&pMat->w1,
                                       (const spolyvec6*)&pMat->h, K);
                    spolyvec6_pack_w1(w1pack, (const spolyvec6*)&pMat->w1);
                    break;

                case 8:
                    spolyvec8_shiftl((spolyvec8*)&pMat->t1);
                    spolyvec8_ntt((spolyvec8*)&pMat->t1);
                    spolyvec8_pointwise_poly_montgomery(
                        (spolyvec8*)&pMat->t1, &pMat->cp,
                        (const spolyvec8*)&pMat->t1);
                    spolyvec8_sub((spolyvec8*)&pMat->w1,
                                  (const spolyvec8*)&pMat->w1,
                                  (const spolyvec8*)&pMat->t1);
                    spolyvec8_reduce((spolyvec8*)&pMat->w1);
                    spolyvec8_invntt_tomont((spolyvec8*)&pMat->w1);
                    /* reconstruct W1 */
                    spolyvec8_caddq((spolyvec8*)&pMat->w1);
                    spolyvec8_use_hint((spolyvec8*)&pMat->w1,
                                       (const spolyvec8*)&pMat->w1,
                                       (const spolyvec8*)&pMat->h, K);
                    spolyvec8_pack_w1(w1pack, (const spolyvec8*)&pMat->w1);
                    break;
            }

            /* rho[ DIL_SEEDBYTES ] := CRH(mu[ DIL_CRHBYTES ], w1pack[w1pb])
             * reusing already-idle rho[] which happens to share size
             */
            shake256_init(&pMat->state);
            shake256_absorb(&pMat->state, mu, DIL_R3_CRHBYTES);
            shake256_absorb(&pMat->state, w1pack, w1pb);
            shake256_finalize(&pMat->state);
            shake256_squeeze(rho, ctilbytes, &pMat->state);

            sigb = 0;

            for (i = 0; i < ctilbytes; ++i)
            {
                sigb += !!(chash[i] == rho[i]);
            }

            rc = (sigb == ctilbytes);
        }
    }

    memset(pMat, 0, sizeof(struct ver_mat));

#if defined(USE_DYNAMIC_ALLOC)
    mlca_free ((void*) pMat);
#endif

    return rc;
}

// This function is called via securerom
// Reroutes call to internal function
asm(".globl .L.mldsa_verify");
int mldsa_verify(const uint8_t* sig, size_t siglen,
                 const uint8_t* m, size_t mlen,
                 const uint8_t* pk, size_t pkbytes)
{
    const uint8_t* mldsa_ds_pure_p;

    // In secureROM context mldsa_ds_pure won't correctly point to the data
    // So we must do this in order to use it
    #if defined EMULATE_HW || defined __HOSTBOOT_MODULE
    mldsa_ds_pure_p = mldsa_ds_pure;
    #else
    asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
                    "sub  %0,2,%0 \n\t" // because subi does not work
                    "addi %0,%0,(mldsa_ds_pure-0x8000)@l" : "=r" (mldsa_ds_pure_p) );
    #endif

    return mldsa_verify_internal(sig, siglen, m, mlen, pk, pkbytes,
                                 mldsa_ds_pure_p, 2);
}
#endif  /*-----  delimiter: NO_MLDSA_VERIFY  --------------*/
#endif /*-----  /delimiter: sign/verify  ------------------------------*/

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*-- Kyber ------*/

/*************************************************
 * Description: Run rejection sampling on uniform random bytes to generate
 *              uniform random integers mod q
 *
 * Arguments:   - int16_t *r:          pointer to output buffer
 *              - unsigned int len:    requested number of 16-bit integers
 *                                     (uniform mod q)
 *              - const uint8_t *buf:  pointer to input buffer
 *                                     (assumed to be uniform random bytes)
 *              - unsigned int buflen: length of input buffer in bytes
 *
 * Returns number of sampled 16-bit integers (at most len)
 **************************************************/
CRS_STATIC unsigned int krej_uniform(int16_t* r, unsigned int len,
                                     const uint8_t* buf, unsigned int buflen)
{
    unsigned int ctr, pos;
    uint16_t     val;

    ctr = pos = 0;

    while ((ctr < len) && (pos + 2 <= buflen))
    {
        val = buf[pos] | ((uint16_t)buf[pos + 1] << 8);
        pos += 2;

        if (val < 19 * KYB_Q)
        {
            val -= (val >> 12) * KYB_Q;   // Barrett reduction

            r[ctr++] = (int16_t)val;
        }
    }

    return ctr;
}

/*************************************************
 * Description: Run rejection sampling on uniform random bytes to generate
 *              uniform random integers mod q. For Kyber round 3.
 *
 * Arguments:   - int16_t *r:          pointer to output buffer
 *              - unsigned int len:    requested number of 16-bit integers
 *                                     (uniform mod q)
 *              - const uint8_t *buf:  pointer to input buffer
 *                                     (assumed to be uniform random bytes)
 *              - unsigned int buflen: length of input buffer in bytes
 *
 * Returns number of sampled 16-bit integers (at most len)
 **************************************************/
CRS_STATIC unsigned int r3_krej_uniform(int16_t* r, unsigned int len,
                                        const uint8_t* buf, unsigned int buflen)
{
    unsigned int ctr, pos;
    uint16_t     val0, val1;

    ctr = pos = 0;

    while (ctr < len && pos + 3 <= buflen)
    {
        val0 = ((buf[pos + 0] >> 0) | ((uint16_t)buf[pos + 1] << 8)) & 0xFFF;
        val1 = ((buf[pos + 1] >> 4) | ((uint16_t)buf[pos + 2] << 4)) & 0xFFF;
        pos += 3;

        if (val0 < KYB_Q)
        {
            r[ctr++] = val0;
        }

        if (ctr < len && val1 < KYB_Q)
        {
            r[ctr++] = val1;
        }
    }

    return ctr;
}

//--------------------------------------
#define KYB_GEN_A(A, B, K)               kyb_gen_matrix((A), (K), (B), 0)
#define R3_KYB_GEN_A(A, B, K)            r3_kyb_gen_matrix((A), (K), (B), 0)
#define KYB_GEN_A_transposed(A, B, K)    kyb_gen_matrix((A), (K), (B), 1)
#define R3_KYB_GEN_A_transposed(A, B, K) r3_kyb_gen_matrix((A), (K), (B), 1)

#define KYB_XOF_BLOCKBYTES               SHAKE128_RATE /* SHA-3 only */

//--------------------------------------
CRS_STATIC void kyber_shake128_absorb(Keccak_state* state,
                                      const uint8_t seed[KYB_SYMBYTES],
                                      uint8_t x, uint8_t y)
{
    unsigned char extseed[KYB_SYMBYTES + 2] CRS_SENSITIVE;

    // yes, this could be a MEMCPY(); please do not comment on it
    //
    MEMMOVE(extseed, seed, KYB_SYMBYTES);

    extseed[KYB_SYMBYTES]     = x;
    extseed[KYB_SYMBYTES + 1] = y;

    shake128_absorb_once(state, extseed, sizeof(extseed));

    MEMSET0_STRICT(extseed, sizeof(extseed));
}

//--------------------------------------
CRS_STATIC void kyb_hash_g(unsigned char* h, const unsigned char* in,
                           size_t ibytes)
{
    sha3_512(h, in, ibytes);
}

//--------------------------------------
CRS_STATIC void kyb_hash_h(unsigned char* h, const unsigned char* in,
                           size_t ibytes)
{
    sha3_256(h, in, ibytes);
}

//--------------------------------------
CRS_STATIC void mlkem_rkprf(uint8_t        out[KYB_SHRDBYTES],
                            const uint8_t  key[KYB_SYMBYTES],
                            const uint8_t* input, size_t ctsize)
{
    Keccak_state state;

    shake256_init(&state);
    shake256_absorb(&state, key, KYB_SYMBYTES);
    shake256_absorb(&state, input, ctsize);
    shake256_finalize(&state);
    shake256_squeeze(out, KYB_SHRDBYTES, &state);
}

//--------------------------------------
#define KYB_GEN_MATRIX_NBLOCKS                                                 \
    ((2 * KYB_N * (1U << 16) / (19 * KYB_Q) + KYB_XOF_BLOCKBYTES) /            \
     KYB_XOF_BLOCKBYTES)

/*************************************************
 * Description: Deterministically generate matrix A (or the transpose of A)
 *              from a seed. Entries of the matrix are polynomials that look
 *              uniformly random. Performs rejection sampling on output of
 *              a XOF
 * Arguments:   - polyvec *a:          pointer to ouptput matrix A
 *              - const uint8_t *seed: pointer to input seed
 *              - int transposed:      boolean deciding whether A or A^T
 *                                     is generated
 **************************************************/

/* only uses a[k]; assumes a[k][k] for one of the kpolyvec<N> types */

CRS_STATIC void kyb_gen_matrix(kpolyvec_max* a, unsigned int k,
                               const uint8_t seed[KYB_SYMBYTES], int transposed)
{
    uint8_t      buf[KYB_GEN_MATRIX_NBLOCKS * KYB_XOF_BLOCKBYTES] CRS_SENSITIVE;
    unsigned int ctr, i, j;
    Keccak_state state;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
#if 0

// was:
            if (transposed)
            {
                xof_absorb(&state, seed, i, j);
            }
            else
            {
                xof_absorb(&state, seed, j, i);
            }

// xof_absorb() restricted to SHA-3, kyber_shake128_absorb()
#endif

            kyber_shake128_absorb(&state, seed, transposed ? i : j,
                                  transposed ? j : i);

            shake128_squeezeblocks(buf, KYB_GEN_MATRIX_NBLOCKS, &state);

            ctr = krej_uniform(a[i].vec[j].coeffs, KYB_N, buf, sizeof(buf));

            while (ctr < KYB_N)
            {
                shake128_squeezeblocks(buf, 1, &state);

                ctr += krej_uniform(a[i].vec[j].coeffs + ctr, KYB_N - ctr, buf,
                                    KYB_XOF_BLOCKBYTES);
            }
        }
    }

    shake128_wipe(&state);
    MEMSET0_STRICT(buf, sizeof(buf));
}

#define KYBR3_GEN_MATRIX_NBLOCKS                                               \
    ((12 * KYB_N / 8 * (1 << 12) / KYB_Q + KYB_XOF_BLOCKBYTES) /               \
     KYB_XOF_BLOCKBYTES)

CRS_STATIC void r3_kyb_gen_matrix(kpolyvec_max* a, unsigned int k,
                                  const uint8_t seed[KYB_SYMBYTES],
                                  int           transposed)
{
    uint8_t buf[KYBR3_GEN_MATRIX_NBLOCKS * KYB_XOF_BLOCKBYTES] CRS_SENSITIVE;
    unsigned int ctr, i, j;
    unsigned int buflen;
    Keccak_state state;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
#if 0

// was:
            if (transposed)
            {
                xof_absorb(&state, seed, i, j);
            }
            else
            {
                xof_absorb(&state, seed, j, i);
            }

// xof_absorb() restricted to SHA-3, kyber_shake128_absorb()
#endif

            kyber_shake128_absorb(&state, seed, transposed ? i : j,
                                  transposed ? j : i);

            shake128_squeezeblocks(buf, KYBR3_GEN_MATRIX_NBLOCKS, &state);

            buflen = KYBR3_GEN_MATRIX_NBLOCKS * KYB_XOF_BLOCKBYTES;
            ctr    = r3_krej_uniform(a[i].vec[j].coeffs, KYB_N, buf, buflen);

            while (ctr < KYB_N)
            {
                shake128_squeezeblocks(buf, 1, &state);
                buflen = KYB_XOF_BLOCKBYTES;
                ctr += r3_krej_uniform(a[i].vec[j].coeffs + ctr, KYB_N - ctr,
                                       buf, buflen);
            }
        }
    }

    shake128_wipe(&state);
    MEMSET0_STRICT(buf, sizeof(buf));
}

/*************************************************
 * Description: Encryption function of the CPA-secure
 *              public-key encryption scheme underlying Kyber.
 * Arguments:   - uint8_t *c:           pointer to output ciphertext
 *                                      (of length KYB_INDCPA_BYTES bytes)
 *              - const uint8_t *m:     pointer to input message
 *                                      (of length KYB_INDCPA_MSGBYTES bytes)
 *              - const uint8_t *pk:    pointer to input public key
 *                                      (of length KYB_INDCPA_PUBLICKEYBYTES)
 *              - const uint8_t *coins: pointer to input random coins
 *                                      used as seed (of length KYB_SYMBYTES)
 *                                      to deterministically generate all
 *                                      randomness
 **************************************************/
CRS_STATIC int indcpa_enc(uint8_t* c, size_t cbytes,
                          const uint8_t  m[KYB_INDCPA_MSGBYTES],
                          const uint8_t* pk, size_t pkbytes,
                          const uint8_t coins[KYB_SYMBYTES], unsigned int kyb_k)
{
    unsigned char seed[KYB_SYMBYTES] CRS_SENSITIVE;
    kpolyvec_max  sp, pkpv, ep, at[KYB_VECT_MAX], bp;
    uint8_t       nonce = 0;
    unsigned int  i;
    kpoly         v, k, epp;
    int           rc = 0;

    (void)pkbytes;
    (void)cbytes;

    switch (kyb_k)
    {
        case 3:
            kunpack_pk3((kpolyvec3*)&pkpv, seed, pk);
            break;

        case 4:
            kunpack_pk4((kpolyvec4*)&pkpv, seed, pk);
            break;
    }

    kpoly_frommsg(&k, m);
    KYB_GEN_A_transposed(at, seed, kyb_k);

    for (i = 0; i < kyb_k; i++)
    {
        kpoly_getnoise(sp.vec + i, coins, nonce++);
    }

    for (i = 0; i < kyb_k; i++)
    {
        kpoly_getnoise(ep.vec + i, coins, nonce++);
    }

    kpoly_getnoise(&epp, coins, nonce++);

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_ntt((kpolyvec3*)&sp);
            break;

        case 4:
            kpolyvec4_ntt((kpolyvec4*)&sp);
            break;
    }

    // matrix-vector multiplication
    for (i = 0; i < kyb_k; i++)
    {
        switch (kyb_k)
        {
            case 3:
                kpolyvec3_pointwise_acc_montgomery(
                    &bp.vec[i], (const kpolyvec3*)&at[i], (const kpolyvec3*)&sp);
                break;

            case 4:
                kpolyvec4_pointwise_acc_montgomery(
                    &bp.vec[i], (const kpolyvec4*)&at[i], (const kpolyvec4*)&sp);
                break;
        }
    }

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_pointwise_acc_montgomery(&v, (const kpolyvec3*)&pkpv,
                                               (const kpolyvec3*)&sp);
            kpolyvec3_invntt_tomont((kpolyvec3*)&bp);
            break;

        case 4:
            kpolyvec4_pointwise_acc_montgomery(&v, (const kpolyvec4*)&pkpv,
                                               (const kpolyvec4*)&sp);
            kpolyvec4_invntt_tomont((kpolyvec4*)&bp);
            break;
    }

    kpoly_invntt_tomont(&v);

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_add((kpolyvec3*)&bp, (const kpolyvec3*)&bp,
                          (const kpolyvec3*)&ep);
            break;

        case 4:
            kpolyvec4_add((kpolyvec4*)&bp, (const kpolyvec4*)&bp,
                          (const kpolyvec4*)&ep);
            break;
    }

    kpoly_add(&v, &v, &epp);
    kpoly_add(&v, &v, &k);

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_reduce((kpolyvec3*)&bp);
            break;

        case 4:
            kpolyvec4_reduce((kpolyvec4*)&bp);
            break;
    }

    kpoly_reduce(&v);

    switch (kyb_k)
    {
        case 3:
            kpack_ciphertext3(c, (kpolyvec3*)&bp, &v);
            rc = (int)KYB_CIPHTXT3_BYTES;
            break;

        case 4:
            kpack_ciphertext4(c, (kpolyvec4*)&bp, &v);
            rc = (int)KYB_CIPHTXT4_BYTES;
            break;
    }

    MEMSET0_STRICT(seed, sizeof(seed));

    return rc;
}

CRS_STATIC int r3_indcpa_enc(uint8_t* c, size_t cbytes,
                             const uint8_t  m[KYB_INDCPA_MSGBYTES],
                             const uint8_t* pk, size_t pkbytes,
                             const uint8_t coins[KYB_SYMBYTES],
                             unsigned int  kyb_k)
{
    unsigned char seed[KYB_SYMBYTES] CRS_SENSITIVE;
    kpolyvec_max  sp, pkpv, ep, at[KYB_VECT_MAX], bp;
    uint8_t       nonce = 0;
    unsigned int  i;
    kpoly         v, k, epp;
    int           rc = 0;

    (void)pkbytes;
    (void)cbytes;

    switch (kyb_k)
    {
        case 3:
            r3_kunpack_pk3((kpolyvec3*)&pkpv, seed, pk);
            break;

        case 4:
            r3_kunpack_pk4((kpolyvec4*)&pkpv, seed, pk);
            break;
    }

    kpoly_frommsg(&k, m);
    R3_KYB_GEN_A_transposed(at, seed, kyb_k);

    for (i = 0; i < kyb_k; i++)
    {
        r3_kpoly_getnoise_eta1(sp.vec + i, coins, nonce++);
    }

    for (i = 0; i < kyb_k; i++)
    {
        r3_kpoly_getnoise_eta2(ep.vec + i, coins, nonce++);
    }

    r3_kpoly_getnoise_eta2(&epp, coins, nonce++);

    switch (kyb_k)
    {
        case 3:
            r3_kpolyvec3_ntt((kpolyvec3*)&sp);
            break;

        case 4:
            r3_kpolyvec4_ntt((kpolyvec4*)&sp);
            break;
    }

    // matrix-vector multiplication
    for (i = 0; i < kyb_k; i++)
    {
        switch (kyb_k)
        {
            case 3:
                r3_kpolyvec3_basemul_acc_montgomery(
                    &bp.vec[i], (const kpolyvec3*)&at[i], (const kpolyvec3*)&sp);
                break;

            case 4:
                r3_kpolyvec4_basemul_acc_montgomery(
                    &bp.vec[i], (const kpolyvec4*)&at[i], (const kpolyvec4*)&sp);
                break;
        }
    }

    switch (kyb_k)
    {
        case 3:
            r3_kpolyvec3_basemul_acc_montgomery(&v, (const kpolyvec3*)&pkpv,
                                                (const kpolyvec3*)&sp);
            r3_kpolyvec3_invntt_tomont((kpolyvec3*)&bp);
            break;

        case 4:
            r3_kpolyvec4_basemul_acc_montgomery(&v, (const kpolyvec4*)&pkpv,
                                                (const kpolyvec4*)&sp);
            r3_kpolyvec4_invntt_tomont((kpolyvec4*)&bp);
            break;
    }

    r3_kpoly_invntt_tomont(&v);

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_add((kpolyvec3*)&bp, (const kpolyvec3*)&bp,
                          (const kpolyvec3*)&ep);
            break;

        case 4:
            kpolyvec4_add((kpolyvec4*)&bp, (const kpolyvec4*)&bp,
                          (const kpolyvec4*)&ep);
            break;
    }

    kpoly_add(&v, &v, &epp);
    kpoly_add(&v, &v, &k);

    switch (kyb_k)
    {
        case 3:
            r3_kpolyvec3_reduce((kpolyvec3*)&bp);
            break;

        case 4:
            r3_kpolyvec4_reduce((kpolyvec4*)&bp);
            break;
    }

    r3_kpoly_reduce(&v);

    switch (kyb_k)
    {
        case 3:
            r3_kpack_ciphertext3(c, (kpolyvec3*)&bp, &v);
            rc = (int)KYB_CIPHTXT3_BYTES;
            break;

        case 4:
            r3_kpack_ciphertext4(c, (kpolyvec4*)&bp, &v);
            rc = (int)KYB_CIPHTXT4_BYTES;
            break;
    }

    MEMSET0_STRICT(seed, sizeof(seed));

    return rc;
}

CRS_STATIC int mlkem_indcpa_enc(uint8_t* c, size_t cbytes,
                                const uint8_t  m[KYB_INDCPA_MSGBYTES],
                                const uint8_t* pk, size_t pkbytes,
                                const uint8_t coins[KYB_SYMBYTES],
                                unsigned int kyb_k, int pkcheck)
{
    unsigned char seed[KYB_SYMBYTES] CRS_SENSITIVE;
    kpolyvec_max  sp, pkpv, ep, at[KYB_VECT_MAX], bp;
    uint8_t       nonce = 0;
    unsigned int  i, notvalid=0;
    kpoly         v, k, epp;
    int           rc = 0;

    (void)pkbytes;
    (void)cbytes;

    switch (kyb_k)
    {
        case 3:
            r3_kunpack_pk3((kpolyvec3*)&pkpv, seed, pk);
            break;

        case 4:
            r3_kunpack_pk4((kpolyvec4*)&pkpv, seed, pk);
            break;
    }

    if (pkcheck)
    {
        /**
         *  FIPS203 Input validation
         *  "ML-KEM.Encaps requires that the byte array containing the
         *  encapsulation key correctly decodes to an array of integers
         *  modulo 𝑞 without any modular reductions."
         */
        switch (kyb_k)
        {
            case 3:
                notvalid = mlkem_pack_check_pk3((kpolyvec3*)&pkpv, pk);
                break;

            case 4:
                notvalid = mlkem_pack_check_pk4((kpolyvec4*)&pkpv, pk);
                break;
        }

        if (notvalid)
        {
            rc = 0;
            goto err;
        }
    }

    kpoly_frommsg(&k, m);
    R3_KYB_GEN_A_transposed(at, seed, kyb_k);

    for (i = 0; i < kyb_k; i++)
    {
        r3_kpoly_getnoise_eta1(sp.vec + i, coins, nonce++);
    }

    for (i = 0; i < kyb_k; i++)
    {
        r3_kpoly_getnoise_eta2(ep.vec + i, coins, nonce++);
    }

    r3_kpoly_getnoise_eta2(&epp, coins, nonce++);

    switch (kyb_k)
    {
        case 3:
            r3_kpolyvec3_ntt((kpolyvec3*)&sp);
            break;

        case 4:
            r3_kpolyvec4_ntt((kpolyvec4*)&sp);
            break;
    }

    // matrix-vector multiplication
    for (i = 0; i < kyb_k; i++)
    {
        switch (kyb_k)
        {
            case 3:
                r3_kpolyvec3_basemul_acc_montgomery(
                    &bp.vec[i], (const kpolyvec3*)&at[i], (const kpolyvec3*)&sp);
                break;

            case 4:
                r3_kpolyvec4_basemul_acc_montgomery(
                    &bp.vec[i], (const kpolyvec4*)&at[i], (const kpolyvec4*)&sp);
                break;
        }
    }

    switch (kyb_k)
    {
        case 3:
            r3_kpolyvec3_basemul_acc_montgomery(&v, (const kpolyvec3*)&pkpv,
                                                (const kpolyvec3*)&sp);
            r3_kpolyvec3_invntt_tomont((kpolyvec3*)&bp);
            break;

        case 4:
            r3_kpolyvec4_basemul_acc_montgomery(&v, (const kpolyvec4*)&pkpv,
                                                (const kpolyvec4*)&sp);
            r3_kpolyvec4_invntt_tomont((kpolyvec4*)&bp);
            break;
    }

    r3_kpoly_invntt_tomont(&v);

    switch (kyb_k)
    {
        case 3:
            kpolyvec3_add((kpolyvec3*)&bp, (const kpolyvec3*)&bp,
                          (const kpolyvec3*)&ep);
            break;

        case 4:
            kpolyvec4_add((kpolyvec4*)&bp, (const kpolyvec4*)&bp,
                          (const kpolyvec4*)&ep);
            break;
    }

    kpoly_add(&v, &v, &epp);
    kpoly_add(&v, &v, &k);

    switch (kyb_k)
    {
        case 3:
            r3_kpolyvec3_reduce((kpolyvec3*)&bp);
            break;

        case 4:
            r3_kpolyvec4_reduce((kpolyvec4*)&bp);
            break;
    }

    r3_kpoly_reduce(&v);

    switch (kyb_k)
    {
        case 3:
            r3_kpack_ciphertext3(c, (kpolyvec3*)&bp, &v);
            rc = (int)KYB_CIPHTXT3_BYTES;
            break;

        case 4:
            r3_kpack_ciphertext4(c, (kpolyvec4*)&bp, &v);
            rc = (int)KYB_CIPHTXT4_BYTES;
            break;
    }

err:
    MEMSET0_STRICT(seed, sizeof(seed));

    return rc;
}

// const uint8_t c[KYB_INDCPA_BYTES],
/*************************************************
 * Description: Decryption function of the CPA-secure
 *              public-key encryption scheme underlying Kyber.
 *
 * Arguments:   - uint8_t *m:        pointer to output decrypted message
 *                                   (of length KYB_INDCPA_MSGBYTES)
 *              - const uint8_t *c:  pointer to input ciphertext
 *                                   (of length KYB_INDCPA_BYTES)
 *              - const uint8_t *sk: pointer to input secret key
 *                                   (of length KYB_INDCPA_SECRETKEYBYTES)
 **************************************************/
CRS_STATIC int indcpa_dec(uint8_t m[KYB_INDCPA_MSGBYTES], const uint8_t* c,
                          size_t         cbytes,
                          const uint8_t* sk, /* [KYB_INDCPA_SECRETKEYBYTES] */
                          unsigned int   kyb_k)
{
    kpolyvec_max bp, skpv;
    kpoly        v, mp;

    (void)cbytes;

    switch (kyb_k)
    {
        case 3:
            kunpack_ciphertext3((kpolyvec3*)&bp, &v, c);
            kunpack_sk3((kpolyvec3*)&skpv, sk);
            kpolyvec3_ntt((kpolyvec3*)&bp);
            kpolyvec3_pointwise_acc_montgomery(&mp, (const kpolyvec3*)&skpv,
                                               (const kpolyvec3*)&bp);
            break;

        case 4:
            kunpack_ciphertext4((kpolyvec4*)&bp, &v, c);
            kunpack_sk4((kpolyvec4*)&skpv, sk);
            kpolyvec4_ntt((kpolyvec4*)&bp);
            kpolyvec4_pointwise_acc_montgomery(&mp, (const kpolyvec4*)&skpv,
                                               (const kpolyvec4*)&bp);
            break;
    }

    kpoly_invntt_tomont(&mp);

    kpoly_sub(&mp, &v, &mp);
    kpoly_reduce(&mp);

    kpoly_tomsg(m, &mp);

    return (int)KYB_INDCPA_MSGBYTES;
}

CRS_STATIC int
r3_indcpa_dec(uint8_t m[KYB_INDCPA_MSGBYTES], const uint8_t* c, size_t cbytes,
              const uint8_t* sk, /* [KYB_INDCPA_SECRETKEYBYTES] */
              unsigned int   kyb_k)

{
    kpolyvec_max bp, skpv;
    kpoly        v, mp;

    (void)cbytes;

    switch (kyb_k)
    {
        case 3:
            r3_kunpack_ciphertext3((kpolyvec3*)&bp, &v, c);
            r3_kunpack_sk3((kpolyvec3*)&skpv, sk);
            r3_kpolyvec3_ntt((kpolyvec3*)&bp);
            r3_kpolyvec3_basemul_acc_montgomery(&mp, (const kpolyvec3*)&skpv,
                                                (const kpolyvec3*)&bp);
            break;

        case 4:
            r3_kunpack_ciphertext4((kpolyvec4*)&bp, &v, c);
            r3_kunpack_sk4((kpolyvec4*)&skpv, sk);
            r3_kpolyvec4_ntt((kpolyvec4*)&bp);
            r3_kpolyvec4_basemul_acc_montgomery(&mp, (const kpolyvec4*)&skpv,
                                                (const kpolyvec4*)&bp);
            break;
    }

    r3_kpoly_invntt_tomont(&mp);

    kpoly_sub(&mp, &v, &mp);
    r3_kpoly_reduce(&mp);

    r3_kpoly_tomsg(m, &mp);

    return (int)KYB_INDCPA_MSGBYTES;
}
#endif /*-----  /delimiter: Kyber  ------------------------------------*/

#if 0 /*-----  delimiter: key.generate  ------------------------------*/
#if !defined(NO_CRYSTALS_SIG) /*-----  delimiter: Dilithium  --------------*/
/*************************************************
 * Description: Generates public and private key (round2)
 * Arguments:   - uint8_t *prv: pointer to output private key
 *              - uint8_t *pub: pointer to output public key
 * Returns >0 upon success; number of bytes written to start of (prv, prbytes)
 *
 * call only with round2 OIDs; will reject other Dilithium variants
 **************************************************/
CRS_STATIC int dil_keygen(const void* pKey, unsigned char* prv, size_t prbytes,
                          unsigned char* pub, size_t* pbbytes, void* rng,
                          const unsigned char* algid, size_t ibytes)
{
    unsigned int         i, type, K, eta, round = 2;
    unsigned char        seedbuf[3 * DIL_SEEDBYTES];
    unsigned char        tr[DIL_CRHBYTES];
    const unsigned char* rho, *rhoprime, *key;
    uint16_t             nonce = 0;
    size_t               wrb, wrpub;

    struct keygen_mat
    {
        polyvec_max mat[DIL_VECT_MAX]; /* using only K * L */
        polyvec_max s1, s1hat;         /* L */
        polyvec_max s2, t1, t0;        /* K */
    };
    struct keygen_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    type  = crs_oid2type(algid, ibytes);
    round = dil_type2round(type);
    K     = dil_type2k(type);
    eta   = dil_type2eta(type);
    wrb   = dil_prv_wirebytes(K, 0, round);

    if (!type || !K || !wrb || (round != 2))
    {
        return MLCA_EKEYTYPE;
    }

    if (!(CRS_ALG_FL_SIG & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    // size queries: NULL prv -> prvbytes, NULL pub -> pub.bytes
    // 'prv' is checked first
    if (!prv)
    {
        return wrb;
    }

    if (!pub)
    {
        return dil_pub_wirebytes(K, 0, round);
    }

    if (!pbbytes)
    {
        return MLCA_EPARAM;
    }

    wrpub = dil_pub_wirebytes(K, 0, round);

    if ((wrb > prbytes) || (wrpub > *pbbytes))
    {
        return MLCA_ETOOSMALL;
    }

    /* Get randomness for rho, rhoprime and key */

    if (randombytes(seedbuf, sizeof(seedbuf), rng) < sizeof(seedbuf))
    {
        return MLCA_ERNG;
    }

    rho      = seedbuf;
    rhoprime = seedbuf + DIL_SEEDBYTES;
    key      = seedbuf + DIL_SEEDBYTES * 2;

    /* Expand matrix */

    switch (K)
    {
        case 5:
            expand_matrix_5x4(pMat->mat, rho);
            break;

        case 6:
            expand_matrix_6x5(pMat->mat, rho);
            break;

        case 8:
            expand_matrix_8x7(pMat->mat, rho);
            break;
    }

    /* Sample short vectors s1 and s2 */
    for (i = 0; i < K - 1; ++i) /* L */
    {
        poly_uniform_eta(&(pMat->s1.vec[i]), rhoprime, eta, nonce++);
    }

    for (i = 0; i < K; ++i)
    {
        poly_uniform_eta(&(pMat->s2.vec[i]), rhoprime, eta, nonce++);
    }

    pMat->s1hat = pMat->s1;

    switch (K)
    {
        case 5:
            polyvec4_ntt((polyvec4*)&pMat->s1hat);
            break;

        case 6:
            polyvec5_ntt((polyvec5*)&pMat->s1hat);
            break;

        case 8:
            polyvec7_ntt((polyvec7*)&pMat->s1hat);
            break;

        default:
            break;
    }

    for (i = 0; i < K; ++i)
    {
        switch (K)
        {
            /* K -> L, so -1 offset is not typo */
            case 5:
                polyvec4_pointwise_acc_montgomery(&pMat->t1.vec[i],
                                                  (const polyvec4*) & (pMat->mat[i]),
                                                  (const polyvec4*)&pMat->s1hat);
                break;

            case 6:
                polyvec5_pointwise_acc_montgomery(&pMat->t1.vec[i],
                                                  (const polyvec5*) & (pMat->mat[i]),
                                                  (const polyvec5*)&pMat->s1hat);
                break;

            case 8:
                polyvec7_pointwise_acc_montgomery(&pMat->t1.vec[i],
                                                  (const polyvec7*) & (pMat->mat[i]),
                                                  (const polyvec7*)&pMat->s1hat);
                break;
        }
    }

    for (i = 0; i < K; ++i)
    {
        poly_reduce(&(pMat->t1.vec[i]));
        poly_invntt_tomont(&(pMat->t1.vec[i]));
    }

    /* Add error vector s2 (..._add()), then
     * Extract t1 and write public key
     */

    /* opportunistic: write trailing type bytes */
    if (wrpub + CRS_WTYPE_BYTES <= *pbbytes)
    {
        MSBF4_WRITE(pub + wrpub, (uint32_t)(type | MLCA_IDP_PUBLIC));
    }

    *pbbytes = wrpub;

    switch (K)
    {
        case 5:
            polyvec5_add((polyvec5*)&pMat->t1, (polyvec5*)&pMat->t1,
                         (const polyvec5*)&pMat->s2);
            polyvec5_freeze((polyvec5*)&pMat->t1);
            polyvec5_power2round((polyvec5*)&pMat->t1, (polyvec5*)&pMat->t0,
                                 (const polyvec5*)&pMat->t1);
            pack_pk5(pub, rho, (const polyvec5*)&pMat->t1);
            break;

        case 6:
            polyvec6_add((polyvec6*)&pMat->t1, (polyvec6*)&pMat->t1,
                         (const polyvec6*)&pMat->s2);
            polyvec6_freeze((polyvec6*)&pMat->t1);
            polyvec6_power2round((polyvec6*)&pMat->t1, (polyvec6*)&pMat->t0,
                                 (const polyvec6*)&pMat->t1);
            pack_pk6(pub, rho, (const polyvec6*)&pMat->t1);
            break;

        case 8:
            polyvec8_add((polyvec8*)&pMat->t1, (polyvec8*)&pMat->t1,
                         (const polyvec8*)&pMat->s2);
            polyvec8_freeze((polyvec8*)&pMat->t1);
            polyvec8_power2round((polyvec8*)&pMat->t1, (polyvec8*)&pMat->t0,
                                 (const polyvec8*)&pMat->t1);
            pack_pk8(pub, rho, (const polyvec8*)&pMat->t1);
            break;

        default:
            break;
    }

    /* Compute CRH(rho, t1) and write priv. key */

    dil_crh(tr, DIL_CRHBYTES, pub, *pbbytes);

    switch (K)
    {
        case 5:
            pack_prv5(prv, rho, key, tr, (const polyvec4*)&pMat->s1,
                      (const polyvec5*)&pMat->s2, (const polyvec5*)&pMat->t0);
            break;

        case 6:
            pack_prv6(prv, rho, key, tr, (const polyvec5*)&pMat->s1,
                      (const polyvec6*)&pMat->s2, (const polyvec6*)&pMat->t0);
            break;

        case 8:
            pack_prv8(prv, rho, key, tr, (const polyvec7*)&pMat->s1,
                      (const polyvec8*)&pMat->s2, (const polyvec8*)&pMat->t0);
            break;

        default:
            break;
    }

    /* opportunistic: write trailing type bytes */
    if (wrb + CRS_WTYPE_BYTES <= prbytes)
    {
        MSBF4_WRITE(prv + wrb, (uint32_t)type);
    }

    MEMSET(pMat, 0, sizeof(struct keygen_mat));
    MEMSET(seedbuf, 0, sizeof(seedbuf));
    MEMSET(tr, 0, sizeof(tr));

    return (int)wrb;
}

// placeholder: deref all yet-unused functions
CRS_STATIC void dr3_unused(void)
{
    if (0)
    {
        (void)dil_r3k2polyeta_bytes(0);
        (void)dilr3_k2eta(0);
        (void)spolyw1_packedbytes(0);
        (void)spolyvec4_freeze(NULL);
        (void)spolyvec5_freeze(NULL);
        (void)spolyvec6_freeze(NULL);
        (void)spolyvec6_pointwise_acc_montgomery(NULL, NULL, NULL);
        (void)spolyvec7_freeze(NULL);
        (void)spolyvec8_freeze(NULL);
        (void)spolyvec8_pointwise_acc_montgomery(NULL, NULL, NULL);
    }
}
/*--------------------------------------
 * round3 equivalent of dil_keygen()
 *
 * call only with round3 OIDs; will reject other Dilithium variants
 */
CRS_STATIC int dilr3_keygen(const void* pKey, unsigned char* prv,
                            size_t prbytes, unsigned char* pub, size_t* pbbytes,
                            void* rng, const unsigned char* algid,
                            size_t ibytes)
{
    const unsigned char* rho, *rhoprime, *key;
    unsigned char        seedbuf[2 * DIL_SEEDBYTES + DIL_R3_CRHBYTES];
    unsigned int         type, K, L, eta, round;
    unsigned char        tr[DIL_SEEDBYTES];
    size_t               wrb, wrpub;

    struct keygen_mat
    {
        spolyvec_max   mat[DIL_VECT_MAX];
        spolyvec_maxm1 s1, s1hat;  /* L */
        spolyvec_max   s2, t1, t0; /* K */
    };
    struct keygen_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    type  = crs_oid2type(algid, ibytes);
    round = dil_type2round(type);
    K     = dil_type2k(type);
    L     = dil_type2l(type);
    eta   = dil_type2eta(type);
    wrb   = dil_prv_wirebytes(K, L, round);

    if (0)
    {
        dr3_unused();
    }

    if (!type || !K || !wrb || (round != 3))
    {
        return MLCA_EKEYTYPE;
    }

    if (!eta || (eta > 4))
    {
        return MLCA_EINTERN;
    }

    if (!(CRS_ALG_FL_SIG & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    // size queries: NULL prv -> prvbytes, NULL pub -> pub.bytes
    // 'prv' is checked first
    if (!prv)
    {
        return wrb;
    }

    if (!pub)
    {
        return dil_pub_wirebytes(K, 0, round);
    }

    if (!pbbytes)
    {
        return MLCA_EPARAM;
    }

    wrpub = dil_pub_wirebytes(K, L, round);

    if ((wrb > prbytes) || (wrpub > *pbbytes))
    {
        return MLCA_ETOOSMALL;
    }

    /* do not mess with this buffer */
    BUILD_ASSERT(sizeof(seedbuf) >= 3 * DIL_SEEDBYTES);

    if (randombytes(seedbuf, DIL_SEEDBYTES, rng) < DIL_SEEDBYTES)
    {
        return MLCA_ERNG;
    }

    shake256(seedbuf, 2 * DIL_SEEDBYTES + DIL_R3_CRHBYTES, seedbuf,
             DIL_SEEDBYTES);

    rho      = seedbuf;
    rhoprime = seedbuf + DIL_SEEDBYTES;
    key      = seedbuf + DIL_SEEDBYTES + DIL_R3_CRHBYTES;

    /* Expand matrix; sample short vectors s1 and s2
     * iter.counts xL, xK, not a typo
     */
    switch (K)
    {
        case 4:
            expand_smatrix_4x4(pMat->mat, rho);
            spolyvec4_uniform_eta((spolyvec4*)&pMat->s1, rhoprime, 0, eta);
            spolyvec4_uniform_eta((spolyvec4*)&pMat->s2, rhoprime, L, eta);
            break;

        case 6:
            expand_smatrix_6x5(pMat->mat, rho);
            spolyvec5_uniform_eta((spolyvec5*)&pMat->s1, rhoprime, 0, eta);
            spolyvec6_uniform_eta((spolyvec6*)&pMat->s2, rhoprime, L, eta);
            break;

        case 8:
            expand_smatrix_8x7(pMat->mat, rho);
            spolyvec7_uniform_eta((spolyvec7*)&pMat->s1, rhoprime, 0, eta);
            spolyvec8_uniform_eta((spolyvec8*)&pMat->s2, rhoprime, L, eta);
            break;
    }

    /* matrix-vector multiplication */
    pMat->s1hat = pMat->s1;

    switch (K)
    {
        case 4:
            spolyvec4_ntt((spolyvec4*)&pMat->s1hat);  /* xL, no typo */
            spolyvec4x4_matrix_pointwise_montgomery(
                (spolyvec4*)&pMat->t1, pMat->mat, (const spolyvec4*)&pMat->s1hat);
            spolyvec4_reduce((spolyvec4*)&pMat->t1);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->t1);
            break;

        case 6:
            spolyvec5_ntt((spolyvec5*)&pMat->s1hat);
            spolyvec6x5_matrix_pointwise_montgomery(
                (spolyvec6*)&pMat->t1, pMat->mat, (const spolyvec5*)&pMat->s1hat);
            spolyvec6_reduce((spolyvec6*)&pMat->t1);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->t1);
            break;

        case 8:
            spolyvec7_ntt((spolyvec7*)&pMat->s1hat);
            spolyvec8x7_matrix_pointwise_montgomery(
                (spolyvec8*)&pMat->t1, pMat->mat, (const spolyvec7*)&pMat->s1hat);
            spolyvec8_reduce((spolyvec8*)&pMat->t1);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->t1);
            break;

        default:
            break;
    }

    /* Add error vector s2 (..._add()), then
     * Extract t1 and write public key
     */
    switch (K)
    {
        case 4:
            spolyvec4_add((spolyvec4*)&pMat->t1, (const spolyvec4*)&pMat->t1,
                          (const spolyvec4*)&pMat->s2);
            spolyvec4_caddq((spolyvec4*)&pMat->t1);
            spolyvec4_power2round((spolyvec4*)&pMat->t1, (spolyvec4*)&pMat->t0,
                                  (const spolyvec4*)&pMat->t1);
            break;

        case 6:
            spolyvec6_add((spolyvec6*)&pMat->t1, (const spolyvec6*)&pMat->t1,
                          (const spolyvec6*)&pMat->s2);
            spolyvec6_caddq((spolyvec6*)&pMat->t1);
            spolyvec6_power2round((spolyvec6*)&pMat->t1, (spolyvec6*)&pMat->t0,
                                  (const spolyvec6*)&pMat->t1);
            break;

        case 8:
            spolyvec8_add((spolyvec8*)&pMat->t1, (const spolyvec8*)&pMat->t1,
                          (const spolyvec8*)&pMat->s2);
            spolyvec8_caddq((spolyvec8*)&pMat->t1);
            spolyvec8_power2round((spolyvec8*)&pMat->t1, (spolyvec8*)&pMat->t0,
                                  (const spolyvec8*)&pMat->t1);
            break;
    }

    /* opportunistic: write trailing type bytes */
    if (wrpub + CRS_WTYPE_BYTES <= *pbbytes)
    {
        MSBF4_WRITE(pub + wrpub, (uint32_t)(type | MLCA_IDP_PUBLIC));
    }

    *pbbytes = wrpub;

    switch (K)
    {
        case 4:
            spack_pk4(pub, rho, (const spolyvec4*)&pMat->t1);
            break;

        case 6:
            spack_pk6(pub, rho, (const spolyvec6*)&pMat->t1);
            break;

        case 8:
            spack_pk8(pub, rho, (const spolyvec8*)&pMat->t1);
            break;

        default:
            break;
    }

    /* Compute H(rho, t1) and write priv. key */

    shake256(tr, DIL_SEEDBYTES, pub, *pbbytes);

    switch (K)
    {
        case 4:
            spack_prv4(prv, rho, key, tr, (const spolyvec4*)&pMat->s1,
                       (const spolyvec4*)&pMat->s2, (const spolyvec4*)&pMat->t0);
            break;

        case 6:
            spack_prv6(prv, rho, key, tr, (const spolyvec5*)&pMat->s1,
                       (const spolyvec6*)&pMat->s2, (const spolyvec6*)&pMat->t0);
            break;

        case 8:
            spack_prv8(prv, rho, key, tr, (const spolyvec7*)&pMat->s1,
                       (const spolyvec8*)&pMat->s2, (const spolyvec8*)&pMat->t0);
            break;

        default:
            break;
    }

    /* opportunistic: write trailing type bytes */
    if (wrb + CRS_WTYPE_BYTES <= prbytes)
    {
        MSBF4_WRITE(prv + wrb, (uint32_t)type);
    }

    MEMSET(pMat, 0, sizeof(struct keygen_mat));
    MEMSET(seedbuf, 0, sizeof(seedbuf));
    MEMSET(tr, 0, sizeof(tr));

    return (int)wrb;
}

/*--------------------------------------
 * mldsa equivalent of dil_keygen()
 *
 * call only with mldsa OIDs; will reject other Dilithium variants
 */
CRS_STATIC int dil_mldsa_keygen(const void* pKey, unsigned char* prv,
                                size_t prbytes, unsigned char* pub,
                                size_t* pbbytes, void* rng,
                                const unsigned char* algid, size_t ibytes)
{
    const unsigned char* rho, *rhoprime, *key;
    unsigned char        seedbuf[2 * DIL_SEEDBYTES + DIL_R3_CRHBYTES];
    unsigned int         type, K, L, eta, round;
    unsigned char        tr[DIL_MLDSA_TRBYTES];
    size_t               wrb, wrpub;

    struct keygen_mat
    {
        spolyvec_max   mat[DIL_VECT_MAX];
        spolyvec_maxm1 s1, s1hat;  /* L */
        spolyvec_max   s2, t1, t0; /* K */
    };
    struct keygen_mat mat, *pMat = &mat;
    MARK_UNUSED(pKey);

    type  = crs_oid2type(algid, ibytes);
    round = dil_type2round(type);
    K     = dil_type2k(type);
    L     = dil_type2l(type);
    eta   = dil_type2eta(type);
    wrb   = dil_prv_wirebytes(K, L, round);

    if (0)
    {
        dr3_unused();
    }

    if (!type || !K || !wrb || (round != 4))
    {
        return MLCA_EKEYTYPE;
    }

    if (!eta || (eta > 4))
    {
        return MLCA_EINTERN;
    }

    if (!(CRS_ALG_FL_SIG & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    // size queries: NULL prv -> prvbytes, NULL pub -> pub.bytes
    // 'prv' is checked first
    if (!prv)
    {
        return wrb;
    }

    if (!pub)
    {
        return dil_pub_wirebytes(K, 0, round);
    }

    if (!pbbytes)
    {
        return MLCA_EPARAM;
    }

    wrpub = dil_pub_wirebytes(K, L, round);

    if ((wrb > prbytes) || (wrpub > *pbbytes))
    {
        return MLCA_ETOOSMALL;
    }

    /* do not mess with this buffer */
    BUILD_ASSERT(sizeof(seedbuf) >= 3 * DIL_SEEDBYTES);

    if (randombytes(seedbuf, DIL_SEEDBYTES, rng) < DIL_SEEDBYTES)
    {
        return MLCA_ERNG;
    }

    /* Domain separation */
    seedbuf[DIL_SEEDBYTES]     = (uint8_t)K;
    seedbuf[DIL_SEEDBYTES + 1] = (uint8_t)L;

    shake256(seedbuf, 2 * DIL_SEEDBYTES + DIL_R3_CRHBYTES, seedbuf,
             DIL_SEEDBYTES + 2);

    rho      = seedbuf;
    rhoprime = seedbuf + DIL_SEEDBYTES;
    key      = seedbuf + DIL_SEEDBYTES + DIL_R3_CRHBYTES;

    /* Expand matrix; sample short vectors s1 and s2
     * iter.counts xL, xK, not a typo
     */
    switch (K)
    {
        case 4:
            expand_smatrix_4x4(pMat->mat, rho);
            spolyvec4_uniform_eta((spolyvec4*)&pMat->s1, rhoprime, 0, eta);
            spolyvec4_uniform_eta((spolyvec4*)&pMat->s2, rhoprime, L, eta);
            break;

        case 6:
            expand_smatrix_6x5(pMat->mat, rho);
            spolyvec5_uniform_eta((spolyvec5*)&pMat->s1, rhoprime, 0, eta);
            spolyvec6_uniform_eta((spolyvec6*)&pMat->s2, rhoprime, L, eta);
            break;

        case 8:
            expand_smatrix_8x7(pMat->mat, rho);
            spolyvec7_uniform_eta((spolyvec7*)&pMat->s1, rhoprime, 0, eta);
            spolyvec8_uniform_eta((spolyvec8*)&pMat->s2, rhoprime, L, eta);
            break;
    }

    /* matrix-vector multiplication */
    pMat->s1hat = pMat->s1;

    switch (K)
    {
        case 4:
            spolyvec4_ntt((spolyvec4*)&pMat->s1hat);  /* xL, no typo */
            spolyvec4x4_matrix_pointwise_montgomery(
                (spolyvec4*)&pMat->t1, pMat->mat, (const spolyvec4*)&pMat->s1hat);
            spolyvec4_reduce((spolyvec4*)&pMat->t1);
            spolyvec4_invntt_tomont((spolyvec4*)&pMat->t1);
            break;

        case 6:
            spolyvec5_ntt((spolyvec5*)&pMat->s1hat);
            spolyvec6x5_matrix_pointwise_montgomery(
                (spolyvec6*)&pMat->t1, pMat->mat, (const spolyvec5*)&pMat->s1hat);
            spolyvec6_reduce((spolyvec6*)&pMat->t1);
            spolyvec6_invntt_tomont((spolyvec6*)&pMat->t1);
            break;

        case 8:
            spolyvec7_ntt((spolyvec7*)&pMat->s1hat);
            spolyvec8x7_matrix_pointwise_montgomery(
                (spolyvec8*)&pMat->t1, pMat->mat, (const spolyvec7*)&pMat->s1hat);
            spolyvec8_reduce((spolyvec8*)&pMat->t1);
            spolyvec8_invntt_tomont((spolyvec8*)&pMat->t1);
            break;

        default:
            break;
    }

    /* Add error vector s2 (..._add()), then
     * Extract t1 and write public key
     */
    switch (K)
    {
        case 4:
            spolyvec4_add((spolyvec4*)&pMat->t1, (const spolyvec4*)&pMat->t1,
                          (const spolyvec4*)&pMat->s2);
            spolyvec4_caddq((spolyvec4*)&pMat->t1);
            spolyvec4_power2round((spolyvec4*)&pMat->t1, (spolyvec4*)&pMat->t0,
                                  (const spolyvec4*)&pMat->t1);
            break;

        case 6:
            spolyvec6_add((spolyvec6*)&pMat->t1, (const spolyvec6*)&pMat->t1,
                          (const spolyvec6*)&pMat->s2);
            spolyvec6_caddq((spolyvec6*)&pMat->t1);
            spolyvec6_power2round((spolyvec6*)&pMat->t1, (spolyvec6*)&pMat->t0,
                                  (const spolyvec6*)&pMat->t1);
            break;

        case 8:
            spolyvec8_add((spolyvec8*)&pMat->t1, (const spolyvec8*)&pMat->t1,
                          (const spolyvec8*)&pMat->s2);
            spolyvec8_caddq((spolyvec8*)&pMat->t1);
            spolyvec8_power2round((spolyvec8*)&pMat->t1, (spolyvec8*)&pMat->t0,
                                  (const spolyvec8*)&pMat->t1);
            break;
    }

    /* opportunistic: write trailing type bytes */
    if (wrpub + CRS_WTYPE_BYTES <= *pbbytes)
    {
        MSBF4_WRITE(pub + wrpub, (uint32_t)(type | MLCA_IDP_PUBLIC));
    }

    *pbbytes = wrpub;

    switch (K)
    {
        case 4:
            spack_pk4(pub, rho, (const spolyvec4*)&pMat->t1);
            break;

        case 6:
            spack_pk6(pub, rho, (const spolyvec6*)&pMat->t1);
            break;

        case 8:
            spack_pk8(pub, rho, (const spolyvec8*)&pMat->t1);
            break;

        default:
            break;
    }

    /* Compute H(rho, t1) and write priv. key */

    shake256(tr, DIL_MLDSA_TRBYTES, pub, *pbbytes);

    switch (K)
    {
        case 4:
            ml_spack_prv4(prv, rho, key, tr, (const spolyvec4*)&pMat->s1,
                          (const spolyvec4*)&pMat->s2,
                          (const spolyvec4*)&pMat->t0);
            break;

        case 6:
            ml_spack_prv6(prv, rho, key, tr, (const spolyvec5*)&pMat->s1,
                          (const spolyvec6*)&pMat->s2,
                          (const spolyvec6*)&pMat->t0);
            break;

        case 8:
            ml_spack_prv8(prv, rho, key, tr, (const spolyvec7*)&pMat->s1,
                          (const spolyvec8*)&pMat->s2,
                          (const spolyvec8*)&pMat->t0);
            break;

        default:
            break;
    }

    /* opportunistic: write trailing type bytes */
    if (wrb + CRS_WTYPE_BYTES <= prbytes)
    {
        MSBF4_WRITE(prv + wrb, (uint32_t)type);
    }

    MEMSET(pMat, 0, sizeof(struct keygen_mat));
    MEMSET(seedbuf, 0, sizeof(seedbuf));
    MEMSET(tr, 0, sizeof(tr));

    return (int)wrb;
}
#endif /*-----  /delimiter: sign/verify  ------------------------------*/

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*-- Kyber ------*/

/*************************************************
 * Description: Generates public and private key for the CPA-secure
 *              public-key encryption scheme underlying Kyber
 *
 * Arguments:   - uint8_t *pk: pointer to output public key
 *                             (of length KYB_INDCPA_PUBLICKEYBYTES bytes)
 *              - uint8_t *sk: pointer to output private key
 *                             (of length KYB_INDCPA_SECRETKEYBYTES bytes)
 **************************************************/
CRS_STATIC int kyb_keygen_derand(unsigned char* prv, size_t prvbytes,
                                 unsigned char* pub, size_t* pbytes,
                                 uint8_t* coins, const unsigned char* algid,
                                 size_t ibytes)
{
    uint8_t        buf[2 * KYB_SYMBYTES] CRS_SENSITIVE;

    // noise[32] || pub.seed[32]; MUST be consecutive
    kpolyvec_max   a[KYB_VECT_MAX], e, pkpv, skpv;
    const uint8_t* noiseseed;
    const uint8_t* publicseed = buf;
    unsigned int   i, type, k, round;
    size_t         pubb, prvb;
    uint8_t        nonce = 0;

    type  = crs_oid2type(algid, ibytes);
    k     = kyb_type2k(type);
    round = kyb_type2round(type);

    if (!type || !k)
    {
        return MLCA_EKEYTYPE;
    }

    if (!((CRS_ALG_FL_KEX | CRS_ALG_FL_CIP) & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    /* Add domain separation byte to seed: Alg 13 in FIPS203 // without the
     * check it's ML-KEM-ipd */
    if (round == 4)
    {
        MEMCPY(buf, coins, KYB_SYMBYTES);
        buf[KYB_SYMBYTES] = (uint8_t)k;
        noiseseed         = buf + KYB_SYMBYTES;
        kyb_hash_g(buf, buf, KYB_SYMBYTES + 1);   // PRF[32+1] -> PRF[64]
    }
    else
    {
        MEMCPY(buf, coins, KYB_SYMBYTES);
        noiseseed = buf + KYB_SYMBYTES;
        kyb_hash_g(buf, buf, KYB_SYMBYTES);   // PRF[32] -> PRF[64]
    }

    prvb = kyb_prv_wirebytes(k, 1 /* full */);
    pubb = kyb_pub_wirebytes(k);

    if (!prvb || !pubb)
    {
        return MLCA_EKEYTYPE;
    }

    // size queries: NULL prv -> prvbytes, NULL pub -> pub.bytes
    // 'prv' is checked first
    if (!prv)
    {
        return prvb;
    }

    if (!pub)
    {
        return pubb;
    }

    if ((*pbytes < pubb) || (prvbytes < prvb))
    {
        return MLCA_ETOOSMALL;
    }

    switch (kyb_type2round(type))
    {
        case 2:
            KYB_GEN_A(a, publicseed, k);

            for (i = 0; i < k; i++)
            {
                kpoly_getnoise(&skpv.vec[i], noiseseed, nonce++);
            }

            for (i = 0; i < k; i++)
            {
                kpoly_getnoise(&e.vec[i], noiseseed, nonce++);
            }

            switch (k)
            {
                case 3:
                    kpolyvec3_ntt((kpolyvec3*)&skpv);
                    kpolyvec3_ntt((kpolyvec3*)&e);
                    break;

                case 4:
                    kpolyvec4_ntt((kpolyvec4*)&skpv);
                    kpolyvec4_ntt((kpolyvec4*)&e);
                    break;
            }

            // matrix-vector multiplication
            for (i = 0; i < k; i++)
            {
                if (k == 3)
                {
                    kpolyvec3_pointwise_acc_montgomery(&pkpv.vec[i],
                                                       (const kpolyvec3*)&a[i],
                                                       (const kpolyvec3*)&skpv);
                }
                else
                {
                    kpolyvec4_pointwise_acc_montgomery(&pkpv.vec[i],
                                                       (const kpolyvec4*)&a[i],
                                                       (const kpolyvec4*)&skpv);
                }

                kpoly_tomont(&pkpv.vec[i]);
            }

            switch (k)
            {
                case 3:
                    kpolyvec3_add((kpolyvec3*)&pkpv, (const kpolyvec3*)&pkpv,
                                  (const kpolyvec3*)&e);
                    kpolyvec3_reduce((kpolyvec3*)&pkpv);
                    kpack_sk3(prv, (kpolyvec3*)&skpv);
                    kpack_pk3(pub, (kpolyvec3*)&pkpv, publicseed);
                    break;

                case 4:
                    kpolyvec4_add((kpolyvec4*)&pkpv, (const kpolyvec4*)&pkpv,
                                  (const kpolyvec4*)&e);
                    kpolyvec4_reduce((kpolyvec4*)&pkpv);
                    kpack_sk4(prv, (kpolyvec4*)&skpv);
                    kpack_pk4(pub, (kpolyvec4*)&pkpv, publicseed);
                    break;
            }

            break;

        case 3:
        case 4:
            R3_KYB_GEN_A(a, publicseed, k);

            for (i = 0; i < k; i++)
            {
                r3_kpoly_getnoise_eta1(&skpv.vec[i], noiseseed, nonce++);
            }

            for (i = 0; i < k; i++)
            {
                r3_kpoly_getnoise_eta1(&e.vec[i], noiseseed, nonce++);
            }

            switch (k)
            {
                case 3:
                    r3_kpolyvec3_ntt((kpolyvec3*)&skpv);
                    r3_kpolyvec3_ntt((kpolyvec3*)&e);
                    break;

                case 4:
                    r3_kpolyvec4_ntt((kpolyvec4*)&skpv);
                    r3_kpolyvec4_ntt((kpolyvec4*)&e);
                    break;
            }

            // matrix-vector multiplication
            for (i = 0; i < k; i++)
            {
                if (k == 3)
                {
                    r3_kpolyvec3_basemul_acc_montgomery(&pkpv.vec[i],
                                                        (const kpolyvec3*)&a[i],
                                                        (const kpolyvec3*)&skpv);
                }
                else
                {
                    r3_kpolyvec4_basemul_acc_montgomery(&pkpv.vec[i],
                                                        (const kpolyvec4*)&a[i],
                                                        (const kpolyvec4*)&skpv);
                }

                r3_kpoly_tomont(&pkpv.vec[i]);
            }

            switch (k)
            {
                case 3:
                    kpolyvec3_add((kpolyvec3*)&pkpv, (const kpolyvec3*)&pkpv,
                                  (const kpolyvec3*)&e);
                    r3_kpolyvec3_reduce((kpolyvec3*)&pkpv);
                    r3_kpack_sk3(prv, (kpolyvec3*)&skpv);
                    r3_kpack_pk3(pub, (kpolyvec3*)&pkpv, publicseed);
                    break;

                case 4:
                    kpolyvec4_add((kpolyvec4*)&pkpv, (const kpolyvec4*)&pkpv,
                                  (const kpolyvec4*)&e);
                    r3_kpolyvec4_reduce((kpolyvec4*)&pkpv);
                    r3_kpack_sk4(prv, (kpolyvec4*)&skpv);
                    r3_kpack_pk4(pub, (kpolyvec4*)&pkpv, publicseed);
                    break;
            }

            break;

        default:   // nop
            break;
    }

    /* opportunistic: write trailing type bytes */
    if (pubb + CRS_WTYPE_BYTES <= *pbytes)
    {
        MSBF4_WRITE(pub + pubb, (uint32_t)(type | MLCA_IDP_PUBLIC));
    }

    *pbytes = pubb;

    /* INDCPA-to-KEM, add PK-derived parts, see crypto_kem_keypair() */
    {
        size_t prv0b = kyb_prv_wirebytes(k, 0);
        /* net prv-key bytes [at start] */

        /* INDCPA skips including pub.key; assume KEM */
        MEMMOVE(prv + prv0b, pub, pubb);
        /* please do not comment on not using MEMCPY() */

        /* note: 32 bytes (hash) + KYB_SYMBYTES appended
         * to the _public_ part of the _private_ key's
         * pub.key field
         *
         * see KYB_PRV2PUB_ADDL_BYTES
         */

        kyb_hash_h(prv + prv0b + pubb, pub, pubb);

        MEMCPY(prv + prvb - KYB_SYMBYTES, coins + KYB_SYMBYTES, KYB_SYMBYTES);

        // if ( randombytes(prv + prvb - KYB_SYMBYTES, KYB_SYMBYTES, rng) <
        // KYB_SYMBYTES )
        //     return MLCA_ERNG;
    }

    /* opportunistic: write trailing type bytes */
    if (prvb + CRS_WTYPE_BYTES <= prvbytes)
    {
        MSBF4_WRITE(prv + prvb, (uint32_t)type);
    }

    MEMSET0_STRICT(buf, sizeof(buf));
    MEMSET0_STRICT(coins, sizeof(coins));

    return 0;
}

CRS_STATIC int kyb_keygen(unsigned char* prv, size_t prvbytes,
                          unsigned char* pub, size_t* pbytes, void* rng,
                          const unsigned char* algid, size_t ibytes)
{
    uint8_t
    coins[2 * KYB_SYMBYTES];   // provided on the derandomized interface.
    // noise[32] || pub.seed[32]; MUST be consecutive
    unsigned int i, type, k, round;

    type  = crs_oid2type(algid, ibytes);
    k     = kyb_type2k(type);
    round = kyb_type2round(type);

    if (!type || !k)
    {
        return MLCA_EKEYTYPE;
    }

    if (!((CRS_ALG_FL_KEX | CRS_ALG_FL_CIP) & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    /* Add domain separation byte to seed: Alg 13 in FIPS203 // without the
     * check it's ML-KEM-ipd */
    if (round == 4)
    {
        if (randombytes(coins, 2 * KYB_SYMBYTES, rng) < KYB_SYMBYTES)
        {
            return MLCA_ERNG;
        }
    }
    else
    {
        if (randombytes(coins, KYB_SYMBYTES, rng) < KYB_SYMBYTES)
        {
            return MLCA_ERNG;
        }

        if (randombytes(coins + KYB_SYMBYTES, KYB_SYMBYTES, rng) < KYB_SYMBYTES)
        {
            return MLCA_ERNG;
        }
    }

    return kyb_keygen_derand(prv, prvbytes, pub, pbytes, coins, algid, ibytes);
}

#endif /*-----  /delimiter: Kyber  ------------------------------------*/

#if !defined(NO_CRYSTALS_KEX) /*-- Kyber, key agreement  ------------------*/
/*************************************************
 * Description: Generates cipher text and shared
 *              secret for given public key
 *
 * Arguments:   - unsigned char *ct: pointer to output cipher text
 *                (an already allocated array of CRYPTO_CIPHERTEXTBYTES bytes)
 *              - unsigned char *ss: pointer to output shared secret
 *                (an already allocated array of CRYPTO_BYTES bytes)
 *              - const unsigned char *pk: pointer to input public key
 *                (an already allocated array of CRYPTO_PUBLICKEYBYTES bytes)
 * Returns >0 (success; written bytecount at start of (ct)) or <0 for errors
 **************************************************/
CRS_STATIC int kyb_kem1_derand(unsigned char* ct, size_t cbytes,
                               unsigned char* shrd, size_t* shbytes,
                               const unsigned char* pub, size_t pbytes,
                               uint8_t* coins, const unsigned char* algid,
                               size_t ibytes)
{
    unsigned char buf[2 * KYB_SYMBYTES];
    unsigned char kr[2 * KYB_SYMBYTES] CRS_SENSITIVE;
    unsigned int  type = 0, k, round;
    size_t        pubb, ctxtb;

    if (algid && ibytes)
    {
        type = crs_oid2type(algid, ibytes);
    }
    else if (pub && (pbytes == kyb_pub_wirebytes(3)))
    {
        type = MLCA_ID_KYB3_R2;
    }
    else if (pub && (pbytes == kyb_pub_wirebytes(4)))
    {
        type = MLCA_ID_KYB4_R2;
    }

    k     = kyb_type2k(type);
    pubb  = kyb_pub_wirebytes(k);
    ctxtb = kyb_ctext_wirebytes(k);
    round = kyb_type2round(type);

    if (round < 2 || round > 4)
    {
        return MLCA_ENSUPPORT;
    }

    if (!pubb || !ctxtb || (pubb != pbytes)) /* catches unknown type */
    {
        return MLCA_EKEYTYPE;
    }

    if (!((CRS_ALG_FL_KEX | CRS_ALG_FL_CIP) & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    // size queries, minimum checks
    if (!ct)
    {
        return (int)ctxtb;
    }
    else if (cbytes < ctxtb)
    {
        return MLCA_ETOOSMALL;
    }

    if (!shrd)
    {
        return (int)KYB_SHRDBYTES;
    }
    else if (*shbytes < KYB_SHRDBYTES)
    {
        return MLCA_ETOOSMALL;
    }

    *shbytes = KYB_SHRDBYTES;

    MEMCPY(buf, coins, KYB_SYMBYTES);

    if (round < 4)
    {
        /* Do not release system RNG output */
        kyb_hash_h(buf, buf, KYB_SYMBYTES);
    }

    /* Multitarget countermeasure for coins + contributory KEM */
    kyb_hash_h(buf + KYB_SYMBYTES, pub, pbytes);

    kyb_hash_g(kr, buf, 2 * KYB_SYMBYTES);

    /* coins are in kr+KYB_SYMBYTES */

    switch (kyb_type2round(type))
    {
        case 2:
            indcpa_enc(ct, cbytes, buf, pub, pbytes, kr + KYB_SYMBYTES, k);
            break;

        case 3:
            r3_indcpa_enc(ct, cbytes, buf, pub, pbytes, kr + KYB_SYMBYTES, k);
            break;

        case 4:
            mlkem_indcpa_enc(ct, cbytes, buf, pub, pbytes, kr + KYB_SYMBYTES, k, 1);
            break;

        default:   // nop
            break;
    }

    if (round < 4)
    {
        /* overwrite coins in kr with H(c) */
        kyb_hash_h(kr + KYB_SYMBYTES, ct, ctxtb);

        /* hash concatenation of pre-k and H(c) to k */
        /* kdf(ss, kr, 2*KYB_SYMBYTES); */
        shake256(shrd, KYB_SHRDBYTES, kr, 2 * KYB_SYMBYTES);
    }
    else
    {

        /**
         * FIPS 204:
         * "... , ML-KEM.Encaps no longer includes a hash of the ciphertext in
         * the derivation of the shared secret"
         */
        MEMCPY(shrd, kr, KYB_SYMBYTES);
    }

    return (int)ctxtb;
}

CRS_STATIC int kyb_kem1(unsigned char* ct, size_t cbytes, unsigned char* shrd,
                        size_t* shbytes, const unsigned char* pub,
                        size_t pbytes, void* rng, const unsigned char* algid,
                        size_t ibytes)
{
    int     rc = 0;
    uint8_t coins[KYB_SYMBYTES];

    if (randombytes(coins, KYB_SYMBYTES, rng) < KYB_SYMBYTES)
    {
        rc = MLCA_ERNG;
        goto err;
    }

    rc = kyb_kem1_derand(ct, cbytes, shrd, shbytes, pub, pbytes, coins, algid,
                         ibytes);

err:
    MEMSET0_STRICT(coins, KYB_SYMBYTES);
    return rc;
}

/*************************************************
 * Description: Compare two arrays for equality in constant time.
 *
 * Arguments:   const uint8_t *a: pointer to first byte array
 *              const uint8_t *b: pointer to second byte array
 *              size_t len:       length of the byte arrays
 *
 * Returns 0 if the byte arrays are equal, 1 otherwise
 **************************************************/
CRS_STATIC int kyb_verify(const uint8_t* a, const uint8_t* b, size_t len)
{
    uint8_t r = 0;
    size_t  i;

    for (i = 0; i < len; i++)
    {
        r |= a[i] ^ b[i];
    }

    return (-(uint64_t)r) >> 63;
}

/*************************************************
 * Description: Copy len bytes from x to r if b is 1;
 *              don't modify x if b is 0. Requires b to be in {0,1};
 *              assumes two's complement representation of negative integers.
 *              Runs in constant time.
 *
 * Arguments:   uint8_t *r:       pointer to output byte array
 *              const uint8_t *x: pointer to input byte array
 *              size_t len:       Amount of bytes to be copied
 *              uint8_t b:        Condition bit; has to be in {0,1}
 **************************************************/
CRS_STATIC void kyb_cmov(uint8_t* r, const uint8_t* x, size_t len, uint8_t b)
{
    size_t i;
    b ^= uint8_t_blocker;
    b = -b;

    for (i = 0; i < len; i++)
    {
        r[i] ^= b & (r[i] ^ x[i]);
    }
}

/*************************************************
 * Description: Generates shared secret for given
 *              cipher text and private key
 *
 * Arguments:   - unsigned char *ss: pointer to output shared secret
 *                (an already allocated array of CRYPTO_BYTES bytes)
 *              - const unsigned char *ct: pointer to input cipher text
 *                (an already allocated array of CRYPTO_CIPHERTEXTBYTES bytes)
 *              - const unsigned char *sk: pointer to input private key
 *                (an already allocated array of CRYPTO_SECRETKEYBYTES bytes)
 *
 * Returns >0 upon success (shared-secret bytecount)
 *
 * On failure, (shared, sbytes) will contain a pseudo-random value.
 **************************************************/
CRS_STATIC int kyb_kem2(unsigned char* shared, size_t sbytes,
                        const unsigned char* ct, size_t cbytes,
                        const unsigned char* prv, size_t pbytes,
                        const unsigned char* algid, size_t ibytes)
{
    uint8_t       cmp[KYB_CIPHERTXT_MAX_BYTES];
    unsigned char buf[2 * KYB_SYMBYTES];
    unsigned char kr[2 * KYB_SYMBYTES] CRS_SENSITIVE;
    unsigned int  k, type = 0, round;
    size_t        i, ctxtb, prvb;
    int           fail = 0;

    if (algid && ibytes)
    {
        type = crs_oid2type(algid, ibytes);
    }
    else if (prv && (pbytes == kyb_prv_wirebytes(3, 1 /*full key*/)))
    {
        type = MLCA_ID_KYB3_R2;
    }
    else if (prv && (pbytes == kyb_prv_wirebytes(4, 1 /*full key*/)))
    {
        type = MLCA_ID_KYB4_R2;
    }

    k     = kyb_type2k(type);
    prvb  = kyb_prv_wirebytes(k, 1);
    ctxtb = kyb_ctext_wirebytes(k);
    round = kyb_type2round(type);

    if (round < 2 || round > 4)
    {
        return MLCA_ENSUPPORT;
    }

    if (!prvb || !ctxtb || (prvb != pbytes)) /* catches unknown type */
    {
        return MLCA_EKEYTYPE;
    }

    if (!((CRS_ALG_FL_KEX | CRS_ALG_FL_CIP) & crs_type2category(type)))
    {
        return MLCA_EKEYMODE;
    }

    /* size query; minimum check */
    if (!shared)
    {
        return (int)KYB_SHRDBYTES;
    }
    else if (sbytes < KYB_SHRDBYTES)
    {
        return MLCA_ETOOSMALL;
    }

    if (round >= 4)
    {
        /* Hash check: required in FIPS 203 */
        kyb_hash_h(buf, prv + 384 * k, 768 * k + 32 - 384 * k);

        if (kyb_verify(buf, prv + 768 * k + 32, 32))
        {
            return MLCA_EKEYTYPE;
        }
    }

    switch (round)
    {
        case 2:
            indcpa_dec(buf, ct, cbytes, prv, k);
            break;

        case 3:
        case 4:
            r3_indcpa_dec(buf, ct, cbytes, prv, k);
            break;

        default:   // nop
            break;
    }

    /* Multitarget countermeasure for coins + contributory KEM */

    for (i = 0; i < KYB_SYMBYTES; i++)
    {
        buf[KYB_SYMBYTES + i] = prv[prvb - 2 * KYB_SYMBYTES + i];
    }

    kyb_hash_g(kr, buf, 2 * KYB_SYMBYTES);

    /* +...wirebytes...: skip to pub.key within prv */
    /* coins are in kr+KYB_SYMBYTES */

    switch (round)
    {
        case 2:
            indcpa_enc(cmp, sizeof(cmp), buf, prv + kyb_prv_wirebytes(k, 0),
                       kyb_pub_wirebytes(k), kr + KYB_SYMBYTES, k);
            break;

        case 3:
            r3_indcpa_enc(cmp, sizeof(cmp), buf, prv + kyb_prv_wirebytes(k, 0),
                          kyb_pub_wirebytes(k), kr + KYB_SYMBYTES, k);
            break;

        case 4:
            mlkem_indcpa_enc(cmp, sizeof(cmp), buf, prv + kyb_prv_wirebytes(k, 0),
                             kyb_pub_wirebytes(k), kr + KYB_SYMBYTES, k, 0);
            break;

        default:   // nop
            break;
    }

    fail = kyb_verify(ct, cmp, ctxtb);

    if (round < 4)
    {
        /* overwrite coins in kr with H(c) */
        kyb_hash_h(kr + KYB_SYMBYTES, ct, ctxtb);

        /* Overwrite pre-k with z on re-encryption failure */
        kyb_cmov(kr, prv + pbytes - KYB_SYMBYTES, KYB_SYMBYTES, fail);

        /* hash concatenation of pre-k and H(c) to k */
        shake256(shared, KYB_SHRDBYTES, kr, 2 * KYB_SYMBYTES);
    }
    else
    {
        /* Updated FO in FIPS 203 */
        /* Compute rejection key */
        mlkem_rkprf(shared, prv + pbytes - KYB_SYMBYTES, ct, ctxtb);
        /* Overwrite pre-k with z on re-encryption failure */
        kyb_cmov(shared, kr, KYB_SYMBYTES, !fail);
    }

    return KYB_SHRDBYTES;
}

#endif /*----  NO_CRYSTALS_KEX, Kyber, key agreement  -------------------*/
#endif /*-----  /delimiter: key.generate  -----------------------------*/
#endif /*-----  /delimiter: Crystals core  ----------------------------*/

#if 0 /*-----  delimiter: PKCS11 wrappers  ---------------------------*/
CRS_STATIC
/*-----  delimiter: mlca_generate ----------------------*/
int __mlca_generate(const void* pKey, unsigned char* prv, size_t prvbytes,
                    unsigned char* pub, size_t* pubbytes, void* rng,
                    const unsigned char* algid, size_t ibytes)
{
    unsigned int cat, type;
    int          rc    = 0;
    int          round = 0;

    if (!prv || !prvbytes || !pub || !pubbytes)
    {
        return 0;
    }

    type = crs_oid2type(algid, ibytes);
    cat  = crs_type2category(type);

    do
    {
#if !defined(NO_CRYSTALS_SIG)

        if (CRS_ALG_FL_SIG & cat)
        {
            round = dil_type2round(type);

            if (round == 2)
            {
                rc = dil_keygen(pKey, prv, prvbytes, pub, pubbytes, rng, algid,
                                ibytes);
            }
            else if (round == 3)
            {
                rc = dilr3_keygen(pKey, prv, prvbytes, pub, pubbytes, rng,
                                  algid, ibytes);
            }
            else if (round == 4)
            {
                rc = dil_mldsa_keygen(pKey, prv, prvbytes, pub, pubbytes, rng,
                                      algid, ibytes);
            }
            else
            {
                return 0;
            }

            break;
        }

#endif

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX)

        if ((CRS_ALG_FL_KEX | CRS_ALG_FL_CIP) & cat)
        {
            rc = kyb_keygen(prv, prvbytes, pub, pubbytes, rng, algid, ibytes);
            break;
        }

#endif

        rc = MLCA_EKEYTYPE;
    }
    while (0);

    return rc;
}
CRS_STATIC
/**/
int mlca_generate(unsigned char* prv, size_t prvbytes, unsigned char* pub,
                  size_t* pubbytes, void* rng, const unsigned char* algid,
                  size_t ibytes)
{
    return __mlca_generate(0, prv, prvbytes, pub, pubbytes, rng, algid, ibytes);
}
/*-----  /delimiter: mlca_generate ----------------------*/

/*------------------------------------*/
CRS_STATIC
/*-----  delimiter: mlca_sign ----------------------*/
int __mlca_sign(const void* pKey, unsigned char* sig, size_t sbytes,
                const unsigned char* msg, size_t mbytes,
                const unsigned char* prv, size_t pbytes, void* rng,
                const unsigned char* algid, size_t ibytes)
{
    unsigned int round;
    int          v;
    unsigned int type = 0;

    if (!sig || !sbytes || !msg || !mbytes || !prv || !pbytes)
    {
        (void)0;
    }

    if (algid && ibytes)
    {
        type = crs_oid2type(algid, ibytes);
    }
    else
    {
        // Only supported for round 2 and round 3
        type = dil_sigbytes2type(sbytes);
    }

    round = dil_type2round(type);

    if ((round < 2) || (round > 4))
    {
        return 0;
    }

    if (round == 2)
    {
        v = r2_sign(pKey, sig, sbytes, msg, mbytes, prv, pbytes, 0);
    }
    else if (round == 3)
    {
        v = r3_sign(pKey, sig, sbytes, msg, mbytes, prv, pbytes, 0);
    }
    else if (round == 4)
    {
        v = mldsa_sign(pKey, sig, sbytes, msg, mbytes, prv, pbytes, 0, rng);
    }
    else
    {
        /* ...does not correspond to any known type... */
    }

    return v;
}
CRS_STATIC
/**/
int mlca_sign(unsigned char* sig, size_t sbytes, const unsigned char* msg,
              size_t mbytes, const unsigned char* prv, size_t pbytes, void* rng,
              const unsigned char* algid, size_t ibytes)
{
    return __mlca_sign(0, sig, sbytes, msg, mbytes, prv, pbytes, rng, algid,
                       ibytes);
}
/*-----  /delimiter: mlca_sign ----------------------*/

/*------------------------------------*/
CRS_STATIC
/*-----  delimiter: mlca_sign_internal ----------------------*/
int __mlca_sign_internal(const void* pKey, unsigned char* sig, size_t sbytes,
                         const unsigned char* msg, size_t mbytes,
                         const unsigned char* prv, size_t pbytes, void* rng,
                         const unsigned char* algid, size_t ibytes)
{
    unsigned int round;
    int          v;
    unsigned int type = 0;

    uint8_t      coins[DIL_MLDSA_RNDBYTES];

    if (!sig || !sbytes || !msg || !mbytes || !prv || !pbytes || !rng)
    {
        (void)0;
    }

    if (algid && ibytes)
    {
        type = crs_oid2type(algid, ibytes);
    }
    else
    {
        // Only supported for round 2 and round 3
        type = dil_sigbytes2type(sbytes);
    }

    round = dil_type2round(type);

    if (round != 4)
    {
        return 0;
    }
    else
    {
        randombytes(coins, DIL_MLDSA_RNDBYTES, rng);

        v = mldsa_sign_internal(pKey, sig, sbytes, msg, mbytes, prv, pbytes, 0,
                                0, 0, coins);
    }

    MEMSET0_STRICT(coins, DIL_MLDSA_RNDBYTES);

    return v;
}
CRS_STATIC
/**/
int mlca_sign_internal(unsigned char* sig, size_t sbytes,
                       const unsigned char* msg, size_t mbytes,
                       const unsigned char* prv, size_t pbytes, void* rng,
                       const unsigned char* algid, size_t ibytes)
{
    return __mlca_sign_internal(0, sig, sbytes, msg, mbytes, prv, pbytes, rng,
                                algid, ibytes);
}
/*-----  /delimiter: mlca_sign_internal ----------------------*/

/*------------------------------------*/
CRS_STATIC
/*-----  delimiter: mlca_verify ----------------------*/
int __mlca_verify(const void* pKey, const unsigned char* sig, size_t sbytes,
                  const unsigned char* msg, size_t mbytes,
                  const unsigned char* pub, size_t pbytes,
                  const unsigned char* algid, size_t ibytes)
{
    unsigned int round;
    int          v    = 0;
    unsigned int type = 0;

    if (!sig || !sbytes || !msg || !mbytes || !pub || !pbytes)
    {
        (void)0;
    }

    if (algid && ibytes)
    {
        type = crs_oid2type(algid, ibytes);
    }
    else
    {
        // Only supported for round 2 and round 3
        type = dil_sigbytes2type(sbytes);
    }

    round = dil_type2round(type);

    if ((round < 2) || (round > 4))
    {
        return 0;
    }

    // ...type cross-check...

    if (round == 2)
    {
        v = r2_verify(pKey, sig, sbytes, msg, mbytes, pub, pbytes);
    }
    else if (round == 3)
    {
        v = r3_verify(pKey, sig, sbytes, msg, mbytes, pub, pbytes);
    }
    else if (round == 4)
    {
        v = mldsa_verify(sig, sbytes, msg, mbytes, pub, pbytes);
    }
    else
    {
        /* ...does not correspond to any known type... */
    }

    return v;
}
CRS_STATIC
/**/
int mlca_verify(const unsigned char* sig, size_t sbytes,
                const unsigned char* msg, size_t mbytes,
                const unsigned char* pub, size_t pbytes,
                const unsigned char* algid, size_t ibytes)
{
    return __mlca_verify(0, sig, sbytes, msg, mbytes, pub, pbytes, algid,
                         ibytes);
}
/*-----  /delimiter: mlca_verify ----------------------*/

/*------------------------------------*/
CRS_STATIC
/*-----  delimiter: mlca_verify_internal ----------------------*/
int __mlca_verify_internal(const void* pKey, const unsigned char* sig,
                           size_t sbytes, const unsigned char* msg,
                           size_t mbytes, const unsigned char* pub,
                           size_t pbytes, const unsigned char* algid,
                           size_t ibytes)
{
    unsigned int round;
    int          v    = 0;
    unsigned int type = 0;

    if (!sig || !sbytes || !msg || !mbytes || !pub || !pbytes)
    {
        (void)0;
    }

    if (algid && ibytes)
    {
        type = crs_oid2type(algid, ibytes);
    }
    else
    {
        // Only supported for round 2 and round 3
        type = dil_sigbytes2type(sbytes);
    }

    round = dil_type2round(type);

    if (round != 4)
    {
        return 0;
    }
    else
    {
        MARK_UNUSED(pKey);
        v = mldsa_verify_internal(sig, sbytes, msg, mbytes, pub, pbytes,
                                  0, 0);
    }

    return v;
}
CRS_STATIC
/**/
int mlca_verify_internal(const unsigned char* sig, size_t sbytes,
                         const unsigned char* msg, size_t mbytes,
                         const unsigned char* pub, size_t pbytes,
                         const unsigned char* algid, size_t ibytes)
{
    return __mlca_verify_internal(0, sig, sbytes, msg, mbytes, pub, pbytes,
                                  algid, ibytes);
}
/*-----  /delimiter: mlca_verify_internal ----------------------*/

#if !defined(NO_CRYSTALS_KEX) /*-- Kyber, key agreement  ------------------*/
CRS_STATIC
/**/
int mlca_kem1(unsigned char* cipher, size_t cbytes, unsigned char* secr,
              size_t* sbytes, const unsigned char* pub, size_t pbytes,
              void* rng, const unsigned char* algid, size_t ibytes)
{
    return kyb_kem1(cipher, cbytes, secr, sbytes, pub, pbytes, rng, algid,
                    ibytes);
}

/*------------------------------------*/
CRS_STATIC
/**/
int mlca_kem2(unsigned char* secr, size_t sbytes, const unsigned char* cipher,
              size_t cbytes, const unsigned char* prv, size_t pbytes,
              const unsigned char* algid, size_t ibytes)
{
    return kyb_kem2(secr, sbytes, cipher, cbytes, prv, pbytes, algid, ibytes);
}
#endif /*-----  /delimiter: Kyber, key agreement  ---------------------*/

/*--------------------------------------
 */
CRS_STATIC
/**/
int mlca_key2wire(unsigned char* wire, size_t wbytes, const unsigned char* key,
                  size_t kbytes, unsigned int flags, const unsigned char* pub,
                  size_t pbytes, const unsigned char* algid, size_t ibytes)
{
    size_t wr = 0;

    do
    {
#if !defined(NO_CRYSTALS_SIG)
        wr = dil_prv2wire(wire, wbytes, key, kbytes, flags, pub, pbytes, algid,
                          ibytes);

        if (wr)
        {
            break;
        }

        wr = dil_pub2wire(wire, wbytes, key, kbytes, algid, ibytes);

        if (wr)
        {
            break;
        }

#endif

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX) /*-- Kyber ------*/
        wr = kyb_prv2wire(wire, wbytes, key, kbytes, algid, ibytes);

        if (wr)
        {
            break;
        }

        wr = kyb_pub2wire(wire, wbytes, key, kbytes, algid, ibytes);
#endif
    }
    while (0);

    MARK_UNUSED(flags);
    MARK_UNUSED(pub);
    MARK_UNUSED(pbytes);

    /* ...log any specific other error here... */

    return (int)wr;
}

/*------------------------------------*/
CRS_STATIC
/**/
int mlca_wire2key(unsigned char* key, size_t kbytes, unsigned int* type,
                  const unsigned char* wire, size_t wbytes,
                  const unsigned char* algid, size_t ibytes)
{
    unsigned int wtype = 0;
    size_t       wr    = 0;

    do
    {
#if !defined(NO_CRYSTALS_SIG)
        wr = dil_wire2pub(key, kbytes, &wtype, wire, wbytes, algid, ibytes);

        if (wr)
        {
            break;
        }

        wr = dil_wire2prv(key, kbytes, &wtype, wire, wbytes, algid, ibytes);

        if (wr)
        {
            break;
        }

#endif

#if !defined(NO_CRYSTALS_CIP) || !defined(NO_CRYSTALS_KEX)
        wr = kyb_wire2prv(key, kbytes, &wtype, wire, wbytes, algid, ibytes);

        if (wr)
        {
            break;
        }

        wr = kyb_wire2pub(key, kbytes, &wtype, wire, wbytes, algid, ibytes);
#endif

    }
    while (0);

    if (wr == CRS__SZ_ETOOSMALL)
    {
        return MLCA_ETOOSMALL;
    }
    else if (wr == CRS__SZ_FMT_INVALID)
    {
        return MLCA_ESTRUCT;
    }

    if (type)
    {
        *type = ((int)wr > 0) ? wtype : 0;
    }

    return (int)wr;
}
#endif /*-----  /delimiter: PKCS11 wrappers  --------------------------*/

/**
 * Supporting platform specific "mlca_alloc" and "mlca_free" for ML-DSA support
 * Specifically, these are needed to use the USE_DYNAMIC_ALLOC #define/compile
 * flag
 *
 */
#if defined(USE_DYNAMIC_ALLOC)
void * mlca_alloc(uint32_t size)
{
    assert(false, "mlca_alloc() not supported");
    void * tmp = nullptr;
    return tmp;
}

// Free the alocated heap space
void mlca_free(void * ptr)
{
    assert(false, "mlca_free() not supported");
    return;
}
#endif /* defined(USE_DYNAMIC_ALLOC) */


#endif /* !MLCA__IMPL_H__ */
