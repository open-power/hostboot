/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8PllPcie.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#ifndef __prdfP8PllPcie_H
#define __prdfP8PllPcie_H

/** @file  prdfP8PllPcie.H
 *  @brief Utility functions for PLL domain.
 */

#include <UtilHash.H>
namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;
namespace PLL
{

/**
 * @brief   get the pcie source osc pos reporting error for this proc
 * @param   i_chip   P8 chip
 * @param   i_sc     service data collector
 * @return  osc position
 */
uint32_t getIoOscPos( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & io_sc );

} // end namespace PLL

namespace Proc
{

enum
{
    // All of the chiplet PLL_ERROR bits below
    // are collected in this TP_LFIR bit
    PLL_DETECT_P8 = 19,
    // Chiplet PLL_ERROR mask and error bits
    PLL_ERROR_MASK  = 12,
    PLL_ERROR_BIT   = 25,
    PB_DMI_RIGHT_PLL_ERROR = 25, // Venice only
    PB_DMI_LEFT_PLL_ERROR  = 26, // Venice and Murano
    // PCB Slave internal parity error
    PARITY_ERROR_MASK  = 8,
    PARITY_ERROR_BIT   = 4,
};

}//end namespace Proc
} // end namespace PRDF

#endif // __prdfP8PllPcie_H
