/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/securerommgr.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

#ifndef __SECUREBOOT_SECUREROMMANAGER_H
#define __SECUREBOOT_SECUREROMMANAGER_H

#include <errl/errlentry.H>
#include <securerom/ROM.H>
#include <utility>
#include <map>

typedef std::vector< std::pair<void*,size_t> > blobPair_t;

/** @class SecureRomManager
 *  @brief Class for loading and interacting with SecureROM in memory
 */
class SecureRomManager
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
         * @param[in] i_ids  Vector of IDs (PNOR or Lid Id(s)) associated with
         *                   the blob that is being verified.
         *                   [default = empty vector]
         * @param[in] i_hwKeyHash  Custom hw keys' hash to test against
         *                         [default = nullptr, use current hw hash key
         *
         * @return errlHndl_t NULL on success
         */
        errlHndl_t verifyContainer(void * i_container,
                                   const RomVerifyIds& i_ids = RomVerifyIds(),
                                   const SHA512_t* i_hwKeyHash = nullptr);

        /**
         * @brief Hash Blob
         *
         * @param[in] i_blob        Void pointer to effective address
         *                              of blob
         * @param[in] i_size        Size of blob in bytes
         * @param[out] o_buf        Resulting hash buffer
         *
         * @return N/A
         */
        void hashBlob(const void * i_blob, size_t i_size, SHA512_t o_buf) const;

        /**
         * @brief Retrieve the internal hardware keys' hash from secure ROM
         *        object.
         *
         * @param[out] o_hash  Reference to the SHA512_t array to copy the
         *                     hash to.
         */
        void getHwKeyHash(SHA512_t o_hash);

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
         * @return N/A
         */
        void hashConcatBlobs (const blobPair_t &i_blobs, SHA512_t o_buf) const;

        /*
         * @brief Get offset of function from the start of the SecureROM
         *
         * @param[in]  i_funcType   Secure Boot function type to get version of
         *
         * @return uint64_t - offset of the function
         */
        sbFuncVer_t getSecRomFuncVersion(const sbFuncType_t i_funcType) const;

        /*
         * @brief Get offset of function from the start of the SecureROM
         *
         *
         * @param[in]  i_funcType   Secure Boot function type to get offset of
         *
         * @return uint64_t - offset of the function
         */
        uint64_t getSecRomFuncOffset(const sbFuncType_t i_funcType) const;


    protected:

        /**
         * @brief  Constructor
         */
        SecureRomManager():iv_securerom(nullptr),
                           iv_secureromValid(false),
                           iv_key_hash(nullptr),
                           iv_curSHA512Ver(SB_FUNC_VERS::SHA512_INIT),
                           iv_curECDSA521Ver(SB_FUNC_VERS::ECDSA521_INIT) {}

        /**
         * @brief Destructor
         */
        ~SecureRomManager() {}

    private:

        /********************************************
         * VARIABLES
         ********************************************/

        /**
         * Void pointer to effective address location of Secure ROM in memory
         */
        const void * iv_securerom;

        /**
         * Cached valid check if secure rom is valid
         */
        bool iv_secureromValid;

        /**
         * HW key' hash retrieved from system
         */
        const SHA512_t* iv_key_hash;

        /**
         * @brief Map to find verify SecureROM function types and their
         *        respective versions and offsets.
         *
         * Description: Nested Map where key is the function type and the
         *              value is a map of versions to offsets
         *
         */
        // Type of nest map in SecRomFuncTypeOffset
        typedef std::map<sbFuncVer_t, uint64_t> FuncVerToOffsetMap_t;
        typedef std::map<sbFuncType_t, FuncVerToOffsetMap_t > SecRomFuncTypeOffsetMap_t;
        static const SecRomFuncTypeOffsetMap_t iv_SecRomFuncTypeOffset;

        // SHA512 function version
        sbFuncVer_t iv_curSHA512Ver;

        // ECDSA521 function version
        sbFuncVer_t iv_curECDSA521Ver;

        /********************************************
         * Private Functions
         ********************************************/

        /**
         * @brief Retrieves HW keys' hash from the system
         */
        void getHwKeyHash();

}; // end of SecureRomManager class

#endif
