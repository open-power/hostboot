/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_utils.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
//
// @file p10_tod_utils.H
// @brief Utilities and classes for the tod_init and tod_setup procedures
//
// *HWP HW Maintainer    : Douglas Holtsinger <Douglas.Holtsinger@ibm.com>
// *HWP FW Maintainer    : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by      : HB,FSP
//
//------------------------------------------------------------------------------

#ifndef _P10_TOD_UTILS_H_
#define _P10_TOD_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// See P10 FBC Workbook:
// "The total latency in optic clock cycles is the TOD Latency value
// (from the latency measure register) plus half the round-trip time
// plus 5 cycles."
const uint32_t P10_TOD_SETUP_LATENCY_FIXED_OPTIC_CYCLES = 5;

// This is the TOD sync pulse latency when the Sync Pulse terminates at a
// TOD node, in terms of PAU clocks.
// This latency is measured from the transition of the Sync pulse at the
// input of TOD block (xb_tp_xY_tod_sync(0:1)) to the transition of the
// Sync pulse at the output of the Delay component of the I_PATH block configured
// with zero delay (PIB.TOD.I_PATH.DELAY.SYNC_OUT_Q_INST.LATC.L2).
// It does not include any Fabric latency.
const uint32_t P10_TOD_SETUP_SYNC_RECEIVE_LATENCY = 9;

// This is the TOD sync pulse latency when Forwarding the Sync Pulse through
// a TOD node in a 2 or more hop network, in terms of PAU clocks.
// This latency is measured from the transition of the Sync pulse at the
// input of TOD block (xb_tp_xY_tod_sync(0:1)) to the transition of the
// Sync pulse at the output of the TOD block (tp_xb_xY_tod_sync(0:1))
// It does not include any Fabric latency.
const uint32_t P10_TOD_SETUP_SYNC_FORWARDING_LATENCY = 8;

// Minimum/Maximum allowable delay for any node
const uint32_t MIN_TOD_DELAY = 0;
const uint32_t MAX_TOD_DELAY = 0x3FF;

// TOD operation delay times for HW/sim
const uint32_t P10_TOD_UTILS_HW_NS_DELAY     = 50000;
const uint32_t P10_TOD_UTILS_SIM_CYCLE_DELAY = 50000;

// TOD retry count for hardware-cleared bits
const uint32_t P10_TOD_UTIL_TIMEOUT_COUNT = 20;

// TFMR register field definitions
const uint32_t TFMR_MAX_CYC_BET_STEPS      = 0;
const uint32_t TFMR_MAX_CYC_BET_STEPS_LEN  = 8;
const uint32_t TFMR_N_CLKS_PER_STEP        = 8;
const uint32_t TFMR_N_CLKS_PER_STEP_LEN    = 2;
const uint32_t TFMR_MASK_HMI               = 10;
const uint32_t TFMR_SYNC_BIT_SEL           = 11;
const uint32_t TFMR_SYNC_BIT_SEL_LEN       = 3;
const uint32_t TFMR_TB_ECLIPZ              = 14;
const uint32_t TFMR_LOAD_TOD_MOD           = 16;
const uint32_t TFMR_MOVE_CHIP_TOD_TO_TB    = 18;
const uint32_t TFMR_CLEAR_TB_ERRORS        = 24;
const uint32_t TFMR_TFAC_TRANSFER_ERROR    = 25;
const uint32_t TFMR_HDEC_PARITY_ERROR      = 26;
const uint32_t TFMR_TBST_CORRUPT           = 27;
const uint32_t TFMR_TBST_ENCODED           = 28;
const uint32_t TFMR_TBST_ENCODED_LEN       = 4;
const uint32_t TFMR_TBST_LAST              = 32;
const uint32_t TFMR_TBST_LAST_LEN          = 4;
const uint32_t TFMR_TB_ENABLED             = 40;
const uint32_t TFMR_TB_VALID               = 41;
const uint32_t TFMR_TB_SYNC_OCCURRED       = 42;
const uint32_t TFMR_TB_MISSING_SYNC        = 43;
const uint32_t TFMR_TB_MISSING_STEP        = 44;
const uint32_t TFMR_TB_RESIDUE_ERROR       = 45;
const uint32_t TFMR_FW_CONTROL_ERROR       = 46;
const uint32_t TFMR_CHIP_TOD_STATUS        = 47;
const uint32_t TFMR_CHIP_TOD_STATUS_LEN    = 4;
const uint32_t TFMR_CHIP_TOD_INTERRUPT     = 51;
const uint32_t TFMR_CHIP_TOD_PARITY_ERROR  = 56;
const uint32_t TFMR_PURR_PARITY_ERROR_TX   = 57;
const uint32_t TFMR_SPURR_PARITY_ERROR_TX  = 58;
const uint32_t TFMR_DEC_PARITY_ERROR_TX    = 59;
const uint32_t TFMR_CORRUPT_TX             = 60;
const uint32_t TFMR_PURR_OVERFLOW_ERROR_TX = 61;
const uint32_t TFMR_SPURR_OVERFLOW_ERROR_TX = 62;

const uint32_t TFMR_N_CLKS_PER_STEP_4CLK  = 3;

const uint32_t TFMR_SYNC_BIT_SEL_16US = 4;

// PB_[EO]LINK_DLY register field definitions
const uint32_t PB_EOLINK_DLY_FMR_LINK_DELAY_LEN = 12;

// TOD_M_PATH_CTRL_REG register field definitions
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_512  = 0;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_128  = 1;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_64   = 2;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_32   = 3;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_4096 = 4;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_2048 = 5;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_1024 = 6;
const uint32_t TOD_M_PATH_CTRL_REG_M_PATH_SYNC_CREATE_SPS_256  = 7;

// TOD_S_PATH_CTRL_REG register field definitions
// The number of syncs that we are ok with the slave path missing (this must
// be set to at least 1 or there will be a fail)
const uint32_t TOD_S_PATH_CTRL_REG_REMOTE_SYNC_MISS_COUNT_2 = 2;

// TOD_[MSI]_PATH_CTRL_REG register field definitions
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_1 = 0;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_2 = 1;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_4 = 2;
const uint32_t STEP_CHECK_CPS_DEVIATION_FACTOR_8 = 3;

const uint32_t STEP_CHECK_CPS_DEVIATION_00_00_PCENT = 0x0;
const uint32_t STEP_CHECK_CPS_DEVIATION_06_25_PCENT = 0x1;
const uint32_t STEP_CHECK_CPS_DEVIATION_12_50_PCENT = 0x2;
const uint32_t STEP_CHECK_CPS_DEVIATION_18_75_PCENT = 0x3;
const uint32_t STEP_CHECK_CPS_DEVIATION_25_00_PCENT = 0x4;
const uint32_t STEP_CHECK_CPS_DEVIATION_31_25_PCENT = 0x5;
const uint32_t STEP_CHECK_CPS_DEVIATION_37_50_PCENT = 0x6;
const uint32_t STEP_CHECK_CPS_DEVIATION_43_75_PCENT = 0x7;
const uint32_t STEP_CHECK_CPS_DEVIATION_50_00_PCENT = 0x8;
const uint32_t STEP_CHECK_CPS_DEVIATION_56_25_PCENT = 0x9;
const uint32_t STEP_CHECK_CPS_DEVIATION_62_50_PCENT = 0xA;
const uint32_t STEP_CHECK_CPS_DEVIATION_68_75_PCENT = 0xB;
const uint32_t STEP_CHECK_CPS_DEVIATION_75_00_PCENT = 0xC;
const uint32_t STEP_CHECK_CPS_DEVIATION_81_25_PCENT = 0xD;
const uint32_t STEP_CHECK_CPS_DEVIATION_87_50_PCENT = 0xE;
const uint32_t STEP_CHECK_CPS_DEVIATION_93_75_PCENT = 0xF;

const uint32_t STEP_CHECK_VALIDITY_COUNT_1   = 0;
const uint32_t STEP_CHECK_VALIDITY_COUNT_2   = 1;
const uint32_t STEP_CHECK_VALIDITY_COUNT_4   = 2;
const uint32_t STEP_CHECK_VALIDITY_COUNT_8   = 3;
const uint32_t STEP_CHECK_VALIDITY_COUNT_16  = 4;
const uint32_t STEP_CHECK_VALIDITY_COUNT_32  = 5;
const uint32_t STEP_CHECK_VALIDITY_COUNT_64  = 6;
const uint32_t STEP_CHECK_VALIDITY_COUNT_128 = 7;

// TOD_CHIP_CTRL register field definitions
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_8   = 0;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_4   = 1;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_2   = 2;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_1   = 3;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_128 = 4;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_64  = 5;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_32  = 6;
const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SEL_16  = 7;

const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_1  = 0x1;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_2  = 0x2;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3  = 0x3;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_4  = 0x4;
const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VAL_3F = 0x3F;

// TOD_LOAD_REG register field definitions.
// See Table 1.4.1: TOD counter load value for different SYNC boundary in TOD Specification
// for an explanation of this value bits[50:59]
const uint64_t P10_TOD_LOAD_REG_LOAD_VALUE_SYNC  = 0x00000000000003FFULL;
// TOD starting value bits[0:49] in Table 1.4.1 from TOD specification
// This is the starting TOD value for all TOD nodes.
// Approximately 35 minutes @ 32Mhz TOD clocks.
// This is the amount of time allotted between the TTYPE_5, when the TOD Slave Value
// counters start incrementing, and the START_TOD when the TOD Master FSM is put into
// the Running State, and the TOD Master transmits its TOD Value over to the Slaves.
const uint64_t P10_TOD_LOAD_REG_LOAD_VALUE_START = 0x0000001000000000ULL;
const uint64_t P10_TOD_LOAD_REG_LOAD_VALUE = (P10_TOD_LOAD_REG_LOAD_VALUE_START | P10_TOD_LOAD_REG_LOAD_VALUE_SYNC);

// Bit which causes TOD FSM to transition out of the Not Set state to the Stopped state
const uint64_t P10_TOD_LOAD_REG_START_TOD     = 0x0000000000000001ULL;

// TOD_[RX,TX]_TTYPE_CTRL_REG register field definitions
const uint64_t TOD_TTYPE_CTRL_REG_TTYPE0 = 0x8000000000000080ULL;
const uint64_t TOD_TTYPE_CTRL_REG_TTYPE1 = 0x4000000000000080ULL;
const uint64_t TOD_TTYPE_CTRL_REG_TTYPE2 = 0x2000000000000080ULL;
const uint64_t TOD_TTYPE_CTRL_REG_TTYPE3 = 0x1000000000000080ULL;
const uint64_t TOD_TTYPE_CTRL_REG_TTYPE4 = 0x0000000000000001ULL;
const uint64_t TOD_TTYPE_CTRL_REG_TTYPE5 = 0x0400000000000080ULL;

// TOD_TX_TTYPE_[0-5]_REG register field definitions
const uint64_t TOD_TX_TTYPE_REG_TX_TTYPE_TRIGGER = 0x8000000000000000ULL;

// TOD_LOAD_TOD_REG register field definitions
const uint64_t TOD_LOAD_TOD_REG_GOTO_STOPPED_STATE = 0x0000000000000001ULL;

// TOD_[PRI, SEC]_PORT_[0,1]_CTRL_REG register field definitions
const uint32_t TOD_PORT_CTRL_REG_TX_X0_SEL    = 4;
const uint32_t TOD_PORT_CTRL_REG_TX_X0_EN     = 20;
const uint32_t TOD_PORT_CTRL_REG_I_PATH_DELAY = 30;

const uint32_t TOD_PORT_CTRL_REG_TX_LEN = 2;
const uint32_t TOD_PORT_CTRL_REG_I_PATH_DELAY_LEN = 10;

const uint32_t TOD_PORT_CTRL_REG_S_PATH_0 = 0x0;
const uint32_t TOD_PORT_CTRL_REG_S_PATH_1 = 0x1;
const uint32_t TOD_PORT_CTRL_REG_M_PATH_0 = 0x2;
const uint32_t TOD_PORT_CTRL_REG_M_PATH_1 = 0x3;

const uint32_t NUM_THREADS_PER_CORE = 4;

// Fabric DL TOD Config Register Enums
const uint8_t DLP_INBOUND_TOD_SELECT_NONE  = 0x00;
const uint8_t DLP_INBOUND_TOD_SELECT_LINK0 = 0x01;
const uint8_t DLP_INBOUND_TOD_SELECT_LINK1 = 0x02;
const uint8_t DLP_INBOUND_TOD_SELECT_OTHER = 0x03;

//------------------------------------------------------------------------------
// Type definitions
//------------------------------------------------------------------------------
typedef uint64_t iohs_latency_t;
typedef uint64_t tod_latency_t;

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
extern "C" {

    enum p10_tod_setup_tod_sel
    {
        TOD_PRIMARY,  // configure primary TOD
        TOD_SECONDARY // configure secondary TOD
    };

    enum p10_tod_setup_bus
    {
        TOD_SETUP_BUS_NONE, // for MDMT
        TOD_SETUP_BUS_IOHS0,
        TOD_SETUP_BUS_IOHS1,
        TOD_SETUP_BUS_IOHS2,
        TOD_SETUP_BUS_IOHS3,
        TOD_SETUP_BUS_IOHS4,
        TOD_SETUP_BUS_IOHS5,
        TOD_SETUP_BUS_IOHS6,
        TOD_SETUP_BUS_IOHS7,
        TOD_SETUP_BUS_BUS_MAX = TOD_SETUP_BUS_IOHS7 // for HWSV code dependencies
    };

    enum tod_action
    {
        TOD_SETUP,
        TOD_INIT,
        TOD_STATUS,
        TOD_CLEANUP,
        TOD_MOVE_TOD_TO_TB,
        TOD_SAVE_CONFIG
    };

    // Input which determines the master oscillator to use
    enum p10_tod_setup_osc_sel
    {
        TOD_OSC_0,             // oscillator connected to OSC0 and not OSC1
        TOD_OSC_1,             // oscillator connected to OSC1 and not OSC0
        TOD_OSC_0_AND_1,       // oscillators connected to both OSC0 and OSC1
        TOD_OSC_0_AND_1_SEL_0, // oscillators connected to both OSC0 and OSC1, but OSC0 will always be selected
        TOD_OSC_0_AND_1_SEL_1, // oscillators connected to both OSC0 and OSC1, but OSC1 will always be selected
        TOD_OSC_NONE           // no oscillators connected
    };

    // enum that gives which oscilators we need to disable,
    // used in p10_tod_cleanup
    enum p10_tod_osc_disable
    {
        TOD_OSC_0_DISABLE,
        TOD_OSC_1_DISABLE,
        TOD_OSC_0_AND_1_DISABLE,
        TOD_OSC_DISABLE_NONE
    };

    // TFMR states, see PC workbook
    enum p10_tod_tfmr_state
    {
        TFMR_STATE_TB_RESET = 0,
        TFMR_STATE_TB_SEND_TOD_MOD = 1,
        TFMR_STATE_TB_NOT_SET = 2,
        TFMR_STATE_TB_SYNC_WAIT = 6,
        TFMR_STATE_TB_GET_TOD = 7,
        TFMR_STATE_TB_RUNNING = 8,
        TFMR_STATE_TB_ERROR = 9
    };

    // TOD FSM states inside register TOD_FSM_REG
    enum p10_tod_fsm_state
    {
        TOD_FSM_STATE_ERROR = 0,
        TOD_FSM_STATE_STOPPED = 1,
        TOD_FSM_STATE_RUNNING = 2,
        TOD_FSM_STATE_NOT_SET = 7,
        TOD_FSM_STATE_RUNNING_STEP = 10,
        TOD_FSM_STATE_NOT_SET_STEP = 11,
        TOD_FSM_STATE_WAIT_SYNC = 13,
        TOD_FSM_STATE_RUNNING_SYNC = 14
    };

    struct p10_tod_setup_conf_regs
    {
        fapi2::buffer<uint64_t> tod_m_path_ctrl_reg;
        fapi2::buffer<uint64_t> tod_pri_port_0_ctrl_reg;
        fapi2::buffer<uint64_t> tod_pri_port_1_ctrl_reg;
        fapi2::buffer<uint64_t> tod_sec_port_0_ctrl_reg;
        fapi2::buffer<uint64_t> tod_sec_port_1_ctrl_reg;
        fapi2::buffer<uint64_t> tod_s_path_ctrl_reg;
        fapi2::buffer<uint64_t> tod_i_path_ctrl_reg;
        fapi2::buffer<uint64_t> tod_pss_mss_ctrl_reg;
        fapi2::buffer<uint64_t> tod_chip_ctrl_reg;
    };

    struct tod_topology_node
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_target;
        bool i_tod_master;
        bool i_drawer_master;
        p10_tod_setup_bus i_bus_rx; // Current node's bus from which step/sync is
        //   received ("Receive Port" in eiinfo)
        p10_tod_setup_bus i_bus_tx; // Upstream node's bus from which step/sync
        //   is transmitted ("Drive Port" in eiinfo)
        std::list<tod_topology_node*> i_children;  // Children of current node
        tod_topology_node* i_parent;              // Parent of current node (or Upstream node),
        // TOD SYNCs are received from parent.  This is initialized by the p10_tod_setup HWP.
        p10_tod_setup_conf_regs o_todRegs;
        tod_latency_t o_int_path_delay;
    };

} //extern "C"

#endif //_P10_TOD_UTILS_H_
