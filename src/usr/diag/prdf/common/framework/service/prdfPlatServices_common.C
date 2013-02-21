/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: ./common/framework/service/prdfPlatServices_common.C $        */
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
 * @file  prdfPlatServices_common.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly common between FSP and Hostboot. All
 * platform specific code should be in the respective FSP only or Hostboot only
 * files.
 */

#include <prdfPlatServices.H>

#include <prdfGlobal.H>
#include <prdfAssert.h>
#include <prdfTrace.H>
#include <prdfErrlUtil.H>

#include <dimmBadDqBitmapFuncs.H> // for dimm[S|G]etBadDqBitmap()
#include <dram_initialization/mss_memdiag/mss_maint_cmds.H>

using namespace TARGETING;

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                     System Level Utility Functions
//##############################################################################

void getECIDString( TargetHandle_t i_target, const char * o_ecidStr )
{
    o_ecidStr ="";
    PRDF_ERR( "[PlatServices::getECIDString] Function not implemented yet" );
}

//##############################################################################
//##                       Processor specific functions
//##############################################################################

//##############################################################################
//##                        Memory specific functions
//##############################################################################

int32_t getBadDqBitmap( TargetHandle_t i_mbaTarget, const uint8_t i_portSlct,
                        const uint8_t i_dimmSlct, const uint8_t i_rankSlct,
                        uint8_t (&o_data)[DIMM_DQ_RANK_BITMAP_SIZE] )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, dimmGetBadDqBitmap,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      i_portSlct, i_dimmSlct, i_rankSlct, o_data );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::getBadDqBitmap] dimmGetBadDqBitmap() failed. "
                  "HUID: 0x%08x port: %d DIMM: %d rank: %d",
                  getHuid(i_mbaTarget), i_portSlct, i_dimmSlct, i_rankSlct );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t setBadDqBitmap( TargetHandle_t i_mbaTarget, const uint8_t i_portSlct,
                        const uint8_t i_dimmSlct, const uint8_t i_rankSlct,
                        const uint8_t (&i_data)[DIMM_DQ_RANK_BITMAP_SIZE] )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, dimmSetBadDqBitmap,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      i_portSlct, i_dimmSlct, i_rankSlct, i_data );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::getBadDqBitmap] dimmSetBadDqBitmap() failed. "
                  "HUID: 0x%08x ps: %d ds: %d rs: %d",
                  getHuid(i_mbaTarget), i_portSlct, i_dimmSlct, i_rankSlct );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mssGetMarkStore( TargetHandle_t i_mbaTarget, uint8_t i_rank,
                         uint8_t & o_chipMark, uint8_t & o_symbolMark )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, mss_get_mark_store,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      i_rank, o_chipMark, o_symbolMark );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssGetMarkStore] mss_get_mark_store() "
                  "failed. HUID: 0x%08x rank: %d",
                  getHuid(i_mbaTarget), i_rank );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mssSetMarkStore( TargetHandle_t i_mbaTarget, uint8_t i_rank,
                         uint8_t i_chipMark, uint8_t i_symbolMark )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    // TODO: mss_put_mark_store() will give a certain return code if the write
    //       to mark store was circumvented by hardware. Will need to check this
    //       return code.

    PRD_FAPI_TO_ERRL( errl, mss_put_mark_store,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      i_rank, i_chipMark, i_symbolMark );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssSetMarkStore] mss_put_mark_store() "
                  "failed. HUID: 0x%08x rank: %d cm: %d sm: %d",
                  getHuid(i_mbaTarget), i_rank, i_chipMark, i_symbolMark );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mssGetSteerMux( TargetHandle_t i_mbaTarget, uint8_t i_rank,
                        uint8_t & o_port0Spare, uint8_t & o_port1Spare,
                        uint8_t & o_eccSpare )
{
    int32_t o_rc = SUCCESS;

/* TODO: Marc is creating a new interface.
    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, TODO,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      i_rank, o_port0Spare, o_port1Spare, o_eccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssGetSteerMux] TODO() "
                  "failed. HUID: 0x%08x rank: %d",
                  getHuid(i_mbaTarget), i_rank );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
*/

    return o_rc;

}

//------------------------------------------------------------------------------

int32_t mssSetSteerMux( TargetHandle_t i_mbaTarget, uint8_t i_rank,
                        uint8_t i_symbol, bool i_x4EccSpare )
{
    int32_t o_rc = SUCCESS;

/* TODO: Marc is creating a new interface.
    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, TODO,
                      fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                      i_rank, i_symbol, i_x4EccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssSetSteerMux] TODO() "
                  "failed. HUID: 0x%08x rank: %d symbol: %d eccSpare: %c",
                  getHuid(i_mbaTarget), i_rank, i_symbol,
                  i_x4EccSpare ? 'T' : 'F' );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
*/

    return o_rc;

}

//------------------------------------------------------------------------------

/* TODO - Get the memory buffer raw card type (i.e. R/C A). This is needed for
          the DRAM site locations for buffered DIMMs. Should be able to get this
          from an attribute but doesn't look like this is available yet.
getMembufRawCardType()
{
}
*/

//------------------------------------------------------------------------------

/* TODO - Get the type of the card a DIMM is plugged into. This is needed for
          the DRAM site locations for IS DIMMs. Should be able to get this from
          an attribute but doesn't look like this is available yet.
getDimmPlugCardType()
{
}
*/

//##############################################################################
//##
//##                           Maintance command  wrapper code
//##
//##############################################################################

mss_MaintCmdWrapper::mss_MaintCmdWrapper( mss_MaintCmd * i_maintCmd ) :
    iv_cmd(i_maintCmd)
{}

//------------------------------------------------------------------------------

mss_MaintCmdWrapper::~mss_MaintCmdWrapper()
{
    delete iv_cmd;
}

//------------------------------------------------------------------------------

int32_t mss_MaintCmdWrapper::stopCmd()
{
    PRDF_ASSERT( NULL != iv_cmd );
    int32_t o_rc = SUCCESS;
    fapi::ReturnCode l_rc = iv_cmd->stopCmd();

    //  convert FAPI RC to error handle
    errlHndl_t err = fapi::fapiRcToErrl(l_rc);

    if (NULL != err)
    {
        PRDF_GET_REASONCODE(err, o_rc);
        PRDF_ERR( "mss_MaintCmdWrapper::stopCmd failed: [0x%X]", o_rc);
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mss_MaintCmdWrapper::setupAndExecuteCmd()
{
    PRDF_ASSERT( NULL != iv_cmd );
    int32_t o_rc = SUCCESS;
    fapi::ReturnCode l_rc = iv_cmd->setupAndExecuteCmd();

    //  convert FAPI RC to error handle
    errlHndl_t err = fapi::fapiRcToErrl(l_rc);

    if (NULL != err)
    {
        PRDF_GET_REASONCODE(err, o_rc);
        PRDF_ERR( "mss_MaintCmdWrapper::setupAndExecuteCmd "
                   "failed: [0x%X]", o_rc);
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mss_MaintCmdWrapper::cleanupCmd()
{
    PRDF_ASSERT( NULL != iv_cmd );
    int32_t o_rc = SUCCESS;
    fapi::ReturnCode l_rc = iv_cmd->cleanupCmd();

    //  convert FAPI RC to error handle
    errlHndl_t err = fapi::fapiRcToErrl(l_rc);

    if (NULL != err)
    {
        PRDF_GET_REASONCODE(err, o_rc);
        PRDF_ERR( "mss_MaintCmdWrapper::cleanupCmd failed: [0x%X]", o_rc);
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}

//------------------------------------------------------------------------------

mss_MaintCmdWrapper* createTimeBaseScrub (
                       const TARGETING::TargetHandle_t i_target,
                       uint64_t i_startAddr,
                       uint64_t i_endAddr,
                       bool  i_isFastSpeed,
                       uint32_t i_stopCondition )
{
    ecmdDataBufferBase ecmdStartAddr(64);
    ecmdDataBufferBase ecmdEndAddr(64);

    mss_MaintCmd::TimeBaseSpeed cmdSpeed = mss_MaintCmd::SLOW_12H;

    if (true == i_isFastSpeed)
    {
        cmdSpeed = mss_MaintCmd::FAST_AS_POSSIBLE;
    }
    // Fill up emd structures for maint cmd
    ecmdStartAddr.setDoubleWord(0, i_startAddr);
    ecmdEndAddr.setDoubleWord(0, i_endAddr);

    mss_MaintCmd *cmd = new mss_TimeBaseScrub(
                                     fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET,
                                                  i_target ),
                                     ecmdStartAddr,
                                     ecmdEndAddr,
                                     cmdSpeed,
                                     i_stopCondition,
                                     false);
    mss_MaintCmdWrapper *cmdWrapper = new mss_MaintCmdWrapper(cmd);
    return cmdWrapper;

}

} // end namespace PlatServices

} // end namespace PRDF

