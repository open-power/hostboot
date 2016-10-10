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
#include <utility>
#include <targeting/common/targetservice.H>
#include <config.h>

typedef uint8_t SHA512_t[64];

typedef std::vector< std::pair<void*,size_t> > blobPair_t;

/* From sha512.h:  */
#define SHA512_DIGEST_LENGTH 64
typedef uint8_t __attribute__((aligned(8))) sha2_hash_t[ \
                SHA512_DIGEST_LENGTH / sizeof(uint8_t) ];


extern trace_desc_t* g_trac_secure;

// Size of a single entry (in Bytes) in a PNOR hash page table.
// Set in buildpnor.pl
const size_t HASH_PAGE_TABLE_ENTRY_SIZE = 32;
typedef uint8_t PAGE_TABLE_ENTRY_t[HASH_PAGE_TABLE_ENTRY_SIZE];

namespace SECUREBOOT
{
    /******************************************/
    /*  Constants                             */
    /******************************************/

    // Processor Security Switch Register Details
    const uint64_t PROC_SECURITY_SWITCH_REGISTER = 0x00010005ull;
    const uint64_t
          PROC_SECURITY_SWITCH_JUMPER_STATE_MASK = 0x8000000000000000ull;
    const uint64_t
          PROC_SECURITY_SWITCH_TRUSTED_BOOT_MASK = 0x4000000000000000ull;
    const uint64_t
          PROC_SECURITY_SWITCH_PROTECT_I2C_SEEPROM_MASK = 0x0100000000000000ull;

    // L3 Purge register
    const uint64_t EX_L3_PURGE_REGISTER = 0x1001080Eull;

    // L2 Purge register
    const uint64_t EX_L2_PURGE_REGISTER = 0x1001280Full;

    // Core protect register
    const uint64_t CORE_PROTECT_REG_0x10013C03 = 0x10013C03ull;

    // Core protect register bits
    const uint64_t CORE_PROTECT_TRUSTED_BOOT_EN_BIT0 = 0x8000000000000000ull;

    // Chiplet multipliers
    const size_t EX_CHILPLET_MULTIPLIER = 0x01000000;

    /******************************************/
    /*  Functions                             */
    /******************************************/

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

    #ifdef CONFIG_SECUREBOOT
    /** @brief Read the bar values for a given target (must be a processor)
     *         and store its values for later matching against the expected
     *         bar values as per the bar value attributes in PNOR.
     *  @param[in] i_targ A target pointer. Must be a processor. Must not be
     *                    NULL.
     */
    void readProcBars(TARGETING::Target* i_targ);

    /** @brief Determine if the bar values match the expected values that
     *         were read previously using the readProcBars call.
     *  @param[in] i_targ A target pointer. Must be a processor. Must not be
     *                    NULL.
     *  @return NULL on success, otherwise a pointer to an error log.
     */
    errlHndl_t procBarValuesMatch(TARGETING::Target* i_targ);

    /**
     *  @brief Lock down processor's untrusted BAR registers, if applicable
     *
     *  @par Detailed Description:
     *      Lock down processor's untrusted BAR registers by setting the logical
     *      BAR size to 0, if applicable. This is a no-op unless the system is
     *      booting OPAL.
     *
     *  @param[in] i_pProc Handle to processor target.  Assertion will
     *      fire if NULL or not a processor.
     *
     *  @return NULL on success, otherwise a pointer to an error log
     */
    errlHndl_t lockProcUntrustedBars(
        const TARGETING::Target* i_pProc);

    #endif

    /** @brief Returns the state of the secure jumper as reported by the master
     *      processor.
     *
     *  @par Detailed Description:
     *      Returns the state of the secure jumper as reported by the master
     *      processor.  This should NOT be used to determine whether security is
     *      enabled, because several conditions are aggregated together to
     *      determine that.  To query whether security is actually enabled or
     *      not, call the enabled() API.  This is a limited-use API intended to
     *      be called by trusted boot code to determine whether a system shipped
     *      with a secure jumper applied or removed, in order to decide
     *      whether to enforce the "TPM Required" policy or not.
     *
     *  @return Boolean indicating acting master processor's secure jumper state
     *  @retval true Jumper is configured to request HW security.  This does not
     *      necessarily imply security is enabled, because an open SBE can
     *      override the HW policy.  Use the enabled() API to determine whether
     *      security is actually enabled.
     *  @retval false Jumper is configured to disble HW security.
     */
    bool getJumperState();

    /**
     * @brief Verify Signed Container
     *
     * @param[in] i_container  Void pointer to effective address of container
     * @param[in] i_hwKeyHash  Custom hw keys' hash to test against
     *                         [default = NULL, use current hw hash key]
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyContainer(void * i_container,
                               const sha2_hash_t* i_hwKeyHash = NULL);

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
     * @brief Retrieve the internal hardware hw key hash from secure ROM
     *        object.
     * @param[out] o_hash  Reference to the sha2_hash_t array to copy the
     *                     hash to.
     */
     void getHwKeyHash(sha2_hash_t o_hash);

     /*
      * @brief Hash the concatenation of N Blobs
      *
      *  Asserts if any blob pointer is NULL
      *
      * @param[in]  i_blobs     Vector of pairs composed of a void
      *                         pointer to effective address and size
      *                         of the blob to concatenate
      * @param[out] o_buf       SHA512 hash
      *
      * @return errlHndl_t  NULL on success
      */
    errlHndl_t hashConcatBlobs(const blobPair_t &i_blobs, SHA512_t o_buf);

    /**
     * @brief Secures/Locks I2C access to SBE Seeproms on each functional
     *        processor target in the system
     *
     * @return void   - All error logs are handled internally in this function
     */
    void secureSbeSeeproms( void );

    /**
     * @brief Common secureboot handler for secureboot failures.
     *        Properly handles callouts etc.
     * @param[in/out] io_err Reference to error log handle.  Caller's handle
     *     will be nullified.  Handle must not be NULL, or function asserts.
     * @param[in] i_waitForShutdown Whether to wait for system to shutdown (and
     *     never return from this call) or not (and return from this call).
     *     In general, code should wait for shutdown unless early in boot before
     *     basic services are up, or in a resource provider path.
     */
    void handleSecurebootFailure(
        errlHndl_t &io_err, bool i_waitForShutdown = true);

}

#endif
