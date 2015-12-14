/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pba_init.C $                 */
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
/// @file p9_pm_pba_init.C
/// @brief Initialize PBA registers for modes PM_INIT, PM_RESET
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_pm_pba_init.H>

// ----------------------------------------------------------------------
// Local Function prototypes
// ----------------------------------------------------------------------

///
/// @brief call pba_slave_setup_init
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_init (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief call pba_slave_reset
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_reset (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief: PgP PBA Setup
///
/// The PBA is 'set up' twice. The first set up is via scan-0 settings or
/// SBE-IPL code to enable the Host Boot image to be injected into the cache
/// of the IPL core.
///
/// This procedure performs the setup that will be done prior to releasing the
/// OCC from reset. This setup serves both the initial boot of OCC as well as
/// for the OCC/PM reset flow performed during runtime.
///
/// PBA slave 0 is reserved to the GPE engines, which must be able to switch
/// modes to read from mainstore or Centaur inband SCOM spaces, and write
/// Centaur inband SCOMs and also write into mainstore using IMA to support
/// the Power Proxy Trace application.
///
/// PBA slave 1 is dedicated to the 405 ICU/DCU. This PBA slave is used for
/// the initial boot, and for the initial runtime code that manages the OCC
/// applet table.  Once OCC has initialzied applets, OCC FW will remove all
/// TLB mappings associated with mainstore, effectively disabling this slave.
///
/// PBA Slave 2 is dedicated to the SGPE. Since 24x7 performance monitoring
/// code can run on the SGPE, the SGPE is not only a read-only master, but is
/// a generic read-write master like all of the others.
///
/// PBA Slave 3 is mapped to the OCB in order to service FSP direct read/write
/// of mainstore.
///
/// The design of PBA allows read buffers to be dedicated to a particular
/// slave, and requires that a slave have a dedicated read buffer in order to
/// do aggressive prefetching. In the end there is little reason to partition
/// the resources.  The SGPE will be running multiple applications that
/// read and write main memory so we want to allow SGPE access to all
/// resources.  It also isn't clear that aggressive prefetching provides any
/// performacne boost. Another wrinkle is that the BCDE claims read buffer C
/// whenever it runs, and the 405 I + D sides never run after the initial OCC
/// startup. For these reasons all slaves are programmed to share all
/// resources.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_slave_setup (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief Walk each slave to hit the respective reset and then poll for
///        completion
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_slave_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Stop the BCDE and BCUE and then poll for respective completion
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_bc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
fapi2::ReturnCode p9_pm_pba_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP(" Entering p9_pm_pba_init");

    FAPI_IMP("p9_pm_pba_init Exit");
    return fapi2::current_err;
}

// ***************************** mode = PM_RESET ******************************
fapi2::ReturnCode pba_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pba_reset ...");

    return fapi2::current_err;
}

// ***************************** mode = PM_INIT *****************************
fapi2::ReturnCode pba_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pba_init ...");

    return fapi2::current_err;
}

// ******************************** pba_slave_setup ***************************
fapi2::ReturnCode pba_slave_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pba_slave_setup");

    return fapi2::current_err;
}

// ************************** pba_slave_reset **********************************
fapi2::ReturnCode pba_slave_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pba_slave_reset");

    return fapi2::current_err;
}

// ****************************** pba_bc_stop **********************************
fapi2::ReturnCode pba_bc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pba_bc_stop...");

    return fapi2::current_err;
}
