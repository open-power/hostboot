/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMds_ipl.H $             */
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
#ifndef __prdfMemMds_ipl_H
#define __prdfMemMds_ipl_H

/**
 * @file  prdfMemMds_ipl.H
 * @brief Functions needed for IPL to support MDS DDIMMs
 */

// Platform includes
#include <prdfPlatServices.H>

namespace PRDF
{

namespace MDS
{

/**
 * @brief  This is called for analyzing media errors on an MDS
 *         DDIMM when handling a command complete attention.
 * @param  i_chip        The input OCMB
 * @param  i_addr        The input address the mcbist command stopped on
 * @param  o_errorsFound True if errors where found and handled. False
 *                       otherwise.
 * @param  io_sc         The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t checkMediaErrors_ipl( ExtensibleChip * i_chip,
    const MemAddr & i_addr, bool & o_errorsFound,
    STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  This is called for analyzing read-path interface errors on an MDS
 *         DDIMM when handling a command complete attention.
 * @param  i_chip        The input OCMB
 * @param  i_addr        The input address the mcbist command stopped on
 * @param  o_errorsFound True if errors where found and handled. False
 *                       otherwise.
 * @param  io_sc         The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t checkReadPathInterfaceErrors_ipl( ExtensibleChip * i_chip,
    const MemAddr & i_addr, bool & o_errorsFound,
    STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  This is called for analyzing write-path interface errors on an MDS
 *         DDIMM when handling a command complete attention.
 * @param  i_chip        The input OCMB
 * @param  i_addr        The input address the mcbist command stopped on
 * @param  o_errorsFound True if errors where found and handled. False
 *                       otherwise.
 * @param  io_sc         The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t checkWritePathInterfaceErrors_ipl( ExtensibleChip * i_chip,
    const MemAddr & i_addr, bool & o_errorsFound,
    STEP_CODE_DATA_STRUCT & io_sc );

} // end namespace MDS

} // end namespace PRDF

#endif // __prdfMemMds_ipl_H
