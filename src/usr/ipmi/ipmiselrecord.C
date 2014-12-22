/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmiselrecord.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
/**
 * @file ipmiselrecord.C
 * @brief code for the IPMI sel record class
 */

#include <ipmi/ipmiif.H>

namespace IPMI
{
    ///
    /// @brief populate an OEM SEL record from an event read
    /// @param[in] i_raw_event_data, pointer to the read event data
    ///
    void oemSEL::populateFromEvent(uint8_t const* i_raw_event_data)
    {
        iv_record = i_raw_event_data[0] << 8 | i_raw_event_data[1];
        iv_record_type = i_raw_event_data[2];
        iv_timestamp = i_raw_event_data[6] << 24 |
                       i_raw_event_data[5] << 16 |
                       i_raw_event_data[4] << 8  |
                       i_raw_event_data[3];

        memcpy(iv_manufacturer, &i_raw_event_data[7], MANUF_LENGTH);
        iv_netfun = i_raw_event_data[10];
        memcpy(iv_cmd, &i_raw_event_data[11], CMD_LENGTH);

        return;
    }

};
