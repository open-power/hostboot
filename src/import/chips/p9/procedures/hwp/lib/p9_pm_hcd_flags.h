/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pm_hcd_flags.h $    */
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

//OCC FLag defines
typedef union occ_flags
{
    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t high_order;
        uint16_t low_order;
#else
        uint16_t low_order;
        uint16_t high_order;
#endif // _BIG_ENDIAN
    } halfwords;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t  pgpe_StartNonStop                 : 1;
        uint32_t  pgpe_PStateProtocolAutoActivate   : 1;
        uint32_t  pgpe_PStateSafeMode               : 1;
        uint32_t  pm_ComplexSuspend                 : 1;
        uint32_t  reserved1                         : 4;
        uint32_t  sgpe_Active                       : 1;
        uint32_t  sgpe_IgnoreStopExits              : 1;
        uint32_t  sgpe_IgnoreStopEntry              : 1;
        uint32_t  sgpe_StopExitsIgnored             : 1;
        uint32_t  sgpe_StopEntryIgnored             : 1;
        uint32_t  reserved2                         : 1;
        uint32_t  sgpe_Aux_Activate                 : 1;
        uint32_t  sgpe_Aux_Active                   : 1;
        uint32_t  pib_I2CMasterEngine1Lock          : 2;
        uint32_t  pib_I2CMasterEngine2Lock          : 2;
        uint32_t  pib_I2CMasterEngine3Lock          : 2;
        uint32_t  undefined                         : 8;
        uint32_t  requested_ActiveQuadUpdate        : 1;
        uint32_t  requested_OccSafeState            : 1;
#else
        uint32_t  requested_OccSafeState            : 1;
        uint32_t  requested_ActiveQuadUpdate        : 1;
        uint32_t  undefined                         : 8;
        uint32_t  pib_I2CMasterEngine3Lock          : 2;
        uint32_t  pib_I2CMasterEngine2Lock          : 2;
        uint32_t  pib_I2CMasterEngine1Lock          : 2;
        uint32_t  sgpe_Aux_Active                   : 1;
        uint32_t  sgpe_Aux_Activate                 : 1;
        uint32_t  reserved2                         : 1;
        uint32_t  sgpe_StopEntryIgnored             : 1;
        uint32_t  sgpe_StopExitsIgnored             : 1;
        uint32_t  sgpe_IgnoreStopEntry              : 1;
        uint32_t  sgpe_IgnoreStopExits              : 1;
        uint32_t  sgpe_Active                       : 1;
        uint32_t  reserved1                         : 4;
        uint32_t  pm_ComplexSuspend                 : 1;
        uint32_t  pgpe_PStateSafeMode               : 1;
        uint32_t  pgpe_PStateProtocolAutoActivate   : 1;
        uint32_t  pgpe_StartNonStop                 : 1;
#endif // _BIG_ENDIAN
    } fields;
} occ_flags_t;

typedef union pgpe_flags
{
    uint16_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t  resclk_enable                     : 1;
        uint16_t  ivrm_enable                       : 1;
        uint16_t  vdm_enable                        : 1;
        uint16_t  wof_enable                        : 1;
        uint16_t  dpll_dynamic_fmax_enable          : 1;
        uint16_t  dpll_dynamic_fmin_enable          : 1;
        uint16_t  dpll_droop_protect_enable         : 1;
        uint16_t  reserved7                         : 1;
        uint16_t  occ_ipc_immed_response            : 1;
        uint16_t  wof_ipc_immed_response            : 1;
        uint16_t  enable_fratio                     : 1;
        uint16_t  enable_vratio                     : 1;
        uint16_t  vratio_modifier                   : 1;
        uint16_t  reserved_13_15                    : 3;
#else
        uint16_t  reserved_13_15                    : 3;
        uint16_t  vratio_modifier                   : 1;
        uint16_t  enable_vratio                     : 1;
        uint16_t  enable_fratio                     : 1;
        uint16_t  wof_ipc_immed_response            : 1;
        uint16_t  occ_ipc_immed_response            : 1;
        uint16_t  reserved7                         : 1;
        uint16_t  dpll_droop_protect_enable         : 1;
        uint16_t  dpll_dynamic_fmin_enable          : 1;
        uint16_t  dpll_dynamic_fmax_enable          : 1;
        uint16_t  wof_enable                        : 1;
        uint16_t  vdm_enable                        : 1;
        uint16_t  ivrm_enable                       : 1;
        uint16_t  resclk_enable                     : 1;
#endif
    } fields;
} pgpe_flags_t;


#ifndef __PPE_PLAT
namespace p9hcd
{
#endif

//Enum form of CME FLAGs.
enum PM_CME_CMEFLG_DEFS
{
    CME_STOP_READY                      = 0,
    CME_PMCR_READY                      = 1,
    CME_QMGR_READY                      = 2,
    CME_QMGR_MASTER                     = 3,
    CME_RCLK_OPERABLE                   = 4,
    CME_IVRM_OPERABLE                   = 5,
    CME_VDM_OPERABLE                    = 6,
    CME_OCC_HB_SAFE_MODE                = 7,
    CME_BLOCK_STOP_EXIT_ENABLED_C0      = 8,
    CME_BLOCK_STOP_EXIT_ENABLED_C1      = 9,
    CME_BLOCK_STOP_ENTRY_ENABLED_C0     = 10,
    CME_BLOCK_STOP_ENTRY_ENABLED_C1     = 11,
    // Reserve 12:24
    CME_FREQ_UPDATE_DISABLE             = 25,
    CME_EX_ID                           = 26,
    CME_SIBLING_FUNCTIONAL              = 27,
    CME_STOP_ENTRY_FIRST_C0             = 28,
    CME_STOP_ENTRY_FIRST_C1             = 29,
    CME_CORE0_GOOD                      = 30,
    CME_CORE1_GOOD                      = 31
};

//Enum form of OCC FLAGs.
enum PM_GPE_OCCFLG_DEFS
{
    PGPE_START_NOT_STOP                 = 0,
    PGPE_PSTATE_PROTOCOL_AUTO_ACTIVATE  = 1,
    PGPE_PSTATE_PROTOCOL_ACTIVATE       = 1,  // @todo PGPE Hcode dependencies
    PGPE_SAFE_MODE                      = 2,
    PM_COMPLEX_SUSPEND                  = 3,
    SGPE_ACTIVE                         = 8,
    SGPE_IGNORE_STOP_CONTROL            = 9,
    SGPE_IGNORE_STOP_ACTION             = 10,
    SGPE_IGNORE_STOP_EXITS              = 11,
    SGPE_IGNORE_STOP_ENTRIES            = 12,
    OCCFLG_CORE_QUIESCE_WORKARND_DIS    = 13,
    SGPE_24_7_ACTIVATE                  = 14,
    SGPE_24_7_ACTIVE                    = 15,
    PIB_I2C_MASTER_ENGINE_1_LOCK_BIT0   = 16, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_1_LOCK_BIT1   = 17, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_2_LOCK_BIT0   = 18, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_2_LOCK_BIT1   = 19, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_3_LOCK_BIT0   = 20, //BIT0 ored BIT1 gives the field
    PIB_I2C_MASTER_ENGINE_3_LOCK_BIT1   = 21, //BIT0 ored BIT1 gives the field
    REQUESTED_ACTIVE_QUAD_UPDATE        = 30,
    REQUEST_OCC_SAFE_STATE              = 31
};

//
//Enum form of OCC SCRATCH2.
//
enum PM_GPE_OCC_SCRATCH2_DEFS
{
    PGPE_ACTIVE                                 = 0,
    PGPE_PSTATE_PROTOCOL_ACTIVE                 = 1,
    PGPE_SAFE_MODE_ACTIVE                       = 2,
    PM_COMPLEX_SUSPENDED                        = 3,
    SPGE_DEBUG_TRAP_ENABLE                      = 8,
    CME_DEBUG_TRAP_ENABLE                       = 9,
    PGPE_DEBUG_TRAP_ENABLE                      = 10,
    L3_CONTAINED_MODE                           = 11,
    PGPE_SAFE_MODE_ERROR                        = 12
};

//
//Enum form of CME_FLAGS
//
enum PM_CME_FLAGS_DEFS
{
    CME_FLAGS_STOP_READY                    = 0,
    CME_FLAGS_PMCR_READY                    = 1,
    CME_FLAGS_QMGR_READY                    = 2,
    CME_FLAGS_QMGR_MASTER                   = 3,
    CME_FLAGS_RCLK_OPERABLE                 = 4,
    CME_FLAGS_IVRM_OPERABLE                 = 5,
    CME_FLAGS_VDM_OPERABLE                  = 6,
    CME_FLAGS_OCC_HB_SAFE_MODE              = 7,
    CME_FLAGS_BLOCK_WKUP_C0                 = 8,
    CME_FLAGS_BLOCK_WKUP_C1                 = 9,
    CME_CORE_QUIESCE_WORKARND_DIS           = 23,
    CME_FLAGS_PSTATES_ENABLED               = 24,
    CME_FLAGS_FREQ_UPDT_DISABLE             = 25,
    CME_FLAGS_EX_ID                         = 26,
    CME_FLAGS_SIBLING_FUNCTIONAL            = 27,
    CME_FLAGS_STOP_ENTRY_FIRST_C0           = 28,
    CME_FLAGS_STOP_ENTRY_FIRST_C1           = 29,
    CME_FLAGS_CORE0_GOOD                    = 30,
    CME_FLAGS_CORE1_GOOD                    = 31
};

//
//Enum form of CME_SCRATCH_
//
enum PM_CME_SCRATCH_DEFS
{
    CME_SCRATCH_LOCAL_PSTATE_IDX_START       = 26,
    CME_SCRATCH_LOCAL_PSTATE_IDX_LENGTH      = 6
};


//
//Enum for of PGPE_HEADER_FLAGS
//
enum PM_PGPE_HEADER_FLAGS
{
    PGPE_HEADER_FLAGS_RESCLK_ENABLE                 = 0,
    PGPE_HEADER_FLAGS_IVRM_ENABLE                   = 1,
    PGPE_HEADER_FLAGS_VDM_ENABLE                    = 2,
    PGPE_HEADER_FLAGS_WOF_ENABLE                    = 3,
    PGPE_HEADER_FLAGS_DPLL_DYNAMIC_FMAX_ENABLE      = 4,
    PGPE_HEADER_FLAGS_DPLL_DYNAMIC_FMIN_ENABLE      = 5,
    PGPE_HEADER_FLAGS_DPLL_DROOP_PROTECT_ENABLE     = 6,
    PGPE_HEADER_FLAGS_OCC_IPC_IMMEDIATE_MODE        = 8,
    PGPE_HEADER_FLAGS_WOF_IPC_IMMEDIATE_MODE        = 9,
    PGPE_HEADER_FLAGS_ENABLE_FRATIO                 = 10,
    PGPE_HEADER_FLAGS_ENABLE_VRATIO                 = 11,
    PGPE_HEADER_FLAGS_VRATIO_MODIFIER               = 12
};

#ifndef __PPE_PLAT
} //End p9hcd namespace
#endif

#endif // _P9_PM_HCDFLAGS_H_
