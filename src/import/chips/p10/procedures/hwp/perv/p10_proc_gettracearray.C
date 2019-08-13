/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_proc_gettracearray.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
//------------------------------------------------------------------------------
/// @file  p10_proc_gettracearray.C
///
/// @brief Collect contents of specified trace array via SCOM.
///
/// Collects contents of specified trace array via SCOM.  Optionally
/// manages chiplet domain trace engine state (start/stop/reset) around
/// trace array data collection.  Trace array data can be collected only
/// when its controlling chiplet trace engine is stopped.
///
/// Trace array entries will be packed into data buffer from
/// oldest->youngest entry.
///
/// Calling code is expected to pass the proper target type based on the
/// desired trace resource; a convenience function is provided to find out
/// the expected target type for a given trace resource.
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Nicholas Landi <nlandi@ibm.com>
// *HWP FW Maintainer   : Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by     : Cronus, SBE
//------------------------------------------------------------------------------
//TODO: RTC:202264
//TODO: Replace all comments with p10 specific code

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p10_proc_gettracearray.H"

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
extern "C" fapi2::ReturnCode p10_proc_gettracearray(
    const fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES>& i_target,
    const proc_gettracearray_args& i_args,
    fapi2::variable_buffer& o_ta_data)
{
    fapi2::ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;

    // mark HWP entry
    FAPI_INF("Entering ...");

    fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES> l_target;
    const uint8_t l_chiplet_num = i_target.getChipletNumber();

    if(IS_MCBIST(l_chiplet_num) || IS_OBUS(l_chiplet_num))
    {
        l_target = i_target.getParent<fapi2::TARGET_TYPE_PERV>();
    }
    else
    {
        l_target = i_target.get();
    }

    o_ta_data.resize(P10_TRACEARRAY_NUM_ROWS * P10_TRACEARRAY_BITS_PER_ROW).flush<0>();
    uint64_t l_data_buffer[P10_TRACEARRAY_NUM_ROWS * P10_TRACEARRAY_BITS_PER_ROW / 8 / sizeof(uint64_t)] = {};

    l_fapiRc = p10_sbe_tracearray(
                   l_target,
                   i_args,
                   l_data_buffer,
                   0,
                   P10_TRACEARRAY_NUM_ROWS);
    FAPI_TRY(l_fapiRc,
             "p10_sbe_tracearray failed");

    for(uint32_t i = 0; i < P10_TRACEARRAY_NUM_ROWS; i++)
    {
        FAPI_TRY(o_ta_data.set<uint64_t>(l_data_buffer[2 * i + 0], 2 * i + 0),
                 "Failed to insert data into trace buffer");
        FAPI_TRY(o_ta_data.set<uint64_t>(l_data_buffer[2 * i + 1], 2 * i + 1),
                 "Failed to insert data into trace buffer");
    }


    // mark HWP exit
    FAPI_INF("Success");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
