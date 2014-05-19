/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdDumpResolution.H $ */
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

#ifndef prdDumpResolution_H
#define prdDumpResolution_H
// Class Description *************************************************
//
//  Name:  DumpResolution
//  Base class: Resolution
//
//  Description: Set dump information in Service Data Collector
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#include <iipResolution.h>

#ifdef __HOSTBOOT_MODULE
#include <prdfGlobal.H>
#else
#include <hdctContent.H>
#endif

#include <prdfPlatServices.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class ServiceDataCollector;

/**
 Set dump information in the Service Data Collector
 @author Mike Kobler
 */
class DumpResolution : public Resolution
{
public:
  /**
   * @brief     Constructor
   * @param[in] iDumpRequestContent
   * @return    Non-SUCCESS in internal function fails, SUCCESS otherwise.
   */
  DumpResolution( hwTableContent iDumpRequestContent = CONTENT_HW )
    : ivDumpContent( iDumpRequestContent )
  {}

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
  //  ~xspprdDumpResolution();

  /**
   * @brief     updates  the dump flag in service data collector
   * @param[io] io_serviceData Reference to STEP_CODE_DATA_STRUCT
   * @return    Non-SUCCESS in internal function fails, SUCCESS otherwise.
   */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_serviceData );

  /*
   * base class defines operator== so one is needed here
   * or the base class version will be used (bad)
   */
  bool operator == (const DumpResolution & r) const
  {
    return ( ivDumpContent  == r.ivDumpContent );
  }

private:  // functions
private:  // Data

  hwTableContent ivDumpContent;

};

} // end namespace PRDF

#endif /* xspprdDumpResolution_h */

