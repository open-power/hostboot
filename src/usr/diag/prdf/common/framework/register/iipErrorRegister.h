/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipErrorRegister.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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
 @file iipErrorRegister.h
 @brief ErrorRegister class declaration
*/
#ifndef iipErrorRegister_h
#define iipErrorRegister_h

// Class Description *************************************************
//
//  Name:  ErrorRegister
//  Base class:  ErrorRegisterType
//  Concrete class that can be used as a base class
//
//  Description: Error register declairation
//  Usage:
//
//  foo(SCAN_COMM_REGISTER &scr, ResolutionMap &resMap,
//      STEP_CODE_DATA_STRUCT &error_data)
//  {
//    ErrorRegister er(scr,resMap);
//    .
//    .
//    SINT32 rc = er.Analyze(error_data);
//  }
//
//  Notes:
//
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#if !defined(iipErrorRegisterType_h)
#include "iipErrorRegisterType.h"
#endif

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

class SCAN_COMM_REGISTER_CLASS;
class ResolutionMap;

class ErrorRegister : public ErrorRegisterType
{
public:
  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register
   <br><b>Parameter:   </b> Resolution Map
   <br><b>Parameter:   </b> Opt: ScrId [0 to 0xfe] - used with ErrorSignature
   <br><b>Notes:       </b> If no ScrId is provided then the scan
                            Comm register address is used
   </ul><br>
   */
  ErrorRegister(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, uint16_t scrId = 0x0fff);

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
  // Objects do not not own ptr to scan comm register and table
  //
  // End Function Specification ****************************************
  // ~ErrorRegister();

  /**
   Analyse the error register
   <ul>
   <br><b>Parameters:  </b> ServiceData object (error.service_data)
   <br><b>Returns:     </b> return code
   <br><b>Requirements:</b> NoErrorOnZeroRead() if don't want rc == DD02 when no bits on in scr
   <br><b>Promises:    </b> error.service_data points to completed serviceData
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> optional
   </ul><br>
   */
  virtual int32_t Analyze(STEP_CODE_DATA_STRUCT & error);

  /**
   Make is so Analyze() does not consider a Scr bit string of all zeros an error
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Analyze() == SUCCESS when scr data has no bits on
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Normaly Anayze() returns DD02 if scr data is zero
   </ul><br>
   */
  void NoErrorOnZeroScrRead(void) { xNoErrorOnZeroScr = true; }


protected:

  /**
   Read the scan comm register, apply any masks, and return the resulting bit string
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
  virtual const BIT_STRING_CLASS & Read(ATTENTION_TYPE i_attn);

  /**
   Filter the bit string (if a filter is provided) & convert it to a BitList
   <ul>
   <br><b>Parameters:  </b> Bit String
   <br><b>Returns:     </b> Bit List
   <br><b>Requirements:</b> Read()
   <br><b>Promises:    </b> Bit list representation of the (filtered) bit string
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> The default implementation does not have a filter
   </ul><br>
   */
  virtual BIT_LIST_CLASS Filter(const BIT_STRING_CLASS & bs);

  virtual bool FilterUndo(BitKey & i_bit_list) { return false; }
  /**
   Find a resolution for the Bit List
   <ul>
   <br><b>Parameters:  </b> reference to ServiceDataCollector to act on
   <br><b>Parameter:   </b> Bit List
   <br><b>Requirements:</b> Filter()
   <br><b>Promises:    </b> The bit list may be modified if the search
                            algoithm modified it to find a match. (as in a fuzzy search)
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> If no match for the Bit List is found in the
                            Resolution Map then the ResolutionMap default is used
   </ul><br>
   */
  virtual int32_t Lookup(STEP_CODE_DATA_STRUCT & scd, BIT_LIST_CLASS & bl); // dg02c - pass bl by value

  /**
   Reset the hardware (if needed)
   <ul>
   <br><b>Parameters:  </b> Bit List, ServiceData (error.service_data)
   <br><b>Returns:     </b> return code
   <br><b>Requirements:</b> LookUp()
   <br><b>Promises:    </b> Hardware may be modified, internal Mask may be modified
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Default implementation does nothing
   </ul><br>
   */
  virtual int32_t Reset(const BIT_LIST_CLASS & bit_list,STEP_CODE_DATA_STRUCT & error);

private:  // functions

  int32_t SetErrorSignature(STEP_CODE_DATA_STRUCT & error, BIT_LIST_CLASS & bl); // dg02a
  /**
   Copy forbidden
   */
  ErrorRegister(const ErrorRegister & er);
  /**
   Assignment forbidden
   */
  ErrorRegister & operator=(const ErrorRegister & er);

protected: // Data

  SCAN_COMM_REGISTER_CLASS & scr;
  int32_t scr_rc;

private:  // Data

  ResolutionMap & rMap;
  bool xNoErrorOnZeroScr;
  uint16_t xScrId;

};

} // end namespace PRDF

#endif /* iipErrorRegister_h */

