/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCaptureData.H $      */
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

#ifndef __prdfMemCaptureData_H
#define __prdfMemCaptureData_H

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>

namespace PRDF
{

namespace MemCaptureData
{

/**
 * @brief Adds memory ECC FFDC to an SDC.
 * @param i_chip MCBIST, MCA, or MBA.
 * @param io_sc  Step code data struct.
 */
template<TARGETING::TYPE T>
void addEccData( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief Adds a new user data section to the error log containing a MemoryMru
 *        plus extended data for extra FFDC.
 * @param i_memMru The memory mru
 * @param io_errl  Target error log.
 */
void addExtMemMruData( const MemoryMru & i_memMru, errlHndl_t io_errl );

} // end namespace MemCaptureData

} // end namespace PRDF

#endif // __prdfMemCaptureData_H

