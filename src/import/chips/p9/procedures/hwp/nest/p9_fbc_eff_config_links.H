/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fbc_eff_config_links.H $      */
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
/// @file p9_fbc_eff_config_links.H
/// @brief Set fabric link effective config attributes (FAPI2)
///
/// Set attributes to drive fabric SMP link enablement/SMP build operations
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

#ifndef _P9_FBC_EFF_CONFIG_LINKS_H_
#define _P9_FBC_EFF_CONFIG_LINKS_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_build_smp.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_fbc_eff_config_links_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&, p9_build_smp_operation, bool, bool);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Set fabric link effective configuration attributes
///
/// @param[in] i_target              Chip level target
/// @param[in] i_op                  Enumerated type representing SMP build phase (HB or FSP)
/// @param[in] i_process_electrical  Process electrical links?
///                                  NOTE: TRUE if XBUS links should be
///                                        processed in this invocation context
/// @param[in] i_process_optical     Process optical links?
///                                  NOTE: TRUE if OBUS links should be
///                                        processed in this invocation context
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fbc_eff_config_links(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
            p9_build_smp_operation i_op,
            bool i_process_electrical,
            bool i_process_optical);

} // extern "C"

#endif // _P9_FBC_EFF_CONFIG_LINKS_H_
