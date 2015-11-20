/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCaptureData.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

#ifndef PRDF_CEN_MBA_CAPTURE_DATA_H
#define PRDF_CEN_MBA_CAPTURE_DATA_H

/**
 *  @file  prdfCenfMbaCaptureData.H
 *  @brief Header File for utility functions to capture MBA related data.
 */

#include <targeting/common/targetservice.H>
#include <iipCaptureData.h>
#include <errlentry.H>
#include <prdfMemoryMru.H>

namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;

namespace CenMbaCaptureData
{

/**
 * @brief Adds all Mem chiplet and MBA regs to the capture data for any MBA
 *        reporting an active attention via the MEM_CHIPLET_FIRs.
 * @note  This is only intended to be called in the MCS or MEMBUF PreAnalysis()
 *        plugins to capture the required FIR registers for FFDC.
 * @note  We are required to do the active attention check because there is a
 *        small window during the IPL where we may get an MCS or MEMBUF
 *        attention and the MBAs are not SCOMable at the time.
 * @param i_membChip A MEMBUF chip.
 * @param io_cd     Capture data struct.
 */
void addMemChipletFirRegs( ExtensibleChip * i_membChip, CaptureData & io_cd );

/**
 * @brief Adds Memory ECC FFDC to an error log.
 * @note  This is intended to be used in non-normal analysis paths that do not
 *        have an SDC (i.e. Restore DRAM Repairs, IPL MNFG CE Isolation).
 * @note  The data will be limited and include things like the DRAM Repairs data
 *        but will not include stuff like the CE/UE tables, because that
 *        information is not relevant during its intended uses.
 * @param i_mbaTrgt An MBA target
 * @param o_errl    Error log.
 */
void addMemEccData( TARGETING::TargetHandle_t i_mbaTrgt, errlHndl_t io_errl );

/**
 * @brief Adds Memory ECC FFDC to an SDC.
 * @param i_mbaChip An MBA chip.
 * @param io_sc     Step code data struct.
 */
void addMemEccData( ExtensibleChip * i_mbaChip, STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief Queries hardware for all DRAM repairs data (chip/symbol marks, DRAM
 *        spare, etc.) for the given MBA and added it to the capture data.
 * @param i_mbaTrgt An MBA target.
 * @param io_cd     Capture data struct.
 * @note  This function will be used to capture DRAM repair data into
 *        capture data struct. Other functions can call this function and
 *        update error log.
 */
void captureDramRepairsData( TARGETING::TargetHandle_t i_mbaTrgt,
                             CaptureData & io_cd );

/**
 * @brief Queries the Bad DQ attributes for the content of the DRAM repairs VPD
 *        and add it to the capture data.
 * @param i_mbaTrgt An MBA target.
 * @param io_cd     Capture data struct.
 * @note  This function will be used to capture DRAM repair data into
 *        capture data struct. Other functions can call this function and
 *        update error log.
 */
void captureDramRepairsVpd( TARGETING::TargetHandle_t i_mbaTrgt,
                            CaptureData & io_cd );

/**
 * @brief Adds a new user data section to the error log containing a MemoryMru
 *        plus extended data for extra FFDC.
 * @param i_mbaTrgt An MBA target
 * @param io_errl   Target error log.
 */
void addExtMemMruData( const MemoryMru & i_memMru, errlHndl_t io_errl );

} // end namespace MbaCaptureData

} // end namespace PRDF

#endif // PRDF_CEN_MBA_CAPTURE_DATA_H

