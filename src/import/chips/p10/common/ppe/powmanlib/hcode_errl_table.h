/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/ppe/powmanlib/hcode_errl_table.h $ */
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

// @file  hcode_errl_table.h
// @brief Error log table pointing to details of error logs created by HCode
//        engines in OCC SRAM. Used to report and collect the error logs the
//        same way as an error being reported by the OCC.
// @note  Refer section 3.2 of the 'OCC Firmware Interface Specifictaion for
//        POWER10' for details on the OCC assisted error logging mechanism.

#ifndef _HCODE_ERRL_TABLE_H
#define _HCODE_ERRL_TABLE_H

#include <stdint.h>

#define HCODE_ELOG_TABLE_MAGIC_NUMBER 0x454C5443 // "ELTC"

// Max number of error log slots per GPE
// Support 1 unrecoverable & 1 informational elog per GPE
#define MAX_ELOG_SLOTS_PER_GPE 1

// Maximum number of error log entries in error log table
#ifdef __PPE_QME
    // QME local table in QME SRAM .. logs downloaded by XGPE
    #define MAX_ELOG_ENTRIES 1
#else
    // OCC global table in OCC SRAM .. (8 QMEs + 1 PGPE + 1 XPGE)*2
    #define MAX_ELOG_ENTRIES 10
#endif

// Structure of an individual error log entry in the table
typedef struct
{
    union
    {
        uint64_t value;
        struct
        {
            uint32_t high_order;
            uint32_t low_order;
        } words;
        struct
        {
            uint64_t errlog_id                  : 8;
            uint64_t errlog_src                 : 8;
            uint64_t errlog_len                 : 16;
            uint64_t errlog_addr                : 32;
        } fields;
    } dw0;
} hcode_elog_entry_t;

// Full Error Log Table
typedef struct hcode_error_table
{
    union
    {
        uint64_t value;
        struct
        {
            uint32_t high_order;
            uint32_t low_order;
        } words;
        struct
        {
            uint64_t magic_word                 : 32; //ELTC
            uint64_t total_log_slots            : 8;
            uint64_t reserved                   : 24;
        } fields;
    } dw0;

    /// Array of error log entries
    hcode_elog_entry_t  elog[MAX_ELOG_ENTRIES];
} hcode_error_table_t;

#endif // _HCODE_ERRL_TABLE_H
