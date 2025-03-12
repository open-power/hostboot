/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/contrib/sha3.H $                        */
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
/* EKB-Mirror-To: hw/ppe                                                  */
#pragma once

#include <stddef.h>
#include <stdint.h>
#include <securerom/keccak.h>
#include <securerom/ecverify.H>
#include <string.h>


/**
 * @brief Abstract layer for keccak.C
 *
 */

#define SHA3_DIGEST_LENGTH 64

typedef uint8_t sha3_t[SHA3_DIGEST_LENGTH];

typedef Keccak_state sha3_ctx_t;

// OpenSSL - like interfece
/**
 * @brief Initialize the context for SHA3
 *
 * @param c Pointer to SHA3-512 context
 * @return int true always
 */
static inline int sha3_init(sha3_ctx_t* c)
{
    sha3_512_init(c);
    return 1;
}

/**
 * @brief Stream like interface for sha3-512 .
 *        Update state with more data
 *
 * @param c Pointer to SHA3-512 context
 * @param data data to be hashed
 * @param len length og the data to be hashed
 * @return int true always
 */
static inline int sha3_update(sha3_ctx_t* c, const void* data, size_t len)
{
    sha3_512_update(c, data, len);
    return 1;
}

/**
 * @brief finalize and output a hash
 *
 * @param md pointer to calculated hash
 * @param c Pointer to SHA3-512 context
 * @return int true always
 */
static inline int sha3_final(sha3_t* md, sha3_ctx_t* c)
{
    sha3_512_final((uint8_t*)md, c);
    return 1;
}

/**
 * @brief compute a sha3 hash (md) of given byte length from "in"
 *
 * @param in Message to be hashed
 * @param inlen Length of the message to be hashed
 * @param md Hash of the message
 * @param mdlen Length of the message hash
 * @return void* Hash of the message
 */
static inline void* sha3(const void* in, size_t inlen, void* md, int mdlen = SHA3_DIGEST_LENGTH)
{
    sha3_t digest;
    sha3_512(digest, (const uint8_t*)in, inlen);
    memcpy(md, digest, ((mdlen > SHA3_DIGEST_LENGTH) ? SHA3_DIGEST_LENGTH : mdlen));
    return md;
}
