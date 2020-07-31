/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_init_done.C $   */
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
/// @file p10_io_init_done.C
/// @brief Wait for dccal done and power-up all configured links/lanes
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_init_done.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_scom_pauc_0.H>
#include <p10_io_init_start_ppe.H>
#include <p10_io_lib.H>

class p10_io_done : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode p10_io_init_done_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);

};

///
/// @brief Check done status for reg_init, dccal, lane power on, and fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_check_thread_done(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    bool& o_done)
{
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(p10_io_ppe_ext_cmd_done_hw_reg_init_pg[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_hw_reg_init: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_dccal_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_dccal: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_zcal_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_zcal_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_ffe_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_ffe_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_power_on_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_power_on_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_fifo_init_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_tx_fifo_init_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Wait for dccal done and power-up all configured links/lanes
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init_done(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    bool l_done = false;
    p10_io_done l_proc;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    //Poll for done
    const int POLLING_LOOPS = 200;

    for (int l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        l_done = true;

        for (auto l_pauc_target : l_pauc_targets)
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_pauc_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pauc_target, l_pauc_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
            FAPI_DBG("Getting DCCAL status for PAUC: %d", l_pauc_num);

            auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
            auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();


            for (auto l_iohs_target : l_iohs_targets)
            {
                int l_thread = 0;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

                FAPI_TRY(l_proc.p10_io_init_done_check_thread_done(l_pauc_target, l_thread, l_done ));

            }

            for (auto l_omic_target : l_omic_targets)
            {
                std::vector<int> l_lanes;
                int l_thread = 0;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omic_target, l_omic_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

                FAPI_TRY(l_proc.p10_io_init_done_check_thread_done(l_pauc_target, l_thread, l_done));
            }
        }

        fapi2::delay(100, 10000000);
    }

    FAPI_ASSERT(l_done,
                fapi2::P10_IO_INIT_DONE_TIMEOUT_ERROR()
                .set_TARGET(i_target),
                "Timeout waiting on io init to complete");
fapi_try_exit:
    return fapi2::current_err;
}
