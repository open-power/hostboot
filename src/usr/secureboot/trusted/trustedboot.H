/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 */
void pcrExtendSingleTpm(TpmTarget* i_pTpm,
                        TPM_Pcr i_pcr,
                        const EventTypes i_eventType,
                        TPM_Alg_Id i_algId,
                        const uint8_t* i_digest,
                        size_t  i_digestSize,
                        const uint8_t* i_logMsg,
                        size_t i_logMsgSize);

/**
 *  @brief Extend a separator into a TPM and log
 *
 *  @param[in] i_pTpm TPM targeting target handle referring to TPM to log a
 *      extend a separator to.  Function will assert if value is nullptr or is
 *      not of TPM type.
 */
void pcrExtendSeparator(TpmTarget* i_pTpm);

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
 * @brief Marks the input TPM as UNUSABLE and creates an unrecoverable errorlog
 *        to notify the user of the system that a TPM has been marked UNUSABLE.
 *        The error log is committed internally.
 *
 * @param[in] i_tpm the TPM to mark UNUSABLE
 * @param[in] i_associatedErrl an error log that forced the TPM to be UNUSABLE;
 *            default - nullptr.
 */
void markTpmUnusable(TARGETING::Target* i_tpm,
                     const errlHndl_t i_associatedErrl = nullptr);

} // end TRUSTEDBOOT namespace
#endif
