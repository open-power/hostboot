/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/terminate.H $                              */
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
/** @file terminate.H
 *  @brief Defines kernel information about the TI data area
 */
#ifndef __KERNEL_TERMINATE_H
#define __KERNEL_TERMINATE_H

#include <kernel/types.h>


/** @fn terminateExecuteTI
 *  @brief Sequence to execute a TI attn
 */
void terminateExecuteTI();

/** @fn termWritePlid
 *  Update TI data area with a PLID.
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] i_plid:    plid to be stored
 *  @param[out] NONE:
 */
void termWritePlid(uint16_t i_source, uint32_t plid);

/** @fn termWriteSRC
 *  Create an SRC and Update the TI data area with the src created
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] i_reasoncode: reasoncode for the failure(assert or shutdown)
 *  @param[in] i_failAddr: i_linkRegister() value (address of failure)
 *  @param[out] NONE:
 */
void termWriteSRC(uint16_t i_source,
                    uint16_t i_reasoncode,
                    uint64_t i_failAddr = 0);


#endif
