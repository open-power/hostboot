/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_iohs_poll_recal.C $ */
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
/// @file p10_io_iohs_poll_recal.C
/// @brief I/O Power Functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_iohs_poll_recal.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_io_lib.H>
#include <p10_scom_iohs.H>

class p10_io_iohs_recal : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode p10_io_iohs_check_busy(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
            const int& i_thread,
            const int& i_lane,
            bool& o_busy);

};

///
/// @brief Check for rx_lane_busy
///
/// @param[in] i_pauc_target The PAUC target to read from
/// @param[in] i_thread The thread to read
/// @param[in] i_lane Lane to target
/// @param[out] o_busy rx_lane_busy
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_recal::p10_io_iohs_check_busy(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const int& i_thread,
    const int& i_lane,
    bool& o_busy)
{
    fapi2::buffer<uint64_t> l_data = 0;
    o_busy = true;
    FAPI_TRY(p10_io_ppe_cache_proc::p10_io_ppe_rx_lane_busy[i_thread].getData(i_pauc_target, l_data, i_lane, true));

    if (l_data == 0)
    {
        o_busy = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Poll for Recalibration to Finish
///
/// @param[in] i_target IOHS Target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_poll_recal(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::iohs;
    const uint32_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    fapi2::buffer<uint64_t> l_data = 0;
    std::vector<int> l_lanes;
    uint64_t l_addr = 0x0;
    int l_thread = 0;
    bool l_busy = false;
    bool l_done = false;
    p10_io_iohs_recal l_proc;

    auto l_pauc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();


    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_iohs_target, l_tgt_str, sizeof(l_tgt_str));

    //Poll for done
    const int POLLING_LOOPS = 800;
    uint64_t l_recal_req = 0;

    FAPI_TRY(p10_io_get_iohs_thread(i_iohs_target, l_thread));

    FAPI_TRY(p10_io_get_iohs_lanes(i_iohs_target, l_lanes));

    for (int l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        FAPI_DBG("Loop %d / %d on %s", l_try, POLLING_LOOPS, l_tgt_str);
        l_done = true;

        for (uint64_t l_lane : l_lanes)
        {
            // rx_phy_dl_recal_req
            //  rx_datasm_stat1_pl
            l_addr = IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL | ((l_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
            FAPI_TRY(fapi2::getScom(i_iohs_target, l_addr, l_data));

            FAPI_TRY(l_data.extractToRight(l_recal_req, IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL, 1));

            FAPI_DBG("%s Lane %d recal_req = 0x%llx.", l_tgt_str, l_lane, l_recal_req);

            if (l_recal_req == 0x1)
            {
                l_done = false;
                break;
            }


            FAPI_TRY(l_proc.p10_io_iohs_check_busy(l_pauc_target, l_thread, l_lane, l_busy));

            FAPI_DBG("IOHS: %s Lane: %d Thread: %d, rx_lane_busy: %d", l_tgt_str, l_lane, l_thread, l_busy);

            if (l_busy)
            {
                l_done = false;
                break;
            }

        }

        if (l_done)
        {
            break;
        }
        else
        {
            fapi2::delay(1000000, 10000000);
        }
    }

    // Avoid failing in Simics until the models get updated
    if( !l_done )
    {
        fapi2::ATTR_IS_SIMICS_Type l_simics;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_simics),
                 "Error from FAPI_ATTR_GET (ATTR_IS_SIMICS)");

        if( l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS )
        {
            FAPI_INF("p10_io_iohs_poll_recal_done> Skipping timeout in Simics");
            l_done = true;
        }
    }

    FAPI_ASSERT(l_done,
                fapi2::P10_IO_IOHS_POLL_RECAL_TIMEOUT_ERROR()
                .set_TARGET(i_iohs_target),
                "Timeout waiting on io recal to complete");
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;


}
