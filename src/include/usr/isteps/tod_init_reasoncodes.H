/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/tod_init_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef TOD_INIT_REASONCODES_H
#define TOD_INIT_REASONCODES_H

//@todo-RTC:149253-Move these to a better place later

#include <hbotcompid.H>

namespace TOD
{
    enum TODModuleId
    {
        TOD_PICK_MDMT                         = 0x01,
        TOD_BUILD_TOD_DRAWERS                 = 0x02,
        TOD_QUERY_ACTIVE_CONFIG               = 0x03,
        TOD_FIND_MASTER_PROC                  = 0x04,
        TOD_SETUP_HWP                         = 0x05,
        TOD_SAVEREGS_HWP                      = 0x06,
        TOD_LOG_UNSUPPORTED_BUSTYPE           = 0x07,
        TOD_LOG_UNSUPPORTED_BUSPORT           = 0x08,
        TOD_SETUP                             = 0x09,
        TOD_READ                              = 0x0A,
        TOD_LOG_INVALID_CONFIG                = 0x0B,
        TOD_LOG_UNSUPORTED_ORDINALID          = 0x0C,
        TOD_GETSCOM                           = 0x0D,
        TOD_GETFUNCNODETARGETSONSYSTEM        = 0x0E,
        TOD_TOPOLOGY_CREATE                   = 0x0F,
        TOD_WIRE_PROCS                        = 0x10,
        TOD_WIRE_DRAWERS                      = 0x11,
        TOD_INIT_HWP                          = 0x12,
    };

    enum TODReasonCode
    {
        TOD_NO_MASTER_PROC                    = TOD_COMP_ID | 0x01,
        TOD_NO_FUNC_NODE_AVAILABLE            = TOD_COMP_ID | 0x02,
        TOD_NO_DRAWERS                        = TOD_COMP_ID | 0x03,
        TOD_HW_ERROR                          = TOD_COMP_ID | 0x04,
        TOD_UNSUPPORTED_BUSTYPE               = TOD_COMP_ID | 0x05,
        TOD_UNSUPPORTED_BUSPORT               = TOD_COMP_ID | 0x06,
        TOD_INVALID_ACTION                    = TOD_COMP_ID | 0x07,
        TOD_INVALID_CONFIG                    = TOD_COMP_ID | 0x08,
        TOD_UNSUPORTED_ORDINALID              = TOD_COMP_ID | 0x09,
        TOD_ECMD_ERROR                        = TOD_COMP_ID | 0x0A,
        TOD_NULL_INPUT_TARGET                 = TOD_COMP_ID | 0x0B,
        TOD_INVALID_TARGET                    = TOD_COMP_ID | 0x0C,
        TOD_CREATION_ERR                      = TOD_COMP_ID | 0x0D,
        TOD_CREATION_ERR_NO_DRAWER            = TOD_COMP_ID | 0x0E,
        TOD_CANNOT_WIRE_DRAWER                = TOD_COMP_ID | 0x0F,
    };

};
#endif
