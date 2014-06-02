/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/chip_accessors/getPciOscswitchConfig.C $     */
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
// $Id: getPciOscswitchConfig.C,v 1.2 2014/01/15 20:03:06 whs Exp $
/**
 *  @file getPciOscswitchConfig.C
 *
 *  @brief Accessor for providing the ATTR_PCI_OSCSWITCH_CONFIG attribute
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getPciOscswitchConfig.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getPciOscswitchConfig(
                              const fapi::Target   &i_procTarget,
                              uint8_t  & o_val)
{
    fapi::ReturnCode l_fapirc;
    fapi::ATTR_NAME_Type    l_chipType = 0x00;
    const uint32_t DEFAULT_EC_VALUE = 0x10;
    uint8_t        l_attrDdLevel = DEFAULT_EC_VALUE;
    uint32_t       l_position = 0;

    FAPI_DBG("getPciOscswitchConfig: entry ");

    do {
        FAPI_DBG("getPciOscswitchConfig: parent path=%s ",
             i_procTarget.toEcmdString()  );

        // Get chip type
        l_fapirc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME,
                                          &i_procTarget,
                                          l_chipType);
        if (l_fapirc)  {
            FAPI_ERR("getPciOscswitchConig:FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME) "
                         "failed w/rc=0x%08x",
                         static_cast<uint32_t>(l_fapirc) );
           break; // break out with error
        }
        FAPI_DBG("getPciOscswitchConfig: Chip type=0x%02x",l_chipType);

        // Get EC level
        l_fapirc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC,
                                          &i_procTarget,
                                          l_attrDdLevel);
        if (l_fapirc)  {
            FAPI_ERR("getPciOscswitchConig:FAPI_ATTR_GET_PRIVILEGED(ATTR_EC) "
                         "failed w/rc=0x%08x",
                         static_cast<uint32_t>(l_fapirc) );
           break; // break out with error
        }
        FAPI_DBG("getPciOscswitchConfig: EC level=0x%02x",l_attrDdLevel);

        // Get the position
        l_fapirc = FAPI_ATTR_GET_PRIVILEGED(ATTR_POS,
                                          &i_procTarget,
                                          l_position);
        if (l_fapirc)  {
            FAPI_ERR("getPciOscswitchConig:FAPI_ATTR_GET_PRIVILEGED(ATTR_POS) "
                         "failed w/rc=0x%08x",
                         static_cast<uint32_t>(l_fapirc) );
           break; // break out with error
        }
        FAPI_DBG("getPciOscswitchConfig: position=0x%08x",l_position);

        // determine value to return
        if (l_chipType == ENUM_ATTR_NAME_MURANO)
        {
            if (l_attrDdLevel < 0x20 )
            {
                o_val = MURANO_DD1X;
            }
            else if (l_attrDdLevel < 0x30 )
            {
                o_val = MURANO_DD2X;
            }
            else
            {
               FAPI_ERR("getPciOscswitchConfig: unexpected ec=0x%02x",
                        l_attrDdLevel);
               const uint32_t & FFDC_CHIP_EC = l_attrDdLevel;
               FAPI_SET_HWP_ERROR(l_fapirc,RC_OSC_SWITCH_UNEXPECTED_CHIP_EC);
               break; // break out with error
            }
        }
        else if (l_chipType == ENUM_ATTR_NAME_VENICE)
        {
            if (l_position == 0x00 || l_position == 0x02 )
            {
                o_val = VENICE_P0P2;
            }
            else if (l_position == 0x01 || l_position == 0x03 )
            {
                o_val = VENICE_P1P3;
            }
            else
            {
               FAPI_ERR("getPciOscswitchConfig: unexpected position=0x%08x",
                        l_position);
               const uint32_t & FFDC_CHIP_POSITION = l_position;
               FAPI_SET_HWP_ERROR(l_fapirc,
                          RC_OSC_SWITCH_UNEXPECTED_CHIP_POSITION);
               break; // break out with error
            }
        }
        // TODO RTC: 109249 Check to see if  DD1X is correct,
        // it was based off Murano DD2X
        else if (l_chipType == ENUM_ATTR_NAME_NAPLES)
        {
            o_val = NAPLES_DD1X;
        }
        else
        {
            FAPI_ERR("getPciOscswitchConfig: unexpected chip type=0x%02x",
                        l_chipType);
            const uint32_t & FFDC_CHIP_TYPE = l_chipType;
            FAPI_SET_HWP_ERROR(l_fapirc,RC_OSC_SWITCH_UNEXPECTED_CHIP_TYPE);
            break; // break out with error
        }
        FAPI_DBG("getPciOscswitchConfig: pci oscswitch config=0x%02x",
                o_val);

    } while (0);

    FAPI_DBG("getPciOscswitchConfig: exit rc=0x%08x)",
               static_cast<uint32_t>(l_fapirc));

    return  l_fapirc;
}

}   // extern "C"
