/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/trustedbootif.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <spi/tpmddif.H>
#include <errl/errlentry.H>
#include <list>
#include <pnor/pnorif.H>
#include <secureboot/containerheader.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

namespace TRUSTEDBOOT
{
    // Const string to append to PCR extension messages
    extern const char* const FW_KEY_HASH_EXT;

    struct _TpmLogMgr;

    // Structure that contains the TPM quote data and the size thereof
    struct _QuoteDataOut
    {
        uint32_t size; // the size (bytes) of the data pointer
        uint8_t* data; // the actual quote data
        _QuoteDataOut() : size(0), data(nullptr)
        {
        }
    } PACKED;
    typedef struct _QuoteDataOut QuoteDataOut;

    // Hostboot code just maps the TpmTarget type, which shared APIs use, as a
    // targeting target
    typedef TARGETING::Target TpmTarget;

    enum
    {
        // The size of AK certificate from the TPM, in bytes
        TPM_NV_DATA_SIZE          = 0x1F4,
        // The size of the master nonce, in bytes
        TPM_NONCE_SIZE_BYTES      = 0x20,
    };

    // The structure that defines the size of the TPM AK certificate
    // (in bytes)
    typedef uint8_t AKCertificate_t[TPM_NV_DATA_SIZE];

    // The structure that defines the size of the master node nonce
    // (in bytes)
    typedef uint8_t MasterTpmNonce_t[TPM_NONCE_SIZE_BYTES];

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
        PCR_0              = 0,
        PCR_1              = 1,
        PCR_2              = 2,
        PCR_3              = 3,
        PCR_4              = 4,
        PCR_5              = 5,
        PCR_6              = 6,
        PCR_7              = 7,
        FW_USED_PCR_COUNT  = 8,
        PCR_DEBUG          = 16,
        /* DRTM range; not supported by Hostboot
        PCR_DRTM_17        = 17,
        PCR_DRTM_18        = 18,
        PCR_DRTM_19        = 19,
        PCR_DRTM_20        = 20,
        PCR_DRTM_21        = 21,
        PCR_DRTM_22        = 22,
        */
        PLATFORM_PCR       = 24, ///< The number of PCR required by the platform spec
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

    // The structure to hold the Authentication Key certificate and its size
    struct _TPM2B_MAX_NV_BUFFER
    {
        uint16_t size; //size of the buffer
        AKCertificate_t buffer;
    } PACKED;
    typedef struct _TPM2B_MAX_NV_BUFFER TPM2B_MAX_NV_BUFFER;

    /// TPM Algorithm defines
    typedef enum
    {
        TPM_ALG_SHA1      = 0x0004,   ///< SHA1 Id
        TPM_ALG_SHA256    = 0x000B,   ///< SHA256 Id
        TPM_ALG_INVALID_ID          ///< Used for error checking
    } TPM_Alg_Id;


    // Enum defines and struct used to group SBE Measurement Registers

    // Details of SBE measurement registers results - from P10SecurityInitFlow document
    /*
     * - 0-1   (x10010-x10011) : PCR 6   : Security state boolean : 0x(00,01)|MinSecFWVer(xx)|0...
     * - 2-3   (x10012-x10013) : PCR 0   : Security state :
     *                                     (SSR)|IsPrimary(0,1)|MSMLock(0,1)|MinSecFWVer(xx)|0..
     * - 4-7   (x10014-x10017) : PCR 0/6 : Hash of SBE secureboot validation code
     * - 8-11  (x10018-x1001B) : PCR 0   : Hash of boot SEEProm L1/L2 boot loaders and boot
     *                                     SEEProm base
     * - 12-15 (x1001C-x1001F) : PCR 0   : Hash of HBBL
     */
    typedef enum
    {
        TPM_SBE_MEASUREMENT_REGS_0_1_SIZE   = 0x10,
        TPM_SBE_MEASUREMENT_REGS_2_3_SIZE   = 0x10,
        TPM_SBE_MEASUREMENT_REGS_4_7_SIZE   = 0x20,
        TPM_SBE_MEASUREMENT_REGS_8_11_SIZE  = 0x20,
        TPM_SBE_MEASUREMENT_REGS_12_15_SIZE = 0x20,
    } TPM_sbe_measurement_reg_defines;

    struct TPM_sbe_measurements_regs_grouped
    {
        uint8_t sbe_measurement_regs_0_1[TPM_SBE_MEASUREMENT_REGS_0_1_SIZE]     = {0};
        uint8_t sbe_measurement_regs_2_3[TPM_SBE_MEASUREMENT_REGS_2_3_SIZE]     = {0};
        uint8_t sbe_measurement_regs_4_7[TPM_SBE_MEASUREMENT_REGS_4_7_SIZE]     = {0};
        uint8_t sbe_measurement_regs_8_11[TPM_SBE_MEASUREMENT_REGS_8_11_SIZE]   = {0};
        uint8_t sbe_measurement_regs_12_15[TPM_SBE_MEASUREMENT_REGS_12_15_SIZE] = {0};
    } PACKED;

    /**
     * @brief Initialize trusted boot/TPM components for the primary TPM
     *
     * @param[in] io_pArgs istep args
     *
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    void* host_update_primary_tpm( void *io_pArgs );

    /**
     * @brief Extend a measurement into the TPM(s) and log atomically
     * @param[in] i_pcr PCR to write to
     * @param[in] i_eventType Event type to log
     * @param[in] i_digest Digest value to write to PCR
     * @param[in] i_digestSize Byte size of i_digest data
     * @param[in] i_logMsg Log message in binary form
     * @param[in] i_logMsgSize The size of the log message in bytes
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
                         const uint8_t* i_logMsg,
                         size_t i_logMsgSize,
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
     *  @param[out] o_spiControllerOffset SPI Controller Offset
     *
     *  @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t getTpmLogDevtreeInfo(
        const TpmTarget* i_pTpm,
              uint64_t&  io_logAddr,
              size_t&    o_allocationSize,
              uint64_t&  o_xscomAddr,
              uint32_t&  o_spiControllerOffset);

    /**
     *  @brief Store devtree node information for the TPM
     *
     *  @param[in] i_pTpm TPM targeting target handle.  Function will assert if
     *      value is nullptr or is not of TPM type.
     *
     *  @param[in] i_xscomAddr Chip Xscom Address
     *
     *  @param[in] i_spiControllerOffset SPI Controller Offset
     */
    void setTpmDevtreeInfo(
        const TpmTarget* i_pTpm,
              uint64_t   i_xscomAddr,
              uint32_t   i_spiControllerOffset);

    #ifdef CONFIG_TPMDD
    /**
     *  @brief Generate random numbers via TPM hardware.
     *
     *  @param[in] i_pTpm Pointer to TPM target. In order to succeed, it cannot
     *            be null and must be a TPM target pointer. The TPM target must
     *            be functional. All of these conditions must be met or an error
     *            log will result.
     *
     *  @param[in] i_randNumSize The desired size (bytes) of the random number
     *             to be requested from the TPM
     *
     *  @param[out] o_randNum A pointer to the array to be filled with random
     *              bits
     *
     *  @return errlHndl_t nullptr on success or an error log pointer on failure
     */
    errlHndl_t GetRandom(const TpmTarget* i_pTpm,
                         size_t i_randNumSize,
                         uint8_t* o_randNum);
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
    errlHndl_t poisonTpm(TpmTarget* i_pTpm);

    /**
     * @brief Poison all functional TPMs on the node. Calls poisonTpm for
     *        each functional TPM.
     *
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t poisonAllTpms();

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

    /**
     * @brief Send the synchronous flush queue message to the TPM daemon
     *
     * @return errlHndl_t nullptr if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t flushTpmQueue();

    /**
     * @brief Send the command to the given TPM to create node attestation
     *        key pair
     *
     * @param[in] i_target the pointer to the TPM target to send the command to
     * @return nullptr if success; non-nullptr on error
     */
    errlHndl_t createAttestationKeys(TpmTarget* i_target);

    /**
     * @brief Send the command to the given TPM to retrieve the AK certificate
     *        from its NVRAM
     *
     * @param[in] i_target the pointer to the TPM target to send the command to
     * @param[out] o_data the buffer to store the contents of AK certificate
     * @return nullptr if success; non-nullptr on error
     */
    errlHndl_t readAKCertificate(TpmTarget* i_target,
                                 TPM2B_MAX_NV_BUFFER* o_data);

    /**
     * @brief Send the command to the given TPM to generate the quote
     *
     * @param[in] i_target the pointer to the TPM target to send the command to
     * @param[in] i_masterNonce the 32-byte nonce from the master node
     * @param[out] o_data a pointer to the  data structure containing the size
     *             of the quote data from the TPM and the actual data
     * @return nullptr if success; non-nullptr on error
     */
    errlHndl_t generateQuote(TpmTarget* i_target,
                             const MasterTpmNonce_t* i_masterNonce,
                             QuoteDataOut* o_data);

    /**
     * @brief Send the command to the given TPM to remove all context associated
     *        with created objects
     *
     * @param[in] i_target the pointer to the TPM target to send the command to
     * @return nullptr if success; non-nullptr on error
     */
    errlHndl_t flushContext(TpmTarget* i_target);

    /**
     * @brief Send the command to the given TPM to read the contents of the
     *        given bank of the given PCR
     * @param[in] i_target the pointer to the TPM target; must not be nullptr
     * @param[in] i_pcr the PCR to read
     * @param[in] i_algId the PCR bank to read
     * @param[in] i_digestSize the size of the digest contained in the PCR
     * @param[out] o_digest the data contained in the requested PCR
     *
     * @return nullptr if success; non-nullptr on error
     */
    errlHndl_t pcrRead(TpmTarget* i_target,
                       TPM_Pcr i_pcr,
                       TPM_Alg_Id i_algId,
                       size_t i_digestSize,
                       uint8_t* o_digest);

    /**
     * @brief Send the synchronous command to the given TPM to expand its log.
     *        Expanding the log means increasing its size to accomodate larger
     *        events in multinode communication protocol.
     * @param[in] i_target the pointer to the TPM target; must not be nullptr
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t expandTpmLog(TpmTarget* i_target);



    /**
     * @brief Reads the SBE Measurement Registers from a Processor and then
     *        groups them together in certain ways as defined by the
     *        TPM_sbe_measurements_regs_grouped struct.
     * @param[in] i_proc_target - the pointer to the Processor target:
     *                            -- must not be nullptr or will fail
     *                            -- must be of TYPE_PROC or will fail
     *                            -- must be XSCOMMABLE or will fail
     * @param[out] o_regs - structure filled in from SBE Measurement registers read
     *                      from a processor.
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t groupSbeMeasurementRegs(TARGETING::Target*    i_proc_target,
                                       TPM_sbe_measurements_regs_grouped & o_regs);

    /**
     * @brief Adds the SBE Measurement Registers from a Processor to the TPM Log.
     *        Optionally can extend the registers to the TPM, as well.
     *        The registers are logged and optionally extended grouped together as
     *        defined in TPM_sbe_measurements_regs_grouped struct.
     * @param[in] i_tpm_target the pointer to the TPM target; must not be nullptr
     * @param[in] i_proc_target the pointer to the Processor target; must not be nullptr
     * @param[in] i_regs - structure containing grouped SBE Measurement registers
     *                     read from a processor.
     *                     This gets ignored if i_extend == false;
     * @param[in] i_extend If true, extend values to PCR 0; false, do not extend values to PCR 0;
     *                     Defaults to false
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t logSbeMeasurementRegs(TpmTarget* i_tpm_target,
                                     TARGETING::Target*    i_proc_target,
                                     TPM_sbe_measurements_regs_grouped i_regs,
                                     bool i_extend = false);

    /**
     * @brief Synchronizes the TPM Log to what has already been extended by
     *         the SBE and Hostboot Bootloader code
     *
     * @warning No-op if trusted boot compiled out
     *
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t synchronizeTpmLog();


} // end TRUSTEDBOOT namespace


#endif // __TRUSTEDBOOTIF_H
