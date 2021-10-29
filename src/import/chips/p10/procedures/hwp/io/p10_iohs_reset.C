/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_iohs_reset.C $     */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_iohs_reset.C
/// @brief Reset the iohs phy
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  :
///-----------------------------------------------------------------------------

#include <p10_iohs_reset.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_scom_pauc_0.H>
#include <p10_io_init_start_ppe.H>
#include <p10_io_lib.H>
#include <p10_scom_iohs.H>
// *!    // Make sure the DL is in reset before running this procedure
// *!    // so that we know the rx_run_lane_* signal inputs are 0.
// *!
// *!    // Clear external command request / done registers
// *!    Write ext_cmd_req = 0x0000
// *!    Write ext_cmd_done = 0x0000
// *!
// *!    // Write the external command lanes to target
// *!    Write ext_cmd_lanes_00_15 = lane_vec_0_15
// *!    Write ext_cmd_lanes_16_31 = lane_vec_16_31
// *!
// *!    // Initialize PHY Lanes
// *!    data = ext_cmd_req_ioreset_pl
// *!    data |= ext_cmd_req_dccal_pl
// *!    data |= ext_cmd_req_tx_zcal_pl
// *!    data |= ext_cmd_req_tx_ffe_pl
// *!    data |= ext_cmd_req_power_on_pl
// *!
// *!    // Poll for done in the IO_INIT_DONE procedure

class p10_iohs_reset_cls : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode p10_iohs_reset_flush_fw_regs();
        fapi2::ReturnCode p10_iohs_reset_ext_req_set_lane_bits(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
                const std::vector<int>& i_lanes,
                const int& i_thread);
        fapi2::ReturnCode p10_iohs_ext_req_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
                const uint8_t i_half);
        fapi2::ReturnCode p10_iolink_reset_ext_req_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_target);
        fapi2::ReturnCode p10_iohs_clear_ext_cmd(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target);
        fapi2::ReturnCode p10_iohs_reset_start(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target);
        fapi2::ReturnCode p10_iohs_init_settings(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target);
        fapi2::ReturnCode p10_iohs_init_start(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target);
        fapi2::ReturnCode p10_iohs_init_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);
        fapi2::ReturnCode p10_iohs_reset_check_thread_done(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            bool& o_done);

};


///
/// @brief Flushes the fw_regs cached values
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_reset_flush_fw_regs()
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
/// @brief Set the lane bits for each target
///
/// @param[in] i_pauc_target The PAUC to to set lane bits for
/// @param[in] i_lanes A vector of lanes configured
/// @param[in] i_thread The thread to set lane bits for
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_reset_ext_req_set_lane_bits(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>&
        i_pauc_target,
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
/// @brief Set the lane bits for each target and write them to the chip
///
/// @param[in] i_target Iolink target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iolink_reset_ext_req_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>&
        i_target)
{
    FAPI_DBG("Begin");
    auto l_iohs_target = i_target.getParent<fapi2::TARGET_TYPE_IOHS>();
    auto l_pauc_target = l_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    std::vector<int> l_lanes;
    int l_thread = 0;

    FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

    FAPI_TRY(p10_io_get_iolink_lanes(i_target, l_lanes));

    FAPI_TRY(p10_iohs_reset_ext_req_set_lane_bits(l_pauc_target, l_lanes, l_thread));

    //Write cached values to the chip
    FAPI_TRY(p10_iohs_reset_flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
///
/// @brief Set the lane bits for each target and write them to the chip
///
/// @param[in] i_target Chip target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_ext_req_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&
        i_target,
        const uint8_t i_half)
{
    FAPI_DBG("Begin");
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    std::vector<int> l_lanes;
    int l_thread = 0;

    FAPI_TRY(p10_io_get_iohs_thread(i_target, l_thread));

    if (i_half == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
    {
        FAPI_TRY(p10_io_get_iohs_lanes(i_target, l_lanes));
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_iolink_target;
        bool l_found = false;

        for (auto l_iolink : i_target.getChildren<fapi2::TARGET_TYPE_IOLINK>())
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iolink, l_unit_pos));

            if ((i_half == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY) && ((l_unit_pos % 2) == 0))
            {
                l_found = true;
                l_iolink_target = l_iolink;
                break;
            }
            else if ((i_half == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY) && ((l_unit_pos % 2) == 1))
            {
                l_found = true;
                l_iolink_target = l_iolink;
                break;
            }
        }

        FAPI_ASSERT(l_found,
                    fapi2::P10_IOHS_RESET_IOLINK_SEARCH_ERR()
                    .set_IOHS_TARGET(i_target)
                    .set_HALF(i_half),
                    "No IOLINK target found to match requested link half!");

        FAPI_TRY(p10_io_get_iolink_lanes(l_iolink_target, l_lanes));
    }

    FAPI_TRY(p10_iohs_reset_ext_req_set_lane_bits(l_pauc_target, l_lanes, l_thread));

    //Write cached values to the chip
    FAPI_TRY(p10_iohs_reset_flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Clears ext_cmd regs
///
/// @param[in] i_target IOHS Target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_clear_ext_cmd(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&
        i_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::pauc;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    int l_thread;
    FAPI_TRY(p10_io_get_iohs_thread(i_target, l_thread));

    FAPI_TRY(p10_io_ppe_ext_cmd_req[l_thread].putData(l_pauc_target, 0));

    // Flush the data to the sram
    FAPI_TRY(p10_iohs_reset_flush_fw_regs());

    FAPI_TRY(p10_io_ppe_ext_cmd_done[l_thread].putData(l_pauc_target, 0));

    // Flush the data to the sram
    FAPI_TRY(p10_iohs_reset_flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Starts iohs phy reset
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_reset_start(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::pauc;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    int l_thread;
    FAPI_TRY(p10_io_get_iohs_thread(i_target, l_thread));

    FAPI_TRY(p10_io_ppe_ext_cmd_req_ioreset_pl[l_thread].putData(l_pauc_target, 1));

    // Flush the data to the sram
    FAPI_TRY(p10_iohs_reset_flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Starts iohs phy init
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_init_settings(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target)
{
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data64;
    using namespace scomt::iohs;

    FAPI_TRY(GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG(i_target, l_data64));
    SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1(1, l_data64);
    SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2(2, l_data64);
    FAPI_TRY(PUT_IOO_RX0_RXCTL_CTL_REGS_RX_MODE16_PG(i_target, l_data64));

    FAPI_TRY(GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(i_target, l_data64));
    SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(3, l_data64);
    SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(7, l_data64);
    FAPI_TRY(PUT_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(i_target, l_data64));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Starts iohs phy init
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_init_start(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::pauc;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    int l_thread;
    FAPI_TRY(p10_io_get_iohs_thread(i_target, l_thread));

    FAPI_TRY(p10_io_ppe_ext_cmd_req_dccal_pl[l_thread].putData(l_pauc_target, 1));
    FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_zcal_pl[l_thread].putData(l_pauc_target, 1));
    FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_ffe_pl[l_thread].putData(l_pauc_target, 1));
    FAPI_TRY(p10_io_ppe_ext_cmd_req_power_on_pl[l_thread].putData(l_pauc_target, 1));

    // Flush the data to the sram
    FAPI_TRY(p10_iohs_reset_flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Check done status for dccal, lane power on, and fifo init for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_init_check_thread_done(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    bool& o_done)
{
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(p10_io_ppe_ext_cmd_done_dccal_pl[i_thread].getData(i_pauc_target, l_data, true));
    FAPI_DBG("Thread: %d, ext_cmd_done_dccal: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_zcal_pl[i_thread].getData(i_pauc_target, l_data, true));
    FAPI_DBG("Thread: %d, ext_cmd_done_tx_zcal: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_tx_ffe_pl[i_thread].getData(i_pauc_target, l_data, true));
    FAPI_DBG("Thread: %d, ext_cmd_done_tx_ffe: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }

    FAPI_TRY(p10_io_ppe_ext_cmd_done_power_on_pl[i_thread].getData(i_pauc_target, l_data, true));
    FAPI_DBG("Thread: %d, ext_cmd_done_power_on: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }


fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Check done status for reset for a thread
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[out] o_done Set to false if something isn't done
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset_cls::p10_iohs_reset_check_thread_done(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    bool& o_done)
{
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_TRY(p10_io_ppe_ext_cmd_done_ioreset_pl[i_thread].getData(i_pauc_target, l_data, true));
    FAPI_DBG("Thread: %d, ext_cmd_done_ioreset: 0x%llx", i_thread, l_data);

    if (l_data == 0)
    {
        o_done = false;
    }


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the IOHS phy
///
/// @param[in] i_target IOHS target to reset
/// @param[in] i_half odd/even/both
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_init(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target, const uint8_t i_half)
{
    FAPI_DBG("Start");

    bool l_done = false;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    //Poll for done
    const int POLLING_LOOPS = 6000; // wait 60s, manual servo op can take up to 50s to finish
    int l_try = 0;
    p10_iohs_reset_cls l_p;

    FAPI_TRY(l_p.p10_iohs_clear_ext_cmd(i_target));
    FAPI_TRY(l_p.p10_iohs_ext_req_lanes(i_target, i_half));
    FAPI_TRY(l_p.p10_iohs_init_settings(i_target));
    FAPI_TRY(l_p.p10_iohs_init_start(i_target));

    for (l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        l_done = true;

        int l_thread = 0;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iohs_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        FAPI_TRY(p10_io_get_iohs_thread(i_target, l_thread));

        FAPI_TRY(l_p.p10_iohs_init_check_thread_done(l_pauc_target, l_thread, l_done));

        fapi2::delay(10000000, 10000000);
    }

    FAPI_ASSERT(l_done,
                fapi2::P10_IOHS_INIT_TIMEOUT_ERROR()
                .set_TARGET(i_target)
                .set_HALF(i_half),
                "Timeout waiting on iohs_init to complete");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Reset the IOLINK phy -- keeps the iolink in reset
///
/// @param[in] i_target Iolink target to reset
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iolink_reset( const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink)
{
    FAPI_DBG("Start");

    auto l_iohs_target = i_iolink.getParent<fapi2::TARGET_TYPE_IOHS>();
    auto l_pauc_target = l_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    bool l_done = false;
    const int POLLING_LOOPS = 6000; // wait 60s, manual servo op can take up to 50s to finish
    int l_try = 0;
    p10_iohs_reset_cls l_p;

    FAPI_TRY(l_p.p10_iohs_clear_ext_cmd(l_iohs_target));
    FAPI_TRY(l_p.p10_iolink_reset_ext_req_lanes(i_iolink));
    FAPI_TRY(l_p.p10_iohs_reset_start(l_iohs_target));

    for (l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        l_done = true;

        int l_thread = 0;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

        FAPI_TRY(l_p.p10_iohs_reset_check_thread_done(l_pauc_target, l_thread, l_done));

        fapi2::delay(10000000, 10000000);
    }

    FAPI_ASSERT(l_done,
                fapi2::P10_IOHS_RESET_TIMEOUT_ERROR()
                .set_TARGET(i_iolink),
                "Timeout waiting on iolink_reset to complete");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Reset the IOLINK phy -- keeps the iolink in reset
///
/// @param[in] i_target Iolink target to reset
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_reset( const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs)
{
    FAPI_DBG("Start");

    auto l_pauc_target = i_iohs.getParent<fapi2::TARGET_TYPE_PAUC>();

    bool l_done = false;
    const int POLLING_LOOPS = 6000; // wait 60s, manual servo op can take up to 50s to finish
    int l_try = 0;
    p10_iohs_reset_cls l_p;

    auto l_iolink_targets = i_iohs.getChildren<fapi2::TARGET_TYPE_IOLINK>();

    for (const auto l_iolink_target : l_iolink_targets)
    {

        FAPI_TRY(l_p.p10_iohs_clear_ext_cmd(i_iohs));
        FAPI_TRY(l_p.p10_iolink_reset_ext_req_lanes(l_iolink_target));
        FAPI_TRY(l_p.p10_iohs_reset_start(i_iohs));

        for (l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
        {
            l_done = true;

            int l_thread = 0;
            fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs, l_iohs_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(p10_io_get_iohs_thread(i_iohs, l_thread));

            FAPI_TRY(l_p.p10_iohs_reset_check_thread_done(l_pauc_target, l_thread, l_done));

            fapi2::delay(10000000, 10000000);
        }

        FAPI_ASSERT(l_done,
                    fapi2::P10_IOHS_RESET_TIMEOUT_ERROR()
                    .set_TARGET(i_iohs),
                    "Timeout waiting on iohs_reset to complete");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
