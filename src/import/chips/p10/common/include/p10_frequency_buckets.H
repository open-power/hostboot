/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_frequency_buckets.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef _P10_FREQUENCY_BUCKETS_H_
#define _P10_FREQUENCY_BUCKETS_H_

// constant defining number of MEM PLL frequency options ('buckets')
// to be built into unsigned HW image
const uint8_t MEM_PLL_FREQ_BUCKETS = 4;

// MEM PLL frequency in MHz
// index is bucket number
const uint32_t MEM_PLL_FREQ_LIST[MEM_PLL_FREQ_BUCKETS] =
{
    1333,
    1466,
    1600,
    2000,
};

// constant definining number of IOHS PLL frequency options ('buckets')
// to be built into unsigned HW image
const uint8_t IOHS_PLL_FREQ_BUCKETS = 8;

// IOHS PLL frequency in MHz
// index is bucket number
const uint32_t IOHS_PLL_FREQ_LIST[IOHS_PLL_FREQ_BUCKETS] =
{
    1250,
    1563,
    1611,
    1992,
    2000,
    2067,
    2070,
    0
};

// OMI bucket descriptor
struct OmiBucketDescriptor_t
{
    uint32_t omifreq; // OMI Frequency in MHz
    uint32_t vco;     // VCO selector

    uint32_t mcafreq; // MCA Frequency in MHz
};

//MC PLL frequency in MHz for Axone
// index is bucket number
// OMI -> ATTR_FREQ_OMI_MHZ
// VCO -> ATTR_OMI_PLL_VCO
// MCA -> ATTR_FREQ_MCA_MHZ
const OmiBucketDescriptor_t OMI_PLL_FREQ_LIST[MEM_PLL_FREQ_BUCKETS] =
{
    //  OMI    VCO   MCA          Data rate
    { 21330,   0,    1333 }, // ->DDR4-2667
    { 23460,   0,    1466 }, // ->DDR4-2933
    { 23460,   1,    1466 }, // ->DDR4-2933
    { 25600,   1,    1600 }  // ->DDR4-3200
};

#endif // _P10_FREQUENCY_BUCKETS_H_
