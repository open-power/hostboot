/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: prdfScomRegisterAccess.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#include <prdfScomRegisterAccess.H>
#include <prdfScanFacility.H>
#include <prdfRegisterCache.H>
#include <prdfExtensibleChip.H>
namespace PRDF
{

ScomRegisterAccess::ScomRegisterAccess(
                    const SCAN_COMM_REGISTER_CLASS  &i_pRegister ,
                    ExtensibleChip* i_pRuleChip
                    )
                    :ScomRegister( i_pRegister ),
                     iv_containerChip( i_pRuleChip )
{
}

//----------------------------------------------------------------------

ScomRegisterAccess::ScomRegisterAccess( uint64_t i_scomAddress,
                                        uint32_t i_bitLength,
                                        ExtensibleChip* i_pRuleChip ):
    ScomRegister( i_scomAddress ,i_bitLength,
                  PlatServices::getTargetType( i_pRuleChip->GetChipHandle())),
    iv_containerChip( i_pRuleChip )
{
}


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
