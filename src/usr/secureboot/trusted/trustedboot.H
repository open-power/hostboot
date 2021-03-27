/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.H $                    */
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
 * @file trustedboot.H
 *
 * @brief Trustedboot TPM interfaces
 *
 */
#ifndef __TRUSTEDBOOT_H
#define __TRUSTEDBOOT_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <secureboot/trustedbootif.H>
#include <spi/tpmddif.H>
#include <trace/interface.H>
#include <sys/msg.h>
#include "trustedTypes.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...) TRACDCOMP(args)
//#define TRACUBIN(args...)  TRACFBIN(args)
#define TRACUBIN(args...)

#define TB_SUCCESS NULL

namespace TRUSTEDBOOT
{

const size_t DEFAULT_BIN_TRACE_SIZE = 128;

/// Common static values
enum TRUSTED_BOOT_LIMITS
{
    MAX_TPMS_PER_NODE = 2,
};

/// Class object to store trusted boot system data
class SystemData
{
public:
    SystemData():
        msgQ(msg_q_create()),
        failedTpmsPosted(false)
    { }

    // NOTE: No destructor implemented to destroy msgQ as required for shutdown

    msg_q_t   msgQ;        ///< TrustedBootRp message queue
    bool failedTpmsPosted; ///< Have we already posted
};


/**
 *  @brief Initialize the targeted TPM
 *
 *  @param[in] i_pTpm TPM targeting target handle indicating TPM to initialize.
 *      Function will assert if value is nullptr or is not of TPM type
 */
void tpmInitialize(TRUSTEDBOOT::TpmTarget* i_pTpm);



/**
 *  @brief Shutdown policy to invoke when system has no usable TPMs
 */
enum class NoTpmShutdownPolicy
{
    BACKGROUND_SHUTDOWN, // Shutdown Hostboot in background
    SYNC_SHUTDOWN,       // Block waiting for Hostboot to shutdown
};

/**
 * @brief Verify a functional primary TPM still exists in the system
 *
 * If no functional primary TPM is found in the system :
 *   If the system is running in secure mode an error log will be committed
 *   and if the TPMRequired attribute is true a system shutdown will be
 *   initiated
 *
 * @param[in] i_noTpmShutdownPolicy Shutdown policy to invoke if a functional
 *     primary TPM is required to boot the system (TPM required policy is
 *     "required") -and- no functional primary TPM is available
 *     (or other critical error occurred)
*/
void tpmVerifyFunctionalPrimaryTpmExists(
    NoTpmShutdownPolicy i_noTpmShutdownPolicy =
        NoTpmShutdownPolicy::SYNC_SHUTDOWN);

/**
 *  @brief Replay (extend) the entries that exist in the log of the primary TPM
 *         into the secondary TPM.
 *
 *  @param[in] i_primaryTpm TPM targeting target handle indicating TPM to
 *             replay the log from. Function will assert if the value is nullptr
 *             or is not of TPM type.
 * @param[in] i_backupTpm TPM targeting target handle indicating TPM to replay
 *            the log to. Function will assert if the value is nullptr or is not
 *            of TPM type.
 *
 */
void tpmReplayLog(TRUSTEDBOOT::TpmTarget* i_primaryTpm,
                  TRUSTEDBOOT::TpmTarget* i_backupTpm);

/**
 *  @brief Send config entries to TPM
 *
 *  @param[in] i_pTpm TPM targeting target handle indicating TPM to send config
 *      entries to. Function will assert if value is nullptr or is not of TPM
 *      type.
 *
 *  @return errlHndl_t nullptr if successful, otherwise pointer to error log
 */
errlHndl_t tpmLogConfigEntries(TRUSTEDBOOT::TpmTarget* i_pTpm);


/**
 *  @brief Extend a measurement into a TPM and log
 *
 *  @param[in] i_pTpm TPM targeting target handle referring to TPM to log a
 *      measurement to.  Function will assert if value is nullptr or is not of
 *      TPM type.
 *  @param[in] i_pcr PCR to write to
 *  @param[in] i_algId Algorithm to extend
 *  @param[in] i_digest Digest value to write to PCR
 *  @param[in] i_digestSize Byte size of i_digest data
 *  @param[in] i_logMsg Null terminated log message
 *  @param[in] i_extendToTpm If true, extend the digest to the designated PCR on the TPM;
 *             else, do not extend. Default is true. Depends on valid i_digest and
 *             i_digestSize.
 *  @param[in] i_extendToSwLog If true, add the log message to the TPM's SW log; if false,
 *             do not add to TPM's SW log. Default is true. False is used to poison the tpm.
 *             Depends on valid i_logMsg.
 */
void pcrExtendSingleTpm(TpmTarget* i_pTpm,
                        TPM_Pcr i_pcr,
                        const EventTypes i_eventType,
                        TPM_Alg_Id i_algId,
                        const uint8_t* i_digest,
                        size_t  i_digestSize,
                        const uint8_t* i_logMsg,
                        size_t i_logMsgSize,
                        bool i_extendtoTpm=true,
                        bool i_extendToSwLog=true);

/**
 *  @brief Extend a separator into a TPM and log
 *
 *  @param[in] i_pTpm TPM targeting target handle referring to TPM to log a
 *      extend a separator to.  Function will assert if value is nullptr or is
 *      not of TPM type.
 *  @param[in] i_extendToTpm If true, extend the separator into the TPMs;
 *             else, do not extend. Default is true.
 *  @param[in] i_extendToSwLog If true, add the separator message to the TPM's SW log;
 *             if false, do not add to the TPM's SW log. Default is true.
 */
void pcrExtendSeparator(TpmTarget* i_pTpm,
                        bool const i_extendToTpm = true,
                        bool const i_extendToSwLog = true);

/** Thread start routine for the TPM Daemon
 * @param[in] void*, unused
 */
void* tpmDaemon(void* unused);

/**
 *  @brief Returns a pointer to the TPM's log manger
 *
 *  @param[in] i_pTpm TPM targeting target handle.  Function asserts if value is
 *      nullptr or does not refer to a TPM targeting target.
 *
 *  @return _TpmLogMgr* Pointer to TPM's log manager, or nullptr if log manager
 *      is not configured.
 */
_TpmLogMgr* getTpmLogMgr(
    const TpmTarget* i_pTpm);

/**
 *  @brief Sets a TPM's log manger
 *
 *  @param[in] i_pTpm TPM targeting target handle.  Function asserts if value is
 *      nullptr or does not refer to a TPM targeting target.
 *
 *  @param[in] i_pTpmLogMg Pointer to TPM log manager, or nullptr to remove log
 *      manager.
 */
void setTpmLogMgr(
          TpmTarget*  i_pTpm,
    const _TpmLogMgr* i_pTpmLogMgr);

/**
 *  @brief Returns TPM with matching role
 *
 *  @param[in] i_tpmRole Role of the TPM to search for
 *
 *  @param[out] o_pTpm TPM targeting target handle of the TPM with the matching
 *      role, or nullptr if none found
 */
void getTpmWithRoleOf(
    TARGETING::TPM_ROLE i_tpmRole,
    TARGETING::Target*& o_pTpm);

/**
 *  @brief Returns value of TPM Sensor if it is available
 *         All error handing is contained in the function and the output value
 *         is only valid if the function returns TRUE
 *
 *  @param[out] o_isTpmRequired Value returned from TPM Required sensor:
 *              TRUE if TPM is required; FALSE if TPM is NOT required
 *              NOTE: this parameter is only valid if this function returns TRUE
 *
 *  @return bool  Returns TRUE if sensor was available and found without error;
 *                otherwise returns FALSE
 */
bool getTpmRequiredSensorValue(
    bool& o_isTpmRequired);

/**
 * @brief Adds the SBE Measurement Registers from a Processor to the TPM's SW Log.
 *        Optionally can extend the registers to the TPM, as well.
 *        The registers are logged and optionally extended grouped together as
 *        defined in TPM_sbe_measurements_regs_grouped struct.
 * @param[in] i_tpm_target the pointer to the TPM target; must not be nullptr
 * @param[in] i_proc_target the pointer to the Processor target; must not be nullptr
 * @param[in] i_regs - structure containing grouped SBE Measurement registers
 *                     read from a processor.
 * @param[in] i_extendToTpm If true, extend values to PCRs; false, do not extend values to PCRs.
 * @return errlHndl_t nullptr if successful, otherwise pointer to error log
 */
errlHndl_t logMeasurementRegs(TpmTarget* i_tpm_target,
                              TARGETING::Target*    i_proc_target,
                              TPM_sbe_measurements_regs_grouped i_regs,
                              bool i_extendToTpm);

/**
 * @brief Synchronizes the Primary TPM Logs to what has already been extended by
 *         the SBE and Hostboot Bootloader code
 *
 * @warning No-op if trusted boot compiled out
 *
 * @return nullptr on success; non-nullptr on error
 */
void synchronizePrimaryTpmLogs();

/**
* @brief Extend a measurement into the primary TPM of all other nodes.  Once
*     the cross-node SMP is established, any measurement logged to a node's
*     primary TPM must be replicated to the primary TPM of all other nodes.
*
* @param[in] i_pcr PCR to write to
* @param[in] i_eventType Event type to log
* @param[in] i_digest Digest value to write to PCR
* @param[in] i_digestSize The size of the digest in bytes
* @param[in] i_logMsg Log message in binary form
* @param[in] i_logMsgSize The size of the log message in bytes
*
* @return errlHndl_t nullptr if successful, otherwise a pointer to a
*      valid error log.
*/
errlHndl_t extendMeasurementToOtherNodes(
    const TPM_Pcr    i_pcr,
    const EventTypes i_eventType,
    const uint8_t*   i_digest,
    const size_t     i_digestSize,
    const uint8_t*   i_logMsg,
    const size_t     i_logMsgSize);

} // end TRUSTEDBOOT namespace
#endif
