/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pstates_common.h $  */
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
/// @file  p9_pstates_common.h
/// @brief Common Pstate definitions
///
// *HWP HW Owner        : Rahul Batra <rbatra@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE:CME:HB:OCC


#ifndef __P9_PSTATES_COMMON_H__
#define __P9_PSTATES_COMMON_H__

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
#define VPD_PV_ORDER_STR {"Nominal   ","PowerSave ", "Turbo     ", "UltraTurbo"}
#define POWERSAVE   1
#define NOMINAL     0
#define TURBO       2
#define ULTRA       3
#define POWERBUS    4
#define VPD_PV_ORDER {POWERSAVE, NOMINAL, TURBO, ULTRA}

#define VPD_PV_CORE_FREQ_MHZ    0
#define VPD_PV_VDD_MV           1
#define VPD_PV_IDD_100MA        2
#define VPD_PV_VCS_MV           3
#define VPD_PV_ICS_100MA        4
#define VPD_PV_PB_FREQ_MHZ      0
#define VPD_PV_VDN_MV           1
#define VPD_PV_IDN_100MA        2

#define VPD_NUM_SLOPES_SET  2
#define VPD_SLOPES_RAW      0
#define VPD_SLOPES_BIASED   1
#define VPD_NUM_SLOPES_REGION       3
#define REGION_POWERSAVE_NOMINAL    1
#define REGION_NOMINAL_TURBO        0
#define REGION_TURBO_ULTRA          2


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

#ifdef __cplusplus
extern "C" {
#endif

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

// ssrivath, Modified units for vdd/vcs/idd/ics as per P9 VPD spec
/// A VPD operating point
///
/// VPD operating points are stored without load-line correction.  Frequencies
/// are in MHz, voltages are specified in units of 1mV, and characterization
/// currents are specified in units of 100mA.
///
typedef struct
{

    uint32_t vdd_mv;
    uint32_t vcs_mv;
    uint32_t idd_100ma;
    uint32_t ics_100ma;
    uint32_t frequency_mhz;
    uint8_t  pstate;        // Pstate of this VpdOperating
    uint8_t  pad[3];

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


//
// WOF Voltage, Frequency Ratio Tables
//

// VDN

// Data is provided in 12ths (eg 12 core pairs on a 24 core chip)
#define VFRT_VRATIO_SIZE 12

// 100%/10% steps + 1 (for 0)
#define VFRT_FRATIO_SIZE 11

typedef uint16_t VFRT_Circuit_t;   // Holds a frequency in MHz
typedef Pstate   VFRT_Hcode_t;

extern VFRT_Circuit_t VFRTCircuitTable[VFRT_FRATIO_SIZE][VFRT_FRATIO_SIZE];

extern VFRT_Hcode_t   VFRTInputTable[VFRT_FRATIO_SIZE][VFRT_FRATIO_SIZE];


#ifdef __cplusplus
} // end extern C
#endif

#endif    /* __P9_PSTATES_COMMON_H__ */
