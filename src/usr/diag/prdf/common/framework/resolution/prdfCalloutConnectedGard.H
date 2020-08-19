/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutConnectedGard.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

#ifndef PRDFCALLOUTCONNECTED_GARD_H
#define PRDFCALLOUTCONNECTED_GARD_H
/**
 *  @file    prdfCalloutConnectedGard.H
 *  @brief   A resolution to callout and gard connected MRU determined at the
 *           time of the error.
 */


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfPlatServices.H>
#include <prdfCallouts.H>
#include <iipResolution.h>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;

class CalloutConnectedGard : public Resolution
{
  public:

    /**
     * @brief   Constructor
     * @param   i_targetType      type of desired unit that's connected to
     *                            i_psourceHandle
     * @param   i_idx             index into getConnected list to callout
     *                            (i_idx = INVALID_INDEX means callout the first
     *                            valid target)
     * @param   i_priority        callout priority  @see srci.H for priority
     *                            values
     * @param   i_altResolution   to use if the connection does not exist or
     *                            is invalid.
     *                            If nullptr than source is called out
     * @param   i_peerConnType    type of unit that is peer connected to
     *                            i_targetType
     * @param   i_trgtGardState   gard policy associated with target callout
     * @note    Don't use this class to callout clocks - use ClockResolution
     */
    CalloutConnectedGard( TARGETING::TYPE i_targetType   = TARGETING::TYPE_NA,
                          uint32_t i_idx                 = INVALID_INDEX,
                          PRDpriority i_priority         = MRU_MED,
                          Resolution * i_altResolution   = nullptr,
                          TARGETING::TYPE i_peerConnType = TARGETING::TYPE_NA,
                          GARD_POLICY i_trgtGardState    = PRDF::GARD ) :
        iv_targetType(i_targetType), iv_idx(i_idx), iv_priority(i_priority),
        iv_altResolution(i_altResolution), iv_peerConnType(i_peerConnType),
        iv_gardState(i_trgtGardState)
    {}

    // ~CalloutConnectedGard(); default dtor is sufficient

    /**
     * @brief     callout and gard target connected to target under analysis.
     * @param     io_service_data  Reference to STEP_CODE_DATA_STRUCT
     * @post      service_data is complete
     * @return    SUCCESS | non-zero
     * @note      if the call to getConnected yields an invalid  target then
     *            altResolution is called. If the altResolution is nullptr than the
     *            source is added to the callout list.
     */
    virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_service_data,
                             bool i_default = false );

    /**
     * @brief     overloads operator ==
     */
    virtual bool operator==(const CalloutConnectedGard & i_right ) const
    {
        return ( iv_targetType    == i_right.iv_targetType     &&
                 iv_idx           == i_right.iv_idx            &&
                 iv_priority      == i_right.iv_priority       &&
                 iv_altResolution == i_right.iv_altResolution  &&
                 iv_peerConnType  == i_right.iv_peerConnType   &&
                 iv_gardState     == i_right.iv_gardState );
    }

  protected:  // Data

    TARGETING::TYPE iv_targetType;
    uint32_t iv_idx;
    PRDpriority iv_priority;
    Resolution * iv_altResolution;
    TARGETING::TYPE iv_peerConnType;
    GARD_POLICY iv_gardState; ///< gard policy associated with resolution

    static constexpr uint32_t INVALID_INDEX = 0xffffffff;
};

} // end namespace PRDF

#endif /* PRDFCALLOUTCONNECTED_GARD_H */
