/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCalloutUtil.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

/** @file prdfCalloutUtil.C */

#include <prdfCalloutUtil.H>

#include <iipServiceDataCollector.h>
#include <prdfCenAddress.H>
#include <prdfCenMarkstore.H>
#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

#include <hwas/common/hwasCallout.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CalloutUtil
{

void defaultError( STEP_CODE_DATA_STRUCT & i_sc )
{
    i_sc.service_data->SetCallout( NextLevelSupport_ENUM, MRU_MED, NO_GARD );
    i_sc.service_data->SetCallout( SP_CODE, MRU_MED, NO_GARD );
    i_sc.service_data->SetServiceCall();
}

//------------------------------------------------------------------------------

void calloutMark( TargetHandle_t i_mba, const CenRank & i_rank,
                  const CenMark & i_mark, STEP_CODE_DATA_STRUCT & io_sc,
                  PRDpriority i_priority )
{
    if ( i_mark.getCM().isValid() )
    {
        MemoryMru memmru ( i_mba, i_rank, i_mark.getCM() );
        io_sc.service_data->SetCallout( memmru, i_priority );
    }

    if ( i_mark.getSM().isValid() )
    {
        MemoryMru memmru ( i_mba, i_rank, i_mark.getSM() );
        io_sc.service_data->SetCallout( memmru, i_priority );
    }
}

//------------------------------------------------------------------------------

void calloutSymbolData( TargetHandle_t i_mba, const CenRank & i_rank,
                        const MemUtils::MaintSymbols & i_symData,
                        STEP_CODE_DATA_STRUCT & io_sc, PRDpriority i_priority )
{
    bool dimmsBad[PORT_SLCT_PER_MBA] = { false, false };

    for ( MemUtils::MaintSymbols::const_iterator it = i_symData.begin();
          it != i_symData.end(); it++ )
    {
        dimmsBad[it->symbol.getPortSlct()] = true;
    }

    for ( uint32_t port = 0; port < PORT_SLCT_PER_MBA; port++ )
    {
        if ( dimmsBad[port] )
        {
            TargetHandleList list = getConnectedDimms( i_mba, i_rank, port );
            for ( TargetHandleList::iterator it = list.begin();
                  it != list.end(); it++ )
            {
                io_sc.service_data->SetCallout( *it, i_priority );
            }
        }
    }
}

//------------------------------------------------------------------------------

TargetHandleList getConnectedDimms( TargetHandle_t i_mba,
                                    const CenRank & i_rank )
{
    #define PRDF_FUNC "[CalloutUtil::getConnectedDimms] "

    TargetHandleList o_list;

    if ( TYPE_MBA != getTargetType(i_mba) )
    {
        PRDF_ERR( PRDF_FUNC"Invalid target type: HUID=0x%08x", getHuid(i_mba) );
    }
    else
    {
        TargetHandleList dimmList = getConnected( i_mba, TYPE_DIMM );
        for ( TargetHandleList::iterator dimmIt = dimmList.begin();
              dimmIt != dimmList.end(); dimmIt++)
        {
            uint8_t dimmSlct;
            int32_t l_rc = getMbaDimm( *dimmIt, dimmSlct );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"getMbaDimm(0x%08x) failed",
                          getHuid(*dimmIt) );
                continue;
            }

            if ( dimmSlct == i_rank.getDimmSlct() )
            {
                o_list.push_back( *dimmIt );
            }
        }
    }

    return o_list;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandleList getConnectedDimms( TargetHandle_t i_mba )
{
    TargetHandleList o_list;

    if ( TYPE_MBA != getTargetType(i_mba) )
    {
        PRDF_ERR( "[CalloutUtil::getConnectedDimms] Invalid target type: "
                  "HUID=0x%08x", getHuid(i_mba) );
    }
    else
        o_list = getConnected( i_mba, TYPE_DIMM );

    return o_list;
}

//------------------------------------------------------------------------------

TargetHandleList getConnectedDimms( TargetHandle_t i_mba,
                                    const CenRank & i_rank,
                                    uint8_t i_port )
{
    #define PRDF_FUNC "[CalloutUtil::getConnectedDimms] "

    TargetHandleList o_list;

    TargetHandleList dimmList = getConnectedDimms( i_mba, i_rank );

    for ( TargetHandleList::iterator dimmIt = dimmList.begin();
          dimmIt != dimmList.end(); dimmIt++)
    {
        uint8_t portSlct;
        int32_t l_rc = getMbaPort( *dimmIt, portSlct );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMbaPort(0x%08x) failed",
                      getHuid(*dimmIt) );
            continue;
        }

        if ( portSlct == i_port )
        {
            o_list.push_back( *dimmIt );
        }
    }

    return o_list;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TargetHandleList getConnectedDimms( TargetHandle_t i_mba,
                                    uint8_t i_port )
{
    #define PRDF_FUNC "[CalloutUtil::getConnectedDimms] "

    TargetHandleList o_list;

    TargetHandleList dimmList = getConnectedDimms( i_mba );

    for ( TargetHandleList::iterator dimmIt = dimmList.begin();
          dimmIt != dimmList.end(); dimmIt++)
    {
        uint8_t portSlct;
        int32_t l_rc = getMbaPort( *dimmIt, portSlct );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMbaPort(0x%08x) failed",
                      getHuid(*dimmIt) );
            continue;
        }

        if ( portSlct == i_port )
        {
            o_list.push_back( *dimmIt );
        }
    }

    return o_list;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getBusEndpoints( ExtensibleChip * i_chip,
                         TargetHandle_t & o_rxTrgt, TargetHandle_t & o_txTrgt,
                         TYPE i_busType, uint32_t i_busPos )
{
    #define PRDF_FUNC "[CalloutUtil::getBusEndpoints] "

    int32_t rc = SUCCESS;

    o_rxTrgt = NULL;
    o_txTrgt = NULL;

    TargetHandle_t chipTrgt = i_chip->GetChipHandle();
    TYPE           chipType = getTargetType(chipTrgt);

    if ( TYPE_PROC == chipType )
    {
        o_rxTrgt = getConnectedChild( chipTrgt, i_busType, i_busPos );

        if ( TYPE_ABUS == i_busType || TYPE_XBUS == i_busType )
        {
            o_txTrgt = getConnectedPeerTarget( o_rxTrgt );
        }
        else if ( TYPE_MCS == i_busType )
        {
            o_txTrgt = getConnectedChild( o_rxTrgt, TYPE_MEMBUF, 0 );
        }
    }
    else if ( TYPE_MCS == chipType )
    {
        o_rxTrgt = chipTrgt;
        o_txTrgt = getConnectedChild( o_rxTrgt, TYPE_MEMBUF, 0 );
    }
    else if ( TYPE_MEMBUF == chipType )
    {
        o_rxTrgt = chipTrgt;
        o_txTrgt = getConnectedParent( o_rxTrgt, TYPE_MCS );
    }

    // Note that all of the 'getConnected' functions above do proper parameter
    // checking and will return NULL if anything is wrong. So this is the only
    // NULL check we actually need in this function.

    if ( NULL == o_rxTrgt || NULL == o_txTrgt )
    {
        PRDF_ERR( PRDF_FUNC"i_chip:0x%08x o_rxTrgt:0x%08x o_txTrgt:0x%08x "
                  "i_busType:%d i_busPos:%d", getHuid(chipTrgt),
                  getHuid(o_rxTrgt), getHuid(o_txTrgt), i_busType, i_busPos );
        rc = FAIL;
    }

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t calloutBusInterface( TargetHandle_t i_rxTrgt, TargetHandle_t i_txTrgt,
                             PRDpriority i_priority )
{
    #define PRDF_FUNC "[CalloutUtil::calloutBusInterface] "

    int32_t rc = SUCCESS;

    do
    {
        // Check for valid targets.
        if ( NULL == i_rxTrgt || NULL == i_txTrgt )
        {
            PRDF_ERR( PRDF_FUNC"Given target(s) are NULL" );
            rc = FAIL; break;
        }

        // Get the HWAS bus type.
        HWAS::busTypeEnum hwasType;

        TYPE rxType = getTargetType(i_rxTrgt);
        TYPE txType = getTargetType(i_txTrgt);

        if ( TYPE_ABUS == rxType && TYPE_ABUS == txType )
        {
            hwasType = HWAS::A_BUS_TYPE;
        }
        else if ( TYPE_XBUS == rxType && TYPE_XBUS == txType )
        {
            hwasType = HWAS::X_BUS_TYPE;
        }
        else if ( (TYPE_MCS    == rxType && TYPE_MEMBUF == txType) ||
                  (TYPE_MEMBUF == rxType && TYPE_MCS    == txType) )
        {
            hwasType = HWAS::DMI_BUS_TYPE;
        }
        else
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target types" );
            rc = FAIL; break;
        }

        // Get the global error log.
        errlHndl_t errl = NULL;
        errl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( NULL == errl )
        {
            PRDF_ERR( PRDF_FUNC"Failed to get the global error log" );
            rc = FAIL; break;
        }

        // Callout this bus interface.
        PRDF_ADD_BUS_CALLOUT( errl, i_rxTrgt, i_txTrgt, hwasType, i_priority );

    } while(0);

    if ( SUCCESS != rc )
    {
        PRDF_ERR( PRDF_FUNC"i_rxTrgt:0x%08x i_txTrgt:0x%08x i_priority:%d",
                  getHuid(i_rxTrgt), getHuid(i_txTrgt), i_priority );
    }

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t calloutBusInterface( ExtensibleChip * i_chip, PRDpriority i_priority,
                             TYPE i_busType, uint32_t i_busPos )
{
    #define PRDF_FUNC "[CalloutUtil::calloutBusInterface] "

    int32_t rc = SUCCESS;

    do
    {
        TargetHandle_t rxTrgt = NULL; TargetHandle_t txTrgt = NULL;

        rc = getBusEndpoints( i_chip, rxTrgt, txTrgt, i_busType, i_busPos );
        if ( SUCCESS != rc ) break;

        rc = calloutBusInterface( rxTrgt, txTrgt, i_priority );
        if ( SUCCESS != rc ) break;

    } while(0);

    if ( SUCCESS != rc )
    {
        PRDF_ERR( PRDF_FUNC"i_chip:0x%08x i_busType:%d i_busPos:%d "
                  "i_priority:%d", i_chip->GetId(), i_busType, i_busPos,
                  i_priority );
    }

    return rc;

    #undef PRDF_FUNC
}

} // end namespace CalloutUtil

} // end namespace PRDF

