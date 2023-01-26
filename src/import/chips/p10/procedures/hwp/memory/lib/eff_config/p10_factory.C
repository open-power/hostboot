/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_factory.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
///
/// @file p10_factory.C
/// @brief P10 eff_config decoder factory
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/eff_config/p10_factory.H>

namespace mss
{
namespace efd
{

///
/// @brief Generates the EFD engine based upon the EFD type
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_gen DRAM generation
/// @param[in] i_planar planar config flag (from ATTR_MEM_MRW_IS_PLANAR)
/// @param[in] i_rank_info the current rank info class
/// @param[out] o_efd_engine shared pointer to the EFD engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const uint8_t i_rev,
                          const uint8_t i_gen,
                          const uint8_t i_planar,
                          const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                          std::shared_ptr<mss::efd::ddimm_efd_base>& o_efd_engine)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_DDR4_MAX) ? mss::spd::rev::DDIMM_DDR4_MAX : i_rev;

    // DRAM generation is the biggest switch we have, so doing that switch first
    switch (i_gen)
    {
        case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4:
            {
                if (i_planar == fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_FALSE)
                {
                    // Then switch over the SPD revision
                    switch (l_fallback_rev)
                    {
                        case mss::spd::rev::V0_3:
                            {

                                o_efd_engine = std::make_shared<mss::efd::ddimm_efd_0_3>(i_target, i_rank_info);
                                return fapi2::FAPI2_RC_SUCCESS;
                                break;
                            }

                        case mss::spd::rev::V0_4:
                            {
                                o_efd_engine = std::make_shared<mss::efd::ddimm_efd_0_4>(i_target, i_rank_info);
                                return fapi2::FAPI2_RC_SUCCESS;
                                break;
                            }

                        default:
                            {
                                FAPI_ASSERT(false,
                                            fapi2::MSS_INVALID_SPD_REVISION()
                                            .set_SPD_REVISION(i_rev)
                                            .set_DRAM_GENERATION(i_gen)
                                            .set_IS_PLANAR(i_planar)
                                            .set_FUNCTION_CODE(EFD_FACTORY)
                                            .set_DIMM_TARGET(i_target),
                                            "Unsupported SPD revision(0x%02x) received in %s EFD decoder factory for DDR%u for %s",
                                            i_rev, "DDIMM", 4, spd::c_str(i_target));
                            }
                    }
                }
                else
                {
                    switch (l_fallback_rev)
                    {
                        case mss::spd::rev::V0_4:
                            {
                                o_efd_engine = std::make_shared<mss::efd::planar_rdimm_efd_0_4>(i_target, i_rank_info);
                                return fapi2::FAPI2_RC_SUCCESS;
                                break;
                            }

                        default:
                            {
                                FAPI_ASSERT(false,
                                            fapi2::MSS_INVALID_SPD_REVISION()
                                            .set_SPD_REVISION(i_rev)
                                            .set_DRAM_GENERATION(i_gen)
                                            .set_IS_PLANAR(i_planar)
                                            .set_FUNCTION_CODE(EFD_FACTORY)
                                            .set_DIMM_TARGET(i_target),
                                            "Unsupported SPD revision(0x%02x) received in %s EFD decoder factory for DDR%u for %s",
                                            i_rev, "Planar", 4, spd::c_str(i_target));
                            }
                    }
                }

                break;
            }

        case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5:
            {
                o_efd_engine = std::make_shared<mss::efd::ddr5::ddimm_0_0>(i_target, i_rank_info);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_REVISION()
                            .set_SPD_REVISION(i_rev)
                            .set_DRAM_GENERATION(i_gen)
                            .set_IS_PLANAR(i_planar)
                            .set_FUNCTION_CODE(EFD_FACTORY)
                            .set_DIMM_TARGET(i_target),
                            "Unsupported DRAM generation received in EFD decoder factory 0x%02x for %s",
                            i_gen, spd::c_str(i_target));
            }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns efd

namespace spd
{

///
/// @brief Generates the base module SPD engine based upon the rev/DRAM generation
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_gen DRAM generation
/// @param[out] o_base_engine shared pointer to the Base cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode base_module_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const uint8_t i_rev,
                                      const uint8_t i_gen,
                                      std::shared_ptr<mss::spd::base_cnfg_base>& o_base_engine)
{
    uint8_t l_fallback_rev = 0;

    // DRAM generation is the biggest switch we have, so doing that switch first
    switch (i_gen)
    {
        case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4:
            // Poor man's fallback technique: if we receive a revision that's later than (or numerically
            // greater than) the latest supported, we'll decode as if it's the latest supported rev
            l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_DDR4_MAX) ? mss::spd::rev::DDIMM_DDR4_MAX : i_rev;

            // Then switch over the SPD revision
            switch (l_fallback_rev)
            {
                case mss::spd::rev::V0_3:
                    {
                        o_base_engine = std::make_shared<mss::spd::base_0_3>(i_target);
                        //o_ddimm_engine = std::make_shared<mss::spd::ddimm_0_3>(i_target);
                        return fapi2::FAPI2_RC_SUCCESS;
                        break;
                    }

                case mss::spd::rev::V0_4:
                    {
                        o_base_engine = std::make_shared<mss::spd::base_0_4>(i_target);
                        //o_ddimm_engine = std::make_shared<mss::spd::ddimm_0_4>(i_target);
                        return fapi2::FAPI2_RC_SUCCESS;
                        break;
                    }

                default:
                    {
                        FAPI_ASSERT(false,
                                    fapi2::MSS_INVALID_SPD_REVISION()
                                    .set_SPD_REVISION(i_rev)
                                    .set_DRAM_GENERATION(i_gen)
                                    .set_FUNCTION_CODE(SPD_FACTORY)
                                    .set_DIMM_TARGET(i_target),
                                    "Unsupported SPD revision(0x%02x) received in SPD decoder factory for DDR%u for %s",
                                    i_rev, 4, spd::c_str(i_target));
                        break;
                    }
            }

            break;

        case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5:
            // Poor man's fallback technique: if we receive a revision that's later than (or numerically
            // greater than) the latest supported, we'll decode as if it's the latest supported rev
            l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_DDR5_MAX) ? mss::spd::rev::DDIMM_DDR5_MAX : i_rev;
            o_base_engine = std::make_shared<mss::spd::ddr5::base_0_0>(i_target);
            return fapi2::FAPI2_RC_SUCCESS;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_SPD_REVISION()
                        .set_SPD_REVISION(i_rev)
                        .set_DRAM_GENERATION(i_gen)
                        .set_FUNCTION_CODE(SPD_FACTORY)
                        .set_DIMM_TARGET(i_target),
                        "Unsupported DRAM generation received in SPD decoder factory 0x%02x for %s",
                        i_gen, spd::c_str(i_target));
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

namespace ddr4
{

///
/// @brief Generates the DDR4 DDIMM module SPD engine based upon the SPD rev
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[out] o_module_specific_engine shared pointer to the module specific cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode ddimm_module_specific_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rev,
        std::shared_ptr<mss::spd::module_specific_base>& o_module_specific_engine)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_DDR4_MAX) ? mss::spd::rev::DDIMM_DDR4_MAX : i_rev;

    // Then switch over the SPD revision
    switch (l_fallback_rev)
    {
        case mss::spd::rev::V0_3:
            {
                o_module_specific_engine = std::make_shared<mss::spd::ddimm_0_3>(i_target);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        case mss::spd::rev::V0_4:
            {
                o_module_specific_engine = std::make_shared<mss::spd::ddimm_0_4>(i_target);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                // Declarations to avoid FAPI_ASSERT compile fails
                const uint8_t DRAM_GEN = fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4;
                const uint8_t DIMM_TYPE = fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM;
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_REVISION_FOR_MODULE_SPECIFC()
                            .set_SPD_REVISION(i_rev)
                            .set_DRAM_GENERATION(DRAM_GEN)
                            .set_DIMM_TYPE(DIMM_TYPE)
                            .set_FUNCTION_CODE(SPD_FACTORY)
                            .set_DIMM_TARGET(i_target),
                            "Unsupported SPD revision(0x%02x) received in SPD decoder factory for DDR%u %sDIMM for %s",
                            i_rev, 4, "D", spd::c_str(i_target));
                break;
            }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Generates the DDR4 planar config RDIMM module SPD engine based upon the SPD rev
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[out] o_module_specific_engine shared pointer to the module specific cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode planar_rdimm_module_specific_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rev,
        std::shared_ptr<mss::spd::module_specific_base>& o_module_specific_engine)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::RDIMM_MAX) ? mss::spd::rev::RDIMM_MAX : i_rev;

    // Then switch over the SPD revision
    switch (l_fallback_rev)
    {
        case mss::spd::rev::V1_1:
            {
                o_module_specific_engine = std::make_shared<mss::spd::planar_rdimm_ddr4_1_1>(i_target);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                // Declarations to avoid FAPI_ASSERT compile fails
                const uint8_t DRAM_GEN = fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4;
                const uint8_t DIMM_TYPE = fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM;
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_REVISION_FOR_MODULE_SPECIFC()
                            .set_SPD_REVISION(i_rev)
                            .set_DRAM_GENERATION(DRAM_GEN)
                            .set_DIMM_TYPE(DIMM_TYPE)
                            .set_FUNCTION_CODE(SPD_FACTORY)
                            .set_DIMM_TARGET(i_target),
                            "Unsupported SPD revision(0x%02x) received in SPD decoder factory for DDR%u %sDIMM for %s",
                            i_rev, 4, "R", spd::c_str(i_target));
                break;
            }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ddr4

namespace ddr5
{

///
/// @brief Generates the DDR5 DDIMM module SPD engine based upon the SPD rev
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[out] o_module_specific_engine shared pointer to the module specific cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode ddimm_module_specific_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rev,
        std::shared_ptr<mss::spd::module_specific_base>& o_module_specific_engine)
{
    // Poor man's fallback technique: if we receive a revision that's later than (or numerically
    // greater than) the latest supported, we'll decode as if it's the latest supported rev
    const uint8_t l_fallback_rev = (i_rev > mss::spd::rev::DDIMM_DDR5_MAX) ? mss::spd::rev::DDIMM_DDR5_MAX : i_rev;

    // Then switch over the SPD revision
    switch (l_fallback_rev)
    {

        case mss::spd::rev::V0_0:
            {
                o_module_specific_engine = std::make_shared<mss::spd::ddr5::ddimm_0_0>(i_target);
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        default:
            {
                // Declarations to avoid FAPI_ASSERT compile fails
                const uint8_t DRAM_GEN = fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5;
                const uint8_t DIMM_TYPE = fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM;
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_REVISION_FOR_MODULE_SPECIFC()
                            .set_SPD_REVISION(i_rev)
                            .set_DRAM_GENERATION(DRAM_GEN)
                            .set_DIMM_TYPE(DIMM_TYPE)
                            .set_FUNCTION_CODE(SPD_FACTORY)
                            .set_DIMM_TARGET(i_target),
                            "Unsupported SPD revision(0x%02x) received in SPD decoder factory for DDR%u %sDIMM for %s",
                            i_rev, 4, "D", spd::c_str(i_target));
                break;
            }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ddr5

///
/// @brief Generates the module specific SPD engines based upon the rev/DRAM generation/DIMM type
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_gen DRAM generation
/// @param[in] i_dimm_type DIMM type
/// @param[out] o_module_specific_engine shared pointer to the module specific cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode module_specific_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rev,
        const uint8_t i_gen,
        const uint8_t i_dimm_type,
        std::shared_ptr<mss::spd::module_specific_base>& o_module_specific_engine)
{

    // DRAM generation is the biggest switch we have, so doing that switch first
    switch (i_gen)
    {
        case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4:

            switch (i_dimm_type)
            {
                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM:
                    return ddr4::ddimm_module_specific_factory(i_target, i_rev, o_module_specific_engine);
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM:
                    return ddr4::planar_rdimm_module_specific_factory(i_target, i_rev, o_module_specific_engine);
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_SPD_REVISION_FOR_MODULE_SPECIFC()
                                .set_SPD_REVISION(i_rev)
                                .set_DRAM_GENERATION(i_gen)
                                .set_DIMM_TYPE(i_dimm_type)
                                .set_FUNCTION_CODE(SPD_FACTORY)
                                .set_DIMM_TARGET(i_target),
                                "Unsupported DIMM_TYPE(0x%02x) received in SPD decoder factory for DDR%u for %s",
                                i_dimm_type, 4, spd::c_str(i_target));
                    break;
            }

            break;

        case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5:
            return ddr5::ddimm_module_specific_factory(i_target, i_rev,  o_module_specific_engine);
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_SPD_REVISION_FOR_MODULE_SPECIFC()
                        .set_SPD_REVISION(i_rev)
                        .set_DRAM_GENERATION(i_gen)
                        .set_DIMM_TYPE(i_dimm_type)
                        .set_FUNCTION_CODE(SPD_FACTORY)
                        .set_DIMM_TARGET(i_target),
                        "Unsupported SPD DRAM_GEN%u for SPD module specific factory for %s",
                        i_gen, spd::c_str(i_target));
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns spd
} // ns mss
