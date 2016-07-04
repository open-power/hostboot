/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_quad_power_off.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_quad_power_off.H
/// @brief Power off the EQ including the functional cores associatated with it.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------

#ifndef _P9_QUADPOWEROFF_H_
#define _P9_QUADPOWEROFF_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_quad_scom_addresses.H>
#include <p9_pm_pfet_control.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_quad_power_off_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
    /**
     ** @brief Power off the EQ including the functional cores associatated with it.
     **
     ** @param[in] i_target    Targe type EQ
     **
     ** @return FAPI2_RC_SUCCESS if success, error otherwise
     **/
    fapi2::ReturnCode p9_quad_power_off (
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target);

} // extern "C"

#endif // _P9_QUADPOWEROFF_H_
