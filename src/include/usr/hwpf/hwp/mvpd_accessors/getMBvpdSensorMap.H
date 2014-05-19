/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdSensorMap.H $ */
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
// $Id: getMBvpdSensorMap.H,v 1.1 2013/11/20 22:36:54 whs Exp $

/**
 *  @file getMBvpdSensorMap.H
 *
 *  @brief Prototype for getMBvpdSensorMap() -
 *          get primary and secondary sensor map
 */

#ifndef    _HWP_MBVPDSENSORMAP_
#define    _HWP_MBVPDSENSORMAP_

#include   <fapi.H>

namespace fapi
{

    enum MBvpdSensorMap
    {
       SENSOR_MAP_PRIMARY =                0x00,
       SENSOR_MAP_SECONDARY =              0x01,
    };
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdSensorMap_FP_t)
     (const fapi::Target &, const fapi::MBvpdSensorMap,  uint8_t &);

extern "C"
{
/**
 * @brief Return primary and secondary sensor map from cvpd record VSPD
 *        keyword MW for attributes:
 *
 *        ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY
 *        ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY
 *
 * @param[in]  i_mbTarget   -   Membuf chip target
 * @param[in]  i_attr       -   Enumerator to select requested value
 * @param[out] o_val        -   Primary or secondary sensor map
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdSensorMap(
                              const fapi::Target &i_mbTarget,
                              const fapi::MBvpdSensorMap i_attr,
                              uint8_t &o_val);

}

#endif
