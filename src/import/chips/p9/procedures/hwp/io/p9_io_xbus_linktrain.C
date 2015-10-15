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
fapi2::ReturnCode checkMaster(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target);

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
    const uint8_t EDIP_GROUPS     = 2;
    const uint8_t GROUP_BROADCAST = 0x0F; // broadcast to all groups
    uint8_t l_group               = 0;

    EdipTrain l_master;
    EdipTrain l_slave;

    // Check if Master Target is an actual master
    checkMaster(i_master);

#if 0 // While we are doing broadside scoms, group broadcasts will not work.
    FAPI_TRY( slave.start(i_slave, IO_EDIP_STATE_WDERF, GROUP_BROADCAST ),
              "Start Slave EDI+ Xbus Training Failed.");

    FAPI_TRY( master.start(i_master, IO_EDIP_STATE_WDERF, GROUP_BROADCAST ),
              "Start Master EDI+ Xbus Training Failed.");
#else
    static_cast<void>(GROUP_BROADCAST);
    FAPI_TRY( l_slave.start(i_slave, IO_EDIP_STATE_WDERF, 0 ),
              "Start EDI+ Xbus Training On Slave Group 0 Failed.");
    FAPI_TRY( l_slave.start(i_slave, IO_EDIP_STATE_WDERF, 1 ),
              "Start EDI+ Xbus Training On Slave Group 1 Failed.");
    FAPI_TRY( l_master.start(i_master, IO_EDIP_STATE_WDERF, 0 ),
              "Start EDI+ Xbus Training On Master Group 0 Failed.");
    FAPI_TRY( l_master.start(i_master, IO_EDIP_STATE_WDERF, 1 ),
              "Start EDI+ Xbus Training On Master Group 1 Failed.");
#endif

    for(l_group = 0; l_group < EDIP_GROUPS; ++l_group)
    {
        FAPI_TRY(l_master.poll(i_master, i_slave, l_group ),
                 "Polling EDI+ Xbus Training Failed");
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
 * @param[in] i_target Fapi2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode checkMaster(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target)
{
    FAPI_IMP("Entering...");
    const uint8_t EDIP_GROUPS = 2;
    Register<EDIP_RX_CTL_MODE1_E_PG> master_reg;

    for(uint8_t l_group = 0; l_group < EDIP_GROUPS; ++l_group)
    {
        FAPI_TRY(master_reg.read(i_target, l_group), "Reading Master Mode Failed");
        FAPI_ASSERT( (master_reg.get<EDIP_RX_MASTER_MODE>() == 1),
                     fapi2::IO_XBUS_NOT_MASTER().set_TARGET(i_target).set_GROUP(l_group),
                     "I/O Xbus Target is not Master")
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}
