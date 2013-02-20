/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCalloutUtil.C $     */
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

/** @file prdfCalloutUtil.C */

#include <prdfCalloutUtil.H>

#include <iipServiceDataCollector.h>
#include <prdfCenAddress.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CalloutUtil
{

void defaultError( STEP_CODE_DATA_STRUCT & i_sc )
{
    i_sc.service_data->SetCallout( NextLevelSupport_ENUM );
    i_sc.service_data->SetCallout( SP_CODE );
    i_sc.service_data->SetServiceCall();
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

} // end namespace CalloutUtil

} // end namespace PRDF

