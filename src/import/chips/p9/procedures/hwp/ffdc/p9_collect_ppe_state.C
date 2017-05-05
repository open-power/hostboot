/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_collect_ppe_state.C $ */
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
///
/// @file   p9_collect_ppe_state.C
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : HB


#include <fapi2.H>
#include <hwp_error_info.H>
#include <p9_const_common.H>

#include <p9_collect_ppe_state.H>
#include <p9_ppe_state.H>

extern "C"
{
    fapi2::ReturnCode
    p9_collect_ppe_state ( const fapi2::ffdc_t& i_target,
                           const fapi2::ffdc_t& i_v_ppe_addresses,
                           fapi2::ReturnCode& o_rc )
    {
        FAPI_INF (">> p9_collect_ppe_state");
        fapi2::ReturnCode l_rc;

        fapi2::ffdc_t PPE_REG_NR;
        fapi2::ffdc_t PPE_REG_VAL;

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc_chip =
            *(reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> *>
              (i_target.ptr()));

        std::vector<uint64_t> l_ppe_addresses =
            *(reinterpret_cast<const std::vector<uint64_t>*>
              (i_v_ppe_addresses.ptr()));


        PPE_DUMP_MODE l_mode = SNAPSHOT; // halt & restart PPE engine, if needed

        std::vector<PPERegValue_t> l_v_sprs;
        std::vector<PPERegValue_t> l_v_xirs;
        std::vector<PPERegValue_t> l_v_gprs;

        for (auto& it1 : l_ppe_addresses )
        {
            fapi2::ReturnCode l_rc_tmp = fapi2::current_err;

            FAPI_INF ("p9_collect_ppe_state: PPE Base Addr 0x%.16llX, 0x%.8X",
                      it1, l_mode);
            FAPI_EXEC_HWP (l_rc, p9_ppe_state, l_proc_chip, it1, l_mode,
                           l_v_sprs, l_v_xirs, l_v_gprs);

            // Ignore l_rc and continue adding whatever was collected

            // @TODO via RTC: 175232
            // Restore current_err to what was passed in
            fapi2::current_err = l_rc_tmp;

            FAPI_INF ("Adding PPE Addr: 0x%.16llX, SPRs: %d XIRs: %d GPRs: %d",
                      it1, l_v_sprs.size(), l_v_xirs.size(), l_v_gprs.size());

            for (auto& it : l_v_sprs)
            {
                PPE_REG_NR.ptr() = static_cast<void*>(&it.number);
                PPE_REG_NR.size() = sizeof (it.number);

                PPE_REG_VAL.ptr() = static_cast<void*>(&it.value);
                PPE_REG_VAL.size() = sizeof (it.value);

                FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_STATE_DATA_SPR);
            }

            l_v_sprs.clear();

            for (auto& it : l_v_xirs)
            {
                PPE_REG_NR.ptr() = static_cast<void*>(&it.number);
                PPE_REG_NR.size() = sizeof (it.number);

                PPE_REG_VAL.ptr() = static_cast<void*>(&it.value);
                PPE_REG_VAL.size() = sizeof (it.value);

                FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_STATE_DATA_XIR);
            }

            l_v_xirs.clear();

            for (auto& it : l_v_gprs)
            {
                PPE_REG_NR.ptr() = static_cast<void*>(&it.number);
                PPE_REG_NR.size() = sizeof (it.number);

                PPE_REG_VAL.ptr() = static_cast<void*>(&it.value);
                PPE_REG_VAL.size() = sizeof (it.value);

                FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_STATE_DATA_GPR);
            }

            l_v_gprs.clear ();
        }

        FAPI_INF ("<< p9_collect_ppe_state");
        return fapi2::FAPI2_RC_SUCCESS; // always return success
    }
}
