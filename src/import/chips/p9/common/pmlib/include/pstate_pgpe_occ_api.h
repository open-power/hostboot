/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/pmlib/include/pstate_pgpe_occ_api.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_pstates_pgpe_occ_api.h
/// @brief Structures used between PGPE HCode and OCC Firmware
///
// *HWP HW Owner        : Rahul Batra <rbatra@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE:OCC


#ifndef __P9_PSTATES_PGPE_API_H__
#define __P9_PSTATES_PGPE_API_H__

#include <p9_pstates_common.h>

#ifdef __cplusplus
extern "C" {
#endif


//---------------
// IPC from 405
//---------------
//Note: These are really not used. They are just for documentation purposes
enum MESSAGE_ID_IPI2HI
{
    MSGID_405_INVALID       = 0,
    MSGID_405_START_SUSPEND = 1,
    MSGID_405_CLIPS         = 2,
    MSGID_405_SET_PMCR      = 3,
    MSGID_405_WOF_CONTROL   = 4,
    MSGID_405_WOF_VFRT      = 5
};

//
// Return Codes
//
#define PGPE_RC_SUCCESS                         0x01
#define PGPE_WOF_RC_NOT_ENABLED                 0x10
#define PGPE_RC_PSTATES_NOT_STARTED             0x11
#define PGPE_RC_REQ_PSTATE_ALREADY_STARTED      0x12
#define PGPE_RC_REQ_PSTATE_ALREADY_STOPPED      0x13
#define PGPE_RC_OCC_NOT_PMCR_OWNER              0x14
#define PGPE_RC_PM_COMPLEX_SUSPEND_SAFE_MODE    0x15
// Active quad mismatch with requested active quads.  PGPE did not switch
// to using the new VFRT.  The original VFRT is still being used.
#define PGPE_WOF_RC_VFRT_QUAD_MISMATCH  0x20
#define PGPE_RC_REQ_WHILE_PENDING_ACK   0x21

//
// PMCR Owner
//
typedef enum
{
    PMCR_OWNER_HOST         = 0,
    PMCR_OWNER_OCC          = 1,
    PMCR_OWNER_CHAR         = 2
} PMCR_OWNER;


typedef struct ipcmsg_base
{
    uint8_t   rc;
} ipcmsg_base_t;


//
// Start Suspend Actions
//
#define PGPE_ACTION_PSTATE_START   0
#define PGPE_ACTION_PSTATE_STOP    1

typedef struct ipcmsg_start_stop
{
    ipcmsg_base_t   msg_cb;
    uint8_t         action;
    PMCR_OWNER      pmcr_owner;
} ipcmsg_start_stop_t;


typedef struct ipcmsg_clip_update
{
    ipcmsg_base_t   msg_cb;
    uint8_t         ps_val_clip_min[MAXIMUM_QUADS];
    uint8_t         ps_val_clip_max[MAXIMUM_QUADS];
    uint8_t         pad[2];
} ipcmsg_clip_update_t;


typedef struct ipcmsg_set_pmcr
{
    ipcmsg_base_t   msg_cb;
    uint8_t         pad[6];
    uint64_t        pmcr[MAXIMUM_QUADS];
} ipcmsg_set_pmcr_t;


//
// WOF Control Actions
//
#define PGPE_ACTION_WOF_ON         1
#define PGPE_ACTION_WOF_OFF        2

typedef struct ipcmsg_wof_control
{
    ipcmsg_base_t   msg_cb;
    uint8_t         action;
    uint8_t         pad;
} ipcmsg_wof_control_t;


typedef struct ipcmsg_wof_vfrt
{
    ipcmsg_base_t   msg_cb;
    uint8_t         active_quads; // OCC updated with the Active Quads that it
    // is using for its Ceff calculations
    uint8_t         pad;
    HomerVFRTLayout_t* homer_vfrt_ptr;
} ipcmsg_wof_vfrt_t;


// -----------------------------------------------------------------------------
// Start Pstate Table

#define MAX_OCC_PSTATE_TABLE_ENTRIES 256

/// Pstate Table produce by the PGPE for consumption by OCC Firmware
///
/// This structure defines the Pstate Table content
/// -- 16B structure

typedef struct
{
    /// Pstate number
    Pstate      pstate;

    /// Assocated Frequency (in MHz)
    uint16_t    frequency_mhz;

    /// Internal VDD voltage ID at the output of the PFET header
    uint8_t    internal_vdd_vid;

} OCCPstateTable_entry_t;

typedef struct
{
    /// Number of Pstate Table entries
    uint32_t                entries;

    /// Internal VDD voltage ID at the output of the PFET header
    OCCPstateTable_entry_t  table[MAX_OCC_PSTATE_TABLE_ENTRIES];

} OCCPstateTable_t;

// End Pstate Table
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Start FFDC

/// Scopes of the First Failure Data Capture (FFDC) registers
enum scope_type
{
    FFDC_CHIP = 0,  // Address is chip scope (eg absolute)
    FFDC_QUAD = 1,  // Address + 0x01000000*quad for good quads from 0 to 5
    FFDC_CORE = 2,  // Address + 0x01000000*core for good cores from 0 to 23
    FFDC_CME = 3    // Address if EX is even; Address + 0x400*EX for EX odd for good Exs from 0 to 11
};

/// Address types of First Failure Data Capture (FFDC) register addresses
enum scope_type1
{
    FFDC_OCI  = 0,   // Address is an OCI address
    FFDC_SCOM = 1    // Address is a SCOM address
};

/// Register definition of the Hcode FFDC register list
#define MAX_FFDC_REG_LIST 12
typedef struct
{
    uint32_t            address;
    /*    union address_attribute
        {
            uint32_t value;
            struct
            {
                uint32_t    address_type : 16;
                uint32_t    scope        : 16;
            } attr;
        }*/
} Hcode_FFDC_entry_t;

/// Hcode FFDC register list
typedef struct
{
    /// Number of FFDC address list entries
    uint32_t            list_entries;

    /// FFDC Address list
    Hcode_FFDC_entry_t  list[MAX_FFDC_REG_LIST];
} Hcode_FFDC_list_t;



/// Hcode FFDC register list
/// @todo RTC: 161183  Fill out the rest of this FFDC list
/// @note The reserved FFDC space for registers and traces set aside in the
/// OCC is 1KB.   On the register side, the following list will generate
/// 12B of content (4B address, 8B data) x the good entries per scope.
/// CHIP scope are not dependent on partial good or currently active and will
/// take 12B x 8 = 96B.  CME scope entries will, at maximum, generate 12B x
/// 12 CMEs x  4 SCOMs = 576B..  The overall  totla for registers is 96 + 576
///
/*typedef struct Hcode_FFDC_list
{

    {PERV_TP_OCC_SCOM_OCCLFIR,  FFDC_SCOM, FFDC_CHIP }, // OCC LFIR
    {PU_PBAFIR,                 FFDC_SCOM, FFDC_CHIP }, // PBA LFIR
    {EX_CME_SCOM_LFIR,          FFDC_SCOM, FFDC_CME  }, // CME LFIR
    {PU_GPE3_GPEDBG_OCI,        FFDC_OCI,  FFDC_CHIP }, // SGPE XSR, SPRG0
    {PU_GPE3_GPEDDR_OCI,        FFDC_OCI,  FFDC_CHIP }, // SGPE IR, EDR
    {PU_GPE3_PPE_XIDBGPRO,      FFDC_OCI,  FFDC_CHIP }, // SGPE XSR, IAR
    {PU_GPE2_GPEDBG_OCI,        FFDC_OCI,  FFDC_CHIP }, // PGPE XSR, SPRG0
    {PU_GPE2_GPEDDR_OCI,        FFDC_OCI,  FFDC_CHIP }, // PGPE IR, EDR
    {PU_GPE2_PPE_XIDBGPRO,      FFDC_OCI,  FFDC_CHIP }, // PGPE XSR, IAR
    {EX_PPE_XIRAMDBG,           FFDC_SCOM, FFDC_CME  }, // CME XSR, SPRG0
    {EX_PPE_XIRAMEDR,           FFDC_SCOM, FFDC_CME  }, // CME IR, EDR
    {EX_PPE_XIDBGPRO,           FFDC_SCOM, FFDC_CME  }, // CME XSR, IAR

};*/

// End FFDC
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Start Quad State

typedef union quad_state0
{
    uint64_t value;
    struct
    {
        uint32_t high_order;
        uint32_t low_order;
    } words;
    struct
    {
        uint64_t quad0_pstate             : 8;  // Pstate of Quad 0; 0xFF indicates EQ is off
        uint64_t quad1_pstate             : 8;  // Pstate of Quad 1; 0xFF indicates EQ is off
        uint64_t quad2_pstate             : 8;  // Pstate of Quad 2; 0xFF indicates EQ is off
        uint64_t quad3_pstate             : 8;  // Pstate of Quad 3; 0xFF indicates EQ is off
        uint64_t active_cores             : 16; // bit vector: 0:core0, 1:core1, ..., 15:core15
    uint64_t ivrm_state               :
        8;  // ivrm state: bit vector 0:quad0, 1:quad1, 2:quad2, 3;quad3, 4: quad4, 5: quad5, 6-7:reserved
        uint64_t reserved                 : 8;  // reserved for future use
    } fields;
} quad_state0_t;

typedef union quad_state1
{
    uint64_t value;
    struct
    {
        uint32_t high_order;
        uint32_t low_order;
    } words;
    struct
    {
        uint64_t quad4_pstate             : 8;  // Pstate of Quad 4; 0xFF indicates EQ is off
        uint64_t quad5_pstate             : 8;  // Pstate of Quad 5; 0xFF indicates EQ is off
        uint64_t reserved0                : 16;
        uint64_t active_cores             : 16; // bit vector: 0:core16, 1:core17, ..., 7:core23
    uint64_t ivrm_state               :
        8;  // ivrm state: bit vector 0:quad0, 1:quad1, 2:quad2, 3;quad3, 4: quad4, 5: quad5, 6-7:reserved
        uint64_t reserved1                : 8;  // reserved for future use
    } fields;
} quad_state1_t;

typedef union pgpe_wof_state
{
    uint64_t value;
    struct
    {
        uint32_t high_order;
        uint32_t low_order;
    } words;
    struct
    {
        uint64_t reserved0              : 8;
        uint64_t fclip_ps               : 8;
        uint64_t vclip_mv               : 16;
        uint64_t fratio                 : 16;
        uint64_t vratio                 : 16;
    } fields;
} pgpe_wof_state_t;

typedef union requested_active_quads
{
    uint64_t value;
    struct
    {
        uint32_t high_order;
        uint32_t low_order;
    } words;
    struct
    {
        uint64_t reserved                   : 56;
        uint64_t requested_active_quads     : 8;
    } fields;
} requested_active_quads_t;

// End Quad State
// -----------------------------------------------------------------------------


typedef struct
{
    /// Magic number + version.  "OPS" || version (nibble)
    uint32_t            magic;

    /// PGPE Beacon
    uint32_t            pgpe_beacon;

    /// Actual Pstate 0 - Quads 0, 1, 2, 3
    quad_state0_t       quad_pstate_0;

    /// Actual Pstate 1 - Quads 4, 5
    quad_state1_t       quad_pstate_1;

    ///PGPE WOF State
    pgpe_wof_state_t    pgpe_wof_state;

    ///Requested Active Quads
    requested_active_quads_t    req_active_quads;

    /// FFDC Address list
    Hcode_FFDC_list_t   ffdc_list;

    /// Pstate Table
    OCCPstateTable_t    pstate_table;

} HcodeOCCSharedData_t;

#ifdef __cplusplus
} // end extern C
#endif

#endif    /* __P9_PSTATES_PGPE_API_H__ */
