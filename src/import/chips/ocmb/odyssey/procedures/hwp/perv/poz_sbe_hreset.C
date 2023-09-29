/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_sbe_hreset.C $ */
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
/// @file  poz_sbe_reset.H
/// @brief Applies Hreset during runtime
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Swathips (swathips@in.ibm.com)
// *HWP FW Maintainer   : Amit Tendolkar (amit.tendolkar@in.ibm.com)
//------------------------------------------------------------------------------

#include <poz_sbe_hreset.H>
#include <poz_scom_perv.H>

using namespace scomt::poz;


SCOMT_PERV_USE_FSXCOMP_FSXLOG_SB_CS;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_SB_MSG;

typedef FSXCOMP_FSXLOG_SB_MSG_t SB_MSG_t;
typedef FSXCOMP_FSXLOG_SB_CS_t SB_CS_t;

using namespace fapi2;

ReturnCode poz_sbe_hreset(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    const poz_sbe_boot_parms i_boot_parms, bool i_use_scom_path)
{
    FAPI_DBG("Entering ...");

    SB_MSG_t SB_MSG;
    SB_CS_t SB_CS;
    //FSXCOMP_FSXLOG_SB_CS_t SB_MSG;
    //FSXCOMP_FSXLOG_SB_MSG_t SB_CS;
    uint32_t l_poll = 1;

    if (!i_use_scom_path)
    {
        //Applying hreset only when SBE is in Runtime State
        FAPI_INF("Checking if SBE is in Runtime State");
        FAPI_TRY(SB_MSG.getCfam(i_target));

        if (SB_MSG.getBits<8, 4>() == 3)
        {
            FAPI_INF("SBE is in Runtime State");
        }
        else
        {
            FAPI_INF("SBE is in NOT Runtime State");
        }

        FAPI_INF("Resetting restart vector0 and vector1 ...");
        FAPI_TRY(SB_CS.getCfam(i_target));
        SB_CS.set_START_RESTART_VECTOR0(0);
        SB_CS.set_START_RESTART_VECTOR1(0);
        FAPI_TRY(SB_CS.putCfam(i_target));

        FAPI_INF("Applying HRESET ...");
        FAPI_TRY(SB_CS.getCfam(i_target));
        SB_CS.set_START_RESTART_VECTOR1(1);
        FAPI_TRY(SB_CS.putCfam(i_target));

        while(1)
        {
            // delay before polling
            FAPI_TRY(delay(i_boot_parms.poll_delay_ns,
                           i_boot_parms.poll_delay_cycles));

            FAPI_INF("Polling for SBE Boot");
            FAPI_TRY(SB_MSG.getCfam(i_target));

            if (SB_MSG.getBit<0>())
            {
                break;
            }

            // bump count
            l_poll++;

            // test for timeout
            FAPI_ASSERT((l_poll <= i_boot_parms.max_polls),
                        fapi2::SBE_BOOT_CHECK_ERR_CFAM_PATH()
                        .set_TARGET(i_target)
                        .set_SB_MSG(SB_MSG()),
                        //.set_BOOT_TYPE(l_check_for_runtime),
                        "SBE did not Boot up prior to timeout!");
        }
    }

    else
    {
        //Applying hreset only when SBE is in Runtime State
        FAPI_INF("Checking if SBE is in Runtime State");
        FAPI_TRY(SB_MSG.getScom(i_target));

        if (SB_MSG.getBits<8, 4>() == 3)
        {
            FAPI_INF("SBE is in Runtime State");
        }
        else
        {
            FAPI_INF("SBE is in NOT Runtime State");
        }

        FAPI_INF("Resetting restart vector1 ...");
        FAPI_TRY(SB_CS.getScom(i_target));
        SB_CS.set_START_RESTART_VECTOR1(0);
        FAPI_TRY(SB_CS.putScom(i_target));

        FAPI_INF("Applying HRESET ...");
        FAPI_TRY(SB_CS.getScom(i_target));
        SB_CS.set_START_RESTART_VECTOR1(1);
        FAPI_TRY(SB_CS.putScom(i_target));

        while(1)
        {
            // delay before polling
            FAPI_TRY(delay(i_boot_parms.poll_delay_ns,
                           i_boot_parms.poll_delay_cycles));

            FAPI_INF("Polling for SBE Boot");
            FAPI_TRY(SB_MSG.getScom(i_target));

            if (SB_MSG.getBit<0>())
            {
                break;
            }

            // bump count
            l_poll++;

            // test for timeout
            FAPI_ASSERT((l_poll <= i_boot_parms.max_polls),
                        fapi2::SBE_BOOT_CHECK_ERR_SCOM_PATH()
                        .set_TARGET(i_target)
                        .set_SB_MSG(SB_MSG()),
                        //.set_BOOT_TYPE(l_check_for_runtime),
                        "SBE did not Boot up prior to timeout!");
        }

    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return current_err;
}
