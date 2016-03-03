/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_fbc_cd.C $          */
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
/// @file p9_build_smp_fbc_cd.C
/// @brief  Fabric configuration (hotplug, CD) functions
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp_fbc_cd.H>
#include <p9_build_smp_adu.H>
#include <p9_fbc_cd_hp_scom.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// NOTE: see comments above function prototype in header
fapi2::ReturnCode p9_build_smp_set_fbc_cd(p9_build_smp_system& i_smp)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    for (auto g_iter = i_smp.groups.begin();
         g_iter != i_smp.groups.end();
         ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin();
             p_iter != g_iter->second.chips.end();
             ++p_iter)
        {
            // run initfile HWP(s)
            FAPI_EXEC_HWP(l_rc, p9_fbc_cd_hp_scom, *(p_iter->second.target), FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p9_fbc_cd_hp_scom");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }
        }
    }

    // issue single switch CD to force all updates to occur
    FAPI_TRY(p9_build_smp_sequence_adu(i_smp, SMP_ACTIVATE_PHASE1, SWITCH_CD),
             "Error from p9_build_smp_sequence_adu (SWITCH_CD)");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
