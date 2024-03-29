/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfScanFacility.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2024                        */
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
SCAN_COMM_REGISTER_CLASS & ScanFacility::GetScanCommRegister( uint64_t address,
                                uint8_t i_scomLength, TARGETING::TYPE i_type,
                                SCAN_COMM_REGISTER_CLASS::AccessLevel i_regOp,
                                uint16_t i_sigOff )
{
    // i_regOp is not used to determine uniqueness of the object for following
    // reason -
    // There can not be two registers in hardware with same address, target
    // type, and signature offset supporting different operations say one
    // supports only write and other both read and write.

    // Signature offset (i_sigOff) is included solely for determining
    // uniqueness of the object since there may be different registers that
    // otherwise share the same address and target type, e.g. registers
    // in Explorer vs Odyssey OCMBs. The hash ID of the register cannot be used
    // for this due to some registers (mask and reset regs defined for FIRs) may
    // not have hash IDs.

    ScomRegister scrKey( address, i_scomLength, i_type, i_regOp, i_sigOff );

    // in case we get a object with different default operation, we shall reset
    // it to what it should be as per rule file.
    ScomRegister &regCreated = iv_scomRegFw.get(scrKey);
    regCreated.setAccessLevel( i_regOp );
    return regCreated;
}

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

//-----------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS &  ScanFacility::GetSummaryRegister(
                                    SCAN_COMM_REGISTER_CLASS & i_arg,
                                     uint16_t i_bit )
{
  SummaryRegister r(i_arg, i_bit);
  return iv_sumRegFw.get(r);
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
                                        SCAN_COMM_REGISTER_CLASS * i_check,
                                        SCAN_COMM_REGISTER_CLASS * i_recov,
                                        SCAN_COMM_REGISTER_CLASS * i_special,
                                        SCAN_COMM_REGISTER_CLASS * i_proccs,
                                        SCAN_COMM_REGISTER_CLASS * i_hostattn )
{
  AttnTypeRegister r(i_check, i_recov, i_special, i_proccs, i_hostattn);
  return iv_attnRegFw.get(r);
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS & ScanFacility::GetConstantRegister(
                                                const BitStringBuffer & i_val )
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
  iv_pluginRegFw.clear();


}

//-----------------------------------------------------------------------------

void ScanFacility::reset()
{
    iv_scomRegFw.clear();
    iv_attnRegFw.clear();
    iv_andRegFw.clear();
    iv_orRegFw.clear();
    iv_notRegFw.clear();
    iv_leftRegFw.clear();
    iv_sumRegFw.clear();
    iv_rightRegFw.clear();
    iv_constRegFw.clear();
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
    PRDF_TRAC("AttnTypeRegisters FW" );
    iv_attnRegFw.printStats();
    PRDF_TRAC("SummaryRegisters FW" );
    iv_sumRegFw.printStats();
    PRDF_TRAC("ConstantRegisters FW" );
    iv_constRegFw.printStats();
    PRDF_TRAC("PluginRegisters FW" );
    iv_pluginRegFw.printStats();
}

#endif

} // end namespace PRDF

