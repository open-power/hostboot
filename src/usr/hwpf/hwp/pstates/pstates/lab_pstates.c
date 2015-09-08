/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/lab_pstates.c $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: lab_pstates.c,v 1.12 2015/06/01 19:02:17 stillgs Exp $

/// \file lab_pstates.c
/// \brief Lab-only (as opposed to product-procedure) support for Pstates.
///
/// Lab-only Pstate support is separated from generic Pstate support to reduce
/// the size of OCC product firmware images.

#ifdef __cplusplus
extern "C" {
#endif

#include "ssx.h"
// jwy #include "ppc32.h"
#include "lab_pstates.h"
// jwy #include "pmc_register_addresses.h"
// jwy #include "pmc_firmware_registers.h"
// jwy #include "pcbs_register_addresses.h"
// jwy #include "pcbs_firmware_registers.h"

/// Convert a voltage in microvolts to a VRM-11 VID code, rounding the implied
/// voltage as required.
///
/// \param v_uv Voltage in micro-volts
///
/// \param round \a round >= 0 indicate round voltage up, while \a round < 0
/// implies round voltage down
///
/// \param vrm11_vid A pointer to the location of the final VID code. This
/// location is updated even if the final VID code is invalid.
///
/// \bug Confirm if the 1.6125V offset is still valid for PgP

// Recall that VRM11 is inverted; rounding a VID code up rounds down the
// voltage.

int
vuv2vrm11(uint32_t v_uv, int round, uint8_t *vrm11_vid)
{
    int32_t offset, vid;

    offset = VRM11_BASE_UV - v_uv;
    vid = offset / VRM11_STEP_UV;

    if (((offset % VRM11_STEP_UV) != 0) && (round < 0)) {
        vid++;
    }

    *vrm11_vid = vid;
    return vid11_validate(vid);
}


/// Convert a VRM-11 VID code to a voltage in microvolts

int
vrm112vuv(uint8_t vrm11_vid, uint32_t *v_uv)
{
    *v_uv= VRM11_BASE_UV - (vrm11_vid * VRM11_STEP_UV);
    return vid11_validate(vrm11_vid);
}


/// Convert a voltage in microvolts to an internal VID code, rounding the
/// implied voltage as required.
///
/// \param v_uv Voltage in micro-volts
///
/// \param round \a round >= 0 indicate round voltage up, while \a round < 0
/// implies round voltage down
///
/// \param ivid A pointer to the location of the final VID code.  This
/// location is updated even the event of errors.
///
/// \retval 0 Success
///
/// \retval -IVID_INVALID_VOLTAGE If \a v_uv can not be converted to a legal
/// IVID encoding.

int
vuv2ivid(uint32_t v_uv, int round, uint8_t *ivid)
{
    int rc;
    int32_t offset, vid;

    offset = v_uv - IVID_BASE_UV;
    vid = offset / IVID_STEP_UV;

    if (((offset % IVID_STEP_UV) != 0) && (round >= 0)) {
	    vid++;
    }

    *ivid = vid;
    if ((vid < 0) || (vid > 0x7f)) {
        rc = -IVID_INVALID_VOLTAGE;
    } else {
        rc = 0;
    }
    return rc;
}

/// Convert an iVID code to a voltage in microvolts

int
ivid2vuv(uint8_t ivid, uint32_t *v_uv)
{
    if (ivid > 0x7f) {
    return -IVID_INVALID_VOLTAGE;
    } else {
    *v_uv= IVID_BASE_UV + (ivid * IVID_STEP_UV);
    return 0;
    }
}

/// Convert a VPD current (in 0.5A units) to milliamps

int
vpdcur2ima(uint16_t i_vpdcur, uint32_t *i_ma)
{
    *i_ma = (i_vpdcur * 1000 / 2);
    return 0;
}

/// Format a voltage in microvolts as 10 microvolts into a user-supplied
/// string..  The string \a s must be able to store at least
/// FORMAT_10UV_STRLEN characters.

int
sprintf_10uv(char *s, uint32_t v_uv)
{
    return sprintf(s, "%d.%05d", v_uv / 1000000, (v_uv % 1000000) / 10);
}

/// Format a current in milliamps into a user-supplied
/// string..  The string \a s must be able to store at least
/// FORMAT_IMA_STRLEN characters.

int
sprintf_ima(char *s, uint32_t i_ma)
{
    return sprintf(s, "%d.%03d", i_ma / 1000, i_ma % 1000);
}


#ifdef FAPIECMD

/// Format a voltage in microvolts as 10 microvolts to a stream.

int
fprintf_10uv(FILE *stream, uint32_t v_uv)
{
    int rc;
    char s[FORMAT_10UV_STRLEN];

    rc = sprintf_10uv(s, v_uv);
    if (rc > 0) {
    rc = fputs(s, stream);
    }
    return rc;
}


/// Format a VRM-11 VID code as 10 microvolts into a user-supplied string. The
/// string \a s must be able to store at least FORMAT_10UV_STRLEN characters.

int
sprintf_vrm11(char *s, uint8_t vrm11)
{
    int rc;
    uint32_t v_uv;

    if ((rc = vrm112vuv(vrm11, &v_uv)) != 0) {
        strcpy(s, FORMAT_10UV_ERROR);
    } else {
        rc = sprintf_10uv(s, v_uv);
    }
    return rc;
}


/// Format a VRM-11 VID code as 10 microvolts to a stream.

int
fprintf_vrm11(FILE *stream, uint8_t vrm11)
{
    int rc;
    char s[FORMAT_10UV_STRLEN];

    rc = sprintf_vrm11(s, vrm11);
    if (rc > 0) {
    rc = fputs(s, stream);
    }
    return rc;
}


/// Format an IVID code as 10 microvolts into a user-supplied string. The
/// string \a s must be able to store at least FORMAT_10UV_STRLEN characters.

int
sprintf_ivid(char *s, uint8_t ivid)
{
    int rc;
    uint32_t v_uv;

    if ((rc = ivid2vuv(ivid, &v_uv)) != 0) {
    return rc;
    }
    return sprintf_10uv(s, v_uv);
}


/// Format an iVID code as 10 microvolts to a stream.

int
fprintf_ivid(FILE *stream, uint8_t ivid)
{
    int rc;
    char s[FORMAT_10UV_STRLEN];

    rc = sprintf_ivid(s, ivid);
    if (rc > 0) {
    rc = fputs(s, stream);
    }
    return rc;
}

/// Format a VPD current code as .5A into a user-supplied string. The
/// string \a s must be able to store at least FORMAT_0P5A_STRLEN characters.

int
sprintf_vpd_current(char *s,  uint16_t current)
{
    int rc;
    uint32_t i_ma;

    if ((rc = vpdcur2ima(current, &i_ma)) != 0) {
    return rc;
    }
    return sprintf_ima(s, i_ma);
}


int
fprintf_vpd_current(FILE *stream, uint16_t current)
{
    int rc;
    char s[FORMAT_IMA_STRLEN];

    rc = sprintf_vpd_current(s, current);
    if (rc > 0) {
    rc = fputs(s, stream);
    }
    return rc;
}



// NB: The gpst_print() routine only needs the revle* functions when compiled
// into little-endian Linux applications, which must provide their
// implementations.

#ifdef _BIG_ENDIAN

#define revle16(x) x
#define revle32(x) x
#define revle64(x) x

#else

uint16_t revle16(uint16_t i_x);
uint32_t revle32(uint32_t i_x);
uint64_t revle64(uint64_t i_x);

#endif


/// Print a GlobalPstateTable structure on a given stream
///
/// \param stream The output stream
///
/// \param gpst The Global Pstate Table to print

void
gpst_print(FILE *stream, GlobalPstateTable *gpst)
{
    // Endian-corrected scalar Pstate fields

    uint32_t options;
    uint32_t pstate0_frequency_khz, frequency_step_khz;
    uint8_t entries, pstate_stepsize, vrm_stepdelay_range, vrm_stepdelay_value;
//    Pstate pmin, pvsafe, psafe;
    Pstate pvsafe, psafe;


    // Endian-corrected vector Pstate fields

    gpst_entry_t entry;

    // Other local variables

    int i;
    uint8_t evid_vdd, evid_vcs, evid_vdd_eff, evid_vcs_eff,
    maxreg_vdd, maxreg_vcs;
    int8_t pstate;
    char evid_vdd_str[FORMAT_10UV_STRLEN];
    char evid_vcs_str[FORMAT_10UV_STRLEN];
    char evid_vdd_eff_str[FORMAT_10UV_STRLEN];
    char evid_vcs_eff_str[FORMAT_10UV_STRLEN];
    char maxreg_vdd_str[FORMAT_10UV_STRLEN];
    char maxreg_vcs_str[FORMAT_10UV_STRLEN];
    char* ivrm_max_ps_str;
    char* ultraturbo_ps_str;
    char* turbo_ps_str;
    char* nominal_ps_str; 
    char* powersave_ps_str;

    
    // Get endian-corrected scalars

    options = revle32(gpst->options.options);
    pstate0_frequency_khz = revle32(gpst->pstate0_frequency_khz);
    frequency_step_khz = revle32(gpst->frequency_step_khz);
    entries = gpst->entries;
    pstate_stepsize = gpst->pstate_stepsize;
    vrm_stepdelay_range = gpst->vrm_stepdelay_range;
    vrm_stepdelay_value = gpst->vrm_stepdelay_value;
//    pmin = gpst->pmin;
    pvsafe = gpst->pvsafe;
    psafe = gpst->psafe;


    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "Global Pstate Table @ %p\n", gpst);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "%d Entries from %+d to %+d\n",
        entries, gpst_pmin(gpst), gpst_pmax(gpst));
    fprintf(stream, "Frequency Step = %u KHz\n", frequency_step_khz);
    fprintf(stream, "Pstate 0 Frequency = %u KHz\n", pstate0_frequency_khz);
    fprintf(stream, "Pstate 0 Frequency Code (per core) :");
    for (i = 0; i < PGP_NCORES; i++) {
        if ((i != 0) && ((i % 4) == 0)) {
            fprintf(stream, "\n                                    ");
        }
        fprintf(stream, " 0x%03x", revle16(gpst->pstate0_frequency_code[i]));
    }
    fprintf(stream, "\n");
    fprintf(stream, "DPLL Fmax Bias (per core)          :");
    for (i = 0; i < PGP_NCORES; i++) {
        fprintf(stream, " %d", gpst->dpll_fmax_bias[i]);
    }
    fprintf(stream, "\n");
    fprintf(stream, "Pstate Step Size %u, VRM Range %u, VRM Delay %u\n",
            pstate_stepsize, vrm_stepdelay_range, vrm_stepdelay_value);
    fprintf(stream, "Pvsafe %d, Psafe %d\n", pvsafe, psafe);
    
    fprintf(stream, "iVRM Maximum Pstate %d, Number of GPST entries (from Psafe) where iVRMs are enabled: %d\n", 
            gpst->ivrm_max_ps, gpst->ivrm_entries);
    

    if (options == 0) {
        fprintf(stream, "No Options\n");
    } else {
        fprintf(stream, "Options 0x%08x:\n", options);
        if (options & PSTATE_NO_COPY_GPST) {
            fprintf(stream, "    PSTATE_NO_COPY_GPST\n");
        }
        if (options & PSTATE_NO_INSTALL_GPST) {
            fprintf(stream, "    PSTATE_NO_INSTALL_GPST\n");
        }
        if (options & PSTATE_NO_INSTALL_LPSA) {
            fprintf(stream, "    PSTATE_NO_INSTALL_LPSA\n");
        }
        if (options & PSTATE_NO_INSTALL_RESCLK) {
            fprintf(stream, "    PSTATE_NO_INSTALL_RESCLK\n");
        }
        if (options & PSTATE_FORCE_INITIAL_PMIN) {
            fprintf(stream, "    PSTATE_FORCE_INITIAL_PMIN\n");
        }
        if (options & PSTATE_IDDQ_0P80V_VALID) {
            fprintf(stream, "    PSTATE_IDDQ_0P80V_VALID\n");
        }
    }
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream,
        "  I Pstate F(MHz) evid_vdd(V)  evid_vcs(V) evid_vdd_eff(V) evid_vcs_eff(V) maxreg_vdd(V)  maxreg_vcs(V)\n"
        "---------------------------------------------------------------------------------------------------------\n");

    for (i = gpst->entries - 1; i >= 0; i--) {

        entry.value = revle64(gpst->pstate[i].value);

    evid_vdd = entry.fields.evid_vdd;
    sprintf_vrm11(evid_vdd_str, evid_vdd);

    evid_vcs = entry.fields.evid_vcs;
    sprintf_vrm11(evid_vcs_str, evid_vcs);

    evid_vdd_eff = entry.fields.evid_vdd_eff;
    sprintf_ivid(evid_vdd_eff_str, evid_vdd_eff);

    evid_vcs_eff = entry.fields.evid_vcs_eff;
    sprintf_ivid(evid_vcs_eff_str, evid_vcs_eff);

    maxreg_vdd = entry.fields.maxreg_vdd;
    sprintf_ivid(maxreg_vdd_str, maxreg_vdd);

    maxreg_vcs = entry.fields.maxreg_vcs;
    sprintf_ivid(maxreg_vcs_str, maxreg_vcs);

    pstate = gpst_pmin(gpst) + i;
    
    ultraturbo_ps_str = "";
    if (pstate == 0 && gpst->turbo_ps != 0)
        ultraturbo_ps_str = " <--- UltraTurbo";
    
    turbo_ps_str = "";
    if (pstate == gpst->turbo_ps)
        turbo_ps_str = " <--- Turbo";
    
    nominal_ps_str = "";
    if (pstate == gpst->nominal_ps)
        nominal_ps_str = " <--- Nominal";   
        
    powersave_ps_str = "";
    if (pstate == gpst->powersave_ps)
        powersave_ps_str = " <--- PowerSave";   
    
    ivrm_max_ps_str = "";
    if (pstate == gpst->ivrm_max_ps)
        ivrm_max_ps_str = " <--- iVRM Maximum";
       
    fprintf(stream,
        "%3d %+4d    "
        "%4d  "
        "0x%02x %s  "
        "0x%02x %s  "
        "0x%02x %s    "
        "0x%02x %s   "
        "0x%02x %s   "
        "0x%02x %s "
        "%s%s%s%s%s\n",
        i, pstate,
        (pstate0_frequency_khz + (frequency_step_khz * pstate)) / 1000,
        evid_vdd, evid_vdd_str,
        evid_vcs, evid_vcs_str,
        evid_vdd_eff, evid_vdd_eff_str,
        evid_vcs_eff, evid_vcs_eff_str,
        maxreg_vdd, maxreg_vdd_str,
        maxreg_vcs, maxreg_vcs_str,
        ultraturbo_ps_str,
        turbo_ps_str,
        nominal_ps_str,
        powersave_ps_str,
        ivrm_max_ps_str);
    }
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
}


/// Print a LocalPstateArray structure on a given stream
///
/// \param stream The output stream
///
/// \param lpsa The Local Pstate Array to print
///
/// \todo Replace the hex dump with a decoded Local Pstate Table + ivrm table

void
lpsa_print(FILE* stream, LocalPstateArray* lpsa)
{
    int i;
    uint8_t entries;
    uint8_t entries_div4;
    char ivid_vdd_str[FORMAT_10UV_STRLEN];
    char ivid_vcs_str[FORMAT_10UV_STRLEN];
    uint8_t ivid_vdd, ivid_vcs;
    lpst_entry_t   lpst_entry;
    vdsvin_entry_t vdsvin_entry;

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "Local Pstate Array @ %p\n", lpsa);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "%d Entries from %+d to %+d\n",
        lpsa->entries, lpst_pmin(lpsa), lpst_pmax(lpsa));
    fprintf(stream, "Step Delay Rising %u, Step Delay Falling %u\n",
            lpsa->stepdelay_rising,
            lpsa->stepdelay_lowering);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------------------\n");
    fprintf(stream,
        " I  ivid_vdd(V)   ivid_vcs(V)   Core vdd  Core vcs  ECO vdd   ECO vcs   ps1 inc  ps2 inc  ps3 inc  inc step  dec step\n"
        "                                pwrratio  pwrratio  pwrratio  pwrratio                                               \n"
        "---------------------------------------------------------------------------------------------------------------------\n");

    entries      = lpsa->entries;
    entries_div4 = entries/4;

    if ( entries % 4 != 0)
       entries_div4++;

    for (i = entries_div4-1  ; i >= 0; i--) {
      lpst_entry.value = revle64(lpsa->pstate[i].value);

      ivid_vdd = lpst_entry.fields.ivid_vdd;
      sprintf_ivid(ivid_vdd_str, ivid_vdd);

      ivid_vcs = lpst_entry.fields.ivid_vcs;
      sprintf_ivid(ivid_vcs_str, ivid_vcs);

      fprintf(stream,
           "%2u  "
           "0x%02x %s  "
           "0x%02x %s  "
           "%-9u %-9u %-9u %-9u "
           "%-8u %-8u %-8u "
           "%-9u %-9u \n",
           i,
           ivid_vdd, ivid_vdd_str,
           ivid_vcs, ivid_vcs_str,
           (uint8_t)lpst_entry.fields.vdd_core_pwrratio,
           (uint8_t)lpst_entry.fields.vcs_core_pwrratio,
           (uint8_t)lpst_entry.fields.vdd_eco_pwrratio,
           (uint8_t)lpst_entry.fields.vcs_eco_pwrratio,
           (uint8_t)lpst_entry.fields.ps1_vid_incr,
           (uint8_t)lpst_entry.fields.ps2_vid_incr,
           (uint8_t)lpst_entry.fields.ps3_vid_incr,
           (uint8_t)lpst_entry.fields.inc_step,
           (uint8_t)lpst_entry.fields.dec_step);
    }

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------------------\n\n");

   fprintf(stream,
        "--------------------------------\n");
   fprintf(stream,
        "VDS\n");
    fprintf(stream,
        " I    beg_offset  end_offset    \n"
        "--------------------------------\n");

    for (i = 15  ; i >= 0; i--) {
      vdsvin_entry.value = revle64(lpsa->vdsvin[i].value);

      fprintf(stream,
           "%2u    "
           "%-10u  "
           "%-10u   \n",
           i,
           (uint8_t)vdsvin_entry.fields.ivid0,
           (uint8_t)vdsvin_entry.fields.ivid1);
    }

    fprintf(stream,
        "--------------------------------\n\n");


   fprintf(stream,
        "-----------------------------------------------------\n");
   fprintf(stream,
        "VIN\n");
    fprintf(stream,
        " I    ptef0 pfet1 pfet2 pfet3 pfet4 pfet5 pfet6 pfet7\n"
        "-----------------------------------------------------\n");

    for (i = 63  ; i >= 0; i--) {
      vdsvin_entry.value = revle64(lpsa->vdsvin[i].value);

      fprintf(stream,
           "%2u    "
           "%-5u %-5u %-5u %-5u %-5u %-5u %-5u %-5u\n",
           i,
           (uint8_t)vdsvin_entry.fields.pfet0,
           (uint8_t)vdsvin_entry.fields.pfet1,
           (uint8_t)vdsvin_entry.fields.pfet2,
           (uint8_t)vdsvin_entry.fields.pfet3,
           (uint8_t)vdsvin_entry.fields.pfet4,
           (uint8_t)vdsvin_entry.fields.pfet5,
           (uint8_t)vdsvin_entry.fields.pfet6,
           (uint8_t)vdsvin_entry.fields.pfet7);
    }

    fprintf(stream,
        "-----------------------------------------------------\n\n");
}

/// Print CPM Pstate Range structure on a given stream
///
/// \param stream   The output stream
///
/// \param cpmrange The CPM Pstate Range structure to print

void
cpmrange_print(FILE* stream, CpmPstateModeRanges* cpmrange)
{
    int i;

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "CPM Pstate Range @ %p\n",  cpmrange);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");

    fprintf(stream, "Valid Number of CPM Pstate Ranges : %u\n",
            cpmrange->validRanges);

    for (i = 0; i < 8; i++) {
      fprintf(stream, "   CPM Range %d Pstate : %d\n",
              i, cpmrange->inflectionPoint[i]);
    }

    fprintf(stream, "  CPM Pmax : %d\n",
            cpmrange->pMax);

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
}

/// Print a Resonant Clocking Setup structure on a given stream
///
/// \param stream The output stream
///
/// \param resclk The ResonantClockingSetup to print

void
resclk_print(FILE* stream, ResonantClockingSetup* resclk)
{
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "Resonant Clocking Setup @ %p\n", resclk);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");

    fprintf(stream, "   Full Clock Sector Buffer Pstate      : %2d\n",
            resclk->full_csb_ps);
    fprintf(stream, "   Low Frequency Resonant Lower Pstate  : %2d\n",
            resclk->res_low_lower_ps);
    fprintf(stream, "   Low Frequency Resonant Upper Pstate  : %2d\n",
            resclk->res_low_upper_ps);
    fprintf(stream, "   High Frequency Resonant Lower Pstate : %2d\n",
            resclk->res_high_lower_ps);
    fprintf(stream, "   High Frequency Resonant Upper Pstate : %2d\n",
            resclk->res_high_upper_ps);

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
}

/// Print an IDDQ structure on a given stream
///
/// \param stream The output stream
///
/// \param iddq The IddqTable to print

void
iddq_print(FILE* stream, IddqTable* iddq)
{
    uint32_t i, j;
    const uint8_t   vdd_measurement_order[LRP_IDDQ_RECORDS] = CORE_IDDQ_MEASUREMENTS_ORDER;
    const char     *core_measurement_str[LRP_IDDQ_RECORDS] = CORE_IDDQ_MEASUREMENT_VOLTAGES;
    const uint8_t   vcs_measurement_order[LRP_IDDQ_RECORDS] = CORE_IDDQ_MEASUREMENTS_ORDER;
    const char     *chip_measurement_str[CRP_IDDQ_RECORDS] = CHIP_IDDQ_MEASUREMENT_VOLTAGES;
    const uint8_t   vio_measurement_order[CRP_IDDQ_RECORDS] = CHIP_IDDQ_MEASUREMENTS_ORDER;


    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "IDDQ Table (version %d) @ %p\n", iddq->iddq_version, iddq);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");


    for (i = 0; i < CORE_IDDQ_MEASUREMENTS; i++) {
        for (j = 0; j < CORE_IDDQ_MEASUREMENTS; j++) {
            if (vdd_measurement_order[j] == i)
                fprintf(stream, "   Core VDD IDDQ @ %sV Raw : 0x%04X, %6d mA; Temperature Corrected: 0x%04X, %6d mA\n",
                  core_measurement_str[j],
                  iddq->iddq_vdd[vdd_measurement_order[j]].fields.iddq_raw_value,
                  iddq->iddq_vdd[vdd_measurement_order[j]].fields.iddq_raw_value*10,
                  iddq->iddq_vdd[vdd_measurement_order[j]].fields.iddq_corrected_value,
                  iddq->iddq_vdd[vdd_measurement_order[j]].fields.iddq_corrected_value*10);
        }
    }

    for (i = 0; i < CORE_IDDQ_MEASUREMENTS; i++) {
        for (j = 0; j < CORE_IDDQ_MEASUREMENTS; j++) {
            if (vcs_measurement_order[j] == i)
                fprintf(stream, "   Core VCS IDDQ @ %sV Raw : 0x%04X, %6d mA; Temperature Corrected: 0x%04X, %6d mA\n",
                  core_measurement_str[j],
                  iddq->iddq_vcs[vcs_measurement_order[j]].fields.iddq_raw_value,
                  iddq->iddq_vcs[vcs_measurement_order[j]].fields.iddq_raw_value*10,
                  iddq->iddq_vcs[vcs_measurement_order[j]].fields.iddq_corrected_value,
                  iddq->iddq_vcs[vcs_measurement_order[j]].fields.iddq_corrected_value*10);
        }
    }

    for (i = 0; i < CHIP_IDDQ_MEASUREMENTS; i++) {
        for (j = 0; j < CHIP_IDDQ_MEASUREMENTS; j++) {
            if (vio_measurement_order[j] == i)
                fprintf(stream, "   Chip VIO IDDQ @ %sV Raw : 0x%04X, %6d mA; Temperature Corrected: 0x%04X, %6d mA\n",
                  chip_measurement_str[j],
                  iddq->iddq_vio[vio_measurement_order[j]].fields.iddq_raw_value,
                  iddq->iddq_vio[vio_measurement_order[j]].fields.iddq_raw_value*10,
                  iddq->iddq_vio[vio_measurement_order[j]].fields.iddq_corrected_value,
                  iddq->iddq_vio[vio_measurement_order[j]].fields.iddq_corrected_value*10);
        }
    }

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
}

// ENUM defining the printable rails
enum vidmod_rails
{
    VDD,
    VCS
};

/// Print the VID Modification structure on a given stream
///
/// \param stream   The output stream
/// \param wof      The WOF Element structure to print
/// \param rail     The rail to put out
void
vidmod_print(FILE* stream, WOFElements* wof, vidmod_rails rail)
{
    char line_str[256];
    char entry_str[128];
    
    uint8_t evid;
    char evid_str[FORMAT_10UV_STRLEN];
    
    strcpy(entry_str, "");
    strcpy(line_str, "   Active Cores->");
    for (int j=0; j < wof->ut_vid_mod.ut_max_cores; ++j) 
    {
        sprintf(entry_str, "      %2d      ", j+1);
        strcat(line_str, entry_str);  
    }    
    fprintf(stream, "%s\n", line_str);   
       
    strcpy(entry_str, "");
    strcpy(line_str, "    Index Pstate  ");
    for (int j=0; j < wof->ut_vid_mod.ut_max_cores; ++j) 
    {
        if (rail == VDD) 
            sprintf(entry_str, " evid_vdd(V)  ");
        else
            sprintf(entry_str, " evid_vcs(V)  ");
        strcat(line_str, entry_str);  
    }    
    fprintf(stream, "%s\n", line_str);
    
    for (int i = wof->ut_vid_mod.ut_segment_pstates; i >= 0; --i) 
    {      
    
        sprintf(line_str, "    %2d    %+4d    ",                          
                        i,
                        -wof->ut_vid_mod.ut_segment_pstates+i);

        for (int j=0; j < wof->ut_vid_mod.ut_max_cores; ++j) 
        {
            if (rail == VDD) 
                evid = wof->ut_vid_mod.ut_segment_vdd_vid[i][j];
            else
                evid = wof->ut_vid_mod.ut_segment_vcs_vid[i][j];                        
            
            sprintf_vrm11(evid_str, evid);
            strcpy(entry_str, "");
            sprintf(entry_str, "0x%02x %s  ",                          
                        evid, evid_str);
            strcat(line_str, entry_str);                        

        } 
        fprintf(stream, "%s\n", line_str);    
    }
    return;
}

/// Print the WOF Element structure on a given stream
///
/// \param stream The output stream
///
/// \param wof The WOF Element structure to print

void
wof_print(FILE* stream, WOFElements* wof)
{
    const char     *vpd_point_str[VPD_PV_POINTS] = VPD_PV_ORDER_STR;
    
    char vpd_vdd_str[FORMAT_10UV_STRLEN];
    char vpd_vcs_str[FORMAT_10UV_STRLEN];
    char vpd_idd_str[FORMAT_IMA_STRLEN];
    char vpd_ics_str[FORMAT_IMA_STRLEN];
        
    uint32_t vdd, vcs, idd, ics;

    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "Workload Optimized Frequency (WOF) elements @ %p\n", wof);
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
 
    fprintf(stream, "WOF Enabled\t: %d\n", wof->wof_enabled);
    
    if (!wof->wof_enabled)
    {
         fprintf(stream, "  >>>> With WOF Disabled, relevant content in the Pstate SuperStructure is not populated <<<<\n");
    }

    fprintf(stream, "VPD Points (biased without System Distribution Elements)\n"); 
    for (int i=0; i < VPD_PV_POINTS; ++i) 
    {

        vdd = wof->operating_points[i].vdd_5mv * 5 * 1000;
        sprintf_10uv(vpd_vdd_str, vdd);

        vcs = wof->operating_points[i].vcs_5mv * 5 * 1000;
        sprintf_10uv(vpd_vcs_str, vcs);

        idd = wof->operating_points[i].idd_500ma;
        sprintf_vpd_current(vpd_idd_str, idd);

        ics = wof->operating_points[i].ics_500ma;
        sprintf_vpd_current(vpd_ics_str, ics);

        fprintf(stream, "   %s         \t: %4d MHz  VDD: %s V %s A  VCS: %s V %s A\n",
            vpd_point_str[i],
            wof->operating_points[i].frequency_mhz,
            vpd_vdd_str,
            vpd_idd_str,
            vpd_vcs_str,
            vpd_ics_str           
            );           
    }

    fprintf(stream, "System Distribution Elements\n"); 
    fprintf(stream, "   VDD loadline            : %d uOhm\n", wof->vdd_sysparm.loadline_uohm);
    fprintf(stream, "   VCS loadline            : %d uOhm\n", wof->vcs_sysparm.loadline_uohm);
    fprintf(stream, "   VDD distribution loss   : %d uOhm\n", wof->vdd_sysparm.distloss_uohm);
    fprintf(stream, "   VCS distribution loss   : %d uOhm\n", wof->vcs_sysparm.distloss_uohm);
    fprintf(stream, "   VDD distribution offset : %d uV\n",   wof->vdd_sysparm.distoffset_uv);
    fprintf(stream, "   VCS distribution offset : %d uV\n",   wof->vcs_sysparm.distoffset_uv);

    fprintf(stream, "WOF Factors\n"); 
    fprintf(stream, "   TDP to RDP factor        0x%X   --> %0.2f%% \n", wof->tdp_rdp_factor, (double)wof->tdp_rdp_factor/100);
    
    fprintf(stream, "Pstates from Turbo to UltraTurbo (inclusive) : %d  (from %-2d to %-2d)\n", 
            wof->ut_vid_mod.ut_segment_pstates+1,       // +1 is for inclusivity 
            0,
            -(wof->ut_vid_mod.ut_segment_pstates));
            

    fprintf(stream, "Turbo<>UltraTurbo VID Modification - VDD\n");    
    vidmod_print(stream, wof, VDD);
        
    fprintf(stream, "Turbo<>UltraTurbo VID Modification - VCS\n");       
    vidmod_print(stream, wof, VCS);
       
    fprintf(stream,
        "---------------------------------------------------------------------------------------------------------\n");
}


/// Print a PstateSuperStructure on a given stream
///
/// \param stream The output stream
///
/// \param pss The PstateSuperStructure to print

void
pss_print(FILE* stream, PstateSuperStructure* pss)
{
    fprintf(stream,
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    fprintf(stream, "PstateSuperStructure @ %p;   Size: %d bytes\n", pss, sizeof(PstateSuperStructure));
    fprintf(stream,
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    gpst_print(stream, &(pss->gpst));
    lpsa_print(stream, &(pss->lpsa));
    cpmrange_print(stream, &(pss->cpmranges));   
    resclk_print(stream, &(pss->resclk));
    wof_print(stream, &(pss->wof));
    iddq_print(stream, &(pss->iddq));
   
    fprintf(stream,
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}


#endif // FAPIECMD

#ifdef __cplusplus
} // end extern C
#endif
