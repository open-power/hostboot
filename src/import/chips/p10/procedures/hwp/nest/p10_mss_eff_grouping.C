/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_mss_eff_grouping.C $ */
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
/// ----------------------------------------------------------------------------
/// @file  p10_mss_eff_grouping.C
///
/// @brief Perform Memory Controller grouping on each processor chip
///
/// The purpose of this procedure is to effectively group the memory on each
/// processor chip based on available memory behind its memory ports.
/// Some placement policy/scheme and other info that are stored in the
/// attributes are used as part of the grouping process.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
/// ----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_mss_eff_grouping.H>
#include <p10_fbc_utils.H>
#include <map>
#include <p10_scom_mc.H>
#include <memory_size.H>
#include <exp_consts.H>
#include <exp_inband.H>

//------------------------------------------------------------------------------
// scomt name spaces
//------------------------------------------------------------------------------
using namespace scomt;
using namespace scomt::mc;

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------
// MCC position
const uint8_t MCC_ID_0 = 0x0;
const uint8_t MCC_ID_1 = 0x1;
const uint8_t MCC_ID_2 = 0x2;
const uint8_t MCC_ID_3 = 0x3;
const uint8_t MCC_ID_4 = 0x4;
const uint8_t MCC_ID_5 = 0x5;
const uint8_t MCC_ID_6 = 0x6;
const uint8_t MCC_ID_7 = 0x7;

// Max queues per MCC (MCPERF0 16:19)
const uint8_t MAX_HTM_QUEUE_PER_MCC = 16;

// Number of ATTR_MEMORY_BAR_REGS elements
const uint8_t BAR_REGS_ELEMENTS = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_NUM_BAR_REGS;

const uint8_t BAR_REGS_INDICES  = 2;
const uint8_t BAR_REGS_DATA_IDX = 0;
const uint8_t BAR_REGS_MASK_IDX = 1;

// SMF addr bit
const uint8_t SECURE_MEMORY_BASE_ADDRESS_BIT = 12;

// -----------------------
// Group allow definitions
// -----------------------
// Enum value used to decode ATTR_MSS_INTERLEAVE_ENABLE
// P10 allows 1, 2, 3, 4, 6, or 8 channels (MCC) to be grouped together.
enum GroupAllowed
{
    GROUP_1    = 0b00000001,   // 0x01 Group of 1 channel allowed
    GROUP_2    = 0b00000010,   // 0x02 Group of 2 channels allowed
    GROUP_3    = 0b00000100,   // 0x04 Group of 3 channels allowed
    GROUP_4    = 0b00001000,   // 0x08 Group of 4 channels allowed
    GROUP_6    = 0b00100000,   // 0x20 Group of 6 channels allowed
    GROUP_8    = 0b10000000,   // 0x80 Group of 8 channels allowed
    ALL_GROUPS = GROUP_1 |
                 GROUP_2 |
                 GROUP_3 |
                 GROUP_4 |
                 GROUP_6 |
                 GROUP_8,
};

// ---------------------------------------------------------------------
// Used to indicate which subchannels of an OMI channel are used
// ---------------------------------------------------------------------
enum OMISubChannelConfig
{
    NONE    = 0b00000000,   // Neither sub channel is enabled
    A       = 0b10000000,   // Sub-channel A is used
    B       = 0b01000000,   // Sub-channel B is used
    BOTH    = A | B,  // Both are enabled (mirroring is allowed)
};

const uint8_t NO_CHANNEL_PER_GROUP = 0xFF;     // Init value of channel per group

// ---------------------------------------------------------------------
// Group size table
// ---------------------------------------------------------------------
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
    {      4,        0b00000000000    },      //    4 GB
    {      8,        0b00000000001    },      //    8 GB
    {     16,        0b00000000011    },      //   16 GB
    {     32,        0b00000000111    },      //   32 GB
    {     64,        0b00000001111    },      //   64 GB
    {    128,        0b00000011111    },      //  128 GB
    {    256,        0b00000111111    },      //  256 GB
    {    512,        0b00001111111    },      //  512 GB
    {   1024,        0b00011111111    },      //    1 TB
    {   2048,        0b00111111111    },      //    2 TB
    {   4096,        0b01111111111    },      //    4 TB
    {   8192,    0b000011111111111    },      //    8 TB
    {  16384,    0b000111111111111    },      //   16 TB
    {  32768,    0b001111111111111    },      //   32 TB
    {  65536,    0b011111111111111    },      //   64 TB
    { 131072,    0b111111111111111    }       //  128 TB
};

// Max display buffer size
const uint8_t MAX_DISPLAY_BUFFER_SIZE = 32;

//----------------------------------------------------------------------------
/// Functions
///---------------------------------------------------------------------------
/// @brief Utility function that converts bytes into TB, GB, or MB and puts
///        the result into a char buffer.
/// @param[in]      i_bytes  Number of bytes
/// @param[out]     o_buf    Output string buffer
/// @return void
void getSizeString (const uint64_t i_bytes, char o_buf[])
{
    // For now, just display either TB, GB, MB, or Bytes
    if (i_bytes >= 0x0000010000000000) // 1TB
    {
        sprintf(o_buf, "0x%016lx (%lu TB)", i_bytes, i_bytes >> 40);
    }
    else if (i_bytes >= 0x0000000040000000) // 1GB
    {
        sprintf(o_buf, "0x%016lx (%lu GB)", i_bytes, i_bytes >> 30);
    }
    else if (i_bytes >= 0x0000000000100000) // 1MB
    {
        sprintf(o_buf, "0x%016lx (%lu MB)", i_bytes, i_bytes >> 20);
    }
    else
    {
        sprintf(o_buf, "0x%016lx (%lu Bytes)", i_bytes, i_bytes);
    }

    return;
}

///----------------------------------------------------------------------------
/// struct EffGroupingSysAttrs
///----------------------------------------------------------------------------
/// @struct EffGroupingSysAttrs
/// Contains system attributes to perform memory effective grouping.
struct EffGroupingSysAttrs
{
    /// @brief getAttrs
    /// Loads system attributes into this struct.
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode getAttrs();

    // Public data
    uint8_t iv_mirrorPlacement = 0;          // ATTR_MEM_MIRROR_PLACEMENT_POLICY: normal/flipped
    uint8_t iv_hwMirrorEnabled = 0;          // ATTR_MRW_HW_MIRRORING_ENABLE: off/required/request
    uint8_t iv_groupsAllowed = 0;            // ATTR_MSS_INTERLEAVE_ENABLE
    uint64_t iv_maxInterleaveGroupSize = 0;  // ATTR_MAX_INTERLEAVE_GROUP_SIZE
    uint8_t iv_smfConfig = 0;                // ATTR_SMF_CONFIG:disabled/enabled
};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingSysAttrs::getAttrs()
{
    FAPI_DBG("Entering EffGroupingSysAttrs::getAttrs");

    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // Get SMF config setting
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG, FAPI_SYSTEM, iv_smfConfig),
             "Error getting ATTR_SMF_CONFIG, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get mirror placement policy
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY, FAPI_SYSTEM, iv_mirrorPlacement),
             "Error getting ATTR_MEM_MIRROR_PLACEMENT_POLICY, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get mirror option
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_HW_MIRRORING_ENABLE, FAPI_SYSTEM, iv_hwMirrorEnabled),
             "Error getting ATTR_MRW_HW_MIRRORING_ENABLE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get interleave option
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_INTERLEAVE_ENABLE, FAPI_SYSTEM, iv_groupsAllowed),
             "Error getting ATTR_MSS_INTERLEAVE_ENABLE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // MAX_INTERLEAVE_GROUP_SIZE (16TB, defined in p10_fbc_utils.H)
    // Store ATTR_MAX_INTERLEAVE_GROUP_SIZE in GB for direct comparison with
    // group size attributes.
    iv_maxInterleaveGroupSize = MAX_INTERLEAVE_GROUP_SIZE >> 30;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MAX_INTERLEAVE_GROUP_SIZE, FAPI_SYSTEM, iv_maxInterleaveGroupSize),
             "Error setting ATTR_MAX_INTERLEAVE_GROUP_SIZE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Display attribute values
    FAPI_INF("EffGroupingSysAttrs: ");
    FAPI_INF("   ATTR_SMF_CONFIG 0x%X", iv_smfConfig);
    FAPI_INF("   ATTR_MEM_MIRROR_PLACEMENT_POLICY 0x%.8X", iv_mirrorPlacement);
    FAPI_INF("   ATTR_MRW_HW_MIRRORING_ENABLE 0x%.8X", iv_hwMirrorEnabled);
    FAPI_INF("   ATTR_MSS_INTERLEAVE_ENABLE 0x%.8X", iv_groupsAllowed);
    FAPI_INF("   ATTR_MAX_INTERLEAVE_GROUP_SIZE %u GB", iv_maxInterleaveGroupSize);

fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingSysAttrs::getAttrs");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingProcAttrs
///----------------------------------------------------------------------------
/// @struct EffGroupingProcAttrs
/// Contains processor chip attributes to perform memory effective grouping.
struct EffGroupingProcAttrs
{
    /// @brief getAttrs
    /// Loads proc attributes into this struct.
    /// @param[in] i_target    Reference to processor chip target
    /// @param[in] i_sysAttrs  System attribute settings
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode getAttrs(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs i_sysAttrs);

    /// @brief getProcBaseAddresses
    /// Get the memory base addresses (non-mirrored/mirrored memory).
    /// @param[in] i_target    Reference to processor chip target
    /// @param[in] i_sysAttrs  System attribute settings
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode getProcBaseAddresses(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs i_sysAttrs);

    // Public data
    std::vector<uint64_t> iv_memBaseAddr;           // ATTR_PROC_MEM_BASES
    uint64_t iv_mirrorBaseAddr;                     // ATTR_PROC_MIRROR_BASE
    uint64_t iv_nhtmBarSize;                        // ATTR_PROC_NHTM_BAR_SIZE
    uint64_t iv_chtmBarSizes[NUM_OF_CHTM_REGIONS];  // ATTR_PROC_CHTM_BAR_SIZES
    uint64_t iv_occSandboxSize = 0;                 // ATTR_PROC_OCC_SANDBOX_SIZE
    uint64_t iv_smfBarSize = 0;                     // ATTR_PROC_SMF_BAR_SIZE
    uint8_t  iv_fabricTopologyId = 0;               // ATTR_PROC_FABRIC_TOPOLOGY_ID
};


// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingProcAttrs::getProcBaseAddresses(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs i_sysAttrs)
{
    FAPI_DBG("Entering");

    uint64_t l_nmMemBaseAddr0;
    uint64_t l_nmMemBaseAddr1;
    uint64_t l_mmioBaseAddr;

    // Get the Mirror/Non-mirror base addresses
    FAPI_TRY(p10_fbc_utils_get_chip_base_address(i_target,
             EFF_TOPOLOGY_ID,
             l_nmMemBaseAddr0,
             l_nmMemBaseAddr1,
             iv_mirrorBaseAddr,
             l_mmioBaseAddr),
             "p10_fbc_utils_get_chip_base_address() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Store non-mirror base addresses into vectors
    iv_memBaseAddr.push_back(l_nmMemBaseAddr0);
    iv_memBaseAddr.push_back(l_nmMemBaseAddr1);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingProcAttrs::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs i_sysAttrs)
{
    char display[32];

    FAPI_DBG("Entering EffGroupingProcAttrs::getAttrs");

    // Get Nest Hardware Trace Macro (NHTM) bar size
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NHTM_BAR_SIZE, i_target, iv_nhtmBarSize),
             "Error getting ATTR_PROC_HTM_BAR_SIZE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Core Hardware Trace Macro (CHTM) bar size
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_CHTM_BAR_SIZES, i_target, iv_chtmBarSizes),
             "Error getting ATTR_PROC_CHTM_BAR_SIZES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get On Chip Controler (OCC) sandbox size
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_OCC_SANDBOX_SIZE, i_target, iv_occSandboxSize),
             "Error getting ATTR_PROC_OCC_SANDBOX_SIZE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get Secure Memory (SMF) bar size
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SMF_BAR_SIZE, i_target, iv_smfBarSize),
             "Error getting ATTR_PROC_SMF_BAR_SIZE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get proc's base addresses (non-mirrored/mirrored)
    FAPI_TRY(getProcBaseAddresses(i_target, i_sysAttrs),
             "EffGroupingProcAttrs::getAttrs: getProcBaseAddresses() returns "
             "error, l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    // Display attribute values
    FAPI_INF("EffGroupingProcAttrs::getAttrs: ");
    getSizeString(iv_nhtmBarSize, display);
    FAPI_INF("  ATTR_PROC_NHTM_BAR_SIZE 0x%.16llX %s", iv_nhtmBarSize, display);

    for (uint8_t ii = 0; ii < NUM_OF_CHTM_REGIONS; ii++)
    {
        getSizeString(iv_chtmBarSizes[ii], display);
        FAPI_INF("  ATTR_PROC_CHTM_BAR_SIZES[%u] 0x%.16llX %s", ii,
                 iv_chtmBarSizes[ii], display);
    }

    getSizeString(iv_occSandboxSize, display);
    FAPI_INF("  ATTR_PROC_OCC_SANDBOX_SIZE 0x%.16llX %s", iv_occSandboxSize, display);

    getSizeString(iv_smfBarSize, display);
    FAPI_INF("  ATTR_PROC_SMF_BAR_SIZE 0x%.16llX %s", iv_smfBarSize, display);

    for (uint8_t ii = 0; ii < iv_memBaseAddr.size(); ii++)
    {
        getSizeString(iv_memBaseAddr[ii], display);
        FAPI_INF("  Non-mirrored base addresses[%d] %s",
                 ii, display);
    }

    getSizeString(iv_mirrorBaseAddr, display);
    FAPI_INF("  Mirrored base address %s", display);

fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingProcAttrs::getAttrs");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingMccAttrs
///----------------------------------------------------------------------------
/// @struct EffGroupingMccAttrs
/// Contains attributes for an MCC
struct EffGroupingMccAttrs
{
    /// @brief Getting attribute of a MCC chiplet
    /// Reads the MCC target attributes and load their values into the struct.
    /// @param[in] i_target Reference to MCC chiplet target
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode getAttrs(
        const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target);

    // Unit Position
    uint8_t iv_unitPos = 0;
    // Total Dimm size behind this MCC
    uint64_t iv_dimmSize = 0;
    // The OCMBs associated with this MCC (for deconfiguring if cannot group)
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> iv_ocmbs;
    std::vector<uint8_t> iv_omi_pos;
};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingMccAttrs::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    FAPI_DBG("Entering EffGroupingMccAttrs::getAttrs");
    uint8_t l_omi_pos = 0;
    uint64_t l_min_size = 0;
    uint64_t l_ocmb_size = 0;

    // Get the ocmbs attached to this MCC
    auto l_omis = i_target.getChildren<fapi2::TARGET_TYPE_OMI>();
    // Get MCC target pos
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, iv_unitPos),
             "Error getting MCC ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("Found %d omi children for MCC %d", l_omis.size(), iv_unitPos);

    // There could be up to 2 OMI/OCMB's per channel
    for (auto l_omi : l_omis)
    {
        // Get the OMI unit position - this should match the OCMB position.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omi, l_omi_pos),
                 "Error getting OMI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        // Get attached ocmb
        auto l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();
        FAPI_DBG("Found %d OCMBs attached to OMI %d", l_ocmbs.size(), l_omi_pos);

        if (l_ocmbs.size() > 0)
        {
            // Get the amount of memory behind this OCMB
            FAPI_TRY(mss::eff_memory_size<mss::mc_type::EXPLORER>(l_ocmbs[0], l_ocmb_size),
                     "Error returned from eff_memory_size - ocmb, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            FAPI_DBG("OCMB size: %lu GB", l_ocmb_size);

            // If both sub-channels (OMIs) have memory connected,
            // the same size (i.e. smaller size) must be used for both.
            if (l_ocmb_size > 0)
            {
                if (l_min_size != 0)
                {
                    if (l_min_size != l_ocmb_size)
                    {
                        l_min_size = (l_min_size > l_ocmb_size) ? l_ocmb_size : l_min_size;
                        FAPI_DBG("Sub-channels for MCC %d have different size. Limiting to the smallest: %lld",
                                 iv_unitPos, l_min_size)
                    }
                }
                else
                {
                    l_min_size = l_ocmb_size;
                }

                iv_ocmbs.push_back(l_ocmbs.front());
                iv_omi_pos.push_back(l_omi_pos);
            }
        }
    }

    // Total memory size for this MCC
    iv_dimmSize = (iv_ocmbs.size() * l_min_size);

    // Display this MCC's attribute info
    FAPI_INF("EffGroupingMccAttrs::getAttrs: MCC %d, OCMBs attached %d, "
             "iv_dimmSize %d GB ",
             iv_unitPos, iv_ocmbs.size(), iv_dimmSize);

fapi_try_exit:
    FAPI_DBG("Exiting EffGroupingMccAttrs::getAttrs");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingMemInfo
///----------------------------------------------------------------------------
/// @struct EffGroupingMemInfo
/// Contains Memory Information for a processor chip.
///
/// P10 - 4 MCs (MIs) total. Each MC has 2 MCCs.
///       Each MCC is connected to two OCMB ports (or sub-channels)
///       Each OCMB has 2 ports supports up to 2 DIMMs.
///
///       - If both sub-channels (OMIs) have memory connected,
///         the same size must be used for both.
///       - Mirroring is done accross sub-channels not accross channels.
///
///          MI0 --> MCC0 --> OMI0 --> OCMB0 --> DIMM0
///                                          --> DIMM1
///                           OMI1 --> OCMB1 --> DIMM0
///                                          --> DIMM1
///                  MCC1 --> OMI2 --> OCMB2 --> DIMM0
///                                          --> DIMM1
///                           OMI3 --> OCMB3 --> DIMM0
///                                          --> DIMM1
///
///          MI1 --> MCC2 --> OMI4 --> OCMB4 --> DIMM0
///                                          --> DIMM1
///                           OMI5 --> OCMB5 --> DIMM0
///                                          --> DIMM1
///                  MCC3 --> OMI6 --> OCMB6 --> DIMM0
///                                          --> DIMM1
///                           OMI7 --> OCMB7 --> DIMM0
///                                          --> DIMM1
///
///          MI2 --> MCC4 --> OMI8 --> OCMB8 --> DIMM0
///                                          --> DIMM1
///                           OMI9 --> OCMB9 --> DIMM0
///                                          --> DIMM1
///                  MCC5 --> OMI10--> OCMB10--> DIMM0
///                                          --> DIMM1
///                           OMI11--> OCMB11--> DIMM0
///                                          --> DIMM1
///
///          MI3 --> MCC6 --> OMI12--> OCMB12--> DIMM0
///                                          --> DIMM1
///                           OMI13--> OCMB13--> DIMM0
///                                          --> DIMM1
///                  MCC7 --> OMI14--> OCMB14--> DIMM0
///                                          --> DIMM1
///                           OMI15--> OCMB15--> DIMM0
///                                          --> DIMM1
///   ----------------------------------------------------------------
///   Total  4        8        16                 32
///
struct EffGroupingMemInfo
{
    // Constructor
    EffGroupingMemInfo()
    {
        memset(iv_mccSize, 0, sizeof(iv_mccSize));
        memset(iv_dimmType, 0, sizeof(iv_dimmType));
        memset(iv_SubChannelsEnabled, 0, sizeof(iv_SubChannelsEnabled));
    }

    /// @brief Gets the memory information of a processor
    /// @param[in] i_mccChiplets  Vector of functional MCCs
    /// @param[in] i_sysAttrs     System attribute settings
    /// @param[in] i_procAttrs    Proc target attributes
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode getMemInfo(
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCC>>& i_mccChiplets,
        const EffGroupingSysAttrs i_sysAttrs,
        const EffGroupingProcAttrs& i_procAttrs);

    // Memory sizes behind an MCC
    uint32_t iv_mccSize[NUM_MCC_PER_PROC];
    // Maximum group size which can be formed
    uint64_t iv_maxGroupMemSize = 0;
    // DIMM types behind MCC (NV/RDIMMs/etc... - NVDIMM is not currently used)
    uint8_t iv_dimmType[NUM_MCC_PER_PROC];
    // Sub-channels enabled per port: 00, 10, 01, 11
    uint8_t iv_SubChannelsEnabled[NUM_MCC_PER_PROC];
};

// See doxygen in struct definition.
fapi2::ReturnCode EffGroupingMemInfo::getMemInfo (
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCC>>& i_mccChiplets,
    const EffGroupingSysAttrs i_sysAttrs,
    const EffGroupingProcAttrs& i_procAttrs)
{
    FAPI_DBG("Entering");

    // Maximum total group size allowed
    iv_maxGroupMemSize = i_sysAttrs.iv_maxInterleaveGroupSize;
    FAPI_DBG("iv_maxGroupMemSize: %u GB", iv_maxGroupMemSize);

    for (auto l_mcc : i_mccChiplets)
    {
        // Get this MCC attribute info
        EffGroupingMccAttrs l_mccAttrs;
        FAPI_TRY(l_mccAttrs.getAttrs(l_mcc),
                 "l_mccAttrs.getAttrs() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Fill in memory info
        iv_mccSize[l_mccAttrs.iv_unitPos] = l_mccAttrs.iv_dimmSize;

        for (auto l_omi_pos : l_mccAttrs.iv_omi_pos)
        {
            iv_SubChannelsEnabled[l_mccAttrs.iv_unitPos] |=
                (OMISubChannelConfig::A >> (l_omi_pos % SUBCHANNEL_PER_CHANNEL));
            FAPI_DBG("OMI: l_omi_pos = %d  iv_SubChannelsEnabled[%d] = %llx",
                     l_omi_pos, l_mccAttrs.iv_unitPos, iv_SubChannelsEnabled[l_mccAttrs.iv_unitPos])
        }
    }

    // Display amount of memory for each MCC
    for (uint8_t ii = 0; ii < NUM_MCC_PER_PROC; ii++)
    {
        FAPI_INF("MCC[%d] = %d GB", ii, iv_mccSize[ii]);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// struct EffGroupingData
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
        memset(iv_mccGrouped, false, sizeof(iv_mccGrouped));
        memset(iv_mirrorOn, 0, sizeof(iv_mirrorOn));
    }

    // ATTR_MSS_MCC_GROUP_32 attribute
    uint32_t iv_data[DATA_GROUPS][DATA_ELEMENTS];

    // True: MCC position has been grouped
    bool iv_mccGrouped[NUM_MCC_PER_PROC];

    // The number of groups
    uint8_t iv_numGroups = 0;

    // The total non-mirrored memory size in GB
    uint32_t iv_totalSizeNonMirr = 0;

    // Indicates if mirror group is to be created
    // from data of this non-mirror group
    uint8_t iv_mirrorOn[DATA_GROUPS / 2];

};

///----------------------------------------------------------------------------
/// struct EffGroupingBaseSizeData
///----------------------------------------------------------------------------
struct EffGroupingBaseSizeData
{
    // Constant
    enum BAR_type_t
    {
        CHTM00 =  0,
        CHTM01 =  1,
        CHTM02 =  2,
        CHTM03 =  3,
        CHTM04 =  4,
        CHTM05 =  5,
        CHTM06 =  6,
        CHTM07 =  7,
        CHTM08 =  8,
        CHTM09 =  9,
        CHTM10 = 10,
        CHTM11 = 11,
        CHTM12 = 12,
        CHTM13 = 13,
        CHTM14 = 14,
        CHTM15 = 15,
        CHTM16 = 16,
        CHTM17 = 17,
        CHTM18 = 18,
        CHTM19 = 19,
        CHTM20 = 20,
        CHTM21 = 21,
        CHTM22 = 22,
        CHTM23 = 23,
        CHTM24 = 24,
        CHTM25 = 25,
        CHTM26 = 26,
        CHTM27 = 27,
        CHTM28 = 28,
        CHTM29 = 29,
        CHTM30 = 30,
        CHTM31 = 31,
        NHTM   = 32,
        SMF    = 33,
        OCC    = 34,
    };

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
        memset(iv_chtm_bar_bases, 0, sizeof(iv_chtm_bar_bases));
        memset(iv_numHtmQueues, 0, sizeof(iv_numHtmQueues));
        iv_requestedBarsList.clear();
    }

    /// @brief setBaseSizeData
    /// Function that sets base and size values for both mirror
    /// and non-mirror.
    /// @param[in] i_sysAttrs    System attribute settings
    /// @param[in] i_groupData   Effective grouping data info
    /// @return void.
    void setBaseSizeData(const EffGroupingSysAttrs& i_sysAttrs,
                         const EffGroupingData& i_groupData);

    /// @brief Figure out which memory region (index) an address belongs to.
    /// @param[in]  i_addr         Given address
    /// @param[in]  i_sysAttrs     System attribute settings
    /// @param[out] o_accMemSize   Accumulated memory size to cover address
    /// @return Memory region index where i_addr belongs to.
    uint8_t getMemoryRegionIndex(const uint64_t i_addr,
                                 const EffGroupingSysAttrs& i_sysAttrs,
                                 uint64_t& o_accMemSize);

    /// @brief Build the requested BARs list (iv_requestedBarsList) based on
    ///        BAR size attribute settings (ATTR_PROC_NHTM_BAR_SIZE,
    ///        ATTR_PROC_OCC_SANDBOX_SIZE, etc...).  The list then will be
    ///        sorted from highest to lowest amount of memory requested.
    /// @param[in] i_sysAttrs     System attribute settings
    /// @param[in] i_procAttrs    Proc attribute values
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode getRequestedBarList(
        const EffGroupingSysAttrs& i_sysAttrs,
        const EffGroupingProcAttrs& i_procAttrs);

    /// @brief Set base address attributes.
    /// @param[in]     i_sysAttrs     System attribute settings
    /// @param[in]     i_requestedBar Requested BAR pair <type, size>
    /// @param[in/out] io_groupData   Effective grouping data info
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode setBaseAddrAttributes(
        const EffGroupingSysAttrs& i_sysAttrs,
        const std::pair<BAR_type_t, uint64_t> i_requestedBar,
        EffGroupingData& io_groupData);

    /// @brief Calculate then assign the number of HTM queues for each
    /// channel.  This is done for performance purpose when dumping
    /// out HTM traces.
    /// To improve trace performance, we need to reserve HTM queues on
    /// the channels that serve HTM trace space.
    /// The # of queues will be 16 (maximum) divided by the # of MCC
    void calcHtmQueues(const EffGroupingData& i_groupData,
                       const uint64_t i_startHtmIndex,
                       const uint64_t i_endHtmIndex);

    /// @brief setBaseSizeAttr
    /// Function that set base and size attribute values for both mirror
    /// and non-mirror based on given base/size data.
    /// @param[in]     i_target      Reference to Processor Chip Target
    /// @param[in]     i_sysAttrs    System attribute settings
    /// @param[in/out] i_groupData   Effective grouping data info
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode setBaseSizeAttr(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const EffGroupingSysAttrs& i_sysAttrs,
        EffGroupingData& io_groupData);

    /// @brief writeBaseAddr
    /// Utility function that writes the BAR base to the appropriate
    /// BAR type's variable.
    /// @param[in]     i_barType     BAR type
    /// @param[in]     i_bar_base    BAR value
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode writeBaseAddr(BAR_type_t i_barType,
                                    const uint64_t i_bar_base);

    /// @brief Utility function that converts BAR type value to a string
    ///        and puts the result into a char buffer.
    /// @param[in]      i_barType  Bar type
    /// @param[out]     o_buf      Output char buffer
    /// @return void
    void getBarString(const BAR_type_t i_barType, char o_buf[]);

    // Public data
    uint64_t iv_mem_bases[NUM_NON_MIRROR_REGIONS];
    uint64_t iv_mem_bases_ack[NUM_NON_MIRROR_REGIONS];
    uint64_t iv_memory_sizes[NUM_NON_MIRROR_REGIONS];
    uint64_t iv_memory_sizes_ack[NUM_NON_MIRROR_REGIONS];

    uint64_t iv_mirror_bases[NUM_MIRROR_REGIONS];
    uint64_t iv_mirror_bases_ack[NUM_MIRROR_REGIONS];
    uint64_t iv_mirror_sizes[NUM_MIRROR_REGIONS];
    uint64_t iv_mirror_sizes_ack[NUM_MIRROR_REGIONS];

    uint64_t iv_smf_bar_base = 0;
    uint64_t iv_occ_sandbox_base = 0;
    uint64_t iv_nhtm_bar_base = 0;
    uint64_t iv_chtm_bar_bases[NUM_OF_CHTM_REGIONS];

    // Num of HTM queues to be reserved for each MCC
    uint8_t iv_numHtmQueues[NUM_MCC_PER_PROC];
    bool iv_omi = false;

    // Requested BARs < BAR type, BAR size >
    std::vector<std::pair<BAR_type_t, uint64_t>> iv_requestedBarsList;

};

// See description in struct definition
void EffGroupingBaseSizeData::getBarString(const BAR_type_t i_barType,
        char o_buf[])
{
    if ( (i_barType >= CHTM00) && (i_barType <= CHTM31) )
    {
        sprintf(o_buf, "CHTM%d", i_barType);
    }
    else if (i_barType == NHTM)
    {
        sprintf(o_buf, "NHTM");
    }
    else if (i_barType == SMF)
    {
        sprintf(o_buf, "SMF");
    }
    else if (i_barType == OCC)
    {
        sprintf(o_buf, "OCC");
    }

    return;
}

// See description in struct definition
void EffGroupingBaseSizeData::setBaseSizeData(
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingData& i_groupData)
{
    FAPI_DBG("Entering");
    char displayBuf[MAX_DISPLAY_BUFFER_SIZE];

    // Process non-mirrored ranges
    for (uint8_t ii = 0; ii < (DATA_GROUPS / 2); ii++) // 0-7 --> Non mirror
    {
        // Base addresses for distinct non-mirrored ranges
        iv_mem_bases[ii]     = i_groupData.iv_data[ii][BASE_ADDR];
        iv_mem_bases_ack[ii] = i_groupData.iv_data[ii][BASE_ADDR];
        iv_memory_sizes[ii]  = i_groupData.iv_data[ii][MCC_SIZE] *
                               i_groupData.iv_data[ii][MCC_IN_GROUP];
        iv_memory_sizes_ack[ii] = i_groupData.iv_data[ii][GROUP_SIZE];

        // Convert to full byte addresses
        iv_mem_bases[ii]        <<= 30;
        iv_mem_bases_ack[ii]    <<= 30;
        iv_memory_sizes[ii]     <<= 30;
        iv_memory_sizes_ack[ii] <<= 30;

        // Only trace valid groups
        if (iv_memory_sizes[ii] > 0)
        {
            FAPI_DBG("Non-mirror, Group %d:", ii);
            FAPI_DBG("    i_groupData.iv_data[%d][BASE_ADDR] = %d",
                     ii,  i_groupData.iv_data[ii][BASE_ADDR]);
            FAPI_DBG("    i_groupData.iv_data[%d][MCC_SIZE] = %d",
                     ii,  i_groupData.iv_data[ii][MCC_SIZE]);
            FAPI_DBG("    i_groupData.iv_data[%d][MCC_IN_GROUP] = %d",
                     ii,  i_groupData.iv_data[ii][MCC_IN_GROUP]);

            getSizeString(iv_mem_bases[ii], displayBuf);
            FAPI_DBG("    iv_mem_bases[%d] = %s", ii, displayBuf);
            getSizeString(iv_mem_bases_ack[ii], displayBuf);
            FAPI_DBG("    iv_mem_bases_ack[%d] = %s", ii, displayBuf);
            getSizeString(iv_memory_sizes[ii], displayBuf);
            FAPI_DBG("    iv_memory_sizes[%d] = %s", ii, displayBuf);
            getSizeString(iv_memory_sizes_ack[ii], displayBuf);
            FAPI_DBG("    iv_memory_sizes_ack[%d] = %s", ii, displayBuf);
        }
    }

    // Process mirrored ranges
    if (i_sysAttrs.iv_hwMirrorEnabled != fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
    {
        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            uint8_t l_index = ii + MIRR_OFFSET;

            if (i_groupData.iv_data[l_index][MCC_IN_GROUP] != 0)
            {
                // Set base address for distinct mirrored ranges
                iv_mirror_bases[ii] = i_groupData.iv_data[l_index][BASE_ADDR];
                iv_mirror_bases_ack[ii] = i_groupData.iv_data[l_index][BASE_ADDR];
                // Set sizes for distinct mirrored ranges
                iv_mirror_sizes[ii] = (i_groupData.iv_data[ii][MCC_SIZE] *
                                       i_groupData.iv_data[ii][MCC_IN_GROUP]) / 2;
                iv_mirror_sizes_ack[ii] = i_groupData.iv_data[l_index][GROUP_SIZE];

                // Convert to full byte addresses
                iv_mirror_bases[ii]     <<= 30;
                iv_mirror_bases_ack[ii] <<= 30;
                iv_mirror_sizes[ii]     <<= 30;
                iv_mirror_sizes_ack[ii] <<= 30;
            }

            // Only trace valid groups
            if (iv_mirror_sizes[ii] > 0)
            {
                FAPI_DBG("Mirror, Group %d:", ii + MIRR_OFFSET);
                FAPI_DBG("    i_groupData.iv_data[%d][BASE_ADDR] = %d",
                         l_index, i_groupData.iv_data[l_index][BASE_ADDR]);
                FAPI_DBG("    i_groupData.iv_data[%d][MCC_IN_GROUP] = %d",
                         l_index, i_groupData.iv_data[l_index][MCC_IN_GROUP]);
                FAPI_DBG("    i_groupData.iv_data[%d][MCC_SIZE] = %d",
                         l_index, i_groupData.iv_data[l_index][MCC_SIZE]);

                getSizeString(iv_mirror_bases[ii], displayBuf);
                FAPI_DBG("    iv_mirror_bases[%d] = %s", ii, displayBuf);
                getSizeString(iv_mirror_bases_ack[ii], displayBuf);
                FAPI_DBG("    iv_mirror_bases_ack[%d] = %s", ii, displayBuf);
                getSizeString(iv_mirror_sizes[ii], displayBuf);
                FAPI_DBG("    iv_mirror_sizes[%d] = %s", ii, displayBuf);
                getSizeString(iv_mirror_sizes_ack[ii], displayBuf);
                FAPI_DBG("    iv_mirror_sizes_ack[%d] = %s", ii, displayBuf);
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

// See description in struct definition
uint8_t EffGroupingBaseSizeData::getMemoryRegionIndex(
    const uint64_t i_addr,
    const EffGroupingSysAttrs& i_sysAttrs,
    uint64_t& o_accMemSize)
{
    uint8_t l_index = 0xFF;
    uint8_t l_numRegions = 0;
    uint64_t* l_memSizePtr = NULL;
    uint64_t l_startBaseAddr = 0;
    char displayBuf[MAX_DISPLAY_BUFFER_SIZE];

    getSizeString(i_addr, displayBuf);
    FAPI_DBG("Entering EffGroupingBaseSizeData::getMemoryRegionIndex: "
             "i_addr = %s", displayBuf);

    // Point to non-mirror or mirror memory data
    l_memSizePtr = &iv_memory_sizes[0];
    l_numRegions = NUM_NON_MIRROR_REGIONS;
    l_startBaseAddr = iv_mem_bases[0];

    if (i_sysAttrs.iv_mirrorPlacement ==
        fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
    {
        l_memSizePtr = &iv_mirror_sizes[0] ;
        l_numRegions = NUM_MIRROR_REGIONS;
        l_startBaseAddr = iv_mirror_bases[0];
    }

    getSizeString(l_startBaseAddr, displayBuf);
    FAPI_DBG(" Start base addr: %s, Num regions %d", displayBuf, l_numRegions);

    o_accMemSize = 0;

    for (uint8_t ii = 0; ii < l_numRegions; ii++)
    {
        // If mem available in region, add them up
        if ( (*l_memSizePtr) > 0 )
        {
            o_accMemSize += (*l_memSizePtr);
            getSizeString(o_accMemSize, displayBuf);
            FAPI_DBG("ii = %d, o_accMemSize = %s", ii, displayBuf);

            if ( (l_startBaseAddr + o_accMemSize) >= i_addr )
            {
                l_index = ii;
                break;
            }
        }

        // Passed last region (no more memory). This is the case where
        // ALT_MEM exists, just return highest region index that contains memory.
        else
        {
            l_index = ii - 1;
            break;
        }

        // Point to next region
        l_memSizePtr++;
    }

    getSizeString(o_accMemSize, displayBuf);
    FAPI_INF("Exiting - Index = %d, , %s", l_index, displayBuf);

    return l_index;
}

// See description in struct definition
void EffGroupingBaseSizeData::calcHtmQueues(const EffGroupingData& i_groupData,
        const uint64_t i_startHtmIndex,
        const uint64_t i_endHtmIndex)
{
    // To improve trace performance, we need to reserve HTM queues on
    // the channels that serve HTM trace space.

    // Number of MCC from HTM start -> HTM end
    uint8_t l_totalChannels = 0;

    for (uint8_t ii = i_startHtmIndex; ii <= i_endHtmIndex; ii++)
    {
        l_totalChannels += i_groupData.iv_data[ii][MCC_IN_GROUP];
    }

    // Spread the queues evenly to all the MCC that serve HTM
    // Each will have max queues (16) divided by the # of MCC
    uint8_t l_numQueues =  MAX_HTM_QUEUE_PER_MCC / l_totalChannels;
    FAPI_DBG("l_totalChannels = %d, l_numQueues %d", l_totalChannels, l_numQueues);

    // Set the queues to the MCC array
    for (uint8_t ii = i_startHtmIndex; ii <= i_endHtmIndex; ii++)
    {
        // MCC in group loop
        for (uint8_t l_memberIdx = 0;
             l_memberIdx < i_groupData.iv_data[ii][MCC_IN_GROUP]; l_memberIdx++)
        {
            uint8_t jj = i_groupData.iv_data[ii][MEMBER_IDX(0) + l_memberIdx];
            iv_numHtmQueues[jj] = l_numQueues; // jj = MCC
        }
    }

    return;
}

// See description in struct definition
fapi2::ReturnCode EffGroupingBaseSizeData::getRequestedBarList(
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingProcAttrs& i_procAttrs)
{
    FAPI_DBG("Entering");
    char displayBuf1[MAX_DISPLAY_BUFFER_SIZE];
    char displayBuf2[MAX_DISPLAY_BUFFER_SIZE];

    // CHTM bar size requested
    for (uint8_t ii = 0; ii < NUM_OF_CHTM_REGIONS; ii++)
    {
        if (i_procAttrs.iv_chtmBarSizes[ii] > 0)
        {
            // ii = CHTM enum
            iv_requestedBarsList.push_back(
                std::make_pair(static_cast<BAR_type_t>(ii),
                               i_procAttrs.iv_chtmBarSizes[ii]));
        }
    }

    // NHTM bar size requested
    if (i_procAttrs.iv_nhtmBarSize > 0)
    {
        iv_requestedBarsList.push_back(std::make_pair(NHTM, i_procAttrs.iv_nhtmBarSize));
    }

    // SMF bar size requested
    if (i_procAttrs.iv_smfBarSize > 0)
    {
        // Determine whether secure memory region can be enabled
        FAPI_ASSERT(i_sysAttrs.iv_smfConfig == fapi2::ENUM_ATTR_SMF_CONFIG_ENABLED,
                    fapi2::MSS_EFF_GROUPING_SMF_NOT_ENABLED()
                    .set_SMF_CONFIG(i_sysAttrs.iv_smfConfig)
                    .set_SMF_TOTAL_BAR_SIZE(i_procAttrs.iv_smfBarSize),
                    "setSMFBaseSizeData: Requirements to enable a secure memory "
                    "space not met: ATTR_PROC_SMF_BAR_SIZE size is set but "
                    "ATTR_SMF_CONFIG is not enabled. smfConfig 0x%.8X, "
                    "smfSize 0x%.16llX",
                    i_sysAttrs.iv_smfConfig, i_procAttrs.iv_smfBarSize);

        // Ensure that requested secure memory size meets minimum design requirements
        FAPI_ASSERT((i_procAttrs.iv_smfBarSize & 0xFFFFFFFFF0000000) != 0,
                    fapi2::MSS_EFF_GROUPING_SMF_256MB_MINIMUM_ERROR()
                    .set_SMF_TOTAL_BAR_SIZE(i_procAttrs.iv_smfBarSize),
                    "setSMFBaseSizeData: Requested size of secure memory must "
                    "meet design minimum requirement of 256MB."
                    "smfSize 0x%.16llX",
                    i_procAttrs.iv_smfBarSize);

        iv_requestedBarsList.push_back(std::make_pair(SMF, i_procAttrs.iv_smfBarSize));
    }

    // OCC bar size requested
    if (i_procAttrs.iv_occSandboxSize > 0)
    {
        iv_requestedBarsList.push_back(std::make_pair(OCC, i_procAttrs.iv_occSandboxSize));
    }

    // Sort reserved memory list from highest to lowest in sizes
    std::sort(iv_requestedBarsList.begin(), iv_requestedBarsList.end(),
              [](const std::pair<BAR_type_t, uint64_t>& a,
                 const std::pair<BAR_type_t, uint64_t>& b)
    {
        return (a.second > b.second);
    });

    // Result traces
    FAPI_INF("getRequestedBarList: Num of requested memory bars: %u", iv_requestedBarsList.size());

    for (auto l_pair : iv_requestedBarsList)
    {
        getBarString(l_pair.first, displayBuf1);
        getSizeString(l_pair.second, displayBuf2);
        FAPI_INF("  BAR type: %s, Requested size: %s", displayBuf1, displayBuf2);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

// See description in struct definition
fapi2::ReturnCode EffGroupingBaseSizeData::writeBaseAddr(BAR_type_t i_barType,
        const uint64_t i_bar_base)
{
    // Write i_bar_base to the correct variable in database
    if ( (i_barType >= CHTM00) && (i_barType <= CHTM31) )
    {
        iv_chtm_bar_bases[i_barType] = i_bar_base;
    }
    else if (i_barType == NHTM)
    {
        iv_nhtm_bar_base = i_bar_base;
    }
    else if (i_barType == SMF)
    {
        iv_smf_bar_base = i_bar_base;
        // Also sets addr(bit 12 in P10) to indicate secure memory base address
        iv_smf_bar_base |= ((uint64_t)1 << (63 - SECURE_MEMORY_BASE_ADDRESS_BIT));
    }
    else if (i_barType == OCC)
    {
        iv_occ_sandbox_base = i_bar_base;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_EFF_GROUPING_INVALID_BAR_TYPE()
                    .set_BAR_TYPE(i_barType),
                    "writeBaseAddr: Invalid BAR type value %d", i_barType);
    }

fapi_try_exit:
    return fapi2::current_err;
}

// See description in struct definition
fapi2::ReturnCode EffGroupingBaseSizeData::setBaseAddrAttributes(
    const EffGroupingSysAttrs& i_sysAttrs,
    const std::pair<BAR_type_t, uint64_t> i_requestedBar,
    EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");

    // Hold mem bases & sizes for mirror/non-mirror
    uint8_t l_numRegions = 0;
    uint8_t l_memHole = 0;
    uint8_t l_index = 0;
    uint8_t l_start_htm_index = 0;
    uint8_t l_end_htm_index = 0;
    uint64_t l_accMemSize = 0;
    uint64_t l_availMem = 0;
    uint64_t l_memSizeAfterBar = 0;
    uint64_t l_barBase = 0;
    uint64_t l_mem_bases[NUM_NON_MIRROR_REGIONS];
    uint64_t l_mem_sizes[NUM_NON_MIRROR_REGIONS];
    uint64_t l_smf_bases[NUM_NON_MIRROR_REGIONS];
    uint64_t l_smf_sizes[NUM_NON_MIRROR_REGIONS];
    uint64_t l_smf_valid[NUM_NON_MIRROR_REGIONS];
    uint64_t l_requestedSize = i_requestedBar.second;
    char displayBuf1[MAX_DISPLAY_BUFFER_SIZE];
    char displayBuf2[MAX_DISPLAY_BUFFER_SIZE];

    // Setup mem base and size working array depending on mirror setting
    if (i_sysAttrs.iv_mirrorPlacement ==
        fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)   // Normal
    {
        l_numRegions = NUM_NON_MIRROR_REGIONS;
        memcpy(l_mem_bases, iv_mem_bases, sizeof(iv_mem_bases));
        memcpy(l_mem_sizes, iv_memory_sizes,  sizeof(iv_memory_sizes));
    }
    else // Flipped
    {
        l_numRegions = NUM_MIRROR_REGIONS;
        memcpy(l_mem_bases, iv_mirror_bases, sizeof(iv_mirror_bases));
        memcpy(l_mem_sizes, iv_mirror_sizes, sizeof(iv_mirror_sizes));
    }

    // Calculate available memory
    for (uint8_t ii = 0; ii < l_numRegions; ii++)
    {
        l_availMem += l_mem_sizes[ii];

        for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
        {
            if (io_groupData.iv_data[ii][ALT_VALID(jj)])
            {
                l_memHole++;
            }
        }
    }

    // Info traces
    getBarString(i_requestedBar.first, displayBuf1);
    getSizeString(l_requestedSize, displayBuf2);
    FAPI_INF("setBaseAddrAttributes: Requested type: %s, %s",
             displayBuf1, displayBuf2);
    getSizeString(l_requestedSize, displayBuf2);
    FAPI_INF("                Avail memory = %s, l_memHole %d",
             displayBuf2, l_memHole);

    // Error if available memory is not enough for requested size
    FAPI_ASSERT(l_availMem >= l_requestedSize,
                fapi2::MSS_EFF_GROUPING_NOT_ENOUGH_MEMORY()
                .set_REQ_MEMORY_TYPE(i_requestedBar.first)
                .set_AVAIL_MEM_SIZE(l_availMem)
                .set_REQUESTED_MEM_SIZE(l_requestedSize)
                .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_mirrorPlacement),
                "setBaseAddrAttributes: Requested memory space is not available."
                "Avail Mem 0x%.16llX, Requested Mem type %d, Size 0x%.16llX, "
                "Placement policy %u",
                l_availMem, i_requestedBar.first, l_requestedSize,
                i_sysAttrs.iv_mirrorPlacement);

    // Calculate which memory region the BAR starts
    l_memSizeAfterBar = l_availMem - l_requestedSize;

    getSizeString(l_memSizeAfterBar, displayBuf1);
    FAPI_DBG("Memsize available after BAR: %s", displayBuf1);
    l_index = getMemoryRegionIndex(l_memSizeAfterBar + l_mem_bases[0],
                                   i_sysAttrs,
                                   l_accMemSize);

    // Adjusted memory size for region where this requested memory starts
    l_mem_sizes[l_index] = l_mem_sizes[l_index] -
                           (l_accMemSize - l_memSizeAfterBar);

    getSizeString(l_mem_sizes[l_index], displayBuf1);
    FAPI_DBG("Adjusted memsize at index - l_mem_sizes[%d] = %s",
             l_index,  displayBuf1);

    if (l_memHole)
    {
        FAPI_ASSERT(l_mem_sizes[l_index] >= l_requestedSize,
                    fapi2::MSS_EFF_GROUPING_MEMORY_BAR_NOT_POSSIBLE()
                    .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_mirrorPlacement)
                    .set_MEMSIZE_INDEX(l_index)
                    .set_ADJUSTED_SIZE(l_mem_sizes[l_index])
                    .set_REQ_MEMORY_TYPE(i_requestedBar.first)
                    .set_REQUESTED_MEM_SIZE(l_requestedSize)
                    .set_AVAIL_MEM_SIZE(l_availMem),
                    "setBaseAddrAttributes: BAR not possible, "
                    "Placement policy %u, MemorySizes[%d] 0x%.16llX, "
                    "Requested Mem type %d, Requested size 0x%.16llX, Avail mem 0x%.16llX",
                    i_sysAttrs.iv_mirrorPlacement, l_index, l_mem_sizes[l_index],
                    i_requestedBar.first, l_requestedSize, l_availMem);
    }

    // Setting base address
    l_barBase = l_mem_bases[l_index] + l_mem_sizes[l_index];
    FAPI_TRY(writeBaseAddr(i_requestedBar.first, l_barBase),
             "Error from writeBaseAddr", (uint64_t)fapi2::current_err);

    // Verify base address aligned with allocated size.
    // The OCC sandbox base is just a FW scratch area and no HW
    // functions mapped to it so we don't need to check its base alignment.
    if ( (i_requestedBar.first != OCC) && (l_barBase > 0) )
    {
        FAPI_ASSERT((l_barBase & (l_requestedSize - 1)) == 0,
                    fapi2::MSS_EFF_GROUPING_ADDRESS_NOT_ALIGNED()
                    .set_REQ_MEMORY_TYPE(i_requestedBar.first)
                    .set_BAR_BASE(l_barBase)
                    .set_BAR_SIZE(l_requestedSize),
                    "setBaseAddrAttributes: BAR base address is not aligned with its size "
                    "Requested Mem type %d, BAR base 0x%.16llX, Bar size 0x%.16llX",
                    i_requestedBar.first, l_barBase, l_requestedSize);
    }

    // Assign HTM queues for NHTM bar
    if (i_requestedBar.first == NHTM)
    {
        l_start_htm_index = getMemoryRegionIndex(iv_nhtm_bar_base,
                            i_sysAttrs,
                            l_accMemSize);
        l_end_htm_index = getMemoryRegionIndex(iv_nhtm_bar_base + l_requestedSize,
                                               i_sysAttrs,
                                               l_accMemSize);
        FAPI_INF("Start HTM index: %d, End HTM index = %d",
                 l_start_htm_index, l_end_htm_index);
        calcHtmQueues(io_groupData, l_start_htm_index, l_end_htm_index);
    }

    // For SMF, needs to update SMF data in groupData variable for
    // ATTR_MSS_MCC_GROUP_32
    // Note: Lower address is compared against addr(22:35)
    else if (i_requestedBar.first == SMF)
    {
        // Ensure that requested secure memory offset meets design requirements
        FAPI_ASSERT((iv_smf_bar_base & 0x000000000FFFFFFF) == 0,
                    fapi2::MSS_EFF_GROUPING_SMF_256MB_OFFSET_ERROR()
                    .set_SMF_BASE_ADDR(iv_smf_bar_base),
                    "setBarBases: Secure memory regions "
                    "are required by design to be on 256MB offsets. "
                    "smfBaseAddr 0x%.16llX", iv_smf_bar_base);

        // Setup smf base and size working array
        memset(l_smf_valid, 0, sizeof(l_smf_valid));
        memset(l_smf_bases, 0, sizeof(l_smf_bases));
        memset(l_smf_sizes, 0, sizeof(l_smf_sizes));

        // Allocate SMF base address and size for region where SMF starts
        l_smf_bases[l_index] = l_mem_bases[l_index] + l_mem_sizes[l_index];
        l_smf_sizes[l_index] = (l_accMemSize - l_memSizeAfterBar);
        l_smf_valid[l_index] = 1;

        // Redefine memory region for SMF and zero out memory size of regions used by SMF
        for (uint8_t ii = l_index + 1; ii < l_numRegions; ii++)
        {
            l_smf_bases[ii] = l_mem_bases[ii];
            l_smf_sizes[ii] = l_mem_sizes[ii];

            if (l_smf_sizes[ii] != 0)
            {
                l_smf_valid[ii] = 1;
            }
        }

        // Update SMF data in groupData variable for ATTR_MSS_MCC_GROUP_32
        // Note: Lower address is compared against addr(22:35)
        for (uint8_t ii = 0; ii < io_groupData.iv_numGroups; ii++)
        {
            io_groupData.iv_data[ii][SMF_VALID] = l_smf_valid[ii];
            io_groupData.iv_data[ii][SMF_SIZE] = l_smf_sizes[ii] >> (63 - 35);
            io_groupData.iv_data[ii][SMF_BASE_ADDR] = l_smf_bases[ii] >> (63 - 35);
        }
    }

    // Zero out memory size of regions used by this BAR
    for (uint8_t ii = l_index + 1; ii < l_numRegions; ii++)
    {
        l_mem_sizes[ii] = 0;
    }

    // Update mem sizes with working array values
    if (i_sysAttrs.iv_mirrorPlacement ==
        fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)   // Normal
    {
        memcpy(iv_memory_sizes, l_mem_sizes, sizeof(iv_memory_sizes));
    }
    else
    {
        memcpy(iv_mirror_sizes, l_mem_sizes, sizeof(iv_mirror_sizes));
    }

    // Result traces
    FAPI_INF("EffGroupingBaseSizeData::setBaseAddrAttributes");

    getSizeString(l_availMem, displayBuf1);
    getSizeString(l_requestedSize, displayBuf2);
    FAPI_INF("  Placement policy %u, Avail memory %s, Requested size %s",
             i_sysAttrs.iv_mirrorPlacement, displayBuf1, displayBuf2);
    FAPI_INF("  Index: %d, iv_mem_bases 0x%.16llX, iv_memory_sizes 0x%.16llX",
             l_index, l_mem_bases[l_index], l_mem_sizes[l_index]);
    getSizeString(l_barBase, displayBuf1);
    FAPI_INF("BAR base %s", displayBuf1);

    if (i_requestedBar.first == SMF)
    {
        for (uint8_t ii = 0; ii < l_numRegions; ii++)
        {
            getSizeString(l_smf_bases[ii], displayBuf1);
            getSizeString(l_smf_sizes[ii], displayBuf2);
            FAPI_INF("  Index: %d, l_smf_bases %s, l_smf_sizes %s",
                     ii, displayBuf1, displayBuf2);
        }
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
    char displayBuf[MAX_DISPLAY_BUFFER_SIZE];

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
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MEM_SIZES_ACK, i_target, iv_memory_sizes_ack),
             "Error setting ATTR_PROC_MEM_SIZES_ACK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_MSS_MCC_GROUP_32
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MCC_GROUP_32, i_target, io_groupData.iv_data),
             "Error setting ATTR_MSS_MCC_GROUP_32, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_NHTM_BAR_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_NHTM_BAR_BASE_ADDR, i_target, iv_nhtm_bar_base),
             "Error setting ATTR_PROC_NHTM_BAR_BASE_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_CHTM_BAR_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_CHTM_BAR_BASE_ADDR, i_target, iv_chtm_bar_bases),
             "Error setting ATTR_PROC_CHTM_BAR_BASE_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_OCC_SANDBOX_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_OCC_SANDBOX_BASE_ADDR, i_target, iv_occ_sandbox_base),
             "Error setting ATTR_PROC_OCC_SANDBOX_BASE_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set ATTR_PROC_SMF_BAR_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_SMF_BAR_BASE_ADDR, i_target, iv_smf_bar_base),
             "Error setting ATTR_PROC_SMF_BAR_BASE_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Mirror mode attribute setting
    if (i_sysAttrs.iv_hwMirrorEnabled != fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
    {

        // Set ATTR_PROC_MIRROR_BASES
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_BASES, i_target, iv_mirror_bases),
                 "Error setting ATTR_PROC_MIRROR_BASES, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Set ATTR_PROC_MIRROR_BASES_ACK
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_BASES_ACK, i_target, iv_mirror_bases_ack),
                 "Error setting ATTR_PROC_MIRROR_BASES_ACK, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Set ATTR_PROC_MIRROR_SIZES
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_SIZES, i_target, iv_mirror_sizes),
                 "Error setting ATTR_PROC_MIRROR_SIZES, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Set ATTR_PROC_MIRROR_SIZES_ACK
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_MIRROR_SIZES_ACK, i_target, iv_mirror_sizes_ack),
                 "Error setting ATTR_PROC_MIRROR_SIZES_ACK, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }

    // Set ATTR_HTM_QUEUES
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_HTM_QUEUES, i_target, iv_numHtmQueues),
             "Error setting ATTR_HTM_QUEUES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    //----------------------------------------------------------------------
    //  Display attribute values
    //----------------------------------------------------------------------
    for (uint8_t ii = 0; ii < NUM_NON_MIRROR_REGIONS; ii++)
    {
        getSizeString(iv_mem_bases[ii], displayBuf);
        FAPI_INF("ATTR_PROC_MEM_BASES    [%u]: %s", ii, displayBuf);

        getSizeString(iv_mem_bases_ack[ii], displayBuf);
        FAPI_INF("ATTR_PROC_MEM_BASES_ACK[%u]: %s", ii, displayBuf);

        getSizeString(iv_memory_sizes[ii], displayBuf);
        FAPI_INF("ATTR_PROC_MEM_SIZES    [%u]: %s", ii, displayBuf);

        getSizeString(iv_memory_sizes_ack[ii], displayBuf);
        FAPI_INF("ATTR_PROC_MEM_SIZES_ACK[%u]: %s", ii, displayBuf);
    }

    getSizeString(iv_nhtm_bar_base, displayBuf);
    FAPI_INF("ATTR_PROC_NHTM_BAR_BASE_ADDR : %s", displayBuf);

    for (uint8_t ii = 0; ii < NUM_OF_CHTM_REGIONS; ii++)
    {
        getSizeString(iv_chtm_bar_bases[ii], displayBuf);
        FAPI_INF("ATTR_PROC_CHTM_BAR_BASE_ADDR[%u] : %s", ii, displayBuf);
    }

    getSizeString(iv_occ_sandbox_base, displayBuf);
    FAPI_INF("ATTR_PROC_OCC_SANDBOX_BASE_ADDR: %s", displayBuf);
    FAPI_INF("ATTR_PROC_SMF_BAR_BASE_ADDR : 0x%.16llX (%d GB)",
             iv_smf_bar_base, (iv_smf_bar_base & 0xFFF7FFFFFFFFFFFF) >> 30);

    // Display mirror mode attribute values
    if (i_sysAttrs.iv_hwMirrorEnabled != fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
    {
        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            getSizeString(iv_mirror_bases[ii], displayBuf);
            FAPI_INF("ATTR_PROC_MIRROR_BASES[%u]: %s", ii, displayBuf);
        }

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            getSizeString(iv_mirror_bases_ack[ii], displayBuf);
            FAPI_INF("ATTR_PROC_MIRROR_BASES_ACK[%u] %s", ii, displayBuf);
        }

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            getSizeString(iv_mirror_sizes[ii], displayBuf);
            FAPI_INF("ATTR_PROC_MIRROR_SIZES[%u]: %s", ii, displayBuf);
        }

        for (uint8_t ii = 0; ii < NUM_MIRROR_REGIONS; ii++)
        {
            getSizeString(iv_mirror_sizes_ack[ii], displayBuf);
            FAPI_INF("ATTR_PROC_MIRROR_SIZES_ACK[%u]: %s", ii, displayBuf);
        }
    }

    // Display ATTR_HTM_QUEUES
    FAPI_INF("Num of HTM queues:");

    for (uint8_t ii = 0; ii < NUM_MCC_PER_PROC; ii++)
    {
        FAPI_INF("ATTR_HTM_QUEUES[%u]: %d", ii, iv_numHtmQueues[ii]);
    }

    // Display ATTR_MSS_MCC_GROUP_32 as debug trace
    for (uint8_t ii = 0; ii < DATA_GROUPS; ii++)
    {
        for (uint8_t jj = 0; jj < DATA_ELEMENTS; jj++)
        {
            FAPI_DBG("ATTR_MSS_MCC_GROUP_32[%u][%u] : 0x%.8X",
                     ii, jj, io_groupData.iv_data[ii][jj]);
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}

/**
 * @struct mcBarData_t
 *
 * Contains BAR data info for a Memory Controller Channel (MCC)
 */
struct mcBarData_t
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    inline mcBarData_t()
        : MCFGP_valid(false), MCFGP_chan_per_group(0),
          MCFGP_chan0_group_member_id(0), MCFGP_chan1_group_member_id(0),
          MCFGP_group_size(0), MCFGP_groupBaseAddr(0), MCMODE2_subchannels_en(0),
          MCFGPM_valid(false), MCFGPM_group_size(0), MCFGPM_groupBaseAddr(0),
          MCFGPA_SMF_valid(0), MCFGPA_SMF_LOWER_addr(0), MCFGPA_SMF_UPPER_addr(0),
          MCFGPMA_SMF_valid(0), MCFGPMA_SMF_LOWER_addr(0), MCFGPMA_SMF_UPPER_addr(0)
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

    // Subchannel information
    uint8_t  MCMODE2_subchannels_en;

    // Info to program MCFGPM reg
    bool     MCFGPM_valid;
    uint32_t MCFGPM_group_size;
    uint32_t MCFGPM_groupBaseAddr;

    // Info to program MCFGPA reg
    bool     MCFGPA_HOLE_valid[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPA_HOLE_LOWER_addr[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPA_HOLE_UPPER_addr[NUM_OF_ALT_MEM_REGIONS];
    bool     MCFGPA_SMF_valid;
    uint32_t MCFGPA_SMF_LOWER_addr;
    uint32_t MCFGPA_SMF_UPPER_addr;

    // Info to program MCFGPMA reg
    bool     MCFGPMA_HOLE_valid[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPMA_HOLE_LOWER_addr[NUM_OF_ALT_MEM_REGIONS];
    uint32_t MCFGPMA_HOLE_UPPER_addr[NUM_OF_ALT_MEM_REGIONS];
    bool     MCFGPMA_SMF_valid;
    uint32_t MCFGPMA_SMF_LOWER_addr;
    uint32_t MCFGPMA_SMF_UPPER_addr;
};

/**
 * @struct mccGroupInfo_t
 * Contains group data information related to an MCC.
 * This information is used to determine the channel per group
 * value for the MCFGP reg.
 *
 */
struct mccGroupInfo_t
{
    /**
     * @brief Default constructor. Initializes instance variables to zero
     */
    inline mccGroupInfo_t()
        : myGroup(0), numMCCInGroup(0), groupSize(0), groupBaseAddr(0),
          channelId(0), smfMemValid(0), smfMemSize(0), smfBaseAddr(0)
    {
        memset(altMemValid, 0, sizeof(altMemValid));
        memset(altMemSize, 0, sizeof(altMemSize));
        memset(altBaseAddr, 0, sizeof(altBaseAddr));
    }
    // The group number which this MCC belongs to
    uint8_t myGroup;
    // # of MCC in the group which this MCC belongs to.
    uint8_t numMCCInGroup;
    // The size of the group which this MCC belongs to
    uint32_t groupSize;
    // The base address of the group which this MCC belongs to
    uint32_t groupBaseAddr;
    // The group member ID of this MCC
    uint8_t channelId;

    // ALT_MEM
    uint8_t altMemValid[NUM_OF_ALT_MEM_REGIONS];
    uint32_t altMemSize[NUM_OF_ALT_MEM_REGIONS];
    uint32_t altBaseAddr[NUM_OF_ALT_MEM_REGIONS];

    // SMF_MEM
    uint8_t smfMemValid;
    uint32_t smfMemSize;
    uint32_t smfBaseAddr;

};

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------
/// @brief grouping_validateAttributes
/// Function that checks to make sure the obtained memory grouping
//  attributes are valid.
///
/// @param[in] i_target    Reference to Processor Chip Target
/// @param[in] i_sysAttrs  Reference to system attributes
/// @param[in] i_procAttrs Reference to proc chip attributes
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode grouping_validateAttributes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingProcAttrs& i_procAttrs)
{
    FAPI_DBG("Entering");

    // If mirror is disabled, then can not be in FLIPPED mode
    if (i_sysAttrs.iv_hwMirrorEnabled == fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
    {
        FAPI_ASSERT(i_sysAttrs.iv_mirrorPlacement !=
                    fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED,
                    fapi2::MSS_EFF_CONFIG_MIRROR_DISABLED()
                    .set_MRW_HW_MIRRORING_ENABLE(i_sysAttrs.iv_hwMirrorEnabled)
                    .set_MIRROR_PLACEMENT_POLICY(i_sysAttrs.iv_mirrorPlacement),
                    "grouping_validateAttributes: Error: Mirroring disabled "
                    "but ATTR_MEM_MIRROR_PLACEMENT_POLICY is in FLIPPED mode");
    }

    // There must be at least one type of grouping allowed
    FAPI_ASSERT( ((i_sysAttrs.iv_groupsAllowed & ALL_GROUPS) != 0),
                 fapi2::MSS_EFF_GROUPING_NO_GROUP_ALLOWED()
                 .set_MSS_INTERLEAVE_ENABLE_VALUE(i_sysAttrs.iv_groupsAllowed)
                 .set_CHIP(i_target),
                 "grouping_validateAttributes: No valid group allowed - Group allowed 0x%.2X",
                 i_sysAttrs.iv_groupsAllowed);
fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

/// @brief Determine if 2 MCCs can be grouped together
///
/// @param[in]  i_memInfo           Memory configuration information
/// @param[in]  i_groupData         Current group data
/// @param[in]  i_mirrorIsRequired  True if Mirroring is required in system
/// @param[in]  i_MCC_A_Id          Port A's Id
/// @param[in]  i_MCC_B_Id          Port B's Id
///
/// @return True if the ports can be group together; false otherwise.
bool isGroupable(const EffGroupingMemInfo& i_memInfo,
                 const EffGroupingData& i_groupData,
                 const bool i_mirrorRequired,
                 const uint8_t i_MCC_A_Id,
                 const uint8_t i_MCC_B_Id)
{
    bool l_groupable = false;

    FAPI_DBG("Entering");

    do
    {
        // Two MCC can be grouped together if:
        //   - They are both not yet grouped.
        //   - They have the same (non-zeroed) memory amount installed
        //   - Their DIMM types are the same.
        //   - If Mirroring policy is 'REQUIRED', both sub-channels must be enabled.
        //   - Grouped channels must have the same number of sub-channels enabled.

        // Check grouped MCC
        if ( (i_groupData.iv_mccGrouped[i_MCC_A_Id] == true) ||
             (i_groupData.iv_mccGrouped[i_MCC_B_Id] == true) )
        {
            FAPI_DBG(" MCC already grouped - MCC_A grouped: %d, MCC_B grouped %d",
                     i_groupData.iv_mccGrouped[i_MCC_A_Id],
                     i_groupData.iv_mccGrouped[i_MCC_B_Id]);
            break;
        }

        // Check memory amount
        if ( (i_memInfo.iv_mccSize[i_MCC_A_Id] == 0) ||
             (i_memInfo.iv_mccSize[i_MCC_B_Id] == 0) ||
             (i_memInfo.iv_mccSize[i_MCC_A_Id] != i_memInfo.iv_mccSize[i_MCC_B_Id]) )
        {
            FAPI_DBG(" Memory not installed or sizes are different: MCC_A: %d GB, MCC_B %d GB",
                     i_memInfo.iv_mccSize[i_MCC_A_Id],
                     i_memInfo.iv_mccSize[i_MCC_B_Id]);
            break;
        }

        // Check DIMM types
        if ( (i_memInfo.iv_dimmType[i_MCC_A_Id] != i_memInfo.iv_dimmType[i_MCC_B_Id]) )
        {
            FAPI_DBG(" DIMM types are different: MCC_A type: %d, MCC_B type: %d",
                     i_memInfo.iv_dimmType[i_MCC_A_Id], i_memInfo.iv_dimmType[i_MCC_B_Id]);
            break;
        }

        // Both channels need to have the same number of subchannels configured, if
        // one has none it cannot be used
        if ( ( (i_memInfo.iv_SubChannelsEnabled[i_MCC_A_Id] == OMISubChannelConfig::BOTH) !=
               (i_memInfo.iv_SubChannelsEnabled[i_MCC_B_Id] == OMISubChannelConfig::BOTH) ) ||
             (i_memInfo.iv_SubChannelsEnabled[i_MCC_A_Id] == OMISubChannelConfig::NONE) ||
             (i_memInfo.iv_SubChannelsEnabled[i_MCC_B_Id] == OMISubChannelConfig::NONE) )
        {
            FAPI_DBG(" Sub-channels are not compatible: MCC_A sub-channel: %d, MCC_B sub-channel: %d",
                     i_memInfo.iv_SubChannelsEnabled[i_MCC_A_Id],
                     i_memInfo.iv_SubChannelsEnabled[i_MCC_B_Id]);
            break;
        }

        // If Mirror policy is 'REQUIRED', both ports must have both
        // sub-channels enabled.
        if (i_mirrorRequired)
        {
            if ( (i_memInfo.iv_SubChannelsEnabled[i_MCC_A_Id] != OMISubChannelConfig::BOTH) ||
                 (i_memInfo.iv_SubChannelsEnabled[i_MCC_B_Id] != OMISubChannelConfig::BOTH) )
            {
                FAPI_DBG(" Sub-channels are not both enabled: MCC_A sub-channel: %d, MCC_B sub-channel: %d",
                         i_memInfo.iv_SubChannelsEnabled[i_MCC_A_Id],
                         i_memInfo.iv_SubChannelsEnabled[i_MCC_B_Id]);
                break;
            }
        }

        // These 2 MCC can be grouped together
        l_groupable = true;

    }
    while(0);

    FAPI_DBG("Exiting isGroupable: Groupable = %d.", l_groupable);
    return l_groupable;
}

///
/// @brief Attempts to group 8 MCC per group
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo             Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired      Mirroring is required
///  @param[in/out] io_groupData       Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_group8MCCPerGroup(const EffGroupingMemInfo& i_memInfo,
                                const bool i_mirrorRequired,
                                EffGroupingData& io_groupData,
                                uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");
    FAPI_INF("grouping_group8MCCPerGroup: Attempting to group 8 MCCs");
    uint8_t& g = io_groupData.iv_numGroups;

    // Check all MCCs against MCC0
    bool grouped = true;

    for (uint8_t l_pos = 1; l_pos < NUM_MCC_PER_PROC; l_pos++)
    {
        FAPI_DBG("Checking MCC%d against MCC0", l_pos);

        if ( !isGroupable(i_memInfo, io_groupData, i_mirrorRequired,
                          MCC_ID_0, l_pos) )
        {
            grouped = false;
            FAPI_INF("Can not group by 8.", l_pos);
            break;
        }
    }

    // Group of 8 is possible
    if (grouped &&
        ((8 * i_memInfo.iv_mccSize[MCC_ID_0]) <= i_memInfo.iv_maxGroupMemSize))
    {
        // All 8 channels have the same amount of memory, group them
        io_groupData.iv_data[g][MCC_SIZE] = i_memInfo.iv_mccSize[0];
        io_groupData.iv_data[g][MCC_IN_GROUP] = 8;
        io_groupData.iv_data[g][GROUP_SIZE] = (NUM_MCC_PER_PROC * i_memInfo.iv_mccSize[0]);
        io_groupData.iv_data[g][MEMBER_IDX(0)] = MCC_ID_0;
        io_groupData.iv_data[g][MEMBER_IDX(1)] = MCC_ID_4;
        io_groupData.iv_data[g][MEMBER_IDX(2)] = MCC_ID_2;
        io_groupData.iv_data[g][MEMBER_IDX(3)] = MCC_ID_6;
        io_groupData.iv_data[g][MEMBER_IDX(4)] = MCC_ID_1;
        io_groupData.iv_data[g][MEMBER_IDX(5)] = MCC_ID_5;
        io_groupData.iv_data[g][MEMBER_IDX(6)] = MCC_ID_3;
        io_groupData.iv_data[g][MEMBER_IDX(7)] = MCC_ID_7;

        // Record all 8 MCCs have been grouped.
        memset(io_groupData.iv_mccGrouped, true, sizeof(io_groupData.iv_mccGrouped));

        // Group index increment
        g++;
        FAPI_INF("grouping_group8MCCPerGroup: Successfully grouped 8 MCCs.");
        io_MCCsRemained = 0;
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 6 MCC per group
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo         Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired  Mirroring is required
///  @param[in/out] io_groupData   Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_group6MCCPerGroup(const EffGroupingMemInfo& i_memInfo,
                                const bool i_mirrorRequired,
                                EffGroupingData& io_groupData,
                                uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");

    FAPI_INF("grouping_group6MCCPerGroup: Attempting to group 6 MCCs");
    uint8_t& g = io_groupData.iv_numGroups;

    // The following is all the allowed ways of grouping 6 MCCs per group.
    // Earlier array entries are higher priority.
    const uint8_t NUM_WAYS_6MCC_PER_GROUP = 4;
    const uint8_t MCC_PER_GROUP = 6;
    const uint8_t CFG_6MCC[NUM_WAYS_6MCC_PER_GROUP][MCC_PER_GROUP] =
    {
        { MCC_ID_0, MCC_ID_1, MCC_ID_2, MCC_ID_3, MCC_ID_4, MCC_ID_5 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_2, MCC_ID_3, MCC_ID_6, MCC_ID_7 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_4, MCC_ID_5, MCC_ID_6, MCC_ID_7 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_4, MCC_ID_5, MCC_ID_6, MCC_ID_7 },
    };

    // Figure out which group of 6 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_6MCC_PER_GROUP; ii++)
    {
        // Check all MCCs in row against first MCC
        bool potential_group = true;

        for (uint8_t jj = 1; jj < MCC_PER_GROUP; jj++)
        {
            FAPI_DBG("Checking CFG_6MCC[%d][%d]: MCC%d vs MCC%d:",
                     ii, jj, CFG_6MCC[ii][jj], CFG_6MCC[ii][0]);

            if ( !isGroupable(i_memInfo,
                              io_groupData,
                              i_mirrorRequired,
                              CFG_6MCC[ii][0],
                              CFG_6MCC[ii][jj]) )
            {
                FAPI_INF("Can not group by 6 for row %d.", ii);
                potential_group = false;
                break;
            }
        }

        // Group of 6 is possible
        if (potential_group &&
            ((MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_6MCC[ii][0]]) <= i_memInfo.iv_maxGroupMemSize))
        {
            io_groupData.iv_data[g][MCC_SIZE] =
                i_memInfo.iv_mccSize[CFG_6MCC[ii][0]];
            io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
            io_groupData.iv_data[g][GROUP_SIZE] =
                MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_6MCC[ii][0]];

            // Record which MCC were grouped
            for (uint8_t jj = 0; jj < MCC_PER_GROUP; jj++)
            {
                io_groupData.iv_data[g][MEMBER_IDX(jj)] = CFG_6MCC[ii][jj];
                io_groupData.iv_mccGrouped[CFG_6MCC[ii][jj]] = true;
            }

            // Group index increment
            g++;
            FAPI_INF("grouping_group6MCCPerGroup: Successfuly group 6 MCCs. "
                     "CFG_6MCC[%d]: %u, %u, %u, %u, %u, %u",
                     ii,
                     CFG_6MCC[ii][0], CFG_6MCC[ii][1],
                     CFG_6MCC[ii][2], CFG_6MCC[ii][3],
                     CFG_6MCC[ii][4], CFG_6MCC[ii][5]);
            io_MCCsRemained -= 6;
            // Break out of row (ii) loop, impossible to have another group of 6
            break;
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 4 MCCs on different MCs
///
/// Rules: 4 MCCs must not be grouped yet
///        4 MCCs must have the same amound of memory.
///        4 MCCs must be on different MCs
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo        Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired Mirroring is required
///  @param[in/out] io_groupData  Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_4MCCs_on_different_MCs(const EffGroupingMemInfo& i_memInfo,
                                     const bool i_mirrorRequired,
                                     EffGroupingData& io_groupData,
                                     uint8_t& io_MCCsRemained)

{
    FAPI_DBG("Entering");
    FAPI_INF("grouping_4MCCs_on_different_MCs: Attempting to group 4 MCCs on different MCs");
    uint8_t& g = io_groupData.iv_numGroups;
    const uint8_t MCC_PER_GROUP = 4;
    const uint8_t NUM_WAYS_4MCC_PER_GROUP = 16;

    // Combination of 4 MCCs on different MCs
    const uint8_t CFG_4MCC[NUM_WAYS_4MCC_PER_GROUP][MCC_PER_GROUP] =
    {
        { MCC_ID_0, MCC_ID_2, MCC_ID_4, MCC_ID_6 },
        { MCC_ID_0, MCC_ID_2, MCC_ID_4, MCC_ID_7 },
        { MCC_ID_0, MCC_ID_2, MCC_ID_5, MCC_ID_6 },
        { MCC_ID_0, MCC_ID_2, MCC_ID_5, MCC_ID_7 },
        { MCC_ID_0, MCC_ID_3, MCC_ID_4, MCC_ID_6 },
        { MCC_ID_0, MCC_ID_3, MCC_ID_4, MCC_ID_7 },
        { MCC_ID_0, MCC_ID_3, MCC_ID_5, MCC_ID_6 },
        { MCC_ID_0, MCC_ID_3, MCC_ID_5, MCC_ID_7 },
        { MCC_ID_1, MCC_ID_2, MCC_ID_4, MCC_ID_6 },
        { MCC_ID_1, MCC_ID_2, MCC_ID_4, MCC_ID_7 },
        { MCC_ID_1, MCC_ID_2, MCC_ID_5, MCC_ID_6 },
        { MCC_ID_1, MCC_ID_2, MCC_ID_5, MCC_ID_7 },
        { MCC_ID_1, MCC_ID_3, MCC_ID_4, MCC_ID_6 },
        { MCC_ID_1, MCC_ID_3, MCC_ID_4, MCC_ID_7 },
        { MCC_ID_1, MCC_ID_3, MCC_ID_5, MCC_ID_6 },
        { MCC_ID_1, MCC_ID_3, MCC_ID_5, MCC_ID_7 },
    };

    // Figure out which groups of 4 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_4MCC_PER_GROUP; ii++)
    {
        // Skip if group size would be too large
        if ( (MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_4MCC[ii][0]]) > i_memInfo.iv_maxGroupMemSize )
        {
            FAPI_DBG("Skip row %u, as group size formed would be too large", ii);
            continue;
        }

        // Check all MCCs in row against first MCC
        bool potential_group = true;

        for (uint8_t jj = 1; jj < MCC_PER_GROUP; jj++)
        {
            FAPI_DBG("Checking CFG_4MCC[%d][%d]: MCC%d vs MCC%d",
                     ii, jj, CFG_4MCC[ii][jj], CFG_4MCC[ii][0]);

            if ( !isGroupable(i_memInfo,
                              io_groupData,
                              i_mirrorRequired,
                              CFG_4MCC[ii][0],
                              CFG_4MCC[ii][jj]) )
            {
                FAPI_INF("Can not group by 4 for row %d.", ii);
                potential_group = false;
                break;
            }
        }

        // Group of 4 is possible
        if ( potential_group )
        {
            io_groupData.iv_data[g][MCC_SIZE] =
                i_memInfo.iv_mccSize[CFG_4MCC[ii][0]];
            io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
            io_groupData.iv_data[g][GROUP_SIZE] =
                MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_4MCC[ii][0]];
            io_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_4MCC[ii][0];
            io_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_4MCC[ii][1];
            io_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_4MCC[ii][2];
            io_groupData.iv_data[g][MEMBER_IDX(3)] = CFG_4MCC[ii][3];

            // Record which MCC were grouped
            for (uint8_t jj = 0; jj < MCC_PER_GROUP; jj++)
            {
                io_groupData.iv_mccGrouped[CFG_4MCC[ii][jj]] = true;
            }

            // Group index increment
            g++;
            FAPI_INF("grouping_4MCCs_on_different_MCs: Successfully grouped 4 "
                     "MCCs. CFG_4MCC[%d] %u, %u, %u, %u", ii,
                     CFG_4MCC[ii][0], CFG_4MCC[ii][1],
                     CFG_4MCC[ii][2], CFG_4MCC[ii][3]);
            io_MCCsRemained -= 4;

            // Exit loop if not enough for another group of 4
            if (io_MCCsRemained < 4)
            {
                break;
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 4 MCCs with 2 channels of opposite corners
///
/// Rules: 4 MCCs must not be grouped yet
///        4 MCCs must have the same amound of memory.
///        4 MCCs must be at opposite corner MCs
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo        Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired Mirroring is required
///  @param[in/out] io_groupData  Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_4MCCs_opposite_corners(const EffGroupingMemInfo& i_memInfo,
                                     const bool i_mirrorRequired,
                                     EffGroupingData& io_groupData,
                                     uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");
    FAPI_INF("grouping_4MCCs_opposite_corners: Attempting to group 4 MCCs opposite corners");
    uint8_t& g = io_groupData.iv_numGroups;
    const uint8_t MCC_PER_GROUP = 4;
    const uint8_t NUM_WAYS_4MCC_PER_GROUP = 2;

    //
    //    MCC6/7       MCC4/5
    //       MC3 -- MC2
    //        |      |
    //       MC1 -- MC0
    //    MCC2/3       MCC0/1
    //

    // Combination of 4 MCCs on different MCs
    const uint8_t CFG_4MCC[NUM_WAYS_4MCC_PER_GROUP][MCC_PER_GROUP] =
    {
        { MCC_ID_0, MCC_ID_1, MCC_ID_6, MCC_ID_7 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_4, MCC_ID_5 },
    };

    // Figure out which groups of 4 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_4MCC_PER_GROUP; ii++)
    {
        // Skip if group size would be too large
        if ( (MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_4MCC[ii][0]]) > i_memInfo.iv_maxGroupMemSize )
        {
            FAPI_DBG("Skip row %u, as group size formed would be too large", ii);
            continue;
        }

        // Check all MCCs in row against first MCC
        bool potential_group = true;

        for (uint8_t jj = 1; jj < MCC_PER_GROUP; jj++)
        {
            FAPI_DBG("grouping_4MCCs_opposite_corners - Checking CFG_4MCC[%d][%d]: MCC%d vs MCC%d",
                     ii, jj, CFG_4MCC[ii][jj], CFG_4MCC[ii][0]);

            if ( !isGroupable(i_memInfo,
                              io_groupData,
                              i_mirrorRequired,
                              CFG_4MCC[ii][0],
                              CFG_4MCC[ii][jj]) )
            {
                FAPI_INF("grouping_4MCCs_opposite_corners - Can not group by 4 for row %d.", ii);
                potential_group = false;
                break;
            }
        }

        // Group of 4 is possible
        if ( potential_group )
        {
            io_groupData.iv_data[g][MCC_SIZE] =
                i_memInfo.iv_mccSize[CFG_4MCC[ii][0]];
            io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
            io_groupData.iv_data[g][GROUP_SIZE] =
                MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_4MCC[ii][0]];
            io_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_4MCC[ii][0];
            io_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_4MCC[ii][1];
            io_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_4MCC[ii][2];
            io_groupData.iv_data[g][MEMBER_IDX(3)] = CFG_4MCC[ii][3];

            // Record which MCC were grouped
            for (uint8_t jj = 0; jj < MCC_PER_GROUP; jj++)
            {
                io_groupData.iv_mccGrouped[CFG_4MCC[ii][jj]] = true;
            }

            // Group index increment
            g++;
            FAPI_INF("grouping_4MCCs_opposite_corners: Successfully grouped 4 "
                     "MCCs. CFG_4MCC[%d] %u, %u, %u, %u", ii,
                     CFG_4MCC[ii][0], CFG_4MCC[ii][1],
                     CFG_4MCC[ii][2], CFG_4MCC[ii][3]);
            io_MCCsRemained -= 4;

            // Exit loop if not enough for another group of 4
            if (io_MCCsRemained < 4)
            {
                break;
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 4 MCC per group
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo         Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired  Mirroring is required
///  @param[in/out] io_groupData   Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_group4MCCPerGroup(const EffGroupingMemInfo& i_memInfo,
                                const bool i_mirrorRequired,
                                EffGroupingData& io_groupData,
                                uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");
    FAPI_INF("grouping_group4MCCPerGroup: Attempting to group 4 MCCs");
    const uint8_t MCC_PER_GROUP = 4;
    uint8_t& g = io_groupData.iv_numGroups;

    //
    //    MCC6/7       MCC4/5
    //       MC3 -- MC2
    //        |      |
    //       MC1 -- MC0
    //    MCC2/3       MCC0/1
    //
    //   Priorities:
    //     1. One channel from each MC chiplet
    //     2. Two channels of opposite corners of the chip
    //     3. Any remaining possible combination
    //

    //  Priority 1: Try to group 1 MCC from each MC chiplet first
    grouping_4MCCs_on_different_MCs(i_memInfo, i_mirrorRequired, io_groupData, io_MCCsRemained);

    // Get out if remained MCCs are not to do group of 4
    if (io_MCCsRemained < 4)
    {
        goto fapi_try_exit;
    }

    // Priority 2: Try to group 2 MCCs of opposite corners of the proc
    grouping_4MCCs_opposite_corners(i_memInfo, i_mirrorRequired, io_groupData, io_MCCsRemained);

    // Get out if remained MCCs are not to do group of 4
    if (io_MCCsRemained < 4)
    {
        goto fapi_try_exit;
    }

    // Priority 3: Attempt group of 4 for the remaining un-grouped MCCs
    FAPI_INF("grouping_group4MCCPerGroup - Attempting to group remaining MCCs as group of 4");

    for (uint8_t mcc0 = 0; mcc0 < (NUM_MCC_PER_PROC - 3); mcc0++)
    {
        FAPI_DBG("mcc0 = MCC%u", mcc0);

        // Skip if MCC is already grouped, has no memory, or group size would
        // be too large
        if ( (io_groupData.iv_mccGrouped[mcc0]) ||
             (i_memInfo.iv_mccSize[mcc0] == 0)  ||
             ((MCC_PER_GROUP * i_memInfo.iv_mccSize[mcc0]) > i_memInfo.iv_maxGroupMemSize) )
        {
            FAPI_DBG("Skip MCC%d because already grouped, no memory, or group size is too large", mcc0);
            FAPI_DBG(" Grouped %u, MCC memsize %u",
                     io_groupData.iv_mccGrouped[mcc0],
                     (i_memInfo.iv_mccSize[mcc0] == 0))
            continue;
        }

        for (uint8_t mcc1 = mcc0 + 1; mcc1 < (NUM_MCC_PER_PROC - 2); mcc1++)
        {
            FAPI_DBG("mcc1 = MCC%u", mcc1);

            // Skip if MCC is already grouped or has no memory
            if ( (io_groupData.iv_mccGrouped[mcc1]) ||
                 (i_memInfo.iv_mccSize[mcc1] == 0) )
            {
                FAPI_DBG("Skip MCC%d because already grouped or empty:", mcc1);
                continue;
            }

            if ( !isGroupable(i_memInfo,
                              io_groupData,
                              i_mirrorRequired,
                              mcc0,
                              mcc1) )
            {
                FAPI_INF("Can not group MCC%u MCC%u together", mcc0, mcc1);
                continue;
            }

            for (uint8_t mcc2 = mcc1 + 1; mcc2 < (NUM_MCC_PER_PROC - 1); mcc2++)
            {
                FAPI_DBG("mcc2 = MCC%u", mcc2);

                // Skip if MCC is already grouped or has no memory
                if ( (io_groupData.iv_mccGrouped[mcc2]) ||
                     (i_memInfo.iv_mccSize[mcc2] == 0) )
                {
                    FAPI_DBG("Skip MCC%d because already grouped or empty:", mcc2);
                    continue;
                }

                if ( !isGroupable(i_memInfo,
                                  io_groupData,
                                  i_mirrorRequired,
                                  mcc0,
                                  mcc2) )
                {
                    FAPI_INF("Can not group MCC%u MCC%u together", mcc0, mcc2);
                    continue;
                }

                for (uint8_t mcc3 = mcc2 + 1; mcc3 < NUM_MCC_PER_PROC; mcc3++)
                {
                    FAPI_DBG("mcc3 = MCC%u", mcc3);

                    // Skip if MCC is already grouped or has no memory
                    if ( (io_groupData.iv_mccGrouped[mcc3]) ||
                         (i_memInfo.iv_mccSize[mcc3] == 0) )
                    {
                        FAPI_DBG("Skip MCC%d because already grouped or empty:", mcc3);
                        continue;
                    }

                    if ( !isGroupable(i_memInfo,
                                      io_groupData,
                                      i_mirrorRequired,
                                      mcc0,
                                      mcc3) )
                    {
                        FAPI_INF("Can not group MCC%u MCC%u together", mcc0, mcc3);
                        continue;
                    }

                    // These 4 MCCs can be grouped together
                    io_groupData.iv_data[g][MCC_SIZE] = i_memInfo.iv_mccSize[mcc0];
                    io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
                    io_groupData.iv_data[g][GROUP_SIZE] =
                        MCC_PER_GROUP * i_memInfo.iv_mccSize[mcc0];
                    io_groupData.iv_data[g][MEMBER_IDX(0)] = mcc0;
                    io_groupData.iv_data[g][MEMBER_IDX(1)] = mcc1;
                    io_groupData.iv_data[g][MEMBER_IDX(2)] = mcc2;
                    io_groupData.iv_data[g][MEMBER_IDX(3)] = mcc3;

                    // Record which MCCs were grouped
                    io_groupData.iv_mccGrouped[mcc0] = true;
                    io_groupData.iv_mccGrouped[mcc1] = true;
                    io_groupData.iv_mccGrouped[mcc2] = true;
                    io_groupData.iv_mccGrouped[mcc3] = true;

                    // Group index increment
                    g++;
                    FAPI_INF("grouping_group4MCCPerGroup: Successfully grouped 4 "
                             "MCCs: %u, %u, %u, %u", mcc0, mcc1, mcc2, mcc3);

                    io_MCCsRemained -= 4;

                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 3 MCC per group
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo        Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired Mirroring is required
///  @param[in/out] io_groupData  Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_group3MCCPerGroup(const EffGroupingMemInfo& i_memInfo,
                                const bool i_mirrorRequired,
                                EffGroupingData& io_groupData,
                                uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");

    // The following is all the allowed ways of grouping 3 MCC per group.
    // Earlier array entries are higher priority.
    FAPI_INF("grouping_group3MCCPerGroup: Attempting to group 3 MCC");
    uint8_t& g = io_groupData.iv_numGroups;

    const uint8_t NUM_WAYS_3MCC_PER_GROUP = 24;
    const uint8_t MCC_PER_GROUP = 3;
    const uint8_t CFG_3MCC[NUM_WAYS_3MCC_PER_GROUP][MCC_PER_GROUP] =
    {
        { MCC_ID_0, MCC_ID_1, MCC_ID_2 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_3 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_4 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_5 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_6 },
        { MCC_ID_0, MCC_ID_1, MCC_ID_7 },

        { MCC_ID_2, MCC_ID_3, MCC_ID_0 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_1 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_4 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_5 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_6 },
        { MCC_ID_2, MCC_ID_3, MCC_ID_7 },

        { MCC_ID_4, MCC_ID_5, MCC_ID_0 },
        { MCC_ID_4, MCC_ID_5, MCC_ID_1 },
        { MCC_ID_4, MCC_ID_5, MCC_ID_2 },
        { MCC_ID_4, MCC_ID_5, MCC_ID_3 },
        { MCC_ID_4, MCC_ID_5, MCC_ID_6 },
        { MCC_ID_4, MCC_ID_5, MCC_ID_7 },

        { MCC_ID_6, MCC_ID_7, MCC_ID_0 },
        { MCC_ID_6, MCC_ID_7, MCC_ID_1 },
        { MCC_ID_6, MCC_ID_7, MCC_ID_2 },
        { MCC_ID_6, MCC_ID_7, MCC_ID_3 },
        { MCC_ID_6, MCC_ID_7, MCC_ID_4 },
        { MCC_ID_6, MCC_ID_7, MCC_ID_5 }
    };

    // Figure out which group of 3 can potentially be grouped
    for (uint8_t ii = 0; ii < NUM_WAYS_3MCC_PER_GROUP; ii++)
    {
        // Check all MCCs in row against first MCC
        bool potential_group = true;

        for (uint8_t jj = 1; jj < MCC_PER_GROUP; jj++)
        {
            FAPI_DBG("Checking CFG_3MCC[%d][%d]: MCC%d vs MCC%d:",
                     ii, jj, CFG_3MCC[ii][jj], CFG_3MCC[ii][0]);

            if ( !isGroupable(i_memInfo,
                              io_groupData,
                              i_mirrorRequired,
                              CFG_3MCC[ii][0],
                              CFG_3MCC[ii][jj]) )
            {
                FAPI_INF("Can not group by 3 for row %d.", ii);
                potential_group = false;
                break;
            }
        }

        // Group of 3 is possible
        if (potential_group &&
            ((MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_3MCC[ii][0]]) <= i_memInfo.iv_maxGroupMemSize))
        {
            io_groupData.iv_data[g][MCC_SIZE] =
                i_memInfo.iv_mccSize[CFG_3MCC[ii][0]];
            io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
            io_groupData.iv_data[g][GROUP_SIZE] =
                MCC_PER_GROUP * i_memInfo.iv_mccSize[CFG_3MCC[ii][0]];
            io_groupData.iv_data[g][MEMBER_IDX(0)] = CFG_3MCC[ii][0];
            io_groupData.iv_data[g][MEMBER_IDX(1)] = CFG_3MCC[ii][1];
            io_groupData.iv_data[g][MEMBER_IDX(2)] = CFG_3MCC[ii][2];

            // Record which MCC were grouped
            for (uint8_t jj = 0; jj < MCC_PER_GROUP; jj++)
            {
                io_groupData.iv_mccGrouped[CFG_3MCC[ii][jj]] = true;
            }

            // Group index increment
            g++;
            FAPI_INF("grouping_group3MCCPerGroup: Successfully grouped 3 "
                     "MCCs. CFG_3MCC[%d] %u, %u, %u, %u", ii,
                     CFG_3MCC[ii][0], CFG_3MCC[ii][1],
                     CFG_3MCC[ii][2]);
            io_MCCsRemained -= 3;

            if (io_MCCsRemained < 3)
            {
                break;
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 2 MCC on the same MC
///
/// Rules: Both MCC must not be grouped yet
///        Both MCC must have the same amound of memory.
///        Both MCC must be on the same MC
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo        Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired Mirroring is required
///  @param[in/out] io_groupData  Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_2MCC_on_same_MC(const EffGroupingMemInfo& i_memInfo,
                              const bool i_mirrorRequired,
                              EffGroupingData& io_groupData,
                              uint8_t& io_MCCsRemained)

{
    FAPI_DBG("Entering");
    FAPI_INF("grouping_2MCC_on_same_MC: Attempting to group 2 MCCs on same MC");
    uint8_t& g = io_groupData.iv_numGroups;
    const uint8_t MCC_PER_GROUP = 2;

    for (uint8_t pos = 0; pos < NUM_MCC_PER_PROC; pos += 2)
    {
        FAPI_DBG("Trying MCC%d vs MCC%d", pos, pos + 1);

        if ( !isGroupable(i_memInfo,
                          io_groupData,
                          i_mirrorRequired,
                          pos,
                          pos + 1) )
        {
            FAPI_INF("Can not group by 2.");
            continue;
        }

        // Group size must be in range
        if ((MCC_PER_GROUP * i_memInfo.iv_mccSize[pos]) >
            i_memInfo.iv_maxGroupMemSize)
        {
            FAPI_DBG("MCC %u & %u can't be grouped because group size is too large, skip",
                     pos, pos + 1);
            continue;
        }

        // Successfully find 2 MCC on same MC to group
        io_groupData.iv_data[g][MCC_SIZE] = i_memInfo.iv_mccSize[pos];
        io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
        io_groupData.iv_data[g][GROUP_SIZE] =
            MCC_PER_GROUP * i_memInfo.iv_mccSize[pos];
        io_groupData.iv_data[g][MEMBER_IDX(0)] = pos;
        io_groupData.iv_data[g][MEMBER_IDX(1)] = pos + 1;

        // Record which MCC were grouped
        io_groupData.iv_mccGrouped[pos] = true;
        io_groupData.iv_mccGrouped[pos + 1] = true;

        // Group index increment
        g++;
        FAPI_INF("grouping_2MCC_on_same_MC: Successfully grouped "
                 "2 MCCs: %u, %u", pos, pos + 1);
        io_MCCsRemained -= 2;

        if (io_MCCsRemained < 2)
        {
            break;
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 2 MCC per group
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo            Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired     Mirroring required
///  @param[in/out] io_groupData      Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_group2MCCPerGroup(const EffGroupingMemInfo& i_memInfo,
                                const bool i_mirrorRequired,
                                EffGroupingData& io_groupData,
                                uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");
    FAPI_INF("grouping_group2MCCPerGroup: Attempting to group 2 MCC");
    uint8_t& g = io_groupData.iv_numGroups;
    const uint8_t MCC_PER_GROUP = 2;

    // Rules:
    //  - Try to group 2 MCC on same MC first.  This has no functional or performace impact,
    //    just a convenience from a debug standpoint.
    //  - If Mirroring is 'REQUIRED', the MCC must have both sub-channels enabled.

    // 1. Try to group 2 MCC that are in the same MC (highest priority)
    grouping_2MCC_on_same_MC(i_memInfo, i_mirrorRequired, io_groupData, io_MCCsRemained);

    // Get out if not enough MCCs to do group of 2
    if (io_MCCsRemained < 2)
    {
        goto fapi_try_exit;
    }

    // 2. Attempt group of 2 for the remaining un-grouped MCC
    FAPI_INF("Attempting to group the remaining MCC as group of 2");

    for (uint8_t pos = 0; pos < (NUM_MCC_PER_PROC - 1); pos++)
    {
        // Skip if MCC is already grouped or has no memory
        if ( (io_groupData.iv_mccGrouped[pos]) ||
             (i_memInfo.iv_mccSize[pos] == 0) )

        {
            FAPI_DBG("Skip MCC%d because already grouped or empty:", pos);
            FAPI_DBG("   io_groupData.iv_mccGrouped[%d] = %d", pos, io_groupData.iv_mccGrouped[pos]);
            FAPI_DBG("    i_memInfo.iv_mccSize[%d] = %d", pos, i_memInfo.iv_mccSize[pos]);
            continue;
        }

        // Skip if group size would be too large
        if ((MCC_PER_GROUP * i_memInfo.iv_mccSize[pos]) >
            i_memInfo.iv_maxGroupMemSize)
        {
            FAPI_DBG("Skip this MCC %u, as group size formed would be too large",
                     pos);
            continue;
        }

        // Check to see if any remaining ungrouped MCC can be grouped together by 2
        for (uint8_t ii = pos + 1; ii < NUM_MCC_PER_PROC; ii++)
        {
            FAPI_DBG("Trying MCC%d vs MCC%d", pos, ii);

            if ( !isGroupable(i_memInfo,
                              io_groupData,
                              i_mirrorRequired,
                              pos,
                              ii) )
            {
                FAPI_INF("Can not group by 2.");
                continue;
            }

            // Successfully find 2 MCC to group
            io_groupData.iv_data[g][MCC_SIZE] = i_memInfo.iv_mccSize[pos];
            io_groupData.iv_data[g][MCC_IN_GROUP] = MCC_PER_GROUP;
            io_groupData.iv_data[g][GROUP_SIZE] =
                MCC_PER_GROUP * i_memInfo.iv_mccSize[pos];
            io_groupData.iv_data[g][MEMBER_IDX(0)] = pos;
            io_groupData.iv_data[g][MEMBER_IDX(1)] = ii;

            // Record which MCC were grouped
            io_groupData.iv_mccGrouped[pos] = true;
            io_groupData.iv_mccGrouped[ii] = true;

            g++;

            FAPI_INF("grouping_group2MCCPerGroup: Successfully grouped 2 "
                     "MCCs: %u, %u", pos, ii);

            break; // Break out of remaining MCC loop
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Attempts to group 1 MCC per group
///
/// If they can be grouped, fills in the following fields in io_groupData:
///  - iv_data[<group>][MCC_SIZE]
///  - iv_data[<group>][MCC_IN_GROUP]
///  - iv_data[<group>][GROUP_SIZE]
///  - iv_data[<group>][MEMBER_IDX(<members>)]
///  - iv_mccGrouped[<group>]
///  - iv_numGroups
///
///  @param[in]  i_memInfo        Reference to EffGroupingMemInfo structure
///  @param[in]  i_mirrorRequired Mirroring required
///  @param[in/out] io_groupData  Reference to in/out data
///  @param[in/out] io_numMCCsRemained Number of ungrouped MCCs remained
///
void grouping_group1MCCPerGroup(const EffGroupingMemInfo& i_memInfo,
                                const bool i_mirrorRequired,
                                EffGroupingData& io_groupData,
                                uint8_t& io_MCCsRemained)
{
    FAPI_DBG("Entering");

    // Any MCC with a non-zero size can be 'grouped'
    FAPI_INF("grouping_group1MCCPerGroup: Attempting to group 1 MCC");
    uint8_t& g = io_groupData.iv_numGroups;

    for (uint8_t pos = 0; pos < NUM_MCC_PER_PROC; pos++)
    {
        // If Mirror policy is 'REQUIRED', both ports must have both sub-channels enabled.
        if ( (i_mirrorRequired) &&
             (i_memInfo.iv_SubChannelsEnabled[pos] != OMISubChannelConfig::BOTH) )
        {
            FAPI_DBG("MCC %d, Sub-channel %d", pos, i_memInfo.iv_SubChannelsEnabled[pos])
            FAPI_DBG("Unable to group 1 MCC: sub-channels are not both enabled "
                     "for REQUIRED mirroring");
            continue;
        }

        if ( (!io_groupData.iv_mccGrouped[pos]) &&
             (i_memInfo.iv_mccSize[pos] != 0) &&
             (i_memInfo.iv_mccSize[pos] <= i_memInfo.iv_maxGroupMemSize) )
        {
            // This MCC is not already grouped and has memory
            io_groupData.iv_data[g][MCC_SIZE] = i_memInfo.iv_mccSize[pos];
            io_groupData.iv_data[g][MCC_IN_GROUP] = 1;
            io_groupData.iv_data[g][GROUP_SIZE] = i_memInfo.iv_mccSize[pos];
            io_groupData.iv_data[g][MEMBER_IDX(0)] = pos;

            // Group index increment
            g++;

            // Record which MCC was grouped
            io_groupData.iv_mccGrouped[pos] = true;
            FAPI_INF("grouping_group1MCCPerGroup: Successfully grouped 1 "
                     "MCC: %u", pos);
            io_MCCsRemained -= 1;

            if (io_MCCsRemained < 1)
            {
                break;
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}


///
/// @brief Callout DIMM attached to ungrouped port, appends
/// MSS_EFF_GROUPING_UNABLE_TO_GROUP_DIMM to input return code
///
/// Ensure any ungrouped DIMMs are called out for deconfiguration
///
/// @tparam    T               Template paramter, passed in port target type
/// @param[in] i_dimm_target   Target identifying DIMM attached to ungrouped port
/// @param[in] i_port_target   Target identifying with ungrouped port
/// @param[in] i_portIndex     Port number associated with target
/// @param[in] i_portSize      Size associated with this port
/// @param[in] o_rc            Return code object to be appended
///
/// @return void
///
template<fapi2::TargetType T>
void calloutDIMM(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target,
    const fapi2::Target<T>& i_port_target,
    const uint8_t i_portIndex,
    const uint64_t i_portSize,
    fapi2::ReturnCode& o_rc)
{
    FAPI_DBG("Start");

    char l_dimm_target_string[fapi2::MAX_ECMD_STRING_LEN];
    char l_port_target_string[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_dimm_target, l_dimm_target_string, fapi2::MAX_ECMD_STRING_LEN);
    fapi2::toString(i_port_target, l_port_target_string, fapi2::MAX_ECMD_STRING_LEN);

    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm_target = i_dimm_target;
    fapi2::ffdc_t DIMM_TARGET;
    fapi2::Target<T> l_port_target = i_port_target;
    fapi2::ffdc_t PORT_TARGET;
    uint8_t l_portIndex = i_portIndex;
    fapi2::ffdc_t MC_PORT;
    uint64_t l_portSize = i_portSize;
    fapi2::ffdc_t MC_PORT_SIZE;

    DIMM_TARGET.ptr() = static_cast<void*>(&l_dimm_target);
    DIMM_TARGET.size() = sizeof(l_dimm_target);
    PORT_TARGET.ptr() = static_cast<void*>(&l_port_target);
    PORT_TARGET.size() = sizeof(l_port_target);
    MC_PORT.ptr() = static_cast<void*>(&l_portIndex);
    MC_PORT.size() = sizeof(l_portIndex);
    MC_PORT_SIZE.ptr() = static_cast<void*>(&l_portSize);
    MC_PORT_SIZE.size() = sizeof(l_portSize);

    FAPI_ERR("Unable to group port %s, calling out DIMM: %s",
             l_port_target_string, l_dimm_target_string);
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_MSS_EFF_GROUPING_UNABLE_TO_GROUP_DIMM);
    FAPI_DBG("End");
    return;
}

///
/// @brief Determine set of DIMM targets attached to a target.
/// Target type could be OCMB, OMI, or MCC.
///
/// @tparam     T                 Template paramter, passed in target
///
/// @param[in]  i_target          Target (of type T)
/// @param[out] o_dimm_targets    Vector of DIMM targets, attached
///                               DIMMs will be appended at end
/// @return void
///
template<fapi2::TargetType T>
void getAttachedDimms(
    const fapi2::Target<T>& i_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& o_dimm_targets);

/// template specialization for OCMB target type
template <>
void getAttachedDimms(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& o_dimm_targets)
{
    FAPI_DBG("Start");
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_dimm_targets =
                i_target.template getChildren<fapi2::TARGET_TYPE_DIMM>();

    o_dimm_targets.insert(o_dimm_targets.end(),
                          l_dimm_targets.begin(),
                          l_dimm_targets.end());
    FAPI_DBG("End");
}

/// template specialization for OMI target type
template <>
void getAttachedDimms(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& o_dimm_targets)
{
    FAPI_DBG("Start");

    for (auto l_ocmb_target : i_target.template getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>())
    {
        getAttachedDimms<fapi2::TARGET_TYPE_OCMB_CHIP>(l_ocmb_target, o_dimm_targets);
    }

    FAPI_DBG("End");
}

/// template specialization for MCC target type
template <>
void getAttachedDimms(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& o_dimm_targets)
{
    FAPI_DBG("Start");

    for (auto l_omi_target : i_target.template getChildren<fapi2::TARGET_TYPE_OMI>())
    {
        getAttachedDimms<fapi2::TARGET_TYPE_OMI>(l_omi_target, o_dimm_targets);
    }

    FAPI_DBG("End");
}

///
/// @brief Generate DIMM callouts based on ports which are ungrouped
///
/// @tparam    T                  Template paramter, passed in port target
///
/// @param[in] i_ports_functional Per-port functional status
/// @param[in] i_ports_ungrouped  Per-port grouping status
/// @param[in] i_ports_tgt_index  Per-port target vector index
/// @param[in] i_ports_targets    Set of port targets
/// @param[in] i_memInfo          Reference to Memory Info
/// @param[in] i_hwMirrorEnabled  Mirroring policy
/// @param[in] o_dimm_targets     Vector of DIMM targets to append deconfigurations
/// @param[in] o_rc               Return code object to append deconfigurations
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode calloutDimmsForUngroupedPorts(
    const uint8_t i_ports_functional[NUM_MCC_PER_PROC],
    const uint8_t i_ports_ungrouped[NUM_MCC_PER_PROC],
    const uint8_t i_ports_tgt_index[NUM_MCC_PER_PROC],
    const std::vector<fapi2::Target<T>>& i_port_targets,
    const EffGroupingMemInfo& i_memInfo,
    const uint8_t i_hwMirrorEnabled,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& o_dimm_targets,
    fapi2::ReturnCode& o_rc);

/// template specialization for MCC target type
template<>
fapi2::ReturnCode calloutDimmsForUngroupedPorts(
    const uint8_t i_ports_functional[NUM_MCC_PER_PROC],
    const uint8_t i_ports_ungrouped[NUM_MCC_PER_PROC],
    const uint8_t i_ports_tgt_index[NUM_MCC_PER_PROC],
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCC>>& i_port_targets,
    const EffGroupingMemInfo& i_memInfo,
    const uint8_t i_hwMirrorEnabled,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& o_dimm_targets,
    fapi2::ReturnCode& o_rc)
{
    FAPI_DBG("Start");

    // o_rc contains the error we're going to append to
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // callout each DIMM which is associated with each ungrouped port
    for (uint8_t ii = 0; (ii < NUM_MCC_PER_PROC); ii += 1)
    {
        if (i_ports_functional[ii] && i_ports_ungrouped[ii])
        {
            getAttachedDimms(i_port_targets[i_ports_tgt_index[ii]],
                             o_dimm_targets);
        }
    }

    // add DIMM callouts
    for (const auto& l_dimm_target : o_dimm_targets)
    {
        fapi2::Target<fapi2::TARGET_TYPE_MCC> l_port_target = l_dimm_target
                .getParent<fapi2::TARGET_TYPE_OCMB_CHIP>()
                .getParent<fapi2::TARGET_TYPE_OMI>()
                .getParent<fapi2::TARGET_TYPE_MCC>();
        uint8_t l_port_index = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_port_target,
                               l_port_index),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        calloutDIMM(l_dimm_target,
                    l_port_target,
                    l_port_index,
                    i_memInfo.iv_mccSize[l_port_index],
                    o_rc);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Utility function to generate base return code for ungrouped port
///        error reporting
/// @param[in] i_maxRegionSize Maximum group/region size
/// @return MSS_EFF_GROUPING_UNABLE_TO_GROUP
fapi2::ReturnCode emitUnableToGroupError(const uint64_t& i_region_size)
{
    FAPI_DBG("Start");
    FAPI_ASSERT(false,
                fapi2::MSS_EFF_GROUPING_UNABLE_TO_GROUP()
                .set_MAX_REGION_SIZE(i_region_size),
                "Unable to group all ports on this chip");
fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Finds ungrouped MCC
/// If any are found then DIMMs will be deconfigured to attempt to satisfy
/// grouping rules
///
/// @tparam    T                  Template paramter, port target type
///
/// @param[in] i_target           Reference to processor chip target
/// @param[in] i_memInfo          Reference to Memory Info
/// @param[in] i_groupData        Reference to Group data
/// @param[in] i_hwMirrorEnabled  Mirroring policy
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
fapi2::ReturnCode grouping_findUngroupedMCC(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingMemInfo& i_memInfo,
    const EffGroupingData& i_groupData,
    const uint8_t i_hwMirrorEnabled)
{
    FAPI_DBG("Entering");

    // get vector of functional port targets
    std::vector<fapi2::Target<T>> l_port_targets = i_target.getChildren<T>();
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // build per-port vectors tracking:
    // - functional status
    // - grouped state
    // - index for associated target
    uint8_t l_ports_functional[NUM_MCC_PER_PROC];
    uint8_t l_ports_ungrouped[NUM_MCC_PER_PROC];
    uint8_t l_ports_tgt_index[NUM_MCC_PER_PROC];
    bool l_all_grouped = true;

    // initialize array storage
    for (uint8_t ii = 0; (ii < NUM_MCC_PER_PROC); ii++)
    {
        l_ports_functional[ii] = 0;
        l_ports_ungrouped[ii] = 0;
        l_ports_tgt_index[ii] = 0;
    }

    // mark functional ports & associated targets
    for (uint8_t jj = 0; (jj < l_port_targets.size()); jj++)
    {
        uint8_t l_unit_pos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_port_targets[jj], l_unit_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        l_ports_functional[l_unit_pos] = 1;
        l_ports_tgt_index[l_unit_pos] = jj;
    }

    // determine if any ports are not grouped
    for (uint8_t ii = 0; (ii < NUM_MCC_PER_PROC); ii++)
    {
        if ((i_memInfo.iv_mccSize[ii] != 0) &&
            (i_groupData.iv_mccGrouped[ii] == false))
        {
            FAPI_ERR("grouping_findUngroupedMCC: Unable to group port %u", ii);
            l_ports_ungrouped[ii] = 1;
            l_all_grouped = false;
        }
    }

    // initialize array storage
    for (uint8_t ii = 0; (ii < NUM_MCC_PER_PROC); ii++)
    {
        FAPI_DBG("Port %d", ii);
        FAPI_DBG("   functional: %d", l_ports_functional[ii]);
        FAPI_DBG("   ungrouped: %d",  l_ports_ungrouped[ii]);
        FAPI_DBG("   tgt_index: %d", l_ports_tgt_index[ii]);
    }

    // assert if there are any ungrouped ports on this chip
    if (!l_all_grouped)
    {
        // DIMMs to be called out
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_dimm_targets;

        // create base HWP error
        l_rc = emitUnableToGroupError(i_memInfo.iv_maxGroupMemSize);

        // append all DIMM callouts
        calloutDimmsForUngroupedPorts(l_ports_functional,
                                      l_ports_ungrouped,
                                      l_ports_tgt_index,
                                      l_port_targets,
                                      i_memInfo,
                                      i_hwMirrorEnabled,
                                      l_dimm_targets,
                                      l_rc);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return l_rc;
    }
    else
    {
        return fapi2::current_err;
    }
}

///
/// @brief Group memory channels
///        Attempt to group memory channels (MCC) according to P10 rules.
///
/// @param[in]  i_target      Reference to processor chip target
/// @param[in]  i_sysAttrs    System attribute settings
/// @param[in]  i_memInfo     Reference to EffGroupingMemInfo structure
/// @param[out] o_groupData   Reference to in/out data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode groupMCC(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs i_sysAttrs,
    const EffGroupingMemInfo& i_memInfo,
    EffGroupingData& o_groupData)
{
    FAPI_DBG("Start");

    // P10 MC architecture allows groups of 8, 6, 4, 3, 2, or 1.
    // Attempt to group from higher to lower number of MCC in a group.

    // Get mirror required setting. This is a factor of the grouping process
    bool l_mirrorRequired = (i_sysAttrs.iv_hwMirrorEnabled ==
                             fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_REQUIRED);

    auto l_mccChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCC>();
    uint8_t l_MCCsRemained = l_mccChiplets.size();

    // Group MCCs
    if ( (i_sysAttrs.iv_groupsAllowed & GROUP_8) && (l_MCCsRemained >= 8) )
    {
        grouping_group8MCCPerGroup(i_memInfo, l_mirrorRequired, o_groupData, l_MCCsRemained);
    }

    if ( (i_sysAttrs.iv_groupsAllowed & GROUP_6) && (l_MCCsRemained >= 6) )
    {
        grouping_group6MCCPerGroup(i_memInfo, l_mirrorRequired, o_groupData, l_MCCsRemained);
    }

    if ( (i_sysAttrs.iv_groupsAllowed & GROUP_4) && (l_MCCsRemained >= 4) )
    {
        grouping_group4MCCPerGroup(i_memInfo, l_mirrorRequired, o_groupData, l_MCCsRemained);
    }

    if ( (i_sysAttrs.iv_groupsAllowed & GROUP_3) && (l_MCCsRemained >= 3) )
    {
        grouping_group3MCCPerGroup(i_memInfo, l_mirrorRequired, o_groupData, l_MCCsRemained);
    }

    if ( (i_sysAttrs.iv_groupsAllowed & GROUP_2) && (l_MCCsRemained >= 2) )
    {
        grouping_group2MCCPerGroup(i_memInfo, l_mirrorRequired, o_groupData, l_MCCsRemained);
    }

    if ( (i_sysAttrs.iv_groupsAllowed & GROUP_1)  && (l_MCCsRemained >= 1) )
    {
        grouping_group1MCCPerGroup(i_memInfo, l_mirrorRequired, o_groupData, l_MCCsRemained);
    }

    // Verify all MCCs are grouped, or error out
    FAPI_TRY(grouping_findUngroupedMCC<fapi2::TARGET_TYPE_MCC>(i_target,
             i_memInfo,
             o_groupData,
             i_sysAttrs.iv_hwMirrorEnabled),
             "grouping_findUngroupedMCC() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

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
/// @return (void)
///
void grouping_calcAltMemory(EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering");

    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        // Determine if the Group size a power of 2
        if ( !isPowerOf2(io_groupData.iv_data[pos][GROUP_SIZE]) )
        {
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
/// @brief Sorts groups from high to low memory sizes
///
/// @param[io] io_groupData Group Data
///
/// @return (void)
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
/// @brief Determine if mirror groups are to be created for existing groups.
///
///        Mirror group is created when these conditions are all met:
///           - ATTR_MRW_HW_MIRRORING_ENABLE != OFF
///           - Both OMI sub-channels are enabled
///
/// @param[in]      i_sysAttrs     System attribute setting
/// @param[in]      i_memInfo      Reference to EffGroupingMemInfo structure
/// @param[in/out]  io_groupData   Grouping data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
void setupMirrorGroup(
    const EffGroupingSysAttrs& i_sysAttrs,
    const  EffGroupingMemInfo& i_memInfo,
    EffGroupingData& io_groupData)
{
    FAPI_DBG("Entering setupMirrorGroup");

    // No mirroring if ATTR_MRW_HW_MIRRORING_ENABLE is off
    if (i_sysAttrs.iv_hwMirrorEnabled == fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
    {
        FAPI_INF("setupMirrorGroup: No mirror group ATTR_MRW_HW_MIRRORING_ENABLE = %d",
                 i_sysAttrs.iv_hwMirrorEnabled);
        goto fapi_try_exit;
    }

    // Loop thru groups to see if mirror group is possible
    for (uint8_t l_group = 0; l_group < io_groupData.iv_numGroups; l_group++)
    {
        // Set mirror on if both sub-channels enabled for each MCC in this group
        for (uint8_t ii = 0; ii < io_groupData.iv_data[l_group][MCC_IN_GROUP]; ii++)
        {
            uint8_t l_mcc = io_groupData.iv_data[l_group][MEMBER_IDX(ii)];

            if (i_memInfo.iv_SubChannelsEnabled[l_mcc] == OMISubChannelConfig::BOTH)
            {
                io_groupData.iv_mirrorOn[l_group] = 1;
            }
        }

        FAPI_INF("setupMirrorGroup: Group %d, MCCInGroup %d, Mirror = %d",
                 l_group, io_groupData.iv_data[l_group][MCC_IN_GROUP],
                 io_groupData.iv_mirrorOn[l_group]);

    } // Group loop

fapi_try_exit:
    FAPI_DBG("Exiting setupMirrorGroup");
    return;
}

///
/// @brief Calculate base and alt-base addresses
///
/// @param[in] i_target     Reference to processor chip target
/// @param[in] i_sysAttrs   System attribute setting
/// @param[in] i_procAttrs  Processor Chip Attributes
/// @param[in] i_cfgMirror  Map mirrored memory
/// @param[io] io_groupData Group Data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode grouping_calcRegions(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const EffGroupingSysAttrs& i_sysAttrs,
    const EffGroupingProcAttrs& i_procAttrs,
    const bool i_cfgMirror,
    EffGroupingData& io_groupData)
{
    char displayBuf[MAX_DISPLAY_BUFFER_SIZE];
    FAPI_DBG("Entering - i_cnfgMirror %d", i_cfgMirror);

    // index for region which is used for mapping current group
    // group size should never exceed the size of a particular
    // region (enforced by restricting group size at formation time)
    // if current group will stack on top of the prior group & not overflow
    // the region, stack it, else place in next region
    // In p10, there's only 1 index for mirrored memory
    uint8_t l_cur_nm_region_idx = 0;
    uint8_t l_max_nm_region_idx = 0;
    uint64_t l_nm_region_size_left = i_sysAttrs.iv_maxInterleaveGroupSize;
    uint64_t l_m_region_size_left = i_sysAttrs.iv_maxInterleaveGroupSize / 2;
    uint64_t l_cur_m_base_addr = 0;

    if (i_procAttrs.iv_memBaseAddr.size())
    {
        l_max_nm_region_idx = i_procAttrs.iv_memBaseAddr.size();
    }

    FAPI_DBG("Begin: l_nm_region_size_left = %u GB, l_m_region_size_left =  %u GB",
             l_nm_region_size_left, l_m_region_size_left);


    // If mirror is on for this system, initialize mirror group data by
    // copying group members from non-mirror to mirror groups
    if (i_cfgMirror)
    {
        l_cur_m_base_addr = i_procAttrs.iv_mirrorBaseAddr;
        getSizeString(l_cur_m_base_addr, displayBuf);
        FAPI_DBG("l_cur_m_base_addr %s", displayBuf);

        for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
        {
            if (io_groupData.iv_mirrorOn[pos])
            {
                uint8_t l_mirrorOffset = pos + MIRR_OFFSET;
                // Mirrored size is half the group size
                io_groupData.iv_data[l_mirrorOffset][GROUP_SIZE] =
                    io_groupData.iv_data[pos][GROUP_SIZE] / 2;
                io_groupData.iv_data[l_mirrorOffset][MCC_SIZE] =
                    io_groupData.iv_data[pos][MCC_SIZE];
                io_groupData.iv_data[l_mirrorOffset][MCC_IN_GROUP] =
                    io_groupData.iv_data[pos][MCC_IN_GROUP];

                // Copy MCC members from non-mirrored to mirrored group
                for (uint8_t ii = 0; ii < io_groupData.iv_data[pos][MCC_IN_GROUP]; ii++)
                {
                    io_groupData.iv_data[l_mirrorOffset][MEMBER_IDX(ii)] =
                        io_groupData.iv_data[pos][MEMBER_IDX(ii)];
                }

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
    }

    // Assign non-mirroring base address for each group
    for (uint8_t pos = 0; pos < io_groupData.iv_numGroups; pos++)
    {
        // Set flag to map mirror memory
        bool l_map_mirror = i_cfgMirror && io_groupData.iv_mirrorOn[pos];
        FAPI_DBG("Group %d, l_map_mirror: %d", pos, l_map_mirror);

        // first group goes in first region
        if (pos == 0)
        {
            // Group size must fit in non-mirror/mirror regions
            FAPI_ASSERT((l_cur_nm_region_idx < l_max_nm_region_idx) &&
                        (l_nm_region_size_left >=
                         io_groupData.iv_data[pos][GROUP_SIZE]),
                        fapi2::MSS_EFF_GROUPING_NM_REGION_MAP_ERROR()
                        .set_PROC_CHIP(i_target)
                        .set_MEM_BASE_ADDRS(i_procAttrs.iv_memBaseAddr)
                        .set_CURR_GROUP_IDX(pos)
                        .set_CURR_GROUP_SIZE(io_groupData.iv_data[pos][GROUP_SIZE])
                        .set_CURR_REGION_IDX(l_cur_nm_region_idx)
                        .set_CURR_REGION_SIZE_LEFT(l_nm_region_size_left)
                        .set_MAX_REGION_IDX(l_max_nm_region_idx)
                        .set_MAX_REGION_SIZE(i_sysAttrs.iv_maxInterleaveGroupSize),
                        "Unable to map non-mirrored group!");

            FAPI_ASSERT(!l_map_mirror ||
                        ((l_m_region_size_left >=
                          io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE])),
                        fapi2::MSS_EFF_GROUPING_M_REGION_MAP_ERROR()
                        .set_PROC_CHIP(i_target)
                        .set_MIRROR_BASE_ADDRS(i_procAttrs.iv_memBaseAddr)
                        .set_CURR_GROUP_IDX(pos)
                        .set_CURR_GROUP_SIZE(io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE])
                        .set_CURR_REGION_SIZE_LEFT(l_m_region_size_left)
                        .set_MAX_REGION_SIZE(i_sysAttrs.iv_maxInterleaveGroupSize / 2),
                        "Unable to map mirrored group!");

            // assign non mirrored base address
            io_groupData.iv_data[pos][BASE_ADDR] =
                (i_procAttrs.iv_memBaseAddr[l_cur_nm_region_idx] >> 30);

            getSizeString(i_procAttrs.iv_memBaseAddr[l_cur_nm_region_idx], displayBuf);
            FAPI_DBG("Assigning non-mirrored base address (=%s) for pos: %d in first group",
                     displayBuf, pos);

            // assign mirrored base address
            if (l_map_mirror)
            {
                getSizeString(l_cur_m_base_addr, displayBuf);
                FAPI_DBG("Assigning mirrored base address (=%s) for first mirror group (pos=%d)",
                         displayBuf, pos + MIRR_OFFSET);
                io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] = l_cur_m_base_addr >> 30;
            }
        }

        // Map next group
        else
        {
            // Check to see if this group can be mapped in the same nm region index
            if (l_nm_region_size_left >= io_groupData.iv_data[pos][GROUP_SIZE])
            {
                // stack on top of last region mapped
                io_groupData.iv_data[pos][BASE_ADDR] =
                    io_groupData.iv_data[pos - 1][BASE_ADDR] +
                    io_groupData.iv_data[pos - 1][GROUP_SIZE];

                if (l_map_mirror)
                {
                    // should have space to map mirrored group if non-mirrored
                    // group fits, assert
                    FAPI_ASSERT((l_m_region_size_left >=
                                 io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE]),
                                fapi2::MSS_EFF_GROUPING_M_REGION_MAP_ERROR()
                                .set_PROC_CHIP(i_target)
                                .set_MIRROR_BASE_ADDRS(i_procAttrs.iv_memBaseAddr)
                                .set_CURR_GROUP_IDX(pos)
                                .set_CURR_GROUP_SIZE(io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE])
                                .set_CURR_REGION_SIZE_LEFT(l_m_region_size_left)
                                .set_MAX_REGION_SIZE(i_sysAttrs.iv_maxInterleaveGroupSize / 2),
                                "Unable to map mirrored group!");

                    io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] = l_cur_m_base_addr >> 30;
                    getSizeString(l_cur_m_base_addr, displayBuf);
                    FAPI_DBG("Assigning mirrored base address (=%s) for pos: %d in curr region",
                             displayBuf, pos + MIRR_OFFSET);
                }
            }
            // Must map to the next nm region index
            else
            {
                // move to next non-mirrored region
                l_cur_nm_region_idx++;

                // reset available size variables
                l_nm_region_size_left = i_sysAttrs.iv_maxInterleaveGroupSize;

                // assert that mappings are valid
                FAPI_ASSERT((l_cur_nm_region_idx < l_max_nm_region_idx) &&
                            (l_nm_region_size_left >=
                             io_groupData.iv_data[pos][GROUP_SIZE]),
                            fapi2::MSS_EFF_GROUPING_NM_REGION_MAP_ERROR()
                            .set_PROC_CHIP(i_target)
                            .set_MEM_BASE_ADDRS(i_procAttrs.iv_memBaseAddr)
                            .set_CURR_GROUP_IDX(pos)
                            .set_CURR_GROUP_SIZE(io_groupData.iv_data[pos][GROUP_SIZE])
                            .set_CURR_REGION_IDX(l_cur_nm_region_idx)
                            .set_CURR_REGION_SIZE_LEFT(l_nm_region_size_left)
                            .set_MAX_REGION_IDX(l_max_nm_region_idx)
                            .set_MAX_REGION_SIZE(i_sysAttrs.iv_maxInterleaveGroupSize),
                            "Unable to map non-mirrored group!");

                FAPI_ASSERT(!l_map_mirror ||
                            ((l_m_region_size_left >=
                              io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE])),
                            fapi2::MSS_EFF_GROUPING_M_REGION_MAP_ERROR()
                            .set_PROC_CHIP(i_target)
                            .set_MIRROR_BASE_ADDRS(i_procAttrs.iv_memBaseAddr)
                            .set_CURR_GROUP_IDX(pos)
                            .set_CURR_GROUP_SIZE(io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE])
                            .set_CURR_REGION_SIZE_LEFT(l_m_region_size_left)
                            .set_MAX_REGION_SIZE(i_sysAttrs.iv_maxInterleaveGroupSize / 2),
                            "Unable to map mirrored group!");

                // assign non mirrored base address
                io_groupData.iv_data[pos][BASE_ADDR] =
                    (i_procAttrs.iv_memBaseAddr[l_cur_nm_region_idx] >> 30);

                // assign mirrored base address
                if (l_map_mirror)
                {
                    io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] = l_cur_m_base_addr >> 30;
                    getSizeString(l_cur_m_base_addr, displayBuf);
                    FAPI_DBG("Assigning mirrored base address (=%s) for pos: %d in new region",
                             displayBuf, pos + MIRR_OFFSET);
                }
            }
        }

        // update remaining size in region
        l_nm_region_size_left -= io_groupData.iv_data[pos][GROUP_SIZE];
        l_m_region_size_left -= (io_groupData.iv_data[pos][GROUP_SIZE] / 2);
        FAPI_DBG("l_nm_region_size_left: %u GB, l_m_region_size_left: %u GB",
                 l_nm_region_size_left, l_m_region_size_left);

        // increment mirrored address (regardless of whether mapped
        // for this group)
        l_cur_m_base_addr += (((uint64_t) io_groupData.iv_data[pos][GROUP_SIZE] << 30) / 2);

        getSizeString(l_cur_m_base_addr, displayBuf);
        FAPI_DBG("l_cur_m_base_addr: %s", displayBuf);

        // set alt region information directly based on base region mapping
        for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
        {
            if (io_groupData.iv_data[pos][ALT_VALID(ii)])
            {
                io_groupData.iv_data[pos][ALT_BASE_ADDR(ii)] =
                    (
                        io_groupData.iv_data[pos][BASE_ADDR] +
                        io_groupData.iv_data[pos][GROUP_SIZE] -
                        io_groupData.iv_data[pos][ALT_SIZE(ii)]
                    )
                    >> 2; //BAR must be adjusted for register alignment
                FAPI_DBG("Base: %lX Size: %lX Alt Size: %lX Calc: %lx", io_groupData.iv_data[pos][BASE_ADDR],
                         io_groupData.iv_data[pos][GROUP_SIZE], io_groupData.iv_data[pos][ALT_SIZE(ii)],
                         io_groupData.iv_data[pos][ALT_BASE_ADDR(ii)]);

                if (l_map_mirror)
                {
                    FAPI_DBG("io_groupData.iv_data[%d][BASE_ADDR]: 0x%016llx (%u GB)",
                             pos + MIRR_OFFSET,
                             io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR],
                             io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR]);
                    FAPI_DBG("io_groupData.iv_data[%d][GROUP_SIZE]: 0x%016llx (%u GB)",
                             pos + MIRR_OFFSET,
                             io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE],
                             io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE]);
                    FAPI_DBG("io_groupData.iv_data[%d][ALT_SIZE(ii)]: 0x%016llx (%u GB)",
                             pos + MIRR_OFFSET,
                             io_groupData.iv_data[pos + MIRR_OFFSET][ALT_SIZE(ii)],
                             io_groupData.iv_data[pos + MIRR_OFFSET][ALT_SIZE(ii)]);
                    io_groupData.iv_data[pos + MIRR_OFFSET][ALT_BASE_ADDR(ii)] =
                        (
                            io_groupData.iv_data[pos + MIRR_OFFSET][BASE_ADDR] +
                            io_groupData.iv_data[pos + MIRR_OFFSET][GROUP_SIZE] -
                            io_groupData.iv_data[pos + MIRR_OFFSET][ALT_SIZE(ii)]
                        )
                        >> 2;
                    io_groupData.iv_data[pos + MIRR_OFFSET][ALT_VALID(ii)] = 1;
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
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

    fapi2::buffer<uint8_t> MC_IN_GP;
    uint8_t l_mcc_in_group[NUM_MCC_PER_PROC];
    memset(l_mcc_in_group, 0, sizeof(l_mcc_in_group));

    for (uint8_t ii = 0; ii < i_groupData.iv_numGroups; ii++)
    {
        MC_IN_GP = 0;
        uint8_t l_count = i_groupData.iv_data[ii][MCC_IN_GROUP];

        for (uint8_t jj = 0; jj < l_count; jj++)
        {
            MC_IN_GP.setBit( i_groupData.iv_data[ii][MEMBER_IDX(jj)] );
        }

        l_mcc_in_group[ii] = MC_IN_GP;
    }

    FAPI_INF("grouping_setATTR_MSS_MEM_MC_IN_GROUP: ");

    for (uint8_t ii = 0; ii < NUM_MCC_PER_PROC; ii++)
    {
        FAPI_INF("  ATTR_MSS_MEM_MC_IN_GROUP[%d]: 0x%02x",
                 ii, l_mcc_in_group[ii]);
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_MC_IN_GROUP, i_target, l_mcc_in_group),
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
/// @return (void)
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
        FAPI_INF("    MCC size %d GB", i_groupData.iv_data[ii][MCC_SIZE]);
        FAPI_INF("    Num of MCC %d", i_groupData.iv_data[ii][MCC_IN_GROUP]);
        FAPI_INF("    Group size  %d GB", i_groupData.iv_data[ii][GROUP_SIZE]);
        FAPI_INF("    Base addr %u GB", i_groupData.iv_data[ii][BASE_ADDR]);

        for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
        {
            FAPI_INF("    ALT-BAR(%d) valid %d", jj, i_groupData.iv_data[ii][ALT_VALID(jj)]);
            FAPI_INF("    ALT-BAR(%d) size %d", jj, i_groupData.iv_data[ii][ALT_SIZE(jj)]);
            FAPI_INF("    ALT-BAR(%d) base addr %u GB", jj, i_groupData.iv_data[ii][ALT_BASE_ADDR(jj)]);
        }

        // Display MC in groups
        for (uint8_t jj = 0; jj < i_groupData.iv_data[ii][MCC_IN_GROUP]; jj++)
        {
            FAPI_INF("    Contains MC %d",
                     i_groupData.iv_data[ii][MEMBER_IDX(jj)]);
        }
    }

    // Display mirror groups
    if (i_sysAttrs.iv_hwMirrorEnabled != fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
    {
        for (uint8_t ii = 0; ii < i_groupData.iv_numGroups; ii++)
        {
            uint8_t l_mirrorOffset = ii + MIRR_OFFSET;

            // Only display valid mirrored group
            if (i_groupData.iv_data[l_mirrorOffset][GROUP_SIZE] > 0)
            {
                FAPI_INF("MIRROR - Group %u: ", l_mirrorOffset);
                FAPI_INF("    MCC size %d GB", i_groupData.iv_data[l_mirrorOffset][MCC_SIZE]);
                FAPI_INF("    Num of MCC %d", i_groupData.iv_data[l_mirrorOffset][MCC_IN_GROUP]);
                FAPI_INF("    Group size  %d GB", i_groupData.iv_data[l_mirrorOffset][GROUP_SIZE]);
                FAPI_INF("    Base addr %u GB", i_groupData.iv_data[l_mirrorOffset][BASE_ADDR]);

                for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
                {
                    FAPI_INF("    ALT-BAR(%d) valid %d", jj, i_groupData.iv_data[l_mirrorOffset][ALT_VALID(jj)]);
                    FAPI_INF("    ALT-BAR(%d) size %d", jj, i_groupData.iv_data[l_mirrorOffset][ALT_SIZE(jj)]);
                    FAPI_INF("    ALT-BAR(%d) base addr %u GB", jj, i_groupData.iv_data[l_mirrorOffset][ALT_BASE_ADDR(jj)]);
                }

                // Display MCC in groups
                for (uint8_t jj = 0; jj < i_groupData.iv_data[l_mirrorOffset][MCC_IN_GROUP]; jj++)
                {
                    FAPI_INF("    Contains MCC %d",
                             i_groupData.iv_data[l_mirrorOffset][MEMBER_IDX(jj)]);
                }
            }
        }
    }

    FAPI_DBG("Exiting");
    return;
}

///
/// @brief Display the Memory controller BAR data resulted from the BAR
///        data calculations.
///
/// @param[in]  i_nonMirror    Type of group data:
///                              true = non-mirror; false = mirrored
/// @param[in]  i_mccPos       MCC position
/// @param[in]  i_mccInfo      Group data of an MCC
///
/// @return void
///
void displayMCCInfoData(const bool i_nonMirror,
                        const uint8_t i_mccPos,
                        const mccGroupInfo_t i_mccInfo)
{
    if (i_mccInfo.numMCCInGroup > 0)
    {
        FAPI_INF("MCC%d: %s:", i_mccPos, i_nonMirror ? "NON-MIRROR" : "MIRROR");
        FAPI_INF("       myGroup %u", i_mccInfo.myGroup);
        FAPI_INF("       numMCCInGroup %u", i_mccInfo.numMCCInGroup);
        FAPI_INF("       groupSize %u", i_mccInfo.groupSize);
        FAPI_INF("       groupBaseAddr 0x%.16llX", i_mccInfo.groupBaseAddr);
        FAPI_INF("       channelId %u", i_mccInfo.channelId);

        for (uint8_t jj = 0; jj < NUM_OF_ALT_MEM_REGIONS; jj++)
        {
            FAPI_INF("        altMemValid[%u] %u", jj, i_mccInfo.altMemValid[jj]);
            FAPI_INF("        altMemSize[%u]  %u", jj, i_mccInfo.altMemSize[jj]);
            FAPI_INF("        altBaseAddr[%u] 0x%.16llX", jj, i_mccInfo.altBaseAddr[jj]);
        }
    }

    return;
}

///
/// @brief Load the mccGroupInfo_t data for the input MCC based on
///        position, input group data, and mirror/non-mirror settings.
///
/// @param[in]  i_nonMirror    Type of group data:
///                              true = non-mirror; false = mirrored
/// @param[in]  i_mccPos       MCC position
/// @param[in]  i_groupData    Array of Group data info
/// @param[out] o_mccInfo      Output mccGroupInfo_t
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
void getMCCData(const bool i_nonMirror,
                const uint8_t i_mccPos,
                const uint32_t i_groupDataArray[DATA_GROUPS][DATA_ELEMENTS],
                mccGroupInfo_t& o_mccInfo)
{
    FAPI_DBG("Entering");

    // Setup Start and End group indexes
    // Non-mirrored groups: 0->7
    // Mirrored groups: 8->15
    uint8_t l_startGroup = 0;
    uint8_t l_endGroup =  (DATA_GROUPS / 2);

    if (i_nonMirror == false)
    {
        l_startGroup = MIRR_OFFSET;
        l_endGroup = (MIRR_OFFSET + NUM_MIRROR_REGIONS);
    }

    // Loop thru all groups in array
    for (uint8_t l_group = l_startGroup; l_group < l_endGroup; l_group++)
    {
        // Skip empty groups
        if (i_groupDataArray[l_group][GROUP_SIZE] == 0)
        {
            continue;
        }

        // Look for this MCC in the group
        for (uint8_t l_memberIdx = 0;
             l_memberIdx < i_groupDataArray[l_group][MCC_IN_GROUP]; l_memberIdx++)
        {
            // If the MCC_ID is this MCC
            uint8_t l_mccPos = i_groupDataArray[l_group][MEMBER_IDX(0) + l_memberIdx];

            if (l_mccPos == i_mccPos)
            {
                // Set the MCC group info for this MCC
                o_mccInfo.myGroup = l_group;
                o_mccInfo.numMCCInGroup = i_groupDataArray[l_group][MCC_IN_GROUP];
                o_mccInfo.groupSize = i_groupDataArray[l_group][GROUP_SIZE];
                o_mccInfo.groupBaseAddr = i_groupDataArray[l_group][BASE_ADDR];
                o_mccInfo.channelId = l_memberIdx;

                // ALT memory regions
                for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
                {
                    if (i_groupDataArray[l_group][ALT_VALID(ii)])
                    {
                        o_mccInfo.altMemValid[ii] = 1;
                        o_mccInfo.altMemSize[ii] = i_groupDataArray[l_group][ALT_SIZE(ii)];
                        o_mccInfo.altBaseAddr[ii] = i_groupDataArray[l_group][ALT_BASE_ADDR(ii)];
                    }
                }

                // SMF memory regions
                if (i_groupDataArray[l_group][SMF_VALID])
                {
                    o_mccInfo.smfMemValid = 1;
                    o_mccInfo.smfMemSize = i_groupDataArray[l_group][SMF_SIZE];
                    o_mccInfo.smfBaseAddr = i_groupDataArray[l_group][SMF_BASE_ADDR];
                }

                // Break out
                break;
            }

        } // MCC loop

        // Found a group this MCC belongs to, break out
        if (o_mccInfo.numMCCInGroup > 0)
        {
            break;
        }

    } // Group loop

    // Display MCC info data
    displayMCCInfoData(i_nonMirror, i_mccPos, o_mccInfo);

    FAPI_DBG("Exit");
    return;
}

///
/// @brief Look up table to determine the MCFGP/MCFGPM group size
///        encoded value (bits 13:23).
///
/// @param[in]   i_mccTarget    MCC target
/// @param[in]   i_groupSize    Group size (in GB)
/// @param[out]  o_value        Encoded value
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getGroupSizeEncodedValue(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_mccTarget,
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
        uint8_t l_mccPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_mccTarget, l_mccPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        // Assert if can't find Group size in the table
        FAPI_ASSERT( false,
                     fapi2::MSS_EFF_GROUPING_INVALID_GROUP_SIZE()
                     .set_MC_TARGET(i_mccTarget)
                     .set_MC_POS(l_mccPos)
                     .set_GROUP_SIZE(i_groupSize),
                     "Error: Can't locate Group size value in GROUP_SIZE_TABLE. "
                     "MC pos: %d, GroupSize %u GB.", l_mccPos, i_groupSize );
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Calculate the BAR data for each MCC based on group info
///
/// @param[in]  i_mcTarget     MC target (MCC/MI)
/// @param[in]  i_mccInfo      The MCC group info
/// @param[in]  o_mcBarData    MC BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getNonMirrorBarIdSize(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_mccTarget,
    const mccGroupInfo_t& i_mccInfo,
    mcBarData_t& o_mcBarData)
{
    // MCFGP Channel_0 Group member ID (bits 5:7)
    o_mcBarData.MCFGP_chan0_group_member_id = i_mccInfo.channelId;

    // If MCFGP is valid, set other fields
    if (o_mcBarData.MCFGP_valid == true)
    {
        // MCFGP Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_mccTarget, i_mccInfo.groupSize,
                                          o_mcBarData.MCFGP_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        o_mcBarData.MCFGP_groupBaseAddr = i_mccInfo.groupBaseAddr;
    }

    // If MCFGPM is valid, set other fields
    if (o_mcBarData.MCFGPM_valid == true)
    {
        // MCFGPM Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_mccTarget, i_mccInfo.groupSize,
                                          o_mcBarData.MCFGPM_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        o_mcBarData.MCFGPM_groupBaseAddr = i_mccInfo.groupBaseAddr;
    }

    // ----------------------------------------------------
    // Determine data for MCFGPA and MCFGPMA registers
    // ----------------------------------------------------

    // Alternate Memory MCFGPA
    for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
    {
        if ( i_mccInfo.altMemValid[ii] )
        {
            o_mcBarData.MCFGPA_HOLE_valid[ii] = 1;
            o_mcBarData.MCFGPA_HOLE_LOWER_addr[ii] = i_mccInfo.altBaseAddr[ii];
            o_mcBarData.MCFGPA_HOLE_UPPER_addr[ii] =
                i_mccInfo.altBaseAddr[ii] + i_mccInfo.altMemSize[ii];
        }
        else
        {
            o_mcBarData.MCFGPA_HOLE_valid[ii] = 0;
            o_mcBarData.MCFGPA_HOLE_LOWER_addr[ii] = 0;
            o_mcBarData.MCFGPA_HOLE_UPPER_addr[ii] = 0;
        }

    }

    // SMF Section of MCFGPA and MCFGPMA
    if ( i_mccInfo.smfMemValid )
    {
        o_mcBarData.MCFGPA_SMF_valid = 1;
        o_mcBarData.MCFGPA_SMF_LOWER_addr = i_mccInfo.smfBaseAddr;
        o_mcBarData.MCFGPA_SMF_UPPER_addr = i_mccInfo.smfBaseAddr + i_mccInfo.smfMemSize;
    }
    else
    {
        o_mcBarData.MCFGPA_SMF_valid = 0;
        o_mcBarData.MCFGPA_SMF_LOWER_addr = 0;
        o_mcBarData.MCFGPA_SMF_UPPER_addr = 0;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Calculate the BAR data for each MCC based on group info
///
/// @param[in]  i_mccTarget    MC target (MCC)
/// @param[in]  i_mccInfo      The MCC group info
/// @param[in]  o_mcBarData    MC BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getNonMirrorBarData(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_mccTarget,
    const mccGroupInfo_t& i_mccInfo,
    mcBarData_t& o_mcBarData)
{
    FAPI_DBG("Entering");

    // Initialize
    o_mcBarData.MCFGP_chan_per_group = NO_CHANNEL_PER_GROUP;
    o_mcBarData.MCFGP_valid = false;
    o_mcBarData.MCFGPM_valid = false;

    // MCFGP valid (MCFGP bit 0)
    if ( i_mccInfo.numMCCInGroup > 0)
    {
        o_mcBarData.MCFGP_valid = true;
        o_mcBarData.MCFGPM_valid = false;

        // ----------------------------------------------------
        // Determine data for MCFGP and MCFGPM registers
        // ----------------------------------------------------
        if (i_mccInfo.numMCCInGroup == 8)
        {
            o_mcBarData.MCFGP_chan_per_group = 0;
        }
        else if (i_mccInfo.numMCCInGroup == 1 ||
                 i_mccInfo.numMCCInGroup == 2 ||
                 i_mccInfo.numMCCInGroup == 3 ||
                 i_mccInfo.numMCCInGroup == 4 ||
                 i_mccInfo.numMCCInGroup == 6 )
        {
            o_mcBarData.MCFGP_chan_per_group = i_mccInfo.numMCCInGroup;
        }

        // Assert if num of MCC in groups are invalid
        FAPI_ASSERT(o_mcBarData.MCFGP_chan_per_group != NO_CHANNEL_PER_GROUP,
                    fapi2::MSS_EFF_GROUPING_INVALID_MCC_CONFIG()
                    .set_MC_TARGET(i_mccTarget)
                    .set_MCC0_NUM_MCC_IN_GROUP(i_mccInfo.numMCCInGroup)
                    .set_MCC0_GROUP(i_mccInfo.myGroup)
                    .set_MCC1_MCC_NUM_IN_GROUP(0)
                    .set_MCC1_GROUP(0),
                    "Error: Invalid number of MCC per group"
                    "group %u, MCC in group %u",
                    i_mccInfo.myGroup, i_mccInfo.numMCCInGroup);
    }

    FAPI_TRY(getNonMirrorBarIdSize(i_mccTarget, i_mccInfo, o_mcBarData));

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Calculate the mirror BAR data for each MCC based on group info
///
/// @param[in]  i_mcTarget     MCC target
/// @param[in]  i_mccInfo      The MCC group info
/// @param[in]  io_mcBarData   MC BAR data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getMirrorBarData(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_mccTarget,
    const mccGroupInfo_t& i_mccInfo,
    mcBarData_t& io_mcBarData)
{
    FAPI_DBG("Entering");

    // ---------------------------------------------------
    // Build MC register values for mirror groups
    // ---------------------------------------------------

    // Set MCFGPM_VALID
    if (i_mccInfo.groupSize > 0)
    {
        io_mcBarData.MCFGPM_valid = true;

        // ----------------------------------------------------
        // Determine data for MCFGPM register
        // ----------------------------------------------------

        // MCFGPM Group size
        FAPI_TRY(getGroupSizeEncodedValue(i_mccTarget, i_mccInfo.groupSize,
                                          io_mcBarData.MCFGPM_group_size),
                 "getGroupSizeEncodedValue() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Group base address
        io_mcBarData.MCFGPM_groupBaseAddr = i_mccInfo.groupBaseAddr;

        // ----------------------------------------------------
        // Determine data for MCFGPMA registers
        // ----------------------------------------------------
        // Alternate Memory MCFGPMA
        for (uint8_t ii = 0; ii < NUM_OF_ALT_MEM_REGIONS; ii++)
        {
            if ( i_mccInfo.altMemValid[ii] )
            {
                io_mcBarData.MCFGPMA_HOLE_valid[ii] = 1;
                io_mcBarData.MCFGPMA_HOLE_LOWER_addr[ii] =
                    i_mccInfo.altBaseAddr[ii];
                io_mcBarData.MCFGPMA_HOLE_UPPER_addr[ii] =
                    i_mccInfo.altBaseAddr[ii] + i_mccInfo.altMemSize[ii];
            }
            else
            {
                io_mcBarData.MCFGPMA_HOLE_valid[ii] = 0;
                io_mcBarData.MCFGPMA_HOLE_LOWER_addr[ii] = 0;
                io_mcBarData.MCFGPMA_HOLE_UPPER_addr[ii] = 0;
            }

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
/// @param[in]  i_mcPosition    MC (MI) position
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
    FAPI_INF("        MCFGPA_SMF_valid %u", i_mcBarData.MCFGPA_SMF_valid);
    FAPI_INF("        MCFGPA_SMF_LOWER_addr 0x%.16llX", i_mcBarData.MCFGPA_SMF_LOWER_addr);
    FAPI_INF("        MCFGPA_SMF_UPPER_addr 0x%.16llX", i_mcBarData.MCFGPA_SMF_UPPER_addr);
    FAPI_INF("        MCFGPMA_SMF_valid %u", i_mcBarData.MCFGPMA_SMF_valid);
    FAPI_INF("        MCFGPMA_SMF_LOWER_addr 0x%.16llX", i_mcBarData.MCFGPMA_SMF_LOWER_addr);
    FAPI_INF("        MCFGPMA_SMF_UPPER_addr 0x%.16llX", i_mcBarData.MCFGPMA_SMF_UPPER_addr);

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
/// @brief Build data to be programmed into Memory controller target.
/// The data will be saved into ATTR_MEMORY_BAR_REGS in order for
/// SBE to program into the memory controllers later.
///
/// Use template function to accomodate future design.
///
/// @param[in]  i_mcTargets    Vector of reference of MC targets
/// @param[in]  i_sysAttrs     System attribute settings
/// @param[in]  i_groupData    Array of Group data info
/// @param[out] o_mcDataPair   Output data pair MCC<->Data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

// Target = MCC
template<fapi2::TargetType T>
fapi2::ReturnCode buildMCBarData(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCC> >& i_mccTargets,
    const EffGroupingSysAttrs& i_sysAttrs,
    const uint32_t i_groupData[DATA_GROUPS][DATA_ELEMENTS],
    std::vector<std::pair<fapi2::Target<T>, mcBarData_t>>& o_mcBarDataPair)
{
    FAPI_DBG("Entering");
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];

    // Build the data per MC channel (MCC)
    for (auto l_mcc : i_mccTargets)
    {
        mcBarData_t l_mcBarData;
        mccGroupInfo_t l_mccGroupInfo;

        // Get this MCC unit position
        uint8_t l_unitPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mcc, l_unitPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        fapi2::toString(l_mcc, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Get group data of MCC target %s", l_targetStr);

        // -----------------------------------------------
        // Build MC register values for non-mirror groups
        // -----------------------------------------------
        // Get MCC data from non-mirrored groups (true = non-mirrored)
        getMCCData(true, l_unitPos, i_groupData, l_mccGroupInfo);

        // If this MCC is configured in a group, proceed with getting its BAR data
        if ( (l_mccGroupInfo.numMCCInGroup > 0) )
        {
            // ---- Build MCFGP/MCFGM data based on MCC group info ----
            FAPI_TRY(getNonMirrorBarData(l_mcc, l_mccGroupInfo, l_mcBarData),
                     "getNonMirrorBarData() returns error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ---------------------------------------------------------------
            // Set MC register values for mirror groups
            // ---------------------------------------------------------------
            if (i_sysAttrs.iv_hwMirrorEnabled != fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
            {
                FAPI_INF("ATTR_MRW_HW_MIRRORING_ENABLE is enabled: checking mirrored groups");
                mccGroupInfo_t l_mccGroupInfoMirrored;
                // Get MCC data from mirrored groups (false = mirrored)
                getMCCData(false, l_unitPos, i_groupData, l_mccGroupInfoMirrored);

                // ---- Build MCFGM data based on MCC group info ----
                FAPI_TRY(getMirrorBarData(l_mcc, l_mccGroupInfoMirrored, l_mcBarData),
                         "getMirrorBarData() returns error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }

            // Add to output pair
            o_mcBarDataPair.push_back(std::make_pair(l_mcc, l_mcBarData));

            // Display data (MC pos = MCC pos/2)
            displayMCBarData(l_unitPos / 2, l_mcBarData);
        }
        else
        {
            FAPI_INF("MCC pos %u is not configured in a memory group.", l_unitPos);
        }

    } // MC loop

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}


///
/// @brief Set subchannel enables in MCMODE2 register
///
/// @param[in]  i_mcBarDataPair  Target pair <MCC, mcBarData>
/// @param[in]  i_memInfo        Memory information
/// @param[out] o_memBarRegs     BAR register attribute data array
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setMCMODE2regData(
    const std::vector<std::pair<fapi2::Target<fapi2::TARGET_TYPE_MCC>, mcBarData_t>>& i_mcBarDataPair,
    const EffGroupingMemInfo& i_memInfo,
    fapi2::ATTR_MEMORY_BAR_REGS_Type o_memBarRegs)
{
    FAPI_DBG("Entering");

    using namespace scomt;
    using namespace scomt::mc;

    uint8_t l_miPos = 0;
    uint8_t l_mccPos = 0;
    fapi2::buffer<uint64_t> l_mcmode2[NUM_MC_PER_PROC];
    fapi2::buffer<uint64_t> l_mcmode2_mask = 0;

    l_mcmode2_mask.setBit<SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE>();
    l_mcmode2_mask.setBit<SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE>();
    l_mcmode2_mask.setBit<SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE>();
    l_mcmode2_mask.setBit<SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE>();

    for (auto l_pair : i_mcBarDataPair)
    {
        auto l_target = l_pair.first;

        fapi2::Target<fapi2::TARGET_TYPE_MI> l_mi_target = l_target.getParent<fapi2::TARGET_TYPE_MI>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mi_target, l_miPos),
                 "Error getting MI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_target, l_mccPos),
                 "Error getting MCC ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        PREP_SCOMFIR_MCMODE2(l_mi_target);

        if ((i_memInfo.iv_SubChannelsEnabled[l_mccPos] & OMISubChannelConfig::A) == OMISubChannelConfig::A)
        {
            if (l_mccPos % 2 == 0)
            {
                SET_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL0_ENABLE(l_mcmode2[l_miPos]);
            }
            else
            {
                SET_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL0_ENABLE(l_mcmode2[l_miPos]);
            }
        }

        if ((i_memInfo.iv_SubChannelsEnabled[l_mccPos] & OMISubChannelConfig::B) == OMISubChannelConfig::B)
        {
            if (l_mccPos % 2 == 0)
            {
                SET_SCOMFIR_MCMODE2_CHANNEL0_SUBCHANNEL1_ENABLE(l_mcmode2[l_miPos]);
            }
            else
            {
                SET_SCOMFIR_MCMODE2_CHANNEL1_SUBCHANNEL1_ENABLE(l_mcmode2[l_miPos]);
            }
        }
    }

    for (l_miPos = 0; l_miPos < NUM_MC_PER_PROC; l_miPos++)
    {
        o_memBarRegs[l_miPos][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCMODE2][BAR_REGS_DATA_IDX] = l_mcmode2[l_miPos];
        o_memBarRegs[l_miPos][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCMODE2][BAR_REGS_MASK_IDX] = l_mcmode2_mask;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Set MCFGP register data
///
/// @param[in]  i_target         Reference to MCC chiplet target
/// @param[in]  i_mccBarData     MCC Bar data
/// @param[out] o_memBarRegs     BAR register attribute data array
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setMCFGPregData(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
    const mcBarData_t& i_mccBarData,
    fapi2::ATTR_MEMORY_BAR_REGS_Type o_memBarRegs)
{
    FAPI_DBG("Entering");
    fapi2::buffer<uint64_t> l_mcfgp_scom_data(0);
    uint8_t l_miPos = 0;
    uint8_t l_mccPos = 0;
    uint8_t l_reg_idx = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP0;

    // Get MI target
    fapi2::Target<fapi2::TARGET_TYPE_MI> l_mi_target = i_target.getParent<fapi2::TARGET_TYPE_MI>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mi_target, l_miPos),
             "Error getting MI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_TRY(PREP_SCOMFIR_MCFGP0(l_mi_target));

    // MCFGP valid
    if (i_mccBarData.MCFGP_valid == true)
    {
        // Set valid bit
        SET_SCOMFIR_MCFGP0_0_VALID(l_mcfgp_scom_data);

        // Group size
        SET_SCOMFIR_MCFGP0_0_GROUP_SIZE(i_mccBarData.MCFGP_group_size, l_mcfgp_scom_data);

        // Group base address
        // MCFGP0 bits 1:24 are to be programmed with group base address bits 8:31.
        // The value of i_mccBarData.groupBaseAddr is already >> 30 bits
        // (in GB), so >> 2 more bits here for a total of 32 bits.
        SET_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(i_mccBarData.MCFGP_groupBaseAddr >> 2,
                                                l_mcfgp_scom_data);

        // Channel per group
        SET_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(i_mccBarData.MCFGP_chan_per_group,
                l_mcfgp_scom_data);

        // Channel 0 group id
        SET_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(i_mccBarData.MCFGP_chan0_group_member_id,
                l_mcfgp_scom_data);

        // R0 Configuration group size
        SET_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(mss::exp::ib::EXPLR_IB_BAR_SIZE,
                l_mcfgp_scom_data);

        // R0 MMIO group size
        SET_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(mss::exp::ib::EXPLR_IB_BAR_SIZE, l_mcfgp_scom_data);

        // Save to buffer
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mccPos),
                 "Error getting MCC ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);


        if (l_mccPos % 2)
        {
            l_reg_idx = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP1;
        }

        o_memBarRegs[l_miPos][l_reg_idx][BAR_REGS_DATA_IDX] = l_mcfgp_scom_data;
        o_memBarRegs[l_miPos][l_reg_idx][BAR_REGS_MASK_IDX] = 0xFFFFFFFFFFFFFFFFULL;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Set MCFGPM register data
///
/// @param[in]  i_target         Reference to MCC chiplet target
/// @param[in]  i_mccBarData     MCC Bar data
/// @param[out] o_memBarRegs     BAR register attribute data array
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setMCFGPMregData(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
    const mcBarData_t& i_mccBarData,
    fapi2::ATTR_MEMORY_BAR_REGS_Type o_memBarRegs)
{
    FAPI_DBG("Entering");
    fapi2::buffer<uint64_t> l_mcfgpm_scom_data(0);
    uint8_t l_mccPos = 0;
    uint8_t l_miPos = 0;
    uint8_t l_reg_idx = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM0;

    // Get MI target
    fapi2::Target<fapi2::TARGET_TYPE_MI> l_mi_target = i_target.getParent<fapi2::TARGET_TYPE_MI>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mi_target, l_miPos),
             "Error getting MI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_TRY(PREP_SCOMFIR_MCFGPM0(l_mi_target));

    // MCFGPM valid
    if (i_mccBarData.MCFGPM_valid == true)
    {
        // Set valid bit
        SET_SCOMFIR_MCFGPM0_VALID(l_mcfgpm_scom_data);

        // Group base address
        // MCFGPM0 bits 1:24 are to be programmed with group base address bits 8:31.
        // The value of i_mccBarData.groupBaseAddr is already >> 30 bits
        // (in GB), so >> 2 more bits here for a total of 32 bits.
        SET_SCOMFIR_MCFGPM0_GROUP_BASE_ADDRESS(i_mccBarData.MCFGPM_groupBaseAddr >> 2,
                                               l_mcfgpm_scom_data);

        // Group size
        SET_SCOMFIR_MCFGPM0_GROUP_SIZE(i_mccBarData.MCFGPM_group_size,
                                       l_mcfgpm_scom_data);

        // Save to buffer
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mccPos),
                 "Error getting MCC ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        if (l_mccPos % 2)
        {
            l_reg_idx = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM1;
        }

        o_memBarRegs[l_miPos][l_reg_idx][BAR_REGS_DATA_IDX] = l_mcfgpm_scom_data;
        o_memBarRegs[l_miPos][l_reg_idx][BAR_REGS_MASK_IDX] = 0xFFFFFFFFFFFFFFFFULL;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Set MCFGPA/MCFGPMA register data
///
/// @param[in]  i_target         Reference to MCC chiplet target
/// @param[in]  i_mccBarData     MCC Bar data
/// @param[in]  i_sysAttrs       System attribute settings
/// @param[out] o_memBarRegs     BAR register attribute data array
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode set_MCFGPA_MCFGPMA_regData(
    const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
    const mcBarData_t& i_mccBarData,
    const EffGroupingSysAttrs i_sysAttrs,
    fapi2::ATTR_MEMORY_BAR_REGS_Type o_memBarRegs)
{
    FAPI_DBG("Entering");
    fapi2::buffer<uint64_t> l_mcfgpa_scom_data(0);
    fapi2::buffer<uint64_t> l_mcfgpma_scom_data(0);
    uint8_t l_mccPos = 0;
    uint8_t l_miPos = 0;
    uint8_t l_reg_idx = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP0A;

    // Get MI target
    fapi2::Target<fapi2::TARGET_TYPE_MI> l_mi_target = i_target.getParent<fapi2::TARGET_TYPE_MI>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mi_target, l_miPos),
             "Error getting MI ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Hole0
    if (i_mccBarData.MCFGPA_HOLE_valid[0] == true)
    {
        // Need to setup both normal and mirrored registers for both
        // Normal and Flipped modes

        // MCFGPA HOLE0 valid
        FAPI_TRY(PREP_SCOMFIR_MCFGP0A(l_mi_target));
        SET_SCOMFIR_MCFGP0A_HOLE_VALID(l_mcfgpa_scom_data);
        // MCFGPM0A HOLE0 valid
        FAPI_TRY(PREP_SCOMFIR_MCFGPM0A(l_mi_target));
        SET_SCOMFIR_MCFGPM0A_HOLE_VALID(l_mcfgpma_scom_data);

        // Normal mode, but still set up mirrored equiv addressses
        if (i_sysAttrs.iv_mirrorPlacement ==
            fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)   // Normal
        {
            // Non-mirrored Hole0 lower addr
            FAPI_TRY(PREP_SCOMFIR_MCFGP0A(l_mi_target));
            SET_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS(i_mccBarData.MCFGPA_HOLE_LOWER_addr[0],
                                                   l_mcfgpa_scom_data);
            // Mirrored Hole0 lower addr (= non-mirrored lower addr << 1)
            FAPI_TRY(PREP_SCOMFIR_MCFGPM0A(l_mi_target));
            SET_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(i_mccBarData.MCFGPA_HOLE_LOWER_addr[0] << 1,
                                                    l_mcfgpma_scom_data);
        }
        // Flipped mode, but still set up non-mirrored equiv addressses
        else
        {
            // Mirrored Hole0 lower addr
            FAPI_TRY(PREP_SCOMFIR_MCFGPM0A(l_mi_target));
            SET_SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS(i_mccBarData.MCFGPMA_HOLE_LOWER_addr[0],
                                                    l_mcfgpma_scom_data);
            // Non-mirrored Hole0 lower addr (= mirrored lower addr >> 1)
            FAPI_TRY(PREP_SCOMFIR_MCFGP0A(l_mi_target));
            SET_SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS(i_mccBarData.MCFGPMA_HOLE_LOWER_addr[0] >> 1,
                                                   l_mcfgpa_scom_data);
        }
    }

    // SMF
    if (i_mccBarData.MCFGPA_SMF_valid == true)
    {
        // Need to setup both normal and mirrored registers for both
        // Normal and Flipped modes

        // MCFGPA SMF valid
        FAPI_TRY(PREP_SCOMFIR_MCFGP0A(l_mi_target));
        SET_SCOMFIR_MCFGP0A_SMF_VALID(l_mcfgpa_scom_data);
        // Non-mirrored Hole0 SMF extend end of range
        SET_SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE(l_mcfgpa_scom_data);

        // MCFGPMA SMF valid
        FAPI_TRY(PREP_SCOMFIR_MCFGPM0A(l_mi_target));
        SET_SCOMFIR_MCFGPM0A_SMF_VALID(l_mcfgpma_scom_data);
        // Mirrored Hole0 SMF extend end of range
        SET_SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE(l_mcfgpma_scom_data);

        // Normal mode, but still set up mirrored equiv addressses
        if (i_sysAttrs.iv_mirrorPlacement ==
            fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)   // Normal
        {
            // Non-mirrored Hole0 SMF lower addr
            FAPI_TRY(PREP_SCOMFIR_MCFGP0A(l_mi_target));
            SET_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS(i_mccBarData.MCFGPA_SMF_LOWER_addr,
                                                  l_mcfgpa_scom_data);
            // Non-mirrored Hole0 SMF upper addr
            SET_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS(i_mccBarData.MCFGPA_SMF_UPPER_addr,
                                                  l_mcfgpa_scom_data);

            // Mirrored SMF lower addr (= non-mirrored lower addr << 1)
            FAPI_TRY(PREP_SCOMFIR_MCFGPM0A(l_mi_target));
            SET_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(i_mccBarData.MCFGPA_SMF_LOWER_addr << 1,
                                                   l_mcfgpma_scom_data);
            // Mirrored SMF upper addr (= non-mirrored upper addr << 1)
            SET_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(i_mccBarData.MCFGPA_SMF_UPPER_addr << 1,
                                                   l_mcfgpma_scom_data);
        }

        // Flipped mode, but still set up non-mirrored equiv addressses
        else
        {
            // Mirrored SMF lower addr
            FAPI_TRY(PREP_SCOMFIR_MCFGPM0A(l_mi_target));
            SET_SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS(i_mccBarData.MCFGPMA_SMF_LOWER_addr,
                                                   l_mcfgpma_scom_data);
            // Mirrored SMF upper addr
            SET_SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS(i_mccBarData.MCFGPMA_SMF_UPPER_addr,
                                                   l_mcfgpma_scom_data);

            // SMF lower addr ( = mirrored smf lower addr >> 1)
            FAPI_TRY(PREP_SCOMFIR_MCFGP0A(l_mi_target));
            SET_SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS(i_mccBarData.MCFGPMA_SMF_LOWER_addr >> 1,
                                                  l_mcfgpa_scom_data);
            // SMF upper addr ( = mirrored smf upper addr >> 1)
            SET_SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS(i_mccBarData.MCFGPMA_SMF_LOWER_addr >> 1,
                                                  l_mcfgpa_scom_data);
        }

    }

    if ((i_mccBarData.MCFGPA_HOLE_valid[0] == true) ||
        (i_mccBarData.MCFGPA_SMF_valid == true))
    {
        // Save to buffer
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mccPos),
                 "Error getting MCC ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);


        if (l_mccPos % 2)
        {
            l_reg_idx = fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP1A;
        }

        o_memBarRegs[l_miPos][l_reg_idx][BAR_REGS_DATA_IDX] = l_mcfgpa_scom_data;
        o_memBarRegs[l_miPos][l_reg_idx][BAR_REGS_MASK_IDX] = 0xFFFFFFFFFFFFFFFFULL;
    }

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Set BAR registers data.
///
/// @param[in]  i_mccBarDataPair  Target pair <target, data>
/// @param[in]  i_sysAttrs        System attribute settings
/// @param[in]  i_memInfo         Memory configuration information
/// @param[out] o_memBarRegs      BAR register attribute data array
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setBarRegsData(
    const std::vector<std::pair<fapi2::Target<fapi2::TARGET_TYPE_MCC>, mcBarData_t>>& i_mccBarDataPair,
    const EffGroupingSysAttrs i_sysAttrs,
    const EffGroupingMemInfo& i_memInfo,
    fapi2::ATTR_MEMORY_BAR_REGS_Type o_memBarRegs)
{
    FAPI_DBG("Entering");

    // Clear array
    for (uint8_t ii = 0; ii < NUM_MC_PER_PROC; ii++)
    {
        for (uint8_t jj = 0; jj < BAR_REGS_ELEMENTS; jj++)
        {
            for (uint8_t kk = 0; kk < BAR_REGS_INDICES; kk++)
            {
                o_memBarRegs[ii][jj][kk] = 0;
            }
        }
    }

    // 0. ---- Get MCMODE2 reg data -----
    FAPI_TRY(setMCMODE2regData(i_mccBarDataPair, i_memInfo, o_memBarRegs),
             "setMCMODE2regData() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Remaining registers are per MCC chiplet
    for (auto l_pair : i_mccBarDataPair)
    {
        fapi2::Target<fapi2::TARGET_TYPE_MCC> l_target = l_pair.first;
        mcBarData_t l_data = l_pair.second;

        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_target, l_targetStr, sizeof(l_targetStr));
        FAPI_INF("Set MC register with data from MCC %s", l_targetStr);

        // 2. ---- Set MCFGP reg data -----
        FAPI_TRY(setMCFGPregData(l_target, l_data, o_memBarRegs),
                 "setMCFGPregData() returns an error. l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // 3. ---- Set MCFGPM reg data -----
        FAPI_TRY(setMCFGPMregData(l_target, l_data, o_memBarRegs),
                 "setMCFGPMregData() returns an error. l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // 4. ---- Set MCFGPA and MCFGPMA regs data -----
        FAPI_TRY(set_MCFGPA_MCFGPMA_regData(l_target, l_data, i_sysAttrs, o_memBarRegs),
                 "set_MCFGPA_MCFGPMA_regData() returns an error. l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

    } // Data pair loop

fapi_try_exit:
    FAPI_DBG("Exit");
    return fapi2::current_err;
}

///
/// @brief Display the values of the BAR registers (ATTR_MEMORY_BAR_REGS)
/// @param[in]  i_memBarRegs     BAR register attribute data array
/// @return void
///
void displayMemoryBarRegs(const fapi2::ATTR_MEMORY_BAR_REGS_Type i_memBarRegs)
{
    for (uint8_t ii = 0; ii < NUM_MC_PER_PROC; ii++)
    {
        FAPI_INF("MI %d:  MCFGP0   0x%.16llX 0x%.16llX", ii,
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP0][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP0][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGP1   0x%.16llX 0x%.16llX",
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP1][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP1][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGPM0  0x%.16llX 0x%.16llX",
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM0][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM0][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGPM1  0x%.16llX 0x%.16llX",
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM1][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM1][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGP0A  0x%.16llX 0x%.16llX ",   //Trailing space fixes hash problem
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP0A][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP0A][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGP1A  0x%.16llX 0x%.16llX",
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP1A][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGP1A][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGPM0A 0x%.16llX 0x%.16llX ",   //Trailing space fixes hash problem
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM0A][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM0A][BAR_REGS_MASK_IDX]);
        FAPI_INF("       MCFGPM1A 0x%.16llX 0x%.16llX",
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM1A][BAR_REGS_DATA_IDX],
                 i_memBarRegs[ii][fapi2::ENUM_ATTR_MEMORY_BAR_REGS_MCFGPM1A][BAR_REGS_MASK_IDX]);
    }

    return;
}

///
/// @brief p10_mss_eff_grouping procedure entry point
/// See doxygen in p10_mss_eff_grouping.H
///
fapi2::ReturnCode p10_mss_eff_grouping(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");

    // Create data structures for grouping operation
    EffGroupingSysAttrs l_sysAttrs;
    EffGroupingProcAttrs l_procAttrs;
    EffGroupingMemInfo l_memInfo;
    EffGroupingBaseSizeData l_baseSizeData;
    EffGroupingData l_groupData;
    bool l_mirrorIsOn = false;
    // BAR registers values for ATTR_MEMORY_BAR_REGS
    fapi2::ATTR_MEMORY_BAR_REGS_Type l_memoryBarRegs;
    // Used to indicate memory procedures are complete
    fapi2::ATTR_MSS_MEM_IPL_COMPLETE_Type l_memIplComplete = fapi2::ENUM_ATTR_MSS_MEM_IPL_COMPLETE_TRUE;

    // Get MCC chiplets
    auto l_mccChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCC>();
    // std_pair<MCC target, MCC data>
    std::vector<std::pair<fapi2::Target<fapi2::TARGET_TYPE_MCC>, mcBarData_t>> l_mccBarDataPair;

    uint8_t l_is_apollo = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_IS_APOLLO, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_apollo));

    // If this is Apollo we want to skip eff grouping
    if (l_is_apollo == fapi2::ENUM_ATTR_MSS_IS_APOLLO_TRUE)
    {
        FAPI_INF("Skipping p10_mss_eff_grouping on Apollo");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Only do memory grouping if there's at least 1 functional MCC.
    // Note: No functional MCC is a valid state, don't flag an error.
    FAPI_DBG("Number of MCCs found: %d", l_mccChiplets.size());

    if (l_mccChiplets.size() == 0)
    {
        FAPI_INF("p10_mss_eff_grouping: No functional MCC, no grouping performed.");

        // Set defaults for Memory Base and Size FAPI Attributes
        FAPI_TRY(l_baseSizeData.setBaseSizeAttr(i_target, l_sysAttrs, l_groupData),
                 "setBaseSizeAttr returns error l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_IPL_COMPLETE, i_target, l_memIplComplete),
                 "Error setting ATTR_MSS_MEM_IPL_COMPLETE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        goto fapi_try_exit;
    }

    // ----------------------------------------------
    // Get the attributes needed for memory grouping
    // ----------------------------------------------
    FAPI_INF("Getting memory grouping attributes");

    // Get system attributes
    FAPI_TRY(l_sysAttrs.getAttrs(),
             "l_sysAttrs.getAttrs() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get proc target attributes
    FAPI_TRY(l_procAttrs.getAttrs(i_target, l_sysAttrs),
             "l_procAttrs.getAttrs() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Validate attributes
    FAPI_TRY(grouping_validateAttributes(i_target, l_sysAttrs, l_procAttrs),
             "grouping_validateAttributes() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ------------------------------------------------------------------
    // Get the memory sizes behind MCC
    // ------------------------------------------------------------------
    FAPI_INF("Getting memory sizes behind MCCs.");
    FAPI_TRY(l_memInfo.getMemInfo(l_mccChiplets, l_sysAttrs, l_procAttrs),
             "p10_mss_eff_grouping: l_memInfo.get_memInfo() returns an error, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    // ----------------------------------------------------------------------
    // Attempt to group the MCC.
    // ----------------------------------------------------------------------
    FAPI_INF("Attempt memory grouping");
    FAPI_TRY(groupMCC(i_target, l_sysAttrs, l_memInfo, l_groupData),
             "groupMCC() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

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

    // Set mirror groups
    setupMirrorGroup(l_sysAttrs, l_memInfo, l_groupData);

    for (uint8_t l_group = 0; l_group < l_groupData.iv_numGroups; l_group++)
    {
        if (l_groupData.iv_mirrorOn[l_group] == 1)
        {
            l_mirrorIsOn = true;
            break;
        }
    }

    FAPI_INF("Mapping groups to regions (mirroring=%s)",
             (l_mirrorIsOn ? ("enabled") : ("disabled")));

    // Calculate base and alt-base addresses
    FAPI_TRY(grouping_calcRegions(i_target,
                                  l_sysAttrs,
                                  l_procAttrs,
                                  l_mirrorIsOn,
                                  l_groupData),
             "Error from grouping_calcRegions, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set the ATTR_MSS_MEM_MC_IN_GROUP attribute
    FAPI_TRY(grouping_setATTR_MSS_MEM_MC_IN_GROUP(i_target, l_groupData),
             "grouping_setATTR_MSS_MEM_MC_IN_GROUP() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Trace a summary of the Grouping Data
    grouping_traceData(l_sysAttrs, l_groupData);

    // Set memory base and size
    l_baseSizeData.setBaseSizeData(l_sysAttrs, l_groupData);

    // Build list of memories to be reserved (NHTM/OCC/SMF/CHTM/..)
    FAPI_TRY(l_baseSizeData.getRequestedBarList(l_sysAttrs, l_procAttrs),
             "getRequestedBarList() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set base address attributes for requested BARs
    for (auto l_barPair : l_baseSizeData.iv_requestedBarsList)
    {
        FAPI_TRY(l_baseSizeData.setBaseAddrAttributes(l_sysAttrs, l_barPair, l_groupData),
                 "setBaseAddrAttributes() returns error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }

    // Set Memory Base and Size FAPI Attributes
    FAPI_TRY(l_baseSizeData.setBaseSizeAttr(i_target, l_sysAttrs, l_groupData),
             "setBaseSizeAttr returns error l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Build MC BAR data
    FAPI_TRY(buildMCBarData(l_mccChiplets,
                            l_sysAttrs,
                            l_groupData.iv_data,
                            l_mccBarDataPair),
             "buildMCBarData() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set MC BAR registers data
    FAPI_TRY(setBarRegsData(l_mccBarDataPair, l_sysAttrs, l_memInfo, l_memoryBarRegs),
             "setBarRegsData() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Write MC BAR registers data to ATTR_MEMORY_BAR_REGS
    displayMemoryBarRegs(l_memoryBarRegs);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEMORY_BAR_REGS, i_target, l_memoryBarRegs),
             "Error setting ATTR_MEMORY_BAR_REGS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Write attribute signifying BAR calculations are complete
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_IPL_COMPLETE, i_target, l_memIplComplete),
             "Error setting ATTR_MSS_MEM_IPL_COMPLETE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}
