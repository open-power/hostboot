/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfFsiCapUtil.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef FSI_CAP_UTIL_H
#define FSI_CAP_UTIL_H

/**
 * @file    prdfFsiCapUtil.H
 * @brief   Captures FSI status register for FFDC.
 */

namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;
namespace PLL
{

/**
 * @brief   capture FSI Status Reg for FFDC
 * @param   i_chip   Extensible chip
 * @param   i_sc     service data collector
 */
void captureFsiStatusReg( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc );

}// namespace PLL

} //namespace PRDF

#endif  //FSI_CAP_UTIL_H
