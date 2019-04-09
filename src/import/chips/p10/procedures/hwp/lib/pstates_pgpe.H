/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/pstates_pgpe.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
// #include <pstates_qme.h>

/// PstateParmsBlock Magic Number
///
/// This magic number identifies a particular version of the
/// PstateParmsBlock and its substructures.  The version number should be
/// kept up to date as changes are made to the layout or contents of the
/// structure.

#define PSTATE_PARMSBLOCK_MAGIC 0x5053544154453030ull /* PSTATE00 */

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

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
    } fields;
} Attributes_t;

/// Resonant Clock Stepping Entry
///
/// @todo needs refinement for P10 yet.
typedef union
{
    uint16_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t    sector_buffer   : 4;
        uint16_t    spare1          : 1;
        uint16_t    pulse_enable    : 1;
        uint16_t    pulse_mode      : 2;
        uint16_t    resonant_switch : 4;
        uint16_t    spare4          : 4;
#else
        uint16_t    spare4          : 4;
        uint16_t    resonant_switch : 4;
        uint16_t    pulse_mode      : 2;
        uint16_t    pulse_enable    : 1;
        uint16_t    spare1          : 1;
        uint16_t    sector_buffer   : 4;
#endif // _BIG_ENDIAN
    } fields;
} ResClkStepEntry_t;

/// @todo needs refinement for P10 yet.
#define RESCLK_FREQ_REGIONS 8
#define RESCLK_STEPS        64
#define RESCLK_L3_STEPS     4

/// Resonant Clock Setup
typedef struct
{
    uint8_t             freq_mhz[RESCLK_FREQ_REGIONS];
    uint8_t             index[RESCLK_FREQ_REGIONS];
    ResClkStepEntry_t   steparray[RESCLK_STEPS];
    uint16_t            step_delay_ns;                   // Max delay: 65.536us
    uint8_t             l3_steparray[RESCLK_L3_STEPS];
    uint16_t            l3_threshold_mv;

} ResClkSetup_t;

/// #W Entry Data Points
typedef struct
{
    union
    {
        uint64_t value;
        struct
        {

#ifdef _BIG_ENDIAN
            uint64_t insrtn_dely   : 8;
            uint64_t spare1        : 2;
            uint64_t calb_adj      : 2;
            uint64_t spare2        : 1;
            uint64_t window_offset : 3;
            uint64_t mux_select    : 36;
            uint64_t dlt_time_set  : 8;
            uint64_t spare3        : 4;
#else
            uint64_t spare3        : 4;
            uint64_t dlt_time_set  : 8;
            uint64_t mux_select    : 36;
            uint64_t window_offset : 3;
            uint64_t spare2        : 1;
            uint64_t calb_adj      : 2;
            uint64_t spare1        : 2;
            uint64_t insrtn_dely   : 8;
#endif
        } fields;
    } digital_droop_sensor_config;
} PoundWEntry_t;

/// #W DPLL Settings
typedef struct
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
} PoundWDpllSettings_t;

/// #W Other Settings
typedef struct
{
    uint8_t              dds_calibration_version;
    PoundWDpllSettings_t dpll_settings;
    uint8_t              light_throttle_settings[10];
    uint8_t              harsh_throttle_settings[10];
    uint16_t             droop_freq_resp_reference;
    uint8_t              large_droop_mode_reg_setting[8];
    uint8_t              misc_droop_mode_reg_setting[8];
    uint8_t              spare[215];
} PoundWOther_t;

/// #W VPD Structure
///
/// Part specific data to manage the Digital Droop Sensor (DDS)
typedef struct
{
    PoundWEntry_t           entry[NUM_OP_POINTS];
    PoundWOther_t           other;
    uint8_t                 rsvd[256];
} PoundW_t;
/// These define the Run-time rails that are controlled by the PGPE during
/// Pstate operations.
#define RUNTIME_RAILS       2
#define RUNTIME_RAIL_VDD    0
#define RUNTIME_RAIL_VCS    1

/// Voltage Regulation Module (VRM) Control Settings
typedef struct
{
    /// The exponent of the exponential encoding of Pstate stepping delay
    uint8_t stepdelay_range;

    /// The significand of the exponential encoding of Pstate stepping delay
    uint8_t stepdelay_value;

    uint8_t spare[2];

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
    uint32_t            nest_frequency_mhz;  // Needed for FITs

    /// VPD operating points are biased but without load-line correction.
    /// Frequencies are in MHz, voltages are specified in units of 1mV, currents
    /// are specified in units of 10mA, and temperatures are specified in 0.5
    /// degrees C.
    PoundVOpPoint_t     operating_points_set[NUM_VPD_PTS_SET][NUM_OP_POINTS];
    uint32_t            spare0[16];             // 128B word-aligned

    PoundVBias_t        poundv_biases_0p05pct[NUM_OP_POINTS];  // Values in 0.5%

    SysPowerDistParms_t vdd_sysparm;
    SysPowerDistParms_t vcs_sysparm;
    SysPowerDistParms_t vdn_sysparm;
    /// #W Other Settings
    VRMParms_t          ext_vrm_parms;

    uint32_t            safe_voltage_mv;
    uint32_t            safe_frequency_khz;

    /// DDS Data
    /// DDSParmBlock dds;
    /// @todo need to define the DDS parm block

    /// The following are needed to generated the Pstate Table to HOMER.
    ResClkSetup_t       resclk;

    /// Precalculated VPD Slopes
    /// All are in 4.12 decimal form into uint16_t integer value
    uint16_t            ps_voltage_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            voltage_ps_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            ps_current_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t            current_ps_slopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];

    //AvsBusTopology
    AvsBusTopology_t avs_bus_topology;

    // Biased Compare VID operating points
    // CompareVIDPoints_t vid_point_set[NUM_OP_POINTS];

    // Biased Threshold operation points
    // uint8_t threshold_set[NUM_OP_POINTS][NUM_THRESHOLD_POINTS];

    // pstate-volt compare slopes
    // int16_t ps_vid_compare_slopes[VPD_NUM_SLOPES_REGION];

    // pstate-volt threshold slopes
    // int16_t ps_dds_thresh_slopes[VPD_NUM_SLOPES_REGION][NUM_THRESHOLD_POINTS];

    // Jump value operating points
    // uint8_t jump_value_set[NUM_OP_POINTS][NUM_JUMP_VALUES];

    // Jump-value slopes
    // int16_t ps_dds_jump_slopes[VPD_NUM_SLOPES_REGION][NUM_JUMP_VALUES];

//} GlobalPstateParmBlock_t __attribute__((packed, aligned(1024)));
} GlobalPstateParmBlock_t;


#ifdef __cplusplus
} // end extern C
#endif
#endif    /* __ASSEMBLER__ */
#endif    /* __PSTATES_PGPE_H__ */
