/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/hash_drbg.H $                      */
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

/**
 * @file hash_drbg.H
 *
 * @brief NIST SP 800-90A Hash_DRBG (Deterministic Random Bit Generator)
 *        implementation using SHA-512
 *
 * This implements a cryptographically secure pseudorandom number generator
 * based on NIST SP 800-90A Rev 1 specification. It uses SHA-512 as the
 * underlying hash function via the existing hashBlob interface.
 *
 * Features:
 * - Configurable security strength (default 256 bits, supports down to 128 bits)
 * - Instantiate with entropy input and optional personalization string
 * - Generate pseudorandom bits
 * - Reseed counter tracking for compliance
 * - No reseeding support (simplified for key generation use case)
 */

#ifndef __SECUREBOOT_HASH_DRBG_H
#define __SECUREBOOT_HASH_DRBG_H

#include <math.h>
#include <stdint.h>
#include <stddef.h>
#include <errl/errlentry.H>
#include <securerom/sha512.H>

namespace SECUREBOOT
{

/**
 * @brief NIST 800-90A Hash_DRBG constants for SHA-512
 */

// SHA-512 specific constants per NIST 800-90A Table 2
constexpr uint16_t HASH_DRBG_OUTLEN = 512;              ///< Output length in bits (SHA-512)
constexpr uint16_t HASH_DRBG_SEEDLEN = 888;             ///< Seed length in bits for SHA-512
constexpr size_t HASH_DRBG_SEEDLEN_BYTES = 111;         ///< Seed length in bytes (888/8)

// Security strength
constexpr uint16_t HASH_DRBG_MIN_SECURITY_STRENGTH = 128;      ///< Security strength (bits)
constexpr uint16_t HASH_DRBG_MAX_SECURITY_STRENGTH = 256;      ///< Security strength (bits)
constexpr uint16_t HASH_DRBG_DEFAULT_SECURITY_STRENGTH = 256;  ///< Security strength (bits)

// Entropy input requirements (per NIST 800-90A Section 10.1)
constexpr size_t HASH_DRBG_MAX_ENTROPY_INPUT_LENGTH = 4294967296; ///< Max entropy bytes (2^35 bits)

// Generation limits
constexpr size_t HASH_DRBG_MAX_BYTES_PER_REQUEST = 65536;        ///< Max bytes per generate (2^19 bits)
constexpr size_t HASH_DRBG_MAX_PERSONALIZATION_STRING_LENGTH = 4294967296; ///< Max personalization bytes (2^35 bits)
constexpr size_t HASH_DRBG_RESEED_INTERVAL = 281474976710656; ///< Reseed interval (2^48 requests)

/**
 * @brief Hash_DRBG internal state structure
 *
 * This structure maintains the internal state of the DRBG as specified
 * in NIST 800-90A Section 10.1.1.1
 */
struct Hash_DRBG_State
{
    uint8_t V[HASH_DRBG_SEEDLEN_BYTES];  ///< Internal state value
    uint8_t C[HASH_DRBG_SEEDLEN_BYTES];  ///< Constant value
    uint64_t reseed_counter;              ///< Reseed counter
    uint16_t security_strength;           ///< Security strength in bits
    bool instantiated;                    ///< Instantiation state

    /**
     * @brief Constructor - initializes state to zero
     */
    Hash_DRBG_State() : reseed_counter(0),
                        security_strength(HASH_DRBG_DEFAULT_SECURITY_STRENGTH),
                        instantiated(false)
    {
        memset(V, 0, sizeof(V));
        memset(C, 0, sizeof(C));
    }
};

/**
 * @brief Hash_DRBG class implementing NIST 800-90A Hash_DRBG
 *
 * This class provides a cryptographically secure deterministic random
 * bit generator using SHA-512 as the underlying hash function.
 *
 * Usage example:
 * @code
 *   Hash_DRBG drbg;
 *   uint8_t entropy[32] = {...};  // From hardware RNG or TPM
 *   uint8_t output[32];
 *
 *   errlHndl_t err = drbg.instantiate(entropy, sizeof(entropy),
 *                                     nullptr, 0, 128);
 *   if (!err)
 *   {
 *       err = drbg.generate(output, sizeof(output));
 *   }
 *   drbg.uninstantiate();
 * @endcode
 */
class Hash_DRBG
{
public:
    /**
     * @brief Constructor
     */
    Hash_DRBG();

    /**
     * @brief Destructor - ensures state is cleared
     */
    ~Hash_DRBG();

    /**
     * @brief Instantiate the DRBG with entropy input
     *
     * Implements Hash_DRBG_Instantiate_algorithm from NIST 800-90A Section 10.1.1.2
     *
     * @param[in] i_entropy_input      Entropy input bytes
     * @param[in] i_entropy_length     Length of entropy input in bytes
     * @param[in] i_personalization    Optional personalization string (can be nullptr)
     * @param[in] i_personalization_length Length of personalization string in bytes
     * @param[in] i_security_strength  Requested security strength in bits (128-256)
     *
     * @return errlHndl_t  Error log handle on failure, nullptr on success
     *
     * @note This implementation doesnt support a separate nonce input,
     *       so it must be included in the entropy input
     * @note Entropy input must be at least (3/2)*security strength bits (Extra half is for nonce)
     * @note Personalization string is optional but recommended for domain separation
     */
    errlHndl_t instantiate(const uint8_t* i_entropy_input,
                          size_t i_entropy_length,
                          const uint8_t* i_personalization,
                          size_t i_personalization_length,
                          uint16_t i_security_strength = HASH_DRBG_DEFAULT_SECURITY_STRENGTH);

    /**
     * @brief Generate pseudorandom bits
     *
     * Implements Hash_DRBG_Generate_algorithm from NIST 800-90A Section 10.1.1.4
     *
     * @param[out] o_output            Buffer to receive pseudorandom bytes
     * @param[in]  i_requested_bytes   Number of bytes to generate (max 65536)
     *
     * @return errlHndl_t  Error log handle on failure, nullptr on success
     *
     * @note DRBG must be instantiated before calling generate
     * @note Additional input not supported in this implementation
     * @note Reseed counter is checked but reseeding is not supported
     */
    errlHndl_t generate(uint8_t* o_output,
                       size_t i_requested_bytes);

    /**
     * @brief Uninstantiate the DRBG and clear internal state
     *
     * Implements Hash_DRBG_Uninstantiate_algorithm from NIST 800-90A Section 10.1.1.5
     * Securely zeros all internal state variables.
     */
    void uninstantiate();

    /**
     * @brief Check if DRBG is instantiated
     *
     * @return bool  True if instantiated, false otherwise
     */
    bool isInstantiated() const { return iv_state.instantiated; }

    /**
     * @brief Get configured security strength
     *
     * @return uint16_t  Security strength in bits
     */
    uint16_t getSecurityStrength() const { return iv_state.security_strength; }

private:
    Hash_DRBG_State iv_state;  ///< Internal DRBG state

    /**
     * @brief Hash derivation function (Hash_df)
     *
     * Implements Hash_df from NIST 800-90A Section 10.3.1
     * Derives a bit string of requested length from input data
     *
     * @param[in]  i_input        Input data to derive from
     * @param[in]  i_input_length Length of input data
     * @param[out] o_output       Output buffer for derived bits
     * @param[in]  i_output_length Requested output length in bytes
     *
     */
    void hash_df(const uint8_t* i_input,
                 size_t i_input_length,
                 uint8_t* o_output,
                 size_t i_output_length);

    /**
     * @brief Hashgen function for generating pseudorandom bits
     *
     * Implements Hashgen from NIST 800-90A Section 10.1.1.4
     *
     * @param[in]  i_requested_bytes Number of bytes to generate
     * @param[out] o_output          Output buffer for generated bits
     *
     */
    void hashgen(size_t i_requested_bytes,
                 uint8_t* o_output);

    /**
     * @brief Add two big-endian byte arrays (modulo 2^i_a_len)
     *
     * Helper function for internal state updates.
     * Adds two big-endian byte arrays (modulo 2^i_a_len) and store in the first byte array.
     * Cases of rollover will be handled via modulo 2^i_a_len.
     *
     * @param[in,out] io_a  First operand and result
     * @param[in]     i_b   Second operand
     * @param[in]     i_a_len Length of array a in bytes
     * @param[in]     i_b_len Length of array b in bytes
     *
     * @note function will assert if i_a_len < io_b_len
     */
    void add_bytes(uint8_t* io_a, const uint8_t* i_b, const size_t i_a_len, const size_t i_b_len);

    /**
     * @brief Increment a big-endian byte array by 1
     *
     * Cases of rollover will be handled via modulo 2^i_len
     *
     * @param[in,out] io_data Data to increment
     * @param[in]     i_len   Length of array in bytes
     */
    void increment_bytes(uint8_t* io_data, size_t i_len);

    // Prevent copying
    Hash_DRBG(const Hash_DRBG&) = delete;
    Hash_DRBG& operator=(const Hash_DRBG&) = delete;
};

} // namespace SECUREBOOT

#endif // __SECUREBOOT_HASH_DRBG_H
