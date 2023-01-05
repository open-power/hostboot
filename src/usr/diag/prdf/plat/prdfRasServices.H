/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfRasServices.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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

#ifndef __prdfRasServices_H
#define __prdfRasServices_H

/** @file  prdfRasServices.H
 *  @brief Utility code to parse an SDC and produce the appropriate error log.
 */

// This must be included after all external includes. This will take care of
// cases where a file must be included in the common code, but the include paths
// are different between FSP and Hostboot.
#include <prdfRasServices_common.H>

namespace PRDF
{

/**
 * @brief Will loop through the input MRU list and call a Hostboot interface
 *        to collect PMIC telemetry for any dimms in the callout list.
 *        An optional plid can be input to link a log to the PMIC telemetry
 *        log that will be created.
 * @param i_mruList List of the targets that have been called out.
 * @param i_plid    The optional plid of the PRD log to link to. If 0, the
 *                  logs will not be linked.
 */
void collectPmicTelemetry(const SDC_MRU_LIST & i_mruList,
                          uint32_t i_plid = 0);

} // end namespace PRDF

#endif // __prdfRasServices_H

