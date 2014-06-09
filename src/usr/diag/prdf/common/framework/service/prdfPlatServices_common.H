/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfPlatServices_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#include <prdfParserEnums.H>

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
class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

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

/**
 * @brief Check if SMP is  cohenerent ( Node stitching complete).
 * @return true if SMP is coherent, false otherwise.
 */
bool isSmpCoherent();

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
 * @param  io_mark             The mark to write. If hardware blocks the write
 *                             to markstore and the block is allowed, io_mark
 *                             will be updated with the new chip mark set by
 *                             hardware.
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
                         const CenRank & i_rank, CenMark & io_mark,
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
 * @brief  Returns the start and end maintenance address of the given rank. By
 *         default, will return the address range of the master rank.
 * @param  i_mba       Target MBA.
 * @param  i_rank      Target rank.
 * @param  o_startAddr The return start address.
 * @param  o_endAddr   The return end address.
 * @param  i_slaveOnly true = slave rank only, false = master rank (default).
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t getMemAddrRange( TARGETING::TargetHandle_t i_mba,
                         const CenRank & i_rank, CenAddr & o_startAddr,
                         CenAddr & o_endAddr, bool i_slaveOnly = false );

/**
 * @brief   Returns master core for the master proc
 * @param   i_procTgt proc target
 * @return  target for master core or NULL
 * @note    if given proc is not master, master proc is found and target for
 *          master core is returned.
 */
TARGETING::TargetHandle_t getMasterCore( TARGETING::TargetHandle_t i_procTgt );

/**
 * @brief   Get spare DRAM information on a DIMM.
 * @param   i_mba MBA target.
 * @param   i_rank Rank.
 * @param   i_ps MBA port select.
 * @param   o_spareConfig Spare DRAM config information.
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 * @note    On a DIMM its possible that spare is not present. Also on X4 DRAM
 *          spare can be on High nibble or low nibble. This function will
 *          populate spare config information in o_spareConfig.
 */
int32_t getDimmSpareConfig( TARGETING::TargetHandle_t i_mba, CenRank i_rank,
                            uint8_t i_ps, uint8_t & o_spareConfig );

/**
 * @brief   Returns the memory buffer raw card type.
 * @param   i_mbaTarget     an MBA target.
 * @param   o_wiringType    Card Type/ Wiring type of DIMM
 * @return  SUCCESS for a valid card type, FAIL otherwise.
 */
int32_t getMemBufRawCardType( TARGETING::TargetHandle_t i_mbaTarget,
                              CEN_SYMBOL::WiringType & o_wiringType );

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

    /** Input flags to control how, and on what, the command runs. **/
    enum CtrlFlags
    {
        /** Run all defaults. See each individual flag of default behavior */
        NO_FLAGS        = 0x00,

        /** When set, the command will run from the beginning of the given rank
         *  to the end of memory. Default is to run to the end of the rank. */
        END_OF_MEMORY   = 0x01,

        /** When set, the command will run on the slave rank only. Default is to
         *  run on the entire master rank. */
        SLAVE_RANK_ONLY = 0x04,
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
 * @brief  Create a maintenance command object.
 * @param  i_cmdType       Maintenance command type which we want to create.
 * @param  i_mba           An MBA target.
 * @param  i_rank          The first rank to start with (see enum CtrlFlags for
 *                         more details).
 * @param  i_stopCond      Bit mask for conditions in which to stop command.
 * @param  i_cmdSpeed      See enum mss_MaintCmd::TimeBaseSpeed for details.
 * @param  i_flags         See enum CtrlFlags for details.
 * @param  i_sAddrOverride A non-NULL value indicates to use this start address
 *                         and not the start address of i_rank.
 * @return A mss_MaintCmdWrapper object, NULL if an internal function failed.
 * @note   This function allocates memory on heap for mss_MaintCmdWrapper
 *         object. It is the caller's responsibilty to delete this object.
 * @note   By default this maintenance command will operate on the address range
 *         that contains i_rank, but the target address range can be modified
 *         with i_flags and/or i_sAddrOverride.
 */
mss_MaintCmdWrapper * createMssCmd( mss_MaintCmdWrapper::CmdType i_cmdType,
                            TARGETING::TargetHandle_t i_mba,
                            const CenRank & i_rank, uint32_t i_stopCond,
                            mss_MaintCmd::TimeBaseSpeed i_cmdSpeed
                                            = mss_MaintCmd::FAST_MAX_BW_IMPACT,
                            uint32_t i_flags = mss_MaintCmdWrapper::NO_FLAGS,
                            const CenAddr * i_sAddrOverride = NULL );

//##############################################################################
//##                        util functions
//##############################################################################

/**
 * @brief   capture FSI Status Reg for FFDC
 * @param   i_chip   Extensible chip
 * @param   i_sc     service data collector
 */
void captureFsiStatusReg( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc );

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_COMMON_H

