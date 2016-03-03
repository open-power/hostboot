/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fbc_smp_utils.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_fbc_smp_utils.H
/// @brief Fabric SMP library functions/constants (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB,FSP
//

#ifndef _P9_FBC_SMP_UTILS_H_
#define _P9_FBC_SMP_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_xbus_scom_addresses.H>
#include <p9_xbus_scom_addresses_fld.H>
#include <p9_obus_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// link types
enum p9_fbc_link_t
{
    ELECTRICAL = fapi2::TARGET_TYPE_XBUS,
    OPTICAL = fapi2::TARGET_TYPE_OBUS
};

// XBUS/ABUS link control structure
struct p9_fbc_link_ctl_t
{
    // associated endpoint target type & unit target number
    p9_fbc_link_t endp_type;
    uint8_t       endp_unit_id;
    // iovalid SCOM addresses/control field
    uint64_t      iovalid_or_addr;
    uint64_t      iovalid_clear_addr;
    uint8_t       iovalid_field_start_bit;
    // EXTFIR/RAS control field
    uint8_t       ras_fir_field_bit;
    // DL layer SCOM addresses
    uint64_t      dl_fir_addr;
    uint64_t      dl_control_addr;
    // TL layer SCOM addresses
    uint64_t      tl_fir_addr;
    uint8_t       tl_fir_trained_field_start_bit;
    uint64_t      tl_link_delay_addr;
    uint32_t      tl_link_delay_hi_start_bit;
    uint32_t      tl_link_delay_lo_start_bit;
};

// link constants
const uint32_t P9_FBC_UTILS_MAX_X_LINKS = 7;
const uint32_t P9_FBC_UTILS_MAX_A_LINKS = 4;

const p9_fbc_link_ctl_t P9_FBC_XBUS_LINK_CTL_ARR[P9_FBC_UTILS_MAX_X_LINKS] =
{
    {
        ELECTRICAL,
        0,
        PERV_XB_CPLT_CONF1_OR,
        PERV_XB_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X0_FIR_ERR,
        XBUS_LL0_LL0_LL0_IOEL_FIR_REG,
        XBUS_0_LL0_IOEL_CONTROL,
        PU_PB_IOE_FIR_REG,
        PU_PB_IOE_FIR_REG_FMR00_TRAINED,
        PU_PB_ELINK_DLY_0123_REG,
        4,
        20
    },
    {
        ELECTRICAL,
        1,
        PERV_XB_CPLT_CONF1_OR,
        PERV_XB_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_6D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X1_FIR_ERR,
        XBUS_1_LL1_LL1_LL1_IOEL_FIR_REG,
        XBUS_1_LL1_IOEL_CONTROL,
        PU_PB_IOE_FIR_REG,
        PU_PB_IOE_FIR_REG_FMR02_TRAINED,
        PU_PB_ELINK_DLY_0123_REG,
        36,
        52
    },
    {
        ELECTRICAL,
        2,
        PERV_XB_CPLT_CONF1_OR,
        PERV_XB_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_8D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X2_FIR_ERR,
        XBUS_2_LL2_LL2_LL2_IOEL_FIR_REG,
        XBUS_2_LL2_IOEL_CONTROL,
        PU_PB_IOE_FIR_REG,
        PU_PB_IOE_FIR_REG_FMR04_TRAINED,
        PU_PB_ELINK_DLY_45_REG,
        4,
        20
    },
    {
        OPTICAL,
        0,
        PERV_OB0_CPLT_CONF1_OR,
        PERV_OB0_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X3_FIR_ERR,
        OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG,
        OBUS_0_LL0_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR00_TRAINED,
        PU_IOE_PB_OLINK_DLY_0123_REG,
        4,
        20
    },
    {
        OPTICAL,
        1,
        PERV_OB1_CPLT_CONF1_OR,
        PERV_OB1_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X4_FIR_ERR,
        OBUS_1_LL1_LL1_LL1_PB_IOOL_FIR_REG,
        OBUS_1_LL1_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR02_TRAINED,
        PU_IOE_PB_OLINK_DLY_0123_REG,
        36,
        52
    },
    {
        OPTICAL,
        2,
        PERV_OB2_CPLT_CONF1_OR,
        PERV_OB2_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X5_FIR_ERR,
        OBUS_2_LL2_LL2_LL2_PB_IOOL_FIR_REG,
        OBUS_2_LL2_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR04_TRAINED,
        PU_IOE_PB_OLINK_DLY_4567_REG,
        4,
        20
    },
    {
        OPTICAL,
        3,
        PERV_OB3_CPLT_CONF1_OR,
        PERV_OB3_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X6_FIR_ERR,
        OBUS_3_LL3_LL3_LL3_PB_IOOL_FIR_REG,
        OBUS_3_LL3_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR06_TRAINED,
        PU_IOE_PB_OLINK_DLY_4567_REG,
        36,
        52
    }
};

const p9_fbc_link_ctl_t P9_FBC_ABUS_LINK_CTL_ARR[P9_FBC_UTILS_MAX_A_LINKS] =
{
    {
        OPTICAL,
        0,
        PERV_OB0_CPLT_CONF1_OR,
        PERV_OB0_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X3_FIR_ERR,
        OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG,
        OBUS_0_LL0_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR00_TRAINED,
        PU_IOE_PB_OLINK_DLY_0123_REG,
        4,
        20
    },
    {
        OPTICAL,
        1,
        PERV_OB1_CPLT_CONF1_OR,
        PERV_OB1_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X4_FIR_ERR,
        OBUS_1_LL1_LL1_LL1_PB_IOOL_FIR_REG,
        OBUS_1_LL1_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR02_TRAINED,
        PU_IOE_PB_OLINK_DLY_0123_REG,
        36,
        52
    },
    {
        OPTICAL,
        2,
        PERV_OB2_CPLT_CONF1_OR,
        PERV_OB2_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X5_FIR_ERR,
        OBUS_2_LL2_LL2_LL2_PB_IOOL_FIR_REG,
        OBUS_2_LL2_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR04_TRAINED,
        PU_IOE_PB_OLINK_DLY_4567_REG,
        4,
        20
    },
    {
        OPTICAL,
        3,
        PERV_OB3_CPLT_CONF1_OR,
        PERV_OB3_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X6_FIR_ERR,
        OBUS_3_LL3_LL3_LL3_PB_IOOL_FIR_REG,
        OBUS_3_LL3_IOOL_CONTROL,
        PU_IOE_PB_IOO_FIR_REG,
        PU_IOE_PB_IOO_FIR_REG_FMR06_TRAINED,
        PU_IOE_PB_OLINK_DLY_4567_REG,
        36,
        52
    }
};

// range of fabric node/chip ID fields
const uint8_t P9_FBC_UTILS_NUM_CHIP_IDS = 8;
const uint8_t P9_FBC_UTILS_NUM_GROUP_IDS = 8;


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Utility function to read & return fabric group ID attribute
///
/// @tparam T template parameter, passed in target.
/// @param[in]   i_target          Reference to  chip/chiplet target
/// @param[out]  o_group_id        Group ID value
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<T>& i_target,
    uint8_t& o_group_id);

// Specialization for proc chip target
template<>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t& o_group_id);

// Specialization for XBUS chiplet target
template<>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    uint8_t& o_group_id);

// Specialization for OBUS chiplet target
template<>
fapi2::ReturnCode p9_fbc_utils_get_group_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    uint8_t& o_group_id);

///
/// @brief Utility function to read & return fabric chip ID attribute
///
/// @tparam T template parameter, passed in target.
/// @param[in]   i_target           Reference to chip/chiplet target
/// @param[out]  o_chip_id          chip ID value
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<T>& i_target,
    uint8_t& o_chip_id);

// Specialization for proc chip target
template<>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t& o_chip_id);

// Specialization for XBUS chiplet target
template<>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    uint8_t& o_chip_id);

// Specialization for OBUS chiplet target
template<>
fapi2::ReturnCode p9_fbc_utils_get_chip_id_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    uint8_t& o_chip_id);


#endif // _P9_FBC_SMP_UTILS_H_
