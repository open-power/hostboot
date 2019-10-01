/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ringId.H $          */
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

#ifndef _P10_RINGID_H_
#define _P10_RINGID_H_

#ifdef WIN32
    #include "win32_stdint.h"
#else
    #include <stdint.h>
    #include <stddef.h>
#endif
#include <p10_ring_id.H>
#include <common_ringId.H>


enum Chiplets
{
    PERV_TYPE,
    N0_TYPE,
    N1_TYPE,
    PCI_TYPE,
    MC_TYPE,
    PAU0_TYPE,
    PAU1_TYPE,
    PAU2_TYPE,
    PAU3_TYPE,
    AXON0_TYPE,
    AXON1_TYPE,
    AXON2_TYPE,
    AXON3_TYPE,
    AXON4_TYPE,
    AXON5_TYPE,
    AXON6_TYPE,
    AXON7_TYPE,
    EQ_TYPE,
    SBE_NUM_CHIPLETS
};

const ChipletType_t QME_NUM_CHIPLETS = 1;


#include "p10_ring_properties.H"

static inline const char* ringid_get_ring_name(RingID i_id)
{
#ifdef __PPE__
    return "";
#else
    return (i_id < NUM_RING_IDS) ? RING_PROPERTIES[i_id].ringName : "INVALID RING ID";
#endif
}

// Returns data structure assocated with chipletType
int
ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData);


#endif
