/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_init_done.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#include <p10_scom_pauc.H>
#include <p10_io_init_start_ppe.H>
#include <p10_io_lib.H>

class p10_io_done : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode p10_io_init_done_pon_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);

        fapi2::ReturnCode p10_io_init_done_poff_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);

        fapi2::ReturnCode p10_io_init_done_check_fails(
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

};
///
/// @brief Check done status for reg_init, dccal, lane power on, and fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_pon_check_thread_done(
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

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check done status for reg_init, dccal, lane power on, and fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_poff_check_thread_done(
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

    FAPI_TRY(p10_io_ppe_ext_cmd_done_power_off_pl[i_thread].getData(i_pauc_target, l_data, true));

    FAPI_DBG("Thread: %d, ext_cmd_done_power_off_pl: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Add fail information for any links that did not finish init
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_done::p10_io_init_done_check_fails(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    bool l_done = false;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

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

            FAPI_TRY(p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));


            if (!l_done)
            {
                char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_iohs_target, l_tgt_str, sizeof(l_tgt_str));

                char l_pauc_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_pauc_target, l_pauc_tgt_str, sizeof(l_pauc_tgt_str));


                fapi2::buffer<uint64_t> l_ffdc_thread = l_thread;
                fapi2::buffer<uint64_t> l_ext_cmd_req = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_done = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_00_15 = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_16_31 = 0;
                fapi2::buffer<uint64_t> l_debug_state = 0;
                fapi2::buffer<uint64_t> l_error_state = 0;
                fapi2::buffer<uint64_t> l_error_valid = 0;
                fapi2::buffer<uint64_t> l_error_thread = 0;
                fapi2::buffer<uint64_t> l_error_lane = 0;
                FAPI_TRY(p10_io_ppe_ext_cmd_req[l_thread].getData(l_pauc_target, l_ext_cmd_req, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_done[l_thread].getData(l_pauc_target, l_ext_cmd_done, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_00_15[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_00_15, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_16_31[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_16_31, true));
                FAPI_TRY(p10_io_ppe_ppe_debug_state[l_thread].getData(l_pauc_target, l_debug_state, true));

                FAPI_TRY(p10_io_ppe_ppe_error_state.getData(l_pauc_target, l_error_state, true));
                FAPI_TRY(p10_io_ppe_ppe_error_valid.getData(l_pauc_target, l_error_valid, true));
                FAPI_TRY(p10_io_ppe_ppe_error_thread.getData(l_pauc_target, l_error_thread, true));
                FAPI_TRY(p10_io_ppe_ppe_error_lane.getData(l_pauc_target, l_error_lane, true));

                FAPI_ASSERT(false,
                            fapi2::P10_IO_INIT_DONE_TIMEOUT_ERROR()
                            .set_TARGET(l_iohs_target)
                            .set_THREAD(l_ffdc_thread)
                            .set_EXT_CMD_REQ(l_ext_cmd_req)
                            .set_EXT_CMD_DONE(l_ext_cmd_done)
                            .set_EXT_CMD_LANES_00_15(l_ext_cmd_lanes_00_15)
                            .set_EXT_CMD_LANES_16_31(l_ext_cmd_lanes_16_31)
                            .set_DEBUG_STATE(l_debug_state)
                            .set_ERROR_STATE(l_error_state)
                            .set_ERROR_VALID(l_error_valid)
                            .set_ERROR_THREAD(l_error_thread)
                            .set_ERROR_LANE(l_error_lane),
                            "Timeout waiting for I/O init to complete on %s(%s:thread(%d))",
                            l_tgt_str, l_pauc_tgt_str, l_thread);
                l_rc = fapi2::current_err;
            }
        }

        for (auto l_omic_target : l_omic_targets)
        {
            int l_thread = 0;
            fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omic_target, l_omic_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

            FAPI_TRY(p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));

            if (!l_done)
            {
                char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_omic_target, l_tgt_str, sizeof(l_tgt_str));

                char l_pauc_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
                fapi2::toString(l_pauc_target, l_pauc_tgt_str, sizeof(l_pauc_tgt_str));

                fapi2::buffer<uint64_t> l_ffdc_thread = l_thread;
                fapi2::buffer<uint64_t> l_ext_cmd_req = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_done = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_00_15 = 0;
                fapi2::buffer<uint64_t> l_ext_cmd_lanes_16_31 = 0;
                fapi2::buffer<uint64_t> l_debug_state = 0;
                fapi2::buffer<uint64_t> l_error_state = 0;
                fapi2::buffer<uint64_t> l_error_valid = 0;
                fapi2::buffer<uint64_t> l_error_thread = 0;
                fapi2::buffer<uint64_t> l_error_lane = 0;
                FAPI_TRY(p10_io_ppe_ext_cmd_req[l_thread].getData(l_pauc_target, l_ext_cmd_req, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_done[l_thread].getData(l_pauc_target, l_ext_cmd_done, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_00_15[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_00_15, true));
                FAPI_TRY(p10_io_ppe_ext_cmd_lanes_16_31[l_thread].getData(l_pauc_target, l_ext_cmd_lanes_16_31, true));
                FAPI_TRY(p10_io_ppe_ppe_debug_state[l_thread].getData(l_pauc_target, l_debug_state, true));

                FAPI_TRY(p10_io_ppe_ppe_error_state.getData(l_pauc_target, l_error_state, true));
                FAPI_TRY(p10_io_ppe_ppe_error_valid.getData(l_pauc_target, l_error_valid, true));
                FAPI_TRY(p10_io_ppe_ppe_error_thread.getData(l_pauc_target, l_error_thread, true));
                FAPI_TRY(p10_io_ppe_ppe_error_lane.getData(l_pauc_target, l_error_lane, true));

                FAPI_ASSERT(false,
                            fapi2::P10_IO_INIT_DONE_TIMEOUT_ERROR()
                            .set_TARGET(l_omic_target)
                            .set_THREAD(l_ffdc_thread)
                            .set_EXT_CMD_REQ(l_ext_cmd_req)
                            .set_EXT_CMD_DONE(l_ext_cmd_done)
                            .set_EXT_CMD_LANES_00_15(l_ext_cmd_lanes_00_15)
                            .set_EXT_CMD_LANES_16_31(l_ext_cmd_lanes_16_31)
                            .set_DEBUG_STATE(l_debug_state)
                            .set_ERROR_STATE(l_error_state)
                            .set_ERROR_VALID(l_error_valid)
                            .set_ERROR_THREAD(l_error_thread)
                            .set_ERROR_LANE(l_error_lane),
                            "Timeout waiting for I/O init to complete on %s(%s:thread(%d))",
                            l_tgt_str, l_pauc_tgt_str, l_thread);
                l_rc = fapi2::current_err;
            }
        }
    }

    if (l_rc)
    {
        fapi2::current_err = l_rc;
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
    const uint32_t IO_INIT_DONE_NS_DELAY = 10000000;
    const uint32_t IO_INIT_DONE_CYCLES   = 10000000;
    bool l_done = false;
    p10_io_done l_proc;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    //Poll for done
    int POLLING_LOOPS = 1000;

    fapi2::ATTR_IS_SIMICS_Type l_simics;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_simics),
             "Error from FAPI_ATTR_GET (ATTR_IS_SIMICS)");

    // In simics we don't want to wait a long time since it will either be done or not instantly
    if( l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS )
    {
        POLLING_LOOPS = 2; // using 2 so that we can still get maximum code coverage in the loop
    }

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
                fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_config_mode),
                         "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

                FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

                if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
                {
                    FAPI_TRY(l_proc.p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));
                }
                else if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
                {
                    FAPI_TRY(l_proc.p10_io_init_done_poff_check_thread_done(l_pauc_target, l_thread, l_done));
                }
            }

            for (auto l_omic_target : l_omic_targets)
            {
                int l_thread = 0;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omic_target, l_omic_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

                FAPI_TRY(l_proc.p10_io_init_done_pon_check_thread_done(l_pauc_target, l_thread, l_done));
            }
        }

        fapi2::delay(IO_INIT_DONE_NS_DELAY, IO_INIT_DONE_CYCLES);
    }

    // Avoid failing in Simics until the models get updated
    if( !l_done && (l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS) )
    {
        FAPI_INF("p10_io_init_done> Skipping timeout in Simics");
    }
    else if (!l_done)
    {
        FAPI_TRY(l_proc.p10_io_init_done_check_fails(i_target))
    }

fapi_try_exit:
    return fapi2::current_err;
}
