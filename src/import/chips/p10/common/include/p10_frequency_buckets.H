/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_frequency_buckets.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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


//
// REFCLOCKS
//

// internal/external reference clock frequencies
// values represented in KHz
enum p10_refclock_freq_t
{
    REFCLOCK_FREQ_100 = 100000,
    REFCLOCK_FREQ_133 = 133333,
    REFCLOCK_FREQ_156 = 156250,
};


//
// PCI
//

// constants defining number of PCI PLL frequency options ('buckets')
// documented in bucket descriptor structure (currently used/max)
const uint8_t P10_NUM_PCI_PLL_BUCKETS = 1;
const uint8_t P10_MAX_PCI_PLL_BUCKETS = 4;

// PCI PLL bucket descriptor, defines bucket properties in terms of:
// - required input reference clock freqeuncy (KHz)
// - resultant output grid frequency (MHz)
struct p10_pci_pll_bucket_descriptor_t
{
    p10_refclock_freq_t refclock_freq_khz;  // PLL input frequency (KHz)
    uint32_t            freq_grid_mhz;      // PCI chiplet grid frequency (MHz)  ATTR_FREQ_PCIE_MHZ
};

const p10_pci_pll_bucket_descriptor_t P10_PCI_PLL_BUCKETS[P10_NUM_PCI_PLL_BUCKETS] =
{
    { REFCLOCK_FREQ_100, 2000 }, // bucket 0
};


//
// filter PLLs
//

// constant defining number of filter PLL frequency options ('buckets')
// to be built into unsigned HW image (currently used/max)
const uint8_t P10_NUM_FILTER_PLL_BUCKETS = 1;
const uint8_t P10_MAX_FILTER_PLL_BUCKETS = 4;


//
// MC
//

// constants defining number of MC PLL frequency options ('buckets')
// documented in bucket descriptor structure (currently used/max)
const uint8_t P10_NUM_MC_PLL_BUCKETS = 4;
const uint8_t P10_MAX_MC_PLL_BUCKETS = 8;

// MC PLL bucket descriptor, defines bucket properties in terms of:
// - required input reference clock freqeuncy (KHz)
// - resultant output grid frequency (MHz)
// - resultant output link frequency (MHz)
struct p10_mc_pll_bucket_descriptor_t
{
    p10_refclock_freq_t refclock_freq_khz;  // PLL input frequency (KHz)
    uint32_t            freq_grid_mhz;      // MC chiplet grid frequency (MHz)   ATTR_FREQ_MC_MHZ
    uint32_t            freq_link_mhz;      // OMI link frequency (MHz)          ATTR_FREQ_OMI_MHZ
};

// array of bucket descriptors, index is bucket number
const p10_mc_pll_bucket_descriptor_t P10_MC_PLL_BUCKETS[P10_NUM_MC_PLL_BUCKETS] =
{
    { REFCLOCK_FREQ_133, 1600, 25600 }, // bucket 0 DDR4-3200
    { REFCLOCK_FREQ_133, 1466, 23460 }, // bucket 1 DDR4-2933
    { REFCLOCK_FREQ_133, 1333, 21330 }, // bucket 2 DDR4-2667
    { REFCLOCK_FREQ_133, 2000, 32000 }  // bucket 3 DDR5
};


//
// IOHS
//

// constants definining number of IOHS PLL frequency options ('buckets')
// documented in bucket descriptor structure (currently used/max)
const uint8_t P10_NUM_IOHS_PLL_BUCKETS = 6;
const uint8_t P10_MAX_IOHS_PLL_BUCKETS = 16;

// IOHS PLL bucket descriptor, defines bucket properties in terms of:
// - required input reference clock frequency (KHz)
// - resultant output grid frequency (MHz)
// - resultant output link frequency (MHz)
struct p10_iohs_pll_bucket_descriptor_t
{
    p10_refclock_freq_t  refclock_freq_khz;  // PLL input frequency (KHz)
    uint32_t             freq_grid_mhz;      // IOHS chiplet grid frequency (MHz)  ATTR_FREQ_IOHS_MHZ
    uint32_t             freq_link_mhz;      // IOHS link frequency (MHz)          ATTR_FREQ_IOHS_LINK_MHZ
};

// array of bucket descriptors, index is bucket number
const p10_iohs_pll_bucket_descriptor_t P10_IOHS_PLL_BUCKETS[P10_NUM_IOHS_PLL_BUCKETS] =
{
    { REFCLOCK_FREQ_156, 2031, 32500 }, // bucket 0
    { REFCLOCK_FREQ_156, 1611, 25781 }, // bucket 1
    { REFCLOCK_FREQ_156, 1992, 31875 }, // bucket 2
    { REFCLOCK_FREQ_133, 2000, 32000 }, // bucket 3
    { REFCLOCK_FREQ_156, 2109, 33750 }, // bucket 4
    { REFCLOCK_FREQ_133, 2067, 33067 }, // bucket 5
};


#endif // _P10_FREQUENCY_BUCKETS_H_
