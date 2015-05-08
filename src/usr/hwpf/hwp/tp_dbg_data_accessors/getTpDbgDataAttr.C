/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tp_dbg_data_accessors/getTpDbgDataAttr.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: getTpDbgDataAttr.C,v 1.1 2015/05/07 20:11:12 thi Exp $
/**
 *  @file getTpDbgDataAttr.C
 *
 *  @brief Fetch TP Debug data attributes based on chip EC
 *         from static arrays (fapiTpDbgDataAttr.H)
 *
 */

#include <stdint.h>
#include <fapi.H>
#include <getTpDbgDataAttr.H>

extern "C"
{

/**
 * @brief Internal utility function to verify if TP_DBG data is found for
 *        input target's type and EC level.
 *        Output the index number of the data array for the target.
 *
 * @param i_fapiTarget cpu target
 * @param o_index      The index where TP_DBG data is held for this target.
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode verifyTpDbgData(const fapi::Target  &i_fapiTarget,
                                 uint32_t & o_index)
{
    FAPI_INF("verifyTpDbgData: entry" );

    // Define and initialize variables
    uint8_t                    l_attrDdLevel = 0;
    fapi::TargetType           l_targetType = fapi::TARGET_TYPE_NONE;
    fapi::ATTR_NAME_Type       l_chipType = 0x00;
    fapi::ReturnCode           rc;

    do
    {
        // Verify input target is a processor
        l_targetType = i_fapiTarget.getType();
        if (l_targetType != fapi::TARGET_TYPE_PROC_CHIP)
        {
            FAPI_ERR("verifyTpDbgData: Invalid target type passed on "
                     "invocation. target type=0x%08X ", 
                      static_cast<uint32_t>(l_targetType));
            // Return error on get attr
            fapi::TargetType & TARGET_TYPE = l_targetType;
            FAPI_SET_HWP_ERROR(rc, RC_GET_TP_DBG_DATA_PARAMETER_ERR );
            break;
        }

        // Get chip type
        rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME,
                                      &i_fapiTarget,
                                      l_chipType);
        if (rc)
        {
            FAPI_ERR("verifyTpDbgData: FAPI_ATTR_GET_PRIVILEGED of "
                     "ATTR_NAME failed w/rc=0x%08X", 
                      static_cast<uint32_t>(rc));
            break;
        }

        // Get EC level
        rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC,
                                      &i_fapiTarget,
                                      l_attrDdLevel);
        // Exit on error
        if (rc)
        {
            FAPI_ERR("verifyTpDbgData: FAPI_ATTR_GET_PRIVILEGED of "
                     "ATTR_EC failed w/rc=0x%08X", static_cast<uint32_t>(rc));
            break;
        }

        FAPI_INF("verifyTpDbgData:  Chip type=0x%02x EC=0x%02x ",
                 l_chipType, l_attrDdLevel);

        // Murano DD1.2 and DD1.0 are equivalent in terms of engineering data
        if ((l_chipType == fapi::ENUM_ATTR_NAME_MURANO) &&
            (l_attrDdLevel == 0x12))
        {
            FAPI_INF("verifyTpDbgData: Treating EC1.2 like EC1.0");
            l_attrDdLevel = 0x10;
        }

        FAPI_INF("verifyTpDbgData: chiptype=0x%x EC=0x%x", l_chipType, l_attrDdLevel);
        // Use chip & ec to select array entry and selection attr to select 
        // data array entry
        o_index = 0;
        uint32_t ii = 0;
        for (ii = 0;
             ii < (sizeof(TP_DBG_DATA_array) / sizeof(TP_DBG_DATA_ATTR));
             ii++)
        {
             if ((TP_DBG_DATA_array[ii].l_ATTR_CHIPTYPE == l_chipType) &&
                 (TP_DBG_DATA_array[ii].l_ATTR_EC       == l_attrDdLevel))
             {
                 o_index = ii;
                 break;
             }
        }

        // No match found
        if (ii == (sizeof(TP_DBG_DATA_array)/sizeof(TP_DBG_DATA_ATTR)))
        {
            FAPI_ERR("verifyTpDbgData:  No match found for chiptype=0x%x "
                     "EC=0x%x", l_chipType, l_attrDdLevel);
            // Return error on get attr
            fapi::ATTR_NAME_Type & CHIP_NAME = l_chipType;
            uint8_t & CHIP_EC = l_attrDdLevel;
            FAPI_SET_HWP_ERROR(rc, RC_GET_TP_DBG_DATA_ERR );
            break;
        }
        
    } while (0);

    FAPI_INF("verifyTpDbgData: exit rc=0x%x",
             static_cast<uint32_t>(rc) );
    return  rc;
}


/**
 * @brief Get processor TP VITL spy length for the specified target CPU.
 * See doxygen in .H file
 */
fapi::ReturnCode getPervVitlRingLengthAttr(const fapi::Target  &i_fapiTarget,
                                           uint32_t (&o_ringLength))
{
    FAPI_INF("getPervVitlRingLengthAttr: entry" );

    // Initialize return values to 0x00
    fapi::ReturnCode rc;
    uint32_t l_dataIndex = 0;
    o_ringLength = 0;

    // Get attributes, currently there's only one array entry
    do
    {
        rc = verifyTpDbgData(i_fapiTarget, l_dataIndex);
        if (rc)
        {
            FAPI_ERR("getPervVitlRingLengthAttr: verifyTpDbgData() returns error");
            break;
        }
        o_ringLength = TP_DBG_DATA_array [l_dataIndex].l_ATTR_RING_LENGTH;
        FAPI_INF("getPervVitlRingLengthAttr: index %d, o_ringLength=%d",
                 l_dataIndex, o_ringLength);
    } while (0);

    FAPI_INF("getPervVitlRingLengthAttr: exit rc=0x%x",
             static_cast<uint32_t>(rc) );
    return  rc;
}


/**
 * @brief Get processor PERV VITL ring length for the specified target CPU.
 * See doxygen in .H file
 */
fapi::ReturnCode getTpVitlSpyLengthAttr(const fapi::Target  &i_fapiTarget,
                                        uint32_t (&o_spyLength))
{
    FAPI_INF("getTpVitlSpyLengthAttr: entry" );

    // Initialize return values to 0x00
    uint32_t l_dataIndex = 0;
    fapi::ReturnCode rc;

    // Get attributes, currently there's only one array entry
    do
    {
        rc = verifyTpDbgData(i_fapiTarget, l_dataIndex);
        if (rc)
        {
            FAPI_ERR("getTpVitlSpyLengthAttr: verifyTpDbgData() returns error");
            break;
        }
        o_spyLength = TP_DBG_DATA_array [l_dataIndex].l_ATTR_SPY_LENGTH;
        FAPI_INF("getTpVitlSpyLengthAttr: index %d, o_spyLength=%d",
                 l_dataIndex, o_spyLength);
    } while (0);

    FAPI_INF("getTpVitlSpyLengthAttr: exit rc=0x%x",
             static_cast<uint32_t>(rc) );
    return  rc;
}


/**
 * @brief Get processor TP VITL spy offsets for the specified target CPU.
 * See doxygen in .H file
 */
fapi::ReturnCode getTpVitlSpyOffsetAttr(const fapi::Target  &i_fapiTarget,
                                        uint32_t (&o_data)[SPY_OFFSET_SIZE])
{
    FAPI_INF("getTpVitlSpyOffsetAttr: entry" );

    // Initialize return values to 0x00
    fapi::ReturnCode rc;
    uint32_t l_dataIndex = 0;
    memset(o_data, 0x00, sizeof(o_data));

    // Get attributes, currently there's only one array entry
    do
    {
        rc = verifyTpDbgData(i_fapiTarget, l_dataIndex);
        if (rc)
        {
            FAPI_ERR("getTpVitlSpyOffsetAttr: verifyTpDbgData() returns error");
            break;
        }
        memcpy(o_data, TP_DBG_DATA_array[l_dataIndex].l_ATTR_TP_DBG_DATA,
               sizeof(o_data));
    } while (0);

    FAPI_INF("getTpVitlSpyOffsetAttr: exit rc=0x%x",
             static_cast<uint32_t>(rc) );
    return  rc;
}

}   // extern "C"

