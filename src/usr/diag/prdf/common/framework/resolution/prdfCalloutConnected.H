/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutConnected.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef PRDFCALLOUTCONNECTED_H
#define PRDFCALLOUTCONNECTED_H
/**
   @file prdfCalloutConnected.H
   @brief A resolution to callout a connected MRU determined at the time of the error.
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipResolution.h>
#include <prdfPlatServices.H>
#include <prdfCallouts.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;

/**
    This resolution calls out a connected MRU.
    @author Doug Gilbert
    @par
      This resolution calls out a connected MRU, but waits until the time of the error
      to determine whats connected.  This allows for runtime GARD, dynamic failover and concurrent
      maintenance - without having to call PRD to re-build itself.
    @code
     CalloutConnected iv_callout(PROC, TYPE_MCS ....);
     // ......
     // This will add the MCSs thats connected to this PROC to the callout list
     iv_callout.Resolve(serviceData);
    @endcode
    @note Don't use this class to callout clocks - use prdfClockResolution
*/
class CalloutConnected : public Resolution
{
public:
  /**
   default ctor
   */
  CalloutConnected(void);

  /**
   * @brief       Constructor
   * @param[in]   i_targetType      type of desired unit that's connected to
   *                                i_psourceHandle
   * @param[in]   i_idx             index into getConnected list to callout
   *                                (i_idx = 0xffffffff means callout the first
   *                                valid target)
   * @param[in]   i_priority        callout priority  @see srci.H for priority
   *                                values
   * @param[in]   i_altResolution   to use if the connection does not exist or
   *                                is invalid.
   *                                If NULL than source is called out
   * @param[i]    i_peerConnType    type of unit that is peer connected to
   *                                i_targetType
   * @note        Don't use this class to callout clocks - use ClockResolution
   */
  CalloutConnected( TARGETING::TYPE i_targetType,
                    uint32_t i_idx =0xffffffff ,
                    PRDpriority i_priority = MRU_MED,
                    Resolution * i_altResolution = NULL,
                    TARGETING::TYPE i_peerConnType = TARGETING::TYPE_NA );

  // ~CalloutConnected(); default dtor is sufficient

  /**
   * @brief     calls out the target connected to target under analysis.
   * @param[io] io_service_data  Reference to STEP_CODE_DATA_STRUCT
   * @post      service_data is complete
   * @return    SUCCESS | non-zero
   * @note      if the call to getConnected yields an invalid  target then
   *            altResolution is called. If the altResolution is NULL than the
   *            source is added to the callout list.
   */
  virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_service_data );

  virtual bool operator==(const CalloutConnected & r) const;

private:  // functions
private:  // Data

  TARGETING::TYPE iv_targetType;
  uint32_t iv_idx;
  PRDF::PRDpriority iv_priority;
  Resolution * iv_altResolution;
  TARGETING::TYPE iv_peerConnType;
};

inline CalloutConnected::CalloutConnected(void)
: iv_targetType(TARGETING::TYPE_NA),
  iv_idx(0xffffffff ),
  iv_priority(MRU_LOW),
  iv_altResolution(NULL),
  iv_peerConnType(TARGETING::TYPE_NA)
{}

inline CalloutConnected::CalloutConnected( TARGETING::TYPE i_targetType,
                                           uint32_t i_idx,
                                           PRDpriority i_priority,
                                           Resolution * i_altResolution,
                                           TARGETING::TYPE i_peerConnType ):
                                           iv_targetType( i_targetType ),
                                           iv_idx( i_idx ),
                                           iv_priority( i_priority ),
                                           iv_altResolution( i_altResolution ),
                                           iv_peerConnType(i_peerConnType)
{ }

inline bool CalloutConnected::operator == ( const CalloutConnected & r ) const
{
    return ( ( iv_targetType == r.iv_targetType ) && ( iv_idx == r.iv_idx ) &&
            ( iv_priority == r.iv_priority ) &&
            ( ( iv_altResolution == r.iv_altResolution ) ||
            ( &iv_altResolution == &r.iv_altResolution ) ) &&
            ( iv_peerConnType == r.iv_peerConnType) );
}

} // end namespace PRDF

#endif /* PRDFCALLOUTCONNECTED_H */
