/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/pstates_common.H $    */
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
/// @file  pstates_common.H
/// @brief Common Pstate definitions
///
// *HWP HW Owner        : Rahul Batra <rbatra@us.ibm.com>
// *HWP HW Owner        : Greg Still<stillgs@us.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE:QME:HB:OCC


#ifndef __PSTATES_COMMON_H__
#define __PSTATES_COMMON_H__

#include <stdint.h>

/// Cores and Quads
#define MAXIMUM_CORES   32
#define MAXIMUM_QUADS   8
#define MAXIMUM_EQ_SETS 4    // A set of 8 cores that are grouped for IDDQ

#define NUM_OP_POINTS      8
#define NUM_PV_POINTS      8
#define VPD_PV_PSAV        0
#define VPD_PV_CF0         0
#define VPD_PV_CF1         1
#define VPD_PV_CF2         2
#define VPD_PV_CF3         3
#define VPD_PV_CF4         4
#define VPD_PV_CF5         5
#define VPD_PV_CF6         6
#define VPD_PV_CF7         7
#define VPD_PV_UT          6
#define VPD_PV_FMAX        7

#define VPD_PV_STR { \
        "CF0", \
        "CF1", \
        "CF2", \
        "CF3", \
        "CF4", \
        "CF5", \
        "CF6", \
        "CF7"  \
    }

/// VPD #V Operating Points (eg Natural order)
#define POWERSAVE   0
#define CF0         0
#define CF1         1
#define CF2         2
#define CF3         3
#define CF4         4
#define CF5         5
#define CF6         6
#define CF7         7
#define ULTRA       6
#define FMAX        7
#define PV_OP {CF0, CF1, CF2, CF3, CF4, CF5, CF6, CF7}
#define PV_OP_STR { \
        "CF0       ", \
        "CF1       ", \
        "CF2       ", \
        "CF3       ", \
        "CF4       ", \
        "CF5       ", \
        "CF6       ", \
        "CF7       "  \
    }


#define VPD_PV_CORE_FREQ_MHZ    0
#define VPD_PV_VDD_MV           1
#define VPD_PV_IDD_TDP_AC_10MA  2
#define VPD_PV_IDD_TDP_DC_10MA  3
#define VPD_PV_IDD_RDP_AC_10MA  4
#define VPD_PV_IDD_RDP_DC_10MA  5
#define VPD_PV_VCS_MV           6
#define VPD_PV_ICS_TDP_AC_10MA  7
#define VPD_PV_ICS_TDP_DC_10MA  8
#define VPD_PV_CORE_FREQ_GB_MHZ 9
#define VPD_PV_VDD_VIN_MV       10
#define VPD_PV_IDD_PWR_PAT_10MA 11
#define VPD_PV_TEMP_PWR_PAT_P5C 12

// Different points considered for calculating slopes
#define VPD_NUM_SLOPES_REGION       7
#define NUM_VPD_PTS_SET             3
#define VPD_PT_SET_RAW              0
#define VPD_PT_SET_BIASED           1
#define VPD_PT_SET_BIASED_SYSP      2
#define VPD_PT_SET {VPD_PT_SET_RAW, VPD_PT_SET_BIASED, VPD_PT_SET_BIASED_SYSP}
#define VPD_PT_SET_STR {"Raw", "Biased", "Biased/SysParam"}
/// @todo Remove the systparm version?

#define VPD_NUM_SLOPES_REGION       7
#define REGION_POWERSAVE_CF1        0
#define REGION_CF0_CF1              0
#define REGION_CF1_CF2              1
#define REGION_CF2_CF3              2
#define REGION_CF3_CF4              3
#define REGION_CF4_CF5              4
#define REGION_CF5_CF6              5
#define REGION_CF6_CF7              6
#define REGION_CF5_UT               5
#define REGION_UT_FMAX              6
#define VPD_OP_SLOPES_REGION_ORDER {REGION_CF0_CF1, REGION_CF1_CF2, REGION_CF2_CF3, REGION_CF3_CF4, REGION_CF4_CF5, REGION_CF5_CF6, REGION_CF6_CF7,}
#define VPD_OP_SLOPES_REGION_ORDER_STR { \
        "CF0_CF1      ", \
        "CF1_CF2      ", \
        "CF2_CF3      ", \
        "CF3_CF4      ", \
        "CF4_CF5      ", \
        "CF5_CF6      ", \
        "CF6_CF7      ", \
    }


#define VID_SLOPE_FP_SHIFT_12       12
#define THRESH_SLOPE_FP_SHIFT       12
#define I_SLOPE_FP_SHIFT_9           9
#define DDS_DELAY_SLOPE_FP_SHIFT_12 12  //DDS Delay slope format 4.12
#define DDS_SLOPE_FP_SHIFT_6         6  //DDS fields(except delay) slope format 2.6

#define THROTTLE_PSTATES            64  //Number of Ptates to index into Throttle Table

/// IDDQ readings,
#define IDDQ_MEASUREMENTS     6
#define MEASUREMENT_ELEMENTS  4    // Number of groups measured
#define IDDQ_READINGS_PER_IQ  2
#define IDDQ_ARRAY_VOLTAGES     { 0.50    0.60 ,  0.70 ,  0.80 ,  0.90 ,  1.00}
#define IDDQ_ARRAY_VOLTAGES_STR {"0.50", "0.60", "0.70", "0.80", "0.90", "1.00"}

/// VPD #W Data from keyword (eg VPD order)
#define NUM_JUMP_VALUES 4
#define NUM_THRESHOLD_POINTS 4
#define VPD_THRESHOLD_STR {"Overvolt", "Small", "Large", "Extreme" }

/// Digital Droop Sensor (DDS) actuation
#ifndef __ASSEMBLER__
typedef enum
{
    DDS_OVERVOLT_INDEX = 0,
    DDS_SMALL_INDEX    = 1,
    DDS_LARGE_INDEX    = 2,
    DDS_XTREME_INDEX   = 3
} DDS_THRESHOLD_INDEX;

typedef enum
{
    DDS_N_S_INDEX = 0,
    DDS_N_L_INDEX = 1,
    DDS_L_S_INDEX = 2,
    DDS_S_N_INDEX = 3
} DDS_JUMP_VALUE_INDEX;
#endif

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C" {
#endif

/// A Pstate type
///
/// Pstates are unsigned but, to avoid bugs, Pstate register fields should
/// always be extracted to a variable of type Pstate.  If the size of Pstate
/// variables ever changes we will have to revisit this convention.
typedef uint8_t Pstate_t;

/// A DPLL frequency code
///
/// DPLL frequency codes (Fmax and Fmult) are 15 bits
typedef uint16_t DpllCode_t;

/// An AVS VID code
typedef uint16_t VidAVS_t;

/// #V frequency, voltage and current operating point
///
/// Frequencies are in MHz, voltages are specified in units of 1mV, currents
/// are specified in units of 10mA, and temperatures are specified in 0.5
/// degrees C.
///
typedef struct
{
    uint32_t frequency_mhz;
    uint32_t vdd_mv;
    uint32_t idd_tdp_ac_10ma;
    uint32_t idd_tdp_dc_10ma;
    uint32_t idd_rdp_ac_10ma;
    uint32_t idd_rdp_dc_10ma;
    uint32_t vcs_mv;
    uint32_t ics_tdp_ac_10ma;
    uint32_t ics_tdp_dc_10ma;
    uint32_t ics_rdp_ac_10ma;
    uint32_t ics_rdp_dc_10ma;
    uint32_t frequency_guardband_sort_mhz;
    uint32_t vdd_vmin;
    uint32_t idd_power_pattern_10ma;
    uint32_t core_power_pattern_temp_0p5C;
    uint8_t  pstate;        // Pstate of this VpdOperating
    uint8_t  pad[3];        // Alignment padding
} PoundVOpPoint_t;

/// #V VPD Biases
///
/// Percent bias applied to VPD operating points prior to interolation
///
/// All values on in .5 percent (0p5pct)
typedef struct
{
    int8_t frequency_0p5pct;
    int8_t vdd_ext_0p5pct[NUM_PV_POINTS];
    int8_t vcs_ext_0p5pct[NUM_PV_POINTS];
} PoundVBias_t;

///
/// #V Static Rail content
///
typedef struct
{
    uint32_t vdn_mv;
    uint32_t idn_tdp_ac_10ma;
    uint32_t idn_tdp_dc_10ma;
    uint32_t vio_mv;
    uint32_t iio_tdp_ac_10ma;
    uint32_t iio_tdp_dc_10ma;
    uint32_t vpci_mv;
    uint32_t ipci_tdp_ac_10ma;
    uint32_t ipci_tdp_dc_10ma;;
} PoundVStaticRails_t;

///
/// #V Other Info content
///
typedef struct
{
    uint32_t pau_frequency_mhz;
    uint32_t total_sort_socket_power_target_W;
    uint32_t vdn_sort_socket_power_alloc_W;
    uint32_t vio_sort_socket_power_alloc_W;
    uint32_t vpci_sort_socket_power_alloc_W;
    uint32_t total_sort_socket_power_actual_0p1W;
    uint32_t idd_rdp_limit_0p1A;
    uint32_t vdd_tdp_wof_index;
    uint32_t vcs_tdp_wof_index;
    uint32_t vio_tdp_wof_index;
    uint32_t amb_cond_tdp_wof_index;
    uint32_t mode_interpolation;
    uint32_t rdp_sort_power_temp_0p5C;
    uint32_t tdp_sort_power_temp_0p5C;
    uint32_t tdp_wof_base_freq_mhz;
    uint32_t fixed_freq_mhz;
    uint32_t powersave_freq_mhz;
    uint32_t ultraturbo_freq_mhz;
    uint32_t fmax_freq_mhz;
    uint32_t mma_throttle_temp_0p5C;
    uint32_t io_throttle_temp_0p5C;
    uint32_t fixed_freq_mode_power_target_0p;
} PoundVOtherInfo_t;


/// System Power Distribution Paramenters
///
/// Parameters set by system design that influence the power distribution
/// for a rail to the processor module.  This values are typically set in the
/// system machine readable workbook and are used in the generation of the
/// Global Pstate Table.
typedef struct
{

    /// Loadline
    ///   Impedance (binary microOhms) of t__PSTATES_COMMON_H__he load line from a processor VDD VRM
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

} SysPowerDistParms_t;

/// AVSBUS Topology
///
/// AVS Bus and Rail numbers for VDD, VDN, VCS, and VIO
///
typedef struct
{
    uint8_t vdd_avsbus_num;
    uint8_t vdd_avsbus_rail;
    uint8_t vdn_avsbus_num;
    uint8_t vdn_avsbus_rail;
    uint8_t vcs_avsbus_num;
    uint8_t vcs_avsbus_rail;
    uint8_t vio_avsbus_num;
    uint8_t vio_avsbus_rail;
} AvsBusTopology_t;

//
// Workload Optimized Frequency (WOF) Structures
//

typedef enum
{
    WOF_MODE_UNKNOWN = 0,
    WOF_MODE_NORMAL = 1,
} WOF_MODE;

/// Header associated with the WOF Table set
typedef struct
{

    ///  ---- Double word 0 -----

    /// Magic Value
    ///   Set to ASCII  "WFTH"

    union magic_number_t
    {
        uint32_t value;
        char     text[4];
    } magic_number;

    uint8_t  reserved0[3];

    /// Layouut version of this structure
    uint8_t  header_version;

    ///  ---- Double word 1 -----

    /// VRT Block Size
    ///    Length, in bytes, of a VRT
    uint16_t vrt_block_size;

    /// VRT block header size
    uint16_t vrt_block_header_size;

    /// VRT Data Size
    ///    Length, in bytes, of the data field.
    uint16_t vrt_data_size;

    /// Over-Current Mode.
    /// 0: Table set assumes OCS is OFF; 1: Table set assumes OCS is ON
    uint8_t ocs_mode;

    /// Core count
    uint8_t core_count;

    ///  ---- Double word 2 -----

    /// Ceff Vcs Start
    ///    CeffVcs value represented by index 0 (in 0.01%)
    uint16_t vcs_start;

    /// Ceff Vdn Step
    ///    CeffVcs step value for each CeffVdn index (in 0.01%)
    uint16_t vcs_step;

    /// Ceff Vcs Size
    ///    Number of CeffVcs indexes
    uint16_t vcs_size;

    /// Ceff Vdd Start
    ///    CeffVdd value represented by index 0 (in 0.01%)
    uint16_t vdd_start;

    ///  ---- Double word 3 -----

    /// Ceff Vdd Step
    ///    CeffVdd step value for each CeffVdd index (in 0.01%)
    uint16_t vdd_step;

    /// Ceff Vdd Size
    ///    Number of CeffVdd indexes
    uint16_t vdd_size;

    /// Vratio Start
    ///    Vratio value represented by index 0 (in 0.01%)
    uint16_t vratio_start;

    /// Vratio Step
    ///   Vratio step value for each CeffVdd index (in 0.01%)
    uint16_t vratio_step;

    ///  ---- Double word 4 -----

    /// Vratio Size
    ///    Number of Vratio indexes
    uint16_t vratio_size;

    /// IO Start
    ///    IO value represented by index 0 (in 0.01%)
    uint16_t io_start;

    /// IO Step
    ///   IO step value for each CeffIO index (in 0.01%)
    uint16_t io_step;

    /// IO Size
    ///    Number of IO indexes
    uint16_t io_size;

    ///  ---- Double word 5 -----

    /// Ambient Condition Start
    ///    Ambient Condition represented by index 0 (in 0.01%)
    uint16_t amb_cond_start;

    /// Ambient Condition Step
    ///    Ambient Condition step value for each CeffAmb index (in 0.01%)
    uint16_t amb_cond_step;

    /// Ambient Condition Size
    ///    Number of Ambient Condition indexes
    uint16_t amb_cond_size;

    uint16_t reserved1;

    ///  ---- Double word 6 -----

    /// Socket Power (in Watts) for the WOF Tables
    uint16_t socket_power_w;

    /// Core Sort Power Target Frequency (in MHz), The #V frequency associated
    /// with the sort power target for this table set. This is the WOF Base
    /// frequency.
    uint16_t sort_power_freq_mhz;

    /// Regulator Design Point Current Capacity (in Amps)
    uint16_t rdp_current_a;

    /// Boost Current Capacity (in Amps)
    uint16_t boost_current_a;

    ///  ---- Double word 7 -----

    /// Thermal Design Point (TDP) VCS Ceff Index
    uint8_t  vcs_tdp_ceff_indx;

    /// Thermal Design Point (TDP) VDD Ceff Index
    uint8_t  vdd_tdp_ceff_indx;

    /// TDP IO Power index
    uint8_t  io_tdp_pwr_indx;

    /// TDP Amb Cond index
    uint8_t  amb_cond_tdp_indx;

    /// Thermal Design Point (TDP) IO Wattage (Watts)
    uint8_t  io_tdp_w;

    /// IO TDP Disabled wattage
    uint8_t  io_dis_w;

    /// Core Sort UltraTurbo Frequency (in MHz)
    uint16_t sort_ultraturbo_freq_mhz;

    ///  ---- Double word 8 -----

    /// Date Timestamp of the table set as established by the generation process.
    uint32_t table_date_timestamp;

    uint32_t reserved2;

    ///  ---- Double word 9 and 10 ----

    /// Up to 16 ASCII characters as a Table Version as established by the
    /// generation process.
    char table_version[16];

    ///  ---- Double word 11 and 12 -----

    /// Up to 16 ASCII characters as a Package designator
    char package_name[16];

    // Padding to 128B is left to the compiler via the following attribute.

} __attribute__((packed, aligned(128))) WofTablesHeader_t;

/// Header associated with the WOF Voltage Ratio Tables (VRT)
typedef struct
{
    union
    {
        uint32_t value;
        struct
        {
#ifdef _BIG_ENDIAN
            uint32_t    marker              : 8;
            uint32_t    type                : 1;
            uint32_t    content             : 1;
            uint32_t    version             : 2;
            uint32_t    io_id               : 2;
            uint32_t    ac_id               : 2;
            uint32_t    vcs_ceff_ratio_pct  : 8;
            uint32_t    vdd_ceff_ratio_pct  : 8;
#else
            uint32_t    vdd_ceff_ratio_pct  : 8;
            uint32_t    vcs_ceff_ratio_pct  : 8;
            uint32_t    ac_id               : 2;
            uint32_t    io_id               : 2;
            uint32_t    version             : 2;
            uint32_t    content             : 1;
            uint32_t    type                : 1;
            uint32_t    marker              : 8;
#endif

        } fields;
    };
} VRT_header_t;

#define WOF_CEF_VDD_SIZE  26    // Indexes: 5% to 150% in 5% steps
#define WOF_CEF_VCS_SIZE  6     // Indexes: 33%, 66%, 100%, 133%, 166%, 200%
#define WOF_IO_SIZE       4     // Indexes: Max-Min/4 to 100% in Max-Min/3 steps
#define WOF_AMBCOND_SIZE  4     // Indexes: Max-Min/4 to 100% in Max-Min/3 steps
#define WOF_VRT_SIZE      12    // Indexes: 31.25% to 100% in 6.25% steps

/// WOF Voltage Ratio Tables (VRT) -- 16B
typedef struct
{
    VRT_header_t vrtHeader;
    uint8_t      data[WOF_VRT_SIZE];
} VRT_t;


/// WOF HOMER Voltage Ratio Table - contents in the form of Pstates and throttle %
typedef struct
{
    VRT_t           ambcond[WOF_AMBCOND_SIZE];
} WOFAmbCond_t;

typedef struct
{
    WOFAmbCond_t    iodlr[WOF_IO_SIZE];
} WOFIO_t;

typedef struct
{
    WOFIO_t         vdd[WOF_CEF_VDD_SIZE];
} WOFVDD_t;

typedef struct
{
    WOFVDD_t        vcs[WOF_CEF_VCS_SIZE];
} WOFVCS_t;

/// WOF System Voltage Rato Tables - contents in the form of frequency and throttle %
typedef struct SystemVRTLayout
{
    WofTablesHeader_t wof_header_data;
    WOFVCS_t          vrt_array;
} SystemVRTLayout_t;

/// WOF HOMER Voltage Ratio Table Set - header plus table set
typedef struct
{
    WofTablesHeader_t wof_header_data;
    WOFVCS_t          vrt_array;
} HomerVRTLayout_t;

#ifdef __cplusplus
} // end extern C
#endif
#endif    /* __ASSEMBLER__ */
#endif    /* __PSTATES_COMMON_H__ */
