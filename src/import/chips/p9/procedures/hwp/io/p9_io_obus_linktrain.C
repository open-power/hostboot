/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_linktrain.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_io_obus_linktrain.C
/// @brief I/O Link Training on the Abus(Obus PHY) Links.
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
/// Train the link.
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///     - Dccal Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Defines
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_obus_linktrain.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>
#include <p9_io_common.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------

/**
 * @brief A HWP to perform FIFO init for ABUS(OPT)
 * @param[in] i_mode  Linktraining Mode
 * @param[in] i_tgt   Reference to the Target
 * @retval    ReturnCode
 */
fapi2::ReturnCode p9_io_obus_linktrain(const OBUS_TGT& i_tgt)
{
    FAPI_IMP("p9_io_obus_linktrain: P9 I/O OPT Abus Entering");
    const uint32_t MAX_LANES         = 24;
    const uint8_t  GRP0              = 0;
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt,  l_tgt_str,  fapi2::MAX_ECMD_STRING_LEN);
    fapi2::buffer<uint64_t> l_data = 0;
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fbc_active;
    fapi2::ATTR_LINK_TRAIN_Type l_link_train;
    fapi2::ATTR_CHIP_EC_FEATURE_HW419022_Type l_hw419022 = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_chip_target =
        i_tgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    bool l_even = true;
    bool l_odd = true;

    FAPI_DBG("I/O Abus FIFO init: Target(%s)", l_tgt_str);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE,
                           i_tgt,
                           l_fbc_active),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

    if (!l_fbc_active)
    {
        FAPI_DBG("Skipping link, not active for FBC protocol");
        goto fapi_try_exit;
    }

    // PHY initialization sequence:
    // - clear TX_UNLOAD_CLK_DISABLE
    // - set TX_FIFO_INIT
    // - set TX_UNLOAD_CLK_DISABLE
    // - set RX_AC_COUPLED

    // Clear TX_UNLOAD_CLK_DISABLE
    for (uint32_t lane = 0; lane < MAX_LANES; ++lane)
    {
        FAPI_TRY(io::read(OPT_TX_MODE2_PL, i_tgt, GRP0, lane, l_data));
        io::set(OPT_TX_UNLOAD_CLK_DISABLE, 0, l_data);
        FAPI_TRY(io::write(OPT_TX_MODE2_PL, i_tgt, GRP0, lane, l_data));
    }

    // Set TX_FIFO_INIT
    l_data.flush<0>();
    io::set(OPT_TX_FIFO_INIT, 1, l_data);

    for (uint32_t lane = 0; lane < MAX_LANES; ++lane)
    {
        FAPI_TRY(io::write(OPT_TX_CNTL1G_PL, i_tgt, GRP0, lane, l_data));
    }

    // Set TX_UNLOAD_CLK_DISABLE
    for (uint32_t lane = 0; lane < MAX_LANES; ++lane)
    {
        FAPI_TRY(io::read(OPT_TX_MODE2_PL, i_tgt, GRP0, lane, l_data));
        io::set(OPT_TX_UNLOAD_CLK_DISABLE, 1, l_data );
        FAPI_TRY(io::write(OPT_TX_MODE2_PL, i_tgt, GRP0, lane, l_data));
    }

    // Set RX_AC_COUPLED
    FAPI_TRY(io::read( OPT_RX_CTL_MODE2_O_PG, i_tgt, GRP0, 0, l_data));
    io::set(OPT_RX_AC_COUPLED, 1, l_data);
    FAPI_TRY(io::write( OPT_RX_CTL_MODE2_O_PG, i_tgt, GRP0, 0, l_data));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW419022,
                           i_chip_target,
                           l_hw419022),
             "Error from FAPI_ATTR_GET (fapi2::ATTR_CHIP_EC_FEATURE_HW419022)");

    // perform DL training workaround
    if (l_hw419022)
    {
        // determine link train capabilities (half/full)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_TRAIN,
                               i_tgt,
                               l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_LINK_TRAIN)");

        l_even = (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH) ||
                 (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY);

        l_odd = (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH) ||
                (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_ODD_ONLY);

        // set TX lane control to force send of TS1 pattern
        if (l_even)
        {
            FAPI_TRY(fapi2::putScom(i_tgt,
                                    OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL,
                                    0x1111111111100000ULL),
                     "Error from putScom (OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL)");
        }

        if (l_odd)
        {
            FAPI_TRY(fapi2::putScom(i_tgt,
                                    OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL,
                                    0x1111111111100000ULL),
                     "Error from putScom (OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL)");
        }

        // Delay to compensate for active links
        FAPI_TRY(fapi2::delay(100000000, 1000000),
                 "Error from A-link retimer delay");
    }

fapi_try_exit:
    FAPI_IMP("p9_io_obus_linktrain: P9 I/O OPT Abus Exiting");
    return fapi2::current_err;
}
