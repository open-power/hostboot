/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fbc_eff_config_links.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
