/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/scomt/proc_scomt.H $            */
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

#ifndef __PROC_SCOMTOOL_
#define __PROC_SCOMTOOL_

#include "fapi2.H"
#include "assert.h"

#ifdef NO_SCOM_CHECKING
    #undef SCOM_CHECKING
#endif

#ifndef NO_SCOM_CHECKING_PLAT_ASSERT
    #ifdef SCOM_CHECKING
        #define SCOM_CHECKING_PLAT_ASSERT
    #endif
#endif

namespace scomt
{

#ifdef SCOM_CHECKING
    #ifndef PLAT_NO_THREAD_LOCAL_STORAGE
        extern thread_local uint64_t       last_scom;
        extern thread_local uint8_t        chip;
        extern thread_local uint8_t        ec;
        extern thread_local bool           no_regchk;
        extern thread_local uint64_t       spare0;
        extern thread_local uint64_t       spare1;
    #else
        extern uint64_t       last_scom;
        extern uint8_t        chip;
        extern uint8_t        ec;
        extern bool           no_regchk;
        extern uint64_t       spare0;
        extern uint64_t       spare1;
    #endif
#endif //SCOM_CHECKING

/// @brief Disable register checking
///
static inline void disableRegchk()
{
#ifdef SCOM_CHECKING
    scomt::no_regchk = true;
#endif
}

/// @brief Enable register checking
///
static inline void enableRegchk()
{
#ifdef SCOM_CHECKING
    scomt::no_regchk = false;
#endif
}

/// @brief Initialize the global scomt variables chip/ec from target attributes
///
/// @param[in]    i_target   The chip unit target to use to get chip/ec attributes
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode init(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_target, chip));
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_target, ec));
fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Initialize the global scomt variables chip/ec from target attributes
///
/// @param[in]    i_target   The chip unit target to use to get chip/ec attributes
/// @return FAPI2_RC_SUCCESS if success, else error code.
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode init(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING

    if (K & fapi2::TARGET_TYPE_CHIPLETS)
    {
        fapi2::Target<fapi2::TARGET_TYPE_CHIPLETS> l_chiplet = (fapi2::Target<fapi2::TARGET_TYPE_CHIPLETS>)i_target;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chip = l_chiplet.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, l_chip, chip));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, l_chip, ec));
    }
    else
    {
        assert(false);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!(i_reg == scomt::last_scom))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx\n",
                     scomt::last_scom,
                     i_reg);
            assert(false);
        }

#endif
        FAPI_ASSERT(i_reg == scomt::last_scom,
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx",
                    scomt::last_scom,
                    i_reg);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg0   One of the valid registers for this operation
/// @param[in]    i_reg1   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg0, const uint64_t& i_reg1)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!((i_reg0 == scomt::last_scom ||
               i_reg1 == scomt::last_scom)))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx or 0x%lx\n",
                     scomt::last_scom,
                     i_reg0,
                     i_reg1);
            assert(false);
        }

#endif
        FAPI_ASSERT((i_reg0 == scomt::last_scom ||
                     i_reg1 == scomt::last_scom),
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg0)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx or 0x%lx",
                    scomt::last_scom,
                    i_reg0,
                    i_reg1);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg0   One of the valid registers for this operation
/// @param[in]    i_reg1   One of the valid registers for this operation
/// @param[in]    i_reg2   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg0,
                                       const uint64_t& i_reg1,
                                       const uint64_t& i_reg2)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!((i_reg0 == scomt::last_scom ||
               i_reg1 == scomt::last_scom ||
               i_reg2 == scomt::last_scom)))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx or 0x%lx\n",
                     scomt::last_scom,
                     i_reg0,
                     i_reg1,
                     i_reg2);
            assert(false);
        }

#endif
        FAPI_ASSERT((i_reg0 == scomt::last_scom ||
                     i_reg1 == scomt::last_scom ||
                     i_reg2 == scomt::last_scom),
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg0)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx or 0x%lx",
                    scomt::last_scom,
                    i_reg0,
                    i_reg1,
                    i_reg2);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg0   One of the valid registers for this operation
/// @param[in]    i_reg1   One of the valid registers for this operation
/// @param[in]    i_reg2   One of the valid registers for this operation
/// @param[in]    i_reg3   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg0,
                                       const uint64_t& i_reg1,
                                       const uint64_t& i_reg2,
                                       const uint64_t& i_reg3)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!((i_reg0 == scomt::last_scom ||
               i_reg1 == scomt::last_scom ||
               i_reg2 == scomt::last_scom ||
               i_reg3 == scomt::last_scom)))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%llx, expecting: 0x%llx, 0x%llx, 0x%llx or 0x%llx\n",
                     scomt::last_scom,
                     i_reg0,
                     i_reg1,
                     i_reg2,
                     i_reg3);
            assert(false);
        }

#endif
        FAPI_ASSERT((i_reg0 == scomt::last_scom ||
                     i_reg1 == scomt::last_scom ||
                     i_reg2 == scomt::last_scom ||
                     i_reg3 == scomt::last_scom),
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg0)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx or 0x%lx",
                    scomt::last_scom,
                    i_reg0,
                    i_reg1,
                    i_reg2,
                    i_reg3);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg0   One of the valid registers for this operation
/// @param[in]    i_reg1   One of the valid registers for this operation
/// @param[in]    i_reg2   One of the valid registers for this operation
/// @param[in]    i_reg3   One of the valid registers for this operation
/// @param[in]    i_reg4   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg0,
                                       const uint64_t& i_reg1,
                                       const uint64_t& i_reg2,
                                       const uint64_t& i_reg3,
                                       const uint64_t& i_reg4)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!((i_reg0 == scomt::last_scom ||
               i_reg1 == scomt::last_scom ||
               i_reg2 == scomt::last_scom ||
               i_reg3 == scomt::last_scom ||
               i_reg4 == scomt::last_scom)))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx, 0x%lx or 0x%lx\n",
                     scomt::last_scom,
                     i_reg0,
                     i_reg1,
                     i_reg2,
                     i_reg3,
                     i_reg4);
            assert(false);
        }

#endif
        FAPI_ASSERT((i_reg0 == scomt::last_scom ||
                     i_reg1 == scomt::last_scom ||
                     i_reg2 == scomt::last_scom ||
                     i_reg3 == scomt::last_scom ||
                     i_reg4 == scomt::last_scom),
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg0)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx, 0x%lx or 0x%lx",
                    scomt::last_scom,
                    i_reg0,
                    i_reg1,
                    i_reg2,
                    i_reg3,
                    i_reg4);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg0   One of the valid registers for this operation
/// @param[in]    i_reg1   One of the valid registers for this operation
/// @param[in]    i_reg2   One of the valid registers for this operation
/// @param[in]    i_reg3   One of the valid registers for this operation
/// @param[in]    i_reg4   One of the valid registers for this operation
/// @param[in]    i_reg5   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg0,
                                       const uint64_t& i_reg1,
                                       const uint64_t& i_reg2,
                                       const uint64_t& i_reg3,
                                       const uint64_t& i_reg4,
                                       const uint64_t& i_reg5)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!((i_reg0 == scomt::last_scom ||
               i_reg1 == scomt::last_scom ||
               i_reg2 == scomt::last_scom ||
               i_reg3 == scomt::last_scom ||
               i_reg4 == scomt::last_scom ||
               i_reg5 == scomt::last_scom)))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx or 0x%lx\n",
                     scomt::last_scom,
                     i_reg0,
                     i_reg1,
                     i_reg2,
                     i_reg3,
                     i_reg4,
                     i_reg5);
            assert(false);
        }

#endif
        FAPI_ASSERT((i_reg0 == scomt::last_scom ||
                     i_reg1 == scomt::last_scom ||
                     i_reg2 == scomt::last_scom ||
                     i_reg3 == scomt::last_scom ||
                     i_reg4 == scomt::last_scom ||
                     i_reg5 == scomt::last_scom),
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg0)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx or 0x%lx",
                    scomt::last_scom,
                    i_reg0,
                    i_reg1,
                    i_reg2,
                    i_reg3,
                    i_reg4,
                    i_reg5);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Check the correct register is prepared for the following operation.
///
/// @param[in]    i_reg0   One of the valid registers for this operation
/// @param[in]    i_reg1   One of the valid registers for this operation
/// @param[in]    i_reg2   One of the valid registers for this operation
/// @param[in]    i_reg3   One of the valid registers for this operation
/// @param[in]    i_reg4   One of the valid registers for this operation
/// @param[in]    i_reg5   One of the valid registers for this operation
/// @param[in]    i_reg6   One of the valid registers for this operation
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode chkReg(const uint64_t& i_reg0,
                                       const uint64_t& i_reg1,
                                       const uint64_t& i_reg2,
                                       const uint64_t& i_reg3,
                                       const uint64_t& i_reg4,
                                       const uint64_t& i_reg5,
                                       const uint64_t& i_reg6)
{
#ifdef SCOM_CHECKING

    if (!scomt::no_regchk)
    {
#ifdef SCOM_CHECKING_PLAT_ASSERT

        if (!((i_reg0 == scomt::last_scom ||
               i_reg1 == scomt::last_scom ||
               i_reg2 == scomt::last_scom ||
               i_reg3 == scomt::last_scom ||
               i_reg4 == scomt::last_scom ||
               i_reg5 == scomt::last_scom ||
               i_reg6 == scomt::last_scom)))
        {
            FAPI_ERR("This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx or 0x%lx\n",
                     scomt::last_scom,
                     i_reg0,
                     i_reg1,
                     i_reg2,
                     i_reg3,
                     i_reg4,
                     i_reg5,
                     i_reg6);
            assert(false);
        }

#endif
        FAPI_ASSERT((i_reg0 == scomt::last_scom ||
                     i_reg1 == scomt::last_scom ||
                     i_reg2 == scomt::last_scom ||
                     i_reg3 == scomt::last_scom ||
                     i_reg4 == scomt::last_scom ||
                     i_reg5 == scomt::last_scom ||
                     i_reg6 == scomt::last_scom),
                    fapi2::INVALID_SCOM_FOR_CHIP_EC()
                    .set_ADDRESS(i_reg0)
                    .set_SCOMT_CHIP(scomt::chip)
                    .set_SCOMT_EC(scomt::ec)
                    .set_SCOMT_ADDRESS(scomt::last_scom),
                    "This operation is not supported for scomt::last_scom: 0x%lx, expecting: 0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx or 0x%lx",
                    scomt::last_scom,
                    i_reg0,
                    i_reg1,
                    i_reg2,
                    i_reg3,
                    i_reg4,
                    i_reg5,
                    i_reg6);
    }

fapi_try_exit:
#endif
    return fapi2::current_err;
}

/// @brief Fail if the current scomt::chip/ec is equal to specified arguments.
///
/// @param[in]    i_chip   scomt::chip is this chip
/// @param[in]    i_ec     and scomt::ec is this ec.
/// @return FAPI2_RC_SUCCESS if success, else error code.
static inline fapi2::ReturnCode failOn(const uint8_t& i_chip, const uint8_t& i_ec)
{
#ifdef SCOM_CHECKING
#ifdef SCOM_CHECKING_PLAT_ASSERT

    if ((scomt::chip == i_chip) && (scomt::ec == i_ec))
    {
        FAPI_ERR("This scom operation (0x%lx) is not supported for chip: 0x%x ec: 0x%x\n",
                 scomt::last_scom,
                 static_cast<uint32_t>(i_chip),
                 static_cast<uint32_t>(i_ec));

        assert(false);
    }

#endif
    FAPI_ASSERT(!((scomt::chip == i_chip) && (scomt::ec == i_ec)),
                fapi2::INVALID_SCOM_FOR_CHIP_EC()
                .set_SCOMT_CHIP(scomt::chip)
                .set_SCOMT_EC(scomt::ec)
                .set_SCOMT_ADDRESS(scomt::last_scom),
                "This scom operation (0x%lx) is not supported for chip: 0x%x ec: 0x%x",
                scomt::last_scom,
                static_cast<uint32_t>(i_chip),
                static_cast<uint32_t>(i_ec));
fapi_try_exit:
#endif
    return fapi2::current_err;
}


}

#endif
