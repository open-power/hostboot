/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfRegisterCache.C $ */
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

BIT_STRING_CLASS & RegDataCache::read( ExtensibleChip * i_chip,
                                       const SCAN_COMM_REGISTER_CLASS * i_reg )
{
    ScomRegisterAccess l_scomAccessKey ( *i_reg, i_chip );
    BIT_STRING_CLASS * l_pBitString = queryCache( l_scomAccessKey );

    if ( NULL == l_pBitString )
    {
        // Creating new entry
        l_pBitString = new BitStringBuffer( i_reg->GetBitLength() );
        // Adding register in the cache
        iv_cachedRead[l_scomAccessKey] = l_pBitString;
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
