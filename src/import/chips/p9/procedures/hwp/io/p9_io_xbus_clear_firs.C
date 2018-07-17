/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_clear_firs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_io_xbus_clear_firs.C
/// @brief Clears I/O Firs
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Clears I/O Xbus FIRs on the PHY Rx/Tx.
///
/// Clocks must be running.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_xbus_clear_firs.H>
#include <p9_io_xbus_read_erepair.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

#include <p9_xbus_scom_addresses.H>
#include <p9_xbus_scom_addresses_fld.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------
fapi2::ReturnCode io_rx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_clock_group );

fapi2::ReturnCode io_tx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_clock_group );

/**
 * @brief Clears PHY Rx/Tx FIRs on the XBUS(EDI+) specified target.  The FIRs
 *   are cleared by toggling a rx & tx fir reset bit.
 * @param[in] i_target         FAPI2 Target
 * @param[in] i_clock_group    Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_clear_firs(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                   i_clock_group )
{
    FAPI_IMP( "I/O Start Xbus Clear FIRs" );

    FAPI_TRY( io_tx_fir_reset( i_target, i_clock_group ), "Tx Reset Failed" );

    FAPI_TRY( io_rx_fir_reset( i_target, i_clock_group ), "Rx Reset Failed" );

fapi_try_exit:
    FAPI_IMP( "I/O End Xbus Clear FIRs" );
    return fapi2::current_err;
}

/**
 * @brief This function resets the Rx Firs on a EDI+ Xbus
 * @param[in] i_target       FAPI2 Target
 * @param[in] i_clock_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode io_rx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group)
{
    const uint8_t LANE_00 = 0;
    uint64_t l_data = 0;

    FAPI_TRY( io::read( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
              "Reading Rx Fir Reg Failed");

    io::set (EDIP_RX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Rx Fir Reg Failed");

    io::set (EDIP_RX_FIR_RESET, 1, l_data);
    FAPI_TRY(io::write( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Rx Fir Reg Failed");

    io::set (EDIP_RX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_RX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Rx Fir Reg Failed");

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief This function resets the Tx Firs on a EDI+ Xbus
 * @param[in] i_target       FAPI2 Target
 * @param[in] i_clock_group  Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode io_tx_fir_reset(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group)
{
    const uint8_t LANE_00 = 0;
    uint64_t l_data = 0;

    FAPI_TRY( io::read( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
              "Reading Tx Fir Reg Failed");

    io::set (EDIP_TX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Tx Fir Reg Failed");

    io::set (EDIP_TX_FIR_RESET, 1, l_data);
    FAPI_TRY(io::write( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Tx Fir Reg Failed");

    io::set (EDIP_TX_FIR_RESET, 0, l_data);
    FAPI_TRY(io::write( EDIP_TX_FIR_RESET, i_target, i_clock_group, LANE_00, l_data ),
             "Writing Tx Fir Reg Failed");

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief This function reads the bad lane data of a EDI+ Xbus
 * @param[in]  i_target        FAPI2 Target
 * @param[in]  i_clock_group   Clock Group
 * @param[out] o_bad_lane_data Bit representation of each lane in the clock group
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_get_bad_lane_data(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group,
    uint32_t& o_bad_lane_data)
{
    FAPI_IMP("I/O EDI+ Xbus Get Current Bad Lane Data :: Start");
    const uint8_t LN0    = 0;
    uint64_t      l_data = 0;
    std::vector<uint8_t> l_bad_lanes;

    FAPI_DBG("Read Bad Lane Vector 0 15");
    FAPI_TRY(io::read(EDIP_RX_LANE_BAD_VEC_0_15, i_target, i_clock_group, LN0, l_data),
             "rmw to edip_rx_lane_bad_vec_0_15 failed.");

    o_bad_lane_data = (io::get(EDIP_RX_LANE_BAD_VEC_0_15, l_data) << 8) & 0x00FFFF00;

    FAPI_DBG("Read Bad Lane Vector 16 23");
    FAPI_TRY(io::read(EDIP_RX_LANE_BAD_VEC_16_23, i_target, i_clock_group, LN0, l_data),
             "rmw to edip_rx_lane_bad_vec_16_23 failed.");

    o_bad_lane_data |= (io::get(EDIP_RX_LANE_BAD_VEC_16_23, l_data) & 0x000000FF);


    FAPI_DBG("Call xbus read erepair");
    FAPI_TRY(p9_io_xbus_read_erepair(i_target, i_clock_group, l_bad_lanes));

    for(auto bad_lane : l_bad_lanes)
    {
        o_bad_lane_data |= (0x1 << (23 - bad_lane));
    }

fapi_try_exit:
    FAPI_IMP("I/O EDI+ Xbus Get Current Bad Lane Data :: Exit");
    return fapi2::current_err;
}

/**
 * @brief Clears PHY Rx/Tx FIRs on the XBUS(EDI+) specified target.  The FIRs
 *   are cleared by toggling a rx & tx fir reset bit.
 * @param[in] i_target         FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_erepair_cleanup(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target)
{
    const uint8_t MAX_CLOCK_GROUPS = 2;
    bool l_clear_pb_spare_deployed = true;
    uint32_t l_grp0_pre_bad_lane_data = 0;
    uint32_t l_grp1_pre_bad_lane_data = 0;
    uint32_t l_pre_bad_lane_data   = 0;
    uint32_t l_post_bad_lane_data  = 0;
    FAPI_IMP("I/O Start Xbus Clear FIRs");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_GRP0_PRE_BAD_LANE_DATA,
                           i_target, l_grp0_pre_bad_lane_data));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_XBUS_GRP1_PRE_BAD_LANE_DATA,
                           i_target, l_grp1_pre_bad_lane_data));

    for (uint8_t l_group = 0; l_group < MAX_CLOCK_GROUPS; ++l_group)
    {
        // Get attribute of pre bad lane data
        FAPI_IMP("Get Pre Bad Lane Data");

        if (l_group == 0)
        {
            l_pre_bad_lane_data = l_grp0_pre_bad_lane_data;
        }
        else
        {
            l_pre_bad_lane_data = l_grp1_pre_bad_lane_data;
        }


        // Get current bad lane data
        //  - bad_lane_vector AND bad_lane_code
        FAPI_IMP("Get Current Bad Lane Data");
        FAPI_TRY(p9_io_xbus_get_bad_lane_data(i_target, l_group, l_post_bad_lane_data));

        FAPI_IMP("Compare Bad Lane Data");

        if (l_pre_bad_lane_data == l_post_bad_lane_data)
        {
            FAPI_DBG("I/O EDI+ Xbus Pre/Post Bad Lane Data Match");

            // If the entire bad lane vector equals 0, then we don't need to clear
            //   any firs.
            if (l_pre_bad_lane_data != 0)
            {
                FAPI_DBG("I/O EDI+ Xbus Clearing PG Firs");

                FAPI_TRY(io_tx_fir_reset(i_target, l_group), "Tx Reset Failed");
                FAPI_TRY(io_rx_fir_reset(i_target, l_group), "Rx Reset Failed");

            }
        }
        else
        {
            FAPI_DBG("Bad lane data does NOT match.");
            l_clear_pb_spare_deployed = false;
        }
    }

    // Clearing of the Spare Lane Deployed FIR when:
    // - the pre/post bad lane data match on both groups. (l_clear_pb_spare_deployed)
    // - AND if either groups have nonzero bad lane data
    if (l_clear_pb_spare_deployed &&
        ((l_grp0_pre_bad_lane_data != 0x0) || (l_grp1_pre_bad_lane_data != 0x0)) )
    {
        fapi2::buffer<uint64_t> l_data;
        fapi2::buffer<uint64_t> l_mask;

        // Clear BUS0_SPARE_DEPLOYED (Bit 9).
        l_data.clearBit<XBUS_1_FIR_REG_RX_BUS0_SPARE_DEPLOYED>();
        l_mask.setBit<XBUS_1_FIR_REG_RX_BUS0_SPARE_DEPLOYED>();
        FAPI_TRY(fapi2::putScomUnderMask(i_target, XBUS_FIR_REG, l_data, l_mask));

    }

fapi_try_exit:
    FAPI_IMP("I/O End Xbus Clear FIRs");
    return fapi2::current_err;
}
