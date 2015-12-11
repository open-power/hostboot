/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_fbc_cd.H $          */
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
/// @file p9_build_smp_fbc_cd.H
/// @brief  Fabric configuration (hotplug, CD) functions
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
///

#ifndef _P9_BUILD_SMP_FBC_CD_H_
#define _P9_BUILD_SMP_FBC_CD_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// TODO: RTC 147511 - Use SCOM register names from p9_misc_scom_addresses.H
// Remove the reg addresses defined below and use the ones in
// p9_misc_scom_addresses.H when available.
const uint64_t PB_SCONFIG_LOAD_WEST = 0x05011811;
const uint64_t PB_SCONFIG_LOAD_CENT = 0x05011C11;
const uint64_t PB_SCONFIG_LOAD_EAST = 0x05012011;

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Program fabric configuration register (hotplug, C/D set)
/// @param[in]   i_smp     Structure encapsulating SMP topology
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_fbc_cd(p9_build_smp_system& i_smp);


} // extern "C"

#endif // _P9_BUILD_SMP_FBC_CD_H_
