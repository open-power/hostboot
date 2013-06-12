/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/pstate_tables.c $            */
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
// $Id: pstate_tables.c,v 1.8 2013/06/12 20:02:07 mjjones Exp $

/// \file pstate_tables.c
/// \brief This file contains code used to generate Pstate tables from real or
/// imagined chip characterizations.
///
/// This code is never run as part of OCC firmware, as Pstate tables are
/// always "given" to OCC either from the FSP (OCC product firmware), or by
/// being built-in the image (lab images).

#include <stdint.h>
#include <stdio.h>
#include "lab_pstates.h"
#include "pstate_tables.h"


#define MAX(X, Y)                               \
    ({                                          \
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
                 int points)
{
    int rc, i;
    uint32_t pstate0_code;
    uint8_t  gpst_points           = 0;   // jwy
    uint32_t curr_pstate_code      = 0;   // jwy
    uint32_t next_pstate_code      = 0;   // jwy

    
    do {
        rc = 0;

        if ((characterization == 0) || (parameters == 0)) {
            rc = -GPST_INVALID_OBJECT;
            break;
        }
        if ((vpd == 0) || (points <= 0)) {
            rc = -GPST_INVALID_ARGUMENT;
            break;
        }

        characterization->vpd        = vpd;
        characterization->ops        = ops;
        characterization->parameters = parameters;
        characterization->points     = points;

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

            // jwy skip vpd point if next point is at same pstate
            curr_pstate_code = vpd[i].frequency_mhz * 1000 / parameters->frequency_step_khz;
            if (i < points - 1) {  
              next_pstate_code = vpd[i+1].frequency_mhz * 1000 / parameters->frequency_step_khz;
            }
            
            if (i < points - 1 && (curr_pstate_code == next_pstate_code)) {
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
                ((ops[gpst_points].idd_ma * (parameters->vdd_load_line_uohm + parameters->vdd_distribution_uohm)) / 1000); // jwy add in distribution_uohm

            ops[gpst_points].vcs_corrected_uv =
                ops[gpst_points].vcs_uv +
                ((ops[gpst_points].ics_ma * (parameters->vcs_load_line_uohm + parameters->vcs_distribution_uohm)) / 1000); // jwy add in distribution_uohm

            // iVRM 'Effective' voltages are set to the measured voltages

            ops[gpst_points].vdd_ivrm_effective_uv = ops[gpst_points].vdd_uv;
            ops[gpst_points].vcs_ivrm_effective_uv = ops[gpst_points].vcs_uv;

            ops[gpst_points].pstate =
                (ops[gpst_points].frequency_khz / parameters->frequency_step_khz) -
                pstate0_code;

            gpst_points++;
        }
        
        // jwy set points to adjusted number of points (ie. if vpd point was skipped due to being same pstate
        // jwy as next vpd point
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

#define NEST_FREQUENCY_KHZ 2400000

int
gpst_stepping_setup(GlobalPstateTable* gpst,
                    int pstate_stepsize,
                    int vrm_delay_ns)
{
    uint32_t cycles;
    int rc, sigbits, stepdelay_range, stepdelay_value;

    do {
        rc = 0;

        if ((pstate_stepsize <= 0) ||
            (pstate_stepsize > PSTATE_STEPSIZE_MAX) ||
            (vrm_delay_ns < 0) ||
            (vrm_delay_ns > VRM_STEPDELAY_MAX)) {
            rc = -GPST_INVALID_ARGUMENT;
            break;
        }

        // Compute the number of pervasive / 2 cycles implied by the delay.
        // This is the frequency of the VRM stepper 'tick'. The base time
        // source for VRM stepping is therefore nest clock / 8.

        cycles = (((NEST_FREQUENCY_KHZ / 1000) * vrm_delay_ns) / 1000) /
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
            rc = -GPST_INVALID_ARGUMENT;
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
// jwy    int32_t vcs_offset;
// jwy    uint32_t vdd_uv;
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

        // Add the check byte

        uint8_t gpstCheckByte(uint64_t gpstEntry);
        gpe.fields.ecc = gpstCheckByte(gpe.value);

    } while (0);

    // Byte reverse the entry into the image.

    entry->value = revle64(gpe.value);
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
            int pstate_stepsize,
            int evrm_delay_ns)
{
    OperatingPoint *ops, interp;
    int rc, points, i, entry, pstate;
    int32_t pmin, pmax;
    uint8_t fNom;

    do {
        rc = 0;

        // Basic pointer checks

        if ((gpst == 0) || (characterization == 0)) {
            rc = -GPST_INVALID_OBJECT;
            break;
        }

        // Check for null or illegal operating point tables

        ops    = characterization->ops;
        points = characterization->points;

        if ((ops == 0) || (points <= 0)) {
            rc = -GPST_INVALID_OBJECT;
            break;
        }

        pmin = ops[0].pstate;
        pmax = ops[points - 1].pstate;

        // Check that the range of Pstates are legal and will actually fit in
        // the table. 'Fitting' will never be a problem for PgP as long as the
        // table of operating points does not include operating points for
        // frequencies below Fmax@Vmin.

        if ((pmin < PSTATE_MIN) ||
            (pmax > PSTATE_MAX) ||
            ((pmax - pmin + 1) > GLOBAL_PSTATE_TABLE_ENTRIES)) {
            rc = -GPST_INVALID_ARGUMENT;
            break;
        }

        // Check the ordering constraints

       for (i = 1; i < points; i++) {
       
            if ((ops[i].pstate < ops[i - 1].pstate)  ||
                (ops[i].vdd_uv < ops[i - 1].vdd_uv) ||    // jwy allow them to be equal
                (ops[i].vcs_uv < ops[i - 1].vcs_uv)) {    // jwy allow them to be equal
                rc = -GPST_INVALID_ARGUMENT;
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

        gpst->pmin    = pmin;
        gpst->entries = pmax - pmin + 1;
 
        // Set the Pmin Pstate

        entry = 0;
        if (gpst_entry_create(&(gpst->pstate[entry]), &(ops[0]))) {
            rc = -GPST_INVALID_ENTRY;
            break;
        }
        entry++;
        pstate = pmin;

        // Iterate over characterized operating points...
       for (i = 1; i < points; i++) {

            // Interpolate intermediate Pstates...
            while (++pstate != ops[i].pstate) {

                interp.pstate = pstate;

#define __INTERPOLATE(field)                                            \
                do {                                                    \
                    interp.field =                                      \
                        interpolate(ops[i - 1].field, ops[i].field,     \
                                    (pstate - ops[i - 1].pstate),    \
                                    (ops[i].pstate - ops[i - 1].pstate)); \
                } while (0)

                __INTERPOLATE(vdd_corrected_uv);
                __INTERPOLATE(vcs_corrected_uv);
                __INTERPOLATE(vdd_ivrm_effective_uv);
                __INTERPOLATE(vcs_ivrm_effective_uv);
                __INTERPOLATE(vdd_maxreg_uv);
                __INTERPOLATE(vcs_maxreg_uv);

                if (gpst_entry_create(&(gpst->pstate[entry]), &interp)) {
                    rc = - GPST_INVALID_ENTRY;
                    break;
                }
                entry++;
            }
            if (rc) break;

            // Set the characterized Pstate
           if (gpst_entry_create(&(gpst->pstate[entry]), &(ops[i]))) {
                rc = -GPST_INVALID_ENTRY;
                break;
            }
            entry++;
        }
        if (rc) break;

        // Fill in the defaults

        gpst->pvsafe = gpst->pmin;

        fNom = revle32(gpst->pstate0_frequency_khz) /
            revle32(gpst->frequency_step_khz);

        for (i = 0; i < PGP_NCORES; i++) {
            gpst->pstate0_frequency_code[i] = revle16(fNom);
            gpst->dpll_fmax_bias[i] = 0;
        }

    } while (0);

    return rc;
}



int
lpst_create(const GlobalPstateTable *gpst, LocalPstateArray *lpsa, const uint8_t dead_zone_5mv)
{            
  int          rc = 0;
  int          i,j;
  gpst_entry_t  entry;
  uint32_t      turbo_uv;              
  uint32_t      v_uv;                  
  uint32_t      vdd_uv;                
  uint8_t       v_ivid;                
  uint32_t      lpst_max_uv;           
  uint8_t       lpst_entries;          
  uint8_t       lpst_entries_div4;          
  uint8_t       gpst_index;            
  Pstate        lpst_pmin;             
  uint8_t       vid_incr[3] = {0,0,0}; 
    
  do {
  
    // Basic pointer checks                            
    if (lpsa == 0) {
      rc = -LPST_INVALID_OBJECT;                    
      break;                                        
    }                                                 
  
    // ------------------------------------------------------------------   
    // find lspt_max in gpst
    //  - lpst_max is gpst entry that is equal to (turbo_vdd - deadzone)
    // ------------------------------------------------------------------
    entry.value = revle64(gpst->pstate[(gpst->entries)-1].value); 
    rc          = vrm112vuv(entry.fields.evid_vdd, &turbo_uv);
    lpst_max_uv = turbo_uv - (dead_zone_5mv * 5000);     
          
    for (i = gpst->entries -1 ; i >= 0; i--) {
       entry.value = revle64(gpst->pstate[i].value);   
       vrm112vuv(entry.fields.evid_vdd, &v_uv);
       
       if (lpst_max_uv >= v_uv)
         break;
    }

    lpst_entries = i + 1;
    lpst_pmin    = 0 - lpst_entries + 1;
    
// jwy    printf("turbo_uv = %d lpst_max_uv = %d entries = %d lpst_pmin = %d\n", turbo_uv, lpst_max_uv, lpst_entries, lpst_pmin);
    
    // ----------------------------------------------------------------------------
    // now loop over gpst from 0 to lpst_entries and fill in lpst from data in gpst
    // ----------------------------------------------------------------------------
    gpst_index = 0;

    lpst_entries_div4 = lpst_entries/4;    
    if ( lpst_entries % 4 != 0)
       lpst_entries_div4++;

    for (i = 0 ; i < lpst_entries_div4; i++) {
      entry.value = revle64(gpst->pstate[gpst_index].value);
         
      // compute ivid_vdd
      rc = vrm112vuv(entry.fields.evid_vdd, &vdd_uv);
      rc = vuv2ivid(vdd_uv, ROUND_VOLTAGE_DOWN, &v_ivid);
      lpsa->pstate[i].fields.ivid_vdd = v_ivid;
      
      // compute ivid_vcs
      rc = vrm112vuv(entry.fields.evid_vcs, &v_uv);
      rc = vuv2ivid(v_uv, ROUND_VOLTAGE_DOWN, &v_ivid);
      lpsa->pstate[i].fields.ivid_vcs = v_ivid;       
      
      // --------------------------------------------------------------
      // compute increment for remaining 3 pstates for this lpst entry 
      // --------------------------------------------------------------               
      vid_incr[0] = 0; 
      vid_incr[1] = 0;
      vid_incr[2] = 0;
      
      for (j = 0; j <= 2; j++) {
        gpst_index++;
        if (gpst_index > lpst_entries)
          break; 
        
        entry.value = revle64(gpst->pstate[gpst_index].value);
        rc          = vrm112vuv(entry.fields.evid_vdd, &vdd_uv);
        rc          = vuv2ivid(vdd_uv, ROUND_VOLTAGE_DOWN, &v_ivid);
        vid_incr[j] = v_ivid - lpsa->pstate[i].fields.ivid_vdd;
      }
      
      lpsa->pstate[i].fields.ps1_vid_incr = vid_incr[0]; 
      lpsa->pstate[i].fields.ps2_vid_incr = vid_incr[1];  
      lpsa->pstate[i].fields.ps3_vid_incr = vid_incr[2];  
      
      // --------------------
      // compute power ratios
      // -------------------- 
      float  sigma = 0;
      float  iac_wc;
      float  iac;
      float  vout;
      float  pwrratio_f;
      uint8_t pwrratio;
      
      // convert to mV (note: vdd_uv is the max of the vdd values for this lpst entry)
      vout = (float)(vdd_uv/1000); 
            
      // equations from Josh
      iac_wc     = 1.25 * ( 28.5 * 1.25 - 16 ) * ( 1 - 0.05 * 2) * 40/71;        // testsite equation & ratio of testsite to anticipated produ
      iac        = 1.25 * (-15.78 -0.618 * sigma + 27.6 * vout/1000) * 40/64;  // product equation & ratio of testsite to actual product
      pwrratio_f = iac / iac_wc;
      pwrratio   = (uint8_t)((pwrratio_f*64) + 0.5);
      
      lpsa->pstate[i].fields.vdd_core_pwrratio = pwrratio;   
      lpsa->pstate[i].fields.vcs_core_pwrratio = pwrratio;   
      lpsa->pstate[i].fields.vdd_eco_pwrratio  = pwrratio;   
      lpsa->pstate[i].fields.vcs_eco_pwrratio  = pwrratio;   

      // ??? what should these be ??? set to 1 for now 
      lpsa->pstate[i].fields.inc_step = 1;
      lpsa->pstate[i].fields.dec_step = 1;

// jwy      printf (" %d %X %X %f %d %d %d %d\n", i, (uint32_t)lpsa->pstate[i].fields.ivid_vdd, (uint32_t)lpsa->pstate[i].fields.ivid_vcs, pwrratio_f, pwrratio, vid_incr[0], vid_incr[1], vid_incr[2]);

      // Byte reverse the entry into the image.
      lpsa->pstate[i].value = revle64(lpsa->pstate[i].value);
      
      gpst_index++;
      if (gpst_index > lpst_entries)
        break; 
    }

    // set these fields in lpst structure    
    lpsa->pmin    = lpst_pmin;
    lpsa->entries = lpst_entries;
 
  } while (0);               

  return rc;            
                      
} // end lpst_create        
