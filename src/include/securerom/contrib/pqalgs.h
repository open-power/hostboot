/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/contrib/pqalgs.h $                      */
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
// SPDX-License-Identifier: Apache-2.0

#if !defined(PQALGS_H__)
#define PQALGS_H__ 1

/* defining USE_STATIC_MLCA keeps functions internal to build unit */

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h> /* size_t */

#define MLCA_MINIMAL

/*--------------------------------------
 * Generate keypair.
 *
 * (algid, ibytes)  selects the key algorithm; must point to a suitable
 *                  object identifier (OID).
 *
 * (prv, prvbytes)  contains the private key, at the start, upon success
 * (pub, *pubbytes) contains the public key, at the start, upon success;
 *                  *pubbytes contains the available size when calling.
 *
 * 'rng' is context passed through to any invocations of the randombytes()
 * call, for environments where RNG access is conditional.
 *
 * Returns number of bytes written to start of (prv, prvbytes); size
 * query with NULL 'prv'.
 *
 * The returned keys are in a provider-specific, possibly nonstandard
 * format.  See mlca_key2wire() for standardized serialization.
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_generate(unsigned char* prv, size_t prvbytes, unsigned char* pub,
              size_t* pubbytes, void* rng, const unsigned char* algid,
              size_t ibytes);

/*--------------------------------------
 * Sign data: generates signature for (msg, mbytes) as message, using
 * private key (prv, pbytes).
 *
 * Returns number of bytes written to start of (sig, sbytes); size
 * query with NULL 'sig'.  Returns <0 for failure.
 *
 * Key has been returned by an earlier call to pqcr_generate().
 *
 * A RNG context 'rng' may be passed for randomized signing
 * If 'rng' is NULL, deterministic signing is used if permitted.
 *
 * (algid, ibytes)  selects the key algorithm.  If (NULL, 0), a
 * key(type)-specific default is selected; see algorithm-specific definitions.
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_sign(unsigned char* sig, size_t sbytes, const unsigned char* msg,
          size_t mbytes, const unsigned char* prv, size_t pbytes,
          void* rng, const unsigned char* algid, size_t ibytes);

#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_sign_internal(unsigned char* sig, size_t sbytes,
                   const unsigned char* msg, size_t mbytes,
                   const unsigned char* prv, size_t pbytes, void* rng,
                   const unsigned char* algid, size_t ibytes);

/*--------------------------------------
 * Verify signature: validates signature (sig, sbytes) corresponding to
 * (msg, mbytes), using the public key (pub, pbytes).
 *
 * Returns >0  if signature has been verified
 *         0   if signature is invalid
 *         <0  other errors, such as invalid key or mode
 *
 * Public key has been returned by an earlier call to pqcr_generate().
 *
 * (algid, ibytes)  selects the key algorithm.  If (NULL, 0), a
 * key(type)-specific default is selected; see algorithm-specific definitions.
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_verify(const unsigned char* sig, size_t sbytes,
            const unsigned char* msg, size_t mbytes,
            const unsigned char* pub, size_t pbytes,
            const unsigned char* algid, size_t ibytes);

#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_verify_internal(const unsigned char* sig, size_t sbytes,
                     const unsigned char* msg, size_t mbytes,
                     const unsigned char* pub, size_t pbytes,
                     const unsigned char* algid, size_t ibytes);

/*--------------------------------------
 * Serialize key: encode [possibly] provider-internal structure to
 * standardized PKCS#8 (private key) or SPKI (public keys).
 *
 * Returns number of bytes written to start of (wire, wbytes); size
 * query with NULL 'wire'.
 *
 * (algid, ibytes) selects encoding algorithm.  If (NULL, 0), a key(type)-
 * specific default is selected; see algorithm-specific definitions.
 *
 * See also: mlca_wire2key()
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_key2wire(unsigned char* wire, size_t wbytes,
              const unsigned char* key, size_t kbytes,
              unsigned int flags, const unsigned char* pub,
              size_t pbytes, const unsigned char* algid, size_t ibytes);

/*--------------------------------------
 * Key agreement: sender.  Generate shared secret and corresponding
 * ciphertext.
 *
 * Returns number of bytes written to start of (cipher, cbytes); size
 * query with NULL 'cipher'.
 *
 * 'rng' is context passed through to any invocations of the randombytes()
 * call, for environments where RNG access is conditional.
 *
 * (algid, ibytes) selects encoding algorithm.  If (NULL, 0), a key(type)-
 * specific default is selected; see algorithm-specific definitions.
 *
 * See also: mlca_kem2() for recipient
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_kem1(unsigned char* cipher, size_t cbytes, unsigned char* secr,
          size_t* sbytes, const unsigned char* pub, size_t pbytes,
          void* rng, const unsigned char* algid, size_t ibytes);

/*--------------------------------------
 * Key agreement: recipient.  Derive shared secret from ciphertext
 * and recipient private key.
 *
 * Returns number of bytes written to start of (secr, sbytes); size
 * query with NULL 'secr'.
 *
 * (algid, ibytes) selects encoding algorithm.  If (NULL, 0), a key(type)-
 * specific default is selected; see algorithm-specific definitions.
 *
 * See also: mlca_kem1() for sender
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_kem2(unsigned char* secr, size_t sbytes,
          const unsigned char* cipher, size_t cbytes,
          const unsigned char* prv, size_t pbytes,
          const unsigned char* algid, size_t ibytes);

/*--------------------------------------
 * Decode key: import a standardized structure into a [possibly]
 * provider-internal format.
 *
 * Returns number of bytes written to start of (key, kbytes); size
 * query with NULL 'key'.
 *
 * sets 'type' to >0 recognized type, one of the MLCA_ID_t constants,
 * if non-NULL.  This works even with size queries to type-check
 * wire structures.
 *
 * Tolerate in-place import: allow importing with 'key' and 'wire' the
 * same pointer; other overlap of (key, kbytes) and (wire, wbytes) is
 * undefined.
 *
 * (algid, ibytes) forces use of a specific the serialization algorithm.
 * With NULL 'algid' or 0 'ibytes', all context is derived from the
 * self-describing standardized structure.
 *
 * See also: mlca_key2wire()
 */
#if defined(USE_STATIC_MLCA)
static
#endif
/**/
int
mlca_wire2key(unsigned char* key, size_t kbytes, unsigned int* type,
              const unsigned char* wire, size_t wbytes,
              const unsigned char* algid, size_t ibytes);

/*-----  extension notes
 * ---------------------------------------------------- As an alternative to
 * object identifiers (OIDs), an append-only list for algorithm/size/etc.
 * selectors have been defined; see MLCA_ID_t for a full list. These
 * constants must be supplied as (NULL, ...constant...) instead of a
 * non-NULL OID, or (NULL, 0) where the latter implies defaults.
 *
 * Implementations MAY use handles instead of raw key structures;
 * the API is not expected to change for such indirection-addressed
 * providers.
 */

typedef enum
{
    /* all reserved values are >0, < 0x1000000
     * mapped values have some internal structure, do
     * not change them
     */

    /* round 2 Dilithium, NIST strength categories,
     * implies IBM-specified private+public key formats when
     * used in serialization context.
     */
    MLCA_ID_DIL3_R2 = 0x0105,
    MLCA_ID_DIL4_R2 = 0x0106,
    MLCA_ID_DIL5_R2 = 0x0108,

    /* round 2 Dilithium, NIST strength categories,
     * implies ref.impl-derived, 'raw' private+public keys when
     * used in serialization context, such as generated/used
     * by liboqs.
     *
     * when used as key(generate) or signature type,
     * DIL<n>_R2_RAW is identical to the corresponding DIL<n>_R2.
     */
    MLCA_ID_DIL3_R2_RAW = 0x0205,
    MLCA_ID_DIL4_R2_RAW = 0x0206,
    MLCA_ID_DIL5_R2_RAW = 0x0208,

    /* round 3 Dilithium, NIST strength categories,
     * compressed round 3 signatures
     *
     * when used as key type, DIL<n>_R2 is identical
     * to the corresponding DIL<n>_R2.
     */
    MLCA_ID_DIL2_R3 = 0x0344,
    MLCA_ID_DIL3_R3 = 0x0365,
    MLCA_ID_DIL5_R3 = 0x0387,

    MLCA_ID_DIL_MLDSA_44 = 0x0444,
    MLCA_ID_DIL_MLDSA_65 = 0x0465,
    MLCA_ID_DIL_MLDSA_87 = 0x0487,

    /* round 2 Kyber, NIST strength categories,
     * implies IBM-specified private+public key formats when
     * used in serialization context.
     */
    MLCA_ID_KYB3_R2 = 0x0503,
    MLCA_ID_KYB4_R2 = 0x0504,

    /* round 3 Kyber, NIST strength categories, 2020-10-01 update,
     * implies IBM-specified private+public key formats when
     * used in serialization context.
     */
    MLCA_ID_KYB3_R3 = 0x0803,
    MLCA_ID_KYB4_R3 = 0x0804,

    MLCA_ID_KYB_MLKEM_768  = 0x0903,
    MLCA_ID_KYB_MLKEM_1024 = 0x0904,

    /* portability note: make sure no comma after last entries
     */

    MLCA_ID_MAX = MLCA_ID_KYB_MLKEM_1024
} MLCA_ID_t;

/* additional bits which may be combined with MLCA_ID_t constants
 */
typedef enum
{
    MLCA_IDP_PUBLIC = 0x1000000
} MLCA_IDplus_t;

/*--------------------------------------
 * features controlling key transport
 */
typedef enum
{
    MLCA_KEYTR_NOPUBLIC = 1, /* omit public-key field from prv.key */
    MLCA_KEYTR_MINIMAL  = 2  /* use maximally-compressed form of key */
} MLCA_KeyTransp_t;

/*-----  limits  ---------------------*/
/* fits any supported Kyber priv.key or public key [raw, not wire-formatted] */
#define KYB_PRV_MAX_BYTES       3168
#define KYB_PUB_MAX_BYTES       1568
#define KYB_CIPHERTXT_MAX_BYTES 1568

#ifdef MLCA_MINIMAL
typedef enum
{
    MLCA_OK          = 0,
    MLCA_EPARAM      = -1, /* missing/NULL param; non-NULL expected */
    MLCA_ESTRENGTH   = -2, /* parameters strength/policy-restricted */
    MLCA_ESTRUCT     = -3, /* key(structure) is not recognized */
    MLCA_EKEYTYPE    = -4, /* object ID/key-object type not recognized */
    MLCA_EKEYMODE    = -5, /* key incompatible with requested function */
    MLCA_EKEYSIZE    = -6, /* invalid input-key size (non-specific) */
    MLCA_EPUBKEYSIZE = -7, /* invalid input-key size (public key) */
    MLCA_EMODE       = -8, /* operation incompatible with requested
                                  function/mode */
    MLCA_ETOOSMALL = -9,   /* insufficient output buffer */
    MLCA_ERNG      = -10,  /* call to random-number generator failed */
    MLCA_EINTERN   = -11,  /* CSP internal consistency error */
    MLCA_EMISSING  = -12,  /* requested key component is not present */
    MLCA_ENSUPPORT = -13,  /* requested operation(OID?) not supported */
    MLCA_EMEM      = -14,  /* memory operation failed */
    MLCA_GEN       = -15,  /* MLCA generic error */
} MLCA_RC;
#else
#include <mlca2_int.h>
#endif

#define FLAGS_KEY2WIRE_DEFAULT    0
#define FLAGS_KEY2WIRE_GETPUB     1
#define FLAGS_KEY2WIRE_GETPUBHASH 2

/* see also: crystals-oids.h */

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif /* PQALGS_H__ */