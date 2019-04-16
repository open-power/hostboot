/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/expupd/expupd_reasoncodes.H $                 */
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

#ifndef __EXPUPD_REASONCODES_H
#define __EXPUPD_REASONCODES_H

#include <hbotcompid.H>

namespace EXPUPD
{

    enum ExpUpdModuleId
    {
        MOD_UPDATE_ALL_EXP_FLASH_IMAGES = 0x01,
    };

    enum ExpUpdReasonCode
    {
        EXPUPD_INVALID_EYECATCHER                        = UCD_COMP_ID | 0x01,
        EXPUPD_INVALID_MAJOR_VER                         = UCD_COMP_ID | 0x02,
    };

}; // namespace EXPUPD

#endif
