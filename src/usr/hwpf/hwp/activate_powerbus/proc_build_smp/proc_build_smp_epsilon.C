/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_epsilon.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_build_smp_epsilon.C,v 1.11 2014/03/06 17:42:24 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_epsilon.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_build_smp_epsilon.C
// *! DESCRIPTION : Epsilon calculation/application functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp_epsilon.H>

extern "C" {


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// table of base epsilon values
//

const uint32_t PROC_BUILD_SMP_EPSILON_MIN_VALUE = 0x1;
const uint32_t PROC_BUILD_SMP_EPSILON_MAX_VALUE = 0xFFFFFFFF;

// HE epsilon (4 chips per-group)
const uint32_t PROC_BUILD_SMP_EPSILON_R_T0_HE[] = {    6,    6,    7,    8,    9,   15 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T1_HE[] = {   56,   58,   60,   62,   65,   84 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T2_HE[] = {  102,  104,  105,  108,  111,  130 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_F_HE[]  = {   66,   67,   69,   71,   75,   93 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_HE[]    = {   46,   47,   47,   48,   50,   55 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_F_HE[]  = {   37,   38,   39,   40,   40,   46 };

// LE epsilon (2 chips per-group)
const uint32_t PROC_BUILD_SMP_EPSILON_R_T0_LE[] = {    6,    6,    7,    8,    9,   15 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T1_LE[] = {   47,   49,   50,   53,   56,   75 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T2_LE[] = {   93,   95,   96,   99,  102,  120 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_F_LE[]  = {   66,   67,   69,   71,   75,   93 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_LE[]    = {   46,   47,   47,   48,   50,   55 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_F_LE[]  = {   37,   38,   39,   40,   40,   46 };

// Stradale epsilon (1 chip per-group)
const uint32_t PROC_BUILD_SMP_EPSILON_R_T0_1S[] = {    6,    6,    7,    8,    9,   15 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T1_1S[] = {    6,    6,    7,    8,    9,   15 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_T2_1S[] = {   63,   64,   65,   68,   72,   90 };
const uint32_t PROC_BUILD_SMP_EPSILON_R_F_1S[]  = {   66,   67,   69,   71,   75,   93 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_1S[]    = {   14,   14,   15,   15,   16,   23 };
const uint32_t PROC_BUILD_SMP_EPSILON_W_F_1S[]  = {   37,   38,   39,   40,   40,   46 };


//
// unit specific epsilon range constants
//

enum proc_build_smp_epsilon_unit
{
    PROC_BUILD_SMP_EPSILON_UNIT_L2_R_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_L2_W_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_L2_R_T0,
    PROC_BUILD_SMP_EPSILON_UNIT_L2_R_T1,
    PROC_BUILD_SMP_EPSILON_UNIT_L3_R_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_L3_W_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_L3_R_T0,
    PROC_BUILD_SMP_EPSILON_UNIT_L3_R_T1,
    PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_T0,
    PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_T1,
    PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_F,
    PROC_BUILD_SMP_EPSILON_UNIT_NX_W_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_HCA_W_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_CAPP_R_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_CAPP_W_T2,
    PROC_BUILD_SMP_EPSILON_UNIT_CAPP_R_T0,
    PROC_BUILD_SMP_EPSILON_UNIT_CAPP_R_T1,
    PROC_BUILD_SMP_EPSILON_UNIT_MCD_P
};

// L2
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T0 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T1 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T2 = 2048;
const uint32_t PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_W_T2 = 128;

// L3
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T0 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T1 = 512;
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T2 = 2048;
const uint32_t PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_W_T2 = 128;

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


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: utility function to round to ceiling
// parameters: i_n => numerator
//             i_d => denominator
// returns: ceiling of i_n / i_d (integer)
//------------------------------------------------------------------------------
uint32_t proc_build_smp_round_ceiling(
    uint32_t i_n,
    uint32_t i_d)
{
    return((i_n / i_d) + ((i_n % i_d)?(1):(0)));
}


//------------------------------------------------------------------------------
// function: utility function to apply positive/negative scaing factor
//           to base epsilon value
// parameters: i_gb_positive   => set guardband direction (true=positive,
//                                false=negative)
//             i_gb_percentage => scaling factor (e.g. 20% = 20)
//             io_target_value => target epsilon value, after
//                                application of scaling factor
//                                NOTE: scaling will be clamped to
//                                minimum/maximum value
// returns: void
//------------------------------------------------------------------------------
void proc_build_smp_guardband_epsilon(
    const bool i_gb_positive,
    const uint8_t i_gb_percentage,
    uint32_t & io_target_value)
{
    uint32_t delta = proc_build_smp_round_ceiling(io_target_value * i_gb_percentage, 100);

    // mark function entry
    FAPI_DBG("proc_build_smp_guardband_epsilon: Start");

    // apply guardband
    if (i_gb_positive)
    {
        // clamp to maximum value if necessary
        if (delta > (PROC_BUILD_SMP_EPSILON_MAX_VALUE - io_target_value))
        {
            FAPI_DBG("proc_build_smp_guardband_epsilon: Guardband application generated out-of-range target value, clamping to maximum value!");
            io_target_value = PROC_BUILD_SMP_EPSILON_MAX_VALUE;
        }
        else
        {
            io_target_value += delta;
        }
    }
    else
    {
        // clamp to minimum value if necessary
        if (delta >= io_target_value)
        {
            FAPI_DBG("proc_build_smp_guardband_epsilon: Guardband application generated out-of-range target value, clamping to minimum value!");
            io_target_value = PROC_BUILD_SMP_EPSILON_MIN_VALUE;
        }
        else
        {
            io_target_value -= delta;
        }
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_guardband_epsilon: End");
    return;
}


//------------------------------------------------------------------------------
// function: check if target epsilon value is less than maximum realizable
//           value given underlying register storage
// parameters: i_target_value => desired epsilon value
//             i_max_hw_value => largest value which can be represented by
//                               underlying register storage
//             i_must_fit     => raise error if true and target value
//                               cannot be represented in underlying storage
//             i_unit         => unit enum for FFDC
//             o_does_fit     => boolean indicating comparison result
// returns: FAPI_RC_SUCCESS if value can be represented in HW storage (or
//              i_must_fit is false)
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if value is out of range and
//              i_must_fit is true
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_check_epsilon(
    const uint32_t i_target_value,
    const uint32_t i_max_hw_value,
    const bool i_must_fit,
    const proc_build_smp_epsilon_unit i_unit,
    bool& o_does_fit)
{
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_build_smp_check_epsilon: Start");

    do
    {
        o_does_fit = (i_max_hw_value > i_target_value);

        if (i_must_fit && !o_does_fit)
        {
            FAPI_ERR("proc_build_smp_check_epsilon: Desired value (= %d) is greater than maximum value supported by HW (= %d)",
                     i_target_value, i_max_hw_value);
            const uint32_t& VALUE = i_target_value;
            const uint32_t& MAX_HW_VALUE = i_max_hw_value;
            const proc_build_smp_epsilon_unit& UNIT = i_unit;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR);
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_check_epsilon: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set L2 unit epsilon configuration attributes
// parameters: i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all attributes are set to valid values,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_l2(
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    bool r_t0_fits = false;
    bool r_t1_fits = false;
    bool r_t2_fits = false;
    bool w_t2_fits = false;
    uint8_t l2_force_t2_attr_value;
    uint32_t l2_r_t0_attr_value;
    uint32_t l2_r_t1_attr_value;
    uint32_t l2_r_t2_attr_value;
    uint32_t l2_w_attr_value;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_l2: Start");

    do
    {
        //
        // NOTE: L2 epsilon valus will only be pushed into attributes by
        //       this procedure.  Hostboot will run on scan flush (safe) values,
        //       and runtime values pushed into attributes will be applied
        //       via winkle image.
        //
        // 10012814 = L2 Epsilon Config Register
        //   0:8  = r_t0 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //   9:17 = r_t1 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //  18:28 = r_t2 (MAX = all 0s = 2048, MIN = 1, HW = target_value+1)
        //  29:35 = w_t2 (MAX = all 0s =  128, MIN = 1, HW = target_value+1)
        //     36 = force t2 (0 = MODE1 = use scope to choose tier,
        //                    1 = MODE2 = use r_t2 value for all read protection
        //

        // target read tier2 & write tier2 epsilon values must be representable
        // in HW storage, error out if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_t2,
            PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_L2_R_T2,
            r_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from proc_build_smp_check_epsilon (r_t2)");
            break;
        }

        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.w_t2,
            PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_W_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_L2_W_T2,
            w_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from proc_build_smp_check_epsilon (w_t2)");
            break;
        }

        // check read tier0, read tier1 target values
        // don't error if these don't fit, as we will just force use of tier2
        // in this case
        (void) proc_build_smp_check_epsilon(
            i_eps_cfg.r_t0,
            PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T0,
            false,
            PROC_BUILD_SMP_EPSILON_UNIT_L2_R_T0,
            r_t0_fits);
        (void) proc_build_smp_check_epsilon(
            i_eps_cfg.r_t1,
            PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T1,
            false,
            PROC_BUILD_SMP_EPSILON_UNIT_L2_R_T1,
            r_t1_fits);

        // set attributes based on unit implementation
        FAPI_DBG("proc_build_smp_set_epsilons_l2: Writing ATTR_L2_R_T2_EPS");
        l2_r_t2_attr_value = ((i_eps_cfg.r_t2 == PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T2)?
                              (0):(i_eps_cfg.r_t2+1));
        rc = FAPI_ATTR_SET(
            ATTR_L2_R_T2_EPS,
            NULL,
            l2_r_t2_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from FAPI_ATTR_SET (ATTR_L2_R_T2_EPS)");
            break;
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l2: Writing ATTR_L2_W_EPS");
        l2_w_attr_value = ((i_eps_cfg.w_t2 == PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_W_T2)?
                           (0):(i_eps_cfg.w_t2+1));
        rc = FAPI_ATTR_SET(
            ATTR_L2_W_EPS,
            NULL,
            l2_w_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from FAPI_ATTR_SET (ATTR_L2_W_EPS)");
            break;
        }

        // force tier2 if necessary
        if (!r_t0_fits || !r_t1_fits)
        {
            l2_force_t2_attr_value = fapi::ENUM_ATTR_L2_FORCE_R_T2_EPS_ON;
            l2_r_t0_attr_value = 0;
            l2_r_t1_attr_value = 0;
        }
        // otherwise, write explicit read tier0, read tier1 attribute values
        else
        {
            l2_force_t2_attr_value = fapi::ENUM_ATTR_L2_FORCE_R_T2_EPS_OFF;
            l2_r_t0_attr_value = ((i_eps_cfg.r_t0 == PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T0)?
                                  (0):(i_eps_cfg.r_t0+1));
            l2_r_t1_attr_value = ((i_eps_cfg.r_t1 == PROC_BUILD_SMP_EPSILON_L2_MAX_VALUE_R_T1)?
                                  (0):(i_eps_cfg.r_t1+1));
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l2: Writing ATTR_L2_FORCE_R_T2_EPS");
        rc = FAPI_ATTR_SET(
            ATTR_L2_FORCE_R_T2_EPS,
            NULL,
            l2_force_t2_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from FAPI_ATTR_SET (ATTR_L2_FORCE_R_T2_EPS)");
            break;
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l2: Writing ATTR_L2_R_T0_EPS");
        rc = FAPI_ATTR_SET(
            ATTR_L2_R_T0_EPS,
            NULL,
            l2_r_t0_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from FAPI_ATTR_SET (ATTR_L2_R_T0_EPS)");
            break;
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l2: Writing ATTR_L2_R_T1_EPS");
        rc = FAPI_ATTR_SET(
            ATTR_L2_R_T1_EPS,
            NULL,
            l2_r_t1_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l2: Error from FAPI_ATTR_SET (ATTR_L2_R_T1_EPS)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons_l2: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set L3 unit epsilon configuration attributes
// parameters: i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all attributes are set to valid values,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_l3(
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    bool r_t0_fits = false;
    bool r_t1_fits = false;
    bool r_t2_fits = false;
    bool w_t2_fits = false;

    uint8_t l3_force_t2_attr_value;
    uint32_t l3_r_t0_attr_value;
    uint32_t l3_r_t1_attr_value;
    uint32_t l3_r_t2_attr_value;
    uint32_t l3_w_attr_value;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_l3: Start");

    do
    {
        //
        // NOTE: L3 epsilon valus will only be pushed into attributes by
        //       this procedure.  Hostboot will run on scan flush (safe) values,
        //       and runtime values pushed into attributes will be applied
        //       via winkle image.
        //
        // 10010829 = L3 Read Epsilon Config Register
        //    0:8 = r_t0 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //   9:17 = r_t1 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //  18:28 = r_t2 (MAX = all 0s = 2048, MIN = 1, HW = target_value+1)
        //  29:30 = force t2 (00 = MODE1 = use scope to choose tier,
        //                    01 = MODE2 = use r_t2 value for all read protection
        //
        // 1001082A = L3 Write Epsilon Config Register
        //    0:6 = w_t2 (MAX = all 0s =  128, MIN = 1, HW = target value+1)
        //

        // target read tier2 & write epsilon values must be representable
        // in HW storage, error if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_t2,
            PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_L3_R_T2,
            r_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from proc_build_smp_check_epsilon (r_t2)");
            break;
        }

        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.w_t2,
            PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_W_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_L3_W_T2,
            w_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from proc_build_smp_check_epsilon (w_t2)");
            break;
        }

        // check read tier0, read tier1 target values
        // don't error if these don't fit, as we will just force use of tier2
        // in this case
        (void) proc_build_smp_check_epsilon(
            i_eps_cfg.r_t0,
            PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T0,
            false,
            PROC_BUILD_SMP_EPSILON_UNIT_L3_R_T0,
            r_t0_fits);
        (void) proc_build_smp_check_epsilon(
            i_eps_cfg.r_t1,
            PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T1,
            false,
            PROC_BUILD_SMP_EPSILON_UNIT_L3_R_T1,
            r_t1_fits);

        // set attributes based on unit implementation
        FAPI_DBG("proc_build_smp_set_epsilons_l3: Writing ATTR_L3_R_T2_EPS");
        l3_r_t2_attr_value = ((i_eps_cfg.r_t2 == PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T2)?
                              (0):(i_eps_cfg.r_t2+1));
        rc = FAPI_ATTR_SET(
            ATTR_L3_R_T2_EPS,
            NULL,
            l3_r_t2_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from FAPI_ATTR_SET (ATTR_L3_R_T2_EPS)");
            break;
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l3: Writing ATTR_L3_W_EPS");
        l3_w_attr_value = ((i_eps_cfg.w_t2 == PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_W_T2)?
                           (0):(i_eps_cfg.w_t2+1));
        rc = FAPI_ATTR_SET(
            ATTR_L3_W_EPS,
            NULL,
            l3_w_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from FAPI_ATTR_SET (ATTR_L3_W_EPS");
            break;
        }

        // force tier2 if necessary
        if (!r_t0_fits || !r_t1_fits)
        {
            l3_force_t2_attr_value = fapi::ENUM_ATTR_L3_FORCE_R_T2_EPS_ON;
            l3_r_t0_attr_value = 0;
            l3_r_t1_attr_value = 0;
        }
        // otherwise, write explicit read tier0, read tier1 attribute values
        else
        {
            l3_force_t2_attr_value = fapi::ENUM_ATTR_L2_FORCE_R_T2_EPS_OFF;
            l3_r_t0_attr_value = ((i_eps_cfg.r_t0 == PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T0)?
                                  (0):(i_eps_cfg.r_t0+1));
            l3_r_t1_attr_value = ((i_eps_cfg.r_t1 == PROC_BUILD_SMP_EPSILON_L3_MAX_VALUE_R_T1)?
                                  (0):(i_eps_cfg.r_t1+1));
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l3: Writing ATTR_L3_FORCE_R_T2_EPS");
        rc = FAPI_ATTR_SET(
            ATTR_L3_FORCE_R_T2_EPS,
            NULL,
            l3_force_t2_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from FAPI_ATTR_SET (ATTR_L3_FORCE_R_T2_EPS)");
            break;
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l3: Writing ATTR_L3_R_T0_EPS");
        rc = FAPI_ATTR_SET(
            ATTR_L3_R_T0_EPS,
            NULL,
            l3_r_t0_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from FAPI_ATTR_SET (ATTR_L3_R_T0_EPS)");
            break;
        }

        FAPI_DBG("proc_build_smp_set_epsilons_l3: Writing ATTR_L3_R_T1_EPS");
        rc = FAPI_ATTR_SET(
            ATTR_L3_R_T1_EPS,
            NULL,
            l3_r_t1_attr_value);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_l3: Error from FAPI_ATTR_SET (ATTR_L3_R_T1_EPS)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons_l3: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set MCS unit epsilon registers for all configured chiplets
//           on target chip
// parameters: i_target  => chip target
//             i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all settings are programmed correctly,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_mcs(
    fapi::Target & i_target,
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    bool r_t0_fits = false;
    bool r_t1_fits = false;
    bool r_t2_fits = false;
    bool r_f_fits  = false;
    ecmdDataBufferBase data(64);
    std::vector<fapi::Target> mcs_chiplets;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_mcs: Start");

    do
    {
        //
        // 02011816 = MCS Epsilon Register
        //    0:7 = jitter (MAX = all 1s = 1016, MIN = all 0s = 0, HW = [target value/4]+1)
        //   8:15 = r_t0   (MAX = all 1s = 1016, MIN = all 0s = 0, HW = [target value/4]+1)
        //  16:23 = r_t1   (MAX = all 1s = 1016, MIN = all 0s = 0, HW = [target value/4]+1)
        //  24:31 = r_t2   (MAX = all 1s = 1016, MIN = all 0s = 0, HW = [target value/4]+1)
        //  32:39 = r_f    (MAX = all 1s = 1016, MIN = all 0s = 0, HW = [target value/4]+1)
        //

        // all target values must be representable in HW storage, error if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_t0,
            PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_T0,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_T0,
            r_t0_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcs: Error from proc_build_smp_check_epsilon (r_t0)");
            break;
        }

        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_t1,
            PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_T1,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_T1,
            r_t1_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcs: Error from proc_build_smp_check_epsilon (r_t1)");
            break;
        }

        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_t2,
            PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_T2,
            r_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcs: Error from proc_build_smp_check_epsilon (r_t2)");
            break;
        }

        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_f,
            PROC_BUILD_SMP_EPSILON_MCS_MAX_VALUE_R_F,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_MCS_R_F,
            r_f_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcs: Error from proc_build_smp_check_epsilon (r_f)");
            break;
        }

        // form data buffer
        rc_ecmd |= data.insertFromRight(
            PROC_BUILD_SMP_EPSILON_MCS_JITTER,
            MCEPS_JITTER_EPSILON_START_BIT,
            (MCEPS_JITTER_EPSILON_END_BIT-
             MCEPS_JITTER_EPSILON_START_BIT+1));

        rc_ecmd |= data.insertFromRight(
            proc_build_smp_round_ceiling(i_eps_cfg.r_t0, 4)+1,
            MCEPS_NODAL_EPSILON_START_BIT,
            (MCEPS_NODAL_EPSILON_END_BIT-
             MCEPS_NODAL_EPSILON_START_BIT+1));

        rc_ecmd |= data.insertFromRight(
            proc_build_smp_round_ceiling(i_eps_cfg.r_t1, 4)+1,
            MCEPS_GROUP_EPSILON_START_BIT,
            (MCEPS_GROUP_EPSILON_END_BIT-
             MCEPS_GROUP_EPSILON_START_BIT+1));

        rc_ecmd |= data.insertFromRight(
            proc_build_smp_round_ceiling(i_eps_cfg.r_t2, 4)+1,
            MCEPS_SYSTEM_EPSILON_START_BIT,
            (MCEPS_SYSTEM_EPSILON_END_BIT-
             MCEPS_SYSTEM_EPSILON_START_BIT+1));

        rc_ecmd |= data.insertFromRight(
            proc_build_smp_round_ceiling(i_eps_cfg.r_f, 4)+1,
            MCEPS_FOREIGN_EPSILON_START_BIT,
            (MCEPS_FOREIGN_EPSILON_END_BIT-
             MCEPS_FOREIGN_EPSILON_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcs: Error 0x%x setting up MCEPS data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // determine configured MCS chiplets
        rc = fapiGetChildChiplets(i_target,
                                  fapi::TARGET_TYPE_MCS_CHIPLET,
                                  mcs_chiplets);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcs: Error from fapiGetChildChiplets");
            break;

        }

        // loop over configured MCS chiplets and set epsilon configuration
        for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin();
             i != mcs_chiplets.end();
             i++)
        {
            rc = fapiPutScom(*i, MCS_MCEPS_0x02011816, data);

            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_epsilons_mcs: fapiPutScom error (MCS_MCEPS_0x02011816)");
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons_mcs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set NX CQ (NX/AS) unit epsilon registers
// parameters: i_target  => chip target
//             i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all settings are programmed correctly,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_nx(
    fapi::Target & i_target,
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    bool w_t2_fits = false;
    ecmdDataBufferBase data(64), mask(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_nx: Start");

    do
    {
        //
        // 0201309D = NX CQ Epsilon Scale register
        //    0:5 = w_t2 (MAX = all 0s =  448, MIN = 1, HW = target_value/7)
        //

        // target write tier2 epsilon value must be representable
        // in HW storage, error out if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.w_t2,
            PROC_BUILD_SMP_EPSILON_NX_MAX_VALUE_W_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_NX_W_T2,
            w_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_nx: Error from proc_build_smp_check_epsilon (w_t2)");
            break;
        }

        // program write epsilon register based on unit implementation
        uint32_t hw_value = proc_build_smp_round_ceiling(i_eps_cfg.w_t2, 7);
        if (hw_value == 64)
        {
            hw_value = 0;
        }

        rc_ecmd |= data.insertFromRight(
            hw_value,
            NX_CQ_EPSILON_SCALE_EPSILON_START_BIT,
            (NX_CQ_EPSILON_SCALE_EPSILON_END_BIT-
             NX_CQ_EPSILON_SCALE_EPSILON_START_BIT+1));
        rc_ecmd |= mask.setBit(
            NX_CQ_EPSILON_SCALE_EPSILON_START_BIT,
            (NX_CQ_EPSILON_SCALE_EPSILON_END_BIT-
             NX_CQ_EPSILON_SCALE_EPSILON_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_epsilons_nx: Error 0x%x setting up NX CQ Epsilon Scale register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register (use mask to avoid overriding other configuration
        // settings in register)
        rc = fapiPutScomUnderMask(i_target,
                                  NX_CQ_EPS_0x0201309D,
                                  data,
                                  mask);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_nx: fapiPutScomUnderMask error (NX_CQ_EPS_0x0201309D)");
            break;
        }
    } while(0);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_nx: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set HCA unit epsilon registers
// parameters: i_target  => chip target
//             i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all settings are programmed correctly,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_hca(
    fapi::Target & i_target,
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    bool w_t2_fits = false;
    ecmdDataBufferBase data(64), mask(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_hca: Start");

    do
    {
        //
        // 0201094F = HCA Mode Register
        //  21:29 = w_t2 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //

        // all target values must be representable in HW storage, error if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.w_t2,
            PROC_BUILD_SMP_EPSILON_HCA_MAX_VALUE_W_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_HCA_W_T2,
            w_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_hca: Error from proc_build_smp_check_epsilon (w_t2)");
            break;
        }

        // form data buffer
        rc_ecmd |= data.insertFromRight(
            ((i_eps_cfg.w_t2 == PROC_BUILD_SMP_EPSILON_HCA_MAX_VALUE_W_T2)?
             (0):(i_eps_cfg.w_t2+1)),
            HCA_MODE_EPSILON_START_BIT,
            (HCA_MODE_EPSILON_END_BIT-
             HCA_MODE_EPSILON_START_BIT+1));
        rc_ecmd |= mask.setBit(
            HCA_MODE_EPSILON_START_BIT,
            (HCA_MODE_EPSILON_END_BIT-
             HCA_MODE_EPSILON_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_epsilons_hca: Error 0x%x setting up HCA Mode data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register (use mask to avoid overriding other configuration
        // settings in register)
        rc = fapiPutScomUnderMask(i_target, HCA_MODE_0x0201094F, data, mask);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_hca: fapiPutScomUnderMask error (HCA_MODE_0x0201094F)");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons_hca: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set CAPP unit epsilon registers
// parameters: i_target  => chip target
//             i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all settings are programmed correctly,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_capp(
    fapi::Target & i_target,
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    bool r_t0_fits = false;
    bool r_t1_fits = false;
    bool r_t2_fits = false;
    bool w_t2_fits = false;
    ecmdDataBufferBase data(64), mask(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_capp: Start");

    do
    {
        //
        // 0201301B = CAPP CXA Snoop Control register
        //   3:11 = r_t0 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //  15:23 = r_t1 (MAX = all 0s =  512, MIN = 1, HW = target_value+1)
        //  25:35 = r_t2 (MAX = all 0s = 2048, MIN = 1, HW = target_value+1)
        //      0 = force t2 (0 = MODE1 = use scope to choose tier,
        //                    0 = MODE2 = use r_t2 value for all read protection
        //
        // 02013018 = CAPP APC Master PB Control register
        //  39:45 = w_t2 (MAX = all 0s =  128, MIN = 1, HW = target value+1)
        //

        // target read tier2 & write tier2 epsilon values must be representable
        // in HW storage, error out if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.r_t2,
            PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_CAPP_R_T2,
            r_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_capp: Error from proc_build_smp_check_epsilon (r_t2)");
            break;
        }

        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.w_t2,
            PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_W_T2,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_CAPP_W_T2,
            w_t2_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_capp: Error from proc_build_smp_check_epsilon (w_t2)");
            break;
        }

        // check read tier0, read tier1 target values
        // don't error if these don't fit, as we will just force use of tier2
        // in this case
        (void) proc_build_smp_check_epsilon(
            i_eps_cfg.r_t0,
            PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T0,
            false,
            PROC_BUILD_SMP_EPSILON_UNIT_CAPP_R_T0,
            r_t0_fits);
        (void) proc_build_smp_check_epsilon(
            i_eps_cfg.r_t1,
            PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T1,
            false,
            PROC_BUILD_SMP_EPSILON_UNIT_CAPP_R_T1,
            r_t1_fits);

        // program write epsilon register based on unit implementation
        rc_ecmd |= data.insertFromRight(
            ((i_eps_cfg.w_t2 == PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_W_T2)?
             (0):(i_eps_cfg.w_t2+1)),
            CAPP_APC_MASTER_CONTROL_EPSILON_START_BIT,
            (CAPP_APC_MASTER_CONTROL_EPSILON_END_BIT-
             CAPP_APC_MASTER_CONTROL_EPSILON_START_BIT+1));
        rc_ecmd |= mask.setBit(
            CAPP_APC_MASTER_CONTROL_EPSILON_START_BIT,
            (CAPP_APC_MASTER_CONTROL_EPSILON_END_BIT-
             CAPP_APC_MASTER_CONTROL_EPSILON_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_epsilons_capp: Error 0x%x setting up CAPP APC Master Control register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register (use mask to avoid overriding other configuration
        // settings in register)
        rc = fapiPutScomUnderMask(i_target,
                                  CAPP_APC_MASTER_PB_CTL_0x02013018,
                                  data,
                                  mask);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_capp: fapiPutScomUnderMask error (CAPP_APC_MASTER_PB_CTL_0x02013018)");
            break;
        }

        // program read epsilon register based on unit implementation
        rc_ecmd = data.flushTo0();
        rc_ecmd |= mask.flushTo0();

        rc_ecmd |= data.insertFromRight(
            ((i_eps_cfg.r_t2 == PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T2)?
             (0):(i_eps_cfg.r_t2+1)),
            CAPP_CXA_SNP_READ_EPSILON_TIER2_START_BIT,
            (CAPP_CXA_SNP_READ_EPSILON_TIER2_END_BIT-
             CAPP_CXA_SNP_READ_EPSILON_TIER2_START_BIT+1));
        rc_ecmd |= mask.setBit(
            CAPP_CXA_SNP_READ_EPSILON_TIER2_START_BIT,
            (CAPP_CXA_SNP_READ_EPSILON_TIER2_END_BIT-
             CAPP_CXA_SNP_READ_EPSILON_TIER2_START_BIT+1));

        // force tier2 if necessary
        if (!r_t0_fits || !r_t1_fits)
        {
            rc_ecmd |= data.writeBit(
                CAPP_CXA_SNP_READ_EPSILON_MODE_BIT,
                PROC_BUILD_SMP_EPSILON_CAPP_FORCE_T2);
            rc_ecmd |= mask.setBit(
                CAPP_CXA_SNP_READ_EPSILON_MODE_BIT);
        }
        else
        {
            rc_ecmd |= data.insertFromRight(
                ((i_eps_cfg.r_t0 == PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T0)?
                 (0):(i_eps_cfg.r_t0+1)),
                CAPP_CXA_SNP_READ_EPSILON_TIER0_START_BIT,
                (CAPP_CXA_SNP_READ_EPSILON_TIER0_END_BIT-
                 CAPP_CXA_SNP_READ_EPSILON_TIER0_START_BIT+1));
            rc_ecmd |= mask.setBit(
                CAPP_CXA_SNP_READ_EPSILON_TIER0_START_BIT,
                (CAPP_CXA_SNP_READ_EPSILON_TIER0_END_BIT-
                 CAPP_CXA_SNP_READ_EPSILON_TIER0_START_BIT+1));

            rc_ecmd |= data.insertFromRight(
                ((i_eps_cfg.r_t1 == PROC_BUILD_SMP_EPSILON_CAPP_MAX_VALUE_R_T1)?
                 (0):(i_eps_cfg.r_t1+1)),
                CAPP_CXA_SNP_READ_EPSILON_TIER1_START_BIT,
                (CAPP_CXA_SNP_READ_EPSILON_TIER1_END_BIT-
                 CAPP_CXA_SNP_READ_EPSILON_TIER1_START_BIT+1));
            rc_ecmd |= mask.setBit(
                CAPP_CXA_SNP_READ_EPSILON_TIER1_START_BIT,
                (CAPP_CXA_SNP_READ_EPSILON_TIER1_END_BIT-
                 CAPP_CXA_SNP_READ_EPSILON_TIER1_START_BIT+1));
        }

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_epsilons_capp: Error 0x%x setting up CAPP CXA Snoop Control register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register (use mask to avoid overriding other configuration
        // settings in register)
        rc = fapiPutScomUnderMask(i_target,
                                  CAPP_CXA_SNOOP_CTL_0x0201301B,
                                  data,
                                  mask);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_capp: fapiPutScomUnderMask error (CAPP_CXA_SNOOP_CTL_0x0201301B)");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons_capp: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set MCD unit epsilon registers
// parameters: i_target  => chip target
//             i_eps_cfg => system epsilon configuration structure
// returns: ECMD_SUCCESS if all settings are programmed correctly,
//          RC_PROC_BUILD_SMP_EPSILON_RANGE_ERR if any target value is out of
//              range given underlying HW storage,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_epsilons_mcd(
    fapi::Target & i_target,
    const proc_build_smp_eps_cfg & i_eps_cfg)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    bool p_fits = false;
    ecmdDataBufferBase data(64), mask(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons_mcd: Start");

    do
    {
        //
        // 0201340B = MCD Recovery Pre Epsilon Configuration register
        //  52:63 = p (MAX = all 1s = 66520, MIN = 0, HW = target_value/16)
        //

        // target pre epsilon value must be representable
        // in HW storage, error out if not
        rc = proc_build_smp_check_epsilon(
            i_eps_cfg.p,
            PROC_BUILD_SMP_EPSILON_MCD_MAX_VALUE_P,
            true,
            PROC_BUILD_SMP_EPSILON_UNIT_MCD_P,
            p_fits);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcd: Error from proc_build_smp_check_epsilon (p)");
            break;
        }

        // program write epsilon register based on unit implementation
        rc_ecmd |= data.insertFromRight(
            proc_build_smp_round_ceiling(i_eps_cfg.p, 16),
            MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_START_BIT,
            (MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_END_BIT-
             MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_START_BIT+1));
        rc_ecmd |= mask.setBit(
            MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_START_BIT,
            (MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_END_BIT-
             MCD_RECOVERY_PRE_EPS_CONFIG_EPSILON_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcd: Error 0x%x setting up MCD Recovery Pre Epsilon Configuration register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register (use mask to avoid overriding other configuration
        // settings in register)
        rc = fapiPutScomUnderMask(i_target,
                                  MCD_PRE_EPS_0x0201340B,
                                  data,
                                  mask);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons_mcd: fapiPutScomUnderMask error (MCD_PRE_EPS_0x0201340B)");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons_mcd: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: calculate target epsilon settings to apply based on
//           system configuration
// parameters: io_smp => structure encapsulating SMP (including system
//                       frequency/epsilon configuration parameter values),
//                       target epsilon values will be filled by this subroutine
// returns: FAPI_RC_SUCCESS if target settings are valid,
//          RC_PROC_BUILD_SMP_EPSILON_INVALID_TABLE_ERR if invalid epsilon
//              table type/content is detected,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_calc_epsilons(
    proc_build_smp_system & io_smp)
{
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_build_smp_calc_epsilons: Start");

    do
    {
        // perform table lookup based on system table type
        FAPI_DBG("proc_build_smp_calc_epsilons: core floor freq = %d, PB freq = %d, table index = %d",
                 io_smp.freq_core_floor,
                 io_smp.freq_pb,
                 io_smp.core_floor_ratio);

        switch(io_smp.eps_cfg.table_type)
        {
            case PROC_FAB_SMP_EPSILON_TABLE_TYPE_HE:
                if (io_smp.pump_mode == PROC_FAB_SMP_PUMP_MODE1)
                {
                    io_smp.eps_cfg.r_t0 = PROC_BUILD_SMP_EPSILON_R_T0_HE[io_smp.core_floor_ratio];
                }
                else
                {
                    io_smp.eps_cfg.r_t0 = PROC_BUILD_SMP_EPSILON_R_T1_HE[io_smp.core_floor_ratio];
                }
                io_smp.eps_cfg.r_t1 = PROC_BUILD_SMP_EPSILON_R_T1_HE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.r_t2 = PROC_BUILD_SMP_EPSILON_R_T2_HE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.r_f  = PROC_BUILD_SMP_EPSILON_R_F_HE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.w_t2 = PROC_BUILD_SMP_EPSILON_W_HE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.w_f  = PROC_BUILD_SMP_EPSILON_W_F_HE[io_smp.core_floor_ratio];
                break;
            case PROC_FAB_SMP_EPSILON_TABLE_TYPE_LE:
                if (io_smp.pump_mode == PROC_FAB_SMP_PUMP_MODE1)
                {
                    io_smp.eps_cfg.r_t0 = PROC_BUILD_SMP_EPSILON_R_T0_LE[io_smp.core_floor_ratio];
                }
                else
                {
                    io_smp.eps_cfg.r_t0 = PROC_BUILD_SMP_EPSILON_R_T1_LE[io_smp.core_floor_ratio];
                }
                io_smp.eps_cfg.r_t1 = PROC_BUILD_SMP_EPSILON_R_T1_LE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.r_t2 = PROC_BUILD_SMP_EPSILON_R_T2_LE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.r_f  = PROC_BUILD_SMP_EPSILON_R_F_LE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.w_t2 = PROC_BUILD_SMP_EPSILON_W_LE[io_smp.core_floor_ratio];
                io_smp.eps_cfg.w_f  = PROC_BUILD_SMP_EPSILON_W_F_LE[io_smp.core_floor_ratio];
                break;
            case PROC_FAB_SMP_EPSILON_TABLE_TYPE_1S:
                if (io_smp.pump_mode == PROC_FAB_SMP_PUMP_MODE1)
                {
                    io_smp.eps_cfg.r_t0 = PROC_BUILD_SMP_EPSILON_R_T0_1S[io_smp.core_floor_ratio];
                }
                else
                {
                    io_smp.eps_cfg.r_t0 = PROC_BUILD_SMP_EPSILON_R_T1_1S[io_smp.core_floor_ratio];
                }
                io_smp.eps_cfg.r_t1 = PROC_BUILD_SMP_EPSILON_R_T1_1S[io_smp.core_floor_ratio];
                io_smp.eps_cfg.r_t2 = PROC_BUILD_SMP_EPSILON_R_T2_1S[io_smp.core_floor_ratio];
                io_smp.eps_cfg.r_f  = PROC_BUILD_SMP_EPSILON_R_F_1S[io_smp.core_floor_ratio];
                io_smp.eps_cfg.w_t2 = PROC_BUILD_SMP_EPSILON_W_1S[io_smp.core_floor_ratio];
                io_smp.eps_cfg.w_f  = PROC_BUILD_SMP_EPSILON_W_F_1S[io_smp.core_floor_ratio];
                break;
            default:
                FAPI_ERR("proc_build_smp_calc_epsilons: Invalid epsilon table type");
                const proc_fab_smp_eps_table_type& TABLE_TYPE = io_smp.eps_cfg.table_type;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_EPSILON_INVALID_TABLE_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        // dump base epsilon values
        FAPI_DBG("proc_build_smp_calc_epsilons: Base epsilon values read from table:");
        FAPI_DBG("proc_build_smp_calc_epsilons:  R_T0 = %d", io_smp.eps_cfg.r_t0);
        FAPI_DBG("proc_build_smp_calc_epsilons:  R_T1 = %d", io_smp.eps_cfg.r_t1);
        FAPI_DBG("proc_build_smp_calc_epsilons:  R_T2 = %d", io_smp.eps_cfg.r_t2);
        FAPI_DBG("proc_build_smp_calc_epsilons:   R_F = %d", io_smp.eps_cfg.r_f);
        FAPI_DBG("proc_build_smp_calc_epsilons:  W_T2 = %d", io_smp.eps_cfg.w_t2);
        FAPI_DBG("proc_build_smp_calc_epsilons:   W_F = %d", io_smp.eps_cfg.w_f);

        // scale base epsilon values if core is running 2x nest frequency
        if (io_smp.core_ceiling_ratio == PROC_BUILD_SMP_CORE_RATIO_8_8)
        {
            FAPI_DBG("proc_build_smp_calc_epsilons: Scaling based on ceiling frequency");
            uint8_t scale_percentage =
                100 *
                io_smp.freq_core_ceiling /
                (2 * io_smp.freq_pb);
            scale_percentage -= 100;

            proc_build_smp_guardband_epsilon(
                io_smp.eps_cfg.gb_positive,
                scale_percentage,
                io_smp.eps_cfg.r_t0);
            proc_build_smp_guardband_epsilon(
                io_smp.eps_cfg.gb_positive,
                scale_percentage,
                io_smp.eps_cfg.r_t1);
            proc_build_smp_guardband_epsilon(
                io_smp.eps_cfg.gb_positive,
                scale_percentage,
                io_smp.eps_cfg.r_t2);
            proc_build_smp_guardband_epsilon(
                io_smp.eps_cfg.gb_positive,
                scale_percentage,
                io_smp.eps_cfg.r_f);
            proc_build_smp_guardband_epsilon(
                io_smp.eps_cfg.gb_positive,
                scale_percentage,
                io_smp.eps_cfg.w_t2);
            proc_build_smp_guardband_epsilon(
                io_smp.eps_cfg.gb_positive,
                scale_percentage,
                io_smp.eps_cfg.w_f);
        }

        // apply guardband to epsilon values
        proc_build_smp_guardband_epsilon(
            io_smp.eps_cfg.gb_positive,
            io_smp.eps_cfg.gb_percentage,
            io_smp.eps_cfg.r_t0);
        proc_build_smp_guardband_epsilon(
            io_smp.eps_cfg.gb_positive,
            io_smp.eps_cfg.gb_percentage,
            io_smp.eps_cfg.r_t1);
        proc_build_smp_guardband_epsilon(
            io_smp.eps_cfg.gb_positive,
            io_smp.eps_cfg.gb_percentage,
            io_smp.eps_cfg.r_t2);
        proc_build_smp_guardband_epsilon(
            io_smp.eps_cfg.gb_positive,
            io_smp.eps_cfg.gb_percentage,
            io_smp.eps_cfg.r_f);
        proc_build_smp_guardband_epsilon(
            io_smp.eps_cfg.gb_positive,
            io_smp.eps_cfg.gb_percentage,
            io_smp.eps_cfg.w_t2);
        proc_build_smp_guardband_epsilon(
            io_smp.eps_cfg.gb_positive,
            io_smp.eps_cfg.gb_percentage,
            io_smp.eps_cfg.w_f);

        // max pre-epsilon counter
        io_smp.eps_cfg.p = PROC_BUILD_SMP_EPSILON_MCD_MAX_VALUE_P-1;

        // dump scaled epsilon values
        FAPI_DBG("proc_build_smp_calc_epsilons: Scaled epsilon values based on %s%d percent guardband:",
                 (io_smp.eps_cfg.gb_positive)?("+"):("-"),
                 io_smp.eps_cfg.gb_percentage);
        FAPI_DBG("proc_build_smp_calc_epsilons:  R_T0 = %d", io_smp.eps_cfg.r_t0);
        FAPI_DBG("proc_build_smp_calc_epsilons:  R_T1 = %d", io_smp.eps_cfg.r_t1);
        FAPI_DBG("proc_build_smp_calc_epsilons:  R_T2 = %d", io_smp.eps_cfg.r_t2);
        FAPI_DBG("proc_build_smp_calc_epsilons:   R_F = %d", io_smp.eps_cfg.r_f);
        FAPI_DBG("proc_build_smp_calc_epsilons:  W_T2 = %d", io_smp.eps_cfg.w_t2);
        FAPI_DBG("proc_build_smp_calc_epsilons:   W_F = %d", io_smp.eps_cfg.w_f);
        FAPI_DBG("proc_build_smp_calc_epsilons:     P = %d", io_smp.eps_cfg.p);

        // check relationship of epsilon counters
        // rules:
        //   read tier values are strictly increasing
        //   read tier2 value is greater than read foreign value
        //   write tier2 value is greater than write foreign value
        if ((io_smp.eps_cfg.r_t0 > io_smp.eps_cfg.r_t1) ||
            (io_smp.eps_cfg.r_t1 > io_smp.eps_cfg.r_t2) ||
            ((io_smp.eps_cfg.r_f  > io_smp.eps_cfg.r_t2) && (io_smp.eps_cfg.table_type != PROC_FAB_SMP_EPSILON_TABLE_TYPE_1S)) ||
            ((io_smp.eps_cfg.w_f  > io_smp.eps_cfg.w_t2) && (io_smp.eps_cfg.table_type != PROC_FAB_SMP_EPSILON_TABLE_TYPE_1S)))
        {
            FAPI_ERR("proc_build_smp_calc_epsilons: Invalid relationship between base epsilon values");
            const proc_fab_smp_eps_table_type& TABLE_TYPE = io_smp.eps_cfg.table_type;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_EPSILON_INVALID_TABLE_ERR);
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_epsilons: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_set_epsilons(
    proc_build_smp_system & i_smp)
{
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_epsilons: Start");

    do
    {
        // calculate epsilons
        rc = proc_build_smp_calc_epsilons(i_smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_calc_epsilons");
            break;
        }

        // set system level attributes
        // L2
        rc = proc_build_smp_set_epsilons_l2(i_smp.eps_cfg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_l2");
            break;
        }

        // L3
        rc = proc_build_smp_set_epsilons_l3(i_smp.eps_cfg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_l3");
            break;
        }

        // process each chip in SMP, program unit epsilon registers
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                fapi::Target target = p_iter->second.chip->this_chip;

                // MCS
                rc = proc_build_smp_set_epsilons_mcs(target, i_smp.eps_cfg);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_mcs");
                    break;
                }

                // HCA
                rc = proc_build_smp_set_epsilons_hca(target, i_smp.eps_cfg);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_hca");
                    break;
                }

                // set epsilons for NX regions only if partial good attribute is set
                if (p_iter->second.nx_enabled)
                {
                    // NX
                    rc = proc_build_smp_set_epsilons_nx(target, i_smp.eps_cfg);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_nx");
                        break;
                    }

                    // CAPP
                    rc = proc_build_smp_set_epsilons_capp(target, i_smp.eps_cfg);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_capp");
                        break;
                    }
                }

                // MCD
                rc = proc_build_smp_set_epsilons_mcd(target, i_smp.eps_cfg);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_epsilons: Error from proc_build_smp_set_epsilons_mcd");
                    break;
                }
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_epsilons: End");
    return rc;
}


} // extern "C"
