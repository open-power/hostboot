/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdFlagResolution.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2013              */
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
#include <iipResolution.h>

#include <iipServiceDataCollector.h>

namespace PRDF
{

/**
 Set a Flag in the Service Data Collector
 @author Mike Kobler
 */
class FlagResolution : public Resolution
{
public:
  /**
   * @brief     Constructor
   * @param[in] i_flag  flag resolution
   */

  FlagResolution( ServiceDataCollector::Flag i_flag ): xFlag( i_flag )
  { }

  /**
   * @brief     Constructor
   */
  FlagResolution() : xFlag( ServiceDataCollector::SERVICE_CALL )
  { }


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
  * @brief      sets a flag in service data collector
  * @param[io]  io_serviceData Reference to STEP_CODE_DATA_STRUCT
  * @return     None
  */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_serviceData );

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

} // end namespace PRDF

#endif /* xspprdFlagResolution_h */

