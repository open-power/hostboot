/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/register/iipErrorRegisterType.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

#ifndef iipErrorRegisterType_h
#define iipErrorRegisterType_h

// Class Description *************************************************
//
//  Name:  iipErrorRegisterType ABC
//  Base class: None
//
//  Description:
//  Usage:
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(IIPBTLST_H)
#include <prdfBitKey.H>
#endif

#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

#include <iipsdbug.h>
//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class BIT_STRING_CLASS;
struct STEP_CODE_DATA_STRUCT;

class ErrorRegisterType
{
  public:
//  ERROR_REGISTER_CLASS();
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   None
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        Compiler default = ok
  //
  // End Function Specification ****************************************

    virtual ~ErrorRegisterType() {}
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:
  //
  // End Function Specification ****************************************

  virtual int32_t Analyze(STEP_CODE_DATA_STRUCT & error) = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Analyze the error reported by this error register
  // Parameters:   Reference to area to return Service Data
  // Returns:      Return code
  // Requirements: None.
  // Promises:     Provide service data for the error condition reported
  //               by the hardware error register this object represents
  // Exceptions:   Simulator may throw TBD otherwise None.
  // Concurrency:
  // Notes:
  //
  // End Function Specification ****************************************

protected:

  virtual const BIT_STRING_CLASS & Read(ATTENTION_TYPE i_attn) = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Read data in from hardware for this error register
  // Parameters:   None
  // Returns:      Reference to a bit string containing the data read
  // Requirements: None.
  // Promises:     Returns a reference to the bit string containing the
  //               value read . May return NULL if hardware access failed.
  // Exceptions:   None. (Future: May throw Ereg_Read_Failure)
  // Concurrency:
  // Notes:
  //
  // End Function Specification ****************************************

  virtual prdfBitKey Filter(const BIT_STRING_CLASS & bs) = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Filter out unwanted bits in the bit string.
  // Parameters:   References to the bit string read in.
  // Returns:      Reference to a bit list
  // Requirements: None.
  // Promises:     Return a bit list containing the desired pattern to
  //               use to find an Resolution to execute.
  // Exceptions:   None.
  // Concurrency:
  // Notes:
  //
  // End Function Specification ****************************************

  virtual bool FilterUndo(prdfBitKey & i_bit_list) = 0;

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
  virtual int32_t Lookup(STEP_CODE_DATA_STRUCT & sdc, prdfBitKey & bl) = 0; //dg02c

  virtual int32_t Reset(const prdfBitKey & bit_list,STEP_CODE_DATA_STRUCT & error) = 0;
  // Function Specification ********************************************
  //
  // Purpose:      Reset the hardware & perform any other actions needed
  //               to prepare for the next Analysis
  // Parameters:   Reference to a bit list
  // Returns:      Return code
  // Requirements: None.
  // Promises:     Hardware register may be modified
  //               May do nothing if nothing is needed.
  // Exceptions:   None.
  // Concurrency:
  // Notes:
  //
  // End Function Specification ****************************************

};


#endif /* iipErrorRegisterType_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder Description
//  ---- -------- ---- -------- ----- -------------------------------
//               v4r1m0 04/03/96 DRG  Initial Creation from iiperst.h
//                                    Abstraction of error register class
//       p4902214 v4r1m0 05/09/97 DRG   Added service data parm to Reset
//  dg02 482244 fips225 11/05/04 dgilbert change Lookup() to pass bl by value
//       558003 fips310 06/21/06 dgilbert add FilterUndo()
//
// End Change Log *****************************************************
