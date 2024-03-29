/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/occError.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
#ifndef OCCERROR_H
#define OCCERROR_H

#include <stdint.h>
#include "htmgt_occ.H"

namespace HTMGT
{
    // Error Severity
    enum occSeverityType
    {
        OCC_SEV_INFORMATIONAL   = 0x00,
        OCC_SEV_RECOVERABLE     = 0x01,
        OCC_SEV_UNRECOVERABLE   = 0x02
    };

    // Error Actions
    enum tmgtErrlActionsType
    {
        TMGT_ERRL_ACTIONS_OCMB_RECOVERY_REQUEST    = 0x04,
        TMGT_ERRL_ACTIONS_MANUFACTURING_ERROR      = 0x08,
        TMGT_ERRL_ACTIONS_FORCE_ERROR_POSTED       = 0x10,
        TMGT_ERRL_ACTIONS_WOF_RESET_REQUIRED       = 0x20,
        TMGT_ERRL_ACTIONS_SAFE_MODE_REQUIRED       = 0x40,
        TMGT_ERRL_ACTIONS_RESET_REQUIRED           = 0x80,
    };

    // Type of Callout
    enum occCalloutType
    {
        OCC_CALLOUT_TYPE_SENSOR        = 0x01,
        OCC_CALLOUT_TYPE_COMPONENT_ID  = 0x02,
        OCC_CALLOUT_TYPE_GPU_SENSOR    = 0x03,
    };

    // OCC memory buffer recovery status id
    enum occMemoryBufferRecoveryStatus
    {
        OCC_MEMORY_BUFFER_RECOVERY_SUCCESS       = 0x00,
        OCC_MEMORY_BUFFER_RECOVERY_FAILED        = 0xF0,
        OCC_MEMORY_BUFFER_RECOVERY_UNSUPPORTED   = 0x11,
    };


    // TMGT-OCC Component Ids
    enum occCompIdType
    {
        OCC_COMPONENT_ID_FIRMWARE         = 0x01,
        OCC_COMPONENT_ID_OVER_TEMPERATURE = 0x04,
        OCC_COMPONENT_ID_OVERSUBSCRIPTION = 0x05,
        OCC_COMPONENT_ID_NONE             = 0xFF,
    };

    // Callout Data Type, this was ported forward from P7
    enum tmgtCompxlateType
    {
        TMGT_COMP_DATA_RID                 = 0x00,
        TMGT_COMP_DATA_PROC_RID            = 0x01,
        TMGT_COMP_DATA_PROCEDURE           = 0x02,
        TMGT_COMP_DATA_POWR_VRM_NUM        = 0x03,
        TMGT_COMP_DATA_MEMORY_TABLE_NUM    = 0x04,
        TMGT_COMP_DATA_POWR_DCA_NUM        = 0x05,
        TMGT_COMP_DATA_IOHUB_TABLE_NUM     = 0x06,
        TMGT_COMP_DATA_SYMBOLIC_FRU        = 0x07,
        TMGT_COMP_DATA_SN_TABLE_NUM        = 0x08,
        TMGT_COMP_DATA_VDD_PROC_RID        = 0x0A,
        TMGT_COMP_DATA_END_OF_TABLE        = 0xFF
    };

    // Callout Priority Translation
    struct occSrciPriorityXlate
    {
        uint8_t      occPriority;
        HWAS::callOutPriority errlPriority;
    } __attribute__ ((__packed__));
    typedef struct occSrciPriorityXlate occSrciPriorityXlate_t;

    const occSrciPriorityXlate_t occPriorityXlateTbl[] =
    {
        {0x01, HWAS::SRCI_PRIORITY_LOW},
        {0x02, HWAS::SRCI_PRIORITY_MED},
        {0x03, HWAS::SRCI_PRIORITY_HIGH},
    };
    const uint8_t OCC_SRCI_PRIORITY_XLATE_SIZE =
        (sizeof(occPriorityXlateTbl) / sizeof(occSrciPriorityXlate_t));

    // OCC Usr Dtls Structure
    struct occErrlUsrDtls
    {
        uint8_t     version;             // User Details Version
        uint8_t     reserved;            // Reserved
        uint16_t    modId;               // Module Id
        uint32_t    fClipHistory;        // Frquency Clip History
        uint64_t    timeStamp;           // Time Stamp
        uint8_t     occId;               // OCC ID
        uint8_t     occRole;             // OCC Role
        uint8_t     operatingState;      // OCC State
        uint8_t     committed;           // Log Committed?
        uint32_t    userData1;           // User Data Word 1
        uint32_t    userData2;           // User Data Word 2
        uint32_t    userData3;           // User Data Word 3
        uint16_t    entrySize;           // Log Size
        uint16_t    userDetailEntrySize; // User Details Size
    } __attribute__ ((__packed__));
    typedef struct occErrlUsrDtls occErrlUsrDtls_t;

    // User Detail Entry Structure
    struct occUserDetailsEntry
    {
        uint8_t     version; // User Details Entry Version
        uint8_t     type;    // User Details Entry Type
        // Note: Users must use ERRL_USR_DETAIL_TYPE enum
        uint16_t    size;    // User Details Entry Size
    } __attribute__ ((__packed__));
    typedef struct occUserDetailsEntry occUserDetailsEntry_t;

#define ERRL_MAX_CALLOUTS 6

    // OCC Error Log Structure
    struct occErrlEntry
    {
        // Log CheckSum
        uint16_t            checkSum;
        // Log Version
        uint8_t             version;
        // Log Entry ID
        uint8_t             entryId;
        // Log Reason Code
        uint8_t             reasonCode;
        // Log Severity
        uint8_t             severity;
        // Actions to process the errors
        uint8_t             actions;
        // Max callouts that could be returned
        uint8_t             maxCallouts;
        // Extended Reason Code
        uint16_t            extendedRC;
        // Max size for entire error log (including user details)
        uint16_t            maxElogSize;
        // Reserved
        uint32_t            reserved;
        // Callouts
        occErrlCallout      callout[ERRL_MAX_CALLOUTS];
    } __attribute__ ((__packed__));
    typedef struct occErrlEntry occErrlEntry_t;


    // OCC Severity and Action
    struct occSeverityActionXlate
    {
        occSeverityType             occSeverity;
        ERRORLOG::errlSeverity_t    occErrlSeverity;
    };
    typedef struct occSeverityActionXlate occSeverityActionXlate_t;

    // Translate Severity and Actions
    const occSeverityActionXlate_t occSeverityErrorActionXlate[] =
    {
        {OCC_SEV_INFORMATIONAL, ERRORLOG::ERRL_SEV_INFORMATIONAL},
        {OCC_SEV_RECOVERABLE,   ERRORLOG::ERRL_SEV_PREDICTIVE},
        {OCC_SEV_UNRECOVERABLE, ERRORLOG::ERRL_SEV_UNRECOVERABLE},
    };
    const uint8_t OCC_SEV_ACTION_XLATE_SIZE =
        (sizeof(occSeverityErrorActionXlate)/sizeof(occSeverityActionXlate_t));




    struct tmgtCompXlate
    {
        uint8_t               compId;
        tmgtCompxlateType     dataType;
        uint32_t              data;
    };
    typedef struct tmgtCompXlate tmgtCompXlate_t;

    const uint16_t TMGT_MAX_COMP_IDS = 4;

    const uint32_t OVERTMP = 0x05;
    const uint32_t TPMD_OV = 0x06;

    const tmgtCompXlate_t tmgt_compXlateTable[TMGT_MAX_COMP_IDS] =
    {
        { 0x01, TMGT_COMP_DATA_PROCEDURE,    HWAS::EPUB_PRC_HB_CODE}, // FW
        { 0x04, TMGT_COMP_DATA_SYMBOLIC_FRU, OVERTMP}, // over temperature
        { 0x05, TMGT_COMP_DATA_SYMBOLIC_FRU, TPMD_OV}, // oversub throttling
        { 0xFF, TMGT_COMP_DATA_END_OF_TABLE, 0},       // none
    };


    struct tmgtSafeModeReasonCode_t
    {
        uint32_t    returnCode;
        uint32_t    huid;
        bool        infoOnly;
    };


    // OCC Error Source
    enum occErrorSource_e
    {
        OCC_ERRSRC_405  = 0x00,
        OCC_ERRSRC_PGPE = 0x10,
        OCC_ERRSRC_XGPE = 0x20,
        OCC_ERRSRC_QME  = 0x40
    };


} // end namespace
#endif
