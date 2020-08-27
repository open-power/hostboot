/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPlatServices_common.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
//##                        Fabric/Memory bus functions
//##############################################################################

/**
 * @brief Adds both endpoints to the callout list (priority medium group A) and
 *        calls out everything else in between (priority low).
 * @param io_sc     The step code data struct.
 * @param i_rxTrgt  The RX endpoint target.
 * @param i_txTrgt  The TX endpoint target.
 * @param i_busType The hardware bus type
 * @param i_flags   Extra flag for callout structure.
 */
void calloutBus(STEP_CODE_DATA_STRUCT& io_sc,
                TARGETING::TargetHandle_t i_rxTrgt,
                TARGETING::TargetHandle_t i_txTrgt,
                HWAS::busTypeEnum i_busType,
                HWAS::CalloutFlag_t i_flags = HWAS::FLAG_NONE);

/**
 * @brief Adds the OpenCAPI adapter attached to the given IOHS link to the
 *        callout list.
 * @param i_chip IOHS processor unit.
 * @param i_link IOHS link.
 * @param io_sc  The step code data struct.
 */
void calloutOpenCapiAdapter(ExtensibleChip* i_chip, unsigned int i_link,
                            STEP_CODE_DATA_STRUCT& io_sc);

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Reads the bad DQ bitmap attribute for both ports of the target rank.
 * @param  i_trgt        An OCMB_CHIP target.
 * @param  i_rank        Target rank.
 * @param  o_bitmap      DQ bitmap container.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t getBadDqBitmap( TARGETING::TargetHandle_t i_trgt,
                         const MemRank & i_rank, MemDqBitmap & o_bitmap );

/**
 * @brief  Writes the bad DQ bitmap attribute for both ports of the target rank.
 * @param  i_trgt   An OCMB_CHIP target.
 * @param  i_rank   Target rank.
 * @param  i_bitmap DQ bitmap container.
 * @note   This is a no-op if DRAM Repairs are disabled in manufacturing.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t setBadDqBitmap( TARGETING::TargetHandle_t i_trgt,
                         const MemRank & i_rank,
                         const MemDqBitmap & i_bitmap );

/**
 * @brief  Clears the bad DQ bitmap attribute for all ports of the target rank.
 * @param  i_trgt   An OCMB_CHIP target.
 * @param  i_rank   Target rank.
 * @note   This is a no-op if DRAM Repairs are disabled in manufacturing.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t clearBadDqBitmap( TARGETING::TargetHandle_t i_trgt,
                           const MemRank & i_rank );

/**
 * @brief  Invokes the get steer mux hardware procedure.
 * @param  i_trgt       Target OCMB
 * @param  i_rank       Target rank.
 * @param  o_port0Spare A symbol associated with the spare on port 0.
 * @param  o_port1Spare A symbol associated with the spare on port 1.
 * @param  o_eccSpare   A symbol associated with the ECC spare (x4 mode only).
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t mssGetSteerMux( TARGETING::TargetHandle_t i_trgt,
                        const MemRank & i_rank, MemSymbol & o_port0Spare,
                        MemSymbol & o_port1Spare, MemSymbol & o_eccSpare );

/**
 * @brief  Invokes the set steer mux hardware procedure.
 * @param  i_trgt       Target OCMB
 * @param  i_rank       Target rank.
 * @param  i_symbol     A symbol associated with the DRAM to be spared.
 * @param  i_x4EccSpare If true, will set ECC spare instead (x4 mode only).
 * @note   The procedure will be able to derive the port from the given symbol.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t mssSetSteerMux( TARGETING::TargetHandle_t i_trgt,
                        const MemRank & i_rank, const MemSymbol & i_symbol,
                        bool i_x4EccSpare );

/**
 * @brief   Get spare DRAM information on a DIMM.
 * @param   i_trgt MEM_PORT/OCMB target.
 * @param   i_rank Rank.
 * @param   i_ps port select.
 * @param   o_spareConfig Spare DRAM config information.
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 * @note    On a DIMM its possible that spare is not present. Also on X4 DRAM
 *          spare can be on High nibble or low nibble. This function will
 *          populate spare config information in o_spareConfig.
 */
template<TARGETING::TYPE T>
int32_t getDimmSpareConfig( TARGETING::TargetHandle_t i_trgt, MemRank i_rank,
                            uint8_t i_ps, uint8_t & o_spareConfig );

/**
 * @brief Checks if DRAM sparing is enabled.
 * @param i_trgt        MEM_PORT
 * @param i_rank        Target rank
 * @param i_ps          Port select
 * @param o_spareEnable Whether DRAM sparing is enabled or not.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t isDramSparingEnabled( TARGETING::TargetHandle_t i_trgt, MemRank i_rank,
                               uint8_t i_ps, bool & o_spareEnable );

/**
 * @brief Checks to see if the spares are available on given target and port.
 * @param i_trgt     Target MEM_PORT
 * @param i_rank     Target rank
 * @param i_ps       Port select
 * @param o_spAvail  If the spare on inputted port select is available
 * @param o_eccAvail If the ecc spare is available
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t isSpareAvailable( TARGETING::TargetHandle_t i_trgt, MemRank i_rank,
                           uint8_t i_ps, bool & o_spAvail, bool & o_eccAvail );

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
 * @param   i_chip     Extensible chip
 * @param   i_wordAddr FSI word address. Note that Hostboot implementation will
 *                     convert this to a byte address.
 * @param   o_data     returned data
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getCfam( ExtensibleChip * i_chip,
                 const uint16_t i_wordAddr,
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

