/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/resolution/iipCallAttnResolution.h $ */
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

#ifndef iipCallAttnResolution_h
#define iipCallAttnResolution_h

// Class Description *************************************************
//
//  Name:  CallAttnResolution
//  Base class: Resolution
//
//  Description: A resolution to call all chips raising attention
//  Usage:  See iipResolution.h
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
//class CalloutMap;

class CallAttnResolution : public Resolution
{
public:
//  CallAttnResolution(CalloutMap & callmap);
  CallAttnResolution() {}
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   Object that maps chipId's to Callouts
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Object created
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:
  //
  // End Function Specification ****************************************

  // ~CallAttnResolution();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes: Compiler default defn is sufficent
  //
  // End Function Specification ****************************************

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);
  // Function Specification ********************************************
  //
  // Purpose:      Resolve service data - callout all chips at attention as
  //               reported by the service processor sysdebug area.
  // Parameters:   Reference to the Step code data structure
  // Returns:      return code
  // Requirements: None
  // Promises:     if rc = SUCCESS then
  //                   ServiceData signature set, Callout list modified
  // Exceptions:   None
  // Concurrency:  synchronous
  // Notes:        if rc != SUCCESS then state of service data is unpredictable
  //
  // End Function Specification ****************************************
private:  // functions
private:  // Data

//  CalloutMap & calloutMap;

};

//inline
//CallAttnResolution::CallAttnResolution(CalloutMap & callmap)
//: calloutMap(callmap)
//{
//}

#endif /* iipCallAttnResolution_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder Description
//  ---- -------- ---- -------- ----- -------------------------------
//                              DRG   Initial Creation
//
// End Change Log *****************************************************
