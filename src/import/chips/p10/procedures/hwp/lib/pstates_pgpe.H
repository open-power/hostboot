/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/pstates_pgpe.H $      */
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
/// @file  pstates_pgpe.H
/// @brief Pstate structures and support routines for PGPE Hcode
///
// *HWP HW Owner        : Rahul Batra <rbatra@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE:HS

#ifndef __PSTATES_PGPE_H__
#define __PSTATES_PGPE_H__

#include <pstates_common.H>


/// PstateParmsBlock Magic Number
///
/// This magic number identifies a particular version of the
/// PstateParmsBlock and its substructures.  The version number should be
/// kept up to date as changes are made to the layout or contents of the
/// structure.

#define PSTATE_PARMSBLOCK_MAGIC 0x5053544154453030ull /* PSTATE00 */
#define PSTATE_PARMSBLOCK_MAGIC_V1 0x5053544154453031ull /* PSTATE01 */

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define SAFE_VOLTAGE_SIZE   2
#define SAFE_VOLTAGE_VDD    0
#define SAFE_VOLTAGE_VCS    1

enum POUNDW_DDS_FIELDS
{
    TRIP_OFFSET             = 0,
    DATA0_OFFSET            = 1,
    DATA1_OFFSET            = 2,
    DATA2_OFFSET            = 3,
    LARGE_DROOP_DETECT      = 4,
    SMALL_DROOP_DETECT      = 5,
    SLOPEA_START_DETECT     = 6,
    SLOPEA_END_DETECT       = 7,
    SLOPEB_START_DETECT     = 8,
    SLOPEB_END_DETECT       = 9,
    SLOPEA_CYCLES           = 10,
    SLOPEB_CYCLES           = 11,
    NUM_POUNDW_DDS_FIELDS   = 12
};

#define POUNDW_DDS_FIELDS_STR   \
    {                               \
        "TRIP_OFFSET",               \
        "DATA0_OFFSET",              \
        "DATA1_OFFSET",              \
        "DATA2_OFFSET",              \
        "LARGE_DROOP_DETECT",        \
        "SMALL_DROOP_DETECT",        \
        "SLOPEA_START_DETECT",       \
        "SLOPEA_END_DETECT",         \
        "SLOPEB_START_DETECT",       \
        "SLOPEB_END_DETECT",         \
        "SLOPEA_CYCLES",             \
        "SLOPEB_CYCLES"              \
    }

enum DDS_TRIP_MODE
{
    DDS_TRIP_MODE_CHIP      = 0x0,
    DDS_TRIP_MODE_CORE      = 0x1,
};

enum DDS_TRIP_INTP_CTRL
{
    DDS_TRIP_INTP_CTRL_TRIP_OFFSET = 0x80,
    DDS_TRIP_INTP_CTRL_DATA0       = 0x40,
    DDS_TRIP_INTP_CTRL_DATA1       = 0x20,
    DDS_TRIP_INTP_CTRL_DATA2       = 0x10,
    DDS_TRIP_INTP_CTRL_LARGE       = 0x08,
    DDS_TRIP_INTP_CTRL_SMALL       = 0x04,
    DDS_TRIP_INTP_CTRL_SLOPEA      = 0x02,
    DDS_TRIP_INTP_CTRL_SLOPEB      = 0x01
};
/// These define the Run-time rails that are controlled by the PGPE during
/// Pstate operations.
#define RUNTIME_RAILS       2
#define RUNTIME_RAIL_VDD    0
#define RUNTIME_RAIL_VCS    1
#define RUNTIME_RAIL_IDD    0
#define RUNTIME_RAIL_ICS    1
#define RUNTIME_RAIL_STR { "VDD", "VCS"}


/// These defines resonant clock data structures constants
#define RESCLK_FREQ_REGIONS 4
#define RESCLK_STEPS        32

/// These define PGPE Flags
#define MAX_PGPE_FLAGS      32 //Note: not all are used, but kept for future use
enum PGPE_FLAGS_IDX
{
    PGPE_FLAG_RESCLK_ENABLE                 = 0,
    PGPE_FLAG_CURRENT_READ_DISABLE          = 1,
    PGPE_FLAG_OCS_DISABLE                   = 2,
    PGPE_FLAG_WOF_ENABLE                    = 3,
    PGPE_FLAG_WOV_UNDERVOLT_ENABLE          = 4,
    PGPE_FLAG_WOV_OVERVOLT_ENABLE           = 5,
    PGPE_FLAG_DDS_COARSE_THROTTLE_ENABLE    = 6,
    PGPE_FLAG_DDS_SLEW_MODE                 = 7,
    PGPE_FLAG_FREQ_JUMP_ENABLE              = 8,
    PGPE_FLAG_PMCR_MOST_RECENT_ENABLE       = 9,
    PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE        = 10,
    PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE        = 11,
    PGPE_FLAG_PHANTOM_HALT_ENABLE           = 12,
    PGPE_FLAG_RVRM_ENABLE                   = 13,
    PGPE_FLAG_DDS_ENABLE                    = 14,
    PGPE_FLAG_TRIP_MODE                     = 15,
    PGPE_FLAG_TRIP_INTERPOLATION_CONTROL    = 16,
    PGPE_FLAG_STATIC_VOLTAGE_ENABLE         = 17,
    PGPE_FLAG_MAX_DEFINED                   = 18
};

/// Control Attributes
typedef union
{
    uint8_t value[128];
    union
    {
        uint8_t pstates_enabled;
        uint8_t resclk_enabled;
        uint8_t wof_enabled;
        uint8_t dds_enabled;
        uint8_t ocs_enabled;
        uint8_t underv_enabled;
        uint8_t overv_enabled;
        uint8_t throttle_control_enabled;
        uint8_t rvrm_enabled;
    } fields;
} Attributes_t;

///
///Resonant Clock Frequency Index
///
typedef struct
{
    uint16_t freq;
    uint8_t idx;
} ResClkFreqIdx_t;

///
/// Resonant Clock Stepping Entry
///
typedef union
{
    uint8_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t    sector_buffer   : 4;
        uint16_t    resonant_switch : 4;
#else
        uint16_t    resonant_switch : 4;
        uint16_t    sector_buffer   : 4;
#endif // _BIG_ENDIAN
    } fields;
} ResClkStepEntry_t;

///
/// Resonant Clock Setup
///
typedef struct
{
    uint8_t             ps[RESCLK_FREQ_REGIONS];
    uint8_t             index[RESCLK_FREQ_REGIONS];
    ResClkStepEntry_t   steparray[RESCLK_STEPS];

} ResClkSetup_t;

/// #W Entry Data Points as per V75
typedef struct __attribute__((__packed__))
{
    union
    {
        uint64_t value;
        struct
        {

#ifdef _BIG_ENDIAN
            uint64_t delay_per_bin : 6;
            uint64_t calb_adj      : 2;
            uint64_t insrtn_dely   : 8;
            uint64_t spare1        : 1;
            uint64_t trip_offset   : 3;
            uint64_t data0_select  : 4;
            uint64_t data1_select  : 4;
            uint64_t data2_select  : 4;
            uint64_t large_droop   : 4;
            uint64_t small_droop   : 4;
            uint64_t slopeA_start  : 4;
            uint64_t slopeA_end    : 4;
            uint64_t slopeB_start  : 4;
            uint64_t slopeB_end    : 4;
            uint64_t slopeA_cycles : 4;
            uint64_t slopeB_cycles : 4;
#else
            uint64_t slopeB_cycles : 4;
            uint64_t slopeA_cycles : 4;
            uint64_t slopeB_end    : 4;
            uint64_t slopeB_start  : 4;
            uint64_t slopeA_end    : 4;
            uint64_t slopeA_start  : 4;
            uint64_t small_droop   : 4;
            uint64_t large_droop   : 4;
            uint64_t data2_select  : 4;
            uint64_t data1_select  : 4;
            uint64_t data0_select  : 4;
            uint64_t trip_offset   : 3;
            uint64_t spare1        : 1;
            uint64_t insrtn_dely   : 8;
            uint64_t calb_adj      : 2;
            uint64_t delay_per_bin : 6;
#endif
        } fields;
    } ddsc;
}
PoundWEntry_t;


typedef struct
{
    union
    {
        uint16_t value;
        struct
        {
#ifdef _BIG_ENDIAN
            uint16_t spare1          : 2;
            uint16_t alt_cal_adj     : 2;
            uint16_t alt_delay       : 8;
            uint16_t spare2          : 1;
            uint16_t alt_trip_offset : 3;
#else
            uint16_t alt_trip_offset : 3;
            uint16_t spare2          : 1;
            uint16_t alt_delay       : 8;
            uint16_t alt_cal_adj     : 2;
            uint16_t spare1          : 2;
#endif
        } fields;
    } alt_cal;
} PoundWEntry_AltCal_t;

typedef struct
{
    union
    {
        uint8_t value;
        struct
        {
#ifdef _BIG_ENDIAN
            uint8_t target_actual_bin: 8;
#else
            uint8_t target_actual_bin: 8;
#endif
        } fields;
    } target_act_bin;
}
PoundWEntry_TgtActBin_t;

typedef struct __attribute__((__packed__))
{
    uint16_t cal_vdd;
    uint16_t alt_cal_vdd;
    uint16_t large_droop_vdd;
    uint16_t worst_droop_min_vdd;
    uint16_t worst_droop_max_vdd;
    uint16_t non_perf_loss_vdd;
}
vdd_calibration;

/// #W DPLL Settings
typedef struct __attribute__((__packed__))
{
    union
    {
        uint16_t value;
        struct
        {
#ifdef _BIG_ENDIAN
            uint16_t N_S_drop_3p125pct   : 4;
            uint16_t N_L_drop_3p125pct   : 4;
            uint16_t L_S_return_3p125pct : 4;
            uint16_t S_N_return_3p125pct : 4;
#else
            uint16_t S_N_return_3p125pct : 4;
            uint16_t L_S_return_3p125pct : 4;
            uint16_t N_L_drop_3p125pct   : 4;
            uint16_t N_S_drop_3p125pct   : 4;
#endif // _BIG_ENDIAN                       /// #W Other Settings
        } fields;
    };
}
PoundWDpllSettings_t;

/// #W Other Settings
typedef struct __attribute__((__packed__))
{
    uint8_t              dds_calibration_version;
    PoundWDpllSettings_t dpll_settings;
    uint16_t             droop_freq_resp_reference_mhz;
    uint64_t             droop_count_control; //DCCR
    uint64_t             ftc_large_droop_mode_reg_setting; //FLMR
    uint64_t             ftc_misc_droop_mode_reg_setting; //FMMR
    uint8_t              calibration_bin;
    uint8_t              spare[10];
}
PoundWOther_t;

/// #W VPD Structure
///
/// Part specific data to manage the Digital Droop Sensor (DDS)
typedef struct __attribute__((__packed__))
{
    PoundWEntry_t           entry[MAXIMUM_CORES][NUM_PV_POINTS];
    PoundWEntry_AltCal_t    entry_alt_cal[MAXIMUM_CORES][NUM_PV_POINTS];
    PoundWEntry_TgtActBin_t entry_tgt_act_bin[MAXIMUM_CORES][NUM_PV_POINTS];
    vdd_calibration         vdd_cal[NUM_PV_POINTS];
    PoundWOther_t           other;
}
PoundW_t;

/// Voltage Regulation Module (VRM) Control Settings
typedef struct
{
    /// Time between ext VRM detects write voltage cmd and when voltage begins to move
    uint32_t transition_start_ns[RUNTIME_RAILS];

    /// Transition rate for an increasing voltage excursion
    uint32_t transition_rate_inc_uv_per_us[RUNTIME_RAILS];

    /// Transition rate for an decreasing voltage excursion
    uint32_t transition_rate_dec_uv_per_us[RUNTIME_RAILS];

    /// Delay to account for rail settling
    uint32_t stabilization_time_us[RUNTIME_RAILS];

    /// External VRM transition step size
    uint32_t step_size_mv[RUNTIME_RAILS];
} VRMParms_t;


/// @todo Need to define the DDS control block

/// Pstate Parameter consumed by PGPE
///
/// The GlobalPstateParameterBlock is an abstraction of a set of voltage/frequency
/// operating points along with hardware limits.
///
typedef struct
{

    union
    {
        uint64_t        value;
        struct
        {
            uint64_t    eye_catcher : 56;
            uint64_t    version     : 8 ;

        } fields;
    } magic;

    Attributes_t        attr;

    uint32_t            reference_frequency_khz;    // Pstate[0] frequency
    uint32_t            frequency_step_khz;
    uint32_t            occ_complex_frequency_mhz;  // Needed for FITs
    uint32_t            dpll_pstate0_value;  // @todo why this and reference_frequency_khz?

    /// VPD operating points are biased but without load-line correction.
    /// Frequencies are in MHz, voltages are specified in units of 1mV, currents
    /// are specified in units of 10mA, and temperatures are specified in 0.5
    /// degrees C.
    PoundVOpPoint_t     operating_points_set[NUM_VPD_PTS_SET][NUM_PV_POINTS];
    uint32_t            spare0[16];             // 128B word-aligned

    PoundVBias_t        poundv_biases_0p05pct;  // Values in 0.5%

    SysPowerDistParms_t vdd_sysparm;
    SysPowerDistParms_t vcs_sysparm;
    SysPowerDistParms_t vdn_sysparm;
    VRMParms_t          ext_vrm_parms;

    uint32_t            safe_voltage_mv[SAFE_VOLTAGE_SIZE];
    uint32_t            safe_frequency_khz;
    uint32_t            safe_throttle_idx;

    /// #W Entry(DDS)
    PoundWEntry_t       dds[MAXIMUM_CORES][NUM_PV_POINTS];

    /// The following are needed to generated the Pstate Table to HOMER.
    ResClkSetup_t       resclk;

    /// Precalculated VPD Slopes
    /// All are in 4.12 decimal form into uint16_t integer value
    uint16_t            ps_voltage_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            voltage_ps_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ps_ac_current_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ps_dc_current_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ac_current_ps_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            dc_current_ps_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ps_ac_current_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ps_dc_current_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ac_current_ps_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            dc_current_ps_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ps_dds_delay_slopes[NUM_VPD_PTS_SET][MAXIMUM_CORES][VPD_NUM_SLOPES_REGION];
    uint8_t             ps_dds_slopes[NUM_POUNDW_DDS_FIELDS][NUM_VPD_PTS_SET][MAXIMUM_CORES][VPD_NUM_SLOPES_REGION];

    //AvsBusTopology
    AvsBusTopology_t avs_bus_topology;

    uint32_t core_on_ratio_vdd;
    uint32_t l3_on_ratio_vdd;
    uint32_t mma_on_ratio_vdd;
    uint32_t core_on_ratio_vcs;
    uint32_t l3_on_ratio_vcs;
    uint32_t vdd_vratio_weight;
    uint32_t vcs_vratio_weight;
    uint16_t array_write_vdn_mv;
    uint16_t array_write_vdd_mv;

    //PGPE Flags
    //Note: not all are used, but reserved for future use
    uint8_t pgpe_flags[MAX_PGPE_FLAGS];

    //Maximum performance loss threshold when undervolting(in 0.1%, tenths of percent)
    uint8_t wov_underv_perf_loss_thresh_pct;

    //WOV undervolting increment percentage(in 0.1%, tenths of percent)
    uint8_t wov_underv_step_incr_pct;

    //WOV undervolting decrement percentage(in 0.1%, tenths of percent)
    uint8_t wov_underv_step_decr_pct;

    //WOV undervolting max percentage(in 0.1%, tenths of percent)
    uint8_t wov_underv_max_pct;

    //When undervolting, if this value is non-zero, then voltage will never be set
    //below this value. If it is zero, then the minimum voltage is only bounded by
    //wov_underv_max_pct.
    uint16_t wov_underv_vmin_mv;

    //When overvolting, then voltage will never be set above this value
    uint16_t wov_overv_vmax_mv;

    //WOV overvolting increment percentage(in 0.1%, tenths of percent)
    uint8_t wov_overv_step_incr_pct;

    //WOV overvolting decrement percentage(in 0.1%, tenths of percent)
    uint8_t wov_overv_step_decr_pct;

    //WOV overvolting max percentage(in 0.1%, tenths of percent)
    uint8_t wov_overv_max_pct;

    //Voltage at which the Retention VRM enters bypass due it's regulation deadzone
    uint8_t rvrm_deadzone_mv;

    //Determine how often to call the wov algorithm with respect
    //to PGPE FIT ticks
    uint32_t wov_sample_125us;

    //Maximum performance loss(in 0.1%, tenths of percent). We should never be at
    //this level, but we check using this value inside PGPE to make sure that this
    //is reported if it ever happens
    uint32_t wov_max_droop_pct;

    //Offset added to VDD to come up the corresponding VCS voltage. Note, VCS value
    //is bounded by the vcs_floor value below
    uint16_t vcs_vdd_offset_mv;

    //The minimum value of VCS
    uint16_t vcs_floor_mv;

    // Ceiling Frequency - Maximum operable frequency for a system that
    // has limitations that are independent from Pstates.
    // If 0, reference_frequency_khz is the maximum frequency;
    // If non-zero, this frequency should be translated to the Pstate space
    //    so as to be the lowest Pstate (which is the highest frequency)
    //    to which the system is clipped.
    uint32_t frequency_ceiling_khz;

    /// #W Alternate Calibration Data
    PoundWEntry_AltCal_t    dds_alt_cal[MAXIMUM_CORES][NUM_PV_POINTS];

    /// #W Target Active Bin Data
    PoundWEntry_TgtActBin_t dds_tgt_act_bin[MAXIMUM_CORES][NUM_PV_POINTS];

    /// #W Other (DDS Data)
    PoundWOther_t           dds_other;

    /// #W VDD Calibration(DDS Data)
    vdd_calibration         vdd_cal[NUM_PV_POINTS];

// __attribute__((packed, aligned(1024))) GlobalPstateParmBlock_t;
} GlobalPstateParmBlock_t;

//Operating Points, Slopes, and Biases
typedef struct
{
    /// Precalculated VPD Slopes
    /// All are in 4.12 decimal form into uint16_t integer value
    uint16_t    ps_voltage_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    voltage_ps_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    ps_ac_current_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    ps_dc_current_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    ac_current_ps_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    dc_current_ps_tdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    ps_ac_current_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    ps_dc_current_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    ac_current_ps_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t    dc_current_ps_rdp[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
} PoundVSlopes_t;

typedef struct
{
    uint16_t    ps_dds_delay_slopes[NUM_VPD_PTS_SET][MAXIMUM_CORES][VPD_NUM_SLOPES_REGION];
    uint8_t     ps_dds_slopes[NUM_POUNDW_DDS_FIELDS][NUM_VPD_PTS_SET][MAXIMUM_CORES][VPD_NUM_SLOPES_REGION];
} PoundWSlopes_t;

typedef struct
{
    uint32_t            reference_frequency_khz;    // Pstate[0] frequency
    uint32_t            frequency_step_khz;
    uint32_t            occ_complex_frequency_mhz;  // Needed for FITs
    uint32_t            dpll_pstate0_value;  // @todo why this and reference_frequency_khz?

    //Safe voltage and frequency
    uint32_t            safe_voltage_mv[SAFE_VOLTAGE_SIZE];
    uint32_t            safe_frequency_khz;
    uint32_t            safe_throttle_idx;

    // Ceiling Frequency - Maximum operable frequency for a system that
    // has limitations that are independent from Pstates.
    // If 0, reference_frequency_khz is the maximum frequency;
    // If non-zero, this frequency should be translated to the Pstate space
    //    so as to be the lowest Pstate (which is the highest frequency)
    //    to which the system is clipped.
    uint32_t frequency_ceiling_khz;


    //Offset added to VDD to come up the corresponding VCS voltage. Note, VCS value
    //is bounded by the vcs_floor value below
    uint16_t vcs_vdd_offset_mv;

    //The minimum value of VCS
    uint16_t vcs_floor_mv;

    uint16_t array_write_vdn_mv;
    uint16_t array_write_vdd_mv;

    uint8_t rvrm_deadzone_mv;

    uint8_t reserved[87];
} GlobalPstateParmBlockBase_t;

//WOF
typedef struct
{
    uint32_t core_on_ratio_vdd;
    uint32_t l3_on_ratio_vdd;
    uint32_t mma_on_ratio_vdd;
    uint32_t core_on_ratio_vcs;
    uint32_t l3_on_ratio_vcs;
    uint32_t vdd_vratio_weight;
    uint32_t vcs_vratio_weight;
} GlobalPstateParmBlockWOF_t;

typedef struct
{
    //Maximum performance loss threshold when undervolting(in 0.1%, tenths of percent)
    uint8_t wov_underv_perf_loss_thresh_pct;

    //WOV undervolting increment percentage(in 0.1%, tenths of percent)
    uint8_t wov_underv_step_incr_pct;

    //WOV undervolting decrement percentage(in 0.1%, tenths of percent)
    uint8_t wov_underv_step_decr_pct;

    //WOV undervolting max percentage(in 0.1%, tenths of percent)
    uint8_t wov_underv_max_pct;

    //When undervolting, if this value is non-zero, then voltage will never be set
    //below this value. If it is zero, then the minimum voltage is only bounded by
    //wov_underv_max_pct.
    uint16_t wov_underv_vmin_mv;

    //When overvolting, then voltage will never be set above this value
    uint16_t wov_overv_vmax_mv;

    //Determine how often to call the wov algorithm with respect
    //to PGPE FIT ticks
    uint32_t wov_sample_125us;

    //Maximum performance loss(in 0.1%, tenths of percent). We should never be at
    //this level, but we check using this value inside PGPE to make sure that this
    //is reported if it ever happens
    uint32_t wov_max_droop_pct;

    //WOV overvolting increment percentage(in 0.1%, tenths of percent)
    uint8_t wov_overv_step_incr_pct;

    //WOV overvolting decrement percentage(in 0.1%, tenths of percent)
    uint8_t wov_overv_step_decr_pct;

    //WOV overvolting max percentage(in 0.1%, tenths of percent)
    uint8_t wov_overv_max_pct;

    uint8_t pad;
} GlobalPstateParmBlockWOV_t;

enum GPPB_OFFSET_IDX
{
    PGPE_FLAGS_OFFSET_IDX       = 0,
    BASE_OFFSET_IDX             = 1,
    AVSBUS_OFFSET_IDX           = 2,
    SYSPARMS_VDD_OFFSET_IDX     = 3,
    SYSPARMS_VCS_OFFSET_IDX     = 4,
    SYSPARMS_VDN_OFFSET_IDX     = 5,
    VRM_PARMS_OFFSET_IDX        = 6,
    VPD_OP_OFFSET_IDX           = 7,
    POUNDV_BIAS_OFFSET_IDX      = 8,
    POUNDV_SLOPES_OFFSET_IDX    = 9,
    POUNDW_SLOPES_OFFSET_IDX    = 10,
    RESCLK_OFFSET_IDX           = 11,
    DDS_OFFSET_IDX              = 12,
    DDS_ALT_CAL_OFFSET_IDX      = 13,
    DDS_TGT_ACT_BIN_OFFSET_IDX  = 14,
    DDS_OTHER_OFFSET_IDX        = 15,
    DDS_VDD_CAL_OFFSET_IDX      = 16,
    WOF_OFFSET_IDX              = 17,
    WOV_OFFSET_IDX              = 18,
    MAX_GPPB_OFFSET_IDX         = 32,
};

/// Pstate Parameter consumed by PGPE
///
/// The GlobalPstateParameterBlock is an abstraction of a set of voltage/frequency
/// operating points along with hardware limits.
///
typedef struct
{

    union
    {
        uint64_t        value;
        struct
        {
            uint64_t    eye_catcher : 56;
            uint64_t    version     : 8 ;

        } fields;
    } magic;

    uint16_t offsets[MAX_GPPB_OFFSET_IDX];

    //PGPE Flags
    //Note: not all are used, but reserved for future use
    uint8_t pgpe_flags[MAX_PGPE_FLAGS];

    //Base GPPB variables
    GlobalPstateParmBlockBase_t base;

    //System Params- VDN, VCS, VDD and VRM
    AvsBusTopology_t avs_bus_topology;
    SysPowerDistParms_t vdd_sysparm;
    SysPowerDistParms_t vcs_sysparm;
    SysPowerDistParms_t vdn_sysparm;
    VRMParms_t          ext_vrm_parms;

    //Operating points, Slopes and Biases
    /// VPD operating points are biased but without load-line correction.
    // Frequencies are in MHz, voltages are specified in units of 1mV, currents
    /// are specified in units of 10mA, and temperatures are specified in 0.5
    /// degrees C.
    PoundVOpPoint_t     operating_points_set[NUM_VPD_PTS_SET][NUM_PV_POINTS];

    PoundVBias_t        poundv_biases_0p05pct;  // Values in 0.5%

    PoundVSlopes_t      poundv_slopes;

    //Resclk
    /// The following are needed to generated the Pstate Table to HOMER.
    ResClkSetup_t   resclk;

    //DDS
    /// #W Entry(DDS)
    PoundWEntry_t       dds[MAXIMUM_CORES][NUM_PV_POINTS];

    /// #W Alternate Calibration Data
    PoundWEntry_AltCal_t    dds_alt_cal[MAXIMUM_CORES][NUM_PV_POINTS];

    /// #W Target Active Bin Data
    PoundWEntry_TgtActBin_t dds_tgt_act_bin[MAXIMUM_CORES][NUM_PV_POINTS];

    /// #W Other (DDS Data)
    PoundWOther_t   dds_other;

    /// #W VDD Calibration(DDS Data)
    vdd_calibration         vdd_cal[NUM_PV_POINTS];

    // #W Pre-calculated slopes
    PoundWSlopes_t poundw_slopes;

    //WOF
    GlobalPstateParmBlockWOF_t wof;

    //WOV
    GlobalPstateParmBlockWOV_t wov;

// __attribute__((packed, aligned(1024))) GlobalPstateParmBlock_t;
} GlobalPstateParmBlock_v1_t;


#ifdef __cplusplus
} // end extern C
#endif
#endif    /* __ASSEMBLER__ */
#endif    /* __PSTATES_PGPE_H__ */
