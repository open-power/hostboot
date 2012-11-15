/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipErrorRegisterSet.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1997,2012              */
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

#ifndef iipErrorRegisterSet_h
#define iipErrorRegisterSet_h

// Class Description *************************************************
//
//  Name:  ErrorRegisterSet
//  Base class: ErrorRegisterMask
//
//  Description: To be used when the bits on in the error register
//               represent a set of errors reported and the error
//               analysis is to a union of the Resolutions
//               for each error bit.
//
//  Usage: See iipErrorRegister.h
//
//  Warning:
//   If this class is used with recoverable errors then all bits on are
//   masked when ANY threshold is detected, therefore the chip should
//   mask the hardware accordingly.
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipErrorRegisterMask_h)
#include <iipErrorRegisterMask.h>
#endif

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

class ErrorRegisterSet: public ErrorRegisterMask
{
public:
  ErrorRegisterSet(SCAN_COMM_REGISTER_CLASS & r,
                   ResolutionMap & rm,
                   FILTER_CLASS * f = NULL);
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   None
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  //~ErrorRegisterSet();
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

  virtual int32_t Analyze(STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Analyze the error(s) reported by this error register
  // Parameters:   Reference to area to return Service Data
  // Returns:      Return code
  // Requirements: None.
  // Promises:     At least one Resolution called (See notes)
  //               Service data error signature scrid and error code modified
  //               if register has no bits on then
  //                  rc = PRD_SCAN_COMM_REGISTER_ZERO (iipconst.h)
  //               If rc != SUCCESS then no promises
  // Exceptions:   Simulator may throw TBD otherwise none.
  // Concurrency:
  // Notes:
  //                A Resolution called for Each bit that's on in the error
  //                register.
  //                If no resolutions exist for a bit then the
  //                ResolutionMap default Resolution is Called.
  //
  // End Function Specification ****************************************
private:  // functions
private:  // Data

};

#endif /* iipErrorRegisterSet_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       p4901848 v4r1 02/20/97 DGILBERT   Initial Creation
//
// End Change Log *****************************************************
