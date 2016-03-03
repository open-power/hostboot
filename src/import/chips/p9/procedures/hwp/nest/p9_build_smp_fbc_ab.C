/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_fbc_ab.C $          */
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
/// @file p9_build_smp_fbc_ab.C
///
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp_fbc_ab.H>
#include <p9_build_smp_adu.H>
#include <p9_fbc_ab_hp_scom.H>
#include <p9_misc_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// PB shadow register constant definition
const uint8_t P9_BUILD_SMP_NUM_SHADOWS = 3;

// HP
const uint64_t PB_HP_MODE_CURR_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PU_PB_WEST_SM0_PB_WEST_HP_MODE_CURR,
    PU_PB_CENT_SM0_PB_CENT_HP_MODE_CURR,
    PU_PB_EAST_HP_MODE_CURR
};

const uint64_t PB_HP_MODE_NEXT_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PU_PB_WEST_SM0_PB_WEST_HP_MODE_NEXT,
    PU_PB_CENT_SM0_PB_CENT_HP_MODE_NEXT,
    PU_PB_EAST_HP_MODE_NEXT
};

// HPX
const uint64_t PB_HPX_MODE_CURR_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PU_PB_WEST_SM0_PB_WEST_HPX_MODE_CURR,
    PU_PB_CENT_SM0_PB_CENT_HPX_MODE_CURR,
    PU_PB_EAST_HPX_MODE_CURR
};

const uint64_t PB_HPX_MODE_NEXT_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PU_PB_WEST_SM0_PB_WEST_HPX_MODE_NEXT,
    PU_PB_CENT_SM0_PB_CENT_HPX_MODE_NEXT,
    PU_PB_EAST_HPX_MODE_NEXT
};

// HPA
const uint64_t PB_HPA_MODE_CURR_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PU_PB_WEST_SM0_PB_WEST_HPA_MODE_CURR,
    PU_PB_CENT_SM0_PB_CENT_HPA_MODE_CURR,
    PU_PB_EAST_HPA_MODE_CURR
};

const uint64_t PB_HPA_MODE_NEXT_SHADOWS[P9_BUILD_SMP_NUM_SHADOWS] =
{
    PU_PB_WEST_SM0_PB_WEST_HPA_MODE_NEXT,
    PU_PB_CENT_SM0_PB_CENT_HPA_MODE_NEXT,
    PU_PB_EAST_HPA_MODE_NEXT
};


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Read and consistency check hotplug shadow register set
///
/// @param[in] i_target        Processor chip target
/// @param[in] i_shadow_regs   Array of hotplug shadow register addresses
/// @param[out] o_data         Hotplug register data
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_build_smp_get_hp_ab_shadow(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target,
    const uint64_t i_shadow_regs[],
    fapi2::buffer<uint64_t>& o_data)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_scom_data;

    // check consistency of west/center/east register copies
    for (uint8_t rr = 0; rr < P9_BUILD_SMP_NUM_SHADOWS; rr++)
    {
        FAPI_TRY(fapi2::getScom(i_target, i_shadow_regs[rr], l_scom_data),
                 "Error from getScom (0x%016llX)", i_shadow_regs[rr]);
        // raise error if shadow copies aren't equal
        FAPI_ASSERT((rr == 0) || (l_scom_data == o_data),
                    fapi2::P9_BUILD_SMP_HOTPLUG_SHADOW_ERR()
                    .set_TARGET(i_target)
                    .set_ADDRESS0(i_shadow_regs[rr - 1])
                    .set_ADDRESS1(i_shadow_regs[rr])
                    .set_DATA0(o_data)
                    .set_DATA1(l_scom_data),
                    "Shadow copies are not equivalent");
        // set output (will be used to compare with next HW read)
        o_data = l_scom_data;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Write hotplug shadow register set
///
/// @param[in] i_target        Processor chip target
/// @param[in] i_shadow_regs   Array of hotplug shadow register addresses
/// @param[in] i_data          Hotplug register data to write
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_build_smp_set_hp_ab_shadow(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target,
    const uint64_t i_shadow_regs[],
    fapi2::buffer<uint64_t>& i_data)
{
    FAPI_DBG("Start");

    // write data to all shadows
    for (uint8_t rr = 0; rr < P9_BUILD_SMP_NUM_SHADOWS; rr++)
    {
        FAPI_TRY(fapi2::putScom(i_target, i_shadow_regs[rr], i_data),
                 "Error from putScom (0x%016llX)", i_shadow_regs[rr]);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Copy all hotplug content from NEXT->CURR
///
/// @param[in] i_target        Processor chip target
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_build_smp_copy_hp_ab_next_curr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_hp_mode_data;
    fapi2::buffer<uint64_t> l_hpx_mode_data;
    fapi2::buffer<uint64_t> l_hpa_mode_data;

    // read NEXT
    FAPI_TRY(p9_build_smp_get_hp_ab_shadow(i_target, PB_HP_MODE_NEXT_SHADOWS, l_hp_mode_data),
             "Error from p9_build_smp_get_hp_ab_shadow (HP_MODE)");
    FAPI_TRY(p9_build_smp_get_hp_ab_shadow(i_target, PB_HPX_MODE_NEXT_SHADOWS, l_hpx_mode_data),
             "Error from p9_build_smp_get_hp_ab_shadow (HPX_MODE)");
    FAPI_TRY(p9_build_smp_get_hp_ab_shadow(i_target, PB_HPA_MODE_NEXT_SHADOWS, l_hpa_mode_data),
             "Error from p9_build_smp_get_hp_ab_shadow (HPA_MODE)");

    // write CURR
    FAPI_TRY(p9_build_smp_set_hp_ab_shadow(i_target, PB_HP_MODE_CURR_SHADOWS, l_hp_mode_data),
             "Error from p9_build_smp_set_hp_ab_shadow (HP_MODE)");
    FAPI_TRY(p9_build_smp_set_hp_ab_shadow(i_target, PB_HPX_MODE_CURR_SHADOWS, l_hpx_mode_data),
             "Error from p9_build_smp_set_hp_ab_shadow (HPX_MODE)");
    FAPI_TRY(p9_build_smp_set_hp_ab_shadow(i_target, PB_HPA_MODE_CURR_SHADOWS, l_hpa_mode_data),
             "Error from p9_build_smp_set_hp_ab_shadow (HPA_MODE)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Copy all hotplug content from CURR->NEXT
///
/// @param[in] i_target        Processor chip target
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_build_smp_copy_hp_ab_curr_next(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_hp_mode_data;
    fapi2::buffer<uint64_t> l_hpx_mode_data;
    fapi2::buffer<uint64_t> l_hpa_mode_data;

    // read CURR
    FAPI_TRY(p9_build_smp_get_hp_ab_shadow(i_target, PB_HP_MODE_CURR_SHADOWS, l_hp_mode_data),
             "Error from p9_build_smp_get_hp_ab_shadow (HP_MODE)");
    FAPI_TRY(p9_build_smp_get_hp_ab_shadow(i_target, PB_HPX_MODE_CURR_SHADOWS, l_hpx_mode_data),
             "Error from p9_build_smp_get_hp_ab_shadow (HPX_MODE)");
    FAPI_TRY(p9_build_smp_get_hp_ab_shadow(i_target, PB_HPA_MODE_CURR_SHADOWS, l_hpa_mode_data),
             "Error from p9_build_smp_get_hp_ab_shadow (HPA_MODE)");

    // write NEXT
    FAPI_TRY(p9_build_smp_set_hp_ab_shadow(i_target, PB_HP_MODE_NEXT_SHADOWS, l_hp_mode_data),
             "Error from p9_build_smp_set_hp_ab_shadow (HP_MODE)");
    FAPI_TRY(p9_build_smp_set_hp_ab_shadow(i_target, PB_HPX_MODE_NEXT_SHADOWS, l_hpx_mode_data),
             "Error from p9_build_smp_set_hp_ab_shadow (HPX_MODE)");
    FAPI_TRY(p9_build_smp_set_hp_ab_shadow(i_target, PB_HPA_MODE_NEXT_SHADOWS, l_hpa_mode_data),
             "Error from p9_build_smp_set_hp_ab_shadow (HPA_MODE)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see comments above function prototype in header
fapi2::ReturnCode p9_build_smp_set_fbc_ab(p9_build_smp_system& i_smp,
        const p9_build_smp_operation i_op)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // quiesce 'slave' fabrics in preparation for joining
    //   PHASE1 -> quiesce all chips except the chip which is the new fabric master
    //   PHASE2 -> quiesce all drawers except the drawer containing the new fabric master
    FAPI_TRY(p9_build_smp_sequence_adu(i_smp, i_op, QUIESCE),
             "Error from p9_build_smp_sequence_adu (QUIESCE)");

    // program NEXT register set for all chips via initfile
    // program CURR register set only for chips which were just quiesced
    for (auto g_iter = i_smp.groups.begin();
         g_iter != i_smp.groups.end();
         ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin();
             p_iter != g_iter->second.chips.end();
             ++p_iter)
        {
            // run initfile HWP (sets NEXT)
            FAPI_EXEC_HWP(l_rc, p9_fbc_ab_hp_scom, *(p_iter->second.target), FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p9_fbc_ab_hp_scom");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            // for chips just quiesced, copy NEXT->CURR
            if (p_iter->second.quiesced_next)
            {
                FAPI_TRY(p9_build_smp_copy_hp_ab_next_curr(*(p_iter->second.target)),
                         "Error from p9_build_smp_copy_hp_ab_next_curr");
            }
        }
    }

    // issue switch AB reconfiguration from chip designated as new master
    // (which is guaranteed to be a master now)
    FAPI_TRY(p9_build_smp_sequence_adu(i_smp, i_op, SWITCH_AB),
             "Error from p9_build_smp_sequence_adu (SWITCH_AB)");

    // reset NEXT register set (copy CURR->NEXT) for all chips
    for (auto g_iter = i_smp.groups.begin();
         g_iter != i_smp.groups.end();
         ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin();
             p_iter != g_iter->second.chips.end();
             ++p_iter)
        {

            FAPI_TRY(p9_build_smp_copy_hp_ab_curr_next(*(p_iter->second.target)),
                     "Error from p9_build_smp_copy_hp_ab_curr_next");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
