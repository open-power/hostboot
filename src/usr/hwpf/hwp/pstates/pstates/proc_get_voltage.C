/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/proc_get_voltage.C $         */
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
// $Id: proc_get_voltage.C,v 1.5 2013/05/02 17:33:30 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_get_voltage.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Jim Yacynych         Email: jimyac@us.ibm.com
// *!

/// \file proc_get_voltage.C
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

#include "proc_get_voltage.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------
//ReturnCode freq2pState(uint32_t freq, PstateSuperStructure *pss, int32_t& pstate);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \param[in]      i_target           Chip Target
/// \param[in]      i_freq_mhz         frequency in Mhz
/// \param[out]     *o_vdd_vid         vdd vid value 
/// \param[out]     *o_vcs_vid         vcs vid value

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

ReturnCode
proc_get_voltage(const Target& i_target, const uint32_t i_freq_mhz, uint8_t& o_vdd_vid, uint8_t& o_vcs_vid)
{
  fapi::ReturnCode     l_rc;
  int                  rc = 0;
  PstateSuperStructure pss; 
  gpst_entry_t         entry;
  Pstate               freq_pstate       = 0;
  Pstate               pmax              = 0;
  uint8_t              freq_pstate_index = 0;

  // -----------------------------
  // create pstate super structure
  // -----------------------------
  FAPI_INF("Executing p8_build_pstate_datablock");

  FAPI_EXEC_HWP(l_rc,  p8_build_pstate_datablock, i_target,  &pss);
  if (!l_rc.ok()) {
    FAPI_ERR("Error calling p8_build_pstate_datablock");
    return l_rc;
  } 
 
  // ----------------------
  // convert freq to pstate
  // ----------------------
  rc = freq2pState(&(pss.gpst), (i_freq_mhz*1000), &freq_pstate);

  if (rc) {
    int & RETURN_CODE = rc;
    FAPI_ERR("**** ERROR : Procedure freq2pState() returned %d", rc);
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GET_VOLTAGE_FREQ2PSTATE_ERROR);
    return l_rc;
  }  

  // ----------------------
  // pstate bounds checking
  // ----------------------
  pmax = pss.gpst.pmin + pss.gpst.entries - 1;
  
  FAPI_DBG("freq_pstate = %d pmax = %d  pmin = %d entries = %d i_freq_mhz = %d\n", freq_pstate, pmax, pss.gpst.pmin, pss.gpst.entries, i_freq_mhz);
  
  if (freq_pstate > pmax) {
    FAPI_ERR("**** ERROR : Pstate for given frequency is greater than pmax %d > %d (pmax)", freq_pstate, pmax);
    FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GET_VOLTAGE_FREQ_PSTATE_GT_PMAX_ERROR);
    return l_rc;
  }
  
  if (freq_pstate < pss.gpst.pmin) {
    freq_pstate = pss.gpst.pmin;
  }

  // --------------------------------------------------------
  // convert pstate to pstate table index and lookup voltages
  // --------------------------------------------------------
  freq_pstate_index = freq_pstate - pss.gpst.pmin;
  entry.value       = revle64(pss.gpst.pstate[freq_pstate_index].value);
  o_vdd_vid         = entry.fields.evid_vdd;
  o_vcs_vid         = entry.fields.evid_vcs;  
  return l_rc;
}

} //end extern C

