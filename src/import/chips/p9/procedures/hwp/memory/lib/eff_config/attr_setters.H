/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/attr_setters.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file attr_setters.H
/// @brief Create setter functions for mss attributes
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP




#ifndef _MSS_ATTR_SETTERS_H_
#define _MSS_ATTR_SETTERS_H_

#include <fapi2.H>



namespace mss
{
///
/// @brief Set ATTR_MSS_VOLT and ATTR_MSS_VOLT_VPP
/// @param[in] i_target_mcs the MCS target
/// @param[in] l_selected_dram_voltage the voltage in millivolts for nominal voltage
/// @param[in] l_selected_dram_voltage_vpp voltage  in millivolts for the VPP
/// @return FAPI2_RC_SUCCESS iff ok
///

fapi2::ReturnCode set_voltage_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
        uint64_t l_selected_dram_voltage,
        uint64_t l_selected_dram_voltage_vpp);

}  // mss

#endif

