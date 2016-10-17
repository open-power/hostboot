/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/service.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#ifndef __SECUREBOOT_SERVICE_H
#define __SECUREBOOT_SERVICE_H

#include <errl/errlentry.H>

typedef uint8_t SHA512_t[64];
/* From sha512.h:  */
#define SHA512_DIGEST_LENGTH 64
typedef uint8_t __attribute__((aligned(8))) sha2_hash_t[ \
                SHA512_DIGEST_LENGTH / sizeof(uint8_t) ];

// TODO securebootp9 added for spnorrp.C - service.H needs many more updates
// in order to match the p8 version
const size_t HASH_PAGE_TABLE_ENTRY_SIZE = 32;
typedef uint8_t PAGE_TABLE_ENTRY_t[HASH_PAGE_TABLE_ENTRY_SIZE];


namespace SECUREBOOT
{
    // TODO securebootp9 - the two constants below were taken from master-p8
    // branch (version 2257b1) of service.H underneath secureboot.
    // The p9 version of service.H needs many more updates in order to match
    // the p8 version.
    const uint64_t PROC_SECURITY_SWITCH_REGISTER = 0x00010005ull;
    const uint64_t
          PROC_SECURITY_SWITCH_TRUSTED_BOOT_MASK = 0x8000000000000000ull;

    /** @brief Perform initialization of Secureboot for the Base image.
     *
     *  - Copy secure header from original location.
     *  - Perform blind-purge of bottom-half of cache.
     *  - Add bottom-half of cache to available memory.
     */
    void* initializeBase(void* unused);

    /**
     * @brief Initialize Secure Rom by loading it into memory and
     *        retrieving Hash Keys
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initializeSecureROM(void);


    /** @brief Determines if Secureboot is enabled.
     */
    bool enabled();

    /**
     * @brief Verify Signed Container
     *
     * @param[in] i_container  Void pointer to effective address of container
     * @param[in] i_hwKeyHash  Custom hw keys' hash to test against
     *                         [default = nullptr, use current hw hash key]
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyContainer(void * i_container,
                               const sha2_hash_t* i_hwKeyHash = nullptr);

    /**
     * @brief Hash Signed Blob
     *
     * @param[in]  i_blob    Void pointer to effective address of blob
     * @param[in]  i_size    Size of blob in bytes
     * @param[out] o_hash    SHA512 hash
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t hashBlob(const void * i_blob, size_t i_size, SHA512_t o_buf);

    /**
     * @brief Retrieve the internal hardware hash key from secure ROM
     *        object.
     * @param[out] o_hash  Reference to the sha2_hash_t array to copy the
     *                     hash to.
     */
    void getHwHashKeys(sha2_hash_t o_hash);

    /**
     * @brief Common secureboot handler for secureboot failures.
     *        Properly handles callouts etc.
     *
     * @return i_err   - Error log to cascade through failure path.
     */
    void handleSecurebootFailure(errlHndl_t &i_err);

}

#endif
