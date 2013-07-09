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

#include <prdfCenConst.H>
#include <prdfTimer.H>

#include <dimmConsts.H>         // for DIMM_DQ_RANK_BITMAP_SIZE
#include <fapiPlatHwpInvoker.H> // for fapi::fapiRcToErrl()

#define PRD_FAPI_TO_ERRL(ERRHNDL, FUNC, _args_...) \
    { \
        fapi::ReturnCode l_rc = FUNC(_args_); \
        ERRHNDL = fapi::fapiRcToErrl(l_rc);   \
    }

//------------------------------------------------------------------------------

namespace PRDF
{

class CenAddr;
class CenDqBitmap;
class CenMark;
class CenRank;
class CenSymbol;

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
                    char * o_ecidStr );

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

/**
 * @brief Sleep for given time (seconds plus milliseconds).
 * @param i_seconds      Sleep time in seconds.
 * @param i_milliseconds Sleep time in milliseconds.
 */
void milliSleep( uint32_t i_seconds, uint32_t i_milliseconds );

/**
 * @brief   Convert a Targeting target to FAPI target
 * @param   i_target  Any target
 * @return  Returns the corresponding FAPI target for a given target
 */
fapi::Target getFapiTarget( TARGETING::TargetHandle_t i_target );

/**
 * @brief Check SMGR runtime state
 * @return true if SMGR state is runtime, false in hostboot without checking
 */
bool atRuntime();

//##############################################################################
//##                       Processor specific functions
//##############################################################################

//##############################################################################
//##                       Lane Repair functions
//##############################################################################

/**
 * @brief   Calls HWP to read newly failed bus lanes
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   o_rxFailLanes Vector of failed lanes
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t readErepair(TARGETING::TargetHandle_t i_rxBusTgt,
                    std::vector<uint8_t> &o_rxFailLanes);

/**
 * @brief   Calls HWP to clear FIRs after a lane repair event
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t clearIOFirs(TARGETING::TargetHandle_t i_rxBusTgt);

/**
 * @brief   Calls HWP to power down failed lanes
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   i_rxFailLanes Vector of  rx failed lanes
 * @param   i_txFailLanes Vector of  tx failed lanes
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t powerDownLanes(TARGETING::TargetHandle_t i_rxBusTgt,
                       const std::vector<uint8_t> &i_rxFailLanes,
                       const std::vector<uint8_t> &i_txFailLanes);

/**
 * @brief   Calls erepair accessor procedure get failed lanes from VPD
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   o_rxFailLanes Vector of  rx failed lanes
 * @param   o_txFailLanes Vector of  tx failed lanes
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getVpdFailedLanes(TARGETING::TargetHandle_t i_rxBusTgt,
                          std::vector<uint8_t> &o_rxFailLanes,
                          std::vector<uint8_t> &o_txFailLanes);

/**
 * @brief   Calls erepair prcd to set failed lanes in vpd and check threshold
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   i_txBusTgt    Target of the tranmitting end of the bus
 * @param   i_rxFailLanes Vector of  rx failed lanes
 * @param   o_thrExceeded True if these failed lanes exceeded erepair threshold
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setVpdFailedLanes(TARGETING::TargetHandle_t i_rxBusTgt,
                          TARGETING::TargetHandle_t i_txBusTgt,
                          std::vector<uint8_t> &i_rxFailLanes,
                          bool & o_thrExceeded);

/**
 * @brief   Calls io_fir_isolation HWP and commits FAPI errorlog containing
 *          additional FFDC
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @return  SUCCESS
 */
int32_t erepairFirIsolation(TARGETING::TargetHandle_t i_rxBusTgt);

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Reads the bad DQ bitmap attribute for both ports of the target rank.
 * @param  i_mbaTarget A MBA target.
 * @param  i_rank        Target rank.
 * @param  o_bitmap      DQ bitmap container.
 * @param  i_allowNoDimm TRUE ignores rc from hardware procedure indicating no
 *                       DIMM is attached. This is useful when iterating all
 *                       possible ranks. Default is FALSE.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getBadDqBitmap( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        CenDqBitmap & o_bitmap, bool i_allowNoDimm = false );

/**
 * @brief  Writes the bad DQ bitmap attribute for both ports of the target rank.
 * @param  i_mbaTarget A MBA target.
 * @param  i_rank   Target rank.
 * @param  i_bitmap DQ bitmap container.
 * @note   This is a no-op if DRAM Repairs are disabled in manufacturing.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setBadDqBitmap( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        const CenDqBitmap & i_bitmap );

/**
 * @brief  Invokes the get mark store hardware procedure.
 * @param  i_mba  Target MBA.
 * @param  i_rank Target rank.
 * @param  o_mark The returned mark.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssGetMarkStore( TARGETING::TargetHandle_t i_mba,
                         const CenRank & i_rank, CenMark & o_mark );

/**
 * @brief  Invokes the set mark store hardware procedure.
 * @param  i_mba               Target MBA.
 * @param  i_rank              Target rank.
 * @param  i_mark              The mark to write.
 * @param  o_writeBlocked      TRUE if a blocke write is allowed and hardware
 *                             blocked the write to markstore.
 * @param  i_allowWriteBlocked TRUE if a blocked write is allowed. This means
 *                             the user will need to read what hardware just
 *                             placed in the markstore and retry. If FALSE and
 *                             the write was blocked, this function will commit
 *                             the FAPI error log and return a non-SUCCESS. The
 *                             default value is FALSE.
 * @note   Both the chip mark and the symbol mark will be written at the same
 *         time, so do a RMW operation to avoid overwritting a previous mark.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssSetMarkStore( TARGETING::TargetHandle_t i_mba,
                         const CenRank & i_rank, const CenMark & i_mark,
                         bool & o_writeBlocked,
                         bool i_allowWriteBlocked = false );

/**
 * @brief  Invokes the get steer mux hardware procedure.
 * @param  i_mba        Target MBA.
 * @param  i_rank       Target rank.
 * @param  o_port0Spare A symbol associated with the spare on port 0.
 * @param  o_port1Spare A symbol associated with the spare on port 1.
 * @param  o_eccSpare   A symbol associated with the ECC spare (x4 mode only).
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssGetSteerMux( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        CenSymbol & o_port0Spare, CenSymbol & o_port1Spare,
                        CenSymbol & o_eccSpare );

/**
 * @brief  Invokes the set steer mux hardware procedure.
 * @param  i_mba        Target MBA.
 * @param  i_rank       Target rank.
 * @param  i_symbol     A symbol associated with the DRAM to be spared.
 * @param  i_x4EccSpare If true, will set ECC spare instead (x4 mode only).
 * @note   The procedure will be able to derive the port from the given symbol.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssSetSteerMux( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        const CenSymbol & i_symbol, bool i_x4EccSpare );

/**
 * @brief  Returns the start and end maintenance address of the given MBA.
 * @param  i_mba       Target MBA.
 * @param  o_startAddr The return start address.
 * @param  o_endAddr   The return end address.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t getMemAddrRange( TARGETING::TargetHandle_t i_mba, CenAddr & o_startAddr,
                         CenAddr & o_endAddr );

/**
 * @brief  Returns the start and end maintenance address of the given rank.
 * @param  i_mba       Target MBA.
 * @param  i_rank      Target rank.
 * @param  o_startAddr The return start address.
 * @param  o_endAddr   The return end address.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t getMemAddrRange( TARGETING::TargetHandle_t i_mba,
                         const CenRank & i_rank, CenAddr & o_startAddr,
                         CenAddr & o_endAddr );

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
 * @brief This is a wrapper class for underlying maintenance class object
 *
 * By this class, we will hide underlying maintenance class dependency
 * from rest of code. All public function mss_MaintCmd used by prd should
 * be defined here also.
 */

class mss_MaintCmdWrapper
{
  public: // data types

    /** Represents underlying maintenance command object type **/
    enum CmdType
    {
        TIMEBASE_SCRUB,
        TIMEBASE_STEER_CLEANUP,
        SUPERFAST_READ,
    };

  public: // functions

    /**
     * @brief Constructor
     *
     * @param i_maintCmd Underlying maintenance command object
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

    // Underlying maintenance command object pointer
    mss_MaintCmd * iv_cmd;

}; // class mss_MaintCmdWrapper

/**
 * @brief  Create a maintenance command object that will run on all memory
 *         behind this MBA.
 * @param  i_cmdType     Maintenance command type which we want to create.
 * @param  i_mba         An MBA target.
 * @param  i_stopCond    Bit mask for conditions in which to stop command.
 * @param  i_isFastSpeed false = slow (12 H), true = fast (default).
 * @return A mss_MaintCmdWrapper object, NULL if an internal function failed.
 * @note   This function allocates memory on heap for mss_MaintCmdWrapper
 *         object. It is the caller's responsibilty to delete this object.
 * @note   i_isFastSpeed will be ignored for super fast commands.
 */
mss_MaintCmdWrapper * createMssCmd( mss_MaintCmdWrapper::CmdType i_cmdType,
                                    TARGETING::TargetHandle_t i_mba,
                                    uint32_t i_stopCond,
                                    bool i_isFastSpeed = true );

/**
 * @brief  Create a maintenance command object that will run on all memory
 *         behind the given rank.
 * @param  i_cmdType     Maintenance command type which we want to create.
 * @param  i_rank        The target rank.
 * @param  i_mba         An MBA target.
 * @param  i_stopCond    Bit mask for conditions in which to stop command.
 * @param  i_isFastSpeed false = slow (12 H), true = fast (default).
 * @return A mss_MaintCmdWrapper object, NULL if an internal function failed.
 * @note   This function allocates memory on heap for mss_MaintCmdWrapper
 *         object. It is the caller's responsibilty to delete this object.
 * @note   i_isFastSpeed will be ignored for super fast commands.
 */
mss_MaintCmdWrapper * createMssCmd( mss_MaintCmdWrapper::CmdType i_cmdType,
                                    TARGETING::TargetHandle_t i_mba,
                                    const CenRank & i_rank, uint32_t i_stopCond,
                                    bool i_isFastSpeed = true );

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_COMMON_H

