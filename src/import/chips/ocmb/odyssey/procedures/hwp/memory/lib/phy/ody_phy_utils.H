/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_phy_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_phy_utils.H
/// @brief Odyssey PHY utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _ODY_PHY_UTILS_H_
#define _ODY_PHY_UTILS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/phy/ody_phy_access.H>
#include <lib/shared/ody_consts.H>
#include <ody_scom_mp_dbyte0_b0.H>
#include <ody_scom_mp_dbyte1_b0.H>
#include <ody_scom_mp_dbyte2_b0.H>
#include <ody_scom_mp_dbyte3_b0.H>
#include <ody_scom_mp_dbyte4_b0.H>
#include <ody_scom_mp_dbyte5_b0.H>
#include <ody_scom_mp_dbyte6_b0.H>
#include <ody_scom_mp_dbyte7_b0.H>
#include <ody_scom_mp_dbyte8_b0.H>
#include <ody_scom_mp_dbyte9_b0.H>


namespace mss
{
namespace ody
{
namespace phy
{

// @brief Odyssey per-bit swizzle registers, ordered in the PHY rank and byte perspective
constexpr const uint64_t PER_BIT_SWIZZLE_REGS[MAX_RANK_PER_PHY][MAX_BYTES_PER_PORT][BITS_PER_BYTE] =
{
    // Rank0
    {
        // DByte 0
        {
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ7LNSELTG0,
        },
        // DByte 1
        {
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ7LNSELTG0,
        },
        // DByte 2
        {
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ7LNSELTG0,
        },
        // DByte 3
        {
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ7LNSELTG0,
        },
        // DByte 4
        {
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ7LNSELTG0,
        },
        // DByte 5
        {
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ7LNSELTG0,
        },
        // DByte 6
        {
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ7LNSELTG0,
        },
        // DByte 7
        {
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ7LNSELTG0,
        },
        // DByte 8
        {
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ7LNSELTG0,
        },
        // DByte 9
        {
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ0LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ1LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ2LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ3LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ4LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ5LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ6LNSELTG0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ7LNSELTG0,
        },
    },
    // Rank1
    {
        // DByte 0
        {
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ7LNSELTG1,
        },
        // DByte 1
        {
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ7LNSELTG1,
        },
        // DByte 2
        {
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ7LNSELTG1,
        },
        // DByte 3
        {
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ7LNSELTG1,
        },
        // DByte 4
        {
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ7LNSELTG1,
        },
        // DByte 5
        {
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ7LNSELTG1,
        },
        // DByte 6
        {
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ7LNSELTG1,
        },
        // DByte 7
        {
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ7LNSELTG1,
        },
        // DByte 8
        {
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ7LNSELTG1,
        },
        // DByte 9
        {
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ0LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ1LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ2LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ3LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ4LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ5LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ6LNSELTG1,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ7LNSELTG1,
        },
    },
    // Rank2
    {
        // DByte 0
        {
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ7LNSELTG2,
        },
        // DByte 1
        {
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ7LNSELTG2,
        },
        // DByte 2
        {
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ7LNSELTG2,
        },
        // DByte 3
        {
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ7LNSELTG2,
        },
        // DByte 4
        {
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ7LNSELTG2,
        },
        // DByte 5
        {
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ7LNSELTG2,
        },
        // DByte 6
        {
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ7LNSELTG2,
        },
        // DByte 7
        {
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ7LNSELTG2,
        },
        // DByte 8
        {
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ7LNSELTG2,
        },
        // DByte 9
        {
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ0LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ1LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ2LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ3LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ4LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ5LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ6LNSELTG2,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ7LNSELTG2,
        },
    },
    // Rank3
    {
        // DByte 0
        {
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ7LNSELTG3,
        },
        // DByte 1
        {
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_DQ7LNSELTG3,
        },
        // DByte 2
        {
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_DQ7LNSELTG3,
        },
        // DByte 3
        {
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_DQ7LNSELTG3,
        },
        // DByte 4
        {
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_DQ7LNSELTG3,
        },
        // DByte 5
        {
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_DQ7LNSELTG3,
        },
        // DByte 6
        {
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_DQ7LNSELTG3,
        },
        // DByte 7
        {
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_DQ7LNSELTG3,
        },
        // DByte 8
        {
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_DQ7LNSELTG3,
        },
        // DByte 9
        {
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ0LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ1LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ2LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ3LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ4LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ5LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ6LNSELTG3,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_DQ7LNSELTG3,
        },
    }
};

///
/// @brief Loads two contiguous 8-bit fields into the DMEM register format
/// @param[in] i_even_field field at the even byte offset
/// @param[in] i_odd_field field at the odd byte offset
/// @param[in,out] io_data the register data
///
void load_dmem_8bit_fields( const uint8_t i_even_field, const uint8_t i_odd_field, fapi2::buffer<uint64_t>& io_data);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_even_field field at the even byte offset
/// @param[out] o_odd_field field at the odd byte offset
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint8_t& o_even_field, uint8_t& o_odd_field);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 16-bit field
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint16_t& o_field);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 32-bit field, read in from two registers
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint32_t& o_field);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 64-bit field, read in from four registers
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint64_t& o_field);

///
/// @brief A helper to check if loads to two IMEM/DMEM fields are needed
/// @param[in] i_attr the attribute value dictating if this is the first load or not
/// @param[in] i_data_even even address data
/// @param[in] i_data_odd odd address data
/// @return true if the data should be loaded, otherwise false
/// @note the IMEM/DMEM should be guaranteed to be initialized to zeroes
/// As such, we can gain performance benefits by only loading non-zero data on the first load
/// the data for these addresses will be loaded if:
/// 1. this is not the first time the IMEM/DMEM have been loaded this boot
/// 2. this is the first IMEM/DMEM load and the data for one of the addresses is non-zero
///
bool phy_mem_load_helper( const uint8_t i_attr,
                          const uint64_t i_data_even,
                          const uint64_t i_data_odd);

///
/// @brief A helper to load two IMEM/DMEM fields only if needed
/// @param[in] i_target the target on which to operate
/// @param[in] i_attr the attribute value dictating if this is the first load or not
/// @param[in] i_addr the starting address to write to - must be the even address
/// @param[in] i_data_even even address data
/// @param[in] i_data_odd odd address data
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note the IMEM/DMEM should be guaranteed to be initialized to zeroes
/// As such, we can gain performance benefits by only loading non-zero data on the first load
/// the data for these addresses will be loaded if:
/// 1. this is not the first time the IMEM/DMEM have been loaded this boot
/// 2. this is the first IMEM/DMEM load and the data for one of the addresses is non-zero
///
fapi2::ReturnCode phy_mem_load_helper( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       const uint8_t i_attr,
                                       const uint64_t i_addr,
                                       const uint64_t i_data_even,
                                       const uint64_t i_data_odd);

///
/// @brief Resets the DMEM values to all 0's
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode reset_dmem( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief fapi2::putScom wrapper to help decrease code size on the SBE using the Synopsys address perspective
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the address on which to operate from the synopsys perspective
/// @param[in] i_data the data to write to the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode putScom_synopsys_addr_wrapper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint32_t i_addr,
        const fapi2::buffer<uint64_t>& i_data);

///
/// @brief fapi2::getScom wrapper to help decrease code size on the SBE using the Synopsys address perspective
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the address on which to operate from the synopsys perspective
/// @param[out] o_data the data read from the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode getScom_synopsys_addr_wrapper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint32_t i_addr,
        fapi2::buffer<uint64_t>& o_data);

///
/// @brief Swizzle a byte of DQ disables from PHY to MC perspective using per-bit swizzle registers
/// @param[in] i_target the target on which to operate
/// @param[in] i_phy_rank the rank for the disables in question, in the PHY perspective
/// @param[in] i_dbyte the DByte for the disables in question
/// @param[in] i_disables_phy the lane disable data in PHY perspecitve
/// @param[out] o_disables_mc the lane disable data swizzled to MC perspective
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode swizzle_bad_bits_phy_to_mc(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_phy_rank,
        const uint8_t i_dbyte,
        const uint8_t i_disables_phy,
        uint8_t& o_disables_mc);

} // namespace phy
} // namespace ody
} // namespace mss
#endif
