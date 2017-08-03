/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#include <lib/mcbist/memdiags.H> ///< MCBIST command interfaces
//#include <utility_procedures/mss_maint_cmds.H> TODO: RTC 157888

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

inline bool isSmpCoherent() { return false; }

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
//##                  Nimbus/Centaur Maintenance Command wrappers
//##############################################################################

/**
 * @brief  Starts Background Scrubbing.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank Will start background scrubbing on the first address of this
 *                slave rank. To ensure the command is started on a master rank
 *                boundary, make sure the slave rank value is 0.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startBgScrub( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Starts a targeted scrub command on the target rank for VCM phase 1.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank The rank to target.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startVcmPhase1( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Starts a targeted scrub command on the target rank for VCM phase 2.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank The rank to target.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startVcmPhase2( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Starts a targeted scrub command on the target rank for TPS phase 1.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank The rank to target.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startTpsPhase1( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Starts a targeted scrub command on the target rank for TPS phase 2.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank The rank to target.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startTpsPhase2( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Starts a targeted scrub command on the target rank for runtime TPS.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank The rank to target.
 * @param  i_countAllCes True if we should count all CEs.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startTpsRuntime( ExtensibleChip * i_chip, const MemRank & i_rank,
                          bool i_countAllCes );

/**
 * @brief Restarts Trace arrays after having stopped on error
 * @param i_tgt EC/EQ target
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t restartTraceArray(TARGETING::TargetHandle_t i_tgt);

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_H

