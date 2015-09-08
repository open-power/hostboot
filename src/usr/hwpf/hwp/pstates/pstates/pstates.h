/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstates.h $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
/* [+] Google Inc.                                                        */
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
#ifndef __PSTATES_H__
#define __PSTATES_H__

// $Id: pstates.h,v 1.14 2015/06/01 19:02:17 stillgs Exp $

/// \file pstates.h
/// \brief Pstate structures and support routines for OCC product firmware

#include "pgp_common.h"

////////////////////////////////////////////////////////////////////////////
// Global and Local Pstate Tables
////////////////////////////////////////////////////////////////////////////

/// The Global Pstate Table must be 1KB-aligned in SRAM. The alignment is
/// specified in the traditional log2 form.
#define GLOBAL_PSTATE_TABLE_ALIGNMENT 10

/// The Global Pstate table has 128 * 8-byte entries
#define GLOBAL_PSTATE_TABLE_ENTRIES 128

/// The Local Pstate table has 32 x 64-bit entries
#define LOCAL_PSTATE_ARRAY_ENTRIES 32

/// The VDS/VIN table has 32 x 64-bit entries
#define VDSVIN_ARRAY_ENTRIES       64

/// The VRM-11 VID base voltage in micro-Volts
#define VRM11_BASE_UV 1612500

/// The VRM-11 VID step as an unsigned number (micro-Volts)
#define VRM11_STEP_UV 6250

/// The iVID base voltage in micro-Volts
#define IVID_BASE_UV 600000

/// The iVID step as an unsigned number (micro-Volts)
#define IVID_STEP_UV 6250

/// CPM Inflection Points
#define CPM_RANGES 8

/// VPD #V Operating Points
#define VPD_PV_POINTS 4
#define VPD_PV_ORDER_STR {"PowerSave", "Nominal    ", "Turbo    ", "UltraTurbo"}
#define POWERSAVE   0
#define NOMINAL     1
#define TURBO       2
#define ULTRA       3

/// IDDQ readings
#define CORE_IDDQ_MEASUREMENTS 6
#define CHIP_IDDQ_MEASUREMENTS 1

#define CORE_IDDQ_ARRAY_VOLTAGES {0.80, 0.90, 1.00, 1.10, 1.20, 1.25}
#define CHIP_IDDQ_ARRAY_VOLTAGES {1.10}

/// Iddq LRPx and CRPx elements
#define LRP_IDDQ_RECORDS    CORE_IDDQ_MEASUREMENTS
#define CRP_IDDQ_RECORDS    CHIP_IDDQ_MEASUREMENTS
#define IDDQ_READINGS_PER_IQ 2

/// LRPx mapping to Core measurements      1      2      3      4      5       6
///    Index                               0      1      2      3      4       5     
#define CORE_IDDQ_MEASUREMENTS_ORDER   {   1,     2,     3,     4,     5,      0}
#define CORE_IDDQ_MEASUREMENT_VOLTAGES {"0.90", "1.00", "1.10", "1.20", "1.25", "0.80"}
#define CORE_IDDQ_VALIDITY_CHECK       {   1,     1,     1,     1,     1,      0}
#define CORE_IDDQ_VALID_SECOND         {   1,     1,     1,     1,     1,      0}

// CRPx mapping to Chip measurements       0
#define CHIP_IDDQ_MEASUREMENTS_ORDER    {  0 }
#define CHIP_IDDQ_MEASUREMENT_VOLTAGES  {"1.10"}
#define CHIP_IDDQ_VALID_SECOND          {  0 }

/// WOF Items
#define NUM_ACTIVE_CORES 12
#define MAX_UT_PSTATES   64     // Oversized

// Error/Panic codes for support routines

#define VRM11_INVALID_VOLTAGE 0x00876101

#define PSTATE_OVERFLOW  0x00778a01
#define PSTATE_UNDERFLOW 0x00778a02

#define PSTATE_LT_PSTATE_MIN 0x00778a03
#define PSTATE_GT_PSTATE_MAX 0x00778a04

#define DPLL_OVERFLOW  0x00d75501
#define DPLL_UNDERFLOW 0x00d75502

#define VID11_OVERFLOW  0x00843101
#define VID11_UNDERFLOW 0x00843102

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

/// PstateSuperStructure Magic Number
///
/// This magic number identifies a particular version of the
/// PstateSuperStructure and its substructures.  The version number should be
/// kept up to date as changes are made to the layout or contents of the
/// structure.

#define PSTATE_SUPERSTRUCTURE_MAGIC 0x5053544154453034ull /* PSTATE04 */


/// \defgroup pstate_options Pstate Options
///
/// These are flag bits for the \a options field of the PstateOptions
/// structure.
///
/// @{

/// gpsm_gpst_install() - Bypass copying the Pstate table from the
/// PstateSuperStructure into the aligned global location.
#define PSTATE_NO_COPY_GPST       0x01

/// gpsm_gpst_install() - Bypass Global Pstate Table installation and setup.
#define PSTATE_NO_INSTALL_GPST    0x02

/// gpsm_lpsa_install() - Bylass Local Pstate Array installation and setup
#define PSTATE_NO_INSTALL_LPSA    0x04

/// gpsm_resclk_install - Bypass resonant clocking Pstate limit setup
#define PSTATE_NO_INSTALL_RESCLK  0x08

/// gpsm_enable_pstates() - Force the system to the minimum Pstate at
/// initialization
///
/// This mode is added as a workaround for the case that the SPIVID interface
/// is not working correctly during initial bringup.  This forces Pstate mode
/// to come up at a low frequency.
#define PSTATE_FORCE_INITIAL_PMIN 0x10

/// Flag to indicated that the 0.8V readings in the IDDQ Table are valid
#define PSTATE_IDDQ_0P80V_VALID   0x20
#define PSTATE_IDDQ_0P80V_INVALID ~PSTATE_IDDQ_0P80V_VALID

/// @}

#ifndef __ASSEMBLER__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <p8_ivrm.H>

/// A Global Pstate Table Entry, in the form of a packed 'firmware register'
///
/// Global Pstate table entries are referenced by OCC firmware, for example
/// in procedures that do 'manual' Pstate manipulation.

typedef union gpst_entry {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
    uint64_t evid_vdd     : 8;
    uint64_t evid_vcs     : 8;
    uint64_t reserved16   : 1;
    uint64_t evid_vdd_eff : 7;
    uint64_t reserved24   : 1;
    uint64_t evid_vcs_eff : 7;
    uint64_t reserved32   : 1;
    uint64_t maxreg_vdd   : 7;
    uint64_t reserved40   : 1;
    uint64_t maxreg_vcs   : 7;
        uint64_t reserved48   : 8;
        uint64_t ecc          : 8;
#else
        uint64_t ecc          : 8;
        uint64_t reserved48   : 8;
    uint64_t maxreg_vcs   : 7;
    uint64_t reserved40   : 1;
    uint64_t maxreg_vdd   : 7;
    uint64_t reserved32   : 1;
    uint64_t evid_vcs_eff : 7;
    uint64_t reserved24   : 1;
    uint64_t evid_vdd_eff : 7;
    uint64_t reserved16   : 1;
    uint64_t evid_vcs     : 8;
    uint64_t evid_vdd     : 8;
#endif // _BIG_ENDIAN
    } fields;

} gpst_entry_t;


/// A Local Pstate Table Entry, in the form of a packed 'firmware register'
///
/// This structure is provided for reference only; Currently the OCC firmware
/// does not manupulate Local Pstate table entries, however it is possible
/// that future lab applications will require this.

typedef union lpst_entry {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
    uint64_t ivid_vdd          : 7;
    uint64_t ivid_vcs          : 7;
    uint64_t vdd_core_pwrratio : 6;
    uint64_t vcs_core_pwrratio : 6;
    uint64_t vdd_eco_pwrratio  : 6;
    uint64_t vcs_eco_pwrratio  : 6;
    uint64_t ps1_vid_incr      : 3;
    uint64_t ps2_vid_incr      : 3;
    uint64_t ps3_vid_incr      : 3;
    uint64_t reserved47        : 7;
    uint64_t inc_step          : 3;
    uint64_t dec_step          : 3;
    uint64_t reserved60        : 4;
#else
    uint64_t reserved60        : 4;
    uint64_t dec_step          : 3;
    uint64_t inc_step          : 3;
    uint64_t reserved47        : 7;
    uint64_t ps3_vid_incr      : 3;
    uint64_t ps2_vid_incr      : 3;
    uint64_t ps1_vid_incr      : 3;
    uint64_t vcs_eco_pwrratio  : 6;
    uint64_t vdd_eco_pwrratio  : 6;
    uint64_t vcs_core_pwrratio : 6;
    uint64_t vdd_core_pwrratio : 6;
    uint64_t ivid_vcs          : 7;
    uint64_t ivid_vdd          : 7;
#endif // _BIG_ENDIAN
    } fields;

} lpst_entry_t;


/// A VDS/VIN table Entry

typedef union vdsvin_entry {
    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
    uint64_t ivid0             : 7;
    uint64_t ivid1             : 7;
    uint64_t reserved14        : 2;
    uint64_t pfet0             : 5;
    uint64_t pfet1             : 5;
    uint64_t pfet2             : 5;
    uint64_t pfet3             : 5;
    uint64_t pfet4             : 5;
    uint64_t pfet5             : 5;
    uint64_t pfet6             : 5;
    uint64_t pfet7             : 5;
    uint64_t reserved_56       : 8;
#else
    uint64_t reserved_56       : 8;
    uint64_t pfet7             : 5;
    uint64_t pfet6             : 5;
    uint64_t pfet5             : 5;
    uint64_t pfet4             : 5;
    uint64_t pfet3             : 5;
    uint64_t pfet2             : 5;
    uint64_t pfet1             : 5;
    uint64_t pfet0             : 5;
    uint64_t reserved14        : 2;
    uint64_t ivid1             : 7;
    uint64_t ivid0             : 7;
#endif // _BIG_ENDIAN
    } fields;
} vdsvin_entry_t;

/// Standard options controlling Pstate setup and GPSM procedures

typedef struct {

    /// Option flags; See \ref pstate_options
    uint32_t options;

    /// Pad structure to 8 bytes.  Could also be used for other options later.
    uint32_t pad;

} PstateOptions;


/// An abstract Global Pstate table
///
/// The GlobalPstateTable is an abstraction of a set of voltage/frequency
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

typedef struct {

    /// The Pstate table
    gpst_entry_t pstate[GLOBAL_PSTATE_TABLE_ENTRIES];

    /// Pstate options
    ///
    /// The options are included as part of the GlobalPstateTable so that they
    /// are available to all procedures after gpsm_initialize().
    PstateOptions options;

    /// The frequency associated with Pstate[0] in KHz
    uint32_t pstate0_frequency_khz;

    /// The frequency step in KHz
    uint32_t frequency_step_khz;

    /// The DPLL frequency code corresponding to Pstate 0
    ///
    /// This frequency code is installed in the PCB Slave as the DPLL Fnom
    /// when the Pstate table is activated. Normally this frequency code is
    /// computed as
    ///
    ///     pstate0_frequency_khz / frequency_step_khz
    ///
    /// however it may be replaced by any other code as a way to
    /// transparently bias frequency on a per-core basis.
    DpllCode pstate0_frequency_code[PGP_NCORES];

    /// The DPLL Fmax bias
    ///
    /// This bias value (default 0, range -8 to +7 frequency ticks) is
    /// installed when the Pstate table is installed.  The value is allowed to
    /// vary per core.  This bias value will usually be set to a small
    /// positive number to provide a small amount of frequency headroom for
    /// the CPM-DPLL voltage control algorithm.
    ///
    /// \bug Hardware currently specifies this field as unsigned for the
    /// computation of frequency stability in
    /// dpll_freqout_mode_en. (HW217404).  This issue will be fixed in
    /// Venice. Since we never plan to use this mode no workaround or
    /// mitigation is provided by GPSM procedures.

    int8_t dpll_fmax_bias[PGP_NCORES];

    /// The number of entries defined in the table.
    uint8_t entries;

    /// The minimum Pstate in the table
    ///
    /// Note that gpsi_min = pmin - PSTATE_MIN, gpsi_max = pmin + entries - 1.
    Pstate pmin;

    /// The "Safe" Global Pstate
    ///
    /// This Pstate is installed in the PMC and represents the safe-mode
    /// voltage.
    Pstate pvsafe;

    /// The "Safe" Local Pstate
    ///
    /// This Pstate is installed in the PCB Slaves and represents the
    /// safe-mode frequency.
    Pstate psafe;

    /// Step size of Global Pstate steps
    uint8_t pstate_stepsize;

    /// The exponent of the exponential encoding of Pstate stepping delay
    uint8_t vrm_stepdelay_range;

    /// The significand of the exponential encoding of Pstate stepping delay
    uint8_t vrm_stepdelay_value;

    /// The Pstate for minimum core frequency in the system, defined by MRW
    uint8_t pfloor;
    
    /// The Pstate representing the Turbo VPD point  
    Pstate turbo_ps;
    
    /// The Pstate representing the Nominal VPD point  
    Pstate nominal_ps;
    
    /// The Pstate representing the PowerSave VPD point  
    Pstate powersave_ps;
    
    /// The Pstate within the GPST which is the maximum for which iVRMs are
    /// defined.  This allows WOF Pstate and iVRM Pstates to be non-overlapping
    /// to simplify characterization.  
    Pstate ivrm_max_ps;
    
    /// The number of entries over which iVRM enablement is possible.  The
    /// starting entry is PMin.
    uint8_t ivrm_entries;
    

} GlobalPstateTable;


/// This macro creates a properly-aligned Global Pstate table structure as a
/// static initialization.

#define GLOBAL_PSTATE_TABLE(x)                                  \
    GlobalPstateTable x                                         \
    ALIGNED_ATTRIBUTE(POW2_32(GLOBAL_PSTATE_TABLE_ALIGNMENT))   \
        SECTION_ATTRIBUTE(".noncacheable")                      \
        = {.entries = 0}


/// An opaque Local Pstate Array
///
/// An array local to each core contains the Local Pstate Table, Vds table and
/// Vin table. The array contents are presented to OCC firmware as an opaque
/// set of 96 x 64-bit entries which are simply installed verbatim into each
/// core. Every core stores the same table.
///
/// When installed in the core, Local Pstate table indices are adjusted such
/// that the defined Pstates begin with table entry 0. The table need not be
/// full - the \a pmin and \a entries fields define the minimum and maximum
/// Pstates represented in the table.  However at least 1 entry must be
/// defined to create a legal table.

typedef struct {

    /// The vdsvin table contents
    vdsvin_entry_t vdsvin[VDSVIN_ARRAY_ENTRIES];

    /// The local pstate table contents
    lpst_entry_t pstate[LOCAL_PSTATE_ARRAY_ENTRIES];

    /// The number of entries defined in the Local Pstate Table
    uint8_t entries;

    /// The minimum Pstate in the Local Pstate table
    ///
    /// Note that lpsi_min = pmin - PSTATE_MIN, lpsi_max = pmin + entries - 1.
    Pstate pmin;

    /// Pstate step delay for rising iVRM voltages
    uint8_t stepdelay_rising;

    /// Pstate step delay for falling iVRM voltages
    uint8_t stepdelay_lowering;

    /// Pad structure to 8-byte alignment
    uint8_t pad[4];

} LocalPstateArray;


/// Resonant Clocking setup parameters
///
/// All Pstate parameters are specified in terms of Pstates as defined in the
/// current PstateSuperStructure.

typedef struct {

    /// Full Clock Sector Buffer Pstate
    Pstate full_csb_ps;

    /// Low-Frequency Resonant Lower Pstate
    Pstate res_low_lower_ps;

    /// Low-Frequency Resonant Upper Pstate
    Pstate res_low_upper_ps;

    /// High-Frequency Resonant Lower Pstate
    Pstate res_high_lower_ps;

    /// High-Frequency Resonant Upper Pstate
    Pstate res_high_upper_ps;

    /// Pad structure to 8-byte alignment
    uint8_t pad[3];

} ResonantClockingSetup;

/// CPM Pstate ranges per mode
///
/// These Pstate range specifications apply to all chiplets operating in the
/// same mode.

typedef union {

    /// Forces alignment
    uint64_t quad[2];

    struct {

        /// Lower limit of each CPM calibration range
        ///
        /// The entries in this table are Pstates representing the
        /// lowest-numbered (lowest-voltage) Pstate of each range. This is the
        /// inflection point between range N and range N+1.
        Pstate inflectionPoint[CPM_RANGES];

        /// The number of ranges valid in the \a inflectionPoint table
        ///
        /// Validity here is defined by the original characterization
        /// data. Whether or not OCC will use any particular range is managed
        /// by OCC.
        uint8_t validRanges;

        /// The Pstate corresponding to the upper limit of range 0.
        ///
        /// This is the "CPmax" for the mode. The "CPmin" for this
        /// mode is the value of inflectionPoint[valid_ranges - 1].
        Pstate pMax;

        uint8_t pad[6];
    };

} CpmPstateModeRanges;


/// A VPD operating point
///
/// VPD operating points are stored without load-line correction.  Frequencies
/// are in MHz, voltages are specified in units of 5mV, and characterization
/// currents are specified in units of 500mA.
///
/// \bug The assumption is that the 'maxreg' points for the iVRM will also be
/// supplied in the VPD in units of 5mv.  If they are supplied in some other
/// form then chip_characterization_create() will need to be modified.

typedef struct {

    uint32_t vdd_5mv;
    uint32_t vcs_5mv;
    uint32_t vdd_maxreg_5mv;
    uint32_t vcs_maxreg_5mv;
    uint32_t idd_500ma;
    uint32_t ics_500ma;
    uint32_t frequency_mhz;

} VpdOperatingPoint;

/// System Power Distribution Paramenters
///
/// Parameters set by system design that influence the power distribution
/// for a rail to the processor module.  This values are typically set in the 
/// system machine readable workbook and are used in the generation of the 
/// Global Pstate Table.  This values are carried in the Pstate SuperStructure
/// for use and/or reference by OCC firmware (eg the WOF algorithm)

typedef struct {

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
/// Each entry is 2 bytes. The values are in 10mA units; this allow for a
/// maximum value of 655.36A represented.
///
typedef uint16_t iddq_entry_t;

/// IDDQ Reading
///
/// Structure with "raw" and "temperature corrected" values.  See VPD
/// documentation for the correction function that is applied to the raw
/// value to load the corrected value.
///
typedef union {
    uint32_t value;
    struct {
#ifdef _BIG_ENDIAN
        iddq_entry_t iddq_raw_value;
        iddq_entry_t iddq_corrected_value;
#else       
        iddq_entry_t iddq_corrected_value;
        iddq_entry_t iddq_raw_value;
#endif // _BIG_ENDIAN
    } fields;

} IddqReading;

/// Iddq Table
///
/// A set of arrays of leakage values (Iddq) collected at various voltage
/// conditions during manufacturing test that will feed into the Workload
/// Optimized Frequency algorithms on the OCC.  These values are not installed
/// in any hardware facilities.
///
typedef struct {

    /// IDDQ version
    uint8_t     iddq_version;

    /// VDD IDDQ readings
    IddqReading iddq_vdd[CORE_IDDQ_MEASUREMENTS];

    /// VCS IDDQ readings
    IddqReading iddq_vcs[CORE_IDDQ_MEASUREMENTS];

    /// VIO IDDQ readings
    IddqReading iddq_vio[CHIP_IDDQ_MEASUREMENTS];

} IddqTable;



/// UltraTurbo Segment VIDs by Core Count
typedef struct {

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
typedef struct {

    /// WOF Enablement
    uint8_t wof_enabled;

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

/// The layout of the data created by the Pstate table creation firmware
///
/// This structure is only used for passing Pstate data from the FSP into OCC,
/// therefore there is no alignment requirement.  The \gpst member is copied
/// to an aligned location, and the \a lpsa and \a resclk members are directly
/// installed in hardware.
///
/// Both the master and slave OCCs (in DCM-mode) install their Pstate tables
/// independently via the API gpsm_initialize().  At that point the
/// PstateSuperStructure can be discarded.

typedef struct {

    /// Magic Number
    uint64_t magic;

    /// Global Pstate Table
    GlobalPstateTable gpst;

    /// Local Pstate Array
    LocalPstateArray lpsa;

    /// Resonant Clocking Setup
    ResonantClockingSetup resclk;

    /// CPM Pstate ranges
    CpmPstateModeRanges cpmranges;

    /// Iddq Table
    IddqTable iddq;

    /// WOF Controls
    WOFElements wof;

} PstateSuperStructure;


int
vid11_validate(Vid11 vid);

int
bias_pstate(Pstate pstate, int bias, Pstate* biased_pstate);

int
bias_frequency(DpllCode fcode, int bias, DpllCode* biased_fcode);

int
bias_vid11(Vid11 vid, int bias, Vid11* biased_fcode);

int
gpst_entry(const GlobalPstateTable* gpst,
           const Pstate pstate,
           const int bias,
           gpst_entry_t* entry);


int
freq2pState (const GlobalPstateTable* gpst,
             const uint32_t freq_khz,
             Pstate* pstate);

int
gpst_vdd2pstate(const GlobalPstateTable* gpst,
                const uint8_t vdd,
                Pstate* pstate,
                gpst_entry_t* entry);

int
pstate_minmax_chk (const GlobalPstateTable* gpst,
                   Pstate* pstate);

/// Return the Pmin value associated with a GlobalPstateTable
static inline Pstate
gpst_pmin(const GlobalPstateTable* gpst)
{
    return gpst->pmin;
}


/// Return the Pmax value associated with a GlobalPstateTable
static inline Pstate
gpst_pmax(const GlobalPstateTable* gpst)
{
    return (int)(gpst->pmin) + (int)(gpst->entries) - 1;
}

/// Return the Pmin value associated with a LocalPstateTable
static inline Pstate
lpst_pmin(const LocalPstateArray* lpsa)
{
    return lpsa->pmin;
}


/// Return the Pmax value associated with a GlobalPstateTable
static inline Pstate
lpst_pmax(const LocalPstateArray* lpsa)
{
    return (int)(lpsa->pmin) + (int)(lpsa->entries) - 1;
}

#ifdef __cplusplus
} // end extern C
#endif

#endif    /* __ASSEMBLER__ */

#endif    /* __PSTATES_H__ */
