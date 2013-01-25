/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: ./framework/service/prdfPlatServices.C $                      */
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

/**
 * @file  prdfPlatServices.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfPlatServices.H>

#include <iipglobl.h>
#include <prdfAssert.h>

#include <diag/mdia/mdia.H>
#include <diag/mdia/mdiamevent.H>
#include <dram_initialization/mss_memdiag/mss_maint_cmds.H>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

using namespace TARGETING;

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

bool isMasterFSP()
{
    // Always true in Hostboot
    return true;
}

//------------------------------------------------------------------------------

bool isMemoryPreservingIpl()
{
    bool l_isMemPreservingIpl = false;

    // TODO (RTC 23138): Add support for Hostboot.

    return l_isMemPreservingIpl;
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

int32_t syncFile( const char * i_fileName )
{
    return SUCCESS;
}

//##############################################################################
//##                       Processor specific functions
//##############################################################################

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

int32_t mdiaSendCmdComplete( TargetHandle_t i_mbaTarget )
{
    int32_t o_rc = SUCCESS;

    do
    {
        // Verify type.
        TYPE l_type = getTargetType(i_mbaTarget);
        if ( TYPE_MBA != l_type )
        {
            PRDF_ERR( "[PlatServices::mdiaSendCmdComplete] unsupported target "
                      "type %d", l_type );
            o_rc = FAIL;
            break;
        }

        // Send command complete to MDIA.
        MDIA::MaintCommandEvent l_mdiaEvent;
        l_mdiaEvent.type   = MDIA::COMMAND_COMPLETE;
        l_mdiaEvent.target = i_mbaTarget;

        errlHndl_t errl = MDIA::processEvent( l_mdiaEvent );
        if ( NULL != errl )
        {
            PRDF_ERR( "[PlatServices::mdiaSendCmdComplete] MDIA::processEvent "
                      "failed" );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[PlatServices::mdiaSendCmdComplete] Failed: i_target=0x%08x",
                  getHuid(i_mbaTarget) );
    }

    return o_rc;
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

} // end namespace PlatServices

} // end namespace PRDF

