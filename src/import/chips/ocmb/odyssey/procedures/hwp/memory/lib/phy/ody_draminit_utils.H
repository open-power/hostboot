/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2025                        */
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
/// @file ody_draminit_utils.H
/// @brief Odyssey PHY draminit utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DRAMINIT_UTILS_H_
#define _ODY_DRAMINIT_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <lib/shared/ody_consts.H>
#include <lib/dimm/ody_rank.H>
#include <lib/phy/ody_snps_dram_train_msg_blk.H>
#include <lib/utils/ody_bad_bits.H>
#include <hwp_data_stream.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr0.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr2.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr3.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr4.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr5.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr6.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr8.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr10.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr11.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr12.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr13.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr14.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr15.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr111.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr32.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr32_per_dram.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr33.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr33_per_dram.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr34.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr35.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr37.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr38.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr39.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr50.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr51.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr52.H>
#include <generic/memory/lib/dimm/ddr5/ddr5_mr112.H>
#include <lib/workarounds/ody_phy_workarounds.H>

#ifdef __PPE__
    #include <ppe42_string.h>
#else
    #include <cstring>
#endif

namespace mss
{
namespace ody
{

///
/// @brief Check if we've selected to skip a step in a procedure using ATTR_ODY_DRAMINIT_STEP_ENABLE
/// @param[in] i_hwp_step enum from ATTR_ODY_DRAMINIT_STEP_ENABLE for the bit we're checking
/// @param[in] i_attr_val value of ATTR_ODY_DRAMINIT_STEP_ENABLE
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
inline bool skip_this_step(const uint8_t i_hwp_step,
                           const uint8_t i_attr_val)
{
    // Sanity check that i_hwp_step doesn't overflow (just return false - don't skip)
    if (i_hwp_step >= BITS_PER_BYTE)
    {
        return false;
    }

    const uint8_t l_step_mask = 0x80 >> i_hwp_step;

    return ((i_attr_val & l_step_mask) == 0x00);
}

namespace phy
{

///
/// @brief SPD to PHY nibble swizzle is implemented in the getBits indexing
/// @param[in] i_nibble_enables nibble enable attr value
/// @param[out] o_byte_disables DQ byte disable bits
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode nibble_enable_db_disable(const fapi2::buffer<uint32_t>& i_nibble_enables,
        uint8_t(&o_byte_disables)[10]);

#ifndef __PPE__
    constexpr uint8_t NUM_RCW = 0x80;
    constexpr uint8_t NUM_SUPPORTED_RCW = 20;
    constexpr uint8_t DIMM_NUMBER = 2;
    constexpr uint8_t DIMM0 = 0;
    constexpr uint8_t DIMM1 = 1;
#endif

#ifndef __PPE__
// Attribute getter FP type
typedef fapi2::ReturnCode (*rcw_attr_getter_ptr)(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        uint8_t& o_value);

// RCW getter methods
const static mss::pair<uint64_t, rcw_attr_getter_ptr>
get_rcw[NUM_SUPPORTED_RCW][mss::ddr5::mr::ATTR_NUM_CHANNELS][DIMM_NUMBER] =
{
    //RCW00
    {
        {
            {0x00, mss::attr::get_ddr5_rcw00_cha_d0},
            {0x00, mss::attr::get_ddr5_rcw00_cha_d1}
        },
        {
            {0x00, mss::attr::get_ddr5_rcw00_chb_d0},
            {0x00, mss::attr::get_ddr5_rcw00_chb_d1}
        }
    },
    //RCW01
    {
        {
            {0x01, mss::attr::get_ddr5_rcw01_cha_d0},
            {0x01, mss::attr::get_ddr5_rcw01_cha_d1}
        },
        {
            {0x01, mss::attr::get_ddr5_rcw01_chb_d0},
            {0x01, mss::attr::get_ddr5_rcw01_chb_d1}
        }
    },
    //RCW05
    {
        {
            {0x05, mss::attr::get_ddr5_rcw05_cha_d0},
            {0x05, mss::attr::get_ddr5_rcw05_cha_d1}
        },
        {
            {0x05, mss::attr::get_ddr5_rcw05_chb_d0},
            {0x05, mss::attr::get_ddr5_rcw05_chb_d1}
        }
    },
    //RCW08
    {
        {
            {0x08, mss::attr::get_ddr5_rcw08_cha_d0},
            {0x08, mss::attr::get_ddr5_rcw08_cha_d1}
        },
        {
            {0x08, mss::attr::get_ddr5_rcw08_chb_d0},
            {0x08, mss::attr::get_ddr5_rcw08_chb_d1}
        }
    },
    //RCW09
    {
        {
            {0x09, mss::attr::get_ddr5_rcw09_cha_d0},
            {0x09, mss::attr::get_ddr5_rcw09_cha_d1}
        },
        {
            {0x09, mss::attr::get_ddr5_rcw09_chb_d0},
            {0x09, mss::attr::get_ddr5_rcw09_chb_d1}
        }
    },
    //RCW0A
    {
        {
            {0x0A, mss::attr::get_ddr5_rcw0a_cha_d0},
            {0x0A, mss::attr::get_ddr5_rcw0a_cha_d1}
        },
        {
            {0x0A, mss::attr::get_ddr5_rcw0a_chb_d0},
            {0x0A, mss::attr::get_ddr5_rcw0a_chb_d1}
        }
    },
    //RCW0C
    {
        {
            {0x0C, mss::attr::get_ddr5_rcw0c_cha_d0},
            {0x0C, mss::attr::get_ddr5_rcw0c_cha_d1}
        },
        {
            {0x0C, mss::attr::get_ddr5_rcw0c_chb_d0},
            {0x0C, mss::attr::get_ddr5_rcw0c_chb_d1}
        }
    },
    //RCW0D
    {
        {
            {0x0D, mss::attr::get_ddr5_rcw0d_cha_d0},
            {0x0D, mss::attr::get_ddr5_rcw0d_cha_d1}
        },
        {
            {0x0D, mss::attr::get_ddr5_rcw0d_chb_d0},
            {0x0D, mss::attr::get_ddr5_rcw0d_chb_d1}
        }
    },
    //RCW0E
    {
        {
            {0x0E, mss::attr::get_ddr5_rcw0e_cha_d0},
            {0x0E, mss::attr::get_ddr5_rcw0e_cha_d1}
        },
        {
            {0x0E, mss::attr::get_ddr5_rcw0e_chb_d0},
            {0x0E, mss::attr::get_ddr5_rcw0e_chb_d1}
        }
    },
    //RCW0F
    {
        {
            {0x0F, mss::attr::get_ddr5_rcw0f_cha_d0},
            {0x0F, mss::attr::get_ddr5_rcw0f_cha_d1}
        },
        {
            {0x0F, mss::attr::get_ddr5_rcw0f_chb_d0},
            {0x0F, mss::attr::get_ddr5_rcw0f_chb_d1}
        }
    },
    //RCW40
    {
        {
            {0x40, mss::attr::get_ddr5_rcw40_cha_d0},
            {0x40, mss::attr::get_ddr5_rcw40_cha_d1}
        },
        {
            {0x40, mss::attr::get_ddr5_rcw40_chb_d0},
            {0x40, mss::attr::get_ddr5_rcw40_chb_d1}
        }
    },
    //RCW41
    {
        {
            {0x41, mss::attr::get_ddr5_rcw41_cha_d0},
            {0x41, mss::attr::get_ddr5_rcw41_cha_d1}
        },
        {
            {0x41, mss::attr::get_ddr5_rcw41_chb_d0},
            {0x41, mss::attr::get_ddr5_rcw41_chb_d1}
        }
    },
    //RCW42
    {
        {
            {0x42, mss::attr::get_ddr5_rcw42_cha_d0},
            {0x42, mss::attr::get_ddr5_rcw42_cha_d1}
        },
        {
            {0x42, mss::attr::get_ddr5_rcw42_chb_d0},
            {0x42, mss::attr::get_ddr5_rcw42_chb_d1}
        }
    },
    //RCW43
    {
        {
            {0x43, mss::attr::get_ddr5_rcw43_cha_d0},
            {0x43, mss::attr::get_ddr5_rcw43_cha_d1}
        },
        {
            {0x43, mss::attr::get_ddr5_rcw43_chb_d0},
            {0x43, mss::attr::get_ddr5_rcw43_chb_d1}
        }
    },
    //RCW44
    {
        {
            {0x44, mss::attr::get_ddr5_rcw44_cha_d0},
            {0x44, mss::attr::get_ddr5_rcw44_cha_d1}
        },
        {
            {0x44, mss::attr::get_ddr5_rcw44_chb_d0},
            {0x44, mss::attr::get_ddr5_rcw44_chb_d1}
        }
    },
    //RCW45
    {
        {
            {0x45, mss::attr::get_ddr5_rcw45_cha_d0},
            {0x45, mss::attr::get_ddr5_rcw45_cha_d1}
        },
        {
            {0x45, mss::attr::get_ddr5_rcw45_chb_d0},
            {0x45, mss::attr::get_ddr5_rcw45_chb_d1}
        }
    },
    //RCW46
    {
        {
            {0x46, mss::attr::get_ddr5_rcw46_cha_d0},
            {0x46, mss::attr::get_ddr5_rcw46_cha_d1}
        },
        {
            {0x46, mss::attr::get_ddr5_rcw46_chb_d0},
            {0x46, mss::attr::get_ddr5_rcw46_chb_d1}
        }
    },
    //RCW47
    {
        {
            {0x47, mss::attr::get_ddr5_rcw47_cha_d0},
            {0x47, mss::attr::get_ddr5_rcw47_cha_d1}
        },
        {
            {0x47, mss::attr::get_ddr5_rcw47_chb_d0},
            {0x47, mss::attr::get_ddr5_rcw47_chb_d1}
        }
    },
    //RCW48
    {
        {
            {0x48, mss::attr::get_ddr5_rcw48_cha_d0},
            {0x48, mss::attr::get_ddr5_rcw48_cha_d1}
        },
        {
            {0x48, mss::attr::get_ddr5_rcw48_chb_d0},
            {0x48, mss::attr::get_ddr5_rcw48_chb_d1}
        }
    },
    //RCW49
    {
        {
            {0x49, mss::attr::get_ddr5_rcw49_cha_d0},
            {0x49, mss::attr::get_ddr5_rcw49_cha_d1}
        },
        {
            {0x49, mss::attr::get_ddr5_rcw49_chb_d0},
            {0x49, mss::attr::get_ddr5_rcw49_chb_d1}
        }
    }
};
#endif

///
/// @class bad_bits_mc
/// @brief Structure of bad bits for rank0 and rank1 in MC perspective
///
struct bad_bits_per_rank_mc
{
    uint32_t iv_bad_bits_byte0_3[mss::ody::HW_MAX_MRANK_PER_PORT];
    uint32_t iv_bad_bits_byte4_7[mss::ody::HW_MAX_MRANK_PER_PORT];
    uint16_t iv_bad_bits_byte8_9[mss::ody::HW_MAX_MRANK_PER_PORT];
} __attribute__ ((aligned (8)));


///
/// @brief Configures the sequence control based upon attributes and requested sequences
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sequence_ctrl user requested sequence control attributes
/// @param[out] o_output the sequence control that this part can support
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
inline fapi2::ReturnCode SequenceCtrl_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint16_t i_sequence_ctrl,
        uint16_t& o_output)
{
    constexpr uint8_t RCD_CSCA = 1;
    constexpr uint8_t LRDIMM_TESTS_START = 2;
    constexpr uint8_t LRDIMM_TESTS_LEN = 4;
    // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
    constexpr uint8_t RFU8 = 7;
    constexpr uint8_t RFU7 = 8;

    fapi2::buffer<uint16_t> l_buffer(i_sequence_ctrl);
    bool l_has_rcd = false;
    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));

    // Make sure Run RCD_CSCA is disabled for UDIMM
    if (!l_has_rcd)
    {
        l_buffer.clearBit<RCD_CSCA>();
    }

    // Force LRDIMM tests to be disabled
    l_buffer.clearBit<LRDIMM_TESTS_START, LRDIMM_TESTS_LEN>();

    // Force RFU tests to be disabled
    l_buffer.clearBit<RFU8>();
    l_buffer.clearBit<RFU7>();

    FAPI_INF_NO_SBE(TARGTIDFORMAT "Applying overrides to SequenceCtrl before:0x%04x after:0x%04x", GENTARGTID(i_target),
                    i_sequence_ctrl, l_buffer);

    o_output = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter AdvTrainOpt
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_AdvTrainOpt(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_ADV_TRAIN_OPT, i_target, io_msg_block.AdvTrainOpt));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter MsgMisc
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_MsgMisc(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_MSG_MISC, i_target, io_msg_block.MsgMisc));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter PllBypassEn
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_PllBypassEn(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PLL_BYPASS_EN, i_target, io_msg_block.PllBypassEn));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter DRAMFreq
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_DRAMFreq(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    uint64_t l_DRAMFreq = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, i_target, l_DRAMFreq));
    io_msg_block.DRAMFreq = static_cast<uint16_t>(l_DRAMFreq);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter RXEN_ADJ
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_RXEN_ADJ(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_RXEN_ADJ, i_target, io_msg_block.RXEN_ADJ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter RX2D_DFE_Misc
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_RX2D_DFE_Misc(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_RX2D_DFE_MISC, i_target, io_msg_block.RX2D_DFE_Misc));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter PhyVref
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_PhyVref(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_PHY_VREF_RD, i_target, io_msg_block.PhyVref));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter D5Misc
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_dimm the active DIMM target on the given memory port
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_D5Misc(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                      PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    fapi2::buffer<uint8_t> l_buffer;
    uint8_t l_redundant_cs_en = 0;
    constexpr uint8_t PARTIAL_RANK_OPTION = 6;

    // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
    constexpr uint8_t RFU5 = 2;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_D5MISC, i_target, l_buffer));
    FAPI_TRY(mss::attr::get_ddr5_redundant_cs_en(i_dimm, l_redundant_cs_en));

    // Update D5Misc[1] depending on redundant CS mode
    l_buffer.writeBit<PARTIAL_RANK_OPTION>(l_redundant_cs_en == fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE);

    // Force RFU bit to be disabled
    l_buffer.clearBit<RFU5>();

    io_msg_block.D5Misc = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter WL_ADJ
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_WL_ADJ(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_WL_ADJ, i_target, io_msg_block.WL_ADJ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter SequenceCtrl
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_SequenceCtrl(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    constexpr uint8_t RCD_CSCA = 1;
    constexpr uint8_t LRDIMM_TESTS_START = 2;
    constexpr uint8_t LRDIMM_TESTS_LEN = 4;
    // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
    constexpr uint8_t RFU8 = 7;
    constexpr uint8_t RFU7 = 8;

    fapi2::buffer<uint16_t> l_buffer;
    bool l_has_rcd = false;

    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_SEQUENCE_CTRL, i_target, l_buffer));

    // Make sure Run RCD_CSCA is disabled for UDIMM
    if (!l_has_rcd)
    {
        l_buffer.clearBit<RCD_CSCA>();
    }

    // Force LRDIMM tests to be disabled
    l_buffer.clearBit<LRDIMM_TESTS_START, LRDIMM_TESTS_LEN>();

    // Force RFU tests to be disabled
    l_buffer.clearBit<RFU8>();
    l_buffer.clearBit<RFU7>();

    io_msg_block.SequenceCtrl = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter HdtCtrl
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_HdtCtrl(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DRAMINIT_VERBOSITY, i_target, io_msg_block.HdtCtrl));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter PhyCfg
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_PhyCfg(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_CFG, i_target, io_msg_block.PhyCfg));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter DFIMRLMargin
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_DFIMRLMargin(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_DFIMRL_MARGIN, i_target, io_msg_block.DFIMRLMargin));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter UseBroadcastMR
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_UseBroadcastMR(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_USE_BROADCAST_MR, i_target, io_msg_block.UseBroadcastMR));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter DisabledDbyte
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_DisabledDbyte(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_DISABLED_DBYTE, i_target, io_msg_block.DisabledDbyte));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter CATrainOpt
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_dimm the active DIMM target on the given memory port
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_CATrainOpt(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
    constexpr uint8_t RFU6 = 1;
    constexpr uint8_t CA13_TRAIN_SKIP = 3;
    constexpr uint8_t CSCA_TRAINING_STEP_SIZE = 4;
    constexpr uint8_t CSCA_TRAINING_STEP_SIZE_LEN = 2;
    constexpr uint8_t CA_DFE_TRAINING = 6;
    constexpr uint8_t CA_2D_TRAINING = 7;

    fapi2::buffer<uint8_t> l_buffer;

    bool l_has_rcd = false;
    uint16_t l_stack_height = 0;
    uint8_t l_density = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_CA_TRAIN_OPTIONS, i_target, l_buffer));
    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));
    FAPI_TRY(mss::attr::get_3ds_height(i_dimm, l_stack_height));
    FAPI_TRY(mss::attr::get_dram_density(i_dimm, l_density));

    // Make sure RDIMM-only training options are disabled for UDIMM
    if (!l_has_rcd)
    {
        l_buffer.clearBit<CA_DFE_TRAINING>()
        .clearBit<CA_2D_TRAINING>();
    }

    // Set max step size for CS and CA training for sim
    if (i_sim)
    {
        l_buffer.setBit<CSCA_TRAINING_STEP_SIZE, CSCA_TRAINING_STEP_SIZE_LEN>();
    }

    // Disable the reserved bit
    l_buffer.clearBit<RFU6>();

    // We want to run CA13 training if we're an 8H stack or greater OR if the DRAM density is 64Gb or greater
    // Skip if we're less than an 8H stack and we're less than a 64Gb
    l_buffer.writeBit<CA13_TRAIN_SKIP>(l_stack_height < fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8
                                       && l_density < fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_64G);

    io_msg_block.CATrainOpt = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter TX2D_DFE_Misc
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_TX2D_DFE_Misc(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    constexpr uint8_t DSTEP_SIZE_X = 0;
    constexpr uint8_t DSTEP_SIZE_X_LEN = 2;
    constexpr uint8_t VSTEP_SIZE_X = 2;
    constexpr uint8_t VSTEP_SIZE_X_LEN = 2;
    constexpr uint8_t TAP_BIAS_STEP = 4;
    constexpr uint8_t TAP_BIAS_STEP_LEN = 2;
    constexpr uint8_t NB_TAP_M1 = 6;
    constexpr uint8_t NB_TAP_M1_LEN = 2;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_TX2D_DFE_MISC, i_target, l_buffer));

    // Set min NbTAP to train for sim
    // Set max step size for voltage and delay training for sim
    if (i_sim)
    {
        l_buffer.clearBit<NB_TAP_M1, NB_TAP_M1_LEN>()
        .setBit<TAP_BIAS_STEP, TAP_BIAS_STEP_LEN>()
        .setBit<DSTEP_SIZE_X, DSTEP_SIZE_X_LEN>()
        .setBit<VSTEP_SIZE_X, VSTEP_SIZE_X_LEN>();
    }

    io_msg_block.TX2D_DFE_Misc = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter RX2D_TrainOpt
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_RX2D_TrainOpt(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
    constexpr uint8_t RFU7 = 0;
    constexpr uint8_t DELAY_STEP_SIZE = 3;
    constexpr uint8_t DELAY_STEP_SIZE_LEN = 2;
    constexpr uint8_t VOLTAGE_STEP_SIZE = 5;
    constexpr uint8_t VOLTAGE_STEP_SIZE_LEN = 2;
    constexpr uint8_t RX2D_DFE = 7;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_RX2D_TRAIN_OPT, i_target, l_buffer));

    // Set min NbTAP to train for sim
    // Set max step size for voltage and delay training for sim
    if (i_sim)
    {
        l_buffer.clearBit<RX2D_DFE>()
        .setBit<DELAY_STEP_SIZE, DELAY_STEP_SIZE_LEN>()
        .setBit<VOLTAGE_STEP_SIZE, VOLTAGE_STEP_SIZE_LEN>();
    }

    // Disable the reserved bit
    l_buffer.clearBit<RFU7>();

    io_msg_block.RX2D_TrainOpt = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter TX2D_TrainOpt
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_TX2D_TrainOpt(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Note: naming fields after Synopsys's structure spec, and they count bits from right to left
    constexpr uint8_t RFU7 = 0;
    constexpr uint8_t DELAY_STEP_SIZE = 3;
    constexpr uint8_t DELAY_STEP_SIZE_LEN = 2;
    constexpr uint8_t VOLTAGE_STEP_SIZE = 5;
    constexpr uint8_t VOLTAGE_STEP_SIZE_LEN = 2;
    constexpr uint8_t TX2D_DFE = 7;

    fapi2::buffer<uint8_t> l_buffer;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_TX2D_TRAIN_OPT, i_target, l_buffer));

    // Set min NbTAP to train for sim
    // Set max step size for voltage and delay training for sim
    if (i_sim)
    {
        l_buffer.clearBit<TX2D_DFE>()
        .setBit<DELAY_STEP_SIZE, DELAY_STEP_SIZE_LEN>()
        .setBit<VOLTAGE_STEP_SIZE, VOLTAGE_STEP_SIZE_LEN>();
    }

    // Disable the reserved bit
    l_buffer.clearBit<RFU7>();

    io_msg_block.TX2D_TrainOpt = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter PhyConfigOverride
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_PhyConfigOverride(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    uint16_t l_PhyConfigOverride = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_CONFIG_OVERRIDE, i_target, l_PhyConfigOverride));
    io_msg_block.PhyConfigOverride = l_PhyConfigOverride;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter EnabledDQsChA
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_EnabledDQsChA(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_ENABLED_DQ_CHA, i_target, io_msg_block.EnabledDQsChA));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter EnabledDQsChB
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_EnabledDQsChB(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_ENABLED_DQ_CHB, i_target, io_msg_block.EnabledDQsChB));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter CsPresentChA
/// @param[in] i_dimm the DIMM target on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_CsPresentChA(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    fapi2::buffer<uint8_t> l_ranks_configed_buf;
    FAPI_TRY(mss::attr::get_dimm_ranks_configed(i_dimm, l_ranks_configed_buf));

    // Update the number of CS present based upon the number of DQ on each channel
    if (io_msg_block.EnabledDQsChA == 0)
    {
        l_ranks_configed_buf = 0;
    }

    l_ranks_configed_buf.reverse();

    io_msg_block.CsPresentChA = l_ranks_configed_buf;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter CsPresentChB
/// @param[in] i_dimm the DIMM target on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_CsPresentChB(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    fapi2::buffer<uint8_t> l_ranks_configed_buf;
    FAPI_TRY(mss::attr::get_dimm_ranks_configed(i_dimm, l_ranks_configed_buf));

    // Update the number of CS present based upon the number of DQ on each channel
    if(io_msg_block.EnabledDQsChB == 0)
    {
        l_ranks_configed_buf = 0;
    }

    l_ranks_configed_buf.reverse();

    io_msg_block.CsPresentChB = l_ranks_configed_buf;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter ReservedF6
/// @param[in] i_dimm the DIMM target on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_ReservedF6(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Need to set ReservedF6[6] (counting right-to-left) to get per-DRAM CK/CS/CA ODT
    constexpr uint8_t PER_DRAM_ODT = 1;
    fapi2::buffer<uint8_t> l_buffer;

    uint8_t l_dimm_type = 0;
    FAPI_TRY(mss::attr::get_dimm_type(i_dimm, l_dimm_type));

    // Only impacts DDIMM
    // Note: doing an if around the setBit to preserve the original value, just in case
    if(fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM == l_dimm_type)
    {
        l_buffer.setBit<PER_DRAM_ODT>();
    }

    io_msg_block.ReservedF6 = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameters WR_RD_RTT_PARK_A/B[RANK]
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_dimm the active DIMM target on the given memory port
/// @param[in] i_rank_infos vector of rank infos representing all mranks on memory port
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_WR_RD_RTT_PARK(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Offset into PMU_SMB_DDR5U_1D_t for channel[A] on Rank[0]
    // To get to channel[B]rank[R], add R and CHANNELB_OFFSET to the pointer
    constexpr uint8_t FIRST_OFFSET = 0xfc;
    constexpr uint8_t CHANNELB_OFFSET = 0xec;

    uint8_t* const l_WR_RD_RTT_PARK_A0_p = (uint8_t*)&io_msg_block + FIRST_OFFSET;

    constexpr uint8_t RD_SHIFT = 4;

    uint8_t l_RD_RTT_PARK_attr[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_WR_RTT_PARK_attr[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_RD_RTT_PARK[mss::ody::MAX_RANK_PER_PHY] = {0};
    uint8_t l_WR_RTT_PARK[mss::ody::MAX_RANK_PER_PHY] = {0};

    FAPI_TRY(mss::attr::get_ddr5_rtt_park_rd(i_dimm, l_RD_RTT_PARK_attr));
    FAPI_TRY(mss::attr::get_ddr5_rtt_park_wr(i_dimm, l_WR_RTT_PARK_attr));

    // Swizzle DRAM index from port rank to phy rank
    for (const auto& l_rank_info : i_rank_infos)
    {
        const auto l_port_rank = l_rank_info.get_port_rank();
        const auto l_phy_rank = l_rank_info.get_phy_rank();

        l_RD_RTT_PARK[l_phy_rank] = l_RD_RTT_PARK_attr[l_port_rank];
        l_WR_RTT_PARK[l_phy_rank] = l_WR_RTT_PARK_attr[l_port_rank];
    }

    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_RD_RTT_PARK));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_WR_RTT_PARK));

    for (uint8_t l_phy_rank = 0; l_phy_rank < mss::ody::MAX_RANK_PER_PHY; l_phy_rank++)
    {
        const uint8_t l_value = (l_RD_RTT_PARK[l_phy_rank] << RD_SHIFT) | l_WR_RTT_PARK[l_phy_rank];
        uint8_t* l_msg_block_p = l_WR_RD_RTT_PARK_A0_p + l_phy_rank;
        *l_msg_block_p = l_value;
        *(l_msg_block_p + CHANNELB_OFFSET) = l_value;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter Reserved1E2
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_Reserved1E2(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    constexpr uint8_t BIAS_STEP_SIZE = 4;
    constexpr uint8_t BIAS_STEP_SIZE_LEN = 2;

    fapi2::buffer<uint8_t> l_buffer;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_CA_DFE_TRAIN_OPTIONS, i_target, l_buffer));

    // Set max bias step size for sim
    if (i_sim)
    {
        l_buffer.setBit<BIAS_STEP_SIZE, BIAS_STEP_SIZE_LEN>();
    }

    io_msg_block.Reserved1E2 = l_buffer;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter Reserved1E4
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_Reserved1E4(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_PHY_DEBUG_TRAIN_OPTIONS, i_target, io_msg_block.Reserved1E4));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter WL_ADJ_START
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_WL_ADJ_START(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    uint16_t l_WL_ADJ_START = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_WL_ADJ_START, i_target, l_WL_ADJ_START));
    io_msg_block.WL_ADJ_START = l_WL_ADJ_START;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameter WL_ADJ_END
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_WL_ADJ_END(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    uint16_t l_WL_ADJ_END = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_WL_ADJ_END, i_target, l_WL_ADJ_END));
    io_msg_block.WL_ADJ_END = l_WL_ADJ_END;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for parameters DisabledDB[BYTE]LaneR[RANK]
/// @param[in] i_dimm the DIMM target on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_DisabledDB(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Offset into PMU_SMB_DDR5U_1D_t for DByte[0] on Rank[0]
    // To get to DByte[i], add MAX_BYTES_PER_PORT*rank and i to the pointer
    constexpr uint16_t FIRST_OFFSET = 0x740;

    uint8_t* const l_DisabledDB0LaneR0_p = (uint8_t*)&io_msg_block + FIRST_OFFSET;

    fapi2::buffer<uint32_t> l_nibble_enables;
    uint8_t l_byte_disables[10] __attribute__ ((aligned (8))) = {};
    FAPI_TRY(mss::attr::get_nibble_enables(i_dimm, l_nibble_enables));
    FAPI_TRY(nibble_enable_db_disable(l_nibble_enables, l_byte_disables));

    for (uint8_t l_phy_rank = 0; l_phy_rank < mss::ody::MAX_RANK_PER_PHY; l_phy_rank++)
    {
        for (uint8_t l_dbyte = 0; l_dbyte < mss::ody::MAX_BYTES_PER_PORT; l_dbyte++)
        {
            uint8_t* const l_msg_block_p = l_DisabledDB0LaneR0_p + (mss::ody::MAX_BYTES_PER_PORT * l_phy_rank) + l_dbyte;
            *l_msg_block_p = l_byte_disables[l_dbyte];
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief msg_block structure setup for Vref_Sweep parameters
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
/// @note these are new in the M18 software
///
inline fapi2::ReturnCode setup_vref_sweeps(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_VREFCS_SWEEP_MIN, i_target, io_msg_block.VrefCS_Sweep_Min));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_VREFCS_SWEEP_MAX, i_target, io_msg_block.VrefCS_Sweep_Max));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_VREFCA_SWEEP_MIN, i_target, io_msg_block.VrefCA_Sweep_Min));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DDR5_VREFCA_SWEEP_MAX, i_target, io_msg_block.VrefCA_Sweep_Max));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to insert per-mrank MR data into the msg_block_params structure
/// @param[in] i_MR_data the per-mrank MR data for both channels
/// @param[in] i_offset byte offset into the PMU_SMB_DDR5U_1D_t struct for channel[A] mrank[0]
/// @param[in] i_phy_rank mrank to insert data into
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
///
inline void insert_MR_data_into_msg_block(const uint8_t i_MR_data,
        const uint8_t i_offset,
        const uint8_t i_phy_rank,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    constexpr uint8_t RANK_OFFSET = 0x26;
    constexpr uint8_t CHANNELB_OFFSET = 0xec;

    uint8_t* l_msg_block_p = (uint8_t*)&io_msg_block + i_offset + (RANK_OFFSET * i_phy_rank);
    *l_msg_block_p = i_MR_data;
    *(l_msg_block_p + CHANNELB_OFFSET) = i_MR_data;
}

///
/// @brief Helper function to insert per-channel MR data into the msg_block_params structure
/// @param[in] i_MR_CHA_data the per-mrank MR data for channel A
/// @param[in] i_MR_CHB_data the per-mrank MR data for channel B
/// @param[in] i_offset byte offset into the PMU_SMB_DDR5U_1D_t struct for channel[A] mrank[0]
/// @param[in] i_phy_rank mrank to insert data into
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
///
inline void insert_per_channel_MR_data_into_msg_block(const uint8_t i_MR_CHA_data,
        const uint8_t i_MR_CHB_data,
        const uint8_t i_offset,
        const uint8_t i_phy_rank,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    constexpr uint8_t RANK_OFFSET = 0x26;
    constexpr uint8_t CHANNELB_OFFSET = 0xec;

    uint8_t* l_msg_block_p = (uint8_t*)&io_msg_block + i_offset + (RANK_OFFSET * i_phy_rank);
    *l_msg_block_p = i_MR_CHA_data;
    *(l_msg_block_p + CHANNELB_OFFSET) = i_MR_CHB_data;
}

///
/// @brief Helper function to insert per-nibble MR data into the msg_block_params structure
/// @param[in] i_MR_data the per-nibble MR data
/// @param[in] i_offset byte offset into the PMU_SMB_DDR5U_1D_t struct for mrank[0] nibble[0]
/// @param[in] i_phy_rank mrank to insert data into
/// @param[in] i_nibble nibble to insert data into
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
///
inline void insert_per_nibble_MR_data_into_msg_block(const uint8_t i_MR_data,
        const uint16_t i_offset,
        const uint8_t i_phy_rank,
        const uint8_t i_nibble,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    constexpr uint8_t PER_NIBBLE_RANK_OFFSET = 0x14;

    uint8_t* l_msg_block_p = (uint8_t*)&io_msg_block + i_offset + (PER_NIBBLE_RANK_OFFSET * i_phy_rank) + i_nibble;
    *l_msg_block_p = i_MR_data;
}

///
/// @brief msg_block structure setup for Mode Register related parameters
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_dimm the active DIMM target on the given memory port
/// @param[in] i_rank_infos vector of rank infos representing all mranks on memory port
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_msg_block_MRs(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
        PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    // Offsets into PMU_SMB_DDR5U_1D_t for per-channel MR: channel[A] on Rank[0]
    // To get to channel[B]rank[R], add (RANK_OFFSET * R) and CHANNELB_OFFSET to the pointer
    constexpr uint8_t MR0_OFFSET = 0x5e;
    constexpr uint8_t MR2_OFFSET = 0x5f;
    constexpr uint8_t MR3_OFFSET = 0x60;
    constexpr uint8_t MR4_OFFSET = 0x61;
    constexpr uint8_t MR5_OFFSET = 0x62;
    constexpr uint8_t MR6_OFFSET = 0x63;
    constexpr uint8_t MR8_OFFSET = 0x65;
    constexpr uint8_t MR10_OFFSET = 0x67;
    constexpr uint8_t MR11_OFFSET = 0x68;
    constexpr uint8_t MR12_OFFSET = 0x69;
    constexpr uint8_t MR13_OFFSET = 0x6a;
    constexpr uint8_t MR14_OFFSET = 0x6b;
    constexpr uint8_t MR15_OFFSET = 0x6c;
    constexpr uint8_t MR32_OFFSET = 0x6e;
    constexpr uint8_t MR32_ORG_OFFSET = 0x72;
    constexpr uint8_t MR33_OFFSET = 0x6f;
    constexpr uint8_t MR33_ORG_OFFSET = 0x76;
    constexpr uint8_t MR34_OFFSET = 0x70;
    constexpr uint8_t MR35_OFFSET = 0x71;
    constexpr uint8_t MR37_OFFSET = 0x73;
    constexpr uint8_t MR38_OFFSET = 0x74;
    constexpr uint8_t MR39_OFFSET = 0x75;
    constexpr uint8_t MR50_OFFSET = 0x80;
    constexpr uint8_t MR51_OFFSET = 0x81;
    constexpr uint8_t MR52_OFFSET = 0x82;
    constexpr uint8_t MR111_OFFSET = 0x6d;
    constexpr uint8_t DFE_GainBias_OFFSET = 0x83;

    // Offsets into PMU_SMB_DDR5U_1D_t for per-device MR: nibble[0] on Rank[0]
    // To get to nibble[N]rank[R], add N and (PD_RANK_OFFSET * R) to the pointer
    constexpr uint16_t VrefDqR0Nib0_OFFSET = 0x600;
    constexpr uint16_t MR3R0Nib0_OFFSET = 0x650;
    constexpr uint16_t VrefCSR0Nib0_OFFSET = 0x6a0;
    constexpr uint16_t VrefCAR0Nib0_OFFSET = 0x6f0;
    constexpr uint16_t MR32R0Nib0_OFFSET = 0x780;

    uint8_t l_MR0[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR2[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR3[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] __attribute__ ((aligned (8))) = {};
    uint8_t l_MR4[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR5[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR6[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR32[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR32_ORG[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR8[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR10[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] __attribute__ ((aligned (8))) = {};
    uint8_t l_MR11[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] __attribute__ ((aligned (8))) = {};
    uint8_t l_MR12[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] __attribute__ ((aligned (8))) = {};
    uint8_t l_MR13[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR14[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR15[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR111[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR33[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR33_ORG[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR32_per_dram[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] __attribute__ ((aligned (8))) = {};
    uint8_t l_MR33_per_dram[mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] __attribute__ ((aligned (8))) = {};
    uint8_t l_MR34[mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};
    uint8_t l_MR35[mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {};
    uint8_t l_MR37[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR38[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR39[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR50[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR51[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_MR52[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_DFE_GainBias[mss::ody::MAX_RANK_PER_DIMM] = {0};
    uint8_t l_dram_width = 0;

    // Create MR data structs
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    const auto l_mr0 = mss::ddr5::mr0_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr2 = mss::ddr5::mr2_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr3 = mss::ddr5::mr3_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr4 = mss::ddr5::mr4_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr5 = mss::ddr5::mr5_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr6 = mss::ddr5::mr6_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr32 = mss::ddr5::mr32_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr32_per_dram = mss::ddr5::mr32_per_dram_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr8 = mss::ddr5::mr8_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr10 = mss::ddr5::mr10_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr11 = mss::ddr5::mr11_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr12 = mss::ddr5::mr12_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr13 = mss::ddr5::mr13_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr14 = mss::ddr5::mr14_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr15 = mss::ddr5::mr15_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr111 = mss::ddr5::mr111_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr33 = mss::ddr5::mr33_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr33_per_dram = mss::ddr5::mr33_per_dram_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr34 = mss::ddr5::mr34_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr35 = mss::ddr5::mr35_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr37 = mss::ddr5::mr37_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr38 = mss::ddr5::mr38_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr39 = mss::ddr5::mr39_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr50 = mss::ddr5::mr50_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr51 = mss::ddr5::mr51_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr52 = mss::ddr5::mr52_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);
    const auto l_mr112 = mss::ddr5::mr112_data<mss::mc_type::ODYSSEY>(i_dimm, l_rc);

    FAPI_TRY(l_rc, TARGTIDFORMAT " Failed attribute access during MR setup", TARGTID);

    FAPI_TRY(mss::attr::get_dram_width(i_dimm, l_dram_width));
    FAPI_ASSERT((l_dram_width != 0),
                fapi2::ODY_DRAMINIT_ZERO_DRAM_WIDTH()
                .set_PORT_TARGET(i_target),
                TARGTIDFORMAT " saw a zero value in ATTR_MEM_EFF_DRAM_WIDTH", TARGTID);

    for (const auto& l_rank_info : i_rank_infos)
    {
        // TODO: JIRA:MSWT-216 Create API to walk through DRAM/nibble indexes
        const uint8_t l_nibble_increment = (l_dram_width / 4);
        const uint8_t l_max_drams = mss::ody::MAX_NIBBLES_PER_PORT / l_nibble_increment;
        const auto l_phy_rank = l_rank_info.get_phy_rank();

        FAPI_TRY(l_mr0.assemble_data(l_rank_info, l_MR0[l_phy_rank]));
        FAPI_TRY(l_mr2.assemble_data(l_rank_info, l_MR2[l_phy_rank]));
        FAPI_TRY(l_mr4.assemble_data(l_rank_info, l_MR4[l_phy_rank]));
        FAPI_TRY(l_mr5.assemble_data(l_rank_info, l_MR5[l_phy_rank]));
        FAPI_TRY(l_mr6.assemble_data(l_rank_info, l_MR6[l_phy_rank]));
        FAPI_TRY(l_mr32.assemble_data(l_rank_info, l_MR32[l_phy_rank]));
        FAPI_TRY(l_mr32.assemble_data(l_rank_info, l_MR32_ORG[l_phy_rank], mss::ddr5::mr::STRAPB));
        FAPI_TRY(l_mr8.assemble_data(l_rank_info, l_MR8[l_phy_rank]));
        FAPI_TRY(l_mr13.assemble_data(l_rank_info, l_MR13[l_phy_rank]));
        FAPI_TRY(l_mr14.assemble_data(l_rank_info, l_MR14[l_phy_rank]));
        FAPI_TRY(l_mr15.assemble_data(l_rank_info, l_MR15[l_phy_rank]));
        FAPI_TRY(l_mr111.assemble_data(l_rank_info, l_MR111[l_phy_rank]));
        FAPI_TRY(l_mr33.assemble_data(l_rank_info, l_MR33[l_phy_rank]));
        FAPI_TRY(l_mr33.assemble_data(l_rank_info, l_MR33_ORG[l_phy_rank], mss::ddr5::mr::STRAPB));
        // Running on DRAM0 for Channel A and DRAM10 for Channel B
        // Since these are the first DRAMS on each channel
        FAPI_TRY(l_mr34.assemble_data(l_rank_info, l_MR34[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_A],
                                      mss::ddr5::mr::ATTR_DRAM_CHA_SELECT));
        FAPI_TRY(l_mr34.assemble_data(l_rank_info, l_MR34[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_B],
                                      mss::ddr5::mr::ATTR_DRAM_CHB_SELECT));
        // Running on DRAM0 for Channel A and DRAM10 for Channel B
        // Since these are the first DRAMS on each channel
        FAPI_TRY(l_mr35.assemble_data(l_rank_info, l_MR35[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_A],
                                      mss::ddr5::mr::ATTR_DRAM_CHA_SELECT));
        FAPI_TRY(l_mr35.assemble_data(l_rank_info, l_MR35[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_B],
                                      mss::ddr5::mr::ATTR_DRAM_CHB_SELECT));
        FAPI_TRY(l_mr37.assemble_data(l_rank_info, l_MR37[l_phy_rank]));
        FAPI_TRY(l_mr38.assemble_data(l_rank_info, l_MR38[l_phy_rank]));
        FAPI_TRY(l_mr39.assemble_data(l_rank_info, l_MR39[l_phy_rank]));
        FAPI_TRY(l_mr50.assemble_data(l_rank_info, l_MR50[l_phy_rank]));
        FAPI_TRY(l_mr51.assemble_data(l_rank_info, l_MR51[l_phy_rank]));
        FAPI_TRY(l_mr52.assemble_data(l_rank_info, l_MR52[l_phy_rank]));
        FAPI_TRY(l_mr112.assemble_data(l_rank_info, l_DFE_GainBias[l_phy_rank]));

        // Get per-DRAM values
        for (uint8_t l_dram = 0, l_nibble_idx = 0; l_dram < l_max_drams; l_dram++, l_nibble_idx += l_nibble_increment)
        {
            FAPI_TRY(l_mr3.assemble_data(l_rank_info, l_MR3[l_phy_rank][l_nibble_idx], l_dram));
            FAPI_TRY(l_mr10.assemble_data(l_rank_info, l_MR10[l_phy_rank][l_nibble_idx], l_dram));
            FAPI_TRY(l_mr11.assemble_data(l_rank_info, l_MR11[l_phy_rank][l_nibble_idx], l_dram));
            FAPI_TRY(l_mr12.assemble_data(l_rank_info, l_MR12[l_phy_rank][l_nibble_idx], l_dram));
            FAPI_TRY(l_mr33_per_dram.assemble_data(l_rank_info,
                                                   l_MR33_per_dram[l_phy_rank][l_nibble_idx],
                                                   l_dram));
            FAPI_TRY(l_mr32_per_dram.assemble_data(l_rank_info,
                                                   l_MR32_per_dram[l_phy_rank][l_nibble_idx],
                                                   l_dram));
        }
    }

    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR0));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR2));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR4));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR5));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR6));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR32));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR32_ORG));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR32_per_dram));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR8));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR13));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR14));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR15));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR111));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR33));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR33_ORG));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR33_per_dram));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR34));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR34));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR35));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR35));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR37));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR38));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR39));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR50));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR51));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR52));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_DFE_GainBias));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR3));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR10));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR11));
    FAPI_TRY(mss::ody::phy::workarounds::clone_redundant_cs_data(i_target, l_MR12));

    for (uint8_t l_phy_rank = 0; l_phy_rank < mss::ody::MAX_RANK_PER_PHY; l_phy_rank++)
    {
        insert_MR_data_into_msg_block(l_MR0[l_phy_rank], MR0_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR2[l_phy_rank], MR2_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR3[l_phy_rank][0], MR3_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR4[l_phy_rank], MR4_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR5[l_phy_rank], MR5_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR6[l_phy_rank], MR6_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR8[l_phy_rank], MR8_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR10[l_phy_rank][0], MR10_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR11[l_phy_rank][0], MR11_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR12[l_phy_rank][0], MR12_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR13[l_phy_rank], MR13_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR14[l_phy_rank], MR14_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR15[l_phy_rank], MR15_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR32[l_phy_rank], MR32_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR32_ORG[l_phy_rank], MR32_ORG_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR33[l_phy_rank], MR33_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR33_ORG[l_phy_rank], MR33_ORG_OFFSET, l_phy_rank, io_msg_block);
        insert_per_channel_MR_data_into_msg_block(l_MR34[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_A],
                l_MR34[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_B],
                MR34_OFFSET, l_phy_rank, io_msg_block);
        insert_per_channel_MR_data_into_msg_block(l_MR35[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_A],
                l_MR35[l_phy_rank][mss::ddr5::mr::ATTR_CHANNEL_B],
                MR35_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR37[l_phy_rank], MR37_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR38[l_phy_rank], MR38_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR39[l_phy_rank], MR39_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR50[l_phy_rank], MR50_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR51[l_phy_rank], MR51_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR52[l_phy_rank], MR52_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_MR111[l_phy_rank], MR111_OFFSET, l_phy_rank, io_msg_block);
        insert_MR_data_into_msg_block(l_DFE_GainBias[l_phy_rank], DFE_GainBias_OFFSET, l_phy_rank, io_msg_block);

        for (uint8_t l_phy_nibble = 0; l_phy_nibble < mss::ody::MAX_NIBBLES_PER_PORT; l_phy_nibble++)
        {
            // Handle the swizzle from phy to MC nibble index for attribute access
            const uint8_t l_mc_nibble = mss::ody::PHY_TO_MC_NIBBLE[l_phy_nibble];

            insert_per_nibble_MR_data_into_msg_block(l_MR10[l_phy_rank][l_mc_nibble],
                    VrefDqR0Nib0_OFFSET, l_phy_rank, l_phy_nibble, io_msg_block);
            insert_per_nibble_MR_data_into_msg_block(l_MR33_per_dram[l_phy_rank][l_mc_nibble],
                    MR3R0Nib0_OFFSET, l_phy_rank, l_phy_nibble, io_msg_block);
            insert_per_nibble_MR_data_into_msg_block(l_MR12[l_phy_rank][l_mc_nibble],
                    VrefCSR0Nib0_OFFSET, l_phy_rank, l_phy_nibble, io_msg_block);
            insert_per_nibble_MR_data_into_msg_block(l_MR11[l_phy_rank][l_mc_nibble],
                    VrefCAR0Nib0_OFFSET, l_phy_rank, l_phy_nibble, io_msg_block);
            insert_per_nibble_MR_data_into_msg_block(l_MR32_per_dram[l_phy_rank][l_mc_nibble],
                    MR32R0Nib0_OFFSET, l_phy_rank, l_phy_nibble, io_msg_block);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

#ifndef __PPE__
///
/// @brief msg_block structure setup for parameter RCW[N]_CHA/B_D[DIMM]
/// @param[in,out] io_msg_block the PMU_SMB_DDR5U_1D_t struct
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode setup_RCW(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   PMU_SMB_DDR5U_1D_t& io_msg_block)
{
    uint8_t l_RCW[NUM_RCW][mss::ddr5::mr::ATTR_NUM_CHANNELS][DIMM_NUMBER] = {};

    // Initialize the RCW to zeros
    memset(l_RCW, 0, sizeof(l_RCW));

    // Get the supported RCW attr values
    for(uint8_t l_getter_index = 0; l_getter_index < NUM_SUPPORTED_RCW; l_getter_index++)
    {
        for(uint8_t l_channel = 0; l_channel < mss::ddr5::mr::ATTR_NUM_CHANNELS; l_channel++)
        {
            for(uint8_t l_dimm = 0; l_dimm < DIMM_NUMBER; l_dimm++)
            {
                const uint64_t l_rcw_id = get_rcw[l_getter_index][l_channel][l_dimm].first;
                FAPI_TRY(get_rcw[l_getter_index][l_channel][l_dimm].second(i_target,
                         l_RCW[l_rcw_id][l_channel][l_dimm]));
            }
        }
    }

    io_msg_block.RCW00_ChA_D0 = l_RCW[0][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW01_ChA_D0 = l_RCW[1][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW02_ChA_D0 = l_RCW[2][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW03_ChA_D0 = l_RCW[3][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW04_ChA_D0 = l_RCW[4][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW05_ChA_D0 = l_RCW[5][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW06_ChA_D0 = l_RCW[6][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW07_ChA_D0 = l_RCW[7][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW08_ChA_D0 = l_RCW[8][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW09_ChA_D0 = l_RCW[9][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW0A_ChA_D0 = l_RCW[10][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW0B_ChA_D0 = l_RCW[11][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW0C_ChA_D0 = l_RCW[12][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW0D_ChA_D0 = l_RCW[13][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW0E_ChA_D0 = l_RCW[14][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW0F_ChA_D0 = l_RCW[15][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW10_ChA_D0 = l_RCW[16][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW11_ChA_D0 = l_RCW[17][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW12_ChA_D0 = l_RCW[18][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW13_ChA_D0 = l_RCW[19][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW14_ChA_D0 = l_RCW[20][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW15_ChA_D0 = l_RCW[21][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW16_ChA_D0 = l_RCW[22][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW17_ChA_D0 = l_RCW[23][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW18_ChA_D0 = l_RCW[24][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW19_ChA_D0 = l_RCW[25][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW1A_ChA_D0 = l_RCW[26][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW1B_ChA_D0 = l_RCW[27][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW1C_ChA_D0 = l_RCW[28][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW1D_ChA_D0 = l_RCW[29][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW1E_ChA_D0 = l_RCW[30][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW1F_ChA_D0 = l_RCW[31][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW20_ChA_D0 = l_RCW[32][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW21_ChA_D0 = l_RCW[33][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW22_ChA_D0 = l_RCW[34][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW23_ChA_D0 = l_RCW[35][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW24_ChA_D0 = l_RCW[36][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW25_ChA_D0 = l_RCW[37][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW26_ChA_D0 = l_RCW[38][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW27_ChA_D0 = l_RCW[39][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW28_ChA_D0 = l_RCW[40][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW29_ChA_D0 = l_RCW[41][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW2A_ChA_D0 = l_RCW[42][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW2B_ChA_D0 = l_RCW[43][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW2C_ChA_D0 = l_RCW[44][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW2D_ChA_D0 = l_RCW[45][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW2E_ChA_D0 = l_RCW[46][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW2F_ChA_D0 = l_RCW[47][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW30_ChA_D0 = l_RCW[48][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW31_ChA_D0 = l_RCW[49][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW32_ChA_D0 = l_RCW[50][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW33_ChA_D0 = l_RCW[51][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW34_ChA_D0 = l_RCW[52][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW35_ChA_D0 = l_RCW[53][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW36_ChA_D0 = l_RCW[54][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW37_ChA_D0 = l_RCW[55][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW38_ChA_D0 = l_RCW[56][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW39_ChA_D0 = l_RCW[57][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW3A_ChA_D0 = l_RCW[58][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW3B_ChA_D0 = l_RCW[59][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW3C_ChA_D0 = l_RCW[60][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW3D_ChA_D0 = l_RCW[61][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW3E_ChA_D0 = l_RCW[62][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW3F_ChA_D0 = l_RCW[63][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW40_ChA_D0 = l_RCW[64][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW41_ChA_D0 = l_RCW[65][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW42_ChA_D0 = l_RCW[66][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW43_ChA_D0 = l_RCW[67][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW44_ChA_D0 = l_RCW[68][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW45_ChA_D0 = l_RCW[69][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW46_ChA_D0 = l_RCW[70][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW47_ChA_D0 = l_RCW[71][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW48_ChA_D0 = l_RCW[72][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW49_ChA_D0 = l_RCW[73][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW4A_ChA_D0 = l_RCW[74][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW4B_ChA_D0 = l_RCW[75][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW4C_ChA_D0 = l_RCW[76][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW4D_ChA_D0 = l_RCW[77][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW4E_ChA_D0 = l_RCW[78][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW4F_ChA_D0 = l_RCW[79][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW50_ChA_D0 = l_RCW[80][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW51_ChA_D0 = l_RCW[81][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW52_ChA_D0 = l_RCW[82][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW53_ChA_D0 = l_RCW[83][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW54_ChA_D0 = l_RCW[84][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW55_ChA_D0 = l_RCW[85][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW56_ChA_D0 = l_RCW[86][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW57_ChA_D0 = l_RCW[87][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW58_ChA_D0 = l_RCW[88][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW59_ChA_D0 = l_RCW[89][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW5A_ChA_D0 = l_RCW[90][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW5B_ChA_D0 = l_RCW[91][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW5C_ChA_D0 = l_RCW[92][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW5D_ChA_D0 = l_RCW[93][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW5E_ChA_D0 = l_RCW[94][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW5F_ChA_D0 = l_RCW[95][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW60_ChA_D0 = l_RCW[96][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW61_ChA_D0 = l_RCW[97][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW62_ChA_D0 = l_RCW[98][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW63_ChA_D0 = l_RCW[99][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW64_ChA_D0 = l_RCW[100][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW65_ChA_D0 = l_RCW[101][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW66_ChA_D0 = l_RCW[102][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW67_ChA_D0 = l_RCW[103][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW68_ChA_D0 = l_RCW[104][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW69_ChA_D0 = l_RCW[105][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW6A_ChA_D0 = l_RCW[106][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW6B_ChA_D0 = l_RCW[107][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW6C_ChA_D0 = l_RCW[108][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW6D_ChA_D0 = l_RCW[109][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW6E_ChA_D0 = l_RCW[110][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW6F_ChA_D0 = l_RCW[111][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW70_ChA_D0 = l_RCW[112][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW71_ChA_D0 = l_RCW[113][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW72_ChA_D0 = l_RCW[114][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW73_ChA_D0 = l_RCW[115][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW74_ChA_D0 = l_RCW[116][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW75_ChA_D0 = l_RCW[117][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW76_ChA_D0 = l_RCW[118][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW77_ChA_D0 = l_RCW[119][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW78_ChA_D0 = l_RCW[120][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW79_ChA_D0 = l_RCW[121][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW7A_ChA_D0 = l_RCW[122][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW7B_ChA_D0 = l_RCW[123][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW7C_ChA_D0 = l_RCW[124][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW7D_ChA_D0 = l_RCW[125][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW7E_ChA_D0 = l_RCW[126][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];
    io_msg_block.RCW7F_ChA_D0 = l_RCW[127][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM0];

    io_msg_block.RCW00_ChB_D0 = l_RCW[0][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW01_ChB_D0 = l_RCW[1][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW02_ChB_D0 = l_RCW[2][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW03_ChB_D0 = l_RCW[3][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW04_ChB_D0 = l_RCW[4][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW05_ChB_D0 = l_RCW[5][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW06_ChB_D0 = l_RCW[6][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW07_ChB_D0 = l_RCW[7][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW08_ChB_D0 = l_RCW[8][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW09_ChB_D0 = l_RCW[9][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW0A_ChB_D0 = l_RCW[10][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW0B_ChB_D0 = l_RCW[11][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW0C_ChB_D0 = l_RCW[12][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW0D_ChB_D0 = l_RCW[13][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW0E_ChB_D0 = l_RCW[14][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW0F_ChB_D0 = l_RCW[15][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW10_ChB_D0 = l_RCW[16][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW11_ChB_D0 = l_RCW[17][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW12_ChB_D0 = l_RCW[18][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW13_ChB_D0 = l_RCW[19][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW14_ChB_D0 = l_RCW[20][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW15_ChB_D0 = l_RCW[21][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW16_ChB_D0 = l_RCW[22][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW17_ChB_D0 = l_RCW[23][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW18_ChB_D0 = l_RCW[24][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW19_ChB_D0 = l_RCW[25][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW1A_ChB_D0 = l_RCW[26][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW1B_ChB_D0 = l_RCW[27][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW1C_ChB_D0 = l_RCW[28][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW1D_ChB_D0 = l_RCW[29][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW1E_ChB_D0 = l_RCW[30][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW1F_ChB_D0 = l_RCW[31][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW20_ChB_D0 = l_RCW[32][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW21_ChB_D0 = l_RCW[33][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW22_ChB_D0 = l_RCW[34][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW23_ChB_D0 = l_RCW[35][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW24_ChB_D0 = l_RCW[36][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW25_ChB_D0 = l_RCW[37][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW26_ChB_D0 = l_RCW[38][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW27_ChB_D0 = l_RCW[39][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW28_ChB_D0 = l_RCW[40][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW29_ChB_D0 = l_RCW[41][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW2A_ChB_D0 = l_RCW[42][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW2B_ChB_D0 = l_RCW[43][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW2C_ChB_D0 = l_RCW[44][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW2D_ChB_D0 = l_RCW[45][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW2E_ChB_D0 = l_RCW[46][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW2F_ChB_D0 = l_RCW[47][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW30_ChB_D0 = l_RCW[48][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW31_ChB_D0 = l_RCW[49][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW32_ChB_D0 = l_RCW[50][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW33_ChB_D0 = l_RCW[51][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW34_ChB_D0 = l_RCW[52][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW35_ChB_D0 = l_RCW[53][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW36_ChB_D0 = l_RCW[54][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW37_ChB_D0 = l_RCW[55][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW38_ChB_D0 = l_RCW[56][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW39_ChB_D0 = l_RCW[57][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW3A_ChB_D0 = l_RCW[58][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW3B_ChB_D0 = l_RCW[59][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW3C_ChB_D0 = l_RCW[60][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW3D_ChB_D0 = l_RCW[61][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW3E_ChB_D0 = l_RCW[62][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW3F_ChB_D0 = l_RCW[63][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW40_ChB_D0 = l_RCW[64][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW41_ChB_D0 = l_RCW[65][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW42_ChB_D0 = l_RCW[66][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW43_ChB_D0 = l_RCW[67][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW44_ChB_D0 = l_RCW[68][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW45_ChB_D0 = l_RCW[69][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW46_ChB_D0 = l_RCW[70][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW47_ChB_D0 = l_RCW[71][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW48_ChB_D0 = l_RCW[72][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW49_ChB_D0 = l_RCW[73][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW4A_ChB_D0 = l_RCW[74][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW4B_ChB_D0 = l_RCW[75][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW4C_ChB_D0 = l_RCW[76][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW4D_ChB_D0 = l_RCW[77][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW4E_ChB_D0 = l_RCW[78][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW4F_ChB_D0 = l_RCW[79][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW50_ChB_D0 = l_RCW[80][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW51_ChB_D0 = l_RCW[81][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW52_ChB_D0 = l_RCW[82][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW53_ChB_D0 = l_RCW[83][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW54_ChB_D0 = l_RCW[84][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW55_ChB_D0 = l_RCW[85][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW56_ChB_D0 = l_RCW[86][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW57_ChB_D0 = l_RCW[87][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW58_ChB_D0 = l_RCW[88][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW59_ChB_D0 = l_RCW[89][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW5A_ChB_D0 = l_RCW[90][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW5B_ChB_D0 = l_RCW[91][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW5C_ChB_D0 = l_RCW[92][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW5D_ChB_D0 = l_RCW[93][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW5E_ChB_D0 = l_RCW[94][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW5F_ChB_D0 = l_RCW[95][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW60_ChB_D0 = l_RCW[96][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW61_ChB_D0 = l_RCW[97][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW62_ChB_D0 = l_RCW[98][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW63_ChB_D0 = l_RCW[99][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW64_ChB_D0 = l_RCW[100][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW65_ChB_D0 = l_RCW[101][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW66_ChB_D0 = l_RCW[102][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW67_ChB_D0 = l_RCW[103][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW68_ChB_D0 = l_RCW[104][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW69_ChB_D0 = l_RCW[105][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW6A_ChB_D0 = l_RCW[106][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW6B_ChB_D0 = l_RCW[107][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW6C_ChB_D0 = l_RCW[108][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW6D_ChB_D0 = l_RCW[109][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW6E_ChB_D0 = l_RCW[110][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW6F_ChB_D0 = l_RCW[111][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW70_ChB_D0 = l_RCW[112][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW71_ChB_D0 = l_RCW[113][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW72_ChB_D0 = l_RCW[114][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW73_ChB_D0 = l_RCW[115][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW74_ChB_D0 = l_RCW[116][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW75_ChB_D0 = l_RCW[117][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW76_ChB_D0 = l_RCW[118][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW77_ChB_D0 = l_RCW[119][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW78_ChB_D0 = l_RCW[120][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW79_ChB_D0 = l_RCW[121][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW7A_ChB_D0 = l_RCW[122][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW7B_ChB_D0 = l_RCW[123][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW7C_ChB_D0 = l_RCW[124][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW7D_ChB_D0 = l_RCW[125][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW7E_ChB_D0 = l_RCW[126][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];
    io_msg_block.RCW7F_ChB_D0 = l_RCW[127][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM0];

    io_msg_block.RCW00_ChA_D1 = l_RCW[0][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW01_ChA_D1 = l_RCW[1][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW02_ChA_D1 = l_RCW[2][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW03_ChA_D1 = l_RCW[3][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW04_ChA_D1 = l_RCW[4][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW05_ChA_D1 = l_RCW[5][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW06_ChA_D1 = l_RCW[6][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW07_ChA_D1 = l_RCW[7][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW08_ChA_D1 = l_RCW[8][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW09_ChA_D1 = l_RCW[9][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW0A_ChA_D1 = l_RCW[10][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW0B_ChA_D1 = l_RCW[11][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW0C_ChA_D1 = l_RCW[12][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW0D_ChA_D1 = l_RCW[13][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW0E_ChA_D1 = l_RCW[14][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW0F_ChA_D1 = l_RCW[15][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW10_ChA_D1 = l_RCW[16][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW11_ChA_D1 = l_RCW[17][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW12_ChA_D1 = l_RCW[18][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW13_ChA_D1 = l_RCW[19][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW14_ChA_D1 = l_RCW[20][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW15_ChA_D1 = l_RCW[21][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW16_ChA_D1 = l_RCW[22][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW17_ChA_D1 = l_RCW[23][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW18_ChA_D1 = l_RCW[24][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW19_ChA_D1 = l_RCW[25][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW1A_ChA_D1 = l_RCW[26][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW1B_ChA_D1 = l_RCW[27][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW1C_ChA_D1 = l_RCW[28][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW1D_ChA_D1 = l_RCW[29][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW1E_ChA_D1 = l_RCW[30][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW1F_ChA_D1 = l_RCW[31][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW20_ChA_D1 = l_RCW[32][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW21_ChA_D1 = l_RCW[33][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW22_ChA_D1 = l_RCW[34][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW23_ChA_D1 = l_RCW[35][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW24_ChA_D1 = l_RCW[36][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW25_ChA_D1 = l_RCW[37][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW26_ChA_D1 = l_RCW[38][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW27_ChA_D1 = l_RCW[39][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW28_ChA_D1 = l_RCW[40][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW29_ChA_D1 = l_RCW[41][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW2A_ChA_D1 = l_RCW[42][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW2B_ChA_D1 = l_RCW[43][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW2C_ChA_D1 = l_RCW[44][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW2D_ChA_D1 = l_RCW[45][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW2E_ChA_D1 = l_RCW[46][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW2F_ChA_D1 = l_RCW[47][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW30_ChA_D1 = l_RCW[48][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW31_ChA_D1 = l_RCW[49][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW32_ChA_D1 = l_RCW[50][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW33_ChA_D1 = l_RCW[51][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW34_ChA_D1 = l_RCW[52][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW35_ChA_D1 = l_RCW[53][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW36_ChA_D1 = l_RCW[54][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW37_ChA_D1 = l_RCW[55][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW38_ChA_D1 = l_RCW[56][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW39_ChA_D1 = l_RCW[57][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW3A_ChA_D1 = l_RCW[58][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW3B_ChA_D1 = l_RCW[59][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW3C_ChA_D1 = l_RCW[60][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW3D_ChA_D1 = l_RCW[61][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW3E_ChA_D1 = l_RCW[62][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW3F_ChA_D1 = l_RCW[63][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW40_ChA_D1 = l_RCW[64][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW41_ChA_D1 = l_RCW[65][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW42_ChA_D1 = l_RCW[66][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW43_ChA_D1 = l_RCW[67][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW44_ChA_D1 = l_RCW[68][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW45_ChA_D1 = l_RCW[69][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW46_ChA_D1 = l_RCW[70][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW47_ChA_D1 = l_RCW[71][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW48_ChA_D1 = l_RCW[72][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW49_ChA_D1 = l_RCW[73][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW4A_ChA_D1 = l_RCW[74][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW4B_ChA_D1 = l_RCW[75][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW4C_ChA_D1 = l_RCW[76][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW4D_ChA_D1 = l_RCW[77][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW4E_ChA_D1 = l_RCW[78][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW4F_ChA_D1 = l_RCW[79][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW50_ChA_D1 = l_RCW[80][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW51_ChA_D1 = l_RCW[81][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW52_ChA_D1 = l_RCW[82][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW53_ChA_D1 = l_RCW[83][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW54_ChA_D1 = l_RCW[84][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW55_ChA_D1 = l_RCW[85][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW56_ChA_D1 = l_RCW[86][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW57_ChA_D1 = l_RCW[87][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW58_ChA_D1 = l_RCW[88][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW59_ChA_D1 = l_RCW[89][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW5A_ChA_D1 = l_RCW[90][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW5B_ChA_D1 = l_RCW[91][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW5C_ChA_D1 = l_RCW[92][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW5D_ChA_D1 = l_RCW[93][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW5E_ChA_D1 = l_RCW[94][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW5F_ChA_D1 = l_RCW[95][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW60_ChA_D1 = l_RCW[96][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW61_ChA_D1 = l_RCW[97][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW62_ChA_D1 = l_RCW[98][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW63_ChA_D1 = l_RCW[99][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW64_ChA_D1 = l_RCW[100][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW65_ChA_D1 = l_RCW[101][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW66_ChA_D1 = l_RCW[102][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW67_ChA_D1 = l_RCW[103][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW68_ChA_D1 = l_RCW[104][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW69_ChA_D1 = l_RCW[105][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW6A_ChA_D1 = l_RCW[106][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW6B_ChA_D1 = l_RCW[107][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW6C_ChA_D1 = l_RCW[108][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW6D_ChA_D1 = l_RCW[109][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW6E_ChA_D1 = l_RCW[110][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW6F_ChA_D1 = l_RCW[111][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW70_ChA_D1 = l_RCW[112][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW71_ChA_D1 = l_RCW[113][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW72_ChA_D1 = l_RCW[114][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW73_ChA_D1 = l_RCW[115][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW74_ChA_D1 = l_RCW[116][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW75_ChA_D1 = l_RCW[117][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW76_ChA_D1 = l_RCW[118][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW77_ChA_D1 = l_RCW[119][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW78_ChA_D1 = l_RCW[120][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW79_ChA_D1 = l_RCW[121][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW7A_ChA_D1 = l_RCW[122][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW7B_ChA_D1 = l_RCW[123][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW7C_ChA_D1 = l_RCW[124][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW7D_ChA_D1 = l_RCW[125][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW7E_ChA_D1 = l_RCW[126][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];
    io_msg_block.RCW7F_ChA_D1 = l_RCW[127][mss::ddr5::mr::ATTR_CHANNEL_A][DIMM1];

    io_msg_block.RCW00_ChB_D1 = l_RCW[0][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW01_ChB_D1 = l_RCW[1][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW02_ChB_D1 = l_RCW[2][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW03_ChB_D1 = l_RCW[3][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW04_ChB_D1 = l_RCW[4][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW05_ChB_D1 = l_RCW[5][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW06_ChB_D1 = l_RCW[6][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW07_ChB_D1 = l_RCW[7][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW08_ChB_D1 = l_RCW[8][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW09_ChB_D1 = l_RCW[9][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW0A_ChB_D1 = l_RCW[10][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW0B_ChB_D1 = l_RCW[11][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW0C_ChB_D1 = l_RCW[12][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW0D_ChB_D1 = l_RCW[13][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW0E_ChB_D1 = l_RCW[14][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW0F_ChB_D1 = l_RCW[15][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW10_ChB_D1 = l_RCW[16][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW11_ChB_D1 = l_RCW[17][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW12_ChB_D1 = l_RCW[18][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW13_ChB_D1 = l_RCW[19][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW14_ChB_D1 = l_RCW[20][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW15_ChB_D1 = l_RCW[21][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW16_ChB_D1 = l_RCW[22][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW17_ChB_D1 = l_RCW[23][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW18_ChB_D1 = l_RCW[24][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW19_ChB_D1 = l_RCW[25][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW1A_ChB_D1 = l_RCW[26][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW1B_ChB_D1 = l_RCW[27][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW1C_ChB_D1 = l_RCW[28][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW1D_ChB_D1 = l_RCW[29][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW1E_ChB_D1 = l_RCW[30][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW1F_ChB_D1 = l_RCW[31][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW20_ChB_D1 = l_RCW[32][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW21_ChB_D1 = l_RCW[33][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW22_ChB_D1 = l_RCW[34][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW23_ChB_D1 = l_RCW[35][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW24_ChB_D1 = l_RCW[36][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW25_ChB_D1 = l_RCW[37][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW26_ChB_D1 = l_RCW[38][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW27_ChB_D1 = l_RCW[39][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW28_ChB_D1 = l_RCW[40][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW29_ChB_D1 = l_RCW[41][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW2A_ChB_D1 = l_RCW[42][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW2B_ChB_D1 = l_RCW[43][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW2C_ChB_D1 = l_RCW[44][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW2D_ChB_D1 = l_RCW[45][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW2E_ChB_D1 = l_RCW[46][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW2F_ChB_D1 = l_RCW[47][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW30_ChB_D1 = l_RCW[48][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW31_ChB_D1 = l_RCW[49][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW32_ChB_D1 = l_RCW[50][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW33_ChB_D1 = l_RCW[51][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW34_ChB_D1 = l_RCW[52][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW35_ChB_D1 = l_RCW[53][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW36_ChB_D1 = l_RCW[54][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW37_ChB_D1 = l_RCW[55][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW38_ChB_D1 = l_RCW[56][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW39_ChB_D1 = l_RCW[57][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW3A_ChB_D1 = l_RCW[58][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW3B_ChB_D1 = l_RCW[59][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW3C_ChB_D1 = l_RCW[60][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW3D_ChB_D1 = l_RCW[61][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW3E_ChB_D1 = l_RCW[62][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW3F_ChB_D1 = l_RCW[63][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW40_ChB_D1 = l_RCW[64][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW41_ChB_D1 = l_RCW[65][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW42_ChB_D1 = l_RCW[66][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW43_ChB_D1 = l_RCW[67][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW44_ChB_D1 = l_RCW[68][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW45_ChB_D1 = l_RCW[69][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW46_ChB_D1 = l_RCW[70][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW47_ChB_D1 = l_RCW[71][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW48_ChB_D1 = l_RCW[72][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW49_ChB_D1 = l_RCW[73][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW4A_ChB_D1 = l_RCW[74][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW4B_ChB_D1 = l_RCW[75][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW4C_ChB_D1 = l_RCW[76][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW4D_ChB_D1 = l_RCW[77][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW4E_ChB_D1 = l_RCW[78][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW4F_ChB_D1 = l_RCW[79][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW50_ChB_D1 = l_RCW[80][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW51_ChB_D1 = l_RCW[81][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW52_ChB_D1 = l_RCW[82][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW53_ChB_D1 = l_RCW[83][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW54_ChB_D1 = l_RCW[84][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW55_ChB_D1 = l_RCW[85][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW56_ChB_D1 = l_RCW[86][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW57_ChB_D1 = l_RCW[87][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW58_ChB_D1 = l_RCW[88][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW59_ChB_D1 = l_RCW[89][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW5A_ChB_D1 = l_RCW[90][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW5B_ChB_D1 = l_RCW[91][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW5C_ChB_D1 = l_RCW[92][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW5D_ChB_D1 = l_RCW[93][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW5E_ChB_D1 = l_RCW[94][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW5F_ChB_D1 = l_RCW[95][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW60_ChB_D1 = l_RCW[96][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW61_ChB_D1 = l_RCW[97][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW62_ChB_D1 = l_RCW[98][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW63_ChB_D1 = l_RCW[99][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW64_ChB_D1 = l_RCW[100][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW65_ChB_D1 = l_RCW[101][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW66_ChB_D1 = l_RCW[102][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW67_ChB_D1 = l_RCW[103][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW68_ChB_D1 = l_RCW[104][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW69_ChB_D1 = l_RCW[105][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW6A_ChB_D1 = l_RCW[106][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW6B_ChB_D1 = l_RCW[107][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW6C_ChB_D1 = l_RCW[108][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW6D_ChB_D1 = l_RCW[109][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW6E_ChB_D1 = l_RCW[110][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW6F_ChB_D1 = l_RCW[111][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW70_ChB_D1 = l_RCW[112][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW71_ChB_D1 = l_RCW[113][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW72_ChB_D1 = l_RCW[114][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW73_ChB_D1 = l_RCW[115][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW74_ChB_D1 = l_RCW[116][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW75_ChB_D1 = l_RCW[117][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW76_ChB_D1 = l_RCW[118][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW77_ChB_D1 = l_RCW[119][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW78_ChB_D1 = l_RCW[120][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW79_ChB_D1 = l_RCW[121][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW7A_ChB_D1 = l_RCW[122][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW7B_ChB_D1 = l_RCW[123][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW7C_ChB_D1 = l_RCW[124][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW7D_ChB_D1 = l_RCW[125][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW7E_ChB_D1 = l_RCW[126][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];
    io_msg_block.RCW7F_ChB_D1 = l_RCW[127][mss::ddr5::mr::ATTR_CHANNEL_B][DIMM1];

fapi_try_exit:
    return fapi2::current_err;
}
#endif

///
/// @class rcw_id
/// @brief Contains information for RCW's as processed from the SMBus messages
///
struct rcw_id
{
    // Note: the comments show the Synopsys mappings
    // The IBM data starts at bit 32 and increases from there
    // So a Synopsys mapping of 31:28 will be an IBM mapping of 32:35
    enum bit_mappings
    {
        CHANNEL_ID     = 32, // Synopsys 31:28
        CHANNEL_ID_LEN = 4,
        DIMM_ID        = 36, // Synopsys 27:24
        DIMM_ID_LEN    = 4,
        RCW_ID         = 40, // Synopsys 23:16
        RCW_ID_LEN     = 8,
        RCW_PAGE       = 48, // Synopsys 15: 8
        RCW_PAGE_LEN   = 8,
        RCW_VAL        = 56, // Synopsys  7: 0
        RCW_VAL_LEN    = 8,
    };

    rcw_id() = delete;

    ///
    /// @brief Reads in and processes the SMBus formatted message
    ///
    rcw_id(const fapi2::buffer<uint64_t>& i_mail) :
        iv_channel_id(0),
        iv_dimm_id(0),
        iv_rcw_id(0),
        iv_rcw_page(0),
        iv_rcw_val(0)
    {
        i_mail.extractToRight<CHANNEL_ID, CHANNEL_ID_LEN>(iv_channel_id)
        .extractToRight<DIMM_ID, DIMM_ID_LEN>(iv_dimm_id)
        .extractToRight<RCW_ID, RCW_ID_LEN>(iv_rcw_id)
        .extractToRight<RCW_PAGE, RCW_PAGE_LEN>(iv_rcw_page)
        .extractToRight<RCW_VAL, RCW_VAL_LEN>(iv_rcw_val);
    }

    ///
    /// @brief rcw_id default destructor
    ///
    ~rcw_id() = default;

    uint8_t iv_channel_id = 0;
    uint8_t iv_dimm_id = 0;
    uint8_t iv_rcw_id = 0;
    uint8_t iv_rcw_page = 0;
    uint8_t iv_rcw_val = 0;
};

///
/// @brief Configures the DRAM training message block using attributes
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_sim value of ATTR_IS_SIMULATION
/// @param[out] o_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_sim,
        PMU_SMB_DDR5U_1D_t& o_struct);

///
/// @brief Loads binary into registers
/// @param[in] i_target the target on which to operate
/// @param[in] i_is_first_load value noting if this is the first load of the given memory array
/// @param[in] i_start_addr start address of  imem/dmem binary to be read through istream
/// @param[in] i_data_start data pointer  of imem/dmem
/// @param[in] i_mem_size size of the dmem/imem istream to be trasferred per loop
/// @param[in] i_mem_total_size total size of the dmem/imem istream
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode load_mem_bin_data(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const uint8_t i_is_first_load,
                                    const uint32_t i_start_addr,
                                    const uint8_t* const i_data_start,
                                    const uint32_t i_mem_size,
                                    const uint32_t i_mem_total_size);

///
///
/// @brief Initializes the protocol for mailbox interaction
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode init_mailbox_protocol(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Get the message passed through the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[in] i_loop_count poll count for reading UCT_PROT_SHADOW.
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                            const uint8_t i_mode,
                            const uint64_t i_loop_count,
                            fapi2::buffer<uint64_t>& o_mail);

///
/// @brief Poll for mail to be available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// note: mode is set in the calling function. mail is returned based on that.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_message_available (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_mailbox_poll_count);

///
/// @brief reads the message after it is available
/// @param[in] i_target the target on which to operate
/// @param[in] i_mode 16 bit or 32 bit to read major message or streaming & SMBus messages
/// @param[out] o_mail message read from the mailbox protocol.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               const uint8_t i_mode,
                               fapi2::buffer<uint64_t>& o_mail);

//
/// @brief Acknowledges that mail is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_mailbox_poll_count poll count for reading UCT_PROT_SHADOW.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode acknowledge_mail (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const uint64_t i_mailbox_poll_count);


///
/// @brief Polls the mail until completion message is received
/// @param[in] i_target the target on which to operate
/// @param[in] i_training_poll_count poll count for getting mail.
/// @param[out] o_status final mail message from training, PASS/FAIL status if it completed
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_completion(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const uint64_t i_training_poll_count,
                                      uint64_t& o_status,
                                      fapi2::hwp_data_ostream& o_log_data );

///
/// @brief Checks the completion condition for training and decodes respective message
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_mail mail content to check for completion
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @param[out] o_loop_end flags that completion was detected, ending polling loop and skipping delay.
/// @param[in,out] io_mail_tracker bitmap representing all mail messages received during polling.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_for_completion_and_decode(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const fapi2::buffer<uint64_t>& i_mail,
        fapi2::hwp_data_ostream& o_log_data,
        bool& o_loop_end, fapi2::buffer<uint32_t>& io_mail_tracker);

///
/// @brief Configures the msg block on to snps phy
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_msg_block the message block to configure and load
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block);

///
/// @brief Configure and load the msg block on to snps phy
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_msg_block the message block to configure and load
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_and_load_dram_train_message_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        PMU_SMB_DDR5U_1D_t& io_msg_block);

// The defines should be removed once GENERICI2C target is added to SBE
#if (!defined(__HOSTBOOT_MODULE) && !defined(__PPE__))
///
/// @brief Gets the RCD target that is needed for the i2c command
/// @param[in] i_target ocmb chip target
/// @param[out] o_rc return code of either fapi2::FAPI2_RC_SUCCESS or FAIL
/// @return RCD target or empty target
///
fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER> get_rcd_target(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target, fapi2::ReturnCode& o_rc);

///
/// @brief Helper function to put together the data sent to i2c command
/// @param[in] i_rcw_info rcw info that need to be sent to i2c
/// @param[out] o_rcw_puti2c_data vector to put the i2c data
/// @return none
///
void assemble_rcw_i2c_data(const rcw_id& i_rcw_info, std::vector<uint8_t>& o_rcw_puti2c_data);
#endif
///
/// @brief Processes a streaming message from the mailbox protocol
/// @param[in] i_target the target on which to operate
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode process_streaming_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Processes an SMBus message request (aka runs an RCW via i2c)
/// @param[in] i_target the target on which to operate
/// @param[in] i_mail_tracker bitmap representing all mail messages received during polling.
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function only handles the message interface for right now
///
fapi2::ReturnCode process_smbus_message(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        const fapi2::buffer<uint32_t>& i_mail_tracker);

///
/// @brief Starts the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes that the firmware binaries and data structures are loaded appropriately
///
fapi2::ReturnCode start_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Stops the ARC processor
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode stall_arc_processor(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Cleans up from the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note puts the processor into a stall state
///
fapi2::ReturnCode cleanup_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief constants for mailbox interaction
///
enum mailbox_consts
{
    // Initialization of protocol
    PROTOCOL_INIT = 1,

    // Responses received as major message
    SUCCESSFUL_COMPLETION = 0x07,
    FAILED_COMPLETION = 0xFF,
    STREAMING_MSG = 0x08,
    SMBUS_MSG = 0x50,
    SMBUS_SYNC = 0x51,

    // Stage completion Major messaging
    END_OF_INITILIAZATION = 0x00,
    END_OF_FINE_WRITE_LEVELING = 0x01,
    END_OF_READ_ENABLE_TRAINING = 0x02,
    END_OF_RD_DLY_CNTR_OPT = 0x03,
    END_OF_WR_DLY_CNTR_OPT = 0x04,
    END_OF_2D_RD_DLY_V_CNTR_OPT = 0x05,
    END_OF_2D_WR_DLY_V_CNTR_OPT = 0x06,
    END_OF_MAX_RD_LAT_TRAINING = 0x09,
    END_OF_RD_DQ_DSKEW_TRAINING = 0x0A,
    TRAINING_STAGE_RESERVED = 0x0B,
    END_OF_CS_CA_TRAINING = 0x0D,
    END_OF_RCD_QCS_QCA_TRAINING = 0x1D,
    END_OF_LRDIMM_MREP_TRAINING = 0x20,
    END_OF_LRDIMM_DWL_TRAINING = 0x21,
    END_OF_LRDIMM_MRD_TRAINING = 0x22,
    END_OF_LRDIMM_MWD_TRAINING = 0x23,
    GEN_WRT_NOISE_SYN = 0xA0,
    END_OF_MPR_RD_DLY_CNTR_OPT = 0xFD,
    END_OF_WR_LVL_COARSE_DLY = 0xFE,

    // IBM additional stream messages
    // Note: BEGINNING_OF_DRAMINIT_ON_PORT gets the port's relative pos OR'd into it
    BEGINNING_OF_DRAMINIT_ON_PORT = 0xFFFFFF00,
    PER_DRAM_RECOVERY = 0xFFFFFF02,
    PER_DRAM_RECOVERY_FINAL_RUN = 0xFFFFFF03,
    BAD_BIT_RECOVERY = 0xFFFFFF04,

    // Mode for reading major message vs streaming msg/SMBus msg
    MAJOR_MSG_MODE = 16,
    STREAMING_SMBUS_MSG_MODE = 32,

    // Register data for different messages
    MESSAGE_AVAILABLE = 0,
    RECEPTION_ACK = 0,
    ACK_MESSAGE = 1,
};

namespace mailbox_bitmap
{
// Bitmap to store the mail messages received during polling
enum mailbox_consts
{
    // Stage completion Major messaging
    END_OF_INITILIAZATION = 0,
    END_OF_FINE_WRITE_LEVELING = 1,
    END_OF_READ_ENABLE_TRAINING = 2,
    END_OF_RD_DLY_CNTR_OPT = 3,
    END_OF_WR_DLY_CNTR_OPT = 4,
    END_OF_2D_RD_DLY_V_CNTR_OPT = 5,
    END_OF_2D_WR_DLY_V_CNTR_OPT = 6,
    END_OF_MAX_RD_LAT_TRAINING = 7,
    END_OF_RD_DQ_DSKEW_TRAINING = 8,
    TRAINING_STAGE_RESERVED = 9,
    END_OF_CS_CA_TRAINING = 10,
    END_OF_RCD_QCS_QCA_TRAINING = 11,
    END_OF_LRDIMM_MREP_TRAINING = 12,
    END_OF_LRDIMM_DWL_TRAINING = 13,
    END_OF_LRDIMM_MRD_TRAINING = 14,
    END_OF_LRDIMM_MWD_TRAINING = 15,
    GEN_WRT_NOISE_SYN = 16,
    END_OF_MPR_RD_DLY_CNTR_OPT = 17,
    END_OF_WR_LVL_COARSE_DLY = 18,
    UNKNOWN_MAJOR_MESSAGE = 19,
    SUCCESSFUL_COMPLETION = 20,
    FAILED_COMPLETION = 21
};

}
///
/// @brief Calculates the end addr of IMEM/DMEM image
/// @param[in] i_start_addr starting address of the image
/// @param[in] i_size size that needs to transferred at a time
/// @return uint32_t calculated end address
///
uint32_t calculate_image_end_addr(const uint32_t i_start_addr, const uint32_t i_size);

/// @brief Assembles a single registers worth of data from the buffer
/// @param[in] i_mem_size size of the dmem/imem istream to be transferred per loop
/// @param[in,out] io_bytes_copied the number of bytes copied
/// @param[in] i_current_byte the pointer to the current byte
/// @param[in,out] io_data the data for this register address
/// @return The updated pointer to the current byte
///
const uint8_t* assemble_mem_bin_data_reg(const uint32_t i_mem_size,
        uint32_t& io_bytes_copied,
        const uint8_t* const i_current_byte,
        fapi2::buffer<uint64_t>& io_data);

///
/// @brief Helper function to ody_load_dmem()
/// @param[in] i_target the ocmb chip target
/// @param[in] i_dmem_data dmem data image
/// @param[in] i_dmem_size size that needs to transferred at a time
/// @param[in] i_dmem_offset address offset of this chunk within the dmem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_load_dmem_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const uint8_t* const i_dmem_data,
                                       const uint32_t i_dmem_size,
                                       const uint32_t i_dmem_offset);

///
/// @brief Helper function to ody_load_imem()
/// @param[in] i_target the ocmb chip target
/// @param[in] i_imem_data imem data image
/// @param[in] i_imem_size size that needs to transferred at a time
/// @param[in] i_imem_offset address offset of this chunk within the imem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_load_imem_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const uint8_t* const i_imem_data,
                                       const uint32_t i_imem_size,
                                       const uint32_t i_imem_offset);
///
/// @brief Conducts an endian swap if needed on this message block address
/// @param[in] i_address the current address to load
/// @param[in] i_end_it the ending iterator of this array
/// @param[in,out] io_no_swap_it the current iterator to check for the address
/// @param[in,out] io_data the register data to update if needed
///
void endian_swap_msg_block_data(const uint64_t i_address, const uint32_t* const i_end_it,
                                const uint32_t*& io_no_swap_it, fapi2::buffer<uint64_t>& io_data);

///
/// @brief Loads the message block into the DMEM
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Only loads the "input" fields
/// @note The guts of this function is auto-generated using gen_dmem_func.py
///       located in the ekb-lab/ody/mem/tools
///
fapi2::ReturnCode load_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const _PMU_SMB_DDR5_1D_t& i_struct);

///
/// @brief Reads the message block from the DMEM
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_struct the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Only loads the "output" fields
/// @note The guts of this function is auto-generated using gen_dmem_func.py
///       located in the ekb-lab/ody/mem/tools
///
fapi2::ReturnCode read_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 _PMU_SMB_DDR5_1D_t& io_struct);

///
/// @brief Sets the mode register attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_mr_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const _PMU_SMB_DDR5_1D_t& i_msg_block);

///
/// @brief Sets the generic attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_generic_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const _PMU_SMB_DDR5_1D_t& i_msg_block);

///
/// @brief Sets the attributes based upon the outputted data from draminit
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_msg_blk message block structure
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const _PMU_SMB_DDR5_1D_t& i_msg_block);

/// @brief Prints the fields from the message block structure
/// @param[in] i_target the target on which to operate
/// @param[in] i_msg_blk message block structure
/// @return None
///
void display_msg_block(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                       const _PMU_SMB_DDR5_1D_t& i_msg_block);

///
/// @brief Checks the FW revision in the message block
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_is_sim true if this is a simulation run
/// @param[in] i_is_simics attribute value
/// @param[in] i_msg_block_response the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_fw_revision(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    const uint8_t i_is_sim,
                                    const uint8_t i_is_simics,
                                    const _PMU_SMB_DDR5_1D_t& i_msg_block_response);

///
/// @brief Checks the training status from mail and message block
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_status the final mail status from training
/// @param[in] i_msg_block_response the message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_training_result(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        const uint64_t i_status,
                                        const _PMU_SMB_DDR5_1D_t& i_msg_block_response);

///
/// @brief Extracts the bad bits out of a structure for comparison purposes for the draminit recovery algorithm
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_bad_bits the bad bits to insert into the message block
/// @param[in,out] io_struct message block to update
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode update_struct_for_bad_bits(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t (&i_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& io_struct);

///
/// @brief Handles any address errors found in the prior run
/// @param[in] i_target the target on which to operate
/// @param[in] i_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[out] o_struct the draminit message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_msg_blk_for_address_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t (&i_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& o_struct);

///
/// @brief Handles any address errors found in the prior run
/// @param[in] i_rank_info the rank info class under test
/// @param[in] i_dram the DRAM under test
/// @param[in] i_nibble_enables the nibbles enabled for this port
/// @param[in,out] io_status the status of the last training run
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @param[in,out] io_bad_dram_on_rank
/// @param[out] o_log_data the ostream object containing streaming messages
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode handle_address_errors_internal(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const uint8_t i_dram,
        const fapi2::buffer<uint32_t>& i_nibble_enables,
        uint64_t& io_status,
        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& io_struct,
        uint8_t& io_bad_dram_on_rank,
        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Handles any address errors found in the prior run
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_status the status of the last training run
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @param[in,out] io_is_first_addr_run true if this is the first address recovery run
/// @param[out] o_log_data the ostream object containing streaming messages
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode handle_address_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        uint64_t& io_status,
                                        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                                        PMU_SMB_DDR5U_1D_t& io_struct,
                                        bool& io_is_first_addr_run,
                                        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Configures the message block for any DQ errors recovery
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_msg_block_for_dq_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& io_struct);

///
/// @brief Disables any nibbles that have DQ0 deconfigured
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_dram_with_bad_dq0(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& io_struct);


///
/// @brief Perform swizzle and compute the bad_bit_flag and update the
///        start_bit and new_bit structures
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_dq_bad_bits_attr value of ATTR_BAD_DQ_BITMAP
/// @param[in] i_current_bad_bits_phy the lane disable data in PHY perspective
/// @param[in] i_start_bad_bits_phy starting bad bits in PHY perspective
/// @param[out] o_bad_bit_flag cumulative bad bit flag that is computed
/// @param[out] o_new_bad_bits_per_rank_mc structure for the bytes after the swizzle for new bad bits
/// @param[out] o_start_bad_bits_per_rank_mc structure for the bytes after the swizzle for the start bad bits
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode swizzle_and_compute_bad_bit_flag_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t (&i_dq_bad_bits_attr)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        const uint8_t (&i_current_bad_bits_phy)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        const uint8_t (&i_start_bad_bits_phy)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        bool& o_bad_bit_flag,
        bad_bits_per_rank_mc& o_new_bad_bits_per_rank_mc,
        bad_bits_per_rank_mc& o_start_bad_bits_per_rank_mc);

///
/// @brief Setup the bytes using the bad bits arrays
/// @param[in] i_rank_infos vector of rank infos
/// @param[in] i_bad_bits_mc the bad array that has the swizzled bytes in mc perspective
/// @param[out] o_bad_bits_per_rank_mc structure that has the bytes that need to be assigned
/// @return none
///
void setup_bad_bit_bytes(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_rank_infos,
                         const uint8_t (&i_bad_bits_phy)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                         bad_bits_per_rank_mc& o_bad_bits_per_rank_mc);

///
/// @brief Compute bad bits flag from the new bad bit found and the attribute value
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_current_bad_bits_mc the lane disable data swizzled to MC perspective
/// @param[in] i_start_bad_bits_mc starting bad bits in mc perspective
/// @param[in] i_bad_bit_attr attribute bad bit value
/// @param[in,out] io_bad_bit_flag cumulative bad bit flag that is computed
/// @return none
///
void compute_bad_bit_flag(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                          const uint8_t i_current_bad_bits_mc, const uint8_t i_start_bad_bits_mc,
                          const uint8_t i_bad_bit_attr, bool& io_bad_bit_flag);

///
/// @brief Updates the bad bits for swizzle detect errors
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_swizzle_detect_fail the swizzle detect fail attribute value
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
///
fapi2::ReturnCode update_bad_bits_for_swizzle_detect(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint16_t i_swizzle_detect_fail,
        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]);

///
/// @brief Sets the value accordingly if the message is noting a swizzle detect failure
/// @param[in] i_msg the streaming message to check
/// @return 1 if this is a swizzle detect failure, otherwise 0
///
inline uint16_t check_if_msg_is_swizzle_detect_failure(const uint64_t i_msg)
{
    // Note: this depends upon the Synopsys FW revision and will need to be updated if the image changes
    constexpr uint32_t SWIZZLE_DETECT_MESSAGE1 = 0x01fa0003;
    constexpr uint32_t SWIZZLE_DETECT_MESSAGE2 = 0x01fd0003;

    if(SWIZZLE_DETECT_MESSAGE1 == i_msg || SWIZZLE_DETECT_MESSAGE2 == i_msg)
    {
        // The first nibble in the attribute indicates if the data is valid
        // The data will be shifted and assembled accordingly
        return 1;
    }

    return 0;
}

///
/// @brief Appends swizzle detect information if needed
/// @param[in] i_msg the streaming message to check
/// @param[in,out] io_swizzle_detect_info the swizzle detect info attribute
///
inline void append_swizzle_data(const uint64_t i_msg, uint16_t& io_swizzle_detect_info)
{
    // Only assemble this data if the swizzle detect has failed
    if(io_swizzle_detect_info)
    {
        io_swizzle_detect_info <<= BITS_PER_NIBBLE;
        io_swizzle_detect_info |= i_msg;
    }
}

///
/// @brief Sets the swizzle detect failure attribute if needed
/// @param[in] i_target the target on which to operate
/// @param[in] i_swizzle_detect_info the swizzle detect info attribute
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
inline fapi2::ReturnCode set_swizzle_fail_attr(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint16_t i_swizzle_detect_info)
{
    // Only assemble this data if the swizzle detect has failed
    if(i_swizzle_detect_info)
    {
        return FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_SWIZZLE_DETECT_FAIL_VALUE, i_target, i_swizzle_detect_info);
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Handles any swizzle detect errors found in prior runs
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_status the status of the last training run
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @param[out] o_log_data the ostream object containing streaming messages
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode handle_swizzle_detect_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        uint64_t& io_status,
        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& io_struct,
        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Handles any DQ errors found in the prior run
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_status the status of the last training run
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @param[out] o_log_data the ostream object containing streaming messages
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode handle_dq_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   uint64_t& io_status,
                                   uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                                   PMU_SMB_DDR5U_1D_t& io_struct,
                                   fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Displays the disable bits
/// @param[in] i_rank_info the rank information
/// @param[in] i_bad_bits the bad bits structure - bytes in the MC perspective. Bits and ranks in the PHY perspective
///
void display_disable_bits(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                          const uint8_t (&i_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]);

///
/// @brief Extracts the bad bits out of a structure for comparison purposes for the draminit recovery algorithm
/// @param[in] i_struct the draminit message block structure
/// @param[out] o_bad_bits the bad bits structure - bytes in the MC perspective. Bits and ranks in the PHY perspective
///
void extract_disable_bits(const PMU_SMB_DDR5U_1D_t& i_struct,
                          uint8_t (&o_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]);

///
/// @brief Returns true if this run could contain address fails
/// @param[in] i_status the status from training
/// @param[in] i_struct the draminit message block structure
/// @return true if there is a potential address fail
///
inline bool has_address_fails(const uint8_t i_status, const PMU_SMB_DDR5U_1D_t& i_struct)
{
    constexpr uint8_t MSG_BLOCK_TRAIN_PASS = 0x00;
    return (i_status != SUCCESSFUL_COMPLETION) || (i_struct.CsTestFail != MSG_BLOCK_TRAIN_PASS);
}

///
/// @brief Returns true if this message block contains new bad bits
/// @param[in] i_start_bad_bits the starting bad bits
/// @param[in] i_struct the structure containing the current bad bits
/// @return true if the bad bits are not the same between the starting bad bits and bad bits in this structure
///
inline bool has_new_bad_bits(const uint8_t (&i_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                             const PMU_SMB_DDR5U_1D_t& i_struct)
{
    uint8_t l_current_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT];
    extract_disable_bits(i_struct, l_current_bad_bits);

    return memcmp(l_current_bad_bits, i_start_bad_bits, sizeof i_start_bad_bits) != MEMCMP_EQUAL;
}

///
/// @brief Returns true if the recovery loop needs to run
/// @param[in] i_status the status from training
/// @param[in] i_start_bad_bits the starting bad bits
/// @param[in] i_struct the structure containing the current bad bits
/// @return true if the recovery loop needs to run
///
inline bool has_draminit_failure(const uint8_t i_status,
                                 const uint8_t (&i_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                                 const PMU_SMB_DDR5U_1D_t& i_struct)
{
    return mss::ody::phy::has_address_fails(i_status, i_struct) ||
           mss::ody::phy::has_new_bad_bits(i_start_bad_bits, i_struct);
}

///
/// @brief Returns true if this message block contains new bad bits
/// @param[in] i_status the status from training
/// @param[in] i_start_bad_bits the starting bad bits
/// @param[in] i_struct the structure containing the current bad bits
/// @param[in] i_loop_num the current loop number
/// @param[in] i_max_loop_num the maximum loop number if i_loop_num is less than or equal to this, we can continue to loop
/// @return true if the recovery loop needs to run
///
inline bool is_recovery_loop_needed(const uint8_t i_status,
                                    const uint8_t (&i_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                                    const PMU_SMB_DDR5U_1D_t& i_struct,
                                    const uint64_t i_loop_num,
                                    const uint64_t i_max_loop_num)
{
    return has_draminit_failure(i_status, i_start_bad_bits, i_struct) &&
           i_loop_num <= i_max_loop_num;
}

///
/// @brief Checks if the DQ errors have exceeded the potential number of repairs
/// @param[in] i_target the memory port on which to operate
/// @param[in] i_status the status of the draminit run
/// @param[in] i_struct the draminit message block
/// @param[in] i_is_swizzle_error if true, error will be ODY_DRAMINIT_REPAIRS_EXCEEDED_SWIZZLE, else ODY_DRAMINIT_REPAIRS_EXCEEDED
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_for_dq_repairs_exceeded(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_status,
        const PMU_SMB_DDR5U_1D_t& i_struct,
        const bool i_is_swizzle_error);


///
/// @brief Resets any needed attributes before a run of training
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
inline fapi2::ReturnCode reset_attrs_pretraining(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_SWIZZLE_DETECT_FAIL_VALUE, i_target,
                                 fapi2::ENUM_ATTR_ODY_SWIZZLE_DETECT_FAIL_VALUE_NO_VALUE));
    FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_MSS_ODY_PASSED_SWIZZLE_DETECT, i_target,
                                 fapi2::ENUM_ATTR_MSS_ODY_PASSED_SWIZZLE_DETECT_NOT_RUN));
fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Runs training and processes some of the results
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_status the status of the last training run
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @param[out] o_log_data the ostream object containing streaming messages
/// @param[in] i_update_bad_bits true if io_start_bad_bits should be updated prior to this run - defaults to TRUE
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_training_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      uint64_t& io_status,
                                      uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                                      PMU_SMB_DDR5U_1D_t& io_struct,
                                      fapi2::hwp_data_ostream& o_log_data,
                                      const bool i_update_bad_bits = true);

///
/// @brief Masks off PhyRxTxPPTerr
/// @param[in] i_target the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note PhyRxTxPPTerr triggers if any DRAM failed to train and therefore is masked off in the case of training recovery was run
///
fapi2::ReturnCode mask_PhyRxTxPPTerr(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Checks if ATTR_ODY_DRAMINIT_ERROR_ON_FAILURE is set and there are errors, if so, exits with an error
/// @param[in] i_target
/// @param[in] i_status the status of the last training run
/// @param[in] i_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in] i_struct the draminit message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode error_on_draminit_failure(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t& i_status,
        const uint8_t (&i_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        const PMU_SMB_DDR5U_1D_t& i_struct);

///
/// @brief Attempts to recover from any errors found during draminit - will not run if no errors occured
/// @param[in] i_target the memory port on which to operate
/// @param[in,out] io_status the status of the last training run
/// @param[in,out] io_start_bad_bits the starting bad bits before this training run - MC byte and PHY rank format
/// @param[in,out] io_struct the draminit message block
/// @param[out] o_log_data the ostream object containing streaming messages
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode handle_draminit_recovery(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        uint64_t& io_status,
        uint8_t (&io_start_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
        PMU_SMB_DDR5U_1D_t& io_struct,
        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Checks verbosity of draminit debug logs
/// @param[in] i_target the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff verbosity is no higher than COURSE_DEBUG on both
///
fapi2::ReturnCode check_draminit_verbosity(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Returns max size of Synopsys training log
/// @param[in] i_port_verbosity Memory port verbosity
/// @return uint32_t of buffer size in B
///
uint32_t getBufferSizeFromVerboseAttr(const uint8_t i_port_verbosity);

} // namespace phy
} // namespace ody
} // namespace mss
#endif
