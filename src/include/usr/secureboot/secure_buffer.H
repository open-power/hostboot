/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/secure_buffer.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2026                             */
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
#ifndef __SECURE_BUFFER_H_
#define __SECURE_BUFFER_H_

// The is_zero_assert function below relies on assert() to verify that
// sensitive buffers have been properly zeroed. If NDEBUG is defined,
// assert() becomes a no-op, which would compromise the security
// guarantees of the buffer cleaning macros. This compile-time check
// forces a build failure if NDEBUG is ever defined, ensuring the assert
// remains active and security guarantees are maintained.
#ifdef NDEBUG
#error "NDEBUG must not be defined - assert() is required for security"
#endif

/**
 * @file secure_buffer.H
 *
 * @brief Macros for securely cleaning sensitive data buffers
 *
 * This file provides macros to ensure that buffers containing sensitive data
 * (such as cryptographic keys, random numbers, or intermediate values) are
 * properly zeroed before being released. This prevents sensitive data from
 * remaining in memory where it could potentially be accessed by unauthorized
 * code or persist across process boundaries.
 *
 * Security Rationale:
 * - Prevents sensitive data from lingering in memory after use
 * - Verifies that zeroing actually occurred (defense against compiler optimization)
 * - Ensures pointers are nullified to prevent use-after-free vulnerabilities
 * - Provides consistent secure cleanup pattern across the codebase
 */

typedef void *(*memset_t)(void *, int, size_t);
static volatile memset_t memset_func = memset;

/**
 * @brief Securely zero memory in a way that cannot be optimized away
 *
 * This function uses a volatile function pointer approach
 * to prevent the compiler from optimizing away the memset call.
 * Even if the compiler determines that the memory will not be read again, the
 * volatile function pointer forces the memset to be executed.
 *
 * This is critical for security-sensitive code where we must guarantee that
 * sensitive data (keys, passwords, etc.) is actually zeroed from memory.
 *
 * @param[in] i_ptr   Pointer to the buffer to zero
 * @param[in] i_size  Size of the buffer in bytes
 */
static inline void secure_cleanse(void* i_ptr, size_t i_size)
{
    memset_func(i_ptr, 0, i_size);
}

/**
 * @brief Verify that a buffer has been completely zeroed
 *
 * This helper function checks every byte in the buffer to ensure it has been
 * set to zero. This verification step provides an additional layer of defense
 * by reading back the memory and asserting that it was actually zeroed.
 *
 * @param[in] i_buffer  Pointer to the buffer to verify
 * @param[in] i_size    Size of the buffer in bytes
 *
 * @note This function will assert if any non-zero bytes are found
 */
static inline void is_zero_assert(const void* i_buffer, const size_t i_size)
{
    const uint8_t* buf = reinterpret_cast<const uint8_t*>(i_buffer);
    for (size_t i = 0; i < i_size; i++)
    {
        assert(!(buf[i]), "Secure buffer was not zeroed!");
    }
}

/**
 * @brief Securely clean a stack-allocated buffer
 *
 * This macro should be used for buffers allocated on the stack (local arrays).
 * It performs two critical operations:
 * 1. Zeros all bytes in the buffer using memset
 * 2. Verifies the buffer was actually zeroed (prevents compiler optimization)
 *
 * Note: Unlike CLEAN_BUFFER_HEAP, this macro does not nullify the pointer
 * because stack-allocated arrays cannot be reassigned. The buffer will go
 * out of scope naturally when the function returns.
 *
 * Example usage:
 * @code
 *     uint8_t sensitive_data[64];
 *     // ... use sensitive_data ...
 *     CLEAN_BUFFER_STACK(sensitive_data, sizeof(sensitive_data));
 * @endcode
 *
 * @param[in] _ptr   Pointer to the buffer to clean
 * @param[in] _size  Size of the buffer in bytes
 *
 * @note Use this macro for stack-allocated buffers only
 * @note For pointers to stack buffers, the pointer itself is not modified
 */
#define CLEAN_BUFFER_STACK(_ptr, _size) \
    do { \
        secure_cleanse(_ptr, _size); \
        is_zero_assert(_ptr, _size); \
    } while (0);

/**
 * @brief Securely clean a heap-allocated buffer
 *
 * This macro should be used for buffers allocated on the heap with new[].
 * It performs four critical operations:
 * 1. Zeros all bytes in the buffer using memset
 * 2. Verifies the buffer was actually zeroed (prevents compiler optimization)
 * 3. Frees the memory using delete[]
 * 4. Sets the pointer to nullptr to prevent use-after-free
 *
 * Example usage:
 * @code
 *     uint8_t* sensitive_data = new uint8_t[256];
 *     // ... use sensitive_data ...
 *     CLEAN_BUFFER_HEAP(sensitive_data, 256);
 * @endcode
 *
 * @param[in] _ptr   Pointer to the buffer to clean
 * @param[in] _size  Size of the buffer in bytes
 *
 * @note Use this macro for heap-allocated buffers (allocated with new[]) only
 * @note The pointer will be set to nullptr after cleaning and deallocation
 * @note Do not use this macro for buffers allocated with malloc() or single objects
 */
#define CLEAN_BUFFER_HEAP(_ptr, _size) \
    do { \
        secure_cleanse(_ptr, _size); \
        is_zero_assert(_ptr, _size); \
        delete[] _ptr; \
        _ptr = nullptr; \
    } while (0);

#endif
