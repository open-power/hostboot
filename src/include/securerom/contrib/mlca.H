/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/contrib/mlca.H $                        */
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

#include <stdint.h>
#include <stddef.h>

/**
 * Flags to be defined by platform for ML-DSA variant .
 * - USE_DYNAMIC_ALLOC : To use dynamic memory allocation
 * - NO_CRYSTALS_CIP, NO_CRYSTALS_KEX : Disable kyber algo
 * - NO_DILITHIUM_SIGN      : Disable the dilithium sign algo (r2/r3)
 * - NO_MLDSA_SIGN          : Disable ML-DSA sign algo ()
 * - NO_DILITHIUM_VERIFY    : Disable the dilithium verify algo (r2/r3)
 * - NO_MLDSA_VERIFY        : Disable ML-DSA verify algo
 *
 * ML-DSA Variant support
 * - DIL_MLDSA_44
 * - DIL_MLDSA_65
 * - DIL_MLDSA_87
 *
 * DIL_MLDSA_87 used in this project to verify the signature
 */

/// Dilithium public key size (bytes) @ref DIL_MLDSA_87_PUB_BYTES
#define DIL_MLDSA_87_CRYPTO_PUBLICKEY_SIZE     (2592)

/// Dilithium signature size (bytes) @ref DIL_MLDSA_SIGBYTES8x7
#define DIL_MLDSA_87_CRYPTO_SIG_SIZE           (4627)


// Enable of USE_DYNAMIC_ALLOC, The caller must support the mlca_alloc
// And mlca_free functions, which are used by dilithum
#if defined(USE_DYNAMIC_ALLOC)
    /**
    * @brief Allocate heap space of given size
    *
    * @param[in] size Size to allocate
    *
    * @return void* ( Generic pointer)
    */
    void* mlca_alloc(uint32_t size);

    /**
    * @brief Release allocated heap space by mlca_alloc
    *
    * @param[in] ptr Start address of allocated space
    *
    * @return void
    */
    void mlca_free(void* ptr);

#endif

/**
 * @brief ML-DSA dilithium verification
 *
 * @param[in] sig Pointer to input signature
 * @param[in] siglen Length of signature
 * @param[in] m Pointer to message
 * @param[in] mlen Length of message
 * @param[in] pk Pointer to bit-packed public key
 * @param[in] pkbytes Length of public key
 *
 * @return 0 (failure) or >0 (written bytecount)
 */
extern "C"
int mldsa_verify(const uint8_t* sig, size_t siglen,
                 const uint8_t* m, size_t mlen,
                 const uint8_t* pk, size_t pkbytes);
