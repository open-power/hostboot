/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfScanFacility.H $ */
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
    @code
      ScanFacility & sf = ScanFacility::Access();
      SCAN_COMM_REGISTER_CLASS & scr = sf.GetScanCommRegister(chipId,Address,bitLen);
      scr.Read() ... see iipscr.h
      ScanRingField srf[] =
      {{hregAliasId1 , fieldBitLength1},
       {hregAliasId2 , fieldBitLength2}};
      SCAN_COMM_REGISTER_CLASS & sr = s.GetScanRingRegister(aTARGETING::
      TargetHandle_t,srf,srf+2);
      scr.Read() .... SCAN_COMM_REGISTER_CLASS
      // Note you can't write a scan ring register from PRD
      // you can only read scan ring registers from PRD if the global attention
      // type is CHECK_STOP
    @endcode
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
    * @return   returns reference to flyweight object from factory
    */
   SCAN_COMM_REGISTER_CLASS & GetScanCommRegister(
                    uint64_t address ,uint32_t i_scomLength,
                    TARGETING::TYPE i_type );

  /**
   Get a scan ring register
   * @param i_ptargetHandle        handle to target in targeting
   * @param pointer to list an array of ScanRingField  see prdfHomRegisterAccess.H
   * @param pointer to last entry+1 of ScanFingField array
   * @pre   AliasId's for the scan ring registers MUST exist in the function unit
          associated with the Id given
   * @post  Access object and scr created for this register. the bit length of the
          scr returned will be the sum of all the field lengths provided.
   * @note  an SCR based on a scan ring register can not be written, and should
          only be read if the global
    attention type is CHECK_STOP.
   */

//FIXME  Need to discuss before deleting the function below
#if 0
  SCAN_COMM_REGISTER_CLASS & GetScanRingRegister(
                                TARGETING::TargetHandle_t i_ptargetHandle,
                                ScanRingField * start,
                                ScanRingField * end);
#endif

  /**
   * @brief  Get a register that bitwise inverts the bitstring of a register
   *         when read or written to
   * @param  SCAN_COMM_REGISTER_CLASS source
   * @post   Only one instance of the register with this SCR paramter will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetNotRegister(SCAN_COMM_REGISTER_CLASS & i_arg);

  /**
   * @brief  Get a register that bitwise left shift the bitstring of a register
   *         when read or written to
   * @param  SCAN_COMM_REGISTER_CLASS source
   * @post   Only one instance of the register with this SCR paramter and amount
     @       will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetLeftShiftRegister(
                        SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount);

  /**
   * @brief Get a register that bitwise right shift the bitstring of a register
   *        when read or written to
   * @param SCAN_COMM_REGISTER_CLASS source
   * @post  Only one instance of the register with this SCR paramter and amount
   * @      will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetRightShiftRegister(
                        SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount);



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
   * @params 3 scr Registers
   * @post only one instance of the register with these SCR's will exist
   */
  SCAN_COMM_REGISTER_CLASS & GetAttnTypeRegister(
                                    SCAN_COMM_REGISTER_CLASS & i_check,
                                    SCAN_COMM_REGISTER_CLASS & i_recov,
                                    SCAN_COMM_REGISTER_CLASS & i_special,
                                    SCAN_COMM_REGISTER_CLASS & i_proccs);

  /**
   * @brief Get a PrdfConstantRegister
   * @param BIT_STRING_CLASS - the bit string constant to use.
   * @post only one instance of the register with this BIT_STRING value will
   * exist.
   */
  SCAN_COMM_REGISTER_CLASS & GetConstantRegister(BIT_STRING_CLASS i_val);
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
#ifdef __MEM_PROFILING
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
  typedef FlyWeight<ConstantRegister, 10>       ConstantRegisters;
  typedef FlyWeightS<ScomRegisterAccess, 10>    PluginRegisters;

  ScanCommRegisters     iv_scomRegFw;
  AttnTypeRegisters     iv_attnRegFw;
  AndRegisters          iv_andRegFw;
  OrRegisters           iv_orRegFw;
  NotRegisters          iv_notRegFw;
  LeftShiftRegisters    iv_leftRegFw;
  RightShiftRegisters   iv_rightRegFw;
  ConstantRegisters     iv_constRegFw;
  PluginRegisters       iv_pluginRegFw;

};

} // end namespace PRDF

#endif /* PRDFSCANFACILITY_H */
