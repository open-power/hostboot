/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfAnalyzeConnected.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef PRDFANALYZECONNECTED_H
#define PRDFANALYZECONNECTED_H
/**
   @file prdfAnalyzeConnected.H
   @brief A resolution to analyze a connected chip determined at the time of
   the error.
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipResolution.h>
#include <prdfPlatServices.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
struct STEP_CODE_DATA_STRUCT;

/**
    This resolution calls out a connected MRU.
    @author Patrick Williams
    @par
      This resolution calls out a connected chip, but waits until the time of
      the error to determine what's connected.  This allows for runtime GARD,
      dynamic failover and concurrent maintenance - without having to call
      PRD to re-build itself.
*/
class AnalyzeConnected : public Resolution
{
  public:

    /**
     * @brief       Constructor
     * @param[in]   i_targetType  Target type of unit that's connected to given
     *                            target
     * @param[in]   i_idx:        index into getConnected list of chip.
     */
    AnalyzeConnected( TARGETING::TYPE i_targetType = TARGETING::TYPE_NA,
                      uint32_t i_idx               = INVALID_INDEX ) :
        iv_targetType(i_targetType), iv_idx(i_idx)
    {}

    // ~prdfAnalyzeConnected(); default dtor is sufficient

    /**
     * @brief     Determine chip object for current connected unit and call its
     *            analyze func.
     * @param[io] io_service_data References to STEP_CODE_DATA_STRUCT
     * @param[i]  i_default Default resolution
     * @return    SUCCESS | non-zero if chip not found.
     * @note      if the call to getConnected yields nullptr  than the
     *            altResolution is called. If the altResolution is nullptr than the
     *            source is added to the callout list.
     */
    virtual int32_t Resolve( STEP_CODE_DATA_STRUCT & io_service_data,
                             bool i_default = false );

    virtual bool operator==(const AnalyzeConnected & r) const
    {
        return ( iv_targetType == r.iv_targetType &&
                 iv_idx        == r.iv_idx );
    }

  private:  // functions
  private:  // Data

    TARGETING::TYPE iv_targetType;
    uint32_t  iv_idx;

    static constexpr uint32_t INVALID_INDEX = 0xffffffff;
};

} // end namespace PRDF

#endif /* PRDFANALYZECONNECTED_H */

