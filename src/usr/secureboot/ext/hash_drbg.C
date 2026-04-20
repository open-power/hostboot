/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/hash_drbg.C $                          */
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
 * @file hash_drbg.C
 *
 * @brief Implementation of NIST SP 800-90A Hash_DRBG using SHA-512
 */

#include <secureboot/hash_drbg.H>
#include <secureboot/service.H>
#include "../common/securetrace.H"
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/secure_buffer.H>

#include <attributeenums.H>
#include <string.h>
#include <assert.h>
#include <conversions.H>
#include <limits.h>

// For SrcUserData
using namespace errl_util;

// Trace definition
extern trace_desc_t* g_trac_secure;

namespace SECUREBOOT
{

//******************************************************************************
// Hash_DRBG::Hash_DRBG
//******************************************************************************
Hash_DRBG::Hash_DRBG()
{
    SB_ENTER("Hash_DRBG::Hash_DRBG");
    // State is initialized by Hash_DRBG_State constructor
    SB_EXIT("Hash_DRBG::Hash_DRBG");
}

//******************************************************************************
// Hash_DRBG::~Hash_DRBG
//******************************************************************************
Hash_DRBG::~Hash_DRBG()
{
    SB_ENTER("Hash_DRBG::~Hash_DRBG");
    // Ensure state is cleared on destruction
    uninstantiate();
    SB_EXIT("Hash_DRBG::~Hash_DRBG");
}

//******************************************************************************
// Hash_DRBG::instantiate
//******************************************************************************
errlHndl_t Hash_DRBG::instantiate(const uint8_t* i_entropy_input,
                                   size_t i_entropy_length,
                                   const uint8_t* i_personalization,
                                   size_t i_personalization_length,
                                   uint16_t i_security_strength)
{
    errlHndl_t l_errl = nullptr;

    SB_ENTER("Hash_DRBG::instantiate: entropy_len=%d, pers_len=%d, strength=%d",
             i_entropy_length, i_personalization_length, i_security_strength);

    // Assert on required parameters
    assert(i_entropy_input != nullptr, "Hash_DRBG::instantiate: Entropy input must not be null");
    assert(i_entropy_length > 0, "Hash_DRBG::instantiate: Entropy length must be greater than 0");
    assert(i_entropy_length <= SIZE_MAX / CONVERSIONS::BITS_PER_BYTE,
        "Hash_DRBG::instantiate: Entropy length too large, would overflow when converting to bits");
    // Make sure personalization doesnt have one parameter filled but not the other
    assert((i_personalization == nullptr) == (i_personalization_length == 0),
        "Hash_DRBG::instantiate: Personalization input must be null if and only if length is 0. "
        "Personalization: %p, Personalization length: %d", i_personalization, i_personalization_length);

    do
    {
        // Check if DRBG is already instantiated
        if (iv_state.instantiated)
        {
            SB_ERR("Hash_DRBG::instantiate: DRBG already instantiated");
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_ALREADY_INSTANTIATED
             * @userdata1    0
             * @userdata2    0
             * @devdesc      Attempted to instantiate an already instantiated DRBG
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE,
                SECUREBOOT::RC_HASH_DRBG_ALREADY_INSTANTIATED,
                0,
                0,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Validate entropy input length including extra bits in absense of a separate nonce input
        // See NIST SP 800-90A section 8.6.4 for seed length and section 8.6.7 for nonce rules
        if (i_entropy_length*CONVERSIONS::BITS_PER_BYTE < (i_security_strength * 3) / 2)
        {
            SB_ERR("Hash_DRBG::instantiate: Entropy input too short: %d bits, Security Strength: %d",
                   i_entropy_length*CONVERSIONS::BITS_PER_BYTE, i_security_strength);
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_ENTROPY_TOO_SHORT
             * @userdata1    Provided entropy length (bits)
             * @userdata2    Minimum required length (same as security strength * 3/2)
             * @devdesc      Entropy input is too short
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE,
                SECUREBOOT::RC_HASH_DRBG_ENTROPY_TOO_SHORT,
                i_entropy_length*CONVERSIONS::BITS_PER_BYTE,
                (i_security_strength * 3) / 2,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        if (i_entropy_length > HASH_DRBG_MAX_ENTROPY_INPUT_LENGTH)
        {
            SB_ERR("Hash_DRBG::instantiate: Entropy input too long: %d > %d",
                   i_entropy_length, HASH_DRBG_MAX_ENTROPY_INPUT_LENGTH);
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_ENTROPY_TOO_LONG
             * @userdata1    Provided entropy length
             * @userdata2    Maximum allowed length
             * @devdesc      Entropy input is too long
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE,
                SECUREBOOT::RC_HASH_DRBG_ENTROPY_TOO_LONG,
                i_entropy_length,
                HASH_DRBG_MAX_ENTROPY_INPUT_LENGTH,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Validate personalization string length
        if (i_personalization_length > HASH_DRBG_MAX_PERSONALIZATION_STRING_LENGTH)
        {
            SB_ERR("Hash_DRBG::instantiate: Personalization string too long: %d > %d",
                   i_personalization_length, HASH_DRBG_MAX_PERSONALIZATION_STRING_LENGTH);
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_PERSONALIZATION_TOO_LONG
             * @userdata1    Provided personalization length
             * @userdata2    Maximum allowed length
             * @devdesc      Personalization string is too long
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE,
                SECUREBOOT::RC_HASH_DRBG_PERSONALIZATION_TOO_LONG,
                i_personalization_length,
                HASH_DRBG_MAX_PERSONALIZATION_STRING_LENGTH,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Validate security strength
        if (i_security_strength < HASH_DRBG_MIN_SECURITY_STRENGTH ||
            i_security_strength > HASH_DRBG_MAX_SECURITY_STRENGTH)
        {
            SB_ERR("Hash_DRBG::instantiate: Invalid security strength: %d",
                   i_security_strength);
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_SECURITY_STRENGTH
             * @userdata1    Requested security strength
             * @userdata2[0:31]   Minimum valid security strength
             * @userdata2[32:63]  Maximum valid security strength
             * @devdesc      Invalid security strength requested
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_INSTANTIATE,
                SECUREBOOT::RC_HASH_DRBG_SECURITY_STRENGTH,
                i_security_strength,
                SrcUserData(bits{0, 31}, HASH_DRBG_MIN_SECURITY_STRENGTH,
                            bits{32, 63}, HASH_DRBG_MAX_SECURITY_STRENGTH),
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Step 1: seed_material = entropy_input || personalization_string
        size_t seed_material_len = i_entropy_length + i_personalization_length;
        uint8_t* seed_material = new uint8_t[seed_material_len];
        memset(seed_material, 0, seed_material_len);

        memcpy(seed_material, i_entropy_input, i_entropy_length);
        if (i_personalization)
        {
            memcpy(seed_material + i_entropy_length,
                   i_personalization,
                   i_personalization_length);
        }

        // Step 2: seed = Hash_df(seed_material, seedlen)
        // Step 3: V = seed
        hash_df(seed_material, seed_material_len,
                        iv_state.V, HASH_DRBG_SEEDLEN_BYTES);

        // Clear seed material
        CLEAN_BUFFER_HEAP(seed_material, seed_material_len);

        // Step 4: C = Hash_df(0x00 || V, seedlen)
        uint8_t c_input[HASH_DRBG_SEEDLEN_BYTES + 1];
        c_input[0] = 0x00;
        memcpy(c_input + 1, iv_state.V, HASH_DRBG_SEEDLEN_BYTES);

        hash_df(c_input, sizeof(c_input),
                        iv_state.C, HASH_DRBG_SEEDLEN_BYTES);

        CLEAN_BUFFER_STACK(c_input, sizeof(c_input));

        // Step 4: reseed_counter = 1
        iv_state.reseed_counter = 1;

        // Step 5: Set security strength and instantiation flag
        iv_state.security_strength = i_security_strength;
        iv_state.instantiated = true;

        SB_INF("Hash_DRBG::instantiate: Successfully instantiated with strength=%d",
               i_security_strength);

    } while(0);

    SB_EXIT("Hash_DRBG::instantiate: errl=%p", l_errl);
    return l_errl;
}

//******************************************************************************
// Hash_DRBG::generate
//******************************************************************************
errlHndl_t Hash_DRBG::generate(uint8_t* o_output,
                                size_t i_requested_bytes)
{
    errlHndl_t l_errl = nullptr;

    SB_ENTER("Hash_DRBG::generate: requested=%d",
             i_requested_bytes);

    // Assert on required parameters
    assert(o_output != nullptr, "Hash_DRBG::generate: Output buffer must not be null");
    assert(i_requested_bytes > 0, "Hash_DRBG::generate: Requested bytes must be greater than 0");

    do
    {
        // Validate DRBG is instantiated
        if (!iv_state.instantiated)
        {
            SB_ERR("Hash_DRBG::generate: DRBG not instantiated");
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_GENERATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_NOT_INSTANTIATED
             * @userdata1    0
             * @userdata2    0
             * @devdesc      Attempted to generate from uninstantiated DRBG
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_GENERATE,
                SECUREBOOT::RC_HASH_DRBG_NOT_INSTANTIATED,
                0, 0, ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Validate requested bytes
        if (i_requested_bytes > HASH_DRBG_MAX_BYTES_PER_REQUEST)
        {
            SB_ERR("Hash_DRBG::generate: Invalid request size: %d", i_requested_bytes);
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_GENERATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_REQUEST_TOO_LARGE
             * @userdata1    Requested bytes
             * @userdata2    Maximum allowed
             * @devdesc      Requested bytes exceeds limit or is zero
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_GENERATE,
                SECUREBOOT::RC_HASH_DRBG_REQUEST_TOO_LARGE,
                i_requested_bytes,
                HASH_DRBG_MAX_BYTES_PER_REQUEST,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        if (iv_state.reseed_counter > HASH_DRBG_RESEED_INTERVAL)
        {
            SB_ERR("Hash_DRBG::generate: Maximum number of requests between reseeds reached: "
                "reseed counter=%d reseed interval=%d",
                iv_state.reseed_counter, HASH_DRBG_RESEED_INTERVAL);
            /*@
             * @errortype
             * @moduleid     SECUREBOOT::MOD_HASH_DRBG_GENERATE
             * @reasoncode   SECUREBOOT::RC_HASH_DRBG_RESEED_REQUIRED
             * @userdata1    Reseed counter
             * @userdata2    Maximum requests allowed between reseeeds
             * @devdesc      Number of generate requests exceeds limit
             * @custdesc     Secure boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_HASH_DRBG_GENERATE,
                SECUREBOOT::RC_HASH_DRBG_RESEED_REQUIRED,
                iv_state.reseed_counter,
                HASH_DRBG_RESEED_INTERVAL,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Step 3: Generate pseudorandom bits using Hashgen
        hashgen(i_requested_bytes, o_output);

        // Step 4: H = Hash(0x03 || V)
        uint8_t h_input[1 + HASH_DRBG_SEEDLEN_BYTES];
        h_input[0] = 0x03;
        memcpy(h_input + 1, iv_state.V, HASH_DRBG_SEEDLEN_BYTES);

        SHA512_t H;
        SECUREBOOT::hashBlob(h_input, sizeof(h_input), H, SB_SIGNING_V1_CONTAINER);

        CLEAN_BUFFER_STACK(h_input, sizeof(h_input));

        // Step 5: V = (V + H + C + reseed_counter) mod 2^seedlen
        add_bytes(iv_state.V, H, HASH_DRBG_SEEDLEN_BYTES, sizeof(H));
        add_bytes(iv_state.V, iv_state.C, HASH_DRBG_SEEDLEN_BYTES, HASH_DRBG_SEEDLEN_BYTES);
        add_bytes(iv_state.V, reinterpret_cast<uint8_t*>(&iv_state.reseed_counter),
            HASH_DRBG_SEEDLEN_BYTES, sizeof(iv_state.reseed_counter));

        CLEAN_BUFFER_STACK(H, sizeof(H));

        // Step 6: Increment reseed counter
        iv_state.reseed_counter++;

        SB_INF("Hash_DRBG::generate: Successfully generated %d bytes, counter=%lld",
               i_requested_bytes, iv_state.reseed_counter);

    } while(0);

    SB_EXIT("Hash_DRBG::generate: errl=%p", l_errl);
    return l_errl;
}

//******************************************************************************
// Hash_DRBG::uninstantiate
//******************************************************************************
void Hash_DRBG::uninstantiate()
{
    SB_ENTER("Hash_DRBG::uninstantiate");

    // Securely zero all internal state
    CLEAN_BUFFER_STACK(iv_state.V, sizeof(iv_state.V));
    CLEAN_BUFFER_STACK(iv_state.C, sizeof(iv_state.C));
    iv_state.reseed_counter = 0;
    iv_state.security_strength = 0;
    iv_state.instantiated = false;

    SB_INF("Hash_DRBG::uninstantiate: State cleared");
    SB_EXIT("Hash_DRBG::uninstantiate");
}

//******************************************************************************
// Hash_DRBG::hash_df
//******************************************************************************
void Hash_DRBG::hash_df(const uint8_t* i_input,
                        size_t i_input_length,
                        uint8_t* o_output,
                        size_t i_output_length)
{
    // Assert on required parameters
    assert(i_input != nullptr, "Hash_DRBG::hash_df: Input buffer must not be null");
    assert(o_output != nullptr, "Hash_DRBG::hash_df: Output buffer must not be null");
    assert(i_input_length > 0, "Hash_DRBG::hash_df: Input length must be greater than 0");
    assert(i_output_length > 0, "Hash_DRBG::hash_df: Output length must be greater than 0");

    // Hash_df as per NIST 800-90A Section 10.3.1
    uint32_t no_of_bits_to_return = i_output_length * CONVERSIONS::BITS_PER_BYTE;
    size_t len = (no_of_bits_to_return + HASH_DRBG_OUTLEN - 1) / HASH_DRBG_OUTLEN;

    // Ensure len doesn't exceed the maximum value of the uint8_t counter variable.
    // All known usages are well within this boundary.
    assert(len <= std::numeric_limits<uint8_t>::max(),
           "Hash_DRBG::hash_df: len exceeds uint8_t max, would overflow counter variable");

    uint8_t* temp = new uint8_t[len * SHA512_DIGEST_LENGTH];
    memset(temp, 0, len * SHA512_DIGEST_LENGTH);
    size_t temp_offset = 0;

    // For counter = 1 to len do
    for (uint8_t counter = 1; counter <= len; counter++)
    {
        // Hash(counter || no_of_bits_to_return || input_string)
        size_t hash_input_len = sizeof(counter) + sizeof(no_of_bits_to_return) + i_input_length;
        uint8_t* hash_input = new uint8_t[hash_input_len];
        memset(hash_input, 0, hash_input_len);

        hash_input[0] = counter;

        *reinterpret_cast<uint32_t*>(hash_input + 1) = no_of_bits_to_return;

        memcpy(hash_input + 5, i_input, i_input_length);

        SHA512_t hash_output;
        SECUREBOOT::hashBlob(hash_input, hash_input_len, hash_output, SB_SIGNING_V1_CONTAINER);

        memcpy(temp + temp_offset, hash_output, SHA512_DIGEST_LENGTH);
        temp_offset += SHA512_DIGEST_LENGTH;

        CLEAN_BUFFER_HEAP(hash_input, hash_input_len);
        CLEAN_BUFFER_STACK(hash_output, sizeof(hash_output));
    }

    // requested_bits = leftmost(temp, no_of_bits_to_return)
    memcpy(o_output, temp, i_output_length);

    CLEAN_BUFFER_HEAP(temp, len * SHA512_DIGEST_LENGTH);
}

//******************************************************************************
// Hash_DRBG::hashgen
//******************************************************************************
void Hash_DRBG::hashgen(size_t i_requested_bytes,
                        uint8_t* o_output)
{
    // Assert on required parameters
    assert(o_output != nullptr, "Hash_DRBG::hashgen: Output buffer must not be null");
    assert(i_requested_bytes > 0, "Hash_DRBG::hashgen: Requested bytes must be greater than 0");

    // Hashgen as per NIST 800-90A Section 10.1.1.4
    // m = ceil(requested_number_of_bits / outlen)
    size_t requested_bits = i_requested_bytes * 8;
    size_t m = (requested_bits + HASH_DRBG_OUTLEN - 1) / HASH_DRBG_OUTLEN;

    // data = V
    uint8_t data[HASH_DRBG_SEEDLEN_BYTES] = {};
    memcpy(data, iv_state.V, HASH_DRBG_SEEDLEN_BYTES);

    // W = Null
    uint8_t* W = new uint8_t[m * SHA512_DIGEST_LENGTH];
    memset(W, 0, m * SHA512_DIGEST_LENGTH);
    size_t W_offset = 0;

    // For i = 1 to m
    for (size_t i = 1; i <= m; i++)
    {
        // w = Hash(data)
        SHA512_t w;
        SECUREBOOT::hashBlob(data, HASH_DRBG_SEEDLEN_BYTES, w, SB_SIGNING_V1_CONTAINER);

        memcpy(W + W_offset, w, SHA512_DIGEST_LENGTH);
        W_offset += SHA512_DIGEST_LENGTH;

        // data = (data + 1) mod 2^seedlen
        increment_bytes(data, HASH_DRBG_SEEDLEN_BYTES);

        CLEAN_BUFFER_STACK(w, sizeof(w));
    }

    // returned_bits = leftmost(W, requested_number_of_bits)
    memcpy(o_output, W, i_requested_bytes);

    CLEAN_BUFFER_STACK(data, sizeof(data));
    CLEAN_BUFFER_HEAP(W, m * SHA512_DIGEST_LENGTH);
}

//******************************************************************************
// Hash_DRBG::add_bytes
//******************************************************************************
void Hash_DRBG::add_bytes(uint8_t* io_a, const uint8_t* i_b, const size_t i_a_len, const size_t i_b_len)
{
    // Assert on required parameters
    assert(io_a != nullptr, "Hash_DRBG::add_bytes: First operand buffer must not be null");
    assert(i_b != nullptr, "Hash_DRBG::add_bytes: Second operand buffer must not be null");
    assert(i_a_len > 0, "Hash_DRBG::add_bytes: Length must be greater than 0");
    assert(i_a_len >= i_b_len, "Hash_DRBG::add_bytes: "
        "First operand length must be greater than or equal to the second operand length");

    uint16_t carry = 0;
    size_t a_i = i_a_len - 1;
    size_t b_i = i_b_len - 1;

    // Add from right to left (big-endian)
    for (size_t reverse_i = 0; reverse_i < i_a_len; reverse_i++)
    {
        uint8_t b_val = 0;
        if (reverse_i < i_b_len)
        {
            b_val = i_b[b_i];
            b_i--;
        }

        uint16_t sum = io_a[a_i] + b_val + carry;
        io_a[a_i] = sum & 0xFF;
        carry = sum >> 8;

        a_i--;
    }
}

//******************************************************************************
// Hash_DRBG::increment_bytes
//******************************************************************************
void Hash_DRBG::increment_bytes(uint8_t* io_data, size_t i_len)
{
    // Assert on required parameters
    assert(io_data != nullptr, "Hash_DRBG::increment_bytes: Data buffer must not be null");
    assert(i_len > 0, "Hash_DRBG::increment_bytes: Length must be greater than 0");

    // Increment from right to left (big-endian)
    for (int i = i_len - 1; i >= 0; i--)
    {
        io_data[i]++;
        if (io_data[i] != 0)
        {
            break;  // No carry, done
        }
        // Otherwise carry to next byte
    }
}

} // namespace SECUREBOOT
