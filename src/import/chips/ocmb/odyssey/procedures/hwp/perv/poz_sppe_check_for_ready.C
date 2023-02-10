/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_sppe_check_for_ready.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
//------------------------------------------------------------------------------
/// @file  poz_sppe_check_for_ready.H
/// @brief Confirm that SPPE has reached expected state based on reset/boot type
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy (skadapal@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <poz_sppe_check_for_ready.H>
#include <poz_sppe_check_for_ready_regs.H>

using namespace fapi2;

typedef enum
{
    SPPE_RUNTIME = 4,
    SPPE_PK_BOOTED  = 0,
} poz_sppe_boot_type_t;

ReturnCode poz_sppe_check_for_ready(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    const poz_sppe_boot_parms i_boot_parms)
{
    FAPI_DBG("Entering ...");

    SB_MSG_t SB_MSG;
    uint32_t l_poll = 1;

    // calculate expected state based on input flag
    // attribute value
    poz_sppe_boot_type_t l_boot_type = SPPE_PK_BOOTED;

    if (!(i_boot_parms.boot_flags & 0xC0000000))
    {
        l_boot_type = SPPE_RUNTIME;
    }

    // loop until expected state is reached or we've
    // waited for the prescribed timeout
    while (1)
    {
        // delay before polling
        FAPI_TRY(delay(i_boot_parms.poll_delay_ns,
                       i_boot_parms.poll_delay_cycles));

        // sample register, break if expected bit is set
        FAPI_TRY(SB_MSG.getCfam(i_target));

        if (SB_MSG.getBit(l_boot_type))
        {
            break;
        }

        // bump count
        l_poll++;

        // test for timeout
        FAPI_ASSERT((l_poll <= i_boot_parms.max_polls),
                    fapi2::POZ_SPPE_NOT_READY_ERR()
                    .set_TARGET(i_target)
                    .set_SB_MSG(SB_MSG())
                    .set_BOOT_TYPE(l_boot_type),
                    "SPPE did not reach expected state prior to timeout!");
    }


fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return current_err;
}
