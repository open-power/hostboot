/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_getecid.C $                   */
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
//------------------------------------------------------------------------------
/// @file  p9_getecid.C
///
/// @brief Get ECID string from target using SCOM
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_getecid.H"
//## auto_generated
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_const_common.H>

enum P9_SBE_COMMON_Private_Constants
{
    OTPC_M_MODE_REGISTER_ECC_ENABLE_BIT = 1 // OTPROM mode register MODE_ECC_ENABLE field/bit definitions
};

fapi2::ReturnCode p9_getecid(const
                             fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip, fapi2::variable_buffer& o_fuseString)
{
    uint64_t attr_data[2];
    bool secure_mode = false;
    fapi2::buffer<uint64_t> l_ecid_part0_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part1_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part1_data48 = 0;
    fapi2::buffer<uint64_t> l_local = 0;
    FAPI_INF("Entering ...");

    FAPI_DBG("determine if security is enabled");
    fapi2::buffer<uint64_t> l_data64;
    FAPI_TRY(fapi2::getScom(i_target_chip, PERV_CBS_CS_SCOM, l_data64));
    secure_mode = l_data64.getBit<4>();

    FAPI_DBG("clear ECC enable before reading ECID data (read-modify-write OTPROM Mode register), insecure mode only");

    if (!secure_mode)
    {
        fapi2::buffer<uint64_t> l_data64;
        FAPI_TRY(fapi2::getScom(i_target_chip, PU_MODE_REGISTER, l_data64));
        l_data64.clearBit<OTPC_M_MODE_REGISTER_ECC_ENABLE_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_MODE_REGISTER, l_data64));
    }

    FAPI_DBG("extract and manipulate ECID data");
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART0_REGISTER, l_ecid_part0_data64));
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART1_REGISTER, l_ecid_part1_data64));
    l_ecid_part0_data64.reverse();
    l_ecid_part1_data64.reverse();

    l_local.insertFromRight<0, 64>(l_ecid_part0_data64);
    attr_data[0] = l_local;
    l_local.insertFromRight<0, 64>(l_ecid_part1_data64);
    attr_data[1] = l_local;
    o_fuseString.insert(l_ecid_part0_data64, 0, 64, 0);
    l_ecid_part1_data64.extractToRight<0, 48>(l_ecid_part1_data48);
    o_fuseString.insert(l_ecid_part1_data48, 64, 48, 0);

    FAPI_DBG("push fuse string into attribute");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target_chip, attr_data));

    FAPI_DBG("restore ECC enable setting (insecure mode only)");

    if (!secure_mode)
    {
        fapi2::buffer<uint64_t> l_data64;
        FAPI_TRY(fapi2::getScom(i_target_chip, PU_MODE_REGISTER, l_data64));
        l_data64.setBit<OTPC_M_MODE_REGISTER_ECC_ENABLE_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_MODE_REGISTER, l_data64));
    }

    FAPI_INF("Exiting ...");

//    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;

}
