/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPlatServices_common.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

#include <errlentry.H>
#include <hwas/common/hwasCallout.H>

#include <prdfTargetServices.H> // must include all common targeting code
#include <prdfMemConst.H>
#include <prdfTimer.H>
#include <prdfParserEnums.H>
#include <prdfMemSymbol.H>
#include <prdfMemDqBitmap.H>
#include <prdfCalloutMap.H>

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
//##                        Fabric/Memory bus functions
//##############################################################################

/**
 * @brief Adds both endpoints to the callout list (priority medium group A) and
 *        calls out everything else in between (priority low).
 * @param io_sc        The step code data struct.
 * @param i_rxTrgt     The RX endpoint target.
 * @param i_txTrgt     The TX endpoint target.
 * @param i_busType    The hardware bus type
 * @param i_flags      Extra flag for callout structure.
 * @param i_rxPriority Priority to callout i_rxTrgt
 * @param i_txPriority Priority to callout i_txTrgt
 * @param i_applyGuard True, guard. False, no guard.
 */
void calloutBus(STEP_CODE_DATA_STRUCT& io_sc,
                TARGETING::TargetHandle_t i_rxTrgt,
                TARGETING::TargetHandle_t i_txTrgt,
                HWAS::busTypeEnum i_busType,
                HWAS::CalloutFlag_t i_flags = HWAS::FLAG_NONE,
                PRDpriority i_rxPriority = MRU_MEDA,
                PRDpriority i_txPriority = MRU_MEDA,
                bool i_applyGuard = true);

/**
 * @brief  Calls out an entire SMPGROUP bus with the given link.
 * @param  i_chip An IOHS chip
 * @param  io_sc  The step code data struct.
 * @param  i_link Position of the connected SMPGROUP (0:1)
 * @return SUCCESS always.
 */
int32_t smp_callout( ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                     uint8_t i_link );

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
 * @param  i_trgt   Target OCMB
 * @param  i_rank   Target rank.
 * @param  o_spare0 A symbol associated with spare 0.
 * @param  o_spare1 A symbol associated with spare 1.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t mssGetSteerMux( TARGETING::TargetHandle_t i_trgt,
                        const MemRank & i_rank, MemSymbol & o_spare0,
                        MemSymbol & o_spare1 );

/**
 * @brief  Invokes the set steer mux hardware procedure.
 * @param  i_trgt       Target OCMB
 * @param  i_rank       Target rank.
 * @param  i_symbol     A symbol associated with the DRAM to be spared.
 * @note   The procedure will be able to derive the port from the given symbol.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t mssSetSteerMux( TARGETING::TargetHandle_t i_trgt,
                        const MemRank & i_rank, const MemSymbol & i_symbol );

/**
 * @brief  Invokes the undo steer mux hardware procedure.
 * @param  i_trgt       Target OCMB
 * @param  i_rank       Target rank.
 * @param  i_spare      spare number (0 or 1)
 * @note   The procedure will be able to derive the port from the given symbol.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t mssUndoSteerMux( TARGETING::TargetHandle_t i_trgt,
                         const MemRank & i_rank, const size_t i_spare );

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
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t isSpareAvailable( TARGETING::TargetHandle_t i_trgt, MemRank i_rank,
                           uint8_t i_ps, bool & o_spAvail );

/**
 * @brief   get DIMM DQ map from FAPI routines
 * @param   i_target      DIMM target
 * @param   io_dqMapPtr   Pointer to area to receive DIMM DQ map (80 bytes)
 * @return  Non-Null if error log occurs
 */
template <TARGETING::TYPE>
void getDimmDqAttr( TARGETING::TargetHandle_t i_target,
                    uint8_t (&io_dqMapPtr)[DQS_PER_DIMM] );

/**
 * @brief  Queries the ATTR_MEM_EFF_HYBRID and ATTR_MEM_EFF_HYBRID_MEMORY_TYPE
 *         attributes to determine if a DIMM is an MDS DDIMM.
 * @param  i_target Target MEM_PORT/OCMB.
 * @return True if the target is an MDS DDIMM, false otherwise.
 */
template<TARGETING::TYPE T>
bool isMdsDimm( TARGETING::TargetHandle_t i_target );

//##############################################################################
//##                         TOD functions
//##############################################################################

// FSP or HBRT only, not Hostboot
#if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)

/**
 * @brief   Retrieves a saved version of a TOD config register from HWSV.
 *          We use the saved value rather than the live version because this
 *          could have changed in response to the TOD fault we're currently
 *          analyzing.
 * @param   i_procTgt  Proc chip target
 * @param   i_slvPath0 Whether we need the register for slave path 0 or 1
 * @param   o_regValue Returns contents of the register
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t getTodPortControlReg ( const TARGETING::TargetHandle_t& i_procTgt,
                               bool i_slvPath0,  uint32_t &o_regValue );

#endif

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

