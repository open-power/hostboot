/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfScomRegisterAccess.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#include <prdfScomRegisterAccess.H>
#include <prdfScanFacility.H>
#include <prdfRegisterCache.H>
#include <prdfExtensibleChip.H>
namespace PRDF
{

ScomRegisterAccess::ScomRegisterAccess(
                    const SCAN_COMM_REGISTER_CLASS & i_pRegister,
                    ExtensibleChip * i_pRuleChip ) :
    ScomRegister( i_pRegister ),
    iv_containerChip( i_pRuleChip )
{}

//----------------------------------------------------------------------

ExtensibleChip* ScomRegisterAccess::getChip( )const
{
    return iv_containerChip;
}

//----------------------------------------------------------------------

bool ScomRegisterAccess::operator == (
                const ScomRegisterAccess & i_rightRegister ) const
{
    if( GetAddress() == i_rightRegister.GetAddress() )
    {
        return ( getChip() == i_rightRegister.getChip() );
    }
    else
    {
        return false ;
    }

}
//----------------------------------------------------------------------

bool ScomRegisterAccess::operator < (
                const ScomRegisterAccess & i_rightRegister ) const
{
    if( GetAddress() == i_rightRegister.GetAddress() )
    {
        return ( getChip() < i_rightRegister.getChip() );
    }
    else
    {
        return ( GetAddress() < i_rightRegister.GetAddress() );
    }
}

//----------------------------------------------------------------------
bool ScomRegisterAccess::operator >= (
                const ScomRegisterAccess & i_right ) const
{
    return !( *this < i_right );
}

//----------------------------------------------------------------------
}//namespace PRDF ends
