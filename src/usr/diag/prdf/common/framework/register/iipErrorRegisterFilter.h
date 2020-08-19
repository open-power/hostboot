/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipErrorRegisterFilter.h $ */
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

#ifndef iipErrorRegisterFilter_h
#define iipErrorRegisterFilter_h

/**
 @file iipErrorRegisterFileter.h
 @brief ErrorRegisterFilter class declaration
*/

// Class Description *************************************************
//
//  Name:  ErrorRegisterFilter
//  Base class: ErrorRegister
//
//  Description: Error register with a filter
//  Usage: (see iipErrorRegisterMask.h)
//
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#if !defined(iipErrorRegister_h)
#include <iipErrorRegister.h>
#endif
#include <prdfFilters.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 Error register class with filtering capabilities
 @author Doug Gilbert
 */
class ErrorRegisterFilter : public ErrorRegister
{
public:

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register to get bitString from hardware
   <br><b>Parameter:   </b> Resolution map to map bit pattern to a resolution
   <br><b>Parameter:   </b> scan comm register id for error signature
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, uint16_t scrId = 0x0fff);

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register to get bitString from hardware
   <br><b>Parameter:   </b> Resolution map to map bit pattern to a resolution
   <br><b>Parameter:   </b> Filter to apply to bit string before mapping it
   <br><b>Parameter:   </b> scan comm register id
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  ErrorRegisterFilter( SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm,
                       FilterClass * f, uint16_t scrId = 0x0fff );

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Compiler default is OK
   </ul><br>
   */
   //~ErrorRegisterFilter();

  /**
   * @brief Get the stored filter associated with this resolution map.
   * @returns Currently assigned filter.
   */
  FilterClass * getFilter() const { return filter; };

  /**
   * @brief Store a new filter with this resolution map.
   * @param i - FilterClass to store.
   */
  void setFilter(FilterClass * i_filter) { filter = i_filter; };

protected:  // functions

  /**
   * @brief Filter the bit string and  convert it to a BitList
   * @param   i_bs      bit string
   * @param   io_sdc    reference to STEP_CODE_DATA struct
   * @return  bit key
   */
  virtual BitKey Filter( const BitString & bs,
                         STEP_CODE_DATA_STRUCT & io_sdc );

  /**
   * Certain filters need to be reversed in order for Reset() to work right
   * @return bit_list modified ? [true|false]
   * @see Filters.H
   */
  virtual bool FilterUndo(BitKey & i_bit_list)
  {
    bool modified = false;
    if(filter) modified = filter->Undo(i_bit_list);
    return modified;
  }

private: // functions

  /** Copy forbidden - no definition exists */
  ErrorRegisterFilter(const ErrorRegisterFilter & er);
  /** Assignment forbidden - no definition exists */
  ErrorRegisterFilter & operator=(const ErrorRegisterFilter & er);

protected: // data

  FilterClass * filter;

private:  // Data

};

inline
ErrorRegisterFilter::ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r,
                                         ResolutionMap & rm,
                                         uint16_t scrId)
: ErrorRegister(r,rm,scrId), filter(nullptr)
{}

inline
ErrorRegisterFilter::ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r,
                                         ResolutionMap & rm,
                                         FilterClass * f,
                                         uint16_t scrId)
: ErrorRegister(r,rm,scrId), filter(f)
{}

} // end namespace PRDF

#endif /* iipErrorRegisterFilter_h */

