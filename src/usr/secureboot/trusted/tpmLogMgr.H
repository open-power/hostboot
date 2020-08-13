/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/tpmLogMgr.H $                      */
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
 * @file tpmLogMgr.H
 *
 * @brief Trustedboot TPM Event Log Manager
 *
 */

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

#ifndef __TPMLOGMGR_H
#define __TPMLOGMGR_H
// -----------------------------------------------
// Includes
// -----------------------------------------------

#ifdef __HOSTBOOT_MODULE
#include <sys/sync.h>
#endif
#include "trustedboot.H"
#include "trustedTypes.H"

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

    /// Event log header algorithms
    struct _TCG_EfiSpecIdEventAlgorithmSize
    {
        uint16_t     algorithmId;
        uint16_t     digestSize;
    } PACKED;
    typedef struct _TCG_EfiSpecIdEventAlgorithmSize
                    TCG_EfiSpecIdEventAlgorithmSize;

    /// Event log header event data
    struct _TCG_EfiSpecIdEventStruct
    {
        char         signature[16];
        uint32_t     platformClass;
        uint8_t      specVersionMinor;
        uint8_t      specVersionMajor;
        uint8_t      specErrata;
        uint8_t      uintnSize;
        uint32_t     numberOfAlgorithms;
        TCG_EfiSpecIdEventAlgorithmSize digestSizes[HASH_COUNT];
        uint8_t      vendorInfoSize;
        char         vendorInfo[0];
    } PACKED;
    typedef struct _TCG_EfiSpecIdEventStruct TCG_EfiSpecIdEventStruct;
    uint32_t TCG_EfiSpecIdEventStruct_size(TCG_EfiSpecIdEventStruct* val);

    enum {
        TPMLOG_BUFFER_SIZE   = 7168,    ///< Size of event log buffer for HB
        TPMLOG_DEVTREE_SIZE  = 64*1024, ///< Size to allocate for OPAL
    };

    struct _TpmLogMgr
    {
        uint32_t logSize;        ///< Current byte size of log
        uint32_t logMaxSize;     ///< Space allocated for log entries
        uint8_t* newEventPtr;    ///< Pointer to location to add new event
        uint8_t* eventLogInMem;  ///< Event log allocated from memory
#ifdef __HOSTBOOT_MODULE
        uint64_t inMemlogBaseAddr; ///< Base address of log for dev tree
        uint64_t devtreeXscomAddr; ///< Devtree Xscom Address
        uint32_t devtreeSpiControllerOffset; ///< Devtree SPI Controller Offset
        uint8_t eventLog[TPMLOG_BUFFER_SIZE]; ///< EventLog Buffer
#endif
        mutex_t  logMutex;       ///< Log mutex
    };
    typedef struct _TpmLogMgr TpmLogMgr;

#ifdef __HOSTBOOT_MODULE
    /**
     * @brief Initialize the log manager
     * @param[in/out] io_logMgr Return a pointer to the log manager
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t TpmLogMgr_initialize(TpmLogMgr * io_logMgr);
#endif

    /**
     * @brief Initialize the log manager to use a pre-existing buffer
     * @param[in] i_val TpmLogMgr structure
     * @param[in] i_eventLogPtr Pointer to event log to use
     * @param[in] i_eventLogSize Allocated log buffer size
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t TpmLogMgr_initializeUsingExistingLog(TpmLogMgr* i_val,
                                                    uint8_t* i_eventLogPtr,
                                                    uint32_t i_eventLogSize);

    /**
     * @brief Add a new event to the log
     * @param[in] i_val TpmLogMgr structure
     * @param[in] i_logEvent Event log entry to add
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t TpmLogMgr_addEvent(TpmLogMgr* i_val,
                                  TCG_PCR_EVENT2* i_logEvent);

    /**
     * @brief Get current log size in bytes
     * @param[in] i_val TpmLogMgr structure
     * @return uint32_t Byte size of log
     */
    uint32_t TpmLogMgr_getLogSize(TpmLogMgr* i_val);

#ifdef __HOSTBOOT_MODULE
    /**
     * @brief Retrieve devtree information
     * @param[in] i_val TpmLogMgr structure
     * @param[in/out] io_logAddr TPM Log address
     * @param[out] o_allocationSize Total memory allocated for log
     * @param[out] o_xscomAddr Chip Xscom Address
     * @param[out] o_spiControllerOffset SPI Controller Offset
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *       error log.
     * Function will allocate a new region in memory to store log
     *  for passing to opal
     */
     errlHndl_t TpmLogMgr_getDevtreeInfo(TpmLogMgr* i_val,
                                         uint64_t & io_logAddr,
                                         size_t & o_allocationSize,
                                         uint64_t & o_xscomAddr,
                                         uint32_t & o_spiControllerOffset);

    /**
     * @brief Store TPM devtree node information
     * @param[in] i_val TpmLogMgr structure
     * @param[in] i_xscomAddr Chip Xscom Address
     * @param[in] i_spiControllerOffset SPI Controller Offset
     */
    void TpmLogMgr_setTpmDevtreeInfo(TpmLogMgr* i_val,
                                     uint64_t i_xscomAddr,
                                     uint32_t i_spiControllerOffset);
    /**
     * @brief Relocate the TPM log to the provided location
     * @param[in] i_val TpmLogMgr structure
     * @param[in] i_newLog Pointer to locate to place log
     * @param[in] i_maxSize Size of newLog location
     */
    void TpmLogMgr_relocateTpmLog(TpmLogMgr* i_val,
                                  uint8_t* i_newLog,
                                  size_t i_maxSize);
#endif


    /**
     * @brief Calculate the log size in bytes by walking the log
     * @param[in] i_val TpmLogMgr structure
     * @return uint32_t Byte size of log
     */
    uint32_t TpmLogMgr_calcLogSize(TpmLogMgr* i_val);

    /**
     * @brief Get pointer to first event in eventLog past the header event
     * @param[in] i_val TpmLogMgr structure
     * @return uint8_t First event handle
     * @retval NULL On empty log
     * @retval !NULL First event handle
     */
    const uint8_t* TpmLogMgr_getFirstEvent(TpmLogMgr* i_val);

    /**
     * @brief Get pointer to next event in log and unmarshal log contents
     *        into i_eventLog
     *
     * @param[in] i_val         TpmLogMgr structure
     * @param[in] i_handle      Current event to unmarshal
     * @param[in] i_eventLog    EVENT2 structure to populate
     * @param[in] o_err         Indicates if an error occurred during
     *                          LogUnmarshal.
     *
     * @return uint8_t*     Pointer to the next event after i_handle
     * @retval NULL When val contains last entry in log
     * @retval !NULL When addition log entries available
     */
    const uint8_t* TpmLogMgr_getNextEvent(TpmLogMgr* i_val,
                                          const uint8_t* i_handle,
                                          TCG_PCR_EVENT2* i_eventLog,
                                          bool* o_err);

    /**
     * @brief Get a TCG_PCR_EVENT2 populated with required data
     *
     * @param[in] i_pcr PCR to write to
     * @param[in] i_eventType Log event type to use
     * @param[in] i_algId_1 Algorithm to use
     * @param[in] i_digest_1 Digest value to write to PCR
     * @param[in] i_digestSize_1 Byte size of i_digest array
     * @param[in] i_algId_2 Algorithm to use
     * @param[in] i_digest_2 Digest value to write to PCR, NULL if not used
     * @param[in] i_digestSize_2 Byte size of i_digest array
     * @param[in] i_logMsg log message in binary form
     * @param[in] i_logMsgSize the size of log message in bytes
     *
     * @return TCG_PCR_EVENT2   PCR event log
     */
    TCG_PCR_EVENT2 TpmLogMgr_genLogEventPcrExtend(TPM_Pcr i_pcr,
                                                  EventTypes i_eventType,
                                                  TPM_Alg_Id i_algId_1,
                                                  const uint8_t* i_digest_1,
                                                  size_t i_digestSize_1,
                                                  TPM_Alg_Id i_algId_2,
                                                  const uint8_t* i_digest_2,
                                                  size_t i_digestSize_2,
                                                  const uint8_t* i_logMsg,
                                                  size_t i_logMsgSize);

    /**
     * @brief Dump contents of log to a trace
     * @param[in] i_val TpmLogMgr structure
     */
    void TpmLogMgr_dumpLog(TpmLogMgr* i_val);

    /**
     * @brief Return a pointer to the start of the log
     * @param[in] i_val TpmLogMgr structure
     * @return uint8_t* Pointer to the start of the TPM log
     */
    uint8_t* TpmLogMgr_getLogStartPtr(TpmLogMgr* i_val);


#ifdef __cplusplus
} // end TRUSTEDBOOT namespace
#endif

#endif
