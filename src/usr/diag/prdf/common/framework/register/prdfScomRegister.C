/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: prdfScomRegister.C $                                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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

// Module Description **************************************************
//
// Description: This module provides the implementation for the PRD Scan
//              Comm Register Chip class.
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <iipchip.h>
#include <prdfScomRegister.H>
#include <iipconst.h>
#include <iipbits.h>
#include <prdfMain.H>
#include <prdf_ras_services.H>
#include <prdfRegisterCache.H>
#include <prdfHomRegisterAccess.H>
#include <prdfPlatServices.H>
#include <prdfExtensibleChip.H>

//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

// --------------------------------------------------------------------
namespace PRDF
{

// ---------------------------------------------------------------------

void ScomRegister::SetBitString( const BIT_STRING_CLASS *bs )
{
    BIT_STRING_CLASS & l_string  = AccessBitString();
    l_string.SetBits(*bs);
}


// ---------------------------------------------------------------------

const BIT_STRING_CLASS *ScomRegister::GetBitString( ATTENTION_TYPE i_type )const
{
    BIT_STRING_CLASS * l_pString = NULL;
    bool l_readStat = false;
    //Expectation is, caller shall first call Read( ) and then GetBitString.
    //This leaves an opportunity of mistake. One may call GetBitString without
    //calling Read() first. As a result, a stray entry in cache gets created
    //which  shall never be in sync with hardware.

    //As a solution, first cache is queried.If the given entry exist, bitString
    //pointer is returned else a new entry is created. This new entry is
    //synchronized with hardware and then pointer to bit string is returned to
    //caller.
    RegDataCache & regDump = RegDataCache::getCachedRegisters();
    l_pString = regDump.queryCache( getChip( ), this );

    if( NULL == l_pString )
    {
        ForceRead( );
        //if ForceRead fails, a dummy entry is returned that way analysis shall
        //fail gracefully else we return a new entry which is in sync with
        //hardware
        l_pString = &( readCache( l_readStat ) );

    }
    return l_pString;
}
// ---------------------------------------------------------------------
BIT_STRING_CLASS & ScomRegister::AccessBitString( )
{
    bool l_readStat = false;
    //Expectation is, caller shall first call Read( ) and then AccessBitString.
    //This leaves an opportunity of mistake. One may call AccessBitString
    //without calling Read() first. As a result, a stray entry in cache gets
    //created which shall never be in sync with hardware. Calling Read( ) before
    //readCache( ) inside function eliminates this scenario.
    Read( );
    return ( readCache( l_readStat ) );

}

//---------------------------------------------------------------------

uint32_t ScomRegister::Read( )
{
    int32_t rc = SUCCESS;
    bool l_readStat = false;
    readCache( l_readStat );
    if( false == l_readStat )
    {
        //updating cache by reading hardware .So next read  need not access
        //hardware
        rc = ForceRead();
    }

    return(rc);
}

// ----------------------------------------------------------------------------
uint32_t ScomRegister::ForceRead() const
{
    int32_t rc = SUCCESS;
    bool l_readStat = false;
    BIT_STRING_CLASS & bs = readCache( l_readStat );
    rc = Access( bs,MopRegisterAccess::READ );
    if( SUCCESS != rc )
    {
        ExtensibleChip* l_pChip = getChip( );
        flushCache( l_pChip );
    }

    return rc;
}
//------------------------------------------------------------------------------

uint32_t ScomRegister::Write()
{
    uint32_t rc = FAIL;
    bool l_entryBeforeWrite = false;
    BIT_STRING_CLASS & bs = readCache( l_entryBeforeWrite );
    PRDF_ASSERT( true == l_entryBeforeWrite );
    rc = Access( bs, MopRegisterAccess::WRITE );

    return(rc);
}
//------------------------------------------------------------------------------
uint32_t ScomRegister::Access( BIT_STRING_CLASS & bs,
                               MopRegisterAccess::Operation op ) const
{
    int32_t l_rc = SCR_ACCESS_FAILED;
    TARGETING::TargetHandle_t i_pchipTarget = getChip()->GetChipHandle();
    l_rc = getScomService().Access( i_pchipTarget,bs,iv_scomAddress,op );

    return(l_rc);
}
//-----------------------------------------------------------------------------
ExtensibleChip* ScomRegister::getChip( )const
{
    ExtensibleChip* l_pchip = NULL;
    l_pchip = ServiceDataCollector::getChipAnalyzed();
    TARGETING::TYPE l_type = PlatServices::getTargetType(
                                                l_pchip->GetChipHandle() );
    PRDF_ASSERT( iv_chipType == l_type )
    return l_pchip;
}
//-----------------------------------------------------------------------------
BIT_STRING_CLASS & ScomRegister::readCache( bool & o_existingEntry ) const
{
    ExtensibleChip* l_pChip = getChip( );
    RegDataCache & regDump = RegDataCache::getCachedRegisters();
    return  regDump.read( l_pChip,this,o_existingEntry );

}
//-----------------------------------------------------------------------------

void ScomRegister::flushCache( ExtensibleChip *i_pChip ) const
{
     RegDataCache & regDump = RegDataCache::getCachedRegisters();
    if( NULL == i_pChip )
    {
        regDump.flush();
    }
    else
    {
        regDump.flush( i_pChip ,this );
    }
}

//-----------------------------------------------------------------------------

bool ScomRegister::operator == ( const ScomRegister & i_rightRegister ) const
{
    if( iv_scomAddress == i_rightRegister.GetAddress() )
    {
        return ( iv_chipType == i_rightRegister.getChipType() );
    }
    else
    {
        return false ;
    }

}

//-----------------------------------------------------------------------------
bool ScomRegister::operator < ( const ScomRegister & i_rightRegister  ) const
{
    if( iv_scomAddress == i_rightRegister.GetAddress() )
    {
        return ( iv_chipType < i_rightRegister.getChipType() );
    }
    else
    {
        return( iv_scomAddress  < i_rightRegister.GetAddress() );
    }


}
//-----------------------------------------------------------------------------
bool ScomRegister::operator >= ( const ScomRegister & i_rightRegister  ) const
{
    return !( *this < i_rightRegister );
}
}//namespace PRDF ends
