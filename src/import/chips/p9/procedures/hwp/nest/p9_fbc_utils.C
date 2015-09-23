/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/sbe/p9_fbc_utils.C $                  */
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
/// @file p9_fbc_utils.C
/// @brief Fabric library functions/constants (FAPI2)
///
/// The functions in this file provide:
/// - Information about the instantaneous state of the fabric
/// - Means to restart the fabric after a checkstop condition
///
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE,HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_utils.H>
#include <p9_misc_scom_addresses.H>

extern "C"
{

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// ADU PMisc Register field/bit definitions
    const uint32_t ALTD_SND_MODE_DISABLE_CHECKSTOP_BIT = 19;
    const uint32_t ALTD_SND_MODE_MANUAL_CLR_PB_STOP_BIT = 21;
    const uint32_t ALTD_SND_MODE_PB_STOP_BIT = 22;

// FBC Mode Register field/bit definitions
    const uint32_t PU_FBC_MODE_PB_INITIALIZED_BIT = 0;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

    fapi2::ReturnCode p9_fbc_utils_get_fbc_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        bool& o_is_initialized,
        bool& o_is_running)
    {
        FAPI_DBG("Start");

        // TODO: HW328175
        // fapi2::buffer<uint64_t> l_fbc_mode_data;
        // FAPI_TRY(fapi2::getScom(i_target, PU_FBC_MODE_REG, l_fbc_mode_data),
        //          "Error reading FBC Mode Register");
        // // fabric is initialized if PB_INITIALIZED bit is one/set
        // o_is_initialized = l_fbc_mode_data.getBit<PU_FBC_MODE_PB_INITIALIZED_BIT>();

        // currently, sampling FBC init from PB Mode register is unreliable
        // as init can drop perodically at runtime (based on legacy sleep backoff)
        // until this issue is fixed, just return true to caller
        o_is_initialized = true;

        // read ADU PMisc Mode Register state
        fapi2::buffer<uint64_t> l_pmisc_mode_data;
        FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
                 "Error reading ADU PMisc Mode register");

        // fabric is running if FBC_STOP bit is zero/clear
        o_is_running = !(l_pmisc_mode_data.getBit<ALTD_SND_MODE_PB_STOP_BIT>());

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }


    fapi2::ReturnCode p9_fbc_utils_override_fbc_stop(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");

        // read ADU PMisc Mode Register state
        fapi2::buffer<uint64_t> l_pmisc_mode_data;
        FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
                 "Error reading ADU PMisc Mode register");

        // set bit to disable checkstop forwarding and write back
        l_pmisc_mode_data.setBit<ALTD_SND_MODE_DISABLE_CHECKSTOP_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
                 "Error writing ADU PMisc Mode register to disable checkstop forwarding to FBC");

        // set bit to manually clear stop control and write back
        l_pmisc_mode_data.setBit<ALTD_SND_MODE_MANUAL_CLR_PB_STOP_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
                 "Error writing ADU PMisc Mode register to manually clear FBC stop control");

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }


} // extern "C"
