/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pll_accessors/getPllRingInfoAttr.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getPllRingInfoAttr.C,v 1.3 2014/04/23 17:23:40 thi Exp $
/**
 *  @file getPllRingInfoAttr.C
 *
 *  @brief Accessor HWP that gets attributes containing information about PLL
 *         Rings
 *
 */

#include <stdint.h>
#include <fapi.H>
#include <getPllRingInfoAttr.H>

extern "C"
{

/**
 * @brief Checks the user's buffer size
 *
 * @param[in] i_attr         Attribute ID (just used for tracing)
 * @param[in] i_actualSize   Actual buffer size
 * @param[in] i_expectedSize Expected buffer size
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode pllInfoCheckSize(const fapi::getPllRingInfo::Attr i_attr,
                                  const size_t i_actualSize,
                                  const size_t i_expectedSize)
{
    fapi::ReturnCode l_rc;

    if (i_actualSize != i_expectedSize)
    {
        FAPI_ERR("getPllRingInfoAttr: Incorrect Attribute output buffer size %d:%d:%d",
                 i_attr, i_actualSize, i_expectedSize);
        const fapi::getPllRingInfo::Attr & ATTR_ID = i_attr;
        const size_t & ACTUAL_SIZE = i_actualSize;
        const size_t & EXPECTED_SIZE = i_expectedSize;
        FAPI_SET_HWP_ERROR(l_rc, RC_GET_PLL_RING_INFO_ATTR_INVALID_OUTPUT_SIZE);
    }

    return l_rc;
}

/**
 * @brief Returns a chip's name and EC level
 *
 * @param[in]  i_attr Attribute ID (just used for tracing)
 * @param[in]  i_chip Reference to Chip fapi target
 * @param[out] o_name Filled in with the chip name
 * @param[out] o_ec   Filled in with the chip EC level
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode pllInfoGetChipNameEc(
    const fapi::getPllRingInfo::Attr i_attr,
    const fapi::Target & i_chip,
    fapi::ATTR_NAME_Type & o_name,
    fapi::ATTR_EC_Type & o_ec)
{
    fapi::ReturnCode l_rc;

    // As an Attribute Accessor HWP that needs the chip's name/EC to figure out
    // the data to return, it is valid to access these privileged attributes
    l_rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, &i_chip, o_name);

    if (l_rc)
    {
        FAPI_ERR("getPllRingInfoAttr: error getting ATTR_NAME for attr %d",
                 i_attr);
    }
    else
    {
        l_rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_chip, o_ec);

        if (l_rc)
        {
            FAPI_ERR("getPllRingInfoAttr: error getting ATTR_EC for attr %d",
                     i_attr);
        }
    }

    return l_rc;
}

/**
 * @brief Returns PROC_DMI_CUPLL_PFD360_OFFSET data
 *
 * This is the offset within a PLL ring of some specific data
 *
 * @param[in]  i_procChip Reference to Processor Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_PROC_DMI_CUPLL_PFD360_OFFSET(
    const fapi::Target & i_procChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_PROC_DMI_CUPLL_PFD360_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_PROC_DMI_CUPLL_PFD360_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::PROC_DMI_CUPLL_PFD360_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        fapi::ATTR_NAME_Type l_name = 0;
        fapi::ATTR_EC_Type l_ec = 0;

        l_rc = pllInfoGetChipNameEc(
            fapi::getPllRingInfo::PROC_DMI_CUPLL_PFD360_OFFSET, i_procChip,
            l_name, l_ec);

        if (!l_rc)
        {
            // Data supplied by HW team
            if ((l_name == fapi::ENUM_ATTR_NAME_MURANO) && 
                ((l_ec == 0x10) || (l_ec == 0x12) || (l_ec == 0x13) ||
                 (l_ec == 0x20) || (l_ec == 0x21)))
            {
                o_val[0] = 0;
                o_val[1] = 0;
                o_val[2] = 0;
                o_val[3] = 0;
                o_val[4] = 360;
                o_val[5] = 407;
                o_val[6] = 501;
                o_val[7] = 454;
            }
            else if ((l_name == fapi::ENUM_ATTR_NAME_VENICE) &&
                     ((l_ec == 0x10) || ((l_ec >= 0x20) && (l_ec < 0x30))))
            {
                o_val[0] = 430;
                o_val[1] = 477;
                o_val[2] = 571;
                o_val[3] = 524;
                o_val[4] = 1359;
                o_val[5] = 1406;
                o_val[6] = 1500;
                o_val[7] = 1453;
            }
            else
            {
                FAPI_ERR("get_PROC_DMI_CUPLL_PFD360_OFFSET: No data for Chip Name:EC %d:0x%x",
                         l_name, l_ec);
                const fapi::Target & PROC_CHIP = i_procChip;
                const fapi::ATTR_NAME_Type & CHIP_NAME = l_name;
                const fapi::ATTR_EC_Type & CHIP_EC = l_ec;
                FAPI_SET_HWP_ERROR(l_rc,
                    RC_GET_PROC_DMI_CUPLL_PFD360_OFFSET_BAD_CHIP_NAME_EC);
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns PROC_DMI_CUPLL_REFCLKSEL_OFFSET data
 *
 * This is the offset within a PLL ring of some specific data
 *
 * @param[in]  i_procChip Reference to Processor Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_PROC_DMI_CUPLL_REFCLKSEL_OFFSET(
    const fapi::Target & i_procChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::PROC_DMI_CUPLL_REFCLKSEL_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        fapi::ATTR_NAME_Type l_name = 0;
        fapi::ATTR_EC_Type l_ec = 0;

        l_rc = pllInfoGetChipNameEc(
            fapi::getPllRingInfo::PROC_DMI_CUPLL_REFCLKSEL_OFFSET, i_procChip,
            l_name, l_ec);

        if (!l_rc)
        {
            // Data supplied by HW team
            if ((l_name == fapi::ENUM_ATTR_NAME_MURANO) && 
                ((l_ec == 0x10) || (l_ec == 0x12) || (l_ec == 0x13) ||
                 (l_ec == 0x20) || (l_ec == 0x21)))
            {
                o_val[0] = 0;
                o_val[1] = 0;
                o_val[2] = 0;
                o_val[3] = 0;
                o_val[4] = 318;
                o_val[5] = 365;
                o_val[6] = 459;
                o_val[7] = 412;
            }
            else if ((l_name == fapi::ENUM_ATTR_NAME_VENICE) &&
                     ((l_ec == 0x10) || ((l_ec >= 0x20) && (l_ec < 0x30))))
            {
                o_val[0] = 388;
                o_val[1] = 435;
                o_val[2] = 529;
                o_val[3] = 482;
                o_val[4] = 1317;
                o_val[5] = 1364;
                o_val[6] = 1458;
                o_val[7] = 1411;
            }
            else
            {
                FAPI_ERR("get_PROC_DMI_CUPLL_REFCLKSEL_OFFSET: No data for Chip Name:EC %d:0x%x",
                         l_name, l_ec);
                const fapi::Target & PROC_CHIP = i_procChip;
                const fapi::ATTR_NAME_Type & CHIP_NAME = l_name;
                const fapi::ATTR_EC_Type & CHIP_EC = l_ec;
                FAPI_SET_HWP_ERROR(l_rc,
                    RC_GET_PROC_DMI_CUPLL_REFCLKSEL_OFFSET_BAD_CHIP_NAME_EC);
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns PROC_ABUS_CUPLL_PFD360_OFFSET data
 *
 * This is the offset within a PLL ring of some specific data
 *
 * @param[in]  i_procChip Reference to Processor Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_PROC_ABUS_CUPLL_PFD360_OFFSET(
    const fapi::Target & i_procChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::PROC_ABUS_CUPLL_PFD360_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        fapi::ATTR_NAME_Type l_name = 0;
        fapi::ATTR_EC_Type l_ec = 0;

        l_rc = pllInfoGetChipNameEc(
            fapi::getPllRingInfo::PROC_ABUS_CUPLL_PFD360_OFFSET, i_procChip,
            l_name, l_ec);

        if (!l_rc)
        {
            // Data supplied by HW team
            if ( ((l_name == fapi::ENUM_ATTR_NAME_MURANO) && 
                  ((l_ec == 0x10) || (l_ec == 0x12) || (l_ec == 0x13) ||
                   (l_ec == 0x20) || (l_ec == 0x21))) ||
                 ((l_name == fapi::ENUM_ATTR_NAME_VENICE) && 
                   ((l_ec == 0x10) || ((l_ec >= 0x20) && (l_ec < 0x30)))) )
            {
                o_val[0] = 198;
                o_val[1] = 151;
                o_val[2] = 104;
            }
            else
            {
                FAPI_ERR("get_PROC_ABUS_CUPLL_PFD360_OFFSET: No data for Chip Name:EC %d:0x%x",
                         l_name, l_ec);
                const fapi::Target & PROC_CHIP = i_procChip;
                const fapi::ATTR_NAME_Type & CHIP_NAME = l_name;
                const fapi::ATTR_EC_Type & CHIP_EC = l_ec;
                FAPI_SET_HWP_ERROR(l_rc,
                    RC_GET_PROC_ABUS_CUPLL_PFD360_OFFSET_BAD_CHIP_NAME_EC);
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns PROC_ABUS_CUPLL_REFCLKSEL_OFFSET data
 *
 * This is the offset within a PLL ring of some specific data
 *
 * @param[in]  i_procChip Reference to Processor Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET(
    const fapi::Target & i_procChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::PROC_ABUS_CUPLL_REFCLKSEL_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        fapi::ATTR_NAME_Type l_name = 0;
        fapi::ATTR_EC_Type l_ec = 0;

        l_rc = pllInfoGetChipNameEc(
            fapi::getPllRingInfo::PROC_ABUS_CUPLL_REFCLKSEL_OFFSET, i_procChip,
            l_name, l_ec);

        if (!l_rc)
        {
            // Data supplied by HW team
            if ( ((l_name == fapi::ENUM_ATTR_NAME_MURANO) && 
                  ((l_ec == 0x10) || (l_ec == 0x12) || (l_ec == 0x13) ||
                   (l_ec == 0x20) || (l_ec == 0x21))) ||
                 ((l_name == fapi::ENUM_ATTR_NAME_VENICE) && 
                   ((l_ec == 0x10) || ((l_ec >= 0x20) && (l_ec < 0x30)))) )
            {
                o_val[0] = 156;
                o_val[1] = 109;
                o_val[2] = 62;
            }
            else
            {
                FAPI_ERR("get_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET: No data for Chip Name:EC %d:0x%x",
                         l_name, l_ec);
                const fapi::Target & PROC_CHIP = i_procChip;
                const fapi::ATTR_NAME_Type & CHIP_NAME = l_name;
                const fapi::ATTR_EC_Type & CHIP_EC = l_ec;
                FAPI_SET_HWP_ERROR(l_rc,
                    RC_GET_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET_BAD_CHIP_NAME_EC);
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns MEMB_DMI_CUPLL_PFD360_OFFSET data
 *
 * This is the offset within a PLL ring of some specific data
 *
 * @param[in]  i_membChip Reference to Membuf Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_MEMB_DMI_CUPLL_PFD360_OFFSET(
    const fapi::Target & i_membChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::MEMB_DMI_CUPLL_PFD360_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        fapi::ATTR_NAME_Type l_name = 0;
        fapi::ATTR_EC_Type l_ec = 0;

        l_rc = pllInfoGetChipNameEc(
            fapi::getPllRingInfo::MEMB_DMI_CUPLL_PFD360_OFFSET, i_membChip,
            l_name, l_ec);

        if (!l_rc)
        {
            // Data supplied by HW team
            if ((l_name == fapi::ENUM_ATTR_NAME_CENTAUR) && 
                ((l_ec == 0x10) || (l_ec == 0x20) || (l_ec == 0x21)))
            {
                o_val = 134;
            }
            else
            {
                FAPI_ERR("get_MEMB_DMI_CUPLL_PFD360_OFFSET: No data for Chip Name:EC %d:0x%x",
                         l_name, l_ec);
                const fapi::Target & MEMBUF_CHIP = i_membChip;
                const fapi::ATTR_NAME_Type & CHIP_NAME = l_name;
                const fapi::ATTR_EC_Type & CHIP_EC = l_ec;
                FAPI_SET_HWP_ERROR(l_rc,
                    RC_GET_MEMB_DMI_CUPLL_PFD360_OFFSET_BAD_CHIP_NAME_EC);
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns MEMB_DMI_CUPLL_REFCLKSEL_OFFSET data
 *
 * This is the offset within a PLL ring of some specific data
 *
 * @param[in]  i_membChip Reference to Membuf Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET(
    const fapi::Target & i_membChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::MEMB_DMI_CUPLL_REFCLKSEL_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        fapi::ATTR_NAME_Type l_name = 0;
        fapi::ATTR_EC_Type l_ec = 0;

        l_rc = pllInfoGetChipNameEc(
            fapi::getPllRingInfo::MEMB_DMI_CUPLL_REFCLKSEL_OFFSET, i_membChip,
            l_name, l_ec);

        if (!l_rc)
        {
            // Data supplied by HW team
            if ((l_name == fapi::ENUM_ATTR_NAME_CENTAUR) && 
                ((l_ec == 0x10) || (l_ec == 0x20) || (l_ec == 0x21)))
            {
                o_val = 92;
            }
            else
            {
                FAPI_ERR("get_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET: No data for Chip Name:EC %d:0x%x",
                         l_name, l_ec);
                const fapi::Target & MEMBUF_CHIP = i_membChip;
                const fapi::ATTR_NAME_Type & CHIP_NAME = l_name;
                const fapi::ATTR_EC_Type & CHIP_EC = l_ec;
                FAPI_SET_HWP_ERROR(l_rc,
                    RC_GET_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET_BAD_CHIP_NAME_EC);
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns MEMB_MEM_PLL_CFG_UPDATE_OFFSET data
 *
 * This is the scan chain position of MEM PLL PLLCTRL1(44) bit in tp_pll_bndy
 *   chain (Offset from beginning of chain)
 *
 * @param[in]  i_membChip Reference to Membuf Chip fapi target
 * @param[out] o_pVal     Pointer to data buffer filled in with attribute data
 * @param[in]  i_len      Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_MEMB_MEM_PLL_CFG_UPDATE_OFFSET(
    const fapi::Target & i_membChip,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ATTR_MEMB_MEM_PLL_CFG_UPDATE_OFFSET_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_MEMB_MEM_PLL_CFG_UPDATE_OFFSET_Type *>(
            o_pVal));

    fapi::ReturnCode l_rc = pllInfoCheckSize(
        fapi::getPllRingInfo::MEMB_MEM_PLL_CFG_UPDATE_OFFSET, i_len,
        sizeof(o_val));

    if (!l_rc)
    {
        o_val = 322; // for all current Centaur ECs
    }
    return l_rc;
}

//-----------------------------------------------------------------------------
// getPllRingInfoAttr HWP - See header file for details
//-----------------------------------------------------------------------------
fapi::ReturnCode getPllRingInfoAttr(const fapi::Target & i_chip,
                                    const fapi::getPllRingInfo::Attr i_attr,
                                    void * o_pVal,
                                    const size_t i_len)
{
    fapi::ReturnCode l_rc;

    switch (i_attr)
    {
        case fapi::getPllRingInfo::PROC_DMI_CUPLL_PFD360_OFFSET:
            l_rc = get_PROC_DMI_CUPLL_PFD360_OFFSET(i_chip, o_pVal, i_len);
            break;
        case fapi::getPllRingInfo::PROC_DMI_CUPLL_REFCLKSEL_OFFSET:
            l_rc = get_PROC_DMI_CUPLL_REFCLKSEL_OFFSET(i_chip, o_pVal, i_len);
            break;
        case fapi::getPllRingInfo::PROC_ABUS_CUPLL_PFD360_OFFSET:
            l_rc = get_PROC_ABUS_CUPLL_PFD360_OFFSET(i_chip, o_pVal, i_len);
            break;
        case fapi::getPllRingInfo::PROC_ABUS_CUPLL_REFCLKSEL_OFFSET:
            l_rc = get_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET(i_chip, o_pVal, i_len);
            break;
        case fapi::getPllRingInfo::MEMB_DMI_CUPLL_PFD360_OFFSET:
            l_rc = get_MEMB_DMI_CUPLL_PFD360_OFFSET(i_chip, o_pVal, i_len);
            break;
        case fapi::getPllRingInfo::MEMB_DMI_CUPLL_REFCLKSEL_OFFSET:
            l_rc = get_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET(i_chip, o_pVal, i_len);
            break;
        case fapi::getPllRingInfo::MEMB_MEM_PLL_CFG_UPDATE_OFFSET:
            l_rc = get_MEMB_MEM_PLL_CFG_UPDATE_OFFSET(i_chip, o_pVal, i_len);
            break;
        default:
            FAPI_ERR("getPllRingInfoAttr: Invalid Attribute ID 0x%02x", i_attr);
            const fapi::getPllRingInfo::Attr & ATTR_ID = i_attr;
            FAPI_SET_HWP_ERROR(l_rc,
                               RC_GET_PLL_RING_INFO_ATTR_INVALID_ATTRIBUTE_ID);
    }

    return l_rc;
}

}
