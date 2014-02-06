/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfTargetServices.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

//------------------------------------------------------------------------------

namespace PRDF
{

class CenRank;

enum PositionBounds
{
    MAX_NODE_PER_SYS    = 8,

    MAX_PROC_PER_NODE   = 8,

    MAX_EX_PER_PROC     = 16,
    MAX_CORE_PER_PROC   = MAX_EX_PER_PROC,
    MAX_L2_PER_PROC     = MAX_EX_PER_PROC,
    MAX_L3_PER_PROC     = MAX_EX_PER_PROC,

    MAX_XBUS_PER_PROC   = 4,
    MAX_ABUS_PER_PROC   = 3,
    MAX_PHB_PER_PROC    = 3,

    MAX_MCS_PER_PROC    = 8,
    MAX_MEMBUF_PER_PROC = MAX_MCS_PER_PROC,

    MAX_MBA_PER_MEMBUF  = 2,
    MAX_PORT_PER_MBA    = 2,
    MAX_DIMM_PER_PORT   = 2,
    MAX_L4_PER_MEMBUF   = 1,

    INVALID_POSITION_BOUND = 0xffffffff,
};

namespace PlatServices
{

//##############################################################################
//##
//##                 Target Manipulation Utility Functions
//##
//##############################################################################

/**
 * @brief   Returns the target for a given HUID.
 * @param   i_huid The HUID of a target.
 * @return  The target for the given HUID.
 * @post    Must check that the returned target is not NULL.
 */
TARGETING::TargetHandle_t getTarget( HUID i_huid );

/**
 * @brief   Returns the target for a given entity path.
 * @param   i_path The entity path of a target.
 * @return  The target for the given entity path.
 * @post    Must check that the returned target is not NULL.
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
 * @brief   Prints the HUID and dumps the entity path of the given target.
 * @param   i_target Any target.
 */
void printTargetInfo( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Get the chip level (DD level) of this target.
 * @param   i_target Any chip or unit target.
 * @return  The chip level or 0 function failed.
 */
uint8_t getChipLevel( TARGETING::TargetHandle_t i_target );

/**
 * @brief set hw changed state for a target
 *
 * @param i_target target handle
 *
 */
void setHWStateChanged(TARGETING::TargetHandle_t i_target);

/**
 * @brief   Get the chip ID (P7, P7+, etc.) of this target.
 * @param   i_target Any chip or unit target.
 * @return  The chip ID or 0 function failed.
 */
//TODO: See .C
//uint32_t getChipId( TARGETING::TargetHandle_t i_target );

//##############################################################################
//##
//##                       getConnected() support functions
//##
//##############################################################################

/**
 * @brief   Returns a list of functional targets of a given type that is
 *          associated with the given target.
 * @param   i_target    The given target.
 * @param   i_connType  Type of target(s) return in list
 * @return  The connected list of targets. On error, the list will be empty.
 * @note    If the given target is the same type as the given type, only the
 *          given target is returned in the list.
 * @note    This function does not support peer-to-peer connections.
 */
TARGETING::TargetHandleList getConnected( TARGETING::TargetHandle_t i_target,
                                          TARGETING::TYPE i_connType );

/**
 * @brief   Returns a functional parent target of a given type.
 * @param   i_target    The given target.
 * @param   i_connType  Type of target(s) return in list
 * @note    If the given target is the same type as the given type, the given
 *          target is returned.
 * @return  The requested parent target, NULL if something failed.
 */
TARGETING::TargetHandle_t getConnectedParent(TARGETING::TargetHandle_t i_target,
                                             TARGETING::TYPE i_connType );

/**
 * @brief   Returns a functional child target of a given type and position.
 * @param   i_target    The given target.
 * @param   i_connType  Type of target(s) return in list
 * @param   i_position  Target position index
 * @return  The requested child target, NULL if target not found.
 */
TARGETING::TargetHandle_t getConnectedChild( TARGETING::TargetHandle_t i_target,
                                             TARGETING::TYPE i_connType,
                                             uint32_t i_position );

/**
 * @brief   Returns the target of a PROC that is connected via the given
 *          target's XBUS or ABUS.
 * @param   i_procTarget Target of TYPE_PROC.
 * @param   i_busType    Bus type of TYPE_XBUS or TYPE_ABUS.
 * @param   i_busPos     Position of bus (XBUS: 0-3, ABUS: 0-2).
 * @return  The connected PROC target. On error, the target will be NULL.
 */
TARGETING::TargetHandle_t getConnectedPeerProc(
                                         TARGETING::TargetHandle_t i_procTarget,
                                         TARGETING::TYPE i_busType,
                                         uint32_t i_busPos );

/**
 * @brief   Returns the connected peer target using ATTR_PEER_TARGET
 * @param   i_tgt Source target
 * @return  Connected peer target, or NULL
 * @note    Only works if ATTR_PEER_TARGET is defined.
 *          Currently only X and A bus targets.
 */
TARGETING::TargetHandle_t getConnectedPeerTarget(
                                  TARGETING::TargetHandle_t i_tgt);

/**
 * @brief   Returns the system target.
 * @return  The system target.
 */
TARGETING::TargetHandle_t getSystemTarget();

/**
 * @brief   Get container chip target for the given target.
 * @param   i_target Any chip or unit target.
 * @return  The container chip target.
 * @post    Must check that the returned target is not NULL.
 */
TARGETING::TargetHandle_t getParentChip( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Returns the list of functional targets of a given type.
 * @param   i_type Type of target requested.
 * @return  The list of functional targets.
 */
TARGETING::TargetHandleList getFunctionalTargetList( TARGETING::TYPE i_type );

/**
 * @brief   Determines if the given target is the last functional core.
 * @param   i_coreTarget A core target.
 * @return  TRUE if target is last functional core, FALSE otherwise.
 */
bool checkLastFuncCore( TARGETING::TargetHandle_t i_coreTarget );

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
 * @brief   Returns the position of a node in which the given target is
 *          contained.
 * @param   i_target Any target.
 * @return  The position of the connected node.
 */
uint32_t getNodePosition( TARGETING::TargetHandle_t i_target );

/**
 * @brief   Returns Model associated with Proc.
 *          Model expected is either MURANO or VENICE.
 * @param   i_proc a proc target
 * @return  proc model if target is valid else MODEL_NA
 */
TARGETING::MODEL getProcModel( TARGETING::TargetHandle_t i_proc );

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
 * @brief   Returns the list of configured master ranks for an MBA.
 * @param   i_memTrgt MBA target or child of MBA.
 * @param   o_ranks   The returned list.
 * @return  Non-SUCCESS if internal functions fail, SUCCESS otherwise.
 */
int32_t getMasterRanks( TARGETING::TargetHandle_t i_memTrgt,
                        std::vector<CenRank> & o_ranks );

/**
 * @brief   Returns the DMI bus channel for the given memory target.
 * @param   i_memTarget MCS target or child of MCS.
 * @return  The DMI bus channel.
 * @note    Can check against MAX_MCS_PER_PROC for validity.
 */
uint32_t getMemChnl( TARGETING::TargetHandle_t i_memTarget );

/**
 * @brief   Determines if a given target is associated with a memory buffer that
 *          is located on the DIMM card.
 * @param   i_target Any memory target or parent or a mba
 * @param   o_memBuf true if associated MBA is non IS MBA
 * @return  FAIL if internal function fails. Success otherwise
 */
int32_t isMembufOnDimm( TARGETING::TargetHandle_t i_memTarget, bool &o_memBuf);

/**
 * @brief   Obtain the MBA port select for the given Dimm.
 * @param   i_dimmTarget Dimm.
 * @param   o_port MBA port select.
 * @return  Non-SUCCESS if internal functions fail, SUCCESS otherwise.
 */
int32_t getMbaPort( TARGETING::TargetHandle_t i_dimmTarget, uint8_t & o_port );


/**
 * @brief   Obtain the MBA Dimm select for the given Dimm.
 * @param   i_dimmTarget Dimm.
 * @param   o_dimm MBA Dimm select.
 * @return  Non-SUCCESS if internal functions fail, SUCCESS otherwise.
 */
int32_t getMbaDimm( TARGETING::TargetHandle_t i_dimmTarget, uint8_t & o_dimm );


/**
 * @brief   checks dram widh ( x4 ) for mba
 * @param   i_mbaTarget MBA target
 * @return  true if DRAM with is X4 false otherwise
 */
bool isDramWidthX4(TARGETING::TargetHandle_t i_mbaTarget);

/**
 * @brief   Obtains number of ranks (including slave ranks) per DIMM select.
 * @param   i_mbaTarget MBA target.
 * @param   i_ds        DIMM select for DIMM.
 * @return  Number of ranks confgured per DIMM select. If internal function
 *          fails it will return 0.
 */
uint8_t getRanksPerDimm( TARGETING::TargetHandle_t i_mbaTarget, uint8_t i_ds );

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

//##############################################################################
//##
//##                        Clock specific functions
//##
//##############################################################################

/**
 * @brief   Gets handle of the clock card for the given target.
 * @param   i_pTargetHandle    Handle of a functional unit.
 * @param   i_peerType         Type of peer clock source
 * @return  Handle_t of clock source.
 * @pre     None.
 * @post    None.
 */
TARGETING::TargetHandle_t getClockId(TARGETING::TargetHandle_t
                             i_pTargetHandle,
                             TARGETING::TYPE i_peerType);

//##############################################################################
//##                     MNFG Policy Flag Functions
//##############################################################################

/**
 * @brief   Returns the state of the MNFG_THRESHOLDS policy flag.
 * @return  TRUE if MNFG_THRESHOLDS is set, FALSE otherwise.
 */
bool mfgMode();

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
 *         MNFG_FLAG_BIT_MNFG_TEST_DRAM_REPAIRS policy flag.
 * @return TRUE if flag is set, FALSE otherwise.
 */
bool mnfgSpareDramDeploy();

/**
 * @brief  Returns the state of the MNFG_IPL_MEMORY_CE_CHECKING policy flag.
 * @return TRUE if MNFG_IPL_MEMORY_CE_CHECKING is set, FALSE otherwise.
 */
bool isMfgCeCheckingEnabled();

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFTARGETSERVICES_H

