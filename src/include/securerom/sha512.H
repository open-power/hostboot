/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/sha512.H $                              */
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
/* IBM_PROLOG_END_TAG                                                     */
#ifndef SHA512_H
#define SHA512_H

#define SHA512_BLOCK_LENGTH 128
#define SHA512_DIGEST_LENGTH 64

#include <stdlib.h>

typedef uint8_t __attribute__((aligned(8))) \
    sha2_hash_t[ SHA512_DIGEST_LENGTH / sizeof(uint8_t) ];

typedef uint8_t  sha2_byte;     /* Exactly 1 byte */
typedef uint32_t sha2_word32;   /* Exactly 4 bytes */
typedef uint64_t sha2_word64;   /* Exactly 8 bytes */

typedef struct _SHA512_CTX
{
    uint64_t state[8];
    uint64_t bitcount[2];
    uint8_t buffer[SHA512_BLOCK_LENGTH];
} SHA512_CTX;

extern "C"
void SHA512_Init(SHA512_CTX* context);
extern "C"
void SHA512_Update(SHA512_CTX* context, const sha2_byte *data, size_t len);
extern "C"
void SHA512_Final(SHA512_CTX* context, sha2_hash_t *result);
extern "C"
void SHA512_Hash(const sha2_byte *data, size_t len, sha2_hash_t *result);

#endif
