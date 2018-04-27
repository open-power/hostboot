/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_query_channel_failure.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file  p9c_query_channel_failure.H
/// @brief DMI and MC query for channel failure
///

// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: HB
// *HWP Level: 2
// *HWP Consumed by: HB and PRDF

#ifndef __P9C_QUERY_CHANNEL_FAILURE_H__
#define __P9C_QUERY_CHANNEL_FAILURE_H__

#include <fapi2.H>

/// @typedef p9_query_channel_failure_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9c_query_channel_failure_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>&,
    bool& );

extern "C"
{
    /**
     * @brief HWP that checks for a channel failure associated with DMI target
     * Should be called for all valid/connected DMI endpoints
     *
     * @param[in]  i_tgt    Reference to DMI chiplet target
     * @param[out] o_failed Channel failure status (true = failure found)
     *
     * @return FAPI2_RC_SUCCESS on success, error otherwise
     */
    fapi2::ReturnCode p9c_query_channel_failure(
        const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_tgt,
        bool& o_failed );
}

#endif  // __P9C_QUERY_CHANNEL_FAILURE_H__
