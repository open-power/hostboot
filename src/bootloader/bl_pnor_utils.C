/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_pnor_utils.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#include <bootloader/bootloader.H>

#define bl_pnor_utils_C

#include <stdio.h>
#include <endian.h>

int strcmp(const char *str1, const char *str2)
{
    for(uint32_t strcmp_index = 0;
        strcmp_index < 12;
        strcmp_index++)
    {
        if((str1[strcmp_index] == '\0') && (str2[strcmp_index] == '\0'))
        {
            return 0;
        }
        else if(str1[strcmp_index] ==  str2[strcmp_index])
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

#include <pnor_utils.C>

#undef bl_pnor_utils_C


