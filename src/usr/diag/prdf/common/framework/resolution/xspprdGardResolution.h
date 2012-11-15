/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdGardResolution.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2012              */
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

#ifndef xspprdGardResolution_h
#define xspprdGardResolution_h

// Class Description *************************************************
//
//  Name:  GardResolution
//  Base class: Resolution
//
//  Description: Set the error type for the failure (determines whether
//               Gard will be called)
//  Usage:
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
/**
 Callout a mru and mark it for Gard (deallocation)
 @author Doug Gilbert
 */
class GardResolution : public Resolution
{
public:

  enum ErrorType
  {
    // No Gard is possible
    NoGard        = 0,
    // Recovered error at threshold
    Predictive    = 1,
    // An uncorrectable error occurred, but the machine continues to run
    Uncorrectable = 2,
    // Checkstop, failing resources can be removed to prevent future occurances
    Fatal         = 3,
    // Resource has spares that could be used to fix the problem via bist on the next IPL.
    Pending       = 4,
    // This is NoGard unless attn type is CheckStop, then it is Fatal (Func)
    CheckStopOnlyGard = 5,       //mp01
    //This is to allow Deferred Deconfig, with No Garding
    DeconfigNoGard = 6           //mp02
  };


  /**
   Constructor
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  GardResolution(ErrorType et=NoGard)
  : xErrorType(et) {}

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Compiler default sufficient
   </ul><br>
   */
  //  ~xspprdGardResolution();

  /**
   Resolve by adding a the MRU callout to the service data collector
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector
   <br><b>Returns:     </b> Return code [SUCCESS | nonZero]
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> serviceData::GetMruList().GetCount()++
   serviceData::QueryGard() == this callout
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

  bool operator==(const GardResolution & r) const
  {
    return (xErrorType == r.xErrorType);
  }

private:  // functions
private:  // Data

  ErrorType xErrorType;

};


#endif /* xspprdGardResolution_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder Description
//  ---- -------- ---- -------- ----- -------------------------------
//                     02/18/99 DRG   Initial Creation
//       D49420.8 v5r2 12/05/00 mak   Change to use PRDcallout
//                     05/18/07 drg   add operator==() to prevent memory leak
//  mp01 D672610  f320 08/28/08 plute Add CheckStopOnlyGard
//  mp02          f710 08/06/08 plute Add DeconfigNoGard
//
// End Change Log *****************************************************
