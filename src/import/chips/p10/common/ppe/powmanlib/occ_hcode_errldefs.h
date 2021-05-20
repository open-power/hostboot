/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/ppe/powmanlib/occ_hcode_errldefs.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
// @file  occ_hcode_errldefs.h
// @brief Error log structures owned by OCC Firmware and also used by
//        PGPE, XPGE and QME HCode, to use the TMGT-OCC Error Logging
//        Mechanism
// @note  Refer section 3.3 of the 'OCC Firmware Interface Specification for
//        POWER10' for definition of the error log format in SRAM

#ifndef _OCC_HCODE_ERRLDEFS_H
#define _OCC_HCODE_ERRLDEFS_H

#include <stdint.h>

// Max number of callouts support per error log
#define ERRL_MAX_CALLOUTS 6

// These are the possible sources that an error log can be coming from
typedef enum
{
    ERRL_SOURCE_405     = 0x00,
    ERRL_SOURCE_PGPE    = 0x10,
    ERRL_SOURCE_XGPE    = 0x20,
    ERRL_SOURCE_QME     = 0x40,
    ERRL_SOURCE_INVALID = 0xFF,
} ERRL_SOURCE;

// These are the possible severities that an error log can have.
// Users must ONLY use these enum values for severity.
/* Error Severity */
typedef enum
{
    ERRL_SEV_INFORMATIONAL  = 0x00,  // Used by TMGT, HCODE
    ERRL_SEV_PREDICTIVE     = 0x01,  // Used by TMGT
    ERRL_SEV_UNRECOVERABLE  = 0x02,  // Used by TMGT, HCODE
    ERRL_SEV_CALLHOME_DATA  = 0x03,  // internal OCC use. Not used by TMGT
    ERRL_SEV_PGPE_ERROR     = 0x04,  // internal OCC use. Not used by TMGT
} ERRL_SEVERITY;

// These are the possible actions that an error log can have.
// Users must ONLY use these enum values for actions.
/* Error Actions */
#ifndef __PPE__
typedef enum
{
    ERRL_ACTIONS_MANUFACTURING_ERROR      = 0x08, //tmgt will set severity to predictive while in mfg mode
    ERRL_ACTIONS_FORCE_SEND               = 0x10, //htmgt will force error to be sent to BMC (for info errors to be seen)
    ERRL_ACTIONS_WOF_RESET_REQUIRED       = 0x20, //Soft reset without incrementing permanent safe mode count
    ERRL_ACTIONS_SAFE_MODE_REQUIRED       = 0x40, //immediate permanent safe mode without any recovery (checkstop)
    ERRL_ACTIONS_RESET_REQUIRED           = 0x80, //permanent safe mode after 3 recovery attempts
} ERRL_ACTIONS_MASK;
#endif

// These are the possible callout priorities that a callout can have.
// Users must ONLY use these enum values for callout priority
/* Callout Priority */
typedef enum
{
    ERRL_CALLOUT_PRIORITY_INVALID   = 0x00,
    ERRL_CALLOUT_PRIORITY_LOW       = 0x01,
    ERRL_CALLOUT_PRIORITY_MED       = 0x02,
    ERRL_CALLOUT_PRIORITY_HIGH      = 0x03,
} ERRL_CALLOUT_PRIORITY;

// These are the user detail types that a user details can have.
// Users must ONLY use these enum values for user detail type
/* User Detail Type */
typedef enum
{
    ERRL_USR_DTL_TRACE_DATA     = 0x01,
    ERRL_USR_DTL_CALLHOME_DATA  = 0x02,
    ERRL_USR_DTL_BINARY_DATA    = 0x03,
#ifndef __PPE__
    ERRL_USR_DTL_HISTORY_DATA   = 0x04,
    ERRL_USR_DTL_WOF_DATA       = 0x05,
    ERRL_USR_DTL_PGPE_PK_TRACE  = 0x06,
    ERRL_USR_DTL_PGPE_DATA      = 0x07,
#else
    ERRL_USR_DTL_DASH_PGPE      = 0x08,
    ERRL_USR_DTL_DASH_XGPE      = 0x09,
    ERRL_USR_DTL_DASH_QME       = 0x0A,
#endif
    ERRL_USR_DTL_PPE_REGS       = 0x0B,
    ERRL_USR_DTL_SR_FFDC        = 0x0C,
} ERRL_USR_DETAIL_TYPE;

// These are the possible OCC States.
/* OCC States */
#ifndef __PPE__
typedef enum
{
    ERRL_OCC_STATE_INVALID      = 0xFF,
} ERRL_OCC_STATE;
#endif

/* Errl Structure Version */
typedef enum
{
    ERRL_STRUCT_VERSION_1       = 0x01,
} ERRL_STRUCT_VERSION;

/* Errl User Details Version */
typedef enum
{
    ERRL_USR_DTL_STRUCT_VERSION_1       = 0x01,
} ERRL_USR_DTL_STRUCT_VERSION;


/* Errl Trace Version */
typedef enum
{
    ERRL_TRACE_VERSION_1        = 0x01,
} ERRL_TRACE_VERSION;

/* Errl PPE Debug Regs Version */
typedef enum
{
    ERRL_PPE_REGS_VERSION_1      = 0x01,
} ERRL_PPE_REGS_VERSION;

// Hcode related callouts will need firmware post-processing
// Callout types will be adapted/extended for Hcode after consulting with FW
// @note As a placeholder TMGT adds a processor callout if
//       sev!=info && source!=405 && numCallouts==0
/* Type of Callout */
typedef enum
{
    ERRL_CALLOUT_TYPE_HUID          = 0x01,
    ERRL_CALLOUT_TYPE_COMPONENT_ID  = 0x02,
    ERRL_CALLOUT_TYPE_GPU_ID        = 0x03,
} ERRL_CALLOUT_TYPE;

/* TMGT-OCC Component Ids */
typedef enum
{
    ERRL_COMPONENT_ID_FIRMWARE         = 0x01,
#ifndef __PPE__
    ERRL_COMPONENT_ID_OVER_TEMPERATURE = 0x04,
    ERRL_COMPONENT_ID_OVERSUBSCRIPTION = 0x05,
#endif
    ERRL_COMPONENT_ID_NONE             = 0xFF,
} ERRL_COMPONENT_ID;

/* Callout Structure */
struct ErrlCallout
{
    uint64_t iv_calloutValue; // Callout Value
    uint8_t  iv_type;         // Type of callout (See ERRL_CALLOUT_TYPE)
    uint8_t  iv_priority;     // Callout Priority (See ERRL_CALLOUT_PRIORITY)
    uint8_t  iv_reserved[6];  // PPE alignment restriction
} __attribute__ ((__packed__));

typedef struct ErrlCallout ErrlCallout_t;

// The User Detail Entry Structure consists of the fields below followed
// by the actual data the user is trying to collect.
// NOTE: A data pointer field is NOT defined but rather inferred here.  In the
//       error log contents, the user will see all the subsequent fields followed
//       by the actual data
//  NOTE: For performance and alignment requirements in PPE42, all data payloads
//        must be 8 byte aligned and with a size of multiples of 8 bytes
/* User Detail Entry Structure */
struct ErrlUserDetailsEntry
{
    uint8_t     iv_version; // User Details Entry Version
    uint8_t     iv_type;    // User Details Entry Type (use  ERRL_USR_DETAIL_TYPE)
    uint16_t    iv_size;    // User Details Entry Size
    uint32_t    iv_reserved;// PPE alignment restriction
} __attribute__ ((__packed__));

typedef struct ErrlUserDetailsEntry ErrlUserDetailsEntry_t;

// The User Detail Structure consists of the fields below followed
// by each individual User Details Entry structure & data
// NOTE: A data pointer field is NOT defined but rather inferred here.  In the
//       error log contents, the user will see all the subsequent fields followed
//       by each User Details Entry structure and its data
/* User Detail Structure */
struct ErrlUserDetails
{
    uint8_t     iv_version;             // User Details Version
    uint8_t     iv_reserved1;           // Reserved
    uint16_t    iv_modId;               // Module Id
    union
    {
        uint32_t    iv_fclipHistory;    // Frequency Clip History
        uint32_t    iv_procVersion;     // PPE Processor Version Register (PVR)
    };
    uint64_t    iv_timeStamp;           // Time Stamp
    union
    {
        struct
        {
            uint8_t    iv_occId;        // OCC ID
            uint8_t    iv_occRole;      // OCC Role
        };
        uint16_t    iv_ppeId;           // PPE Instance in Chip
    };
    union
    {
        uint8_t     iv_operatingState;  // OCC State
        uint8_t     iv_reserved2;       // PPE unused field
    };
    uint8_t     iv_committed: 1;        // Log Committed?
    uint8_t     iv_reserved3: 7;
    uint32_t    iv_userData1;           // User Data Word 1
    uint32_t    iv_userData2;           // User Data Word 2
    uint32_t    iv_userData3;           // User Data Word 3
    uint16_t    iv_entrySize;           // Log Size
    uint16_t    iv_userDetailEntrySize; // User Details Size
    uint32_t    iv_reserved4;           // PPE alignment requirement
} __attribute__ ((__packed__));

typedef struct ErrlUserDetails ErrlUserDetails_t;

/* Error Log Structure */
struct ErrlEntry
{
    uint16_t            iv_checkSum;         // Log CheckSum
    uint8_t             iv_version;          // Log Version
    uint8_t             iv_entryId;          // Log Entry ID
    uint8_t             iv_reasonCode;       // Log Reason Code
    uint8_t             iv_severity;         // Log Severity - see ERRL_SEVERITY enum
    union                                    // Actions to process the errors
    {
        struct
        {
            uint8_t reset_required     : 1;  // Error is critical and requires OCC reset
            uint8_t safe_mode_required : 1;  // immediate permanent safe mode (used for checkstops)
            uint8_t wof_reset_required : 1;  // request soft reset (will not increment counts for safe mode)
            uint8_t force_send         : 1;  // Force elog to be sent to the BMC
            uint8_t mfg_error          : 1;  // Fan go to max,oversubscription,core above warning,Throttled.
            uint8_t reserved1          : 3;
        };
        uint8_t word;
        uint8_t reserved2;                   // PPE: must be set 0 until actions are used
    } iv_actions;
    // Max number of callouts that can be returned (internally used for actual callout count until commit)
    uint8_t             iv_numCallouts;
    uint16_t            iv_extendedRC;
    // Maximum size for the whole error log including all user details
    uint16_t            iv_maxSize;
    uint32_t            iv_reserved3;         // PPE alignment
    ErrlCallout_t       iv_callouts[ERRL_MAX_CALLOUTS]; // Callouts
    ErrlUserDetails_t   iv_userDetails;      // User Details section for Log

} __attribute__ ((__packed__));

typedef struct ErrlEntry ErrlEntry_t;

/* Error Log Handle */
typedef ErrlEntry_t* errlHndl_t;

#endif //_OCC_HCODE_ERRLDEFS_H
