/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.H $                   */
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

#ifdef CONFIG_NVDIMM
#include <isteps/nvdimm/nvdimm.H>
#endif

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
 * @param  o_startAddr The returned start address.
 * @param  o_endAddr   The returned end address.
 * @param  i_rangeType See enum AddrRangeType.
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE TT, typename VT>
uint32_t getMemAddrRange( ExtensibleChip * i_chip, const MemRank & i_rank,
                          VT & o_startAddr, VT & o_endAddr,
                          AddrRangeType i_rangeType );

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
 * @param  i_dimmSlct  When used, this function will only return the address
 *                     range for the target DIMM select. Otherwise, the default
 *                     is to return the  address range for all DIMM selects.
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE TT, typename VT>
uint32_t getMemAddrRange( ExtensibleChip * i_chip,
                          VT & o_startAddr, VT & o_endAddr,
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

#ifdef CONFIG_NVDIMM
/**
 * @brief Notify PHYP/Hostboot of NVDIMM protection status
 *
 * @param i_target     Processor with NVDIMM
 * @param i_state      Protection state of NVDIMM
 */
uint32_t nvdimmNotifyProtChange( TARGETING::TargetHandle_t i_target,
    const NVDIMM::nvdimm_protection_t i_state );

/**
 * @brief Add SMART-specific, page 4 NVDIMM registers to the FFDC
 *
 * @param i_nvdimm An nvdimm target
 * @param io_errl  Error log to add the FFDC to
 */
void nvdimmAddFfdc( TARGETING::TargetHandle_t i_nvdimm, errlHndl_t & io_errl  );

#endif

//##############################################################################
//##                    Maintenance Command wrappers
//##############################################################################

/**
 * @brief  Starts Background Scrubbing.
 * @param  i_chip OCMB chip.
 * @param  i_rank Will start background scrubbing on the first address of this
 *                slave rank. To ensure the command is started on a master rank
 *                boundary, make sure the slave rank value is 0.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startBgScrub( ExtensibleChip * i_chip, const MemRank & i_rank );

/**
 * @brief  Starts a scrub command on the target rank.
 * @param  i_chip      OCMB chip.
 * @param  i_rank      Target rank.
 * @param  i_rangeType See enum AddrRangeType.
 * @param  i_stopCond  The stop conditions for the targeted scrub.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE TT, typename SCT>
uint32_t startTdScrub( ExtensibleChip * i_chip, const MemRank & i_rank,
                       AddrRangeType i_rangeType, SCT i_stopCond );

//##############################################################################
//##                  Core/cache trace array functions
//##############################################################################

/**
 * @brief Restarts Trace arrays after having stopped on error
 * @param i_tgt EC/EQ target
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t restartTraceArray(TARGETING::TargetHandle_t i_tgt);

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_H

