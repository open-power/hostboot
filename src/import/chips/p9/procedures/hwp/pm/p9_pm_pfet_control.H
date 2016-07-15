/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pfet_control.H $  */
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
/// @file p9_pm_pfet_control.H
/// @brief Enable PFET devices to power on/off all enabled Core and Cache
/// chiplets in target passed.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------

#ifndef _P9_PM_PFETCTL_H_
#define _P9_PM_PFETCTL_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_quad_scom_addresses.H>

namespace PM_PFET_TYPE_C
{
//Valid rail options
enum pfet_rail_t
{
    BOTH,
    VDD,
    VCS
};

//Valid force options
enum pfet_force_t
{
    OFF,
    ON
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_pfet_control_eq_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op);

typedef fapi2::ReturnCode (*p9_pm_pfet_control_ex_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op);

typedef fapi2::ReturnCode (*p9_pm_pfet_control_ec_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
    const PM_PFET_TYPE_C::pfet_force_t i_op);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

    /**
     ** @brief HWP
     ** p9_pm_pfet_control_eq - Enable power on/off for cache chiplet
     **
     ** @param[in]  &i_target    Target type cache chiplet
     ** @param[in]  i_rail       Valid rail options:
     **                          BOTH
     **                          VDD
     **                          VCS
     ** @param[in]  i_op         Valid options:
     **                          OFF
     **                          ON
     ** @return FAPI2_RC_SUCCESS on success, error otherwise
     **/
    fapi2::ReturnCode  p9_pm_pfet_control_eq (
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
        const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
        const PM_PFET_TYPE_C::pfet_force_t i_op);

    /**
     ** @brief HWP
     ** p9_pm_pfet_control_ex - Enable power on/off for EX chiplet
     **
     ** @param[in]  &i_target    Target type EX chiplet
     ** @param[in]  i_rail       Valid rail options:
     **                          BOTH
     **                          VDD
     **                          VCS
     ** @param[in]  i_op         Valid options:
     **                          OFF
     **                          ON
     ** @return FAPI2_RC_SUCCESS on success, error otherwise
     **/
    fapi2::ReturnCode  p9_pm_pfet_control_ex (
        const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
        const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
        const PM_PFET_TYPE_C::pfet_force_t i_op);

    /**
     ** @brief HWP
     ** p9_pm_pfet_control_ec - Enable power on/off for core chiplet
     **
     ** @param[in]  &i_target    Target type core chiplet
     ** @param[in]  i_rail       Valid rail options:
     **                          BOTH
     **                          VDD
     **                          VCS
     ** @param[in]  i_op         Valid options:
     **                          OFF
     **                          ON
     ** @return FAPI2_RC_SUCCESS on success, error otherwise
     **/
    fapi2::ReturnCode  p9_pm_pfet_control_ec (
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const PM_PFET_TYPE_C::pfet_rail_t  i_rail,
        const PM_PFET_TYPE_C::pfet_force_t i_op);

} // extern "C"

#endif // _P9_PM_PFETCTL_H_
