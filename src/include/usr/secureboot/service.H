/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/service.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <config.h>
#include <secureboot/settings.H>
#include <utility>
#include <cstdint>

typedef uint8_t SHA512_t[64];

typedef std::vector< std::pair<void*,size_t> > blobPair_t;

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
    // these constants represent the scom addresses and masks we need
    // to obtain secure boot settings from the system
    enum class ProcSecurity : uint64_t
    {
        SabBit = 0x8000000000000000ull,
        SeepromLockBit = 0x800000000000000ull,
        SwitchRegister = 0x00010005ull,
    };

    enum class ProcCbsControl : uint64_t
    {
        JumperStateBit = 0x0400000000000000ull,
        StatusRegister = 0x00050001ull,
    };

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
#if defined(CONFIG_SECUREBOOT) && !defined(__HOSTBOOT_RUNTIME)
    bool enabled();
#else
    inline bool enabled() { return false; };
#endif
    //@fixme-RTC:163094-Remove RUNTIME check once the code is there

    /** @brief Get security switch register value
     *  @par Detailed Description:
     *      Returns the state of the security switch register as
     *      reported by the given processor (via the supplied target
     *      pointer).
     *  @param[out] o_regValue The value read from the register if the
     *      call was successful. If not successful this value is set to
     *      zero. Check the return value for a non null error log to
     *      determine if the call was unsuccessful.
     *  @param[in] i_targ The target processor to obtain the jumper
     *      state from. Must not be null. Optional parameter that
     *      defaults to master processor.
     *  @return errlHndl_t indicating whether the query was successful.
     *  @retval null if successful otherwise pointer to error log
     */
    errlHndl_t getSecuritySwitch(uint64_t& o_regValue,
            TARGETING::Target* i_targ
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);


    /** @brief Returns the state of the secure jumper as reported by the
     *      given processor.
     *
     *  @par Detailed Description:
     *      Returns the state of the secure jumper as reported by the
     *      the given processor.  This should NOT be used to determine
     *      whether security is enabled, because several conditions are
     *      aggregated together to determine that.  To query whether
     *      security is actually enabled or not, call the enabled() API.
     *      This is a limited-use API intended to be called by trusted
     *      boot code to determine whether a system shipped with a
     *      secure jumper applied or removed, in order to decide
     *      whether to enforce the "TPM Required" policy or not.
     *  @param[out] o_state Provides an enum value of type SecureJumperState
     *      that can be either SECURITY_DEASSERTED or SECURITY_ASSERTED
     *      indicating the given processor's secure jumper state.
     *      Asserted means it is configured to request HW security.  This
     *      does not necessarily imply security is enabled, because the
     *      HW can be overridden by some functions.  Use the getEnabled()
     *      API to determine whether security is actually enabled.
     *      Deasserted means the jumper is configured to disble HW security.
     *  @param[in] i_targ The target processor to obtain the jumper
     *      state from. Must not be null. Optional parameter that
     *      defaults to master processor.
     *
     *  @return errlHndl_t indicating whether the query was successful.
     *  @retval null if successful otherwise pointer to error log.
     */
    errlHndl_t getJumperState(SecureJumperState& o_state,
                TARGETING::Target* i_targ
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

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
     * @brief Retrieve the internal hardware keys' hash used to validate
     *     containers
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
