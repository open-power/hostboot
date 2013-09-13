/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfPluginCallResolution.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2013              */
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
          : iv_function( NULL ) {}

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

        virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & i_error)
        {
            // In Isolation only pass, we are only interested in error
            // signature. So we will not execute plugin resolution as it may
            // call some HWP/update VPD etc which is not desired is isolation
            // only pass.
            if ( i_error.service_data->IsIsolationOnlyPass()) return SUCCESS;

            if (NULL == iv_function)
            {
                return FAIL;

            }

            ExtensibleChip * l_pResolutionChip =
                                    ServiceDataCollector::getChipAnalyzed( );

            PRDF_ASSERT( NULL != l_pResolutionChip );

            return ( *iv_function ) ( l_pResolutionChip, PluginDef::bindParm
                                        <STEP_CODE_DATA_STRUCT&>( i_error ) );

        };
};

} // end namespace PRDF

#endif

