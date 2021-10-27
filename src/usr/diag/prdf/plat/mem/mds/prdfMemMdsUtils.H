/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMdsUtils.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __prdfMemMdsUtils_H
#define __prdfMemMdsUtils_H

/**
 * @file  prdfMemMdsUtils.H
 * @brief Utility functions for supporting MDS DDIMMs
 */

// Platform includes
#include <prdfPlatServices.H>
#include <prdfTargetServices.H>

namespace PRDF
{

namespace MDS
{

/**
 * @brief  This is the utility used for reading registers from the MDS dimm's
 *         media controller.
 * @param  i_target The input MDS_CTLR/OCMB
 * @param  i_addr   The input address
 * @param  o_data   The data read from the media controller
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t readMdsCtlr( TARGETING::TargetHandle_t i_target, uint32_t i_addr,
                      uint32_t & o_data );

/**
 * @brief  This is called to clear the media error logs on an MDS DDIMMs
 *         media controller.
 * @param  i_chip The input OCMB
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t clearMediaErrLogs( ExtensibleChip * i_ocmb );

} // end namespace MDS

} // end namespace PRDF

#endif // __prdfMemMdsUtils_H

