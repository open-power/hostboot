/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: prdfRegisterCache.C $                                         */
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

#include <prdfRegisterCache.H>
#include <iipconst.h>

namespace PRDF
{

//------------------------------------------------------------------------------

RegDataCache & RegDataCache::getCachedRegisters()
{
    return PRDF_GET_SINGLETON( ReadCache );
}

//------------------------------------------------------------------------------

RegDataCache::~RegDataCache()
{
    flush();
}

//------------------------------------------------------------------------------

BIT_STRING_CLASS & RegDataCache::read(
                                ExtensibleChip* i_pChip,
                                const SCAN_COMM_REGISTER_CLASS * i_pRegister,
                                bool & o_readStat )
{
    ScomRegisterAccess l_scomAccessKey ( *i_pRegister,i_pChip );
    BIT_STRING_CLASS * l_pBitString = queryCache( l_scomAccessKey );
    o_readStat = false;
    if( NULL == l_pBitString )
    {
        // Creating new entry
        l_pBitString = new BitStringBuffer( i_pRegister->GetBitLength( ) );
        // Adding register in the cache
        iv_cachedRead[l_scomAccessKey] = l_pBitString;
    }
    else
    {
        o_readStat = true;
    }
    return *l_pBitString;
}

//------------------------------------------------------------------------------

void RegDataCache::flush()
{
    for ( CacheDump::iterator it = iv_cachedRead.begin();
          it != iv_cachedRead.end(); it++ )
    {
        // Freeing up the bit string memory reserved on heap
        delete it->second;
    }

    // Deleting all the entry from the cache
    iv_cachedRead.clear();
}

//------------------------------------------------------------------------------

void RegDataCache::flush( ExtensibleChip* i_pChip,
                          const SCAN_COMM_REGISTER_CLASS * i_pRegister )
{
    ScomRegisterAccess l_scomAccessKey ( *i_pRegister,i_pChip );
    // Find the entries associated with the given target in the map
    CacheDump::iterator it = iv_cachedRead.find( l_scomAccessKey );

    // If entry exists delete the entry for given scom address
    if ( it !=iv_cachedRead.end() )
    {
        delete it->second;
        iv_cachedRead.erase( it );
    }
}

//------------------------------------------------------------------------------

BIT_STRING_CLASS * RegDataCache::queryCache(
                            ExtensibleChip* i_pChip,
                            const SCAN_COMM_REGISTER_CLASS * i_pRegister )const
{
    ScomRegisterAccess l_scomAccessKey ( *i_pRegister,i_pChip );
    return queryCache( l_scomAccessKey );
}

//------------------------------------------------------------------------------

BIT_STRING_CLASS * RegDataCache::queryCache(
                        const ScomRegisterAccess & i_scomAccessKey ) const
{
    BIT_STRING_CLASS * l_pBitString = NULL;
    CacheDump::const_iterator itDump = iv_cachedRead.find( i_scomAccessKey );
    if( iv_cachedRead.end() != itDump )
    {
        l_pBitString = itDump->second ;
    }

    return l_pBitString;
}

//------------------------------------------------------------------------------
}// end namespace  PRDF
