/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdFlagResolution.h $ */
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

#ifndef xspprdFlagResolution_h
#define xspprdFlagResolution_h

// Class Description *************************************************
//
//  Name:  FlagResolution
//  Base class: Resolution
//
//  Description: Set a Flag in the Service Data Collector
//  Usage:
//
// End Class Description *********************************************

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
 Set a Flag in the Service Data Collector
 @author Mike Kobler
 */
class FlagResolution : public Resolution
{
public:
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
  FlagResolution(ServiceDataCollector::Flag flag)
  : xFlag(flag) {}
  FlagResolution()
    : xFlag(ServiceDataCollector::SERVICE_CALL) {}

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
  //  ~xspprdFlagResolution();

  /**
   Resolve by adding a the MRU callout to the service data collector
   <ul>
   <br><b>Parameters:  </b> ServiceDataCollector
   <br><b>Returns:     </b> Return code [SUCCESS | nonZero]
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> serviceData::GetMruList().GetCount()++
   serviceData::QueryFlag() == this callout
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error);

  /*
   * base class defines operator== so one is needed here
   * or the base class version will be used (bad)
   */
  bool operator==(const FlagResolution & r) const
  {
    return (xFlag == r.xFlag);
  }

private:  // functions
private:  // Data

  ServiceDataCollector::Flag xFlag;

};


#endif /* xspprdFlagResolution_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder   Description
//  ---- -------- ---- -------- ------- -------------------------------
//       D49420.9 V5R2 12/04/00 mkobler Initial Creation
//       f522283   300 09/27/05 dgilbert make FlyWeight-able
//       D608564  f310 05/18/07 dgilbert add operator==() to fix mem leak
//
// End Change Log *****************************************************
