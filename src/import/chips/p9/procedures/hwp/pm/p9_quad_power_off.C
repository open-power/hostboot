/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_quad_power_off.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_quad_power_off.C
/// @brief Power off the EQ including the functional cores associatated with it.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//     - For each good EC associated with the targeted EQ, power it off.
//     - Power off the EQ.
// @endverbatim
//
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_quad_power_off.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// Procedure p9_quad_power_off entry point, comments in header
fapi2::ReturnCode p9_quad_power_off(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target)
{
    fapi2::buffer<uint64_t> l_data64;
    constexpr uint64_t l_rawData = 0x1100000000000000ULL; // Bit 3 & 7 are set to be manipulated
    constexpr uint32_t MAX_CORE_PER_QUAD = 4;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    uint32_t l_cnt = 0;

    FAPI_INF("p9_quad_power_off: Entering...");

    // Print chiplet position
    FAPI_INF("Quad power off chiplet no.%d", i_target.getChipletNumber());

    FAPI_DBG("Disabling bits 20/22/24/26 in EQ_QPPM_QPMMR_CLEAR, to gain access"
             " to PFET controller, otherwise Quad Power off scom will fail");
    l_data64.setBit<20>();
    l_data64.setBit<22>();
    l_data64.setBit<24>();
    l_data64.setBit<26>();
    FAPI_TRY(fapi2::putScom(i_target, EQ_QPPM_QPMMR_CLEAR, l_data64));

    // QPPM_QUAD_CTRL_REG
    do
    {
        // EX0, Enables the EDRAM charge pumps in L3 EX0, on power down they
        // must be de-asserted in the opposite order 3 -> 0
        // EX1, Enables the EDRAM charge pumps in L3 EX1, on power down they
        // must be de-asserted in the opposite order 7 -> 4
        FAPI_DBG("De-asserting EDRAM charge pumps in Ex0 & Ex1 in Sequence for "
                 "Reg EQ_QPPM_QCCR_SCOM1, Data Value [0x%0X%0X]",
                 uint32_t((l_rawData << l_cnt) >> 32), uint32_t(l_rawData << l_cnt));
        FAPI_TRY(fapi2::putScom(i_target, EQ_QPPM_QCCR_SCOM1, (l_rawData << l_cnt)));
    }
    while(++l_cnt < MAX_CORE_PER_QUAD);

    // Call the procedure
    FAPI_EXEC_HWP(rc, p9_pm_pfet_control_eq, i_target,
                  PM_PFET_TYPE_C::BOTH, PM_PFET_TYPE_C::OFF);
    FAPI_TRY(rc);

fapi_try_exit:
    FAPI_INF("p9_quad_power_off: ...Exiting");
    return fapi2::current_err;
}
