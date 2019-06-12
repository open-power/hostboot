/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file pmic_common_utils.C
/// @brief Utility functions common for several PMIC procedures
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
namespace pmic
{

///
/// @brief polls PMIC for PBULK PWR_GOOD status
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode success if good, error if polling fail or power not good
///
fapi2::ReturnCode poll_for_pbulk_good(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;

    // Using default poll parameters
    mss::poll_parameters l_poll_params;

    FAPI_ASSERT( mss::poll(i_pmic_target, l_poll_params, [&i_pmic_target]()->bool
    {
        fapi2::buffer<uint8_t> l_pbulk_status_buffer;

        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R08, l_pbulk_status_buffer),
        "pmic_enable: Could not read 0x%02hhX on %s ", REGS::R08, mss::c_str(i_pmic_target));

        return l_pbulk_status_buffer.getBit<FIELDS::VIN_BULK_INPUT_PWR_GOOD_STATUS>() ==
        mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>::PWR_GOOD;

    fapi_try_exit:
        // No ack, return false and continue polling
        return false;
    }),
    fapi2::MSS_EXP_I2C_POLLING_TIMEOUT().
    set_TARGET(i_pmic_target),
    "I2C read from %s either did not ACK or VIN_BULK did not respond with PWR_GOOD status",
    mss::c_str(i_pmic_target) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unlocks PMIC vendor region
///
/// @param[in] i_pmic_target JEDEC-COMPLIANT PMIC to unlock
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode unlock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Unlock
    const fapi2::buffer<uint8_t> l_password_low(CONSTS::VENDOR_PASSWORD_LOW);
    const fapi2::buffer<uint8_t> l_password_high(CONSTS::VENDOR_PASSWORD_HIGH);
    const fapi2::buffer<uint8_t> l_unlock_code(CONSTS::UNLOCK_VENDOR_REGION);

    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R37_PASSWORD_LOWER_BYTE_0, l_password_low));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R38_PASSWORD_UPPER_BYTE_1, l_password_high));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R39_COMMAND_CODES, l_unlock_code));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Locks PMIC vendor region
///
/// @param[in] i_pmic_target - JEDEC-COMPLIANT PMIC to lock
/// @param[in] i_rc - return code from the end of the caller function (if applicable)
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff i_rc == SUCCESS && no errors in unlocking, else return current_err
///
fapi2::ReturnCode lock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                                     const fapi2::ReturnCode i_rc)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Lock vendor region, password registers are cleared automatically
    const fapi2::buffer<uint8_t> l_lock_code(CONSTS::LOCK_VENDOR_REGION);
    const fapi2::buffer<uint8_t> l_zero_code(0);

    fapi2::ReturnCode l_lock_return_code = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R39_COMMAND_CODES, l_lock_code));

    return i_rc;

fapi_try_exit:
    // Since we could have 2 possible errors at the same time here, we are letting the caller's i_rc take precedence.
    // So, if we find an error while locking, we will report it here. We will only "return" this error if the
    // caller's error is success, as to not overwrite it.
    FAPI_ERR("Error code 0x%0llx: Error while trying to lock vendor region", uint64_t(fapi2::current_err));
    return ((i_rc == fapi2::FAPI2_RC_SUCCESS) ? fapi2::current_err : i_rc);
}

} // pmic
} // mss
