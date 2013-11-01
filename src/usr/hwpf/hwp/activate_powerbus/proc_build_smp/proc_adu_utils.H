/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_adu_utils.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_adu_utils.H,v 1.6 2013/09/26 17:57:02 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_adu_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_adu_utils.H
// *! DESCRIPTION : ADU library functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Jeshua Smith  Email: jeshua@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
// *! The functions contained in this library provide a mechanism to issue
// *! fabric commands from the P8 Alter Display Unit (ADU).
// *!
// *! To perform a read operation on the fabric:
// *!   o Obtain lock protecting ADU resources:
// *!         proc_adu_utils_manage_adu_lock()
// *!   o Clear ADU Status registers, reset ADU state machine:
// *!         proc_adu_utils_reset_adu()
// *!   o Program fabric command/address into ADU control logic & issue command
// *!         proc_adu_utils_send_fbc_op()
// *!   o Poll ADU status bits to ensure read data has arrived:
// *!         proc_adu_utils_get_adu_status()
// *!   o Read ADU data registers to retrieve data:
// *!         proc_adu_utils_get_adu_data_registers()
// *!   o Clear ADU lock:
// *!         proc_adu_utils_manage_adu_lock()
// *!
// *! To perform a write operation on the fabric:
// *!   o Obtain lock protecting ADU resources:
// *!         proc_adu_utils_manage_adu_lock()
// *!   o Clear ADU Status registers, reset ADU state machine:
// *!         proc_adu_utils_reset_adu()
// *!   o Write ADU data registers to set data to be written:
// *!         proc_adu_utils_set_adu_data_registers()
// *!   o Program fabric command/address into ADU control logic & issue command
// *!         proc_adu_utils_send_fbc_op()
// *!   o Poll ADU status bits to ensure read data has arrived:
// *!         proc_adu_utils_get_adu_status()
// *!   o Clear ADU lock:
// *!         proc_adu_utils_manage_adu_lock()
// *!
// *! Additional functions are provided to:
// *!   o Check ADU lock owner:
// *!         proc_adu_utils_get_adu_lock_id()
// *!   o Manage ADU auto-increment function
// *!         proc_adu_utils_clear_adu_auto_inc()
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//
// TODO:
//   o check if ADU data register read fails when locked?
//     if not seems stray read operation can increment pointer?
//
//------------------------------------------------------------------------------

#ifndef _PROC_ADU_UTILS_H_
#define _PROC_ADU_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "proc_fbc_utils.H"
#include "p8_scom_addresses.H"

extern "C" {

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// ADU status bit comparison constants
enum proc_adu_utils_status_bit
{
    ADU_STATUS_BIT_CLEAR = 0,    // status bit is clear (=0)
    ADU_STATUS_BIT_SET = 1,      // status bit is set (=1)
    ADU_STATUS_BIT_DONT_CARE = 2 // status bit is a don't care (=0 or =1)
};

// ADU fabric operation type
enum proc_adu_utils_fbc_op_type
{
    ADU_FBC_OP_CMD_RD_ADDR_DATA = 0, // read command, address & data phase
    ADU_FBC_OP_CMD_ADDR_ONLY = 1,    // address phase only
    ADU_FBC_OP_CMD_WR_ADDR_DATA = 2  // write command, address & data phase
};

// ADU fabric init command issue policy control
enum proc_adu_utils_fbc_init_policy
{
    ADU_FBC_OP_FBC_INIT_NO_OVERRIDE = 0x0, // don't issue command if fabric
                                           // init line is low
    ADU_FBC_OP_FBC_INIT_OVERRIDE = 0x1,    // issue command even if fabric
                                           // init line is low
    ADU_FBC_OP_FBC_INIT_WAIT_LOW = 0x2     // wait until fabric init line is
                                           // low to issue command
};

// ADU supported fabric ttypes
enum proc_adu_utils_fbc_ttype
{
    ADU_FBC_OP_TTYPE_PBOP = 0x3F,     // PB operation
    ADU_FBC_OP_TTYPE_PMISC = 0x31,    // pervasive misc
    ADU_FBC_OP_TTYPE_CI_PR_W = 0x37,  // cache-inhibited partial write
    ADU_FBC_OP_TTYPE_DMA_PR_W = 0x26, // DMA partial write
    ADU_FBC_OP_TTYPE_CI_PR_RD = 0x34, // cache-inhibited partial read
    ADU_FBC_OP_TTYPE_DMA_PR_RD = 0x35 // DMA partial read
};

// ADU supported fabric tsize encodings
enum proc_adu_utils_fbc_tsize
{
    ADU_FBC_OP_TSIZE_PBOP_DIS_ALL_FP_EN = 0x08,   // pbop disable_all
                                                  // (dis command, dis data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_PBOP_EN_RCMD_FP_EN = 0x09,   // pbop enable_rcmd_only
                                                  // (en command, dis data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_PBOP_EN_DATA_FP_EN = 0x0A,   // pbop enable_data_only
                                                  // (dis command, en data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_PBOP_EN_ALL_FP_EN = 0x0B,    // pbop enable_all
                                                  // (en command, en data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_PBOP_DIS_ALL_FP_DIS = 0x00,  // pbop disable_all
                                                  // (dis command, dis data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_PBOP_EN_RCMD_FP_DIS = 0x01,  // pbop enable_rcmd_only
                                                  // (en command, dis data)
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_PBOP_EN_DATA_FP_DIS = 0x02,  // pbop enable_data_only
                                                  // (dis command, en data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_PBOP_EN_ALL_FP_DIS = 0x03,   // pbop enable_all
                                                  // (en command, en data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_FPBOP_DIS_ALL_FP_EN = 0x48,  // fpbop disable_all
                                                  // (dis command, dis data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_FPBOP_EN_RCMD_FP_EN = 0x49,  // fpbop enable_rcmd_only
                                                  // (en command, dis data)
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_FPBOP_EN_DATA_FP_EN = 0x4A,  // fpbop enable_data_only
                                                  // (dis command, en data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_FPBOP_EN_ALL_FP_EN = 0x4B,   // fpbop enable_all
                                                  // (en command, en data),
                                                  // MC fast-path enable
    ADU_FBC_OP_TSIZE_FPBOP_DIS_ALL_FP_DIS = 0x40, // fpbop disable_all
                                                  // (dis command, dis data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_FPBOP_EN_RCMD_FP_DIS = 0x41, // fpbop enable_rcmd_only
                                                  // (en command, dis data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_FPBOP_EN_DATA_FP_DIS = 0x42, // fpbop enable_data_only
                                                  // (dis command, en data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_FPBOP_EN_ALL_FP_DIS  = 0x43, // fpbop enable_all
                                                  // (en command, en data),
                                                  // MC fast-path disable
    ADU_FBC_OP_TSIZE_PMISC_SWITCH_AB = 0x01,      // pervasive misc switch AB
    ADU_FBC_OP_TSIZE_1B = 0x01,                   // one byte transfer size
    ADU_FBC_OP_TSIZE_2B = 0x02,                   // two byte transfer size
    ADU_FBC_OP_TSIZE_3B = 0x03,                   // three byte transfer size
    ADU_FBC_OP_TSIZE_4B = 0x04,                   // four byte transfer size
    ADU_FBC_OP_TSIZE_8B = 0x08,                   // eight byte transfer size
    ADU_FBC_OP_TSIZE_CI_PR_W_1B = 0x01,           // one byte transfer size
    ADU_FBC_OP_TSIZE_CI_PR_W_2B = 0x02,           // two byte transfer size
    ADU_FBC_OP_TSIZE_CI_PR_W_4B = 0x03,           // four byte transfer size
    ADU_FBC_OP_TSIZE_CI_PR_W_8B = 0x04            // eight byte transfer size
};


// ADU supported fabric priority encodings
enum proc_adu_utils_fbc_drop_priority
{
    ADU_FBC_OP_DROP_PRIORITY_LOW = 0x0, // lowest priority command request
                                        // (highest issue rate, first to be
                                        // dropped)
    ADU_FBC_OP_DROP_PRIORITY_MED = 0x1, // medium priority command request
                                        // (next highest issue rate, can be
                                        // dropped after low priority commands)
    ADU_FBC_OP_DROP_PRIORITY_HIGH = 0x2 // high priority command request
                                        // (slowest issue rate, can only be
                                        // dropped after low & medium priority
                                        // commands)
};

// ADU suppored fabric scope encodings
enum proc_adu_utils_fbc_scope
{
    ADU_FBC_OP_SCOPE_NODAL = 0x0,         // nodal scope, physical broadcast to
                                          // all units on local chip
    ADU_FBC_OP_SCOPE_GROUP = 0x1,         // group scope, physical broadcast to
                                          // all units on local physical group
    ADU_FBC_OP_SCOPE_SYSTEM = 0x2,        // system scope, physical broadcast to
                                          // all units in SMP
    ADU_FBC_OP_SCOPE_REMOTE_GROUP = 0x3,  // remote group scope, physical
                                          // broadcast to all units in remote
                                          // group
    ADU_FBC_OP_SCOPE_FOREIGN_LINK0 = 0x4, // foreign scope, physical broadcast
                                          // is all units on the local chip on
                                          // local SMP and remote chip on
                                          // remote SMP (foreign link ID 0)
    ADU_FBC_OP_SCOPE_FOREIGN_LINK1 = 0x5, // foreign scope, physical broadcast
                                          // is all units on the local chip on
                                          // local SMP and remote chip on
                                          // remote SMP (foreign link ID 1)
    ADU_FBC_OP_SCOPE_FOREIGN_LINK2 = 0x6, // foreign scope, physical broadcast
                                          // is all units on the local chip on
                                          // local SMP and remote chip on
                                          // remote SMP (foreign link ID 2)
    ADU_FBC_OP_SCOPE_FOREIGN_LINK3 = 0x7  // foreign scope, physical broadcast
                                          // is all units on the local chip on
                                          // local SMP and remote chip on
                                          // remote SMP (foreign link ID 3)
};

// ADU lock operations
enum proc_adu_utils_adu_lock_operation
{
    ADU_LOCK_ACQUIRE,       // acquire lock
    ADU_LOCK_FORCE_ACQUIRE, // acquire lock (with lock pick)
    ADU_LOCK_RELEASE        // release lock
};

// ADU fabric operation control information
struct proc_adu_utils_fbc_op {
    proc_adu_utils_fbc_ttype ttype;                 // fabric ttype
    proc_adu_utils_fbc_tsize tsize;                 // fabric tsize
    uint64_t address;                               // fabric address
    proc_adu_utils_fbc_scope scope;                 // fabric scope
    proc_adu_utils_fbc_drop_priority drop_priority; // fabric drop priority
    proc_adu_utils_fbc_op_type cmd_type;            // command type
    proc_adu_utils_fbc_init_policy init_policy;     // fabric init issue policy
    bool use_autoinc;                               // use ADU auto-increment?
};

// ADU fabric hotplug operation control information
struct proc_adu_utils_fbc_op_hp_ctl {
    bool do_tm_quiesce;          // quiesce fabric token manager prior to
                                 // issuing programmed command?
    bool do_pre_quiesce;         // send fabric quiesce command prior to
                                 // issuing programmed command?
    bool do_post_init;           // send fabric init command after issuing
                                 // programmed command
    uint32_t post_quiesce_delay; // cycle delay to pause after pre-quiesce
                                 // command (clean cresp) before issuing
                                 // programmed command
    uint32_t pre_init_delay;     // cycle delay to pause after programmed
                                 // command (clean cresp) before issuing
                                 // post-init command
};

// ADU status structure
struct proc_adu_utils_adu_status {
    proc_adu_utils_status_bit busy;             // altd_busy
    proc_adu_utils_status_bit wait_cmd_arbit;   // altd_wait_cmd_arbit
    proc_adu_utils_status_bit addr_done;        // altd_addr_done
    proc_adu_utils_status_bit data_done;        // altd_data_done
    proc_adu_utils_status_bit wait_resp;        // altd_wait_resp
    proc_adu_utils_status_bit overrun_err;      // altd_overrun_error
    proc_adu_utils_status_bit autoinc_err;      // altd_autoinc_error
    proc_adu_utils_status_bit command_err;      // altd_command_error
    proc_adu_utils_status_bit address_err;      // altd_address_error
    proc_adu_utils_status_bit command_hang_err; // altd_pb_op_hang_error
    proc_adu_utils_status_bit data_hang_err;    // altd_pb_data_hang_error
    proc_adu_utils_status_bit pbinit_missing;   // altd_pbinit_missing
};


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// ADU operation delay times for HW/sim
const uint32_t PROC_ADU_UTILS_ADU_HW_NS_DELAY = 10000;
const uint32_t PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY = 10000;

// field width definitions
const uint32_t PROC_ADU_UTILS_ADU_MAX_POST_QUIESCE_DELAY = ((1ULL << 20)-1ULL);
const uint32_t PROC_ADU_UTILS_ADU_MAX_PRE_INIT_DELAY = ((1ULL << 10)-1ULL);

// auto-increment constant definitions
const uint32_t PROC_ADU_UTILS_AUTO_INCREMENT_BOUNDARY_MASK = 0x7FFFFULL;
const uint32_t PROC_ADU_UTILS_AUTO_INCREMENT_BOUNDARY = 0x7FFF8ULL;

// ADU Control register field/bit definitions
const uint32_t ADU_CONTROL_FBC_TTYPE_START_BIT = 0;
const uint32_t ADU_CONTROL_FBC_TTYPE_END_BIT = 5;
const uint32_t ADU_CONTROL_FBC_RNW_BIT = 6;
const uint32_t ADU_CONTROL_FBC_TSIZE_START_BIT = 7;
const uint32_t ADU_CONTROL_FBC_TSIZE_END_BIT = 13;
const uint32_t ADU_CONTROL_FBC_ADDRESS_START_BIT = 14;
const uint32_t ADU_CONTROL_FBC_ADDRESS_END_BIT = 63;

const uint32_t ADU_CONTROL_FBC_ADDRESS_SPLIT_BIT = 32;
const uint32_t ADU_CONTROL_FBC_ADDRESS_SPLIT_MASK = 0xFFFFFFFFULL;

// ADU Command register field/bit definitions
const uint32_t ADU_COMMAND_START_OP_BIT = 2;
const uint32_t ADU_COMMAND_CLEAR_STATUS_BIT = 3;
const uint32_t ADU_COMMAND_RESET_BIT = 4;
const uint32_t ADU_COMMAND_ADDRESS_ONLY_BIT = 6;
const uint32_t ADU_COMMAND_LOCK_PICK_BIT = 10;
const uint32_t ADU_COMMAND_LOCKED_BIT = 11;
const uint32_t ADU_COMMAND_LOCK_ID_START_BIT = 12;
const uint32_t ADU_COMMAND_LOCK_ID_END_BIT = 15;
const uint32_t ADU_COMMAND_LOCK_ID_MAX_VALUE = 0xF;
const uint32_t ADU_COMMAND_FBC_SCOPE_START_BIT = 16;
const uint32_t ADU_COMMAND_FBC_SCOPE_END_BIT = 18;
const uint32_t ADU_COMMAND_AUTO_INC_BIT = 19;
const uint32_t ADU_COMMAND_FBC_DROP_PRIORITY_START_BIT = 20;
const uint32_t ADU_COMMAND_FBC_DROP_PRIORITY_END_BIT = 21;
const uint32_t ADU_COMMAND_FBC_INIT_OVERRIDE_BIT = 23;
const uint32_t ADU_COMMAND_FBC_INIT_WAIT_LOW_BIT = 25;
const uint32_t ADU_COMMAND_FBC_TM_QUIESCE_BIT = 26;
const uint32_t ADU_COMMAND_FBC_PRE_QUIESCE_BIT = 27;
const uint32_t ADU_COMMAND_FBC_POST_QUIESCE_COUNT_START_BIT = 28;
const uint32_t ADU_COMMAND_FBC_POST_QUIESCE_COUNT_END_BIT = 47;
const uint32_t ADU_COMMAND_FBC_PRE_INIT_COUNT_START_BIT = 50;
const uint32_t ADU_COMMAND_FBC_PRE_INIT_COUNT_END_BIT = 59;
const uint32_t ADU_COMMAND_FBC_POST_INIT_BIT = 63;

// ADU Status register field/bit definitions
const uint32_t ADU_STATUS_FBC_ALTD_BUSY_BIT = 0;
const uint32_t ADU_STATUS_FBC_ALTD_WAIT_CMD_ARBIT_BIT = 1;
const uint32_t ADU_STATUS_FBC_ALTD_ADDR_DONE_BIT = 2;
const uint32_t ADU_STATUS_FBC_ALTD_DATA_DONE_BIT = 3;
const uint32_t ADU_STATUS_FBC_ALTD_WAIT_RESP_BIT = 4;
const uint32_t ADU_STATUS_FBC_ALTD_OVERRUN_ERR_BIT = 5;
const uint32_t ADU_STATUS_FBC_ALTD_AUTOINC_ERR_BIT = 6;
const uint32_t ADU_STATUS_FBC_ALTD_COMMAND_ERR_BIT = 7;
const uint32_t ADU_STATUS_FBC_ALTD_ADDRESS_ERR_BIT = 8;
const uint32_t ADU_STATUS_FBC_ALTD_COMMAND_HANG_ERR_BIT = 9;
const uint32_t ADU_STATUS_FBC_ALTD_DATA_HANG_ERR_BIT = 10;
const uint32_t ADU_STATUS_FBC_ALTD_INIT_MISSING_BIT = 18;

// ADU Force ECC register field/bit definitions
const uint32_t ADU_FORCE_ECC_DATA_ITAG_BIT = 0;
const uint32_t ADU_FORCE_ECC_DATA_TX_ECC_HI_START_BIT = 1;
const uint32_t ADU_FORCE_ECC_DATA_TX_ECC_HI_END_BIT = 8;
const uint32_t ADU_FORCE_ECC_DATA_TX_ECC_LO_START_BIT = 9;
const uint32_t ADU_FORCE_ECC_DATA_TX_ECC_LO_END_BIT = 16;
const uint32_t ADU_FORCE_ECC_DATA_TX_ECC_OVERWRITE_BIT = 17;

// ADU Data register field/bit definitions
const uint32_t ADU_DATA_START_BIT = 0;
const uint32_t ADU_DATA_END_BIT = 63;

const uint32_t ADU_DATA_SPLIT_BIT = 32;
const uint32_t ADU_DATA_SPLIT_MASK = 0xFFFFFFFFULL;


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

// function: read ADU Command register, get ADU lock identifier
// parameters: i_target  => P8 chip target
//             o_lock_id => lock ID read
// returns: FAPI_RC_SUCCESS if SCOM read is successful,
//          else error
fapi::ReturnCode proc_adu_utils_get_adu_lock_id(
    const fapi::Target& i_target,
    uint8_t& o_lock_id);

// function: read-modify-write ADU Command register to clear auto-increment
//           mode (necessary to complete operation at 0.5M boundary)
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target => P8 chip target
// returns: FAPI_RC_SUCCESS if read-modify-write sequence is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          else error
fapi::ReturnCode proc_adu_utils_clear_adu_auto_inc(
    const fapi::Target& i_target);

// function: manipulate state of ADU atomic lock (set/pick/clear)
// parameters: i_target         => P8 chip target
//             i_lock_operation => lock operation to perform
//             i_num_attempts   => number of lock manipulation attempts to
//                                 make before giving up (will only
//                                 continue to attempt if SCOM return code
//                                 indicates failure due to lock state)
// returns: FAPI_RC_SUCCESS if lock manipulation is successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid number of attempts
//              is specified,
//          RC_PROC_ADU_UTILS_INTERNAL_ERR if an unexpected internal
//              logic error occurs,
//          else error
fapi::ReturnCode proc_adu_utils_manage_adu_lock(
    const fapi::Target& i_target,
    const proc_adu_utils_adu_lock_operation& i_lock_operation,
    const uint32_t& i_num_attempts);

// function: write ADU Command register to clear the ADU Status register and
//           reset the ADU state machine
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target => P8 chip target
// returns: FAPI_RC_SUCCESS if ADU reset is successful
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          else error
fapi::ReturnCode proc_adu_utils_reset_adu(
    const fapi::Target& i_target);

// function: initiate fabric command via writes to ADU Command & Control
//           registers
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target     => P8 chip target
//             i_adu_ctl    => struct defining fabric command type & ADU control
//                             parameters
//             i_use_hp     => perform actions specified in hotplug control
//                             argument?
//             i_adu_hp_ctl => struct defining hotplug control parameters
// returns: FAPI_RC_SUCCESS if ADU Command/Control register writes are
//              successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          RC_PROC_ADU_UTILS_INVALID_ARGS if invalid/out-of-range input
//              parameters are specified,
//          else error
fapi::ReturnCode proc_adu_utils_send_fbc_op(
    const fapi::Target& i_target,
    const proc_adu_utils_fbc_op& i_adu_ctl,
    const bool& i_use_hp,
    const proc_adu_utils_fbc_op_hp_ctl& i_adu_hp_ctl);

// function: read ADU Status register, return structure encapsulating
//           error/status bits
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target      => P8 chip target
//             o_status_act  => struct defining state of status/error bits
// returns: FAPI_RC_SUCCESS if status register read is successful,
//          else error
fapi::ReturnCode proc_adu_utils_get_adu_status(
    const fapi::Target& i_target,
    proc_adu_utils_adu_status& o_status_act);

// function: write ADU Data & Force ECC registers (to set outbound data to be
//           delivered to the fabric)
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target        => P8 chip target
//             i_write_data    => 64-bits of data to be written
//             i_override_itag => set value of itag (65th) bit?
//             i_write_itag    => value of itag (65th) bit to be written if
//                                i_override_itag=true
//             i_override_ecc  => set override ECC value?
//             i_write_ecc     => value of ECC to be written if
//                                i_override_ecc=true
// returns: FAPI_RC_SUCCESS if register writes are successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          else error
fapi::ReturnCode proc_adu_utils_set_adu_data_registers(
    const fapi::Target& i_target,
    const uint64_t& i_write_data,
    const bool& i_override_itag,
    const bool& i_write_itag,
    const bool& i_override_ecc,
    const uint8_t& i_write_ecc);

// function: read ADU Data & Force ECC registers (to get inbound data
//           delivered from the fabric)
//           NOTE: intended to be run while holding ADU lock
// parameters: i_target     => P8 chip target
//             i_get_itag   => get value of itag (65th) bit?
//             o_read_data  => 64-bits of data read
//             o_read_itag  => value of itag (65th) bit read (only valid
//                             if i_get_itag=true)
// returns: FAPI_RC_SUCCESS if register reads are successful,
//          FAPI_RC_PLAT_ERR_ADU_LOCKED if operation failed due to state of
//              ADU atomic lock,
//          else error
fapi::ReturnCode proc_adu_utils_get_adu_data_registers(
    const fapi::Target& i_target,
    const bool& i_get_itag,
    uint64_t& o_read_data,
    bool& o_read_itag);

} // extern "C"

#endif // _PROC_ADU_UTILS_H_
