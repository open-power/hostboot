/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getControlCapableData.H $ */
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
// $ID: getControlCapableData.H, v 1.1 2014/9/4 09:05:00 eliner Exp $
/**
 *  @file getControlCapable.H
 *
 *  @brief MBvpd accessor for the ATTR_MSS_POWER_CONTROL_CAPABLE attributes
 */

#ifndef _HWP_MVPDCONTROLCAPABLEDATA_
#define _HWP_MVPDCONTROLCAPABLEDATA_

extern "C"
{
/**
 * @brief MBvpd accessor for the ATTR_MSS_POWER_CONTROL_CAPABLE attribute
 *
 * Access Power control capable value in MBvpd record VSPD keyword MR
 *
 * @param[in] i_mbTarget - Reference to mb Target
 * @param[out] o_val     - retrieved MR value
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getControlCapableData(const fapi::Target &i_mbTarget,
                                       uint8_t & o_val);
}

#endif
