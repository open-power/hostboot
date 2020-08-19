/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfClockResolution.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2009,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifndef prdfClockResolution_H
#define prdfClockResolution_H
// Class Description *************************************************
//
//  Name:  ClockResolution
//  Base class: Resolution
//
//  Description: Set dump information in Service Data Collector
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipResolution_h)
#include <iipResolution.h>
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
class ClockResolution : public Resolution
{
public:
  /**
   * @brief     constructor
   * @param[in] i_pTargetHandle  target pointer for clock source
   * @param[in] i_targetType  type of target connected to clock source
   * @return    Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    ClockResolution( TARGETING::TargetHandle_t i_pTargetHandle = nullptr,
                         TARGETING::TYPE i_targetType = TARGETING::TYPE_PROC ) :
                         iv_ptargetClock( i_pTargetHandle ),
                         iv_targetType( i_targetType )
    { }

  /**
   * @brief     Resolve by adding MRU callout to the service data collector
   * @param[io] io_data Reference to STEP_CODE_DATA_STRUCT
   * @return    Non-SUCCESS if an internal function fails, SUCCESS otherwise
  */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_data,
                           bool i_default = false );

  /*
   * base class defines operator== so one is needed here
   * or the base class version will be used (bad)
   */
  bool operator==(const ClockResolution & r) const
  {
    return ( ( iv_ptargetClock == r.iv_ptargetClock ) &&
             ( iv_targetType == r.iv_targetType ) );
  }

private:  // functions
private:  // Data

  TARGETING::TargetHandle_t iv_ptargetClock;
  TARGETING::TYPE iv_targetType ;
};

} // end namespace PRDF

#endif /* prdfClockResolution_H */

