/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fbc_utils.H $                 */
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
/// @file p9_fbc_utils.H
/// @brief Fabric library functions/constants (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE,HB
//

#ifndef _P9_FBC_UTILS_H_
#define _P9_FBC_UTILS_H_

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
    XBUS = 0,
    ABUS = 1
};

// link constants
const uint32_t P9_FBC_UTILS_MAX_X_LINKS = 7;
const uint32_t P9_FBC_UTILS_MAX_A_LINKS = 4;

// link control structure (DLL/TL/iovalid/FIRs)
struct p9_fbc_link_ctl_t
{
    p9_fbc_link_t link_type;
    uint8_t       link_id;
    uint64_t      iovalid_or_addr;
    uint64_t      iovalid_clear_addr;
    uint8_t       iovalid_field_start_bit;
    uint8_t       ras_fir_field_bit;
    uint64_t      dll_control_addr;
};

const p9_fbc_link_ctl_t P9_FBC_LINK_CTL_ARR[P9_FBC_UTILS_MAX_X_LINKS + P9_FBC_UTILS_MAX_A_LINKS] =
{
    {
        XBUS,
        0,
        PERV_XB_CPLT_CONF1_OR,
        PERV_XB_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X0_FIR_ERR,
        XBUS_0_LL0_IOEL_CONTROL
    },
    {
        XBUS,
        1,
        PERV_XB_CPLT_CONF1_OR,
        PERV_XB_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_6D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X1_FIR_ERR,
        XBUS_1_LL1_IOEL_CONTROL
    },
    {
        XBUS,
        2,
        PERV_XB_CPLT_CONF1_OR,
        PERV_XB_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_8D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X2_FIR_ERR,
        XBUS_2_LL2_IOEL_CONTROL
    },
    {
        XBUS,
        3,
        PERV_OB0_CPLT_CONF1_OR,
        PERV_OB0_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X3_FIR_ERR,
        OBUS_0_LL0_IOOL_CONTROL
    },
    {
        XBUS,
        4,
        PERV_OB1_CPLT_CONF1_OR,
        PERV_OB1_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X4_FIR_ERR,
        OBUS_1_LL3_IOOL_CONTROL
    },
    {
        XBUS,
        5,
        PERV_OB2_CPLT_CONF1_OR,
        PERV_OB2_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X5_FIR_ERR,
        OBUS_2_LL3_IOOL_CONTROL
    },
    {
        XBUS,
        6,
        PERV_OB3_CPLT_CONF1_OR,
        PERV_OB3_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X6_FIR_ERR,
        OBUS_3_LL3_IOOL_CONTROL
    },
    {
        ABUS,
        0,
        PERV_OB0_CPLT_CONF1_OR,
        PERV_OB0_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X3_FIR_ERR,
        OBUS_0_LL0_IOOL_CONTROL
    },
    {
        ABUS,
        1,
        PERV_OB1_CPLT_CONF1_OR,
        PERV_OB1_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X4_FIR_ERR,
        OBUS_1_LL3_IOOL_CONTROL
    },
    {
        ABUS,
        2,
        PERV_OB2_CPLT_CONF1_OR,
        PERV_OB2_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X5_FIR_ERR,
        OBUS_2_LL3_IOOL_CONTROL
    },
    {
        ABUS,
        3,
        PERV_OB3_CPLT_CONF1_OR,
        PERV_OB3_CPLT_CONF1_CLEAR,
        PERV_1_CPLT_CONF1_IOVALID_4D,
        PU_PB_CENT_SM1_EXTFIR_MASK_REG_PB_X6_FIR_ERR,
        OBUS_3_LL3_IOOL_CONTROL
    }
};

// address range definitions
const uint64_t P9_FBC_UTILS_FBC_MAX_ADDRESS = ((1ULL << 56) - 1ULL);
const uint64_t P9_FBC_UTILS_CACHELINE_MASK = 0x7FULL;
const uint64_t P9_FBC_UTILS_LAST_ADDR_IN_CACHELINE = 0x78ULL;

// cacheline size = 128B
const uint64_t FABRIC_CACHELINE_SIZE = 0x80;


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C" {

///
/// @brief Read FBC/ADU registers to determine state of fabric init and stop
/// control signals
///
/// @param[in] i_target Reference to processor chip target
/// @param[out] o_is_initialized State of fabric init signal
/// @param[out] o_is_running State of fabric pervasive stop control
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fbc_utils_get_fbc_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        bool& o_is_initialized,
        bool& o_is_running);

///
/// @brief Use ADU pMisc Mode register to clear fabric stop signal, overriding
/// a stop condition caused by a checkstop
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fbc_utils_override_fbc_stop(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Return base address origin (non-mirrored/mirrored) for this chip
///
/// @param[in] i_target Reference to processor chip target
/// @param[out] o_base_address_nm Non-mirrored base address for this chip
/// @param[out] o_base_address_m Mirrored base address for this chip
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fbc_utils_get_chip_base_address(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        uint64_t& o_base_address_nm,
        uint64_t& o_base_address_m);

} // extern "C"

#endif // _P9_FBC_UTILS_H_
