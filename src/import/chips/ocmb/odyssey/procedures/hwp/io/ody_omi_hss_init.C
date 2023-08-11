/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_hss_init.C
/// @brief Setup PHY PPE registers and start reg init, dccal, lane power-up and fifo init
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

#include <ody_omi_hss_init.H>
#include <ody_io_ppe_common.H>



fapi2::ReturnCode ody_omi_hss_init_tx_lanes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ppe_common)
{
    FAPI_DBG("Starting ody_omi_hss_init_tx_lanes");
    uint32_t l_tx_lane_mask = 0;
    const uint8_t c_thread = 0;
    const uint32_t l_tx_fifo_l2u_dly = 0;
    const uint32_t l_tx_unload_sel = 1;
    fapi2::ATTR_OMI_TX_PRE1_Type l_tx_pre1 = 13; // (13/128) = 10%
    fapi2::ATTR_OMI_TX_PRE2_Type l_tx_pre2 = 0;
    fapi2::ATTR_OMI_TX_POST_Type l_tx_post = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_LANES, i_target, l_tx_lane_mask));
    // FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_PRE1, i_target, l_tx_pre1));
    // FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_PRE2, i_target, l_tx_pre2));
    // FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_TX_POST, i_target, l_tx_post));

    FAPI_TRY(i_ppe_common.hss_init_tx(i_target,
                                      c_thread,
                                      l_tx_lane_mask,
                                      l_tx_pre1,
                                      l_tx_pre2,
                                      l_tx_post,
                                      l_tx_fifo_l2u_dly,
                                      l_tx_unload_sel));

fapi_try_exit:
    FAPI_DBG("End ody_omi_hss_init_tx_lanes");
    return fapi2::current_err;
}

fapi2::ReturnCode ody_omi_hss_init_rx_lanes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ppe_common,
        fapi2::ATTR_FREQ_OMI_MHZ_Type i_freq)
{
    FAPI_DBG("Starting ody_omi_hss_init_rx_lanes");
    uint32_t l_rx_lane_mask = 0;
    const uint8_t c_thread = 0;
    fapi2::ATTR_OMI_RX_LTEG_Type l_rx_lte_gain = 7;
    fapi2::ATTR_OMI_RX_LTEZ_Type l_rx_lte_zero = 1;
    int32_t l_rx_peak1 = 0;
    int32_t l_rx_peak2 = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LANES, i_target, l_rx_lane_mask));
    //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LTEG, i_target, l_rx_lte_gain));
    //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LTEZ, i_target, l_rx_lte_zero));

    if ( i_freq < 32000)
    {
        l_rx_peak1 = 4;
    }
    else
    {
        l_rx_peak2 = 6;
    }

    FAPI_TRY(i_ppe_common.hss_init_rx(i_target,
                                      c_thread,
                                      l_rx_lane_mask,
                                      l_rx_lte_gain,
                                      l_rx_lte_zero,
                                      l_rx_peak1,
                                      l_rx_peak2));

fapi_try_exit:
    FAPI_DBG("End ody_omi_hss_init_rx_lanes");
    return fapi2::current_err;
}


fapi2::ReturnCode ody_omi_hss_init_functional_margin(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ppe_common)
{
    FAPI_DBG("Starting ody_omi_hss_init_functional_margin");
    uint32_t l_rx_lane_mask = 0;
    const uint8_t c_thread = 0;
    fapi2::ATTR_OMI_RX_VERT_OFFSET_Type l_rx_vert_offset = 0;
    fapi2::ATTR_OMI_RX_HORIZ_DATA_OFFSET_Type l_rx_horiz_data_offset = 0;
    fapi2::ATTR_OMI_RX_HORIZ_EDGE_OFFSET_Type l_rx_horiz_edge_offset = 0;

    bool l_mfg_mode = false;

    FAPI_TRY(ody_io::get_functional_margin_mfg_mode(l_mfg_mode));

    if (l_mfg_mode)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_LANES, i_target, l_rx_lane_mask));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_VERT_OFFSET, i_target, l_rx_vert_offset));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_HORIZ_DATA_OFFSET, i_target, l_rx_horiz_data_offset));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_RX_HORIZ_EDGE_OFFSET, i_target, l_rx_horiz_edge_offset));

        FAPI_TRY(i_ppe_common.setup_func_margin(i_target,
                                                c_thread,
                                                l_rx_vert_offset,
                                                l_rx_horiz_data_offset,
                                                l_rx_horiz_edge_offset));
    }

fapi_try_exit:
    FAPI_DBG("End ody_omi_hss_init_functional_margin");
    return fapi2::current_err;
}

///
/// @brief Setup PHY PPE registers and start reg init, dccal, lane power-up and fifo init
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_hss_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Starting ody_omi_hss_init");
    const uint8_t c_thread = 0;
    const uint8_t c_pcie_mode = 0;
    const uint32_t c_auto_recal_mask = 0x0;
    fapi2::ATTR_FREQ_OMI_MHZ_Type l_omi_freq;
    fapi2::ATTR_OMI_CHANNEL_LENGTH_Type l_omi_channel_length;

    const uint8_t l_ssc = 1;
    //fapi2::ATTR_OMI_SPREAD_SPECTRUM_Type l_ssc;

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_ODY_OMI_BASE);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_omi_freq));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_CHANNEL_LENGTH, i_target, l_omi_channel_length));
    // FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_SPREAD_SPECTRUM, i_target, l_ssc));

    FAPI_TRY(l_ppe_common.hss_init(i_target,
                                   c_thread,
                                   l_omi_freq,
                                   l_omi_channel_length,
                                   l_ssc,
                                   c_pcie_mode,
                                   c_auto_recal_mask));

    FAPI_TRY(ody_omi_hss_init_tx_lanes(i_target, l_ppe_common));

    FAPI_TRY(ody_omi_hss_init_rx_lanes(i_target, l_ppe_common, l_omi_freq));

    FAPI_TRY(ody_omi_hss_init_functional_margin(i_target, l_ppe_common));

fapi_try_exit:
    FAPI_DBG("End ody_omi_hss_init");
    return fapi2::current_err;
}
