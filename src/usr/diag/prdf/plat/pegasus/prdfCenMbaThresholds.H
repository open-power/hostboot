/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaThresholds.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef __PRDF_CEN_MBA_THRESHOLDS_H
#define __PRDF_CEN_MBA_THRESHOLDS_H

/** @file  prdfCenMbaThresholds.H
 *  @brief Utility functions used to get specific Centaur thresholds
 *         during IPL time.
 */

#include <prdfCenMbaThresholds_common.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfMfgThresholds.H>

namespace PRDF
{

class ExtensibleChip;

/**
 * @brief  Returns the manufacturing memory CE thresholds Per 2GB ( base ).
 */
inline uint8_t getMnfgCeTh()
{
    return MfgThresholdMgr::getInstance()->
                    getThreshold( PRDF_CEN_MBA_IPL_SOFT_CE_TH_ALGO );

}

} // end namespace PRDF

#endif /* __PRDF_CEN_MBA_THRESHOLDS_H */

