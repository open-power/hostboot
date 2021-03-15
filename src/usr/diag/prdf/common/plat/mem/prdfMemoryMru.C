/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemoryMru.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <prdfTargetServices.H>
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace MemoryMruData;
using namespace PlatServices;

//------------------------------------------------------------------------------

MemoryMru::MemoryMru( uint32_t i_memMru ) :
    iv_target(nullptr), iv_rank(0), iv_special(NO_SPECIAL_CALLOUT)
{
    #define PRDF_FUNC "[MemoryMru::MemoryMru] "

    iv_memMruMeld.u = i_memMru;

    iv_memMruMeld.s.valid = 0; // initially invalidated

    // Get target using node, proc, membuf and position
    TargetHandle_t system = getSystemTarget();

    TargetHandle_t node = getConnectedChild( system, TYPE_NODE,
            iv_memMruMeld.s.nodePos );
    if ( nullptr == node )
    {
        PRDF_ERR( PRDF_FUNC "Could not find functional node attached to "
                "system at pos: %u", iv_memMruMeld.s.nodePos );
        PRDF_ASSERT( false );
    }

    TargetHandle_t proc = getConnectedChild( node, TYPE_PROC,
            iv_memMruMeld.s.procPos );
    if ( nullptr == proc )
    {
        PRDF_ERR( PRDF_FUNC "Could not find functional  proc attached to "
                "node 0x%08X at pos: %u", getHuid( node ),
                iv_memMruMeld.s.procPos );
        PRDF_ASSERT( false );
    }

    // If our target is OCMB
    if ( 1 == iv_memMruMeld.s.isOcmb )
    {
        // chnlPos specifies the position of the MCC relative to the proc
        TargetHandle_t mcc = getConnectedChild( proc, TYPE_MCC,
                                                iv_memMruMeld.s.chnlPos );
        if ( nullptr == mcc )
        {
            PRDF_ERR( PRDF_FUNC "Could not find functional mcc attached to "
                      "proc 0x%08x at pos: %u", getHuid(proc),
                      iv_memMruMeld.s.chnlPos );
            PRDF_ASSERT( false );
        }

        // omiPos specifies the position of the OMI relative to the MCC
        TargetHandle_t omi = getConnectedChild( mcc, TYPE_OMI,
                                                iv_memMruMeld.s.omiPos );
        if ( nullptr == omi )
        {
            PRDF_ERR( PRDF_FUNC "Could not find functional omi attached to "
                      "mcc 0x%08x at pos: %u", getHuid(mcc),
                      iv_memMruMeld.s.omiPos );
            PRDF_ASSERT( false );
        }

        // There is only one OCMB attached per OMI
        iv_target = getConnectedChild( omi, TYPE_OCMB_CHIP, 0 );
        if ( nullptr == iv_target )
        {
            PRDF_ERR( PRDF_FUNC "Could not find functional ocmb attached to "
                      "omi 0x%08x", getHuid(mcc) );
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
                iv_memMruMeld.s.symbol );
        if ( !iv_symbol.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "fromSymbol() failed" );
            PRDF_ASSERT( false );
        }

        if ( iv_memMruMeld.s.dramSpared ) iv_symbol.setDramSpared();

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
        if ( TYPE_OCMB_CHIP == getTargetType(iv_target) )
        {
            if ( CALLOUT_ALL_MEM == iv_special )
            {
                o_list = getConnectedChildren( iv_target, TYPE_DIMM );
            }
            else if ( (CALLOUT_RANK       == iv_special) ||
                      (NO_SPECIAL_CALLOUT == iv_special) )
            {
                // Rank callouts and symbol callouts both callout a single DIMM.
                uint32_t ds = iv_rank.getDimmSlct();
                // TODO RTC 210072 - support for multiple ports
                TargetHandle_t memPort = getConnectedChild( iv_target,
                        TYPE_MEM_PORT, 0 );
                TargetHandle_t dimm = getConnectedChild(memPort, TYPE_DIMM, ds);

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

    TargetHandle_t proc = nullptr;
    if ( TYPE_OCMB_CHIP == trgtType )
    {
        TargetHandle_t mcc = getConnectedParent( iv_target, TYPE_MCC );
        proc = getConnectedParent( mcc, TYPE_PROC );
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "Invalid target type" );
        PRDF_ASSERT(false);
    }
    TargetHandle_t node = getConnectedParent( proc, TYPE_NODE );

    // If our target is an OCMB, then chnlPos will specify the MCC position and
    // omiPos will specify the OMI position.
    if ( TYPE_OCMB_CHIP == getTargetType(iv_target) )
    {
        TargetHandle_t omi = getConnectedParent( iv_target, TYPE_OMI );
        TargetHandle_t mcc = getConnectedParent( omi, TYPE_MCC );

        iv_memMruMeld.s.isOcmb  = 1;
        iv_memMruMeld.s.chnlPos = getTargetPosition(mcc) % MAX_MCC_PER_PROC;
        iv_memMruMeld.s.omiPos  = getTargetPosition(omi) % MAX_OMI_PER_MCC;
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "Invalid target type" );
        PRDF_ASSERT(false);
    }

    iv_memMruMeld.s.nodePos    = getTargetPosition( node );
    iv_memMruMeld.s.procPos    = getTargetPosition( proc );
    iv_memMruMeld.s.mrank      = iv_rank.getMaster();
    iv_memMruMeld.s.srank      = iv_rank.getSlave();

    return;

    #undef PRDF_FUNC
}

} // end namespace PRDF

