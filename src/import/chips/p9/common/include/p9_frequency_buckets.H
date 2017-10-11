/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9_frequency_buckets.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

// constant defining number of NEST PLL frequency options ('buckets')
// to be built into unsigned HW image
const uint8_t NEST_PLL_FREQ_BUCKETS = 5;

// Nest PLL frequency in MHZ
// index is bucket number
const uint32_t NEST_PLL_FREQ_LIST[NEST_PLL_FREQ_BUCKETS] =
{
    1600,
    1866,
    2000,
    2133,
    2400
};

// I2C bus divisor
// index is bucket number
// The values in this list will be factor of 1:64 to the NEST_PLL_FREQ_LIST
const uint32_t NEST_PLL_FREQ_I2CDIV_LIST[NEST_PLL_FREQ_BUCKETS] =
{
    25,
    29,
    31,
    33,
    37
};

// constant defining number of MEM PLL frequency options ('buckets')
// to be built into unsigned HW image
const uint8_t MEM_PLL_FREQ_BUCKETS = 5;

// MEM PLL frequency in MHz
// index is bucket number
const uint32_t MEM_PLL_FREQ_LIST[MEM_PLL_FREQ_BUCKETS] =
{
    1866,
    2133,
    2400,
    2666,
    2666
};

// constant definining number of OBUS PLL frequency options ('buckets')
// to be built into unsigned HW image
const uint8_t OBUS_PLL_FREQ_BUCKETS = 3;

// OBUS PLL frequency in MHz
// index is bucket number
const uint32_t OBUS_PLL_FREQ_LIST_P9N_10[OBUS_PLL_FREQ_BUCKETS] =
{
    1250,
    1250,
    1611
};

const uint32_t OBUS_PLL_FREQ_LIST_P9N_20[OBUS_PLL_FREQ_BUCKETS] =
{
    1563,
    1250,
    1611
};

const uint32_t OBUS_PLL_FREQ_LIST_P9N_21[OBUS_PLL_FREQ_BUCKETS] =
{
    1563,
    1250,
    1611
};

const uint32_t OBUS_PLL_FREQ_LIST_P9N_22[OBUS_PLL_FREQ_BUCKETS] =
{
    1563,
    1250,
    1611
};

const uint32_t OBUS_PLL_FREQ_LIST_P9C_10[OBUS_PLL_FREQ_BUCKETS] =
{
    1601,
    1250,
    1611
};

const uint32_t OBUS_PLL_FREQ_LIST_P9A_10[OBUS_PLL_FREQ_BUCKETS] =
{
    1611,
    1250,
    1611
};
