/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_putmemproc.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file p9_putmemproc.C
/// @brief Invoke ADU putmem chipop
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 3
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_putmemproc.H>
#include <p9_adu_setup.H>
#include <p9_adu_access.H>
#include <p9_adu_coherent_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// NOTE: doxygen in header
fapi2::ReturnCode p9_putmemproc(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const uint32_t i_bytes,
    uint8_t* i_data,
    const uint32_t i_mem_flags)
{
    p9_ADU_oper_flag l_flags;
    uint64_t l_target_address = i_address;
    uint64_t l_end_address = i_address + i_bytes;
    uint32_t l_granules_before_setup = 0;
    uint32_t l_granule = 0;
    uint8_t l_data[1];
    bool l_first_access = true;

    FAPI_DBG("Start");

    FAPI_ASSERT(((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC) == fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC) &&
                ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PBA)  == 0) &&
                ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_LCO_MODE) == 0) &&
                ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INJECT_MODE) == 0),
                fapi2::P9_PUTMEMPROC_INVALID_FLAGS().
                set_TARGET(i_target).
                set_ADDRESS(i_address).
                set_BYTES(i_bytes).
                set_FLAGS(i_mem_flags).
                set_FLAG_CHECK_OP_TYPE(((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC) ==
                                        fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC) &&
                                       ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PBA)  == 0)).
                set_FLAG_CHECK_LCO_MODE((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_LCO_MODE) == 0).
                set_FLAG_CHECK_CACHE_INJECT_MODE((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INJECT_MODE) == 0),
                "Invalid flag specified for ADU access");

    FAPI_ASSERT(((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_ECC_OVERRIDE) == 0) &&
                ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TAG) == 0) &&
                ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_HOST_PASS_THROUGH) == 0),
                fapi2::P9_PUTMEMPROC_UNSUPPORTED_FLAGS().
                set_TARGET(i_target).
                set_ADDRESS(i_address).
                set_BYTES(i_bytes).
                set_FLAGS(i_mem_flags).
                set_FLAG_CHECK_ECC_OVERRIDE((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_ECC_OVERRIDE) == 0).
                set_FLAG_CHECK_TAG((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TAG) == 0).
                set_FLAG_CHECK_HOST_PASS_THROUGH((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_HOST_PASS_THROUGH) == 0),
                "Unsupported flag specified for ADU access");

    // set auto-increment
    l_flags.setAutoIncrement((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_AUTO_INCR_ON) ==
                             fapi2::SBE_MEM_ACCESS_FLAGS_AUTO_INCR_ON);

    // set fast mode
    l_flags.setFastMode((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_FAST_MODE_ON) ==
                        fapi2::SBE_MEM_ACCESS_FLAGS_FAST_MODE_ON);

    // set operation type and transaction size
    if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INHIBITED_MODE) ==
        fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INHIBITED_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::CACHE_INHIBIT);

        if (i_bytes == 4)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_4);
        }
        else if (i_bytes == 2)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_2);
        }
        else if (i_bytes == 1)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_1);
        }
        else if (i_bytes == 8)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_8);
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::P9_PUTMEMPROC_INVALID_SIZE_CI().
                        set_TARGET(i_target).
                        set_ADDRESS(i_address).
                        set_BYTES(i_bytes).
                        set_FLAGS(i_mem_flags),
                        "Invalid byte count specified for cache-inhibited access");
        }
    }
    else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PB_DIS_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_PB_DIS_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::PB_DIS_OPER);
    }
    else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::PMISC_OPER);
    }
    else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PB_INIT_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_PB_INIT_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::PB_INIT_OPER);
    }
    else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE) ==
             fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::PRE_SWITCH_CD);
    }
    else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_AB_MODE) ==
             fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_AB_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::PRE_SWITCH_AB);
    }
    else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE)
    {
        l_flags.setOperationType(p9_ADU_oper_flag::POST_SWITCH);
    }
    else
    {
        l_flags.setOperationType(p9_ADU_oper_flag::DMA_PARTIAL);

        if (i_bytes == 4)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_4);
        }
        else if (i_bytes == 2)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_2);
        }
        else if (i_bytes == 1)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_1);
        }
        else if ((i_bytes % 8) == 0)
        {
            l_flags.setTransactionSize(p9_ADU_oper_flag::TSIZE_8);
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::P9_PUTMEMPROC_INVALID_SIZE_DMA().
                        set_TARGET(i_target).
                        set_ADDRESS(i_address).
                        set_BYTES(i_bytes).
                        set_FLAGS(i_mem_flags),
                        "Invalid byte count specified for DMA partial write access");
        }
    }

    while (l_target_address < l_end_address)
    {
        // invoke ADU setup HWP to prepare current stream of contiguous granules
        FAPI_TRY(p9_adu_setup(i_target,
                              l_target_address,
                              false,
                              l_flags.setFlag(),
                              l_granules_before_setup),
                 "Error from p9_adu_setup");

        FAPI_DBG("Granules before setup: %d",
                 l_granules_before_setup);
        l_first_access = true;

        while (l_granules_before_setup && (l_target_address < l_end_address))
        {
            // invoke ADU access HWP to move one granule (8B)
            l_data[0] = i_data[l_granule];
            FAPI_TRY(p9_adu_access(i_target,
                                   l_target_address,
                                   false,
                                   l_flags.setFlag(),
                                   l_first_access,
                                   (l_granules_before_setup == 1) ||
                                   ((l_target_address + 8) >=
                                    l_end_address),
                                   l_data),
                     "Error from p9_adu_access");

            l_first_access = false;
            l_granules_before_setup--;
            l_target_address += 8;
            l_granule++;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
