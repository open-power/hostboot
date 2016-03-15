/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/customize_attrs_for_payload.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef __RUNTIME_CUST_ATTRS_FOR_PAYLOAD_H
#define __RUNTIME_CUST_ATTRS_FOR_PAYLOAD_H

/**
 *  @file customize_attrs_for_payload.H
 *  @brief Provides the definition for the payload specific attribute
 *      customization functions
 */

#include <errl/errlentry.H>
#include <runtime/rt_targeting.H>
#include <targeting/common/attributes.H>

namespace RUNTIME
{

static const TARGETING::ATTR_HBRT_HYP_ID_type HBRT_HYP_ID_UNKNOWN
    = 0xFFFFFFFFFFFFFFFFULL;

static const RT_TARG::rtChipId_t RT_TYPE_UNKNOWN
    = 0xFFFFFFFFFFFFFFFFULL;

/**
 *  @brief Populate ATTR_HBRT_HYP_ID attributes for the current payload type,
 *      allowing runtime/host interfaces to reference equivalent targets
 *  @param[in] i_configForPhyp Whether to configure the IDs for PHyp (true), or
 *      all other payload kinds (false)
 *  @return Error log handle
 *  @retval NULL Populated all ATTR_HBRT_HYP_ID attributes successfully
 *  @retval !NULL Failed to populate one or more ATTR_HBRT_HYP_ID attributes
 */
errlHndl_t configureHbrtHypIds(bool i_configForPhyp);


}; // End namespace RUNTIME

#endif
