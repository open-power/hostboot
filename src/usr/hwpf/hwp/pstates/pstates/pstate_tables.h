/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstate_tables.h $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
/* [+] International Business Machines Corp.                              */
/* [+] Google Inc.                                                        */
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
#ifndef __PSTATE_TABLES_H__
#define __PSTATE_TABLES_H__

// $Id: pstate_tables.h,v 1.10 2014/07/03 02:57:52 daviddu Exp $

/// \file pstate_tables.h 
/// \brief Code used to generate Pstate tables from real or imagined chip
/// characterizations. 

#include <pstates.h>

// Constants associated with VRM stepping

#define PSTATE_STEPSIZE_MAX        127
#define VRM_STEPDELAY_RANGE_BITS   4
#define LOG2_VRM_STEPDELAY_DIVIDER 3
#define VRM_STEPDELAY_MAX          1600000


#ifndef __ASSEMBLER__

#ifdef __cplusplus
extern "C" {
#endif

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


/// An internal operating point
///
/// Internal operating points include characterization and load-line corrected
/// voltages for the external VRM.  For the internal VRM, effective e-voltages
/// and maxreg voltages are stored.  All voltages are stored as
/// uV. Characterization currents are in mA. Frequencies are in KHz. The
/// Pstate of the operating point (as a potentially out-of-bounds value) is
/// also stored.

typedef struct {

    uint32_t vdd_uv;
    uint32_t vcs_uv;
    uint32_t vdd_corrected_uv;
    uint32_t vcs_corrected_uv;
    uint32_t vdd_ivrm_effective_uv;
    uint32_t vcs_ivrm_effective_uv;
    uint32_t vdd_maxreg_uv;
    uint32_t vcs_maxreg_uv;
    uint32_t idd_ma;
    uint32_t ics_ma;
    uint32_t frequency_khz;
    int32_t  pstate;

} OperatingPoint;


/// Constants required to compute and interpolate operating points
///
/// The nominal frequency and frequency step-size is given in Hz. Load-line
/// and on-chip distribution resistances are given in micro-Ohms.
///
/// \todo Confirm that the "eVID V[dd,cs] Eff" correction is modeled as a simple
/// resistance similar to the load line.

typedef struct {

    uint32_t pstate0_frequency_khz;
    uint32_t frequency_step_khz;
    uint32_t vdd_load_line_uohm;
    uint32_t vcs_load_line_uohm;
    uint32_t vdd_distribution_uohm;
    uint32_t vcs_distribution_uohm;
    uint32_t vdd_voffset_uv;
    uint32_t vcs_voffset_uv;
} OperatingPointParameters;


/// A chip characterization

typedef struct {

    VpdOperatingPoint *vpd;
    OperatingPoint *ops;
    OperatingPointParameters *parameters;
    int points;

} ChipCharacterization;


uint16_t
revle16(uint16_t i_x);

uint32_t
revle32(uint32_t x);

uint64_t
revle64(const uint64_t i_x);

int
chip_characterization_create(ChipCharacterization *characterization,
                 VpdOperatingPoint *vpd,
                 OperatingPoint *ops,
                 OperatingPointParameters *parameters,
                 int points);

int
gpst_create(GlobalPstateTable *gpst,
        ChipCharacterization *characterization,
            int pstate_stepsize,
            int evrm_delay_ns);
            

int
lpst_create(const GlobalPstateTable *gpst,
            LocalPstateArray *lpsa, 
            const uint8_t dead_zone_5mv,
            double volt_int_vdd_bias, 
            double volt_int_vcs_bias,            
            uint8_t *vid_incr_gt7_nonreg);            

typedef struct IVRM_PARM_DATA {
    uint32_t vin_min;                   // Minimum input voltage
    uint32_t vin_max;                   // Maximum input voltage
    uint32_t vin_table_step_size;       // Granularity of Vin table entries
    uint32_t vin_table_setsperrow;      // Vin sets per Vds row
    uint32_t vin_table_pfetstrperset;   // PFET Strength values per Vin set    
    uint32_t vout_min;                  // Minimum regulated output voltage
    uint32_t vout_max;                  // Maximum regulated output voltage
    uint32_t vin_entries_per_vds;       // Vin array entries per vds region
    uint32_t vds_min_range_upper_bound; // Starting point for vds regions
    uint32_t vds_step_percent;          // vds region step muliplier
    uint32_t vds_region_entries;        // vds region array entries (in hardware)
    uint32_t pfetstr_default;           // Default PFET Strength with no calibration
    uint32_t positive_guardband;        // Plus side guardband (%)
    uint32_t negative_guardband;        // Negative side guardband (%)
    uint32_t number_of_coefficients;    // Number of coefficents in cal data
    uint32_t force_pfetstr_values;      // 0 - calculated; 1 = forced
    uint32_t forced_pfetstr_value;      // If force_pfetstr_values = 1, use this value
                                        // 5b value used as it to fill in all entries
} ivrm_parm_data_t;

void
build_vds_region_table(ivrm_parm_data_t* i_ivrm_parms,
                       PstateSuperStructure* pss);
  
  
void  
fill_vin_table(ivrm_parm_data_t* i_ivrm_parms,
               PstateSuperStructure* pss);


void fit_file(int n, 
               uint8_t version, 
               double C[], 
               ivrm_cal_data_t* cal_data);
               
void write_HWtab_bin(ivrm_parm_data_t* i_ivrm_parms,
                      double C[],
                      PstateSuperStructure*   pss);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif // __ASSEMBLER__

#endif // __PSTATE_TABLES_H__
