/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getControlCapableData.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
// $ID: getControlCapableData.C, v 1.1 2014/9/4 09:05:00 eliner Exp $
/**
 *  @file getControlCapable.C
 *
 *  @brief MBvpd accessor for the ATTR_VPD_POWER_CONTROL_CAPABLE attributes
 */

#include    <stdint.h>
#include    <fapi.H>
#include    <getControlCapableData.H>

extern "C"
{
using namespace fapi;
fapi::ReturnCode getControlCapableData(
                const fapi::Target &i_mbTarget,
                uint8_t & o_val)
{
    fapi::ReturnCode l_rc;

    FAPI_DBG("getControlCapableData: start");
    do {
        // ATTR_VPD_POWER_CONTROL_CAPABLE is at the membuf level, but the
        //  getMBvpdAttr() function takes a mba, so need to do a
        //  conversion
        std::vector<fapi::Target> l_mbas;
        l_rc = fapiGetChildChiplets( i_mbTarget,
                                     fapi::TARGET_TYPE_MBA_CHIPLET,
                                     l_mbas );
        if( l_rc )
        {
            FAPI_ERR("getControlCapableData: fapiGetChildChiplets failed");
            break;
        }

        // If we don't have any functional MBAs then we will fail in
        //  the other function so just return a default value here
        if( l_mbas.empty() )
        {
            o_val = fapi::ENUM_ATTR_VPD_POWER_CONTROL_CAPABLE_NONE;
            break;
        }

        // Call a VPD Accessor HWP to get the data
        FAPI_EXEC_HWP(l_rc, getMBvpdAttr,
                      l_mbas[0], ATTR_VPD_POWER_CONTROL_CAPABLE,
                      &o_val, sizeof(ATTR_VPD_POWER_CONTROL_CAPABLE_Type));
    } while(0);
    FAPI_DBG("getControlCapableData: end");

    return l_rc;
}
}
