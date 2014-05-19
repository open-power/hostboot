/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/service.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

namespace SECUREBOOT
{
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
     * @param[in] i_size       Size of container in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyContainer(void * i_container, size_t i_size);

    /**
     * @brief Hash Signed Blob
     *
     * @param[in]  i_blob    Void pointer to effective address of blob
     * @param[in]  i_size    Size of blob in bytes
     * @param[out] o_hash    SHA512 hash
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t hashBlob(void * i_blob, size_t i_size, SHA512_t o_buf);

}

#endif
