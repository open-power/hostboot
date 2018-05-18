/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPlatServices_common.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
#include <prdfMemConst.H>
#include <prdfTimer.H>
#include <prdfParserEnums.H>
#include <prdfMemSymbol.H>
#include <prdfMemDqBitmap.H>

#include <plat_hwp_invoker.H>

#include <errlentry.H>

//------------------------------------------------------------------------------

namespace PRDF
{

class CenAddr;
enum DIMMS_PER_RANK : uint8_t;
template <DIMMS_PER_RANK T>
class MemDqBitmap;
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
 * @brief Get a PRD timer value based on the current time.
 * @param o_timer The returned Timer
 */
void getCurrentTime( Timer & o_timer );

/**
 * @brief Sleep for given time (seconds plus milliseconds).
 * @param i_seconds      Sleep time in seconds.
 * @param i_milliseconds Sleep time in milliseconds.
 */
void milliSleep( uint32_t i_seconds, uint32_t i_milliseconds );

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

/**
 * @brief Initiate hwudump.
 * @param i_target target handle.
 * @param i_errl   error handle
 * @param i_errlActions error action flags
 */
/* TODO RTC 144705
void initiateUnitDump( TARGETING::TargetHandle_t i_target,
                       errlHndl_t i_errl,
                       uint32_t i_errlActions);
*/

/**
 * @return True, if this system is using an FSP. False, otherwise (i.e. BMC
 *         based system or SP-less machine).
 */
bool isSpConfigFsp();

//##############################################################################
//##                       Processor specific functions
//##############################################################################

/**
 * @brief capture SBE image failure Registers for FFDC
 * @param i_procTarget Processor target
 */
/* TODO RTC 136050
void collectSBE_FFDC(TARGETING::TargetHandle_t i_procTarget);
*/

//##############################################################################
//##                       Lane Repair functions
//##############################################################################

/**
 * @brief   Calls HWP to read newly failed bus lanes
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   o_rxFailLanes Vector of failed lanes
 * @param   i_clkGrp      Clock group
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t readErepairXbus(TARGETING::TargetHandle_t i_rxBusTgt,
                        std::vector<uint8_t> &o_rxFailLanes,
                        uint8_t i_clkGrp);

/**
 * @brief   Calls HWP to clear FIRs after a lane repair event
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   i_clkGrp      Clock group
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t clearIOFirsXbus(TARGETING::TargetHandle_t i_rxBusTgt);

/**
 * @brief   Calls HWP to power down failed lanes
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   i_rxFailLanes Vector of  rx failed lanes
 * @param   i_txFailLanes Vector of  tx failed lanes
 * @param   i_clkGrp      Clock group
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t powerDownLanesXbus(TARGETING::TargetHandle_t i_rxBusTgt,
                           const std::vector<uint8_t> &i_rxFailLanes,
                           const std::vector<uint8_t> &i_txFailLanes,
                           uint8_t i_clkGrp);

/**
 * @brief   Calls erepair accessor procedure get failed lanes from VPD
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   o_rxFailLanes Vector of  rx failed lanes
 * @param   o_txFailLanes Vector of  tx failed lanes
 * @param   i_clkGrp      Clock group
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getVpdFailedLanesXbus(TARGETING::TargetHandle_t i_rxBusTgt,
                              std::vector<uint8_t> &o_rxFailLanes,
                              std::vector<uint8_t> &o_txFailLanes,
                              uint8_t i_clkGrp);

/**
 * @brief   Calls erepair prcd to set failed lanes in vpd and check threshold
 * @param   i_rxBusTgt    Target of the receiving end of the bus
 * @param   i_txBusTgt    Target of the tranmitting end of the bus
 * @param   i_rxFailLanes Vector of  rx failed lanes
 * @param   o_thrExceeded True if these failed lanes exceeded erepair threshold
 * @param   i_clkGrp      Clock group
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setVpdFailedLanesXbus(TARGETING::TargetHandle_t i_rxBusTgt,
                              TARGETING::TargetHandle_t i_txBusTgt,
                              std::vector<uint8_t> &i_rxFailLanes,
                              bool & o_thrExceeded,
                              uint8_t i_clkGrp);

/**
 * @brief Checks if OBUS target is configured in SMP (ABUS) mode
 * @param obusTgt OBUS target to check
 * @return true if SMP mode
 */
bool obusInSmpMode(TARGETING::TargetHandle_t obusTgt);

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Reads the bad DQ bitmap attribute for both ports of the target rank.
 * @param  i_trgt        A MCA/MBA target.
 * @param  i_rank        Target rank.
 * @param  o_bitmap      DQ bitmap container.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template <DIMMS_PER_RANK T>
int32_t getBadDqBitmap( TARGETING::TargetHandle_t i_trgt,
                        const MemRank & i_rank, MemDqBitmap<T> & o_bitmap );

/**
 * @brief  Writes the bad DQ bitmap attribute for both ports of the target rank.
 * @param  i_trgt   A MCA/MBA target.
 * @param  i_rank   Target rank.
 * @param  i_bitmap DQ bitmap container.
 * @note   This is a no-op if DRAM Repairs are disabled in manufacturing.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template <DIMMS_PER_RANK T>
int32_t setBadDqBitmap( TARGETING::TargetHandle_t i_trgt,
                        const MemRank & i_rank,
                        const MemDqBitmap<T> & i_bitmap );

/**
 * @brief  Invokes the get mark store hardware procedure.
 * @param  i_mba  Target MBA.
 * @param  i_rank Target rank.
 * @param  o_mark The returned mark.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
/* TODO RTC 157888
int32_t mssGetMarkStore( TARGETING::TargetHandle_t i_mba,
                         const CenRank & i_rank, CenMark & o_mark );
*/

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
/* TODO RTC 157888
int32_t mssSetMarkStore( TARGETING::TargetHandle_t i_mba,
                         const CenRank & i_rank, CenMark & io_mark,
                         bool & o_writeBlocked,
                         bool i_allowWriteBlocked = false );
*/

/**
 * @brief  Invokes the get steer mux hardware procedure.
 * @param  i_mba        Target MBA.
 * @param  i_rank       Target rank.
 * @param  o_port0Spare A symbol associated with the spare on port 0.
 * @param  o_port1Spare A symbol associated with the spare on port 1.
 * @param  o_eccSpare   A symbol associated with the ECC spare (x4 mode only).
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
/* TODO RTC 157888
int32_t mssGetSteerMux( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        CenSymbol & o_port0Spare, CenSymbol & o_port1Spare,
                        CenSymbol & o_eccSpare );
*/

/**
 * @brief  Invokes the set steer mux hardware procedure.
 * @param  i_mba        Target MBA.
 * @param  i_rank       Target rank.
 * @param  i_symbol     A symbol associated with the DRAM to be spared.
 * @param  i_x4EccSpare If true, will set ECC spare instead (x4 mode only).
 * @note   The procedure will be able to derive the port from the given symbol.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
/* TODO RTC 157888
int32_t mssSetSteerMux( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        const CenSymbol & i_symbol, bool i_x4EccSpare );
*/

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
/* TODO RTC 157888
int32_t getDimmSpareConfig( TARGETING::TargetHandle_t i_mba, CenRank i_rank,
                            uint8_t i_ps, uint8_t & o_spareConfig );
*/

/**
 * @brief  Returns the raw card type of a buffered DIMM.
 * @param  i_mbaTarget  An MBA target. This MBA must be on a buffered DIMM.
 * @param  o_wiringType The DIMM's raw card type. Will return WIRING_INVALID if
 *                      the raw card type currently is not supported.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getMemBufRawCardType( TARGETING::TargetHandle_t i_mbaTarget,
                              CEN_SYMBOL::WiringType & o_wiringType );


/**
 * @brief   get DIMM DQ map from FAPI routines
 * @param   i_target      DIMM target
 * @param   io_dqMapPtr   Pointer to area to receive DIMM DQ map (80 bytes)
 * @return  Non-Null if error log occurs
 */
template <TARGETING::TYPE>
void getDimmDqAttr( TARGETING::TargetHandle_t i_target,
                    uint8_t (&io_dqMapPtr)[DQS_PER_DIMM] );

//##############################################################################
//##                        util functions
//##############################################################################


/**
 * @brief   get cfam data
 * @param   i_chip   Extensible chip
 * @param   i_addr   address
 * @param   o_data   returned data
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getCfam( ExtensibleChip * i_chip,
                 const uint32_t i_addr,
                 uint32_t & o_data);

/**
 * @brief   get sysref clk target for the given proc target.
 * @param   i_procTarget  proc target.
 * @param   i_peerType    Type of peer clock source
 * @param   i_oscPos      OSC position (0 or 1)
 * @return  Handle_t of systemref clock target.
 */
TARGETING::TargetHandle_t getActiveRefClk(
                            TARGETING::TargetHandle_t i_procTarget,
                            TARGETING::TYPE i_connType);


/**
 * @brief   Add callouts and FFDC for Deadman timer
 * @param   i_target      target for processor chip
 * @param   io_sc         service data structure
 * @return  Nothing.
 */
void deadmanTimerFFDC( TARGETING::TargetHandle_t  i_target,
                       STEP_CODE_DATA_STRUCT & io_sc );

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_COMMON_H

