/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/sbe_utils/src/sbe_targets.C $                 */
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

#include "sbe_targets.H"

using namespace fapi2;

namespace sbeutil
{

ReturnCode find_ocmb_chip_type(
    const Target<TARGET_TYPE_OCMB_CHIP>& i_target,
    SbeChipType_t& o_sbe_chip_type)
{
    FAPI_DBG("find_ocmb_chip_type Entering");
    ATTR_BUS_POS_Type l_bus_pos;
    FAPI_TRY(FAPI_ATTR_GET(ATTR_BUS_POS, i_target, l_bus_pos),
             "ATTR_BUS_POS read failed");
    o_sbe_chip_type = (SbeChipType_t)(CHIP_TYPE_ODYSSEY_00 + l_bus_pos);

fapi_try_exit:
    return current_err;
}

template<>
ReturnCode find_chip_type(
    const Target<TARGET_TYPE_SYSTEM>& i_target, SbeChipType_t& o_sbe_chip_type)
{
    FAPI_DBG("find_chip_type<TARGET_TYPE_SYSTEM> Entering");

    o_sbe_chip_type = CHIP_TYPE_ANY;

fapi_try_exit:
    return current_err;
}

template<>
ReturnCode find_chip_type(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target, SbeChipType_t& o_sbe_chip_type)
{
    Target<TARGET_TYPE_OCMB_CHIP> l_ocmb_chip_targ;
    FAPI_TRY(i_target.template reduceType<TARGET_TYPE_OCMB_CHIP>(l_ocmb_chip_targ),
             "reduceType() failed");
    FAPI_TRY(find_ocmb_chip_type(l_ocmb_chip_targ, o_sbe_chip_type),
             "find_ocmb_chip_type failed");

fapi_try_exit:
    return current_err;
}

template<>
ReturnCode find_chip_type(
    const Target<TARGET_TYPE_OCMB_CHIP>& i_target, SbeChipType_t& o_sbe_chip_type)
{
    FAPI_TRY(find_ocmb_chip_type(i_target, o_sbe_chip_type),
             "find_ocmb_chip_type failed");

fapi_try_exit:
    return current_err;
}

//---------------------------------------------------------------------------
template<>
ReturnCode convertToSbeTarget<TARGET_TYPE_SYSTEM>(
    const Target<TARGET_TYPE_SYSTEM>& i_target,
    SbeTarget& o_sbe_targ)
{
    o_sbe_targ.iv_targ_type = LOG_TARGET_TYPE_SYSTEM;
    o_sbe_targ.iv_inst_num = 0;

fapi_try_exit:
    return current_err;
}

template<>
ReturnCode convertToSbeTarget<TARGET_TYPE_OCMB_CHIP>(
    const Target<TARGET_TYPE_OCMB_CHIP>& i_target,
    SbeTarget& o_sbe_targ)
{
    o_sbe_targ.iv_targ_type = LOG_TARGET_TYPE_OCMB_CHIP;
    o_sbe_targ.iv_inst_num = 0;

fapi_try_exit:
    return current_err;
}

//---------------------------------------------------------------------------
template<>
ReturnCode
SbeTarget::convertToFapiTarget<TARGET_TYPE_SYSTEM>(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
    Target<TARGET_TYPE_SYSTEM>& o_target)
{
    FAPI_ASSERT(iv_inst_num == 0,
                fapi2::SBE_TARGET_ERROR(),
                "Instance number is not zero for the system target");
    o_target = Target<TARGET_TYPE_SYSTEM>();

fapi_try_exit:
    return current_err;
}

template<>
ReturnCode
SbeTarget::convertToFapiTarget<TARGET_TYPE_OCMB_CHIP>(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_chip,
    Target<TARGET_TYPE_OCMB_CHIP>& o_target)
{
    FAPI_ASSERT(iv_inst_num == 0,
                fapi2::SBE_TARGET_ERROR(),
                "Instance number is not zero for the OCMB chip target");
    FAPI_TRY(i_chip.reduceType(o_target), "reduceType failed");

fapi_try_exit:
    return current_err;
}

template<>
fapi2::ReturnCode getChildByInstance(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_parentChip,
    fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_child,
    const uint8_t i_inst_num)
{
    bool l_target_found = false;

    //Note: For the DIMM target, ATTR_CHIP_UNIT_POS is not supported and
    //      the attribute ATTR_REL_POS is always relative to a target's
    //      immediate parent, which is MEM_PORT here. Hence, to find the
    //      given instance of DIMM target of OCMB chip target, the logic
    //      is as follows:
    //          - find the parent MEM_PORT target with CHIP_UNIT_POS = (i_inst_num / 2)
    //          - for that MEM_PORT target, find the child DIMM target with
    //            REL_POS = (i_inst_num % 2)

    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_memport_child;
    uint8_t l_memport_inst = i_inst_num / 2;

    // Here, getChildByInstance() will call the generic implementation
    // that compares instance number with ATTR_CHIP_UNIT_POS to find the
    // MEM_PORT child of OCMB chip target

    FAPI_TRY(getChildByInstance(i_parentChip, l_memport_child, l_memport_inst),
             "getChildByInstance() for the MEM_PORT having instance number %d failed",
             l_memport_inst);

    for(auto& l_dimm :
        l_memport_child.getChildren<fapi2::TARGET_TYPE_DIMM>(fapi2::TARGET_STATE_PRESENT))
    {
        fapi2::ATTR_REL_POS_Type l_rel_pos;
        FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_dimm, l_rel_pos);

        if(l_rel_pos == (i_inst_num % 2))
        {
            o_child = l_dimm;
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
    fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& o_child,
    const uint8_t i_inst_num)
{
    bool l_target_found = false;

    for(auto& l_sensor :
        i_parentChip.getChildren<fapi2::TARGET_TYPE_TEMP_SENSOR>(fapi2::TARGET_STATE_PRESENT))
    {
        fapi2::ATTR_REL_POS_Type l_rel_pos;
        FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_sensor, l_rel_pos);

        if(l_rel_pos == i_inst_num)
        {
            o_child = l_sensor;
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
fapi2::ReturnCode getInstNum(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                             uint8_t& o_instNum)
{
    //Note: For the DIMM target, ATTR_CHIP_UNIT_POS is not supported and
    //      the attribute ATTR_REL_POS is always relative to a target's
    //      immediate parent, which is MEM_PORT here. There is no _POS
    //      attribute that helps to uniquely identify a DIMM target.
    //      identify the DIMM target instance, the logic
    //      is as follows:
    //         DIMM target instance number =
    //          (Parent MEM_PORT target's CHIP_UNIT_POS * 2) +
    //           REL_POS of the DIMM target itself

    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_memport_parent =
        i_target.template getParent<fapi2::TARGET_TYPE_MEM_PORT>();

    fapi2::ATTR_CHIP_UNIT_POS_Type l_chipUnitPos;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_memport_parent, l_chipUnitPos));

    fapi2::ATTR_REL_POS_Type l_relPos;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_relPos));

    o_instNum = (l_chipUnitPos * 2) + l_relPos;

fapi_try_exit:
    return fapi2::current_err;
}

template<>
fapi2::ReturnCode getInstNum(const fapi2::Target<TARGET_TYPE_TEMP_SENSOR>& i_target,
                             uint8_t& o_instNum)
{
    fapi2::ATTR_REL_POS_Type l_relPos;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_relPos));

    o_instNum = l_relPos;

fapi_try_exit:
    return fapi2::current_err;
}

}
