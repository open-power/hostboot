/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getControlCapableData.C $ */
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
/// @file getControlCapable.C
/// @brief MBvpd accessor for the ATTR_VPD_POWER_CONTROL_CAPABLE attributes
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include  <generic/memory/lib/utils/c_str.H>
#include    <stdint.h>
#include    <fapi2.H>
#include    <getControlCapableData.H>
#include    <getMBvpdAttr.H>

extern "C"
{
    ///
    /// @brief MBvpd accessor for the ATTR_VPD_POWER_CONTROL_CAPABLE attribute
    /// @param[in] i_mbTarget - Reference to mb Target
    /// @param[out] o_val     - retrieved MR value
    /// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
    ///
    fapi2::ReturnCode getControlCapableData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        uint8_t& o_val)
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        FAPI_DBG("getControlCapableData: start on %s", mss::c_str(i_mbTarget));
        // ATTR_VPD_POWER_CONTROL_CAPABLE is at the membuf level, but the
        //  getMBvpdAttr() function takes a mba, so need to do a
        //  conversion
        const auto l_mbas = i_mbTarget.getChildren<fapi2::TARGET_TYPE_MBA>();

        // If we don't have any functional MBAs then we will fail in
        //  the other function so just return a default value here
        if( l_mbas.empty() )
        {
            o_val = fapi2::ENUM_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE_NONE;
            return l_rc;
        }

        // Call a VPD Accessor HWP to get the data
        FAPI_EXEC_HWP(l_rc, getMBvpdAttr,
                      l_mbas[0], fapi2::ATTR_CEN_VPD_POWER_CONTROL_CAPABLE,
                      &o_val, sizeof(fapi2::ATTR_CEN_VPD_POWER_CONTROL_CAPABLE_Type));
        FAPI_DBG("getControlCapableData: end on %s", mss::c_str(i_mbTarget));

        return l_rc;
    }
}
