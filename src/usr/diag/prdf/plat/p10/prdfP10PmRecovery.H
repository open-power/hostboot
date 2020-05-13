/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p10/prdfP10PmRecovery.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/** @file  prdfP10PmRecovery.H
 *  @brief Power management STOP failure recovery actions
 */

#ifndef __prdfP10PmRecovery_H
#define __prdfP10PmRecovery_H

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

namespace PRDF
{

/**
 * @brief Power management STOP failure recovery actions
 * @param i_chip  P10 extensible chip
 * @param io_sc   Step code data structure
 * @param return SUCCESS/FAIL
 */
int32_t pmRecovery( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc );

} // end namespace PRDF

#endif // __prdfP10PmRecovery_H
