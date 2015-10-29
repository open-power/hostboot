/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_pcie_hotplug_control.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pcie_hotplug_control.H
/// @brief Manage slot power on hot-plug controlled slots (FAPI2)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB

#ifndef _P9_PCIE_HOTPLUG_CONTROL_H_
#define _P9_PCIE_HOTPLUG_CONTROL_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pcie_hotplug_control_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        const bool);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Enable/disable PCIE slot power
/// @param[in] i_target => P9 chip target
/// @param[in] i_enable_slot_power => boolean to control power state (true=enable, false=disable)
/// @return FAPI_RC_SUCCESS if the setup completes successfully,
//
    fapi2::ReturnCode p9_pcie_hotplug_control(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
            const bool i_enable_slot_power);
} //extern"C"

#endif //_P9_PCIE_HOTPLUG_CONTROL_H_
