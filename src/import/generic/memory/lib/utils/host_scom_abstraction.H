/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/host_scom_abstraction.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
/// @file host_scom_abstraction.H
/// @brief Abstracs out how scoms are done as they are different between different hosts
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Amita Banchhor <amita.banchhor@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef _HOST_SCOM_ABSTRACTION_H_
#define _HOST_SCOM_ABSTRACTION_H_

#include <generic/memory/lib/utils/find.H>

#include <fapi2.H>
#ifdef __PPE__
    #include <ody_fifo.H>
#endif

///
/// @brief putScom abstraction for host in PPE vs non-PPE hosts with an OCMB_CHIP target
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the register address
/// @param[in] i_data the data to scom into the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Scoms differ between the platforms
///       PPE hosts use ody_put_scom, while non-PPE hosts use fapi2::putScom
///
inline fapi2::ReturnCode putScomHost(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const uint64_t i_addr,
                                     const fapi2::buffer<uint64_t>& i_data)
{
#ifndef __PPE__
    return fapi2::putScom(i_target, i_addr, i_data);
#else
    return ody_put_scom(i_target, i_addr, i_data);
#endif
}

///
/// @brief getScom abstraction for host in PPE vs non-PPE hosts with an OCMB_CHIP target
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the register address
/// @param[out] o_data the data to scom from the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Scoms differ between the platforms
///       PPE hosts use ody_get_scom, while non-PPE hosts use fapi2::getScom
///
inline fapi2::ReturnCode getScomHost(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const uint64_t i_addr,
                                     fapi2::buffer<uint64_t>& o_data)
{
#ifndef __PPE__
    return fapi2::getScom(i_target, i_addr, o_data);
#else
    return ody_get_scom(i_target, i_addr, o_data);
#endif
}

///
/// @brief putScom abstraction for host in PPE vs non-PPE hosts with a MEM_PORT target
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the register address
/// @param[in] i_data the data to scom into the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Scoms differ between the platforms
///       PPE hosts use ody_put_scom, while non-PPE hosts use fapi2::putScom
///
inline fapi2::ReturnCode putScomHost(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                     const uint64_t i_addr,
                                     const fapi2::buffer<uint64_t>& i_data)
{
#ifndef __PPE__
    return fapi2::putScom(i_target, i_addr, i_data);
#else
    uint8_t l_rel_pos = 0;
    const auto& l_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_rel_pos));

    {
        const uint64_t OFFSET = (l_rel_pos == 0) ? 0 : 0x0000000000000400;
        FAPI_TRY(ody_put_scom(l_target, i_addr | OFFSET, i_data));
    }

fapi_try_exit:
    return fapi2::current_err;
#endif
}

///
/// @brief getScom abstraction for host in PPE vs non-PPE hosts with a MEM_PORT target
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the register address
/// @param[out] o_data the data to scom from the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Scoms differ between the platforms
///       PPE hosts use ody_get_scom, while non-PPE hosts use fapi2::getScom
///
inline fapi2::ReturnCode getScomHost(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                     const uint64_t i_addr,
                                     fapi2::buffer<uint64_t>& o_data)
{
#ifndef __PPE__
    return fapi2::getScom(i_target, i_addr, o_data);
#else
    uint8_t l_rel_pos = 0;
    const auto& l_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_rel_pos));

    {
        const uint64_t OFFSET = (l_rel_pos == 0) ? 0 : 0x0000000000000400;
        FAPI_TRY(ody_get_scom(l_target, i_addr | OFFSET, o_data));
    }

fapi_try_exit:
    return fapi2::current_err;
#endif
}

#endif
