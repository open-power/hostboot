/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCalloutGard.H $ */
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

#ifndef PRDF_CALLOUT_GARD_H
#define PRDF_CALLOUT_GARD_H
/**
 * @file    prdfCalloutGard.H
 * @brief   A resolution to callout and gard MRU reporting attention.
 */

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfCallouts.H>
#include <iipResolution.h>
#include <iipServiceDataCollector.h>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------


class CalloutGardResolution: public Resolution
{
  public:
    /**
     * @brief constructor
     * @param i_callout     callout instance
     * @param i_priority    i_priority associated with callout.
     * @param i_gardState   gard policy associated with callout.
     */
    CalloutGardResolution( PRDcallout i_callout, PRDpriority i_priority,
                           GARD_POLICY i_gardState );
    /**
     * @brief constructor
     */
    CalloutGardResolution(void);    // default

    /**
     * @brief constructor
     */
    CalloutGardResolution(const CalloutGardResolution & i_cr);

    //~CalloutGardResolution();

    /**
     * @brief Executes the callout and enforces gard policy.
     * @param error step code data struct.
     */
    virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & error,
                            bool i_default = false);

    /**
     * @brief compares if two CalloutGardResolution are identical.
     */
    virtual bool operator==(const CalloutGardResolution & i_right ) const
    {
    return(( iv_callout == i_right.iv_callout) &&
           ( iv_calloutPriority == i_right.iv_calloutPriority) &&
           ( iv_gardState == i_right.iv_gardState ));
    }

  protected:  // Data

    PRDcallout iv_callout; ///< MRU associated with callout action
    PRDpriority iv_calloutPriority; ///< Priority associated with callout
    GARD_POLICY iv_gardState; ///< gard policy associated with resolution

};


inline CalloutGardResolution::CalloutGardResolution(
                                     PRDcallout i_callout,
                                     PRDpriority i_priority,
                                     GARD_POLICY i_gardState ) :
    iv_callout( i_callout ),
    iv_calloutPriority( i_priority ),
    iv_gardState( i_gardState )
{}

inline
CalloutGardResolution::CalloutGardResolution() :
    iv_callout( nullptr ),
    iv_calloutPriority( MRU_MED ),
    iv_gardState( GARD )
{}

inline
CalloutGardResolution::CalloutGardResolution(
                            const CalloutGardResolution & i_cr) :
  iv_callout( i_cr.iv_callout ),
  iv_calloutPriority( i_cr.iv_calloutPriority ),
  iv_gardState( i_cr.iv_gardState )
{}

} // end namespace PRDF

#endif /* PRDF_CALLOUT_GARD_H */
