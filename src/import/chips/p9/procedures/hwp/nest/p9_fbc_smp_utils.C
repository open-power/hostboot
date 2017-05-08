/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fbc_smp_utils.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_fbc_smp_utils.C
/// @brief Fabric SMP library functions/constants (FAPI2)
///
/// The functions in this file provide:
/// - Determination of a chip's group/chip ID
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_smp_utils.H>
#include <p9_misc_scom_addresses.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// Specialization for proc chip target. See doxygen in header file.
template<>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t& o_chip_id)
{
    FAPI_DBG("(PROC): Start");
    fapi2::ReturnCode l_rc;

    // Retrieve chip ID attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID,
                           i_target,
                           o_chip_id),
             "(PROC): Error getting ATTR_PROC_FABRIC_CHIP_ID, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Display attribute value
    FAPI_DBG("(PROC): ATTR_PROC_FABRIC_CHIP_ID = 0x%.8X", o_chip_id);

    FAPI_ASSERT(o_chip_id < P9_FBC_UTILS_NUM_CHIP_IDS,
                fapi2::P9_FBC_UTILS_FABRIC_CHIP_ID_ATTR_ERR()
                .set_ATTR_DATA(o_chip_id),
                "(PROC): Invalid fabric chip ID attribute value 0x%02X", o_chip_id);

fapi_try_exit:
    FAPI_DBG("(PROC): End");
    return fapi2::current_err;
}


// Specialization for chiplet targets. See doxygen in header file.
template<>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    uint8_t& o_chip_id)
{
    FAPI_DBG("(XBUS): Start");
    return (p9_fbc_utils_get_chip_id_attr(
                i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                o_chip_id));
}

// Specialization for chiplet targets.  See doxygen in header file.
template<>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    uint8_t& o_chip_id)
{
    FAPI_DBG("(OBUS): Start");
    return (p9_fbc_utils_get_chip_id_attr(
                i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                o_chip_id));
}


// Specialization for proc chip target.  See doxygen in header file.
template<>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t& o_group_id)
{
    FAPI_INF("(PROC): Start");
    fapi2::ReturnCode l_rc;

    // Retrieve group ID attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID,
                           i_target,
                           o_group_id),
             "(PROC): Error getting ATTR_FABRIC_GROUP_ID, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Display attribute value
    FAPI_DBG("(PROC): ATTR_PROC_FABRIC_GROUP_ID = 0x%X", o_group_id);

    FAPI_ASSERT(o_group_id < P9_FBC_UTILS_NUM_GROUP_IDS,
                fapi2::P9_FBC_UTILS_FABRIC_GROUP_ID_ATTR_ERR()
                .set_ATTR_DATA(o_group_id),
                "(PROC): Invalid fabric group ID attribute value 0x%02X", o_group_id);

fapi_try_exit:
    FAPI_DBG("(PROC): End");
    return fapi2::current_err;
}


// Specialization for chiplet targets.  See doxygen in header file.
template<>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    uint8_t& o_group_id)
{
    FAPI_DBG("(XBUS): Start");
    return (p9_fbc_utils_get_group_id_attr(
                i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                o_group_id));
}


// Specialization for chiplet targets.  See doxygen in header file.
template<>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    uint8_t& o_group_id)
{
    FAPI_DBG("(OBUS): Start");
    return (p9_fbc_utils_get_group_id_attr(
                i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                o_group_id));
}
