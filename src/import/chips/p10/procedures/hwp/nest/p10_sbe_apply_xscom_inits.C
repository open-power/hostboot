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
    const size_t i_xscomPairSize,
    const void* i_pxscomInit)
{
    FAPI_DBG("p10_sbe_apply_xscom_inits - Start");

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    adu_operationFlag l_adu_flags;
    l_adu_flags.setOperationType(adu_operationFlag::CACHE_INHIBIT);
    l_adu_flags.setTransactionSize(adu_operationFlag::TSIZE_8);
    uint32_t l_adu_flags_serialized = l_adu_flags.setFlag();
    const xscomsInits_t* p_regInits = reinterpret_cast<const xscomsInits_t*>(i_pxscomInit);

    // SBE is supplied a precomputed list of XSCOM address/data pairs, simply
    // walk through and apply them as cache-inhibited operations using the
    // ADU functions which support chip-op function
    for(uint32_t i = 0 ; i < i_xscomPairSize; ++i)
    {
        uint32_t l_granules;
        uint8_t l_data[sizeof(uint64_t)];

        for (uint8_t b = 0; b < sizeof(uint64_t); b++)
        {
            l_data[b] = (p_regInits[i].data >> (8 * (sizeof(uint64_t) - b - 1))) & 0xFF;
        }

        FAPI_DBG("Processing Xscom Address=0x%08x%08x Data=0x%08x%08x",
                 ((p_regInits[i].address & 0xFFFFFFFF00000000ull) >> 32), (p_regInits[i].address & 0xFFFFFFFF),
                 ((p_regInits[i].data & 0xFFFFFFFF00000000ull) >> 32), (p_regInits[i].data & 0xFFFFFFFF));

        FAPI_EXEC_HWP(l_rc,
                      p10_adu_setup,
                      i_target,
                      p_regInits[i].address,// XSCOM address
                      false,                  // write operation
                      l_adu_flags_serialized, // CI, 8B size
                      l_granules);            // single 8B granule

        if (l_rc)
        {
            FAPI_ERR("Failed in p10_adu_setup (addr: 0x%08x%08x)",
                     ((p_regInits[i].address & 0xFFFFFFFF00000000ull) >> 32), (p_regInits[i].address & 0xFFFFFFFF));
            break;
        }

        FAPI_EXEC_HWP(l_rc,
                      p10_adu_access,
                      i_target,
                      p_regInits[i].address,// XSCOM address
                      false,                  // write operation
                      l_adu_flags_serialized, // CI, 8B size
                      (l_granules == 1),      // first 8B granule
                      (l_granules == 1),      // last 8B granule
                      l_data);                // XSCOM data

        if (l_rc)
        {
            FAPI_ERR("Failed in p10_adu_access (addr: 0x%08x%08x)",
                     ((p_regInits[i].address & 0xFFFFFFFF00000000ull) >> 32), (p_regInits[i].address & 0xFFFFFFFF));
            break;
        }
    }

    FAPI_DBG("p10_sbe_apply_xscom_inits - End");
    return l_rc;
}
