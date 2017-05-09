/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfLaneRepair.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef _PRDFLANEREPAIR_H
#define _PRDFLANEREPAIR_H

/** @file  prdfLaneRepair.H
 *  @brief Common Lane Repair code for Lane Spared, Spares Exceeded, and
 *         Too Many Bus Errors conditions.
 */

#include <iipconst.h>
#include <targeting/common/target.H>
#include <prdfErrlUtil.H>
#include <prdfCalloutMap.H>

namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;

namespace LaneRepair
{
/**
 * @brief Handles a Lane Repair Event
 * @param i_chip    Chip that detected the lane repair event
 * @param i_sc      The step code data struct.
 * @param i_spareDeployed  True if FIR bit indicates a spare was deployed
 * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t handleLaneRepairEvent (ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc,
                               bool i_spareDeployed);
/**
 * @brief  Will add target bus interface endpoints and all parts in between the
 *         endpoints to the global error log in RasServices.
 * @param  i_chip    RX-side chip of bus interface
 * @param  i_sc      The step code data struct.
 * @param  i_priority Callout priority (default MRU_LOW).
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
int32_t calloutBusInterface( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc,
                             PRDpriority i_priority = MRU_LOW );



} // end namespace LaneRepair
} // end namespace PRDF

#endif /* _PRDFLANEREPAIR_H */

