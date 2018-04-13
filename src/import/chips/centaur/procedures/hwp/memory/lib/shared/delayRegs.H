/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/lib/shared/delayRegs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
///
/// @file delayRegs.H
/// @brief Const arrays for delay registers, indexed by port, rank, dp18 block
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
//
#ifndef DELAYREGS_H_
#define DELAYREGS_H_

constexpr uint64_t const l_disable_reg[MAX_PORTS_PER_MBA][NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK] =
{
    /* port 0 */
    {
        // primary rank pair 0
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_4
        },
        // primary rank pair 1
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P0_4
        },
        // primary rank pair 2
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P0_4
        },
        // primary rank pair 3
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P0_4
        }
    },
    /* port 1 */
    {
        // primary rank pair 0
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P1_4
        },
        // primary rank p1
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP1_P1_4
        },
        // primary rank pair 2
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP2_P1_4
        },
        // primary rank pair 3
        {
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_0,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_1,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_2,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_3,
            CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP3_P1_4
        }
    }
};

constexpr uint64_t const l_dqs_gate_delay[MAX_PORTS_PER_MBA][NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK] =
{
    /* port 0 */
    {
        // primary rank pair 0
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_4
        },
        // primary rank pair 1
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P0_4
        },
        // primary rank pair 2
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P0_4
        },
        // primary rank pair 3
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P0_4
        }
    },
    /* port 1 */
    {
        // primary rank pair 0
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P1_4
        },
        // primary rank p1
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP1_P1_4
        },
        // primary rank pair 2
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP2_P1_4
        },
        // primary rank pair 3
        {
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP3_P1_4
        }
    }
};

constexpr uint64_t const l_dqs_rd_phase_select[MAX_PORTS_PER_MBA][NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK] =
{
    /* port 0 */
    {
        // primary rank pair 0
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4
        },
        // primary rank pair 1
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4
        },
        // primary rank pair 2
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4
        },
        // primary rank pair 3
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_4
        }
    },
    /* port 1 */
    {
        // primary rank pair 0
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P1_4
        },
        // primary rank p1
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR1_P1_4
        },
        // primary rank pair 2
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR2_P1_4
        },
        // primary rank pair 3
        {
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_0,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_1,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_2,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_3,
            CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR3_P1_4
        }
    }
};

#endif
