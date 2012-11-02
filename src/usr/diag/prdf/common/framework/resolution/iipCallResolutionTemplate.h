/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipCallResolutionTemplate.h $ */
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

#ifndef iipCallResolutionTemplate_h
#define iipCallResolutionTemplate_h

// Class Description *************************************************
//
//  Name:  CallResolutionTemplate
//  Base class: Resolution
//
//  Description: Call a specified member function on object of type class T
//    function signature: int32_t functname(STEP_CODE_DATA_STRUCT & error);
//  Usage:
//
//  CallResolutionTemplate<SixDamain> rd(&SixDomain,&SixDomain::Analyze);
//  ResolutionMap rm(...);
//  rm.Add(BIT_LIST_STRING_16,rd);
//
//  Resolution &r = rm.LookUp(BIT_LIST_CLASS(BIT_LIST_STRING_16));
//  r->Resolve(error);     // calls SixDomain::Analyze(error);
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#ifndef iipResolution_h
#include <iipResolution.h>
#endif

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

template<class T>
class CallResolutionTemplate : public Resolution
{
public:
  typedef int32_t (T::*FUNCT) (STEP_CODE_DATA_STRUCT &);

  CallResolutionTemplate(T *obj, FUNCT pf)
    : Resolution(),object(obj),pFunction(pf) {}
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

  //~CallResolutionTemplate();
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficent
  //
  // End Function Specification ****************************************

  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error)
  {
    return((object->*pFunction)(error));
  }
  // See Resolution.h

private:  // functions
  CallResolutionTemplate(const CallResolutionTemplate<T>&); // not allowed
  CallResolutionTemplate<T>& operator=(const CallResolutionTemplate<T>&);
private:  // Data

  T * object;
  FUNCT pFunction;

};

} // end namespace PRDF

#endif /* iipCallResolutionTemplate_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder Description
//  ---- -------- ---- -------- ----- -------------------------------
//                              DRG   Initial Creation
//
// End Change Log *****************************************************
