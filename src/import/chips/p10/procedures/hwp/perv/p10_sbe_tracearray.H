/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_tracearray.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_sbe_tracearray.H
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
// *HWP HW Maintainer   : Nicholas Landi <nlandi@ibm.com>
// *HWP FW Maintainer   : Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by     : Cronus, SBE
//------------------------------------------------------------------------------

#ifndef _P10_SBE_TRACEARRAY_H
#define _P10_SBE_TRACEARRAY_H
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include "p10_tracearray_defs.H"

constexpr uint32_t P10_TRACEARRAY_FIRST_ROW  = 0;
constexpr uint32_t PEC_CHIPLET_ID_START  = 0x08;
constexpr uint32_t PEC_CHIPLET_ID_END    = 0x09;
constexpr uint32_t MC_CHIPLET_ID_START   = 0x0C;
constexpr uint32_t MC_CHIPLET_ID_END     = 0x0F;
constexpr uint32_t PAUC_CHIPLET_ID_START  = 0x10;
constexpr uint32_t PAUC_CHIPLET_ID_END    = 0x13;
constexpr uint32_t IOHS_CHIPLET_ID_START = 0x18;
constexpr uint32_t IOHS_CHIPLET_ID_END   = 0x1F;

#define IS_MC(chipletId) \
    ((chipletId >= MC_CHIPLET_ID_START) && \
     (chipletId <= MC_CHIPLET_ID_END))
#define IS_PAUC(chipletId) \
    ((chipletId >= PAUC_CHIPLET_ID_START) && \
     (chipletId <= PAUC_CHIPLET_ID_END))
#define IS_IOHS(chipletId) \
    ((chipletId >= IOHS_CHIPLET_ID_START) && \
     (chipletId <= IOHS_CHIPLET_ID_END))
#define IS_PEC(busId) \
    ((busId > _PROC_TB_LAST_PROC_TARGET) && \
     (busId <= _PROC_TB_LAST_PEC_TARGET))

// structure to represent HWP arguments
struct proc_gettracearray_args
{
    p10_tracearray_bus_id trace_bus; ///< The trace bus whose associated trace array should be dumped
    bool stop_pre_dump;             ///< Stop the trace array before starting the dump
    bool ignore_mux_setting;        ///< Do not fail if the primary trace mux is set to a different bus
    bool collect_dump;              ///< Do dump the trace array; useful if you just want to start/stop
    bool reset_post_dump;           ///< Reset the debug logic after dumping
    bool restart_post_dump;         ///< Start the trace array after dumping
};

static const fapi2::TargetType P10_SBE_TRACEARRAY_TARGET_TYPES =
    fapi2::TARGET_TYPE_PROC_CHIP |
    fapi2::TARGET_TYPE_PERV |
    fapi2::TARGET_TYPE_CORE |
    fapi2::TARGET_TYPE_EQ;

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_sbe_tracearray_FP_t) (
    const fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
    const proc_gettracearray_args& i_args,
    uint64_t* o_ta_data,
    const uint32_t i_cur_row,
    const uint32_t i_num_rows
);

extern "C" {
    /**
     * @brief Return the target type needed to access a given trace array
     *
     * @param ta_id The trace array / trace bus ID requested.
     *
     * @return The type of target to hand to p10_sbe_tracearray to clearly
     *         identify the array instance.
     */
    static inline fapi2::TargetType p10_sbe_tracearray_target_type(
        p10_tracearray_bus_id i_trace_bus)
    {
        if (i_trace_bus <= _PROC_TB_LAST_PROC_TARGET)
        {
            return fapi2::TARGET_TYPE_PROC_CHIP;
        }
        else if(i_trace_bus <= _PROC_TB_LAST_IOHS_TARGET)
        {
            return fapi2::TARGET_TYPE_PERV;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_CORE_EQ_TARGET)
        {
            return fapi2::TARGET_TYPE_CORE;
        }
        else
        {
            return fapi2::TARGET_TYPE_EQ;
        }
    }

    /* @brief Retrieve trace array data, based on the number of
     *        rows requested, from selected trace array via SCOM.
     *        Optionally performing trace stop (prior to dump) and/or
     *        trace restart, reset (after dump).
     *        If a partial dump is requested along with other control flags,
     *        pre-dump control would take effect before reading row 0 and
     *        post-dump control would take effect after reading last row.
     *
     * @param i_target      Chip or chiplet target. The necessary target type can be
     *                      queried through p10_sbe_tracearray_target_type().
     * @param i_args        Argument structure with additional parameters
     * @param o_ta_data     Trace array data. Will contain requested number of trace
     *                      rows from the array concatenated,
     *                      starting with the oldest trace entry after the previous
     *                      dump call and ending with the newest
     * @param i_cur_row     Current count of the row being extracted.
     *                      Internally used to determine the order of
     *                      pre and post dump control in case of partial dump.
     * @param i_num_rows    Number of rows of the tracearray to read.
     *                      By default P10_TRACEARRAY_NUM_ROWS are read
     *
     * @return FAPI2_RC_SUCCESS
     *             if trace array dump sequence completes successfully,
     */
    fapi2::ReturnCode p10_sbe_tracearray(
        const fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
        const proc_gettracearray_args& i_args,
        uint64_t* o_ta_data,
        const uint32_t i_cur_row = P10_TRACEARRAY_FIRST_ROW,
        const uint32_t i_num_rows = P10_TRACEARRAY_NUM_ROWS
    );

    static inline uint16_t max_rows(const p10_tracearray_bus_id i_trace_bus)
    {
        return ((i_trace_bus == PROC_TB_CORE0 || i_trace_bus == PROC_TB_CORE1) ?
                P10_TRACEARRAY_NUM_CORE_ROWS : P10_TRACEARRAY_NUM_ROWS);
    }

} // extern "C"
#endif //_P10_SBE_TRACEARRAY_H
