/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getputmemproc_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_getputmemproc_utils.C
///
/// @brief Common code to support get/putmemproc procedures.
///        Note: This file is not intended to be imported to SBE platform
///              to save its space.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: N/A
/// *HWP Consumed by: Cronus, HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_getputmemproc_utils.H>
#include <fapi2_mem_access.H>
#include <p10_adu_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

////////////////////////////////////////////////////////
// p10_validateSbeMemoryAccessFlagsADU
////////////////////////////////////////////////////////
    fapi2::ReturnCode p10_validateSbeMemoryAccessFlagsADU(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_bytes,
        const uint32_t i_mem_flags)
    {
        FAPI_DBG("Start");

        FAPI_ASSERT(((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC) == fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PROC) &&
                    ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TARGET_PBA)  == 0) &&
                    ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_LCO_MODE) == 0) &&
                    ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INJECT_MODE) == 0),
                    fapi2::P10_GETPUTMEMPROC_INVALID_FLAGS().
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
                    fapi2::P10_GETPUTMEMPROC_UNSUPPORTED_FLAGS().
                    set_TARGET(i_target).
                    set_ADDRESS(i_address).
                    set_BYTES(i_bytes).
                    set_FLAGS(i_mem_flags).
                    set_FLAG_CHECK_ECC_OVERRIDE((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_ECC_OVERRIDE) == 0).
                    set_FLAG_CHECK_TAG((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_TAG) == 0).
                    set_FLAG_CHECK_HOST_PASS_THROUGH((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_HOST_PASS_THROUGH) == 0),
                    "Unsupported flag specified for ADU access");

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

////////////////////////////////////////////////////////
// p10_getADUFlags
////////////////////////////////////////////////////////
    fapi2::ReturnCode p10_getADUFlags(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_bytes,
        const uint32_t i_mem_flags,
        adu_operationFlag& o_aduFlags)
    {
        FAPI_DBG("Start");

        // set auto-increment
        o_aduFlags.setAutoIncrement((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_AUTO_INCR_ON) ==
                                    fapi2::SBE_MEM_ACCESS_FLAGS_AUTO_INCR_ON);

        // set fast mode
        o_aduFlags.setFastMode((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_FAST_MODE_ON) ==
                               fapi2::SBE_MEM_ACCESS_FLAGS_FAST_MODE_ON);

        // set operation type and transaction size
        if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INHIBITED_MODE) ==
            fapi2::SBE_MEM_ACCESS_FLAGS_CACHE_INHIBITED_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::CACHE_INHIBIT);

            if (i_bytes == 4)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_4);
            }
            else if (i_bytes == 2)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_2);
            }
            else if (i_bytes == 1)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_1);
            }
            else if ((i_bytes % 8) == 0)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_8);
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::P10_GETPUTMEMPROC_INVALID_SIZE_CI().
                            set_TARGET(i_target).
                            set_ADDRESS(i_address).
                            set_BYTES(i_bytes).
                            set_FLAGS(i_mem_flags),
                            "Invalid byte count specified for cache-inhibited access");
            }
        }
        else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PB_DIS_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_PB_DIS_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::PB_DIS_OPER);
        }
        else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_SWITCH_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::PMISC_OPER);

            if (i_bytes == 1)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_1);
            }
            else if (i_bytes == 2)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_2);
            }
        }
        else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PB_INIT_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_PB_INIT_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::PB_INIT_OPER);
        }
        else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE) ==
                 fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_CD_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::PRE_SWITCH_CD);
        }
        else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_AB_MODE) ==
                 fapi2::SBE_MEM_ACCESS_FLAGS_PRE_SWITCH_AB_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::PRE_SWITCH_AB);
        }
        else if ((i_mem_flags & fapi2::SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE) == fapi2::SBE_MEM_ACCESS_FLAGS_POST_SWITCH_MODE)
        {
            o_aduFlags.setOperationType(adu_operationFlag::POST_SWITCH);
        }
        else
        {
            o_aduFlags.setOperationType(adu_operationFlag::DMA_PARTIAL);

            if (i_bytes == 4)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_4);
            }
            else if (i_bytes == 2)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_2);
            }
            else if (i_bytes == 1)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_1);
            }
            else if ((i_bytes % 8) == 0)
            {
                o_aduFlags.setTransactionSize(adu_operationFlag::TSIZE_8);
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::P10_GETPUTMEMPROC_INVALID_SIZE_DMA().
                            set_TARGET(i_target).
                            set_ADDRESS(i_address).
                            set_BYTES(i_bytes).
                            set_FLAGS(i_mem_flags),
                            "Invalid byte count specified for DMA partial write access");
            }
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

}
