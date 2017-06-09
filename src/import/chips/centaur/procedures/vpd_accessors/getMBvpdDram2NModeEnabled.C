/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdDram2NModeEnabled.C $ */
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
///  @file getMBvpdDram2NModeEnabled.C
///  @brief MBVPD Accessor for providing the ATTR_VPD_DRAM_2N_MODE_ENABLED attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi support
#include    <fapi2.H>
#include    <getMBvpdDram2NModeEnabled.H>
#include    <getMBvpdAttr.H>

extern "C"
{

///
/// @brief Get the ATTR_DRAM_2N_MODE_ENABLED FAPI attribute
///
/// Return whether Dram 2N Mode is enabled based on the MR keyword
///   DRAM_2N_MODE value. The DRAM_2N_Mode values for both ports of the mba
///   must be equal, otherwise an error is returned.
///
/// @param[in]  i_mbaTarget - Reference to mba Target
/// @param[out] o_val  - ATTR_VPD_DRAM_2N_MODE_ENABLED enumeration value
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdDram2NModeEnabled(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>&   i_mbaTarget,
        uint8_t&   o_val)
    {
        fapi2::ReturnCode l_fapirc;
        uint8_t l_dram2NMode [2] = {0, 0};
        const uint8_t DRAM_2N_MODE  = 0x02;

        FAPI_DBG("getMBvpdDram2NModeEnabled: entry ");

        // Retrieve the Dram 2N Mode from the MR keyword
        FAPI_EXEC_HWP(l_fapirc,
                      getMBvpdAttr,
                      i_mbaTarget,
                      fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED,
                      &l_dram2NMode,
                      sizeof(l_dram2NMode));

        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdDram2NModeEnabled: Read of VZ keyword failed");
            return l_fapirc;  //  break out with fapirc
        }

        // ensure values match
        FAPI_ASSERT(l_dram2NMode[0] == l_dram2NMode[1],
                    fapi2::CEN_MBVPD_DRAM_2N_MODE_NOT_EQUAL().
                    set_PORT0(l_dram2NMode[0]).
                    set_PORT1(l_dram2NMode[1]).
                    set_MBA_TARGET(i_mbaTarget),
                    "getMBvpdDram2NModeEnabled:"
                    " ports should have same value 0x%02x != 0x%02x",
                    l_dram2NMode[0], l_dram2NMode[1]);

        // return value
        if (DRAM_2N_MODE == l_dram2NMode[0] )
        {
            o_val = fapi2::ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_TRUE;
        }
        else
        {
            o_val = fapi2::ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_FALSE;
        }

        FAPI_DBG("getMBvpdDram2NModeEnabled: exit rc=0x%08x)",
                 static_cast<uint32_t>(l_fapirc));

    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
