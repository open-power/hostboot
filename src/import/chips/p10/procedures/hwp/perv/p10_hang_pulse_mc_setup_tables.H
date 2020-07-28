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

/*
 * We're making all these tables "static const" since they're being used
 * in one place only each, and we trust the compiler to leave them out
 * of a module if they're not used.
 */

#include <multicast_group_defs.H>

static const hang_pulse_t SETUP_HANG_COUNTERS_PERV[] =
{
    {0, 16, 0},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_N0[] =
{
    {0, 16, 0},
    {1, 24, 1},
    {3, 15, 1},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_N1[] =
{
    {0, 16, 0},
    {1, 22, 1},
    {2, 16, 1},
    {3, 20, 1},
    {4, 17, 1},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_PCI[] =
{
    {0, 16, 0},
    {1, 43, 0},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_MC[] =
{
    {0, 16, 0},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_IOHS[] =
{
    {0, 16, 0},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_PAU[] =
{
    {0, 16, 0},
    {1, 3, 0},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const hang_pulse_t SETUP_HANG_COUNTERS_EQ[] =
{
    {0, 16, 0},
    {1, 21, 1},
    {5, 6, 0},
    {6, 7, 0, 1}
};

static const mc_setup_t ISTEP3_MC_GROUPS[] =
{
    { fapi2::MCGROUP_GOOD,       MC_GROUP_0, HONOR_PGOOD,           0, 0x7FFFFFFFFFFFFFFF },
    { fapi2::MCGROUP_GOOD_NO_TP, MC_GROUP_1, HONOR_PGOOD_FORCE_EQ,  0, 0x3FFFFFFFFFFFFFFF },
    { fapi2::MCGROUP_GOOD_MC,    MC_GROUP_2, HONOR_PGOOD,           0, 0x000F000000000000 },
    { fapi2::MCGROUP_GOOD_IOHS,  MC_GROUP_3, HONOR_PGOOD,           0, 0x000000FF00000000 },
    { fapi2::MCGROUP_GOOD_PAU,   MC_GROUP_4, HONOR_PGOOD,           0, 0x0000F00000000000 },
    { fapi2::MCGROUP_GOOD_PCI,   MC_GROUP_5, HONOR_PGOOD,           0, 0x00C0000000000000 },
    { fapi2::MCGROUP_ALL_EQ,     MC_GROUP_6, HONOR_PGOOD,           1, 0x00000000FF000000 },
};

static const mc_setup_t SELECT_EX_MC_GROUPS[] =
{
    { fapi2::MCGROUP_GOOD,       MC_GROUP_0, HONOR_PGOOD,           0, 0x7FFFFFFFFFFFFFFF },
    { fapi2::MCGROUP_GOOD_NO_TP, MC_GROUP_1, HONOR_PGOOD,           0, 0x3FFFFFFFFFFFFFFF },
    { fapi2::MCGROUP_GOOD_MC,    MC_GROUP_2, HONOR_PGOOD,           0, 0x000F000000000000 },
    { fapi2::MCGROUP_GOOD_IOHS,  MC_GROUP_3, HONOR_PGOOD,           0, 0x000000FF00000000 },
    { fapi2::MCGROUP_GOOD_PAU,   MC_GROUP_4, HONOR_PGOOD,           0, 0x0000F00000000000 },
    { fapi2::MCGROUP_GOOD_PCI,   MC_GROUP_5, HONOR_PGOOD,           0, 0x00C0000000000000 },
    { fapi2::MCGROUP_GOOD_EQ,    MC_GROUP_6, HONOR_CORE_PGOOD_ATTR, 1, 0x00000000FF000000 },
};

static const mc_setup_t ISTEP4_MC_GROUPS[] =
{
    { fapi2::MCGROUP_GOOD,       MC_GROUP_0, HONOR_PGOOD,           0, 0x7FFFFFFFFFFFFFFF },
    { fapi2::MCGROUP_GOOD_NO_TP, MC_GROUP_1, HONOR_PGOOD,           0, 0x3FFFFFFFFFFFFFFF },
    { fapi2::MCGROUP_GOOD_MC,    MC_GROUP_2, HONOR_PGOOD,           0, 0x000F000000000000 },
    { fapi2::MCGROUP_GOOD_IOHS,  MC_GROUP_3, HONOR_PGOOD,           0, 0x000000FF00000000 },
    { fapi2::MCGROUP_GOOD_PAU,   MC_GROUP_4, HONOR_PGOOD,           0, 0x0000F00000000000 },
    { fapi2::MCGROUP_GOOD_PCI,   MC_GROUP_5, HONOR_PGOOD,           0, 0x00C0000000000000 },
    { fapi2::MCGROUP_GOOD_EQ,    MC_GROUP_6, HONOR_CORE_PGOOD_REG,  1, 0x00000000FF000000 },
};
