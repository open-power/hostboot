/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_2.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_c_2_H_
#define __p10_scom_c_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [EC_PC_THRCTL_TCTLCOM_HOLD_OUT]
static const uint64_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT = 0x20020455ull;

static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT = 0;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT = 1;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT = 2;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT = 3;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT = 4;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT = 5;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT = 6;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 9;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT = 10;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT = 11;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT = 12;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT = 13;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT = 14;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT = 15;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT = 16;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT = 17;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT = 19;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 20;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT = 21;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT = 22;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT = 23;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT = 24;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT = 25;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT = 26;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT = 27;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT = 28;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT = 30;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 31;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT = 32;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT = 33;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT = 34;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT = 35;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT = 36;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT = 37;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT = 38;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT = 39;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT = 41;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 42;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT = 43;
//<< [EC_PC_THRCTL_TCTLCOM_HOLD_OUT]
// c/reg00002.H

//>> [L2_L2MISC_L2CERRS_TOPOTABLE3]
static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE3 = 0x20020017ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN = 4;
//<< [L2_L2MISC_L2CERRS_TOPOTABLE3]
// c/reg00002.H

//>> [L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]
static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD = 0x20010625ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN = 4;
//<< [L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD]
// c/reg00002.H

//>> [NC_NCCHTM_NCCHTSC_HTM_MODE]
static const uint64_t NC_NCCHTM_NCCHTSC_HTM_MODE = 0x20010680ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY = 17;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP = 18;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES = 19;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET = 24;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN = 8;
//<< [NC_NCCHTM_NCCHTSC_HTM_MODE]
// c/reg00002.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00002.H"
#endif
#endif
