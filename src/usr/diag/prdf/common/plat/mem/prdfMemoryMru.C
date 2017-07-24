/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemoryMru.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

/** @file prdfMemoryMru.C */

#include <prdfMemoryMru.H>
//#include <prdfCalloutUtil.H> TODO RTC 162077
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace MemoryMruData;
using namespace PlatServices;
using namespace CEN_SYMBOL;

//------------------------------------------------------------------------------

MemoryMru::MemoryMru( uint32_t i_memMru ) :
    iv_target(NULL), iv_rank(0), iv_special(NO_SPECIAL_CALLOUT)
{
    #define PRDF_FUNC "[MemoryMru::MemoryMru] "

    iv_memMruMeld.u = i_memMru;

    iv_memMruMeld.s.valid = 0; // initially invalidated

    // Get target using node, proc, membuf and position
    TargetHandle_t system = getSystemTarget();

    TargetHandle_t node = getConnectedChild( system, TYPE_NODE,
            iv_memMruMeld.s.nodePos );
    if ( NULL == node )
    {
        PRDF_ERR( PRDF_FUNC "Could not find functional node attached to "
                "system at pos: %u", iv_memMruMeld.s.nodePos );
        PRDF_ASSERT( false );
    }

    TargetHandle_t proc = getConnectedChild( node, TYPE_PROC,
            iv_memMruMeld.s.procPos );
    if ( NULL == proc )
    {
        PRDF_ERR( PRDF_FUNC "Could not find functional  proc attached to "
                "node 0x%08X at pos: %u", getHuid( node ),
                iv_memMruMeld.s.procPos );
        PRDF_ASSERT( false );
    }

    // If our target is MBA, get the chnlPos from the membuf
    if ( 0 == iv_memMruMeld.s.isMca )
    {
        TargetHandle_t membuf = getConnectedChild( proc, TYPE_MEMBUF,
                iv_memMruMeld.s.chnlPos );
        if ( NULL == membuf )
        {
            PRDF_ERR( PRDF_FUNC "Could not find functional membuf "
                    "attached to proc 0x%08X at pos: %u", getHuid( proc ),
                    iv_memMruMeld.s.chnlPos );
            PRDF_ASSERT( false );
        }

        iv_target = getConnectedChild( membuf, TYPE_MBA,
                iv_memMruMeld.s.mbaPos );
        if ( NULL == iv_target )
        {
            PRDF_ERR( PRDF_FUNC "Could not find functional mba attached "
                    "to 0x%08X at pos: %u", getHuid( membuf ),
                    iv_memMruMeld.s.mbaPos );
            PRDF_ASSERT( false );
        }
    }
    else
    {
        iv_target = getConnectedChild( proc, TYPE_MCA,
                iv_memMruMeld.s.chnlPos );
        if ( NULL == iv_target )
        {
            PRDF_ERR( PRDF_FUNC "Could not find functional mca "
                    "attached to proc 0x%08X at pos: %u", getHuid( proc ),
                    iv_memMruMeld.s.chnlPos );
            PRDF_ASSERT( false );
        }
    }


    // Get the rank
    iv_rank = MemRank( iv_memMruMeld.s.mrank, iv_memMruMeld.s.srank );

    // Get the symbol or special callout
    if ( (FIRST_SPECIAL_CALLOUT <= iv_memMruMeld.s.symbol) &&
            (iv_memMruMeld.s.symbol <= LAST_SPECIAL_CALLOUT) )
    {
        iv_special = (MemoryMruData::Callout)iv_memMruMeld.s.symbol;
    }
    else
    {
        if ( SYMBOLS_PER_RANK <= iv_memMruMeld.s.symbol )
        {
            PRDF_ERR( PRDF_FUNC "Invalid symbol value :%u",
                    iv_memMruMeld.s.symbol );
            PRDF_ASSERT( false );
        }

        iv_symbol = MemSymbol::fromSymbol( iv_target, iv_rank,
                iv_memMruMeld.s.symbol,
                iv_memMruMeld.s.pins );
        if ( !iv_symbol.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "fromSymbol() failed" );
            PRDF_ASSERT( false );
        }

        if ( iv_memMruMeld.s.dramSpared ) iv_symbol.setDramSpared();
        if ( iv_memMruMeld.s.eccSpared  ) iv_symbol.setEccSpared();

    }

    // If the code gets to this point the MemoryMru is valid.
    iv_memMruMeld.s.valid = 1;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

MemoryMru::MemoryMru( TARGETING::TargetHandle_t i_target,
                      const MemRank & i_rank, const MemSymbol & i_symbol ) :
    iv_target(i_target), iv_rank(i_rank),
    iv_special(NO_SPECIAL_CALLOUT), iv_symbol( i_symbol )
{
    #define PRDF_FUNC "[MemoryMru::MemoryMru] "

    PRDF_ASSERT( i_symbol.isValid() );

    iv_memMruMeld.u = 0;

    getCommonVars();

    iv_memMruMeld.s.symbol     = iv_symbol.getSymbol();
    iv_memMruMeld.s.pins       = iv_symbol.getPins();
    iv_memMruMeld.s.dramSpared = iv_symbol.isDramSpared() ? 1 : 0;
    iv_memMruMeld.s.eccSpared  = iv_symbol.isEccSpared()  ? 1 : 0;

    // If the code gets to this point the MemoryMru is valid.
    iv_memMruMeld.s.valid = 1;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

MemoryMru::MemoryMru( TARGETING::TargetHandle_t i_target,
                      const MemRank & i_rank,
                      MemoryMruData::Callout i_specialCallout ) :
    iv_target(i_target), iv_rank(i_rank), iv_special(i_specialCallout)
{
    #define PRDF_FUNC "[MemoryMru::MemoryMru] "

    PRDF_ASSERT( FIRST_SPECIAL_CALLOUT <= i_specialCallout &&
                 i_specialCallout <= LAST_SPECIAL_CALLOUT );

    iv_memMruMeld.u = 0;

    getCommonVars();

    iv_memMruMeld.s.symbol = iv_special;

    // If the code gets to this point the MemoryMru is valid.
    iv_memMruMeld.s.valid = 1;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandleList MemoryMru::getCalloutList() const
{
    #define PRDF_FUNC "[MemoryMru::getCalloutList] "

    TargetHandleList o_list;

    if ( 0 == iv_memMruMeld.s.valid )
    {
        PRDF_ERR( PRDF_FUNC "MemoryMru 0x%08x not valid.", iv_memMruMeld.u );
    }
    else
    {
        if ( TARGETING::TYPE_MBA == getTargetType(iv_target) )
        {
            if ( NO_SPECIAL_CALLOUT != iv_special )
            {
                switch ( iv_special )
                {
                    /*TODO RTC 162077 - reenable/update for Cumulus/MBA
                    case CALLOUT_RANK:
                        //o_list = CalloutUtil::getConnectedDimms( iv_target,
                        //                                         iv_rank );
                        break;
                    case CALLOUT_ALL_MEM:
                        //o_list = CalloutUtil::getConnectedDimms( iv_target );
                        break;
                    */
                    default:
                        PRDF_ERR( PRDF_FUNC "MemoryMruData::Callout 0x%02x not "
                                "supported", iv_special );
                }
            }
            else
            {
                //TODO RTC 162077 - reenable/update for Cumulus/MBA
                //uint8_t ps = iv_symbol.getPortSlct<TYPE_MBA>();

                //// Add DIMM represented by symbol
                //if ( iv_memMruMeld.s.eccSpared ) ps = 1; // Adjust for ECC spare
                //o_list = CalloutUtil::getConnectedDimms( iv_target,
                //        iv_rank, ps );
            }
        }
        else if ( TARGETING::TYPE_MCA == getTargetType(iv_target) )
        {
            if ( CALLOUT_ALL_MEM == iv_special )
            {
                o_list = getConnected( iv_target, TYPE_DIMM );
            }
            else if ( (CALLOUT_RANK       == iv_special) ||
                      (NO_SPECIAL_CALLOUT == iv_special) )
            {
                // Rank callouts and symbol callouts both callout a single DIMM.
                uint32_t ds = iv_rank.getDimmSlct();
                TargetHandle_t dimm = getConnectedChild( iv_target,
                                                         TYPE_DIMM, ds );
                if ( nullptr == dimm )
                {
                    PRDF_ERR( PRDF_FUNC "getConnectedChild(0x%08x,%d) returned "
                              "nullptr", getHuid(iv_target), ds );
                }
                else
                    o_list.push_back( dimm );
            }
            else
            {
                PRDF_ERR( PRDF_FUNC "MemoryMruData::Callout 0x%02x not "
                          "supported", iv_special );
            }
        }
        else
        {
            PRDF_ERR( PRDF_FUNC "Invalid target type: HUID=0x%08x",
                      getHuid(iv_target) );
        }
    }

    return o_list;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void MemoryMru::getCommonVars()
{
    #define PRDF_FUNC "[MemoryMru::getCommonVars] "

    TARGETING::TYPE trgtType = getTargetType( iv_target );
    PRDF_ASSERT( TYPE_MCA == trgtType || TYPE_MBA == trgtType );

    TargetHandle_t proc = getConnectedParent( iv_target, TYPE_PROC );
    TargetHandle_t node = getConnectedParent( proc, TYPE_NODE );

    // If our target is an MBA, get the chnlPos from the membuf and the
    // mbaPos from the target
    if ( TYPE_MBA == getTargetType(iv_target) )
    {
        TargetHandle_t membuf = getConnectedParent( iv_target, TYPE_MEMBUF );

        iv_memMruMeld.s.isMca   = 0;
        iv_memMruMeld.s.chnlPos = getMemChnl( membuf );
        iv_memMruMeld.s.mbaPos  = getTargetPosition( iv_target );
    }
    // If our target is an MCA, then chnlPos will specify the MCA position
    // and mbaPos will be an unused field
    else
    {
        iv_memMruMeld.s.isMca   = 1;
        iv_memMruMeld.s.chnlPos = getTargetPosition( iv_target );
    }

    iv_memMruMeld.s.nodePos    = getTargetPosition( node );
    iv_memMruMeld.s.procPos    = getTargetPosition( proc );
    iv_memMruMeld.s.mrank      = iv_rank.getMaster();
    iv_memMruMeld.s.srank      = iv_rank.getSlave();

    return;

    #undef PRDF_FUNC
}

} // end namespace PRDF

