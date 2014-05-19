/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devicefw/devfwreasoncodes.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __DEVICEFW_DEVFWREASONCODES_H
#define __DEVICEFW_DEVFWREASONCODES_H

#include <hbotcompid.H>

namespace DeviceFW
{
    enum DevFwModuleId
    {
        DEVFW_MOD_ASSOCIATOR    = 0x01,
    };

    enum DevFwReasonCode
    {
        DEVFW_RC_INVALID_REGISTRATION   = DEVFW_COMP_ID | 0x01,
        DEVFW_RC_NO_ROUTE_FOUND         = DEVFW_COMP_ID | 0x02,
        DEVFW_RC_NULL_TARGET            = DEVFW_COMP_ID | 0x03,
        DEVFW_RC_DOUBLE_REGISTRATION    = DEVFW_COMP_ID | 0x04,
    };
};

#endif
