/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstate_tables.h $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __PSTATE_TABLES_H__
#define __PSTATE_TABLES_H__

// $Id: pstate_tables.h,v 1.6 2013/05/02 17:33:31 jimyac Exp $

/// \file pstate_tables.h 
/// \brief Code used to generate Pstate tables from real or imagined chip
/// characterizations. 

#include "pstates.h"

// Constants associated with VRM stepping

#define PSTATE_STEPSIZE_MAX        127
#define VRM_STEPDELAY_RANGE_BITS   4
#define LOG2_VRM_STEPDELAY_DIVIDER 3
#define VRM_STEPDELAY_MAX          1600000


#ifndef __ASSEMBLER__

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
            const uint8_t dead_zone_5mv);


#endif // __ASSEMBLER__

#endif // __PSTATE_TABLES_H__
