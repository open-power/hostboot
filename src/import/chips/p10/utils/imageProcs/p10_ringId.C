/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ringId.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

//#include <string.h>
#include <common_ringId.H>
#include <p10_infrastruct_help.H>

namespace P10_RID
{
#include "p10_ringId.H"
};


using namespace P10_RID;

int P10_RID::ringid_get_chiplet_properties(
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

        case PCI_TYPE :
            *o_chipletData = (ChipletData_t*)&PCI::g_chipletData;
            break;

        case MC_TYPE :
            *o_chipletData = (ChipletData_t*)&MC::g_chipletData;
            break;

        case PAU0_TYPE :
            *o_chipletData = (ChipletData_t*)&PAU0::g_chipletData;
            break;

        case PAU1_TYPE :
            *o_chipletData = (ChipletData_t*)&PAU1::g_chipletData;
            break;

        case PAU2_TYPE :
            *o_chipletData = (ChipletData_t*)&PAU2::g_chipletData;
            break;

        case PAU3_TYPE :
            *o_chipletData = (ChipletData_t*)&PAU3::g_chipletData;
            break;

        case AXON0_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON0::g_chipletData;
            break;

        case AXON1_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON1::g_chipletData;
            break;

        case AXON2_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON2::g_chipletData;
            break;

        case AXON3_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON3::g_chipletData;
            break;

        case AXON4_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON4::g_chipletData;
            break;

        case AXON5_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON5::g_chipletData;
            break;

        case AXON6_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON6::g_chipletData;
            break;

        case AXON7_TYPE :
            *o_chipletData = (ChipletData_t*)&AXON7::g_chipletData;
            break;

        case EQ_TYPE :
            *o_chipletData = (ChipletData_t*)&EQ::g_chipletData;
            break;

        default :
            return TOR_INVALID_CHIPLET_TYPE;
    }

    return INFRASTRUCT_RC_SUCCESS;
}
