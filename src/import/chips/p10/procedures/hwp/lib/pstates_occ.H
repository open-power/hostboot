/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/pstates_occ.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file  pstates_occ.H
/// @brief Pstate structures and support routines for OCC product firmware
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP FW Owner        : Martha Broyles <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HB:OCC

#ifndef __PSTATES_OCC_H__
#define __PSTATES_OCC_H__

#include <pstates_common.H>
#include <pstates_pgpe.H>

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C" {
#endif

/// PstateParmsBlock Magic Number
///
/// This magic number identifies a particular version of the
/// PstateParmsBlock and its substructures.  The version number should be
/// kept up to date as changes are made to the layout or contents of the
/// structure.

#define OCC_PARMSBLOCK_MAGIC 0x4f43435050423030ull /* OCCPPB00 */

/// IDDQ Reading Type
/// Each entry is 2 bytes. The values are in 5mA units; this allow for a
/// maximum value of 327.675A to be represented.
///
typedef uint16_t iddq_entry_t;

/// AvgTemp Reading Type
/// Each entry is 1 byte. The values are in 0.5degC units; this allow for a
/// maximum value of 127degC to be represented.
///
typedef uint8_t avgtemp_entry_t;

/// IQ VPD Leakage Current Information
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

    /// MMA state for the leakage readings.  Used for system validity checking.
    uint8_t     mma_not_active;
    uint8_t     good_normal_cores_per_sort;

    /// Good Normal Cores Per EQs (otherwise known as Octants)
    /// EQs 01, EQs 23, EQs 45, EQs 67
    uint8_t     good_normal_cores_per_EQs[MAXIMUM_EQ_SETS];

    /// Leakage splits by region by rail
    uint8_t    iddq_all_cores_off_all_caches_off_core_pct;
    uint8_t    iddq_all_cores_off_all_caches_off_cache_pct;
    uint8_t    iddq_all_cores_off_all_caches_off_racetrack_pct;
    uint8_t    icsq_all_cores_off_all_caches_off_core_pct;
    uint8_t    icsq_all_cores_off_all_caches_off_cache_pct;
    uint8_t    icsq_all_cores_off_all_caches_off_racetrack_pct;

    uint8_t    mma_off_leakage_pct;

    uint8_t     spare0[18];

    iddq_entry_t iddq_all_good_cores_on_caches_on_5ma[IDDQ_MEASUREMENTS];
    iddq_entry_t iddq_all_good_cores_off_good_caches_off_5ma[IDDQ_MEASUREMENTS];
    iddq_entry_t iddq_all_good_cores_off_good_caches_on_5ma[IDDQ_MEASUREMENTS];
    iddq_entry_t iddq_eqs_good_cores_on_good_caches_on_5ma[MAXIMUM_EQ_SETS][IDDQ_MEASUREMENTS];

    iddq_entry_t icsq_all_good_cores_on_caches_on_5ma[IDDQ_MEASUREMENTS];
    iddq_entry_t icsq_all_good_cores_off_good_caches_off_5ma[IDDQ_MEASUREMENTS];
    iddq_entry_t icsq_all_good_cores_off_good_caches_on_5ma[IDDQ_MEASUREMENTS];
    iddq_entry_t icsq_eqs_good_cores_on_good_caches_on_5ma[MAXIMUM_EQ_SETS][IDDQ_MEASUREMENTS];


    /// Temperatures of IDDQ measurements in 0.5C units
    avgtemp_entry_t avgtemp_all_cores_on_good_caches_on_p5c[IDDQ_MEASUREMENTS];
    avgtemp_entry_t avgtemp_all_cores_off_caches_off_p5c[IDDQ_MEASUREMENTS];
    avgtemp_entry_t avgtemp_all_good_cores_off_good_caches_on_p5c[IDDQ_MEASUREMENTS];

    /// spare (per MVPD documentation)
    uint8_t spare_1[36];
} IddqTable_t;

/// Pstate Parameters consumed by the OCC
///
/// The layout of the data created by the Pstate table creation firmware for
/// comsumption by the OCC firmware.  This data will reside in the Quad
/// Power Management Region (QPMR).
///
/// This structure is aligned to 128B to allow for easy downloading using the
/// OCC block copy engine
///
typedef struct
{

    union
    {
        uint64_t        value;
        struct
        {
            unit64_t    eye_catcher : 56;
            uint64_t    version     : 8 ;

        } fields;
    } magic;

    Attributes_t        attr;

    /// VPD operating points are biased but without load-line correction.
    /// Frequencies are in MHz, voltages are specified in units of 1mV, currents
    /// are specified in units of 10mA, and temperatures are specified in 0.5
    /// degrees C.
    VpdOperatingPoint_t operating_points[NUM_OP_POINTS];

    SysPowerDistParms_t vdd_sysparm;
    SysPowerDistParms_t vdn_sysparm;
    SysPowerDistParms_t vcs_sysparm;

    IddqTable_t         iddq;

    uint32_t            frequency_min_khz;
    uint32_t            frequency_max_khz;    // Frequency of Pstate0
    uint32_t            frequency_step_khz;
    uint32_t            pstate_min;           // Pstate reflecting frequency_min_khz
    uint32_t            occ_complex_frequency_mhz;

} OCCPstateParmBlock_t __attribute__((aligned(128))) ;

#ifdef __cplusplus
} // end extern C
#endif
#endif    /* __ASSEMBLER__ */
#endif    /* __PSTATES_OCC_H__ */
