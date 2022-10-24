/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_init_start_ppe.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_io_init_start_ppe.C
/// @brief Start PHY PPE's and begin bringing up configured lanes/links
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_init_start_ppe.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_scom_pauc.H>
#include <p10_scom_iohs.H>
#include <p10_scom_omi.H>
#include <p10_io_lib.H>

class p10_io_init : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode lane_reversal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
        fapi2::ReturnCode lane_bad_threshold(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
        fapi2::ReturnCode flush_mem_regs();
        fapi2::ReturnCode flush_fw_regs();
        fapi2::ReturnCode disable_bad_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target);
        fapi2::ReturnCode init_regs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
        fapi2::ReturnCode img_regs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
        fapi2::ReturnCode sim_speedup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
        fapi2::ReturnCode ext_req_all(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
        fapi2::ReturnCode ext_req_set_lane_bits(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
                                                const std::vector<int>& i_lanes,
                                                const int& i_thread);
        fapi2::ReturnCode ext_req_lanes(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
};

///
/// @brief Setup lane reversal as needed prior to init.
///
/// @param[in] i_target Chip target to setup
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::lane_reversal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data;
    using namespace scomt::iohs;
    auto l_iohs_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>();

    for (auto l_iohs_target : l_iohs_targets)
    {
        fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL_Type l_lane_reversal;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL, l_iohs_target, l_lane_reversal),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_FABRIC_LANE_REVERSAL)");
        FAPI_TRY(GET_DLP_OPTICAL_CONFIG(l_iohs_target, l_data));
        SET_DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP((l_lane_reversal & 0x80) >> 7, l_data);
        SET_DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP((l_lane_reversal & 0x40) >> 6, l_data);
        SET_DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP((l_lane_reversal & 0x20) >> 5, l_data);
        SET_DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP((l_lane_reversal & 0x10) >> 4, l_data);
        SET_DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP((l_lane_reversal & 0x08) >> 3, l_data);
        FAPI_TRY(PUT_DLP_OPTICAL_CONFIG(l_iohs_target, l_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup lane bad threshold as needed prior to init.
///
/// @param[in] i_target Chip target to setup
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::lane_bad_threshold(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data;
    using namespace scomt::iohs;
    auto l_iohs_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>();

    fapi2::ATTR_MFG_FLAGS_Type l_mfg_flags = {0};

    fapi2::ATTR_IOHS_MNFG_BAD_LANE_MAX_Type l_mnfg_bad_lane_max = 0;
    fapi2::ATTR_IOHS_MNFG_BAD_LANE_DURATION_Type l_mnfg_bad_lane_duration = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags) );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MNFG_BAD_LANE_MAX, i_target, l_mnfg_bad_lane_max),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_MNFG_BAD_LANE_MAX)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MNFG_BAD_LANE_DURATION, i_target, l_mnfg_bad_lane_duration),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_MNFG_BAD_LANE_DURATION)");

    for (auto l_iohs_target : l_iohs_targets)
    {
        if (l_mfg_flags[fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS / 32] & (1 << (31 -
                (fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS % 32))))
        {
            FAPI_DBG("Setting IOHS bad_lane_max to %d", l_mnfg_bad_lane_max);
            FAPI_DBG("Setting IOHS bad_lane_duration to %d", l_mnfg_bad_lane_duration);
            FAPI_TRY(GET_DLP_OPTICAL_CONFIG(l_iohs_target, l_data));
            SET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX(l_mnfg_bad_lane_max, l_data);
            SET_DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION(l_mnfg_bad_lane_duration, l_data);
            FAPI_TRY(PUT_DLP_OPTICAL_CONFIG(l_iohs_target, l_data));
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Flushes the mem_regs cached values
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::flush_mem_regs()
{
    FAPI_DBG("Begin");

    for (auto i = 0; i < P10_IO_LIB_NUMBER_OF_THREADS; i++)
    {
        FAPI_TRY(p10_io_ppe_mem_regs[i].flush());
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Flushes the fw_regs cached values
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::flush_fw_regs()
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
/// @brief Setup threads, gcr_ids, serdies, number of lanes, and start ppes
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::img_regs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data = 0;
    using namespace scomt::pauc;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    fapi2::ATTR_OMI_SPREAD_SPECTRUM_Type l_omi_ss;
    fapi2::ATTR_IOHS_SPREAD_SPECTRUM_Type l_iohs_ss;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_SPREAD_SPECTRUM, i_target, l_omi_ss),
             "Error from FAPI_ATTR_GET (ATTR_OMI_SPREAD_SPECTRUM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_SPREAD_SPECTRUM, i_target, l_iohs_ss),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_SPREAD_SPECTRUM)");

    for (auto l_pauc_target : l_pauc_targets)
    {
        bool l_enable_fir = false;
        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        // 0x00: > 900mv
        // 0x01: > 850mv & <= 900mv
        // 0x10: > 800mv & <= 850mv
        // 0x11: <= 800mv
        p10_io_ppe_ppe_vio_volts.putData(l_pauc_target, 0x1);

        //Note the supervisor thread does not +1 to the ppe_num_threads. (as of 7/9/2019)
        FAPI_TRY(p10_io_ppe_ppe_num_threads.putData(l_pauc_target, P10_IO_LIB_NUMBER_OF_THREADS));

        //Set the GCR for all threads and set stop_thread for all of them
        //Bellow we turn off stop_thread for configured
        for (int l_gcr_thrd = 0; l_gcr_thrd < P10_IO_LIB_NUMBER_OF_THREADS; l_gcr_thrd++)
        {
            //Set the gcr bus id for this thread.
            FAPI_TRY(p10_io_ppe_fw_gcr_bus_id[l_gcr_thrd].putData(l_pauc_target, l_gcr_thrd));
            FAPI_TRY(p10_io_ppe_fw_stop_thread[l_gcr_thrd].putData(l_pauc_target, 1));
        }


        for (auto l_iohs_target : l_iohs_targets)
        {
            fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
            int l_num_lanes = P10_IO_LIB_NUMBER_OF_IOHS_LANES;
            int l_thread = 0;

            FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));
            FAPI_DBG("Setting number of lanes and turning off stop_thread for IOHS thread %d", l_thread);

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_config_mode),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

            //Enable spread spectrum
            FAPI_TRY(p10_io_ppe_fw_spread_en[l_thread].putData(l_pauc_target, l_iohs_ss));

            //Set the number of lanes
            FAPI_TRY(p10_io_ppe_fw_num_lanes[l_thread].putData(l_pauc_target, l_num_lanes));

            //Set the serdes_16_to_1
            FAPI_TRY(p10_io_ppe_fw_serdes_16_to_1_mode[l_thread].putData(l_pauc_target, P10_IO_PPE_IOHS_SERDES_16_TO_1));

            //Turn off stop_thread
            FAPI_TRY(p10_io_ppe_fw_stop_thread[l_thread].putData(l_pauc_target, 0));

            //if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX ||
            //    l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
            //{
            //    FAPI_DBG("Found Xbus IOHS thread %d", l_thread);
            //    l_enable_fir = true;
            //}
            if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
            {
                FAPI_DBG("Found Xbus IOHS thread %d", l_thread);
                l_enable_fir = true;
            }

            if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
            {
                FAPI_DBG("Found Abus IOHS thread %d", l_thread);
                l_enable_fir = true;
            }

        }

        for (auto l_omic_target : l_omic_targets)
        {
            int l_thread;
            auto l_omi_targets = l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();
            int l_num_lanes = P10_IO_LIB_NUMBER_OF_OMIC_LANES;

            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));
            FAPI_DBG("Setting number of lanes and turning off stop_thread for OMIC thread %d", l_thread);

            //Enable spread spectrum
            FAPI_TRY(p10_io_ppe_fw_spread_en[l_thread].putData(l_pauc_target, l_omi_ss));

            //Set the number of lanes
            FAPI_TRY(p10_io_ppe_fw_num_lanes[l_thread].putData(l_pauc_target, l_num_lanes));

            //Set the serdes_16_to_1
            FAPI_TRY(p10_io_ppe_fw_serdes_16_to_1_mode[l_thread].putData(l_pauc_target, P10_IO_PPE_OMIC_SERDES_16_TO_1));

            //Turn off stop_thread
            FAPI_TRY(p10_io_ppe_fw_stop_thread[l_thread].putData(l_pauc_target, 0));

            for (auto l_omi_target : l_omi_targets)
            {
                auto l_ocmbs = l_omi_target.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();

                if (l_ocmbs.size() > 0)
                {
                    FAPI_DBG("Found OCMB Child on OMIC thread %d", l_thread);
                    l_enable_fir = true;
                }
            }
        }

        // Flush the data to the sram
        FAPI_TRY(p10_io_ppe_img_regs.flush());
        FAPI_TRY(flush_fw_regs());

        // Enable SRAM Scrubbing
        FAPI_TRY(GET_PHY_PPE_WRAP_ARB_CSCR_RW(l_pauc_target, l_data));
        SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE(1, l_data);
        FAPI_TRY(PUT_PHY_PPE_WRAP_ARB_CSCR_RW(l_pauc_target, l_data));

        // Start the ppe's
        FAPI_TRY(PREP_PHY_PPE_WRAP_XIXCR(l_pauc_target));
        SET_PHY_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(6, l_data); //Hard reset
        FAPI_TRY(PUT_PHY_PPE_WRAP_XIXCR(l_pauc_target, l_data));

        SET_PHY_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(2, l_data); //Resume
        FAPI_TRY(PUT_PHY_PPE_WRAP_XIXCR(l_pauc_target, l_data));

        // Clear PPE Halted FIR
        FAPI_TRY(GET_PHY_SCOM_MAC_FIR_REG_RW(l_pauc_target, l_data));
        SET_PHY_SCOM_MAC_FIR_REG_PPE_HALTED(0, l_data);
        FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_REG_RW(l_pauc_target, l_data));

        if (l_enable_fir)
        {
            const uint64_t l_phy_fir_mask_ppe_and = 0xFF00000000000000;
            const uint64_t l_phy_fir_mask_ppe_or  = 0x00002EC000000000;

            FAPI_TRY(GET_PHY_SCOM_MAC_FIR_MASK_REG_RW(l_pauc_target, l_data),
                     "Error from getScom (PHY_SCOM_MAC_FIR_MASK_REG_RW)");

            l_data &= l_phy_fir_mask_ppe_and;
            l_data |= l_phy_fir_mask_ppe_or;

            FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_RW(l_pauc_target, l_data),
                     "Error from putScom (PHY_SCOM_MAC_FIR_MASK_REG_RW)");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Disable bad lanes
///
/// @param[in] i_iohs_target target to disable bad lanes
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::disable_bad_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::pauc;
    using namespace scomt::iohs;

    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_Type l_bad_valid;
    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_Type l_bad_vec;
    int l_thread = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_pauc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    FAPI_TRY(p10_io_get_iohs_thread(i_iohs_target, l_thread));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID, i_iohs_target, l_bad_valid),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_MFG_BAD_LANE_VEC_VALID)");

    if (l_bad_valid == fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_TRUE)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC, i_iohs_target, l_bad_vec),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_MFG_BAD_LANE_VEC)");

        if (l_bad_vec != 0)
        {
            uint32_t l_mask = 0x80000000;

            for (int l_lane = 0; l_lane < P10_IO_LIB_NUMBER_OF_IOHS_LANES; l_lane++)
            {
                if ((l_mask & l_bad_vec) == l_mask)
                {

                    FAPI_TRY(p10_io_iohs_put_pl_regs_single(i_iohs_target,
                                                            IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_MODE1_PL,
                                                            IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
                                                            1,
                                                            l_lane,
                                                            1));

                    FAPI_TRY(p10_io_iohs_put_pl_regs_single(i_iohs_target,
                                                            IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL,
                                                            IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_INIT_DONE,
                                                            1,
                                                            l_lane,
                                                            1));

                    FAPI_TRY(p10_io_ppe_rx_recal_abort[l_thread].putData(l_pauc_target, 1, l_lane));

                }

                l_mask >>= 1;
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup custom init settings for the mem regs
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::init_regs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::pauc;
    using namespace scomt::iohs;
    using namespace scomt::omi;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();
    fapi2::buffer<uint64_t> l_data;

    fapi2::ATTR_FREQ_OMI_MHZ_Type l_omi_freq;
    fapi2::ATTR_FREQ_IOHS_LINK_MHZ_Type l_iohs_freq;
    fapi2::ATTR_CHIP_EC_FEATURE_HW550299_Type l_hw550299;
    fapi2::ATTR_CHIP_EC_FEATURE_HW539048_Type l_hw539048;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW550299, i_target, l_hw550299),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW550299)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_omi_freq),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_OMI_MHZ)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW539048, i_target, l_hw539048),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW539048)");


    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();


        for (auto l_iohs_target : l_iohs_targets)
        {
            int l_num_lanes = P10_IO_LIB_NUMBER_OF_IOHS_LANES;
            int l_thread = 0;
            fapi2::ATTR_IO_IOHS_CHANNEL_LOSS_Type l_loss;
            fapi2::ATTR_IO_IOHS_XTALK_Type l_xtalk;
            fapi2::ATTR_IO_IOHS_PRE1_Type l_pre1;
            fapi2::ATTR_IO_IOHS_PRE2_Type l_pre2;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_IOHS_PRE1, l_iohs_target, l_pre1),
                     "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_PRE1)");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_IOHS_PRE2, l_iohs_target, l_pre2),
                     "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_PRE2)");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_IOHS_CHANNEL_LOSS, l_iohs_target, l_loss),
                     "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_CHANNEL_LOSS)");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_IOHS_XTALK, l_iohs_target, l_xtalk),
                     "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_CHANNEL_XTALK)");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_LINK_MHZ, l_iohs_target, l_iohs_freq),
                     "Error from FAPI_ATTR_GET (ATTR_FREQ_IOHS_LINK_MHZ)");


            FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));
            FAPI_DBG("Setting number of lanes and turning off stop_thread for IOHS thread %d", l_thread);

            uint32_t l_ppe_channel_loss = 0;

            if (l_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_MID_LOSS)
            {
                l_ppe_channel_loss = 1;
            }
            else if (l_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_LOW_LOSS)
            {
                l_ppe_channel_loss = 2;
            }

            uint32_t l_ppe_data_rate = 0;

            if (l_iohs_freq == fapi2::ENUM_ATTR_FREQ_IOHS_LINK_MHZ_25781)
            {
                l_ppe_data_rate = 1;
            }
            else if (l_iohs_freq >= fapi2::ENUM_ATTR_FREQ_IOHS_LINK_MHZ_31875)
            {
                l_ppe_data_rate = 2;
            }

            FAPI_DBG("Setting IOHS data rate variable(%d) based on freq(%d)", l_ppe_data_rate, l_iohs_freq);


            if (l_ppe_data_rate <= 1)
            {
                // Peaking
                FAPI_TRY(p10_io_ppe_ppe_ctle_peak1_disable[l_thread].putData(l_pauc_target, 0x1));

                // RX A CTLE_PEAK1
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN,
                                                 l_num_lanes,
                                                 4));

                // RX B CTLE_PEAK1
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN,
                                                 l_num_lanes,
                                                 4));
            }

            // LTE Gain/Zero
            FAPI_TRY(p10_io_ppe_ppe_lte_gain_disable[l_thread].putData(l_pauc_target, 0x1));
            FAPI_TRY(p10_io_ppe_ppe_lte_zero_disable[l_thread].putData(l_pauc_target, 0x1));

            // RX A LTE_GAIN
            FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN,
                                             l_num_lanes,
                                             7));

            // RX B LTE_GAIN
            FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN,
                                             l_num_lanes,
                                             7));

            if (l_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_LOW_LOSS
                || l_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_MID_LOSS)
            {

                // RX A LTE_ZERO
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN,
                                                 l_num_lanes,
                                                 1));

                // RX B LTE_ZERO
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN,
                                                 l_num_lanes,
                                                 1));

            }
            else
            {
                // RX A LTE_ZERO
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN,
                                                 l_num_lanes,
                                                 3));

                // RX B LTE_ZERO
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN,
                                                 l_num_lanes,
                                                 3));
            }

            if (l_loss == fapi2::ENUM_ATTR_IO_IOHS_CHANNEL_LOSS_MID_LOSS)
            {
                // Peaking
                FAPI_TRY(p10_io_ppe_ppe_ctle_peak2_disable[l_thread].putData(l_pauc_target, 0x1));

                // RX A CTLE_PEAK1
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN,
                                                 l_num_lanes,
                                                 0));

                // RX B CTLE_PEAK1
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN,
                                                 l_num_lanes,
                                                 0));
            }

            FAPI_TRY(p10_io_ppe_tx_ffe_pre1_coef[l_thread].putData(l_pauc_target, l_pre1));
            FAPI_TRY(p10_io_ppe_tx_ffe_pre2_coef[l_thread].putData(l_pauc_target, l_pre2));

            FAPI_TRY(p10_io_ppe_ppe_data_rate[l_thread].putData(l_pauc_target, l_ppe_data_rate));
            FAPI_TRY(p10_io_ppe_ppe_channel_loss[l_thread].putData(l_pauc_target, l_ppe_channel_loss));


            if (l_hw539048)
            {
                FAPI_TRY(p10_io_ppe_rx_eo_enable_dfe_full_cal[l_thread].putData(l_pauc_target, 0x0));
            }

            if (l_xtalk == fapi2::ENUM_ATTR_IO_IOHS_XTALK_HI_XTALK)
            {
                // Disable Peak1 Cal, Peak1 == 2, LTEZ = 1
                // Peaking
                FAPI_TRY(p10_io_ppe_ppe_ctle_peak1_disable[l_thread].putData(l_pauc_target, 0x1));
                // RX A CTLE_PEAK1
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN,
                                                 l_num_lanes,
                                                 2));

                // RX B CTLE_PEAK1
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN,
                                                 l_num_lanes,
                                                 2));
                // RX A LTE_ZERO
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN,
                                                 l_num_lanes,
                                                 1));

                // RX B LTE_ZERO
                FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
                                                 IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN,
                                                 l_num_lanes,
                                                 1));
            }


            FAPI_TRY(disable_bad_lanes(l_iohs_target));

            // HW573551 :: Allow recal to run with powered down lanes
            l_data.flush<0>();
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG(l_iohs_target)); // rx_psave_force_sts_0_15
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG(l_iohs_target, l_data)); // rx_psave_force_sts_0_15
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG(l_iohs_target)); // rx_psave_force_sts_16_32
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT12_PG(l_iohs_target, l_data)); // rx_psave_force_sts_16_32

            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(l_iohs_target)); // tx_psave_force_sts_0_15
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG(l_iohs_target, l_data)); // tx_psave_force_sts_0_15
            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(l_iohs_target)); // tx_psave_force_sts_16_32
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG(l_iohs_target, l_data)); // tx_psave_force_sts_16_32

            l_data.flush<0>();
            l_data.insertFromRight(0xFFFF,
                                   IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
                                   IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN);
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG(l_iohs_target));
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG(l_iohs_target, l_data));

            l_data.flush<0>();
            l_data.insertFromRight(0xFF,
                                   IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23,
                                   IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23_LEN);
            FAPI_TRY(PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG(l_iohs_target));
            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG(l_iohs_target, l_data));

            l_data.flush<0>();
            l_data.insertFromRight(0xFFFF,
                                   IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
                                   IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN);
            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(l_iohs_target));
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(l_iohs_target, l_data));

            l_data.flush<0>();
            l_data.insertFromRight(0xFF,
                                   IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
                                   IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN);
            FAPI_TRY(PREP_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(l_iohs_target));
            FAPI_TRY(PUT_IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(l_iohs_target, l_data));
        }

        for (auto l_omic_target : l_omic_targets)
        {
            int l_thread;
            auto l_omi_targets = l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

            uint32_t l_omi_data_rate = 0;

            if (l_omi_freq == fapi2::ENUM_ATTR_FREQ_OMI_MHZ_25600)
            {
                l_omi_data_rate = 1;
            }

            int l_num_lanes = P10_IO_LIB_NUMBER_OF_OMI_LANES;
            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));
            FAPI_DBG("Setting number of lanes and turning off stop_thread for OMIC thread %d", l_thread);

            for (auto l_omi_target : l_omi_targets)
            {
                fapi2::ATTR_IO_OMI_CHANNEL_LOSS_Type l_loss;
                fapi2::ATTR_IO_IOHS_PRE1_Type l_pre1;
                fapi2::ATTR_IO_IOHS_PRE2_Type l_pre2;

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OMI_PRE1, l_omi_target, l_pre1),
                         "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_PRE1)");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OMI_PRE2, l_omi_target, l_pre2),
                         "Error from FAPI_ATTR_GET (ATTR_IO_IOHS_PRE2)");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OMI_CHANNEL_LOSS, l_omi_target, l_loss),
                         "Error from FAPI_ATTR_GET (ATTR_IO_OMI_CHANNEL_LOSS)");

                uint32_t l_ppe_channel_loss = 0;

                if (l_loss == fapi2::ENUM_ATTR_IO_OMI_CHANNEL_LOSS_MID_LOSS)
                {
                    l_ppe_channel_loss = 1;
                }
                else if (l_loss == fapi2::ENUM_ATTR_IO_OMI_CHANNEL_LOSS_LOW_LOSS)
                {
                    l_ppe_channel_loss = 2;
                }

                // Peaking
                FAPI_TRY(p10_io_ppe_ppe_ctle_peak1_disable[l_thread].putData(l_pauc_target, 0x1));

                // RX A CTLE_PEAK1
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN,
                                                l_num_lanes,
                                                4));
                // RX B CTLE_PEAK1
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN,
                                                l_num_lanes,
                                                4));


                // LTE Gain
                FAPI_TRY(p10_io_ppe_ppe_lte_gain_disable[l_thread].putData(l_pauc_target, 0x1));

                // RX A LTE_GAIN
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN,
                                                l_num_lanes,
                                                7));

                // RX B LTE_GAIN
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN,
                                                l_num_lanes,
                                                7));


                // LTE Zero
                FAPI_TRY(p10_io_ppe_ppe_lte_zero_disable[l_thread].putData(l_pauc_target, 0x1));

                // RX A LTE_ZERO
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN,
                                                l_num_lanes,
                                                1));

                // RX B LTE_ZERO
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN,
                                                l_num_lanes,
                                                1));


                FAPI_TRY(p10_io_ppe_tx_ffe_pre1_coef[l_thread].putData(l_pauc_target, l_pre1));
                FAPI_TRY(p10_io_ppe_tx_ffe_pre2_coef[l_thread].putData(l_pauc_target, l_pre2));

                FAPI_TRY(p10_io_ppe_ppe_data_rate[l_thread].putData(l_pauc_target, l_omi_data_rate));
                FAPI_TRY(p10_io_ppe_ppe_channel_loss[l_thread].putData(l_pauc_target, l_ppe_channel_loss));

                // Eye Opt / Recal Steps
                //FAPI_TRY(p10_io_ppe_tx_dc_enable_dcc[l_thread].putData(l_pauc_target, 0x0));
                if (l_hw539048)
                {
                    FAPI_TRY(p10_io_ppe_rx_eo_enable_dfe_full_cal [l_thread].putData(l_pauc_target, 0x0));
                }

                if (l_hw550299)
                {
                    FAPI_TRY(p10_io_ppe_rx_eo_enable_edge_offset_cal[l_thread].putData(l_pauc_target, 0x0));
                    FAPI_TRY(p10_io_ppe_rx_rc_enable_edge_offset_cal[l_thread].putData(l_pauc_target, 0x0));
                }

            }
        }

        // Flush the data to the sram
        FAPI_TRY(flush_mem_regs());

    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Set bits in mem_regs to speed up simulation
///
/// @param[in] i_target Chip target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::sim_speedup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::iohs;
    using namespace scomt::omi;

    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        for (auto l_omic_target : l_omic_targets)
        {
            auto l_omi_targets = l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

            for (auto l_omi_target : l_omi_targets)
            {
                int l_num_lanes = P10_IO_LIB_NUMBER_OF_OMI_LANES;
                // RX A CTLE_PEAK1
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN,
                                                l_num_lanes,
                                                10));

                // RX A CTLE_PEAK2
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN,
                                                l_num_lanes,
                                                0));

                // RX B CTLE_PEAK1
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN,
                                                l_num_lanes,
                                                10));

                // RX B CTLE_PEAK2
                FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2,
                                                RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN,
                                                l_num_lanes,
                                                0));
            }

        }

        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();

        for (auto l_iohs_target : l_iohs_targets)
        {
            int l_num_lanes = P10_IO_LIB_NUMBER_OF_IOHS_LANES;
            // RX A CTLE_PEAK1
            FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN,
                                             l_num_lanes,
                                             10));

            // RX A CTLE_PEAK2
            FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN,
                                             l_num_lanes,
                                             0));

            // RX B CTLE_PEAK1
            FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN,
                                             l_num_lanes,
                                             10));

            // RX B CTLE_PEAK2
            FAPI_TRY(p10_io_iohs_put_pl_regs(l_iohs_target,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2,
                                             IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN,
                                             l_num_lanes,
                                             0));
        }

        //Set the reg_init bit
        for (auto i = 0; i < P10_IO_LIB_NUMBER_OF_THREADS; i++)
        {
            //PPE_Lib::ppe_mem_regs_put("loff_setting_ovr_enb", "1", ppe_thread);
            FAPI_TRY(p10_io_ppe_loff_setting_ovr_enb[i].putData(l_pauc_target, 1));

            //PPE_Lib::ppe_mem_regs_put("amp_setting_ovr_enb", "1", ppe_thread);
            FAPI_TRY(p10_io_ppe_amp_setting_ovr_enb[i].putData(l_pauc_target, 1));

            //PPE_Lib::ppe_mem_regs_put("rx_eo_converged_end_count", "0000", ppe_thread);
            FAPI_TRY(p10_io_ppe_rx_eo_converged_end_count[i].putData(l_pauc_target, 0));

            //PPE_Lib::ppe_mem_regs_put("rx_min_recal_cnt", "0000", ppe_thread);
            FAPI_TRY(p10_io_ppe_rx_min_recal_cnt[i].putData(l_pauc_target, 0));

            //PPE_Lib::ppe_mem_regs_put("rx_vga_jump_target", "00110000", ppe_thread); //48
            FAPI_TRY(p10_io_ppe_rx_vga_jump_target[i].putData(l_pauc_target, 0x30));

            //PPE_Lib::ppe_mem_regs_put("rx_vga_amax_target", "00110000", ppe_thread); //48
            FAPI_TRY(p10_io_ppe_rx_vga_amax_target[i].putData(l_pauc_target, 0x30));

            //PPE_Lib::ppe_mem_regs_put("rx_vga_amax_target", "00110000", ppe_thread); //48
            FAPI_TRY(p10_io_ppe_rx_vga_amax_target[i].putData(l_pauc_target, 0x30));

            //PPE_Lib::ppe_mem_regs_put("rx_vga_recal_max_target", "00111000", ppe_thread); //56
            FAPI_TRY(p10_io_ppe_rx_vga_recal_max_target[i].putData(l_pauc_target, 0x38));

            //PPE_Lib::ppe_mem_regs_put("rx_vga_recal_min_target", "00101000", ppe_thread); //40
            FAPI_TRY(p10_io_ppe_rx_vga_recal_min_target[i].putData(l_pauc_target, 0x28));

            //Disable long running tasks
            FAPI_TRY(p10_io_ppe_rx_eo_enable_lte_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_eo_enable_dfe_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_eo_enable_ddc[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_eo_enable_quad_phase_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_rc_enable_lte_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_rc_enable_dfe_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_rc_enable_ddc[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_rc_enable_quad_phase_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_tx_dc_enable_dcc[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_tx_rc_enable_dcc[i].putData(l_pauc_target, 0x0));
            //FAPI_TRY(p10_io_ppe_rx_dc_enable_zcal[i].putData(l_pauc_target, 0x0));

            FAPI_TRY(p10_io_ppe_rx_eo_enable_edge_offset_cal[i].putData(l_pauc_target, 0x1));
            FAPI_TRY(p10_io_ppe_rx_eo_enable_ctle_peak_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_rc_enable_ctle_peak_cal[i].putData(l_pauc_target, 0x0));
            FAPI_TRY(p10_io_ppe_rx_rc_enable_edge_offset_cal[i].putData(l_pauc_target, 0x0));
        }
    }

    //Flush values
    for (auto i = 0; i < P10_IO_LIB_NUMBER_OF_THREADS; i++)
    {
        FAPI_TRY(p10_io_ppe_mem_regs[i].flush());
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Set the ext_cmd_req bits for reg_init, dccal, power on, and fifo init and
///        write them to the chip.
///
/// @param[in] i_target Chip target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::ext_req_all(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        for (auto l_iohs_target : l_iohs_targets)
        {
            fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
            int l_thread = 0;
            FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_config_mode),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");


            if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
            {
                FAPI_TRY(p10_io_ppe_ext_cmd_req_hw_reg_init_pg[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_dccal_pl[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_zcal_pl[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_ffe_pl[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_power_on_pl[l_thread].putData(l_pauc_target, 1));
            }
            else if (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
            {
                FAPI_TRY(p10_io_ppe_ext_cmd_req_hw_reg_init_pg[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_dccal_pl[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_zcal_pl[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_ffe_pl[l_thread].putData(l_pauc_target, 1));
                FAPI_TRY(p10_io_ppe_ext_cmd_req_power_off_pl[l_thread].putData(l_pauc_target, 1));
            }

        }

        for (auto l_omic_target : l_omic_targets)
        {
            int l_thread = 0;
            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));

            FAPI_TRY(p10_io_ppe_ext_cmd_req_hw_reg_init_pg[l_thread].putData(l_pauc_target, 1));
            FAPI_TRY(p10_io_ppe_ext_cmd_req_dccal_pl[l_thread].putData(l_pauc_target, 1));
            FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_zcal_pl[l_thread].putData(l_pauc_target, 1));
            FAPI_TRY(p10_io_ppe_ext_cmd_req_tx_ffe_pl[l_thread].putData(l_pauc_target, 1));
            FAPI_TRY(p10_io_ppe_ext_cmd_req_power_on_pl[l_thread].putData(l_pauc_target, 1));
        }
    }

    //Write cached values to the chip
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
fapi2::ReturnCode p10_io_init::ext_req_set_lane_bits(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
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
/// @param[in] i_target Chip target to work with
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init::ext_req_lanes(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Begin");
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_iohs_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        for (auto l_iohs_target : l_iohs_targets)
        {
            std::vector<int> l_lanes;
            int l_thread = 0;

            FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));
            FAPI_DBG("Starting DCCAL for IOHS thread %d", l_thread);

            fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL_Type l_lane_reversal;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL, l_iohs_target, l_lane_reversal),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_FABRIC_LANE_REVERSAL)");

            if (l_lane_reversal & 0x80)
            {
                // SW531947 :: If there is a x18 swizzle, we want to train all lanes
                //             as tx / rx are controlled with different x9s
                for (int l_lane = 0; l_lane < P10_IO_LIB_NUMBER_OF_IOHS_LANES; l_lane++)
                {
                    l_lanes.push_back(l_lane);
                }
            }
            else
            {
                FAPI_TRY(p10_io_get_iohs_lanes(l_iohs_target, l_lanes));
            }


            FAPI_TRY(ext_req_set_lane_bits(l_pauc_target, l_lanes, l_thread));
        }

        for (auto l_omic_target : l_omic_targets)
        {
            std::vector<int> l_lanes;
            int l_thread = 0;

            FAPI_TRY(p10_io_get_omic_thread(l_omic_target, l_thread));
            FAPI_DBG("Starting DCCAL for OMIC thread %d", l_thread);

            FAPI_TRY(p10_io_get_omic_lanes(l_omic_target, l_lanes));

            FAPI_TRY(ext_req_set_lane_bits(l_pauc_target, l_lanes, l_thread));
        }

    }

    //Write cached values to the chip
    FAPI_TRY(flush_fw_regs());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup PHY PPE registers and start reg init, dccal, lane power-up and fifo init
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_init_start_ppe(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    uint8_t l_sim = 0;
    p10_io_init l_proc;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, l_sys, l_sim));

    FAPI_TRY(l_proc.lane_reversal(i_target));

    FAPI_TRY(l_proc.lane_bad_threshold(i_target));

    FAPI_TRY(l_proc.img_regs(i_target));

    FAPI_TRY(l_proc.init_regs(i_target));

    //Wait for reset to finish
    //FIXME: is there a way to tell when it's done?
    fapi2::delay(100, 8000000);

    if (l_sim)
    {
        FAPI_TRY(l_proc.sim_speedup(i_target));
    }

    FAPI_TRY(l_proc.ext_req_lanes(i_target));
    FAPI_TRY(l_proc.ext_req_all(i_target));

fapi_try_exit:
    return fapi2::current_err;
}
