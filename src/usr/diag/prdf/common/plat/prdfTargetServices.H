/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfTargetServices.H $          */
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

#ifndef PRDFTARGETSERVICES_H
#define PRDFTARGETSERVICES_H

/**
 * @file  prdfTargetServices.H
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file should only contain targeting external interfaces, which are
 * strictly common between FSP and Hostboot. All other interfaces should be in
 * prdfPlatServices.H.
 *
 * Also, this file should not be included directly. Instead, include
 * prdfPlatServices.H, which includes this file.
 */

#include <iipconst.h>
#include <targeting/common/target.H>
#include <prdfParserEnums.H>

#ifdef __HOSTBOOT_MODULE
  #include <chipids.H>
#endif

//------------------------------------------------------------------------------

namespace PRDF
{

class ExtensibleChip;
class MemRank;
struct STEP_CODE_DATA_STRUCT;

typedef std::vector<ExtensibleChip *> ExtensibleChipList;

namespace PlatServices
{

//##############################################################################
//##
//##                     System Level Utility Functions
//##
//##############################################################################

/** @return TRUE if this system is, or will be, using PHYP. FALSE otherwise. */
bool isHyprConfigPhyp();

/** @return TRUE if this system is, or will be, using OPAL. FALSE otherwise. */
bool isHyprConfigOpal();

/** @return TRUE if the hypervisor is running. FALSE otherwise. */
bool isHyprRunning();

/** @return TRUE if this system has redundant clocks. FALSE otherwise.*/
bool hasRedundantClocks();

//##############################################################################
//##
//##                 Target Manipulation Utility Functions
//##
//##############################################################################

/**
 * @brief   Returns the target for a given HUID.
 * @param   i_huid The HUID of a target.
 * @return  The target for the given HUID.
 * @post    Must check that the returned target is not nullptr.
 */
TARGETING::TargetHandle_t getTarget( HUID i_huid );

/**
 * @brief   Returns the target for a given entity path.
 * @param   i_path The entity path of a target.
 * @return  The target for the given entity path.
 * @post    Must check that the returned target is not nullptr.
 */
TARGETING::TargetHandle_t getTarget( const TARGETING::EntityPath & i_path );

/**
 * @brief   Returns the entity path for a given target.
 * @param   i_target   A target.
 * @param   o_path     The returned path.
 * @param   i_pathType The desired path type, optional.
 * @return  Non-SUCCESS if internal functions fail, SUCCESS otherwise.
 * @note    Will use the path type specified the EntityPath contructor unless
 *          a supported PATH_TYPE is given.
 */
int32_t getEntityPath( TARGETING::TargetHandle_t i_target,
                       TARGETING::EntityPath & o_path,
                       TARGETING::EntityPath::PATH_TYPE i_pathType
                                            = TARGETING::EntityPath::PATH_NA );

/**
 * @brief   Returns the HUID for a given target.
 * @param   i_target A target.
 * @return  The HUID for the given target.
 * @post    Must check that the returned target is not INVALID_HUID.
 */
HUID getHuid( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Query functional state of a target.
 * @param   i_target Any target.
 * @return  TRUE if target is functional, FALSE otherwise.
 */
bool isFunctional( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Returns the type of the given target.
 * @param   i_target Any target.
 * @return  The type for the given target.
 */
TARGETING::TYPE getTargetType( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Returns the class of the given target.
 * @param   i_target Any target.
 * @return  The class for the given target.
 */
TARGETING::CLASS getTargetClass( TARGETING::TargetHandle_t i_target );

/**
 * @param  i_trgt A chip target or any unit target within the chip.
 * @return The model of a chip.
 */
TARGETING::MODEL getChipModel( TARGETING::TargetHandle_t i_trgt );

#ifdef __HOSTBOOT_MODULE

// NOTE: This should be used instead of getChipModel() because of the case of
//       MODEL_OCMB, where we need the chip ID to distinguish between Explorer
//       and Gemini.

/**
 * @param  i_trgt A chip target or any unit target within the chip.
 * @return The chip ID.
 */
uint32_t getChipId( TARGETING::TargetHandle_t i_trgt );

#endif

/**
 * @param  i_trgt A chip target or any unit target within the chip.
 * @return The level (EC level) of a chip.
 */
uint8_t getChipLevel( TARGETING::TargetHandle_t i_trgt );

//##############################################################################
//##
//##                         General Utility Functions
//##
//##############################################################################

/**
 * @brief   Gives the ability to link HWPs error logs with PRD error logs.
 *
 * During the IPL, a HWP may find a FIR attention that could cause the HWP to
 * fail. The HWP will create/commit an error log and write the PLID in
 * ATTR_PRD_HWP_PLID (all via FAPI interface). If PRD isolates to a target with
 * a non-zero ATTR_PRD_HWP_PLID, it will link the two error logs together, clear
 * the attribute, and override the thresholding to make the error log
 * predictive.
 *
 * @note    It is a requirement for the HWP to set the attribute on the same
 *          target as the active FIR attention.
 *
 * @param   i_chip Any chip.
 * @param   i_sc   Step code data struct.
 */
void hwpErrorIsolation( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc);

//##############################################################################
//##
//##                       getConnected() support functions
//##
//##############################################################################

/**
 * @brief   Returns a list of functional child targets of a given type that is
 *          associated with the given target.
 * @param   i_target    The given target.
 * @param   i_connType  Type of target(s) return in list
 * @return  The connected list of targets. On error, the list will be empty.
 */
TARGETING::TargetHandleList getConnectedChildren(
    TARGETING::TargetHandle_t i_target, TARGETING::TYPE i_connType );

/**
 * @brief   Returns a functional parent target of a given type.
 * @param   i_target    The given target.
 * @param   i_connType  Type of target(s) return in list
 * @note    If the given target is the same type as the given type, the given
 *          target is returned.
 * @note    This function will assert if no valid parent is found.
 * @return  The requested parent target.
 */
TARGETING::TargetHandle_t getConnectedParent(TARGETING::TargetHandle_t i_target,
                                             TARGETING::TYPE i_connType );

/**
 * @brief   Returns a functional child target of a given type and position.
 * @param   i_target    The given parent target.
 * @param   i_connType  Type of target(s) return in list
 * @param   i_position  Target position index
 * @return  The requested child target, nullptr if target not found.
 */
TARGETING::TargetHandle_t getConnectedChild( TARGETING::TargetHandle_t i_parent,
                                             TARGETING::TYPE i_childType,
                                             uint32_t i_childPos );

/**
 * @brief  ExtensibleChip wrapper for targeting version of getConnectedChildren.
 * @param  i_chip    The given chip.
 * @param  i_connType  Type of target(s) return in list
 * @return The connected list of chips. On error, the list will be empty.
 */
ExtensibleChipList getConnectedChildren( ExtensibleChip * i_chip,
                                         TARGETING::TYPE i_connType );

/**
 * @brief  ExtensibleChip wrapper for targeting version of getConnectedParent().
 * @param  i_child      The child ExtensibleChip.
 * @param  i_parentType The targeting type of the parent.
 * @note   If the child is the same type as the parent type, the child is
 *         returned.
 * @note   This function will assert if no valid parent is found.
 * @return The connected parent, nullptr if not found.
 */
ExtensibleChip * getConnectedParent( ExtensibleChip * i_child,
                                     TARGETING::TYPE i_parentType );

/**
 * @brief  ExtensibleChip wrapper for targeting version of getConnectedChild().
 * @param  i_parent    The parent ExtensibleChip.
 * @param  i_childType The targeting type of the child.
 * @param  i_childPos  The position of the child relative to the parent.
 * @note   If the parent is the same type as the child type, the parent is
 *         returned.
 * @return The connected child, nullptr if not found.
 */
ExtensibleChip * getConnectedChild( ExtensibleChip * i_parent,
                                    TARGETING::TYPE i_childType,
                                    uint32_t i_childPos );

/**
 * @brief Returns the fused-core neighbor of a given core chip
 * @param i_core  The given core chip
 * @return        The neighbor core chip
 */
ExtensibleChip * getNeighborCore( ExtensibleChip * i_core );

/**
 * @brief  Returns the PROC target connected via the given bus type and
 *         position.
 * @param  i_procTarget A PROC target.
 * @param  i_busType    The connected bus type.
 * @param  i_busPos     The position of the bus relative to the PROC.
 * @return The connected PROC target or nullptr on error.
 */
TARGETING::TargetHandle_t getConnectedPeerProc(
                                         TARGETING::TargetHandle_t i_procTarget,
                                         TARGETING::TYPE i_busType,
                                         uint32_t i_busPos);

/**
 * @brief  Returns the peer target connected to the given target.
 * @param  i_target The source target
 * @return The connected peer target or nullptr on error.
 * @note   This utilizes ATTR_PEER_TARGET, which must be defined for the given
 *         target.
 */
TARGETING::TargetHandle_t getConnectedPeerTarget(
                                  TARGETING::TargetHandle_t i_target);

/**
 * @param  i_trgt The target OCMB_CHIP or MEM_PORT.
 * @param  i_rank The target rank.
 * @return A list of DIMMs connected to the target and rank.
 */
TARGETING::TargetHandleList getConnectedDimms( TARGETING::TargetHandle_t i_trgt,
                                               const MemRank & i_rank );

/**
 * @param  i_trgt The target OCMB_CHIP or MEM_PORT.
 * @param  i_rank The target rank.
 * @param  i_port Port select
 * @return The DIMM connected to the target and rank on a port.
 */
TARGETING::TargetHandle_t getConnectedDimm( TARGETING::TargetHandle_t i_trgt,
                                            const MemRank & i_rank,
                                            uint8_t i_port = 0 );

/**
 * @brief   Returns the system target.
 * @return  The system target.
 */
TARGETING::TargetHandle_t getSystemTarget();

/**
 * @brief   Get container chip target for the given target.
 * @param   i_target Any chip or unit target.
 * @return  The container chip target.
 * @post    Must check that the returned target is not nullptr.
 */
TARGETING::TargetHandle_t getParentChip( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Returns the list of functional targets of a given type.
 * @param   i_type Type of target requested.
 * @return  The list of functional targets.
 */
TARGETING::TargetHandleList getFunctionalTargetList( TARGETING::TYPE i_type );

/**
 * @brief   Determines if the given target is the last functional CORE.
 * @param   i_trgt A CORE target.
 * @return  TRUE if target is last functional CORE, FALSE otherwise.
 */
bool checkLastFuncCore( TARGETING::TargetHandle_t i_trgt );

/** @return The master PROC target. nullptr on failure. */
TARGETING::TargetHandle_t getMasterProc();

//##############################################################################
//##
//##                       Target position support code
//##
//##############################################################################

/**
 * @brief   Returns the position of the given target.
 * @param   i_target Any target.
 * @return  The position or index of the given target relative to its container.
 *          Can compare against enums in PositionBounds for validity.
 */
uint32_t getTargetPosition( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Returns Phb Config associated with the Proc target.
 *          Config number indicates about slot bifurcation and
 *          associated PHB with the slot.
 * @param   i_proc Proc target
 * @return  PCI Config info as uin32_t. value expected is from [0-12].
 */
uint32_t getPhbConfig( TARGETING::TargetHandle_t i_proc );

//##############################################################################
//##
//##                        Memory specific functions
//##
//##############################################################################

/**
 * @brief   Determines if a given target is associated with a memory buffer that
 *          is located on the DIMM card (as opposed to IS DIMMs connected to the
 *          memory buffer).
 * @param   i_trgt MBA
 * @return  True if the DIMMs connected to this target have a memory buffer on
 *          the DIMM card. False otherwise.
 */
template<TARGETING::TYPE T>
bool isMembufOnDimm( TARGETING::TargetHandle_t i_trgt );

/**
 * @brief   Obtain the port select for the given Dimm.
 * @param   i_dimmTrgt Dimm.
 * @return  port select
 */
uint8_t getDimmPort( TARGETING::TargetHandle_t i_dimmTrgt );

/**
 * @brief   Obtain the Dimm select for the given Dimm.
 * @param   i_trgt Dimm.
 * @return  The DIMM select
 */
uint8_t getDimmSlct( TARGETING::TargetHandle_t i_trgt );

/**
 * @brief   checks dram width ( x4 )
 * @param   i_trgt DIMM target
 * @return  true if DRAM width is X4, false otherwise
 */
bool isDramWidthX4(TARGETING::TargetHandle_t i_trgt);

/**
 * @brief  Returns a sorted list of configured master ranks for an OCMB.
 * @param  i_trgt  OCMB_CHIP target.
 * @param  o_ranks The returned list.
 * @param  i_ds    When used, this function will only return the list of ranks
 *                 for the target DIMM select. Otherwise, the default is to
 *                 return the list for all DIMM selects.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 * @note   Will assert if the list is empty because the target should not be
 *         configured with no memory.
 */
template<TARGETING::TYPE T>
void getMasterRanks( TARGETING::TargetHandle_t i_trgt,
                     std::vector<MemRank> & o_ranks,
                     uint8_t i_ds = MAX_DIMM_PER_PORT );

/**
 * @brief  Returns a sorted list of configured slave ranks for an OCMB.
 * @param  i_trgt  OCMB_CHIP target.
 * @param  o_ranks The returned list.
 * @param  i_ds    When used, this function will only return the list of ranks
 *                 for the target DIMM select. Otherwise, the default is to
 *                 return the list for all DIMM selects.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 * @note   Will assert if the list is empty because the target should not be
 *         configured with no memory.
 */
template<TARGETING::TYPE T>
void getSlaveRanks( TARGETING::TargetHandle_t i_trgt,
                    std::vector<MemRank> & o_ranks,
                    uint8_t i_ds = MAX_DIMM_PER_PORT );

/**
 * @brief  Obtains the number of master ranks per DIMM select.
 * @param  i_trgt OCMB_CHIP target.
 * @param  i_ds   DIMM select.
 * @return Total number of master ranks configured per DIMM select.
 */
template<TARGETING::TYPE T>
uint8_t getNumMasterRanksPerDimm( TARGETING::TargetHandle_t i_trgt,
                                  uint8_t i_ds );

/**
 * @brief  Obtains the total number of ranks (including slave ranks) per DIMM
 *         select.
 * @param  i_trgt OCMB_CHIP target.
 * @param  i_ds   DIMM select.
 * @return Total number of ranks configured per DIMM select.
 */
template<TARGETING::TYPE T>
uint8_t getNumRanksPerDimm( TARGETING::TargetHandle_t i_trgt, uint8_t i_ds );

//##############################################################################
//##
//##                        Clock specific functions
//##
//##############################################################################

/**
 * @brief   Gets handle of the clock card for the given target.
 * @param   i_pTargetHandle    Handle of a functional unit.
 * @param   i_peerType         Type of peer clock source
 * @param   i_oscPos           OSC position (0 or 1)
 * @return  Handle_t of clock source.
 * @pre     None.
 * @post    None.
 */
TARGETING::TargetHandle_t getClockId(TARGETING::TargetHandle_t
                             i_pTargetHandle,
                             TARGETING::TYPE i_peerType,
                             uint32_t i_oscPos);

//##############################################################################
//##                     MNFG Policy Flag Functions
//##############################################################################

/**
 * @brief   Returns the state of the MNFG_THRESHOLDS policy flag.
 * @return  TRUE if MNFG_THRESHOLDS is set, FALSE otherwise.
 */
bool mfgMode();

/**
 *  @brief  Returns status of MNFG_DISABLE_FABRIC_eREPAIR flag
 *  @return TRUE if MNFG_DISABLE_FABRIC_eREPAIR set, FALSE otherwise
 */
bool isFabeRepairDisabled();

/**
 * @brief  Returns status of MNFG_DISABLE_MEMORY_eREPAIR flag
 * @return TRUE if MNFG_DISABLE_MEMORY_eREPAIR set, FALSE otherwise
 */
bool isMemeRepairDisabled();

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

/**
 * @brief  Returns the state of the MNFG_FAST_BACKGROUND_SCRUB policy flag.
 * @return TRUE if MNFG_FAST_BACKGROUND_SCRUB is set, FALSE otherwise.
 */
bool enableFastBgScrub();

/**
 * @brief  Returns the state of the
 *         MNFG_FLAG_TEST_DRAM_REPAIRS policy flag.
 * @return TRUE if flag is set, FALSE otherwise.
 */
bool mnfgSpareDramDeploy();

/**
 * @brief  Returns the state of the MNFG_IPL_MEMORY_CE_CHECKING policy flag.
 * @return TRUE if MNFG_IPL_MEMORY_CE_CHECKING is set, FALSE otherwise.
 */
bool isMfgCeCheckingEnabled();

/** @return TRUE if MNFG_FLAG_AVP_ENABLE is set, FALSE otherwise.
 */
bool isMfgAvpEnabled();

/** @return TRUE if MNFG_FLAG_HDAT_AVP_ENABLE is set, FALSE otherwise. */
bool isMfgHdatAvpEnabled();

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFTARGETSERVICES_H

