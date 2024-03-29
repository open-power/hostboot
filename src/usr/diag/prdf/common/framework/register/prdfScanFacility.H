/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfScanFacility.H $ */
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

#ifndef PRDFSCANFACILITY_H
#define PRDFSCANFACILITY_H
/**
   @file prdfScanFacility.H
   @brief Description
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfFlyWeight.H>
#include <prdfFlyWeightS.H>
#include <vector>
#include <prdfHomRegisterAccess.H>
#include <prdfScomRegister.H>
#include <prdfScomRegisterAccess.H>
#include <prdfOperatorRegister.H>
#include <prdfPlatServices.H>

namespace PRDF
{


/**
    PRD Scan Facility
    @author Doug Gilbert
    @par    The Scan facility is used by PRD to access Scan and Scan Comm
    @       functions.It attempts to reduce duplicate objects and their
    @       aggragates as must as possible.
*/
class ScanFacility
{
public:
  /**
   The Scan Facility is a singleton - this function provides access to it.
   */
  static ScanFacility & Access(void);

    /**
    * @brief     Returns reference to flyweight object of type ScomRegister.
    *            An object of given address is first searched in flyweight.
    *            If object exist, reference to existing object is returned
    *            else a new one is created.
    * @param     i_address        address of the register
    * @param     i_scomLength     length of the bit string
    * @param     i_type           type of target associated with register
    * @param     i_regOp          operations supported for given register
    * @param     i_sigOff         signature offset associated with this target
    * @return   returns reference to flyweight object from factory
    */
   SCAN_COMM_REGISTER_CLASS & GetScanCommRegister( uint64_t address,
                                uint8_t i_scomLength, TARGETING::TYPE i_type,
                                SCAN_COMM_REGISTER_CLASS::AccessLevel i_regOp,
                                uint16_t i_sigOff );

  /**
   * @brief  Get a register that bitwise inverts the bitstring of a register
   *         when read or written to
   * @param  SCAN_COMM_REGISTER_CLASS source
   * @post   Only one instance of the register with this SCR parameter will
   *         exist
   */
  SCAN_COMM_REGISTER_CLASS & GetNotRegister(SCAN_COMM_REGISTER_CLASS & i_arg);

  /**
   * @brief  Get a register that bitwise left shift the bitstring of a register
   *         when read or written to
   * @param  SCAN_COMM_REGISTER_CLASS source
   * @post   Only one instance of the register with this SCR parameter and
   *         amount will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetLeftShiftRegister(
                        SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount);

  /**
   * @brief Get a register that bitwise right shift the bitstring of a register
   *        when read or written to
   * @param SCAN_COMM_REGISTER_CLASS source
   * @post  Only one instance of the register with this SCR parameter and amount
   * @      will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetRightShiftRegister(
                        SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount);

  /**
   * @brief  Get a register for the summary construct
   * @param  SCAN_COMM_REGISTER_CLASS source
   * @param  uint16_t i_bit  bit to set if any attentions found in i_arg
   * @post   Only one instance of the register with this SCR parameter and
   *         amount will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetSummaryRegister(
                        SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_bit);

  /**
   * @brief  Get a register that bit-wise ANDs the bitstring of two register
   *         when read or written to
   * @param  The 2 SCR 's to AND
   * @posrt  Only one instance of the register with these SCRs will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetAndRegister(SCAN_COMM_REGISTER_CLASS & i_left,
                                            SCAN_COMM_REGISTER_CLASS & i_right);

  /**
   * @brief  Get a register that bitwise ORs the bitstrings of two register when
   *         read or written
   * @param  the 2 SCR's to OR
   * @post   Only one instance of the register with these SCR's will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetOrRegister(SCAN_COMM_REGISTER_CLASS & i_left,
                                           SCAN_COMM_REGISTER_CLASS & i_right);

  /**
   * @brief  Get a AttnTypeRegister
   * @params 5 pointers to scr Registers
   * @post only one instance of the register with these SCR's will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetAttnTypeRegister(
                                    SCAN_COMM_REGISTER_CLASS * i_check,
                                    SCAN_COMM_REGISTER_CLASS * i_recov,
                                    SCAN_COMM_REGISTER_CLASS * i_special,
                                    SCAN_COMM_REGISTER_CLASS * i_proccs,
                                    SCAN_COMM_REGISTER_CLASS * i_hostattn );

  /**
   * @brief Get a PrdfConstantRegister
   * @param BitString - the bit string constant to use.
   * @post only one instance of the register with this BIT_STRING value will
   * exist.
   */
  SCAN_COMM_REGISTER_CLASS & GetConstantRegister(const BitStringBuffer & i_val);
  /**
   * @brief Get a plugin  register
   * @param Reference to target less flyweight object
   * @param RuleChip  associatd with register
   * @post only one instance of the register with this BIT_STRING value will
   * exist.
   */
  SCAN_COMM_REGISTER_CLASS & GetPluginRegister(
                                SCAN_COMM_REGISTER_CLASS & i_flyweight,
                                ExtensibleChip & i_RuleChip );
  /**
   * @brief Delete all the plugin  register
   * @param None
   * @post  all the ScomRegisterAccess register flyweight object created for
   *        plugin shall be deleted
   * exist.
   */
  void ResetPluginRegister();

  /**
   * @brief Intended to reset all the flyweights if PRD is uninitialized due to
   *        a reIPL, reset/reload, or failover. This free up the memory and
   *        avoids memory leaks in the flyweights.
   */
  void reset();

#ifdef FLYWEIGHT_PROFILING
/**
 * @brief       prints memory allocated for object residing on flyweight
 */
  void printStats();
#endif

  /**
   Destructor
   */
//  ~ScanFacility();
private:  // functions
  /**
   Constructor
   * @param
   * @returns
   * @pre
   * @post
   * @see
   * @note
   */
  ScanFacility() {}


private:  // Data
  typedef FlyWeightS<ScomRegister,50>           ScanCommRegisters;
  //FIXME RTC 64345 Investigate benefit of changing below from FlyWeight to
  //FlyWeightS
  typedef FlyWeight<AttnTypeRegister,50>        AttnTypeRegisters;
  typedef FlyWeightS<AndRegister,50>            AndRegisters;
  typedef FlyWeightS<OrRegister,10>             OrRegisters;
  typedef FlyWeightS<NotRegister,50>            NotRegisters;
  typedef FlyWeightS<LeftShiftRegister,10>      LeftShiftRegisters;
  typedef FlyWeightS<RightShiftRegister, 10>    RightShiftRegisters;
  typedef FlyWeightS<SummaryRegister,10>        SummaryRegisters;
  typedef FlyWeight<ConstantRegister, 10>       ConstantRegisters;
  typedef FlyWeightS<ScomRegisterAccess, 10>    PluginRegisters;

  ScanCommRegisters     iv_scomRegFw;
  AttnTypeRegisters     iv_attnRegFw;
  AndRegisters          iv_andRegFw;
  OrRegisters           iv_orRegFw;
  NotRegisters          iv_notRegFw;
  LeftShiftRegisters    iv_leftRegFw;
  SummaryRegisters      iv_sumRegFw;
  RightShiftRegisters   iv_rightRegFw;
  ConstantRegisters     iv_constRegFw;
  PluginRegisters       iv_pluginRegFw;

};

} // end namespace PRDF

#endif /* PRDFSCANFACILITY_H */
