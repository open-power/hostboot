/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/spd_accessors/getSpdAttrAccessor.C $         */
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
/**
 *  @file getSpdAttrAccessor.C
 *
 *  @brief Accessor HWP that gets DDR neutral DIMM SPD FAPI Attribute data
 *
 */

#include <stdint.h>
#include <fapi.H>
#include <getSpdAttrAccessor.H>

namespace fapi
{
    namespace getSpdAttr
    {
        enum DdrType
        {
            DDR3 = 1,
            DDR4 = 2,
        };
    }
}

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
fapi::ReturnCode checkSize(const fapi::getSpdAttr::Attr i_attr,
                           const size_t i_actualSize,
                           const size_t i_expectedSize)
{
    fapi::ReturnCode l_rc;

    if (i_actualSize != i_expectedSize)
    {
        FAPI_ERR("getSpdAttrAccessor: Incorrect Attribute output buffer size %d:%d:%d",
                 i_attr, i_actualSize, i_expectedSize);
        const fapi::getSpdAttr::Attr & ATTR_ID = i_attr;
        const size_t & ACTUAL_SIZE = i_actualSize;
        const size_t & EXPECTED_SIZE = i_expectedSize;
        FAPI_SET_HWP_ERROR(l_rc, RC_GET_SPD_ACCESSOR_INVALID_OUTPUT_SIZE);
    }

    return l_rc;
}

/**
 * @brief Returns the DIMM DDR Type
 *
 * This function only supports DDR3 and DDR4
 *
 * @param[in]  i_dimm Reference to DIMM fapi target.
 * @param[out] o_type Filled in with the DIMM DDR Type.
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode getDdrType(const fapi::Target & i_dimm,
                            fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type & o_type)
{
    fapi::ReturnCode l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &i_dimm,
                                          o_type);
    if (l_rc)
    {
        FAPI_ERR("getSpdAttrAccessor: Error querying DDR type");
    }
    else if ((o_type != fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3) &&
             (o_type != fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4))
    {
        FAPI_ERR("getSpdAttrAccessor: Invalid DIMM DDR Type 0x%02x", o_type);
        const fapi::Target & DIMM = i_dimm;
        const fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type & TYPE = o_type;
        FAPI_SET_HWP_ERROR(l_rc, RC_GET_SPD_ACCESSOR_INVALID_DDR_TYPE);
    }

    return l_rc;
}

/**
 * @brief Returns SPD_SDRAM_BANKS data
 *
 * The raw data has different meanings for DDR3 and DDR4, this HWP translates
 * each to the enumeration in the common FAPI Attribute
 *
 * @param[in]  i_dimm Reference to DIMM fapi target
 * @param[in]  i_attr The Attribute to get
 * @param[out] o_pVal Pointer to data buffer filled in with attribute data
 * @param[in]  i_len  Size of o_pVal
 * @param[in]  i_type DDR Type
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_SPD_SDRAM_BANKS(const fapi::Target & i_dimm,
    const fapi::getSpdAttr::Attr i_attr,
    void * o_pVal,
    const size_t i_len,
    const fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type i_type)
{
    fapi::ATTR_SPD_SDRAM_BANKS_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_SPD_SDRAM_BANKS_Type *>(o_pVal));
    o_val = 0;

    fapi::ReturnCode l_rc = checkSize(i_attr, i_len, sizeof(o_val));

    if (!l_rc)
    {
        if (i_type == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            fapi::ATTR_SPD_SDRAM_BANKS_DDR3_Type l_banks = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_BANKS_DDR3, &i_dimm, l_banks);

            if (l_rc)
            {
                FAPI_ERR("get_SPD_SDRAM_BANKS: Error getting DDR3 attr");
            }
            else
            {
                switch (l_banks)
                {
                case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_DDR3_B8:
                    o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B8;
                    break;
                case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_DDR3_B16:
                    o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B16;
                    break;
                case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_DDR3_B32:
                    o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B32;
                    break;
                case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_DDR3_B64:
                    o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B64;
                    break;
                default:
                   FAPI_ERR("get_SPD_SDRAM_BANKS: Unrecognized DDR3 attr 0x%x",
                            l_banks);
                   o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_UNKNOWN;
                }
            }
        }
        else
        {
            fapi::ATTR_SPD_SDRAM_BANKS_DDR4_Type l_banks = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_BANKS_DDR4, &i_dimm, l_banks);

            if (l_rc)
            {
                FAPI_ERR("get_SPD_SDRAM_BANKS: Error getting DDR4 attr");
            }
            else
            {
                switch (l_banks)
                {
                case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_DDR4_B4:
                    o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B4;
                    break;
                case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_DDR4_B8:
                    o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B8;
                    break;
                   FAPI_ERR("get_SPD_SDRAM_BANKS: Unrecognized DDR4 attr 0x%x",
                            l_banks);
                   o_val = fapi::ENUM_ATTR_SPD_SDRAM_BANKS_UNKNOWN;
                }
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns SPD_MODULE_NOMINAL_VOLTAGE data
 *
 * The raw data has different meanings for DDR3 and DDR4, this HWP translates
 * each to the enumeration in the common FAPI Attribute
 *
 * @param[in]  i_dimm Reference to DIMM fapi target
 * @param[in]  i_attr The Attribute to get
 * @param[out] o_pVal Pointer to data buffer filled in with attribute data
 * @param[in]  i_len  Size of o_pVal
 * @param[in]  i_type DDR Type
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_SPD_MODULE_NOMINAL_VOLTAGE(const fapi::Target & i_dimm,
    const fapi::getSpdAttr::Attr i_attr,
    void * o_pVal,
    const size_t i_len,
    const fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type i_type)
{
    fapi::ATTR_SPD_MODULE_NOMINAL_VOLTAGE_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_SPD_MODULE_NOMINAL_VOLTAGE_Type *>(
            o_pVal));
    o_val = 0;

    fapi::ReturnCode l_rc = checkSize(i_attr, i_len, sizeof(o_val));

    if (!l_rc)
    {
        if (i_type == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            fapi::ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3_Type l_voltage = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3, &i_dimm,
                                 l_voltage);

            if (l_rc)
            {
                FAPI_ERR("get_SPD_MODULE_NOMINAL_VOLTAGE: Error getting DDR3 attr");
            }
            else
            {
                if (l_voltage &
                    fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3_NOTOP1_5)
                {
                    o_val |=
                        fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5;
                }
                if (l_voltage &
                    fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3_OP1_35)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35;
                }
                if (l_voltage &
                    fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3_OP1_2X)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2X;
                }
            }
        }
        else
        {
            fapi::ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR4_Type l_voltage = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR4, &i_dimm,
                                 l_voltage);

            if (l_rc)
            {
                FAPI_ERR("get_SPD_MODULE_NOMINAL_VOLTAGE: Error getting DDR4 attr");
            }
            else
            {
                if (l_voltage &
                    fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR4_OP1_2V)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V;
                }
                if (l_voltage &
                    fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR4_END1_2V)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_END1_2V;
                }
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns SPD_CAS_LATENCIES_SUPPORTED data
 *
 * The raw data has different meanings for DDR3 and DDR4, this HWP translates
 * each to the enumeration in the common FAPI Attribute
 *
 * @param[in]  i_dimm Reference to DIMM fapi target
 * @param[in]  i_attr The Attribute to get
 * @param[out] o_pVal Pointer to data buffer filled in with attribute data
 * @param[in]  i_len  Size of o_pVal
 * @param[in]  i_type DDR Type
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_SPD_CAS_LATENCIES_SUPPORTED(const fapi::Target & i_dimm,
    const fapi::getSpdAttr::Attr i_attr,
    void * o_pVal,
    const size_t i_len,
    const fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type i_type)
{
    fapi::ATTR_SPD_CAS_LATENCIES_SUPPORTED_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_SPD_CAS_LATENCIES_SUPPORTED_Type *>(
            o_pVal));
    o_val = 0;

    fapi::ReturnCode l_rc = checkSize(i_attr, i_len, sizeof(o_val));

    if (!l_rc)
    {
        if (i_type == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            fapi::ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_Type cl = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3, &i_dimm,
                                 cl);
            if (l_rc)
            {
                FAPI_ERR("get_SPD_CAS_LATENCIES_SUPPORTED: Error getting DDR3 attr");
            }
            else
            {
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_4)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_4;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_5)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_5;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_6)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_6;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_7)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_7;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_8)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_8;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_9)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_9;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_10)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_10;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_11)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_11;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_12)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_12;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_13)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_13;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_14)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_14;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_15)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_15;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_16)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_16;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_17)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_17;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_CL_18)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_18;
                }
            }
        }
        else
        {
            fapi::ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_Type cl = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4, &i_dimm,
                                 cl);
            if (l_rc)
            {
                FAPI_ERR("get_SPD_CAS_LATENCIES_SUPPORTED: Error getting DDR4 attr");
            }
            else
            {
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_7)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_7;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_8)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_8;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_9)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_9;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_10)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_10;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_11)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_11;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_12)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_12;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_13)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_13;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_14)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_14;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_15)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_15;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_16)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_16;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_17)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_17;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_18)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_18;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_19)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_19;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_20)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_20;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_21)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_21;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_22)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_22;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_23)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_23;
                }
                if (cl & fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_CL_24)
                {
                    o_val |= fapi::ENUM_ATTR_SPD_CAS_LATENCIES_SUPPORTED_CL_24;
                }
            }
        }
    }

    return l_rc;
}

/**
 * @brief Returns SPD_MODULE_REVISION_CODE data
 *
 * The fields are different sizes for DDR3 and DDR4, this HWP copies the value
 * to the attribute size in the common FAPI Attribute
 *
 * @param[in]  i_dimm Reference to DIMM fapi target
 * @param[in]  i_attr The Attribute to get
 * @param[out] o_pVal Pointer to data buffer filled in with attribute data
 * @param[in]  i_len  Size of o_pVal
 * @param[in]  i_type DDR Type
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode get_SPD_MODULE_REVISION_CODE(const fapi::Target & i_dimm,
    const fapi::getSpdAttr::Attr i_attr,
    void * o_pVal,
    const size_t i_len,
    const fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type i_type)
{
    fapi::ATTR_SPD_MODULE_REVISION_CODE_Type & o_val =
        *(reinterpret_cast<fapi::ATTR_SPD_MODULE_REVISION_CODE_Type *>(o_pVal));
    o_val = 0;

    fapi::ReturnCode l_rc = checkSize(i_attr, i_len, sizeof(o_val));

    if (!l_rc)
    {
        if (i_type == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            // Size of DDR3 data matches DDR neutral attribute (uint32_t)
            l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_REVISION_CODE_DDR3, &i_dimm,
                                 o_val);

            if (l_rc)
            {
                FAPI_ERR("get_SPD_MODULE_REVISION_CODE: Error getting DDR3 attr");
            }
        }
        else
        {
            // Size of DDR4 data (uint8_t) is smaller than the DDR neutral
            // attribute (uint32_t)
            fapi::ATTR_SPD_MODULE_REVISION_CODE_DDR4_Type l_code = 0;
            l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_REVISION_CODE_DDR4, &i_dimm,
                                 l_code);

            if (l_rc)
            {
                FAPI_ERR("get_SPD_MODULE_NOMINAL_VOLTAGE: Error getting DDR4 attr");
            }
            else
            {
                o_val = static_cast<fapi::ATTR_SPD_MODULE_REVISION_CODE_Type>(
                    l_code);
            }
        }
    }

    return l_rc;
}

//-----------------------------------------------------------------------------
// getSpdAttrAccessor HWP - See header file for details
//-----------------------------------------------------------------------------
fapi::ReturnCode getSpdAttrAccessor(const fapi::Target & i_dimm,
                                    const fapi::getSpdAttr::Attr i_attr,
                                    void * o_pVal,
                                    const size_t i_len)
{
    fapi::ReturnCode l_rc;

    fapi::ATTR_SPD_DRAM_DEVICE_TYPE_Type l_type = 0;
    l_rc = getDdrType(i_dimm, l_type);

    if (l_rc)
    {
        FAPI_ERR("getSpdAttrAccessor: Error from getDdrType for Attr ID 0x%02x",
                 i_attr);
    }
    else
    {
        switch (i_attr)
        {
        case fapi::getSpdAttr::SPD_SDRAM_BANKS:
            l_rc = get_SPD_SDRAM_BANKS(i_dimm, i_attr, o_pVal, i_len, l_type);
            break;
        case fapi::getSpdAttr::SPD_MODULE_NOMINAL_VOLTAGE:
            l_rc = get_SPD_MODULE_NOMINAL_VOLTAGE(i_dimm,  i_attr,o_pVal, i_len,
                                                  l_type);
            break;
        case fapi::getSpdAttr::SPD_CAS_LATENCIES_SUPPORTED:
            l_rc = get_SPD_CAS_LATENCIES_SUPPORTED(i_dimm, i_attr, o_pVal,
                                                   i_len, l_type);
            break;
        case fapi::getSpdAttr::SPD_MODULE_REVISION_CODE:
            l_rc = get_SPD_MODULE_REVISION_CODE(i_dimm,  i_attr, o_pVal, i_len,
                                                l_type);
            break;
        default:
            FAPI_ERR("getSpdAttrAccessor: Invalid Attribute ID 0x%02x", i_attr);
            const fapi::getSpdAttr::Attr & ATTR_ID = i_attr;
            FAPI_SET_HWP_ERROR(l_rc, RC_GET_SPD_ACCESSOR_INVALID_ATTRIBUTE_ID);
        }
    }

    return l_rc;
}

}
