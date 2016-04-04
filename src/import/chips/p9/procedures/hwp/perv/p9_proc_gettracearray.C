/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_proc_gettracearray.C $ */
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
/// @file  p9_proc_gettracearray.C
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

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p9_proc_gettracearray.H"

#include <p9_mc_scom_addresses.H>
#include <p9_misc_scom_addresses.H>
#include <p9_obus_scom_addresses.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_quad_scom_addresses.H>
#include <p9_xbus_scom_addresses.H>

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

//------------------------------------------------------------------------------
// Table of known trace arrays
//------------------------------------------------------------------------------

struct ta_def
{
    /* One entry per mux setting; value of 0 means N/A */
    proc_gettracearray_bus_id bus_ids[TRACE_MUX_POSITIONS];
    uint32_t debug_scom_base, trace_scom_base, ex_odd_scom_offset;
};

proc_gettracearray_bus_id NO_TB = (proc_gettracearray_bus_id)0;

static const ta_def ta_defs[] =
{
    /* PERV */
    { { PROC_TB_PIB, PROC_TB_OCC, PROC_TB_TOD },                       PERV_TP_DBG_MODE_REG,    PERV_TP_TPCHIP_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_SBE, PROC_TB_PIB_ALT },                                PERV_TP_DBG_MODE_REG,    PERV_TP_TPCHIP_TRA0_TR1_TRACE_HI_DATA_REG },
    /* N0 */
    { { PROC_TB_PBIOE0 },                                              PU_N0_DBG_MODE_REG,      PU_TCN0_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PBIOE1 },                                              PU_N0_DBG_MODE_REG,      PU_TCN0_TRA0_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_CXA0, PROC_TB_NX },                                    PU_N0_DBG_MODE_REG,      PU_TCN0_TRA1_TR0_TRACE_HI_DATA_REG },
    /* N1 */
    { { PROC_TB_PB6    },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PB7    },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA0_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_PB8    },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA1_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PB9    },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA1_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_PB10   },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA2_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PB11   },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA2_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_MCD0, PROC_TB_MCD1, PROC_TB_VAS },                     PU_N1_DBG_MODE_REG,      PU_TCN1_TRA3_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_MCS2, PROC_TB_MCS3, PROC_TB_PB13 },                    PU_N1_DBG_MODE_REG,      PU_TCN1_TRA3_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_PBIO0  },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA4_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PBIO1  },                                              PU_N1_DBG_MODE_REG,      PU_TCN1_TRA4_TR1_TRACE_HI_DATA_REG },
    /* N2 */
    { { PROC_TB_CXA1, PROC_TB_IOPSI },                                 PU_N2_DBG_MODE_REG,      PU_TCN2_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PCIS0, PROC_TB_PCIS1, PROC_TB_PCIS2 },                 PU_N2_DBG_MODE_REG,      PU_TCN2_TRA0_TR1_TRACE_HI_DATA_REG },
    /* N3 */
    { { PROC_TB_PB0    },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PB1    },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA0_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_PB2    },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA1_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PB3    },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA1_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_PB4    },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA2_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PB5    },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA2_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_INT, PROC_TB_NPU1, PROC_TB_NMMU1 },                    PU_N3_DBG_MODE_REG,      PU_TCN3_TRA3_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_MCS0, PROC_TB_MCS1, PROC_TB_PB12 },                    PU_N3_DBG_MODE_REG,      PU_TCN3_TRA3_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_BRIDGE },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA4_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_NPU0   },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA5_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_NMMU0  },                                              PU_N3_DBG_MODE_REG,      PU_TCN3_TRA5_TR1_TRACE_HI_DATA_REG },
    /* XBUS */
    { { PROC_TB_PBIOX0, PROC_TB_IOX0 },                                XBUS_PERV_DBG_MODE_REG,  XBUS_PERV_TCXB_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PBIOX1, PROC_TB_IOX1 },                                XBUS_PERV_DBG_MODE_REG,  XBUS_PERV_TCXB_TRA0_TR1_TRACE_HI_DATA_REG },
    { { PROC_TB_PBIOX2, PROC_TB_IOX2 },                                XBUS_PERV_DBG_MODE_REG,  XBUS_PERV_TCXB_TRA1_TR0_TRACE_HI_DATA_REG },
    /* PCIx */
    { { PROC_TB_PCI0X, PROC_TB_PCI00 },                                PEC_0_DBG_MODE_REG,      PEC_0_TCPCI0_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PCI1X, PROC_TB_PCI11, PROC_TB_PCI12 },                 PEC_1_DBG_MODE_REG,      PEC_1_TCPCI1_TRA0_TR0_TRACE_HI_DATA_REG },
    { { PROC_TB_PCI2X, PROC_TB_PCI23, PROC_TB_PCI24, PROC_TB_PCI25 },  PEC_2_DBG_MODE_REG,      PEC_2_TCPCI2_TRA0_TR0_TRACE_HI_DATA_REG },
    /* OBUS */
    { { PROC_TB_PBIOOA, PROC_TB_IOO },                                 OBUS_TCOB0_DBG_MODE_REG, OBUS_TCOB0_TRA0_TR0_TRACE_HI_DATA_REG },
    /* MC */
    { { PROC_TB_MCA0   },                                              MCA_3_DBG_MODE_REG,      PU_TCMC01_FAST_TRA0_TRACE_HI_DATA_REG },
    { { PROC_TB_MCA1   },                                              MCA_3_DBG_MODE_REG,      PU_TCMC01_FAST_TRA1_TRACE_HI_DATA_REG },
    { { PROC_TB_IOMC0, PROC_TB_IOMC1, PROC_TB_IOMC2, PROC_TB_IOMC3  }, MCA_3_DBG_MODE_REG,      MCA_TCMC01_SLOW_TRA0_TRACE_HI_DATA_REG },
    /* EX */
    { { PROC_TB_L20, NO_TB, NO_TB, PROC_TB_SKIT10 },                   EQ_DBG_MODE_REG,         EQ_TPLC20_TR0_TRACE_HI_DATA_REG, EX_L21_SCOM_OFFSET },
    { { PROC_TB_L21, NO_TB, NO_TB, PROC_TB_SKIT11 },                   EQ_DBG_MODE_REG,         EQ_TPLC20_TR1_TRACE_HI_DATA_REG, EX_L21_SCOM_OFFSET },
    { { PROC_TB_L30, PROC_TB_NCU0, PROC_TB_CME, PROC_TB_EQPB },        EQ_DBG_MODE_REG,         EQ_L3TRA0_TR0_TRACE_HI_DATA_REG, EX_L31_SCOM_OFFSET },
    { { PROC_TB_L31, PROC_TB_NCU1, PROC_TB_IVRM, PROC_TB_SKEWADJ },    EQ_DBG_MODE_REG,         EQ_L3TRA0_TR1_TRACE_HI_DATA_REG, EX_L31_SCOM_OFFSET },
    /* CORE */
    { { PROC_TB_CORE0  },                                              C_DBG_MODE_REG,          0x00011440 },
    { { PROC_TB_CORE1  },                                              C_DBG_MODE_REG,          0x00011480 },
};

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

class TraceArrayFinder
{
    public:
        const ta_def* pdef;
        uint32_t mux_sel;

        TraceArrayFinder(proc_gettracearray_bus_id i_trace_bus) : pdef(NULL), mux_sel(0)
        {
            for (unsigned int i = 0; i < ARRAY_SIZE(ta_defs); i++)
            {
                for (uint32_t sel = 0; sel < TRACE_MUX_POSITIONS; sel++)
                {
                    if (ta_defs[i].bus_ids[sel] == i_trace_bus)
                    {
                        pdef = ta_defs + i;
                        mux_sel = sel;
                        return;
                    }
                }
            }
        }
};

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
extern "C" fapi2::ReturnCode p9_proc_gettracearray(
    const fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES>& i_target,
    const proc_gettracearray_args& i_args,
    fapi2::variable_buffer& o_ta_data)
{
    fapi2::Target < PROC_GETTRACEARRAY_TARGET_TYPES | fapi2::TARGET_TYPE_EQ > target = i_target;
    uint32_t tra_scom_offset = 0;

    // mark HWP entry
    FAPI_IMP("Entering ...");

    const TraceArrayFinder l_ta_finder(i_args.trace_bus);

    if (!l_ta_finder.pdef)
    {
        FAPI_ERR("Unsupported trace bus identifier %d specified", i_args.trace_bus);
        return fapi2::RC_PROC_GETTRACEARRAY_INVALID_BUS;
        ;
    }

    const uint32_t DEBUG_TRACE_CONTROL = l_ta_finder.pdef->debug_scom_base + DEBUG_TRACE_CONTROL_OFS;
    const uint32_t TRACE_SCOM_BASE     = l_ta_finder.pdef->trace_scom_base;

    fapi2::TargetType arg_type = i_target.getType();
    fapi2::TargetType ta_type = proc_gettracearray_target_type(i_args.trace_bus);

    if ((arg_type & ta_type) == 0)
    {
        FAPI_ERR("Specified trace array requires target type 0x%X, but the supplied target is of type 0x%X", ta_type, arg_type);
        return fapi2::RC_PROC_GETTRACEARRAY_INVALID_TARGET;
    }

    /* Nimbus DD1 core traces can't be read out via SCOM. Check an EC feature to see if that's fixed. */
    if (ta_type == fapi2::TARGET_TYPE_CORE)
    {
        uint8_t l_core_trace_scomable = 0;

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> proc_target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_CORE_TRACE_SCOMABLE, proc_target, l_core_trace_scomable),
                 "Failed to query chip EC feature ATTR_CHIP_EC_FEATURE_CORE_TRACE_SCOMABLE");

        if (!l_core_trace_scomable)
        {
            FAPI_ERR("Core arrays cannot be dumped in this chip EC; please use fastarray instead.");
            return fapi2::RC_PROC_GETTRACEARRAY_CORE_NOT_DUMPABLE;
        }
    }

    /* For convenience, we link Cache trace arrays to the virtual EX chiplets. Transform back
     * to EQ chiplet and SCOM address offset. */
    if (ta_type == fapi2::TARGET_TYPE_EX)
    {
        uint8_t l_chipunit_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_chipunit_num),
                 "Failed to get chipUnit ID from EX target");
        target = i_target.getParent<fapi2::TARGET_TYPE_EQ>();

        if (l_chipunit_num & 1)
        {
            tra_scom_offset = l_ta_finder.pdef->ex_odd_scom_offset;
        }
    }

    /* Check that the trace mux is set up as expected */
    if (!i_args.ignore_mux_setting)
    {
        fapi2::buffer<uint64_t> buf;
        FAPI_TRY(fapi2::getScom(target, TRACE_SCOM_BASE + tra_scom_offset + TRACE_TRCTRL_CONFIG_OFS, buf),
                 "Failed to read current trace mux setting");
        uint32_t cur_sel = 0;
        buf.extractToRight<TRCTRL_MUX0_SEL, TRCTRL_MUX0_SEL_LEN>(cur_sel);

        if (cur_sel != l_ta_finder.mux_sel)
        {
            FAPI_ERR("Primary trace mux is set to %d, but %d is needed for requested trace bus", cur_sel, l_ta_finder.mux_sel);
            return fapi2::RC_PROC_GETTRACEARRAY_TRACE_MUX_INCORRECT;
        }
    }

    if (i_args.stop_pre_dump)
    {
        FAPI_DBG("Stopping trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_STOP>();
        FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL, buf), "Failed to stop chiplet domain trace arrays");
    }

    if (i_args.collect_dump)
    {
        fapi2::buffer<uint64_t> buf;
        o_ta_data.resize(PROC_GETTRACEARRAY_NUM_ENTRIES * PROC_GETTRACEARRAY_BITS_PER_ENTRY).flush<0>();

        /* Start with the low data register because that's where the "trace running" bit is. */
        for (int i = 0; i < PROC_GETTRACEARRAY_NUM_ENTRIES; i++)
        {
            FAPI_TRY(fapi2::getScom(target, TRACE_SCOM_BASE + tra_scom_offset + TRACE_LO_DATA_OFS, buf),
                     "Failed to read trace array low data register, iteration %d", i);

            /* The "trace running" bit is our best indicator of whether the array is currently running.
             * If it is, the read won't have incremented the address, so it's okay to bail out. */
            if (buf.getBit<TRACE_LO_DATA_RUNNING>())
            {
                FAPI_ERR("Trace array is still running -- If you think you stopped it, maybe the controlling debug macro is slaved to another debug macro?");
                return fapi2::RC_PROC_GETTRACEARRAY_TRACE_RUNNING;
            }

            FAPI_TRY(o_ta_data.set<uint64_t>(buf, 2 * i + 1), "Failed to insert data into trace buffer");
        }

        /* Then dump the high data */
        for (int i = 0; i < PROC_GETTRACEARRAY_NUM_ENTRIES; i++)
        {
            FAPI_TRY(fapi2::getScom(target, TRACE_SCOM_BASE + tra_scom_offset + TRACE_HI_DATA_OFS, buf),
                     "Failed to read trace array high data register, iteration %d", i);
            FAPI_TRY(o_ta_data.set<uint64_t>(buf, 2 * i + 0), "Failed to insert data into trace buffer");
        }
    }

    if (i_args.reset_post_dump)
    {
        FAPI_DBG("Resetting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_RESET>();
        FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL, buf), "Failed to reset chiplet domain trace arrays");
    }

    if (i_args.restart_post_dump)
    {
        FAPI_DBG("Starting trace arrays");
        fapi2::buffer<uint64_t> buf;
        buf.flush<0>().setBit<DEBUG_TRACE_CONTROL_START>();
        FAPI_TRY(fapi2::putScom(target, DEBUG_TRACE_CONTROL, buf), "Failed to restart chiplet domain trace arrays");
    }

    // mark HWP exit
    FAPI_IMP("Success");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
