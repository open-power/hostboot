/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdfPlatServices_ipl.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

/**
 * @file  prdfPlatServices_ipl.C
 * @brief Wrapper code for external interfaces used by PRD (IPL only).
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfPlatServices.H>

#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

#include <prdfCenDqBitmap.H>

#include <diag/mdia/mdia.H>
#include <diag/mdia/mdiamevent.H>
#include <config.h>

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

bool isInMdiaMode()
{
    bool o_isInMdiaMode = false;
#ifndef CONFIG_VPO_COMPILE
    MDIA::waitingForMaintCmdEvents(o_isInMdiaMode);
#endif
    return o_isInMdiaMode;
}

//------------------------------------------------------------------------------

int32_t mdiaSendEventMsg( TargetHandle_t i_mbaTarget,
                          MDIA::MaintCommandEventType i_eventType )
{
    #define PRDF_FUNC "[PlatServices::mdiaSendCmdComplete] "

    int32_t o_rc = SUCCESS;

#ifndef CONFIG_VPO_COMPILE

    do
    {
        if ( !isInMdiaMode() ) break; // no-op

        // Verify type.
        TYPE l_type = getTargetType(i_mbaTarget);
        if ( TYPE_MBA != l_type )
        {
            PRDF_ERR( PRDF_FUNC"unsupported target type %d", l_type );
            o_rc = FAIL;
            break;
        }

        // Send command complete to MDIA.
        MDIA::MaintCommandEvent l_mdiaEvent;

        l_mdiaEvent.target = i_mbaTarget;
        l_mdiaEvent.type = i_eventType;

        errlHndl_t errl = MDIA::processEvent( l_mdiaEvent );
        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC"MDIA::processEvent() failed" );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_target=0x%08x i_eventType=%d",
                  getHuid(i_mbaTarget), i_eventType );
    }

#endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mssRestoreDramRepairs( TargetHandle_t i_mbaTarget,
                               uint8_t & o_repairedRankMask,
                               uint8_t & o_badDimmMask )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, mss_restore_DRAM_repairs,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      o_repairedRankMask, o_badDimmMask );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssRestoreDramRepairs] "
                  "mss_restore_dram_repairs() failed. HUID: 0x%08x",
                  getHuid(i_mbaTarget) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mssIplUeIsolation( TargetHandle_t i_mba, const CenRank & i_rank,
                           CenDqBitmap & o_bitmap )
{
    #define PRDF_FUNC "[PlatServices::mssIplUeIsolation] "

    int32_t o_rc = SUCCESS;

    uint8_t data[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE];

    errlHndl_t errl = NULL;
    PRD_FAPI_TO_ERRL( errl, mss_IPL_UE_isolation, getFapiTarget(i_mba),
                      i_rank.getMaster(), data );
    if ( NULL != errl )
    {
        PRDF_ERR( PRDF_FUNC"mss_IPL_UE_isolation() failed: MBA=0x%08x "
                  "rank=%d", getHuid(i_mba), i_rank.getMaster() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    else
    {
        o_bitmap = CenDqBitmap ( i_mba, i_rank, data );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

