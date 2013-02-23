/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: ./common/framework/service/prdfPlatServices_common.H $        */
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

#ifndef PRDFPLATSERVICES_COMMON_H
#define PRDFPLATSERVICES_COMMON_H

/**
 * @file  prdfPlatServices_common.H
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly common between FSP and Hostboot. All
 * platform specific code should be in the respective FSP only or Hostboot only
 * files.
 *
 * Note that only the respective platform specific header files should include
 * this header file.
 */

#include <prdfTargetServices.H> // must include all common targeting code

#include <prdfTimer.H>

#include <dimmConsts.H>         // for DIMM_DQ_RANK_BITMAP_SIZE
#include <fapiPlatHwpInvoker.H> // for fapi::fapiRcToErrl()

class mss_MaintCmd;

#define PRD_FAPI_TO_ERRL(ERRHNDL, FUNC, _args_...) \
    { \
        fapi::ReturnCode l_rc = FUNC(_args_); \
        ERRHNDL = fapi::fapiRcToErrl(l_rc);   \
    }

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
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
 * @return  TRUE if this is a memory preserving IPL, FALSE otherwise.
 */
bool isMemoryPreservingIpl();

/**
 * @brief   Return ECID string for a given target
 * @param   i_target  Any target
 * @param   o_ecidStr buffer for ECID string
 * @return  Returns ECID string for given target
 */
void getECIDString( TARGETING::TargetHandle_t i_target,
                    const char * o_ecidStr );

/**
 * @brief Get a PRD timer value based on the current time.
 * @param o_timer The returned Timer
 */
void getCurrentTime( Timer & o_timer );

/**
 * @brief  Sync the file with RMGR
 * @param  i_fileName File name
 * @return Non-SUCCESS if sync is unsuccessful, SUCCESS otherwise.
 */
int32_t syncFile( const char * i_fileName );

//##############################################################################
//##                       Processor specific functions
//##############################################################################

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Reads the bad DQ bitmap attribute.
 * @param  i_mbaTarget A MBA target.
 * @param  i_portSlct  Port select (0-1).
 * @param  i_dimmSlct  DIMM select (0-1).
 * @param  i_rankSlct  Rank select (0-3).
 * @param  o_data      The return data array.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getBadDqBitmap( TARGETING::TargetHandle_t i_mbaTarget,
                        const uint8_t i_portSlct,
                        const uint8_t i_dimmSlct,
                        const uint8_t i_rankSlct,
                        uint8_t (&o_data)[DIMM_DQ_RANK_BITMAP_SIZE] );

/**
 * @brief  Writes the bad DQ bitmap attribute.
 * @param  i_mbaTarget A MBA target.
 * @param  i_portSlct  Port select (0-1).
 * @param  i_dimmSlct  DIMM select (0-1).
 * @param  i_rankSlct  Rank select (0-3).
 * @param  i_data      The input data array.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setBadDqBitmap( TARGETING::TargetHandle_t i_mbaTarget,
                        const uint8_t i_portSlct,
                        const uint8_t i_dimmSlct,
                        const uint8_t i_rankSlct,
                        const uint8_t (&i_data)[DIMM_DQ_RANK_BITMAP_SIZE] );

/**
 * @brief  Invokes the get mark store hardware procedure.
 * @param  i_mbaTarget  A MBA target.
 * @param  i_rank       Target rank (0-7).
 * @param  o_chipMark   A symbol associated with the returned chip mark.
 * @param  o_symbolMark A symbol associated with the returned symbol mark.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssGetMarkStore( TARGETING::TargetHandle_t i_mbaTarget, uint8_t i_rank,
                         uint8_t & o_chipMark, uint8_t & o_symbolMark );

/**
 * @brief  Invokes the set mark store hardware procedure.
 * @param  i_mbaTarget  A MBA target.
 * @param  i_rank       Target rank (0-7).
 * @param  i_chipMark   A symbol associated with the new chip mark.
 * @param  i_symbolMark A symbol associated with the new symbol mark.
 * @note   Both the chip mark and the symbol mark will be written at the same
 *         time, so do a RMW operation to avoid overwriting a previous mark.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssSetMarkStore( TARGETING::TargetHandle_t i_mbaTarget, uint8_t i_rank,
                         uint8_t i_chipMark, uint8_t i_symbolMark );

/**
 * @brief  Invokes the get steer mux hardware procedure.
 * @param  i_mbaTarget  A MBA target.
 * @param  i_rank       Target rank (0-7).
 * @param  o_port0Spare A symbol associated with the spare on port 0.
 * @param  o_port1Spare A symbol associated with the spare on port 1.
 * @param  o_eccSpare   A symbol associated with the ECC spare (x4 mode only).
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssGetSteerMux( TARGETING::TargetHandle_t i_mbaTarget, uint8_t i_rank,
                        uint8_t & o_port0Spare, uint8_t & o_port1Spare,
                        uint8_t & o_eccSpare );

/**
 * @brief  Invokes the set steer mux hardware procedure.
 * @param  i_mbaTarget  A MBA target.
 * @param  i_rank       Target rank (0-7).
 * @param  i_symbol     A symbol associated with the DRAM to be spared.
 * @param  i_x4EccSpare If true, will set ECC spare instead (x4 mode only).
 * @note   The procedure will be able to derive the port from the given symbol.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssSetSteerMux( TARGETING::TargetHandle_t i_mbaTarget, uint8_t i_rank,
                        uint8_t i_symbol, bool i_x4EccSpare );

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

//##############################################################################
//##                    Maintance Command class wrapper
//##############################################################################

/**
 * @brief This is a wrapper class for underlying maintainance class object
 *
 * By this class, we will hide underlying maintainance class dependency
 * from rest of code. All public function mss_MaintCmd used by prd should
 * be defined here also.
 */

class mss_MaintCmdWrapper
{

  public: // functions

    /**
     * @brief Constructor
     *
     * @param i_maintCmd Underlying maintainance command object
     */
    mss_MaintCmdWrapper( mss_MaintCmd * i_maintCmd );

    /**
     * @brief Destructor
     */
    virtual ~mss_MaintCmdWrapper();

    /**
     * @brief  Stops running maint cmd, and saves the address it stopped at.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t stopCmd();

    /**
     * @brief  Saves any settings that need to be restored when command is done.
     *         Loads the setup parameters into the hardware. Starts the command,
     *         then either polls for complete or exits with command running.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
     int32_t setupAndExecuteCmd();

    /**
     * @brief  Called once a command is done if we need to restore settings that
     *         had to be modified to run a specific command type, or clear error
     *         data in the hw that is no longer relevant.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
     int32_t cleanupCmd();

  private: // instance variables

    // Underlying maintainance command object pointer
    mss_MaintCmd * iv_cmd;

}; // class mss_MaintCmdWrapper

/**
 * @brief  Create Time base scrub object, wrap i around mss_MaintCmdWrapper
 *         object
 * @param  i_mba           An MBA target.
 * @param  i_startAddr     Start address for scrubbing.
 * @param  i_endAddr       End address for scrubbing.
 * @param  i_isFastSpeed   false = slow (12 H) , true = fast
 * @param  i_stopCondition Bit mask for conditions on which scrubbing should
 *                         stop.
 * @return mss_MaintCmdWrapper object
 * @note   This function allocates memory on heap for mss_MaintCmdWrapper
 *         object. It is the caller's responsibilty to delete this object.
 */
mss_MaintCmdWrapper * createTimeBaseScrub(
                       const TARGETING::TargetHandle_t i_mba,
                       uint64_t i_startAddr,
                       uint64_t i_endAddr,
                       bool i_isFastSpeed,
                       uint32_t i_stopCondition );


} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_COMMON_H

