/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/tpmLogMgr.H $                 */
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
#include "../trustedboot.H"
#include "../trustedTypes.H"
#else
#include "trustedboot.H"
#include "trustedTypes.H"
#endif

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
        TPMLOG_BUFFER_SIZE   = 1024, ///< Size of event log buffer in bytes
    };

    struct _TpmLogMgr
    {
        uint32_t logSize;        ///< Current byte size of log
        uint8_t eventLog[TPMLOG_BUFFER_SIZE]; ///< EventLog Buffer
        uint8_t* newEventPtr;    ///< Pointer to location to add new event
        mutex_t  logMutex;       ///< Log mutex
    };
    typedef struct _TpmLogMgr TpmLogMgr;

    /**
     * @brief Initialize the log manager
     * @param[in/out] io_logMgr Return a pointer to the log manager
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t TpmLogMgr_initialize(TpmLogMgr * io_logMgr);

    /**
     * @brief Add a new event to the log
     * @param[in] val TpmLogMgr structure
     * @param[in] logEvent Event log entry to add
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t TpmLogMgr_addEvent(TpmLogMgr* val, TCG_PCR_EVENT2* logEvent);

    /**
     * @brief Get current log size in bytes
     * @param[in] val TpmLogMgr structure
     * @return uint32_t Byte size of log
     */
    uint32_t TpmLogMgr_getLogSize(TpmLogMgr* val);

    /**
     * @brief Dump contents of log to a trace
     * @param[in] val TpmLogMgr structure
     */
    void TpmLogMgr_dumpLog(TpmLogMgr* val);


#ifdef __cplusplus
} // end TRUSTEDBOOT namespace
#endif

#endif
