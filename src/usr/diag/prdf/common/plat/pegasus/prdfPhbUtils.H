/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPhbUtils.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef PHB_CONFIG_H
#define PHB_CONFIG_H

/** @file  prdfPhbUtils.H
 *  @brief Utility functions to determine PHB Configuration.
 */

#include <prdfPlatServices.H>

namespace PRDF
{

namespace Proc
{

/**
 * @brief  Returns PHB target associated with given IOPCIFR and clock.
 * @param  i_procTrgt The target processor.
 * @param  i_iopciIdx IOPCIFIR instance number (0,1)
 * @param  i_clkIdx   The target clock within the IOPCIFIR (0-1)
 * @param  o_phbTrgt  NULL if the PHB does not exist. Otherwise the PHB target.
 * @return NULL if no configured PHB found, otherwise the target PHB.
 */
int32_t getConfiguredPHB( TARGETING::TargetHandle_t i_procTrgt,
                          uint32_t i_iopciIdx, uint32_t i_clkIdx,
                          TARGETING::TargetHandle_t & o_phbTrgt );

} // end namespace Proc

} // end namespace PRDF

#endif // PHB_CONFIG_H
