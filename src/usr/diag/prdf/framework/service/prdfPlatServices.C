/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdfPlatServices.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
 * @file  prdfPlatServices.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfPlatServices.H>

#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>
#include <prdfAssert.h>

#include <prdfCenAddress.H>
#include <prdfCenDqBitmap.H>
#include <iipServiceDataCollector.h>
#include <UtilHash.H>

#include <diag/mdia/mdia.H>
#include <diag/mdia/mdiamevent.H>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <targeting/common/targetservice.H>

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

bool isMemoryPreservingIpl()
{
    using namespace TARGETING;

    bool l_isMemPreservingIpl = false;
    TargetHandle_t l_pTarget = getSystemTarget();

    if(l_pTarget && l_pTarget->getAttr<ATTR_IS_MPIPL_HB>())
    {
        l_isMemPreservingIpl = true;
    }

    return l_isMemPreservingIpl;
}

bool isSapphireRunning( )
{
    return false;
}

//------------------------------------------------------------------------------

void getCurrentTime( Timer & o_timer )
{
    timespec_t curTime;
    PRDF_ASSERT(0 == clock_gettime(CLOCK_MONOTONIC, &curTime))

    // Hostboot uptime in seconds
    o_timer = curTime.tv_sec;

    // Since Hostboot doesn't have any system checkstop, we don't have to worry
    // about the detailed time struct for system checkstop timestamp.
}

//------------------------------------------------------------------------------

void milliSleep( uint32_t i_seconds, uint32_t i_milliseconds )
{
    nanosleep( i_seconds, i_milliseconds * 1000000 );
}

//##############################################################################
//##                       Processor specific functions
//##############################################################################

void collectSBE_FFDC(TARGETING::TargetHandle_t i_procTarget)
{
    // Do nothing for Hostboot
}

//##############################################################################
//##                        Memory specific functions
//##############################################################################

bool isInMdiaMode()
{
    bool o_isInMdiaMode = false;

    MDIA::waitingForMaintCmdEvents(o_isInMdiaMode);

    return o_isInMdiaMode;
}

//------------------------------------------------------------------------------

int32_t mdiaSendEventMsg( TargetHandle_t i_mbaTarget,
                          MDIA::MaintCommandEventType i_eventType )
{
    #define PRDF_FUNC "[PlatServices::mdiaSendCmdComplete] "

    int32_t o_rc = SUCCESS;

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

TARGETING::TargetHandle_t getMasterCore( TARGETING::TargetHandle_t i_procTgt )
{
    #define PRDF_FUNC "[PlatServices::getMasterCore] "

    PRDF_ERR( PRDF_FUNC"MasterCore info not available in hostboot: PROC = "
              "0x%08x ",getHuid( i_procTgt ) );
    return NULL;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool isSmpCoherent() { return false; }

//##############################################################################
//##                        util functions
//##############################################################################

void captureFsiStatusReg( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[PlatServices::captureFsiStatusReg] "

    do
    {
        // HB doesn't allow cfam access on master proc
        TargetHandle_t l_procTgt = i_chip->GetChipHandle();

        if( TYPE_PROC == getTargetType(l_procTgt) )
        {
            TargetHandle_t l_pMasterProcChip = NULL;
            targetService().
                masterProcChipTargetHandle( l_pMasterProcChip );

            if( l_pMasterProcChip == l_procTgt )
            {
                PRDF_DTRAC( PRDF_FUNC"can't access CFAM from master "
                            "proc: 0x%.8X", i_chip->GetId() );
                break;
            }
        }

        errlHndl_t errH = NULL;
        ecmdDataBufferBase cfamData(32);
        uint32_t u32Data = 0;

        PRD_FAPI_TO_ERRL(errH,
                         fapiGetCfamRegister,
                         PlatServices::getFapiTarget(i_chip->GetChipHandle()),
                         0x00001007,
                         cfamData);

        if(errH)
        {
            PRDF_ERR( PRDF_FUNC"chip: 0x%.8X, failed to get "
                      "CFAM_FSI_STATUS: 0x%X",
                      i_chip->GetId(), cfamData.getWord( 0 ) );
            PRDF_COMMIT_ERRL(errH, ERRL_ACTION_SA|ERRL_ACTION_REPORT);
            break;
        }

        u32Data = cfamData.getWord(0);
        BIT_STRING_ADDRESS_CLASS bs (0, 32, (CPU_WORD *) &u32Data);

        io_sc.service_data->GetCaptureData().Add(
                            i_chip->GetChipHandle(),
                            ( Util::hashString("CFAM_FSI_STATUS") ^
                              i_chip->getSignatureOffset() ),
                            bs);
    } while(0);

    #undef PRDF_FUNC
}


} // end namespace PlatServices

} // end namespace PRDF

