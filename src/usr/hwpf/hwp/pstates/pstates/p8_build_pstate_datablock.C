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
// $Id: p8_build_pstate_datablock.C,v 1.24 2013/10/30 17:35:53 jimyac Exp $
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
ReturnCode proc_get_mvpd_data    (const Target& i_target, uint32_t attr_mvpd_data[PV_D][PV_W], ivrm_mvpd_t *ivrm_mvpd, uint8_t *present_chiplets, uint8_t *functional_chiplets);
ReturnCode proc_get_attributes   (const Target& i_target, AttributeList *attr_list);
ReturnCode proc_get_extint_bias  (uint32_t attr_mvpd_data[PV_D][PV_W], const AttributeList *attr, double *volt_int_vdd_bias, double *volt_int_vcs_bias);
ReturnCode proc_boost_gpst       (PstateSuperStructure *pss, uint32_t attr_boost_percent);
ReturnCode proc_upd_cpmrange     (PstateSuperStructure *pss, const AttributeList *attr);
ReturnCode proc_chk_valid_poundv (const uint32_t chiplet_mvpd_data[PV_D][PV_W], uint8_t chiplet_num, uint8_t bucket_id);
ReturnCode proc_res_clock        (PstateSuperStructure *pss, AttributeList *attr_list);
// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \param[in]      i_target           Chip Target
/// \param[in/out]  *io_pss            Reference to PstateSuperStructure

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

ReturnCode
p8_build_pstate_datablock(const Target& i_target,
                          PstateSuperStructure *io_pss)
{
  fapi::ReturnCode l_rc;
  int rc;

  AttributeList attr;
  ChipCharacterization* characterization;
  uint8_t i                   = 0;
  uint8_t present_chiplets    = 0;
  uint8_t functional_chiplets = 0;

  const uint8_t pv_op_order[S132A_POINTS] = PV_OP_ORDER;

  double volt_int_vdd_bias = 1.0;
  double volt_int_vcs_bias = 1.0;

  uint32_t frequency_step_khz = 0;
  uint32_t attr_mvpd_voltage_control[PV_D][PV_W];

  ivrm_mvpd_t ivrm_mvpd;

  FAPI_INF("Executing p8_build_pstate_datablock ....");

  do
  {

    // -----------------------------------------------------------
    // Clear the PstateSuperStructure and install the magic number
    // -----------------------------------------------------------
    memset(io_pss, 0, sizeof(*io_pss));
    (*io_pss).magic = revle64(PSTATE_SUPERSTRUCTURE_MAGIC);

    // -------------------------
    // get all attributes needed
    // -------------------------
    FAPI_IMP("Getting Attributes to build Pstate Superstructure");

    l_rc = proc_get_attributes(i_target ,  &attr );
    if (l_rc) break;

    // calculate pstate frequency step in Khz
    frequency_step_khz = (attr.attr_freq_proc_refclock * 1000)/attr.attr_proc_dpll_divider;

    // ----------------
    // get #V & #M data
    // ----------------
    FAPI_IMP("Getting #V & #M Data");

    // clear array
    memset(attr_mvpd_voltage_control, 0, sizeof(attr_mvpd_voltage_control));
    memset(&ivrm_mvpd,                0, sizeof(ivrm_mvpd));

    l_rc = proc_get_mvpd_data(i_target, attr_mvpd_voltage_control, &ivrm_mvpd, &present_chiplets, &functional_chiplets);
    if (l_rc) {
      break;
    }
    else if (present_chiplets == 0) {
      FAPI_ERR("**** ERROR : There are no cores present");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_NO_CORES_PRESENT_ERROR);
      break;
    }
    else if (functional_chiplets == 0) {
      FAPI_IMP("No FUNCTIONAL chiplets found - local pstate data is not valid");
      // indicate not LPST installed in PSS
      (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options) |
                                       PSTATE_NO_INSTALL_LPSA);
    }

    // ---------------------------------------------
    // process external and internal bias attributes
    // ---------------------------------------------
    FAPI_IMP("Apply Biasing to #V");

    l_rc = proc_get_extint_bias(attr_mvpd_voltage_control, &attr, &volt_int_vdd_bias, &volt_int_vcs_bias);
    if (l_rc) break;

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
    s132a_parms.pstate0_frequency_khz = ((s132a_vpd[S132A_POINTS-1].frequency_mhz * 1000) / frequency_step_khz) * frequency_step_khz;   // pstate0 is turbo rounded down and forced to be a multiple of freq_step_khz
    s132a_parms.frequency_step_khz    =  frequency_step_khz;                                                                            // ATTR_REFCLK_FREQUENCY/ATTR_DPLL_DIVIDER
    s132a_parms.vdd_load_line_uohm    = attr.attr_proc_r_loadline_vdd;
    s132a_parms.vcs_load_line_uohm    = attr.attr_proc_r_loadline_vcs;
    s132a_parms.vdd_distribution_uohm = attr.attr_proc_r_distloss_vdd;
    s132a_parms.vcs_distribution_uohm = attr.attr_proc_r_distloss_vcs;

    // --------------------------------------
    // Create Chip characterization structure
    // --------------------------------------

    ChipCharacterization s132a_characterization;
    s132a_characterization.vpd        = s132a_vpd;
    s132a_characterization.ops        = s132a_points;
    s132a_characterization.parameters = &s132a_parms;
    s132a_characterization.points     = S132A_POINTS;

    // ---------------------------
    // Finish the characterization
    // ---------------------------
    characterization = &s132a_characterization;

    rc = chip_characterization_create(characterization,
                                      characterization->vpd,
                                      characterization->ops,
                                      characterization->parameters,
                                      characterization->points);

    // check for error
    int & CHAR_RETURN_CODE = rc;
    if (rc == -GPST_INVALID_OBJECT) {
      FAPI_ERR("**** ERROR : chip_characterization_create was passed null pointer to characterization or characterization->parameters");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_CHARACTERIZATION_OBJECT_ERROR);
      break;
    }
    else if (rc == -GPST_INVALID_ARGUMENT) {
      int & POINTS  = characterization->points;
      FAPI_ERR("**** ERROR : chip_characterization_create was passed null pointer to characterization->vpd or no points");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_CHARACTERIZATION_ARGUMENT_ERROR);
      break;
    }
    else if (rc) {
      FAPI_ERR("**** ERROR : chip_characterization_create returned error rc = %d", rc );
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_CHARACTERIZATION_ERROR);
      break;
    }

    // ------------------------------
    // Create the Global Pstate table
    // ------------------------------
    FAPI_IMP("Creating Global Pstate Table");

    rc = gpst_create(&((*io_pss).gpst),
                     characterization,
                     PSTATE_STEPSIZE,
                     EVRM_DELAY_NS);

    FAPI_INF("GPST vpd pmin = %d  vpd pmax = %d  vpd points = %d", s132a_characterization.ops[0].pstate, s132a_characterization.ops[s132a_characterization.points - 1].pstate, s132a_characterization.points);
    FAPI_INF("GPST pmin = %d  entries = %u", (*io_pss).gpst.pmin, (*io_pss).gpst.entries);
    FAPI_INF("GPST refclock(Mhz) = %d  pstate0_freq(Khz) = %d  frequency_step(Khz) = %d", attr.attr_freq_proc_refclock, s132a_parms.pstate0_frequency_khz, s132a_parms.frequency_step_khz);

    // check for error
    int & GPST_RETURN_CODE = rc;
    if (rc == -GPST_INVALID_OBJECT) {
      FAPI_ERR("**** ERROR : gpst_create was passed null pointer to gpst, characterization, or characterization->ops or characterization->points = 0");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_OBJECT_ERROR);
      break;
    }
    else if (rc == -GPST_INVALID_ARGUMENT) {
      int32_t & OPS_PMIN           = s132a_characterization.ops[0].pstate;
      int32_t & OPS_PMAX           = s132a_characterization.ops[s132a_characterization.points - 1].pstate;
      FAPI_ERR("**** ERROR : gpst_create was passed bad argument and resulted in PSTATE limits error or operating point ordering error");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ARGUMENT_ERROR);
      break;
    }
    else if (rc == -GPST_INVALID_ENTRY) {
      FAPI_ERR("**** ERROR : gpst_entry_create was passed a voltage that was out of limits of vrm11 vid code or ivid vide code");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ENTRY_ERROR);
      break;
    }
    else if (rc) {
      FAPI_ERR("**** ERROR : gpst_create returned error rc = %d", rc );
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ERROR);
      break;
    }

    // -----------------------------
    // Boost the Global Pstate table
    // -----------------------------
    FAPI_IMP("Boost Global Pstate Table per CPM Boost Attribute");

    l_rc = proc_boost_gpst (io_pss, attr.attr_cpm_turbo_boost_percent);
    if (l_rc) break;

    // -----------------------------------------------------------------
    // calculate safe_pstate & pvsafe pstate from attr_pm_safe_frequency
    // -----------------------------------------------------------------
//   jwy   Pstate psafe_pstate;
//   jwy   rc = freq2pState(&((*io_pss).gpst), (attr.attr_pm_safe_frequency * 1000), &psafe_pstate);
//   jwy
//   jwy   if (rc) {
//   jwy     fprintf(stderr, " freq2pState() returned %d\n", rc);
//   jwy     exit(1);
//   jwy   }
//   jwy
//   jwy   rc = pstate_minmax_chk(&(pss->gpst), &psafe_pstate);
//   jwy
//   jwy   (*io_pss).gpst.psafe  = psafe_pstate;
//   jwy   (*io_pss).gpst.pvsafe = psafe_pstate;

    // -----------------------------
    // Create the Local Pstate table
    // -----------------------------
    FAPI_IMP("Creating Local Pstate Table");

    rc = lpst_create( &((*io_pss).gpst), &((*io_pss).lpsa), DEAD_ZONE_5MV, volt_int_vdd_bias, volt_int_vcs_bias);

    int & LPST_RETURN_CODE = rc;
    if (rc == -LPST_INVALID_OBJECT) {
      FAPI_ERR("**** ERROR : lpst_create was passed null pointer to gpst or lpsa");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_OBJECT_ERROR);
      break;
    }
    else if (rc == -IVID_INVALID_VOLTAGE) {
      FAPI_ERR("**** ERROR : lpst_create attempted to convert an invalid voltage value to ivid format (GT 1.39375V or LT 0.6V");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_IVID_ERROR);
      break;
    }
    else if (rc == -LPST_GPST_WARNING) {
      FAPI_IMP("No Local Pstate Generated  - Global Pstate Table is completely within Deadzone" );

      // indicate not LPST installed in PSS
      (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options) |
                                       PSTATE_NO_INSTALL_LPSA);
    }
    else if (rc) {
      FAPI_ERR("**** ERROR : lpst_create returned error rc = %d", rc );
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_ERROR);
      break;
    }

    // -----------------------
    // Create VDS & VIN tables
    // -----------------------
    FAPI_IMP("Create VDS & VIN Tables");

    ivrm_parm_data_t        ivrm_parms;

    // Set defaults
    ivrm_parms.vin_min                   = 600;        // Minimum input voltage
    ivrm_parms.vin_max                   = 1375;       // Maximum input voltage
    ivrm_parms.vin_table_step_size       = 25;         // Granularity of Vin table entries
    ivrm_parms.vin_table_setsperrow      = 4;          // Vin sets per Vds row
    ivrm_parms.vin_table_pfetstrperset   = 8;          // PFET Strength values per Vin set
    ivrm_parms.vout_min                  = 600;        // Minimum regulated output voltage
    ivrm_parms.vout_max                  = 1200;       // Maximum regulated output voltage
    ivrm_parms.vin_entries_per_vds       = 32;         // Vin array entries per vds region
    ivrm_parms.vds_min_range_upper_bound = 100;        // Starting point for vds regions
    ivrm_parms.vds_step_percent          = 25;         // vds region step muliplier
    ivrm_parms.vds_region_entries        = 16;         // vds region array entries (in hardware)
    ivrm_parms.pfetstr_default           = 0x11;       // Default PFET Strength with no calibration
    ivrm_parms.positive_guardband        = 11;         // Plus side guardband (%)
    ivrm_parms.negative_guardband        = 6;          // Negative side guardband (%)
    ivrm_parms.number_of_coefficients    = 4;          // Number of coefficents in cal data
    ivrm_parms.force_pfetstr_values      = 1;          // 0 - calculated; 1 = forced
    ivrm_parms.forced_pfetstr_value      = 0x03;

    // create vds
    build_vds_region_table(&ivrm_parms, io_pss);

    // loop over chiplets and find ones with valid data
    // break after first valid chiplet since superstructure does not handle separate vin table for each chiplet
    for (i = 0; i < CHIPLETS; i++) {

      if (ivrm_mvpd.data.ex[i].point_valid > 0) {

        // perform least squares fit to get coefficients & then fill in VIN table
        fit_file(ivrm_parms.number_of_coefficients,
                 ivrm_mvpd.header.version,
                 ivrm_mvpd.data.ex[i].Coef,
                 &(ivrm_mvpd.data.ex[i]) );

        write_HWtab_bin(&ivrm_parms,
                        ivrm_mvpd.data.ex[i].Coef,
                        io_pss);
        break;
      }
    }

    // ---------------------------------------
    // Update CPM Range info in Superstructure
    // ---------------------------------------
    FAPI_IMP("Creating CPM Range Table");

    l_rc = proc_upd_cpmrange (io_pss, &attr);
    if (l_rc) break;

    // -----------------------------------------------
    // Update Resonant Clocking info in Superstructure
    // -----------------------------------------------
    if (attr.attr_chip_ec_feature_resonant_clk_valid) {
      FAPI_IMP("Creating Resonant Clocking Band Table");

      l_rc = proc_res_clock (io_pss, &attr);
      if (l_rc) break;
    }
    else {
    (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options) |
                                                           PSTATE_NO_INSTALL_RESCLK );

    }

    // ------------------------
    // Force optional overrides
    // ------------------------
    (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options) |
                                                            PSTATE_FORCE_INITIAL_PMIN);

    //  Attributes to write
    //  -------------------
    //  uint32_t ATTR_PM_PSTATE0_FREQUENCY // Binary in Khz
  } while(0);

  return l_rc;
} // end p8_build_pstate_datablock


/// -----------------------------------------------------------------------
/// \brief Get needed attributes
/// \param[in]    i_target          => Chip Target
/// \param[inout] attr              => pointer to attribute list structure
/// -----------------------------------------------------------------------

ReturnCode proc_get_attributes(const Target& i_target,
                               AttributeList *attr)
{
  ReturnCode l_rc;
  int        i      = 0;

  do
  {
    // --------------------------
    // attributes not yet defined
    // --------------------------
    attr->attr_dpll_bias                 = 0;
    attr->attr_undervolting              = 0;

    // ---------------------------------------------------------------
    // set ATTR_PROC_DPLL_DIVIDER to 4 and do not read attribute value
    // ---------------------------------------------------------------
    attr->attr_proc_dpll_divider = 4;
    FAPI_INF("ATTR_PROC_DPLL_DIVIDER - set to 4");

    l_rc = FAPI_ATTR_SET(ATTR_PROC_DPLL_DIVIDER, &i_target, attr->attr_proc_dpll_divider );
    if  (l_rc ) {
      FAPI_ERR("fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
      break;
    }

    // ----------------------------
    // attributes currently defined
    // ----------------------------
    #define DATABLOCK_GET_ATTR(attr_name, target, attr_assign) \
            l_rc = FAPI_ATTR_GET(attr_name, target, attr->attr_assign); \
            if (l_rc) break; \
            FAPI_INF("%-60s = 0x%08x %u", #attr_name, attr->attr_assign, attr->attr_assign);

    DATABLOCK_GET_ATTR(ATTR_FREQ_EXT_BIAS_UP,                                &i_target, attr_freq_ext_bias_up);
    DATABLOCK_GET_ATTR(ATTR_FREQ_EXT_BIAS_DOWN,                              &i_target, attr_freq_ext_bias_down);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_UP,                         &i_target, attr_voltage_ext_vdd_bias_up);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VCS_BIAS_UP,                         &i_target, attr_voltage_ext_vcs_bias_up);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_DOWN,                       &i_target, attr_voltage_ext_vdd_bias_down);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VCS_BIAS_DOWN,                       &i_target, attr_voltage_ext_vcs_bias_down);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_UP,                         &i_target, attr_voltage_int_vdd_bias_up);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VCS_BIAS_UP,                         &i_target, attr_voltage_int_vcs_bias_up);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_DOWN,                       &i_target, attr_voltage_int_vdd_bias_down);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VCS_BIAS_DOWN,                       &i_target, attr_voltage_int_vcs_bias_down);
    DATABLOCK_GET_ATTR(ATTR_FREQ_PROC_REFCLOCK,                                   NULL, attr_freq_proc_refclock);
    //jwy DATABLOCK_GET_ATTR(ATTR_PROC_DPLL_DIVIDER,                               &i_target, attr_proc_dpll_divider);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_MAX,                                        NULL, attr_freq_core_max);
    DATABLOCK_GET_ATTR(ATTR_PM_SAFE_FREQUENCY,                                    NULL, attr_pm_safe_frequency);
    DATABLOCK_GET_ATTR(ATTR_BOOT_FREQ_MHZ,                                        NULL, attr_boot_freq_mhz);
    DATABLOCK_GET_ATTR(ATTR_CPM_TURBO_BOOST_PERCENT,                              NULL, attr_cpm_turbo_boost_percent);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDD,                                  NULL, attr_proc_r_loadline_vdd);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VCS,                                  NULL, attr_proc_r_loadline_vcs);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDD,                                  NULL, attr_proc_r_distloss_vdd);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VCS,                                  NULL, attr_proc_r_distloss_vcs);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDD,                                 NULL, attr_proc_vrm_voffset_vdd);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VCS,                                 NULL, attr_proc_vrm_voffset_vcs);
    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY, NULL, attr_pm_resonant_clock_full_clock_sector_buffer_frequency);
    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY,           NULL, attr_pm_resonant_clock_low_band_lower_frequency);
    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY,           NULL, attr_pm_resonant_clock_low_band_upper_frequency);
    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY,          NULL, attr_pm_resonant_clock_high_band_lower_frequency);
    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY,          NULL, attr_pm_resonant_clock_high_band_upper_frequency);

    // Read array attribute
    l_rc = FAPI_ATTR_GET(ATTR_CPM_INFLECTION_POINTS, &i_target, attr->attr_cpm_inflection_points); if (l_rc) break;

    for (i = 0; i < 16; i++) {
      FAPI_INF("ATTR_CPM_INFLECTION_POINTS(%d) = 0x%08x %u",i, attr->attr_cpm_inflection_points[i], attr->attr_cpm_inflection_points[i]);
    }

    // Read chip ec feature
    DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_RESONANT_CLK_VALID, &i_target, attr_chip_ec_feature_resonant_clk_valid);

    // --------------------------------------------------------------
    // do basic attribute value checking and generate error if needed
    // --------------------------------------------------------------

//   jwy  FIXME Add this error check once attr_pm_safe_frequency attribute is updated to be uint32
//   jwy  if (attr->attr_pm_safe_frequency > attr->attr_boot_freq_mhz) {
//   jwy    FAPI_ERR("ATTR_PM_SAFE_FREQUENCY (%u) is greater than ATTR_BOOT_FREQ_MHZ (%u)", attr->attr_pm_safe_frequency, attr->attr_boot_freq_mhz);
//   jwy    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_ERROR);
//   jwy    return l_rc;
//   jwy  }

    //check that dpll_divider is not 0
    if (attr->attr_proc_dpll_divider == 0) {
      FAPI_ERR("**** ERROR : Attribute ATTR_PROC_DPLL_DIVIDER = 0");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_ATTR_DPLL_DIV_ERROR);
      break;
    }

    // ----------------------------------------------------
    // Check Valid Frequency and Voltage Biasing Attributes
    //  - cannot have both up and down bias set
    // ----------------------------------------------------
    if (attr->attr_freq_ext_bias_up > 0 && attr->attr_freq_ext_bias_down > 0) {
      FAPI_ERR("**** ERROR : Frequency bias up and down both defined");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_FREQ_BIAS_ERROR);
      break;
    }

    if (attr->attr_voltage_ext_vdd_bias_up > 0 && attr->attr_voltage_ext_vdd_bias_down > 0) {
      FAPI_ERR("**** ERROR : External voltage bias up and down both defined");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_EXT_VOLTAGE_BIAS_ERROR);
      break;
    }

    if (attr->attr_voltage_ext_vcs_bias_up > 0 && attr->attr_voltage_ext_vcs_bias_down > 0) {
      FAPI_ERR("**** ERROR : External voltage bias up and down both defined");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_EXT_VOLTAGE_BIAS_ERROR);
      break;
    }

    if (attr->attr_voltage_int_vdd_bias_up > 0 && attr->attr_voltage_int_vdd_bias_down > 0) {
      FAPI_ERR("**** ERROR : Internal voltage bias up and down both defined");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_INT_VOLTAGE_BIAS_ERROR);
      break;
    }

    if (attr->attr_voltage_int_vcs_bias_up > 0 && attr->attr_voltage_int_vcs_bias_down > 0) {
      FAPI_ERR("**** ERROR : Internal voltage bias up and down both defined");
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_INT_VOLTAGE_BIAS_ERROR);
      break;
    }

    // print debug message if double biasing is enabled
    if ( (attr->attr_voltage_ext_vdd_bias_up + attr->attr_voltage_ext_vdd_bias_down > 0) &&
         (attr->attr_voltage_int_vdd_bias_up + attr->attr_voltage_int_vdd_bias_down > 0) )
    {
      FAPI_INF("Double Biasing enabled on external and internal VDD");
    }

    if ( (attr->attr_voltage_ext_vcs_bias_up + attr->attr_voltage_ext_vcs_bias_down > 0) &&
         (attr->attr_voltage_int_vcs_bias_up + attr->attr_voltage_int_vcs_bias_down > 0) )
    {
      FAPI_INF("Double Biasing enabled on external and internal VCS");
    }

    // check resonant clocking attribute values relative to each other
    if (attr->attr_chip_ec_feature_resonant_clk_valid) {

      if ( (attr->attr_pm_resonant_clock_low_band_lower_frequency  > attr->attr_pm_resonant_clock_low_band_upper_frequency) ||
           (attr->attr_pm_resonant_clock_low_band_upper_frequency  > attr->attr_pm_resonant_clock_high_band_lower_frequency) ||
           (attr->attr_pm_resonant_clock_high_band_lower_frequency > attr->attr_pm_resonant_clock_high_band_upper_frequency) ) {

        FAPI_ERR("**** ERROR : Resonant clocking band attribute values are not in ascending order from low to high");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_RESCLK_BAND_ERROR);
        break;
      }
    }

    // ------------------------------------------------------
    // do attribute default value setting if the are set to 0
    // ------------------------------------------------------
    if (attr->attr_freq_proc_refclock == 0){
      attr->attr_freq_proc_refclock = 133;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_FREQ_PROC_REFCLOCK = 133");
    }

    if (attr->attr_proc_dpll_divider == 0) {
      attr->attr_proc_dpll_divider = 4;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_DPLL_DIVIDER = 4");
    }

    if (attr->attr_pm_safe_frequency  == 0) {
      attr->attr_pm_safe_frequency = attr->attr_boot_freq_mhz;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_PM_SAFE_FREQUENCY = ATTR_BOOT_FREQ_MHZ");
    }

    if (attr->attr_proc_r_loadline_vdd == 0) {
      attr->attr_proc_r_loadline_vdd = 570;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_LOADLINE_VDD = 570");
    }

    if (attr->attr_proc_r_loadline_vcs == 0) {
      attr->attr_proc_r_loadline_vcs = 570;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_LOADLINE_VCS = 570");
    }

    if (attr->attr_proc_r_distloss_vdd == 0) {
      attr->attr_proc_r_distloss_vdd = 390;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_DISTLOSS_VDD = 390");
    }

    if (attr->attr_proc_r_distloss_vcs == 0) {
      attr->attr_proc_r_distloss_vcs = 3500;
      FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_DISTLOSS_VCS = 3500");
    }

  } while(0);

  return l_rc;
}

/// ----------------------------------------------------------------
/// \brief Get #V data and put into array
/// \param[in]    i_target          => Chip Target
/// \param[inout] attr_mvpd_data    => 5x5 array to hold the #V data
/// ----------------------------------------------------------------

ReturnCode proc_get_mvpd_data(const Target&     i_target,
                                     uint32_t    attr_mvpd_data[PV_D][PV_W],
                                     ivrm_mvpd_t *ivrm_mvpd,
                                     uint8_t     *present_chiplets,
                                     uint8_t     *functional_chiplets)
{
  ReturnCode l_rc;
  std::vector<fapi::Target>       l_exChiplets;
  uint8_t                         l_functional = 0;
  uint8_t *  l_buffer         =  reinterpret_cast<uint8_t *>(malloc(512) );
  uint8_t *  l_buffer_pdm     =  reinterpret_cast<uint8_t *>(malloc(512) );
  uint8_t *  l_buffer_inc;
  uint8_t *  l_buffer_pdm_inc;
  uint32_t   l_bufferSize     = 512;
  uint32_t   l_bufferSize_pdm = 512;
  uint32_t   l_record         = 0;
  uint32_t   chiplet_mvpd_data[PV_D][PV_W];
  uint8_t    j                = 0;
  uint8_t    i                = 0;
  uint8_t    ii               = 0;
  uint8_t    first_chplt      = 1;
  uint8_t    version_pdm      = 0;
  uint8_t    bucket_id        = 0;
  uint16_t   cal_data[4];

  do
  {
    // initialize
    *present_chiplets    = 0;
    *functional_chiplets = 0;

    // -----------------------------------------------------------------
    // get list of chiplets and loop over each and get #V data from each
    // -----------------------------------------------------------------
    // check that frequency is the same per chiplet
    // for voltage, get the max for use for the chip

    l_rc = fapiGetChildChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_exChiplets, TARGET_STATE_PRESENT);
    if (l_rc) {
      FAPI_ERR("Error from fapiGetChildChiplets!");
      break;
    }

    FAPI_INF("Number of EX chiplets present => %u", l_exChiplets.size());

    for (j=0; j < l_exChiplets.size(); j++) {
      *present_chiplets = 1;
      l_bufferSize      = 512;
      l_bufferSize_pdm  = 512;
      uint8_t l_chipNum = 0xFF;

      l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_chipNum);
      if (l_rc) {
        FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
        break;
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
        break;
      }

      // check buffer size
      if (l_bufferSize < PDV_BUFFER_SIZE) {
        FAPI_ERR("**** ERROR : Wrong size buffer returned from fapiGetMvpdField for #V => %d", l_bufferSize );
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_BUFFER_SIZE_ERROR);
        break;
      }

      // clear array
      memset(chiplet_mvpd_data, 0, sizeof(chiplet_mvpd_data));

      // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
      #define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

      // use copy of allocated buffer pointer to increment through buffer
      l_buffer_inc = l_buffer;

      bucket_id = *l_buffer_inc;
      l_buffer_inc++;

      FAPI_INF("#V chiplet = %u bucket id = %u", l_chipNum, bucket_id);

      for (i=0; i<=4; i++) {

        for (ii=0; ii<=4; ii++) {
          chiplet_mvpd_data[i][ii] = (uint32_t) UINT16_GET(l_buffer_inc);
          FAPI_INF("#V data = 0x%04X  %-6d", chiplet_mvpd_data[i][ii], chiplet_mvpd_data[i][ii]);
          // increment to next MVPD value in buffer
          l_buffer_inc+= 2;
        }
      }

      // perform data validity checks on this #V data before proceeding to use it
      l_rc = proc_chk_valid_poundv(chiplet_mvpd_data, l_chipNum, bucket_id);
      if (l_rc) break;

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
        // on subsequent chiplets, check that frequencies are same for each operating point for each chiplet
        if ( (attr_mvpd_data[0][0] != chiplet_mvpd_data[0][0]) ||
             (attr_mvpd_data[1][0] != chiplet_mvpd_data[1][0]) ||
             (attr_mvpd_data[2][0] != chiplet_mvpd_data[2][0]) ||
             (attr_mvpd_data[3][0] != chiplet_mvpd_data[3][0]) ||
             (attr_mvpd_data[4][0] != chiplet_mvpd_data[4][0]) ) {

          FAPI_ERR("**** ERROR : frequencies are not the same for each operating point for each chiplet");
          FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_MVPD_CHIPLET_VOLTAGE_NOT_EQUAL);
          break;
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

      // --------------------------------------------
      // Process #M Data
      // --------------------------------------------

      // Determine if present chiplet is functional
      l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[j], l_functional);
      if (l_rc) {
        FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
        break;
      }

      if ( l_functional ) {
        *functional_chiplets = 1;

        // Get Chiplet #M MVPD data
        l_rc = fapiGetMvpdField((fapi::MvpdRecord)l_record,
                               fapi::MVPD_KEYWORD_PDM,
                               i_target,
                               l_buffer_pdm,
                               l_bufferSize_pdm);
        if (!l_rc.ok()) {
          FAPI_ERR("**** ERROR : Unexpected error encountered in fapiGetMvpdField");
          break;
        }

        // check buffer size
        if (l_bufferSize_pdm < PDM_BUFFER_SIZE) {
          FAPI_ERR("**** ERROR : Wrong size buffer returned from fapiGetMvpdField for #M => %d", l_bufferSize_pdm );
          FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDM_BUFFER_SIZE_ERROR);
          break;
        }

        // use copy of allocated buffer pointer to increment through buffer
        l_buffer_pdm_inc = l_buffer_pdm;

        // get #M version and advance pointer 1-byte to beginning of #M data
        version_pdm = *l_buffer_pdm_inc;
        ivrm_mvpd->header.version = version_pdm ;
        l_buffer_pdm_inc++;

        // loop over 13 entries of #M data with 4 measurements per entry
        FAPI_INF("#M chiplet = %u  version = %u", l_chipNum, version_pdm);

        for (i=0; i < POUNDM_POINTS; i++) {

          for (ii=0; ii<4; ii++) {
            cal_data[ii] = UINT16_GET(l_buffer_pdm_inc);

            if (version_pdm == 2)
              l_buffer_pdm_inc+= 4;
            else
              l_buffer_pdm_inc+= 2;

          }

          ivrm_mvpd->data.ex[j].point[i].gate_voltage   = cal_data[0];
          ivrm_mvpd->data.ex[j].point[i].drain_voltage  = cal_data[1];
          ivrm_mvpd->data.ex[j].point[i].source_voltage = cal_data[2];
          ivrm_mvpd->data.ex[j].point[i].drain_current  = cal_data[3];

          FAPI_INF("#M data (hex & dec) = 0x%04x 0x%04x 0x%04x 0x%04x    %5u %5u %5u %5u", cal_data[0], cal_data[1], cal_data[2], cal_data[3], cal_data[0], cal_data[1], cal_data[2], cal_data[3]);
        }

        // set number of samples to 13
        ivrm_mvpd->data.ex[j].point_valid = POUNDM_POINTS;
      } // end functional

    } // end for loop

  } while(0);

  free (l_buffer);
  free (l_buffer_pdm);

  return l_rc;

} // end proc_get_mvpd_data


/// ---------------------------------------------------------------------------
/// \brief Check and process #V bias attributes for external and internal
/// \param[in]    attr_mvpd_data         => 5x5 array to hold the #V data
/// \param[in]    *attr                  => pointer to attribute list structure
/// \param[inout] * volt_int_vdd_bias    => pointer to internal vdd bias
/// \param[inout] * volt_int_vcs_bias    => pointer to internal vcs bias
/// ---------------------------------------------------------------------------
ReturnCode proc_get_extint_bias(uint32_t attr_mvpd_data[PV_D][PV_W],
                                const AttributeList *attr,
                                double *volt_int_vdd_bias,
                                double *volt_int_vcs_bias)
{
  ReturnCode l_rc;
  int    i                 = 0;
  double freq_bias         = 1.0;
  double volt_ext_vdd_bias = 1.0;
  double volt_ext_vcs_bias = 1.0;

  // --------------------------------------------------------------------------
  // Apply specified Frequency and Voltage Biasing to attr_mvpd_voltage_control
  //   - at least one bias value is guaranteed to be 0
  //   - convert freq/voltage to double
  //   - compute biased freq/voltage and round
  //   - convert back to integer
  // --------------------------------------------------------------------------

  freq_bias          = 1.0 + (BIAS_PCT_UNIT * (double)attr->attr_freq_ext_bias_up)        - (BIAS_PCT_UNIT * (double)attr->attr_freq_ext_bias_down);
  volt_ext_vdd_bias  = 1.0 + (BIAS_PCT_UNIT * (double)attr->attr_voltage_ext_vdd_bias_up) - (BIAS_PCT_UNIT * (double)attr->attr_voltage_ext_vdd_bias_down);
  volt_ext_vcs_bias  = 1.0 + (BIAS_PCT_UNIT * (double)attr->attr_voltage_ext_vcs_bias_up) - (BIAS_PCT_UNIT * (double)attr->attr_voltage_ext_vcs_bias_down);
  *volt_int_vdd_bias = 1.0 + (BIAS_PCT_UNIT * (double)attr->attr_voltage_int_vdd_bias_up) - (BIAS_PCT_UNIT * (double)attr->attr_voltage_int_vdd_bias_down);
  *volt_int_vcs_bias = 1.0 + (BIAS_PCT_UNIT * (double)attr->attr_voltage_int_vcs_bias_up) - (BIAS_PCT_UNIT * (double)attr->attr_voltage_int_vcs_bias_down);

  // loop over each operating point
  for (i=0; i <= 4; i++) {
    attr_mvpd_data[i][0] = (uint32_t) ((( (double)attr_mvpd_data[i][0]) * freq_bias) + 0.5);
    attr_mvpd_data[i][1] = (uint32_t) ((( (double)attr_mvpd_data[i][1]) * volt_ext_vdd_bias) + 0.5);
    attr_mvpd_data[i][3] = (uint32_t) ((( (double)attr_mvpd_data[i][3]) * volt_ext_vcs_bias) + 0.5);
  }

  FAPI_INF("BIAS freq    = %f", freq_bias);
  FAPI_INF("BIAS vdd ext = %f  vcs ext = %f", volt_ext_vdd_bias, volt_ext_vcs_bias);
  FAPI_INF("BIAS vdd int = %f  vcs int = %f", *volt_int_vdd_bias, *volt_int_vcs_bias);

  return l_rc;
} // end proc_get_extint_bias


/// ------------------------------------------------------------
/// \brief Update CPM Range table
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// ------------------------------------------------------------

ReturnCode proc_upd_cpmrange (PstateSuperStructure *pss,
                              const AttributeList *attr)
{
  ReturnCode l_rc;
  int        rc           = 0;
  uint8_t    i            = 0;
  uint8_t    valid_points = 0;
  Pstate     pstate;
  uint32_t   freq_khz;

  do
  {
    // extract valid points from attribute and put into superstructure
    valid_points                      = attr->attr_cpm_inflection_points[8];
    pss->cpmranges.validRanges = valid_points;

    FAPI_INF("CPM valid points = %u", valid_points);

    // loop over valid points in attribute and convert to Khz and then convert to pstate value
    for (i = 0; i < valid_points; i++) {
      freq_khz = attr->attr_cpm_inflection_points[i] * revle32(pss->gpst.frequency_step_khz);
      FAPI_INF("Converting CPM inflection point %u (%u khz) to Pstate", i, freq_khz);
      rc = freq2pState(&(pss->gpst), freq_khz, &pstate);  if (rc) break;
      rc = pstate_minmax_chk(&(pss->gpst), &pstate);      if (rc) break;
      pss->cpmranges.inflectionPoint[i] = pstate;

      FAPI_INF("CPM point  freq_khz = %u  pstate = %d",freq_khz, pstate);
    }

    if (rc) break;

    // convert pMax attribute to Khz and then convert to pstate value

    if (attr->attr_cpm_inflection_points[9] == 0) {
      FAPI_INF(" CPM pMax  = 0. Skipping conversion to pstate");
    }
    else {
      freq_khz = attr->attr_cpm_inflection_points[9] * revle32(pss->gpst.frequency_step_khz);
      FAPI_INF("Converting CPM pMax (%u khz) to Pstate", freq_khz);
      rc = freq2pState(&(pss->gpst), freq_khz, &pstate);   if (rc) break;
      rc = pstate_minmax_chk(&(pss->gpst), &pstate);       if (rc) break;
      pss->cpmranges.pMax = pstate;

      FAPI_INF("CPM pMax   freq_khz = %u  pstate = %d",freq_khz, pstate);
    }

  } while (0);

  // ------------------------------------------------------
  // check error code from freq2pState or pstate_minmax_chk
  // ------------------------------------------------------
  if (rc) {
    int      & RETURN_CODE = rc;
    int8_t   & PSTATE      = pstate;
    uint32_t & FREQ_KHZ    = freq_khz;

    if (rc == -PSTATE_LT_PSTATE_MIN || rc == -PSTATE_LT_PSTATE_MIN) {
      FAPI_ERR("**** ERROR : Computed pstate for freq (%d khz) out of bounds of MAX/MIN possible rc = %d", freq_khz, rc);
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSTATE_MINMAX_BOUNDS_ERROR);
    }
    else if (rc == -GPST_PSTATE_GT_GPST_PMAX){
      FAPI_ERR("**** ERROR : Computed pstate is greater than max pstate in gpst (max pstate = %d  computed pstate = %d  rc = %d", pstate, gpst_pmax(&(pss->gpst)), rc );
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSTATE_GT_GPSTPMAX_ERROR);
    }
    else {
      FAPI_ERR("**** ERROR : Bad Return code rc = %d", rc );
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_ERROR);
    }
  }

  return l_rc;
} // end proc_upd_cpmrange


/// -------------------------------------------------------------------
/// \brief Boost max frequency in pstate table based on boost attribute
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// -------------------------------------------------------------------

ReturnCode proc_boost_gpst (PstateSuperStructure *pss,
                            uint32_t attr_boost_percent)
{
  ReturnCode l_rc;
  uint8_t    i;
  uint8_t    idx;
  double    boosted_pct;
  uint32_t   boosted_freq_khz;
  uint32_t   pstate0_frequency_khz;
  uint32_t   frequency_step_khz;
  uint32_t   pstate_diff;
  gpst_entry_t entry;
  uint8_t    gpsi_max;

  do
  {

    if (attr_boost_percent == 0) {
      FAPI_INF("CPM Turbo Boost Attribute = 0 -- no boosting will be done");
      break;
    }
    // calculate percent to boost
    boosted_pct = 1.0 + (BOOST_PCT_UNIT * (double)attr_boost_percent);

    // get turbo frequency (pstate0 frequency)
    pstate0_frequency_khz = revle32(pss->gpst.pstate0_frequency_khz);

    // get pstate frequency step
    frequency_step_khz    = revle32(pss->gpst.frequency_step_khz);

    // calculate boosted frequency
    boosted_freq_khz = (uint32_t) ( (double)pstate0_frequency_khz * boosted_pct);

    // if boosted frequency is <= turbo frequency, then no boost is to be done
    if (boosted_freq_khz <= pstate0_frequency_khz) {
      FAPI_INF("CPM Turbo Boost Attribute resulted in no increase in pstates - boost_pct = %f turbo_freq_khz = %u boosted_freq_khz = %u",
               boosted_pct,  pstate0_frequency_khz, boosted_freq_khz);
      break;
    }
    // calculate # pstates that boosted frequency is above turbo
    pstate_diff = (boosted_freq_khz/frequency_step_khz) - (pstate0_frequency_khz/frequency_step_khz);

    // pstate difference is 0 then no boost is to be done, else update global pstate table
    if (pstate_diff == 0) {
      FAPI_INF("CPM Turbo Boost Attribute resulted in no increase in pstates - boost_pct = %f turbo_freq_khz = %u boosted_freq_khz = %u",
               boosted_pct,  pstate0_frequency_khz, boosted_freq_khz);
      break;
    }
    else {
      gpsi_max    = pss->gpst.entries - 1;
      entry.value = revle64(pss->gpst.pstate[gpsi_max].value);

      FAPI_INF("Boosting Pstate Table : %% = %f num pstates added = %d", boosted_pct, pstate_diff);

     for (i = 1; i <= pstate_diff; i++) {
        idx = gpsi_max + i;
        pss->gpst.pstate[idx].value = revle64(entry.value);
      }

      pss->gpst.entries += pstate_diff;

    }

  } while(0);
  return l_rc;
} // end proc_boost_gpst


/// -------------------------------------------------------------------
/// \brief Perform data validity check on #V data
/// \param[in] poundv_data   => pointer to array of #V data
/// -------------------------------------------------------------------

ReturnCode proc_chk_valid_poundv(const uint32_t poundv_data[PV_D][PV_W],
                                       uint8_t chiplet_num,
                                       uint8_t bucket_id)
{
  ReturnCode    l_rc;
  const uint8_t pv_op_order[S132A_POINTS] = PV_OP_ORDER;
  const char    *pv_op_str[S132A_POINTS] = PV_OP_ORDER_STR;
  uint8_t       i = 0;

  do
  {
    // check for non-zero freq, voltage, or current in valid operating points
    for (i = 0; i <= S132A_POINTS-1; i++) {

      FAPI_INF("Checking for Zero valued data in each #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
               pv_op_str[pv_op_order[i]],
               poundv_data[pv_op_order[i]][0],
               poundv_data[pv_op_order[i]][1],
               poundv_data[pv_op_order[i]][2],
               poundv_data[pv_op_order[i]][3],
               poundv_data[pv_op_order[i]][4]);

      if (poundv_data[pv_op_order[i]][0] == 0 ||
          poundv_data[pv_op_order[i]][1] == 0 ||
          poundv_data[pv_op_order[i]][2] == 0 ||
          poundv_data[pv_op_order[i]][3] == 0 ||
          poundv_data[pv_op_order[i]][4] == 0   ) {

        FAPI_ERR("**** ERROR : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)", chiplet_num, bucket_id, pv_op_str[pv_op_order[i]]);
        const uint8_t& OP_POINT    = pv_op_order[i];
        const uint8_t& CHIPLET_NUM = chiplet_num;
        const uint8_t& BUCKET_ID   = bucket_id;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_ZERO_DATA_ERROR);
        break;
      }
    }

    if (l_rc) break;

    // check valid operating points' values have this relationship (power save <= nominal <= turbo)
    for (i = 1; i <= S132A_POINTS-1; i++) {

    FAPI_INF("Checking for relationship between #V operating point(%s <= %s) f=%u <= f=%u  v=%u <= v=%u  i=%u <= i=%u  v=%u <= v=%u  i=%u <= i=%u",
               pv_op_str[pv_op_order[i-1]], pv_op_str[pv_op_order[i]],
               poundv_data[pv_op_order[i-1]][0], poundv_data[pv_op_order[i]][0],
               poundv_data[pv_op_order[i-1]][1], poundv_data[pv_op_order[i]][1],
               poundv_data[pv_op_order[i-1]][2], poundv_data[pv_op_order[i]][2],
               poundv_data[pv_op_order[i-1]][3], poundv_data[pv_op_order[i]][3],
               poundv_data[pv_op_order[i-1]][4], poundv_data[pv_op_order[i]][4]);

      if (poundv_data[pv_op_order[i-1]][0] > poundv_data[pv_op_order[i]][0]  ||
          poundv_data[pv_op_order[i-1]][1] > poundv_data[pv_op_order[i]][1]  ||
          poundv_data[pv_op_order[i-1]][2] > poundv_data[pv_op_order[i]][2]  ||
          poundv_data[pv_op_order[i-1]][3] > poundv_data[pv_op_order[i]][3]  ||
          poundv_data[pv_op_order[i-1]][4] > poundv_data[pv_op_order[i]][4]    ) {

        FAPI_ERR("**** ERROR : Relationship error between #V operating point (%s <= %s)(power save <= nominal <= turbo) (chiplet = %u  bucket id = %u  op point = %u)",
                 pv_op_str[pv_op_order[i-1]], pv_op_str[pv_op_order[i]], chiplet_num, bucket_id, pv_op_order[i]);
        const uint8_t& OP_POINT    = pv_op_order[i];
        const uint8_t& CHIPLET_NUM = chiplet_num;
        const uint8_t& BUCKET_ID   = bucket_id;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_OPPOINT_ORDER_ERROR);
        break;
      }
    }

  } while(0);

  return l_rc;
}


/// -------------------------------------------------------------------
/// \brief Convert Resonant Clocking attributes to pstate values and update superstructure with those values
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// -------------------------------------------------------------------
ReturnCode proc_res_clock (PstateSuperStructure *pss,
                           AttributeList *attr_list)
{
  ReturnCode l_rc;
  int        rc       = 0;
  uint32_t   freq_khz = 0;
  Pstate     pstate   = 0;

  do
  {
    // ----------------------------------------------------------------------------
    // convert resonant clock frequencies to pstate value and set in superstructure
    // ----------------------------------------------------------------------------
    #define DATABLOCK_RESCLK(attr_name, ps_name) \
        freq_khz = attr_list->attr_name; \
        FAPI_INF("Converting %s (%u khz) to Pstate", #attr_name, freq_khz); \
        rc = freq2pState(&(pss->gpst), freq_khz, &pstate); \
        if (rc) break; \
        rc = pstate_minmax_chk(&(pss->gpst), &pstate); \
        if (rc == -GPST_PSTATE_GT_GPST_PMAX) { \
          pstate = gpst_pmax(&(pss->gpst)); \
          FAPI_INF("%s pstate is greater than gpst_max(%d) - clipping to gpst_max", #attr_name, pstate); \
        } \
        pss->resclk.ps_name = pstate;

    DATABLOCK_RESCLK(attr_pm_resonant_clock_full_clock_sector_buffer_frequency, full_csb_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_low_band_lower_frequency,           res_low_lower_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_low_band_upper_frequency,           res_low_upper_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_high_band_lower_frequency,          res_high_lower_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_high_band_upper_frequency,          res_high_upper_ps);

  } while(0);

  // ---------------------------------
  // check error code from freq2pState
  // ---------------------------------
  if (rc && rc != -GPST_PSTATE_GT_GPST_PMAX) {
    int &      RETURN_CODE = rc;
    int8_t &   PSTATE      = pstate;
    uint32_t & FREQ_KHZ    = freq_khz;

    if (rc == -PSTATE_LT_PSTATE_MIN || rc == -PSTATE_LT_PSTATE_MIN) {
      FAPI_ERR("**** ERROR : Computed pstate for freq (%d khz) out of bounds of MAX/MIN possible rc = %d", freq_khz, rc);
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSTATE_MINMAX_BOUNDS_ERROR);
    }
    else {
      FAPI_ERR("**** ERROR : Bad Return code rc = %d", rc );
      FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_ERROR);
    }
  }

  return l_rc;
}


} //end extern C

