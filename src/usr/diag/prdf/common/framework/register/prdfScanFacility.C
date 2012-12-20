/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfScanFacility.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
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

/**
  @file prdfScanFacility.C
  @brief PRD ScanFaclity class definition
*/
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfScanFacility_C

#include <iipscr.h>
#include <prdfScanFacility.H>
#include <prdfFlyWeight.C>
#include <prdfFlyWeightS.C>
#include <prdfScomRegisterAccess.H>

#undef prdfScanFacility_C

namespace PRDF
{

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

NullRegister AttnTypeRegister::cv_null(1024);

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------


ScanFacility & ScanFacility::Access(void)
{
  static ScanFacility sf;
  return sf;
}
//-----------------------------------------------------------------------------
SCAN_COMM_REGISTER_CLASS & ScanFacility::GetScanCommRegister(
    uint64_t address , uint32_t i_scomLength,TARGETING::TYPE i_type  )
{
  ScomRegister scrKey(address ,i_scomLength ,i_type );
  return iv_scomRegFw.get(scrKey);
}
//------------------------------------------------------------------------------

#if 0
SCAN_COMM_REGISTER_CLASS & ScanFacility::GetScanRingRegister(
                                TARGETING::TargetHandle_t i_ptargetHandle,
                                ScanRingField * start,
                                ScanRingField * end)
{
  uint32_t bitLength = 0;
  for(ScanRingField * srf = start; srf != end; ++srf)
  {
    bitLength += srf->length;
  }
  HomRegisterAccessScan hra(i_ptargetHandle,start,end);
  iv_scanAccessList.push_back(hra);
  ScanCommRegisterChip scrKey(start->registerId,bitLength,hra);
  return iv_scomRegFw.get(scrKey);
}
#endif

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetNotRegister(
                                        SCAN_COMM_REGISTER_CLASS & i_arg )
{
  NotRegister r(i_arg);
  return iv_notRegFw.get(r);
}

//-----------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetLeftShiftRegister(
                                    SCAN_COMM_REGISTER_CLASS & i_arg,
                                     uint16_t i_amount )
{
  LeftShiftRegister r(i_arg, i_amount);
  return iv_leftRegFw.get(r);
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetRightShiftRegister(
                                SCAN_COMM_REGISTER_CLASS & i_arg,
                                uint16_t i_amount )
{
  RightShiftRegister r(i_arg, i_amount);
  return iv_rightRegFw.get(r);
}


//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetAndRegister(
                                            SCAN_COMM_REGISTER_CLASS & i_left,
                                            SCAN_COMM_REGISTER_CLASS & i_right )
{
  AndRegister r(i_left,i_right);
  return iv_andRegFw.get(r);
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetOrRegister(
                                            SCAN_COMM_REGISTER_CLASS & i_left,
                                            SCAN_COMM_REGISTER_CLASS & i_right )
{
  OrRegister r(i_left,i_right);
  return iv_orRegFw.get(r);
}

//-----------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetAttnTypeRegister(
                                            SCAN_COMM_REGISTER_CLASS & i_check,
                                            SCAN_COMM_REGISTER_CLASS & i_recov,
                                            SCAN_COMM_REGISTER_CLASS & i_special,
                                            SCAN_COMM_REGISTER_CLASS & i_proccs )
{
  AttnTypeRegister r(i_check,i_recov,i_special,i_proccs);
  return iv_attnRegFw.get(r);
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetConstantRegister(
                                                    BIT_STRING_CLASS i_val )
{
  ConstantRegister r(i_val);
  return iv_constRegFw.get(r);
}
//------------------------------------------------------------------------------
SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetPluginRegister(
                                        SCAN_COMM_REGISTER_CLASS & i_flyweight,
                                        ExtensibleChip & i_RuleChip )
{
  ScomRegisterAccess l_regKey ( i_flyweight,&i_RuleChip );
  return iv_pluginRegFw.get(l_regKey);

}
//-----------------------------------------------------------------------------
void ScanFacility::ResetPluginRegister()
{
  PRDF_INF( "ScanFacility.ResetPluginRegister()" );
  iv_pluginRegFw.clear();


}

//------------------------------------------------------------------------------
#ifdef FLYWEIGHT_PROFILING
void ScanFacility::printStats()
{
    PRDF_TRAC("ScomRegister");
    iv_scomRegFw.printStats();
    PRDF_TRAC("Not Register");
    iv_notRegFw.printStats();
    PRDF_TRAC("Left Register");
    iv_leftRegFw.printStats();
    PRDF_TRAC("Right Register");
    iv_rightRegFw.printStats();
    PRDF_TRAC("And Register");
    iv_andRegFw.printStats();
    PRDF_TRAC("Or Register");
    iv_orRegFw.printStats();

}

#endif

} // end namespace PRDF

