/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/xspprdFlagResolution.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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

