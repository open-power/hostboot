/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_tracearray.C $ */
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
/// @file  p9_sbe_tracearray.C
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
//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_sbe_tracearray.H>

#include <p9_mc_scom_addresses.H>
#include <p9_misc_scom_addresses.H>
#include <p9_obus_scom_addresses.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_quad_scom_addresses.H>
#include <p9_xbus_scom_addresses.H>

p9_tracearray_bus_id NO_TB = (p9_tracearray_bus_id)0;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// offset to store high/low data within a given entry
const uint32_t HI_BIT_OFFSET = 0;
const uint32_t LO_BIT_OFFSET = 64;

const uint32_t DEBUG_TRACE_CONTROL_OFS = PERV_DEBUG_TRACE_CONTROL - PERV_DBG_MODE_REG;

const uint32_t DEBUG_TRACE_CONTROL_START = 0;
const uint32_t DEBUG_TRACE_CONTROL_STOP  = 1;
const uint32_t DEBUG_TRACE_CONTROL_RESET = 2;

const uint32_t TRACE_HI_DATA_OFS         =
    PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG - PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG;
const uint32_t TRACE_LO_DATA_OFS         =
    PERV_TP_TPCHIP_TRA0_TR0_TRACE_LO_DATA_REG - PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG;
const uint32_t TRACE_TRCTRL_CONFIG_OFS   =
    PERV_TP_TPCHIP_TRA0_TR0_TRACE_TRCTRL_CONFIG - PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG;

const uint32_t EX_L21_SCOM_OFFSET        = EQ_TPLC21_TR0_TRACE_HI_DATA_REG - EQ_TPLC20_TR0_TRACE_HI_DATA_REG;
const uint32_t EX_L31_SCOM_OFFSET        = EQ_L3TRA1_TR0_TRACE_HI_DATA_REG - EQ_L3TRA0_TR0_TRACE_HI_DATA_REG;

const uint32_t TRACE_LO_DATA_RUNNING     = PERV_1_TPCHIP_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING;
const uint32_t TRCTRL_MUX0_SEL           = 14;
const uint32_t TRCTRL_MUX0_SEL_LEN       = 2;

const uint32_t TRACE_MUX_POSITIONS       = 1 << TRCTRL_MUX0_SEL_LEN;

const uint32_t TA_BASE_SCOM_MULTIPLIER = 0x00000040;
const uint32_t TA_EX_OFFSET_MULTIPLIER = 0x00000040;
const uint32_t TA_DEBUG_BASE_SCOM      = 0x000107C0;
const uint32_t TA_TRACE_BASE_SCOM      = 0x00010400;
//------------------------------------------------------------------------------
// Table of known trace arrays
//------------------------------------------------------------------------------

struct ta_def
{
    /* One entry per mux setting; value of 0 means N/A */
    p9_tracearray_bus_id bus_ids[TRACE_MUX_POSITIONS];
    const uint8_t chiplet;
    const uint8_t base_multiplier;
    const uint8_t ex_multiplier;
};

static const ta_def ta_defs[] =
{
    /* PERV */
    { { PROC_TB_PIB, PROC_TB_OCC, PROC_TB_TOD },                       0x01,    0x00, 0x00},
    { { PROC_TB_SBE, PROC_TB_PIB_ALT },                                0x01,    0x01, 0x00},
    /* N0 */
    { { PROC_TB_PBIOE0 },                                              0x02,    0x00, 0x00},
    { { PROC_TB_PBIOE1 },                                              0x02,    0x01, 0x00},
    { { PROC_TB_CXA0, PROC_TB_NX },                                    0x02,    0x02, 0x00},
    /* N1 */
    { { PROC_TB_PB6    },                                              0x03,      0x00, 0x00},
    { { PROC_TB_PB7    },                                              0x03,      0x01, 0x00},
    { { PROC_TB_PB8    },                                              0x03,      0x02, 0x00},
    { { PROC_TB_PB9    },                                              0x03,      0x03, 0x00},
    { { PROC_TB_PB10   },                                              0x03,      0x04, 0x00},
    { { PROC_TB_PB11   },                                              0x03,      0x05, 0x00},
    { { PROC_TB_MCD0, PROC_TB_MCD1, PROC_TB_VAS },                     0x03,      0x06, 0x00},
    { { PROC_TB_MCS2, PROC_TB_MCS3, PROC_TB_PB13 },                    0x03,      0x07, 0x00},
    { { PROC_TB_PBIO0  },                                              0x03,      0x08, 0x00},
    { { PROC_TB_PBIO1  },                                              0x03,      0x09, 0x00},
    /* N2 */
    { { PROC_TB_CXA1, PROC_TB_IOPSI },                                 0x04,      0x00, 0x00},
    { { PROC_TB_PCIS0, PROC_TB_PCIS1, PROC_TB_PCIS2 },                 0x04,      0x01, 0x00},
    /* N3 */
    { { PROC_TB_PB0    },                                              0x05,      0x00, 0x00},
    { { PROC_TB_PB1    },                                              0x05,      0x01, 0x00},
    { { PROC_TB_PB2    },                                              0x05,      0x02, 0x00},
    { { PROC_TB_PB3    },                                              0x05,      0x03, 0x00},
    { { PROC_TB_PB4    },                                              0x05,      0x04, 0x00},
    { { PROC_TB_PB5    },                                              0x05,      0x05, 0x00},
    { { PROC_TB_INT, PROC_TB_NPU1, PROC_TB_NMMU1 },                    0x05,      0x06, 0x00},
    { { PROC_TB_MCS0, PROC_TB_MCS1, PROC_TB_PB12 },                    0x05,      0x07, 0x00},
    { { PROC_TB_BRIDGE },                                              0x05,      0x08, 0x00},
    { { PROC_TB_NPU0   },                                              0x05,      0x0A, 0x00},
    { { PROC_TB_NMMU0  },                                              0x05,      0x0B, 0x00},
    /* XBUS */
    { { PROC_TB_PBIOX0, PROC_TB_IOX0 },                                0x06,  0x00, 0x00},
    { { PROC_TB_PBIOX1, PROC_TB_IOX1 },                                0x06,  0x01, 0x00},
    { { PROC_TB_PBIOX2, PROC_TB_IOX2 },                                0x06,  0x03, 0x00},
    /* PCIx */
    { { PROC_TB_PCI0X, PROC_TB_PCI00 },                                0x0D,      0x00, 0x00},
    { { PROC_TB_PCI1X, PROC_TB_PCI11, PROC_TB_PCI12 },                 0x0E,      0x00, 0x00},
    { { PROC_TB_PCI2X, PROC_TB_PCI23, PROC_TB_PCI24, PROC_TB_PCI25 },  0x0F,      0x00, 0x00},
    /* OBUS */
    { { PROC_TB_PBIOOA, PROC_TB_IOO },                                 0x09, 0x00, 0x00},
    /* MC */
    { { PROC_TB_MCA0   },                                              0x07,      0x20, 0x00},
    { { PROC_TB_MCA1   },                                              0x07,      0x21, 0x00},
    { { PROC_TB_IOMC0, PROC_TB_IOMC1, PROC_TB_IOMC2, PROC_TB_IOMC3  }, 0x07,      0x00, 0x00},
    /* EX */
    { { PROC_TB_L20, NO_TB, NO_TB, PROC_TB_SKIT10 },                   0x10,      0x94, 0x0C},
    { { PROC_TB_L21, NO_TB, NO_TB, PROC_TB_SKIT11 },                   0x10,      0x95, 0x0C},
    { { PROC_TB_L30, PROC_TB_NCU0, PROC_TB_CME, PROC_TB_EQPB },        0x10,      0x00, 0x02},
    { { PROC_TB_L31, PROC_TB_NCU1, PROC_TB_IVRM, PROC_TB_SKEWADJ },    0x10,      0x01, 0x02},
    /* CORE */
    { { PROC_TB_CORE0  },                                              0x20,         0x01, 0x00},
    { { PROC_TB_CORE1  },                                              0x20,         0x02, 0x00},
};

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

class TraceArrayFinder
{
    public:
        uint32_t mux_sel;
        uint32_t debug_scom_base;
        uint32_t trace_scom_base;
        uint32_t ex_odd_scom_offset;

        TraceArrayFinder(p9_tracearray_bus_id i_trace_bus) :
            mux_sel(0), debug_scom_base(0),
            trace_scom_base(0), ex_odd_scom_offset(0)
        {
            for(auto& l_ta_def : ta_defs)
            {
                for(size_t sel = 0; sel < TRACE_MUX_POSITIONS; sel++)
                {
                    if(l_ta_def.bus_ids[sel] == i_trace_bus)
                    {
                        fapi2::buffer<uint32_t> l_buffer;
                        l_buffer.insert<0, 8>(l_ta_def.chiplet);
                        debug_scom_base = l_buffer | TA_DEBUG_BASE_SCOM;

                        trace_scom_base = l_buffer |
                                          (TA_TRACE_BASE_SCOM +
                                           TA_BASE_SCOM_MULTIPLIER *
                                           l_ta_def.base_multiplier);

                        // Special handling Core
                        if(l_ta_def.chiplet == 0x20)
                        {
                            trace_scom_base &= 0x00FFFFFF;
                        }

                        ex_odd_scom_offset = TA_EX_OFFSET_MULTIPLIER *
                                             l_ta_def.ex_multiplier;

                        mux_sel = sel;
                        return;
                    }
                }
            }
        }
};

//-----------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------
fapi2::ReturnCode p9_sbe_tracearray(
    const fapi2::Target<P9_SBE_TRACEARRAY_TARGET_TYPES>& i_target,
    const p9_sbe_tracearray_args& i_args,
    uint64_t* o_ta_data,
    const uint32_t i_cur_row,
    const uint32_t i_num_rows
)
{
    fapi2::Target < P9_SBE_TRACEARRAY_TARGET_TYPES |
    fapi2::TARGET_TYPE_EQ > target = i_target;
    FAPI_INF("Start");
    const TraceArrayFinder l_ta_finder(i_args.trace_bus);

    fapi2::TargetType arg_type = i_target.getType();
    fapi2::TargetType ta_type =
        p9_sbe_tracearray_target_type(i_args.trace_bus);

    const uint32_t DEBUG_TRACE_CONTROL = l_ta_finder.debug_scom_base +
                                         DEBUG_TRACE_CONTROL_OFS;
    const uint32_t TRACE_SCOM_BASE     = l_ta_finder.trace_scom_base;
    const uint32_t TRACE_SCOM_OFFSET   = l_ta_finder.ex_odd_scom_offset;

    if ((arg_type & ta_type) == 0)
    {
        FAPI_ERR("Specified trace array requires target type 0x%X,"
                 "but the supplied target is of type 0x%X", ta_type, arg_type);
        return fapi2::RC_PROC_GETTRACEARRAY_INVALID_TARGET;
    }

    /* Nimbus DD1 core traces can't be read out via SCOM.
     * Check an EC feature to see if that's fixed. */
    if (ta_type == fapi2::TARGET_TYPE_CORE)
    {
        uint8_t l_core_trace_scomable = 0;

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> proc_target =
            i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_CORE_TRACE_SCOMABLE,
                               proc_target, l_core_trace_scomable),
                 "Failed to query chip EC feature"
                 "ATTR_CHIP_EC_FEATURE_CORE_TRACE_SCOMABLE");

        if (!l_core_trace_scomable)
        {
            FAPI_ERR("Core arrays cannot be dumped in this chip EC;"
                     "please use fastarray instead.");
            return fapi2::RC_PROC_GETTRACEARRAY_CORE_NOT_DUMPABLE;
        }
    }

    /* For convenience, we link Cache trace arrays to the virtual EX chiplets.
     * Transform back to EQ chiplet. */
    if (ta_type == fapi2::TARGET_TYPE_EX)
    {
        target = i_target.getParent<fapi2::TARGET_TYPE_EQ>();
    }

    /* Check that the trace mux is set up as expected */
    if (!i_args.ignore_mux_setting)
    {
        fapi2::buffer<uint64_t> buf;
        FAPI_TRY(fapi2::getScom(target,
                                TRACE_SCOM_BASE + TRACE_SCOM_OFFSET + TRACE_TRCTRL_CONFIG_OFS,
                                buf),
                 "Failed to read current trace mux setting");
        uint32_t cur_sel = 0;
        buf.extractToRight<TRCTRL_MUX0_SEL, TRCTRL_MUX0_SEL_LEN>(cur_sel);

        if (cur_sel != l_ta_finder.mux_sel)
        {
            FAPI_ERR("Primary trace mux is set to %d,"
                     " but %d is needed for requested trace bus",
                     cur_sel, l_ta_finder.mux_sel);
            return fapi2::RC_PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT;
        }
    }

    /* If control is requested along with dump, pre dump condition
     * should run only once.
     * */
    if (i_args.stop_pre_dump && (!i_args.collect_dump || (i_cur_row == 0)))
    {
        FAPI_DBG("Stopping trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_STOP>();
        FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL, buf),
                 "Failed to stop chiplet domain trace arrays");
    }

    if (i_args.collect_dump)
    {
        fapi2::buffer<uint64_t> buf;

        /* Start with the low data register because that's where the
         * "trace running" bit is. */
        for (uint32_t i = 0; i < i_num_rows; i++)
        {
            FAPI_TRY(fapi2::getScom(target,
                                    TRACE_SCOM_BASE + TRACE_SCOM_OFFSET + TRACE_LO_DATA_OFS,
                                    buf),
                     "Failed to read trace array low data register,"
                     " iteration %d", i);

            /* The "trace running" bit is our best indicator of whether
             * the array is currently running.
             * If it is, the read won't have incremented the address,
             * so it's okay to bail out. */
            if (buf.getBit<TRACE_LO_DATA_RUNNING>())
            {
                FAPI_ERR("Trace array is still running -- "
                         " If you think you stopped it, maybe the controlling "
                         "debug macro is slaved to another debug macro?");
                return fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING;
            }

            *((uint64_t*)o_ta_data + (2 * i + 1)) = buf;
        }

        /*
         * Run empty scoms to move the address pointer of trace array control
         * logic, till it reaches the same row again, as the trace array is
         * a circular buffer
         */
        for (uint32_t i = 0; i < (P9_TRACEARRAY_NUM_ROWS - i_num_rows); i++)
        {
            FAPI_TRY(fapi2::getScom(target,
                                    TRACE_SCOM_BASE + TRACE_SCOM_OFFSET + TRACE_LO_DATA_OFS,
                                    buf),
                     "Failed to read trace array low data register, iteration %d", i);
        }

        /* Then dump the high data */
        for (uint32_t i = 0; i < i_num_rows; i++)
        {
            FAPI_TRY(fapi2::getScom(target,
                                    TRACE_SCOM_BASE + TRACE_SCOM_OFFSET + TRACE_HI_DATA_OFS, buf),
                     "Failed to read trace array high data register, iteration %d", i);
            *((uint64_t*)o_ta_data + (2 * i + 0)) = buf;
        }
    }

    /* If control is requested along with dump, post dump condition should run
     * only after all the P9_TRACEARRAY_NUM_ROWS rows are read.
     * */
    if (i_args.reset_post_dump &&
        (!i_args.collect_dump || (i_cur_row >= P9_TRACEARRAY_NUM_ROWS)))
    {
        FAPI_DBG("Resetting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_RESET>();
        FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL, buf),
                 "Failed to reset chiplet domain trace arrays");
    }

    if (i_args.restart_post_dump &&
        (!i_args.collect_dump || (i_cur_row >= P9_TRACEARRAY_NUM_ROWS)))
    {
        FAPI_DBG("Starting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_START>();
        FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL, buf),
                 "Failed to restart chiplet domain trace arrays");
    }

    // mark HWP exit
    FAPI_INF("Success");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

}
