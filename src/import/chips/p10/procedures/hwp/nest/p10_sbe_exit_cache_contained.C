/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_exit_cache_contained.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file p10_sbe_exit_cache_contained.C
/// @brief Execute sequence of HWP calls on SBE to exit HB cache
///        containment
///        - Stop instructions on active cores
///        - Revert MC setup in place to support HB execution in cache
///          contained footprint
///        - Configures MC/MCD BAR resources on all sockets, via XSCOM
///        - Purges active/backing caches and resets contained mode
///          configuration
///        - Restarts instructions on master core to relaunch HB from
///          main memory

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_sbe_exit_cache_contained.H>
#include <p10_sbe_stop_hb.H>
#include <p10_revert_sbe_mcs_setup.H>
#include <p10_sbe_apply_xscom_inits.H>
#include <p10_sbe_purge_hb.H>
#include <p10_sbe_instruct_start.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Process input target and associated attributes to generate set of
///        core targets needed for HWP calls
///
/// @param[in]  i_target                Reference to processor chip target
/// @param[inout] io_steps              Requested HWP steps, will be modified
///                                     based on attributes of input target
/// @param[out] o_active_core_targets   Set of targets to process which are
///                                     associated with active cores
///                                     (running HB code)
/// @param[out] o_backing_cache_targets Set of targets to process which are
///                                     associated with backing caches
/// @param[out] o_master_core_target    Designated HB master core target,
///                                     should lie in set of active core targets
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p10_sbe_exit_cache_contained_validate_inputs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p10_sbe_exit_cache_contained_step_t& io_steps,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& o_active_core_targets,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& o_backing_cache_targets,
    fapi2::Target<fapi2::TARGET_TYPE_CORE>& o_master_core_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_IPL_PHASE_Type l_ipl_type;
    fapi2::ATTR_PROC_SBE_MASTER_CHIP_Type l_is_master_sbe;
    fapi2::ATTR_IS_MPIPL_Type l_is_mpipl;
    fapi2::ATTR_MASTER_CORE_Type l_master_core_num;
    fapi2::ATTR_ACTIVE_CORES_VEC_Type l_attr_active_cores_vec;
    fapi2::ATTR_ACTIVE_CORES_VEC_Type l_attr_backing_caches_vec;
    fapi2::buffer<uint32_t> l_active_cores;
    fapi2::buffer<uint32_t> l_backing_caches;
    bool l_master_core_found = false;

    // validate that HWP steps should be run -- only desire to run on the
    // master SBE in a non-MPIPL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP,
                           i_target,
                           l_is_master_sbe),
             "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL,
                           FAPI_SYSTEM,
                           l_is_mpipl),
             "Error from FAPI_ATTR_GET (ATTR_IS_MPIPL)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE,
                           FAPI_SYSTEM,
                           l_ipl_type),
             "Error from FAPI_ATTR_GET (ATTR_SYSTEM_IPL_PHASE)");


    if ((l_ipl_type != fapi2::ENUM_ATTR_SYSTEM_IPL_PHASE_HB_IPL) ||
        (l_is_master_sbe != fapi2::ENUM_ATTR_PROC_SBE_MASTER_CHIP_TRUE) ||
        (l_is_mpipl != fapi2::ENUM_ATTR_IS_MPIPL_FALSE))
    {
        io_steps = p10_sbe_exit_cache_contained_step_t::SKIP_ALL;
        goto fapi_try_exit;
    }

    // validate and generate set of targets for HWP steps to use
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MASTER_CORE,
                           i_target,
                           l_master_core_num),
             "Error from FAPI_ATTR_GET (ATTR_MASTER_CORE)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ACTIVE_CORES_VEC,
                           i_target,
                           l_attr_active_cores_vec),
             "Error on FAPI_ATTR_GET (ATTR_ACTIVE_CORES_VEC)");
    l_active_cores = l_attr_active_cores_vec;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BACKING_CACHES_VEC,
                           i_target,
                           l_attr_backing_caches_vec),
             "Error on FAPI_ATTR_GET (ATTR_BACKING_CACHES_VEC)");
    l_backing_caches = l_attr_backing_caches_vec;

    for (auto& l_core_target : i_target.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_core_target,
                               l_core_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        FAPI_ASSERT(!(l_active_cores.getBit(l_core_num) &&
                      l_backing_caches.getBit(l_core_num)),
                    fapi2::P10_SBE_EXIT_CACHE_CONTAINED_ACTIVE_BACKING_OVERLAP_ERR()
                    .set_TARGET(i_target)
                    .set_ACTIVE_CORES(l_active_cores)
                    .set_BACKING_CACHES(l_backing_caches)
                    .set_FIRST_OVERLAP(l_core_num),
                    "Core %d appears in set of both active cores and backing caches!",
                    l_core_num);

        if (l_active_cores.getBit(l_core_num))
        {
            if (l_master_core_num == l_core_num)
            {
                FAPI_ASSERT(!l_master_core_found,
                            fapi2::P10_SBE_EXIT_CACHE_CONTAINED_MULTIPLE_MASTER_ERR()
                            .set_TARGET(i_target)
                            .set_MASTER_CORE(o_master_core_target)
                            .set_MASTER_CORE_NUM(l_master_core_num)
                            .set_CORE_NUM(l_core_num),
                            "Master core: %d found more than once in set of active cores!",
                            l_core_num);

                o_master_core_target = l_core_target;
                l_master_core_found = true;
            }

            o_active_core_targets.push_back(l_core_target);

        }

        if (l_backing_caches.getBit(l_core_num))
        {
            o_backing_cache_targets.push_back(l_core_target);
        }
    }

    FAPI_ASSERT(l_master_core_found,
                fapi2::P10_SBE_EXIT_CACHE_CONTAINED_NO_MASTER_ERR()
                .set_TARGET(i_target)
                .set_MASTER_CORE_NUM(l_master_core_num)
                .set_ACTIVE_CORES(l_active_cores),
                "Master core: %d not found in set of active cores!",
                l_master_core_num);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// doxygen in header
fapi2::ReturnCode
p10_sbe_exit_cache_contained(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const std::vector<std::pair<uint64_t, uint64_t>>& i_reg_inits,
    const p10_sbe_exit_cache_contained_step_t i_steps)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG("Start");

    do
    {
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>> l_active_core_targets;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>> l_backing_cache_targets;
        fapi2::Target<fapi2::TARGET_TYPE_CORE> l_master_core_target;
        p10_sbe_exit_cache_contained_step_t l_steps = i_steps;

        // process input target & set operation
        l_rc = p10_sbe_exit_cache_contained_validate_inputs(
                   i_target,
                   l_steps,
                   l_active_core_targets,
                   l_backing_cache_targets,
                   l_master_core_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p10_sbe_exit_cache_contained_validate_inputs");
            break;
        }

        if (l_steps == p10_sbe_exit_cache_contained_step_t::RUN_ALL ||
            ((l_steps & p10_sbe_exit_cache_contained_step_t::STOP_HB) ==
             p10_sbe_exit_cache_contained_step_t::STOP_HB))
        {
            FAPI_EXEC_HWP(l_rc,
                          p10_sbe_stop_hb,
                          l_active_core_targets);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_sbe_stop_hb");
                break;
            }
        }

        if (l_steps == p10_sbe_exit_cache_contained_step_t::RUN_ALL ||
            ((l_steps & p10_sbe_exit_cache_contained_step_t::REVERT_MCS_SETUP) ==
             p10_sbe_exit_cache_contained_step_t::REVERT_MCS_SETUP))
        {
            FAPI_EXEC_HWP(l_rc,
                          p10_revert_sbe_mcs_setup,
                          i_target);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_revert_sbe_mcs_setup");
                break;
            }
        }

        if (l_steps == p10_sbe_exit_cache_contained_step_t::RUN_ALL ||
            ((l_steps & p10_sbe_exit_cache_contained_step_t::SETUP_MEMORY_BARS) ==
             p10_sbe_exit_cache_contained_step_t::SETUP_MEMORY_BARS))
        {
            FAPI_EXEC_HWP(l_rc,
                          p10_sbe_apply_xscom_inits,
                          i_target,
                          i_reg_inits);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_sbe_apply_xscom_inits");
                break;
            }
        }

        if (l_steps == p10_sbe_exit_cache_contained_step_t::RUN_ALL ||
            ((l_steps & p10_sbe_exit_cache_contained_step_t::PURGE_HB) ==
             p10_sbe_exit_cache_contained_step_t::PURGE_HB))
        {
            FAPI_EXEC_HWP(l_rc,
                          p10_sbe_purge_hb,
                          l_active_core_targets,
                          l_backing_cache_targets);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_sbe_purge_hb");
                break;
            }
        }

        if (l_steps == p10_sbe_exit_cache_contained_step_t::RUN_ALL ||
            ((l_steps & p10_sbe_exit_cache_contained_step_t::RESUME_HB) ==
             p10_sbe_exit_cache_contained_step_t::RESUME_HB))
        {
            FAPI_EXEC_HWP(l_rc,
                          p10_sbe_instruct_start,
                          l_master_core_target,
                          ALL_THREADS);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_sbe_instruct_start");
                break;
            }
        }

    }
    while(0);

    FAPI_DBG("End");
    return l_rc;
}
