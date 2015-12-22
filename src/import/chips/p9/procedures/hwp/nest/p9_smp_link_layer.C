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
/// @brief Start SMP link layer (FAPI2)
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
#include <p9_fbc_utils.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// IOO/IOL control registers share common layout
const uint32_t DLL_CONTROL_LINK0_STARTUP_BIT = XBUS_LL0_IOEL_CONTROL_LINK0_STARTUP;
const uint32_t DLL_CONTROL_LINK1_STARTUP_BIT = XBUS_LL0_IOEL_CONTROL_LINK1_STARTUP;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Engage DLL/TL training for a single fabric link
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_ctl Reference to link control structure
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_smp_link_layer_train_link(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                             const p9_fbc_link_ctl_t& i_ctl)

{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dll_control;

    FAPI_TRY(fapi2::getScom(i_target, i_ctl.dll_control_addr, l_dll_control),
             "Error reading DLL control register!");
    l_dll_control.setBit<DLL_CONTROL_LINK0_STARTUP_BIT>();
    l_dll_control.setBit<DLL_CONTROL_LINK1_STARTUP_BIT>();
    FAPI_TRY(fapi2::putScom(i_target, i_ctl.dll_control_addr, l_dll_control),
             "Error writing DLL control register!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}



fapi2::ReturnCode
p9_smp_link_layer(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");

    uint8_t l_x_en_attr[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_en_attr[P9_FBC_UTILS_MAX_A_LINKS];
    std::vector<std::pair<p9_fbc_link_t, uint8_t>> l_valid_links;
    std::vector<p9_fbc_link_ctl_t> l_link_ctls(P9_FBC_LINK_CTL_ARR,
            P9_FBC_LINK_CTL_ARR + (sizeof(P9_FBC_LINK_CTL_ARR) / sizeof(P9_FBC_LINK_CTL_ARR[0])));
    bool l_ctl_match_found = false;


    // read X/A link enable attributes, extract set of valid links
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG,
                           i_target,
                           l_x_en_attr),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG");

    for (uint8_t x = 0; x < P9_FBC_UTILS_MAX_X_LINKS; x++)
    {
        if (l_x_en_attr[x])
        {
            FAPI_DBG("Adding link X%d", x);
            l_valid_links.push_back(std::make_pair(XBUS, x));
        }
        else
        {
            FAPI_DBG("Skipping link X%d", x);
        }
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG,
                           i_target,
                           l_a_en_attr),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");

    for (uint8_t a = 0; a < P9_FBC_UTILS_MAX_A_LINKS; a++)
    {
        if (l_a_en_attr[a])
        {
            FAPI_DBG("Adding link A%d", a);
            l_valid_links.push_back(std::make_pair(ABUS, a));
        }
        else
        {
            FAPI_DBG("Skipping link A%d", a);
        }
    }

    // for each valid link, search vector table & call link update routine
    for (auto l_link_iter = l_valid_links.begin(); l_link_iter != l_valid_links.end(); l_link_iter++)
    {
        FAPI_DBG("Processing %s%d",
                 (l_link_iter->first == XBUS) ? ("X") : ("A)"),
                 l_link_iter->second);

        l_ctl_match_found = false;

        for (auto l_link_ctl_iter = l_link_ctls.begin();
             (l_link_ctl_iter != l_link_ctls.end()) && (!l_ctl_match_found);
             l_link_ctl_iter++)
        {
            if ((l_link_ctl_iter->link_type == l_link_iter->first) &&
                (l_link_ctl_iter->link_id == l_link_iter->second))
            {
                l_ctl_match_found = true;
                FAPI_TRY(p9_smp_link_layer_train_link(i_target,
                                                      *l_link_ctl_iter),
                         "Error from p9_smp_link_layer_train_link");
            }
        }

        FAPI_ASSERT(l_ctl_match_found,
                    fapi2::P9_SMP_LINK_LAYER_TABLE_ERR().set_TARGET(i_target).
                    set_LINK(l_link_iter->first).
                    set_LINK_ID(l_link_iter->second),
                    "No match found for link");
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
