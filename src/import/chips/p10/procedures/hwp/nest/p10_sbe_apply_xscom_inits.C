/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_apply_xscom_inits.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
///
/// @file p10_sbe_setup_memory_bars.H
/// @brief Program ADU to apply set of register inits via XSCOM
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_sbe_apply_xscom_inits.H>
#include <p10_adu_setup.H>
#include <p10_adu_access.H>
#include <p10_adu_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_sbe_apply_xscom_inits(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const std::vector<std::pair<uint64_t, uint64_t>>& i_reg_inits)
{
    FAPI_DBG("Start");

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    adu_operationFlag l_adu_flags;
    l_adu_flags.setOperationType(adu_operationFlag::CACHE_INHIBIT);
    l_adu_flags.setTransactionSize(adu_operationFlag::TSIZE_8);
    uint32_t l_adu_flags_serialized = l_adu_flags.setFlag();

    // SBE is supplied a precomputed list of XSCOM address/data pairs, simply
    // walk through and apply them as cache-inhibited operations using the
    // ADU functions which support chip-op function
    for (const auto& l_reg_init : i_reg_inits)
    {
        uint32_t l_granules;
        uint8_t l_data[sizeof(uint64_t)];

        for (uint8_t b = 0; b < sizeof(uint64_t); b++)
        {
            l_data[b] = (l_reg_init.second >> (8 * (sizeof(uint64_t) - b - 1))) & 0xFF;
        }

        FAPI_DBG("Processing addr: 0x%016llX, data: 0x%016llX",
                 l_reg_init.first, l_reg_init.second);

        FAPI_EXEC_HWP(l_rc,
                      p10_adu_setup,
                      i_target,
                      l_reg_init.first,       // XSCOM address
                      false,                  // write operation
                      l_adu_flags_serialized, // CI, 8B size
                      l_granules);            // single 8B granule

        if (l_rc)
        {
            FAPI_ERR("Error from p10_adu_setup (addr: 0x%016llX)",
                     l_reg_init.first);
            break;
        }

        FAPI_EXEC_HWP(l_rc,
                      p10_adu_access,
                      i_target,
                      l_reg_init.first,       // XSCOM address
                      false,                  // write operation
                      l_adu_flags_serialized, // CI, 8B size
                      (l_granules == 1),      // first 8B granule
                      (l_granules == 1),      // last 8B granule
                      l_data);                // XSCOM data

        if (l_rc)
        {
            FAPI_ERR("Error from p10_adu_access (addr: 0x%016llX)",
                     l_reg_init.first);
            break;
        }

    }

    FAPI_DBG("End");
    return l_rc;
}
