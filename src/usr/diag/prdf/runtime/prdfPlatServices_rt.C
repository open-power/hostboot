/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/runtime/prdfPlatServices_rt.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

/**
 * @file  prdfPlatServices_rt.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <runtime/interface.h>

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

void sendPageGardRequest( uint64_t i_systemAddress )
{
    #define PRDF_FUNC "[PlatServices::sendPageGardRequest] "

    do
    {
        if( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() interface is not defined");
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_systemAddress,
                                                      i_systemAddress,
                                                      MEMORY_ERROR_CE );
        if( SUCCESS != rc )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() failed");
            break;
        }
    }while(0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void sendLmbGardRequest( uint64_t i_systemAddress, bool i_isFetchUE )
{
    //NO-OP for OPAL
}
//------------------------------------------------------------------------------

void sendDynMemDeallocRequest( uint64_t i_startAddr, uint64_t i_endAddr )
{
    #define PRDF_FUNC "[PlatServices::sendDynMemDeallocRequest] "

    do
    {
        if( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() interface is not defined");
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_startAddr,
                                                     i_startAddr,
                                                     MEMORY_ERROR_UE );
        if( SUCCESS != rc )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() failed");
            break;
        }
    }while(0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

