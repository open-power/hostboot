/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_proc_gettracearray.H $ */
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
/// @file  p10_proc_gettracearray.H
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

#ifndef _PROC_GETTRACEARRAY_H_
#define _PROC_GETTRACEARRAY_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <target_filters.H>
#include "p10_tracearray_defs.H"
#include "p10_sbe_tracearray.H"

static const fapi2::TargetType PROC_GETTRACEARRAY_TARGET_TYPES =
    fapi2::TARGET_TYPE_PROC_CHIP |
    fapi2::TARGET_TYPE_IOHS |
    fapi2::TARGET_TYPE_PAUC |
    fapi2::TARGET_TYPE_MI |
    fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_CORE |
    fapi2::TARGET_TYPE_EQ ;


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p10_proc_gettracearray_FP_t)(const fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES>&,
                               const proc_gettracearray_args&,
                               fapi2::variable_buffer& o_ta_data);

extern "C"
{

    /**
     * @brief Return the target type needed to access a given trace array
     * @param ta_id The trace array / trace bus ID requested.
     * @return The type of target to hand to proc_gettracearray to clearly identify the array instance.
     */
    static inline fapi2::TargetType proc_gettracearray_target_type(p10_tracearray_bus_id i_trace_bus)
    {
        if (i_trace_bus <= _PROC_TB_LAST_PROC_TARGET)
        {
            return fapi2::TARGET_TYPE_PROC_CHIP;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_PEC_TARGET)
        {
            return fapi2::TARGET_TYPE_PEC;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_MC_TARGET)
        {
            return fapi2::TARGET_TYPE_MI;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_PAUC_TARGET)
        {
            return fapi2::TARGET_TYPE_PAUC;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_IOHS_TARGET)
        {
            return fapi2::TARGET_TYPE_IOHS;
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

    /**
     * @brief Determine whether a trace entry is a start marker
     * @param[in] i_buffer a buffer containing the trace entry
     * @param[in] i_offset the bit offset of the entry inside the buffer, defaults to 0 if omitted
     * @return FAPI2_RC_SUCCESS  if the entry _is_ a start marker
     */
    static inline fapi2::ReturnCodes p10_tracearray_is_trace_start_marker(
        const fapi2::variable_buffer i_buffer, uint32_t i_offset = 0)
    {
        uint32_t l_magic = 0;
        uint64_t l_zeros = 0;
        fapi2::ReturnCodes l_rc;

        l_rc = i_buffer.extract(l_magic, i_offset, 32);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            return l_rc;
        }

        l_rc = i_buffer.extract(l_zeros, i_offset + 32, 64);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            return l_rc;
        }

        return (l_magic == 0xBA55A1E0 && l_zeros == 0) ?
               fapi2::FAPI2_RC_SUCCESS : fapi2::FAPI2_RC_FALSE;
    }


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

    /**
     * @brief Retrieve trace array data from selected trace array via SCOM,
     *        optionally performing trace stop (prior to dump) and/or
     *        trace restart (after dump)
     *
     * @param i_target  Chip or chiplet target. The necessary target type can be
     *                  queried through proc_gettracearray_target_type().
     * @param i_args    Argument structure with additional parameters
     * @param o_ta_data Trace array data. Will contain all trace entries read
     *                  from the array concatenated, starting with the oldest trace
     *                  entry and ending with the newest.
     * @return FAPI2_RC_SUCCESS
     *             if trace array dump sequence completes successfully,
     */
    fapi2::ReturnCode p10_proc_gettracearray(const fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES>& i_target,
            const proc_gettracearray_args& i_args,
            fapi2::variable_buffer& o_ta_data);

} // extern "C"

#endif // _PROC_GETTRACEARRAY_H_
