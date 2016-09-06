/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/securerom.H $                         */
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

#ifndef __SECUREBOOT_SECUREROM_H
#define __SECUREBOOT_SECUREROM_H

#include <errl/errlentry.H>
#include <secureboot/rom.H>
#include <utility>

typedef std::vector< std::pair<void*,size_t> > blobPair_t;

/** @class SecureROM
 *  @brief Class for loading and interacting with SecureROM in memory
 */
class SecureROM
{
    public:

        /**
         * @brief Initialize Secure Rom by loading it into memory and
         *        getting Hash Keys
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t initialize();

        /**
         * @brief Verify Container against system hash keys
         *
         * @param[in] i_container  Void pointer to effective address
         *                          of container
         * @param[in] i_hwKeyHash  Custom hw keys' hash to test against
         *                         [default = NULL, use current hw hash key]
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t verifyContainer(void * i_container,
                                   const sha2_hash_t* i_hwKeyHash = NULL);

        /**
         * @brief Hash Blob
         *
         * @param[in] i_blob        Void pointer to effective address
         *                              of blob
         * @param[in] i_size        Size of blob in bytes
         * @param[in/out] io_buf    Resulting hash buffer
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t hashBlob(const void * i_blob, size_t i_size, SHA512_t io_buf) const;

        /**
         * @brief Retrieve the internal hardware hash key from secure ROM
         *        object.
         *
         * @param[out] o_hash  Reference to the sha2_hash_t array to copy the
         *                     hash to.
         */
        void getHwKeyHash(sha2_hash_t o_hash);

        /*
         * @brief Hash the concatenation of N Blobs
         *
         * Asserts if any blob pointer is NULL
         *
         * @param[in]  i_blobs     Vector of pairs composed of a void
         *                         pointer to effective address and size
         *                         of the blob to concatenate
         * @param[out] o_buf       SHA512 hash
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t hashConcatBlobs (const blobPair_t &i_blobs,
                                    SHA512_t o_buf) const;

    protected:

        /**
         * @brief Constructor
         */
        SecureROM();

        /**
         * @brief Destructor
         */
        ~SecureROM();

    private:

        /********************************************
         * VARIABLES
         ********************************************/

        /**
         * Void pointer to effective address location of Secure ROM
         *  in memory
         */
        void * iv_device_ptr;

        /**
         * HW key hash Retrieved From System
         */
        sha2_hash_t iv_key_hash;

        /********************************************
         * Private Functions
         ********************************************/

        /**
         * @brief Retrieves HW Keys from the system
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t getHwKeyHash();

        /**
         * @brief Static instance function for testcase only
         */
        static SecureROM& getInstance();

        /**
         * @brief Safely Frees Allocated Memory
         */
        void _cleanup();

        /********************************************
         * Friend(s)
         ********************************************/

        // let my testcase poke around
        friend class SecureROMTest;

}; // end of SecureROM class

#endif
