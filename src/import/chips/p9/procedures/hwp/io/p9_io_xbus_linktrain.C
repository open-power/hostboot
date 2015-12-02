/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_linktrain.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_io_xbus_linktrain.C
/// @brief I/O Link Training on the Xbus Links.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Train the link through several steps (WDERF).
///     - (W) Wiretest
///     - (D) Deskew
///     - (E) Eye Optimization
///     - (R) Repair/Recal
///     - (F) Functional
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///     - Dccal Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_xbus_linktrain.H>
#include <p9_io_gcr.H>
#include <p9_io_regs.H>
#include <p9_io_edip_train.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------
fapi2::ReturnCode check_master(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group);

/**
 * @brief A HWP that runs on every instance of the XBUS(EDI+)
 * @param[in] i_master Reference to the Master Target
 * @param[in] i_slave  Reference to the Slave Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_linktrain(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_master,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_slave)
{
    FAPI_IMP("I/O Start Xbus Training");
    const uint8_t EDIP_GROUPS = 2;
    uint8_t l_group           = 0;
    char master_string[fapi2::MAX_ECMD_STRING_LEN];
    char slave_string[fapi2::MAX_ECMD_STRING_LEN];

    fapi2::toString(i_master, master_string, fapi2::MAX_ECMD_STRING_LEN);
    fapi2::toString(i_slave,  slave_string, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_DBG("I/O Xbus Targets: Master(%s) Slave(%s)",
             master_string,
             slave_string);

    EdipTrain l_master;
    EdipTrain l_slave;

    // Start Training on all groups
    for(l_group = 0; l_group < EDIP_GROUPS; ++l_group)
    {

        // Check if master target is actually master.
        FAPI_TRY( check_master( i_master, l_group ),
                  "Target(%s:g%d) is not master.",
                  master_string, l_group);

        // Start Slave Target First
        FAPI_TRY( l_slave.start( i_slave, IO_EDIP_STATE_WDERF, l_group ),
                  "Start EDI+ Xbus Training On Slave Group(%d) Failed.",
                  l_group);

        FAPI_TRY( l_master.start( i_master, IO_EDIP_STATE_WDERF, l_group ),
                  "Start EDI+ Xbus Training On Master Group(%d) Failed.",
                  l_group);
    }

    // Poll for Training to complete on all Groups
    for(l_group = 0; l_group < EDIP_GROUPS; ++l_group)
    {
        FAPI_TRY(l_master.poll( i_master, i_slave, l_group ),
                 "Polling EDI+ Xbus Training Group(%d) Failed",
                 l_group);
    }

fapi_try_exit:

    if( !l_master.isSuccessful() )
    {
        l_master.addErrorInfo(i_master, l_group);
        l_slave.addErrorInfo( i_slave,  l_group);
    }

    FAPI_IMP("I/O End Xbus Training");
    return fapi2::current_err;
}

/**
 * @brief Checks if the Xbus target is set to Master Mode
 * @param[in] i_target        Fapi2 Target
 * @param[in] i_clock_group   Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode check_master(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t& i_clock_group)
{
    FAPI_IMP("Entering...");
    Register<EDIP_RX_CTL_MODE1_E_PG> master_reg;

    FAPI_TRY(master_reg.read(i_target, i_clock_group),
             "Reading Master Mode Failed");

    FAPI_ASSERT( (master_reg.get<EDIP_RX_MASTER_MODE>() == 1),
                 fapi2::IO_XBUS_NOT_MASTER().set_TARGET(i_target).set_GROUP(i_clock_group),
                 "I/O Xbus Target is not Master. Group(%d)",
                 i_clock_group);

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}
