/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfPluginCallResolution.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2005,2020                        */
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

#ifndef __PRDFPLUGINCALLRESOLUTION_H
#define __PRDFPLUGINCALLRESOLUTION_H

#include <iipResolution.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
namespace PRDF
{

class PluginCallResolution : public Resolution
{
    private:
        ExtensibleChipFunction * iv_function;

    public:
        PluginCallResolution(void)
          : iv_function( nullptr ) {}

        PluginCallResolution( ExtensibleChipFunction * i_function )
            :iv_function(i_function) {};

        PluginCallResolution & operator = (const PluginCallResolution & r)
        {
          iv_function = r.iv_function;
          return *this;
        }

        bool operator == (const PluginCallResolution & r)
        {
          return (iv_function == r.iv_function);
        }

        virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & i_error,
                                bool i_default = false)
        {
            // In Isolation only pass, we are only interested in error
            // signature. So we will not execute plugin resolution as it may
            // call some HWP/update VPD etc which is not desired is isolation
            // only pass.
            if ( i_error.service_data->IsIsolationOnlyPass()) return SUCCESS;

            if (nullptr == iv_function)
            {
                return FAIL;

            }

            ExtensibleChip * l_pResolutionChip =
                                    ServiceDataCollector::getChipAnalyzed( );

            PRDF_ASSERT( nullptr != l_pResolutionChip );

            return ( *iv_function ) ( l_pResolutionChip, PluginDef::bindParm
                                        <STEP_CODE_DATA_STRUCT&>( i_error ) );

        };
};

} // end namespace PRDF

#endif

