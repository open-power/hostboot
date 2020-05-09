/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_3.H $       */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_nmmu_3_H_
#define __p10_scom_nmmu_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> [NMMU_PMU0_CNT_REG]
static const uint64_t NMMU_PMU0_CNT_REG = 0x02010c4full;

static const uint32_t NMMU_PMU0_CNT_REG_MM_PMU0_CNT = 0;
static const uint32_t NMMU_PMU0_CNT_REG_MM_PMU0_CNT_LEN = 64;
//<< [NMMU_PMU0_CNT_REG]
// nmmu/reg00003.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "nmmu/reg00003.H"
#endif
#endif
