/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_proc_gettracearray.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_proc_gettracearray.H
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
// *HWP HW Owner        : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP HW Backup Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner        : Thi Tran <thi@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#ifndef _PROC_GETTRACEARRAY_H_
#define _PROC_GETTRACEARRAY_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// maximum trace array entries supported by P9 chip design
const uint8_t PROC_GETTRACEARRAY_NUM_ENTRIES = 128;
// bits to store per trace array entry
const uint8_t PROC_GETTRACEARRAY_BITS_PER_ENTRY = 128;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/**
 * @brief Identifiers for supported trace arrays.
 *
 * There is an identifier for each available trace bus. Many arrays are shared
 * between multiple trace buses; in that case, several identifiers point to the
 * same trace array.
 */
enum proc_gettracearray_bus_id
{
    /* Pervasive chiplet - TARGET_TYPE_PROC_CHIP */
    PROC_TB_PIB     = 1,
    PROC_TB_OCC,
    PROC_TB_TOD,
    PROC_TB_SBE,
    PROC_TB_PIB_ALT,  /* alternate sink for PIB trace */

    /* Nest chiplets - TARGET_TYPE_PROC_CHIP */
    PROC_TB_PB0,
    PROC_TB_PB1,
    PROC_TB_PB2,
    PROC_TB_PB3,
    PROC_TB_PB4,
    PROC_TB_PB5,
    PROC_TB_PB6,
    PROC_TB_PB7,
    PROC_TB_PB8,
    PROC_TB_PB9,
    PROC_TB_PB10,
    PROC_TB_PB11,
    PROC_TB_PB12,
    PROC_TB_PB13,
    PROC_TB_MCS0,
    PROC_TB_MCS1,
    PROC_TB_MCS2,
    PROC_TB_MCS3,
    PROC_TB_MCD0,
    PROC_TB_MCD1,
    PROC_TB_VAS,
    PROC_TB_PBIO0,
    PROC_TB_PBIO1,
    PROC_TB_PBIOE0,
    PROC_TB_PBIOE1,
    PROC_TB_CXA0,
    PROC_TB_CXA1,
    PROC_TB_NX,
    PROC_TB_IOPSI,
    PROC_TB_PCIS0,
    PROC_TB_PCIS1,
    PROC_TB_PCIS2,
    PROC_TB_NPU0,
    PROC_TB_NPU1,
    PROC_TB_NMMU0,
    PROC_TB_NMMU1,
    PROC_TB_INT,
    PROC_TB_BRIDGE,

    /* XBUS chiplet - TARGET_TYPE_PROC_CHIP */
    PROC_TB_IOX0,
    PROC_TB_IOX1,
    PROC_TB_IOX2,
    PROC_TB_PBIOX0,
    PROC_TB_PBIOX1,
    PROC_TB_PBIOX2,

    /* PCI chiplets - TARGET_TYPE_PROC_CHIP */
    PROC_TB_PCI0X,
    PROC_TB_PCI00,
    PROC_TB_PCI1X,
    PROC_TB_PCI11,
    PROC_TB_PCI12,
    PROC_TB_PCI2X,
    PROC_TB_PCI23,
    PROC_TB_PCI24,
    PROC_TB_PCI25,

    _PROC_TB_LAST_PROC_TARGET = PROC_TB_PCI25,

    /* OBus chiplets - TARGET_TYPE_OBUS */
    PROC_TB_PBIOOA,
    PROC_TB_IOO,

    _PROC_TB_LAST_OBUS_TARGET = PROC_TB_IOO,

    /* MemCtrl chiplets - TARGET_TYPE_MCS */
    PROC_TB_MCA0,
    PROC_TB_MCA1,
    PROC_TB_IOMC0,
    PROC_TB_IOMC1,
    PROC_TB_IOMC2,
    PROC_TB_IOMC3,

    _PROC_TB_LAST_MC_TARGET = PROC_TB_IOMC3,

    /* Cache chiplets - TARGET_TYPE_EX */
    PROC_TB_L30,
    PROC_TB_L31,
    PROC_TB_NCU0,
    PROC_TB_NCU1,
    PROC_TB_CME,
    PROC_TB_EQPB,    // note: only for odd EX instances
    PROC_TB_IVRM,
    PROC_TB_SKEWADJ, // note: only for even EX instances
    PROC_TB_L20,
    PROC_TB_L21,
    PROC_TB_SKIT10,
    PROC_TB_SKIT11,

    _PROC_TB_LAST_EX_TARGET = PROC_TB_SKIT11,

    /* Core chiplets - TARGET_TYPE_CORE */
    PROC_TB_CORE0,
    PROC_TB_CORE1,
};

static const fapi2::TargetType PROC_GETTRACEARRAY_TARGET_TYPES =
    fapi2::TARGET_TYPE_PROC_CHIP |
    fapi2::TARGET_TYPE_OBUS |
    fapi2::TARGET_TYPE_MCBIST |
    fapi2::TARGET_TYPE_EX |
    fapi2::TARGET_TYPE_CORE;

// structure to represent HWP arguments
struct proc_gettracearray_args
{
    proc_gettracearray_bus_id trace_bus; ///< The trace bus whose associated trace array should be dumped
    bool stop_pre_dump;                  ///< Stop the trace array before starting the dump
    bool ignore_mux_setting;             ///< Do not fail if the primary trace mux is set to a different bus
    bool collect_dump;                   ///< Do dump the trace array; useful if you just want to start/stop
    bool reset_post_dump;                ///< Reset the debug logic after dumping
    bool restart_post_dump;              ///< Start the trace array after dumping
};

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_proc_gettracearray_FP_t)(const fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES>&,
                              const proc_gettracearray_args&,
                              fapi2::variable_buffer& o_ta_data);

extern "C"
{

    /**
     * @brief Return the target type needed to access a given trace array
     * @param ta_id The trace array / trace bus ID requested.
     * @return The type of target to hand to proc_gettracearray to clearly identify the array instance.
     */
    static inline fapi2::TargetType proc_gettracearray_target_type(proc_gettracearray_bus_id i_trace_bus)
    {
        if (i_trace_bus <= _PROC_TB_LAST_PROC_TARGET)
        {
            return fapi2::TARGET_TYPE_PROC_CHIP;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_OBUS_TARGET)
        {
            return fapi2::TARGET_TYPE_OBUS;
        }
        else if (i_trace_bus <= _PROC_TB_LAST_MC_TARGET)
        {
            return fapi2::TARGET_TYPE_MCBIST;
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
     *         RC_PROC_GETTRACEARRAY_INVALID_BUS
     *             if an invalid trace bus ID has been requested
     *         RC_PROC_GETTRACEARRAY_INVALID_TARGET
     *             if the supplied target type does not match the requested trace bus
     *         RC_PROC_GETTRACEARRAY_CORE_NOT_DUMPABLE
     *             if a core trace array has been requested but the chip's core
     *             is not dumpable via SCOM -> use fastarray instead
     *         RC_PROC_GETTRACEARRAY_TRACE_RUNNING
     *             if trace array is running when dump collection is attempted,
     *         RC_PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT
     *             if the primary trace mux is not set up to trace the requested bus,
     *         else FAPI getscom/putscom return code for failing operation
     */
    fapi2::ReturnCode p9_proc_gettracearray(const fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES>& i_target,
                                            const proc_gettracearray_args& i_args,
                                            fapi2::variable_buffer& o_ta_data);

} // extern "C"

#endif // _PROC_GETTRACEARRAY_H_
