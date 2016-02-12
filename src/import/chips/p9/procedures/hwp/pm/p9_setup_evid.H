/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_setup_evid.H $                  */
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
/// @file  p9_setup_evid.H
/// @brief Setup External Voltage IDs
///
/// *HW Owner    : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
/// *FW Owner    : Sangeetha T S <sangeet2@in.ibm.com>
/// *Team        : PM
/// *Consumed by : HB
/// *Level       : 2
///

#ifndef __P9_SETUP_EVID_H__
#define __P9_SETUP_EVID_H__

#include <fapi2.H>

extern "C"
{

/// @typedef p9_setup_evid_FP_t
/// function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p9_setup_evid_FP_t) (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief Read attributes containing part's boot voltages(VDD,VCS and VDN)
/// and set these voltage using the AVSBUS interface (VDD, VDN and VCS).
///
/// @param [in] i_target TARGET_TYPE_PROC_CHIP
/// @attr
/// @attritem  ATTR_VCS_BOOT_VOLTAGE  - 1mV grandularity setting for VCS rail
/// @attritem  ATTR_VDD_BOOT_VOLTAGE  - 1mV grandularity setting for VDD rail
/// @attritem  ATTR_VDN_BOOT_VOLTAGE  - 1mV grandularity setting for VDN rail
/// @attritem  ATTR_VDD_AVSBUS_BUSNUM - AVSBus Number having the VDD VRM
/// @attritem  ATTR_VDD_AVSBUS_RAIL   - AVSBus Rail number for VDD VRM
/// @attritem  ATTR_VDN_AVSBUS_BUSNUM - AVSBus Number having the VDN VRM
/// @attritem  ATTR_VDN_AVSBUS_RAIL   - AVSBus Rail number for VDN VRM
/// @attritem  ATTR_VCS_AVSBUS_BUSNUM - AVSBus Number having the VCS VRM
/// @attritem  ATTR_VCS_AVSBUS_RAIL   - AVSBus Rail number for VCS VRM
///
/// @retval FAPI_RC_SUCCESS
    fapi2::ReturnCode
    p9_setup_evid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


} // extern C

#endif  // __P9_SETUP_EVID_H__
