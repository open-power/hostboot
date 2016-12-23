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
        uint32_t  pgpe_StartNonStop             : 1;
        uint32_t  pgpe_PStateProtocolActivate   : 1;
        uint32_t  pgpe_PStateSafeMode           : 1;
        uint32_t  pm_ComplexSuspend             : 1;
        uint32_t  reserved1                     : 4;
        uint32_t  sgpe_Active                   : 1;
        uint32_t  sgpe_IgnoreStopExits          : 1;
        uint32_t  sgpe_IgnoreStopEntry          : 1;
        uint32_t  sgpe_StopExitsIgnored         : 1;
        uint32_t  sgpe_StopEntryIgnored         : 1;
        uint32_t  reserved2                     : 1;
        uint32_t  sgpe_Aux_Activate             : 1;
        uint32_t  sgpe_Aux_Active               : 1;
        uint32_t  pib_I2CMasterEngine1Lock      : 2;
        uint32_t  pib_I2CMasterEngine2Lock      : 2;
        uint32_t  pib_I2CMasterEngine3Lock      : 2;
        uint32_t  undefined                     : 8;
        uint32_t  requested_ActiveQuadUpdate    : 1;
        uint32_t  requested_OccSafeState        : 1;
#else
        uint32_t  requested_OccSafeState        : 1;
        uint32_t  requested_ActiveQuadUpdate    : 1;
        uint32_t  undefined                     : 8;
        uint32_t  pib_I2CMasterEngine3Lock      : 2;
        uint32_t  pib_I2CMasterEngine2Lock      : 2;
        uint32_t  pib_I2CMasterEngine1Lock      : 2;
        uint32_t  sgpe_Aux_Active               : 1;
        uint32_t  sgpe_Aux_Activate             : 1;
        uint32_t  reserved2                     : 1;
        uint32_t  sgpe_StopEntryIgnored         : 1;
        uint32_t  sgpe_StopExitsIgnored         : 1;
        uint32_t  sgpe_IgnoreStopEntry          : 1;
        uint32_t  sgpe_IgnoreStopExits          : 1;
        uint32_t  sgpe_Active                   : 1;
        uint32_t  reserved1                     : 4;
        uint32_t  pm_ComplexSuspend             : 1;
        uint32_t  pgpe_PStateSafeMode           : 1;
        uint32_t  pgpe_PStateProtocolActivate   : 1;
        uint32_t  pgpe_StartNonStop             : 1;
#endif // _BIG_ENDIAN
    } fields;
} occ_flags_t;



//
//OCC SCRATCH2 defines
//
typedef union occ_scratch2
{
    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pgpe_active                    : 1;
        uint32_t pgpe_pstate_protocol_active    : 1;
        uint32_t pgpe_safe_mode                 : 1;
        uint32_t pm_complex_suspended           : 1;
        uint32_t reserved0                      : 4;
        uint32_t sgpe_debug_trap_enable         : 1;
        uint32_t cme_debug_trap_enable          : 1;
        uint32_t pgpe_debug_trap_enable         : 1;
        uint32_t l3_contained_mode              : 1;
        uint32_t reserved1                      : 20;
#else
        uint32_t reserved1                      : 20;
        uint32_t l3_contained_mode              : 1;
        uint32_t pgpe_debug_trap_enable         : 1;
        uint32_t cme_debug_trap_enable          : 1;
        uint32_t sgpe_debug_trap_enable         : 1;
        uint32_t reserved0                      : 4;
        uint32_t pm_complex_suspended           : 1;
        uint32_t pgpe_safe_mode                 : 1;
        uint32_t pgpe_pstate_protocol_active    : 1;
        uint32_t pgpe_active                    : 1;
#endif
    } fields;
} occ_scratch2_t;

typedef union pgpe_flags
{
    uint16_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t  resclk_enable                 : 1;
        uint16_t  ivrm_enable                   : 1;
        uint16_t  vdm_enable                    : 1;
        uint16_t  wof_enable                    : 1;
        uint16_t  dpll_dynamic_fmax_enable      : 1;
        uint16_t  dpll_dynamic_fmin_enable      : 1;
        uint16_t  dpll_droop_protect_enable     : 1;
        uint16_t  reserved7                     : 1;
        uint16_t  occ_ipc_immed_response        : 1;
        uint16_t  reserved_9_15                 : 7;
#else
        uint16_t  reserved_9_15                 : 7;
        uint16_t  occ_ipc_immed_response        : 1;
        uint16_t  reserved7                     : 1;
        uint16_t  dpll_droop_protect_enable     : 1;
        uint16_t  dpll_dynamic_fmin_enable      : 1;
        uint16_t  dpll_dynamic_fmax_enable      : 1;
        uint16_t  wof_enable                    : 1;
        uint16_t  vdm_enable                    : 1;
        uint16_t  ivrm_enable                   : 1;
        uint16_t  resclk_enable                 : 1;
#endif
    } fields;
} pgpe_flags_t;

typedef union cme_flags
{
    uint32_t value;
    struct
    {
        uint32_t  stop_ready                    : 1;
        uint32_t  PStatePMCRReady               : 1;
        uint32_t  PStateQuadMgrReady            : 1;
        uint32_t  PStateQuadMgrMaster           : 1;
        uint32_t  ResonantClockOperable         : 1;
        uint32_t  iVRMsOperable                 : 1;
        uint32_t  VDMsOperable                  : 1;
        uint32_t  OCCHBSafeModeEngaged          : 1;
        uint32_t  reserved_8_27                 : 20;
        uint32_t  STOPEntryFirst0               : 1;
        uint32_t  STOPEntryFirst1               : 1;
        uint32_t  Core0Good                     : 1;
        uint32_t  Core1Good                     : 1;
    } fields;
} cme_flags_t;

#ifndef __PPE_PLAT
namespace p9hcd
{
#endif

//Enum form of OCC FLAGs.
enum PM_GPE_OCCFLG_DEFS
{
    PGPE_START_NOT_STOP                 = 0,
    PGPE_PSTATE_PROTOCOL_ACTIVATE       = 1,
    PGPE_SAFE_MODE                      = 2,
    PM_COMPLEX_SUSPEND                  = 3,
    SGPE_ACTIVE                         = 8,
    SGPE_IGNORE_STOP_EXITS              = 9,
    SGPE_IGNORE_STOP_ENTRY              = 10,
    SGPE_STOP_EXITS_IGNORED             = 11,
    SGPE_STOP_ENTRIES_IGNORED           = 12,
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
    L3_CONTAINED_MODE                           = 11
};

#ifndef __PPE_PLAT
} //End p9hcd namespace
#endif

#endif // _P9_PM_HCDFLAGS_H_
