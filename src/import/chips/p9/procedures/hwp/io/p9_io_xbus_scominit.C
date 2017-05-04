/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_scominit.C $ */
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
/// @file p9_io_xbus_scominit.C
/// @brief Invoke XBUS initfile
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 3
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//
//   Invoke XBUS scominit file.
//
// Procedure Prereq:
//   - System clocks are running.
// @endverbatim
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_regs.H>
#include <p9_io_scom.H>
#include <p9_io_xbus_scominit.H>
#include <p9_xbus_g0_scom.H>
#include <p9_xbus_g1_scom.H>

enum
{
    ENUM_ATTR_XBUS_GROUP_0,
    ENUM_ATTR_XBUS_GROUP_1
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/**
 * @brief Sets ATTR_IO_XBUS_MASTER_MODE based on fabric chip id and fabric group id
 * @param[in] i_target    Fapi2 Target
 * @param[in] i_ctarget   Fapi2 Connected Target
 * @retval    ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode set_rx_master_mode(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_ctarget );

/**
 * @brief Gets the value of the ATTR_PROC_FABRIC_GROUP_ID and passes back by reference
 * @param[in] i_target    Fapi2 Target
 * @param[in] o_group_id  Group ID
 * @retval    ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode p9_get_proc_fabric_group_id(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    uint8_t&                                        o_group_id );

/**
 * @brief Gets the value of the ATTR_PROC_FABRIC_CHIP_ID and passes back by refernce
 * @param[in] i_target    Fapi2 Target
 * @param[in] o_chip_id   Chip ID
 * @retval    ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode p9_get_proc_fabric_chip_id(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    uint8_t&                                        o_chip_id );

/**
 * @brief Sets the Msb Swap Register based upon an attribute
 * @param[in]  i_tgt    Fapi2 Target
 * @param[out] o_grp    Group
 * @retval     ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode set_msb_swap(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS > i_tgt,
    const uint8_t                                  i_grp );

/**
 * @brief HWP that calls the XBUS SCOM initfiles
 * Should be called for all valid/connected XBUS endpoints
 * @param[in] i_target           Reference to XBUS chiplet target
 * @param[in] i_connected_target Reference to connected XBUS chiplet target
 * @param[in] i_group            Reference to XBUS group-0/1
 * @return FAPI2_RC_SUCCESS on success, error otherwise
 */
fapi2::ReturnCode p9_io_xbus_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_connected_target,
    const uint8_t i_group)
{
    // mark HWP entry
    FAPI_INF("p9_io_xbus_scominit: Entering ...");
    const uint8_t     LANE_00  = 0;
    fapi2::ReturnCode rc       = fapi2::FAPI2_RC_SUCCESS;

    // get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_system_target;

    // get proc chip to pass for EC level checks in procedure
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // assert IO reset to power-up bus endpoint logic
    // read-modify-write, set single reset bit (HW auto-clears)
    // on writeback
    FAPI_TRY( io::rmw( EDIP_RX_IORESET, i_target, i_group, LANE_00, 1 ),
              "I/O Xbus Scominit: Primary Set Reset Hard Failed." );
    FAPI_TRY( io::rmw( EDIP_RX_IORESET, i_connected_target, i_group, LANE_00, 1 ),
              "I/O Xbus Scominit: Connected Set Reset Hard Failed." );

    // Calculated HW Delay needed based on counter size and clock speed.
    // 50us -- Based on Counter Size, 40us minimum
    // 1 Million sim cycles -- Based on sim learning
    FAPI_TRY( fapi2::delay( 50000, 1000000 ) );

    FAPI_TRY( io::rmw( EDIP_TX_IORESET, i_target, i_group, LANE_00, 1 ),
              "I/O Xbus Scominit: Primary Set Reset Hard Failed." );
    FAPI_TRY( io::rmw( EDIP_TX_IORESET, i_connected_target, i_group, LANE_00, 1 ),
              "I/O Xbus Scominit: Connected Set Reset Hard Failed." );

    // Calculated HW Delay needed based on counter size and clock speed.
    // 50us -- Based on Counter Size, 40us minimum
    // 1 Million sim cycles -- Based on sim learning
    FAPI_TRY( fapi2::delay( 50000, 1000000 ) );

    // Set rx master/slave attribute prior to calling the scominit procedures.
    // The scominit procedure will reference the attribute to set the register field.
    FAPI_TRY( set_rx_master_mode( i_target, i_connected_target ),
              "Setting Rx Master Mode Attribute Failed." );

    // Set Msb Swap based upon attribute data.
    FAPI_TRY( set_msb_swap( i_target, i_group ), "Failed Setting MSB Swap" );
    FAPI_TRY( set_msb_swap( i_connected_target, i_group ), "Failed Setting MSB Swap" );

    switch(i_group)
    {
        case ENUM_ATTR_XBUS_GROUP_0:
            FAPI_INF("Group 0:Invoke FAPI procedure core: input_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g0_scom, i_target, l_system_target);

            if( rc )
            {
                FAPI_ERR( "P9 Xbus G0 Main Target Scominit Failed" );
                fapi2::current_err = rc;
                break;
            }

            FAPI_INF("Group 0:Invoke FAPI procedure core: connected_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g0_scom, i_connected_target, l_system_target);

            if( rc )
            {
                FAPI_ERR( "P9 Xbus G0 Connected Target Scominit Failed" );
                fapi2::current_err = rc;
                break;
            }

            break;

        case ENUM_ATTR_XBUS_GROUP_1:
            FAPI_INF("Group 1:Invoke FAPI procedure core: input_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g1_scom, i_target, l_system_target, l_proc);

            if( rc )
            {
                FAPI_ERR( "P9 Xbus G1 Main Target Scominit Failed" );
                fapi2::current_err = rc;
                break;
            }

            FAPI_INF("Group 1:Invoke FAPI procedure core: connected_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g1_scom, i_connected_target, l_system_target, l_proc);

            if( rc )
            {
                FAPI_ERR( "P9 Xbus G1 Connected Target Scominit Failed" );
                fapi2::current_err = rc;
                break;
            }

            break;
    }

    // mark HWP exit
    FAPI_INF("p9_io_xbus_scominit: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Sets ATTR_IO_XBUS_MASTER_MODE based on fabric chip id and fabric group id
 * @param[in] i_target    Fapi2 Target
 * @param[in] i_ctarget   Fapi2 Connected Target
 * @retval    ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode set_rx_master_mode(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_ctarget )
{
    FAPI_IMP( "I/O Xbus Scominit: Set Master Mode Enter." );
    uint8_t  l_primary_group_id   = 0;
    uint8_t  l_primary_chip_id    = 0;
    uint32_t l_primary_id         = 0;
    uint8_t  l_primary_attr       = 0;
    uint8_t  l_connected_group_id = 0;
    uint8_t  l_connected_chip_id  = 0;
    uint32_t l_connected_id       = 0;
    uint8_t  l_connected_attr     = 0;

    FAPI_TRY( p9_get_proc_fabric_group_id( i_target,  l_primary_group_id   ) );
    FAPI_TRY( p9_get_proc_fabric_group_id( i_ctarget, l_connected_group_id ) );

    FAPI_TRY( p9_get_proc_fabric_chip_id( i_target,  l_primary_chip_id   ) );
    FAPI_TRY( p9_get_proc_fabric_chip_id( i_ctarget, l_connected_chip_id ) );

    l_primary_id   = ( (uint32_t)l_primary_group_id   << 8 ) + (uint32_t)l_primary_chip_id;
    l_connected_id = ( (uint32_t)l_connected_group_id << 8 ) + (uint32_t)l_connected_chip_id;

    FAPI_DBG( "I/O Xbus Scominit: Target ID(%d) Connected ID(%d)", l_primary_id, l_connected_id );

    if( l_primary_id < l_connected_id )
    {
        l_primary_attr   = fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE;
        l_connected_attr = fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_FALSE;
    }
    else
    {
        l_primary_attr   = fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_FALSE;
        l_connected_attr = fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE;
    }

    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_IO_XBUS_MASTER_MODE, i_target, l_primary_attr ),
              "I/O Xbus Scominit: Set Primary Master Mode Attribute Failed." );
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_IO_XBUS_MASTER_MODE, i_ctarget, l_connected_attr ),
              "I/O Xbus Scominit: Set Connected Master Mode Attribute Failed." );

fapi_try_exit:
    FAPI_IMP( "I/O Xbus Scominit: Set Master Mode Exit." );
    return fapi2::current_err;
}

/**
 * @brief Gets the value of the ATTR_PROC_FABRIC_GROUP_ID and passes back by reference
 * @param[in]  i_target    Fapi2 Target
 * @param[out] o_group_id  Group ID
 * @retval     ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode p9_get_proc_fabric_group_id(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    uint8_t&                                        o_group_id)
{
    FAPI_IMP("I/O Xbus Scominit: Get Proc Group Start.");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Retrieve node attribute
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_PROC_FABRIC_GROUP_ID, l_proc, o_group_id ),
              "(PROC): Error getting ATTR_PROC_FABRIC_GROUP_ID, l_rc 0x%.8X",
              (uint64_t)fapi2::current_err );

fapi_try_exit:
    FAPI_IMP("I/O Xbus Scominit: Get Proc Group Exit.");
    return fapi2::current_err;
}

/**
 * @brief Gets the value of the ATTR_PROC_FABRIC_CHIP_ID and passes back by refernce
 * @param[in]  i_target    Fapi2 Target
 * @param[out] o_chip_id   Chip ID
 * @retval     ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode p9_get_proc_fabric_chip_id(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    uint8_t&                                        o_chip_id)
{
    FAPI_IMP("I/O Xbus Scominit: Get Proc Chip Id Start.");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Retrieve pos ID attribute
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_PROC_FABRIC_CHIP_ID, l_proc, o_chip_id ),
              "(PROC): Error getting ATTR_PROC_FABRIC_CHIP_ID, l_rc 0x%.8X",
              (uint64_t)fapi2::current_err );

fapi_try_exit:
    FAPI_IMP("I/O Xbus Scominit: Get Proc Chip Id Exit.");
    return fapi2::current_err;
}

/**
 * @brief Sets the Msb Swap Register based upon an attribute
 * @param[in]  i_tgt    Fapi2 Target
 * @param[out] o_grp    Group
 * @retval     ReturnCode  Fapi2 ReturnCode
 */
fapi2::ReturnCode set_msb_swap(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS > i_tgt,
    const uint8_t                                  i_grp )
{
    FAPI_IMP("Set Msb Swap Start.");
    const uint8_t LN0   = 0;
    uint8_t tx_msb_swap = 0x0;
    uint8_t field_data  = 0x0;

    // Retrieve msb swap attribute
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_EI_BUS_TX_MSBSWAP, i_tgt, tx_msb_swap ),
              "(PROC): Error getting ATTR_EI_BUS_TX_MSB_SWAP, l_rc 0x%.8X",
              (uint64_t)fapi2::current_err );

    switch( i_grp )
    {
        case ENUM_ATTR_XBUS_GROUP_0:
            if( tx_msb_swap & fapi2::ENUM_ATTR_EI_BUS_TX_MSBSWAP_GROUP_0_SWAP )
            {
                field_data = 1;
            }

            break;

        case ENUM_ATTR_XBUS_GROUP_1:
            if( tx_msb_swap & fapi2::ENUM_ATTR_EI_BUS_TX_MSBSWAP_GROUP_1_SWAP )
            {
                field_data = 1;
            }

            break;
    }

    FAPI_TRY( io::rmw( EDIP_TX_MSBSWAP, i_tgt, i_grp, LN0, field_data ) );


fapi_try_exit:
    FAPI_IMP("Set Msb Swap Exit.");
    return fapi2::current_err;
}

