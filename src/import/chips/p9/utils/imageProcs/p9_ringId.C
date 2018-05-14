/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ringId.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#include <p9_infrastruct_help.H>

namespace P9_RID
{
#include "p9_ringId.H"
};


using namespace P9_RID;

int P9_RID::ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData)
{
    switch (i_chipletType)
    {
        case PERV_TYPE :
            *o_chipletData = (ChipletData_t*)&PERV::g_chipletData;
            break;

        case N0_TYPE :
            *o_chipletData = (ChipletData_t*)&N0::g_chipletData;
            break;

        case N1_TYPE :
            *o_chipletData = (ChipletData_t*)&N1::g_chipletData;
            break;

        case N2_TYPE :
            *o_chipletData = (ChipletData_t*)&N2::g_chipletData;
            break;

        case N3_TYPE :
            *o_chipletData = (ChipletData_t*)&N3::g_chipletData;
            break;

        case XB_TYPE :
            *o_chipletData = (ChipletData_t*)&XB::g_chipletData;
            break;

        case MC_TYPE :
            *o_chipletData = (ChipletData_t*)&MC::g_chipletData;
            break;

        case OB0_TYPE :
            *o_chipletData = (ChipletData_t*)&OB0::g_chipletData;
            break;

        case OB1_TYPE :
            *o_chipletData = (ChipletData_t*)&OB1::g_chipletData;
            break;

        case OB2_TYPE :
            *o_chipletData = (ChipletData_t*)&OB2::g_chipletData;
            break;

        case OB3_TYPE :
            *o_chipletData = (ChipletData_t*)&OB3::g_chipletData;
            break;

        case PCI0_TYPE :
            *o_chipletData = (ChipletData_t*)&PCI0::g_chipletData;
            break;

        case PCI1_TYPE :
            *o_chipletData = (ChipletData_t*)&PCI1::g_chipletData;
            break;

        case PCI2_TYPE :
            *o_chipletData = (ChipletData_t*)&PCI2::g_chipletData;
            break;

        case EQ_TYPE :
            *o_chipletData = (ChipletData_t*)&EQ::g_chipletData;
            break;

        case EC_TYPE :
            *o_chipletData = (ChipletData_t*)&EC::g_chipletData;
            break;

        default :
            MY_ERR("Invalid chipletType(=%d)\n", i_chipletType);
            return TOR_INVALID_CHIPLET_TYPE;
    }

    return INFRASTRUCT_RC_SUCCESS;
}
