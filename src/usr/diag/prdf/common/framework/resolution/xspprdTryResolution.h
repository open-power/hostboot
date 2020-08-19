/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdTryResolution.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 1998,2020                        */
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

#ifndef xspprdTryResolution_h
#define xspprdTryResolution_h

// Class Description *************************************************
//
//  Name:  TryResolution
//  Base class: Resolution
//
//  Description: Try a resolution  - if it does not work then
//               call a default resolution
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
/**
 **One line Class description**
 @author Doug Gilbert
 */
class TryResolution: public Resolution
{
public:
  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Resolution to try first
   <br><b>Parameter:   </b> Resolution if the try resolution fails
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  TryResolution(Resolution &tryRes, Resolution & defaultRes);
  TryResolution();

  /*
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
  //  ~TryResolution();

  /**
   ** description **
   <ul>
   <br><b>Parameters:  </b> parms
   <br><b>Returns:     </b> return
   <br><b>Requirements:</b> preconditions
   <br><b>Promises:    </b> postconditions
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> optional
   </ul><br>
   */

  /**
   Resolve by calling TryResolution else call DefaultResolution
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector
   <br><b>Returns:     </b> Return code [SUCCESS | nonZero]
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> if(TryResolution.Resolve() != SUCCESS)
                            then xDefaultResolution.Resolve();
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error,
                          bool i_default = false);

private:  // functions
private:  // Data

Resolution * xTryResolution;
Resolution * xDefaultResolution;

};

inline
TryResolution::TryResolution(Resolution &tryRes, Resolution & defaultRes)
: xTryResolution(&tryRes), xDefaultResolution(&defaultRes) {}

inline
TryResolution::TryResolution()
  : xTryResolution(nullptr), xDefaultResolution(nullptr) {}

} // end namespace PRDF

#endif /* xspprdTryResolution_h */

