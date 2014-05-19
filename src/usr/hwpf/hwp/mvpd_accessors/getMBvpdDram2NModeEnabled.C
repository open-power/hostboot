/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdDram2NModeEnabled.C $ */
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
// $Id: getMBvpdDram2NModeEnabled.C,v 1.3 2014/02/12 22:11:39 mjjones Exp $
/**
 *  @file getMBvpdDram2NModeEnabled.C
 *
 *  @brief get the Dram 2N Mode value from MBvpd keyword MR
 *         and return whether 2N mode is enabled
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getMBvpdDram2NModeEnabled.H>
#include    <getMBvpdPhaseRotatorData.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getMBvpdDram2NModeEnabled(
                              const fapi::Target   &i_mbaTarget,
                              uint8_t  & o_val)
{
    fapi::ReturnCode l_fapirc;
    uint8_t l_dram2NMode [2] = {0,0};

    FAPI_DBG("getMBvpdDram2NModeEnabled: entry ");

    do {
        // Retrieve the Dram 2N Mode from the MR keyword
        FAPI_EXEC_HWP(l_fapirc,
                      getMBvpdPhaseRotatorData,
                      i_mbaTarget,
                      fapi::PHASE_ROT_DRAM_2N_MODE,
                      l_dram2NMode);
        if (l_fapirc)
        {
            FAPI_ERR("getMBvpdDram2NModeEnabled: Read of VZ keyword failed");
            break;  //  break out with fapirc
        }
        // ensure values match
        if (l_dram2NMode[0] != l_dram2NMode[1]) {
            FAPI_ERR("getMBvpdDram2NModeEnabled:"
                     " ports should have same value 0x%02x != 0x%02x",
                     l_dram2NMode[0],l_dram2NMode[1]);
            const uint32_t & PORT0 = l_dram2NMode[0];
            const uint32_t & PORT1 = l_dram2NMode[1];
            const fapi::Target & MBA_TARGET = i_mbaTarget;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_MBVPD_DRAM_2N_MODE_NOT_EQUAL);
            break;  //  break out with fapirc
        }
        // return value
        const uint8_t DRAM_2N_MODE  = 0x02;
        if (DRAM_2N_MODE == l_dram2NMode[0] )
        {
            o_val=fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_TRUE;
        }
        else
        {
            o_val=fapi::ENUM_ATTR_VPD_DRAM_2N_MODE_ENABLED_FALSE;
        }

    } while (0);

    FAPI_DBG("getMBvpdDram2NModeEnabled: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
