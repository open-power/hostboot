/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_fbc_ab.H $          */
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
/// @file p9_build_smp_fbc_ab.H
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

#ifndef _P9_BUILD_SMP_FBC_AB_H_
#define _P9_BUILD_SMP_FBC_AB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp.H>


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Program fabric configuration register (hotplug, A/B set)
///
/// @param[in] i_smp     Structure encapsulating SMP topology
/// @param[in] i_op      Enumerated type representing SMP build phase
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_fbc_ab(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op);

} // extern "C"

#endif // _P9_BUILD_SMP_FBC_AB_H_
