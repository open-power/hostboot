/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipErrorRegisterMask.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef iipErrorRegisterMask_h
#define iipErrorRegisterMask_h

/**
 @file iipErrorRegisterMask.h
 @brief ErrorRegisterMask class declaration
*/

// Class Description *************************************************
//
//  Name:  ErrorRegisterMask
//  Base class:  ErrorRegister
//  Concrete class that can be used as a base class
//
//  Description: Maskable & Filterable Error register declairation
//--------------
//  Usage:
//  foo(SCAN_COMM_REGISTER &scr, ResolutionMap &resMap,
//      STEP_CODE_DATA_STRUCT &error_data)
//  {
//    ErrorRegisterMask erm(scr,resMap);
//    uint32_t mask_data[] = {0x00000000, 0xFFFFFFFF};
//    erm.SetMaskBits(BitString(64,mask_data));
//    ...
//    int32_t rc = er.Analyze(error_data);
//    ...
//    erm.SetMaskBit(15);
//  }
//--------------------
//  Filter example
//
//  FILTER_PRIORITY_CLASS filter(BIT_LIST_STRING_1); // bit 1 takes priority
//  ErrorRegisterMask erm(scr,resMap,&filter);       // if it's on
//  ...
//  int32_t rc = erm.Analyze(error_data);
//
//  Notes:
//
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipErrorRegisterFilter_h)
#include <iipErrorRegisterFilter.h>
#endif

#include <prdfBitString.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
  Error register with bit masking capabilities
  @version V4R5
*/
class ErrorRegisterMask : public ErrorRegisterFilter
{
public:

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> ScanCommRegister
   <br><b>Parameter:   </b> Resolution map
   <br><b>Parameter:   </b> Optional Filter
   <br><b>Parameter:   </b> Optional scrId
   <br><b>Parameter:   </b> Optional maskScan comm register
   <br><b>Notes:       </b> If no ScrId is provided then the scan
                            Comm register address is used
   </ul><br>
   */
  ErrorRegisterMask(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, FILTER_CLASS * f = nullptr, uint16_t scrId = 0x0fff, SCAN_COMM_REGISTER_CLASS & maskScr = *((SCAN_COMM_REGISTER_CLASS *) nullptr)); // dg00

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> ScanCommRegister
   <br><b>Parameter:   </b> Resolution map
   <br><b>Parameter:   </b> scrId - for the signature
   <br><b>Parameter:   </b> Optional maskScan comm register
   </ul><br>
   */
  ErrorRegisterMask(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, uint16_t scrId, SCAN_COMM_REGISTER_CLASS & maskScr = *((SCAN_COMM_REGISTER_CLASS *) nullptr)); // dg00

  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is ok
  //
  // End Function Specification ****************************************
  // ~ErrorRegisterMask();

  /**
   Set a mask bit
   <ul>
   <br><b>Parameters:  </b> bit position
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> bitStringMask.isBitSet(bitPosition) == true.

   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> The bitstring read from hardware during Read()
                            will have this bitpos reset (zeroed) prior to using
                            it for any Analysis.
   </ul><br>
   */
  void SetMaskBit(uint32_t bitPosition);

  /**
   Set mask bits
   <ul>
   <br><b>Parameters:  </b> BitString
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> bitStringMask != bitString;

   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> The bitstring read from hardware during Read()
                            will have the bit positions reset (zeroed) as
                            specified in the bitStringMask (by 1's) prior
                            to using it for any Analysis.
   </ul><br>
   */
  void SetMaskBits(const BitString & bitString);

protected:

  /**
   Read the scan comm register, apply the mask, and return the resulting bit string
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> a Bit String
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Bit string contains data from hardware with masked bits zeroed
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Any class that overides Read() but does not
                            override Analyze() should set src_rc
                            return code from mops scr access
   </ul><br>
   */
  virtual const BitString & Read();


  /**
   Reset the error register and set mask bit if sdc is at threshold
   <ul>
   <br><b>Parameters:  </b> BitList
   <br><b>Returns:     </b> return code
   <br><b>Requirements:</b> Filter()
   <br><b>Promises:    </b> if xMaskScr == nullptr then
                               bitStringMask bit(s) set if error.service_data->IsAtThreshold()
                            ELSE bitStringMask remains unchanged
                            Hardware may be modified
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  virtual int32_t Reset( const BIT_LIST_CLASS & bit_list,
                         STEP_CODE_DATA_STRUCT & error );

private:  // functions
  /** Copy forbidden  - no definition (code) exists*/
  ErrorRegisterMask(const ErrorRegisterMask & er);
  /** Assignment forbidden - no definition (code) exists */
  ErrorRegisterMask & operator=(const ErrorRegisterMask & er);

protected: // Data

  BitStringBuffer   bitString;
  BitStringBuffer   bitStringMask;

private:  // Data

  SCAN_COMM_REGISTER_CLASS & xMaskScr;    // dg00
//  bool  maskIt;

};

inline void ErrorRegisterMask::SetMaskBit(uint32_t bitPosition)
{ bitStringMask.setBit(bitPosition); }

inline void ErrorRegisterMask::SetMaskBits(const BitString & bitString)
{ bitStringMask.setString(bitString); }

} // end namespace PRDF

#endif /* iipErrorRegisterMask_h */

