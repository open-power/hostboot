/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/runtime/prdfPlatServices_rt.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
    // TODO: RTC 118920 need to create and call OPAL interfaces
}

//------------------------------------------------------------------------------

void sendLmbGardRequest( uint64_t i_systemAddress, bool i_isFetchUE )
{
    // TODO: RTC 118920 need to create and call OPAL interfaces
}

//------------------------------------------------------------------------------

void sendDynMemDeallocRequest( uint64_t i_startAddr, uint64_t i_endAddr )
{
    // TODO: RTC 118920 need to create and call OPAL interfaces
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

