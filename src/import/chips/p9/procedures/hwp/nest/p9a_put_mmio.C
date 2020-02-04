/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9a_put_mmio.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
//------------------------------------------------------------------------------------
//
/// @file p9a_put_mmio.C
/// @brief Implement putMMIO via ADU
//
// *HWP HWP Owner: Ben Gass bgass@us.ibm.com
// *HWP FW Owner: Daniel Crowell dcrowell@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

#include <p9a_put_mmio.H>
#include <p9a_mmio_util.H>
#include <p9_adu_setup.H>
#include <p9_adu_access.H>
#include <p9_adu_coherent_utils.H>

/// @brief Writes data via mmio to the target.
///
/// @param[in] i_target      HW target to operate on.
/// @param[in] i_mmioAddr    Address to read, relative to this Target's system
///                          MMIO address.
/// @param[in] i_transSize   The transaction size.
/// @param[in] i_data        Buffer that holds data to write to the HW target.
///                          The size of the buffer determines the number of
///                          amount of bytes that are written.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9a_put_mmio(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_mmioAddr,
                               const size_t i_transSize,
                               const std::vector<uint8_t>& i_data)
{
    uint8_t data[8];
    uint32_t l_idx;
    uint32_t l_data_idx;
    uint32_t l_max_grans;
    uint32_t l_grans;
    p9_ADU_oper_flag l_myAduFlag;
    uint64_t l_addr = i_mmioAddr;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc_target;

    auto l_size = i_data.size();
    char l_hexdata[(l_size * 2) + 1];

    for (uint32_t l_i = 0; l_i < l_size; l_i++)
    {
        sprintf(&l_hexdata[l_i * 2], "%02X", i_data[l_i]);
    }

    uint32_t l_tsize = static_cast<uint32_t>(i_transSize);

    FAPI_ASSERT(l_tsize == 4 || l_tsize == 8,
                fapi2::P9A_MMIO_BAD_SIZE_ERR()
                .set_TARGET(i_target)
                .set_SIZE(l_size),
                "Incorrect MMIO size");

    l_grans = (l_size / l_tsize);

    if ((l_size % l_tsize) > 0)
    {
        l_grans++;
    }

    FAPI_TRY(addOMIBase(i_target, l_addr));
    FAPI_DBG("Write address: %lX", l_addr);
    FAPI_DBG("Write data: %s", l_hexdata);

    l_proc_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    l_myAduFlag.setOperationType(p9_ADU_oper_flag::CACHE_INHIBIT);
    l_myAduFlag.setAutoIncrement(true);
    l_myAduFlag.setTransactionSize(static_cast<p9_ADU_oper_flag::Transaction_size_t>(l_tsize));

    l_data_idx = 0;

    while (l_data_idx < l_size)
    {
        FAPI_TRY(p9_adu_setup(l_proc_target, l_addr, false, l_myAduFlag.setFlag(), l_max_grans));

        while (l_grans > 0 && l_max_grans > 0)
        {

            for (l_idx = 0 ; l_idx < l_tsize && l_data_idx < l_size; l_idx++)
            {
                data[l_idx + (l_addr & 0x4)] = i_data[l_data_idx];
                l_data_idx++;
            }

            FAPI_TRY(p9_adu_access(l_proc_target, l_addr, false, l_myAduFlag.setFlag(),
                                   l_data_idx == 0, // The first transaction
                                   l_grans == 1,    // The last transaction
                                   data));

            l_grans--;
            l_max_grans--;
            l_addr += l_tsize;
        }
    }

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}
