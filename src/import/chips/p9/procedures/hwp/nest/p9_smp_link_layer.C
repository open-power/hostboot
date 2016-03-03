/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_smp_link_layer.C $            */
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
/// @file p9_smp_link_layer.C
/// @brief Start SMP DLL/link layer (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_smp_link_layer.H>
#include <p9_fbc_smp_utils.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Engage DLL/TL training for a single fabric link (X/A)
///
/// @param[in] i_target  Reference to processor chip target
/// @param[in] i_ctl     Reference to link control structure
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_smp_link_layer_train_link(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                             const p9_fbc_link_ctl_t& i_ctl)

{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dll_control;

    FAPI_TRY(fapi2::getScom(i_target, i_ctl.dl_control_addr, l_dll_control),
             "Error reading DLL control register!");
    // optical (IOOOL)/electrical (IOEL) control registers share common bit layout
    l_dll_control.setBit<XBUS_LL0_IOEL_CONTROL_LINK0_STARTUP>();
    l_dll_control.setBit<XBUS_LL0_IOEL_CONTROL_LINK1_STARTUP>();
    FAPI_TRY(fapi2::putScom(i_target, i_ctl.dl_control_addr, l_dll_control),
             "Error writing DLL control register!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_smp_link_layer(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const bool i_train_electrical,
                  const bool i_train_optical)
{
    FAPI_INF("Start");

    // logical link (X/A) configuration parameters
    // enable on local end
    uint8_t l_x_en[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_en[P9_FBC_UTILS_MAX_A_LINKS];

    // process set of enabled links
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");

    for (uint8_t l_link = 0; l_link < P9_FBC_UTILS_MAX_X_LINKS; l_link++)
    {
        if (l_x_en[l_link])
        {
            if ((i_train_electrical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link].endp_type == ELECTRICAL)) ||
                (i_train_optical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link].endp_type == OPTICAL)))
            {
                FAPI_DBG("Training link X%d", l_link);
                FAPI_TRY(p9_smp_link_layer_train_link(i_target,
                                                      P9_FBC_XBUS_LINK_CTL_ARR[l_link]),
                         "Error from p9_smp_link_layer_train_link (X)");
            }
        }
        else
        {
            FAPI_DBG("Skipping link X%d", l_link);
        }
    }

    for (uint8_t l_link = 0; l_link < P9_FBC_UTILS_MAX_A_LINKS; l_link++)
    {
        if (l_a_en[l_link])
        {
            if (i_train_optical &&
                (P9_FBC_ABUS_LINK_CTL_ARR[l_link].endp_type == OPTICAL))
            {
                FAPI_DBG("Training link A%d", l_link);
                FAPI_TRY(p9_smp_link_layer_train_link(i_target,
                                                      P9_FBC_ABUS_LINK_CTL_ARR[l_link]),
                         "Error from p9_smp_link_layer_train_link (A)");
            }
        }
        else
        {
            FAPI_DBG("Skipping link A%d", l_link);
        }
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
