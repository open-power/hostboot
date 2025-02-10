/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/contrib/v3_mlca/include/mlca2_int.h $   */
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
 * @file mlca2_int.h
 * 
 * MLCA internal data structures.
 * This header file should not be included in client application. 
 * 
 */

#ifndef MLCA_INT_H
#define MLCA_INT_H

#include <mlca2.h>
#include <stdint.h>

typedef union mlca_api_t mlca_api_t;
typedef struct mlca_kem_api_t mlca_kem_api_t;
typedef struct mlca_sig_api_t mlca_sig_api_t;
typedef struct mlca_asntl_t mlca_asntl_t;
typedef struct mlca_encoding_t mlca_encoding_t;
typedef struct mlca_encoding_impl_t mlca_encoding_impl_t;
typedef struct mlca_cpu_features_t mlca_cpu_features_t;

#define OS_NIX 1
#define OS_OTHER 2

#define TARGET_ARM64 1
#define TARGET_ARM 2
#define TARGET_AMD64 3
#define TARGET_x86 4
#define TARGET_S390X 5
#define TARGET_MIPS64 6
#define TARGET_OTHER 7

/**
 * Algorithm implementation specific data structure.
 */
struct mlca_alg_impl_t {
    int opt_level;
    int (*check_compatibility) (const mlca_cpu_features_t*);
    const void* alg_ctx;
};

/**
 * KEM API structure.
 */
struct mlca_kem_api_t {
    int (*keypair) (const mlca_ctx_t *ctx, unsigned char *pk, unsigned char *sk);
    int (*kem_enc) (const mlca_ctx_t *ctx, unsigned char *ct, unsigned char *ss, const unsigned char *pk);
    int (*kem_dec) (const mlca_ctx_t *ctx, unsigned char *ss, const unsigned char* ct, const unsigned char* sk);
};

/**
 * Signature API structure.
 */
struct mlca_sig_api_t {
    int (*keypair            ) (const mlca_ctx_t *ctx, unsigned char *pk, unsigned char *sk);
    int (*sig_sign           ) (const mlca_ctx_t *ctx, unsigned char* sig, size_t *siglen, const unsigned char* m, size_t mlen, const unsigned char* sk);
    int (*sig_sign_internal  ) (const mlca_ctx_t *ctx, unsigned char* sig, size_t *siglen, const unsigned char* m, size_t mlen, const unsigned char* sk);
    int (*sig_verify         ) (const mlca_ctx_t *ctx, const unsigned char *m, size_t mlen, const unsigned char *sig, size_t siglen, const unsigned char *pk);
    int (*sig_verify_internal) (const mlca_ctx_t *ctx, const unsigned char *m, size_t mlen, const unsigned char *sig, size_t siglen, const unsigned char *pk);
};


/**
 * ASN.1 specific structure
 */
struct mlca_asntl_t {
    int asntag;
    int asnlen;
    char asnvalue;
    int asndecskip;
    char asndec_flag;
    int encpub;
    int optional;
};

/**
 * Structure for MLCA encodings
 */
struct mlca_encoding_t {
    const char* algorithm_oid;
    int encodings_len;
    const mlca_encoding_impl_t* encoding;
};

/**
 * Structure for encoding implementations.
 */
struct mlca_encoding_impl_t {

    const char* algorithm_oid;
    const char* encoding_name;

    int raw;

    size_t crypto_publickeybytes;
    /** The (maximum) length, in bytes, of secret keys for this KEM. */
    size_t crypto_secretkeybytes;
    /** The (maximum) length, in bytes, of ciphertexts for this KEM. */
    size_t crypto_ciphertextbytes;

    size_t crypto_bytes;

    int pk_asntl_len;
    int sk_asntl_len;

    const mlca_asntl_t* pk_asntl;
    const mlca_asntl_t* sk_asntl;

    int (*encode) (const mlca_encoding_impl_t* ctx_out, const mlca_encoding_impl_t* ctx_in, unsigned char* pk, unsigned char** pkenc, unsigned char* sk, unsigned char** skenc);
    int (*decode) (const mlca_encoding_impl_t* ctx_out, const mlca_encoding_impl_t* ctx_in, unsigned char* pk, unsigned char** pkdec, unsigned char* sk, unsigned char** skdec);

};

/**
 * Structure for MLCA API.
 */
union mlca_api_t {
    const mlca_kem_api_t* kem_api;
    const mlca_sig_api_t* sig_api;
};

/**
 * Structure for MLCA algorithms.
 */
struct mlca_alg_t {

    /** Printable string representing the name of the key encapsulation mechanism. */
    const char *algorithm_name;
    const char *algorithm_oid;

    mlca_algorithm_type_t type;
    
    /** Printable string representing the version of the cryptographic algorithm. */
    const char *alg_version;

    /** The NIST security level (1, 2, 3, 4, 5) claimed in this algorithm's original NIST submission. */
    uint8_t claimed_nist_level;

    /** Whether the KEM offers IND-CCA security (TRUE) or IND-CPA security (FALSE). */
    int ind_cca;

    const mlca_encoding_t* encodings;

    /** algorithm-specific context */
    int alg_ctx_len;

    const mlca_alg_impl_t* alg_ctx_all;

    const mlca_api_t api;
};

/**
 * Data structure representing CPU features.
 */
struct mlca_cpu_features_t {
    int initialized;
    uint32_t hwcap;
    int message_security_assist;
    int message_security_assist_6;
    int vector_facility;
    int vector_enhancements_facility_1;
    int vector_enhancements_facility_2;
};

/**
 * Algorithm definitions (external)
 */
extern const mlca_alg_t kyber_mlca_ctx[6];
extern const mlca_alg_t dilithium_mlca_ctx[9];

#endif // MLCA_INT_H