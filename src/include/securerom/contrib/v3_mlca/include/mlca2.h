/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/contrib/v3_mlca/include/mlca2.h $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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
/**
 * @file mlca2.h
 * 
 * MLCA public header file.
 * 
 */

#ifndef MLCA2_H
#define MLCA2_H

//MAB#include <mlca2_random.h>
#include <securerom/contrib/v3_mlca/include/mlca2_random.h>
#include <securerom/contrib/v3_mlca/include/mlca2_int.h>
#include <stddef.h>

/**
 * MLCA context structure.
 */
typedef struct mlca_ctx_t mlca_ctx_t;

/**
 * MLCA algorithm type.
 */
typedef enum mlca_algorithm_type_t mlca_algorithm_type_t;

/**
 * Error codes
 */
typedef enum {
	MLCA_OK          =   0,
	MLCA_EPARAM      =  -1,  /* missing/NULL param; non-NULL expected */
	MLCA_ESTRENGTH   =  -2,  /* parameters strength/policy-restricted */
	MLCA_ESTRUCT     =  -3,  /* key(structure) is not recognized */
	MLCA_EKEYTYPE    =  -4,  /* object ID/key-object type not recognized */
	MLCA_EKEYMODE    =  -5,  /* key incompatible with requested function */
	MLCA_EKEYSIZE    =  -6,  /* invalid input-key size (non-specific) */
	MLCA_EPUBKEYSIZE =  -7,  /* invalid input-key size (public key) */
	MLCA_EMODE       =  -8,  /* operation incompatible with requested
	                            function/mode */
	MLCA_ETOOSMALL   =  -9,  /* insufficient output buffer */
	MLCA_ERNG        = -10,  /* call to random-number generator failed */
	MLCA_EINTERN     = -11,  /* CSP internal consistency error */
	MLCA_EMISSING    = -12,  /* requested key component is not present */
	MLCA_ENSUPPORT   = -13,  /* requested operation(OID?) not supported */
    MLCA_EMEM        = -14,  /* memory operation failed */
    MLCA_GEN         = -15,  /* MLCA generic error */
} MLCA_RC;


/**
 * MLCA Context initialization
 * 
 * @param[out] ctx MLCA context.
 * @param[in] alg_len Number of algorithms to be used with the context.
 * @param[in] protocol Protocol to be used with the context.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_init(mlca_ctx_t* ctx, int alg_len, int protocol);

/**
 * Set algorithm identified by name/OID and optimization level.
 * 
 * @param[in/out] ctx MLCA context.
 * @param[in] algorithm_or_oid Algorithm name or OID to identify the algorithm.
 * @param[in] opt_level Optimization level: AUTO, GENERIC or ASSEMBLY. If auto is selected, the most optimal implementation is determined at run-time.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_set_alg(mlca_ctx_t* ctx, const char* algorithm_or_oid, int opt_level);

/**
 * Set random number generator associated with the context.
 * 
 * @param[in/out] ctx MLCA context.
 * @param[in] rng Random number context to be set. If 0, the default RNG is used.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_set_rng(mlca_ctx_t *ctx, const mlca_random_t *rng);

/**
 * Sets an encoding to be used with the MLCA context.
 * 
 * @param[in/out] ctx MLCA context.
 * @param[in] encoding Integer identifying an encoding.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_set_encoding_by_idx(mlca_ctx_t* ctx, int encoding);

/**
 * Sets an encoding by name or OID to be used with the PACA context.
 * 
 * @param[in/out] ctx MLCA context.
 * @param[in] oid_or_name Encoding name or OID to identify the algorithm.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_set_encoding_by_name_oid(mlca_ctx_t* ctx, const char* oid_or_name);

/**
 * Resets the state of a MLCA context (not free).
 * 
 * @param[in/out] ctx Context with associtated state to be reset.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_ctx_reset(mlca_ctx_t* ctx);

/**
 * Frees memory associated with a MLCA context.
 * 
 * @param[in/out] ctx Context where associated memory is to be freed.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_ctx_free(mlca_ctx_t* ctx);

/**
 * KEM keypair generation.
 * 
 * @param[in] ctx MLCA context.
 * @param[out] pk Contains the public key.
 * @param[out] sk Contains the private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_kem_keygen(const mlca_ctx_t *ctx, unsigned char *pk, unsigned char *sk);

/**
 * KEM Encapsulation.
 * 
 * @param[in] ctx MLCA context.
 * @param[out] ct Contains the ciphertext.
 * @param[out] ss Contains the secret key.
 * @param[in] pk Contains the public key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_kem_enc(const mlca_ctx_t *ctx, unsigned char *ct, unsigned char *ss, const unsigned char *pk);

/**
 * KEM Decapsulation.
 * 
 * @param[in] ctx MLCA context.
 * @param[out] ss Contains the shared secret.
 * @param[in] ct Contains the ciphertext.
 * @param[in] sk Contains the private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_kem_dec(const mlca_ctx_t *ctx, unsigned char *ss, const unsigned char *ct,
                           const unsigned char *sk);

/**
 * MLCA Signature keypair generation.
 * 
 * @param[in] ctx MLCA context.
 * @param[out] pk Contains the public key.
 * @param[out] sk Contains the private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_sig_keygen(const mlca_ctx_t *ctx, unsigned char *pk, unsigned char *sk);

/**
 * MLCA Signature signing.
 * 
 * @param[in] ctx MLCA context.
 * @param[out] sig Contains the signature.
 * @param[in/out] siglen Contains the signature length and returns the actual signature length.
 * @param[in] m Contains the message to be signed.
 * @param[in] mlen Contains the length of the message to be signed.
 * @param[in] sk Contains the private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_sig_sign(const mlca_ctx_t *ctx, unsigned char* sig, size_t* siglen, const unsigned char* m, size_t mlen, const unsigned char* sk);

/**
 * MLCA Signature signing - internal API for testing.
 * 
 * @param[in] ctx MLCA context.
 * @param[out] sig Contains the signature.
 * @param[in/out] siglen Contains the signature length and returns the actual signature length.
 * @param[in] m Contains the message to be signed.
 * @param[in] mlen Contains the length of the message to be signed.
 * @param[in] sk Contains the private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_sig_sign_internal(const mlca_ctx_t *ctx, unsigned char* sig, size_t* siglen, const unsigned char* m, size_t mlen, const unsigned char* sk);

/**
 * MLCA Signature verification.
 * 
 * @param[in] ctx MLCA context.
 * @param[in] m Contains the message associated with the signature.
 * @param[in] mlen Contains the length of the message to be signed.
 * @param[in] sig Contains the signature to be verified.
 * @param[in] siglen Contains the signature length.
 * @param[in] pk Contains the public key.
 * @return 0 if the signature verification failed, 1 if the signature is successfully verified.
 */
MLCA_RC mlca_sig_verify(const mlca_ctx_t *ctx, const unsigned char *m, size_t mlen, const unsigned char *sig, size_t siglen, const unsigned char *pk);

/**
 * MLCA Signature verification - internal API for testing.
 * 
 * @param[in] ctx MLCA context.
 * @param[in] m Contains the message associated with the signature.
 * @param[in] mlen Contains the length of the message to be signed.
 * @param[in] sig Contains the signature to be verified.
 * @param[in] siglen Contains the signature length.
 * @param[in] pk Contains the public key.
 * @return 0 if the signature verification failed, 1 if the signature is successfully verified.
 */
MLCA_RC mlca_sig_verify_internal(const mlca_ctx_t *ctx, const unsigned char *m, size_t mlen, const unsigned char *sig, size_t siglen, const unsigned char *pk);


// Encoding
/**
 * Encode a KEM keypair, according to a separately set encoding.
 * 
 * @param[in] ctx MLCA context.
 * @param[in] pk Public key, may be null.
 * @param[out] pkenc Encoded public key.
 * @param[in] sk Private key, may be null.
 * @param[out] skenc Encoded public key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_kem_keypair_encode(const mlca_ctx_t *ctx, unsigned char* pk, unsigned char** pkenc, unsigned char* sk, unsigned char** skenc);

/**
 * Decode a KEM keypair, according to a separately set encoding.
 * 
 * @param[in] ctx MLCA context.
 * @param[in] pk Public key, may be null.
 * @param[out] pkdec Decoded public key.
 * @param[in] sk Private key, may be null.
 * @param[out] skdec Decoded private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_kem_keypair_decode(const mlca_ctx_t *ctx, unsigned char* pk, unsigned char** pkdec, unsigned char* sk, unsigned char** skdec);

/**
 * Encode a Signature keypair, according to a separately set encoding.
 * 
 * @param[in] ctx MLCA context.
 * @param[in] pk Public key, may be null.
 * @param[out] pkenc Encoded public key.
 * @param[in] sk Private key, may be null.
 * @param[out] skenc Encoded public key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_sig_keypair_encode(const mlca_ctx_t *ctx, unsigned char* pk, unsigned char** pkenc, unsigned char* sk, unsigned char** skenc);

/**
 * Decode a Signature keypair, according to a separately set encoding.
 * 
 * @param[in] ctx MLCA context.
 * @param[in] pk Public key, may be null.
 * @param[out] pkdec Decoded public key.
 * @param[in] sk Private key, may be null.
 * @param[out] skdec Decoded private key.
 * @return MLCA_RC Return code.
 */
MLCA_RC mlca_sig_keypair_decode(const mlca_ctx_t *ctx, unsigned char* pk, unsigned char** pkdec, unsigned char* sk, unsigned char** skdec);

// Memory management
/**
 * Memory allocation.
 * 
 * @param[in] size Size of the memory to be allocated in bytes.
 * @return A pointer to the allocated memory or 0 if unsuccessful.
 */
void* mlca_malloc(size_t size);

/**
 * Memory allocation with zero initialization.
 * 
 * @param[in] count Number of items to be allocated.
 * @param[in] size Size of the items to be allocated.
 * @return A pointer to the allocated memory or 0 if unsuccessful.
 */
void* mlca_calloc(size_t count, size_t size);

/**
 * Memory free.
 * 
 * @param[in] mem Pointer to the memory to be freed.
 */
void mlca_free(void* mem);

/**
 * Secure memory free.
 * 
 * @param[in] mem Pointer to the memory to be freed.
 * @param[in] size Size of the memory to be freed.
 * @return
 */
void mlca_secure_free(void* mem, size_t size);

/**
 * Secure memory clear (not free)
 * 
 * @param[in] mem Pointer to the memory to be freed.
 * @param[in] size Size of the memory to be freed.
 */
void mlca_secure_clear(void* mem, size_t size);

// Crypto algorithm properties.
/**
 * KEM public key size associated with a MLCA context
 * 
 * @param[in] ctx MLCA context.
 * @return Size of the associated public key.
 */
size_t mlca_kem_crypto_publickeybytes(const mlca_ctx_t* ctx);

/**
 * KEM private key size associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Size of the associated private key.
 */
size_t mlca_kem_crypto_secretkeybytes(const mlca_ctx_t* ctx);

/**
 * KEM ciphertext size associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Size of the associated ciphertext.
 */
size_t mlca_kem_crypto_ciphertextbytes(const mlca_ctx_t* ctx);

/**
 * KEM shared secret size associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Size of the associated shared secret.
 */
size_t mlca_kem_crypto_bytes(const mlca_ctx_t* ctx);

/**
 * Signature scheme public key size associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Size of the associated public key.
 */
size_t mlca_sig_crypto_publickeybytes(const mlca_ctx_t* ctx);

/**
 * Signature scheme private key size associated with a MLCA context.
 * 
 * @param ctx MLCA context.
 * @return size_t Size of the associated private key.
 */
size_t mlca_sig_crypto_secretkeybytes(const mlca_ctx_t* ctx);

/**
 * Signature scheme signature size associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Size of the associated signature.
 */
size_t mlca_sig_crypto_bytes(const mlca_ctx_t* ctx);

/**
 * Claimed NIST security level associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return NIST level: 0, 1, 2, 3, 4, 5, or 6
 */
int mlca_claimed_nist_level(const mlca_ctx_t* ctx);

/**
 * Type of algorithm associated with a MLCA context.
 * 
 * @param ctx MLCA context.
 * @return Algorithm type: KEM or SIGNATURE.
 */
mlca_algorithm_type_t mlca_alg_type(const mlca_ctx_t* ctx);

/**
 * Algorithm name associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Algorithm name as a string.
 */
const char* mlca_algorithm_name(const mlca_ctx_t* ctx);

/**
 * Algorithm OID associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Algorithm OID as a string.
 */
const char* mlca_algorithm_oid(const mlca_ctx_t* ctx);


/**
 * Selected optimization level associated with a MLCA context.
 * 
 * @param[in] ctx MLCA context.
 * @return Optimization level: GENERIC or ASSEMBLY.
 */
int mlca_opt_level(const mlca_ctx_t* ctx);

/**
 * MLCA memory typedef
 */
typedef struct mlca_mem_t mlca_mem_t;

/**
 * MLCA algorithm typedef
 */
typedef struct mlca_alg_t mlca_alg_t;

/**
 * MLCA algorithm implementation typedef (opaque)
 */
typedef struct mlca_alg_impl_t mlca_alg_impl_t;

/**
 * MLCA memory struct.
 */
struct mlca_mem_t {
    /** Memory slots */
    unsigned char* mem[5];
    /** Memory slot is secret (1) or not (0) */
    int sec[5];
    /** Lenghts of the memory slots */
    size_t len[5];
    /** Memory provided or internally allocated */
    int prov[5];
    /** Auxiliary data */
    int aux[5];
};

/**
 * MLCA context
 */
struct mlca_ctx_t {
    /** Algorithm context  */
    const mlca_alg_t** alg;
    /** Algorithm implementation */
    const mlca_alg_impl_t** alg_impl;
    /** Algorithm encoding index */
    int alg_enc_idx;
    /** Random context */
    const mlca_random_t* rng;
    /** Context data */
    mlca_mem_t data;
    /** Current state */
    int state;
    /** Number of algorithms */
    int num_algs;
    /** Protocol used along with the context */
    int protocol;
};

/**
 * MLCA algorithm type (KEM or SIGNATURE)
 */
enum mlca_algorithm_type_t {
    KEM, SIGNATURE
};

/**
 * Algorithm names
 */
#define MLCA_ALGORITHM_SIG_DILITHIUM_54_R2 "Dilithium54_R2"
#define MLCA_ALGORITHM_SIG_DILITHIUM_65_R2 "Dilithium65_R2"
#define MLCA_ALGORITHM_SIG_DILITHIUM_87_R2 "Dilithium87_R2"
#define MLCA_ALGORITHM_SIG_DILITHIUM_2 "Dilithium2"
#define MLCA_ALGORITHM_SIG_DILITHIUM_3 "Dilithium3"
#define MLCA_ALGORITHM_SIG_DILITHIUM_5 "Dilithium5"
#define MLCA_ALGORITHM_SIG_MLDSA_44 "ML-DSA-44"
#define MLCA_ALGORITHM_SIG_MLDSA_65 "ML-DSA-65"
#define MLCA_ALGORITHM_SIG_MLDSA_87 "ML-DSA-87"
#define MLCA_ALGORITHM_KEM_KYBER_768 "Kyber768_R2"
#define MLCA_ALGORITHM_KEM_KYBER_1024 "Kyber1024_R2"
#define MLCA_ALGORITHM_KEM_KYBER_768_R3 "Kyber768"
#define MLCA_ALGORITHM_KEM_KYBER_1024_R3 "Kyber1024"
#define MLCA_ALGORITHM_KEM_MLKEM_768 "ML-KEM-768"
#define MLCA_ALGORITHM_KEM_MLKEM_1024 "ML-KEM-1024"

/**
 * Algorithm OIDs
 */
#define MLCA_ALGORITHM_SIG_DILITHIUM_R2_5x4_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x01\x05\x04"
#define MLCA_ALGORITHM_SIG_DILITHIUM_R2_6x5_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x01\x06\x05"
#define MLCA_ALGORITHM_SIG_DILITHIUM_R2_8x7_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x01\x08\x07"

#define MLCA_ALGORITHM_SIG_DILITHIUM_R3_4x4_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x07\x04\x04"
#define MLCA_ALGORITHM_SIG_DILITHIUM_R3_6x5_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x07\x06\x05"
#define MLCA_ALGORITHM_SIG_DILITHIUM_R3_8x7_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x07\x08\x07"

#define MLCA_ALGORITHM_SIG_MLDSA_44_OID "\x06\x09" "\x60\x86\x48\x01\x65\x03\x04\x03\x11"
#define MLCA_ALGORITHM_SIG_MLDSA_65_OID "\x06\x09" "\x60\x86\x48\x01\x65\x03\x04\x03\x12"
#define MLCA_ALGORITHM_SIG_MLDSA_87_OID "\x06\x09" "\x60\x86\x48\x01\x65\x03\x04\x03\x13"

#define MLCA_ALGORITHM_KEM_KYBER_768_R2_OID  "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x05\x03\x03"
#define MLCA_ALGORITHM_KEM_KYBER_1024_R2_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x05\x04\x04"
#define MLCA_ALGORITHM_KEM_KYBER_768_R3_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x08\x03\x03"
#define MLCA_ALGORITHM_KEM_KYBER_1024_R3_OID "\x06\x0b" "\x2b\x06\x01\x04\x01\x02\x82\x0b\x08\x04\x04"

#define MLCA_ALGORITHM_KEM_MLKEM_768_OID "\x06\x09" "\x60\x86\x48\x01\x65\x03\x04\x04\x02"
#define MLCA_ALGORITHM_KEM_MLKEM_1024_OID "\x06\x09" "\x60\x86\x48\x01\x65\x03\x04\x04\x03"

/**
 * Optimization levels
 */
#define OPT_LEVEL_AUTO -1
#define OPT_LEVEL_GENERIC 0
#define OPT_LEVEL_ASSEMBLY 1

#endif // MLCA_H
