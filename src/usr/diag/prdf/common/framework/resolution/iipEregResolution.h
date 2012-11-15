/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipEregResolution.h $ */
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

#ifndef iipEregResolution_h
#define iipEregResolution_h

// Class Description *************************************************
//
//  Name:  EregResolution     concrete class
//  Base class: Resolution
//
//  Description: Resolve an error by analyzing an error register
//  Usage:
//
//    ResolutionMap ereg1Resolutions(...);
//    ErrorRegister ereg1(....);
//    ErrorRegister ereg2(....);
//
//    Resolution *r = new EregResolution(ereg2);
//    ereg1Resolutions.add(BIT_LIST_STRING_20,r); // If bit 20 of ereg1 on then
//                                                // Resolution = ereg2.Analyze();
//
//
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class ErrorRegisterType;

class EregResolution : public Resolution
{
  public:
  EregResolution();
  EregResolution(ErrorRegisterType & er);
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   ErrorRegister object to be invoked by Resolve()
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  // ~EregResolution();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficient
  //
  // End Function Specification ****************************************
  // Copy ctor   - compiler default is sufficient
  // Assignment  - compiler default is sufficient

    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & data);
  // Function Specification ********************************************
  //
  // Purpose:
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficient
  //
  // End Function Specification ****************************************

  private:  // functions
  private:  // Data

    ErrorRegisterType * errorRegister;

};

inline
EregResolution::EregResolution(ErrorRegisterType &er)
: errorRegister(&er) {}

inline
EregResolution::EregResolution()
  : errorRegister(NULL) {}

#endif /* iipEregResolution_h */

// Change Log *********************************************************
//
//  Flag Reason  Vers Date     Coder    Description
//  ---- ------- ---- -------- -------- -------------------------------
//              v4r1m0 05/13/96  DRG    Initial Creation
//  pw01 494911  f310 03/04/05 iawillia Use ErrorRegisterType instead of
//                                          ErrorRegister.
//                   f522283 fips300 09/27/05 dgilbert Make class FlyWeight -able
// End Change Log *****************************************************
