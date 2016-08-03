/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pstates.h $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file  p9_pstates.h
/// @brief Pstate structures and support routines for OCC product firmware
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP FW Owner        : Martha Broyles <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE, OCC


#ifndef __P9_PSTATES_H__
#define __P9_PSTATES_H__

/// A Pstate type
///
/// Pstates are unsigned but, to avoid bugs, Pstate register fields should
/// always be extracted to a variable of type Pstate.  If the size of Pstate
/// variables ever changes we will have to revisit this convention.
typedef uint8_t Pstate;

/// A DPLL frequency code
///
/// DPLL frequency codes (Fmax and Fmult) are 15 bits
typedef uint16_t DpllCode;

/// An AVS VID code
typedef uint16_t VidAVS;

/// The minimum Pstate (knowing the increasing Pstates numbers represent
/// decreasing frequency)
#define PSTATE_MIN 255

/// The maximum Pstate (knowing the increasing Pstates numbers represent
/// decreasing frequency)
#define PSTATE_MAX 0

/// The minimum \e legal DPLL frequency code
///
/// This is ~1GHz with a 16.6MHz tick frequency.
/// @todo  Check this and the maximum
#define DPLL_MIN 0x03c

/// The maximum DPLL frequency code
#define DPLL_MAX 0x1ff

/// The minimum \a legal (non-power-off) AVS VID code
/// @todo Need to check with J. Kuesmann if there is a limit.  May want this
/// to be an attribute.
#define AVS_MIN 0x0000

/// The maximum \a legal (non-power-off) AVS VID code
/// @todo Need to check with J. Kuesmann if there is a limit.  May want this
/// to be an attribute.
#define AVS_MAX 0xFFFF

////////////////////////////////////////////////////////////////////////////
// Global and Local Pstate Tables
////////////////////////////////////////////////////////////////////////////

/// The Local Pstate table has 32 x 64-bit entries
#define LOCAL_PSTATE_ARRAY_ENTRIES 32

/// The Local Pstate Table alignment in memory. The alignment is
/// specified in the traditional log2 form.
/// The generated table applies to allow Quads in P9.
/// @todo see if there is really any alignment requirement from the OCC team
#define LOCAL_PSTATE_TABLE_ALIGNMENT 10   // 1KB

/// The VDS/VIN table has 32 x 64-bit entries
/// @todo We need to discuss if VDS is precomputed (like in P8) to avoid
/// division during runtime.   Leaving this from P8 for now.
#define VDSVIN_ARRAY_ENTRIES       64

/// The AVS VID base voltage in micro-Volts
#define AVS_BASE_UV 1612500

/// The AVS VID step as an unsigned number (micro-Volts)
#define AVS_STEP_UV 1000

//ssrivath, Is this the same as IVID_BASE_UV and IVID_STEP_UV below
/// The VRM-11 VID base voltage in micro-Volts
#define VRM11_BASE_UV 1612500

/// The VRM-11 VID step as an unsigned number (micro-Volts)
#define VRM11_STEP_UV 6250

// ssrivath, iVID values based on Section 2.8.7 of spec
/// The iVID base voltage in micro-Volts
#define IVID_BASE_UV 512000

/// The iVID step as an unsigned number (micro-Volts)
#define IVID_STEP_UV 4000

/// Maximum number of Quads (4 cores plus associated caches)
#define MAX_QUADS 6

// Constants associated with VRM stepping
// @todo Determine what is needed here (eg Attribute mapping) and if any constants
// are warrented

/// VPD #V Operating Points
#define VPD_PV_POINTS 4
#define VPD_PV_ORDER_STR {"PowerSave", "Nominal    ", "Turbo    ", "UltraTurbo"}
#define POWERSAVE   1
#define NOMINAL     0
#define TURBO       2
#define ULTRA       3
#define POWERBUS    4
#define VPD_PV_ORDER {POWERSAVE, NOMINAL, TURBO, ULTRA}

/// IDDQ readings,
#define IDDQ_MEASUREMENTS 6
#define MEASUREMENT_ELEMENTS  6    // Number of Quads for P9
#define IDDQ_READINGS_PER_IQ 2
#define IDDQ_ARRAY_VOLTAGES {0.60, 0.70, 0.80, 0.90, 1.00, 1.10}

/// WOF Items
#define NUM_ACTIVE_CORES 24
#define MAX_UT_PSTATES   64     // Oversized

//ssrivath, Temporary definition
#define PGP_NCORES 24

/// Error/Panic codes for support routines
/// @todo Review the necessary error codes. This are really PGPE functions now
/// and many below elsewhere.  However, the error code plumbing from PGPE to
/// OCC for error logging purposes is an action.

#define VRM11_INVALID_VOLTAGE 0x00876101

#define PSTATE_OVERFLOW  0x00778a01
#define PSTATE_UNDERFLOW 0x00778a02

#define PSTATE_LT_PSTATE_MIN 0x00778a03
#define PSTATE_GT_PSTATE_MAX 0x00778a04

#define DPLL_OVERFLOW  0x00d75501
#define DPLL_UNDERFLOW 0x00d75502

#define AVSVID_OVERFLOW  0x00843101
#define AVSVID_UNDERFLOW 0x00843102

#define GPST_INVALID_OBJECT      0x00477801
#define GPST_INVALID_ARGUMENT    0x00477802
#define GPST_INVALID_ENTRY       0x00477803
#define GPST_PSTATE_CLIPPED_LOW  0x00477804
#define GPST_PSTATE_CLIPPED_HIGH 0x00477805
#define GPST_BUG                 0x00477806
#define GPST_PSTATE_GT_GPST_PMAX 0x00477807

#define LPST_INVALID_OBJECT      0x00477901
#define LPST_GPST_WARNING        0x00477902
#define LPST_INCR_CLIP_ERROR     0x00477903

/// PstateParmsBlock Magic Number
///
/// This magic number identifies a particular version of the
/// PstateParmsBlock and its substructures.  The version number should be
/// kept up to date as changes are made to the layout or contents of the
/// structure.

#define PSTATE_PARMSBLOCK_MAGIC 0x5053544154453030ull /* PSTATE00 */


/// \defgroup pstate_options Pstate Options
///
/// These are flag bits for the \a options field of the PstateOptions
/// structure.
///
/// @{


/// pgpe_pstate() - Disable Pstate Hcode
#define PSTATE_DISABLE            0x01

/// pgpe_pstate() - Disable IVRM use.
#define PSTATE_IVRMS_DISABLE      0x02

/// pgpe_pstate() - Disable Resonant Clock use.
#define PSTATE_RESCLK_DISABLE     0x04

/// pgpe_pstate() - Disable VDM use.
#define PSTATE_VDM_DISABLE        0x08

/// pgpe_pstate() - Force the system to the minimum Pstate at initialization
///
/// This mode is added as a workaround for the case that the AVSBus interface
/// is not working correctly during initial bringup.  This forces Pstate mode
/// to come up at a low frequency.
#define PSTATE_FORCE_INITIAL_PMIN 0x10

/// @}


/// \defgroup pstate_options Pstate Options
///
/// These are flag bits for the \a options field of the PstateOptions
/// structure.
///
/// @{

/// pgpe_gpst_output() - Bypass producing the Global Pstate table into HOMER
#define PSTATE_NO_GPST            0x01

/// cme_lps_install() - Bylass Local Pstate installation and setup
#define PSTATE_NO_INSTALL_LPSA    0x02

/// cme_resclk_install - Bypass resonant clocking Pstate limit setup
#define PSTATE_NO_INSTALL_RESCLK  0x04

/// pgpe_enable_pstates() - Force the system to the minimum Pstate at
/// initialization
///
/// This mode is added as a workaround for the case that the AVSBus interface
/// is not working correctly during initial bringup.  This forces Pstate mode
/// to come up at a low frequency.
#define PSTATE_FORCE_INITIAL_PMIN 0x10

/// @}

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


/// Standard options controlling Pstate setup and installation procedures

typedef struct
{

    /// Option flags; See \ref pstate_options
    uint32_t options;

    /// Pad structure to 8 bytes.  Could also be used for other options later.
    uint32_t pad;

} PGPEPstateOptions;


/// Standard options controlling Pstate setup and installation procedures

typedef struct
{

    /// Option flags; See \ref pstate_options
    uint32_t options;

    /// Pad structure to 8 bytes.  Could also be used for other options later.
    uint32_t pad;

} QMPstateOptions;

// ssrivath, Moving from pstate param header to this file @TODO - Consolidate with PGPE/QM PState options
typedef struct
{

    /// Option flags; See \ref pstate_options
    uint32_t options;

    /// Pad structure to 8 bytes.  Could also be used for other options later.
    uint32_t pad;

} PstateOptions;


/// Resonant Clock Stepping Entry
///
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

} ResonantClockingStepEntry;

static const uint32_t RESCLK_FREQ_REGIONS = 8;
static const uint32_t RESCLK_STEPS = 64;
static const uint32_t RESCLK_L3_STEPS = 4;

typedef struct ResonantClockControl
{
    uint8_t resclk_freq[RESCLK_FREQ_REGIONS];    // Lower frequency of Resclk Regions

    uint8_t resclk_index[RESCLK_FREQ_REGIONS];   // Index into value array for the
    // respective Resclk Region

    /// Array containing the transition steps
    ResonantClockingStepEntry steparray[RESCLK_STEPS];

    /// Delay between steps (in nanoseconds)
    /// Maximum delay: 65.536us
    uint16_t    step_delay_ns;

    /// L3 Clock Stepping Array
    uint8_t     l3_steparray[RESCLK_L3_STEPS];

    /// Resonant Clock Voltage Threshold (in millivolts)
    /// This value is used to choose the appropriate L3 clock region setting.
    uint16_t l3_threshold_mv;

} ResonantClockingSetup;

// ssrivath, Modified units for vdd/vcs/idd/ics as per P9 VPD spec
/// A VPD operating point
///
/// VPD operating points are stored without load-line correction.  Frequencies
/// are in MHz, voltages are specified in units of 1mV, and characterization
/// currents are specified in units of 100mA.
///
//ssrivath, Is maxreg points part of P9 VPD ?
/// \bug The assumption is that the 'maxreg' points for the iVRM will also be
/// supplied in the VPD in units of 5mv.  If they are supplied in some other
/// form then chip_characterization_create() will need to be modified.

typedef struct
{

    uint32_t vdd_mv;
    uint32_t vcs_mv;
    //uint32_t vdd_maxreg_5mv;
    //uint32_t vcs_maxreg_5mv;
    uint32_t idd_100ma;
    uint32_t ics_100ma;
    uint32_t frequency_mhz;

} VpdOperatingPoint;

/// VPD Biases.
///
/// Percent bias applied to VPD operating points prior to interolation
///
/// All values on in .5 percent (half percent -> hp)
typedef struct
{

    int8_t vdd_ext_hp;
    int8_t vdd_int_hp;
    int8_t vdn_ext_hp;
    int8_t vcs_ext_hp;
    int8_t frequency_hp;

} VpdBias;

/// System Power Distribution Paramenters
///
/// Parameters set by system design that influence the power distribution
/// for a rail to the processor module.  This values are typically set in the
/// system machine readable workbook and are used in the generation of the
/// Global Pstate Table.  This values are carried in the Pstate SuperStructure
/// for use and/or reference by OCC firmware (eg the WOF algorithm)

typedef struct
{

    /// Loadline
    ///   Impedance (binary microOhms) of the load line from a processor VDD VRM
    ///   to the Processor Module pins.
    uint32_t loadline_uohm;

    /// Distribution Loss
    ///   Impedance (binary in microOhms) of the VDD distribution loss sense point
    ///   to the circuit.
    uint32_t distloss_uohm;

    /// Distribution Offset
    ///   Offset voltage (binary in microvolts) to apply to the rail VRM
    ///   distribution to the processor module.
    uint32_t distoffset_uv;

} SysPowerDistParms;



/// IDDQ Reading Type
/// Each entry is 2 bytes. The values are in 6.25mA units; this allow for a
/// maximum value of 409.6A to be represented.
///
typedef uint16_t iddq_entry_t;

/// AvgTemp Reading Type
/// Each entry is 1 byte. The values are in 0.5degC units; this allow for a
/// maximum value of 127degC to be represented.
///
typedef uint16_t avgtemp_entry_t;

/// Iddq Table
///
/// A set of arrays of leakage values (Iddq) collected at various voltage
/// conditions during manufacturing test that will feed into the Workload
/// Optimized Frequency algorithms on the OCC.  These values are not installed
/// in any hardware facilities.
///
typedef struct
{

    /// IDDQ version
    uint8_t     iddq_version;

    /// Good Quads per Sort
    uint8_t     good_quads_per_sort;

    /// Good Normal Cores per Sort
    uint8_t     good_normal_cores_per_sort;

    /// Good Caches per Sort
    uint8_t     good_caches_per_sort;

    /// Good Normal Cores
    uint8_t     good_normal_cores[MAX_QUADS];

    /// Good Caches
    uint8_t     good_caches[MAX_QUADS];

    /// RDP to TDP Scaling Factor in 0.01% units
    uint16_t    rdp_to_tdp_scale_factor;

    /// WOF Iddq Margin (aging factor) in 0.01% units
    uint16_t    wof_iddq_margin_factor;

    /// Temperature Scale Factor per 10C in 0.01% units
    uint16_t    temperature_scale_factor;

    /// Spare
    uint8_t     spare[10];

    /// IVDD ALL Good Cores ON; 6.25mA units
    iddq_entry_t ivdd_all_good_cores_on[IDDQ_MEASUREMENTS];

    /// IVDD ALL Cores OFF; 6.25mA units
    iddq_entry_t ivdd_all_cores_off[IDDQ_MEASUREMENTS];

    /// IVDD ALL Good Cores OFF; 6.25mA units
    iddq_entry_t ivdd_all_good_cores_off[IDDQ_MEASUREMENTS];

    /// IVDD Quad 0 Good Cores ON, Caches ON; 6.25mA units
    iddq_entry_t ivdd_quad_good_cores_on[MAX_QUADS][IDDQ_MEASUREMENTS];

    /// IVDDN ; 6.25mA units
    iddq_entry_t ivdn;


    /// IVDD ALL Good Cores ON, Caches ON; 6.25mA units
    avgtemp_entry_t avgtemp_all_good_cores_on[IDDQ_MEASUREMENTS];

    /// avgtemp ALL Cores OFF, Caches OFF; 6.25mA units
    avgtemp_entry_t avgtemp_all_cores_off_caches_off[IDDQ_MEASUREMENTS];

    /// avgtemp ALL Good Cores OFF, Caches ON; 6.25mA units
    avgtemp_entry_t avgtemp_all_good_cores_off[IDDQ_MEASUREMENTS];

    /// avgtemp Quad 0 Good Cores ON, Caches ON; 6.25mA units
    avgtemp_entry_t avgtemp_quad_good_cores_on[MAX_QUADS][IDDQ_MEASUREMENTS];

    /// avgtempN ; 6.25mA units
    avgtemp_entry_t avgtemp_vdn;

} IddqTable;

//
/// UltraTurbo Segment VIDs by Core Count
typedef struct
{

    /// Number of Segment Pstates
    uint8_t     ut_segment_pstates;

    /// Maximum number of core possibly active
    uint8_t     ut_max_cores;

    /// VDD VID modification
    ///      1 core active  = offset 0
    ///      2 cores active = offset 1
    ///         ...
    ///      12 cores active = offset 11
    uint8_t ut_segment_vdd_vid[MAX_UT_PSTATES][NUM_ACTIVE_CORES];

    /// VCS VID modification
    ///      1 core active  = offset 0
    ///      2 cores active = offset 1
    ///         ...
    ///      12 cores active = offset 11
    uint8_t ut_segment_vcs_vid[MAX_UT_PSTATES][NUM_ACTIVE_CORES];

} VIDModificationTable;

/// Workload Optimized Frequency (WOF) Elements
///
/// Structure defining various control elements needed by the WOF algorithm
/// firmware running on the OCC.
///
typedef struct
{

    /// WOF Enablement
    uint8_t wof_enabled;

    /// TDP<>RDP Current Factor
    ///   Value read from ??? VPD
    ///   Defines the scaling factor that converts current (amperage) value from
    ///   the Thermal Design Point to the Regulator Design Point (RDP) as input
    ///   to the Workload Optimization Frequency (WOF) OCC algorithm.
    ///
    ///   This is a ratio value and has a granularity of 0.01 decimal.  Data
    ///   is held in hexidecimal (eg 1.22 is represented as 122 and then converted
    ///   to hex 0x7A).
    uint32_t tdp_rdp_factor;

    /// UltraTurbo Segment VIDs by Core Count
    VIDModificationTable ut_vid_mod;

    uint8_t pad[4];

} WOFElements;

/// VDM/Droop Parameter Block
///
typedef struct
{
    uint8_t  vid_compare_override_mv_enable;
    uint8_t  vid_compare_override_mv[VPD_PV_POINTS];
    uint8_t  vdm_response;

    // For the following *_enable fields, bits are defined to indicate
    // which of the respective *override* array entries are valid.
    // bit 0: UltraTurbo; bit 1: Turbo; bit 2: Nominal; bit 3: PowSave
    uint8_t  droop_small_override_enable;
    uint8_t  droop_large_override_enable;
    uint8_t  droop_extreme_override_enable;
    uint8_t  overvolt_override_enable;
    uint16_t fmin_override_khz_enable;
    uint16_t fmax_override_khz_enable;

    // The respecitve *_enable above indicate which index values are valid
    uint8_t  droop_small_override[VPD_PV_POINTS];
    uint8_t  droop_large_override[VPD_PV_POINTS];
    uint8_t  droop_extreme_override[VPD_PV_POINTS];
    uint8_t  overvolt_override[VPD_PV_POINTS];
    uint16_t fmin_override_khz[VPD_PV_POINTS];
    uint16_t fmax_override_khz[VPD_PV_POINTS];

    /// Pad structure to 8-byte alignment
    /// @todo pad once fully structure is complete.
    // uint8_t pad[1];

} VDMParmBlock;


/// The layout of the data created by the Pstate table creation firmware for
/// comsumption by the Pstate GPE.  This data will reside in the Quad
/// Power Management Region (QPMR).
///

/// Standard options controlling Pstate setup procedures

/// System Power Distribution Paramenters
///
/// Parameters set by system design that influence the power distribution
/// for a rail to the processor module.  This values are typically set in the
/// system machine readable workbook and are used in the generation of the
/// Global Pstate Table.  This values are carried in the Pstate SuperStructure
/// for use and/or reference by OCC firmware (eg the WOF algorithm)


/// Quad Manager Flags
///

typedef union
{
    uint16_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t    resclk_enable               : 1;
        uint16_t    ivrm_enable                 : 1;
        uint16_t    wof_enable                  : 1;
        uint16_t    dpll_dynamic_fmax_enable    : 1;
        uint16_t    dpll_dynamic_fmin_enable    : 1;
        uint16_t    dpll_droop_protect_enable   : 1;
        uint16_t    reserved                    : 10;
#else
        uint16_t    reserved                    : 10;
        uint16_t    dpll_droop_protect_enable   : 1;
        uint16_t    dpll_dynamic_fmin_enable    : 1;
        uint16_t    dpll_dynamic_fmax_enable    : 1;
        uint16_t    wof_enable                  : 1;
        uint16_t    ivrm_enable                 : 1;
        uint16_t    resclk_enable               : 1;
#endif // _BIG_ENDIAN
    } fields;

} QuadManagerFlags;

/// IVRM Parameter Block
///
/// @todo Major work item.  Largely will seed the CME Quad Manager to perform
/// iVRM voltage calculations

static const uint32_t IVRM_ARRAY_SIZE = 64;
typedef struct iVRMInfo
{

    /// Pwidth from 0.03125 to 1.96875 in 1/32 increments at Vin=Vin_Max
    uint8_t strength_lookup[IVRM_ARRAY_SIZE];   // Each entry is a six bit value, right justified

    /// Scaling factor for the Vin_Adder calculation.
    uint8_t vin_multipler[IVRM_ARRAY_SIZE];     // Each entry is from 0 to 255.

    /// Vin_Max used in Vin_Adder calculation (in millivolts)
    uint16_t    vin_max_mv;

    /// Delay between steps (in nanoseconds)
    /// Maximum delay: 65.536us
    uint16_t    step_delay_ns;

    /// Stabilization delay once target voltage has been reached (in nanoseconds)
    /// Maximum delay: 65.536us
    uint16_t    stablization_delay_ns;

    /// Deadzone (in millivolts)
    /// Maximum: 255mV.  If this value is 0, 50mV is assumed.
    uint8_t    deadzone_mv;

    /// Pad to 8B
    uint8_t    pad;

} IvrmParmBlock;


/// The layout of the data created by the Pstate table creation firmware for
/// comsumption by the CME Quad Manager.  This data will reside in the Core
/// Power Management Region (CPMR).
///
typedef struct
{

    /// Magic Number
    uint64_t magic;     // the last byte of this number the structure's version.

    // QM Flags
    QuadManagerFlags qmflags;

    /// Operating points
    ///
    /// VPD operating points are stored without load-line correction.  Frequencies
    /// are in MHz, voltages are specified in units of 5mV, and currents are
    /// in units of 500mA.
    VpdOperatingPoint operating_points[VPD_PV_POINTS];

    /// Loadlines and Distribution values for the VDD rail
    SysPowerDistParms vdd_sysparm;

    /// External Biases
    ///
    /// Biases applied to the VPD operating points prior to load-line correction
    /// in setting the external voltages.  This is used to recompute the Vin voltage
    /// based on the Global Actual Pstate .
    /// Values in 0.5%
    VpdBias ext_biases[VPD_PV_POINTS];

    /// Internal Biases
    ///
    /// Biases applied to the VPD operating points that are used for interpolation
    /// in setting the internal voltages (eg Vout to the iVRMs) as part of the
    /// Local Actual Pstate.
    /// Values in 0.5%
    VpdBias int_biases[VPD_PV_POINTS];

    /// IVRM Data
    IvrmParmBlock ivrm;

    /// Resonant Clock Grid Management Setup
    ResonantClockingSetup resclk;

    /// VDM Data
    VDMParmBlock vdm;

} LocalPstateParmBlock;

/// Global Pstate Parameter Block
///
/// The GlobalPstateParameterBlock is an abstraction of a set of voltage/frequency
/// operating points along with hardware limits.  Besides the hardware global
/// Pstate table, the abstract table contains enough extra information to make
/// it the self-contained source for setting up and managing voltage and
/// frequency in either Hardware or Firmware Pstate mode.
///
/// When installed in PMC, Global Pstate table indices are adjusted such that
/// the defined Pstates begin with table entry 0. The table need not be full -
/// the \a pmin and \a entries fields define the minimum and maximum Pstates
/// represented in the table.  However at least 1 entry must be defined to
/// create a legal table.
///
/// Note that Global Pstate table structures to be mapped into PMC hardware
/// must be 1KB-aligned.  This requirement is fullfilled by ensuring that
/// instances of this structure are 1KB-aligned.
typedef struct
{

    /// Pstate options
    ///
    /// The options are included as part of the GlobalPstateTable so that they
    /// are available to all procedures after gpsm_initialize().
    PstateOptions options;

    /// The frequency associated with Pstate[0] in KHz
    uint32_t reference_frequency_khz;

    /// The frequency step in KHz
    uint32_t frequency_step_khz;

    /// Operating points
    ///
    /// VPD operating points are stored without load-line correction.  Frequencies
    /// are in MHz, voltages are specified in units of 5mV, and currents are
    /// in units of 500mA.
    VpdOperatingPoint operating_points[VPD_PV_POINTS];

    /// Biases
    ///
    /// Biases applied to the VPD operating points prior to load-line correction
    /// in setting the external voltages.
    /// Values in 0.5%
    VpdBias ext_biases[VPD_PV_POINTS];

    /// Loadlines and Distribution values for the VDD rail
    SysPowerDistParms vdd_sysparm;

    /// Loadlines and Distribution values for the VCS rail
    SysPowerDistParms vcs_sysparm;

    /// Loadlines and Distribution values for the VDN rail
    SysPowerDistParms vdn_sysparm;

    /// The "Safe" Voltage
    ///
    /// A voltage to be used when safe-mode is activated
    /// @todo Need to detail this out yet.
    uint32_t safe_voltage_mv;

    /// The "Safe" Frequency
    ///
    /// A voltage to be used when safe-mode is activated
    /// @todo Need to detail this out yet.
    uint32_t safe_frequency_khz;

    /// The exponent of the exponential encoding of Pstate stepping delay
    uint8_t vrm_stepdelay_range;

    /// The significand of the exponential encoding of Pstate stepping delay
    uint8_t vrm_stepdelay_value;

    /// VDM Data
    VDMParmBlock vdm;

    /// The following are needed to generated the Pstate Table to HOMER.

    /// Internal Biases
    ///
    /// Biases applied to the VPD operating points that are used for interpolation
    /// in setting the internal voltages (eg Vout to the iVRMs) as part of the
    /// Local Actual Pstate.
    /// Values in 0.5%
    VpdBias int_biases[VPD_PV_POINTS];

    /// IVRM Data
    IvrmParmBlock ivrm;

    /// Resonant Clock Grid Management Setup
    ResonantClockingSetup resclk;

    // @todo DPLL Droop Settings.  These need communication to SGPE for STOP

} GlobalPstateParmBlock;




/// The layout of the data created by the Pstate table creation firmware for
/// comsumption by the OCC firmware.  This data will reside in the Quad
/// Power Management Region (QPMR).
///
typedef struct
{

    /// Magic Number
    uint64_t magic;  // the last byte of this number the structure's version.

    /// Operating points
    ///
    /// VPD operating points are stored without load-line correction.  Frequencies
    /// are in MHz, voltages are specified in units of 5mV, and currents are
    /// in units of 500mA.
    VpdOperatingPoint operating_points[VPD_PV_POINTS];

    /// Loadlines and Distribution values for the VDD rail
    SysPowerDistParms vdd_sysparm;

    /// Loadlines and Distribution values for the VCS rail
    SysPowerDistParms vcs_sysparm;

    /// Iddq Table
    IddqTable iddq;

    /// WOF Controls
    WOFElements wof;

    // Frequency Limits
    uint32_t frequency_min_khz;    // Comes from PowerSave #V point after biases
    uint32_t frequency_max_khz;    // Comes from UltraTurbo #V point after biases
    uint32_t frequency_step_khz;   // Comes from refclk/dpll_divider attributes.

    // Todo:  Martha asked for min_psate and max_pstate
    uint32_t pstate_min;    // Comes from PowerSave #V point after biases
    uint32_t pstate_max;    // Comes from UltraTurbo #V point after biases

} OCCPstateParmBlock;


/// The layout of the various Pstate Parameter Blocks (PPBs) passed a single
/// structure for data movement.
///
/// This structure is only used for passing Pstate data from the FSP/HostService
/// for placement into HOMER for consumption by into OCC, the Pstate PGPE and
/// CME. Therefore there is no alignment requirement.

typedef struct
{

    /// Magic Number
    uint64_t magic;

    // PGPE content
    GlobalPstateParmBlock globalppb;

    // CME content
    LocalPstateParmBlock localppb;

    // OCC content
    OCCPstateParmBlock occppb;

} PstateSuperStructure;

/// Pstate Table
///
/// This structure defines the Pstate Table content
/// -- 16B structure

typedef struct
{
    /// Pstate number
    Pstate      pstate;

    /// Assocated Frequency (in MHz)
    uint16_t    frequency_mhz;

    /// External VRM setpoint (in mV).  this directly translates to AVSBus value
    uint16_t    external_vdd_mv;

    /// Effective VDD voltage at the module pins.  This accounts for the system
    /// parameter effects.
    uint16_t    effective_vdd_mv;

    /// Maximum iVRM regulation voltage.  This is effective_vdd_mv - dead_zone_mv.
    uint16_t    max_regulation_vdd_mv;

    /// Internal VDD voltage at the output of the PFET header
    uint16_t    internal_vdd_mv;

    /// Pad to 16 bytes
    uint32_t    spare;

} PstateTable;

/// Generated Pstate Table
///
/// This structure defines the Pstate Tables generated by PGPE Hcode upon
/// initialization.  This content depicts the values that will be computed on the
/// fly during Pstate protocol execution based on the PstateSuperStructure
/// parameter content.

static const uint32_t MAX_PSTATE_TABLE_ENTRIES = 128;

typedef struct
{

    /// Magic Number
    uint64_t magic;   // ASCII: "PSTATABL"

    // PGPE content
    GlobalPstateParmBlock globalppb;

    /// The fastest frequency - after biases have been applied
    uint32_t pstate0_frequency_khz;

    /// Highest Pstate Number => slowest Pstate generated
    uint32_t highest_pstate;

    /// Generated table with system paramters included but without biases
    PstateTable raw_pstates[MAX_PSTATE_TABLE_ENTRIES];

    /// Generated table with system paramters and biases
    /// Note: if all bias attributes are 0, this content will be the same
    /// as the raw_pstates content.
    PstateTable biased_pstates[MAX_PSTATE_TABLE_ENTRIES];

} GeneratedPstateInfo;



#ifdef __cplusplus
} // end extern C
#endif

#endif    /* __P9_PSTATES_H__ */
