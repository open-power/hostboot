/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_hang_pulse_mc_setup_tables.H $ */
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


uint8_t SETUP_HANG_COUNTERS_PERV[][3] =
{
    {0, 16, 0},
    {1, 4, 0},
    {2, 18, 0},
    {3, 1, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_PULSE_FREQ[][3] =
{
    {0, 1, 0},
    {1, 31, 0}
};

uint8_t SETUP_HANG_COUNTERS_N0[][3] =
{
    {0, 16, 0},
    {1, 24, 0},
    {2, 34, 0},
    {3, 15, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_COUNTERS_N1[][3] =
{
    {0, 16, 0},
    {1, 23, 0},
    {2, 15, 0},
    {3, 19, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_COUNTERS_PCI[][3] =
{
    {0, 16, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_COUNTERS_MC[][3] =
{
    {0, 16, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_COUNTERS_IOHS[][3] =
{
    {0, 16, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_COUNTERS_PAU[][3] =
{
    {0, 16, 0},
    {1, 4, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint8_t SETUP_HANG_COUNTERS_EQ[][3] =
{
    {0, 16, 0},
    {1, 23, 0},
    {5, 6, 0},
    {6, 8, 0}
};

uint64_t ignore_pgood = 0x0;
uint64_t honor_pgood = 0x1;
uint64_t honor_core_pgood = 0x2;

uint64_t mc_group_1 = 0x1;
uint64_t mc_group_2 = 0x2;
uint64_t mc_group_3 = 0x3;
uint64_t mc_group_4 = 0x4;
uint64_t mc_group_5 = 0x5;
uint64_t mc_group_6 = 0x6;

uint64_t MC_GROUPS[][3] =
{
    { mc_group_1, 0x3FFFFFFFFFFFFFFF, honor_pgood },
    { mc_group_2, 0x000F000000000000, honor_pgood },
    { mc_group_3, 0x000000FF00000000, honor_pgood },
    { mc_group_4, 0x0000F00000000000, honor_pgood },
    { mc_group_5, 0x00C0000000000000, honor_pgood },
    { mc_group_6, 0x00000000FF000000, honor_core_pgood }
};
