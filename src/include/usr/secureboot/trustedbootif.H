/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/trustedbootif.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
 * @file trustedbootif.H
 *
 * @brief Trustedboot interfaces
 *
 */
#ifndef __TRUSTEDBOOTIF_H
#define __TRUSTEDBOOTIF_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <targeting/common/targetservice.H>
#include <i2c/tpmddif.H>
#include <errl/errlentry.H>
#include <list>
#include <pnor/pnorif.H>
#include <secureboot/containerheader.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <config.h>

namespace TRUSTEDBOOT
{
    // Const string to append to PCR extension messages
    extern const char* const FW_KEY_HASH_EXT;

    struct _TpmLogMgr;

    // Hostboot code just maps the TpmTarget type, which shared APIs use, as a
    // targeting target
    typedef TARGETING::Target TpmTarget;

    /**
     *  @brief Enum used for the getTPMs API to specify scope of TPMs to return
     */
    enum class TPM_FILTER : uint8_t
    {
        ALL_FUNCTIONAL,     ///< Return only functional (and present) TPMs
        ALL_IN_BLUEPRINT,   ///< Return any TPM in the blueprint
    };

    /// TPM PCR designations
    typedef enum
    {
        PCR_0     = 0,
        PCR_1     = 1,
        PCR_2     = 2,
        PCR_3     = 3,
        PCR_4     = 4,
        PCR_5     = 5,
        PCR_6     = 6,
        PCR_7     = 7,
        PCR_DEBUG = 16,
        PCR_DRTM_17 = 17,
        PCR_DRTM_18 = 18,
        PCR_DRTM_19 = 19,
        PCR_DRTM_20 = 20,
        PCR_DRTM_21 = 21,
        PCR_DRTM_22 = 22,
        PLATFORM_PCR = 24, ///< The number of PCR required by the platform spec
        IMPLEMENTATION_PCR = 24, ///< The number of PCRs implemented by TPM
    } TPM_Pcr;

    /// TCG PC Client Platform Firmware Profile Spec Family "2.0" v00.50
    typedef enum : uint8_t
    {
        EV_PREBOOT_CERT            = 0x00,
        EV_POST_CODE               = 0x01,
        EV_UNUSED                  = 0x02,
        EV_NO_ACTION               = 0x03,
        EV_SEPARATOR               = 0x04,
        EV_ACTION                  = 0x05,
        EV_EVENT_TAG               = 0x06,
        EV_S_CRTM_CONTENTS         = 0x07,
        EV_S_CRTM_VERSION          = 0x08,
        EV_CPU_MICROCODE           = 0x09,
        EV_PLATFORM_CONFIG_FLAGS   = 0x0A,
        EV_TABLE_OF_DEVICES        = 0x0B,
        EV_COMPACT_HASH            = 0x0C,
        EV_IPL                     = 0x0D,   ///< Deprecated
        EV_IPL_PARTITION_DATA      = 0x0E,   ///< Deprecated
        EV_NONHOST_CODE            = 0x0F,
        EV_NONHOST_CONFIG          = 0x10,
        EV_NONHOST_INFO            = 0x11,
        EV_OMIT_BOOT_DEVICE_EVENTS = 0x12,
        EV_INVALID                 ///< Used for error checking
    } EventTypes;

    // Indicate the points in the code where the backup TPM test failed.
    // TODO RTC:191761
    // remove once the Cxx test is created.
    typedef enum : uint8_t
    {
        TPM_TEST_NO_ERROR             = 0x00,
        TPM_TEST_LOGS_NOT_INITIALIZED = 0x01,
        TPM_TEST_LOG_SIZE_MISMATCH    = 0x02,
        TPM_TEST_UNMARSHAL_ERROR      = 0x03,
        TPM_TEST_LOG_MISMATCH         = 0x04,
        TPM_TEST_DIGEST_MISMATCH      = 0x05,
    } BackupTpmTestFailures;


    /**
     * @brief Initialize trusted boot/TPM components for the master TPM
     *
     * @param[in] io_pArgs istep args
     *
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    void* host_update_master_tpm( void *io_pArgs );

    /**
     * @brief Extend a measurement into the TPM(s) and log atomically
     * @param[in] i_pcr PCR to write to
     * @param[in] i_eventType Event type to log
     * @param[in] i_digest Digest value to write to PCR
     * @param[in] i_digestSize Byte size of i_digest data
     * @param[in] i_logMsg Null terminated log message, truncated at 128 chars
     * @param[in] i_sendAsync Perform extension asynchronously, default true
     * @param[in] i_pTpm A specific TPM to singly extend a measurement into,
                  default is nullptr, which indicates all of the TPMs will be
                  extended.
     * @param[in] i_mirrorToLog After extending the measurement, mirror to log.
     *            default is true. Typically, false is used to poison the TPM.
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     * Digest will be right padded with zeros or truncated to match TPM digest
     *  size being used
     */
    errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                         EventTypes i_eventType,
                         const uint8_t* i_digest,
                         size_t  i_digestSize,
                         const char* i_logMsg,
                         bool i_sendAsync = true,
                         const TpmTarget* i_pTpm = nullptr,
                         bool i_mirrorToLog = true);

    /**
     * @brief Extend a separator into the TPMs and log atomically
     * @param[in] i_sendAsync Perform extension asynchronously, default true
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t pcrExtendSeparator(bool i_sendAsync = true);

    /**
     * @brief Attempt to initialize the backup TPM by sending a synchronous
     *        MSG_TYPE_INIT_BACKUP_TPM to TPM daemon. Any error will be
     *        committed internally.
     */
    void initBackupTpm();

    /**
     * @brief A testcase to make sure the backup TPM's logs and PCR registers
     *        look exactly as the primary's.
     * @return errlHndl_t NULL if test ran successfully; otherwise a pointer to
     *         the error log.
     */
    errlHndl_t testCmpPrimaryAndBackupTpm(); //TODO RTC:191761
                                             // make this a Cxx standalone
                                             // test when the simics model has
                                             // support for both boot chips.

    /**
     *  @brief Returns list of TPMs in the system meeting the specified critera
     *
     *  @param[out] o_tpmList Vector of TPM targeting target handles meeting the
     *      criteria specified by the i_filter parameter (functional targets or
     *      blueprint targets).  By default, returns functional targets.
     *
     *  @param[in] i_filter Filter specifying scope of TPMs to return.
     *
     *  @warning Silently clears caller supplied vector before populating it
     */
    void getTPMs(
        TARGETING::TargetHandleList& o_tpmList,
        TPM_FILTER i_filter = TPM_FILTER::ALL_FUNCTIONAL);

    /**
     *  @brief Retrieve TPM log device tree information
     *
     *  @param[in] i_pTpm TPM targeting target handle.  Function will assert if
     *      value is nullptr or is not of TPM type.
     *
     *  @param[in/out] io_logAddr TPM Log Address
     *
     *  @param[out] o_allocationSize Total memory allocated for log
     *
     *  @param[out] o_xscomAddr Chip Xscom Address
     *
     *  @param[out] o_i2cMasterOffset I2c Master Offset
     *
     *  @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t getTpmLogDevtreeInfo(
        const TpmTarget* i_pTpm,
              uint64_t&  io_logAddr,
              size_t&    o_allocationSize,
              uint64_t&  o_xscomAddr,
              uint32_t&  o_i2cMasterOffset);

    /**
     *  @brief Store devtree node information for the TPM
     *
     *  @param[in] i_pTpm TPM targeting target handle.  Function will assert if
     *      value is nullptr or is not of TPM type.
     *
     *  @param[in] i_xscomAddr Chip Xscom Address
     *
     *  @param[in] i_i2cMasterOffset i2c Master Offset
     */
    void setTpmDevtreeInfo(
        const TpmTarget* i_pTpm,
              uint64_t   i_xscomAddr,
              uint32_t   i_i2cMasterOffset);

    #ifdef CONFIG_TPMDD
    /**
     *  @brief Generate random numbers via TPM hardware.
     *
     *  @parm[in] i_pTpm Pointer to TPM target. In order to succeed, it cannot
     *            be null and must be a TPM target pointer. The TPM target must
     *            be functional. All of these conditions must be met or an error
     *            log will result.
     *
     *  @parm[out] o_randNum A uint64_t reference to be filled with random bits.
     *
     *  @return errlHndl_t nullptr on success or an error log pointer on failure
     */
    errlHndl_t GetRandom(const TpmTarget* i_pTpm, uint64_t& o_randNum);
    #endif

    /**
     *  @brief Poison a TPM. Poisoning a TPM's PCR means extending a random
     *         number measurement to the TPM, but not to the corresponding log
     *         entry. This includes extending random numbers to every bank/PCR
     *         combo in use by the firmware (sha1/sha256 banks of PCR 0-7). The
     *         random number along with the absent log entry makes remote
     *         attestation impossible with that TPM for that boot.
     *
     *  @parm[in] i_pTpm Pointer to the TPM target to be poisoned. Must be a TPM
     *                   and must not be nullptr
     *
     *  @return errlHndl_t nullptr if successful or error log otherwise. Failure
     *                     to poison a TPM will result in deconfiguring the TPM.
     */
    errlHndl_t poisonTpm(const TpmTarget* i_pTpm);

    /**
     *  @brief Helper function for validating TPM handles. Returns an error log
     *         if the supplied TPM is null, not a TPM target, or not functional.
     *
     *  @parm[in] i_pTpm Pointer to the TPM target to be checked.
     *
     *  @return errlHndl_t nullptr if valid or error log otherwise.
     */
    errlHndl_t validateTpmHandle(const TpmTarget* i_pTpm);

    /**
     * @brief Checks whether the node has a present and functioning primary TPM.
     * @retval true if a present and functional primary TPM is available;
     *         false otherwise
     */
    bool functionalPrimaryTpmExists();

    /**
     * @brief Wrapper around pcrExtend for measuring PNOR sections
     * @param[in] i_conHdr  Reference to ContainerHeader of a section
     * @param[in] i_vaddr   Pointer to a virtual address for the protected
     *                      portion of the PNOR section.
     *                      [Not used if SECUREBOOT::enabled()]
     * @param[in] i_sec     Section ID of PNOR section
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t extendPnorSectionHash(const SECUREBOOT::ContainerHeader& i_conHdr,
                                     const void* i_vaddr,
                                     const PNOR::SectionId i_sec);

    /**
     *
     *  @brief Extends the Hostboot base image to the TPM
     *
     *  @warning No-op if trusted boot compiled out
     *
     *  @return errHndl_t Error log pointer
     *  @retval NULL  Successfully extended Hostboot base image to the TPM
     *  @retval !NULL Failed to extend Hostboot base image to TPM
     *                                     */
    errlHndl_t extendBaseImage();

    /**
     *  @brief Return the primary TPM, if any
     *
     *  @param[out] o_pPrimaryTpm TPM targeting target handle of the primary
     *      TPM, or nullptr if none.
     */
    void getPrimaryTpm(TARGETING::Target*& o_pPrimaryTpm);

    /**
     *  @brief Return the backup TPM, if any
     *
     *  @param[out] o_pBackupTpm TPM targeting target handle of the backup
     *      TPM, or nullptr if none.
     */
    void getBackupTpm(TARGETING::Target*& o_pBackupTpm);

    /**
     *  @brief Returns whether system requires a functional TPM to boot or not
     *
     *  @return bool Whether system requires a functional TPM to boot or not.
     *  @retval true Functional TPM is required to boot
     *  @retval false Functional TPM is not required to boot
     */
    bool isTpmRequired();

} // end TRUSTEDBOOT namespace


#endif // __TRUSTEDBOOTIF_H
