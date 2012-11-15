/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/xspprdAccessPllChip.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2000,2012              */
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

// Module Description **************************************************
//
// Description:
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define xspprdAccessPllChip_C

#include <xspprdAccessPllChip.h>

#if !defined(IIPSCR_H)
#include <iipscr.h>
#endif

#if !defined(PRDFSCANFACILITY_H)
#include <prdfScanFacility.H>
#endif

#include <iipServiceDataCollector.h>

#undef xspprdAccessPllChip_C
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint32_t PLL_LOCK  = 0x00800003; // Pll status address
const uint32_t PLL_MASK  = 0x0080000C; // Pll Mask/Block reg address
const uint32_t PLL_ID    = 0xeed;
// Pll status bit definitions
const uint32_t PLL0     = 8;
const uint32_t PLL1     = 9;
const uint32_t PLL2     = 10;
const uint32_t PLL3     = 11;
const uint32_t PLLBLK0  = 8;
const uint32_t PLLBLK1  = 9;
const uint32_t PLLBLK2  = 10;
const uint32_t PLLBLK3  = 11;

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

// --------------------------------------------------------------------

bool AccessPllChip::QueryPll(void)
{
  bool hasPll = false;
  SCAN_COMM_REGISTER_CLASS & pll_lock_reg =
    ScanFacility::Access().GetScanCommRegister(GetChipHandle(),PLL_LOCK,64);
  SCAN_COMM_REGISTER_CLASS & pll_mask_reg =
    ScanFacility::Access().GetScanCommRegister(GetChipHandle(),PLL_MASK,64);


  // Read pll_lock register
  int32_t rc = pll_lock_reg.Read();
  pll_mask_reg.Read();

  if (rc == SUCCESS) {
    const BIT_STRING_CLASS * lock = pll_lock_reg.GetBitString();
    const BIT_STRING_CLASS * mask = pll_mask_reg.GetBitString();

    if ( (lock != NULL) && (mask != NULL) ) {
      CPU_WORD senseBits = lock->GetField(PLL0,    4);
      CPU_WORD blockBits = mask->GetField(PLLBLK0, 4);
      if (senseBits & (~blockBits)) hasPll = true;
    }
  }

  return hasPll;
}

// --------------------------------------------------------------------

int32_t AccessPllChip::ClearPll(void)
{
  int32_t rc = SUCCESS;
  SCAN_COMM_REGISTER_CLASS & pll_lock_reg =
    ScanFacility::Access().GetScanCommRegister(GetChipHandle(),PLL_LOCK,64);
//  SCAN_COMM_REGISTER_CLASS & pll_mask_reg =
//    ScanFacility::Access().GetScanCommRegister(GetId(),PLL_MASK,64);

  pll_lock_reg.Read();

  // Need to also clear out status bits
  pll_lock_reg.ClearBit(PLL0);
  pll_lock_reg.ClearBit(PLL1);
  pll_lock_reg.ClearBit(PLL2);
  pll_lock_reg.ClearBit(PLL3);

  rc = pll_lock_reg.Write();

  return rc;
}

// --------------------------------------------------------------------

int32_t AccessPllChip::MaskPll(STEP_CODE_DATA_STRUCT & serviceData)
{
  int32_t rc = SUCCESS;
//  SCAN_COMM_REGISTER_CLASS & pll_lock_reg =
//    ScanFacility::Access().GetScanCommRegister(GetId(),PLL_LOCK,64);
  SCAN_COMM_REGISTER_CLASS & pll_mask_reg =
    ScanFacility::Access().GetScanCommRegister(GetChipHandle(),PLL_MASK,64);


  //Read pll status reg mask to get current state
  pll_mask_reg.Read();

  // Set mask bits for pll
  pll_mask_reg.SetBit(PLLBLK0);
  pll_mask_reg.SetBit(PLLBLK1);
  pll_mask_reg.SetBit(PLLBLK2);
  pll_mask_reg.SetBit(PLLBLK3);

  // Write back to hardware
  rc = pll_mask_reg.Write();

  return rc;
}

// --------------------------------------------------------------------

int32_t AccessPllChip::UnMaskPll(void)
{
  int32_t rc = SUCCESS;
//  SCAN_COMM_REGISTER_CLASS & pll_lock_reg =
//    ScanFacility::Access().GetScanCommRegister(GetId(),PLL_LOCK,64);
  SCAN_COMM_REGISTER_CLASS & pll_mask_reg =
    ScanFacility::Access().GetScanCommRegister(GetChipHandle(),PLL_MASK,64);

  //Read pll status reg mask to get current state
  pll_mask_reg.Read();

  // Set mask bits for pll
  pll_mask_reg.ClearBit(PLLBLK0);
  pll_mask_reg.ClearBit(PLLBLK1);
  pll_mask_reg.ClearBit(PLLBLK2);
  pll_mask_reg.ClearBit(PLLBLK3);

  // Write back to hardware
  rc = pll_mask_reg.Write();

  return rc;
}
// --------------------------------------------------------------------

void AccessPllChip::CapturePll(STEP_CODE_DATA_STRUCT & serviceData)
{
  SCAN_COMM_REGISTER_CLASS & pll_lock_reg =
    ScanFacility::Access().GetScanCommRegister(GetChipHandle(),PLL_LOCK,64);
  (serviceData.service_data->GetCaptureData()).Add(GetChipHandle(), PLL_ID ,pll_lock_reg);
}

// --------------------------------------------------------------------
// --------------------------------------------------------------------


// Change Log *********************************************************
//
//  Flag Reason    Vers Date     Coder    Description
//  ---- --------- ---- -------- -------- ------------------------------
//                 v5r2 04/14/00 mkobler  Initial Creation
//       512857 fips240 07/29/05 dgilbert add AccessPllChip
//
// End Change Log *****************************************************
