/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/thread_activate/proc_thread_control/proc_thread_control.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_thread_control.H,v 1.8 2012/09/10 17:34:27 karm Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_thread_control
// *! DESCRIPTION : Core Thread start/stop/step/query/activate operations
// *!               Use to start (start or sreset) thread instruction execution,
// *!                 stop instruction execution, or single instruction step.
// *!               Also used to query the state of a thread.
// *! OWNER NAME  : Lance Karm          Email: karm@us.ibm.com
// *! BACKUP NAME : Sebastien Lafontant Email: slafont@us.ibm.com
//------------------------------------------------------------------------------


#ifndef _PROC_THREAD_CONTROL_H_
#define _PROC_THREAD_CONTROL_H_

#include <fapi.H>
#include "p8_scom_addresses.H"

typedef fapi::ReturnCode
(*proc_thread_control_FP_t)(const fapi::Target&,
        const uint8_t,
        const uint8_t,
        const bool,
        ecmdDataBufferBase&,
        uint64_t&);


// ProcThreadControl input commands
const uint8_t PTC_CMD_SRESET            = 0;
const uint8_t PTC_CMD_STEP              = 1;
const uint8_t PTC_CMD_START             = 2;
const uint8_t PTC_CMD_STOP              = 3;
const uint8_t PTC_CMD_ACTIVATE          = 4;
const uint8_t PTC_CMD_QUERY             = 5;

// ProcThreadContrl Thread Control and State bit definitions
const uint8_t PTC_DIR_CTL_SP_SRESET     = 60;
const uint8_t PTC_DIR_CTL_SP_STEP       = 61;
const uint8_t PTC_DIR_CTL_SP_START      = 62;
const uint8_t PTC_DIR_CTL_SP_STOP       = 63;
const uint8_t PTC_RAM_THREAD_ACTIVE_T0  = 8;
const uint8_t PTC_RAS_MODE_SINGLE       = 50;

const uint8_t PTC_RAS_STAT_CHKSTOP      = 2;
const uint8_t PTC_RAS_STAT_INST_COMP    = 12;
const uint8_t PTC_RAS_STAT_THD_POR      = 20;
const uint8_t PTC_RAS_STAT_MAINT        = 21;
const uint8_t PTC_RAS_STAT_ENABLED      = 48;
const uint8_t PTC_RAS_STAT_THD_QUIESCED = 49;
const uint8_t PTC_RAS_STAT_THD_STARTING = 50;
const uint8_t PTC_RAS_STAT_RUN_BIT      = 51;
const uint8_t PTC_RAS_STAT_THD_STOPPING = 52;

const uint8_t PTC_STEP_COMP_POLL_LIMIT  = 10;

// o_state thread state return bit enums
const uint64_t THREAD_STATE_RUNNING    = 0x8000000000000000ULL;
const uint64_t THREAD_STATE_QUIESCED   = 0x4000000000000000ULL;
const uint64_t THREAD_STATE_STARTING   = 0x2000000000000000ULL;
const uint64_t THREAD_STATE_STOPPING   = 0x1000000000000000ULL;
const uint64_t THREAD_STATE_POR        = 0x0800000000000000ULL;
const uint64_t THREAD_STATE_ENABLED    = 0x0400000000000000ULL;
const uint64_t THREAD_STATE_RAM_ACTIVE = 0x0200000000000000ULL;
const uint64_t THREAD_STATE_MAINT      = 0x0100000000000000ULL;
const uint64_t THREAD_STATE_CHKSTOP    = 0x0080000000000000ULL;
const uint64_t THREAD_STATE_INSTCOMP   = 0x0040000000000000ULL;


extern "C"
{
    fapi::ReturnCode proc_thread_control(const fapi::Target&, const uint8_t,
            const uint8_t, const bool, ecmdDataBufferBase&, uint64_t&);

    fapi::ReturnCode proc_thread_control_sreset(const fapi::Target&,
            const uint8_t, const bool, ecmdDataBufferBase&, uint64_t&);
    fapi::ReturnCode proc_thread_control_start(const fapi::Target&,
            const uint8_t, const bool, ecmdDataBufferBase&, uint64_t&);
    fapi::ReturnCode proc_thread_control_stop(const fapi::Target&,
            const uint8_t, const bool, ecmdDataBufferBase&, uint64_t&);
    fapi::ReturnCode proc_thread_control_step(const fapi::Target&,
            const uint8_t, const bool, ecmdDataBufferBase&, uint64_t&);
    fapi::ReturnCode proc_thread_control_activate(const fapi::Target&,
            const uint8_t, ecmdDataBufferBase&, uint64_t&);
    fapi::ReturnCode proc_thread_control_query(const fapi::Target&,
            const uint8_t, ecmdDataBufferBase&, uint64_t&);
}

#endif // _PROC_THREAD_CONTROL_H_
