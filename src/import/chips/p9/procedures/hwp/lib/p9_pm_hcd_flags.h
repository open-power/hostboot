/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pm_hcd_flags.h $    */
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
///
/// @file  p9_pm_hcode_flags.h
/// @brief Hocde defined flag register structures
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS:HCD
///
///-----------------------------------------------------------------------------

#ifndef _P9_PM_HCDFLAGS_H_
#define _P9_PM_HCDFLAGS_H_

#ifndef __PPE_PLAT
namespace p9hcd
{
#endif

//Enum form of OCC FLAGs.
enum PM_GPE_OCCFLG_DEFS
{
    PGPE_PSTATE_PROTOCOL_STOP               = 0,
    PGPE_PSTATE_PROTOCOL_AUTO_ACTIVATE      = 1,
    PGPE_PSTATE_PROTOCOL_ACTIVATE           = 1,  // @todo PGPE Hcode dependencies
    PGPE_SAFE_MODE                          = 2,
    PM_COMPLEX_SUSPEND                      = 3,
    PGPE_PROLONGED_DROOP_WORKAROUND_ACTIVE  = 7,
    SGPE_ACTIVE                             = 8,
    SGPE_IGNORE_STOP_CONTROL                = 9,
    SGPE_IGNORE_STOP_ACTION                 = 10,
    SGPE_IGNORE_STOP_EXITS                  = 11,
    SGPE_IGNORE_STOP_ENTRIES                = 12,
    AUX_THREAD_ACTIVATE                     = 14,
    AUX_THREAD_ACTIVE                       = 15,
    PIB_I2C_MASTER_ENGINE_1_LOCK_BIT0       = 16, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_1_LOCK_BIT1       = 17, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_2_LOCK_BIT0       = 18, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_2_LOCK_BIT1       = 19, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_3_LOCK_BIT0       = 20, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_3_LOCK_BIT1       = 21, //BIT0 ored BIT1 gives the field
    PGPE_OCS_DIRTY                          = 26,
    PGPE_PM_RESET_SUPPRESS                  = 27,
    WOF_HCODE_MODE_BIT0                     = 28,
    WOF_HCODE_MODE_BIT1                     = 29,
    REQUESTED_ACTIVE_QUAD_UPDATE            = 30,
    REQUEST_OCC_SAFE_STATE                  = 31
};

//Enum form of OCC FLAG2.
enum PM_GPE_OCCFLG2_DEFS
{
    OCCFLG2_DEAD_CORES_START                = 0,
    OCCFLG2_DEAD_CORES_LENGTH               = 24,
    OCCFLG2_ENABLE_PRODUCE_WOF_VALUES       = 24,
    OCCFLG2_PGPE_HCODE_FIT_ERR_INJ          = 27,
    PM_CALLOUT_ACTIVE                       = 28,
    STOP_RECOVERY_TRIGGER_ENABLE            = 29,
    OCCFLG2_SGPE_HCODE_STOP_REQ_ERR_INJ     = 30,
    OCCFLG2_PGPE_HCODE_PSTATE_REQ_ERR_INJ   = 31
};

//
//Enum form of OCC SCRATCH2.
//
enum PM_GPE_OCC_SCRATCH2_DEFS
{
    PGPE_ACTIVE                             = 0,
    PGPE_PSTATE_PROTOCOL_ACTIVE             = 1,
    PGPE_SAFE_MODE_ACTIVE                   = 2,
    PM_COMPLEX_SUSPENDED                    = 3,
    SPGE_DEBUG_TRAP_ENABLE                  = 8,
    CME_DEBUG_TRAP_ENABLE                   = 9,
    PGPE_DEBUG_TRAP_ENABLE                  = 10,
    L3_CONTAINED_MODE                       = 11,
    PGPE_SAFE_MODE_ERROR                    = 14,
    PM_DEBUG_HALT_ENABLE                    = 15,
    CORE_THROTTLE_CONTINUOUS_CHANGE_ENABLE  = 16,
    PGPE_OP_TRACE_DISABLE                   = 24,
    PGPE_OP_TRACE_MEM_MODE                  = 25

};

//
//Enum form of CME_FLAGS
//
enum PM_CME_FLAGS_DEFS
{
    CME_FLAGS_STOP_READY                                = 0,
    CME_FLAGS_PMCR_READY                                = 1,
    CME_FLAGS_QMGR_READY                                = 2,
    CME_FLAGS_QMGR_MASTER                               = 3,
    CME_FLAGS_RCLK_OPERABLE                             = 4,
    CME_FLAGS_IVRM_OPERABLE                             = 5,
    CME_FLAGS_VDM_OPERABLE                              = 6,
    CME_FLAGS_PGPE_HB_LOSS_SAFE_MODE                    = 7,
    CME_FLAGS_STOP_BLOCK_EXIT_C0                        = 8,
    CME_FLAGS_STOP_BLOCK_EXIT_C1                        = 9,
    CME_FLAGS_STOP_BLOCK_ENTRY_C0                       = 10,
    CME_FLAGS_STOP_BLOCK_ENTRY_C1                       = 11,
    CME_FLAGS_CORE_QUIESCE_ACTIVE                       = 12,
    CME_FLAGS_PM_DEBUG_HALT_ENABLE                      = 13,
    CME_FLAGS_DROOP_SUSPEND_ENTRY                       = 14,
    CME_FLAGS_SAFE_MODE                                 = 16,
    CME_FLAGS_PSTATES_SUSPENDED                         = 17,
    CME_FLAGS_DB0_COMM_RECV_STARVATION_CNT_ENABLED      = 18,
    CME_FLAGS_SPWU_CHECK_ENABLE                         = 22,
    CME_FLAGS_BLOCK_ENTRY_STOP11                        = 23,
    CME_FLAGS_PSTATES_ENABLED                           = 24,
    CME_FLAGS_FREQ_UPDT_DISABLE                         = 25,
    CME_FLAGS_EX_ID                                     = 26,
    CME_FLAGS_SIBLING_FUNCTIONAL                        = 27,
    CME_FLAGS_STOP_ENTRY_FIRST_C0                       = 28,
    CME_FLAGS_STOP_ENTRY_FIRST_C1                       = 29,
    CME_FLAGS_CORE0_GOOD                                = 30,
    CME_FLAGS_CORE1_GOOD                                = 31
};

//
//Enum form of CME_SCRATCH_
//
enum PM_CME_SCRATCH_DEFS
{
    CME_SCRATCH_DB0_PROCESSING_ENABLE       = 25,
    CME_SCRATCH_LOCAL_PSTATE_IDX_START      = 26,
    CME_SCRATCH_LOCAL_PSTATE_IDX_LENGTH     = 6
};


//
//Enum form of CPPM_CSAR
//
enum PM_CPPM_CSAR_DEFS
{
    CPPM_CSAR_PGPE_ACK_FOR_NACK_ON_PROLONGED_DROOP_W_CSAR_SET  = 26,
    CPPM_CSAR_FIT_HCODE_ERROR_INJECT                = 27,
    CPPM_CSAR_ENABLE_PSTATE_REGISTRATION_INTERLOCK  = 28,
    CPPM_CSAR_DISABLE_CME_NACK_ON_PROLONGED_DROOP   = 29,
    CPPM_CSAR_PSTATE_HCODE_ERROR_INJECT             = 30,
    CPPM_CSAR_STOP_HCODE_ERROR_INJECT               = 31
};

//
//Enum for of PPM Register Bits for FW Usage
//
enum PM_PPM_FW_FLAGS
{
    CPPM_CPMMR_DISABLE_PERIODIC_CORE_QUIESCE = 2,
    CPPM_CPMMR_RUNTIME_WAKEUP_MODE           = 3,
    CPPM_CPMMR_WAKEUP_ERROR_INJECT_MODE      = 8,
    QPPM_QCCR_IGNORE_QUAD_STOP_EXITS        = 10,
    QPPM_QCCR_IGNORE_QUAD_STOP_ENTRIES      = 11
};

#ifndef __PPE_PLAT
} //End p9hcd namespace
#endif

#endif // _P9_PM_HCDFLAGS_H_
