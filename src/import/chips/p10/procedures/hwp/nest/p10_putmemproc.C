/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_putmemproc.C $   */
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
/// @file p10_putmemproc.C
/// @brief Invoke ADU putmem chipop.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_putmemproc.H>
#include <p10_adu_setup.H>
#include <p10_adu_access.H>
#include <p10_getputmemproc_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// NOTE: doxygen in header
fapi2::ReturnCode p10_putmemproc(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const uint32_t i_bytes,
    uint8_t* i_data,
    const uint32_t i_mem_flags)
{
    FAPI_DBG("Start");
    adu_operationFlag l_flags;
    uint64_t l_target_address = i_address;
    uint64_t l_end_address = i_address + i_bytes;
    uint32_t l_granules_before_setup = 0;
    uint32_t l_granule = 0;
    bool l_first_access = true;


    // Validate flags
    FAPI_TRY(p10_validateSbeMemoryAccessFlagsADU(i_target, i_address, i_bytes, i_mem_flags),
             "Error returned from p10_validateSbeMemoryAccessFlagsADU()");

    FAPI_TRY(p10_getADUFlags(i_target, i_address, i_bytes, i_mem_flags, l_flags),
             "Error returned from p10_getADUFlags()");

    // Write data
    while (l_target_address < l_end_address)
    {
        // invoke ADU setup HWP to prepare current stream of contiguous granules
        FAPI_TRY(p10_adu_setup(i_target,
                               l_target_address,
                               false,
                               l_flags.setFlag(),
                               l_granules_before_setup),
                 "Error from p10_adu_setup");

        FAPI_DBG("Granules before setup: %08X",
                 l_granules_before_setup);
        l_first_access = true;

        while (l_granules_before_setup && (l_target_address < l_end_address))
        {
            // invoke ADU access HWP to move one granule (8B)

            // NOTE: SBE environment does not support memset and therefore must
            // use compiler assisted initialization for dynamically sized
            // memory whereas some other environments do not support that ability.
#ifndef __PPE__
            uint8_t l_data[8];
            memset(l_data, 0, 8);
#else
            uint8_t l_data[8] = {0};
#endif
            // Prepare data array for writing, 8 bytes at a time
            // Depends on TSIZE, data in array needs to be right aligned.
            uint8_t l_startIndex = l_target_address % 8;

            for (uint32_t ii = 0; ii < l_flags.getTransactionSize(); ii++)
            {
                l_data[l_startIndex + ii] = i_data[( (l_granule * l_flags.getTransactionSize()) + ii)];
            }

            FAPI_TRY(p10_adu_access(i_target,
                                    l_target_address,
                                    false,
                                    l_flags.setFlag(),
                                    l_first_access,
                                    (l_granules_before_setup == 1) ||
                                    ((l_target_address + 8) >=
                                     l_end_address),
                                    l_data),
                     "Error from p10_adu_access");

            l_first_access = false;
            l_granules_before_setup--;
            l_target_address += l_flags.getTransactionSize();
            l_granule++;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
