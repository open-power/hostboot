/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_power.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_io_power.C
/// @brief I/O Power Functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_power.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_scom_pauc.H>
#include <p10_io_lib.H>

class p10_io_power : public p10_io_ppe_cache_proc
{
    private:
        fapi2::ReturnCode p10_io_power_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            const bool& i_on,
            bool& o_done);


    public:
        fapi2::ReturnCode flush_fw_regs();

        fapi2::ReturnCode ext_req_clear(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
                                        const int& i_thread);

        fapi2::ReturnCode ext_req_set_lane_bits(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const std::vector<int>& i_lanes,
            const int& i_thread);

        fapi2::ReturnCode p10_io_power_start(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            const bool& i_on);

        fapi2::ReturnCode p10_io_power_poll(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            const bool& i_on);

};

///
/// @brief Check done status for lane power on and tx fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_power::p10_io_power_check_thread_done(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    const bool& i_on,
    bool& o_done)
{
    fapi2::buffer<uint64_t> l_data = 0;

    if (i_on)
    {
        FAPI_TRY(p10_io_ppe_ext_cmd_done_power_on_pl[i_thread].getData(i_pauc_target, l_data, true));

        FAPI_DBG("Thread: %d, ext_cmd_done_power_on_pl: 0x%llx", i_thread, l_data);

        if (l_data == 0)
        {
            o_done = false;
        }

        FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_fifo_init_pl[i_thread].getData(i_pauc_target, l_data, true));

        FAPI_DBG("Thread: %d, ext_cmd_done_power_on_pl: 0x%llx", i_thread, l_data);

        if (l_data == 0)
        {
            o_done = false;
        }
    }
    else
    {
        FAPI_TRY(p10_io_ppe_ext_cmd_done_power_off_pl[i_thread].getData(i_pauc_target, l_data, true));

        FAPI_DBG("Thread: %d, ext_cmd_done_power_off_pl: 0x%llx", i_thread, l_data);

        if (l_data == 0)
        {
            o_done = false;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Flushes the fw_regs cached values
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_power::flush_fw_regs()
{
    FAPI_DBG("Begin");

    for (auto i = 0; i < P10_IO_LIB_NUMBER_OF_THREADS; i++)
    {
        FAPI_TRY(p10_io_ppe_fw_regs[i].flush());
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Set the lane bits for each target and write them to the chip
///
/// @param[in] i_iohs_target Iohs target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_power(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target, const bool& i_on)
{
    std::vector<int> l_lanes;
    int l_thread = 0;
    p10_io_power l_proc;

    auto l_pauc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    FAPI_TRY(p10_io_get_iohs_thread(i_iohs_target, l_thread));
    FAPI_DBG("Starting Power On/Off for IOHS thread %d", l_thread);

    FAPI_TRY(l_proc.ext_req_clear(l_pauc_target, l_thread));

    FAPI_TRY(p10_io_get_iohs_lanes(i_iohs_target, l_lanes));

    FAPI_TRY(l_proc.ext_req_set_lane_bits(l_pauc_target, l_lanes, l_thread));

    FAPI_TRY(l_proc.p10_io_power_start(l_pauc_target, l_thread, i_on));

    //Write cached values to the chip
    FAPI_TRY(l_proc.flush_fw_regs());

    FAPI_TRY(l_proc.p10_io_power_poll(l_pauc_target, l_thread, i_on));


fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Set the lane bits for each target and write them to the chip
///
/// @param[in] i_omic_target Omic target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_omic_power(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target, const bool& i_on)
{
    std::vector<int> l_lanes;
    int l_thread = 0;
    p10_io_power l_proc;

    auto l_pauc_target = i_omic_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    FAPI_TRY(p10_io_get_omic_thread(i_omic_target, l_thread));
    FAPI_DBG("Starting Power On/Off for OMIC thread %d", l_thread);

    FAPI_TRY(l_proc.ext_req_clear(l_pauc_target, l_thread));

    FAPI_TRY(p10_io_get_omic_lanes(i_omic_target, l_lanes));

    FAPI_TRY(l_proc.ext_req_set_lane_bits(l_pauc_target, l_lanes, l_thread));

    FAPI_TRY(l_proc.p10_io_power_start(l_pauc_target, l_thread, i_on));

    //Write cached values to the chip
    FAPI_TRY(l_proc.flush_fw_regs());

    FAPI_TRY(l_proc.p10_io_power_poll(l_pauc_target, l_thread, i_on));


fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Set the lane bits for each target
///
/// @param[in] i_pauc_target The PAUC to to set lane bits for
/// @param[in] i_thread The thread to set lane bits for
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_power::ext_req_clear(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
        const int& i_thread)
{
    FAPI_DBG("Begin");

    FAPI_TRY(p10_io_ppe_ext_cmd_lanes_00_15[i_thread].putData(i_pauc_target, 0));
    FAPI_TRY(p10_io_ppe_ext_cmd_lanes_16_31[i_thread].putData(i_pauc_target, 0));
    FAPI_TRY(p10_io_ppe_ext_cmd_req[i_thread].putData(i_pauc_target, 0));
    FAPI_TRY(flush_fw_regs());

    FAPI_TRY(p10_io_ppe_ext_cmd_done[i_thread].putData(i_pauc_target, 0));
    FAPI_TRY(flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Set the lane bits for each target
///
/// @param[in] i_pauc_target The PAUC to to set lane bits for
/// @param[in] i_lanes A vector of lanes configured
/// @param[in] i_thread The thread to set lane bits for
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_power::ext_req_set_lane_bits(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
        const std::vector<int>& i_lanes,
        const int& i_thread)
{
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_lane_bits_00_15;
    fapi2::buffer<uint64_t> l_lane_bits_16_31;

    //Set bits for each lane
    for (int l_lane : i_lanes)
    {
        if (l_lane < 16)
        {
            l_lane_bits_00_15.setBit(48 + l_lane);
        }
        else
        {
            l_lane_bits_16_31.setBit(48 + (l_lane - 16));
        }
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_lanes_00_15[i_thread]
             .putData(i_pauc_target, l_lane_bits_00_15));
    FAPI_TRY(p10_io_ppe_ext_cmd_lanes_16_31[i_thread]
             .putData(i_pauc_target, l_lane_bits_16_31));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Set the ext_cmd_req bits for power_on and tx_fifo_init or power_off
///
/// @param[in] i_pauc_target Pauc target to work with
/// @param[in] i_thread The thread to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_power::p10_io_power_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    const bool& i_on)
{
    FAPI_DBG("Begin");

    if (i_on)
    {
        FAPI_TRY(p10_io_ppe_ext_cmd_req_power_on_pl[i_thread].putData(i_pauc_target, 1));
        FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_fifo_init_pl[i_thread].putData(i_pauc_target, 1));
    }
    else
    {
        FAPI_TRY(p10_io_ppe_ext_cmd_req_power_off_pl[i_thread].putData(i_pauc_target, 1));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Wait for power-on/off of selected links/lanes
///
/// @param[in] i_pauc_target Pauc target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_power::p10_io_power_poll(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    const bool& i_on)
{
    bool l_done = false;

    //Poll for done
    const int POLLING_LOOPS = 200;

    for (int l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        l_done = true;

        fapi2::ATTR_CHIP_UNIT_POS_Type l_pauc_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_pauc_target, l_pauc_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        FAPI_DBG("Getting Power(%d) status for PAUC: %d", i_on, l_pauc_num);

        FAPI_TRY(p10_io_power_check_thread_done(i_pauc_target, i_thread, i_on, l_done ));

        fapi2::delay(100, 10000000);
    }

    FAPI_ASSERT(l_done,
                fapi2::P10_IO_POWER_ON_OFF_TIMEOUT_ERROR()
                .set_TARGET(i_pauc_target),
                "Timeout waiting on power on/off to complete");
fapi_try_exit:
    return fapi2::current_err;
}
