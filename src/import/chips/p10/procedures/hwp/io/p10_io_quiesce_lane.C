/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_quiesce_lane.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/// @file p10_io_quiesce_lane.C
/// @brief Quiesce PHY resources associated with lane failed/spared by DL
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------
///

// EKB-Mirror-To: hostboot

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_io_quiesce_lane.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>
#include <p10_io_lib.H>
#include <p10_scom_iohs.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint32_t NUM_LANES_PER_HALF_LINK = 9;
const uint32_t NUM_LANES_PER_PHY_REG = 16;

const uint8_t DL_TO_PHY_BITMAP_REV[]   = { 8, 7, 6, 5, 3, 2, 1, 0, 4 };
const uint8_t DL_TO_PHY_BITMAP_NOREV[] = { 0, 1, 2, 3, 5, 6, 7, 8, 4 };

const uint64_t PHY_RX_PSAVE_FORCE_REQ_ADDRS[2] =
{
    scomt::iohs::IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG,
    scomt::iohs::IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG
};
const uint64_t PHY_RX_PSAVE_FENCE_REQ_ADDRS[2] =
{
    scomt::iohs::IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG,
    scomt::iohs::IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG
};

const uint64_t PHY_TX_PSAVE_FORCE_REQ_ADDRS[2] =
{
    scomt::iohs::IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG,
    scomt::iohs::IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG
};
const uint64_t PHY_TX_PSAVE_FENCE_REQ_ADDRS[2] =
{
    scomt::iohs::IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG,
    scomt::iohs::IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG
};


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Quiesce PHY resources associated with lane failed/spared by DL
///
/// @param[in] i_iolink_target Reference to IOLINK target
/// @param[in] i_rx_not_tx True=spare RX, False=spare TX
/// @param[inout] io_dl_lane DL lane spared
///
/// @return fapi::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_io_quiesce_lane(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
    const bool i_rx_not_tx,
    uint8_t& io_dl_lane)
{
    using namespace scomt::iohs;

    FAPI_INF("Begin, side: %s", (i_rx_not_tx) ? ("RX") : ("TX"));

    // target related variables
    const auto l_iohs_target = i_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>();
    const auto l_pauc_target = l_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_unit_pos = 0;
    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_iolink_target, l_target_str, sizeof(l_target_str));

    // set variable defaults assuming even iolink, no lane reversal
    uint32_t l_phy_lane = 0;
    const uint8_t* l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_NOREV;

    // PHY powersave force/fence register addreses & data buffer
    uint64_t l_phy_psave_force_req_addr;
    uint64_t l_phy_psave_fence_req_addr;
    fapi2::buffer<uint64_t> l_phy_psave_data;

    // IOHS lane reversal configuration
    fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL_Type l_iohs_fabric_lane_reversal = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL,
                           l_iohs_target,
                           l_iohs_fabric_lane_reversal));

    // adjust variables based on iolink physical position (even/odd)
    //   - value of first PHY RX lane associated with iolink
    //   - DL register to query for RX lane control status
    //   - DL-to-PHY bit map to use
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iolink_target, l_iolink_unit_pos));

    // RX side analysis
    // iolink identifying DL/TL resources will always align with the same x9 set of PHY lanes
    if (i_rx_not_tx)
    {
        // DL odd (PHY 9:17)
        if (l_iolink_unit_pos % 2)
        {
            l_phy_lane += NUM_LANES_PER_HALF_LINK;

            if (l_iohs_fabric_lane_reversal & 0x10) // rx lane reversal, odd iolink
            {
                l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_REV;
            }
        }
        // DL even (PHY 0:8)
        else
        {
            if (l_iohs_fabric_lane_reversal & 0x40) // rx lane reversal, even iolink
            {
                l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_REV;
            }
        }
    }
    // TX side analysis
    else
    {
        // x18 full lane swap -- iolink identifying DL/TL resources will align with opposite
        // x9 set of PHY lanes
        if (l_iohs_fabric_lane_reversal & 0x80)
        {
            // lanes will be reversed unless the x9 TX swap bit is set as well
            l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_REV;

            // PHY lanes will be in opposite half relative to DL
            // DL odd (PHY 0:8)
            if (l_iolink_unit_pos % 2)
            {
                if (l_iohs_fabric_lane_reversal & 0x08) // tx lane reversal, odd iolink
                {
                    l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_NOREV;
                }
            }
            // DL even (PHY 9:17)
            else
            {
                l_phy_lane += NUM_LANES_PER_HALF_LINK;

                if (l_iohs_fabric_lane_reversal & 0x20) // tx lane reversal, even iolink
                {
                    l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_NOREV;
                }
            }
        }
        // no x18 full lane swap -- iolink identifying DL/TL resources will align with
        // same x9 set of PHY lanes
        else
        {
            l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_NOREV;

            // DL odd (PHY 9:17)
            if (l_iolink_unit_pos % 2)
            {
                l_phy_lane += NUM_LANES_PER_HALF_LINK;

                if (l_iohs_fabric_lane_reversal & 0x08) // tx lane reversal, odd iolink
                {
                    l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_REV;
                }
            }
            // DL even (PHY 0:8)
            else
            {
                if (l_iohs_fabric_lane_reversal & 0x20) // tx lane reversal, even iolink
                {
                    l_dl_to_phy_bitmap = DL_TO_PHY_BITMAP_REV;
                }
            }
        }
    }

    // log traces for debug
    FAPI_IMP("iolink target: %s",
             l_target_str);
    FAPI_IMP("iolink unit position: %d, PHY lane: %d, DL lane reversal: 0x%02X",
             l_iolink_unit_pos, l_phy_lane, l_iohs_fabric_lane_reversal);


    // RX side analysis -- read DL state to determine failed PHY lane
    // (TX side will simply use DL lane passed in from RX analysis)
    if (i_rx_not_tx)
    {
        // flag marking PHY lane found
        bool l_phy_lane_found = false;

        // read DL register to determine lane status
        uint64_t l_dl_rx_lane_control_addr = (l_iolink_unit_pos % 2) ?
                                             (DLP_LINK1_RX_LANE_CONTROL) :
                                             (DLP_LINK0_RX_LANE_CONTROL);
        fapi2::buffer<uint64_t> l_dl_rx_lane_control_data = 0;
        FAPI_TRY(fapi2::getScom(l_iohs_target, l_dl_rx_lane_control_addr, l_dl_rx_lane_control_data));
        FAPI_IMP("DL RX lane control: 0x%016X",
                 l_dl_rx_lane_control_data);

        // expect to find one lane marked as either: spared, failed, disabled, or not locked
        for (uint8_t l_dl_bit = 0; l_dl_bit < NUM_LANES_PER_HALF_LINK; l_dl_bit++)
        {
            if ( l_dl_rx_lane_control_data.getBit(l_dl_bit + DLP_LINK0_RX_LANE_CONTROL_DISABLED) ||
                 l_dl_rx_lane_control_data.getBit(l_dl_bit + DLP_LINK0_RX_LANE_CONTROL_SPARED) ||
                 !l_dl_rx_lane_control_data.getBit(l_dl_bit + DLP_LINK0_RX_LANE_CONTROL_LOCKED) ||
                 l_dl_rx_lane_control_data.getBit(l_dl_bit + DLP_LINK0_RX_LANE_CONTROL_FAILED))
            {
                // take no action if a second lane is unexpectedly identified, to avoid action
                // which may bring down the link
                FAPI_ASSERT(!l_phy_lane_found,
                            fapi2::P10_IO_QUIESCE_LANE_MULTIPLE_RX_IDENTIFIED_ERR()
                            .set_IOLINK_TARGET(i_iolink_target)
                            .set_IOHS_TARGET(l_iohs_target)
                            .set_PAUC_TARGET(l_pauc_target)
                            .set_IOLINK_UNIT_POS(l_iolink_unit_pos)
                            .set_DL_RX_LANE_CONTROL_ADDR(l_dl_rx_lane_control_addr)
                            .set_DL_RX_LANE_CONTROL_DATA(l_dl_rx_lane_control_data)
                            .set_IOHS_FABRIC_LANE_REVERSAL(l_iohs_fabric_lane_reversal),
                            "Multiple lanes identified in DL RX Lane Control Register, aborting!");

                // use lookup table to translate DL bit position to PHY lane within iolink
                l_phy_lane_found = true;
                io_dl_lane = l_dl_bit;
            }
        }

        // generate callout if no lane is identified
        FAPI_ASSERT(l_phy_lane_found,
                    fapi2::P10_IO_QUIESCE_LANE_NO_RX_IDENTIFIED_ERR()
                    .set_IOLINK_TARGET(i_iolink_target)
                    .set_IOHS_TARGET(l_iohs_target)
                    .set_PAUC_TARGET(l_pauc_target)
                    .set_IOLINK_UNIT_POS(l_iolink_unit_pos)
                    .set_DL_RX_LANE_CONTROL_ADDR(l_dl_rx_lane_control_addr)
                    .set_DL_RX_LANE_CONTROL_DATA(l_dl_rx_lane_control_data)
                    .set_IOHS_FABRIC_LANE_REVERSAL(l_iohs_fabric_lane_reversal),
                    "No lanes identified in DL RX Lane Control Register, aborting!");
    }

    // swizzle from DL->PHY lane
    l_phy_lane += l_dl_to_phy_bitmap[io_dl_lane];
    FAPI_IMP("PHY lane: %d, DL bit: %d, DL-to-PHY xlate: %d",
             l_phy_lane, io_dl_lane, l_dl_to_phy_bitmap[io_dl_lane]);

    // confirm lane is within range
    FAPI_ASSERT(l_phy_lane < 2 * NUM_LANES_PER_HALF_LINK,
                fapi2::P10_IO_QUIESCE_LANE_CALCULATION_ERR()
                .set_IOLINK_TARGET(i_iolink_target)
                .set_IOHS_TARGET(l_iohs_target)
                .set_PAUC_TARGET(l_pauc_target)
                .set_IOLINK_UNIT_POS(l_iolink_unit_pos)
                .set_DL_LANE(io_dl_lane)
                .set_PHY_LANE(l_phy_lane)
                .set_RX_NOT_TX(i_rx_not_tx)
                .set_IOHS_FABRIC_LANE_REVERSAL(l_iohs_fabric_lane_reversal),
                "Calculated PHY lane is out of range, aborting!");

    // prepare lane for power down, RX side only
    if (i_rx_not_tx)
    {
        int l_thread = 0;
        bool l_rx_lane_busy = true;
        fapi2::buffer<uint64_t> l_data = 0;
        const uint32_t POLLING_LOOPS = 800;
        class : public p10_io_ppe_cache_proc
        {
        } l_io_quiesce_lane;

        FAPI_TRY(p10_io_get_iohs_thread(l_iohs_target, l_thread));

        //FAPI_TRY(l_io_quiesce_lane.p10_io_ppe_rx_cmd_init_done[l_thread].putData(l_pauc_target,
        //                                                                         1,
        //                                                                         (int) l_phy_lane,
        //                                                                         true));
        //
        //FAPI_TRY(p10_io_iohs_put_pl_regs_single(l_iohs_target,
        //                                        IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_MODE1_PL,
        //                                        IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
        //                                        1,
        //                                        l_phy_lane,
        //                                        1));
        //
        //FAPI_TRY(p10_io_iohs_put_pl_regs_single(l_iohs_target,
        //                                        IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL,
        //                                        IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_INIT_DONE,
        //                                        1,
        //                                        l_phy_lane,
        //                                        1));

        FAPI_TRY(l_io_quiesce_lane.p10_io_ppe_rx_recal_abort[l_thread].putData(l_pauc_target,
                 1,
                 (int) l_phy_lane,
                 true));

        //FAPI_TRY(p10_io_iohs_put_pl_regs_single(l_iohs_target,
        //                                        IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL,
        //                                        IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
        //                                        1,
        //                                        l_phy_lane,
        //                                        1));

        for (uint32_t l_try = 0; l_try < POLLING_LOOPS && l_rx_lane_busy; l_try++)
        {
            FAPI_INF("Loop %d / %d", l_try, POLLING_LOOPS);

            FAPI_TRY(l_io_quiesce_lane.p10_io_ppe_rx_lane_busy[l_thread].getData(l_pauc_target,
                     l_data,
                     l_phy_lane,
                     true));
            FAPI_INF("  data: %016llX\n", l_data);
            l_rx_lane_busy = (l_data != 0);

            if (l_rx_lane_busy)
            {
                FAPI_TRY(fapi2::delay(1000000, 10000000));
            }
        }

        if (l_rx_lane_busy)
        {
            fapi2::ATTR_IS_SIMICS_Type l_simics;
            const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_simics),
                     "Error from FAPI_ATTR_GET (ATTR_IS_SIMICS)");

            if (l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS)
            {
                FAPI_INF("Skipping timeout in Simics");
                l_rx_lane_busy = false;
            }
        }

        FAPI_ASSERT(!l_rx_lane_busy,
                    fapi2::P10_IO_QUIESCE_LANE_RX_LANE_BUSY_TIMEOUT_ERROR()
                    .set_IOLINK_TARGET(i_iolink_target)
                    .set_IOHS_TARGET(l_iohs_target)
                    .set_PAUC_TARGET(l_pauc_target)
                    .set_IOLINK_UNIT_POS(l_iolink_unit_pos)
                    .set_RX_LANE_BUSY(l_data)
                    .set_IOHS_FABRIC_LANE_REVERSAL(l_iohs_fabric_lane_reversal),
                    "Timed out waiting for RX lane busy to drop!");
    }

    // set correct PHY powersave force/fence register addreses
    if (i_rx_not_tx)
    {
        l_phy_psave_force_req_addr = PHY_RX_PSAVE_FORCE_REQ_ADDRS[l_phy_lane / NUM_LANES_PER_PHY_REG];
        l_phy_psave_fence_req_addr = PHY_RX_PSAVE_FENCE_REQ_ADDRS[l_phy_lane / NUM_LANES_PER_PHY_REG];
    }
    else
    {
        l_phy_psave_force_req_addr = PHY_TX_PSAVE_FORCE_REQ_ADDRS[l_phy_lane / NUM_LANES_PER_PHY_REG];
        l_phy_psave_fence_req_addr = PHY_TX_PSAVE_FENCE_REQ_ADDRS[l_phy_lane / NUM_LANES_PER_PHY_REG];
    }

    // update force, fence request registers in sequence -- use RMW to update bit
    // associated with targeted lane
    FAPI_TRY(fapi2::getScom(l_iohs_target, l_phy_psave_force_req_addr, l_phy_psave_data));
    l_phy_psave_data.setBit(48 + (l_phy_lane % NUM_LANES_PER_PHY_REG));
    FAPI_TRY(fapi2::putScom(l_iohs_target, l_phy_psave_force_req_addr, l_phy_psave_data));

    FAPI_TRY(fapi2::getScom(l_iohs_target, l_phy_psave_fence_req_addr, l_phy_psave_data));
    l_phy_psave_data.setBit(48 + (l_phy_lane % NUM_LANES_PER_PHY_REG));
    FAPI_TRY(fapi2::putScom(l_iohs_target, l_phy_psave_fence_req_addr, l_phy_psave_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Quiesce PHY resources associated with lane failed/spared by DL
///
///        HWP will first query RX side target (input from PRD) to determine which
///        DL lane was spared.  At the DL layer, the same bit position will be need
///        to be queisced on the TX side as well.
///
///        Both RX/TX sides need to consider independent lane reversal (DL->PHY remap)
///        personalization to find the associated PHY lane to power down.
///
/// @param[in] i_target Reference to IOLINK target with recently spared lane, on RX side
///
/// @return fapi::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_io_quiesce_lane(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_rx_iolink_target)
{
    FAPI_DBG("Begin");

    // DL bit lane which is spared (in range of 0:8 for a single x9 link)
    uint8_t l_dl_lane = 0xFF;
    bool l_action_state = false;


    const auto l_iohs_target = i_rx_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>();
    FAPI_TRY(p10_iohs_phy_get_action_state(l_iohs_target, l_action_state))

    if (l_action_state)
    {
        FAPI_DBG("Quiesce Lane skipped, IOHS Action in progress...");
    }
    else
    {
        // PRD provides IOLINK associated with RX side registering error, use FAPI
        // API to find connected IOLINK to manipulate TX side resources
        fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_tx_iolink_target;
        FAPI_TRY(i_rx_iolink_target.getOtherEnd(l_tx_iolink_target));

        // examine RX DL logic to determine lane spared & power down associated
        // PHY lane (taking into account RX side lane reversal in PHY->DL path)
        FAPI_TRY(p10_io_quiesce_lane(i_rx_iolink_target, true, l_dl_lane));

        // given this information, power down associated PHY lane on TX side
        // (using connected link target and knowledge of the TX side x9 lane
        // reversal/x18 end-to-end swap)
        FAPI_TRY(p10_io_quiesce_lane(l_tx_iolink_target, false, l_dl_lane));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
