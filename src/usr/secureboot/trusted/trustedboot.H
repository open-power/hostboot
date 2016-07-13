/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <i2c/tpmddif.H>
#include <trace/interface.H>
#include <sys/msg.h>
#include "trustedTypes.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACUBIN(args...)  TRACFBIN(args)
#define TRACUBIN(args...)

#define TB_SUCCESS NULL

namespace TRUSTEDBOOT
{

/// Common static values
enum
{
    MAX_SYSTEM_TPMS = 2,
    TPM_MASTER_INDEX = 0,     ///< Index into tpm array for master chip
    TPM_BACKUP_INDEX = 1,     ///< Index for backup TPM
};

/// Class object to store system TPM information
class SystemTpms
{
public:
    SystemTpms():
        msgQ(msg_q_create()),
        failedTpmsPosted(false)
    { }

    // NOTE: No destructor implemented to destroy msgQ as required for shutdown

    msg_q_t   msgQ;        ///< TrustedBootRp message queue
    bool failedTpmsPosted; ///< Have we already posted
    TpmTarget tpm[MAX_SYSTEM_TPMS];
};


/**
 * @brief Initialize the targeted TPM
 * @param[in/out] io_target Current TPM target structure
*/
void tpmInitialize(TRUSTEDBOOT::TpmTarget & io_target);

/**
 * @brief Verify a functional TPM still exists in the system
 * @return errlHndl_t NULL if TPM available, otherwise a pointer to the
 *       error log.
*/
errlHndl_t tpmVerifyFunctionalTpmExists();

/**
 * @brief Replay the entries that exist in the log into the TPM as needed
 * @param[in/out] io_target Current TPM target structure
 */
void tpmReplayLog(TRUSTEDBOOT::TpmTarget & io_target);

/**
 * @brief Send config entries to tpm
 *
 * @param[in/out] io_target Current TPM target structure
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t tpmLogConfigEntries(TRUSTEDBOOT::TpmTarget & io_target);


/**
 * @brief Verify a functional TPM still exists in the system
 * @return errlHndl_t NULL if TPM available, otherwise a pointer to the
 *       error log.
*/
errlHndl_t tpmVerifyFunctionalTpmExists();

/**
 * @brief Extend a measurement into a TPM and log
 * @param[in/out] io_target Current TPM target structure
 * @param[in] i_pcr PCR to write to
 * @param[in] i_algId Algorithm to extend
 * @param[in] i_digest Digest value to write to PCR
 * @param[in] i_digestSize Byte size of i_digest data
 * @param[in] i_logMsg Null terminated log message
 */
void pcrExtendSingleTpm(TpmTarget & io_target,
                        TPM_Pcr i_pcr,
                        TPM_Alg_Id i_algId,
                        const uint8_t* i_digest,
                        size_t  i_digestSize,
                        const char* i_logMsg);


/**
 * @brief Is the TPM_REQUIRED flag set such that the
 *         system should not boot without a functional TPM
 * @retval true TPM is required to boot
 * @retval false TPM is not required, failures should be logged
 */
bool isTpmRequired();

/** Thread start routine for the TPM Daemon
 * @param[in] void*, unused
 */
void* tpmDaemon(void* unused);

} // end TRUSTEDBOOT namespace
#endif
