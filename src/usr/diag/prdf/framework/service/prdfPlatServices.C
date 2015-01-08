/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdfPlatServices.C $      */
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
#include <initservice/initserviceif.H>

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

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

//------------------------------------------------------------------------------

void initiateUnitDump( TargetHandle_t i_target,
                       errlHndl_t i_errl,
                       uint32_t i_errlActions )
{
    // no-op in Hostboot but just go ahead and commit
    // the errorlog in case it's not null.
    if ( NULL != i_errl )
    {
        PRDF_COMMIT_ERRL(i_errl, i_errlActions);
    }
}

//------------------------------------------------------------------------------

bool isSpConfigFsp()
{
    #ifdef __HOSTBOOT_RUNTIME

    return false; // Should never have an FSP when using HBRT.

    #else

    return INITSERVICE::spBaseServicesEnabled();

    #endif
}

//##############################################################################
//##                       Processor specific functions
//##############################################################################

void collectSBE_FFDC(TARGETING::TargetHandle_t i_procTarget)
{
    // Do nothing for Hostboot
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

//##############################################################################
//##                        util functions
//##############################################################################

int32_t getCfam( ExtensibleChip * i_chip,
                 STEP_CODE_DATA_STRUCT & io_sc,
                 const uint32_t i_addr,
                 uint32_t & o_data)
{
    #define PRDF_FUNC "[PlatServices::getCfam] "

    int32_t rc = SUCCESS;

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

        PRD_FAPI_TO_ERRL(errH,
                         fapiGetCfamRegister,
                         PlatServices::getFapiTarget(l_procTgt),
                         i_addr,
                         cfamData);

        if ( NULL == errH )
        {
            o_data = cfamData.getWord(0);
        }
        else
        {
            rc = FAIL;
            PRDF_ERR( PRDF_FUNC"chip: 0x%.8X, failed to get cfam address: "
                      "0x%X", i_chip->GetId(), i_addr );
            PRDF_COMMIT_ERRL(errH, ERRL_ACTION_SA|ERRL_ACTION_REPORT);
            break;
        }


    } while(0);


    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getActiveRefClk(TARGETING::TargetHandle_t
                            i_procTarget,
                            TARGETING::TYPE i_connType,
                            uint32_t i_oscPos)
{
    return PlatServices::getClockId( i_procTarget,
                                     i_connType,
                                     i_oscPos );
}

} // end namespace PlatServices

} // end namespace PRDF

