/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_occ_control.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: p8_occ_control.C,v 1.5 2014/04/21 20:17:31 bcbrock Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_occ_control.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
///   o Write PPC405 rese/halt bits per parameteri_ppc405_reset_ctrl   (OCR, OJCFG)
///       o if PPC405_RESET_NULL , do nothing
///       o if PPC405_RESET_OFF  , write reset bit to 0 (PPC405 not reset)
///       o if PPC405_RESET_ON   , write reset bit to 1 (PPC405 reset)
///       o if PPC405_HALT_OFF   , write halt bit to 0  (PPC405 not halted)
///       o if PPC405_HALT_ON    , write halt bit to 1  (PPC405 halted)
///       o if PPC405_RESET_SEQUENCE , Safe halt/reset of OCC (See comments)
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

// We are not allowed to add new files to fw810, so the BIT() macro is added
// by hand.
//#include "pore_bitmanip.H"

/// Create a multi-bit mask of \a n bits starting at bit \a b
#define BITS(b, n) ((ULL(0xffffffffffffffff) << (64 - (n))) >> (b))

/// Create a single bit mask at bit \a b
#define BIT(b) BITS((b), 1)


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

// We need to get the FAPI team to provide a simple 32-bit address/64-bit data
// SCOM abstraction. In the meantime, we can't define these as local static
// functions due to PHYP restrictions, so we give these SCOM abstractions
// unique names.

#define putScom(target, address, data) \
    _occControlPutScom(target, address, data, #address, __FILE__, __LINE__)

#define getScom(target, address, data) \
    _occControlGetScom(target, address, data, #address, __FILE__, __LINE__)

    fapi::ReturnCode
    _occControlPutScom(const Target& i_target, const uint32_t i_address,
             const uint64_t i_data,
             const char* i_sAddress, const char* i_file, const int i_line)
    {
        fapi::ReturnCode rc;
        uint32_t ecmdRc;
        ecmdDataBufferBase data(64);
        
        do {
            ecmdRc = data.setDoubleWord(0, i_data);
            if (ecmdRc) {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase at %s:%d",
                         ecmdRc, i_file, i_line);
                rc.setEcmdError(ecmdRc);
                break;
            }

            rc = fapiPutScom(i_target, i_address, data);
            if (!rc.ok()) {
                FAPI_ERR("putScom() to %s (0x%08x) failed at %s:%d.",
                         i_sAddress, i_address, i_file, i_line);
                break;
            }
        } while (0);
        return rc;
    }

    fapi::ReturnCode
    _occControlGetScom(const Target& i_target, const uint32_t i_address,
             uint64_t& o_data,
             const char* i_sAddress, const char* i_file, const int i_line)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data(64);
        
        do {
            rc = fapiGetScom(i_target, i_address, data);
            if (!rc.ok()) {
                FAPI_ERR("getScom() from %s (0x%08x) failed at %s:%d.",
                         i_sAddress, i_address, i_file, i_line);
                break;
            }
            o_data = data.getDoubleWord(0);
        } while (0);
        
        return rc;
    }

/// \param[in]  i_target            => Chip Target
/// \param[in]  i_ppc405_reset_ctrl => PPC405_RESET_NULL : do nothing   PPC405_RESET_OFF : set ppc405 reset=0  PPC405_RESET_ON : set ppc405 reset=1
/// \param[in]  i_ppc405_boot_ctrl  => PPC405_BOOT_NULL  : do nothing   PPC405_BOOT_SRAM : boot from sram      PPC405_BOOT_MEM : boot from memory     PPC405_BOOT_OLD : boot from sram (OLD tests)

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

fapi::ReturnCode
p8_occ_control(const Target& i_target, const uint8_t i_ppc405_reset_ctrl, const uint8_t i_ppc405_boot_ctrl)
{
    fapi::ReturnCode rc, rc1;
  ecmdDataBufferBase data(64);
  uint32_t   l_ecmdRc = 0;
  uint64_t firMask, occLfir;

  FAPI_INF("Executing p8_occ_control ....");

  // -------------------------------------
  // process arguments passed to procedure
  // -------------------------------------

  // check ppc405_reset_ctrl
  if (!(i_ppc405_reset_ctrl <= PPC405_RESET_SEQUENCE) ) {
    FAPI_ERR("Bad PPC405 Reset Setting Passed to Procedure => %d", i_ppc405_reset_ctrl);
    const uint8_t& RESET_PARM = i_ppc405_reset_ctrl;
    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCC_CONTROL_BAD_405RESET_PARM);
    return rc;
  }

  // check sram_bv_ctrl
  if (!(i_ppc405_boot_ctrl <= PPC405_BOOT_OLD) ) {
    FAPI_ERR("Bad Boot Vector Setting Passed to Procedure => %d", i_ppc405_boot_ctrl);
    const uint8_t& BOOT_PARM = i_ppc405_boot_ctrl;
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
  // Handle the i_ppc405_reset_ctrl parameter
  // ----------------------------------------------------------

  switch (i_ppc405_reset_ctrl) {

  case PPC405_RESET_OFF:

      rc = putScom(i_target, OCC_CONTROL_AND_0x0006B001, ~BIT(0));
      if (!rc.ok()) return rc;
      break;

  case PPC405_RESET_ON:

      rc = putScom(i_target, OCC_CONTROL_OR_0x0006B002, BIT(0));
      if (!rc.ok()) return rc;
      break;
      
  case PPC405_HALT_OFF:

      rc = putScom(i_target, OCC_JTG_PIB_OJCFG_AND_0x0006B005, ~BIT(6));
      if (!rc.ok()) return rc;
      break;

  case PPC405_HALT_ON:

      rc = putScom(i_target, OCC_JTG_PIB_OJCFG_OR_0x0006B006, BIT(6));
      if (!rc.ok()) return rc;
      break;

  case PPC405_RESET_SEQUENCE:

      // It is unsafe in general to simply reset the 405, as this is an
      // asynchronous reset that can leave OCI slaves in unrecoverable states
      // (cf. SW255563). This is a "safe" reset-entry sequence that includes
      // halting the 405 (a synchronous operation) before issuing the
      // reset. Since this sequence halts/unhalts the 405 and modifies FIRs it
      // is coded and called out apart from the simple PPC405_RESET_OFF
      // sequence above that simply sets the 405 reset bit.
      //
      // The sequence:
      //
      // 1. Mask the "405 halted" FIR bit to avoid FW thinking the halt we're
      // about to inject on the 405 is an error.
      //
      // 2. Halt the 405. If the 405 does not halt in 1ms we note that fact
      // but press on, hoping (probably in vain) that any subsequent reset
      // actions will clear up the issue. To check if the 405 halted we must
      // clear the FIR and verify that the FIR is set again.
      //
      // 3. Put the 405 into reset.
      //
      // 4. Clear the halt bit.
      //
      // 5. Restore the original FIR mask

      // Save the FIR mask, and mask the halted FIR

      rc = getScom(i_target, OCC_LFIR_MASK_0x01010803, firMask);
      if (!rc.ok()) return rc;

      rc = putScom(i_target, OCC_LFIR_MASK_OR_0x01010805, BIT(25));
      if (!rc.ok()) return rc;

      do {

          // Halt the 405 and verify that it is halted

          rc = putScom(i_target, OCC_JTG_PIB_OJCFG_OR_0x0006B006, BIT(6));
          if (!rc.ok()) break;

          rc = fapiDelay(1000000, 10000); // 1,000,000 ns = 1ms
          if (!rc.ok()) {
              FAPI_ERR("fapiDelay() failed");
              break;
          }

          rc = putScom(i_target, OCC_LFIR_AND_0x01010801, ~BIT(25));
          if (!rc.ok()) break;

          rc = getScom(i_target, OCC_LFIR_0x01010800, occLfir);
          if (!rc.ok()) break;

          if (!(occLfir & BIT(25))) {
              FAPI_ERR("OCC will not halt. Pressing on, hoping for the best.");
          }

          // Put the 405 into reset, unhalt the 405 and clear the halted FIR
          // bit. 

          rc = putScom(i_target, OCC_CONTROL_OR_0x0006B002, BIT(0));
          if (!rc.ok()) break;

          rc = putScom(i_target, OCC_JTG_PIB_OJCFG_AND_0x0006B005, ~BIT(6));
          if (!rc.ok()) break;

          rc = putScom(i_target, OCC_LFIR_AND_0x01010801, ~BIT(25));
          if (!rc.ok()) break;

      } while (0);

      // Restore the original FIR mask, then decide which error code (if any)
      // to return.

      rc1 = putScom(i_target, OCC_LFIR_MASK_0x01010803, firMask);

      if (!rc.ok() && !rc1.ok()) {
          FAPI_ERR("Double fault, returing final error code");
          return rc1;
      } else if (!rc.ok()) {
          return rc;
      } else if (!rc1.ok()) {
          return rc1;
      }          
      break;


  default:
      break;
  }

  FAPI_INF("Completing p8_occ_control ....");

  return rc;
}

} //end extern C
