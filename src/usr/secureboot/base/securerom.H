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

/** @file SecureRom.H
 *
 *  @brief SecureROM class definition and miscellaneious defines
 *  needed to work with Secure ROM binary
 */

#include <errl/errlentry.H>


/******************************************************************/
/*  Start of Chip Logic Secure ROM include section  */
/******************************************************************/
// These defines come from the following directory:
// /afs/awd/projects/eclipz/c22/libs/tp/logic/p8m/head/trusted_boot_rom/src
// and are needed to run functions in the SecureROM code stored in memory

/* From hw_utils.h:  */
#define ECID_SIZE 16


/* From ecverify.h   */
#define EC_COORDBYTES 66     /* P-521   */
typedef uint8_t ecc_key_t[2*EC_COORDBYTES];

/* From hw_utils.h */
#define PIBMEM 0x00080000
#define PIBMEM_HW_KEY_HASH (PIBMEM +0x0008)

/* From sha512.h:  */
typedef uint8_t  sha2_byte;     /* Exactly 1 byte */

// This is the interface that call_rom_SHA512 calls into
// void SHA512_Hash(const sha2_byte *data, size_t len, sha2_hash_t *result);


/*  From ROM.h */
typedef enum { ROM_DONE, ROM_FAILED, PHYP_PARTIAL } ROM_response;

typedef struct {
  uint32_t        magic_number;    // (17082011)
  uint16_t        version;         // (1: see versions above)
  uint64_t        container_size;  // filled by caller
  uint64_t        target_hrmor;    // filled by caller
  uint64_t        stack_pointer;   // filled by caller
  //bottom of stack -> 128k added by rom code to get real stack pointer
  ecc_key_t       hw_pkey_a;
  ecc_key_t       hw_pkey_b;
  ecc_key_t       hw_pkey_c;
  uint64_t        prefix; // prefix header place holder
  // followed by sw header (if not special prefix)
  // followed by optional unprotected payload data
}__attribute__((packed)) ROM_container_raw;


typedef struct {
  sha2_hash_t         hw_key_hash;
  uint8_t             my_ecid[ECID_SIZE];
  uint64_t            entry_point;
  uint64_t            log;
}__attribute__((packed)) ROM_hw_params;


// Need this for the following definition
#ifdef __cplusplus
extern "C"
{
#endif

// Interfaces for Assembly Functions to call into Secure ROM
// - 1st parameter is address of function offset into Secure ROM,
//   followed by additional parameters as necssary

ROM_response call_rom_verify(void*, ROM_container_raw*, ROM_hw_params*);
void         call_rom_SHA512(void*, const sha2_byte *, size_t, sha2_hash_t*);

#ifdef __cplusplus
}
#endif


/* Offsets needed to call functions in jump table at start of  */
/* SecureROM code - see .../trusted_boot_rom/bootrom.dis       */
#define SHA512_HASH_FUNCTION_OFFSET 0x20
#define ROM_VERIFY_FUNCTION_OFFSET 0x30


/******************************************************************/
/*  End of Chip Logic Secure ROM include section  */
/******************************************************************/


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
         * @param[in] i_size       Size of container
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t verifyContainer(void * i_container, size_t i_size);

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
        errlHndl_t hashBlob(void * i_blob, size_t i_size, SHA512_t io_buf);

        /**
         * @brief Retrieve the internal hardware hash key from secure ROM
         *        object.
         *
         * @param[out] o_hash  Reference to the sha2_hash_t array to copy the
         *                     hash to.
         */
        void getHwHashKeys(sha2_hash_t o_hash);


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
         * Hash Key Retrieved From System
         */
        sha2_hash_t iv_hash_key;


        /********************************************
         * Private Functions
         ********************************************/

        /**
         * @brief Retrieves HW Keys from the system
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t getHwHashKeys();

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
