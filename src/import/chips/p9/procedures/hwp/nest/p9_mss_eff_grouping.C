/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_mss_eff_grouping.C $          */
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
///----------------------------------------------------------------------------
/// @file  p9_mss_eff_grouping.C
///
/// @brief Perform Memory Controller grouping on a processor chip
///
/// The purpose of this procedure is to effectively group the memory on each
/// processor chip based on available memory behind its memory grouping ports.
/// Some placement policy/scheme and other info that are stored in the
/// attributes are used as part of the grouping process.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_mss_eff_grouping.H>
#include <p9_fbc_utils.H>
#include <map>
#include <memory_size.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------
// ------------------
// System structure
// ------------------
// MC port position
const uint8_t MCPORTID_0 = 0x0;
const uint8_t MCPORTID_1 = 0x1;
const uint8_t MCPORTID_2 = 0x2;
const uint8_t MCPORTID_3 = 0x3;
const uint8_t MCPORTID_4 = 0x4;
const uint8_t MCPORTID_5 = 0x5;
const uint8_t MCPORTID_6 = 0x6;
const uint8_t MCPORTID_7 = 0x7;

// -----------------------
// Group allow definitions
// -----------------------
// Enum value used to decode ATTR_MSS_INTERLEAVE_ENABLE
// P9 allows 1, 2, 3, 4, 6, or 8 memory ports to be grouped together.
enum GroupAllowed
{
    GROUP_1    = 0b00000001,   // 0x01 Group of 1 port allowed
    GROUP_2    = 0b00000010,   // 0x02 Group of 2 ports allowed
    GROUP_3    = 0b00000100,   // 0x04 Group of 3 ports allowed
    GROUP_4    = 0b00001000,   // 0x08 Group of 4 ports allowed
    GROUP_6    = 0b00100000,   // 0x20 Group of 6 ports allowed
    GROUP_8    = 0b10000000,   // 0x80 Group of 8 ports allowed
    ALL_GROUPS = GROUP_1 |
                 GROUP_2 |
                 GROUP_3 |
                 GROUP_4 |
                 GROUP_6 |
                 GROUP_8,
};

///----------------------------------------------------------------------------
/// struct EffGroupingSysAttrs
///----------------------------------------------------------------------------
///
/// @struct EffGroupingSysAttrs
/// Contains system attribute values that are needed to perform
/// memory effective grouping.
///
struct EffGroupingSysAttrs
{
    ///
    /// @brief getAttrs
    /// Function that reads the system attributes and load their values
    /// into the struct.
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs();

    // Public data
    uint8_t iv_selectiveMode = 0;        // ATTR_MEM_MIRROR_PLACEMENT_POLICY
    uint8_t iv_enhancedNoMirrorMode = 0; // ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING
    uint8_t iv_fabricAddrBarMode = 0;    // ATTR_PROC_FABRIC_ADDR_BAR_MODE

};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingSysAttrs::getAttrs()
{
    FAPI_DBG("Entering EffGroupingSysAttrs::getAttrs");

    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // Get mirror placement policy
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY,
                           FAPI_SYSTEM, iv_selectiveMode),
             "Error getting ATTR_MEM_MIRROR_PLACEMENT_POLICY, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get enhanced grouping option
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING,
                           FAPI_SYSTEM, iv_enhancedNoMirrorMode),
             "Error getting ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Fabric address BAR mode
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE,
                           FAPI_SYSTEM, iv_fabricAddrBarMode),
             "Error getting ATTR_PROC_FABRIC_ADDR_BAR_MODE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Display attribute values
    FAPI_INF("EffGroupingSysAttrs: ");
    FAPI_INF("   ATTR_MEM_MIRROR_PLACEMENT_POLICY 0x%.8X", iv_selectiveMode);
    FAPI_INF("   ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING 0x%.8X", iv_enhancedNoMirrorMode);
    FAPI_INF("   ATTR_PROC_FABRIC_ADDR_BAR_MODE 0x%.8X", iv_fabricAddrBarMode);

fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingSysAttrs::getAttrs");
    return fapi2::current_err;
}


///----------------------------------------------------------------------------
/// struct EffGroupingProcAttrs
///----------------------------------------------------------------------------
///
/// @struct EffGroupingProcAttrs
/// Contains processor chip attribute values that are needed to perform
/// memory effective grouping.
///
struct EffGroupingProcAttrs
{
    ///
    /// @brief getAttrs
    /// Function that reads the processor target attributes and load their
    /// values into the struct.
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs i_sysAttrs);

    ///
    /// @brief calcProcBaseAddr
    /// Function that calculates the Memory base address values (for both
    /// non-mirrored/mirrored memory) for this proc target.
    /// The memory base addresses then will be written to the
    /// ATTR_PROC_MEM_BASE and ATTR_PROC_MIRROR_BASE attributes.
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode calcProcBaseAddr(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs i_sysAttrs);

    // Public data
    uint8_t  iv_groupsAllowed = 0;  // ATTR_MSS_INTERLEAVE_ENABLE
    uint64_t iv_memBaseAddr = 0;    // ATTR_PROC_MEM_BASE
    uint64_t iv_mirrorBaseAddr = 0; // ATTR_PROC_MIRROR_BASE
    uint64_t iv_htmBarSizes[NUM_OF_HTM_REGIONS] = {0, 0}; // ATTR_PROC_HTM_BAR_SIZES
    uint64_t iv_occSandboxSize = 0; // ATTR_PROC_OCC_SANDBOX_SIZE
    uint32_t iv_fabricSystemId = 0; // ATTR_FABRIC_SYSTEM_ID
    uint8_t  iv_fabricGroupId = 0;  // ATTR_FABRIC_GROUP_ID
    uint8_t  iv_fabricChipId = 0;   // ATTR_FABRIC_CHIP_ID
};


// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingProcAttrs::calcProcBaseAddr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs i_sysAttrs)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Get the Mirror/Non-mirror base addresses
    FAPI_TRY(p9_fbc_utils_get_chip_base_address(i_target, iv_memBaseAddr,
             iv_mirrorBaseAddr),
             "p9_fbc_utils_get_chip_base_address() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Write base addr for non-mirror memory regions
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MEM_BASE, i_target,
                           iv_memBaseAddr),
             "Error setting ATTR_PROC_MEM_BASE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set base addr for mirror memory regions
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_BASE, i_target,
                           iv_mirrorBaseAddr),
             "Error setting ATTR_PROC_MIRROR_BASE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingProcAttrs::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs i_sysAttrs)
{
    FAPI_DBG("Entering EffGroupingProcAttrs::getAttrs");
    fapi2::ReturnCode l_rc;

    // Get interleave option
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_INTERLEAVE_ENABLE, i_target,
                           iv_groupsAllowed),
             "Error getting ATTR_MSS_INTERLEAVE_ENABLE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Hardware Trace Macro (HTM) bar size
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_HTM_BAR_SIZES, i_target, iv_htmBarSizes),
             "Error getting ATTR_PROC_HTM_BAR_SIZES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get On Chip Controler (OCC) sandbox size
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_OCC_SANDBOX_SIZE, i_target,
                           iv_occSandboxSize),
             "Error getting ATTR_PROC_OCC_SANDBOX_SIZE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Fabric system ID
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_ID, i_target,
                           iv_fabricSystemId),
             "Error getting ATTR_FABRIC_SYSTEM_ID, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Fabric group ID
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID, i_target,
                           iv_fabricGroupId),
             "Error getting ATTR_FABRIC_GROUP_ID, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Fabric chip ID
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID, i_target,
                           iv_fabricChipId),
             "Error getting ATTR_FABRIC_CHIP_ID, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Figure out memory base addresses for this proc and
    // writes values to ATTR_PROC_MEM_BASE and ATTR_PROC_MIRROR_BASE
    FAPI_TRY(calcProcBaseAddr(i_target, i_sysAttrs),
             "EffGroupingProcAttrs::getAttrs: calcProcBaseAddr() returns "
             "error, l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    // Display attribute values
    FAPI_INF("EffGroupingProcAttrs::getAttrs: ");
    FAPI_INF("  ATTR_MSS_INTERLEAVE_ENABLE 0x%.8X", iv_groupsAllowed);
    FAPI_INF("  ATTR_PROC_HTM_BAR_SIZES[0] 0x%.16llX", iv_htmBarSizes[0]);
    FAPI_INF("  ATTR_PROC_HTM_BAR_SIZES[1] 0x%.16llX", iv_htmBarSizes[1]);
    FAPI_INF("  ATTR_PROC_OCC_SANDBOX_SIZE 0x%.16llX", iv_occSandboxSize);
    FAPI_INF("  ATTR_FABRIC_SYSTEM_ID 0x%.8X", iv_fabricSystemId);
    FAPI_INF("  ATTR_FABRIC_GROUP_ID 0x%.8X", iv_fabricGroupId);
    FAPI_INF("  ATTR_FABRIC_CHIP_ID 0x%.8X", iv_fabricChipId);
    FAPI_INF("  ATTR_PROC_MEM_BASE 0x%.16llX", iv_memBaseAddr);
    FAPI_INF("  ATTR_PROC_MIRROR_BASE 0x%.16llX", iv_mirrorBaseAddr);


fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingProcAttrs::getAttrs");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingMcaAttrs
///----------------------------------------------------------------------------
///
/// @struct EffGroupingMcaAttrs
///
/// Contains attributes for an MCA Chiplet (Nimbus only)
///
struct EffGroupingMcaAttrs
{
    ///
    /// @brief Getting attribute of an MCA chiplet
    ///
    /// Function that reads the MCA target attributes and load their
    /// values into the struct.
    ///
    /// @param[in] i_target Reference to MCA chiplet target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(
        const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

    // Unit Position
    uint8_t iv_unitPos = 0;

    // Dimm size behind this MCA
    uint64_t iv_dimmSize = 0;

};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingMcaAttrs::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    FAPI_DBG("Entering EffGroupingMcaAttrs::getAttrs");
    fapi2::ReturnCode l_rc;

    // Get the amount of memory behind this MCA target
    FAPI_TRY(mss::eff_memory_size(i_target, iv_dimmSize),
             "Error returned from eff_memory_size, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get the MCA unit position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, iv_unitPos),
             "Error getting MCA ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // MCA's total dimm size
    FAPI_INF("MCA %u: Total DIMM size %lu GB", iv_unitPos, iv_dimmSize);

fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingMcaAttrs::getAttrs");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingDmiAttrs
///----------------------------------------------------------------------------
///
/// @struct EffGroupingDmiAttrs
///
/// Contains attributes for an DMI Chiplet (Cumulus only)
///
struct EffGroupingDmiAttrs
{
    ///
    /// @brief Getting attribute of a DMI chiplet
    ///
    /// Function that reads the DMI target attributes and load their
    /// values into the struct.
    ///
    /// @param[in] i_target Reference to DMI chiplet target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(
        const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_target);

    // Unit Position
    uint8_t iv_unitPos = 0;

    // Dimm size behind this DMI
    uint32_t iv_dimmSize = 0;

    // The membuf chip associated with this DMI
    // (for deconfiguring if cannot group)
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> iv_membuf;
};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingDmiAttrs::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_target)
{
    FAPI_DBG("Entering EffGroupingDmiAttrs::getAttrs");
    fapi2::ReturnCode l_rc;

    // Get the amount of memory behind this DMI target
#if 0
    // Note: For Cumulus, needs Memory team to support the function
    //       to be called on DMI targets.
    FAPI_TRY(mss::eff_memory_size(i_target, iv_dimmSize),
             "Error returned from eff_memory_size, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
#endif

    // Get the membufs attached to this DMI
    // Note: For Cumulus, needs to have getAssociatedMembufs() supported
    //auto l_associatedMembufs = i_target.getAssociatedMembufs();
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_membuf1;
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_membuf2;
    auto l_associatedMembufs = {l_membuf1, l_membuf2};

    // Get the DMI unit position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, iv_unitPos),
             "Error getting DMI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set the membuf target associated with this DMI
    for (auto membuf_itr = l_associatedMembufs.begin();
         membuf_itr != l_associatedMembufs.end();
         ++membuf_itr)
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>l_membuf = (*membuf_itr);

        // Set the membuf associated with this DMI
        iv_membuf = l_membuf;
    }

    // Display this DMI's attribute info
    FAPI_INF("EffGroupingDmiAttrs::getAttrs: DMI %d: iv_dimmSize %d GB ",
             iv_unitPos, iv_dimmSize);

fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingDmiAttrs::getAttrs");
    return fapi2::current_err;
}


///----------------------------------------------------------------------------
/// struct EffGroupingMemInfo
///----------------------------------------------------------------------------
///
/// @struct EffGroupingMemInfo
/// Contains Memory Information for a processor chip.
///
/// Nimbus - 4 MCS total, 2 MCA ports per MCS, 2 DIMMSs per MCA port
///
///          MCS0 --> MCA port0 --> DIMM0
///                                 DIMM1
///                   MCA port1 --> DIMM0
///                                 DIMM1
///          MCS1 --> MCA port2 --> DIMM0
///                                 DIMM1
///                   MCA port3 --> DIMM0
///                                 DIMM1
///          MCS2 --> MCA port4 --> DIMM0
///                                 DIMM1
///                   MCA port5 --> DIMM0
///                                 DIMM1
///          MCS3 --> MCA port6 --> DIMM0
///                                 DIMM1
///                   MCA port7 --> DIMM0
///                                 DIMM1
///          ----------------------------
///   Total   4           8
///
///
/// Cumulus - 4 MIs total, each MI has 2 DMIs (MC ports) with memBufs
///           connected.
///           Each memBuf has 2 MBAs, each MBA has 2 DRAM ports, each
///           DRAM port has 2 DIMMs
///
///          MI0 --> DMI0 --> memBuf --> MBA01 --> Port0 --> DIMM0
///                                                          DIMM1
///                                                Port1 --> DIMM0
///                                                          DIMM1
///                                      MBA23 --> Port2 --> DIMM0
///                                                          DIMM1
///                                                Port3 --> DIMM0
///                                                          DIMM1
///
///                  DMI1 --> memBuf --> MBA01 --> Port0 --> DIMM0
///                                                          DIMM1
///                                                Port1 --> DIMM0
///                                                          DIMM1
///                                      MBA23 --> Port2 --> DIMM0
///                                                          DIMM1
///                                                Port3 --> DIMM0
///                                                          DIMM1
///          ......
///          ......
///
///          MI3 --> DMI6 --> memBuf --> MBA01 --> Port0 --> DIMM0
///                                                          DIMM1
///                                                Port1 --> DIMM0
///                                                          DIMM1
///                                      MBA23 --> Port2 --> DIMM0
///                                                          DIMM1
///                                                Port3 --> DIMM0
///                                                          DIMM1
///
///                  DMI7 --> memBuf --> MBA01 --> Port0 --> DIMM0
///                                                          DIMM1
///                                                Port1 --> DIMM0
///                                                          DIMM1
///                                      MBA23 --> Port2 --> DIMM0
///                                                          DIMM1
///                                                Port3 --> DIMM0
///                                                          DIMM1
///   ----------------------------------------------------------------
///   Total  4        8
///
struct EffGroupingMemInfo
{
    // Constructor
    EffGroupingMemInfo()
    {
        memset(iv_portSize, 0, sizeof(iv_portSize));
    }

    ///
    /// @brief Gets the memory information of a processor
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getMemInfo(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

    // Mark if this proc is a Nimbus
    bool iv_nimbusProc = false;

    // Memory sizes behind MC ports
    uint32_t iv_portSize[NUM_MC_PORTS_PER_PROC];

};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingMemInfo::getMemInfo (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Memory info will be filled in differently for Nimbus vs Cumulus
    // due to chip structure

    // Get the functional MCAs
    auto l_mcaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCA>();

    if (l_mcaChiplets.size() > 0)
    {
        FAPI_DBG("Number of MCAs found: %d", l_mcaChiplets.size());

        // MCA found, proc is a Nimbus.
        iv_nimbusProc = true;

        for (auto l_mca : l_mcaChiplets)
        {
            // Get the MCA attributes
            EffGroupingMcaAttrs l_mcaAttrs;
            FAPI_TRY(l_mcaAttrs.getAttrs(l_mca),
                     "l_mcaAttrs.getAttrs() returns error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
            // Get the mem size behind this MCA
            iv_portSize[l_mcaAttrs.iv_unitPos] = l_mcaAttrs.iv_dimmSize;
        }
    }
    else
    {
        auto l_dmiChiplets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();

        if (l_dmiChiplets.size() > 0)
        {
            FAPI_DBG("Number of DMIs found: %d", l_dmiChiplets.size());

            // DMI found, proc is a Cumulus.
            for (auto l_dmmi : l_dmiChiplets)
            {
                // Get this DMI attribute info
                EffGroupingDmiAttrs l_dmiAttrs;
                FAPI_TRY(l_dmiAttrs.getAttrs(l_dmmi),
                         "l_dmiAttrs.getAttrs() returns error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                // Fill in memory info
                iv_portSize[l_dmiAttrs.iv_unitPos] = l_dmiAttrs.iv_dimmSize;
            }
        }
        else
        {
            // Note: You may have none of DMI nor MCA but it's a valid state;
            // therefore don't flag an error
            FAPI_INF("No MCA or DMI found in this proc target");
        }
    }

    // Display amount of memory for each MC port
    for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
    {
        FAPI_INF("MCport[%d] = %d GB", ii, iv_portSize[ii]);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingMemInfo
///----------------------------------------------------------------------------
///
/// @struct EffGroupingData
/// Contains Effective Grouping Data for a processor chip.
///
struct EffGroupingData
{
    // Constructor
    EffGroupingData()
    {
        memset(iv_data, 0, sizeof(iv_data));

        for (uint8_t l_port = 0; l_port < NUM_MC_PORTS_PER_PROC; l_port++)
        {
            iv_portGrouped[l_port] = false;
        }
    }

    // The ATTR_MSS_MCS_GROUP_32 attribute
    uint32_t iv_data[DATA_GROUPS][DATA_ELEMENTS];

    // The ports that have been grouped
    bool iv_portGrouped[NUM_MC_PORTS_PER_PROC];

    // The number of groups
    uint8_t iv_numGroups = 0;

    // The total non-mirrored memory size in GB
    uint32_t iv_totalSizeNonMirr = 0;
};


///----------------------------------------------------------------------------
/// struct EffGroupingBaseSizeData
///----------------------------------------------------------------------------
struct EffGroupingBaseSizeData
{
    // Constructor
    EffGroupingBaseSizeData()
    {
        memset(iv_mem_bases, 0, sizeof(iv_mem_bases));
        memset(iv_mem_bases_ack, 0, sizeof(iv_mem_bases_ack));
        memset(iv_memory_sizes, 0, sizeof(iv_memory_sizes));
        memset(iv_memory_sizes_ack, 0, sizeof(iv_memory_sizes_ack));
        memset(iv_mirror_bases, 0, sizeof(iv_mirror_bases));
        memset(iv_mirror_bases_ack, 0, sizeof(iv_mirror_bases_ack));
        memset(iv_mirror_sizes, 0, sizeof(iv_mirror_sizes));
        memset(iv_mirror_sizes_ack, 0, sizeof(iv_mirror_sizes_ack));
        memset(iv_htm_bar_bases, 0, sizeof(iv_htm_bar_bases));
    }

    ///
    /// @brief setBaseSizeData
    /// Function that set base and size values for both mirror
    /// and non-mirror.
    ///
    /// @param[in] i_sysAttrs    System attribute settings
    /// @param[in] i_groupData   Effective grouping data info
    ///
    /// @return void.
    ///
    void setBaseSizeData(const EffGroupingSysAttrs& i_sysAttrs,
                         const EffGroupingData& i_groupData);

    ///
    /// @brief Setting HTM and OCC base address based on HTM/OCC bar size
    ///
    /// @param[in] i_target       Reference to Processor Chip Target
    /// @param[in] i_sysAttrs     System attribute settings
    /// @param[in] i_groupData    Effective grouping data info
    /// @param[in] i_procAttrs    Proc attribute values
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode set_HTM_OCC_base_addr(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs& i_sysAttrs,
        const EffGroupingData& i_groupData,
        const EffGroupingProcAttrs& i_procAttrs);

    ///
    /// @brief setBaseSizeAttr
    /// Function that set base and size attribute values for both mirror
    /// and non-mirror based on given base/size data.
    ///
    /// @param[in]     i_target      Reference to Processor Chip Target
    /// @param[in]     i_sysAttrs    System attribute settings
    /// @param[in/out] i_groupData   Effective grouping data info
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode setBaseSizeAttr(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs& i_sysAttrs,
        EffGroupingData& io_groupData);

    // Public data
    uint64_t iv_mem_bases[NUM_NON_MIRROR_REGIONS];
    uint64_t iv_mem_bases_ack[NUM_NON_MIRROR_REGIONS];
    uint64_t iv_memory_sizes[NUM_NON_MIRROR_REGIONS];
    uint64_t iv_memory_sizes_ack[NUM_NON_MIRROR_REGIONS];

    uint64_t iv_mirror_bases[NUM_MIRROR_REGIONS];
    uint64_t iv_mirror_bases_ack[NUM_MIRROR_REGIONS];
    uint64_t iv_mirror_sizes[NUM_MIRROR_REGIONS];
    uint64_t iv_mirror_sizes_ack[NUM_MIRROR_REGIONS];

    uint64_t iv_occ_sandbox_base = 0;
    uint64_t iv_htm_bar_bases[NUM_OF_HTM_REGIONS];
};

// See description in struct definition
void EffGroupingBaseSizeData::setBaseSizeData(
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingData& i_groupData)
{
    FAPI_DBG("Entering");

    // Process non-mirrored ranges
    for (uint8_t ii = 0; ii < (DATA_GROUPS / 2); ii++) // 0-7 --> Non mirror
    {
        // Base addresses for distinct non-mirrored ranges
        iv_mem_bases[ii]     = i_groupData.iv_data[ii][BASE_ADDR];
        iv_mem_bases_ack[ii] = i_groupData.iv_data[ii][BASE_ADDR];
        iv_memory_sizes[ii]  = i_groupData.iv_data[ii][PORT_SIZE] *
                               i_groupData.iv_data[ii][PORTS_IN_GROUP];
        iv_memory_sizes_ack[ii] = i_groupData.iv_data[ii][GROUP_SIZE];

        // Convert to full byte addresses
        iv_mem_bases[ii]        <<= 30;
        iv_mem_bases_ack[ii]    <<= 30;
        iv_memory_sizes[ii]     <<= 30;
        iv_memory_sizes_ack[ii] <<= 30;

        FAPI_DBG("Non-mirror, Group %d:", ii);
        FAPI_DBG("    i_groupData.iv_data[%d][BASE_ADDR] = 0x%.16llX",
                 ii,  i_groupData.iv_data[ii][BASE_ADDR]);
        FAPI_DBG("    i_groupData.iv_data[%d][PORT_SIZE] = %d",
                 ii,  i_groupData.iv_data[ii][PORT_SIZE]);
        FAPI_DBG("    i_groupData.iv_data[%d][PORTS_IN_GROUP] = %d",
                 ii,  i_groupData.iv_data[ii][PORTS_IN_GROUP]);
        FAPI_DBG("    iv_mem_bases[%d] = 0x%.16llX", ii, iv_mem_bases[ii]);
        FAPI_DBG("    iv_mem_bases_ack[%d] = 0x%.16llX", ii, iv_mem_bases_ack[ii]);
        FAPI_DBG("    iv_memory_sizes[%d] = %.16lld bytes", ii, iv_memory_sizes[ii]);
        FAPI_DBG("    iv_memory_sizes_ack[%d] = %.16lld bytes", ii, iv_memory_sizes_ack[ii]);
    }

    // Process mirrored ranges
    if (!i_sysAttrs.iv_enhancedNoMirrorMode)
    {
        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            uint8_t l_index = ii + MIRR_OFFSET;

            // Set base address for distinct mirrored ranges
            iv_mirror_bases[ii] = i_groupData.iv_data[l_index][BASE_ADDR];
            iv_mirror_bases_ack[ii] = i_groupData.iv_data[l_index][BASE_ADDR];

            // Set sizes for distinct mirrored ranges
            if (i_groupData.iv_data[ii][PORTS_IN_GROUP] > 1) // ii -> Non-mirror index
            {
                iv_mirror_sizes[ii] = (i_groupData.iv_data[ii][PORT_SIZE] *
                                       i_groupData.iv_data[ii][PORTS_IN_GROUP]) / 2;
            }

            iv_mirror_sizes_ack[ii] = i_groupData.iv_data[l_index][GROUP_SIZE];

            // Convert to full byte addresses
            iv_mirror_bases[ii]     <<= 30;
            iv_mirror_bases_ack[ii] <<= 30;
            iv_mirror_sizes[ii]     <<= 30;
            iv_mirror_sizes_ack[ii] <<= 30;

            FAPI_DBG("Mirror: %d", ii);
            FAPI_DBG("    i_groupData.iv_data[%d][BASE_ADDR] = 0x%.16llX",
                     l_index,  i_groupData.iv_data[l_index][BASE_ADDR]);
            FAPI_DBG("    i_groupData.iv_data[%d][PORTS_IN_GROUP] = %d",
                     ii,  i_groupData.iv_data[ii][PORTS_IN_GROUP]);
            FAPI_DBG("    i_groupData.iv_data[%d][PORT_SIZE] = %d",
                     ii, i_groupData.iv_data[ii][PORT_SIZE]);
            FAPI_DBG("    iv_mirror_bases[%d] = 0x%.16llX", ii, iv_mirror_bases[ii]);
            FAPI_DBG("    iv_mirror_bases_ack[%d] = 0x%.16llX", ii, iv_mirror_bases_ack[ii]);
            FAPI_DBG("    iv_mirror_sizes[%d] = %.16lld bytes", ii, iv_mirror_sizes[ii]);
            FAPI_DBG("    iv_mirror_sizes_ack[%d] = %.16lld bytes", ii, iv_mirror_sizes_ack[ii]);
        }
    }

    FAPI_DBG("Exiting");
    return;
}

// See description in struct definition
fapi2::ReturnCode EffGroupingBaseSizeData::set_HTM_OCC_base_addr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingData& i_groupData,
    const EffGroupingProcAttrs& i_procAttrs)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    uint64_t l_totalSize = 0;
    uint8_t l_memHole = 0;
    uint64_t l_htmSize = i_procAttrs.iv_htmBarSizes[0] +
                         i_procAttrs.iv_htmBarSizes[1];
    uint64_t l_htmOccSize = l_htmSize +
                            i_procAttrs.iv_occSandboxSize;

    // No HTM/OCC size desired, get out with FAPI2_RC_SUCCESS (by default).
    if (l_htmOccSize == 0)
    {
        FAPI_INF("set_HTM_OCC_base_addr: No HTM/OCC memory requested.");
        return l_rc;
    }

    // MEM_MIRROR_PLACEMENT_POLICY_NORMAL
    if (i_sysAttrs.iv_selectiveMode ==
        fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
    {
        for (uint8_t ii = 0; ii < NUM_NON_MIRROR_REGIONS; ii++)
        {
            l_totalSize += iv_memory_sizes[ii];

            for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
            {
                if (i_groupData.iv_data[ii][ALT_VALID(jj)])
                {
                    l_memHole++;
                }
            }
        }

        // If total memory is not enough for requested HTM & OCC, error
        FAPI_ASSERT(l_totalSize >= l_htmOccSize,
                    fapi2::MSS_EFF_GROUPING_NO_SPACE_FOR_HTM_OCC_BAR()
                    .set_TOTAL_SIZE(l_totalSize)
                    .set_HTM_BAR_SIZE_1(i_procAttrs.iv_htmBarSizes[0])
                    .set_HTM_BAR_SIZE_2(i_procAttrs.iv_htmBarSizes[1])
                    .set_OCC_SANDBOX_BAR_SIZE(i_procAttrs.iv_occSandboxSize)
                    .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_selectiveMode),
                    "EffGroupingBaseSizeData::set_HTM_OCC_base_addr: Required memory "
                    "space for the HTM and OCC SANDBOX BARS is not available. "
                    "Policy NORMAL, TotalSize 0x%.16llX, HtmOccSize 0x%.16llX",
                    l_totalSize, l_htmOccSize);


        uint64_t l_non_mirroring_size = l_totalSize - l_htmOccSize;
        uint64_t l_temp_size = 0;
        uint8_t l_index = 0;

        for (uint8_t ii = 0; ii < NUM_NON_MIRROR_REGIONS; ii++)
        {
            l_temp_size += iv_memory_sizes[ii];

            if (l_temp_size >= l_non_mirroring_size)
            {
                l_index = ii;
                break;
            }
        }

        if (l_memHole)
        {
            FAPI_ASSERT(iv_memory_sizes[l_index] >= l_htmOccSize,
                        fapi2::MSS_EFF_GROUPING_HTM_OCC_BAR_NOT_POSSIBLE()
                        .set_TOTAL_SIZE(l_totalSize)
                        .set_HTM_BAR_SIZE_1(i_procAttrs.iv_htmBarSizes[0])
                        .set_HTM_BAR_SIZE_2(i_procAttrs.iv_htmBarSizes[1])
                        .set_OCC_SANDBOX_BAR_SIZE(i_procAttrs.iv_occSandboxSize)
                        .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_selectiveMode),
                        "EffGroupingBaseSizeData::set_HTM_OCC_base_addr: Memory HTM/OCC "
                        "BAR not possible, Policy NORMAL, MemorySizes[%d] 0x%.16llX, "
                        "HtmOccSize 0x%.16llX",
                        l_index, iv_memory_sizes[l_index], l_htmOccSize);
        }
        else
        {
            for (uint8_t ii = l_index + 1; ii < NUM_NON_MIRROR_REGIONS; ii++)
            {
                if (iv_memory_sizes[ii])
                {
                    iv_memory_sizes[ii] = 0;
                }
            }
        }

        iv_memory_sizes[l_index] = iv_memory_sizes[l_index] -
                                   (l_temp_size - l_non_mirroring_size);

        // Setting HTM & OCC Base addresses
        if (l_htmSize < i_procAttrs.iv_occSandboxSize)
        {
            iv_occ_sandbox_base = iv_mem_bases[l_index] +
                                  iv_memory_sizes[l_index];
            iv_htm_bar_bases[0] = iv_occ_sandbox_base +
                                  i_procAttrs.iv_occSandboxSize;
            iv_htm_bar_bases[1] = iv_htm_bar_bases[0] +
                                  i_procAttrs.iv_htmBarSizes[0];
        }
        else
        {
            iv_htm_bar_bases[0] = iv_mem_bases[l_index] +
                                  iv_memory_sizes[l_index];
            iv_htm_bar_bases[1] = iv_htm_bar_bases[0] +
                                  i_procAttrs.iv_htmBarSizes[0];
            iv_occ_sandbox_base = iv_htm_bar_bases[1] +
                                  i_procAttrs.iv_htmBarSizes[1];
        }

        FAPI_INF("EffGroupingBaseSizeData::set_HTM_OCC_base_addr: NORMAL");
        FAPI_INF("  Total memory 0x%.16llX, Required HtmOccSize 0x%.16llX",
                 l_totalSize, l_htmOccSize);
        FAPI_INF("  Index: %d, iv_mem_bases 0x%.16llX, iv_memory_sizes 0x%.16llX",
                 l_index, iv_mem_bases[l_index], iv_memory_sizes[l_index]);
        FAPI_INF("HTM_BASE[0] 0x%.16llX, HTM_BASE[1] 0x%.16llX, OCC_BASE 0x%.16llX",
                 iv_htm_bar_bases[0], iv_htm_bar_bases[1],
                 iv_occ_sandbox_base);
    }
    // MEM_MIRROR_PLACEMENT_POLICY_FLIPPED
    else if (i_sysAttrs.iv_selectiveMode ==
             fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
    {
        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS ; ii++)
        {
            l_totalSize += iv_mirror_sizes[ii];

            for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
            {
                if (i_groupData.iv_data[ii][ALT_VALID(jj)])
                {
                    l_memHole++;
                }
            }
        }

        // Check available total memory, if not enough for requested HTM & OCC
        // size, error out
        FAPI_ASSERT(l_totalSize >= l_htmOccSize,
                    fapi2::MSS_EFF_GROUPING_NO_SPACE_FOR_HTM_OCC_BAR()
                    .set_TOTAL_SIZE(l_totalSize)
                    .set_HTM_BAR_SIZE_1(i_procAttrs.iv_htmBarSizes[0])
                    .set_HTM_BAR_SIZE_2(i_procAttrs.iv_htmBarSizes[1])
                    .set_OCC_SANDBOX_BAR_SIZE(i_procAttrs.iv_occSandboxSize)
                    .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_selectiveMode),
                    "EffGroupingBaseSizeData::set_HTM_OCC_base_addr: Required memory "
                    "space for the HTM and OCC SANDBOX BARS is not available. "
                    "Policy FLIPPED, TotalSize 0x%.16llX, HtmOccSize 0x%.16llX",
                    l_totalSize, l_htmOccSize);

        uint64_t l_mirroring_size = l_totalSize - l_htmOccSize;
        uint64_t l_temp_size = 0;
        uint8_t l_index = 0;

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            l_temp_size += iv_mirror_sizes[ii];

            if (l_temp_size >= l_mirroring_size)
            {
                l_index = ii;
                break;
            }
        }

        if (l_memHole)
        {
            FAPI_ASSERT(iv_mirror_sizes[l_index] >= l_htmOccSize,
                        fapi2::MSS_EFF_GROUPING_HTM_OCC_BAR_NOT_POSSIBLE()
                        .set_TOTAL_SIZE(l_totalSize)
                        .set_HTM_BAR_SIZE_1(i_procAttrs.iv_htmBarSizes[0])
                        .set_HTM_BAR_SIZE_2(i_procAttrs.iv_htmBarSizes[1])
                        .set_OCC_SANDBOX_BAR_SIZE(i_procAttrs.iv_occSandboxSize)
                        .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_selectiveMode),
                        "EffGroupingBaseSizeData::set_HTM_OCC_base_addr Memory HTM/OCC "
                        "BAR not possible, Policy FLIPPED, MemorySizes[%d] 0x%.16llX, "
                        "HtmOccSize 0x%.16llX",
                        l_index, iv_mirror_sizes[l_index], l_htmOccSize);
        }
        else
        {
            for (uint8_t ii = l_index + 1; ii < NUM_MIRROR_REGIONS; ii++)
            {
                if (iv_mirror_sizes[ii])
                {
                    iv_mirror_sizes[ii] = 0;
                }
            }
        }

        iv_mirror_sizes[l_index] = iv_mirror_sizes[l_index] -
                                   (l_temp_size - l_mirroring_size);

        if (l_htmSize < i_procAttrs.iv_occSandboxSize)
        {
            iv_occ_sandbox_base = iv_mirror_bases[l_index] +
                                  iv_mirror_sizes[l_index];
            iv_htm_bar_bases[0] = iv_occ_sandbox_base +
                                  i_procAttrs.iv_occSandboxSize;
            iv_htm_bar_bases[1] = iv_htm_bar_bases[0] +
                                  i_procAttrs.iv_htmBarSizes[0];
        }
        else
        {
            iv_htm_bar_bases[0] = iv_mirror_bases[l_index] +
                                  iv_mirror_sizes[l_index];
            iv_htm_bar_bases[1] = iv_htm_bar_bases[0] +
                                  i_procAttrs.iv_htmBarSizes[0];
            iv_occ_sandbox_base = iv_htm_bar_bases[1] +
                                  i_procAttrs.iv_htmBarSizes[1];
        }

        FAPI_INF("EffGroupingBaseSizeData::set_HTM_OCC_base_addr: FLIPPED");
        FAPI_INF("  Total memory 0x%.16llX, Required HtmOccSize 0x%16llX",
                 l_totalSize, l_htmOccSize);
        FAPI_INF("  Index: %d, iv_mirror_bases 0x%.16llX, "
                 "iv_mirror_sizes 0x%.16llX",
                 l_index, iv_mirror_bases[l_index], iv_mirror_sizes[l_index]);
        FAPI_INF("HTM_BASE[0] 0x%.16llX, HTM_BASE[1] 0x%.16llX, OCC_BASE 0x%.16llX",
                 iv_htm_bar_bases[0], iv_htm_bar_bases[1],
                 iv_occ_sandbox_base);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


// See description in struct definition
fapi2::ReturnCode EffGroupingBaseSizeData::setBaseSizeAttr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs& i_sysAttrs,
    EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    //----------------------------------------------------------------------
    //  Setting attributes
    //----------------------------------------------------------------------

    // Set ATTR_PROC_MEM_BASES
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MEM_BASES, i_target, iv_mem_bases),
             "Error setting ATTR_PROC_MEM_BASES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_MEM_BASES_ACK
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MEM_BASES_ACK, i_target, iv_mem_bases_ack),
             "Error setting ATTR_PROC_MEM_BASES_ACK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_MEM_SIZES
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MEM_SIZES, i_target, iv_memory_sizes),
             "Error setting ATTR_PROC_MEM_SIZES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_MEM_SIZES_ACK
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MEM_SIZES_ACK, i_target,
                           iv_memory_sizes_ack),
             "Error setting ATTR_PROC_MEM_SIZES_ACK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_MSS_MCS_GROUP_32
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MCS_GROUP_32, i_target,
                           io_groupData.iv_data),
             "Error setting ATTR_MSS_MCS_GROUP_32, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_HTM_BAR_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_HTM_BAR_BASE_ADDR, i_target,
                           iv_htm_bar_bases),
             "Error setting ATTR_PROC_HTM_BAR_BASE_ADDR, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_OCC_SANDBOX_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_OCC_SANDBOX_BASE_ADDR, i_target,
                           iv_occ_sandbox_base),
             "Error setting ATTR_PROC_OCC_SANDBOX_BASE_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Mirror mode attribute setting
    if (!i_sysAttrs.iv_enhancedNoMirrorMode)
    {

        // Set ATTR_PROC_MIRROR_BASES
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_BASES, i_target,
                               iv_mirror_bases),
                 "Error setting ATTR_PROC_MIRROR_BASES, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Set ATTR_PROC_MIRROR_BASES_ACK
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_BASES_ACK, i_target,
                               iv_mirror_bases_ack),
                 "Error setting ATTR_PROC_MIRROR_BASES_ACK, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Set ATTR_PROC_MIRROR_SIZES
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_SIZES, i_target,
                               iv_mirror_sizes),
                 "Error setting ATTR_PROC_MIRROR_SIZES, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Set ATTR_PROC_MIRROR_SIZES_ACK
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_SIZES_ACK, i_target,
                               iv_mirror_sizes_ack),
                 "Error setting ATTR_PROC_MIRROR_SIZES_ACK, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }

    //----------------------------------------------------------------------
    //  Display attribute values
    //----------------------------------------------------------------------

    for (uint8_t ii = 0; ii < NUM_NON_MIRROR_REGIONS; ii++)
    {
        FAPI_INF("ATTR_PROC_MEM_BASES    [%u]: 0x%.16llX", ii, iv_mem_bases[ii]);
        FAPI_INF("ATTR_PROC_MEM_BASES_ACK[%u]: 0x%.16llX", ii, iv_mem_bases_ack[ii]);
        FAPI_INF("ATTR_PROC_MEM_SIZES    [%u]: 0x%.16llX", ii, iv_memory_sizes[ii]);
        FAPI_INF("ATTR_PROC_MEM_SIZES_ACK[%u]: 0x%.16llX", ii, iv_memory_sizes_ack[ii]);
    }

    FAPI_INF("ATTR_PROC_HTM_BAR_BASE_ADDR[0] : 0x%.16llX", iv_htm_bar_bases[0]);
    FAPI_INF("ATTR_PROC_HTM_BAR_BASE_ADDR[1] : 0x%.16llX", iv_htm_bar_bases[1]);
    FAPI_INF("ATTR_PROC_OCC_SANDBOX_BASE_ADDR: 0x%.16llX", iv_occ_sandbox_base);

    // Display mirror mode attribute values
    if (!i_sysAttrs.iv_enhancedNoMirrorMode)
    {
        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            FAPI_INF("ATTR_PROC_MIRROR_BASES[%u]: 0x%.16llX",
                     ii, iv_mirror_bases[ii]);
        }

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            FAPI_INF("ATTR_PROC_MIRROR_BASES_ACK[%u] "
                     "0x%.16llX", ii, iv_mirror_bases_ack[ii]);
        }

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            FAPI_INF("ATTR_PROC_MIRROR_SIZES[%u]: 0x%.16llX",
                     ii, iv_mirror_sizes[ii]);
        }

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            FAPI_INF("ATTR_PROC_MIRROR_SIZES_ACK[%u]: 0x%.16llX",
                     ii, iv_mirror_sizes_ack[ii]);
        }
    }

    // Display ATTR_MSS_MCS_GROUP_32 as debug trace
    for (uint8_t ii = 0; ii < DATA_GROUPS; ii++)
    {
        for (uint8_t jj = 0; jj < DATA_ELEMENTS; jj++)
        {
            FAPI_DBG("ATTR_MSS_MCS_GROUP_32[%u][%u] : 0x%.8X",
                     ii, jj, io_groupData.iv_data[ii][jj]);
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------

///
/// @brief grouping_checkValidAttributes
/// Function that checks to make sure the obtained memory grouping
//  attributes are valid.
///
/// @param[in] i_target    Reference to Processor Chip Target
/// @param[in] i_sysAttrs  Reference to system attributes
/// @param[in] i_procAttrs Reference to proc chip attributes
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode grouping_checkValidAttributes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingProcAttrs& i_procAttrs)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // If mirror is disabled, then can not be in FLIPPED mode
    if (i_sysAttrs.iv_enhancedNoMirrorMode)
    {
        FAPI_ASSERT(i_sysAttrs.iv_selectiveMode !=
                    fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED,
                    fapi2::MSS_EFF_CONFIG_MIRROR_DISABLED()
                    .set_MRW_ENHANCED_GROUPING_NO_MIRRORING(
                        i_sysAttrs.iv_enhancedNoMirrorMode)
                    .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_selectiveMode),
                    "grouping_checkValidAttributes: Error: Mirroring disabled "
                    "but ATTR_MEM_MIRROR_PLACEMENT_POLICY is in FLIPPED mode");
    }

    // There must be at least one type of grouping allowed
    // Unused bits are don't care (i.e.: 0x10, 040)
    FAPI_ASSERT( ((i_procAttrs.iv_groupsAllowed & ALL_GROUPS) != 0),
                 fapi2::MSS_EFF_GROUPING_NO_GROUP_ALLOWED()
                 .set_MSS_INTERLEAVE_ENABLE_VALUE(i_procAttrs.iv_groupsAllowed)
                 .set_CHIP(i_target),
                 "grouping_checkValidAttributes: No valid group type allowed" );

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Attempts to group 8 ports per group
///
/// If they can be grouped, fills in the following fields in o_groupData:
///  - iv_data[<group>][PORT_SIZE]
///  - iv_data[<group>][PORTS_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_portGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
///  @param[out] o_groupData Reference to output data
///
void grouping_group8PortsPerGroup(const EffGroupingMemInfo& i_memInfo,
                                  EffGroupingData& o_groupData)
{
    // There are 8 MC ports (MCA) in a Nimbus and they can be grouped
    // together if they all have the same memory size (assumed that no ports
    // have already been grouped
    FAPI_DBG("Entering");

    FAPI_INF("grouping_group8PortsPerGroup: Attempting to group 8 MC ports");
    uint8_t& g = o_groupData.iv_numGroups;

    if ( i_memInfo.iv_portSize[0] != 0 )
    {
        // First MC port has memory
        bool grouped = true;

        for (uint8_t l_pos = 1; l_pos < NUM_MC_PORTS_PER_PROC; l_pos++)
        {
            if (i_memInfo.iv_portSize[0] != i_memInfo.iv_portSize[l_pos])
            {
                // This group port does not have the same size as port 0
                // Can't group by 8
                FAPI_DBG("Can not group by 8: ");
                FAPI_DBG("   i_memInfo.iv_portSize[0] = %d GB", i_memInfo.iv_portSize[0]);
                FAPI_DBG("   i_memInfo.iv_portSize[%d] = %d GB",
                         l_pos, i_memInfo.iv_portSize[l_pos]);
                grouped = false;
                break;
            }
        }

        // Group of 8 is possible
        if (grouped)
        {
            // All 8 ports have same amount of memory, group them
            o_groupData.iv_data[g][PORT_SIZE] = i_memInfo.iv_portSize[0];
            o_groupData.iv_data[g][PORTS_IN_GROUP] = 8;
            o_groupData.iv_data[g][GROUP_SIZE] =
                (NUM_MC_PORTS_PER_PROC * i_memInfo.iv_portSize[0]);
            o_groupData.iv_data[g][MEMBER_IDX(0)] = MCPORTID_0;
            o_groupData.iv_data[g][MEMBER_IDX(1)] = MCPORTID_4;
            o_groupData.iv_data[g][MEMBER_IDX(2)] = MCPORTID_2;
            o_groupData.iv_data[g][MEMBER_IDX(3)] = MCPORTID_6;
            o_groupData.iv_data[g][MEMBER_IDX(4)] = MCPORTID_1;
            o_groupData.iv_data[g][MEMBER_IDX(5)] = MCPORTID_5;
            o_groupData.iv_data[g][MEMBER_IDX(6)] = MCPORTID_3;
            o_groupData.iv_data[g][MEMBER_IDX(7)] = MCPORTID_7;
            g++; // increase o_groupData.iv_numGroups

            // Record which MC ports were grouped
            for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
            {
                o_groupData.iv_portGrouped[ii] = true;
            }

            FAPI_INF("grouping_group8PortsPerGroup: Successfully grouped 8 "
                     "MC ports.");
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 6 ports per group
///
/// If they can be grouped, fills in the following fields in o_groupData:
///  - iv_data[<group>][PORT_SIZE]
///  - iv_data[<group>][PORTS_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_portGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
///  @param[out] o_groupData Reference to output data
///
void grouping_group6PortsPerGroup(const EffGroupingMemInfo& i_memInfo,
                                  EffGroupingData& o_groupData)
{
    FAPI_DBG("Entering");

    FAPI_INF("grouping_group6PortsPerGroup: Attempting to group 6 MC ports");
    uint8_t& g = o_groupData.iv_numGroups;

    // The following is all the allowed ways of grouping 6 MC ports per group.
    // Earlier array entries are higher priority.
    const uint8_t NUM_WAYS_6MCPORTS_PER_GROUP = 4;
    const uint8_t PORTS_PER_GROUP = 6;
    const uint8_t CFG_6MCPORT[NUM_WAYS_6MCPORTS_PER_GROUP][PORTS_PER_GROUP] =
    {
        { MCPORTID_0, MCPORTID_1, MCPORTID_2, MCPORTID_3, MCPORTID_4, MCPORTID_5 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_2, MCPORTID_3, MCPORTID_6, MCPORTID_7 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_4, MCPORTID_5, MCPORTID_6, MCPORTID_7 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_4, MCPORTID_5, MCPORTID_6, MCPORTID_7 },
    };

    // Figure out which group of 6 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_6MCPORTS_PER_GROUP; ii++)
    {
        // Skip if first MC port entry is already grouped or has no memory
        if ( (o_groupData.iv_portGrouped[CFG_6MCPORT[ii][0]]) ||
             (i_memInfo.iv_portSize[CFG_6MCPORT[ii][0]] == 0) )

        {
            FAPI_DBG("CFG_6MCPORT[%d][0] is already grouped or has no memory:", ii);
            FAPI_DBG("    o_groupData.iv_portGrouped[CFG_6MCPORT[%d][0]] = %d",
                     ii, o_groupData.iv_portGrouped[CFG_6MCPORT[ii][0]]);
            FAPI_DBG("    i_memInfo.iv_portSize[CFG_6MCPORT[%d][0]] = %d",
                     ii, i_memInfo.iv_portSize[CFG_6MCPORT[ii][0]]);
            continue;
        }

        // Check the remaining MC port ids (horizontally) in this
        // CFG_6MCPORT[ii]
        // If they are not yet grouped and have the same amount of memory
        // as the first entry, then they can be grouped together of 6.
        bool potential_group = true;

        for (uint8_t jj = 1; jj < PORTS_PER_GROUP; jj++)
        {
            FAPI_DBG("Checking CFG_6MCPORT[%d][%d]: MCPORTID %d:",
                     ii, jj, CFG_6MCPORT[ii][jj]);

            if ( (o_groupData.iv_portGrouped[CFG_6MCPORT[ii][jj]]) ||
                 (i_memInfo.iv_portSize[CFG_6MCPORT[ii][0]] !=
                  i_memInfo.iv_portSize[CFG_6MCPORT[ii][jj]]) )
            {
                // This port is already grouped or does not have the same
                // size as first entry CFG_6MCPORT[ii][0]
                FAPI_DBG("   Unable to group way by 6: ");
                FAPI_DBG("      o_groupData.iv_portGrouped[CFG_6MCPORT[%d][%d]] = %d",
                         ii, jj, o_groupData.iv_portGrouped[CFG_6MCPORT[ii][jj]]);
                FAPI_DBG("      i_memInfo.iv_portSize[CFG_6MCPORT[%d][0]] = %d GB",
                         ii, i_memInfo.iv_portSize[CFG_6MCPORT[ii][0]]);
                FAPI_DBG("      i_memInfo.iv_portSize[CFG_6MCPORT[%d][%d]] = %d GB",
                         ii, jj, i_memInfo.iv_portSize[CFG_6MCPORT[ii][jj]]);
                potential_group = false;
                break;
            }
        }

        // Group of 6 is possible
        if (potential_group)
        {
            o_groupData.iv_data[g][PORT_SIZE] =
                i_memInfo.iv_portSize[CFG_6MCPORT[ii][0]];
            o_groupData.iv_data[g][PORTS_IN_GROUP] = PORTS_PER_GROUP;
            o_groupData.iv_data[g][GROUP_SIZE] =
                PORTS_PER_GROUP * i_memInfo.iv_portSize[CFG_6MCPORT[ii][0]];

            // Record which MC ports were grouped
            for (uint8_t jj = 0; jj < PORTS_PER_GROUP; jj++)
            {
                o_groupData.iv_data[g][MEMBER_IDX(jj)] = CFG_6MCPORT[ii][jj];
                o_groupData.iv_portGrouped[CFG_6MCPORT[ii][jj]] = true;
            }

            g++;

            FAPI_INF("grouping_group6PortsPerGroup: Successfuly group 6 MC "
                     "ports.  CFG_6MCPORT[%d]: %u, %u, %u, %u, %u, %u",
                     ii,
                     CFG_6MCPORT[ii][0], CFG_6MCPORT[ii][1],
                     CFG_6MCPORT[ii][2], CFG_6MCPORT[ii][3],
                     CFG_6MCPORT[ii][4], CFG_6MCPORT[ii][5]);
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 4 ports per group
///
/// If they can be grouped, fills in the following fields in o_groupData:
///  - iv_data[<group>][PORT_SIZE]
///  - iv_data[<group>][PORTS_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_portGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
///  @param[out] o_groupData Reference to output data
///
void grouping_group4PortsPerGroup(const EffGroupingMemInfo& i_memInfo,
                                  EffGroupingData& o_groupData)
{
    FAPI_DBG("Entering");

    // The following is all the allowed ways of grouping 4 MC ports per group.
    // Earlier array entries are higher priority.
    // First try to group 2 sets of 4 (0/1, 2/3 or 4/5)
    // If no success then try to group 1 set of 4
    FAPI_INF("grouping_group4PortsPerGroup: Attempting to group 4 MC ports");
    uint8_t& g = o_groupData.iv_numGroups;

    const uint8_t NUM_WAYS_4MCPORTS_PER_GROUP = 6;
    const uint8_t PORTS_PER_GROUP = 4;
    const uint8_t CFG_4MCPORT[NUM_WAYS_4MCPORTS_PER_GROUP][PORTS_PER_GROUP] =
    {
        { MCPORTID_0, MCPORTID_1, MCPORTID_4, MCPORTID_5 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_6, MCPORTID_7 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_6, MCPORTID_7 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_4, MCPORTID_5 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_2, MCPORTID_3 },
        { MCPORTID_4, MCPORTID_5, MCPORTID_6, MCPORTID_7 }
    };

    // Array recording which groups of 4 can potentially be grouped
    uint8_t config4_gp[NUM_WAYS_4MCPORTS_PER_GROUP];
    memset(config4_gp, 0, sizeof(config4_gp));

    // Figure out which groups of 4 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_4MCPORTS_PER_GROUP; ii++)
    {
        // Skip if first MC port entry is already grouped or has no memory
        if ( (o_groupData.iv_portGrouped[CFG_4MCPORT[ii][0]]) ||
             (i_memInfo.iv_portSize[CFG_4MCPORT[ii][0]] == 0) )

        {
            FAPI_DBG("CFG_4MCPORT[%d][0] is already grouped or has no memory:", ii);
            FAPI_DBG("    o_groupData.iv_portGrouped[CFG_4MCPORT[%d][0]] = %d",
                     ii, o_groupData.iv_portGrouped[CFG_4MCPORT[ii][0]]);
            FAPI_DBG("    i_memInfo.iv_portSize[CFG_4MCPORT[%d][0]] = %d",
                     ii, i_memInfo.iv_portSize[CFG_4MCPORT[ii][0]]);
            continue;
        }

        // Check the remaining MC port ids (horizontally) in this
        // CFG_4MCPORT[ii]
        // If they are not yet grouped and have the same amount of memory
        // as the first entry, then they can be grouped together of 4.
        bool potential_group = true;

        for (uint8_t jj = 1; jj < PORTS_PER_GROUP; jj++)
        {
            FAPI_DBG("Checking CFG_4MCPORT[%d][%d]: MCPORTID %d:",
                     ii, jj, CFG_4MCPORT[ii][jj]);

            if ( (o_groupData.iv_portGrouped[CFG_4MCPORT[ii][jj]]) ||
                 (i_memInfo.iv_portSize[CFG_4MCPORT[ii][0]] !=
                  i_memInfo.iv_portSize[CFG_4MCPORT[ii][jj]]) )
            {
                // This port is already grouped or does not have the same
                // size as first entry CFG_4MCPORT[ii][0]
                FAPI_DBG("   Unable to group way by 4: ");
                FAPI_DBG("      o_groupData.iv_portGrouped[CFG_4MCPORT[%d][%d]] = %d",
                         ii, jj, o_groupData.iv_portGrouped[CFG_4MCPORT[ii][jj]]);
                FAPI_DBG("      i_memInfo.iv_portSize[CFG_4MCPORT[%d][0]] = %d GB",
                         ii, i_memInfo.iv_portSize[CFG_4MCPORT[ii][0]]);
                FAPI_DBG("      i_memInfo.iv_portSize[CFG_4MCPORT[%d][%d]] = %d GB",
                         ii, jj, i_memInfo.iv_portSize[CFG_4MCPORT[ii][jj]]);

                potential_group = false;
                break;
            }
        }

        // Group of 4 is possible
        if (potential_group)
        {
            FAPI_INF("    Potential group MC ports: MCPORTID %u, MCPORTID %u, MCPORTID %u, MCPORTID %u",
                     CFG_4MCPORT[ii][0], CFG_4MCPORT[ii][1],
                     CFG_4MCPORT[ii][2], CFG_4MCPORT[ii][3]);
            config4_gp[ii] = 1;
        }
    }

    // Figure out which groups of 4 to actually group
    uint8_t gp1 = 0xff;
    uint8_t gp2 = 0xff;

    // Check if 2 groups of 4 are possible (0/1, 2/3 or 4/5)
    for (uint8_t ii = 0; ii < NUM_WAYS_4MCPORTS_PER_GROUP; ii += 2)
    {
        if (config4_gp[ii] && config4_gp[ii + 1])
        {
            gp1 = ii;
            gp2 = ii + 1;
            break;
        }
    }

    if (gp1 == 0xff)
    {
        // 2 groups of 4 are not possible, look for 1 group of 4
        for (uint8_t ii = 0; ii < NUM_WAYS_4MCPORTS_PER_GROUP; ii++)
        {
            if (config4_gp[ii])
            {
                gp1 = ii;
                break;
            }
        }
    }

    // If gp1/gp2 marked as succesfful, update o_groupData
    if (gp1 != 0xff)
    {
        o_groupData.iv_data[g][PORT_SIZE] =
            i_memInfo.iv_portSize[CFG_4MCPORT[gp1][0]];
        o_groupData.iv_data[g][PORTS_IN_GROUP] = PORTS_PER_GROUP;
        o_groupData.iv_data[g][GROUP_SIZE] =
            PORTS_PER_GROUP * i_memInfo.iv_portSize[CFG_4MCPORT[gp1][0]];
        o_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_4MCPORT[gp1][0];
        o_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_4MCPORT[gp1][2];
        o_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_4MCPORT[gp1][1];
        o_groupData.iv_data[g][MEMBER_IDX(3)] = CFG_4MCPORT[gp1][3];
        g++;

        // Record which MC ports were grouped
        for (uint8_t ii = 0; ii < PORTS_PER_GROUP; ii++)
        {
            o_groupData.iv_portGrouped[CFG_4MCPORT[gp1][ii]] = true;
        }

        FAPI_INF("grouping_group4PortsPerGroup: Successfully grouped 4 "
                 "MC ports. CFG_4MCPORT[%d] %u, %u, %u, %u", gp1,
                 CFG_4MCPORT[gp1][0], CFG_4MCPORT[gp1][1],
                 CFG_4MCPORT[gp1][2], CFG_4MCPORT[gp1][3]);

    }

    if (gp2 != 0xff)
    {
        o_groupData.iv_data[g][PORT_SIZE] =
            i_memInfo.iv_portSize[CFG_4MCPORT[gp2][0]];
        o_groupData.iv_data[g][PORTS_IN_GROUP] = PORTS_PER_GROUP;
        o_groupData.iv_data[g][GROUP_SIZE] =
            PORTS_PER_GROUP * i_memInfo.iv_portSize[CFG_4MCPORT[gp2][0]];
        o_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_4MCPORT[gp2][0];
        o_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_4MCPORT[gp2][2];
        o_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_4MCPORT[gp2][1];
        o_groupData.iv_data[g][MEMBER_IDX(3)] = CFG_4MCPORT[gp2][3];
        g++;

        // Record which MC ports were grouped
        for (uint8_t ii = 0; ii < PORTS_PER_GROUP; ii++)
        {
            o_groupData.iv_portGrouped[CFG_4MCPORT[gp2][ii]] = true;
        }

        FAPI_INF("grouping_group4PortsPerGroup: Successfully grouped 4 "
                 "MC ports. CFG_4MCPORT[%d] %u, %u, %u, %u", gp2,
                 CFG_4MCPORT[gp2][0], CFG_4MCPORT[gp2][1],
                 CFG_4MCPORT[gp2][2], CFG_4MCPORT[gp2][3]);
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 3 ports per group
///
/// If they can be grouped, fills in the following fields in o_groupData:
///  - iv_data[<group>][PORT_SIZE]
///  - iv_data[<group>][PORTS_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_portGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
///  @param[out] o_groupData Reference to output data
///
void grouping_group3PortsPerGroup(const EffGroupingMemInfo& i_memInfo,
                                  EffGroupingData& o_groupData)
{
    FAPI_DBG("Entering");

    // The following is all the allowed ways of grouping 3 MC ports per group.
    // Earlier array entries are higher priority.
    FAPI_INF("grouping_group3PortsPerGroup: Attempting to group 3 MC ports");
    uint8_t& g = o_groupData.iv_numGroups;

    const uint8_t NUM_WAYS_3MCPORTS_PER_GROUP = 24;
    const uint8_t PORTS_PER_GROUP = 3;
    const uint8_t CFG_3MCPORT[NUM_WAYS_3MCPORTS_PER_GROUP][PORTS_PER_GROUP] =
    {
        { MCPORTID_0, MCPORTID_1, MCPORTID_2 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_3 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_4 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_5 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_6 },
        { MCPORTID_0, MCPORTID_1, MCPORTID_7 },

        { MCPORTID_2, MCPORTID_3, MCPORTID_0 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_1 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_4 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_5 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_6 },
        { MCPORTID_2, MCPORTID_3, MCPORTID_7 },

        { MCPORTID_4, MCPORTID_5, MCPORTID_0 },
        { MCPORTID_4, MCPORTID_5, MCPORTID_1 },
        { MCPORTID_4, MCPORTID_5, MCPORTID_2 },
        { MCPORTID_4, MCPORTID_5, MCPORTID_3 },
        { MCPORTID_4, MCPORTID_5, MCPORTID_6 },
        { MCPORTID_4, MCPORTID_5, MCPORTID_7 },

        { MCPORTID_6, MCPORTID_7, MCPORTID_0 },
        { MCPORTID_6, MCPORTID_7, MCPORTID_1 },
        { MCPORTID_6, MCPORTID_7, MCPORTID_2 },
        { MCPORTID_6, MCPORTID_7, MCPORTID_3 },
        { MCPORTID_6, MCPORTID_7, MCPORTID_4 },
        { MCPORTID_6, MCPORTID_7, MCPORTID_5 }
    };

    // Figure out which group of 3 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_3MCPORTS_PER_GROUP; ii++)
    {
        // Skip if first MC port entry is already grouped or has no memory
        if ( (o_groupData.iv_portGrouped[CFG_3MCPORT[ii][0]]) ||
             (i_memInfo.iv_portSize[CFG_3MCPORT[ii][0]] == 0) )

        {
            FAPI_DBG("CFG_3MCPORT[%d][0] is already grouped or has no memory:", ii);
            FAPI_DBG("    o_groupData.iv_portGrouped[CFG_3MCPORT[%d][0]] = %d",
                     ii, o_groupData.iv_portGrouped[CFG_3MCPORT[ii][0]]);
            FAPI_DBG("    i_memInfo.iv_portSize[CFG_3MCPORT[%d][0]] = %d",
                     ii, i_memInfo.iv_portSize[CFG_3MCPORT[ii][0]]);
            continue;
        }

        bool potential_group = true;

        for (uint8_t jj = 1; jj < PORTS_PER_GROUP; jj++)
        {
            FAPI_DBG("Checking CFG_3MCPORT[%d][%d]: MCPORTID %d:",
                     ii, jj, CFG_3MCPORT[ii][jj]);

            if ( (o_groupData.iv_portGrouped[CFG_3MCPORT[ii][jj]]) ||
                 (i_memInfo.iv_portSize[CFG_3MCPORT[ii][0]] !=
                  i_memInfo.iv_portSize[CFG_3MCPORT[ii][jj]]) )
            {
                // This port is already grouped or does not have the same
                // size as port 0
                FAPI_DBG("   Unable to group way by 3: ");
                FAPI_DBG("      o_groupData.iv_portGrouped[CFG_3MCPORT[%d][%d]] = %d",
                         ii, jj, o_groupData.iv_portGrouped[CFG_3MCPORT[ii][jj]]);
                FAPI_DBG("      i_memInfo.iv_portSize[CFG_3MCPORT[%d][0]] = %d GB",
                         ii, i_memInfo.iv_portSize[CFG_3MCPORT[ii][0]]);
                FAPI_DBG("      i_memInfo.iv_portSize[CFG_3MCPORT[%d][%d]] = %d GB",
                         ii, jj, i_memInfo.iv_portSize[CFG_3MCPORT[ii][jj]]);

                potential_group = false;
                break;
            }
        }

        // Group of 3 is possible
        if (potential_group)
        {
            o_groupData.iv_data[g][PORT_SIZE] =
                i_memInfo.iv_portSize[CFG_3MCPORT[ii][0]];
            o_groupData.iv_data[g][PORTS_IN_GROUP] = PORTS_PER_GROUP;
            o_groupData.iv_data[g][GROUP_SIZE] =
                PORTS_PER_GROUP * i_memInfo.iv_portSize[CFG_3MCPORT[ii][0]];
            o_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_3MCPORT[ii][0];
            o_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_3MCPORT[ii][1];
            o_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_3MCPORT[ii][2];
            g++;

            // Record which MC ports were grouped
            for (uint8_t jj = 0; jj < PORTS_PER_GROUP; jj++)
            {
                o_groupData.iv_portGrouped[CFG_3MCPORT[ii][jj]] = true;
            }

            FAPI_INF("grouping_group3PortsPerGroup: Successfully grouped 3 "
                     "MC ports. CFG_3MCPORT[%d] %u, %u, %u, %u", ii,
                     CFG_3MCPORT[ii][0], CFG_3MCPORT[ii][1],
                     CFG_3MCPORT[ii][2]);
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 2 ports per group
///
/// If they can be grouped, fills in the following fields in o_groupData:
///  - iv_data[<group>][PORT_SIZE]
///  - iv_data[<group>][PORTS_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_portGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
///  @param[out] o_groupData Reference to output data
///
void grouping_group2PortsPerGroup(const EffGroupingMemInfo& i_memInfo,
                                  EffGroupingData& o_groupData)
{
    FAPI_DBG("Entering");

    // Any two ports with the same amount of memory can be grouped together
    FAPI_INF("grouping_group2PortsPerGroup: Attempting to group 2 MC ports");
    uint8_t& g = o_groupData.iv_numGroups;
    const uint8_t PORTS_PER_GROUP = 2;

    for (uint8_t pos = 0; pos < NUM_MC_PORTS_PER_PROC; pos++)
    {
        // Skip if port is already grouped or has no memory
        if ( (o_groupData.iv_portGrouped[pos]) ||
             (i_memInfo.iv_portSize[pos] == 0) )

        {
            FAPI_DBG("Skip this port because already grouped or it doesn't have memory:");
            FAPI_DBG("    o_groupData.iv_portGrouped[%d] = %d", pos, o_groupData.iv_portGrouped[pos]);
            FAPI_DBG("    i_memInfo.iv_portSize[%d] = %d", pos, i_memInfo.iv_portSize[pos]);
            continue;
        }

        // If any of the remaining ungrouped port has the same amount of memory, group it
        for (uint8_t ii = pos + 1; ii < NUM_MC_PORTS_PER_PROC; ii++)
        {
            if ( (o_groupData.iv_portGrouped[ii]) ||
                 (i_memInfo.iv_portSize[ii] == 0) )
            {
                continue;
            }

            // Same amount of memory?
            if (i_memInfo.iv_portSize[pos] == i_memInfo.iv_portSize[ii])
            {
                o_groupData.iv_data[g][PORT_SIZE] = i_memInfo.iv_portSize[pos];
                o_groupData.iv_data[g][PORTS_IN_GROUP] = PORTS_PER_GROUP;
                o_groupData.iv_data[g][GROUP_SIZE] =
                    PORTS_PER_GROUP * i_memInfo.iv_portSize[pos];
                o_groupData.iv_data[g][MEMBER_IDX(0)] = pos;
                o_groupData.iv_data[g][MEMBER_IDX(1)] = ii;
                g++;

                // Record which MC ports were grouped
                o_groupData.iv_portGrouped[pos] = true;
                o_groupData.iv_portGrouped[ii] = true;

                FAPI_INF("grouping_group2PortsPerGroup: Successfully grouped 2 "
                         "MC ports: %u, %u", pos, ii);

                break; // Break out of remaining port loop
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 1 port per group
///
/// If they can be grouped, fills in the following fields in o_groupData:
///  - iv_data[<group>][PORT_SIZE]
///  - iv_data[<group>][PORTS_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_portGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo   Reference to EffGroupingMemInfo structure
///  @param[out] o_groupData Reference to output data
///
void grouping_group1PortsPerGroup(const EffGroupingMemInfo& i_memInfo,
                                  EffGroupingData& o_groupData)
{
    FAPI_DBG("Entering");

    // Any MC port with a non-zero size can be 'grouped'
    FAPI_INF("grouping_group1PortsPerGroup: Attempting to group 1 MC port");
    uint8_t& g = o_groupData.iv_numGroups;

    for (uint8_t pos = 0; pos < NUM_MC_PORTS_PER_PROC; pos++)
    {
        if ( (!o_groupData.iv_portGrouped[pos]) &&
             (i_memInfo.iv_portSize[pos] != 0) )
        {
            // This MCS is not already grouped and has memory
            o_groupData.iv_data[g][PORT_SIZE] = i_memInfo.iv_portSize[pos];
            o_groupData.iv_data[g][PORTS_IN_GROUP] = 1;
            o_groupData.iv_data[g][GROUP_SIZE] = i_memInfo.iv_portSize[pos];
            o_groupData.iv_data[g][MEMBER_IDX(0)] = pos;
            g++;

            // Record which MCS was grouped
            o_groupData.iv_portGrouped[pos] = true;
            FAPI_INF("grouping_group1PortsPerGroup: Successfully grouped 1 "
                     "MC port: %u", pos);

        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Finds ungrouped ports
///
/// If any are found then their associated MCA/Membuf chip is deconfigured
///
/// @param[in] i_mcChiplets  Reference to MC targets (MCA or MEMBUF)
/// @param[in] i_memInfo     Reference to Memory Info
/// @param[in] i_groupData   Reference to Group data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode grouping_findUngroupedPorts(
    const std::vector< fapi2::Target<T> >& i_mcTargets,
    const EffGroupingMemInfo& i_memInfo,
    const EffGroupingData& i_groupData);

// Specialization for MCA targets
template<>
fapi2::ReturnCode grouping_findUngroupedPorts(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> >& i_mcTargets,
    const EffGroupingMemInfo& i_memInfo,
    const EffGroupingData& i_groupData)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // std_pair<MC number, target>
    std::map<uint8_t, fapi2::Target<fapi2::TARGET_TYPE_MCA>> l_unGroupedPair;

    // Mark the MCs that are not grouped
    for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
    {
        if ( (i_memInfo.iv_portSize[ii] != 0) &&
             (i_groupData.iv_portGrouped[ii] == false) )
        {
            FAPI_ERR("grouping_findUngroupedPorts: Unable to group port %u", ii);

            for (auto l_mca : i_mcTargets)
            {
                // Get the MCA position
                uint8_t l_unitPos = 0;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mca, l_unitPos),
                         "Error getting MCA ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                if (l_unitPos == ii)
                {
                    l_unGroupedPair.insert(std::pair<uint8_t, fapi2::Target<fapi2::TARGET_TYPE_MCA>>
                                           (ii, l_mca));
                    break;
                }
            }
        }
    }

    // There are some ungrouped MC ports
    if (l_unGroupedPair.size() > 0)
    {
        // Assert with first failed port as FFDC
        uint8_t l_mcPortNum = l_unGroupedPair.begin()->first;
        fapi2::Target<fapi2::TARGET_TYPE_MCA> l_portTarget =
            l_unGroupedPair.begin()->second;
        FAPI_ASSERT(false,
                    fapi2::MSS_EFF_GROUPING_UNABLE_TO_GROUP_MC()
                    .set_MC_PORT_NUMBER(l_mcPortNum)
                    .set_TARGET(l_portTarget),
                    "grouping_findUngroupedPorts: Unable to group port %u", l_mcPortNum);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

// Specialization for DMI targets
template<>
fapi2::ReturnCode grouping_findUngroupedPorts(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_DMI> >& i_mcTargets,
    const EffGroupingMemInfo& i_memInfo,
    const EffGroupingData& i_groupData)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // std_pair<MC number, target>
    std::map<uint8_t, fapi2::Target<fapi2::TARGET_TYPE_DMI>> l_unGroupedPair;

    // Mark the MCs that are not grouped
    for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
    {
        if ( (i_memInfo.iv_portSize[ii] != 0) &&
             (i_groupData.iv_portGrouped[ii] == false) )
        {
            FAPI_ERR("grouping_findUngroupedPorts: Unable to group port %u", ii);

            for (auto l_dmi : i_mcTargets)
            {
                // Get the DMI position
                uint8_t l_unitPos = 0;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_dmi, l_unitPos),
                         "Error getting DMI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                if (l_unitPos == ii)
                {
                    l_unGroupedPair.insert(std::pair<uint8_t, fapi2::Target<fapi2::TARGET_TYPE_DMI>>
                                           (ii, l_dmi));
                    break;
                }
            }
        }
    }

    // There are some ungrouped MC ports
    if (l_unGroupedPair.size() > 0)
    {
        // Assert with first failed port as FFDC
        uint8_t l_mcPortNum = l_unGroupedPair.begin()->first;
        fapi2::Target<fapi2::TARGET_TYPE_DMI> l_portTarget =
            l_unGroupedPair.begin()->second;
        FAPI_ASSERT(false,
                    fapi2::MSS_EFF_GROUPING_UNABLE_TO_GROUP_MC()
                    .set_MC_PORT_NUMBER(l_mcPortNum)
                    .set_TARGET(l_portTarget),
                    "grouping_findUngroupedPorts: Unable to group port %u", l_mcPortNum);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Determine if memory is a power of 2 in size
///
/// @param[i] i_size Memory Size
///
/// @return True if memory is a power of 2 in size; false otherwise.
///
bool isPowerOf2(uint32_t i_size)
{
    bool l_powerOf2 = false;

    if (i_size > 0)
    {
        l_powerOf2 = !(i_size & (i_size - 1));
    }

    FAPI_DBG("isPowerOf2: MemSize %d GB, l_powerOf2 0x%.8X",
             i_size, l_powerOf2);
    return l_powerOf2;
}

///
/// @brief Determine the next power of 2 value of a memory size.
///
/// @param[i] i_size   Memory size
///
/// @return Next power of 2 value
///
uint32_t nextPowerOf2(uint32_t i_size)
{
    uint32_t l_value = 1;

    while (l_value < i_size)
    {
        l_value <<= 1;
    }

    FAPI_DBG("MemSize %d GB, NextPowerOf2 %d GB", i_size, l_value);

    return l_value;
}

///
/// @brief Calculate Alt Memory
///
/// @param[io] io_groupData Group Data
///
void grouping_calcAltMemory(EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");

    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        // Determine if the Group size a power of 2
        if ( !isPowerOf2(io_groupData.iv_data[pos][GROUP_SIZE]) )
        {

            // Note:
            // The 2nd memory hole was intended for use with 12Gb DRAM parts,
            // which we do not have to support - so it will not be used in Nimbus.

            // Memsize is not power of 2, needs ALT bar definition
            FAPI_INF("Group %u needs alt bars definition, group size %u GB",
                     pos, io_groupData.iv_data[pos][GROUP_SIZE]);

            // Alt size is the difference between real group size
            // and next power of 2 size
            io_groupData.iv_data[pos][ALT_SIZE(0)] =
                nextPowerOf2(io_groupData.iv_data[pos][GROUP_SIZE]) -
                io_groupData.iv_data[pos][GROUP_SIZE];

            // Set group size to the next power of 2 value
            io_groupData.iv_data[pos][GROUP_SIZE] =
                nextPowerOf2(io_groupData.iv_data[pos][GROUP_SIZE]);

            FAPI_INF("New Group Size is %u GB, Alt Size %u GB",
                     io_groupData.iv_data[pos][GROUP_SIZE],
                     io_groupData.iv_data[pos][ALT_SIZE(0)]);
            io_groupData.iv_data[pos][ALT_VALID(0)] = 1;
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Sorts groups from high to low memory size
///
/// @param[io] io_groupData Group Data
///
void grouping_sortGroups(EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");

    // Done with a simple bubble sort
    FAPI_INF("grouping_sortGroups: Sorting Groups");

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
                    FAPI_INF("grouping_sortGroups: Swapping groups %u and %u",
                             pos, pos + 1);

                    for (uint32_t j = 0; j < DATA_ELEMENTS; j++)
                    {
                        // Save data from group pos
                        temp[j] = io_groupData.iv_data[pos][j];
                        // Copy data from pos+1 to pos
                        io_groupData.iv_data[pos][j] =
                            io_groupData.iv_data[pos + 1][j];
                        // Copy saved data from group pos to pos+1
                        io_groupData.iv_data[pos + 1][j] = temp[j];
                    }

                    swapped = true;
                }
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Calculate Mirror Memory base and alt-base addresses
///
/// @param[in] i_target           Reference to processor chip target
/// @param[io] io_procAttrs       Processor Attributes (iv_mirrorBaseAddr can be
///                                                     updated)
/// @param[io] io_groupData       Group Data
/// @param[in] i_totalSizeNonMirr Total non mirrored size
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode grouping_calcMirrorMemory(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    EffGroupingProcAttrs& io_procAttrs,
    EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Calculate mirrored group size and non mirrored group size
    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        if (io_groupData.iv_data[pos][PORTS_IN_GROUP] > 1)
        {
            uint8_t l_mirrorOffset = pos + MIRR_OFFSET;
            // Mirrored size is half the group size
            io_groupData.iv_data[l_mirrorOffset][GROUP_SIZE] =
                io_groupData.iv_data[pos][GROUP_SIZE] / 2;
            io_groupData.iv_data[l_mirrorOffset][PORT_SIZE] =
                io_groupData.iv_data[pos][PORT_SIZE];
            io_groupData.iv_data[l_mirrorOffset][PORTS_IN_GROUP] =
                io_groupData.iv_data[pos][PORTS_IN_GROUP];

            for (uint8_t l_altRegion = 0; l_altRegion < NUM_OF_ALT_MEM_REGIONS; l_altRegion++)
            {
                if (io_groupData.iv_data[pos][ALT_VALID(l_altRegion)])
                {
                    FAPI_INF("Mirrored group %u needs alt bars definition, group size %u GB",
                             pos, io_groupData.iv_data[pos][GROUP_SIZE]);
                    io_groupData.iv_data[l_mirrorOffset][ALT_SIZE(l_altRegion)] =
                        io_groupData.iv_data[pos][ALT_SIZE(l_altRegion)] / 2;
                    io_groupData.iv_data[l_mirrorOffset][ALT_VALID(l_altRegion)] = 1;
                }
            }
        }
    }

    // Convert base addresses to GB for calculation
    uint64_t memBaseAddr_GB = io_procAttrs.iv_memBaseAddr >> 30;
    uint64_t mirrorBaseAddr_GB = io_procAttrs.iv_mirrorBaseAddr >> 30;
    FAPI_DBG("io_procAttrs.iv_memBaseAddr 0x%.16llX, memBaseAddr_GB 0x%.16llX", io_procAttrs.iv_memBaseAddr,
             memBaseAddr_GB);
    FAPI_DBG("io_procAttrs.iv_mirrorBaseAddr 0x%.16llX, mirrorBaseAddr_GB 0x%.16llX", io_procAttrs.iv_mirrorBaseAddr,
             mirrorBaseAddr_GB);
    FAPI_DBG("io_groupData.iv_totalSizeNonMirr %d", io_groupData.iv_totalSizeNonMirr);

    // Check if the memory base address overlaps with the mirror base address
    if ( (memBaseAddr_GB > (mirrorBaseAddr_GB + (io_groupData.iv_totalSizeNonMirr / 2))) ||
         (mirrorBaseAddr_GB > (memBaseAddr_GB + io_groupData.iv_totalSizeNonMirr)) )
    {
        // No overlapping
        for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
        {
            if (pos == 0)
            {
                // Note:
                // The 2nd memory hole was intended for use with 12Gb DRAM parts,
                // which we do not have to support - so it will not be used in Nimbus.
                io_groupData.iv_data[pos][BASE_ADDR] = memBaseAddr_GB;

                if (io_groupData.iv_data[pos][ALT_VALID(0)])
                {
                    io_groupData.iv_data[pos][ALT_BASE_ADDR(0)] = io_groupData.iv_data[pos][BASE_ADDR] +
                            (io_groupData.iv_data[pos][GROUP_SIZE] / 2);
                }
            }
            else
            {
                io_groupData.iv_data[pos][BASE_ADDR] = io_groupData.iv_data[pos - 1][BASE_ADDR] +
                                                       io_groupData.iv_data[pos - 1][GROUP_SIZE];

                if (io_groupData.iv_data[pos][ALT_VALID(0)])
                {
                    io_groupData.iv_data[pos][ALT_BASE_ADDR(0)] = io_groupData.iv_data[pos][BASE_ADDR] +
                            io_groupData.iv_data[pos][GROUP_SIZE] / 2;
                }
            }

            if (io_groupData.iv_data[pos][PORTS_IN_GROUP] > 1)
            {
                io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] = mirrorBaseAddr_GB;
                mirrorBaseAddr_GB += io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE];
                io_procAttrs.iv_mirrorBaseAddr = (mirrorBaseAddr_GB << 30);

                if (io_groupData.iv_data[pos][ALT_VALID(0)])
                {
                    io_groupData.iv_data[pos + MIRR_OFFSET][ALT_BASE_ADDR(0)] = io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] +
                            io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE] / 2;
                    io_groupData.iv_data[pos + MIRR_OFFSET][ALT_VALID(0)] = 1;
                }

                FAPI_DBG("Adjust Mirror Base Address for group %d", pos);
                FAPI_DBG("New values: io_procAttrs.iv_mirrorBaseAddr 0x%.16llX, mirrorBaseAddr_GB 0x%.16llX",
                         io_procAttrs.iv_mirrorBaseAddr, mirrorBaseAddr_GB);
                FAPI_DBG("Mirror group size: io_groupData.iv_data[%d][GROUP_SIZE] = %d", pos + MIRR_OFFSET,
                         io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE]);
                FAPI_DBG("Mirror group base addr: io_groupData.iv_data[%d][BASE_ADDR] = 0x%.16llX", pos + MIRR_OFFSET,
                         io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR]);
            }
        }
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_EFF_GROUPING_BASE_ADDRESS_OVERLAPS_MIRROR_ADDRESS()
                    .set_PROC_CHIP(i_target)
                    .set_MEM_BASE_ADDR(io_procAttrs.iv_memBaseAddr)
                    .set_MIRROR_BASE_ADDR(io_procAttrs.iv_mirrorBaseAddr)
                    .set_SIZE_NON_MIRROR(io_groupData.iv_totalSizeNonMirr),
                    "Mirror Base address overlaps with memory base address");
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Calculate Non-mirror Memory base and alt-base addresses
///
/// @param[in] i_procAttrs  Processor Chip Attributes
/// @param[io] io_groupData Group Data
///
void grouping_calcNonMirrorMemory(const EffGroupingProcAttrs& i_procAttrs,
                                  EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");

    // Assign mirroring and non-mirroring base address for each group
    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        if (pos == 0)
        {
            io_groupData.iv_data[pos][BASE_ADDR] =
                (i_procAttrs.iv_memBaseAddr >> 30);

            for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
            {
                if (io_groupData.iv_data[pos][ALT_VALID(ii)])
                {
                    io_groupData.iv_data[pos][ALT_BASE_ADDR(ii)] =
                        io_groupData.iv_data[pos][GROUP_SIZE] -
                        io_groupData.iv_data[pos][ALT_SIZE(ii)];
                }
            }
        }
        else
        {
            io_groupData.iv_data[pos][BASE_ADDR] =
                io_groupData.iv_data[pos - 1][BASE_ADDR] +
                io_groupData.iv_data[pos - 1][GROUP_SIZE];

            for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
            {
                if (io_groupData.iv_data[pos][ALT_VALID(ii)])
                {
                    io_groupData.iv_data[pos][ALT_BASE_ADDR(ii)] =
                        io_groupData.iv_data[pos][GROUP_SIZE] -
                        io_groupData.iv_data[pos][ALT_SIZE(ii)];
                }
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Sets the ATTR_MSS_MEM_MC_IN_GROUP attribute
///
/// @param[in] i_target    Reference to Processor Chip target
/// @param[in] i_groupData Group Data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode grouping_setATTR_MSS_MEM_MC_IN_GROUP(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingData& i_groupData)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    fapi2::buffer<uint8_t> MC_IN_GP;
    uint8_t l_mcPort_in_group[NUM_MC_PORTS_PER_PROC];
    memset(l_mcPort_in_group, 0, sizeof(l_mcPort_in_group));

    for (uint8_t ii = 0; ii < i_groupData.iv_numGroups; ii++)
    {
        MC_IN_GP = 0;
        uint8_t l_count = i_groupData.iv_data[ii][PORTS_IN_GROUP];

        for (uint8_t jj = 0; jj < l_count; jj++)
        {
            MC_IN_GP.setBit( i_groupData.iv_data[ii][MEMBER_IDX(jj)] );
        }

        l_mcPort_in_group[ii] = MC_IN_GP;
    }

    FAPI_INF("grouping_setATTR_MSS_MEM_MC_IN_GROUP: ");

    for (uint8_t ii = 0; ii < NUM_MC_PORTS_PER_PROC; ii++)
    {
        FAPI_INF("  ATTR_MSS_MEM_MC_IN_GROUP[%d]: 0x%02x",
                 ii, l_mcPort_in_group[ii]);
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_MC_IN_GROUP, i_target,
                           l_mcPort_in_group),
             "Error setting ATTR_MSS_MEM_MC_IN_GROUP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Traces the Grouping Data
///
/// @param[in] i_sysAttrs  System Attributes
/// @param[in] i_groupData Group Data
///
void grouping_traceData(const EffGroupingSysAttrs& i_sysAttrs,
                        const EffGroupingData& i_groupData)
{
    FAPI_DBG("Entering");

    // Display number of groups
    FAPI_INF("Total number of Memory groups: %u", i_groupData.iv_numGroups);

    // Display non-mirror groups
    for (uint8_t ii = 0; ii < i_groupData.iv_numGroups; ii++)
    {
        FAPI_INF("NON-MIRROR - Group %u: ", ii);
        FAPI_INF("    MC port size %d GB", i_groupData.iv_data[ii][PORT_SIZE]);
        FAPI_INF("    Num of ports %d", i_groupData.iv_data[ii][PORTS_IN_GROUP]);
        FAPI_INF("    Group size  %d GB", i_groupData.iv_data[ii][GROUP_SIZE]);
        FAPI_INF("    Base addr 0x%08x", i_groupData.iv_data[ii][BASE_ADDR]);

        for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
        {
            FAPI_INF("    ALT-BAR(%d) valid %d ", jj, i_groupData.iv_data[ii][ALT_VALID(jj)]);
            FAPI_INF("    ALT-BAR(%d) size %d ", jj, i_groupData.iv_data[ii][ALT_SIZE(jj)]);
            FAPI_INF("    ALT-BAR(%d) base addr 0x%08X", jj, i_groupData.iv_data[ii][ALT_BASE_ADDR(jj)]);
        }

        // Display MC in groups
        for (uint8_t jj = 0; jj < i_groupData.iv_data[ii][PORTS_IN_GROUP]; jj++)
        {
            FAPI_INF("    Contains MC %d",
                     i_groupData.iv_data[ii][MEMBER_IDX(jj)]);
        }
    }

    // Display mirror groups
    if (!i_sysAttrs.iv_enhancedNoMirrorMode)
    {
        for (uint8_t ii = 0; ii < i_groupData.iv_numGroups; ii++)
        {
            uint8_t l_mirrorOffset = ii + MIRR_OFFSET;

            FAPI_INF("MIRROR - Group %u: ", l_mirrorOffset);
            FAPI_INF("    MC port size %d GB", i_groupData.iv_data[l_mirrorOffset][PORT_SIZE]);
            FAPI_INF("    Num of ports %d", i_groupData.iv_data[l_mirrorOffset][PORTS_IN_GROUP]);
            FAPI_INF("    Group size  %d GB", i_groupData.iv_data[l_mirrorOffset][GROUP_SIZE]);
            FAPI_INF("    Base addr 0x%08x", i_groupData.iv_data[l_mirrorOffset][BASE_ADDR]);

            for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
            {
                FAPI_INF("    ALT-BAR(%d) valid %d ", jj, i_groupData.iv_data[l_mirrorOffset][ALT_VALID(jj)]);
                FAPI_INF("    ALT-BAR(%d) size %d ", jj, i_groupData.iv_data[l_mirrorOffset][ALT_SIZE(jj)]);
                FAPI_INF("    ALT-BAR(%d) base addr 0x%08X", jj, i_groupData.iv_data[l_mirrorOffset][ALT_BASE_ADDR(jj)]);
            }

            // Display MC in groups
            for (uint8_t jj = 0; jj < i_groupData.iv_data[l_mirrorOffset][PORTS_IN_GROUP]; jj++)
            {
                FAPI_INF("    Contains MC %d",
                         i_groupData.iv_data[l_mirrorOffset][MEMBER_IDX(jj)]);
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief p9_mss_eff_grouping procedure entry point
/// See doxygen in p9_mss_eff_grouping.H
///
fapi2::ReturnCode p9_mss_eff_grouping(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Create data structures for grouping operation
    EffGroupingSysAttrs l_sysAttrs;
    EffGroupingProcAttrs l_procAttrs;
    EffGroupingMemInfo l_memInfo;
    EffGroupingBaseSizeData l_baseSizeData;
    EffGroupingData l_groupData;

    // ----------------------------------------------
    // Get the attributes needed for memory grouping
    // ----------------------------------------------
    FAPI_INF("Getting system memory grouping attributes");

    // Get the system attributes needed to perform grouping
    FAPI_TRY(l_sysAttrs.getAttrs(),
             "l_sysAttrs.getAttrs() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get the proc target attributes needed to perform grouping
    FAPI_TRY(l_procAttrs.getAttrs(i_target, l_sysAttrs),
             "l_procAttrs.getAttrs() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Check that the system and processor chip attributes are valid
    FAPI_TRY(grouping_checkValidAttributes(i_target, l_sysAttrs, l_procAttrs),
             "grouping_checkValidAttributes() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ------------------------------------------------------------------
    // Get the memory sizes behind MC ports
    // ------------------------------------------------------------------
    FAPI_INF("Getting memory sizes behind MC ports");
    FAPI_TRY(l_memInfo.getMemInfo(i_target),
             "p9_mss_eff_grouping: l_memInfo.get_memInfo() returns an error, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    // ----------------------------------------------------------------------
    // Attempt to group the memory per Group port (per MCA/DMI).
    // P9 MC architecture allows 1, 2, 3, 4, 6, or 8 MC ports to be grouped
    // together.
    // All of the grouping functions are called if allowed.
    // If the memory cannot be grouped by one function they may be grouped by
    // the subsequent functions.
    // ----------------------------------------------------------------------
    FAPI_INF("Attempt memory grouping");

    // Group MCs
    if (l_procAttrs.iv_groupsAllowed & GROUP_8)
    {
        grouping_group8PortsPerGroup(l_memInfo, l_groupData);
    }

    if (l_procAttrs.iv_groupsAllowed & GROUP_6)
    {
        grouping_group6PortsPerGroup(l_memInfo, l_groupData);
    }

    if (l_procAttrs.iv_groupsAllowed & GROUP_4)
    {
        grouping_group4PortsPerGroup(l_memInfo, l_groupData);
    }

    if (l_procAttrs.iv_groupsAllowed & GROUP_3)
    {
        grouping_group3PortsPerGroup(l_memInfo, l_groupData);
    }

    if (l_procAttrs.iv_groupsAllowed & GROUP_2)
    {
        grouping_group2PortsPerGroup(l_memInfo, l_groupData);
    }

    if (l_procAttrs.iv_groupsAllowed & GROUP_1)
    {
        grouping_group1PortsPerGroup(l_memInfo, l_groupData);
    }

    // Verify all ports are grouped, or error out
    if (l_memInfo.iv_nimbusProc == true)
    {
        auto l_mcaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCA>();
        FAPI_TRY(grouping_findUngroupedPorts(l_mcaChiplets, l_memInfo, l_groupData),
                 "grouping_findUngroupedPorts() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }
    else
    {
        auto l_dmiChiplets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();
        FAPI_TRY(grouping_findUngroupedPorts(l_dmiChiplets, l_memInfo, l_groupData),
                 "grouping_findUngroupedPorts() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }

    // Calculate Alt Memory
    grouping_calcAltMemory(l_groupData);

    // Sort Groups from high memory size to low
    grouping_sortGroups(l_groupData);

    // Calculate the total non mirrored size
    for (uint8_t pos = 0; pos < l_groupData.iv_numGroups; pos++)
    {
        l_groupData.iv_totalSizeNonMirr += l_groupData.iv_data[pos][GROUP_SIZE];
    }

    FAPI_INF("Total non-mirrored size %u GB", l_groupData.iv_totalSizeNonMirr);

    if (!l_sysAttrs.iv_enhancedNoMirrorMode)
    {
        // Calculate base and alt-base addresses
        FAPI_TRY(grouping_calcMirrorMemory(i_target, l_procAttrs, l_groupData),
                 "Error from grouping_calcMirrorMemory, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }
    else
    {
        // ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING is true
        // Calculate base and alt-base addresses
        grouping_calcNonMirrorMemory(l_procAttrs, l_groupData);
    }

    // Set the ATTR_MSS_MEM_MC_IN_GROUP attribute
    FAPI_TRY(grouping_setATTR_MSS_MEM_MC_IN_GROUP(i_target, l_groupData),
             "grouping_setATTR_MSS_MEM_MC_IN_GROUP() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Trace a summary of the Grouping Data
    grouping_traceData(l_sysAttrs, l_groupData);

    // Set memory base and size
    l_baseSizeData.setBaseSizeData(l_sysAttrs, l_groupData);

    // Set HTM/OCC base addresses
    FAPI_TRY(l_baseSizeData.set_HTM_OCC_base_addr(i_target, l_sysAttrs,
             l_groupData, l_procAttrs),
             "set_HTM_OCC_base_addr() returns error l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set Memory Base and Size FAPI Attributes
    FAPI_TRY(l_baseSizeData.setBaseSizeAttr(i_target, l_sysAttrs, l_groupData),
             "setBaseSizeAttr returns error l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}
