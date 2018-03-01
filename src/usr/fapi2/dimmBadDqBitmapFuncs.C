/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/dimmBadDqBitmapFuncs.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include <dimmBadDqBitmapFuncs.H>
#include <string.h>
#include <attribute_service.H>
#include <target.H>
#include <errl/errlmanager.H>

using namespace TARGETING;

extern "C"
{


//------------------------------------------------------------------------------
// Utility function to check parameters and get the Bad DQ bitmap
//------------------------------------------------------------------------------
fapi2::ReturnCode dimmBadDqCheckParamGetBitmap( const fapi2::Target
    <fapi2::TARGET_TYPE_MCA|fapi2::TARGET_TYPE_MBA> & i_fapiTrgt,
    const uint8_t i_port,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    TARGETING::TargetHandle_t & o_dimmTrgt,
    uint8_t (&o_dqBitmap)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT])
{
    fapi2::ReturnCode l_rc;

    do
    {
        // Check parameters.
        if ( (i_dimm >= mss::MAX_DIMM_PER_PORT) ||
             (i_rank >= mss::MAX_RANK_PER_DIMM) )
        {
            FAPI_ERR( "dimmBadDqCheckParamGetBitmap: Bad parameter. "
                      "i_dimm:%d i_rank:%d", i_dimm, i_rank );
            l_rc = fapi2::FAPI2_RC_INVALID_ATTR_GET;
            break;
        }

        errlHndl_t l_errl = nullptr;
        TARGETING::TargetHandle_t l_trgt = nullptr;

        l_errl = fapi2::platAttrSvc::getTargetingTarget(i_fapiTrgt, l_trgt);
        if ( l_errl )
        {
            FAPI_ERR( "dimmBadDqCheckParamGetBitmap: Error from "
                      "getTargetingTarget" );
            errlCommit( l_errl, FAPI2_COMP_ID );
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }

        // Get the proc model
        TARGETING::Target* l_masterProc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );
        TARGETING::ATTR_MODEL_type l_procModel =
            l_masterProc->getAttr<TARGETING::ATTR_MODEL>();

        // Get the DIMM
        TargetHandleList l_dimmList;

        if ( TARGETING::MODEL_CUMULUS == l_procModel )
        {
            // Get all functional DIMMs
            getChildAffinityTargets( l_dimmList, l_trgt, CLASS_NA, TYPE_DIMM );

            // Find the DIMM with the correct MBA port/dimm
            uint8_t l_port = 0;
            uint8_t l_dimm = 0;

            for ( auto &dimmTrgt : l_dimmList )
            {
                // Get and compare the port
                l_port = dimmTrgt->getAttr<ATTR_MBA_PORT>();

                if ( l_port == i_port )
                {
                    // Get and compare the dimm
                    l_dimm = dimmTrgt->getAttr<ATTR_MBA_DIMM>();

                    if ( l_dimm == i_dimm )
                    {
                        o_dimmTrgt = dimmTrgt;
                        // Port and dimm are correct, get the Bad DQ bitmap
                        l_rc = FAPI_ATTR_GET( fapi2::ATTR_BAD_DQ_BITMAP,
                                              dimmTrgt, o_dqBitmap );
                        if ( l_rc ) break;
                    }
                }
            }
        }
        else if ( TARGETING::MODEL_NIMBUS == l_procModel )
        {
            // Get all connected DIMMs, even nonfunctioning ones.
            getChildAffinityTargets( l_dimmList, l_trgt, CLASS_NA, TYPE_DIMM,
                                     false );
            o_dimmTrgt = l_dimmList[i_dimm];

            // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
            l_rc = FAPI_ATTR_GET( fapi2::ATTR_BAD_DQ_BITMAP, o_dimmTrgt,
                                  o_dqBitmap );
        }
        else
        {
            // Invalid target.
            FAPI_ERR( "dimmBadDqCheckParamGetBitmap: Invalid proc model" );
            l_rc = fapi2::FAPI2_RC_INVALID_ATTR_GET;
            break;
        }

        if ( l_rc )
        {
            FAPI_ERR( "dimmBadDqCheckParamGetBitmap: Error getting "
                      "ATTR_BAD_DQ_BITMAP." );
        }

    }while(0);

    return l_rc;
}

//------------------------------------------------------------------------------
fapi2::ReturnCode p9DimmGetBadDqBitmap( const fapi2::Target
    <fapi2::TARGET_TYPE_MCA|fapi2::TARGET_TYPE_MBA> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    uint8_t (&o_data)[mss::BAD_DQ_BYTE_COUNT],
    const uint8_t i_port )
{
    FAPI_INF( ">>p9DimmGetBadDqBitmap. %d:%d", i_dimm, i_rank );

    fapi2::ReturnCode l_rc;

    do
    {
        uint8_t l_dqBitmap[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT];
        TARGETING::TargetHandle_t l_dimmTrgt = nullptr;

        // Check parameters and get Bad Dq Bitmap
        l_rc = dimmBadDqCheckParamGetBitmap( i_fapiTrgt, i_port, i_dimm, i_rank,
                                             l_dimmTrgt, l_dqBitmap );
        if ( l_rc )
        {
            FAPI_ERR( "p9DimmGetBadDqBitmap: Error from "
                      "dimmBadDqCheckParamGetBitmap." );
            break;
        }
        // Write contents of DQ bitmap for specific rank to o_data.
        memcpy( o_data, l_dqBitmap[i_rank], mss::BAD_DQ_BYTE_COUNT );
    }while(0);

    FAPI_INF( "<<p9DimmGetBadDqBitmap" );

    return l_rc;
}

//------------------------------------------------------------------------------
fapi2::ReturnCode p9DimmSetBadDqBitmap( const fapi2::Target
    <fapi2::TARGET_TYPE_MCA|fapi2::TARGET_TYPE_MBA> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    const uint8_t (&i_data)[mss::BAD_DQ_BYTE_COUNT],
    const uint8_t i_port )
{
    FAPI_INF( ">>p9DimmSetBadDqBitmap. %d:%d", i_dimm, i_rank );

    fapi2::ReturnCode l_rc;

    do
    {
        // Get the Bad DQ Bitmap by querying ATTR_BAD_DQ_BITMAP.
        uint8_t l_dqBitmap[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT];
        TARGETING::TargetHandle_t l_dimmTrgt = nullptr;

        // Check parameters and get Bad Dq Bitmap
        l_rc = dimmBadDqCheckParamGetBitmap( i_fapiTrgt, i_port, i_dimm, i_rank,
                                             l_dimmTrgt, l_dqBitmap );
        if ( l_rc )
        {
            FAPI_ERR("p9DimmSetBadDqBitmap: Error getting ATTR_BAD_DQ_BITMAP.");
            break;
        }
        // Add the rank bitmap to the DIMM bitmap and write the bitmap.
        memcpy( l_dqBitmap[i_rank], i_data, mss::BAD_DQ_BYTE_COUNT );

        errlHndl_t l_errl = nullptr;
        TARGETING::TargetHandle_t l_trgt = nullptr;
        l_errl = fapi2::platAttrSvc::getTargetingTarget(i_fapiTrgt, l_trgt);
        if ( l_errl )
        {
            FAPI_ERR( "p9DimmSetBadDqBitmap: Error from getTargetingTarget" );
            break;
        }

        l_rc = FAPI_ATTR_SET( fapi2::ATTR_BAD_DQ_BITMAP, l_dimmTrgt,
                l_dqBitmap );

        if ( l_rc )
        {
            FAPI_ERR("p9DimmSetBadDqBitmap: Error setting ATTR_BAD_DQ_BITMAP.");
        }
    }while(0);

    FAPI_INF( "<<p9DimmSetBadDqBitmap" );

    return l_rc;
}

} // extern "C"
