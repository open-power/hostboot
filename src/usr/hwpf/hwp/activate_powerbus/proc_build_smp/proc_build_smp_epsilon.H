/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_epsilon.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_build_smp_epsilon.H,v 1.2 2012/09/05 03:11:55 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_epsilon.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_epsilon.H
// *! DESCRIPTION : Epsilon calculation/application functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_EPSILON_H_
#define _PROC_BUILD_SMP_EPSILON_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_build_smp.H"


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// table of base epsilon values
//

const uint32_t PROC_BUILD_SMP_EPSILON_MIN_VALUE = 0x1;
const uint32_t PROC_BUILD_SMP_EPSILON_MAX_VALUE = 0xFFFFFFFF;

const uint32_t PROC_BUILD_SMP_EPSILON_R_T0_HE[] = {    6,    6,    7,    8,    9,   17 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T1_HE[] = {   42,   44,   46,   49,   53,   75 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T2_HE[] = {   85,   87,   89,   92,   96,  118 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_F_HE[]  = {   57,   59,   61,   64,   68,   90 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_HE[]    = {   30,   31,   31,   32,   34,   41 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_F_HE[]  = {   13,   13,   14,   15,   16,   23 };
const uint32_t PROC_BUILD_SMP_EPSILON_P_HE[]    = {  925, 1605, 1605, 1605, 1605, 1605 };

const uint32_t PROC_BUILD_SMP_EPSILON_R_T0_LE[] = {    6,    6,    7,    8,    9,   17 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T1_LE[] = {    6,    6,    7,    8,    9,   17 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T2_LE[] = {   62,   63,   65,   68,   73,   94 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_F_LE[]  = {   57,   59,   61,   64,   68,   90 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_LE[]    = {    3,    3,    4,    5,    6,   14 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_F_LE[]  = {   13,   13,   14,   15,   16,   23 };
const uint32_t PROC_BUILD_SMP_EPSILON_P_LE[]    = {  925, 1605, 1605, 1605, 1605, 1605 };


//
// unit specific epsilon range constants
//

// L2
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T0 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T1 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T2 = 2048;
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_W_T2 = 128;

const uint8_t  PROC_BUILD_SMP_EPSILON_L2_FORCE_T2 = 0x1;

// L3
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T0 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T1 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T2 = 2048;
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_W_T2 = 128;

const uint8_t  PROC_BUILD_SMP_EPSILON_L3_FORCE_T2 = 0x1;

// MCS
const uint32_t PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_T0 = 1016;
const uint32_t PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_T1 = 1016;
const uint32_t PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_T2 = 1016;
const uint32_t PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_F  = 1016;

const uint8_t  PROC_BUILD_SMP_EPSILON_MCS_JITTER = 0x1;

// NX
const uint32_t PROC_BUILD_SMP_EPSILON_NX_MAX_VALUE_W_T2 = 448;

// HCA
const uint32_t PROC_BUILD_SMP_EPSILON_HCA_MAX_VALUE_W_T2 = 512;

// CAPP
const uint32_t PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T0 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T1 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T2 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_W_T2 = 128;

const uint32_t PROC_BUILD_SMP_EPSILON_CAPP_FORCE_T2 = 0x1;

// MCD
const uint32_t PROC_BUILD_SMP_EPSILON_MCD_MAX_VALUE_P = 65520;


//
// unit specific register field/bit definition constants
//

// MCS MCEPS register field/bit definitions
const uint32_t MCEPS_JITTER_EPSILON_START_BIT = 0;
const uint32_t MCEPS_JITTER_EPSILON_END_BIT = 7;
const uint32_t MCEPS_NODAL_EPSILON_START_BIT = 8;
const uint32_t MCEPS_NODAL_EPSILON_END_BIT = 15;
const uint32_t MCEPS_GROUP_EPSILON_START_BIT = 16;
const uint32_t MCEPS_GROUP_EPSILON_END_BIT = 23;
const uint32_t MCEPS_SYSTEM_EPSILON_START_BIT = 24;
const uint32_t MCEPS_SYSTEM_EPSILON_END_BIT = 31;
const uint32_t MCEPS_FOREIGN_EPSILON_START_BIT = 32;
const uint32_t MCEPS_FOREIGN_EPSILON_END_BIT = 39;

// NX CQ Epsilon Scale register field/bit definitions
const uint32_t NX_CQ_EPSILON_SCALE_EPSILON_START_BIT = 0;
const uint32_t NX_CQ_EPSILON_SCALE_EPSILON_END_BIT = 5;

// HCA Mode register field/bit definitions
const uint32_t HCA_MODE_EPSILON_START_BIT = 21;
const uint32_t HCA_MODE_EPSILON_END_BIT = 29;

// CAPP CXA Snoop Control register field/bit definitions
const uint32_t CAPP_CXA_SNP_READ_EPSILON_TIER0_START_BIT = 3;
const uint32_t CAPP_CXA_SNP_READ_EPSILON_TIER0_END_BIT = 11;
const uint32_t CAPP_CXA_SNP_READ_EPSILON_TIER1_START_BIT = 15;
const uint32_t CAPP_CXA_SNP_READ_EPSILON_TIER1_END_BIT = 23;
const uint32_t CAPP_CXA_SNP_READ_EPSILON_TIER2_START_BIT = 25;
const uint32_t CAPP_CXA_SNP_READ_EPSILON_TIER2_END_BIT = 35;
const uint32_t CAPP_CXA_SNP_READ_EPSILON_MODE_BIT = 0;

// CAPP APC Master PB Control register field/bit definitions
const uint32_t CAPP_APC_MASTER_CONTROL_EPSILON_START_BIT = 39;
const uint32_t CAPP_APC_MASTER_CONTROL_EPSILON_END_BIT = 45;

// MCD Recovery Pre Epsilon Configuration register field/bit definitions
const uint32_t MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_START_BIT = 52;
const uint32_t MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_END_BIT = 63;

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: utility function to round to ceiling
// parameters: i_n => numerator
//             i_d => denominator
// returns: ceiling of i_n / i_d (integer)
//------------------------------------------------------------------------------
uint32_t proc_build_smp_round_ceiling(
    uint32_t i_n,
    uint32_t i_d);


//------------------------------------------------------------------------------
// function: set target epsilon values into system attributes/HW
// parameters: i_smp => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if application is successful
//          RC_PROC_BUILD_SMP_EPSILON_INVALID_TABLE_ERR if invalid epsilon
//              table type/content is detected,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons(
    proc_build_smp_system & i_smp);

} // extern "C"

#endif // _PROC_BUILD_SMP_EPSILON_H_
