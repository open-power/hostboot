/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstate_tables.c $            */
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
// $Id: pstate_tables.c,v 1.26 2015/08/20 17:04:06 stillgs Exp $

/// \file pstate_tables.c
/// \brief This file contains code used to generate Pstate tables from real or
/// imagined chip characterizations.
///
/// This code is never run as part of OCC firmware, as Pstate tables are
/// always "given" to OCC either from the FSP (OCC product firmware), or by
/// being built-in the image (lab images).



#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "lab_pstates.h"
#include "pstate_tables.h"


// Debugging support, normally disabled. All of the formatted I/O you see in
// the code is effectively under this switch.

#ifdef __FAPI

#include "fapi.H"
#define fprintf(stream, ...) FAPI_ERR(__VA_ARGS__)
#define printf(...) FAPI_INF(__VA_ARGS__)
#define TRACE_NEWLINE ""

#else // __FAPI

#include <stdio.h>
#define fprintf(stream, ...) printf("***ERROR*** " __VA_ARGS__)
#define TRACE_NEWLINE "\n"

#endif // __FAPI

#define TRACE_ERROR(x)                                                  \
    ({                                                                  \
        fprintf(stderr, "%s:%d : Returning error code %d " TRACE_NEWLINE, \
                __FILE__, __LINE__, (x));                               \
        (x);                                                            \
    })

#define TRACE_ERRORX(x, ...)                    \
    ({                                          \
        TRACE_ERROR(x);                         \
        fprintf(stderr, ##__VA_ARGS__);         \
        (x);                                    \
    })

#ifdef __cplusplus
extern "C" {
#endif

#define MAX(X, Y)                           \
    ({                                      \
    typeof (X) __x = (X);                   \
    typeof (Y) __y = (Y);                   \
    (__x > __y) ? __x : __y;                \
    })

static int
cntlz32(uint32_t x)
{
    return __builtin_clz(x);
}


/// Byte-reverse a 16-bit integer if on a little-endian machine

uint16_t
revle16(uint16_t i_x)
{
    uint16_t rx;

#ifndef _BIG_ENDIAN
    uint8_t *pix = (uint8_t*)(&i_x);
    uint8_t *prx = (uint8_t*)(&rx);

    prx[0] = pix[1];
    prx[1] = pix[0];
#else
    rx = i_x;
#endif

    return rx;
}


/// Byte-reverse a 32-bit integer if on a little-endian machine

uint32_t
revle32(uint32_t i_x)
{
    uint32_t rx;

#ifndef _BIG_ENDIAN
    uint8_t *pix = (uint8_t*)(&i_x);
    uint8_t *prx = (uint8_t*)(&rx);

    prx[0] = pix[3];
    prx[1] = pix[2];
    prx[2] = pix[1];
    prx[3] = pix[0];
#else
    rx = i_x;
#endif

    return rx;
}


/// Byte-reverse a 64-bit integer if on a little-endian machine

uint64_t
revle64(const uint64_t i_x)
{
    uint64_t rx;

#ifndef _BIG_ENDIAN
    uint8_t *pix = (uint8_t*)(&i_x);
    uint8_t *prx = (uint8_t*)(&rx);

    prx[0] = pix[7];
    prx[1] = pix[6];
    prx[2] = pix[5];
    prx[3] = pix[4];
    prx[4] = pix[3];
    prx[5] = pix[2];
    prx[6] = pix[1];
    prx[7] = pix[0];
#else
    rx = i_x;
#endif

    return rx;
}


/// Create a ChipCharacterization from an array of VPD operating points and
/// characterization parameters.
///
/// \param characterization An uninitialized or unused ChipCharacterization
/// structure.
///
/// \param vpd An initialized array of VpdOperatingPoints, sorted by increasing
/// frequency. Note that there must be at least 1 DPLL frequency code step (1
/// Pstate step) between each VPD operating point in order to use the
/// characterization to create a Pstate table.
///
/// \param ops An uninitialized array of OperatingPoint, this array will be
/// intialized by this API.
///
/// \param parameters An initialized OperatingPointParameters structure
///
/// \param points The (non-negative) number of operating points
///
/// \retval 0 Success
///
/// \returns Other return codes indicate errors.

int
chip_characterization_create(ChipCharacterization *characterization,
                 VpdOperatingPoint *vpd,
                 OperatingPoint *ops,
                 OperatingPointParameters *parameters,
                 uint32_t points)
{
    int rc;
    uint32_t i, c;
    uint32_t pstate0_code;
    uint8_t  gpst_points            = 0;
    uint32_t curr_pstate_code       = 0;
    uint32_t next_pstate_code       = 0;
    uint32_t max_cores              = 0;


    do {
        rc = 0;

        if ((characterization == 0) || (parameters == 0)) {
            rc = -GPST_INVALID_OBJECT;
            break;
        }
        if ((vpd == 0) || (points <= 0)) {
            rc = TRACE_ERRORX(-GPST_INVALID_ARGUMENT, 
                            "vpd & points");
            break;
        }

        characterization->vpd        = vpd;
        characterization->ops        = ops;
        characterization->parameters = parameters;
        characterization->points     = points;

        max_cores =  characterization->max_cores;

        // Now convert the array of VPD operating point to the array of
        // internal operating points
        //
        // For frequencies and characterization voltages and currents this is
        // simple math.  Creating load-line corrected volatges requires
        // multiplying worst-case currents by the effective load-line
        // resistance.
        //
        // Note that the Pstate computation is made relative to the Pstate 0
        // frequency code (DPLL input).  It's done this way so that
        // frequencies with non-integral codes always round down (to lower
        // frequencies).

        pstate0_code =
            parameters->pstate0_frequency_khz / parameters->frequency_step_khz;

        for (i = 0; i < points; i++) {

            // Skip vpd point if next point is at same pstate
            curr_pstate_code = vpd[i].frequency_mhz * 1000 / parameters->frequency_step_khz;
            if (i < points-1) {
              next_pstate_code = vpd[i+1].frequency_mhz * 1000 / parameters->frequency_step_khz;
            }

            if (i < points-1 && (curr_pstate_code == next_pstate_code)) {
              continue;
            }

            ops[gpst_points].vdd_uv = vpd[i].vdd_5mv * 5000;
            ops[gpst_points].vcs_uv = vpd[i].vcs_5mv * 5000;

            ops[gpst_points].vdd_maxreg_uv = vpd[i].vdd_maxreg_5mv * 5000;
            ops[gpst_points].vcs_maxreg_uv = vpd[i].vcs_maxreg_5mv * 5000;

            ops[gpst_points].idd_ma = vpd[i].idd_500ma * 500;
            ops[gpst_points].ics_ma = vpd[i].ics_500ma * 500;

            ops[gpst_points].frequency_khz = vpd[i].frequency_mhz * 1000;

            // 'Corrected' voltages values add in the load-line & distribution IR drop

            ops[gpst_points].vdd_corrected_uv =
                ops[gpst_points].vdd_uv +
                ((ops[gpst_points].idd_ma * (parameters->vdd_load_line_uohm + parameters->vdd_distribution_uohm)) / 1000) +
                parameters->vdd_voffset_uv; // SW267784 add in offset in uohm

            ops[gpst_points].vcs_corrected_uv =
                ops[gpst_points].vcs_uv +
                ((ops[gpst_points].ics_ma * (parameters->vcs_load_line_uohm + parameters->vcs_distribution_uohm)) / 1000) +
                parameters->vcs_voffset_uv;   // SW267784 add in offset in uohm

            // iVRM 'Effective' voltages are set to the measured voltages

            ops[gpst_points].vdd_ivrm_effective_uv = ops[gpst_points].vdd_uv;
            ops[gpst_points].vcs_ivrm_effective_uv = ops[gpst_points].vcs_uv;

            ops[gpst_points].pstate =
                (ops[gpst_points].frequency_khz / parameters->frequency_step_khz) -
                pstate0_code;

            // For WOF, compute the "per active core" point set based on ratioing
            // the current at the operating point in a linear fashion.  The ratio
            // is only computed for up to the number of cores present on this chip
            // as the current contained in the VPD is measured with only that number
            // of cores active.
            if (i == TURBO || i == ULTRA)
            {
                for (c = 0; c < max_cores; ++c)
                {
                    double ratio = (double)(c+1)/max_cores;
                    double idd_currentf_ma = (double)ops[gpst_points].idd_ma;
                    uint32_t idd_current_ratioed_ma = (uint32_t)(idd_currentf_ma * ratio + 0.5);  // round up
                    uint32_t vdd_impedance_uohm = parameters->vdd_load_line_uohm + parameters->vdd_distribution_uohm;
                    
                    uint32_t vdd_dist_uplift_uv = 
                            (uint32_t)( idd_current_ratioed_ma * 
                                       ((double)vdd_impedance_uohm/1000));
                                                                      
                    ops[gpst_points].vdd_corrected_wof_uv[c] =
                        ops[gpst_points].vdd_uv +              // Base Point with bias but no system effects
                        vdd_dist_uplift_uv +                   // Distribution loss based on apportioned current
                        parameters->vdd_voffset_uv;            // Offset present

                    printf( "ops[%d].vdd_uv = %u "
                            "ratio = %f "
                            "id_ma = %6.0f "
                            "current ratioed_ma = %d "
                            "load line = %d "
                            "dist loss = %d "
                            "dist impedance uohm %d "
                            "dist uplift %d uV "
                            "dist offset %d uV "                            
                            "ops[%d].vdd_corrected_wof_uv[%u] = %u" TRACE_NEWLINE,
                            gpst_points, ops[gpst_points].vdd_uv,
                            ratio,
                            idd_currentf_ma,
                            idd_current_ratioed_ma,
                            parameters->vdd_load_line_uohm,
                            parameters->vdd_distribution_uohm,
                            vdd_impedance_uohm,
                            vdd_dist_uplift_uv,
                            parameters->vdd_voffset_uv,   
                            gpst_points, c, ops[gpst_points].vdd_corrected_wof_uv[c]);

                    double ics_currentf_ma = (double)ops[gpst_points].ics_ma;
                    uint32_t ics_current_ratioed_ma = (uint32_t)(ics_currentf_ma * ratio + 0.5);  // round up
                    
                    uint32_t vcs_impedance_uohm = parameters->vcs_load_line_uohm + parameters->vcs_distribution_uohm;
                    
                    uint32_t vcs_dist_uplift_uv = 
                            (uint32_t)( ics_current_ratioed_ma * 
                                       ((double)vcs_impedance_uohm/1000));
                                     
                    ops[gpst_points].vcs_corrected_wof_uv[c] =
                        ops[gpst_points].vcs_uv +              // Base Point with bias but no system effects
                        vcs_dist_uplift_uv +                   // Distribution loss based on apportioned current
                        parameters->vcs_voffset_uv;            // Offset present

                    printf( "ops[%d].vcs_uv = %u "
                            "ratio = %f "
                            "id_ma = %6.0f "
                            "current ratioed_ma = %d "
                            "load line = %d "
                            "dist loss = %d "
                            "dist impedance %d "
                            "dist uplift %d uV "
                            "dist offset %d UV "
                            "ops[%d].vcs_corrected_wof_uv[%u] = %u" TRACE_NEWLINE,
                            gpst_points, ops[gpst_points].vcs_uv,
                            ratio,
                            ics_currentf_ma,
                            ics_current_ratioed_ma,
                            parameters->vcs_load_line_uohm,
                            parameters->vcs_distribution_uohm,
                            ((parameters->vcs_load_line_uohm +
                                 parameters->vcs_distribution_uohm)),
                            vcs_dist_uplift_uv,
                            parameters->vcs_voffset_uv,   
                            gpst_points, c, ops[gpst_points].vcs_corrected_wof_uv[c]);
                }
            }

            printf("gpst_points %u "
                "ops[gpst_points].vdd_uv = %u "
                "ops[gpst_points].vcs_uv = %u "
                "ops[gpst_points].vdd_maxreg_uv = %u "
                "ops[gpst_points].vcs_maxreg_uv = %u "
                "ops[gpst_points].idd_ma = %u "
                "ops[gpst_points].ics_ma = %u" TRACE_NEWLINE,
                gpst_points,
                ops[gpst_points].vdd_uv,
                ops[gpst_points].vcs_uv,
                ops[gpst_points].vdd_maxreg_uv,
                ops[gpst_points].vcs_maxreg_uv,
                ops[gpst_points].idd_ma,
                ops[gpst_points].ics_ma);
            gpst_points++;
        }

        // Set points to adjusted number of points (ie. if vpd point was skipped due to being same pstate
        // as next vpd point
        characterization->points = gpst_points;

    } while (0);

    return rc;
}


// Set up GPST Pstate stepping parameters
//
// \param gpst A GlobalPstateTable object to be initialized with the stepping
// setup.
//
// \param pstate_stepsize Unsigned 7 bit (baby-) stepsize for Pstate
// transitions between the Global Pstate Actual and the Global Pstate
// Target.  The value 0 is considered illegal here.
//
// \param vrm_delay_ns This value defines the voltage settling delay (in
// nano-seconds) after each voltage change sequenced by the GPSM.  This
// includes all voltage changes \e except those explicitly managed by
// firmware manipulation of the SPIVID interface.  Legal values range from 0
// up to approximately 1,600,000 (1.6ms).  The VRM step delay is stored using
// an exponential encoding. The step delay computed here is a
// normalized (if possible) exponential encoding for highest accuracy.
//
// \note The caller is responsible for the mode-correctness of this call.
// The call should only be made when the GPSM is quiesced.
//
// \retval 0 Success
//
// \retval -GPST_INVALID_ARGUMENT Either argument was invalid in some way.

// jwy if we use this proc in future, do not use this value for nest freq
// instead, use the value of attribute ATTR_FREQ_PB
#define NEST_FREQ_KHZ 2400000

int
gpst_stepping_setup(GlobalPstateTable* gpst,
                    int pstate_stepsize,
                    int vrm_delay_ns)
{
    uint32_t cycles, sigbits, stepdelay_range, stepdelay_value;
    int rc;

    do {
        rc = 0;

        if ((pstate_stepsize <= 0) ||
            (pstate_stepsize > PSTATE_STEPSIZE_MAX) ||
            (vrm_delay_ns < 0) ||
            (vrm_delay_ns > VRM_STEPDELAY_MAX)) {
            rc = TRACE_ERRORX(-GPST_INVALID_ARGUMENT, 
                              "pstate_stepsize");
            break;
        }

        // Compute the number of pervasive / 2 cycles implied by the delay.
        // This is the frequency of the VRM stepper 'tick'. The base time
        // source for VRM stepping is therefore nest clock / 8.

        cycles = (((NEST_FREQ_KHZ / 1000) * vrm_delay_ns) / 1000) /
            (1 << LOG2_VRM_STEPDELAY_DIVIDER);

        // Normalize the exponential encoding

        sigbits = 32 - cntlz32(cycles);

       stepdelay_range = (sigbits - VRM_STEPDELAY_RANGE_BITS);

        if (stepdelay_range < 0)
        {
            stepdelay_range = 0;
        }

        stepdelay_value = cycles >> (stepdelay_range + LOG2_VRM_STEPDELAY_DIVIDER);

        if (stepdelay_range > ((1u << VRM_STEPDELAY_RANGE_BITS) - 1)) {
            rc = TRACE_ERRORX(-GPST_INVALID_ARGUMENT, 
                              "stepdelay_range");
            break;
        }

        gpst->pstate_stepsize = pstate_stepsize;
        gpst->vrm_stepdelay_range = stepdelay_range;
        gpst->vrm_stepdelay_value = stepdelay_value;

    } while (0);

    return rc;
}


// Create (initialize) a GPST entry from an operating point.
//
// Most of the voltages are straightforward - note that vuv2vrm11 rounds the
// voltages safely.
//
// The specification requires that Vcs be given as a signed offset. The Vcs
// offset is a simple signed number of VID steps (not a crazy inverted
// encoding like the Vdd VID code). We're always going to round the VCS offset
// up (greater Vdiff).  A fine point - we add the original offset to the
// VRM-11 form of the voltage, not the original voltage, further potentially
// increasing Vdiff.
//
// -*- NB : Note a subtle point about endianess here: The gpst_entry_t is
// coded to allow the correct creation of the uint64_t form of the object on
// big/little endian machines.  However, the 'gpe' pointer here is a pointer
// to a structure in a memory image, and using the host-endian form of the
// structure is wrong - in this case we always need to use the big-endian
// form! So we first construct the entry as an integer, then reverse it into
// the image.

static int
gpst_entry_create(gpst_entry_t *entry, OperatingPoint *op)
{
    int rc;
    uint8_t vid;

    gpst_entry_t gpe;

    do {

        // Clear the entry and do the straightforward conversions

        gpe.value = 0;

#define __SET(type, round, gpe_field, op_field)         \
    rc = vuv2##type(op->op_field, round, &vid);    \
    if (rc) break;                                  \
    gpe.fields.gpe_field = vid;

        __SET(vrm11, ROUND_VOLTAGE_UP, evid_vdd, vdd_corrected_uv);
        __SET(vrm11, ROUND_VOLTAGE_UP, evid_vcs, vcs_corrected_uv);
        __SET(ivid, ROUND_VOLTAGE_DOWN, evid_vdd_eff, vdd_ivrm_effective_uv);
        __SET(ivid, ROUND_VOLTAGE_DOWN, evid_vcs_eff, vcs_ivrm_effective_uv);
        __SET(ivid, ROUND_VOLTAGE_DOWN, maxreg_vdd, vdd_maxreg_uv);
        __SET(ivid, ROUND_VOLTAGE_DOWN, maxreg_vcs, vcs_maxreg_uv);

       ;

        // Add the check byte

        uint8_t gpstCheckByte(uint64_t gpstEntry);
        gpe.fields.ecc = gpstCheckByte(gpe.value);

    } while (0);

    // Byte reverse the entry into the image.

    entry->value = revle64(gpe.value);
    return rc;
}


int
vid_mod_entry_create(WOFElements *wof, uint32_t index, uint32_t core, OperatingPoint *op)
{
    int rc = 0;
    uint8_t vid;

    do {


#define __SETVM(type, round, wof_field, op_field)         \
    rc = vuv2##type(op->op_field, round, &vid);    \
    if (rc) \
    { \
        fprintf(stderr, "   SETVM error:  op_field = %u; vid = %u" TRACE_NEWLINE, op->op_field, vid); \
        break;                                    \
    } \
    wof->ut_vid_mod.wof_field = vid; \

        __SETVM(vrm11, ROUND_VOLTAGE_UP, ut_segment_vdd_vid[index][core], vdd_corrected_wof_uv[core]);

                printf("   op->vdd_corrected_wof_uv[%d] = %u; wof->ut_vid_mod.ut_segment_vdd_vid[%d][%d] = 0x%02X" TRACE_NEWLINE,                    
                    core, op->vdd_corrected_wof_uv[core],
                    index, core, wof->ut_vid_mod.ut_segment_vdd_vid[index][core]);

        __SETVM(vrm11, ROUND_VOLTAGE_UP, ut_segment_vcs_vid[index][core], vcs_corrected_wof_uv[core]);



        printf("   op->vcs_corrected_wof_uv[%d] = %u; wof->ut_vid_mod.ut_segment_vcs_vid[%d][%d] = 0x%02X" TRACE_NEWLINE,
                    core, op->vcs_corrected_wof_uv[core],
                    index, core, wof->ut_vid_mod.ut_segment_vcs_vid[index][core]);

    } while (0);

    return rc;
}



// Linear interpolation of voltages

static uint32_t
interpolate(uint32_t base, uint32_t next, int step, int steps)
{
    return base + (((next - base) * step) / steps);
}


/// Create a global Pstate table from an array of internal operating points
///
/// \param gpst A pointer to a GlobalPstateTable structure.  This structure
/// must not currently be in use as the PMC Global Pstate Table.
///
/// \param characterization An initialized ChipCharacterization.  The
/// operating point table must be sorted in ascending order by both Pstate and
/// (uncorrected) Vdd and Vcs voltages. The range of Pstates in the table must
/// also physicaly fit within the physical number of entries.
///
/// \param pstate_stepsize Pstate step size
///
/// \param evrm_delay_ns External VRM delay in nano-seconds
///
/// This routine creates a GlobalPstateTable by linear interpolation of
/// corrected voltages between characterized operating points.
///
/// Defaults - Can be overidden later:
///
/// - The Psafe is always set to the minimum Pstate
/// - The dpll_fmax_bias is set to 0 for all cores
/// - The undervolting bias is set to 0
/// - The pstate0_frequency_code is det to the default value for all cores.
///
/// This routine always checks for errors
///
/// \retval 0 Success
///
/// \retval -GPST_INVALID_OBJECT Either the \a gpst or \a ops were NULL (0) or
/// obviously invalid or incorrectly initialized.
///
/// \retval -GPST_INVALID_ARGUMENT This code indicates one of several types of
/// errors that may occur in the \a ops.
///
/// \retval -VRM_INVALID_VOLTAGE A characterized or interpolated voltage can
/// not be represented as a VRM-11 VID code.

int
gpst_create(GlobalPstateTable *gpst,
            ChipCharacterization *characterization,
            WOFElements *wof,
            int pstate_stepsize,
            int evrm_delay_ns)
{
    OperatingPoint *ops, interp;
    int rc;
    uint32_t points, pstates_ut = 0;
    int32_t entry, entry_turbo;
    int32_t pmin, pmax, pstate;
    uint8_t fNom;
    uint32_t i, c, max_cores;
    gpst_entry_t gpst_entry_temp;

    do {
        rc = 0;

        // Basic pointer checks

        if ((gpst == 0) || (characterization == 0)) {
            rc = -GPST_INVALID_OBJECT;
            break;
        }

        // Check for null or illegal operating point tables

        ops         = characterization->ops;
        points      = characterization->points;
        max_cores   = characterization->max_cores;

        if ((ops == 0) || (points <= 0)) {
            rc = -GPST_INVALID_OBJECT;
            break;
        }

        pmin = ops[0].pstate;
        pmax = ops[points - 1].pstate;
        printf("**** Check : pmin %x, pmax %x" TRACE_NEWLINE,
                pmin, pmax);

        // Check that the range of Pstates are legal and will actually fit in
        // the table. 'Fitting' will never be a problem for PgP as long as the
        // table of operating points does not include operating points for
        // frequencies below Fmax@Vmin.

        if ((pmin < PSTATE_MIN) ||
            (pmax > PSTATE_MAX) ||
            ((pmax - pmin + 1) > GLOBAL_PSTATE_TABLE_ENTRIES)) {
            rc = TRACE_ERRORX(-GPST_INVALID_ARGUMENT, 
                "pmin %x, PSTATE_MIN %x; pmax %x, PSTATE_MAX %x; pmax - pmin + 1 %x, GLOBAL_PSTATE_TABLE_ENTRIES %x" TRACE_NEWLINE,
                pmin,
                PSTATE_MIN,
                pmax,
                PSTATE_MAX,
                pmax - pmin + 1,
                GLOBAL_PSTATE_TABLE_ENTRIES
            );            
            break;
        }

        // Check the ordering constraints

       for (i = 1; i < points; i++) {

            if ((ops[i].pstate < ops[i - 1].pstate)  ||
                (ops[i].vdd_uv < ops[i - 1].vdd_uv)  |    // allow them to be equal
                (ops[i].vcs_uv < ops[i - 1].vcs_uv)) {    // allow them to be equal
                rc = TRACE_ERRORX(-GPST_INVALID_ARGUMENT, 
                    "i = %u pstate %x, ops[i - 1].pstate %x; ops[i].vdd_uv  %x, ops[i - 1].vdd_uv %x; ops[i].vcs_uv %x, ops[i - 1].vcs_uv %x" TRACE_NEWLINE,
                    i,
                    ops[i].pstate,
                    ops[i - 1].pstate,
                    ops[i].vdd_uv ,
                    ops[i - 1].vdd_uv,
                    ops[i].vcs_uv,
                    ops[i - 1].vcs_uv
                );

                break;
            }
        }
        if (rc) break;

        // Update the table from VPD/system parameters, then default the
        // pstate0_frequency_code (fNom) to the 'nominal' code and set the
        // DPLL bias to 0.

        gpst->pstate0_frequency_khz =
            revle32(characterization->parameters->pstate0_frequency_khz);
        gpst->frequency_step_khz =
            revle32(characterization->parameters->frequency_step_khz);

        // Now we can interpolate the operating points to build the
        // table. Interpolation is done by creating (or using) an
        // OperatingPoint for each intermediate (or characterized) Pstate.
        // The gpst_entry_create() function then creates the GPST entry from
        // the operating point. Only the voltages are interpolated, and they
        // are all interpolated in units of micro-Volts.

        // The WOF algorithm augments the interpolation between the Turbo
        // and the UltraTurbo points to calculate a differnt segment based
        // on the number of cores that might be active.

        gpst->pmin    = pmin;
        gpst->entries = pmax - pmin + 1;

        // Set the Pmin Pstate
        entry = 0;
        if (gpst_entry_create(&(gpst->pstate[entry]), &(ops[0]))) {
            rc = TRACE_ERRORX(-GPST_INVALID_ENTRY,
                "gpst_entry_create error setting Pmin");
            break;
        }
        entry++;
        pstate = pmin;
        printf("**** Check : pstate %x" TRACE_NEWLINE, pstate);

#define __INTERPOLATE(field)                                            \
                do {                                                    \
                    interp.field =                                      \
                        interpolate(ops[i - 1].field, ops[i].field,     \
                                    (pstate - ops[i - 1].pstate),    \
                                    (ops[i].pstate - ops[i - 1].pstate)); \
                } while (0)


        // Iterate over characterized operating points...
        for (i = 1; i < points; i++) {

            // For WOF, handle the Turbo<>UltraTurbo segment differently
            if (i == ULTRA) {

                // Save the Turbo Pstate in the GPST structure for future reference
                gpst->turbo_ps = ops[i-1].pstate;
                
                printf( " Turbo -> %d", gpst->turbo_ps);

                for (c = 0; c < max_cores; ++c) {
                    pstate = gpst->turbo_ps;    // Start again
                    entry = entry_turbo;
                    pstates_ut = 0;             // Turbo is the first pstate
                                        
                    // --------------------------------------------------
                    // Fill in the Turbo information in the WOF structure
                    interp.pstate = pstate;
                    
                    // Compute the VID overlay values for this core count
                    __INTERPOLATE(vdd_corrected_wof_uv[c]);
                    __INTERPOLATE(vcs_corrected_wof_uv[c]);

                    printf( ">> Turbo UT WOF entry %u pstate %x %-2d index %d "
                        "ops[%d].vdd_corrected_wof_uv[%d] = %06d "
                        "ops[%d].vdd_corrected_wof_uv[%d] = %06d "
                        "interp.vdd_corrected_wof_uv[%d] = %06d ",
                        entry,
                        pstate, pstate,
                        pstates_ut,
                        i-1, c, ops[i-1].vdd_corrected_wof_uv[c],
                        i, c, ops[i].vdd_corrected_wof_uv[c],
                        c, interp.vdd_corrected_wof_uv[c]
                        );
                    
                    // >>> Note: iVRMs are not supported as active in the Turbo
                    // to UltraTurbo segment
                    if (wof->wof_enabled) 
                    {
                        printf(">>>> WOF Enabled <<<< " TRACE_NEWLINE);
                        if (vid_mod_entry_create(wof, pstates_ut, c, &interp)) {
                            rc = TRACE_ERRORX(-GPST_INVALID_ENTRY,
                                              "gpst_entry_create error - vid mod interpolation");
                            break;
                        }
                    }

                    pstates_ut++;
                    entry++;

                    // --------------------------------------------------
                    // Interpolate intermediate Pstates...
                    while (++pstate != ops[i].pstate) {
                        printf("pstate = %d", pstate);

                        interp.pstate = pstate;
                        
                        if (wof->wof_enabled) 
                        {                       
                            // Compute the VID overlay values for this core count
                            __INTERPOLATE(vdd_corrected_wof_uv[c]);
                            __INTERPOLATE(vcs_corrected_wof_uv[c]);

                            printf( "UT WOF entry %u pstate %x %-2d index %d "
                                "ops[%d].vdd_corrected_wof_uv[%d] = %06d "
                                "ops[%d].vdd_corrected_wof_uv[%d] = %06d "
                                "interp.vdd_corrected_wof_uv[%d]  = %06d ",
                                entry,
                                pstate, pstate,
                                pstates_ut,
                                i-1, c, ops[i-1].vdd_corrected_wof_uv[c],
                                i, c, ops[i].vdd_corrected_wof_uv[c],
                                c, interp.vdd_corrected_wof_uv[c]
                                );

                            // >>> Note: iVRMs are not supported as active in the Turbo
                            // to UltraTurbo segment

                            if (vid_mod_entry_create(wof, pstates_ut, c, &interp)) {
                                rc = TRACE_ERRORX(-GPST_INVALID_ENTRY,
                                                  "gpst_entry_create error - vid mod interpolation");
                                break;
                            }
                            
                            // Increment VID modification table index
                            pstates_ut++;
                        }

                        // Compute the VIDs for this Pstate
                        __INTERPOLATE(vdd_corrected_uv);
                        __INTERPOLATE(vcs_corrected_uv);
                        __INTERPOLATE(vdd_ivrm_effective_uv);
                        __INTERPOLATE(vcs_ivrm_effective_uv);
                        __INTERPOLATE(vdd_maxreg_uv);
                        __INTERPOLATE(vcs_maxreg_uv);

                        // Write the Global Ptate Table if processing the
                        // maximum core count
                        if (c == max_cores-1)
                        {
                            printf(">>>> Writing GPST entry %d <<<<" TRACE_NEWLINE, entry);
                            if (gpst_entry_create(&(gpst->pstate[entry]), &interp))
                            {
                                rc = TRACE_ERRORX(-GPST_INVALID_ENTRY,
                                                  "gpst_entry_create error - UT interpolation");
                                break;
                            }

                           gpst_entry_temp.value =  revle64(gpst->pstate[entry].value);
                           printf("UT entry %u pstate %x %-2d"
                                "evid_vdd = 0x%02llX (VRM-11) "
                                "evid_vcs = 0x%02llX (VRM-11) "
                                "evid_vdd_eff = 0x%02llX (iVID) "
                                "evid_vcs_eff = 0x%02llX (iVID) "
                                "maxreg_vdd = 0x%02llX (iVID) "
                                "maxreg_vcs = 0x%02llX (iVID) ",
                                entry,
                                pstate, pstate,
                                gpst_entry_temp.fields.evid_vdd,
                                gpst_entry_temp.fields.evid_vcs,
                                gpst_entry_temp.fields.evid_vdd_eff,
                                gpst_entry_temp.fields.evid_vcs_eff,
                                gpst_entry_temp.fields.maxreg_vdd,
                                gpst_entry_temp.fields.maxreg_vcs);                               

                        }
                        entry++;                        
                    }
                    if (rc) break;
                  
                    // Set the characterized Pstate
                    if (gpst_entry_create(&(gpst->pstate[entry]), &(ops[i]))) {
                        rc = TRACE_ERRORX(-GPST_INVALID_ENTRY,
                                          "gpst_entry_create error - normal UT interpolation");
                        break;
                    }

                    gpst_entry_temp.value =  revle64(gpst->pstate[entry].value);
                    printf("UT entry %u pstate %x %-2d "
                            "evid_vdd = 0x%02llX (VRM-11) "
                            "evid_vcs = 0x%02llX (VRM-11) "
                            "evid_vdd_eff = 0x%02llX (iVID) "
                            "evid_vcs_eff = 0x%02llX (iVID) "
                            "maxreg_vdd = 0x%02llX (iVID) "
                            "maxreg_vcs = 0x%02llX (iVID) ",
                            entry,
                            pstate, pstate,
                            gpst_entry_temp.fields.evid_vdd,
                            gpst_entry_temp.fields.evid_vcs,
                            gpst_entry_temp.fields.evid_vdd_eff,
                            gpst_entry_temp.fields.evid_vcs_eff,
                            gpst_entry_temp.fields.maxreg_vdd,
                            gpst_entry_temp.fields.maxreg_vcs);
                    
                    if (wof->wof_enabled) 
                    {
                        // Fill in the UltraTurbo information in the WOF structure
                        interp.pstate = pstate;

                        // Compute the VID overlay values for this core count
                        __INTERPOLATE(vdd_corrected_wof_uv[c]);
                        __INTERPOLATE(vcs_corrected_wof_uv[c]);

                        printf( ">> UltraTurbo UT WOF entry %u pstate %x %-2d index %d "
                            "ops[%d].vdd_corrected_wof_uv[%d] = %06d "
                            "ops[%d].vdd_corrected_wof_uv[%d] = %06d "
                            "interp.vdd_corrected_wof_uv[%d]  = %06d " TRACE_NEWLINE,
                            entry,
                            pstate, pstate,
                            pstates_ut,
                            i-1, c, ops[i-1].vdd_corrected_wof_uv[c],
                            i, c, ops[i].vdd_corrected_wof_uv[c],
                            c, interp.vdd_corrected_wof_uv[c]
                            );

                        // >>> Note: iVRMs are not supported as active in the Turbo
                        // to UltraTurbo segment
                    
                        if (vid_mod_entry_create(wof, pstates_ut, c, &interp)) {
                            rc = TRACE_ERRORX(-GPST_INVALID_ENTRY,
                                              "gpst_entry_create error - vid mod interpolation");
                            break;
                        }
                                                                        
                        // Save the UltraTurbo segment Pstate count
                        wof->ut_vid_mod.ut_segment_pstates = pstates_ut;

                        // Save the maximum core count
                        wof->ut_vid_mod.ut_max_cores = max_cores;

                        printf( "UT WOF entry %u pstate %x index %d "
                                "wof->ut_vid_mod.ut_segment_vcs_vid[%d][%d] = 0x%02X  "
                                "ops[%d].vdd_corrected_uv  %d UltraTurbo",
                                entry,
                                pstate,
                                pstates_ut,
                                pstates_ut, c, wof->ut_vid_mod.ut_segment_vdd_vid[pstates_ut][c],
                                i, ops[i].vdd_corrected_uv
                                ); 
                    }        
                    entry++;                  
                }

            }
            else
            {

                // Save the PowerSave and Nominal Pstate in the GPST structure for future reference
                // Get update for each point;

                if (i == NOMINAL)
                {
                    gpst->nominal_ps = ops[i].pstate;
                    printf( " Nominal Pstate -> %d", gpst->nominal_ps);

                    gpst->powersave_ps = ops[i-1].pstate;
                    printf( " PowerSave Pstate -> %d", gpst->powersave_ps);
                }

                // Interpolate intermediate Pstates...
                while (++pstate != ops[i].pstate) {

                    interp.pstate = pstate;

                    __INTERPOLATE(vdd_corrected_uv);
                    __INTERPOLATE(vcs_corrected_uv);
                    __INTERPOLATE(vdd_ivrm_effective_uv);
                    __INTERPOLATE(vcs_ivrm_effective_uv);
                    __INTERPOLATE(vdd_maxreg_uv);
                    __INTERPOLATE(vcs_maxreg_uv);

                    if (gpst_entry_create(&(gpst->pstate[entry]), &interp)) {
                        rc = TRACE_ERRORX(-GPST_INVALID_ENTRY, 
                            "gpst_entry_create error - normal interpolation");
                        break;
                    }

                    gpst_entry_temp.value =  revle64(gpst->pstate[entry].value);
                    printf( "Non UT entry %u pstate %x %-2d "
                            "evid_vdd = 0x%02llX (VRM-11) "
                            "evid_vcs = 0x%02llX (VRM-11) "
                            "evid_vdd_eff = 0x%02llX (iVID) "
                            "evid_vcs_eff = 0x%02llX (iVID) "
                            "maxreg_vdd = 0x%02llX (iVID) "
                            "maxreg_vcs = 0x%02llX (iVID) ",
                            entry,
                            pstate, pstate,
                            gpst_entry_temp.fields.evid_vdd,
                            gpst_entry_temp.fields.evid_vcs,
                            gpst_entry_temp.fields.evid_vdd_eff,
                            gpst_entry_temp.fields.evid_vcs_eff,
                            gpst_entry_temp.fields.maxreg_vdd,
                            gpst_entry_temp.fields.maxreg_vcs);

                    entry++;
                }
                if (rc) break;

                // Set the characterized Pstate
                if (gpst_entry_create(&(gpst->pstate[entry]), &(ops[i]))) {
                    rc = -GPST_INVALID_ENTRY;
                    break;
                }

                gpst_entry_temp.value =  revle64(gpst->pstate[entry].value);
                printf( ">> VPD Point Non UT entry %u pstate %x %-2d "
                         "evid_vdd = 0x%02llX (VRM-11) "
                         "evid_vcs = 0x%02llX (VRM-11) "
                         "evid_vdd_eff = 0x%02llX (iVID) "
                         "evid_vcs_eff = 0x%02llX (iVID) "
                         "maxreg_vdd = 0x%02llX (iVID) "
                         "maxreg_vcs = 0x%02llX (iVID) ",
                         entry,
                         pstate, pstate,
                         gpst_entry_temp.fields.evid_vdd,
                         gpst_entry_temp.fields.evid_vcs,
                         gpst_entry_temp.fields.evid_vdd_eff,
                         gpst_entry_temp.fields.evid_vcs_eff,
                         gpst_entry_temp.fields.maxreg_vdd,
                            gpst_entry_temp.fields.maxreg_vcs);

                // The iVRM maximum pstate is set for each characterization point
                // as the points are traversed.  The last one processed by this
                // clause is Turbo.  As iVRMs are not engaged at the Turbo point
                // itself, subtract 1.
                gpst->ivrm_max_ps  = ops[i].pstate - 1;
                printf( " ivrm Pstate -> %d Op Point Pstate%d" TRACE_NEWLINE, gpst->ivrm_max_ps, ops[i].pstate);

                // Set the number of entries from Psave to the iVRM maximum
                // (Turbo Pstate - 1)
                gpst->ivrm_entries = entry - 1;

                // Save the entry for the post Turbo clause.  Written for each iteration.
                // Only the last one written matters
                entry_turbo = entry;
                
                printf( " entry_turbo -> %d" TRACE_NEWLINE, entry_turbo);
                
                entry++;
            }
        }
        if (rc) break;

        // Fill in the defaults

        gpst->pvsafe = gpst->pmin+1;

        fNom = revle32(gpst->pstate0_frequency_khz) /
            revle32(gpst->frequency_step_khz);

        for (i = 0; i < PGP_NCORES; i++) {
            gpst->pstate0_frequency_code[i] = revle16(fNom);
            gpst->dpll_fmax_bias[i] = 0;
        }

        // Hardcode the vrm delay settings for GA1
        // This should be set by gpst_stepping_setup() in the future.
        gpst->pstate_stepsize = pstate_stepsize;
        // SW256954: Updated following two values
        gpst->vrm_stepdelay_range = 0x8;
        gpst->vrm_stepdelay_value = 0x9;

    } while (0);

    return rc;
}


/// Create a local Pstate table
///
/// \param gpst A pointer to a GlobalPstateTable structure for lookup.
///
/// \param lpsa A pointer to a LocalPstateArray structure to populate
///
/// \param dead_zone_5mv dead zone value
///
/// \param evrm_delay_ns External VRM delay in nano-seconds
///
/// This routine creates a LocalPstateArray by using the dead zone value and
/// data in the GlobalPstateTable.
///
/// \retval 0 Success
///
/// \retval -LPST_INVALID_OBJECT Either the \a gpst or \a lpsa were NULL (0) or
/// obviously invalid or incorrectly initialized.
///
/// \retval -LPST_INVALID_ARGUMENT indicates that the difference between
///  pmax & pmin in gpst is less than deadzone voltage (ie. no data to build lpsa)

int
lpst_create(const GlobalPstateTable *gpst,
            LocalPstateArray *lpsa,
            const uint8_t dead_zone_5mv,
            double volt_int_vdd_bias,
            double volt_int_vcs_bias,
            uint8_t *vid_incr_gt7_nonreg)
{
  int           rc = 0;
  int8_t        i;
  uint8_t       j;
  gpst_entry_t  entry;
  uint32_t      turbo_uv;
  uint32_t      gpst_uv;
  uint32_t      v_uv;
  uint32_t      vdd_uv;
  uint8_t       v_ivid;
  uint8_t       gpst_ivid;
  uint8_t       lpst_max_found = 0;
  uint32_t      lpst_max_uv;
  uint8_t       lpst_entries;
  uint8_t       lpst_entries_div4;
  uint8_t       gpst_index;
  Pstate        lpst_pmin;
  Pstate        lpst_pstate;
  Pstate        lpst_max_pstate = 0;
  uint8_t       vid_incr[3] = {0,0,0};
  uint8_t       steps_above_curr;
  uint8_t       steps_below_curr;
  uint8_t       inc_step;
  uint8_t       dec_step;

  do {

    // Basic pointer checks
    if ((gpst == 0) || (lpsa == 0)) {
      rc = -LPST_INVALID_OBJECT;
      break;
    }


    // ------------------------------------------------------------------
    // find lspt_max in gpst
    //  - lpst_max is gpst entry that is equal to (turbo_vdd - deadzone)
    // ------------------------------------------------------------------

    entry.value = revle64(gpst->pstate[(gpst->ivrm_entries)].value);
    rc          = ivid2vuv(entry.fields.evid_vdd_eff, &turbo_uv);  if (rc) break;

    printf("gpst->ivrm_entries = %u, turbo_uv = %u", gpst->ivrm_entries, turbo_uv);

    turbo_uv    = (uint32_t) (turbo_uv * volt_int_vdd_bias);
    lpst_max_uv = turbo_uv - (dead_zone_5mv * 5000);

    for (i = gpst->ivrm_entries ; i >= 0; i--) {
      entry.value = revle64(gpst->pstate[i].value);
      rc         = ivid2vuv(entry.fields.evid_vdd_eff, &v_uv);  if (rc) break;
      v_uv        = (uint32_t) (v_uv * volt_int_vdd_bias);

      if (lpst_max_uv >= v_uv) {
        lpst_max_found = 1;
        lpst_max_pstate = gpst_pmax(gpst) - (gpst->entries - i - 1);
        printf("lpst_max_pstate = %x" TRACE_NEWLINE, lpst_max_pstate);
        break;
      }
    }

    if (rc) break;

    // generate a warning if lpst max not found
    //  - indicates that the difference between pmax & pmin in gpst is less than deadzone voltage
    //  - no data will be in lpst (lpst entries = 0)
    if (lpst_max_found == 0) {
      rc = -LPST_GPST_WARNING;
      break;
    }

    lpst_entries = gpst->ivrm_entries;
    lpst_pmin    = gpst->pmin;

    printf("lpst_entries = %u" TRACE_NEWLINE, lpst_entries);
    // ----------------------------------------------------------------------------
    // now loop over gpst from 0 to lpst_entries and fill in lpst from data in gpst
    // ----------------------------------------------------------------------------
    gpst_index = 0;

    lpst_entries_div4 = lpst_entries/4;
    if ( lpst_entries % 4 != 0)
       lpst_entries_div4++;

    // current lpst pstate value as table is created
    lpst_pstate = gpst_pmin(gpst);

    printf("lpst create before loop: lpst_entries_div4 = %d" TRACE_NEWLINE, lpst_entries_div4);
    for (i = 0 ; i < lpst_entries_div4; i++) {
      entry.value = revle64(gpst->pstate[gpst_index].value);

      // compute ivid_vdd
      rc = ivid2vuv(entry.fields.evid_vdd_eff, &vdd_uv);   if (rc) break;
      vdd_uv    = (uint32_t) (vdd_uv * volt_int_vdd_bias);
      rc = vuv2ivid(vdd_uv, ROUND_VOLTAGE_DOWN, &v_ivid);  if (rc) break;
      lpsa->pstate[i].fields.ivid_vdd = v_ivid;

      // compute ivid_vcs
      rc = ivid2vuv(entry.fields.evid_vcs_eff, &v_uv);  if (rc) break;
      v_uv    = (uint32_t) (v_uv * volt_int_vcs_bias);
      rc = vuv2ivid(v_uv, ROUND_VOLTAGE_DOWN, &v_ivid); if (rc) break;
      lpsa->pstate[i].fields.ivid_vcs = v_ivid;

      // --------------------------------------------------------------
      // compute increment for remaining 3 pstates for this lpst entry
      // --------------------------------------------------------------
      vid_incr[0] = 0;
      vid_incr[1] = 0;
      vid_incr[2] = 0;

      for (j = 0; j <= 2; j++) {

        gpst_index++;
        if (gpst_index >= lpst_entries)
          break;

        entry.value = revle64(gpst->pstate[gpst_index].value);
        rc          = ivid2vuv(entry.fields.evid_vdd_eff, &vdd_uv);   if (rc) break;
        vdd_uv    = (uint32_t) (vdd_uv * volt_int_vdd_bias);
        rc          = vuv2ivid(vdd_uv, ROUND_VOLTAGE_DOWN, &v_ivid);  if (rc) break;
        vid_incr[j] = v_ivid - lpsa->pstate[i].fields.ivid_vdd;

        // point to next lpst pstate
        lpst_pstate++;

        // the max for this field is 7, so clip to 7 if it's > 7
        if (vid_incr[j] > 7) {
          vid_incr[j] = 7;

          // if in regulation, return an error
          if (lpst_pstate <= lpst_max_pstate) {
            rc = TRACE_ERRORX(-LPST_INCR_CLIP_ERROR, 
                "lpst clip: lpst_pstate %x lpst_max_pstate %x",
                lpst_pstate,
                lpst_max_pstate
                );                      
            break;
          }

          // if not in regulation, return a warning
          if (lpst_pstate > lpst_max_pstate) {
            *vid_incr_gt7_nonreg = 1;
          }
        }

      }
      if (rc) break;
      printf("lpst create after loop" TRACE_NEWLINE);

      lpsa->pstate[i].fields.ps1_vid_incr = vid_incr[0];
      lpsa->pstate[i].fields.ps2_vid_incr = vid_incr[1];
      lpsa->pstate[i].fields.ps3_vid_incr = vid_incr[2];

      // --------------------
      // compute power ratios
      // --------------------
      float  sigma = 3;
      float  iac_wc;
      float  iac;
      float  vout;
      float  pwrratio_f;
      uint8_t pwrratio;

      // convert to mV and subract 100 mV (note: vdd_uv is the max of the vdd values for this lpst entry)
      vout = (float)((vdd_uv/1000) - 100);

      // equations from Josh
      iac_wc     = 1.25 * ( 28.5 * 1.25 - 16 ) * ( 1 - 0.05 * 2) * 40/71;        // testsite equation & ratio of testsite to anticipated produ
      iac        = 1.25 * (-15.78 -0.618 * sigma + 27.6 * vout/1000) * 40/64;    // product equation & ratio of testsite to actual product
      pwrratio_f = iac / iac_wc;

      if (pwrratio_f >= 1.0)
        pwrratio   = 63;
      else
        pwrratio   = (uint8_t)((pwrratio_f*64) + 0.5);

      lpsa->pstate[i].fields.vdd_core_pwrratio = pwrratio;
      lpsa->pstate[i].fields.vcs_core_pwrratio = pwrratio;
      lpsa->pstate[i].fields.vdd_eco_pwrratio  = pwrratio;
      lpsa->pstate[i].fields.vcs_eco_pwrratio  = pwrratio;

      // ------------------------------------
      // compute increment step and decrement
      // ------------------------------------
      //  - look above current pstate to pstate that is >= 25 mV for inc_step
      //  - look below current pstate to pstate that is >= 25 mV for dec_step

      // find # steps above and below current lpst pstate
      steps_above_curr = gpst_pmax(gpst) - lpst_pstate;
      steps_below_curr = lpst_pstate     -  gpst_pmin(gpst);


      // start looking above in gpst to find inc_step
      inc_step = 0; // default

      for (j = 1; j <= steps_above_curr; j++) {
        inc_step = j - 1;
        entry.value = revle64(gpst->pstate[lpst_pstate - gpst_pmin(gpst) + j].value);
        rc         = ivid2vuv(entry.fields.evid_vdd_eff, &gpst_uv);      if (rc) break;
        gpst_uv     = (uint32_t) (gpst_uv * volt_int_vdd_bias);
        rc         = vuv2ivid(gpst_uv, ROUND_VOLTAGE_DOWN, &gpst_ivid);  if (rc) break;

        if ( (gpst_ivid - v_ivid) >= 4)
          break;
      }
      if (rc) break;

      // clip inc_step
      if (inc_step > 7)
        inc_step = 7;

      lpsa->pstate[i].fields.inc_step = inc_step;

      // start looking below in gpst to find dec_step
      dec_step = 0; // default

      for (j = 1; j <= steps_below_curr; j++) {
        dec_step = j - 1;
        entry.value = revle64(gpst->pstate[lpst_pstate - gpst_pmin(gpst) - j].value);
        rc         = ivid2vuv(entry.fields.evid_vdd_eff, &gpst_uv);         if (rc) break;
        gpst_uv     = (uint32_t) (gpst_uv * volt_int_vdd_bias);
        rc         = vuv2ivid(gpst_uv, ROUND_VOLTAGE_DOWN, &gpst_ivid);  if (rc) break;

        if ( (v_ivid - gpst_ivid ) >= 4)
          break;
      }
      if (rc) break;

      // clip dec_step
      if (dec_step > 7)
        dec_step = 7;

      lpsa->pstate[i].fields.dec_step = dec_step;

      // Byte reverse the entry into the image.
      lpsa->pstate[i].value = revle64(lpsa->pstate[i].value);

      gpst_index++;
      if (gpst_index > lpst_entries)
        break;

       // point to next lpst pstate
       lpst_pstate++;
    }

    // set these fields in lpst structure
    if (lpst_max_found == 0) {
      lpsa->pmin    = 0;
      lpsa->entries = 0;
    }
    else {
      lpsa->pmin    = lpst_pmin;
      lpsa->entries = lpst_entries;
    }

  } while (0);

  return rc;

} // end lpst_create

// This routine will fully fill out the VDS region table even if
// some of the upper entries are not used.
void
build_vds_region_table( ivrm_parm_data_t*       i_ivrm_parms,
                        PstateSuperStructure*   pss)
{
    uint8_t     i;
    uint32_t    vds;
    uint64_t    beg_offset = 0;
    uint64_t    end_offset = 0;

    vds = (i_ivrm_parms->vds_min_range_upper_bound*1000)/IVID_STEP_UV;
    end_offset = (uint64_t)vds;

    for (i = 0; i < i_ivrm_parms->vds_region_entries; i++)
    {
        pss->lpsa.vdsvin[i].fields.ivid0 = beg_offset;
        pss->lpsa.vdsvin[i].fields.ivid1 = end_offset;

        // Calculate offsets for next entry
        beg_offset = end_offset + 1;

        // clip at 127
        if (beg_offset >= 127)
          beg_offset = 127;

        vds =(uint32_t)( (float)end_offset * (1 + ( (float)i_ivrm_parms->vds_step_percent/100)));
        end_offset = (uint64_t)vds;

        // clip at 127
        if (end_offset >= 127)
          end_offset = 127;
    }
}

// This routine will fully fill out the VDS region table even if
// some of the upper entries are not used.
void
fill_vin_table( ivrm_parm_data_t*       i_ivrm_parms,
                PstateSuperStructure*   pss)
{
    uint8_t     s;
    uint8_t     i;
    uint32_t    idx;

    i = i_ivrm_parms->vin_table_setsperrow;
    for (i = 0; i < i_ivrm_parms->vds_region_entries; i++)
    {
        for (s = 0; s < i_ivrm_parms->vin_table_setsperrow; s++) {
            idx = (i*4) + s;
            pss->lpsa.vdsvin[idx].fields.pfet0 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet1 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet2 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet3 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet4 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet5 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet6 = i_ivrm_parms->forced_pfetstr_value;
            pss->lpsa.vdsvin[idx].fields.pfet7 = i_ivrm_parms->forced_pfetstr_value;

            // Byte reverse the entry into the image.
            pss->lpsa.vdsvin[idx].value = revle64(pss->lpsa.vdsvin[idx].value);
         }
    }
}

#undef  abs
#define abs(x) (((x)<0.0)?(-(x)):(x))

void simeq(int n, double A[], double Y[], double X[])
{

/*      PURPOSE : SOLVE THE LINEAR SYSTEM OF EQUATIONS WITH REAL     */
/*                COEFFICIENTS   [A] * |X| = |Y|                     */
/*                                                                   */
/*      INPUT  : THE NUMBER OF EQUATIONS  n                          */
/*               THE REAL MATRIX  A   should be A[i][j] but A[i*n+j] */
/*               THE REAL VECTOR  Y                                  */
/*      OUTPUT : THE REAL VECTOR  X                                  */
/*                                                                   */
/*      METHOD : GAUSS-JORDAN ELIMINATION USING MAXIMUM ELEMENT      */
/*               FOR PIVOT.                                          */
/*                                                                   */
/*      USAGE  :     simeq(n,A,Y,X);                                 */
/*                                                                   */
/*                                                                   */
/*    WRITTEN BY : JON SQUIRE , 28 MAY 1983                          */
/*    ORIGINAL DEC 1959 for IBM 650, TRANSLATED TO OTHER LANGUAGES   */
/*    e.g. FORTRAN converted to Ada converted to C                   */

    double *B;           /* [n][n+1]  WORKING MATRIX */
    int *ROW;            /* ROW INTERCHANGE INDICES */
    uint32_t HOLD , I_PIVOT;  /* PIVOT INDICES */
    double PIVOT;        /* PIVOT ELEMENT VALUE */
    double ABS_PIVOT;
    uint8_t i,j,k,m;

    B = (double *)calloc((n+1)*(n+1), sizeof(double));
    ROW = (int *)calloc(n, sizeof(int));
    m = n+1;

    /* BUILD WORKING DATA STRUCTURE */
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        B[i*m+j] = A[i*n+j];
      }
      B[i*m+n] = Y[i];
    }
    /* SET UP ROW  INTERCHANGE VECTORS */
    for(k=0; k<n; k++){
      ROW[k] = k;
    }

    /* BEGIN MAIN REDUCTION LOOP */
    for(k=0; k<n; k++){

      /* FIND LARGEST ELEMENT FOR PIVOT */
      PIVOT = B[ROW[k]*m+k];
      ABS_PIVOT = abs(PIVOT);
      I_PIVOT = k;
      for(i=k; i<n; i++){
        if( abs(B[ROW[i]*m+k]) > ABS_PIVOT){
          I_PIVOT = i;
          PIVOT = B[ROW[i]*m+k];
          ABS_PIVOT = abs ( PIVOT );
        }
      }

      /* HAVE PIVOT, INTERCHANGE ROW POINTERS */
      HOLD = ROW[k];
      ROW[k] = ROW[I_PIVOT];
      ROW[I_PIVOT] = HOLD;

      /* CHECK FOR NEAR SINGULAR */
      if( ABS_PIVOT < 1.0E-10 ){
        for(j=k+1; j<n+1; j++){
          B[ROW[k]*m+j] = 0.0;
        }
      } /* singular, delete row */
      else{

        /* REDUCE ABOUT PIVOT */
        for(j=k+1; j<n+1; j++){
          B[ROW[k]*m+j] = B[ROW[k]*m+j] / B[ROW[k]*m+k];
        }

        /* INNER REDUCTION LOOP */
        for(i=0; i<n; i++){
          if( i != k){
            for(j=k+1; j<n+1; j++){
              B[ROW[i]*m+j] = B[ROW[i]*m+j] - B[ROW[i]*m+k] * B[ROW[k]*m+j];
            }
          }
        }
      }
      /* FINISHED INNER REDUCTION */
    }

    /* END OF MAIN REDUCTION LOOP */
    /* BUILD  X  FOR RETURN, UNSCRAMBLING ROWS */
    for(i=0; i<n; i++){
      X[i] = B[ROW[i]*m+n];
    }
    free(B);
    free(ROW);
} /* end simeq */


void fit_file(int n, uint8_t version, double C[], ivrm_cal_data_t* cal_data)
{
  uint8_t i, j, k;
  int points;
  double y;
  double Vd, Vs;
  double x[30];        /* at least 2n */
  double A[2500];
  double Y[50];

  // -----------------------------------------------------------------------------------------
  // initialize harcoded values to use for Vs & Vg for version1
  //   version1 specifies Vd &Vs as uV and 16 bits is not enough to specify values about 65 mV
  // -----------------------------------------------------------------------------------------
  double Vs_v1[13];
  double Vd_v1[13];
   Vd_v1[0]  = 700;    Vs_v1[0]  = 888;
   Vd_v1[1]  = 831;    Vs_v1[1]  = 1033;
   Vd_v1[2]  = 787;    Vs_v1[2]  = 1033;
   Vd_v1[3]  = 718;    Vs_v1[3]  = 1033;
   Vd_v1[4]  = 962;    Vs_v1[4]  = 1179;
   Vd_v1[5]  = 918;    Vs_v1[5]  = 1179;
   Vd_v1[6]  = 850;    Vs_v1[6]  = 1179;
   Vd_v1[7]  = 750;    Vs_v1[7]  = 1179;
   Vd_v1[8]  = 1093;   Vs_v1[8]  = 1325;
   Vd_v1[9]  = 1050;   Vs_v1[9]  = 1325;
   Vd_v1[10] = 981;    Vs_v1[10] = 1325;
   Vd_v1[11] = 881;    Vs_v1[11] = 1325;
   Vd_v1[12] = 731;    Vs_v1[12] = 1325;

  points = cal_data->point_valid;

  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      A[i*n+j] = 0.0;
    }
    Y[i] = 0.0;
  }

  x[0]=1.0;

  for (k = 0; k <= points-1; k++) {

    if (version == 0) {
      Vd = Vd_v1[k];
      Vs = Vs_v1[k];
      y  = ((double)cal_data->point[k].drain_current)/1000;      // uA
    }
    else if (version == 1 || version == 2 || version == 3) {
      Vd = (double)cal_data->point[k].drain_voltage;             // mV
      Vs = (double)cal_data->point[k].source_voltage;            // mV
      y  = ((double)cal_data->point[k].drain_current)/1000;      // uA
    }
    else {                                                       //simulation data
      Vd = (double)cal_data->point[k].drain_voltage;             // mV
      Vs = (double)cal_data->point[k].source_voltage;            // mV
      y  = ((double)cal_data->point[k].drain_current)/1000;      // uA
    }

    x[1]=Vs/1.11;      // x[1] = target Vin = Vgs / 1.11
    x[2]=Vs/1.11-Vd;   // x[2] = target Vds = Vin/1.11 - Vout = Vs/1.11 - Vd
    x[3]=x[1]*x[2];    // x[3] = Vin*Vds

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        A[i*n+j] = A[i*n+j] + x[i]*x[j];
      }
      Y[i] = Y[i] + y*x[i];
    }
  }

  simeq(n, A, Y, C);

} /* end fit_file */

void write_HWtab_bin(ivrm_parm_data_t* i_ivrm_parms,
                      double C[],
                      PstateSuperStructure* pss)
{
  uint8_t i, j;
  double VIN_MIN;
  double VDS_MIN;
  double Vin[40]; /* at least 2n */
  double Vds[40];
  uint32_t    NUM_VIN;
  uint32_t    NUM_VDS;
  double LSB_CURRENT;
  double TEMP_UPLIFT;
  double Ical[40][40];
  double Iratio[40][40];
  double Iratio_clip;
  uint8_t Iratio_int[40][40];
  uint32_t temp;
  uint8_t ratio_val;
  uint8_t idx;

  NUM_VIN     = i_ivrm_parms->vin_entries_per_vds;
  NUM_VDS     = i_ivrm_parms->vds_region_entries;
  VIN_MIN     = 600;
  VDS_MIN     = 100;
  LSB_CURRENT = 4.1;
  TEMP_UPLIFT = 1.1;

  for(i=0; i<NUM_VIN; i++) { Vin[i] = VIN_MIN + i * 25; }

  Vds[0]=VDS_MIN;
  for(i=1; i<NUM_VDS; i++) {
     temp=(int) (Vds[i-1]*1.25/6.25);
     Vds[i] = temp*6.25 ;
  }

  for(i=0; i<NUM_VIN; i++) {
     for (j=0; j<NUM_VDS; j++) {
        if(Vin[i]-Vds[j]>=700) {
           Ical[i][j]   = C[0] + C[1]*Vin[i] + C[2]*Vds[j] + C[3]*Vin[i]*Vds[j]; // compute cal current
           Iratio[i][j] = TEMP_UPLIFT * LSB_CURRENT / Ical[i][j];

           // clip at 3.875 and use for both temp calculations
           Iratio_clip = (Iratio[i][j]+1/16>3.875 ? 3.875 : Iratio[i][j]+1/16);
// bug           temp = (int) (Iratio[i][j]+1/16>3.875 ? 3.875 : Iratio[i][j]+1/16);
           temp = (int) Iratio_clip;
           ratio_val = 0;
           ratio_val = (temp << 3) & 0x018;          // jwy shift temp left 3 and clear out lower 3 bits - this gets bits 0:1 of value
           temp = (int) ( (Iratio_clip - temp)*8 + 0.5);
           temp = temp > 7 ? 7 : temp;  // bug fix - clip to 7 if overflow
           ratio_val = (temp & 0x07)| ratio_val;     // jwy OR lower 3 bits of temp with upper 2 bits already in 0:1 - this merges bits 2:4 with 0:1 for final value
           Iratio_int[i][j] = ratio_val;
        } else {
           Iratio[i][j]     = 0;
           Iratio_int[i][j] = 0;
        }
     }
  }

  // fill in Vin table with Iratio data
  for (i=0; i<NUM_VDS; i++) {          // 16 rows

    for(j=0; j<4; j++) {               // 32 cols
      idx = (i*4) + j;
      pss->lpsa.vdsvin[idx].fields.pfet0 = Iratio_int[j*8][i];
      pss->lpsa.vdsvin[idx].fields.pfet1 = Iratio_int[(j*8)+1][i];
      pss->lpsa.vdsvin[idx].fields.pfet2 = Iratio_int[(j*8)+2][i];
      pss->lpsa.vdsvin[idx].fields.pfet3 = Iratio_int[(j*8)+3][i];
      pss->lpsa.vdsvin[idx].fields.pfet4 = Iratio_int[(j*8)+4][i];
      pss->lpsa.vdsvin[idx].fields.pfet5 = Iratio_int[(j*8)+5][i];
      pss->lpsa.vdsvin[idx].fields.pfet6 = Iratio_int[(j*8)+6][i];
      pss->lpsa.vdsvin[idx].fields.pfet7 = Iratio_int[(j*8)+7][i];

      // Byte reverse the entry into the image.
      pss->lpsa.vdsvin[idx].value = revle64(pss->lpsa.vdsvin[idx].value);
    }
  }
} /* end fit_file */


#ifdef __cplusplus
} // end extern C
#endif
