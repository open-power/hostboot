/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_mss_setup_bars.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
/// *HWP Level       : 1
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
#include <memory_size.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------
const uint8_t MAX_MCS_PER_PROC     = 4;        // 4 MCS per proc chip
const uint8_t MAX_MC_PORTS_PER_MCS = 2;        // 2 MC ports per MCS
const uint8_t NO_CHANNEL_PER_GROUP = 0xFF;     // Init value of channel per group
const uint8_t MAX_ALT_MEM_REGIONS  = 2;        // Max num of memory holes

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
    {    1,         0,           0b0000    },      // 1 MC port/group for port0, port1 is not populated.
    {    1,         1,           0b0000    },      // 1 MC port/group for both port0 and port1
    {    1,         3,           0b0001    },      // 1 MC port/group for port0, 3 MC port/group for port1
    {    0,         1,           0b0000    },      // 1 MC port/group for port1, port0 is not populated.
    {    2,         1,           0b0100    },      // 2 MC port/group different MC port pairs
    {    3,         1,           0b0010    },      // 3 MC port/group for port0, 1 MC port/group for port1
    {    3,         3,           0b0011    },      // 3 MC port/group for port0, 3 MC port/group for port1
    {    2,         0,           0b0100    },      // 2 MC port/group different MC port pairs
    {    2,         2,           0b0101    },      // 2 MC port/group in the same MC port pairs (Need additional verification in code below)
    {    2,         3,           0b0100    },      // 2 MC port/group different MC port pairs
    {    0,         2,           0b0100    },      // 2 MC port/group different MC port pairs
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
 * @struct mcsPortGroupInfo_t
 *
 * Contains group data information related to a port.
 * This information is used to determine the channel per group
 * value for the MCFGP reg.
 *
 */
struct mcsPortGroupInfo_t
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    inline mcsPortGroupInfo_t()
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
    uint8_t altMemValid[MAX_ALT_MEM_REGIONS];
    uint32_t altMemSize[MAX_ALT_MEM_REGIONS];
    uint32_t altBaseAddr[MAX_ALT_MEM_REGIONS];
};

/**
 * @struct mcsBarData_t
 *
 * Contains BAR data info for an MCS
 */
struct mcsBarData_t
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    inline mcsBarData_t()
        : MCS_MCFGP_VALID(false), MCFGP_chan_per_group(0),
          MCFGP_chan0_group_member_id(0), MCFGP_chan1_group_member_id(0),
          MCFGP_group_size(0), MCFGP_groupBaseAddr(0),
          MCS_MCFGPM_VALID(false), MCFGPM_group_size(0), MCFGPM_groupBaseAddr(0)
    {
        memset(MCFGPA_HOLE_valid, 0, sizeof(MCFGPA_HOLE_valid));
        memset(MCFGPA_HOLE_LOWER_addr, 0, sizeof(MCFGPA_HOLE_LOWER_addr));
        memset(MCFGPA_HOLE_UPPER_addr, 0, sizeof(MCFGPA_HOLE_UPPER_addr));

        memset(MCFGPMA_HOLE_valid, 0, sizeof(MCFGPMA_HOLE_valid));
        memset(MCFGPMA_HOLE_LOWER_addr, 0, sizeof(MCFGPMA_HOLE_LOWER_addr));
        memset(MCFGPMA_HOLE_UPPER_addr, 0, sizeof(MCFGPMA_HOLE_UPPER_addr));
    }

    // Info to program MCFGP reg
    bool     MCS_MCFGP_VALID;
    uint8_t  MCFGP_chan_per_group;
    uint8_t  MCFGP_chan0_group_member_id;
    uint8_t  MCFGP_chan1_group_member_id;
    uint32_t MCFGP_group_size;
    uint32_t MCFGP_groupBaseAddr;

    // Info to program MCFGPM reg
    bool     MCS_MCFGPM_VALID;
    uint32_t MCFGPM_group_size;
    uint32_t MCFGPM_groupBaseAddr;

    // Info to program MCFGPA reg
    bool     MCFGPA_HOLE_valid[MAX_ALT_MEM_REGIONS];
    uint32_t MCFGPA_HOLE_LOWER_addr[MAX_ALT_MEM_REGIONS];
    uint32_t MCFGPA_HOLE_UPPER_addr[MAX_ALT_MEM_REGIONS];

    // Info to program MCFGPMA reg
    bool     MCFGPMA_HOLE_valid[MAX_ALT_MEM_REGIONS];
    uint32_t MCFGPMA_HOLE_LOWER_addr[MAX_ALT_MEM_REGIONS];
    uint32_t MCFGPMA_HOLE_UPPER_addr[MAX_ALT_MEM_REGIONS];
};

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------
///
/// @brief Get MCS position for the input PORT_ID
///        PORT_ID 0 --> MCS 0
///        PORT_ID 1 --> MCS 0
///        PORT_ID 2 --> MCS 1
///        PORT_ID 3 --> MCS 1
///        PORT_ID 4 --> MCS 2
///        PORT_ID 5 --> MCS 2
///        PORT_ID 6 --> MCS 3
///        PORT_ID 7 --> MCS 3
///
/// @param[in]  i_portID      PortID
/// @return MCS position
///
uint8_t getMCSPosition(uint8_t i_portID)
{
    return (i_portID / 2);
}

///
/// @brief Get the port number (with respect to the MCS, 0 or 1) for the
///        input PORT_ID
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
uint8_t getMCSPortNum(uint8_t i_portID)
{
    uint8_t l_mcsPos = getMCSPosition(i_portID);
    return (i_portID - (2 * l_mcsPos));
}

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------
///
/// @brief Validate group data received from ATTR_MSS_MCS_GROUP_32
///
/// @param[in]  i_mcTargets     Vector of reference of MC targets (MCS or MI)
/// @param[in]  i_groupData     Array of Group data info
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode validateGroupData(
    const std::vector< fapi2::Target<T> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS]);

template<> // TARGET_TYPE_MCS
fapi2::ReturnCode validateGroupData(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS])
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    uint8_t l_portFound[NUM_MC_PORTS_PER_PROC];

    // ------------------------------------------------------------
    // Perform these verifications:
    // 1) The MCS sizes specified in the input group data
    //    agrees with with the amount memory currently reported.
    // 2) An MC port can only appear once in any group.
    // ------------------------------------------------------------

    // Initialize local arrays
    memset(l_portFound, 0, sizeof(l_portFound));

    // Loop thru each MCS
    for (auto l_mcs : i_mcTargets)
    {
        // Figure out the amount of memory behind this MCS
        // by adding up all memory from its MCA ports
        auto l_mcaChiplets = l_mcs.getChildren<fapi2::TARGET_TYPE_MCA>();
        uint64_t l_mcsSize = 0;
        uint64_t l_mcaSize = 0;

        for (auto l_mca : l_mcaChiplets)
        {
            uint8_t l_mcaPos = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mca, l_mcaPos),
                     "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Get the amount of memory behind this MCA target
            FAPI_TRY(mss::eff_memory_size(l_mca, l_mcaSize),
                     "Error returned from eff_memory_size, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            FAPI_INF("MCA %u: Total DIMM size %lu GB", l_mcaPos, l_mcaSize);
            l_mcsSize += l_mcaSize;
        }

        // Get this MCS unit position
        uint8_t l_unitPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mcs, l_unitPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Loop thru non-mirror groups (0-7)
        uint32_t l_mcsSizeGroupData = 0;

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
                // If the PORT_ID listed belongs to this MCS, add the amount
                // of memory behind the port to this MCS.
                uint8_t l_mcsId = getMCSPosition(i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]);

                if (l_mcsId == l_unitPos)
                {
                    l_mcsSizeGroupData += i_groupData[l_group][PORT_SIZE];
                    // Increase # of times this PORT_ID is found
                    l_portFound[i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]]++;
                }

            } // Port loop

        } // Group loop

        // Assert if MCS specified in Group data doesn't agree
        // with the amount gets from Memory interface.
        FAPI_ASSERT(l_mcsSizeGroupData == l_mcsSize,
                    fapi2::MSS_SETUP_BARS_MCS_MEMSIZE_DISCREPENCY()
                    .set_TARGET(l_mcs)
                    .set_MEMSIZE_GROUP_DATA(l_mcsSizeGroupData)
                    .set_MEMSIZE_REPORTED(l_mcsSize),
                    "Error: MCS %u memory discrepancy: Group data size %u, "
                    "Current memory reported %u",
                    l_unitPos, l_mcsSizeGroupData, l_mcsSize);

    } // MCS loop

    // Assert if a PORT_ID is found more than once in any group
    for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
    {
        FAPI_ASSERT(l_portFound[ii] <= 1,
                    fapi2::MSS_SETUP_BARS_MULTIPLE_GROUP_ERR()
                    .set_PORT_ID(ii)
                    .set_COUNTER(l_portFound[ii]),
                    "Error: PORT_ID %u is grouped multiple times.  Counter %u",
                    ii, l_portFound[ii]);
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

template<> // TARGET_TYPE_MI
fapi2::ReturnCode validateGroupData(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MI> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS])
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Note: Add code for Cumulus (MI) here.

    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Look up table to determine the MCFGP/MCFGPM group size
///        encoded value (bits 13:23).
///
/// @param[in]   i_groupSize    Group size (in GB)
/// @param[out]  o_value        Encoded value
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getGroupSizeEncodedValue(
    const uint32_t i_groupSize,
    uint32_t& o_value)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

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

    // Assert if can't find Group size in the table
    FAPI_ASSERT( l_sizeFound == true,
                 fapi2::MSS_SETUP_BARS_INVALID_GROUP_SIZE()
                 .set_GROUP_SIZE(i_groupSize),
                 "Error: Can't locate Group size value in GROUP_SIZE_TABLE. "
                 "GroupSize u% GB.", i_groupSize );

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Calculate the BAR data for each MCS based on group info
///        of port0/1
///
/// @param[in]  i_portInfo     The port group info
/// @param[in]  o_mcsBarData   MCS BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getBarData(const mcsPortGroupInfo_t i_portInfo[],
                             mcsBarData_t& o_mcsBarData)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // This function assign the MCFGP_MC_CHANNELS_PER_GROUP value
    // to the MCS according to the rule listed in the Nimbus workbook.

    // Initialize
    o_mcsBarData.MCFGP_chan_per_group = NO_CHANNEL_PER_GROUP;
    o_mcsBarData.MCS_MCFGP_VALID = false;
    o_mcsBarData.MCS_MCFGPM_VALID = false;

    // ----------------------------------------------------
    // Determine data for MCFGP and MCFGPM registers
    // ----------------------------------------------------

    // Channel per group (MCFGP bits 1:4)
    for (uint8_t ii = 0;
         ii < (sizeof(CHANNEL_PER_GROUP_TABLE) / sizeof(channelPerGroupTable_t));
         ii++)
    {
        if ( (i_portInfo[0].numPortsInGroup == CHANNEL_PER_GROUP_TABLE[ii].port0_ports_in_group) &&
             (i_portInfo[1].numPortsInGroup == CHANNEL_PER_GROUP_TABLE[ii].port1_ports_in_group) )
        {
            o_mcsBarData.MCFGP_chan_per_group = CHANNEL_PER_GROUP_TABLE[ii].channel_per_group;
        }
    }

    // Assert if ports 0/1 don't match any entry in table
    FAPI_ASSERT(o_mcsBarData.MCFGP_chan_per_group != NO_CHANNEL_PER_GROUP,
                fapi2::MSS_SETUP_BARS_INVALID_PORTS_CONFIG()
                .set_PORT_0_PORTS_IN_GROUP(i_portInfo[0].numPortsInGroup)
                .set_PORT_0_GROUP(i_portInfo[0].myGroup)
                .set_PORT_1_PORTS_IN_GROUP(i_portInfo[1].numPortsInGroup)
                .set_PORT_1_GROUP(i_portInfo[1].myGroup),
                "Error: ports 0/1 config doesn't match any entry in Channel/group table. "
                "Port_0: group %u, ports in group %u",
                "Port_1: group %u, ports in group %u",
                i_portInfo[0].myGroup, i_portInfo[0].numPortsInGroup,
                i_portInfo[1].myGroup, i_portInfo[1].numPortsInGroup);


    // MCFGP valid (MCFGP bit 0)
    if ( i_portInfo[0].numPortsInGroup == 0)
    {
        // Port0 not populated
        o_mcsBarData.MCS_MCFGP_VALID = false;
    }
    else
    {
        // Port0 populated
        o_mcsBarData.MCS_MCFGP_VALID = true;
    }

    // MCFGPM valid (MCFGPM bit 0)
    if ( i_portInfo[1].numPortsInGroup == 0)
    {
        // Port1 not populated
        o_mcsBarData.MCS_MCFGPM_VALID = false;
    }
    else
    {
        // MCFGPM is valid if Channel_per_group < 0b0101
        if (o_mcsBarData.MCFGP_chan_per_group < 0b0101)
        {
            o_mcsBarData.MCS_MCFGPM_VALID = true;
        }
        // Determine if MCFGPM valid when Channel_per_group = 0b0101
        else if (o_mcsBarData.MCFGP_chan_per_group == 0b0101)
        {
            // Port1 populated, 2 MC/group
            // The table assigns 0b0101 if both ports belong 2 MC port/group,
            // Here, verify that they belong to the same group, if not,
            // re-assign the channel per group to 2 MC/group in different
            // MC port pairs (0b0100)
            if ( i_portInfo[0].myGroup != i_portInfo[1].myGroup )
            {
                o_mcsBarData.MCFGP_chan_per_group = 0b0100;
                o_mcsBarData.MCS_MCFGPM_VALID = true;
            }
        }
        // MCFGPM is not valid if Channel_per_group > 0b0101
        // (2,4,6 or 8, and in same MC port pair)
        // This is true because mirroring is not supported on Nimbus.
        else
        {
            o_mcsBarData.MCS_MCFGPM_VALID = false;
        }
    }

    // MCFGP Channel_0 Group member ID (bits 5:7)
    o_mcsBarData.MCFGP_chan0_group_member_id = i_portInfo[0].channelId;
    // MCFGP Channel_1 Group member ID (bits 8:10)
    o_mcsBarData.MCFGP_chan1_group_member_id = i_portInfo[1].channelId;

    // If MCFGP is valid, set other fields
    if (o_mcsBarData.MCS_MCFGP_VALID == true)
    {
        // MCFGP Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_portInfo[0].groupSize,
                                          o_mcsBarData.MCFGP_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        o_mcsBarData.MCFGP_groupBaseAddr = i_portInfo[0].groupBaseAddr;
    }

    // If MCFGPM is valid, set other fields
    if (o_mcsBarData.MCS_MCFGPM_VALID == true)
    {
        // MCFGPM Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_portInfo[1].groupSize,
                                          o_mcsBarData.MCFGPM_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        o_mcsBarData.MCFGPM_groupBaseAddr = i_portInfo[1].groupBaseAddr;
    }

    // ----------------------------------------------------
    // Determine data for MCFGPA and MCFGPMA registers
    // ----------------------------------------------------

    // Alternate Memory MCFGPA
    for (uint8_t ii = 0; ii < MAX_ALT_MEM_REGIONS; ii++)
    {
        if ( i_portInfo[0].altMemValid[ii] )
        {
            o_mcsBarData.MCFGPA_HOLE_valid[ii] = 1;
            o_mcsBarData.MCFGPA_HOLE_LOWER_addr[ii] = i_portInfo[0].altBaseAddr[ii];
            o_mcsBarData.MCFGPA_HOLE_UPPER_addr[ii] =
                i_portInfo[0].altBaseAddr[ii] + i_portInfo[0].altMemSize[ii];
        }
        else
        {
            o_mcsBarData.MCFGPA_HOLE_valid[ii] = 0;
            o_mcsBarData.MCFGPA_HOLE_LOWER_addr[ii] = 0;
            o_mcsBarData.MCFGPA_HOLE_UPPER_addr[ii] = 0;
        }

        if ( i_portInfo[1].altMemValid[ii] )
        {
            o_mcsBarData.MCFGPMA_HOLE_valid[ii] = 1;
            o_mcsBarData.MCFGPMA_HOLE_LOWER_addr[ii] = i_portInfo[1].altBaseAddr[ii];
            o_mcsBarData.MCFGPMA_HOLE_UPPER_addr[ii] =
                i_portInfo[0].altBaseAddr[ii] + i_portInfo[1].altMemSize[ii];
        }
        else
        {
            o_mcsBarData.MCFGPA_HOLE_valid[ii] = 0;
            o_mcsBarData.MCFGPA_HOLE_LOWER_addr[ii] = 0;
            o_mcsBarData.MCFGPA_HOLE_UPPER_addr[ii] = 0;
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
/// @param[in]  i_mcTargets     MC target (MCS/MI)
/// @param[in]  i_portInfo      Port data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
void displayMCPortInfoData(const fapi2::Target<T> i_mcTarget,
                           const mcsPortGroupInfo_t i_portInfo[]);

template<> // TARGET_TYPE_MCS
void displayMCPortInfoData(const fapi2::Target<fapi2::TARGET_TYPE_MCS> i_mcTarget,
                           const mcsPortGroupInfo_t i_portInfo[])
{
    for (uint8_t ii = 0; ii < MAX_MC_PORTS_PER_MCS; ii++)
    {
        FAPI_DBG("    Port %u:", ii);
        FAPI_DBG("        myGroup %u", i_portInfo[ii].myGroup);
        FAPI_DBG("        numPortsInGroup %u", i_portInfo[ii].numPortsInGroup);
        FAPI_DBG("        groupSize %u", i_portInfo[ii].groupSize);
        FAPI_DBG("        groupBaseAddr %u", i_portInfo[ii].groupBaseAddr);
        FAPI_DBG("        channelId %u", i_portInfo[ii].channelId);

        for (uint8_t jj = 0; jj < MAX_ALT_MEM_REGIONS; jj++)
        {
            FAPI_DBG("        altMemValid[%u] %u", jj, i_portInfo[ii].altMemValid[jj]);
            FAPI_DBG("        altMemSize[%u]  %u", jj, i_portInfo[ii].altMemSize[jj]);
            FAPI_DBG("        altBaseAddr[%u] %u", jj, i_portInfo[ii].altBaseAddr[jj]);
        }
    }

    return;
}

template<> // TARGET_TYPE_MI
void displayMCPortInfoData(const fapi2::Target<fapi2::TARGET_TYPE_MI> i_mcTarget,
                           const mcsPortGroupInfo_t i_portInfo[])
{

    // Note: Add code for MI.
    return;
}

///
/// @brief Display the Memory controller BAR data resulted from the BAR
///        data calculations.
///
/// @param[in]  i_mcTargets     MC target (MCS/MI)
/// @param[in]  i_mcBarData     BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
void displayMCBarData(const fapi2::Target<T> i_mcTarget,
                      const mcsBarData_t i_mcBarData);


template<> // TARGET_TYPE_MCS
void displayMCBarData(const fapi2::Target<fapi2::TARGET_TYPE_MCS> i_mcTarget,
                      const mcsBarData_t i_mcBarData)
{
    FAPI_DBG("    BAR data:");
    FAPI_DBG("        MCS_MCFGP_VALID %u", i_mcBarData.MCS_MCFGP_VALID);
    FAPI_DBG("        MCFGP_chan_per_group %u", i_mcBarData.MCFGP_chan_per_group);
    FAPI_DBG("        MCFGP_chan0_group_member_id %u", i_mcBarData.MCFGP_chan0_group_member_id);
    FAPI_DBG("        MCFGP_chan1_group_member_id %u", i_mcBarData.MCFGP_chan1_group_member_id);
    FAPI_DBG("        MCFGP_group_size %u", i_mcBarData.MCFGP_group_size);
    FAPI_DBG("        MCFGP_groupBaseAddr %u", i_mcBarData.MCFGP_groupBaseAddr);
    FAPI_DBG("        MCS_MCFGPM_VALID %u", i_mcBarData.MCS_MCFGPM_VALID);
    FAPI_DBG("        MCFGPM_group_size %u", i_mcBarData.MCFGPM_group_size);
    FAPI_DBG("        MCFGPM_groupBaseAddr %u", i_mcBarData.MCFGPM_groupBaseAddr);

    for (uint8_t jj = 0; jj < MAX_ALT_MEM_REGIONS; jj++)
    {
        FAPI_DBG("        MCFGPA_HOLE_valid[%u]      %u", jj, i_mcBarData.MCFGPA_HOLE_valid[jj]);
        FAPI_DBG("        MCFGPA_HOLE_LOWER_addr[%u] %u", jj, i_mcBarData.MCFGPA_HOLE_LOWER_addr[jj]);
        FAPI_DBG("        MCFGPA_HOLE_UPPER_addr[%u] %u", jj, i_mcBarData.MCFGPA_HOLE_UPPER_addr[jj]);

        FAPI_DBG("        MCFGPMA_HOLE_valid[%u]      %u", jj, i_mcBarData.MCFGPMA_HOLE_valid[jj]);
        FAPI_DBG("        MCFGPMA_HOLE_LOWER_addr[%u] %u", jj, i_mcBarData.MCFGPMA_HOLE_LOWER_addr[jj]);
        FAPI_DBG("        MCFGPMA_HOLE_UPPER_addr[%u] %u", jj, i_mcBarData.MCFGPMA_HOLE_UPPER_addr[jj]);

    }

    return;
}

template<> // TARGET_TYPE_MI
void displayMCBarData(const fapi2::Target<fapi2::TARGET_TYPE_MI> i_mcTarget,
                      const mcsBarData_t i_mcBarData)
{

    // Note: Add code for MI.
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
    std::map<fapi2::Target<T>, mcsBarData_t>& o_mcBarDataPair);

template<> // TARGET_TYPE_MCS
fapi2::ReturnCode buildMCBarData(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS],
    std::map<fapi2::Target<fapi2::TARGET_TYPE_MCS>, mcsBarData_t>& o_mcBarDataPair)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    mcsPortGroupInfo_t l_portInfo[MAX_MC_PORTS_PER_MCS];
    mcsBarData_t l_mcsBarData;
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

    for (auto l_mcs : i_mcTargets)
    {

        // Initialize
        memset(&l_mcsBarData, 0, sizeof(l_mcsBarData));

        // Get this MCS unit position
        uint8_t l_unitPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mcs, l_unitPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        fapi2::toString(l_mcs, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Build BAR data for MCS target: %s, UnitPos %u ", l_targetStr, l_unitPos);

        // ---- Fill in group info for each port in this MCS ----
        memset(l_portInfo, 0, sizeof(l_portInfo));

        // Loop thru non-mirror groups (0-7)
        for (uint8_t l_group = 0; l_group < (DATA_GROUPS / 2); l_group++)
        {
            // Skip empty groups
            if (i_groupData[l_group][GROUP_SIZE] == 0)
            {
                continue;
            }

            // Loop thru the MCA ports and determine if they belong to this MCS
            for (uint8_t l_memberIdx = 0;
                 l_memberIdx < i_groupData[l_group][PORTS_IN_GROUP]; l_memberIdx++)
            {
                uint8_t l_mcsPos = getMCSPosition(i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]);

                // If the PORT_ID belongs to this MCS
                if (l_mcsPos == l_unitPos)
                {
                    // Get the port number with respect to this MCS (0 or 1)
                    uint8_t l_mcsPortNum = getMCSPortNum(i_groupData[l_group][MEMBER_IDX(0) + l_memberIdx]);

                    // Set the port group info for this port
                    l_portInfo[l_mcsPortNum].myGroup = l_group;
                    l_portInfo[l_mcsPortNum].numPortsInGroup = i_groupData[l_group][PORTS_IN_GROUP];
                    l_portInfo[l_mcsPortNum].groupSize = i_groupData[l_group][GROUP_SIZE];
                    l_portInfo[l_mcsPortNum].groupBaseAddr = i_groupData[l_group][BASE_ADDR];
                    l_portInfo[l_mcsPortNum].channelId = l_memberIdx;

                    // ALT memory regions
                    for (uint8_t ii = 0; ii < MAX_ALT_MEM_REGIONS; ii++)
                    {
                        if (i_groupData[l_group][ALT_VALID(ii)])
                        {
                            l_portInfo[l_mcsPortNum].altMemValid[ii] = 1;
                            l_portInfo[l_mcsPortNum].altMemSize[ii] = i_groupData[l_group][ALT_SIZE(ii)];
                            l_portInfo[l_mcsPortNum].altBaseAddr[ii] = i_groupData[l_group][ALT_BASE_ADDR(ii)];
                        }
                    }
                }

            } // Port loop

        } // Group loop

        // If one of MCS port is configured in a group, get the BAR data
        if ( (l_portInfo[0].numPortsInGroup > 0) ||
             (l_portInfo[1].numPortsInGroup > 0) )
        {
            // Display MCS port info data
            displayMCPortInfoData(l_mcs, l_portInfo);

            // ---- Build MCFGP/MCFGM data based on port group info ----
            FAPI_TRY(getBarData(l_portInfo, l_mcsBarData),
                     "getBarData() returns error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Display data
            displayMCBarData(l_mcs, l_mcsBarData);

            // Add to output pair
            o_mcBarDataPair.insert(std::pair<fapi2::Target<fapi2::TARGET_TYPE_MCS>, mcsBarData_t>
                                   (l_mcs, l_mcsBarData));
        }
        else
        {
            FAPI_INF("MCS Unit pos %u is not configured in a memory group.",
                     l_unitPos);
        }

    } // MCS loop

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

template<> // TARGET_TYPE_MI
fapi2::ReturnCode buildMCBarData(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MI> >& i_mcTargets,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS],
    std::map<fapi2::Target<fapi2::TARGET_TYPE_MI>, mcsBarData_t>& o_mcBarDataPair)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Add code for MI

    FAPI_DBG("Exit");
    return fapi2::current_err;
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
    const std::map<fapi2::Target<T>, mcsBarData_t> i_mcBarDataPair);

template<> // TARGET_TYPE_MCS
fapi2::ReturnCode writeMCBarData(
    const std::map<fapi2::Target<fapi2::TARGET_TYPE_MCS>, mcsBarData_t> i_mcBarDataPair)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);

    for (auto l_pair : i_mcBarDataPair)
    {
        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_target = l_pair.first;
        mcsBarData_t l_data = l_pair.second;

        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_target, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Program MCS target: %s", l_targetStr);

        // 1. ---- Set MCFGP reg -----

        l_scomData = 0;

        // MCFGP valid (bit 0)
        if (l_data.MCS_MCFGP_VALID == true)
        {
            l_scomData.setBit<MCS_MCFGP_VALID>();

            // Group size (bits 13:23)
            l_scomData.insertFromRight<MCS_MCFGP_GROUP_SIZE,
                                       MCS_MCFGP_GROUP_SIZE_LEN>(
                                           l_data.MCFGP_group_size);

            // Group base address (bits 24:47)
            l_scomData.insertFromRight<MCS_MCFGP_GROUP_BASE_ADDRESS,
                                       MCS_MCFGP_GROUP_BASE_ADDRESS_LEN>(
                                           l_data.MCFGP_groupBaseAddr);
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

        if (l_data.MCS_MCFGPM_VALID == true)
        {
            // MCFGP valid (bit 0)
            l_scomData.setBit<MCS_MCFGPM_VALID>();

            // Group size (bits 13:23)
            l_scomData.insertFromRight<MCS_MCFGPM_GROUP_SIZE,
                                       MCS_MCFGPM_GROUP_SIZE_LEN>(
                                           l_data.MCFGPM_group_size);

            // Group base address (bits 24:47)
            l_scomData.insertFromRight<MCS_MCFGPM_GROUP_BASE_ADDRESS,
                                       MCS_MCFGPM_GROUP_BASE_ADDRESS_LEN>(
                                           l_data.MCFGPM_groupBaseAddr);

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

            // Hole 0 lower addr
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE0_LOWER_ADDRESS,
                                       MCS_MCFGPA_HOLE0_LOWER_ADDRESS_LEN>(
                                           l_data.MCFGPA_HOLE_LOWER_addr[0]);
            // Hole 0 upper addr
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE0_UPPER_ADDRESS,
                                       MCS_MCFGPA_HOLE0_UPPER_ADDRESS_LEN>(
                                           l_data.MCFGPMA_HOLE_UPPER_addr[0]);
        }

        // Hole 1
        if (l_data.MCFGPA_HOLE_valid[1] == true)
        {
            // MCFGPA HOLE1 valid (bit 0)
            l_scomData.setBit<MCS_MCFGPA_HOLE0_VALID>();

            // Hole 1 lower addr
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE1_LOWER_ADDRESS,
                                       MCS_MCFGPA_HOLE1_LOWER_ADDRESS_LEN>(
                                           l_data.MCFGPA_HOLE_LOWER_addr[1]);
            // Hole 1 upper addr
            l_scomData.insertFromRight<MCS_MCFGPA_HOLE1_UPPER_ADDRESS,
                                       MCS_MCFGPA_HOLE1_UPPER_ADDRESS_LEN>(
                                           l_data.MCFGPMA_HOLE_UPPER_addr[1]);
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

            // Hole 0 lower addr
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE0_LOWER_ADDRESS,
                                       MCS_MCFGPMA_HOLE0_LOWER_ADDRESS_LEN>(
                                           l_data.MCFGPMA_HOLE_LOWER_addr[0]);
            // Hole 0 upper addr
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE0_UPPER_ADDRESS,
                                       MCS_MCFGPMA_HOLE0_UPPER_ADDRESS_LEN>(
                                           l_data.MCFGPMA_HOLE_UPPER_addr[0]);
        }

        // Hole 1
        if (l_data.MCFGPMA_HOLE_valid[1] == true)
        {
            // MCFGPMA HOLE1 valid (bit 0)
            l_scomData.setBit<MCS_MCFGPMA_HOLE1_VALID>();

            // Hole 1 lower addr
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE1_LOWER_ADDRESS,
                                       MCS_MCFGPMA_HOLE1_LOWER_ADDRESS_LEN>(
                                           l_data.MCFGPMA_HOLE_LOWER_addr[1]);
            // Hole 1 upper addr
            l_scomData.insertFromRight<MCS_MCFGPMA_HOLE1_UPPER_ADDRESS,
                                       MCS_MCFGPMA_HOLE1_UPPER_ADDRESS_LEN>(
                                           l_data.MCFGPMA_HOLE_UPPER_addr[1]);
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

template<> // TARGET_TYPE_MI
fapi2::ReturnCode writeMCBarData(
    const std::map<fapi2::Target<fapi2::TARGET_TYPE_MI>, mcsBarData_t> i_mcBarDataPair)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Add code for MI

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
    fapi2::ReturnCode l_rc;
    uint8_t l_enhancedNoMirrorMode = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // Stores data read from ATTR_MSS_MCS_GROUP_32
    uint32_t l_groupData[DATA_GROUPS][DATA_ELEMENTS];
    // std_pair<MCS target, MCS data>
    std::map<fapi2::Target<fapi2::TARGET_TYPE_MCS>, mcsBarData_t> l_mcsBarDataPair;
    // std_pair<MI target, MI data>
    std::map<fapi2::Target<fapi2::TARGET_TYPE_MI>, mcsBarData_t> l_miBarDataPair;

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

    // Get mirror policy
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING,
                           FAPI_SYSTEM, l_enhancedNoMirrorMode),
             "Error getting ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

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

        // Write data to MCS
        FAPI_TRY(writeMCBarData(l_mcsBarDataPair),
                 "writeMCBarData() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Note: there is no mirror memory for Nimbus

    }

    // Setup BAR for Cumulus
    else if (l_miChiplets.size() > 0)
    {
        // Note: Add code for Cumulus:
        // 1) Add code to template functions for MI in Cumulus
        // 2) Need to also program Mirror memory in Cumulus.
    }

fapi_try_exit:
    FAPI_DBG("Exiting");

    return fapi2::current_err;
}
