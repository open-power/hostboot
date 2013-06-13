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


//------------------------------------------------------------------------------

const BIT_STRING_CLASS * ScomRegister::GetBitString(ATTENTION_TYPE i_type) const
{
    // Calling Read() will ensure that an entry exists in the cache and the
    // entry has at been synched with hardware at least once. Note that we
    // cannot read hardware for write-only registers. In this case, an entry
    // will be created in the cache, if it does not exist, when readCache() is
    // called below.
    if ( ( ACCESS_NONE != iv_operationType ) &&
            ( ACCESS_WO != iv_operationType ) )
    {
        Read();
    }
    return &(readCache());
}

//------------------------------------------------------------------------------

BIT_STRING_CLASS & ScomRegister::AccessBitString()
{
    // Calling Read() will ensure that an entry exists in the cache and the
    // entry has at been synched with hardware at least once. Note that we
    // cannot read hardware for write-only registers. In this case, an entry
    // will be created in the cache, if it does not exist, when readCache() is
    // called below.
    if ( ( ACCESS_NONE != iv_operationType ) &&
            ( ACCESS_WO != iv_operationType ) )
    {
        Read();
    }

    return readCache();
}

//------------------------------------------------------------------------------

uint32_t ScomRegister::Read() const
{
    uint32_t o_rc = SUCCESS;

    // First query the cache for an existing entry.
    if ( !queryCache() )
    {
        // There was not a previous entry in the cache, so do a ForceRead() to
        // sync the cache with hardware.
        o_rc = ForceRead();
    }

    return o_rc;
}

//------------------------------------------------------------------------------

uint32_t ScomRegister::ForceRead() const
{
    #define PRDF_FUNC "[ScomRegister::ForceRead] "

    uint32_t o_rc = FAIL;

    do
    {
        // No read allowed if register access attribute is write-only or no
        // access.
        if ( ( ACCESS_NONE == iv_operationType ) &&
                ( ACCESS_WO == iv_operationType ) )
        {
            PRDF_ERR( PRDF_FUNC"Write-only register: 0x%08x 0x%016llx",
                      getChip()->GetId(), iv_scomAddress );
            break;
        }

        // Read hardware.
        o_rc = Access( readCache(), MopRegisterAccess::READ );
        if ( SUCCESS != o_rc )
        {
            // The read failed. Remove the entry from the cache so a subsequent
            // Read() will attempt to read from hardware again.
            flushCache( getChip() );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t ScomRegister::Write()
{
    #define PRDF_FUNC "[ScomRegister::Write] "

    uint32_t o_rc = FAIL;

    do
    {
        // No write allowed if register access attribute is read-only or no
        // access.
        if ( ( ACCESS_NONE == iv_operationType ) &&
                 ( ACCESS_RO == iv_operationType ) )
        {
            PRDF_ERR( PRDF_FUNC"Read-only register: 0x%08x 0x%016llx",
                      getChip()->GetId(), iv_scomAddress );
            break;
        }

        // Query the cache for an existing entry.
        if ( !queryCache() )
        {
            // Something bad happened and there was nothing in the cache to
            // write to hardware.
            PRDF_ERR( PRDF_FUNC"No entry found in cache: 0x%08x 0x%016llx",
                      getChip()->GetId(), iv_scomAddress );
            break;
        }

        // Write hardware.
        o_rc = Access( readCache(), MopRegisterAccess::WRITE );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
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

//------------------------------------------------------------------------------

bool ScomRegister::queryCache() const
{
    RegDataCache & cache = RegDataCache::getCachedRegisters();
    BIT_STRING_CLASS * bs = cache.queryCache( getChip(), this );
    return ( NULL != bs );
}

//------------------------------------------------------------------------------

BIT_STRING_CLASS & ScomRegister::readCache() const
{
    RegDataCache & cache = RegDataCache::getCachedRegisters();
    return cache.read( getChip(), this );
}

//------------------------------------------------------------------------------

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
