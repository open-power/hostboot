/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_tracearray.H $ */
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
//------------------------------------------------------------------------------
/// @file  p9_sbe_tracearray.H
///
/// @brief Collect contents of specified trace array via SCOM.
///
/// Collects contents of specified trace array via SCOM.  Optionally
/// manages chiplet domain trace engine state (start/stop/reset) around
/// trace array data collection.  Trace array data can be collected only
/// when its controlling chiplet trace engine is stopped.
///
/// Request number of Trace array entries will be packed into data buffer from
/// oldest->youngest entry.
///
/// Calling code is expected to pass the proper target type based on the
/// desired trace resource; a convenience function is provided to find out
/// the expected target type for a given trace resource.
//------------------------------------------------------------------------------
// *HWP HW Owner        : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP HW Backup Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner        : Shakeeb Pasha<shakeebbk@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 1
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------

#ifndef _P9_SBE_TRACEARRAY_H
#define _P9_SBE_TRACEARRAY_H
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include "p9_tracearray_defs.H"

// structure to represent HWP arguments
struct p9_sbe_tracearray_args
{
    p9_tracearray_bus_id trace_bus; ///< The trace bus whose associated trace array should be dumped
    bool stop_pre_dump;             ///< Stop the trace array before starting the dump
    bool ignore_mux_setting;        ///< Do not fail if the primary trace mux is set to a different bus
    bool collect_dump;              ///< Do dump the trace array; useful if you just want to start/stop
    bool reset_post_dump;           ///< Reset the debug logic after dumping
    bool restart_post_dump;         ///< Start the trace array after dumping
};

static const fapi2::TargetType P9_SBE_TRACEARRAY_TARGET_TYPES =
    fapi2::TARGET_TYPE_PROC_CHIP |
    fapi2::TARGET_TYPE_EX |
    fapi2::TARGET_TYPE_CORE;

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_sbe_tracearray_FP_t) (
    const fapi2::Target<P9_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
    const p9_sbe_tracearray_args& i_args,
    uint8_t* o_ta_data,
    const uint32_t i_num_rows
);

extern "C" {
    /**
     * @brief Return the target type needed to access a given trace array
     *
     * @param ta_id The trace array / trace bus ID requested.
     *
     * @return The type of target to hand to p9_sbe_tracearray to clearly
     *         identify the array instance.
     */
    static inline fapi2::TargetType p9_sbe_tracearray_target_type(p9_tracearray_bus_id i_trace_bus)
    {
        /* On SBE there is no support for MCBIST and OBUS fapi targets.
         * But since the usage related to these targets in p9_sbe_tracearray
         * is only for SCOMs with fully qualified adresses, PROC
         * target is used for MCBIST and OBUS as well */
        if (i_trace_bus <= _PROC_TB_LAST_MC_TARGET)
        {
            return fapi2::TARGET_TYPE_PROC_CHIP;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_EX_TARGET)
        {
            return fapi2::TARGET_TYPE_EX;
        }
        else
        {
            return fapi2::TARGET_TYPE_CORE;
        }
    }



    /* TODO via RTC:164528 - Look at optimization to improve performance
     * @brief Retrieve trace array data, based on the number of
     *        rows requested, from selected trace array via SCOM.
     *        Optionally performing trace stop (prior to dump) and/or
     *        trace restart, reset (after dump).
     *        If a partial dump is requested along with other control flags,
     *        pre-dump control would take effect before reading row 0 and
     *        post-dump control would take effect after reading last row.
     *
     * @param i_target      Chip or chiplet target. The necessary target type can be
     *                      queried through p9_sbe_tracearray_target_type().
     * @param i_args        Argument structure with additional parameters
     * @param o_ta_data     Trace array data. Will contain requested number of trace
     *                      rows from the array concatenated,
     *                      starting with the oldest trace entry after the previous
     *                      dump call and ending with the newest
     * @param i_cur_row     Current count of the row being extracted.
     *                      Internally used to determine the order of
     *                      pre and post dump control in case of partial dump.
     * @param i_num_rows    Number of rows of the tracearray to read.
     *                      By default P9_TRACEARRAY_NUM_ROWS are read
     *
     * @return FAPI2_RC_SUCCESS
     *             if trace array dump sequence completes successfully,
     *         RC_PROC_GETTRACEARRAY_INVALID_BUS
     *             if an invalid trace bus ID has been requested
     *         RC_PROC_GETTRACEARRAY_CORE_NOT_DUMPABLE
     *             if a core trace array has been requested but the chip's core
     *             is not dumpable via SCOM -> use fastarray instead
     *         RC_PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT
     *             if the primary trace mux is not set up to trace the requested bus,
     *         else FAPI getscom/putscom return code for failing operation
     */
    fapi2::ReturnCode p9_sbe_tracearray(
        const fapi2::Target<P9_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
        const p9_sbe_tracearray_args& i_args,
        uint64_t* o_ta_data,
        const uint32_t i_cur_row = 0,
        const uint32_t i_num_rows = P9_TRACEARRAY_NUM_ROWS
    );
} // extern "C"
#endif //_P9_SBE_TRACEARRAY_H
