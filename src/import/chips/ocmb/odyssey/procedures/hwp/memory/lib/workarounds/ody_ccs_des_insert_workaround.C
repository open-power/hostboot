/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_ccs_des_insert_workaround.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2026                        */
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
/// @file ody_ccs_des_insert_workaround.C
/// @brief Odyssey workaround for CCS command des insert
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>
#include <lib/ccs/ody_ccs.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/workarounds/ccs_des_insert_workaround.H>

namespace mss
{
namespace ccs
{
namespace workarounds
{

///
/// @brief Calculate idles at start of CCS based on self refresh support
/// @param[in] i_port the port target to effect
/// @param[in] i_mrw_idle_power_ctr_req MRW idle power control request
/// @param[in] i_mrw_power_ctr_req MRW power control request
/// @param[in,out] io_delay idle value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode calculate_idles(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                  const uint8_t i_mrw_idle_power_ctr_req,
                                  const uint8_t i_mrw_power_ctr_req,
                                  uint16_t& io_delay)
{
    uint64_t l_mem_port_freq = 0;

    constexpr uint16_t IDLE_3200_FREQ = 1024;
    constexpr uint16_t IDLE_4000_FREQ = 1280;
    constexpr uint16_t IDLE_4800_FREQ = 1536;

    // If these attributes are set to allow the DIMM to go into STR-self time refresh mode,
    // we need to add delay before CCS commands to allow the DRAMs to come out of STR
    if(((i_mrw_idle_power_ctr_req == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_OFF)
        || (i_mrw_idle_power_ctr_req == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_POWER_DOWN))
       && ((i_mrw_power_ctr_req == fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF)
           || (i_mrw_power_ctr_req == fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN)))
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRFC, i_port, io_delay));
    }
    else
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, i_port, l_mem_port_freq));

        switch(l_mem_port_freq)
        {
            case mss::ddr_dimm_speeds::DIMM_SPEED_3200:
                io_delay = IDLE_3200_FREQ;
                break;

            case mss::ddr_dimm_speeds::DIMM_SPEED_4000:
                io_delay = IDLE_4000_FREQ;
                break;

            case mss::ddr_dimm_speeds::DIMM_SPEED_4800:
                io_delay = IDLE_4800_FREQ;
                break;

            default:
                io_delay = IDLE_4800_FREQ;
                break;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Workaround for DES command insertion
/// @param[in] i_target the target to effect
/// @param[in] i_port the port target to effect
/// @param[in,out] io_inst_count the inst count for the ccs instructions
/// @param[in] i_current_cke the CKE for this instruction
/// @param[in] i_rank_config rank configs relative to memport pos
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode insert_des<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
    size_t& io_inst_count,
    const uint8_t i_current_cke,
    const mss::ccs::rank_configuration i_rank_config)
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;
    constexpr uint64_t CCS_ARR0_ZERO = TT::CCS_ARR0_START;
    constexpr uint64_t CCS_ARR1_ZERO = TT::CCS_ARR1_START;

    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_des;
    uint16_t l_delay = 0;
    uint8_t l_mrw_idle_power_ctr_req = 0;
    uint8_t l_mrw_power_ctr_req = 0;

    // Grab port index and first inst

    FAPI_ASSERT(io_inst_count < TT::CCS_ARRAY_LEN,
                fapi2::MSS_CONCURRENT_CCS_EXCEEDS_INSTRUCTION_LIMIT()
                .set_MC_TARGET(i_target)
                .set_REQUESTED_INSTRUCTIONS(io_inst_count)
                .set_MAX_INSTRUCTIONS(TT::CCS_ARRAY_LEN),
                TARGTIDFORMAT "Over CCS concurrent instructions limit, received: %d instructions, MAX: %d instructions", TARGTID,
                io_inst_count,
                TT::CCS_ARRAY_LEN);

    // If first instruction pass delay of trfc, otherwise assume its last and pass delay of 1
    if(io_inst_count == 0)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_mrw_idle_power_ctr_req));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_mrw_power_ctr_req));

        FAPI_TRY(calculate_idles(i_port, l_mrw_idle_power_ctr_req, l_mrw_power_ctr_req, l_delay));
        l_des =  mss::ccs::des_command<mss::mc_type::ODYSSEY>(l_delay);
        l_des.arr1.template insertFromRight<TT::ARR1_GOTO_CMD, TT::ARR1_GOTO_CMD_LEN>(io_inst_count + 1);
    }
    else
    {
        l_delay = 1;
        l_des =  mss::ccs::des_command<mss::mc_type::ODYSSEY>(l_delay);
        l_des.arr1.template setBit<TT::ARR1_END>();
    }

    // First, update the current instruction's chip selects for the current port
    FAPI_TRY(l_des.configure_rank(i_port, i_rank_config), GENTARGTIDFORMAT
             " Error configuring rank in ccs::execute on port", GENTARGTID(i_port));

    // Now, configure the idles and repeats within this instruction
    FAPI_TRY(l_des.configure_idles_and_repeats(i_port), GENTARGTIDFORMAT
             " Error configuring idles and repeats in ccs::execute on port", GENTARGTID(i_port));

    // Finally, configure the parity if needed
    FAPI_TRY(l_des.compute_parity(i_port, i_rank_config), GENTARGTIDFORMAT
             " Error computing and configuring parity in ccs::execute on port", GENTARGTID(i_port));
    l_des.set_cke_helper(i_current_cke);

    FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + io_inst_count, l_des.arr0) );
    FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + io_inst_count, l_des.arr1) );

    FAPI_INF_NO_SBE(TARGTIDFORMAT" ccs inst %d fixup: 0x%016lX 0x%016lX (0x%lx, 0x%lx)", TARGTID,
                    io_inst_count, l_des.arr0, l_des.arr1,
                    CCS_ARR0_ZERO + io_inst_count, CCS_ARR1_ZERO + io_inst_count);

    // Increment arr count by 1
    io_inst_count++;
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}
} // namespace workaround
} // namespace ccs
} // namespace mss
