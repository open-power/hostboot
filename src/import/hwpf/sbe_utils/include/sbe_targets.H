/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/sbe_utils/include/sbe_targets.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

// @file sbe_targets.H
// @brief SBE chip types, and methods to get SBE chip type from the fapi target
//
// *HWP HWP Owner: P Rajees <rajerpp1@in.ibm.com>
// *HWP HWP Backup: T Rajeswaran <rajeswgo@in.ibm.com>
// *HWP Team: SBE
// *HWP Consumed by: Cronus:HB
//
#ifndef __SBE_TARGETS__
#define __SBE_TARGETS__

#include "fapi2.H"

namespace sbeutil
{
/**
 *  @brief  Enum to be used while sending a target info to SBE along with
 *          fapi2::target_type and target instance. Will be used in SBE interface
 *          like sbe-attribute library or sbei library.
 *
 */
enum SbeChipType_t : uint8_t
{
    CHIP_TYPE_ANY,          ///< Any chip (will be used for TARGET_TYPE_SYSTEM)
    CHIP_TYPE_ODYSSEY_00,   ///< Odyssey chip 0
    CHIP_TYPE_ODYSSEY_01,   ///< Odyssey chip 1
    CHIP_TYPE_ODYSSEY_02,   ///< Odyssey chip 2
    CHIP_TYPE_ODYSSEY_03,   ///< Odyssey chip 3
    CHIP_TYPE_ODYSSEY_04,   ///< Odyssey chip 4
    CHIP_TYPE_ODYSSEY_05,   ///< Odyssey chip 5
    CHIP_TYPE_ODYSSEY_06,   ///< Odyssey chip 6
    CHIP_TYPE_ODYSSEY_07,   ///< Odyssey chip 7
    CHIP_TYPE_ODYSSEY_08,   ///< Odyssey chip 8
    CHIP_TYPE_ODYSSEY_09,   ///< Odyssey chip 9
    CHIP_TYPE_ODYSSEY_10,   ///< Odyssey chip 10
    CHIP_TYPE_ODYSSEY_11,   ///< Odyssey chip 11
    CHIP_TYPE_ODYSSEY_12,   ///< Odyssey chip 12
    CHIP_TYPE_ODYSSEY_13,   ///< Odyssey chip 13
    CHIP_TYPE_ODYSSEY_14,   ///< Odyssey chip 14
    CHIP_TYPE_ODYSSEY_15,   ///< Odyssey chip 15
};

/**
 * @brief Get the child target of given type and the instance
 *        number from the parent chip target
 * @param[in]   i_chip        Parent chip target
 *
 * @param[out]  o_target      Fapi target
 *
 * @param[in]   i_inst_num    Instance number of the child
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<fapi2::TargetType T>
fapi2::ReturnCode getChildByInstance(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_parentChip,
    fapi2::Target<T>& o_child,
    const uint8_t i_inst_num)
{
    bool l_target_found = false;

    for(auto& l_child : i_parentChip.getChildren<T>(fapi2::TARGET_STATE_PRESENT))
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;
        FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_child, l_unit_pos);

        if(l_unit_pos == i_inst_num)
        {
            o_child = l_child;
            l_target_found = true;
            break;
        }
    }

    FAPI_ASSERT(l_target_found,
                fapi2::SBE_TARGET_ERROR(),
                "Invalid instance number:%d", i_inst_num);
fapi_try_exit:
    return fapi2::current_err;
}

template<>
fapi2::ReturnCode getChildByInstance(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_parentChip,
    fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_child,
    const uint8_t i_inst_num);

template<>
fapi2::ReturnCode getChildByInstance(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_parentChip,
    fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& o_child,
    const uint8_t i_inst_num);

/**
 *  @brief  structure that can encapsulate all details required by sbe to recreate
 *          a fapi target send by host via a chipop
 */
struct SbeTarget
{
        SbeChipType_t        iv_chip_type;
        fapi2::LogTargetType iv_targ_type;
        uint8_t              iv_inst_num;

        /**
         * @brief Performs preliminary checks before returning fapi target
         *        of given type from the sbe target
         *
         * @param[in]   i_chip        Parent chip target that contains
         *                            the fapi target
         *
         * @param[out]  o_target      Fapi target
         *
         * @return FAPI2_RC_SUCCESS on success
         */
        template<fapi2::TargetType T>
        fapi2::ReturnCode convertToFapiTargetWrap(
            const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
            fapi2::Target<T>& o_target);

    private:

        /**
         * @brief Get fapi target of given type from the sbe target
         *
         * @param[in]   i_chip        Parent chip target that contains
         *                            the fapi target
         *
         * @param[out]  o_target      Fapi target
         *
         * @return FAPI2_RC_SUCCESS on success
         */
        template<fapi2::TargetType T>
        fapi2::ReturnCode convertToFapiTarget(
            const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
            fapi2::Target<T>& o_target)
        {
            FAPI_DBG("convertToFapiTarget Entering for type 0x%lX",
                     o_target.getType());

            // For the below targets, this generic template will not work
            //     TARGET_TYPE_SYSTEM: FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS) is invalid
            //                         i_chip.getChildren<T>() is invalid
            //     TARGET_TYPE_OCMB_CHIP: i_chip.getChildren<T>() is invalid
            //     TARGET_TYPE_ANY_POZ_CHIP: is not expected
            //
            //     so we need specialized implementation
            static_assert((T != fapi2::TARGET_TYPE_SYSTEM) &&
                          (T != fapi2::TARGET_TYPE_ANY_POZ_CHIP) &&
                          (T != fapi2::TARGET_TYPE_OCMB_CHIP),
                          "Speciallized implementation required");


            FAPI_TRY(getChildByInstance<T>(i_chip, o_target, iv_inst_num),
                     "getChildByInstance failed");

        fapi_try_exit:
            return fapi2::current_err;
        }

};

/**
 * @brief Get SBE chip type from the OCMB fapi target
 *
 * @param[in]   i_target          Fapi target of type OCMB chip
 *
 * @param[out]  o_sbe_chip_type   SBE chip type
 *
 * @return FAPI2_RC_SUCCESS on success
 */
fapi2::ReturnCode find_ocmb_chip_type(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    SbeChipType_t& o_sbe_chip_type);

//---------------------------------------------------------------------------
/**
 * @brief Get SBE chip type for the OCMB chip's child fapi target
 *
 * @param[in]   i_target          OCMB chip's child fapi target
 *
 * @param[out]  o_sbe_chip_type   SBE chip type
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<fapi2::TargetType T>
fapi2::ReturnCode find_chip_type(
    const fapi2::Target<T>& i_target, SbeChipType_t& o_sbe_chip_type)
{
    FAPI_DBG("find_chip_type Entering for type 0x%lX", i_target.getType());

    // For below target we cant call a getParent<fapi2::TARGET_TYPE_ANY_POZ_CHIP>
    //     so we need speciallized implementation
    static_assert((T != fapi2::TARGET_TYPE_SYSTEM) &&
                  (T != fapi2::TARGET_TYPE_ANY_POZ_CHIP) &&
                  (T != fapi2::TARGET_TYPE_OCMB_CHIP),
                  "Speciallized implementation required");

    const auto l_chip_targ =
        i_target.template getParent<fapi2::TARGET_TYPE_OCMB_CHIP>();
    FAPI_DBG("l_chip_targ.type 0x%lX", l_chip_targ.getType());

    fapi2::ATTR_NAME_Type l_name;
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, l_chip_targ, l_name));
    FAPI_DBG("l_name=%d", l_name);

    switch(l_name)
    {
        case fapi2::ENUM_ATTR_NAME_ODYSSEY:
            {
                const auto l_ocmb_chip_targ =
                    i_target.template getParent<fapi2::TARGET_TYPE_OCMB_CHIP>();
                FAPI_TRY(find_ocmb_chip_type(l_ocmb_chip_targ, o_sbe_chip_type),
                         "find_ocmb_chip_type failed");
            }
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::SBE_TARGET_ERROR(),
                        "Invalid target");
    }

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Get SBE chip type from the system fapi target
 *
 * @param[in]   i_target          Fapi target of type system
 *
 * @param[out]  o_sbe_chip_type   SBE chip type
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<>
fapi2::ReturnCode find_chip_type(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
    SbeChipType_t& o_sbe_chip_type);

/**
 * @brief Get SBE chip type from the POZ chip fapi target
 *
 * @param[in]   i_target          Fapi target of type POZ chip
 *
 * @param[out]  o_sbe_chip_type   SBE chip type
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<>
fapi2::ReturnCode find_chip_type(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    SbeChipType_t& o_sbe_chip_type);

/**
 * @brief Get SBE chip type from the OCMB fapi target
 *
 * @param[in]  i_target          Fapi target of type OCMB chip
 *
 * @param[out] o_sbe_chip_type   SBE chip type
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<>
fapi2::ReturnCode find_chip_type(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    SbeChipType_t& o_sbe_chip_type);

//---------------------------------------------------------------------------

template<fapi2::TargetType T>
fapi2::ReturnCode getInstNum(const fapi2::Target<T>& i_target,
                             uint8_t& o_instNum)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unit_pos));

    o_instNum = l_unit_pos;

fapi_try_exit:
    return fapi2::current_err;
}

template<>
fapi2::ReturnCode getInstNum(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                             uint8_t& o_instNum);

template<>
fapi2::ReturnCode getInstNum(const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_target,
                             uint8_t& o_instNum);

/**
 * @brief Create SBE target from the fapi target
 *
 * @param[in]  i_target         Fapi target
 *
 * @param[out] o_sbe_targ       SBE target
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<fapi2::TargetType T>
fapi2::ReturnCode convertToSbeTarget(
    const fapi2::Target<T>& i_target,
    SbeTarget& o_sbe_targ)
{
    FAPI_DBG("convertToSbeTarget Entering for type 0x%lX", i_target.getType());


    // For below target we this generic template will not work
    //     TARGET_TYPE_SYSTEM: FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS) is invalid
    //     TARGET_TYPE_OCMB_CHIP: instance number shoul be 0 (since sbe is inside OCMB)
    //     TARGET_TYPE_ANY_POZ_CHIP: is not expected
    //
    //     so we need speciallized implementation
    static_assert((T != fapi2::TARGET_TYPE_SYSTEM) &&
                  (T != fapi2::TARGET_TYPE_ANY_POZ_CHIP) &&
                  (T != fapi2::TARGET_TYPE_OCMB_CHIP),
                  "Speciallized implementation required");

    o_sbe_targ.iv_targ_type = fapi2::toLogTargetType<T>();

    FAPI_TRY(getInstNum(i_target, o_sbe_targ.iv_inst_num),
             "getInstNum failed");

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Create SBE target from the fapi system target
 *
 * @param[in]  i_target         Fapi system target
 *
 * @param[out] o_sbe_targ       SBE target
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<>
fapi2::ReturnCode convertToSbeTarget<fapi2::TARGET_TYPE_SYSTEM>(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
    SbeTarget& o_sbe_targ);

/**
 * @brief Create SBE target from the fapi OCMB_CHIP target
 *
 * @param[in]  i_target         Fapi OCMB chip target
 *
 * @param[out] o_sbe_targ       SBE target
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<>
fapi2::ReturnCode convertToSbeTarget<fapi2::TARGET_TYPE_OCMB_CHIP>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    SbeTarget& o_sbe_targ);

/**
 * @brief Wrapper function to create SBE target from the
 *        fapi target
 *
 * @param[in]  i_target         Fapi target
 *
 * @param[out] o_sbe_targ       SBE target
 *
 * @return FAPI2_RC_SUCCESS on success
 */
template<fapi2::TargetType T>
fapi2::ReturnCode convertToSbeTargetWrap(
    const fapi2::Target<T>& i_target,
    SbeTarget& o_sbe_targ)
{
    FAPI_DBG("convertToSbeTargetWrap Entering for type 0x%lX", i_target.getType());
    FAPI_TRY(find_chip_type(i_target, o_sbe_targ.iv_chip_type));

    FAPI_TRY(convertToSbeTarget(i_target, o_sbe_targ));

fapi_try_exit:
    return fapi2::current_err;
}

//---------------------------------------------------------------------------
template<>
fapi2::ReturnCode SbeTarget::convertToFapiTarget(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& o_target);

template<>
fapi2::ReturnCode SbeTarget::convertToFapiTarget(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& o_target);

template<fapi2::TargetType T>
fapi2::ReturnCode SbeTarget::convertToFapiTargetWrap(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
    fapi2::Target<T>& o_target)
{
    FAPI_ASSERT(iv_targ_type == fapi2::toLogTargetType<T>(),
                fapi2::SBE_TARGET_ERROR(),  "Invalid target");

    SbeChipType_t l_chip_type;
    FAPI_TRY(find_chip_type(i_chip, l_chip_type));
    FAPI_ASSERT(iv_chip_type == l_chip_type,
                fapi2::SBE_TARGET_ERROR(),
                "Invalid target");

    FAPI_TRY(convertToFapiTarget(i_chip, o_target),
             "convertToFapiTarget failed");

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace sbe_utils

#endif
