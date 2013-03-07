/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_occ_control.C $        */
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
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
// $Id: p8_occ_control.C,v 1.1 2012/08/21 16:17:31 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_occ_control.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Jim Yacynych         Email: jimyac@us.ibm.com
// *!

/// \file p8_occ_control.C
/// \brief Initialize boot vector registers and control PPC405 reset

/// \todo
///
///   High-level procedure flow:
/// \verbatim
///   o process parameters passed to procedure
///   o Initialize boot vector registers in SRAM (SRBV0,1,2,3) if (i_ppc405_boot_ctrl != PPC405_BOOT_NULL)
///     o initialize SRBV0,1,2 with all 0's (illegal instructions)
///     o initialize SRBV0 per passed parameter (i_ppc405_boot_ctrl)
///       o initialize to Branch Absolute 0xFFF80010 if i_ppc405_boot_ctrl = PPC405_BOOT_SRAM
///       o initialize to Branch Absolute 0x00000010 if i_ppc405_boot_ctrl = PPC405_BOOT_MEM
///       o initialize to Branch Relative -16        if i_ppc405_boot_ctrl = PPC405_BOOT_OLD
///   o Write PPC405 reset bit per parameteri_ppc405_reset_ctrl   (OCR)
///       o if PPC405_RESET_NULL , do nothing
///       o if PPC405_RESET_OFF  , write reset bit to 0 (PPC405 not reset)
///       o if PPC405_RESET_ON   , write reset bit to 1 (PPC405 reset)
/// Procedure Prereq:
///   o System clocks are running
/// \endverbatim
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_occ_control.H"

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

/// \param[in]  i_target            => Chip Target
/// \param[in]  i_ppc405_reset_ctrl => PPC405_RESET_NULL : do nothing   PPC405_RESET_OFF : set ppc405 reset=0  PPC405_RESET_ON : set ppc405 reset=1
/// \param[in]  i_ppc405_boot_ctrl  => PPC405_BOOT_NULL  : do nothing   PPC405_BOOT_SRAM : boot from sram      PPC405_BOOT_MEM : boot from memory     PPC405_BOOT_OLD : boot from sram (OLD tests)

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

fapi::ReturnCode
p8_occ_control(const Target& i_target, const uint8_t i_ppc405_reset_ctrl, const uint8_t i_ppc405_boot_ctrl)
{
  fapi::ReturnCode rc;
  ecmdDataBufferBase data(64);
  uint32_t   l_ecmdRc = 0;

  FAPI_INF("Executing p8_occ_control ....");

  // -------------------------------------
  // process arguments passed to procedure
  // -------------------------------------

  // check ppc405_reset_ctrl
  if (!(i_ppc405_reset_ctrl <= PPC405_RESET_ON) ) {
    FAPI_ERR("Bad PPC405 Reset Setting Passed to Procedure => %d", i_ppc405_reset_ctrl);
    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCC_CONTROL_BAD_405RESET_PARM);
    return rc;
  }

  // check sram_bv_ctrl
  if (!(i_ppc405_boot_ctrl <= PPC405_BOOT_OLD) ) {
    FAPI_ERR("Bad Boot Vector Setting Passed to Procedure => %d", i_ppc405_boot_ctrl);
    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCC_CONTROL_BAD_405BOOT_PARM);
    return rc;
  }

  // ------------------------------------------------
  // Set up Boot Vector Registers in SRAM
  //    - set bv0-2 to all 0's (illegal instructions)
  //    - set bv3 to proper branch instruction
  //    - boot vector registers
  //      - OCC_SRAM_BOOT_VEC0_0x00066004
  //      - OCC_SRAM_BOOT_VEC1_0x00066005
  //      - OCC_SRAM_BOOT_VEC2_0x00066006
  //      - OCC_SRAM_BOOT_VEC3_0x00066007
  // -------------------------------------------------

  l_ecmdRc |= data.flushTo0();

  if (l_ecmdRc) {
    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
    rc.setEcmdError(l_ecmdRc);
    return rc;
  }

  // write 0's to bv0-2
  if (i_ppc405_boot_ctrl != PPC405_BOOT_NULL) {

    FAPI_DBG("Writing to Boot Vector0 Register");

    rc = fapiPutScom(i_target, OCC_SRAM_BOOT_VEC0_0x00066004, data);
    if (!rc.ok()) {
      FAPI_ERR("**** ERROR : Unexpected error encountered in write to SRAM Boot Vector0 Register");
      return rc;
    }

    FAPI_DBG("Writing to Boot Vector1 Register");

    rc = fapiPutScom(i_target, OCC_SRAM_BOOT_VEC1_0x00066005, data);
    if (!rc.ok()) {
      FAPI_ERR("**** ERROR : Unexpected error encountered in write to SRAM Boot Vector1 Register");
      return rc;
    }

    FAPI_DBG("Writing to Boot Vector2 Register");

    rc = fapiPutScom(i_target, OCC_SRAM_BOOT_VEC2_0x00066006, data);
    if (!rc.ok()) {
      FAPI_ERR("**** ERROR : Unexpected error encountered in write to SRAM Boot Vector2 Register");
      return rc;
    }

    // write branch instruction to bv3
    if (i_ppc405_boot_ctrl == PPC405_BOOT_SRAM) {
      l_ecmdRc |= data.setWord(0, PPC405_BRANCH_SRAM_INSTR);          // Branch Absolute 0xFFF80010  => ba 0xfff80010 (boot from sram)
    }
    else if (i_ppc405_boot_ctrl == PPC405_BOOT_MEM) {
      l_ecmdRc |= data.setWord(0, PPC405_BRANCH_MEM_INSTR);           // Branch Absolute 0x00000010  => ba 0x00000010 (boot from memory)
    }
    else {
      l_ecmdRc |= data.setWord(0, PPC405_BRANCH_OLD_INSTR);
    }

    if (l_ecmdRc) {
      FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
      rc.setEcmdError(l_ecmdRc);
      return rc;
    }

    FAPI_DBG("Writing to Boot Vector3 Register");

    rc = fapiPutScom(i_target, OCC_SRAM_BOOT_VEC3_0x00066007, data);
    if (!rc.ok()) {
      FAPI_ERR("**** ERROR : Unexpected error encountered in write to SRAM Boot Vector3 Register");
      return rc;
    }
  }

  // ----------------------------------------------------------
  // Set or Clear PPC405 reset in OCC Control register (
  //   OCC_CONTROL_0x0006B000
  //   OCC_CONTROL_AND_0x0006B001
  //   OCC_CONTROL_OR_0x0006B002
  //
  //  - bit 0 =>   0= ppc405 not in reset    1= ppc405 in reset
  // ----------------------------------------------------------

  if (i_ppc405_reset_ctrl == PPC405_RESET_OFF) {
    l_ecmdRc |= data.flushTo1();
    l_ecmdRc |= data.clearBit(0);

    if (l_ecmdRc) {
      FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
      rc.setEcmdError(l_ecmdRc);
      return rc;
    }

    FAPI_DBG("Writing OCC Control Register to clear bit 0 (core_reset)");

    rc = fapiPutScom(i_target, OCC_CONTROL_AND_0x0006B001, data);
    if (!rc.ok()) {
      FAPI_ERR("**** ERROR : Unexpected error encountered in write to OCC Control Register => OCC_CONTROL_AND_0x0006B001");
      return rc;
    }
  }

  if (i_ppc405_reset_ctrl == PPC405_RESET_ON) {
    l_ecmdRc |= data.flushTo0();
    l_ecmdRc |= data.setBit(0);

    if (l_ecmdRc) {
      FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
      rc.setEcmdError(l_ecmdRc);
      return rc;
    }

    FAPI_DBG("Writing OCC Control Register to set bit 0 (core_reset)");

    rc = fapiPutScom(i_target, OCC_CONTROL_OR_0x0006B002, data);
    if (!rc.ok()) {
      FAPI_ERR("**** ERROR : Unexpected error encountered in write to OCC Control Register => OCC_CONTROL_OR_0x0006B002");
      return rc;
    }
  }

  FAPI_INF("Completing p8_occ_control ....");

  return rc;
}

} //end extern C
