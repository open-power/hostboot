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
//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p10_sbe_tracearray.H>

//TODO: RTC:202264
//TODO: Replace all comments with p10 specific code


//#include <p10_mc_scom_addresses.H>
//#include <p10_misc_scom_addresses.H>
//#include <p10_obus_scom_addresses.H>
//#include <p10_perv_scom_addresses.H>
//#include <p10_perv_scom_addresses_fld.H>
//#include <p10_quad_scom_addresses.H>
//#include <p10_xbus_scom_addresses.H>

p10_tracearray_bus_id NO_TB = (p10_tracearray_bus_id)0;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// offset to store high/low data within a given entry
const uint32_t HI_BIT_OFFSET = 0;
const uint32_t LO_BIT_OFFSET = 64;

//const uint32_t DEBUG_TRACE_CONTROL_OFS = PERV_DEBUG_TRACE_CONTROL - PERV_DBG_MODE_REG;

const uint32_t DEBUG_TRACE_CONTROL_START = 0;
const uint32_t DEBUG_TRACE_CONTROL_STOP  = 1;
const uint32_t DEBUG_TRACE_CONTROL_RESET = 2;

//const uint32_t TRACE_HI_DATA_OFS         =
//    PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG - PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG;
//const uint32_t TRACE_LO_DATA_OFS         =
//    PERV_TP_TPCHIP_TRA0_TR0_TRACE_LO_DATA_REG - PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG;
//const uint32_t TRACE_TRCTRL_CONFIG_OFS   =
//    PERV_TP_TPCHIP_TRA0_TR0_TRACE_TRCTRL_CONFIG - PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG;

//const uint32_t EX_L21_SCOM_OFFSET        = EQ_TPLC21_TR0_TRACE_HI_DATA_REG - EQ_TPLC20_TR0_TRACE_HI_DATA_REG;
//const uint32_t EX_L31_SCOM_OFFSET        = EQ_L3TRA1_TR0_TRACE_HI_DATA_REG - EQ_L3TRA0_TR0_TRACE_HI_DATA_REG;

//const uint32_t TRACE_LO_DATA_RUNNING     = PERV_1_TPCHIP_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING;
const uint32_t TRCTRL_MUX0_SEL           = 14;
const uint32_t TRCTRL_MUX0_SEL_LEN       = 2;
const uint32_t TRCTRL_HOLD_OFF           = 18;
const uint32_t TRCTRL_RUN_STATUS         = 19;

const uint32_t TRACE_MUX_POSITIONS       = 1 << TRCTRL_MUX0_SEL_LEN;

const uint32_t TA_BASE_SCOM_MULTIPLIER = 0x00000040;
const uint32_t TA_DEBUG_BASE_SCOM      = 0x000107C0;
const uint32_t TA_TRACE_BASE_SCOM      = 0x00010400;
//------------------------------------------------------------------------------
// Table of known trace arrays
//------------------------------------------------------------------------------

enum chip_type_and_ec
{
    ANY_CHIP = 0xFF,
};

struct ta_def
{
    /* One entry per mux setting; value of 0 means N/A */
    p10_tracearray_bus_id bus_ids[TRACE_MUX_POSITIONS];
    const uint8_t ex_odd_scom_offset: 2;
        const uint8_t chiplet: 6;
        const uint8_t base_multiplier;
        const uint8_t chip_type_and_ec;
    };

    static const ta_def ta_defs[] =
{
    /* PERV */
    { { PROC_TB_PIB, PROC_TB_OCC, PROC_TB_TOD },                       0x00, 0x01, 0x00, ANY_CHIP },
    { { PROC_TB_SBE, PROC_TB_PIB_ALT },                                0x00, 0x01, 0x01, ANY_CHIP },
    /* N0 */
    { { PROC_TB_PBIOE0 },                                              0x00, 0x02, 0x00, ANY_CHIP },
    { { PROC_TB_PBIOE1 },                                              0x00, 0x02, 0x01, ANY_CHIP },
    { { PROC_TB_CXA0, PROC_TB_NX },                                    0x00, 0x02, 0x02, ANY_CHIP },
    /* N1 */
    { { PROC_TB_PB6    },                                              0x00, 0x03, 0x00, ANY_CHIP },
    { { PROC_TB_PB7    },                                              0x00, 0x03, 0x01, ANY_CHIP },
    { { PROC_TB_PB8    },                                              0x00, 0x03, 0x02, ANY_CHIP },
    { { PROC_TB_PB9    },                                              0x00, 0x03, 0x03, ANY_CHIP },
    { { PROC_TB_PB10   },                                              0x00, 0x03, 0x04, ANY_CHIP },
    { { PROC_TB_PB11   },                                              0x00, 0x03, 0x05, ANY_CHIP },
    { { PROC_TB_MCD0, PROC_TB_MCD1, PROC_TB_VAS },                     0x00, 0x03, 0x06, ANY_CHIP },
    { { PROC_TB_MCS2, PROC_TB_MCS3, PROC_TB_PB13 },                    0x00, 0x03, 0x07, ANY_CHIP },
    { { PROC_TB_PBIO0  },                                              0x00, 0x03, 0x08, ANY_CHIP },
    { { PROC_TB_PBIO1  },                                              0x00, 0x03, 0x09, ANY_CHIP },
    /* N2 */
    { { PROC_TB_CXA1, PROC_TB_IOPSI },                                 0x00, 0x04, 0x00, ANY_CHIP },
    { { PROC_TB_PCIS0, PROC_TB_PCIS1, PROC_TB_PCIS2 },                 0x00, 0x04, 0x01, ANY_CHIP },
    /* N3 */
    { { PROC_TB_PB0    },                                              0x00, 0x05, 0x00, ANY_CHIP },
    { { PROC_TB_PB1    },                                              0x00, 0x05, 0x01, ANY_CHIP },
    { { PROC_TB_PB2    },                                              0x00, 0x05, 0x02, ANY_CHIP },
    { { PROC_TB_PB3    },                                              0x00, 0x05, 0x03, ANY_CHIP },
    { { PROC_TB_PB4    },                                              0x00, 0x05, 0x04, ANY_CHIP },
    { { PROC_TB_PB5    },                                              0x00, 0x05, 0x05, ANY_CHIP },
    { { PROC_TB_INT, PROC_TB_NPU1, PROC_TB_NMMU1 },                    0x00, 0x05, 0x06, ANY_CHIP },
    { { PROC_TB_MCS0, PROC_TB_MCS1, PROC_TB_PB12 },                    0x00, 0x05, 0x07, ANY_CHIP },
    { { PROC_TB_BRIDGE },                                              0x00, 0x05, 0x08, ANY_CHIP },
    { { PROC_TB_NPU0   },                                              0x00, 0x05, 0x0A, ANY_CHIP },
    { { PROC_TB_NMMU0  },                                              0x00, 0x05, 0x0B, ANY_CHIP },
    /* XBUS */
    { { PROC_TB_PBIOX0, PROC_TB_IOX0 },                                0x00, 0x06, 0x00, ANY_CHIP },
    { { PROC_TB_PBIOX1, PROC_TB_IOX1 },                                0x00, 0x06, 0x01, ANY_CHIP },
    { { PROC_TB_PBIOX2, PROC_TB_IOX2 },                                0x00, 0x06, 0x02, ANY_CHIP },
    /* PCIx */
    { { PROC_TB_PCI0X, PROC_TB_PCI00 },                                0x00, 0x0D, 0x00, ANY_CHIP },
    { { PROC_TB_PCI1X, PROC_TB_PCI11, PROC_TB_PCI12 },                 0x00, 0x0E, 0x00, ANY_CHIP },
    { { PROC_TB_PCI2X, PROC_TB_PCI23, PROC_TB_PCI24, PROC_TB_PCI25 },  0x00, 0x0F, 0x00, ANY_CHIP },
    /* OBUS */
    { { PROC_TB_PBIOOA, PROC_TB_IOO },                                 0x00, 0x09, 0x00, ANY_CHIP },
    /* MC */
    //{ { PROC_TB_MCA0   },                                              0x00, 0x07, 0x20, NIMBUS },
    //{ { PROC_TB_MCA1   },                                              0x00, 0x07, 0x21, NIMBUS },
    //{ { PROC_TB_IOMC0, PROC_TB_IOMC1, PROC_TB_IOMC2, PROC_TB_IOMC3  }, 0x00, 0x07, 0x00, NIMBUS },
    //{ { PROC_TB_MCA0   },                                              0x00, 0x07, 0x00, (uint8_t)~NIMBUS },
    //{ { PROC_TB_MCA1   },                                              0x00, 0x07, 0x01, (uint8_t)~NIMBUS },
    //{ { PROC_TB_IOMC0, PROC_TB_IOMC1, PROC_TB_IOMC2, PROC_TB_IOMC3  }, 0x00, 0x07, 0x02, (uint8_t)~NIMBUS },
    /* EX */
    { { PROC_TB_L20, NO_TB, NO_TB, PROC_TB_SKIT10 },                   0x01, 0x10, 0x94, ANY_CHIP },
    { { PROC_TB_L21, NO_TB, NO_TB, PROC_TB_SKIT11 },                   0x01, 0x10, 0x95, ANY_CHIP },
    { { PROC_TB_L30, PROC_TB_NCU0, PROC_TB_CME, PROC_TB_EQPB },        0x02, 0x10, 0x00, ANY_CHIP },
    { { PROC_TB_L31, PROC_TB_NCU1, PROC_TB_IVRM, PROC_TB_SKEWADJ },    0x02, 0x10, 0x01, ANY_CHIP },
    /* CORE */
    { { PROC_TB_CORE0  },                                              0x00, 0x20, 0x41, ANY_CHIP },
    { { PROC_TB_CORE1  },                                              0x00, 0x20, 0x42, ANY_CHIP }
};

class TraceArrayFinder
{
    public:
        bool valid;
        uint32_t mux_sel;
        uint32_t debug_scom_base;
        uint32_t trace_scom_base;
        uint32_t ex_odd_scom_offset;

        TraceArrayFinder(p10_tracearray_bus_id i_trace_bus, chip_type_and_ec i_chip_type_and_ec) :
            valid(false), mux_sel(0), debug_scom_base(0),
            trace_scom_base(0), ex_odd_scom_offset(0)
        {
            for(auto& l_ta_def : ta_defs)
            {
                for(size_t sel = 0; sel < TRACE_MUX_POSITIONS; sel++)
                {
                    if((l_ta_def.bus_ids[sel] == i_trace_bus) &&
                       ((l_ta_def.chip_type_and_ec & i_chip_type_and_ec) != 0))
                    {
                        uint32_t l_buffer = 0;
                        l_buffer |= l_ta_def.chiplet << 24;
                        debug_scom_base = l_buffer | TA_DEBUG_BASE_SCOM;

                        trace_scom_base = l_buffer |
                                          (TA_TRACE_BASE_SCOM +
                                           TA_BASE_SCOM_MULTIPLIER *
                                           l_ta_def.base_multiplier);
                        ex_odd_scom_offset = l_ta_def.ex_odd_scom_offset;
                        mux_sel = sel;
                        valid = true;
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
 * On DD1 that capability is not available, so we have to skip the SCOM operations to the TRCTRL register
 * and can check for running trace by looking at the trace_running bit in the returned trace data.
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
    const fapi2::Target < P10_SBE_TRACEARRAY_TARGET_TYPES | fapi2::TARGET_TYPE_EQ > &i_target,
    const uint32_t i_scom_base,
    const uint32_t i_num_rows,
    uint64_t* o_ta_data)
{
    bool l_reset_trace_ctrl = false;
    fapi2::buffer<uint64_t> l_trace_ctrl;
    //fapi2::buffer<uint64_t> buf = 0;
    uint8_t l_trctrl_has_no_run_bits = 0;

    //fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> proc_target =
    //    i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_TRCTRL_HAS_NO_RUN_BITS,
    //                       proc_target, l_trctrl_has_no_run_bits),
    //         "Failed to query chip EC feature "
    //         "ATTR_CHIP_EC_FEATURE_TRCTRL_HAS_NO_RUN_BITS");

    /* weird doubly inverted logic because the EC attr XML definition doesn't have inversion
     * and I don't want to add new XML every time we decide to build another P10 variant */
    if (!l_trctrl_has_no_run_bits)
    {
        //FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_TRCTRL_CONFIG_OFS, l_trace_ctrl),
        //         "Failed to read current trace control setting");

        //if (l_trace_ctrl.getBit<TRCTRL_RUN_STATUS>())
        //{
        //    FAPI_TRY(fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING);
        //}

        //l_trace_ctrl.setBit<TRCTRL_HOLD_OFF>();
        //FAPI_TRY(fapi2::putScom(i_target, i_scom_base + TRACE_TRCTRL_CONFIG_OFS, l_trace_ctrl),
        //         "Failed to enable holding trace_run off; a possible reason is that "
        //         "tracing was started just before the SCOM access");
        //l_reset_trace_ctrl = true;
    }

    /* Start with the low data register because that's where the
     * "trace running" bit is. */
    for (uint32_t i = 0; i < i_num_rows; i++)
    {
        //FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_LO_DATA_OFS, buf),
        //         "Failed to read trace array low data register,"
        //         " iteration %d", i);

        ///* On DD1, the "trace running" bit is our best indicator of whether
        // * the array is currently running.
        // * If it is, the read won't have incremented the address,
        // * so it's okay to bail out. */
        //if (buf.getBit<TRACE_LO_DATA_RUNNING>())
        //{
        //    FAPI_TRY(fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING);
        //}

        //*(o_ta_data + (2 * i + 1)) = buf;
    }

    /*
     * Run empty scoms to move the address pointer of trace array control
     * logic, till it reaches the same row again, as the trace array is
     * a circular buffer
     */
    for (uint32_t i = 0; i < (P10_TRACEARRAY_NUM_ROWS - i_num_rows); i++)
    {
        //FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_LO_DATA_OFS, buf),
        //         "Failed to read trace array low data register, "
        //         "iteration %d", i);
    }

    /* Then dump the high data */
    for (uint32_t i = 0; i < i_num_rows; i++)
    {
        //FAPI_TRY(fapi2::getScom(i_target, i_scom_base + TRACE_HI_DATA_OFS, buf),
        //         "Failed to read trace array high data register, "
        //         "iteration %d", i);
        //*(o_ta_data + (2 * i + 0)) = buf;
    }

fapi_try_exit:

    if (l_reset_trace_ctrl)
    {
        //l_trace_ctrl.clearBit<TRCTRL_HOLD_OFF>();
        //fapi2::ReturnCode l_rc = fapi2::putScom(i_target, i_scom_base + TRACE_TRCTRL_CONFIG_OFS, l_trace_ctrl);

        //if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        //{
        //    FAPI_ERR("Failed to stop holding trace_run off");

        //    if (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS)
        //    {
        //        fapi2::current_err = l_rc;
        //    }
        //}
    }

    return fapi2::current_err;
}

static chip_type_and_ec map_chip_type_and_ec(fapi2::ATTR_NAME_Type i_name, fapi2::ATTR_EC_Type i_ec)
{
    return ANY_CHIP;
}

fapi2::ReturnCode p10_sbe_tracearray(
    const fapi2::Target<P10_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
    const proc_gettracearray_args& i_args,
    uint64_t* o_ta_data,
    const uint32_t i_cur_row,
    const uint32_t i_num_rows
)
{
    fapi2::Target < P10_SBE_TRACEARRAY_TARGET_TYPES | fapi2::TARGET_TYPE_EQ > target = i_target;
    FAPI_INF("Start");

    fapi2::ATTR_NAME_Type l_name;
    fapi2::ATTR_EC_Type l_ec;
    fapi2::ReturnCode l_rc = fapi2::queryChipEcAndName(i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(), l_name, l_ec);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Failed to query proc chip name and EC level");
        return l_rc;
    }

    FAPI_INF("Chip type/EC: %d/0x%02x", l_name, l_ec);

    const TraceArrayFinder l_ta_finder(i_args.trace_bus, map_chip_type_and_ec(l_name, l_ec));

    fapi2::TargetType arg_type = i_target.getType();
    fapi2::TargetType ta_type =
        p10_sbe_tracearray_target_type(i_args.trace_bus);

    //const uint32_t DEBUG_TRACE_CONTROL = l_ta_finder.debug_scom_base +
    //                                     DEBUG_TRACE_CONTROL_OFS;
    const uint32_t TRACE_SCOM_BASE     = l_ta_finder.trace_scom_base;
    uint32_t tra_scom_offset = 0;
    uint32_t l_proc_offset = 0;

    FAPI_ASSERT(l_ta_finder.valid, fapi2::PROC_GETTRACEARRAY_INVALID_BUS()
                .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus),
                "Invalid trace bus specified: 0x%X", i_args.trace_bus);

    FAPI_ASSERT((arg_type & ta_type) != 0, fapi2::PROC_GETTRACEARRAY_INVALID_TARGET()
                .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus).set_REQUIRED_TYPE(ta_type),
                "Specified trace bus requires target type 0x%X, but the supplied target is of type 0x%X",
                ta_type, arg_type);

    {
        /* There is no support for OBUS and MCBIST on SBE.
         * These are passed as PERV targets, but have to be converted to
         * PROC with manual address offset for chiplet, as trace scoms
         * are not allowed for PERV targets in Cronus */
        const uint8_t l_chiplet_num = i_target.getChipletNumber();

        if(IS_MCBIST(l_chiplet_num) || IS_OBUS(l_chiplet_num))
        {
            target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
            l_proc_offset = (l_chiplet_num << 24) - (TRACE_SCOM_BASE & 0xFF000000);
        }
    }

    /* check that core trace arrays can be logged out, based on EC feature attribute */
    if (ta_type == fapi2::TARGET_TYPE_CORE)
    {
        uint8_t l_core_trace_not_scomable = 0;

        //fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> proc_target =
        //    i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_CORE_TRACE_NOT_SCOMABLE,
        //                       proc_target, l_core_trace_not_scomable),
        //         "Failed to query chip EC feature "
        //         "ATTR_CHIP_EC_FEATURE_CORE_TRACE_NOT_SCOMABLE");

        FAPI_ASSERT(!l_core_trace_not_scomable ||
                    !i_args.collect_dump,
                    fapi2::PROC_GETTRACEARRAY_CORE_NOT_DUMPABLE()
                    .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus),
                    "Core arrays cannot be dumped in this chip EC; please use fastarray instead.");
    }

    /* For convenience, we link Cache trace arrays to the virtual EX chiplets.
     * Transform back to EQ chiplet. */
    if (ta_type == fapi2::TARGET_TYPE_EX)
    {
        target = i_target.getParent<fapi2::TARGET_TYPE_EQ>();
        uint8_t l_chipunit_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               i_target,
                               l_chipunit_num),
                 "Failed to get chipUnit ID from EX target");

        if (l_chipunit_num & 1)
        {
            if(l_ta_finder.ex_odd_scom_offset == 0x01)
            {
                //tra_scom_offset = EX_L21_SCOM_OFFSET;
            }
            else if(l_ta_finder.ex_odd_scom_offset == 0x02)
            {
                //tra_scom_offset = EX_L31_SCOM_OFFSET;
            }
        }
    }

    /* confirm the mux setting unless we are not dumping, or explicitly
       instructed to skip the check */
    if (!i_args.ignore_mux_setting &&
        i_args.collect_dump)
    {
        fapi2::buffer<uint64_t> buf;
        //FAPI_TRY(fapi2::getScom(target,
        //                        (TRACE_SCOM_BASE +
        //                         tra_scom_offset +
        //                         TRACE_TRCTRL_CONFIG_OFS +
        //                         l_proc_offset),
        //                        buf),
        //         "Failed to read current trace mux setting");
        uint32_t cur_sel = 0;
        buf.extractToRight<TRCTRL_MUX0_SEL, TRCTRL_MUX0_SEL_LEN>(cur_sel);

        FAPI_ASSERT(cur_sel == l_ta_finder.mux_sel, fapi2::PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT()
                    .set_TARGET(i_target).set_TRACE_BUS(i_args.trace_bus).set_MUX_SELECT(cur_sel),
                    "Primary trace mux is set to %d, but %d is needed for requested trace bus",
                    cur_sel, l_ta_finder.mux_sel);
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
        //FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL + l_proc_offset, buf),
        //         "Failed to stop chiplet domain trace arrays");
    }

    if (i_args.collect_dump)
    {
        /* Run the do_dump subroutine, turn the TRACE_RUNNING return code into FFDC */
        fapi2::ReturnCode l_rc = p10_sbe_tracearray_do_dump(target,
                                 TRACE_SCOM_BASE + tra_scom_offset + l_proc_offset,
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
         ((i_cur_row + i_num_rows) >= P10_TRACEARRAY_NUM_ROWS)))
    {
        FAPI_DBG("Resetting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_RESET>();
        //FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL + l_proc_offset, buf),
        //         "Failed to reset chiplet domain trace arrays");
    }

    if (i_args.restart_post_dump &&
        (!i_args.collect_dump ||
         ((i_cur_row + i_num_rows) >= P10_TRACEARRAY_NUM_ROWS)))
    {
        FAPI_DBG("Starting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_START>();
        //FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL + l_proc_offset, buf),
        //         "Failed to restart chiplet domain trace arrays");
    }

    // mark HWP exit
    FAPI_INF("Success");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

}
