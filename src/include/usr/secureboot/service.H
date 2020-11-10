/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/service.H $                        */
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
#ifndef __SECUREBOOT_SERVICE_H
#define __SECUREBOOT_SERVICE_H

#include <errl/errlentry.H>
#include <config.h>
#include <secureboot/settings.H>
#include <utility>
#include <cstdint>
#include <securerom/sha512.H>
#include <securerom/ROM.H>

/*
 * @brief Used to capture the first 4 bytes of the hash for tracing purposes
 */
inline uint32_t sha512_to_u32(SHA512_t i_hash)
{
   if (i_hash == nullptr)
   {
       return 0;
   }
   else
   {
       return *(reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(i_hash)));
   }
};

typedef std::vector< std::pair<void*,size_t> > blobPair_t;

// TODO securebootp9 added for spnorrp.C - service.H needs many more updates
// in order to match the p8 version
const size_t HASH_PAGE_TABLE_ENTRY_SIZE = 32;
typedef uint8_t PAGE_TABLE_ENTRY_t[HASH_PAGE_TABLE_ENTRY_SIZE];


namespace SECUREBOOT
{
    class ContainerHeader;

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
    errlHndl_t initializeSecureRomManager(void);

    /**
     * @brief Trace the Security Settings on each functional processor
     *
     *  @param[in] i_doConsoleTrace Optional variable that determines if
     *                              register values are traced to the CONSOLE.
     *                              Default is false
     *
     *  @return errlHndl_t  nullptr on success, else pointer to error log
     */
    errlHndl_t traceSecuritySettings(bool i_doConsoleTrace = false);


    /** @brief Determines if Secureboot is enabled.
     */
#if defined(CONFIG_SECUREBOOT)
    bool enabled();
#else
    inline bool enabled() { return false; };
#endif

    /** @brief Get security switch register value
     *  @par Detailed Description:
     *      Returns the state of the security switch register as
     *      reported by the given processor (via the supplied target
     *      pointer).
     *  @param[out] o_regValue The value read from the register if the
     *      call was successful. If not successful this value is set to
     *      zero. Check the return value for a non null error log to
     *      determine if the call was unsuccessful.
     *  @param[in] i_pProc The target processor to obtain the jumper
     *      state from. Must not be null. Optional parameter that
     *      defaults to master processor.
     *  @return errlHndl_t indicating whether the query was successful.
     *  @retval null if successful otherwise pointer to error log
     */
    errlHndl_t getSecuritySwitch(uint64_t& o_regValue,
            TARGETING::Target* i_pProc
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

    /** @brief Get Processor CBS Control register value
     *  @par Detailed Description:
     *      Returns the state of the Processor CBS Control register as
     *      reported by the given processor (via the supplied target
     *      pointer).
     *  @param[out] o_regValue The value read from the register if the
     *      call was successful. If not successful this value is set to
     *      zero. Check the return value for a non null error log to
     *      determine if the call was unsuccessful.
     *  @param[in] i_pProc The target processor to obtain the jumper
     *      state from. Must not be null. Optional parameter that
     *      defaults to the master processor sentinel.
     */
    errlHndl_t getProcCbsControlRegister(uint64_t& o_regValue,
            TARGETING::Target* i_pProc
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

    /**
     *  @brief  Clear specified bits in the processor security switch register
     *
     *  @par Detailed Description:
     *      Clears the specified bits in the processor security switch register.
     *
     *  @param[in] i_bits Vector of ProcSecurity (bit) enums
     *  @param[in] i_pTarget Processor target to write.  Must be either
     *      the master processor target sentinel or valid processor target.
     *      Must not be NULL.
     *
     *  @return errHndl_t Error log handle indicating success or failure
     *  @retval nullptr  Cleared specified security switch register bits
     *      successfully
     *  @retval !nullptr Error log providing failure details
     */
    errlHndl_t clearSecuritySwitchBits(
        const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
              TARGETING::Target*                     i_pTarget =
              TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

    /**
     *  @brief  Set specified bits in the processor security switch register
     *
     *  @par Detailed Description:
     *      Sets the specified bits in the processor security switch register.
     *
     *  @param[in] i_bits Vector of ProcSecurity (bit) enums
     *  @param[in] i_pTarget Processor target to write.  Must be either
     *      the master processor target sentinel or valid processor target.
     *      Must not be NULL.
     *
     *  @return errHndl_t Error log handle indicating success or failure
     *  @retval nullptr  Set specified security switch register bits
     *      successfully
     *  @retval !nullptr Error log providing failure details
     */
    errlHndl_t setSecuritySwitchBits(
        const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
              TARGETING::Target*                     i_pTarget =
              TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

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
     *  @param[in] i_pProc The target processor to obtain the jumper
     *      state from. Must not be null. Optional parameter that
     *      defaults to master processor.
     *
     *  @return errlHndl_t indicating whether the query was successful.
     *  @retval null if successful otherwise pointer to error log.
     */
    errlHndl_t getJumperState(SecureJumperState& o_state,
                TARGETING::Target* i_pProc
                    = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

    /* Defition in securerommgr.H */
    sbFuncVer_t getSecRomFuncVersion(const sbFuncType_t i_funcType);

    /* Defition in securerommgr.H */
    uint64_t getSecRomFuncOffset(const sbFuncType_t i_funcType);

    /**
     * @brief Verify Signed Container
     *
     * @param[in] i_container  Void pointer to effective address of container
     * @param[in] i_ids  Vector of IDs (PNOR or Lid Id(s)) associated with
     *                   the blob that is being verified.
     *                   [default = empty vector]
     * @param[in] i_hwKeyHash  Custom hw keys' hash to test against
     *                         [default = nullptr, use current hw hash key]
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyContainer(void * i_container,
                               const RomVerifyIds& i_ids = RomVerifyIds(),
                               const SHA512_t* i_hwKeyHash = nullptr);

    /**
     * @brief Verify component ID in a container header against a reference
     *     component ID. Up to 8 ASCII characters, not including NULL, will be
     *     compared (thus, it is critical that all components are unique with
     *     respect to the first 8 bytes).
     *
     * @param[in] i_containerHeader Verified container's header
     * @param[in] i_pComponentString Reference component ID string; must not be
     *     nullptr or function will assert.
     *
     * @return errlHndl_t Error log handle
     * @retval nullptr Component ID verification succeeded
     * @retval !nullptr Error; component ID verification failed
     */
    errlHndl_t verifyComponentId(
        const ContainerHeader& i_containerHeader,
        const char*            i_pComponentId);

    /**
     * @brief Hash Signed Blob
     *
     * @param[in]  i_blob    Void pointer to effective address of blob
     * @param[in]  i_size    Size of blob in bytes
     * @param[out] o_hash    SHA512 hash
     *
     * @return N/A
     */
    void hashBlob(const void * i_blob, size_t i_size, SHA512_t o_buf);

    /**
     * @brief Retrieve the internal hardware keys' hash used to validate
     *     containers
     * @param[out] o_hash  Reference to the SHA512_t array to copy the
     *                     hash to.
     */
     void getHwKeyHash(SHA512_t o_hash);

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
      * @return N/A
      */
    void hashConcatBlobs(const blobPair_t &i_blobs, SHA512_t o_buf);

    /**
     * @brief Common secureboot handler for secureboot failures.
     *        Properly handles callouts etc.
     * @param[in/out] io_err Reference to error log handle.  Caller's handle
     *     will be nullified.  Handle must not be NULL, or function asserts.
     * @param[in] i_waitForShutdown Whether to wait for system to shutdown (and
     *     never return from this call) or not (and return from this call).
     *     In general, code should wait for shutdown unless early in boot before
     *     basic services are up, or in a resource provider path.
     * @param[in] i_calledByRP Indicates that this function is being called from
     *     within a resource provider message handler, which lets the
     *     implementation know that it needs to take precautionary measures to
     *     avoid deadlock scenarios. If called by a resource provider pass true.
     *     If not, false.
     */
    void handleSecurebootFailure(errlHndl_t &io_err,
                                 bool i_waitForShutdown = true,
                                 bool i_calledByRP = false);

    /**
     *  @brief Adds the values of the Security Registers of the processors in
     *         the system to an existing error log
     *
     *  @param[in/out] io_err  Error Log that the values of the security
     *                         registers will be added to. Must not be nullptr.
     *                         NOTE:  The state of the system/processors
     *                         (ie, SCOM vs FSI) determines which registers can
     *                         be included.
     *  @param[in] i_calledByRP See the handleSecurebootFailure function's
     *                         "called by resource provider" option.
     *  @return N/A
     */
    void addSecurityRegistersToErrlog(errlHndl_t & io_err,
                                      bool i_calledByRP = false);

    /**
     * @brief Common handler for adding all relevant secureboot information to
     *        the user details section of an error log
     * @param[in/out] io_err  Error Log to add secure info to.
     *                        Must not be nullptr.
     * @param[in] i_calledByRP See the handleSecurebootFailure function's
     *                        "called by resource provider" option.
     */
    void addSecureUserDetailsToErrlog(errlHndl_t & io_err,
                                      bool i_calledByRP = false);

    /*
     *  @brief Determines if Attribute Overrides are Allowed
     *         If Secureboot is enabled, check allowAttrOverrides setting;
     *         If Secureboot is not enabled, always allow Attribute Overrides
     *
     *  @return bool   TRUE if Attribute Overrides Are Allowed; FALSE otherwise
     */
    bool allowAttrOverrides();

   /*
    * @brief Determines if SBE security backdoor bit is set
    * @return bool TRUE if SBE security backdoor is enabled; FALSE otherwise
    */
    bool getSbeSecurityBackdoor();

    /*
     *  @brief Gets the current SBE security mode value from the secureboot
     *         subsystem
     *
     *  @return uint8_t returns 0 if SBE should check for security disable
     *                  requests, 1 if not
     */
    uint8_t getSbeSecurityMode();

    /*
     *  @brief Sets the current SBE security mode value in the secureboot
     *         subsystem
     *
     *  @param[in] uint8_t The value to set the security mode to. Will accept a
     *                     a value of 0 if SBE should check for security disable
     *                     requests and 1 if not. All other values are not
     *                     allowed and will be rejected via an assert.
     *
     *  @return errlHndl_t Error log handle; nullptr if success, pointer to
     *      valid error log otherwise.
     */
    errlHndl_t setSbeSecurityMode(uint8_t i_sbeSecurityMode);

}

#endif
