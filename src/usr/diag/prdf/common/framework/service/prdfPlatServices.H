/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfPlatServices.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef PRDFPLATSERVICES_H
#define PRDFPLATSERVICES_H

/**
 * @file  prdfPlatServices.H
 * @brief Wrapper code for things PRD needs from external components ( other then targetting ).
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <algorithm>

#include <iipconst.h>
#include <prdfTargetServices.H>
#include <prdfTimer.H>

#include <errlentry.H>
#include <dimmConsts.H>

#ifdef __HOSTBOOT_MODULE
  #include <dram_initialization/mss_memdiag/mss_maint_cmds.H>
#endif

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##
//##                        Hostboot and FSP functions
//##
//##############################################################################

//##############################################################################
//##                     System Level Utility Functions
//##############################################################################

//FIXME functions defintion not found.Should we remove it?
//void enterCCMMode();
//bool inCMMode();
//bool isCM_FUNCTIONAL(TARGETING::TargetHandle_t);

/**
 * @brief   Returns if role is mater fsp.
 * @param   None.
 * @return  TRUE if master fsp. FALSE if not master fsp.
 * @pre     None.
 * @post    None.
 */
bool isMasterFSP();

/**
 * @brief   Checks if we are currently doing a memory preserving IPL.
 * @param   None.
 * @return  TRUE if this is a memory preserving IPL, FALSE otherwise.
 * @pre     None.
 * @post    None.
 */
bool isMemoryPreservingIpl();

/**
 * @brief   Return ecidString for a given target
 * @param   i_pGivenTarget  handle to target
 * @param   o_ecidStr       buffer for ecidstring
 * @return  Returns ecidString for given target Handle
 * @pre     none
 * @post    none
 */
void getECIDString( TARGETING::TargetHandle_t i_pGivenHandle, const char *o_ecidStr );

/**
 * @brief Get a PRD timer value based on the current time.
 * @param o_timer The returned Timer
 */
void getCurrentTime( Timer & o_timer );

/**
 * @brief   synch the file with rmgr
 * @param   i_fileName file name
 * @return  NULL if synch is unsuccessfull, error handle otherwise
 */
errlHndl_t syncFile( const char* i_fileName );

//##############################################################################
//##                     MNFG Policy Flag Functions
//##############################################################################

/**
 * @brief   Returns the state of the MNFG_THRESHOLDS policy flag.
 * @return  TRUE if MNFG_THRESHOLDS is set, FALSE otherwise.
 */
bool mfgMode();

/**
 * @brief   Returns the state of the MNFG_HDAT_AVP_ENABLE policy flag.
 * @return  TRUE if MNFG_HDAT_AVP_ENABLE is set, FALSE otherwise.
 */
bool hdatAvpMode();

/**
 * @brief   Returns status of MNFG_SRC_TERM manufacturing policy flag.
 * @param   None.
 * @return  TRUE if MNFG_SRC_TERM policy flag is set, FALSE
 *          otherwise.
 * @pre     None.
 * @post    None.
 */
bool mnfgTerminate();

/**
 * @brief  Returns the state of the MNFG_NO_RBS policy flag.
 * @return TRUE if MNFG_NO_RBS is set, FALSE otherwise.
 */
bool areDramRepairsDisabled();

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief   Returns the memory buffer raw card type (i.e. R/C A).
 * @param   i_memTarget A memory buffer, MBA, or DIMM.
 * @return
 */
/* TODO - See .C
getMembufRawCardType( TARGETING::TargetHandle_t i_memTarget );
*/

/**
 * @brief   Returns the type of the card the DIMM is plugged into.
 * @param   i_dimmTarget A DIMM target.
 * @return
 */

/* TODO - See .C
getDimmPlugCardType( TARGETING::TargetHandle_t i_dimmTarget );
*/

/**
 * @brief   Writes the bad DQ bitmap attribute.
 * @param   i_mbaTarget A MBA target.
 * @param   i_portSlct  Port select (0-1).
 * @param   i_dimmSlct  DIMM select (0-1).
 * @param   i_rankSlct  Rank select (0-3).
 * @param   i_data      The input data array.
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
/* TODO - See .C
int32_t setBadDqBitmap( TARGETING::TargetHandle_t i_mbaTarget
                        const uint8_t i_portSlct,
                        const uint8_t i_dimmSlct,
                        const uint8_t i_rankSlct,
                        const uint8_t (&i_data)[DIMM_DQ_RANK_BITMAP_SIZE] );
*/

//##############################################################################
//##
//##                        Hostboot only functions
//##
//##############################################################################

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Checks if we are running in MDIA mode.
 * @return TRUE if in MDIA mode, FALSE otherwise.
 */
bool isInMdiaMode();

/**
 * @brief  Sends a command complete message to MDIA.
 * @param  i_mbaTarget An MBA target.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mdiaSendCmdComplete( TARGETING::TargetHandle_t i_mbaTarget );

/**
 * @brief  Invokes the get mark store hardware procedure.
 * @param  i_mbaTarget
 * @param  i_rank
 * @param  o_chipMark
 * @param  o_symbolMark
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssGetMarkStore(
        TARGETING::TargetHandle_t i_mbaTarget,
        uint8_t i_rank,
        uint8_t & o_chipMark,
        uint8_t & o_symbolMark);

/**
 * @brief  Invokes the get steer mux hardware procedure.
 * @param  i_mbaTarget
 * @param  i_rank
 * @param  i_muxType Read/Write Mux select
 * @param  o_portZeroSpare
 * @param  o_portOneSpare
 * @param  o_eccSpare
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssGetSteerMux(
        TARGETING::TargetHandle_t i_mbaTarget,
        uint8_t i_rank,
        mss_SteerMux::muxType i_muxType,
        uint8_t & o_portZeroSpare,
        uint8_t & o_portOneSpare,
        uint8_t & o_eccSpare);

/**
 * @brief  Invokes the restore DRAM repairs hardware procedure.
 * @param  i_mbaTarget
 * @param  o_repairedRankMask An encoded bitmask of repaired ranks.
 * @param  o_badDimm An encoded bitmask of bad DIMMs.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssRestoreDramRepairs(
        TARGETING::TargetHandle_t i_mbaTarget,
        uint8_t & o_repairedRankMask,
        uint8_t & o_badDimmMask);

/**
 * @brief   Reads the bad DQ bitmap attribute.
 * @param   i_mbaTarget A MBA target.
 * @param   i_portSlct  Port select (0-1).
 * @param   i_dimmSlct  DIMM select (0-1).
 * @param   i_rankSlct  Rank select (0-3).
 * @param   o_data      The return data array.
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
// FIXME: Eventually needs to be supported in FSP code as well.
int32_t getBadDqBitmap( TARGETING::TargetHandle_t i_mbaTarget,
                        const uint8_t i_portSlct,
                        const uint8_t i_dimmSlct,
                        const uint8_t i_rankSlct,
                        uint8_t (&o_data)[DIMM_DQ_RANK_BITMAP_SIZE] );

#endif // __HOSTBOOT_MODULE

//##############################################################################
//##
//##                           FSP only functions
//##
//##############################################################################

#ifndef __HOSTBOOT_MODULE

/**
 * @brief  Do a runtime deconfiguration of the given target.
 * @param  i_target The target to deconfigure.
 * @return NULL if deconfig is successful, non-NULL otherwise.
 */
errlHndl_t runtimeDeconfig( TARGETING::TargetHandle_t i_target );

#endif // not __HOSTBOOT_MODULE

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_H

