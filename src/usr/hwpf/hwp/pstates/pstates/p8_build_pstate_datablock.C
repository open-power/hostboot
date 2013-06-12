/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/p8_build_pstate_datablock.C $ */
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
// $Id: p8_build_pstate_datablock.C,v 1.14 2013/06/12 20:05:23 mjjones Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_build_pstate_datablock.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Jim Yacynych         Email: jimyac@us.ibm.com
// *!

/// \file p8_build_pstate_datablock.C
/// \brief
///
/// \todo
///   High-level procedure flow:
/// \verbatim
///
/// Procedure Prereq:
///   o System clocks are running
/// \endverbatim
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "pstate_tables.h"
#include "lab_pstates.h"
#include "pstates.h"

#include "p8_build_pstate_datablock.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------
ReturnCode proc_get_mvpd_data  (const Target& i_target, uint32_t attr_mvpd_data[PV_D][PV_W]);
ReturnCode proc_get_attributes (const Target& i_target, AttributeList *attr_list);
// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \param[in]      i_target           Chip Target
/// \param[in/out]  *io_pss            Reference to PstateSuperStructure

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

ReturnCode
p8_build_pstate_datablock(const Target& i_target, PstateSuperStructure *io_pss)
{
  fapi::ReturnCode l_rc;
  int rc;
  
  AttributeList attr;
  ChipCharacterization* characterization;
  uint8_t i           = 0;

  double freq_bias     = 1.0;
  double volt_bias_vdd = 1.0;
  double volt_bias_vcs = 1.0;

  uint32_t frequency_step_khz = 0;  
  uint32_t attr_mvpd_voltage_control[PV_D][PV_W];      
 
  FAPI_INF("Executing p8_build_pstate_datablock ....");
 
  // -------------------------
  // get all attributes needed
  // -------------------------
  l_rc = proc_get_attributes(i_target ,  &attr );
  if (l_rc) 
    return l_rc;
 
  // -----------
  // get #V data
  // -----------
  // clear array
  memset(attr_mvpd_voltage_control, 0, sizeof(attr_mvpd_voltage_control));
  
  l_rc = proc_get_mvpd_data(i_target ,  attr_mvpd_voltage_control);
  if (l_rc) 
    return l_rc;
    
  // ----------------------------------------------------
  // Check Valid Frequency and Voltage Biasing Attributes
  //  - cannot have both up and down bias set
  // ----------------------------------------------------
  if (attr.attr_freq_bias_up > 0 && attr.attr_freq_bias_down > 0) {
    FAPI_ERR("**** ERROR : Frequency bias up and down both defined");
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_FREQ_BIAS_ERROR);
    return l_rc;
  }

  if (attr.attr_voltage_ext_bias_up > 0 && attr.attr_voltage_ext_bias_down > 0) {
    FAPI_ERR("**** ERROR : External Frequency bias up and down both defined");
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_EXT_VOLTAGE_BIAS_ERROR);
    return l_rc;
  }

  if (attr.attr_voltage_int_bias_up > 0 && attr.attr_voltage_int_bias_down > 0) {
    FAPI_ERR("**** ERROR : Internal Frequency bias up and down both defined");
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_INT_VOLTAGE_BIAS_ERROR);
    return l_rc;
  }

  // --------------------------------------------------------------------
  // Apply specified Frequency and Voltage Biasing to attr_mvpd_voltage_control
  //   - convert freq/voltage to double
  //   - compute biased freq/voltage and round
  //   - convert back to integer
  //   - align frequency to frequency_step_khz (attr_freq_proc_refclock/attr_proc_dpll_divider)
  //   - are (double) and (int) required???
  // --------------------------------------------------------------------
  frequency_step_khz = (attr.attr_freq_proc_refclock*1000)/attr.attr_proc_dpll_divider;

  freq_bias     = 1.0 + (0.01 * (double)attr.attr_freq_bias_up)        - (0.01 * (double)attr.attr_freq_bias_down);         // at least one bias value is guaranteed to be 0
  volt_bias_vdd = 1.0 + (0.01 * (double)attr.attr_voltage_ext_bias_up) - (0.01 * (double)attr.attr_voltage_ext_bias_down);  // at least one bias value is guaranteed to be 0
  volt_bias_vcs = 1.0 + (0.01 * (double)attr.attr_voltage_ext_bias_up) - (0.01 * (double)attr.attr_voltage_ext_bias_down);  // at least one bias value is guaranteed to be 0

  // loop over each bucket
  for (i=0; i <= 4; i++) {
    attr_mvpd_voltage_control[i][0] = (uint32_t) ((( (double)attr_mvpd_voltage_control[i][0]) * freq_bias) + 0.5);

    // align to frequency step as defined by attr_proc_refclk_frequency/attr_proc_dpll_divider
    // jwy FIXME:caused float exception    attr_mvpd_voltage_control[i][0] = (attr_mvpd_voltage_control[i][0] + (frequency_step_khz - (attr_mvpd_voltage_control[i][0]%frequency_step_khz))%frequency_step_khz);

    attr_mvpd_voltage_control[i][1] = (uint32_t) ((( (double)attr_mvpd_voltage_control[i][1]) * volt_bias_vdd) + 0.5);    // vdd
    attr_mvpd_voltage_control[i][3] = (uint32_t) ((( (double)attr_mvpd_voltage_control[i][3]) * volt_bias_vcs) + 0.5);    // vcs
  }

  // -----------------------------------------------
  // populate VpdOperatingPoint with MVPD attributes
  // -----------------------------------------------
  // Assumes a constant 100mV dead zone
  VpdOperatingPoint s132a_vpd[S132A_POINTS];

  for (i = 0; i < S132A_POINTS; i++) {
    s132a_vpd[i].frequency_mhz  = attr_mvpd_voltage_control[pv_op_order[i]][0];
    s132a_vpd[i].vdd_5mv        = attr_mvpd_voltage_control[pv_op_order[i]][1];
    s132a_vpd[i].idd_500ma      = attr_mvpd_voltage_control[pv_op_order[i]][2];
    s132a_vpd[i].vdd_maxreg_5mv = attr_mvpd_voltage_control[pv_op_order[i]][1] - DEAD_ZONE_5MV;
    s132a_vpd[i].vcs_5mv        = attr_mvpd_voltage_control[pv_op_order[i]][3];
    s132a_vpd[i].ics_500ma      = attr_mvpd_voltage_control[pv_op_order[i]][4];
    s132a_vpd[i].vcs_maxreg_5mv = attr_mvpd_voltage_control[pv_op_order[i]][3] - DEAD_ZONE_5MV;
  }
  
  // -------------------------------------------------------------------
  // Create s132a_points and filled in by chip_characterization_create()
  // -------------------------------------------------------------------
  OperatingPoint s132a_points[S132A_POINTS];

  // -------------------------------------------------
  // populate OperatingPointParameters with attributes
  // -------------------------------------------------
  // Parameters from a P7 system, consistent with s132a. We'll assume the
  // package/header drop is 100uOhm for both Vdd and Vcs.

  OperatingPointParameters s132a_parms;
  s132a_parms.pstate0_frequency_khz = s132a_vpd[S132A_POINTS-1].frequency_mhz * 1000;   // pstate0 is turbo
  s132a_parms.frequency_step_khz    =  frequency_step_khz;                              // ATTR_REFCLK_FREQUENCY/ATTR_DPLL_DIVIDER
  
  s132a_parms.vdd_load_line_uohm    = 570;                           // hardcoded values to use temporarily per Adrian 4/11
  s132a_parms.vcs_load_line_uohm    = 570;                           // hardcoded values to use temporarily per Adrian 4/11
  s132a_parms.vdd_distribution_uohm = 500;                           // hardcoded values to use temporarily per Adrian 4/11
  s132a_parms.vcs_distribution_uohm = 800;                           // hardcoded values to use temporarily per Adrian 4/11 

  // --------------------------------------
  // Create Chip characterization structure
  // --------------------------------------

  ChipCharacterization s132a_characterization;
  s132a_characterization.vpd        = s132a_vpd;
  s132a_characterization.ops        = s132a_points;
  s132a_characterization.parameters = &s132a_parms;
  s132a_characterization.points     = S132A_POINTS;

  // ------------------------------
  // Clear the PstateSuperStructure and install the magic number
  // ------------------------------
  memset(io_pss, 0, sizeof(*io_pss));
  (*io_pss).magic = revle64(PSTATE_SUPERSTRUCTURE_MAGIC);

  // ---------------------------
  // Finish the characterization
  // ---------------------------
  characterization = &s132a_characterization;

  rc = chip_characterization_create(characterization,
                                    characterization->vpd,
                                    characterization->ops,
                                    characterization->parameters,
                                    characterization->points);

  if (rc) {
    int & RETURN_CODE = rc;
    FAPI_ERR("**** ERROR : Procedure chip_characterization_create() returned %d", rc);
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_CHIP_CHARACTERIZE_ERROR);
    return l_rc;
  }

  // ------------------------------
  // Create the Global Pstate table
  // ------------------------------
  rc = gpst_create(&((*io_pss).gpst),
                                characterization,
                                PSTATE_STEPSIZE,
                                EVRM_DELAY_NS);

  FAPI_DBG("gpst pmin = %d  gpst entries = %d", (*io_pss).gpst.pmin, (*io_pss).gpst.entries);
  FAPI_DBG("attr_freq_proc_refclock  = %d khz", (attr.attr_freq_proc_refclock*1000));
  FAPI_DBG("pstate0_freq = %d frequency_step = %d", s132a_parms.pstate0_frequency_khz, s132a_parms.frequency_step_khz);
  FAPI_DBG("vpd pmin = %d  vpd pmax = %d  vpd points = %d", s132a_characterization.ops[0].pstate, s132a_characterization.ops[s132a_characterization.points - 1].pstate, s132a_characterization.points);
   
  if (rc) {
    int & RETURN_CODE = rc;
    FAPI_ERR("**** ERROR : Procedure gpst_create() returned %d", rc);
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ERROR);
    return l_rc;
  }
 
// jwy  // ---------------------                                                                                
// jwy  // calculate safe_pstate                                                                                
// jwy  // ---------------------                                                                                
// jwy  Pstate psafe_pstate;                                                                                    
// jwy  rc = freq2pState(&((*io_pss).gpst), (attr.attr_pm_safe_frequency * 1000), &psafe_pstate);                                  
// jwy  
// jwy  if (rc) {                                                                                               
// jwy    fprintf(stderr, " freq2pState() returned %d\n", rc);                                                  
// jwy    exit(1);                                                                                              
// jwy  }                                                                                                       
// jwy                                                                                                          
// jwy  // pstate bounds checking                                                                               
// jwy  Pstate pmax;                                                                                            
// jwy  pmax = (*io_pss).gpst.pmin + (*io_pss).gpst.entries - 1;                                                            
// jwy  
// jwy  if (psafe_pstate > pmax) {                                                                              
// jwy    fprintf(stderr, " safe frequency pstate(%d) is greater than max pstate(%d)\n", psafe_pstate, pmax);   
// jwy    exit(1);                                                                                              
// jwy  }                                                                                                       
// jwy  
// jwy  if (psafe_pstate < (*io_pss).gpst.pmin)                                                                       
// jwy    psafe_pstate = (*io_pss).gpst.pmin;                                                                         
// jwy                                                                                                          
// jwy  (*io_pss).gpst.psafe = psafe_pstate;                                                                          
// jwy                                                                                                          
// jwy  // -----------------------                                                                              
// jwy  // calculate pvsafe pstate                                                                              
// jwy  // -----------------------                                                                              
// jwy  Pstate       pvsafe_pstate;                                                                             
// jwy  Vid11        pvsafe_vrm11;                                                                              
// jwy  gpst_entry_t entry;                                                                                     
// jwy                                                                                                          
// jwy  rc = vuv2vrm11((attr.attr_pm_safe_voltage*1000), 1, &pvsafe_vrm11);              // assume attr_pm_safe_voltage is in millivolts                                                   
// jwy  rc = gpst_vdd2pstate(&((*io_pss).gpst), pvsafe_vrm11, &pvsafe_pstate, &entry);                                
// jwy  (*io_pss).gpst.pvsafe = pvsafe_pstate;                                                                        


  
  // Force optional overrides
  (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)   |
                                                PSTATE_NO_INSTALL_LPSA   |
                                                PSTATE_NO_INSTALL_RESCLK |
                                                PSTATE_FORCE_INITIAL_PMIN);
  // ------------------------------
  // Create the Global Pstate table
  // ------------------------------
  rc = lpst_create( &((*io_pss).gpst), &((*io_pss).lpsa), DEAD_ZONE_5MV);
 
  if (rc) {
//    int & RETURN_CODE = rc;
    FAPI_ERR("**** ERROR : Procedure lpst_create() returned %d", rc);
 //   FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ERROR);
 //   return l_rc;
  }                                
  
  // print global pstate table                              
// jwy  gpst_print(stdout, &(*io_pss).gpst);

//  Attributes to write
//  -------------------
//  uint32_t ATTR_PM_PSTATE0_FREQUENCY // Binary in Khz

  return l_rc;
}



/// \brief Get needed attributes
/// \param[in]    i_target          => Chip Target
/// \param[inout] attr              => pointer to attribute list structure

ReturnCode proc_get_attributes(const Target& i_target, AttributeList *attr) {
  ReturnCode l_rc;

  // --------------------------
  // attributes not yet defined
  // --------------------------
   attr->attr_dpll_bias              = 0;
   attr->attr_undervolting           = 0;
   attr->attr_freq_bias_up           = 0;
   attr->attr_freq_bias_down         = 0;
   attr->attr_voltage_ext_bias_up    = 0;
   attr->attr_voltage_ext_bias_down  = 0;
   attr->attr_voltage_int_bias_up    = 0;
   attr->attr_voltage_int_bias_down  = 0;
   
   attr->attr_dpll_bias              = 0;
   attr->attr_undervolting           = 0;
   attr->attr_pm_safe_voltage        = 925;    // assume millivolts until it is defined in attraibute
   attr->attr_proc_dpll_divider      = 4;

  l_rc = FAPI_ATTR_GET(ATTR_FREQ_PROC_REFCLOCK,      NULL, attr->attr_freq_proc_refclock); if (l_rc) return l_rc;
// jwy  l_rc = FAPI_ATTR_GET(ATTR_PROC_DPLL_DIVIDER,       NULL, attr->attr_proc_dpll_divider);  if (l_rc) return l_rc;
  l_rc = FAPI_ATTR_GET(ATTR_FREQ_CORE_MAX,           NULL, attr->attr_freq_core_max);      if (l_rc) return l_rc;
  l_rc = FAPI_ATTR_GET(ATTR_PROC_R_LOADLINE,         NULL, attr->attr_proc_r_loadline);    if (l_rc) return l_rc;
  l_rc = FAPI_ATTR_GET(ATTR_PROC_R_DISTLOSS,         NULL, attr->attr_proc_r_distloss);    if (l_rc) return l_rc;
  l_rc = FAPI_ATTR_GET(ATTR_PROC_VRM_VOFFSET,        NULL, attr->attr_proc_vrm_voffset);   if (l_rc) return l_rc;

  l_rc = FAPI_ATTR_GET(ATTR_PM_SAFE_FREQUENCY,       NULL, attr->attr_pm_safe_frequency);  if (l_rc) return l_rc;

   l_rc = FAPI_ATTR_GET(ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY, NULL, attr->attr_pm_resonant_clock_full_clock_sector_buffer_frequency); if (l_rc) return l_rc;
   l_rc = FAPI_ATTR_GET(ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY,           NULL, attr->attr_pm_resonant_clock_low_band_lower_frequency);           if (l_rc) return l_rc;
   l_rc = FAPI_ATTR_GET(ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY,           NULL, attr->attr_pm_resonant_clock_low_band_upper_frequency);           if (l_rc) return l_rc;
   l_rc = FAPI_ATTR_GET(ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY,          NULL, attr->attr_pm_resonant_clock_high_band_lower_frequency);          if (l_rc) return l_rc;
   l_rc = FAPI_ATTR_GET(ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY,          NULL, attr->attr_pm_resonant_clock_high_band_upper_frequency);          if (l_rc) return l_rc;
  
  return l_rc;
}

/// \brief Get #V data and put into array
/// \param[in]    i_target          => Chip Target
/// \param[inout] attr_mvpd_data    => 5x5 array to hold the #V data

ReturnCode proc_get_mvpd_data(const Target& i_target, uint32_t attr_mvpd_data[PV_D][PV_W]) {
  ReturnCode l_rc;
  std::vector<fapi::Target>       l_exChiplets;
  uint8_t                         l_functional = 0;  
  uint8_t * l_buffer    =  reinterpret_cast<uint8_t *>(malloc(512) );
  uint32_t l_bufferSize = 512;
  uint32_t l_record     = 0;
  uint32_t chiplet_mvpd_data[PV_D][PV_W];
  uint8_t j           = 0;
  uint8_t i           = 0;
  uint8_t ii          = 0;
  uint8_t first_chplt = 1;

  // -----------------------------------------------------------------
  // get list of chiplets and loop over each and get #V data from each
  // -----------------------------------------------------------------
  // check that frequency is the same per chiplet
  // for voltage, get the max for use for the chip

  l_rc = fapiGetChildChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_exChiplets, TARGET_STATE_PRESENT);
  if (l_rc) {
    FAPI_ERR("Error from fapiGetChildChiplets!");
    return l_rc;
  }

  for (j=0; j < l_exChiplets.size(); j++) {

    // Determine if it's functional
    l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[j], l_functional);
    if (l_rc) {
      FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
      return l_rc;
    }
    else {

      if ( l_functional ) {
        l_bufferSize = 512;
        uint8_t l_chipNum = 0xFF;
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_chipNum);
        if (l_rc) {
          FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
          return l_rc;
        }

        // set l_record to appropriate lprx record (add core number to lrp0)
        l_record = (uint32_t)fapi::MVPD_RECORD_LRP0 + l_chipNum;

        // Get Chiplet MVPD data and put in chiplet_mvpd_data using accessor function
        l_rc = fapiGetMvpdField((fapi::MvpdRecord)l_record,
                                fapi::MVPD_KEYWORD_PDV,
                                i_target,
                                l_buffer,
                                l_bufferSize);
        if (!l_rc.ok()) {
          FAPI_ERR("**** ERROR : Unexpected error encountered in fapiGetMvpdField");
          return l_rc;
        }

        // check buffer size
        if (l_bufferSize < MVPD_BUFFER_SIZE) {
          FAPI_ERR("**** ERROR : Worng size buffer returned from fapiGetMvpdField => %d", l_bufferSize );
          FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_MVPD_BUFFER_SIZE_ERROR);
          return l_rc;
        }

        // clear array
        memset(chiplet_mvpd_data, 0, sizeof(chiplet_mvpd_data));

        // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
        #define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))
        l_buffer++;

        for (i=0; i<=4; i++) {

          for (ii=0; ii<=4; ii++) {
            chiplet_mvpd_data[i][ii] = (uint32_t) UINT16_GET(l_buffer);
            FAPI_DBG("%04X  %-6d", chiplet_mvpd_data[i][ii], chiplet_mvpd_data[i][ii]);  
            // increment to next MVPD value in buffer
            l_buffer+= 2;
          }
        }

        // on first chiplet put each bucket's data into attr_mvpd_voltage_control
        if (first_chplt) {

          for (i=0; i<=4; i++) {

            for (ii=0; ii<=4; ii++) {
              attr_mvpd_data[i][ii] = chiplet_mvpd_data[i][ii];
            }
          }
          first_chplt = 0;
        }
        else {
          // on subsequent chiplets, check that frequencies are same for each bucket for each chiplet
          if ( (attr_mvpd_data[0][0] != chiplet_mvpd_data[0][0]) ||
               (attr_mvpd_data[1][0] != chiplet_mvpd_data[1][0]) ||
               (attr_mvpd_data[2][0] != chiplet_mvpd_data[2][0]) ||
               (attr_mvpd_data[3][0] != chiplet_mvpd_data[3][0]) ||
               (attr_mvpd_data[4][0] != chiplet_mvpd_data[4][0]) ) {

            FAPI_ERR("**** ERROR : Procedure gpst_create() returned ");
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_MVPD_CHIPLET_VOLTAGE_NOT_EQUAL);
            return l_rc;
          }
        }

        // check each bucket for max voltage and if max, put bucket's data into attr_mvpd_voltage_control
        for (i=0; i <= 4; i++) {

          if (attr_mvpd_data[i][1] < chiplet_mvpd_data[i][1]) {
            attr_mvpd_data[i][0] = chiplet_mvpd_data[i][0];
            attr_mvpd_data[i][1] = chiplet_mvpd_data[i][1];
            attr_mvpd_data[i][2] = chiplet_mvpd_data[i][2];
            attr_mvpd_data[i][3] = chiplet_mvpd_data[i][3];
            attr_mvpd_data[i][4] = chiplet_mvpd_data[i][4];
          }
        }
      } // end if l_functional
      else {            // Not Functional so skip it
      }
    }
  } // end for loop

  return l_rc;

} // end proc_get_mvpd_data


} //end extern C

