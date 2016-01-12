/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_gpe_init.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_occ_gpe_init.C
/// @brief Initialize or reset the targeted GPE0 and/or GPE1
///
// *HWP HWP Owner: Greg Still  <stillgs@us.ibm.com>
// *HWP FW  Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: HS

///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_RESET {
///         for each GPE,
///             halt the GPE
///             wait for the GPE to become inactive
///             clear instruction address register
///             clear interrupt vector prefix register
///     }
///     if PM_INIT {
///         operation performed by OC firmware.
///         Thus, noop
///     }
///
///  Procedure Prereq:
///     - System clocks are running
///
/// \endverbatim
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_occ_gpe_init.H>

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------
const uint64_t OCC_GPE_HALT = 0x1;

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// OCC GPE Reset Function
//------------------------------------------------------------------------------
/// @brief Reset the targeted GPE0 and/or GPE1
///
/// param[in] i_target   Chip target
/// param[in] i_engine   Targeted engine:  GPE0, GPE1, GPEALL
///
/// @return FAPI2_RC_SUCCESS incase of success or error code
///
fapi2::ReturnCode pm_occ_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9occgpe::GPE_ENGINES i_engine);

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_occ_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode,
    const p9occgpe::GPE_ENGINES i_engine)
{
    FAPI_IMP("p9_pm_occ_gpe_init Enter");

    // Initialization:  perform order or dynamic operations to initialize
    // the GPEs using necessary Platform or Feature attributes.
    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_INF("OCC-GPE initialization and start-up is performed by "
                 "OCC firmware. No action taken here");
    }
    // Reset:  perform reset of GPE engines so that they can be reconfigured
    // and reinitialized
    else if (i_mode == p9pm::PM_RESET)
    {
        if (i_engine == p9occgpe::GPE0 || i_engine == p9occgpe::GPEALL)
        {
            FAPI_TRY(pm_occ_gpe_reset(i_target, p9occgpe::GPE0),
                     "ERROR: Failed to reset GPE0");
        }

        if (i_engine == p9occgpe::GPE1 || i_engine == p9occgpe::GPEALL)
        {
            FAPI_TRY(pm_occ_gpe_reset(i_target, p9occgpe::GPE1),
                     "ERROR: Failed to reset GPE1");
        }
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::PM_OCC_GPE_BAD_MODE().set_BADMODE(i_mode),
                    "Unknown mode 0x%X passed to p9_pm_occ_gpe_init", i_mode);
    }

fapi_try_exit:
    FAPI_IMP("p9_pm_occ_gpe_init Exit");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_occ_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9occgpe::GPE_ENGINES i_engine)
{
    FAPI_IMP("pm_occ_gpe_reset Enter");

    fapi2::buffer<uint64_t> l_data64;
    uint64_t l_controlReg = 0;
    uint64_t l_statusReg = 0;
    uint64_t l_instrAddrReg = 0;
    uint64_t l_intVecReg = 0;
    uint32_t l_pollCount = 10; // poll 10 times
    uint32_t l_timeout = 1; // in micro seconds;

    if (i_engine == p9occgpe::GPE0)
    {
        l_controlReg = PU_GPE0_PPE_XIXCR;
        l_statusReg = PU_GPE0_GPEXIXSR_SCOM;
        l_instrAddrReg = PU_GPE0_PPE_XIDBGPRO;
        l_intVecReg = PU_GPE0_GPEIVPR_SCOM;
    }
    else if (i_engine == p9occgpe::GPE1)
    {
        l_controlReg = PU_GPE1_PPE_XIXCR;
        l_statusReg = PU_GPE1_GPEXIXSR_SCOM;
        l_instrAddrReg = PU_GPE1_PPE_XIDBGPRO;
        l_intVecReg = PU_GPE1_GPEIVPR_SCOM;
    }

    // Halt the OCC GPE
    l_data64.flush<0>().insertFromRight(OCC_GPE_HALT, 1, 3);
    FAPI_TRY(putScom(i_target, l_controlReg, l_data64),
             "ERROR: Failed to halt the OCC GPE");

    // Wait for OCC GPE to halt
    do
    {
        FAPI_TRY(fapi2::getScom(i_target, l_statusReg, l_data64),
                 "ERROR: Failed to get the OCC GPE status");

        if (l_data64.getBit<0>() == 1)
        {
            FAPI_INF("OCC GPE has been halted");
            break;
        }

        FAPI_TRY(fapi2::delay(l_timeout * 1000, 200000),
                 " fapi2::delay Failed. ");   // In microseconds
    }
    while(--l_pollCount != 0);

    FAPI_ASSERT((l_pollCount != 0),
                fapi2::PM_OCC_GPE_RESET_TIMEOUT()
                .set_OCCGPESTATUS(l_data64),
                "OCC GPE could not be halted during reset operation.");

    //Clear status (Instruction Address) register
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, l_instrAddrReg, l_data64),
             "ERROR: Failed to Clear the status register");

    //Clear Interrupt vector prefix register
    FAPI_TRY(putScom(i_target, l_intVecReg, l_data64),
             "ERROR: Failed to clear interrupt vector prefix register");

fapi_try_exit:
    return fapi2::current_err;
}
