/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_occ_sram_init.C $      */
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
// $Id: p8_occ_sram_init.C,v 1.3 2013/04/01 04:11:52 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_occ_sram_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Jim Yacynych        Email: ajimyac@us.ibm.com
// *!
// *! General Description:
// *!        
// *!   The purpose of this procedure is to initialize the OCC SRAM
// *!   
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_occ_sram_init.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// \param[in] i_target Chip target
/// \param[in] mode     Control mode for the procedure 
///                     (PM_CONFIG, PM_INIT, PM_RESET)

/// \retval PM_SUCCESS if something good happens,
/// \retval PM_OCCSRAM_CODE_BAD* otherwise

fapi::ReturnCode
p8_occ_sram_init(const Target& i_target, uint32_t mode)
{
  fapi::ReturnCode rc;
  //ecmdDataBufferBase data;
  //ecmdDataBufferBase mask;
  
  
  FAPI_INF("Executing p8_occ_sram_init in mode %x ...", mode);
  
  /// -------------------------------
  /// Configuration:  perform translation of any Platform Attributes into Feature Attributes
  /// that are applied during Initalization
  if (mode == PM_CONFIG) 
  {
  
    FAPI_INF("OCC SRAM configuration...");  
    FAPI_INF("---> None defined...");
    
  }
  
  /// -------------------------------
  /// Initialization:  perform order or dynamic operations to initialize 
  /// the OCC SRAM using necessary Platform or Feature attributes. 
  else if (mode == PM_INIT) 
  {

    FAPI_INF("OCC SRAM initialization...");
 
  } 
  
  /// -------------------------------
  /// Reset:  perform reset of OCC SRAM so that it can reconfigured and 
  /// reinitialized 
  else if (mode == PM_RESET) 
  {
  
    FAPI_INF("OCC SRAM reset...");
    
  } 
   
  /// -------------------------------
  /// Unsupported Mode
  else 
  {
  
    FAPI_ERR("Unknown mode passed to p8_occ_sram_init. Mode %x ....", mode);
    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCCSRAM_CODE_BAD_MODE);
    
  }
  
  return rc;

}

} //end extern C

