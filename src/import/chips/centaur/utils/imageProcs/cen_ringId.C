/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/utils/imageProcs/cen_ringId.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

#include <string.h>
#include <common_ringId.H>

namespace CEN_RID
{
#include "cen_ringId.H"
};


using namespace CEN_RID;

void CEN_RID::ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData)
{
    switch (i_chipletType)
    {
        case CEN_TYPE :
            *o_chipletData = (ChipletData_t*)&CEN::g_chipletData;
            break;

        default :
            *o_chipletData = NULL;
            break;
    }
}
