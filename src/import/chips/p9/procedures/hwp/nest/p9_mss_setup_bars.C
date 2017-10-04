/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_mss_setup_bars.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// ----------------------------------------------------------------------------
/// @file  p9_mss_setup_bars.H
///
/// @brief  Program memory controller base address registers (BARs)
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 3
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_mss_setup_bars.H>
#include <p9_mss_eff_grouping.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <map>
#include <generic/memory/lib/utils/memory_size.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------
const uint8_t MAX_MC_PORTS_PER_MCS = 2;        // 2 MC ports per MCS
const uint8_t NO_CHANNEL_PER_GROUP = 0xFF;     // Init value of channel per group

///----------------------------------------------------------------------------
/// Data structure definitions
///----------------------------------------------------------------------------

///
/// @struct channel_per_group_t
/// @brief Table of Channel Per Group value in MCFGP reg based on
///        the # of ports in group of ports 0 and 1 of an MCS.
///
static const struct channelPerGroupTable_t
{
    uint8_t port0_ports_in_group;
    uint8_t port1_ports_in_group;
    uint8_t channel_per_group;

} CHANNEL_PER_GROUP_TABLE[] =
{
    // Port 0    Port 1    Channel/group value
    {    1,         1,           0b0000    },      // 1 MC port/group for both port0 and port1
    {    1,         3,           0b0001    },      // 1 MC port/group for port0, 3 MC port/group for port1
    {    2,         1,           0b0100    },      // 2 MC port/group different MC port pairs
    {    3,         1,           0b0010    },      // 3 MC port/group for port0, 1 MC port/group for port1
    {    3,         3,           0b0011    },      // 3 MC port/group for port0, 3 MC port/group for port1
    {    2,         2,           0b0101    },      // 2 MC port/group in the same MC port pairs (Need additional verification in code below)
    {    2,         3,           0b0100    },      // 2 MC port/group different MC port pairs
    {    1,         2,           0b0100    },      // 2 MC port/group different MC port pairs
    {    3,         2,           0b0100    },      // 2 MC port/group different MC port pairs
    {    4,         4,           0b0110    },      // 4 MC ports/group, two ports in the same MC pairs
    {    6,         6,           0b0111    },      // 6 MC ports/group, two ports in the same MC pairs
    {    8,         8,           0b1000    },      // 8 MC ports/group, two ports in the same MC pairs
};


///
/// @struct group_size_t
/// @brief Table that determines MCFGP/MCFGPM bits 13:23 based on the group size.
///
static const struct groupSizeTable_t
{
    // System attributes
    uint32_t groupSize;
    uint32_t encodedGroupSize;

} GROUP_SIZE_TABLE[] =
{
    // GroupSize  Encoded GroupSize
    {    4,        0b00000000000    },      //    4 GB
    {    8,        0b00000000001    },      //    8 GB
    {   16,        0b00000000011    },      //   16 GB
    {   32,        0b00000000111    },      //   32 GB
    {   64,        0b00000001111    },      //   64 GB
    {  128,        0b00000011111    },      //  128 GB
    {  256,        0b00000111111    },      //  256 GB
    {  512,        0b00001111111    },      //  512 GB
    { 1024,        0b00011111111    },      //    1 TB
    { 2048,        0b00111111111    },      //    2 TB
    { 4096,        0b01111111111    },      //    4 TB
};

/**
 * @struct mcPortGroupInfo_t
 *
 * Contains group data information related to a port (MCA/DMI).
 * This information is used to determine the channel per group
 * value for the MCFGP reg.
 *
 */
struct mcPortGroupInfo_t
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    inline mcPortGroupInfo_t()
        : myGroup(0), numPortsInGroup(0), groupSize(0), groupBaseAddr(0),
          channelId(0)
    {
        memset(altMemValid, 0, sizeof(altMemValid));
        memset(altMemSize, 0, sizeof(altMemSize));
        memset(altBaseAddr, 0, sizeof(altBaseAddr));
    }
    // The group number which this port belongs to
    uint8_t myGroup;
    // # of ports in the group which this port belongs to.
    uint8_t numPortsInGroup;
    // The size of the group which this port belongs to
    uint32_t groupSize;
    // The base address of the group which this port belongs to
    uint32_t groupBaseAddr;
    // The group member ID of this port
    uint8_t channelId;

    // ALT_MEM
    uint8_t altMemValid[NUM_OF_ALT_MEM_REGIONS];
    uint32_t altMemSize[NUM_OF_ALT_MEM_REGIONS];
    uint32_t altBaseAddr[NUM_OF_ALT_MEM_REGIONS];
};

/**
 * @struct mcBarData_t
 *
 * Contains BAR data info for a Memory Controller (MCS/MI)
 */
struct mcBarData_t
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    inline mcBarData_t()
        : MCFGP_valid(false), MCFGP_chan_per_group(0),
          MCFGP_chan0_group_member_id(0), MCFGP_chan1_group_member_id(0),
          MCFGP_group_size(0), MCFGP_groupBaseAddr(0),
          MCFGPM_valid(false), MCFGPM_group_size(0), MCFGPM_groupBaseAddr(0)
    {
        memset(MCFGPA_HOLE_valid, 0, sizeof(MCFGPA_HOLE_valid));
        memset(MCFGPA_HOLE_LOWER_addr, 0, sizeof(MCFGPA_HOLE_LOWER_addr));
        memset(MCFGPA_HOLE_UPPER_addr, 0, sizeof(MCFGPA_HOLE_UPPER_addr));

        memset(MCFGPMA_HOLE_valid, 0, sizeof(MCFGPMA_HOLE_valid));
        memset(MCFGPMA_HOLE_LOWER_addr, 0, sizeof(MCFGPMA_HOLE_LOWER_addr));
        memset(MCFGPMA_HOLE_UPPER_addr, 0, sizeof(MCFGPMA_HOLE_UPPER_addr));
    }

    // Info to program MCFGP reg
    bool     MCFGP_valid;
    uint8_t  MCFGP_chan_per_group;
    uint8_t  MCFGP_chan0_group_member_id;
    uint8_t  MCFGP_chan1_group_member_id;
    uint32_t MCFGP_group_size;
    uint32_t MCFGP_groupBaseAddr;

    // Info to program MCFGPM reg
    bool     MCFGPM_valid;
    uint32_t MCFGPM_group_size;
    uint32_t MCFGPM_groupBaseAddr;

    // Info to program MCFGPA reg
    bool     MCFGPA_HOLE_valid[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPA_HOLE_LOWER_addr[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPA_HOLE_UPPER_addr[NUM_OF_ALT_MEM_REGIONS];

    // Info to program MCFGPMA reg
    bool     MCFGPMA_HOLE_valid[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPMA_HOLE_LOWER_addr[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPMA_HOLE_UPPER_addr[NUM_OF_ALT_MEM_REGIONS];
};

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------
///
/// @brief Get MC(MCS/MI) position for the input PORT_ID
///
///        PORT_ID 0 --> MC 0
///        PORT_ID 1 --> MC 0
///        PORT_ID 2 --> MC 1
///        PORT_ID 3 --> MC 1
///        PORT_ID 4 --> MC 2
///        PORT_ID 5 --> MC 2
///        PORT_ID 6 --> MC 3
///        PORT_ID 7 --> MCS 3
///
/// @param[in]  i_portID      PortID
/// @return MC position
///
uint8_t getMCPosition(uint8_t i_portID)
{
    return (i_portID / 2);
}

///
/// @brief Get the port number (with respect to the MC, 0 or 1) for the
///        input PORT_ID
///
///        PORT_ID 0 --> MCS port 0
///        PORT_ID 1 --> MCS port 1
///        PORT_ID 2 --> MCS port 0
///        PORT_ID 3 --> MCS port 1
///        PORT_ID 4 --> MCS port 0
///        PORT_ID 5 --> MCS port 1
///        PORT_ID 6 --> MCS port 0
///        PORT_ID 7 --> MCS port 1
///
/// @param[in]  i_portID      PortID
/// @return port num
///
uint8_t getMCPortNum(uint8_t i_portID)
{
    uint8_t l_mcPos = getMCPosition(i_portID);
    return (i_portID - (2 * l_mcPos));
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///
/// @brief Get the memory size behind a Memory controller
///        by calling into mss library.
///
/// @param[in]  i_target        MC target (MCS or MI)
/// @param[out] o_mcSize        The total mem size found
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode getMcMemSize(const fapi2::Target<T>& i_target,
                               uint64_t& o_mcSize);

/// MC = MCS (Nimbus)
template<>
fapi2::ReturnCode getMcMemSize(
    const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
    uint64_t& o_mcSize)
{
    FAPI_DBG("Entering");

    // Figure out the amount of memory behind this MCS
    // by adding up all memory from its MCA ports
    auto l_mcaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCA>();
    uint64_t l_mcaSize = 0;

    for (auto l_mca : l_mcaChiplets)
    {
        uint8_t l_mcaPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mca, l_mcaPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get the amount of memory behind this MCA target
        FAPI_TRY(mss::eff_memory_size(l_mca, l_mcaSize),
                 "Error returned from eff_memory_size - MCA, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_INF("MCA %u: Total DIMM size %lu GB", l_mcaPos, l_mcaSize);
        o_mcSize += l_mcaSize;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

/// MC = MI (Cumulus)
template<>
fapi2::ReturnCode getMcMemSize(
    const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
    uint64_t& o_mcSize)
{
    FAPI_DBG("Entering");

    // Figure out the amount of memory behind this MI
    // by adding up all memory from its DMI ports
    auto l_dmiChiplets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();
    uint64_t l_dmiSize = 0;

    for (auto l_dmi : l_dmiChiplets)
    {
        uint8_t l_dmiPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_dmi, l_dmiPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get the amount of memory behind this DMI target
        FAPI_TRY(mss::eff_memory_size(l_dmi, l_dmiSize),
                 "Error returned from eff_memory_size - DMI, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_INF("DMI %u: Total DIMM size %lu GB", l_dmiPos, l_dmiSize);
        o_mcSize += l_dmiSize;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///
/// @brief Calculate the memory size behind a Memory controller
///        from group data.
///
/// @param[in]  i_mcPos         MC position
/// @param[in]  i_groupData     Array of Group data info
/// @param[out] o_portFound     Mark how many time a port is found.
/// @param[out] o_mcSize        The total mem size calculated
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
void getGroupDataMcMemSize(
    uint8_t i_mcPos,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS],
    uint8_t o_portFound[NUM_MC_PORTS_PER_PROC],
    uint64_t& o_mcSize)
{
    FAPI_DBG("Entering");

    // Loop thru non-mirror groups (0-7)
    for (uint8_t l_group = 0; l_group < (DATA_GROUPS / 2); l_group++)
    {
        // Skip empty groups
        if (i_groupData[l_group][GROUP_SIZE] == 0)
        {
            continue;
        }

        // Loop thru the group port member index to determine if the
        // PORT_ID listed belongs to this MCS
        for (uint8_t l_memberIdx = 0;
             l_memberIdx < i_groupData[l_group][PORTS_IN_GROUP]; l_memberIdx++)
        {
            // If the PORT_ID listed belongs to this MC, add the amount
            // of memory behind the port to this MC.
            uint8_t l_mcId = getMCPosition(i_groupData[l_group][MEMBER_IDX(0) +
                                           l_memberIdx]);

            if (l_mcId == i_mcPos)
            {
                o_mcSize += i_groupData[l_group][PORT_SIZE];
                FAPI_INF("getGroupDataMcMemSize - Port %u, DIMM size %lu GB",
                         i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx],
                         i_groupData[l_group][PORT_SIZE]);
                // Increase # of times this PORT_ID is found
                o_portFound[i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]]++;
            }

        } // Port loop

    } // Group loop

    FAPI_DBG("Exit");
    return;
}


///
/// @brief Validate group data received from ATTR_MSS_MCS_GROUP_32
///
/// Perform these verifications:
///   - The memory sizes of MCS/MI in the input group data
///     agrees with with the amount memory currently reported.
///   - An MCA/DMMI port can only appear once in any group.
///
/// @param[in]  i_mcTargets     Vector of reference of MC targets (MCS or MI)
/// @param[in]  i_groupData     Array of Group data info
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode validateGroupData(
    const std::vector< fapi2::Target<T> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS])
{
    FAPI_DBG("Entering");

    uint64_t l_mcSize = 0;
    uint64_t l_mcSizeGroupData = 0;
    uint8_t l_portFound[NUM_MC_PORTS_PER_PROC];

    // Initialize local arrays
    memset(l_portFound, 0, sizeof(l_portFound));

    // Loop thru each MC
    for (auto l_mc : i_mcTargets)
    {
        // Get this MCS unit position
        uint8_t l_mcPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc, l_mcPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_INF("validateGroupData: MC unit pos %d", l_mcPos);

        // Get the memory size behind this MC
        FAPI_TRY(getMcMemSize(l_mc, l_mcSize),
                 "Error returned from getMcMemSize, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get this MC memsize reported in Group data
        getGroupDataMcMemSize(l_mcPos, i_groupData, l_portFound,
                              l_mcSizeGroupData);

        FAPI_DBG("validateGroupData: MemSize %.16lld, Group Memsize %.16lld",
                 l_mcSize, l_mcSizeGroupData);

        // Assert if MC specified in Group data doesn't agree
        // with the amount gets from Memory interface.
        FAPI_ASSERT(l_mcSizeGroupData == l_mcSize,
                    fapi2::MSS_SETUP_BARS_MC_MEMSIZE_DISCREPENCY()
                    .set_TARGET(l_mc)
                    .set_MC_POS(l_mcPos)
                    .set_MEMSIZE_GROUP_DATA(l_mcSizeGroupData)
                    .set_MEMSIZE_REPORTED(l_mcSize),
                    "Error: MCS %u memory discrepancy: Group data size %u, "
                    "Current memory reported %u",
                    l_mcPos, l_mcSizeGroupData, l_mcSize);

    } // MC loop

    // Assert if a PORT_ID is found more than once in any group
    for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
    {
        // Assert if a PORT_ID is found more than once in any group
        FAPI_ASSERT(l_portFound[ii] <= 1,
                    fapi2::MSS_SETUP_BARS_MULTIPLE_GROUP_ERR()
                    .set_PORT_ID(ii)
                    .set_COUNTER(l_portFound[ii]),
                    "Error: PORT_ID %u is grouped multiple times. "
                    "Port %d, Counter %u", ii, l_portFound[ii]);
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Look up table to determine the MCFGP/MCFGPM group size
///        encoded value (bits 13:23).
///
/// @param[in]   i_mcTarget     MC target (MCS/MI)
/// @param[in]   i_groupSize    Group size (in GB)
/// @param[out]  o_value        Encoded value
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode getGroupSizeEncodedValue(
    const fapi2::Target<T>& i_mcTarget,
    const uint32_t i_groupSize,
    uint32_t& o_value)
{
    FAPI_DBG("Entering");

    bool l_sizeFound = false;

    for (uint8_t ii = 0;
         ii < (sizeof(GROUP_SIZE_TABLE) / sizeof(groupSizeTable_t));
         ii++)
    {
        if ( i_groupSize == GROUP_SIZE_TABLE[ii].groupSize)
        {
            o_value = GROUP_SIZE_TABLE[ii].encodedGroupSize;
            l_sizeFound = true;
            break;
        }
    }

    if (l_sizeFound == false)
    {
        uint8_t l_mcPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_mcTarget, l_mcPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        // Assert if can't find Group size in the table
        FAPI_ASSERT( false,
                     fapi2::MSS_SETUP_BARS_INVALID_GROUP_SIZE()
                     .set_MC_TARGET(i_mcTarget)
                     .set_MC_POS(l_mcPos)
                     .set_GROUP_SIZE(i_groupSize),
                     "Error: Can't locate Group size value in GROUP_SIZE_TABLE. "
                     "MC pos: %d, GroupSize %u GB.", l_mcPos, i_groupSize );
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Calculate the BAR data for each MC (MCS/MI) based on group info
///        of port0/1
///
/// @param[in]  i_mcTarget     MC target (MCS/MI)
/// @param[in]  i_portInfo     The port group info
/// @param[in]  o_mcBarData    MC BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode getNonMirrorBarData(const fapi2::Target<T>& i_mcTarget,
                                      const mcPortGroupInfo_t i_portInfo[],
                                      mcBarData_t& o_mcBarData)
{
    FAPI_DBG("Entering");

    // This function assign the MCFGP_MC_CHANNELS_PER_GROUP value
    // to the MC according to the rule listed in the Nimbus/Cumulus workbook.

    // Initialize
    o_mcBarData.MCFGP_chan_per_group = NO_CHANNEL_PER_GROUP;
    o_mcBarData.MCFGP_valid = false;
    o_mcBarData.MCFGPM_valid = false;

    // ----------------------------------------------------
    // Determine data for MCFGP and MCFGPM registers
    // ----------------------------------------------------

    // Channel per group (MCFGP bits 1:4)
    for (uint8_t ii = 0;
         ii < (sizeof(CHANNEL_PER_GROUP_TABLE) / sizeof(channelPerGroupTable_t));
         ii++)
    {
        uint8_t l_port0_lookup_val = i_portInfo[0].numPortsInGroup;
        uint8_t l_port1_lookup_val = i_portInfo[1].numPortsInGroup;

        // If port is disabled, treat as single port.  However, this
        // port will be set invalid in MCFGP reg further below
        //
        if (l_port0_lookup_val == 0)
        {
            l_port0_lookup_val = 1;
        }

        if (l_port1_lookup_val == 0)
        {
            l_port1_lookup_val = 1;
        }

        if ( (l_port0_lookup_val == CHANNEL_PER_GROUP_TABLE[ii].port0_ports_in_group) &&
             (l_port1_lookup_val == CHANNEL_PER_GROUP_TABLE[ii].port1_ports_in_group) )
        {
            o_mcBarData.MCFGP_chan_per_group = CHANNEL_PER_GROUP_TABLE[ii].channel_per_group;
        }
    }

    // Assert if ports 0/1 don't match any entry in table
    FAPI_ASSERT(o_mcBarData.MCFGP_chan_per_group != NO_CHANNEL_PER_GROUP,
                fapi2::MSS_SETUP_BARS_INVALID_PORTS_CONFIG()
                .set_MC_TARGET(i_mcTarget)
                .set_PORT_0_PORTS_IN_GROUP(i_portInfo[0].numPortsInGroup)
                .set_PORT_0_GROUP(i_portInfo[0].myGroup)
                .set_PORT_1_PORTS_IN_GROUP(i_portInfo[1].numPortsInGroup)
                .set_PORT_1_GROUP(i_portInfo[1].myGroup),
                "Error: ports 0/1 config doesn't match any entry in Channel/group table. "
                "Port_0: group %u, ports in group %u, Port_1: group %u, ports in group %u",
                i_portInfo[0].myGroup, i_portInfo[0].numPortsInGroup,
                i_portInfo[1].myGroup, i_portInfo[1].numPortsInGroup);


    // MCFGP valid (MCFGP bit 0)
    if ( i_portInfo[0].numPortsInGroup == 0)
    {
        // Port0 not populated
        o_mcBarData.MCFGP_valid = false;
    }
    else
    {
        // Port0 populated
        o_mcBarData.MCFGP_valid = true;
    }

    // MCFGPM valid (MCFGPM bit 0)
    if ( i_portInfo[1].numPortsInGroup == 0)
    {
        // Port1 not populated
        o_mcBarData.MCFGPM_valid = false;
    }
    else
    {
        // MCFGPM is valid if Channel_per_group < 0b0101
        if (o_mcBarData.MCFGP_chan_per_group < 0b0101)
        {
            o_mcBarData.MCFGPM_valid = true;
        }
        // Determine if MCFGPM valid when Channel_per_group = 0b0101
        else if (o_mcBarData.MCFGP_chan_per_group == 0b0101)
        {
            // Port1 populated, 2 MC/group
            // The table assigns 0b0101 if both ports belong 2 MC port/group,
            // Here, verify that they belong to the same group, if not,
            // re-assign the channel per group to 2 MC/group in different
            // MC port pairs (0b0100)
            if ( i_portInfo[0].myGroup != i_portInfo[1].myGroup )
            {
                o_mcBarData.MCFGP_chan_per_group = 0b0100;
                o_mcBarData.MCFGPM_valid = true;
            }
        }
        // MCFGPM is not valid if Channel_per_group > 0b0101
        // (2,4,6 or 8, and in same MC port pair)
        // This is true because mirroring is not supported on Nimbus.
        // For Cumulus, mirroring will be checked/programmed later
        // in another function.
        else
        {
            o_mcBarData.MCFGPM_valid = false;
        }
    }

    // MCFGP Channel_0 Group member ID (bits 5:7)
    o_mcBarData.MCFGP_chan0_group_member_id = i_portInfo[0].channelId;
    // MCFGP Channel_1 Group member ID (bits 8:10)
    o_mcBarData.MCFGP_chan1_group_member_id = i_portInfo[1].channelId;

    // If MCFGP is valid, set other fields
    if (o_mcBarData.MCFGP_valid == true)
    {
        // MCFGP Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_mcTarget, i_portInfo[0].groupSize,
                                          o_mcBarData.MCFGP_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        o_mcBarData.MCFGP_groupBaseAddr = i_portInfo[0].groupBaseAddr;
    }

    // If MCFGPM is valid, set other fields
    if (o_mcBarData.MCFGPM_valid == true)
    {
        // MCFGPM Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_mcTarget, i_portInfo[1].groupSize,
                                          o_mcBarData.MCFGPM_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        o_mcBarData.MCFGPM_groupBaseAddr = i_portInfo[1].groupBaseAddr;
    }

    // ----------------------------------------------------
    // Determine data for MCFGPA and MCFGPMA registers
    // ----------------------------------------------------

    // Alternate Memory MCFGPA
    for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
    {
        if ( i_portInfo[0].altMemValid[ii] )
        {
            o_mcBarData.MCFGPA_HOLE_valid[ii] = 1;
            o_mcBarData.MCFGPA_HOLE_LOWER_addr[ii] = i_portInfo[0].altBaseAddr[ii];
            o_mcBarData.MCFGPA_HOLE_UPPER_addr[ii] =
                i_portInfo[0].altBaseAddr[ii] + i_portInfo[0].altMemSize[ii];
        }
        else
        {
            o_mcBarData.MCFGPA_HOLE_valid[ii] = 0;
            o_mcBarData.MCFGPA_HOLE_LOWER_addr[ii] = 0;
            o_mcBarData.MCFGPA_HOLE_UPPER_addr[ii] = 0;
        }

        if ( i_portInfo[1].altMemValid[ii] )
        {
            o_mcBarData.MCFGPMA_HOLE_valid[ii] = 1;
            o_mcBarData.MCFGPMA_HOLE_LOWER_addr[ii] = i_portInfo[1].altBaseAddr[ii];
            o_mcBarData.MCFGPMA_HOLE_UPPER_addr[ii] =
                i_portInfo[1].altBaseAddr[ii] + i_portInfo[1].altMemSize[ii];
        }
        else
        {
            o_mcBarData.MCFGPMA_HOLE_valid[ii] = 0;
            o_mcBarData.MCFGPMA_HOLE_LOWER_addr[ii] = 0;
            o_mcBarData.MCFGPMA_HOLE_UPPER_addr[ii] = 0;
        }

    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Calculate the mirror BAR data for each MC based on group info
///        of port0/1
///
/// @param[in]  i_mcTarget     MC target (MCS/MI)
/// @param[in]  i_portInfo     The port group info
/// @param[in]  io_mcBarData   MC BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode getMirrorBarData(const fapi2::Target<T>& i_mcTarget,
                                   const mcPortGroupInfo_t i_portInfo[],
                                   mcBarData_t& io_mcBarData)
{
    FAPI_DBG("Entering");

    // ---------------------------------------------------
    // Build MC register values for mirror groups
    // ---------------------------------------------------

    // Check MCFGP value to see if mirror is possible
    // (See Table 1 of P9 Cumulus Memory Controller Workbook)
    //
    if ( (io_mcBarData.MCFGP_chan_per_group < 0b0101) ||
         (io_mcBarData.MCFGP_chan_per_group > 0b1000) )
    {
        FAPI_IMP("Mirror is not possible with MCFGP = 0x%.8X, NO MIRROR is "
                 "programmed. ", io_mcBarData.MCFGP_chan_per_group);
        goto fapi_try_exit;
    }

    // Set MCFGPM_VALID
    io_mcBarData.MCFGPM_valid = true;

    // ----------------------------------------------------
    // Determine data for MCFGPM register
    // ----------------------------------------------------

    // MCFGPM Group size
    FAPI_TRY(getGroupSizeEncodedValue(i_mcTarget, i_portInfo[1].groupSize,
                                      io_mcBarData.MCFGPM_group_size),
             "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Group base address
    io_mcBarData.MCFGPM_groupBaseAddr = i_portInfo[1].groupBaseAddr;

    // ----------------------------------------------------
    // Determine data for MCFGPMA registers
    // ----------------------------------------------------
    // Alternate Memory MCFGPMA
    for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
    {
        if ( i_portInfo[1].altMemValid[ii] )
        {
            io_mcBarData.MCFGPMA_HOLE_valid[ii] = 1;
            io_mcBarData.MCFGPMA_HOLE_LOWER_addr[ii] =
                i_portInfo[1].altBaseAddr[ii];
            io_mcBarData.MCFGPMA_HOLE_UPPER_addr[ii] =
                i_portInfo[1].altBaseAddr[ii] + i_portInfo[1].altMemSize[ii];
        }
        else
        {
            io_mcBarData.MCFGPMA_HOLE_valid[ii] = 0;
            io_mcBarData.MCFGPMA_HOLE_LOWER_addr[ii] = 0;
            io_mcBarData.MCFGPMA_HOLE_UPPER_addr[ii] = 0;
        }

    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Display the Memory controller BAR data resulted from the BAR
///        data calculations.
///
/// @param[in]  i_portInfo      Port data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
void displayMCPortInfoData(const mcPortGroupInfo_t i_portInfo[])
{
    for (uint8_t ii = 0; ii < MAX_MC_PORTS_PER_MCS; ii++)
    {
        FAPI_INF("    Port %u:", ii);

        if (i_portInfo[ii].numPortsInGroup > 0)
        {
            FAPI_INF("        myGroup %u", i_portInfo[ii].myGroup);
            FAPI_INF("        numPortsInGroup %u", i_portInfo[ii].numPortsInGroup);
            FAPI_INF("        groupSize %u", i_portInfo[ii].groupSize);
            FAPI_INF("        groupBaseAddr 0x%.16llX", i_portInfo[ii].groupBaseAddr);
            FAPI_INF("        channelId %u", i_portInfo[ii].channelId);

            for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
            {
                FAPI_INF("        altMemValid[%u] %u", jj, i_portInfo[ii].altMemValid[jj]);
                FAPI_INF("        altMemSize[%u]  %u", jj, i_portInfo[ii].altMemSize[jj]);
                FAPI_INF("        altBaseAddr[%u] 0x%.16llX", jj, i_portInfo[ii].altBaseAddr[jj]);
            }
        }
        else
        {
            FAPI_INF("        Not configured");
        }
    }

    return;
}

///
/// @brief Display the Memory controller BAR data resulted from the BAR
///        data calculations.
///
/// @param[in]  i_mcPosition    MC (MCS/MI) position
/// @param[in]  i_mcBarData     BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
void displayMCBarData(const uint8_t i_mcPosition,
                      const mcBarData_t i_mcBarData)
{
    FAPI_INF("    MC pos: %u - BAR data:", i_mcPosition);
    FAPI_INF("        MCFGP_valid %u", i_mcBarData.MCFGP_valid);
    FAPI_INF("        MCFGP_chan_per_group %u", i_mcBarData.MCFGP_chan_per_group);
    FAPI_INF("        MCFGP_chan0_group_member_id %u", i_mcBarData.MCFGP_chan0_group_member_id);
    FAPI_INF("        MCFGP_chan1_group_member_id %u", i_mcBarData.MCFGP_chan1_group_member_id);
    FAPI_INF("        MCFGP_group_size %u", i_mcBarData.MCFGP_group_size);
    FAPI_INF("        MCFGP_groupBaseAddr 0x%.16llX", i_mcBarData.MCFGP_groupBaseAddr);
    FAPI_INF("        MCFGPM_valid %u", i_mcBarData.MCFGPM_valid);
    FAPI_INF("        MCFGPM_group_size %u", i_mcBarData.MCFGPM_group_size);
    FAPI_INF("        MCFGPM_groupBaseAddr 0x%.16llX", i_mcBarData.MCFGPM_groupBaseAddr);

    for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
    {
        FAPI_INF("        MCFGPA_HOLE_valid[%u]      %u", jj, i_mcBarData.MCFGPA_HOLE_valid[jj]);
        FAPI_INF("        MCFGPA_HOLE_LOWER_addr[%u] %u", jj, i_mcBarData.MCFGPA_HOLE_LOWER_addr[jj]);
        FAPI_INF("        MCFGPA_HOLE_UPPER_addr[%u] %u", jj, i_mcBarData.MCFGPA_HOLE_UPPER_addr[jj]);

        FAPI_INF("        MCFGPMA_HOLE_valid[%u]      %u", jj, i_mcBarData.MCFGPMA_HOLE_valid[jj]);
        FAPI_INF("        MCFGPMA_HOLE_LOWER_addr[%u] %u", jj, i_mcBarData.MCFGPMA_HOLE_LOWER_addr[jj]);
        FAPI_INF("        MCFGPMA_HOLE_UPPER_addr[%u] %u", jj, i_mcBarData.MCFGPMA_HOLE_UPPER_addr[jj]);

    }

    return;
}

///
/// @brief Load the mcPortGroupInfo_t data for the input MC based on
///        MC position, input group data, and mirror/non-mirror setting.
///
/// @param[in]  i_nonMirror     Type of group data:
///                              true = non-mirror; false = mirrored
/// @param[in]  i_mcPos         MC position (MCS/MI)
/// @param[in]  i_groupData     Array of Group data info
/// @param[out] o_portInfo      Output mcPortGroupInfo_t
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
void getPortData(const bool i_nonMirror,
                 const uint8_t i_mcPos,
                 const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS],
                 mcPortGroupInfo_t o_portInfo[MAX_MC_PORTS_PER_MCS])
{
    FAPI_DBG("Entering");

    // Non-mirrored groups: 0->7
    // Mirrored groups: 8->11
    uint8_t l_startGroup = 0;
    uint8_t l_endGroup =  (DATA_GROUPS / 2);

    if (i_nonMirror == false)
    {
        l_startGroup = MIRR_OFFSET;
        l_endGroup = (MIRR_OFFSET + NUM_MIRROR_REGIONS);
    }

    // Loop thru specified groups
    for (uint8_t l_group = l_startGroup; l_group < l_endGroup; l_group++)
    {
        // Skip empty groups
        if (i_groupData[l_group][GROUP_SIZE] == 0)
        {
            continue;
        }

        // Loop thru the ports (MCA/DMI) and determine if they belong
        // to this MC (MCS/MI)
        for (uint8_t l_memberIdx = 0;
             l_memberIdx < i_groupData[l_group][PORTS_IN_GROUP]; l_memberIdx++)
        {
            uint8_t l_mcPos = getMCPosition(i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]);

            // If the PORT_ID belongs to this MC
            if (l_mcPos == i_mcPos)
            {
                // Get the port number with respect to this MC (0 or 1)
                uint8_t l_mcPortNum = getMCPortNum(i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]);

                // Set the port group info for this port
                o_portInfo[l_mcPortNum].myGroup = l_group;
                o_portInfo[l_mcPortNum].numPortsInGroup = i_groupData[l_group][PORTS_IN_GROUP];
                o_portInfo[l_mcPortNum].groupSize = i_groupData[l_group][GROUP_SIZE];
                o_portInfo[l_mcPortNum].groupBaseAddr = i_groupData[l_group][BASE_ADDR];
                o_portInfo[l_mcPortNum].channelId = l_memberIdx;

                // ALT memory regions
                for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
                {
                    if (i_groupData[l_group][ALT_VALID(ii)])
                    {
                        o_portInfo[l_mcPortNum].altMemValid[ii] = 1;
                        o_portInfo[l_mcPortNum].altMemSize[ii] = i_groupData[l_group][ALT_SIZE(ii)];
                        o_portInfo[l_mcPortNum].altBaseAddr[ii] = i_groupData[l_group][ALT_BASE_ADDR(ii)];
                    }
                }
            }

        } // Port loop

    } // Group loop

    // Set channel ID for certain scenario
    if ( (o_portInfo[0].numPortsInGroup > 0) ||
         (o_portInfo[1].numPortsInGroup > 0) )
    {
        // If odd port (port1) has memory and even port (port0) is empty,
        // and odd port is in a group of 2 (obviously with a cross-MCS port),
        // then program channel id for port0 (because HW looks for id at this
        // port), zero out port1's group id
        if ( (o_portInfo[1].numPortsInGroup == 2) &&
             (o_portInfo[0].numPortsInGroup == 0) )
        {
            o_portInfo[0].channelId = o_portInfo[1].channelId;
            o_portInfo[1].channelId = 0;
        }
    }

    // Display MC port info data
    FAPI_INF("getPortData from %s group - Results for MCS/MI pos %d",
             i_nonMirror ? "NON-MIRROR" : "MIRROR", i_mcPos);
    displayMCPortInfoData(o_portInfo);

    FAPI_DBG("Exit");
    return;
}

///
/// @brief Use Group data obtained from p9_mss_eff_grouping to build
///        data to be programmed into each Memory controller target (MCS
///        or MI).
///
/// @param[in]  i_mcTargets     Vector of reference of MC targets (MCS/MI)
/// @param[in]  i_groupData     Array of Group data info
/// @param[out] o_mcDataPair    Output data pair MCS<->Data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode buildMCBarData(
    const std::vector< fapi2::Target<T> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS],
    std::vector<std::pair<fapi2::Target<T>, mcBarData_t>>& o_mcBarDataPair)
{
    FAPI_DBG("Entering");

    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MRW_HW_MIRRORING_ENABLE_Type l_mirror_ctl;

    // Get mirror policy
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_HW_MIRRORING_ENABLE,
                           FAPI_SYSTEM, l_mirror_ctl),
             "Error getting ATTR_MRW_HW_MIRRORING_ENABLE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    for (auto l_mc : i_mcTargets)
    {
        mcBarData_t l_mcBarData;
        mcPortGroupInfo_t l_portInfo[MAX_MC_PORTS_PER_MCS];

        // Get this MC unit position
        uint8_t l_unitPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc, l_unitPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        fapi2::toString(l_mc, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Build BAR data for MC target: %s", l_targetStr);

        // -----------------------------------------------
        // Build MC register values for non-mirror groups
        // -----------------------------------------------

        // Get port data from non-mirrored groups (true = non-mirrored)
        getPortData(true, l_unitPos, i_groupData, l_portInfo);

        // If one of MC port is configured in a group, proceed with
        // getting BAR data
        if ( (l_portInfo[0].numPortsInGroup > 0) ||
             (l_portInfo[1].numPortsInGroup > 0) )
        {
            // ---- Build MCFGP/MCFGM data based on port group info ----
            FAPI_TRY(getNonMirrorBarData(l_mc, l_portInfo, l_mcBarData),
                     "getNonMirrorBarData() returns error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ---------------------------------------------------------------
            // Set MC register values for mirror groups
            //   - Nimbus:  No mirror
            //   - Cumulus: If ATTR_MRW_HW_MIRRORING_ENABLE = true
            // ---------------------------------------------------------------
            if (l_mirror_ctl == fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_TRUE)
            {
                FAPI_INF("ATTR_MRW_HW_MIRRORING_ENABLE is enabled: checking mirrored groups");
                mcPortGroupInfo_t l_portInfoMirrored[MAX_MC_PORTS_PER_MCS];
                // Get port data from mirrored groups (false = mirrored)
                getPortData(false, l_unitPos, i_groupData, l_portInfoMirrored);

                // If at least 2MC ports/group, get the mirror BAR data
                if ( (l_portInfoMirrored[0].numPortsInGroup >= 2) &&
                     (l_portInfoMirrored[1].numPortsInGroup >= 2) )
                {
                    // ---- Build MCFGM data based on port group info ----
                    FAPI_TRY(getMirrorBarData(l_mc, l_portInfoMirrored, l_mcBarData),
                             "getMirrorBarData() returns error, l_rc 0x%.8X",
                             (uint64_t)fapi2::current_err);
                }
            }

            // Add to output pair
            o_mcBarDataPair.push_back(std::make_pair(l_mc, l_mcBarData));

            // Display data
            displayMCBarData(l_unitPos, l_mcBarData);
        }
        else
        {
            FAPI_INF("MC pos %u is not configured in a memory group.", l_unitPos);
        }

    } // MC loop

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Set MCFGPA MEMORY HOLE UPPER_ADDRESS_AT_END_OF_RANGE bit
///
/// @param[in]      i_target        MC target (MCS or MI)
/// @param[in/out]  io_data         Data buffer
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
void setUpperAddrEndOfRangeBit(const fapi2::Target<T>& i_target,
                               fapi2::buffer<uint64_t>& io_scomData);

/// MC = MCS (Nimbus)
template<>
void setUpperAddrEndOfRangeBit(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                               fapi2::buffer<uint64_t>& io_scomData)
{
    // This bit is not used in Nimbus
    return;
}

/// MC = MI (Cumulus)
template<>
void setUpperAddrEndOfRangeBit(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
                               fapi2::buffer<uint64_t>& io_scomData)
{
    io_scomData.setBit<MCS_MCFGPA_RESERVED_1>();
    return;
}

///
/// @brief Write BAR data to a memory controller
///
/// @param[in] i_mcBarDataPair Target pair <target, data>
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode writeMCBarData(
    const std::vector<std::pair<fapi2::Target<T>, mcBarData_t>>& i_mcBarDataPair)
{
    FAPI_DBG("Entering");

    fapi2::buffer<uint64_t> l_scomData(0);

    fapi2::ATTR_MSS_INTERLEAVE_GRANULARITY_Type l_interleave_granule_size;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_INTERLEAVE_GRANULARITY,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_interleave_granule_size),
             "Error getting ATTR_MSS_INTERLEAVE_GRANULARITY, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    for (auto l_pair : i_mcBarDataPair)
    {
        fapi2::Target<T> l_target = l_pair.first;
        mcBarData_t l_data = l_pair.second;

        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_target, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Program MC target: %s", l_targetStr);

        // 1. ---- Set MCFGP reg -----
        l_scomData = 0;

        // MCFGP valid (bit 0)
        if (l_data.MCFGP_valid == true)
        {
            l_scomData.setBit<MCS_MCFGP_VALID>();

            // Group size (bits 13:23)
            l_scomData.insertFromRight<MCS_MCFGP_GROUP_SIZE,
                                       MCS_MCFGP_GROUP_SIZE_LEN>(
                                           l_data.MCFGP_group_size);

            // Group base address (bits 24:47) 0b000000000000000000000001 = 4GB
            // 000000001 (base addr of 4GB)
            // 000000010 (base addr of 8GB)
            // 000000100 (base addr of 16GB)
            // 000001000 (base addr of 32GB)
            // 000010000 (base addr of 64GB)
            // 000100000 (base addr of 128GB)
            // 001000000 (base addr of 256GB)
            l_scomData.insertFromRight<MCS_MCFGP_GROUP_BASE_ADDRESS,
                                       MCS_MCFGP_GROUP_BASE_ADDRESS_LEN>(
                                           (l_data.MCFGP_groupBaseAddr >> 2));

            // configure interleave granularity if 2/4/8 MC per group only
            if ((l_data.MCFGP_chan_per_group == 0b0100) || // 2 MC/group
                (l_data.MCFGP_chan_per_group == 0b0101) ||
                (l_data.MCFGP_chan_per_group == 0b0110) || // 4 MC/group
                (l_data.MCFGP_chan_per_group == 0b1000))   // 8 MC/group
            {
                fapi2::buffer<uint64_t> l_mcmode0_scom_data;
                FAPI_TRY(fapi2::getScom(l_target, MCS_MCMODE0, l_mcmode0_scom_data),
                         "Error reading from MCS_MCMODE0 reg");
                l_mcmode0_scom_data.insertFromRight<MCS_MCMODE0_GROUP_INTERLEAVE_GRANULARITY,
                                                    MCS_MCMODE0_GROUP_INTERLEAVE_GRANULARITY_LEN>(l_interleave_granule_size);
                FAPI_TRY(fapi2::putScom(l_target, MCS_MCMODE0, l_mcmode0_scom_data),
                         "Error writing to MCS_MCMODE0 reg");
            }
        }

        // Channel per group (bits 1:4)
        l_scomData.insertFromRight<MCS_MCFGP_MC_CHANNELS_PER_GROUP,
                                   MCS_MCFGP_MC_CHANNELS_PER_GROUP_LEN>(
                                       l_data.MCFGP_chan_per_group);

        // Channel 0 group id (bits 5:7)
        l_scomData.insertFromRight<MCS_MCFGP_CHANNEL_0_GROUP_MEMBER_IDENTIFICATION,
                                   MCS_MCFGP_CHANNEL_0_GROUP_MEMBER_IDENTIFICATION_LEN>(
                                       l_data.MCFGP_chan0_group_member_id);

        // Channel 1 group id (bits 8:10)
        l_scomData.insertFromRight<MCS_MCFGP_CHANNEL_1_GROUP_MEMBER_IDENTIFICATION,
                                   MCS_MCFGP_CHANNEL_1_GROUP_MEMBER_IDENTIFICATION_LEN>(
                                       l_data.MCFGP_chan1_group_member_id);

        // Write to reg
        FAPI_INF("Write MCFGP reg 0x%.16llX, Value 0x%.16llX",
                 MCS_MCFGP, l_scomData);
        FAPI_TRY(fapi2::putScom(l_target, MCS_MCFGP, l_scomData),
                 "Error writing to MCS_MCFGP reg");

        // 2. ---- Set MCFGPM reg -----
        l_scomData = 0;

        if (l_data.MCFGPM_valid == true)
        {
            // MCFGP valid (bit 0)
            l_scomData.setBit<MCS_MCFGPM_VALID>();

            // Group size (bits 13:23)
            l_scomData.insertFromRight<MCS_MCFGPM_GROUP_SIZE,
                                       MCS_MCFGPM_GROUP_SIZE_LEN>(
                                           l_data.MCFGPM_group_size);

            // Group base address (bits 24:47), 0b000000000000000000000001 = 4GB
            // 000000001 (base addr of 4GB)
            // 000000010 (base addr of 8GB)
            // 000000100 (base addr of 16GB)
            // 000001000 (base addr of 32GB)
            // 000010000 (base addr of 64GB)
            // 000100000 (base addr of 128GB)
            // 001000000 (base addr of 256GB)
            l_scomData.insertFromRight<MCS_MCFGPM_GROUP_BASE_ADDRESS,
                                       MCS_MCFGPM_GROUP_BASE_ADDRESS_LEN>(
                                           (l_data.MCFGPM_groupBaseAddr >> 2));

        }

        // Write to reg
        FAPI_INF("Write MCFGPM reg 0x%.16llX, Value 0x%.16llX",
                 MCS_MCFGPM, l_scomData);
        FAPI_TRY(fapi2::putScom(l_target, MCS_MCFGPM, l_scomData),
                 "Error writing to MCS_MCFGPM reg");

        // 3. ---- Set MCFGPA reg -----
        l_scomData = 0;

        // Hole 0
        if (l_data.MCFGPA_HOLE_valid[0] == true)
        {
            // MCFGPA HOLE0 valid (bit 0)
            l_scomData.setBit<MCS_MCFGPA_HOLE0_VALID>();

            // MCFGPA_HOLE0_UPPER_ADDRESS_AT_END_OF_RANGE
            setUpperAddrEndOfRangeBit(l_target, l_scomData);

            // Hole 0 lower addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE0_LOWER_ADDRESS,
                                       MCS_MCFGPA_HOLE0_LOWER_ADDRESS_LEN>(
                                           (l_data.MCFGPA_HOLE_LOWER_addr[0] >> 2));
            // Hole 0 upper addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE0_UPPER_ADDRESS,
                                       MCS_MCFGPA_HOLE0_UPPER_ADDRESS_LEN>(
                                           (l_data.MCFGPMA_HOLE_UPPER_addr[0] >> 2));
        }

        // Hole 1
        if (l_data.MCFGPA_HOLE_valid[1] == true)
        {
            // MCFGPA HOLE1 valid (bit 0)
            l_scomData.setBit<MCS_MCFGPA_HOLE0_VALID>();

            // MCFGPA_HOLE1_UPPER_ADDRESS_AT_END_OF_RANGE
            setUpperAddrEndOfRangeBit(l_target, l_scomData);

            // Hole 1 lower addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE1_LOWER_ADDRESS,
                                       MCS_MCFGPA_HOLE1_LOWER_ADDRESS_LEN>(
                                           (l_data.MCFGPA_HOLE_LOWER_addr[1] >> 2));
            // Hole 1 upper addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE1_UPPER_ADDRESS,
                                       MCS_MCFGPA_HOLE1_UPPER_ADDRESS_LEN>(
                                           (l_data.MCFGPMA_HOLE_UPPER_addr[1] >> 2));
        }

        // Write to reg
        FAPI_INF("Write MCFGPA reg 0x%.16llX, Value 0x%.16llX",
                 MCS_MCFGPA, l_scomData);
        FAPI_TRY(fapi2::putScom(l_target, MCS_MCFGPA, l_scomData),
                 "Error writing to MCS_MCFGPA reg");

        // 4. ---- Set MCFGPMA reg -----
        l_scomData = 0;

        // Hole 0
        if (l_data.MCFGPMA_HOLE_valid[0] == true)
        {
            // MCFGPMA HOLE0 valid (bit 0)
            l_scomData.setBit<MCS_MCFGPMA_HOLE0_VALID>();

            // MCFGPA_HOLE0_UPPER_ADDRESS_AT_END_OF_RANGE
            setUpperAddrEndOfRangeBit(l_target, l_scomData);

            // Hole 0 lower addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE0_LOWER_ADDRESS,
                                       MCS_MCFGPMA_HOLE0_LOWER_ADDRESS_LEN>(
                                           ( l_data.MCFGPMA_HOLE_LOWER_addr[0] >> 2));
            // Hole 0 upper addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE0_UPPER_ADDRESS,
                                       MCS_MCFGPMA_HOLE0_UPPER_ADDRESS_LEN>(
                                           (l_data.MCFGPMA_HOLE_UPPER_addr[0] >> 2));
        }

        // Hole 1
        if (l_data.MCFGPMA_HOLE_valid[1] == true)
        {
            // MCFGPMA HOLE1 valid (bit 0)
            // 0b0000000001 = 4GB
            l_scomData.setBit<MCS_MCFGPMA_HOLE1_VALID>();

            // MCFGPA_HOLE1_UPPER_ADDRESS_AT_END_OF_RANGE
            setUpperAddrEndOfRangeBit(l_target, l_scomData);

            // Hole 1 lower addr
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE1_LOWER_ADDRESS,
                                       MCS_MCFGPMA_HOLE1_LOWER_ADDRESS_LEN>(
                                           (l_data.MCFGPMA_HOLE_LOWER_addr[1] >> 2));
            // Hole 1 upper addr
            // 0b0000000001 = 4GB
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE1_UPPER_ADDRESS,
                                       MCS_MCFGPMA_HOLE1_UPPER_ADDRESS_LEN>(
                                           (l_data.MCFGPMA_HOLE_UPPER_addr[1] >> 2));
        }

        // Write to reg
        FAPI_INF("Write MCFGPMA reg 0x%.16llX, Value 0x%.16llX",
                 MCS_MCFGPMA, l_scomData);

        FAPI_TRY(fapi2::putScom(l_target, MCS_MCFGPMA, l_scomData),
                 "Error writing to MCS_MCFGPMA reg");

    } // Data pair loop

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Unmask FIR before opening BARs
///
/// @param[in] i_mcBarDataPair Target pair <target, data>
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode unmaskMCFIR(
    const std::vector<std::pair<fapi2::Target<T>, mcBarData_t>>& i_mcBarDataPair)
{
    FAPI_DBG("Entering");

    fapi2::buffer<uint64_t> l_mcfiraction;
    fapi2::buffer<uint64_t> l_mcfirmask_and;

    // Setup MC Fault Isolation Action1 register buffer
    l_mcfiraction.setBit<MCS_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
    l_mcfiraction.setBit<MCS_MCFIR_COMMAND_LIST_TIMEOUT>();

    // Setup FIR bits in MC Fault Isolation Mask Register buffer
    l_mcfirmask_and.flush<1>();
    l_mcfirmask_and.clearBit<MCS_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
    l_mcfirmask_and.clearBit<MCS_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
    l_mcfirmask_and.clearBit<MCS_MCFIR_POWERBUS_PROTOCOL_ERROR>();
    l_mcfirmask_and.clearBit<MCS_MCFIR_MULTIPLE_BAR>();
    l_mcfirmask_and.clearBit<MCS_MCFIR_INVALID_ADDRESS>();
    l_mcfirmask_and.clearBit<MCS_MCFIR_COMMAND_LIST_TIMEOUT>();

    for (auto l_pair : i_mcBarDataPair)
    {
        fapi2::Target<T> l_target = l_pair.first;
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_target, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Unmask FIR for MC target: %s", l_targetStr);

        // Write MC FIR action1
        FAPI_TRY(fapi2::putScom(l_target, MCS_MCFIRACT1, l_mcfiraction),
                 "Error from putScom (MCS_MCFIRACT1)");

        // Write mask
        FAPI_TRY(fapi2::putScom(l_target, MCS_MCFIRMASK_AND, l_mcfirmask_and),
                 "Error from putScom (MCS_MCFIRMASK_AND)");

    } // Data pair loop

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief p9_mss_setup_bars procedure entry point
/// See doxygen in p9_mss_setup_bars.H
///
fapi2::ReturnCode p9_mss_setup_bars(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");

    uint8_t l_mem_ipl_complete = 1;

    // Stores data read from ATTR_MSS_MCS_GROUP_32
    uint32_t l_groupData[DATA_GROUPS][DATA_ELEMENTS];
    // std_pair<MCS target, MCS data>
    std::vector<std::pair<fapi2::Target<fapi2::TARGET_TYPE_MCS>, mcBarData_t>> l_mcsBarDataPair;
    // std_pair<MI target, MI data>
    std::vector<std::pair<fapi2::Target<fapi2::TARGET_TYPE_MI>, mcBarData_t>> l_miBarDataPair;

    // Get functional MCS chiplets, should be none for Cumulus
    auto l_mcsChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();
    // Get functional MI chiplets, , should be none for Nimbus
    auto l_miChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();

    FAPI_INF("Num of MCS %u; Num of MIs %u", l_mcsChiplets.size(), l_miChiplets.size());

    if ( (l_mcsChiplets.size() > 0) && (l_miChiplets.size() > 0) )
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_SETUP_BARS_INVALID_MC_CHIPLETS_DETECTED()
                    .set_NUM_MCS(l_mcsChiplets.size())
                    .set_NUM_MI(l_miChiplets.size()),
                    "Error: Both MCS and MI chiplets are found in proc, "
                    "NumOfMCS %u, NumOfMI %u",
                    l_mcsChiplets.size(), l_miChiplets.size());
    }

    // Get group data setup by p9_mss_eff_grouping
    memset(l_groupData, 0, sizeof(l_groupData));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MCS_GROUP_32, i_target,
                           l_groupData),
             "Error getting ATTR_MSS_MCS_GROUP_32, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Setup BAR for Nimbus
    if (l_mcsChiplets.size() > 0)
    {
        // Validate group data from attributes
        FAPI_TRY(validateGroupData(l_mcsChiplets, l_groupData),
                 "validateGroupData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Build MC BAR data based on Group data info
        FAPI_TRY(buildMCBarData(l_mcsChiplets, l_groupData, l_mcsBarDataPair),
                 "buildMCBarData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Unmask MC FIRs
        FAPI_TRY(unmaskMCFIR(l_mcsBarDataPair),
                 "unmaskMCFIR() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Write data to MCS
        FAPI_TRY(writeMCBarData(l_mcsBarDataPair),
                 "writeMCBarData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }

    // Setup BAR for Cumulus
    else if (l_miChiplets.size() > 0)
    {
        // Validate group data from attributes
        FAPI_TRY(validateGroupData(l_miChiplets, l_groupData),
                 "validateGroupData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Build MC BAR data based on Group data info
        FAPI_TRY(buildMCBarData(l_miChiplets, l_groupData, l_miBarDataPair),
                 "buildMCBarData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Unmask MC FIRs
        FAPI_TRY(unmaskMCFIR(l_miBarDataPair),
                 "unmaskMCFIR() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Write data to MI
        FAPI_TRY(writeMCBarData(l_miBarDataPair),
                 "writeMCBarData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

    }

    // write attribute signifying BARs are valid & MSS inits are finished
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_IPL_COMPLETE, i_target, l_mem_ipl_complete),
             "Error from FAPI_ATTR_SET (ATTR_MSS_MEM_IPL_COMPLETE)");

fapi_try_exit:
    FAPI_DBG("Exiting");

    return fapi2::current_err;
}
