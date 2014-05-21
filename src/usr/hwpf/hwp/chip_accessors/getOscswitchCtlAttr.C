/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/chip_accessors/getOscswitchCtlAttr.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: getOscswitchCtlAttr.C,v 1.1 2014/05/23 01:19:13 whs Exp $
/**
 *  @file getOscswitchCtlAttr.C
 *
 *  @brief Accessor for providing the ATTR_OSCSWITCH_CTLx attributes
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getOscswitchCtlAttr.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getOscswitchSizeCheck(
                                  const fapi::getOscswitchCtl::Attr i_attr,
                                  const size_t i_fieldSize,
                                  const size_t i_len);

// ----------------------------------------------------------------------------
// HWP accessor for providing ATTR_OSCSWITCH_CTLx attributes
// ----------------------------------------------------------------------------
fapi::ReturnCode getOscswitchCtlAttr( const fapi::Target & i_pProcTarget,
                                  const fapi::getOscswitchCtl::Attr i_attr,
                                  void * o_pVal,
                                  const size_t i_len)
{
    fapi::ReturnCode l_fapirc;

    FAPI_DBG("getOscswitchCtlAttr: entry ");

    do {
        // see if platform has redundant clocks
        uint8_t  l_redundantClocks = 0;
        l_fapirc = FAPI_ATTR_GET(ATTR_REDUNDANT_CLOCKS,
                                          NULL,
                                          l_redundantClocks);
        if (l_fapirc)
        {
             FAPI_ERR("getOscswitchCtlAttr:FAPI_ATTR_GET(ATTR_REDUNDANT_CLOCKS)"
                     " failed w/rc=0x%08x",
                     static_cast<uint32_t>(l_fapirc) );
            break; // break out with error
        }

        // find the chip type if there are redundant clocks, otherwise use
        // the ENUM_ATTR_NAME_NONE entry for systems without redundant clocks
        fapi::ATTR_NAME_Type    l_chipType = ENUM_ATTR_NAME_NONE ;
        if (l_redundantClocks)
        {
            // Get chip type
            l_fapirc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME,
                                          &i_pProcTarget,
                                          l_chipType);
            if (l_fapirc)
            {
                 FAPI_ERR("getOscswitchCtlAttr:"
                         " FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME) "
                         "failed w/rc=0x%08x",
                         static_cast<uint32_t>(l_fapirc) );
                break; // break out with error
            }
        }
        FAPI_DBG("getOscswitchCtlAttr: Chip type=0x%02x",l_chipType);

        // find entry in Oscswitch Ctl data table
        const    getOscswitchCtl::OSCSWITCH_CTL_DATA * l_pOscswitchCtlData =
                 reinterpret_cast<const getOscswitchCtl::OSCSWITCH_CTL_DATA *>
                 (&getOscswitchCtl::OSCSWITCH_CTL_DATA_array);
        uint8_t l_data = 0;
        uint8_t l_tableSize = sizeof(getOscswitchCtl::OSCSWITCH_CTL_DATA_array)/
                               sizeof(getOscswitchCtl::OSCSWITCH_CTL_DATA);
        for (l_data = 0; l_data<l_tableSize; l_data++)
        {
            if (l_pOscswitchCtlData[l_data].l_CHIP_TYPE == l_chipType)
            {
                break; //found match. Could add EC check here if ever needed
            }
        }
        if (l_data >= l_tableSize) // did not find an entry
        {
            const uint32_t FFDC_CHIP_TYPE = l_chipType;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_OSC_SWITCH_CTL_UNEXPECTED_CHIP_TYPE);
            break ; // break with error
        }

        // return requested attribute value
        switch (i_attr)
        {
            case fapi::getOscswitchCtl::CTL0:
            {
                uint32_t * l_pCtl0 = (uint32_t *) o_pVal;
                l_fapirc = getOscswitchSizeCheck(i_attr,
                           sizeof (l_pOscswitchCtlData[l_data].l_CTL0),
                           i_len);
                if (l_fapirc)
                {
                    break; // break with error
                }
                *l_pCtl0 = l_pOscswitchCtlData[l_data].l_CTL0;
                break;
            }
            case fapi::getOscswitchCtl::CTL1:
            {
                uint8_t * l_pCtl1 = (uint8_t *) o_pVal;
                l_fapirc = getOscswitchSizeCheck(i_attr,
                           sizeof (l_pOscswitchCtlData[l_data].l_CTL1),
                           i_len);
                if (l_fapirc)
                {
                    break; // break with error
                }
                *l_pCtl1 = l_pOscswitchCtlData[l_data].l_CTL1;
                break;
            }
            case fapi::getOscswitchCtl::CTL2:
            {
                uint32_t * l_pCtl2 = (uint32_t *) o_pVal;
                l_fapirc = getOscswitchSizeCheck(i_attr,
                           sizeof (l_pOscswitchCtlData[l_data].l_CTL2),
                           i_len);
                if (l_fapirc)
                {
                    break; // break with error
                }
                *l_pCtl2 = l_pOscswitchCtlData[l_data].l_CTL2;
                break;
            }
            default:
            {
                const uint8_t FFDC_UNEXPECTED_ATTR = i_attr;
                FAPI_SET_HWP_ERROR(l_fapirc,RC_OSC_SWITCH_CTL_UNEXPECTED_ATTR);
                break ; // break with error
            }
        }

    } while (0);

    FAPI_DBG("getOscswitchCtlAttr: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

// check output field length
fapi::ReturnCode getOscswitchSizeCheck(
                                  const fapi::getOscswitchCtl::Attr i_attr,
                                  const size_t i_fieldSize,
                                  const size_t i_len)
{
    fapi::ReturnCode l_fapirc;
    if (i_len != i_fieldSize)
    {
        const fapi::getOscswitchCtl::Attr FFDC_ATTR = i_attr;
        const size_t  FFDC_EXPECTED_SIZE = i_fieldSize;
        const size_t  FFDC_PASSED_SIZE = i_len;
        FAPI_SET_HWP_ERROR(l_fapirc,RC_OSC_SWITCH_CTL_INVALID_ATTR_SIZE);
    }
    return  l_fapirc;
}


}   // extern "C"
