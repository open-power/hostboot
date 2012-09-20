/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/resolution/prdfErrorTypeResolution.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2012              */
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

#ifndef prdfErrorTypeResolution_H
#define prdfErrorTypeResolution_H
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
#endif

#if !defined(iipServiceDataCollector_h)
#include <iipServiceDataCollector.h>
#endif

/**
 @file prdfErrorTypeResolution.H
 @brief Set the appropiate error type in the SDC and flag for
        Gard if necessary.
*/
class prdfErrorTypeResolution : public Resolution
{
public:

  enum ErrorType
  {
    Repairable    = 0,
    Correctable   = 1,
    Uncorrectable = 2,
    Fatal         = 3,
    Catastrophic  = 4
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
  prdfErrorTypeResolution(ErrorType et)
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
  //  ~ErrorTypeResolution();

  /**
   Resolve by adding the error type to the service data collector
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector
   <br><b>Returns:     </b> Return code [SUCCESS | nonZero]
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> sdc.GetErrorType() == ErrorType
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & sdc);

private:  // functions
private:  // Data

  ErrorType xErrorType;

};


#endif /* prdfErrorTypeResolution_H */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder   Description
//  ---- -------- ---- -------- ------- -------------------------------
//                     02/26/03 mkobler  Initial Creation
//
// End Change Log *****************************************************
