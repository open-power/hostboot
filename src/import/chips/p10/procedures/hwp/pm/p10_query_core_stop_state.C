/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_query_core_stop_state.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file  p9_query_core_stop_state.H
/// @brief Check if the targeted core is fully in the input STOP state
///
/// *HWP HWP Owner          : David Du      <daviddu@us.ibm.com>
/// *HWP Backup HWP Owner   : Greg Still    <stillgs@us.ibm.com>
/// *HWP FW Owner           : RANGANATHPRASAD G. BRAHMASAMUDRA <prasadbgr@in.ibm.com>
/// *HWP Team               : PM
/// *HWP Consumed by        : SBE:CRO
/// *HWP Level              : 2
///
/// High-level procedure flow:
/// @verbatim
///    - Read the STOP History Register from the target core
///    - Return SUCCESS if::
///        - STOP_GATED is set (indicating it is stopped)
///        - STOP_TRANSITION is clear (indicating it is stable)
///        - ACT_STOP_LEVEL is at the appropriate value (either 11 (0xB) or 15 (0x15)
///    - Return PENDING if
///        - STOP_TRANSITION is set (indicating transition is progress)
///    - Return ERROR if
///        - STOP_GATED is set, STOP_TRANSITION is clear and ACT_STOP_LEVEL is not
///          appropriate
///        - STOP_TRANSITION is clear but STOP_GATED is clear
///        - Hardware access errors
/// Coverage of Error Cases
///    - Core Running ---> PENDING
///    - Core Stopped
///        - Transition == pending of entry/exit ---> PENDING
///        - Transition == completed
///            - actual_stop_level != expected_stop_level ---> ERROR
///            - actual_stop_level == expected_stop_level ---> SUCCESS
/// @endverbatim
///

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------

#include "p10_query_core_stop_state.H"
#include "p10_scom_c.H"
using namespace scomt::c;

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode
p10_query_core_stop_state(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint32_t i_expected_stop_level)
{
    FAPI_IMP("> p10_query_core_stop_state[Expected STOP Level: %d]", i_expected_stop_level);

    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_stop_gated           = 0;
    uint32_t l_stop_transition      = 0;
    uint32_t l_stop_requested_level = 0;
    uint32_t l_stop_actual_level    = 0;

    FAPI_ASSERT( ((i_expected_stop_level >= 2) && (i_expected_stop_level <= 15)),
                 fapi2::ILLEGAL_EXPECTED_STOP_LEVEL()
                 .set_CORE_TARGET(i_target)
                 .set_EXPECTED_STOP_LEVEL(i_expected_stop_level),
                 "Expected Illegal STOP Level to be Reached");

    FAPI_TRY(fapi2::getScom(i_target, QME_SSH_OTR, l_data64));

    l_data64.extractToRight<QME_SSH_OTR_STOP_GATED, 1>(l_stop_gated);

    l_data64.extractToRight<QME_SSH_OTR_STOP_TRANSITION,
                            QME_SSH_OTR_STOP_TRANSITION_LEN>(l_stop_transition);

    l_data64.extractToRight<QME_SSH_OTR_REQ_STOP_LEVEL,
                            QME_SSH_OTR_REQ_STOP_LEVEL_LEN>(l_stop_requested_level);

    l_data64.extractToRight<QME_SSH_OTR_ACT_STOP_LEVEL,
                            QME_SSH_OTR_ACT_STOP_LEVEL_LEN>(l_stop_actual_level);

    FAPI_DBG("GATED = %d; TRANSITION = %d(Entry:2/Exit:3); REQUESTED_LEVEL = %d; ACTUAL_LEVEL = %d",
             l_stop_gated,
             l_stop_transition,
             l_stop_requested_level,
             l_stop_actual_level);

    if ((l_stop_transition != 0) || (l_stop_gated == 0))
    {
        /*
         * Don't use FAPI_ASSERT() here as this is a "try again" return code
         * used inside a polling loop. We don't want to spam logs with something
         * that's not an error really; thus no FAPI_INF/DBG used as well
         */
        return fapi2::RC_STOP_TRANSITION_PENDING;
    }

    // After stop gated and transition at proper state,
    // check actual stop level reached with expected level.
    // If not, something is off.
    FAPI_ASSERT( (((l_stop_actual_level == 2)   && (i_expected_stop_level == 2)) ||
                  ((l_stop_actual_level == 3)   && (i_expected_stop_level >= 3)  && (i_expected_stop_level < 11)) ||
                  ((l_stop_actual_level == 6)   && (i_expected_stop_level == 6)) ||
                  (((l_stop_actual_level == 11) || (l_stop_actual_level == 15))  && (i_expected_stop_level >= 11))),
                 fapi2::EXPECTED_STOP_LEVEL_NOT_REACHED()
                 .set_ACTUAL_STOP_LEVEL(l_stop_actual_level)
                 .set_EXPECTED_STOP_LEVEL(i_expected_stop_level)
                 .set_CORE_TARGET(i_target),
                 "Reaching Unexpected STOP Level");

    FAPI_INF("SUCCESS!! Valid STOP level[%d] has been achieved.", l_stop_actual_level);

fapi_try_exit:
    FAPI_INF("< p10_query_core_stop_state");

    return fapi2::current_err;
}
