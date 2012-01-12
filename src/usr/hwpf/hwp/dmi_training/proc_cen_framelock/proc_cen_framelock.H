//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/proc_cen_framelock.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: proc_cen_framelock.H,v 1.3 2012/01/06 23:44:51 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_framelock.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cen_framelock.H
// *! DESCRIPTION : Run framelock and FRTL (FAPI)
// *!
// *! OWNER NAME  : Irving Baysah           Email: baysah@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_CEN_FRAMELOCK_H_
#define _PROC_CEN_FRAMELOCK_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"
#include "cen_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// enum to represent supported channel init timeout values
enum proc_cen_framelock_channel_init_timeout
{
    CHANNEL_INIT_TIMEOUT_NO_TIMEOUT = 0,
    CHANNEL_INIT_TIMEOUT_3US = 1,
    CHANNEL_INIT_TIMEOUT_7US = 2,
    CHANNEL_INIT_TIMEOUT_14US = 3
};

// structure to represent HWP arguments
struct proc_cen_framelock_args
{
    uint8_t mcs_pu; // MCS offset on P8 chip target to operate on
    bool in_error_state; // apply error state overrides to framelock/auto FRTL?
    proc_cen_framelock_channel_init_timeout channel_init_timeout;
                         // channel init timeout value to program for framelock/
                         // auto/FRTL
    bool frtl_auto_not_manual; // set FRTL mode (true = auto-calculation via HW,
                               // false = manually-programmed via SW)
    uint8_t frtl_manual_pu; // in manual FRTL mode, P8 MCI FRTL value to be
                            // programmed
    uint8_t frtl_manual_mem; // in manual FRTL mode, Centaur MBI FRTL value to
                             // be programmed
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_cen_framelock_FP_t)(const fapi::Target&,
                           const fapi::Target&,
                           const proc_cen_framelock_args&);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// maximum MCS offset supported by P8 chip design
const uint8_t PROC_CEN_FRAMELOCK_MAX_MCS_OFFSET = 7;

// framelock/FRTL polling constants
const uint8_t PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS = 5;
const uint8_t PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS = 5;

// P8 MCI Configuration Register field/bit definitions
const uint32_t MCI_CFG_START_FRAMELOCK_BIT            = 7;
const uint32_t MCI_CFG_START_FRTL_BIT                 = 8;
const uint32_t MCI_CFG_AUTO_FRTL_DISABLE_BIT          = 9;
const uint32_t MCI_CFG_MANUAL_FRTL_START_BIT          = 10;
const uint32_t MCI_CFG_MANUAL_FRTL_END_BIT            = 16;
const uint32_t MCI_CFG_MANUAL_FRTL_DONE_BIT           = 17;
const uint32_t MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT = 35;
const uint32_t MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT   = 36;

const uint8_t MCI_CFG_MANUAL_FRTL_FIELD_MASK = 0x7F;
const uint32_t MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK = 0x3;

// P8 MCI Status Register field/bit definitions
const uint32_t MCI_STAT_FRAMELOCK_PASS_BIT = 0;
const uint32_t MCI_STAT_FRAMELOCK_FAIL_BIT = 1;
const uint32_t MCI_STAT_FRTL_PASS_BIT      = 2;
const uint32_t MCI_STAT_FRTL_FAIL_BIT      = 3;

// Centaur MBI Configuration Register field/bit defintions
const uint32_t MBI_CFG_FORCE_FRAMELOCK_BIT            = 7;
const uint32_t MBI_CFG_FORCE_FRTL_BIT                 = 8;
const uint32_t MBI_CFG_AUTO_FRTL_DISABLE_BIT          = 9;
const uint32_t MBI_CFG_MANUAL_FRTL_START_BIT          = 10;
const uint32_t MBI_CFG_MANUAL_FRTL_END_BIT            = 16;
const uint32_t MBI_CFG_MANUAL_FRTL_DONE_BIT           = 17;
const uint32_t MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT = 35;
const uint32_t MBI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT   = 36;

const uint8_t MBI_CFG_MANUAL_FRTL_FIELD_MASK = 0x7F;
const uint32_t  MBI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK = 0x3;

// Centaur MBI Status Register field/bit definitions
const uint32_t MBI_STAT_FRAMELOCK_PASS_BIT = 0;
const uint32_t MBI_STAT_FRAMELOCK_FAIL_BIT = 1;
const uint32_t MBI_STAT_FRTL_PASS_BIT      = 2;
const uint32_t MBI_STAT_FRTL_FAIL_BIT      = 3;

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

// function: FAPI proc_cen_framelock HWP entry point, execute P8/Centaur
//           framelock and FRTL operations
// parameters: i_pu_target  => P8 chip target
//             i_mem_target => Centaur chip target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if framelock/FRTL sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_INVALID_ARGS
//              if invalid/out of range arguments are presented in i_args,
//          RC_PROC_CEN_FRAMELOCK_INTERNAL_ERR
//              if internal program logic error is encountered,
//          RC_PROC_CEN_FRAMELOCK_FL_CEN_FIR_ERR
//              if Centaur MBI FIR is set during framelock operation,
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR
//              if P8 MCI FIR is set during framelock operation,
//          RC_PROC_CEN_FRAMELOCK_FL_CEN_FAIL_ERR
//              if Centaur MBI indicates framelock operation failure,
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FAIL_ERR
//              if P8 MCI indicates framelock operation failure,
//          RC_PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after framelock
//              operation is started,
//          RC_PROC_CEN_FRAMELOCK_FRTL_CEN_FIR_ERR
//              if Centaur MBI FIR is set during FRTL operation,
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR
//              if P8 MCI FIR is set during FRTL operation,
//          RC_PROC_CEN_FRAMELOCK_FRTL_CEN_FAIL_ERR
//              if Centaur MBI indicates FRTL operation failure,
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FAIL_ERR
//              if P8 MCI indicates FRTL operation failure,
//          RC_PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after FRTL
//              operation is started,
//          
//          else FAPI getscom/putscom return code for failing operation
fapi::ReturnCode proc_cen_framelock(const fapi::Target& i_pu_target,
                                    const fapi::Target& i_mem_target,
                                    const proc_cen_framelock_args& i_args);

} // extern "C"

#endif // _PROC_CEN_FRAMELOCK_H_
