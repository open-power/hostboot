/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_revert_sbe_mcs_setup.C $      */
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
/// @file p9_revert_sbe_mcs_setup.C
/// @brief Revert MC configuration applied by SBE (FAPI2)

///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_revert_sbe_mcs_setup.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Reset SBE applied hostboot dcbz MC configuration for one unit target
///
/// @param[in] i_target Reference to an MC target (MCS/MI)
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode revert_hb_dcbz_config(const fapi2::Target<T>& i_target);


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// specialization for MCS target type
template<>
fapi2::ReturnCode revert_hb_dcbz_config(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_mcfgp;
    fapi2::buffer<uint64_t> l_mcmode1;
    fapi2::buffer<uint64_t> l_mcfirmask;

    // MCFGP -- mark BAR invalid & reset grouping configuration fields
    FAPI_TRY(fapi2::getScom(i_target, MCS_MCFGP, l_mcfgp),
             "Error from getScom (MCS_MCFGP)");
    l_mcfgp.clearBit<MCS_MCFGP_VALID>();
    l_mcfgp.clearBit<MCS_MCFGP_MC_CHANNELS_PER_GROUP,
                     MCS_MCFGP_MC_CHANNELS_PER_GROUP_LEN>();
    l_mcfgp.clearBit<MCS_MCFGP_CHANNEL_0_GROUP_MEMBER_IDENTIFICATION,
                     MCS_MCFGP_CHANNEL_0_GROUP_MEMBER_IDENTIFICATION_LEN>();
    l_mcfgp.clearBit<MCS_MCFGP_GROUP_SIZE, MCS_MCFGP_GROUP_SIZE_LEN>();
    FAPI_TRY(fapi2::putScom(i_target, MCS_MCFGP, l_mcfgp),
             "Error from putScom (MCS_MCFGP)");

    // MCMODE1 -- enable speculation
    FAPI_TRY(fapi2::getScom(i_target, MCS_MCMODE1, l_mcmode1),
             "Error from getScom (MCS_MCMODE1)");
    l_mcmode1.clearBit<MCS_MCMODE1_DISABLE_ALL_SPEC_OPS>();
    l_mcmode1.clearBit<MCS_MCMODE1_DISABLE_SPEC_OP,
                       MCS_MCMODE1_DISABLE_SPEC_OP_LEN>();
    FAPI_TRY(fapi2::putScom(i_target, MCS_MCMODE1, l_mcmode1),
             "Error from putScom (MCS_MCMODE1)");

    // MCFIRMASK -- mask all errors
    l_mcfirmask.flush<1>();
    FAPI_TRY(fapi2::putScom(i_target, MCS_MCFIRMASK_OR, l_mcfirmask),
             "Error from putScom (MCS_MCFIRMASK_OR)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// specialization for MI target type
template<>
fapi2::ReturnCode revert_hb_dcbz_config(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target)
{
    // TODO: implement for Cumulus (MI target)
    return fapi2::current_err;
}


// HWP entry point
fapi2::ReturnCode
p9_revert_sbe_mcs_setup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");

    auto l_mcs_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();

    if (l_mcs_chiplets.size())
    {
        for (auto l_target_mcs : l_mcs_chiplets)
        {
            FAPI_TRY(revert_hb_dcbz_config(l_target_mcs),
                     "Error from revert_hb_dcbz_config (MCS)");
        }
    }
    else
    {
        auto l_mi_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();

        for (auto l_target_mi : l_mi_chiplets)
        {
            FAPI_TRY(revert_hb_dcbz_config(l_target_mi),
                     "Error from revert_hb_dcbz_config (MI)");
        }
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
