/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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

#ifndef PRDFPLATSERVICES_H
#define PRDFPLATSERVICES_H

/**
 * @file  prdfPlatServices.H
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

// This must be included after all Hostboot specific includes. This will take
// care of cases where a file must be included in the common code, but the
// include paths are different between FSP and Hostboot.
#include <prdfPlatServices_common.H>

// Must be included after including the common PlatServices code.
#ifdef __HOSTBOOT_RUNTIME
  #include <prdfPlatServices_rt.H>
#else
  #include <prdfPlatServices_ipl.H>
#endif

#include <prdfBitString.H>
#include <mem/prdfMemRank.H>

// External includes
#include <targeting/common/targetservice.H>
#include <gen_mss_mcbist_settings.H>

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

// Inline function definitions for Hostboot compiler optimization. See
// prdfPlatServices_common.H for the function declarations.

inline bool atRuntime()
{
    #ifdef __HOSTBOOT_RUNTIME
    return true;
    #else
    return false;
    #endif
}

inline bool isSmpCoherent() { return atRuntime(); }

/**
 * @brief Read data using SCOM
 *
 * @param i_target  Target to read from
 * @param io_bs     Bit string that holds data that is read in
 * @param i_address Address to read from
 *
 * @return SUCCESS or PRD_SCANCOM_FAILURE
 */
uint32_t getScom(TARGETING::TargetHandle_t i_target, BitString& io_bs,
                   uint64_t i_address);

/**
 * @brief Write data using SCOM
 *
 * @param i_target  Target to write data to
 * @param io_bs     Bit string that holds data to write
 * @param i_address Address to write data to
 *
 * @return SUCCESS or PRD_SCANCOM_FAILURE
 */
uint32_t putScom(TARGETING::TargetHandle_t i_target, BitString& io_bs,
                   uint64_t i_address);

//##############################################################################
//##                        Fabric/Memory bus functions
//##############################################################################

/**
 * @brief  In the event of a spare lane deploy on an SMP bus, this function will
 *         power down all of the spare lanes on the given link.
 * @param  i_chip  An IOHS chip.
 * @param  i_link  The IOLINK position relative to the given IOHS chip.
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
uint32_t powerDownSpareLanes(ExtensibleChip* i_chip, unsigned int i_link);

/**
 * @brief  In the event of a spare lane deploy on an SMP bus when the
 *         manufacturing thresholds policy is enabled, we want to run TDR on the
 *         half-link containing the spare. However, TDR can only be run on a
 *         failed link. So we'll have to force the link into half-bandwidth mode
 *         if it isn't already in that mode.
 * @param  i_chip  An IOHS chip.
 * @param  i_link  The IOLINK position relative to the given IOHS chip.
 */
void mnfgForceHalfBandwidthMode(ExtensibleChip* i_chip, unsigned int i_link);

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Returns the start and end address of the given rank.
 * @note   The end addresses returned from the MCBIST HWPs give a maximum
 *         possible address and do not take into account the actual configured
 *         address range. The MCBIST HW logic tolerates this unlike the MBA HW
 *         logic. Functions like Dynamic Memory Deallocation may need to adjust
 *         the actual address based on the actual HW config.
 * @param  i_chip      An OCMB.
 * @param  i_rank      The target rank.
 * @param  i_port      The target memory port.
 * @param  o_startAddr The returned start address.
 * @param  o_endAddr   The returned end address.
 * @param  i_rangeType See enum AddrRangeType.
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE TT, typename VT>
uint32_t getMemAddrRange( ExtensibleChip * i_chip, const MemRank & i_rank,
                          const uint8_t& i_port, VT & o_startAddr,
                          VT & o_endAddr, AddrRangeType i_rangeType );

/**
 * @brief  Returns the start and end address of the given rank.
 * @note   The end addresses returned from the MCBIST HWPs give a maximum
 *         possible address and do not take into account the actual configured
 *         address range. The MCBIST HW logic tolerates this unlike the MBA HW
 *         logic. Functions like Dynamic Memory Deallocation may need to adjust
 *         the actual address based on the actual HW config.
 * @param  i_chip      An OCMB.
 * @param  o_startAddr The returned start address.
 * @param  o_endAddr   The returned end address.
 * @param  i_port      The target memory port.
 * @param  i_dimmSlct  When used, this function will only return the address
 *                     range for the target DIMM select. Otherwise, the default
 *                     is to return the  address range for all DIMM selects.
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE TT, typename VT>
uint32_t getMemAddrRange( ExtensibleChip * i_chip,
                          VT & o_startAddr, VT & o_endAddr,
                          const uint8_t& i_port,
                          uint8_t i_dimmSlct = MAX_DIMM_PER_PORT );

/**
 * @brief  Queries if Row Repair is enabled.
 * @param  i_chip An OCMB.
 * @param  i_rank Any rank on the target DIMMs.
 * @return True if Row Repair is enabled on the DIMMs containing this rank.
 *         False otherwise.
 */
template<TARGETING::TYPE T>
bool isRowRepairEnabled( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Calls the hardware procedure to deploy the row repair
 * @param  i_chip An OCMB.
 * @param  i_rank Any rank on the target DIMMs.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise
 */
template<TARGETING::TYPE T>
uint32_t deployRowRepair( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Whenever an OMI link has degraded, the bus must be reconfigured to
 *         avoid infinite retrains.
 * @param  i_target An OMI.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t omiDegradeDlReconfig(TARGETING::TargetHandle_t i_target);

/**
 * @brief Calls a Hostboot interface to collect PMIC telemetry for any dimms
 *        in the callout list. An optional plid can be input to link a log to
 *        the PMIC telemetry log that will be created.
 * @param i_ocmb The OCMB target to collect PMIC telemetry for.
 * @param i_plid The optional plid of the PRD log to link to. If 0, the logs
 *               will not be linked.
 */
void getPmicTelemetry(TARGETING::TargetHandle_t i_ocmb, uint32_t i_plid = 0);

/**
 * @brief Calls a Hostboot interface to collect the SBE (Odyssey) scratch reg
 *        data (Synopsys training data). An error log with the data will be
 *        created and committed. An optional PLID may be used as a parameter
 *        to link the created error log to another error.
 *
 * @param i_ocmb The OCMB (Odyssey) target to collect the scratch data for.
 * @param i_plid The optional PLID to link the created error to.
 */
void getSbeScratchData(TARGETING::TargetHandle_t i_ocmb, uint32_t i_plid = 0);


/**
 * @brief  Calls a Hostboot interface to collect FIFO SBE FFDC error logs. This
 *         is used in the event of a DQS drift tracking fail.
 * @param  i_target An Odyssey OCMB.
 * @param  o_errls  FFDC error logs returned from the SBE.
 * @return Non-nullptr error log if an internal function fails, otherwise a
 *         nullptr error log.
 */
errlOwner getDqsDriftTrackFailFfdc(TARGETING::TargetHandle_t i_ocmb,
                                   errlHndl_t& o_errls);


//##############################################################################
//##                    Maintenance Command wrappers
//##############################################################################

/**
 * @brief  Starts Background Scrubbing.
 * @param  i_chip OCMB chip.
 * @param  i_rank Will start background scrubbing on the first address of this
 *                slave rank. To ensure the command is started on a master rank
 *                boundary, make sure the slave rank value is 0.
 * @param  i_port Target memory port.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startBgScrub( ExtensibleChip * i_chip, const MemRank & i_rank,
                       const uint8_t& i_port );

/**
 * @brief  Starts a scrub command on the target rank.
 * @param  i_chip      OCMB chip.
 * @param  i_rank      Target rank.
 * @param  i_rank      Target port.
 * @param  i_rangeType See enum AddrRangeType.
 * @param  i_stopCond  The stop conditions for the targeted scrub.
 * @param  i_endBound  End bound to determine where scrub stops when hitting
 *                     the specified stop conditions
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE TT, typename SCT>
uint32_t startTdScrub(ExtensibleChip * i_chip, const MemRank & i_rank,
                      const uint8_t& i_port, AddrRangeType i_rangeType,
                      SCT i_stopCond,
                      mss::mcbist::end_boundary i_endBound = mss::mcbist::NONE);

/*
 * @brief  Resumes a scrub command on the target.
 * @param  i_chip      OCMB chip.
 * @param  i_rangeType See enum AddrRangeType.
 * @param  i_stopCond  The stop conditions for the targeted scrub.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE TT, typename SCT>
uint32_t resumeTdScrub( ExtensibleChip * i_chip, SCT i_stopCond );

/**
 * @brief  Starts a scrub command on the next row of the input address
 * @param  i_chip      OCMB chip.
 * @param  i_rank      Target rank.
 * @param  i_addr      Target address.
 * @param  i_rangeType See enum AddrRangeType.
 * @param  i_stopCond  The stop conditions for the targeted scrub.
 * @param  i_endBound  End bound to determine where scrub stops when hitting
 *                     the specified stop conditions
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE TT, typename SCT>
uint32_t startTdScrubOnNextRow( ExtensibleChip * i_chip, const MemRank & i_rank,
        const MemAddr & i_addr, AddrRangeType i_rangeType, SCT i_stopCond,
        mss::mcbist::end_boundary i_endBound = mss::mcbist::NONE );

/**
 * @brief  Starts a single address steer command for the input address.
 * @param  i_chip      OCMB chip.
 * @param  i_addr      Target address.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t singleAddrSteer( ExtensibleChip * i_chip, const MemAddr & i_addr );

//##############################################################################
//##                  Core/cache trace array functions
//##############################################################################

/**
 * @brief Restarts Trace arrays after having stopped on error
 * @param i_tgt EC/EQ target
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t restartTraceArray(TARGETING::TargetHandle_t i_tgt);

//##############################################################################
//##                       RCS/PLL/Clock functions
//##############################################################################

/**
 * @brief  In the event of an RCS OSC error, transient error recovery.
 * @param  i_chip   A proc chip
 * @param  i_clkPos Clock position relative to the proc chip.
 * @return True if recovery failed (hard error). False otherwise.
 */
bool rcsTransientErrorRecovery(ExtensibleChip* i_chip, uint32_t i_clkPos);

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_H

