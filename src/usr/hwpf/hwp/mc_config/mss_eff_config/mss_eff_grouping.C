/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: mss_eff_grouping.C,v 1.34 2014/09/29 16:25:38 gpaulraj Exp $
// Mike Jones - modified version from 1.28 to 1.00 because it is a sandbox version
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_grouping.C
// *! DESCRIPTION : see additional comments below
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
//Owner :- Girisankar paulraj
//Back-up owner :- Mark bellows
//
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.34   |gpaulraj  | 09-23-14| fixed last check in issue
//  1.33   |gpaulraj  | 09-23-14| fixed 2 MCS/group issue on starting with odd MCS grouping
//  1.32   |gpaulraj  | 06-26-14| support MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER for Brazos
//  1.31   | thi      | 05-23-14| Support MEM_MIRROR_PLACEMENT_POLICY_DRAWER for Brazos
//  1.30   | jdsloat  | 04-10-14| Mike Jones's rewrite.
//  1.29   | gpaulraj | 04-20-14| Updated Dimm call out/FW defect/Mike's Feedback
//  1.28   | gpaulraj | 11-21-13| modified 8MCS/group id as per spec
//  1.27   | gpaulraj | 08-13-13| Fixed alternate BAR settings for Mirror
//  1.26   | gpaulraj | 08-12-13| added mirror policy and HTM/OCC Bar setup
//  1.25   | gpaulraj | 05-23-13| Fixed FW review feedback
//  1.24   | bellows  | 04-09-13| Updates that really allow checkboard and all group sizes.  Before, group size of 1 was all that was possible
//  1.23   | bellows  | 03-26-13| Allow for checkboard mode with more than one mcs per group
//  1.22   | bellows  | 03-21-13| Error Logging support
//  1.21   | bellows  | 03-11-13| Fixed syntax error with respect to the fapi macro under cronus
//  1.20   | bellows  | 03-08-13| Proper way to deconfigure mulitple/variable MCS
//  1.19   | bellows  | 02-27-13| Added back in mirror overlap check.  Added in error rc for grouping
//  1.18   | asaetow  | 02-01-13| Removed FAPI_ERR("Mirror Base address overlaps with memory base address. "); temporarily.
//         |          |         | NOTE: Need Giri to check mirroring enable before checking for overlaps.
//  1.17   | gpaulraj | 01-31-13| Error place holders added
//  1.16   | gpaulraj | 12-14-12| Modified "nnable to group dimm size" as Error message
//  1.15   | bellows  | 12-11-12| Picked up latest updates from Girisankar
//  1.14   | bellows  | 12-11-12| added ; to DBG line
//  1.13   | bellows  | 12-07-12| fix for interleaving attr and array bounds
//  1.11   | bellows  | 11-27-12| review updates
//  1.10   | bellows  | 09-27-12| Additional Review Updates
//  1.9    | bellows  | 09-25-12| updates from review, code from Girisankar
//  1.8    | bellows  | 09-06-12| updates suggested by Van
//  1.7    | bellows  | 08-31-12| updates from Girisankar: C++ Object. Also use 32 bit Attribute
//  1.6    | bellows  | 08-29-12| expanded group id temporaily to 32 bits, fixed compiler warnings
//         |          |         | Read old 8bit attr, and move to 32
//         |          |         | Removed read of attr that has not been written
//  1.2    | bellows  | 07-16-12| bellows | added in Id tag
//  1.1    | gpaulraj | 03-19-12| First drop for centaur

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <fapi.H>
#include <mss_eff_grouping.H>
#include <cen_scom_addresses.H>
#include <mss_error_support.H>

extern "C"
{

// Used for decoding ATTR_MSS_INTERLEAVE_ENABLE (iv_groupsAllowed)
const uint8_t MCS_GROUP_8 = 0x8;
const uint8_t MCS_GROUP_4 = 0x4;
const uint8_t MCS_GROUP_2 = 0x2;
const uint8_t MCS_GROUP_1 = 0x1;

// MCS positions
const uint8_t MCSID_0 = 0x0;
const uint8_t MCSID_1 = 0x1;
const uint8_t MCSID_2 = 0x2;
const uint8_t MCSID_3 = 0x3;
const uint8_t MCSID_4 = 0x4;
const uint8_t MCSID_5 = 0x5;
const uint8_t MCSID_6 = 0x6;
const uint8_t MCSID_7 = 0x7;

// System structure
const uint8_t NUM_MBA_PORTS = 2;
const uint8_t NUM_MBA_DIMMS = 2; // DIMMs per port
const uint8_t NUM_MBA_PER_MCS = 2;
const uint8_t NUM_MCS_PER_PROC = 8;

// Constants used for EffGroupingData
const uint8_t DATA_GROUPS = 16;   // 8 regular groups, 8 mirrored groups
const uint8_t MIRR_OFFSET = 8;  // Start of mirrored offset in DATA_GROUPS
const uint8_t DATA_ELEMENTS = 16; // 16 items of data for each group

// Indexes used for EffGroupingData::iv_data DATA ELEMENTS
const uint8_t MCS_SIZE = 0;           // Memory Size of each MCS in group (GB)
const uint8_t MCS_IN_GROUP = 1;       // Number of MCSs in group
const uint8_t GROUP_SIZE = 2;         // Memory Size of entire group (GB)
const uint8_t BASE_ADDR = 3;          // Base Address
#define MEMBER_IDX(X) ((X) + 4)       // List of MCSs in group
const uint8_t ALT_VALID = 12;         // Alt Memory Valid
const uint8_t ALT_SIZE = 13;          // Alt Memory Size
const uint8_t ALT_BASE_ADDR = 14;     // Alt Base Address
const uint8_t LARGEST_MBA_SIZE = 15;  // Largest MBA size

/**
 * @struct EffGroupingData
 *
 * Contains Effective Grouping Data for a processor chip
 */
struct EffGroupingData
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    EffGroupingData();

    // The ATTR_MSS_MCS_GROUP_32 attribute
    uint32_t iv_data[DATA_GROUPS][DATA_ELEMENTS];

    // The MCSs that have been grouped
    bool iv_mcsGrouped[NUM_MCS_PER_PROC];

    // The number of groups
    uint8_t iv_numGroups;

    // The total non-mirrored memory size in GB
    uint32_t iv_totalSizeNonMirr;
};

/**
 * @struct EffGroupingMemInfo
 *
 * Contains Memory Information for a processor chip
 */
struct EffGroupingMemInfo
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    EffGroupingMemInfo();

    /**
     * @brief Gets the memory information
     *
     * @param[in]  i_assocCentaurs Reference to vector of Centaur Chips
     *                             associated with the Proc Chip
     * @return fapi::ReturnCode
     */
    fapi::ReturnCode getMemInfo(
        const std::vector<fapi::Target> & i_assocCentaurs);

    // MCS memory sizes
    uint32_t iv_mcsSize[NUM_MCS_PER_PROC];

    // MBA memory sizes
    uint32_t iv_mbaSize[NUM_MCS_PER_PROC][NUM_MBA_PER_MCS];

    // Largest MBA memory sizes
    uint32_t iv_largestMbaSize[NUM_MCS_PER_PROC];

    // Membuf chip associated with each MCS (for deconfiguring if cannot group)
    fapi::Target iv_membufs[NUM_MCS_PER_PROC];
};

/**
 * @struct EffGroupingSysAttrs
 *
 * Contains system attributes
 */
struct EffGroupingSysAttrs
{
    /**
     * @brief Default Constructor. Initializes attributes
     */
    EffGroupingSysAttrs() : iv_mcsInterleaveMode(0),
                            iv_selectiveMode(0),
                            iv_enhancedNoMirrorMode(0) {}
    /**
     * @brief Gets attributes
     */
    fapi::ReturnCode getAttrs();

    // Public data
    uint8_t iv_mcsInterleaveMode;    // ATTR_ALL_MCS_IN_INTERLEAVING_GROUP
    uint8_t iv_selectiveMode;        // ATTR_MEM_MIRROR_PLACEMENT_POLICY
    uint8_t iv_enhancedNoMirrorMode; // ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING
};

/**
 * @struct EffGroupingProcAttrs
 *
 * Contains attributes for a Processor Chip
 */
struct EffGroupingProcAttrs
{
    /**
     * @brief Default Constructor. Initializes attributes
     */
    EffGroupingProcAttrs() : iv_groupsAllowed(0),
                             iv_memBaseAddr(0),
                             iv_mirrorBaseAddr(0),
                             iv_htmBarSize(0),
                             iv_occSandboxSize(0) {}
    /**
     * @brief Gets attributes
     *
     * @param[in] i_proc Reference to Processor Chip Target
     */
    fapi::ReturnCode getAttrs(const fapi::Target & i_proc);

    // Public data
    uint8_t  iv_groupsAllowed;  // ATTR_MSS_INTERLEAVE_ENABLE
    uint64_t iv_memBaseAddr;    // ATTR_PROC_MEM_BASE >> 30
    uint64_t iv_mirrorBaseAddr; // ATTR_PROC_MIRROR_BASE >> 30
    uint64_t iv_htmBarSize;     // ATTR_PROC_HTM_BAR_SIZE
    uint64_t iv_occSandboxSize; // ATTR_PROC_OCC_SANDBOX_SIZE
};

/**
 * @struct EffGroupingMembufAttrs
 *
 * Contains attributes for a Membuf Chip
 */
struct EffGroupingMembufAttrs
{
    /**
     * @brief Default Constructor. Initializes attributes
     *
     * @param[in] i_procTarget Reference to Processor Chip Target
     */
    EffGroupingMembufAttrs() : iv_pos(0), iv_mcsPos(0) {}

    /**
     * @brief Gets attributes
     *
     * @param[in] i_membuf Reference to membuf Chip Target
     */
    fapi::ReturnCode getAttrs(const fapi::Target & i_membuf);

    uint32_t iv_pos;    // ATTR_POS (Position)
    uint32_t iv_mcsPos; // Associated MCS unit position derived from iv_pos)
};

/**
 * @struct EffGroupingMbaAttrs
 *
 * Contains attributes for an MBA Chiplet
 */
struct EffGroupingMbaAttrs
{
    /**
     * @brief Default Constructor. Initializes attributes
     *
     * @param[in] i_procTarget Reference to Processor Chip Target
     */
    EffGroupingMbaAttrs();

    /**
     * @brief Gets attributes
     *
     * @param[in] i_mba Reference to MBA chiplet Target
     */
    fapi::ReturnCode getAttrs(const fapi::Target & i_mba);

    // Unit Position (ATTR_CHIP_UNIT_POS)
    uint8_t iv_unitPos;

    // Dimm Size (ATTR_EFF_DIMM_SIZE)
    uint8_t iv_effDimmSize[NUM_MBA_PORTS][NUM_MBA_DIMMS];
};

//------------------------------------------------------------------------------
EffGroupingData::EffGroupingData() : iv_numGroups(0), iv_totalSizeNonMirr(0)
{
    // Initialize all instance variables to zero
    for (uint32_t i = 0; i < DATA_GROUPS; i++)
    {
        for (uint32_t j = 0; j < DATA_ELEMENTS; j++)
        {
            iv_data[i][j] = 0;
        }
    }

    for (uint32_t i = 0; i < NUM_MCS_PER_PROC; i++)
    {
        iv_mcsGrouped[i] = false;
    }
}

//------------------------------------------------------------------------------
EffGroupingMemInfo::EffGroupingMemInfo()
{
    // Initialize all instance variables to zero
    for (uint32_t i = 0; i < NUM_MCS_PER_PROC; i++)
    {
        iv_mcsSize[i] = 0;
        for (uint32_t j = 0; j < NUM_MBA_PER_MCS; j++)
        {
            iv_mbaSize[i][j] = 0;
        }
        iv_largestMbaSize[i] = 0;
    }
}

//------------------------------------------------------------------------------
fapi::ReturnCode EffGroupingMemInfo::getMemInfo (
    const std::vector<fapi::Target> & i_assocCentaurs)
{
    fapi::ReturnCode rc;

    for (uint32_t i = 0; i < i_assocCentaurs.size(); i++)
    {
        const fapi::Target & cenTarget = i_assocCentaurs[i];

        // Get the Centaur attributes
        EffGroupingMembufAttrs centaurAttrs;
        rc = centaurAttrs.getAttrs(cenTarget);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error getting Centaur chip attributes");
            break;
        }

        // Store the Centaur Target in iv_membufs (indexed by MCS position)
        iv_membufs[centaurAttrs.iv_mcsPos] = cenTarget;

        // Get the functional MBA children of the Centaur
        std::vector <fapi::Target> l_mba_chiplets;
        rc = fapiGetChildChiplets(cenTarget,
                                  fapi::TARGET_TYPE_MBA_CHIPLET,
                                  l_mba_chiplets);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error getting child MBA chiplets");
            break;
        }

        for (uint32_t j = 0; j < l_mba_chiplets.size(); j++)
        {
            fapi::Target & mbaTarget = l_mba_chiplets[j];

            // Get the MBA Chiplet attributes
            EffGroupingMbaAttrs mbaAttrs;
            rc = mbaAttrs.getAttrs(mbaTarget);
            if (rc)
            {
                FAPI_ERR("mss_eff_grouping: Error getting MBA attributes");
                break;
            }

            // Add each Effective DIMM size to iv_mcsSize and iv_mbaSize
            for (uint8_t port = 0; port < NUM_MBA_PORTS; port++)
            {
                for (uint8_t dimm = 0; dimm < NUM_MBA_DIMMS; dimm++)
                {
                    iv_mcsSize[centaurAttrs.iv_mcsPos]
                        += mbaAttrs.iv_effDimmSize[port][dimm];
                    iv_mbaSize[centaurAttrs.iv_mcsPos][mbaAttrs.iv_unitPos]
                        += mbaAttrs.iv_effDimmSize[port][dimm];
                }
            }

            FAPI_INF("mss_eff_grouping: Cen Pos %u, MBA UPos %u, MBA total size %u GB",
                     centaurAttrs.iv_pos, mbaAttrs.iv_unitPos,
                     iv_mbaSize[centaurAttrs.iv_mcsPos][mbaAttrs.iv_unitPos]);
        }
        if (rc)
        {
            break;
        }
    }

    if (!rc)
    {
        // Calculate max MBA size
        for (uint8_t i = 0; i < NUM_MCS_PER_PROC; i++)
        {
            iv_largestMbaSize[i] = iv_mbaSize[i][0];

            for (uint32_t j = 1; j < NUM_MBA_PER_MCS; j++)
            {
                if (iv_mbaSize[i][j] > iv_largestMbaSize[i])
                {
                    iv_largestMbaSize[i] = iv_mbaSize[i][j];
                }
            }
        }

        // Trace sizes
        for (uint8_t i = 0; i < NUM_MCS_PER_PROC; i++)
        {
            FAPI_INF("mss_eff_grouping: MCS Pos %u, MCS Size %u GB, "
                     "MBA0 Size %u GB, MBA1 Size %u GB",
                     i, iv_mcsSize[i], iv_mbaSize[i][0], iv_mbaSize[i][1]);
        }
    }

    return rc;
}

//------------------------------------------------------------------------------
fapi::ReturnCode EffGroupingSysAttrs::getAttrs()
{
    fapi::ReturnCode rc;

    do
    {
        rc = FAPI_ATTR_GET(ATTR_ALL_MCS_IN_INTERLEAVING_GROUP, NULL,
                           iv_mcsInterleaveMode);
        if (rc)
        {
            FAPI_ERR("Error querying sys chip ATTR_ALL_MCS_IN_INTERLEAVING_GROUP");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_MEM_MIRROR_PLACEMENT_POLICY, NULL,
                           iv_selectiveMode);
        if (rc)
        {
            FAPI_ERR("Error querying sys ATTR_MEM_MIRROR_PLACEMENT_POLICY");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING, NULL,
                           iv_enhancedNoMirrorMode);
        if (rc)
        {
            FAPI_ERR("Error querying sys ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING");
            break;
        }

        FAPI_INF("mss_eff_grouping::EffGroupingSysAttrs: "
                 "ALL_MCS_IN_INTERLEAVING_GROUP 0x%02x, "
                 "MEM_MIRROR_PLACEMENT_POLICY 0x%02x, "
                 "MRW_ENHANCED_GROUPING_NO_MIRRORING 0x%02x",
                 iv_mcsInterleaveMode, iv_selectiveMode,
                 iv_enhancedNoMirrorMode);
    } while(0);

    return rc;
}

//------------------------------------------------------------------------------
fapi::ReturnCode EffGroupingProcAttrs::getAttrs(const fapi::Target & i_proc)
{
    fapi::ReturnCode rc;

    do
    {
        rc = FAPI_ATTR_GET(ATTR_MSS_INTERLEAVE_ENABLE, &i_proc,
                           iv_groupsAllowed);
        if (rc)
        {
            FAPI_ERR("Error querying proc chip ATTR_MSS_INTERLEAVE_ENABLE for %s",
                     i_proc.toEcmdString());
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE, &i_proc, iv_memBaseAddr);
        if (rc)
        {
            FAPI_ERR("Error querying proc chip ATTR_PROC_MEM_BASE for %s",
                     i_proc.toEcmdString());
            break;
        }
        iv_memBaseAddr >>= 30;

        rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE, &i_proc, iv_mirrorBaseAddr);
        if (rc)
        {
            FAPI_ERR("Error querying proc chip ATTR_PROC_MIRROR_BASE for %s",
                     i_proc.toEcmdString());
            break;
        }
        iv_mirrorBaseAddr >>= 30;

        rc = FAPI_ATTR_GET(ATTR_PROC_HTM_BAR_SIZE, &i_proc, iv_htmBarSize);
        if (rc)
        {
            FAPI_ERR("Error querying proc chip ATTR_PROC_HTM_BAR_SIZE for %s",
                     i_proc.toEcmdString());
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_OCC_SANDBOX_SIZE, &i_proc,
                           iv_occSandboxSize);
        if (rc)
        {
            FAPI_ERR("Error querying proc chip ATTR_PROC_OCC_SANDBOX_SIZE for %s",
                     i_proc.toEcmdString());
            break;
        }

        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: "
                 "MSS_INTERLEAVE_ENABLE 0x%02x", iv_groupsAllowed);
        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: 1 MCSs per group %s",
                 (iv_groupsAllowed & MCS_GROUP_1) ?
                     "supported" : "not supported");
        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: 2 MCSs per group %s",
                 (iv_groupsAllowed & MCS_GROUP_2) ?
                     "supported" : "not supported");
        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: 4 MCSs per group %s",
                 (iv_groupsAllowed & MCS_GROUP_4) ?
                     "supported" : "not supported");
        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: 8 MCSs per group %s",
                 (iv_groupsAllowed & MCS_GROUP_8) ?
                     "supported" : "not supported");
        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: "
                 "ATTR_PROC_MEM_BASE >> 30 0x%016llx, "
                 "ATTR_PROC_MIRROR_BASE >> 30 0x%016llx",
                 iv_memBaseAddr, iv_mirrorBaseAddr);
        FAPI_INF("mss_eff_grouping::EffGroupingProcAttrs: "
                 "ATTR_PROC_HTM_BAR_SIZE 0x%016llx, "
                 "ATTR_PROC_OCC_SANDBOX_SIZE 0x%016llx",
                 iv_htmBarSize, iv_occSandboxSize);
    } while(0);

    return rc;
}

//------------------------------------------------------------------------------
fapi::ReturnCode EffGroupingMembufAttrs::getAttrs(const fapi::Target & i_membuf)
{
    fapi::ReturnCode rc;

    do
    {
        rc = FAPI_ATTR_GET(ATTR_POS, &i_membuf, iv_pos);
        if (rc)
        {
            FAPI_ERR("Error querying membuf chip ATTR_POS for %s",
                     i_membuf.toEcmdString());
            break;
        }

        // Assumption is that
        // Chip pos 0: MCS unit-pos 0: Membuf pos 0
        // Chip pos 0: MCS unit-pos 1: Membuf pos 1
        // Chip pos 0: MCS unit-pos 2: Membuf pos 2
        // Chip pos 0: MCS unit-pos 3: Membuf pos 3
        // Chip pos 0: MCS unit-pos 4: Membuf pos 4
        // Chip pos 0: MCS unit-pos 5: Membuf pos 5
        // Chip pos 0: MCS unit-pos 6: Membuf pos 6
        // Chip pos 0: MCS unit-pos 7: Membuf pos 7
        // Chip pos 1: MCS unit-pos 0: Membuf pos 8
        // Chip pos 1: MCS unit-pos 1: Membuf pos 9
        // Chip pos 1: MCS unit-pos 2: Membuf pos 10
        // Chip pos 1: MCS unit-pos 3: Membuf pos 11
        // Chip pos 1: MCS unit-pos 4: Membuf pos 12
        // Chip pos 1: MCS unit-pos 5: Membuf pos 13
        // Chip pos 1: MCS unit-pos 6: Membuf pos 14
        // Chip pos 1: MCS unit-pos 7: Membuf pos 15
        // etc.
        iv_mcsPos = iv_pos % 8;

        FAPI_INF("mss_eff_grouping::EffGroupingMembufAttrs: "
                 "%s: POS %u, mcsPos %u",
                 i_membuf.toEcmdString(), iv_pos, iv_mcsPos);
    } while(0);
    return rc;
}

//------------------------------------------------------------------------------
EffGroupingMbaAttrs::EffGroupingMbaAttrs() : iv_unitPos(0)
{
    for (uint8_t i = 0; i < NUM_MBA_PORTS; i++)
    {
        for (uint8_t j = 0; j < NUM_MBA_DIMMS; j++)
        {
            iv_effDimmSize[i][j] = 0;
        }
    }
}
//------------------------------------------------------------------------------
fapi::ReturnCode EffGroupingMbaAttrs::getAttrs(const fapi::Target & i_mba)
{
    fapi::ReturnCode rc;

    do
    {
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_mba, iv_unitPos);
        if (rc)
        {
            FAPI_ERR("Error querying MBA ATTR_CHIP_UNIT_POS for %s",
                     i_mba.toEcmdString());
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &i_mba, iv_effDimmSize);
        if (rc)
        {
            FAPI_ERR("Error querying MBA ATTR_EFF_DIMM_SIZE for %s",
                     i_mba.toEcmdString());
            break;
        }

        FAPI_INF("mss_eff_grouping::EffGroupingMbaAttrs: %s: CHIP_UNIT_POS %u",
                 i_mba.toEcmdString(), iv_unitPos);

        for (uint8_t i = 0; i < NUM_MBA_PORTS; i++)
        {
            for (uint8_t j = 0; j < NUM_MBA_DIMMS; j++)
            {
                FAPI_INF("mss_eff_grouping::EffGroupingMbaAttrs: MBA %u: "
                         "EFF_DIMM_SIZE[%u][%u] %u GB",
                         iv_unitPos, i, j, iv_effDimmSize[i][j]);
            }
        }
    } while(0);

    return rc;
}

/**
 * @brief checks that attributes are valid
 *
 * @param[in] i_sysAttrs  Reference to system attributes
 * @param[in] i_procAttrs Reference to proc chip attributes
 *
 * @return fapi::ReturnCode
 */
fapi::ReturnCode grouping_checkValidAttributes(
    const EffGroupingSysAttrs & i_sysAttrs,
    const EffGroupingProcAttrs & i_procAttrs)
{
    fapi::ReturnCode rc;
    do
    {
        if (i_sysAttrs.iv_enhancedNoMirrorMode)
        {
            if (i_sysAttrs.iv_selectiveMode ==
                fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                FAPI_ERR("mss_eff_grouping: Mirroring disabled, selective mode invalid");
                const uint8_t & MIRROR_PLACEMENT_POLICY =
                    i_sysAttrs.iv_selectiveMode;
                FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MIRROR_DISABLED);
                break;
            }

            if (i_sysAttrs.iv_selectiveMode ==
                fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
            {
                FAPI_ERR("mss_eff_grouping: Mirroring disabled, flipped mode invalid");
                const uint8_t & MIRROR_PLACEMENT_POLICY =
                    i_sysAttrs.iv_selectiveMode;
                FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MIRROR_DISABLED);
                break;
            }
        }

        if (i_sysAttrs.iv_mcsInterleaveMode)
        {
            // Fabric interleaving mode, must be 2, 4 or 8 MCSs per group
            if ( ((!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_2)) &&
                  (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_4)) &&
                  (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_8))) ||
                 (i_procAttrs.iv_groupsAllowed & MCS_GROUP_1) )
            {
                FAPI_ERR("mss_eff_grouping: Interleaving mode, but MCSs per group invalid (0x%02x)",
                         i_procAttrs.iv_groupsAllowed);
                const uint8_t ALL_MCS_IN_INTERLEAVING_GROUP =
                    i_sysAttrs.iv_mcsInterleaveMode;
                const uint8_t MSS_INTERLEAVE_ENABLE =
                    i_procAttrs.iv_groupsAllowed;
                FAPI_SET_HWP_ERROR(rc,
                    RC_MSS_EFF_CONFIG_INTERLEAVE_MODE_INVALID_MCS_PER_GROUP);
                break;
            }
        }
        else
        {
            // Fabric checkerboard mode, all MCSs per group allowed, but more
            // than 1 MCS per group will will have a performance impact
            if ( (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_1)) &&
                 (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_2)) &&
                 (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_4)) &&
                 (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_8)) )
            {
                FAPI_ERR("mss_eff_grouping: Checkerboard mode, but MCSs per group invalid (0x%02x)",
                         i_procAttrs.iv_groupsAllowed);
                const uint8_t ALL_MCS_IN_INTERLEAVING_GROUP =
                    i_sysAttrs.iv_mcsInterleaveMode;
                const uint8_t MSS_INTERLEAVE_ENABLE =
                    i_procAttrs.iv_groupsAllowed;
                FAPI_SET_HWP_ERROR(rc,
                    RC_MSS_EFF_CONFIG_CHECKERBOARD_MODE_INVALID_MCS_PER_GROUP);
                break;
            }

            if (!(i_procAttrs.iv_groupsAllowed & MCS_GROUP_1))
            {
                FAPI_INF("mss_eff_grouping: Fabric is in checkerboard mode "
                         "with more than 1 MCS per group, performance would "
                         "be better in interleaving mode");
            }
        }

        if (i_sysAttrs.iv_selectiveMode ==
            fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
        {
            if (i_procAttrs.iv_htmBarSize != 0 ||
                i_procAttrs.iv_occSandboxSize != 0)
            {
                FAPI_ERR("mss_eff_grouping: Selective mode does not support "
                         "HTM and OCC Sandbox BARs");
                const uint64_t & HTM_BAR_SIZE = i_procAttrs.iv_htmBarSize;
                const uint64_t & OCC_SANDBOX_BAR_SIZE =
                    i_procAttrs.iv_occSandboxSize;
                FAPI_SET_HWP_ERROR(rc,
                    RC_MSS_EFF_GROUPING_SELCTIVE_MODE_HTM_OCC_BAR);
                break;
            }
        }
    } while (0);

    return rc;
}

/**
 * @brief Attempts to group 8 MCSs per group
 *
 * If they can be grouped, fills in the following fields in o_groupData:
 * - iv_data[<group>][MCS_SIZE]
 * - iv_data[<group>][MCS_IN_GROUP]
 * - iv_data[<group>][GROUP_SIZE]
 * - iv_data[<group>][MEMBER_IDX(<members>)]
 * - iv_data[<group>][LARGEST_MBA_SIZE]
 * - iv_mcsGrouped[<group>]
 * - iv_numGroups
 *
 * @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
 * @param[out] o_groupData Reference to output data
 */
void grouping_group8McsPerGroup(const EffGroupingMemInfo & i_memInfo,
                                EffGroupingData & o_groupData)
{
    // There are 8 MCSs in a proc chip, they can be grouped together if they all
    // have the same memory size. Assume that no MCSs have already been grouped
    FAPI_INF("mss_eff_grouping: Attempting to group 8 MCSs per group");
    uint8_t & g = o_groupData.iv_numGroups;

    if ((NUM_MCS_PER_PROC == 8) && (i_memInfo.iv_mcsSize[0] != 0))
    {
        // MCS 0 has memory
        bool grouped = true;
        uint32_t maxMbaSize = i_memInfo.iv_largestMbaSize[0];

        for (uint8_t pos = 1; pos < NUM_MCS_PER_PROC; pos++)
        {
            if (i_memInfo.iv_mcsSize[0] != i_memInfo.iv_mcsSize[pos])
            {
                // This MCS does not have the same size as MCS 0
                grouped = false;
                break;
            }
            else if (i_memInfo.iv_largestMbaSize[pos] > maxMbaSize)
            {
                maxMbaSize = i_memInfo.iv_largestMbaSize[pos];
            }
        }

        if (grouped)
        {
            // All 8 MCSs are the same size and can be grouped
            FAPI_INF("mss_eff_grouping: Grouped all 8 MCSs");
            o_groupData.iv_data[g][MCS_SIZE] = i_memInfo.iv_mcsSize[0];
            o_groupData.iv_data[g][MCS_IN_GROUP] = 8;
            o_groupData.iv_data[g][GROUP_SIZE] = 8 * i_memInfo.iv_mcsSize[0];
            o_groupData.iv_data[g][MEMBER_IDX(0)] = MCSID_0;
            o_groupData.iv_data[g][MEMBER_IDX(1)] = MCSID_4;
            o_groupData.iv_data[g][MEMBER_IDX(2)] = MCSID_2;
            o_groupData.iv_data[g][MEMBER_IDX(3)] = MCSID_6;
            o_groupData.iv_data[g][MEMBER_IDX(4)] = MCSID_1;
            o_groupData.iv_data[g][MEMBER_IDX(5)] = MCSID_5;
            o_groupData.iv_data[g][MEMBER_IDX(6)] = MCSID_3;
            o_groupData.iv_data[g][MEMBER_IDX(7)] = MCSID_7;
            o_groupData.iv_data[g][LARGEST_MBA_SIZE] = maxMbaSize;
            g++;

            // Record which MCSs were grouped
            for (uint8_t i = 0; i < NUM_MCS_PER_PROC; i++)
            {
                o_groupData.iv_mcsGrouped[i] = true;
            }
        }
    }
}

/**
 * @brief Attempts to group 4 MCSs per group
 *
 * If they can be grouped, fills in the following fields in o_groupData:
 * - iv_data[<group>][MCS_SIZE]
 * - iv_data[<group>][MCS_IN_GROUP]
 * - iv_data[<group>][GROUP_SIZE]
 * - iv_data[<group>][MEMBER_IDX(<members>)]
 * - iv_data[<group>][LARGEST_MBA_SIZE]
 * - iv_mcsGrouped[<group>]
 * - iv_numGroups
 *
 * @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
 * @param[out] o_groupData Reference to output data
 */
void grouping_group4McsPerGroup(const EffGroupingMemInfo & i_memInfo,
                                EffGroupingData & o_groupData)
{
    // The following is all the allowed ways of grouping 4 MCSs per group.
    // Earlier array entries are higher priority.
    // First try to group 2 sets of 4 (0/1, 2/3 or 4/5)
    // If no success then try to group 1 set of 4
    FAPI_INF("mss_eff_grouping: Attempting to group 4 MCSs per group");
    uint8_t & g = o_groupData.iv_numGroups;
    const uint8_t NUM_WAYS_4MCS_PER_GROUP = 6;
    const uint8_t CFG_4MCS[NUM_WAYS_4MCS_PER_GROUP][4] =
        { { MCSID_0, MCSID_1, MCSID_4, MCSID_5 },
          { MCSID_2, MCSID_3, MCSID_6, MCSID_7 },
          { MCSID_0, MCSID_1, MCSID_6, MCSID_7 },
          { MCSID_2, MCSID_3, MCSID_4, MCSID_5 },
          { MCSID_0, MCSID_1, MCSID_2, MCSID_3 },
          { MCSID_4, MCSID_5, MCSID_6, MCSID_7 } };

    // Array recording which groups of 4 can potentially be grouped
    uint8_t config4_gp[NUM_WAYS_4MCS_PER_GROUP] = {0};

    // Figure out which groups of 4 can potentially be grouped
    for (uint8_t i = 0; i < NUM_WAYS_4MCS_PER_GROUP; i++)
    {
        if ((!o_groupData.iv_mcsGrouped[CFG_4MCS[i][0]]) &&
            (i_memInfo.iv_mcsSize[CFG_4MCS[i][0]] != 0))
        {
            // First MCS of group is not already grouped and has memory
            bool potential_group = true;
            for (uint8_t j = 1; j < 4; j++)
            {
                if ( (o_groupData.iv_mcsGrouped[CFG_4MCS[i][j]]) ||
                     (i_memInfo.iv_mcsSize[CFG_4MCS[i][0]] !=
                         i_memInfo.iv_mcsSize[CFG_4MCS[i][j]]) )
                {
                    // This MCS is already grouped or does not have the same
                    // size as MCS 0
                    potential_group = false;
                    break;
                }
            }
            if (potential_group)
            {
                FAPI_INF("mss_eff_grouping: Potential group MCSs %u, %u, %u, %u",
                         CFG_4MCS[i][0], CFG_4MCS[i][1],
                         CFG_4MCS[i][2], CFG_4MCS[i][3]);
                config4_gp[i] = 1;
            }
        }
    }

    // Figure out which groups of 4 to actually group
    uint8_t gp1 = 0xff;
    uint8_t gp2 = 0xff;

    // Check if 2 groups of 4 are possible (0/1, 2/3 or 4/5)
    for (uint8_t i = 0; i < NUM_WAYS_4MCS_PER_GROUP; i += 2)
    {
        if (config4_gp[i] && config4_gp[i + 1])
        {
            FAPI_INF("mss_eff_grouping: Grouped MCSs %u, %u, %u, %u",
                     CFG_4MCS[i][0], CFG_4MCS[i][1],
                     CFG_4MCS[i][2], CFG_4MCS[i][3]);
            FAPI_INF("mss_eff_grouping: Grouped MCSs %u, %u, %u, %u",
                     CFG_4MCS[i + 1][0], CFG_4MCS[i + 1][1],
                     CFG_4MCS[i + 1][2], CFG_4MCS[1 + 1][3]);
            gp1 = i;
            gp2 = i + 1;
            break;
        }
    }

    if (gp1 == 0xff)
    {
        // 2 groups of 4 are not possible, look for 1 group of 4
        for (uint8_t i = 0; i < NUM_WAYS_4MCS_PER_GROUP; i++)
        {
            if (config4_gp[i])
            {
                FAPI_INF("mss_eff_grouping: Grouped MCSs %u, %u, %u, %u",
                         CFG_4MCS[i][0], CFG_4MCS[i][1],
                         CFG_4MCS[i][2], CFG_4MCS[i][3]);
                gp1 = i;
                break;
            }
        }
    }

    if (gp1 != 0xff)
    {
        // Figure out the maximum MBA size for group 1
        uint32_t maxMbaSize = i_memInfo.iv_largestMbaSize[CFG_4MCS[gp1][0]];
        for (uint8_t i = 1; i < 4; i++)
        {
            if (i_memInfo.iv_largestMbaSize[CFG_4MCS[gp1][i]] > maxMbaSize)
            {
                maxMbaSize = i_memInfo.iv_largestMbaSize[CFG_4MCS[gp1][i]];
            }
        }

        o_groupData.iv_data[g][MCS_SIZE] =
            i_memInfo.iv_mcsSize[CFG_4MCS[gp1][0]];
        o_groupData.iv_data[g][MCS_IN_GROUP] = 4;
        o_groupData.iv_data[g][GROUP_SIZE] =
            4 * i_memInfo.iv_mcsSize[CFG_4MCS[gp1][0]];
        o_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_4MCS[gp1][0];
        o_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_4MCS[gp1][2];
        o_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_4MCS[gp1][1];
        o_groupData.iv_data[g][MEMBER_IDX(3)] = CFG_4MCS[gp1][3];
        o_groupData.iv_data[g][LARGEST_MBA_SIZE] = maxMbaSize;
        g++;

        // Record which MCSs were grouped
        for (uint8_t i = 0; i < 4; i++)
        {
            o_groupData.iv_mcsGrouped[CFG_4MCS[gp1][i]] = true;
        }
    }

    if (gp2 != 0xff)
    {
        // Figure out the maximum MBA size for group 2
        uint32_t maxMbaSize =
            i_memInfo.iv_largestMbaSize[CFG_4MCS[gp2][0]];
        for (uint8_t i = 1; i < 4; i++)
        {
            if (i_memInfo.iv_largestMbaSize[CFG_4MCS[gp2][i]] > maxMbaSize)
            {
                maxMbaSize = i_memInfo.iv_largestMbaSize[CFG_4MCS[gp2][i]];
            }
        }

        o_groupData.iv_data[g][MCS_SIZE] =
            i_memInfo.iv_mcsSize[CFG_4MCS[gp2][0]];
        o_groupData.iv_data[g][MCS_IN_GROUP] = 4;
        o_groupData.iv_data[g][GROUP_SIZE] =
            4 * i_memInfo.iv_mcsSize[CFG_4MCS[gp2][0]];
        o_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_4MCS[gp2][0];
        o_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_4MCS[gp2][2];
        o_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_4MCS[gp2][1];
        o_groupData.iv_data[g][MEMBER_IDX(3)] = CFG_4MCS[gp2][3];
        o_groupData.iv_data[g][LARGEST_MBA_SIZE] = maxMbaSize;
        g++;

        // Record which MCSs were grouped
        for (uint8_t i = 0; i < 4; i++)
        {
            o_groupData.iv_mcsGrouped[CFG_4MCS[gp2][i]] = true;
        }
    }
}

/**
 * @brief Attempts to group 2 MCSs per group
 *
 * If they can be grouped, fills in the following fields in o_groupData:
 * - iv_data[<group>][MCS_SIZE]
 * - iv_data[<group>][MCS_IN_GROUP]
 * - iv_data[<group>][GROUP_SIZE]
 * - iv_data[<group>][MEMBER_IDX(<members>)]
 * - iv_data[<group>][LARGEST_MBA_SIZE]
 * - iv_mcsGrouped[<group>]
 * - iv_numGroups
 *
 * @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
 * @param[out] o_groupData Reference to output data
 */
void grouping_group2McsPerGroup(const EffGroupingMemInfo & i_memInfo,
                                EffGroupingData & o_groupData)
{
    // 2 adjacent MCSs are grouped if they have the same size
    // 0/1, 2/3, 4/5, 6/7
    FAPI_INF("mss_eff_grouping: Attempting to group 2 MCSs per group");
    uint8_t & g = o_groupData.iv_numGroups;

    for (uint8_t pos = 0; pos < NUM_MCS_PER_PROC - 1; pos = pos+2)
    {
        if ((!o_groupData.iv_mcsGrouped[pos]) &&
            (!o_groupData.iv_mcsGrouped[pos + 1]) &&
            (i_memInfo.iv_mcsSize[pos] != 0) &&
            (i_memInfo.iv_mcsSize[pos] == i_memInfo.iv_mcsSize[pos + 1]))
        {
            // These 2 MCSs are not already grouped and have the same amount of
            // memory
            FAPI_INF("mss_eff_grouping: Grouped MCSs %u and %u", pos, pos + 1);
            o_groupData.iv_data[g][MCS_SIZE] = i_memInfo.iv_mcsSize[pos];
            o_groupData.iv_data[g][MCS_IN_GROUP] = 2;
            o_groupData.iv_data[g][GROUP_SIZE] = 2 * i_memInfo.iv_mcsSize[pos];
            o_groupData.iv_data[g][MEMBER_IDX(0)] = pos;
            o_groupData.iv_data[g][MEMBER_IDX(1)] = pos + 1;
            if (i_memInfo.iv_largestMbaSize[pos] >
                i_memInfo.iv_largestMbaSize[pos + 1])
            {
                o_groupData.iv_data[g][LARGEST_MBA_SIZE] =
                    i_memInfo.iv_largestMbaSize[pos];
            }
            else
            {
                o_groupData.iv_data[g][LARGEST_MBA_SIZE] =
                    i_memInfo.iv_largestMbaSize[pos + 1];
            }
            g++;

            // Record which MCSs were grouped
            o_groupData.iv_mcsGrouped[pos] = true;
            o_groupData.iv_mcsGrouped[pos + 1] = true;
           
        }
    }
}

/**
 * @brief Attempts to group 1 MCS per group
 *
 * If they can be grouped, fills in the following fields in o_groupData:
 * - iv_data[<group>][MCS_SIZE]
 * - iv_data[<group>][MCS_IN_GROUP]
 * - iv_data[<group>][GROUP_SIZE]
 * - iv_data[<group>][MEMBER_IDX(<members>)]
 * - iv_data[<group>][LARGEST_MBA_SIZE]
 * - iv_mcsGrouped[<group>]
 * - iv_numGroups
 *
 * @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
 * @param[out] o_groupData Reference to output data
 */
void grouping_group1McsPerGroup(const EffGroupingMemInfo & i_memInfo,
                                EffGroupingData & o_groupData)
{
    // Any MCS with a non-zero size can be 'grouped'
    FAPI_INF("mss_eff_grouping: Attempting to group 1 MCSs per group");
    uint8_t & g = o_groupData.iv_numGroups;
    for (uint8_t pos = 0; pos < NUM_MCS_PER_PROC; pos++)
    {
        if ((!o_groupData.iv_mcsGrouped[pos]) &&
            (i_memInfo.iv_mcsSize[pos] != 0))
        {
            // This MCS is not already grouped and has memory
            FAPI_INF("mss_eff_grouping: MCS %u grouped", pos);
            o_groupData.iv_data[g][MCS_SIZE] = i_memInfo.iv_mcsSize[pos];
            o_groupData.iv_data[g][MCS_IN_GROUP] = 1;
            o_groupData.iv_data[g][GROUP_SIZE] = i_memInfo.iv_mcsSize[pos];
            o_groupData.iv_data[g][MEMBER_IDX(0)] = pos;
            o_groupData.iv_data[g][LARGEST_MBA_SIZE] =
                i_memInfo.iv_largestMbaSize[pos];
            g++;

            // Record which MCS was grouped
            o_groupData.iv_mcsGrouped[pos] = true;
        }
    }
}

/**
 * @brief Finds ungrouped MCSs
 *
 * If any are found then their associated Membuf chip is deconfigured
 *
 * @param[in] i_memInfo   Reference to Memory Info
 * @param[in] i_groupData Reference to Group data
 *
 * @return fapi::ReturnCode
 */
fapi::ReturnCode grouping_findUngroupedMCSs(
    const EffGroupingMemInfo & i_memInfo,
    const EffGroupingData & i_groupData)
{
    fapi::ReturnCode rc;

    bool ungrouped = false;
    for (uint8_t i = 0; i < NUM_MCS_PER_PROC; i++)
    {
        if ((i_memInfo.iv_mcsSize[i] != 0) &&
            (i_groupData.iv_mcsGrouped[i] == false))
        {
            FAPI_ERR("mss_eff_grouping: Unable to group MCS %u", i);
            ungrouped = true;
            const fapi::Target & MEMBUF = i_memInfo.iv_membufs[i];
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_GROUPING_UNABLE_TO_GROUP_MCS);
            fapiLogError(rc);
            rc = fapi::FAPI_RC_SUCCESS;
        }
    }

    if (ungrouped)
    {
        // One or more MCSs could not be grouped and errors were logged to
        // callout the memory plug procedure and deconfigure the membuf.
        // Return an error
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_GROUPING_UNABLE_TO_GROUP);
    }

    return rc;
}

/**
 * @brief Calculates the number of 1s in a memory size
 *
 * @param[i] i_size Memory Size
 *
 * @return Number of 1s
 */
uint8_t grouping_num1sInSize(uint32_t i_size)
{
    uint8_t numOnes = 0;
    uint32_t l_size = i_size;

    while (l_size != 0)
    {
        if (l_size & 1)
        {
            numOnes++;
        }
        l_size >>= 1;
    }

    FAPI_DBG("mss_eff_grouping: Num 1s in 0x%08x is %u", i_size, numOnes);
    return numOnes;
}

/**
 * @brief Calculate Alt Memory
 *
 * @param[io] io_groupData Group Data
 */
void grouping_calcAltMemory(EffGroupingData & io_groupData)
{
    FAPI_INF("mss_eff_grouping: Calculating Alt Memory");
    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        // Find the number of 1s in the group size
        uint8_t numOnes = grouping_num1sInSize(
            io_groupData.iv_data[pos][GROUP_SIZE]);

        if (numOnes > 1)
        {
            FAPI_INF("mss_eff_grouping: Group %u needs alt bars definition, group size %u GB",
                     pos, io_groupData.iv_data[pos][GROUP_SIZE]);

            // New group size is the largest MBA size of the group
            // multiplied by the number of MBAs in the group
            io_groupData.iv_data[pos][GROUP_SIZE] =
                io_groupData.iv_data[pos][LARGEST_MBA_SIZE] *
                    NUM_MBA_PER_MCS *
                        io_groupData.iv_data[pos][MCS_IN_GROUP];
            FAPI_INF("mss_eff_grouping: New Group Size is %u GB",
                     io_groupData.iv_data[pos][GROUP_SIZE]);

            // Alt size is the number of MCSs in the group multiplied by
            // (the MCS size minus the largest MBA size)
            io_groupData.iv_data[pos][ALT_SIZE] =
                io_groupData.iv_data[pos][MCS_IN_GROUP] *
                    (io_groupData.iv_data[pos][MCS_SIZE] -
                     io_groupData.iv_data[pos][LARGEST_MBA_SIZE]);
            FAPI_INF("mss_eff_grouping: Alt Size is %u GB",
                     io_groupData.iv_data[pos][ALT_SIZE]);

            io_groupData.iv_data[pos][ALT_VALID] = 1;
        }
    }
}

/**
 * @brief Sorts groups from high to low memory size
 *
 * @param[io] io_groupData Group Data
 */
void grouping_sortGroups(EffGroupingData & io_groupData)
{
    // Done with a simple bubble sort
    FAPI_INF("mss_eff_grouping: Sorting Groups");
    if (io_groupData.iv_numGroups)
    {
        uint32_t temp[DATA_ELEMENTS];
        bool swapped = true;
        while (swapped == true)
        {
            // Make a pass over the groups swapping adjacent sizes as needed
            swapped = false;
            for (uint8_t pos = 0; pos < io_groupData.iv_numGroups - 1; pos++)
            {
                if (io_groupData.iv_data[pos][GROUP_SIZE] <
                    io_groupData.iv_data[pos + 1][GROUP_SIZE])
                {
                    FAPI_INF("mss_eff_grouping: Swapping groups %u and %u",
                             pos, pos + 1);
                    for (uint32_t j = 0; j < DATA_ELEMENTS; j++)
                    {
                        temp[j] = io_groupData.iv_data[pos][j];
                    }
                    for (uint32_t j = 0; j < DATA_ELEMENTS; j++)
                    {
                        io_groupData.iv_data[pos][j] =
                            io_groupData.iv_data[pos + 1][j];
                    }
                    for (uint32_t j = 0; j < DATA_ELEMENTS; j++)
                    {
                        io_groupData.iv_data[pos + 1][j] = temp[j];
                    }
                    swapped = true;
                }
            }
        }
    }
}

/**
 * @brief Calculate Mirror Memory base and alt-base addresses
 *
 * @param[in] i_target           Reference to processor chip target
 * @param[io] io_procAttrs       Processor Attributes (iv_mirrorBaseAddr can be
 *                                                     updated)
 * @param[io] io_groupData       Group Data
 * @param[in] i_totalSizeNonMirr Total non mirrored size
 *
 * @return fapi::ReturnCode
 */
fapi::ReturnCode grouping_calcMirrorMemory(const fapi::Target & i_target,
                                           EffGroupingProcAttrs & io_procAttrs,
                                           EffGroupingData & io_groupData)
{
    FAPI_INF("mss_eff_grouping: Calculating Mirror Memory");
    fapi::ReturnCode rc;

    // Calculate mirrored group size and non mirrored group size
    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        if (io_groupData.iv_data[pos][MCS_IN_GROUP] > 1)
        {
            // Mirrored size is half the group size
            io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE] =
                io_groupData.iv_data[pos][GROUP_SIZE] / 2;

            if (io_groupData.iv_data[pos][ALT_VALID])
            {
                FAPI_INF("mss_eff_grouping: Mirrored group %u needs alt bars definition, group size %u GB",
                         pos, io_groupData.iv_data[pos][GROUP_SIZE]);
                io_groupData.iv_data[pos + MIRR_OFFSET][ALT_SIZE] =
                    io_groupData.iv_data[pos][ALT_SIZE] / 2;
                io_groupData.iv_data[pos + MIRR_OFFSET][ALT_VALID] = 1;
            }
        }
    }

    // Check if the memory base address overlaps with the mirror base address
    if ( (io_procAttrs.iv_memBaseAddr >
          (io_procAttrs.iv_mirrorBaseAddr +
           io_groupData.iv_totalSizeNonMirr / 2)) ||
         (io_procAttrs.iv_mirrorBaseAddr >
          (io_procAttrs.iv_memBaseAddr + io_groupData.iv_totalSizeNonMirr)) )
    {
        for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
        {
            if (pos == 0)
            {
                io_groupData.iv_data[pos][BASE_ADDR] =
                    io_procAttrs.iv_memBaseAddr;
                if (io_groupData.iv_data[pos][ALT_VALID])
                {
                    io_groupData.iv_data[pos][ALT_BASE_ADDR] =
                        io_groupData.iv_data[pos][BASE_ADDR] +
                        io_groupData.iv_data[pos][GROUP_SIZE] / 2;
                }
            }
            else
            {
                io_groupData.iv_data[pos][BASE_ADDR] =
                    io_groupData.iv_data[pos - 1][BASE_ADDR] +
                    io_groupData.iv_data[pos - 1][GROUP_SIZE];
                if (io_groupData.iv_data[pos][ALT_VALID])
                {
                    io_groupData.iv_data[pos][ALT_BASE_ADDR] =
                        io_groupData.iv_data[pos][BASE_ADDR] +
                        io_groupData.iv_data[pos][GROUP_SIZE] / 2;
                }
            }

            if (io_groupData.iv_data[pos][MCS_IN_GROUP] > 1)
            {
                io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] =
                    io_procAttrs.iv_mirrorBaseAddr;
                io_procAttrs.iv_mirrorBaseAddr =
                    io_procAttrs.iv_mirrorBaseAddr +
                    io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE];
                if (io_groupData.iv_data[pos][ALT_VALID])
                {
                    io_groupData.iv_data[pos + MIRR_OFFSET][ALT_BASE_ADDR] =
                        io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] +
                        io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE] / 2;
                    io_groupData.iv_data[pos + MIRR_OFFSET][ALT_VALID] = 1;
                }
            }
        }
    }
    else
    {
        FAPI_ERR("mss_eff_grouping: Mirror Base address overlaps with memory base address");
        const fapi::Target & PROC_CHIP = i_target;
        const uint64_t & MEM_BASE_ADDR = io_procAttrs.iv_memBaseAddr;
        const uint64_t & MIRROR_BASE_ADDR = io_procAttrs.iv_mirrorBaseAddr;
        const uint32_t & SIZE_NON_MIRROR = io_groupData.iv_totalSizeNonMirr;
        FAPI_SET_HWP_ERROR(rc,
            RC_MSS_EFF_GROUPING_BASE_ADDRESS_OVERLAPS_MIRROR_ADDRESS);
    }

    return rc;
}

/**
 * @brief Calculate Non-mirror Memory base and alt-base addresses
 *
 * @param[in] i_procAttrs  Processor Chip Attributes
 * @param[io] io_groupData Group Data
 */
void grouping_calcNonMirrorMemory(const EffGroupingProcAttrs & i_procAttrs,
                                  EffGroupingData & io_groupData)
{
    FAPI_INF("mss_eff_grouping: Calculating Mirror Memory");

    // Assign mirroring and non-mirroring base address for each group
    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        if (pos == 0)
        {
            io_groupData.iv_data[pos][BASE_ADDR] = i_procAttrs.iv_memBaseAddr;
            if (io_groupData.iv_data[pos][ALT_VALID])
            {
                io_groupData.iv_data[pos][ALT_BASE_ADDR] =
                    io_groupData.iv_data[pos][BASE_ADDR] +
                    io_groupData.iv_data[pos][GROUP_SIZE] / 2;
            }
        }
        else
        {
            io_groupData.iv_data[pos][BASE_ADDR] =
                io_groupData.iv_data[pos - 1][BASE_ADDR] +
                io_groupData.iv_data[pos - 1][GROUP_SIZE];
            if (io_groupData.iv_data[pos][ALT_VALID])
            {
                io_groupData.iv_data[pos][ALT_BASE_ADDR] =
                    io_groupData.iv_data[pos][BASE_ADDR] +
                    io_groupData.iv_data[pos][GROUP_SIZE] / 2;
            }
        }
    }
}

/**
 * @brief Sets the ATTR_MSS_MEM_MC_IN_GROUP attribute
 *
 * @param[in] i_target    Reference to Processor Chip target
 * @param[in] i_groupData Group Data
 *
 * @return fapi::ReturnCode
 */
fapi::ReturnCode grouping_setATTR_MSS_MEM_MC_IN_GROUP(
    const fapi::Target & i_target,
    const EffGroupingData & i_groupData)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase MC_IN_GP(8);
    uint8_t mcs_in_group[8] = {0};

    for (uint8_t i = 0; i < i_groupData.iv_numGroups; i++)
    {
        MC_IN_GP.flushTo0();
        uint8_t count = i_groupData.iv_data[i][MCS_IN_GROUP];
        for (uint8_t j = 0; j < count; j++)
        {
            MC_IN_GP.setBit(i_groupData. iv_data[i][MEMBER_IDX(j)]);
        }
        mcs_in_group[i] = MC_IN_GP.getByte(0);
    }

    FAPI_INF("mss_eff_grouping: ATTR_MSS_MEM_MC_IN_GROUP[0][1][2][3]: "
             "0x%02x, 0x%02x, 0x%02x, 0x%02x",
             mcs_in_group[0], mcs_in_group[1], mcs_in_group[2],
             mcs_in_group[3]);
    FAPI_INF("mss_eff_grouping: ATTR_MSS_MEM_MC_IN_GROUP[4][5][6][7]: "
             "0x%02x, 0x%02x, 0x%02x, 0x%02x",
             mcs_in_group[4], mcs_in_group[5], mcs_in_group[6],
             mcs_in_group[7]);

    rc = FAPI_ATTR_SET(ATTR_MSS_MEM_MC_IN_GROUP, &i_target, mcs_in_group);
    if (rc)
    {
        FAPI_ERR("Error writing ATTR_MSS_MEM_MC_IN_GROUP");
    }

    return rc;
}

/**
 * @brief Traces the Grouping Data
 *
 * @param[in] i_sysAttrs  System Attributes
 * @param[in] i_groupData Group Data
 */
void grouping_traceData(const EffGroupingSysAttrs & i_sysAttrs,
                        const EffGroupingData & i_groupData)
{
    for (uint8_t i = 0; i < i_groupData.iv_numGroups; i++)
    {
        FAPI_INF("mss_eff_grouping: Group %u, MCS Size %u GB, "
                 "Num MCSs %u, GroupSize %u GB", i,
                 i_groupData.iv_data[i][MCS_SIZE],
                 i_groupData.iv_data[i][MCS_IN_GROUP],
                 i_groupData.iv_data[i][GROUP_SIZE]);

        FAPI_INF("mss_eff_grouping: Group %u, Base Add 0x%08x", i,
                 i_groupData.iv_data[i][BASE_ADDR]);

        if (!i_sysAttrs.iv_enhancedNoMirrorMode)
        {
            FAPI_INF("mss_eff_grouping: Group %u, Mirror Group Size %u GB, "
                     "Mirror Base Addr 0x%08x", i,
                     i_groupData.iv_data[i + MIRR_OFFSET][GROUP_SIZE],
                     i_groupData.iv_data[i + MIRR_OFFSET][BASE_ADDR]);
        }
        for (uint8_t j = 0; j <  i_groupData.iv_data[i][MCS_IN_GROUP]; j++)
        {
            FAPI_INF("mss_eff_grouping: Group %u, Contains MCS %u", i,
                     i_groupData.iv_data[i][MEMBER_IDX(j)]);
        }
        FAPI_INF("mss_eff_grouping: Group %u, Alt-bar valid %u, "
                 "Alt-bar size %u GB, Alt-bar base addr 0x%08x", i,
                 i_groupData.iv_data[i][ALT_VALID],
                 i_groupData.iv_data[i][ALT_SIZE],
                 i_groupData.iv_data[i][ALT_BASE_ADDR]);
        if (!i_sysAttrs.iv_enhancedNoMirrorMode)
        {
            FAPI_INF("mss_eff_grouping: Group %u, Mirror Alt-bar valid %u, "
                     "Mirror Alt-bar Size %u GB, "
                     "Mirror Alt-bar Base Addr 0x%08x", i,
                     i_groupData.iv_data[i + MIRR_OFFSET][ALT_VALID],
                     i_groupData.iv_data[i + MIRR_OFFSET][ALT_SIZE],
                     i_groupData.iv_data[i + MIRR_OFFSET][ALT_BASE_ADDR]);
        }
    }
}

/**
 * @brief Sets Base and Size FAPI Attributes
 *
 * Attributes set:
 * - ATTR_PROC_MEM_BASES
 * - ATTR_PROC_MEM_BASES_ACK
 * - ATTR_PROC_MEM_SIZES
 * - ATTR_PROC_MEM_SIZES_ACK
 * - ATTR_MSS_MCS_GROUP_32
 * - ATTR_PROC_MIRROR_BASES
 * - ATTR_PROC_MIRROR_BASES_ACK
 * - ATTR_PROC_MIRROR_SIZES
 * - ATTR_PROC_MIRROR_SIZES_ACK
 * - ATTR_PROC_HTM_BAR_BASE_ADDR
 * - ATTR_PROC_OCC_SANDBOX_BASE_ADDR
 *
 * @param[in] i_target    Reference to Processor Chip Target
 * @param[in] i_sysAttrs  System Attributes
 * @param[in] i_procAttrs Processor Chip Attributes (iv_htmBarSize set)
 * @param[in] i_groupData Group Data
 */
fapi::ReturnCode grouping_setBaseSizeAttrs(
    const fapi::Target & i_target,
    const EffGroupingSysAttrs & i_sysAttrs,
    EffGroupingProcAttrs & io_procAttrs,
    EffGroupingData & i_groupData)
{
    FAPI_INF("mss_eff_grouping: Setting Base/Size attributes");
    fapi::ReturnCode rc;

    do
    {
        uint64_t occ_sandbox_base = 0;
        uint64_t htm_bar_base = 0;
        uint64_t mem_bases[8] = {0};
        uint64_t mem_bases_ack[8] = {0};
        uint64_t l_memory_sizes[8] = {0};
        uint64_t l_memory_sizes_ack[8] = {0};
        uint64_t mirror_bases[4] = {0};
        uint64_t mirror_bases_ack[4] = {0};
        uint64_t l_mirror_sizes[4] = {0};
        uint64_t l_mirror_sizes_ack[4] = {0};

        // base addresses for distinct non-mirrored ranges
        mem_bases[0] = i_groupData.iv_data[0][BASE_ADDR];
        mem_bases[1] = i_groupData.iv_data[1][BASE_ADDR];
        mem_bases[2] = i_groupData.iv_data[2][BASE_ADDR];
        mem_bases[3] = i_groupData.iv_data[3][BASE_ADDR];
        mem_bases[4] = i_groupData.iv_data[4][BASE_ADDR];
        mem_bases[5] = i_groupData.iv_data[5][BASE_ADDR];
        mem_bases[6] = i_groupData.iv_data[6][BASE_ADDR];
        mem_bases[7] = i_groupData.iv_data[7][BASE_ADDR];
        mem_bases_ack[0] = i_groupData.iv_data[0][BASE_ADDR];
        mem_bases_ack[1] = i_groupData.iv_data[1][BASE_ADDR];
        mem_bases_ack[2] = i_groupData.iv_data[2][BASE_ADDR];
        mem_bases_ack[3] = i_groupData.iv_data[3][BASE_ADDR];
        mem_bases_ack[4] = i_groupData.iv_data[4][BASE_ADDR];
        mem_bases_ack[5] = i_groupData.iv_data[5][BASE_ADDR];
        mem_bases_ack[6] = i_groupData.iv_data[6][BASE_ADDR];
        mem_bases_ack[7] = i_groupData.iv_data[7][BASE_ADDR];

        // Base size modified for selective mode to do better packing memory
        // which helps to do bare metal exerciser memory stressing
        if (i_sysAttrs.iv_selectiveMode ==
            fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
        {
            l_memory_sizes[0] = i_groupData.iv_data[0][GROUP_SIZE] / 2;
            l_memory_sizes[1] = i_groupData.iv_data[1][GROUP_SIZE] / 2;
            l_memory_sizes[2] = i_groupData.iv_data[2][GROUP_SIZE] / 2;
            l_memory_sizes[3] = i_groupData.iv_data[3][GROUP_SIZE] / 2;
            l_memory_sizes[4] = i_groupData.iv_data[4][GROUP_SIZE] / 2;
            l_memory_sizes[5] = i_groupData.iv_data[5][GROUP_SIZE] / 2;
            l_memory_sizes[6] = i_groupData.iv_data[6][GROUP_SIZE] / 2;
            l_memory_sizes[7] = i_groupData.iv_data[7][GROUP_SIZE] / 2;
        }
        else
        {
            // sizes for distinct non-mirrored ranges
            l_memory_sizes[0] = i_groupData.iv_data[0][MCS_SIZE]
                * i_groupData.iv_data[0][MCS_IN_GROUP];
            l_memory_sizes[1] = i_groupData.iv_data[1][MCS_SIZE]
                * i_groupData.iv_data[1][MCS_IN_GROUP];
            l_memory_sizes[2] = i_groupData.iv_data[2][MCS_SIZE]
                * i_groupData.iv_data[2][MCS_IN_GROUP];
            l_memory_sizes[3] = i_groupData.iv_data[3][MCS_SIZE]
                * i_groupData.iv_data[3][MCS_IN_GROUP];
            l_memory_sizes[4] = i_groupData.iv_data[4][MCS_SIZE]
                * i_groupData.iv_data[4][MCS_IN_GROUP];
            l_memory_sizes[5] = i_groupData.iv_data[5][MCS_SIZE]
                * i_groupData.iv_data[5][MCS_IN_GROUP];
            l_memory_sizes[6] = i_groupData.iv_data[6][MCS_SIZE]
                * i_groupData.iv_data[6][MCS_IN_GROUP];
            l_memory_sizes[7] = i_groupData.iv_data[7][MCS_SIZE]
                * i_groupData.iv_data[7][MCS_IN_GROUP];
        }

        l_memory_sizes_ack[0] = i_groupData.iv_data[0][GROUP_SIZE];
        l_memory_sizes_ack[1] = i_groupData.iv_data[1][GROUP_SIZE];
        l_memory_sizes_ack[2] = i_groupData.iv_data[2][GROUP_SIZE];
        l_memory_sizes_ack[3] = i_groupData.iv_data[3][GROUP_SIZE];
        l_memory_sizes_ack[4] = i_groupData.iv_data[4][GROUP_SIZE];
        l_memory_sizes_ack[5] = i_groupData.iv_data[5][GROUP_SIZE];
        l_memory_sizes_ack[6] = i_groupData.iv_data[6][GROUP_SIZE];
        l_memory_sizes_ack[7] = i_groupData.iv_data[7][GROUP_SIZE];

        if (!i_sysAttrs.iv_enhancedNoMirrorMode)
        {
            // Process mirrored ranges
            if (i_sysAttrs.iv_selectiveMode ==
                fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                uint8_t groupcount = 0;
                for (uint8_t i = 0; i < NUM_MCS_PER_PROC; i++)
                {
                    if (i_groupData.iv_data[i][GROUP_SIZE] > 1)
                    {
                        groupcount++;
                    }
                }
                if (groupcount < 7)
                {
                    mem_bases[groupcount + 0] =
                        i_groupData.iv_data[8][BASE_ADDR] +
                            (i_groupData.iv_data[8][GROUP_SIZE] / 2);
                    mem_bases[groupcount + 1] =
                        i_groupData.iv_data[9][BASE_ADDR] +
                            (i_groupData.iv_data[9][GROUP_SIZE] / 2);
                    mem_bases[groupcount + 2] =
                        i_groupData.iv_data[10][BASE_ADDR] +
                            (i_groupData.iv_data[10][GROUP_SIZE] / 2);
                    mem_bases[groupcount + 3] =
                        i_groupData.iv_data[11][BASE_ADDR] +
                            (i_groupData.iv_data[11][GROUP_SIZE] / 2);
                }

                // Selective mode - Mirroring will be moved in non-mirroring
                // space virutally
                mirror_bases[0] = 0;
                mirror_bases[1] = 0;
                mirror_bases[2] = 0;
                mirror_bases[3] = 0;
            }
            else
            {
                // base addresses for distinct mirrored ranges
                mirror_bases[0] = i_groupData.iv_data[8][BASE_ADDR];
                mirror_bases[1] = i_groupData.iv_data[9][BASE_ADDR];
                mirror_bases[2] = i_groupData.iv_data[10][BASE_ADDR];
                mirror_bases[3] = i_groupData.iv_data[11][BASE_ADDR];
            }
            mirror_bases_ack[0] = i_groupData.iv_data[8][BASE_ADDR];
            mirror_bases_ack[1] = i_groupData.iv_data[9][BASE_ADDR];
            mirror_bases_ack[2] = i_groupData.iv_data[10][BASE_ADDR];
            mirror_bases_ack[3] = i_groupData.iv_data[11][BASE_ADDR];

            if (i_sysAttrs.iv_selectiveMode ==
                fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                uint8_t groupcount = 0;
                for (uint8_t i = 0; i < NUM_MCS_PER_PROC; i++)
                {
                    if (i_groupData.iv_data[i][MCS_IN_GROUP] > 1)
                    {
                        groupcount++;
                    }
                }
                if (groupcount < 7)
                {
                    l_memory_sizes[groupcount + 0] =
                        i_groupData.iv_data[8][GROUP_SIZE] / 2;
                    l_memory_sizes[groupcount + 1] =
                        i_groupData.iv_data[9][GROUP_SIZE] / 2;
                    l_memory_sizes[groupcount + 2] =
                        i_groupData.iv_data[10][GROUP_SIZE] / 2;
                    l_memory_sizes[groupcount + 3] =
                        i_groupData.iv_data[11][GROUP_SIZE] / 2;
                }
                l_mirror_sizes[0] = 0;
                l_mirror_sizes[1] = 0;
                l_mirror_sizes[2] = 0;
                l_mirror_sizes[3] = 0;
            }
            else
            {
                // sizes for distinct mirrored ranges
                for (uint8_t i = 0; i < 4; i++)
                {
                    if (i_groupData.iv_data[i][MCS_IN_GROUP] > 1)
                    {
                        l_mirror_sizes[i] =
                            (i_groupData.iv_data[i][MCS_SIZE] *
                             i_groupData.iv_data[0][MCS_IN_GROUP]) / 2;
                    }
                    else
                    {
                        l_mirror_sizes[i] = 0;
                    }
                }
            }
            l_mirror_sizes_ack[0] = i_groupData.iv_data[8][GROUP_SIZE];
            l_mirror_sizes_ack[1] = i_groupData.iv_data[9][GROUP_SIZE];
            l_mirror_sizes_ack[2] = i_groupData.iv_data[10][GROUP_SIZE];
            l_mirror_sizes_ack[3] = i_groupData.iv_data[11][GROUP_SIZE];
        }

        mem_bases[0] = mem_bases[0] << 30;
        mem_bases[1] = mem_bases[1] << 30;
        mem_bases[2] = mem_bases[2] << 30;
        mem_bases[3] = mem_bases[3] << 30;
        mem_bases[4] = mem_bases[4] << 30;
        mem_bases[5] = mem_bases[5] << 30;
        mem_bases[6] = mem_bases[6] << 30;
        mem_bases[7] = mem_bases[7] << 30;
        mem_bases_ack[0] = mem_bases_ack[0] << 30;
        mem_bases_ack[1] = mem_bases_ack[1] << 30;
        mem_bases_ack[2] = mem_bases_ack[2] << 30;
        mem_bases_ack[3] = mem_bases_ack[3] << 30;
        mem_bases_ack[4] = mem_bases_ack[4] << 30;
        mem_bases_ack[5] = mem_bases_ack[5] << 30;
        mem_bases_ack[6] = mem_bases_ack[6] << 30;
        mem_bases_ack[7] = mem_bases_ack[7] << 30;
        l_memory_sizes[0] = l_memory_sizes[0] << 30;
        l_memory_sizes[1] = l_memory_sizes[1] << 30;
        l_memory_sizes[2] = l_memory_sizes[2] << 30;
        l_memory_sizes[3] = l_memory_sizes[3] << 30;
        l_memory_sizes[4] = l_memory_sizes[4] << 30;
        l_memory_sizes[5] = l_memory_sizes[5] << 30;
        l_memory_sizes[6] = l_memory_sizes[6] << 30;
        l_memory_sizes[7] = l_memory_sizes[7] << 30;
        l_memory_sizes_ack[0] = l_memory_sizes_ack[0] << 30;
        l_memory_sizes_ack[1] = l_memory_sizes_ack[1] << 30;
        l_memory_sizes_ack[2] = l_memory_sizes_ack[2] << 30;
        l_memory_sizes_ack[3] = l_memory_sizes_ack[3] << 30;
        l_memory_sizes_ack[4] = l_memory_sizes_ack[4] << 30;
        l_memory_sizes_ack[5] = l_memory_sizes_ack[5] << 30;
        l_memory_sizes_ack[6] = l_memory_sizes_ack[6] << 30;
        l_memory_sizes_ack[7] = l_memory_sizes_ack[7] << 30;

        if (!i_sysAttrs.iv_enhancedNoMirrorMode)
        {
            mirror_bases[0] = mirror_bases[0] << 30;
            mirror_bases[1] = mirror_bases[1] << 30;
            mirror_bases[2] = mirror_bases[2] << 30;
            mirror_bases[3] = mirror_bases[3] << 30;
            mirror_bases_ack[0] = mirror_bases_ack[0] << 30;
            mirror_bases_ack[1] = mirror_bases_ack[1] << 30;
            mirror_bases_ack[2] = mirror_bases_ack[2] << 30;
            mirror_bases_ack[3] = mirror_bases_ack[3] << 30;
            l_mirror_sizes[0] = l_mirror_sizes[0] << 30;
            l_mirror_sizes[1] = l_mirror_sizes[1] << 30;
            l_mirror_sizes[2] = l_mirror_sizes[2] << 30;
            l_mirror_sizes[3] = l_mirror_sizes[3] << 30;
            FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[0]: 0x%016llx", l_mirror_sizes[0]);
            FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[1]: 0x%016llx", l_mirror_sizes[1]);
            FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[2]: 0x%016llx", l_mirror_sizes[2]);
            FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[3]: 0x%016llx", l_mirror_sizes[3]);
            l_mirror_sizes_ack[0] = l_mirror_sizes_ack[0] << 30;
            l_mirror_sizes_ack[1] = l_mirror_sizes_ack[1] << 30;
            l_mirror_sizes_ack[2] = l_mirror_sizes_ack[2] << 30;
            l_mirror_sizes_ack[3] = l_mirror_sizes_ack[3] << 30;
        }

        //------------------------------------------------------------------
        // Defining HTM and OCC base address based on HTM/OCC bar size
        //------------------------------------------------------------------
        if ((i_sysAttrs.iv_selectiveMode ==
             fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) ||
            (i_sysAttrs.iv_selectiveMode ==
             fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER))
        {
            uint64_t total_size = 0;
            uint8_t memhole = 0;
            for (uint8_t i = 0; i < 8; i++)
            {
                total_size += l_memory_sizes[i];
                if (i_groupData.iv_data[i][ALT_VALID])
                {
                    memhole++;
                }
            }
            if ((total_size >=
                 (io_procAttrs.iv_htmBarSize +
                  io_procAttrs.iv_occSandboxSize)) &&
                ((io_procAttrs.iv_htmBarSize +
                  io_procAttrs.iv_occSandboxSize) > 0))
            {
                uint64_t other_bar_size = io_procAttrs.iv_htmBarSize +
                                          io_procAttrs.iv_occSandboxSize;
                uint64_t non_mirroring_size = total_size - other_bar_size;
                uint64_t temp_size = 0;
                uint8_t done = 0;
                uint8_t j = 0;
                uint8_t i = 0;
                while (!done)
                {
                    if ((temp_size <= non_mirroring_size) &&
                        (non_mirroring_size <=
                            (temp_size += l_memory_sizes[i++])))
                    {
                        done = 1;
                    }
                }
                j = i;

                if (memhole)
                {
                    if (l_memory_sizes[j - 1] < other_bar_size)
                    {
                        FAPI_ERR("mss_eff_grouping: Memory HTM/OCC BAR not "
                                 "possible (normal), Total Memory 0x%016llx",
                                 l_memory_sizes[j - 1]);
                        const uint64_t TOTAL_SIZE = l_memory_sizes[j - 1];
                        const uint64_t & HTM_BAR_SIZE =
                            io_procAttrs.iv_htmBarSize;
                        const uint64_t & OCC_SANDBOX_BAR_SIZE =
                            io_procAttrs.iv_occSandboxSize;
                        const uint8_t & MIRROR_PLACEMENT_POLICY =
                            i_sysAttrs.iv_selectiveMode;
                        FAPI_SET_HWP_ERROR(rc,
                            RC_MSS_EFF_GROUPING_HTM_OCC_BAR_NOT_POSSIBLE);
                        break;
                    }
                    else
                    {
                        l_memory_sizes[i - 1] = l_memory_sizes[i - 1]
                            - (temp_size - non_mirroring_size);
                    }
                }
                else
                {
                    l_memory_sizes[i - 1] = l_memory_sizes[i - 1] - (temp_size
                        - non_mirroring_size);
                    for (; i < 8; i++)
                    {
                        if (l_memory_sizes[i])
                        {
                            l_memory_sizes[i] = 0;
                        }
                    }
                }
                if (io_procAttrs.iv_htmBarSize < io_procAttrs.iv_occSandboxSize)
                {
                    occ_sandbox_base = mem_bases[j - 1] + l_memory_sizes[j - 1];
                    htm_bar_base = occ_sandbox_base +
                        io_procAttrs.iv_occSandboxSize;
                }
                else
                {
                    htm_bar_base = mem_bases[j - 1] + l_memory_sizes[j - 1];
                    occ_sandbox_base = htm_bar_base + io_procAttrs.iv_htmBarSize;
                }
                FAPI_DBG("mss_eff_grouping: TOTAL MEMORY 0x%016llx", total_size);
                if (!i_sysAttrs.iv_enhancedNoMirrorMode)
                {
                    FAPI_DBG("mss_eff_grouping: MIRRORING SIZE: 0x%016llx & %d",
                             l_mirror_sizes[j - 1], j);
                    FAPI_DBG("mss_eff_grouping: Required MIRRORING SIZE: 0x%016llx ",
                             non_mirroring_size);
                }
                FAPI_DBG("mss_eff_grouping: HTM_BASE : 0x%016llx", htm_bar_base);
                FAPI_DBG("mss_eff_grouping: OCC_BASE : 0x%016llx",
                         occ_sandbox_base);
            }
            else if ((total_size >=
                     (io_procAttrs.iv_htmBarSize +
                      io_procAttrs.iv_occSandboxSize)) &&
                     ((io_procAttrs.iv_htmBarSize +
                       io_procAttrs.iv_occSandboxSize) == 0))
            {
            }
            else
            {
                FAPI_ERR("mss_eff_grouping: Required memory space for the HTM "
                         "and OCC SANDBOX BARS is not available (normal). "
                         "Total Size 0x%016llx", total_size);
                const uint64_t TOTAL_SIZE = total_size;
                const uint64_t & HTM_BAR_SIZE = io_procAttrs.iv_htmBarSize;
                const uint64_t & OCC_SANDBOX_BAR_SIZE =
                    io_procAttrs.iv_occSandboxSize;
                const uint8_t & MIRROR_PLACEMENT_POLICY =
                    i_sysAttrs.iv_selectiveMode;
                FAPI_SET_HWP_ERROR(rc,
                    RC_MSS_EFF_GROUPING_NO_SPACE_FOR_HTM_OCC_BAR);
                break;
            }
        }
        else if ((i_sysAttrs.iv_selectiveMode ==
                 fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED) ||
                 (i_sysAttrs.iv_selectiveMode ==
                 fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER))
        {
            uint64_t total_size = 0;
            uint8_t memhole = 0;
            uint8_t j = 0;
            for (uint8_t i = 0; i < 4; i++)
            {
                total_size += l_mirror_sizes[i];
                if (i_groupData.iv_data[i][ALT_VALID])
                {
                    memhole++;
                }
            }

            if ((total_size >=
                 (io_procAttrs.iv_htmBarSize + io_procAttrs.iv_occSandboxSize)) &&
                ((io_procAttrs.iv_htmBarSize + io_procAttrs.iv_occSandboxSize) >
                 0))
            {
                uint64_t other_bar_size = 0;
                other_bar_size = io_procAttrs.iv_htmBarSize +
                    io_procAttrs.iv_occSandboxSize;
                uint64_t non_mirroring_size = total_size - other_bar_size;
                uint64_t temp_size = 0;
                uint8_t done = 0;
                uint8_t i = 0;
                while (!done)
                {
                    if ((temp_size <= non_mirroring_size)
                        && (non_mirroring_size <= (temp_size
                            += l_mirror_sizes[i++])))
                    {
                        done = 1;
                    }
                }
                j = i;
                if (memhole)
                {
                    if (l_mirror_sizes[j - 1] < other_bar_size)
                    {
                        FAPI_ERR("mss_eff_grouping: Memory HTM/OCC BAR not "
                                 "possible (flipped), Total Memory 0x%016llx",
                                 l_memory_sizes[j - 1]);
                        const uint64_t TOTAL_SIZE = l_memory_sizes[j - 1];
                        const uint64_t & HTM_BAR_SIZE =
                            io_procAttrs.iv_htmBarSize;
                        const uint64_t & OCC_SANDBOX_BAR_SIZE =
                            io_procAttrs.iv_occSandboxSize;
                        const uint8_t & MIRROR_PLACEMENT_POLICY =
                            i_sysAttrs.iv_selectiveMode;
                        FAPI_SET_HWP_ERROR(rc,
                            RC_MSS_EFF_GROUPING_HTM_OCC_BAR_NOT_POSSIBLE);
                        break;
                    }
                    else
                    {
                        l_mirror_sizes[i - 1] = l_mirror_sizes[i - 1]
                            - (temp_size - non_mirroring_size);
                    }
                }
                else
                {
                    l_mirror_sizes[i - 1] = l_mirror_sizes[i - 1] - (temp_size
                        - non_mirroring_size);
                    for (; i < 8; i++)
                    {
                        if (l_memory_sizes[i])
                            l_memory_sizes[i] = 0;
                    }
                }
                if (io_procAttrs.iv_htmBarSize < io_procAttrs.iv_occSandboxSize)
                {
                    occ_sandbox_base = mirror_bases[j - 1] +
                        l_mirror_sizes[j - 1];
                    io_procAttrs.iv_htmBarSize =
                        occ_sandbox_base + io_procAttrs.iv_occSandboxSize;
                }
                else
                {
                    htm_bar_base = mirror_bases[j - 1] + l_mirror_sizes[j - 1];
                    occ_sandbox_base = htm_bar_base + io_procAttrs.iv_htmBarSize;
                }
                FAPI_DBG(" TOTAL MEMORY 0x%016llx", total_size);
                FAPI_DBG("  MIRRORING SIZE: 0x%016llx & %d",
                         l_mirror_sizes[j - 1], j);
                FAPI_DBG("  Required MIRRORING SIZE: 0x%016llx ",
                         non_mirroring_size);
                FAPI_DBG("  HTM_BASE : 0x%016llx", htm_bar_base);
                FAPI_DBG("  OCC_BASE : 0x%016llx", occ_sandbox_base);
            }
            else if ((total_size >=
                (io_procAttrs.iv_htmBarSize + io_procAttrs.iv_occSandboxSize)) &&
                ((io_procAttrs.iv_htmBarSize + io_procAttrs.iv_occSandboxSize) == 0))
            {
            }
            else
            {
                FAPI_ERR("mss_eff_grouping: Required memory space for the HTM "
                         "and OCC SANDBOX BARS is not available (flipped). "
                         "Total Size 0x%016llx", total_size);
                const uint64_t TOTAL_SIZE = total_size;
                const uint64_t & HTM_BAR_SIZE = io_procAttrs.iv_htmBarSize;
                const uint64_t & OCC_SANDBOX_BAR_SIZE =
                    io_procAttrs.iv_occSandboxSize;
                const uint8_t & MIRROR_PLACEMENT_POLICY =
                    i_sysAttrs.iv_selectiveMode;
                FAPI_SET_HWP_ERROR(rc,
                    RC_MSS_EFF_GROUPING_NO_SPACE_FOR_HTM_OCC_BAR);
                break;
            }
        }

        //----------------------------------------------------------------------
        //  Setting up Calculated Attributes
        //----------------------------------------------------------------------
        for (uint8_t i = 0; i < 8; i++)
        {
            FAPI_INF("mss_eff_grouping: ATTR_PROC_MEM_BASES[%u]: 0x%016llx",
                     i, mem_bases[i]);
        }
        rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASES, &i_target, mem_bases);
        if (rc)
        {
            FAPI_ERR("Error writing ATTR_PROC_MEM_BASES");
            break;
        }

        for (uint8_t i = 0; i < 8; i++)
        {
            FAPI_INF("mss_eff_grouping: ATTR_PROC_MEM_BASES_ACK[%u]: 0x%016llx",
                     i, mem_bases_ack[i]);
        }
        rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASES_ACK, &i_target, mem_bases_ack);
        if (rc)
        {
            FAPI_ERR("Error writing ATTR_PROC_MEM_BASES_ACK");
            break;
        }

        for (uint8_t i = 0; i < 8; i++)
        {
            FAPI_INF("mss_eff_grouping: ATTR_PROC_MEM_SIZES[%u]: 0x%016llx",
                     i, l_memory_sizes[i]);
        }
        rc = FAPI_ATTR_SET(ATTR_PROC_MEM_SIZES, &i_target, l_memory_sizes);
        if (rc)
        {
            FAPI_ERR("Error writing ATTR_PROC_MEM_SIZES");
            break;
        }

        for (uint8_t i = 0; i < 8; i++)
        {
            FAPI_INF("mss_eff_grouping: ATTR_PROC_MEM_SIZES_ACK[%u]: 0x%016llx",
                     i, l_memory_sizes_ack[i]);
        }
        rc = FAPI_ATTR_SET(ATTR_PROC_MEM_SIZES_ACK, &i_target,
                           l_memory_sizes_ack);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error writing ATTR_PROC_MEM_SIZES_ACK");
            break;
        }

        rc = FAPI_ATTR_SET(ATTR_MSS_MCS_GROUP_32, &i_target,
                           i_groupData.iv_data);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error writing ATTR_MSS_MCS_GROUP");
            break;
        }

        if (!i_sysAttrs.iv_enhancedNoMirrorMode)
        {
            for (uint8_t i = 0; i < 4; i++)
            {
                FAPI_INF("mss_eff_grouping: ATTR_PROC_MIRROR_BASES[%u]: "
                         "0x%016llx", i, mirror_bases[i]);
            }
            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASES, &i_target, mirror_bases);
            if (rc)
            {
                FAPI_ERR("Error writing ATTR_PROC_MIRROR_BASES");
                break;
            }

            for (uint8_t i = 0; i < 4; i++)
            {
                FAPI_INF("mss_eff_grouping: ATTR_PROC_MIRROR_BASES_ACK[%u]: "
                         "0x%016llx", i, mirror_bases_ack[i]);
            }
            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASES_ACK, &i_target,
                               mirror_bases_ack);
            if (!rc.ok())
            {
                FAPI_ERR("Error writing ATTR_PROC_MIRROR_BASES_ACK");
                break;
            }

            for (uint8_t i = 0; i < 4; i++)
            {
                FAPI_INF("mss_eff_grouping: ATTR_PROC_MIRROR_SIZES[%u]: "
                         "0x%016llx", i, l_mirror_sizes[i]);
            }
            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_SIZES, &i_target,
                               l_mirror_sizes);
            if (rc)
            {
                FAPI_ERR("Error writing ATTR_PROC_MIRROR_SIZES");
                break;
            }

            for (uint8_t i = 0; i < 4; i++)
            {
                FAPI_INF("mss_eff_grouping: ATTR_PROC_MIRROR_SIZES_ACK[%u]: "
                         "0x%016llx", i, l_mirror_sizes_ack[i]);
            }
            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_SIZES_ACK, &i_target,
                               l_mirror_sizes_ack);
            if (rc)
            {
                FAPI_ERR("Error writing ATTR_PROC_MIRROR_SIZES_ACK");
                break;
            }
        }

        FAPI_INF("mss_eff_grouping: ATTR_PROC_HTM_BAR_BASE_ADDR: 0x%016llx",
                 htm_bar_base);
        rc = FAPI_ATTR_SET(ATTR_PROC_HTM_BAR_BASE_ADDR, &i_target,
                            htm_bar_base);
        if (rc)
        {
            FAPI_ERR("Error writing ATTR_PROC_HTM_BAR_BASE_ADDR");
            break;
        }

        FAPI_INF("mss_eff_grouping: ATTR_PROC_OCC_SANDBOX_BASE_ADDR: 0x%016llx",
                 occ_sandbox_base);
        rc = FAPI_ATTR_SET(ATTR_PROC_OCC_SANDBOX_BASE_ADDR, &i_target,
                           occ_sandbox_base);
        if (rc)
        {
            FAPI_ERR("Error writing  ATTR_PROC_OCC_SANDBOX_BASE_ADDR");
            break;
        }
    } while (0);

    return rc;
}

//------------------------------------------------------------------------------
// mss_eff_grouping HW Procedure
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_grouping(const fapi::Target & i_target,
    std::vector<fapi::Target> &i_associated_centaurs)
{
    fapi::ReturnCode rc;
    FAPI_INF("mss_eff_grouping: Start, chip %s", i_target.toEcmdString());

    do
    {
        // Fill in the EffGroupingMemInfo structure with memory information
        EffGroupingMemInfo memInfo;
        rc = memInfo.getMemInfo(i_associated_centaurs);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error getting mem info");
            break;
        }

        // Get the necessary system attributes
        EffGroupingSysAttrs sysAttrs;
        rc = sysAttrs.getAttrs();
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error getting system attributes");
            break;
        }

        // Get the necessary processor chip attributes
        EffGroupingProcAttrs procAttrs;
        rc = procAttrs.getAttrs(i_target);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error getting proc chip attributes");
            break;
        }

        // Check that the system and processor chip attributes are valid
        rc = grouping_checkValidAttributes(sysAttrs, procAttrs);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error validating sys/proc attributes");
            break;
        }

        // Create a EffGroupingData structure
        EffGroupingData groupData;

        // Attempt to Group the MCSs. All of the grouping functions are called
        // if allowed, if MCSs cannot be grouped by one function they may be
        // grouped by the subsequent functions
        if (procAttrs.iv_groupsAllowed & MCS_GROUP_8)
        {
            grouping_group8McsPerGroup(memInfo, groupData);
        }
        if (procAttrs.iv_groupsAllowed & MCS_GROUP_4)
        {
            grouping_group4McsPerGroup(memInfo, groupData);
        }
        if (procAttrs.iv_groupsAllowed & MCS_GROUP_2)
        {
            grouping_group2McsPerGroup(memInfo, groupData);
        }
        if (procAttrs.iv_groupsAllowed & MCS_GROUP_1)
        {
            // Note that grouping_checkValidAttributes() ensures that this is
            // only in checkerboard mode
            grouping_group1McsPerGroup(memInfo, groupData);
        }

        // Find the ungrouped MCSs and deconfigure their associated membuf chips
        rc = grouping_findUngroupedMCSs(memInfo, groupData);
        if (rc)
        {
            // Ungrouped MCSs were found, return the error
            FAPI_ERR("mss_eff_grouping: Error from grouping_findUngroupedMCSs");
            break;
        }

        // Calculate Alt Memory
        grouping_calcAltMemory(groupData);

        // Sort Groups from high memory size to low
        grouping_sortGroups(groupData);

        // Calculate the total non mirrored size
        for (uint8_t pos = 0; pos < groupData.iv_numGroups; pos++)
        {
            groupData.iv_totalSizeNonMirr += groupData.iv_data[pos][GROUP_SIZE];
        }
        FAPI_INF("mss_eff_grouping: Total non-mirrored size %u GB",
                 groupData.iv_totalSizeNonMirr);

        if (!sysAttrs.iv_enhancedNoMirrorMode)
        {
            // Calculate base and alt-base addresses
            rc = grouping_calcMirrorMemory(i_target, procAttrs, groupData);
            if (rc)
            {
                FAPI_ERR("mss_eff_grouping: Error from grouping_calcMirrorMemory");
                break;
            }
        }
        else
        {
            // ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING is true
            // Calculate base and alt-base addresses
            grouping_calcNonMirrorMemory(procAttrs, groupData);
        }

        // Set the ATTR_MSS_MEM_MC_IN_GROUP attribute
        rc = grouping_setATTR_MSS_MEM_MC_IN_GROUP(i_target, groupData);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error from grouping_setATTR_MSS_MEM_MC_IN_GROUP");
            break;
        }

        // Trace a summary of the Grouping Data
        grouping_traceData(sysAttrs, groupData);

        // Set Memory Base and Size FAPI Attributes
        rc = grouping_setBaseSizeAttrs(i_target, sysAttrs, procAttrs,
                                       groupData);
        if (rc)
        {
            FAPI_ERR("mss_eff_grouping: Error from grouping_setBaseSizeAttrs");
            break;
        }
    } while (0);

    FAPI_INF("mss_eff_grouping: End");
    return rc;
}

} //end extern C
