/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/xspprdAndResetErrorRegister.h $ */
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

#ifndef xspprdAndResetErrorRegister_h
#define xspprdAndResetErrorRegister_h

/**
 @file iipAndResetErrorRegister.h
 @brief AndResetErrorRegister declaration
*/

// Class Description *************************************************
//
//  Name:  AndResetErrorRegister
//  Base class: ErrorRegisterMask
//
//  Description: Resets the bit(s) in an error register that were used to
//               Analyze an error. Intended to be used with hardware
//               registers that support SCOM AND-Write to reset bits.
//               This has an advantage in that register is only written
//               to reset the bits as opposted to a read-modify-write.
//
//  Usage: See iipResetErrorRegister.h
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#ifndef iipErrorRegisterMask_h
#include <iipErrorRegisterMask.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
/**
    Reset Error register using And-Write
    @author Doug Gilbert
*/
class AndResetErrorRegister: public ErrorRegisterMask
{
  public:
/**
  Constructor
  <ul>
  <br><b>Parameter:   </b> Scan comm register to read from
  <br><b>Parameter:   </b> Resolution map (see iipResolutionMap.h)
  <br><b>Paramteer:   </b> Scan comm register to write to (for reset)
  <br><b>Parameter:   </b> Ptr to filter class (optional)
  <br><b>Parameter:   </b> Scan comm register id(optional)
  <br><b>Parameter:   </b> Scan comm Register of hardware mask (optional)
  <br><b>Returns:     </b> Nothing
  <br><b>Requirements:</b> (software) - None
  <br><b>Promises:    </b> Object created
  <br><b>Exceptions:  </b> None
  <br><b>Notes:       </b> Scan comm register to write to should be AND-write
                           in hardware or strange things will happen
  </ul><br>
*/
  AndResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,ResolutionMap & rm, SCAN_COMM_REGISTER_CLASS & resetScr, FILTER_CLASS * f = nullptr, uint16_t scrId = 0x0fff, SCAN_COMM_REGISTER_CLASS & maskScr = *((SCAN_COMM_REGISTER_CLASS *) nullptr));

/**
  Constructor
  <ul>
  <br><b>Parameter:   </b> Scan comm register to read from
  <br><b>Parameter:   </b> Resolution map (see iipResolutionMap.h)
  <br><b>Parameter:   </b> Scan comm register to Write to Reset the error
  <br><b>Parameter:   </b> Scan Comm Register id
  <br><b>Parameter:   </b> Scan comm Register of hardware mask (optional)
  <br><b>Returns:     </b> Nothing
  <br><b>Requirements:</b> (software) - None.
  <br><b>Promises:    </b> Object created
  <br><b>Exceptions:  </b> None
  <br><b>Notes:       </b> Scancomm register to write to should be AND-write in hardware
                           or results will not be as expected
  </ul><br>
*/
 AndResetErrorRegister(SCAN_COMM_REGISTER_CLASS & r,ResolutionMap & rm, SCAN_COMM_REGISTER_CLASS & resetScr, uint16_t scrId, SCAN_COMM_REGISTER_CLASS & r1 = *((SCAN_COMM_REGISTER_CLASS *) nullptr));


/**
  Destructor
  <ul>
  <br><b>Parameters:  </b> None.
  <br><b>Returns:     </b> No value returned
  <br><b>Requirements:</b> None.
  <br><b>Promises:    </b> None.
  <br><b>Exceptions:  </b> None.
  <br><b>Notes:       </b> Compiler default is sufficient
  </ul><br>
*/
//  ~xspprdAndResetErrorRegister();

protected:  // functions

  /**
   Reset the error register in hardware
   <ul>
   <br><b>Parameter:   </b> The bit listed used to Resolve the error
   <br><b>Parameter:   </b> The serviceData collector
   <br><b>Returns:     </b> Return code [SUCCESS | mops return code]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Bits listed in the bitList are turned off in the
                            corresponding hardware register
   hardware register.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Hardware register Modified. The a logical anding is done in hardware
   </ul><br>
   */
  virtual int32_t Reset(const BIT_LIST_CLASS & bit_list, STEP_CODE_DATA_STRUCT & error);

  private:  // functions
  /*
  copy constructor - prohibits coping - no definition should exist
  */
  AndResetErrorRegister(const AndResetErrorRegister & ares);

  /*
    Assignment operator - prohipits assignment - do definition should exist
  */
  AndResetErrorRegister & operator=(const AndResetErrorRegister & er);

 private:  // Data

   SCAN_COMM_REGISTER_CLASS & xAndResetScr;

};

inline AndResetErrorRegister::AndResetErrorRegister
(      SCAN_COMM_REGISTER_CLASS & r,
       ResolutionMap & rm,
       SCAN_COMM_REGISTER_CLASS & resetScr,
       FILTER_CLASS * f,
       uint16_t scrId,
       SCAN_COMM_REGISTER_CLASS & maskScr
  )
: ErrorRegisterMask(r,rm,f,scrId,maskScr), xAndResetScr(resetScr)
{}

inline AndResetErrorRegister::AndResetErrorRegister
(      SCAN_COMM_REGISTER_CLASS & r,
       ResolutionMap & rm,
       SCAN_COMM_REGISTER_CLASS & resetScr,
       uint16_t scrId,
       SCAN_COMM_REGISTER_CLASS & r1
)
: ErrorRegisterMask(r,rm,scrId,r1), xAndResetScr(resetScr)
{}

} // end namespace PRDF

#endif /* xspprdAndResetErrorRegister_h */

