/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_chiplet_scominit.C $          */
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
/// @file p9_chiplet_scominit.C
///
/// @brief SCOM inits to all chiplets (sans Quad)
///

//
// *HWP HW Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 2
// *HWP Consumed by : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_chiplet_scominit.H>
#include <p9_fbc_no_hp_scom.H>
#include <p9_fbc_ioe_tl_scom.H>
#include <p9_fbc_ioe_dl_scom.H>
#include <p9_fbc_ioo_tl_scom.H>
#include <p9_fbc_ioo_dl_scom.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint8_t MCEPS_JITTER_EPSILON = 0x1;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_XBUS>> l_xbus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> l_obus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCA>> l_mca_targets;
    fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_fbc_optics_cfg_mode = { fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP };
    fapi2::buffer<uint64_t> l_mceps;
    fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_eps_read_cycles_t0;
    fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_eps_read_cycles_t1;
    fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_eps_read_cycles_t2;
    FAPI_DBG("Start");


    // apply MC epsilons
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, FAPI_SYSTEM, l_eps_read_cycles_t0),
             "Error from FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES_T0)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, FAPI_SYSTEM, l_eps_read_cycles_t1),
             "Error from FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, FAPI_SYSTEM, l_eps_read_cycles_t2),
             "Error from FAPI_ATTR_GET (ATTR_PROC_EPS_READ_CYCLES_T2)");
    l_mceps.insertFromRight<MCS_PORT02_MCEPSQ_JITTER_EPSILON, MCS_PORT02_MCEPSQ_JITTER_EPSILON_LEN>(MCEPS_JITTER_EPSILON);
    l_mceps.insertFromRight<MCS_PORT02_MCEPSQ_LOCAL_NODE_EPSILON, MCS_PORT02_MCEPSQ_LOCAL_NODE_EPSILON_LEN>
    (l_eps_read_cycles_t0 / 4);
    l_mceps.insertFromRight<MCS_PORT02_MCEPSQ_NEAR_NODAL_EPSILON, MCS_PORT02_MCEPSQ_NEAR_NODAL_EPSILON_LEN>
    (l_eps_read_cycles_t1 / 4);
    l_mceps.insertFromRight<MCS_PORT02_MCEPSQ_REMOTE_NODAL_EPSILON, MCS_PORT02_MCEPSQ_REMOTE_NODAL_EPSILON_LEN>
    (l_eps_read_cycles_t2 / 4);
    l_mceps.insertFromRight<MCS_PORT02_MCEPSQ_GROUP_EPSILON, MCS_PORT02_MCEPSQ_GROUP_EPSILON_LEN>(l_eps_read_cycles_t1 / 4);
    l_mceps.insertFromRight<MCS_PORT02_MCEPSQ_VECTOR_GROUP_EPSILON, MCS_PORT02_MCEPSQ_VECTOR_GROUP_EPSILON_LEN>
    (l_eps_read_cycles_t2 / 4);
    l_mca_targets = i_target.getChildren<fapi2::TARGET_TYPE_MCA>();

    for (auto l_mca_target : l_mca_targets)
    {
        FAPI_TRY(fapi2::putScom(l_mca_target, MCS_PORT02_MCEPSQ, l_mceps),
                 "Error from putScom (MCS_PORT02_MCEPSQ)");
    }

    // apply FBC non-hotplug initfile
    FAPI_DBG("Invoking p9.fbc.no_hp.scom.initfile...");
    FAPI_EXEC_HWP(l_rc, p9_fbc_no_hp_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_no_hp_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    // invoke IOE (XBUS FBC IO) SCOM initfiles
    FAPI_DBG("Invoking p9.fbc.ioe_tl.scom.initfile...");
    FAPI_EXEC_HWP(l_rc, p9_fbc_ioe_tl_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_ioe_tl_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    l_xbus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_XBUS>();

    for (auto l_iter = l_xbus_chiplets.begin();
         l_iter != l_xbus_chiplets.end();
         l_iter++)
    {
        FAPI_DBG("Invoking p9.fbc.ioe_dl.scom.initfile...");
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioe_dl_scom, *l_iter);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioe_dl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    // invoke IOO (OBUS FBC IO) SCOM initfiles
    FAPI_DBG("Invoking p9.fbc.ioo_tl.scom.initfile...");
    FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_tl_scom, i_target);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_ioo_tl_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    l_obus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();

    for (auto l_iter = l_obus_chiplets.begin();
         l_iter != l_obus_chiplets.end();
         l_iter++)
    {
        uint8_t l_unit_pos;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_iter, l_unit_pos),
                 "Error from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, *l_iter, l_fbc_optics_cfg_mode[l_unit_pos]),
                 "Error from FAPI_ATTR_GET(ATTR_OPTICS_CONFIG_MODE)");

        FAPI_DBG("Invoking p9.fbc.ioo_dl.scom.initfile...");
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_dl_scom, *l_iter);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioo_dl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, i_target, l_fbc_optics_cfg_mode),
             "Error from FAPI_ATTR_SET(ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
