/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_tracearray.C $ */
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
/// @file  p10_sbe_tracearray.C
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
//
// The SBE is only capable of accepting a limited subset of the supported input
// target types. As such, all targets not supported by the SBE are converted to
// TARGET_TYPE_PERV according to the chart below.
//
// In P10 there are some exceptions to how particular trace arrays or their
// debug macros are accessed:
// 1) The L2/SKIT/L3/NCU trace arrays are scoped to a CORE target type while
//    their debug macros are scoped to a PERV (EQ) target type => there is only
//    one control per EQ.
//
//-----------------------------------------------------------------------------------
//                    Accepted                SBE compatible
//                  Target Types               Target Types
//-----------------------------------------------------------------------------------
//                  | PROC_CHIP ---------------> PROC_CHIP  |
//                  | CORE --------------------> EQ (L3,etc)|
//                  | EQ ----------------------> EQ         |
//                  | --------------------------------------|
//                  | IOHS --------------------> PERV       |
//                  | PAUC -/                               |
//                  | PEC -/                                |
//                  | MI -/                                 |
//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p10_sbe_tracearray.H>
#include <p10_scom_perv.H>
#include <p10_scom_c.H>

using namespace scomt;
using namespace scomt::perv;
using namespace scomt::c;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// offset to store high/low data within a given entry
const uint32_t HI_BIT_OFFSET = 0;
const uint32_t LO_BIT_OFFSET = 64;

const uint32_t DEBUG_TRACE_CONTROL_OFS = EPS_DBG_DEBUG_TRACE_CONTROL - EPS_DBG_MODE_REG;

const uint32_t DEBUG_TRACE_CONTROL_START = 0;
const uint32_t DEBUG_TRACE_CONTROL_STOP  = 1;
const uint32_t DEBUG_TRACE_CONTROL_RESET = 2;

const uint32_t TRACE_HI_DATA_OFS       = static_cast<uint32_t>(TRA0_TR0_TRACE_HI_DATA_REG)
        - static_cast<uint32_t>(TRA0_TR0_TRACE_HI_DATA_REG);
const uint32_t TRACE_LO_DATA_OFS       = static_cast<uint32_t>(TRA0_TR0_TRACE_LO_DATA_REG)
        - static_cast<uint32_t>(TRA0_TR0_TRACE_HI_DATA_REG);
const uint32_t TRACE_TRCTRL_CONFIG_OFS = static_cast<uint32_t>(TRA0_TR0_CONFIG)
        - static_cast<uint32_t>(TRA0_TR0_TRACE_HI_DATA_REG);

const uint32_t TRACE_LO_DATA_RUNNING     = TRA0_TR0_TRACE_LO_DATA_REG_RUNNING;

const uint32_t TRACE_MUX_POSITIONS       = 1 << (TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN);

const uint32_t TA_BASE_SCOM_MULTIPLIER = 0x00000020;
const uint32_t TA_DEBUG_BASE_SCOM      = 0x000107C0;
const uint32_t TA_EQ_DEBUG_BASE_SCOM   = 0x000183E0;
const uint32_t TA_TRACE_BASE_SCOM      = 0x00010400;


//------------------------------------------------------------------------------
// Helper methods
//------------------------------------------------------------------------------
/*
 * @brief Determine if the secondary trace mux is used.
 *
 * @param pri_setting The primary mux setting if the secondary mux is used
 *
 * @return if pri_setting is < 5 then the secondary mux setting should be used
 *
 */
static inline bool use_sec_mux(uint8_t pri_setting)
{
    return (pri_setting < 4);
}

/*
 * @brief Determine the amount of offset needed for an EQ scoped L3, NCU or CLKADJ bus
 *
 * @param i_target: the target passed from the wrapper
 *
 * @return offset
 *
 */
static inline uint32_t get_eq_scom_offset(fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_region_select = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                           i_target,
                           l_region_select),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    FAPI_DBG("reg_sel: %llx", l_region_select);

fapi_try_exit:
    return ((l_region_select % 4) * 0x40);
}

//------------------------------------------------------------------------------
// Table of known trace arrays
//------------------------------------------------------------------------------


struct ta_def
{
    /* One entry per mux setting; value of 0 means N/A */
    p10_tracearray_bus_id bus_ids[TRACE_MUX_POSITIONS];
    const uint8_t chiplet;
    const uint16_t base_multiplier;
    const uint8_t pri_setting; // setting of primary mux if secondary mux is used
};

static const ta_def ta_defs[] =
{
    // bus ids                                                    cplt  mult  pri_setting
    /* PERV */
    { { PROC_TB_PIB  , PROC_TB_OCC , PROC_TB_TOD },               0x01, 0x0000, 5 },
    { { PROC_TB_SBE  , PROC_TB_PIB_ALT },                         0x01, 0x0002, 5 },
    /* N0 */
    { { PROC_TB_VAS  , PROC_TB_NX     },                          0x02, 0x0000, 5 },
    { { PROC_TB_INT  , PROC_TB_NMMU0_0  },                        0x02, 0x0002, 5 },
    { { PROC_TB_PE1  , PROC_TB_NMMU0_1  },                        0x02, 0x0004, 5 },
    /* N1 */
    { { PROC_TB_PB0    },                                         0x03, 0x0000, 5 },
    { { PROC_TB_PB1    },                                         0x03, 0x0002, 5 },
    { { PROC_TB_PB2    },                                         0x03, 0x0004, 5 },
    { { PROC_TB_PB3    },                                         0x03, 0x0006, 5 },
    { { PROC_TB_PB4    },                                         0x03, 0x0008, 5 },
    { { PROC_TB_PB5    },                                         0x03, 0x000A, 5 },
    { { PROC_TB_PB6    },                                         0x03, 0x000C, 5 },
    { { PROC_TB_PB7    },                                         0x03, 0x000E, 5 },
    { { PROC_TB_PB8    },                                         0x03, 0x0010, 5 },
    { { PROC_TB_PB9    },                                         0x03, 0x0012, 5 },
    { { PROC_TB_PB10   },                                         0x03, 0x0014, 5 },
    { { PROC_TB_PB11   },                                         0x03, 0x0016, 5 },
    { { PROC_TB_PE0, PROC_TB_NMMU1_1 },                           0x03, 0x0018, 5 },
    { { PROC_TB_NMMU1_0},                                         0x03, 0x001A, 5 },//---same array
    { { PROC_TB_PSI, PROC_TB_PBA, PROC_TB_ADU, PROC_TB_BR },      0x03, 0x001A, 1 },//-/
    { { PROC_TB_MCD  },                                           0x03, 0x001C, 5 },
    /* PCI */
    { { PROC_TB_PE_0, PROC_TB_PE_1, PROC_TB_PE_2, PROC_TB_AIB },  0x00, 0x0000, 5 },
    /* MC */
    { { PROC_TB_MC0, PROC_TB_MC1   },                             0x00, 0x0000, 5 },
    { { PROC_TB_DLM01_45, PROC_TB_DLM23_67 },                     0x00, 0x0004, 5 },
    /* PAUC */
    { { PROC_TB_PAU0_0, PROC_TB_PAU1_0, PROC_TB_PTL0},            0x00, 0x0000, 5 },
    { { PROC_TB_PAU0_1, PROC_TB_PAU1_1, PROC_TB_PTL1},            0x00, 0x0002, 5 },
    /* AXON */
    { { NO_TB, NO_TB, PROC_TB_IOHS },                             0x00, 0x0000, 5 },
    /* CORE */
    { { PROC_TB_L20 },                                            0x20, 0x07E2, 5 },
    { { PROC_TB_L21 },                                            0x20, 0x07E4, 5 },
    /* EQ */
    { { PROC_TB_L3_0, PROC_TB_NCU_0, PROC_TB_CLKADJ },            0x20, 0x03F0, 5 },
    { { PROC_TB_L3_1, PROC_TB_NCU_1 },                            0x20, 0x03F1, 5 },
    { { PROC_TB_QME0 },                                           0x20, 0x0400, 5 },
    { { PROC_TB_QME1 },                                           0x20, 0x0402, 5 }
};

class TraceArrayFinder
{
    public:
        bool valid;
        uint8_t mux_num;
        uint32_t pri_mux_sel;
        uint32_t sec_mux_sel;
        uint32_t debug_scom_base;
        uint32_t trace_scom_base;

        TraceArrayFinder(p10_tracearray_bus_id i_trace_bus, fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target) :
            valid(false), mux_num(0), pri_mux_sel(0), sec_mux_sel(0), debug_scom_base(0),
            trace_scom_base(0)
        {
            FAPI_DBG("Looking up trace bus");

            for(auto& l_ta_def : ta_defs)
            {
                for(size_t sel = 0; sel < TRACE_MUX_POSITIONS; sel++)
                {
                    if(l_ta_def.bus_ids[sel] == i_trace_bus)
                    {
                        uint32_t l_buffer = 0;
                        l_buffer |= l_ta_def.chiplet << 24;

                        trace_scom_base = l_buffer |
                                          (TA_TRACE_BASE_SCOM
                                           + (TA_BASE_SCOM_MULTIPLIER
                                              *  l_ta_def.base_multiplier));

                        if (i_trace_bus > _PROC_TB_LAST_IOHS_TARGET)
                        {
                            debug_scom_base = TA_EQ_DEBUG_BASE_SCOM;

                            // L3 / NCU / CLKADJ need an offset based on which one is requested.
                            if (i_trace_bus >= _PROC_TB_LAST_CORE_TARGET && i_trace_bus < _PROC_TB_LAST_CORE_EQ_TARGET)
                            {
                                trace_scom_base += get_eq_scom_offset(i_target);
                                i_target = i_target.getParent<fapi2::TARGET_TYPE_EQ>();
                            }
                        }
                        else
                        {
                            debug_scom_base = l_buffer | TA_DEBUG_BASE_SCOM;
                        }

                        // Determine mux position of requested bus
                        /* In P10 the East and West PAUCs have a different mux configuration. East PAUCs
                         * have only one PAU attached each and West PAUCs have 2 PAUs attached. This portion
                         * of code is to determine if the target passed is E or W and determines if:
                         * 1) The trace bus passes exists for this PAUC (checked in p10_sbe_tracearray); and
                         * 2) The mux position for the PTL is correct
                         */
                        pri_mux_sel = sel;

                        if ( (i_target.getChipletNumber() == 0x10 || i_target.getChipletNumber() == 0x11)
                             && ( (i_trace_bus == PROC_TB_PTL0 || i_trace_bus == PROC_TB_PTL1) ) )
                        {
                            pri_mux_sel = 1;
                        }

                        FAPI_DBG("Assigning secondary mux");

                        // Traces with a pri setting <4 also use a secondary select to control one of the traces
                        // connected to the primary mux.
                        if (( use_sec_mux(l_ta_def.pri_setting)))
                        {
                            pri_mux_sel = l_ta_def.pri_setting;
                            sec_mux_sel = sel;
                        }
                        else
                        {
                            sec_mux_sel = 5;
                        }

                        valid = true;
                        FAPI_DBG("Returning found information");
                        return;
                    }
                }
            }
        }
};

//-----------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------

/**
 * @brief Perform the actual dumping of the trace array
 *
 * Make sure trace_run is held off during the dump, and check that the trace is no longer running after
 * we enabled holding it off (holding it off only makes sure it doesn't turn back on during the trace,
 * it will not force it off if it's currently running).
 *
 * The error handling makes sure that the hold_off bit is cleared even in case of an error.
 *
 * @param i_target      The target to run SCOMs against
 * @param i_scom_base   The calculated base SCOM address for the targeted trace array
 * @param i_num_rows    The number of rows requested to be dumped
 * @param o_ta_data     The destination data array
 *
 * @return fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING if trace is still running, else fapi2::FAPI2_RC_SUCCESS
 */
fapi2::ReturnCode p10_sbe_tracearray_do_dump(
    const fapi2::Target < P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
    const uint32_t i_scom_base,
    const uint32_t i_num_rows,
    uint64_t* o_ta_data)
{
    fapi2::buffer<uint64_t> l_trace_ctrl;
    fapi2::buffer<uint64_t> buf = 0;

    FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_TRCTRL_CONFIG_OFS, l_trace_ctrl),
             "Failed to read current trace control setting");

    if (l_trace_ctrl.getBit<TRA0_TR0_CONFIG_TRACE_RUN_STATUS>())
    {
        FAPI_TRY(fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING);
    }

    l_trace_ctrl.setBit<TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
    FAPI_TRY(fapi2::putScom(i_target, i_scom_base + TRACE_TRCTRL_CONFIG_OFS, l_trace_ctrl),
             "Failed to enable holding trace_run off; a possible reason is that "
             "tracing was started just before the SCOM access");

    /* Start with low data register */
    for (uint32_t i = 0; i < i_num_rows; i++)
    {
        FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_LO_DATA_OFS, buf),
                 "Failed to read trace array low data register,"
                 " iteration %d", i);

        *(o_ta_data + (2 * i + 1)) = buf;
    }


    /* Then dump the high data */
    for (uint32_t i = 0; i < i_num_rows; i++)
    {
        FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_HI_DATA_OFS, buf),
                 "Failed to read trace array high data register, "
                 "iteration %d", i);
        *(o_ta_data + (2 * i + 0)) = buf;
    }

fapi_try_exit:

    l_trace_ctrl.clearBit<TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
    fapi2::ReturnCode l_rc = fapi2::putScom(i_target, i_scom_base + TRACE_TRCTRL_CONFIG_OFS, l_trace_ctrl);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Failed to stop holding trace_run off");

        if (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = l_rc;
        }
    }

    return fapi2::current_err;
}

fapi2::ReturnCode p10_sbe_tracearray(
    const fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
    const proc_gettracearray_args& i_args,
    uint64_t* o_ta_data,
    const uint32_t i_cur_row,
    const uint32_t i_num_rows
)
{
    FAPI_INF("Start");

    fapi2::Target < P10_SBE_TRACEARRAY_TARGET_TYPES > l_trctrl_target = i_target;
    fapi2::Target < P10_SBE_TRACEARRAY_TARGET_TYPES > l_dbg_target;

    if (i_args.trace_bus > _PROC_TB_LAST_IOHS_TARGET)
    {
        l_dbg_target = l_trctrl_target.getParent<fapi2::TARGET_TYPE_PERV>();
    }
    else
    {
        l_dbg_target = l_trctrl_target.get();
    }

    TraceArrayFinder l_ta_finder(i_args.trace_bus, l_trctrl_target);
    FAPI_DBG("Assigning targets");
    fapi2::TargetType arg_type = l_trctrl_target.getType();
    fapi2::TargetType ta_type = p10_sbe_tracearray_target_type(i_args.trace_bus);

    FAPI_DBG("Assignment of trace control and trace base");

    uint32_t DEBUG_TRACE_CONTROL = l_ta_finder.debug_scom_base;
    const uint32_t TRACE_SCOM_BASE     = l_ta_finder.trace_scom_base;
    const uint16_t NUM_TRACE_ROWS = max_rows(i_args.trace_bus);
    DEBUG_TRACE_CONTROL = l_ta_finder.debug_scom_base +
                          DEBUG_TRACE_CONTROL_OFS;


    FAPI_DBG("Bus Checking");
    FAPI_ASSERT(l_ta_finder.valid, fapi2::PROC_GETTRACEARRAY_INVALID_BUS()
                .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus),
                "Invalid trace bus specified: 0x%X", i_args.trace_bus);

    FAPI_ASSERT((arg_type & ta_type) != 0, fapi2::PROC_GETTRACEARRAY_INVALID_TARGET()
                .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus).set_REQUIRED_TYPE(ta_type),
                "Specified trace bus requires target type 0x%X, but the supplied target is of type 0x%X",
                ta_type, arg_type);

    // Check if this PAUC target has the requested bus
    if ( ! IS_PEC(i_args.trace_bus))
    {
        FAPI_ASSERT(!( (i_target.getChipletNumber() == 0x10 || i_target.getChipletNumber() == 0x11)
                       &&  ( (i_args.trace_bus == PROC_TB_PAU1_0 || i_args.trace_bus == PROC_TB_PAU1_1) ) ),
                    fapi2::PROC_GETTRACEARRAY_INVALID_BUS()
                    .set_TARGET(i_target)
                    .set_TRACE_BUS(i_args.trace_bus),
                    "This bus (0x%04x) is not available for this PAUC target.", i_args.trace_bus);
    }

    FAPI_DBG("TRACE BUS : 0x%08x", i_args.trace_bus);
    FAPI_DBG("DEBUG ADDR: 0x%08x", DEBUG_TRACE_CONTROL);
    FAPI_DBG("TRACE BASE: 0x%08x", TRACE_SCOM_BASE);

    /* confirm the mux setting unless we are not dumping, or explicitly
       instructed to skip the check */
    if (!i_args.ignore_mux_setting &&
        i_args.collect_dump)
    {
        fapi2::buffer<uint64_t> buf;
        FAPI_TRY(fapi2::getScom(l_trctrl_target,
                                (TRACE_SCOM_BASE + TRACE_TRCTRL_CONFIG_OFS),
                                buf),
                 "Failed to read current trace mux setting");
        uint32_t cur_sel = 0;
        buf.extractToRight<TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL, TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(cur_sel);

        // If the secondary mux select is <4 then this trace must use both muxes; determine if both muxes are set
        // to receive data from the requseted trace bus. Otherwise only check primary mux.
        // The config stores the mux0 in bits 14:15 and the mux1 in bits 16:17 .
        if ( use_sec_mux(l_ta_finder.sec_mux_sel))
        {
            FAPI_ASSERT((cur_sel == ((l_ta_finder.pri_mux_sel << 2) | (l_ta_finder.sec_mux_sel))),
                        fapi2::PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT()
                        .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus).set_MUX_SELECT(cur_sel),
                        "Secondary trace mux is set to %d, but %d is needed for requested trace bus\n"
                        "Primary trace mux is set to %d, but %d is needed for requested trace bus",
                        (cur_sel >> 2), l_ta_finder.sec_mux_sel, (cur_sel & 0x3), l_ta_finder.pri_mux_sel);
        }
        else
        {
            // Muxes that do not have selects will always be 0
            FAPI_ASSERT(cur_sel >> 2 == l_ta_finder.pri_mux_sel,
                        fapi2::PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT()
                        .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus).set_MUX_SELECT(cur_sel),
                        "Primary trace mux is set to %d, but %d is needed for requested trace bus",
                        cur_sel, l_ta_finder.pri_mux_sel);
        }
    }

    /* If control is requested along with dump, pre dump condition
     * should run only once.
     * */
    if (i_args.stop_pre_dump && (!i_args.collect_dump ||
                                 (i_cur_row == P10_TRACEARRAY_FIRST_ROW)))
    {
        FAPI_DBG("Stopping trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_STOP>();

        FAPI_TRY(fapi2::putScom(l_dbg_target, DEBUG_TRACE_CONTROL, buf),
                 "Failed to stop chiplet domain trace arrays");
    }

    if (i_args.collect_dump)
    {
        /* Run the do_dump subroutine, turn the TRACE_RUNNING return code into FFDC */
        fapi2::ReturnCode l_rc = p10_sbe_tracearray_do_dump(l_trctrl_target,
                                 TRACE_SCOM_BASE,
                                 i_num_rows, o_ta_data);
        FAPI_ASSERT(l_rc != fapi2::ReturnCode(fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING),
                    fapi2::PROC_GETTRACEARRAY_TRACE_RUNNING()
                    .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus),
                    "Trace array is still running -- If you think you stopped it, "
                    "maybe the controlling debug macro is slaved to another debug macro?");
        FAPI_TRY(l_rc);
    }

    /* If control is requested along with dump, post dump condition should run
     * only after all the P10_TRACEARRAY_NUM_ROWS rows are read.
     * */
    if (i_args.reset_post_dump &&
        (!i_args.collect_dump ||
         ((i_cur_row + i_num_rows) >= NUM_TRACE_ROWS)))
    {
        FAPI_DBG("Resetting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_RESET>();

        FAPI_TRY(fapi2::putScom(l_dbg_target, DEBUG_TRACE_CONTROL, buf),
                 "Failed to reset chiplet domain trace arrays");
    }

    if (i_args.restart_post_dump &&
        (!i_args.collect_dump ||
         ((i_cur_row + i_num_rows) >= NUM_TRACE_ROWS)))
    {
        FAPI_DBG("Starting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_START>();

        FAPI_TRY(fapi2::putScom(l_dbg_target, DEBUG_TRACE_CONTROL, buf),
                 "Failed to restart chiplet domain trace arrays");
    }

    // mark HWP exit
    FAPI_INF("Success");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

}
