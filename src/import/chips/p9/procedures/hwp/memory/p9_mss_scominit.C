/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_scominit.C $            */
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
/// @file p9_mss_scominit.C
/// @brief SCOM inits for PHY, MC
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_scominit.H>
#include <p9_mca_scom.H>
#include <p9_ddrphy_scom.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::FAPI2_RC_SUCCESS;

///
/// @brief SCOM inits for PHY, MC
/// @param[in] i_target, the MCBIST
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_scominit( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("Start MSS SCOM init");
    auto l_mca_targets = i_target.getChildren<TARGET_TYPE_MCA>();

    for (auto l_mca_target : l_mca_targets )
    {
        fapi2::ReturnCode l_rc;
        FAPI_EXEC_HWP(l_rc, p9_mca_scom, l_mca_target, i_target, l_mca_target.getParent<fapi2::TARGET_TYPE_MCS>() );

        if (l_rc)
        {
            FAPI_ERR("Error from p9.mca.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        FAPI_EXEC_HWP(l_rc, p9_ddrphy_scom, l_mca_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9.ddrphy.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

fapi_try_exit:
    FAPI_INF("End MSS SCOM init");
    return fapi2::current_err;
}
